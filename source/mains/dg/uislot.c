/**
    @file
    uislot.c
    
    @name 
    bach.slot
    
    @realname 
    bach.slot

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest 
    Display and edit a single slot window
    
    @description
    Provides the display and interface for the content of a slot window. 
    You can perfectly imagine its content as the whole slot content of an hidden dummy note.
    
    @discussion
    bach.slot represents essentially an always-open slot window associated to an imaginary note. 
    
    @category
    bach, bach objects, bach notation, bach interface, U/I
    
    @keywords
    slot, display, edit, breakpoint function, filter, spat, number, list, matrix,
    color, select
    
    @palette
    YES
    
    @palette category
    bach, bach objects, bach notation, bach interface

    @seealso
    bach.roll, bach.score, bach.slot2line, bach.slot2curve, bach.slot2filtercoeff, Slot Machines
    
    @owner
    Daniele Ghisi
*/

#include "notation.h" // header with all the structures for the notation objects
#include "llll_modifiers.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

#include "bach_jit.h"


typedef struct _uislot 
{
    t_notation_obj    r_ob;            ///< The common notation object structure 
    
    double            zoom;            ///< Zoom handling text fonts and dimensions
    
    char            notify_when_open_slot_changes;    ///< Send a notification when the slot changes
} t_uislot;


// global class pointer variable
t_class    *s_uislot_class = 0;

// functions
void uislot_inletinfo(t_uislot *x, void *b, long a, char *t);
void uislot_assist(t_uislot *x, void *b, long m, long a, char *s);
void uislot_free(t_uislot *x);
t_uislot* uislot_new(t_symbol *s, long argc, t_atom *argv);
void uislot_paint(t_uislot *x, t_object *view);
void uislot_paint_ext(t_uislot *x, t_object *view, t_jgraphics *g, t_rect rect);
void uislot_paint_to_jitter_matrix(t_uislot *x, t_symbol *matrix_name);

void uislot_anything(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_int(t_uislot *x, t_atom_long num);
void uislot_float(t_uislot *x, double num);
void uislot_bang(t_uislot *x);

// interface functions
void uislot_dump(t_uislot *x, t_symbol *s, long argc, t_atom *argv);

// mouse functions
void uislot_mouseenter(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mouseleave(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mousemove(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mousedrag(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mousedown(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mouseup(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_mousewheel(t_uislot *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc);
long uislot_oksize(t_uislot *x, t_rect *newrect);
long uislot_key(t_uislot *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
long uislot_keyfilter(t_uislot *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter);
void uislot_mousedoubleclick(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers);
void uislot_focusgained(t_uislot *x, t_object *patcherview);
void uislot_focuslost(t_uislot *x, t_object *patcherview);
void uislot_enter(t_uislot *x);
void uislot_edclose(t_uislot *x, char **ht, long size);
void uislot_okclose(t_uislot *x, char *s, short *result);
t_atom_long uislot_acceptsdrag(t_uislot *x, t_object *drag, t_object *view);
void uislot_jsave(t_uislot *x, t_dictionary *d);
void uislot_preset(t_uislot *x);
void uislot_begin_preset(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_restore_preset(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_end_preset(t_uislot *x);

void set_uislot_from_llll(t_uislot *x, t_llll* inputlist, char also_lock_general_mutex);
t_llll* get_uislot_values_as_llll(t_uislot *x, e_data_considering_types for_what, long dump_what, t_llll *slot_indices, char also_lock_general_mutex, char explicitly_get_also_default_stuff);
void send_uislot_values_as_llll(t_uislot *x, long send_what, t_llll *slot_indices);

void set_uislot_from_llll_from_read(t_uislot *x, t_llll* inputlist);

void uislot_old_undo(t_uislot *x);
void uislot_old_redo(t_uislot *x);
void uislot_new_undo_redo(t_uislot *x, char what);
void uislot_undo(t_uislot *x);
void uislot_redo(t_uislot *x);
void uislot_inhibit_undo(t_uislot *x, long val);
void uislot_prune_last_undo_step(t_uislot *x);

void uislot_change_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_append_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_prepend_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_insert_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_delete_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_erase_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_move_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_copy_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_add_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_resetslotinfo(t_uislot *x);

void uislot_getdomain(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_getdomainpixels(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_domain(t_uislot *x, t_symbol *s, long argc, t_atom *argv);

void changed_bang(t_uislot *x, int change_type);

t_max_err uislot_setattr_activeslot(t_uislot *x, t_object *attr, long ac, t_atom *av);

void create_whole_uislot_undo_tick(t_uislot *x);

void uislot_copy(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_paste(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
void uislot_cut(t_uislot *x, t_symbol *s, long argc, t_atom *argv);
            


// clipboard
t_clipboard clipboard = {k_NONE, k_NOTATION_OBJECT_SLOT, NULL, NULL, 0.};

// import-export
void uislot_read(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_symbol *filename = NULL;
    if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
        filename = atom_getsym(argv);
    llll_read((t_object *) x, filename, (read_fn)set_uislot_from_llll_from_read);
}

void uislot_read_singlesymbol(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom a;
    char *text = NULL;
    long size;
    atom_gettext_debug(argc, argv, &size, &text, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
    if (size > 0) {
        t_symbol *s = gensym(text);
        atom_setsym(&a, s);
        bach_freeptr(text);
        uislot_read(x, NULL, 1, &a);
    }
}

void uislot_write(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *uislot_as_llll;
    t_symbol *filename = NULL;
    if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
        filename = atom_getsym(argv);
    uislot_as_llll = get_uislot_values_as_llll(x, k_CONSIDER_FOR_SAVING, -1, NULL, true, false); // we save everything
    llll_writenative((t_object *) x, filename, uislot_as_llll);
}

void uislot_writetxt(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
    t_llll *uislot_as_llll = get_uislot_values_as_llll(x, k_CONSIDER_FOR_SAVING, -1, NULL, true, false); // we save everything
    llll_writetxt((t_object *) x, uislot_as_llll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART);
}

void uislot_bang(t_uislot *x)
{
    // nothing for now, just redraw
    jbox_redraw((t_jbox *) x);
}


// OBSOLETE FUNCTION!!!! NOW IT IS NEVER CALLED!!!!
// change_type: 0 = calculateUNDOSTEP; 1 = BANG+calculateUNDOSTEPonly; 2 = BANGonly
void changed_bang(t_uislot *x, int change_type){
    if (!x->r_ob.j_isdragging && (change_type & k_CHANGED_CREATE_UNDO_STEP)) {
        
        if (x->r_ob.save_data_with_patcher && !x->r_ob.j_box.l_dictll) // set dirty flag
            object_attr_setchar(x->r_ob.patcher_parent, gensym("dirty"), 1);
        
//        double this_time = systime_ms();
            
        if (x->r_ob.allow_undo){
            // update undo and redo lists

            t_llll *kill_me_redo[CONST_MAX_UNDO_STEPS];
            t_llll *kill_me_undo; 
            int i;
                
            lock_general_mutex((t_notation_obj *)x);    
            for (i = 0; i< CONST_MAX_UNDO_STEPS; i++) { // deleting redolist
                kill_me_redo[i] = x->r_ob.old_redo_llll[i];
                x->r_ob.old_redo_llll[i] = NULL;
            }
            
            // deleting last element of the undo list
            kill_me_undo = x->r_ob.old_undo_llll[CONST_MAX_UNDO_STEPS - 1];
            
            for (i = CONST_MAX_UNDO_STEPS - 1; i > 0; i--) // reassign undo steps
                x->r_ob.old_undo_llll[i] = x->r_ob.old_undo_llll[i-1];
            unlock_general_mutex((t_notation_obj *)x);    
            
            // killing elements
            for (i = 0; i < CONST_MAX_UNDO_STEPS; i++) {
                if (kill_me_redo[i])
                    llll_free(kill_me_redo[i]);
            }
            if (kill_me_undo) 
            llll_free(kill_me_undo);
            
            
            // setting first element of the list
            x->r_ob.old_undo_llll[0] = get_uislot_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_BODY + k_HEADER_SLOTINFO, NULL, true, true); // we don't undo clefs, key, midichannels and commands changes

            // setting new undo time
            x->r_ob.last_undo_time = systime_ms();
        }
    }

    // in any case:
    jbox_redraw((t_jbox *)x);    
    
    if (change_type & k_CHANGED_SEND_BANG)
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 2);
}


void uislot_begin_preset(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    x->r_ob.preset_ac = atom_getlong(argv) ;
    x->r_ob.preset_av = (t_atom *)bach_newptr(x->r_ob.preset_ac * sizeof(t_atom));
    
    // could allocate memory here etc.
//    post("begin_preset %ld values will be arriving",x->r_ob.preset_ac);
}

void uislot_restore_preset(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    long start, size;
    
    start = atom_getlong(argv);
    size = atom_getlong(argv + 1);
//    post("restore_preset start %ld size %ld", start,size);
    
    sysmem_copyptr(argv+2, x->r_ob.preset_av+start, size*sizeof(t_atom));
}

void uislot_end_preset(t_uislot *x)
{
//    post("end_preset received");
    uislot_anything(x, NULL, x->r_ob.preset_ac,x->r_ob.preset_av);
    bach_freeptr(x->r_ob.preset_av);
}

void uislot_preset(t_uislot *x){
    t_atom temp[256];
    void *buf;
    long i, index, size;
    char wrote = false, begin = true, done = false;
    t_llll *whole_info = get_uislot_values_as_llll(x, k_CONSIDER_FOR_SAVING, -1, NULL, true, false); // we save all

    // 1. we deparse the list
    t_atom *av = NULL, *this_av = NULL;
    long ac = llll_deparse(whole_info, &av, 0, /* LLLL_D_FLOAT64 | */  LLLL_D_QUOTE); //offset 0
    this_av = av;
    
    // 2. We fill the binbuf
    buf = gensym("_preset")->s_thing; 
    if (!buf)    // no preset object
        return;
        
    index = 0;
    while (!done) {
        i = index;
        size = ac - index;
        if (size > 250)
            size = 250;
        else    // you are at the end
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
        
    if (av) 
        bach_freeptr(av);
}

/* preset: Zicarelli


    t_atom temp[256];
    // imagine that we have
    reallylongdata
    
    long i, j, index;
    char wrote = false, begin = true;
    index = 0;
    for (; ; ) {
        i = index;
        size = x->s_length - index;
        if (size > 250)
            size = 250;
    }
    
    ...
    
myobject_begin_preset allocates a size (how much data?)
myobject_recall_preset contains the data 
myobject_end_preset 

*/

int T_EXPORT main(void){
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();

    bach_inspector_ui_classinit();

    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.slot", 
                            (method)uislot_new,
                            (method)uislot_free,
                            sizeof(t_uislot),
                            (method)NULL,
                            A_GIMME,
                            0L);
    
    c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//    jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
    jbox_initclass(c, JBOX_TEXTFIELD);
    
    class_addmethod(c, (method) uislot_paint, "paint", A_CANT, 0);

    // interface functions: act on selection

    class_addmethod(c, (method) uislot_preset, "preset", 0);
    class_addmethod(c, (method) uislot_begin_preset, "begin_preset", A_GIMME, 0);
    class_addmethod(c, (method) uislot_restore_preset, "restore_preset", A_GIMME, 0);
    class_addmethod(c, (method) uislot_end_preset, "end_preset", 0);
    CLASS_METHOD_ATTR_PARSE(c, "begin_preset", "undocumented", gensym("long"), 0L, "1");
    CLASS_METHOD_ATTR_PARSE(c, "restore_preset", "undocumented", gensym("long"), 0L, "1");
    CLASS_METHOD_ATTR_PARSE(c, "end_preset", "undocumented", gensym("long"), 0L, "1");


    // @method paintjit @digest Draw the slot onto a jitter matrix
    // @description @copy BACH_DOC_PAINTJIT
    class_addmethod(c, (method) uislot_paint_to_jitter_matrix, "paintjit", A_SYM, 0);

    
    // @method llll @digest Set slot content and/or slotinfo
    // @description An incoming llll sets the content of the slots.
    // The expected syntax is: <b>slot <m>SLOTINFO</m> <m>SLOTS_CONTENT</m></b>
    // where both <m>SLOTINFO</m> and <m>SLOTS_CONTENT</m> are optional. <br />
    // The <m>SLOTINFO</m> is the only part of header which <o>bach.slot</o> can have.
    // The <m>SLOTS_CONTENT</m> is the body of the object, with all the content
    // of all the slots. <br /> <br />
    // @copy BACH_DOC_SLOTINFO_SYNTAX <br /> <br />
    // @copy BACH_DOC_NOTE_SLOTS_SYNTAX <br /> <br />
    // @seealso dump
    class_addmethod(c, (method) uislot_anything, "anything", A_GIMME, 0);

    
    // @method int @digest Display slot window
    // @description An <m>int</m> <m>N</m> has <o>bach.slot</o> display the <m>N</m>-th slot window.
    class_addmethod(c, (method) uislot_int, "int", A_LONG, 0);
    class_addmethod(c, (method) uislot_float, "float", A_FLOAT, 0);
    class_addmethod(c, (method) uislot_bang, "bang", 0);

    
    // @method refresh @digest Force recomputation and redraw
    // @description The <m>refresh</m> message forces the recomputation of all the features and forces the object box to be redrawn.
    class_addmethod(c, (method) uislot_anything, "refresh", A_GIMME, 0);

    
    
    // @method dump @digest Dump information
    // @description A <m>dump</m> message will simply output the content of <o>bach.slot</o> in gathered syntax from the first outlet. <br />
    // The output syntax is: <b>slot <m>SLOTINFO</m> <m>SLOTS_CONTENT</m></b>.
    // The <m>SLOTINFO</m> is the only part of header which <o>bach.slot</o> can have.
    // The <m>SLOTS_CONTENT</m> is the body of the object, with all the content
    // of all the slots. <br /> 
    // If the symbol "body" is given as argument, the <m>SLOTINFO</m> will not be dumped. 
    // If the symbol "header" or "slotinfo" is given as argument, the <m>SLOTS_CONTENT</m> will not be dumped. 
    // If a list of integers is given as output, they are considered slot indices, and only the content of the related slots will be dumped. 
    // <br /> <br />
    // @copy BACH_DOC_SLOTINFO_SYNTAX <br /> <br />
    // @copy BACH_DOC_NOTE_SLOTS_SYNTAX <br /> <br />
    // @marg 0 @name selective_dump_option @optional 1 @type symbol
    // @example dump @caption dump whole information
    // @example dump 2 @caption dump only information about 2nd slot
    // @example dump 1 2 4 @caption dump 1st, 2nd and 4th slot
    // @example dump body @caption dump all slots, no slotinfo
    // @example dump header @caption dump slotinfo only
    // @seealso llll
    class_addmethod(c, (method) uislot_anything, "dump", A_GIMME, 0);


    // @method clear @digest Clear the content
    // @description A <m>clear</m> message deletes all the content in all the slots.
    // A clear followed by a number clears the content of the given slot.
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @example clear @caption clear all
    // @example clear 3 @caption clear slot 3
    // @example clear active @caption clear active slot
    // @example clear lyrics @caption clear slot named "lyrics"
    // @seealso resetslotinfo, eraseslot
    class_addmethod(c, (method) uislot_anything, "clear", A_GIMME, 0);

    // @method next @digest Switch to next slot window
    // @description A <m>next</m> message opens the next slot's window.
    // If last slot is reached, the first slot window will be opened.
    class_addmethod(c, (method) uislot_anything, "next", A_GIMME, 0);

    // @method prev @digest Switch to previous slot window
    // @description A <m>prev</m> message opens the previous slot window.
    // If first slot is reached, the last slot window will be opened.
    class_addmethod(c, (method) uislot_anything, "prev", A_GIMME, 0);


    
    // @method copy @digest Copy
    // @description Copies into the global clipboard slot data.
    // A "slot" or "slotinfo" symbol is always expected as argument. In the first case, slot data is copied, in the second case,
    // the structure of the slot (slotinfo) is copied. <br />
    // With no further arguments, the content of the open slot window is copied; if in addition to the "slot" symbol an integer
    // is given, such integer is the number of the slot whose content is copied; finally, this integer can 
    // be substituted by the "all" symbol to copy the content of all slots.
    // @marg 0 @name slot @optional 0 @type symbol
    // @marg 1 @name slot_number @optional 1 @type int/symbol
    // @example copy slot 1 @caption copy first slot
    // @example copy slot active @caption copy currently open slot
    // @example copy slot all @caption copy all slot
    // @example copy slotinfo 3 @caption copy structure of slot 3
    // @seealso cut, paste
    class_addmethod(c, (method) uislot_copy, "copy", A_GIMME, 0);
    
    
    // @method cut @digest Cut
    // @description Cuts, and puts global roll clipboard, slot data.
    // The behavior and arguments of <m>cut</m> are exaclty as <m>copy</m>, with the addition that the copied 
    // content is subsequently deleted (see <m>copy</m> to know more).
    // @marg 0 @name slot @optional 0 @type symbol
    // @marg 1 @name slot_number @optional 1 @type int/symbol
    // @example cut slot 1 @caption cut first slot
    // @example cut slot active @caption cut currently open slot
    // @example cut slot all @caption cut all slots
    // @seealso copy, paste
    class_addmethod(c, (method) uislot_cut, "cut", A_GIMME, 0);
    
    
    // @method paste @digest Paste
    // @description Pastes the content contained in the global clipboard, if the clipboard contains slot content. <br />
    // A "slot" of "slotinfo" symbol is always expected as argument. In the first case, the content of a slot is pasted,
    // in the second case, the information about the structure of the slot is pasted.
    // The second integer argument sets the slot into which content has to be pasted.
    // This number can be replaced with the "active" symbol, and the 
    // slot content will be applied to the open slot window.
    // @marg 0 @name slot @optional 0 @type symbol
    // @marg 1 @name slot_number @optional 1 @type int/symbol
    // @example paste slot @caption paste copied slot(s) to selection
    // @example paste slot all @caption the same
    // @example paste slot 3 @caption paste copied slot to slot 3
    // @example paste slot ampenv @caption paste copied slot to "ampenv" slot
    // @example paste slot active @caption paste copied slot to currently open slot
    // @example paste slotinfo 4 @caption paste slotinfo onto slot 4
    // @seealso cut, copy
    //    class_addmethod(c, (method) uislot_paste, "paste", A_GIMME, 0); // THIS MUST BE COMMENTED!!!!!
                                                                        // Paste must be indeed handled inside the anything method,
                                                                        // otherwise it treads over the external editor paste method
    
    
    // @method sample @digest Sample a function slot
    // @description A <m>sample</m> message will sample a given function slot in a certain number of points.
    // Two arguments are expected: the slot number and the number of sampling points.
    // The sampling is regular: sampling points are equally spaced.
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. <br />
    // If the <b>delta</b> symbol is given as third argument, the first numeric argument (which can also be non-integer, in
    // this case) is considered to be the distance between samples (in the slot's domain function unit), and not the number of samples.
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name number_of_points @optional 0 @type int
    // @marg 2 @name delta @optional 1 @type symbol
    // @example sample 2 10 @caption sample slot 2 in 10 equally spaced points
    // @example sample ampenv 10 @caption the same, for slot named "ampenv"
    // @example sample active 10 @caption the same, for currently open slot
    // @example sample 2 1000 ms @caption sample score each second
    // @example sample 1 0.05 delta @caption sample slot 1 in points spaced by 0.05
    // @example sample active 0.05 delta @caption the same, for currently open slot
    // @seealso interp
    class_addmethod(c, (method) uislot_anything, "sample", A_GIMME, 0);
    
    
    // @method interp @digest Return interpolated value of a function slot
    // @description An <m>interp</m> message will return the interpolated value in the range of a function slot,
    // corresponding to the input domain value.
    // Two arguments are expected: the slot number and the input domain value.
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot.
    // Each of the two arguments can be an llll containing respectively more than one slot, or more than one domain value,
    // in which case multiple interpolation values are given at output. The interpolation value are wrapped in a level of
    // parenthesis if more than one domain value per slot is requested.
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol/llll
    // @marg 1 @name interpolation_x @optional 0 @type float/llll
    // @example interp 2 0.4 @caption get y value of slot 2 at x = 0.4
    // @example interp ampenv 0.4 @caption the same for slot named "ampenv"
    // @example interp active 0.4 @caption the same for currently open slot
    // @example interp [1 2 3] 0.4 @caption interpolate slots 1, 2, 3 at once
    // @example interp active [0.2 0.4 0.9] @caption interpolate active slot on multiple values
    // @example interp [1 2 3] [0.2 0.4 0.9] @caption interpolate slots 1, 2, 3 on multiple values
    // @seealso sample
    class_addmethod(c, (method) uislot_anything, "interp", A_GIMME, 0);


    // @method read @digest Open file
    // @description A <m>read</m> message will load the content of <o>bach.slot</o> starting from the information saved in a file. 
    // If an argument is given, this is the filename (if the file is in the search path 
    // or in the same folder) or the full file path. If no argument is given, a dialog window pops up.
    // @marg 0 @name file @optional 1 @type symbol
    // @example read @caption open file via dialog box
    // @example read slotexample.txt @caption open bach text file
    // @seealso write, writetxt
    class_addmethod(c, (method) uislot_read, "read", A_GIMME, 0);
    class_addmethod(c, (method) uislot_read_singlesymbol, "readsinglesymbol", A_GIMME, 0); // only for drag'n'drop purposes


    // @method write @digest Save file in native format
    // @description A <m>write</m> message will save the content of <o>bach.slot</o> in a file, in native format. 
    // If an argument is given, this is the filename (if the file is in the search path 
    // or in the same folder) or the full file path. If no argument is given, a dialog window pops up.
    // @marg 0 @name file @optional 1 @type symbol
    // @example write @caption save file via dialog box
    // @example write myfile.llll @caption save bach file in native format
    // @seealso writetxt, read
    class_addmethod(c, (method) uislot_write, "write", A_GIMME, 0);


    // @method writetxt @digest Save file in text format
    // @description A <m>writetxt</m> message will save the content of <o>bach.slot</o>, as llll, in a file, in readable text format.
    // @copy BACH_DOC_WRITETXT_TEXT_FORMAT_AND_ARGUMENTS
    // @example writetxt @caption export as a text file, opening a dialog box for the file name
    // @example writetxt myfile.txt @caption export as a text file with the provided file name
    // @example writetxt myfile.txt @maxdecimals 3 @caption export with a floating-point precision of 3 decimal digits
    // @example writetxt myfile.txt @maxdecimals 3 @wrap 40 @caption as the above, limiting the length of each line to 40 characters
    // @example writetxt myfile.txt @indent 1 @caption export indenting each sublist by one space per depth level
    // @example writetxt myfile.txt @indent 1 @maxdepth 2 @caption as the above, but only first-level sublists are placed on new lines
    // @example writetxt myfile.txt @maxdepth 1 @caption no indentation is performed
    // @marg 0 @name filename @optional 1 @type symbol
    // @mattr indent @type atom @default tab @digest Number of spaces for indentation or "tab" symbol
    // @mattr maxdepth @type int @default -1 @digest Maximum depth for new lines
    // @mattr wrap @type int @default 0 @digest Maximum number of characters per line (0 means: no wrapping)
    // @seealso write, exportmidi, read
    class_addmethod(c, (method) uislot_writetxt, "writetxt", A_GIMME, 0);


    // @method addslot @digest Set the conent of one or more slots
    // @description An <m>addslot</m> message will modify all the content of one or more slots.
    // The syntax is <b>addslot [<m>slot_number</m> <m>SLOT_CONTENT</m>] [<m>slot_number</m> <m>SLOT_CONTENT</m>]...</b>. <br />
    // @copy BACH_DOC_NOTE_SLOT_CONTENT
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @example addslot [6 0.512] @caption fill (float) slot 6 with number 0.512
    // @example addslot [5 42] @caption fill (int) slot 5 with number 42
    // @example addslot [7 "Lorem Ipsum" ] @caption fill (text) slot 7 with some text
    // @example addslot [10 [John George [Ringo] [Brian]] ] @caption fill (llll) slot 10 with an llll
    // @example addslot [3 10 20 30] @caption fill (intlist) slot 3 of selected notes with list of values 10, 20, 30
    // @example addslot [2 [0 0 0] [0.5 0 1] [1 1 0.2] @caption fill (function) slot 2 with a breakpoint function in (x y slope) form
    // @example addslot [amplienv [0 0 0] [0.5 0 1] [1 1 0.2]] @caption the same for slot named 'amplienv'
    // @example addslot [active [0 0 0] [0.5 0 1] [1 1 0.2]] @caption the same for currently open slot
    // @example addslot [3 10 20 30] [2 [0 0 0] [0.5 0 1] [1 1 0.2]] @caption set more slots at once
    // @seealso changeslotitem, eraseslot
    class_addmethod(c, (method) uislot_add_slot, "addslot", A_GIMME, 0);


    // @method eraseslot @digest Clear a specific slot
    // @description An <m>eraseslot</m> message will clear the content of a specific slot. The slot number of the slot to clear is given as argument.
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @example eraseslot active @caption clear currently open slot
    // @example eraseslot 4 @caption clear 4th slot
    // @example eraseslot amplienv @caption clear slot named amplienv
    // @seealso addslot, changeslotitem, resetslotinfo
    class_addmethod(c, (method) uislot_erase_slot, "eraseslot", A_GIMME, 0);

    
    // @method moveslot @digest Move a slot to another one for selected items
    // @description @copy BACH_DOC_MESSAGE_MOVESLOT
    // @marg 0 @name slot_from @optional 0 @type int/symbol
    // @marg 1 @name slot_to @optional 0 @type int/symbol
    // @example moveslot 2 7 @caption move the content of slot 2 to slot 7 for selected items
    // @example moveslot 2 active @caption destination slot is the active slot
    // @example moveslot amplienv myfunction @caption move the 'amplienv' slot to the 'myfunction' slot
    // @seealso copyslot, eraseslot, addslot, changeslotitem, resetslotinfo
    class_addmethod(c, (method) uislot_move_slot, "moveslot", A_GIMME, 0);
    
    
    // @method copyslot @digest Copy a slot to another one for selected items
    // @description @copy BACH_DOC_MESSAGE_COPYSLOT
    // @marg 0 @name slot_from @optional 0 @type int/symbol
    // @marg 1 @name slot_to @optional 0 @type int/symbol
    // @example copyslot 2 7 @caption copy the content of slot 2 to slot 7 for selected items
    // @example copyslot 2 active @caption destination slot is the active slot
    // @example copyslot amplienv myfunction @caption copy the slot named amplienv to the slot named myfunction
    // @seealso moveslot, eraseslot, addslot, changeslotitem, resetslotinfo
    class_addmethod(c, (method) uislot_copy_slot, "copyslot", A_GIMME, 0);
    

    
    // @method changeslotitem @digest Change a specific element inside a slot
    // @description A <m>changeslotitem</m> message will change a specific element inside a slot (possibly containing more than one element, such as
    // a <m>function</m> slot, or an <m>intlist</m> slot...). 
    // The syntax is <b>changeslotvalue <m>slot_number</m> <m>element_index</m> <m>SLOT_ELEMENT_CONTENT</m></b>. <br />
    // Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 
    // The <m>element_index</m> is the number identifying the position of the element to be changed (e.g., for a <m>function</m> slot: 1 for the first point, 2 for the second, and so on).
    // The element content is a single element in the lists of the slot content syntax: a single point for a slot <m>function</m>, a single number for an <m>intlist</m> or <m>floatlist</m> slot,
    // and so on. Such element must be unwrapped from its outer level of parentheses (if any). For instance, for a function,
    // a good syntax is <b>changeslotvalue 2 3 0.5 20 0</b> which will change the 3rd point of the function contained in the second slot
    // to the point <b>[0.5 20 0]</b>. <br />
    // @copy BACH_DOC_NOTE_SLOT_CONTENT
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name element_index @optional 0 @type int
    // @marg 2 @name slot_element @optional 0 @type llll
    // @example changeslotitem 3 2 13 @caption set the 2nd element of 3nd (int or float) slot to 13
    // @example changeslotitem 3 0 13 @caption append 13 at the end of slot 3
    // @example changeslotitem 1 2 0.5 10 0 @caption change the 2nd point of the 1st (function) slot to (0.5 10 0) in (x y slope) form
    // @example changeslotitem active 2 0.5 10 0 @caption the same, for the currently open slot
    // @example changeslotitem spectrenv 2 0.5 10 0 @caption the same, for the a slot named 'spectrenv'
    // @example changeslotitem 9 1 highpass 400 0 2 @caption set the 1st element of 9nd (dynfilter) slot to "highpass 400 0 2"
    // @example changeslotitem 8 0 Max.app 0 @caption append the Max.app file in the 8th (filelist) slot, and make it active
    // @example changeslotitem 8 0 0 2 @caption Make 2nd file active in 8th (filelist) slot
    // @seealso addslot, eraseslot
    class_addmethod(c, (method) uislot_change_slot_item, "changeslotvalue", A_GIMME, 0);
    class_addmethod(c, (method) uislot_change_slot_item, "changeslotitem", A_GIMME, 0);


    
    
    // @method appendslotitem @digest Append a slot element at the end of a slot
    // @description @copy BACH_DOC_MESSAGE_APPENDSLOTITEM
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name slot_element @optional 0 @type llll
    // @mattr modify @type int @default 0 @digest If there is a point at the introduced X coordinate, modify it instead of adding a new one
    // @mattr thresh @type float @default 0. @digest X coordinate threshold for the <m>modify</m> attribute
    // @seealso changeslotitem, prependslotitem, insertslotitem, deleteslotitem, addslot, eraseslot
    class_addmethod(c, (method) uislot_append_slot_item, "appendslotitem", A_GIMME, 0);
    
    // @method prependslotitem @digest Prepend a slot element at the beginning of a slot
    // @description @copy BACH_DOC_MESSAGE_PREPENDSLOTITEM
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name slot_element @optional 0 @type llll
    // @mattr modify @type int @default 0 @digest If there is a point at the introduced X coordinate, modify it instead of adding a new one
    // @mattr thresh @type float @default 0. @digest X coordinate threshold for the <m>modify</m> attribute
    // @seealso appendslotitem, changeslotitem, insertslotitem, deleteslotitem, addslot, eraseslot
    class_addmethod(c, (method) uislot_prepend_slot_item, "prependslotitem", A_GIMME, 0);
    
    // @method insertslotitem @digest Insert a slot element at a given position in a slot
    // @description @copy BACH_DOC_MESSAGE_INSERTSLOTITEM
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name element_position @optional 0 @type int
    // @marg 2 @name slot_element @optional 0 @type llll
    // @mattr modify @type int @default 0 @digest If there is a point at the introduced X coordinate, modify it instead of adding a new one
    // @mattr thresh @type float @default 0. @digest X coordinate threshold for the <m>modify</m> attribute
    // @seealso appendslotitem, prependslotitem, changeslotitem, deleteslotitem, addslot, eraseslot
    class_addmethod(c, (method) uislot_insert_slot_item, "insertslotitem", A_GIMME, 0);
    
    // @method deleteslotitem @digest Delete the slot element at a given position of a slot
    // @description @copy BACH_DOC_MESSAGE_DELETESLOTITEM
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name element_position_or_wrapped_xcoord @optional 0 @type int/llll
    // @mattr thresh @type float @default 0. @digest Tolerance threshold for X matching
    // @example deleteslotitem 3 2 @caption delete 2nd item of 3rd slot
    // @example deleteslotitem 3 [0.7] @caption delete item 3rd slot matching X = 0.7
    // @example deleteslotitem 3 [0.7] @thresh 0.1 @caption the same, with a tolerance of 0.1
    // @seealso appendslotitem, prependslotitem, insertslotitem, changeslotitem, addslot, eraseslot
    class_addmethod(c, (method) uislot_delete_slot_item, "deleteslotitem", A_GIMME, 0);

    
    
    

    // @method resetslotinfo @digest Reset the slotinfo to the default one
    // @description @copy BACH_DOC_RESET_SLOTINFO
    // @seealso eraseslot
    class_addmethod(c, (method) uislot_resetslotinfo, "resetslotinfo", 0);

    
    // @method getdomain @digest Get the current domain
    // @description The <m>getdomain</m> message forces <o>bach.slot</o> to output from the Queries and Notifications outlet the current domain,
    // i.e. the portion of <o>bach.slot</o> currently displayed inside the screen. This makes sense only for types of slots whose content domain
    // is zoomable and mapped on the X axis; namely slots of type function, 3dfunction, spat and dynfilter.
    // The syntax of the output answer is: <b>domain <m>slot_number</m> <m>start</m> <m>end</m></b>, where the 
    // <m>slot_number</m> can be replaced by the slot name, depending on the <m>outputslotnames</m> attribute,
    // and the two following elements are the starting and ending point of the domain. <br />
    // @copy BACH_DOC_QUERY_LABELS
    // @marg 0 @name query_label @optional 1 @type llll
    class_addmethod(c, (method) uislot_getdomain, "getdomain", A_GIMME, 0);


    // @method getdomainpixels @digest Get the pixel position of the domain
    // @description The <m>getdomainpixels</m> message forces <o>bach.slot</o> to output from the playout the current position
    // (in pixels) of the domain, i.e. the starting (left) and ending (right) pixels of the currently displayed portion of slot.
    // These pixels are referred to the notation object box.
    // The syntax of the output answer is: <b>domainpixels <m>start_pixel</m> <m>end_pixel</m></b>, where the 
    // two elements following the "domainpixels" symbol are the leftmost and rightmost horizontal points (in pixels) of the domain. <br />
    // This makes sense only for types of slots whose content domain
    // is zoomable and mapped on the X axis; namely slots of type function, 3dfunction, spat and dynfilter. <br /> 
    // @copy BACH_DOC_QUERY_LABELS
    // @marg 0 @name query_label @optional 1 @type llll
    class_addmethod(c, (method) uislot_getdomainpixels, "getdomainpixels", A_GIMME, 0);

    
    // @method domain @digest Set the displayed domain
    // @description If the <m>domain</m> message is followed by a single number, this is considered as the size
    // of the domain (i.e. the displayed portion of <o>bach.slot</o>) for the currently displayed slot, 
    // and such message will change the local horizontal zoom of the slot so that the displayed
    // portion matches the inserted number. <br />
    // If the <m>domain</m> message is followed by a two numbers, these are considered as the starting and ending domain points for the currently displayed slot,
    // and such message will change both the zoom and the scrollbar position so that the displayed
    // portion of slot starts from the input starting point and ends at the input ending point. <br />
    // This makes sense only for types of slots whose content domain
    // is zoomable and mapped on the X axis; namely slots of type function, 3dfunction, spat and dynfilter.
    // @marg 0 @name start_or_duration @optional 0 @type float
    // @marg 1 @name end @optional 1 @optional 1 @type float
    // @example domain 0.4 @caption force the domain to contain 0.4 domain units
    // @example domain 0.5 0.7 @caption display the portion between x=0.5 and x=0.7
    // @seealso getdomain, getdomainpixels
    class_addmethod(c, (method) uislot_domain, "domain", A_GIMME, 0);
    
    // @method (mouse) @digest Edit slot content
    // @description @copy BACH_DOC_SLOT_EDIT_MOUSE_COMMANDS
    class_addmethod(c, (method) uislot_mouseenter, "mouseenter", A_CANT, 0);
    class_addmethod(c, (method) uislot_mouseleave, "mouseleave", A_CANT, 0);
    class_addmethod(c, (method) uislot_mousemove, "mousemove", A_CANT, 0);
    class_addmethod(c, (method) uislot_mousedown, "mousedown", A_CANT, 0);
    class_addmethod(c, (method) uislot_mousedrag, "mousedrag", A_CANT, 0);
    class_addmethod(c, (method) uislot_mouseup, "mouseup", A_CANT, 0);
    class_addmethod(c, (method) uislot_mousewheel, "mousewheel", A_CANT, 0);
    class_addmethod(c, (method) uislot_mousedoubleclick, "mousedoubleclick", A_CANT, 0);
    class_addmethod(c, (method) uislot_oksize, "oksize", A_CANT, 0);

    class_addmethod(c, (method) uislot_edclose, "edclose", A_CANT, 0);
    class_addmethod(c, (method) uislot_okclose, "okclose", A_CANT, 0);
    
    
    // @method openslotwin @digest Open a slot window
    // @description An <m>openslotwin</m> message, followed by the number of the slot whose window should be open,
    // opens the corresponding slot window. Instead of the slot number, you can use slot names, so you can set a symbol
    // as argument containing the name of the slot whose window should be open.
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @example openslotwin 3 @caption open 3rd slot window
    // @example openslotwin amplienv @caption open slot window for slot named 'amplienv'
    // @seealso addslot
    class_addmethod(c, (method) uislot_anything, "openslotwin", A_GIMME, 0);

    
    // @method (drag) @digest Open file
    // @description Dragging a file on the object will load its content, if a proper readable format is recognized.
    class_addmethod(c, (method) uislot_acceptsdrag,    "acceptsdrag_unlocked", A_CANT, 0);
    class_addmethod(c, (method) uislot_acceptsdrag,    "acceptsdrag_locked", A_CANT, 0);

    
    // @method (keyboard) @digest Edit slot content
    // @description @copy BACH_DOC_SLOT_EDIT_KEYBOARD_COMMANDS
      class_addmethod(c, (method) uislot_key, "key", A_CANT, 0);
      class_addmethod(c, (method) uislot_keyfilter, "keyfilter", A_CANT, 0);
    class_addmethod(c, (method) uislot_enter,    "enter", A_CANT, 0);
    class_addmethod(c, (method) uislot_focusgained, "focusgained", A_CANT, 0);
    class_addmethod(c, (method) uislot_focuslost, "focuslost", A_CANT, 0);
    class_addmethod(c, (method) uislot_jsave, "jsave", A_CANT, 0);

    // @method undo @digest Perform an undo step
    // @description An <m>undo</m> message will perform an undo step. 
    // @seealso redo, inhibitundo, droplastundo
    class_addmethod(c, (method) uislot_undo, "undo", 0);


    // @method redo @digest Perform a redo step
    // @description A <m>redo</m> message will perform a redo step. 
    // @seealso undo, inhibitundo, droplastundo
    class_addmethod(c, (method) uislot_redo, "redo", 0);

    
    // @method inhibitundo @digest Temporarily disable/enable undo step creation
    // @description An <m>inhibitundo</m> message followed by any non-zero number will
    // temporarily disable any undo step creation. Use the same message followed by a zero
    // to re-enable undo steps.
    // @seealso droplastundo, undo, redo
    class_addmethod(c, (method) uislot_inhibit_undo, "inhibitundo", A_LONG, 0);

    
    // @method droplastundo @digest Prune last undo step 
    // @description A <m>droplastundo</m> message will prune the last undo step, by merging
    // its information into the previous one.
    // @seealso inhibitundo, undo, redo
    class_addmethod(c, (method) uislot_prune_last_undo_step, "droplastundo", 0);

    
    class_addmethod(c, (method) uislot_inletinfo, "inletinfo", A_CANT, 0);
    class_addmethod(c, (method) uislot_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method) jbox_notify, "notify", A_CANT, 0);

    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_UI);


    notation_class_add_notation_attributes(c, k_NOTATION_OBJECT_SLOT);
    
    CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 200 100"); 
    // @exclude bach.slot

    CLASS_STICKY_ATTR(c,"category",0,"Slots");
    
    CLASS_ATTR_LONG(c,"activeslot",0, t_notation_obj, active_slot_num_1based);
    CLASS_ATTR_STYLE_LABEL(c,"activeslot",0,"text","Active Slot");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"activeslot", 0, "1");
    CLASS_ATTR_ACCESSORS(c, "activeslot", (method)NULL, (method)uislot_setattr_activeslot);
    CLASS_ATTR_BASIC(c,"activeslot",0);
    // @description The currently open slot. You can also use the slot name, which will be converted into the number

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c,"category",0,"Appearance");

    CLASS_ATTR_DOUBLE(c,"zoom", 0, t_uislot, zoom);
    CLASS_ATTR_STYLE_LABEL(c,"zoom",0,"text","Zoom %");
    CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"zoom",0,"150");
    CLASS_ATTR_FILTER_MIN(c, "zoom", 1);
    CLASS_ATTR_BASIC(c,"zoom",0);
    // @description The zoom factor

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c,"category",0,"Behavior");
    
    CLASS_ATTR_CHAR(c,"notifyopenslot",0, t_uislot, notify_when_open_slot_changes);
    CLASS_ATTR_STYLE_LABEL(c,"notifyopenslot",0,"onoff","Notify About Open Slot");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notifyopenslot",0,"1");
    CLASS_ATTR_BASIC(c,"notifyopenslot",0);
    // @description Toggles the ability to send a notification each time the open slot window
    // is changed (and at the object instantiation, to state the originally open slot window).

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_ATTR_INVISIBLE(c, "fontname", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);
    CLASS_ATTR_INVISIBLE(c, "fontface", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);
    CLASS_ATTR_INVISIBLE(c, "fontsize", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);

    s_uislot_class = c;
    class_register(CLASS_BOX, s_uislot_class);
    
    dev_post("bach.slot compiled %s %s", __DATE__, __TIME__);
    return 0;
}


void uislot_resetslotinfo(t_uislot *x)
{
    create_whole_uislot_undo_tick(x);
    notation_obj_reset_slotinfo((t_notation_obj *)x);
    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CHANGE_SLOTINFO);
}


void uislot_add_slot_do(t_uislot *x, t_llll *slot_as_llll)
{
    create_whole_uislot_undo_tick(x);
    lock_general_mutex((t_notation_obj *)x);
    set_slots_values_to_note_from_llll((t_notation_obj *) x, x->r_ob.dummynote, slot_as_llll);
    unlock_general_mutex((t_notation_obj *)x);
    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_ADD_SLOTS_TO_SELECTION);
}


void uislot_add_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *slot_as_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE); // We clone it: we operate destructively
    if (slot_as_llll)
        uislot_add_slot_do(x, slot_as_llll);
    llll_free(slot_as_llll);
}

void uislot_erase_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    long slotnum;
    
    if (argc < 1) {
        object_error((t_object *)x, "Not enough arguments!");
        return;
    }
    
    slotnum = atom_to_slotnum((t_notation_obj *)x, argv, true);
    if (slotnum < 0 || slotnum >= CONST_MAX_SLOTS) {
        object_error((t_object *)x, "Wrong slot number!");
        return;
    }

    create_whole_uislot_undo_tick(x);
    lock_general_mutex((t_notation_obj *)x);
    note_clear_slot((t_notation_obj *) x, x->r_ob.dummynote, slotnum);
    unlock_general_mutex((t_notation_obj *)x);
    
    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_ERASE_SLOTS_FOR_SELECTION);
}

void uislot_move_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    if (argc < 2) {
        object_error((t_object *)x, "Not enough arguments!");
        return;
    }
    
    long from = atom_to_slotnum((t_notation_obj *)x, argv, true);
    long to = atom_to_slotnum((t_notation_obj *)x, argv + 1, true);
    if (from < 0 || from >= CONST_MAX_SLOTS || to < 0 || to >= CONST_MAX_SLOTS) {
        object_error((t_object *)x, "Wrong slot number!");
        return;
    }
    
    create_whole_uislot_undo_tick(x);
    lock_general_mutex((t_notation_obj *)x);
    move_note_slot((t_notation_obj *) x, x->r_ob.dummynote, from, to, false);
    unlock_general_mutex((t_notation_obj *)x);
    
    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_MOVE_SLOTS_FOR_SELECTION);
}

void uislot_copy_slot(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    if (argc < 2) {
        object_error((t_object *)x, "Not enough arguments!");
        return;
    }
    
    long from = atom_to_slotnum((t_notation_obj *)x, argv, true);
    long to = atom_to_slotnum((t_notation_obj *)x, argv + 1, true);
    if (from < 0 || from >= CONST_MAX_SLOTS || to < 0 || to >= CONST_MAX_SLOTS) {
        object_error((t_object *)x, "Wrong slot number!");
        return;
    }
    
    create_whole_uislot_undo_tick(x);
    lock_general_mutex((t_notation_obj *)x);
    move_note_slot((t_notation_obj *) x, x->r_ob.dummynote, from, to, true);
    unlock_general_mutex((t_notation_obj *)x);
    
    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_COPY_SLOTS_FOR_SELECTION);
}



void uislot_change_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    notationobj_sel_change_slot_item_from_params((t_notation_obj *)x, args, s == _llllobj_sym_lambda, k_CHANGESLOTITEM_MODE_MODIFY_ONE);
    llll_release(args);
}


void uislot_append_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    if (args->l_head)
        llll_insertlong_after(1, args->l_head); // inserting dummy position
    notationobj_sel_change_slot_item_from_params((t_notation_obj *)x, args, s == _llllobj_sym_lambda, k_CHANGESLOTITEM_MODE_APPEND);
    llll_release(args);
}


void uislot_prepend_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    if (args->l_head)
        llll_insertlong_after(1, args->l_head); // inserting dummy position
    notationobj_sel_change_slot_item_from_params((t_notation_obj *)x, args, s == _llllobj_sym_lambda, k_CHANGESLOTITEM_MODE_PREPEND);
    llll_release(args);
}

void uislot_insert_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    notationobj_sel_change_slot_item_from_params((t_notation_obj *)x, args, s == _llllobj_sym_lambda, k_CHANGESLOTITEM_MODE_INSERT_AUTO);
    llll_release(args);
}


void uislot_delete_slot_item(t_uislot *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    notationobj_sel_change_slot_item_from_params((t_notation_obj *)x, args, s == _llllobj_sym_lambda, k_CHANGESLOTITEM_MODE_DELETE_ONE);
    llll_release(args);
}








t_max_err uislot_setattr_activeslot(t_uislot *x, t_object *attr, long ac, t_atom *av){
    if (ac && av) {
        long slot;
        if (atom_gettype(av) == A_SYM)
            slot = slotname_to_slotnum((t_notation_obj *)x, atom_getsym(av)) + 1;
        else
            slot = atom_getlong(av);
        open_slot_window((t_notation_obj *)x, slot - 1, (t_notation_item *)x->r_ob.dummynote);
    }
    return MAX_ERR_NONE;
}


void uislot_assist(t_uislot *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing slotinfo and/or slot content
        sprintf(s, "llll: Slot data or Slotinfo"); // @description See the <m>llll</m> method for more information
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
        switch (a)
        {
            case 0:    // @out 0 @type llll @digest The whole object dump
                sprintf(s, "llll (%s): Dump", type); // @description The information about the slotinfo and/or slot content is sent through this outlet, when a "dump" is requested.
                break;                                 // See the <m>dump</m> message to know more about the output syntax.
            case 1: // @out 1 @type llll @digest Notifications and answers to queries
                sprintf(s, "llll (%s): Queries and Notifications", type); // @description This outlet sends the notifications and the answer to incoming queries, such as <m>sample</m> or <m>interp</m>.
                break;
            case 2:  // @out 2 @type bang @digest bang when changed
                sprintf(s, "bang When Changed"); // @description This outlet sends a bang whenever any element is changed via the interface.
                break;
        }
    }
}

void uislot_inletinfo(t_uislot *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}


void create_whole_uislot_undo_tick(t_uislot *x){
    if (x->r_ob.inhibited_undo)
        return;
    if (!(atom_gettype(&x->r_ob.max_undo_steps) == A_LONG && atom_getlong(&x->r_ob.max_undo_steps) == 0)) {
        t_llll *content = get_uislot_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_ALL, NULL, true, true);
        // we clone the content outside the memory pool so that it does not fill it
        t_llll *content_cloned = llll_clone_extended(content, WHITENULL_llll, 1, NULL);
        t_undo_redo_information *operation = build_undo_redo_information(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, content_cloned);
        llll_free(content);
        create_undo_redo_tick((t_notation_obj *) x, k_UNDO, 0, operation, true);
    }
}



// 0-based
long get_slotnum_from_llllelem(t_notation_obj *r_ob, t_llllelem *elem)
{
    long slot_num = hatom_gettype(&elem->l_hatom) == H_SYM ? 
                        slotname_to_slotnum(r_ob, hatom_getsym(&elem->l_hatom)) :
                        (is_hatom_number(&elem->l_hatom) ? hatom_getlong(&elem->l_hatom) - 1 : -1);
    return slot_num;
}

void uislot_anything(t_uislot *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
    
    t_llll *inputlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);
    
    if (inputlist && inputlist->l_head) {
        
        if (hatom_gettype(&inputlist->l_head->l_hatom) == H_SYM && hatom_getsym(&inputlist->l_head->l_hatom) != _llllobj_sym_slot) {
            t_symbol *router = hatom_getsym(&inputlist->l_head->l_hatom);
            
            if (router == _sym_paste) {
                uislot_paste(x, s, argc, argv);
                
            } else if (router == _llllobj_sym_clear) {
                create_whole_uislot_undo_tick(x);
                if (inputlist->l_head->l_next) {
                    long slot_num = get_slotnum_from_llllelem((t_notation_obj *)x, inputlist->l_head->l_next);
                    note_clear_slot((t_notation_obj *) x, x->r_ob.dummynote, slot_num);
                } else {
                    long i;
                    for (i = 0; i < CONST_MAX_SLOTS; i++)
                        note_clear_slot((t_notation_obj *) x, x->r_ob.dummynote, i);
                }
                handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CLEAR_UISLOT);
                
                
            } else if (router == gensym("openslotwin")) {
                if (inputlist->l_head->l_next) {
                    long slot = llllelem_to_slotnum((t_notation_obj *)x, inputlist->l_head->l_next, true);
                    uislot_int(x, slot + 1);
                }
                
                
            } else if (router == gensym("refresh")) {
                notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);

            
            } else if (router == _sym_dump) {
                if (inputlist && inputlist->l_size > 1 && get_slotnum_from_llllelem((t_notation_obj *)x, inputlist->l_head->l_next) >= 0) {
                    llll_behead(inputlist);
                    send_uislot_values_as_llll(x, k_HEADER_BODY, inputlist);
                } else {
                    long send_what = inputlist && inputlist->l_size > 1 ? header_objects_to_long(inputlist) : -1;
                    llll_behead(inputlist);
                    send_uislot_values_as_llll(x, send_what, NULL);
                }
                
                
                
            } else if (router == _llllobj_sym_next) {
                open_slot_window((t_notation_obj *) x, MIN(CONST_MAX_SLOTS - 1, x->r_ob.active_slot_num + 1), (t_notation_item *)x->r_ob.dummynote);
            
            } else if (router == _llllobj_sym_prev) {
                // shift+tab on a slot goes to the next one
                open_slot_window((t_notation_obj *) x, MAX(0, x->r_ob.active_slot_num - 1), (t_notation_item *)x->r_ob.dummynote);
            
            } else if (router == _llllobj_sym_interp) {
                // asking for interpolation
                if (inputlist->l_size >= 3) {
                    t_llll *out_ll = llll_get();
                    llll_appendsym(out_ll, _llllobj_sym_interp);

                    lock_general_mutex((t_notation_obj *)x);

                    t_llllelem *slots_elem = inputlist->l_head->l_next;
                    t_llllelem *positions_elem = inputlist->l_head->l_next->l_next;
                    if (hatom_gettype(&slots_elem->l_hatom) == H_LLLL && hatom_gettype(&positions_elem->l_hatom) == H_LLLL) {
                        // multi-slots AND multipositions
                        t_llll *slots = slots_develop_ranges((t_notation_obj *) x, hatom_getllll(&inputlist->l_head->l_next->l_hatom));
                        t_llll *positions = hatom_getllll(&positions_elem->l_hatom);
                        
                        for (t_llllelem *el = slots->l_head; el; el = el->l_next) {
                            long slot_num = llllelem_to_slotnum((t_notation_obj *) x, el, true);
                            t_llll *this_ll = llll_get();
                            for (t_llllelem *posel = positions->l_head; posel; posel = posel->l_next) {
                                double pt_x = is_hatom_number(&posel->l_hatom) ? hatom_getdouble(&posel->l_hatom) : 0.;
                                double pt_y = get_function_slot_interp((t_notation_obj *)x, x->r_ob.dummynote, slot_num, pt_x);
                                llll_appenddouble(this_ll, pt_y);
                            }
                            llll_appendllll(out_ll, this_ll);
                        }
                        llll_free(slots);
                    } else if (hatom_gettype(&slots_elem->l_hatom) == H_LLLL) {
                        // multi-slots but single position
                        t_llll *slots = slots_develop_ranges((t_notation_obj *) x, hatom_getllll(&inputlist->l_head->l_next->l_hatom));

                        for (t_llllelem *el = slots->l_head; el; el = el->l_next) {
                            long slot_num = llllelem_to_slotnum((t_notation_obj *) x, el, true);
                            double pt_x = is_hatom_number(&positions_elem->l_hatom) ? hatom_getdouble(&positions_elem->l_hatom) : 0.;
                            double pt_y = get_function_slot_interp((t_notation_obj *)x, x->r_ob.dummynote, slot_num, pt_x);
                            llll_appenddouble(out_ll, pt_y);
                        }
                        llll_free(slots);
                    } else if (hatom_gettype(&positions_elem->l_hatom) == H_LLLL) {
                        // multi-positions but single slot
                        t_llll *positions = hatom_getllll(&positions_elem->l_hatom);
                        
                        t_llll *this_ll = llll_get();
                        for (t_llllelem *posel = positions->l_head; posel; posel = posel->l_next) {
                            long slot_num = llllelem_to_slotnum((t_notation_obj *) x, slots_elem, true);
                            double pt_x = is_hatom_number(&posel->l_hatom) ? hatom_getdouble(&posel->l_hatom) : 0.;
                            double pt_y = get_function_slot_interp((t_notation_obj *)x, x->r_ob.dummynote, slot_num, pt_x);
                            llll_appenddouble(this_ll, pt_y);
                        }
                        llll_appendllll(out_ll, this_ll);
                    } else {
                        // standard simple case
                        long slot_num = llllelem_to_slotnum((t_notation_obj *) x, slots_elem, true);
                        double pt_x = is_hatom_number(&positions_elem->l_hatom) ? hatom_getdouble(&positions_elem->l_hatom) : 0.;
                        double pt_y = get_function_slot_interp((t_notation_obj *)x, x->r_ob.dummynote, slot_num, pt_x);
                        llll_appenddouble(out_ll, pt_y);
                    }

                    unlock_general_mutex((t_notation_obj *)x);

                    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, out_ll);
                    llll_free(out_ll);
                }
            } else if (router == _llllobj_sym_sample) {
                // asking for sampling
                if (inputlist->l_size >= 3) {
                    long slot_num = llllelem_to_slotnum((t_notation_obj *) x, inputlist->l_head->l_next, true);
                    long num_pts = is_hatom_number(&inputlist->l_head->l_next->l_next->l_hatom) ? hatom_getlong(&inputlist->l_head->l_next->l_next->l_hatom) : 10;
                    char is_delta = false;
                    double delta = 0;
                    if (inputlist->l_size >= 4 && hatom_gettype(&inputlist->l_head->l_next->l_next->l_next->l_hatom) == H_SYM && hatom_getsym(&inputlist->l_head->l_next->l_next->l_next->l_hatom) == gensym("delta")) {
                        delta = hatom_getdouble(&inputlist->l_head->l_next->l_next->l_hatom);
                        is_delta = true;
                    }
                    t_llll *sampled = is_delta ? get_function_slot_sampling_delta((t_notation_obj *)x, x->r_ob.dummynote, slot_num, delta) : get_function_slot_sampling((t_notation_obj *)x, x->r_ob.dummynote, slot_num, num_pts);
                    if (sampled) {
                        llll_prependsym(sampled, _llllobj_sym_sample, 0, WHITENULL_llll);
                        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, sampled);
                        llll_free(sampled);
                    }
                }
            } else if (router == _llllobj_sym_addslot) {
                llll_behead(inputlist);
                uislot_add_slot_do(x, inputlist);
            } else if (!x->r_ob.itsme) {
                // trying to send deparsed message to uislot, 
                // TO DO: not the best way, though, at least for long messages!...
                t_atom *av = NULL, rv;
                long ac = llll_deparse(inputlist, &av, 0, 0);
                if (ac) {
                    x->r_ob.itsme = true;
                    object_method_typed((t_object *)x, hatom_getsym(&inputlist->l_head->l_hatom), ac - 1, av + 1, &rv);
                    x->r_ob.itsme = false;
                }
                bach_freeptr(av);
            } else {
                post_unknown_message((t_object *) x, inputlist);
            }
        } else {
            create_whole_uislot_undo_tick(x);
            set_uislot_from_llll(x, inputlist, true);
            handle_rebuild_done((t_notation_obj *) x);
            handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOTS_FROM_MESSAGE);
        }
    }
    
    llll_free(inputlist);
}

void set_uislot_from_llll_from_read(t_uislot *x, t_llll* inputlist){  
    if (inputlist) {
        create_whole_uislot_undo_tick(x); 
        set_uislot_from_llll(x, inputlist, true);
        handle_rebuild_done((t_notation_obj *) x);
        handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_READ_UISLOT);
        llll_free(inputlist);
    }
}

void set_uislot_from_llll(t_uislot *x, t_llll* inputlist, char also_lock_general_mutex){  
// set the whole uislot, starting from a llll (it clones the llll)

    t_llll *wholeuislot = llll_get();
    
    if (!inputlist) { 
        llll_free(wholeuislot); 
        return; 
    }
    
    if (also_lock_general_mutex)
        lock_general_mutex((t_notation_obj *)x);    

    llll_clone_upon(inputlist, wholeuislot);
    

    // if we have a "slot" message at the beginning, we get rid of it (ok, it's a "signature" that everything is ok)
    if (wholeuislot->l_size > 0 && hatom_gettype(&wholeuislot->l_head->l_hatom) == H_SYM) { 
        t_llllelem *firstelem = wholeuislot->l_head; // this is a symbol
        t_symbol *firstsym = hatom_getsym(&firstelem->l_hatom);
        if (firstsym == _llllobj_sym_slot) 
            llll_destroyelem(firstelem);
        else if (firstsym == _llllobj_sym_score || firstsym == _llllobj_sym_roll) {
            object_error((t_object *) x, "Can't load a bach.%s content into a bach.slot.", firstsym->s_name);
            llll_free(wholeuislot);
            
            if (also_lock_general_mutex)
                unlock_general_mutex((t_notation_obj *)x);    
            
            return;
        }
    }

    if (wholeuislot->l_size > 0) { 
        
        // checking header
        while (true) { // cycle on the header elements
            t_llllelem *firstelem = wholeuislot->l_head; // this has to be a linked list
            
            if (!firstelem) 
                break; // there's no body content
            
            if (hatom_gettype(&firstelem->l_hatom) == H_LLLL) {
                t_llll *firstllll = hatom_getllll(&firstelem->l_hatom);
                if (firstllll->l_size > 0) {
                    t_llllelem *pivot = firstllll->l_head;
                    if (hatom_gettype(&pivot->l_hatom) == H_SYM) {
                        // we're still in the header;
                        t_symbol *pivotsym = hatom_getsym(&pivot->l_hatom);
                        if (pivotsym == _llllobj_sym_slots) {
                            break;
                        } else if (pivotsym == _llllobj_sym_slotinfo) {
                            llll_destroyelem(pivot); // we kill the pivot, in order to give the correct llll to the set_slotinfo function
                            set_slotinfo_from_llll((t_notation_obj *) x, firstllll);
                        }
                    } else 
                        break; // break and go to the body of the object!
                } else 
                    break; // break and go to the body of the object!
            }
            llll_destroyelem(firstelem); // we kill the first element and continue
        }
        
        if (wholeuislot && wholeuislot->l_size > 0) {
            long i;
            for (i = 0; i < CONST_MAX_SLOTS; i++)
                note_clear_slot((t_notation_obj *) x, x->r_ob.dummynote, i);
            
            llll_flatten(wholeuislot, 1, 0);
            set_slots_values_to_note_from_llll((t_notation_obj *) x, x->r_ob.dummynote, wholeuislot);
        }
    }
    
    if (also_lock_general_mutex)
        unlock_general_mutex((t_notation_obj *)x);    
    
    llll_free(wholeuislot);
    jbox_redraw((t_jbox *)x);
}


long uislot_oksize(t_uislot *x, t_rect *newrect)
{
    return 0;
}
    
t_uislot* uislot_new(t_symbol *s, long argc, t_atom *argv)
{
    int i;
    t_uislot* x = NULL;
    t_max_err err = MAX_ERR_GENERIC;
    t_dictionary *d;
    long flags;
    
    if (!(d=object_dictionaryarg(argc,argv)))
        return NULL;

    x = (t_uislot*) object_alloc_debug(s_uislot_class);
    flags = 0 
            | JBOX_DRAWFIRSTIN 
            | JBOX_NODRAWBOX
            | JBOX_DRAWINLAST
    //        | JBOX_TRANSPARENT    
    //        | JBOX_NOGROW
    //        | JBOX_GROWY
            | JBOX_GROWBOTH
            | JBOX_HILITE
    //        | JBOX_BACKGROUND
            | JBOX_TEXTFIELD
    //        | JBOX_DRAWBACKGROUND
    //        | JBOX_DEFAULTNAMES
    //        | JBOX_MOUSEDRAGDELTA
            ;
    
    x->r_ob.creatingnewobj = 1;
    err = jbox_new(&x->r_ob.j_box.l_box, flags, argc, argv); 
    x->r_ob.j_box.l_box.b_firstin = (t_object*) x;

    x->r_ob.obj_type = k_NOTATION_OBJECT_SLOT;
    x->r_ob.slot_window_zoom = x->r_ob.bgslot_zoom = 100;

    notation_obj_init((t_notation_obj *) x, k_NOTATION_OBJECT_SLOT, (rebuild_fn) set_uislot_from_llll, (notation_obj_fn) create_whole_uislot_undo_tick, NULL, (notation_obj_undo_redo_fn)uislot_new_undo_redo, (bach_paint_ext_fn)uislot_paint_ext);

    x->r_ob.active_slot_num = 0;
    x->r_ob.active_slot_num_1based = 1;
    x->r_ob.slot_background_alpha_percentage = 100;

    // retrieving patcher parent
    object_obex_lookup(x, gensym("#P"), &(x->r_ob.patcher_parent));
    
    // initializing undo/redo lists
    for (i = 0; i < CONST_MAX_UNDO_STEPS; i++) {
        x->r_ob.old_undo_llll[i] = NULL;
        x->r_ob.old_redo_llll[i] = NULL;
    }
    
    initialize_popup_menus((t_notation_obj *) x);
    initialize_slots((t_notation_obj *) x, false);
    
    // initializing dummy note
    double noteav[2];
    noteav[0] = CONST_DEFAULT_NEW_NOTE_CENTS;
    noteav[1] = CONST_DEFAULT_NEW_NOTE_DURATION;
    x->r_ob.dummynote = build_note_from_ac_av((t_notation_obj *) x, 2, noteav);
    x->r_ob.active_slot_notationitem = (t_notation_item *)x->r_ob.dummynote;    // constantly!

    
    // retrieve saved attribute values
    attr_dictionary_process(x, d);
    
    /// Find first accessible slot
    for (i = x->r_ob.active_slot_num; i < x->r_ob.active_slot_num + CONST_MAX_SLOTS; i++) {
        long j = i % CONST_MAX_SLOTS;
        if (x->r_ob.slotinfo[j].access_type != k_SLOT_ACCESS_CANT) {
            x->r_ob.active_slot_num = j;
            x->r_ob.active_slot_num_1based = j+1;
            break;
        }
    }
    
    // setup llll
    llllobj_jbox_setup((t_llllobj_jbox *) x, 2, "b44"); 

    initialize_textfield((t_notation_obj *) x);    
    
    // retrieving vlues
    x->r_ob.add_staff = 0;
    x->r_ob.itsme = 0;
    x->r_ob.add_voice = 0;
    x->r_ob.j_inset_y = 0.5;
    set_mousedown((t_notation_obj *)x, NULL, k_NONE);


    for (i = 0; i < CONST_MAX_SLOTS; i++)
        x->r_ob.slotinfo[i].slot_uwidth = x->r_ob.slotinfo[i].slot_active_uheight = -1;
    
    x->r_ob.m_editor = NULL;

    jbox_ready(&x->r_ob.j_box.l_box);

    if (x) {
        // retrieving values
        t_llll *llll_for_rebuild = llll_retrieve_from_dictionary(d, "whole_uislot_data");
        llllobj_manage_dict_llll((t_object *)x, LLLL_OBJ_UI, llll_for_rebuild);
        if (llll_for_rebuild) { // new method
            set_uislot_from_llll(x, llll_for_rebuild, true);
            if (x->r_ob.send_rebuild_done_at_startup)
                handle_rebuild_done((t_notation_obj *) x);
            llll_free(llll_for_rebuild);
        }
        
        if (!USE_NEW_UNDO_SYSTEM && x->r_ob.allow_undo)
            x->r_ob.old_undo_llll[0] = get_uislot_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_BODY + k_HEADER_SLOTINFO, NULL, true, true);
        
        x->r_ob.last_undo_time = systime_ms();

        llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_UI);
        x->r_ob.creatingnewobj = 0;

        return x;
    }

    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL; 

}


void uislot_int(t_uislot *x, t_atom_long num){
    open_slot_window((t_notation_obj *) x, CLAMP(num, 1, CONST_MAX_SLOTS) - 1, (t_notation_item *)x->r_ob.dummynote);
    if (x->r_ob.notify_also_upon_messages && x->notify_when_open_slot_changes)
        send_changed_open_slot_notification((t_notation_obj *)x, 1);
}

void uislot_float(t_uislot *x, double num){
    t_atom argv[1]; atom_setfloat(argv, num);
    uislot_anything(x, _llllobj_sym_list, 1, argv);
}

void uislot_free(t_uislot *x){
    free_note((t_notation_obj *)x, x->r_ob.dummynote);
    notation_obj_free((t_notation_obj *) x);
}


void uislot_paint_ext(t_uislot *x, t_object *view, t_jgraphics *g, t_rect rect)
{
    paint_background((t_object *)x, g, &rect, &x->r_ob.j_background_rgba, x->r_ob.corner_roundness);

    x->r_ob.height = rect.height;
    x->r_ob.width = rect.width;

    if (x->r_ob.zoom_y == 0) 
        x->r_ob.firsttime = 1;
    if (x->r_ob.firsttime) { // actually, it shouldn't be used anymore (only vzoom set is needed)
        x->r_ob.slot_window_active = x->r_ob.slot_window_active_nozoom = build_rect(CONST_SLOT_WINDOW_INSET_X, 0, rect.width - 2 * CONST_SLOT_WINDOW_INSET_X, rect.height); // needed to properly deal with background slots at the first painting 
        x->r_ob.zoom_y = 1;
        x->r_ob.firsttime = 0; 
    }

    lock_general_mutex((t_notation_obj *)x);
    if (x->r_ob.active_slot_num >= 0 && x->r_ob.active_slot_num < CONST_MAX_SLOTS) {
        x->r_ob.zoom_x = 1;
        x->r_ob.zoom_y = x->zoom/100.;
        x->r_ob.slot_window_ms1 = 0;
        x->r_ob.slot_window_ms2 = 1000; // dummy
        
        x->r_ob.slot_window_x1 = 1;
        x->r_ob.slot_window_x2 = rect.width - 2;
        
        if (x->r_ob.slot_background_alpha_percentage < 100) {
            t_jfont *jf_text_small = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(x->r_ob.slot_background_font_size * x->r_ob.zoom_y));  // text font (small and bold)
            t_jfont *jf_text_smallbold = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(x->r_ob.slot_background_font_size * x->r_ob.zoom_y));  // text font (small and bold)
            t_jfont *jf_dynamics = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(x->r_ob.slot_background_font_size * 2 * x->r_ob.zoom_y));  // text font (small and bold)
            t_jfont *jf_dynamics_roman = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, round(x->r_ob.slot_background_font_size * x->r_ob.zoom_y));

            double slot_window_active_x1 = CONST_SLOT_WINDOW_INSET_X;
            double slot_window_active_width = (rect.width - 2 * CONST_SLOT_WINDOW_INSET_X) * x->r_ob.slot_window_hzoom_factor;
            slot_window_active_x1 -= x->r_ob.slot_window_zoomed_start * slot_window_active_width;
            
            t_rect rect_oo = build_rect(0, 0, rect.width, rect.height);
            t_jsurface *bg_slots_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, rect_oo.width, rect_oo.height);
            t_jgraphics *bg_slots_g = jgraphics_create(bg_slots_surface);
            
            paint_background_slots((t_notation_obj *) x, bg_slots_g, 
                        slot_window_active_x1, rect.height - CONST_SLOT_FUNCTION_UY_INSET_BOTTOM * x->r_ob.zoom_y, slot_window_active_width,
                        jf_text_small, jf_text_smallbold, jf_dynamics, jf_dynamics_roman, (t_notation_item *)x->r_ob.dummynote, 0, 0, 0, 0, x->r_ob.active_slot_num);
            jgraphics_set_source_rgba(g, 0, 0, 0, (100 - x->r_ob.slot_background_alpha_percentage)/100.); 
            jgraphics_set_source_rgba(bg_slots_g, 0, 0, 0, (100 - x->r_ob.slot_background_alpha_percentage)/100.); 
            jgraphics_image_surface_draw(g, bg_slots_surface, rect_oo, rect_oo);
            
            jgraphics_destroy(bg_slots_g);
            jgraphics_surface_destroy(bg_slots_surface);
            
            jfont_destroy_debug(jf_text_small);
            jfont_destroy_debug(jf_text_smallbold);
            jfont_destroy_debug(jf_dynamics);
            jfont_destroy_debug(jf_dynamics_roman);
        }

        if (x->r_ob.active_slot_num_1based == 0)
            notationobj_throw_issue((t_notation_obj *)x);
            
        paint_slot((t_notation_obj *) x, g, rect, (t_notation_item *)x->r_ob.dummynote, x->r_ob.active_slot_num);
    } else {
        t_jrgba grey = get_grey(0.2);
        paint_line(g, grey, 0, 0, rect.width, rect.height, 1);
        paint_line(g, grey, 0, rect.height, rect.width, 0, 1);
    }
    unlock_general_mutex((t_notation_obj *)x);
    
    if (x->r_ob.need_send_rebuild_done_after_paint) {
        // sending rebuild done (will be deferred_low!!!)
        send_rebuild_done((t_notation_obj *) x);
        x->r_ob.need_send_rebuild_done_after_paint = false;
    }

    t_jrgba border_color = (x->r_ob.active_slot_num >= 0 && x->r_ob.active_slot_num < CONST_MAX_SLOTS) ? x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_color : get_grey(0.5);
    paint_border((t_object *)x, g, &rect, &border_color, (!x->r_ob.show_border) ? 0 : (x->r_ob.j_has_focus && x->r_ob.show_focus ? 2.5 : 1), x->r_ob.corner_roundness);
}

void uislot_paint(t_uislot *x, t_object *view)
{
    
    t_jgraphics *g;
    t_rect rect;
    
    g = (t_jgraphics*) patcherview_get_jgraphics(view);
    jbox_get_rect_for_view(&x->r_ob.j_box.l_box.b_ob, view, &rect);
    
    uislot_paint_ext(x, view, g, rect);
    
    if (x->r_ob.jit_destination_matrix && strlen(x->r_ob.jit_destination_matrix->s_name) > 0)
        uislot_paint_to_jitter_matrix(x, x->r_ob.jit_destination_matrix);

    send_changed_bang_and_automessage_if_needed((t_notation_obj *)x);

    if (x->r_ob.notify_when_painted)
        llllobj_outlet_symbol_as_llll((t_object *)x, LLLL_OBJ_UI, 1, _llllobj_sym_painted);
}

void uislot_paint_to_jitter_matrix(t_uislot *x, t_symbol *matrix_name)
{
    bach_paint_to_jitter_matrix((t_object *)x, matrix_name, x->r_ob.width, x->r_ob.height, (bach_paint_ext_fn)uislot_paint_ext);
}


void uislot_jsave(t_uislot *x, t_dictionary *d)
{
    if (x->r_ob.save_data_with_patcher){
        if (x->r_ob.j_box.l_dictll) {
            llll_store_in_dictionary(x->r_ob.j_box.l_dictll, d, "whole_uislot_data", NULL);
        } else {
            t_llll *whole_info = get_uislot_values_as_llll(x, x->r_ob.bwcompatible <= 7900 ? k_CONSIDER_FOR_SAVING_WITH_BW_COMPATIBILITY : k_CONSIDER_FOR_SAVING, k_HEADER_BODY + k_HEADER_SLOTINFO, NULL, true, false);
            llll_store_in_dictionary(whole_info, d, "whole_uislot_data", NULL);
            llll_free(whole_info);
        }
    }
}


///////////////////////////////////////////
///////////// MOUSE ACTIONS ///////////////
///////////////////////////////////////////

void uislot_mouseenter(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers) {
    x->r_ob.j_mouse_is_over = true;
    jbox_redraw((t_jbox *)x);
}

void uislot_mouseleave(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers) {
    x->r_ob.j_mouse_is_over = false;
    jbox_redraw((t_jbox *)x);
}

void uislot_mousemove(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers) {
    
    char redraw = false, mousepointerchanged = false;
    long new_cursor = -1;
    
    llll_format_modifiers(&modifiers, NULL);

    // track mouse position
    x->r_ob.j_mouse_x = pt.x; 
    x->r_ob.j_mouse_y = pt.y;

    if (x->r_ob.hovered_slotitem && (is_pt_in_inner_slot_subwindow((t_notation_obj *)x, pt) || x->r_ob.j_mouse_is_down))
        new_cursor = x->r_ob.hovering_segment ? BACH_CURSOR_RESIZE_UPDOWN : BACH_CURSOR_RESIZE_FOURWAY;
    else
        new_cursor = BACH_CURSOR_DEFAULT;
    
    if (x->r_ob.mouse_hover)
        slot_handle_mousemove((t_notation_obj *) x, patcherview, pt, modifiers, &redraw, &mousepointerchanged);
    
    if (!mousepointerchanged && new_cursor >= 0)
        bach_set_cursor((t_object *)x, &x->r_ob.j_mouse_cursor, patcherview, (e_bach_mouse_cursors)new_cursor);
    
    
    if (redraw)
        jbox_redraw((t_jbox *)x);
}



void uislot_mousedrag(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers){
    char slot_dragged = 0;
    char redraw = 0; // do we have to redraw?
    char changed = 0;
    t_rect rect;

    llll_format_modifiers(&modifiers, NULL);

    // getting rectangle dimensions
    jbox_get_rect_for_view(&x->r_ob.j_box.l_box.b_ob, patcherview, &rect);

    x->r_ob.j_isdragging = true;

    if (x->r_ob.main_dragging_direction == 0)
        x->r_ob.main_dragging_direction = (fabs(x->r_ob.j_mousedown_point.x - pt.x) > fabs(x->r_ob.j_mousedown_point.y - pt.y) ? -1 : 1);

    
    if (modifiers & eShiftKey && modifiers & eCommandKey) {
        x->r_ob.j_mousedrag_point_shift_ffk.x += (pt.x - x->r_ob.j_mousedrag_point.x) * CONST_FINER_FROM_KEYBOARD;
        x->r_ob.j_mousedrag_point_shift_ffk.y += (pt.y - x->r_ob.j_mousedrag_point.y) * CONST_FINER_FROM_KEYBOARD;
        x->r_ob.j_mousedrag_point = pt;
    } else if (modifiers == eShiftKey) {
        if (x->r_ob.main_dragging_direction < 0)
            x->r_ob.j_mousedrag_point_shift_ffk.x = pt.x;
        else
            x->r_ob.j_mousedrag_point_shift_ffk.y = pt.y;
        x->r_ob.j_mousedrag_point = pt;
    } else {
        x->r_ob.j_mousedrag_point_shift_ffk = x->r_ob.j_mousedrag_point = pt;
    }
    
    // first of all: are we in a slot mode???? Cause if we are in a slot mode, we gotta handle that separately
    slot_dragged = slot_handle_mousedrag((t_notation_obj *) x, patcherview, pt, modifiers, &changed, &redraw);
    if (slot_dragged) {
        jbox_redraw((t_jbox *) x);
        handle_change((t_notation_obj *) x, x->r_ob.continuously_output_changed_bang ? k_CHANGED_STANDARD_SEND_BANG : k_CHANGED_DO_NOTHING, k_UNDO_OP_UNKNOWN);
        x->r_ob.changed_while_dragging = true;
        return;
    }
}

t_atom_long uislot_acceptsdrag(t_uislot *x, t_object *drag, t_object *view)
{
    return notationobj_acceptsdrag((t_notation_obj *)x, drag, view);
}


void uislot_okclose(t_uislot *x, char *s, short *result)
{
    *result = 3;
}

void uislot_edclose(t_uislot *x, char **ht, long size){
    notation_obj_edclose((t_notation_obj *) x, ht, size);
}




void uislot_mousedown(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers){
    double this_x, this_y;
    void* clicked_ptr = NULL; 
    e_element_types clicked_obj = k_ELEMENT_TYPES_UNDEFINED; 
    char clicked_slot = 0, changed = 0;
    char need_popup = modifiers & eRightButton;
    
    evnum_incr();

    llll_format_modifiers(&modifiers, NULL);

    x->r_ob.j_mouse_is_down = false;
    x->r_ob.j_isdragging = false;
    x->r_ob.j_clicked_obj_has_been_selected = false;
    x->r_ob.changed_while_dragging = false;
    x->r_ob.j_mouse_hasbeendragged = 0; // we'll need this later, to check whether the mouse has been dragged
    x->r_ob.j_selection_hasbeendragged = 0; // we'll need this later, to check whether the mouse has been dragged
    x->r_ob.j_mousedown_point = pt;
    x->r_ob.j_mousedrag_point = x->r_ob.j_mousedrag_point_shift_ffk = pt; 
    // gotta find if there's an element selected! We start with notes:
    x->r_ob.j_mouse_is_down = true;
//    x->r_ob.dragging_x = pt.x;
//    x->r_ob.dragging_y = pt.y;
    x->r_ob.floatdragging_x = pt.x;
    x->r_ob.floatdragging_y = pt.y;
    x->r_ob.main_dragging_direction = 0;

    this_x = pt.x; 
    this_y = pt.y; // click-point coordinates

    lock_general_mutex((t_notation_obj *)x);    
    clicked_slot = slot_handle_mousedown((t_notation_obj *) x, patcherview, pt, modifiers, &clicked_obj, &clicked_ptr, &changed, need_popup);
    unlock_general_mutex((t_notation_obj *)x);    

    handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_SEND_BANG, k_UNDO_OP_CHANGE_SLOT);
}


void send_uislot_values_as_llll(t_uislot *x, long send_what, t_llll *slot_indices){
    t_llll* out_llll = get_uislot_values_as_llll(x, k_CONSIDER_FOR_DUMPING, send_what, slot_indices, true, false);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 0, out_llll);
    llll_free(out_llll);
}


t_llll* note_get_some_slots_values_as_llll(t_notation_obj *r_ob, t_note *note, char mode, t_llll *slot_indices){
    // if mode == 2 it's a partialnote
    
    // slots
    t_llll* out_llll = llll_get();
    t_llll* slot_indices_all_numerical = slot_indices ? llll_clone(slot_indices) : NULL;
    
    t_llllelem *elem;
    if (slot_indices) {
        for (elem = slot_indices_all_numerical->l_head; elem; elem = elem->l_next) {
            long this_slot_num = get_slotnum_from_llllelem(r_ob, elem);
            hatom_change_to_long(&elem->l_hatom, this_slot_num + 1); // 1-based
        }
    }
    
    int j;
    llll_appendsym(out_llll, _llllobj_sym_slots, 0, WHITENULL_llll); 
    
    for (j=0; j<CONST_MAX_SLOTS; j++) {
        if ((!slot_indices_all_numerical || slot_indices_all_numerical->l_size == 0 || is_long_in_llll_first_level(slot_indices_all_numerical, j + 1)) && note->slot[j].firstitem) {
            
            t_llll *thisslot_llll = note_get_single_slot_values_as_llll(r_ob, note, mode, j, false);
            llll_appendllll(out_llll, thisslot_llll, 0, WHITENULL_llll);
        }
    }
    
    if (slot_indices_all_numerical)
        llll_free(slot_indices_all_numerical);
    
    return out_llll;
}


// dump_what is a combination of e_header_elems
// slot_indices is a list of 1-based indices of the slots to ouptut, leave NULL for all slots 
t_llll* get_uislot_values_as_llll(t_uislot *x, e_data_considering_types for_what, long dump_what, t_llll *slot_indices, char also_lock_general_mutex, char explicitly_get_also_default_stuff) {
    t_llll* out_llll = llll_get();
    
    llll_appendsym(out_llll, _llllobj_sym_slot, 0, WHITENULL_llll); // "slot" router

    if (also_lock_general_mutex)
        lock_general_mutex((t_notation_obj *)x);    
    
    llll_chain(out_llll, get_notation_obj_header_as_llll((t_notation_obj *)x, dump_what, false, explicitly_get_also_default_stuff, for_what == k_CONSIDER_FOR_UNDO, for_what));
    
    if (dump_what & k_HEADER_BODY)
        llll_appendllll(out_llll, note_get_some_slots_values_as_llll((t_notation_obj *) x, x->r_ob.dummynote, 0, slot_indices), 0, WHITENULL_llll);

    if (also_lock_general_mutex)
        unlock_general_mutex((t_notation_obj *)x);    

    return out_llll;
}

void uislot_mouseup(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers) {
    
    lock_general_mutex((t_notation_obj *)x);    
    handle_mouseup_in_bach_inspector((t_notation_obj *) x, &x->r_ob.m_inspector, patcherview, pt);
    slot_handle_mouseup((t_notation_obj *)x, patcherview, pt, modifiers);
    unlock_general_mutex((t_notation_obj *)x);    

    x->r_ob.j_mouse_is_down = false;
    x->r_ob.j_isdragging = false;

    handle_change_if_there_are_free_undo_ticks((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_MOUSEDRAG_CHANGE);

    bach_set_cursor((t_object *)x, &x->r_ob.j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);

    x->r_ob.j_mousedrag_copy_ptr = NULL;
    set_mousedown((t_notation_obj *)x, NULL, k_NONE, false);
    x->r_ob.j_dragging_direction = 0;
    
    // reset the dragged flags
    x->r_ob.j_mouse_hasbeendragged = 0;
    x->r_ob.j_selection_hasbeendragged = 0;
    
    jbox_redraw((t_jbox *)x);
}

void send_domain(t_uislot *x, long outlet, t_symbol *label){
    t_llll *outlist = llll_get();
    llll_appendsym(outlist, _llllobj_sym_domain, 0, WHITENULL_llll);
    if (label)
        llll_appendsym(outlist, label, 0, WHITENULL_llll);

    lock_general_mutex((t_notation_obj *)x);
    long s = x->r_ob.active_slot_num_1based;
    if (s >= 0 && s < CONST_MAX_SLOTS) {
        if (x->r_ob.output_slot_names)
            llll_appendsym(outlist, x->r_ob.slotinfo[s].slot_name, 0, WHITENULL_llll);
        else
            llll_appendlong(outlist, s, 0, WHITENULL_llll);
        
        double start_x = rescale(x->r_ob.slot_window_zoomed_start, 0, 1, x->r_ob.slotinfo[s].slot_domain[0], x->r_ob.slotinfo[s].slot_domain[1]);
        double end_x = start_x + (x->r_ob.slotinfo[s].slot_domain[1] - x->r_ob.slotinfo[s].slot_domain[0]) / x->r_ob.slot_window_hzoom_factor;
        llll_appenddouble(outlist, start_x, 0, WHITENULL_llll);
        llll_appenddouble(outlist, end_x, 0, WHITENULL_llll);
    }
    unlock_general_mutex((t_notation_obj *)x);

    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, outlet, outlist);
    llll_free(outlist);
}


void uislot_domain(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    // change x_zoom, so that the domain is argv[0]
    long slot_num = x->r_ob.active_slot_num;
    if (slot_num >= 0 && slot_num < CONST_MAX_SLOTS && 
        (x->r_ob.slotinfo[slot_num].slot_type == k_SLOT_TYPE_FUNCTION || x->r_ob.slotinfo[slot_num].slot_type == k_SLOT_TYPE_3DFUNCTION ||
         x->r_ob.slotinfo[slot_num].slot_type == k_SLOT_TYPE_SPAT || x->r_ob.slotinfo[slot_num].slot_type == k_SLOT_TYPE_DYNFILTER)) {
            
            if (argc == 1) { // set the length
                double domain = atom_getfloat(argv);
                if (domain > 0) {
                    x->r_ob.slot_window_hzoom_factor = (x->r_ob.slotinfo[slot_num].slot_domain[1] - x->r_ob.slotinfo[slot_num].slot_domain[0]) / domain;
                    x->r_ob.slot_window_hzoom_factor = MAX(0.01, x->r_ob.slot_window_hzoom_factor);
                    if (x->r_ob.notify_also_upon_messages)
                        send_domain(x, 1, NULL);
                    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
                } else {
                    object_warn((t_object *)x, "Can't handle negative domains.");
                }
                
            } else if (argc >= 2) { // set the length
                
                double domain_start = atom_getfloat(argv);
                double domain_end = atom_getfloat(argv+1);
                double domain = domain_end - domain_start;
                
                x->r_ob.slot_window_hzoom_factor = (x->r_ob.slotinfo[slot_num].slot_domain[1] - x->r_ob.slotinfo[slot_num].slot_domain[0]) / domain;
                x->r_ob.slot_window_hzoom_factor = MAX(0.01, x->r_ob.slot_window_hzoom_factor);
                x->r_ob.slot_window_zoomed_start = domain_start / (x->r_ob.slotinfo[slot_num].slot_domain[1] - x->r_ob.slotinfo[slot_num].slot_domain[0]);
                x->r_ob.slot_window_zoomed_start = CLAMP(x->r_ob.slot_window_zoomed_start, 0., 1 - 1./x->r_ob.slot_window_hzoom_factor);
                
                if (x->r_ob.notify_also_upon_messages)
                    send_domain(x, 1, NULL);
                
                notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
            }
        }
}


void uislot_getdomain(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    // outputting domain (in ms)
    t_symbol *label = get_querying_label_from_GIMME((t_notation_obj *) x, s, argc, argv);
    send_domain(x, 1, label);
}


void uislot_getdomainpixels(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *outlist = llll_get();
    t_symbol *label = get_querying_label_from_GIMME((t_notation_obj *) x, s, argc, argv);
    
    llll_appendsym(outlist, gensym("domainpixels"), 0, WHITENULL_llll);
    if (label)
        llll_appendsym(outlist, label, 0, WHITENULL_llll);
    llll_appenddouble(outlist, x->r_ob.slot_window_active_nozoom.x, 0, WHITENULL_llll);
    llll_appenddouble(outlist, x->r_ob.slot_window_active_nozoom.x + x->r_ob.slot_window_active_nozoom.width, 0, WHITENULL_llll);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 1, outlist);
    llll_free(outlist);
}


void uislot_mousewheel(t_uislot *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc){
    char res = 0;
    
    lock_general_mutex((t_notation_obj *)x);
    res = slot_handle_mousewheel((t_notation_obj *) x, view, pt, modifiers, x_inc, y_inc);
    unlock_general_mutex((t_notation_obj *)x);
    
    if (res) {
        jbox_redraw((t_jbox *)x);
        send_domain(x, 1, NULL);
    }
}

void uislot_mousedoubleclick(t_uislot *x, t_object *patcherview, t_pt pt, long modifiers) {
    char changed;
    char clicked_slot;
    
    lock_general_mutex((t_notation_obj *)x);    
    clicked_slot = slot_handle_mousedoubleclick((t_notation_obj *) x, patcherview, pt, modifiers, &changed);

    if (clicked_slot) {
        unlock_general_mutex((t_notation_obj *)x);    
        handle_change_if_there_are_free_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
    }
}


long uislot_keyfilter(t_uislot *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter)
{
    return 1; // nothing to do now
}


void uislot_enter(t_uislot *x)    // enter is triggerd at "endeditbox time"
{
    long size    = 0;
    char *text    = NULL;
    t_object *textfield;

    textfield = jbox_get_textfield((t_object *)x);
    object_method(textfield, gensym("gettextptr"), &text, &size);

    if (x->r_ob.is_editing_type == k_TEXT_IN_SLOT) {
        t_llll *new_text_as_llll = llll_get();
        create_whole_uislot_undo_tick(x);
        llll_appendsym(new_text_as_llll, gensym(text), 0, WHITENULL_llll);
        note_change_slot_item((t_notation_obj *) x, x->r_ob.dummynote, x->r_ob.active_slot_num, 1, new_text_as_llll);
        llll_free(new_text_as_llll);
        handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
    } else if (x->r_ob.is_editing_type == k_DYNAMICS_IN_SLOT) {
        t_llll *new_text_as_llll = llll_get();
        create_whole_uislot_undo_tick(x);
        llll_appendsym(new_text_as_llll, gensym(text), 0, WHITENULL_llll);
        note_change_slot_item((t_notation_obj *) x, x->r_ob.dummynote, x->r_ob.active_slot_num, 1, new_text_as_llll);
        llll_free(new_text_as_llll);
        handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
    } else if (x->r_ob.is_editing_type == k_LLLL_IN_SLOT) {
        t_llll *my_llll = llll_from_text_buf(text, size > MAX_SYM_LENGTH);
        if (my_llll) {
            create_whole_uislot_undo_tick(x);
#ifdef BACH_NEW_LLLLSLOT_SYNTAX
            // nothing to do
#else
            llll_wrap_once(&my_llll);
#endif
            note_change_slot_item((t_notation_obj *) x, x->r_ob.dummynote, x->r_ob.active_slot_num, 1, my_llll);
            llll_free(my_llll);
            handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
        }
    } else if (x->r_ob.is_editing_type == k_NUMBER_IN_SLOT) {
        t_llll *ll = llll_from_text_buf(text, size > MAX_SYM_LENGTH);
        create_simple_notation_item_undo_tick((t_notation_obj *) x, get_activeitem_undo_item((t_notation_obj *) x), k_UNDO_MODIFICATION_CHANGE);
        notation_item_change_slotitem((t_notation_obj *) x, x->r_ob.active_slot_notationitem, x->r_ob.active_slot_num, 1, ll);
        llll_free(ll);
        handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
    }
    end_editing_textfield((t_notation_obj *) x);
}
    

void uislot_paste_slot(t_uislot *x)
{
    t_llll *clonedslot;
    
    create_whole_uislot_undo_tick(x);
    
    lock_general_mutex((t_notation_obj *)x);    
    clonedslot = llll_clone(clipboard.gathered_syntax);
    unlock_general_mutex((t_notation_obj *)x);
    if (clonedslot->l_head && hatom_gettype(&clonedslot->l_head->l_hatom) == H_LLLL && hatom_gettype(&clonedslot->l_head->l_hatom.h_w.w_llll->l_head->l_hatom) == H_LONG)
        hatom_setlong(&clonedslot->l_head->l_hatom.h_w.w_llll->l_head->l_hatom, x->r_ob.active_slot_num_1based);
    set_slots_values_to_note_from_llll((t_notation_obj *) x, x->r_ob.dummynote, clonedslot);
    llll_free(clonedslot);
    handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_SLOT_CONTENT);
}

long uislot_key(t_uislot *x, t_object *patcherview, long keycode, long modifiers, long textcharacter){
    int j;
    
    llll_format_modifiers(&modifiers, &keycode);

    if ((keycode == 'i' && modifiers == eCommandKey && !(modifiers & eShiftKey)) && is_editable((t_notation_obj *)x, k_BACH_INSPECTOR, k_ELEMENT_ACTIONS_NONE)) {
        if (x->r_ob.active_slot_num >= 0) {
            if (x->r_ob.m_inspector.inspector_patcher)
                bring_external_inspector_to_front(&x->r_ob.m_inspector);
            open_bach_inspector((t_notation_obj *)x, &x->r_ob.m_inspector, &x->r_ob.slotinfo[x->r_ob.active_slot_num], k_SLOTINFO);
        }
        jbox_redraw((t_jbox *) x);
        return 1;
    }

    if (keycode == 'z' && modifiers & eCommandKey && x->r_ob.allow_undo) {
        if (modifiers & eShiftKey)
            uislot_redo(x);
        else
            uislot_undo(x);
        return 1;
    }

    // first of all: are we pressing a key associated with some slot?
    llll_format_modifiers(&modifiers, &keycode);
    if (!(modifiers & eCommandKey) && !(modifiers & eAltKey) && !(modifiers & eControlKey) && is_editable((t_notation_obj *)x, k_SLOT, k_ELEMENT_ACTIONS_NONE)) {
        for (j=0; j<CONST_MAX_SLOTS; j++) {
            if (x->r_ob.slotinfo[j].slot_key == textcharacter) {
                open_slot_window((t_notation_obj *) x, j, (t_notation_item *)x->r_ob.dummynote);
                if (x->notify_when_open_slot_changes)
                    send_changed_open_slot_notification((t_notation_obj *)x, 1);
                return 1;
            }
        }
    }

    if (((keycode == JKEY_TAB && modifiers == eShiftKey) || keycode == JKEY_RIGHTARROW) && x->r_ob.active_slot_num_1based > 0 && x->r_ob.dummynote && is_editable((t_notation_obj *)x, k_SLOT, k_ELEMENT_ACTIONS_NONE)) {
        // shift+tab on a slot goes to the next one
        open_slot_window((t_notation_obj *) x, MIN(CONST_MAX_SLOTS - 1, x->r_ob.active_slot_num + 1), (t_notation_item *)x->r_ob.dummynote);
        if (x->notify_when_open_slot_changes)
            send_changed_open_slot_notification((t_notation_obj *)x, 1);
        return 1;
    } else if (((keycode == JKEY_TAB && modifiers == (eShiftKey | eAltKey)) || keycode == JKEY_LEFTARROW) && x->r_ob.active_slot_num > -1 && x->r_ob.active_slot_notationitem && is_editable((t_notation_obj *)x, k_SLOT, k_ELEMENT_ACTIONS_NONE)) {
        // shift+tab on a slot goes to the prev one
        open_slot_window((t_notation_obj *) x, MAX(0, x->r_ob.active_slot_num - 1), (t_notation_item *)x->r_ob.dummynote);
        if (x->notify_when_open_slot_changes)
            send_changed_open_slot_notification((t_notation_obj *)x, 1);
        return 1;
    } else if (keycode >= 48 && keycode <= 57 && is_editable((t_notation_obj *)x, k_SLOT, k_ELEMENT_ACTIONS_NONE)) {
        open_slot_window((t_notation_obj *) x, ((keycode == 48) ? 10 : keycode - 48) - 1, (t_notation_item *)x->r_ob.dummynote);
        if (x->notify_when_open_slot_changes)
            send_changed_open_slot_notification((t_notation_obj *)x, 1);
        return 1;
    } else if (keycode == JKEY_BACKSPACE || keycode == JKEY_DELETE) {
        if (is_editable((t_notation_obj *)x, k_SLOT, k_ELEMENT_ACTIONS_NONE)) {
            if (x->r_ob.selected_slot_items->l_size > 0) {
                create_whole_uislot_undo_tick(x);
                delete_all_selected_function_points((t_notation_obj *)x, x->r_ob.active_slot_num);
                handle_change_if_there_are_free_undo_ticks((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_DELETE_SLOT_CONTENT);
            }
        }
    } else if ((keycode == 'c' || keycode == 'x') && x->r_ob.allow_copy_paste) { // Cmd+C or Cmd+X
            if (modifiers & eCommandKey) {
                // copy/cut
                if (x->r_ob.active_slot_num >= 0 && x->r_ob.dummynote) { // we copy the slot
                    if (x->r_ob.selected_slot_items->l_size > 0)
                        notation_obj_copy_slot_selection((t_notation_obj *)x, &clipboard, x->r_ob.active_slot_notationitem, x->r_ob.active_slot_num, keycode == 'x');
                    else
                        notation_obj_copy_slot((t_notation_obj *)x, &clipboard, x->r_ob.active_slot_notationitem, (modifiers & eShiftKey) ? -1 : x->r_ob.active_slot_num, keycode == 'x');
                }
                return 1;
            }
            return 0;
    } else if (keycode == 'v') { // Cmd+V
            if (!(modifiers & eCommandKey))
                send_uislot_values_as_llll(x, -1, NULL);
            else if (modifiers & eCommandKey && x->r_ob.allow_copy_paste && (clipboard.object == k_NOTATION_OBJECT_ROLL || clipboard.object == k_NOTATION_OBJECT_ANY) && clipboard.gathered_syntax && clipboard.gathered_syntax->l_size > 0) {
                // paste!
                if (clipboard.type == k_SLOT) {
                    // gotta paste the (only) cached slot into the active slot (we don't check the type)
                    uislot_paste_slot(x);
                } else if (clipboard.type == k_SLOT_SELECTION) {
                    if (x->r_ob.active_slot_num >= 0) {
                        double offset = x->r_ob.j_mouse_x - x->r_ob.slot_window_active_x1;
                        t_rect activeslotwin = build_rect(x->r_ob.slot_window_active_x1, x->r_ob.slot_window_active_y1, x->r_ob.slot_window_active_x2 - x->r_ob.slot_window_active_x1, x->r_ob.slot_window_active_y2 - x->r_ob.slot_window_active_y1);
                        
                        // getting leftmost x
                        t_llllelem *elem;
                        double min = 0;
                        char def_min = 0;
                        for (elem = clipboard.gathered_syntax->l_head; elem; elem = elem->l_next) {
                            if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                                t_llll *ll = hatom_getllll(&elem->l_hatom);
                                if (ll->l_head && is_hatom_number(&ll->l_head->l_hatom)) {
                                    if (!def_min)
                                        min = hatom_getdouble(&ll->l_head->l_hatom);
                                    else
                                        min = MIN(min, hatom_getdouble(&ll->l_head->l_hatom));
                                    def_min = true;
                                }
                            }
                        }
                        if (def_min) {
                            t_pt pt;
                            function_xy_values_to_pt((t_notation_obj *)x, (t_notation_item *)x->r_ob.dummynote, min, 0, x->r_ob.active_slot_num, activeslotwin, &pt);
                            offset -= pt.x - activeslotwin.x;
                        }
                        
                        create_whole_uislot_undo_tick(x);
                        paste_slotitems((t_notation_obj *) x, (t_notation_item *)x->r_ob.dummynote, x->r_ob.active_slot_num, clipboard.gathered_syntax, activeslotwin, offset, !(modifiers & eControlKey));
                        handle_change_if_there_are_free_undo_ticks((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_SLOT_CONTENT);
                    }
                }
            }
            return 1;
    }
    

    return 0;
}
    
    
    
void uislot_focusgained(t_uislot *x, t_object *patcherview) {
    x->r_ob.j_has_focus = true;
    jbox_redraw((t_jbox *)x);
}

void uislot_focuslost(t_uislot *x, t_object *patcherview) {
    set_mousedown((t_notation_obj *)x, NULL, k_NONE, false);
    x->r_ob.j_has_focus = false;
}


void uislot_old_redo(t_uislot *x){
    if (x->r_ob.old_redo_llll[0]) {
        int i;
        set_uislot_from_llll(x, x->r_ob.old_redo_llll[0], true); // resetting roll
        
        lock_general_mutex((t_notation_obj *)x);    
        for (i = CONST_MAX_UNDO_STEPS - 1; i > 0; i--) // reshifting all undo elements
            x->r_ob.old_undo_llll[i]=x->r_ob.old_undo_llll[i-1];
        x->r_ob.old_undo_llll[0] = x->r_ob.old_redo_llll[0];
        for (i = 0; i < CONST_MAX_UNDO_STEPS - 1; i++) // reshifting all redo elements
            x->r_ob.old_redo_llll[i]=x->r_ob.old_redo_llll[i+1];
        x->r_ob.old_redo_llll[CONST_MAX_UNDO_STEPS - 1] = NULL;
        unlock_general_mutex((t_notation_obj *)x);    
    } else {
        object_warn((t_object *)x, "Can't redo!");
    }
}

void uislot_old_undo(t_uislot *x){
    if (x->r_ob.old_undo_llll[1]) {
        int i;
        set_uislot_from_llll(x, x->r_ob.old_undo_llll[1], true); // resetting roll
        
        lock_general_mutex((t_notation_obj *)x);    
        for (i = CONST_MAX_UNDO_STEPS - 1; i > 0; i--) // reshifting all redo elements
            x->r_ob.old_redo_llll[i]=x->r_ob.old_redo_llll[i-1];
        x->r_ob.old_redo_llll[0] = x->r_ob.old_undo_llll[0];
        for (i = 0; i < CONST_MAX_UNDO_STEPS - 1; i++) // reshifting all undo elements
            x->r_ob.old_undo_llll[i]=x->r_ob.old_undo_llll[i+1];
        x->r_ob.old_undo_llll[CONST_MAX_UNDO_STEPS - 1] = NULL;
        unlock_general_mutex((t_notation_obj *)x);    
    } else {
        object_warn((t_object *)x, "Can't undo!");
    }
}


void uislot_inhibit_undo(t_uislot *x, long val){
    x->r_ob.inhibited_undo = val;
}


void uislot_prune_last_undo_step(t_uislot *x){
    prune_last_undo_step((t_notation_obj *)x, true);
}


void uislot_undo(t_uislot *x){
    if (USE_NEW_UNDO_SYSTEM)
        uislot_new_undo_redo(x, k_UNDO);
    else
        uislot_old_undo(x);
}


void uislot_redo(t_uislot *x){
    if (USE_NEW_UNDO_SYSTEM)
        uislot_new_undo_redo(x, k_REDO);
    else
        uislot_old_redo(x);
}


// what = -1 -> undo, what = 1 -> redo
void uislot_new_undo_redo(t_uislot *x, char what){
    t_llll *llll = NULL;
    long undo_op = k_UNDO_OP_UNKNOWN;
    
    lock_general_mutex((t_notation_obj *)x);    
    systhread_mutex_lock(x->r_ob.c_undo_mutex);    

    if (what == k_UNDO)
        llll = x->r_ob.undo_llll;
    else if (what == k_REDO)
        llll = x->r_ob.redo_llll;
    
    if (!llll) {
    systhread_mutex_unlock(x->r_ob.c_undo_mutex);    
        unlock_general_mutex((t_notation_obj *)x);    
        return;
    }
    
    while (llll->l_head && hatom_gettype(&llll->l_head->l_hatom) != H_LONG){
        object_error((t_object *) x, what == k_UNDO ? "Wrongly placed undo tick!" : "Wrongly placed redo tick!");
        llll_destroyelem(llll->l_head);
    }

    if (!llll->l_head) {
        if (!(atom_gettype(&x->r_ob.max_undo_steps) == A_LONG && atom_getlong(&x->r_ob.max_undo_steps) == 0))
            object_warn((t_object *) x, what == k_UNDO ? "Can't undo!" : "Can't redo!");
        systhread_mutex_unlock(x->r_ob.c_undo_mutex);    
        unlock_general_mutex((t_notation_obj *)x);    
        return;
    }
    
    undo_op = hatom_getlong(&llll->l_head->l_hatom);
    if (x->r_ob.verbose_undo_redo) {
        char *buf = undo_op_to_string(undo_op); 
        object_post((t_object *) x, "%s %s", what == k_UNDO ? "Undo" : "Redo", buf);
        bach_freeptr(buf);
    }
    
    // Destroy the marker
    if (llll->l_head == x->r_ob.last_undo_marker) 
        x->r_ob.last_undo_marker = NULL;
    llll_destroyelem(llll->l_head);

    if (what == k_UNDO)
        x->r_ob.num_undo_steps--;
    else
        x->r_ob.num_redo_steps--;
    
    while (llll->l_head && hatom_gettype(&llll->l_head->l_hatom) == H_OBJ){
        t_undo_redo_information *this_information = (t_undo_redo_information *)hatom_getobj(&llll->l_head->l_hatom);
        long type = this_information->n_it_type;
        long modif_type = this_information->modification_type;
        long header_info = this_information->header_info;
        t_llll *content = this_information->n_it_content;
        t_llll *newcontent = NULL;
        t_undo_redo_information *new_information = NULL;

        if (modif_type != k_UNDO_MODIFICATION_CHANGE && modif_type != k_WHOLE_NOTATION_OBJECT && modif_type != k_HEADER_DATA) {
            object_error((t_object *) x, "Wrong undo/redo data");
            llll_destroyelem(llll->l_head);
            continue;
        }
        
        if (type == k_WHOLE_NOTATION_OBJECT){
            // need to reconstruct the whole uislot
            newcontent = get_uislot_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_ALL, NULL, false, true);
            new_information = build_undo_redo_information(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, newcontent);
            set_uislot_from_llll(x, content, false);
            
        } else if (type == k_NOTE) {
            if (modif_type == k_UNDO_MODIFICATION_CHANGE) {
                long i;
                newcontent = get_uislotnote_values_as_llll((t_notation_obj *) x, x->r_ob.dummynote, k_CONSIDER_FOR_UNDO);
                new_information = build_undo_redo_information(0, k_NOTE, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, newcontent);
                llll_flatten(content, 1, 0);
                if (content->l_head)
                    llll_destroyelem(content->l_head);
                for (i = 0; i < CONST_MAX_SLOTS; i++)
                    note_clear_slot((t_notation_obj *)x, x->r_ob.dummynote, i);
                set_slots_values_to_note_from_llll((t_notation_obj *) x, x->r_ob.dummynote, content);
            }
            
        } else if (type == k_HEADER_DATA) {
            if (modif_type == k_UNDO_MODIFICATION_CHANGE) { 
                newcontent = get_uislot_values_as_llll(x, k_CONSIDER_FOR_UNDO, header_info, NULL, false, true);
                new_information = build_undo_redo_information(0, k_HEADER_DATA, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, newcontent);
                set_uislot_from_llll(x, content, false);
            }
        } 
        
        if (new_information)
            create_undo_redo_tick((t_notation_obj *) x, -what, 1, new_information, false);
        
        llll_free(content);
        bach_freeptr(this_information);
        llll_destroyelem(llll->l_head);
    }    

    create_undo_redo_step_marker((t_notation_obj *) x, -what, 1, undo_op, false);
    systhread_mutex_unlock(x->r_ob.c_undo_mutex);    
    unlock_general_mutex((t_notation_obj *)x);    

    handle_change((t_notation_obj *)x, x->r_ob.send_undo_redo_bang ? k_CHANGED_STANDARD_SEND_BANG : k_CHANGED_STANDARD, k_UNDO_OP_UNKNOWN);
}


void uislot_copy_or_cut(t_uislot *x, t_symbol *s, long argc, t_atom *argv, char cut){
    t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    if (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slotinfo)) {
        slotinfo_copy((t_notation_obj *)x, llllelem_to_slotnum((t_notation_obj *)x, ll->l_head->l_next, true));
    } else if (ll->l_size >= 1 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slot || hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots)) {
        if (x->r_ob.active_slot_notationitem) {
            if (cut)
                create_whole_uislot_undo_tick(x);
            notation_obj_copy_slot((t_notation_obj *)x, &clipboard, x->r_ob.active_slot_notationitem, ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LONG ?
                                   hatom_getlong(&ll->l_head->l_next->l_hatom) - 1 :
                                   (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_SYM && hatom_getsym(&ll->l_head->l_next->l_hatom) == _sym_all ? -1 : x->r_ob.active_slot_num), cut);
        }
    }
    llll_free(ll);
}


void uislot_copy(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    uislot_copy_or_cut(x, s, argc, argv, false);
}

void uislot_cut(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    uislot_copy_or_cut(x, s, argc, argv, true);
}

void uislot_paste(t_uislot *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
    
    if (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slotinfo)) {
        slotinfo_paste((t_notation_obj *)x, llllelem_to_slotnum((t_notation_obj *)x, ll->l_head->l_next, true));
    } else if (ll->l_size >= 1 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slot || hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots)) {
        if (clipboard.type == k_SLOT) {
            create_whole_uislot_undo_tick(x);
            notation_obj_paste_slot((t_notation_obj *) x, &clipboard, 
                                    ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LONG ? hatom_getlong(&ll->l_head->l_next->l_hatom) - 1 :
                                    (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_SYM &&
                                     hatom_getsym(&ll->l_head->l_next->l_hatom) == _llllobj_sym_active ? x->r_ob.active_slot_num : -1));
        }
    }
    
    llll_free(ll);
}

