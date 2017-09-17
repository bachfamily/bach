#include "notation.h" 

static t_class	*s_bach_inspector_ui_class;

/// Tools for dealing with bach specific attributes (appearing in the bach inspector)

char *field2string(void *field, char type, long size, long max_decimals){
	char *res = NULL;
	switch (type) {
		case k_BACH_ATTR_CHAR:
			res = (char *)bach_newptr(20 * sizeof(char));
			snprintf_zero(res, 20, "%d", *((char *)field));
			break;
		case k_BACH_ATTR_LONG:
			res = (char *)bach_newptr(20 * sizeof(char));
			snprintf_zero(res, 20, "%ld", *((long *)field));
			break;
		case k_BACH_ATTR_RAT:
			res = (char *)bach_newptr(40 * sizeof(char));
			snprintf_zero(res, 40, "%ld/%ld", ((t_rational *)field)->r_num, ((t_rational *)field)->r_den);
			break;
		case k_BACH_ATTR_COLOR:
			res = (char *)bach_newptr(80 * sizeof(char));
			snprintf_zero(res, 80, "%.2f %.2f %.2f %.2f", ((t_jrgba *)field)->red, ((t_jrgba *)field)->green, ((t_jrgba *)field)->blue, ((t_jrgba *)field)->alpha);
			break;
		case k_BACH_ATTR_DOUBLE:
			res = double_to_string(*((double *)field), max_decimals);
			break;
		case k_BACH_ATTR_LONG_ARRAY:
			res = long_array_to_string((long *) field, size, false); 
			break;
		case k_BACH_ATTR_RAT_ARRAY:
			res = rat_array_to_string((t_rational *) field, size, false); 
			break;
		case k_BACH_ATTR_DOUBLE_ARRAY:
			res = double_array_to_string((double *) field, size, max_decimals); 
			break;
		case k_BACH_ATTR_ATOM_ARRAY: 
		case k_BACH_ATTR_ATOM_ARRAY_VARSIZE: 
		{
			long textsize;
			atom_gettext_debug(size, (t_atom *) field, &textsize, &res, 0);
			break;
		}
		case k_BACH_ATTR_SYM:
		{
			t_llll *temp = llll_get();
            if (*((t_symbol **)field) != NULL)
                llll_appendsym(temp, *((t_symbol **)field));
            else
                llll_appendsym(temp, _llllobj_sym_none);
			llll_to_text_buf(temp, &res, 0, BACH_DEFAULT_MAXDECIMALS, 0, NULL);
			llll_free(temp);
			break;
		}
		case k_BACH_ATTR_ATOM:
		{
			long textsize;
			atom_gettext_debug(1, (t_atom *) field, &textsize, &res, 0);
			break;
		}
		case k_BACH_ATTR_LLLL:
			llll_to_text_buf(*((t_llll **)field), &res, 0, BACH_DEFAULT_MAXDECIMALS, 0, NULL);
			break;
		case k_BACH_ATTR_OBJ:
			res = (char *)bach_newptr(80 * sizeof(char));
			snprintf_zero(res, 80, "%p", *(void **)field);
			break;
		case k_BACH_ATTR_BIT:
			res = (char *)bach_newptr(20 * sizeof(char));
			snprintf_zero(res, 20, "%ld", *((long *)field) & size ? 1 : 0);
			break;
		default:
			res = (char *)bach_newptr(20 * sizeof(char));
			snprintf_zero(res, 20, "???");
			break;
	}
	return res;
}

char is_atom_nonzero(t_atom *atom)
{
	if (atom_gettype(atom) == A_LONG)
		return atom_getlong(atom) != 0;
	else if (atom_gettype(atom) == A_FLOAT)
		return atom_getfloat(atom) != 0;
	else if (atom_gettype(atom) == A_SYM)
		return atom_getsym(atom) != NULL;
	return 0;
}

char is_attribute_nonzero(void *obj, t_bach_attribute *attr, char type){
    if (!obj)
        return false;
    
	void *field = (char *) obj + attr->field_position;
	switch (type) {
		case k_BACH_ATTR_CHAR:
			return *((char *)field) ? 1 : 0;
		case k_BACH_ATTR_LONG:
			return *((long *)field) ? 1 : 0;
		case k_BACH_ATTR_RAT:
			return ((t_rational *)field)->r_num ? 1 : 0;
		case k_BACH_ATTR_COLOR:
			return 1;
		case k_BACH_ATTR_DOUBLE:
			return *((double *)field) ? 1 : 0;
		case k_BACH_ATTR_LONG_ARRAY:
		case k_BACH_ATTR_RAT_ARRAY:
		case k_BACH_ATTR_ATOM_ARRAY:
		case k_BACH_ATTR_DOUBLE_ARRAY:
			return 1;
		case k_BACH_ATTR_ATOM_ARRAY_VARSIZE:
			return (*((long *)((char *) obj + attr->field_position_for_var_attr_size)) ? 1 : 0);
		case k_BACH_ATTR_SYM:
			return *((t_symbol **)field) ? 1 : 0;
		case k_BACH_ATTR_ATOM:
			return is_atom_nonzero(((t_atom *)field));
		case k_BACH_ATTR_LLLL:
			return *((t_llll **)field) ? 1 : 0;
		case k_BACH_ATTR_OBJ:
			return *((void **)field) ? 1 : 0;
		default:
			return 0;
	}
}


void initialize_attr_manager(t_bach_attr_manager *man){
	long i;
	man->inspector_header = (bach_inspector_header_fn)bach_default_inspector_header_fn;
	man->inspector_image = (bach_inspector_image_fn)bach_get_icon_surface_fn;
	for (i = 0; i < CONST_MAX_BACH_ELEMENT_TYPES; i++) {
		man->num_attr[i] = 0;
		man->miniature[i] = NULL;
		man->color[i] = NULL;
//		man->header[i] = NULL;
	}
}

void declare_bach_attribute(t_bach_attr_manager *man, char forced_position, t_symbol *name, const char *displayed_label, long owner_type, long field_position, long attr_type, long attr_size, char display_type, long preprocess_flags, long postprocess_flags)
{
	long current_num_attr = man->num_attr[owner_type];
	long n = (forced_position < 0 || current_num_attr >= CONST_MAX_BACH_ATTR - 1) ? current_num_attr : MIN(forced_position, current_num_attr);

	if (n < current_num_attr && current_num_attr < CONST_MAX_BACH_ATTR) {
		long i;
		sysmem_copyptr(&man->attr[owner_type][n], &man->attr[owner_type][n+1], (current_num_attr - n) * sizeof(t_bach_attribute));
		for (i = n+1; i <= current_num_attr; i++)
			man->attr[owner_type][i].idx++;
	}
	
	if (n < CONST_MAX_BACH_ATTR) {
		man->attr[owner_type][n].idx = n;
		man->attr[owner_type][n].owner_type = owner_type;
		man->attr[owner_type][n].attr_size = attr_size;
		man->attr[owner_type][n].attr_type = attr_type;
		man->attr[owner_type][n].display_type = display_type;
		man->attr[owner_type][n].num_enum_index_elems = 0;
		man->attr[owner_type][n].name = name;
		man->attr[owner_type][n].displayed_label = displayed_label;
		man->attr[owner_type][n].field_position = field_position;
		man->attr[owner_type][n].setter = NULL;
		man->attr[owner_type][n].getter = NULL;
		man->attr[owner_type][n].preprocess = NULL;
		man->attr[owner_type][n].postprocess = NULL;
		man->attr[owner_type][n].field_position_for_var_attr_size = -1;
		man->attr[owner_type][n].preprocess_flags = preprocess_flags;
		man->attr[owner_type][n].postprocess_flags = postprocess_flags;
		man->attr[owner_type][n].inactive = NULL;
		man->num_attr[owner_type]++;
	}
	
}

t_bach_attribute *get_bach_attribute(t_bach_attr_manager *man, long owner_type, t_symbol *name)
{
	long i;
	for (i = 0; i < man->num_attr[owner_type]; i++) {
		if (man->attr[owner_type][i].name == name)
			return &man->attr[owner_type][i];
	}
	return NULL;
}

void bach_attribute_add_var_size_offset(t_bach_attribute *attr, long offset)
{
	if (attr)
		attr->field_position_for_var_attr_size = offset;
}

void bach_attribute_add_functions(t_bach_attribute *attr, bach_getter_fn getter, bach_setter_fn setter, bach_attr_process_fn preprocess, bach_attr_process_fn postprocess, bach_inactive_fn inactive)
{
	if (attr){
		attr->getter = getter;
		attr->setter = setter;
		attr->preprocess = preprocess;
		attr->postprocess = postprocess;
		attr->inactive = inactive;
	}
}



void bach_attribute_add_enumindex(t_bach_attribute *attr, long num_items, t_symbol **items)
{
	if (attr){
		long i;
		attr->num_enum_index_elems = num_items;
		for (i = 0; i < num_items; i++)
			attr->enum_index[i] = items[i];
	}
}


long get_field_position(void *field, void *structure){
	return ((long)field) - ((long)structure);
}

void get_slottypes_as_sym_list(t_notation_obj *r_ob, t_symbol **list)
{
    long i;
    for (i = 0; i < k_NUM_SLOT_TYPES; i++)
        list[i] = slot_type_to_symbol((e_slot_types)i);
}

void get_slotlinkages_as_sym_list(t_notation_obj *r_ob, t_symbol **list)
{
	list[k_SLOT_LINKAGE_NONE] = _llllobj_sym_none;
	list[k_SLOT_LINKAGE_LYRICS] = _llllobj_sym_lyrics;
	list[k_SLOT_LINKAGE_NOTE_COLOR] = _llllobj_sym_notecolor;
	list[k_SLOT_LINKAGE_NOTEHEAD_ADJUST] = _llllobj_sym_noteheadadjust;
	list[k_SLOT_LINKAGE_NOTEHEAD_FONT] = _llllobj_sym_noteheadfont;
	list[k_SLOT_LINKAGE_NOTEHEAD] = _llllobj_sym_notehead;
    list[k_SLOT_LINKAGE_NOTE_SIZE] = _llllobj_sym_notesize;
    list[k_SLOT_LINKAGE_ARTICULATIONS] = _llllobj_sym_articulations;
    list[k_SLOT_LINKAGE_ANNOTATION] = _llllobj_sym_annotation;
    list[k_SLOT_LINKAGE_DYNAMICS] = _llllobj_sym_dynamics; 
    list[k_SLOT_LINKAGE_DURATIONLINE_COLOR] = _llllobj_sym_dlcolor;
}

long inspector_umenu_index_to_clef(t_notation_obj *r_ob, long index){
	switch (index) {
		case 0: return k_CLEF_G;
		case 1: return k_CLEF_F;
		case 2: return k_CLEF_FG;
		case 3: return k_CLEF_FF;
		case 4: return k_CLEF_GG;
		case 5: return k_CLEF_FFG;
		case 6: return k_CLEF_FGG;
		case 7: return k_CLEF_FFGG;
            
		case 8: return k_CLEF_G8va;
        case 9: return k_CLEF_G15ma;
        case 10: return k_CLEF_G8vb;
        case 11: return k_CLEF_G15mb;
        case 12: return k_CLEF_F8va;
        case 13: return k_CLEF_F15ma;
        case 14: return k_CLEF_F8vb;
        case 15: return k_CLEF_F15mb;
            
		case 16: return k_CLEF_SOPRANO;
		case 17: return k_CLEF_MEZZO;
		case 18: return k_CLEF_ALTO;
		case 19: return k_CLEF_TENOR;
		case 20: return k_CLEF_BARYTONE;
		case 21: return k_CLEF_PERCUSSION;
		case 22: return k_CLEF_NONE;
		default: return k_CLEF_G;	
	}
}

long clef_to_inspector_umenu_index(t_notation_obj *r_ob, long index){
	switch (index) {
		case k_CLEF_G: return 0;
		case k_CLEF_F: return 1;
		case k_CLEF_FG: return 2;
		case k_CLEF_FF: return 3;
		case k_CLEF_GG: return 4;
		case k_CLEF_FFG: return 5;
		case k_CLEF_FGG: return 6;
		case k_CLEF_FFGG: return 7;

        case k_CLEF_G8va: return 8;
        case k_CLEF_G15ma: return 9;
        case k_CLEF_G8vb: return 10;
        case k_CLEF_G15mb: return 11;
        case k_CLEF_F8va: return 12;
        case k_CLEF_F15ma: return 13;
        case k_CLEF_F8vb: return 14;
        case k_CLEF_F15mb: return 15;
		
        case k_CLEF_SOPRANO: return 16;
        case k_CLEF_MEZZO: return 17;
		case k_CLEF_ALTO: return 18;
		case k_CLEF_TENOR: return 19;
		case k_CLEF_BARYTONE: return 20;
		case k_CLEF_PERCUSSION: return 21;
		case k_CLEF_NONE: return 22;
		default: return 0;	
	}
}

void get_clefs_as_sym_list(t_notation_obj *r_ob, t_symbol **list)
{
	list[0] = _llllobj_sym_G;
	list[1] = _llllobj_sym_F;
	list[2] = _llllobj_sym_FG;
	list[3] = _llllobj_sym_FF;
	list[4] = _llllobj_sym_GG;
	list[5] = _llllobj_sym_FFG;
	list[6] = _llllobj_sym_FGG;
	list[7] = _llllobj_sym_FFGG;
    
	list[8] = _llllobj_sym_G8va;
    list[9] = _llllobj_sym_G15ma;
    list[10] = _llllobj_sym_G8vb;
    list[11] = _llllobj_sym_G15mb;
    list[12] = _llllobj_sym_F8va;
    list[13] = _llllobj_sym_F15ma;
    list[14] = _llllobj_sym_F8vb;
    list[15] = _llllobj_sym_F15mb;

	list[16] = _llllobj_sym_Soprano;
	list[17] = _llllobj_sym_Mezzo;
	list[18] = _llllobj_sym_Alto;
	list[19] = _llllobj_sym_Tenor;
	list[20] = _llllobj_sym_Barytone;
	list[21] = _llllobj_sym_Percussion;
	list[22] = _llllobj_sym_none;
}

void get_access_types_as_sym_list(t_notation_obj *r_ob, t_symbol **list){
    list[0] = gensym("Read and write");
    list[1] = gensym("Read only");
    list[2] = gensym("Can't access");
}


void notation_obj_declare_bach_attributes(t_notation_obj *r_ob){

	// SLOTINFO ATTRIBUTES
	t_symbol *slottypes[k_NUM_SLOT_TYPES];
	t_symbol *slotlinkages[k_NUM_SLOT_LINKAGES];
    t_symbol *accesstypes[3];
	t_symbol *clefs[23];
	t_bach_attr_manager *man = r_ob->m_inspector.attr_manager;
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, "Name", k_SLOTINFO, t_slotinfo, slot_name, k_BACH_ATTR_SYM, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_type, "Type", k_SLOTINFO, t_slotinfo, slot_type, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
	get_slottypes_as_sym_list(r_ob, slottypes);
	bach_attribute_add_enumindex(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_type), k_NUM_SLOT_TYPES, slottypes);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_key, "Hot Key", k_SLOTINFO, t_slotinfo, slot_key, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_CHAR, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_color, "Color", k_SLOTINFO, t_slotinfo, slot_color, k_BACH_ATTR_COLOR, 1, k_BACH_ATTR_DISPLAY_COLOR, 0, 0);

    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_access, "Access", k_SLOTINFO, t_slotinfo, access_type, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
    get_access_types_as_sym_list(r_ob, accesstypes);
    bach_attribute_add_enumindex(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_access), 3, accesstypes);

    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_domain, "Domain", k_SLOTINFO, t_slotinfo, slot_domain, k_BACH_ATTR_DOUBLE_ARRAY, 2, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_domainslope, "Domain Slope", k_SLOTINFO, t_slotinfo, slot_domain_par, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_range, "Range", k_SLOTINFO, t_slotinfo, slot_range, k_BACH_ATTR_DOUBLE_ARRAY, 2, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_slope, "Range Slope", k_SLOTINFO, t_slotinfo, slot_range_par, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_zrange, "Z-Axis Range", k_SLOTINFO, t_slotinfo, slot_zrange, k_BACH_ATTR_DOUBLE_ARRAY, 2, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_zslope, "Z-Axis Range Slope", k_SLOTINFO, t_slotinfo, slot_zrange_par, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_ysnap, "Snap Y Values", k_SLOTINFO, t_slotinfo, slot_ysnap, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_zsnap, "Snap Z Values", k_SLOTINFO, t_slotinfo, slot_zsnap, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_default, "Default Value", k_SLOTINFO, t_slotinfo, slot_default, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_representation, "Representation", k_SLOTINFO, t_slotinfo, slot_repr, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _sym_grid, "Grid", k_SLOTINFO, t_slotinfo, grid, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
		DECLARE_BACH_ATTR(man, -1, _llllobj_sym_singleslotfortiednotes, "Slot Spans Ties", k_SLOTINFO, t_slotinfo, slot_singleslotfortiednotes, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_copywhensplit, "Copy When Split", k_SLOTINFO, t_slotinfo, copy_when_split, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        DECLARE_BACH_ATTR(man, -1, _llllobj_sym_follownotehead, "Follow Notehead", k_SLOTINFO, t_slotinfo, trim_with_notehead, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_width, "Slot Window Width", k_SLOTINFO, t_slotinfo, slot_uwidth, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_height, "Slot Window Height", k_SLOTINFO, t_slotinfo, slot_active_uheight, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_background, "Kept In Background", k_SLOTINFO, t_slotinfo, kept_in_background, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_popup, "Is In Popup Menu", k_SLOTINFO, t_slotinfo, appear_in_popup_menu, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_linkto, "Linked To", k_SLOTINFO, t_slotinfo, linked_to, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
	get_slotlinkages_as_sym_list(r_ob, slotlinkages);
	bach_attribute_add_enumindex(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_linkto), k_NUM_SLOT_LINKAGES, slotlinkages);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_rightclick, "Right-Click Pop Up", k_SLOTINFO, t_slotinfo, pops_up_by_right_click, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_background), NULL, (bach_setter_fn)set_bach_attr_slotinfo_flags, NULL, NULL, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_popup), NULL, (bach_setter_fn)set_bach_attr_slotinfo_flags, NULL, NULL, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_rightclick), NULL, (bach_setter_fn)set_bach_attr_slotinfo_flags, NULL, NULL, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_SLOTINFO, _llllobj_sym_linkto), NULL, (bach_setter_fn)set_bach_attr_slotinfo_flags, NULL, NULL, NULL);


	// NOTE ATTRIBUTES
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, "Name", k_NOTE, t_notation_item, names, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_NOTE, _llllobj_sym_name), NULL, (bach_setter_fn)bach_set_name_fn, NULL, NULL, NULL);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_cents, "Cents", k_NOTE, t_note, midicents, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_pitch, "Pitch", k_NOTE, t_note, midicents, k_BACH_ATTR_SYM, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
		DECLARE_BACH_ATTR(man, -1, _llllobj_sym_duration, "Duration (ms)", k_NOTE, t_note, duration, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_velocity, "Velocity", k_NOTE, t_note, velocity, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
		DECLARE_BACH_ATTR(man, -1, _llllobj_sym_tie, "Tied To Next", k_NOTE, t_note, tie_to, k_BACH_ATTR_OBJ, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_lock, "Lock", k_NOTE, t_note, locked, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_mute, "Mute", k_NOTE, t_note, muted, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_solo, "Solo", k_NOTE, t_note, solo, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_NOTE, _llllobj_sym_lock), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_NOTE, _llllobj_sym_mute), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_NOTE, _llllobj_sym_solo), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	r_ob->m_inspector.attr_manager->miniature[k_NOTE] = (bach_inspector_miniature_fn)bach_note_miniature_fn;

	// CHORD ATTRIBUTES
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, "Name", k_CHORD, t_notation_item, names, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_CHORD, _llllobj_sym_name), NULL, (bach_setter_fn)bach_set_name_fn, NULL, NULL, NULL);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_lock, "Lock", k_CHORD, t_chord, locked, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_mute, "Mute", k_CHORD, t_chord, muted, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_solo, "Solo", k_CHORD, t_chord, solo, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_CHORD, _llllobj_sym_lock), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_CHORD, _llllobj_sym_mute), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_CHORD, _llllobj_sym_solo), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	r_ob->m_inspector.attr_manager->miniature[k_CHORD] = (bach_inspector_miniature_fn)bach_chord_miniature_fn;

	// VOICE ATTRIBUTES
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, "Name", k_VOICE, t_notation_item, names, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_VOICE, _llllobj_sym_name), NULL, (bach_setter_fn)bach_set_name_fn, NULL, NULL, NULL);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_midichannel, "Midichannel", k_VOICE, t_voice, midichannel, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_clef, "Clef", k_VOICE, t_voice, clef, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_key, "Key", k_VOICE, t_voice, key, k_BACH_ATTR_SYM, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	get_clefs_as_sym_list(r_ob, clefs);
	bach_attribute_add_enumindex(get_bach_attribute(man, k_VOICE, _llllobj_sym_clef), 23, clefs);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_stafflines, "Staff Lines", k_VOICE, t_voice, staff_lines_dummy, k_BACH_ATTR_SYM, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_lock, "Lock", k_VOICE, t_voice, locked, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_mute, "Mute", k_VOICE, t_voice, muted, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	DECLARE_BACH_ATTR(man,-1,  _llllobj_sym_solo, "Solo", k_VOICE, t_voice, solo, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_VOICE, _llllobj_sym_lock), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_VOICE, _llllobj_sym_mute), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	bach_attribute_add_functions(get_bach_attribute(man, k_VOICE, _llllobj_sym_solo), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
	
	r_ob->m_inspector.attr_manager->miniature[k_VOICE] = (bach_inspector_miniature_fn)bach_voice_miniature_fn;


	// MARKERS
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, "Name", k_MARKER, t_notation_item, names, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	bach_attribute_add_functions(get_bach_attribute(man, k_MARKER, _llllobj_sym_name), NULL, (bach_setter_fn)bach_set_name_fn, NULL, NULL, NULL);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_onset, "Onset (ms)", k_MARKER, t_marker, position_ms, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

	// PITCH BREAKPOINTS
//	DECLARE_BACH_ATTR(r_ob, -1, _llllobj_sym_name, "Name", k_PITCH_BREAKPOINT, t_notation_item, name, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_position, "Relative Onset Position", k_PITCH_BREAKPOINT, t_bpt, rel_x_pos, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_onset, "Onset (ms)", k_PITCH_BREAKPOINT, t_bpt, dummy_absolute_onset, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_deltacents, "Relative Pitch (Δ cents)", k_PITCH_BREAKPOINT, t_bpt, delta_mc, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_cents, "Pitch (cents)", k_PITCH_BREAKPOINT, t_bpt, dummy_absolute_mc, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_velocity, "Velocity", k_PITCH_BREAKPOINT, t_bpt, velocity, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
	DECLARE_BACH_ATTR(man, -1, _llllobj_sym_slope, "Slope", k_PITCH_BREAKPOINT, t_bpt, slope, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

}


double get_inspector_needed_height(t_bach_inspector_manager *man, long obj_type, double zoom){
	// need to increase needed_height because of umenus or colors?
	long num_attributes = man->attr_manager->num_attr[obj_type];
//	double needed_height = (num_attributes + 0.5) * CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom;
	double needed_height = (num_attributes + 1 + 1.25) * CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom;
	long i;
	for (i = 0; i < num_attributes; i++){
		t_bach_attribute *attr = &man->attr_manager->attr[obj_type][i];
		if (attr->display_type == k_BACH_ATTR_DISPLAY_ENUMINDEX && man->active_inspector_enumindex == attr){
			double needed_height_for_umenu = CONST_BACH_INSPECTOR_ENUMINDEX_UY_STEP * zoom * attr->num_enum_index_elems;
			double ypos_umenu = CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom * (attr->idx + 1);
			double this_bottom_y = ypos_umenu + needed_height_for_umenu + 10 * zoom;
			if (this_bottom_y > needed_height)
				needed_height = this_bottom_y;
		} else if (attr->display_type == k_BACH_ATTR_DISPLAY_COLOR && man->active_inspector_color == attr) {
			double needed_height_for_palette = (70 + 10) * zoom;
			double ypos_palette = CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom * (attr->idx + 1);
			double this_bottom_y = ypos_palette + needed_height_for_palette + 10 * zoom;
			if (this_bottom_y > needed_height)
				needed_height = this_bottom_y;
		}
	}
	return needed_height;
}



// lastline must be sized at least 1000 chars
void get_bach_inspector_lastline_string(t_notation_obj *r_ob, t_bach_inspector_manager *man, char *lastline)
{
	snprintf_zero(lastline, 1000, "");
	
	if (!r_ob)
		return;
	
	if (man->active_bach_inspector_obj_type == k_VOICE) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
			snprintf_zero(lastline, 1000, "↓ next voice, ↑ previous voice, ENTER first chord");
		else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			snprintf_zero(lastline, 1000, "↓ next voice, ↑ previous voice, ENTER first measure");
	} else if (man->active_bach_inspector_obj_type == k_MEASURE) {
		snprintf_zero(lastline, 1000, "→ next measure, ← previous measure, ↓ jump to next voice, ↑ jump to previous voice, ENTER first chord, ESC current voice");
	} else if (man->active_bach_inspector_obj_type == k_TEMPO) {
		snprintf_zero(lastline, 1000, "→ next tempo, ← previous tempo, ESC current measure");
	} else if (man->active_bach_inspector_obj_type == k_CHORD) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) 
			snprintf_zero(lastline, 1000, "→ next chord, ← previous chord, ↓ jump to next voice, ↑ jump to previous voice, ENTER first note, ESC current voice");
		else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			snprintf_zero(lastline, 1000, "→ next chord, ← previous chord, ↓ jump to next voice, ↑ jump to previous voice, ENTER first note, ESC current measure");
	} else if (man->active_bach_inspector_obj_type == k_NOTE) {
		snprintf_zero(lastline, 1000, "↑ next note, ↓ previous note, → jump to next chord, ← jump to previous chord, ENTER first pitch breakpoint, ESC current chord");
	} else if (man->active_bach_inspector_obj_type == k_PITCH_BREAKPOINT) {
		snprintf_zero(lastline, 1000, "→ jump to next pitch breakpoint, ← jump to previous pitch breakpoint, ESC current note");
	} else if (man->active_bach_inspector_obj_type == k_MARKER) {
		snprintf_zero(lastline, 1000, "→ jump to next marker, ← jump to previous marker");
	} else if (man->active_bach_inspector_obj_type == k_SLOTINFO) {
		snprintf_zero(lastline, 1000, "→ next slotinfo, ← previous slotinfo, or use numbers/hotkeys");
	}
}


void paint_bach_inspector_items(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *view, t_rect rect, t_jfont *jf_label, t_jfont *jf_attrname, t_jfont *jf_text, t_jfont *jf_keyfunctions, void *obj, long obj_type, double zoom, t_jrgba background_color){
	double real_height = rect.height - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom;
	double ypos, ystep = CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom;
	double row_vheight = CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT * zoom;
	double step_vpad_before_text = (CONST_BACH_INSPECTOR_ITEM_UY_STEP - CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT) * zoom / 2.;

	t_jrgba attrname_color = CONST_BACH_INSPECTOR_TEXT_COLOR;
	t_jrgba text_color = CONST_BACH_INSPECTOR_TEXT_COLOR;
	t_jrgba text_color_no_correction = CONST_BACH_INSPECTOR_TEXT_COLOR;
	t_jrgba inactive_color = CONST_BACH_INSPECTOR_INACTIVE_COLOR;
	t_jrgba label_color = CONST_BACH_INSPECTOR_TEXT_COLOR;
	t_jrgba umenu_color = get_grey(0.1);
	t_jrgba umenu_bg_color = build_jrgba(0.95, 0.95, 0.95, 1.);
		
	long i;
    
    if (obj_type < 0 || obj_type >= CONST_MAX_BACH_ELEMENT_TYPES)
        return;
    
	long num_attributes = man->attr_manager->num_attr[obj_type];

	double needed_height = get_inspector_needed_height(man, obj_type, zoom);
	
	man->bach_inspector_items_needed_height = needed_height;

	t_jgraphics *g = jbox_start_layer((t_object *)man->inspector_ui, view, gensym("bach_inspector_items"), rect.width, needed_height);
	double layer_y_pos = 0;
	
	if (g){
		double column0_x = CONST_BACH_INSPECTOR_ITEM_UX_COLUMN0 * zoom;
		double column1_x = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN1_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN1 * zoom);
		double column2_x = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN2_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN2 * zoom);
		double column2b_x = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN2b_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN2b * zoom);
		
		if (needed_height < real_height) {
			layer_y_pos = CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom;
			man->bach_inspector_scrollbar_delta_y = 0; 
			man->bach_inspector_show_scrollbar = 0;
		} else {
			layer_y_pos = CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom - man->bach_inspector_scrollbar_pos * (needed_height - real_height);
			man->bach_inspector_scrollbar_delta_y = man->bach_inspector_scrollbar_pos * (needed_height - real_height);
			man->bach_inspector_show_scrollbar = 1;
		}

		for (i = 0, ypos = 0; i < num_attributes; i++, ypos += ystep) {
			char *content_txt = NULL;
			t_bach_attribute *attr = &man->attr_manager->attr[obj_type][i];
			char inactive = bach_inactive(man, obj, attr);
			
			if (i % 2)
				paint_filledrectangle(g, build_jrgba(0.98, 0.98, 0.98, 1.), 0, ypos, rect.width, ystep);

			if (i < num_attributes - 1)
				paint_dashed_x_line(g, build_jrgba(0.92, 0.92, 0.92, 1), 2, rect.width - 2, ypos + ystep - 1, 1., 2.);

			write_text(g, jf_label, inactive ? inactive_color : label_color, attr->displayed_label, column0_x, ypos, column1_x - column0_x, ystep, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
			write_text(g, jf_attrname, inactive ? inactive_color : attrname_color, attr->name->s_name, column1_x, ypos, column2_x - column1_x, ystep, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
			
			if (man->inspector_ui->edited_attribute == attr)
				continue;
			
			if (attr->display_type == k_BACH_ATTR_DISPLAY_TEXT) {
				content_txt = get_bach_attribute_as_string(man, obj, attr);
				write_text(g, jf_text, inactive ? inactive_color : text_color, content_txt, column2_x, ypos, rect.width - column2_x, ystep, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);

			} else if (attr->display_type == k_BACH_ATTR_DISPLAY_ENUMINDEX) {
				long num = 0;
				long ac = 0; 
				t_atom *av = NULL;
				t_symbol *sym;

				bach_get_attr(man, obj, attr, &ac, &av);
				if (ac && av) {
					num = atom_getlong(av);
					bach_freeptr(av);
				}
				num = CLAMP(num, 0, attr->num_enum_index_elems-1);
				
				sym = attr->enum_index[num];
				
				if (!sym)
				  sym = _llllobj_sym_empty_symbol;
				
				content_txt = (char *)bach_newptr((strlen(sym->s_name) + 1) * sizeof(char));
				strcpy(content_txt, sym->s_name);

				// display enumindex
				paint_rectangle_rounded(g, inactive ? inactive_color : umenu_color, umenu_bg_color, column2_x - 2, ypos - 1 + step_vpad_before_text, (column2b_x + 15 * zoom) - column2_x + 2, row_vheight + 2, 1.5, 5 * zoom, 4 * zoom);
				write_text(g, jf_text, inactive ? inactive_color : text_color_no_correction, content_txt, column2_x, ypos + step_vpad_before_text, column2b_x - column2_x, row_vheight, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
				
				// triangle
				jgraphics_set_source_jrgba(g, &umenu_color);
				jgraphics_set_line_width(g, 0.);
				jgraphics_move_to(g, column2b_x + 2 * zoom, ypos + step_vpad_before_text + 4 * zoom);
				jgraphics_line_to(g, column2b_x + 10 * zoom, ypos + step_vpad_before_text + 4 * zoom);
				jgraphics_line_to(g, column2b_x + 6 * zoom, ypos + ystep - 5 * zoom);
				jgraphics_close_path(g); 
				jgraphics_fill(g);
				
			} else if (attr->display_type == k_BACH_ATTR_DISPLAY_CHAR) {
				content_txt = get_bach_attribute_as_character(man, obj, &man->attr_manager->attr[obj_type][i]);
				write_text(g, jf_text, inactive ? inactive_color : text_color, content_txt, column2_x, ypos + step_vpad_before_text, rect.width - column2_x, row_vheight, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
			
			} else if (attr->display_type == k_BACH_ATTR_DISPLAY_ONOFF) {
				paint_strokenrectangle(g, inactive ? inactive_color : text_color, column2_x, ypos + step_vpad_before_text, row_vheight, row_vheight, 1);
				if (is_attribute_nonzero(obj, attr, man->attr_manager->attr[obj_type][i].attr_type)) {
					paint_line(g, inactive ? inactive_color : text_color, column2_x, ypos + step_vpad_before_text, column2_x + row_vheight, ypos + step_vpad_before_text + row_vheight, 1);
					paint_line(g, inactive ? inactive_color : text_color, column2_x, ypos + step_vpad_before_text + row_vheight, column2_x + row_vheight, ypos + step_vpad_before_text, 1);
				}

			} else if (attr->display_type == k_BACH_ATTR_DISPLAY_COLOR) {
				t_jrgba color = get_bach_attribute_as_color(man, obj, &man->attr_manager->attr[obj_type][i]);
				paint_rectangle_rounded(g, inactive ? inactive_color : get_grey(0.1), color, column2_x - 2, ypos - 2 + step_vpad_before_text, (column2b_x + 15 * zoom) - column2_x + 2, row_vheight + 2, 1.5, 2 * zoom, 2 * zoom);
			}
			
			if (content_txt)
				bach_freeptr(content_txt);
		}

		// last item is...
		char lastline[1000];
		get_bach_inspector_lastline_string(r_ob, man, lastline);
		write_text(g, jf_keyfunctions, label_color, lastline, column0_x, ypos + ystep * 0.3, rect.width - column0_x, 10 * ystep, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, true);
		
		// enumindex? color?
		for (i = 0; i < num_attributes; i++){
			t_bach_attribute *attr = &man->attr_manager->attr[obj_type][i];
			if (attr->display_type == k_BACH_ATTR_DISPLAY_ENUMINDEX && man->active_inspector_enumindex == attr){
				long num_index = attr->num_enum_index_elems;
				double maxwidth = 20 * zoom, thisy;
				double enumindex_step = CONST_BACH_INSPECTOR_ENUMINDEX_UY_STEP * zoom;
				double ypos = CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom * attr->idx;
				long j;
				
				// getting max rectangle width
				for (j = 0; j < num_index; j++) {
					double thisw, thish;
					if (attr->enum_index[j]) {
						jfont_text_measure(jf_text, attr->enum_index[j]->s_name, &thisw, &thish); //attr->enum_index[17]
						if (thisw + 20 * zoom > maxwidth)
							maxwidth = thisw + 20 * zoom;
					}
				}
				
				// painting umenu rectangle
				paint_rectangle(g, umenu_color, umenu_bg_color, column2_x - 2, ypos + ystep + 4, maxwidth, num_index * enumindex_step + 2 * zoom, 1);
				
				// setting active umenu rectangle in the structure
				man->active_inspector_enumindex_rect = build_rect(column2_x, ypos + ystep + 4 + 1 * zoom + layer_y_pos, maxwidth, num_index * enumindex_step);

				for (j = 0, thisy = ypos + ystep + 4 + 1 * zoom; j < num_index; j++, thisy += enumindex_step) {
					if (man->active_inspector_enumindex_mouseover_idx == j)	// mouseover?
						paint_filledrectangle(g, build_jrgba(0.49, 0.69, 0.86, 0.4), column2_x - 1, thisy, maxwidth - 2, enumindex_step);
					write_text(g, jf_text, text_color_no_correction, attr->enum_index[j] ? attr->enum_index[j]->s_name : "", column2_x + 5 * zoom, thisy, rect.width - (column2_x + 5 * zoom), enumindex_step, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
				} 
				
			} else if (attr->display_type == k_BACH_ATTR_DISPLAY_COLOR && man->active_inspector_color == attr) {
				double ypos = CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom * attr->idx + (CONST_BACH_INSPECTOR_ITEM_UY_STEP - CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT) * zoom;
				t_rect palette_rect = build_rect(column2_x - 2, ypos + ystep + 4, 140 * zoom, 70 * zoom);
				t_jrgba color = get_bach_attribute_as_color(man, obj, attr);
				t_jfont *jf_coeff = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(10 * zoom));
				man->active_inspector_color_palette_rect = build_rect(palette_rect.x, palette_rect.y + layer_y_pos, palette_rect.width, palette_rect.height);
				man->active_inspector_color_spectrum_rect = build_rect(column2_x - 2 + 140 * zoom, man->active_inspector_color_palette_rect.y, 20 * zoom, man->active_inspector_color_palette_rect.height);
				paint_colorpalette(r_ob, g, palette_rect, column2_x - 2 + 140 * zoom, 20 * zoom, color, man->active_inspector_top_right_color, true, true, true, true, jf_coeff, get_grey(0), get_grey(0.85), CONST_BACH_INSPECTOR_DEFAULT_ZOOM);
				jfont_destroy_debug(jf_coeff);
			}
		}

		jbox_end_layer((t_object *)r_ob, view, gensym("bach_inspector_items"));
	}

	jbox_paint_layer((t_object *)man->inspector_ui, view, gensym("bach_inspector_items"), 0., layer_y_pos);	// position of the layer
}

// txt MUST be sized CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS
void bach_default_inspector_header_fn(t_notation_obj *r_ob, t_bach_inspector_manager *inspector_manager, void *elem, long elem_type, char *txt)
{
	if (elem_type == k_SLOTINFO) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Slotinfo For Slot %ld", ((t_slotinfo *)elem)->slot_num + 1);
	} else if (elem_type == k_CHORD) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Chord %ld Of Measure %ld Of Voice %ld", chord_get_position(r_ob, (t_chord *)elem), ((t_chord *)elem)->parent->measure_number + 1, ((t_chord *)elem)->parent->voiceparent->v_ob.number + 1);
		else
			snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Chord %ld Of Voice %ld", chord_get_position(r_ob, (t_chord *)elem), ((t_chord *)elem)->voiceparent->v_ob.number + 1);
	} else if (elem_type == k_NOTE) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Note %ld Of Chord %ld Of Measure %ld Of Voice %ld", note_get_position(r_ob, (t_note *)elem), chord_get_position(r_ob, ((t_note *)elem)->parent), ((t_note *)elem)->parent->parent->measure_number + 1, ((t_note *)elem)->parent->parent->voiceparent->v_ob.number + 1);
		else
			snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Note %ld Of Chord %ld Of Voice %ld", note_get_position(r_ob, (t_note *)elem), chord_get_position(r_ob, ((t_note *)elem)->parent), ((t_note *)elem)->parent->voiceparent->v_ob.number + 1);
	} else if (elem_type == k_MEASURE) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Measure %ld Of Voice %ld ", ((t_measure *)elem)->measure_number + 1, ((t_measure *)elem)->voiceparent->v_ob.number + 1);
	} else if (elem_type == k_TEMPO) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Tempo %ld Of Measure %ld Of Voice %ld ", get_tempo_position(r_ob, (t_tempo *)elem), ((t_tempo *)elem)->owner->measure_number + 1, ((t_tempo *)elem)->owner->voiceparent->v_ob.number + 1);
	} else if (elem_type == k_VOICE) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Voice %ld", ((t_voice *)elem)->number + 1);
	} else if (elem_type == k_MARKER) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Marker %ld", get_marker_position(r_ob, ((t_marker *)elem)));
	} else if (elem_type == k_PITCH_BREAKPOINT) {
		if (!((t_bpt *)elem)->next) {
			if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
				snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Tail Of Note %ld Of Chord %ld Of Measure %ld Of Voice %ld", note_get_position(r_ob, ((t_bpt *)elem)->owner), chord_get_position(r_ob, (((t_bpt *)elem)->owner)->parent), (((t_bpt *)elem)->owner)->parent->parent->measure_number + 1, (((t_bpt *)elem)->owner)->parent->parent->voiceparent->v_ob.number + 1);
			else
				snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Tail Of Note %ld Of Chord %ld Of Voice %ld", note_get_position(r_ob, ((t_bpt *)elem)->owner), chord_get_position(r_ob, (((t_bpt *)elem)->owner)->parent), (((t_bpt *)elem)->owner)->parent->voiceparent->v_ob.number + 1);
		} else {
			if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
				snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Pitch Breakpoint %ld Of Note %ld Of Chord %ld Of Measure %ld Of Voice %ld", get_breakpoint_position(r_ob, ((t_bpt *)elem)) - 1, note_get_position(r_ob, ((t_bpt *)elem)->owner), chord_get_position(r_ob, (((t_bpt *)elem)->owner)->parent), (((t_bpt *)elem)->owner)->parent->parent->measure_number + 1, (((t_bpt *)elem)->owner)->parent->parent->voiceparent->v_ob.number + 1);
			else
				snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Pitch Breakpoint %ld Of Note %ld Of Chord %ld Of Voice %ld", get_breakpoint_position(r_ob, ((t_bpt *)elem)) - 1, note_get_position(r_ob, ((t_bpt *)elem)->owner), chord_get_position(r_ob, (((t_bpt *)elem)->owner)->parent), (((t_bpt *)elem)->owner)->parent->voiceparent->v_ob.number + 1);
		}
	} else if (elem_type == k_NONE) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Nothing To Inspect");
	} else if (elem_type == k_MIXED) {
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Mixed Selection");
	} else 
		snprintf_zero(txt, CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS, "Can't Inspect Element");
}

t_jrgba bach_default_inspector_color_fn(void *notation_obj, void *elem, long elem_type){	
	t_jrgba bg_color = build_jrgba(.77, .77, .77, 1); 
	if (elem_type == k_SLOTINFO) 
		bg_color = build_jrgba(.78, .61, .61, 1);
	else if (elem_type == k_CHORD) 
		bg_color = build_jrgba(.59, .73, .61, 1);
	else if (elem_type == k_MEASURE) 
		bg_color = build_jrgba(.59, .63, .73, 1);
	else if (elem_type == k_NOTE) 
		bg_color = build_jrgba(.73, .70, .59, 1);
	else if (elem_type == k_VOICE) 
		bg_color = build_jrgba(.69, .52, .52, 1);
	else if (elem_type == k_TEMPO) 
		bg_color = build_jrgba(.76, .59, .75, 1);
	else if (elem_type == k_MARKER) 
		bg_color = build_jrgba(.71, .69, .53, 1);
	else if (elem_type == k_PITCH_BREAKPOINT) 
		bg_color = build_jrgba(.61, .52, .69, 1);
	else if (elem_type == k_NONE) 
		bg_color = build_jrgba(.77, .77, .77, 1);
	else if (elem_type == k_MIXED) 
		bg_color = build_jrgba(.77, .77, .77, 1);
	return bg_color;
}

t_jsurface *bach_get_icon_surface_fn(t_notation_obj *r_ob, t_bach_inspector_manager *inspector_manager, void *obj, long elem_type)
{
	t_bach_resources *resources = (t_bach_resources *)_llllobj_sym_bachcursors->s_thing;	
	if (resources) {
		switch (elem_type) {
			case k_NOTE: return resources->s_icon_note;
			case k_CHORD: return resources->s_icon_chord;
			case k_MEASURE: return resources->s_icon_measure;
			case k_VOICE: return resources->s_icon_voice;
			case k_TEMPO: return resources->s_icon_tempo;
			case k_MARKER: return resources->s_icon_marker;
			case k_PITCH_BREAKPOINT: return resources->s_icon_pitchbreakpoint;
			case k_MIXED: return resources->s_icon_mixedselection;
			case k_SLOTINFO: return resources->s_icon_slotinfo;
			default: return NULL; 
		}
	}
	return NULL;
}

t_rect bach_chord_miniature_fn(t_notation_obj *r_ob, void *elem, long elem_type, char *show_line){
	t_voice *voice = r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? (t_voice *)((t_chord *)elem)->voiceparent : (t_voice *)((t_chord *)elem)->parent->voiceparent;
	double topmmost_voice_y = get_staff_top_y(r_ob, voice, false);
	double bottommost_voice_y = get_staff_bottom_y(r_ob, voice, false);
	double hh = (bottommost_voice_y - topmmost_voice_y) + 30 * r_ob->zoom_y;
	double ww = 70 * r_ob->zoom_y;
	double xx = ((t_chord *)elem)->stem_x - ww/2.;
	double yy = (topmmost_voice_y + bottommost_voice_y)/2 - hh/2.;
	*show_line = k_INSPECTOR_MINIATURE_SHOW_VERTICAL_LINE;
	return build_rect(xx, yy, ww, hh);
}

t_rect bach_note_miniature_fn(t_notation_obj *r_ob, void *elem, long elem_type, char *show_line){
	double hh = 60 * r_ob->zoom_y;
	double ww = 50 * r_ob->zoom_y;
	double xx = ((t_note *)elem)->center.x - ww/2;
	double yy = ((t_note *)elem)->center.y - hh/2;
	*show_line = k_INSPECTOR_MINIATURE_SHOW_BOTH_LINES;
	return build_rect(xx, yy, ww, hh);
}

t_rect bach_voice_miniature_fn(t_notation_obj *r_ob, void *elem, long elem_type, char *show_line){
	t_voice *voice = (t_voice *)elem;
	double topmmost_voice_y = get_staff_top_y(r_ob, voice, false);
	double bottommost_voice_y = get_staff_bottom_y(r_ob, voice, false);
	double hh = (bottommost_voice_y - topmmost_voice_y) + 30 * r_ob->zoom_y;
	double ww = deltauxpixels_to_deltaxpixels(r_ob, 30 + r_ob->key_signature_uwidth + r_ob->voice_names_uwidth);
	double xx = r_ob->j_inset_x - 8 * r_ob->zoom_y;
	double yy = (topmmost_voice_y + bottommost_voice_y)/2 - hh/2.;
	*show_line = k_INSPECTOR_MINIATURE_NO_LINE;
	return build_rect(xx, yy, ww, hh);
}


void paint_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *view, t_jgraphics* g, t_rect graphic_rect, void *obj, long obj_type, double zoom)
{

	t_jfont *jf_label = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(CONST_BACH_INSPECTOR_TEXT_FONT_SIZE * zoom));
	t_jfont *jf_attrname = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, round(MAX(5, CONST_BACH_INSPECTOR_TEXT_FONT_SIZE - 2) * zoom));
	t_jfont *jf_text = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(CONST_BACH_INSPECTOR_TEXT_FONT_SIZE * zoom));
	t_jfont *jf_slot_number = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, 18. * zoom);
	t_jfont *jf_keyfunctions = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(CONST_BACH_INSPECTOR_TEXT_FONT_SIZE * 0.85 * zoom));

	double column0_x = CONST_BACH_INSPECTOR_ITEM_UX_COLUMN0 * zoom;

	double vscrollbar_width = CONST_BACH_INSPECTOR_VSCROLLBAR_WIDTH * zoom;
	double real_height = graphic_rect.height - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom;

	t_jrgba label_color = CONST_BACH_INSPECTOR_TEXT_COLOR;
	char txt[CONST_BACH_INSPECTOR_MAX_HEADER_NUM_CHARS];
	
	t_jrgba backgroundcolor_noalpha = get_grey(1.);
	
	man->there_is_miniature_in_inspector = false;
	paint_filledrectangle(g, backgroundcolor_noalpha, 0, 0, graphic_rect.width, graphic_rect.height);

	// setting alpha to 1 before painting layers! otherwise we have blending issues
	jgraphics_set_source_rgba(g, 0, 0, 0, 1);
	jbox_invalidate_layer((t_object *)man->inspector_ui, NULL, gensym("bach_inspector_items"));
	paint_bach_inspector_items(r_ob, man, view, graphic_rect, jf_label, jf_attrname, jf_text, jf_keyfunctions, obj, obj_type, zoom, backgroundcolor_noalpha);

	paint_filledrectangle(g, get_grey(0.98), 0, 0, graphic_rect.width, CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom);

	// paint icon
//	t_jsurface *sur = bach_get_icon_surface(r_ob, obj, obj_type);
	t_jsurface *sur = NULL;
    double sur_offset_x = 0;
	if (man->attr_manager->inspector_image) {
		if ((sur = (*man->attr_manager->inspector_image)(r_ob, man, obj, obj_type))) {
            t_rect rect;
            t_jrgba white = get_grey(1);
            if (man->attr_manager->adapt_image) {
                double h = jgraphics_image_surface_get_height(sur);
                double w = jgraphics_image_surface_get_width(sur);
                if (w/h > man->attr_manager->adapt_image_max_ratio)
                    w = h * man->attr_manager->adapt_image_max_ratio;
                if (h/w > man->attr_manager->adapt_image_max_ratio)
                    w = h /man->attr_manager->adapt_image_max_ratio;

                rect = build_rect(column0_x, column0_x, 40 * (w/h) * zoom, 40 * zoom);
                sur_offset_x = rect.width;
                
                paint_rect(g, &rect, NULL, &white, 0, 0);
                jgraphics_image_surface_draw(g, sur, build_rect(0, 0, w, h), rect);
                paint_rect(g, &rect, &label_color, NULL, 1, 0);
            } else {
                rect = build_rect(column0_x, column0_x, 40 * zoom, 40 * zoom);
                sur_offset_x = rect.width;
                
                paint_rect(g, &rect, NULL, &white, 0, 0);
                jgraphics_image_surface_draw(g, sur, build_rect(0, 0, 80, 80), build_rect(column0_x, column0_x, sur_offset_x, sur_offset_x));
                paint_rect(g, &rect, &label_color, NULL, 1, 0);
            }
		}
	}

	// writing header
	if (man->attr_manager->inspector_header)
		(*man->attr_manager->inspector_header)(r_ob, man, obj, obj_type, txt);

/*	if (man->attr_manager->header[obj_type])
		(*man->attr_manager->header[obj_type])(r_ob, obj, obj_type, txt);
	else if (man->bach_managing)
		bach_default_inspector_header_fn(r_ob, obj, obj_type, txt);*/
	
	write_text(g, jf_label, label_color, txt, 2 * column0_x + sur_offset_x, 3 * zoom, graphic_rect.width, CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom - column0_x, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED, true, true);
	
	
//	double hline_y = round_to_semiinteger(CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * 0.86 * zoom);
//	paint_line_fast(g, get_grey(0.), 2 * zoom, hline_y, graphic_rect.width - 2 * zoom, hline_y, 0.5);

	double needed_height = man->bach_inspector_items_needed_height; //(r_ob->m_inspector.attr_manager->num_attr[obj_type] + 0.5) * CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom;
	
	if (needed_height > real_height) {	// scrollbar
		double vscrollbar_bg_width = 13 * zoom;
		double vscrollbar_height = MAX(CONST_BACH_INSPECTOR_VSCROLLBAR_MIN_UHEIGHT * zoom, (real_height - 4 * zoom) * (real_height / needed_height));
		double vscrollbar_top_y = CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom + ((real_height - 4 * zoom) - vscrollbar_height) * man->bach_inspector_scrollbar_pos;
		double right_distance_from_border = CONST_BACH_INSPECTOR_VSCROLLBAR_RIGHT_PAD * zoom;
		double x_innerdash = graphic_rect.width - vscrollbar_width - (vscrollbar_bg_width - vscrollbar_width)/2 - right_distance_from_border + 2 * zoom;
		double length_innerdash = vscrollbar_width - 4 * zoom;
		
		paint_rectangle_rounded(g, build_jrgba(0.5, 0.5, 0.5, 0.1), build_jrgba(1, 1, 1, 0.15), graphic_rect.width - vscrollbar_bg_width - right_distance_from_border, CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom, vscrollbar_bg_width, graphic_rect.height - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom, 0.5, 2, 3);
		paint_rectangle_rounded(g, get_grey(0.2), get_grey(0.8), graphic_rect.width - vscrollbar_width - (vscrollbar_bg_width - vscrollbar_width)/2 - right_distance_from_border, vscrollbar_top_y, vscrollbar_width, vscrollbar_height, 0.5, 2, 3);
		paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2, 0.5);
		paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2 - 2.5 * zoom, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2 - 2.5 * zoom, 0.5);
		paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2 + 2.5 * zoom, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2 + 2.5 * zoom, 0.5);

		man->bach_inspector_scrollbar_height = vscrollbar_height;
		man->bach_inspector_scrollbar_top_y = vscrollbar_top_y;
	}
	
	jfont_destroy_debug(jf_label);
	jfont_destroy_debug(jf_attrname);
	jfont_destroy_debug(jf_text);
	jfont_destroy_debug(jf_slot_number);
	jfont_destroy_debug(jf_keyfunctions);
}


void bach_default_preprocess(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr){
	if (attr->owner_type == k_SLOTINFO) {
		if (attr->name == _llllobj_sym_representation || attr->name == _llllobj_sym_range || attr->name == _llllobj_sym_domain || attr->name == _llllobj_sym_type)
			(*r_ob->whole_obj_undo_tick_function)(r_ob);
		else
			create_header_undo_tick(r_ob, k_HEADER_SLOTINFO);
	} else if (attr->name == _llllobj_sym_name && (attr->owner_type == k_NOTE || attr->owner_type == k_CHORD || attr->owner_type == k_MEASURE)) {
		create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, (e_element_types) attr->owner_type, k_UNDO_MODIFICATION_CHANGE_NAME);
    } else if (attr->name == _llllobj_sym_name && attr->owner_type == k_MARKER) {
        create_header_undo_tick(r_ob, k_HEADER_MARKERS);
	} else if (attr->owner_type == k_PITCH_BREAKPOINT) {
		create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)((t_bpt *)obj)->owner->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
	} else if (attr->owner_type == k_NOTE) {
		if (attr->name == _llllobj_sym_lock || attr->name == _llllobj_sym_mute || attr->name == _llllobj_sym_solo)
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)((t_note *)obj)->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE_FLAG);
		else
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)((t_note *)obj)->parent, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
	} else if (attr->owner_type == k_CHORD) {
		if (attr->name == _llllobj_sym_grace || attr->name == _llllobj_sym_duration)
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)((t_chord *)obj)->parent, k_MEASURE, k_UNDO_MODIFICATION_CHANGE);
		else if (attr->name == _llllobj_sym_lock || attr->name == _llllobj_sym_mute || attr->name == _llllobj_sym_solo)
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, k_CHORD, k_UNDO_MODIFICATION_CHANGE_FLAG);
		else
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, k_CHORD, k_UNDO_MODIFICATION_CHANGE);
	} else if (attr->owner_type == k_MEASURE) {
		if (attr->name == _llllobj_sym_lock || attr->name == _llllobj_sym_mute || attr->name == _llllobj_sym_solo)
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, k_MEASURE, k_UNDO_MODIFICATION_CHANGE_FLAG);
		else if (attr->name == _llllobj_sym_lockwidth || attr->name == _llllobj_sym_width || attr->name == _llllobj_sym_widthfactor) {
			// creating undo tick for all measures in the tuttipoint
			long i;
			t_measure *this_meas;
			t_tuttipoint *tpt = ((t_measure *)obj)->tuttipoint_reference;
			for (i = 0; i < r_ob->num_voices; i++) 
				for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next)
					create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)this_meas, k_MEASURE, k_UNDO_MODIFICATION_CHANGE);
		} else
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, k_MEASURE, k_UNDO_MODIFICATION_CHANGE);
	} else if (attr->owner_type == k_TEMPO) {
		t_tempo *sync_tempi[CONST_MAX_VOICES];
		long i, num_sync_tempi = get_synchronous_tempi(r_ob, (t_tempo *)obj, sync_tempi);
		if (num_sync_tempi > 1 && sync_tempi[0] == (t_tempo *)obj) {
			r_ob->also_changing_in_inspector_all_sync_tempi = true;
			for (i = 0; i < num_sync_tempi; i++) 
				create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)sync_tempi[i]->owner, k_MEASURE, k_UNDO_MODIFICATION_CHANGE);
		} else {
			r_ob->also_changing_in_inspector_all_sync_tempi = false;
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)(((t_tempo *)obj)->owner), k_MEASURE, k_UNDO_MODIFICATION_CHANGE);
		}
	} else if (attr->owner_type == k_VOICE) {
		if (attr->name == _llllobj_sym_lock || attr->name == _llllobj_sym_mute || attr->name == _llllobj_sym_solo)
			create_simple_selected_notation_item_undo_tick(r_ob, (t_notation_item *)obj, k_VOICE, k_UNDO_MODIFICATION_CHANGE_FLAG);
		else if (attr->name == _llllobj_sym_clef)
			create_header_undo_tick(r_ob, k_HEADER_CLEFS);
		else if (attr->name == _llllobj_sym_key || attr->name == _llllobj_sym_mode || attr->name == _llllobj_sym_accpattern)
			create_header_undo_tick(r_ob, k_HEADER_KEYS);
		else if (attr->name == _llllobj_sym_midichannel)
			create_header_undo_tick(r_ob, k_HEADER_MIDICHANNELS);
		else if (attr->name == _llllobj_sym_stafflines)
			create_header_undo_tick(r_ob, k_HEADER_STAFFLINES);
		else
			(*r_ob->whole_obj_undo_tick_function)(r_ob);
	} else if (attr->owner_type == k_MARKER) {
		create_header_undo_tick(r_ob, k_HEADER_MARKERS);
	}
}

void bach_preprocess_attr(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr){
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (attr->preprocess)
		(*attr->preprocess)(man, obj, attr);
	else if (r_ob)
		bach_default_preprocess(r_ob, obj, attr);
}

void bach_default_postprocess(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr){
	if (attr->owner_type == k_SLOTINFO) {
		if (attr->name == _llllobj_sym_domain)
			check_slot_domain(r_ob, ((t_slotinfo *)obj)->slot_num);
		else if (attr->name == _llllobj_sym_range)
			check_slot_range(r_ob, ((t_slotinfo *)obj)->slot_num);
		else if (attr->name == _llllobj_sym_zrange)
			check_slot_zrange(r_ob, ((t_slotinfo *)obj)->slot_num);
		else if (attr->name == _llllobj_sym_representation)
			set_matrix_parameters_from_slotinfo(r_ob, ((t_slotinfo *)obj)->slot_num);
        else if (attr->name == _llllobj_sym_access)
            check_slot_access(r_ob, ((t_slotinfo *)obj)->slot_num);
		else if (attr->name == _llllobj_sym_color) {
			t_atom av[4];
			t_jrgba color = get_bach_attribute_as_color(&r_ob->m_inspector, obj, attr);
			assure_color_goodness(&color);
			atom_setfloat(av, color.red);
			atom_setfloat(av+1, color.green);
			atom_setfloat(av+2, color.blue);
			atom_setfloat(av+3, color.alpha);
			bach_set_attr(&r_ob->m_inspector, obj, attr, 4, av);
		}
	} else if (attr->owner_type == k_CHORD) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
			if (attr->name == _llllobj_sym_duration) {
				recompute_all_for_measure(r_ob, ((t_chord *)obj)->parent, true);
			} else {
				recompute_all_for_measure(r_ob, ((t_chord *)obj)->parent, false);
			}
		} else
			((t_chord *)obj)->need_recompute_parameters = true;
	} else if (attr->owner_type == k_NOTE) {
		if (attr->name == _llllobj_sym_cents) {
            note_set_auto_enharmonicity((t_note *)obj);
			note_compute_approximation(r_ob, (t_note *)obj);
		}
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			recompute_all_for_measure(r_ob, ((t_note *)obj)->parent->parent, false);
		else
			((t_note *)obj)->parent->need_recompute_parameters = true;
	} else if (attr->owner_type == k_MEASURE) {
		if (attr->name == _llllobj_sym_lockrhythmictree)
			recompute_all_for_measure(r_ob, (t_measure *)obj, true);
		else if (attr->name == _llllobj_sym_boxes || attr->name == _llllobj_sym_usecustomboxes) {
			synchronize_boxes_for_measure(r_ob, (t_measure *)obj);
			recompute_all_for_measure(r_ob, (t_measure *)obj, true);
		} else
			recompute_all_for_measure(r_ob, (t_measure *)obj, false);
	} else if (attr->owner_type == k_VOICE) {
		if (attr->name == _llllobj_sym_name) {
			recalculate_voicenames_width(r_ob);
			update_hscrollbar(r_ob, 0);
		}
		implicitely_recalculate_all(r_ob, false);
	} else if (attr->owner_type == k_MARKER) {
		recalculate_marker_name_uwidth(r_ob, (t_marker *)obj);
        recompute_total_length(r_ob);
        update_hscrollbar(r_ob, 0);
	}
	handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_BACH_ATTRIBUTE);
}


void bach_postprocess_attr(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr){
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (attr->postprocess)
		(*attr->postprocess)(man, obj, attr);
	else if (r_ob)
		bach_default_postprocess(r_ob, obj, attr);
    
	if (r_ob && r_ob->m_inspector.attr_manager->miniature[attr->owner_type]) {
		invalidate_notation_static_layer_and_repaint(r_ob);
	}
}

void set_bach_attr_slotinfo_flags(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av) {
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (ac && av && attr->owner_type == k_SLOTINFO) {
		if (attr->name == _llllobj_sym_background)
			change_background_slot_flag(r_ob, ((t_slotinfo *)obj)->slot_num, atom_getlong(av));
		else if (attr->name == _llllobj_sym_popup)
			change_popupmenu_slot_flag(r_ob, ((t_slotinfo *)obj)->slot_num, atom_getlong(av));
		else if (attr->name == _llllobj_sym_rightclick) {
			t_atom newav;
			atom_setlong(&newav, atom_getlong(av) ? ((t_slotinfo *)obj)->slot_num + 1 : 0);
			notation_obj_setattr_rightclickdirectlypopsoutslot(r_ob, NULL, 1, &newav);
		} else if (attr->name == _llllobj_sym_linkto) {
			change_linkto_slot_flag(r_ob, ((t_slotinfo *)obj)->slot_num, atom_getlong(av));
		}
	}
}

long bach_default_attr_inactive(t_notation_obj *r_ob, void *elem, t_bach_attribute *attr){
	if (attr->owner_type == k_CHORD) {
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && (attr->name == _llllobj_sym_mute || attr->name == _llllobj_sym_solo)) {
			if (((t_chord *)elem)->r_sym_duration.r_num < 0)
				return 1;	// inactive
		}
	} else if (attr->owner_type == k_PITCH_BREAKPOINT) {
		if (attr->name == _llllobj_sym_position && !((t_bpt *)elem)->next) {
			return 1;	// it's a note tail: the position has always to be 1.
		} else if (attr->name == _llllobj_sym_velocity && !r_ob->breakpoints_have_velocity) {
			return 1;
		}
	} else if (attr->owner_type == k_MARKER) {
		if (attr->name == _llllobj_sym_value) {
			if (((t_marker *)elem)->role != k_MARKER_ROLE_TEMPO && ((t_marker *)elem)->role != k_MARKER_ROLE_TIME_SIGNATURE)
				return 1;	// inactive
		}
	} else if (attr->owner_type == k_MEASURE) {
		if (attr->name == _llllobj_sym_number) {
			if (!((t_measure *)elem)->force_measure_number)
				return 1;	// inactive
		} else if (attr->name == _llllobj_sym_width) {
			if (!((t_measure *)elem)->is_spacing_fixed)
				return 1;	// inactive
		} else if (attr->name == _llllobj_sym_widthfactor) {
			if (((t_measure *)elem)->is_spacing_fixed)
				return 1;	// inactive
		} else if (attr->name == _llllobj_sym_boxes) {
			if (!((t_measure *)elem)->custom_boxing)
				return 1;	// inactive
		}
	} else if (attr->owner_type == k_SLOTINFO) {
		char slot_type = ((t_slotinfo *)elem)->slot_type;
        long slot_access = ((t_slotinfo *)elem)->access_type;
        if (slot_access != k_SLOT_ACCESS_READANDWRITE) {
            if (attr->name == _llllobj_sym_access)
                return 0;
            return 1;
        }
        // slot is writable
		if ((attr->name == _llllobj_sym_domain || attr->name == _llllobj_sym_domainslope) &&
			(slot_type != k_SLOT_TYPE_FUNCTION && slot_type != k_SLOT_TYPE_FILTER && slot_type != k_SLOT_TYPE_DYNFILTER))
			return 1;
		else if ((attr->name == _llllobj_sym_zrange || attr->name == _llllobj_sym_zslope) && slot_type != k_SLOT_TYPE_3DFUNCTION)
			return 1;
		else if (attr->name == _llllobj_sym_ysnap && slot_type != k_SLOT_TYPE_FUNCTION && slot_type != k_SLOT_TYPE_3DFUNCTION)
			return 1;
		else if (attr->name == _llllobj_sym_zsnap && slot_type != k_SLOT_TYPE_3DFUNCTION)
			return 1;
		else if ((attr->name == _llllobj_sym_width || attr->name == _llllobj_sym_height) && r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
			return 1;
		else if (attr->name == _llllobj_sym_height && (slot_type == k_SLOT_TYPE_INTLIST || slot_type == k_SLOT_TYPE_FLOATLIST || slot_type == k_SLOT_TYPE_FILELIST))
			return 1;
		else if (attr->name == _llllobj_sym_default && 
				(slot_type != k_SLOT_TYPE_INT && slot_type != k_SLOT_TYPE_INTLIST && slot_type != k_SLOT_TYPE_INTMATRIX &&
				slot_type != k_SLOT_TYPE_FLOAT && slot_type != k_SLOT_TYPE_FLOATLIST && slot_type != k_SLOT_TYPE_FLOATMATRIX && slot_type != k_SLOT_TYPE_TOGGLEMATRIX))
			return 1;
		else if (attr->name == _llllobj_sym_representation && 
				(slot_type == k_SLOT_TYPE_FILELIST || slot_type == k_SLOT_TYPE_TEXT || slot_type == k_SLOT_TYPE_LLLL || slot_type == k_SLOT_TYPE_NONE || slot_type == k_SLOT_TYPE_COLOR || slot_type == k_SLOT_TYPE_ARTICULATIONS || slot_type == k_SLOT_TYPE_NOTEHEAD || slot_type == k_SLOT_TYPE_DYNAMICS))
			return 1;
        else if (attr->name == _sym_grid && (slot_type != k_SLOT_TYPE_FUNCTION))
            return 1;
		else if ((attr->name == _llllobj_sym_range || attr->name == _llllobj_sym_slope) &&
				(slot_type == k_SLOT_TYPE_FILELIST || slot_type == k_SLOT_TYPE_TEXT || slot_type == k_SLOT_TYPE_LLLL || slot_type == k_SLOT_TYPE_NONE || slot_type == k_SLOT_TYPE_COLOR || slot_type == k_SLOT_TYPE_TOGGLEMATRIX || slot_type == k_SLOT_TYPE_ARTICULATIONS || slot_type == k_SLOT_TYPE_NOTEHEAD || slot_type == k_SLOT_TYPE_DYNAMICS))
			return 1;
	} else if (attr->owner_type == k_VOICE) {
/*		if (attr->name == _llllobj_sym_accpattern && ((t_voice *)elem)->mode != k_MODE_NONSTANDARD)
			return 1;*/
	}
	return 0;	// active
}


void bach_default_set_bach_attr(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr, long ac, t_atom *av)
{
	long i;
	void *field = (char *) obj + attr->field_position;
//	t_atom none_atom;

	if (!ac || !av) {
		if (attr->name == _llllobj_sym_name || attr->name == _llllobj_sym_representation || attr->name == _sym_grid ||
			attr->name == _llllobj_sym_ysnap || attr->name == _llllobj_sym_zsnap) {
			ac = 0;
			av = NULL;
		} else
			return;
	}
		
	if (attr->owner_type == k_SLOTINFO) {
		long slotnum = ((t_slotinfo *)obj)->slot_num;
		if ((attr->name == _llllobj_sym_slope || attr->name == _llllobj_sym_domainslope)) {
			clip_atom(av, -1, 1);
		} else if (attr->name == _llllobj_sym_default) {
			clip_atom(av, r_ob->slotinfo[slotnum].slot_range[0], r_ob->slotinfo[slotnum].slot_range[1]);
		} else if (attr->name == _llllobj_sym_type) {
			t_llll *slots_to_erase = llll_get();
			change_slot_type(r_ob, slotnum, slot_type_to_symbol((e_slot_types)atom_getlong(av)), slots_to_erase);
			notationobj_erase_slots_from_llll(r_ob, slots_to_erase);
			llll_free(slots_to_erase);
		} else if (attr->name == _llllobj_sym_width || attr->name == _llllobj_sym_height) {
			if (atom_gettype(av) == A_SYM)
				atom_setfloat(av, -1.);
		}
	} else if (attr->owner_type == k_CHORD) {
		if (attr->name == _llllobj_sym_onset) {
			atom_max(av, 0);
		} else if (attr->name == _llllobj_sym_duration && r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			*((t_rational *)field) = (parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom) ? (hatom_gettype(&parsed->l_head->l_hatom) == H_DOUBLE ? approx_double_with_rat_fixed_den(hatom_getdouble(&parsed->l_head->l_hatom), CONST_RAT_APPROX_TEMPI_DEN, 0, NULL) : hatom_getrational(&parsed->l_head->l_hatom) ) : long2rat(0));
			if (rat_rat_cmp(rat_abs(*((t_rational *)field)), CONST_MIN_SYM_DURATION_FOR_CHORD) < 0) {
				*((t_rational *)field) = CONST_MIN_SYM_DURATION_FOR_CHORD;
				object_warn((t_object *) r_ob, "Warning: trying to create too small chords!");
				return;
			}
			llll_free(parsed);
			return;
		}
	} else if (attr->owner_type == k_PITCH_BREAKPOINT) {
		t_bpt *bpt = (t_bpt *)obj;
		if (attr->name == _llllobj_sym_position || attr->name == _llllobj_sym_onset) {
			double position = 0.;
			double onset = 0;
			if (attr->name == _llllobj_sym_onset) {
				onset = atom_getfloat(av);
				if (bpt->owner->duration == 0) {
					object_warn((t_object *) r_ob, "Warning: can't have breakpoint if note duration is 0!");
					return;
				}
				position = (onset - bpt->owner->parent->onset)/bpt->owner->duration;
			} else {
				position = atom_getfloat(av);
			}
			double prev_position = bpt->prev ? bpt->prev->rel_x_pos : 0.;
			double next_position = bpt->next ? bpt->next->rel_x_pos : 1.;
			char error = false;
			if (!bpt->next && attr->name == _llllobj_sym_onset) {
				if (position <= prev_position) 
					error = true;
				else {
					trim_note_end(r_ob, bpt->owner, onset - (bpt->owner->parent->onset + bpt->owner->duration));
					return;
				}
			} else {
				if (position <= prev_position || position >= next_position) 
					error = true;
			}

			if (error) {
				object_warn((t_object *) r_ob, "Warning: breakpoints can't cross or overlap!");
				return;
			} 
			
			bpt->rel_x_pos = position;
			return;
        } else if (attr->name == _llllobj_sym_velocity) {
            clip_atom(av, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
		} else if (attr->name == _llllobj_sym_slope) {
			clip_atom(av, -1., 1.);
		} else if (attr->name == _llllobj_sym_cents) {
			double cents = atom_getfloat(av);
			bpt->delta_mc = cents - bpt->owner->midicents;
			return;
		}
	} else if (attr->owner_type == k_NOTE) {
		if (attr->name == _llllobj_sym_duration) {
			atom_max(av, 0);
		} else if (attr->name == _llllobj_sym_cents) {
			clip_atom(av, 0, CONST_MAX_CENTS);
		} else if (attr->name == _llllobj_sym_velocity) {
			clip_atom(av, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
		} else if (attr->name == _llllobj_sym_tie) {
			t_measure *meas = ((t_note *)obj)->parent->parent;
			((t_note *)obj)->tie_to = atom_getobj(av) ? (t_note *) WHITENULL : NULL;
			meas->need_check_ties = true;
			set_need_perform_analysis_and_change_flag(r_ob);
			return;
		} else if (attr->name == _llllobj_sym_pitch) {
			if (ac && atom_gettype(av) == A_SYM) {
                t_llll *ll = llll_parse(ac, av);
                if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_PITCH)
                    note_set_pitch(r_ob, (t_note *)obj, hatom_getpitch(&ll->l_head->l_hatom));
//				note_set_pitch_from_notename(r_ob, (t_note *)obj, atom_getsym(av), true);
                llll_free(ll);
            }
			return;
		}
	} else if (attr->owner_type == k_MEASURE) {
		if (attr->name == _llllobj_sym_timesig) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			((t_measure *)obj)->timesignature = get_timesignature_from_llll((t_object *)r_ob, parsed);
			compute_utf_timesignature(r_ob, &((t_measure *)obj)->timesignature);
			synchronize_boxes_for_measure(r_ob, (t_measure *)obj);
			llll_free(parsed);
			return;
		} else if (attr->name == _llllobj_sym_usecustomnumber) {
			if (ac && av && atom_gettype(av) == A_LONG && atom_getlong(av)) {
				((t_measure *)obj)->forced_measure_number = ((t_measure *)obj)->measure_number + 1; // beware: forced_measure_number is 1-based, whereas measure_number is 0-based
				((t_measure *)obj)->force_measure_number = true;
			} else
				((t_measure *)obj)->force_measure_number = false;
			return;
		} else if (attr->name == _llllobj_sym_number) {
			if (ac && av && atom_gettype(av) == A_LONG) 
				((t_measure *)obj)->forced_measure_number = atom_getlong(av);
			return;
		} else if (attr->name == _llllobj_sym_barline) {
			if (ac && av && atom_gettype(av) == A_LONG) {
			char barline_type_as_char = 'a'; // automatic, default
				switch (atom_getlong(av)) {
					case 0:
						barline_type_as_char = k_BARLINE_AUTOMATIC;
						break;
					case 1:
						barline_type_as_char = k_BARLINE_NORMAL;
						break;
					case 2:
						barline_type_as_char = k_BARLINE_DASHED;
						break;
					case 3:
						barline_type_as_char = k_BARLINE_POINTS;
						break;
					case 4:
						barline_type_as_char = k_BARLINE_DOUBLE;
						break;
					case 5:
						barline_type_as_char = k_BARLINE_FINAL;
						break;
					case 6:
						barline_type_as_char = k_BARLINE_HIDDEN;
						break;
					case 7:
						barline_type_as_char = k_BARLINE_SOLID;
						break;
					default:
						barline_type_as_char = k_BARLINE_AUTOMATIC;
						break;
				}
				((t_measure *)obj)->end_barline->barline_type = barline_type_as_char;
				recompute_all_for_measure(r_ob, (t_measure *)obj, false);
			}
			return;
		} else if (attr->name == _llllobj_sym_lockwidth) {
			if (ac && av && atom_gettype(av) == A_LONG && atom_getlong(av)) {
				assign_local_spacing_width_multiplier(r_ob, ((t_measure *)obj)->tuttipoint_reference, 1.);
				assign_fixed_spacing_uwidth(r_ob, ((t_measure *)obj)->tuttipoint_reference, ((t_measure *)obj)->tuttipoint_reference->width_ux);
			} else
				remove_fixed_spacing_uwidth(r_ob, ((t_measure *)obj)->tuttipoint_reference);
			return;
		} else if (attr->name == _llllobj_sym_width) {
			double w = ac && av && is_atom_number(av) ? ((t_measure *)obj)->tuttipoint_reference->width_ux + atom_getfloat(av) - ((t_measure *)obj)->width_ux : ((t_measure *)obj)->tuttipoint_reference->width_ux;
			assign_local_spacing_width_multiplier(r_ob, ((t_measure *)obj)->tuttipoint_reference, 1.);
			assign_fixed_spacing_uwidth(r_ob, ((t_measure *)obj)->tuttipoint_reference, w);
			if (ac && av && is_atom_number(av))
				((t_measure *)obj)->width_ux = atom_getfloat(av);	// we set it also directly because so the inspector is immediately redrawn with the correct value
																	// otherwise we'll have to wait for the paint method to perform_analysis_and_change
			// KNOWN BUG: it doesn't work very well for nonstard tuttipoints
			return;
		} else if (attr->name == _llllobj_sym_widthfactor) {
			if (ac && av && is_atom_number(av))
				assign_local_spacing_width_multiplier(r_ob, ((t_measure *)obj)->tuttipoint_reference, MAX(0., atom_getfloat(av)));
			return;
		}
	} else if (attr->owner_type == k_TEMPO) {
		if (attr->name == _llllobj_sym_onset) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			t_tempo *tempo = (t_tempo *)obj;
			t_rational r_onset = (parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom) ? hatom_getrational(&parsed->l_head->l_hatom) : long2rat(0));
			
			llll_free(parsed);

			if ((tempo->prev && rat_rat_cmp(r_onset, tempo->prev->changepoint) < 0) || 
				(tempo->next &&  rat_rat_cmp(r_onset, tempo->next->changepoint) > 0) ||
				 rat_rat_cmp(r_onset, measure_get_sym_duration(tempo->owner)) >= 0) {
				object_warn((t_object *)r_ob, "Can't move the tempo: there's another tempo in between.");
				return; // we don't set anything
			} else if (tempo->prev && rat_rat_cmp(r_onset, tempo->prev->changepoint) == 0) 
				delete_tempo(r_ob, tempo->prev);
			else if (tempo->next && rat_rat_cmp(r_onset, tempo->next->changepoint) == 0) 
				delete_tempo(r_ob, tempo->next);
			
			if (r_onset.r_num < 0) {
				*((t_rational *)field) = long2rat(0);
				return;
			}
			
		} else if (attr->name == _llllobj_sym_tempo && r_ob->also_changing_in_inspector_all_sync_tempi) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			t_rational tempo = (parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom) ? (hatom_gettype(&parsed->l_head->l_hatom) == H_DOUBLE ? approx_double_with_rat_fixed_den(hatom_getdouble(&parsed->l_head->l_hatom), CONST_RAT_APPROX_TEMPI_DEN, 0, NULL) : hatom_getrational(&parsed->l_head->l_hatom) ) : long2rat(0));
			t_tempo *sync_tempi[CONST_MAX_VOICES];
			long num_sync_tempi = get_synchronous_tempi(r_ob, (t_tempo *)obj, sync_tempi);
			for (i = 0; i < num_sync_tempi; i++) 
				sync_tempi[i]->figure_tempo_value = tempo;
			llll_free(parsed);
			return;
		} else if (attr->name == _llllobj_sym_figure && r_ob->also_changing_in_inspector_all_sync_tempi) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			t_rational figure = (parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom) ? (hatom_gettype(&parsed->l_head->l_hatom) == H_DOUBLE ? approx_double_with_rat_fixed_den(hatom_getdouble(&parsed->l_head->l_hatom), CONST_RAT_APPROX_TEMPI_DEN, 0, NULL) : hatom_getrational(&parsed->l_head->l_hatom) ) : RAT_1OVER4);
			t_tempo *sync_tempi[CONST_MAX_VOICES];
			long num_sync_tempi = get_synchronous_tempi(r_ob, (t_tempo *)obj, sync_tempi);
			for (i = 0; i < num_sync_tempi; i++) 
				sync_tempi[i]->tempo_figure = figure;
			llll_free(parsed);
			return;
		}
	} else if (attr->owner_type == k_VOICE){
		if (attr->name == _llllobj_sym_midichannel) {
			change_single_midichannel(r_ob, (t_voice *)obj, atom_getlong(av), true);
			return;
		} else if (attr->name == _llllobj_sym_clef) {
			change_single_clef(r_ob, (t_voice *)obj, inspector_umenu_index_to_clef(r_ob, atom_getlong(av)), true);
			return;
		} else if (attr->name == _llllobj_sym_key) {
			change_single_key(r_ob, (t_voice *)obj, ac_av_to_single_symbol(ac, av), true);
			return;
		} else if (attr->name == _llllobj_sym_name) {
			change_single_voicename_from_ac_av(r_ob, (t_voice *)obj, ac, av, true);
			return;
		} else if (attr->name == _llllobj_sym_stafflines) {
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			set_stafflines_to_voice_from_llllelem(r_ob, (t_voice *)obj, parsed->l_head, false, NULL);
			// synchronizing the llll attribute
			llll_free(r_ob->stafflines_as_llll);
			r_ob->stafflines_as_llll = get_stafflines_as_llll(r_ob, false);
			llll_free(parsed);
			return;
		}
	}

	switch (attr->attr_type) {
		case k_BACH_ATTR_CHAR:
            if (attr->display_type == k_BACH_ATTR_DISPLAY_CHAR) {
                *((char *)field) = (ac ? ((int)atom_getsym(av)->s_name[0] > 0 ? atom_getsym(av)->s_name[0] : 0) : 0);
            } else
				*((char *)field) = (ac ? atom_getlong(av) : 0);
			break;
		case k_BACH_ATTR_LONG:
			*((long *)field) = (ac ? atom_getlong(av) : 0);
			break;
		case k_BACH_ATTR_RAT:
		{
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			*((t_rational *)field) = (parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom) ? (hatom_gettype(&parsed->l_head->l_hatom) == H_DOUBLE ? approx_double_with_rat_fixed_den(hatom_getdouble(&parsed->l_head->l_hatom), CONST_RAT_APPROX_TEMPI_DEN, 0, NULL) : hatom_getrational(&parsed->l_head->l_hatom) ) : long2rat(0));
			llll_free(parsed);
			break;
		}
		case k_BACH_ATTR_COLOR:
			*((t_jrgba *)field) = (ac >= 3 ? build_jrgba(atom_getfloat(av), atom_getfloat(av+1), atom_getfloat(av+2), ac >= 4 ? atom_getfloat(av+3) : 1.) : build_jrgba(0, 0, 0, 1));
			break;
		case k_BACH_ATTR_DOUBLE:
			*((double *)field) = (ac ? atom_getfloat(av) : 0);
			break;
		case k_BACH_ATTR_SYM:
			*((t_symbol **)field) = (ac == 1 && atom_gettype(av) == A_SYM ? atom_getsym(av) : (ac ? ac_av_to_single_symbol(ac, av) : _llllobj_sym_empty_symbol));
			break;
		case k_BACH_ATTR_ATOM:
			*((t_atom *)field) = *av;
			break;
		case k_BACH_ATTR_LONG_ARRAY:
			for (i = 0; i < attr->attr_size && i < ac; i++)
				((long *)field)[i] = atom_getlong(av+i);
			break;
		case k_BACH_ATTR_RAT_ARRAY:
		{
			t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			t_llllelem *elem;
			for (i = 0, elem = parsed->l_head; i < attr->attr_size && i < ac && elem; i++, elem = elem->l_next)
				if (is_hatom_number(&elem->l_hatom))
					((t_rational *)field)[i] = hatom_getrational(&elem->l_hatom);
			llll_free(parsed);
			break;
		}
		case k_BACH_ATTR_DOUBLE_ARRAY:
			for (i = 0; i < attr->attr_size && i < ac; i++)
				((double *)field)[i] = atom_getfloat(av+i);
			break;
		case k_BACH_ATTR_ATOM_ARRAY:
			for (i = 0; i < attr->attr_size && i < ac; i++)
				((t_atom *)field)[i] = av[i];
			break;
		case k_BACH_ATTR_ATOM_ARRAY_VARSIZE:
			for (i = 0; i < attr->attr_size && i < ac; i++)
				((t_atom *)field)[i] = av[i];
			*((long *)((char *) obj + attr->field_position_for_var_attr_size)) = ac;
			break;
		case k_BACH_ATTR_LLLL:
			if (*((t_llll **)field))
				llll_free(*((t_llll **)field));
			*((t_llll **)field) = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
			break;
		case k_BACH_ATTR_OBJ:
			//there's no default for this case! handle each case separately
			break;
		default:
			break;
	}
}

long bach_inactive(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (attr->inactive)
		return ((*attr->inactive)(man, obj, attr));
	else 
		return bach_default_attr_inactive(r_ob, obj, attr);
}


void bach_set_attr(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (attr->setter)
		((*attr->setter)(man, obj, attr, ac, av));
	else 
		bach_default_set_bach_attr(r_ob, obj, attr, ac, av);
}

// like atom_setparse, will allocate memory if ac and av are NULL, otherwise will attempt to use the indicated memory // (t_note *)obj
void bach_default_get_bach_attr(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr, long *ac, t_atom **av)
{
	void *field = (char *) obj + attr->field_position;
	long size;
	char *string;
	
	if (attr->owner_type == k_SLOTINFO) {
		if (attr->name == _llllobj_sym_width) {
			if (attr->attr_type == k_BACH_ATTR_DOUBLE && *((double *)field) < 0) {
				*ac = 1;
				*av = (t_atom *)bach_newptr(sizeof(t_atom));
				atom_setsym(*av, _llllobj_sym_temporal);
				return;
			}
		} else if (attr->name == _llllobj_sym_height) {
			if (attr->attr_type == k_BACH_ATTR_DOUBLE && *((double *)field) < 0) {
				*ac = 1;
				*av = (t_atom *)bach_newptr(sizeof(t_atom));
				atom_setsym(*av, _llllobj_sym_auto);
				return;
			}
		}
	} else if (attr->owner_type == k_PITCH_BREAKPOINT) {
		if (attr->name == _llllobj_sym_onset) {
			t_bpt *bpt = (t_bpt *)obj;
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setfloat(*av, bpt->rel_x_pos * bpt->owner->duration + bpt->owner->parent->onset);
			return;
		} else if (attr->name == _llllobj_sym_cents) {
			t_bpt *bpt = (t_bpt *)obj;
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setfloat(*av, bpt->delta_mc + bpt->owner->midicents);
			return;
		}
	} else if (attr->owner_type == k_TEMPO) {
		if (attr->name == _llllobj_sym_tempo && attr->attr_type == k_BACH_ATTR_RAT) {
			t_rational val = (*((t_rational *)field));
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			if (val.r_den == 1)
				atom_setlong(*av, val.r_num);
			else
				atom_setfloat(*av, rat2double(val));
			return;
		}
	} else if (attr->owner_type == k_NOTE) {
		if (attr->name == _llllobj_sym_tie && attr->attr_type == k_BACH_ATTR_OBJ) {
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setobj(*av, ((t_note *)obj)->tie_to);
			return;
		} else if (attr->name == _llllobj_sym_pitch) {
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
            t_pitch pitch = note_get_pitch(r_ob, (t_note *)obj);
			atom_setsym(*av, pitch.toSym());
			return;
		}
	} else if (attr->owner_type == k_MEASURE) {
		if (attr->name == _llllobj_sym_timesig) {
			t_llll *ll = get_timesignature_as_llll(&((t_measure *)obj)->timesignature);
			*ac = llll_deparse(ll, av, 0, 0);
			llll_free(ll);
			return;
		} else if (attr->name == _llllobj_sym_barline) {
			long idx = 0;
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			switch (((t_measure *)obj)->end_barline->barline_type) {
				case k_BARLINE_AUTOMATIC:
					idx = 0;
					break;
				case k_BARLINE_NORMAL:
					idx = 1;
					break;
				case k_BARLINE_DASHED:
					idx = 2;
					break;
				case k_BARLINE_POINTS:
					idx = 3;
					break;
				case k_BARLINE_DOUBLE:
					idx = 4;
					break;
				case k_BARLINE_FINAL:
					idx = 5;
					break;
				case k_BARLINE_HIDDEN:
					idx = 6;
					break;
				case k_BARLINE_SOLID:
					idx = 7;
					break;
				default:
					idx = 0;
					break;
			}
			atom_setlong(*av, idx);
			return;
		} else if (attr->name == _llllobj_sym_number) {
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			// beware: forced_measure_number is 1-based, whereas measure_number is 0-based
			atom_setlong(*av, ((t_measure *)obj)->force_measure_number ? ((t_measure *)obj)->forced_measure_number : ((t_measure *)obj)->measure_number + 1);
			return;
		}
	} else if (attr->owner_type == k_VOICE) {
		if (attr->name == _llllobj_sym_clef) {
			long clef = (*((long *)field));
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setlong(*av, clef_to_inspector_umenu_index(r_ob, clef));
			return;
		} else if (attr->name == _llllobj_sym_mode) {
			char mode = (*((char *)field));
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setlong(*av, mode == k_MODE_MAJOR ? 0 : (mode == k_MODE_MINOR ? 1 : 2));
			return;
		} else if (attr->name == _llllobj_sym_key) {
			*ac = 1;
			*av = (t_atom *)bach_newptr(sizeof(t_atom));
			atom_setsym(*av, r_ob->keys_as_symlist[((t_voice *)obj)->number]);

			return;
		} else if (attr->name == _llllobj_sym_stafflines) {
			t_voice *voice = (t_voice *)obj;
			if (voice->are_staff_lines_standard) {
				*ac = 1;
				*av = (t_atom *)bach_newptr(sizeof(t_atom));
				atom_setlong(*av, voice->num_staff_lines);
			} else {
				char *string = char_array_to_string(voice->staff_lines, voice->num_staff_lines, true);
				t_llll *ll = llll_from_text_buf(string, false);
				*ac = llll_deparse(ll, av, 0, 0);
				bach_freeptr(string);
				llll_free(ll);
			}
			return;
			
		}
	}
	
	size = attr->attr_type == k_BACH_ATTR_ATOM_ARRAY_VARSIZE ? *((long *)((char *) obj + attr->field_position_for_var_attr_size)) : attr->attr_size;
	string = field2string(field, attr->attr_type, size, -1); // all decimals, we'll trim them later
	atom_setparse_debug(ac, av, string);
	bach_freeptr(string);
}

// like atom_setparse, will allocate memory if ac and av are NULL, otherwise will attempt to use the indicated memory
void bach_get_attr(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long *ac, t_atom **av)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (attr->getter)
		((*attr->getter)(man, obj, attr, ac, av));
	else 
		bach_default_get_bach_attr(r_ob, obj, attr, ac, av);
}

// preprocess > setattr > process
void set_bach_attr_and_process_from_ac_av(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av, char force_undo_step)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob)
        r_ob->also_changing_in_inspector_all_sync_tempi = false;
	bach_preprocess_attr(man, obj, attr);
	if (force_undo_step && r_ob)
		handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_BACH_ATTRIBUTE);
	bach_set_attr(man, obj, attr, ac, av);
    if (r_ob)
        remove_all_free_undo_ticks(r_ob, true); // because while setting the attribute we might have also created some ticks... which we don't want! :-)
            // daniele 2016/12/13: this seems to work fine, but I don't really remember why any longer ;-)
	bach_postprocess_attr(man, obj, attr);
}

void end_editing_bach_inspector_ui_textfield(t_bach_inspector_ui *insp){
	t_object *textfield = jbox_get_textfield((t_object *) insp); 
	insp->edited_attribute = NULL;
	object_method(textfield, _sym_settext, "");
	object_attr_setlong(insp, _sym_fontface, 0);
}

void bach_inspector_enter(t_notation_obj *r_ob, t_bach_inspector_manager *man) // we've ended changing an attribute
{
	t_bach_attribute *attr = man->inspector_ui ? man->inspector_ui->edited_attribute : man->is_editing_attribute;
	void *obj = man->active_bach_inspector_item;
	long size = 0;
	char *text = NULL;
	t_object *textfield = jbox_get_textfield(man->inspector_ui ? (t_object *)man->inspector_ui : (t_object *)r_ob);
	
	if (!textfield)
		return;
	
	object_method(textfield, gensym("gettextptr"), &text, &size);
	
    if (attr && text) {
		t_atom *av = NULL;
		long ac = 0;
		atom_setparse_debug(&ac, &av, text);

		set_bach_attr_and_process_from_ac_av(man, obj, attr, ac, av, true);
		
		bach_freeptr(av);
	}
	
	if (man->inspector_ui)
		end_editing_bach_inspector_ui_textfield(man->inspector_ui);
	else if (r_ob)
		end_editing_textfield(r_ob);
}

void close_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man)
{
	if (r_ob && r_ob->is_editing_type == k_BACH_INSPECTOR_ITEM)
		bach_inspector_enter(r_ob, man);
		
	man->active_inspector_enumindex = NULL;
	man->active_inspector_enumindex_mouseover_idx = -1;
	man->active_inspector_color = NULL;
	man->active_bach_inspector_obj_type = k_NONE;
	man->active_bach_inspector_item = NULL;
		
    if (r_ob) {
        recompute_total_length(r_ob);
        invalidate_notation_static_layer_and_repaint(r_ob);
    }
}



long handle_mousewheel_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_pt pt, double x_inc, double y_inc)
{
	if (man->active_bach_inspector_item) {
        if (pt.y >= CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * (r_ob ? r_ob->zoom_y : 1)) {
			man->bach_inspector_scrollbar_pos -= y_inc/5;
			clip_double(&man->bach_inspector_scrollbar_pos, 0, 1);
			if (r_ob) invalidate_notation_static_layer_and_repaint(r_ob);
			jbox_redraw((t_jbox *)man->inspector_ui);
			return 1;
		}
	}
	return 0;
}	


long handle_doubleclick_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_pt pt)
{
	if (man->active_bach_inspector_item) {
		t_bach_attribute *attr = pt_to_attribute_to_edit(man, patcherview, pt);
		if (attr && (attr->display_type == k_BACH_ATTR_DISPLAY_CHAR || attr->display_type == k_BACH_ATTR_DISPLAY_TEXT) && !bach_inactive(man, man->active_bach_inspector_item, attr)) {
			start_editing_bach_attribute(r_ob, man, patcherview, attr);
			return 1;
		}
	}
	return 0;
}	


long handle_mousemove_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_pt pt)
{
	if (man->active_bach_inspector_item) {
		if (man->active_inspector_enumindex) {
			if (pt.y > man->active_inspector_enumindex_rect.y && pt.y < man->active_inspector_enumindex_rect.y + man->active_inspector_enumindex_rect.height &&
				pt.x > man->active_inspector_enumindex_rect.x && pt.x < man->active_inspector_enumindex_rect.x + man->active_inspector_enumindex_rect.width) {
				double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM;
				man->active_inspector_enumindex_mouseover_idx = CLAMP(floor((pt.y - man->active_inspector_enumindex_rect.y) / (CONST_BACH_INSPECTOR_ENUMINDEX_UY_STEP * zoom)), 0, man->active_inspector_enumindex->num_enum_index_elems - 1);
			} else {
				man->active_inspector_enumindex_mouseover_idx = -1;
			}
			if ((t_jbox *)man->inspector_ui)
				jbox_redraw((t_jbox *)man->inspector_ui);
			else 
				invalidate_notation_static_layer_and_repaint(r_ob);
		}
	}
	return 0;
}


long handle_mousedown_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_rect rect, t_pt pt, long modifiers)
{
	double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM;
	if (man->inspector_ui) {
//		r_ob->inspector_ui->dragging_y = pt.y;
		man->inspector_ui->floatdragging_y = pt.y;
	}
	
	if (man->active_bach_inspector_item) {
		if (man->bach_inspector_show_scrollbar) {
			if (pt.x > rect.width - (CONST_BACH_INSPECTOR_VSCROLLBAR_RIGHT_PAD + CONST_BACH_INSPECTOR_VSCROLLBAR_WIDTH) * zoom &&
				pt.x < rect.width - CONST_BACH_INSPECTOR_VSCROLLBAR_RIGHT_PAD * zoom && 
				pt.y > man->bach_inspector_scrollbar_top_y &&	pt.y < man->bach_inspector_scrollbar_top_y + man->bach_inspector_scrollbar_height) {
				if (r_ob)
					set_mousedown(r_ob, WHITENULL_llll, k_BACH_INSPECTOR_VSCROLLBAR);
				return 1;
			}
		} 
		
		if (man->active_inspector_enumindex && !bach_inactive(man, man->active_bach_inspector_item, man->active_inspector_enumindex)) {
			if (pt.y > man->active_inspector_enumindex_rect.y && pt.y < man->active_inspector_enumindex_rect.y + man->active_inspector_enumindex_rect.height &&
				pt.x > man->active_inspector_enumindex_rect.x && pt.x < man->active_inspector_enumindex_rect.x + man->active_inspector_enumindex_rect.width) {
				t_atom av;
				double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM; 
				double chosen_idx = CLAMP(floor((pt.y - man->active_inspector_enumindex_rect.y) / (CONST_BACH_INSPECTOR_ENUMINDEX_UY_STEP * zoom)), 0, man->active_inspector_enumindex->num_enum_index_elems - 1);
				atom_setlong(&av, chosen_idx);
				set_bach_attr_and_process_from_ac_av(man, man->active_bach_inspector_item, man->active_inspector_enumindex, 1, &av, true);
				man->active_inspector_enumindex = NULL;
                if (r_ob)
                    invalidate_notation_static_layer_and_repaint(r_ob);
				return 1;
			} else {
				man->active_inspector_enumindex = NULL;
                if (r_ob)
                    invalidate_notation_static_layer_and_repaint(r_ob);
			}
		} else if (man->active_inspector_color && !bach_inactive(man, man->active_bach_inspector_item, man->active_inspector_color)) {
			// to do
			
			if (pt.y > man->active_inspector_color_palette_rect.y && pt.y < man->active_inspector_color_palette_rect.y + man->active_inspector_color_palette_rect.height &&
				pt.x > man->active_inspector_color_palette_rect.x && pt.x < man->active_inspector_color_palette_rect.x + man->active_inspector_color_palette_rect.width) {
                if (r_ob)
                    set_mousedown(r_ob, WHITENULL_llll, k_BACH_INSPECTOR_COLOR_PALETTE);
				man->active_inspector_color->still_not_dragged = true;
				handle_mousedrag_in_bach_inspector(r_ob, man, patcherview, rect, pt, modifiers);
			} else if (pt.y > man->active_inspector_color_spectrum_rect.y && pt.y < man->active_inspector_color_spectrum_rect.y + man->active_inspector_color_spectrum_rect.height &&
						pt.x > man->active_inspector_color_spectrum_rect.x && pt.x < man->active_inspector_color_spectrum_rect.x + man->active_inspector_color_spectrum_rect.width){
                if (r_ob)
                    set_mousedown(r_ob, WHITENULL_llll, k_BACH_INSPECTOR_COLOR_SPECTRUM);
				man->active_inspector_color->still_not_dragged = true;
				handle_mousedrag_in_bach_inspector(r_ob, man, patcherview, rect, pt, modifiers);
			} else {
				man->active_inspector_color = NULL;
                if (r_ob)
                    invalidate_notation_static_layer_and_repaint(r_ob);
			}
		} else {
			
			t_bach_attribute *attr = pt_to_attribute_to_edit(man, patcherview, pt);
			long ac = 0;
			t_atom *av = NULL;
			void *elem = man->active_bach_inspector_item;
			
			if (attr && !bach_inactive(man, elem, attr)) {
				
				if (r_ob)
					set_mousedown(r_ob, attr, k_BACH_INSPECTOR_ITEM);
				attr->still_not_dragged = true;
				
				bach_get_attr(man, elem, attr, &ac, &av);
				
				if (ac && av && attr->attr_size == 1 && 
					(attr->attr_type == k_BACH_ATTR_CHAR || attr->attr_type == k_BACH_ATTR_LONG || attr->attr_type == k_BACH_ATTR_DOUBLE)
					&& is_atom_number(av))
					attr->float_dragging_value = atom_getfloat(av);
				
				if (attr->display_type == k_BACH_ATTR_DISPLAY_ONOFF) {
					ac = 1;
					if (atom_gettype(av) == A_OBJ)
						atom_setobj(av, atom_getobj(av) ? NULL : WHITENULL_llll);
					else
						atom_setlong(av, atom_getlong(av) ? 0 : 1);
					set_bach_attr_and_process_from_ac_av(man, elem, attr, ac, av, true);
                    if (r_ob)
                        invalidate_notation_static_layer_and_repaint(r_ob);
					bach_freeptr(av);
					return 1;
				
				} else if (attr->display_type == k_BACH_ATTR_DISPLAY_ENUMINDEX) {
					man->active_inspector_enumindex = attr;
					man->active_inspector_enumindex_mouseover_idx = -1;
                    if (r_ob)
                        invalidate_notation_static_layer_and_repaint(r_ob);
					
				} else if (attr->display_type == k_BACH_ATTR_DISPLAY_COLOR) {
					t_jrgba color = get_bach_attribute_as_color(man, elem, attr);
					man->active_inspector_color = attr;
					man->active_inspector_top_right_color = get_01normalized_color(color);
                    if (r_ob)
                        invalidate_notation_static_layer_and_repaint(r_ob);
				}
				
				bach_freeptr(av);
			}
		}
	}
	return 0;
}	

long get_mousedown_obj_type_for_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man)
{
    if (!r_ob && man->get_custom_mousedown_obj_type)
        return man->get_custom_mousedown_obj_type(man->thing);
    else if (r_ob)
        return r_ob->j_mousedown_obj_type;
    else
        return k_NONE;
}

void *get_mousedown_ptr_for_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man)
{
    if (!r_ob && man->get_custom_mousedown_ptr)
        return man->get_custom_mousedown_ptr(man->thing);
    else if (r_ob)
        return r_ob->j_mousedown_ptr;
    else
        return NULL;
}

long handle_mousedrag_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_rect rect, t_pt pt, long modifiers)
{
	if (man->active_bach_inspector_item) {
		double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM;
		void *elem = man->active_bach_inspector_item;
        
        long mousedown_obj_type = get_mousedown_obj_type_for_inspector(r_ob, man);
        void *mousedown_ptr = get_mousedown_ptr_for_inspector(r_ob, man);
        
		if (mousedown_obj_type == k_BACH_INSPECTOR_ITEM && mousedown_ptr) {
			t_bach_attribute *attr = (t_bach_attribute *)mousedown_ptr;
			if (attr->display_type == k_BACH_ATTR_DISPLAY_TEXT && attr->attr_size == 1 &&
				(attr->attr_type == k_BACH_ATTR_DOUBLE || attr->attr_type == k_BACH_ATTR_LONG || attr->attr_type == k_BACH_ATTR_CHAR)) {
				t_atom av;
				
				// Dragging is not allowed for:
				if (attr->owner_type == k_MEASURE && attr->name == _llllobj_sym_width) 
					return 0;
				
				// If dragging is allowed...
				if (attr->still_not_dragged) {
					bach_preprocess_attr(man, elem, attr);
					attr->still_not_dragged = false;
				}
				
				double delta_val = ((man->inspector_ui ? man->inspector_ui->floatdragging_y : r_ob->floatdragging_y) - pt.y)/(CONST_BACH_INSPECTOR_ATTR_DRAG_UCHANGE * zoom) * CLAMP(fabs(attr->float_dragging_value), 1, 200);
				
				if ((modifiers & eCommandKey) && (modifiers & eShiftKey))
					delta_val	*= CONST_FINER_FROM_KEYBOARD;
				
				attr->float_dragging_value += delta_val;
				
				if (attr->attr_type == k_BACH_ATTR_DOUBLE)
					atom_setfloat(&av, attr->float_dragging_value);
				else 
					atom_setlong(&av, attr->float_dragging_value);
				
				bach_set_attr(man, elem, attr, 1, &av);
				invalidate_notation_static_layer_and_repaint(r_ob);
				
				if (man->inspector_ui)
					man->inspector_ui->floatdragging_y = pt.y;
				else
					r_ob->floatdragging_y = pt.y;
			}
		} else if (mousedown_obj_type == k_BACH_INSPECTOR_VSCROLLBAR) {
			double needed_height = man->bach_inspector_items_needed_height; 
			double real_height = rect.height - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD * zoom;
			
			man->bach_inspector_scrollbar_delta_y += pt.y - (man->inspector_ui ? man->inspector_ui->floatdragging_y : r_ob->floatdragging_y);
			man->bach_inspector_scrollbar_pos = CLAMP(man->bach_inspector_scrollbar_delta_y/(needed_height - real_height), 0., 1.);
			invalidate_notation_static_layer_and_repaint(r_ob);

			if (man->inspector_ui)
				man->inspector_ui->floatdragging_y = pt.y;
			else
				r_ob->floatdragging_y = pt.y;
		} else if (mousedown_obj_type == k_BACH_INSPECTOR_COLOR_PALETTE && man->active_inspector_color) {
			t_atom av[4];
			t_jrgba newcolor;
				
			if (man->active_inspector_color->still_not_dragged) {
				bach_preprocess_attr(man, elem, man->active_inspector_color);
				man->active_inspector_color->still_not_dragged = false;
			}
			
			if (modifiers & eControlKey) {
				double delta_y = pt.y - (man->inspector_ui ? man->inspector_ui->floatdragging_y : r_ob->floatdragging_y);
				
				if (modifiers & eShiftKey && modifiers & eCommandKey)
					delta_y *= CONST_FINER_FROM_KEYBOARD;
				
				newcolor = get_bach_attribute_as_color(man, man->active_bach_inspector_item, man->active_inspector_color);
				newcolor.alpha -= delta_y/(CONST_ALPHA_DRAG_UCHANGE * zoom);				
				clip_double(&newcolor.alpha, 0, 1);
			} else {
				double xx = CLAMP((pt.x - man->active_inspector_color_palette_rect.x)/man->active_inspector_color_palette_rect.width, 0, 1);
				double yy = 1 - CLAMP((pt.y - man->active_inspector_color_palette_rect.y)/man->active_inspector_color_palette_rect.height, 0, 1);
				newcolor = xy_coordinates_to_color(xx, yy, man->active_inspector_top_right_color);
			}
			atom_setfloat(av, newcolor.red);
			atom_setfloat(av+1, newcolor.green);
			atom_setfloat(av+2, newcolor.blue);
			atom_setfloat(av+3, newcolor.alpha);
			bach_set_attr(man, man->active_bach_inspector_item, man->active_inspector_color, 4, av);
			invalidate_notation_static_layer_and_repaint(r_ob);
		} else if (mousedown_obj_type == k_BACH_INSPECTOR_COLOR_SPECTRUM && man->active_inspector_color) {
			t_atom av[4];
			double xx, yy;
			t_jrgba color = get_bach_attribute_as_color(man, man->active_bach_inspector_item, man->active_inspector_color);

			if (man->active_inspector_color->still_not_dragged) {
				bach_preprocess_attr(man, elem, man->active_inspector_color);
				man->active_inspector_color->still_not_dragged = false;
			}

			get_color_xy_coordinates(color, &xx, &yy);
			man->active_inspector_top_right_color = double_to_color(CLAMP(pt.y, man->active_inspector_color_spectrum_rect.y, man->active_inspector_color_spectrum_rect.y + man->active_inspector_color_spectrum_rect.height - CONST_EPSILON3), man->active_inspector_color_spectrum_rect.y, man->active_inspector_color_spectrum_rect.y + man->active_inspector_color_spectrum_rect.height, true);
			man->active_inspector_top_right_color.alpha = color.alpha;
			t_jrgba newcolor = xy_coordinates_to_color(xx, yy, man->active_inspector_top_right_color);
			atom_setfloat(av, newcolor.red);
			atom_setfloat(av+1, newcolor.green);
			atom_setfloat(av+2, newcolor.blue);
			atom_setfloat(av+3, newcolor.alpha);
			bach_set_attr(man, man->active_bach_inspector_item, man->active_inspector_color, 4, av);
			invalidate_notation_static_layer_and_repaint(r_ob);
		}
	}
	return 0;
}

long handle_mouseup_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_pt pt)
{
    long mousedown_obj_type = get_mousedown_obj_type_for_inspector(r_ob, man);
    void *mousedown_ptr = get_mousedown_ptr_for_inspector(r_ob, man);
	if (man->active_bach_inspector_item && mousedown_obj_type == k_BACH_INSPECTOR_ITEM && mousedown_ptr) {
		t_bach_attribute *attr = (t_bach_attribute *)mousedown_ptr;
		void *elem = man->active_bach_inspector_item;
		if (!attr->still_not_dragged) {
 			bach_postprocess_attr(man, elem, attr);
			return 1;
		}
	}
	return 0;
}

void bring_external_inspector_to_front(t_bach_inspector_manager *man){
	if (man->inspector_patcher) {
		object_method(man->inspector_patcher, gensym("vis"));
		jbox_grabfocus((t_jbox *)man->inspector_ui);
	}
}


void open_external_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, void *obj, long obj_type){
	if (man->inspector_patcher)  {
//		object_method(man->inspector_patcher, gensym("vis"));
	} else {
		t_dictionary *d = dictionary_new();
		char parsebuf[256];
		t_atom a;
		long ac = 0;
		t_atom *av = NULL;

		// create a patcher without scroll bars and a toolbar
		snprintf_zero(parsebuf, 256, "@defrect 0 0 500 400 @title bach inspector @varname inspectorpatcher @enablehscroll 0 @enablevscroll 0 @presentation 0 @toolbarid \"\"");
		atom_setparse_debug(&ac,&av,parsebuf);
		attr_args_dictionary(d,ac,av);
		atom_setobj(&a,d);
		bach_freeptr(av); 
		man->inspector_patcher = (t_object *)object_new_typed(CLASS_NOBOX,gensym("jpatcher"),1, &a);
		freeobject((t_object *)d);	// we created this dictionary and we don't need it anymore

		object_method(man->inspector_patcher, gensym("vis"));
		man->inspector_ui = (t_bach_inspector_ui *)newobject_sprintf(man->inspector_patcher, "@maxclass bach_inspector_ui @patching_rect 0 0 500 400 @varname inspectorui");
//		object_attach_byptr_register(r_ob->inspector_ui, r_ob->inspector_ui, CLASS_BOX);			// attach our UI object to itself
		object_attach_byptr_register(man->inspector_ui, man->inspector_patcher, CLASS_NOBOX);		// attach our UI object to object UI
		object_attach_byptr(man->inspector_ui, jpatcher_get_firstview(man->inspector_patcher));

		((t_bach_inspector_ui *)man->inspector_ui)->notation_obj = r_ob;
		((t_bach_inspector_ui *)man->inspector_ui)->inspector_manager = man;
		jbox_grabfocus((t_jbox *) man->inspector_ui);
	}
}

void open_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, void *obj, long obj_type)
{
	man->active_bach_inspector_item = obj;
	man->active_bach_inspector_obj_type = obj_type;
	open_external_inspector(r_ob, man, obj, obj_type);
	if (man->inspector_ui)
		jbox_redraw((t_jbox *) man->inspector_ui);
}

void open_bach_inspector_for_notation_item(t_notation_obj *r_ob, t_notation_item *it){
	open_bach_inspector(r_ob, &r_ob->m_inspector, it, it->type);
}


void switch_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, void *obj, long obj_type)
{
	if (man->inspector_ui && man->inspector_ui->edited_attribute)
		bach_inspector_enter(r_ob, man);

	man->active_inspector_enumindex = NULL;
	man->active_inspector_enumindex_mouseover_idx = -1;
	man->active_inspector_color = NULL;
	open_bach_inspector(r_ob, man, obj, obj_type);
	
	resync_selection_with_bach_inspector(r_ob);
}


void switch_bach_inspector_for_notation_item(t_notation_obj *r_ob, t_notation_item *it)
{
	if (r_ob->force_notation_item_inscreen)
		(r_ob->force_notation_item_inscreen)(r_ob, it, NULL);
		
	switch_bach_inspector(r_ob, &r_ob->m_inspector, it, it->type);
}

long handle_key_in_bach_inspector(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, long keycode, long modifiers, long textcharacter){
	if (man->active_bach_inspector_item) {
		void *item = man->active_bach_inspector_item;
        
        if (keycode == JKEY_ENTER) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_NOTE) {
                    t_bpt *firstbpt = ((t_note *)item)->firstbreakpoint;
                    if (firstbpt) {
                        firstbpt = firstbpt->next; // first breakpoint corresponds to note head, but we never inspect it (one should inspect the note itself instead!)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)firstbpt);
                    }
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    t_note *firstnote = ((t_chord *)item)->firstnote;
                    if (firstnote)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)firstnote);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    t_chord *firstchord = ((t_measure *)item)->firstchord;
                    if (firstchord)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)firstchord);
                } else if (man->active_bach_inspector_obj_type == k_VOICE) {
                    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                        t_chord *firstchord = ((t_rollvoice *)item)->firstchord;
                        if (firstchord)
                            switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)firstchord);
                    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                        t_measure *firstmeasure = ((t_scorevoice *)item)->firstmeasure;
                        if (firstmeasure) 
                            switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)firstmeasure);
                    }
                }
                invalidate_notation_static_layer_and_repaint(r_ob);
            }
			return 1;
            
        } else if (keycode == JKEY_ESC) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_PITCH_BREAKPOINT) {
                    switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_bpt *)item)->owner);
                } else if (man->active_bach_inspector_obj_type == k_NOTE) {
                    switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_note *)item)->parent);
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_chord *)item)->voiceparent);
                    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_chord *)item)->parent);
                    } else {
                        close_bach_inspector(r_ob, man);
                    }
                } else if (man->active_bach_inspector_obj_type == k_TEMPO) {
                    switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_tempo *)item)->owner);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)((t_measure *)item)->voiceparent);
                }
                invalidate_notation_static_layer_and_repaint(r_ob);
            } else
                close_bach_inspector(r_ob, man);
			return 1;
            
		} else if (keycode == JKEY_LEFTARROW || (keycode == JKEY_TAB && modifiers == (eShiftKey | eAltKey) && man->active_bach_inspector_obj_type == k_SLOTINFO)) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_PITCH_BREAKPOINT) {
                    t_bpt *prev = ((t_bpt *)item)->prev;
                    if (prev && prev->prev) // as always, we don't inspect the VERY FIRST breakpoint, because it corresponds to the note head (inspect the note itself, instead!)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_NOTE) {
                    t_chord *prevch = chord_get_prev(((t_note *)item)->parent);
                    t_note *prev = !prevch ? NULL : nth_note(prevch, CLAMP(note_get_position(r_ob, (t_note *)item) - 1, 0, prevch->num_notes - 1));
                    if (prev)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    t_chord *prev = chord_get_prev((t_chord *)item);
                    if (prev)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_TEMPO) {
                    t_tempo *prev = tempo_get_prev((t_tempo *)item);
                    if (prev)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    t_measure *prev = ((t_measure *)item)->prev;
                    if (prev)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_MARKER) {
                    t_marker *prev = ((t_marker *)item)->prev;
                    if (prev) 
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_SLOTINFO){
                    long num = ((t_slotinfo *)item)->slot_num;
                    switch_bach_inspector(r_ob, man, &r_ob->slotinfo[MAX(0, num - 1)], k_SLOTINFO);
                }
                invalidate_notation_static_layer_and_repaint(r_ob);
            }
			return 1;
        } else if (keycode == JKEY_RIGHTARROW || (keycode == JKEY_TAB && modifiers == eShiftKey && man->active_bach_inspector_obj_type == k_SLOTINFO)) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_PITCH_BREAKPOINT) {
                    t_bpt *next = ((t_bpt *)item)->next;
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_NOTE) {
                    t_chord *nextch = chord_get_next(((t_note *)item)->parent);
                    t_note *next = !nextch ? NULL : nth_note(nextch, CLAMP(note_get_position(r_ob, (t_note *)item) - 1, 0, nextch->num_notes - 1));
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    t_chord *next = chord_get_next((t_chord *)item);
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_TEMPO) {
                    t_tempo *next = tempo_get_next((t_tempo *)item);
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    t_measure *next = ((t_measure *)item)->next;
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_MARKER) {
                    t_marker *next = ((t_marker *)item)->next;
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_SLOTINFO){
                    long num = ((t_slotinfo *)item)->slot_num;
                    switch_bach_inspector(r_ob, man, &r_ob->slotinfo[MIN(CONST_MAX_SLOTS - 1, num + 1)], k_SLOTINFO);
                }
                invalidate_notation_static_layer_and_repaint(r_ob);
            }
			return 1;
        } else if (keycode == JKEY_DOWNARROW) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_NOTE) {
                    t_note *prev = ((t_note *)item)->prev;
                    if (prev)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    t_scorevoice *nextvoice = ((t_measure *)item)->voiceparent->next;
                    t_measure *meas = !nextvoice ? NULL : nth_measure_of_scorevoice(nextvoice, ((t_measure *)item)->measure_number);
                    if (meas)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)meas);
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    t_voice *nextvoice = voice_get_next(r_ob, r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? (t_voice *)((t_chord *)item)->voiceparent : (t_voice *)((t_chord *)item)->parent->voiceparent);
                    t_chord *ch = !nextvoice ? NULL : (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? find_ms_nearest_chord_in_rollvoice(r_ob, (t_rollvoice *)nextvoice, ((t_chord *)item)->onset) :
                                                       find_ux_nearest_chord_in_scorevoice(r_ob, (t_scorevoice *)nextvoice, chord_get_alignment_ux(r_ob, (t_chord *)item)));
                    if (ch)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)ch);
                } else if (man->active_bach_inspector_obj_type == k_VOICE) {
                    t_voice *next = voice_get_next(r_ob, (t_voice *)item);
                    if (next && next->number < r_ob->num_voices) 
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                }
            }
			return 1;
        } else if (keycode == JKEY_UPARROW) {
            if (r_ob) {
                if (man->active_bach_inspector_obj_type == k_NOTE) {
                    t_note *next = ((t_note *)item)->next;
                    if (next)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)next);
                } else if (man->active_bach_inspector_obj_type == k_MEASURE) {
                    t_scorevoice *prevvoice = ((t_measure *)item)->voiceparent->prev;
                    t_measure *meas = !prevvoice ? NULL : nth_measure_of_scorevoice(prevvoice, ((t_measure *)item)->measure_number);
                    if (meas)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)meas);
                } else if (man->active_bach_inspector_obj_type == k_CHORD) {
                    t_voice *prevvoice = voice_get_prev(r_ob, r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? (t_voice *)((t_chord *)item)->voiceparent : (t_voice *)((t_chord *)item)->parent->voiceparent);
                    t_chord *ch = !prevvoice ? NULL : (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? find_ms_nearest_chord_in_rollvoice(r_ob, (t_rollvoice *)prevvoice, ((t_chord *)item)->onset) :
                                                       find_ux_nearest_chord_in_scorevoice(r_ob, (t_scorevoice *)prevvoice, chord_get_alignment_ux(r_ob, (t_chord *)item)));
                    if (ch)
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)ch);
                } else if (man->active_bach_inspector_obj_type == k_VOICE) {
                    t_voice *prev = voice_get_prev(r_ob, (t_voice *)item);
                    if (prev) 
                        switch_bach_inspector_for_notation_item(r_ob, (t_notation_item *)prev);
                }
            }
			return 1;
		} else if (keycode == 'z' && modifiers & eCommandKey && r_ob && r_ob->allow_undo) {
            if (r_ob) {
                if (modifiers & eShiftKey)
                    object_method_typed((t_object *)r_ob, gensym("redo"), 0, NULL, NULL);
                else
                    object_method_typed((t_object *)r_ob, gensym("undo"), 0, NULL, NULL);
            }
			return 1;
			
		} else if (r_ob && man->active_bach_inspector_obj_type == k_SLOTINFO && !(modifiers & eCommandKey)
					&& !(modifiers & eAltKey) && !(modifiers & eControlKey)) {
			if (keycode >= 48 &&  keycode <= 57) {
				switch_bach_inspector(r_ob, man, &r_ob->slotinfo[keycode == 48 ? 9 : keycode - 49], k_SLOTINFO);
				return 1;
			} else {
				long j;
				for (j=0; j<CONST_MAX_SLOTS; j++) {
					if (r_ob->slotinfo[j].slot_key == textcharacter) {
						switch_bach_inspector(r_ob, man, &r_ob->slotinfo[j], k_SLOTINFO);
						return 1;
					}
				}
			}
		}
		return 0;
	}
	return 0;
}


void bach_attr_get_single_voicename(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr, long *ac, t_atom **av){
	t_symbol *sym = *((t_symbol **)((char *) obj + attr->field_position));
	if (sym == _llllobj_sym_abr_none_abr || sym == _llllobj_sym_empty_symbol) {
		*ac = 0;
	} else {
		*ac = 1;
		*av = (t_atom *)bach_newptr(sizeof(t_atom));
		atom_setsym(*av, sym);
	}
}

void bach_attr_set_single_voicename(t_notation_obj *r_ob, void *obj, t_bach_attribute *attr, long ac, t_atom *av){
	if (attr->owner_type == k_VOICE){
		change_single_voicename_from_ac_av(r_ob, (t_voice *)obj, ac, av, false);
/*		if (ac && av) {
			t_symbol *newname = ac_av_to_single_symbol(ac, av);
			if (newname == _llllobj_sym_empty_symbol)
				newname = _llllobj_sym_abr_none_abr;
			change_single_voicename(r_ob, (t_voice *)obj, newname, false);
		} else
			change_single_voicename(r_ob, (t_voice *)obj, _llllobj_sym_empty_symbol, false);*/
	}
}

void bach_set_name_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av) {
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    t_notation_item *it = (t_notation_item *)obj;
	t_llll *ll = llll_parse(ac, av);
    change_notation_item_names(r_ob, it, ll, false);
/*    if (it->type == k_MARKER)
        create_header_undo_tick(r_ob, k_HEADER_MARKERS);
    change_notation_item_names(r_ob, it, ll, it->type == k_MARKER ? false : true); */
	llll_free(ll);
}



void bach_set_flags_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av){
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	if (ac && av) {
		if (atom_getlong(av)){
			if (attr->name == _llllobj_sym_lock)
				lock_notation_item(r_ob, (t_notation_item *)obj);
			else if (attr->name == _llllobj_sym_mute)
				mute_notation_item(r_ob, (t_notation_item *)obj);
			else if (attr->name == _llllobj_sym_solo)
				solo_notation_item(r_ob, (t_notation_item *)obj);
		} else {
			if (attr->name == _llllobj_sym_lock)
				unlock_notation_item(r_ob, (t_notation_item *)obj);
			else if (attr->name == _llllobj_sym_mute)
				unmute_notation_item(r_ob, (t_notation_item *)obj);
			else if (attr->name == _llllobj_sym_solo)
				unsolo_notation_item(r_ob, (t_notation_item *)obj);
		}
	}
}



/////////////// EXTERNAL UI OBJECT FOR INSPECTOR

// useless?
void bach_inspector_ui_patcherview_vis(t_bach_inspector_ui *x, t_object *patcherview)
{
    object_attach_byptr(x, patcherview);
}

// useless?
void bach_inspector_ui_patcherview_invis(t_bach_inspector_ui *x, t_object *patcherview)
{
    object_detach_byptr(x, patcherview);
}

// should be called, but is never
// but if the corresponding method is declared, then notify is called when the patcher is resized
void bach_inspector_ui_boxscreenrectchanged(t_jbox *box, t_object *patcherview)
{
	jbox_redraw(box);
}

void bach_inspector_ui_classinit(void)
{
	t_class *c = class_new("bach_inspector_ui", (method)bach_inspector_ui_new, (method)bach_inspector_ui_free, sizeof(t_bach_inspector_ui), 0L, A_GIMME, 0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	jbox_initclass(c, JBOX_TEXTFIELD);
	class_addmethod(c, (method)bach_inspector_ui_paint,	"paint",		A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_mousedown,"mousedown",	A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_mousedrag,"mousedrag",	A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_mousewheel,"mousewheel",	A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_mouseup,"mouseup",	A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_mousemove,"mousemove",	A_CANT, 0);
    class_addmethod(c, (method)bach_inspector_ui_mousedoubleclick, "mousedoubleclick", A_CANT, 0);
  	class_addmethod(c, (method)bach_inspector_ui_key, "key", A_CANT, 0);
  	class_addmethod(c, (method)bach_inspector_ui_enter, "enter", A_CANT, 0);
	
	// The following function awfully gets called all the time, constantly, as if ticks were scheduled.
	// Yet if I remove this, the bach_inspector_ui_boxscreenrectchanged() is NOT properly called when patch is resized. Why???
	class_addmethod(c, (method)bach_inspector_ui_notify,	"notify",	A_CANT, 0);		// for auto-repainting.  
	
	// patcherview_vis and patcherview_invis are supposed to be called when the patcher is resized (or created?) and closed
	// actually, only patcherview_invis is called at close time
	class_addmethod(c, (method)bach_inspector_ui_patcherview_vis, "patcherview_vis", A_CANT, 0);
	class_addmethod(c, (method)bach_inspector_ui_patcherview_invis, "patcherview_invis", A_CANT, 0);
	
	// declaring the "boxscreenrectchanged" method doesn't cause bach_inspector_ui_boxscreenrectchanged() to be called - why???
	// instead, if (and only if) "boxscreenrectchanged" is declared bach_inspector_ui_notify is called when the patcher is resized
	// this actually looks like a bug... 
	class_addmethod(c, (method)bach_inspector_ui_boxscreenrectchanged,	"boxscreenrectchanged",	A_CANT, 0);

//	CLASS_ATTR_RGBA(c, "oncolor", 0, t_scripto_ui, u_oncolor);
//	CLASS_ATTR_PAINT(c, "oncolor", 0);
//	CLASS_ATTR_RGBA(c, "offcolor", 0, t_scripto_ui, u_offcolor);
//	CLASS_ATTR_PAINT(c, "offcolor", 0);
	
	class_register(CLASS_BOX, c);
	
	s_bach_inspector_ui_class = c;
}


void *bach_inspector_ui_new(t_symbol *s, long argc, t_atom *argv)
{
	t_bach_inspector_ui *x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	long flags;
	
	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;

	x = (t_bach_inspector_ui *) object_alloc(s_bach_inspector_ui_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
	//		| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
			| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
			| JBOX_GROWBOTH
			| JBOX_HILITE
	//		| JBOX_BACKGROUND
			| JBOX_TEXTFIELD
	//		| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
			;

	err = jbox_new(&x->u_box, flags, argc, argv); 

	x->u_box.b_firstin = (t_object*) x;
	
	attr_dictionary_process(x, d);
	jbox_ready(&x->u_box);

	x->edited_attribute = NULL;
	
	t_object *textfield;
	textfield = jbox_get_textfield((t_object *) x); 
	if (textfield) {
		t_jrgba black = get_grey(0);
		jbox_set_fontname((t_object *) x, gensym("Arial"));
		jbox_set_fontsize((t_object *) x, 12);
		
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0); // set it to 0 if you don't want user to edit it in lock mode
		textfield_set_useellipsis(textfield, 1);
		textfield_set_wantsreturn(textfield, 0);
		textfield_set_wordwrap(textfield, 0);
		textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 0, 0, 0, 0);	// margin on each side
		textfield_set_textcolor(textfield, &black);// textcolor
		object_method(textfield, _sym_settext, "");
	}
	

	return x;
}

void bach_inspector_ui_paint(t_bach_inspector_ui *x, t_object *patcherview)
{
	t_jgraphics *g;
	t_rect rect;
	t_rect patcher_rect;
	
	g = (t_jgraphics*) patcherview_get_jgraphics(patcherview); 
	jbox_get_rect_for_view(&x->u_box.b_ob, patcherview, &rect);
	
	// assuring that the object rectangle coincide with the patcher rectangle
	jpatcher_get_rect(x->inspector_manager->inspector_patcher, &patcher_rect);
//	object_attr_getdouble_array(x->notation_obj->inspector_patcher, _sym_rect, 4, patcher_rect_dim);
	
	patcherview_set_zoomfactor(patcherview, 1.);
	if (!(fabs(rect.width - patcher_rect.width) < CONST_EPSILON5 && fabs(rect.height - patcher_rect.height) < CONST_EPSILON5)) {
		t_size size;
		size.width = patcher_rect.width;
		size.height = patcher_rect.height;
		jbox_set_presentation_size((t_object *)x, &size);
		jbox_set_patching_size((t_object *)x, &size);
	}	
	
	paint_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, g, rect, x->inspector_manager->active_bach_inspector_item, x->inspector_manager->active_bach_inspector_obj_type, CONST_BACH_INSPECTOR_DEFAULT_ZOOM);
}

void bach_inspector_ui_mousedown(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_rect rect;
	jbox_get_rect_for_view(&x->u_box.b_ob, patcherview, &rect);
	handle_mousedown_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, rect, pt, modifiers);
	jbox_redraw((t_jbox *)x);
}
	
long bach_inspector_ui_key(t_bach_inspector_ui *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
	if (handle_key_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, keycode, modifiers, textcharacter))
		return 1;
	
	return 0;
}

// gets called when the patcher is resized only if the boxscreenrectchanged is declared
// Problem: gets called ALL the time!!! Which I suppose it might even 
t_max_err bach_inspector_ui_notify(t_bach_inspector_ui *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	// THIS FUNCTION GETS CALLED ALL THE TIME WHEN INSPECTOR IS OPEN. WHY!?!?

	if (msg == gensym("attr_modified")) {
		t_symbol *attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
		if (attrname != _sym_zoomfactor) {
			jbox_redraw((t_jbox *) x);
		}
	}
	return 0;
}
	
void bach_inspector_ui_enter(t_bach_inspector_ui *x)	// enter is triggerd at "endeditbox time"
{
	bach_inspector_enter(x->notation_obj, x->inspector_manager);
}

void bach_inspector_ui_mousedoubleclick(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers)
{
	handle_doubleclick_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, pt);
}
	
void bach_inspector_ui_mousedrag(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_rect rect;
	jbox_get_rect_for_view(&x->u_box.b_ob, patcherview, &rect);
	handle_mousedrag_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, rect, pt, modifiers);
	jbox_redraw((t_jbox *)x);
}
	
void bach_inspector_ui_mousemove(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers) {
	handle_mousemove_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, pt);
}

void bach_inspector_ui_mouseup(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers) {
	handle_mouseup_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, pt);
}

void bach_inspector_ui_mousewheel(t_bach_inspector_ui *x, t_object *patcherview, t_pt pt, long modifiers, double x_inc, double y_inc){
	handle_mousewheel_in_bach_inspector(x->notation_obj, x->inspector_manager, patcherview, pt, x_inc, y_inc);
}

	
void bach_inspector_ui_free(t_bach_inspector_ui *x)
{
	x->inspector_manager->inspector_ui = NULL;
	x->inspector_manager->inspector_patcher = NULL;
	jbox_free((t_jbox *)x);
}

