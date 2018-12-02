/**
    @file
    pad.c
    
    @name
    bach.pad
    
    @realname
    bach.pad
 
    @type
    object
    
    @module
    bach
 
    @author
    bachproject
    
    @digest
    Pad, loop or trim an llll
    
    @description
    Pads, loops or trims an llll in order to match a given length.
 
    @discussion
    If the required length is less than the original one, the llll can be trimmed, depending on the
    <m>trim</m> attribute.
 
    @category
    bach, bach objects, bach llll
 
    @keywords
    repeat, size, length, trim, extend, loop
 
    @seealso
    bach.length, bach.repeat
    
    @owner
    Daniele Ghisi
 */


#include "llllobj.h"
#include "llll_commons_ext.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"




typedef struct _pad
{
    t_llllobj_object     n_ob;
    void                *n_proxy[3];
    long                n_in;
    
    long                n_output_size; // output size
    
    char                n_mode;         // one of the #e_pad_mode
    long                n_loopsize;     // loop size (for loop mode only)
    char                n_trim;         // allow trimming
    char                n_align;        // alignment
    char                n_rounding;     // rounding direction (for non-evenly distributed center-alignment)
} t_pad;




void pad_assist(t_pad *x, void *b, long m, long a, char *s);
void pad_inletinfo(t_pad *x, void *b, long a, char *t);

t_pad *pad_new(t_symbol *s, short ac, t_atom *av);
void pad_free(t_pad *x);

void pad_bang(t_pad *x);
void pad_int(t_pad *x, t_atom_long v);
void pad_float(t_pad *x, double v);
void pad_anything(t_pad *x, t_symbol *msg, long ac, t_atom *av);

t_class *pad_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.pad", (method)pad_new, (method)pad_free, (short)sizeof(t_pad), 0L, A_GIMME, 0);
    
    // @method llll @digest Function depends on inlet
    // @description
    // In first inlet: the incoming llll is padded or trimmed (accorded to the attribute values), and the result is output from the outlet.<br />
    // In second inlet: the incoming llll is converted into an <m>int</m>.<br />
    // In third inlet: sets the padding element (or elements, for "Loop" <m>mode</m>).
    // This can be a single symbol or integer, such as <b>0</b> or <b>foo</b>, or a complex llll of size 1, such as
    // <b>[1 2 4]</b>, or - in "Loop" <m>mode</m> - any complex <m>llll</m>, from which the padding elements should be picked.
    // Setting <b>null</b> forces <o>bach.pad</o> to repeat the elements of the incoming list (default).
    class_addmethod(c, (method)pad_anything,    "anything",        A_GIMME,    0);
    
    // @method int @digest Sets output length
    // @description A non-negative integer in the second inlet sets the desired output length for padding or trimming.
    class_addmethod(c, (method)pad_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)pad_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)pad_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Repeat last operation
    // @description Returns the padding of the most recently received llll.
    class_addmethod(c, (method)pad_bang,        "bang",            0);
    
    class_addmethod(c, (method)pad_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)pad_inletinfo,    "inletinfo",    A_CANT,        0);

    CLASS_ATTR_CHAR(c, "mode", 0, t_pad, n_mode);
    CLASS_ATTR_STYLE_LABEL(c,"mode",0,"text","Padding Mode");
    CLASS_ATTR_ENUMINDEX(c, "mode", 0, "Repeat Loop Palindrome Loop Palindrome Loop No Repetitions");
    CLASS_ATTR_BASIC(c,"mode",0);
    // @description Sets the padding mode: <br />
    // - <b>Repeat</b> (default) just copies a single element (the first or last element, depending on the <m>align</m> attribute) over and over,
    // until the desired length has been reached (e.g.: ABCDDDDDD...); <br />
    // - <b>Loop</b> copies the whole llll (or a portion of it, depending on the <m>loopsize</m> attribute) over and over, until the desired length
    // has been reached. Last copy can of course be trimmed, if it overflows the desired length (e.g.: ABCDABCDABCDABCD...); <br />
    // - <b>Palindrome Loop</b> is like the previous one, but reverses the loop direction at each new loop (e.g.: ABCDDCBAABCDDCBA...); <br />
    // - <b>Palindrome Loop No Repetitions</b> is like the previous one, but avoids repetitions at the loop beginning or end (e.g.: ABCDCBABCDCBA...).

    CLASS_ATTR_LONG(c, "loopsize", 0, t_pad, n_loopsize);
    CLASS_ATTR_STYLE_LABEL(c,"loopsize",0,"text","Number of Elements to Repeat");
    // @description Sets the number of elements to be repeated in "Loop" <m>mode</m> (has no effect in "Repeat" <m>mode</m>)

    
    CLASS_ATTR_CHAR(c, "trim", 0, t_pad, n_trim);
    CLASS_ATTR_STYLE_LABEL(c,"trim",0,"onoff","Trim If Needed");
    CLASS_ATTR_BASIC(c,"trim",0);
    // @description If the <m>trim</m> attribute is set to 1 (default),
    // when the output length is less than the length of the original llll, this latter
    // is trimmed at output; otherwise it is output as it is.
    
    CLASS_ATTR_CHAR(c, "align", 0, t_pad, n_align);
    CLASS_ATTR_STYLE_LABEL(c,"align",0,"enumindex","Alignment");
    CLASS_ATTR_ENUMINDEX(c, "align", 0, "Left Center Right");
    CLASS_ATTR_BASIC(c,"align",0);
    // @description Sets the alignment of the original llll within the padded llll. <br />
    // - If alignment is 0 = <b>Left</b> (default), the padding will be done at right. <br />
    // - If alignment is 1 = <b>Center</b> the padding will be equally done at left and at right
    // (rounding to the right). <br />
    // - If alignment is 2 = <b>Right</b>, the padding will be done at left.
    
    CLASS_ATTR_CHAR(c, "roundalign", 0, t_pad, n_rounding);
    CLASS_ATTR_STYLE_LABEL(c,"roundalign",0,"enumindex","Rounding Alignment Direction");
    CLASS_ATTR_ENUMINDEX(c, "roundalign", 0, "Left Right");
    // @description Sets the rounding direction for the specific situation where the <m>align</m> attribute is set to "Center" and
    // an odd number of elements should be split into right and left padding. <br />
    // - If <m>roundalign</m> is 0 = <b>Left</b> (default), one more element is given at the right padding side; <br />
    // - If <m>roundalign</m> is 1 = <b>Right</b>, one more element is given at the left padding side. <br />
    
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    

    class_register(CLASS_BOX, c);
    pad_class = c;
    
    dev_post("bach.pad compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void pad_bang(t_pad *x)
{    
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        pad_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void pad_int(t_pad *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    pad_anything(x, _sym_int, 1, &outatom);
}

void pad_float(t_pad *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    pad_anything(x, _sym_float, 1, &outatom);
}

void pad_anything(t_pad *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *ll, *reservoir;
    long inlet = proxy_getinlet((t_object *) x);    
    if (inlet == 0) {
        if (msg != _sym_bang) {
            ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
            if (!ll)
                return;
        } else
            ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, true);
        
        
        reservoir = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 0);
        llll_pad(ll, x->n_output_size, x->n_align, (e_pad_mode)x->n_mode, x->n_loopsize, reservoir, x->n_trim, x->n_rounding);
        llll_release(reservoir);
        x->n_ob.l_rebuild = 0;
        llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, ll, 0);
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
    } else if (inlet == 1) {
        t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
        if (ll && ll->l_head && is_hatom_number(&ll->l_head->l_hatom))
            x->n_output_size = hatom_getlong(&ll->l_head->l_hatom);
        llll_release(ll);
    } else {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 2);
        x->n_ob.l_rebuild = 1;
    }
}

void pad_assist(t_pad *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) {
        if (a == 0) sprintf(s, "llll"); // @in 0 @type llll @digest The llll to be padded or trimmed
        else if (a == 1) sprintf(s, "int: Output Length"); // @in 1 @type int @digest The output length
        else sprintf(s, "llll: Padding Elements"); // @in 2 @type anything/llll @digest The padding element(s)
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest The padded or trimmed llll
    }
}

void pad_inletinfo(t_pad *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void pad_free(t_pad *x)
{
    long i;
    for (i = 2; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_pad *pad_new(t_symbol *s, short ac, t_atom *av)
{
    t_pad *x = NULL;
    t_max_err err = 0;
    long true_ac;
    
    
    if ((x = (t_pad *) object_alloc_debug(pad_class))) {
        long i;
        x->n_output_size = 0;
        x->n_align = 0;
        x->n_rounding = 0;
        x->n_loopsize = 0;
        x->n_mode = BACH_PAD_REPEAT;
        x->n_trim = 1;
        
        
        true_ac = attr_args_offset(ac, av);
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 3, "4");
        if (true_ac) {

            // @arg 0 @name output_length @optional 0 @type int @digest Output length
            // @description The first integer argument sets the output length, i.e. the target length that
            // the output llll must have.
            if (atom_gettype(av) == A_LONG)
                x->n_output_size = atom_getlong(av);

            if (true_ac > 1) {
                // @arg 1 @name padding_elements @optional 1 @type llll @digest Padding element or elements
                // @description The second argument sets the element used for padding (or elements, in "Loop" <m>mode</m>).
                // This can be a single symbol or integer, such as <b>0</b> or <b>foo</b>, or a complex llll of size 1, such as
                // <b>[1 2 4]</b>, or - in "Loop" <m>mode</m> - any complex <m>llll</m>, from which the padding elements should be picked.
                // Not setting this argument, or setting it as <b>null</b> forces <o>bach.pad</o> to repeat the
                // elements of the incoming list (default).
                llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac - 1, av + 1, 2);
            }
        }
        for (i = 2; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
    } else
        error(BACH_CANT_INSTANTIATE);        
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
