/*
 *  convertbase.c
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
	convertbase.c
	
	@name
	bach.convertbase
	
	@realname
	bach.convertbase
 
	@type
	object
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Perform base conversion for numbers
	
	@description
	Converts numbers from any base to any other base.
	
	@discussion
	
	@category
	bach, bach abstractions, bach math
 
	@keywords
	convert, base, conversion, number, digit
	
	@seealso
	bach.factorize, bach./, bach.%, bach.gcd, bach.lcm
	
	@owner
	Daniele Ghisi
 */


#include "foundation/llllobj.h"
#include "foundation/llll_commons_ext.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "math/bach_math_utilities.h"

enum {
    BACH_CONVERTBASE_OUTSYM_NEVER = 0,
    BACH_CONVERTBASE_OUTSYM_IFNEEDED = 1,
    BACH_CONVERTBASE_OUTSYM_ALWAYS = 2,
};

typedef struct _convertbase
{
	t_llllobj_object 	n_ob;
    void				*n_proxy[2];
	long				n_in;
    
    long                n_startbase;
    long                n_endbase;
    long                n_maxdecimals;
    char                n_symout_left;
    char                n_symout_right;
} t_convertbase;




void convertbase_assist(t_convertbase *x, void *b, long m, long a, char *s);
void convertbase_inletinfo(t_convertbase *x, void *b, long a, char *t);

t_convertbase *convertbase_new(t_symbol *s, short ac, t_atom *av);
void convertbase_free(t_convertbase *x);

void convertbase_int(t_convertbase *x, t_atom_long v);
void convertbase_float(t_convertbase *x, double v);
void convertbase_anything(t_convertbase *x, t_symbol *msg, long ac, t_atom *av);

t_class *convertbase_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.convertbase", (method)convertbase_new, (method)convertbase_free, (long) sizeof(t_convertbase), 0L, A_GIMME, 0);
	
    // @method llll @digest Set digits, output result
    // @description Any <m>llll</m> in the second inlet is considered as a plain list
    // of digits to be converted.
    // The conversion is performed, and the converted digits
    // are output from the right outlet, while the converted number (obtained by simply
    // juxtaposition of the same digits) is output from the left outlet. <br />
    // If the list is an <m>llll</m> of depth 2, it is interpreted as a floating point number,
    // having as first sublist the digits corresponding to the integer part of the number
    // and as second sublist the digits corresponding to the fractional part.
    class_addmethod(c, (method)convertbase_anything,	"anything",		A_GIMME,	0);
	
    // @method int @digest Set number, output result
    // @description Any integer in the left inlet is consider as the number to be converted,
    // written in the starting base (e.g. <b>21</b> meaning 7 if starting base is base 3).
    // The conversion is performed, and the converted digits
    // are output from the right outlet, while the converted number (obtained by simply
    // juxtaposition of the same digits) is output from the left outlet.
	class_addmethod(c, (method)convertbase_int,			"int",			A_LONG,		0);
    
    // @method float @digest Set number, output result
    // @description Any float in the left inlet
    // is consider as the number to be converted, written in the starting base
    // (e.g. <b>21.2</b> meaning 7.66666... if starting base is base 3).
    // The conversion is performed, and the converted digits
    // are output from the right outlet, with a level of parentheses around the
    // digits corresponding to the integer part, and a level of parentheses around the digits
    // corresponding to the fractional part. The converted number is output from the left outlet.
	class_addmethod(c, (method)convertbase_float,		"float",		A_FLOAT,	0);

    // @method rational @digest Set number, output result
    // @description Any rational number is converted into a floating point number. See <m>float</m>.
    class_addmethod(c, (method)convertbase_anything,	"list",			A_GIMME,	0);
	
	class_addmethod(c, (method)convertbase_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)convertbase_inletinfo,	"inletinfo",	A_CANT,		0);

    CLASS_ATTR_LONG(c, "startbase", 0, t_convertbase, n_startbase);
    CLASS_ATTR_STYLE_LABEL(c,"startbase",0,"text","Start Base");
    CLASS_ATTR_BASIC(c,"startbase",0);
    // @description The base of the original number or digits.
    
    CLASS_ATTR_LONG(c, "endbase", 0, t_convertbase, n_endbase);
    CLASS_ATTR_STYLE_LABEL(c,"endbase",0,"text","End Base");
    CLASS_ATTR_BASIC(c,"endbase",0);
    // @description The base in which the number should be converted.
    
    CLASS_ATTR_LONG(c, "maxdecimals", 0, t_convertbase, n_maxdecimals);
    CLASS_ATTR_STYLE_LABEL(c,"maxdecimals",0,"text","Maximum Decimal Digits");
    CLASS_ATTR_BASIC(c,"maxdecimals",0);
    // @description The maximum number of decimal digits for the conversion. Default is 6.

    CLASS_ATTR_CHAR(c, "numbersymout", 0, t_convertbase, n_symout_left);
    CLASS_ATTR_STYLE_LABEL(c,"numbersymout",0,"enumindex","Left Outlet Symbol Mode");
    CLASS_ATTR_ENUMINDEX(c,"numbersymout", 0, "Never If Needed Always");
    // @description Handles if and when symbols should be output instead of numbers from left inlet. <br />
    // - Never: always output number (this might result in incorrect output if <m>endbase</m> is greater than 10); <br />
    // - If Needed (default): if the converted number has alphabetic digits (e.g. "12AD9"), then it is output as a symbol,
    // otherwise it is output as a standard number; <br />
    // - Always: the converted number is always output as a symbol.

    CLASS_ATTR_CHAR(c, "digitssymout", 0, t_convertbase, n_symout_right);
    CLASS_ATTR_STYLE_LABEL(c,"digitssymout",0,"text","Right Outlet Symbol Mode");
    CLASS_ATTR_ENUMINDEX(c,"digitssymout", 0, "Never If Needed Always");
    // @description Handles if and when symbols should be output instead of digits from right inlet. <br />
    // - Never (default): always output number-like digits, even if digits are greater than 10 (i.e.: outputs "12" instead of "C", and so on) <br />
    // - If Needed: if the digit is alphabetical (e.g. "C"), then it is output as a symbol,
    // otherwise it is output as a standard number; <br />
    // - Always: the digits are always output as symbols.

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	convertbase_class = c;
	
	dev_post("bach.convertbase compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void convertbase_int(t_convertbase *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	convertbase_anything(x, _sym_int, 1, &outatom);
}

void convertbase_float(t_convertbase *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	convertbase_anything(x, _sym_float, 1, &outatom);
}


char does_any_digit_need_sym(t_llll *digits)
{
    if (digits->l_depth == 1) {
        for (t_llllelem *elem = digits->l_head; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_SYM)
                return true;
            if (hatom_gettype(&elem->l_hatom) == H_LONG && hatom_getlong(&elem->l_hatom) >= 10)
                return true;
        }
    } else {
        for (t_llllelem *elem = digits->l_head; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_LLLL)
                if (does_any_digit_need_sym(hatom_getllll(&elem->l_hatom)))
                    return true;
        }
    }
    return false;
}

t_symbol *double_to_symbol(double num, long maxdecimals)
{
    char buf[1024];
    snprintf_zero(buf, 1024, "%.*f", maxdecimals, num);
    return gensym(buf);
}

t_symbol *long_to_symbol(long num)
{
    char buf[1024];
    snprintf_zero(buf, 1024, "%ld", num);
    return gensym(buf);
}


long char_to_long(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    
    if (c >= 'A' && c <= 'Z')
        return 10 + c - 'A';
    
    if (c >= 'a' && c <= 'z')
        return 10 + c - 'a';
    
    return 0;
}

char long_to_char(long num)
{
    if (num >= 0 && num <= 9)
        return '0' + num;
    else if (num >= 10 && num <= 36)
        return 'A' + (num - 10);
    return '0';
}

t_symbol *digits_to_symbol(t_llll *digits)
{
    if (!digits || digits->l_size <= 0)
        return _llllobj_sym_empty_symbol;
    
    long buf_size = digits->l_size;
    char *buf = (char *)bach_newptr((buf_size + 1) * sizeof(char));
    long cur = 0;
    for (t_llllelem *elem = digits->l_head; elem; elem = elem->l_next, cur++) {
        if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *s = hatom_getsym(&elem->l_hatom);
            if (s && s->s_name[0]) {
                if (s->s_name[0] >= 'A' && s->s_name[0] <= 'Z')
                    buf[cur] = s->s_name[0];
                else if (s->s_name[0] >= 'a' && s->s_name[0] <= 'z')
                    buf[cur] = 'A' + (s->s_name[0] - 'a');
                else
                    buf[cur] = 0;
            } else
                buf[cur] = 0;
        } else if (hatom_gettype(&elem->l_hatom) == H_LONG) {
            buf[cur] = long_to_char(hatom_getlong(&elem->l_hatom));
        } else {
            buf[cur] = 0;
        }
    }
    
    buf[buf_size] = 0;
    
    t_symbol *out = gensym(buf);
    bach_freeptr(buf);
    
    return out;
}


t_llll *long_to_digits(long num, long base)
{
    t_llll *digits = llll_get();
    while (num != 0) {
        llll_appendlong(digits, num % base);
        num = num/base;
    }
    llll_rev(digits, 1, 1);
    return digits;
}


t_llll *float_to_digits(double num, long base, long maxdecimals)
{
/*    // precook num, to handle finite precision
    double temp = num;
    double epsilon = 1.;
    for (long i = 0; i < maxdecimals; i++) { epsilon /= 10; temp *= 10; }
    temp = fmod(temp, 1.);
    for (long i = 0; i < maxdecimals; i++) temp /= 10;
    double candidate_num = num-temp;
    if (fabs(candidate_num + epsilon - num) < fabs(candidate_num - num))
        num = candidate_num + epsilon;
    */
    
    // actually calculate
    t_llll *digits = llll_get();
    double mult = 1.0/base;
    double num_ok = num;
    
    // BEWARE: due to floating point issues, here mult could actually be 1/base + epsilon.
    // we don't want this, we want it to be 1/base - epsilon, if anything.
    if (perfect_log2(base) == -1)
        mult -= DBL_EPSILON;
    
    for (long i = 0; i < maxdecimals; i++) {
        if (num_ok == 0.)
            break;
        long this_coeff = (long)(num_ok / mult);
        llll_appendlong(digits, this_coeff);
        num_ok -= this_coeff * mult;
        mult /= base;
    }
    return digits;
}


long digits_to_long(t_llll *digits, long base)
{
    long multiplier = 1;
    long out = 0;
    for (t_llllelem *elem = digits->l_tail; elem; elem = elem->l_prev) {
        if (hatom_gettype(&elem->l_hatom) == H_LONG)
            out += multiplier * hatom_getlong(&elem->l_hatom);
        else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *sym = hatom_getsym(&elem->l_hatom);
            if (sym && sym->s_name && sym->s_name[0])
                out += multiplier * char_to_long(sym->s_name[0]);
        }
        multiplier *= base;
    }
    return out;
}

double digits_to_fractional_part(t_llll *digits, long base)
{
    double multiplier = 1./base;
    double out = 0;
    for (t_llllelem *elem = digits->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LONG)
            out += multiplier * hatom_getlong(&elem->l_hatom);
        else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *sym = hatom_getsym(&elem->l_hatom);
            if (sym && sym->s_name && sym->s_name[0])
                out += multiplier * char_to_long(sym->s_name[0]);
        }
        multiplier /= base;
    }
    return out;
}



long convertbase_long(long num, long startbase, long endbase, t_llll **out_digits, char outsym_mode, t_symbol **outsym)
{
    if (startbase != 10) {
        t_llll *temp_digits = long_to_digits(num, 10);
        num = digits_to_long(temp_digits, startbase);
        llll_free(temp_digits);
    }
    
    t_llll *digits = long_to_digits(num, endbase);

    if (endbase != 10)
        num = digits_to_long(digits, 10);
    
    if (outsym && (outsym_mode == BACH_CONVERTBASE_OUTSYM_ALWAYS ||
                   (outsym_mode == BACH_CONVERTBASE_OUTSYM_IFNEEDED && does_any_digit_need_sym(digits))))
        *outsym = digits_to_symbol(digits);
    
    if (out_digits)
        *out_digits = digits;
    else
        llll_free(digits);
    
    return num;
}


// returns integer part, and fractional part in <fractional_part>
long convertbase_double(double num, long startbase, long endbase, t_llll **out_digits, char outsym_mode, t_symbol **outsym, double *fractional_part, long maxdecimals)
{
    
    double num_fractional = fmod(num, 1.);
    long num_integer = (long)(num);
    
    
    t_llll *int_digits = NULL, *fractional_digits = NULL;
    t_symbol *int_sym = NULL, *fractional_sym = NULL;
    long result_int = convertbase_long(num_integer, startbase, endbase, &int_digits, outsym ? outsym_mode : BACH_CONVERTBASE_OUTSYM_NEVER, &int_sym);
    
    // and now, taking care of the fractional part
    if (startbase != 10) {
        t_llll *temp_digits = float_to_digits(num_fractional, 10, maxdecimals);
        num_fractional = digits_to_fractional_part(temp_digits, startbase);
        llll_free(temp_digits);
    }
    
    fractional_digits = float_to_digits(num_fractional, endbase, maxdecimals);
    
    if (endbase != 10)
        num_fractional = digits_to_fractional_part(fractional_digits, 10);
    
    if (outsym && (outsym_mode == BACH_CONVERTBASE_OUTSYM_ALWAYS ||
                   (outsym_mode == BACH_CONVERTBASE_OUTSYM_IFNEEDED && does_any_digit_need_sym(fractional_digits))))
        fractional_sym = digits_to_symbol(fractional_digits);
    
    if (fractional_part)
        *fractional_part = num_fractional;
    
    if (outsym) {
        if (int_sym && !fractional_sym) {
            fractional_sym = digits_to_symbol(fractional_digits);
        } else if (fractional_sym && !int_sym) {
            int_sym = long_to_symbol(result_int);
        }
        
        if (fractional_sym && int_sym) {
            long len1 = strlen(int_sym->s_name);
            long len2 = strlen(fractional_sym->s_name);
            char *buf = (char *)bach_newptr((len1 + len2 + 2) * sizeof(char));
            sysmem_copyptr(int_sym->s_name, buf, len1 * sizeof(char));
            buf[len1] = '.';
            sysmem_copyptr(fractional_sym->s_name, buf + len1 + 1, len2 * sizeof(char));
            buf[len1+len2+1] = 0;
            *outsym = gensym(buf);
            bach_freeptr(buf);
        }
    }
    
    
    if (out_digits) {
        *out_digits = llll_get();
        llll_appendllll(*out_digits, int_digits);
        llll_appendllll(*out_digits, fractional_digits);
    } else {
        llll_free(int_digits);
        llll_free(fractional_digits);
    }
    
    return result_int;
}




long convertbase_digits(t_llll *digits, long startbase, long endbase, t_llll **out_digits, char outsym_mode, t_symbol **outsym, char *is_float, double *float_part, double maxdecimals)
{
    if (digits->l_depth == 2) {
        if (digits->l_head && digits->l_head->l_next && hatom_gettype(&digits->l_head->l_hatom) == H_LLLL && hatom_gettype(&digits->l_head->l_next->l_hatom) == H_LLLL) {
            long integer_part = digits_to_long(hatom_getllll(&digits->l_head->l_hatom), startbase);
            double fractional_part = digits_to_fractional_part(hatom_getllll(&digits->l_head->l_next->l_hatom), startbase);
            if (is_float) *is_float = 1;
            return convertbase_double(integer_part + fractional_part, 10, endbase, out_digits, outsym_mode, outsym, float_part, maxdecimals);
        } else {
            return convertbase_double(0., 10, endbase, out_digits, outsym_mode, outsym, float_part, maxdecimals);
        }
    } else {
        long num = digits_to_long(digits, startbase);
        if (is_float) *is_float = 0;
        return convertbase_long(num, 10, endbase, out_digits, outsym_mode, outsym);
    }
}

t_llll *symbol_to_digits(t_symbol *num_as_sym, char *is_float)
{
    t_llll *digits = llll_get();

    if (!num_as_sym || !num_as_sym->s_name[0]) {
        if (is_float)
            *is_float = 0;
        return digits;
    }

    long c;
    char *buf = num_as_sym->s_name;
    long len = strlen(num_as_sym->s_name);
    if (strstr(num_as_sym->s_name, ".")) {
        t_llll *integer = llll_get();
        t_llll *fractional = llll_get();
        c = 0;
        while (c < len && buf[c] != '.') {
            llll_appendlong(integer, char_to_long(buf[c]));
            c++;
        }
        c++;
        while (c < len) {
            llll_appendlong(fractional, char_to_long(buf[c]));
            c++;
        }
        llll_appendllll(digits, integer);
        llll_appendllll(digits, fractional);
        
        if (is_float)
            *is_float = 1;
    } else {
        for (c = 0; c < len; c++)
            llll_appendlong(digits, char_to_long(buf[c]));
        if (is_float)
            *is_float = 0;
    }
    
    return digits;
}

long convertbase_sym(t_symbol *num_as_sym, long startbase, long endbase, t_llll **out_digits, char outsym_mode, t_symbol **outsym, char *is_float, double *float_part, long maxdecimals)
{
    if (!num_as_sym || !num_as_sym->s_name[0])
        return 0;

    t_llll *digits = symbol_to_digits(num_as_sym, is_float);

    long res = convertbase_digits(digits, startbase, endbase, out_digits, outsym_mode, outsym, is_float, float_part, maxdecimals);

    llll_free(digits);
    
    return res;
}




void convertbase_anything(t_convertbase *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
    char float_mode = 0;
	long inlet = proxy_getinlet((t_object *) x);
    long output_long = 0;
    double output_float_part = 0.;
    t_symbol *output_sym = NULL;
    t_llll *output_digits = NULL;
    ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
    
    if (ll && ll->l_head) {
        if (inlet == 0) {
            long type = hatom_gettype(&ll->l_head->l_hatom);
            switch (type) {

                case H_LONG:
                    float_mode = 0;
                    output_long = convertbase_long(hatom_getlong(&ll->l_head->l_hatom), x->n_startbase, x->n_endbase, &output_digits, x->n_symout_left, &output_sym);
                    break;
                    
                case H_SYM:
                    output_long = convertbase_sym(hatom_getsym(&ll->l_head->l_hatom), x->n_startbase, x->n_endbase, &output_digits, x->n_symout_left, &output_sym, &float_mode, &output_float_part, x->n_maxdecimals);
                    break;
                    
                case H_DOUBLE:
                case H_RAT:
                    float_mode = 1;
                    output_long = convertbase_double(hatom_getdouble(&ll->l_head->l_hatom), x->n_startbase, x->n_endbase, &output_digits, x->n_symout_left, &output_sym, &output_float_part, x->n_maxdecimals);
                    break;
                    

                default:
                    break;
            }
        } else if (inlet == 1) {
            // convert from digits
            output_long = convertbase_digits(ll, x->n_startbase, x->n_endbase, &output_digits, x->n_symout_left, &output_sym, &float_mode, &output_float_part, x->n_maxdecimals);
        }
    }
    

    if (!output_digits)
        output_digits = llll_get();
    
    // check output digits for conversions into symbols
    for (t_llllelem *elem = output_digits->l_head; elem; elem = elem->l_next) {
        if (x->n_symout_right == BACH_CONVERTBASE_OUTSYM_ALWAYS || (x->n_symout_right == BACH_CONVERTBASE_OUTSYM_IFNEEDED && hatom_getlong(&elem->l_hatom) >= 10)) {
            char buf[2];
            buf[0] = long_to_char(hatom_getlong(&elem->l_hatom));
            buf[1] = 0;
            hatom_setsym(&elem->l_hatom, gensym(buf));
        }
    }

    // actually output stuff
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 1, output_digits);
    if (output_sym)
        llllobj_outlet_anything((t_object *)x, LLLL_OBJ_VANILLA, 0, output_sym, 0, NULL);
    else if (float_mode) {
        llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 0, output_long + output_float_part);
    } else {
        llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 0, output_long);
    }
    
    llll_free(output_digits);
    llll_free(ll);
}

void convertbase_assist(t_convertbase *x, void *b, long m, long a, char *s)
{	
    if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "number/symbol: Original Number"); // @in 0 @type number/symbol @digest The number in the original base
        else sprintf(s, "llll: Original Digits"); // @in 1 @type llll @digest The digits in the original base
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a == 0) sprintf(s, "number/symbol: Converted Number"); // @out 0 @type number/symbol @digest The number in the target base
		else sprintf(s, "llll (%s): Converted Digits", type); // @out 1 @type llll @digest The digits in the target base
	}
}

void convertbase_inletinfo(t_convertbase *x, void *b, long a, char *t)
{
    // both inlets are hot
    return;
//    *t = 1;
}

void convertbase_free(t_convertbase *x)
{
    long i;
    for (i = 1; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_convertbase *convertbase_new(t_symbol *s, short ac, t_atom *av)
{
	t_convertbase *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	
	if ((x = (t_convertbase *) object_alloc_debug(convertbase_class))) {
        long i;
        x->n_startbase = x->n_endbase = 10;
        x->n_maxdecimals = BACH_DEFAULT_MAXDECIMALS;
        x->n_symout_left = BACH_CONVERTBASE_OUTSYM_IFNEEDED;
        x->n_symout_right = BACH_CONVERTBASE_OUTSYM_NEVER;
        
		true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 3, "4a", NULL);
        if (true_ac) {

            // @arg 0 @name startbase @optional 1 @type int @digest The original base
            // @description The first integer argument sets the base of the incoming numbers or digits.
            if (atom_gettype(av) == A_LONG)
                x->n_startbase = atom_getlong(av);

            if (true_ac > 1 && atom_gettype(av+1) == A_LONG) {
                // @arg 1 @name endbase @optional 1 @type int @digest The target base
                // @description The second integer argument sets the desired output base.
                x->n_endbase = atom_getlong(av + 1);
            }
        }
        for (i = 1; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else
		error(BACH_CANT_INSTANTIATE);		
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
