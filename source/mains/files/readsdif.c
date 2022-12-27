/*
 *  readsdif.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 @file
 readsdif.c
 
 @name 
 bach.readsdif
 
 @realname 
 bach.readsdif
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Read an SDIF file
 
 @description 
 Reads an SDIF file and returns its contents as lllls.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 SDIF, file, read, load, convert

 @seealso
 bach.writesdif, bach.read, bach.roll
 
 @owner
 Andrea Agostini
 */

/*
 ---header format:
 (nvt ((name1 value1) (name2 value2) ...)
	  ((name1 value1) (name2 value2) ...)
	  ...)
 (frametypes (frame_sig1 ((matrix_sig1 [component_name1]) 
						  (matrix_sig2 [component_name2])
						  ... )) 
			 (frame_sig2 ((matrix_sig1 [component_name1]) 
						  (matrix_sig2 [component_name2])
						  ... ))
			 ...)
 (matrixtypes (matrix_sig1 (col_name1 col_name2 ...))
			  (matrix_sig2 (col_name1 col_name2 ...))	
			 ...)
 
 

 
 ---body format:
 (str_id1 (frame_sig1 ms1 ((mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						   (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						   ... ))
		  (frame_sig2 ms2 ((mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						   (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... ))
		  ...)
 (str_id2 (frame_sig1 ms1 ((mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						   (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... ))
		  (frame_sig2 ms2 ((mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						  (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... ))
		  ...)
 ...
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "libraries/SDIF-3.11.4-src/include/sdif.h"

typedef struct _readsdif
{
	t_llllobj_object	n_ob;
	long				n_auto;
} t_readsdif;


void readsdif_assist(t_readsdif *x, void *b, long m, long a, char *s);
void readsdif_inletinfo(t_readsdif *x, void *b, long a, char *t);

t_readsdif *readsdif_new(t_symbol *s, short ac, t_atom *av);
void readsdif_free(t_readsdif *x);

void readsdif_bang(t_readsdif *x);
void readsdif_int(t_readsdif *x, t_atom_long v);
void readsdif_float(t_readsdif *x, double v);
void readsdif_anything(t_readsdif *x, t_symbol *msg, long ac, t_atom *av);
void readsdif_read(t_readsdif *x, t_symbol *msg);
void readsdif_doread(t_readsdif *x, t_symbol *msg, long ac, t_atom *av);
long readsdif_cmp_by_stream(void *dummy, t_llllelem *a, t_llllelem *b);
long readsdif_acceptsdrag(t_readsdif *x, t_object *drag, t_object *view);

void readsdif_fakeexit(void);

t_class *readsdif_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.readsdif", (method)readsdif_new, (method)readsdif_free, (long) sizeof(t_readsdif), 0L, A_GIMME, 0);
	
	// @method bang @digest Output the stored lllls
	// @description After an SDIF file has been read, a bang causes its contents to be output.
	class_addmethod(c, (method)readsdif_bang,		"bang",			0);
	
	
	// @method read @digest Read an SDIF file from disk
	// @description The specified file is read from disk 
	// and the data contained in it are converted into two lllls, 
	// one for the SDIF header and one for the data body.<br/><br/>
	// The format of the two lllls is as follows:<br/>
	// - The header llll is composed by three optional lllls, 
	// respectively for the name-value tables (preceded by the <m>nvt</m> key),
	// the frame definitions (preceded by the <m>frametypes</m> key)
	// and the matrix definitions (preceded by the <m>matrixtypes</m> key).
	// Each of these sublists is actually output only if the corresponding data are present
	// in the SDIF files. The structure of the header llll is <br/>
	// <m>(nvt ((&lt;name&gt; &lt;value&gt;) ...) ...)<br/>
	// (frametypes (&lt;frame signature&gt; ((&lt;matrix signature&gt; &lt;component name (optional)&gt;) ...) ...) ...)<br/>
	// (matrixtypes (&lt;matrix signature&gt; (&lt;column name&gt; ...) ...) ...)</m><br/><br/>
	// - The body llll contains the actual data from the SDIF file, rearranged by stream.
	// It is composed by one sublist for each stream in the SDIF file.
	// The structure of the body llll is <br/>
	// <m> (&lt;stream id&gt; (&lt;frame signature&gt; &lt;time&gt; ((&lt;matrix signature&gt; ((&lt;data item&gt; ...) ...) ...)) ...) ...)</m><br/>
	// This means that the data contained in each matrix are represented as a sublist
	// containing one sublist per row, containing the row's data.
	// Text and Char matrices are an exceptions, as the text they contain is packed into symbols, one per row.
	// Therefore, the structure of a text matrix sublist is<br/>
	// <m> &lt;matrix signature&gt; (&lt;row text&gt; ...)</m><br/><br/>
	// When the reading operation is completed, a <m>bang</m> is output from the third outlet.<br/>
	// The lllls are optionally output, according to the <m>auto</m> attribute.
	// In this case, the body llll will be output from the second outlet,
	// and the header llll from the first outlet.
	// If no file name is provided, a dialog box will open.
	// @marg 0 @name file_name @optional 1 @type symbol
	class_addmethod(c, (method)readsdif_read,		"read",			A_DEFSYM,	0);
	
	class_addmethod(c, (method)readsdif_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)readsdif_inletinfo,	"inletinfo",	A_CANT,		0);
	
	// @method (drag) @digest Drag-and-drop file loading
	// @description The specified SDIF file is read from disk and the data it contains is stored
	// and optionally output, according to the <m>auto</m> attribute.
	class_addmethod(c, (method)readsdif_acceptsdrag, "acceptsdrag_locked", A_CANT, 0);
	class_addmethod(c, (method)readsdif_acceptsdrag, "acceptsdrag_unlocked", A_CANT, 0);
	
	CLASS_ATTR_LONG(c, "auto",	0,	t_readsdif, n_auto);
	CLASS_ATTR_FILTER_CLIP(c, "auto", 0, 1);
	CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
	CLASS_ATTR_BASIC(c, "auto", 0);
	// @description When set to 1, the contents of the SDIF file
	// are automatically output immediately after being read from disk.

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	SdifGenInitCond("");
	SdifSetExitFunc((SdifExitFuncT) readsdif_fakeexit);
	
	class_register(CLASS_BOX, c);
	readsdif_class = c;
	
	dev_post("bach.readsdif compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void readsdif_bang(t_readsdif *x)
{	
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void readsdif_read(t_readsdif *x, t_symbol *msg)
{
	defer(x, (method)readsdif_doread, msg, 0, NULL);
}

long readsdif_acceptsdrag(t_readsdif *x, t_object *drag, t_object *view)
{
	if (jdrag_matchdragrole(drag, gensym("sdiffile"), 0))  {
		jdrag_object_add(drag, (t_object *)x, gensym("read"));
		return true;
	}
	return false;
}

void readsdif_doread(t_readsdif *x, t_symbol *s, long ac, t_atom *av)
{
	t_fourcc outtype;
	t_fourcc filetype = 'SDIF';
	char filename[MAX_PATH_CHARS];
	char filepath[MAX_PATH_CHARS];
	short path;
	
	if (s == gensym("")) {      // if no argument supplied, ask for file
		if (open_dialog(filename, &path, &outtype, &filetype, 1))       // non-zero: user cancelled
			return;
	} else {
		strcpy(filename, s->s_name);    // must copy symbol before calling locatefile_extended
		if (locatefile_extended(filename, &path, &outtype, &filetype, 1)) { // non-zero: not found
			object_error((t_object *) x, "%s: not found", s->s_name);
			return;
		}
	}
	// we have a file
	path_toabsolutesystempath(path, filename, filepath);
	
	char outtypetxt[5];
	strncpy_zero(outtypetxt, (char *) &outtype, 4);
	outtypetxt[4] = 0;
	
	t_llll *sdif_ll = llll_make();
	size_t  bytesread = 0;
	int	eof = 0;	/* End-of-file flag */
	
	SdifFileT *file = SdifFOpen (filepath, eReadFile);
	bytesread += SdifFReadGeneralHeader  (file); /* Read file header */
	bytesread += SdifFReadAllASCIIChunks (file); /* Read ASCII header info, such as name-value tables */
	
	
	// name-value tables
	
	SdifNameValuesLT *nvtlist = SdifFNameValueList(file);
	SdifListT *nvtl = SdifNameValueTableList(nvtlist);
	SdifHashTableIteratorT *nvtiter = SdifCreateHashTableIterator(NULL);
	SdifListInitLoop(nvtl);
	t_llll *header_ll = llll_make();
	t_llll *nvt_ll = llll_make();
	while (SdifListIsNext(nvtl)) {
		t_llll *table_ll = llll_make();
		SdifNameValueTableT *currnvt = (SdifNameValueTableT *) SdifListGetNext(nvtl);
		SdifHashTableT *nvht = SdifNameValueTableGetHashTable(currnvt);
		SdifHashTableIteratorInitLoop(nvtiter, nvht);
		while (SdifHashTableIteratorIsNext(nvtiter))
		{
			t_llll *nv_ll = llll_make();
			SdifNameValueT *nv = (SdifNameValueT *) SdifHashTableIteratorGetNext(nvtiter);
			const char *nv_name = SdifNameValueGetName(nv);
			const char *nv_value = SdifNameValueGetValue(nv);
			llll_appendsym(nv_ll, gensym(nv_name), 0, WHITENULL_llll);
			llll_appendsym(nv_ll, gensym(nv_value), 0, WHITENULL_llll);
			llll_appendllll(table_ll, nv_ll, 0, WHITENULL_llll);
		}
		llll_appendllll(nvt_ll, table_ll, 0, WHITENULL_llll);
	}
	SdifKillHashTableIterator(nvtiter);

	if (nvt_ll->l_size == 0)
		llll_free(nvt_ll);
	else {
		llll_prependsym(nvt_ll, gensym("nvt"), 0, WHITENULL_llll);
		llll_appendllll(header_ll, nvt_ll, 0, WHITENULL_llll);
	}
	
	
	// frame types
	
	SdifHashTableT *fttable = SdifFGetFrameTypesTable(file);
	t_llll *frametypes_ll = llll_make();
	SdifHashTableIteratorT *frametypes_iterator = SdifCreateHashTableIterator(NULL);
	
	SdifHashTableIteratorInitLoop(frametypes_iterator, fttable);
	while (SdifHashTableIteratorIsNext(frametypes_iterator)) {
		t_llll *this_framedef_ll = llll_make();
		SdifFrameTypeT *ft = (SdifFrameTypeT *) SdifHashTableIteratorGetNext(frametypes_iterator);
		SdifSignature fsig = ft->Signature;
		const char *fsig_txt = SdifSignatureToString(fsig);
		llll_appendsym(this_framedef_ll, gensym(fsig_txt), 0, WHITENULL_llll);
		
		long ncomps = SdifFrameTypeGetNbComponents(ft);
		long i;
		for (i = 1; i <= ncomps; i++) {
			t_llll *this_component_ll = llll_make();
			SdifComponentT *fcomp = SdifFrameTypeGetNthComponent(ft, i);
			SdifSignature msig = SdifFrameTypeGetComponentSignature(fcomp);
			const char *msig_txt = SdifSignatureToString(msig);
			const char *comp_name = fcomp->Name;
			llll_appendsym(this_component_ll, gensym(msig_txt), 0, WHITENULL_llll);
			if (comp_name)
				llll_appendsym(this_component_ll, gensym(comp_name), 0, WHITENULL_llll);
			llll_appendllll(this_framedef_ll, this_component_ll, 0, WHITENULL_llll);
		}
		llll_appendllll(frametypes_ll, this_framedef_ll, 0, WHITENULL_llll);
	}
	SdifKillHashTableIterator(frametypes_iterator);
	
	if (frametypes_ll->l_size == 0)
		llll_free(frametypes_ll);
	else {
		llll_prependsym(frametypes_ll, gensym("frametypes"), 0, WHITENULL_llll);
		llll_appendllll(header_ll, frametypes_ll, 0, WHITENULL_llll);
	}
	
	
	// matrix types
	
	
	SdifHashTableT *mttable = SdifFGetMatrixTypesTable(file);
	t_llll *matrixtypes_ll = llll_make();
	SdifHashTableIteratorT *matrixtypes_iterator = SdifCreateHashTableIterator(NULL);
	
	SdifHashTableIteratorInitLoop(matrixtypes_iterator, mttable);
	while (SdifHashTableIteratorIsNext(matrixtypes_iterator)) {
		t_llll *this_matrixdef_ll = llll_make();
		SdifMatrixTypeT *mt = (SdifMatrixTypeT *) SdifHashTableIteratorGetNext(matrixtypes_iterator);
		SdifSignature msig = mt->Signature;
		const char *msig_txt = SdifSignatureToString(msig);
		llll_appendsym(this_matrixdef_ll, gensym(msig_txt), 0, WHITENULL_llll);
	
		t_llll *colnames_ll = llll_make();
		int ncols = SdifMatrixTypeGetNbColumns(mt);
		int j;
		for (j = 1; j <= ncols; j++) {
			const char *colname = SdifMatrixTypeGetColumnName(mt, j);
			if (colname)
				llll_appendsym(colnames_ll, gensym(colname), 0, WHITENULL_llll);
			else
				llll_appendllll(colnames_ll, llll_make(), 0, WHITENULL_llll);
		}
		llll_appendllll(this_matrixdef_ll, colnames_ll, 0, WHITENULL_llll);
		llll_appendllll(matrixtypes_ll, this_matrixdef_ll, 0, WHITENULL_llll);
	}
	SdifKillHashTableIterator(matrixtypes_iterator);

	if (matrixtypes_ll->l_size == 0)
		llll_free(matrixtypes_ll);
	else {
		llll_prependsym(matrixtypes_ll, gensym("matrixtypes"), 0, WHITENULL_llll);
		llll_appendllll(header_ll, matrixtypes_ll, 0, WHITENULL_llll);
	}
	

	// body
	
	t_shashtable *stream2ll = shashtable_new(0);
	
	while (!eof  && SdifFLastError (file) == NULL)
	{
		bytesread += SdifFReadFrameHeader(file);
		/* search for a frame we're interested in */
		while (!SdifFCurrFrameIsSelected (file)) {
			bytesread += SdifFSkipFrameData (file);
			if ((eof = SdifFGetSignature(file, &bytesread) == eEof))
				break;                                         /* eof */
			bytesread += SdifFReadFrameHeader(file);
		}
		
		if (!eof) {    /* Access frame header information */
			SdifFloat8      time     = SdifFCurrTime (file);
			SdifSignature   sig      = SdifFCurrFrameSignature (file);
			t_atom_ulong    streamid = SdifFCurrID (file);
			SdifUInt4       nmatrix  = SdifFCurrNbMatrix (file);
			unsigned long	m;
			
			t_llll *stream_ll = (t_llll *) shashtable_retrieve(stream2ll, streamid);
			
			if (!stream_ll) {
				stream_ll = llll_make();
				llll_appendlong(stream_ll, streamid, 0, WHITENULL_llll);
				llll_appendllll(sdif_ll, stream_ll, 0, WHITENULL_llll);
				shashtable_insert_with_key(stream2ll, stream_ll, streamid, 0);
			}
			
			char *frame_signature = SdifSignatureToString(sig); // don't even need to free it!
			t_llll *frame_ll = llll_make();
			llll_appendsym(frame_ll, gensym(frame_signature), 0, WHITENULL_llll);
			llll_appenddouble(frame_ll, time * 1000, 0, WHITENULL_llll);
			
			/* Read all matrices in this frame matching the selection. */
			for (m = 0; m < nmatrix; m++) {
				bytesread += SdifFReadMatrixHeader (file);
				
				if (SdifFCurrMatrixIsSelected (file)) {    /* Access matrix header information */
					SdifSignature	sig   = SdifFCurrMatrixSignature (file);
					SdifInt4	nrows = SdifFCurrNbRow (file);
					SdifInt4	ncols = SdifFCurrNbCol (file);
					SdifDataTypeET	type  = SdifFCurrDataType (file);
					char *matrix_signature = SdifSignatureToString(sig); // don't even need to free it!
					switch (type) {
						case eFloat4a:
						case eFloat4b:
							type = eFloat4;
							break;
						case eFloat8a:
						case eFloat8b:
							type = eFloat8;
							break;
						default:
							break;
					}
					t_llll *matrix_ll = llll_make();
					llll_appendsym(matrix_ll, gensym(matrix_signature), 0, WHITENULL_llll);
					t_llll *matrixdata_ll = llll_make();
					char *matrix_txt = NULL;
					if ((type & 0xFF00) == (eText & 0xFF00))
						matrix_txt = (char *) bach_newptr(ncols + 1);
					long row, col;
					SdifFloat8 value;
					
					for (row = 0; row < nrows; row++) {
						t_llll *row_ll = NULL;
						bytesread += SdifFReadOneRow (file);
						if (!matrix_txt)
							row_ll = llll_make();
						for (col = 1; col <= ncols; col++) {
							/* Access value by value... */
							value = SdifFCurrOneRowCol (file, col);
							switch (type & 0xFF00) {
								case (eText & 0xFF00):
									matrix_txt[col - 1] = value;
									break;
								case (eFloat4 & 0xFF00):
									llll_appenddouble(row_ll, value, 0, WHITENULL_llll);
									break;
								case (eInt1 & 0xFF00):
								case (eUInt1 & 0xFF00):
									llll_appendlong(row_ll, value, 0, WHITENULL_llll);
									break;
								default:
									break;
							}
						}
						if (matrix_txt) {
							matrix_txt[ncols] = 0;
							llll_appendsym(matrixdata_ll, gensym(matrix_txt), 0, WHITENULL_llll);
							bach_freeptr(matrix_txt);
						} else
							llll_appendllll(matrixdata_ll, row_ll, 0, WHITENULL_llll);
					}
					llll_appendllll(matrix_ll, matrixdata_ll, 0, WHITENULL_llll);
					llll_appendllll(frame_ll, matrix_ll, 0, WHITENULL_llll);
				} else {
					bytesread += SdifFSkipMatrixData(file);
				}
				
				bytesread += SdifFReadPadding(file, SdifFPaddingCalculate(file->Stream, bytesread));
			} 
			
			llll_appendllll(stream_ll, frame_ll, 0, WHITENULL_llll);

			/* read next signature */
			eof = SdifFGetSignature(file, &bytesread) == eEof;
			
		}
	}
	SdifErrorT *err = NULL;
	
	if ((err = SdifFLastError (file)))   /* Check for errors */
	{
		post("SDIF error: %s", err->UserMess);
	}
	
	SdifFClose(file);
	
	shashtable_free(stream2ll);
	
	llll_inplacesort(sdif_ll, (sort_fn) readsdif_cmp_by_stream);
	
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, sdif_ll, 1);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, header_ll, 0);
	llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 2);
	if (x->n_auto)
		readsdif_bang(x);
}

long readsdif_cmp_by_stream(void *dummy, t_llllelem *a, t_llllelem *b)
{
	t_atom_long strid1 = a->l_hatom.h_w.w_llll->l_head->l_hatom.h_w.w_long;
	t_atom_long strid2 = b->l_hatom.h_w.w_llll->l_head->l_hatom.h_w.w_long;
	return strid1 <= strid2;

}


void readsdif_fakeexit(void)
{
	dev_post("here we'd want to exit!!!");
}

void readsdif_assist(t_readsdif *x, void *b, long m, long a, char *s)
{
	if (m == ASSIST_INLET) {
		sprintf(s, "read / bang"); // @in 0 @type read/bang @digest Read to load an SDIF file, bang to output its contents
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): header", type);		break;	// @out 0 @type llll @digest header llll
			case 1:	sprintf(s, "llll (%s): body", type);		break;	// @out 1 @type llll @digest body llll
			case 2:	sprintf(s, "bang When Finished Reading");	break;	// @out 2 @type bang @digest bang when loading is completed
		}
	}
}

void readsdif_inletinfo(t_readsdif *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void readsdif_free(t_readsdif *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_readsdif *readsdif_new(t_symbol *s, short ac, t_atom *av)
{
	t_readsdif *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_readsdif *) object_alloc_debug(readsdif_class))) {
		attr_args_process(x, ac, av);		
		llllobj_obj_setup((t_llllobj_object *) x, 0, "b44");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
