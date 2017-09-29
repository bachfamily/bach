/**
 @file
 reg.c
 
 @name 
 bach.reg
 
 @realname 
 bach.reg
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Store an llll
 
 @description
 Stores an llll to be retrieved with a bang.
 
 @discussion
 If the <m>embed</m> attribute is set to 1, the llll is saved with the patcher.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 store, output

 @seealso
 bach.write, bach.shelf, bach.value, bach.pv, bach.portal
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

#include "bach_rat.hpp"
#include "pitchparser.h"

typedef struct _reg
{
	struct llllobj_object 	n_ob;
	void					*n_proxy;
	long					n_embed;
	long					n_in;
    
    t_object                *m_editor;
    
    t_pitchparser_wrapper   ppw;
} t_reg;

//DEFINE_LLLL_ATTR_DEFAULT_GETTER_AND_SETTER(t_reg, dummy, reg_getattr_dummy, reg_setattr_dummy)

void reg_assist(t_reg *x, void *b, long m, long a, char *s);
void reg_inletinfo(t_reg *x, void *b, long a, char *t);
void reg_appendtodictionary(t_reg *x, t_dictionary *d);

t_reg *reg_new(t_symbol *s, short ac, t_atom *av);
void reg_free(t_reg *x);

void reg_bang(t_reg *x);
void reg_int(t_reg *x, t_atom_long v);
void reg_float(t_reg *x, double v);
void reg_anything(t_reg *x, t_symbol *msg, long ac, t_atom *av);


// editor
void reg_okclose(t_reg *x, char *s, short *result);
void reg_edclose(t_reg *x, char **ht, long size);
void reg_dblclick(t_reg *x);


t_class *reg_class;


int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.reg", (method)reg_new, (method)reg_free, (short)sizeof(t_reg), 0L, A_GIMME, 0);

	// @method llll @digest Store the llll
	// @description In left inlet: the llll is stored and output. <br />
	// In right inlet: the llll is stored.
	class_addmethod(c, (method)reg_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)reg_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)reg_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)reg_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the llll
	// @description A bang in the left inlet outputs the stored llll.
	class_addmethod(c, (method)reg_bang,		"bang",			0);
	class_addmethod(c, (method)reg_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)reg_inletinfo,	"inletinfo",	A_CANT,		0);
	class_addmethod(c, (method)reg_appendtodictionary,	"appendtodictionary", A_CANT, 0);

    
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)reg_dblclick,		"dblclick",		A_CANT, 0);
    class_addmethod(c, (method)reg_edclose,         "edclose",		A_CANT, 0);
    class_addmethod(c, (method)reg_okclose,         "okclose",       A_CANT, 0);

    
    
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "embed",	0,	t_reg, n_embed);
	CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
	CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
	CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
	CLASS_ATTR_SAVE(c, "embed", 0);
	CLASS_ATTR_BASIC(c, "embed", 0);
	// @description When set to 1, the stored llll is saved with the patcher
	// and will be available, to be retrieved with a bang, next time the patch is loaded.
	
	class_register(CLASS_BOX, c);
    
	reg_class = c;
	
	dev_post("bach.reg compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void reg_dblclick(t_reg *x)
{
    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    t_llll *ll = llllobj_get_store_contents((t_object *)x, LLLL_OBJ_VANILLA, 0, 0);
    llll_to_text_buf_pretty(ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, 0, NULL);
    object_method(x->m_editor, _sym_settext, buf, gensym("utf-8"));
    object_attr_setsym(x->m_editor, gensym("title"), gensym("llll"));
    llll_release(ll);
}

void reg_okclose(t_reg *x, char *s, short *result)
{
    *result = 3;
}

void reg_edclose(t_reg *x, char **ht, long size)
{
    // do something with the text
    if (ht) {
        t_atom av;
        atom_setobj(&av, *ht);
        t_llll *ll = llll_parse(1, &av);
        if (ll) {
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}




void reg_bang(t_reg *x)
{
	if (proxy_getinlet((t_object *) x) == 0)
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
/*
    t_rat<t_int16> r(2,4);
    post("%ld", r.num());
    t_urrat<t_int32> u = r;
    t_rat<t_atom_long> s = t_rat<t_atom_long>(r);
    t_rat<t_atom_long> t(3,4);
    s += t;
    s += t_rat<t_atom_long> (3, 4);
    post("%ld/%ld", s.num(), s.den());
    s += t_rat<t_atom_long>(3);
    ++s;
    --s;
    t_rat<t_atom_long> w = s + t_rat<t_atom_long>(r) + t_rat<t_atom_long>(2);
    double d = w;
    t_rat<t_atom_long> fd = t_rat<t_atom_long>(0.5);
    post("%lf", d);
    t_rat<t_int32> a = t_rat<t_int32>(2,3);
    t_rat<t_int32> b = t_rat<t_int32>(2,3);
    t_rat<t_int32> c = a + b;
    t_rat<t_int32> e = a;
    e += 2;
    //e = e.plusEqual(2);
    int uno = 1;
    //post("is_integral: %ld", std::is_integral<double>::value);
    //post("int 2: %ld", foofoo(uno, 1));
    c = a + t_rat<t_int32>(1);
    c = a + 3;
    c = 3 + a;
    c = 3 - a;
    c = 3 * a;
    c = 3 / a;
    bool boo;
    boo = a == b;
    boo = a == 1;
    boo = a != 1;
    boo = a < b;

    //c = 3 * a.inv();
 */
    /*
    t_rat<t_int32> r1(3, 9);
    t_rat<t_int32> r2(1, 2);
    t_rat<t_int32> r3;
    r3 = r1 + r2;
    r3 = r1 - r2;
    r3 = r1 * r2;
    r3 = r1 / r2;
    
    long i1 = 2;
    r3 = r1 + i1;
    r3 = r1 - i1;
    r3 = r1 * i1;
    r3 = r1 / i1;
    
    t_bool b1;
    b1 = r1 == r2;
    b1 = r1 != r2;
    b1 = r1 < r2;
    b1 = r1 > r2;
    b1 = r1 <= r2;
    b1 = r1 >= r2;
    
    b1 = r1 == r1;
    b1 = r1 != r1;
    b1 = r1 < r1;
    b1 = r1 > r1;
    b1 = r1 <= r1;
    b1 = r1 >= r1;
   
    b1 = r1 == i1;
    b1 = r1 != i1;
    b1 = r1 < i1;
    b1 = r1 > i1;
    b1 = r1 <= i1;
    b1 = r1 >= i1;
    
    t_rat<t_int32> r4(2, 1);
    b1 = r4 == i1;
    b1 = r4 != i1;
    b1 = r4 < i1;
    b1 = r4 > i1;
    b1 = r4 <= i1;
    b1 = r4 >= i1;
    
    r3 = i1 + r1;
    r3 = i1 * r1;
    r3 = i1 - r1;
    r3 = i1 / r1;
*/
}

void reg_int(t_reg *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	reg_anything(x, _sym_int, 1, &outatom);
}

void reg_float(t_reg *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	reg_anything(x, _sym_float, 1, &outatom);
}

void reg_anything(t_reg *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *in_llll;
    
#define testtest
#ifdef testtest

    t_pitch p = pitchparser_scan_string(&x->ppw, msg->s_name);
    post("%s", p.toCString());
    
    
    
    
    
    if (msg == gensym("testtest")) {
        const char *txt = "12345 678 1/2 1/4 \"foo bar\" foo bar 10 (c#4 d4-2/10t)";
        atom a;
        atom_setobj(&a, (void *) txt);
        in_llll = llll_parse(1, &a);
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, in_llll);
        llll_free(in_llll);
        
        
        t_pitch p1, p2, p3;
        std::string s3;
        
        p1 = t_pitch(3, t_pitch::natural, 1); // f1
        p2 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: g1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::flat, 0); // db0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: g1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: g#1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::sharp, 0); // d#0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: gx1
        
        p1 = t_pitch(3, t_pitch::natural, 1); // f1
        p2 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: eb1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::flat, 0); // db0
        p3 = p1 - p2; //
        s3 = p3.toString(); // expected: e#1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: e1
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(1, t_pitch::sharp, 0); // d#0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: eb1
        
        
        
        
        p1 = t_pitch(3, t_pitch::natural, 1); // f1
        p2 = t_pitch(5, t_pitch::natural, 0); // a0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: d2
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(5, t_pitch::flat, 0); // ab0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: d2
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(5, t_pitch::natural, 0); // a0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: d#2
        
        p1 = t_pitch(3, t_pitch::sharp, 1); // f#1
        p2 = t_pitch(5, t_pitch::sharp, 0); // a#0
        p3 = p1 + p2;
        s3 = p3.toString(); // expected: dx2
        
        p1 = t_pitch(3, t_pitch::natural, 2); // f2
        p2 = t_pitch(6, t_pitch::natural, 0); // b0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: gb1
        
        p1 = t_pitch(3, t_pitch::sharp, 2); // f#2
        p2 = t_pitch(6, t_pitch::flat, 0); // bb0
        p3 = p1 - p2; //
        s3 = p3.toString(); // expected: g#1
        
        p1 = t_pitch(3, t_pitch::sharp, 2); // f#2
        p2 = t_pitch(6, t_pitch::natural, 0); // b0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: g1
        
        p1 = t_pitch(3, t_pitch::sharp, 2); // f#1
        p2 = t_pitch(6, t_pitch::sharp, 0); // b#0
        p3 = p1 - p2;
        s3 = p3.toString(); // expected: gb1
        
        
        p1 = t_pitch(3, t_pitch::natural, 0); // f0
        p3 = p1 * 1;
        s3 = p3.toString(); // expected: f0

        p1 = t_pitch(3, t_pitch::natural, 0); // f0
        p3 = p1 * 2;
        s3 = p3.toString(); // expected: bb0
        
        p1 = t_pitch(3, t_pitch::natural, 0); // f0
        p3 = p1 * 3;
        s3 = p3.toString(); // expected: eb1
        
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * 1;
        s3 = p3.toString(); // expected: eb1
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * 2;
        s3 = p3.toString(); // expected: gb2
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * 3;
        s3 = p3.toString(); // expected: bbb0
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * 4;
        s3 = p3.toString(); // expected: dbb1
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * 3;
        s3 = p3.toString(); // expected: bbb3
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * 4;
        s3 = p3.toString(); // expected: dbb5
        
        
        p1 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = -p1;
        s3 = p3.toString(); // expected: bb-1
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = -p1;
        s3 = p3.toString(); // expected: a-1
 
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = -p1;
        s3 = p3.toString(); // expected: a-2
        
        p1 = t_pitch(1, t_pitch::natural, -1); // d-1
        p3 = -p1;
        s3 = p3.toString(); // expected: bb0
        
        p1 = t_pitch(2, t_pitch::flat, -1); // eb-1
        p3 = -p1;
        s3 = p3.toString(); // expected: a0
        
        p1 = t_pitch(2, t_pitch::flat, -2); // eb-2
        p3 = -p1;
        s3 = p3.toString(); // expected: a1
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * -1;
        s3 = p3.toString(); // expected: a-1
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * -2;
        s3 = p3.toString(); // expected: f#-1
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * -3;
        s3 = p3.toString(); // expected: d#-1
        
        p1 = t_pitch(2, t_pitch::flat, 0); // eb0
        p3 = p1 * -4;
        s3 = p3.toString(); // expected: b#-2
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * -1;
        s3 = p3.toString(); // expected: a-2
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * -2;
        s3 = p3.toString(); // expected: f#-3
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * -3;
        s3 = p3.toString(); // expected: d#-4
        
        p1 = t_pitch(2, t_pitch::flat, 1); // eb1
        p3 = p1 * -4;
        s3 = p3.toString(); // expected: b#-6
        
        p1 = t_pitch(2, t_pitch::natural, 4); // e4
        p2 = t_pitch(0, t_pitch::natural, 1); // c1
        p3 = p1 % p2;
        s3 = p3.toString(); // expected: e0
        
        p1 = t_pitch(1, t_pitch::natural, 0); // c1
        p2 = t_pitch(3, t_pitch::natural, 0); // f0
        p3 = p1 % p2;
        s3 = p3.toString(); // expected: d0
        
        p1 = t_pitch(2, t_pitch::natural, -4); // e-4
        p2 = t_pitch(0, t_pitch::natural, 1); // c1
        p3 = p1 % p2;
        s3 = p3.toString(); // expected: e-1
        
        p1 = t_pitch(2, t_pitch::natural, 4); // e4
        p2 = t_pitch(0, t_pitch::natural, -1); // c-1
        p3 = p1 % p2;
        s3 = p3.toString(); // expected: e0
        
        p1 = t_pitch(1, t_pitch::flat * 3, 4); // dbbb1
        p2 = t_pitch(0, t_pitch::natural, 1); // c1
        p3 = p1 % p2;
        s3 = p3.toString(); // expected: dbbb1
        
        p1 = t_pitch(2, t_pitch::natural, 0); // e0
        p3 = p1 / 2;
        s3 = p3.toString(); // expected: d0
        
        p1 = t_pitch(4, t_pitch::flat, 0); // gb0
        p3 = p1 / 2;
        s3 = p3.toString(); // expected: eb0
        
        p1 = t_pitch(1, t_pitch::natural, 1); // d1
        p3 = p1 / 2;
        s3 = p3.toString(); // expected: g0
        
        p1 = t_pitch(2, t_pitch::natural, 2); // e2
        p3 = p1 / 4;
        s3 = p3.toString(); // expected: g0
        
        p1 = t_pitch(2, t_pitch::natural, 2); // e2
        p3 = p1 / 2;
        s3 = p3.toString(); // expected: d1
        
        p1 = t_pitch(0, t_pitch::natural, 1); // c1
        p3 = p1 / 2;
        s3 = p3.toString(); // expected: f#0?
        
        p1 = t_pitch(0, t_pitch::natural, 1); // c1
        p3 = p1 % 2;
        s3 = p3.toString(); // expected: dbb0
        
        p1 = t_pitch(1, t_pitch::natural, 0); // d0
        p3 = p1 / -1;
        s3 = p3.toString(); // expected: bb-1
        
        p1 = t_pitch(2, t_pitch::natural, 0); // e0
        p3 = p1 / -2;
        s3 = p3.toString(); // expected: bb-1
        
        p1 = t_pitch(1, t_pitch::natural, -1); // d-1
        p3 = p1 / -1;
        s3 = p3.toString(); // expected: bb0
        
        p1 = t_pitch(2, t_pitch::natural, -1); // e-1
        p3 = p1 / -2;
        s3 = p3.toString(); // expected: e0
        
        post("foo");

        return;
    }
#endif // testtest
    
    in_llll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
	if (!in_llll)
		return;
	
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, in_llll, 0);

	if (proxy_getinlet((t_object *) x) == 0)
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void reg_assist(t_reg *x, void *b, long m, long a, char *s)
{
	if (m == ASSIST_INLET) {
		if (a == 0)	sprintf(s, "llll to Store and Output / bang"); // @in 0 @type llll/bang @digest Store and output llll
		// @description An llll is stored and output, a bang outputs the stored llll.
		else sprintf(s, "llll to Store");
		// @in 1 @type llll @digest llll to store
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Stored llll
	}
}

void reg_inletinfo(t_reg *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void reg_appendtodictionary(t_reg *x, t_dictionary *d)
{
	if (x->n_embed) {
		llll_store_in_dictionary(x->n_ob.l_incache[0].s_ll, d, "reg_data", &x->n_ob.l_incache[0].s_lock);
	}
}

void reg_free(t_reg *x)
{
	object_free_debug(x->n_proxy);
    pitchparser_free(&x->ppw);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_reg *reg_new(t_symbol *s, short ac, t_atom *av)
{
	t_reg *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	t_llll *def_llll;
	t_dictionary *d;
	
	if ((x = (t_reg *) object_alloc_debug(reg_class))) {
        
        pitchparser_new(&x->ppw);
        
        x->m_editor = NULL;

        // @arg 0 @name default @optional 1 @type llll @digest Default llll
		// @description An optional default llll. 
		// If an llll has been saved with the patcher through the <m>embed</m> attribute,
		// it will override the argument llll.
		long true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
		if (true_ac) {
			def_llll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 0);
			if (def_llll)
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, def_llll, 0);
		}

		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);

		d = (t_dictionary *)gensym("#D")->s_thing;
		if (d) {
			def_llll = llll_retrieve_from_dictionary(d, "reg_data");
			if (def_llll) {
				llll_retain(def_llll);
				llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, def_llll, 0);
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, def_llll, 0);
				x->n_embed = 1;
			}
		}
	}
	
	
	if (x && err == MAX_ERR_NONE)
		return x;

	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
