/**
 @file
 insert.c
 
 @name 
 bach.insert
 
 @realname 
 bach.insert
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Insert elements in an llll
 
 @description
 Inserts elements at specified addresses of an llll.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 insert, element, address, introduce, add

 @seealso
 bach.subs, bach.replace, bach.find, bach.nth
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"


typedef struct _insert
{
	t_llllobj_object	n_ob;
	long				n_mode;
	long				n_multi;
	void				*n_proxy[3];
	long				n_in;
} t_insert;


void insert_assist(t_insert *x, void *b, long m, long a, char *s);
void insert_inletinfo(t_insert *x, void *b, long a, char *t);

t_insert *insert_new(t_symbol *s, short ac, t_atom *av);
void insert_free(t_insert *x);

void insert_bang(t_insert *x);
void insert_int(t_insert *x, t_atom_long v);
void insert_float(t_insert *x, double v);
void insert_anything(t_insert *x, t_symbol *msg, long ac, t_atom *av);

t_max_err insert_setattr_set(t_insert *x, t_object *attr, long ac, t_atom *av);

t_class *insert_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.insert", (method)insert_new, (method)insert_free, (short)sizeof(t_insert), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// In first inlet: the elements received in the third inlet will be inserted in the llll.<br />
	// In second inlet: the address or addresses at which the elements must be inserted.
	// The syntax depends on the value of the <m>multi</m> attribute:
	// if it is 0, a single address is expected; if it is 1, an llll whose sublists are separate addresses, at which separate insertions have to be performed, is expected.
	// If single elements at the root level are encountered, they are treated as single-element sublist.
	// This means that in the multiple insertions case the lllls <b>(1) (2 3) (4) (5)</b> and <b>1 (2 3) 4 (5)</b> are considered the same,
	// and in both cases four insertions are performed.
	// As a general rule, for each insertion the first inserted element will have the specified address.
	// In the case of multiple insertions, these leads to some additional complexity managed through the <m>mode</m> attribute.
	// Both positive and negative addresses are correctly treated, 
	// but the result can be hardly predictable when multiple insertions are performed mixing positive and negative addresses on a single sublist,
	// or when multiple insertions are performed on a single position.<br/>
	// @copy BACH_DOC_ADDRESS_BASIC
	// If an address points to a non-existing position, the necessary elements will be created as empty sublists whenever possible,
	// but only in single insertion mode or in multiple insertion mode with the <m>mode</m> attribute is set to 1.
	// In multiple insertion mode with the <m>mode</m> attribute set to 0, or if the element creation is not possible according to the original list structure, the given insertion is ignored.<br/>
	// In third inlet: the elements to insert.
	// The syntax depends on the value of the <m>multi</m> attribute:
	// if it is 0, a single sequence of elements is expected;
	// if it is 1, an llll whose sublists are separate sequence of elements, each to be inserted at the corresponding given address, is expected.
	// If single elements at the root level are encountered, they are treated as single-element sublist.
	// This means that in the multiple insertions case the lllls <b>(a) (b c) (d) (e)</b> and <b>a (b c) d (e)</b> are considered the same.
	// If less sequences to insert than addresses are provided, the last sequence is repeated over and over. 
	// This is especially useful to insert the same sequence at many addresses, as providing the sequence only once is enough.
	// If more sequences than addresses are provided, the exceeding sequences are ignored.
	class_addmethod(c, (method)insert_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)insert_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)insert_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)insert_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Perform the insertion with the most recently received lllls.
	class_addmethod(c, (method)insert_bang,			"bang",			0);
	
	class_addmethod(c, (method)insert_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)insert_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LONG(c, "multi",	0,	t_insert, n_multi);
	CLASS_ATTR_STYLE_LABEL(c, "multi", 0, "onoff", "Multiple Insertions");
	CLASS_ATTR_FILTER_CLIP(c, "multi", 0, 1);
	CLASS_ATTR_BASIC(c, "multi", 0);	
	// @description
	// When set to 1, multiple insertions can be performed.
	// This changes the syntax for the second and third inlets - see the description of the <m>llll</m> message.
	
	CLASS_ATTR_LONG(c, "mode",	0,	t_insert, n_mode);
	CLASS_ATTR_STYLE_LABEL(c, "mode", 0, "onoff", "Multiple Insertion Mode");
	CLASS_ATTR_FILTER_CLIP(c, "mode", 0, 1);
	CLASS_ATTR_BASIC(c, "mode", 0);	
	// @description
	// The <m>mode</m> attribute controls the detailed meaning of the addresses for multiple insertions.
	// When set to 0 (default), the addresses refer to positions in the original llll.
	// This means, e.g., that if the llll <b>(a) (b)</b> is received in the third inlet (sequences to insert),
	// the llll <b>(2) (3)</b> is received in the second inlet (addresses),
	// and the llll <b>10 20 30</b> is received in the left inlet (llll to perform the insertion upon),
	// the result of the double insertion will be <b>10 a 20 b 30</b>, that is the addresses are computed independently
	// with respect to the original llll, and the insertions are performed "right before" the specified original addresses.
	// If the addresses were negative, the insertions would have been performed "right after" the specified original addresses. <br />
	// If the <m>mode</m> attribute is set to 1, the addresses refer to positions in the resulting llll,
	// that is each insertion will be performed so that the position of the first element of each sequence 
	// matches the corresponding given address in the resulting llll.
	// In the above example, the resulting llll would thus be <b>10 a b 20 30</b>, so that <b>a</b> and <b>b</b>
	// take the second and third position respectively.
	
	CLASS_ATTR_LLLL(c, "set", 0, t_insert, n_ob, NULL, insert_setattr_set); // struct field is dummy
	CLASS_ATTR_INVISIBLE(c, "set", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);
	// @description
	// The <m>set</m> attribute allows setting the insertion elements.
	// This is especially useful when used in the object box.
	

	class_register(CLASS_BOX, c);
	insert_class = c;
	
	dev_post("bach.insert compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err insert_setattr_set(t_insert *x, t_object *attr, long ac, t_atom *av)
{
	if ((ac == 0 || av) && x->n_ob.l_running) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, 2);
	}
	return MAX_ERR_NONE;
}

void insert_bang(t_insert *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		insert_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void insert_int(t_insert *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	insert_anything(x, _sym_int, 1, &outatom);
}

void insert_float(t_insert *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	insert_anything(x, _sym_float, 1, &outatom);
}

void insert_anything(t_insert *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *address, *wedge;
	
	switch (proxy_getinlet((t_object *) x)) {
		case 0:
            if (msg != _sym_bang) {
                ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!ll)
                    return;
            }
            else
                ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            if (x->n_multi == 0) {
                address = llll_get();
                llll_appendllll(address, llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1), 0, WHITENULL_llll);
                wedge = llll_get();
                llll_appendllll(wedge, llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 1), 0, WHITENULL_llll);
            } else {
                address = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
                wedge = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 1);			
            }
            if (x->n_mode == 0 && x->n_multi == 1)
                llll_multiinsert_a(ll, address, wedge);
            else
                llll_multiinsert_b(ll, address, wedge);
            x->n_ob.l_rebuild = 0;
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			break;

		case 1:
			llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1, true, false);
			x->n_ob.l_rebuild = 1;
			break;
			
		case 2: 
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 2);
			x->n_ob.l_rebuild = 1;
			break;
	}
}

void insert_assist(t_insert *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll to Insert in"); // @in 0 @type llll @digest llll to insert the new elements in
		else if (a == 1) sprintf(s, "llll: Address"); // @in 1 @type llll @digest Addresses
		else sprintf(s, "llll to Insert"); // @in 2 @type llll @digest Elements to insert
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest llll with the new elements inserted
	}
}

void insert_inletinfo(t_insert *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void insert_free(t_insert *x)
{
	long i;
	for (i = 2; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_insert *insert_new(t_symbol *s, short ac, t_atom *av)
{
	t_insert *x = NULL;
	long i;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_insert *) object_alloc_debug(insert_class))) {
		// @arg 0 @name address @optional 1 @type llll @digest Default insertion address(es)
		// @description The initial address or addresses at which the insertion must be performed
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 3, "4");
		if (true_ac)
			llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 1, true, false);


		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);

        attr_args_process(x, ac, av);
        
        t_llll *address = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        if (address->l_size == 0) {
            t_llll *new_address = llll_get();
            llll_appendlong(new_address, 1);
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, new_address, 1);
        }
        llll_release(address);
	} else
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}