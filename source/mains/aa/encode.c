/**
 @file
 encode.c
 
 @name 
 bach.encode
 
 @realname 
 bach.encode
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 experimental
 
 @digest 
 Encode an llll for transmission
 
 @description
 Encodes an llll, which will have to be decoded by bach.decode
 
 @discussion
 
 @category
 bach, bach objects, bach llll

 @keywords
 encode, transmission, receive

 @seealso
 bach.decode
 
 @owner
 Andrea Agostini
 */

#define MAX_CHUNK_SIZE 32768

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_hashtab.h"
#include "ext_critical.h"

typedef struct _encode
{
	struct llllobj_object 	n_ob;
	long					n_chunksize;
} t_encode;

typedef struct _chunk
{
	t_atom *c_av;
	long c_ac;
} t_chunk;


void encode_assist(t_encode *x, void *b, long m, long a, char *s);
void encode_inletinfo(t_encode *x, void *b, long a, char *t);

t_encode *encode_new(t_symbol *s, short ac, t_atom *av);
void encode_free(t_encode *x);

void encode_bang(t_encode *x);
void encode_int(t_encode *x, t_atom_long v);
void encode_float(t_encode *x, double v);
void encode_anything(t_encode *x, t_symbol *msg, long ac, t_atom *av);

t_class *encode_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.encode", (method)encode_new, (method)encode_free, (short)sizeof(t_encode), 0L, A_GIMME, 0);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
	
	class_addmethod(c, (method)encode_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)encode_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)encode_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)encode_anything,		"list",			A_GIMME,	0);
	class_addmethod(c, (method)encode_bang,			"bang",			0);
	
	class_addmethod(c, (method)encode_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)encode_inletinfo,	"inletinfo",	A_CANT,		0);
		
	CLASS_ATTR_LONG(c, "chunksize",	0,	t_encode, n_chunksize);
	CLASS_ATTR_LABEL(c, "chunksize", 0, "Chunk Size");
	CLASS_ATTR_FILTER_CLIP(c, "chunksize", 4, MAX_CHUNK_SIZE);
	
	class_register(CLASS_BOX, c);
	encode_class = c;

    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	dev_post("bach.encode compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void encode_bang(t_encode *x)
{	
	encode_anything(x, _sym_bang, 0, NULL);
}

void encode_int(t_encode *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	encode_anything(x, _sym_int, 1, &outatom);
}

void encode_float(t_encode *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	encode_anything(x, _sym_float, 1, &outatom);
}

// format of the generated chunks (message selector is llll for all of them!):
// <id> start <tot_chunks> <checksum>
// or
// <id> <chunk_num> <data> ...


void encode_anything(t_encode *x, t_symbol *msg, long ac, t_atom *av)
{
	long data_ac, tot_chunks, i;
	long start, end, headersize = 0, nextatomsize, chunksize, chunk_ac;
	t_atom *data_av = NULL, *chunk_av;
	char *chunk_txt;
	t_chunk *thechunks;
	t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!ll)
		return;
	chunk_av = (t_atom *) bach_newptr(65536 * sizeof(t_atom));
	data_ac = llll_deparse(ll, &data_av, 0, LLLL_D_QUOTE | LLLL_D_MAX | LLLL_D_FLOAT64);
	llll_free(ll);	
	start = end = 0;
	tot_chunks = 0;
	thechunks = (t_chunk *) bach_newptr(512 * sizeof(t_chunk));
	atom_setlong(chunk_av, rand());
	atom_setsym(chunk_av + 1, _sym_start);
	atom_setlong(chunk_av + 2, LONG_MAX);
	atom_setlong(chunk_av + 3, 0);
	chunk_txt = NULL;
	atom_gettext(3, chunk_av, &headersize, &chunk_txt, 0);
	sysmem_freeptr(chunk_txt);
	while (start < data_ac) {
		chunksize = headersize + 1;
		nextatomsize = 0;
		chunk_txt = NULL;
		atom_gettext(1, data_av + end, &nextatomsize, &chunk_txt, 0);
		sysmem_freeptr(chunk_txt);
		do {
			chunksize += nextatomsize + 1;
			end++;
			if (end >= data_ac)
				break;
			chunk_txt = NULL;
			atom_gettext(1, data_av + end, &nextatomsize, &chunk_txt, 0);
			sysmem_freeptr(chunk_txt);
		} while (chunksize + nextatomsize + 1 < x->n_chunksize);
		thechunks[tot_chunks].c_ac = end - start;
		thechunks[tot_chunks].c_av = data_av + start;
		tot_chunks++;
		if (tot_chunks % 512 == 0)
			thechunks = (t_chunk *) bach_resizeptr(thechunks, (tot_chunks + 512) * sizeof(t_chunk));
		start = end;
	}
	atom_setlong(chunk_av + 2, tot_chunks);
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_llll, 4, chunk_av);
	
	for (i = 0; i < tot_chunks; i++) {
		atom_setlong(chunk_av + 1, i);
		chunk_ac = thechunks[i].c_ac;
		bach_copyptr(thechunks[i].c_av, chunk_av + 2, chunk_ac * sizeof(t_atom));
		llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_llll, chunk_ac + 2, chunk_av);
	}
	bach_freeptr(thechunks);
	bach_freeptr(data_av);
	bach_freeptr(chunk_av);
}


void encode_assist(t_encode *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
	} else 
		sprintf(s, "Data");
}

void encode_inletinfo(t_encode *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void encode_free(t_encode *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_encode *encode_new(t_symbol *s, short ac, t_atom *av)
{
	long true_ac;
	t_encode *x = NULL;
	t_max_err err = 0;
	
	srand(systime_ms());
	
	if ((x = (t_encode *) object_alloc_debug(encode_class))) {
		true_ac = attr_args_offset(ac, av);
		if (true_ac) 
			x->n_chunksize = atom_getlong(av);
		attr_args_process(x, ac, av);
		x->n_chunksize = (x->n_chunksize == 0) ? 1024 : CLAMP(x->n_chunksize, 4, MAX_CHUNK_SIZE);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "a", "llll");
		object_warn((t_object *) x, "This is a deprecated object which might not work as expected");
		object_warn((t_object *) x, "and might be fixed in a future release of bach");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}
