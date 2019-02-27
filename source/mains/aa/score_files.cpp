/**
	@file
	score_files.c - functions for [bach.score] to deal with files

	by Andrea Agostini
*/

#include "score_files.h"
#include "mxml.h"
#ifdef WIN_VERSION
#include <Shellapi.h>
#include <process.h>
#endif

#define CONST_DYNAMICS_TEXT_ALLOC_SIZE 2048

void score_doread(t_score *x, t_symbol *s, long argc, t_atom *argv);

t_max_err score_dowritexml(const t_score *score, t_symbol *s, long ac, t_atom *av);
t_llll *score_readxml(t_score *x,
                      t_filehandle fh,
                      long parenthesizedquartertones,
                      long lyricsslot,
                      long noteheadslot,
                      long articulationsslot,
                      long dynamicsslot,
                      long directionsslot);

t_max_err score_dowritemidi(t_score *x, t_symbol *s, long ac, t_atom *av);
t_max_err score_dowritelilypond(t_score *x, t_symbol *s, long ac, t_atom *av);
t_max_err score_dowritelilypond_pdf(t_score *x, t_symbol *s, long ac, t_atom *av);

mxml_node_t *bach_mxmlNewTextElement(mxml_node_t *parent, const char *name, int whitespace, const char *string);
mxml_node_t *bach_mxmlNewIntElement(mxml_node_t *parent, const char *name, int whitespace, int value);
mxml_node_t *bach_mxmlNewRealElement(mxml_node_t *parent, const char *name, int whitespace, double value);
const char *whitespace_cb(mxml_node_t *node, int where);
long timesignature_eq(t_timesignature *a, t_timesignature *b);
const char *bach_xml_acc2name(t_rational acc, long *mc_alter);
void xml_value_to_name(long den, char *chordtype);
t_rational xml_name_and_dots_to_value(const char *chordtype, long dots);
mxml_node_t *bach_xml_add_clef(mxml_node_t *node, const char *sign, long line, long octave, const char *number);
void bach_xml_add_ornament(const t_articulations_typo_preferences *atp, mxml_node_t **ornaments, mxml_node_t *notations, long id);
void bach_xml_add_technical_or_articulation(const t_articulations_typo_preferences *atp, mxml_node_t **technical, mxml_node_t **articulations, mxml_node_t *notations, long id, char mode);

mxml_type_t xml_load_cb(mxml_node_t *node);

long rat2ticks(const t_rational *pos, long time_division);
t_rational get_play_durations_between_timepoints(t_score *x, t_scorevoice *voice, t_timepoint *tp1, t_timepoint *tp2);
t_rational normalize_timepoint(t_score *x, t_timepoint *tp);
void strip_final_ws(char *text);
char strip_cresc_decresc(char *text);


const char* const xml_accepted_dynamics[] = { "p", "pp", "ppp", "pppp", "ppppp", "pppppp", "f", "ff", "fff", "ffff", "fffff", "ffffff", "mp", "mf", "sf", "sfp", "sfpp", "fp", "rf", "rfz", "sfz", "sffz", "fz", "0", "n"};
long num_xml_accepted_dynamics = sizeof(xml_accepted_dynamics)/sizeof(xml_accepted_dynamics[0]);




// **********************************************
// import-export
// **********************************************

void score_xml_add_clefs(mxml_node_t *attributesxml, long clef, long *staves, long *splitpoints)
{
    // CLEFS
    switch (clef) {
        case k_CLEF_F:
            bach_xml_add_clef(attributesxml, "F", 4, 0, NULL);
            break;
        case k_CLEF_G8va:
            bach_xml_add_clef(attributesxml, "G", 2, 1, NULL);
            break;
        case k_CLEF_G15ma:
            bach_xml_add_clef(attributesxml, "G", 2, 2, NULL);
            break;
        case k_CLEF_F8vb:
            bach_xml_add_clef(attributesxml, "F", 4, -1, NULL);
            break;
        case k_CLEF_F15mb:
            bach_xml_add_clef(attributesxml, "F", 4, -1, NULL);
            break;
        case k_CLEF_SOPRANO:
            bach_xml_add_clef(attributesxml, "C", 5, 0, NULL);
            break;
        case k_CLEF_MEZZO:
            bach_xml_add_clef(attributesxml, "C", 4, 0, NULL);
            break;
        case k_CLEF_ALTO:
            bach_xml_add_clef(attributesxml, "C", 3, 0, NULL);
            break;
        case k_CLEF_TENOR:
            bach_xml_add_clef(attributesxml, "C", 2, 0, NULL);
            break;
        case k_CLEF_BARYTONE:
            bach_xml_add_clef(attributesxml, "C", 1, 0, NULL);
            break;
        case k_CLEF_FF:
            *staves = 2;
            splitpoints[0] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "F", 4, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "2");
            break;
        case k_CLEF_FG:
            *staves = 2;
            splitpoints[0] = 6000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "2");
            break;
        case k_CLEF_GG:
            *staves = 2;
            splitpoints[0] = 7900;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "G", 2, 2, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            break;
        case k_CLEF_FFG:
            *staves = 3;
            splitpoints[0] = 6000;
            splitpoints[1] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 3);
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "3");
            break;
        case k_CLEF_FGG:
            *staves = 3;
            splitpoints[0] = 7900;
            splitpoints[1] = 6000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 3);
            bach_xml_add_clef(attributesxml, "G", 2, 1, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "3");
            break;
        case k_CLEF_FFGG:
            *staves = 4;
            splitpoints[0] = 7900;
            splitpoints[1] = 6000;
            splitpoints[2] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 4);
            bach_xml_add_clef(attributesxml, "G", 2, 1, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "3");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "4");
            break;
        case k_CLEF_G:
        default:
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            break;
    }
}


void score_exportxml(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom av;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&av, arguments);
	defer(x, (method)score_dowritexml, s, 1, &av);
}

void score_read_singlesymbol(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom a;
    char *text = NULL;
    long size;
    atom_gettext_debug(argc, argv, &size, &text, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
    if (size > 0) {
        t_llll *arguments = llll_get();
        t_symbol *s = gensym(text);
        llll_appendsym(arguments, s);
        bach_freeptr(text);
        atom_setobj(&a, arguments);
        defer((t_object *) x, (method) score_doread, s, 1, &a);
    }
}

void score_read(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom a;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	//llll_retain(arguments);
	atom_setobj(&a, arguments);
	defer((t_object *) x, (method) score_doread, s, 1, &a);
}

void score_doread(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_llll *arguments = (t_llll *) atom_getobj(argv);
	t_symbol *filename_sym = NULL;
	t_filehandle fh = NULL;
	t_fourcc outtype = 0;
	t_fourcc file_types[] = {'TEXT', 'LLLL'};
	t_llll *score_ll = NULL;
	char testbuf[11];
	t_ptr_size count = 11;
	e_undo_operations undo_op = k_UNDO_OP_UNKNOWN;
	short path;
	char filename[2048];
	t_dictionary *dict = NULL;
	
    long parenthesizedquartertones = 0;
    long lyricsslot = x->r_ob.link_lyrics_to_slot;
    long noteheadslot = x->r_ob.link_notehead_to_slot;
    long articulationsslot = x->r_ob.link_articulations_to_slot;
    long dynamicsslot = x->r_ob.link_dynamics_to_slot;
    long import_lyrics = 1, import_noteheads = 1, import_articulations = 1, import_dynamics = 1, directionsslot = 0;

	llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiiiiiii",
				   gensym("filename"), &filename_sym,
                   gensym("parenthesizedquartertones"), &parenthesizedquartertones,
                   gensym("importlyrics"), &lyricsslot,
                   gensym("importnoteheads"), &noteheadslot,
                   gensym("importarticulations"), &articulationsslot,
                   gensym("lyrics"), &import_lyrics,
                   gensym("noteheads"), &import_noteheads,
                   gensym("articulations"), &import_articulations,
                   gensym("dynamics"), &import_dynamics,
                   gensym("directionsslot"), &directionsslot
                   );
    
    if (!import_lyrics)
        lyricsslot = 0;
    if (!import_noteheads)
        noteheadslot = 0;
    if (!import_articulations)
        articulationsslot = 0;
    if (!import_dynamics)
        dynamicsslot = 0;

    if (arguments->l_size >= 1 && hatom_gettype(&arguments->l_head->l_hatom) == H_SYM) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        llll_behead(arguments);
    }
    

	if (bach_openfile_for_read((t_object *) x, filename_sym, &path, file_types, 2, &outtype, filename) != MAX_ERR_NONE) {
		object_error((t_object *) x, "Can't open file");
		goto score_doread_error_dontclose;
	}
	
	if (*filename == 0)
		goto score_doread_error_dontclose;

	if (dictionary_read(filename, path, &dict) == MAX_ERR_NONE) {
		score_ll = llll_retrieve_from_dictionary(dict, "data");
		object_free(dict);
		undo_op = k_UNDO_OP_READ_SCORE;
	} else {
		if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
			goto score_doread_error_dontclose;
		// let's try to guess if it's xml
		sysfile_read(fh, &count, testbuf);
		sysfile_setpos(fh, SYSFILE_FROMSTART, 0);
		if ((count > 5 && !memcmp(testbuf, "<?xml", 5)) || // plain text
			(count > 8 && !memcmp(testbuf, "\xef\xbb\xbf<?xml", 8)) || // utf-8
			(count > 10 && (!memcmp(testbuf, "\xff\xfe\x3c\x00\x3f\x00\x78\x00\x6d\x00", 10) || // utf-16 little-endian
							!memcmp(testbuf, "\xfe\xff\x00\x3c\x00\x3f\x00\x78\x6d\x00", 10)))) { // utf-16 big-endian
			score_ll = score_readxml(x, fh, parenthesizedquartertones, lyricsslot, noteheadslot, articulationsslot, dynamicsslot, directionsslot);
			undo_op = k_UNDO_OP_IMPORT_XML_SCORE;
		} else {
			score_ll = llll_readfile((t_object *) x, fh);

		}
	}
	if (score_ll) {
		set_score_from_llll_from_read(x, score_ll);
		llll_free(score_ll);
		handle_rebuild_done((t_notation_obj *) x);
		handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER, undo_op);
	} else {
		object_error((t_object *) x, "File doesn't contain a score");
		goto score_doread_error_close;
	}
	
score_doread_error_dontclose:
	llll_free(arguments);
	return;
score_doread_error_close:
    if (fh)
        sysfile_close(fh);
	llll_free(arguments);
	return;
}

void score_write(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_llll *score_as_llll;
	t_symbol *filename = NULL;
	if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
		filename = atom_getsym(argv);
	score_as_llll = get_score_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, x->r_ob.write_trees, x->r_ob.write_trees && x->r_ob.output_and_save_level_types, true, false); // we save the clefs as well
	llll_writenative((t_object *) x, filename, score_as_llll);
} 

void score_writetxt(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *score_as_llll = get_score_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, x->r_ob.write_trees, x->r_ob.write_trees && x->r_ob.output_and_save_level_types, true, false); // we save the clefs as well
	llll_writetxt((t_object *) x, score_as_llll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART);
}

void score_exportom(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *score_as_llll_for_om = get_score_values_as_llll(x, k_CONSIDER_FOR_EXPORT_OM, k_HEADER_ALL, false, false, true, false);
	llll_writetxt((t_object *) x, score_as_llll_for_om, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

void score_exportpwgl(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *score_as_llll_for_pwgl = get_score_values_as_llll_for_pwgl(x);
	llll_writetxt((t_object *) x, score_as_llll_for_pwgl, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

void score_exportmidi(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom av;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&av, arguments);
	defer(x, (method) score_dowritemidi, s, 1, &av);
}


void score_exportlilypond(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom av;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&av, arguments);
	defer(x, (method) score_dowritelilypond, s, 1, &av);
}

void score_exportlilypond_pdf(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom av;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&av, arguments);
	defer(x, (method) score_dowritelilypond_pdf, s, 1, &av);
}

t_llll *score_parse_articulations_to_llll(t_score *x, mxml_node_t *notationsXML, long articulationsslot)
{
    t_llll *articulationsll = llll_get();
    /* <!ELEMENT ornaments
     (((trill-mark | turn | delayed-turn | inverted-turn |
     delayed-inverted-turn | vertical-turn | shake |
     wavy-line | mordent | inverted-mordent | schleifer |
     tremolo | other-ornament), accidental-mark*)*)>
     */
    mxml_node_t *ornamentsXML;
    for (ornamentsXML = mxmlFindElement(notationsXML, notationsXML, "ornaments", NULL, NULL, MXML_DESCEND_FIRST);
         ornamentsXML;
         ornamentsXML = mxmlFindElement(ornamentsXML, notationsXML, "ornaments", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_ornamentXML;
        for (this_ornamentXML = mxmlWalkNext(ornamentsXML, ornamentsXML, MXML_DESCEND_FIRST);
             this_ornamentXML;
             this_ornamentXML = mxmlWalkNext(this_ornamentXML, ornamentsXML, MXML_NO_DESCEND)) {
            char *ornament_txt = NULL;
            if (this_ornamentXML->type == MXML_ELEMENT)
                ornament_txt = this_ornamentXML->value.element.name;
            if (ornament_txt) {
                if (!strcmp(ornament_txt, "trill-mark"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TRILL), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "turn") ||
                         !strcmp(ornament_txt, "delayed-turn") ||
                         !strcmp(ornament_txt, "vertical-turn") ||
                         !strcmp(ornament_txt, "inverted-turn") ||
                         !strcmp(ornament_txt, "delayed-inverted-turn"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_GRUPPETTO), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_UP), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "inverted-mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_DOWN), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "wavy-line"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_DOUBLE_MORDENT), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "tremolo")) {
                    switch (mxmlGetInteger(this_ornamentXML)) {
                        case 1:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO1), 0, WHITENULL_llll);
                            break;
                        case 2:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO2), 0, WHITENULL_llll);
                            break;
                        default:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO3), 0, WHITENULL_llll);
                            break;
                    }
                }
            }
        }
    }
    
    
    /*
     <!ELEMENT technical
     ((up-bow | down-bow | harmonic | open-string |
     thumb-position | fingering | pluck | double-tongue |
     triple-tongue | stopped | snap-pizzicato | fret |
     string | hammer-on | pull-off | bend | tap | heel |
     toe | fingernails | hole | arrow | handbell |
     other-technical)*)>
     */
    
    mxml_node_t *technicalXML;
    for (technicalXML = mxmlFindElement(notationsXML, notationsXML, "technical", NULL, NULL, MXML_DESCEND_FIRST);
         technicalXML;
         technicalXML = mxmlFindElement(technicalXML, notationsXML, "technical", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_technicalXML;
        for (this_technicalXML = mxmlWalkNext(technicalXML, technicalXML, MXML_DESCEND_FIRST);
             this_technicalXML;
             this_technicalXML = mxmlWalkNext(this_technicalXML, technicalXML, MXML_NO_DESCEND)) {
            char *technical_txt = NULL;
            if (this_technicalXML->type == MXML_ELEMENT)
                technical_txt = this_technicalXML->value.element.name;
            if (technical_txt) {
                if (!strcmp(technical_txt, "harmonic"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_HARMONIC), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "up-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_UP), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "down-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_DOWN), 0, WHITENULL_llll);
            }
        }
    }
    
    
    /*
     <!ELEMENT articulations
     ((accent | strong-accent | staccato | tenuto |
     detached-legato | staccatissimo | spiccato |
     scoop | plop | doit | falloff | breath-mark |
     caesura | stress | unstress | other-articulation)*)>
     */

    mxml_node_t *articulationsXML;
    for (articulationsXML = mxmlFindElement(notationsXML, notationsXML, "articulations", NULL, NULL, MXML_DESCEND_FIRST);
         articulationsXML;
         articulationsXML = mxmlFindElement(articulationsXML, notationsXML, "articulations", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_articulationsXML;
        for (this_articulationsXML = mxmlWalkNext(articulationsXML, articulationsXML, MXML_DESCEND_FIRST);
             this_articulationsXML;
             this_articulationsXML = mxmlWalkNext(this_articulationsXML, articulationsXML, MXML_NO_DESCEND)) {
            char *articulations_txt = NULL;
            if (this_articulationsXML->type == MXML_ELEMENT)
                articulations_txt = this_articulationsXML->value.element.name;
            if (articulations_txt) {
                if (!strcmp(articulations_txt, "staccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "accent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_ACCENT), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tenuto"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_PORTATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "staccatissimo"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATISSIMO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "spiccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MARTELLATO), 0, WHITENULL_llll);
            }
        }
    }
    
    /*
     <!ELEMENT fermata  (#PCDATA)>
     */
    mxml_node_t *fermataXML = mxmlFindElement(notationsXML, notationsXML, "fermata", NULL, NULL, MXML_DESCEND_FIRST);
    if (fermataXML) {
        llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_FERMATA), 0, WHITENULL_llll);
    }
    
    if (articulationsll->l_size > 0) {
        llll_prependlong(articulationsll, articulationsslot);
    } else {
        llll_free(articulationsll);
        articulationsll = NULL;
    }
    return articulationsll;
}

long xmlwrite_notehead_manage_filled(mxml_node_t *noteXML, mxml_node_t *noteheadXML,
                                      long filledID, long nonfilledID, long autoID)
{
    long noteheadID;
    mxml_node_t *filledXML = mxmlFindElement(noteheadXML, noteXML, "notehead", "filled", NULL, MXML_DESCEND_FIRST);
    if (filledXML) {
        const char *filledtxt = mxmlGetText(filledXML, NULL);
        if (!strcmp(filledtxt, "yes")) {
            noteheadID = filledID;
        } else if (!strcmp(filledtxt, "no")) {
            noteheadID = nonfilledID;
        } else
            noteheadID = autoID;
    } else
        noteheadID = autoID;
    return noteheadID;
}


void xmlwrite_open_hairpin(mxml_node_t *measureXML, char hairpin, char *currently_open_hairpin, long offset)
{
    mxml_node_t *hairpin_directionxml = NULL;
    mxml_node_t *hairpin_direction_typexml = NULL;
    mxml_node_t *wedge_xml = NULL;
    hairpin_directionxml = mxmlNewElement(measureXML, "direction");
    hairpin_direction_typexml = mxmlNewElement(hairpin_directionxml, "direction-type");
    wedge_xml = mxmlNewElement(hairpin_direction_typexml, "wedge");
    mxmlElementSetAttr(hairpin_directionxml, "placement", "below");
    mxmlElementSetAttr(wedge_xml, "type", hairpin > 0 ? "crescendo" : "diminuendo");
    if (currently_open_hairpin)
        *currently_open_hairpin = hairpin;

    if (offset)
        bach_mxmlNewIntElement(hairpin_directionxml, "offset", 0, offset);
}

void xmlwrite_close_hairpin(mxml_node_t *measureXML, char *currently_open_hairpin, long offset)
{
    mxml_node_t *hairpin_directionxml = NULL;
    mxml_node_t *hairpin_direction_typexml = NULL;
    mxml_node_t *wedge_xml = NULL;
    hairpin_directionxml = mxmlNewElement(measureXML, "direction");
    hairpin_direction_typexml = mxmlNewElement(hairpin_directionxml, "direction-type");
    wedge_xml = mxmlNewElement(hairpin_direction_typexml, "wedge");
    mxmlElementSetAttr(hairpin_directionxml, "placement", "below");
    mxmlElementSetAttr(wedge_xml, "type", "stop");
    if (currently_open_hairpin)
        *currently_open_hairpin = 0;

    if (offset)
        bach_mxmlNewIntElement(hairpin_directionxml, "offset", 0, offset);
}

void xmlwrite_add_dynamics(mxml_node_t *measureXML, char *text, long offset)
{
    mxml_node_t *directionxml = mxmlNewElement(measureXML, "direction");
    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
    mxml_node_t *dynamics_xml = mxmlNewElement(direction_typexml, "dynamics");
    mxmlElementSetAttr(directionxml, "placement", "below");
    
    if (!strcmp(text, "p") ||
        !strcmp(text, "pp") ||
        !strcmp(text, "ppp") ||
        !strcmp(text, "pppp") ||
        !strcmp(text, "ppppp") ||
        !strcmp(text, "pppppp") ||
        !strcmp(text, "f") ||
        !strcmp(text, "ff") ||
        !strcmp(text, "fff") ||
        !strcmp(text, "ffff") ||
        !strcmp(text, "fffff") ||
        !strcmp(text, "ffffff") ||
        !strcmp(text, "mp") ||
        !strcmp(text, "mf") ||
        !strcmp(text, "sf") ||
        !strcmp(text, "sfp") ||
        !strcmp(text, "sfpp") ||
        !strcmp(text, "fp") ||
        !strcmp(text, "rf") ||
        !strcmp(text, "rfz") ||
        !strcmp(text, "sfz") ||
        !strcmp(text, "sffz") ||
        !strcmp(text, "fz")) {
        mxmlElementSetAttr(directionxml, "placement", "below");
        mxmlNewElement(dynamics_xml, text);
    } else
        bach_mxmlNewTextElement(dynamics_xml, "other-dynamics", 0, text);
    
    if (offset)
        bach_mxmlNewIntElement(directionxml, "offset", 0, offset);
}


void xml_get_dynamics(mxml_node_t *from_this_node, mxml_node_t *stop_at_this_node, char *dynamics_text)
{
    mxml_node_t *tempXML = from_this_node;
    long dynamics_text_cur = 0;
    dynamics_text[0] = 0;
    
    while (tempXML && tempXML != stop_at_this_node) {
        mxml_node_t *dynamicXML = NULL, *wedgeXML = NULL;
        if ((dynamicXML = mxmlFindElement(tempXML, tempXML, "dynamics", NULL, NULL, MXML_DESCEND))) {
            
            for (long di = 0; di < num_xml_accepted_dynamics; di++) {
                if (mxmlFindElement(dynamicXML, dynamicXML, xml_accepted_dynamics[di], NULL, NULL, MXML_DESCEND_FIRST))
                    dynamics_text_cur += snprintf_zero(dynamics_text + dynamics_text_cur, CONST_DYNAMICS_TEXT_ALLOC_SIZE - dynamics_text_cur, "%s_", xml_accepted_dynamics[di]);
            }
            if (*dynamics_text == 0) {
                dynamics_text[0] = '=';
                dynamics_text[1] = 0;
            }
                
            
        } else if ((wedgeXML = mxmlFindElement(tempXML, tempXML, "wedge", NULL, NULL, MXML_DESCEND))) {
            char hairpin = 0;
            const char *wedgetypetxt = mxmlElementGetAttr(wedgeXML, "type");
            if (!strcmp(wedgetypetxt, "crescendo"))
                hairpin = 1;
            else if (!strcmp(wedgetypetxt, "diminuendo"))
                hairpin = -1;
            if (hairpin){
                if (dynamics_text_cur > 0 && dynamics_text_cur <= CONST_DYNAMICS_TEXT_ALLOC_SIZE && dynamics_text[dynamics_text_cur - 1] == '=') {
                    dynamics_text[dynamics_text_cur - 1] = 0;
                    dynamics_text_cur--;
                }
                if (dynamics_text_cur < CONST_DYNAMICS_TEXT_ALLOC_SIZE)
                    dynamics_text[dynamics_text_cur++] = (hairpin > 0 ? '<' : '>');
            }
        }
        tempXML = tempXML->next;
    }
    
    if (dynamics_text_cur > 0 && dynamics_text_cur <= CONST_DYNAMICS_TEXT_ALLOC_SIZE && dynamics_text[dynamics_text_cur - 1] == '=') {
        dynamics_text[dynamics_text_cur - 1] = 0;
        dynamics_text_cur--;
    }
}

t_llll *xml_get_words(mxml_node_t *from_this_node, mxml_node_t *stop_at_this_node, t_llll *words)
{
    mxml_node_t *tempXML = from_this_node;
    if (!words)
        words = llll_get();
    while (tempXML && tempXML != stop_at_this_node) {
        mxml_node_t *wordsXML = NULL;
        if ((wordsXML = mxmlFindElement(tempXML, tempXML, "words", NULL, NULL, MXML_DESCEND))) {
            const char *wordstxt = mxmlGetOpaque(wordsXML);
            if (wordstxt)
                llll_appendsym(words, gensym(wordstxt));
        }
        tempXML = tempXML->next;
    }
    return words;
}

t_shortRational xml_get_accidental(mxml_node_t *accXML)
{
    t_shortRational alter;
    if (!accXML)
        return t_pitch::natural;
    const char *accidentaltxt = mxmlGetText(accXML, NULL);
    
    if (!strcmp(accidentaltxt, "sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural"))
        alter = t_pitch::natural;
    else if (!strcmp(accidentaltxt, "flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "double-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "flat-flat"))
        alter = 2 * t_pitch::flat;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "natural-sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural-flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "quarter-flat"))
        alter = t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "quarter-sharp"))
        alter = t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "three-quarters-flat"))
        alter = t_pitch::flat +  t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "three-quarters-sharp"))
        alter = t_pitch::sharp + t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "sharp-down"))
        alter = t_pitch::qrtrsharp - t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "sharp-up"))
        alter = t_pitch::qrtrsharp + t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "natural-down"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "natural-up"))
        alter = t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "flat-down"))
        alter = t_pitch::qrtrflat + t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "flat-up"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "triple-sharp"))
        alter = 3 * t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "triple-flat"))
        alter = 3 * t_pitch::flat;
    else
        alter = t_pitch::natural;
    return alter;
}



class timedThing {
private:
    typedef enum _timedThingType {
        note,
        dynamics
    } timedThingType;
    
public:
    timedThingType type;
    t_rational timePos;
    double xPosition;
    t_llll *notell;
    const char* dyn;
    
    timedThing(t_llll *notell, t_rational timePos, double xPosition) : type(note), timePos(timePos), xPosition(xPosition), notell(notell), dyn(nullptr) { }
    
    timedThing(const char* dyn, t_rational timePos, double xPosition) : type(dynamics), timePos(timePos), xPosition(xPosition), notell(nullptr), dyn(dyn) { }
    
    t_bool isNote() { return type == note; }
    t_bool isDynamics() { return type == dynamics; }
};



t_llll *score_readxml(t_score *x,
                      t_filehandle fh,
                      long parenthesizedquartertones,
                      long lyricsslot,
                      long noteheadslot,
                      long articulationsslot,
                      long dynamicsslot,
                      long directionsslot)
{
	t_ptr_size size;
	unsigned char *buffer;
    long new_tonedivision = 2;
    t_llll *maintempo_ll = NULL;
    
	// allocate memory block that is the size of the file
	sysfile_geteof(fh, &size);
	buffer = (unsigned char *) sysmem_newptr(size + 2);
	if (!buffer) {
		object_error((t_object *) x, "File too long");
		return NULL;
	}
    buffer[0] = 0;
	// read in the file
	sysfile_read(fh, &size, buffer);
	sysfile_close(fh);
	*(buffer + size) = 0;
	*(buffer + size + 1) = 0;
/*
	if (*buffer >= 0xfe) {
		long convlen = 0;
		char *convbuf = charset_unicodetoutf8((unsigned short *) buffer, 0, &convlen);
		sysmem_freeptr(buffer);
		if (!convbuf) {
			object_error((t_object *) x, "bad file");
			return NULL;
		}
		buffer = (unsigned char *) convbuf;
	}
*/
	mxml_node_t *scoreXML = mxmlLoadString(NULL, (char *) buffer, xml_load_cb);
	sysmem_freeptr(buffer);
	
	mxml_node_t *score_partwiseXML = mxmlFindElement(scoreXML, scoreXML, "score-partwise", NULL, NULL, MXML_DESCEND_FIRST);
	if (!score_partwiseXML) {
		object_error((t_object *) x, "File is not a partwise MusicXML!");
		return NULL;
	}
	t_llll *scorell = llll_get();
	llll_appendsym(scorell, _llllobj_sym_score, 0, WHITENULL_llll);
	
	// parse all the header stuff
	mxml_node_t *part_listXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part-list", NULL, NULL, MXML_DESCEND_FIRST);
	if (!part_listXML) {
		object_error((t_object *) x, "Missing <part-list> tag");
		llll_free(scorell);
		return NULL;
	}
	
	t_llll *clefsll = llll_get();
	llll_appendsym(clefsll, _llllobj_sym_clefs, 0, WHITENULL_llll);
	llll_appendllll(scorell, clefsll, 0, WHITENULL_llll);
	
	t_llll *keysll = llll_get();
	llll_appendsym(keysll, _llllobj_sym_keys, 0, WHITENULL_llll);
	llll_appendllll(scorell, keysll, 0, WHITENULL_llll);
    
    t_llll *numpartsll = llll_get();
    llll_appendsym(numpartsll, _llllobj_sym_numparts, 0, WHITENULL_llll);
    llll_appendllll(scorell, numpartsll);

	// iterate on the parts
	mxml_node_t *partXML;
    long partnum = 1; // for debug
	for (partXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part", NULL, NULL, MXML_DESCEND_FIRST);
		 partXML;
		 partXML = mxmlFindElement(partXML, score_partwiseXML, "part", NULL, NULL, MXML_NO_DESCEND), partnum++) {
	
        t_llll *voicell[CONST_MAX_VOICES];
        voicell[0] = llll_get();
        voicell[1] = llll_get();
        
        long voices_for_this_xml_part = 1;
        
        
		long divisions = 0;
		long velocity = 90;
		t_llll *timell = NULL;
		t_llll *tempill = NULL;
		// iterate on the measures for this part
		mxml_node_t *measureXML;
		long isfirstmeasure = 1;
		long measure_number = 1;
        
        char dynamics_text[CONST_DYNAMICS_TEXT_ALLOC_SIZE];
        
        dynamics_text[0] = 0;
        t_llll *words = NULL;
        t_symbol *clefsym, *keysym;
        
        t_rational global_position = t_rational(0);
        t_llll *all_elements_ll = llll_get();
        
		for (measureXML = mxmlFindElement(partXML, partXML, "measure", NULL, NULL, MXML_DESCEND_FIRST);
			 measureXML;
			 measureXML = mxmlFindElement(measureXML, partXML, "measure", NULL, NULL, MXML_NO_DESCEND), measure_number++) {
            
            t_llll *measurell[CONST_MAX_VOICES];
            t_rational used_duration[CONST_MAX_VOICES];

            for (long i = 0; i <= voices_for_this_xml_part; i++) {
                measurell[i] = llll_get();
                used_duration[i] = t_rational(0);
            }

            t_rational current_timepoint = t_rational(0);
            
			t_llll *measureinfoll = llll_get();
			mxml_node_t *attributesXML = mxmlFindElement(measureXML, measureXML, "attributes", NULL, NULL, MXML_DESCEND_FIRST);
			// parse the attributes:
			if (attributesXML) {
				if (isfirstmeasure) {
					
					// clef
					long numclefs;
					long top_clef = k_CLEF_G, bottom_clef = k_CLEF_G, clef = k_CLEF_G;
					mxml_node_t *clefXML;
					for (numclefs = 0, clefXML = mxmlFindElement(attributesXML, attributesXML, "clef", NULL, NULL, MXML_DESCEND_FIRST);
						 clefXML && numclefs < 16;
						 numclefs++, clefXML = mxmlFindElement(clefXML, attributesXML, "clef", NULL, NULL, MXML_NO_DESCEND)) {
						mxml_node_t *signXML = mxmlFindElement(clefXML, clefXML, "sign", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *lineXML = mxmlFindElement(clefXML, clefXML, "line", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *clef_octave_changeXML = mxmlFindElement(clefXML, clefXML, "clef-octave-change", NULL, NULL, MXML_DESCEND_FIRST);
						const char *sign = "";
						long line = -1, clef_octave_change = 0;
						long this_clef = k_CLEF_G;
						if (signXML)
							sign = mxmlGetText(signXML, 0);
						if (lineXML)
							line = mxmlGetInteger(lineXML);
						if (clef_octave_changeXML)
							clef_octave_change = mxmlGetInteger(clef_octave_changeXML);
						if (!strcmp(sign, "G")) {
							if (clef_octave_change == 1)		this_clef = k_CLEF_G8va;
							else if (clef_octave_change > 1)	this_clef = k_CLEF_G15ma;
							else								this_clef = k_CLEF_G;
						} else if (!strcmp(sign, "F")) {
							if (line == 3)
								this_clef = k_CLEF_BARYTONE;
							else {
								if (clef_octave_change == -1)		this_clef = k_CLEF_F8vb;
								else if (clef_octave_change < -1)	this_clef = k_CLEF_F15mb;
								else								this_clef = k_CLEF_F;
							}
						} else if (!strcmp(sign, "C")) {
							switch (line) {
								case 1:		this_clef = k_CLEF_SOPRANO;	break;
								case 2:		this_clef = k_CLEF_MEZZO;	break;
								case 3:		this_clef = k_CLEF_ALTO;	break;
								case 4:		this_clef = k_CLEF_TENOR;	break;
								default:	this_clef = k_CLEF_MEZZO;	break;
							}
						} else if (!strcmp(sign, "percussion")) {
							this_clef = k_CLEF_PERCUSSION;
						} else {
							this_clef = k_CLEF_NONE;
						}
						
						if (numclefs == 0 || (this_clef > k_CLEF_PERCUSSION && this_clef < top_clef))
							top_clef = this_clef;
						if (numclefs == 0 || this_clef > bottom_clef)
							bottom_clef = this_clef;
					}
					// k_CLEF_PERCUSSION and k_CLEF_NO can only exist if top_clef and bottom_clef are the same 
					if (top_clef == bottom_clef) {
						clef = top_clef;
					} else {
						if (top_clef <= k_CLEF_G8va) {
							if (bottom_clef <= k_CLEF_G)
								clef = k_CLEF_GG;
							else if (bottom_clef <= k_CLEF_F)
								clef = k_CLEF_FGG;
							else
								clef = k_CLEF_FFGG;
						} else if (top_clef == k_CLEF_G) {
							if (bottom_clef <= k_CLEF_F)
								clef = k_CLEF_FG;
							else
								clef = k_CLEF_FFG;						
						} else
							clef = k_CLEF_FF;
					}
                    clefsym = clef_number_to_clef_symbol((t_notation_obj *) x, clef);
					//llll_appendsym(clefsll, clefsym, 0, WHITENULL_llll);

                    //dev_llll_print(clefsll);
					// key signature
					
					mxml_node_t *keyXML = mxmlFindElement(attributesXML, attributesXML, "key", NULL, NULL, MXML_DESCEND_FIRST);
					if (keyXML) {
						mxml_node_t *fifthsXML = mxmlFindElement(keyXML, keyXML, "fifths", NULL, NULL, MXML_DESCEND_FIRST);
						if (fifthsXML) {
							long fifths = mxmlGetInteger(fifthsXML);
							e_modes mode = k_MODE_MAJOR;
							mxml_node_t *modeXML = mxmlFindElement(keyXML, keyXML, "mode", NULL, NULL, MXML_DESCEND_FIRST);
							const char *mode_txt = mxmlGetText(modeXML, NULL);
							if (mode_txt && !strcmp(mode_txt, "minor"))
								mode = k_MODE_MINOR;
							keysym = key_and_mode_to_sym((t_notation_obj *) x, fifths, mode, NULL);
                            // we're gonna append this later
						} else {
							t_rational acc_pattern[7];
							long i;
							for (i = 0; i < 7; i++)
								acc_pattern[i] = long2rat(0);
							mxml_node_t *key_stepXML; 
							for (key_stepXML = mxmlFindElement(keyXML, keyXML, "key-step", NULL, NULL, MXML_DESCEND_FIRST);
								 key_stepXML;
								 key_stepXML = mxmlFindElement(key_stepXML, key_stepXML, "key-step", NULL, NULL, MXML_NO_DESCEND)) {
								mxml_node_t *key_alterXML = mxmlFindElement(key_stepXML, key_stepXML, "key-alter", NULL, NULL, MXML_NO_DESCEND);
								double alter_dbl = mxmlGetReal(key_alterXML);
								char key_char = mxmlGetText(key_stepXML, NULL)[0];
								key_char = key_char >= 'a' ? key_char - 'a' : key_char - 'A';
								long step = (key_char + 5) % 7;
								acc_pattern[step] = approx_double_with_rat_fixed_den(alter_dbl, 100, 1, NULL);
							}
                            keysym = key_and_mode_to_sym((t_notation_obj *) x, 0, k_MODE_NONSTANDARD, acc_pattern);
                            // we're gonna append this later
						}
                    } else {
                        keysym = gensym("CM");
                        // we're gonna append this later
                    }

				}
				
				// time signature
				timell = llll_get(); // if an old one was present, it is already a grandchild of measurell
				t_llll *timenumll = llll_get();
				mxml_node_t *timeXML = mxmlFindElement(attributesXML, attributesXML, "time", NULL, NULL, MXML_DESCEND_FIRST);
				mxml_node_t *beatsXML, *beat_typeXML;
				//= mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
				//mxml_node_t *beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
				long beat_den = 1;
				// first find lcm
				for (beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
					 beat_typeXML;
					 beat_typeXML = mxmlFindElement(beat_typeXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND)) {
					if (mxmlFindElement(beat_typeXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
						break;
					beat_den = lcm(beat_den, mxmlGetInteger(beat_typeXML));
				}
				long beat_type = 0;
				long beats = 1;
				if (beat_den == 0) { // which means that one of the beat_types is 0 - thus we prevent division by 0 below
					object_error((t_object *) x, "Bad time signature");
				} else {
					for (beatsXML = mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
						 beatsXML;
						 beatsXML = mxmlFindElement(beatsXML, timeXML, "beats", NULL, NULL, MXML_NO_DESCEND)) {
						if (mxmlFindElement(beatsXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
							break;
						beat_typeXML = mxmlFindElement(beatsXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND);
						if (!beat_typeXML)
							break;
						beat_type = mxmlGetInteger(beat_typeXML);
						beats = mxmlGetInteger(beatsXML);
						llll_appendlong(timenumll, beats * beat_den / beat_type, 0, WHITENULL_llll);
					}
				}
				if (timenumll->l_size) {
					if (timenumll->l_size == 1) {
						llll_appendlong(timell, beats, 0, WHITENULL_llll);
						llll_free(timenumll);
					} else
						llll_appendllll(timell, timenumll, 0, WHITENULL_llll);
					llll_appendlong(timell, beat_den, 0, WHITENULL_llll);
				} else {
					llll_free(timenumll);
					if (isfirstmeasure) {
						llll_appendlong(timell, 4, 0, WHITENULL_llll);
						llll_appendlong(timell, 4, 0, WHITENULL_llll);
					}
				}

				// divisions
				mxml_node_t *divisionsXML = mxmlFindElement(attributesXML, attributesXML, "divisions", NULL, NULL, MXML_DESCEND_FIRST);
				if (divisionsXML)
					divisions = mxmlGetInteger(divisionsXML) * 4;
				if (!divisions) {
					object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
					divisions = 4;
				}

			} else if (isfirstmeasure) {
				object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
				divisions = 4;
				llll_appendsym(clefsll, _llllobj_sym_G, 0, WHITENULL_llll);
				llll_appendsym(keysll, gensym("CM"), 0 , WHITENULL_llll);
				timell = llll_get();
				llll_appendlong(timell, 4, 0, WHITENULL_llll);
				llll_appendlong(timell, 4, 0, WHITENULL_llll);
			}
			
			if (timell->l_owner) { // which means that we're using the one from the previous measure
				timell = llll_clone(timell);
			}			
			llll_appendllll(measureinfoll, timell, 0, WHITENULL_llll);

			// tempi
			tempill = llll_get();
			// if tempill already has a value, it has already been used
			
			mxml_node_t *directionXML;
			for (directionXML = mxmlFindElement(measureXML, measureXML, "direction", NULL, NULL, MXML_DESCEND_FIRST);
				 directionXML;
				 directionXML = mxmlFindElement(directionXML, measureXML, "direction", NULL, NULL, MXML_NO_DESCEND)) {
				
				mxml_node_t *direction_typeXML;
				for (direction_typeXML = mxmlFindElement(directionXML, directionXML, "direction-type", NULL, NULL, MXML_DESCEND_FIRST);
					 direction_typeXML;
					 direction_typeXML = mxmlFindElement(direction_typeXML, directionXML, "direction-type", NULL, NULL, MXML_NO_DESCEND)) {
					
					mxml_node_t *metronomeXML = mxmlFindElement(direction_typeXML, direction_typeXML, "metronome", NULL, NULL, MXML_DESCEND_FIRST);
					if (metronomeXML) {
						t_llll *onetempoll = llll_get();
						mxml_node_t *beat_unitXML = mxmlFindElement(metronomeXML, directionXML, "beat-unit", NULL, NULL, MXML_DESCEND_FIRST);
						if (beat_unitXML) {
							const char *beat_unittxt = mxmlGetText(beat_unitXML, NULL);
							long dots = 0;
							mxml_node_t *beat_unit_dotXML;
							for (beat_unit_dotXML = mxmlFindElement(beat_unitXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND);
								 beat_unit_dotXML;
								 beat_unit_dotXML = mxmlFindElement(beat_unit_dotXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND))
								dots++;
							
							t_rational tempo_figure = xml_name_and_dots_to_value(beat_unittxt, dots);
							if (tempo_figure.r_num != 0) {
								llll_appendrat(onetempoll, tempo_figure, 0, WHITENULL_llll);
								mxml_node_t *per_minuteXML = mxmlFindElement(metronomeXML, metronomeXML, "per-minute", NULL, NULL, MXML_DESCEND_FIRST);
								if (per_minuteXML) {
									const char *per_minutetxt = mxmlGetText(per_minuteXML, NULL);
									double per_minute = 0;
									if (per_minutetxt) {
										while (*per_minutetxt && !isdigit(*per_minutetxt))
											per_minutetxt++;
										per_minute = strtod(per_minutetxt, NULL);
									}
									llll_appenddouble(onetempoll, per_minute, 0, WHITENULL_llll);
								}
								else {
									object_warn((t_object *) x, "Bad tempo, setting to 60");
									llll_appendlong(onetempoll, 60, 0, WHITENULL_llll);
								}
								
								mxml_node_t *offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
                                t_rational offset;
								if (offsetXML) {
									offset = genrat(mxmlGetInteger(offsetXML), divisions);
                                } else {
                                    offset = genrat(0, 1);
                                }
                                llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
                                llll_appendlong(onetempoll, 0, 0, WHITENULL_llll); // tempo interpolation
                                if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                                    maintempo_ll = llll_get();
                                    llll_appendllll_clone(maintempo_ll, onetempoll);
                                }
								llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
							} else
								object_warn((t_object *) x, "Bad tempo");
						}
					}
				}
				mxml_node_t *soundtempoXML = mxmlFindElement(directionXML, directionXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
                if (!soundtempoXML)
                    soundtempoXML = mxmlFindElement(measureXML, measureXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
				if (soundtempoXML) {
					t_llll *onetempoll = llll_get();
					double bpm = strtod(mxmlElementGetAttr(soundtempoXML, "tempo"), NULL);
					llll_appendrat(onetempoll, genrat(1, 4), 0, WHITENULL_llll);
					llll_appenddouble(onetempoll, bpm, 0, WHITENULL_llll);
                    mxml_node_t *offsetXML = NULL;
                    t_rational offset;
                    if (directionXML)
                        offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
                    if (offsetXML) {
                        offset = genrat(mxmlGetInteger(offsetXML), divisions);
                    } else {
                        offset = genrat(0, 1);
                    }
                    llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
                    if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                        maintempo_ll = llll_get();
                        llll_appendllll_clone(maintempo_ll, onetempoll);
                    }
					llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
				}
			}
            if (tempill->l_size) {
				llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else if (maintempo_ll) {
                llll_clone_upon(maintempo_ll, tempill);
                llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else {
				llll_free(tempill);
				tempill = NULL;
			}

            
            
            
            
            ///////////////////////////////
            ///////////////////////////////
            //
			// chords and notes
            //
            ///////////////////////////////
            ///////////////////////////////

            mxml_node_t *nextnoteXML = NULL;
  
            mxml_node_t *firstnoteXML = NULL;
			t_llll *chordll = NULL;
            t_llll *chord_parentll[CONST_MAX_VOICES];
            
            for (long i = 0; i < voices_for_this_xml_part; i++)
                chord_parentll[i] = measurell[i];
//            chord_parentll[0] = measurell[0];
			long grace_group = 0, grace = 0;
			long pops = 0;
            t_llll *chordslotsll = NULL;
            
            long current_voice_in_part = 0;

            
            t_pitch allpitches[10000];
            long numpitches = 0;
            
            mxml_node_t *itemXML;
            for (itemXML = mxmlGetFirstChild(measureXML);
                 itemXML;
                 itemXML = mxmlWalkNext(itemXML, measureXML, MXML_NO_DESCEND)) {
            
                t_bool switch_to_new_voice = false;
                //mxml_node_t *nextnode = noteXML;
                t_bool isrest = false;
                const char *itemName = mxmlGetElement(itemXML);
                if (!itemName)
                    continue;
                
                if (!strcmp(itemName, "forward")) {
                    isrest = true;
                    
                } else if (!strcmp(itemName, "backup")) {
                    mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                    t_rational backupdur = t_rational(mxmlGetInteger(durationXML), divisions);
                    current_timepoint -= backupdur;
                    
                    //t_rational getHere = used_duration[current_voice_in_part] - backupdur;
                    if (current_timepoint < 0) {
                        object_warn((t_object *) x, "<backup> tag wants to backup too far");
                        current_timepoint = t_rational(0);
                    }
                    switch_to_new_voice = true;
                    continue;
                    
                } else if (!strcmp(itemName, "direction")) {

                    
                    
                    
                    
                } else if (strcmp(itemName, "note")) {
                    continue;
                }
                
                if (!firstnoteXML)
                    firstnoteXML = itemXML;
            
                nextnoteXML = mxmlFindElement(itemXML, measureXML, "note", NULL, NULL, MXML_NO_DESCEND);
                
                mxml_node_t *voiceXML = mxmlFindElement(itemXML, itemXML, "voice", NULL, NULL, MXML_DESCEND_FIRST);

                if (voiceXML) {
                    int newvoice = mxmlGetInteger(voiceXML) - 1;
                    if (newvoice != current_voice_in_part) {
                        switch_to_new_voice = true;
                        current_voice_in_part = newvoice;
                    }
                }
                
                while (current_voice_in_part < voices_for_this_xml_part) {
                    if (used_duration[current_voice_in_part] > current_timepoint) {
                        ++current_voice_in_part;
                        switch_to_new_voice = true;
                    } else
                        break;
                }
                
                while (current_voice_in_part >= voices_for_this_xml_part) {
                    voicell[voices_for_this_xml_part + 1] = llll_clone(voicell[voices_for_this_xml_part]);
                    measurell[voices_for_this_xml_part + 1] = llll_clone(measurell[voices_for_this_xml_part]);
                    used_duration[voices_for_this_xml_part + 1] = t_rational(0);
                    
                    chord_parentll[voices_for_this_xml_part] = measurell[voices_for_this_xml_part];
                    ++voices_for_this_xml_part;
                }
                
                if (used_duration[current_voice_in_part] < current_timepoint) {
                    t_rational restdur = - (current_timepoint - used_duration[current_voice_in_part]);
                    chordll = llll_get();
                    llll_appendrat(chordll, restdur);
                    llll_appendlong(chordll, 0);
                    llll_appendllll(chord_parentll[current_voice_in_part], chordll);
                    used_duration[current_voice_in_part] = current_timepoint;
                }
                
                // IMPORTING DYNAMICS
                if (itemXML == firstnoteXML && (!nextnoteXML || switch_to_new_voice)) { // just 1 note,
                    // assuming that this is the right thing to do when we switch to another voice
                    xml_get_dynamics(measureXML->child, NULL, dynamics_text);
                    words = xml_get_words(measureXML->child, NULL, NULL);
                }
                else if (itemXML == firstnoteXML) {
                    xml_get_dynamics(measureXML->child, firstnoteXML, dynamics_text);
                    words = xml_get_words(measureXML->child, firstnoteXML, NULL);
                }
                else if (!nextnoteXML || switch_to_new_voice) {
                    char temp_dynamics_text[CONST_DYNAMICS_TEXT_ALLOC_SIZE];
                    temp_dynamics_text[0] = 0;
                    xml_get_dynamics(itemXML->next, NULL, temp_dynamics_text);
                    if (temp_dynamics_text[0]) {
                        // merge dynamics
                        long len = strlen(dynamics_text);
                        if (len == 0)
                            snprintf_zero(dynamics_text, CONST_DYNAMICS_TEXT_ALLOC_SIZE, "%s", temp_dynamics_text);
                        else {
                            if (dynamics_text[len-1] == '=') {
                                dynamics_text[len-1] = 0;
                                len--;
                            }
                            snprintf_zero(dynamics_text + len, CONST_DYNAMICS_TEXT_ALLOC_SIZE - len, "%s", temp_dynamics_text);
                        }
                    }
                    words = xml_get_words(itemXML->next, NULL, words);
                }
                
                
                // if there is a chord and we're closing (even if temporarily) this voice,
                // append to it its articulations and flags
                if (chordll && switch_to_new_voice) {
                    if (chordslotsll) {
                        llll_appendllll(chordll, chordslotsll);
                    }
                    llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
                    chordll = NULL;
                }
                
				mxml_node_t *chordXML = mxmlFindElement(itemXML, itemXML, "chord", NULL, NULL, MXML_DESCEND_FIRST);
				if (chordXML && !chordll) {
					object_warn((t_object *) x, "<chord> tag with no preceding note");
					chordXML = NULL;
				}
				
				mxml_node_t *notationsXML = mxmlFindElement(itemXML, itemXML, "notations", NULL, NULL, MXML_DESCEND_FIRST);

				if (!chordXML) {
					if (chordll) { // if there was a previous chord, append its flags to it
                        if (chordslotsll) {
                            llll_appendllll(chordll, chordslotsll);
                            chordslotsll = NULL;
                        }
						llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
					}
					grace = mxmlFindElement(itemXML, itemXML, "grace", NULL, NULL, MXML_DESCEND_FIRST) != 0;
					if (grace && !grace_group) { // that is, we're starting a new grace group
						chordll = llll_get();
						llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
						llll_appendsym(chordll, _llllobj_sym_g, 0, WHITENULL_llll);
						chord_parentll[current_voice_in_part] = chordll;
						grace_group = 1;
					} else if (!grace && grace_group) { // that is, this is the first note outside a grace group
						if (chord_parentll[current_voice_in_part] != measurell[current_voice_in_part]) // don't climb too much, even if there is a mistake!
							chord_parentll[current_voice_in_part] = chord_parentll[current_voice_in_part]->l_owner->l_parent;
						grace_group = 0;
					}

					while (pops) {
						if (chord_parentll[current_voice_in_part] != measurell[current_voice_in_part]) { // don't climb too much, even if there is a mistake!
							chord_parentll[current_voice_in_part] = chord_parentll[current_voice_in_part]->l_owner->l_parent;
							pops--;
						} else
							pops = 0;
					}

					// level stuff
					mxml_node_t *beamXML;
					for (beamXML = mxmlFindElement(itemXML, itemXML, "beam", NULL, NULL, MXML_DESCEND_FIRST);
						 beamXML;
						 beamXML = mxmlFindElement(beamXML, itemXML, "beam", NULL, NULL, MXML_NO_DESCEND)) {
						const char *beamtxt = mxmlGetText(beamXML, NULL);
						if (!strcmp(beamtxt, "begin")) {
							chordll = llll_get();
							llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
							chord_parentll[current_voice_in_part] = chordll;
						} else if (!strcmp(beamtxt, "end")) {
							pops++;
						}
					}

					mxml_node_t *tupletXML;
					for (tupletXML = mxmlFindElement(notationsXML, notationsXML, "tuplet", NULL, NULL, MXML_DESCEND_FIRST);
						 tupletXML;
						 tupletXML = mxmlFindElement(tupletXML, notationsXML, "tuplet", NULL, NULL, MXML_NO_DESCEND)) {
						const char *tuplettypetxt = mxmlElementGetAttr(tupletXML, "type");
						if (!strcmp(tuplettypetxt, "start")) {
							chordll = llll_get();
							llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
							chord_parentll[current_voice_in_part] = chordll;
						} else if (!strcmp(tuplettypetxt, "stop")) {
							pops++;
						}
					}
					
					chordll = llll_get();
					llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
					
					mxml_node_t *restXML = mxmlFindElement(itemXML, itemXML, "rest", NULL, NULL, MXML_DESCEND_FIRST);
                    if (restXML)
                        isrest = true;
					t_rational duration = t_rational(0);

					mxml_node_t *typeXML = mxmlFindElement(itemXML, itemXML, "type", NULL, NULL, MXML_DESCEND_FIRST);
					if (typeXML) {
						const char *typetxt = mxmlGetText(typeXML, NULL);
						long dots = 0;
						mxml_node_t *dotXML;
						for (dotXML = mxmlFindElement(typeXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND);
							 dotXML;
							 dotXML = mxmlFindElement(dotXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND))
							dots++;
						
						duration = xml_name_and_dots_to_value(typetxt, dots);
					}
                    if ((!typeXML && !grace) || (restXML && duration == 1)) { // it could be the only note in the part
						mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                        if (durationXML)
                            duration = genrat(mxmlGetInteger(durationXML), divisions);
                        else if (duration == t_rational(0)) {
                            object_warn((t_object *) x, "Note without duration");
                            duration = genrat(1, 4); // use a dummy duration!
                        }
					} else if (!typeXML && grace) { // if it's a grace note and there is no type
						duration = genrat(1, 8); // use a dummy duration!
					}
					
					mxml_node_t *time_modificationXML = mxmlFindElement(itemXML, itemXML, "time-modification", NULL, NULL, MXML_DESCEND_FIRST);
					if (time_modificationXML) {
						mxml_node_t *actual_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "actual-notes", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *normal_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-notes", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *normal_typeXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-type", NULL, NULL, MXML_DESCEND_FIRST);
						long actual_notes = mxmlGetInteger(actual_notesXML);
						long normal_notes = mxmlGetInteger(normal_notesXML);
						if (!typeXML && normal_typeXML) {
							const char *normal_typetxt = mxmlGetText(normal_typeXML, NULL);
							long normal_dots = 0;
							mxml_node_t *normal_dotXML;
							for (normal_dotXML = mxmlFindElement(normal_typeXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND);
								 normal_dotXML;
								 normal_dotXML = mxmlFindElement(normal_dotXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND))
								normal_dots++;
							
							duration = xml_name_and_dots_to_value(normal_typetxt, normal_dots);
						}
						duration = rat_long_prod(duration, normal_notes);
						duration = rat_long_div(duration, actual_notes);
					}
                    
                    if (!grace)
                        current_timepoint = used_duration[current_voice_in_part] += duration;
                    
					if (isrest) { // which can be either because it is an actual rest, or beacuse of <forward>
						duration.r_num *= -1;
					}
					llll_appendrat(chordll, duration, 0, WHITENULL_llll);
				}
				
				if (!isrest) {
					mxml_node_t *pitchXML = mxmlFindElement(itemXML, itemXML, "pitch", NULL, NULL, MXML_DESCEND_FIRST);
					const char *steptxt = NULL;
					long octave = 0;
                    short degree = 0;
                    t_shortRational alter;

					if (pitchXML) {
						mxml_node_t *stepXML = mxmlFindElement(pitchXML, pitchXML, "step", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *alterXML = mxmlFindElement(pitchXML, pitchXML, "alter", NULL, NULL, MXML_DESCEND_FIRST);
						mxml_node_t *octaveXML = mxmlFindElement(pitchXML, pitchXML, "octave", NULL, NULL, MXML_DESCEND_FIRST);
						steptxt = mxmlGetText(stepXML, NULL);
                        degree = toupper(*steptxt) - 'C';
                        if (degree < 0)
                            degree += 7;
                        CLAMP(degree, 0, 6);
						alter = approx_double_with_rat_fixed_den(mxmlGetReal(alterXML) / 2., 8, 0, nullptr);
						octave = mxmlGetInteger(octaveXML) + 1;
						mxml_node_t *accidentalXML = mxmlFindElement(itemXML, itemXML, "accidental", NULL, NULL, MXML_DESCEND_FIRST);
                        if (accidentalXML) {
                            alter = xml_get_accidental(accidentalXML);
                        }
                        short den = alter.den();
                        if (den > new_tonedivision)
                            new_tonedivision = den;
                        if (den <= 2 && parenthesizedquartertones) {
                            const char *parentheses = mxmlElementGetAttr(accidentalXML, "parentheses");
                            if (parentheses && !strcmp(parentheses, "yes")) {
                                alter += t_pitch::qrtrsharp;
                                if (new_tonedivision < 4)
                                    new_tonedivision = 4;
                            } else {
                                for (long i = numpitches - 1; i >= 0; i--) {
                                    if (allpitches[i].degree() == degree &&
                                        allpitches[i].degree() == octave &&
                                        ((!accidentalXML && alter == 0) ||
                                         allpitches[i].alter() == alter - t_pitch::qrtrsharp))
                                        alter = allpitches[i].alter();
                                }
                            }
                        } else if (!accidentalXML && alter == 0) { // see if there is a previous note to get the alteration from
                            for (long i = numpitches - 1; i >= 0; i--) {
                                if (allpitches[i].degree() == degree &&
                                    allpitches[i].octave() == octave) {
                                    alter = allpitches[i].alter();
                                    break;
                                }
                            }
                        }
                        
                        
                        
                        
					} else {
						mxml_node_t *unpitchedXML = mxmlFindElement(itemXML, itemXML, "unpitched", NULL, NULL, MXML_DESCEND_FIRST);
						if (unpitchedXML) {
							mxml_node_t *display_stepXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-step", NULL, NULL, MXML_DESCEND_FIRST);
							if (display_stepXML) {
								mxml_node_t *display_octaveXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-octave", NULL, NULL, MXML_DESCEND_FIRST);
								steptxt = mxmlGetText(display_stepXML, NULL);
                                degree = toupper(*steptxt) - 'C';
                                if (degree < 0)
                                    degree += 7;
                                CLAMP(degree, 0, 6);
								octave = mxmlGetInteger(display_octaveXML) + 1;
							} else {
								degree = 6;
								octave = 5;
							}
						}
					}

					t_llll *notell = llll_get();
                    t_pitch pch = t_pitch(degree, alter, octave);
                    allpitches[numpitches++] = pch;
                    llll_appendpitch(notell, pch);
					mxml_node_t *soundXML = mxmlFindElement(itemXML, itemXML, "sound", NULL, NULL, MXML_DESCEND_FIRST);
					mxml_node_t *dynamicsXML = mxmlFindElement(soundXML, soundXML, "dynamics", NULL, NULL, MXML_DESCEND_FIRST);
					if (dynamicsXML)
						velocity = mxmlGetInteger(dynamicsXML) / 100. * 90.;					
					llll_appendlong(notell, velocity, 0, WHITENULL_llll);
					if (mxmlFindElement(itemXML, itemXML, "tie", "type", "start", MXML_DESCEND_FIRST))
						llll_appendlong(notell, 1, 0, WHITENULL_llll);
					else
						llll_appendlong(notell, 0, 0, WHITENULL_llll);

                    t_llll *slotsll = llll_get();
                    llll_appendsym(slotsll, gensym("slots"));
                    
                    if (noteheadslot > 0) {
                        mxml_node_t *noteheadXML = mxmlFindElement(itemXML, itemXML, "notehead", NULL, NULL, MXML_DESCEND_FIRST);
                        if (noteheadXML) {
                            const char *notehead_txt = mxmlGetText(noteheadXML, NULL);
                            if (notehead_txt) {
                                long noteheadID = -1;
                                if (!strcmp(notehead_txt, "x"))
                                    noteheadID = k_NOTEHEAD_CROSS;
                                else if (!strcmp(notehead_txt, "diamond"))
                                    noteheadID = k_NOTEHEAD_DIAMOND;
                                else if (!strcmp(notehead_txt, "cross"))
                                    noteheadID = k_NOTEHEAD_PLUS;
                                else if (!strcmp(notehead_txt, "normal")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_NOTE, k_NOTEHEAD_WHITE_NOTE, k_NOTEHEAD_DEFAULT);
                                } else if (!strcmp(notehead_txt, "square")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_SQUARE, k_NOTEHEAD_WHITE_SQUARE, k_NOTEHEAD_SQUARE);
                                } else if (!strcmp(notehead_txt, "triangle")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_TRIANGLE, k_NOTEHEAD_WHITE_TRIANGLE, k_NOTEHEAD_TRIANGLE);
                                }
                                if (noteheadID > 0) {
                                    t_llll *noteheadll = llll_get();
                                    llll_appendlong(noteheadll, noteheadslot);
                                    llll_appendsym(noteheadll, notehead_id2symbol(&x->r_ob.noteheads_typo_preferences, noteheadID));
                                    llll_appendllll(slotsll, noteheadll);
                                }
                            }
                        }
                    }
                    
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll)
                            llll_appendllll(slotsll, articulationsll);
                    }
                    
                    if (dynamicsslot > 0 && dynamics_text[0]) {
                        t_llll *dynamicsll = llll_get();
                        llll_appendlong(dynamicsll, dynamicsslot);
                        llll_appendsym(dynamicsll, gensym(dynamics_text));
                        llll_appendllll(slotsll, dynamicsll);
                    }
                    
                    if (directionsslot > 0 && words && words->l_size) {
                        llll_prependlong(words, directionsslot);
                        llll_appendllll(slotsll, words);
                        words = NULL;
                    }
                    
                    if (lyricsslot > 0) {
                        mxml_node_t *lyricXML = mxmlFindElement(itemXML, itemXML, "lyric", NULL, NULL, MXML_DESCEND_FIRST);
                        if (lyricXML) {
                            t_llll *lyricsll = llll_get();
                            mxml_node_t *textXML = mxmlFindElement(lyricXML, lyricXML, "text", NULL, NULL, MXML_DESCEND_FIRST);
                            mxml_node_t *syllabicXML = mxmlFindElement(lyricXML, lyricXML, "syllabic", NULL, NULL, MXML_DESCEND_FIRST);
                            llll_appendlong(lyricsll, lyricsslot);
                            const char *txt = textXML ? mxmlGetText(textXML, NULL) : NULL;
                            const char *syllabictxt = syllabicXML ? mxmlGetText(syllabicXML, NULL) : NULL;
                            t_symbol *txtsym = _llllobj_sym_empty_symbol;
                            if (syllabictxt && (!strcmp(syllabictxt, "begin") || !strcmp(syllabictxt, "middle"))) {
                                long len = strlen(txt);
                                char *temp_txt = (char *)bach_newptr((len + 2) * sizeof(char));
                                snprintf_zero(temp_txt, len + 2, "%s-", txt);
                                txtsym = gensym(temp_txt);
                                bach_freeptr(temp_txt);
                            } else if (txt) {
                                txtsym = gensym(txt);
                            }
                            llll_appendsym(lyricsll, txtsym);
                            llll_appendllll(slotsll, lyricsll);
                        }
                    }
                    if (slotsll->l_size > 1)
                        llll_appendllll(notell, slotsll);
                    else
                        llll_free(slotsll);
                        
                    llll_appendlong(notell, 0, 0, WHITENULL_llll); // note flags
                    llll_appendllll(chordll, notell, 0, WHITENULL_llll);
                    
                } else { // if it's a rest look for articulations and put them in the chord slot
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll) {
                            chordslotsll = llll_get();
                            llll_appendsym(chordslotsll, _llllobj_sym_slots);
                            llll_appendllll(chordslotsll, articulationsll);
                        }
                    }
                }
                xml_get_dynamics(itemXML->next, nextnoteXML, dynamics_text);
                words = xml_get_words(itemXML->next, nextnoteXML, NULL);
			}
			
            if (chordll) {
                if (chordslotsll) {
                    llll_appendllll(chordll, chordslotsll);
                }
                llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
                chordll = NULL;
            }
            
            mxml_node_t *barlineXML = mxmlFindElement(measureXML, measureXML, "barline", NULL, NULL, MXML_DESCEND_FIRST);
			if (barlineXML) {
                mxml_node_t *barstyleXML = mxmlFindElement(barlineXML, barlineXML, "bar-style", NULL, NULL, MXML_DESCEND_FIRST);
                if (barstyleXML) {
                    const char *bar_styletxt = mxmlGetText(barstyleXML, NULL);
                    char barline[2];
                    barline[1] = 0;
                    if (!strcmp(bar_styletxt, "regular"))			*barline = k_BARLINE_NORMAL;
                    else if (!strcmp(bar_styletxt, "dashed"))		*barline = k_BARLINE_DASHED;
                    else if (!strcmp(bar_styletxt, "dotted"))		*barline = k_BARLINE_POINTS;
                    else if (!strcmp(bar_styletxt, "light-light"))	*barline = k_BARLINE_DOUBLE;
                    else if (!strcmp(bar_styletxt, "light-heavy"))	*barline = k_BARLINE_FINAL;
                    else if (!strcmp(bar_styletxt, "none"))			*barline = k_BARLINE_HIDDEN;
                    else if (!strcmp(bar_styletxt, "heavy"))		*barline = k_BARLINE_SOLID;
                    else *barline = 0;
                    t_llll *barlinell = llll_get();
                    llll_appendsym(barlinell, _llllobj_sym_barline, 0, WHITENULL_llll);
                    if (*barline)
                        llll_appendsym(barlinell, gensym(barline), 0, WHITENULL_llll);
                    else
                        llll_appendlong(barlinell, 0, 0, WHITENULL_llll);
                    llll_appendllll(measureinfoll, barlinell, 0, WHITENULL_llll);
                }
			}
            
            llll_prependllll(measurell[0], measureinfoll, 0, WHITENULL_llll);
            llll_appendlong(measurell[0], 0, 0, WHITENULL_llll); // measure flags
            llll_appendllll(voicell[0], measurell[0]);
            
            for (long i = 1; i <= voices_for_this_xml_part; i++) {
                llll_prependllll_clone(measurell[i], measureinfoll);
                llll_appendlong(measurell[i], 0, 0, WHITENULL_llll); // measure flags
                llll_appendllll(voicell[i], measurell[i]);
            }

			isfirstmeasure = 0;
		}
        
        for (long i = 0; i < voices_for_this_xml_part; i++) {
            llll_appendlong(voicell[i], 0, 0, WHITENULL_llll); // part flags
            llll_appendllll(scorell, voicell[i], 0, WHITENULL_llll);
            llll_appendsym(clefsll, clefsym);
            llll_appendsym(keysll, keysym);
        }
        
        llll_free(voicell[voices_for_this_xml_part]);
        llll_appendlong(numpartsll, voices_for_this_xml_part); // numparts has been added to scorell at the beginning

        llll_free(words);
	}
	mxmlDelete(scoreXML);
    
    long tone_division = x->r_ob.tone_division;
    if (tone_division % new_tonedivision != 0) {
        object_warn((t_object *) x, "Changed microtonal division!");
        object_attr_setlong(x, gensym("tonedivision"), lcm(tone_division, 4));
    }

	//dev_llll_post(scorell, 1, -1, 10, x, NULL);
	return scorell;
}

t_max_err score_dowritexml(const t_score *x, t_symbol *s, long ac, t_atom *av)
{
	long err = MAX_ERR_NONE;
	long partidx, measureidx;
	long divisions, midicents = 0;
	long isfirstnote;
	t_fourcc filetype = 'TEXT', outtype;
	char measurenum[256];
	char *stafftxt;
	t_symbol *filename_sym = NULL;
	t_scorevoice *voice;
	t_measure *measure;
	t_chord *chord;
	t_note *note;
	t_llll *export_slots = NULL;
	long export_velocities = 0, export_noteheads = 1, export_lyrics = 1, export_dynamics = 1, export_articulations = 1, export_glissandi = 0;
	long dynamics_slot = x->r_ob.link_dynamics_to_slot;
    long articulations_slot = x->r_ob.link_articulations_to_slot;
    const t_articulations_typo_preferences *atp = &x->r_ob.articulations_typo_preferences;
	long parenthesized_quartertones = 0;
	t_llll *arguments = (t_llll *) atom_getobj(av);
    t_slotitem *slotitem;
    
	llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siilliiiiii",
				   _sym_filename, &filename_sym,
				   gensym("dynamicsslot"), &dynamics_slot,
				   gensym("velocity"), &export_velocities,
				   gensym("directionslots"), &export_slots,
                   gensym("directionsslots"), &export_slots,
				   gensym("parenthesizedquartertones"), &parenthesized_quartertones,
                   gensym("articulations"), &export_articulations,
                   gensym("lyrics"), &export_lyrics,
                   gensym("noteheads"), &export_noteheads,
                   gensym("dynamics"), &export_dynamics,
                   gensym("glissandi"), &export_glissandi
                   );

    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_destroyelem(arguments->l_head);
    }
    

	llll_free(arguments);
    
    if (!export_articulations)
        articulations_slot = 0;
    if (!export_dynamics)
        dynamics_slot = 0;

	whitespace_cb(NULL, -1);
	mxmlSetWrapMargin(1000);
	long numparts = x->r_ob.num_voices;
	
	mxml_node_t *scorexml = mxmlNewXML("1.0");
	mxmlNewElement(scorexml, "!DOCTYPE score-partwise PUBLIC \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\"\n\"http://www.musicxml.org/dtds/partwise.dtd\" ");
	mxml_node_t *scorepartwisexml = mxmlNewElement(scorexml, "score-partwise");
	mxmlElementSetAttr(scorepartwisexml, "version", "3.0");
	
    
    // Adding identification
    char bachversiontxt[512];
    char datetxt[512];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf_zero(bachversiontxt, 512, "bach for Max %s", bach_get_current_version_string_verbose());
    snprintf_zero(datetxt, 512, "%.4d-%.2d-%.2d", tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday);
    mxml_node_t *identificationxml = mxmlNewElement(scorepartwisexml, "identification");
    mxml_node_t *encodingxml = mxmlNewElement(identificationxml, "encoding");
    bach_mxmlNewTextElement(encodingxml, "software", 0, bachversiontxt);
    bach_mxmlNewTextElement(encodingxml, "encoding-date", 0, datetxt);

    
    
	mxml_node_t *partlistxml = mxmlNewElement(scorepartwisexml, "part-list");
	
    lock_general_mutex((t_notation_obj *)x);

	// prepare the slot export
	t_llllelem *this_slotnum_elem, *next_elem;
	if (!export_slots)
		export_slots = llll_get();
	
	t_llll *developed = llll_develop_ranges(export_slots);
	llll_free(export_slots);
	export_slots = developed;
	
	for (this_slotnum_elem = export_slots->l_head; this_slotnum_elem; this_slotnum_elem = next_elem) {
		next_elem = this_slotnum_elem->l_next;
		t_atom_long *this_slotnum = &this_slotnum_elem->l_hatom.h_w.w_long; // llll_develop_ranges returned a list composed solely of H_LONGs
		if (*this_slotnum < 1 || *this_slotnum > CONST_MAX_SLOTS) {
            if (*this_slotnum != 0) // 0 means don't set, no warning should be given
                object_warn((t_object *) x, "Slot %ld does not exist", *this_slotnum);
            llll_destroyelem(this_slotnum_elem);
		} else {
			t_slotinfo *this_slot_info = &x->r_ob.slotinfo[(*this_slotnum) - 1];
			long slot_type = this_slot_info->slot_type;
			if (slot_type == k_SLOT_TYPE_NONE) {
				object_warn((t_object *) x, "Slot %ld is of type none", *this_slotnum);
				llll_destroyelem(this_slotnum_elem);
			} else /* if (slot_type != k_SLOT_INT || 
					   slot_type != k_SLOT_FLOAT ||
					   slot_type != k_SLOT_INTLIST ||
					   slot_type != k_SLOT_FLOATLIST ||
					   slot_type != k_SLOT_TEXT ||
					   slot_type != k_SLOT_LLLL) {
				object_warn((t_object *) score, "slot %ld is unsupported for export", *this_slotnum);
				llll_destroyelem(this_slotnum_elem);		
			} else */
				(*this_slotnum)--;
		}
	}
	
    //////////////////
	// prepare the dynamics slot
    //////////////////
    char dynamics_slot_is_text = false;
	if (dynamics_slot > 0) {
		if (dynamics_slot > CONST_MAX_SLOTS) {
			object_warn((t_object *) x, "Slot %ld does not exist", dynamics_slot);
			dynamics_slot = 0;
		} else {
			t_slotinfo *this_slot_info = &x->r_ob.slotinfo[dynamics_slot - 1];
			long slot_type = this_slot_info->slot_type;
			if (slot_type == k_SLOT_TYPE_NONE) {
				object_warn((t_object *) x, "Slot %ld is of type none", dynamics_slot);
				dynamics_slot = 0;
			} else if (slot_type != k_SLOT_TYPE_DYNAMICS) {
				object_warn((t_object *) x, "Requested dynamics slot %ld is not of type dynamics", dynamics_slot);
				dynamics_slot = 0;
			}
            if (slot_type == k_SLOT_TYPE_TEXT)
                dynamics_slot_is_text = true;
		}
	}
	dynamics_slot --;

    //////////////////
    // checking articulations slot
    //////////////////
    if (articulations_slot > 0) {
        if (articulations_slot > CONST_MAX_SLOTS) {
            object_warn((t_object *) x, "Slot %ld does not exist", articulations_slot);
            articulations_slot = 0;
        } else {
            t_slotinfo *this_slot_info = &x->r_ob.slotinfo[articulations_slot - 1];
            long slot_type = this_slot_info->slot_type;
            if (slot_type == k_SLOT_TYPE_NONE) {
                object_warn((t_object *) x, "Slot %ld is of type none", articulations_slot);
                articulations_slot = 0;
            } else if (slot_type != k_SLOT_TYPE_ARTICULATIONS) {
                object_warn((t_object *) x, "Requested articulations slot is not of type articulation", articulations_slot);
                articulations_slot = 0;
            }
        }
    }
    articulations_slot --;
    
    t_llll *numparts_llll = get_numparts_as_llll((t_notation_obj *) x);
    t_llllelem *numparts_elem = numparts_llll->l_head;
    long voices_left_in_voiceensemble ;
    t_llllelem *this_voice_ensemble_measure;
    t_bool new_voice_ensemble = true;
    
    long voiceidx;
    partidx = 1;
    
	for (voiceidx = 1, voice = x->firstvoice; voice && voiceidx <= numparts; voiceidx++, voice = voice->next) {
		char id[32]; 
		char *nametxt = NULL;
		long textsize = 0;
        
        if (new_voice_ensemble) {
            
            numparts_elem = numparts_elem->l_next;
            voices_left_in_voiceensemble = hatom_getlong(&numparts_elem->l_hatom);
            
            mxml_node_t *partxml = mxmlNewElement(partlistxml, "score-part");
            
            t_atom *names = NULL;
            long name_ac = 0;
            if (voice->v_ob.r_it.names->l_size != 0) {
                name_ac = llll_deparse(voice->v_ob.r_it.names, &names, 0, 0);
            }
            
            snprintf_zero(id, 32, "P%ld", partidx);
            mxmlElementSetAttr(partxml, "id", id);
            
            if (name_ac == 0 || (atom_gettype(&names[0]) == A_SYM && atom_getsym(&names[0]) == _llllobj_sym_abr_none_abr)) {
                nametxt = (char *) sysmem_newptr(1);
                *nametxt = 0;
            } else
                atom_gettext(name_ac, names, &textsize, &nametxt,
                             OBEX_UTIL_ATOM_GETTEXT_TRUNCATE_ZEROS |
                             OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE |
                             OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
            
            // nametxt = "dummy";
            
            bach_mxmlNewTextElement(partxml, "part-name", 0, nametxt);
            sysmem_freeptr(nametxt); // COMMENT THIS IF REVERTING TO OLD VERSION!
            mxml_node_t *score_instrument = mxmlNewElement(partxml, "score-instrument");
            snprintf_zero(id, 32, "P%ld-I%ld", partidx, partidx);
            mxmlElementSetAttr(score_instrument, "id", id);
            bach_mxmlNewTextElement(score_instrument, "instrument-name", 0, "Grand Piano");
            
            bach_freeptr(names);
        }
        
        if (voices_left_in_voiceensemble == 1) {
            partidx++;
            new_voice_ensemble = true;
        } else {
            --voices_left_in_voiceensemble;
            new_voice_ensemble = false;
        }
	}
	
    
    //////////////////
    //////////////////
    // here we export the body of the score
    //////////////////
    //////////////////

    //////////////////
    // first, pass through all the score to calculate a value of the division attribute that is valid for every measure
    // this is not very elegant, but makes things much simpler with voice ensembles
    //////////////////
    divisions = 16;
    for (voiceidx = 1, voice = x->firstvoice; voice && voiceidx <= numparts; voiceidx++, voice = voice->next) {
        for (measure = voice->firstmeasure; measure; measure = measure->next) {
            for (chord = measure->firstchord; chord; chord = chord->next) {
                divisions = lcm(divisions, chord->r_sym_duration.r_den);
            }
        }
    }
    
    t_llll *voice_ensemble_measures = llll_get();

    numparts_elem = numparts_llll->l_head;
    new_voice_ensemble = true;
    
    partidx = 1;
	for (voiceidx = 1, voice = x->firstvoice; voice && voiceidx <= numparts; voiceidx++, voice = voice->next) {
		t_timesignature *ts = NULL;
        long clef;
        mxml_node_t *partxml;
        t_llll *open_gliss = export_glissandi ? llll_get() : NULL;

        if (new_voice_ensemble) {
            char part_id[16];
            clef = voice->v_ob.clef;
            partxml = mxmlNewElement(scorepartwisexml, "part");
            snprintf_zero(part_id, 16, "P%ld", partidx);
            mxmlElementSetAttr(partxml, "id", part_id);
            
            numparts_elem = numparts_elem->l_next;
            voices_left_in_voiceensemble = hatom_getlong(&numparts_elem->l_hatom);
        }
		stafftxt = NULL;
		long staves = 1;
		long splitpoints[3];
        
        char currently_open_hairpin = 0;
        char currently_ongoing_lyrics_syllable = 0;
        
		for (measureidx = 1, measure = voice->firstmeasure; measure; measureidx++, measure = measure->next) {			
            mxml_node_t *measurexml;
            
            if (new_voice_ensemble || !this_voice_ensemble_measure->l_next) {
                measurexml = mxmlNewElement(partxml, "measure");
                if (voices_left_in_voiceensemble > 1)
                    this_voice_ensemble_measure = llll_appendobj(voice_ensemble_measures, measurexml);
                
                snprintf_zero(measurenum, 256, "%ld", measureidx);
                mxmlElementSetAttr(measurexml, "number", measurenum);
                
                // measure attributes
                mxml_node_t *attributesxml = mxmlNewElement(measurexml, "attributes");

                /*
                // divisions (lcm of duration denominators)
                divisions = 16;
                for (chord = measure->firstchord; chord; chord = chord->next) {
                    divisions = lcm(divisions, chord->r_sym_duration.r_den);
                }
                 */
                
                bach_mxmlNewIntElement(attributesxml, "divisions", 0, divisions / 4);
                
                // key signature
                if (measureidx == 1) {
                    mxml_node_t *keyxml = mxmlNewElement(attributesxml, "key");
                    if (voice->v_ob.mode != k_MODE_NONSTANDARD) {
                        bach_mxmlNewIntElement(keyxml, "fifths", 0, voice->v_ob.key);
                        bach_mxmlNewTextElement(keyxml, "mode", 0, voice->v_ob.mode == k_MODE_MAJOR ? "major" : "minor");
                    } else {
                        long i;
                        for (i = 0; i < 7; i++) {
                            t_rational pattern = voice->v_ob.acc_pattern[i];
                            if (pattern.r_num != 0) {
                                char stepname[2];
                                stepname[0] = 'A' + (i + 2) % 7;
                                stepname[1] = 0;
                                bach_mxmlNewTextElement(keyxml, "key-step", 0, stepname);
                                bach_mxmlNewRealElement(keyxml, "key-alter", 0, rat2double(pattern) * 2.);
                                bach_mxmlNewTextElement(keyxml, "key-accidental", 0, bach_xml_acc2name(pattern, NULL));
                            }
                        }
                    }
                    
                }
                
                // time signature
                if (measureidx == 1 || !ts_are_equal(ts, &measure->timesignature)) {
                    ts = &measure->timesignature;
                    mxml_node_t *timexml = mxmlNewElement(attributesxml, "time");
                    
                    if (ts->num_numerator_elements == 1) { // simple time signature
                        bach_mxmlNewIntElement(timexml, "beats", 0, ts->numerator);
                        bach_mxmlNewIntElement(timexml, "beat-type", 0, ts->denominator);
                    } else { // composite time signature
                        long i;
                        for (i = 0; i < ts->num_numerator_elements; i++) {
                            bach_mxmlNewIntElement(timexml, "beats", 0, ts->numerator_elements[i]);
                            bach_mxmlNewIntElement(timexml, "beat-type", 0, ts->denominator);
                        }
                    }
                }
                
                if (measureidx == 1) {
                    score_xml_add_clefs(attributesxml, clef, &staves, splitpoints);
                }
                
                // tempo
                t_tempo *tempo;
                for (tempo = measure->firsttempo; tempo; tempo = tempo->next) {
                    char tempo_figure_txt[16], tempo_txt[16];
                    mxml_node_t *directionxml = mxmlNewElement(measurexml, "direction");
                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                    mxml_node_t *metronomexml = mxmlNewElement(direction_typexml, "metronome");
                    t_rational screen_tempo_figure;
                    char tempo_figure_num_dots;
                    if (is_duration_drawable((t_notation_obj *) x, tempo->tempo_figure, &screen_tempo_figure, &tempo_figure_num_dots)) {
                        xml_value_to_name(screen_tempo_figure.r_den, tempo_figure_txt);
                        bach_mxmlNewTextElement(metronomexml, "beat-unit", 0, tempo_figure_txt);
                        char i;
                        for (i = 0; i < tempo_figure_num_dots; i++)
                            mxmlNewElement(metronomexml, "beat-unit-dot");
                        if (tempo->tempo_value.r_den == 1)
                            bach_mxmlNewIntElement(metronomexml, "per-minute", 0, tempo->figure_tempo_value.r_num);
                        else
                            bach_mxmlNewRealElement(metronomexml, "per-minute", 0, rat2double(tempo->figure_tempo_value));
                    } else {
                        bach_mxmlNewTextElement(metronomexml, "beat-unit", 0, "quarter");
                        if (tempo->tempo_value.r_den == 1)
                            bach_mxmlNewIntElement(metronomexml, "per-minute", 0, tempo->tempo_value.r_num);
                        else
                            bach_mxmlNewRealElement(metronomexml, "per-minute", 0, rat2double(tempo->tempo_value));
                    }
                    mxml_node_t *offsetxml = mxmlNewElement(directionxml, "offset");
                    mxmlElementSetAttr(offsetxml, "sound", "yes");
                    mxmlNewInteger(offsetxml, tempo->changepoint.r_num * divisions / tempo->changepoint.r_den);
                    mxml_node_t *soundxml = mxmlNewElement(directionxml, "sound");
                    snprintf_zero(tempo_txt, 16, "%lf", rat2double(tempo->tempo_value));
                    mxmlElementSetAttr(soundxml, "tempo", tempo_txt);
                }
                
            } else {
                if (measureidx == 1)
                    this_voice_ensemble_measure = voice_ensemble_measures->l_head;
                else
                    this_voice_ensemble_measure = this_voice_ensemble_measure->l_next;
                measurexml = (mxml_node_t *) hatom_getobj(&this_voice_ensemble_measure->l_hatom);
                t_rational dur = measure_get_sym_duration(measure);
                t_atom_long backup = dur * divisions;
                mxml_node_t *backupxml = mxmlNewElement(measurexml, "backup");
                bach_mxmlNewIntElement(backupxml, "duration", 0, backup);
            }
            
            // chords
			for (chord = measure->firstchord; chord; chord = chord->next) {
				char durtxt[16];
				t_rational dur = chord->r_sym_duration;
				long is_rest, is_grace;
				t_xml_chord_beam_info beam_info;
				t_xml_chord_tuplet_info tuplet_info[CONST_MAX_XML_NESTED_TUPLETS];
				long num_tuplets;
				long num_dots = chord->num_dots;
				char chordtype[16], normal_type[16];
				t_rational screen_accidental;
                char we_have_already_exported_dynamics_for_this_chord = false;
                t_llll *open_gliss_chord = export_glissandi ? llll_get() : NULL;
                char at_least_a_gliss_has_ended = false;
				xml_value_to_name(chord->figure.r_den, chordtype);
				
				if (dur.r_num < 0) {
					dur.r_num *= -1;
					is_rest = 1;
				} else
					is_rest = 0;
				
				is_grace = chord->is_grace_chord;
				
				snprintf_zero(durtxt, 16, "%ld", dur.r_num * divisions / dur.r_den);
				
				beam_info = get_xml_chord_beam_info((t_notation_obj *) x, chord);
				num_tuplets = get_xml_chord_tuplet_info((t_notation_obj *) x, chord, tuplet_info);

				if (num_tuplets)
					xml_value_to_name(tuplet_info[0].tuplet_actual_type.r_den, normal_type);
					
                
                // cycle on notes
				for (isfirstnote = 1, note = chord->firstnote; isfirstnote || note; isfirstnote = 0, note = note ? note->next : NULL) {
                    
					// dynamics and slots
					if (note) {
						char dynamics_txt[16];
						mxml_node_t *directionxml = NULL;
						mxml_node_t *direction_typexml = NULL;
						mxml_node_t *dynamics_xml = NULL;
						if (export_velocities) {
							mxml_node_t *soundxml = NULL;
                            directionxml = mxmlNewElement(measurexml, "direction");
                            direction_typexml = mxmlNewElement(directionxml, "direction-type");
                            dynamics_xml = mxmlNewElement(direction_typexml, "dynamics");
							soundxml = mxmlNewElement(directionxml, "sound");
							snprintf_zero(dynamics_txt, 16, "%lf", (double) (note->velocity * 100. / 90.));
							mxmlElementSetAttr(soundxml, "dynamics", dynamics_txt);
						}
                        
                        
                        /// EXPORT FOR DYNAMICS
						if (dynamics_slot >= 0) { // *if* we export the dynamics
							t_slot *slot = &note->slot[dynamics_slot];
                            t_bool single = x->r_ob.slotinfo[dynamics_slot].slot_singleslotfortiednotes;
                            
							if (slot->firstitem && slot->firstitem->item &&             // if there are dynamics...
                                !we_have_already_exported_dynamics_for_this_chord &&    // ... and we haven't already exported dynamcis from another note
                                                                                        //     of the same chord (first note having dynamics wins in
                                                                                        //     the dynamics display!)...
                                !(note->tie_from && single)) {                          // ... unless the slot is marked as "single slot for tied notes"
                                                                                        // and the note has a tie arriving to it...
                                
                                // ...then we need to export the dynamics
								char text[2048];
                                
                                // is there an hairpin that is currently "open"? e.g. did a previous dynamics end with < or > ?
                                // then the hairpin has to end on the current note
                                if (currently_open_hairpin)
                                    xmlwrite_close_hairpin(measurexml, &currently_open_hairpin, 0);
                                
                                if (dynamics_slot_is_text) {
                                    
                                    // if the dynamics slot is of TEXT type, we just copy the dynamics
                                    strncpy_zero(text, (char *) slot->firstitem->item, 2048);
                                    strip_final_ws(text);
                                    xmlwrite_add_dynamics(measurexml, text, 0);
                                
                                } else {
                                    
                                    // otherwise, the slot is surely of type dynamics (or it would have been nullified previously, with an error).
                                    char dyn_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
                                    char dyn_text_dep[CONST_MAX_NUM_DYNAMICS_CHARS];
                                    long hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
                                    long num_dynamics = 0;
                                    char open_hairpin = 0;
                                    
                                    // we fill all the information about dynamics for the current chord
                                    // this fills:
                                    // - num_dynamics: with the number of dynamics found for the chord (a chord might have more than one dynamic attached,
                                    // e.g. when a note has something like "p<ff>>p>pppp")
                                    // - dyn_text: with the all dynamics, as string – but beware: with the glyphs used by the notation fonts in bach!
                                    //   this is not a human readable form!
                                    // - hairpins: with an array of hairpins (one for each dynamics of the chord), that can be 0 (no hairpin),
                                    //   1 (crescendo), 2 (exponential crescendo), -1 (diminuendo), -2 (exponential diminuendo).
                                    // - open_hairpin: 1 only if there's an open hairpin (e.g. "p<ff>>p<"), false otherwise
                                    // For instance, a chord having one note with a dynamics slot containing "p<ff>>p>pppp", will be parsed as
                                    // num_dynamics: 4
                                    // dyn_text: array of C-strings with the codepoints of "p", "ff", "p", "pppp" for November for bach
                                    // hairpins: array of 1, -2, -1, 0
                                    // open_hairpin: false

                                    // dg: NOW chord_parse_dynamics is DEPRECATED: MUST BE CHANGED!
                                    // WAS: chord_parse_dynamics((t_notation_obj *)x, chord, dynamics_slot, NULL);
                                    // SOMETHING MUST BE CHANGED HERE
                                    
                                    // obtaining the rational duration of the entire sequence of possibly tied chords
                                    t_rational dur_with_ties = note_get_tieseq_symduration(note);
                                    
                                    // for each dynamics, we need to deparse into human readable form and put it as dynamics marking
                                    for (long di = 0; di < num_dynamics; di++) {
                                        // each piece of dynamics has an offset. E.g. if a note has "p<ff>>p>0", this is assumed as if "p"
                                        // was at the beginning, "ff" was after 1/3 of its duration, "p" again after 2/3 of its duration and 0 at the end.
                                        long offset = 0;
                                        if (num_dynamics > 1)
                                            offset = round(((double)di * (dur_with_ties.r_num * divisions / dur_with_ties.r_den))/(num_dynamics - 1));
                                        
                                        // This deparses dyn_text to a human-readable string representing the dynamics (such as "mp", "sfz", etc.)
                                        deparse_dynamics_to_string_once((t_notation_obj *)x, dyn_text[di], dyn_text_dep);
                                        if (currently_open_hairpin)
                                            xmlwrite_close_hairpin(measurexml, &currently_open_hairpin, offset);
                                        xmlwrite_add_dynamics(measurexml, dyn_text_dep, offset);
                                        if (hairpins[di])
                                            xmlwrite_open_hairpin(measurexml, hairpins[di], &currently_open_hairpin, offset);
                                    }
                                }
                                
                                // we won't export dynamics for this chord any longer, even if other notes of the same chord should have dynamics.
                                we_have_already_exported_dynamics_for_this_chord = true;

							}
						}
                        
						for (this_slotnum_elem = export_slots->l_head; this_slotnum_elem; this_slotnum_elem = this_slotnum_elem->l_next) {
							long slotnum = hatom_getlong(&this_slotnum_elem->l_hatom);
							t_llll *slot_contents = note_get_single_slot_values_as_llll((t_notation_obj *) x, note, k_CONSIDER_FOR_DUMPING, slotnum, false);
                            t_bool single = x->r_ob.slotinfo[slotnum].slot_singleslotfortiednotes;
                            if (slot_contents->l_size > 1 && !(note->tie_from && single)) {
								llll_destroyelem(slot_contents->l_head);
								char *text = NULL;
                                llll_to_text_buf(slot_contents, &text, 0, 10, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_SPECIAL, NULL);
                                if (*text) {
                                    mxml_node_t *directionxml = mxmlNewElement(measurexml, "direction");
                                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                                    bach_mxmlNewTextElement(direction_typexml, "words", 0, text);
                                }
								bach_freeptr(text);
							}
							llll_free(slot_contents);
						}
					}
                    
					mxml_node_t *notexml = mxmlNewElement(measurexml, "note");
					long screen_midicents = 0;
					long i;
					const char *acc_name = NULL;
					long add_par_qrtrtone = 0;
					if (is_grace)
						mxmlNewElement(notexml, "grace");
					
					if (note) {
						if (!isfirstnote) {
							mxmlNewElement(notexml, "chord");
						}
						
						mxml_node_t *pitchxml = mxmlNewElement(notexml, "pitch");
						mxml_node_t *stepxml = mxmlNewElement(pitchxml, "step");
						mxml_node_t *alterxml = mxmlNewElement(pitchxml, "alter");
						mxml_node_t *octavexml = mxmlNewElement(pitchxml, "octave");
						screen_midicents = note_get_screen_midicents(note);
						switch (screen_midicents % 1200) {
							case 0:		mxmlNewText(stepxml, 0, "C");	break;
							case 200:	mxmlNewText(stepxml, 0, "D");	break;
							case 400:	mxmlNewText(stepxml, 0, "E");	break;
							case 500:	mxmlNewText(stepxml, 0, "F");	break;
							case 700:	mxmlNewText(stepxml, 0, "G");	break;
							case 900:	mxmlNewText(stepxml, 0, "A");	break;
							case 1100:	mxmlNewText(stepxml, 0, "B");	break;
						}
						// alter
						screen_accidental = note_get_screen_accidental(note);
						if (parenthesized_quartertones && screen_accidental.r_den > 2) {
                            if (parenthesized_quartertones == 30061984) { // yeah, that's bad and private :-) It's however a very bad convention, but I needed it now.
                                screen_accidental = screen_accidental > 0 ? screen_accidental + genrat(1, 4) : screen_accidental - genrat(1, 4);
                                add_par_qrtrtone = 1;
                            } else {
                                screen_accidental = rat_rat_diff(screen_accidental, genrat(1, 4));
                                add_par_qrtrtone = 1;
                            }
						}
						double alter = rat2double(rat_long_prod(screen_accidental, 2));
						if (alter == (int) alter)
							mxmlNewInteger(alterxml, alter);
						else
							mxmlNewReal(alterxml, alter);
							
						// octave
						mxmlNewInteger(octavexml, note_get_screen_midicents(note) / 1200 - 1);
					} else {
						mxmlNewElement(notexml, "rest");
					}

					if (!is_grace) {
						// duration
						bach_mxmlNewIntElement(notexml, "duration", 0, dur.r_num * divisions / dur.r_den);
					}

					
					if (note) {
						long mc_alter;
						acc_name = bach_xml_acc2name(screen_accidental, &mc_alter);
						midicents = screen_midicents + mc_alter;		
						
						if (note->tie_from) { // stop the tie and delete this item
							mxml_node_t *tie = mxmlNewElement(notexml, "tie");
							mxmlElementSetAttr(tie, "type", "stop");
						}
						
						if (note->tie_to) {
							mxml_node_t *tie = mxmlNewElement(notexml, "tie");
							mxmlElementSetAttr(tie, "type", "start");						
						}
					}
						
					mxml_node_t *type = mxmlNewElement(notexml, "type");
					mxmlNewText(type, 0, chordtype);
						
					for (i = 0; i < num_dots; i++)
						mxmlNewElement(notexml, "dot");
						
					if (note && note->show_accidental) {
						mxml_node_t *accidental = bach_mxmlNewTextElement(notexml, "accidental", 0, acc_name);
						if (add_par_qrtrtone)
							mxmlElementSetAttr(accidental, "parentheses", "yes");
					}
						
					if (num_tuplets) {
						mxml_node_t *time_modification = mxmlNewElement(notexml, "time-modification");
						bach_mxmlNewIntElement(time_modification, "actual-notes", 0, tuplet_info[0].actual_notes);
						bach_mxmlNewIntElement(time_modification, "normal-notes", 0, tuplet_info[0].normal_notes);
						bach_mxmlNewTextElement(time_modification, "normal-type", 0, normal_type);
						for (i = 0; i < tuplet_info[0].normal_dots; i++)
							mxmlNewElement(time_modification, "normal-dot");
					}
						
					if (note) {
                        
                        
                        /// noteheads
                        /*
                         The notehead element indicates shapes other than the open
                         and closed ovals associated with note durations. The element
                         value can be slash, triangle, diamond, square, cross, x,
                         circle-x, inverted triangle, arrow down, arrow up, slashed,
                         back slashed, normal, cluster, circle dot, left triangle,
                         rectangle, or none. For shape note music, the element values
                         do, re, mi, fa, fa up, so, la, and ti are also used,
                         corresponding to Aikin's 7-shape system. The fa up shape is
                         typically used with upstems; the fa shape is typically used
                         with downstems or no stems.
                         
                         The arrow shapes differ from triangle and inverted triangle
                         by being centered on the stem. Slashed and back slashed
                         notes include both the normal notehead and a slash. The
                         triangle shape has the tip of the triangle pointing up;
                         the inverted triangle shape has the tip of the triangle
                         pointing down. The left triangle shape is a right triangle
                         with the hypotenuse facing up and to the left.
                         */
                        if (export_noteheads && note->notehead_ID != k_NOTEHEAD_DEFAULT) {
                            const char *notehead_txt = NULL;
                            const char *filled_txt = NULL;
                            switch (note->notehead_ID) {
                                case k_NOTEHEAD_WHITE_NOTE:
                                    if (chord->figure.r_den != 2) {
                                        notehead_txt = "normal";
                                        filled_txt = "no";
                                    }
                                    break;
                                case k_NOTEHEAD_BLACK_NOTE:
                                    if (chord->figure.r_den < 4) {
                                        notehead_txt = "normal";
                                        filled_txt = "yes";
                                    }
                                    break;
                                case k_NOTEHEAD_CROSS:
                                    notehead_txt = "x";
                                    break;
                                case k_NOTEHEAD_DIAMOND:
                                    notehead_txt = "diamond";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_PLUS:
                                    notehead_txt = "cross";
                                    break;
                                case k_NOTEHEAD_BLACK_SQUARE:
                                    notehead_txt = "square";
                                    filled_txt = "yes";
                                    break;
                                case k_NOTEHEAD_WHITE_SQUARE:
                                    notehead_txt = "square";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_SQUARE:
                                    notehead_txt = "square";
                                    break;
                                case k_NOTEHEAD_BLACK_TRIANGLE:
                                    notehead_txt = "triangle";
                                    filled_txt = "yes";
                                    break;
                                case k_NOTEHEAD_WHITE_TRIANGLE:
                                    notehead_txt = "triangle";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_TRIANGLE:
                                    notehead_txt = "triangle";
                                    break;
                                case k_NOTEHEAD_DOUBLE_WHOLE_NOTE:
                                case k_NOTEHEAD_WHOLE_NOTE:
                                case k_NOTEHEAD_ACCENT:
                                case k_NOTEHEAD_BLACK_RHOMBUS:
                                case k_NOTEHEAD_WHITE_RHOMBUS:
                                default:
                                    break;
                            }
                            if (notehead_txt) {
                                mxml_node_t *notehead = bach_mxmlNewTextElement(notexml, "notehead", 0, notehead_txt);
                                if (filled_txt) {
                                    mxmlElementSetAttr(notehead, "filled", filled_txt);
                                }
                            }
                        }

                        
						// staff
						long staff = 0;
						if (staves > 1) {
							for (staff = 0; staff < staves - 1 && screen_midicents <= splitpoints[staff]; staff++) 
								;
							bach_mxmlNewIntElement(notexml, "staff", 0, staff + 1);
						}

						for (i = 0; i < beam_info.num_beams; i++) {
							mxml_node_t *beam = mxmlNewElement(notexml, "beam");
							char beamnumber_txt[16];
							const char *beamtype;
							snprintf_zero(beamnumber_txt, 16, "%ld", i + 1);
							mxmlElementSetAttr(beam, "number", beamnumber_txt);
							switch (beam_info.beam_type[i]) {
								case k_XML_START:		beamtype = "begin";			break;
								case k_XML_STOP:		beamtype = "end";			break;
								case k_XML_CONTINUE:	beamtype = "continue";		break;
								case k_XML_HOOK_LEFT:	beamtype = "backward hook";	break;
								case k_XML_HOOK_RIGHT:	beamtype = "forward hook";	break;
								default:				beamtype = "";				break;
							}
							mxmlNewText(beam, 0, beamtype);
						}
					}
					
					mxml_node_t *notations = mxmlNewElement(notexml, "notations");
					
					if (note) {
						if (note->tie_from) { // stop the tie and delete this item
							mxml_node_t *tied = mxmlNewElement(notations, "tied");
							mxmlElementSetAttr(tied, "type", "stop");
						}
						
						if (note->tie_to) {
							mxml_node_t *tied = mxmlNewElement(notations, "tied");
							mxmlElementSetAttr(tied, "type", "start");						
						}
					}
                    
                    if (export_glissandi) {
                        if (open_gliss && open_gliss->l_head && note && (!note->tie_from || x->r_ob.dl_spans_ties == 0)) {
                            mxml_node_t *slide = mxmlNewElement(notations, "slide");
                            mxmlElementSetAttr(slide, "line-type", "solid");
                            char numtxt[64];
                            snprintf_zero(numtxt, 64, "%ld", hatom_getlong(&open_gliss->l_head->l_hatom));
                            mxmlElementSetAttr(slide, "number", numtxt);
                            mxmlElementSetAttr(slide, "type", "stop");
                            llll_behead(open_gliss);
                            at_least_a_gliss_has_ended = true;
                        }
                        if (note && note->lastbreakpoint->delta_mc != 0 && (!note->tie_from || x->r_ob.dl_spans_ties == 0)) {
                            // finding first free gliss id
                            long curr_gliss_id = 0;
                            for (long i = 1; i <= 6; i++) {
                                if (!is_long_in_llll_first_level(open_gliss, i) && !is_long_in_llll_first_level(open_gliss_chord, i)) {
                                    curr_gliss_id = i;
                                    break;
                                }
                            }
                            if (curr_gliss_id > 0) {
                                mxml_node_t *slide = mxmlNewElement(notations, "slide");
                                mxmlElementSetAttr(slide, "line-type", "solid");
                                char numtxt[64];
                                snprintf_zero(numtxt, 64, "%ld", curr_gliss_id);
                                mxmlElementSetAttr(slide, "number", numtxt);
                                mxmlElementSetAttr(slide, "type", "start");
                                llll_appendlong(open_gliss_chord, curr_gliss_id);
                                curr_gliss_id++;
                            }
                        }
                    }
					
					if (num_tuplets) {
						long are_there_tuplets = 0;
						for (i = 0; i < num_tuplets; i++) { // first, see if there is at least one tuplet to write
							if ((are_there_tuplets = tuplet_info[i].type != k_XML_CONTINUE))
								break; // that is, it is a start or stop
						}
						if (are_there_tuplets) {
							for ( ; i < num_tuplets; i++) {
								if (tuplet_info[i].type == k_XML_CONTINUE)
									continue;
								mxml_node_t *tuplet = mxmlNewElement(notations, "tuplet");
								const char *tuplet_type;
								switch (tuplet_info[i].type) {
									case k_XML_START:	tuplet_type = "start";	break;
									case k_XML_STOP:	tuplet_type = "stop";	break;
									default:			tuplet_type = "";		break;
								}
								mxmlElementSetAttr(tuplet, "type", tuplet_type);
								char txt[16];
								snprintf_zero(txt, 16, "%ld", i + 1);
								mxmlElementSetAttr(tuplet, "number", txt);
								mxml_node_t *tuplet_actual = mxmlNewElement(tuplet, "tuplet-actual");
								bach_mxmlNewIntElement(tuplet_actual, "tuplet-number", 0, tuplet_info[i].tuplet_actual_number);
								xml_value_to_name(tuplet_info[i].tuplet_actual_type.r_den, txt);
								bach_mxmlNewTextElement(tuplet_actual, "tuplet-type", 0, txt);
								long j;
								for (j = 0; j < tuplet_info[i].tuplet_actual_dots; j++)
									mxmlNewElement(tuplet_actual, "tuplet-dot");
								
								mxml_node_t *tuplet_normal = mxmlNewElement(tuplet, "tuplet-normal");
								bach_mxmlNewIntElement(tuplet_normal, "tuplet-number", 0, tuplet_info[i].tuplet_normal_number);
								xml_value_to_name(tuplet_info[i].tuplet_normal_type.r_den, txt);
								bach_mxmlNewTextElement(tuplet_normal, "tuplet-type", 0, txt);
								for (j = 0; j < tuplet_info[i].tuplet_normal_dots; j++)
									mxmlNewElement(tuplet_normal, "tuplet-dot");
							}
						}
					}
                    
					 
					if (note && (note->num_articulations > 0 || (isfirstnote && chord->num_articulations > 0) || articulations_slot >= 0)) {
						long i;
						mxml_node_t *ornaments = NULL;
						mxml_node_t *technical = NULL;
						mxml_node_t *articulations = mxmlNewElement(notations, "articulations");
						/* <!ELEMENT ornaments
						 (((trill-mark | turn | delayed-turn | inverted-turn |
						 delayed-inverted-turn | vertical-turn | shake |
						 wavy-line | mordent | inverted-mordent | schleifer |
						 tremolo | other-ornament), accidental-mark*)*)>
						 
						 <!ELEMENT technical
						 ((up-bow | down-bow | harmonic | open-string |
						 thumb-position | fingering | pluck | double-tongue |
						 triple-tongue | stopped | snap-pizzicato | fret |
						 string | hammer-on | pull-off | bend | tap | heel |
						 toe | fingernails | hole | arrow | handbell | 
						 other-technical)*)>
						 
						 <!ELEMENT articulations
						 ((accent | strong-accent | staccato | tenuto |
						 detached-legato | staccatissimo | spiccato |
						 scoop | plop | doit | falloff | breath-mark | 
						 caesura | stress | unstress | other-articulation)*)>
						 
						 <!ELEMENT fermata  (#PCDATA)>
						 */
						
						// 1. first the ornaments, who might require different <ornaments> elements
                        {
                            //      OLD WAY of assigning articulations:
                            for (i = 0; i < note->num_articulations; i++) {
                                long id = note->articulation[i].articulation_ID;
                                bach_xml_add_ornament(atp, &ornaments, notations, id);
                            }
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++) {
                                    long id = chord->articulation[i].articulation_ID;
                                    bach_xml_add_ornament(atp, &ornaments, notations, id);
                                }
                            }
                            
                            //      NEW WAY of assigning articulations:
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                    bach_xml_add_ornament(atp, &ornaments, notations, ((t_articulation *)slotitem->item)->articulation_ID);
                                }
                            }
                        }
                        
                        
                        
                        // 2. then technical and articulations
                        {
                            // old way (the weird interleaved-fashion of this part is due to the fact that standard articulations must apparently
                            // be put BEFORE other-articulations in order to be properly parsed by Finale
                            for (i = 0; i < note->num_articulations; i++)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, note->articulation[i].articulation_ID, 1);
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, chord->articulation[i].articulation_ID, 1);
                            }

                            for (i = 0; i < note->num_articulations; i++)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, note->articulation[i].articulation_ID, 2);

                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, chord->articulation[i].articulation_ID, 2);
                            }

                            
                            // new way
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 1);
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 2);
                            }
                        }
                        
						// 3. then fermatas (hopefully one!)
                        {
                            // old way:
                            for (i = 0; i < note->num_articulations; i++) {
                                long id = note->articulation[i].articulation_ID;
                                switch (id) {
                                    case k_ARTICULATION_FERMATA:
                                        bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                }
                            }
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++) {
                                    long id = chord->articulation[i].articulation_ID;
                                    switch (id) {
                                        case k_ARTICULATION_FERMATA:
                                            bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                    }
                                }
                            }
                            
                            // new way:
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                    t_articulation *art = ((t_articulation *)slotitem->item);
                                    if (art->articulation_ID == k_ARTICULATION_FERMATA)
                                        bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                }
                            }
                        }
                        
                        
                    } else if (is_rest && articulations_slot >= 0) {
                        mxml_node_t *ornaments = mxmlNewElement(notations, "ornaments");
                        mxml_node_t *technical = mxmlNewElement(notations, "technical");
                        mxml_node_t *articulations = mxmlNewElement(notations, "articulations");
                        // 1. first the ornaments, who might require different <ornaments> elements
                        {
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                bach_xml_add_ornament(atp, &ornaments, notations, ((t_articulation *)slotitem->item)->articulation_ID);
                            }
                        }

                        // 2. then technical and articulations
                        {
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 1);
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 2);
                        }
                        
                        // 3. then fermatas (hopefully one!)
                        {
                            // new way:
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                t_articulation *art = ((t_articulation *)slotitem->item);
                                if (art->articulation_ID == k_ARTICULATION_FERMATA)
                                    bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                            }
                        }
                        
                    }
					
                    // lyrics
                    if (export_lyrics && isfirstnote && chord->lyrics && chord->lyrics->label) { // first note in chord: we'll attach lyrics to it
                        mxml_node_t *lyricxml = mxmlNewElement(notexml, "lyric");
                        mxmlElementSetAttr(lyricxml, "number", "1");
                        
                        if (chord->lyrics->lyrics_dashed_extension)
                            bach_mxmlNewTextElement(lyricxml, "syllabic", 0, currently_ongoing_lyrics_syllable ? "middle" : "begin");
                        else
                            bach_mxmlNewTextElement(lyricxml, "syllabic", 0, currently_ongoing_lyrics_syllable ? "end" : "single");
                        currently_ongoing_lyrics_syllable = chord->lyrics->lyrics_dashed_extension;
                        
                        bach_mxmlNewTextElement(lyricxml, "text", 0, chord->lyrics->label);
                        
                        // possibly to do: add word extension?
                    }
                    
					
				}
                
                if (open_gliss) {
                    if (at_least_a_gliss_has_ended)
                        llll_clear(open_gliss);
                    if (open_gliss_chord)
                        llll_chain(open_gliss, open_gliss_chord);
                }
			}
            
            if (voices_left_in_voiceensemble == 1) {
                char barline = measure->end_barline->barline_type;
                if (measure->next == NULL && barline == k_BARLINE_AUTOMATIC)
                    barline = k_BARLINE_FINAL;
                if (barline != k_BARLINE_AUTOMATIC) {
                    const char *type = "regular";
                    mxml_node_t *barlinexml = mxmlNewElement(measurexml, "barline");
                    switch (barline) {
                        case k_BARLINE_NORMAL:	type = "regular";		break;
                        case k_BARLINE_DASHED:	type = "dashed";		break;
                        case k_BARLINE_POINTS:	type = "dotted";		break;
                        case k_BARLINE_DOUBLE:	type = "light-light";	break;
                        case k_BARLINE_FINAL:	type = "light-heavy";	break;
                        case k_BARLINE_HIDDEN:	type = "none";			break;
                        case k_BARLINE_SOLID:	type = "heavy";			break;
                    }
                    bach_mxmlNewTextElement(barlinexml, "bar-style", 0, type);
                }
            }
            if (!measure->next && currently_open_hairpin)
                    xmlwrite_close_hairpin(measurexml, &currently_open_hairpin, 0);
        
		}
        
        if (voices_left_in_voiceensemble == 1) {
            partidx++;
            llll_clear(voice_ensemble_measures);
            new_voice_ensemble = true;
        } else {
            --voices_left_in_voiceensemble;
            new_voice_ensemble = false;
        }
        
        if (open_gliss)
            llll_free(open_gliss);
	}
    
    
    unlock_general_mutex((t_notation_obj *)x);
	
	t_filehandle fh;
	//bach_fix_filename_extension(&filename_sym, "xml");
	switch (bach_openfile_write(filename_sym, "Untitled.xml", &fh, &filetype, 1, &outtype, NULL, NULL)) {
        case FILE_ERR_NONE:
            break;
        case FILE_ERR_CANCELED:
            goto score_dowritexml_error_dontclose;
            break;
        case FILE_ERR_CANTOPEN:
            if (filename_sym)
                object_error((t_object *) x, "could not create file: %s", filename_sym->s_name);
            else
                object_error((t_object *) x, "could not create file");
            goto score_dowritexml_error_dontclose;
            break;
    }
	
	mxmlSaveMaxFile(scorexml, fh, whitespace_cb);

//score_dowritexml_error_close:
	sysfile_close(fh);
score_dowritexml_error_dontclose:
    llll_free(voice_ensemble_measures);
    llll_free(numparts_llll);
	mxmlDelete(scorexml);
	return err;
}


const char *bach_xml_acc2name(t_rational acc, long *mc_alter) 
{
	const char *acc_name;
	long dummy_alter;
	if (!mc_alter)
		mc_alter = &dummy_alter;
	if (acc.r_num == 0) {
		acc_name = "natural";
		*mc_alter = 0;
	} else if (acc.r_num == 1 && acc.r_den == 4) {
		acc_name = "quarter-sharp";
		*mc_alter = 50;
	} else if (acc.r_num == 1 && acc.r_den == 2) {
		acc_name = "sharp";
		*mc_alter = 100;
	} else if (acc.r_num == 3 && acc.r_den == 4) {
		acc_name = "three-quarter-sharp";
		*mc_alter = 150;
	} else if (acc.r_num == 2 && acc.r_den == 1) {
		acc_name = "double-sharp";
		*mc_alter = 200;
	} else if (acc.r_num == - 1 && acc.r_den == 4) {
		acc_name = "quarter-flat";
		*mc_alter = 50;
	} else if (acc.r_num == -1 && acc.r_den == 2) {
		acc_name = "flat";
		*mc_alter = 100;
	} else if (acc.r_num == -3 && acc.r_den == 4) {
		acc_name = "three-quarter-flat";
		*mc_alter = 150;
	} else if (acc.r_num == -2 && acc.r_den == 1) {
		acc_name = "double-flat";
		*mc_alter = 200;
	} else {
		acc_name = "unknown";
		*mc_alter = 0;
	}
	return acc_name;
}

const char *whitespace_cb(mxml_node_t *node, int where)
{
	static long prev = MXML_WS_AFTER_CLOSE;
	static char indent[256];
	const char *rv = "";
	static long open_count;
	static long close_count;
//	static long guard = 6;
	static long ws_lvl = -2;
//	static long safe = 0;
/*	if (node) {
		const char *name = mxmlGetElement(node);
		if (!strcmp(name, "dot")) {
			char foo = 0;
		}
	}*/
		
	
	if (where < 0) {
		ws_lvl = -2;
		prev = MXML_WS_AFTER_CLOSE;
		return NULL;
	}
	
/*	if (ws_lvl > guard) {
		long foo = 0;
		if (safe)
			return "\n      ";
	}*/
/*	
	if (prev == MXML_WS_BEFORE_OPEN && where != MXML_WS_AFTER_OPEN) {
		long foo = 0;
	}
	if (prev == MXML_WS_BEFORE_CLOSE && where != MXML_WS_AFTER_CLOSE) {
		long foo = 0;
	}
	if (where == MXML_WS_AFTER_OPEN && prev != MXML_WS_BEFORE_OPEN) {
		long foo = 0;
	}
	if (where == MXML_WS_AFTER_CLOSE && prev != MXML_WS_BEFORE_CLOSE) {
		long foo = 0;
	}
*/

	if (ws_lvl < 0) { 
		open_count = 0;
		close_count = 0;
		prev = MXML_WS_AFTER_CLOSE;
		if (where == MXML_WS_BEFORE_OPEN) {
			return ws_lvl++ == -2 ? NULL : "\n";
		} else 
			return NULL;
	}
	switch (where) {
		case MXML_WS_BEFORE_OPEN:
			indent[ws_lvl] = ws_lvl == 0 ? '\n' : '\t';
			indent[++ws_lvl] = 0;
			open_count++;
			if (prev == MXML_WS_AFTER_OPEN)
				rv = indent;
			else
				rv = indent + 1;
			break;
		case MXML_WS_AFTER_OPEN:
			rv = "";
			break;
		case MXML_WS_BEFORE_CLOSE:
			if (prev == MXML_WS_AFTER_CLOSE)
				rv = indent + 1;
			else
				rv = "";
			break;
		case MXML_WS_AFTER_CLOSE:
			//indent[ws_lvl] = ' ';
			indent[--ws_lvl] = 0;
			close_count++;
			rv = "\n";
			break;
		default:
			rv = ""; // should never happen
	}
	prev = where;
	return *rv ? rv : NULL;
}



mxml_node_t *bach_mxmlNewTextElement(mxml_node_t *parent, const char *name, int whitespace, const char *string)
{
	mxml_node_t *node = mxmlNewElement(parent, name);
	mxmlNewText(node, whitespace, string);
	return node;
}

mxml_node_t *bach_mxmlNewIntElement(mxml_node_t *parent, const char *name, int whitespace, int value)
{
	mxml_node_t *node = mxmlNewElement(parent, name);
	mxmlNewInteger(node, value);
	return node;
}

mxml_node_t *bach_mxmlNewRealElement(mxml_node_t *parent, const char *name, int whitespace, double value)
{
	mxml_node_t *node = mxmlNewElement(parent, name);
	mxmlNewReal(node, value);
	return node;
}


void xml_value_to_name(long den, char *chordtype)
{
	switch (den) {	
		case 1:		strcpy(chordtype, "whole");				break;
		case 2:		strcpy(chordtype, "half");				break;
		case 4:		strcpy(chordtype, "quarter");			break;
		case 8:		strcpy(chordtype, "eighth");			break;
		case 32:	strcpy(chordtype, "32nd");				break;
		default:	sprintf(chordtype, "%ldth", den);		break;
	}
}

t_rational xml_name_and_dots_to_value(const char *chordtype, long dots)
{
	long figure_den;
	if (!strcmp(chordtype, "whole"))
		figure_den = 1;
	else if (!strcmp(chordtype, "half"))
		figure_den = 2;
	else if (!strcmp(chordtype, "quarter"))
		figure_den = 4;
	else if (!strcmp(chordtype, "eighth"))
		figure_den = 8;
	else figure_den = strtol(chordtype, NULL, 0);
	return figure_and_dots_to_figure_sym_duration(genrat(1, figure_den), dots);
}

mxml_node_t *bach_xml_add_clef(mxml_node_t *node, const char *sign, long line, long octave, const char *number)
{
	mxml_node_t *clefxml = mxmlNewElement(node, "clef");
	bach_mxmlNewTextElement(clefxml, "sign", 0, sign);
	bach_mxmlNewIntElement(clefxml, "line", 0, line);
	if (octave)
		bach_mxmlNewIntElement(clefxml, "clef-octave-change", 0, octave);
	if (number)
		mxmlElementSetAttr(clefxml, "number", number);
	return clefxml;
}


void bach_xml_add_ornament(const t_articulations_typo_preferences *atp, mxml_node_t **ornaments, mxml_node_t *notations, long id)
{
    if (*ornaments == NULL)
        *ornaments = mxmlNewElement(notations, "ornaments");

    if (id >= k_NUM_STANDARD_ARTICULATIONS) {
        // nonstandard
        if (atp->artpref[id].xmlornament && atp->artpref[id].xmlornament != _llllobj_sym_none)
            mxmlNewElement(*ornaments, atp->artpref[id].xmlornament->s_name);
        return;
    }
    
    // standard
    switch (id) {
        case k_ARTICULATION_TRILL:
            mxmlNewElement(*ornaments, "trill-mark");
            break;
        case k_ARTICULATION_TRILL_FLAT:
        case k_ARTICULATION_TRILL_SHARP:
            mxmlNewElement(*ornaments, "trill-mark");
            bach_mxmlNewTextElement(notations, "accidental-mark", 0, id == k_ARTICULATION_TRILL_FLAT ? "flat" : "sharp");
            *ornaments = mxmlNewElement(notations, "ornaments");
            break;
        case k_ARTICULATION_MORDENT_DOWN:
            mxmlNewElement(*ornaments, "mordent");
            break;
        case k_ARTICULATION_MORDENT_UP:
            mxmlNewElement(*ornaments, "inverted-mordent");
            break;
        case k_ARTICULATION_DOUBLE_MORDENT:
            mxmlNewElement(*ornaments, "wavy-line");
            break;
        case k_ARTICULATION_GRUPPETTO:
            mxmlNewElement(*ornaments, "turn");
            break;
        case k_ARTICULATION_TREMOLO3:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 3);
            break;
        case k_ARTICULATION_TREMOLO2:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 2);
            break;
        case k_ARTICULATION_TREMOLO1:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 1);
            break;
    }
}


void bach_xml_set_custom_articulation_attributes(const t_articulations_typo_preferences *atp, mxml_node_t *node, long articulation_id)
{
    if (atp->artpref[articulation_id].font)
        mxmlElementSetAttr(node, "font-family", atp->artpref[articulation_id].font->s_name);

    {
        char size[256];
        snprintf_zero(size, 256, "%ld", (long)round(atp->artpref[articulation_id].base_pt));
        mxmlElementSetAttr(node, "font-size", size);
    }
    
    if (atp->artpref[articulation_id].positioning & k_ARTICULATION_POSITIONING_ABOVE_NOTE)
        mxmlElementSetAttr(node, "placement", "above");
    else if (atp->artpref[articulation_id].positioning & k_ARTICULATION_POSITIONING_BELOW_NOTE)
        mxmlElementSetAttr(node, "placement", "below");
    
    // TO BE BETTER IMPLEMENTED: export custom positioning
}


// "other-articulation" and "other-technical" seem to have to be the LAST elements in the list. Hence, we deal with standard ones before
// mode = 1 standard only, mode = 2 nonstandard only
void bach_xml_add_technical_or_articulation(const t_articulations_typo_preferences *atp, mxml_node_t **technical, mxml_node_t **articulations, mxml_node_t *notations, long id, char mode)
{
    if (id >= k_NUM_STANDARD_ARTICULATIONS) {
        // nonstandard
        if (atp->artpref[id].xmltechnical && atp->artpref[id].xmltechnical != _llllobj_sym_none) {
            if (atp->artpref[id].xmltechnical == gensym("custom") || atp->artpref[id].xmltechnical == gensym("other-technical")) {
                if (mode != 1) {
                    char *buf = articulation_to_text_buf((t_articulations_typo_preferences *)atp, id);
                    if (*technical == NULL)
                        *technical = mxmlNewElement(notations, "technical");
                    bach_xml_set_custom_articulation_attributes(atp, bach_mxmlNewTextElement(*technical, "other-technical", 0, buf), id);
                    bach_freeptr(buf);
                }
            } else {
                if (mode != 2) {
                    if (*technical == NULL)
                        *technical = mxmlNewElement(notations, "technical");
                    mxmlNewElement(*technical, atp->artpref[id].xmltechnical->s_name);
                }
            }
        }
        if (atp->artpref[id].xmlarticulations && atp->artpref[id].xmlarticulations != _llllobj_sym_none) {
            if (atp->artpref[id].xmlarticulations == gensym("custom") || atp->artpref[id].xmlarticulations == gensym("other-articulation")) {
                if (mode != 1) {
                    char *buf = articulation_to_text_buf((t_articulations_typo_preferences *)atp, id);
                    if (*articulations == NULL)
                        *articulations = mxmlNewElement(notations, "articulations");
                    bach_xml_set_custom_articulation_attributes(atp, bach_mxmlNewTextElement(*articulations, "other-articulation", 0, buf), id);
                    bach_freeptr(buf);
                }
            } else {
                if (mode != 2) {
                    if (*articulations == NULL)
                        *articulations = mxmlNewElement(notations, "articulations");
                    mxmlNewElement(*articulations, atp->artpref[id].xmlarticulations->s_name);
                }
            }
        }
        return;
    }
    
    if (mode == 2)
        return;
    
    switch (id) {
            case k_ARTICULATION_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "staccato");
            break;
			case k_ARTICULATION_ACCENT:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            break;
								case k_ARTICULATION_PORTATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "tenuto");
            break;
								case k_ARTICULATION_ACCENT_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            mxmlNewElement(*articulations, "staccato");
            break;
								case k_ARTICULATION_ACCENT_PORTATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            mxmlNewElement(*articulations, "tenuto");
            break;
								case k_ARTICULATION_PORTATO_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "tenuto");
            mxmlNewElement(*articulations, "staccato");
            break;
								case k_ARTICULATION_STACCATISSIMO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "staccatissimo");
            break;
								case k_ARTICULATION_MARTELLATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "spiccato");
            break;
								case k_ARTICULATION_MARTELLATO_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "spiccato");
            mxmlNewElement(*articulations, "staccato");
            break;
								case k_ARTICULATION_HARMONIC:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "harmonic");
            break;
								case k_ARTICULATION_LEFT_HAND_PIZZICATO:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            bach_mxmlNewTextElement(*technical, "tap", 0, "+");
            break;
								case k_ARTICULATION_BOWING_UP:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "up-bow");
            break;
								case k_ARTICULATION_BOWING_DOWN:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "down-bow");
            break;
    }
}


mxml_type_t xml_load_cb(mxml_node_t *node)
{
	const char *name = mxmlGetElement(node);
	
	if (!strcmp(name, "divisions") ||
		!strcmp(name, "fifths") ||
		!strcmp(name, "beats") ||
		!strcmp(name, "beat-type") ||
		!strcmp(name, "line") ||
		!strcmp(name, "duration") ||
		!strcmp(name, "staff") ||
		!strcmp(name, "octave") ||
		!strcmp(name, "display-octave") ||
		!strcmp(name, "actual-notes") ||
		!strcmp(name, "normal-notes") ||
		!strcmp(name, "tuplet-number") ||
		!strcmp(name, "dynamics") ||
		!strcmp(name, "tremolo") ||
		!strcmp(name, "clef-octave-change") ||
        !strcmp(name, "voice") ||
		!strcmp(name, "offset"))
		return MXML_INTEGER;
	else if (!strcmp(name, "alter") ||
			 !strcmp(name, "key-alter"))
		return MXML_REAL;
	else if (!strcmp(name, "per-minute"))
		return MXML_TEXT;
    else if (!strcmp(name, "words"))
        return MXML_OPAQUE;
	else
		return MXML_TEXT;
}


// av:
// long: format

long rat2ticks(const t_rational *pos, long time_division)
{
	return pos->r_num * 4. / pos->r_den * time_division + 0.5;
}

t_rational ticks2rat(long ticks, long time_division)
{
	return genrat(ticks, 4 * time_division);
}

t_max_err score_dowritemidi(t_score *x, t_symbol *s, long ac, t_atom *av)
{
	long format = 0;
	long num_tracks;
	long time_division = 960;
	double tempo = 60;
	long tempo_interp_sampling_interval = 240;
	long timesig_num = 4, timesig_den = 4; // unused for now, that's ok
	long i;
	long voice_num;
	t_llll **this_track_ll, **track_ll;
	t_scorevoice *this_scorevoice;
	t_marker *this_marker;
	unsigned char *buffer = NULL;
	long first_onset = 0;
	long export_markers = 1;
	t_llll *voices_to_write = NULL;
	t_scorevoice *firstvoice = NULL;
	t_symbol *filename_sym = NULL;
	long ok = 1;
	t_llllelem *this_voicenum_elem;
	long num_voices = 0;
	t_llll *arguments = (t_llll *) atom_getobj(av);
	t_ptr_size count = 0;
	t_scorevoice *longest_voice = NULL;
	long longest_voice_num = 0;
	t_timepoint longest_voice_start;

	
	llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiil",
				   _sym_filename, &filename_sym,
				   gensym("exportmarkers"), &export_markers,
				   gensym("format"), &format,
				   gensym("resolution"), &time_division,
				   gensym("temporampsamplingrate"), &tempo_interp_sampling_interval,
				   gensym("voices"), &voices_to_write);
	
    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_behead(arguments);
    }
    
    lock_general_mutex((t_notation_obj *)x);
	
	prepare_voices_to_write((t_notation_obj *) x, &voices_to_write);
	num_voices = voices_to_write->l_size;
	bach_assert_objerror_goto(x, ok = (num_voices > 0), "No valid voices for export", score_dowritemidi_error);
	firstvoice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&voices_to_write->l_head->l_hatom));
	num_tracks = format == 0 ? 1 : num_voices + 1;
	
	// first, prepare our intermediary structure (guess what? it's an llll!)
	this_track_ll = track_ll = (t_llll **) bach_newptr(num_tracks * sizeof(t_llll *));
	for (i = 0; i < num_tracks; i++)
		track_ll[i] = llll_get();
	
	// now set the key signature, taken from the first voice
	append_keysig_to_midi_export(track_ll[0], &firstvoice->v_ob);
	
	// let's do the markers
	longest_voice = get_longest_scorevoice(x);
	longest_voice_num = longest_voice->v_ob.number;
	longest_voice_start = build_timepoint_with_voice(0, long2rat(0), longest_voice_num);

	for (this_marker = x->r_ob.firstmarker; this_marker; this_marker = this_marker->next) {
		t_timepoint this_marker_tp, this_voice_start;
		t_scorevoice *this_marker_voice;
		if (this_marker->attach_to == k_MARKER_ATTACH_TO_MS) { // if the marker is attached to ms, we transform the ms in symbolic duration
			this_marker_tp = ms_to_timepoint((t_notation_obj *) x, this_marker->position_ms, longest_voice_num, k_MS_TO_TP_RETURN_INTERPOLATION);
			this_marker_voice = longest_voice;
			this_voice_start = longest_voice_start;
		} else {
			t_measure *this_marker_measure = (t_measure *) shashtable_retrieve(x->r_ob.IDtable, this_marker->measure_attach_ID);
			this_marker_voice = this_marker_measure->voiceparent;
			long this_marker_voicenum = this_marker_voice->v_ob.number;
			this_voice_start = build_timepoint_with_voice(0, long2rat(0), this_marker_voicenum);
			this_marker_tp = build_timepoint_with_voice(this_marker_measure->measure_number, this_marker->r_sym_pim_attach, this_marker_voicenum);
		}
		t_rational this_marker_pos_rat = get_sym_durations_between_timepoints(this_marker_voice, this_voice_start, this_marker_tp);

		t_atom *av = NULL;
		long ac = llll_deparse(this_marker->r_it.names, &av, 0, 0);
		t_atomarray *name = atomarray_new_debug(ac, av);
		append_marker_to_midi_export(track_ll[0], name, rat2ticks(&this_marker_pos_rat, time_division));
		bach_freeptr(av);
	}
	
	// now, one voice after another, insert all the notes
	for (this_voicenum_elem = voices_to_write->l_head; this_voicenum_elem; this_voicenum_elem = this_voicenum_elem->l_next) {
		voice_num = hatom_getlong(&this_voicenum_elem->l_hatom);
		this_scorevoice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&this_voicenum_elem->l_hatom));
		t_measure *this_measure;
		t_chord *this_chord;
		long channel = this_scorevoice->v_ob.midichannel % 16 - 1;
		t_timepoint voice_start_tp;
		
		if (format == 1)
			this_track_ll++;
		
		voice_start_tp = build_timepoint_with_voice(0, long2rat(0), voice_num);

		for (this_measure = this_scorevoice->firstmeasure; this_measure; this_measure = this_measure->next) {
			long this_measure_number = this_measure->measure_number; // 0-based
			t_timepoint measure_start_tp;
			t_rational measure_start_rat;
			long new_ts_num = this_measure->timesignature.numerator;
			long new_ts_den = this_measure->timesignature.denominator;
			t_tempo *this_tempo = this_measure->firsttempo;
			
			measure_start_tp = build_timepoint_with_voice(this_measure_number, long2rat(0), voice_num);
			measure_start_rat = get_sym_durations_between_timepoints(this_scorevoice, voice_start_tp, measure_start_tp);
			
			if ((this_measure_number == 0 && voice_num == 0) || new_ts_num != timesig_num || new_ts_den != timesig_den) {
				timesig_num = new_ts_num;
				timesig_den = new_ts_den;
				append_timesig_to_midi_export(track_ll[0], timesig_num, timesig_den, rat2ticks(&measure_start_rat, time_division));
			}
			
			// if there is no tempo at the beginning of the score, start with the default tempo 
			if (voice_num == 0 && this_measure_number == 0 && (this_tempo == NULL || this_tempo->changepoint.r_num != 0))
				append_tempo_to_midi_export(track_ll[0], tempo, 0);
			
			// set all the tempi in this measure, and all the tempo interpolations starting from it
			for ( ; this_tempo; this_tempo = this_tempo->next) {
				t_rational this_tempo_onset_rat = rat_rat_sum(measure_start_rat, this_tempo->changepoint);
				long this_tempo_onset_ticks = rat2ticks(&this_tempo_onset_rat, time_division);
				double new_tempo = rat2double(this_tempo->tempo_value);
				// if this tempo is different from the previous one, or we are at the beginning of the score, insert it
				if (tempo != new_tempo || (voice_num == 0 && this_measure_number == 0)) {
					append_tempo_to_midi_export(track_ll[0], new_tempo, this_tempo_onset_ticks);
					tempo = new_tempo;
				}
				// if it's a tempo ramp
				if (this_tempo->interpolation_type) {
					t_tempo *next_tempo = tempo_get_next(this_tempo);
					double next_tempo_bpm = rat2double(next_tempo->tempo_value);
					if (next_tempo_bpm != tempo) {
						t_measure *next_tempo_measure = next_tempo->owner;
						t_timepoint this_tempo_onset_tp = build_timepoint_with_voice(this_measure_number, this_tempo->changepoint, voice_num);
						t_timepoint next_tempo_onset_tp = build_timepoint_with_voice(next_tempo_measure->measure_number, next_tempo->changepoint, voice_num);
						t_rational next_tempo_onset_rat = get_sym_durations_between_timepoints(this_scorevoice, voice_start_tp, next_tempo_onset_tp);
						long next_tempo_onset_ticks = rat2ticks(&next_tempo_onset_rat, time_division);
						t_rational interp_dur_rat = get_sym_durations_between_timepoints(this_scorevoice, this_tempo_onset_tp, next_tempo_onset_tp);
						long interp_dur_ticks = rat2ticks(&interp_dur_rat, time_division);
						long interp_dur_ticks_div2 = interp_dur_ticks / 2;
						long this_tempo_sample;
						
						for (this_tempo_sample = this_tempo_onset_ticks; 
							 this_tempo_sample <= next_tempo_onset_ticks; 
							 this_tempo_sample += tempo_interp_sampling_interval) {
							long this_tempo_sampling_point;
							if (this_tempo_sample + interp_dur_ticks <= next_tempo_onset_ticks)
								this_tempo_sampling_point = this_tempo_sample + interp_dur_ticks_div2;
							else
								this_tempo_sampling_point = (next_tempo_onset_ticks - this_tempo_sample) / 2;
							double this_step_bpm = 1. / (((1. / tempo) * ((this_tempo_sample - this_tempo_onset_ticks) / interp_dur_ticks)) +
														 ((1. / next_tempo_bpm) * (next_tempo_onset_ticks - this_tempo_sample) / interp_dur_ticks));
							append_tempo_to_midi_export(track_ll[0], this_step_bpm, this_tempo_sample);
						}
					}
				}
			}

			for (this_chord = this_measure->firstchord; this_chord; this_chord = this_chord->next) {
				
				t_rational this_chord_onset_rat = rat_rat_sum(measure_start_rat, this_chord->play_r_sym_onset);
				t_rational this_chord_duration_rat = this_chord->play_r_sym_duration;

				// and now write its notes one by one
				t_note *this_note;
				for (this_note = this_chord->firstnote; this_note; this_note = this_note->next) {
					if (this_note->tie_from)
						continue;
					long pitch = (this_note->midicents + 50.) / 100.;
					long vel = this_note->velocity;
					t_rational noteoff_rat;
					if (this_note->tie_to) {
						t_note *last = note_get_last_in_tieseq(this_note);
						t_chord *last_chord = last->parent;
						t_timepoint start_tp, end_tp;
						start_tp = build_timepoint_with_voice(this_measure_number, this_chord->play_r_sym_onset, voice_num);
//						end_tp = build_timepoint_with_voice(last_chord->parent->measure_number, last_chord->play_r_sym_onset, voice_num);
                        end_tp = build_timepoint_with_voice(last_chord->parent->measure_number,
                                                            rat_rat_sum(last_chord->play_r_sym_onset, last_chord->play_r_sym_duration),
                                                            voice_num);
                        noteoff_rat = rat_rat_sum(this_chord_onset_rat, get_play_durations_between_timepoints(x, this_scorevoice, &start_tp, &end_tp));
					} else
						noteoff_rat = rat_rat_sum(this_chord_onset_rat, this_chord_duration_rat);

					long on_ticks = rat2ticks(&this_chord_onset_rat, time_division);
					long off_ticks = rat2ticks(&noteoff_rat, time_division);
					if (off_ticks > on_ticks + 1)
						off_ticks --;
					if (on_ticks < first_onset)
						first_onset = on_ticks;
					append_note_to_midi_export(*this_track_ll, E_NOTEON, pitch, vel, channel, on_ticks);
					append_note_to_midi_export(*this_track_ll, E_NOTEOFF, pitch, 0, channel, off_ticks);
				}
			}
		}
	}
    
    unlock_general_mutex((t_notation_obj *)x);
	
	// if there are notes before 0, then we have to fix up some stuff
	if (first_onset < 0) {
		// go get the key signature and put it at the beginning
		t_llllelem *elem;
		for (elem = track_ll[0]->l_head; elem; elem = elem->l_next) {
			t_llll *event_ll = hatom_getllll(&elem->l_hatom);
			long type = hatom_getlong(&event_ll->l_head->l_hatom);
			if (type == E_KEYSIG) {
				hatom_setlong(&event_ll->l_head->l_next->l_hatom, first_onset);
				break;
			}
		}
		
		// then get the first tempo, if it was at 0, and put it at the beginning
		for (elem = track_ll[0]->l_head; elem; elem = elem->l_next) {
			t_llll *event_ll = hatom_getllll(&elem->l_hatom);
			long type = hatom_getlong(&event_ll->l_head->l_hatom);
			if (type == E_TEMPO) {
				t_atom_long *time = &event_ll->l_head->l_next->l_hatom.h_w.w_long;
				if (*time == 0)
					*time = first_onset;
				break;
			}
		}
		
		// then add a first time signature at the very beginning, accounting for the whole duration of the notes before 0
		t_rational grace_timesig = ticks2rat(-first_onset, time_division);
		append_timesig_to_midi_export(track_ll[0], grace_timesig.r_num, grace_timesig.r_den, first_onset);
	}
	
	// now that we have parsed all the roll into our intermediate data structure, let's convert it into raw MIDI data and write them 
	count = create_raw_midi_data_buffer(track_ll, num_tracks, format, time_division, first_onset, &buffer);
	//bach_fix_filename_extension(&filename_sym, "mid");
	bach_write_binary_file(filename_sym, "Untitled.mid", 'Midi', &count, buffer);
	
	if (track_ll) {
		for (i = 0, this_track_ll = track_ll; i < num_tracks; this_track_ll++, i++) {
			if (*this_track_ll)
				llll_free(*this_track_ll);
		}
		bach_freeptr(track_ll);
	}
score_dowritemidi_error:
	if (*buffer)
		bach_freeptr(buffer);
	if (arguments)
		llll_free(arguments);
	return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}

t_rational get_play_durations_between_timepoints(t_score *x, t_scorevoice *voice, t_timepoint *tp1, t_timepoint *tp2) 
{
	t_rational rem1, rem2, result;
	rem1 = normalize_timepoint(x, tp1);
	rem2 = normalize_timepoint(x, tp2);
	result = get_sym_durations_between_timepoints(voice, *tp1, *tp2);
	result = rat_rat_sum(result, rem1);
	result = rat_rat_diff(result, rem2);
	return result;
}

t_rational normalize_timepoint(t_score *x, t_timepoint *tp)
{
	if (tp->pt_in_measure.r_num < 0) {
		if (tp->measure_num > 0) {
			tp->measure_num--;
			tp->pt_in_measure = rat_rat_sum(measure_get_sym_duration(nth_measure_of_scorevoice(nth_scorevoice(x, tp->voice_num), tp->measure_num)), tp->pt_in_measure);
			return long2rat(0);
		} else {
			t_rational remainder = rat_opp(tp->pt_in_measure);
			tp->pt_in_measure = long2rat(0);
			return remainder;
		}
	}
	return long2rat(0);
}

void strip_final_ws(char *text)
{
	char *this_text;
	for (this_text = text + strlen(text) - 1; this_text >= text; this_text--) {
		if (isspace(*this_text))
			*this_text = 0;
		else
			break;
	}
}

char strip_cresc_decresc(char *text)
{
    long i, len = strlen(text);
    char res = 0;
    
    // we return crescendo (1) or diminuendo (-1) only if the last character is "<" or ">"
    // id est: we don't account for intermediate crescendi such as "f<ff>p<", I have no idea of how they might be properly handled in musicXML.
    // For instance: "f<ff>p" will return 0, "f<ff>p>" will return -1
    // In both cases, we'll trim the string TO THE FIRST found "<" or ">": both strings will be trimmed to "f".
    
    if (len > 0) {
        if (text[len - 1] == '<')
            res = -1;
        else if (text[len - 1] == '>')
            res = 1;
    }

    for (i = 0; i < len; i++) {
        if (text[i] == '<' || text[i] == '>') {
            text[i] = 0;
            break;
        }
    }
    return res;
}

void tolower_str(char *str) 
{
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}

long clef_number_to_lilypond_buf(t_notation_obj *r_ob, long clef, char **buf)
{
	if (!*buf)
		*buf = (char *)bach_newptr(100 * sizeof(char));
	
	t_symbol *clef_as_sym = clef_number_to_clef_symbol(r_ob, clef); 
	if (clef_as_sym == _llllobj_sym_Barytone) 
		clef_as_sym = gensym("varbarytone");
	else if (clef_as_sym == _llllobj_sym_F || clef_as_sym == _llllobj_sym_FF || clef_as_sym == _llllobj_sym_FFG)
		clef_as_sym = gensym("bass");
	else if (clef_as_sym == _llllobj_sym_G || clef_as_sym == _llllobj_sym_GG || clef_as_sym == _llllobj_sym_FGG || clef_as_sym == _llllobj_sym_FFGG)
		clef_as_sym = gensym("treble");
	else if (clef_as_sym == _llllobj_sym_G8)
		clef_as_sym = gensym("\"treble^8\"");
	else if (clef_as_sym == _llllobj_sym_G15)
		clef_as_sym = gensym("\"treble^15\"");
	else if (clef_as_sym == _llllobj_sym_F8)
		clef_as_sym = gensym("\"bass_8\"");
	else if (clef_as_sym == _llllobj_sym_F15)
		clef_as_sym = gensym("\"bass_15\"");
	
	char *clef_buf = strdup(clef_as_sym->s_name);
	tolower_str(clef_buf);
	long count = sprintf(*buf, "\t\t\t\\clef %s\r\n", clef_buf);
	free(clef_buf);
	return count;
}


char *note_and_acc_to_lilypond_buf(t_notation_obj *r_ob, t_note *note)
{
	char *buf = (char *)bach_newptr((4 + 4 * note->num_accidentals + 20) * sizeof(char));
	long cur = 0;
	long step = midicents2diatonicstep(note_get_screen_midicents(note));
	
	// note
	switch (step) {
		case 0:
			buf[cur++] = 'c';
			break;
		case 1:
			buf[cur++] = 'd';
			break;
		case 2:
			buf[cur++] = 'e';
			break;
		case 3:
			buf[cur++] = 'f';
			break;
		case 4:
			buf[cur++] = 'g';
			break;
		case 5:
			buf[cur++] = 'a';
			break;
		case 6:
			buf[cur++] = 'b';
			break;
		default:
			buf[cur++] = 'c';
			break;
	}
	
	// accidental
	long i;
    t_rational note_screen_accidental = note_get_screen_accidental(note);
	if (rat_rat_cmp(note_screen_accidental, genrat(0, 1)) == 0){
		// most common case, nothing to do
	} else if (rat_rat_cmp(note_screen_accidental, genrat(1, 4)) == 0){
		buf[cur++] = 'i';
		buf[cur++] = 'h';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(1, 2)) == 0){
		buf[cur++] = 'i';
		buf[cur++] = 's';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(3, 4)) == 0){
		buf[cur++] = 'i';
		buf[cur++] = 's';
		buf[cur++] = 'i';
		buf[cur++] = 'h';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(1, 1)) == 0){
		buf[cur++] = 'i';
		buf[cur++] = 's';
		buf[cur++] = 'i';
		buf[cur++] = 's';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 4)) == 0){
		buf[cur++] = 'e';
		buf[cur++] = 'h';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 2)) == 0){
		buf[cur++] = 'e';
		buf[cur++] = 's';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(-3, 4)) == 0){
		buf[cur++] = 'e';
		buf[cur++] = 's';
		buf[cur++] = 'e';
		buf[cur++] = 'h';
	} else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 1)) == 0){
		buf[cur++] = 'e';
		buf[cur++] = 's';
		buf[cur++] = 'e';
		buf[cur++] = 's';
	}
	
	// octaviation
	long temp = note_get_screen_midicents(note) / 1200 - 4;
	if (temp > 0) {
		for (i = 1; i <= temp; i++)
			buf[cur++] = '\'';
	} else if (temp < 0) {
		for (i = 1; i <= -temp; i++)
			buf[cur++] = ',';
	}
	
	buf[cur] = 0;
	return buf;
}

long articulation_to_lilypond_buf(t_notation_obj *r_ob, long articulation_ID, char **buf){
	if (!(*buf))
		*buf = (char *)bach_newptr(40 * sizeof(char));
	
	(*buf)[0] = 0;
	switch (articulation_ID) {
		case k_ARTICULATION_STACCATO: sprintf(*buf, "\\staccato"); break;
		case k_ARTICULATION_ACCENT: sprintf(*buf, "\\accent"); break;
		case k_ARTICULATION_PORTATO: sprintf(*buf, "\\tenuto"); break;
		case k_ARTICULATION_TRILL: sprintf(*buf, "\\trill"); break;
		case k_ARTICULATION_TRILL_NATURAL: sprintf(*buf, "\\trillNatural"); break;
		case k_ARTICULATION_TRILL_FLAT: sprintf(*buf, "\\trillFlat"); break;
		case k_ARTICULATION_TRILL_SHARP: sprintf(*buf, "\\trillSharp"); break;
		case k_ARTICULATION_FERMATA: sprintf(*buf, "\\fermata"); break;
		case k_ARTICULATION_ACCENT_STACCATO: sprintf(*buf, "\\staccato\\accent"); break;
		case k_ARTICULATION_ACCENT_PORTATO: sprintf(*buf, "\\tenuto\\accent"); break;
		case k_ARTICULATION_PORTATO_STACCATO: sprintf(*buf, "\\portato"); break;
		case k_ARTICULATION_STACCATISSIMO: sprintf(*buf, "\\staccatissimo"); break;
		case k_ARTICULATION_MARTELLATO: sprintf(*buf, "\\marcato"); break;
		case k_ARTICULATION_MARTELLATO_STACCATO: sprintf(*buf, "\\staccato\\marcato"); break;
		case k_ARTICULATION_MORDENT_UP: sprintf(*buf, "\\prall"); break;
		case k_ARTICULATION_MORDENT_DOWN: sprintf(*buf, "\\mordent"); break;
		case k_ARTICULATION_DOUBLE_MORDENT: sprintf(*buf, "\\prallprall"); break;
		case k_ARTICULATION_GRUPPETTO: sprintf(*buf, "\\turn"); break;
		case k_ARTICULATION_HARMONIC: sprintf(*buf, "\\flageolet"); break;
		case k_ARTICULATION_LEFT_HAND_PIZZICATO: sprintf(*buf, "\\stopped"); break;
		case k_ARTICULATION_BOWING_UP: sprintf(*buf, "\\upbow"); break;
		case k_ARTICULATION_BOWING_DOWN: sprintf(*buf, "\\downbow"); break;
		case k_ARTICULATION_TREMOLO3: sprintf(*buf, ":32"); break;
		case k_ARTICULATION_TREMOLO2: sprintf(*buf, ":16"); break;
		case k_ARTICULATION_TREMOLO1: sprintf(*buf, ":8"); break;	
	}
	
	return strlen(*buf);
}


long chord_to_lilypond_buf(t_notation_obj *r_ob, t_chord *ch, char **buf)
{
	long cur = 0, j;
	char is_all_chord_tie_to_next = chord_is_all_tied_to(r_ob, ch, false, NULL);
	
	// estimating (upper bound!) on length of the string
	long estimated_buffer_length = 0;
	t_note *note;
	
	estimated_buffer_length = 10; // say, initial security pad, or for rests
	estimated_buffer_length += (4 + 4 + 20) * ch->num_notes; // name and space and possible tie + accidentals + octaviation (secured) for each note 
	estimated_buffer_length += 2; // in case we have a chord
	estimated_buffer_length += 20; // chars needed to write the duration (uuuupper bound)
	estimated_buffer_length += ch->num_dots; // number of dots
	for (note = ch->firstnote; note; note = note->next) 
		estimated_buffer_length += 40 * note->num_articulations;
	estimated_buffer_length += 40 * ch->num_articulations;

	if (!*buf)
		*buf = (char *)bach_newptr(estimated_buffer_length * sizeof(char));
	
	(*buf)[cur++] = '\t';
	(*buf)[cur++] = '\t';
	(*buf)[cur++] = '\t';
	
	if (ch->num_notes == 0) 
		(*buf)[cur++] = 'r';
	else if (ch->num_notes > 1)
		(*buf)[cur++] = '<';
	
	for (note = ch->firstnote; note; note = note->next) {
		// adding note name
		char *note_buf = note_and_acc_to_lilypond_buf(r_ob, note);
		long len_note_buf = strlen(note_buf);
		strncpy((*buf) + cur, note_buf, len_note_buf);
		cur += len_note_buf;
		bach_freeptr(note_buf);
		
		// single tie for note
		if (!is_all_chord_tie_to_next && note->tie_to && note->tie_to != WHITENULL)
			(*buf)[cur++] = '~';
		
		if (ch->num_notes > 1) {
			for (j = 0; j < note->num_articulations; j++) {
				char *buf_articulation = NULL;
				long len_art = articulation_to_lilypond_buf(r_ob, note->articulation[j].articulation_ID, &buf_articulation);
				strncpy((*buf) + cur, note_buf, len_art);
				cur += len_art;
				bach_freeptr(buf_articulation);
			}
		}
				
		if (ch->num_notes > 1 && note->next)
			(*buf)[cur++] = ' ';
	}

	if (ch->num_notes > 1)
		(*buf)[cur++] = '>';

	// adding duration
	char dur_buf[20];
	if (rat_rat_cmp(ch->figure, genrat(2, 1)) == 0)
		snprintf_zero(dur_buf, 20, "\\breve");
	else
		snprintf_zero(dur_buf, 20, "%ld", ch->figure.r_den);
	long len_dur_buf = strlen(dur_buf);
	strncpy((*buf) + cur, dur_buf, len_dur_buf);
	cur += len_dur_buf;
	
	// adding dots
	long i; 
	for (i = 0; i < ch->num_dots; i++)
		(*buf)[cur++] = '.';

	// articulations
	if (ch->num_notes == 1) {
		for (j = 0; j < ch->firstnote->num_articulations; j++) {
			char *buf_articulation = NULL;
			long len_art = articulation_to_lilypond_buf(r_ob, ch->firstnote->articulation[j].articulation_ID, &buf_articulation);
			strncpy((*buf) + cur, buf_articulation, len_art);
			bach_freeptr(buf_articulation);
			cur += len_art;
		}
	}
	for (j = 0; j < ch->num_articulations; j++) {
		char *buf_articulation = NULL;
		long len_art = articulation_to_lilypond_buf(r_ob, ch->articulation[j].articulation_ID, &buf_articulation);
		strncpy((*buf) + cur, buf_articulation, len_art);
		bach_freeptr(buf_articulation);
		cur += len_art;
	}	
	
	// tie
	if (is_all_chord_tie_to_next)
		(*buf)[cur++] = '~';
	
	(*buf)[cur++] = '\r';
	(*buf)[cur++] = '\n';
	(*buf)[cur] = 0;
		
	return cur;
}



void key_to_note_name_lilypond_buf(t_notation_obj *r_ob, long key, char **buf)
{
	if (!*buf)
		*buf = (char *)bach_newptr(10 * sizeof(char));
	switch (key) {
		case 0: sprintf(*buf, "c"); break;
		case 1: sprintf(*buf, "g"); break;
		case 2: sprintf(*buf, "d"); break;
		case 3: sprintf(*buf, "a"); break;
		case 4: sprintf(*buf, "e"); break;
		case 5: sprintf(*buf, "b"); break;
		case 6: sprintf(*buf, "fis"); break;
		case 7: sprintf(*buf, "cis"); break;
		case 8: sprintf(*buf, "gis"); break;
		case 9: sprintf(*buf, "dis"); break;
		case 10: sprintf(*buf, "ais"); break;
		case 11: sprintf(*buf, "eis"); break;
		case 12: sprintf(*buf, "bis"); break;
		case -1: sprintf(*buf, "f"); break;
		case -2: sprintf(*buf, "bes"); break;
		case -3: sprintf(*buf, "ees"); break;
		case -4: sprintf(*buf, "aes"); break;
		case -5: sprintf(*buf, "des"); break;
		case -6: sprintf(*buf, "ges"); break;
		case -7: sprintf(*buf, "ces"); break;
		case -8: sprintf(*buf, "fes"); break;
		case -9: sprintf(*buf, "beses"); break;
		case -10: sprintf(*buf, "eeses"); break;
		case -11: sprintf(*buf, "aeses"); break;
		case -12: sprintf(*buf, "deses"); break;
		default: sprintf(*buf, "c"); break;
	}
}

long barline_to_lilypond_buf(t_notation_obj *r_ob, t_measure *measure, char **buf)
{
	if (!*buf)
		*buf = (char *)bach_newptr(30 * sizeof(char));

	char type = measure->end_barline->barline_type;
	if (type == k_BARLINE_AUTOMATIC || type == 0)
		type = measure->next ? k_BARLINE_NORMAL : k_BARLINE_FINAL;
	
	switch (type) {
		case k_BARLINE_NORMAL:
			return snprintf_zero(*buf, 30, "\t\t\t|\r\n");
			break;
		case k_BARLINE_SOLID:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \".\"\r\n");
			break;
		case k_BARLINE_DOUBLE:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \"||\"\r\n");
			break;
		case k_BARLINE_DASHED:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \"dashed\"\r\n");
			break;
		case k_BARLINE_FINAL:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \"|.\"\r\n");
			break;
		case k_BARLINE_HIDDEN:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \"\"\r\n");
			break;
		case k_BARLINE_POINTS:
			return snprintf_zero(*buf, 30, "\t\t\t\\bar \":\"\r\n");
			break;
		default:
			return snprintf_zero(*buf, 30, "\t\t\t|\r\n");
			break;
	}
}


long tempo_to_lilypond_buf(t_notation_obj *r_ob, t_tempo *tempo, char **buf, char *must_start_tempo_span, char *must_end_tempo_span)
{
	if (!*buf)
		*buf = (char *)bach_newptr(150 * sizeof(char));

	t_rational temp = rat_long_prod(tempo->figure_tempo_value, tempo->tempo_figure.r_num);
	
	*must_start_tempo_span = 0;
	if (*must_end_tempo_span == -1)
		*must_end_tempo_span = 1;
	
	if (tempo->interpolation_type) {
		t_tempo *next_tempo = tempo_get_next(tempo);
		long cmp = rat_rat_cmp(next_tempo->tempo_value, tempo->tempo_value);
		if (cmp > 0) {
			*must_start_tempo_span = 1;
			return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n\t\t\t\\override TextSpanner.bound-details.left.text = \"acc.\"\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
		} else if (cmp < 0) {
			*must_start_tempo_span = 1;
			return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n\t\t\t\\override TextSpanner.bound-details.left.text = \"rall.\"\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
		} else 
			return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
	} else 
		return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
}	


void write_tempo_interp_if_needed(t_notation_obj *r_ob, char *must_start_tempo_span, char *must_end_tempo_span, t_filestruct *f, t_ptr_size *count)
{
	char *buf = (char *)bach_newptr(150 * sizeof(char));

	if (*must_end_tempo_span == 1) {
		*must_end_tempo_span = 0;
		*count = snprintf_zero(buf, 150, "\t\t\t\\stopTextSpan\r\n");
		sysfile_write(f, count, buf);
	}

	if (*must_start_tempo_span == 1) {
		*must_start_tempo_span = 0;
		*must_end_tempo_span = -1;
		*count = snprintf_zero(buf, 150, "\t\t\t\\startTextSpan\r\n");
		sysfile_write(f, count, buf);
	} 
	
	bach_freeptr(buf);
}

t_max_err score_dowritelilypond_pdf(t_score *x, t_symbol *s, long ac, t_atom *av)
{
	char filename[MAX_FILENAME_CHARS];
	char fullname[MAX_PATH_CHARS];
	char fullname_conform[MAX_PATH_CHARS];
	short path = 0;
	t_atom new_av[4];
	atom_setobj(new_av, atom_getobj(av));
	atom_setobj(new_av+1, filename);
	atom_setobj(new_av+2, &path);
	atom_setlong(new_av+3, true);
	t_max_err err = score_dowritelilypond(x, s, 4, new_av);

	if (!err) {
		path_topathname(path, filename, fullname);
		long l = strlen(fullname);
#ifdef MAC_VERSION
		path_nameconform(fullname, fullname_conform, PATH_STYLE_MAX, PATH_TYPE_BOOT);
#else
		path_nameconform(fullname, fullname_conform, PATH_STYLE_MAX, PATH_TYPE_ABSOLUTE);
#endif
		if (l > 3 && !strncmp(fullname_conform + l - 3, ".ly", 3)) {
			fullname_conform[l - 3] = 0;
		}

#ifdef MAC_VERSION
		char buf1[MAX_PATH_CHARS * 4];
		char buf2[MAX_PATH_CHARS * 4];
		snprintf_zero(buf1, MAX_PATH_CHARS * 4, "/Applications/LilyPond.app/Contents/Resources/bin/lilypond -o \"%s\" \"%s\"", fullname_conform, fullname_conform);
		snprintf_zero(buf2, MAX_PATH_CHARS * 4, "open \"%s.pdf\"", fullname_conform);
		system(buf1);
		system(buf2);
#endif
#ifdef WIN_VERSION
		char lilypond_doc_path[MAX_PATH_CHARS * 4];
		char pdf_doc_path[MAX_PATH_CHARS * 4];
		char lilypond_app_path[MAX_PATH_CHARS * 4];
		char pdf_app_path[MAX_PATH_CHARS * 4];
		char lilypond_cmd[MAX_PATH_CHARS * 4];
		char pdf_cmd[MAX_PATH_CHARS * 4];
		HINSTANCE winapi_err;
		snprintf_zero(lilypond_doc_path, MAX_PATH_CHARS * 4, "%s.ly", fullname_conform);
		FindExecutable(lilypond_doc_path, NULL, lilypond_app_path);
		long lilypond_app_path_len;
		if ((lilypond_app_path_len = strlen(lilypond_app_path)) < 20) {
			object_error((t_object *) x, "Can't open %s", lilypond_doc_path);
			return MAX_ERR_GENERIC;
		}
		if (!strcmp(lilypond_app_path + lilypond_app_path_len - 20, "lilypond-windows.exe")) {
			strncpy_zero(lilypond_app_path + lilypond_app_path_len - 20, "lilypond.exe", MAX_PATH_CHARS * 4);
		} else if (!strcmp(lilypond_app_path + lilypond_app_path_len - 21, "lilypond-windows.exe\"")) { // one never knows...
			strncpy_zero(lilypond_app_path + lilypond_app_path_len - 21, "lilypond.exe\"", MAX_PATH_CHARS * 4);
		}
		long sys_err;
		//post("lilypond: %s", lilypond_app_path);
		snprintf_zero(lilypond_cmd, MAX_PATH_CHARS * 4, "\"\"%s\" -o \"%s\" \"%s\"\"", lilypond_app_path, fullname_conform, fullname_conform);
		//post("command: %s", lilypond_cmd);
		//sys_err = system("cmd"); 
		sys_err = system(lilypond_cmd);
		//post("sys_err = %ld", sys_err);

		snprintf_zero(pdf_doc_path, MAX_PATH_CHARS * 4, "\"%s.pdf\"", fullname_conform);
		FindExecutable(pdf_doc_path, NULL, pdf_app_path);
		//post("pdf_app_path: %s", pdf_app_path);
		//post("pdf_doc_path: %s", pdf_doc_path);
		if (*pdf_app_path == 0) {
			object_error((t_object *) x, "Can't open %s", pdf_doc_path);
			return MAX_ERR_GENERIC;		
		}
		//post("acrobat: %s", pdf_app_path);
		//snprintf_zero(pdf_cmd, MAX_PATH_CHARS * 4, "\"\"%s\" \"%s\"\"", pdf_app_path, pdf_doc_path);
		//post("command: %s", pdf_cmd);

		_spawnl(_P_NOWAIT, pdf_app_path, pdf_doc_path, pdf_doc_path, NULL);

		//system(pdf_cmd);
#endif
	}
	return err;
}


char are_trills_with_accidental_used(t_score *x)
{
	t_scorevoice *voice;
	t_measure *meas;
	t_chord *chord;
	t_note *note;
	long j;
	
	for (voice = (t_scorevoice *)x->r_ob.firstvoice; voice; voice = voice->next) {
		for (meas = voice->firstmeasure; meas; meas = meas->next) {
			for (chord = meas->firstchord; chord; chord = chord->next) {
				for (j = 0; j < chord->num_articulations; j++)
					if (chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_NATURAL ||
						chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_SHARP ||
						chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_FLAT)
						return true;
				
				for (note = chord->firstnote; note; note = note->next) {
					for (j = 0; j < note->num_articulations; j++)
						if (note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_NATURAL ||
							note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_SHARP ||
							note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_FLAT)
							return true;
				}
			}
		}
	}
	
	return false;
}


t_max_err score_dowritelilypond(t_score *x, t_symbol *s, long ac, t_atom *av)
{
	t_llll *voices_to_write = NULL;
	t_llll *arguments = (t_llll *) atom_getobj(av);
	char *filename = ac >= 2 ? (char *)atom_getobj(av+1) : NULL;
	short *path = ac >= 3 ? (short *)atom_getobj(av+2) : NULL;
	char direct_to_pdf = ac >= 4 ? atom_getlong(av+3) : false;
	t_symbol *filename_sym = NULL;
	t_llllelem *elem;
	t_fourcc outtype;
	t_filehandle f;
	t_fourcc filetype = 'TEXT';
	t_ptr_size count = 0;
	t_max_err err = MAX_ERR_NONE;
	char ok = true;
	
	llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "sl",
				   _sym_filename, &filename_sym,
				   _llllobj_sym_voices, &voices_to_write); 

    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_behead(arguments);
    }
    

    lock_general_mutex((t_notation_obj *)x);
	
	prepare_voices_to_write((t_notation_obj *) x, &voices_to_write);
	long num_voices = voices_to_write->l_size;
	bach_assert_objerror_goto(x, ok = (num_voices > 0), "No valid voices for export", score_dowritelilypond_error); // CANT SEEM TO MAKE THIS WORK

	
	if (direct_to_pdf) { // export directly to pdf, so user will input the pdf file name, we'll have to convert it into the .ly filename manually
		if (!filename_sym || filename_sym == gensym("")) {      // if no argument supplied, ask for file
			strncpy_zero(filename, "Untitled.pdf", MAX_PATH_CHARS);
			if (saveasdialog_extended(filename, path, &outtype, &filetype, 1)) {    // non-zero: user cancelled
				err = MAX_ERR_GENERIC;
			}
		} else {
			strncpy_zero(filename, filename_sym->s_name, MAX_PATH_CHARS);
			*path = path_getdefault();
		}
		
		if (!err) {
			char *ext = strchr(filename, '.');
			if (!ext) {
				strncat_zero(filename, ".ly", MAX_PATH_CHARS);
			} else {
				char *temp = ext;
				while (temp) {
					ext = temp;
					temp = strchr(temp + 1, '.');
				}
				if (ext && strcmp(ext, ".ly")) { // should be always true
					if (!strcmp(ext, ".pdf")) {
						ext[1] = 'l';
						ext[2] = 'y';
						ext[3] = 0;
					} else 
						strncat_zero(ext, ".ly", MAX_PATH_CHARS);
				}
			}
			
			err = path_createsysfile(filename, *path, 'TEXT', &f);
			sysfile_seteof(f, 0);
		}
	} else {
		err = bach_openfile_write(filename_sym, "Untitled.ly", &f, &filetype, 1, &outtype, filename, path);
	}
	
	if (err) {
		ok = 0;
		goto score_dowritelilypond_error;
	}


	count = 19;
	sysfile_write(f, &count, "\\version \"2.18.0\"\r\n");
	
	if (!are_all_measureinfo_synchronous(x)) { // if measureinfo is NOT the same for every voice
		char header_buf[1000];
		count = snprintf_zero(header_buf, 1000, "\\layout {\r\n\
			\\context {\r\n\
			\t\\Score\r\n\
			\t\\remove \"Timing_translator\"\r\n\
			\t\\remove \"Default_bar_line_engraver\"\r\n\
			\t\\remove \"Metronome_mark_engraver\"\r\n\
			}\r\n\
			\\context {\r\n\
			\t\\Staff\r\n\
			\t\\consists \"Timing_translator\"\r\n\
			\t\\consists \"Default_bar_line_engraver\"\r\n\
			\t\\consists \"Metronome_mark_engraver\"\r\n\
			}\r\n\
		}\r\n");
		sysfile_write(f, &count, header_buf);
	}
	
	if (are_trills_with_accidental_used(x)) { // we only put this if naturals/flat/sharps trills are used
		char header_buf[1000];
		count = snprintf_zero(header_buf, 1000, "\
		trillFlatMarkup = \\markup { \\vcenter { \\musicglyph #\"scripts.trill\"\
			\\smaller \\flat } } \
		trillFlat = \
#(let* ((music (make-articulation \"trill\"))\
        (trill-flat (lambda (grob)\
					 (grob-interpret-markup\
					  grob\
					  trillFlatMarkup))))\
		(ly:music-set-property! music 'tweaks\
		 (acons 'stencil trill-flat\
		 (ly:music-property music 'tweaks)))\
		  music)\
		  trillSharpMarkup = \\markup { \\vcenter { \\musicglyph #\"scripts.trill\"\
		  \\smaller \\sharp } }\
		  trillSharp =\
		  #(let* ((music (make-articulation \"trill\"))\
		  (trill-flat (lambda (grob)\
		  (grob-interpret-markup\
		  grob\
		  trillSharpMarkup))))\
\
		  (ly:music-set-property! music 'tweaks\
		  (acons 'stencil trill-sharp\
		   (ly:music-property music 'tweaks)))\
		music)\
		}");
	}
	
	count = 10;
	sysfile_write(f, &count, "\\score {\r\n");
	
	count = 5;
	sysfile_write(f, &count, "\t<<\r\n");

	for (elem = voices_to_write->l_head; elem; elem = elem->l_next) {
		t_scorevoice *voice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&elem->l_hatom));

		count = 16;
		sysfile_write(f, &count, "\t\t\\new Staff {\r\n");

		// clef
		char *clef_buf = NULL;
		count = clef_number_to_lilypond_buf((t_notation_obj *) x, voice->v_ob.clef, &clef_buf);
		sysfile_write(f, &count, clef_buf);
		bach_freeptr(clef_buf);
		
		// key
		char key_note_buf[30];
		char *key_note_name_buf = NULL;
		key_to_note_name_lilypond_buf((t_notation_obj *)x, voice->v_ob.mode == k_MODE_NONSTANDARD ? 0 : voice->v_ob.key, &key_note_name_buf);
		count = snprintf_zero(key_note_buf,  30, "\t\t\t\\key %s %s\r\n", key_note_name_buf, voice->v_ob.mode == k_MODE_MINOR ? "\\minor" : "\\major");
		sysfile_write(f, &count, key_note_buf);
		bach_freeptr(key_note_name_buf);
		
		// measures
		t_measure *measure;
		char must_start_tempo_span = 0, must_end_tempo_span = 0;
		for (measure = voice->firstmeasure; measure; measure = measure->next) {
			t_tempo *tempo = measure->firsttempo;

			count = 5;
			sysfile_write(f, &count, "\t\t\t\r\n");

			if (!measure->prev || !ts_are_equal(&measure->timesignature, &measure->prev->timesignature)) {
				// time signature
				char ts_buf[100];
				char ts_buf_num[100];
				ts_buf_num[0] = 0;
				if (measure->timesignature.num_numerator_elements > 1) {
					char *temp_ts_num = long_array_to_string(measure->timesignature.numerator_elements, measure->timesignature.num_numerator_elements, true);
					bach_freeptr(temp_ts_num);
					snprintf_zero(ts_buf_num, 100, "#'%s ", temp_ts_num);
				}
				count = snprintf_zero(ts_buf, 100, "\t\t\t\\time %s%ld/%ld\r\n", ts_buf_num, measure->timesignature.numerator, measure->timesignature.denominator);
				sysfile_write(f, &count, ts_buf);
			}

			if (is_measure_empty(measure)) {
				char empty_measure_buf[30];
				
				// writing tempi
				while (tempo) {
					char *tempo_buf = NULL;
					count = tempo_to_lilypond_buf((t_notation_obj *)x, tempo, &tempo_buf, &must_start_tempo_span, &must_end_tempo_span);
					sysfile_write(f, &count, tempo_buf);
					tempo = tempo->next;
					bach_freeptr(tempo_buf);
				}			

				count = snprintf_zero(empty_measure_buf, 30, "\t\t\tR1*%ld/%ld\r\n", measure->timesignature.numerator, measure->timesignature.denominator);
				write_tempo_interp_if_needed((t_notation_obj *)x, &must_start_tempo_span, &must_end_tempo_span, f, &count);
				sysfile_write(f, &count, empty_measure_buf);
			} else {
				
				// writing chords, one for each line
				t_chord *ch;
				char inside_grace_sequence = false;
				for (ch = measure->firstchord; ch; ch = ch->next) {
					
					// is there a tempo on the chord
					while (tempo && rat_rat_cmp(tempo->changepoint, ch->r_sym_onset) <= 0) {
						char *tempo_buf = NULL;
						count = tempo_to_lilypond_buf((t_notation_obj *)x, tempo, &tempo_buf, &must_start_tempo_span, &must_end_tempo_span);
						sysfile_write(f, &count, tempo_buf);
						bach_freeptr(tempo_buf);
						tempo = tempo->next;
					}
					
					// does the chord open one or more tuplet levels?
					t_llll *level = ch->rhythmic_tree_elem->l_parent;
					while (level) {
						if (is_level_tuplet(level) && get_level_start_chord(level, true) == ch) {
							char tuplet_buf[40];
							t_rhythm_level_properties *prop = (t_rhythm_level_properties *)level->l_thing.w_obj;
							count = snprintf_zero(tuplet_buf, 40, "\t\t\t\\times %ld/%ld {\r\n", prop->tupletinfo.tuplet_local_ratio.r_num, prop->tupletinfo.tuplet_local_ratio.r_den);
							sysfile_write(f, &count, tuplet_buf);
						}
						level = level->l_owner ? level->l_owner->l_parent : NULL;
					}
					
					if (ch->is_grace_chord && !inside_grace_sequence) {
						char grace_buf[20];
						count = snprintf_zero(grace_buf, 20, "\t\t\t\\grace {\r\n");
						inside_grace_sequence = true;
						sysfile_write(f, &count, grace_buf);
					} else if (!ch->is_grace_chord && inside_grace_sequence) {
						char grace_end_buf[20];
						count = snprintf_zero(grace_end_buf, 20, "\t\t\t}\r\n");
						inside_grace_sequence = false;
						sysfile_write(f, &count, grace_end_buf);
					}
					
					char *ch_buf = NULL;
					count = chord_to_lilypond_buf((t_notation_obj *)x, ch, &ch_buf);
					sysfile_write(f, &count, ch_buf);
					bach_freeptr(ch_buf);

					write_tempo_interp_if_needed((t_notation_obj *)x, &must_start_tempo_span, &must_end_tempo_span, f, &count);

					// does the chord end one or more tuplet levels?
					level = ch->rhythmic_tree_elem->l_parent;
					while (level) {
						if (is_level_tuplet(level) && get_level_end_chord(level, true) == ch) {
							char tuplet_buf[20];
							count = snprintf_zero(tuplet_buf, 20, "\t\t\t}\r\n");
							sysfile_write(f, &count, tuplet_buf);
						}
						level = level->l_owner ? level->l_owner->l_parent : NULL;
					}				
				}
				
				// possibly closing a grace chord sequence
				if (inside_grace_sequence) {
					char grace_end_buf[20];
					count = snprintf_zero(grace_end_buf, 20, "\t\t\t}\r\n");
					sysfile_write(f, &count, grace_end_buf);
				}
			}
			
			// barline
			char *barline_buf = NULL;
			count = barline_to_lilypond_buf((t_notation_obj *)x, measure, &barline_buf);
			sysfile_write(f, &count, barline_buf);
			bach_freeptr(barline_buf);
		} 
	
		count = 5;
		sysfile_write(f, &count, "\t\t}\r\n");
	}

	count = 5;
	sysfile_write(f, &count, "\t>>\r\n");

	count = 3;
	sysfile_write(f, &count, "}\r\n");

	sysfile_close(f);
	
score_dowritelilypond_error:
    unlock_general_mutex((t_notation_obj *)x);
	if (arguments)
		llll_free(arguments);
	return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}




void score_exportimage(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method)notationobj_dowriteimage, s, 1, &av);
}

