/**
	@file
	wordcloud.c
	
	@name 
	bach.wordcloud
	
	@realname 
	bach.wordcloud

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@status
	ok
	
	@digest 
	Display a word cloud
	
	@description
	Displays an interactive word cloud.
	
	@discussion
	
	@category
	bach, bach objects, bach interface, U/I, bach miscellanea

	@keywords
	word, cloud, tag, display, click
	
	@palette
	YES
 
	@palette category
	bach, bach objects, bach miscellanea, bach interface

	@seealso
	bach.hypercomment
	
	@owner
	Daniele Ghisi
*/

#include "llllobj.h"
#include "bach_math_utilities.h"
#include "bach_graphics.h"
#include "llll_commons_ext.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_dictionary.h"
#include "jpatcher_api.h"
#include "jpatcher_syms.h"
#include "jgraphics.h"
#include "ext_boxstyle.h"

#define CONST_MAX_TAGS 1000

/**********************************************************************/
// Data Structures

typedef struct _wordcloud_tag {
	t_symbol	*tag;
	double		weights;
	double		font_size;
	t_rect		rect;
	long		line_num;
} t_wordcloud_tag;


typedef struct _wordcloud {
    
	t_llllobj_jbox			j_box; // root object

	t_jrgba					j_textcolor;
	t_jrgba					j_mouseover_textcolor;
	t_jrgba					j_mousedown_textcolor;
	t_jrgba					j_bgcolor;
	t_jrgba					j_bordercolor;
	
	double					borderwidth;
	double					corner_roundness;

	double					min_weights;
	double					max_weights;
	
	char					underline;
	char					showhand;
	char					is_editing;
	double					space_between_words;
	
	char					cursor_is_hand;
	
	char					autofit;
	char					save_data_with_patcher;

	void					*out1;
	
	t_llll					*tags_as_llll;
	t_llll					*weights_as_llll;
	
	t_wordcloud_tag			*tag;
	long					num_tags;
	
	char					need_rebuild_tags;
	
	void					*n_proxy[2];
	long					n_in;
	
	char					alignment;
	char					vertical_alignment;
	char					line_vertical_alignment;
	double					scatter;
	
	double					min_font_size;
	double					max_font_size;
	double					slope;
	
	char					creating_new_obj;
	
	long					mouseclick_tag;
	long					mousemove_tag;

	// preset attributes
	t_atom		*preset_av;		
	long		preset_ac;		
	
} t_wordcloud;

static t_class *s_wordcloud_class = NULL;


/**********************************************************************/
// Prototypes

t_wordcloud* wordcloud_new(t_symbol *s, short argc, t_atom *argv);
void wordcloud_free(t_wordcloud *x);
void wordcloud_set(t_wordcloud *x, t_symbol *s, long ac, t_atom *av);
void wordcloud_paint(t_wordcloud *x, t_object *view);
void wordcloud_jsave(t_wordcloud *x, t_dictionary *d);
void wordcloud_mousedown(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers);
void wordcloud_mouseup(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers);
void wordcloud_mousemove(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers);
void wordcloud_mouseleave(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers);
void wordcloud_assist(t_wordcloud *x, void *b, long m, long a, char *s);
void wordcloud_inletinfo(t_wordcloud *x, void *b, long a, char *t);

t_max_err wordcloud_setattr_align(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_valign(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_linevalign(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_vscatter(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_maxfontsize(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_fontsizeslope(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_minfontsize(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_space(t_wordcloud *x, t_object *attr, long ac, t_atom *av);
t_max_err wordcloud_setattr_autofit(t_wordcloud *x, t_object *attr, long ac, t_atom *av);

void wordcloud_anything(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv);
void wordcloud_int(t_wordcloud *x, t_atom_long num);
void wordcloud_float(t_wordcloud *x, double num);
void wordcloud_bang(t_wordcloud *x);

long wordcloud_oksize(t_wordcloud *x, t_rect *newrect);

void rebuild_tags(t_wordcloud *x, t_object *view, t_rect rect, t_symbol *font_name, double font_size, long font_weight, long font_slant);

void wordcloud_preset(t_wordcloud *x);
void wordcloud_begin_preset(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv);
void wordcloud_restore_preset(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv);
void wordcloud_end_preset(t_wordcloud *x);
void wordcloud_setinterleaved(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv);


int T_EXPORT main(void){
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.wordcloud", 
				  (method)wordcloud_new,
				  (method)wordcloud_free,
				  sizeof(t_wordcloud),
				  (method)NULL,
				  A_GIMME,
				  0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	//	jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR);	// include textfield and Fonts attributes
	//	jbox_initclass(c, 0);
	
	// @method bang @digest Rebuild wordcloud
	// @description A <m>bang</m> forces to rebuild the word cloud from the most recently received input data. 
	class_addmethod(c, (method)	wordcloud_bang,			"bang", 0);

	class_addmethod(c, (method) wordcloud_paint,			"paint", A_CANT, 0);

	// @method llll @digest Set words or weights
	// @description An <m>llll</m> in the left inlet sets the list of words to be displayed in the word cloud. 
	// Words are then sorted alphabetically and the word cloud is built. <br />
	// An <m>llll</m> in the right inlet sets the weight associated with the words put in the left inlet. If no
	// weights are inserted, all words will be assigned the same weight.
	class_addmethod(c, (method) wordcloud_anything, "anything", A_GIMME, 0);
	class_addmethod(c, (method) wordcloud_anything, "list", A_GIMME, 0);
	class_addmethod(c, (method) wordcloud_jsave,		"jsave",		A_CANT, 0);
		
    class_addmethod(c, (method) wordcloud_preset, "preset", 0);
    class_addmethod(c, (method) wordcloud_begin_preset, "begin_preset", A_GIMME, 0);
    class_addmethod(c, (method) wordcloud_restore_preset, "restore_preset", A_GIMME, 0);
    class_addmethod(c, (method) wordcloud_end_preset, "end_preset", 0);
	CLASS_METHOD_ATTR_PARSE(c, "begin_preset", "undocumented", gensym("long"), 0L, "1");
	CLASS_METHOD_ATTR_PARSE(c, "restore_preset", "undocumented", gensym("long"), 0L, "1");
	CLASS_METHOD_ATTR_PARSE(c, "end_preset", "undocumented", gensym("long"), 0L, "1"); 
	
	class_addmethod(c, (method) wordcloud_mousedown,	"mousedown",	A_CANT, 0);
	class_addmethod(c, (method) wordcloud_mouseup,		"mouseup",	A_CANT, 0);
	class_addmethod(c, (method) wordcloud_mousemove,	"mousemove",	A_CANT, 0);
	class_addmethod(c, (method) wordcloud_mouseleave, "mouseleave", A_CANT, 0);
	
	class_addmethod(c, (method) wordcloud_inletinfo, "inletinfo", A_CANT, 0);
	class_addmethod(c, (method) wordcloud_assist, "assist", A_CANT, 0);
	class_addmethod(c, (method) wordcloud_oksize, "oksize", A_CANT, 0);
	
	llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_UI);
	
	CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 200 300"); // new dimensions
	// @exclude bach.wordcloud

	CLASS_STICKY_ATTR(c,"category",0,"Color");
	
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_wordcloud, j_bgcolor, "Background Color", "rect_fill");
    CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "1. 1. 1. 1.");
    CLASS_ATTR_BASIC(c, "bgcolor", 0);
    // @description Color of the background
#else
    CLASS_ATTR_RGBA(c, "bgcolor", 0, t_wordcloud, j_bgcolor);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
    CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
    CLASS_ATTR_BASIC(c, "bgcolor", 0);
    CLASS_ATTR_ALIAS(c, "bgcolor", "backgroundcolor");
#endif
	
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_BASIC(c,"textcolor",0);
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_wordcloud, j_textcolor, "Text Color", "text_letter");
    class_attr_stylemap(c, (char *)"textcolor", (char *)"textcolor_inverse");
    CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0. 0. 0. 1.");
	// @description Color of the text
#else
    CLASS_ATTR_RGBA(c, "textcolor", 0, t_wordcloud, j_textcolor);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
    CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
    CLASS_ATTR_BASIC(c, "textcolor", 0);
#endif
	
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "hovercolor", 0, t_wordcloud, j_mouseover_textcolor, "Mouse Hover Color", "text_letter");
    CLASS_ATTR_LEGACYDEFAULT(c, "hovercolor", "hovercolor", 0, "0.34 0.45 0.16 1.");
    class_attr_stylemap(c, (char *)"hovercolor", (char *)"selectioncolor");
    CLASS_ATTR_BASIC(c, "hovercolor", 0);
    // @description Color of the text when mouse is clicking on it
#else
	CLASS_ATTR_RGBA(c, "hovercolor", 0, t_wordcloud, j_mouseover_textcolor);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "hovercolor", 0, "0.34 0.45 0.16 1.");
	CLASS_ATTR_STYLE_LABEL(c, "hovercolor", 0, "rgba", "Mouse Hover Color");
	// @description Color of the text when mouse is over it.
#endif
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "clickcolor", 0, t_wordcloud, j_mousedown_textcolor, "Mouse Click Color", "text_letter");
    CLASS_ATTR_LEGACYDEFAULT(c, "clickcolor", "clickcolor", 0, "0. 0. 0. 1.");
    class_attr_stylemap(c, (char *)"clickcolor", (char *)"accentcolor");
    CLASS_ATTR_BASIC(c, "clickcolor", 0);
    // @description Color of the text when mouse is clicking on it
#else
	CLASS_ATTR_RGBA(c, "clickcolor", 0, t_wordcloud, j_mousedown_textcolor);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "clickcolor", 0, "0. 0. 0. 1.");
	CLASS_ATTR_STYLE_LABEL(c, "clickcolor", 0, "rgba", "Mouse Click Color");
#endif
    
	CLASS_ATTR_RGBA(c, "bordercolor", 0, t_wordcloud, j_bordercolor);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0. 0. 0. 1.");
	CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
	CLASS_ATTR_BASIC(c, "bordercolor", 0);
	// @description Color of the border
	
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
	
	
	CLASS_STICKY_ATTR(c,"category",0,"Appearance");
	
	CLASS_ATTR_DOUBLE(c, "rounded", 0, t_wordcloud, corner_roundness); 
	CLASS_ATTR_STYLE_LABEL(c,"rounded",0,"text","Roundness of Box Corners");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rounded",0,"0.");
	
	CLASS_ATTR_DOUBLE(c, "borderwidth", 0, t_wordcloud, borderwidth); 
	CLASS_ATTR_STYLE_LABEL(c,"borderwidth",0,"text","Border Width");
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"borderwidth",0,"0.");
#else
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"borderwidth",0,"1.");
#endif
    
	CLASS_ATTR_CHAR(c, "underline", 0, t_wordcloud, underline);
	CLASS_ATTR_STYLE_LABEL(c,"underline",0,"onoff","Underline Mouse Hover Tags");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"underline",0,"1");
	CLASS_ATTR_BASIC(c, "underline", 0);
	// @description Underline tags when mouse is over them
	
	CLASS_ATTR_CHAR(c, "showhand", 0, t_wordcloud, showhand);
	CLASS_ATTR_STYLE_LABEL(c,"showhand",0,"onoff","Show Hand Cursor On Tags");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showhand",0,"1");
	CLASS_ATTR_BASIC(c, "showhand", 0);
	// @description Show the hand cursor when it is over a tag
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
	
	CLASS_STICKY_ATTR(c,"category",0,"Font");
	
	CLASS_ATTR_DOUBLE(c, "minfontsize", 0, t_wordcloud, min_font_size); 
	CLASS_ATTR_STYLE_LABEL(c,"minfontsize",0,"text","Minimum Font Size");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minfontsize",0,"8"); 		
	CLASS_ATTR_ACCESSORS(c, "minfontsize", (method)NULL, (method)wordcloud_setattr_minfontsize);
	CLASS_ATTR_BASIC(c, "minfontsize", 0);
	// @description Font size corresponding to the minimum displayed weight.
	
	CLASS_ATTR_DOUBLE(c, "maxfontsize", 0, t_wordcloud, max_font_size); 
	CLASS_ATTR_STYLE_LABEL(c,"maxfontsize",0,"text","Maximum Font Size");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxfontsize",0,"20"); 		
	CLASS_ATTR_ACCESSORS(c, "maxfontsize", (method)NULL, (method)wordcloud_setattr_maxfontsize);
	CLASS_ATTR_BASIC(c, "maxfontsize", 0);
	// @description Font size corresponding to the maximum displayed weight.
	
	CLASS_ATTR_DOUBLE(c, "fontsizeslope", 0, t_wordcloud, slope); 
	CLASS_ATTR_STYLE_LABEL(c,"fontsizeslope",0,"text","Font Size Slope");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"fontsizeslope",0,"0."); 		
	CLASS_ATTR_ACCESSORS(c, "fontsizeslope", (method)NULL, (method)wordcloud_setattr_fontsizeslope);
	// @description Slope parameter for font size mapping, as for <o>curve~</o> (0. meaning: linear).
	
	CLASS_ATTR_CHAR(c, "align", 0, t_wordcloud, alignment); 
	CLASS_ATTR_STYLE_LABEL(c,"align",0,"enumindex","Horizontal Alignment");
	CLASS_ATTR_ENUMINDEX(c,"align", 0, "Left Center Right Justify");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"align",0,"1"); 		
	CLASS_ATTR_ACCESSORS(c, "align", (method)NULL, (method)wordcloud_setattr_align);
	CLASS_ATTR_BASIC(c, "align", 0);
	// @description Sets the horizontal alignment for the cloud. Possibilities are: "Left", "Center", "Right", "Justify".
	
	CLASS_ATTR_CHAR(c, "valign", 0, t_wordcloud, vertical_alignment); 
	CLASS_ATTR_STYLE_LABEL(c,"valign",0,"enumindex","Global Vertical Alignment");
	CLASS_ATTR_ENUMINDEX(c,"valign", 0, "Top Middle Bottom Justify");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"valign",0,"1"); 		
	CLASS_ATTR_ACCESSORS(c, "valign", (method)NULL, (method)wordcloud_setattr_valign);
	CLASS_ATTR_BASIC(c, "valign", 0);
	// @description Sets the vertical alignment for the cloud. Possibilities are: "Top", "Middle", "Bottom", "Justify".
	
	CLASS_ATTR_CHAR(c, "linevalign", 0, t_wordcloud, line_vertical_alignment); 
	CLASS_ATTR_STYLE_LABEL(c,"linevalign",0,"enumindex","Line Vertical Alignment");
	CLASS_ATTR_ENUMINDEX(c,"linevalign", 0, "Top Middle Bottom Baseline");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linevalign",0,"1"); 		
	CLASS_ATTR_ACCESSORS(c, "linevalign", (method)NULL, (method)wordcloud_setattr_linevalign);
	// @description Sets the vertical alignment for each line inside the cloud. Possibilities are: "Top", "Middle", "Bottom", "Baseline".
	
	CLASS_ATTR_DOUBLE(c, "vscatter", 0, t_wordcloud, scatter); 
	CLASS_ATTR_STYLE_LABEL(c,"vscatter",0,"text","Relative Vertical Scatter");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"vscatter",0,"0."); 		
	CLASS_ATTR_ACCESSORS(c, "vscatter", (method)NULL, (method)wordcloud_setattr_vscatter);
	// @description Amount of allowed vertical scatter for each element inside the cloud. A number between 0 and 1 is expected,
	// 0 corresponding to no scatter (vertical position is set by <m>valign</m> and <m>linevalign</m> attributes, 1. corresponding
	// to the maximum allowed random scatter (i.e. <m>linevalign</m> attribute is rendered mute). 
	
	CLASS_ATTR_DOUBLE(c, "space", 0, t_wordcloud, space_between_words); 
	CLASS_ATTR_STYLE_LABEL(c,"space",0,"text","Space between words");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"space",0,"10"); 
	CLASS_ATTR_ACCESSORS(c, "space", (method)NULL, (method)wordcloud_setattr_space);
	// @description Factor for spacing words apart.
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Behavior");

	CLASS_ATTR_CHAR(c, "embed", 0, t_wordcloud, save_data_with_patcher);
	CLASS_ATTR_STYLE_LABEL(c,"embed",0,"onoff","Save Data With Patcher");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"embed",0,"1");
	CLASS_ATTR_BASIC(c,"embed",0);
	// @description @copy BACH_DOC_EMBED
	
	CLASS_ATTR_CHAR(c, "autofit", 0, t_wordcloud, autofit);
	CLASS_ATTR_STYLE_LABEL(c,"autofit",0,"onoff","Fit Words Automatically");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autofit",0,"1");
	CLASS_ATTR_BASIC(c,"autofit",0);
	CLASS_ATTR_ACCESSORS(c, "autofit", (method)NULL, (method)wordcloud_setattr_autofit);
	// @description Toggles the ability to filter the minimum weight of displayed words depending on the
	// object size, so that, when resized only most important words are kept displayed. 
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
	
	s_wordcloud_class = c;
	class_register(CLASS_BOX, s_wordcloud_class);
	
	dev_post("bach.wordcloud compiled %s %s", __DATE__, __TIME__);
	return 0;
}

void wordcloud_begin_preset(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv)
{
	x->preset_ac = atom_getlong(argv) ;
	x->preset_av = (t_atom *)bach_newptr(x->preset_ac * sizeof(t_atom));
	
	// could allocate memory here etc.
	//	post("begin_preset %ld values will be arriving",x->r_ob.preset_ac);
}


void wordcloud_restore_preset(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv)
{
	long start, size;
	
	start = atom_getlong(argv);
	size = atom_getlong(argv + 1);
	//	post("restore_preset start %ld size %ld", start,size);
	
	sysmem_copyptr(argv+2, x->preset_av+start, size*sizeof(t_atom));
}

void wordcloud_end_preset(t_wordcloud *x)
{
	//	post("end_preset received");
	wordcloud_setinterleaved(x, NULL, x->preset_ac, x->preset_av);
	bach_freeptr(x->preset_av);
}

void wordcloud_preset(t_wordcloud *x){
	t_atom temp[256];
	void *buf;
	long i, index, size;
	char wrote = false, begin = true, done = false;
	
	t_llll *ll = llll_get();
	llll_appendllll_clone(ll, x->tags_as_llll, 0, WHITENULL_llll, NULL);
	llll_appendllll_clone(ll, x->weights_as_llll, 0, WHITENULL_llll, NULL);
	llll_trans_inplace(ll, 2);
	llll_flat(ll, 0, 0, 0, LLLL_FREETHING_DONT);
	
	// 1. we deparse the list
	t_atom *av = NULL, *this_av = NULL;
	long ac = llll_deparse(ll, &av, 0, /* LLLL_D_FLOAT64 | */ LLLL_D_QUOTE); //offset 0
	this_av = av;
	
	// 2. We fill the binbuf
	buf = gensym("_preset")->s_thing; 
	if (!buf)	// no preset object
		return;
	
	index = 0;
	while (!done) {
		i = index;
		size = ac - index;
		if (size > 250)
			size = 250;
		else	// you are at the end
			done = true;
		
		sysmem_copyptr(this_av, temp+5, 250*sizeof(t_atom));
		
		if (size) {
			atom_setobj(temp, x);
			atom_setsym(temp + 1, ob_sym(x));
			if (begin) {
				atom_setsym(temp + 2, gensym("begin_preset"));
				atom_setlong(temp + 3, ac);
				binbuf_insert(buf, NULL, 4, temp);
				begin = false;
			}
			atom_setsym(temp + 2, gensym("restore_preset"));
			atom_setlong(temp + 3, index);
			atom_setlong(temp + 4, size);
			binbuf_insert(buf, NULL, size + 5, temp);
			wrote = true;
		}
		index += size;
		this_av += 250;
	}
	if (wrote) {
		atom_setobj(temp, x);
		atom_setsym(temp + 1, ob_sym(x));
		atom_setsym(temp + 2, gensym("end_preset"));
		binbuf_insert(buf, NULL, 3, temp);
	}
	
	if (av) bach_freeptr(av);
}

void wordcloud_bang(t_wordcloud *x)
{
	x->need_rebuild_tags = true;
	jbox_redraw((t_jbox *)x);
}

long wordcloud_oksize(t_wordcloud *x, t_rect *newrect)
{
	x->need_rebuild_tags = true;
	jbox_redraw((t_jbox *)x);
	return 1;
}


t_max_err wordcloud_setattr_align(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->alignment = CLAMP(atom_getlong(av), 0, 3);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_valign(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->vertical_alignment = CLAMP(atom_getlong(av), 0, 3);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_linevalign(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->line_vertical_alignment = CLAMP(atom_getlong(av), 0, 3);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_autofit(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->autofit = CLAMP(atom_getlong(av), 0, 1);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_vscatter(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->scatter = CLAMP(atom_getfloat(av), 0., 1.);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_maxfontsize(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->max_font_size = atom_getfloat(av);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_minfontsize(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->min_font_size = atom_getfloat(av);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_fontsizeslope(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->slope = atom_getfloat(av);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err wordcloud_setattr_space(t_wordcloud *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->space_between_words = atom_getfloat(av);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}


void wordcloud_int(t_wordcloud *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	wordcloud_anything(x, _llllobj_sym_list, 1, argv);
}

void wordcloud_float(t_wordcloud *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	wordcloud_anything(x, _llllobj_sym_list, 1, argv);
}



void wordcloud_setinterleaved(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv){
	t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll **delaced = llll_delace(ll, 2);
	x->tags_as_llll = delaced[0];
	x->weights_as_llll = delaced[1];
	bach_freeptr(delaced);
	x->need_rebuild_tags = true;
	jbox_redraw((t_jbox *) x);
}


void wordcloud_anything(t_wordcloud *x, t_symbol *s, long argc, t_atom *argv){
	
	long inlet = proxy_getinlet((t_object *) x);

	if (inlet == 1) {
		llll_free(x->weights_as_llll);
		x->weights_as_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);
	} else if (inlet == 0) {
		llll_free(x->tags_as_llll);
		x->tags_as_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);
		x->need_rebuild_tags = true;
		jbox_redraw((t_jbox *) x);
	}
}



t_wordcloud* wordcloud_new(t_symbol *s, short argc, t_atom *argv)
{
	t_wordcloud* x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	long flags;
	t_object *textfield;
	
	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;
	
	x = (t_wordcloud*) object_alloc_debug(s_wordcloud_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
			| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
	//		| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
			| JBOX_GROWBOTH
			| JBOX_HILITE
	//		| JBOX_BACKGROUND
			| JBOX_TEXTFIELD
	//		| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
	//		| JBOX_MOUSEDRAGDELTA
	;
	
	err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
	x->j_box.l_box.b_firstin = (t_object*) x;
	x->creating_new_obj = true;

	x->cursor_is_hand = false;
	x->num_tags = 0;
	x->max_weights = 1;
	x->min_weights = 0;
	x->need_rebuild_tags = false;
	x->tags_as_llll = x->weights_as_llll = NULL;
	x->mousemove_tag = x->mouseclick_tag = -1;
	
	x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
	
	x->tag = (t_wordcloud_tag *)bach_newptrclear(CONST_MAX_TAGS * sizeof(t_wordcloud_tag));
	
	// retrieve saved attribute values
	attr_dictionary_process(x, d);
	
	textfield = jbox_get_textfield((t_object *) x);  // JUST TO HAVE A TEXT ATTRIBUTE READY
	if (textfield) {
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 3, 3, 3, 3);	// margin on each side
	}
	
	llllobj_jbox_setup((t_llllobj_jbox *) x, 2, "a", NULL);
	
	jbox_ready(&x->j_box.l_box);
    // bach_init_size((t_object *)x, 200, 300);
	
	if (x) {
		t_llll *llll_for_rebuild = llll_retrieve_from_dictionary(d, "whole_wordcloud_data");
		
		if (llll_for_rebuild) { // new method
			// retrieving saved values?
			llllobj_manage_dict_llll((t_object *)x, LLLL_OBJ_UI, llll_for_rebuild);
			if (llll_for_rebuild->l_head && llll_for_rebuild->l_head->l_next &&
				hatom_gettype(&llll_for_rebuild->l_head->l_hatom) == H_LLLL && hatom_gettype(&llll_for_rebuild->l_head->l_next->l_hatom) == H_LLLL) {
				x->tags_as_llll = llll_clone(hatom_getllll(&llll_for_rebuild->l_head->l_hatom));
				x->weights_as_llll = llll_clone(hatom_getllll(&llll_for_rebuild->l_head->l_next->l_hatom));
				x->need_rebuild_tags = true;
				jbox_redraw((t_jbox *) x);
			}
			llll_free(llll_for_rebuild);
		}
		
		x->creating_new_obj = false; 
        llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_UI);
		return x;
	}
	
	object_free_debug(x);
	return NULL;
}

 
void wordcloud_free(t_wordcloud *x)
{
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);
	if (x->weights_as_llll)
		llll_free(x->weights_as_llll);
	if (x->tags_as_llll)
		llll_free(x->tags_as_llll);
	bach_freeptr(x->tag);
	jbox_free(&x->j_box.l_box);
	llllobj_jbox_free((t_llllobj_jbox *) x);
}


void wordcloud_inletinfo(t_wordcloud *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void wordcloud_assist(t_wordcloud *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) {
		if (a == 0) // @out 0 @type llll @digest The tags to be displayed 
			sprintf(s, "llll: Tags");
		else if (a == 1) // @out 1 @type llll @digest The weight of each tag 
			sprintf(s, "llll: Weights"); // @description The weight is a numeric value associated with the tag, determining its size
	} else {
		sprintf(s, "symbol: Clicked Tag");
	}
}


void wordcloud_paint(t_wordcloud *x, t_object *view)
{
	t_jgraphics *g;
	t_rect rect;
	double base_font_size = jbox_get_fontsize((t_object *) x);
	long font_slant = jbox_get_font_slant((t_object *) x);
	long font_weight = jbox_get_font_weight((t_object *) x);
	t_symbol *font_name = jbox_get_fontname((t_object *) x);
	t_jfont *jf;
    t_jrgba j_textcolor_r, j_bgcolor_r, j_mousedown_text_color_r, j_mouseover_textcolor_r;
    
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("clickcolor"), &j_mousedown_text_color_r);
    object_attr_getjrgba((t_object *)x, gensym("hovercolor"), &j_mouseover_textcolor_r);

	
	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view((t_object *)x, view, &rect);

	paint_background((t_object *)x, g, &rect, &j_bgcolor_r, x->corner_roundness);
	
	if (x->need_rebuild_tags)
		rebuild_tags(x, view, rect, font_name, base_font_size, font_weight, font_slant);
	
	long i;
	for (i = 0; i < x->num_tags; i++) {
		t_wordcloud_tag this_tag = x->tag[i];
		double size = this_tag.font_size;
		t_jrgba color = x->mouseclick_tag == i ? j_mousedown_text_color_r : (x->mousemove_tag == i ? j_mouseover_textcolor_r : j_textcolor_r);
		jf = jfont_create_debug(font_name->s_name, (t_jgraphics_font_slant) font_slant, (t_jgraphics_font_weight) font_weight, size);

		write_text(g, jf, color, this_tag.tag->s_name, this_tag.rect.x, this_tag.rect.y, this_tag.rect.width, this_tag.rect.height, JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, false, false);
		
		if (x->underline && x->mousemove_tag == i) {
			double underline_shift = size * 1.05;
			paint_line(g, color, this_tag.rect.x, this_tag.rect.y + underline_shift, 
					   this_tag.rect.x + this_tag.rect.width, this_tag.rect.y + underline_shift, 1. * size / 25.);
		}
		
		jfont_destroy_debug(jf);
	}
	
	paint_border((t_object *)x, g, &rect, &x->j_bordercolor, x->borderwidth, x->corner_roundness);
}

float random_float_in_range(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}



// returns 0 if could draw all tags, 1 if overflow
char do_rebuild_tags(t_wordcloud *x, t_object *view, t_rect rect, t_symbol *font_name, double base_font_size, long font_weight, long font_slant, 
					 double min_drawable_weights, char return_immediately_if_overflow)
{
	double inset_x = 4, inset_y = 3;
	double real_pixel_width = rect.width - 2 * inset_x, real_pixel_height = rect.height - 2 * inset_y;
	double cur_x = 0, cur_y = 0;
	long num_lines = 1;
	double bottommost_y = 0;
	char res = 0;
	double wspace = x->space_between_words;
	t_llllelem *tags_elem, *weights_elem;
	long i = 0;
	double running_max_h = 0;
	
	for (tags_elem = x->tags_as_llll->l_head, weights_elem = x->weights_as_llll->l_head;
		 tags_elem && weights_elem && i < CONST_MAX_TAGS; tags_elem = tags_elem->l_next, weights_elem = weights_elem->l_next) {
		
		double w, h;
		char type = hatom_gettype(&weights_elem->l_hatom);
		double this_weights = (type == H_DOUBLE || type == H_LONG || type == H_RAT) ? hatom_getdouble(&weights_elem->l_hatom) : 1.;
		if (this_weights >= min_drawable_weights) { 
			t_symbol *tag = hatom_gettype(&tags_elem->l_hatom) == H_SYM ? hatom_getsym(&tags_elem->l_hatom) : _llllobj_sym_empty_symbol;
			double font_size = x->min_weights == x->max_weights ? (x->min_font_size + x->max_font_size) / 2. : 
			rescale_with_slope(this_weights, x->autofit ? min_drawable_weights : x->min_weights, x->max_weights, x->min_font_size, x->max_font_size, x->slope);
			t_jfont *jf = jfont_create_debug(font_name->s_name, (t_jgraphics_font_slant) font_slant, (t_jgraphics_font_weight) font_weight, font_size);
			jfont_text_measure(jf, tag->s_name, &w, &h);
			
			if (cur_x + w > real_pixel_width) {
				// new line
				cur_x = 0;
				cur_y += running_max_h;
				running_max_h = h;
				num_lines++;
			} else {
				running_max_h = MAX(running_max_h, h);
			}
			
			x->tag[i].weights = this_weights;
			x->tag[i].tag = tag;
			x->tag[i].font_size = font_size;
			x->tag[i].rect = build_rect(inset_x + cur_x, inset_y + cur_y, w, h);
			x->tag[i].line_num = num_lines;
			
			if (inset_y + cur_y + h > bottommost_y)
				bottommost_y  = inset_y + cur_y + h;
			
			cur_x += w + wspace;
			i++;
			jfont_destroy_debug(jf);
		}
	}
	
	x->num_tags = i;
	
	if (bottommost_y > rect.height) { // overflow
		res = 1;
		if (return_immediately_if_overflow) 
			return res;
	}
	
	// modifying horizontal and line-vertical alignment
	if (true) {
		i = 0;
		long num_line = 1;
		long start_i = 0, end_i = 0;
		double running_max_x = 0, running_max_height = 0, running_max_fontsize = 0, cur_y = 0;
		long running_count = 0;
		while (true) {
			// finding ending index for numline
			while (i < x->num_tags && x->tag[i].line_num <= num_line) {
				cur_y = x->tag[i].rect.y;
				running_count++;
				running_max_x = MAX(running_max_x, x->tag[i].rect.x + x->tag[i].rect.width);
				running_max_fontsize = MAX(running_max_fontsize, x->tag[i].font_size);
				running_max_height = MAX(running_max_height, x->tag[i].rect.height);
				i++;
			}
			end_i = i - 1;
			
			long j;
			double diff = real_pixel_width - running_max_x;
			for (j = start_i; j <= end_i; j++) {
				switch (x->alignment) {
					case 1:	// align center
						x->tag[j].rect.x += diff/2.;
						break;
					case 2: // align right
						x->tag[j].rect.x += diff;
						break;
					case 3: // justified
						if (running_count > 1)
							x->tag[j].rect.x += (j - start_i) * diff/(running_count - 1);
						else
							x->tag[j].rect.x += diff/2.;
						break;
					default: // align left: nothing to do
						break;
				}
			}

			for (j = start_i; j <= end_i; j++) {
				switch (x->line_vertical_alignment) {
					case 1:	// align middle
						x->tag[j].rect.y += (running_max_height - x->tag[j].rect.height) * (0.5 + x->scatter * 0.5 * random_float_in_range(-1, 1));
						break;
					case 2: // align bottom
						x->tag[j].rect.y += (running_max_height - x->tag[j].rect.height) * (1 + x->scatter * random_float_in_range(-1, 0));
						break;
					case 3: // align to text baseline
						x->tag[j].rect.y += (running_max_fontsize - x->tag[j].font_size) * (1 + x->scatter * random_float_in_range(-1, 0));
						break;
					default: // align top: nothing to do
						x->tag[j].rect.y += x->scatter * random_float_in_range(0, 1) * (running_max_height - x->tag[j].rect.height);
						break;
				}
			}
			
			// get ready for next line
			running_max_x = 0;
			running_max_height = 0;
			running_max_fontsize = 0;
			running_count = 0;
			start_i = end_i + 1;
			num_line ++;

			if (start_i >= x->num_tags)
				break;
		}
	}
	
	// modifying global vertical alignment
	// finding bottommost y
	double ydiff = real_pixel_height - bottommost_y;
	if (x->vertical_alignment > 0) {
		switch (x->vertical_alignment) {
			case 1:	// align middle
				for (i = 0; i < x->num_tags; i++) 
					x->tag[i].rect.y += ydiff/2.;
				break;
			case 2: // align bottom
				for (i = 0; i < x->num_tags; i++) 
					x->tag[i].rect.y += ydiff;
				break;
			case 3: // justified
				if (num_lines == 1) {
					for (i = 0; i < x->num_tags; i++) 
						x->tag[i].rect.y += ydiff/2.;
				} else {
					for (i = 0; i < x->num_tags; i++) 
						x->tag[i].rect.y += (x->tag[i].line_num - 1) * ydiff/(num_lines - 1);
				}
				break;
			default: // align top: nothing to do
				break;
		}
	}
	
	return res;
}



void rebuild_tags(t_wordcloud *x, t_object *view, t_rect rect, t_symbol *font_name, double base_font_size, long font_weight, long font_slant)
{
	if (!x->tags_as_llll || x->tags_as_llll->l_size == 0) {
		x->num_tags = 0;
		return;
	}
	
	if (!x->weights_as_llll) 
		x->weights_as_llll = llll_get();
	
	long i;
	for (i = x->weights_as_llll->l_size; i < (long)x->tags_as_llll->l_size; i++)
		llll_appenddouble(x->weights_as_llll, 1., 0, WHITENULL_llll);
	
	t_llllelem *weights_elem;
	x->max_weights = 1;
	x->min_weights = 0;
	char min_defined = false;
	char max_defined = false;
	for (weights_elem = x->weights_as_llll->l_head; weights_elem; weights_elem = weights_elem->l_next) {
		char type = hatom_gettype(&weights_elem->l_hatom);
		if (type == H_DOUBLE || type == H_LONG) {
			double val = hatom_getdouble(&weights_elem->l_hatom);
			if (!max_defined || val > x->max_weights) {
				x->max_weights = val;
				max_defined = true;
			}
			if (!min_defined || val < x->min_weights) {
				x->min_weights = val;
				min_defined = true;
			}
		}
	}
	
	if (x->autofit) {
		// build llll containing min_drawable_weights attempts, depending on the weights histogram
		double min_drawable_weight = x->min_weights;
		double standard_step = (x->max_weights - x->min_weights)/25;
		double idx_step = (x->weights_as_llll->l_size)/40.;
		t_llll *attempts = llll_get();
		t_llllelem *elem;
		
		double d, d_i;
		long j;
		for (d = min_drawable_weight; d < x->max_weights; d += standard_step)
			llll_appenddouble(attempts, d, 0, WHITENULL_llll);
		t_llll *cloned_weights = llll_clone(x->weights_as_llll);
		llll_mergesort_inplace(&cloned_weights, (sort_fn)llll_leq_elem, NULL);
		for (d_i = 0, j = 0, elem = cloned_weights->l_head; elem && d_i < cloned_weights->l_size; ) {
			if (is_hatom_number(&elem->l_hatom))
				llll_appenddouble(attempts, hatom_getdouble(&elem->l_hatom), 0, WHITENULL_llll);
			d_i += idx_step;
			while (j < d_i && j < (long)x->weights_as_llll->l_size) {
				j++;
				elem = elem->l_next;
			}
		}
		llll_free(cloned_weights);
		llll_inplacesort(attempts, (sort_fn)llll_leq_elem);
		attempts = llll_thin_simple(attempts, 0);
//		dev_llll_print(attempts, NULL, 0, 2, NULL);
		
/*		while (do_rebuild_tags(x, view, rect, font_name, base_font_size, font_weight, font_slant, min_drawable_weights, min_drawable_weights <= x->max_weights)
			   && min_drawable_weights < x->max_weights)
			min_drawable_weights += standard_step; */
		elem = attempts->l_head;
		while (do_rebuild_tags(x, view, rect, font_name, base_font_size, font_weight, font_slant, min_drawable_weight, elem->l_next != NULL)
			   && elem->l_next) {
			elem = elem->l_next;
			min_drawable_weight = hatom_getdouble(&elem->l_hatom);
//			dev_post("Testing with minimum weight %.2f", min_drawable_weight);
		}
		
		llll_free(attempts);
	} else {
		do_rebuild_tags(x, view, rect, font_name, base_font_size, font_weight, font_slant, x->min_weights, false);
	}

	x->need_rebuild_tags = false;
}

// The jsave method is called when the patcher is being saved so that we can add custom data (data that is not an attribute)
// to the patcher dictionary.

void wordcloud_jsave(t_wordcloud *x, t_dictionary *d)
{
	if (x->save_data_with_patcher) {
		if (x->j_box.l_dictll) {
			llll_store_in_dictionary(x->j_box.l_dictll, d, "whole_wordcloud_data", NULL);
		} else {
			if (x->tags_as_llll && x->weights_as_llll) {
				t_llll *ll = llll_get();
				llll_appendllll_clone(ll, x->tags_as_llll, 0, WHITENULL_llll, NULL);
				llll_appendllll_clone(ll, x->weights_as_llll, 0, WHITENULL_llll, NULL);
				llll_store_in_dictionary(ll, d, "whole_wordcloud_data", NULL);
				llll_free(ll);
			}
		}
	}
}



void wordcloud_mousemove(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers) {
	long i;
	char is_in_rect = false;
	x->mousemove_tag = -1;
	for (i = 0; i < x->num_tags; i++) {
		is_in_rect = is_pt_in_rectangle(pt, x->tag[i].rect);
		if (is_in_rect) {
			if (x->showhand && !x->cursor_is_hand) {
				jmouse_setcursor(patcherview, (t_object*) x, JMOUSE_CURSOR_POINTINGHAND);
				x->cursor_is_hand = true;
			}
			x->mousemove_tag = i;
			jbox_redraw((t_jbox *)x);
		}
		if (is_in_rect)
			break;
	}
	if (!x->showhand || (!is_in_rect && x->cursor_is_hand)) {
		jmouse_setcursor(patcherview, (t_object*) x, JMOUSE_CURSOR_ARROW);
		x->cursor_is_hand = false;
		jbox_redraw((t_jbox *)x);
	}
}

void wordcloud_mousedown(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers){
	t_symbol *foundsym = NULL;
	long i;

	evnum_incr();

	for (i = 0; i < x->num_tags; i++) {
		if (is_pt_in_rectangle(pt, x->tag[i].rect)) {
			foundsym = x->tag[i].tag;
			x->mouseclick_tag = i;
			jbox_redraw((t_jbox *)x);
			break;
		}
	}
	if (foundsym) 
		llllobj_outlet_anything((t_object *)x, LLLL_OBJ_UI, 0, foundsym, 0, NULL);
}

void wordcloud_mouseup(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers){
	x->mouseclick_tag = -1;
	jbox_redraw((t_jbox *)x);
}


void wordcloud_mouseleave(t_wordcloud *x, t_object *patcherview, t_pt pt, long modifiers) {
	x->mousemove_tag = -1;
	x->mouseclick_tag = -1;
	jbox_redraw((t_jbox *)x);
}
