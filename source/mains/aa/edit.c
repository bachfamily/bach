#define	EDIT_MAX_CHARS	65536

#include "ext.h"
#include "ext_obex.h"
#include "ext_dictionary.h"
#include "ext_charset.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jpatcher_syms.h"
#include "jgraphics.h"
#include "llllobj.h"


/**********************************************************************/
// Data Structures
typedef struct _edit {
	t_llllobj_jbox		j_box;
	t_jrgba				j_textcolor;
	t_jrgba				j_layercolor[8];
	t_jrgba				j_bgcolor;
	t_jtextlayout		*j_tl[8];
	char				*j_colors;
} t_edit;

t_edit* edit_new(t_symbol *s, short argc, t_atom *argv);
void edit_free(t_edit *x);
void edit_anything(t_edit *x, t_symbol *s, long ac, t_atom *av);
void edit_select(t_edit *x);
void edit_doselect(t_edit *x);
void edit_paint(t_edit *x, t_object *view);
long edit_keyfilter(t_edit *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter);
void edit_enter(t_edit *x);
void edit_notify(t_edit *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
//void edit_mousedownonchar(t_edit *x, long l);

void edit_bang(t_edit *x);
void edit_parsecolors(t_edit *x, unsigned short *uni_text);

static t_class *s_edit_class = NULL;

int T_EXPORT main(void)
{
	t_class *c; 
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	jpatcher_syms_init();
	
	c = class_new("bach.edit", (method)edit_new, (method)edit_free, sizeof(t_edit), (method)NULL, A_GIMME, 0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR | JBOX_FIXWIDTH);	// include textfield and Fonts attributes
	
	class_addmethod(c, (method)edit_paint,				"paint",			A_CANT, 0);
	class_addmethod(c, (method)edit_keyfilter,			"keyfilter",		A_CANT, 0);
	class_addmethod(c, (method)edit_enter,				"enter",			A_CANT, 0);
	class_addmethod(c, (method)edit_anything,			"anything",			A_GIMME, 0);
	class_addmethod(c, (method)edit_select,				"select",			0);
	class_addmethod(c, (method)edit_bang,				"bang",				0);
	
//	class_addmethod(c, (method)edit_mousedownonchar,	"mousedownonchar",	A_LONG, 0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_UI);
	
	CLASS_ATTR_RGBA(c, "textcolor", 0, t_edit, j_textcolor);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 0.");
	CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
	CLASS_ATTR_CATEGORY(c, "textcolor", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "bgcolor", 0, t_edit, j_bgcolor);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "0.8 0.8 0.8 1.");
	CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
	CLASS_ATTR_CATEGORY(c, "bgcolor", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor1", 0, t_edit, j_layercolor[0]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor1", 0, "1 0 0 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor1", 0, "rgba", "Layer Color 1");
	CLASS_ATTR_CATEGORY(c, "layercolor1", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor2", 0, t_edit, j_layercolor[1]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor2", 0, "0 1 0 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor2", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor2", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor3", 0, t_edit, j_layercolor[2]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor3", 0, "1 1 0 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor3", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor3", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor4", 0, t_edit, j_layercolor[3]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor4", 0, "1 0 1 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor4", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor4", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor5", 0, t_edit, j_layercolor[4]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor5", 0, "0 1 1 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor5", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor5", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor6", 0, t_edit, j_layercolor[5]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor6", 0, "0 0 1 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor6", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor6", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor7", 0, t_edit, j_layercolor[6]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor7", 0, "0 0 0 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor7", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor7", 0, "Color");
	
	CLASS_ATTR_RGBA(c, "layercolor8", 0, t_edit, j_layercolor[7]);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "layercolor8", 0, "1 1 1 1.");
	CLASS_ATTR_STYLE_LABEL(c, "layercolor8", 0, "rgba", "Layer Color 2");
	CLASS_ATTR_CATEGORY(c, "layercolor8", 0, "Color");
	
	CLASS_ATTR_DEFAULT(c, "rect", 0, "0. 0. 100. 20.");
	
	class_register(CLASS_BOX, c);
	s_edit_class = c; 
	return 0;
}

void edit_free(t_edit *x)
{
	jbox_free((t_jbox *) &x->j_box);
}

void edit_anything(t_edit *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll;
	char *buff;
	
	if (!(in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, msg, ac, av, 0)))
		return;
	
	llll_to_text_buf(in_llll, &buff, 0, 10, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);

	object_method(jbox_get_textfield((t_object *)x), gensym("settext"), buff);

	jbox_redraw((t_jbox *) x);
}

void edit_select(t_edit *x)
{
	defer(x, (method)edit_doselect, 0, 0, 0);
}

void edit_doselect(t_edit *x)
{
	t_object *p = NULL; 
	post("select");
	object_obex_lookup(x,gensym("#P"), &p);
	if (p) {
		t_atom rv; 
		long ac = 1; 
		t_atom av[1]; 
		atom_setobj(av, x); 
		object_method_typed(p, gensym("selectbox"), ac, av, &rv); 
	}
}

long edit_keyfilter(t_edit *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter)
{
	t_atom arv;
	long rv = 1;
	long k = *keycode;
	
	if (k == JKEY_TAB || k == JKEY_ENTER || k == JKEY_RETURN || k == JKEY_ESC) {
		object_method_typed(patcherview, gensym("endeditbox"), 0, NULL, &arv); 
		rv = 0;		// don't pass those keys to edit
	}

	return rv;
}

/*
void edit_mousedownonchar(t_edit *x, long l)
{
	post("%d", l);
	return;
}*/

void edit_enter(t_edit *x)	// enter is triggerd at "endeditbox time"
{
	// jbox_redraw(x);
	edit_bang(x);
}

void edit_bang(t_edit *x)
{
	t_object *textfield = NULL;
	char *text;
	long size;
	t_llll *ll;

	textfield = jbox_get_textfield((t_object *)x);
	if (!textfield) 
		return;

	object_method(textfield, gensym("gettextptr"), &text, &size);
	
	ll = llll_from_text_buf(text);
	if (ll) {
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 0, ll);
		llll_free(ll);
	}
}

void edit_paint(t_edit *x, t_object *view)
{
	t_rect rect;
	t_jgraphics *g;
	long size	= 0;
	long i;
	char *text = NULL, *this_colors;
	t_object *textfield = jbox_get_textfield((t_object *)x);
	char *layertext = (char *) bach_newptrclear(2048), *this_layertext;
	t_jfont *jf = jfont_create("Monaco", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, 12);
	unsigned short *uni_text, *this_uni_text;
	char *utf_char, *this_utf_char;
	long dummy_len;
	
	
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	
	// set up matrix
	jbox_get_rect_for_view((t_object*) x, view, &rect); 
	
	// soft gray background
	jgraphics_rectangle(g, 0., 0., rect.width, rect.height);
	jgraphics_set_source_jrgba(g, &x->j_bgcolor);
	jgraphics_fill(g);
	
	// set line width for the corners
	jgraphics_set_line_width(g, 2.);
	jgraphics_set_source_rgba(g, x->j_bgcolor.red * 0.7, x->j_bgcolor.green * 0.7, x->j_bgcolor.blue * 0.7, x->j_bgcolor.alpha * 0.7);
	
	// draw top left corner
	jgraphics_move_to(g, 1., rect.height - 8.);
	jgraphics_line_to(g, 1., rect.height - 1.);
	jgraphics_line_to(g, 8., rect.height - 1.);
	jgraphics_stroke(g);
	
	// draw bottom right corner
	jgraphics_move_to(g, rect.width - 8., 1.);
	jgraphics_line_to(g, rect.width - 1., 1.);
	jgraphics_line_to(g, rect.width - 1., 8.);
	jgraphics_stroke(g);
	
	object_method(textfield, gensym("gettextptr"), &text, &size);
	uni_text = charset_utf8tounicode(text, &dummy_len);
	edit_parsecolors(x, uni_text);
	
	for (i = 0; i < 8; i++) {
		for (this_uni_text = uni_text, this_colors = x->j_colors, this_layertext = layertext;
			 *this_uni_text; 
			 this_uni_text++, this_colors++) {
			if (*this_colors - 48 == i || *this_uni_text == 32) {
				utf_char = charset_unicodetoutf8(this_uni_text, 1, &dummy_len);
				for (this_utf_char = utf_char; *this_utf_char; this_layertext++, this_utf_char++)
					*this_layertext = *this_utf_char;
				bach_freeptr(utf_char);
			} else {
				*this_layertext++ = '\xc2';
				*this_layertext++ = '\xa0';
			}
		}
		
		bach_freeptr(uni_text);
		*this_layertext = 0;
		
		jtextlayout_set(x->j_tl[i], layertext, jf, 3, 3, rect.width-6, rect.height-6, JGRAPHICS_TEXT_JUSTIFICATION_LEFT, 0);
		jtextlayout_draw(x->j_tl[i], g);
		
		
	}
	jfont_destroy(jf);
}

void edit_parsecolors(t_edit *x, unsigned short *uni_text)
{
	char *this_color = x->j_colors;
	long depth = 0;
	long sym_start = 1, backquoted = 0, space = 1;
	
	
	for ( ; *uni_text; uni_text++, this_color++) {
		if (isspace(*uni_text)) {
			backquoted = 0;
			space = 1;
		} else if (space) {
				sym_start = 1;
				space = 0;
		}
		
		if (sym_start && *uni_text == '`')
			backquoted = 1;
		
		sym_start = 0;

		if (*uni_text == '\\')
			*uni_text++;
		
		if (!*uni_text)
			break;
		
		if (!backquoted && *uni_text == '(')
			depth++;
		
		*this_color = MAX(depth, 0) % 8 + '0';
		if (!backquoted && *uni_text == ')')
			depth--;
	}
}

t_edit *edit_new(t_symbol *name, short argc, t_atom *argv)
{
	t_edit* x;
	t_dictionary *d = NULL;
	long i;
	
	if (!(d = object_dictionaryarg(argc,argv)))
		return NULL;
 	
	x = (t_edit *) object_alloc_debug(s_edit_class);
	if (x) {
		long		flags;
		t_object	*textfield;
		
		x->j_colors = (char *) bach_newptrclear(EDIT_MAX_CHARS);
		
		flags = 0 
		| JBOX_DRAWFIRSTIN 
		| JBOX_NODRAWBOX
		| JBOX_DRAWINLAST
		| JBOX_TRANSPARENT	
		//		| JBOX_NOGROW
		//		| JBOX_GROWY
		| JBOX_GROWBOTH
		//		| JBOX_IGNORELOCKCLICK
		//		| JBOX_HILITE
		//		| JBOX_BACKGROUND
		//		| JBOX_NOFLOATINSPECTOR
		| JBOX_TEXTFIELD
		;
		
		jbox_new((t_jbox *) &x->j_box, flags, argc, argv);
		x->j_box.l_box.b_firstin = (t_object*) x;
		
		textfield = jbox_get_textfield((t_object*) x); 
		if (textfield) {
			textfield_set_editonclick(textfield, 1);				// set it to 0 if you don't want user to edit it in lock mode
			textfield_set_selectallonedit(textfield, 0);
			textfield_set_autoscroll(textfield, 1);
			textfield_set_textmargins(textfield, 3, 3, 3, 3);		// margin on each side
			textfield_set_textcolor(textfield, &x->j_textcolor);	// textcolor
		}

		attr_dictionary_process(x, d);

		llllobj_jbox_setup((t_llllobj_jbox *) x, 0, "4"); 

		for (i = 0; i < 8; i++) {
			x->j_tl[i] = jtextlayout_create();
			jtextlayout_settextcolor(x->j_tl[i], x->j_layercolor + i);
		}
		jbox_set_fontname((t_object *) x, gensym("Monaco"));
		jbox_set_fontsize((t_object *) x, 12);
		jbox_ready((t_jbox *) &x->j_box);
	}
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	return x;
}
