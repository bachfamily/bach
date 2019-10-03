/*
 *  hypercomment.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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
	hypercomment.c
	
	@name 
	bach.hypercomment
	
	@realname 
	bach.hypercomment

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@status
	ok
	
	@digest 
	A <o>comment</o> with hyperlink references
	
	@description
	Works like a standard <o>comment</o> object, with the possibility to easily have
	hyperlink references inside it.
	
	@discussion
	
	@category
	bach, bach objects, bach interface, U/I, bach miscellanea
	
	@keywords
	comment, link, hyperlink, reference, hand, write, send, click

	@palette
	YES
 
	@palette category
	bach, bach objects, bach miscellanea, bach interface

	@seealso
	comment, bach.wordcloud
	
	@owner
	Daniele Ghisi
*/

#include "foundation/bach.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_dictionary.h"
#include "jpatcher_api.h"
#include "jpatcher_syms.h"
#include "jgraphics.h"
#include "graphics/bach_graphics.h"
#include "ext_boxstyle.h"

#define CONST_MAX_LINK_PER_COMMENT 100
#define MAX_LINK_START_SYMBOLS 100
#define MAX_LINK_END_SYMBOLS 200

/**********************************************************************/
// Data Structures

typedef struct _hypercomment_link {
	t_symbol *link_sym;
	t_symbol *link_label;
	t_rect	 rect;
} t_hypercomment_link;

typedef struct _hypercomment {

	t_jbox					j_box; // root object

	t_jrgba					j_dummy_transparent;
	t_jrgba					j_textcolor;
	t_jrgba					j_hypertextcolor;
	t_jrgba					j_bgcolor;
	
	t_symbol				*hyperlinkchars[MAX_LINK_START_SYMBOLS];
	long					hyperlinkchars_num;
	t_symbol				*interruptchars[MAX_LINK_END_SYMBOLS];
	long					interruptchars_num;
	t_symbol				*labelchars;
	char					hidechars;

	t_symbol				*sendname;

	char					underline;
	char					showhand;
	char					is_editing;
	
	char					drop_hyperlink_chars_at_output;
	
	char					cursor_is_hand;

	void					*out1;
	
	t_hypercomment_link		link[CONST_MAX_LINK_PER_COMMENT];
	long					num_links;
	
//	t_llll					*references;
	
} t_hypercomment;


/**********************************************************************/
// Prototypes

t_hypercomment* hypercomment_new(t_symbol *s, short argc, t_atom *argv);
void hypercomment_free(t_hypercomment *x);
void hypercomment_set(t_hypercomment *x, t_symbol *s, long ac, t_atom *av);
void hypercomment_select(t_hypercomment *x);
void hypercomment_doselect(t_hypercomment *x);
void hypercomment_paint(t_hypercomment *x, t_object *view);
long hypercomment_key(t_hypercomment *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
long hypercomment_keyfilter(t_hypercomment *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter);
void hypercomment_enter(t_hypercomment *x);
void hypercomment_jsave(t_hypercomment *x, t_dictionary *d);
void hypercomment_mousedoubleclick(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers);
void hypercomment_mousedown(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers);
void hypercomment_mousemove(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers);
void hypercomment_assist(t_hypercomment *x, void *b, long m, long a, char *s);


t_max_err hypercomment_setattr_sendto(t_hypercomment *x, t_object *attr, long ac, t_atom *av);



/**********************************************************************/
// Globals and Statics

static t_class *s_hypercomment_class = NULL;


/**********************************************************************/
// Class Definition and Life Cycle

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c; 
	
	jpatcher_syms_init();
	
    CLASS_NEW_CHECK_SIZE(c, "bach.hypercomment", 
				  (method)hypercomment_new,
				  (method)hypercomment_free,
				  sizeof(t_hypercomment),
				  (method)NULL,
				  A_GIMME,
				  0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR | JBOX_FIXWIDTH);	// include textfield and Fonts attributes
	
	class_addmethod(c, (method) hypercomment_paint,		"paint",		A_CANT, 0);
	class_addmethod(c, (method) hypercomment_key,		"key",			A_CANT, 0);
	class_addmethod(c, (method) hypercomment_keyfilter,	"keyfilter",	A_CANT, 0);
	class_addmethod(c, (method) hypercomment_enter,		"enter",		A_CANT, 0);
	class_addmethod(c, (method) hypercomment_jsave,		"jsave",		A_CANT, 0);
	class_addmethod(c, (method) hypercomment_set,		"anything",		A_GIMME, 0);
//	class_addmethod(c, (method) hypercomment_select,	"select",		0);
	class_addmethod(c, (method) jbox_notify,			"notify",		A_CANT, 0);
	class_addmethod(c, (method) hypercomment_assist,	"assist", A_CANT, 0);

	class_addmethod(c, (method) hypercomment_mousedown, "mousedown",	A_CANT, 0);
    class_addmethod(c, (method) hypercomment_mousedoubleclick, "mousedoubleclick", A_CANT, 0);
	class_addmethod(c, (method) hypercomment_mousemove, "mousemove",	A_CANT, 0);
	
  
//  hypercomment is not an LLLLOBJ, so it doesn't have this. I don't think it'll need it.
//    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_UI);

    
	CLASS_STICKY_ATTR(c,"category",0,"Color");

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_hypercomment, j_bgcolor, "Background Color", "rect_fill");
    class_attr_stylemap(c, (char *)"bgcolor", (char *)"clearcolor");
    CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "1. 1. 1. 0.");
    CLASS_ATTR_BASIC(c, "bgcolor", 0);
    // @description Color of the background
#else
    CLASS_ATTR_RGBA(c, "bgcolor", 0, t_hypercomment, j_bgcolor);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 0.");
    CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
    CLASS_ATTR_BASIC(c, "bgcolor", 0);
#endif
    
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "hyperlinkcolor", 0, t_hypercomment, j_hypertextcolor, "Hyperlink Color", "text_letter");
    CLASS_ATTR_LEGACYDEFAULT(c, "hyperlinkcolor", "hyperlinkcolor", 0, "0.34 0.45 0.16 1.");
    class_attr_stylemap(c, (char *)"hyperlinkcolor", (char *)"selectioncolor");
    CLASS_ATTR_BASIC(c, "hyperlinkcolor", 0);
    // @description Color of the hyperlinks in the text
#else
    CLASS_ATTR_RGBA(c, "hyperlinkcolor", 0, t_hypercomment, j_hypertextcolor);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "hyperlinkcolor", 0, "0.34 0.45 0.16 1.");
    CLASS_ATTR_STYLE_LABEL(c, "hyperlinkcolor", 0, "rgba", "Hyperlink Color");
    CLASS_ATTR_BASIC(c, "hyperlinkcolor", 0);
#endif
    
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_hypercomment, j_textcolor, "Text Color", "text_letter");
    CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0. 0. 0. 1.");
    CLASS_ATTR_BASIC(c, "textcolor", 0);
    // @description Color of the text
#else
    CLASS_ATTR_RGBA(c, "textcolor", 0, t_hypercomment, j_textcolor);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
    CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
    CLASS_ATTR_BASIC(c, "textcolor", 0);
    // @exclude all
#endif

    
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Settings");

		CLASS_ATTR_SYM_VARSIZE(c, "linkstart", 0, t_hypercomment, hyperlinkchars, hyperlinkchars_num, MAX_LINK_START_SYMBOLS);
		CLASS_ATTR_STYLE_LABEL(c,"linkstart",0,"text","Starting Character(s) For Links");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkstart",0,"#");
		CLASS_ATTR_BASIC(c, "linkstart", 0);
		// @description List of symbols, each containing a character or sequence of characters which, put at the beginning of a word, identify it as an hyperlink.

		CLASS_ATTR_SYM_VARSIZE(c, "linkend", 0, t_hypercomment, interruptchars, interruptchars_num, MAX_LINK_END_SYMBOLS);
		CLASS_ATTR_STYLE_LABEL(c,"linkend",0,"text","Character(s) Interrupting Links");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkend",0,". : ! ? \",\" \";\" ( ) [ ] { }");
		// @description List of symbols, each containing a character or sequence of characters which will interrupt any ongoing link.
		// If any of these characters is found, the link will be interrupted.
		// For instance, if comma is contained in this symbol, a word like <b>#one,two</b>, only the <b>#one</b> part will be marked as link. 

//		CLASS_ATTR_CHAR(c, "hide", 0, t_hypercomment, hidechars);
//		CLASS_ATTR_STYLE_LABEL(c,"hide",0,"enumindex","Hide Link Character(s)");
//		CLASS_ATTR_ENUMINDEX(c,"hide", 0, "None Starting Character(s) Ending Character(s) Both");
//		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hide",0,"0");
		// @exclude bach.hypercomment
		// @description Toggles the ability to hide the character used to define the start or the end of an hyperlink.

//		CLASS_ATTR_SYM(c, "label", 0, t_hypercomment, labelchars);
//		CLASS_ATTR_STYLE_LABEL(c,"label",0,"text","Character For Labeling Links");
//		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"label",0,"$");
		// @exclude bach.hypercomment
		// @description Symbol containing the character which will define the label of a given link, if put before the end of such link.
		// For instance, if such symbol is "@" and the start link symbol is "#", one can define a hyperlink on the word "this" and mark it with the 
		// "foo" label in the following way: #this$foo.
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Behavior");
	
		CLASS_ATTR_CHAR(c, "drop", 0, t_hypercomment, drop_hyperlink_chars_at_output);
		CLASS_ATTR_STYLE_LABEL(c,"drop",0,"onoff","Drop Hyperlink Starting Character At Output");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"drop",0,"1");
		CLASS_ATTR_BASIC(c, "drop", 0);
		// @description Toggles the ability to drop the hyperlink leading character when the clicked link is output or sent
		// via a <o>send</o> object (see <m>sendto</m>).

		CLASS_ATTR_SYM(c, "sendto", 0, t_hypercomment, sendname);
		CLASS_ATTR_STYLE_LABEL(c,"sendto",0,"text","Automatically Send Link To");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"sendto",0,"");
		CLASS_ATTR_ACCESSORS(c, "sendto", (method)NULL, (method)hypercomment_setattr_sendto);
		// @description Symbol containing the possible name of a <o>send</o> object, to which the clicked link must be sent. 
		// Leave a void symbol if not needed.  
		
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Appearance");

		CLASS_ATTR_CHAR(c, "underline", 0, t_hypercomment, underline);
		CLASS_ATTR_STYLE_LABEL(c,"underline",0,"onoff","Underline Hyperlinks");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"underline",0,"1");
		// @description Underline hyperlink words

		CLASS_ATTR_CHAR(c, "showhand", 0, t_hypercomment, showhand);
		CLASS_ATTR_STYLE_LABEL(c,"showhand",0,"onoff","Show Hand Cursor On Links");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showhand",0,"1");
		// @description Show the hand cursor when it is over a link
		
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_ATTR_DEFAULT(c, "rect", 0, "0. 0. 100. 20.");
	// @exclude bach.hypercomment
	
	class_register(CLASS_BOX, c);
	s_hypercomment_class = c; 
	
//	post("bach.hypercomment compiled %s %s", __DATE__, __TIME__);

	return;
}

t_max_err hypercomment_setattr_sendto(t_hypercomment *x, t_object *attr, long ac, t_atom *av){
	if (ac && av && atom_gettype(av) == A_SYM)
		x->sendname = atom_getsym(av);
	else 
		x->sendname = gensym("");
		
	return MAX_ERR_NONE;
}


t_hypercomment* hypercomment_new(t_symbol *name, short argc, t_atom *argv)
{
	t_hypercomment* x;
	t_dictionary *d = NULL;
	
	if (!(d = object_dictionaryarg(argc,argv)))
		return NULL;
 	
	x = (t_hypercomment*)object_alloc(s_hypercomment_class);
	if (x) {
		long		flags;
		t_object	*textfield;
//		t_symbol	*s = NULL;
		
		flags = 0 
				| JBOX_DRAWFIRSTIN 
				| JBOX_NODRAWBOX
				| JBOX_DRAWINLAST
				| JBOX_TRANSPARENT	
		//		| JBOX_NOGROW
		//		| JBOX_GROWY
		//		| JBOX_GROWBOTH
		//		| JBOX_IGNORELOCKCLICK
		//		| JBOX_HILITE
		//		| JBOX_BACKGROUND
		//		| JBOX_NOFLOATINSPECTOR
				| JBOX_TEXTFIELD
		;
		
		jbox_new(&x->j_box, flags, argc, argv);
		x->j_box.b_firstin = (t_object*) x;

		x->is_editing = 0;
		x->j_dummy_transparent.red = x->j_dummy_transparent.green = x->j_dummy_transparent.blue = x->j_dummy_transparent.alpha = 0;
		x->cursor_is_hand = false;
		x->num_links = 0;

		textfield = jbox_get_textfield((t_object*) x); 
		if (textfield) {
			object_attr_setchar(textfield, gensym("editwhenunlocked"), 1);
			textfield_set_noactivate(textfield, 1);
			textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
			textfield_set_textmargins(textfield, TEXTFIELD_DEF_LEFTMARGIN, TEXTFIELD_DEF_TOPMARGIN, TEXTFIELD_DEF_RIGHTMARGIN, TEXTFIELD_DEF_BOTTOMMARGIN);	// margin on each side
			object_attr_setchar(textfield, gensym("visible"), 0); // not visible
//			object_attr_setjrgba(x, gensym("textcolor"), &x->j_dummy_transparent);
			textfield_set_textcolor(textfield, &x->j_dummy_transparent);// textcolor
		}

		x->out1 = outlet_new((t_object *)x,0);

		attr_dictionary_process(x, d);
		
		jbox_ready(&x->j_box);
	}
	return x;
}

void hypercomment_free(t_hypercomment *x)
{
	jbox_free(&x->j_box);
}


void hypercomment_set(t_hypercomment *x, t_symbol *s, long ac, t_atom *av)
{
	char *buff = NULL;
	long size;

	if (ac && av) {
		atom_gettext(ac, av, &size, &buff, 0);
		object_method(jbox_get_textfield((t_object *)x), gensym("settext"), buff);
	} else {
		object_method(jbox_get_textfield((t_object *)x), gensym("settext"), "");
	}
	jbox_redraw((t_jbox *)x);
}
/*
void hypercomment_select(t_hypercomment *x)
{
	defer(x, (method)hypercomment_doselect, 0, 0, 0);
}

void hypercomment_doselect(t_hypercomment *x)
{
	t_object *p = NULL; 
	object_obex_lookup(x,gensym("#P"), &p);
	if (p) {
		t_atom rv; 
		long ac = 1; 
		t_atom av[1]; 
		atom_setobj(av, x); 
		object_method_typed(p, gensym("selectbox"), ac, av, &rv); 
	}
}
*/

long hypercomment_key(t_hypercomment *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
	char buff[256];
	buff[0] = textcharacter;  // we know this is just a simple char
	buff[1] = 0; 
	object_method(patcherview, gensym("insertboxtext"), x, buff);
	jbox_redraw((t_jbox *)x);

	return 1; 
}

long hypercomment_keyfilter(t_hypercomment *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter)
{
	t_atom arv;
	long rv = 1;
	long k = *keycode;
	
	if (k == JKEY_TAB || k == JKEY_ESC) {
		object_method_typed(patcherview, gensym("endeditbox"), 0, NULL, &arv); 
		rv = 0;		// don't pass those keys to hypercomment
	}
	return rv;
}

void hypercomment_enter(t_hypercomment *x)	// enter is triggerd at "endeditbox time"
{
/*	long size	= 0;
	char *text	= NULL;
	t_object *textfield = jbox_get_textfield((t_object *)x);
	
	object_method(textfield, gensym("gettextptr"), &text, &size);
	if (size)
		post("This is the new text: %s", text);
*/
}


/**********************************************************************/
// Methods
void hypercomment_bang(t_hypercomment *x)
{
	t_object *textfield = NULL;
	jbox_get_textfield((t_object *)x);
	if (textfield) {
		;
	}
}

char does_start_link(t_hypercomment *x, char *buf, long *length)
{
	long i;
	for (i = 0; i < x->hyperlinkchars_num; i++)  {
		unsigned long len = strlen(x->hyperlinkchars[i]->s_name);
		if (strlen(buf) >= len && strncmp(x->hyperlinkchars[i]->s_name, buf, len) == 0) {
			if (length)
				*length = len;
			return 1;
		}
	}
	return 0;
}

char does_end_link(t_hypercomment *x, char *buf, long *length)
{
	long i;
	for (i = 0; i < x->interruptchars_num; i++)  {
		unsigned long len = strlen(x->interruptchars[i]->s_name);
		if (strlen(buf) >= len && strncmp(x->interruptchars[i]->s_name, buf, len) == 0) {
			if (length)
				*length = len;
			return 1;
		}
	}
	return 0;
}

char is_char_in_sym(char c, t_symbol *sym)
{
	if (!sym || !sym->s_name)
		return 0;
		
	long i, l = strlen(sym->s_name);
	for (i = 0; i < l; i++)
		if (sym->s_name[i] == c)
			return 1;
	return 0;
} 

void hypercomment_assist(t_hypercomment *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) {
		sprintf(s, "Set Text");
	} else {
		sprintf(s, "symbol: Clicked Hyperlink");
	}
}


void hypercomment_paint(t_hypercomment *x, t_object *view)
{
	t_jgraphics *g;
	t_rect rect;
	double font_size = jbox_get_fontsize((t_object *) x);
	long font_slant = jbox_get_font_slant((t_object *) x);
	long font_weight = jbox_get_font_weight((t_object *) x);
	t_symbol *font_name = jbox_get_fontname((t_object *) x);
	
	char *text = NULL;
	long size;
	t_object *textfield = jbox_get_textfield((t_object *)x);

    t_jrgba j_textcolor_r, j_bgcolor_r, j_hypertextcolor_r;
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("hyperlinkcolor"), &j_hypertextcolor_r);
    
	object_method(textfield, gensym("gettextptr"), &text, &size);

	t_jfont *jf = jfont_create(font_name->s_name, (t_jgraphics_font_slant) font_slant, (t_jgraphics_font_weight) font_weight, font_size);

	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view((t_object *)x, view, &rect);

	paint_background((t_object *)x, g, &rect, &j_bgcolor_r, 0.);
	
	if (!patcherview_get_locked(view)) {
/*		t_jrgba dotted_line_color;
		t_jrgba white_color; 
		dotted_line_color.red = dotted_line_color.green = dotted_line_color.blue = 0;
		white_color.red = white_color.green = white_color.blue = 1;
		dotted_line_color.alpha = 1;
		white_color.alpha = 0.5;

		paint_line(g, white_color, 0, 0, rect.width, 0, 1);
		paint_line(g, white_color, rect.width, 0, rect.width, rect.height, 1);
		paint_line(g, white_color, rect.width, rect.height, 0, rect.height, 1);
		paint_line(g, white_color, 0, rect.height, 0, 0, 1);

		paint_dashed_line(g, dotted_line_color, 0, 0, rect.width, 0, 1, 1);
		paint_dashed_line(g, dotted_line_color, rect.width, 0, rect.width, rect.height, 1, 1);
		paint_dashed_line(g, dotted_line_color, rect.width, rect.height, 0, rect.height, 1, 1);
		paint_dashed_line(g, dotted_line_color, 0, rect.height, 0, 0, 1, 1); */
	} else {
		x->is_editing = false;
	}

//	dev_post("Repaint! Editing: %d", x->is_editing);
	
	if (!x->is_editing) { // always!
		double inset_x = 4, inset_y = 3;
		double real_pixel_width = rect.width - 8;
		double cur_x = 0, cur_y;
		long line_num = 0;
		double w, h = font_size, wspace, hspace = font_size;

		const char *white = " ";
		jfont_text_measure(jf, white, &wspace, &hspace);

		long len = strlen(text);
		char *text_cpy = (char *)sysmem_newptr((len + 1) * sizeof(char));
		strcpy(text_cpy, text);

		char delim[3];
		char *p;

		x->num_links = 0;

		delim[0] = ' ';
		delim[1] = 10;
		delim[2] = 0;

		// starting spaces and returns
		long i = 0;
		while (text[i] == 10 || text[i] == ' '){
			if (text[i] == 10) {
				line_num++;
				cur_x = 0;
			} else if (text[i] == ' ') {
				cur_x += wspace;
			}
			i++;
		}
		
		for (p = strtok(text_cpy, delim); p; p = strtok(NULL, delim))
		{
			jfont_text_measure(jf, p, &w, &h);
			
			if (cur_x + w > real_pixel_width) {
				// overflow: must wrap
				line_num++;
				cur_x = 0;
			} 
			
			cur_y = line_num * h;
			
			long link_start_len = 0;
			if (p && does_start_link(x, p, &link_start_len)) {
				// find link end:
				char first_char_hidden = false, last_char_hidden = false;
				long i, interrupt_i = -1;
				long len_p = strlen(p);
				for (i = 0; i < len_p; i++) {
					if (does_end_link(x, p + i, NULL)) {
						interrupt_i = i;
						break;
					}
				}
				
/*				if (x->hidechars & 0x1 && !x->is_editing) {
					p++; // hiding starting link character
					interrupt_i--;
					first_char_hidden = true;
				}*/
				
				if (interrupt_i < 0 || interrupt_i > 0) { // hyperlink part
					long first_part_size = strlen(p) + 1;
					char *first_part = sysmem_newptr(first_part_size * sizeof(char));
					strcpy(first_part,p);
					//first_part = strdup(p);
					
					if (interrupt_i > 0 && interrupt_i < first_part_size)
						first_part[interrupt_i] = 0;

					jfont_text_measure(jf, first_part, &w, &h);

					if (x->num_links < CONST_MAX_LINK_PER_COMMENT) {
						x->link[x->num_links].rect.x = cur_x;
						x->link[x->num_links].rect.y = cur_y;
						x->link[x->num_links].rect.width = w;
						x->link[x->num_links].rect.height = h;
						x->link[x->num_links].link_sym = gensym((x->drop_hyperlink_chars_at_output && !first_char_hidden) ? first_part + link_start_len : first_part);
						x->link[x->num_links].link_label = NULL;
						x->num_links++;
					}
					
					if (x->underline) {
						double underline_shift = font_size * 1.05;
						paint_line(g, j_hypertextcolor_r, cur_x + inset_x, cur_y + inset_y + underline_shift, cur_x + inset_x + w, cur_y + inset_y + underline_shift, 1. * font_size / 12.);
					}
					
					write_text(g, jf, j_hypertextcolor_r, first_part, cur_x + inset_x, cur_y + inset_y, w, h, JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, 1, 0);
					
					cur_x += w;
					
					sysmem_freeptr(first_part);
				}
				
				if (interrupt_i >= 0) { // non hyperlink part
/*					if (x->hidechars & 0x2 ? 1 : 0)
						last_char_hidden = true;*/
					
					char *second_part = sysmem_newptr((strlen(p + interrupt_i + last_char_hidden) + 1)*sizeof(char));
					strcpy(second_part,p + interrupt_i + last_char_hidden);
					//second_part = strdup(p + interrupt_i);

					if (second_part) {
						if (strlen(second_part) > 0) {
							jfont_text_measure(jf, second_part, &w, &h);
							
							write_text(g, jf, j_textcolor_r, second_part, cur_x + inset_x, cur_y + inset_y, w, h, JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, 1, 0);
							
							cur_x += w;
						}
						sysmem_freeptr(second_part);
					}
				}

				
			} else {
				
				write_text(g, jf, j_textcolor_r, p, cur_x + inset_x, cur_y + inset_y, w, h, JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, 1, 0);
				cur_x += w;
			
			}
			
			
			long len_p = strlen(p);
			i = p - text_cpy + len_p;
			while (text[i] == 10 || text[i] == ' '){
				if (text[i] == 10) {
					line_num++;
					cur_x = 0;
				} else if (text[i] == ' ') {
					cur_x += wspace;
				}
				i++;
			}
		}
		
		sysmem_freeptr(text_cpy);
	}

	jfont_destroy(jf);

    t_jrgba border_color = build_jrgba(0.69, 0.69, 0.678, 1);
    if (!patcherview_get_locked(view))
        paint_border((t_object *)x, g, &rect, &border_color, 1., 0.);

    // OLD Max6-style code
/*    t_jrgba border_color = build_jrgba(0.69, 0.85, 0.92, 1);
	paint_border((t_object *)x, g, &rect, &border_color, x->is_editing ? 4 : 0., 0.);
 */
}


// The jsave method is called when the patcher is being saved so that we can add custom data (data that is not an attribute)
// to the patcher dictionary.

void hypercomment_jsave(t_hypercomment *x, t_dictionary *d)
{
/*	t_object	*textfield = jbox_get_textfield((t_object*)x);
	long		size = 0;
	char		*text = NULL;
	
	object_method(textfield, gensym("gettextptr"), &text, &size);
	if (size)
		dictionary_appendsym(d, gensym("bach_hypercomment_string"), gensym(text));
	else
		dictionary_appendsym(d, gensym("bach_hypercomment_string"), gensym(""));
*/
}

// THIS FUNCTION IS NEVER CALLED!
// dg: 03/01/2019: WHY?
void hypercomment_mousedoubleclick(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers) {
	long		size = 0;
	char		*text = NULL;
	t_object	*textfield = jbox_get_textfield((t_object*)x);
	object_method(textfield, gensym("gettextptr"), &text, &size);

	if (!patcherview_get_locked(patcherview)) {
		x->is_editing = 1;
		textfield_set_textcolor(textfield, &x->j_dummy_transparent);// textcolor
		object_method(patcherview, gensym("insertboxtext"), x, text);
	}
}

void hypercomment_mousemove(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers) {
	long i;
	char is_in_rect = false;
	if (x->showhand) {
		for (i = 0; i < x->num_links; i++) {
			is_in_rect = is_pt_in_rectangle(pt, x->link[i].rect);
			if (is_in_rect && !x->cursor_is_hand) {
				jmouse_setcursor(patcherview, (t_object*) x, JMOUSE_CURSOR_POINTINGHAND);
				x->cursor_is_hand = true;
			}
			if (is_in_rect)
				break;
		}
	}
	if (!x->showhand || (!is_in_rect && x->cursor_is_hand)) {
		jmouse_setcursor(patcherview, (t_object*) x, JMOUSE_CURSOR_ARROW);
		x->cursor_is_hand = false;
	}
}

void hypercomment_mousedown(t_hypercomment *x, t_object *patcherview, t_pt pt, long modifiers){
	t_symbol *foundsym = NULL;
	long i;
	for (i = 0; i < x->num_links; i++) {
		if (is_pt_in_rectangle(pt, x->link[i].rect)) {
			foundsym = x->link[i].link_sym;
			break;
		}
	}
	if (foundsym) {
		if (x->sendname && x->sendname->s_name && strlen(x->sendname->s_name) > 0)
			object_method_typed(x->sendname->s_thing, foundsym, 0, NULL, NULL);
		outlet_anything(x->out1, foundsym, 0, NULL);
	}
}
