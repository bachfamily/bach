/*
 *  bach_slots.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

#include "notation/notation.h"
#include "notation/notation_attrs.h"

#define CONST_SLOT_INT_FLOAT_BAR_Y_POS 0.2 // relative to window active height
#define CONST_SLOT_INT_FLOAT_BAR_Y_HEIGHT 0.35 // relative to window active height
#define CONST_SLOT_INTLIST_FLOATLIST_BAR_UWIDTH 13 // 
#define CONST_SLOT_MAX_LEGEND_CHARS 200

#define CONST_SLOT_CARD_UWIDTH 20






void initialize_slots(t_notation_obj *r_ob, char reinitialize)
{
	int i;

	if (reinitialize)
		free_slotinfos(r_ob);
	
	// the first slot is for the velocity envelope
    i = 0;
	r_ob->slotinfo[i].slot_name = gensym("velocity envelope");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_function);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_FUNCTION;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0;
	r_ob->slotinfo[i].slot_range[1] = CONST_MAX_VELOCITY;
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_RELATIVE;
    r_ob->slotinfo[i].slot_uwidth = -2.;
    r_ob->slotinfo[i].slot_active_uheight = -1.;
	r_ob->slotinfo[i].slot_default = 0;
    r_ob->slotinfo[i].copy_when_split = false;
	
    
    i = 1;
    r_ob->slotinfo[i].slot_name = gensym("slot function");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_function);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_FUNCTION;
    r_ob->slotinfo[i].slot_range_par = 0.;
    r_ob->slotinfo[i].slot_key = 0;
    r_ob->slotinfo[i].slot_range[0] = 0.;
    r_ob->slotinfo[i].slot_range[1] = 1.;
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_RELATIVE;
    r_ob->slotinfo[i].slot_uwidth = -2.;
    r_ob->slotinfo[i].slot_active_uheight = -1.;
    r_ob->slotinfo[i].slot_default = 0;
    r_ob->slotinfo[i].copy_when_split = false;
    
    
    i = 2;
	r_ob->slotinfo[i].slot_name = gensym("slot intlist");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_intlist);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_INTLIST;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0;
	r_ob->slotinfo[i].slot_range[1] = 127;
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_LONG_FLOAT_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
  	r_ob->slotinfo[i].slot_default = 64;
    r_ob->slotinfo[i].copy_when_split = true;

    
    i = 3;
	r_ob->slotinfo[i].slot_name = gensym("slot floatlist");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_floatlist);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_FLOATLIST;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0;
	r_ob->slotinfo[i].slot_range[1] = 1.;
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_LONG_FLOAT_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;
    

    i = 4;
	r_ob->slotinfo[i].slot_name = gensym("slot int");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_int);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_INT;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0;
	r_ob->slotinfo[i].slot_range[1] = 127;
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_LONG_FLOAT_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 64;
    r_ob->slotinfo[i].copy_when_split = true;
    

    i = 5;
	r_ob->slotinfo[i].slot_name = gensym("slot float");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_float);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_FLOAT;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0.;
	r_ob->slotinfo[i].slot_range[1] = 1.;
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_LONG_FLOAT_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;
    

    i = 6;
	r_ob->slotinfo[i].slot_name = gensym("slot text");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_text);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_TEXT;
	r_ob->slotinfo[i].slot_range_par = 0.;
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
	r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_TEXT_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = false;

    
    i = 7;
	r_ob->slotinfo[i].slot_name = gensym("slot filelist");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_filelist);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_FILELIST;
	r_ob->slotinfo[i].slot_range_par = 0.; // idle, ignored
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
	r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL; // idle, ignored
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
	r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_FILELIST_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;

    
    i = 8;
	r_ob->slotinfo[i].slot_name = gensym("slot spat");
	if (reinitialize)
		change_slot_type(r_ob, i, _llllobj_sym_spat);
	else
		r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_SPAT;
	r_ob->slotinfo[i].slot_range_par = 0.; // idle, ignored
	r_ob->slotinfo[i].slot_key = 0;
	r_ob->slotinfo[i].slot_range[0] = 0.; // min radius
	r_ob->slotinfo[i].slot_range[1] = 10.; // max radius
	r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL; // idle, ignored
	r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
	r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_RELATIVE;
    r_ob->slotinfo[i].slot_uwidth = -2.; //CONST_SLOT_FUNCTION_DEFAULT_UWIDTH;
	r_ob->slotinfo[i].slot_active_uheight = -1;
	r_ob->slotinfo[i].slot_default = 0.;

    
    i = 9;
    r_ob->slotinfo[i].slot_name = gensym("slot llll");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_llll);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_LLLL;
    r_ob->slotinfo[i].slot_range_par = 0.;
    r_ob->slotinfo[i].slot_key = 0;
    r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_TEXT_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = false;

	
	for (i = 10; i < CONST_MAX_SLOTS; i++){
        if (i >= 19 && i <= 23) continue;
        
		char temp[20];
		snprintf_zero(temp, 20, "slot %d", i+1);
		r_ob->slotinfo[i].slot_name = gensym(temp);
		r_ob->slotinfo[i].slot_key = '\0';
		r_ob->slotinfo[i].slot_range_par = 0.;
		if (reinitialize)
			change_slot_type(r_ob, i, _llllobj_sym_none);
		else
			r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_NONE;
		r_ob->slotinfo[i].slot_range[0] = 0.;
		r_ob->slotinfo[i].slot_range[1] = 1.;
		r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
		r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
		r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
        r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
		r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_NONE_DEFAULT_UWIDTH;
		r_ob->slotinfo[i].slot_active_uheight = -1;
		r_ob->slotinfo[i].slot_default = 0.;
        r_ob->slotinfo[i].copy_when_split = true;
	}
	
    
    
    for (i = 0; i < CONST_MAX_SLOTS; i++) {
        r_ob->slotinfo[i].slot_num = i;
        r_ob->slotinfo[i].slot_domain[0] = 0;
        r_ob->slotinfo[i].slot_domain[1] = 1;
        r_ob->slotinfo[i].slot_domain_par = 0;
        r_ob->slotinfo[i].slot_singleslotfortiednotes = 1;
        r_ob->slotinfo[i].slot_zrange[0] = 0;
        r_ob->slotinfo[i].slot_zrange[1] = 1;
        r_ob->slotinfo[i].slot_zrange_par = 0;
        r_ob->slotinfo[i].slot_zsnap = NULL;
    }
    
    for (i = 0; i < CONST_MAX_SLOTS; i++) {
        r_ob->slotinfo[i].slot_color = get_default_slotcolor(i);
        r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_NONE;
        r_ob->slotinfo[i].kept_in_background = false;
        r_ob->slotinfo[i].appear_in_popup_menu = false;
        r_ob->slotinfo[i].pops_up_by_right_click = false;
        r_ob->slotinfo[i].trim_with_notehead = false;
        r_ob->slotinfo[i].access_type = k_SLOT_ACCESS_READANDWRITE;
        r_ob->slotinfo[i].grid = NULL;

        r_ob->slotinfo[i].extend_beyond_tails = 0;
    }
    

    
    // Special linked slots
    i = BACH_DEFAULT_SLOT_DYNAMICS - 1;
    r_ob->slotinfo[i].slot_name = gensym("dynamics");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_dynamics);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_DYNAMICS;
    r_ob->slotinfo[i].slot_range_par = 0.;
    r_ob->slotinfo[i].slot_key = 'd';
    r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_DYNAMICS_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = false;
//    r_ob->slotinfo[i].slot_singleslotfortiednotes = false; // we leave it to true!
    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_DYNAMICS;

    
    
    
    
    i = BACH_DEFAULT_SLOT_LYRICS - 1;
    r_ob->slotinfo[i].slot_name = gensym("lyrics");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_text);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_TEXT;
    r_ob->slotinfo[i].slot_range_par = 0.;
    r_ob->slotinfo[i].slot_key = 'l';
    r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_TEXT_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = false;
    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_LYRICS;

    
    i = BACH_DEFAULT_SLOT_ARTICULATIONS - 1;
    r_ob->slotinfo[i].slot_name = gensym("articulations");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_articulations);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_ARTICULATIONS;
    r_ob->slotinfo[i].slot_range_par = 0.;
    r_ob->slotinfo[i].slot_key = 'a';
    r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL;
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_ARTICULATIONS_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;
    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_ARTICULATIONS;

    
    i = BACH_DEFAULT_SLOT_NOTEHEADS - 1;
    r_ob->slotinfo[i].slot_name = gensym("notehead");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_notehead);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_NOTEHEAD;
    r_ob->slotinfo[i].slot_range_par = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_key = 'h';
    r_ob->slotinfo[i].slot_range[0] = 0.;
    r_ob->slotinfo[i].slot_range[1] = 1.;
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL; // idle, ignored
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0;
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false;
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_NOTEHEAD_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;
    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_NOTEHEAD;

    
    i = BACH_DEFAULT_SLOT_ANNOTATIONS - 1;
    r_ob->slotinfo[i].slot_name = gensym("annotation");
    if (reinitialize)
        change_slot_type(r_ob, i, _llllobj_sym_text);
    else
        r_ob->slotinfo[i].slot_type = k_SLOT_TYPE_TEXT;
    r_ob->slotinfo[i].slot_range_par = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_key = 't';
    r_ob->slotinfo[i].slot_range[0] = 0.; // idle, ignored
    r_ob->slotinfo[i].slot_range[1] = 1.; // idle, ignored
    r_ob->slotinfo[i].slot_repr = r_ob->slotinfo[i].slot_ysnap = NULL; // idle, ignored
    r_ob->slotinfo[i].slot_num_cols = r_ob->slotinfo[i].slot_num_rows = 0; // idle, ignored
    r_ob->slotinfo[i].slot_has_enum_rows = r_ob->slotinfo[i].slot_has_enum_cols = false; // idle, ignored
    r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    r_ob->slotinfo[i].slot_uwidth = CONST_SLOT_TEXT_DEFAULT_UWIDTH;
    r_ob->slotinfo[i].slot_active_uheight = -1;
    r_ob->slotinfo[i].slot_default = 0.;
    r_ob->slotinfo[i].copy_when_split = true;
    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_ANNOTATION;


    if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
        for (i = 0; i < CONST_MAX_SLOTS; i++)
            r_ob->slotinfo[i].slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
}

void free_slotinfos(t_notation_obj *r_ob){
	long j;
	for (j=0; j<CONST_MAX_SLOTS; j++) {
		if (r_ob->slotinfo[j].slot_repr) {
			llll_free(r_ob->slotinfo[j].slot_repr);
			r_ob->slotinfo[j].slot_repr = NULL; // needed for resetslotinfo message
		}
		if (r_ob->slotinfo[j].slot_ysnap) {
			llll_free(r_ob->slotinfo[j].slot_ysnap);
			r_ob->slotinfo[j].slot_ysnap = NULL;
		}
		if (r_ob->slotinfo[j].slot_zsnap) {
			llll_free(r_ob->slotinfo[j].slot_zsnap);
			r_ob->slotinfo[j].slot_zsnap = NULL;
		}
        if (r_ob->slotinfo[j].grid) {
            llll_free(r_ob->slotinfo[j].grid);
            r_ob->slotinfo[j].grid = NULL;
        }
	}
}
	
// convert the numerical slottype to symbol
t_symbol *slot_type_to_symbol(e_slot_types slot_type)
{
	switch (slot_type) {
		case k_SLOT_TYPE_FUNCTION: return _llllobj_sym_function;
		case k_SLOT_TYPE_SPAT: return _llllobj_sym_spat;
		case k_SLOT_TYPE_INT: return _llllobj_sym_int; 
		case k_SLOT_TYPE_FLOAT: return _llllobj_sym_float;
		case k_SLOT_TYPE_INTLIST: return _llllobj_sym_intlist;
		case k_SLOT_TYPE_FLOATLIST: return _llllobj_sym_floatlist;
		case k_SLOT_TYPE_TEXT: return _llllobj_sym_text;
		case k_SLOT_TYPE_LLLL: return _llllobj_sym_llll;
		case k_SLOT_TYPE_INTMATRIX: return _llllobj_sym_intmatrix;
		case k_SLOT_TYPE_FLOATMATRIX: return _llllobj_sym_floatmatrix;
		case k_SLOT_TYPE_TOGGLEMATRIX: return _llllobj_sym_togglematrix;
		case k_SLOT_TYPE_FILELIST: return _llllobj_sym_filelist;
		case k_SLOT_TYPE_FILTER: return _llllobj_sym_filter;
		case k_SLOT_TYPE_DYNFILTER: return _llllobj_sym_dynfilter;
		case k_SLOT_TYPE_COLOR: return _llllobj_sym_color;
		case k_SLOT_TYPE_3DFUNCTION: return _llllobj_sym_3dfunction;
        case k_SLOT_TYPE_ARTICULATIONS: return _llllobj_sym_articulations;
        case k_SLOT_TYPE_NOTEHEAD: return _llllobj_sym_notehead;
        case k_SLOT_TYPE_DYNAMICS: return _llllobj_sym_dynamics;
		default: return _llllobj_sym_none;
	}	
}

// convert the symbolic slottype to the numerical type
e_slot_types slot_symbol_to_type(t_symbol *type)
{
    e_slot_types slottype = k_SLOT_TYPE_NONE;
    if (type == _llllobj_sym_function)
        slottype = k_SLOT_TYPE_FUNCTION;
    else if (type == _llllobj_sym_3dfunction)
        slottype = k_SLOT_TYPE_3DFUNCTION;
    else if (type == _llllobj_sym_spat)
        slottype = k_SLOT_TYPE_SPAT;
    else if (type == _llllobj_sym_int)
        slottype = k_SLOT_TYPE_INT;
    else if (type == _llllobj_sym_float)
        slottype = k_SLOT_TYPE_FLOAT;
    else if (type == _llllobj_sym_intlist)
        slottype = k_SLOT_TYPE_INTLIST;
    else if (type == _llllobj_sym_floatlist)
        slottype = k_SLOT_TYPE_FLOATLIST;
    else if (type == _llllobj_sym_text)
        slottype = k_SLOT_TYPE_TEXT;
    else if (type == _llllobj_sym_llll)
        slottype = k_SLOT_TYPE_LLLL;
    else if (type == _llllobj_sym_intmatrix)
        slottype = k_SLOT_TYPE_INTMATRIX;
    else if (type == _llllobj_sym_floatmatrix)
        slottype = k_SLOT_TYPE_FLOATMATRIX;
    else if (type == _llllobj_sym_togglematrix)
        slottype = k_SLOT_TYPE_TOGGLEMATRIX;
    else if (type == _llllobj_sym_filelist)
        slottype = k_SLOT_TYPE_FILELIST;
    else if (type == _llllobj_sym_filter)
        slottype = k_SLOT_TYPE_FILTER;
    else if (type == _llllobj_sym_dynfilter)
        slottype = k_SLOT_TYPE_DYNFILTER;
    else if (type == _llllobj_sym_color)
        slottype = k_SLOT_TYPE_COLOR;
    else if (type == _llllobj_sym_articulations)
        slottype = k_SLOT_TYPE_ARTICULATIONS;
    else if (type == _llllobj_sym_notehead)
        slottype = k_SLOT_TYPE_NOTEHEAD;
    else if (type == _llllobj_sym_dynamics)
        slottype = k_SLOT_TYPE_DYNAMICS;
    else
        slottype = k_SLOT_TYPE_NONE;
    return slottype;
}


t_symbol *slot_temporalmode_to_symbol(e_slot_temporalmodes slot_temporalmode)
{
    switch (slot_temporalmode) {
        case k_SLOT_TEMPORALMODE_RELATIVE: return _llllobj_sym_relative;
        case k_SLOT_TEMPORALMODE_MILLISECONDS: return _llllobj_sym_milliseconds;
        case k_SLOT_TEMPORALMODE_TIMEPOINTS: return _llllobj_sym_timepoints;
        default: return _llllobj_sym_none;
    }	
}


e_slot_temporalmodes slot_symbol_to_temporalmode(t_symbol *temporalmode)
{
    e_slot_temporalmodes slot_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    if (temporalmode == _llllobj_sym_relative)
        slot_temporalmode = k_SLOT_TEMPORALMODE_RELATIVE;
    else if (temporalmode == _llllobj_sym_milliseconds)
        slot_temporalmode = k_SLOT_TEMPORALMODE_MILLISECONDS;
    else if (temporalmode == _llllobj_sym_timepoints)
        slot_temporalmode = k_SLOT_TEMPORALMODE_TIMEPOINTS;
    return slot_temporalmode;
}




long slot_access_type_from_symbol(t_symbol *sym)
{
    if (sym == _llllobj_sym_none)
        return k_SLOT_ACCESS_CANT;
    
    if (sym == _llllobj_sym_readonly)
        return k_SLOT_ACCESS_READONLY;
    
    return k_SLOT_ACCESS_READANDWRITE;
}

t_symbol *slot_access_type_to_symbol(e_slot_access_types type)
{
    switch (type) {
        case k_SLOT_ACCESS_CANT:
            return _llllobj_sym_none;
            break;

        case k_SLOT_ACCESS_READONLY:
            return _llllobj_sym_readonly;
            break;

        case k_SLOT_ACCESS_READANDWRITE:
        default:
            return _llllobj_sym_readandwrite;
            break;
    }
}

char is_slot_readable(t_notation_obj *r_ob, long slotnum)
{
    if (slotnum >= 0 && slotnum < CONST_MAX_SLOTS && r_ob->slotinfo[slotnum].access_type != k_SLOT_ACCESS_CANT)
        return true;
    return false;
}

char slot_is_writable(t_notation_obj *r_ob, long slotnum)
{
    if (slotnum >= 0 && slotnum < CONST_MAX_SLOTS && r_ob->slotinfo[slotnum].access_type == k_SLOT_ACCESS_READANDWRITE)
        return true;
    return false;
}



t_llll* get_single_slotinfo_as_llll(t_notation_obj *r_ob, long slotnum, char explicitly_get_also_default_stuff, char also_get_fields_saved_in_max_inspector)
{
    long j = slotnum;
    t_llll* inner_llll = llll_get();
    t_llll *name = llll_get();
    t_llll *type = llll_get();
    t_llll *key = llll_get();
    
    char key_char[2];
    long slot_type = r_ob->slotinfo[j].slot_type;
    
    // number (1-based)
    llll_appendlong(inner_llll, j + 1, 0, WHITENULL_llll);
    
    // name
    llll_appendsym(name, _llllobj_sym_name, 0, WHITENULL_llll);
    llll_appendsym(name, r_ob->slotinfo[j].slot_name, 0, WHITENULL_llll);
    llll_appendllll(inner_llll, name, 0, WHITENULL_llll);
    
    // type
    llll_appendsym(type, _llllobj_sym_type, 0, WHITENULL_llll);
    llll_appendsym(type, slot_type_to_symbol((e_slot_types)r_ob->slotinfo[j].slot_type), 0, WHITENULL_llll);
    llll_appendllll(inner_llll, type, 0, WHITENULL_llll);
    
    // key
    key_char[0] = r_ob->slotinfo[j].slot_key;
    key_char[1] = 0;
    llll_appendsym(key, _llllobj_sym_key, 0, WHITENULL_llll);
    if (r_ob->slotinfo[j].slot_key > 0)
        llll_appendsym(key, gensym(key_char), 0, WHITENULL_llll);
    else
        llll_appendlong(key, 0, 0, WHITENULL_llll);
    llll_appendllll(inner_llll, key, 0, WHITENULL_llll);
    
    if (explicitly_get_also_default_stuff ||
        (slot_type != k_SLOT_TYPE_FILELIST && slot_type != k_SLOT_TYPE_TEXT && slot_type != k_SLOT_TYPE_LLLL && slot_type != k_SLOT_TYPE_NONE && slot_type != k_SLOT_TYPE_COLOR &&  slot_type != k_SLOT_TYPE_ARTICULATIONS && slot_type != k_SLOT_TYPE_NOTEHEAD && slot_type != k_SLOT_TYPE_DYNAMICS)) {
        // range
        t_llll *range = llll_get();
        t_llll *slope = llll_get();
        t_llll *rep = llll_get();
        llll_appendsym(range, _llllobj_sym_range, 0, WHITENULL_llll);
        llll_appenddouble(range, r_ob->slotinfo[j].slot_range[0], 0, WHITENULL_llll);
        llll_appenddouble(range, r_ob->slotinfo[j].slot_range[1], 0, WHITENULL_llll);
        llll_appendllll(inner_llll, range, 0, WHITENULL_llll);
        
        // slope
        llll_appendsym(slope, _llllobj_sym_slope, 0, WHITENULL_llll);
        llll_appenddouble(slope, r_ob->slotinfo[j].slot_range_par, 0, WHITENULL_llll);
        llll_appendllll(inner_llll, slope, 0, WHITENULL_llll);
        
        // representation
        llll_appendsym(rep, _llllobj_sym_representation, 0, WHITENULL_llll);
        if (r_ob->slotinfo[j].slot_repr && r_ob->slotinfo[j].slot_repr->l_head) {
            llll_appendhatom_clone(rep, &r_ob->slotinfo[j].slot_repr->l_head->l_hatom, 0, WHITENULL_llll);
            if (r_ob->slotinfo[j].slot_repr->l_head->l_next)
                llll_appendhatom_clone(rep, &r_ob->slotinfo[j].slot_repr->l_head->l_next->l_hatom, 0, WHITENULL_llll);
        }
        llll_appendllll(inner_llll, rep, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || (slot_type == k_SLOT_TYPE_FUNCTION)) {
        t_llll *grid = llll_get();
        llll_appendsym(grid, _sym_grid, 0, WHITENULL_llll);
        if (r_ob->slotinfo[j].grid)
            llll_chain_clone(grid, r_ob->slotinfo[j].grid);
        llll_appendllll(inner_llll, grid, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || (slot_type == k_SLOT_TYPE_3DFUNCTION)) {
        // zrange
        t_llll *zrange = llll_get();
        t_llll *zslope = llll_get();
        llll_appendsym(zrange, _llllobj_sym_zrange, 0, WHITENULL_llll);
        llll_appenddouble(zrange, r_ob->slotinfo[j].slot_zrange[0], 0, WHITENULL_llll);
        llll_appenddouble(zrange, r_ob->slotinfo[j].slot_zrange[1], 0, WHITENULL_llll);
        llll_appendllll(inner_llll, zrange, 0, WHITENULL_llll);
        
        // zslope
        llll_appendsym(zslope, _llllobj_sym_zslope, 0, WHITENULL_llll);
        llll_appenddouble(zslope, r_ob->slotinfo[j].slot_zrange_par, 0, WHITENULL_llll);
        llll_appendllll(inner_llll, zslope, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || slot_type == k_SLOT_TYPE_FUNCTION || slot_type == k_SLOT_TYPE_3DFUNCTION) {
        t_llll *ysnap = llll_get();
        llll_appendsym(ysnap, _llllobj_sym_ysnap, 0, WHITENULL_llll);
        if (r_ob->slotinfo[j].slot_ysnap)
            llll_chain_clone(ysnap, r_ob->slotinfo[j].slot_ysnap);
        llll_appendllll(inner_llll, ysnap, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || slot_type == k_SLOT_TYPE_3DFUNCTION) {
        t_llll *zsnap = llll_get();
        llll_appendsym(zsnap, _llllobj_sym_zsnap, 0, WHITENULL_llll);
        if (r_ob->slotinfo[j].slot_zsnap)
            llll_chain_clone(zsnap, r_ob->slotinfo[j].slot_zsnap);
        llll_appendllll(inner_llll, zsnap, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || (slot_type == k_SLOT_TYPE_FUNCTION || slot_type == k_SLOT_TYPE_3DFUNCTION || slot_type == k_SLOT_TYPE_FILTER || slot_type == k_SLOT_TYPE_DYNFILTER)) {
        t_llll *domain = llll_get();
        t_llll *domainslope = llll_get();
        
        llll_appendsym(domain, _llllobj_sym_domain, 0, WHITENULL_llll);
        llll_appenddouble(domain, r_ob->slotinfo[j].slot_domain[0], 0, WHITENULL_llll);
        llll_appenddouble(domain, r_ob->slotinfo[j].slot_domain[1], 0, WHITENULL_llll);
        
        llll_appendsym(domainslope, _llllobj_sym_domainslope, 0, WHITENULL_llll);
        llll_appenddouble(domainslope, r_ob->slotinfo[j].slot_domain_par, 0, WHITENULL_llll);
        
        llll_appendllll(inner_llll, domain, 0, WHITENULL_llll);
        llll_appendllll(inner_llll, domainslope, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || !are_colors_equal(r_ob->slotinfo[j].slot_color, get_default_slotcolor(j), 0.01)) {
        t_llll *color = llll_get();
        llll_appendsym(color, _llllobj_sym_color, 0, WHITENULL_llll);
        llll_appenddouble(color, r_ob->slotinfo[j].slot_color.red, 0, WHITENULL_llll);
        llll_appenddouble(color, r_ob->slotinfo[j].slot_color.green, 0, WHITENULL_llll);
        llll_appenddouble(color, r_ob->slotinfo[j].slot_color.blue, 0, WHITENULL_llll);
        llll_appenddouble(color, r_ob->slotinfo[j].slot_color.alpha, 0, WHITENULL_llll);
        llll_appendllll(inner_llll, color, 0, WHITENULL_llll);
    }
    
    if (explicitly_get_also_default_stuff || slot_type == k_SLOT_TYPE_INT || slot_type == k_SLOT_TYPE_INTLIST || slot_type == k_SLOT_TYPE_FLOAT || slot_type == k_SLOT_TYPE_FLOATLIST ||
        slot_type == k_SLOT_TYPE_TOGGLEMATRIX || slot_type == k_SLOT_TYPE_INTMATRIX || slot_type == k_SLOT_TYPE_FLOATMATRIX) {
        t_llll *defaultllll = llll_get();
        llll_appendsym(defaultllll, _llllobj_sym_default, 0, WHITENULL_llll);
        llll_appenddouble(defaultllll, r_ob->slotinfo[j].slot_default, 0, WHITENULL_llll);
        llll_appendllll(inner_llll, defaultllll, 0, WHITENULL_llll);
    }
    
    t_llll *temporalmode = llll_get();
    llll_appendsym(temporalmode, _llllobj_sym_temporalmode);
    switch (r_ob->slotinfo[j].slot_temporalmode) {
        case k_SLOT_TEMPORALMODE_NONE:
            llll_appendsym(temporalmode, _llllobj_sym_none);
            break;
        case k_SLOT_TEMPORALMODE_RELATIVE:
            llll_appendsym(temporalmode, _llllobj_sym_relative);
            break;
        case k_SLOT_TEMPORALMODE_MILLISECONDS:
            llll_appendsym(temporalmode, _llllobj_sym_milliseconds);
            break;
        case k_SLOT_TEMPORALMODE_TIMEPOINTS:
            llll_appendsym(temporalmode, _llllobj_sym_timepoints);
            break;
        default:
            break;
    }
    llll_appendllll(inner_llll, temporalmode);
    
    t_llll *extend = llll_get();
    llll_appendsym(extend, _llllobj_sym_extend);
    llll_appendlong(extend, r_ob->slotinfo[j].extend_beyond_tails);
    llll_appendllll(inner_llll, extend);
    
    
    
    t_llll *width = llll_get();
    llll_appendsym(width, _llllobj_sym_width, 0, WHITENULL_llll);
    if (r_ob->slotinfo[j].slot_uwidth < 0) {
        if (r_ob->slotinfo[j].slot_uwidth == -2.)
            llll_appendsym(width, _llllobj_sym_auto);
        else if (r_ob->slotinfo[j].slot_uwidth == -3.)
            llll_appendsym(width, _llllobj_sym_duration);
        else
            llll_appendsym(width, _llllobj_sym_temporal);
    } else {
        llll_appenddouble(width, r_ob->slotinfo[j].slot_uwidth, 0, WHITENULL_llll);
    }
    llll_appendllll(inner_llll, width, 0, WHITENULL_llll);
    
    
    t_llll *height = llll_get();
    llll_appendsym(height, _llllobj_sym_height, 0, WHITENULL_llll);
    if (r_ob->slotinfo[j].slot_active_uheight < 0)
        llll_appendsym(height, _llllobj_sym_auto, 0, WHITENULL_llll);
    else
        llll_appenddouble(height, r_ob->slotinfo[j].slot_active_uheight, 0, WHITENULL_llll);
    llll_appendllll(inner_llll, height, 0, WHITENULL_llll);
    
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_singleslotfortiednotes, r_ob->slotinfo[j].slot_singleslotfortiednotes));
    
    llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_copywhensplit, r_ob->slotinfo[j].copy_when_split));
    
    llll_appendllll(inner_llll, symbol_and_symbol_to_llll(_llllobj_sym_access, slot_access_type_to_symbol((e_slot_access_types)r_ob->slotinfo[j].access_type)));
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_follownotehead, r_ob->slotinfo[j].trim_with_notehead));
    
    if (also_get_fields_saved_in_max_inspector) {
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_background, r_ob->slotinfo[j].kept_in_background));
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_popup, r_ob->slotinfo[j].appear_in_popup_menu));
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_linkto, r_ob->slotinfo[j].linked_to));
        llll_appendllll(inner_llll, build_sym_long_llll(_llllobj_sym_rightclick, r_ob->slotinfo[j].pops_up_by_right_click));
    }
    return inner_llll;
}
                                    
t_llll* get_slotinfo_as_llll(t_notation_obj *r_ob, char explicitly_get_also_default_stuff, char also_get_fields_saved_in_max_inspector, char bw_compatible){
	t_llll* out_llll = llll_get();
	int j;

	llll_appendsym(out_llll, _llllobj_sym_slotinfo, 0, WHITENULL_llll);
	
    for (j = 0; j < (bw_compatible ? 30 : CONST_MAX_SLOTS); j++)
        llll_appendllll(out_llll, get_single_slotinfo_as_llll(r_ob, j, explicitly_get_also_default_stuff, also_get_fields_saved_in_max_inspector));
	return out_llll;
	
}


char can_slot_be_hzoomed(t_notation_obj *r_ob, long slot_num)
{
    switch (r_ob->slotinfo[slot_num].slot_type) {
        case k_SLOT_TYPE_FUNCTION:
        case k_SLOT_TYPE_3DFUNCTION:
        case k_SLOT_TYPE_SPAT:
        case k_SLOT_TYPE_DYNFILTER:
        case k_SLOT_TYPE_INTLIST:
        case k_SLOT_TYPE_FLOATLIST:
            return 1;
            break;
            
        default:
            return 0;
            break;
    }
}

char can_slot_be_hmoved(t_notation_obj *r_ob, long slot_num)
{
    
    switch (r_ob->slotinfo[slot_num].slot_type) {
        case k_SLOT_TYPE_ARTICULATIONS:
        case k_SLOT_TYPE_NOTEHEAD:
            return 1;
            break;

        case k_SLOT_TYPE_FUNCTION:
        case k_SLOT_TYPE_3DFUNCTION:
        case k_SLOT_TYPE_SPAT:
        case k_SLOT_TYPE_DYNFILTER:
        case k_SLOT_TYPE_INTLIST:
        case k_SLOT_TYPE_FLOATLIST:
            return 1;
            break;
            
        default:
            return 0;
            break;
    }

}


t_chord *notation_item_get_parent_chord(t_notation_obj *r_ob, t_notation_item *nitem)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
        return NULL;
    
    switch (nitem->type) {
        case k_NOTE:
            return ((t_note *)nitem)->parent;
            break;

        case k_PITCH_BREAKPOINT:
            return ((t_bpt *)nitem)->owner->parent;
            break;

        case k_CHORD:
            return ((t_chord *)nitem);
            break;
            
        default:
            return NULL;
            break;
    }
}




t_slot *notation_item_get_slot_extended(t_notation_obj *r_ob, t_notation_item *nitem, long slotnumber, char force_get_for_chords)
{
    if (!nitem || slotnumber < 0 || slotnumber > CONST_MAX_SLOTS)
        return NULL;
    
    switch (nitem->type) {
        case k_NOTE:
            return &((t_note *)nitem)->slot[slotnumber];
            break;

        case k_CHORD:
            if (!force_get_for_chords && ((t_chord *)nitem)->firstnote)
                return NULL;
            else
#ifdef BACH_CHORDS_HAVE_SLOTS
                return &((t_chord *)nitem)->slot[slotnumber];
#else
                return NULL;
#endif
            break;

        case k_MARKER:
#ifdef BACH_MARKERS_HAVE_SLOTS
            return &((t_marker *)nitem)->slot[slotnumber];
#else
            return NULL;
#endif
            
        default:
            return NULL;
            break;
    }
}

t_slot *notation_item_get_slot(t_notation_obj *r_ob, t_notation_item *nitem, long slotnumber)
{
    return notation_item_get_slot_extended(r_ob, nitem, slotnumber, false);
}

t_slotitem *notation_item_get_slot_firstitem(t_notation_obj *r_ob, t_notation_item *nitem, long slotnumber)
{
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slotnumber);
    if (slot)
        return slot->firstitem;
    
    return NULL;
}

t_slotitem *notation_item_get_slot_nth_item(t_notation_obj *r_ob, t_notation_item *nitem, long slotnumber, long n)
{
    t_slotitem *it = notation_item_get_slot_firstitem(r_ob, nitem, slotnumber);
    
    for (long i = 0; it && i < n; i++)
        it = it->next;
    
    return it;
}

t_slotitem *slot_get_nth_item(t_slot *s, long n)
{
    t_slotitem *it = s->firstitem;
    
    for (long i = 0; it && i < n; i++)
        it = it->next;
    
    return it;
}



long notation_item_get_slot_numitems(t_notation_obj *r_ob, t_notation_item *nitem, long slotnumber)
{
    // can't rely on slot->length, since we use that for number of chars in text slot.
    // Not a great way of doing this, though, but we almost never used this function
    t_slot *s = notation_item_get_slot_extended(r_ob, nitem, slotnumber, false);
    if (!s || !s->firstitem)
        return 0;
    
    long count = 0;
    t_slotitem *item;
    for (item = s->firstitem; item; item = item->next)
        count++;
    
    return count;
}


t_slot *get_activeitem_slot(t_notation_obj *r_ob, long slotnumber)
{
    return notation_item_get_slot(r_ob, r_ob->active_slot_notationitem, slotnumber);
}



t_slot *get_activeitem_activeslot(t_notation_obj *r_ob)
{
    return get_activeitem_slot(r_ob, r_ob->active_slot_num);
}


t_slotitem *get_activeitem_slot_firstitem(t_notation_obj *r_ob, long slotnum)
{
    t_slot *slot = get_activeitem_slot(r_ob, slotnum);
    if (slot)
        return slot->firstitem;
    
    return NULL;
}

long get_activeitem_slot_length(t_notation_obj *r_ob, long slotnum)
{
    t_slot *slot = get_activeitem_slot(r_ob, slotnum);
    if (slot)
        return slot->length;
    
    return 0;
}

t_slotitem *get_activeitem_activeslot_firstitem(t_notation_obj *r_ob)
{
    t_slot *slot = get_activeitem_activeslot(r_ob);
    if (slot)
        return slot->firstitem;
    
    return NULL;
}


void paint_numberlist_bars_in_noteslot(t_notation_obj *r_ob, t_jgraphics* g, t_rect *bars_bounding_rectangle, t_rect *displayed_bounding_rectangle,
									   t_notation_item *nitem, long slot_number, t_jrgba slot_color, char alternate, double slot_zoom,
									   char paint_bar_labels, t_jfont *jf_label_font, t_jrgba label_color){
	
	// retrieve content: we expect the content to be an array of long/floats
	long s = slot_number;
	double slot_max = r_ob->slotinfo[s].slot_range[1]; 
	double slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
	t_slotitem *temp;
	char is_enum = false; 
	long how_many_enums = 0, count = 0; 
	char unit[30]; 
	char value_str[50];
	double cur_x = 0, bar_width = get_slot_numberlist_single_bar_width(r_ob, slot_number, nitem);
	double bars_surface_top_pad = 10 * r_ob->zoom_y * slot_zoom / 100.;
	double bars_surface_bottom_pad = 2;
	unit[0] = '\0';
	
//	dev_post("y1: %.3f, y2: %.3f", displayed_bounding_rectangle->y, displayed_bounding_rectangle->y+displayed_bounding_rectangle->height);
	
	t_jsurface *bars_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, bars_bounding_rectangle->width, bars_bounding_rectangle->height + bars_surface_top_pad + bars_surface_bottom_pad);
	t_jgraphics *bars_g = jgraphics_create(bars_surface);

	for (count = 0, cur_x = 0, temp = get_activeitem_slot_firstitem(r_ob, s); temp; temp = temp->next, cur_x += bar_width, count++){
		double curr_val; // let's retrieve the slot value
		if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST)
			curr_val = *((long *)temp->item); // long item
		else
			curr_val = *((double *)temp->item); // double item
		curr_val = CLAMP(curr_val, slot_min, slot_max);
		
		double this_height = notationobj_rescale_with_slope_inv(r_ob, curr_val, slot_min, slot_max, 0, bars_bounding_rectangle->height, r_ob->slotinfo[s].slot_range_par);
		
		paint_filledrectangle(bars_g, alternate && (count % 2) ? color_interp(slot_color, get_grey(0), 0.1) : slot_color, cur_x, bars_bounding_rectangle->height + bars_surface_top_pad - this_height, bar_width, this_height + bars_surface_bottom_pad);
		
		// retrieve display unit (or enum)
		if ((r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST) && r_ob->slotinfo[s].slot_repr 
			&& (r_ob->slotinfo[s].slot_repr->l_size > 0) && (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_LLLL)) {
			is_enum = true;
			how_many_enums = hatom_getllll(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->l_size;
		} else if (r_ob->slotinfo[s].slot_repr && (r_ob->slotinfo[s].slot_repr->l_size > 0) 
				   && (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)) {
			strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
		}
		
		// display the value
		if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST) { // long case
			if (is_enum) {
				long value = (long)round(curr_val);
				if (value - round(slot_min) < how_many_enums) {
					snprintf_zero(value_str, 50, "%s", nth_sym_of_a_plain_sym_llll(hatom_getllll(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom), value - round(slot_min) + 1)->s_name);
					write_text(bars_g, jf_label_font, label_color, value_str, 
						   cur_x, 0, bar_width, bars_bounding_rectangle->height + bars_surface_top_pad - this_height, 
						   JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, true, is_enum ? true : false);
				} else
					write_long_if_there_is_space(bars_g, jf_label_font, label_color, (long)round(curr_val), unit, cur_x, 0, bar_width, bars_bounding_rectangle->height + bars_surface_top_pad - this_height, 
												 JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED);
			} else
				write_long_if_there_is_space(bars_g, jf_label_font, label_color, (long)round(curr_val), unit, cur_x, 0, bar_width, bars_bounding_rectangle->height + bars_surface_top_pad - this_height, 
											 JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED);
		} else // float case
			write_double_account_for_fixed_width(bars_g, jf_label_font, label_color, curr_val, unit, cur_x, 0, bar_width, bars_bounding_rectangle->height + bars_surface_top_pad - this_height, 
												 JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, 4);
		
	}

	t_rect sourceRect = build_rect(displayed_bounding_rectangle->x - bars_bounding_rectangle->x, displayed_bounding_rectangle->y - bars_bounding_rectangle->y, 
								   displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + bars_surface_top_pad + bars_surface_bottom_pad);
	t_rect destRect = build_rect(displayed_bounding_rectangle->x, displayed_bounding_rectangle->y - bars_surface_top_pad, 
								 displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + bars_surface_top_pad + bars_surface_bottom_pad);
//	dev_post("- y1: %.3f, y2: %.3f", sourceRect.y, sourceRect.y+sourceRect.height);
//	dev_post("- y1: %.3f, y2: %.3f", destRect.y, destRect.y+destRect.height);
	jgraphics_set_source_rgba(g, 0, 0, 0, 1);
	jgraphics_image_surface_draw(g, bars_surface, sourceRect, destRect);
	jgraphics_surface_destroy(bars_surface);
	jgraphics_destroy(bars_g);
}


double get_slot_cards_single_card_width(t_notation_obj *r_ob, long slot_num)
{
    return CONST_SLOT_CARD_UWIDTH * r_ob->zoom_y * r_ob->slot_window_zoom / 100.;
}

long get_slot_cards_num_rows(t_notation_obj *r_ob, long slot_num)
{
    return MAX(1, 1 + floor(r_ob->slot_window_active.height / 40.));
}

double get_slot_cards_single_card_height(t_notation_obj *r_ob, long slot_num)
{
    return r_ob->slot_window_active.height / get_slot_cards_num_rows(r_ob, slot_num);
}

long get_slot_cards_num_cols(t_notation_obj *r_ob, long slot_num)
{
    long type = r_ob->slotinfo[slot_num].slot_type;
    long num_cards = (type == k_SLOT_TYPE_ARTICULATIONS ? r_ob->articulations_typo_preferences.num_articulations : r_ob->noteheads_typo_preferences.num_noteheads) - 1;
    long num_rows = get_slot_cards_num_rows(r_ob, slot_num);
    return (long)ceil((float)num_cards / num_rows);
}


void paint_articulations_cards_in_slot(t_notation_obj *r_ob, t_jgraphics* g, t_rect *cards_bounding_rectangle, t_rect *displayed_bounding_rectangle, t_notation_item *nitem, long slot_number, t_jrgba slot_color, char alternate, double slot_zoom, char paint_bar_labels, t_jfont *jf_label_font, t_jrgba label_color)
{
    
    // retrieve content: we expect the content to be an array of long/floats
    long s = slot_number;
    t_slotitem *temp;
    long id;
    long num_cards = r_ob->articulations_typo_preferences.num_articulations - 1;
    double card_width = get_slot_cards_single_card_width(r_ob, slot_number);
    double card_height = get_slot_cards_single_card_height(r_ob, slot_number);
    long num_rows = get_slot_cards_num_rows(r_ob, slot_number);
    long num_cards_per_row = ceil((float)num_cards / num_rows);
    double total_cards_width = num_cards_per_row * card_width;
    double zoom_y = r_ob->zoom_y * slot_zoom / 100.;
    double cards_surface_top_pad = 0.;
    double cards_surface_bottom_pad = 2;
    t_llll *selected_arts = llll_get();
    for (temp = get_activeitem_slot_firstitem(r_ob, s); temp; temp = temp->next)
        llll_appendlong(selected_arts, ((t_articulation *)temp->item)->articulation_ID);


    //	dev_post("y1: %.3f, y2: %.3f", displayed_bounding_rectangle->y, displayed_bounding_rectangle->y+displayed_bounding_rectangle->height);
    
    t_jsurface *cards_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, total_cards_width /*cards_bounding_rectangle->width*/, cards_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);
    t_jgraphics *cards_g = jgraphics_create(cards_surface);
    
    
    for (id = 1; id < r_ob->articulations_typo_preferences.num_articulations; id++) {
        long this_row = (id - 1) % num_cards_per_row;
        long this_col = (id - 1) / num_cards_per_row;
        double cur_x = this_row * card_width;
        double cur_y = this_col * card_height;
        char selected = is_long_in_llll_first_level(selected_arts, id);
        double width, height;
        t_symbol *font = r_ob->articulations_typo_preferences.artpref[id].font;
        double fontsize = r_ob->articulations_typo_preferences.artpref[id].base_pt * zoom_y * 0.75;
        t_jfont *jf_art = jfont_create_debug(font ? font->s_name : r_ob->articulations_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, fontsize);
        char *buf = articulation_to_text_buf(&r_ob->articulations_typo_preferences, id);
        jfont_text_measure(jf_art, buf, &width, &height);
        paint_rectangle(cards_g, build_jrgba(1, 1, 1, 1), selected ? change_alpha(slot_color, 0.5) : build_jrgba(0.9, 0.9, 0.9, 0.5), cur_x, cur_y, card_width, card_height, 1);
        write_text(cards_g, jf_art, label_color, buf, cur_x, cur_y, card_width, card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
        bach_freeptr(buf);
        jfont_destroy_debug(jf_art);
    }
    
    t_rect sourceRect = build_rect(displayed_bounding_rectangle->x - cards_bounding_rectangle->x, displayed_bounding_rectangle->y - cards_bounding_rectangle->y, displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);
    t_rect destRect = build_rect(displayed_bounding_rectangle->x, displayed_bounding_rectangle->y - cards_surface_top_pad,
                                 displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);
    //	dev_post("- y1: %.3f, y2: %.3f", sourceRect.y, sourceRect.y+sourceRect.height);
    //	dev_post("- y1: %.3f, y2: %.3f", destRect.y, destRect.y+destRect.height);
    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
    jgraphics_image_surface_draw(g, cards_surface, sourceRect, destRect);
    jgraphics_surface_destroy(cards_surface);
    jgraphics_destroy(cards_g);
    llll_free(selected_arts);
}


void paint_notehead_cards_in_slot(t_notation_obj *r_ob, t_jgraphics* g, t_rect *cards_bounding_rectangle, t_rect *displayed_bounding_rectangle, t_notation_item *nitem, long slot_number, t_jrgba slot_color, char alternate, double slot_zoom, char paint_bar_labels, t_jfont *jf_label_font, t_jrgba label_color)
{
    
    // retrieve content: we expect the content to be an array of long/floats
    long s = slot_number;
    long id;
    long num_cards = r_ob->noteheads_typo_preferences.num_noteheads - 1;
    double card_width = get_slot_cards_single_card_width(r_ob, slot_number);
    double card_height = get_slot_cards_single_card_height(r_ob, slot_number);
    long num_rows = get_slot_cards_num_rows(r_ob, slot_number);
    long num_cards_per_row = ceil((float)num_cards / num_rows);
    double total_cards_width = num_cards_per_row * card_width;
    double zoom_y = r_ob->zoom_y * slot_zoom / 100.;
    double cards_surface_top_pad = 0.;
    double cards_surface_bottom_pad = 2;
    long selected_id = -1;
    if (get_activeitem_slot_firstitem(r_ob, s))
        selected_id = notationobj_notehead_symbol2id(r_ob, (t_symbol *)get_activeitem_slot_firstitem(r_ob, s)->item);
    
    
    t_jsurface *cards_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, total_cards_width /*cards_bounding_rectangle->width*/, cards_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);
    t_jgraphics *cards_g = jgraphics_create(cards_surface);
    
    
    for (id = 1; id < r_ob->noteheads_typo_preferences.num_noteheads; id++) {
        long this_row = (id - 1) % num_cards_per_row;
        long this_col = (id - 1) / num_cards_per_row;
        double cur_x = this_row * card_width;
        double cur_y = this_col * card_height;
        char selected = (id == selected_id);
        t_notehead_preferences *nhpref = &r_ob->noteheads_typo_preferences.nhpref[id];
        double fontsize = nhpref->base_pt * zoom_y * 0.75;
        t_symbol *font = nhpref->font;
        t_jfont *jf_nh = jfont_create_debug(font ? font->s_name : r_ob->noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, fontsize);
        
        paint_rectangle(cards_g, build_jrgba(1, 1, 1, 1), selected ? change_alpha(slot_color, 0.5) : build_jrgba(0.9, 0.9, 0.9, 0.5), cur_x, cur_y, card_width, card_height, 1);

        if (r_ob->obj_type != k_NOTATION_OBJECT_SCORE || (nhpref->unicode_character_black == nhpref->unicode_character_white && nhpref->unicode_character_black == nhpref->unicode_character_whole && nhpref->unicode_character_black == nhpref->unicode_character_doublewhole)) {
            // all glyphs are the same
            char *buf = notehead_to_text_buf(r_ob, id, RAT_1OVER4);
            write_text(cards_g, jf_nh, label_color, buf, cur_x, cur_y - 0.25 * card_height, card_width, card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            bach_freeptr(buf);
        } else if (nhpref->unicode_character_white && nhpref->unicode_character_whole && nhpref->unicode_character_white == nhpref->unicode_character_doublewhole) {
            char *bufblack = notehead_to_text_buf(r_ob, id, RAT_1OVER4);
            char *bufwhite = notehead_to_text_buf(r_ob, id, RAT_1OVER2);
            write_text(cards_g, jf_nh, label_color, bufblack, cur_x, cur_y - 0.25 * card_height, card_width/2., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufwhite, cur_x+card_width/2., cur_y - 0.25 * card_height, card_width/2., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            bach_freeptr(bufblack);
            bach_freeptr(bufwhite);
        } else if (nhpref->unicode_character_whole == nhpref->unicode_character_doublewhole) {
            char *bufblack = notehead_to_text_buf(r_ob, id, RAT_1OVER4);
            char *bufwhite = notehead_to_text_buf(r_ob, id, RAT_1OVER2);
            char *bufwhole = notehead_to_text_buf(r_ob, id, long2rat(1));
            write_text(cards_g, jf_nh, label_color, bufblack, cur_x, cur_y - 0.25 * card_height, card_width/3., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufwhite, cur_x+card_width/3., cur_y - 0.25 * card_height, card_width/3., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufwhole, cur_x+2*card_width/3., cur_y - 0.25 * card_height, card_width/3., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            bach_freeptr(bufblack);
            bach_freeptr(bufwhite);
            bach_freeptr(bufwhole);
        } else {
            // essentially all glyphs differ
            char *bufblack = notehead_to_text_buf(r_ob, id, RAT_1OVER4);
            char *bufwhite = notehead_to_text_buf(r_ob, id, RAT_1OVER2);
            char *bufwhole = notehead_to_text_buf(r_ob, id, long2rat(1));
            char *bufdoublewhole = notehead_to_text_buf(r_ob, id, long2rat(2));
            write_text(cards_g, jf_nh, label_color, bufblack, cur_x, cur_y - 0.25 * card_height, card_width/4., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufwhite, cur_x+card_width/4., cur_y - 0.25 * card_height, card_width/4., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufwhole, cur_x+2*card_width/4., cur_y - 0.25 * card_height, card_width/4., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            write_text(cards_g, jf_nh, label_color, bufdoublewhole, cur_x+3*card_width/4., cur_y - 0.25 * card_height, card_width/4., card_height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
            bach_freeptr(bufblack);
            bach_freeptr(bufwhite);
            bach_freeptr(bufwhole);
            bach_freeptr(bufdoublewhole);
        }
        
        jfont_destroy_debug(jf_nh);
    }
    
    t_rect sourceRect = build_rect(displayed_bounding_rectangle->x - cards_bounding_rectangle->x, displayed_bounding_rectangle->y - cards_bounding_rectangle->y, displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);
    t_rect destRect = build_rect(displayed_bounding_rectangle->x, displayed_bounding_rectangle->y - cards_surface_top_pad,
                                 displayed_bounding_rectangle->width, displayed_bounding_rectangle->height + cards_surface_top_pad + cards_surface_bottom_pad);

    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
    jgraphics_image_surface_draw(g, cards_surface, sourceRect, destRect);
    jgraphics_surface_destroy(cards_surface);
    jgraphics_destroy(cards_g);
}

char does_active_slot_need_legend(t_notation_obj *r_ob, long active_slot_number, long active_slot_type)
{
	switch (active_slot_type) {
		case k_SLOT_TYPE_FUNCTION:
			if ((r_ob->j_mousedown_obj_type == k_SLOT_FUNCTION_POINT && r_ob->j_mousedown_ptr) || 
				(r_ob->mouse_hover && is_pt_in_inner_slot_subwindow(r_ob, build_pt(r_ob->j_mouse_x, r_ob->j_mouse_y))))
				return true;
		case k_SLOT_TYPE_3DFUNCTION:
			if ((r_ob->j_mousedown_obj_type == k_SLOT_3DFUNCTION_POINT && r_ob->j_mousedown_ptr) || 
				(r_ob->mouse_hover && is_pt_in_inner_slot_subwindow(r_ob, build_pt(r_ob->j_mouse_x, r_ob->j_mouse_y))) || r_ob->hovered_slotitem)
				return true;
			break;
		case k_SLOT_TYPE_SPAT:
			if (r_ob->j_mousedown_obj_type == k_SLOT_SPAT_POINT && r_ob->j_mousedown_ptr)
				return true;
			break;
		case k_SLOT_TYPE_FILTER:
		{
			t_biquad *biquad = (get_activeitem_slot_firstitem(r_ob, active_slot_number) ? (t_biquad *)get_activeitem_slot_firstitem(r_ob, active_slot_number)->item : NULL);
			if (biquad && biquad->filter_type != k_FILTER_DISPLAY && biquad->filter_type != k_FILTER_NONE)			
				return true;
		}
			break;
		case k_SLOT_TYPE_DYNFILTER:
			if (r_ob->j_mousedown_obj_type == k_SLOT_DYNFILTER_BIQUAD)
				return true;
			break;
        case k_SLOT_TYPE_ARTICULATIONS:
        case k_SLOT_TYPE_NOTEHEAD:
            if (r_ob->mouse_hover && is_pt_in_inner_slot_subwindow(r_ob, build_pt(r_ob->j_mouse_x, r_ob->j_mouse_y)))
                return true;
            break;
	}
	return false;
}


long get_maxdecimals_from_min_max_num(double min, double max)
{
    double delta = max - min;
    if (delta < 0.001)
        return 6;
    if (delta < 0.01)
        return 5;
    if (delta < 0.1)
        return 4;
    if (delta < 1)
        return 3;
    if (delta < 10)
        return 2;
    if (delta < 100)
        return 1;
    return 0;
}

void get_slot_grid_params(t_notation_obj *r_ob, long slot_number, double *grid_domain, double *grid_range, t_symbol **grid_domain_label, t_symbol **grid_range_label, long *grid_domain_size, long *grid_range_size, long array_len)
{
    t_llll *ll = r_ob->slotinfo[slot_number].grid;
    char force_labels = false;
    
    *grid_domain_size = 0;
    *grid_range_size = 0;

    if (!ll)
        return;

    if (is_symbol_in_llll_first_level(ll, _sym_labels))
        force_labels = true;

    if (ll->l_head) {
        long md = get_maxdecimals_from_min_max_num(r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1]);
        switch (hatom_gettype(&ll->l_head->l_hatom)) {
            case H_LLLL:
                for (t_llllelem *elem = hatom_getllll(&ll->l_head->l_hatom)->l_head; elem && *grid_domain_size < array_len; elem = elem->l_next) {
                    if (is_hatom_number(&elem->l_hatom)) {
                        grid_domain[*grid_domain_size] = hatom_getdouble(&elem->l_hatom);
                        grid_domain_label[*grid_domain_size] = force_labels ? double_to_symbol_fixed(grid_domain[*grid_domain_size], md) : NULL;
                        (*grid_domain_size)++;
                    } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                        t_llll *subll = hatom_getllll(&elem->l_hatom);
                        if (subll->l_head && is_hatom_number(&subll->l_head->l_hatom)) {
                            grid_domain[*grid_domain_size] = hatom_getdouble(&subll->l_head->l_hatom);
                            grid_domain_label[*grid_domain_size] = subll->l_head->l_next ? hatom_to_symbol(&subll->l_head->l_next->l_hatom) : NULL;
                            (*grid_domain_size)++;
                        }
                    }
                }
                break;
                
            case H_LONG:
            {
                long l = MIN(hatom_getlong(&ll->l_head->l_hatom), array_len);
                if (l > 1) {
                    double min = r_ob->slotinfo[slot_number].slot_domain[0];
                    double max = r_ob->slotinfo[slot_number].slot_domain[1];
                    for (long i = 0; i < l && *grid_domain_size < array_len; i++) {
                        grid_domain[*grid_domain_size] = min + i * (max - min) / (l - 1);
                        grid_domain_label[*grid_domain_size] =  force_labels ? double_to_symbol_fixed(grid_domain[*grid_domain_size], md) : NULL;
                        (*grid_domain_size)++;
                    }
                }
            }
                break;
                
            default:
                break;
        }
    }

    if (ll->l_head && ll->l_head->l_next) {
        long md = get_maxdecimals_from_min_max_num(r_ob->slotinfo[slot_number].slot_range[0], r_ob->slotinfo[slot_number].slot_range[1]);
        switch (hatom_gettype(&ll->l_head->l_next->l_hatom)) {
            case H_LLLL:
                for (t_llllelem *elem = hatom_getllll(&ll->l_head->l_next->l_hatom)->l_head; elem && *grid_domain_size < array_len; elem = elem->l_next) {
                    if (is_hatom_number(&elem->l_hatom)) {
                        grid_range[*grid_range_size] = hatom_getdouble(&elem->l_hatom);
                        grid_range_label[*grid_range_size] =  force_labels ? double_to_symbol_fixed(grid_range[*grid_range_size], md) : NULL;
                        (*grid_range_size)++;
                    } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                        t_llll *subll = hatom_getllll(&elem->l_hatom);
                        if (subll->l_head && is_hatom_number(&subll->l_head->l_hatom)) {
                            grid_range[*grid_range_size] = hatom_getdouble(&subll->l_head->l_hatom);
                            grid_range_label[*grid_range_size] = subll->l_head->l_next ? hatom_to_symbol(&subll->l_head->l_next->l_hatom) : NULL;
                            (*grid_range_size)++;
                        }
                    }
                }
                break;
                
            case H_LONG:
            {
                long l = MIN(hatom_getlong(&ll->l_head->l_next->l_hatom), array_len);
                if (l > 1) {
                    double min = r_ob->slotinfo[slot_number].slot_range[0];
                    double max = r_ob->slotinfo[slot_number].slot_range[1];
                    for (long i = 0; i < l && *grid_range_size < array_len; i++) {
                        grid_range[*grid_range_size] = min + i * (max - min) / (l - 1);
                        grid_range_label[*grid_range_size] =  force_labels ? double_to_symbol_fixed(grid_range[*grid_range_size], md) : NULL;
                        (*grid_range_size)++;
                    }
                }
            }
                break;
                
            default:
                break;
        }
    }
}


void function_slot_has_labels(t_notation_obj *r_ob, long slot_number, char *has_x_labels, char *has_y_labels)
{
    t_llll *grid = r_ob->slotinfo[slot_number].grid;

    *has_x_labels = *has_y_labels = false;

    if (r_ob->slotinfo[slot_number].slot_type != k_SLOT_TYPE_FUNCTION)
        return;
    
    if (grid && is_symbol_in_llll_first_level(grid, _sym_labels)) {
        *has_x_labels = *has_y_labels = true;
        return;
    }
    
    if (!grid || grid->l_depth <= 2)
        return;
    
    if (grid->l_head && hatom_gettype(&grid->l_head->l_hatom) == H_LLLL && hatom_getllll(&grid->l_head->l_hatom)->l_depth > 1)
        *has_x_labels = true;

    if (grid->l_head && grid->l_head->l_next && hatom_gettype(&grid->l_head->l_next->l_hatom) == H_LLLL && hatom_getllll(&grid->l_head->l_next->l_hatom)->l_depth > 1)
        *has_y_labels = true;
}

double function_slot_get_max_label_width(t_notation_obj *r_ob, long slot_number, t_jfont *jf)
{
    return 20 * r_ob->zoom_y; // fixed for now
}

void paint_slot(t_notation_obj *r_ob, t_jgraphics* g, t_rect graphic_rect, t_notation_item *item, long slot_number)
{
// you have to set r_ob->slot_window_x1 and r_ob->slot_window_x2 "manually" *before* entering this function 
 	t_jrgba lightoff_color, slot_color, slot_bordercolor, slot_bordercolor2, slot_backgroundcolor, slot_backgroundcolor_orig, slot_textcolor = CONST_SLOT_TEXTCOLOR;
	t_jrgba slot_namecolor = CONST_SLOT_NAME_COLOR_CLEAR, slot_numbers_linecolor = CONST_SLOT_TEXTCOLOR, slot_text_textcolor = CONST_SLOT_TEXT_TEXTCOLOR;
	double slot_window_active_x1, slot_window_active_x2, slot_window_active_y1, slot_window_active_y2, slot_window_active_width, slot_window_active_height;
	t_jfont *jf_slot_name, *jf_slot_values, *jf_slot_text, *jf_slot_file, *jf_slot_file_bold, *jf_slot_file_italic, *jf_slot_smallvalues, *jf_slot_function_point_labels, *jf_slot_dynamics, *jf_slot_dynamics_roman, *jf_slot_function_grid_labels = NULL;
	int s = slot_number, slot_window_height, y_file_step, y_numberlist_step;
	double slotname_right_limit = 0;
	double left_pos, usable_width;
    char has_y_labels = false, has_x_labels = false;
	char link_to_label[100];
	t_pt mouse; 
	long slot_type = r_ob->slotinfo[s].slot_type;
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom/100.);
	
	char slot_needs_legend = false;
	char legend[CONST_SLOT_MAX_LEGEND_CHARS];
	legend[0] = 0;
    
    function_slot_has_labels(r_ob, slot_number, &has_x_labels, &has_y_labels);
	
    // slot fonts
    jf_slot_name = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(7.0 * zoom_y));
    jf_slot_values = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(8.0 * zoom_y));
    jf_slot_smallvalues = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(5.5 * zoom_y));
    jf_slot_text = jfont_create_debug("Courier", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(7.2 * zoom_y));
    jf_slot_file = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(7.0 * zoom_y));
    jf_slot_file_bold = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(7.0 * zoom_y));
    jf_slot_file_italic = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, round(7.0 * zoom_y));
    jf_slot_function_point_labels = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(5 * zoom_y));
    jf_slot_dynamics = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(18 * zoom_y));
    jf_slot_dynamics_roman = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, round(9 * zoom_y));
    if (has_x_labels || has_y_labels)
        jf_slot_function_grid_labels = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(5 * zoom_y));
    
    
	mouse.x = r_ob->j_mouse_x; 
	mouse.y = r_ob->j_mouse_y;
	
	// correcting slot window x
	if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT && (!slot_is_temporal(r_ob, slot_number))) { // if the slot is NOT temporal
		double start_pix = r_ob->j_inset_x + CONST_ROLL_UX_LEFT_START * zoom_y;
		
		if (r_ob->slot_window_x2 - r_ob->slot_window_x1 <= r_ob->slot_minimum_window_uwidth * zoom_y) {
			r_ob->slot_window_x2 = r_ob->slot_window_x1 + r_ob->slot_minimum_window_uwidth * zoom_y;
		}
		
		if (r_ob->slot_window_x1 < start_pix) {
			double diff = r_ob->slot_window_x2 - r_ob->slot_window_x1;
			r_ob->slot_window_x1 = start_pix;
			r_ob->slot_window_x2 = start_pix + diff;
		}

		if (r_ob->slot_window_x2 > graphic_rect.width - r_ob->j_inset_x) {
			if (r_ob->slot_window_x1 - (r_ob->slot_window_x2 - (graphic_rect.width - r_ob->j_inset_x)) > start_pix){
				r_ob->slot_window_x1 -= (r_ob->slot_window_x2 - (graphic_rect.width - r_ob->j_inset_x));
				r_ob->slot_window_x2 = graphic_rect.width - r_ob->j_inset_x;
			}
		}
	}
	
	// determine the active slot window x
	if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT) {
		r_ob->slot_window_x1 -= CONST_SLOT_WINDOW_INSET_X;
		r_ob->slot_window_x2 += CONST_SLOT_WINDOW_INSET_X;
	}

	slot_window_active_x1 = r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X;
	slot_window_active_x2 = r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X;
    
    if (has_y_labels) {
        double new_slot_window_active_x1 = slot_window_active_x1 + function_slot_get_max_label_width(r_ob, slot_number, jf_slot_function_grid_labels);
        if (new_slot_window_active_x1 < slot_window_active_x2)
            slot_window_active_x1 = new_slot_window_active_x1;
        else
            has_y_labels = false;
    }
    
	slot_window_active_width = slot_window_active_x2 - slot_window_active_x1;
	
	// slot colors
	slot_color = r_ob->slotinfo[r_ob->active_slot_num].slot_color; 
	
	slot_backgroundcolor = slot_backgroundcolor_orig = get_grey(1);
	slot_bordercolor = slot_bordercolor2 = slot_color;
	slot_backgroundcolor.alpha = r_ob->slot_background_alpha_percentage/100.;
	
	//	slot_window_height;
	y_file_step = CONST_SLOT_FILE_UY_STEP * zoom_y;
	y_numberlist_step = CONST_SLOT_NUMBERLIST_UY_STEP * zoom_y;
	
	if (r_ob->slotinfo[s].slot_active_uheight >= 0) {
		slot_window_height = r_ob->slotinfo[s].slot_active_uheight + get_slot_window_top_inset_uheight(r_ob, s) + get_slot_window_bottom_inset_uheight(r_ob, s);
	} else {	// automatic slot height
		slot_window_height = get_default_slot_window_uheight(r_ob, s, item, false);
	}

	// "turn off" the light
	if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT) {
		lightoff_color = build_jrgba(0.8, 0.8, 0.8, 0.7);
		paint_rectangle(g, lightoff_color, lightoff_color, 0., 0., graphic_rect.width, graphic_rect.height, 1.);
	}
	
	// determine the slot window y
	if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
		r_ob->slot_window_y1 = 1;
		r_ob->slot_window_y2 = graphic_rect.height - 1;
	} else {
        r_ob->slot_window_y1 = r_ob->system_jump * onset_to_system_index(r_ob, notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem)) + notation_item_get_center_y(r_ob, r_ob->active_slot_notationitem);
		r_ob->slot_window_y2 = r_ob->slot_window_y1 - slot_window_height * zoom_y;
		// for notes too high, we reverse the direction of the slot window
		if (r_ob->slot_window_y2 < 7 * zoom_y) r_ob->slot_window_y2 = r_ob->slot_window_y1 + slot_window_height * zoom_y;
		// if reversing is worse, we do our best to fit the slot within in the window
		if (r_ob->slot_window_y2 > graphic_rect.height - 7 * zoom_y) {
			r_ob->slot_window_y2 = 7 * zoom_y;
			r_ob->slot_window_y1 = r_ob->slot_window_y2 + slot_window_height * zoom_y;
		}
		// re-sorting y1 and y2
		if (r_ob->slot_window_y1 > r_ob->slot_window_y2) {
			double temp = r_ob->slot_window_y1;
			r_ob->slot_window_y1 = r_ob->slot_window_y2;
			r_ob->slot_window_y2 = temp;
		}
	}

	slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_WINDOW_INSET_Y;
	slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;

	// changing active window depending on slot type
	switch (slot_type) {
		case k_SLOT_TYPE_COLOR:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_COLOR_UY_INSET_TOP * zoom_y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_COLOR_UY_INSET_BOTTOM * zoom_y - 10 * zoom_y;
			break;
		case k_SLOT_TYPE_FILTER:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_FUNCTION_UY_INSET_TOP * zoom_y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_FUNCTION_UY_INSET_BOTTOM * zoom_y;
			break;
		case k_SLOT_TYPE_FUNCTION:
		case k_SLOT_TYPE_3DFUNCTION:
		case k_SLOT_TYPE_SPAT:
		case k_SLOT_TYPE_DYNFILTER:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_FUNCTION_UY_INSET_TOP * zoom_y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_FUNCTION_UY_INSET_BOTTOM * zoom_y;
			break;
		case k_SLOT_TYPE_INT:
		case k_SLOT_TYPE_FLOAT:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_NUMBER_UY_START * zoom_y + CONST_SLOT_WINDOW_INSET_Y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;
			break;
		case k_SLOT_TYPE_INTLIST:
		case k_SLOT_TYPE_FLOATLIST:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_NUMBERLIST_UY_START * zoom_y + CONST_SLOT_WINDOW_INSET_Y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;
			break;
		case k_SLOT_TYPE_TOGGLEMATRIX:
		case k_SLOT_TYPE_INTMATRIX:
		case k_SLOT_TYPE_FLOATMATRIX:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_NUMBERMATRIX_UY_START * zoom_y + CONST_SLOT_WINDOW_INSET_Y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;
			break;
		case k_SLOT_TYPE_FILELIST:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_FILE_UY_START * zoom_y + CONST_SLOT_WINDOW_INSET_Y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;
			break;
		case k_SLOT_TYPE_TEXT:
		case k_SLOT_TYPE_LLLL:
        case k_SLOT_TYPE_ARTICULATIONS:
        case k_SLOT_TYPE_NOTEHEAD:
        case k_SLOT_TYPE_DYNAMICS:
			slot_window_active_y1 = r_ob->slot_window_y1 + CONST_SLOT_TEXT_UY_START * zoom_y;
			slot_window_active_y2 = r_ob->slot_window_y2 - CONST_SLOT_WINDOW_INSET_Y;
			break;
		default:
			break;
	}
    
    if (has_x_labels) {
        double new_slot_window_active_y2 = slot_window_active_y2 - 5 * zoom_y;
        if (new_slot_window_active_y2 > slot_window_active_y1)
            slot_window_active_y2 = new_slot_window_active_y2;
        else
            has_x_labels = false;
    }
    
	
	slot_window_active_height = slot_window_active_y2 - slot_window_active_y1;
	
	left_pos = r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X;

	slot_needs_legend = does_active_slot_need_legend(r_ob, s, slot_type);
	
	// "turn on" the light on the slot window related to the note
	if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT) 
		paint_rectangle(g, slot_color, change_alpha(get_grey(1.), r_ob->slot_background_alpha_percentage / 100.), r_ob->slot_window_x1, r_ob->slot_window_y1, r_ob->slot_window_x2 - r_ob->slot_window_x1, r_ob->slot_window_y2 - r_ob->slot_window_y1, 1.);

	// write the slot number
	if (r_ob->show_slot_numbers && (!slot_needs_legend || !r_ob->show_slot_legend)){
		t_jfont *jf_slot_number = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, 18. * zoom_y);
		char slotnum_as_txt[10];
		snprintf_zero(slotnum_as_txt, 9, "%d", s+1);
		write_text(g, jf_slot_number, build_jrgba(0.75, 0.75, 0.75, 0.35), slotnum_as_txt, r_ob->slot_window_x1, r_ob->j_inset_y + r_ob->slot_window_y1, 
				   r_ob->slot_window_x2 - r_ob->slot_window_x1 - CONST_SLOT_WINDOW_INSET_X, slot_window_active_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
		jfont_destroy_debug(jf_slot_number);
	}
	
    
    if (slot_type == k_SLOT_TYPE_ARTICULATIONS || slot_type == k_SLOT_TYPE_NOTEHEAD) {
        r_ob->slot_window_active_unscrolled_width = MAX(slot_window_active_width, get_slot_cards_num_cols(r_ob, s) * get_slot_cards_single_card_width(r_ob, s));
    } else
        r_ob->slot_window_active_unscrolled_width = slot_window_active_width;
    
    
	r_ob->slot_window_active_nozoom = build_rect(slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height);

	// modifying activeslotwin w.r. to zoom
	if (((!slot_is_temporal(r_ob, s)) || r_ob->obj_type == k_NOTATION_OBJECT_SLOT) && (can_slot_be_hzoomed(r_ob, s) || can_slot_be_hmoved(r_ob, s))) {
		slot_window_active_width *= r_ob->slot_window_hzoom_factor;
		slot_window_active_x1 = slot_window_active_x1 - r_ob->slot_window_zoomed_start * slot_window_active_width;
		slot_window_active_x2 = slot_window_active_x1 + slot_window_active_width;
	}
	
	r_ob->slot_window_active_x1 = slot_window_active_x1;
	r_ob->slot_window_active_x2 = slot_window_active_x2;
	r_ob->slot_window_active_y1 = slot_window_active_y1;
	r_ob->slot_window_active_y2 = slot_window_active_y2;
	r_ob->slot_window_active = build_rect(slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height);
	r_ob->slot_window = build_rect(r_ob->slot_window_x1, r_ob->slot_window_y1, r_ob->slot_window_x2 - r_ob->slot_window_x1, r_ob->slot_window_y2 - r_ob->slot_window_y1);	
	
	switch (slot_type) {
		case k_SLOT_TYPE_FUNCTION:
			paint_function_in_slot_win(r_ob, g, r_ob->slot_window_active, r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, 1., true, false, false, true, r_ob->slot_window_zoom, true, r_ob->show_slot_labels, jf_slot_function_point_labels, r_ob->allow_horizontal_slot_zooming);

            // grid?
            if (r_ob->slotinfo[s].grid) {
                t_pt temp_pt;
                double grid_domain[2048];
                double grid_range[2048];
                t_symbol *grid_domain_label[2048];
                t_symbol *grid_range_label[2048];
                long num_grid_domain = 0, num_grid_range = 0;
                t_jrgba grid_color = build_jrgba(0., 0., 0., 0.2);
                t_jrgba grid_text_color = CONST_SLOT_NAME_COLOR_CLEAR;
                
                get_slot_grid_params(r_ob, s, grid_domain, grid_range, grid_domain_label, grid_range_label, &num_grid_domain, &num_grid_range, 2048);
                
                for (long i = 0; i < num_grid_domain; i++) {
                    function_xy_values_to_pt(r_ob, item, grid_domain[i], slot_window_active_y1, s, r_ob->slot_window_active, &temp_pt);
                    paint_line(g, grid_color, temp_pt.x, slot_window_active_y1, temp_pt.x, slot_window_active_y2, 1);
                    if (has_x_labels && grid_domain_label[i])
                        write_text(g, jf_slot_function_grid_labels, grid_text_color, grid_domain_label[i]->s_name, i == 0 ? temp_pt.x : temp_pt.x - 300, slot_window_active_y2 + 0.5 * zoom_y, i == num_grid_domain - 1 ? 300 : 600, 200,
                                   JGRAPHICS_TEXT_JUSTIFICATION_TOP + (i == 0 ? JGRAPHICS_TEXT_JUSTIFICATION_LEFT : (i == num_grid_domain - 1 ? JGRAPHICS_TEXT_JUSTIFICATION_RIGHT : JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED)), true, false);
                }

                for (long i = 0; i < num_grid_range; i++) {
                    function_xy_values_to_pt(r_ob, item, slot_window_active_x1, grid_range[i], s, r_ob->slot_window_active, &temp_pt);
                    paint_line(g, grid_color, slot_window_active_x1, temp_pt.y, slot_window_active_x2, temp_pt.y, 1);
                    if (has_y_labels && grid_range_label[i])
                        write_text(g, jf_slot_function_grid_labels, grid_text_color, grid_range_label[i]->s_name, slot_window_active_x1 - 500, temp_pt.y - 300, 500 - 0.5 * zoom_y, 600, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT | JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, false);
                }
            }
			
			// are we clicking or hovering on a point?
			if (slot_needs_legend) {
				// display value
				double x_val, y_val;
				double slope = 0;
				char domain_unit[30], unit[30]; 
				
				// retrieve x and y
				if (r_ob->j_mousedown_obj_type == k_SLOT_FUNCTION_POINT && r_ob->j_mousedown_ptr){
					x_val = ((t_pts *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->x;
					y_val = ((t_pts *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->y;
				} else if (r_ob->hovered_slotitem && !r_ob->hovering_segment){
					x_val = ((t_pts *) (r_ob->hovered_slotitem->item))->x;
					y_val = ((t_pts *) (r_ob->hovered_slotitem->item))->y;
				} else {
					pt_to_function_xy_values(r_ob, item, mouse, s, r_ob->slot_window_active, &x_val, &y_val);
				}
				
				if (r_ob->j_mousedown_obj_type == k_SLOT_FUNCTION_SEGMENT && r_ob->j_mousedown_ptr) {
					t_slotitem *item = (t_slotitem *) r_ob->j_mousedown_ptr;
					slope = ((t_pts *)item->item)->slope;
				}
				
				// retrieve display unit (or enum)
				unit[0] = 0;
				domain_unit[0] = 0;
				if (r_ob->slotinfo[s].slot_repr && r_ob->slotinfo[s].slot_repr->l_size > 0) {
					if (r_ob->slotinfo[s].slot_repr->l_head->l_next) {
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)
							strncpy_zero(domain_unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_hatom) == H_SYM)
							strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_hatom)->s_name, 30);
					} else {
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)
							strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
					}
				}

                if (r_ob->slotinfo[s].slot_temporalmode == k_SLOT_TEMPORALMODE_MILLISECONDS)
                    snprintf_zero(domain_unit, 30, "ms");
                    
				if (slope == 0)
                    snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "(%.2f%s %.2f%s)", x_val, domain_unit, y_val, unit);
				else
					snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "(%.2f%s %.2f%s C%.2f)", x_val, domain_unit, y_val, unit, slope);

			}
			break;
			
		case k_SLOT_TYPE_3DFUNCTION:
			paint_3dfunction_in_slot_win(r_ob, g, r_ob->slot_window_active, r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, 1., true, false, false, true, r_ob->slot_window_zoom, true, r_ob->slot_window_hzoom_factor > 1.);

			// are we clicking on a point?
			if (slot_needs_legend) {
				// display value
				double x_val, y_val, z_val = 0;
				char over_point = false;
				char domain_unit[30], unit[30], zunit[30]; 
				
				// retrieve x and y
				if (r_ob->j_mousedown_obj_type == k_SLOT_3DFUNCTION_POINT && r_ob->j_mousedown_ptr){
					x_val = ((t_pts3d *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->x;
					y_val = ((t_pts3d *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->y;
					z_val = ((t_pts3d *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->z;
					over_point = true;
				} else if (r_ob->hovered_slotitem){
					x_val = ((t_pts3d *) (r_ob->hovered_slotitem->item))->x;
					y_val = ((t_pts3d *) (r_ob->hovered_slotitem->item))->y;
					z_val = ((t_pts3d *) (r_ob->hovered_slotitem->item))->z;
					over_point = true;
				} else {
					// we just need the x y values (this would not be univoque with the z value as well)
					pt_to_function_xy_values(r_ob, item, mouse, s, r_ob->slot_window_active, &x_val, &y_val);
					z_val = 0;
				}
				
				// retrieve display unit (or enum)
				unit[0] = 0;
				domain_unit[0] = 0;
				zunit[0] = 0;
				if (r_ob->slotinfo[s].slot_repr && (r_ob->slotinfo[s].slot_repr->l_size > 0)) {
					if (r_ob->slotinfo[s].slot_repr->l_head->l_next) {
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)	
							strncpy_zero(domain_unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_hatom) == H_SYM)
							strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_hatom)->s_name, 30);
						if (r_ob->slotinfo[s].slot_repr->l_head->l_next->l_next && (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_next->l_hatom) == H_SYM))
							strncpy_zero(zunit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_next->l_next->l_hatom)->s_name, 30);
					} else {
						if (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)	
							strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
					}
				}
				if (over_point)
					snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "(%.2f%s %.2f%s %.2f%s)", x_val, domain_unit, y_val, unit, z_val, zunit); // snprintf_zero has issues!!!
				else
					snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "(%.2f%s %.2f%s ?)", x_val, domain_unit, y_val, unit);
				
			}
			break;
			
		case k_SLOT_TYPE_SPAT:
			paint_spatfunction_in_slot_win(r_ob, g, r_ob->slot_window_active, r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, slot_textcolor, 1., true, false, false, false, CONST_SLOT_SPAT_CIRCLE_URADIUS, r_ob->slot_window_zoom, true, r_ob->slot_window_hzoom_factor > 1.);
			
			if (slot_needs_legend) {
				// display value
				double t_val = ((t_spatpt *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->t;
				double radius_val = ((t_spatpt *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->radius;
				double angle_val = ((t_spatpt *) (((t_slotitem *)r_ob->j_mousedown_ptr)->item))->angle;

				snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "(%.2f: dist %.2f, angle %ld°)", t_val, radius_val, (long)round(rad2deg(angle_val)));
			}
			break;
			
		case k_SLOT_TYPE_INT:
		case k_SLOT_TYPE_FLOAT:
		{
			// retrieve content: we expect the content to be a long
			double slot_max = r_ob->slotinfo[s].slot_range[1], slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
			double curr_val; // let's retrieve the slot value
			double slider_width;
			double bar_y_top = slot_window_active_y1 + CONST_SLOT_INT_FLOAT_BAR_Y_POS * slot_window_active_height;
			double bar_y_height = CONST_SLOT_INT_FLOAT_BAR_Y_HEIGHT * slot_window_active_height;
			char is_enum = false, is_defined = true; 
			long how_many_enums = 0; 
			char unit[30]; 
			char value_str[50];
			
            value_str[0] = 0;
			unit[0] = '\0';
			bar_y_top = round_to_semiinteger(bar_y_top);
			bar_y_height = round(bar_y_height);
			
			if (r_ob->active_slot_notationitem && get_activeitem_slot_firstitem(r_ob, s) && get_activeitem_slot_firstitem(r_ob, s)->item) {
				if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT)
					curr_val = *((long *)get_activeitem_slot_firstitem(r_ob, s)->item); // first (and only) long item
				else
					curr_val = *((double *)get_activeitem_slot_firstitem(r_ob, s)->item); // first (and only) double item
			} else {
				curr_val = slot_min;
				is_defined = false;
				snprintf_zero(value_str, 50, "None");
			}
			curr_val = CLAMP(curr_val, slot_min, slot_max);
			
			if (is_defined) {
				// draw the bar
				slider_width = notationobj_rescale_with_slope_inv(r_ob, curr_val, slot_min, slot_max, 0, slot_window_active_width, r_ob->slotinfo[s].slot_range_par);
				paint_rectangle(g, slot_color, slot_color, r_ob->slot_window_x1, bar_y_top, slot_window_active_x1 + slider_width - r_ob->slot_window_x1, bar_y_height, 0);

				// retrieve display unit (or enum)
				if ((r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT) && r_ob->slotinfo[s].slot_repr && (r_ob->slotinfo[s].slot_repr->l_size > 0) && (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_LLLL)) {
					is_enum = true;
					how_many_enums = hatom_getllll(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->l_size;
				} else if (r_ob->slotinfo[s].slot_repr && (r_ob->slotinfo[s].slot_repr->l_size > 0) && (hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM)) {
					strncpy_zero(unit, hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom)->s_name, 30);
				}
				
                // display the value
                if (r_ob->is_editing_type != k_NUMBER_IN_SLOT) {
                    if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT) // long case
                        if (is_enum) {
                            long value =  (long)round(curr_val);
                            if (value - round(slot_min) < how_many_enums)
                                snprintf_zero(value_str, 50, "%s", nth_sym_of_a_plain_sym_llll(hatom_getllll(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom), value - round(slot_min) + 1)->s_name);
                            else
                                snprintf_zero(value_str, 50, "%ld", (long)round(curr_val));
                        } else
                            snprintf_zero(value_str, 50, "%ld%s", (long)round(curr_val), unit);
                        else // float case
                            snprintf_zero(value_str, 50, "%.3f%s", curr_val, unit);
                }
			} else {
				t_jrgba greyed = build_jrgba(0, 0, 0, 0.02);
				paint_rectangle(g, greyed, greyed, r_ob->slot_window_x1, bar_y_top, r_ob->slot_window.width, bar_y_height, 0);
			}
			
			write_text(g, jf_slot_values, slot_textcolor, value_str, 
					   slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height, 
					   JGRAPHICS_TEXT_JUSTIFICATION_BOTTOMRIGHT, true, false);
			break;
		}

		case k_SLOT_TYPE_INTLIST:
		case k_SLOT_TYPE_FLOATLIST:
		{
			paint_numberlist_bars_in_noteslot(r_ob, g, &r_ob->slot_window_active, &r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, true,
											  r_ob->slot_window_zoom, r_ob->show_slot_labels, jf_slot_smallvalues, slot_textcolor);
			break;
		}
			
		case k_SLOT_TYPE_INTMATRIX:
		case k_SLOT_TYPE_FLOATMATRIX:
		case k_SLOT_TYPE_TOGGLEMATRIX:
		{
			double slot_max = r_ob->slotinfo[s].slot_range[1]; double slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
			
			//long num_numbers = r_ob->active_slot_note->slot[s].length;
			t_slotitem *firstitem = get_activeitem_slot_firstitem(r_ob, s);
			long i = 0, j, row = 0, col = 0;
			char is_enum_rows = false, is_enum_cols = false; 
			char unit[30]; 
			double bar_width;
			char value_str[50];
			double h_cell_size, v_cell_size, slot_window_table_x1 = slot_window_active_x1, slot_window_table_y1 = slot_window_active_y1;
			double enum_pad_y = CONST_SLOT_NUMBERMATRIX_UY_PAD * zoom_y;
			double enum_pad_x = CONST_SLOT_NUMBERMATRIX_UX_PAD * zoom_y;
			t_llll *tab, *enum_rows = NULL, *enum_cols = NULL;
			t_llllelem *row_elem, *col_elem, *elem;
			t_jrgba bars_color = build_jrgba(0.8, 0.8, 0.8, 0.7);
			unit[0] = '\0';
			
			if (r_ob->slotinfo[s].slot_repr && r_ob->slotinfo[s].slot_repr->l_size > 0 && hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_LLLL) {
				t_llll *enumllll = hatom_getllll(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom);
				if (enumllll && enumllll->l_head && enumllll->l_tail) {
					if (hatom_gettype(&enumllll->l_head->l_hatom) == H_LLLL) {
						is_enum_rows = true;
						enum_rows = hatom_getllll(&enumllll->l_head->l_hatom);
						slot_window_table_x1 += enum_pad_x;
					}
					if (hatom_gettype(&enumllll->l_tail->l_hatom) == H_LLLL) {
						is_enum_cols = true;
						enum_cols = hatom_getllll(&enumllll->l_tail->l_hatom);
						slot_window_table_y1 += enum_pad_y;
					}
				}
			}
			
			if (!is_enum_cols) slot_window_table_y1 += 2 * zoom_y;
			
			r_ob->slot_window_table_x1 = slot_window_table_x1;
			r_ob->slot_window_table_y1 = slot_window_table_y1;
			
			h_cell_size = (slot_window_active_x2 - slot_window_table_x1) / r_ob->slotinfo[s].slot_num_cols;
			v_cell_size = (slot_window_active_y2 - slot_window_table_y1) / r_ob->slotinfo[s].slot_num_rows;
			
			if (h_cell_size > 0 && v_cell_size > 0) {
				if (is_enum_rows) {
					double max_width = 0;
					double width = 0, height = 0;
					double pad = 2 * zoom_y;
					i = 0;
					for (elem = enum_rows->l_head; elem; elem = elem->l_next) {
						char text[50]; 
						text[0] = 0;
						if (hatom_gettype(&elem->l_hatom) == H_SYM)
							snprintf_zero(text, 50, "%s", hatom_getsym(&elem->l_hatom)->s_name);
						else if (hatom_gettype(&elem->l_hatom) == H_LONG)
							snprintf_zero(text, 50, "%ld", hatom_getlong(&elem->l_hatom));
						else if (hatom_gettype(&elem->l_hatom) == H_DOUBLE)
							snprintf_zero(text, 50, "%.2f", hatom_getdouble(&elem->l_hatom));
						
						jfont_text_measure(jf_slot_smallvalues, text, &width, &height);
						if (width > max_width) max_width = width;
					}
					
					r_ob->slot_window_table_x1 = slot_window_table_x1 = slot_window_active_x1 + max_width + pad;
					h_cell_size = (slot_window_active_x2 - slot_window_table_x1) / r_ob->slotinfo[s].slot_num_cols;
					
					for (elem = enum_rows->l_head; elem; elem = elem->l_next) {
						char text[50]; 
						text[0] = 0; 
						if (hatom_gettype(&elem->l_hatom) == H_SYM)
							snprintf_zero(text, 50, "%s", hatom_getsym(&elem->l_hatom)->s_name);
						else if (hatom_gettype(&elem->l_hatom) == H_LONG)
							snprintf_zero(text, 50, "%ld", hatom_getlong(&elem->l_hatom));
						else if (hatom_gettype(&elem->l_hatom) == H_DOUBLE)
							snprintf_zero(text, 50, "%.2f", hatom_getdouble(&elem->l_hatom));
						
						write_text(g, jf_slot_smallvalues, slot_textcolor, text, 
								   slot_window_active_x1, slot_window_table_y1 + i * v_cell_size, 
								   slot_window_table_x1 - slot_window_active_x1 - pad, v_cell_size, 
								   JGRAPHICS_TEXT_JUSTIFICATION_RIGHT, true, false);
						i++;
					}
				}
				if (is_enum_cols) {
					i = 0;
					for (elem = enum_cols->l_head; elem; elem = elem->l_next) {
						//					t_jtextlayout *jtl; 
						char text[50]; 
						text[0] = 0;
						if (hatom_gettype(&elem->l_hatom) == H_SYM)
							snprintf_zero(text, 50, "%s", hatom_getsym(&elem->l_hatom)->s_name);
						else if (hatom_gettype(&elem->l_hatom) == H_LONG)
							snprintf_zero(text, 50, "%ld", hatom_getlong(&elem->l_hatom));
						else if (hatom_gettype(&elem->l_hatom) == H_DOUBLE)
							snprintf_zero(text, 50, "%.2f", hatom_getdouble(&elem->l_hatom));
						
						write_text(g, jf_slot_smallvalues, slot_textcolor, text, 
								   slot_window_table_x1 + i * h_cell_size, slot_window_active_y1, h_cell_size, enum_pad_y,  
								   JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
						i++;
					}
				}
				
				tab = firstitem ? (t_llll *) firstitem->item : NULL;
				row_elem = tab ? tab->l_head : NULL;
				for (row = 0; row < r_ob->slotinfo[s].slot_num_rows; row++){
					if (row_elem && hatom_gettype(&row_elem->l_hatom) == H_LLLL) {
						t_llll *row_llll = hatom_getllll(&row_elem->l_hatom);
						col_elem = row_llll ? row_llll->l_head : NULL;
					} else
						col_elem = NULL;
					for (col = 0; col < r_ob->slotinfo[s].slot_num_cols; col++){
						
						double curr_val; // let's retrieve the slot value 
						if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTMATRIX || r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_TOGGLEMATRIX)
							curr_val = col_elem ? hatom_getlong(&col_elem->l_hatom) : 0; // long item
						else
							curr_val = col_elem ? hatom_getdouble(&col_elem->l_hatom) : 0; // double item
						
						if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTMATRIX || r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FLOATMATRIX) {
							// draw the bar
							bar_width = notationobj_rescale_with_slope_inv(r_ob, curr_val, slot_min, slot_max, 0, h_cell_size, r_ob->slotinfo[s].slot_range_par);
							paint_rectangle(g, bars_color, bars_color, slot_window_table_x1 + col * h_cell_size, slot_window_table_y1 + row * v_cell_size, bar_width, v_cell_size, 1.);
							
							// display the value
							if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTMATRIX)
								snprintf_zero(value_str, 50, "%ld%s", (long)round(curr_val), unit);
							else if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FLOATMATRIX)
								snprintf_zero(value_str, 50, "%.2f%s", curr_val, unit);
							
							// do we display it at left or at right, w.r. to the bar?
							if (bar_width < h_cell_size/2.) {
								write_text_standard_singleline(g, jf_slot_smallvalues, slot_textcolor, value_str,
												  slot_window_table_x1 + col * h_cell_size + bar_width + 2, slot_window_table_y1 + row * v_cell_size, h_cell_size - bar_width - 2, v_cell_size);
							} else {
								write_text(g, jf_slot_smallvalues, slot_textcolor, value_str, 
										   slot_window_table_x1 + col * h_cell_size, slot_window_table_y1 + row * v_cell_size, bar_width - 2, v_cell_size, 
										   JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
							}
						} else {
							// make a cross, for togglematrix
							if (curr_val) {
								t_jrgba cross_color = get_grey(0.3);
								paint_line(g, cross_color, slot_window_table_x1 + col * h_cell_size + 2, slot_window_table_y1 + row * v_cell_size + 2, slot_window_table_x1 + (col + 1) * h_cell_size - 2, slot_window_table_y1 + (row + 1) * v_cell_size - 2, 1.);
								paint_line(g, cross_color, slot_window_table_x1 + (col + 1) * h_cell_size - 2, slot_window_table_y1 + row * v_cell_size + 2, slot_window_table_x1 + col * h_cell_size + 2, slot_window_table_y1 + (row + 1) * v_cell_size - 2, 1.);
							}
						}
						
						if (col_elem) col_elem = col_elem->l_next;
					}
					if (row_elem) row_elem = row_elem->l_next;
				}
				
				// display the "chessboard"-coloring
				for (i = 1; i < r_ob->slotinfo[s].slot_num_rows; i += 2)
					paint_rectangle(g, build_jrgba(0, 0, 0, 1), build_jrgba(0, 0, 0, 0.2), slot_window_table_x1, slot_window_table_y1 + v_cell_size * i, slot_window_active_x2 - slot_window_table_x1, v_cell_size, 0);
				for (j = 1; j < r_ob->slotinfo[s].slot_num_cols; j += 2)
					paint_rectangle(g, build_jrgba(0, 0, 0, 1), build_jrgba(1, 1, 1, 0.2), slot_window_table_x1 + h_cell_size * j, slot_window_table_y1, h_cell_size, v_cell_size * r_ob->slotinfo[s].slot_num_rows, 0);
				
				// display the grid
				for (i = 0; i < r_ob->slotinfo[s].slot_num_rows; i++) 
					paint_line(g, slot_numbers_linecolor, slot_window_table_x1, slot_window_table_y1 + v_cell_size * (i + 1), slot_window_active_x2, slot_window_table_y1 + v_cell_size * (i + 1), 1.);
				for (j = 0; j < r_ob->slotinfo[s].slot_num_cols; j++)
					paint_line(g, slot_numbers_linecolor, slot_window_table_x1 + h_cell_size * (j + 1), slot_window_table_y1, slot_window_table_x1 + h_cell_size * (j + 1), slot_window_table_y1 + v_cell_size * r_ob->slotinfo[s].slot_num_rows, 1.);
				
				paint_line(g, slot_numbers_linecolor, slot_window_table_x1, slot_window_table_y1, slot_window_active_x2, slot_window_table_y1, 1.);
				paint_line(g, slot_numbers_linecolor, slot_window_table_x1, slot_window_table_y1, slot_window_table_x1, slot_window_table_y1 + v_cell_size * r_ob->slotinfo[s].slot_num_rows, 1.);
			}
			break;
		}
			
		case k_SLOT_TYPE_TEXT:
			
			// this doesn't work properly, due to some issues in the max api the text does not stay confined in the rectangle
			if (r_ob->is_editing_type != k_TEXT_IN_SLOT) {
				// retrieve content: we expect the content to be a char[]
				long num_letters =  get_activeitem_slot_length(r_ob, s);
				double text_pad = 5 * zoom_y;
				
				//		t_jtextlayout *jtl; 
				char *text = (char *) bach_newptr(MAX(num_letters+1, 8) * sizeof(char)); 
				if (num_letters && r_ob->active_slot_notationitem && get_activeitem_slot_firstitem(r_ob, s) && get_activeitem_slot_firstitem(r_ob, s)->item) {
					char *first_letter = ((char *)get_activeitem_slot_firstitem(r_ob, s)->item);
					strncpy(text, first_letter, num_letters);
					text[num_letters]='\0'; // we manually add the ending character (which is NOT automatically added by strncpy)
				} else
					snprintf_zero(text, 8, "No text");
				
				paint_dashed_y_line(g, slot_color, slot_window_active_x1 + 2 * zoom_y, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height, 2 * zoom_y, 2 * zoom_y);
				
				write_text(g, jf_slot_text, slot_text_textcolor, text, 
						   slot_window_active_x1 + text_pad, slot_window_active_y1, slot_window_active_width - text_pad, slot_window_active_height - 10*zoom_y, 
						   JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, false, false);
				bach_freeptr(text);
			}
			break;
			
		case k_SLOT_TYPE_LLLL:
			// retrieve content: we expect the content to be a char[]
			if (r_ob->is_editing_type != k_LLLL_IN_SLOT &&
				(r_ob->active_slot_notationitem) && (get_activeitem_slot_firstitem(r_ob, s)) && (get_activeitem_slot_firstitem(r_ob, s)->item)) {
				
				char *buf = NULL;
				llll_to_text_buf((t_llll *) get_activeitem_slot_firstitem(r_ob, s)->item, &buf, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
				write_text(g, jf_slot_text, slot_text_textcolor, buf, 
						   slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height - 10*zoom_y, 
						   JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
				bach_freeptr(buf);
			}
			break;

			
		case k_SLOT_TYPE_FILELIST:
		{
			// retrieve content: we expect the content to be a char[]
			//long num_files = r_ob->active_slot_note->slot[s].length;
			char textf[MAX_PATH_CHARS]; char text[MAX_PATH_CHARS+3];
			t_slotitem *active = slot_get_active_slotitem(get_activeitem_slot(r_ob, s));
			t_slotitem *temp = get_activeitem_slot_firstitem(r_ob, s);
			t_file *file;
			int i = 0;
			//		t_jtextlayout *jtl; 
			while (temp){
				double y_pos;
				t_jrgba textc = slot_textcolor;
				file = ((t_file *)temp->item);					
				strncpy_zero(textf, file->filename, MAX_PATH_CHARS);
				snprintf_zero(text, MAX_PATH_CHARS+3, "%d] .../%s", i+1, textf);
				if (temp != active) { 
					y_pos = slot_window_active_y1 + y_file_step * i;
					write_text(g, jf_slot_file, textc, text, 
							   slot_window_active_x1, y_pos, slot_window_active_width, 20*zoom_y, 
							   JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
				} else {
					textc = slot_color;
					y_pos = slot_window_active_y1+ y_file_step * i;
					write_text(g, jf_slot_file_bold, textc, text, 
							   slot_window_active_x1, y_pos, slot_window_active_width, 20*zoom_y, 
							   JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
				}
				if (!file->exists){
					double ww, hh;
					jfont_text_measure(temp != active ? jf_slot_file : jf_slot_file_bold, text, &ww, &hh);
					paint_line(g, textc, slot_window_active_x1, y_pos + hh/2, slot_window_active_x1 + ww, y_pos + hh/2, 0.5);
				}
				i++;
				temp = temp->next;
			}
			// last element: "add a file"
			write_text(g, jf_slot_file_italic, slot_textcolor, "add file...", 
					   slot_window_active_x1, slot_window_active_y1 + y_file_step * i, slot_window_active_width, 20*zoom_y, 
					   JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
			break;
		}

		case k_SLOT_TYPE_FILTER:
		{
			t_biquad *biquad = (get_activeitem_slot_firstitem(r_ob, s) ? (t_biquad *)get_activeitem_slot_firstitem(r_ob, s)->item : NULL);
			
			paint_filledrectangle(g, build_jrgba(1, 1, 1, slot_backgroundcolor.alpha * 2./3.), slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height);
			
			// type of filter in transparence
			write_text(g, jf_slot_name, build_jrgba(0.6, 0.6, 0.6, 0.5), biquad ? filtertype_to_filtersym(biquad->filter_type)->s_name : "none", 
					   slot_window_active_x1 + 2, slot_window_active_y1 + 2, slot_window_active_width, slot_window_active_height, 
					   JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
			
			paint_filtergraph_in_slot_win(r_ob, g, build_rect(slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height), 
										  r_ob->active_slot_notationitem, s, slot_color, 1., true, true, true, false, true, r_ob->slot_window_zoom);
			
			// displaying values
			if (slot_needs_legend) {
				
				if (r_ob->slotinfo[s].slot_repr && r_ob->slotinfo[s].slot_repr->l_head && hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM && hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == _llllobj_sym_cents) {
					double mc = f2mc(biquad->cutoff_freq, 440);
					long screen_note = 0; 
					t_rational screen_acc = long2rat(0);
					char *outname = NULL;
					mc_to_screen_approximations(r_ob, mc, &screen_note, &screen_acc, NULL, NULL);
					midicents2notename(r_ob->middleC_octave, screen_note, screen_acc, r_ob->note_names_style, true, &outname);
					snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "%ldmc (%s)  %.1fQ  %.1fdB", (long)round(mc), outname, biquad->Q, biquad->gain_dB);
					bach_freeptr(outname);
				} else
					snprintf_zero(legend, CONST_SLOT_MAX_LEGEND_CHARS, "%ldHz  %.1fQ  %.1fdB", (long)round(biquad->cutoff_freq), biquad->Q, biquad->gain_dB);
			}
			break;
		}

		case k_SLOT_TYPE_DYNFILTER:
		{
			t_biquad *biquad = (get_activeitem_slot_firstitem(r_ob, s) ? (t_biquad *)get_activeitem_slot_firstitem(r_ob, s)->item : NULL);
			
			paint_filledrectangle(g, build_jrgba(1, 1, 1, slot_backgroundcolor.alpha * 2./3.), r_ob->slot_window_active_nozoom.x, r_ob->slot_window_active_nozoom.y, r_ob->slot_window_active_nozoom.width, r_ob->slot_window_active_nozoom.height);
			
			// type of filter in transparence
			write_text(g, jf_slot_name, build_jrgba(0.6, 0.6, 0.6, 0.5), biquad ? filtertype_to_filtersym(biquad->filter_type)->s_name : "none", 
					   r_ob->slot_window_active_nozoom.x + 2, r_ob->slot_window_active_nozoom.y + 2, r_ob->slot_window_active_nozoom.width, r_ob->slot_window_active_nozoom.height, 
					   JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
			
			paint_dynfiltergraph_in_slot_win(r_ob, g, r_ob->slot_window_active, r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, 1., true, true, true, r_ob->slot_window_zoom);
			
			// displaying values
			if (slot_needs_legend) {
				t_biquad *biquad = (t_biquad *) ((t_slotitem *)r_ob->j_mousedown_ptr)->item;
				if (biquad && biquad->filter_type != k_FILTER_DISPLAY && biquad->filter_type != k_FILTER_NONE) {
					
					if (r_ob->slotinfo[s].slot_repr && r_ob->slotinfo[s].slot_repr->l_head && hatom_gettype(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == H_SYM && hatom_getsym(&r_ob->slotinfo[s].slot_repr->l_head->l_hatom) == _llllobj_sym_cents) {
						double mc = f2mc(biquad->cutoff_freq, 440);
						long screen_note = 0; 
						t_rational screen_acc = long2rat(0);
						char *outname = NULL;
						mc_to_screen_approximations(r_ob, mc, &screen_note, &screen_acc, NULL, NULL);
						midicents2notename(r_ob->middleC_octave, screen_note, screen_acc, r_ob->note_names_style, true, &outname);
						snprintf_zero(legend, 100, "%ldmc (%s)  %.1fQ  %.1fdB", (long)round(mc), outname, biquad->Q, biquad->gain_dB);
						bach_freeptr(outname);
					} else
						snprintf_zero(legend, 100, "%ldHz  %.1fQ  %.1fdB", (long)round(biquad->cutoff_freq), biquad->Q, biquad->gain_dB);
				}
			}
			break;
		}
		
		case k_SLOT_TYPE_COLOR:
		{
			t_jrgba *color = (get_activeitem_slot_firstitem(r_ob, s) ? (t_jrgba *)get_activeitem_slot_firstitem(r_ob, s)->item : NULL);
			
			r_ob->slot_window_spectrum_width = (slot_window_active_width < 25 * zoom_y ? slot_window_active_width /4 : 10 * zoom_y);
			r_ob->slot_window_palette_width = slot_window_active_width - (r_ob->slot_window_spectrum_width + 4 * zoom_y);
			r_ob->slot_window_spectrum_x = slot_window_active_x1 + r_ob->slot_window_palette_width + 4 * zoom_y;
			
			if (!color) {
				write_text(g, jf_slot_name, slot_textcolor, "(no color)",
						   r_ob->slot_window_active_x1, r_ob->slot_window_active_y1, 
						   slot_window_active_width, slot_window_active_height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
			} else {
				paint_colorpalette(r_ob, g, build_rect(slot_window_active_x1, slot_window_active_y1, r_ob->slot_window_palette_width, slot_window_active_height), r_ob->slot_window_spectrum_x, r_ob->slot_window_spectrum_width, *color, r_ob->slot_top_right_color, true, true, true, true, jf_slot_file, get_grey_to_write_over_color(*color, 0.25), *color, zoom_y);
			}
			break;
		}

            
        case k_SLOT_TYPE_ARTICULATIONS:
        {
            paint_articulations_cards_in_slot(r_ob, g, &r_ob->slot_window_active, &r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, true, r_ob->slot_window_zoom, r_ob->show_slot_labels, jf_slot_smallvalues, slot_textcolor);
            
            if (slot_needs_legend) {
                double id = pt_to_card_id_in_slot(r_ob, mouse, s, r_ob->slot_window_active);
                if (id > 0 && id < r_ob->articulations_typo_preferences.num_articulations) {
                    t_symbol *s = notationobj_articulation_id2symbol(r_ob, id);
                    if (s)
                        snprintf_zero(legend, 100, "%s", s->s_name);
                }
            }
        }
            break;

        case k_SLOT_TYPE_NOTEHEAD:
        {
            paint_notehead_cards_in_slot(r_ob, g, &r_ob->slot_window_active, &r_ob->slot_window_active_nozoom, r_ob->active_slot_notationitem, s, slot_color, true, r_ob->slot_window_zoom, r_ob->show_slot_labels, jf_slot_smallvalues, slot_textcolor);
            
            if (slot_needs_legend) {
                double id = pt_to_card_id_in_slot(r_ob, mouse, s, r_ob->slot_window_active);
                if (id > 0 && id < r_ob->noteheads_typo_preferences.num_noteheads) {
                    t_symbol *s = notationobj_notehead_id2symbol(r_ob, id);
                    if (s)
                        snprintf_zero(legend, 100, "%s", s->s_name);
                }
            }
        }
            break;
            
        case k_SLOT_TYPE_DYNAMICS:
        {
            
            // this doesn't work properly, due to some issues in the max api the text does not stay confined in the rectangle
            if (r_ob->is_editing_type != k_DYNAMICS_IN_SLOT) {
                t_dynamics *dyn = (get_activeitem_slot_firstitem(r_ob, s) ? (t_dynamics *)get_activeitem_slot_firstitem(r_ob, s)->item : NULL);
                double text_pad = 5 * zoom_y;
                double curr_hairpin_start_x = 0;
                long curr_hairpin_type = 0;
                paint_dynamics(r_ob, g, &slot_text_textcolor, r_ob->active_slot_notationitem, slot_window_active_x1 + text_pad, slot_window_active_x2 - slot_window_active_x1 - 2 * text_pad, dyn, jf_slot_dynamics, jf_slot_dynamics_roman, 18 * zoom_y, 9 * zoom_y, slot_window_active_y1 + slot_window_active_height * 0.5, &curr_hairpin_start_x, &curr_hairpin_type, NULL, NULL, 1, 0, true);
            }
        }
            break;
            
		default:
			write_text(g, jf_slot_values, slot_textcolor, "unused", 
									  slot_window_active_x1, slot_window_active_y1, slot_window_active_width, slot_window_active_height, 
									  JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
			break;
	}
	
	
	// show legend
	if (r_ob->show_slot_legend && legend[0]) {
		double width, height, used_width;
		jfont_text_measure(jf_slot_name, legend, &width, &height);
		slotname_right_limit = width; // since we draw the legend (at the right top), we cut the slotname, if it's too long // was: 30 * zoom_y
		used_width = r_ob->slot_window_active_nozoom.width;
		if (r_ob->slot_window_x2 > graphic_rect.width){
			// if the x_end of slot window goes beyond the end of the window (as in temporal slots) 
			slotname_right_limit += (r_ob->slot_window_x2 - graphic_rect.width);
			used_width -= (r_ob->slot_window_x2 - graphic_rect.width); 
		}
		
		write_text(g, jf_slot_name, slot_textcolor, legend, 
				   r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X, r_ob->j_inset_y + r_ob->slot_window_y1 + 2, 
				   used_width, slot_window_active_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
	}
	
	// slot horizontal scrollbar
	if (((!slot_is_temporal(r_ob, s)) || r_ob->obj_type == k_NOTATION_OBJECT_SLOT) &&
        ((can_slot_be_hzoomed(r_ob, s) && r_ob->slot_window_hzoom_factor > 1) || (can_slot_be_hmoved(r_ob, s) && r_ob->slot_window_active_unscrolled_width > r_ob->slot_window_active.width))) {
		double overall_zoom = r_ob->zoom_y * r_ob->slot_window_zoom / 100.;
        double start_x, width;
        if (!can_slot_be_hzoomed(r_ob, s)) {
            start_x = r_ob->slot_window_active_nozoom.x + (r_ob->slot_window_zoomed_start / (r_ob->slot_window_active_unscrolled_width / r_ob->slot_window_active_nozoom.width)) * r_ob->slot_window_active_nozoom.width;
            width = MAX(4, r_ob->slot_window_active.width * r_ob->slot_window_active.width/r_ob->slot_window_active_unscrolled_width);
        } else {
            start_x = r_ob->slot_window_active_nozoom.x + r_ob->slot_window_zoomed_start * r_ob->slot_window_active_nozoom.width;
            width = MAX(4, r_ob->slot_window_active_nozoom.width/r_ob->slot_window_hzoom_factor);
        }
        double start_y = r_ob->obj_type == k_NOTATION_OBJECT_SLOT ? r_ob->slot_window_active.y + r_ob->slot_window_active.height : r_ob->slot_window.y + r_ob->slot_window.height + 1.5 * overall_zoom;
		double height = r_ob->obj_type == k_NOTATION_OBJECT_SLOT ? r_ob->slot_window.y + r_ob->slot_window.height - (r_ob->slot_window_active.y + r_ob->slot_window_active.height) : 1.5 * overall_zoom;
		paint_rectangle_rounded(g, build_jrgba(0.3, 0.3, 0.3, 1), build_jrgba(0.3, 0.3, 0.3, 1), start_x, start_y, width, height, 1, 1.5 * overall_zoom, 1 * overall_zoom);
	}

	
	// selection rectangle?
	if (r_ob->j_mousedown_obj_type == k_SLOT_REGION) 
		paint_rectangle(g, r_ob->j_selection_rgba, change_alpha(r_ob->j_selection_rgba, 0.2), r_ob->j_mousedown_point.x, r_ob->j_mousedown_point.y, MIN(r_ob->j_mousedrag_point.x, r_ob->slot_window_x2) - r_ob->j_mousedown_point.x, MIN(r_ob->j_mousedrag_point.y, r_ob->slot_window_y2) - r_ob->j_mousedown_point.y, 1);
	
	
	// prepare the slot name box width
	usable_width = r_ob->slot_window_active_nozoom.width - slotname_right_limit;
	if (r_ob->slot_window_x1 < 0) { // name outside the window
		double delta_pos = -r_ob->slot_window_x1;
		left_pos = CONST_SLOT_WINDOW_INSET_X;
		usable_width -= delta_pos;
	}

	// link-to label?
	link_to_label[0] = 0;
	if (s == r_ob->link_notehead_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ notehead");
	else if (s == r_ob->link_lyrics_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ lyrics");
	else if (s == r_ob->link_nitemcolor_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ color");
	else if (s == r_ob->link_notehead_font_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ noteheadfont");
	else if (s == r_ob->link_notesize_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ notesize");
	else if (s == r_ob->link_notehead_adjust_to_slot - 1)
		snprintf_zero(link_to_label, 100, "→ noteheadadjust");
    else if (s == r_ob->link_articulations_to_slot - 1)
        snprintf_zero(link_to_label, 100, "→ articulations");
    else if (s == r_ob->link_annotation_to_slot - 1)
        snprintf_zero(link_to_label, 100, "→ annotation");
    else if (s == r_ob->link_dynamics_to_slot - 1)
        snprintf_zero(link_to_label, 100, "→ dynamics");

    if (link_to_label[0]) {
		t_jfont *jf_linkto = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, 8. * zoom_y);
//		write_text(g, jf_linkto, col, link_to_label, left_pos, r_ob->slot_window_y1, slot_window_active_width - 2 * CONST_SLOT_WINDOW_INSET_X, r_ob->slot_window_y2 - r_ob->slot_window_y1 - 1 * zoom_y, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
        write_text(g, jf_linkto, slot_namecolor, link_to_label, r_ob->slot_window_x1, r_ob->slot_window_y2 + 2 * zoom_y, r_ob->slot_window_x2 - r_ob->slot_window_x1, r_ob->slot_window_y2 - r_ob->slot_window_y1 - 1 * zoom_y, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
		jfont_destroy_debug(jf_linkto);
	}

	// paint color strip over the slot name
	double slotname_w, slotname_h;
	jfont_text_measure(jf_slot_name, r_ob->slotinfo[s].slot_name->s_name, &slotname_w, &slotname_h);
	if (MIN(slotname_w, usable_width) > 5)
		paint_rectangle(g, slot_color, slot_color, left_pos, r_ob->slot_window_y1, MIN(slotname_w, usable_width), 1.25 * r_ob->zoom_y * r_ob->slot_window_zoom / 100., 0);
	
	// write the slot name
	write_text(g, jf_slot_name, slot_namecolor, r_ob->slotinfo[s].slot_name->s_name, left_pos, r_ob->j_inset_y + r_ob->slot_window_y1 + 2, 
			   usable_width, slot_window_active_height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
	
	
	jfont_destroy_debug(jf_slot_name);
	jfont_destroy_debug(jf_slot_values);
	jfont_destroy_debug(jf_slot_smallvalues);
	jfont_destroy_debug(jf_slot_text);
	jfont_destroy_debug(jf_slot_file);
	jfont_destroy_debug(jf_slot_file_bold);
	jfont_destroy_debug(jf_slot_file_italic);
	jfont_destroy_debug(jf_slot_function_point_labels);
    jfont_destroy_debug(jf_slot_dynamics);
    jfont_destroy_debug(jf_slot_dynamics_roman);
    if (jf_slot_function_grid_labels)
        jfont_destroy_debug(jf_slot_function_grid_labels);
}


// beware: returns the 0-based number!!!!
long slotname_to_slotnum(t_notation_obj *r_ob, t_symbol *name){
	long i;

	for (i = 0; i < CONST_MAX_SLOTS; i++)
		if (name == r_ob->slotinfo[i].slot_name)
			return i;
			
	if (name == _llllobj_sym_active) 
		return r_ob->active_slot_num;

	return -1;
}


long llllelem_to_slotnum(t_notation_obj *r_ob, t_llllelem *elem, char elem_is_1based)
{
	long j = -1;
	if (hatom_gettype(&elem->l_hatom) == H_SYM)
		j = slotname_to_slotnum(r_ob, hatom_getsym(&elem->l_hatom));
	else if (is_hatom_number(&elem->l_hatom))
		j = hatom_getlong(&elem->l_hatom) - (elem_is_1based ? 1 : 0);
	return j;
}

long atom_to_slotnum(t_notation_obj *r_ob, t_atom *av, char atom_is_1based)
{
	long j = -1;

	if (atom_gettype(av) == A_SYM)
		j = slotname_to_slotnum(r_ob, atom_getsym(av));
	else if (is_atom_number(av))
		j = atom_getlong(av) - (atom_is_1based ? 1 : 0);
	return j;
}

long hatom_to_slotnum(t_notation_obj *r_ob, t_hatom *h, char hatom_is_1based)
{
    long j = -1;
    
    if (hatom_gettype(h) == H_SYM)
        j = slotname_to_slotnum(r_ob, hatom_getsym(h));
    else if (is_hatom_number(h))
        j = hatom_getlong(h) - (hatom_is_1based ? 1 : 0);
    return j;
}

long number_slot_to_text_buf(t_notation_obj *r_ob, t_slotitem *firstslotitem, long num_elems, char **buf, char slot_type, long slot_num, char numbers_only){
	long i, len, cur = 0;
	t_slotitem *curr_item;
	char part_string[2048];
	long size = LLLL_BUF_SIZE_STEP;
	*buf = (char *) bach_newptr(LLLL_BUF_SIZE_STEP);

	for (i = 0, curr_item = firstslotitem; i < num_elems && curr_item; i++, curr_item = curr_item->next) {
		if (slot_type == k_SLOT_TYPE_INT || slot_type == k_SLOT_TYPE_INTLIST) {
			if (!numbers_only && r_ob->slotinfo[slot_num].slot_repr && r_ob->slotinfo[slot_num].slot_repr->l_size > 0 && hatom_gettype(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom) == H_LLLL) { // enum
				double slot_min = r_ob->slotinfo[slot_num].slot_range[0];
				t_llll *enumllll = hatom_getllll(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom);
				long idx = *((long *)curr_item->item) - round(slot_min) + 1;
				if (idx <= (long)enumllll->l_size)
					snprintf_zero(part_string, 2048, "%s ", nth_sym_of_a_plain_sym_llll(hatom_getllll(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom), *((long *)curr_item->item) - round(slot_min) + 1)->s_name);
				else 
					snprintf_zero(part_string, 2048, "%ld ", *((long *)curr_item->item));
			} else if (!numbers_only && r_ob->slotinfo[slot_num].slot_repr && r_ob->slotinfo[slot_num].slot_repr->l_size > 0 && hatom_gettype(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom) == H_SYM) { // unit of measurement
				snprintf_zero(part_string, 2048, "%ld%s ", *((long *)curr_item->item), hatom_getsym(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom)->s_name);
			} else {
				snprintf_zero(part_string, 2048, "%ld ", *((long *)curr_item->item));
			}
		} else {
			if (!numbers_only && r_ob->slotinfo[slot_num].slot_repr && r_ob->slotinfo[slot_num].slot_repr->l_size > 0 && hatom_gettype(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom) == H_SYM)
				snprintf_zero(part_string, 2048, "%.3f%s ", *((double *)curr_item->item), hatom_getsym(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom)->s_name);
			else 
				snprintf_zero(part_string, 2048, "%.3f ", *((double *)curr_item->item)); 
		}
		len = strlen(part_string);
		if (cur + len >= size) {
			size += LLLL_BUF_SIZE_STEP;
			*buf = (char *) bach_resizeptr((*buf), size);
		}
		strncpy((*buf) + cur, part_string, len);
		cur += len;
	}
    
    if (cur <= 0)
        (*buf)[0] = 0;
    else
        (*buf)[cur - 1] = 0; // last item was a space: last space will be deleted
//	(*buf)[cur++] = 0;
	
	return cur;
}


double get_slot_window_top_inset_uheight(t_notation_obj *r_ob, long slot_num)
{
	char slot_type = r_ob->slotinfo[slot_num].slot_type;
	switch (slot_type) {
		case k_SLOT_TYPE_FUNCTION: 
		case k_SLOT_TYPE_3DFUNCTION: 
		case k_SLOT_TYPE_SPAT:  
		case k_SLOT_TYPE_FILTER: 
		case k_SLOT_TYPE_DYNFILTER:
			return CONST_SLOT_FUNCTION_UY_INSET_TOP; 
			break;
		case k_SLOT_TYPE_COLOR: 
			return CONST_SLOT_COLOR_UY_INSET_TOP; 
			break;
		case k_SLOT_TYPE_FILELIST:
			return CONST_SLOT_FILE_UY_START; 
			break;
		case k_SLOT_TYPE_INTLIST: 
		case k_SLOT_TYPE_FLOATLIST:
			return CONST_SLOT_NUMBERLIST_UY_START; 
			break;
		case k_SLOT_TYPE_INTMATRIX: 
		case k_SLOT_TYPE_FLOATMATRIX: 
		case k_SLOT_TYPE_TOGGLEMATRIX: 
			return CONST_SLOT_NUMBERMATRIX_UY_START; 
			break;
		default: 
			return CONST_SLOT_WINDOW_INSET_Y / r_ob->zoom_y;
			break;
	}
	return CONST_SLOT_WINDOW_INSET_Y / r_ob->zoom_y;
}

double get_slot_window_bottom_inset_uheight(t_notation_obj *r_ob, long slot_num)
{
	char slot_type = r_ob->slotinfo[slot_num].slot_type;
	switch (slot_type) {
		case k_SLOT_TYPE_FUNCTION: 
		case k_SLOT_TYPE_3DFUNCTION: 
		case k_SLOT_TYPE_SPAT:  
		case k_SLOT_TYPE_FILTER: 
		case k_SLOT_TYPE_DYNFILTER:
			return CONST_SLOT_FUNCTION_UY_INSET_BOTTOM; 
			break;
		case k_SLOT_TYPE_COLOR: 
			return CONST_SLOT_COLOR_UY_INSET_BOTTOM; 
			break;
		default: 
			return CONST_SLOT_WINDOW_INSET_Y / r_ob->zoom_y;
			break;
	}
	return CONST_SLOT_WINDOW_INSET_Y / r_ob->zoom_y;
}


double get_default_slot_window_uheight(t_notation_obj *r_ob, long slot_num, t_notation_item *nitem, char get_active_uheight)
{
	char slot_type = r_ob->slotinfo[slot_num].slot_type;
	if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
		double inset = get_slot_window_top_inset_uheight(r_ob, slot_num) + get_slot_window_bottom_inset_uheight(r_ob, slot_num);
		return - inset + r_ob->height/(r_ob->zoom_y * ((get_active_uheight ? r_ob->bgslot_zoom : r_ob->slot_window_zoom)/100.));
	}

	double slot_window_height = 50;
	switch (slot_type) {
		case k_SLOT_TYPE_FUNCTION: 
		case k_SLOT_TYPE_3DFUNCTION: 
		case k_SLOT_TYPE_SPAT:  
		case k_SLOT_TYPE_FILTER: 
		case k_SLOT_TYPE_DYNFILTER:
		case k_SLOT_TYPE_INTLIST: 
		case k_SLOT_TYPE_FLOATLIST:
			slot_window_height = 50; 
			break;
		case k_SLOT_TYPE_COLOR: 
			slot_window_height = 70; 
			break;
		case k_SLOT_TYPE_INT: 
		case k_SLOT_TYPE_FLOAT: 
			slot_window_height = 45;
			break;
		case k_SLOT_TYPE_TEXT: 
		case k_SLOT_TYPE_LLLL: 
        case k_SLOT_TYPE_ARTICULATIONS:
        case k_SLOT_TYPE_NOTEHEAD:
			slot_window_height = 50;
			break;
		case k_SLOT_TYPE_FILELIST:
        {
            t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
            slot_window_height = CONST_SLOT_FILE_UY_START + CONST_SLOT_FILE_UY_STEP * (slot ? slot->length+2 : 50);
        }
			break;
/*		case k_SLOT_TYPE_INTLIST: 
		case k_SLOT_TYPE_FLOATLIST:
			slot_window_height = CONST_SLOT_NUMBERLIST_UY_START + CONST_SLOT_NUMBERLIST_UY_STEP * (note->slot[slot_num].length+2); 
			break;*/
		case k_SLOT_TYPE_INTMATRIX: 
		case k_SLOT_TYPE_FLOATMATRIX: 
		case k_SLOT_TYPE_TOGGLEMATRIX: 
			slot_window_height = CONST_SLOT_NUMBERMATRIX_UY_START + CONST_SLOT_NUMBERLIST_UY_STEP * (r_ob->slotinfo[slot_num].slot_num_cols+2); 
			break;
		case k_SLOT_TYPE_NONE:
			slot_window_height = 30; 
			break;
        case k_SLOT_TYPE_DYNAMICS:
            slot_window_height = 40;
            break;
		default:
			slot_window_height = 40; 
			break;
	}
	
	if (get_active_uheight) 
		slot_window_height = slot_window_height - get_slot_window_top_inset_uheight(r_ob, slot_num) - get_slot_window_bottom_inset_uheight(r_ob, slot_num);

	return slot_window_height;
}


char slot_is_temporal(t_notation_obj *r_ob, long slotnum)
{
    return (r_ob->slotinfo[slotnum].slot_temporalmode != k_SLOT_TEMPORALMODE_NONE);
}

char slot_is_temporal_absolute(t_notation_obj *r_ob, long slotnum)
{
    return (r_ob->slotinfo[slotnum].slot_temporalmode == k_SLOT_TEMPORALMODE_MILLISECONDS || r_ob->slotinfo[slotnum].slot_temporalmode == k_SLOT_TEMPORALMODE_TIMEPOINTS);
}



char slot_can_extend_beyond_note_tail(t_notation_obj *r_ob, long slotnum)
{
    return r_ob->slotinfo[slotnum].extend_beyond_tails;
//    return slot_is_temporal_absolute(r_ob, slotnum);
}

void slot_clip_domain_value(t_notation_obj *r_ob, t_notation_item *nitem, long slotnum, double *val)
{
    if (slot_can_extend_beyond_note_tail(r_ob, slotnum))
        *val = MAX(*val, r_ob->slotinfo[slotnum].slot_domain[0]);
    else {
        double min = r_ob->slotinfo[slotnum].slot_domain[0];
        double max = r_ob->slotinfo[slotnum].slot_domain[1];
        if (r_ob->slotinfo[slotnum].slot_temporalmode == k_SLOT_TEMPORALMODE_MILLISECONDS) {
            min = 0;
            max = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slotnum, nitem);
        }
        clip_double(val, min, max);
    }
}


void paint_background_slots(t_notation_obj *r_ob, t_jgraphics* g, double slot_bgwindow_active_x1, double slot_bgwindow_active_y2, double duration_line_length, t_jfont *jf_slottext, t_jfont *jf_slotbold, t_jfont *jf_slotdynamics, t_jfont *jf_slotdynamicsroman, t_notation_item *nitem, double pos_x_for_numbers, double pos_y_for_numbers, double pos_x_for_text, double pos_y_for_text, long dont_paint_this_slot)
{
	long i;
	double x_deplacement_numbers = 0., x_deplacement_text = 0.;
	double zoom_y = r_ob->zoom_y * (r_ob->bgslot_zoom / 100.);
    char has_y_labels = false, has_x_labels = false;

	for (i = 0; i < r_ob->num_background_slots; i++) {
		long slotnum = r_ob->background_slots[i] - 1;
		if (slotnum == dont_paint_this_slot)
			continue;

		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && r_ob->slotinfo[slotnum].slot_singleslotfortiednotes && nitem->type == k_NOTE && ((t_note *)nitem)->tie_from)
			continue;

		double slot_window_active_width, slot_window_active_height; 

        function_slot_has_labels(r_ob, i, &has_x_labels, &has_y_labels);

        
        if (slot_is_temporal(r_ob, slotnum)) {
			if (r_ob->obj_type != k_NOTATION_OBJECT_SCORE || nitem->type != k_NOTE || !((t_note *)nitem)->tie_to || !r_ob->slotinfo[slotnum].slot_singleslotfortiednotes)
				slot_window_active_width = duration_line_length;
			else {
                t_note *note = (t_note *)nitem;
				t_note *lastnote = note_get_last_in_tieseq(note);
				if (lastnote && lastnote->parent && lastnote->parent->parent && lastnote->parent->parent->tuttipoint_reference) {
					double end_pos = unscaled_xposition_to_xposition(r_ob, lastnote->parent->parent->tuttipoint_reference->offset_ux + lastnote->parent->stem_offset_ux + lastnote->parent->duration_ux);
					slot_window_active_width = end_pos - note->center.x;
				} else 
					slot_window_active_width = duration_line_length;
            }
            
/*            if (r_ob->slotinfo[slotnum].slot_uwidth == -2. && slot_is_temporal(r_ob, slotnum)) { // auto
                double max_x = slot_get_max_x(r_ob, notation_item_get_slot(r_ob, nitem, slotnum), slotnum);
                
                if (slot_is_temporal_absolute(r_ob, slotnum)) {
                    slot_window_active_width = MAX(slot_window_active_width, 1 * zoom_y);
                }
            } */
		} else
			slot_window_active_width = r_ob->slotinfo[slotnum].slot_uwidth * zoom_y;
		
		if (r_ob->slotinfo[slotnum].slot_active_uheight < 0) // automatic
			slot_window_active_height = get_default_slot_window_uheight(r_ob, slotnum, nitem, true) * zoom_y;
		else
			slot_window_active_height = r_ob->slotinfo[slotnum].slot_active_uheight * zoom_y;
		
        double slot_window_active_x1 = slot_bgwindow_active_x1;
        double slot_window_active_y1 = slot_bgwindow_active_y2 - slot_window_active_height;

        if (has_x_labels) {
            double new_slot_bgwindow_active_y2 = slot_bgwindow_active_y2 - 5 * zoom_y;
            double diff = (slot_bgwindow_active_y2 - new_slot_bgwindow_active_y2);
            if (diff < slot_window_active_height) {
                slot_window_active_height -= diff;
            } else
                has_x_labels = false;
        }

        if (has_y_labels) {
            double new_slot_bgwindow_active_x1 = slot_bgwindow_active_x1 + function_slot_get_max_label_width(r_ob, slotnum, NULL);
            double diff = (new_slot_bgwindow_active_x1 - slot_bgwindow_active_x1);
            if (diff < slot_window_active_width) {
                slot_window_active_width -= diff;
                slot_window_active_x1 += diff;
            } else
                has_y_labels = false;
        }
        
        t_slot *slot = notation_item_get_slot(r_ob, nitem, slotnum);
		if (slotnum >= 0 && slotnum < CONST_MAX_SLOTS && slot && slot->firstitem && slot->firstitem->item){
			t_jrgba slot_color = change_luminosity(r_ob->slotinfo[slotnum].slot_color, 0.9);
			t_rect rect = build_rect(slot_window_active_x1, slot_window_active_y1,
                                     slot_is_temporal(r_ob, slotnum) ? slot_window_active_width : r_ob->slotinfo[slotnum].slot_uwidth * zoom_y,  slot_window_active_height);

            if (slot_can_extend_beyond_note_tail(r_ob, slotnum))
                rect.width = r_ob->width - rect.x - r_ob->j_inset_x;
            
			switch (r_ob->slotinfo[slotnum].slot_type) {
				case k_SLOT_TYPE_FUNCTION:
					paint_function_in_slot_win(r_ob, g, rect, rect, nitem, slotnum, slot_color, 0.5, false, false, true, false, r_ob->bgslot_zoom, false, false, NULL, false);
					break;
				case k_SLOT_TYPE_3DFUNCTION:
					paint_3dfunction_in_slot_win(r_ob, g, rect, rect, nitem, slotnum, slot_color, 0.5, false, false, true, false, r_ob->bgslot_zoom, false, false);
					break;
				case k_SLOT_TYPE_SPAT:
					paint_spatfunction_in_slot_win(r_ob, g, rect, rect, nitem, slotnum, slot_color, slot_color, 0.5, false, false, true, true, CONST_SLOT_SPAT_CIRCLE_URADIUS * 0.7, r_ob->bgslot_zoom, false, false);
					break;
				case k_SLOT_TYPE_INT:
				case k_SLOT_TYPE_FLOAT:
				{
					char *number_txt = NULL; double width; double height;
					long size = (r_ob->slotinfo[slotnum].slot_type == k_SLOT_TYPE_INT || r_ob->slotinfo[slotnum].slot_type == k_SLOT_TYPE_FLOAT) ? 1 : slot->length;
					number_slot_to_text_buf(r_ob, slot->firstitem, size, &number_txt, r_ob->slotinfo[slotnum].slot_type, slotnum);
					jfont_text_measure(jf_slotbold, number_txt, &width, &height);
					write_text_standard_account_for_vinset(r_ob, g, jf_slotbold, slot_color, number_txt, pos_x_for_numbers + x_deplacement_numbers, pos_y_for_numbers);
					x_deplacement_numbers += width + 4 * zoom_y;
					if (number_txt) 
						bach_freeptr(number_txt);
				}
					break;
				case k_SLOT_TYPE_INTLIST:
				case k_SLOT_TYPE_FLOATLIST:
				{
					if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
						paint_numberlist_bars_in_noteslot(r_ob, g, &rect, &rect, nitem, slotnum, slot_color, true, r_ob->bgslot_zoom, false, jf_slotbold, slot_color);
					} else {
						char *number_txt = NULL; double width; double height;
						long size = (r_ob->slotinfo[slotnum].slot_type == k_SLOT_TYPE_INT || r_ob->slotinfo[slotnum].slot_type == k_SLOT_TYPE_FLOAT) ? 1 : slot->length;
						number_slot_to_text_buf(r_ob, slot->firstitem, size, &number_txt, r_ob->slotinfo[slotnum].slot_type, slotnum);
						jfont_text_measure(jf_slotbold, number_txt, &width, &height);
						write_text_standard_account_for_vinset(r_ob, g, jf_slotbold, slot_color, number_txt, pos_x_for_numbers + x_deplacement_numbers, pos_y_for_numbers);
						x_deplacement_numbers += width + 4 * zoom_y;
						if (number_txt) 
							bach_freeptr(number_txt);
					}
				}
					break;
                    
                case k_SLOT_TYPE_ARTICULATIONS:
                {
                    double width; double height;
                    t_slotitem *item;
                    for (item = slot->firstitem; item; item = item->next) {
                        long id = ((t_articulation *)item->item)->articulation_ID;
                        double fontsize = r_ob->slot_background_font_size * r_ob->articulations_typo_preferences.artpref[id].base_pt / 12. * zoom_y * (r_ob->bgslot_zoom/100.);
                        t_jfont *jf_art = jfont_create_debug(r_ob->articulations_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, fontsize);

                        char *buf = articulation_to_text_buf(&r_ob->articulations_typo_preferences, id);
                        jfont_text_measure(jf_art, buf, &width, &height);
                        write_text_standard_account_for_vinset(r_ob, g, jf_art, slot_color, buf, pos_x_for_text + x_deplacement_text, pos_y_for_text - 0.75 * fontsize);
                        x_deplacement_text += width + 4 * zoom_y;
                        bach_freeptr(buf);
                        jfont_destroy_debug(jf_art);
                    }
                    x_deplacement_text += 4 * zoom_y;
                }
                    break;
                    
                case k_SLOT_TYPE_NOTEHEAD:
                {
                    double width; double height;
                    t_slotitem *item;
                    for (item = slot->firstitem; item; item = item->next) {
                        long id = *((long *)item->item);
                        double fontsize = r_ob->slot_background_font_size * r_ob->noteheads_typo_preferences.nhpref[id].base_pt / 12. * zoom_y * (r_ob->bgslot_zoom/100.);
                        t_jfont *jf_nh = jfont_create_debug(r_ob->articulations_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, fontsize);
                        
                        char *buf = notehead_to_text_buf(r_ob, id, notation_item_get_symduration(r_ob, nitem));
                        jfont_text_measure(jf_nh, buf, &width, &height);
                        write_text_standard_account_for_vinset(r_ob, g, jf_nh, slot_color, buf, pos_x_for_text + x_deplacement_text, pos_y_for_text - 0.75 * fontsize);
                        x_deplacement_text += width + 4 * zoom_y;
                        bach_freeptr(buf);
                        jfont_destroy_debug(jf_nh);
                    }
                    x_deplacement_text += 4 * zoom_y;
                }
                    break;
                case k_SLOT_TYPE_TEXT:
				{
					long num_letters = slot->length;
					double width, height;
					char *text = (char *) bach_newptr(MAX(num_letters+1, 1) * sizeof(char)); 
					if (slot->firstitem && slot->firstitem->item) {
						char *first_letter = ((char *)slot->firstitem->item);
						strncpy(text, first_letter, num_letters);
						text[num_letters]=0; // we manually add the ending character (which is NOT automatically added by strncpy)
					} else {
						text[0] = 0;
					}
					jfont_text_measure(jf_slottext, text, &width, &height);
					write_text_standard_account_for_vinset(r_ob, g, jf_slottext, slot_color, text, pos_x_for_text + x_deplacement_text, pos_y_for_text);
					x_deplacement_text += width + 4 * zoom_y;
					bach_freeptr(text);
				}
					break;
				case k_SLOT_TYPE_LLLL:
				case k_SLOT_TYPE_INTMATRIX:
				case k_SLOT_TYPE_FLOATMATRIX:
				case k_SLOT_TYPE_TOGGLEMATRIX:
					if (slot && slot->firstitem && slot->firstitem->item) {
						double width, height;
						char *buf = NULL;
						llll_to_text_buf((t_llll *) slot->firstitem->item, &buf, 0, BACH_DEFAULT_MAXDECIMALS, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
						jfont_text_measure(jf_slottext, buf, &width, &height);
						write_text_standard_account_for_vinset(r_ob, g, jf_slottext, slot_color, buf, pos_x_for_text + x_deplacement_text, pos_y_for_text);
						x_deplacement_text += width + 4 * zoom_y;
						bach_freeptr(buf);
					}
					break;
				case k_SLOT_TYPE_FILELIST:
				{
					char textf[MAX_PATH_CHARS];
					double width, height;
					t_slotitem *active = slot_get_active_slotitem(slot);
                    t_slotitem *temp = slot ? slot->firstitem : NULL;
					t_file *file;
					while (temp){
						t_jrgba text_color;
						text_color = slot_color;
						file = ((t_file *)temp->item);		
						strncpy_zero(textf, file->filename, MAX_PATH_CHARS);
						jfont_text_measure(temp == active ? jf_slotbold : jf_slottext, textf, &width, &height);
						write_text_standard_account_for_vinset(r_ob, g, temp == active ? jf_slotbold : jf_slottext, slot_color, textf, pos_x_for_text + x_deplacement_text, pos_y_for_text);
						if (!file->exists)
							paint_line(g, slot_color, pos_x_for_text + x_deplacement_text, pos_y_for_text + height/2, pos_x_for_text + x_deplacement_text + width, pos_y_for_text + height/2, 1);
						x_deplacement_text += width + 4 * zoom_y;
						temp = temp->next;
					}
				}
					break;
				case k_SLOT_TYPE_FILTER:
					paint_filtergraph_in_slot_win(r_ob, g, build_rect(slot_window_active_x1, slot_window_active_y1, 
																	  slot_is_temporal(r_ob, slotnum) ? slot_window_active_width : r_ob->slotinfo[slotnum].slot_uwidth * zoom_y,
																	  slot_window_active_height), nitem, slotnum, slot_color, 0.5, false, true, false, false, false, r_ob->bgslot_zoom);
					break;
				case k_SLOT_TYPE_DYNFILTER:
				{
					t_rect rect = build_rect(slot_window_active_x1, slot_window_active_y1, 
											 slot_is_temporal(r_ob, slotnum) ? slot_window_active_width : r_ob->slotinfo[slotnum].slot_uwidth * zoom_y, slot_window_active_height);
					paint_dynfiltergraph_in_slot_win(r_ob, g, rect, rect, nitem, slotnum, slot_color, 0.5, false, true, false, r_ob->bgslot_zoom);
				}
					break;
				case k_SLOT_TYPE_COLOR:
				{
					t_jrgba *color = (slot && slot->firstitem ? (t_jrgba *)slot->firstitem->item : NULL);
					if (color) {
						double side = 6 * zoom_y;
						paint_rectangle(g, get_grey(0.1), *color, pos_x_for_text + x_deplacement_text, slot_window_active_y1 + slot_window_active_height - side - 3 * zoom_y, side, side, 0.5);
						x_deplacement_text += side + 3 * zoom_y;
					}
				}
                    break;
                case k_SLOT_TYPE_DYNAMICS:
                {
                    char dyntext[1024];
                    double width;
                    t_dynamics *dyn = (slot->firstitem && slot->firstitem->item ? (t_dynamics *)slot->firstitem->item : NULL);
                    dyntext[0] = 0;
                    
                    /*
                    if (dyn)
                        snprintf_zero(dyntext, 1024, "%s", dyn->text_deparsed->s_name);
                    jfont_text_measure(jf_slottext, dyntext, &width, &height);
                    write_text_standard_account_for_vinset(r_ob, g, jf_slottext, slot_color, dyntext, pos_x_for_text + x_deplacement_text, pos_y_for_text);
                    x_deplacement_text += width + 4 * zoom_y;
                     */
                    
                    width = paint_dynamics(r_ob, g, &slot_color, nitem, pos_x_for_text + x_deplacement_text, -1, dyn, jf_slotdynamics, jf_slotdynamicsroman, r_ob->slot_background_font_size*2., r_ob->slot_background_font_size, pos_y_for_text, NULL, NULL, NULL, NULL, 2, 0, true);
                    x_deplacement_text += width + 4 * zoom_y;

                }
                    break;
			}
		}
	}
}





void paint_function_in_slot_win(t_notation_obj *r_ob, t_jgraphics* g, t_rect function_bounding_rectangle, t_rect displayed_bounding_rectangle,
								t_notation_item *nitem, long slot_number,
								t_jrgba slot_color, double new_alpha, char show_points, char can_change_luminosity, 
								char can_change_alpha, char mouse_hover, double slot_zoom, char highlight_selection,
								char paint_point_labels, t_jfont *jf_label_font, 
								char paint_lines_separately)
{
	
	t_pt this_point_screen, next_point_screen;
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_number);
    t_slotitem *temp = slot ? slot->firstitem : NULL;
	t_pts this_point, next_point;
	t_llll *displayed_points = llll_get();
	
	double zoom_y = r_ob->zoom_y * (slot_zoom/100.);

	// getting point colors
	t_jrgba point_line_color = CONST_SLOT_NAME_COLOR_CLEAR; // color of the point circle line
	t_jrgba point_inner_color = get_grey(1); // color of the point inner part
	double lines_surface_vpad = 2;
	
	if (can_change_luminosity) 
		point_line_color = change_luminosity(point_line_color, 0.2);
	if (can_change_alpha) 
		point_line_color = change_alpha(point_line_color, new_alpha);
	
	t_jrgba point_hover_lines_color = change_alpha(point_line_color, 0.5);
	
	t_jsurface *lines_surface = NULL;
	t_jgraphics *lines_g = NULL;
	
	if (paint_lines_separately) {
		lines_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, function_bounding_rectangle.width, function_bounding_rectangle.height + 2 * lines_surface_vpad);
		lines_g = jgraphics_create(lines_surface);
	}
	
	// first we display all the lines
	if (temp) 
		this_point = *((t_pts *)temp->item);
	else {
		this_point.x = 0; 
		this_point.y = 0;
	}

	while (temp && temp->next) {
		t_jrgba line_color = slot_color;
		t_pt ctrl1, ctrl2, middle, ctrl3, ctrl4;
		
		next_point = *((t_pts *)temp->next->item);
		
		if (highlight_selection && temp->selected && temp->next->selected)
			line_color = r_ob->j_selection_rgba;
		
		function_xy_values_to_pt(r_ob, nitem, this_point.x, this_point.y, slot_number, function_bounding_rectangle, &this_point_screen);
		function_xy_values_to_pt(r_ob, nitem, next_point.x, next_point.y, slot_number, function_bounding_rectangle, &next_point_screen);
		
		if (can_change_luminosity) 
			line_color = change_luminosity(line_color, highlight_selection && temp->selected && temp->next->selected ? 0.9 : 0.3);
		if (can_change_alpha) 
			line_color = change_alpha(line_color, new_alpha);
			
		double line_width = CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y;
		if (mouse_hover && r_ob->hovered_slotitem == temp->next && r_ob->hovering_segment)
			line_width += 1 * zoom_y;

		if (paint_lines_separately) {
			this_point_screen.x -= function_bounding_rectangle.x;
			this_point_screen.y -= function_bounding_rectangle.y;
			next_point_screen.x -= function_bounding_rectangle.x;
			next_point_screen.y -= function_bounding_rectangle.y;
			
			this_point_screen.y += lines_surface_vpad;
			next_point_screen.y += lines_surface_vpad;
			paint_curve_and_get_bezier_control_points(lines_g, line_color, this_point_screen, next_point_screen, next_point.slope, line_width, &ctrl1, &ctrl2, &middle, &ctrl3, &ctrl4, (e_slope_mapping)r_ob->slope_mapping_type);
			this_point_screen.x += function_bounding_rectangle.x;
			this_point_screen.y += function_bounding_rectangle.y;
			next_point_screen.x += function_bounding_rectangle.x;
			next_point_screen.y += function_bounding_rectangle.y;
			ctrl1.x += function_bounding_rectangle.x;
			ctrl1.y += function_bounding_rectangle.y;
			ctrl2.x += function_bounding_rectangle.x;
			ctrl2.y += function_bounding_rectangle.y;
			middle.x += function_bounding_rectangle.x;
			middle.y += function_bounding_rectangle.y;
			ctrl3.x += function_bounding_rectangle.x;
			ctrl3.y += function_bounding_rectangle.y;
			ctrl4.x += function_bounding_rectangle.x;
			ctrl4.y += function_bounding_rectangle.y;
		} else
			paint_curve_and_get_bezier_control_points(g, line_color, this_point_screen, next_point_screen, next_point.slope, line_width, &ctrl1, &ctrl2, &middle, &ctrl3, &ctrl4, (e_slope_mapping)r_ob->slope_mapping_type);
		
		if (paint_point_labels) {
			double abs_slope = fabs(next_point.slope);
			
			if (!temp->prev) // very first point
				llll_appendllll(displayed_points, pt_to_llll(this_point_screen, false), 0, WHITENULL_llll);
			
			if (abs_slope > 0.4) // refinement point of left bezier curve
				llll_appendllll(displayed_points, pt_to_llll(get_single_bezier_subdivision_point(this_point_screen, ctrl1, ctrl2, middle, 0.5), false), 0, WHITENULL_llll)->l_thing.w_obj = WHITENULL; // in order to distinguish midpoints from standard points, later on
			
			if (abs_slope > 0.1) // mid-curve point (the point between the two bezier curves) 
				llll_appendllll(displayed_points, pt_to_llll(middle, false), 0, WHITENULL_llll)->l_thing.w_obj = WHITENULL; // in order to distinguish midpoints from standard points, later on

			if (abs_slope > 0.4) // refinement point of right bezier curve
				llll_appendllll(displayed_points, pt_to_llll(get_single_bezier_subdivision_point(middle, ctrl3, ctrl4, next_point_screen, 0.5), false), 0, WHITENULL_llll)->l_thing.w_obj = WHITENULL; // in order to distinguish midpoints from standard points, later on

			// next point
			llll_appendllll(displayed_points, pt_to_llll(next_point_screen, false), 0, WHITENULL_llll);
		}

		temp = temp->next;
		this_point = next_point;
	}
	
	if (paint_lines_separately) {
		t_rect sourceRect = build_rect(displayed_bounding_rectangle.x - function_bounding_rectangle.x, displayed_bounding_rectangle.y - function_bounding_rectangle.y, 
										displayed_bounding_rectangle.width, displayed_bounding_rectangle.height + 2 * lines_surface_vpad);
		t_rect destRect = build_rect(displayed_bounding_rectangle.x, displayed_bounding_rectangle.y - lines_surface_vpad, 
									  displayed_bounding_rectangle.width, displayed_bounding_rectangle.height + 2 * lines_surface_vpad);
		jgraphics_set_source_rgba(g, 0, 0, 0, 1);
		jgraphics_image_surface_draw(g, lines_surface, sourceRect, destRect);
		jgraphics_surface_destroy(lines_surface);
		jgraphics_destroy(lines_g);
	}
	
	// then we display all the points (so they're on the foreground)
	if (show_points) {
        for (temp = slot ? slot->firstitem : NULL; temp; temp = temp->next) {
			t_pts point = *((t_pts *)temp->item);
			t_pt point_screen;
			double pt_radius = r_ob->function_slot_pt_uradius * r_ob->zoom_y;

			function_xy_values_to_pt(r_ob, nitem, point.x, point.y, slot_number, function_bounding_rectangle, &point_screen);
			
			if (is_pt_in_rectangle_tolerance(point_screen, displayed_bounding_rectangle, 0.1)) {
				
				paint_circle(g, point_line_color, pt_radius - 0.5 < CONST_SLOT_FUNCTION_LINE_WIDTH ? point_line_color : point_inner_color, point_screen.x, point_screen.y, pt_radius, 1.);
				
				if (highlight_selection && temp->selected) // point selected?
					paint_circle_stroken(g, r_ob->j_selection_rgba, point_screen.x, point_screen.y, CONST_SLOT_FUNCTION_POINT_URADIUS * 1.5 * zoom_y, 2.);
				
				if (mouse_hover && !r_ob->hovering_segment && r_ob->hovered_slotitem &&
					(r_ob->hovered_slotitem == temp || (r_ob->hovered_slotitem->selected && temp->selected))){ // mouse hover?
					paint_circle_stroken(g, point_hover_lines_color, point_screen.x, point_screen.y, CONST_SLOT_FUNCTION_POINT_URADIUS * 2.5 * zoom_y, 1.);
					paint_circle_stroken(g, point_hover_lines_color, point_screen.x, point_screen.y, CONST_SLOT_FUNCTION_POINT_URADIUS * 3 * zoom_y, 1.);
				}
			}
		}
	}
			
	// point labels?
	if (paint_point_labels) {
		t_llll *label_rectangles = llll_get();

		// finding appropriate number of decimal points
		long num_decimal_points = 1;
		double range = r_ob->slotinfo[slot_number].slot_range[1] - r_ob->slotinfo[slot_number].slot_range[0];
		if (range <= 0.1)
			num_decimal_points = 3;
		else if (range <= 1)
			num_decimal_points = 2;
		else if (range < 100)
			num_decimal_points = 1;
		else
			num_decimal_points = 0;
		
		
		t_llllelem *temp_pt_el;
        for (temp = slot ? slot->firstitem : NULL, temp_pt_el = displayed_points->l_head; temp && temp_pt_el; temp = temp->next) {
			char label[100];
			double ww, hh;
			double x_pos, y_pos, push_x = 0;
			char direction = 0;
			char hide_label = false;
			t_pts point = *((t_pts *)temp->item);
			t_pt point_screen = llll_to_pt(hatom_getllll(&temp_pt_el->l_hatom));
			
			if (is_pt_in_rectangle(point_screen, displayed_bounding_rectangle)) {
				
				snprintf_zero(label, 100, "%.*f", num_decimal_points, point.y);
				jfont_text_measure(jf_label_font, label, &ww, &hh);
				
				// choosing label direction ( 1 = up, -1 = down, w.r. to the point )
				if (!temp->next && !temp->prev) {
					direction = (point_screen.y > displayed_bounding_rectangle.y + displayed_bounding_rectangle.height / 2. ? 1 : -1); 
				} else if (!temp->next) {
					t_pts prev_point = *((t_pts *)temp->prev->item);
					direction = (prev_point.y > point.y ? -1 : 1);
				} else if (!temp->prev) {
					t_pts next_point = *((t_pts *)temp->next->item);
					direction = (next_point.y > point.y ? -1 : 1);
				} else {
					t_pts prev_point = *((t_pts *)temp->prev->item);
					t_pts next_point = *((t_pts *)temp->next->item);
					if (next_point.y >= point.y && prev_point.y >= point.y) {
						direction = -1;
					} else if (next_point.y <= point.y && prev_point.y <= point.y) {
						direction = 1;
					} else {
						t_pt prev_pt_screen = llll_to_pt(hatom_getllll(&temp_pt_el->l_prev->l_hatom));
						t_pt next_pt_screen = llll_to_pt(hatom_getllll(&temp_pt_el->l_next->l_hatom));
						double slope_next = (next_pt_screen.y - point_screen.y)/(next_pt_screen.x - point_screen.x);
						double slope_prev = (prev_pt_screen.y - point_screen.y)/(prev_pt_screen.x - point_screen.x);
						if (fabs(slope_prev) <= fabs(slope_next)) {
							direction = (prev_pt_screen.y <= point_screen.y ? 1 : -1);
							push_x = CLAMP(notationobj_rescale_with_slope(r_ob, fabs(slope_prev), 0., 2., 0., 0.7, -0.4), 0, 0.7);
						} else {
							direction = (next_pt_screen.y <= point_screen.y ? 1 : -1);
							push_x = -CLAMP(notationobj_rescale_with_slope(r_ob, fabs(slope_next), 0., 2., 0., 0.7, -0.4), 0, 0.7);
						}
					}
				}
				
				y_pos = point_screen.y - CONST_SLOT_FUNCTION_POINT_URADIUS * 1.4 * zoom_y * direction - (direction == 1 ? hh : 0);
				if (!(y_pos >= displayed_bounding_rectangle.y && y_pos <= displayed_bounding_rectangle.y + displayed_bounding_rectangle.height - hh)) {
					direction *= -1;
					y_pos = point_screen.y - CONST_SLOT_FUNCTION_POINT_URADIUS * 1.4 * zoom_y * direction - (direction == 1 ? hh : 0);
					if (y_pos >= displayed_bounding_rectangle.y && y_pos <= displayed_bounding_rectangle.y + displayed_bounding_rectangle.height - hh)
						hide_label = true;
				}
				
				if (!hide_label) {
					
					x_pos = point_screen.x - ww/2. + push_x * ww;
					x_pos = CLAMP(x_pos, displayed_bounding_rectangle.x, displayed_bounding_rectangle.x + displayed_bounding_rectangle.width - ww);
					
					// checking collisions between line segments and the label rectangle
					t_llllelem *aux = temp_pt_el->l_prev;
					t_pt temp_pt_screen = point_screen;
					while (aux) {
						t_pt aux_pt_screen = llll_to_pt(hatom_getllll(&aux->l_hatom));
						double collision_safety_pad = CONST_FUNCTION_SLOT_LABEL_TO_LINE_COLLISION_SAFETY;
						if (line_rectangle_collision(aux_pt_screen.x, aux_pt_screen.y, temp_pt_screen.x, temp_pt_screen.y, 
													 x_pos - collision_safety_pad, y_pos - collision_safety_pad, 
													 ww + 2 * collision_safety_pad, hh + 2 * collision_safety_pad, false)) {
							hide_label = true;
							break;
						}
						aux = aux->l_prev;
						temp_pt_screen = aux_pt_screen;
						if (temp_pt_screen.x < x_pos)
							break;
					}
					
					aux = temp_pt_el->l_next;
					temp_pt_screen = point_screen;
					while (!hide_label && aux) {
						t_pt aux_pt_screen = llll_to_pt(hatom_getllll(&aux->l_hatom));
						double collision_safety_pad = CONST_FUNCTION_SLOT_LABEL_TO_LINE_COLLISION_SAFETY;
						if (line_rectangle_collision(temp_pt_screen.x, temp_pt_screen.y, aux_pt_screen.x, aux_pt_screen.y, 
													 x_pos - collision_safety_pad, y_pos - collision_safety_pad, 
													 ww + 2 * collision_safety_pad, hh + 2 *  - collision_safety_pad, false)) {
							hide_label = true;
							break;
						}
						aux = aux->l_next;
						temp_pt_screen = aux_pt_screen;
						if (temp_pt_screen.x > x_pos + ww)
							break;
					}
					
					
					// checking collisions between the label rectangle and previous label rectangles
					if (!hide_label) {
						aux = label_rectangles->l_tail;
						while (aux) {
							t_rect aux_rect = llll_to_rect(hatom_getllll(&aux->l_hatom));
							if (rectangle_rectangle_collision(aux_rect.x, aux_rect.y, aux_rect.width, aux_rect.height, 
															  x_pos - CONST_FUNCTION_SLOT_LABEL_TO_LABEL_COLLISION_SAFETY, y_pos - CONST_FUNCTION_SLOT_LABEL_TO_LABEL_COLLISION_SAFETY, 
															  ww + 2 * CONST_FUNCTION_SLOT_LABEL_TO_LABEL_COLLISION_SAFETY, hh + 2 * CONST_FUNCTION_SLOT_LABEL_TO_LABEL_COLLISION_SAFETY)) {
								hide_label = true;
								break;
							}
							aux = aux->l_prev;
							if (aux_rect.x + aux_rect.width + 5 * zoom_y < x_pos)
								break;
						}
					}
				}
				
				if (!hide_label) {
					t_llll *this_rect_llll = llll_get();
					llll_appenddouble(this_rect_llll, x_pos, 0, WHITENULL_llll);
					llll_appenddouble(this_rect_llll, y_pos, 0, WHITENULL_llll);
					llll_appenddouble(this_rect_llll, ww, 0, WHITENULL_llll);
					llll_appenddouble(this_rect_llll, hh, 0, WHITENULL_llll);
					llll_appendllll(label_rectangles, this_rect_llll, 0, WHITENULL_llll);
					
					write_text(g, jf_label_font, temp->selected ? r_ob->j_selection_rgba : point_line_color, label, x_pos, y_pos, displayed_bounding_rectangle.x + displayed_bounding_rectangle.width - x_pos, displayed_bounding_rectangle.y + displayed_bounding_rectangle.height - y_pos, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
				}
				
			}
			
			// updating displayed point element
			temp_pt_el = temp_pt_el->l_next;
			while (temp_pt_el && temp_pt_el->l_thing.w_obj == WHITENULL)
				temp_pt_el = temp_pt_el->l_next;
		}
		llll_free(label_rectangles);
	}
	
	llll_free(displayed_points);
}

void paint_3dfunction_in_slot_win(t_notation_obj *r_ob, t_jgraphics* g, t_rect function_bounding_rectangle, t_rect displayed_bounding_rectangle, 
								  t_notation_item *nitem, long slot_number,
								  t_jrgba slot_color, double new_alpha, char show_points, char can_change_luminosity, char can_change_alpha, 
								  char mouse_hover, double slot_zoom, char paint_lines_separately, char trim_overflowing_lines){
	
	t_pt this_point_screen, next_point_screen; 
	t_slotitem *temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number);
	t_pts3d this_point, next_point;

	double zoom_y = r_ob->zoom_y * (slot_zoom/ 100.);

	t_jsurface *lines_surface = NULL;
	t_jgraphics *lines_g = NULL;
	
	const double PAD_X = trim_overflowing_lines ? 0 : 30 * zoom_y;
	const double PAD_Y = 30 * zoom_y;
	if (paint_lines_separately) {
		lines_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, function_bounding_rectangle.width + 2 * PAD_X, function_bounding_rectangle.height + 2 * PAD_Y);
		lines_g = jgraphics_create(lines_surface);
	}

	// first: all planes
	const double L = CONST_SLOT_3DFUNCTION_ZDIM_USIZE * zoom_y;
	const double alpha = CONST_SLOT_3DFUNCTION_ZDIM_ANGLE;
	t_jrgba border_color = change_alpha(get_grey(0.8), 0.65);
	t_jrgba fill_color = change_alpha(get_grey(0.8), 0.25);
	t_jrgba hovered_fill_color = change_alpha(get_grey(0.55), 0.25);

	temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); // first point
	while (temp) {
		t_pts3d this_point = *((t_pts3d *)temp->item);
		function_xy_values_to_pt(r_ob, nitem, this_point.x, this_point.y, slot_number, function_bounding_rectangle, &this_point_screen);

		if (is_pt_in_rectangle_tolerance(this_point_screen, displayed_bounding_rectangle, 0.1)) {
			double x1 = this_point_screen.x;
			
			paint_quadrilater(g, border_color, r_ob->hovered_slotitem == temp ? hovered_fill_color : fill_color, x1, function_bounding_rectangle.y, x1, function_bounding_rectangle.y + function_bounding_rectangle.height, 
							  x1 - L * sin(alpha), function_bounding_rectangle.y + function_bounding_rectangle.height + L * cos(alpha), x1 - L * sin(alpha), 
							  function_bounding_rectangle.y + L * cos(alpha), 0.5);
		}
		temp = temp->next;
	}

	// then we display all the lines
	temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); // first point
	if (temp) 
		this_point = *((t_pts3d *)temp->item);
	else {
		this_point.x = 0; 
		this_point.y = 0;
		this_point.z = 0;
	}

	while (temp && temp->next) {
		t_jrgba line_color = slot_color;
		next_point = *((t_pts3d *)temp->next->item);
		
		function_xyz_values_to_pt(r_ob, nitem, this_point.x, this_point.y, this_point.z, slot_number, function_bounding_rectangle, &this_point_screen, slot_zoom);
		function_xyz_values_to_pt(r_ob, nitem, next_point.x, next_point.y, next_point.z, slot_number, function_bounding_rectangle, &next_point_screen, slot_zoom);
		
		if (can_change_luminosity) 
			line_color = change_luminosity(line_color, 0.3);
		if (can_change_alpha) 
			line_color = change_alpha(line_color, new_alpha);
//		notationobj_paint_curve(r_ob, g, line_color, this_point_screen.x, this_point_screen.y, next_point_screen.x, next_point_screen.y, next_point.slope, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);

		double start_curve_width = CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y * notationobj_rescale_with_slope(r_ob, this_point.z, r_ob->slotinfo[slot_number].slot_zrange[0], r_ob->slotinfo[slot_number].slot_zrange[1], 0.5, 2., r_ob->slotinfo[slot_number].slot_zrange_par);
		double end_curve_width = CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y * notationobj_rescale_with_slope(r_ob, next_point.z, r_ob->slotinfo[slot_number].slot_zrange[0], r_ob->slotinfo[slot_number].slot_zrange[1], 0.5, 2., r_ob->slotinfo[slot_number].slot_zrange_par);

		if (paint_lines_separately)
			notationobj_paint_doublewidth_curve(r_ob, lines_g, line_color, this_point_screen.x - function_bounding_rectangle.x + PAD_X, this_point_screen.y - function_bounding_rectangle.y + PAD_Y, next_point_screen.x - function_bounding_rectangle.x + PAD_X, next_point_screen.y - function_bounding_rectangle.y + PAD_Y, next_point.slope, start_curve_width, end_curve_width);
		else
			notationobj_paint_doublewidth_curve(r_ob, g, line_color, this_point_screen.x, this_point_screen.y, next_point_screen.x, next_point_screen.y, next_point.slope, start_curve_width, end_curve_width);
		
		temp = temp->next;
		this_point = next_point;
	}
	
	if (paint_lines_separately) {
		jgraphics_set_source_rgba(g, 0, 0, 0, 1);
		jgraphics_image_surface_draw(g, lines_surface, build_rect(displayed_bounding_rectangle.x - function_bounding_rectangle.x, displayed_bounding_rectangle.y - function_bounding_rectangle.y, displayed_bounding_rectangle.width + 2 * PAD_X, displayed_bounding_rectangle.height + 2 * PAD_Y), 
									 build_rect(displayed_bounding_rectangle.x - PAD_X, displayed_bounding_rectangle.y - PAD_Y, displayed_bounding_rectangle.width + 2 * PAD_X, displayed_bounding_rectangle.height + 2 * PAD_Y));
		jgraphics_surface_destroy(lines_surface);
		jgraphics_destroy(lines_g);
	}

	// then we display all the points (so they're on the foreground)
	if (show_points) {
		temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); // first point
		while (temp) {
			t_pts3d point = *((t_pts3d *)temp->item);
			t_pt point_screen, test_point_screen;
			t_jrgba point_color = slot_color;
			double radius = CONST_SLOT_FUNCTION_POINT_URADIUS * zoom_y * notationobj_rescale_with_slope(r_ob, point.z, r_ob->slotinfo[slot_number].slot_zrange[0], r_ob->slotinfo[slot_number].slot_zrange[1], 0.5, 2., r_ob->slotinfo[slot_number].slot_zrange_par);

			function_xyz_values_to_pt(r_ob, nitem, point.x, point.y, point.z, slot_number, function_bounding_rectangle, &point_screen, slot_zoom);
			function_xy_values_to_pt(r_ob, nitem, point.x, point.y, slot_number, function_bounding_rectangle, &test_point_screen);
			
			if (is_pt_in_rectangle_tolerance(test_point_screen, displayed_bounding_rectangle, 0.1)) {
				if (can_change_luminosity) 
					point_color = change_luminosity(point_color, 2.9);
				if (can_change_alpha) 
					point_color = change_alpha(point_color, new_alpha);
				paint_circle_filled(g, point_color, point_screen.x, point_screen.y, radius);
				
				point_color = slot_color;
				if (can_change_luminosity) 
					point_color = change_luminosity(point_color, 0.2);
				if (can_change_alpha) 
					point_color = change_alpha(point_color, new_alpha);
				paint_circle_stroken(g, point_color, point_screen.x, point_screen.y, radius, 1.);
				
				
				// mouse_hover?
				if (mouse_hover && r_ob->hovered_slotitem == temp){
					if (can_change_luminosity) 
						point_color = change_luminosity(point_color, 2);
					paint_circle_stroken(g, point_color, point_screen.x, point_screen.y, radius * 2.5, 1.);
					paint_circle_stroken(g, point_color, point_screen.x, point_screen.y, radius * 3, 1.);
				}
			}
			temp = temp->next;
		}
	}
}

void paint_spatfunction_in_slot_win(t_notation_obj *r_ob, t_jgraphics* g, t_rect function_bounding_rectangle, t_rect displayed_bounding_rectangle, t_notation_item *nitem, long slot_number,
									t_jrgba slot_color, t_jrgba slot_textcolor, double new_alpha, char show_points, char can_change_line_luminosity, char can_change_point_luminosity, 
									char can_change_alpha, double point_radius, double slot_zoom, char paint_lines_separately, char trim_overflowing_lines){
	double slot_max, slot_min, slot_domain_max, slot_domain_min;
	t_slotitem *temp;
	t_spatpt this_point, next_point;
	
	double zoom_y = r_ob->zoom_y * (slot_zoom / 100.);
	
	slot_max = r_ob->slotinfo[slot_number].slot_range[1]; slot_min = r_ob->slotinfo[slot_number].slot_range[0]; // max and min values allowed for the slots
	slot_domain_max = r_ob->slotinfo[slot_number].slot_domain[1]; slot_domain_min = r_ob->slotinfo[slot_number].slot_domain[0]; // max and min values allowed for the slots
	
	t_jsurface *lines_surface = NULL;
	t_jgraphics *lines_g = NULL;
	
	const double PAD_X = trim_overflowing_lines ? 0 : 20 * zoom_y;
	const double PAD_Y = 20 * zoom_y;
	if (paint_lines_separately) {
		lines_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, function_bounding_rectangle.width + 2 * PAD_X, function_bounding_rectangle.height + 2 * PAD_Y);
		lines_g = jgraphics_create(lines_surface);
	}

	// first we display all the lines
	temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); // first point
	
	if (temp) 
		this_point = *((t_spatpt *)temp->item);
	else {
		this_point.t = 0;
		this_point.radius = 0;
		this_point.interp = 0;
		this_point.angle = 0;
	}
	while (temp && temp->next) {
		char direction, turns; 
		t_jrgba line_color = slot_color;
        t_pt this_point_screen, next_point_screen;
		next_point = *((t_spatpt *)temp->next->item);

        function_xy_values_to_pt(r_ob, nitem, this_point.t, this_point.radius, slot_number, function_bounding_rectangle, &this_point_screen);
        function_xy_values_to_pt(r_ob, nitem, next_point.t, next_point.radius, slot_number, function_bounding_rectangle, &next_point_screen);
        
		// how many turns do we have to draw?
		
		if (next_point.angle - this_point.angle > 0) 
			direction = -1; 
		else if (next_point.angle - this_point.angle < 0) 
			direction = 1; 
		else 
			direction = 0;
		turns = floor(fabs(next_point.angle - this_point.angle)/ (2 * M_PI));
		
		if (can_change_line_luminosity) line_color = change_luminosity(line_color, 0.3);
		if (can_change_alpha) line_color = change_alpha(line_color, new_alpha);

		if ((direction == 0) || (next_point_screen.x == this_point_screen.x) || (next_point.interp == k_SPAT_INTERPOLATION_SEGMENT)) { // easy case: just a segment
			if (paint_lines_separately)
				paint_line(lines_g, line_color, this_point_screen.x - function_bounding_rectangle.x + PAD_X, this_point_screen.y - function_bounding_rectangle.y + PAD_Y, next_point_screen.x - function_bounding_rectangle.x + PAD_X, next_point_screen.y - function_bounding_rectangle.y + PAD_Y, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
			else
				paint_line(g, line_color, this_point_screen.x, this_point_screen.y, next_point_screen.x, next_point_screen.y, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
		} else {
			char j;
			double const H = 18 * zoom_y;
			double const P = 0.4;
			double D = sqrt((next_point_screen.x - this_point_screen.x) * (next_point_screen.x - this_point_screen.x) + (next_point_screen.y - this_point_screen.y) * (next_point_screen.y - this_point_screen.y));
			double theta = atan((next_point_screen.y - this_point_screen.y) / (next_point_screen.x - this_point_screen.x));
			double turn_x_step = D / (turns+1);
			t_pt this_turn_p0, this_turn_p1, this_turn_p2, this_turn_p3, this_turn_h1, this_turn_h2;

			jgraphics_set_source_jrgba(paint_lines_separately ? lines_g : g, &line_color);
#ifdef BACH_MAX
			jgraphics_set_line_width(paint_lines_separately ? lines_g : g, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y); 
			if (paint_lines_separately)
				jgraphics_move_to(lines_g, this_point_screen.x - function_bounding_rectangle.x + PAD_X, this_point_screen.y - function_bounding_rectangle.y + PAD_Y);
			else
				jgraphics_move_to(g, this_point_screen.x, this_point_screen.y);
#endif
#ifdef BACH_JUCE
			Path p;
			p.startNewSubPath(this_point_screen.x, this_point_screen.y);
#endif
			for (j = 0; j <= turns; j++) {
				double new_x, new_y;
				if (j == 0) 
					this_turn_p0.y = 0;
				else 
					this_turn_p0.y = 0.5 * H * direction;
				if (j == 0) 
					this_turn_p1.x = 0;
				else 
					this_turn_p1.x = j * turn_x_step + P * turn_x_step;
				if (j == turns) 
					this_turn_p2.x = D;
				else 
					this_turn_p2.x = (j+1) * turn_x_step - P * turn_x_step;
				if (j == turns) 
					this_turn_p3.y = 0;
				else 
					this_turn_p3.y = 0.5 * H * direction;
				if (j == turns) 
					this_turn_p3.x = D;
				else 
					this_turn_p3.x = (j+1) * turn_x_step;
				
				this_turn_p0.x = 0;
				this_turn_p1.y = H * direction;
				this_turn_p2.y = H * direction;
				// points for the little loop
				this_turn_h1.x = (j+1) * turn_x_step + P * turn_x_step;
				this_turn_h2.x = (j+1) * turn_x_step - P * turn_x_step;
				this_turn_h1.y = this_turn_h2.y = 0;
				
				// gotta rotate the points
				new_x = this_turn_p0.x * cos(theta) - this_turn_p0.y * sin(theta); 
				new_y = this_turn_p0.x * sin(theta) + this_turn_p0.y * cos(theta); 
				this_turn_p0.x = new_x; this_turn_p0.y = new_y;
				new_x = this_turn_p1.x * cos(theta) - this_turn_p1.y * sin(theta); 
				new_y = this_turn_p1.x * sin(theta) + this_turn_p1.y * cos(theta); 
				this_turn_p1.x = new_x; this_turn_p1.y = new_y;
				new_x = this_turn_p2.x * cos(theta) - this_turn_p2.y * sin(theta); 
				new_y = this_turn_p2.x * sin(theta) + this_turn_p2.y * cos(theta); 
				this_turn_p2.x = new_x; this_turn_p2.y = new_y;
				new_x = this_turn_p3.x * cos(theta) - this_turn_p3.y * sin(theta); 
				new_y = this_turn_p3.x * sin(theta) + this_turn_p3.y * cos(theta); 
				this_turn_p3.x = new_x; this_turn_p3.y = new_y;
				new_x = this_turn_h1.x * cos(theta) - this_turn_h1.y * sin(theta); 
				new_y = this_turn_h1.x * sin(theta) + this_turn_h1.y * cos(theta); 
				this_turn_h1.x = new_x; this_turn_h1.y = new_y;
				new_x = this_turn_h2.x * cos(theta) - this_turn_h2.y * sin(theta); 
				new_y = this_turn_h2.x * sin(theta) + this_turn_h2.y * cos(theta); 
				this_turn_h2.x = new_x; this_turn_h2.y = new_y;
				
				// gotta shift the points
				this_turn_p0.x += this_point_screen.x; this_turn_p1.x += this_point_screen.x; this_turn_p2.x += this_point_screen.x; this_turn_p3.x += this_point_screen.x;
				this_turn_p0.y += this_point_screen.y; this_turn_p1.y += this_point_screen.y; this_turn_p2.y += this_point_screen.y; this_turn_p3.y += this_point_screen.y;
				this_turn_h1.x += this_point_screen.x; this_turn_h2.x += this_point_screen.x;
				this_turn_h1.y += this_point_screen.y; this_turn_h2.y += this_point_screen.y;
				
				// We paint the points for debug
				/*						paint_circle_filled((t_notation_obj *) x, g, get_grey(0.), this_turn_p0.x, this_turn_p0.y, 1.);
				 paint_circle_filled((t_notation_obj *) x, g, get_grey(0.), this_turn_p1.x, this_turn_p1.y, 1.);
				 paint_circle_filled((t_notation_obj *) x, g, get_grey(0.), this_turn_p2.x, this_turn_p2.y, 1.);
				 paint_circle_filled((t_notation_obj *) x, g, get_grey(0.), this_turn_p3.x, this_turn_p3.y, 1.);*/
				
				// We paint the line (actually: a Bézier curve with 2 internal control points)
#ifdef BACH_MAX
				if (paint_lines_separately)
					jgraphics_curve_to(lines_g, this_turn_p1.x - function_bounding_rectangle.x + PAD_X, this_turn_p1.y - function_bounding_rectangle.y + PAD_Y, this_turn_p2.x - function_bounding_rectangle.x + PAD_X, this_turn_p2.y - function_bounding_rectangle.y + PAD_Y, this_turn_p3.x - function_bounding_rectangle.x + PAD_X, this_turn_p3.y - function_bounding_rectangle.y + PAD_Y);
				else
					jgraphics_curve_to(g, this_turn_p1.x, this_turn_p1.y, this_turn_p2.x, this_turn_p2.y, this_turn_p3.x, this_turn_p3.y);
#endif
#ifdef BACH_JUCE
				p.cubicTo(this_turn_p1.x, this_turn_p1.y, this_turn_p2.x, this_turn_p2.y, this_turn_p3.x, this_turn_p3.y);
#endif
				// draw small circle arc if needed
				if (j < turns) {
#ifdef BACH_MAX
					if (paint_lines_separately)
						jgraphics_curve_to(lines_g, this_turn_h1.x - function_bounding_rectangle.x + PAD_X, this_turn_h1.y - function_bounding_rectangle.y + PAD_Y, this_turn_h2.x - function_bounding_rectangle.x + PAD_X, this_turn_h2.y - function_bounding_rectangle.y + PAD_Y, this_turn_p3.x - function_bounding_rectangle.x + PAD_X, this_turn_p3.y - function_bounding_rectangle.y + PAD_Y);
					else
						jgraphics_curve_to(g, this_turn_h1.x, this_turn_h1.y, this_turn_h2.x, this_turn_h2.y, this_turn_p3.x, this_turn_p3.y);
#endif
#ifdef BACH_JUCE
					p.cubicTo(this_turn_h1.x, this_turn_h1.y, this_turn_h2.x, this_turn_h2.y, this_turn_p3.x, this_turn_p3.y);
#endif
				} else {
					;
					//							// small arrow
					//							this_turn_x2 -= CONST_SLOT_SPAT_CIRCLE_URADIUS * zoom_y;
					//							paint_line((t_notation_obj *) x, g, line_color, this_turn_x2, this_turn_y2, this_turn_x2 - 3 * zoom_y, this_turn_y2 - 1.5 * zoom_y, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
					//							paint_line((t_notation_obj *) x, g, line_color, this_turn_x2, this_turn_y2, this_turn_x2 - 3 * zoom_y, this_turn_y2 + 1.5 * zoom_y, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
				}
			}
#ifdef BACH_MAX
			jgraphics_stroke(paint_lines_separately ? lines_g : g);	
#endif
#ifdef BACH_JUCE
			g->strokePath(p, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
#endif
		}
		
		temp = temp->next;
		this_point = next_point;
	}

	if (paint_lines_separately) {
		jgraphics_set_source_rgba(g, 0, 0, 0, 1);
		jgraphics_image_surface_draw(g, lines_surface, build_rect(displayed_bounding_rectangle.x - function_bounding_rectangle.x, displayed_bounding_rectangle.y - function_bounding_rectangle.y, displayed_bounding_rectangle.width + 2 * PAD_X, displayed_bounding_rectangle.height + 2 * PAD_Y), 
									 build_rect(displayed_bounding_rectangle.x - PAD_X, displayed_bounding_rectangle.y - PAD_Y, displayed_bounding_rectangle.width + 2 * PAD_X, displayed_bounding_rectangle.height + 2 * PAD_Y));
		jgraphics_surface_destroy(lines_surface);
		jgraphics_destroy(lines_g);
	}
	
	// then we display all the points (so they're on the foreground)
	temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); // first point
	while (temp) {
		t_spatpt point = *((t_spatpt *)temp->item);
        t_pt point_screen;
        
        function_xy_values_to_pt(r_ob, nitem, point.t, point.radius, slot_number, function_bounding_rectangle, &point_screen);

        double angle_mod_2_pi, this_sin, this_cos, tick_end_x, tick_end_y;
 
		if (is_pt_in_rectangle_tolerance(build_pt(point_screen.x, point_screen.y), displayed_bounding_rectangle, 1.)) {
			paint_circle(g, slot_textcolor, get_grey(1), point_screen.x, point_screen.y, point_radius * zoom_y, 1);
			
			angle_mod_2_pi = point.angle - floor(point.angle/(2 * M_PI)) * 2 * M_PI;
			this_sin = sin(angle_mod_2_pi); this_cos = cos(angle_mod_2_pi);
			tick_end_x = point_screen.x + point_radius * 0.85 * zoom_y * this_sin;
			tick_end_y = point_screen.y - point_radius * 0.85 * zoom_y * this_cos;
			paint_line(g, slot_textcolor, point_screen.x, point_screen.y, tick_end_x, tick_end_y, 1.);
		}
			
		temp = temp->next;
	}
	
}


void paint_filtergraph_in_slot_win(t_notation_obj *r_ob, t_jgraphics* g, t_rect bounding_rectangle, t_notation_item *nitem, long slot_number,
								   t_jrgba slot_color, double new_alpha, char can_change_luminosity, 
								   char can_change_alpha, char paint_bandwidth, char write_coefficients, char paint_0db_line, double slot_zoom){
	
	double slot_window_active_x1 = bounding_rectangle.x, slot_window_active_y1 = bounding_rectangle.y;
	double slot_window_active_width = bounding_rectangle.width, slot_window_active_height = bounding_rectangle.height;
	double slot_max = r_ob->slotinfo[slot_number].slot_range[1], slot_min = r_ob->slotinfo[slot_number].slot_range[0];
	double slot_domain_max = r_ob->slotinfo[slot_number].slot_domain[1], slot_domain_min = r_ob->slotinfo[slot_number].slot_domain[0];
	t_biquad *bqd = (notation_item_get_slot_firstitem(r_ob, nitem, slot_number) ? (t_biquad *)notation_item_get_slot_firstitem(r_ob, nitem, slot_number)->item : NULL);
	
	double zoom_y = r_ob->zoom_y * (slot_zoom / 100.);
	
	if (bqd) {
		t_jrgba line_color = slot_color;
		t_jrgba secondary_lines_color;
		t_jrgba fillcolor;
		t_jpath *lines_only = NULL;
		double cutoff_freq_rel_x = notationobj_rescale_with_slope_inv(r_ob, bqd->cutoff_freq, slot_domain_min, slot_domain_max, 0, slot_window_active_width, r_ob->slotinfo[slot_number].slot_domain_par);
		long num_steps_before_cutoff_freq = round(cutoff_freq_rel_x/CONST_SLOT_FILTER_NUM_PIXELS_PER_STEP);
		double step_px = num_steps_before_cutoff_freq > 0 ? cutoff_freq_rel_x/num_steps_before_cutoff_freq : 0;
		long num_steps = num_steps_before_cutoff_freq > 0 ? ceil(slot_window_active_width/step_px) : 0;
		long i;
		double cur, prev_y = 0, prev_cur = 0;
		char already_painting = false, prev_pos_y_wr_to_screen = -1;
		double first_entered_x = slot_window_active_x1, prev_response = slot_min;

		if (num_steps_before_cutoff_freq < 1){
			num_steps = round(slot_window_active_width/CONST_SLOT_FILTER_NUM_PIXELS_PER_STEP);
			step_px = slot_window_active_width/num_steps;
		}
		
		if (can_change_luminosity) 
			line_color = change_luminosity(line_color, 0.3);
		if (can_change_alpha) 
			line_color = change_alpha(line_color, new_alpha);
		
		secondary_lines_color = change_luminosity(line_color, 1.9);
		fillcolor = change_alpha(get_grey(0.5), 0.2);
		
		// painting 0db line
		if (paint_0db_line){
			double central_y = 2 * slot_window_active_y1 + slot_window_active_height - notationobj_rescale_with_slope_inv(r_ob, 0, slot_min, slot_max, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height, r_ob->slotinfo[slot_number].slot_range_par);
			paint_line(g, secondary_lines_color, slot_window_active_x1, central_y, slot_window_active_x1 + slot_window_active_width, central_y, 0.5);
		}
		
		jgraphics_new_path(g);
		for (i = 0, cur = 0; i <= num_steps; i++, cur += step_px) {
			double this_freq = notationobj_rescale_with_slope(r_ob, cur, 0, slot_window_active_width, slot_domain_min, slot_domain_max, r_ob->slotinfo[slot_number].slot_domain_par);
			double this_response = gain_response_dB(this_freq, r_ob->sampling_freq, bqd->a1, bqd->a2, bqd->b0, bqd->b1, bqd->b2);
			double this_y;
			char pos_y_wr_to_screen = 0; // this is -1 if the point is under the window bottom line 

			if (cur > slot_window_active_width)
				cur = slot_window_active_width;
			
			if (this_response > slot_max)
				pos_y_wr_to_screen = 0;
			else if (this_response < slot_min)
				pos_y_wr_to_screen = -1;
			
			if (this_response <= slot_min)
				this_y = slot_window_active_y1 + slot_window_active_height;
			else if (this_response >= slot_max)
				this_y = slot_window_active_y1;
			else
				this_y = 2 * slot_window_active_y1 + slot_window_active_height - notationobj_rescale_with_slope_inv(r_ob, this_response, slot_min, slot_max, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height, r_ob->slotinfo[slot_number].slot_range_par);
			this_y = CLAMP(this_y, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height);
			
			if (prev_pos_y_wr_to_screen != 0 && pos_y_wr_to_screen == 0 && !already_painting) {
				first_entered_x = slot_window_active_x1 + cur;
				if (i == 0)
					jgraphics_move_to(g, slot_window_active_x1 + cur, this_y);
				else {
					double prev_true_pty = 2 * slot_window_active_y1 + slot_window_active_height - notationobj_rescale_with_slope_inv(r_ob, prev_response, slot_min, slot_max, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height, r_ob->slotinfo[slot_number].slot_range_par);
					double ptx = cur - (cur - prev_cur)/(1 + prev_true_pty - (slot_window_active_y1 + slot_window_active_height));
					jgraphics_move_to(g, slot_window_active_x1 + ptx, slot_window_active_y1 + slot_window_active_height);
					jgraphics_line_to(g, slot_window_active_x1 + cur, this_y);
				}
				already_painting = true;
			} else if (pos_y_wr_to_screen == 0)
				jgraphics_line_to(g, slot_window_active_x1 + cur, this_y);
			
			if (already_painting && (pos_y_wr_to_screen != 0 || i == num_steps)){
				if (i == num_steps && pos_y_wr_to_screen == 0) {
					lines_only = jgraphics_copy_path(g);
					jgraphics_line_to(g, slot_window_active_x1 + (pos_y_wr_to_screen == 0 ? cur : prev_cur), slot_window_active_y1 + slot_window_active_height);
				} else {
					double this_true_pty = 2 * slot_window_active_y1 + slot_window_active_height - notationobj_rescale_with_slope_inv(r_ob, this_response, slot_min, slot_max, slot_window_active_y1, slot_window_active_y1 + slot_window_active_height, r_ob->slotinfo[slot_number].slot_range_par);
					double ptx = pos_y_wr_to_screen == 0 ? cur : prev_cur + (cur - prev_cur)/(1 + this_true_pty - (slot_window_active_y1 + slot_window_active_height));
					jgraphics_line_to(g, slot_window_active_x1 + ptx, slot_window_active_y1 + slot_window_active_height);
					lines_only = jgraphics_copy_path(g);
				}
				jgraphics_line_to(g, first_entered_x, slot_window_active_y1 + slot_window_active_height);
				jgraphics_close_path(g);
				
				
				// path has ended: 
				jgraphics_set_line_width(g, CONST_SLOT_FUNCTION_LINE_WIDTH * zoom_y);
				jgraphics_set_source_jrgba(g, &fillcolor);
				jgraphics_fill(g); 
				if (lines_only) {
					jgraphics_append_path(g, lines_only);
					jgraphics_set_source_jrgba(g, &line_color);
					jgraphics_stroke(g); 
					jgraphics_path_destroy(lines_only);
				} 
				already_painting = false;
			}
			
			prev_pos_y_wr_to_screen = pos_y_wr_to_screen; 
			prev_response = this_response;
			prev_y = this_y;
			prev_cur = cur;
		}
		
		// painting bandwidth
		if (paint_bandwidth && bqd->filter_type != k_FILTER_NONE && bqd->filter_type != k_FILTER_DISPLAY) {
			t_jrgba bandwidth_color = build_jrgba(0.5, 0, 0, 1);
			double bandwidth = 0;
			if (bqd->filter_type == k_FILTER_BANDPASS || bqd->filter_type == k_FILTER_BANDSTOP || bqd->filter_type == k_FILTER_LOWPASS || 
				bqd->filter_type == k_FILTER_HIGHPASS || bqd->filter_type == k_FILTER_PEAKNOTCH || bqd->filter_type == k_FILTER_ALLPASS)
				bandwidth = bqd->bandwidth;
			else if (bqd->filter_type == k_FILTER_LOWSHELF || bqd->filter_type == k_FILTER_HIGHSHELF)
				bandwidth = bqd->shelfslope;
			else
				bandwidth = bqd->cutoff_freq /(2*bqd->Q);
			
			bqd->bandwidth_x2 = slot_window_active_x1 + notationobj_rescale_with_slope_inv(r_ob, bqd->cutoff_freq * pow(2, bandwidth), slot_domain_min, slot_domain_max, 0, slot_window_active_width, r_ob->slotinfo[slot_number].slot_domain_par);
			bqd->bandwidth_x1 = slot_window_active_x1 + notationobj_rescale_with_slope_inv(r_ob, bqd->cutoff_freq * pow(2, -bandwidth), slot_domain_min, slot_domain_max, 0, slot_window_active_width, r_ob->slotinfo[slot_number].slot_domain_par);
			bqd->bandwidth_x1 = CLAMP(bqd->bandwidth_x1, slot_window_active_x1, slot_window_active_x1 + slot_window_active_width);
			bqd->bandwidth_x2 = CLAMP(bqd->bandwidth_x2, slot_window_active_x1, slot_window_active_x1 + slot_window_active_width);
			paint_rectangle(g, bandwidth_color, change_alpha(bandwidth_color, 0.1), bqd->bandwidth_x1, slot_window_active_y1, bqd->bandwidth_x2 - bqd->bandwidth_x1, slot_window_active_height, 0);
			paint_line(g, change_alpha(bandwidth_color, 0.8), bqd->bandwidth_x2, slot_window_active_y1, bqd->bandwidth_x2, slot_window_active_y1 + slot_window_active_height, 0.5);
			paint_line(g, change_alpha(bandwidth_color, 0.8), bqd->bandwidth_x1, slot_window_active_y1, bqd->bandwidth_x1, slot_window_active_y1 + slot_window_active_height, 0.5);
		}
		
		
		// painting coefficients
		if (write_coefficients) {
			t_jfont *textfont = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(5.0 * zoom_y));
			char text[1000];
			snprintf_zero(text, 1000, "%.2f, %.2f, %.2f, %.2f, %.2f", bqd->b0, bqd->b1, bqd->b2, bqd->a1, bqd->a2);
			write_text(g, textfont, line_color, text, slot_window_active_x1, slot_window_active_y1, slot_window_active_width, 
										  slot_window_active_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
			jfont_destroy_debug(textfont);
		}
	} else {
		// no data
		
	}
}



void paint_dynfiltergraph_in_slot_win(t_notation_obj *r_ob, t_jgraphics* g, t_rect dynfilter_bounding_rectangle, t_rect displayed_bounding_rectangle,
									  t_notation_item *nitem, long slot_number, t_jrgba slot_color, double new_alpha, char can_change_luminosity,
									  char can_change_alpha, char paint_markers, double slot_zoom){
	
	double slot_max = r_ob->slotinfo[slot_number].slot_range[1], slot_min = r_ob->slotinfo[slot_number].slot_range[0];
	double slot_domain_min = r_ob->slotinfo[slot_number].slot_domain[0];
	double slot_domain_max = r_ob->slotinfo[slot_number].slot_domain[1];
	double slot_domain_min_window = slot_domain_min;
	double slot_domain_max_window = slot_domain_max;
	t_slotitem *bqditem = notation_item_get_slot_firstitem(r_ob, nitem, slot_number);
	t_biquad *bqd = (bqditem ? (t_biquad *)bqditem->item : NULL);
	double t = 0, t_cur = 0;
	long num_t_steps = round(displayed_bounding_rectangle.width/CONST_SLOT_DYNFILTER_NUM_H_PIXELS_PER_STEP);
	double step_t_px = displayed_bounding_rectangle.width/num_t_steps;
	double domain = slot_domain_max - slot_domain_min;
	t_jrgba grey = get_grey(0.9);
	t_jrgba black = get_grey(0.);

	double zoom_y = r_ob->zoom_y * (slot_zoom / 100.);

	slot_domain_min_window = notationobj_rescale_with_slope(r_ob, displayed_bounding_rectangle.x, dynfilter_bounding_rectangle.x, dynfilter_bounding_rectangle.x + dynfilter_bounding_rectangle.width, slot_domain_min, slot_domain_max, r_ob->slotinfo[slot_number].slot_domain_par);
	slot_domain_max_window = notationobj_rescale_with_slope(r_ob, displayed_bounding_rectangle.x + displayed_bounding_rectangle.width, dynfilter_bounding_rectangle.x, dynfilter_bounding_rectangle.x + dynfilter_bounding_rectangle.width, slot_domain_min, slot_domain_max, r_ob->slotinfo[slot_number].slot_domain_par);
	
	if (!bqd)
		return;
	
	for (t = 0, t_cur = 0; t < num_t_steps; t++, t_cur += step_t_px) {
		double time = notationobj_rescale_with_slope(r_ob, t, 0, num_t_steps, slot_domain_min_window, slot_domain_max_window, r_ob->slotinfo[slot_number].slot_domain_par);
		long num_steps = round(displayed_bounding_rectangle.width/CONST_SLOT_DYNFILTER_NUM_V_PIXELS_PER_STEP);
		double step_px = displayed_bounding_rectangle.width/num_steps;
		long i;
		double cur;
		t_biquad interp_bqd;
		
		while (bqditem->next && ((t_biquad *)bqditem->next->item)->t < time/domain) {
			bqditem = bqditem->next;
			bqd = (t_biquad *)bqditem->item;
		}
		
		interp_bqd = (bqditem->next && bqd->t < time/domain ? interpolate_biquad(r_ob, *bqd, *((t_biquad *)bqditem->next->item), time/domain, r_ob->dynfilter_interp_mode) : *bqd);
		
		for (i = 0, cur = 0; i < num_steps; i++, cur += step_px) {
			double this_freq = notationobj_rescale_with_slope(r_ob, cur, 0, displayed_bounding_rectangle.height, slot_min, slot_max, r_ob->slotinfo[slot_number].slot_range_par);
			double this_response_dB = CLAMP(gain_response_dB(this_freq, r_ob->sampling_freq, interp_bqd.a1, interp_bqd.a2, interp_bqd.b0, interp_bqd.b1, interp_bqd.b2), CONST_DYNFILTER_SLOT_MIN_GAIN, CONST_DYNFILTER_SLOT_MAX_GAIN);
			t_jrgba color = this_response_dB < 0 ? color_interp(slot_color, grey, this_response_dB/CONST_DYNFILTER_SLOT_MIN_GAIN) : color_interp(slot_color, black, this_response_dB/CONST_DYNFILTER_SLOT_MAX_GAIN);
			double y2 = displayed_bounding_rectangle.y + displayed_bounding_rectangle.height - cur;
			double y1 = displayed_bounding_rectangle.y + displayed_bounding_rectangle.height - cur - step_px;
			y1 = CLAMP(y1, displayed_bounding_rectangle.y, displayed_bounding_rectangle.y + displayed_bounding_rectangle.height);
			y2 = CLAMP(y2, displayed_bounding_rectangle.y, displayed_bounding_rectangle.y + displayed_bounding_rectangle.height);
			paint_rectangle(g, color, color, displayed_bounding_rectangle.x + t_cur, y1, step_t_px, y2 - y1, 0);
		}
	} 
	
	// markers
	if (paint_markers){
		t_slotitem *bqditem;
		for (bqditem = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); bqditem; bqditem = bqditem->next){
			t_biquad *bqd = (t_biquad *)bqditem->item;
			t_jrgba fillcolor = build_jrgba(0.8, 0, 0, 0.1);
			t_jrgba markcolor = build_jrgba(0.8, 0., 0., 1.);
			double thisx = notationobj_rescale_with_slope_inv(r_ob, bqd->t, slot_domain_min, slot_domain_max, dynfilter_bounding_rectangle.x, dynfilter_bounding_rectangle.x + dynfilter_bounding_rectangle.width, r_ob->slotinfo[slot_number].slot_domain_par);
			if (thisx + 0.1 >= displayed_bounding_rectangle.x && thisx <= displayed_bounding_rectangle.x + displayed_bounding_rectangle.width + 0.1) {
				double thisfreqy = notationobj_rescale_with_slope_inv(r_ob, bqd->cutoff_freq, slot_min, slot_max, displayed_bounding_rectangle.y + displayed_bounding_rectangle.height, displayed_bounding_rectangle.y, r_ob->slotinfo[slot_number].slot_range_par);
				paint_rectangle(g, markcolor, fillcolor, thisx - 1.5 * zoom_y, displayed_bounding_rectangle.y + 1, 3 * zoom_y, displayed_bounding_rectangle.height - 2, 0.8);
				paint_rectangle(g, markcolor, markcolor, thisx - 1.5 * zoom_y, thisfreqy - 1.5 * zoom_y, 3 * zoom_y, 3 * zoom_y, 0);
			}
		}
	}
}


void paint_colorpalette(t_notation_obj *r_ob, t_jgraphics* g, t_rect palette_rectangle, double spectrum_x, double spectrum_width, t_jrgba selected_color, 
						t_jrgba top_right_corner_color, char show_circle, char show_spectrum, char show_spectrum_arrow, char show_coefficients, 
						t_jfont *coeff_font, t_jrgba coeff_color, t_jrgba coeff_bg_color, double zoom){
	double palette_x = floor(palette_rectangle.x), palette_y = floor(palette_rectangle.y);
	double palette_width = ceil(palette_rectangle.width), palette_height = ceil(palette_rectangle.height);
	t_jrgba black_alpha_1 = get_grey(0);
	t_jrgba white_alpha_1 = get_grey(1);
	t_jrgba black = get_grey(0);
	t_jrgba white = get_grey(1);
	double h_step_pix = 1;
	double v_step_pix = 1;
	long i, j;
	long num_h_steps = MAX(2, round(palette_width/CONST_SLOT_COLOR_NUM_H_PIXELS_PER_STEP));
	long num_v_steps = MAX(2, round(palette_height/CONST_SLOT_COLOR_NUM_V_PIXELS_PER_STEP));
	double cur_x, cur_y, real_x, real_y;
	
//	top_right_corner_color.alpha = 1;
	double alpha = white.alpha = black.alpha = top_right_corner_color.alpha = selected_color.alpha;
	
	h_step_pix = palette_width / num_h_steps;
	v_step_pix = palette_height / num_v_steps;

	if (alpha > 0) {
		// painting the palette
		double next_x = palette_x, next_y = palette_y;
		for (i = 0, cur_x = real_x = palette_x; i < num_h_steps; i++, cur_x = next_x, real_x += h_step_pix) {
			t_jrgba curr_column_color = color_interp(white, top_right_corner_color, ((double)i)/(num_h_steps - 1));
			for (j = 0, cur_y = real_y = palette_y; j < num_v_steps; j++, cur_y = next_y, real_y += v_step_pix){
				t_jrgba thiscolor = color_interp(curr_column_color, black, ((double)j)/(num_v_steps - 1));
				next_x = round(real_x + h_step_pix);
				next_y = round(real_y + v_step_pix);
				paint_filledrectangle_fast(g, thiscolor, cur_x, cur_y, next_x - cur_x, next_y - cur_y);
			}
		}
	}
	
	paint_strokenrectangle(g, black_alpha_1, palette_x, palette_y, palette_width, palette_height, 0.5);
	
	if (show_coefficients && coeff_font){
		char coeff_str[200];
		snprintf_zero(coeff_str, 200, "R: %.2f G: %.2f B: %.2f A: %.2f", selected_color.red, selected_color.green, selected_color.blue, selected_color.alpha);
		paint_rectangle(g, coeff_bg_color, coeff_bg_color, palette_x, palette_y + palette_height, palette_width, 10 * zoom, 0);
		write_text_standard_singleline(g, coeff_font, coeff_color, coeff_str, palette_x, palette_y + palette_height, palette_width, 200 * zoom);
	}
	
	if (show_circle){
		double circle_x, circle_y;
		if (!get_color_xy_coordinates(selected_color, &circle_x, &circle_y)) {
			// not black
			circle_x = rescale(circle_x, 0, 1, palette_x, palette_x + palette_width);
			circle_y = rescale(circle_y, 1, 0, palette_y, palette_y + palette_height);
		} else {
			// black
            if (r_ob)
                circle_x = CLAMP(r_ob->j_mouse_hasbeendragged ? r_ob->j_mousedrag_point.x : r_ob->j_mousedown_point.x, palette_x, palette_x + palette_width);
            else
                circle_x = palette_x + palette_x/2.;
			circle_y = rescale(circle_y, 1, 0, palette_y, palette_y + palette_height);
		}
		paint_circle_stroken(g, white_alpha_1, circle_x, circle_y, 3 * zoom, 1.8);
		paint_circle_stroken(g, white_alpha_1, circle_x, circle_y, 3 * zoom, 1);
	}
	
	if (show_spectrum){
		for (j = 0, cur_y = palette_y; j < num_v_steps; j++, cur_y += v_step_pix){
			t_jrgba thiscolor = double_to_color(((double)j)/(num_v_steps - 1), 0, 1, true);
			paint_filledrectangle(g, thiscolor, spectrum_x, cur_y, round(spectrum_width), v_step_pix);
		}
		paint_strokenrectangle(g, black_alpha_1, spectrum_x, palette_y, round(spectrum_width), palette_height, 0.5);
		if (show_spectrum_arrow){
			double ypos = color_to_double(top_right_corner_color, palette_y, palette_y + palette_height, true);
			paint_strokenrectangle(g, white_alpha_1, spectrum_x - 1 * zoom, ypos - 2 * zoom, spectrum_width + 2 * zoom, 4 * zoom, 2.4);
			paint_strokenrectangle(g, black_alpha_1, spectrum_x - 1 * zoom, ypos - 2 * zoom, spectrum_width + 2 * zoom, 4 * zoom, 1.5);
		}
	}
}


void set_matrix_parameters_from_slotinfo(t_notation_obj *r_ob, long slot_num){
	long j = slot_num;
	if (r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_INTMATRIX || r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_FLOATMATRIX || r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_TOGGLEMATRIX) {
		t_llll *this_llll = r_ob->slotinfo[slot_num].slot_repr && r_ob->slotinfo[slot_num].slot_repr->l_head && hatom_gettype(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom) == H_LLLL ?
								hatom_getllll(&r_ob->slotinfo[slot_num].slot_repr->l_head->l_hatom) : NULL;
		if (this_llll) {
			if (this_llll->l_head && (hatom_gettype(&this_llll->l_head->l_hatom) == H_LONG || hatom_gettype(&this_llll->l_head->l_hatom) == H_DOUBLE)){
				r_ob->slotinfo[j].slot_num_rows = hatom_getlong(&this_llll->l_head->l_hatom);
			} else if (this_llll->l_head && hatom_gettype(&this_llll->l_head->l_hatom) == H_LLLL){
				r_ob->slotinfo[j].slot_num_rows = hatom_getllll(&this_llll->l_head->l_hatom)->l_size;
				r_ob->slotinfo[j].slot_has_enum_rows = true;
			}
			if (this_llll->l_tail && (hatom_gettype(&this_llll->l_tail->l_hatom) == H_LONG || hatom_gettype(&this_llll->l_tail->l_hatom) == H_DOUBLE)){
				r_ob->slotinfo[j].slot_num_cols = hatom_getlong(&this_llll->l_tail->l_hatom);
			} else if (this_llll->l_tail && hatom_gettype(&this_llll->l_tail->l_hatom) == H_LLLL){
				r_ob->slotinfo[j].slot_num_cols = hatom_getllll(&this_llll->l_tail->l_hatom)->l_size;
				r_ob->slotinfo[j].slot_has_enum_cols = true;
			}
		}
	}
}


// (#slot_1_based (name Lyrics) (type text) ( ))

t_llll *set_slotinfo_from_llll(t_notation_obj *r_ob, t_llll* slotinfo)
{
	if (slotinfo) {
		t_llllelem *elem;  
		for (elem = slotinfo->l_head; elem; elem = elem->l_next) {
			long type = hatom_gettype(&elem->l_hatom);
			if (type == H_LLLL) { // there's a nested llll, so specifications for the single slot
				t_llll *single_slots = hatom_getllll(&elem->l_hatom); 
				
				// here we should have : (slotnumber slotname slottype slotmin slotmax optional:slotkey)
				//or: new way: (slotnumber (attribute val) (attribute val)

				if (single_slots && single_slots->l_head && single_slots->l_head->l_next && hatom_gettype(&single_slots->l_head->l_next->l_hatom) == H_LLLL) {
					// NEW CODE (new way of defining slotinfo)

					long j = hatom_getlong(&single_slots->l_head->l_hatom) - 1; // slot number is 1-based in the interface, 0-based inside the code

                    if (j >= 0 && j < CONST_MAX_SLOTS) {
                        
                        t_llllelem *elem;
                        
                        // user defined values:
                        char need_check_slot_domain = false, need_remove_extension = false;
                        for (elem = single_slots->l_head->l_next; elem; elem = elem->l_next) {
                            if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                                t_llll *this_llll = hatom_getllll(&elem->l_hatom);
                                
                                t_symbol *router = (this_llll && this_llll->l_head && hatom_gettype(&this_llll->l_head->l_hatom) == H_SYM) ? hatom_getsym(&this_llll->l_head->l_hatom) : NULL;
                                if (router){
                                    
                                    if (router == _llllobj_sym_name && this_llll->l_head->l_next){
                                        t_symbol *slotname = (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM) ? hatom_getsym(&this_llll->l_head->l_next->l_hatom) : _llllobj_sym_no_name;
                                        r_ob->slotinfo[j].slot_name = slotname;
                                        
                                    } else if (router == _llllobj_sym_type && this_llll->l_head->l_next){
                                        t_symbol *slottype = (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM) ? hatom_getsym(&this_llll->l_head->l_next->l_hatom) : _llllobj_sym_none;
                                        change_slot_type(r_ob, j, slottype);
                                        
                                    } else if (router == _llllobj_sym_range && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next){
                                        r_ob->slotinfo[j].slot_range[0] = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        r_ob->slotinfo[j].slot_range[1] = hatom_getdouble(&this_llll->l_head->l_next->l_next->l_hatom);
                                        slot_check_range(r_ob, j);
                                        
                                    } else if (router == _llllobj_sym_zrange && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next){
                                        r_ob->slotinfo[j].slot_zrange[0] = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        r_ob->slotinfo[j].slot_zrange[1] = hatom_getdouble(&this_llll->l_head->l_next->l_next->l_hatom);
                                        slot_check_zrange(r_ob, j);
                                        
                                    } else if (router == _llllobj_sym_key && this_llll->l_head->l_next){
                                        if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_LONG)
                                            r_ob->slotinfo[j].slot_key = hatom_getlong(&this_llll->l_head->l_next->l_hatom);
                                        else if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM)
                                            r_ob->slotinfo[j].slot_key = hatom_getsym(&this_llll->l_head->l_next->l_hatom)->s_name[0];
                                        
                                    } else if (router == _llllobj_sym_slope && this_llll->l_head->l_next){
                                        r_ob->slotinfo[j].slot_range_par = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        clip_double(&r_ob->slotinfo[j].slot_range_par, -1., 1.);
                                        
                                    } else if (router == _llllobj_sym_zslope && this_llll->l_head->l_next){
                                        r_ob->slotinfo[j].slot_zrange_par = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        clip_double(&r_ob->slotinfo[j].slot_zrange_par, -1., 1.);
                                        
                                    } else if (router == _llllobj_sym_domainslope && this_llll->l_head->l_next){
                                        r_ob->slotinfo[j].slot_domain_par = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        clip_double(&r_ob->slotinfo[j].slot_domain_par, -1., 1.);
                                        
                                    } else if (router == _llllobj_sym_color && this_llll->l_size >= 4){
                                        r_ob->slotinfo[j].slot_color = build_jrgba(hatom_getdouble(&this_llll->l_head->l_next->l_hatom),
                                                                                   hatom_getdouble(&this_llll->l_head->l_next->l_next->l_hatom),
                                                                                   hatom_getdouble(&this_llll->l_head->l_next->l_next->l_next->l_hatom),
                                                                                   this_llll->l_size >= 5 ? hatom_getdouble(&this_llll->l_head->l_next->l_next->l_next->l_next->l_hatom) : 1);
                                        assure_color_goodness(&r_ob->slotinfo[j].slot_color);
                                        
                                    } else if (router == _llllobj_sym_default && this_llll->l_head->l_next){
                                        r_ob->slotinfo[j].slot_default = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        clip_double(&r_ob->slotinfo[j].slot_default, r_ob->slotinfo[j].slot_range[0], r_ob->slotinfo[j].slot_range[1]);
                                        
                                    } else if (router == _llllobj_sym_representation) {
                                        t_llll *representation = llll_get();
                                        t_llllelem *repelem = this_llll->l_head->l_next;
                                        if (repelem) { // && !(hatom_gettype(&repelem->l_hatom) == H_LLLL && hatom_getllll(&repelem->l_hatom)->l_size == 0)) { // WHY DID WE PUT THIS?
                                            llll_appendhatom_clone(representation, &repelem->l_hatom, 0, WHITENULL_llll);
                                            if (repelem->l_next) { // domain and range representation defined?
                                                llll_appendhatom_clone(representation, &repelem->l_next->l_hatom, 0, WHITENULL_llll);
                                                if (repelem->l_next->l_next) // zrange representation defined?
                                                    llll_appendhatom_clone(representation, &repelem->l_next->l_next->l_hatom, 0, WHITENULL_llll);
                                            }
                                        }
                                        if (r_ob->slotinfo[j].slot_repr)
                                            llll_free(r_ob->slotinfo[j].slot_repr);
                                        r_ob->slotinfo[j].slot_repr = representation;
                                        set_matrix_parameters_from_slotinfo(r_ob, j);
                                        
                                    } else if (router == _llllobj_sym_ysnap && this_llll->l_head->l_next) {
                                        if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_LLLL){
                                            if (r_ob->slotinfo[j].slot_ysnap)
                                                llll_free(r_ob->slotinfo[j].slot_ysnap);
                                            r_ob->slotinfo[j].slot_ysnap = llll_clone(hatom_getllll(&this_llll->l_head->l_next->l_hatom));
                                        } else {
                                            if (r_ob->slotinfo[j].slot_ysnap)
                                                llll_free(r_ob->slotinfo[j].slot_ysnap);
                                            r_ob->slotinfo[j].slot_ysnap = llll_clone(this_llll);
                                            llll_behead(r_ob->slotinfo[j].slot_ysnap);
                                        }
                                        
                                    } else if (router == _llllobj_sym_zsnap && this_llll->l_head->l_next) {
                                        if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_LLLL){
                                            if (r_ob->slotinfo[j].slot_zsnap)
                                                llll_free(r_ob->slotinfo[j].slot_zsnap);
                                            r_ob->slotinfo[j].slot_zsnap = llll_clone(hatom_getllll(&this_llll->l_head->l_next->l_hatom));
                                        } else {
                                            if (r_ob->slotinfo[j].slot_zsnap)
                                                llll_free(r_ob->slotinfo[j].slot_zsnap);
                                            r_ob->slotinfo[j].slot_zsnap = llll_clone(this_llll);
                                            llll_behead(r_ob->slotinfo[j].slot_zsnap);
                                        }
                                        
                                    } else if (router == _sym_grid) {
                                        if (r_ob->slotinfo[j].grid)
                                            llll_free(r_ob->slotinfo[j].grid);
                                        r_ob->slotinfo[j].grid = llll_clone(this_llll);
                                        llll_behead(r_ob->slotinfo[j].grid);
                                        
                                    } else if (router == _llllobj_sym_temporalmode && this_llll->l_head->l_next) {
                                        e_slot_temporalmodes temporalmode = k_SLOT_TEMPORALMODE_NONE;
                                        if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT && hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM)
                                            temporalmode = slot_symbol_to_temporalmode(hatom_getsym(&this_llll->l_head->l_next->l_hatom));

                                        change_slot_temporalmode(r_ob, j, slot_temporalmode_to_symbol(temporalmode));

                                    } else if (router == _llllobj_sym_extend && this_llll->l_head->l_next) {
                                        r_ob->slotinfo[j].extend_beyond_tails = (hatom_getlong(&this_llll->l_head->l_next->l_hatom) > 0 ? 1 : 0);
                                        need_remove_extension = (hatom_getlong(&this_llll->l_head->l_next->l_hatom) == 0);
                                        need_check_slot_domain = true;

                                    } else if (router == _llllobj_sym_width && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom) && r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
                                            r_ob->slotinfo[j].slot_uwidth = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        else if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM){
                                            t_symbol *w_sym = hatom_getsym(&this_llll->l_head->l_next->l_hatom);
                                            
                                            if (w_sym == _llllobj_sym_temporal) { // backward compatibility with old temporal behaviour!
                                                r_ob->slotinfo[j].slot_uwidth = -3.; // duration
                                                r_ob->slotinfo[j].slot_temporalmode = r_ob->obj_type == k_NOTATION_OBJECT_SLOT ? k_SLOT_TEMPORALMODE_NONE : k_SLOT_TEMPORALMODE_RELATIVE;
                                            } else if (w_sym == _llllobj_sym_auto) {
                                                r_ob->slotinfo[j].slot_uwidth = -2.;
                                            } else if (w_sym == _llllobj_sym_duration) {
                                                r_ob->slotinfo[j].slot_uwidth = -3.;
                                            }
                                        }
                                        
                                    } else if (router == _llllobj_sym_height && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom) && r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
                                            r_ob->slotinfo[j].slot_active_uheight = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        else // automatic height
                                            r_ob->slotinfo[j].slot_active_uheight = -1;
                                        
                                    } else if (router == _llllobj_sym_singleslotfortiednotes && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom))
                                            r_ob->slotinfo[j].slot_singleslotfortiednotes = hatom_getlong(&this_llll->l_head->l_next->l_hatom);

                                    } else if (router == _llllobj_sym_copywhensplit && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom))
                                            r_ob->slotinfo[j].copy_when_split = hatom_getlong(&this_llll->l_head->l_next->l_hatom);

                                    } else if (router == _llllobj_sym_follownotehead && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom))
                                            r_ob->slotinfo[j].trim_with_notehead = hatom_getlong(&this_llll->l_head->l_next->l_hatom);
                                        
                                    } else if (router == _llllobj_sym_access && this_llll->l_head->l_next) {
                                        if (is_hatom_number(&this_llll->l_head->l_next->l_hatom))
                                            r_ob->slotinfo[j].access_type = hatom_getlong(&this_llll->l_head->l_next->l_hatom);
                                        else if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM)
                                            r_ob->slotinfo[j].access_type = slot_access_type_from_symbol(hatom_getsym(&this_llll->l_head->l_next->l_hatom));
                                        slot_check_access(r_ob, r_ob->active_slot_num);
                                        
                                    } else if (router == _llllobj_sym_domain && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next) {
                                        r_ob->slotinfo[j].slot_domain[0] = hatom_getdouble(&this_llll->l_head->l_next->l_hatom);
                                        r_ob->slotinfo[j].slot_domain[1] = hatom_getdouble(&this_llll->l_head->l_next->l_next->l_hatom);
                                        need_check_slot_domain = 1; // we check the domain later on, because one might set the temporal mode later, and this'll affect the checking
                                        
                                        /// ATTRIBUTES WHICH ARE ALREADY SAVED IN THE MAX EXTERNAL (but which can also be set by message, e.g. for undo)
                                    } else if (router == _llllobj_sym_background && this_llll->l_head->l_next){
                                        change_background_slot_flag(r_ob, j, hatom_getlong(&this_llll->l_head->l_next->l_hatom));
                                        
                                    } else if (router == _llllobj_sym_popup && this_llll->l_head->l_next){
                                        change_popupmenu_slot_flag(r_ob, j, hatom_getlong(&this_llll->l_head->l_next->l_hatom));
                                        
                                    } else if (router == _llllobj_sym_rightclick && this_llll->l_head->l_next){
                                        if (!this_llll->l_head->l_next || (this_llll->l_head->l_next && hatom_getlong(&this_llll->l_head->l_next->l_hatom))) {
                                            t_atom av;
                                            atom_setlong(&av, j+1);
                                            notation_obj_setattr_rightclickdirectlypopsoutslot(r_ob, NULL, 1, &av);
                                        }
                                        
                                    } else if (router == _llllobj_sym_linkto && this_llll->l_head->l_next){
                                        change_linkto_slot_flag(r_ob, j, hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM ? linkto_sym_to_linkto_elem(r_ob, hatom_getsym(&this_llll->l_head->l_next->l_hatom)) : hatom_getlong(&this_llll->l_head->l_next->l_hatom));
                                    }
                                }
                            }
                        }
                        
                        if (need_remove_extension)
                            notationobj_slot_remove_extensions(r_ob, j);
                            
                        if (need_check_slot_domain && (r_ob->slotinfo[j].slot_temporalmode != k_SLOT_TEMPORALMODE_MILLISECONDS && r_ob->slotinfo[j].slot_temporalmode != k_SLOT_TEMPORALMODE_TIMEPOINTS))
                            slot_check_domain(r_ob, j);
                        
                        if (r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_FILTER){
                            // ????
                        }
                    }
					
				} else if (single_slots && single_slots->l_size >= 5) {
					// OLD CODE (old way to define slotinfo
					
					long j = hatom_getlong(&single_slots->l_head->l_hatom) - 1; // slot number is 1-based in the interface, 0-based inside the code
					
					if (j >= 0 && j < CONST_MAX_SLOTS) {
						long old_slottype;
						t_symbol *slottype;
						t_symbol *slotname = (hatom_gettype(&single_slots->l_head->l_next->l_hatom) == H_SYM) ? hatom_getsym(&single_slots->l_head->l_next->l_hatom) : _llllobj_sym_no_name;
						r_ob->slotinfo[j].slot_name = slotname;
						
						old_slottype = r_ob->slotinfo[j].slot_type;
						slottype = (hatom_gettype(&single_slots->l_head->l_next->l_next->l_hatom) == H_SYM) ? hatom_getsym(&single_slots->l_head->l_next->l_next->l_hatom) : _llllobj_sym_none;
						change_slot_type(r_ob, j, slottype);
						
						r_ob->slotinfo[j].slot_range[0] = hatom_getdouble(&single_slots->l_head->l_next->l_next->l_next->l_hatom);
						r_ob->slotinfo[j].slot_range[1] = hatom_getdouble(&single_slots->l_head->l_next->l_next->l_next->l_next->l_hatom);
						r_ob->slotinfo[j].slot_num_cols = r_ob->slotinfo[j].slot_num_rows = 0;
						r_ob->slotinfo[j].slot_has_enum_rows = r_ob->slotinfo[j].slot_has_enum_cols = false;
												
						if (single_slots->l_size >= 6) {
							if (hatom_gettype(&single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom) == H_LONG)
								r_ob->slotinfo[j].slot_key = hatom_getlong(&single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom);
							else if (hatom_gettype(&single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom) == H_SYM)
								r_ob->slotinfo[j].slot_key = hatom_getsym(&single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom)->s_name[0];

							if (single_slots->l_size >= 7) {
								t_llll *representation = llll_get();
								r_ob->slotinfo[j].slot_range_par = hatom_getdouble(&single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_next->l_hatom);
								clip_double(&r_ob->slotinfo[j].slot_range_par, -1., 1.);
								
								if (r_ob->slotinfo[j].slot_repr) 
									llll_free(r_ob->slotinfo[j].slot_repr);
								
								if (single_slots->l_size >= 8) {
									t_llllelem *repelem = single_slots->l_head->l_next->l_next->l_next->l_next->l_next->l_next->l_next;
									if (! ((hatom_gettype(&repelem->l_hatom) == H_LLLL) && (hatom_getllll(&repelem->l_hatom)->l_size == 0))) {
										if (r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_INTMATRIX || r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_FLOATMATRIX || r_ob->slotinfo[j].slot_type == k_SLOT_TYPE_TOGGLEMATRIX) {
											t_llll *this_llll = hatom_getllll(&repelem->l_hatom);
											if (this_llll) {
												if (this_llll->l_head && (hatom_gettype(&this_llll->l_head->l_hatom) == H_LONG || hatom_gettype(&this_llll->l_head->l_hatom) == H_DOUBLE)){
													r_ob->slotinfo[j].slot_num_rows = hatom_getlong(&this_llll->l_head->l_hatom);
												} else if (this_llll->l_head && hatom_gettype(&this_llll->l_head->l_hatom) == H_LLLL){
													r_ob->slotinfo[j].slot_num_rows = hatom_getllll(&this_llll->l_head->l_hatom)->l_size;
													r_ob->slotinfo[j].slot_has_enum_rows = true;
												}
												if (this_llll->l_tail && (hatom_gettype(&this_llll->l_tail->l_hatom) == H_LONG || hatom_gettype(&this_llll->l_tail->l_hatom) == H_DOUBLE)){
													r_ob->slotinfo[j].slot_num_cols = hatom_getlong(&this_llll->l_tail->l_hatom);
												} else if (this_llll->l_tail && hatom_gettype(&this_llll->l_tail->l_hatom) == H_LLLL){
													r_ob->slotinfo[j].slot_num_cols = hatom_getllll(&this_llll->l_tail->l_hatom)->l_size;
													r_ob->slotinfo[j].slot_has_enum_cols = true;
												}
											}
										}
										llll_appendhatom_clone(representation, &repelem->l_hatom, 0, WHITENULL_llll);
									}
								}
								
								r_ob->slotinfo[j].slot_repr = representation;
								
							} else {
								r_ob->slotinfo[j].slot_range_par = 0.;
								if (r_ob->slotinfo[j].slot_repr) 
									llll_free(r_ob->slotinfo[j].slot_repr);
								r_ob->slotinfo[j].slot_repr = llll_get();
							}
						} else {
							r_ob->slotinfo[j].slot_key = 0;
							r_ob->slotinfo[j].slot_range_par = 0.;
							if (r_ob->slotinfo[j].slot_repr) 
								llll_free(r_ob->slotinfo[j].slot_repr);
							r_ob->slotinfo[j].slot_repr = llll_get();
						}
					}
				}
			}
		}
	}
	return NULL;
}




void convert_note_slot_type(t_notation_obj *r_ob, t_note *note, long slot_num, long conversion_type){
	t_slotitem *item;
	for (item = note->slot[slot_num].firstitem; item; item = item->next){
		if (item->item) {
			if (conversion_type == 1) // INT to FLOAT
				*((double *)(item->item)) = (double) *((long *)(item->item));
			else if (conversion_type == 2) // FLOAT TO INT
				*((long *)(item->item)) = (long) *((double *)(item->item));
		}
	}
}

char convert_slot_type(t_notation_obj *r_ob, long slot_num, long old_slottype, long new_slottype)
{
	long conversion_type = -1;
	
	if (old_slottype == new_slottype)
		conversion_type = 0;
	else if ((old_slottype == k_SLOT_TYPE_INT && new_slottype == k_SLOT_TYPE_INTLIST) ||
			 (old_slottype == k_SLOT_TYPE_FLOAT && new_slottype == k_SLOT_TYPE_FLOATLIST))
		conversion_type = 0;
	else if ((old_slottype == k_SLOT_TYPE_TOGGLEMATRIX && new_slottype == k_SLOT_TYPE_INTMATRIX) ||
			 (old_slottype == k_SLOT_TYPE_INTMATRIX && new_slottype == k_SLOT_TYPE_TOGGLEMATRIX) ||
			 (old_slottype == k_SLOT_TYPE_INTMATRIX && new_slottype == k_SLOT_TYPE_FLOATMATRIX) ||
			 (old_slottype == k_SLOT_TYPE_FLOATMATRIX && new_slottype == k_SLOT_TYPE_INTMATRIX) ||
			 (old_slottype == k_SLOT_TYPE_FLOATMATRIX && new_slottype == k_SLOT_TYPE_TOGGLEMATRIX) ||
			 (old_slottype == k_SLOT_TYPE_TOGGLEMATRIX && new_slottype == k_SLOT_TYPE_FLOATMATRIX))
		conversion_type = 0;
	else if ((old_slottype == k_SLOT_TYPE_INT && new_slottype == k_SLOT_TYPE_FLOAT) ||
			 (old_slottype == k_SLOT_TYPE_INTLIST && new_slottype == k_SLOT_TYPE_FLOATLIST) ||
			 (old_slottype == k_SLOT_TYPE_INT && new_slottype == k_SLOT_TYPE_FLOATLIST))
		conversion_type = 1;
	else if ((old_slottype == k_SLOT_TYPE_FLOAT && new_slottype == k_SLOT_TYPE_INT) ||
			 (old_slottype == k_SLOT_TYPE_FLOATLIST && new_slottype == k_SLOT_TYPE_INTLIST) ||
			 (old_slottype == k_SLOT_TYPE_FLOAT && new_slottype == k_SLOT_TYPE_INTLIST))
		conversion_type = 2;
	else if ((old_slottype == k_SLOT_TYPE_FILTER && new_slottype == k_SLOT_TYPE_DYNFILTER))
		conversion_type = 0;
	
	if (conversion_type > 0) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
			convert_note_slot_type(r_ob, r_ob->dummynote, slot_num, conversion_type);
		} else {
			t_voice *voice; 
			t_chord *chord; 
			t_note *note;
			for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
				for (chord = r_ob->obj_type == k_NOTATION_OBJECT_SCORE ? (((t_scorevoice *) voice)->firstmeasure ? ((t_scorevoice *) voice)->firstmeasure->firstchord : NULL)
					 : ((t_rollvoice *) voice)->firstchord; chord; chord = chord_get_next(chord))
					for (note = chord->firstnote; note; note = note->next) 
						convert_note_slot_type(r_ob, note, slot_num, conversion_type);
		}
	}
	

	// auto setting domain/range for filter slots
	if (new_slottype == k_SLOT_TYPE_FILTER && old_slottype == k_SLOT_TYPE_DYNFILTER) {
		r_ob->slotinfo[slot_num].slot_domain_par = r_ob->slotinfo[slot_num].slot_range_par;
		r_ob->slotinfo[slot_num].slot_range_par = 0.;
		r_ob->slotinfo[slot_num].slot_domain[0] = r_ob->slotinfo[slot_num].slot_range[0];
		r_ob->slotinfo[slot_num].slot_domain[1] = r_ob->slotinfo[slot_num].slot_range[1];
		r_ob->slotinfo[slot_num].slot_range[0] = CONST_FILTER_SLOT_DEFAULT_MIN_GAIN;
		r_ob->slotinfo[slot_num].slot_range[1] = CONST_FILTER_SLOT_DEFAULT_MAX_GAIN;
	} else if (new_slottype == k_SLOT_TYPE_FILTER && old_slottype != k_SLOT_TYPE_FILTER) {
		r_ob->slotinfo[slot_num].slot_range[0] = CONST_FILTER_SLOT_DEFAULT_MIN_GAIN;
		r_ob->slotinfo[slot_num].slot_range[1] = CONST_FILTER_SLOT_DEFAULT_MAX_GAIN;
		r_ob->slotinfo[slot_num].slot_domain[0] = 0;
		r_ob->slotinfo[slot_num].slot_domain[1] = r_ob->sampling_freq/2.;
		r_ob->slotinfo[slot_num].slot_domain_par = 0.6;
		r_ob->slotinfo[slot_num].slot_range_par = 0;
	} else if (new_slottype == k_SLOT_TYPE_DYNFILTER && old_slottype == k_SLOT_TYPE_FILTER) {
		r_ob->slotinfo[slot_num].slot_range[0] = r_ob->slotinfo[slot_num].slot_domain[0];
		r_ob->slotinfo[slot_num].slot_range[1] = r_ob->slotinfo[slot_num].slot_domain[1];
		r_ob->slotinfo[slot_num].slot_domain[0] = 0;
		r_ob->slotinfo[slot_num].slot_domain[1] = 1.;
		r_ob->slotinfo[slot_num].slot_range_par = r_ob->slotinfo[slot_num].slot_domain_par;
		r_ob->slotinfo[slot_num].slot_domain_par = 0.;
	} else if (new_slottype == k_SLOT_TYPE_DYNFILTER && old_slottype != k_SLOT_TYPE_DYNFILTER) {
		r_ob->slotinfo[slot_num].slot_range[0] = 0;
		r_ob->slotinfo[slot_num].slot_range[1] = r_ob->sampling_freq/2.;
		r_ob->slotinfo[slot_num].slot_domain[0] = 0;
		r_ob->slotinfo[slot_num].slot_domain[1] = 1.;
		r_ob->slotinfo[slot_num].slot_domain_par = 0.;
		r_ob->slotinfo[slot_num].slot_range_par = 0.6;
	}

	// converting width (only major conversion: temporal/nontemporal...)
	if ((new_slottype == k_SLOT_TYPE_FUNCTION || new_slottype == k_SLOT_TYPE_3DFUNCTION || new_slottype == k_SLOT_TYPE_SPAT || new_slottype == k_SLOT_TYPE_DYNFILTER) &&
		(old_slottype != k_SLOT_TYPE_FUNCTION && old_slottype != k_SLOT_TYPE_3DFUNCTION && old_slottype != k_SLOT_TYPE_SPAT && old_slottype != k_SLOT_TYPE_DYNFILTER)) {
        if (r_ob->slotinfo[slot_num].slot_temporalmode == k_SLOT_TEMPORALMODE_NONE)
            r_ob->slotinfo[slot_num].slot_temporalmode = k_SLOT_TEMPORALMODE_RELATIVE;
		r_ob->slotinfo[slot_num].slot_uwidth = -1; // temporal, automatically
	} else if ((old_slottype == k_SLOT_TYPE_FUNCTION || old_slottype == k_SLOT_TYPE_3DFUNCTION || old_slottype == k_SLOT_TYPE_SPAT) &&
			 (new_slottype != k_SLOT_TYPE_FUNCTION && new_slottype != k_SLOT_TYPE_3DFUNCTION && new_slottype != k_SLOT_TYPE_SPAT)) {
		if (new_slottype == k_SLOT_TYPE_NONE)
			r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_FILELIST_DEFAULT_UWIDTH;
		else if (new_slottype == k_SLOT_TYPE_INT || new_slottype == k_SLOT_TYPE_INTLIST || new_slottype == k_SLOT_TYPE_FLOAT || new_slottype == k_SLOT_TYPE_FLOATLIST)
			r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_LONG_FLOAT_DEFAULT_UWIDTH;
		else if (new_slottype == k_SLOT_TYPE_INTMATRIX || new_slottype == k_SLOT_TYPE_FLOATMATRIX || new_slottype == k_SLOT_TYPE_TOGGLEMATRIX)
			r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_MATRIX_DEFAULT_UWIDTH;
		else if (new_slottype == k_SLOT_TYPE_TEXT || new_slottype == k_SLOT_TYPE_LLLL)
			r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_TEXT_DEFAULT_UWIDTH;
        else if (new_slottype == k_SLOT_TYPE_ARTICULATIONS)
            r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_ARTICULATIONS_DEFAULT_UWIDTH;
        else if (new_slottype == k_SLOT_TYPE_NOTEHEAD)
            r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_NOTEHEAD_DEFAULT_UWIDTH;
        else if (new_slottype == k_SLOT_TYPE_DYNAMICS)
            r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_DYNAMICS_DEFAULT_UWIDTH;
		else if (new_slottype == k_SLOT_TYPE_FILTER)
			r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_FILTER_DEFAULT_UWIDTH;
	} else if (new_slottype == k_SLOT_TYPE_FILELIST && old_slottype != k_SLOT_TYPE_FILELIST)
		r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_FILELIST_DEFAULT_UWIDTH;
		
	// converting heights (only major conversions: for auto heights to slots having lists.
	if ((new_slottype == k_SLOT_TYPE_INTLIST || new_slottype == k_SLOT_TYPE_FLOATLIST || new_slottype == k_SLOT_TYPE_FILELIST || new_slottype == k_SLOT_TYPE_INTMATRIX || new_slottype == k_SLOT_TYPE_FLOATMATRIX || new_slottype == k_SLOT_TYPE_TOGGLEMATRIX) &&
		(old_slottype != k_SLOT_TYPE_INTLIST && old_slottype != k_SLOT_TYPE_FLOATLIST && old_slottype != k_SLOT_TYPE_FILELIST && old_slottype != k_SLOT_TYPE_INTMATRIX && old_slottype != k_SLOT_TYPE_FLOATMATRIX && old_slottype != k_SLOT_TYPE_TOGGLEMATRIX)) 
		r_ob->slotinfo[slot_num].slot_active_uheight = -1; // auto height, automatically

	if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
		r_ob->slotinfo[slot_num].slot_uwidth = -1;
		
	if (conversion_type < 0)
		return 1;

	return 0;
}

// change the type of the slot slot_num to the new_type
void change_slot_type(t_notation_obj *r_ob, long slot_num, t_symbol *new_type)
{
	long j = slot_num; 
	long old_slottype = r_ob->slotinfo[j].slot_type;
	e_slot_types new_slottype = k_SLOT_TYPE_NONE;
	
    new_slottype = slot_symbol_to_type(new_type);
	
	if (convert_slot_type(r_ob, slot_num, old_slottype, new_slottype)) {
		notationobj_erase_slot(r_ob, slot_num);
	}
	
	r_ob->slotinfo[j].slot_type = new_slottype;
	
}


void slot_convert_ms_to_relative(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num, double new_domain_min, double new_domain_max)
{
    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_num, nitem);
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
    if (slot) {
        for (t_slotitem *it = slot->firstitem; it; it = it->next) {
            switch (r_ob->slotinfo[slot_num].slot_type) {
                case k_SLOT_TYPE_FUNCTION:
                    ((t_pts *)it->item)->x = new_domain_min + (new_domain_max - new_domain_min) * (((t_pts *)it->item)->x / duration);
                    break;
                    
                case k_SLOT_TYPE_3DFUNCTION:
                    ((t_pts3d *)it->item)->x = new_domain_min + (new_domain_max - new_domain_min) * (((t_pts3d *)it->item)->x / duration);
                    break;
                    
                case k_SLOT_TYPE_SPAT:
                    ((t_spatpt *)it->item)->t = new_domain_min + (new_domain_max - new_domain_min) * (((t_spatpt *)it->item)->t / duration);
                    break;
                    
                case k_SLOT_TYPE_DYNFILTER:
                    ((t_biquad *)it->item)->t = new_domain_min + (new_domain_max - new_domain_min) * (((t_biquad *)it->item)->t / duration);
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void notationobj_convert_slot_ms_to_relative(t_notation_obj *r_ob, long slot_num)
{
    double domain_min = r_ob->slotinfo[slot_num].slot_domain[0];
    double domain_max = r_ob->slotinfo[slot_num].slot_domain[1];
    
    for (t_voice *v = r_ob->firstvoice; v && v->number < r_ob->num_voices; v = voice_get_next(r_ob, v)) {
        for (t_chord *c = chord_get_first(r_ob, v); c; c = chord_get_next(c)) {
            if (!c->firstnote) {
                slot_convert_ms_to_relative(r_ob, (t_notation_item *)c, slot_num, domain_min, domain_max);
            } else {
                for (t_note *n = c->firstnote; n; n = n->next)
                    slot_convert_ms_to_relative(r_ob, (t_notation_item *)n, slot_num, domain_min, domain_max);
            }
        }
    }
}



void slot_convert_relative_to_ms(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num, double old_domain_min, double old_domain_max)
{
    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_num, nitem);
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
    if (slot) {
        for (t_slotitem *it = slot->firstitem; it; it = it->next) {
            switch (r_ob->slotinfo[slot_num].slot_type) {
                case k_SLOT_TYPE_FUNCTION:
                    ((t_pts *)it->item)->x = ((((t_pts *)it->item)->x - old_domain_min)/(old_domain_max - old_domain_min)) * duration;
                    break;
                    
                case k_SLOT_TYPE_3DFUNCTION:
                    ((t_pts3d *)it->item)->x = ((((t_pts3d *)it->item)->x - old_domain_min)/(old_domain_max - old_domain_min)) * duration;
                    break;
                    
                case k_SLOT_TYPE_SPAT:
                    ((t_spatpt *)it->item)->t = ((((t_spatpt *)it->item)->t - old_domain_min)/(old_domain_max - old_domain_min)) * duration;
                    break;
                    
                case k_SLOT_TYPE_DYNFILTER:
                    ((t_biquad *)it->item)->t = ((((t_biquad *)it->item)->t - old_domain_min)/(old_domain_max - old_domain_min)) * duration;
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void notationobj_convert_slot_relative_to_ms(t_notation_obj *r_ob, long slot_num)
{
    double domain_min = r_ob->slotinfo[slot_num].slot_domain[0];
    double domain_max = r_ob->slotinfo[slot_num].slot_domain[1];
    
    for (t_voice *v = r_ob->firstvoice; v && v->number < r_ob->num_voices; v = voice_get_next(r_ob, v)) {
        for (t_chord *c = chord_get_first(r_ob, v); c; c = chord_get_next(c)) {
            if (!c->firstnote) {
                slot_convert_relative_to_ms(r_ob, (t_notation_item *)c, slot_num, domain_min, domain_max);
            } else {
                for (t_note *n = c->firstnote; n; n = n->next)
                    slot_convert_relative_to_ms(r_ob, (t_notation_item *)n, slot_num, domain_min, domain_max);
            }
        }
    }
}



char convert_slot_temporalmode(t_notation_obj *r_ob, long slot_num, long old_temporalmode, long new_temporalmode)
{
    char need_check_domain = false;
    switch (new_temporalmode) {
        case k_SLOT_TEMPORALMODE_NONE:
            switch (old_temporalmode) {
                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                    // change slot domain, to fit the content
                {
                    double max_x = notationobj_get_slot_max_x(r_ob, slot_num);
                    r_ob->slotinfo[slot_num].slot_domain[0] = 0;
                    r_ob->slotinfo[slot_num].slot_domain[1] = max_x;
                    need_check_domain = true;
                }
                    break;
                default:
                    break; // nothing to do
            }
            
            if (old_temporalmode != k_SLOT_TEMPORALMODE_NONE && r_ob->slotinfo[slot_num].slot_uwidth < 0)
                r_ob->slotinfo[slot_num].slot_uwidth = CONST_SLOT_FUNCTION_DEFAULT_UWIDTH;
            
            break;
            
        case k_SLOT_TEMPORALMODE_RELATIVE:
            switch (old_temporalmode) {
                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                    r_ob->slotinfo[slot_num].slot_domain[0] = 0;
                    r_ob->slotinfo[slot_num].slot_domain[1] = 1;
                    notationobj_convert_slot_ms_to_relative(r_ob, slot_num);
                    r_ob->slotinfo[slot_num].slot_uwidth = -2;
                    need_check_domain = true;
                    break;
                default:
                    break;
            }
            break;

        case k_SLOT_TEMPORALMODE_MILLISECONDS:
            switch (old_temporalmode) {
                case k_SLOT_TEMPORALMODE_RELATIVE:
                    notationobj_convert_slot_relative_to_ms(r_ob, slot_num);
                    r_ob->slotinfo[slot_num].slot_uwidth = -2;
                    need_check_domain = true;
                    break;
                default:
                    break;
            }
            break;
            
        default:
            break;
    }
    
    return need_check_domain;
}


void change_slot_temporalmode(t_notation_obj *r_ob, long slot_num, t_symbol *new_temporalmode_sym)
{
    long j = slot_num;
    long old_slottemporalmode = r_ob->slotinfo[j].slot_temporalmode;
    e_slot_temporalmodes new_temporalmode = k_SLOT_TEMPORALMODE_NONE;
    
    new_temporalmode = slot_symbol_to_temporalmode(new_temporalmode_sym);
    
    if (convert_slot_temporalmode(r_ob, slot_num, old_slottemporalmode, new_temporalmode)) {
        r_ob->slotinfo[j].slot_temporalmode = new_temporalmode;
        slot_check_domain(r_ob, slot_num);
    } else {
        r_ob->slotinfo[j].slot_temporalmode = new_temporalmode;
    }
    
}


void slot_remove_extensions(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num)
{
    t_llll *ll = notation_item_get_partial_single_slot_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_DUMPING, slot_num, 0., 1.);
    llll_wrap_once(&ll);
    notation_item_set_slots_from_llll(r_ob, nitem, ll);
    llll_free(ll);
}

void notationobj_slot_remove_extensions(t_notation_obj *r_ob, long slot_num)
{
    for (t_voice *v = r_ob->firstvoice; v && v->number < r_ob->num_voices; v = voice_get_next(r_ob, v)) {
        for (t_chord *c = chord_get_first(r_ob, v); c; c = chord_get_next(c)) {
            if (!c->firstnote) {
                slot_remove_extensions(r_ob, (t_notation_item *)c, slot_num);
            } else {
                for (t_note *n = c->firstnote; n; n = n->next)
                    slot_remove_extensions(r_ob, (t_notation_item *)n, slot_num);
            }
        }
    }
}


// ******* DATA ***********

void slotitem_delete(t_notation_obj *r_ob, long slot_num, t_slotitem *item){
	if (item->selected) {
		t_llllelem *temp;
		for (temp = r_ob->selected_slot_items->l_head; temp; temp = temp->l_next){
			if ((t_slotitem *)hatom_getobj(&temp->l_hatom) == item){
				llll_destroyelem(temp);
				break;
			}
		}
	}
	
	if (item->item) {
        if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_NOTEHEAD) {
            // nothing to do, it's a symbol
        } else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_DYNAMICS) {
            dynamics_check_dependencies_before_deleting_it(r_ob, (t_dynamics *) item->item);
            free_dynamics(r_ob, (t_dynamics *) item->item);
        } else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_LLLL || r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INTMATRIX ||
			r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOATMATRIX || r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_TOGGLEMATRIX)
			llll_free((t_llll *) item->item);
		else
			bach_freeptr(item->item);
	}
	
	if (r_ob->hovered_slotitem == item) {
		r_ob->hovered_slotitem = NULL;
		r_ob->hovering_segment = false;
	}
		
	if (item){
		if (item->prev && item->next){
			item->prev->next = item->next;
			item->next->prev = item->prev;
		} else if (item->prev) { 
			item->prev->next = item->next;
#ifdef BACH_SLOTS_HAVE_LASTITEM
			item->parent->lastitem = item->prev;
#endif
		} else if (item->next) {
			item->next->prev = item->prev;
			item->parent->firstitem = item->next;
		} else { // there was just 1 element
//			if (item->parent) {
				item->parent->firstitem = NULL;
#ifdef BACH_SLOTS_HAVE_LASTITEM
				item->parent->lastitem = NULL;
#endif
			}
//		}
		item->parent->length--;
		bach_freeptr(item);
	}
}


void slot_set_active_item(t_slot *slot, t_slotitem *item_to_be_set_as_active)
{
#ifdef BACH_SLOTS_HAVE_ACTIVEITEM
    slot->activeitem = item_to_be_set_as_active;
#else
    t_slotitem *item;
    for (item = slot->firstitem; item; item = item->next)
        item->active = 0;
    item_to_be_set_as_active->active = true;
#endif
}



t_slotitem *slot_get_active_slotitem(t_slot *slot)
{
#ifdef BACH_SLOTS_HAVE_ACTIVEITEM
    return slot->activeitem;
#else
    t_slotitem *item;;
    for (item = slot->firstitem; item; item = item->next)
        if (item->active)
            return item;
    return NULL;
#endif
}

t_slotitem *slot_get_last_item(t_slot *slot)
{
#ifdef BACH_SLOTS_HAVE_LASTITEM
    return slot->lastitem;
#else
    t_slotitem *item = slot->firstitem;
    while (item && item->next)
        item = item->next;
    return item;
#endif
}

void slotitem_append(t_slotitem *item)
{
	if (item){
        t_slotitem *lastitem = slot_get_last_item(item->parent);
		if (lastitem) {
			lastitem->next = item;
			item->prev = lastitem;
			item->next = NULL;
#ifdef BACH_SLOTS_HAVE_LASTITEM
			item->parent->lastitem = item;
#endif
		} else { // there was no data
			item->parent->firstitem = item;
#ifdef BACH_SLOTS_HAVE_LASTITEM
			item->parent->lastitem = item;
#endif
			item->prev = NULL;
			item->next = NULL;
		}
		item->parent->length++;
	}
}

void slotitem_prepend(t_slotitem *item){
	if (item){
		if (item->parent->firstitem) {
			item->prev = NULL;
			item->next = item->parent->firstitem;
			item->parent->firstitem->prev = item;
			item->parent->firstitem = item;
		} else { // there wa no data: just add data
			item->parent->firstitem = item;
#ifdef BACH_SLOTS_HAVE_LASTITEM
			item->parent->lastitem = item;
#endif
			item->prev = NULL;
			item->next = NULL;
		}
		item->parent->length++;
	}
}


void slotitem_insert(t_slotitem *item, t_slotitem *prev_item, t_slotitem *next_item)
{
	if (item && prev_item && next_item){
		item->next = next_item;
		item->prev = prev_item;
		if (prev_item)
			prev_item->next = item;
		else
			item->parent->firstitem = item;
		if (next_item) 
			next_item->prev = item;
        else {
#ifdef BACH_SLOTS_HAVE_LASTITEM
			item->parent->lastitem = item;
#endif
        }
		item->parent->length++;
	}
}



t_slotitem *slot_xcoord_to_slotitem(t_notation_obj *r_ob, long slotnum, t_slot *s, double x_val, double thresh, long *idx, double *dist)
{
    t_slotitem *tmp, *res = NULL;
    double distance = 0;
    long count = 0, pos = -1;
    switch (r_ob->slotinfo[slotnum].slot_type) {
        case k_SLOT_TYPE_FUNCTION:
        {
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_pts *p = (t_pts *)tmp->item;
                    double this_difference = p->x - x_val;
                    double this_distance = fabs(this_difference);
                    if (this_distance <= thresh && (!res || this_distance < distance)) {
                        distance = this_distance;
                        res = tmp;
                        pos = count;
                    } else if (this_difference > thresh)
                        break;
                }
            }
        }
            break;
 
            
        case k_SLOT_TYPE_3DFUNCTION:
        {
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_pts3d *p = (t_pts3d *)tmp->item;
                    double this_difference = p->x - x_val;
                    double this_distance = fabs(this_difference);
                    if (this_distance <= thresh && (!res || this_distance < distance)) {
                        distance = this_distance;
                        res = tmp;
                        pos = count;
                    } else if (this_difference > thresh)
                        break;
                }
            }
        }
            break;

        case k_SLOT_TYPE_SPAT:
        {
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_spatpt *p = (t_spatpt *)tmp->item;
                    double this_difference = p->t - x_val;
                    double this_distance = fabs(this_difference);
                    if (this_distance <= thresh && (!res || this_distance < distance)) {
                        distance = this_distance;
                        res = tmp;
                        pos = count;
                    } else if (this_difference > thresh)
                        break;
                }
            }
        }
            break;

            
        case k_SLOT_TYPE_DYNFILTER:
        {
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_biquad *p = (t_biquad *)tmp->item;
                    double this_difference = p->t - x_val;
                    double this_distance = fabs(this_difference);
                    if (this_distance <= thresh && (!res || this_distance < distance)) {
                        distance = this_distance;
                        res = tmp;
                        pos = count;
                    } else if (this_difference > thresh)
                        break;
                }
            }
        }
            break;
            
            
        default:
            break;
    }
    
    if (dist)
        *dist = distance;
    
    if (idx)
        *idx = pos;
    
    return res;
}



long slotitem_find_insertion_point(t_notation_obj *r_ob, long slotnum, t_slotitem *item)
{
    t_slotitem *tmp;
    long count = 0;
    t_slot *s = item->parent;
    switch (r_ob->slotinfo[slotnum].slot_type) {
        case k_SLOT_TYPE_FUNCTION:
        {
            t_pts *item_p = (t_pts *)item->item;
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_pts *p = (t_pts *)tmp->item;
                    if (item_p->x < p->x)
                        return count;
                }
            }
            return count;
        }
            break;

        case k_SLOT_TYPE_3DFUNCTION:
        {
            t_pts3d *item_p = (t_pts3d *)item->item;
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_pts3d *p = (t_pts3d *)tmp->item;
                    if (item_p->x < p->x)
                        return count;
                }
            }
            return count;
        }
            break;

        case k_SLOT_TYPE_SPAT:
        {
            t_spatpt *item_p = (t_spatpt *)item->item;
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_spatpt *p = (t_spatpt *)tmp->item;
                    if (item_p->t < p->t)
                        return count;
                }
            }
            return count;
        }
            break;

        case k_SLOT_TYPE_DYNFILTER:
        {
            t_biquad *item_p = (t_biquad *)item->item;
            for (tmp = s->firstitem; tmp; tmp = tmp->next, count++) {
                if (tmp->item) {
                    t_biquad *p = (t_biquad *)tmp->item;
                    if (item_p->t < p->t)
                        return count;
                }
            }
            return count;
        }
            break;
            
        default:
            break;
    }
    return 0;
}

void slotitem_insert_extended(t_notation_obj *r_ob, long slotnum, t_slotitem *item, e_slot_changeslotitem_modes mode, long insertion_position_0based)
{
    switch (mode) {
        case k_CHANGESLOTITEM_MODE_PREPEND:
            slotitem_prepend(item);
            break;
            
        case k_CHANGESLOTITEM_MODE_INSERT:
        {
            t_slotitem *item_at_position = slot_get_nth_item(item->parent, insertion_position_0based);
            if (item_at_position) {
                if (item_at_position->prev)
                    slotitem_insert(item, item_at_position->prev, item_at_position);
                else
                    slotitem_prepend(item);
            } else {
                slotitem_append(item);
            }
        }
            break;
            
        case k_CHANGESLOTITEM_MODE_INSERT_AUTO:
        {
            switch (r_ob->slotinfo[slotnum].slot_type) {
                case k_SLOT_TYPE_FUNCTION:
                case k_SLOT_TYPE_3DFUNCTION:
                case k_SLOT_TYPE_SPAT:
                case k_SLOT_TYPE_DYNFILTER:
                    slotitem_insert_extended(r_ob, slotnum, item, k_CHANGESLOTITEM_MODE_INSERT, slotitem_find_insertion_point(r_ob, slotnum, item));
                    break;
                    
                default:
                    slotitem_insert_extended(r_ob, slotnum, item, k_CHANGESLOTITEM_MODE_INSERT, insertion_position_0based);
                    break;
            }
            break;
        }
            
        default:
            slotitem_append(item);
            break;
    }
}


long slotitem_to_index(t_slotitem *slotitem){ //return the index of the slotitem in the list (1-based!)
	if (slotitem) {
		t_slot *parent = slotitem->parent;
		t_slotitem *temp = parent->firstitem;
		long i = 1;
		while (temp) {
			if (temp == slotitem)
				return i; 
			i++;
			temp = temp->next;
		}
	}
	return -1;
}

t_jrgba get_default_slotcolor(int num_slot){
	t_jrgba color = build_jrgba(0.85, 0.74, 0.51, 1.);
	switch (num_slot % 10) {
		case 0:
			color = build_jrgba ( 0.92, 0., 0., 1. ); break;
		case 1:
			color = build_jrgba ( 0., 0, 0.87, 1. ); break;
		case 2:
			color = build_jrgba ( 0., 0.82, 0.12, 1. ); break;
		case 3:
			color = build_jrgba ( 0.91, 0.76, 0.05, 1. ); break;
		case 4:
			color = build_jrgba ( 1., 0.55, 0., 1. ); break;
		case 5:
			color = build_jrgba ( 0.92, 0., 0.72, 1. ); break;
		case 6:
			color = build_jrgba ( 0., 0.76, 1., 1. ); break;
		case 7:
			color = build_jrgba ( 0.62, 0.83, 0., 1. ); break;
		case 8:
			color = build_jrgba ( 0.5, 0., 1., 1. ); break;
		case 9:
			color = build_jrgba ( 0.15, 0.94, 0.61, 1. ); break;
	}
	return color;
}


void build_default_data_for_dynamics_slot(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num)
{
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
    slot->firstitem = build_slotitem(r_ob, slot);
    slot->firstitem->next = NULL;
    slot->firstitem->prev = NULL;
    slot->firstitem->item = build_dynamics(nitem);
#ifdef BACH_SLOTS_HAVE_LASTITEM
    slot->lastitem = slot->firstitem;
#endif
    slot->length = 1;
}


void build_default_data_for_text_slot(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num)
{
	char *emptytext = (char *)bach_newptr(sizeof(char));
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
	slot->firstitem = build_slotitem(r_ob, slot);
	slot->firstitem->next = NULL;
	slot->firstitem->prev = NULL;
	*emptytext = 0;
	slot->firstitem->item = emptytext;
#ifdef BACH_SLOTS_HAVE_LASTITEM
	slot->lastitem = slot->firstitem;
#endif
	slot->length = 0;
}

void build_default_data_for_llll_slot(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num)
{
	t_llll *nil_llll = llll_get();
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
	slot->firstitem = build_slotitem(r_ob, slot);
	slot->firstitem->next = NULL;
	slot->firstitem->prev = NULL;
	slot->firstitem->item = nil_llll;
#ifdef BACH_SLOTS_HAVE_LASTITEM
	slot->lastitem = slot->firstitem;
#endif
	slot->length = 1;
}

void initialize_biquad(t_biquad *biquad){
	biquad->bandwidth_x1 = biquad->bandwidth_x2 = -1;
	biquad->filter_type = k_FILTER_NONE;
	biquad->a1 = biquad->a2 = biquad->b0 = biquad->b1 = biquad->b2 = 0;
	biquad->gain_dB = 0;
	biquad->Q = 1;
	biquad->cutoff_freq = 440;
	biquad->shelfslope = 0;
	biquad->bandwidth = 0;
	biquad->t = 0;
}


t_biquad interpolate_biquad(t_notation_obj *r_ob, t_biquad biquad1, t_biquad biquad2, double t_interp, char mode){
	t_biquad out;
	double p;
	
	if (biquad2.t == biquad1.t)
		return biquad1;
	
	initialize_biquad(&out);
	p = (t_interp - biquad1.t)/(biquad2.t - biquad1.t);
	
	if (mode == 0){ // only coefficients are interpolated
		out.a0 = (1-p) * biquad1.a0 + p * biquad2.a0; 
		out.a1 = (1-p) * biquad1.a1 + p * biquad2.a1; 
		out.a2 = (1-p) * biquad1.a2 + p * biquad2.a2; 
		out.b0 = (1-p) * biquad1.b0 + p * biquad2.b0; 
		out.b1 = (1-p) * biquad1.b1 + p * biquad2.b1; 
		out.b2 = (1-p) * biquad1.b2 + p * biquad2.b2; 
	} else {
		out.cutoff_freq = (1-p) * biquad1.cutoff_freq + p * biquad2.cutoff_freq; 
		out.Q = (1-p) * biquad1.Q + p * biquad2.Q; 
		out.gain_dB = (1-p) * biquad1.gain_dB + p * biquad2.gain_dB; 
		out.filter_type = biquad1.filter_type;
		synchronize_biquad_coeff_from_freq_gain_and_Q(&out, r_ob->sampling_freq);
	}
	out.t = t_interp;
	return out;
}


void notation_item_check_slots(t_notation_obj *r_ob, t_notation_item *nitem)
{
#ifdef BACH_CHECK_NOTATION_ITEMS
    long i;
    for (i = 0; i < CONST_MAX_SLOTS; i++) {
        t_slot *s = notation_item_get_slot(r_ob, nitem, i);
        t_slotitem *item = s ? s->firstitem : NULL;
        while (item) {
            if ((long)item > 0 && (long)item < 1000) {
                long foo = 7;
                foo++;
                bach_breakpoint(0);
            }
            if ((long)item->item > 0 && (long)item->item < 1000) {
                long foo = 7;
                foo++;
                bach_breakpoint(0);
            }
            item = item->next;
        }
    }
#endif
}


void notation_item_check_against_tuttipoints(t_notation_obj *r_ob, t_notation_item *nitem)
{
#ifdef BACH_CHECK_NOTATION_ITEMS
    t_tuttipoint *test = *((t_tuttipoint **) ((long)r_ob + sizeof(t_notation_obj)));
    long step = sizeof(t_tuttipoint);
    long nitemstep = 0;
    switch (nitem->type) {
        case k_CHORD:
            nitemstep = sizeof(t_chord);
            break;
        case k_NOTE:
            nitemstep = sizeof(t_note);
            break;
            
        default:
            break;
    }
    while (test) {
        if (((long)test < (long)nitem && (long)test + step > (long)nitem) ||
            ((long)nitem < (long) test && (long)nitem + nitemstep > (long)test)) {
            long foo = 7;
            foo++;
            bach_breakpoint(0);
        }
        test = test->next;
    }
#endif
}




void notation_item_check(t_notation_obj *r_ob, t_notation_item *nitem)
{
#ifdef BACH_CHECK_NOTATION_ITEMS
    notation_item_check_against_tuttipoints(r_ob, nitem);
    notation_item_check_slots(r_ob, nitem);
    if ((long)nitem->group > 0 && (long)nitem->group < 1000)
        bach_breakpoint(0);
    
    switch (nitem->type) {
        case k_NOTE:
            if (!((t_note *)nitem)->firstbreakpoint || !((t_note *)nitem)->lastbreakpoint)
                bach_breakpoint(0);
            if (!((t_note *)nitem)->parent)
                bach_breakpoint(0);
            break;

        case k_CHORD:
            if (!((t_note *)nitem)->parent)
                bach_breakpoint(0);
            break;

        default:
            break;
    }
    
#endif
}


void notation_item_check_force(t_notation_obj *r_ob, t_notation_item *nitem)
{
/*    notation_item_check_against_tuttipoints(r_ob, nitem);
    notation_item_check_slots(r_ob, nitem);
    if ((long)nitem->group > 0 && (long)nitem->group < 1000)
        bach_breakpoint(0);
  */
    switch (nitem->type) {
        case k_NOTE:
            if (!((t_note *)nitem)->firstbreakpoint || !((t_note *)nitem)->lastbreakpoint)
                bach_breakpoint(0);
            if (!((t_note *)nitem)->parent)
                bach_breakpoint(0);
            break;
            
        case k_CHORD:
            if (!((t_note *)nitem)->parent)
                bach_breakpoint(0);
            break;
            
        default:
            break;
    }
}


void notation_obj_check(t_notation_obj *r_ob)
{
#ifdef BACH_CHECK_NOTATION_ITEMS
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_scorevoice *voice;
        t_measure *measure;
        t_chord *chord;
        t_note *note;
        for (voice = (t_scorevoice *)r_ob->firstvoice; voice && voice->v_ob.number < r_ob->num_voices; voice = (t_scorevoice *)voice_get_next(r_ob, (t_voice *)voice)) {
            notation_item_check(r_ob, (t_notation_item *)voice);
            for (measure = voice->firstmeasure; measure; measure = measure->next) {
                notation_item_check(r_ob, (t_notation_item *)measure);
                for (chord = measure->firstchord; chord; chord = chord->next) {
                    notation_item_check(r_ob, (t_notation_item *)chord);
                    for (note = chord->firstnote; note; note = note->next)
                        notation_item_check(r_ob, (t_notation_item *)note);
                }
            }
        }
    }
#endif
}

void notation_obj_check_force(t_notation_obj *r_ob, char also_lock_mutex)
{
//    return;
#ifdef CONFIGURATION_Development
    if (also_lock_mutex)
        lock_general_mutex(r_ob);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_scorevoice *voice;
        t_measure *measure;
        t_chord *chord;
        t_note *note;
        for (voice = (t_scorevoice *)r_ob->firstvoice; voice && voice->v_ob.number < r_ob->num_voices; voice = (t_scorevoice *)voice_get_next(r_ob, (t_voice *)voice)) {
            notation_item_check_force(r_ob, (t_notation_item *)voice);
            for (measure = voice->firstmeasure; measure; measure = measure->next) {
                notation_item_check_force(r_ob, (t_notation_item *)measure);
                for (chord = measure->firstchord; chord; chord = chord->next) {
                    notation_item_check_force(r_ob, (t_notation_item *)chord);
                    for (note = chord->firstnote; note; note = note->next) {
                        if (!note->parent) {
                            char foo = 7;
                            foo++;
                        }
                        notation_item_check_force(r_ob, (t_notation_item *)note);
                    }
                }
            }
        }
    }
    if (also_lock_mutex)
        unlock_general_mutex(r_ob);
#endif
}



void notation_obj_check_against_tuttipoints(t_notation_obj *r_ob)
{
#ifdef BACH_CHECK_NOTATION_ITEMS
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_scorevoice *voice;
        t_measure *measure;
        t_chord *chord;
        t_note *note;
        for (voice = (t_scorevoice *)r_ob->firstvoice; voice && voice->v_ob.number < r_ob->num_voices; voice = (t_scorevoice *)voice_get_next(r_ob, (t_voice *)voice)) {
            notation_item_check_against_tuttipoints(r_ob, (t_notation_item *)voice);
            for (measure = voice->firstmeasure; measure; measure = measure->next) {
                notation_item_check_against_tuttipoints(r_ob, (t_notation_item *)measure);
                for (chord = measure->firstchord; chord; chord = chord->next) {
                    notation_item_check_against_tuttipoints(r_ob, (t_notation_item *)chord);
                    for (note = chord->firstnote; note; note = note->next)
                        notation_item_check_against_tuttipoints(r_ob, (t_notation_item *)note);
                }
            }
        }
    }
#endif
}



void notation_item_set_slots_from_llll(t_notation_obj *r_ob, t_notation_item *nitem, t_llll* slots)
{
	if (!nitem)
		return;
	
#ifdef BACH_CHECK_NOTATION_ITEMS
    notation_item_check_slots(r_ob, nitem);
#endif
    
	if (slots) {
		t_llllelem *elem;
		for (elem = slots->l_head; elem; elem = elem->l_next) { // elem iterates on the slot
			long type = hatom_gettype(&elem->l_hatom);
			if (type == H_LLLL) { // there's a nested list. this has to be true for all the slots
				t_llll *this_slot = hatom_getllll(&elem->l_hatom); 
				if (this_slot->l_size >= 1) { // valid size! at least the slot number + another thing;
					
					// the first value tells us the number of the slot
					t_llllelem *head = this_slot->l_head;

					// slot number are 1-based in the interface, 0-based inside the code
					long j = llllelem_to_slotnum(r_ob, head, true);

					if (head->l_next) {
						
						if (j >= 0 && j < CONST_MAX_SLOTS) {
							double slotmin, slotmax;
                            t_slot *slot = notation_item_get_slot(r_ob, nitem, j);
                            
							// we erase the slot
							notation_item_clear_slot(r_ob, nitem, j);
							
							slotmin = r_ob->slotinfo[j].slot_range[0];	
							slotmax = r_ob->slotinfo[j].slot_range[1];
							//  now it depends on the slot
							switch (r_ob->slotinfo[j].slot_type) {
								case k_SLOT_TYPE_FUNCTION:
								{
                                    t_llll *sorted_ll = llll_clone(this_slot);
                                    llll_behead(sorted_ll);
                                    llll_mergesort_inplace(&sorted_ll, llll_sort_by_first, NULL);

                                    t_llllelem *subelem;
									for (subelem = sorted_ll->l_head /* this_slot->l_head->l_next */; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										long subtype = hatom_gettype(&subelem->l_hatom);
										if (subtype == H_LLLL) { // must be a llll: in the form (x y slope) or (x y)
											t_llll *single_point = hatom_getllll(&subelem->l_hatom);
											if ((single_point->l_size >= 2)  && (single_point->l_size <= 3)) {
												double x_val, y_val, slope;
												t_pts *point;
												t_slotitem *thisitem = build_slotitem(r_ob, slot);
												x_val = hatom_getdouble(&single_point->l_head->l_hatom);
												y_val = hatom_getdouble(&single_point->l_head->l_next->l_hatom);
												if (single_point->l_size == 2) 
													slope = 0;
												else
													slope = hatom_getdouble(&single_point->l_head->l_next->l_next->l_hatom);
                                                slot_clip_domain_value(r_ob, nitem, j, &x_val);
												clip_double(&y_val, slotmin, slotmax);
												clip_double(&slope, -1., 1.);
												point = (t_pts *)bach_newptr(sizeof(t_pts));
												point->x = x_val; point->y = y_val; point->slope = slope;
												thisitem->item = point;
												slotitem_append(thisitem); // points are ordered! we just have to append them
											}
										}
									}
                                    
                                    llll_free(sorted_ll);

									break;
								}
								case k_SLOT_TYPE_3DFUNCTION:
								{
									double slotzmin = r_ob->slotinfo[j].slot_zrange[0];	
									double slotzmax = r_ob->slotinfo[j].slot_zrange[1];
									t_llllelem *subelem;

                                    t_llll *sorted_ll = llll_clone(this_slot);
                                    llll_behead(sorted_ll);
                                    llll_mergesort_inplace(&sorted_ll, llll_sort_by_first, NULL);

									for (subelem = sorted_ll->l_head; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										long subtype = hatom_gettype(&subelem->l_hatom);
										if (subtype == H_LLLL) { // must be a llll: in the form (x y z slope) or (x y z)
											t_llll *single_point = hatom_getllll(&subelem->l_hatom);
											if ((single_point->l_size >= 3)  && (single_point->l_size <= 4)) {
												double x_val, y_val, z_val, slope;
												t_pts3d *point;
												t_slotitem *thisitem = build_slotitem(r_ob, slot);
												x_val = hatom_getdouble(&single_point->l_head->l_hatom);
												y_val = hatom_getdouble(&single_point->l_head->l_next->l_hatom);
												z_val = hatom_getdouble(&single_point->l_head->l_next->l_next->l_hatom);
												if (single_point->l_size == 3) 
													slope = 0;
												else
													slope = hatom_getdouble(&single_point->l_head->l_next->l_next->l_next->l_hatom);
                                                slot_clip_domain_value(r_ob, nitem, j, &x_val);
												clip_double(&y_val, slotmin, slotmax);
												clip_double(&z_val, slotzmin, slotzmax); 
												clip_double(&slope, -1., 1.);
												point = (t_pts3d *)bach_newptr(sizeof(t_pts3d));
												point->x = x_val; 
												point->y = y_val; 
												point->z = z_val;
												point->slope = slope;
												thisitem->item = point;
												slotitem_append(thisitem); // points are ordered! we just have to append them
											}
										}
									}

                                    llll_free(sorted_ll);
                                    break;
								}
								case k_SLOT_TYPE_SPAT:
								{
                                    t_llll *sorted_ll = llll_clone(this_slot);
                                    llll_behead(sorted_ll);
                                    llll_mergesort_inplace(&sorted_ll, llll_sort_by_first, NULL);

                                    t_llllelem *subelem;
									for (subelem = sorted_ll->l_head; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										long subtype = hatom_gettype(&subelem->l_hatom);
										if (subtype == H_LLLL) { // must be a llll: in the form (t radius angle) or (t radius)
											t_llll *single_point = hatom_getllll(&subelem->l_hatom);
											if ((single_point->l_size >= 2)  && (single_point->l_size <= 4)) {
												double t_val, r_val, angle;
												long interp;
												t_spatpt *point;
												t_slotitem *thisitem = build_slotitem(r_ob, slot);
												t_val = hatom_getdouble(&single_point->l_head->l_hatom);
												r_val = hatom_getdouble(&single_point->l_head->l_next->l_hatom);
												if (single_point->l_size == 2) {
													angle = 0; interp = k_SPAT_INTERPOLATION_ARC;
												} else {
													angle = deg2rad(hatom_getdouble(&single_point->l_head->l_next->l_next->l_hatom));
													interp = (single_point->l_size >= 4) ? hatom_getlong(&single_point->l_head->l_next->l_next->l_next->l_hatom) : k_SPAT_INTERPOLATION_ARC;
												}
                                                slot_clip_domain_value(r_ob, nitem, j, &t_val);
                                                clip_double(&r_val, slotmin, slotmax);
												clip_double(&angle, -CONST_MAX_TURN_ANGLE * 2 * M_PI, CONST_MAX_TURN_ANGLE * 2 * M_PI);
												clip_long(&interp, 0, 1);
												point = (t_spatpt *)bach_newptr(sizeof(t_spatpt));
												point->t = t_val; point->radius = r_val; point->angle = angle; point->interp = (char) interp;
												thisitem->item = point;
												slotitem_append(thisitem); // points are ordered! we just have to append them
											}
										}
									}
                                    llll_free(sorted_ll);
									break;
								}
								case k_SLOT_TYPE_INT:
								{
									t_llllelem *subelem = this_slot->l_head->l_next;
									t_slotitem *thisitem = build_slotitem(r_ob, slot);
									long *val = (long *)bach_newptr(sizeof(long));
									*val = hatom_getlong(&subelem->l_hatom);
									clip_long(val, round(slotmin), round(slotmax));
									thisitem->item = val;
									slotitem_append(thisitem);
									break;
								}

								case k_SLOT_TYPE_FLOAT:
								{
									t_llllelem *subelem = this_slot->l_head->l_next;
									t_slotitem *thisitem = build_slotitem(r_ob, slot);
									double *val = (double *)bach_newptr(sizeof(double));
									*val = hatom_getdouble(&subelem->l_hatom);
									clip_double(val, slotmin, slotmax);
									thisitem->item = val;
									slotitem_append(thisitem);
									break;
								}
								case k_SLOT_TYPE_INTLIST:
								{
									t_llllelem *subelem;
									for (subelem = this_slot->l_head->l_next; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										long *val = (long *)bach_newptr(sizeof(long));
										t_slotitem *thisitem = build_slotitem(r_ob, slot);
										*val = hatom_getlong(&subelem->l_hatom);
										clip_long(val, round(slotmin), round(slotmax));
										thisitem->item = val;
										slotitem_append(thisitem);
									}
									break;
								}
                                case k_SLOT_TYPE_ARTICULATIONS:
                                {
                                    t_llllelem *subelem;
                                    for (subelem = this_slot->l_head->l_next; subelem; subelem = subelem->l_next) { // elem iterates on the slot
                                        long art_ID = hatom_gettype(&subelem->l_hatom) == H_SYM ? notationobj_articulation_symbol2id(r_ob, hatom_getsym(&subelem->l_hatom)) : hatom_getlong(&subelem->l_hatom);
                                        t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                        t_articulation *art = build_articulation(r_ob, art_ID, nitem, thisitem, hatom_getsym(&subelem->l_hatom));
                                        thisitem->item = art;
                                        slotitem_append(thisitem);
                                    }
                                    break;
                                }
                                case k_SLOT_TYPE_NOTEHEAD:
                                {
                                    t_llllelem *subelem;
                                    for (subelem = this_slot->l_head->l_next; subelem; subelem = subelem->l_next) { // elem iterates on the slot
                                        t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                        t_symbol *s = hatom_gettype(&subelem->l_hatom) == H_SYM ? hatom_getsym(&subelem->l_hatom) : _llllobj_sym_none;
                                        thisitem->item = s;
                                        slotitem_append(thisitem);
                                    }
                                    break;
                                }
                                case k_SLOT_TYPE_DYNAMICS:
                                {
                                    t_llll *cloned_ll = llll_clone(this_slot);
                                    t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                    llll_behead(cloned_ll);
                                    t_dynamics *dyn = dynamics_from_llll(r_ob, nitem, cloned_ll);
                                    thisitem->item = dyn;
                                    slotitem_append(thisitem);
                                    llll_free(cloned_ll);
                                    break;
                                }
                                case k_SLOT_TYPE_FLOATLIST:
								{
									t_llllelem *subelem;
									for (subelem = this_slot->l_head->l_next; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										double *val = (double *)bach_newptr(sizeof(double));
										t_slotitem *thisitem = build_slotitem(r_ob, slot);
										*val = hatom_getdouble(&subelem->l_hatom);
										clip_double(val, slotmin, slotmax);
										thisitem->item = val;
										slotitem_append(thisitem);
									}
									break;
								}
								case k_SLOT_TYPE_TEXT:
								{
									t_llllelem *subelem = this_slot->l_head->l_next;
									t_symbol *text = (hatom_gettype(&subelem->l_hatom) == H_SYM) ? hatom_getsym(&subelem->l_hatom) : _llllobj_sym_empty_symbol;
									long numchars = MAX(0, strlen(text->s_name));
									t_slotitem *thisitem = build_slotitem(r_ob, slot);
									thisitem->item = (char *)bach_newptr((numchars + 10) * sizeof(char));
									memcpy(thisitem->item, text->s_name, numchars * sizeof(char));
									((char *) thisitem->item)[numchars] = 0;
									slot->length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
									slotitem_append(thisitem);
									slot->length = numchars;
									break;
								}
                                case k_SLOT_TYPE_LLLL:
                                case k_SLOT_TYPE_INTMATRIX:
                                case k_SLOT_TYPE_FLOATMATRIX:
                                case k_SLOT_TYPE_TOGGLEMATRIX:
								{
#ifdef BACH_NEW_LLLLSLOT_SYNTAX
                                    if (r_ob->creatingnewobj && llllobj_get_version_number((t_object *)r_ob, LLLL_OBJ_UI) <= 70908) {
                                        t_llllelem *subelem = this_slot->l_head->l_next;
                                        t_llll *this_llll = (hatom_gettype(&subelem->l_hatom) == H_LLLL) ? hatom_getllll(&subelem->l_hatom) : NULL;
                                        if (this_llll) {
                                            t_llll *cloned = llll_clone(this_llll);
                                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                            thisitem->item = cloned;
                                            slot->length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
                                            slotitem_append(thisitem);
                                            slot->length = 1;
                                        }
                                    } else {
                                        t_llll *this_llll = llll_clone(this_slot);
                                        if (this_llll) {
                                            llll_behead(this_llll);
                                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                            thisitem->item = this_llll;
                                            slot->length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
                                            slotitem_append(thisitem);
                                            slot->length = 1;
                                        }
                                    }
#else
									t_llllelem *subelem = this_slot->l_head->l_next;
									t_llll *this_llll = (hatom_gettype(&subelem->l_hatom) == H_LLLL) ? hatom_getllll(&subelem->l_hatom) : NULL;
									if (this_llll) {
										t_llll *cloned = llll_clone(this_llll);
										t_slotitem *thisitem = build_slotitem(r_ob, slot);
										thisitem->item = cloned;
										slot->length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
										slotitem_append(thisitem);
										slot->length = 1;
									}
#endif
									break;
								}		
#ifdef BACH_MAX
								case k_SLOT_TYPE_FILELIST:
								{
									t_llllelem *subelem;
									t_llllelem *end_elem = NULL;
									long active_file_index = 1; 
									long i = 1;
									if (hatom_gettype(&this_slot->l_tail->l_hatom) == H_LONG) {
										active_file_index = hatom_getlong(&this_slot->l_tail->l_hatom);
										end_elem = this_slot->l_tail;
									}
									for (subelem = this_slot->l_head->l_next; subelem && subelem != end_elem; subelem = subelem->l_next) { // elem iterates on the slot
										t_symbol *single_path = (hatom_gettype(&subelem->l_hatom) == H_SYM) ? hatom_getsym(&subelem->l_hatom) : _llllobj_sym_empty_symbol;
										t_slotitem *thisitem = build_slotitem(r_ob, slot);
										t_file *file;
										file = (t_file *)bach_newptr(sizeof(t_file));
										set_file_from_symbol(r_ob, file, single_path);
										thisitem->item = file;
										if (i == active_file_index)
                                            slot_set_active_item(slot, thisitem);
										slotitem_append(thisitem); // files are ordered! we just have to append them
										i++;
									}	
									break;
								}
									
								case k_SLOT_TYPE_FILTER:
								{
									t_slotitem *thisitem = build_slotitem(r_ob, slot);
									t_biquad *biquad = (t_biquad *)bach_newptr(sizeof(t_biquad));
									t_llll *biquadllll;
									
									initialize_biquad(biquad);
									biquadllll = llll_clone(this_slot);
									
									if (biquadllll && biquadllll->l_head)
										llll_behead(biquadllll);
									
									set_biquad_filter_from_llll(r_ob, biquad, biquadllll);
									thisitem->item = biquad;
									slotitem_append(thisitem);
									llll_free(biquadllll);
									break;
								}
									
								case k_SLOT_TYPE_DYNFILTER:
								{
									t_llllelem *subelem;
									for (subelem = this_slot->l_head->l_next; subelem; subelem = subelem->l_next) { // elem iterates on the slot
										if (hatom_gettype(&subelem->l_hatom) == H_LLLL) {
											t_slotitem *thisitem = build_slotitem(r_ob, slot);
											t_biquad *biquad = (t_biquad *)bach_newptr(sizeof(t_biquad));
											set_biquad_filter_from_llll(r_ob, biquad, hatom_getllll(&subelem->l_hatom));
											thisitem->item = biquad;
											slotitem_append(thisitem);
										}
									}
									break;
								}
									
								case k_SLOT_TYPE_COLOR:
								{
									t_jrgba *col = (t_jrgba *)bach_newptr(sizeof(t_jrgba));
									t_slotitem *thisitem = build_slotitem(r_ob, slot);
									t_llll *col_llll;
									
									*col = get_grey(0);
									col_llll = llll_clone(this_slot);
									
									if (col_llll && col_llll->l_head)
										llll_behead(col_llll);
									
									change_color_according_to_llll(col, col_llll);
									
									thisitem->item = col;
									slotitem_append(thisitem);
									llll_free(col_llll);
									break;
								}
#endif
							}
						}
					} else {
						notation_item_clear_slot(r_ob, nitem, j);
					}
					
                    t_chord *ch = notation_item_get_parent_chord(r_ob, nitem);
					if (r_ob->link_lyrics_to_slot > 0 && r_ob->link_lyrics_to_slot - 1 == j && ch) { //i.e.: note is not dummy, since it has a parent!
						if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
							recompute_all_for_measure(r_ob, ch->parent, false);
						else
							ch->need_recompute_parameters = true;
                        set_need_perform_analysis_and_change_flag(r_ob);
					}
                    if (r_ob->link_dynamics_to_slot > 0 && r_ob->link_dynamics_to_slot - 1 == j && ch) { //i.e.: note is not dummy, since it has a parent!
                        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                            recompute_all_for_measure(r_ob, ch->parent, false);
                        else
                            ch->need_recompute_parameters = true;
                        set_need_perform_analysis_and_change_flag(r_ob);
                    }

                    if (r_ob->link_articulations_to_slot > 0 && r_ob->link_articulations_to_slot - 1 == j && ch)
                        reset_articulation_position_for_chord(r_ob, ch);
                    
				}
			}
			
		}
	}
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notation_item_check_slots(r_ob, nitem);
#endif

}

void note_set_slots_from_llll(t_notation_obj *r_ob, t_note *note, t_llll* slots)
{
    notation_item_set_slots_from_llll(r_ob, (t_notation_item *)note, slots);
}


void change_slot_long_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, long new_val, char val_given_as_delta)
{
//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && notation_item_get_slot_firstitem(r_ob, nitem, slot_num) && notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item) {
		// retrieve current value
		long slot_max = round(r_ob->slotinfo[slot_num].slot_range[1]); 
		long slot_min = round(r_ob->slotinfo[slot_num].slot_range[0]); // max and min values allowed for the slots
		long curr_val = slot_min;
		long *temp = ((long *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item);
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INT) // MUST be long, if we wanna call this function
			curr_val = *temp; // first (and only) long item
		*temp = (val_given_as_delta) ? curr_val + new_val : new_val; 
		if (*temp > slot_max) *temp = slot_max; // check validity
		if (*temp < slot_min) *temp = slot_min;
	}
}

void change_slot_float_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, double new_val, char val_given_as_delta) {
//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && notation_item_get_slot_firstitem(r_ob, nitem, slot_num) && notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item) {
		// retrieve current value
		double slot_max = r_ob->slotinfo[slot_num].slot_range[1]; 
		double slot_min = r_ob->slotinfo[slot_num].slot_range[0]; // max and min values allowed for the slots
		double curr_val = slot_min;
		double *temp = ((double *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item);
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOAT) // MUST be float, if we wanna call this function
			curr_val = *temp; // item value
		*temp = (val_given_as_delta) ? curr_val + new_val : new_val; 
		if (*temp > slot_max) *temp = slot_max; // check validity
		if (*temp < slot_min) *temp = slot_min;
	}
}

void change_slot_longlist_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, long new_val, char val_given_as_delta) {
//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && (slotitem) && (slotitem->item)) {
		// retrieve current value
		long slot_max = round(r_ob->slotinfo[slot_num].slot_range[1]); long slot_min = round(r_ob->slotinfo[slot_num].slot_range[0]); // max and min values allowed for the slots
		long curr_val = slot_min;
		long *temp = ((long *)slotitem->item);
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INTLIST) // MUST be longlist, if we wanna call this function
			curr_val = *temp; // first (and only) long item
		*temp = (val_given_as_delta) ? curr_val + new_val : new_val; 
		if (*temp > slot_max) *temp = slot_max; // check validity
		if (*temp < slot_min) *temp = slot_min;
	}
}

void change_slot_floatlist_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, double new_val, char val_given_as_delta) {
//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && (slotitem) && (slotitem->item)) {
		// retrieve current value
		double slot_max = r_ob->slotinfo[slot_num].slot_range[1]; double slot_min = r_ob->slotinfo[slot_num].slot_range[0]; // max and min values allowed for the slots
		double curr_val = slot_min;
		double *temp = ((double *)slotitem->item);
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOATLIST) // MUST be floatlist, if we wanna call this function
			curr_val = *temp; // item value
		*temp = (val_given_as_delta) ? curr_val + new_val : new_val; 
		if (*temp > slot_max) *temp = slot_max; // check validity
		if (*temp < slot_min) *temp = slot_min;
	}
}


void change_slot_matrix_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, long row, long col, double new_val, char val_given_as_delta) {
	if (slotitem && slotitem->item) {
		t_llll *matrix = (t_llll *) slotitem->item;
		if (matrix){
			t_llllelem *rowelem = llll_getindex(matrix, row, I_NON_NEGATIVE);
			
			if (!rowelem) {
				long i, howmany_rows_to_add = row - matrix->l_size; 
				for (i = 0; i < howmany_rows_to_add; i++)
					llll_appendllll(matrix, llll_get(), 0, WHITENULL_llll);
				rowelem = llll_getindex(matrix, row, I_NON_NEGATIVE);
			} else if (rowelem && hatom_gettype(&rowelem->l_hatom) != H_LLLL)
				hatom_change_to_llll(&rowelem->l_hatom, llll_get());
			
			if (rowelem && hatom_gettype(&rowelem->l_hatom) == H_LLLL) {
				t_llll *row_llll = hatom_getllll(&rowelem->l_hatom);
				t_llllelem *elem = llll_getindex(row_llll, col, I_NON_NEGATIVE);
				
				if (!elem) {
					long i, howmany_cols_to_add = col - row_llll->l_size; 
					for (i = 0; i < howmany_cols_to_add; i++)
						llll_appendlong(row_llll, 0, 0, WHITENULL_llll);
					elem = llll_getindex(row_llll, col, I_NON_NEGATIVE);
				}
				
				if (elem) {
					double curr_val = (hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_DOUBLE) ? hatom_getdouble(&elem->l_hatom) : 0;
					
					if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOATMATRIX)
						hatom_change_to_double_and_free(&elem->l_hatom, val_given_as_delta ? CLAMP(curr_val + new_val, r_ob->slotinfo[slot_num].slot_range[0], r_ob->slotinfo[slot_num].slot_range[1]) : CLAMP(new_val, r_ob->slotinfo[slot_num].slot_range[0], r_ob->slotinfo[slot_num].slot_range[1]));
					else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INTMATRIX)
						hatom_change_to_long_and_free(&elem->l_hatom, val_given_as_delta ? CLAMP(round(curr_val) + round(new_val), r_ob->slotinfo[slot_num].slot_range[0], r_ob->slotinfo[slot_num].slot_range[1]) : CLAMP(round(new_val), r_ob->slotinfo[slot_num].slot_range[0], r_ob->slotinfo[slot_num].slot_range[1]));
					else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_TOGGLEMATRIX)
						hatom_change_to_long_and_free(&elem->l_hatom, val_given_as_delta ? ( ((((long)round(curr_val) ? 1 : 0) + ((long)round(new_val))) % 2) ? 1 : 0 ) : 
																			( ((long)round(new_val)) ? 1 : 0 ));
				}
			}
		}
	}
}


void change_slot_pts_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, double new_x_val, double new_y_val, double new_slope_val, char val_given_as_delta, long modifiers) {
	//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && (slotitem) && (slotitem->item)) {
		// retrieve current value
		double curr_x, curr_y, curr_slope;
		double slot_max = r_ob->slotinfo[slot_num].slot_range[1]; double slot_min = r_ob->slotinfo[slot_num].slot_range[0]; // max and min values allowed for the slots
		t_pts *temp = (t_pts *) slotitem->item;
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FUNCTION) { // MUST be function, if we wanna call this function
			curr_x = temp->x; 
			curr_y = temp->y; 
			curr_slope = temp->slope; // current values
		}
		
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == -1)
			temp->x = val_given_as_delta ? temp->x + new_x_val : new_x_val; 
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == 1)
			temp->y = val_given_as_delta ? temp->y + new_y_val : new_y_val; 
		temp->slope = val_given_as_delta ? temp->slope + new_slope_val : new_slope_val; 
		
		// check validity
        slot_clip_domain_value(r_ob, nitem, slot_num, &temp->x);
		clip_double(&temp->y, slot_min, slot_max);
		clip_double(&temp->slope, -1., 1.);
		if (slotitem->prev) { // not the first element: let's check if the x value is correctly AFTER the x value of the previous element
			double prev_x = ((t_pts *)slotitem->prev->item)->x;
			if (temp->x < prev_x) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->prev; t_slotitem *tmp_slot2;
					while (tmp_slot && (temp->x < ((t_pts *)tmp_slot->item)->x)){
						tmp_slot2 = tmp_slot->prev;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else 
					temp->x = prev_x;
			}
		}
		if (slotitem->next) { // not the last element: let's check if the x value is correctly AFTER the x value of the previous element
			double next_x = ((t_pts *)slotitem->next->item)->x;
			if (temp->x > next_x && (!slotitem->selected || !slotitem->next->selected)) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->next; t_slotitem *tmp_slot2;
					while (tmp_slot && (temp->x > ((t_pts *)tmp_slot->item)->x)){
						tmp_slot2 = tmp_slot->next;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else 
					temp->x = next_x;
			}
		}
	}
}


void change_slot_3dpts_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, double new_x_val, double new_y_val, double new_z_val, double new_slope_val, char val_given_as_delta, long modifiers)
{
	//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && slotitem && slotitem->item) {
		// retrieve current value
		double curr_x, curr_y, curr_z, curr_slope;
		double slot_max = r_ob->slotinfo[slot_num].slot_range[1]; 
		double slot_min = r_ob->slotinfo[slot_num].slot_range[0]; // max and min values allowed for the slots
		double slot_zmax = r_ob->slotinfo[slot_num].slot_zrange[1]; 
		double slot_zmin = r_ob->slotinfo[slot_num].slot_zrange[0]; // max and min values allowed for the slots
		t_pts3d *temp = (t_pts3d *) slotitem->item;
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_3DFUNCTION) { // MUST be function, if we wanna call this function
			curr_x = temp->x; 
			curr_y = temp->y; 
			curr_z = temp->z;
			curr_slope = temp->slope; // current values
		}
		
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == 1)
			temp->y = val_given_as_delta ? temp->y + new_y_val : new_y_val; 
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == -1)
			temp->x = val_given_as_delta ? temp->x + new_x_val : new_x_val; 
		temp->z = val_given_as_delta ? temp->z + new_z_val : new_z_val; 
		temp->slope = val_given_as_delta ? temp->slope + new_slope_val : new_slope_val; 
		
		// check validity
        slot_clip_domain_value(r_ob, nitem, slot_num, &temp->x);
		clip_double(&temp->y, slot_min, slot_max);
		clip_double(&temp->z, slot_zmin, slot_zmax);
		clip_double(&temp->slope, -1., 1.);
		if (slotitem->prev) { // not the first element: let's check if the x value is correctly AFTER the x value of the previous element
			double prev_x = ((t_pts3d *)slotitem->prev->item)->x;
			if (temp->x < prev_x) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->prev; t_slotitem *tmp_slot2;
					while (tmp_slot && (temp->x < ((t_pts3d *)tmp_slot->item)->x)){
						tmp_slot2 = tmp_slot->prev;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else 
					temp->x = prev_x;
			}
		}
		if (slotitem->next) { // not the last element: let's check if the x value is correctly AFTER the x value of the previous element
			double next_x = ((t_pts3d *)slotitem->next->item)->x;
			if (temp->x > next_x) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->next, *tmp_slot2;
					while (tmp_slot && (temp->x > ((t_pts3d *)tmp_slot->item)->x)){
						tmp_slot2 = tmp_slot->next;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else 
					temp->x = next_x;
			}
		}
	}
}

void change_slot_spatpts_value(t_notation_obj *r_ob, t_notation_item *nitem, int slot_num, t_slotitem *slotitem, double new_t_val, double new_r_val, double new_angle_val, char val_given_as_delta, long modifiers) {
	//  val_given_as_delta is 1 if the value is given as difference with the existing value, 0 otherwise
	if (nitem && (slotitem) && (slotitem->item)) {
		// retrieve current value
		double curr_t, curr_radius, curr_angle;
		double slot_max = r_ob->slotinfo[slot_num].slot_range[1]; double slot_min = r_ob->slotinfo[slot_num].slot_range[0]; // max and min values allowed for the slots
		t_spatpt *temp = (t_spatpt *) slotitem->item;
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_SPAT) { // MUST be spat, if we wanna call this function
			curr_t = temp->t; 
			curr_radius = temp->radius; 
			curr_angle = temp->angle;
		}
		
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == -1)
			temp->t = val_given_as_delta ? temp->t + new_t_val : new_t_val; 
		if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == 1)
			temp->radius = val_given_as_delta ? temp->radius + new_r_val : new_r_val; 
		temp->angle = val_given_as_delta ? temp->angle + new_angle_val : new_angle_val; 
		
		// check validity
        slot_clip_domain_value(r_ob, nitem, slot_num, &temp->t);
		clip_double(&temp->radius, slot_min, slot_max);
		clip_double(&temp->angle, -CONST_MAX_TURN_ANGLE * M_PI * 2, CONST_MAX_TURN_ANGLE * M_PI * 2);
		if (slotitem->prev) { // not the first element: let's check if the t value is correctly AFTER the t value of the previous element
			double prev_t = ((t_spatpt *)slotitem->prev->item)->t;
			if (temp->t < prev_t) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->prev; t_slotitem *tmp_slot2;
					while (tmp_slot && (temp->t < ((t_spatpt *)tmp_slot->item)->t)){
						tmp_slot2 = tmp_slot->prev;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else
					temp->t = prev_t;
			}
		}
		if (slotitem->next) { // not the last element: let's check if the t value is correctly AFTER the t value of the previous element
			double next_t = ((t_spatpt *)slotitem->next->item)->t;
			if (temp->t > next_t) {
				if (modifiers & eAltKey) {
					t_slotitem *tmp_slot = slotitem->next; t_slotitem *tmp_slot2;
					while (tmp_slot && (temp->t > ((t_spatpt *)tmp_slot->item)->t)){
						tmp_slot2 = tmp_slot->next;
						lock_general_mutex(r_ob);	
						slotitem_delete(r_ob, slot_num, tmp_slot);
						unlock_general_mutex(r_ob);	
						tmp_slot = tmp_slot2;
					}
				} else 
					temp->t = next_t;
			}
		}
	}
}


char is_llll_relative_modification(t_llll *values_as_llll)
{
    char there_is_a_relative_modification = false;
    if (values_as_llll->l_size >= 1) {
        for (t_llllelem *el = values_as_llll->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_tail && hatom_gettype(&ll->l_tail->l_hatom) == H_SYM) {
                    t_symbol *s = hatom_getsym(&ll->l_tail->l_hatom);
                    if (s == gensym("plus") || s == gensym("minus") || s == gensym("times") || s == gensym("div"))
                        there_is_a_relative_modification = true;
                    else
                        return 0;
                } else if (ll && ll->l_tail)
                    return 0;
            }
        }
    } else
        return 0;

    return there_is_a_relative_modification;
}

// position == -1 means ALL
void notation_item_change_slotitem(t_notation_obj *r_ob, t_notation_item *nitem, long slotnum, long position_1based, t_llll *new_values_as_llll, e_slot_changeslotitem_modes mode, char modify_existing, double modification_x_thresh)
{
    long position = position_1based;

    /*
    // old bw compatibility stuff ? NO, let's drop this
    if (BW_COMPATIBILITY && position < 0)
        mode = k_CHANGESLOTITEM_MODE_MODIFY_ALL;
    */
    
    if (position == 0)
        mode = k_CHANGESLOTITEM_MODE_APPEND;

    if (mode == k_CHANGESLOTITEM_MODE_MODIFY_ALL) {
        long numitems = notation_item_get_slot_numitems(r_ob, nitem, slotnum);
        long i;
        for (i = 1; i <= numitems; i++)
            notation_item_change_slotitem(r_ob, nitem, slotnum, i, new_values_as_llll, k_CHANGESLOTITEM_MODE_MODIFY_ONE);
        return;
    }
    
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slotnum);
    if (slotnum < 0 || slotnum >= CONST_MAX_SLOTS || !slot)
        return;
    
    long slot_type = r_ob->slotinfo[slotnum].slot_type;
   
    if (position < 0) // handling negative positions
        position = slot->length + position + 1;

    if (mode == k_CHANGESLOTITEM_MODE_DELETE_ALL) {
        // delete all slot items
        notation_item_clear_slot(r_ob, nitem, slotnum);

    } else if (mode == k_CHANGESLOTITEM_MODE_DELETE_ONE) {
        // delete a given slot item
        t_slotitem *it = NULL;
        
        if (new_values_as_llll && new_values_as_llll->l_head && hatom_gettype(&new_values_as_llll->l_head->l_hatom) == H_LLLL) {
            // deletion from X position
            t_llll *tmpll = hatom_getllll(&new_values_as_llll->l_head->l_hatom);
            if (tmpll && tmpll->l_head) {
                double xpos = hatom_getdouble(&tmpll->l_head->l_hatom);
                it = slot_xcoord_to_slotitem(r_ob, slotnum, slot, xpos, modification_x_thresh, NULL, NULL);
            } else {
                object_warn((t_object *)r_ob, "Wrong syntax for slotitem deletion!");
            }
        } else {
            // deletion from index
            it = notation_item_get_slot_nth_item(r_ob, nitem, slotnum, position - 1);
        }

        if (it)
            slotitem_delete(r_ob, slotnum, it);
        else
            object_warn((t_object *)r_ob, "Warning: there's no slotitem to delete!");

    } else {
        
        if (new_values_as_llll) {
            double slotmin, slotmax;
            t_llll *values_as_llll = llll_clone(new_values_as_llll); // we work on a cloned copy, because we want to change it!
            
            slotmin = r_ob->slotinfo[slotnum].slot_range[0];
            slotmax = r_ob->slotinfo[slotnum].slot_range[1];
            
            switch (slot_type) {
                case k_SLOT_TYPE_TEXT:
                case k_SLOT_TYPE_LLLL:
                case k_SLOT_TYPE_INT:
                case k_SLOT_TYPE_FLOAT:
                case k_SLOT_TYPE_COLOR:
                    mode = k_CHANGESLOTITEM_MODE_MODIFY_ONE;
                    position = 1;
                    break;
                    
                default:
                    break;
            }
 
            if (slot_type != k_SLOT_TYPE_TEXT && position > slot->length)
                mode = k_CHANGESLOTITEM_MODE_APPEND;
            
            if (slot_type != k_SLOT_TYPE_LLLL && values_as_llll->l_depth > 1 && !is_llll_relative_modification(values_as_llll)) {
                llll_flatten(values_as_llll, 1, 0); // possibly removing the outer level of parentheses [::: BUT WHY DID WE NEED THIS????]
            }
            
            
            if ((mode == k_CHANGESLOTITEM_MODE_APPEND || mode == k_CHANGESLOTITEM_MODE_PREPEND || mode == k_CHANGESLOTITEM_MODE_INSERT || mode == k_CHANGESLOTITEM_MODE_INSERT_AUTO) && modify_existing && values_as_llll->l_head) {
                // see if we can modify an existing point
                long idx = -1;
                t_slotitem *it = slot_xcoord_to_slotitem(r_ob, slotnum, slot, hatom_getdouble(&values_as_llll->l_head->l_hatom), modification_x_thresh, &idx, NULL);
                if (it) {
                    mode = k_CHANGESLOTITEM_MODE_MODIFY_ONE;
                    position = idx + 1;
                }
            }
            
            if (mode == k_CHANGESLOTITEM_MODE_APPEND || mode == k_CHANGESLOTITEM_MODE_PREPEND || mode == k_CHANGESLOTITEM_MODE_INSERT || mode == k_CHANGESLOTITEM_MODE_INSERT_AUTO) {
                
                // APPENDING a new value!
                switch (slot_type) {
                        
                    case k_SLOT_TYPE_FUNCTION:
                    {
                        if ((values_as_llll->l_size >= 2) && (values_as_llll->l_size <= 3)) {
                            double x_val, y_val, slope;
                            t_pts *point;
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            x_val = hatom_getdouble(&values_as_llll->l_head->l_hatom);
                            y_val = hatom_getdouble(&values_as_llll->l_head->l_next->l_hatom);
                            if (values_as_llll->l_size == 2)
                                slope = 0;
                            else
                                slope = hatom_getdouble(&values_as_llll->l_head->l_next->l_next->l_hatom);
                            slot_clip_domain_value(r_ob, nitem, slotnum, &x_val);
                            clip_double(&y_val, slotmin, slotmax);
                            clip_double(&slope, -1., 1.);
                            point = (t_pts *)bach_newptr(sizeof(t_pts));
                            point->x = x_val; point->y = y_val; point->slope = slope;
                            thisitem->item = point;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, k_CHANGESLOTITEM_MODE_INSERT_AUTO, position - 1);
                        }
                        break;
                    }
                    case k_SLOT_TYPE_3DFUNCTION:
                    {
                        double slotzmin = r_ob->slotinfo[slotnum].slot_zrange[0];
                        double slotzmax = r_ob->slotinfo[slotnum].slot_zrange[1];
                        if ((values_as_llll->l_size >= 3)  && (values_as_llll->l_size <= 4)) {
                            double x_val, y_val, z_val, slope;
                            t_pts3d *point;
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            x_val = hatom_getdouble(&values_as_llll->l_head->l_hatom);
                            y_val = hatom_getdouble(&values_as_llll->l_head->l_next->l_hatom);
                            z_val = hatom_getdouble(&values_as_llll->l_head->l_next->l_next->l_hatom);
                            if (values_as_llll->l_size == 3)
                                slope = 0;
                            else
                                slope = hatom_getdouble(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom);
                            slot_clip_domain_value(r_ob, nitem, slotnum, &x_val);
                            clip_double(&y_val, slotmin, slotmax);
                            clip_double(&z_val, slotzmin, slotzmax);
                            clip_double(&slope, -1., 1.);
                            point = (t_pts3d *)bach_newptr(sizeof(t_pts));
                            point->x = x_val;
                            point->y = y_val;
                            point->z = z_val;
                            point->slope = slope;
                            thisitem->item = point;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, k_CHANGESLOTITEM_MODE_INSERT_AUTO, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_SPAT:
                    {
                        if ((values_as_llll->l_size >= 2)  && (values_as_llll->l_size <= 3)) {
                            double t_val, r_val, angle;
                            long interp;
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            t_spatpt *point;
                            t_val = hatom_getdouble(&values_as_llll->l_head->l_hatom);
                            r_val = hatom_getdouble(&values_as_llll->l_head->l_next->l_hatom);
                            if (values_as_llll->l_size == 2) {
                                angle = 0; interp = k_SPAT_INTERPOLATION_ARC;
                            } else {
                                angle = deg2rad(hatom_getdouble(&values_as_llll->l_head->l_next->l_next->l_hatom));
                                interp = (values_as_llll->l_size >= 4) ? hatom_getlong(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom) : k_SPAT_INTERPOLATION_ARC;
                            }
                            slot_clip_domain_value(r_ob, nitem, slotnum, &t_val);
                            clip_double(&r_val, slotmin, slotmax);
                            clip_double(&angle, -CONST_MAX_TURN_ANGLE * 2 * M_PI, CONST_MAX_TURN_ANGLE * 2 * M_PI);
                            clip_long(&interp, 0, 1);
                            point = (t_spatpt *)bach_newptr(sizeof(t_spatpt));
                            point->t = t_val;
                            point->radius = r_val;
                            point->angle = angle;
                            point->interp = (char) interp;
                            thisitem->item = point;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, k_CHANGESLOTITEM_MODE_INSERT_AUTO, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_INT: case k_SLOT_TYPE_INTLIST:
                    {
                        if (values_as_llll->l_head) {
                            t_slotitem *thisitem = build_default_slotitem(r_ob, slot, slotnum);
                            change_long(r_ob, ((long *)thisitem->item), NULL, values_as_llll->l_head, 0, nitem);
                            clip_long(((long *)thisitem->item), round(slotmin), round(slotmax));
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_ARTICULATIONS:
                    {
                        if (values_as_llll->l_head) {
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM) {
                                thisitem->item = build_articulation(r_ob, notationobj_articulation_symbol2id(r_ob, hatom_getsym(&values_as_llll->l_head->l_hatom)), nitem, thisitem, hatom_getsym(&values_as_llll->l_head->l_hatom));
                            } else {
                                thisitem->item = build_articulation(r_ob, hatom_getlong(&values_as_llll->l_head->l_hatom), nitem, thisitem, notationobj_articulation_id2symbol(r_ob, hatom_getlong(&values_as_llll->l_head->l_hatom)));
                            }
                            ((t_articulation *)thisitem->item)->need_recompute_position = true;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_DYNAMICS:
                    {
                        if (values_as_llll->l_head) {
                            t_slotitem *thisitem = build_default_slotitem(r_ob, slot, slotnum);
                            t_dynamics *dyn = dynamics_from_llll(r_ob, nitem, values_as_llll);
                            thisitem->item = dyn;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_NOTEHEAD:
                    {
                        if (values_as_llll->l_head) {
                            t_slotitem *thisitem = build_default_slotitem(r_ob, slot, slotnum);
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM)
                                thisitem->item = hatom_getsym(&values_as_llll->l_head->l_hatom);
                            else
                                thisitem->item = _llllobj_sym_none;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }

                        
                    case k_SLOT_TYPE_FLOAT: case k_SLOT_TYPE_FLOATLIST:
                    {
                        if (values_as_llll->l_head) {
                            t_slotitem *thisitem = build_default_slotitem(r_ob, slot, slotnum);
                            change_double(r_ob, ((double *)thisitem->item), NULL, values_as_llll->l_head, 0, nitem);
                            clip_double(((double *)thisitem->item), slotmin, slotmax);
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                    case k_SLOT_TYPE_TEXT:
                    {
                        if (values_as_llll->l_head) {
                            t_symbol *text = (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM) ? hatom_getsym(&values_as_llll->l_head->l_hatom) : _llllobj_sym_empty_symbol;
                            long numchars = strlen(text->s_name);
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            if (thisitem->item)
                                bach_freeptr(thisitem->item);
                            thisitem->item = (char *)bach_newptr((numchars + 10) * sizeof(char));
                            memcpy(thisitem->item, text->s_name, numchars * sizeof(char));
                            ((char *)thisitem->item)[numchars] = 0;
                            slot->length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                            slot->length = numchars;
                        }
                        break;
                    }
                    case k_SLOT_TYPE_LLLL: case k_SLOT_TYPE_INTMATRIX: case k_SLOT_TYPE_FLOATMATRIX: case k_SLOT_TYPE_TOGGLEMATRIX:
                    {
                        
#ifdef BACH_NEW_LLLLSLOT_SYNTAX
                        t_llll *this_llll = values_as_llll ? llll_clone(values_as_llll) : NULL;
                        if (this_llll) {
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            if (thisitem->item)
                                llll_free((t_llll *) thisitem->item);
                            thisitem->item = this_llll;
                            slot->length = 0;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                            slot->length = 1;
                        }
#else
                        if (values_as_llll->l_head) {
                            t_llll *this_llll = (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LLLL) ? hatom_getllll(&values_as_llll->l_head->l_hatom) : NULL;
                            if (this_llll) {
                                t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                t_llll *cloned = llll_clone(this_llll);
                                if (thisitem->item)
                                    llll_free((t_llll *) thisitem->item);
                                thisitem->item = cloned;
                                slot->length = 0;
                                slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                                slot->length = 1;
                            }
                        }
#endif
                        break;
                        
                    }
#ifdef BACH_MAX
                    case k_SLOT_TYPE_FILELIST:
                    {
                        if (values_as_llll->l_head) {
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM) {
                                t_file *file = (t_file *)bach_newptr(sizeof(t_file));
                                t_symbol *single_path = hatom_getsym(&values_as_llll->l_head->l_hatom);
                                t_slotitem *thisitem = build_slotitem(r_ob, slot);
                                set_file_from_symbol(r_ob, file, single_path);
                                thisitem->item = file;
                                slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                            }
                            if (hatom_gettype(&values_as_llll->l_tail->l_hatom) == H_LONG) {
                                long act_item = hatom_getlong(&values_as_llll->l_tail->l_hatom);
                                if (act_item == 0)
                                    slot_set_active_item(slot, slot_get_last_item(slot));
                                else if (act_item < 0)
                                    slot_set_active_item(slot, NULL);
                                else {
                                    t_slotitem *tmp = slot->firstitem; long count = 1;
                                    while (tmp) {
                                        if (count == act_item) {
                                            slot_set_active_item(slot, tmp);
                                            break;
                                        }
                                        tmp = tmp->next;
                                        count++;
                                    }
                                }
                            }
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_FILTER: case k_SLOT_TYPE_DYNFILTER:
                    {
                        if (values_as_llll->l_head) {
                            t_biquad *biquad = (t_biquad *)bach_newptr(sizeof(t_biquad));
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            initialize_biquad(biquad);
                            set_biquad_filter_from_llll(r_ob, biquad, values_as_llll);
                            thisitem->item = biquad;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_COLOR:
                    {
                        if (values_as_llll->l_head) {
                            t_jrgba *col = (t_jrgba *)bach_newptr(sizeof(t_jrgba));
                            t_slotitem *thisitem = build_slotitem(r_ob, slot);
                            *col = build_jrgba(0, 0, 0, 1);
                            change_color_according_to_llll(col, values_as_llll);
                            thisitem->item = col;
                            slotitem_insert_extended(r_ob, slotnum, thisitem, mode, position - 1);
                        }
                        break;
                    }
                        
#endif
                }
                
            } else {
                
                // modifying a single specific slot item
                
                long i;
                t_slotitem *sl_item = slot->firstitem;
                for (i = 1; (i < position) && sl_item; i++)
                    sl_item = sl_item->next;
                switch (r_ob->slotinfo[slotnum].slot_type) {
                    case k_SLOT_TYPE_INT: case k_SLOT_TYPE_INTLIST:
                        if (values_as_llll->l_head) {
                            change_long(r_ob, ((long *)sl_item->item), NULL, values_as_llll->l_head, 0, nitem);
                            clip_long(((long *)sl_item->item), round(slotmin), round(slotmax));
                        }
                        break;
                    case k_SLOT_TYPE_FLOAT: case k_SLOT_TYPE_FLOATLIST:
                        if (values_as_llll->l_head) {
                            change_double(r_ob, ((double *)sl_item->item), NULL, values_as_llll->l_head, 0, nitem);
                            clip_double(((double *)sl_item->item), slotmin, slotmax);
                        }
                        break;
                    case k_SLOT_TYPE_ARTICULATIONS:
                        if (values_as_llll->l_head) {
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM)
                                ((t_articulation *)sl_item->item)->articulation_ID = notationobj_articulation_symbol2id(r_ob, hatom_getsym(&values_as_llll->l_head->l_hatom));
                            else
                                ((t_articulation *)sl_item->item)->articulation_ID = hatom_getlong(&values_as_llll->l_head->l_hatom);
                            ((t_articulation *)sl_item->item)->need_recompute_position = true;
                        }
                        break;
                        
                    case k_SLOT_TYPE_NOTEHEAD:
                        if (values_as_llll->l_head) {
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM)
                                sl_item->item = hatom_getsym(&values_as_llll->l_head->l_hatom);
                            else
                                sl_item->item = _llllobj_sym_none;
                        }
                        break;
                        
                    case k_SLOT_TYPE_DYNAMICS:
                        if (values_as_llll->l_head) {
                            if (sl_item->item) {
                                dynamics_check_dependencies_before_deleting_it(r_ob, (t_dynamics *)sl_item->item);
                                free_dynamics(r_ob, (t_dynamics *)sl_item->item);
                            }
                            t_dynamics *dyn = dynamics_from_llll(r_ob, nitem, values_as_llll);
                            sl_item->item = dyn;
                        }
                        break;

                    case k_SLOT_TYPE_FUNCTION:
                    {
                        if (values_as_llll->l_head) {
                            if (is_hatom_number(&values_as_llll->l_head->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LLLL)
                                change_double(r_ob, &((t_pts *)sl_item->item)->x, NULL, values_as_llll->l_head, 0, nitem);
                            clip_double(&((t_pts *)sl_item->item)->x, 0., 1.);
                            if (values_as_llll->l_head->l_next && (is_hatom_number(&values_as_llll->l_head->l_next->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_pts *)sl_item->item)->y, NULL, values_as_llll->l_head->l_next, 0, nitem);
                            clip_double(&((t_pts *)sl_item->item)->y, slotmin, slotmax);
                            if (values_as_llll->l_head->l_next && values_as_llll->l_head->l_next->l_next && (is_hatom_number(&values_as_llll->l_head->l_next->l_next->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_pts *)sl_item->item)->slope, NULL, values_as_llll->l_head->l_next->l_next, 0, nitem);
                            clip_double(&((t_pts *)sl_item->item)->slope, -1., 1.);
                        }
                        break;
                    }
                    case k_SLOT_TYPE_3DFUNCTION:
                    {
                        if (values_as_llll->l_head) {
                            if (is_hatom_number(&values_as_llll->l_head->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LLLL)
                                change_double(r_ob, &((t_pts3d *)sl_item->item)->x, NULL, values_as_llll->l_head, 0, nitem);
                            clip_double(&((t_pts3d *)sl_item->item)->x, 0., 1.);
                            if (values_as_llll->l_head->l_next && (is_hatom_number(&values_as_llll->l_head->l_next->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_pts3d *)sl_item->item)->y, NULL, values_as_llll->l_head->l_next, 0, nitem);
                            clip_double(&((t_pts3d *)sl_item->item)->y, slotmin, slotmax);
                            if (values_as_llll->l_head->l_next && values_as_llll->l_head->l_next->l_next && (is_hatom_number(&values_as_llll->l_head->l_next->l_next->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_pts3d *)sl_item->item)->z, NULL, values_as_llll->l_head->l_next->l_next, 0, nitem);
                            clip_double(&((t_pts3d *)sl_item->item)->z, slotmin, slotmax);
                            if (values_as_llll->l_head->l_next && values_as_llll->l_head->l_next->l_next && values_as_llll->l_head->l_next->l_next->l_next &&
                                (is_hatom_number(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom) || hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_pts3d *)sl_item->item)->slope, NULL, values_as_llll->l_head->l_next->l_next->l_next, 0, nitem);
                            clip_double(&((t_pts3d *)sl_item->item)->slope, -1., 1.);
                        }
                        break;
                    }
                    case k_SLOT_TYPE_SPAT:
                    {
                        if (values_as_llll->l_head) {
                            if ((hatom_gettype(&values_as_llll->l_head->l_hatom) == H_DOUBLE) || (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LONG) || (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_RAT) || (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LLLL))
                                change_double(r_ob, &((t_spatpt *)sl_item->item)->t, NULL, values_as_llll->l_head, 0, nitem);
                            clip_double(&((t_spatpt *)sl_item->item)->t, 0., 1.);
                            if (values_as_llll->l_head->l_next && ((hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_DOUBLE) ||
                                                                   (hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_LONG) || (hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_RAT) || (hatom_gettype(&values_as_llll->l_head->l_next->l_hatom) == H_LLLL)))
                                change_double(r_ob, &((t_spatpt *)sl_item->item)->radius, NULL, values_as_llll->l_head->l_next, 0, nitem);
                            clip_double(&((t_spatpt *)sl_item->item)->radius, slotmin, slotmax);
                            if (values_as_llll->l_head->l_next && values_as_llll->l_head->l_next->l_next && ((hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_DOUBLE) ||
                                                                                                             (hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_LONG) || (hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_RAT) || (hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_hatom) == H_LLLL)))
                                change_double(r_ob, &((t_spatpt *)sl_item->item)->angle, NULL, values_as_llll->l_head->l_next->l_next, 1, nitem);
                            clip_double(&((t_spatpt *)sl_item->item)->angle, -CONST_MAX_TURN_ANGLE * 2 * M_PI, CONST_MAX_TURN_ANGLE * 2 * M_PI);
                            if (values_as_llll->l_head->l_next && values_as_llll->l_head->l_next->l_next && values_as_llll->l_head->l_next->l_next->l_next
                                && (hatom_gettype(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom) == H_LONG))
                                ((t_spatpt *)sl_item->item)->interp = hatom_getlong(&values_as_llll->l_head->l_next->l_next->l_next->l_hatom);
                            if (((t_spatpt *)sl_item->item)->interp < 0) ((t_spatpt *)sl_item->item)->interp = 0;
                            if (((t_spatpt *)sl_item->item)->interp > 1) ((t_spatpt *)sl_item->item)->interp = 1;
                        }
                        break;
                    }
#ifdef BACH_MAX
                    case k_SLOT_TYPE_FILELIST:
                    {
                        if (values_as_llll->l_head) {
                            if (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM) {
                                t_symbol *single_path = hatom_getsym(&values_as_llll->l_head->l_hatom);
                                t_file *this_file = (t_file *)sl_item->item;
                                set_file_from_symbol(r_ob, this_file, single_path);
                            }
                            if (hatom_gettype(&values_as_llll->l_tail->l_hatom) == H_LONG) {
                                long act_item = hatom_getlong(&values_as_llll->l_tail->l_hatom);
                                if (act_item < 0) {
                                    slot_set_active_item(slot, NULL);
                                } else {
                                    t_slotitem *tmp;
                                    long count = 1;
                                    if (act_item == 0) act_item = position;
                                    tmp = slot->firstitem;
                                    while (tmp) {
                                        if (count == act_item) {
                                            slot_set_active_item(slot, tmp);
                                            break;
                                        }
                                        tmp = tmp->next;
                                        count++;
                                    }
                                }
                            }
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_FILTER: case k_SLOT_TYPE_DYNFILTER:
                    {
                        if (values_as_llll->l_head) {
                            t_biquad *biquad = (t_biquad *)sl_item->item;
                            set_biquad_filter_from_llll(r_ob, biquad, values_as_llll);
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_COLOR:
                    {
                        if (values_as_llll->l_head) {
                            t_jrgba *col = (t_jrgba *)sl_item->item;
                            change_color_according_to_llll(col, values_as_llll);
                        }
                        break;
                    }
#endif
                    case k_SLOT_TYPE_TEXT:
                    {
                        if (values_as_llll->l_head) {
                            t_symbol *sym = (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_SYM) ? hatom_getsym(&values_as_llll->l_head->l_hatom) : _llllobj_sym_empty_symbol;
                            long len = strlen(sym->s_name);
                            if (!sl_item) {
                                build_default_data_for_text_slot(r_ob, nitem, slotnum);
                                sl_item = slot->firstitem;
                            }
                            if (sl_item->item) 
                                bach_freeptr(sl_item->item);
                            sl_item->item = (char *)bach_newptr((len + 10) * sizeof(char));
                            memcpy((char *)sl_item->item, sym->s_name, len * sizeof(char));
                            ((char *)sl_item->item)[len] = 0;
                            slot->length = len; // or len + 1?
                        }
                        break;
                    }
                        
                    case k_SLOT_TYPE_LLLL: case k_SLOT_TYPE_INTMATRIX: case k_SLOT_TYPE_FLOATMATRIX: case k_SLOT_TYPE_TOGGLEMATRIX:
                    {
#ifdef BACH_NEW_LLLLSLOT_SYNTAX
                        t_llll *this_llll = llll_clone(values_as_llll);
                        if (this_llll) {
                            if (!sl_item) {
                                build_default_data_for_llll_slot(r_ob, nitem, slotnum);
                                sl_item = slot->firstitem;
                            }
                            if (sl_item->item)
                                llll_free((t_llll *) sl_item->item);
                            sl_item->item = this_llll;
                        }
#else
                        if (values_as_llll->l_head) {
                            t_llll *this_llll = (hatom_gettype(&values_as_llll->l_head->l_hatom) == H_LLLL) ? hatom_getllll(&values_as_llll->l_head->l_hatom) : NULL;
                            if (this_llll) {
                                t_llll *cloned = llll_clone(this_llll);
                                if (!sl_item) {
                                    build_default_data_for_llll_slot(r_ob, nitem, slotnum);
                                    sl_item = slot->firstitem;
                                }
                                if (sl_item->item)
                                    llll_free((t_llll *) sl_item->item);
                                sl_item->item = cloned;
                            }
                        }
#endif
                        break;
                    }
                        
                        
                        
                }
            }
            
            llll_free(values_as_llll);
        }
    }
	
    t_chord *ch = (nitem->type == k_CHORD ? (t_chord *)nitem : (nitem->type == k_NOTE ? ((t_note *)nitem)->parent : NULL));
	if (r_ob->link_lyrics_to_slot > 0 && r_ob->link_lyrics_to_slot - 1 == slotnum && ch) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			recompute_all_for_measure(r_ob, ch->parent, false);
		else
			ch->need_recompute_parameters = true;
	}
    
    if (r_ob->link_dynamics_to_slot > 0 && r_ob->link_dynamics_to_slot - 1 == slotnum && nitem) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            t_measure *meas = (t_measure *)notation_item_get_ancestor_of_at_least_a_certain_type(r_ob, nitem, k_MEASURE);
            if (meas)
                recompute_all_for_measure(r_ob, meas, false);
        } else {
            t_chord *ch = notation_item_get_parent_chord(r_ob, nitem);
            if (ch)
                ch->need_recompute_parameters = true;
        }
    }
	
}

void note_change_slot_item(t_notation_obj *r_ob, t_note *note, long slotnum, long position, t_llll *new_values_as_llll, e_slot_changeslotitem_modes mode, char modify_existing, double modification_x_thresh)
{
    notation_item_change_slotitem(r_ob, (t_notation_item *)note, slotnum, position, new_values_as_llll, mode, modify_existing, modification_x_thresh);
}

void set_biquad_coeffs(t_biquad *biquad, t_llll *llll){
	if (llll->l_size >= 5) {
		biquad->b0 = hatom_getdouble(&llll->l_head->l_hatom);
		biquad->b1 = hatom_getdouble(&llll->l_head->l_next->l_hatom);
		biquad->b2 = hatom_getdouble(&llll->l_head->l_next->l_next->l_hatom);
		biquad->a1 = hatom_getdouble(&llll->l_head->l_next->l_next->l_next->l_hatom);
		biquad->a2 = hatom_getdouble(&llll->l_head->l_next->l_next->l_next->l_next->l_hatom);
		biquad->a0 = 1;
	}
}

void set_biquad_filter_from_llll(t_notation_obj *r_ob, t_biquad *biquad, t_llll *llll){
	if (llll->l_head){
		t_llll *okllll = llll;
		
		if (llll->l_size >= 2 && 
			(llll->l_size <= 3 || (is_hatom_number(&llll->l_head->l_hatom) && hatom_gettype(&llll->l_head->l_next->l_hatom) == H_LLLL))) {
			// dynamic information
			biquad->t = hatom_getdouble(&llll->l_head->l_hatom);
			okllll = hatom_getllll(&llll->l_head->l_next->l_hatom);
		}
		
		if (okllll->l_size <= 4 || okllll->l_size == 6) {
			t_llllelem *freqelem = okllll->l_head;
			t_symbol *router = NULL;
			if (okllll->l_size == 6 && hatom_gettype(&okllll->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom) == H_LLLL) {
				t_llll *subllll = hatom_getllll(&okllll->l_head->l_next->l_next->l_next->l_next->l_next->l_hatom);
				if (subllll && subllll->l_head && hatom_gettype(&subllll->l_head->l_hatom) == H_SYM) {
					router = hatom_getsym(&subllll->l_head->l_hatom);
					if (router == _llllobj_sym_display || router == _llllobj_sym_none) {
						biquad->filter_type = k_FILTER_DISPLAY;
						set_biquad_coeffs(biquad, okllll);
						return;
					} else 
						freqelem = subllll->l_head->l_next;
				}
			} else if (okllll->l_size <= 4 && hatom_gettype(&okllll->l_head->l_hatom) == H_SYM) {
				router = hatom_getsym(&okllll->l_head->l_hatom);
				freqelem = okllll->l_head->l_next;
			} else if (okllll->l_size <= 4 && hatom_gettype(&okllll->l_head->l_hatom) == H_LLLL) {
				freqelem = okllll->l_head->l_next;
			}
			
			if (router)
				biquad->filter_type = filtersym_to_filtertype(router);
			
			if (freqelem)
				change_double(r_ob, &biquad->cutoff_freq, NULL, freqelem, false, NULL);
			if (freqelem && freqelem->l_next)
				change_double(r_ob, &biquad->gain_dB, NULL, freqelem->l_next, false, NULL);
			if (freqelem && freqelem->l_next && freqelem->l_next->l_next)
				change_double(r_ob, &biquad->Q, NULL, freqelem->l_next->l_next, false, NULL);

/*			if (freqelem && is_hatom_number(&freqelem->l_hatom))
				biquad->cutoff_freq = hatom_getdouble(&freqelem->l_hatom);
			if (freqelem && freqelem->l_next && is_hatom_number(&freqelem->l_next->l_hatom))
				biquad->gain_dB = hatom_getdouble(&freqelem->l_next->l_hatom);
			if (freqelem && freqelem->l_next && freqelem->l_next->l_next  && is_hatom_number(&freqelem->l_next->l_next->l_hatom))
				biquad->Q = hatom_getdouble(&freqelem->l_next->l_next->l_hatom);*/
		
			synchronize_biquad_coeff_from_freq_gain_and_Q(biquad, r_ob->sampling_freq);
		
		} else if (okllll->l_size == 5) {
			biquad->filter_type = k_FILTER_DISPLAY;
			set_biquad_coeffs(biquad, okllll);
		}
	}
}

void notation_item_clear_slot(t_notation_obj *r_ob, t_notation_item *nitem, int slot_number, char also_check_slot_recomputations)
{
	t_slotitem *temp_slotitem, *temp_slotitem2;
	if (!nitem || slot_number < 0 || slot_number >= CONST_MAX_SLOTS)
		return;
    t_slot *slot = notation_item_get_slot_extended(r_ob, nitem, slot_number, true);
	
    if (!slot)
        return; // nothing to do
    
	temp_slotitem = slot->firstitem;

	while (temp_slotitem) {
		temp_slotitem2 = temp_slotitem;
		temp_slotitem = temp_slotitem->next;
		if (!(temp_slotitem2->parent))
			post("Error in slot handling.");

		if (r_ob->j_mousedown_ptr == temp_slotitem2)
			set_mousedown(r_ob, NULL, k_NONE);

		slotitem_delete(r_ob, slot_number, temp_slotitem2);
		
	}
	slot->length = 0;
#ifdef BACH_SLOTS_HAVE_ACTIVEITEM
	slot->activeitem = NULL;
#endif
	slot->firstitem = NULL;
#ifdef BACH_SLOTS_HAVE_LASTITEM
	slot->lastitem = NULL;
#endif
    
	if (also_check_slot_recomputations && r_ob->obj_type != k_NOTATION_OBJECT_SLOT) // i.e. note is not dummy: it has a parent!
		check_slot_linkage_recomputations_for_notationitem(r_ob, nitem, slot_number);
}

void erase_all_notationitem_slots(t_notation_obj *r_ob, t_notation_item *nitem, char also_check_slot_recomputations)
{
    long i;
    for (i = 0; i < CONST_MAX_SLOTS; i++)
        notation_item_clear_slot(r_ob, nitem, i, also_check_slot_recomputations);
}


void note_clear_slot(t_notation_obj *r_ob, t_note *note, int slot_number, char also_check_slot_recomputations)
{
    notation_item_clear_slot(r_ob, (t_notation_item *)note, slot_number, also_check_slot_recomputations);
}





void move_notationitem_slot(t_notation_obj *r_ob, t_notation_item *nitem, int slot_from, int slot_to, char keep_original, char also_check_slot_recomputations)
{
    if (!nitem || slot_from < 0 || slot_from >= CONST_MAX_SLOTS || slot_to < 0 || slot_to >= CONST_MAX_SLOTS)
        return;
    
    t_llll *ll = notation_item_get_single_slot_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_DUMPING, slot_from, false);
    llll_behead(ll);
    llll_prependlong(ll, slot_to + 1);
    llll_wrap(&ll);
    notation_item_set_slots_from_llll(r_ob, nitem, ll);
    llll_free(ll);
    
    if (!keep_original)
        notation_item_clear_slot(r_ob, nitem, slot_from);
    
    if (also_check_slot_recomputations && r_ob->obj_type != k_NOTATION_OBJECT_SLOT) { // i.e. note is not dummy: it has a parent!
        check_slot_linkage_recomputations_for_notationitem(r_ob, nitem, slot_from);
        check_slot_linkage_recomputations_for_notationitem(r_ob, nitem, slot_to);
    }
}

void move_note_slot(t_notation_obj *r_ob, t_note *note, int slot_from, int slot_to, char keep_original, char also_check_slot_recomputations)
{
    move_notationitem_slot(r_ob, (t_notation_item *)note, slot_from, slot_to, keep_original, also_check_slot_recomputations);
}



// 0-based
void check_slot_linkage_recomputations_for_everything(t_notation_obj *r_ob, long changed_slot_index)
{
	long s = changed_slot_index;
	if (s >= 0 && s < CONST_MAX_SLOTS){ 
		long type = r_ob->slotinfo[s].slot_type;
		if (type == k_SLOT_TYPE_INT) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);

			if (r_ob->link_notehead_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);

		} else if (type == k_SLOT_TYPE_FLOAT) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);
			
		} else if (type == k_SLOT_TYPE_INTLIST) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);
			
		} else if (type == k_SLOT_TYPE_FLOATLIST) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);
			
			if (r_ob->link_notehead_adjust_to_slot - 1 == s)
				quick_notation_obj_recompute_all_chord_parameters(r_ob);
			
		} else if (type == k_SLOT_TYPE_TEXT) {
			if (r_ob->link_lyrics_to_slot - 1 == s) 
				quick_notation_obj_recompute_all_chord_parameters(r_ob);
            
        } else if (type == k_SLOT_TYPE_DYNAMICS) {
            if (r_ob->link_dynamics_to_slot - 1 == s)
                quick_notation_obj_recompute_all_chord_parameters(r_ob);
		}
	}
}


void check_slot_linkage_recomputations_for_active_notationitem(t_notation_obj *r_ob)
{
	check_slot_linkage_recomputations_for_notationitem(r_ob, r_ob->active_slot_notationitem, r_ob->active_slot_num);
}

// 0 based
void check_slot_linkage_recomputations_for_notationitem(t_notation_obj *r_ob, t_notation_item *nitem, long changed_slot_index)
{
    if (!nitem)
        return;
    
    t_chord *ch = NULL;
	long s = changed_slot_index;
    if (nitem->type == k_NOTE)
        ch = ((t_note *)nitem)->parent;
    else if (nitem->type == k_CHORD)
        ch = (t_chord *)nitem;
    
    if (!ch)
        return;
    
	if (s >= 0 && s < CONST_MAX_SLOTS){ 
		long type = r_ob->slotinfo[s].slot_type;
		if (type == k_SLOT_TYPE_INT) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				ch->need_recompute_parameters = true;
			
            if (r_ob->link_notehead_to_slot - 1 == s) {
                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
					recompute_all_for_measure(r_ob, ch->parent, false);
				else
					ch->need_recompute_parameters = true;
            }
			
		} else if (type == k_SLOT_TYPE_FLOAT) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				ch->need_recompute_parameters = true;
			
		} else if (type == k_SLOT_TYPE_INTLIST) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				ch->need_recompute_parameters = true;
			if (r_ob->link_notesize_to_slot - 1 == s)
				ch->need_recompute_parameters = true;
			
		} else if (type == k_SLOT_TYPE_FLOATLIST) {
			if (r_ob->link_notesize_to_slot - 1 == s)
				ch->need_recompute_parameters = true;
			
            if (r_ob->link_notehead_adjust_to_slot - 1 == s) {
				if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)	
					recompute_all_for_measure(r_ob, ch->parent, false);
				else
					ch->need_recompute_parameters = true;
            }
			
		} else if (type == k_SLOT_TYPE_TEXT) {
			if (r_ob->link_lyrics_to_slot - 1 == s) {
				ch->need_recompute_parameters = true;
				if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
					recompute_all_for_measure(r_ob, ch->parent, false);
			}

        } else if (type == k_SLOT_TYPE_NOTEHEAD) {
            if (r_ob->link_notehead_to_slot - 1 == s) {
                ch->need_recompute_parameters = true;
                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                    recompute_all_for_measure(r_ob, ch->parent, false);
            }

        } else if (type == k_SLOT_TYPE_ARTICULATIONS) {
            if (r_ob->link_articulations_to_slot - 1 == s) {
                ch->need_recompute_parameters = true;
                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                    recompute_all_for_measure(r_ob, ch->parent, false);
            }

        } else if (type == k_SLOT_TYPE_DYNAMICS) {
            if (r_ob->link_dynamics_to_slot - 1 == s) {
                ch->need_recompute_parameters = true;
                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                    recompute_all_for_measure(r_ob, ch->parent, false);
            }

        }
	}
	
	if (ch->need_recompute_parameters && r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
		set_need_perform_analysis_and_change_flag(r_ob);
	
}


char set_slots_to_selection(t_notation_obj *r_ob, t_llll *slots, char also_set_slots_to_rests)
{
// sets a slot to the selected items
	t_notation_item *curr_it = r_ob->firstselecteditem;

	char changed = 0;
	t_llll *clonedslots;
	
	lock_general_mutex(r_ob);	
	clonedslots = llll_clone(slots);
	
	curr_it = r_ob->firstselecteditem;
	while (curr_it) { // cycle on the selected items
		if (curr_it->type == k_NOTE) {
			changed = 1;
			create_simple_selected_notation_item_undo_tick(r_ob, curr_it, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
			note_set_slots_from_llll(r_ob, (t_note *)curr_it, clonedslots);
            
        } else if (curr_it->type == k_DYNAMICS) {
            t_notation_item *it = ((t_dynamics *)curr_it)->owner_item;
            changed = 1;
            create_simple_selected_notation_item_undo_tick(r_ob, it, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
            notation_item_set_slots_from_llll(r_ob, it, clonedslots);

		} else if (curr_it->type == k_CHORD) {
			t_note *temp;
			create_simple_selected_notation_item_undo_tick(r_ob, curr_it, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
            if (((t_chord *)curr_it)->firstnote) {
                for (temp = ((t_chord *)curr_it)->firstnote; temp; temp = temp->next) {
                    changed = 1;
                    note_set_slots_from_llll(r_ob, temp, clonedslots);
                }
            } else {
                if (also_set_slots_to_rests)
                    notation_item_set_slots_from_llll(r_ob, curr_it, clonedslots);
            }
		} else if (curr_it->type == k_MEASURE) {
			t_chord *temp; t_note *temp2;
			for (temp = ((t_measure *)curr_it)->firstchord; temp; temp = temp->next) {
				create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)temp, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                if (temp->firstnote) {
                    for (temp2 = temp->firstnote; temp2; temp2 = temp2->next) {
                        changed = 1;
                        note_set_slots_from_llll(r_ob, temp2, clonedslots);
                    }
                } else {
                    if (also_set_slots_to_rests)
                        notation_item_set_slots_from_llll(r_ob, (t_notation_item *)temp, clonedslots);
                }
			}
		}
		curr_it = curr_it->next_selected;
	}
	unlock_general_mutex(r_ob);	
	
	llll_free(clonedslots);
	return changed;
}


char set_breakpoints_to_selection(t_notation_obj *r_ob, t_llll *breakpoints)
{
    // sets a slot to the selected items
    t_notation_item *curr_it = r_ob->firstselecteditem;
    
    char changed = 0;
    t_llll *clonedbpts;
    
    lock_general_mutex(r_ob);
    clonedbpts = llll_clone(breakpoints);
    
    curr_it = r_ob->firstselecteditem;
    while (curr_it) { // cycle on the selected items
        if (curr_it->type == k_NOTE) {
            changed = 1;
            create_simple_selected_notation_item_undo_tick(r_ob, curr_it, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
            note_set_breakpoints_from_llll(r_ob, (t_note *)curr_it, clonedbpts);
        } else if (curr_it->type == k_CHORD) {
            t_note *temp;
            create_simple_selected_notation_item_undo_tick(r_ob, curr_it, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
            for (temp = ((t_chord *)curr_it)->firstnote; temp; temp = temp->next) {
                changed = 1;
                note_set_breakpoints_from_llll(r_ob, temp, clonedbpts);
            }
        } else if (curr_it->type == k_MEASURE) {
            t_chord *temp; t_note *temp2;
            for (temp = ((t_measure *)curr_it)->firstchord; temp; temp = temp->next) {
                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)temp, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                for (temp2 = temp->firstnote; temp2; temp2 = temp2->next) {
                    changed = 1;
                    note_set_breakpoints_from_llll(r_ob, temp2, clonedbpts);
                }
            }
        }
        curr_it = curr_it->next_selected;
    }
    unlock_general_mutex(r_ob);	
    
    llll_free(clonedbpts);
    return changed;
}



char is_pt_in_slot_window(t_notation_obj *r_ob, long point_x, long point_y){
	if ((point_x >= r_ob->slot_window_x1) && (point_x <= r_ob->slot_window_x2) &&
		(point_y >= r_ob->slot_window_y1) && (point_y <= r_ob->slot_window_y2))
		return 1;
	else
		return 0;
}


// returns -1 if the point is in the STRIP but NOT on the BAR HANDLE, returns 1 if the point is on the bar handle
char is_pt_in_slot_longfloat_strip(t_notation_obj *r_ob, long point_x, long point_y){
	
	double y1 = r_ob->slot_window_active_nozoom.y + CONST_SLOT_INT_FLOAT_BAR_Y_POS * r_ob->slot_window_active_nozoom.height;
	double y2 = y1 + CONST_SLOT_INT_FLOAT_BAR_Y_HEIGHT * r_ob->slot_window_active_nozoom.height;
	
	if (point_y >= y1 && point_y <= y2)
		return 1;
	return 0;
	
	double slot_window_height, bar_y_pos, bar_x_pos;
	int s = r_ob->active_slot_num;
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
	double slot_max = r_ob->slotinfo[s].slot_range[1]; double slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
	double curr_val; // let's retrieve the slot value
	if (get_activeitem_slot_firstitem(r_ob, s) && get_activeitem_slot_firstitem(r_ob, s)->item) {
		if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT)
			curr_val = *((long *)get_activeitem_slot_firstitem(r_ob, s)->item); // first (and only) long item
		else
			curr_val = *((double *)get_activeitem_slot_firstitem(r_ob, s)->item); // first (and only) double item
	} else {
		curr_val = slot_min;
	}
	slot_window_height = r_ob->slot_window_active_nozoom.height;
	bar_y_pos = r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height/ 2.;
	bar_x_pos = notationobj_rescale_with_slope_inv(r_ob, curr_val, slot_min, slot_max, r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X, r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X, r_ob->slotinfo[s].slot_range_par);
	if (fabs(point_y - bar_y_pos) < slot_window_height / 6.) 
		if (fabs(point_x - bar_x_pos) < CONST_SLOT_LONG_FLOAT_BAR_UWIDTH * zoom_y * 1.)
			return 1;
		else
			return -1;
	else
		return 0;
}

double get_slot_numberlist_single_bar_width(t_notation_obj *r_ob, long slot_num, t_notation_item *nitem)
{
	double slot_width = r_ob->obj_type == k_NOTATION_OBJECT_SLOT ? r_ob->slot_window_active.width : r_ob->slotinfo[slot_num].slot_uwidth * r_ob->zoom_y * r_ob->slot_window_zoom / 100.;
	double default_bar_width = CONST_SLOT_INTLIST_FLOATLIST_BAR_UWIDTH * r_ob->zoom_y * r_ob->slot_window_zoom / 100.;
    t_slot *slot = notation_item_get_slot(r_ob, nitem, slot_num);
    long num_elems = slot ? slot->length : 0;
	double needed_width_with_pad = (num_elems + 1) * default_bar_width;
	double bar_width = default_bar_width;
	if (needed_width_with_pad > slot_width) 
		// must reduce bars width
		bar_width = slot_width / (num_elems + 1);
	
	return bar_width * r_ob->slot_window_hzoom_factor;
}

long pt_to_slot_longfloatlistbar_strip(t_notation_obj *r_ob, long point_x, long point_y){
	if (!r_ob->active_slot_notationitem || r_ob->active_slot_num < 0)
		return -1;
	
	double bar_width = get_slot_numberlist_single_bar_width(r_ob, r_ob->active_slot_num, r_ob->active_slot_notationitem);
	long index = floor((point_x - r_ob->slot_window_active.x)/bar_width);
	return index;
}

// slotnum is 0 based
void open_slot_window(t_notation_obj *r_ob, long slot_num, t_notation_item *nitem, char resync_with_inspector)
{
    if (!nitem)
        return;
    
    if (slot_num >= 0 && slot_num < CONST_MAX_SLOTS && r_ob->slotinfo[slot_num].access_type != k_SLOT_ACCESS_CANT) {
        r_ob->active_slot_num = slot_num;
        r_ob->active_slot_num_1based = slot_num + 1;
        r_ob->active_slot_notationitem = nitem;
        r_ob->hovered_slotitem = NULL;
        r_ob->hovering_segment = false;
        clear_slot_window_selection(r_ob);
        if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT) {
            r_ob->slot_window_hzoom_factor = 1.;
            r_ob->slot_window_zoomed_start = 0.;
        }
        
        if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_COLOR && nitem && notation_item_get_slot_firstitem(r_ob, nitem, slot_num))
            r_ob->slot_top_right_color = get_01normalized_color(*((t_jrgba *)(notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item)));
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        if (resync_with_inspector)
            resync_bach_inspector_with_selection(r_ob);
    }
}


void close_slot_window(t_notation_obj *r_ob)
{
	r_ob->active_slot_num = -1;
    r_ob->active_slot_num_1based = 0;
    r_ob->active_slot_notationitem = NULL;
	r_ob->hovered_slotitem = NULL;
	r_ob->hovering_segment = false;
	clear_slot_window_selection(r_ob);
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}



char is_pt_in_inner_slot_subwindow(t_notation_obj *r_ob, t_pt pt){
	if (pt.x >= r_ob->slot_window_active_nozoom.x && pt.x <= r_ob->slot_window_active_nozoom.x + r_ob->slot_window_active_nozoom.width &&
		pt.y >= r_ob->slot_window_active_nozoom.y && pt.y <= r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height)
		return 1;
	
	return 0;
}

char is_pt_in_inner_slot_subwindow_with_tolerance(t_notation_obj *r_ob, t_pt pt, double tolerance){
	if (pt.x + tolerance >= r_ob->slot_window_active_nozoom.x && pt.x - tolerance<= r_ob->slot_window_active_nozoom.x + r_ob->slot_window_active_nozoom.width &&
		pt.y + tolerance>= r_ob->slot_window_active_nozoom.y && pt.y - tolerance<= r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height)
		return 1;
	
	return 0;
}



t_notation_item *get_activeitem_undo_item(t_notation_obj *r_ob)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
        return r_ob->active_slot_notationitem;
    
    switch (r_ob->active_slot_notationitem->type) {
        case k_NOTE:
            return (t_notation_item *)((t_note *)r_ob->active_slot_notationitem)->parent;
            break;

        case k_CHORD:
            return r_ob->active_slot_notationitem;
            break;

        default:
            return r_ob->active_slot_notationitem;
            break;
    }
}

t_slotitem *build_slotitem(t_notation_obj *r_ob, t_slot *parent)
{
	t_slotitem *thisitem = (t_slotitem *)bach_newptrclear(sizeof(t_slotitem));
	thisitem->parent = parent;
	return thisitem;
}

t_slotitem *build_default_slotitem(t_notation_obj *r_ob, t_slot *parent, long slot_num)
{
    t_slotitem *thisitem = build_slotitem(r_ob, parent);
    thisitem->item = NULL;
    if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INT || r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_INTLIST) {
        long *val = (long *)bach_newptr(sizeof(long));
        *val = r_ob->slotinfo[slot_num].slot_default;
        thisitem->item = val;
    } else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOAT || r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FLOATLIST) {
        double *val = (double *)bach_newptr(sizeof(double));
        *val = r_ob->slotinfo[slot_num].slot_default;
        thisitem->item = val;
    }
    return thisitem;
}

void clear_slot_window_selection(t_notation_obj *r_ob)
{
	t_llllelem *temp_el;
	for (temp_el = r_ob->selected_slot_items->l_head; temp_el; temp_el = temp_el->l_next) {
		t_slotitem *this_item = (t_slotitem *)hatom_getobj(&temp_el->l_hatom);
		this_item->selected = false;
	}
	llll_clear(r_ob->selected_slot_items);
}

void select_slotitem(t_notation_obj *r_ob, t_slotitem *item, e_selection_modes mode)
{
	t_llllelem *temp_el;
	char already_selected = false;
	
	for (temp_el = r_ob->selected_slot_items->l_head; temp_el; temp_el = temp_el->l_next) {
		t_slotitem *this_item = (t_slotitem *)hatom_getobj(&temp_el->l_hatom);
		if (this_item == item) {
			already_selected = true;
			if (mode == k_SELECTION_MODE_INVOLUTIVE || mode == k_SELECTION_MODE_FORCE_UNSELECT) {
				llll_destroyelem(temp_el);
				item->selected = false;
			}
			break;
		}
	}
	
	if (!already_selected) {
		if (mode == k_SELECTION_MODE_INVOLUTIVE || mode == k_SELECTION_MODE_FORCE_SELECT) {
			llll_appendobj(r_ob->selected_slot_items, item, 0, WHITENULL_llll);
			item->selected = true;
		}
	}
}

char slot_handle_mousewheel(t_notation_obj *r_ob, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc)
{
	long s = r_ob->active_slot_num;
	
	if (s < 0 || !r_ob->allow_horizontal_slot_zooming)
		return 0;
	
    if (((!slot_is_temporal(r_ob, s)) || r_ob->obj_type == k_NOTATION_OBJECT_SLOT) && is_pt_in_rectangle(pt, r_ob->slot_window)) {
		
		if (can_slot_be_hzoomed(r_ob, s) && (modifiers == eCommandKey || modifiers == eCommandKey + eShiftKey)) { // zoom
			double old_zoom = r_ob->slot_window_hzoom_factor;
			double new_zoom = old_zoom;
			
			new_zoom -= y_inc * CONST_Y_MOUSEWHEEL_FACTOR * (modifiers & eShiftKey ? CONST_FINER_FROM_KEYBOARD : 1.) / 100.;
			r_ob->slot_window_hzoom_factor = MAX(new_zoom, 1.);
			
			r_ob->slot_window_zoomed_start += ((pt.x - r_ob->slot_window_active_nozoom.x)/r_ob->slot_window_active_nozoom.width) * (1/old_zoom - 1/r_ob->slot_window_hzoom_factor);
			r_ob->slot_window_zoomed_start = CLAMP(r_ob->slot_window_zoomed_start, 0., 1 - 1./r_ob->slot_window_hzoom_factor);
			
			notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
			return 1;
		
        } else if (can_slot_be_hmoved(r_ob, s)) { // move
            double delta_x = (abs(y_inc) > abs(x_inc) ? y_inc : x_inc) * CONST_X_MOUSEWHEEL_FACTOR;
			if (modifiers & eShiftKey && modifiers & eCommandKey) 
				delta_x *= CONST_FINER_FROM_KEYBOARD;
			r_ob->slot_window_zoomed_start = (r_ob->slot_window_zoomed_start * r_ob->slot_window_active.width - delta_x)/r_ob->slot_window_active.width;
            if (can_slot_be_hzoomed(r_ob, s))
                r_ob->slot_window_zoomed_start = CLAMP(r_ob->slot_window_zoomed_start, 0., 1 - 1./r_ob->slot_window_hzoom_factor);
            else {
                r_ob->slot_window_zoomed_start = CLAMP(r_ob->slot_window_zoomed_start, 0., (r_ob->slot_window_active_unscrolled_width - r_ob->slot_window_active.width)/r_ob->slot_window_active.width);
            }
            
			notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
			return 1;
		}
	}
	
	return 0;
}

// returns 1 if something has been found (and thus the main function must return), 0 otherwise
// changed and redraw come from the main function
void slot_handle_mouseup(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers){
	long s = r_ob->active_slot_num;

    if (!slot_is_writable(r_ob, s))
        return;

	r_ob->slot_pen_mode = false;
	
	if (s > -1 && r_ob->active_slot_notationitem) {

		if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FUNCTION) {
			if (r_ob->j_mousedown_obj_type == k_SLOT_REGION) {
				// select slot items
				t_slotitem *item;
				double start_x_pos, start_y_pos, end_x_pos, end_y_pos; 
				pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, r_ob->j_mousedown_point, r_ob->active_slot_num, r_ob->slot_window_active, &start_x_pos, &start_y_pos);
				pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt, r_ob->active_slot_num, r_ob->slot_window_active, &end_x_pos, &end_y_pos);
				
				if (start_x_pos > end_x_pos) 
					swap_doubles(&start_x_pos, &end_x_pos);
				if (start_y_pos > end_y_pos) 
					swap_doubles(&start_y_pos, &end_y_pos);
					
				for (item = get_activeitem_slot_firstitem(r_ob, s); item; item = item->next) {
					t_pts *pts = (t_pts *)item->item;
					if (pts->x >= start_x_pos && pts->x <= end_x_pos && pts->y >= start_y_pos && pts->y <= end_y_pos) 
						select_slotitem(r_ob, item, k_SELECTION_MODE_INVOLUTIVE);
				}
			}
		}
	}
}

void delete_all_selected_function_points(t_notation_obj *r_ob, long slot_num)
{
	t_llll *cloned = llll_clone(r_ob->selected_slot_items);
	clear_slot_window_selection(r_ob);
	t_llllelem *elem;
	
	for (elem = cloned->l_head; elem; elem = elem->l_next) {
		t_slotitem *item = (t_slotitem *)hatom_getobj(&elem->l_hatom);
		slotitem_delete(r_ob, slot_num, item);
	}
}



t_slotitem *insert_new_slot_function_point(t_notation_obj *r_ob, long slot_num, double x_val, double y_val, double slope, 
										   char set_as_active_item, t_slotitem *delete_all_elements_between_the_new_slot_point_and_this_item)
{
	// we add a point
	t_slotitem *thisitem = build_slotitem(r_ob, get_activeitem_slot(r_ob, slot_num));
	t_pts *thispts = (t_pts *)bach_newptr(sizeof(t_pts));
	t_slotitem *temp;
	char forward_delete_elements = false;
	
	thispts->x = x_val;	
	thispts->y = y_val; 
	thispts->slope = slope; 
	thisitem->item = thispts; // correctly assign the point to the item
	
//	dev_post("x: %.2f, y: %.2f", x_val, y_val);
	
	// we check where we have to put the point within the list
	temp = get_activeitem_slot_firstitem(r_ob, slot_num);
	if (temp) {
		if (x_val < ((t_pts *)temp->item)->x)
			slotitem_prepend(thisitem); // first item
		else {
			char done = 0;
			while (temp) { // look for the element following our element
				if (x_val < ((t_pts *)temp->item)->x) {
					done = 1;
					break;
				}
				if (temp == delete_all_elements_between_the_new_slot_point_and_this_item) 
					forward_delete_elements = true;
				temp = temp->next;
			}
			if (done) // we have found the element following to our element
				slotitem_insert(thisitem, temp->prev, temp);
			else
				slotitem_append(thisitem); // last element
		}
	} else
		slotitem_append(thisitem); // TO DO: to be changed
	
	if (delete_all_elements_between_the_new_slot_point_and_this_item) {
		if (forward_delete_elements) {
			t_slotitem *temp2 = delete_all_elements_between_the_new_slot_point_and_this_item->next;
			while (temp2) {
				t_slotitem *next = temp2->next;
				if (temp2 == thisitem)
					break;
				slotitem_delete(r_ob, slot_num, temp2);
				temp2 = next;
			}
		} else {
			while (temp) {
				if (temp == delete_all_elements_between_the_new_slot_point_and_this_item) {
					t_slotitem *temp2 = temp->prev;
					while (temp2) {
						t_slotitem *prev = temp2->prev;
						if (temp2 == thisitem)
							break;
						slotitem_delete(r_ob, slot_num, temp2);
						temp2 = prev;
					}
					break;	
				}
				temp = temp->next;
			}
		}
	}
	
	if (set_as_active_item)
        slot_set_active_item(get_activeitem_slot(r_ob, slot_num), thisitem);
	
	return thisitem;
}


t_slotitem *append_new_numberlist_elem(t_notation_obj *r_ob, t_notation_item *nitem, long slot_num, t_notation_item *undo_item)
{
	long s = slot_num;
	t_slotitem *thisitem = build_slotitem(r_ob, notation_item_get_slot(r_ob, nitem, s));
	
	if (undo_item)
		create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
	
	if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST) {
		long *val = (long *)bach_newptr(sizeof(long));
		*val = round(CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1])); 
		thisitem->item = val;
	} else {
		double *val = (double *)bach_newptr(sizeof(double));
		*val = CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]); 
		thisitem->item = val;
	}
	slotitem_append(thisitem);
	return thisitem;
}



// returns 1 if something has been found (and thus the main function must return), 0 otherwise
// changed and redraw come from the main function
char slot_handle_mousedown(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers, e_element_types *clicked_obj, 
						   void **clicked_ptr, char *changed, char need_popup)
{
	double this_x = pt.x, this_y = pt.y;
    double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
    int s = r_ob->active_slot_num;
    t_slot *activeslot = get_activeitem_activeslot(r_ob);
	
    if (!slot_is_writable(r_ob, s))
        return 0;
    
	if (activeslot && r_ob->active_slot_num > -1) {
	
		r_ob->floatdragging_x = pt.x;
		r_ob->floatdragging_y = pt.y;
		
		if (r_ob->active_slot_notationitem) {
			t_notation_item *undo_item = get_activeitem_undo_item(r_ob);
			if (notation_item_is_globally_locked(r_ob, r_ob->active_slot_notationitem)) {
				if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
					close_slot_window((t_notation_obj *)r_ob);
				return 1;
			}
			if (is_pt_in_slot_window(r_ob, this_x, this_y) || r_ob->slotinfo[r_ob->active_slot_num].slot_type == k_SLOT_TYPE_3DFUNCTION) {
				switch (r_ob->slotinfo[s].slot_type) {
					case k_SLOT_TYPE_FUNCTION:
					{
						// with functions, we can add, delete points, change slope, move points... we can make a lot of things! :-)
						
						//long num_points = r_ob->active_slot_note->slot[s].length; // it's the number of points in the function
						//let's check if we've clicked on a point
						long retrieved_elem_type = k_SLOT_FUNCTION_POINT;
						t_slotitem *clicked = pt_to_function_slot_point(r_ob, pt, s, true, &retrieved_elem_type);
						
						if (clicked) { // something has been clicked
							if (retrieved_elem_type == k_SLOT_FUNCTION_SEGMENT) {
								*clicked_obj = k_SLOT_FUNCTION_SEGMENT;
								*clicked_ptr = clicked;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
								bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, modifiers == eControlKey ? BACH_CURSOR_CURVE : BACH_CURSOR_RESIZE_UPDOWN);
							} else {
								if (modifiers == eCommandKey) { // delete point
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									if (clicked->selected)
										delete_all_selected_function_points(r_ob, s);
									else {
										clear_slot_window_selection(r_ob);
										slotitem_delete(r_ob, s, clicked);
									}
									r_ob->changed_while_dragging = true;
									*changed = 1;
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								} else { //select point for deplacement
									*clicked_obj = clicked->selected ? k_SLOT_SELECTION : k_SLOT_FUNCTION_POINT;
									*clicked_ptr = clicked;
									set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
									bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_FOURWAY);
									if (!clicked->selected)
										clear_slot_window_selection(r_ob);
								}
							}
						} else { // nothing has been clicked: new point.
							if (is_pt_in_inner_slot_subwindow(r_ob, pt)) {
								
								if (modifiers & eShiftKey) {
									// we draw a slot region rectangle and select a range of slotitems
									*clicked_obj = k_SLOT_REGION;
									*clicked_ptr = NULL;
									set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
									
								} else if (!(modifiers & eCommandKey)) {
									
									// we add a point
									double x_val, y_val;
									t_slotitem *newitem;
									
									clear_slot_window_selection(r_ob);
									pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt, s, r_ob->slot_window_active, &x_val, &y_val);
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    slot_clip_domain_value(r_ob, r_ob->active_slot_notationitem, s, &x_val);
									newitem = insert_new_slot_function_point(r_ob, s, x_val, y_val, 0., true, NULL);
									
									r_ob->hovered_slotitem = newitem;
									r_ob->hovering_segment = false;
									
									if (modifiers & eControlKey)  {
										bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_PENCIL);
										r_ob->slot_pen_mode = true;
									}
									
									// the point is clicked upon
									*clicked_obj = k_SLOT_FUNCTION_POINT;
									*clicked_ptr = newitem;
									set_mousedown(r_ob, newitem, k_SLOT_FUNCTION_POINT);
									bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, r_ob->slot_pen_mode ? BACH_CURSOR_PENCIL : BACH_CURSOR_RESIZE_FOURWAY);
									
									r_ob->changed_while_dragging = true;
									*changed = 1;
								}
							} else {
								clear_slot_window_selection(r_ob);
							}
						}
					}
						break;
						
						
					case k_SLOT_TYPE_3DFUNCTION:
					{
						//let's check if we've clicked on a point
						t_slotitem *clicked = pt_to_3dfunction_slot_point(r_ob, pt, s);
						
						if (clicked) { // something has been clicked
							if (modifiers == eCommandKey) { // delete point
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								slotitem_delete(r_ob, s, clicked);
								r_ob->changed_while_dragging = true;
								*changed = 1;
								notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
							} else { //select point for deplacement
								*clicked_obj = k_SLOT_3DFUNCTION_POINT;
								*clicked_ptr = clicked;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
								bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_FOURWAY);
								jmouse_setcursor(patcherview, (t_object *) r_ob, JMOUSE_CURSOR_RESIZE_FOURWAY);
							}
						} else { // nothing has been clicked: 
							
							if (is_pt_in_slot_window(r_ob, this_x, this_y)) {
								if (!(modifiers & eCommandKey) && is_pt_in_inner_slot_subwindow(r_ob, pt)) {
									
									// we add a point
									t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
									t_pts3d *thispts = (t_pts3d *)bach_newptr(sizeof(t_pts3d));
									double x_val, y_val, z_val;
									t_slotitem *temp;
									
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									
									pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt, s, r_ob->slot_window_active, &x_val, &y_val);
                                    slot_clip_domain_value(r_ob, r_ob->active_slot_notationitem, s, &x_val);
									z_val = 0; // by default
									
									thispts->x = x_val;	
									thispts->y = y_val; 
									thispts->z = z_val; 
									thispts->slope = 0.; 
									thisitem->item = thispts; // correctly assign the point to the item
									// we check where we have to put the point within the list
									temp = get_activeitem_slot_firstitem(r_ob, s);
									if (temp) {
										if (x_val < ((t_pts3d *)temp->item)->x)
											slotitem_prepend(thisitem); // first item
										else {
											char done = 0;
											temp = temp->next;
											while (temp) { // look for the element following our element
												if (x_val < ((t_pts3d *)temp->item)->x) {
													done = 1;
													break;
												}
												temp = temp->next;
											}
											if (done) // we have found the element following to our element
												slotitem_insert(thisitem, temp->prev, temp);
											else
												slotitem_append(thisitem); // last element
										}
									} else
										slotitem_append(thisitem); // TO DO: to be changed
									
                                    slot_set_active_item(activeslot, thisitem);
									r_ob->hovered_slotitem = thisitem;
									r_ob->hovering_segment = false;
									
									// the point is selected
									*clicked_obj = k_SLOT_3DFUNCTION_POINT;
									*clicked_ptr = thisitem;
									set_mousedown(r_ob, thisitem, k_SLOT_3DFUNCTION_POINT);
									bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_FOURWAY);
									jmouse_setcursor(patcherview, (t_object*) r_ob, JMOUSE_CURSOR_RESIZE_FOURWAY);
									
									r_ob->changed_while_dragging = true;
									*changed = 1;
								}
							} else {
								if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
									close_slot_window(r_ob);
							}
						}
					} 
						break;
						
						
					case k_SLOT_TYPE_SPAT:
					{
						// with spat, just like with functions, we can add, delete points, change slope, move points... it makes a lot of things! :-)
						
						//let's check if we've clicked on a point
                        t_slotitem *clicked = pt_to_spat_slot_point(r_ob, pt, s);
						if (clicked) { // something has been clicked
							if (modifiers == eCommandKey) { // delete point
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								slotitem_delete(r_ob, s, clicked);
								r_ob->changed_while_dragging = true;
								*changed = 1;
								notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
							} else if (modifiers & eAltKey) { // change interpolation type
								t_spatpt *this_spatpt = (t_spatpt *) clicked->item;
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								this_spatpt->interp = (this_spatpt->interp == k_SPAT_INTERPOLATION_ARC) ? k_SPAT_INTERPOLATION_SEGMENT : k_SPAT_INTERPOLATION_ARC;
								*changed = 1;
								r_ob->changed_while_dragging = true;
								notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
							} else { //select point for deplacement
								*clicked_obj = k_SLOT_SPAT_POINT;
								*clicked_ptr = clicked;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
							}
						} else { // nothing has been clicked: new point.
							if (!(modifiers & eCommandKey) && is_pt_in_inner_slot_subwindow(r_ob, build_pt(this_x, this_y))) {
								// we add a point
								
								t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
								t_slotitem *temp;
								t_spatpt *thispts = (t_spatpt *)bach_newptr(sizeof(t_spatpt));
								double t_val, r_val;
								
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                
                                pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, build_pt(this_x, this_y), s, r_ob->slot_window_active, &t_val, &r_val);
/*
                                t_val = notationobj_rescale_with_slope(r_ob, this_x, r_ob->slot_window_active.x, r_ob->slot_window_active.x + r_ob->slot_window_active.width, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
								r_val = notationobj_rescale_with_slope(r_ob, (r_ob->slot_window_active.y + r_ob->slot_window_active.height) - this_y, 0, r_ob->slot_window_active.height, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
 */
                                slot_clip_domain_value(r_ob, r_ob->active_slot_notationitem, s, &t_val);
                                
								thispts->t = t_val;	thispts->radius = r_val; thispts->angle = 0.; thispts->interp = k_SPAT_INTERPOLATION_ARC;
								thisitem->item = thispts; // correctly assign the point to the item
								// we check where we have to put the point within the list
								temp = get_activeitem_slot_firstitem(r_ob, s); //  r_ob->active_slot_note->slot[s].lastitem
								if (temp) {
									if (t_val < ((t_spatpt *)temp->item)->t)
										slotitem_prepend(thisitem); // first item
									else {
										char done = 0;
										temp = temp->next;
										while (temp) { // look for the element following our element
											if (t_val < ((t_spatpt *)temp->item)->t) {
												done = 1;
												break;
											}
											temp = temp->next;
										}
										if (done) // we have found the element following to our element
											slotitem_insert(thisitem, temp->prev, temp);
										else
											slotitem_append(thisitem); // last element
									}
								} else
									slotitem_append(thisitem); // TO DO: to be changed
								
                                slot_set_active_item(activeslot, thisitem);
								
								// the point is selected
								*clicked_obj = k_SLOT_SPAT_POINT;
								*clicked_ptr = thisitem;
								set_mousedown(r_ob, thisitem, k_SLOT_SPAT_POINT);
								
								r_ob->changed_while_dragging = true;
								*changed = 1;
							}
						}
					}
						break;
						
						
					case k_SLOT_TYPE_INT:
					case k_SLOT_TYPE_FLOAT:
					{
						char res = is_pt_in_slot_longfloat_strip(r_ob, this_x, this_y);
						if (res != 0) { // clicked on the strip
							char redraw;
							if (modifiers == eCommandKey) {
								if (get_activeitem_slot_firstitem(r_ob, s)) {
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									slotitem_delete(r_ob, s, get_activeitem_slot_firstitem(r_ob, s));
									r_ob->changed_while_dragging = true;
									*changed = 1;
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								}
							} else {
								if (!get_activeitem_slot_firstitem(r_ob, s)) { // there's no data yet. we set the default value
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    t_slot *slot = activeslot;
                                    slot->firstitem = build_slotitem(r_ob, slot);
									slot->firstitem->next = NULL;
									slot->firstitem->prev = NULL;
									if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT) {
										long *head = (long *)bach_newptr(sizeof(long));
										*head = round(CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]));
										slot->firstitem->item = head;
									} else { //float case
										double *head = (double *)bach_newptr(sizeof(double));
										*head = CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]);
										slot->firstitem->item = head;
									}
#ifdef BACH_SLOTS_HAVE_LASTITEM
									slot->lastitem = slot->firstitem;
#endif
									slot->length = 1;
									*changed = redraw = 1;
									r_ob->changed_while_dragging = true;
								}
								
								*clicked_obj = k_SLOT_INT_FLOAT_BAR;
								*clicked_ptr = 0; // it doesn't really matter...
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
								
								if (modifiers == eCommandKey+eAltKey) { // if we clicked for the default value, we keep the default value
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT) 
										change_slot_long_value(r_ob, r_ob->active_slot_notationitem, s, round(CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1])), false);
									else if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FLOAT)
										change_slot_float_value(r_ob, r_ob->active_slot_notationitem, s, CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]), false);
									*changed = redraw = 1;
									r_ob->changed_while_dragging = true;
								} else {
									if (!(modifiers & eShiftKey)) { // Shift key is for relative modifications
										slot_handle_mousedrag(r_ob, patcherview, pt, modifiers, changed, &redraw);
										*changed = redraw = 1;
										r_ob->changed_while_dragging = true;
									}
								}

								if (redraw) 
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
							} 
						}
					}
						break;
						
						
					case k_SLOT_TYPE_INTLIST:
					case k_SLOT_TYPE_FLOATLIST:
					{
						if (is_pt_in_inner_slot_subwindow(r_ob, pt)) {
							long item_clicked = pt_to_slot_longfloatlistbar_strip(r_ob, this_x, this_y);
							
							if (item_clicked >= 0) {
								if (item_clicked < get_activeitem_slot_length(r_ob, s)) {
									t_slotitem *temp2 = get_activeitem_slot_firstitem(r_ob, s);
									long i = 0;
									while (i < item_clicked && temp2) { 
										i++; 
										temp2 = temp2->next; 
									}
									if (temp2) { // there is number data in the item
										if (modifiers == eCommandKey) { // delete data
											create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
											slotitem_delete(r_ob, s, temp2);
											*changed = 1;
											r_ob->changed_while_dragging = true;
										} else { 
											if (modifiers == eCommandKey+eAltKey){
												create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
												if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST) 
													change_slot_longlist_value(r_ob, r_ob->active_slot_notationitem, s, temp2, round(CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1])), false);
												else if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FLOATLIST)
													change_slot_floatlist_value(r_ob, r_ob->active_slot_notationitem, s, temp2, CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]), false);
												r_ob->changed_while_dragging = true;
												*changed = 1;
												notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
											} else {
												*clicked_obj = k_SLOT_INT_FLOAT_BAR;
												*clicked_ptr = temp2; 
												set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
												
												if (!(modifiers & eShiftKey)) {
													char redraw = false;
													create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
													slot_handle_mousedrag(r_ob, patcherview, pt, modifiers, changed, &redraw);
													
													r_ob->changed_while_dragging = true;
													*changed = 1;
													
													if (redraw) 
														notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
												}
											}
										}
									}
								} else {
									if (!(modifiers & eCommandKey)) {
										t_slotitem *thisitem = append_new_numberlist_elem(r_ob, r_ob->active_slot_notationitem, s, undo_item);
										r_ob->changed_while_dragging = true;
										*changed = 1;
										*clicked_obj = k_SLOT_INT_FLOAT_BAR;
										*clicked_ptr = thisitem; 
										set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
									}
								}
							}
						} 
					}
						break;
						
						
					case k_SLOT_TYPE_INTMATRIX:
					case k_SLOT_TYPE_FLOATMATRIX:
					case k_SLOT_TYPE_TOGGLEMATRIX:
					{
						double slot_window_table_y1 = r_ob->slot_window_table_y1;
						double slot_window_table_x1 = r_ob->slot_window_table_x1;
						double h_cell_size = (r_ob->slot_window_active_x2 - slot_window_table_x1) / r_ob->slotinfo[s].slot_num_cols;
						double v_cell_size = (r_ob->slot_window_active_y2 - slot_window_table_y1) / r_ob->slotinfo[s].slot_num_rows;
						
						if (this_y >= slot_window_table_y1 && this_y <= r_ob->slot_window_active_y2 &&
							this_x >= slot_window_table_x1 && this_x <= r_ob->slot_window_active_x2) {
							t_slotitem *temp2 = get_activeitem_slot_firstitem(r_ob, s);
							if (!temp2) {
								t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
								
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								
								thisitem->item = llll_get();
								slotitem_append(thisitem);
								temp2 = thisitem;
							}
							if (temp2 && temp2->item) {
								long clicked_row = floor((this_y - slot_window_table_y1)/v_cell_size) + LLLL_IDX_BASE;
								long clicked_col = floor((this_x - slot_window_table_x1)/h_cell_size) + LLLL_IDX_BASE;
								r_ob->slot_clicked_row = CLAMP(clicked_row, 1, r_ob->slotinfo[s].slot_num_rows);
								r_ob->slot_clicked_col = CLAMP(clicked_col, 1, r_ob->slotinfo[s].slot_num_cols);
								
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								
								if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_TOGGLEMATRIX) {
									if (modifiers == eCommandKey+eAltKey)
										change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, temp2, r_ob->slot_clicked_row, r_ob->slot_clicked_col, CLAMP(r_ob->slotinfo[s].slot_default, 0, 1), 0);
									else
										change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, temp2, r_ob->slot_clicked_row, r_ob->slot_clicked_col, 1, 1);
									r_ob->changed_while_dragging = true;
								} else {
									char redraw;
									*clicked_obj = k_SLOT_MATRIX_CELL;
									*clicked_ptr = temp2; 
									set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
									if (modifiers == eCommandKey+eAltKey) {
										if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTMATRIX)
											change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, temp2, r_ob->slot_clicked_row, r_ob->slot_clicked_col, round(CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1])), 0);
										else if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FLOATMATRIX)
											change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, temp2, r_ob->slot_clicked_row, r_ob->slot_clicked_col, CLAMP(r_ob->slotinfo[s].slot_default, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]), 0);
										redraw = true;
									} else 
										slot_handle_mousedrag(r_ob, patcherview, pt, modifiers, changed, &redraw);
									
									r_ob->changed_while_dragging = true;
									*changed = true;
									
									if (redraw) 
										notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								}
							}
						}
					}
						break;
						
                    case k_SLOT_TYPE_DYNAMICS:
					case k_SLOT_TYPE_TEXT:
					case k_SLOT_TYPE_LLLL:
					{
						if (modifiers == eCommandKey) {
							create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
							
                            notation_item_clear_slot(r_ob, r_ob->active_slot_notationitem, s);
                            
                            if ((r_ob->link_lyrics_to_slot > 0 && r_ob->link_lyrics_to_slot - 1 == s) ||
                                (r_ob->link_dynamics_to_slot > 0 && r_ob->link_dynamics_to_slot - 1 == s)) {
                                t_chord *ch = notation_item_get_parent_chord(r_ob, r_ob->active_slot_notationitem);
                                if (ch) {
                                    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                                        recompute_all_for_measure(r_ob, ch->parent, false);
                                    else
                                        ch->need_recompute_parameters = true;
                                }
                            }
                            
							r_ob->changed_while_dragging = true;
							*changed = 1;
						}
					}
						break;
                        
					case k_SLOT_TYPE_FILELIST:
					{
						int const y_file_inlet = CONST_SLOT_FILE_UY_START * zoom_y; 
						int const y_file_step = CONST_SLOT_FILE_UY_STEP * zoom_y;
						// which file has been clicked??
						long click_y_deplacement = this_y - (r_ob->slot_window_y1 + y_file_inlet);
						int file_clicked;
						if (click_y_deplacement > 0)
							file_clicked = floor((double) click_y_deplacement / (double) y_file_step);
						else
							file_clicked = -1;
						if (file_clicked > get_activeitem_slot_length(r_ob, s)) file_clicked = -1;
						
						if (file_clicked > -1){
							t_slotitem *temp2 = get_activeitem_slot_firstitem(r_ob, s); long i = 0;
							while ((i<file_clicked) && (temp2)) { i++; temp2 = temp2->next; }
							if (temp2) { // there is file data in the clicked file
								if (modifiers == eCommandKey) { // delete data
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									slotitem_delete(r_ob, s, temp2);
								} else if (modifiers & eShiftKey) {
									// re-select file
									t_fourcc outtype;
									char filename[512];
									short path;							
									
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									
									unlock_general_mutex(r_ob);	
									if (!(open_dialog(filename, &path, &outtype, NULL, 0))) {
										// if opendialog returns 0 everything is ok, NOT user-cancelled
										if (temp2->item) {
											t_file *file = (t_file*) temp2->item;
											snprintf_zero(file->filename, MAX_PATH_CHARS, filename);
											file->filename_length = strlen(filename);
											file->exists = true;
											file->pathID = path;
										} else {
											t_file *file = (t_file *)bach_newptr(sizeof(t_file));
											snprintf_zero(file->filename, MAX_PATH_CHARS, filename);
											file->pathID = path; 
											file->filename_length = strlen(filename);
											file->exists = true;
											temp2->item = file;
										}
										r_ob->changed_while_dragging = true;
                                        slot_set_active_item(activeslot, temp2);
									}
									lock_general_mutex(r_ob);	
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								} else { // just make file active
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									r_ob->changed_while_dragging = true;
                                    slot_set_active_item(activeslot, temp2);
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								}
							} else { // there is no data associated
								if (!(modifiers & eCommandKey)) {
									// select file
									t_fourcc outtype;
									char filename[512];
									short path;	
									
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									
									unlock_general_mutex(r_ob);	
									if (!(open_dialog(filename, &path, &outtype, NULL, 0))) {
										// if opendialog returns 0 everything is ok, NOT user-cancelled
										t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
										t_file *file;
										file = (t_file *)bach_newptr(sizeof(t_file));
										snprintf_zero(file->filename, MAX_PATH_CHARS, filename);
										file->pathID = path; file->filename_length = strlen(file->filename);
										thisitem->item = file;
										file->exists = true;
										slotitem_append(thisitem);
                                        slot_set_active_item(activeslot, thisitem);
										r_ob->changed_while_dragging = true;
										*changed = true;
									}
									lock_general_mutex(r_ob);	
									notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
								}
							}
						}
					} 
						break;
						
						
					case k_SLOT_TYPE_FILTER:
					{
						if (need_popup){
							// change filter?
							unlock_general_mutex(r_ob);	
							if (handle_filters_popup(r_ob, modifiers, NULL)){
								*changed = true;
								r_ob->changed_while_dragging = true;
							}
							lock_general_mutex(r_ob);
						} else if (modifiers == eCommandKey+eAltKey) { // if we clicked for the default value, we keep the default value
							t_biquad *bqd = (get_activeitem_slot_firstitem(r_ob, s) ? (t_biquad *) get_activeitem_slot_firstitem(r_ob, s)->item : NULL);
							
							if (bqd && bqd->gain_dB != 0) {
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								bqd->gain_dB = 0;
								synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
								*changed = 1;
								r_ob->changed_while_dragging = true;
							}
						}
					} 
						break;
						
						
					case k_SLOT_TYPE_DYNFILTER:
					{
						t_slotitem *clicked = pt_to_dynfilter_biquad(r_ob, pt, s);
						
						if (clicked || (!get_activeitem_slot_firstitem(r_ob, s) && need_popup)) { // something has been clicked or there was no data and we right-clicked
							if (need_popup){
								// change filter?
								unlock_general_mutex(r_ob);	
								if (handle_filters_popup(r_ob, modifiers, clicked)){
									*changed = true;
									r_ob->changed_while_dragging = true;
								}
								lock_general_mutex(r_ob);
							} else if (modifiers == eCommandKey) { // delete point
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								slotitem_delete(r_ob, s, clicked);
								r_ob->changed_while_dragging = true;
								*changed = 1;
								notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
							} else if (modifiers == eCommandKey+eAltKey) { // if we clicked for the default value, we keep the default value
								t_biquad *bqd = (t_biquad *) clicked->item;
								
								if (bqd && bqd->gain_dB != 0) {
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									bqd->gain_dB = 0;
									synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
									*changed = 1;
									r_ob->changed_while_dragging = true;
								}
							} else { //select point for deplacement
								*clicked_obj = k_SLOT_DYNFILTER_BIQUAD;
								*clicked_ptr = clicked;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
							}
							
						}
					}
						break;
						
						
					case k_SLOT_TYPE_COLOR:
					{
						char redraw = 0;
						
						if (pt.y >= r_ob->slot_window_active_y1 && pt.y <= r_ob->slot_window_active_y2) {
							if (pt.x >= r_ob->slot_window_active_x1 && pt.x <= r_ob->slot_window_active_x1 + r_ob->slot_window_palette_width) {
								*clicked_obj = k_SLOT_COLOR_PALETTE;
								*clicked_ptr = WHITENULL;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
								if (!(modifiers & eControlKey)) { 
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									slot_handle_mousedrag(r_ob, patcherview, pt, 0, changed, &redraw);
								}
							} else if (pt.x >= r_ob->slot_window_spectrum_x && pt.x <= r_ob->slot_window_spectrum_x + r_ob->slot_window_spectrum_width) {
								*clicked_obj = k_SLOT_COLOR_SPECTRUM;
								*clicked_ptr = WHITENULL;
								set_mousedown(r_ob, *clicked_ptr, (e_element_types) *clicked_obj);
								if (!(modifiers & eControlKey)) { 
									create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
									slot_handle_mousedrag(r_ob, patcherview, pt, 0, changed, &redraw);
								}
							}
						}
						if (redraw)
							notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
					}
						break;
                        

                    case k_SLOT_TYPE_ARTICULATIONS:
                    {
                        long id = 0;
                        t_slotitem *item = pt_to_articulation_slotitem(r_ob, pt, s, r_ob->slot_window_active, &id);
                        t_chord *ch = notation_item_get_parent_chord(r_ob, r_ob->active_slot_notationitem);
                        if (item && modifiers & eCommandKey) {
                            create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                            slotitem_delete(r_ob, s, item);
                            if (ch)
                                reset_articulation_position_for_chord(r_ob, ch);
                            *changed = 1;
                            r_ob->changed_while_dragging = true;
                        } else if (!item && id > 0 && !(modifiers & eCommandKey)) {
                            create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                            t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
                            t_articulation *art = build_articulation(r_ob, id, r_ob->active_slot_notationitem, thisitem, notationobj_articulation_id2symbol(r_ob, id));
                            thisitem->item = art;
                            slotitem_append(thisitem);
                            if (ch)
                                reset_articulation_position_for_chord(r_ob, ch);
                            r_ob->changed_while_dragging = true;
                            *changed = true;
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_NOTEHEAD:
                    {
                        long id = 0;
                        t_chord *ch = notation_item_get_parent_chord(r_ob, r_ob->active_slot_notationitem);
                        if (modifiers & eCommandKey) {
                            if (get_activeitem_slot_firstitem(r_ob, s)) {
                                create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                slotitem_delete(r_ob, s, get_activeitem_slot_firstitem(r_ob, s));
                                if (ch) {
                                    ch->need_recompute_parameters = true;
                                    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                                        recompute_all_for_measure(r_ob, ch->parent, false);
                                }
                                *changed = 1;
                                r_ob->changed_while_dragging = true;
                            }
                        } else {
                            t_slotitem *item = pt_to_notehead_slotitem(r_ob, pt, s, r_ob->slot_window_active, &id);
                            if (!item && id >= 0 && !(modifiers & eCommandKey)) {
                                if (!get_activeitem_slot_firstitem(r_ob, s)) {
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
                                    thisitem->item = notationobj_notehead_id2symbol(r_ob, id);
                                    slotitem_append(thisitem);
                                } else {
                                    get_activeitem_slot_firstitem(r_ob, s)->item = notationobj_notehead_id2symbol(r_ob, id);
                                }
                                if (ch) { // if it's not the bach.slot dummy note
                                    ch->need_recompute_parameters = true;
                                    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                                        recompute_all_for_measure(r_ob, ch->parent, false);
                                }
                                r_ob->changed_while_dragging = true;
                                *changed = true;
                            }
                        }
                    }
                        break;

					default:
						break;
				}
			} else {
				// clicked outside the slot window
				char has_changed = 0;
				if (r_ob->is_editing_type == k_TEXT_IN_SLOT || r_ob->is_editing_type == k_LLLL_IN_SLOT || r_ob->is_editing_type == k_DYNAMICS_IN_SLOT) {
					end_editing_textfield(r_ob);
					has_changed = 1;
				}
				
				if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
					close_slot_window(r_ob);
				
				return has_changed;
			}
		
			if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
				check_slot_linkage_recomputations_for_active_notationitem(r_ob);

		} else { // something has gone wrong with slots, just return to normal view. 
			if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
				close_slot_window(r_ob);
		}
		return 1; // stop! we don't care about what else could have been clicked!
	}
	return 0;
}


// returns 1 if something has been found (and thus the main function must return), 0 otherwise
// changed and redraw come from the main function
char slot_handle_mousedoubleclick(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers, char *changed)
{
	double this_x = pt.x, this_y = pt.y;
    t_slot *activeslot = get_activeitem_activeslot(r_ob);
    int s = r_ob->active_slot_num;
    
    if (!slot_is_writable(r_ob, s))
        return 0;

    if (activeslot && r_ob->active_slot_num > -1) {
		if (r_ob->active_slot_notationitem) {
			t_notation_item *undo_item = get_activeitem_undo_item(r_ob);

			if (notation_item_is_globally_locked(r_ob, r_ob->active_slot_notationitem)){
				if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
					close_slot_window((t_notation_obj *)r_ob);
				return 1;
			}
			
			if (is_pt_in_slot_window(r_ob, this_x, this_y)) {
				
				if (!is_pt_in_inner_slot_subwindow(r_ob, pt)) {
					if (modifiers == eCommandKey + eLeftButton) {
						// erase note slot
						create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
						
						notation_item_clear_slot(r_ob, r_ob->active_slot_notationitem, s);
						
						if ((r_ob->link_lyrics_to_slot > 0 && r_ob->link_lyrics_to_slot - 1 == s) ||
                            (r_ob->link_dynamics_to_slot > 0 && r_ob->link_dynamics_to_slot - 1 == s)) {
                            t_chord *ch = notation_item_get_parent_chord(r_ob, r_ob->active_slot_notationitem);
                            if (ch) {
                                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                                    recompute_all_for_measure(r_ob, ch->parent, false);
                                else
                                    ch->need_recompute_parameters = true;
                            }
						}
						
						r_ob->changed_while_dragging = true;
						*changed = 1;
						return 1;
					} else if (modifiers == eLeftButton) {
						// edit note slot content in external text editor
						
						
						unlock_general_mutex(r_ob);	
						if (!r_ob->m_editor)
							r_ob->m_editor = (t_object *) object_new(CLASS_NOBOX, _sym_jed, (t_object *)r_ob, 0);
						else
							object_attr_setchar(r_ob->m_editor, _sym_visible, 1);

						t_llll *ll = notation_item_get_single_slot_values_as_llll(r_ob, r_ob->active_slot_notationitem, k_CONSIDER_FOR_SLOT_LLLL_EDITOR, r_ob->active_slot_num, false);
						char *buf = NULL;
						llll_behead(ll);
                        
                        long maxdepth = -1;
                        if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_DYNAMICS)
                            maxdepth = 2;
                        
                        llll_to_text_buf_pretty(ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, 0, "\t", maxdepth, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
//						llll_to_text_buf(ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, 0, NULL);
						void *rv = object_method(r_ob->m_editor, _sym_settext, buf, _sym_utf_8);  // non-0 if the text was too long
                        if (rv) {
                            t_object *ed = r_ob->m_editor;
                            r_ob->m_editor = NULL;
                            object_free(ed);
                        } else {
                            char titlename[512];
                            snprintf_zero(titlename, 450, "Editor for %s", r_ob->slotinfo[s].slot_name->s_name);
                            object_attr_setsym(r_ob->m_editor, _sym_title, gensym(titlename));
                        }
                        
                        r_ob->changed_while_dragging = true;
                        *changed = true;
                        llll_free(ll);
						bach_freeptr(buf);
						lock_general_mutex(r_ob);
						return 1;
					}
				}
				
				
				
                switch (r_ob->slotinfo[s].slot_type) {
                    case k_SLOT_TYPE_FUNCTION:
                    {
                        if (r_ob->j_last_mousedown_obj_type == k_SLOT_FUNCTION_POINT && r_ob->j_last_mousedown_ptr){
                            t_slotitem *item = (t_slotitem *)r_ob->j_last_mousedown_ptr;
                            t_pts *pts = (t_pts *) (item->item);
                            if (pts && item && r_ob->j_last_mousedown_obj_type == k_SLOT_FUNCTION_POINT) {
                                if ((modifiers == eLeftButton + eShiftKey && item->prev) || (modifiers == eLeftButton && item->prev && !item->next)) {
                                    // assign to the point the y value of the previous one
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    pts->y = ((t_pts *)item->prev->item)->y;
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                } else if ((modifiers & eLeftButton && modifiers & eControlKey && item->next) || (modifiers == eLeftButton && item->next && !item->prev)) {
                                    // assign to the point the y value of the next one
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    pts->y = ((t_pts *)item->next->item)->y;
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                } else if (modifiers == eLeftButton && r_ob->active_slot_num >= 0 && r_ob->active_slot_num < CONST_MAX_SLOTS && item->next && item->prev) {
                                    // assign to the point the linear interpolation of the y of the following and previous point, with respect to the slope
                                    t_pt pt_next, pt_prev, pt_interp;
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_pts *)item->prev->item)->x, ((t_pts *)item->prev->item)->y, r_ob->active_slot_num, r_ob->slot_window_active, &pt_prev);
                                    function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_pts *)item->next->item)->x, ((t_pts *)item->next->item)->y, r_ob->active_slot_num, r_ob->slot_window_active, &pt_next);
                                    pt_interp.x = (pt_next.x + pt_prev.x)/2.;
                                    pt_interp.y = (pt_next.y + pt_prev.y)/2.;
                                    pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt_interp, r_ob->active_slot_num, r_ob->slot_window_active, &pts->x, &pts->y);
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                }
                            }
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_3DFUNCTION:
                    {
                        if (r_ob->j_last_mousedown_obj_type == k_SLOT_FUNCTION_POINT && r_ob->j_last_mousedown_ptr){
                            t_slotitem *item = (t_slotitem *)r_ob->j_last_mousedown_ptr;
                            t_pts3d *pts = (t_pts3d *) (item->item);
                            if (pts && item && r_ob->j_last_mousedown_obj_type == k_SLOT_3DFUNCTION_POINT) {
                                if ((modifiers == eLeftButton + eShiftKey && item->prev) || (modifiers == eLeftButton && item->prev && !item->next)) {
                                    // assign to the point the y and value of the previous one
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    pts->y = ((t_pts3d *)item->prev->item)->y;
                                    pts->z = ((t_pts3d *)item->prev->item)->z;
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                } else if ((modifiers & eLeftButton && modifiers & eControlKey && item->next) || (modifiers == eLeftButton && item->next && !item->prev)) {
                                    // assign to the point the y value of the next one
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    pts->y = ((t_pts3d *)item->next->item)->y;
                                    pts->z = ((t_pts3d *)item->next->item)->z;
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                } else if (modifiers == eLeftButton && r_ob->active_slot_num >= 0 && r_ob->active_slot_num < CONST_MAX_SLOTS && item->next && item->prev) {
                                    // assign to the point the linear interpolation of the y of the following and previous point, with respect to the slope
                                    //								t_pt pt_next, pt_prev, pt_interp;
                                    //								t_rect activeslotwin = build_rect(r_ob->slot_window_active_x1, r_ob->slot_window_active_y1, r_ob->slot_window_active_x2 - r_ob->slot_window_active_x1, r_ob->slot_window_active_y2 - r_ob->slot_window_active_y1);
                                    
                                    create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                                    
                                    //								TO DO, make it better by taking all slopes correctly into account, as we did for the simple FUNCTION case?
                                    /*
                                     function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_pts *)item->prev->item)->x, ((t_pts *)item->prev->item)->y, r_ob->active_slot_num, activeslotwin, &pt_prev);
                                     function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_pts *)item->next->item)->x, ((t_pts *)item->next->item)->y, r_ob->active_slot_num, activeslotwin, &pt_next);
                                     pt_interp.x = (pt_next.x + pt_prev.x)/2.;
                                     pt_interp.y = (pt_next.y + pt_prev.y)/2.;
                                     pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt_interp, r_ob->active_slot_num, activeslotwin, &pts->x, &pts->y);
                                     */
                                    
                                    pts->y = 0.5 * (((t_pts3d *)item->next->item)->y + ((t_pts3d *)item->prev->item)->y);
                                    pts->z = 0.5 * (((t_pts3d *)item->next->item)->z + ((t_pts3d *)item->prev->item)->z);
                                    
                                    r_ob->changed_while_dragging = true;
                                    *changed = true;
                                }
                            }
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_TEXT:
                    {
                        char titlename[512];
                        long textlength;
                        char *text;
                        if (!get_activeitem_slot_firstitem(r_ob, s) ||
                            !get_activeitem_slot_firstitem(r_ob, s)->item) { // there's no data yet. we just set a default value
                            build_default_data_for_text_slot(r_ob, r_ob->active_slot_notationitem, s);
                        }
                        
                        if (!(modifiers & eShiftKey)) {
                            t_jrgba slot_text_textcolor = CONST_SLOT_TEXT_TEXTCOLOR;
                            start_editing_textslot(r_ob, patcherview, r_ob->active_slot_notationitem, r_ob->active_slot_num, slot_text_textcolor);
                        } else {
                            // let's edit the text
                            unlock_general_mutex(r_ob);
                            if (!r_ob->m_editor)
                                r_ob->m_editor = (t_object *) object_new(CLASS_NOBOX, _sym_jed, (t_object *)r_ob, 0);
                            else
                                object_attr_setchar(r_ob->m_editor, _sym_visible, 1);
                            textlength = get_activeitem_slot_length(r_ob, s);
                            text = (char *) bach_newptr(textlength + 4);
                            strncpy(text, (const char *) get_activeitem_slot_firstitem(r_ob, s)->item, textlength);
                            text[textlength] = 0;
                            
                            void *rv = object_method(r_ob->m_editor, _sym_settext, text, _sym_utf_8);  // non-0 if the text was too long
                            if (rv) {
                                t_object *ed = r_ob->m_editor;
                                r_ob->m_editor = NULL;
                                object_free(ed);
                            } else {
                                snprintf_zero(titlename, 450, "Editor for %s", r_ob->slotinfo[s].slot_name->s_name);
                                object_attr_setsym(r_ob->m_editor, _sym_title, gensym(titlename));
                            }

                            r_ob->changed_while_dragging = true;
                            *changed = true;
                            bach_freeptr(text);
                            lock_general_mutex(r_ob);
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_LLLL:
                    {
                        char titlename[512];
                        long textlength;
                        t_llll *this_llll;
                        char *text = NULL;
                        if (!get_activeitem_slot_firstitem(r_ob, s)) { // there's no data yet. we just set a default value
                            build_default_data_for_llll_slot(r_ob, r_ob->active_slot_notationitem, s);
                        }
                        
                        if (!(modifiers & eShiftKey)) {
                            t_jrgba slot_text_textcolor = CONST_SLOT_TEXT_TEXTCOLOR;
                            start_editing_textslot(r_ob, patcherview, r_ob->active_slot_notationitem, r_ob->active_slot_num, slot_text_textcolor);
                        } else {
                            // let's edit the text
                            unlock_general_mutex(r_ob);
                            if (!r_ob->m_editor)
                                r_ob->m_editor = (t_object *) object_new(CLASS_NOBOX, _sym_jed, (t_object *)r_ob, 0);
                            else
                                object_attr_setchar(r_ob->m_editor, _sym_visible, 1);
                            
                            this_llll = (t_llll *) get_activeitem_slot_firstitem(r_ob, s)->item;
                            if (this_llll) {
                                textlength = llll_to_text_buf(this_llll, &text, 0, BACH_DEFAULT_MAXDECIMALS, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
                                
                                void *rv = object_method(r_ob->m_editor, _sym_settext, text, _sym_utf_8);  // non-0 if the text was too long
                                if (rv) {
                                    t_object *ed = r_ob->m_editor;
                                    r_ob->m_editor = NULL;
                                    object_free(ed);
                                } else {
                                    snprintf_zero(titlename, 512, "llll %s", r_ob->slotinfo[s].slot_name->s_name);
                                    object_attr_setsym(r_ob->m_editor, _sym_title, gensym(titlename));
                                }

                                r_ob->changed_while_dragging = true;
                                *changed = true;
                                llll_free(this_llll);
                                bach_freeptr(text);
                            }
                            lock_general_mutex(r_ob);	
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_DYNAMICS:
                    {
                        char titlename[512];
                        if (!get_activeitem_slot_firstitem(r_ob, s) ||
                            !get_activeitem_slot_firstitem(r_ob, s)->item) { // there's no data yet. we just set a default value
                            build_default_data_for_dynamics_slot(r_ob, r_ob->active_slot_notationitem, s);
                        }
                        
                        if (!(modifiers & eShiftKey)) {
                            t_jrgba slot_text_textcolor = CONST_SLOT_TEXT_TEXTCOLOR;
                            start_editing_textslot(r_ob, patcherview, r_ob->active_slot_notationitem, r_ob->active_slot_num, slot_text_textcolor);
                        } else {
                            // let's edit the text
                            char text[4096];
                            unlock_general_mutex(r_ob);
                            t_dynamics *dyn = (t_dynamics *) get_activeitem_slot_firstitem(r_ob, s)->item;
                            if (!r_ob->m_editor)
                                r_ob->m_editor = (t_object *) object_new(CLASS_NOBOX, _sym_jed, (t_object *)r_ob, 0);
                            else
                                object_attr_setchar(r_ob->m_editor, _sym_visible, 1);

                            snprintf_zero(text, 4096, "%s", dyn->text_deparsed);

                            void *rv = object_method(r_ob->m_editor, _sym_settext, text, _sym_utf_8);  // non-0 if the text was too long
                            if (rv) {
                                t_object *ed = r_ob->m_editor;
                                r_ob->m_editor = NULL;
                                object_free(ed);
                            } else {
                                snprintf_zero(titlename, 450, "Editor for %s", r_ob->slotinfo[s].slot_name->s_name);
                                object_attr_setsym(r_ob->m_editor, _sym_title, gensym(titlename));
                            }
                            
                            r_ob->changed_while_dragging = true;
                            *changed = true;
                            lock_general_mutex(r_ob);
                        }
                    }
                        break;

                        
                    case k_SLOT_TYPE_DYNFILTER:
                    {
                        double this_t = notationobj_rescale_with_slope(r_ob, pt.x, r_ob->slot_window_active_x1, r_ob->slot_window_active_x2, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                        t_slotitem *temp = get_activeitem_slot_firstitem(r_ob, s);
                        t_slotitem *newitem = (t_slotitem *)bach_newptr(sizeof (t_slotitem));
                        t_biquad *interp = (t_biquad *)bach_newptr(sizeof (t_biquad));
                        newitem->parent = activeslot;
                        newitem->item = interp;
                        
                        create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                        
                        if (!temp) {
                            initialize_biquad(interp);
                            interp->t = this_t;
                            slotitem_append(newitem);
                        } else {
                            while (temp) {
                                if (((t_biquad *)temp->item)->t > this_t)
                                    break;
                                temp = temp->next;
                            }
                            
                            if (!temp) {
                                t_slotitem *lastitem = slot_get_last_item(activeslot);
                                if (lastitem) {
                                    *interp = *((t_biquad *)lastitem->item);
                                    interp->t = this_t;
                                    slotitem_append(newitem);
                                }
                            } else if (temp && !temp->prev) {
                                *interp = *((t_biquad *)get_activeitem_slot_firstitem(r_ob, s)->item);
                                interp->t = this_t;
                                slotitem_prepend(newitem);
                            } else { 
                                *interp = interpolate_biquad(r_ob, *((t_biquad *)temp->prev->item), *((t_biquad *)temp->item), this_t, r_ob->dynfilter_interp_mode);
                                interp->t = this_t;
                                slotitem_insert(newitem, temp->prev, temp);
                            }
                        }
                        r_ob->changed_while_dragging = true;
                        *changed = true;
                    }
                        break;
                        
                    case k_SLOT_TYPE_COLOR:
                    {
                        
                        if (!get_activeitem_slot_firstitem(r_ob, s)) {
                            t_slotitem *thisitem = build_slotitem(r_ob, activeslot);
                            
                            create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
                            
                            t_jrgba *col = (t_jrgba *)bach_newptr(sizeof(t_jrgba));
                            r_ob->slot_top_right_color = *col = build_jrgba(1, 0, 0, 1);
                            thisitem->item = col;
                            slotitem_append(thisitem);
                            r_ob->changed_while_dragging = true;
                            *changed = true;
                        }
                    }
                        break;
                        
                    case k_SLOT_TYPE_FLOAT:
                    case k_SLOT_TYPE_INT:
                    {
                        double bar_y_top = r_ob->slot_window_active_y1 + CONST_SLOT_INT_FLOAT_BAR_Y_POS * r_ob->slot_window_active.height;
                        double bar_y_height = CONST_SLOT_INT_FLOAT_BAR_Y_HEIGHT * r_ob->slot_window_active.height;
                        if (pt.y > bar_y_top + bar_y_height) {
                            t_jrgba slot_text_textcolor = CONST_SLOT_TEXT_TEXTCOLOR;
                            start_editing_numberslot(r_ob, patcherview, r_ob->active_slot_notationitem, r_ob->active_slot_num, slot_text_textcolor);
                        }
                    }
                        
                }
                
			} else {
				// clicked outside the slot window
				char changed = 0;
				if (r_ob->is_editing_type == k_TEXT_IN_SLOT || r_ob->is_editing_type == k_LLLL_IN_SLOT || r_ob->is_editing_type == k_DYNAMICS_IN_SLOT) {
					end_editing_textfield(r_ob);
					changed = 1;
				}
				if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
					close_slot_window(r_ob);
				return changed;
			}
		} else { // something has gone wrong with slots, just return to normal view. 
			if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
				close_slot_window(r_ob);
		}
		return 1; // stop! we don't care about what else could have been clicked!
	}
	return 0;
}


void slot_handle_mousedrag_function_point(t_notation_obj *r_ob, t_slotitem *activeslotitem, t_pt pt, long modifiers, 
											char *changed, char *redraw, t_notation_item *undo_item, char changing_segment) 
{
	long s = r_ob->active_slot_num;
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom/100.);
	double delta_y_pixel = pt.y - r_ob->floatdragging_y;
    double ypt = CLAMP(pt.y, r_ob->slot_window_active_nozoom.y, r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height);
    double xpt;

    if (slot_can_extend_beyond_note_tail(r_ob, r_ob->active_slot_num) && r_ob->slotinfo[r_ob->active_slot_num].slot_uwidth == -2.) // auto
        xpt = MAX(pt.x, r_ob->slot_window_active_nozoom.x);
    else
        xpt = CLAMP(pt.x, r_ob->slot_window_active_nozoom.x, r_ob->slot_window_active_nozoom.x + r_ob->slot_window_active_nozoom.width);
	
	if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
		create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
	
	if (!changing_segment && modifiers & eControlKey && modifiers & eShiftKey) { // shift all following points horizontally
		double old_x_value = ((t_pts *) activeslotitem->item)->x;
        double new_x_value;
        
        switch (r_ob->slotinfo[s].slot_temporalmode) {
            case k_SLOT_TEMPORALMODE_MILLISECONDS:
                new_x_value = xposition_to_ms(r_ob, xpt, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem);
                break;

            case k_SLOT_TEMPORALMODE_RELATIVE:
            {
                double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                new_x_value = (xposition_to_ms(r_ob, xpt, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem))/(duration == 0 ? 1 : duration);
            }
                break;

            default:
                new_x_value = notationobj_rescale_with_slope(r_ob, xpt, r_ob->slot_window_active.x, r_ob->slot_window_active.x + r_ob->slot_window_active.width, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                break;
        }
        
		t_slotitem *tempitem;
		if (slot_can_extend_beyond_note_tail(r_ob, s) || new_x_value > r_ob->slotinfo[s].slot_domain[0]) {
            t_slotitem *lastitem = slot_get_last_item(get_activeitem_activeslot(r_ob));
			for (tempitem = lastitem; tempitem; tempitem = tempitem->prev) {
				change_slot_pts_value(r_ob, r_ob->active_slot_notationitem, s, tempitem, new_x_value - old_x_value, 0, 0, true, 0);
				if (tempitem == activeslotitem)
					break;
			}
		}
	} else if (modifiers & eControlKey && activeslotitem->prev) { // change slope
		// checking if previous value is less or more than this one
		double prev_y = ((t_pts *) activeslotitem->prev->item)->y;
		double this_y = ((t_pts *) activeslotitem->item)->y;
		change_slot_pts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, 0., 0.,
								(prev_y >= this_y ? -1 : 1) * delta_y_pixel / (CONST_SLOPE_DRAG_UCHANGE * zoom_y), 1, 0);
	} else {
		// we drag it!
		t_pts *thisbpt = ((t_pts *) activeslotitem->item);
		double curr_slope = thisbpt->slope; // slope does not change
		double slot_max = r_ob->slotinfo[s].slot_range[1]; 
		double slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
        double new_x_value;
		
        switch (r_ob->slotinfo[s].slot_temporalmode) {
            case k_SLOT_TEMPORALMODE_MILLISECONDS:
                new_x_value = changing_segment ? thisbpt->x : xposition_to_ms(r_ob, xpt, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem);
                break;

            case k_SLOT_TEMPORALMODE_RELATIVE:
            {
                double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                new_x_value = changing_segment ? thisbpt->x : (xposition_to_ms(r_ob, xpt, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem))/(duration == 0 ? 1 : duration);
            }
                break;

            default:
                new_x_value = changing_segment ? thisbpt->x : notationobj_rescale_with_slope(r_ob, xpt, r_ob->slot_window_active.x, r_ob->slot_window_active.x + r_ob->slot_window_active.width, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                break;
        }
        
        double new_y_value = notationobj_rescale_with_slope(r_ob, r_ob->slot_window_y2 - CONST_SLOT_FUNCTION_UY_INSET_BOTTOM * zoom_y -  ypt, 0, r_ob->slot_window_active.height, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
		if (r_ob->slotinfo[s].slot_ysnap && r_ob->slotinfo[s].slot_ysnap->l_head && (modifiers & eAltKey) && (modifiers & eShiftKey)) // checking if there's a y snap
			ysnap_double(&new_y_value, r_ob->slotinfo[s].slot_ysnap, 0);
		change_slot_pts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, new_x_value, new_y_value, curr_slope, 0, modifiers);
	}
	r_ob->floatdragging_x = pt.x;	
	r_ob->floatdragging_y = pt.y;
	r_ob->j_mouse_hasbeendragged = true;
	*redraw = 1;
	*changed = 1;
}





void slot_handle_mousedrag_function_selection(t_notation_obj *r_ob, t_slotitem *activeslotitem, t_pt pt, long modifiers, char *changed, char *redraw, t_notation_item *undo_item) {
	
	double delta_y_pixel = r_ob->floatdragging_y - pt.y;
	double delta_x_pixel = r_ob->floatdragging_x - pt.x;
	
	t_llllelem *elem;

	// first of all we see if we actually have to change the x values, and if there are no barriers preventing it
	for (elem = r_ob->selected_slot_items->l_head; elem; elem = elem->l_next) {
		t_slotitem *item = (t_slotitem *)hatom_getobj(&elem->l_hatom);
		t_pts *function_point = (t_pts *)item->item;
		t_pt point_coordinates;
		function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, function_point->x, function_point->y, r_ob->active_slot_num, r_ob->slot_window_active, &point_coordinates);
		if (delta_x_pixel > 0) {
			t_slotitem *prev_item = item->prev;
			t_pts *prev_function_point = prev_item ? (t_pts *)prev_item->item : NULL;
			t_pt prev_point_coordinates;
            if (!prev_function_point || !is_obj_in_llll_first_level(r_ob->selected_slot_items, prev_item)) {
                if (prev_function_point)
                    function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, prev_function_point->x, prev_function_point->y, r_ob->active_slot_num, r_ob->slot_window_active, &prev_point_coordinates);
                else
                    prev_point_coordinates.x = r_ob->slot_window_active.x;
                if (point_coordinates.x - delta_x_pixel < prev_point_coordinates.x)
                    delta_x_pixel = -MIN(prev_point_coordinates.x - point_coordinates.x, 0);
            }
		} else if (delta_x_pixel < 0) {
            t_slotitem *next_item = item->next;
            t_pts *next_function_point = next_item ? (t_pts *)next_item->item : NULL;
            t_pt next_point_coordinates;
            if (!next_function_point || !is_obj_in_llll_first_level(r_ob->selected_slot_items, next_item)) {
                if (next_function_point)
                    function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, next_function_point->x, next_function_point->y, r_ob->active_slot_num, r_ob->slot_window_active, &next_point_coordinates);
                else
                    next_point_coordinates.x = r_ob->slot_window_active.x + r_ob->slot_window_active.width;
                if (point_coordinates.x - delta_x_pixel > next_point_coordinates.x)
                    delta_x_pixel = -MAX(next_point_coordinates.x - point_coordinates.x, 0);
            }
		}
	}
	
	for (elem = r_ob->selected_slot_items->l_head; elem; elem = elem->l_next) {
		t_slotitem *item = (t_slotitem *)hatom_getobj(&elem->l_hatom);
		t_pts *function_point = (t_pts *)item->item;
		t_pt point_coordinates;
		function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, function_point->x, function_point->y, r_ob->active_slot_num, r_ob->slot_window_active, &point_coordinates);
		point_coordinates.y -= delta_y_pixel;
		point_coordinates.x -= delta_x_pixel;
		slot_handle_mousedrag_function_point(r_ob, item, point_coordinates, modifiers, changed, redraw, undo_item, false);
	}
	r_ob->floatdragging_x = pt.x;	
	r_ob->floatdragging_y = pt.y;
}

// returns 1 if something has been found (and thus the main function must return), 0 otherwise
// changed and redraw come from the main function
char slot_handle_mousedrag(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers, char *changed, char *redraw){
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);

    if (!slot_is_writable(r_ob, r_ob->active_slot_num))
        return 0;

    if (r_ob->active_slot_num > -1) {
		if (r_ob->active_slot_notationitem) {
			t_notation_item *undo_item = get_activeitem_undo_item(r_ob);
			int s;
			if (notation_item_is_globally_locked(r_ob, r_ob->active_slot_notationitem)) {
				if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
					close_slot_window(r_ob);
				return 1; // note or chord are locked
			}
			s = r_ob->active_slot_num;
			switch (r_ob->slotinfo[s].slot_type) {
					
					
				case k_SLOT_TYPE_FUNCTION:
				{
					// let's see if a point is selected
					if (r_ob->j_mousedown_obj_type == k_SLOT_FUNCTION_POINT) {
						if (r_ob->slot_pen_mode) {
							if (is_pt_in_inner_slot_subwindow(r_ob, pt)) {
								// continuously add points
								double x_val, y_val;
								t_slotitem *newitem;
								pt_to_function_xy_values(r_ob, r_ob->active_slot_notationitem, pt, s, r_ob->slot_window_active, &x_val, &y_val);
								create_simple_notation_item_undo_tick(r_ob, undo_item, k_UNDO_MODIFICATION_CHANGE);
								newitem = insert_new_slot_function_point(r_ob, s, x_val, y_val, 0., true, r_ob->hovered_slotitem);
								r_ob->hovered_slotitem = newitem;
								set_mousedown(r_ob, newitem, k_SLOT_FUNCTION_POINT);
								*redraw = 1;
								*changed = 1;
							}
						} else
							slot_handle_mousedrag_function_point(r_ob, (t_slotitem *) r_ob->j_mousedown_ptr, pt, modifiers, changed, redraw, undo_item, false);
						
					} else if (r_ob->j_mousedown_obj_type == k_SLOT_FUNCTION_SEGMENT) {
						if (modifiers & eControlKey) { // change slope
							slot_handle_mousedrag_function_point(r_ob, (t_slotitem *) r_ob->j_mousedown_ptr, pt, modifiers, changed, redraw, undo_item, false);
						} else {
							t_slotitem *activeitem = (t_slotitem *) r_ob->j_mousedown_ptr;
							if (activeitem && activeitem->prev) {
								t_pts *start = (t_pts *)activeitem->prev->item;
								t_pts *end = (t_pts *)activeitem->item;
								t_pt start_pt, end_pt;
								function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, start->x, start->y, s, r_ob->slot_window_active, &start_pt);
								function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, end->x, end->y, s, r_ob->slot_window_active, &end_pt);
								start_pt.y -= r_ob->floatdragging_y - pt.y;
								end_pt.y -= r_ob->floatdragging_y - pt.y;
								slot_handle_mousedrag_function_point(r_ob, activeitem->prev, start_pt, modifiers, changed, redraw, undo_item, true);
								slot_handle_mousedrag_function_point(r_ob, activeitem, end_pt, modifiers, changed, redraw, undo_item, true);
								r_ob->floatdragging_x = pt.x;	
								r_ob->floatdragging_y = pt.y;
							}
						}
					} else if (r_ob->j_mousedown_obj_type == k_SLOT_SELECTION) {
						slot_handle_mousedrag_function_selection(r_ob, (t_slotitem *) r_ob->j_mousedown_ptr, pt, modifiers, changed, redraw, undo_item);
					} else if (r_ob->j_mousedown_obj_type == k_SLOT_REGION) {
						*redraw = 1;
						*changed = 0;
					}
				} 
					break;
					
					
				case k_SLOT_TYPE_3DFUNCTION:
				{
					// let's see if a point is selected
					if (r_ob->j_mousedown_obj_type == k_SLOT_3DFUNCTION_POINT) {
						double delta_y_pixel = pt.y - r_ob->floatdragging_y;
						double xpt = pt.x, ypt = pt.y;
						t_slotitem *activeslotitem;
						xpt = CLAMP(ypt, r_ob->slot_window_active_nozoom.x, r_ob->slot_window_active_nozoom.x + r_ob->slot_window_active_nozoom.width); 
						ypt = CLAMP(ypt, r_ob->slot_window_active_nozoom.y, r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height); 
						activeslotitem = (t_slotitem *) r_ob->j_mousedown_ptr;
						
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						if (modifiers & eControlKey && modifiers & eShiftKey && !(modifiers & eAltKey)) { // shift all following points horizontally
                            double delta_x_value;
                            
                            switch (r_ob->slotinfo[s].slot_temporalmode) {
                                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (xposition_to_ms(r_ob, pt.x, 0) - xposition_to_ms(r_ob, r_ob->floatdragging_x, 0));
                                    break;
                                    
                                case k_SLOT_TEMPORALMODE_RELATIVE:
                                {
                                    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (xposition_to_ms(r_ob, pt.x, 0) - xposition_to_ms(r_ob, r_ob->floatdragging_x, 0))/(duration = 0 ? 1 : duration);
                                }


                                default:
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (pt.x - r_ob->floatdragging_x) * (r_ob->slotinfo[s].slot_domain[1] - r_ob->slotinfo[s].slot_domain[0])/r_ob->slot_window_active.width;
                                    break;
                            }
                            
							t_slotitem *tempitem;
							if (slot_can_extend_beyond_note_tail(r_ob, s) || ((t_pts3d *) activeslotitem->item)->x + delta_x_value > r_ob->slotinfo[s].slot_domain[0]) {
                                t_slotitem *lastitem = slot_get_last_item(get_activeitem_activeslot(r_ob));
								for (tempitem = lastitem; tempitem; tempitem = tempitem->prev) {
									change_slot_3dpts_value(r_ob, r_ob->active_slot_notationitem, s, tempitem, delta_x_value, 0, 0, 0, true, 0);
									if (tempitem == activeslotitem)
										break;
								}
							}
						} else if (modifiers & eControlKey && !(modifiers & eAltKey)) { // change slope
							change_slot_3dpts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, 0., 0., 0., -delta_y_pixel / (CONST_SLOPE_DRAG_UCHANGE * zoom_y), 1, 0);
						} else {
							// we drag it!
							t_pts3d *thisbpt = ((t_pts3d *) activeslotitem->item);
                            double delta_x_value;
                            
                            switch (r_ob->slotinfo[s].slot_temporalmode) {
                                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (xposition_to_ms(r_ob, pt.x, 0) - xposition_to_ms(r_ob, r_ob->floatdragging_x, 0));
                                    break;
                                    
                                case k_SLOT_TEMPORALMODE_RELATIVE:
                                {
                                    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (xposition_to_ms(r_ob, pt.x, 0) - xposition_to_ms(r_ob, r_ob->floatdragging_x, 0)) / (duration == 0 ? 1 : duration);
                                }
                                    break;
                                    
                                default:
                                    delta_x_value = (modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (pt.x - r_ob->floatdragging_x) * (r_ob->slotinfo[s].slot_domain[1] - r_ob->slotinfo[s].slot_domain[0])/r_ob->slot_window_active.width;
                                    break;
                            }
                            
							double delta_y_value = -(modifiers & eControlKey && modifiers & eAltKey ? 0 : 1) * (pt.y - r_ob->floatdragging_y) * (r_ob->slotinfo[s].slot_range[1] - r_ob->slotinfo[s].slot_range[0])/r_ob->slot_window_active.width;
							double delta_z_value = (modifiers & eControlKey && modifiers & eAltKey ? 1 : 0) * (pt.y - r_ob->floatdragging_y) * (r_ob->slotinfo[s].slot_zrange[1] - r_ob->slotinfo[s].slot_zrange[0])/(CONST_SLOT_3DFUNCTION_ZDIM_USIZE * zoom_y);
							change_slot_3dpts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, delta_x_value, delta_y_value, delta_z_value, 0, true, modifiers);
							if (r_ob->slotinfo[s].slot_ysnap && r_ob->slotinfo[s].slot_ysnap->l_head && modifiers & eAltKey && modifiers & eShiftKey && !(modifiers & eControlKey)) // checking if there's a y snap
								ysnap_double(&(thisbpt->y), r_ob->slotinfo[s].slot_ysnap, 0);
							if (r_ob->slotinfo[s].slot_zsnap && r_ob->slotinfo[s].slot_zsnap->l_head && modifiers & eAltKey && modifiers & eShiftKey && modifiers & eControlKey) // checking if there's a z snap
								ysnap_double(&(thisbpt->z), r_ob->slotinfo[s].slot_zsnap, 0);
						}
						r_ob->floatdragging_x = pt.x;	
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
						*redraw = 1;
						*changed = 1;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_SPAT:
				{
					// let's see if a point is selected
					if (r_ob->j_mousedown_obj_type == k_SLOT_SPAT_POINT) {
						double delta_y_pixel = pt.y - r_ob->floatdragging_y;
						double xpt, ypt = pt.y;
						t_slotitem *activeslotitem;
						xpt = pt.x;
						xpt = CLAMP(ypt, r_ob->slot_window_active_nozoom.x, r_ob->slot_window_active_nozoom.x + r_ob->slot_window_active_nozoom.width); 
						ypt = CLAMP(ypt, r_ob->slot_window_active_nozoom.y, r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height); 
						activeslotitem = (t_slotitem *) r_ob->j_mousedown_ptr;
						
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						if (modifiers & eControlKey && modifiers & eShiftKey) { // shift all following points horizontally
							double old_t_value = ((t_spatpt *) activeslotitem->item)->t;
                            double new_t_value;
                            
                            switch (r_ob->slotinfo[s].slot_temporalmode) {
                                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                                    new_t_value = xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem);
                                    break;

                                case k_SLOT_TEMPORALMODE_RELATIVE:
                                {
                                    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                                    new_t_value = (xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem))/(duration == 0 ? 1 : duration);
                                }
                                    break;

                                default:
                                    new_t_value = notationobj_rescale_with_slope(r_ob, pt.x, r_ob->slot_window_active.x, r_ob->slot_window_active.x + r_ob->slot_window_active.width, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                                    break;
                            }
                            
							t_slotitem *tempitem;
							if (slot_can_extend_beyond_note_tail(r_ob, s) || new_t_value > r_ob->slotinfo[s].slot_domain[0]) {
                                t_slotitem *lastitem = slot_get_last_item(get_activeitem_activeslot(r_ob));
								for (tempitem = lastitem; tempitem; tempitem = tempitem->prev) {
									change_slot_spatpts_value(r_ob, r_ob->active_slot_notationitem, s, tempitem, new_t_value - old_t_value, 0, 0, true, 0);
									if (tempitem == activeslotitem)
										break;
								}
							}
						} else if (modifiers & eControlKey) { // change angle
							change_slot_spatpts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, 0., 0., -delta_y_pixel / (CONST_ANGLE_DRAG_UCHANGE * zoom_y), 1, 0);
						} else {
							// we drag it!
							t_spatpt *thisspatpt = ((t_spatpt *) activeslotitem->item);
							double curr_angle = thisspatpt->angle; // slope does not change
							double slot_max = r_ob->slotinfo[s].slot_range[1]; double slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
							//double new_t_value = notationobj_rescale_with_slope(r_ob, pt.x, slot_window_active_x1, slot_window_active_x2, 0., 1., 0., false);
                            double new_t_value;
                            
                            switch (r_ob->slotinfo[s].slot_temporalmode) {
                                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                                    new_t_value = xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem);
                                    break;

                                case k_SLOT_TEMPORALMODE_RELATIVE:
                                {
                                    double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                                    new_t_value = (xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem))/(duration == 0 ? 1 : duration);
                                }
                                    break;

                                default:
                                    new_t_value = notationobj_rescale_with_slope(r_ob, pt.x, r_ob->slot_window_active.x, r_ob->slot_window_active.x + r_ob->slot_window_active.width, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                                    break;
                            }

							double new_r_value = notationobj_rescale_with_slope(r_ob, r_ob->slot_window_y2 - CONST_SLOT_FUNCTION_UY_INSET_BOTTOM * zoom_y -  ypt, 0, r_ob->slot_window_active.height, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
							change_slot_spatpts_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, new_t_value, new_r_value, curr_angle, 0, modifiers);
						}
						r_ob->floatdragging_x = pt.x;	
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
						*redraw = 1;
						*changed = 1;
					}
				} 
					break;
					
					
				case k_SLOT_TYPE_INT:
				case k_SLOT_TYPE_FLOAT:
				{
					// we have to handle the movement of the bar
					if (r_ob->j_mousedown_obj_type == k_SLOT_INT_FLOAT_BAR && (modifiers != eCommandKey + eAltKey)) { // the bar has been clicked!
						double xpt = pt.x;
						int s; char as_delta = false;
						double slot_min, slot_max, new_value;
						s = r_ob->active_slot_num;
																			   
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						slot_max = r_ob->slotinfo[s].slot_range[1]; slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
						
						if (modifiers == eShiftKey + eCommandKey) {
							as_delta = true;
							new_value = (xpt - r_ob->floatdragging_x) * CONST_FINER_FROM_KEYBOARD * (slot_max - slot_min)/((r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X) - (r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X));
						} else if (modifiers == eShiftKey) {
							as_delta = true;
							new_value = (xpt - r_ob->floatdragging_x) * (slot_max - slot_min)/((r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X) - (r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X));
						} else {
							xpt = CLAMP(xpt, r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X, r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X);
							new_value = notationobj_rescale_with_slope(r_ob, xpt, r_ob->slot_window_x1 + CONST_SLOT_WINDOW_INSET_X, r_ob->slot_window_x2 - CONST_SLOT_WINDOW_INSET_X, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
						}
						
						if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INT)
							change_slot_long_value(r_ob, r_ob->active_slot_notationitem, s, round(new_value), as_delta);
						else
							change_slot_float_value(r_ob, r_ob->active_slot_notationitem, s, new_value, as_delta);
						
						r_ob->floatdragging_x = pt.x;
						r_ob->j_mouse_hasbeendragged = true;
						
						*redraw = 1;
						*changed = 1;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_INTLIST:
				case k_SLOT_TYPE_FLOATLIST:
				{
					if (r_ob->j_mousedown_obj_type == k_SLOT_INT_FLOAT_BAR) { // we are inside the bar
						// new value
						double ypt = pt.y;
						int s = r_ob->active_slot_num;
						double slot_min, slot_max, new_value;
						char as_delta = false;

						// first of all: has the strip changed?
						long strip = pt_to_slot_longfloatlistbar_strip(r_ob, pt.x, pt.y);
						if (strip >= 0) {
							if (strip < get_activeitem_slot_length(r_ob, s))
								r_ob->j_mousedown_ptr = nth_slotitem(r_ob, r_ob->active_slot_notationitem, s, strip);
						}

																			   
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						slot_max = r_ob->slotinfo[s].slot_range[1]; slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
						
						if (modifiers == eShiftKey + eCommandKey) {
							as_delta = true;
							new_value = (r_ob->floatdragging_y - ypt) * CONST_FINER_FROM_KEYBOARD * (slot_max - slot_min)/r_ob->slot_window_active_nozoom.height;
						} else if (modifiers == eShiftKey) {
							as_delta = true;
							new_value = (r_ob->floatdragging_y - ypt) * (slot_max - slot_min)/r_ob->slot_window_active_nozoom.height;
						} else {
							ypt = CLAMP(ypt, r_ob->slot_window_active_nozoom.y, r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height);
							new_value = notationobj_rescale_with_slope(r_ob, ypt, r_ob->slot_window_active_nozoom.y + r_ob->slot_window_active_nozoom.height, r_ob->slot_window_active_nozoom.y, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
						}
						
						if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTLIST)
							change_slot_longlist_value(r_ob, r_ob->active_slot_notationitem, s, (t_slotitem *) r_ob->j_mousedown_ptr, round(new_value), as_delta);
						else
							change_slot_floatlist_value(r_ob, r_ob->active_slot_notationitem, s, (t_slotitem *) r_ob->j_mousedown_ptr, new_value, as_delta);
						
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
						
						*redraw = 1;
						*changed = 1;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_INTMATRIX:
				case k_SLOT_TYPE_FLOATMATRIX:
				{
					// we have to handle the movement of the bar
					if (r_ob->j_mousedown_obj_type == k_SLOT_MATRIX_CELL) { // the cell has been clicked!
						// new value
						double slot_window_table_x1 = r_ob->slot_window_table_x1; //r_ob->slot_window_active_x1 + r_ob->slotinfo[s].slot_has_enum_rows * CONST_SLOT_NUMBERMATRIX_UX_PAD * zoom_y; 
						double h_cell_size = (r_ob->slot_window_active_x2 - slot_window_table_x1) / r_ob->slotinfo[s].slot_num_cols;
						double xpt = pt.x;
						t_slotitem *activeslotitem = (t_slotitem *) r_ob->j_mousedown_ptr;
						int s; char as_delta = false;
						double slot_min, slot_max, new_value;
						s = r_ob->active_slot_num;
						slot_max = r_ob->slotinfo[s].slot_range[1]; slot_min = r_ob->slotinfo[s].slot_range[0]; // max and min values allowed for the slots
						
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						if (modifiers & eShiftKey && modifiers & eCommandKey) {
							as_delta = true;
							new_value = (xpt - r_ob->floatdragging_x) * CONST_FINER_FROM_KEYBOARD * (slot_max - slot_min)/(r_ob->slot_window_active_x2 - slot_window_table_x1);
						} else {
							xpt = CLAMP(xpt, slot_window_table_x1, r_ob->slot_window_active_x2);
							new_value = notationobj_rescale_with_slope(r_ob, xpt, slot_window_table_x1 + (r_ob->slot_clicked_col - 1) * h_cell_size, slot_window_table_x1 + r_ob->slot_clicked_col * h_cell_size, slot_min, slot_max, r_ob->slotinfo[s].slot_range_par);
						}
						
						if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_INTMATRIX)
							change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, r_ob->slot_clicked_row, r_ob->slot_clicked_col, round(new_value), as_delta);
						else
							change_slot_matrix_value(r_ob, r_ob->active_slot_notationitem, s, activeslotitem, r_ob->slot_clicked_row, r_ob->slot_clicked_col, new_value, as_delta);
						
						r_ob->floatdragging_x = pt.x;
						r_ob->j_mouse_hasbeendragged = true;
						
						*redraw = 1;
						*changed = 1;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_FILTER:
				{
					
					if (get_activeitem_slot_firstitem(r_ob, s)) {
						t_biquad *bqd = (t_biquad *) get_activeitem_slot_firstitem(r_ob, s)->item;
						double delta_x = pt.x - r_ob->floatdragging_x;
						double delta_y = pt.y - r_ob->floatdragging_y;
						
						if (modifiers & eShiftKey && modifiers & eCommandKey) {
							delta_x *= CONST_FINER_FROM_KEYBOARD;
							delta_y *= CONST_FINER_FROM_KEYBOARD;
						}
						
						if (bqd->filter_type != k_FILTER_NONE && bqd->filter_type != k_FILTER_DISPLAY) {
							
							if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
								create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
							
							if (modifiers == eControlKey){
								// change Q
								double new_Q = bqd->Q * (1 - delta_y/(CONST_FILTER_SLOT_Q_DRAG_UCHANGE * zoom_y));
								new_Q = CLAMP(new_Q, 0, r_ob->sampling_freq/2.);
								bqd->Q = new_Q;
								synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
								
								*redraw = 1;
								*changed = 1;
							} else if (modifiers == eShiftKey){
								// change gain
								double new_gain = bqd->gain_dB - delta_y/(CONST_FILTER_SLOT_GAIN_DRAG_UCHANGE  * zoom_y);
								new_gain = CLAMP(new_gain, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]);
								bqd->gain_dB = new_gain;
								synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
								
								*redraw = 1;
								*changed = 1;
							} else {
								// change cutoff frequency
								double old_freq = bqd->cutoff_freq;
								double old_freq_pixel = notationobj_rescale_with_slope_inv(r_ob, old_freq, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slot_window_active_x1, r_ob->slot_window_active_x2, r_ob->slotinfo[s].slot_domain_par);
								double new_freq = notationobj_rescale_with_slope(r_ob, old_freq_pixel + delta_x, r_ob->slot_window_active_x1, r_ob->slot_window_active_x2, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
								new_freq = CLAMP(new_freq, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1]);
								bqd->cutoff_freq = new_freq;
								synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
								
								*redraw = 1;
								*changed = 1;
							}
						}
						
						r_ob->floatdragging_x = pt.x;
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_DYNFILTER:
				{
					
					// let's see if a point is selected
					t_slotitem *item = (t_slotitem *) r_ob->j_mousedown_ptr;
					if (r_ob->j_mousedown_obj_type == k_SLOT_DYNFILTER_BIQUAD) {
						t_biquad *bqd = (t_biquad *) item->item;
						double delta_x = pt.x - r_ob->floatdragging_x;
						double delta_y = pt.y - r_ob->floatdragging_y;
						
						if (modifiers & eShiftKey && modifiers & eCommandKey) {
							delta_x *= CONST_FINER_FROM_KEYBOARD;
							delta_y *= CONST_FINER_FROM_KEYBOARD;
						}
						
						if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
							create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
						
						if (modifiers & eShiftKey && modifiers & eControlKey){
							// change gain
							double new_gain = bqd->gain_dB - delta_y/(CONST_FILTER_SLOT_GAIN_DRAG_UCHANGE  * zoom_y);
							new_gain = CLAMP(new_gain, CONST_DYNFILTER_SLOT_MIN_GAIN, CONST_DYNFILTER_SLOT_MAX_GAIN);
							bqd->gain_dB = new_gain;
							synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
							
							*redraw = 1;
							*changed = 1;
						} else if (modifiers & eControlKey){
							// change Q
							double new_Q = bqd->Q * (1 - delta_y/(CONST_FILTER_SLOT_Q_DRAG_UCHANGE * zoom_y));
							new_Q = CLAMP(new_Q, 0, r_ob->sampling_freq/2.);
							bqd->Q = new_Q;
							synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
							
							*redraw = 1;
							*changed = 1;
							
						} else {
							
							if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == 1) {
								// handle y changes
								if (bqd->filter_type != k_FILTER_NONE && bqd->filter_type != k_FILTER_DISPLAY) {
									// change cutoff frequency
									double old_freq = bqd->cutoff_freq;
									double old_freq_pixel = notationobj_rescale_with_slope_inv(r_ob, old_freq, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1], 0, r_ob->slot_window_active_y2 - r_ob->slot_window_active_y1, r_ob->slotinfo[s].slot_range_par);
									double new_freq = notationobj_rescale_with_slope(r_ob, old_freq_pixel - delta_y, 0, r_ob->slot_window_active_y2 - r_ob->slot_window_active_y1, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1], r_ob->slotinfo[s].slot_range_par);
									new_freq = CLAMP(new_freq, r_ob->slotinfo[s].slot_range[0], r_ob->slotinfo[s].slot_range[1]);
									bqd->cutoff_freq = new_freq;
									synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
									
									*redraw = 1;
									*changed = 1;
								}
							}
							if (!(modifiers & eShiftKey) || r_ob->main_dragging_direction == -1) {
								// change filter position
                                double new_pos;
                                switch (r_ob->slotinfo[s].slot_temporalmode) {
                                    case k_SLOT_TEMPORALMODE_MILLISECONDS:
                                        new_pos = xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem);
                                        break;

                                    case k_SLOT_TEMPORALMODE_RELATIVE:
                                    {
                                        double duration = notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, s, r_ob->active_slot_notationitem);
                                        new_pos = (xposition_to_ms(r_ob, pt.x, 0) - notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem))/duration;
                                    }
                                        break;

                                    default:
                                        new_pos = notationobj_rescale_with_slope(r_ob, pt.x, r_ob->slot_window_active_x1, r_ob->slot_window_active_x2, r_ob->slotinfo[s].slot_domain[0], r_ob->slotinfo[s].slot_domain[1], r_ob->slotinfo[s].slot_domain_par);
                                        break;
                                }
                                
                                bqd->t = new_pos;
                                slot_clip_domain_value(r_ob, r_ob->active_slot_notationitem, s, &bqd->t);
                                
								if (item->next && ((t_biquad *)item->next->item)->t < bqd->t)
									bqd->t = ((t_biquad *)item->next->item)->t;
								if (item->prev && ((t_biquad *)item->prev->item)->t > bqd->t)
									bqd->t = ((t_biquad *)item->prev->item)->t;
								*redraw = 1;
								*changed = 1;
							}
						}
						
						
						r_ob->floatdragging_x = pt.x;
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
					}
				}
					break;
					
					
				case k_SLOT_TYPE_COLOR:
				{
					if (get_activeitem_slot_firstitem(r_ob, s)) {
						t_jrgba *color = (t_jrgba *) get_activeitem_slot_firstitem(r_ob, s)->item;
						t_pt okpt = r_ob->j_mousedrag_point_shift_ffk;
						
						// inside the palette
						if (r_ob->j_mousedown_obj_type == k_SLOT_COLOR_PALETTE) {
							if (modifiers & eControlKey) {
								double delta_y = pt.y - r_ob->floatdragging_y;
								
								if (modifiers & eShiftKey && modifiers & eCommandKey)
									delta_y *= CONST_FINER_FROM_KEYBOARD;
								
								if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
									create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
								
								color->alpha -= delta_y/(CONST_ALPHA_DRAG_UCHANGE * zoom_y);				
								clip_double(&color->alpha, 0, 1);
								
								*redraw = 1;
								*changed = 1;
							} else {
								double xx = CLAMP((okpt.x - r_ob->slot_window_active_x1)/r_ob->slot_window_palette_width, 0, 1);
								double yy = 1 - CLAMP((okpt.y - r_ob->slot_window_active_y1)/(r_ob->slot_window_active_y2 - r_ob->slot_window_active_y1), 0, 1);
								//							double newx, newy;
								*color = xy_coordinates_to_color(xx, yy, r_ob->slot_top_right_color);
								//							get_color_xy_coordinates(*color, &newx, &newy);
								*redraw = 1;
								*changed = 1;
							}
						} else if (r_ob->j_mousedown_obj_type == k_SLOT_COLOR_SPECTRUM) {
							double xx, yy;
							
							if (!(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))
								create_simple_selected_notation_item_undo_tick(r_ob, undo_item, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
							
							get_color_xy_coordinates(*color, &xx, &yy);
							r_ob->slot_top_right_color = double_to_color(CLAMP(okpt.y, r_ob->slot_window_active_y1, r_ob->slot_window_active_y2 - CONST_EPSILON3), r_ob->slot_window_active_y1, r_ob->slot_window_active_y2, true);
							r_ob->slot_top_right_color.alpha = color->alpha;
							*color = xy_coordinates_to_color(xx, yy, r_ob->slot_top_right_color);
							*redraw = 1;
							*changed = 1;
						}
						
						r_ob->floatdragging_x = pt.x;
						r_ob->floatdragging_y = pt.y;
						r_ob->j_mouse_hasbeendragged = true;
					}
				}
					break;
				default:
					break;
			}
			
			if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
				check_slot_linkage_recomputations_for_active_notationitem(r_ob);
			
		} else { // something has gone wrong with slots, just return to normal view. 
			if (r_ob->obj_type != k_NOTATION_OBJECT_SLOT)
				close_slot_window(r_ob);
		}
		return 1;
	}
	return 0;
}





t_slotitem *pt_to_dynfilter_biquad(t_notation_obj *r_ob, t_pt pt, long slot_number)
{
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
	double marker_semiwidth = 1.5 * zoom_y + CONST_SLOT_DYNFILTER_BIQUAD_ADD_WIDTH_FOR_SELECTION;
	t_slotitem *temp;
	if (pt.y >= r_ob->slot_window_active_y1 && pt.y <= r_ob->slot_window_active_y2) {
		for (temp = get_activeitem_slot_firstitem(r_ob, slot_number); temp; temp = temp->next) {
            double thisx;
            switch (r_ob->slotinfo[slot_number].slot_temporalmode) {
                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                    thisx = ms_to_xposition(r_ob, ((t_biquad *)temp->item)->t + notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem), NULL);
                    break;

                case k_SLOT_TEMPORALMODE_RELATIVE:
                    thisx = ms_to_xposition(r_ob, ((t_biquad *)temp->item)->t * notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_number, r_ob->active_slot_notationitem) + notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem), NULL);
                    break;

                default:
                    thisx = notationobj_rescale_with_slope_inv(r_ob, ((t_biquad *)temp->item)->t, r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1], r_ob->slot_window_active_x1, r_ob->slot_window_active_x2, r_ob->slotinfo[slot_number].slot_domain_par);
                    break;
            }

            if (fabs(thisx - pt.x) < marker_semiwidth)
				return temp;
		}
	}
	return NULL;
}

t_slotitem *pt_to_function_slot_point(t_notation_obj *r_ob, t_pt pt, long slot_number, char also_find_segments, long *found_item)
{
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
	double point_radius = CONST_SLOT_FUNCTION_POINT_URADIUS * zoom_y + CONST_SLOT_FUNCTION_POINT_ADD_RADIUS_FOR_SELECTION;
	t_slotitem *temp, *clicked = NULL;
	double item_x_val, item_y_val, item_x_pixel, item_y_pixel;
	double prev_item_x_pixel = 0, prev_item_y_pixel = 0;
	for (temp = get_activeitem_slot_firstitem(r_ob, slot_number); temp; temp = temp->next) {
		item_x_val = ((t_pts *)temp->item)->x;	
		item_y_val = ((t_pts *)temp->item)->y;
        
        switch (r_ob->slotinfo[slot_number].slot_temporalmode) {
            case k_SLOT_TEMPORALMODE_MILLISECONDS:
                item_x_pixel = ms_to_xposition(r_ob, item_x_val + notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem), NULL);
                break;

            case k_SLOT_TEMPORALMODE_RELATIVE:
                item_x_pixel = ms_to_xposition(r_ob, item_x_val * notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_number, r_ob->active_slot_notationitem) + notation_item_get_onset_ms(r_ob, r_ob->active_slot_notationitem), NULL);
                break;

            default:
                item_x_pixel = r_ob->slot_window_active.x + r_ob->slot_window_active.width * notationobj_rescale_with_slope_inv(r_ob, item_x_val, r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1], 0., 1., r_ob->slotinfo[slot_number].slot_domain_par);
                break;
        }
        
		item_y_pixel = 2 * r_ob->slot_window_active.y + r_ob->slot_window_active.height - notationobj_rescale_with_slope_inv(r_ob, item_y_val, r_ob->slotinfo[slot_number].slot_range[0], r_ob->slotinfo[slot_number].slot_range[1], r_ob->slot_window_active.y, r_ob->slot_window_active.y + r_ob->slot_window_active.height, r_ob->slotinfo[slot_number].slot_range_par);
		if (fabs(pt.x - item_x_pixel) < point_radius &&
			((pt.x - item_x_pixel)*(pt.x - item_x_pixel) + (pt.y - item_y_pixel)*(pt.y - item_y_pixel) < point_radius * point_radius)) {
			clicked = temp;
			if (found_item)
				*found_item = k_SLOT_FUNCTION_POINT;
			break;
		} else if (temp->prev && pt.x >= prev_item_x_pixel && pt.x <= item_x_pixel &&
				   is_pt_in_curve_shape(pt.x, pt.y, prev_item_x_pixel, prev_item_y_pixel, item_x_pixel, item_y_pixel, 
										((t_pts *)temp->item)->slope, CONST_SLOT_FUNCTION_UY_LINE_SELECTION_WIDTH * r_ob->zoom_y * (r_ob->slot_window_zoom/100.), (e_slope_mapping)r_ob->slope_mapping_type)) {
			clicked = temp;
			if (found_item)
			   *found_item = k_SLOT_FUNCTION_SEGMENT;
			break;
		}
		prev_item_x_pixel = item_x_pixel;
		prev_item_y_pixel = item_y_pixel;
	}
	return clicked;
}

t_slotitem *pt_to_3dfunction_slot_point(t_notation_obj *r_ob, t_pt pt, long slot_number)
{
	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
	t_slotitem *temp, *clicked = NULL;
	for (temp = get_activeitem_slot_firstitem(r_ob, slot_number); temp; temp = temp->next) {
		t_pt this_pt;
		double this_radius = CONST_SLOT_FUNCTION_POINT_URADIUS * zoom_y * notationobj_rescale_with_slope(r_ob, ((t_pts3d *)temp->item)->z, r_ob->slotinfo[slot_number].slot_zrange[0], r_ob->slotinfo[slot_number].slot_zrange[1], 0.5, 2., r_ob->slotinfo[slot_number].slot_zrange_par);
		function_xyz_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_pts3d *)temp->item)->x, ((t_pts3d *)temp->item)->y, ((t_pts3d *)temp->item)->z, slot_number, r_ob->slot_window_active, &this_pt, r_ob->slot_window_zoom);
		if ((pt.x - this_pt.x)*(pt.x - this_pt.x) + (pt.y - this_pt.y)*(pt.y - this_pt.y) < (this_radius + CONST_SLOT_FUNCTION_POINT_ADD_RADIUS_FOR_SELECTION) * (this_radius + CONST_SLOT_FUNCTION_POINT_ADD_RADIUS_FOR_SELECTION)) {
			clicked = temp;
			break;
		}
	}
	return clicked;
}


t_slotitem *pt_to_spat_slot_point(t_notation_obj *r_ob, t_pt pt, long slot_number)
{
    double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
    t_slotitem *temp, *clicked = NULL;
    for (temp = get_activeitem_slot_firstitem(r_ob, slot_number); temp; temp = temp->next) {
        t_pt this_pt;
        double this_radius = CONST_SLOT_SPAT_CIRCLE_URADIUS * zoom_y;
        
        function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, ((t_spatpt *)temp->item)->t, ((t_spatpt *)temp->item)->radius, slot_number, r_ob->slot_window_active, &this_pt);
        
        if ((pt.x - this_pt.x)*(pt.x - this_pt.x) + (pt.y - this_pt.y)*(pt.y - this_pt.y) < (this_radius + CONST_SLOT_FUNCTION_POINT_ADD_RADIUS_FOR_SELECTION) * (this_radius + CONST_SLOT_FUNCTION_POINT_ADD_RADIUS_FOR_SELECTION)) {
            clicked = temp;
            break;
        }
    }
    return clicked;
}


void pt_to_function_xy_values(t_notation_obj *r_ob, t_notation_item *nitem, t_pt pt, long slot_number, t_rect active_slot_window, double *xval, double *yval)
{
    switch (r_ob->slotinfo[slot_number].slot_temporalmode) {
        case k_SLOT_TEMPORALMODE_MILLISECONDS:
            *xval = xposition_to_ms(r_ob, pt.x, 0) - (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0);
            break;
            
        case k_SLOT_TEMPORALMODE_RELATIVE:
        {
            double duration = (nitem ? notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_number, nitem) : 1);
            *xval = (xposition_to_ms(r_ob, pt.x, 0) - (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0))/(duration == 0 ? 1 : duration);
        }
            break;

        default:
            *xval = notationobj_rescale_with_slope(r_ob, pt.x, active_slot_window.x, active_slot_window.x + active_slot_window.width, r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1], r_ob->slotinfo[slot_number].slot_domain_par);
            break;
    }
	*yval = notationobj_rescale_with_slope(r_ob, active_slot_window.y + active_slot_window.height - pt.y, 0, active_slot_window.height, r_ob->slotinfo[slot_number].slot_range[0], r_ob->slotinfo[slot_number].slot_range[1], r_ob->slotinfo[slot_number].slot_range_par);
}

void function_xy_values_to_pt(t_notation_obj *r_ob, t_notation_item *nitem, double xval, double yval, long slot_number, t_rect active_slot_window, t_pt *pt)
{
    switch (r_ob->slotinfo[slot_number].slot_temporalmode) {
        case k_SLOT_TEMPORALMODE_MILLISECONDS:
            pt->x = ms_to_xposition(r_ob, xval + (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0), NULL);
            break;
            
        case k_SLOT_TEMPORALMODE_RELATIVE:
            pt->x = ms_to_xposition(r_ob, xval * (nitem ? notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_number, nitem) : 1) + (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0), NULL);
            break;
            
        default:
            pt->x = active_slot_window.x + notationobj_rescale_with_slope_inv(r_ob, xval, r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1], 0., 1., r_ob->slotinfo[slot_number].slot_domain_par) * active_slot_window.width;
            break;
    }
	pt->y = 2 * active_slot_window.y + active_slot_window.height - notationobj_rescale_with_slope_inv(r_ob, yval, r_ob->slotinfo[slot_number].slot_range[0], r_ob->slotinfo[slot_number].slot_range[1], active_slot_window.y, active_slot_window.y + active_slot_window.height, r_ob->slotinfo[slot_number].slot_range_par);
}


void function_xyz_values_to_pt(t_notation_obj *r_ob, t_notation_item *nitem, double xval, double yval, double zval, long slot_number, t_rect active_slot_window, t_pt *pt, double slot_zoom)
{
	double zoom_y = r_ob->zoom_y * (slot_zoom / 100.);
    
    switch (r_ob->slotinfo[slot_number].slot_temporalmode) {
        case k_SLOT_TEMPORALMODE_MILLISECONDS:
            pt->x = ms_to_xposition(r_ob, xval + (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0), NULL);
            break;
            
        case k_SLOT_TEMPORALMODE_RELATIVE:
            pt->x = ms_to_xposition(r_ob, xval * notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_number, nitem) + (nitem ? notation_item_get_onset_ms(r_ob, nitem) : 0), NULL);
            break;

        default:
            pt->x = active_slot_window.x + notationobj_rescale_with_slope_inv(r_ob, xval, r_ob->slotinfo[slot_number].slot_domain[0], r_ob->slotinfo[slot_number].slot_domain[1], 0., 1., r_ob->slotinfo[slot_number].slot_domain_par) * active_slot_window.width;
            break;
    }
    
	pt->y = 2 * active_slot_window.y + active_slot_window.height - notationobj_rescale_with_slope_inv(r_ob, yval, r_ob->slotinfo[slot_number].slot_range[0], r_ob->slotinfo[slot_number].slot_range[1], active_slot_window.y, active_slot_window.y + active_slot_window.height, r_ob->slotinfo[slot_number].slot_range_par);
	// accounting for z dimension
	double L = CONST_SLOT_3DFUNCTION_ZDIM_USIZE * zoom_y;
	double alpha = CONST_SLOT_3DFUNCTION_ZDIM_ANGLE;
	double rescaled_z = notationobj_rescale_with_slope_inv(r_ob, zval, r_ob->slotinfo[slot_number].slot_zrange[0], r_ob->slotinfo[slot_number].slot_zrange[1], 0., 1., r_ob->slotinfo[slot_number].slot_zrange_par);
//	double z_ratio = (rescaled_z - r_ob->slotinfo[slot_number].slot_zrange[0])/(r_ob->slotinfo[slot_number].slot_zrange[1] - r_ob->slotinfo[slot_number].slot_zrange[0]);
	pt->x = pt->x - L * rescaled_z * sin(alpha);
	pt->y = pt->y + L * rescaled_z * cos(alpha);
}




long pt_to_card_id_in_slot(t_notation_obj *r_ob, t_pt pt, long slot_number, t_rect active_slot_window)
{
    long num_cols = get_slot_cards_num_cols(r_ob, slot_number);
    double card_width = get_slot_cards_single_card_width(r_ob, slot_number);
    double card_height = get_slot_cards_single_card_height(r_ob, slot_number);

    if (pt.y - active_slot_window.y < 0)
        return -1;
    
    long id = 1 + (long)floor(MAX(0, pt.y - active_slot_window.y) / card_height) * num_cols + (long)floor(MAX(0, pt.x - active_slot_window.x) / card_width);
    
    long type = r_ob->slotinfo[slot_number].slot_type;
    long max = 0;
    switch (type) {
        case k_SLOT_TYPE_ARTICULATIONS:
            max = r_ob->articulations_typo_preferences.num_articulations;
            break;
            
        case k_SLOT_TYPE_NOTEHEAD:
            max = r_ob->noteheads_typo_preferences.num_noteheads;
            break;
            
        default:
            break;
    }
    
    if (id > 0 && id < max)
        return id;
    
    return -1;
}


t_slotitem *articulation_id_to_slotitem(t_notation_obj *r_ob, t_notation_item *nitem, long slot_number, long art_ID)
{
    t_slotitem *temp;
    for (temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); temp; temp = temp->next)
        if (((t_articulation *)temp->item)->articulation_ID == art_ID)
            return temp;
    return NULL;
}

t_slotitem *pt_to_articulation_slotitem(t_notation_obj *r_ob, t_pt pt, long slot_number, t_rect active_slot_window, long *art_ID)
{
    long id = pt_to_card_id_in_slot(r_ob, pt, slot_number, active_slot_window);
    if (art_ID) *art_ID = id;
    if (id > 0 && r_ob->active_slot_notationitem)
        return articulation_id_to_slotitem(r_ob, r_ob->active_slot_notationitem, slot_number, id);
    return NULL;
}


t_slotitem *notehead_id_to_slotitem(t_notation_obj *r_ob, t_notation_item *nitem, long slot_number, long nh_ID)
{
    t_slotitem *temp;
    for (temp = notation_item_get_slot_firstitem(r_ob, nitem, slot_number); temp; temp = temp->next)
        if (temp->item && *((long *)temp->item) == nh_ID)
            return temp;
    return NULL;
}

t_slotitem *pt_to_notehead_slotitem(t_notation_obj *r_ob, t_pt pt, long slot_number, t_rect active_slot_window, long *nh_ID)
{
    long id = pt_to_card_id_in_slot(r_ob, pt, slot_number, active_slot_window);
    if (nh_ID) *nh_ID = id;
    if (id > 0 && r_ob->active_slot_notationitem)
        return notehead_id_to_slotitem(r_ob, r_ob->active_slot_notationitem, slot_number, id);
    return NULL;
}

//mouse hover on slots
// returns 1 if something has been found
char slot_handle_mousemove(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers, char *redraw, char *mousepointer_changed)
{
    *mousepointer_changed = false;

	t_slotitem *prevhoveredslotitem = r_ob->hovered_slotitem;
	if (r_ob->active_slot_num > -1 && r_ob->active_slot_notationitem) {
		int s = r_ob->active_slot_num;
		char must_return = true;
		
		switch (r_ob->slotinfo[s].slot_type) {
			case k_SLOT_TYPE_FUNCTION:
				if (is_pt_in_slot_window(r_ob, pt.x, pt.y)) {
					long element_type = k_SLOT_FUNCTION_POINT;
					r_ob->hovered_slotitem = pt_to_function_slot_point(r_ob, pt, s, true, &element_type);
					r_ob->hovering_segment = (element_type == k_SLOT_FUNCTION_SEGMENT ? true : false); 
					if (redraw) 
						*redraw = 1;
					must_return = true;
				}
				break;
			case k_SLOT_TYPE_3DFUNCTION:
				r_ob->hovered_slotitem = pt_to_3dfunction_slot_point(r_ob, pt, s);
				if (redraw) 
					*redraw = 1;
				must_return = true;
				break;
            case k_SLOT_TYPE_ARTICULATIONS:
            case k_SLOT_TYPE_NOTEHEAD:
                if (is_pt_in_slot_window(r_ob, pt.x, pt.y)) {
                    if (redraw)
                        *redraw = 1;
                    must_return = true;
                }
                break;
			default:
				break;
		}

        // changing mousecursors
        char found = false;
        char is_pt_in_subwindow = is_pt_in_inner_slot_subwindow(r_ob, pt);

        if (slot_is_writable(r_ob, s)) {
            switch (r_ob->slotinfo[s].slot_type) {
                case k_SLOT_TYPE_3DFUNCTION:
                case k_SLOT_TYPE_FUNCTION:
                case k_SLOT_TYPE_SPAT:
                    if (r_ob->hovered_slotitem && (is_pt_in_subwindow || r_ob->j_mouse_is_down) && modifiers != eCommandKey) {
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview,
                                        r_ob->hovering_segment ? (modifiers == eControlKey ? BACH_CURSOR_CURVE : BACH_CURSOR_RESIZE_UPDOWN) : BACH_CURSOR_RESIZE_FOURWAY);
                        *mousepointer_changed = true;
                        found = true;
                    }
                    if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FUNCTION && is_pt_in_subwindow) {
                        if ((r_ob->slot_pen_mode || !r_ob->j_mouse_is_down) && modifiers == eControlKey && !r_ob->hovered_slotitem) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_PENCIL);
                            *mousepointer_changed = true;
                            found = true;
                        } else if (!r_ob->hovered_slotitem && modifiers == eShiftKey) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CROSSHAIR);
                            *mousepointer_changed = true;
                            found = true;
                        }
                    } else if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_SPAT && is_pt_in_subwindow) {
                        if (modifiers == eControlKey) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_ROTATION); // rotate
                            *mousepointer_changed = true;
                            found = true;
                        } else if (modifiers == eAltKey) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_SWITCH); // linear vs interp
                            *mousepointer_changed = true;
                            found = true;
                        }
                    }
                    break;
                case k_SLOT_TYPE_INTLIST:
                case k_SLOT_TYPE_FLOATLIST:
                    if (is_pt_in_subwindow) {
                        long idx = pt_to_slot_longfloatlistbar_strip(r_ob, pt.x, pt.y);
                        if (idx >= get_activeitem_slot_length(r_ob, s) && modifiers == 0) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_ADD_POINT);
                            *mousepointer_changed = true;
                            found = true;
                        } else if (idx >= 0) {
                            if (modifiers == eCommandKey + eAltKey)  {
                                bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_REVERT); // revert to default
                                *mousepointer_changed = true;
                                found = true;
                            }
                        }
                    }
                    break;
                case k_SLOT_TYPE_INT:
                case k_SLOT_TYPE_FLOAT:
                    if (is_pt_in_slot_longfloat_strip(r_ob, pt.x, pt.y)) {
                        if (modifiers == eCommandKey + eAltKey) {
                            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_REVERT); // revert to default
                            *mousepointer_changed = true;
                            found = true;
                        }
                    }
                case k_SLOT_TYPE_FILELIST:
                    if (modifiers == eShiftKey) {
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_SWITCH); // change file
                        *mousepointer_changed = true;
                        found = true;
                    }
            }
        }
		
		if (!found) {
            if (is_pt_in_subwindow && modifiers == eCommandKey) {
                *mousepointer_changed = true;
				bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DELETE);
//            } else {
//				bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
            }
		}
		
		if (must_return)
			return 1;
	}
	if (redraw) 
		*redraw = (prevhoveredslotitem != r_ob->hovered_slotitem);
	return 0;
}


char notation_item_has_slot_content(t_notation_obj *r_ob, t_notation_item *nitem, e_data_considering_types mode)
{
	long i;
	for (i=0; i<CONST_MAX_SLOTS; i++) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && mode == k_CONSIDER_FOR_SAMPLING && nitem->type == k_NOTE && r_ob->slotinfo[i].slot_singleslotfortiednotes) {
            if (notation_item_get_slot_firstitem(r_ob, (t_notation_item *)note_get_first_in_tieseq((t_note *)nitem), i))
                return true;
        } else {
            if (notation_item_get_slot_firstitem(r_ob, nitem, i))
                return true;
        }
	}
	return false;
}


t_symbol *get_slot_type_as_pwgl_symbol(t_notation_obj *r_ob, long slot_num)
{
	switch (r_ob->slotinfo[slot_num].slot_type) {
		case k_SLOT_TYPE_FUNCTION:
			return gensym(":function");
			break;
		case k_SLOT_TYPE_3DFUNCTION:
			return gensym(":32function");
			break;
		case k_SLOT_TYPE_INT:
			return gensym(":int");
			break;
		case k_SLOT_TYPE_FLOAT:
			return gensym(":float");
			break;
		case k_SLOT_TYPE_INTLIST:
			return gensym(":intlist");
			break;
		case k_SLOT_TYPE_FLOATLIST:
			return gensym(":floatlist");
			break;
		case k_SLOT_TYPE_INTMATRIX:
			return gensym(":intmatrix");
			break;
		case k_SLOT_TYPE_FLOATMATRIX:
			return gensym(":floatmatrix");
			break;
		case k_SLOT_TYPE_TOGGLEMATRIX:
			return gensym(":togglematrix");
			break;
		case k_SLOT_TYPE_FILELIST:
			return gensym(":filelist");
			break;
		case k_SLOT_TYPE_TEXT:
			return gensym(":text");
			break;
		case k_SLOT_TYPE_LLLL:
			return gensym(":llll");
			break;
		case k_SLOT_TYPE_SPAT:
			return gensym(":spat");
			break;
		case k_SLOT_TYPE_FILTER:
			return gensym(":filter");
			break;
		case k_SLOT_TYPE_DYNFILTER:
			return gensym(":dynfilter");
			break;
		case k_SLOT_TYPE_COLOR:
			return gensym(":color");
			break;
        case k_SLOT_TYPE_ARTICULATIONS:
            return gensym(":articulations");
            break;
        case k_SLOT_TYPE_NOTEHEAD:
            return gensym(":notehead");
            break;
        case k_SLOT_TYPE_DYNAMICS:
            return gensym(":dynamics");
            break;
		default:
			return gensym(":none");
	}	
}

void append_note_slot_formatted_for_pwgl(t_notation_obj *r_ob, t_llll *this_note_llll, t_note *note){	
	t_slotitem *item;
	llll_appendsym(this_note_llll, gensym(":expressions"), 0, WHITENULL_llll);
	
	t_llll *slot_llll = llll_get();
	long i;
	for (i = 0; i < CONST_MAX_SLOTS; i++) {
		if (note->slot[i].firstitem) {
			t_llll *this_slot_llll = llll_get();
			char slot_id[100];
			
			if (r_ob->slotinfo[i].slot_type == k_SLOT_TYPE_FUNCTION) {
				snprintf_zero(slot_id, 99, ":bpf/%d", r_ob->private_count);
				llll_appendsym(this_slot_llll, gensym(slot_id), 0, WHITENULL_llll);
				llll_appendsym(this_slot_llll, gensym(":print-symbol"), 0, WHITENULL_llll);
				llll_appendsym(this_slot_llll, r_ob->slotinfo[i].slot_name, 0, WHITENULL_llll);
				
				t_llll *breakpoint_functions = llll_get();
				t_llll *breakpoints = llll_get(); // PWGL has the possibility to associate more than one function
				llll_appendsym(this_slot_llll, gensym(":break-point-functions"), 0, WHITENULL_llll);
				for (item = note->slot[i].firstitem; item; item = item->next) {
					t_pts *this_pt = (t_pts *)item->item;
					t_llll *this_bpt_llll = llll_get();
					llll_appenddouble(this_bpt_llll, this_pt->x, 0, WHITENULL_llll);
					llll_appenddouble(this_bpt_llll, this_pt->y, 0, WHITENULL_llll);
					llll_appendsym(this_bpt_llll, gensym(":slope"), 0, WHITENULL_llll);
					llll_appenddouble(this_bpt_llll, this_pt->slope, 0, WHITENULL_llll);
					llll_appendllll(breakpoints, this_bpt_llll, 0, WHITENULL_llll);
				}
				llll_appendllll(breakpoint_functions, breakpoints, 0, WHITENULL_llll);
				llll_appendllll(this_slot_llll, breakpoint_functions, 0, WHITENULL_llll);
			} else {
				char *buf = NULL;
				t_llll *slotval = note_get_single_slot_values_as_llll(r_ob, note, k_CONSIDER_FOR_EXPORT_PWGL, i, false);
				snprintf_zero(slot_id, 99, ":group/%d", r_ob->private_count);
				llll_appendsym(this_slot_llll, gensym(slot_id), 0, WHITENULL_llll);
				llll_appendsym(this_slot_llll, gensym(":print-symbol"), 0, WHITENULL_llll);
//				if (r_ob->slotinfo[i].slot_type != k_SLOT_TYPE_TEXT)
				llll_wrap_once(&slotval);
				llll_to_text_buf(slotval, &buf, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_PWGL_STYLE, LLLL_TB_PWGL_STYLE, NULL);
				llll_appendsym(this_slot_llll, gensym(buf), 0, WHITENULL_llll);
				llll_free(slotval);
			}

			r_ob->private_count++;
			
			t_llll *plist = llll_get();
			llll_appendsym(this_slot_llll, gensym(":plist"), 0, WHITENULL_llll);
			llll_appendsym(plist, gensym(":bach-slot-type"), 0, WHITENULL_llll);
			llll_appendsym(plist, get_slot_type_as_pwgl_symbol(r_ob, i), 0, WHITENULL_llll);
			llll_appendsym(plist, gensym(":bach-slot-number"), 0, WHITENULL_llll);
			llll_appendlong(plist, i + 1, 0, WHITENULL_llll);
			llll_appendllll(this_slot_llll, plist, 0, WHITENULL_llll);

			llll_appendllll(slot_llll, this_slot_llll, 0, WHITENULL_llll);

		}
	}
	
	llll_appendllll(this_note_llll, slot_llll, 0, WHITENULL_llll);
	
}




//could be computationally improved.
//computes the gain response of a filter, relative to frequency freq and period T
// TODO: MAKE THIS MORE EFFICIENT (it's extremely easy)
double gain_response(double freq, double sampling_freq, double a1, double a2, double b0, double b1, double b2) {
	double omega = 2*PI*freq;
	double T = 1/sampling_freq; // period
	double numerator = pow((b0+b1*cos(omega*T)+b2*cos(2*omega*T)), 2) + pow((b1*sin(omega*T)+b2*sin(2*omega*T)), 2);
	double denominator = pow((1+a1*cos(omega*T)+a2*cos(2*omega*T)), 2) + pow((a1*sin(omega*T)+a2*sin(2*omega*T)), 2);
	return sqrt(numerator/denominator);
}


double gain_response_dB(double freq, double sampling_freq, double a1, double a2, double b0, double b1, double b2) {
	double linear = gain_response(freq, sampling_freq, a1, a2, b0, b1, b2);
	return 20 * log(linear)/log(10.);
}


void synchronize_biquad_coeff_from_freq_gain_and_Q(t_biquad *biquad, double sampling_freq){
    double freq = biquad->cutoff_freq;
	double gain = biquad->gain_dB;
	double Q = biquad->Q;
	
	double A = sqrt(pow(10, gain/20));
	double w0 = 2*PI*freq/sampling_freq;
	double cos_w0 = cos(w0);
	double sin_w0 = sin(w0);
	double alpha;
	
	// check Q!!!
	if (Q < CONST_FILTER_MIN_Q){
		Q = biquad->Q = CONST_FILTER_MIN_Q;
	}
	
	if (biquad->filter_type == k_FILTER_PEAKNOTCH || biquad->filter_type == k_FILTER_BANDPASS || biquad->filter_type == k_FILTER_BANDSTOP || 
		biquad->filter_type == k_FILTER_LOWPASS || biquad->filter_type == k_FILTER_HIGHPASS || biquad->filter_type == k_FILTER_RESONANT 
		|| biquad->filter_type == k_FILTER_ALLPASS) {
		biquad->bandwidth = asinh(1/(2*Q))/(M_LN2/2 * w0/sin_w0);
//		alpha = sin_w0 * sinh(M_LN2/2 * biquad->bandwidth * w0/sin_w0);
	} else if (biquad->filter_type == k_FILTER_HIGHSHELF || biquad->filter_type == k_FILTER_LOWSHELF) {
		biquad->shelfslope = 1/((1/(Q*Q) - 2)/(A + 1/A) + 1);
//		alpha = sin_w0/2 * sqrt((A + 1/A)*(1/biquad->shelfslope - 1) + 2);
	}
	
	alpha = sin_w0/(2*Q);

	switch (biquad->filter_type) {
		case k_FILTER_LOWPASS:
			biquad->b0 = A * (1 - cos_w0) /2;
			biquad->b1 = A * (1 - cos_w0);
			biquad->b2 = A * (1 - cos_w0) /2;
			biquad->a0 = 1 + alpha;
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = 1 - alpha;
			break;
		case k_FILTER_HIGHPASS:
			biquad->b0 = A * (1 + cos_w0) / 2;
			biquad->b1 = - A * (1 + cos_w0);
			biquad->b2 = A * (1 + cos_w0) / 2;
			biquad->a0 = 1 + alpha;
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = 1 - alpha;
			break;
		case k_FILTER_BANDPASS:
			biquad->b0 = alpha * A;
			biquad->b1 = 0;
			biquad->b2 = -alpha * A;
			biquad->a0 = 1 + alpha;
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = 1 - alpha;
			break;
		case k_FILTER_BANDSTOP:
			biquad->b0 = A;
			biquad->b1 = -2 * A * cos_w0;
			biquad->b2 = A;
			biquad->a0 = 1 + alpha;
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = 1 - alpha;
			break;
		case k_FILTER_PEAKNOTCH: 
			biquad->b0 = 1 + (alpha * A);
			biquad->b1 = -2 * cos_w0;
			biquad->b2 = 1 - (alpha * A);
			biquad->a0 = 1 + (alpha / A);
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = 1 - (alpha / A);
			break;
		case k_FILTER_LOWSHELF:
			biquad->b0 = A * ((A + 1) - (A - 1) * cos_w0 + 2*sqrt(A)*alpha);
			biquad->b1 = 2 * A * ((A - 1) - (A + 1) * cos_w0);
			biquad->b2 = A * ((A + 1) - (A - 1) * cos_w0 - 2*sqrt(A)*alpha);
			biquad->a0 = (A + 1) + (A - 1) * cos_w0 + 2*sqrt(A)*alpha;
			biquad->a1 = -2 * ((A - 1) + (A + 1) * cos_w0);
			biquad->a2 = (A + 1) + (A - 1) * cos_w0 - 2*sqrt(A)*alpha;
			break;
		case k_FILTER_HIGHSHELF:
			biquad->b0 = A * ((A + 1) + (A - 1) * cos_w0 + 2*sqrt(A)*alpha);
			biquad->b1 = -2 * A * ((A - 1) + (A + 1) * cos_w0);
			biquad->b2 = A * ((A + 1) + (A - 1) * cos_w0 - 2*sqrt(A)*alpha);
			biquad->a0 = (A + 1) - (A - 1) * cos_w0 + 2*sqrt(A)*alpha;
			biquad->a1 = 2 * ((A - 1) - (A + 1) * cos_w0);
			biquad->a2 = (A + 1) - (A - 1) * cos_w0 - 2*sqrt(A)*alpha;
			break;
		case k_FILTER_ALLPASS:
			biquad->b0 = (A*A) *(1 - alpha);
			biquad->b1 = -2 * (A*A) * cos_w0;
			biquad->b2 = (A*A) * (1 + alpha);
			biquad->a0 = (1 + alpha);
			biquad->a1 = -2 * cos_w0;
			biquad->a2 = (1 - alpha);
			break;
			// RESONANT: todo!
		case k_FILTER_RESONANT: 
		{
			double r = exp(-PI * biquad->bandwidth * 1/sampling_freq);
			biquad->b0 = 1;
			biquad->b1 = 0;
			biquad->b2 = -biquad->b0;
			biquad->a0 = (1 + alpha);
			biquad->a1 = 2 * r * cos(TWOPI * biquad->cutoff_freq / sampling_freq);
			biquad->a2 = r * r / 1 / (1 + alpha);
			break;
		}
		default: // should never get here
			biquad->b0 = A;
			biquad->b1 = -2 * A;
			biquad->b2 = A;
			biquad->a0 = 1;
			biquad->a1 = -2;
			biquad->a2 = 1;
			break;
    }
	
	if (biquad->a0 != 1) { // normalization
		double a0 = biquad->a0;
		biquad->a1 /= a0;
		biquad->a2 /= a0;
		biquad->b0 /= a0;
		biquad->b1 /= a0;
		biquad->b2 /= a0;
		biquad->a0 = 1;
	}
}

e_filter_types filtersym_to_filtertype(t_symbol *sym){
	if (sym == _llllobj_sym_display)
		return k_FILTER_DISPLAY;
	else if (sym == _llllobj_sym_lowpass)
		return k_FILTER_LOWPASS;
	else if (sym == _llllobj_sym_highpass)
		return k_FILTER_HIGHPASS;
	else if (sym == _llllobj_sym_bandpass)
		return k_FILTER_BANDPASS;
	else if (sym == _llllobj_sym_bandstop)
		return k_FILTER_BANDSTOP;
	else if (sym == _llllobj_sym_peaknotch)
		return k_FILTER_PEAKNOTCH;
	else if (sym == _llllobj_sym_lowshelf)
		return k_FILTER_LOWSHELF;
	else if (sym == _llllobj_sym_highshelf)
		return k_FILTER_HIGHSHELF;
	else if (sym == _llllobj_sym_resonant)
		return k_FILTER_RESONANT;
	else if (sym == _llllobj_sym_allpass)
		return k_FILTER_ALLPASS;
	else
		return k_FILTER_NONE;
}

t_symbol *filtertype_to_filtersym(long filtertype){
	switch (filtertype) {
		case k_FILTER_DISPLAY:
			return _llllobj_sym_display;
		case k_FILTER_LOWPASS:
			return _llllobj_sym_lowpass;
		case k_FILTER_HIGHPASS:
			return _llllobj_sym_highpass;
		case k_FILTER_BANDPASS:
			return _llllobj_sym_bandpass;
		case k_FILTER_BANDSTOP:
			return _llllobj_sym_bandstop;
		case k_FILTER_PEAKNOTCH:
			return _llllobj_sym_peaknotch;
		case k_FILTER_LOWSHELF:
			return _llllobj_sym_lowshelf;
		case k_FILTER_HIGHSHELF:
			return _llllobj_sym_highshelf;
		case k_FILTER_RESONANT:
			return _llllobj_sym_resonant;
		case k_FILTER_ALLPASS:
			return _llllobj_sym_allpass;
		default:
			return _llllobj_sym_none;
	}
}



void set_file_from_symbol(t_notation_obj *r_ob, t_file *file, t_symbol *sym){
	t_fourcc type = 0;
	
	if (path_frompathname(sym->s_name, &file->pathID, file->filename)) {	// (char *)(sym->s_name + 100)
		char filename[MAX_PATH_CHARS];
		char foldername[MAX_PATH_CHARS];
		char filename_nopath[MAX_PATH_CHARS];
		
		strncpy_zero(filename, sym->s_name, MAX_PATH_CHARS);
		// file was NOT located exactly in the position it pointed to (as a full path).
		
		path_splitnames(filename, foldername, filename_nopath);
		if (!filename_nopath[0]) {
			strncpy_zero(filename_nopath, filename, MAX_PATH_CHARS);
			foldername[0] = 0;
		}
		
		if (locatefile_extended(filename_nopath, &file->pathID, &type, &type,-1)) { 
			// file could not be located, not even in all Max's search path.
			// We still add it as an item, but we mark it as non-existing (we cannot ignore it: 
			// when one moves the patches one doesn't want
			// to lose slot content, even if the files could NOT be located any more!!!!)
			file->exists = false;
			file->pathID = 0;
			object_warn((t_object *) r_ob, "Warning: file %s could not be located", sym->s_name);
			strncpy_zero(file->filename, sym->s_name, MAX_PATH_CHARS);
			//											bach_freeptr(thisitem);
			//											bach_freeptr(file);
		} else {
			// file was anyway located in the Max's search path. We update the information.
			file->exists = true;
			strncpy_zero(file->filename, filename_nopath, MAX_PATH_CHARS);
		} 
		file->filename_length = strlen(file->filename);
	} else {
		// file was located exactly in the position it pointed to (as a full path).
		file->filename_length = strlen(file->filename);
		file->exists = true;
	}
}

int simple_compare_longs_fn(const void *a, const void *b){
	return isign(*((long *)a) - *((long *)b));
}

void change_background_slot_flag(t_notation_obj *r_ob, long slot_num_0_based, char new_flag){
	long idx = longarray_findidx(r_ob->num_background_slots, slot_num_0_based + 1, r_ob->background_slots);
	if (new_flag){
		if (idx == -1 && r_ob->num_background_slots < CONST_MAX_SLOTS) 
			r_ob->background_slots[r_ob->num_background_slots++] = slot_num_0_based+1;
		r_ob->slotinfo[slot_num_0_based].kept_in_background = true;
		qsort(r_ob->background_slots, r_ob->num_background_slots, sizeof(long), simple_compare_longs_fn);
	} else {
		if (idx >= 0) {
			sysmem_copyptr(&r_ob->background_slots[idx+1], &r_ob->background_slots[idx], (r_ob->num_background_slots - idx - 1) * sizeof(long));
			r_ob->num_background_slots--;
		}
		r_ob->slotinfo[slot_num_0_based].kept_in_background = false;
	}
}

void change_popupmenu_slot_flag(t_notation_obj *r_ob, long slot_num_0_based, char new_flag){
	long idx = longarray_findidx(r_ob->num_popup_menu_slots, slot_num_0_based + 1, r_ob->popup_menu_slots);
	if (new_flag){
		if (idx == -1 && r_ob->num_popup_menu_slots < CONST_MAX_SLOTS) 
			r_ob->popup_menu_slots[r_ob->num_popup_menu_slots++] = slot_num_0_based+1;
		r_ob->slotinfo[slot_num_0_based].appear_in_popup_menu = true;
		qsort(r_ob->popup_menu_slots, r_ob->num_popup_menu_slots, sizeof(long), simple_compare_longs_fn);
	} else {
		if (idx >= 0) {
			sysmem_copyptr(&r_ob->popup_menu_slots[idx+1], &r_ob->popup_menu_slots[idx], (r_ob->num_popup_menu_slots - idx - 1) * sizeof(long));
			r_ob->num_popup_menu_slots--;
		}
		r_ob->slotinfo[slot_num_0_based].appear_in_popup_menu = false;
	}
}




t_max_err notation_obj_setattr_lyrics_font(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        long size = NULL;
        char *text = NULL;
        
        atom_gettext_debug(ac, av, &size, &text, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
        
        if (size && text) {
            t_symbol *font = gensym(text);
            r_ob->lyrics_font = font;
            implicitely_recalculate_all(r_ob, false);
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
            bach_freeptr(text);
        }
    }
    return MAX_ERR_NONE;
}

t_max_err notation_obj_setattr_annotations_font(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        long size = NULL;
        char *text = NULL;
        
        atom_gettext_debug(ac, av, &size, &text, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
        
        if (size && text) {
            t_symbol *font = gensym(text);
            r_ob->annotations_font = font;
            implicitely_recalculate_all(r_ob, false);
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
            bach_freeptr(text);
        }
    }
    return MAX_ERR_NONE;
}


t_max_err notation_obj_setattr_showaccidentalspreferences(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac) {
        r_ob->show_accidentals_preferences = (e_show_accidentals_preferences)CLAMP(atom_getlong(av), 0, 5);
        quick_notation_obj_recompute_all_chord_parameters(r_ob);
    }

    return MAX_ERR_NONE;
}

t_max_err notation_obj_setattr_backgroundslots(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
	long i;
	for (i = 0; i < CONST_MAX_SLOTS; i++)
		r_ob->slotinfo[i].kept_in_background = false;

//	dev_post("object %x asks for %ld bgslots", r_ob, ac);
	if (ac) {
		for (i = 0; i < ac && i < CONST_MAX_SLOTS; i++, av++) {
			long this_slot = CLAMP(1, atom_getlong(av), CONST_MAX_SLOTS);
			r_ob->background_slots[i] = this_slot;
			r_ob->slotinfo[this_slot - 1].kept_in_background = true;
		}
	} 
	r_ob->num_background_slots = ac;
	
	return MAX_ERR_NONE;
}


t_max_err notation_obj_setattr_popupmenuslots(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
	long i;
	for (i = 0; i < CONST_MAX_SLOTS; i++)
		r_ob->slotinfo[i].appear_in_popup_menu = false;
	for (i = 0; i < ac && i < CONST_MAX_SLOTS; i++, av++){
		long this_slot = CLAMP(1, atom_getlong(av), CONST_MAX_SLOTS);
		r_ob->popup_menu_slots[i] = this_slot;
		r_ob->slotinfo[this_slot - 1].appear_in_popup_menu = true;
	}
	r_ob->num_popup_menu_slots = ac;
	return MAX_ERR_NONE;
}


t_max_err notation_obj_setattr_rightclickdirectlypopsoutslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
	long i;
	for (i = 0; i < CONST_MAX_SLOTS; i++)
		r_ob->slotinfo[i].pops_up_by_right_click = false;
	if (ac) {
		long slotnum = atom_getlong(av);
		r_ob->right_click_directly_pops_out_slot = 0;
		if (slotnum > 0 && slotnum <= CONST_MAX_SLOTS) {
			r_ob->right_click_directly_pops_out_slot = slotnum;
			r_ob->slotinfo[slotnum-1].pops_up_by_right_click = true;
		} 
		return MAX_ERR_NONE;
	} else
		return MAX_ERR_GENERIC;
}

long linkto_sym_to_linkto_elem(t_notation_obj *r_ob, t_symbol *sym){
	if (sym == _llllobj_sym_lyrics)
		return k_SLOT_LINKAGE_LYRICS;
	else if (sym == _llllobj_sym_notecolor || sym == _llllobj_sym_color)
		return k_SLOT_LINKAGE_NOTE_COLOR;
	else if (sym == _llllobj_sym_noteheadadjust)
		return k_SLOT_LINKAGE_NOTEHEAD_ADJUST;
	else if (sym == _llllobj_sym_notehead || sym == _llllobj_sym_noteheadchar)
		return k_SLOT_LINKAGE_NOTEHEAD;
	else if (sym == _llllobj_sym_noteheadfont)
		return k_SLOT_LINKAGE_NOTEHEAD_FONT;
	else if (sym == _llllobj_sym_notesize)
		return k_SLOT_LINKAGE_NOTE_SIZE;
    else if (sym == _llllobj_sym_articulations)
        return k_SLOT_LINKAGE_ARTICULATIONS;
    else if (sym == _llllobj_sym_annotation)
        return k_SLOT_LINKAGE_ANNOTATION;
    else if (sym == _llllobj_sym_dynamics)
        return k_SLOT_LINKAGE_DYNAMICS;
    else if (sym == _llllobj_sym_dlcolor)
        return k_SLOT_LINKAGE_DURATIONLINE_COLOR;
	return k_SLOT_LINKAGE_NONE;
}

void set_linkto_notation_obj_field_to_value(t_notation_obj *r_ob, char link_to_what, long value){
	switch (link_to_what) {
		case k_SLOT_LINKAGE_LYRICS:
			r_ob->link_lyrics_to_slot = value;
			break;
		case k_SLOT_LINKAGE_NOTE_COLOR:
			r_ob->link_nitemcolor_to_slot = value;
			break;
		case k_SLOT_LINKAGE_NOTEHEAD_ADJUST:
			r_ob->link_notehead_adjust_to_slot = value;
			break;
		case k_SLOT_LINKAGE_NOTEHEAD:
			r_ob->link_notehead_to_slot = value;
			break;
		case k_SLOT_LINKAGE_NOTEHEAD_FONT:
			r_ob->link_notehead_font_to_slot = value;
			break;
		case k_SLOT_LINKAGE_NOTE_SIZE:
			r_ob->link_notesize_to_slot = value;
			break;
        case k_SLOT_LINKAGE_ARTICULATIONS:
            r_ob->link_articulations_to_slot = value;
            break;
        case k_SLOT_LINKAGE_ANNOTATION:
            r_ob->link_annotation_to_slot = value;
            break;
        case k_SLOT_LINKAGE_DYNAMICS:
            r_ob->link_dynamics_to_slot = value;
            break;
        case k_SLOT_LINKAGE_DURATIONLINE_COLOR:
            r_ob->link_dlcolor_to_slot = value;
            break;
	}
}

void change_linkto_slot_flag(t_notation_obj *r_ob, long slot_num_0_based, char link_to_what){
	
    set_linkto_notation_obj_field_to_value(r_ob, link_to_what, 0);
    if (slot_num_0_based >= 0 && slot_num_0_based < CONST_MAX_SLOTS) {
        // deleting previous value
        if (r_ob->slotinfo[slot_num_0_based].linked_to) {
            set_linkto_notation_obj_field_to_value(r_ob, r_ob->slotinfo[slot_num_0_based].linked_to, 0);
            r_ob->slotinfo[slot_num_0_based].linked_to = k_SLOT_LINKAGE_NONE;
        }
        
        // setting new value
        if (link_to_what != k_SLOT_LINKAGE_NONE){
            long i;
            for (i = 0; i < CONST_MAX_SLOTS; i++)
                if (r_ob->slotinfo[i].linked_to == link_to_what)
                    r_ob->slotinfo[i].linked_to = k_SLOT_LINKAGE_NONE;
            r_ob->slotinfo[slot_num_0_based].linked_to = link_to_what;
            set_linkto_notation_obj_field_to_value(r_ob, link_to_what, slot_num_0_based + 1);
        }
    }
    if (link_to_what == k_SLOT_LINKAGE_LYRICS || link_to_what == k_SLOT_LINKAGE_NOTEHEAD_ADJUST ||
        link_to_what == k_SLOT_LINKAGE_NOTEHEAD || link_to_what == k_SLOT_LINKAGE_NOTEHEAD_FONT ||
        link_to_what == k_SLOT_LINKAGE_NOTE_SIZE || link_to_what == k_SLOT_LINKAGE_ARTICULATIONS ||
        link_to_what == k_SLOT_LINKAGE_ANNOTATION || link_to_what == k_SLOT_LINKAGE_DYNAMICS)
        implicitely_recalculate_all(r_ob, false);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}

double get_function_slot_interp(t_notation_obj *r_ob, t_note *note, long slot_num, double x)
{
	if (slot_num >= 0 && slot_num < CONST_MAX_SLOTS) {
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FUNCTION) {
			t_slotitem *it = note->slot[slot_num].firstitem;

			if (!it)
				return 0; // TO DO: return default?
				
			while (it) {
				t_pts *pts = (t_pts *)it->item;
				if (x < pts->x)
					break;
				it = it->next;
			}
			
			// here <it> is the item at right side of x
		
            if (!it) {// after last item
                t_slotitem *lastitem = slot_get_last_item(&note->slot[slot_num]);
                if (!lastitem)
                    return 0;
				return ((t_pts *)lastitem->item)->y;
            } else if (!it->prev) // before first item
				return ((t_pts *)note->slot[slot_num].firstitem->item)->y;
			else {
				t_pts *next = (t_pts *)it->item;
				t_pts *prev = (t_pts *)it->prev->item;
				return notationobj_rescale_with_slope(r_ob, x, prev->x, next->x, prev->y, next->y, next->slope);
			}
		}
	}

	object_warn((t_object *)r_ob, "Warning: querying interpolation of non-function slot.");
	return 0;
}

t_llll* get_function_slot_sampling(t_notation_obj *r_ob, t_note *note, long slot_num, long num_pts)
{
    t_llll *out = NULL;
    if (slot_num >= 0 && slot_num < CONST_MAX_SLOTS) {
        if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FUNCTION) {
            long i;
            double domain_min = r_ob->slotinfo[slot_num].slot_domain[0];
            double domain_max = r_ob->slotinfo[slot_num].slot_domain[1];
            double domain_slope = r_ob->slotinfo[slot_num].slot_domain_par;
            t_llll *x_ll = llll_get();
            t_llll *y_ll = llll_get();
            
            out = llll_get();
            
            for (i = 0; i < num_pts; i++) {
                double this_x = notationobj_rescale_with_slope(r_ob, i, 0, num_pts - 1, domain_min, domain_max, domain_slope);
                double this_y = get_function_slot_interp(r_ob, note, slot_num, this_x);
                llll_appenddouble(x_ll, this_x, 0, WHITENULL_llll);
                llll_appenddouble(y_ll, this_y, 0, WHITENULL_llll);
            }
            llll_appendllll(out, x_ll, 0, WHITENULL_llll);
            llll_appendllll(out, y_ll, 0, WHITENULL_llll);
        } else {
            object_warn((t_object *)r_ob, "Warning: querying for sampling of non-function slot.");
        }
    }
    return out;
}



    
double slot_get_max_x(t_notation_obj *r_ob, t_slot *slot, long slot_num)
{
    t_slotitem *li = slot_get_last_item(slot);
    if (li) {
        switch (r_ob->slotinfo[slot_num].slot_type) {
            case k_SLOT_TYPE_FUNCTION:
                return ((t_pts *)li->item)->x;

            case k_SLOT_TYPE_3DFUNCTION:
                return ((t_pts3d *)li->item)->x;

            case k_SLOT_TYPE_SPAT:
                return ((t_spatpt *)li->item)->t;

            case k_SLOT_TYPE_DYNFILTER:
                return ((t_biquad *)li->item)->t;

            default:
                return 0;
        }
    } else
        return 0;
}

double notationobj_get_slot_max_x(t_notation_obj *r_ob, long slot_num)
{
    double max_x = 0;
    for (t_voice *v = r_ob->firstvoice; v && v->number < r_ob->num_voices; v = voice_get_next(r_ob, v)) {
        for (t_chord *c = chord_get_first(r_ob, v); c; c = chord_get_next(c)) {
            if (!c->firstnote) {
                max_x = MAX(max_x, slot_get_max_x(r_ob, notation_item_get_slot(r_ob, (t_notation_item *)c, slot_num), slot_num));
            } else {
                for (t_note *n = c->firstnote; n; n = n->next)
                    max_x = MAX(max_x, slot_get_max_x(r_ob, notation_item_get_slot(r_ob, (t_notation_item *)n, slot_num), slot_num));
            }
        }
    }
    return max_x;
}

double slot_get_domain_min(t_notation_obj *r_ob, long slot_num)
{
    if (r_ob->slotinfo[slot_num].slot_temporalmode != k_SLOT_TEMPORALMODE_MILLISECONDS)
        return r_ob->slotinfo[slot_num].slot_domain[0];
    else
        return 0;
}



double slot_get_domain_max(t_notation_obj *r_ob, long slot_num, t_notation_item *nitem)
{
    if (r_ob->slotinfo[slot_num].slot_temporalmode != k_SLOT_TEMPORALMODE_MILLISECONDS)
        return r_ob->slotinfo[slot_num].slot_domain[1];
    else
        return notation_item_get_duration_ms_for_slots_account_for_ties(r_ob, slot_num, nitem);
}

double slot_get_domain_max_force_default_duration(t_notation_obj *r_ob, long slot_num, double default_duration)
{
    if (r_ob->slotinfo[slot_num].slot_temporalmode != k_SLOT_TEMPORALMODE_MILLISECONDS)
        return r_ob->slotinfo[slot_num].slot_domain[1];
    else
        return default_duration;
}



t_llll* get_function_slot_sampling_delta(t_notation_obj *r_ob, t_note *note, long slot_num, double delta)
{
	t_llll *out = NULL;
	if (slot_num >= 0 && slot_num < CONST_MAX_SLOTS) {
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_FUNCTION) {
            double domain_min, domain_max;
            
            switch (r_ob->slotinfo[slot_num].slot_temporalmode) {
                case k_SLOT_TEMPORALMODE_MILLISECONDS:
                    domain_min = 0;
                    domain_max = slot_get_max_x(r_ob, &note->slot[slot_num], slot_num);
                    break;
                    
                default:
                    domain_min = r_ob->slotinfo[slot_num].slot_domain[0];
                    domain_max = r_ob->slotinfo[slot_num].slot_domain[1];
                    break;
            }
			
            t_llll *x_ll = llll_get();
			t_llll *y_ll = llll_get();
			
			out = llll_get();
			
            double this_x = domain_min;
			for (; this_x <= domain_max; this_x += delta) {
				double this_y = get_function_slot_interp(r_ob, note, slot_num, this_x);
				llll_appenddouble(x_ll, this_x, 0, WHITENULL_llll);
				llll_appenddouble(y_ll, this_y, 0, WHITENULL_llll);
			}
			llll_appendllll(out, x_ll, 0, WHITENULL_llll);
			llll_appendllll(out, y_ll, 0, WHITENULL_llll);
		} else {
			object_warn((t_object *)r_ob, "Warning: querying for sampling of non-function slot.");
		}
	}
	return out;
}


void paste_slotitems(t_notation_obj *r_ob, t_notation_item *nitem, long slotnum, t_llll *newitems, t_rect active_slot_window, double offset, char delete_intermediate_points)
{
	double slot_domain_min = r_ob->slotinfo[slotnum].slot_domain[0];
	double slot_domain_max = r_ob->slotinfo[slotnum].slot_domain[1];
	t_llllelem *elem;
	t_slotitem *last_inserted = NULL;
	for (elem = newitems->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *this_ll = hatom_getllll(&elem->l_hatom);
			if (this_ll->l_size >= 2 && is_hatom_number(&this_ll->l_head->l_hatom) && is_hatom_number(&this_ll->l_head->l_next->l_hatom)) {
				double xval = 0, yval = 0, slope = 0;
				t_pt pt;
				xval = hatom_getdouble(&this_ll->l_head->l_hatom);
				yval = hatom_getdouble(&this_ll->l_head->l_next->l_hatom);

				// offseting x value
			 	function_xy_values_to_pt(r_ob, nitem, xval, yval, slotnum, active_slot_window, &pt);
				pt.x += offset;
				pt_to_function_xy_values(r_ob, nitem, pt, slotnum, active_slot_window, &xval, &yval);
				
				// retrieving slope
				if (this_ll->l_size >= 3 && is_hatom_number(&this_ll->l_head->l_next->l_next->l_hatom))
					slope = hatom_getdouble(&this_ll->l_head->l_next->l_next->l_hatom);
				
				if (slot_can_extend_beyond_note_tail(r_ob, slotnum) || (xval >= slot_domain_min && xval <= slot_domain_max))
					last_inserted = insert_new_slot_function_point(r_ob, slotnum, xval, yval, slope, false, delete_intermediate_points ? last_inserted : NULL);
			}
		}
	}
}



// expects 1-based input and outputs 1-based outputs
t_llll *slots_develop_ranges(t_notation_obj *r_ob, t_llll *ll)
{
    t_llll *output = llll_get();
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        t_hatom *elem_hatom = &elem->l_hatom;
        long type = hatom_gettype(elem_hatom);
        if (type == H_LLLL) {
            t_llll *range_ll = hatom_getllll(elem_hatom);
            switch (range_ll->l_size) {
                case 1:
                {
                    llll_appendhatom_clone(output, &range_ll->l_head->l_hatom);
                    break;
                }
                case 2:
                {
                    t_atom_long start = llllelem_to_slotnum(r_ob, range_ll->l_head, true) + 1; // must revert them to be 1 based
                    t_atom_long end = llllelem_to_slotnum(r_ob, range_ll->l_tail, true) + 1;
                    t_atom_long incr = start <= end ? 1 : -1;
                    t_atom_long i;
                    for (i = start; i <= end; i += incr)
                        llll_appendlong(output, i, 0, WHITENULL_llll);
                    break;
                }
            }
        } else {
            llll_appendhatom_clone(output, elem_hatom);
        }
    }
    pedantic_llll_check(output);
    return output;
}


void notationobj_sel_erase_slot(t_notation_obj *r_ob, long slotnum, char lambda)
{
    t_notation_item *curr_it;
    char changed = 0;
    
    lock_general_mutex(r_ob);
    curr_it = notation_item_get_first_selected_account_for_lambda(r_ob, lambda);
    while (curr_it) {
        if (curr_it->type == k_NOTE) {
            t_note *nt = (t_note *) curr_it;
            if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)nt->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                note_clear_slot(r_ob, nt, slotnum);
                changed = 1;
            }
        } else if (curr_it->type == k_CHORD) {
            t_chord *ch = (t_chord *) curr_it;
            t_note *nt;
            if (!ch->firstnote && r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)ch)) {
                    create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                    notation_item_clear_slot(r_ob, (t_notation_item *)ch, slotnum);
                    changed = 1;
                }
#endif
            } else {
                for (nt=ch->firstnote; nt; nt = nt->next) {
                    if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        note_clear_slot(r_ob, nt, slotnum);
                        changed = 1;
                    }
                }
            }
        } else if (curr_it->type == k_MEASURE) {
            t_measure *meas = (t_measure *) curr_it;
            t_chord *ch = meas->firstchord;
            while (ch) {
                t_note *nt;
                for (nt=ch->firstnote; nt; nt = nt->next) {
                    if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        note_clear_slot(r_ob, nt, slotnum);
                        changed = 1;
                    }
                }
                ch = ch->next;
            }
        }
        curr_it = lambda ? NULL : curr_it->next_selected;
    }
    unlock_general_mutex(r_ob);

}


// this function must be mutex-locked
void notationobj_sel_move_slot(t_notation_obj *r_ob, long slotfrom, long slotto, char keeporiginal, char lambda)
{
    t_notation_item *curr_it;
    char changed = 0;
    
    curr_it = notation_item_get_first_selected_account_for_lambda(r_ob, lambda);
    while (curr_it) {
        if (curr_it->type == k_NOTE) {
            t_note *nt = (t_note *) curr_it;
            if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)nt->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                move_note_slot(r_ob, nt, slotfrom, slotto, keeporiginal, true);
                changed = 1;
            }
        } else if (curr_it->type == k_CHORD) {
            t_chord *ch = (t_chord *) curr_it;
            t_note *nt;
            if (!ch->firstnote && r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)ch)) {
                    create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                    move_notationitem_slot(r_ob, (t_notation_item *)ch, slotfrom, slotto, keeporiginal, true);
                    changed = 1;
                }
#endif
            } else {
                for (nt=ch->firstnote; nt; nt = nt->next) {
                    if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        move_note_slot(r_ob, nt, slotfrom, slotto, keeporiginal, true);
                        changed = 1;
                    }
                }
            }
        } else if (curr_it->type == k_MEASURE) {
            t_measure *meas = (t_measure *) curr_it;
            t_chord *ch = meas->firstchord;
            while (ch) {
                t_note *nt;
                for (nt=ch->firstnote; nt; nt = nt->next) {
                    if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        move_note_slot(r_ob, nt, slotfrom, slotto, keeporiginal, true);
                        changed = 1;
                    }
                }
                ch = ch->next;
            }
        }
        curr_it = lambda ? NULL : curr_it->next_selected;
    }
}




// arguments are: slot#, position, new value (as llll).
// this function must be mutexed
void notationobj_sel_change_slot_item_from_params(t_notation_obj *r_ob, t_llll *args_orig, char lambda, e_slot_changeslotitem_modes mode)
{
    long slotnum, position;
    t_llll *args = llll_clone(args_orig);
    char changed = 0;

    if (!args || !args->l_head)
        return;
    
    long voice = 0, modify = 0;
    double thresh = 0.;
    llll_parseattrs((t_object *)r_ob, args, true, "iid", _llllobj_sym_voice, &voice, _llllobj_sym_modify, &modify, _llllobj_sym_thresh, &thresh);
    voice -= 1;
    
    if (mode == k_CHANGESLOTITEM_MODE_INSERT_AUTO && args->l_size <= 2)
        llll_insertlong_after(1, args->l_head); // dummy position for auto-insertion mode

    if (mode == k_CHANGESLOTITEM_MODE_DELETE_ONE && args->l_size == 2 && hatom_gettype(&args->l_head->l_next->l_hatom) == H_LLLL)
        llll_insertlong_after(1, args->l_head); // dummy position for deletion from X value

    if (!args->l_head || !args->l_head->l_next)
        return;
    
    slotnum = llllelem_to_slotnum(r_ob, args->l_head, true);
    if (slotnum < 0) {
        llll_free(args);
        return;
    }
    
    llll_behead(args);
    
    if (hatom_gettype(&args->l_head->l_hatom) == H_SYM) {
        if (hatom_getsym(&args->l_head->l_hatom) == _llllobj_sym_all) {
            if (mode == k_CHANGESLOTITEM_MODE_MODIFY_ONE)
                mode = k_CHANGESLOTITEM_MODE_MODIFY_ALL;
            else if (mode == k_CHANGESLOTITEM_MODE_DELETE_ONE)
                mode = k_CHANGESLOTITEM_MODE_DELETE_ALL;
        } else if (hatom_getsym(&args->l_head->l_hatom) == _llllobj_sym_auto) {
            if (mode == k_CHANGESLOTITEM_MODE_INSERT)
                mode = k_CHANGESLOTITEM_MODE_INSERT_AUTO;
        }
        position = 1;
    } else {
        position = hatom_getlong(&args->l_head->l_hatom);
    }
    
    llll_behead(args);
    
    if (args) {
        t_notation_item *curr_it;

        curr_it = notation_item_get_first_selected_account_for_lambda(r_ob, lambda);
        while (curr_it) {
            if (curr_it->type == k_NOTE) {
                t_note *nt = (t_note *) curr_it;
                if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                    if (voice < 0 || voice == notation_item_get_voicenumber(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)nt->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        note_change_slot_item(r_ob, nt, slotnum, position, args, mode, modify, thresh);
                        changed = 1;
                    }
                }
            } else if (curr_it->type == k_CHORD) {
                t_chord *ch = (t_chord *) curr_it;
                if (voice < 0 || voice == notation_item_get_voicenumber(r_ob, (t_notation_item *)ch)) {
                    if (!ch->firstnote) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        notation_item_change_slotitem(r_ob, (t_notation_item *)ch, slotnum, position, args, mode, modify, thresh);
                        changed = 1;
#endif
                    } else {
                        t_note *nt;
                        for (nt=ch->firstnote; nt; nt = nt->next) {
                            if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                                note_change_slot_item(r_ob, nt, slotnum, position, args, mode, modify, thresh);
                                changed = 1;
                            }
                        }
                    }
                }
            } else if (curr_it->type == k_MEASURE) {
                t_measure *meas = (t_measure *) curr_it;
                if (voice < 0 || voice == notation_item_get_voicenumber(r_ob, (t_notation_item *)meas)) {
                    t_chord *ch = meas->firstchord;
                    while (ch) {
                        t_note *nt;
                        for (nt=ch->firstnote; nt; nt = nt->next) {
                            if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                                note_change_slot_item(r_ob, nt, slotnum, position, args, mode, modify, thresh);
                                changed = 1;
                            }
                        }
                        ch = ch->next;
                    }
                }
            }
            curr_it = lambda ? NULL : curr_it->next_selected;
        }
    }
    
    llll_free(args);
}








// slot_number < 0 reduces the duration line
long notation_item_reducefunction(t_notation_obj *r_ob, t_notation_item *nitem, long slot_number, long maxnumpoints, double thresh, long p, long relative, long slope, long algorithm, e_slope_mapping slopemapping)
{
    long changed = 0;
    t_llll *ll = NULL;
    if (slot_number >= 0)
        ll = notation_item_get_single_slot_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_SLOT_VALUES_ONLY, slot_number, false);
    else if (nitem->type == k_NOTE)
        ll = note_get_breakpoints_values_no_router_as_llll(r_ob, (t_note *)nitem);
    else // nothing to reduce
        return changed;
    
    if (relative && slot_number >= 0)
        thresh *= (r_ob->slotinfo[slot_number].slot_range[1] - r_ob->slotinfo[slot_number].slot_range[0]);

    if (!ll) // nothing to reduce
        return changed;
    
    t_llll *reduced = llll_approximate_breakpoint_function(ll, maxnumpoints, thresh, p, algorithm, slope, slopemapping);
    
    if (slot_number >= 0) {
        t_llll *set_ll = llll_get();
        t_llll *subset_ll = llll_get();
        llll_appendlong(subset_ll, slot_number + 1);
        llll_chain(subset_ll, reduced);
        llll_appendllll(set_ll, subset_ll);
        notation_item_set_slots_from_llll(r_ob, nitem, set_ll);
        changed = 1;
        llll_free(set_ll);
    } else if (nitem->type == k_NOTE) {
        note_set_breakpoints_from_llll(r_ob, (t_note *)nitem, reduced);
        changed = 1;
        llll_free(reduced);
    }
    
    
    return changed;
}

// arguments are: slot#, position, new value (as llll).
// this function must be mutexed
void notationobj_sel_reducefunction(t_notation_obj *r_ob, t_llll *args_orig, char lambda)
{
    
    t_llll *args = llll_clone(args_orig);
    char changed = 0;
    
    if (!args || !args->l_head)
        return;
    
    long maxnumpoints = 0, p = 1, relative = 1, slope = 1, algorithm = 1;
    t_symbol *slopemapping_sym = gensym("bach");
    double thresh = 0.;
    llll_parseattrs((t_object *)r_ob, args, true, "idiisi", gensym("maxnumpoints"), &maxnumpoints, _llllobj_sym_thresh, &thresh, _llllobj_sym_p, &p, _llllobj_sym_slope, &slope, gensym("slopemapping"), &slopemapping_sym, gensym("algorithm"), &algorithm);
    e_slope_mapping slopemapping = ((slopemapping_sym == gensym("Max") || slopemapping_sym == gensym("max")) ? k_SLOPE_MAPPING_MAX : k_SLOPE_MAPPING_BACH);
    
    if (!args->l_head || !args->l_head)
        return;
    
    long slotnum;
    if (args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_SYM && hatom_getsym(&args->l_head->l_hatom) == gensym("durationline"))
        slotnum = -1;
    else {
        slotnum = llllelem_to_slotnum(r_ob, args->l_head, true);
        if (slotnum < 0) {
            llll_free(args);
            return;
        }
    }
    
    t_notation_item *curr_it;
    
    curr_it = notation_item_get_first_selected_account_for_lambda(r_ob, lambda);
    while (curr_it) {
        if (curr_it->type == k_NOTE) {
            t_note *nt = (t_note *) curr_it;
            if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)nt->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                changed = notation_item_reducefunction(r_ob, curr_it, slotnum, maxnumpoints, thresh, p, relative, slope, algorithm, slopemapping);
            }
        } else if (curr_it->type == k_CHORD) {
            t_chord *ch = (t_chord *) curr_it;
            if (!ch->firstnote) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                changed = notation_item_reducefunction(r_ob, curr_it, slotnum, maxnumpoints, thresh, p, relative, slope, algorithm, slopemapping);
#endif
            } else {
                t_note *nt;
                for (nt=ch->firstnote; nt; nt = nt->next) {
                    if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                        create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                        changed = notation_item_reducefunction(r_ob, (t_notation_item *)nt, slotnum, maxnumpoints, thresh, p, relative, slope, algorithm, slopemapping);
                    }
                }
            }
        } else if (curr_it->type == k_MEASURE) {
            t_measure *meas = (t_measure *) curr_it;
            t_chord *ch = meas->firstchord;
            while (ch) {
                t_note *nt;
                if (!ch->firstnote) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                    create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                    changed = notation_item_reducefunction(r_ob, (t_notation_item *)ch, slotnum, maxnumpoints, thresh, p, relative, slope, algorithm, slopemapping);
#endif
                } else {
                    for (nt=ch->firstnote; nt; nt = nt->next) {
                        if (!notation_item_is_globally_locked(r_ob, (t_notation_item *)nt)) {
                            create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
                            changed = notation_item_reducefunction(r_ob, (t_notation_item *)nt, slotnum, maxnumpoints, thresh, p, relative, slope, algorithm, slopemapping);
                        }
                    }
                }
                ch = ch->next;
            }
        }
        curr_it = lambda ? NULL : curr_it->next_selected;
    }
    
    llll_free(args);
}




