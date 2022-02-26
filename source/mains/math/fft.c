/*
 *  fft.c
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
	fft.c
	
	@name 
	bach.fft
	
	@realname 
	bach.fft

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Fast Fourier transform for lllls
	
	@description
	Performs the Fast Fourier transform on 
	the incoming llll (whatever its size is), and outputs 
	either the cartesian or the polar representation.
	
	@discussion
	The algorithm used is the one provided by the library kiss_fft
	
	@category
	bach, bach objects, bach math

	@keywords
	Fourier, transform, discrete

	@seealso
	fft~, bach.expr, bach.pol2car, bach.car2pol, bach.resample
	
	@owner
	Daniele Ghisi
*/

#include "math/spectral.h"
#include "foundation/llll_files.h" // llllobj.h is included here
#include "foundation/llll_commons_ext.h"
#include "libraries/kiss_fft/kiss_fft.h"
#include "foundation/llll_commons.h"
#include "math/bach_math_utilities.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>


typedef struct _fft
{
	struct llllobj_object	n_ob; 

	long			inverse;
	long			polar;
	
	void	*n_proxy[2];
	long	n_in;

	t_systhread_mutex		c_mutex;

} t_fft;


void fft_assist(t_fft *x, void *b, long m, long a, char *s);
void fft_inletinfo(t_fft *x, void *b, long a, char *t);

t_fft *fft_new(t_symbol *s, short ac, t_atom *av);
void fft_free(t_fft *x);

void fft_bang(t_fft *x);
void fft_int(t_fft *x, t_atom_long v);
void fft_float(t_fft *x, double v);
void fft_anything(t_fft *x, t_symbol *msg, long ac, t_atom *av);
t_max_err fft_notify(t_fft *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_class *fft_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.fft", (method)fft_new, (method)fft_free, (long) sizeof(t_fft), 0L, A_GIMME, 0);
	
	// @method llll @digest Perform the FFT of the incoming llll
	// @description The algorithm performs the FFT on the incoming data, assumed to be a plain llll. 
	// The library used to perform such task is kiss_fft.
	class_addmethod(c, (method)fft_anything,		"anything",		A_GIMME,	0);			
	
	
	class_addmethod(c, (method)fft_int,				"int",			A_LONG,		0);			
	class_addmethod(c, (method)fft_float,			"float",		A_FLOAT,	0);
	class_addmethod(c, (method)fft_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the FFT
	// @description Perform the FFT operation on the most recently received input value.
	class_addmethod(c, (method)fft_bang,			"bang",			0);					
	
	class_addmethod(c, (method)fft_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)fft_inletinfo,		"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	CLASS_ATTR_LONG(c, "inv",	0,	t_fft, inverse);
	CLASS_ATTR_LABEL(c, "inv", 0, "Perform Inverse FFT");
	CLASS_ATTR_BASIC(c, "inv", 0);	
	// @description Perform the inverse FFT, instead of the direct one.

	CLASS_ATTR_LONG(c, "polar",	0,	t_fft, polar);
	CLASS_ATTR_LABEL(c, "polar", 0, "Polar Input And Output");
	CLASS_ATTR_BASIC(c, "polar", 0);	
	// @description Output data in polar coordinates, instead of cartesian ones.

	class_register(CLASS_BOX, c);
	fft_class = c;
	
	dev_post("bach.fft compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void fft_bang(t_fft *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		fft_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void fft_int(t_fft *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	fft_anything(x, _sym_int, 1, &outatom);
}

void fft_float(t_fft *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	fft_anything(x, _sym_float, 1, &outatom);
}

void fft_anything(t_fft *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
	long inlet = proxy_getinlet((t_object *) x);
	
	if (msg != _sym_bang) {
		ll = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		if (!ll)
			return;
		x->n_ob.l_rebuild = 1;
	}
//	 else
//		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlet == 0) {
		t_llll *orig_left, *orig_right, *left, *right;
		double *out_ampli, *out_phase;
		long i, nfft = 0;
		
		orig_left = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		orig_right = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
		
		if (orig_left->l_size > orig_right->l_size) {
			long diff = orig_left->l_size - orig_right->l_size;
			for (i = 0; i < diff; i++)
				llll_appenddouble(orig_right, 0, 0, WHITENULL_llll);
		} else if (orig_right->l_size > orig_left->l_size) {
			long diff = orig_right->l_size - orig_left->l_size;
			for (i = 0; i < diff; i++)
				llll_appenddouble(orig_left, 0, 0, WHITENULL_llll);
		}
		
		nfft = orig_left->l_size; // now this is also = orig_right->l_size
		
		if (nfft > 0) {
			kiss_fft_cpx *fin;
			fin = (kiss_fft_cpx *)bach_newptr(nfft * sizeof(kiss_fft_cpx));
			out_ampli = (double *)bach_newptr(nfft * sizeof(double));
			out_phase = (double *)bach_newptr(nfft * sizeof(double));
			
			
			if (x->polar) {
				double *in_ampli, *in_phase;
				llll_to_double_array(orig_left, &in_ampli);
				llll_to_double_array(orig_right, &in_phase);
				for (i = 0; i < nfft; i++)
					fin[i] = polar_to_cpx(in_ampli[i], in_phase[i]);
				bach_freeptr(in_ampli);
				bach_freeptr(in_phase);
			} else {
				double *in_real, *in_imag;
				llll_to_double_array(orig_left, &in_real);
				llll_to_double_array(orig_right, &in_imag);
				for (i = 0; i < nfft; i++){
					fin[i].r = in_real[i];
					fin[i].i = in_imag[i];
				}
				bach_freeptr(in_real);
				bach_freeptr(in_imag);
			}
			
			bach_fft(nfft, x->inverse, fin, out_ampli, out_phase);
			
			if (x->polar) {
				left = double_array_to_llll(out_ampli, nfft);
				right = double_array_to_llll(out_phase, nfft);
			} else {
				long i;
				left = llll_get();
				right = llll_get();
				for (i = 0; i < nfft; i++) {
					llll_appenddouble(left, out_ampli[i]*cos(out_phase[i]), 0, WHITENULL_llll);
					llll_appenddouble(right, out_ampli[i]*sin(out_phase[i]), 0, WHITENULL_llll);
				}
			}

			bach_freeptr(out_ampli);
			bach_freeptr(out_phase);
			bach_freeptr(fin);
		} else {
			left = llll_get();
			right = llll_get();
		}
		

		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, right, 1);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, left, 0);
		
		x->n_ob.l_rebuild = 0;
		fft_bang(x);
		
		llll_free(orig_left);
		llll_free(orig_right);
	}
}

void fft_assist(t_fft *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) 
			sprintf(s, x->polar ? "llll: Amplitudes" : "llll: Real/x Parts");	// @in 0 @type llll @digest Input amplitudes or real (x) parts 
																				// @description Depending on the object "polar" attribute, this can accept either the incoming 
																				//				amplitudes, or the incoming real parts of the numbers
		else 
			sprintf(s, x->polar ? "llll: Phases" : "llll: Imaginary/y Parts");	// @in 1 @type llll @digest Input phases or imaginary (y) parts
																				// @description Depending on the object "polar" attribute, this can accept either the incoming 
																				//				phases (in radiants), or the incoming imaginary parts of the numbers
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, x->polar ? "llll (%s): FFT Amplitudes" : "llll (%s): FFT Real/x Parts", type);	break; // @out 0 @type llll @digest Output amplitude or real (x) parts
			case 1: sprintf(s, x->polar ? "llll (%s): FFT Phases" : "llll (%s): FFT Imaginary/y Parts", type);	break; // @out 1 @type llll @digest Output phases (in radiants) or imaginary (y) parts
		}
	}
}

void fft_inletinfo(t_fft *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void fft_free(t_fft *x)
{
	object_free_debug(x->n_proxy[1]);
	llllobj_obj_free((t_llllobj_object *) x);
}


t_fft *fft_new(t_symbol *s, short ac, t_atom *av)
{
	t_fft *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_fft *) object_alloc_debug(fft_class))) {
		x->inverse = x->polar = 0;
		attr_args_process(x, ac, av);
		
		llllobj_obj_setup((t_llllobj_object *) x, 2, "44");

		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
	} else
		error(BACH_CANT_INSTANTIATE);
	
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
