/**
 @file
 resample.c
 
 @name 
 bach.resample
 
 @realname 
 bach.resample
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Resample lllls
 
 @description
 Upsample or downsample any llll
 
 @discussion
 
 @category
 bach, bach objects, bach math

 @keywords
 resample, sample, upsample, downsample, upsampling, downsampling, reduce, increase, interpolation, interpolate
 
 @seealso
 bach.reducefunction, bach.fft
 
 @owner
 Daniele Ghisi
 */


#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "llllobj.h"
#include "ext_strings.h"
#include "llll_commons_ext.h"
#include "collector.h"
#include "llll_math.h"

enum {
    BACH_RESAMPLE_NEAREST = 0,
    BACH_RESAMPLE_POINT = 1,
    BACH_RESAMPLE_TRIANGLE = 2,
    BACH_RESAMPLE_SINC = 3,
    BACH_RESAMPLE_BLACKMAN_SINC = 4,
    BACH_RESAMPLE_LANCZOS_SINC = 5,
    BACH_RESAMPLE_GAUSSIAN = 6,
    BACH_RESAMPLE_MITCHELL_NETRAVALI = 7,
    BACH_RESAMPLE_SPLINE16 = 8,
    BACH_RESAMPLE_SPLINE36 = 9,
    BACH_RESAMPLE_SPLINE64 = 10,
};

enum {
    BACH_RESAMPLE_MODE_FACTOR = 0,
    BACH_RESAMPLE_MODE_TARGETLENGTH = 1
};


typedef struct _resample_iteration_data {
    t_lexpr		*e_lexpr;
    t_collector	*e_collector;
    long		e_count; // how many variables
    long		e_evaluate;
    t_hatom		e_data[LEXPR_MAX_VARS]; // data for one iteration of the incoming lllls
} t_resample_iteration_data;



typedef struct _resample
{
	struct llllobj_object 	n_ob;

    char        n_mode;

    t_atom      n_factor;
    long        n_length;

	long        n_function;
    double      n_support;
    char		n_align;
    
    t_lexpr     *n_lexpr;
    
    t_systhread_mutex n_mutex;

} t_resample;


void resample_assist(t_resample *x, void *b, long m, long a, char *s);
void resample_inletinfo(t_resample *x, void *b, long a, char *t);

t_resample *resample_new(t_symbol *s, short ac, t_atom *av);
void resample_free(t_resample *x);

void resample_bang(t_resample *x);
void resample_int(t_resample *x, long num);
void resample_float(t_resample *x, double num);
void resample_anything(t_resample *x, t_symbol *msg, long ac, t_atom *av);
t_max_err resample_notify(t_resample *x, t_symbol *s, t_symbol *msg, void *sender, void *data);


t_class *resample_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}	
	
	c = class_new("bach.resample", (method)resample_new, (method)resample_free, (short)sizeof(t_resample), 0L, A_GIMME, 0);
	
    
    // @method llll @digest Resample incoming llll
    // @description Any incoming <m>llll</m> resampled by the specified <m>factor</m>, according to the values of the other attributes.
    class_addmethod(c, (method)resample_anything,					"anything",				A_GIMME,	0);
	
	class_addmethod(c, (method)resample_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)resample_float,					"float",				A_FLOAT,	0);
	class_addmethod(c, (method)resample_anything,					"list",					A_GIMME,	0);

    // @method bang @digest Resample last received llll
    // @description Performs resampling on last received llll.
    class_addmethod(c, (method)resample_bang,						"bang",		0);
	
	class_addmethod(c, (method)resample_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)resample_inletinfo,	"inletinfo",	A_CANT,		0);
    class_addmethod(c, (method)resample_notify,		"bachnotify",		A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


    CLASS_ATTR_CHAR(c, "mode",	0,	t_resample, n_mode);
    CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Output Mode");
    CLASS_ATTR_ENUMINDEX(c, "mode", 0, "Multiplier Target Length");
    CLASS_ATTR_BASIC(c, "mode", 0);
    // @description Sets the way output length should be specified: either via a scaling multiplier (see <m>factor</m> attribute),
    // or via an absolute target length (see <m>length</m> attribute).
    // For instance, to downsample an llll by a factor of 3, use "Multiplier" <m>mode</m>,
    // with <b>1/3</b> as <m>factor</m>; to upsample an llll so that its final length be 127, use "Target Length"
    // <m>mode</m> and <b>127</b> as <m>length</m>.
    
    CLASS_ATTR_ATOM(c, "factor",	0,	t_resample, n_factor);
    CLASS_ATTR_STYLE_LABEL(c,"factor",0,"text","Resampling Factor");
    CLASS_ATTR_BASIC(c, "factor", 0);
    // @description In "Multiplier" <m>mode</m>, sets the resampling factor.

    CLASS_ATTR_LONG(c, "length",	0,	t_resample, n_length);
    CLASS_ATTR_STYLE_LABEL(c,"length",0,"text","Output Length");
    CLASS_ATTR_BASIC(c, "length", 0);
    // @description In "Target Length" <m>mode</m>, sets the total length of the output sampled llll.

    CLASS_ATTR_DOUBLE(c, "support",	0,	t_resample, n_support);
    CLASS_ATTR_STYLE_LABEL(c,"support",0,"text","Filter Support");
    // @description Sets the support for the resampling filter.

    CLASS_ATTR_LONG(c, "function",	0,	t_resample, n_function);
    CLASS_ATTR_STYLE_LABEL(c,"function",0,"enumindex","Filter Function");
    CLASS_ATTR_ENUMINDEX(c, "function", 0, "Nearest Neighbour Point Triangle Sinc BlackmanSinc LanczosSinc Gaussian Mitchell-Netravali Spline16 Spline36 Spline64");
    // @description Sets the function used for the resampling filter.

    CLASS_ATTR_CHAR(c, "align", 0, t_resample, n_align);
    CLASS_ATTR_STYLE_LABEL(c,"align",0,"enumindex","Alignment");
    CLASS_ATTR_ENUMINDEX(c, "align", 0, "Left Center Right");
    CLASS_ATTR_BASIC(c,"align",0);
    // @description Sets the alignment of the original llll within the resampled llll. 0 is left, 1 (default) is middle, 2 is right.
    
	class_register(CLASS_BOX, c);
	resample_class = c;
	
	dev_post("bach.resample compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


t_max_err resample_notify(t_resample *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    if (msg == _sym_attr_modified) {
        t_symbol *attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
        if (attrname == _sym_mode) {
            object_attr_setdisabled((t_object *)x, gensym("factor"), x->n_mode != BACH_RESAMPLE_MODE_FACTOR);
            object_attr_setdisabled((t_object *)x, gensym("length"), x->n_mode != BACH_RESAMPLE_MODE_TARGETLENGTH);
        }
    }
    return MAX_ERR_NONE;
}

void resample_bang(t_resample *x)
{
    resample_anything(x, _sym_bang, 0, NULL);
}

void resample_int(t_resample *x, long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	resample_anything(x, _llllobj_sym_list, 1, argv);
}

void resample_float(t_resample *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	resample_anything(x, _llllobj_sym_list, 1, argv);
}




//// ACTUAL FUNCTIONS

// subrange_start and subrange_width could be doubles, we don't expose them though
t_llll *get_multipliers_for_resampling(t_object *x, int original_width, double support, long subrange_start, long subrange_width, int target_width, char align, double(*f)(double), char fix_filterstep_to_one, char use_rationals, t_rational(*f_rat)(t_rational))
/**
 * This function returns a resampling "program" which is interpreted by the
 * FilteredResize filters.  It handles edge conditions so FilteredResize
 * doesn't have to.
 **/
{
    double scale = double(target_width) / subrange_width;
    double filter_step = fix_filterstep_to_one ? 1.0 : MIN(scale, 1.0);
    t_rational filter_step_rat;
    
    if (use_rationals)
        filter_step_rat = (fix_filterstep_to_one || scale >= 1.0) ? long2rat(1) : genrat(target_width, subrange_width);
    
    double filter_support = support; // was: support / filter_step;
    int fir_filter_size = int(ceil(filter_support*2));
    double total;
    t_rational total_rat;

    t_llll *result = llll_get();

    double pos_step = (double)subrange_width / target_width;
    // the following translates such that the image center remains fixed
    double pos;
    t_rational pos_rat, pos_step_rat;
    
    if (use_rationals)
        pos_step_rat = genrat(subrange_width, target_width);
    
    if (original_width <= filter_support / MIN(scale, 1.0)) {
        object_warn((t_object *)x, "Source llll too small for this resampling parameters."); // Width=%d, Support=%d", original_width, (int)filter_support);
    }
    
    if (fir_filter_size == 1 || align == 0) // PointResize or align left
        pos = (double)subrange_start;
    else if (align == 2) // align right
        pos = (double)subrange_start + (((double)subrange_width - target_width) / (target_width));
    else
        pos = (double)subrange_start + (((double)subrange_width - target_width) / (target_width*2));
    
    if (use_rationals) {
        if (fir_filter_size == 1 || align == 0) // PointResize or align left
            pos_rat = long2rat(subrange_start);
        else if (align == 2) // align right
            pos_rat = rat_long_sum(genrat(subrange_width - target_width, target_width), subrange_start);
        else
            pos_rat = rat_long_sum(genrat(subrange_width - target_width, 2 * target_width), subrange_start);
    }
    
    for (int i=0; i<target_width; ++i) {
        int end_pos = int(pos + filter_support);
        
        if (end_pos > original_width-1)
            end_pos = original_width-1;
        
        int start_pos = end_pos - fir_filter_size + 1;
        
        if (start_pos < 0)
            start_pos = 0;
        
//        llll_appenddouble(result, start_pos);
        
        // the following code ensures that the coefficients add to exactly FPScale
        if (use_rationals)
            total_rat = long2rat(0);
        else
            total = 0.0;
        
        // Ensure that we have a valid position
        double ok_pos = MAX(0.0, MIN(original_width-1,pos));
        t_rational ok_pos_rat = pos_rat;
        if (use_rationals) {
            if (rat_long_cmp(pos_rat, 0) < 0)
                ok_pos_rat = long2rat(0);
            else if (rat_long_cmp(pos_rat, original_width-1) > 0)
                ok_pos_rat = long2rat(original_width-1);
        }
        
        for (int j=0; j<fir_filter_size; ++j) {  // Accumulate all coefficients
            if (use_rationals)
                total_rat = rat_rat_sum(total_rat, f_rat(rat_rat_prod(long_rat_diff(start_pos+j, ok_pos_rat), filter_step_rat)));
            else
                total += f((start_pos+j - ok_pos) * filter_step);
        }
        
        if ((use_rationals && total_rat.r_num == 0) || (!use_rationals && total == 0.0)) {
            // Shouldn't happend for valid positions.
            object_warn((t_object *)x, "Got zero coefficient, should never happen.");
            total = 1.0;
        }
        
        long l = start_pos;
        t_llll *subll = llll_get();
        for (int k=0; k<fir_filter_size; ++k, l++) {
            t_llll *thisfactor_ll = llll_get();
            llll_appendlong(thisfactor_ll, l + 1); //1-based outside
            if (use_rationals)
                llll_appendrat(thisfactor_ll, rat_rat_div(f_rat(rat_rat_prod(long_rat_diff(start_pos+k, ok_pos_rat), filter_step_rat)), total_rat));
            else
                llll_appenddouble(thisfactor_ll, f((start_pos+k - ok_pos) * filter_step) / total);
            llll_appendllll(subll, thisfactor_ll);
        }
        llll_appendllll(result, subll);
        
        pos += pos_step;
        if (use_rationals)
            pos_rat = rat_rat_sum(pos_rat, pos_step_rat);
    }
    
    return result;
}




// destructive
void llll_lowpass_sinc(t_llll *ll, double freq)
{
    long orig_size = ll->l_size;
    t_llll *impulse = llll_get(); // TO DO
    long impulse_size = 0;
    // adding sinc values
    
    
    // convolve
    t_llll *convolved = llll_get();
    t_llllelem *elem, *sub_elem, *imp_elem;
    long i;
    for (i = 0; i < impulse_size - 1; i++)
        llll_prependdouble(ll, 0);
    for (i = 0; i < impulse_size - 1; i++)
        llll_appenddouble(ll, 0);
    for (elem = ll->l_head, i = 0; elem && i < ll->l_size - impulse_size + 1; i++) {
        double this_sum = 0;
        for (sub_elem = elem, imp_elem = impulse->l_head; sub_elem && imp_elem; imp_elem = imp_elem->l_next, sub_elem = sub_elem->l_next)
            this_sum += hatom_getdouble(&sub_elem->l_hatom) * hatom_getdouble(&imp_elem->l_hatom);
        llll_appenddouble(convolved, this_sum);
    }
    
    // only taking middle part
    llll_pad(convolved, orig_size, 1, BACH_PAD_REPEAT, 0, NULL, true, 0);
    
    llll_free(ll);
    ll = convolved;
}

// destructive
void llll_downsample(t_llll *ll, long factor)
{
    // downsampling sequence via decimation
    long i;
    t_llllelem *elem, *nextelem;
    for (elem = ll->l_head, i = 0; elem; elem = nextelem, i++) {
        nextelem = elem->l_next;
        if (i % factor != 0)
            llll_destroyelem(elem);
    }
    
    // apply sinc lowpass filter
    llll_lowpass_sinc(ll, 10); // DUMMY, TO DO
}



// destructive
void llll_upsample(t_llll *ll, long factor)
{
    // upsampling sequence with zero padding
    long i;
    t_llllelem *elem, *nextelem;
    for (elem = ll->l_head, i = 0; elem; elem = nextelem, i++) {
        nextelem = elem->l_next;
        for (long j = 1; j < factor; j++)
            llll_insertdouble_after(0, elem);
    }
    
    // apply sinc lowpass filter
    llll_lowpass_sinc(ll, 10); // DUMMY, TO DO
}





/***************************
 ***** Point filter *****
 **************************/

double point_f(double x) {
    return (x>= -0.5 && x < 0.5) ? 1.0 : 0.0;
}

t_rational point_f_rat(t_rational x) {
    if (rat_rat_cmp(x, genrat_noreduce(-1, 2)) >= 0 && rat_rat_cmp(x, genrat_noreduce(1, 2)) < 0)
        return long2rat(1);
    return long2rat(0);
}


/***************************
 ***** Triangle filter *****
 **************************/

double triangle_f(double x) {
    x = fabs(x);
    return (x<1.0) ? 1.0-x : 0.0;
}

t_rational triangle_f_rat(t_rational x) {
    x = rat_abs(x);
    if (rat_long_cmp(x, 1) < 0)
        return long_rat_diff(1, x);
    return long2rat(0);
}



/***********************
 *** Sinc filter ***
 ***********************/
double sinc_f(double value) {
    value = fabs(value);
    
    if (value > 0.000001) {
        value *= M_PI;
        return sin(value)/value;
    } else {
        return 1.0;
    }
}


/***********************
 *** Gaussian filter ***
 ***********************/

/* Solve taps from p*value*value < 9 as pow(2.0, -9.0) == 1.0/512.0 i.e 0.5 bit
 value*value < 9/p       p = param*0.1;
 value*value < 90/param
 value*value < 90/{0.1, 22.5, 30.0, 100.0}
 value*value < {900, 4.0, 3.0, 0.9}
 value       < {30, 2.0, 1.73, 0.949}         */
/*
GaussianFilter::GaussianFilter(double p = 30.0) {
    param = min(100.0,max(0.1,p));
}
*/
double gaussian_f(double value) {
    const double input_param = 30; // TO BE set as parameter
    double param = MIN(100.0,MAX(0.1,input_param));
    double p = param*0.1;
    return pow(2.0, - p*value*value);
}






/*********************************
 *** Mitchell-Netravali filter ***
 *********************************/

void mitchell_netravali_f_get_params(double b, double c,
                                    double *p0, double *p2, double *p3, double *q0, double *q1, double *q2, double *q3) {
    *p0 = (   6. -  2.*b            ) / 6.;
    *p2 = ( -18. + 12.*b +  6.*c    ) / 6.;
    *p3 = (  12. -  9.*b -  6.*c    ) / 6.;
    *q0 = (            8.*b + 24.*c ) / 6.;
    *q1 = (         - 12.*b - 48.*c ) / 6.;
    *q2 = (            6.*b + 30.*c ) / 6.;
    *q3 = (      -     b -  6.*c    ) / 6.;
}

double mitchell_netravali_f (double x) {
    double p0, p2, p3, q0, q1, q2, q3;
    mitchell_netravali_f_get_params(1./3., 1./3., &p0, &p2, &p3, &q0, &q1, &q2, &q3);  // to be set as parameter, b and c
    x = fabs(x);
    return (x<1) ? (p0+x*x*(p2+x*p3)) : (x<2) ? (q0+x*(q1+x*(q2+x*q3))) : 0.0;
}


/***********************
 *** Lanczos3 filter ***
 ***********************/

double lanczos_sinc(double value) {
    if (value > 0.000001) {
        value *= M_PI;
        return sin(value) / value;
    } else {
        return 1.0;
    }
}

double lanczos_f(double value) {
    const int t = 3; // to be set as parameter? between 1 and 1000
    double taps = (double)(MAX(1, MIN(100,t)));
    value = fabs(value);
    
    if (value < taps) {
        return (lanczos_sinc(value) * lanczos_sinc(value / taps));
    } else {
        return 0.0;
    }
}


/***********************
 *** Blackman filter ***
 ***********************/
double blackman_f(double value) {
    const int t = 4; // to be set as parameter? between 1 and 1000
    
    double taps = (double)(MAX(1,MIN(100,t)));
    double rtaps = 1.0/taps;

    
    value = fabs(value);
    
    if (value < taps) {
        if (value > 0.000001) {
            value *= M_PI;
            return (sin(value) / value) * (0.42 + 0.5*cos(value*rtaps) + 0.08*cos(2*value*rtaps));
        } else {
            return 1.0;
        }
    } else {
        return 0.0;
    }
}


/***********************
 *** Spline16 filter ***
 ***********************/

double spline16_f(double value) {
    value = fabs(value);
    
    if (value < 1.0) {
        return ( ( value - 9.0/5.0 ) * value - 1.0/5.0 ) * value + 1.0;
    } else if (value < 2.0) {
        return ( ( -1.0/3.0 * (value-1.0) + 4.0/5.0 ) * (value-1.0) - 7.0/15.0 ) * (value-1.0);
    }
    return 0.0;
}

/***********************
 *** Spline36 filter ***
 ***********************/

double spline36_f(double value) {
    value = fabs(value);
    
    if        (value < 1.0) {
        return ( ( 13.0/11.0  * (value    ) - 453.0/ 209.0 ) * (value    ) -   3.0/ 209.0 ) *(value    ) + 1.0;
    } else if (value < 2.0) {
        return ( ( -6.0/11.0  * (value-1.0) + 270.0/ 209.0 ) * (value-1.0) - 156.0/ 209.0 ) *(value-1.0);
    } else if (value < 3.0) {
        return  ( ( 1.0/11.0  * (value-2.0) -  45.0/ 209.0 ) * (value-2.0) +  26.0/ 209.0 ) *(value-2.0);
    }
    return 0.0;
}

/***********************
 *** Spline64 filter ***
 ***********************/

double spline64_f(double value) {
    value = fabs(value);
    
    if        (value < 1.0) {
        return (( 49.0/41.0 * (value    ) - 6387.0/2911.0) * (value    ) -    3.0/2911.0) * (value    ) + 1.0;
    } else if (value < 2.0) {
        return ((-24.0/41.0 * (value-1.0) + 4032.0/2911.0) * (value-1.0) - 2328.0/2911.0) * (value-1.0);
    } else if (value < 3.0) {
        return ((  6.0/41.0 * (value-2.0) - 1008.0/2911.0) * (value-2.0) +  582.0/2911.0) * (value-2.0);
    } else if (value < 4.0) {
        return ((- 1.0/41.0 * (value-3.0) +  168.0/2911.0) * (value-3.0) -   97.0/2911.0) * (value-3.0);
    }
    return 0.0;
}


double (*resample_get_function(t_resample *x))(double)
{
    switch (x->n_function) {
        case BACH_RESAMPLE_TRIANGLE:
            return triangle_f;
        case BACH_RESAMPLE_SINC:
            return sinc_f;
        case BACH_RESAMPLE_GAUSSIAN:
            return gaussian_f;
        case BACH_RESAMPLE_BLACKMAN_SINC:
            return blackman_f;
        case BACH_RESAMPLE_LANCZOS_SINC:
            return lanczos_f;
        case BACH_RESAMPLE_MITCHELL_NETRAVALI:
            return mitchell_netravali_f;
        case BACH_RESAMPLE_SPLINE16:
            return spline16_f;
        case BACH_RESAMPLE_SPLINE36:
            return spline36_f;
        case BACH_RESAMPLE_SPLINE64:
            return spline64_f;
        default:
            return point_f;
    }
}


t_rational (*resample_get_rat_function(t_resample *x))(t_rational)
{
    switch (x->n_function) {
        case BACH_RESAMPLE_TRIANGLE:
            return triangle_f_rat;
        default:
            return point_f_rat;
    }
}



long multiply_fn(void *data, t_hatom *a, const t_llll *address){
    t_hatom *multiplier = (t_hatom *) data;
    t_hatom temp;
    hatom_op_times(multiplier, a, &temp);
    *a = temp;
    return 0;
}

long sum_fn(void *data, t_hatom *a, const t_llll *address){
    t_hatom *add = (t_hatom *) data;
    t_hatom temp;
    hatom_op_plus(add, a, &temp);
    *a = temp;
    return 0;
}

long bach_expr_get_data(t_resample_iteration_data *x, long list, t_llll *ll, char isaddress) // never called for address
{
    if (ll->l_size)
        x->e_data[list] = ll->l_head->l_hatom; // that is, for each list get the hatom coming from iter and remember it
    else
        x->e_evaluate = 0; // or, if no hatom is coming, tell the guy not to evaluate
    return 0;
}

long bach_expr_cmd(t_resample_iteration_data *x, long cmd)
{
    t_hatom *result_hatom, *this_lexpr_data, *max_lexpr_data;
    t_llll *result_llll;
    
    if (x->e_evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
        result_hatom = lexpr_eval(x->e_lexpr, x->e_data);
        if (result_hatom) {
            long type = hatom_gettype(result_hatom);
            if (type == H_SYM || hatom_type_is_number(type)) {
                result_llll = llll_get();
                llll_appendhatom(result_llll, result_hatom, 0, WHITENULL_llll);
                collector_get(x->e_collector, result_llll, 0, 0);
            }
            bach_freeptr(result_hatom);
        } else { // if there was an empty llll in the incoming data
            collector_get(x->e_collector, llll_get(), 0, 0);
        }
        
    }
    for (this_lexpr_data = x->e_data, max_lexpr_data = this_lexpr_data + x->e_count; this_lexpr_data < max_lexpr_data; this_lexpr_data++)
        this_lexpr_data->h_type = A_NOTHING;
    if (cmd)
        collector_change_level(x->e_collector, cmd);
    x->e_evaluate = 1;
    return 0;
}



t_llll *llll_plus(t_llll *ll1, t_llll *ll2, t_lexpr *lexpr)
{
    t_resample_iteration_data data, *data_ptr = &data;
    data.e_count = 2;
    data.e_collector = collector_new(1, 0);
    data.e_lexpr = lexpr;
    data.e_evaluate = 0;

    t_llll *lists[2];
    lists[0] = ll1;
    lists[1] = ll2;
    llll_iter(2, lists, -1, 1, 1, 0, 2, 0, NULL,
              (iter_datafn) bach_expr_get_data, data_ptr, NULL, NULL, (iter_cmdfn) bach_expr_cmd, data_ptr, NULL, NULL, NULL, NULL);
    bach_expr_cmd(data_ptr, 0);
    t_llll *result = collector_output(data.e_collector, 0, 0);
    collector_clear(data.e_collector);
    collector_free(data.e_collector);
    return result;
}


t_llll *multipliers_to_res(t_resample *x, t_llll *multipliers, t_llll *elems)
{
    t_llllelem *sample_el, *mult_el;
    t_llllelem *elems_cur = elems->l_head, *temp_cur = NULL;
    long elems_cur_idx = 0;
    char firsttime;
    t_hatom temp_hatom;
    t_llll *out_ll = llll_get();
    
    for (sample_el = multipliers->l_head; sample_el; sample_el = sample_el->l_next) {
        t_llll *sample_mult_ll = hatom_getllll(&sample_el->l_hatom);
        t_hatom this_sample;
        char this_sample_set = false;
        hatom_setlong(&this_sample, 0);
        
        firsttime = true;
        
        // TO DO HANDLE LLLLS!!!!

        // updating temp cur
        for (mult_el = sample_mult_ll ? sample_mult_ll->l_head : NULL; mult_el; mult_el = mult_el->l_next) {
            t_llll *this_mult_ll = hatom_getllll(&mult_el->l_hatom);
            long this_cur = hatom_getlong(&this_mult_ll->l_head->l_hatom) - 1; // to 0-based
            t_hatom *this_mult = &this_mult_ll->l_tail->l_hatom;
            t_hatom this_component;
            
            if (firsttime) {
                // updating elems_cur?
                while (elems_cur && this_cur > elems_cur_idx) {
                    elems_cur = elems_cur->l_next;
                    elems_cur_idx++;
                }
                temp_cur = elems_cur;
                firsttime = false;
            } else if (temp_cur)
                temp_cur = temp_cur->l_next;
            
            if (temp_cur) {
                if (hatom_gettype(&temp_cur->l_hatom) == H_LLLL) {
                    t_llll *this_component_ll = llll_clone(hatom_getllll(&temp_cur->l_hatom));
                    llll_funall(this_component_ll, multiply_fn, this_mult, 0, -1, FUNALL_ONLY_PROCESS_ATOMS);
                    hatom_setllll(&this_component, this_component_ll);
                } else
                    hatom_op_times(this_mult, &temp_cur->l_hatom, &this_component);
                
                if (hatom_gettype(&this_sample) == H_LLLL && hatom_gettype(&this_component) == H_LLLL) {
                    t_llll *plus = llll_plus(hatom_getllll(&this_sample), hatom_getllll(&this_component), x->n_lexpr);
                    llll_free(hatom_getllll(&this_sample));
                    llll_free(hatom_getllll(&this_component));
                    hatom_setllll(&this_sample, plus);
                } else if (hatom_gettype(&this_sample) == H_LLLL) {
                    llll_funall(hatom_getllll(&this_sample), sum_fn, &this_component, 0, -1, FUNALL_ONLY_PROCESS_ATOMS);
                } else if (hatom_gettype(&this_component) == H_LLLL) {
                    if (!this_sample_set)
                        this_sample = this_component;
                    else {
                        llll_funall(hatom_getllll(&this_component), sum_fn, &this_sample, 0, -1, FUNALL_ONLY_PROCESS_ATOMS);
                        this_sample = this_component;
                    }
                } else {
                    hatom_op_plus(&this_sample, &this_component, &temp_hatom);
                    this_sample = temp_hatom;
                }
                this_sample_set = true;
            }
        }
        
        llll_appendhatom(out_ll, &this_sample);
    }
    
    return out_ll;
}


void resample_anything(t_resample *x, t_symbol *msg, long ac, t_atom *av)
{
    if (msg != _sym_bang)
        llllobj_parse_and_store((t_object *)x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
    
    t_llll *ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    
    systhread_mutex_lock(x->n_mutex);
    char factor_is_rational = true;
    long new_size = ll->l_size;
    
    if (x->n_mode == BACH_RESAMPLE_MODE_TARGETLENGTH) {
        new_size = x->n_length;
        factor_is_rational = true;
    } else {
        t_llll *factor_ll = llll_parse(1, &x->n_factor);
        t_rational factor_rat = long2rat(1);
        double factor = 1.;
        
        if (factor_ll->l_head) {
            if (hatom_gettype(&factor_ll->l_head->l_hatom) == H_DOUBLE) {
                factor_is_rational = false;
                factor = hatom_getdouble(&factor_ll->l_head->l_hatom);
            } else {
                factor_rat = hatom_getrational(&factor_ll->l_head->l_hatom);
                if (factor_rat.r_den == 0)
                    factor_rat = long2rat(0);
            }
        }
        
        if (factor_is_rational)
            new_size = ll->l_size * factor_rat.r_num / factor_rat.r_den;
        else
            new_size = (long)round(ll->l_size * factor);
    }
    
    t_llll *multipliers = get_multipliers_for_resampling((t_object *)x, ll->l_size, x->n_support, 0, ll->l_size, new_size, x->n_align, resample_get_function(x), x->n_function == BACH_RESAMPLE_NEAREST, factor_is_rational && (x->n_function == BACH_RESAMPLE_NEAREST || x->n_function == BACH_RESAMPLE_POINT || x->n_function == BACH_RESAMPLE_TRIANGLE), resample_get_rat_function(x));
    
    t_llll *res = multipliers_to_res(x, multipliers, ll);
    
    systhread_mutex_unlock(x->n_mutex);

    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, multipliers);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, res);
    
    llll_free(ll);
    llll_free(multipliers);
    llll_free(res);
}


void resample_assist(t_resample *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest Incoming llll
		sprintf(s, "llll");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a == 0)
            sprintf(s, "Resampled llll (%s)", type); // @out 0 @type llll @digest Resampled llll
        else
            sprintf(s, "Resampling coefficients (%s)", type); // @in 1 @type llll @digest Resampling coefficients
                                // @description For each of the output samples an llll of the type
                                // <m>(<b>el_idx1</b> <b>coeff1</b>] [<b>el_idx2</b> <b>coeff2</b>)...</m>
                                // is output; the sample is actually the linear combination <b>el_1 * coeff1 + el_2 * coeff2...</b>,
                                // where <m>el_i</m> is the element of the original list at position <m>el_idxi</m>.
	}
}

void resample_inletinfo(t_resample *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void resample_free(t_resample *x)
{
    systhread_mutex_free_debug(x->n_mutex);
    lexpr_free(x->n_lexpr);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_resample *resample_new(t_symbol *s, short ac, t_atom *av)
{
	t_resample *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_resample *) object_alloc_debug(resample_class))) {
        atom_setlong(&x->n_factor, 1);
        x->n_length = 0;
        x->n_mode = BACH_RESAMPLE_MODE_FACTOR;
        x->n_support = 2;
        x->n_function = BACH_RESAMPLE_BLACKMAN_SINC;
        x->n_align = 1; // center

        systhread_mutex_new_debug(&x->n_mutex, 0);

        long fooac;
        t_atom *fooav = NULL;
        atom_setparse_debug(&fooac, &fooav, "$x1 + $x2");
        x->n_lexpr = lexpr_new(fooac, fooav, 0, NULL, (t_object *) x);
        bach_freeptr(fooav);
        
		attr_args_process(x, ac, av);
        
        // @arg 0 @name factor_or_target_length @optional 1 @type number @digest Factor or target length
        // @description In "Multiplier" mode (default) sets the sampling factor; in "Target length" mode sets the
        // expected output length.
        long true_ac = attr_args_offset(ac, av);
        if (true_ac) {
            if (x->n_mode == BACH_RESAMPLE_MODE_TARGETLENGTH)
                x->n_length = atom_getlong(av);
            else
                x->n_factor = *av;
        }
        
        if (x->n_mode == BACH_RESAMPLE_MODE_TARGETLENGTH)
            object_attr_setdisabled((t_object *)x, gensym("factor"), true);
        else
            object_attr_setdisabled((t_object *)x, gensym("length"), true);
        
		llllobj_obj_setup((t_llllobj_object *) x, 1, "44");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

