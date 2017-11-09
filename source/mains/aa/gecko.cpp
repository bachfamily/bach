/**
 @file
 gecko.c
 
 @name 
 bach.gecko
 
 @realname 
 bach.gecko
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 hidden
 
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

#include <gecode/int.hh>
#include <gecode/search.hh>

/// VERY IMPORTANT:
// these files are usually pre-included through the "prefix header" build setting
// but since they conflict with the geckode headers, they must be explicitly included here
#include <Carbon/Carbon.h>
#include <QuickTime/QuickTime.h>


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"


typedef struct _gecko
{
	struct llllobj_object 	n_ob;
	void					*n_proxy;
	long					n_embed;
	long					n_in;
} t_gecko;

//DEFINE_LLLL_ATTR_DEFAULT_GETTER_AND_SETTER(t_gecko, dummy, gecko_getattr_dummy, gecko_setattr_dummy)

void gecko_assist(t_gecko *x, void *b, long m, long a, char *s);
void gecko_inletinfo(t_gecko *x, void *b, long a, char *t);
void gecko_appendtodictionary(t_gecko *x, t_dictionary *d);

t_gecko *gecko_new(t_symbol *s, short ac, t_atom *av);
void gecko_free(t_gecko *x);

void gecko_bang(t_gecko *x);
void gecko_int(t_gecko *x, t_atom_long v);
void gecko_float(t_gecko *x, double v);
void gecko_anything(t_gecko *x, t_symbol *msg, long ac, t_atom *av);

//void gecko_debugdict(t_gecko *x);

t_class *gecko_class;


using namespace Gecode;

class SendMoreMoney : public Space {
protected:
    IntVarArray l;
public:
    SendMoreMoney(void) : l(*this, 8, 0, 9) {
        IntVar s(l[0]), e(l[1]), n(l[2]), d(l[3]),
        m(l[4]), o(l[5]), r(l[6]), y(l[7]);
        // no leading zeros
        rel(*this, s, IRT_NQ, 0);
        rel(*this, m, IRT_NQ, 0);
        // all letters distinct
        distinct(*this, l);
        // linear equation
        IntArgs c(4+4+5); IntVarArgs x(4+4+5);
        c[0]=1000; c[1]=100; c[2]=10; c[3]=1;
        x[0]=s;    x[1]=e;   x[2]=n;  x[3]=d;
        c[4]=1000; c[5]=100; c[6]=10; c[7]=1;
        x[4]=m;    x[5]=o;   x[6]=r;  x[7]=e;
        c[8]=-10000; c[9]=-1000; c[10]=-100; c[11]=-10; c[12]=-1;
        x[8]=m;      x[9]=o;     x[10]=n;    x[11]=e;   x[12]=y;
        linear(*this, c, x, IRT_EQ, 0);
        // post branching
        branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
    }
    // search support
    SendMoreMoney(bool share, SendMoreMoney& s) : Space(share, s) {
        l.update(*this, share, s.l);
    }
    virtual Space* copy(bool share) {
        return new SendMoreMoney(share,*this);
    }
    // print solution
    void print(void) const {
        /*
         std::ostringstream ostr;
         ostr << l << std::endl;
         std::string mystring = ostr.str();
         const char *mycstr = mystring.c_str();
         fprintf(stderr, "%s\n", mycstr); */
        
        int i;
        for (i = 0; i < 8; i++) {
            int v = l[i].val();
            fprintf(stderr, "%d\n", v);
        }
    }
    
    
    void output(t_gecko *x, int outnum) const {
        t_atom a[8];
        int i;
        for (i = 0; i < 8; i++) {
            atom_setlong(a+i, l[i].val());
        }
        llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, outnum, _sym_list, 8, a);
    }
};






int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.gecko", (method)gecko_new, (method)gecko_free, (short)sizeof(t_gecko), 0L, A_GIMME, 0);

	// @method llll @digest Store the llll
	// @description In left inlet: the llll is stored and output. <br />
	// In right inlet: the llll is stored.
	class_addmethod(c, (method)gecko_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)gecko_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)gecko_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)gecko_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the llll
	// @description A bang in the left inlet outputs the stored llll.
	class_addmethod(c, (method)gecko_bang,		"bang",			0);
	class_addmethod(c, (method)gecko_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)gecko_inletinfo,	"inletinfo",	A_CANT,		0);
	class_addmethod(c, (method)gecko_appendtodictionary,	"appendtodictionary", A_CANT, 0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "embed",	0,	t_gecko, n_embed);
	CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
	CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
	CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
	CLASS_ATTR_SAVE(c, "embed", 0);
	CLASS_ATTR_BASIC(c, "embed", 0);
	// @description When set to 1, the stored llll is saved with the patcher
	// and will be available, to be retrieved with a bang, next time the patch is loaded.
	
	class_register(CLASS_BOX, c);
	gecko_class = c;
	
	dev_post("bach.gecko compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void gecko_bang(t_gecko *x)
{
    SendMoreMoney* m = new SendMoreMoney;
    DFS<SendMoreMoney> e(m);
    delete m;
    // search and print all solutions
    while (SendMoreMoney* s = e.next()) {
        s->output(x, 0);
        delete s;
    }
}

void gecko_int(t_gecko *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	gecko_anything(x, _sym_int, 1, &outatom);
}

void gecko_float(t_gecko *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	gecko_anything(x, _sym_float, 1, &outatom);
}

void gecko_anything(t_gecko *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll;
    in_llll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
	if (!in_llll)
		return;
	
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, in_llll, 0);

	if (proxy_getinlet((t_object *) x) == 0)
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void gecko_assist(t_gecko *x, void *b, long m, long a, char *s)
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

void gecko_inletinfo(t_gecko *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void gecko_appendtodictionary(t_gecko *x, t_dictionary *d)
{
	if (x->n_embed) {
		llll_store_in_dictionary(x->n_ob.l_incache[0].s_ll, d, "gecko_data", &x->n_ob.l_incache[0].s_lock);
	}
}

void gecko_free(t_gecko *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_gecko *gecko_new(t_symbol *s, short ac, t_atom *av)
{
	t_gecko *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	t_llll *def_llll;
	t_dictionary *d;
	
	if ((x = (t_gecko *) object_alloc_debug(gecko_class))) {
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
			def_llll = llll_retrieve_from_dictionary(d, "gecko_data");
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
