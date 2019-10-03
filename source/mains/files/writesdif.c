/*
 *  writesdif.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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
 writesdif.c
 
 @name 
 bach.writesdif
 
 @realname 
 bach.writesdif
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Write an SDIF file
 
 @description 
 Writes an SDIF file starting from its llll representation.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 SDIF, write, save, disk, file, convert

 @seealso
 bach.readsdif, bach.write, bach.roll
 
 @owner
 Andrea Agostini
 */

/*
 ---header format:
 (nvt ((name1 value1) (name2 value2) ...)
	  ((name1 value1) (name2 value2) ...)
	  ...)
 (frametypes (frame_sig1 (matrix_sig1 (col_name1 col_name2 ...)) 
						 (matrix_sig2 (col_name1 col_name2 ...))
						 ... ) 
			 (frame_sig2 (matrix_sig1 (col_name1 col_name2)) 
						 (matrix_sig2 (col_name1 col_name2))
						 ...)
			 ...)
 (matrixtypes (matrix_sig1 (col_name1 col_name2 ...)) 
			  (matrix_sig2 (col_name1 col_name2 ...))

			  ...)


 
 ---body format:
 (str_id1 (frame_sig1 ms1 (mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						  (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						   ... )
		  (frame_sig2 ms2 (mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						  (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... )
		  ...)
 (str_id2 (frame_sig1 ms1 (mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						  (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... )
		  (frame_sig2 ms2 (mat_sig1 ((col1 col2 ...) (col1 col2 ...) ...))
						  (mat_sig2 ((col1 col2 ...) (col1 col2 ...) ...))
						  ... )
		  ...)
 ...
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "libraries/SDIF-3.11.4-src/include/sdif.h"
#include <stdio.h>

typedef struct _writesdif
{
	t_llllobj_object	n_ob;
	void				*n_proxy[3];
	long				n_in;
} t_writesdif;


void writesdif_assist(t_writesdif *x, void *b, long m, long a, char *s);
void writesdif_inletinfo(t_writesdif *x, void *b, long a, char *t);

t_writesdif *writesdif_new(t_symbol *s, short ac, t_atom *av);
void writesdif_free(t_writesdif *x);

void writesdif_int(t_writesdif *x, t_atom_long v);
void writesdif_float(t_writesdif *x, double v);
void writesdif_anything(t_writesdif *x, t_symbol *msg, long ac, t_atom *av);
void writesdif_dowrite(t_writesdif *x, t_symbol *msg, long ac, t_atom *av);
long writesdif_cmp_by_time(void *dummy, t_llllelem *a, t_llllelem *b);
SdifSignature writesdif_get_signature_from_hatom(t_writesdif *x, t_hatom *h);

void writesdif_fakeexit(void);

t_class *writesdif_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.writesdif", (method)writesdif_new, (method)writesdif_free, (long) sizeof(t_writesdif), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// An llll received in the second inlet sets the header of the SDIF file to be written.
	// An llll received in the third inlet sets the body of the SDIF file to be written.<br/><br/>
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
	// It should be noted that minimal error and consistency checking is performed.
	// As a consequence, if the input data are not semantically correct, the resulting SDIF file can be invalid
	// and other applications may refuse to open it.
	class_addmethod(c, (method)writesdif_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)writesdif_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)writesdif_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)writesdif_anything,	"list",			A_GIMME,	0);

	// @method write @digest Write the SDIF file
	// @description
	// The SDIF file whose contents have been passed to <o>bach.writesdif</o> is written to disk.
	// A file name can be provided as a message argument; otherwise, a dialog box will open.
	// @marg 0 @name file_name @optional 1 @type symbol		
	class_addmethod(c, (method)writesdif_anything,	"write",		A_GIMME,	0);
	class_addmethod(c, (method)writesdif_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)writesdif_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	SdifGenInitCond("");
	SdifSetExitFunc((SdifExitFuncT) writesdif_fakeexit);
	
	class_register(CLASS_BOX, c);
	writesdif_class = c;
	
	dev_post("bach.writesdif compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void writesdif_int(t_writesdif *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	writesdif_anything(x, _sym_int, 1, &outatom);
}

void writesdif_float(t_writesdif *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	writesdif_anything(x, _sym_float, 1, &outatom);
}

void writesdif_dowrite(t_writesdif *x, t_symbol *s, long ac, t_atom *av)
{
	t_fourcc outtype;
	char filename[512];
	char filepath[MAX_PATH_CHARS];
	short path;
	t_llll *header_ll = (t_llll *) atom_getobj(av);
	t_llll *raw_body_ll = (t_llll *) atom_getobj(av + 1);

	t_llll *halfcooked_body_ll = llll_make();
	t_llllelem *stream_elem;
	t_llll *cooked_body_ll = NULL;
	
	SdifFileT *file = NULL;
	t_hashtab *newmatrices = hashtab_new_debug(0);

	// error-checking and preparing the cooked body
	// the cooked body will be ordered time-wise, and have the following structure:
	/*
	 (stream_id1 frame_sig1 time1 (data_type1 ncols1 matrix_sig1 ( (col1 col2 ...) (col1 col2 ...) ) )
								  (data_type2 ncols2 matrix_sig2 ( (col1 col2 ...) (col1 col2 ...) ) )
								  ...)
	 (stream_id2 frame_sig2 time2 (data_type1 ncols1 matrix_sig1 ( (col1 col2 ...) (col1 col2 ...) ) )
								  (data_type2 ncols2 matrix_sig2 ( (col1 col2 ...) (col1 col2 ...) ) )
								  ...)
	 ...
	 */
	for (stream_elem = raw_body_ll->l_head; stream_elem; stream_elem = stream_elem->l_next) {
		bach_assert_objerror_goto(x, stream_elem->l_hatom.h_type == H_LLLL, "bad body llll: stream is not an llll", writesdif_exit);
		t_llll *stream_ll = stream_elem->l_hatom.h_w.w_llll;
		bach_assert_objerror_goto(x, stream_ll->l_size >= 2, "bad body llll: insufficient stream data", writesdif_exit);
		bach_assert_objerror_goto(x, hatom_is_number(&stream_ll->l_head->l_hatom), "bad body llll: stream ID is not a number", writesdif_exit);
		t_atom_long stream_id = hatom_getlong(&stream_ll->l_head->l_hatom);
		t_llllelem *frame_elem;
		for (frame_elem = stream_ll->l_head->l_next; frame_elem; frame_elem = frame_elem->l_next) {
			bach_assert_objerror_goto(x, frame_elem->l_hatom.h_type == H_LLLL, "bad body llll: frame is not an llll", writesdif_exit);
			t_llll *frame_ll = frame_elem->l_hatom.h_w.w_llll;
			bach_assert_objerror_goto(x, frame_ll->l_size >= 2, "bad body llll: insufficient frame data", writesdif_exit);
			t_llllelem *frame_data_elem = frame_ll->l_head;
			bach_assert_objerror_goto(x, frame_data_elem->l_hatom.h_type != H_LLLL, "bad body llll: signature is an llll", writesdif_exit); // signature must not be an llll
			frame_data_elem = frame_data_elem->l_next;
			bach_assert_objerror_goto(x, hatom_is_number(&frame_data_elem->l_hatom) != 0, "bad body llll: time is not a number", writesdif_exit); // time must be a number

			t_llll *frame_ll_clone = llll_clone(frame_ll);
			llll_prependlong(frame_ll_clone, stream_id, 0, WHITENULL_llll);
			llll_appendllll(halfcooked_body_ll, frame_ll_clone, 0, WHITENULL_llll);
			// frame_ll_clone is now identical to the frame definition ll in the original file,
			// but with the stream_id prepended
			
			t_llllelem *matrix_elem;
			
			// loop on the frame components
			for (matrix_elem = frame_ll_clone->l_head->l_next->l_next->l_next; matrix_elem; matrix_elem = matrix_elem->l_next) {
				bach_assert_objerror_goto(x, matrix_elem->l_hatom.h_type == H_LLLL, "bad body llll: frame data is not an llll", writesdif_exit);
				t_llll *matrix_ll = matrix_elem->l_hatom.h_w.w_llll;
				bach_assert_objerror_goto(x, matrix_ll->l_size == 2, "bad body llll: bad frame data", writesdif_exit);
				long row_size = 0;
				long matrix_hatom_type = H_NOTHING;
				long matrix_type = 0;
				t_llllelem *matrix_data_elem;
				// loop on the component data
				for (matrix_data_elem = matrix_ll->l_head; matrix_data_elem; matrix_data_elem = matrix_data_elem->l_next) {
					bach_assert_objerror_goto(x, matrix_data_elem->l_hatom.h_type != H_LLLL, "bad body llll: matrix signature is an llll", writesdif_exit);
					//writesdif_get_signature_from_hatom(x, &matrix_data_elem->l_hatom);
					matrix_data_elem = matrix_data_elem->l_next;
					t_llll *matrix_data_ll = hatom_getllll(&matrix_data_elem->l_hatom);
					bach_assert_objerror_goto(x, matrix_data_ll, "bad body llll: matrix data is not an llll", writesdif_exit);
					bach_assert_objerror_goto(x, matrix_data_ll->l_depth <= 2, "bad body llll: matrix row contains lllls", writesdif_exit);
					t_llllelem *row_elem;
					for (row_elem = matrix_data_ll->l_head; row_elem; row_elem = row_elem->l_next) {
						switch (row_elem->l_hatom.h_type) {
							case H_LLLL: 
							{
								bach_assert_objerror_goto(x, matrix_hatom_type == H_NOTHING || matrix_hatom_type != H_SYM, 
														  "bad body llll: inconsistent data type", writesdif_exit);
								t_llll *row_ll = row_elem->l_hatom.h_w.w_llll;
								long ok_size = 1;
								if (row_size == 0) {
									row_size = row_ll->l_size;
								} else if (row_size != row_ll->l_size)
									ok_size = 0;
								bach_assert_objerror_goto(x, ok_size, "bad body llll: inconsistent matrix row size", writesdif_exit);
								t_llllelem *col_elem;
								for (col_elem = row_ll->l_head; col_elem; col_elem = col_elem->l_next) {
									long type = col_elem->l_hatom.h_type;
									bach_assert_objerror_goto(x, hatom_type_is_number(type), "bad body llll: row contains symbols", writesdif_exit);
									if (matrix_hatom_type < type)
										matrix_hatom_type = type;
								}
								break;
							}
							case H_SYM:
							{
								bach_assert_objerror_goto(x, matrix_hatom_type == H_NOTHING || matrix_hatom_type == H_SYM, "bad body llll: inconsistent data type", writesdif_exit);
								long len = strlen(row_elem->l_hatom.h_w.w_sym->s_name);
								if (len >= row_size)
									row_size = len;
								matrix_hatom_type = H_SYM;
								break;
							}
						}
					}

				}
				switch (matrix_hatom_type) {
					case H_LONG:	matrix_type = eInt8;	break;
					case H_DOUBLE:	matrix_type = eFloat8;	break;
					case H_SYM:		matrix_type = eText;	break;
					default:		break;
				}
				llll_prependlong(matrix_ll, row_size, 0, WHITENULL_llll);
				llll_prependlong(matrix_ll, matrix_type, 0, WHITENULL_llll);
			}
		}
	}
	llll_mergesort(halfcooked_body_ll, &cooked_body_ll, (sort_fn) writesdif_cmp_by_time, NULL);
	halfcooked_body_ll = NULL;
	
	if (!s || s == gensym("")) {      // if no argument supplied, ask for file
		strncpy_zero(filename, "Untitled.sdif", 512);
		if (saveasdialog_extended(filename, &path, &outtype, NULL, 0))     // non-zero: user cancelled
			goto writesdif_exit;
	} else {
		strcpy(filename, s->s_name);
		path = path_getdefault();
	}
	path_toabsolutesystempath(path, filename, filepath);
	
	file = SdifFOpen(filepath, eWriteFile);
	
	// here we need to write the header!
	t_llllelem *header_elem;
	for (header_elem = header_ll->l_head; header_elem; header_elem = header_elem->l_next) {
		bach_assert_objerror_goto(x, header_elem->l_hatom.h_type == H_LLLL, "bad header llll: data are not lllls", writesdif_exit);
		t_llll *header_item_ll = header_elem->l_hatom.h_w.w_llll;
		t_llllelem *header_item_elem = header_item_ll->l_head;
		bach_assert_objerror_goto(x, header_item_elem && header_item_elem->l_hatom.h_type == H_SYM, "bad header llll: key is not a symbol", writesdif_exit);
		t_symbol *header_item_type = header_item_elem->l_hatom.h_w.w_sym;

		if (header_item_type == gensym("nvt")) {		
/*
  (nvt ((name1 value1) (name2 value2) ...)
	  ((name1 value1) (name2 value2) ...)
	  ...)
*/
			SdifNameValuesLNewTable(file->NameValues, 0xffffffff);
			for (header_item_elem = header_item_elem->l_next; header_item_elem; header_item_elem = header_item_elem->l_next) {
				bach_assert_objerror_goto(x, header_item_elem->l_hatom.h_type == H_LLLL, "bad header llll", writesdif_exit);
				t_llll *table_ll = header_item_elem->l_hatom.h_w.w_llll;
				t_llllelem *table_elem;
				for (table_elem = table_ll->l_head; table_elem; table_elem = table_elem->l_next) {
					bach_assert_objerror_goto(x, table_elem->l_hatom.h_type == H_LLLL, "bad header llll", writesdif_exit);
					t_llll *nv_ll = table_elem->l_hatom.h_w.w_llll;
					bach_assert_objerror_goto(x, nv_ll->l_size == 2, "bad header llll", writesdif_exit);
					t_llllelem *name_elem = nv_ll->l_head;
					t_llllelem *value_elem = nv_ll->l_tail;
					bach_assert_objerror_goto(x, name_elem->l_hatom.h_type == H_SYM && value_elem->l_hatom.h_type != H_LLLL, "bad header llll", writesdif_exit);
					char value_txt[512];
					switch (value_elem->l_hatom.h_type) {
						case H_SYM:
							strncpy_zero(value_txt, value_elem->l_hatom.h_w.w_sym->s_name, 512);
							break;
						case H_LONG:
							snprintf_zero(value_txt, 512, ATOM_LONG_PRINTF_FMT, value_elem->l_hatom.h_w.w_long);
							break;
						case H_RAT:
							snprintf_zero(value_txt, 512, RATIONAL_PRINTF_FMT, value_elem->l_hatom.h_w.w_rat.r_num, value_elem->l_hatom.h_w.w_rat.r_den);
							break;
						case H_DOUBLE:
							snprintf_zero(value_txt, 512, "%lf", value_elem->l_hatom.h_w.w_double);
							break;	
					}
					SdifNameValuesLPutCurrNVTTranslate(file->NameValues, name_elem->l_hatom.h_w.w_sym->s_name, value_txt);
				}
			}
			
		} else if (header_item_type == gensym("frametypes")) {
/*			
			 (frametypes (frame_sig1 (matrix_sig1 [component_name1]) 
									 (matrix_sig2 [component_name2])
						  ... ) 
						 (frame_sig2 (matrix_sig1 [component_name1]) 
									 (matrix_sig2 [component_name2])
						  ... )

			 ...)
*/			
			
			
			// loop on frame types
			for (header_item_elem = header_item_elem->l_next; header_item_elem; header_item_elem = header_item_elem->l_next) {
				bach_assert_objerror_goto(x, header_item_elem->l_hatom.h_type == H_LLLL, "bad header llll: frame definition is not an llll", writesdif_exit);
				t_llll *framedef_ll = header_item_elem->l_hatom.h_w.w_llll;
				bach_assert_objerror_goto(x, framedef_ll->l_size >= 2, "bad header llll: insufficient data in frame definition", writesdif_exit);

				t_llllelem *framedef_elem = framedef_ll->l_head;
				bach_assert_objerror_goto(x, framedef_elem && framedef_elem->l_hatom.h_type != H_LLLL, "bad header llll: frame signature is an llll", writesdif_exit);
				SdifSignature frame_signature = writesdif_get_signature_from_hatom(x, &framedef_elem->l_hatom);
				SdifFrameTypeT *frame_type = SdifGetFrameType(SdifFGetFrameTypesTable(file), frame_signature);
				if (!frame_type) {
					frame_type = SdifCreateFrameType(frame_signature, 
													 SdifGetFrameType(gSdifPredefinedTypes->FrameTypesTable, frame_signature));
					SdifPutFrameType(SdifFGetFrameTypesTable(file), frame_type);
				} else
					bach_assert_objerror_goto(x, SdifTestFrameTypeModifMode(file, frame_type), "bad header llll: bad frame definition", writesdif_exit);
				// loop on frame components
				for (framedef_elem = framedef_elem->l_next; framedef_elem; framedef_elem = framedef_elem->l_next) {
					bach_assert_objerror_goto(x, framedef_elem->l_hatom.h_type == H_LLLL, "bad header llll: frame component is not an llll", writesdif_exit);
					t_llll *component_ll = framedef_elem->l_hatom.h_w.w_llll;
					t_llllelem *component_elem = component_ll->l_head;
					bach_assert_objerror_goto(x, component_elem->l_hatom.h_type != H_LLLL, "bad header llll: frame component signature is an llll", writesdif_exit);
					
					SdifSignature matrix_signature = writesdif_get_signature_from_hatom(x, &component_elem->l_hatom);
					if (SdifTestMatrixType(file, matrix_signature)) {
						component_elem = component_elem->l_next;
						const char *component_name;
						if (component_elem) {
							bach_assert_objerror_goto(x, component_elem->l_hatom.h_type == H_SYM, "bad header llll: frame component name is not a symbol", writesdif_exit);
							component_name = component_elem->l_hatom.h_w.w_sym->s_name;
						} else
							component_name = (char *) "";
						SdifFrameTypePutComponent(frame_type, matrix_signature, component_name);
					}
				}
				frame_type->ModifMode = eNoModif;
			}
			
		} else if (header_item_type == gensym("matrixtypes")) {
/*
	 (matrixtypes (matrix_sig1 (col_name1 col_name2 ...))
				  (matrix_sig2 (col_name1 col_name2 ...))	
				  ...)		
*/
			// loop on matrix types
			for (header_item_elem = header_item_elem->l_next; header_item_elem; header_item_elem = header_item_elem->l_next) {
				bach_assert_objerror_goto(x, header_item_elem->l_hatom.h_type == H_LLLL, "bad header llll: frame definition is not an llll", writesdif_exit);
				t_llll *matrixdef_ll = header_item_elem->l_hatom.h_w.w_llll;
				t_llllelem *matrixdef_elem = matrixdef_ll->l_head;
				bach_assert_objerror_goto(x, matrixdef_elem && matrixdef_elem->l_hatom.h_type != H_LLLL, "bad header llll: matrix signature is an llll", writesdif_exit);
				SdifSignature matrix_signature = writesdif_get_signature_from_hatom(x, &matrixdef_elem->l_hatom);
				SdifMatrixTypeT *matrix_type = SdifGetMatrixType(SdifFGetMatrixTypesTable(file), matrix_signature);																 
				if (!matrix_type) {
					matrix_type = SdifCreateMatrixType(matrix_signature, 
													   SdifGetMatrixType(gSdifPredefinedTypes->MatrixTypesTable, matrix_signature));
					SdifPutMatrixType(SdifFGetMatrixTypesTable(file), matrix_type);
				} else
					bach_assert_objerror_goto(x, SdifTestMatrixTypeModifMode(file, matrix_type), "bad header llll: bad matrix definition", writesdif_exit);
				
				matrixdef_elem = matrixdef_elem->l_next;
				bach_assert_objerror_goto(x, matrixdef_elem, "bad header llll: matrix definition without columns", writesdif_exit);
				t_llll *columns_ll = hatom_getllll(&matrixdef_elem->l_hatom);
				bach_assert_objerror_goto(x, columns_ll != NULL, "bad header llll: definition of matrix columns is not an llll", writesdif_exit);
				
				t_llllelem *column_elem;
				// loop on matrix columns
				for (column_elem = columns_ll->l_head; column_elem; column_elem = column_elem->l_next) {
					t_symbol *column_name_sym = hatom_getsym(&column_elem->l_hatom);
					bach_assert_objerror_goto(x, column_name_sym != NULL, "bad header llll: matrix column name is not a symbol", writesdif_exit);
					SdifMatrixTypeInsertTailColumnDef(matrix_type, column_name_sym->s_name);
				}
				matrix_type->ModifMode = eNoModif;
			}
		} else {
			bach_assert_objerror_goto(x, 0, "bad header llll: key is not nvt, matrixtypes or frametypes", writesdif_exit);
		}
		

	}
	
	SdifFWriteGeneralHeader(file);
	SdifFWriteAllASCIIChunks(file);

	// and here we write the body
	t_llllelem *frame_elem;
	for (frame_elem = cooked_body_ll->l_head; frame_elem; frame_elem = frame_elem->l_next) {
		t_llll *frame_ll = frame_elem->l_hatom.h_w.w_llll;
		t_llllelem *frame_data_elem = frame_ll->l_head;
		t_atom_long stream_id = frame_data_elem->l_hatom.h_w.w_long;
		frame_data_elem = frame_data_elem->l_next;
		SdifSignature frame_signature = writesdif_get_signature_from_hatom(x, &frame_data_elem->l_hatom);
		

		
		frame_data_elem = frame_data_elem->l_next;
		double time = hatom_getdouble(&frame_data_elem->l_hatom) / 1000.;
		
		SdifUInt4 framesize = 0;
		SdifFSetCurrFrameHeader(file, frame_signature, _SdifUnknownSize, frame_ll->l_size - 3, stream_id, time);
		framesize += SdifFWriteFrameHeader(file);
 		//framesize += SdifFWriteMatrixHeader(file);

		for (frame_data_elem = frame_data_elem->l_next; frame_data_elem; frame_data_elem= frame_data_elem->l_next) {
			t_llll *matrix_ll = frame_data_elem->l_hatom.h_w.w_llll;
			long nrows = matrix_ll->l_size - 3; // type, ncols, sig
			t_llllelem *matrix_elem = matrix_ll->l_head;
			SdifDataTypeET matrix_type = (SdifDataTypeET) matrix_elem->l_hatom.h_w.w_long;
			matrix_elem = matrix_elem->l_next;
			long ncols = matrix_elem->l_hatom.h_w.w_long;
			matrix_elem = matrix_elem->l_next;
			SdifSignature matrix_signature = writesdif_get_signature_from_hatom(x, &matrix_elem->l_hatom);
			SdifFSetCurrMatrixHeader(file, matrix_signature, matrix_type, nrows, ncols);
			framesize += SdifFWriteMatrixHeader(file);
			
			matrix_elem = matrix_elem->l_next;
			t_llll *matrix_data_ll = matrix_elem->l_hatom.h_w.w_llll;
			t_llllelem *matrix_data_elem;
			
			long row;
			
			for (matrix_data_elem = matrix_data_ll->l_head, row = 0; matrix_data_elem; matrix_data_elem = matrix_data_elem->l_next, row++) {
				if (matrix_type != eText) {
					t_llllelem *col_elem;
					long col;
					t_llll *row_ll = matrix_data_elem->l_hatom.h_w.w_llll;
					for (col_elem = row_ll->l_head, col = 1; col_elem; col_elem = col_elem->l_next, col++) {
						double value = hatom_getdouble(&col_elem->l_hatom);
						SdifFSetCurrOneRowCol(file, col, value);
					}
				} else {
					long col;
					char *row_txt = matrix_data_elem->l_hatom.h_w.w_sym->s_name;
					for (col = 1; *row_txt; col++, row_txt++)
						SdifFSetCurrOneRowCol(file, col, *row_txt);
					for ( ; col <= ncols; col++)
						SdifFSetCurrOneRowCol(file, col, 0);
				}
				framesize += SdifFWriteOneRow(file);
			}
			framesize += SdifFWritePadding(file, SdifFPaddingCalculate (file->Stream, framesize));
			SdifUpdateChunkSize (file, framesize - 8);  /* Set frame size */
		}
	}

writesdif_exit:	
	if (file) {
		SdifFClose(file);
		//remove(filepath);
	}
	object_free_debug(newmatrices);
	llll_free(header_ll);
	llll_free(halfcooked_body_ll);
	llll_free(cooked_body_ll);
	llll_free(raw_body_ll);
	return;
}

long writesdif_cmp_by_time(void *dummy, t_llllelem *a, t_llllelem *b)
{
	t_atom_long strid1 = a->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom.h_w.w_double;
	t_atom_long strid2 = b->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom.h_w.w_double;
	return strid1 <= strid2;
	
}

SdifSignature writesdif_get_signature_from_hatom(t_writesdif *x, t_hatom *h)
{
	char signature_txt[5];
	switch (h->h_type) {
		case H_SYM:
			strncpy_zero(signature_txt, h->h_w.w_sym->s_name, 5);
			if (strlen(signature_txt) < 4) {
				object_warn((t_object *) x, "Too short frame signature: %s", signature_txt);
				snprintf_zero(signature_txt, 5, "%s    ", signature_txt);
			}
			break;
		case H_DOUBLE:
			snprintf_zero(signature_txt, 5, "%05lf", h->h_w.w_double);
			object_warn((t_object *) x, "Float frame signature: %lf", h->h_w.w_double);
			break;
		case H_LONG:
			snprintf_zero(signature_txt, 5, "%05" ATOM_LONG_FMT_MODIFIER "ld", h->h_w.w_long);
			object_warn((t_object *) x, "Int frame signature:" ATOM_LONG_PRINTF_FMT, h->h_w.w_double);
			break;
		case H_RAT:
			snprintf_zero(signature_txt, 5, "%05" ATOM_LONG_FMT_MODIFIER "ld", hatom_getlong(h));
			object_warn((t_object *) x, "Rational frame signature: " RATIONAL_PRINTF_FMT, h->h_w.w_rat.r_num, h->h_w.w_rat.r_den);
			break;
		default:
			break;
	}
	return SdifStringToSignature(signature_txt);
}

void writesdif_fakeexit(void)
{
	error("bach.writesdif: internal error");
}


void writesdif_anything(t_writesdif *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_symbol *path;
	long inlet = proxy_getinlet((t_object *) x);
	
	if (inlet) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet - 1);
		return;
	}
	
	if (msg == _sym_write) {
		t_atom outatom[2];
		t_llll *body_ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1);
		t_llll *header_ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0);
		path = ac ? atom_getsym(av) : gensym("");
		atom_setobj(outatom, header_ll);
		atom_setobj(outatom + 1, body_ll);
		defer(x, (method) writesdif_dowrite, path, 2, outatom);
	} else {
		object_error((t_object *) x, "Unknown message %s", msg->s_name);
	}
}

void writesdif_assist(t_writesdif *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "write");		break;	// in 0 @type write @digest Write the SDIF file
			case 1: sprintf(s, "llll: header");	break;	// in 1 @type llll @digest SDIF header
			case 2: sprintf(s, "llll: body");	break;	// in 2 @type llll @digest SDIF body
		}
	}
}

void writesdif_inletinfo(t_writesdif *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void writesdif_free(t_writesdif *x)
{
	long i;
	for (i = 2; i > 0; i--)
		object_free(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_writesdif *writesdif_new(t_symbol *s, short ac, t_atom *av)
{
	t_writesdif *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_writesdif *) object_alloc_debug(writesdif_class))) {
		long i;
		attr_args_process(x, ac, av);		
		llllobj_obj_setup((t_llllobj_object *) x, 2, "");
		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
