/*
 *  bach_jucewrapper.h
 *
 */

#ifndef _BACH_JUCEWRAPPER_H_
#define _BACH_JUCEWRAPPER_H_

#include <string.h>
#include <atomic>
#include <limits.h>
#include <float.h>

#define MAC_VERSION

#define ATOM_LONG_FMT_MODIFIER "ll"
#define ATOM_FLOAT_FMT_MODIFIER "l"        // for scanf "%lf" will read into a double



int32_t ATOMIC_INCREMENT_32_MANUAL(volatile std::atomic<std::int32_t> *ptr)
{
    return (*ptr)++;
}

int32_t ATOMIC_DECREMENT_32_MANUAL(volatile std::atomic<std::int32_t> *ptr)
{
    return (*ptr)--;
}

#define ATOMIC_INCREMENT ATOMIC_INCREMENT_32_MANUAL
#define ATOMIC_DECREMENT ATOMIC_DECREMENT_32_MANUAL
#define ATOMIC_INCREMENT_BARRIER_32 ATOMIC_INCREMENT_32_MANUAL
#define ATOMIC_DECREMENT_BARRIER_32 ATOMIC_DECREMENT_32_MANUAL

#define MAX_PATH_CHARS        2048
#define MAX_FILENAME_CHARS    512

#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef CLAMP
#define CLAMP(a, lo, hi) ( (a)>(lo)?( (a)<(hi)?(a):(hi) ):(lo) )
#endif

#ifndef CLIP_ASSIGN
#define CLIP_ASSIGN(a, lo, hi) ((a) = ( (a)>(lo)?( (a)<(hi)?(a):(hi) ):(lo) ))
#endif

#define FALSE 0
#define TRUE 1

//// gensyms: TO DO, have a symbol table
#define _sym_filename gensym("filename")
#define _sym_bang gensym("bang")
#define _sym_wind gensym("wind")
#define _sym_settext gensym("settext")
#define _sym_dsp gensym("dsp")
#define _sym_list gensym("list")
#define _sym_int gensym("int")
#define _sym_float gensym("float")
#define _sym_up gensym("up")
#define _sym_down gensym("down")
#define _sym_print gensym("print")
#define _sym_all gensym("all")
#define _sym_paste gensym("paste")
#define _sym_clear gensym("clear")
#define _sym_replace gensym("replace")
#define _sym_readonly gensym("readonly")
#define _sym_attr_modified gensym("attr_modified")
#define _sym_getname gensym("getname")
#define _sym_grid gensym("grid")
#define _sym_fontface gensym("fontface")
#define _sym_zoomfactor gensym("zoomfactor")
#define _sym_labels gensym("labels")

void common_symbols_init()
{
    
}



#define CLASS_BOX                gensym("box")
#define CLASS_NOBOX                gensym("nobox")


// key codes
// key/keyup objects fourth outlet and key message to objects uses
// the following values for keycodes
typedef enum _keycode {
    // keycode is ascii value with modifiers stripped
    // a-z keys thus report lowercase keycode regardless of shift key or capslock state
    JKEY_NONE                = -1,
    JKEY_SPACEBAR           = -2,
    JKEY_ESC                = -3,
    JKEY_RETURN             = -4,
    JKEY_ENTER                = -4,  // same as JKEY_RETURN
    JKEY_TAB                = -5,
    JKEY_DELETE             = -6,
    JKEY_BACKSPACE          = -7,
    JKEY_INSERT             = -8,
    JKEY_UPARROW            = -9,
    JKEY_DOWNARROW          = -10,
    JKEY_LEFTARROW          = -11,
    JKEY_RIGHTARROW         = -12,
    JKEY_PAGEUP             = -13,
    JKEY_PAGEDOWN           = -14,
    JKEY_HOME               = -15,
    JKEY_END                = -16,
    JKEY_F1                 = -17,
    JKEY_F2                 = -18,
    JKEY_F3                 = -19,
    JKEY_F4                 = -20,
    JKEY_F5                 = -21,
    JKEY_F6                 = -22,
    JKEY_F7                 = -23,
    JKEY_F8                 = -24,
    JKEY_F9                 = -25,
    JKEY_F10                = -26,
    JKEY_F11                = -27,
    JKEY_F12                = -28,
    JKEY_F13                = -29,
    JKEY_F14                = -30,
    JKEY_F15                = -31,
    JKEY_F16                = -32,
    JKEY_NUMPAD0            = -33,
    JKEY_NUMPAD1            = -34,
    JKEY_NUMPAD2            = -35,
    JKEY_NUMPAD3            = -36,
    JKEY_NUMPAD4            = -37,
    JKEY_NUMPAD5            = -38,
    JKEY_NUMPAD6            = -39,
    JKEY_NUMPAD7            = -40,
    JKEY_NUMPAD8            = -41,
    JKEY_NUMPAD9            = -42,
    JKEY_NUMPADADD          = -43,
    JKEY_NUMPADSUBTRACT     = -44,
    JKEY_NUMPADMULTIPLY     = -45,
    JKEY_NUMPADDIVIDE       = -46,
    JKEY_NUMPADSEPARATOR    = -47,
    JKEY_NUMPADDECIMALPOINT = -48,
    JKEY_NUMPADEQUALS       = -49,
    JKEY_NUMPADDELETE       = -50,
    JKEY_PLAYPAUSE            = -51,
    JKEY_STOP                = -52,
    JKEY_NEXTTRACK            = -53,
    JKEY_PREVTRACK            = -54,
    JKEY_HELP                = -55
} t_keycode;


typedef long t_atom_long;
typedef double t_atom_float;
typedef long t_int16;
typedef unsigned long t_uint16;
typedef bool t_bool;
typedef long t_max_err;
typedef uint32_t        unicodeChar;
//typedef unsigned short unicodeChar;
typedef __uint32_t t_uint32;
typedef t_uint32 t_fourcc;
typedef unsigned long long t_ptr_uint;
typedef t_ptr_uint t_ptr_size;
typedef long t_ptr_int;

typedef void *(*method)(void *, ...);
typedef void *t_systhread;
typedef void *t_systhread_mutex;

/**
 Flags that determine how functions convert atoms into text (C-strings).
 @ingroup atom
 */
typedef enum{
    OBEX_UTIL_ATOM_GETTEXT_DEFAULT =            0x00000000,     ///< default translation rules for getting text from atoms
    OBEX_UTIL_ATOM_GETTEXT_TRUNCATE_ZEROS =        0x00000001,  ///< eliminate redundant zeros for floating point numbers (default used)
    OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE    =        0x00000002, ///< don't introduce quotes around symbols with spaces
    OBEX_UTIL_ATOM_GETTEXT_SYM_FORCE_QUOTE =    0x00000004,     ///< always introduce quotes around symbols (useful for JSON)
    OBEX_UTIL_ATOM_GETTEXT_COMMA_DELIM =        0x00000008,     ///< separate atoms with commas (useful for JSON)
    OBEX_UTIL_ATOM_GETTEXT_FORCE_ZEROS =        0x00000010,     ///< always print the zeros
    OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES =            0x00000020,  ///< print more decimal places
    OBEX_UTIL_ATOM_GETTEXT_NUM_LO_RES =            0x00000040   ///< // print fewer decimal places (HI_RES will win though)
} e_atom_gettext_flags;

/** Standard values returned by function calls with a return type of #t_max_err
 @ingroup misc */
typedef enum {
    MAX_ERR_NONE =            0,    ///< No error
    MAX_ERR_GENERIC =        -1,    ///< Generic error
    MAX_ERR_INVALID_PTR =    -2,    ///< Invalid Pointer
    MAX_ERR_DUPLICATE =        -3,    ///< Duplicate
    MAX_ERR_OUT_OF_MEM =    -4    ///< Out of memory
} e_max_errorcodes;


typedef volatile std::atomic<std::int32_t> t_int32_atomic;
typedef volatile __int64_t t_int64_atomic;
typedef volatile unsigned long t_uint32_atomic;
typedef volatile __uint64_t t_uint64_atomic;



// Core structs

/**
 Coordinates for specifying a rectangular region.
 @ingroup     datatypes
 @see        t_pt
 @see        t_size        */
typedef struct _rect
{
    double x;                ///< The horizontal origin
    double y;                ///< The vertical origin
    double width;            ///< The width
    double height;            ///< The height
} t_rect;


/**
 Coordinates for specifying a point.
 @ingroup     datatypes
 @see        t_rect
 @see        t_size        */
typedef struct _pt
{
    double x;                ///< The horizontal coordinate
    double y;                ///< The vertical coordinate
} t_pt;


/**
 Coordinates for specifying the size of a region.
 @ingroup     datatypes
 @see        t_rect
 @see        t_pt        */
typedef struct _size
{
    double width;            ///< The width
    double height;            ///< The height
} t_size;


/**    A color composed of red, green, and blue components.
 Typically such a color is assumed to be completely opaque (with no transparency).
 @ingroup    color
 @see        t_jrgba        */
typedef struct _jrgb {
    double red;                ///< Red component in the range [0.0, 1.0]
    double green;            ///< Green component in the range [0.0, 1.0]
    double blue;            ///< Blue component in the range [0.0, 1.0]
} t_jrgb;


/**    A color composed of red, green, blue, and alpha components.
 @ingroup color            */
typedef struct _jrgba {
    double red;                ///< Red component in the range [0.0, 1.0]
    double green;            ///< Green component in the range [0.0, 1.0]
    double blue;
    double alpha;            ///< Alpha (transparency) component in the range [0.0, 1.0]
} t_jrgba;






/** The structure for the head of any object which wants to have inlets or outlets,
 or support attributes.
 @ingroup obj
 */
typedef struct object
{
    void *o_messlist;    ///<  list of messages and methods. The -1 entry of the message list of an object contains a pointer to its #t_class entry.
    // (also used as freelist link)

    void *o_inlet;            ///<  list of inlets
    void *o_outlet;        ///<  list of outlets
} t_object;



typedef enum {
    A_NOTHING = 0,    ///< no type, thus no atom
    A_LONG,            ///< long integer
    A_FLOAT,        ///< 32-bit float
    A_SYM,            ///< t_symbol pointer
    A_OBJ,            ///< t_object pointer (for argtype lists; passes the value of sym)
    A_DEFLONG,        ///< long but defaults to zero
    A_DEFFLOAT,        ///< float, but defaults to zero
    A_DEFSYM,        ///< symbol, defaults to ""
    A_GIMME,        ///< request that args be passed as an array, the routine will check the types itself.
    A_CANT,            ///< cannot typecheck args
    A_SEMI,            ///< semicolon
    A_COMMA,        ///< comma
    A_DOLLAR,        ///< dollar
    A_DOLLSYM,        ///< dollar
    A_GIMMEBACK,    ///< request that args be passed as an array, the routine will check the types itself. can return atom value in final atom ptr arg. function returns long error code 0 = no err. see gimmeback_meth typedef
    
    A_DEFER    =        0x41,    ///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred.
    A_USURP =        0x42,    ///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred and multiple calls within one servicing of the queue are filtered down to one call.
    A_DEFER_LOW =    0x43,    ///< A special signature for declaring methods. This is like A_GIMME, but the call is deferref to the back of the queue.
    A_USURP_LOW =    0x44    ///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred to the back of the queue and multiple calls within one servicing of the queue are filtered down to one call.
} e_max_atomtypes;



/** Union for packing any of the datum defined in #e_max_atomtypes.
 @ingroup atom
 */
union word
{
    t_atom_long w_long;            ///< long integer
    t_atom_float w_float;    ///< 32-bit float
    struct symbol *w_sym;    ///< pointer to a symbol in the Max symbol table
    struct object *w_obj;    ///< pointer to a #t_object or other generic pointer
};


/** An atom is a typed datum.
 @ingroup atom
 */
typedef struct atom        // and an atom which is a typed datum
{
    short            a_type;
    union word        a_w;
} t_atom;



typedef struct symbol
{
    char *s_name;            ///< name: a c-string
    t_object *s_thing;    ///< possible binding to a t_object
} t_symbol;




union word64
{
    long w_long;
    double w_float;
    struct symbol *w_sym;
    struct object *w_obj;
};

typedef struct atom64
{
    short a_type;
    union word64 a_w;
} t_atom64;







/** A linklist element. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup linklist
 @see t_linklist
 */
typedef struct _llelem
{
    t_object         *thing;
    struct _llelem    *next;
    struct _llelem    *prev;
    long flags;
    long marked;
} t_llelem;


/** The linklist object. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup linklist
 @see t_llelem
 */
typedef struct _linklist
{
    t_object     ob;
    long        count;
    t_llelem    *head;
    t_llelem    *tail;
    long        readonly;
    void         *lock;
    t_llelem    *cache;
    long        flags;
    t_llelem    *pending;        // used to help prevent accessing deleted elements during complex list traversal (methodall, etc)
    t_uint32_atomic iterating;
    long        sweep;
} t_linklist;



/** The hashtab object. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup hashtab
 @see t_hashtab
 */
typedef struct _hashtab
{
    t_object                ob;
    long                    slotcount;
    t_linklist                **slots;
    long                    readonly;
    long                    flags;
    void                    *reserved;
} t_hashtab;



/** The atomarray object. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup atomarray
 */
typedef struct _atomarray
{
    t_object    ob;
    long        ac;
    t_atom        *av;
    long        flags;
#ifndef C74_X64
    t_atom64    *av64;
#endif
} t_atomarray;




/** The dictionary object. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup dictionary
 @see t_dictionary
 */
typedef struct _dictionary
{
    t_object        d_obj;
    t_hashtab        *d_hashtab;
    t_linklist        *d_linklist;
} t_dictionary;



typedef t_object t_pxobject; // not right, but we don't need this


/** The t_jbox struct provides the header for a Max user-interface object.
 This struct should be considered opaque and is subject to change without notice.
 Do not access it's members directly any code.
 
 @ingroup patcher
 */
typedef struct _jbox
{
    t_object     b_ob;
    void         *obex;
    t_object    *b_patcher;
    t_rect        b_patching_rect;
    t_rect        b_presentation_rect;
    t_symbol    *b_name;
    t_symbol    *b_id;            // immutable box ID
    t_object    *b_firstin;        // the object, could be the box
    t_object    *b_textfield;    // optional text field.
    t_symbol    *b_fontname;
    double        b_fontsize;
    char*        b_hint;
    t_jrgba        b_color;
    double        b_unused;        // we can chop this or make it do something different
    void        *b_binbuf;      // really an atombuf  :)
    long        b_temp;
    char        b_spooled;
    char        b_hidden;
    char        b_hilitable;
    char        b_background;
    char        b_ignoreclick;
    char        b_bogus;
    char        b_drawfirstin;
    char        b_outline;
    char        b_growy;
    char        b_growboth;
    char        b_nogrow;
    char        b_drawinlast;
    char        b_paintoverchildren;
    char        b_mousedragdelta;        // hide mouse during drag, and send mousedragdelta instead of mousedrag for infinite scrolling
    char        b_presentation;
    char        b_drawiolocked;
    char        b_dragactive;
    char        b_drawbackground;
    char        b_hinttrack;
    char        b_fontface;
    char        *b_annotation;
    char        b_opaque;
    char        b_useimagebuffer;
    char        b_noinspectfirstin;
    char        b_editactive;            // editing via inspector
    t_symbol    *b_prototypename;
    char        b_commasupport;
    char        b_reserved1;            // this is actually used and should be renamed!
    char        b_textjustification;
    char        b_reserved3;
    void        *b_ptemp;
} t_jbox;


typedef t_jbox t_pxjbox; // wrong, but we don't need this


typedef short t_getbytes_size;

#define MSG_MAXARG 7
typedef struct messlist
{
    struct symbol *m_sym;        ///< Name of the message
    method m_fun;                ///< Method associated with the message
    char m_type[MSG_MAXARG + 1];    ///< Argument type information
} t_messlist;

/**
 The data structure for a Max class. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup class
 */
typedef struct maxclass
{
    struct symbol *c_sym;            ///< symbol giving name of class
    struct object **c_freelist;        // linked list of free ones
    method c_freefun;                // function to call when freeing
    t_getbytes_size c_size;            // size of an instance
    char c_tiny;                    // flag indicating tiny header
    char c_noinlet;                    // flag indicating no first inlet for patcher
    struct symbol *c_filename;        ///< name of file associated with this class
    t_messlist *c_newmess;            // constructor method/type information
    method c_menufun;                // function to call when creating from object pallette (default constructor)
    long c_flags;                    // class flags used to determine context in which class may be used
    long c_messcount;                // size of messlist array
    t_messlist *c_messlist;            // messlist arrray
    void *c_attributes;                // t_hashtab object
    void *c_extra;                    // t_hashtab object
    long c_obexoffset;                // if non zero, object struct contains obex pointer at specified byte offset
    void *c_methods;                // methods t_hashtab object
    method c_attr_get;                // if not set, NULL, if not present CLASS_NO_METHOD
    method c_attr_gettarget;        // if not set, NULL, if not present CLASS_NO_METHOD
    method c_attr_getnames;            // if not set, NULL, if not present CLASS_NO_METHOD
    struct maxclass *c_superclass;    // a superclass point if this is a derived class
} t_class;


/** A hashtab entry. This struct is provided for debugging convenience,
 but should be considered opaque and is subject to change without notice.
 
 @ingroup hashtab
 @see t_hashtab
 */
typedef struct _hashtab_entry
{
    t_object                ob;
    t_symbol                *key;
    t_object                *value;
    long                    flags;
    struct _hashtab            *parent;
} t_hashtab_entry;







char *sysmem_newptr(size_t size)
{
    return (char *)malloc(size);
}

char *sysmem_newptrclear(size_t size)
{
    char *m = (char *)malloc(size);
    memset(m, size, 0);
    return m;
}

char *sysmem_resizeptr(void *ptr, long newsize)
{
    return (char *)realloc(ptr, newsize);
}

void sysmem_copyptr(const void *src, void *dst, long bytes)
{
    memcpy(dst, src, bytes);
}


void sysmem_freeptr(void *ptr)
{
    free(ptr);
}

long sysmem_ptrsize(void *ptr)
{
    return sizeof(ptr); // I THINK THIS IS WRONG
}



struct t_jgraphics {
    
};

struct t_jfont {
    
};

struct t_jsurface {
    
};

struct t_jpopupmenu {
    
};

typedef void* t_filehandle;
/*struct t_filehandle {
    
};*/

void post(const char *format, ...)
{
    // NOTHING TO DO
}

void cpost(const char *format, ...)
{
    // NOTHING TO DO
}

void postatom(t_atom *ap)
{
    ;
}


void error(const char *format, ...)
{
    // NOTHING TO DO
}

void object_error(t_object *x, const char *format, ...)
{
    // NOTHING TO DO
}

void object_post(t_object *x, const char *format, ...)
{
    // NOTHING TO DO
}

void object_bug(t_object *x, const char *format, ...)
{
    // NOTHING TO DO
}

void object_warn(t_object *x, const char *format, ...)
{
    // NOTHING TO DO
}


t_symbol *gensym(const char *str)
{
    return NULL; // TO DO: make it proper
}

void *defer(void *ob,method fn,t_symbol *sym,short argc,t_atom *argv)
{
    // TO DO
    return NULL;
}

void *defer_low(void *ob,method fn,t_symbol *sym,short argc,t_atom *argv)
{
    // TO DO
    return NULL;
}




/** Modes used by sysfile_setpos()
 @ingroup files */
typedef enum {
    SYSFILE_ATMARK = 0,            ///< ?
    SYSFILE_FROMSTART = 1,        ///< Calculate the file position from the start of the file.
    SYSFILE_FROMLEOF = 2,        ///< Calculate the file position from the logical end of the file.
    SYSFILE_FROMMARK = 3        ///< Calculate the file position from the current file position.
} t_sysfile_pos_mode;


t_max_err sysfile_read( t_filehandle f, t_ptr_size *count, void *bufptr)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err sysfile_write(t_filehandle f, t_ptr_size *count, const void *bufptr)
{
    return MAX_ERR_GENERIC;
}

t_max_err sysfile_setpos(t_filehandle f, t_sysfile_pos_mode mode, t_ptr_int offset)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err sysfile_close(t_filehandle f)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err sysfile_geteof(t_filehandle f, t_ptr_size *logeof)
{
    // TO DO
    return MAX_ERR_GENERIC;
}
t_max_err sysfile_seteof(t_filehandle f, t_ptr_size logeof)
{
    return MAX_ERR_GENERIC;
}


// hashtable


/** Flags used in linklist and hashtab objects
 @ingroup datastore */
typedef enum {
    OBJ_FLAG_OBJ =             0x00000000,    ///< free using object_free()
    OBJ_FLAG_REF =            0x00000001,    ///< don't free
    OBJ_FLAG_DATA =            0x00000002,    ///< don't free data or call method
    OBJ_FLAG_MEMORY =        0x00000004,    ///< don't call method, and when freeing use sysmem_freeptr() instead of freeobject
    OBJ_FLAG_SILENT =        0x00000100,    ///< don't notify when modified
    OBJ_FLAG_INHERITABLE =    0x00000200,  ///< obexprototype entry will be inherited by subpatchers and abstractions
    OBJ_FLAG_ITERATING =    0x00001000,    ///< used by linklist to signal when is inside iteration
    OBJ_FLAG_DEBUG =        0x40000000    ///< context-dependent flag, used internally for linklist debug code
} e_max_datastore_flags;

t_hashtab *hashtab_new(long slotcount)
{
    // TO DO
    return NULL;
}

void hashtab_flags(t_hashtab *x, long flags)
{
    // TO DO
}

t_max_err hashtab_lookup(t_hashtab *x, t_symbol *key, t_object **val)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err hashtab_store(t_hashtab *x, t_symbol *key, t_object *val)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err hashtab_funall(t_hashtab *x, method fun, void *arg)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err hashtab_clear(t_hashtab *x)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err hashtab_delete(t_hashtab *x, t_symbol *key)
{
    
}




char *strncpy_zero(char *dst, const char* src, long size)
{
    strncpy(dst, src, size-1);
    dst[size-1] = 0;
    return dst;
}

char *strncat_zero(char *dst, const char* src, long size)
{
    long l = strlen(dst);
    strncpy_zero(dst+l, src, size-l);
    return dst;
}


int snprintf_zero(char *buffer, size_t count, const char *format, ...)
{
    // TO DO!!!!
    return 0;
}

long atom_gettype(const t_atom *a)
{
    return a->a_type;
}

t_symbol *atom_getsym(const t_atom *a)
{
    return a->a_w.w_sym;
}

t_object *atom_getobj(const t_atom *a)
{
    return a->a_w.w_obj;
}

long atom_getlong(const t_atom *a)
{
    return a->a_w.w_long;
}


long atom_getfloat(const t_atom *a)
{
    return a->a_w.w_float;
}


t_max_err atom_setobj(t_atom *a, void *b)
{
    a->a_type = A_OBJ;
    a->a_w.w_obj = (t_object *)b;
    return MAX_ERR_NONE;
}

t_max_err atom_setsym(t_atom *a, t_symbol *s)
{
    a->a_type = A_SYM;
    a->a_w.w_sym = s;
    return MAX_ERR_NONE;
}

t_max_err atom_setlong(t_atom *a, long l)
{
    a->a_type = A_LONG;
    a->a_w.w_long = l;
    return MAX_ERR_NONE;
}

t_max_err atom_setfloat(t_atom *a, double d)
{
    a->a_type = A_FLOAT;
    a->a_w.w_float = d;
    return MAX_ERR_NONE;
}

t_max_err atom_setparse(long *ac, t_atom **av, const char *parsestr)
{
    return MAX_ERR_GENERIC;
}

t_max_err atom_gettext(long ac, t_atom *av, long *textsize, char **text, long flags)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_atomarray *atomarray_new(long ac, t_atom *av)
{
    // TO DO;
    return NULL;
}
t_max_err atomarray_getatoms(t_atomarray *x, long *ac, t_atom **av)
{
    // TO DO;
    return MAX_ERR_GENERIC;
}

short readatom(char *outstr, char **text, long *n, long e, t_atom *ap)
{
    return 0;
}


t_uint32 systime_ms(void)
{
    // TO DO
    return 0;
}

void *object_method(void *x, t_symbol *s, ...)
{
    // TO DO
    return NULL;
}

t_max_err atom_alloc(long *ac, t_atom **av, char *alloc)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

char object_attr_getchar(void *x, t_symbol *s)
{
    return 0;
}
t_max_err object_attr_setchar(void *x, t_symbol *s, char c)
{
    return MAX_ERR_GENERIC;
}

t_object* object_attr_getobj(void *x, t_symbol *s)
{
    return NULL;
}

t_max_err object_attr_setobj(void *x, t_symbol *s, t_object *o)
{
    return MAX_ERR_GENERIC;
}

t_max_err object_attr_setsym(void *x, t_symbol *s, t_symbol *c)
{
    return MAX_ERR_GENERIC;
}

t_max_err object_attr_setlong(void *x, t_symbol *s, t_atom_long c)
{
    return MAX_ERR_GENERIC;
}



#ifndef calcoffset
#define calcoffset(x,y) ((t_ptr_int)(&(((x *)0L)->y)))
#endif

short wind_advise_explain(t_object *w, char *note, char *explanation, char *b1, char *b2, char *b3)
{
    return 0;
}

void *object_new(t_symbol *name_space, t_symbol *classname, ...)
{
    // TO DO
    return NULL;
}

void *newinstance(t_symbol *s, short argc, t_atom *argv)
{
    return NULL;
}


void *object_new_typed(t_symbol *name_space, t_symbol *classname, long ac, t_atom *av)
{
    return NULL;
}




short open_dialog(char *name, short *volptr, t_fourcc *typeptr, t_fourcc *types, short ntypes)
{
    return 0;
}


short locatefile_extended(char *name, short *outvol, t_fourcc *outtype, t_fourcc *filetypelist, short numtypes)
{
    return 0;
}

/**
 Permissions or mode with which to open a file.
 @ingroup files
 */
typedef enum {
    PATH_READ_PERM = 1,        ///< Read mode
    PATH_WRITE_PERM = 2,    ///< Write mode
    PATH_RW_PERM = 3        ///< Read/Write mode
} e_max_openfile_permissions;
#define READ_PERM        PATH_READ_PERM        // for backwards compatibility
#define WRITE_PERM        PATH_WRITE_PERM        // for backwards compatibility
#define RW_PERM            PATH_RW_PERM        // for backwards compatibility


short saveasdialog_extended(char *name, short *vol, t_fourcc *type, t_fourcc *typelist, short numtypes)
{
    return 0;
}

short path_getdefault(void)
{
    return 0;
}

short path_createsysfile(char *name, short path, t_fourcc type, t_filehandle *ref)
{
    return 0;
}

short path_opensysfile(const char *name, short path, t_filehandle *ref, short perm)
{
    return 0;
}



// HANDLES! TO DO
typedef char **t_handle;            ///< a handle (address of a pointer)  @ingroup misc
t_handle sysmem_newhandle(long size)
{
    return NULL;
}

t_handle sysmem_newhandleclear(unsigned long size)
{
    return NULL;
}


long sysmem_ptrandhand(void *p, t_handle h, long size)
{
    return 0;
}

void sysmem_freehandle(t_handle handle)
{
    ;
}


/** Flags used reading and writing text files.
 @ingroup files */
typedef enum {
    TEXT_LB_NATIVE =            0x00000001L,    ///< Use the linebreak format native to the current platform.
    TEXT_LB_MAC =                0x00000002L,    ///< Use Macintosh line breaks
    TEXT_LB_PC =                0x00000004L,    ///< Use Windows line breaks
    TEXT_LB_UNIX =                0x00000008L,    ///< Use Unix line breaks
    TEXT_LB_MASK = 0x0000000FL,                // can use to mask out non-LB related flags
    TEXT_ENCODING_USE_FILE =    0x00000100L,    ///< If this flag is not set then the encoding is forced to UTF8
    TEXT_NULL_TERMINATE    =        0x00000200L        ///< Terminate memory returned from sysfile_readtextfile() with a NULL character
} t_sysfile_text_flags;





t_max_err class_addmethod(t_class *c, const method m, const char *name, ...)
{
    return MAX_ERR_GENERIC;
}

void class_setname(char *obname, char *filename)
{
    ;
}


t_max_err sysfile_writetextfile(t_filehandle f, t_handle htext, t_sysfile_text_flags flags)
{
    return MAX_ERR_GENERIC;
}




#define CLASS_ATTR_ATOM_LONG(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_LABEL(c,attrname,flags,labelstr) ((void)0)
#define CLASS_ATTR_FILTER_MIN(c,attrname,minval) ((void)0)
#define CLASS_ATTR_FILTER_CLIP(c,attrname,minval,maxval) ((void)0)
#define CLASS_ATTR_STYLE_LABEL(c,attrname,flags,stylestr,labelstr) ((void)0)
#define CLASS_ATTR_SAVE(c,attrname,flags) ((void)0)
#define CLASS_ATTR_STYLE(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_CHAR_VARSIZE(c,attrname,flags,structname,structmember,sizemember,maxsize) ((void)0)
#define CLASS_ATTR_ACCESSORS(c,attrname,getter,setter) ((void)0)
#define CLASS_ATTR_LLLL(c,attrname,flags,structname,structmember,getter,setter) ((void)0)
#define CLASS_ATTR_DEFAULT(c,attrname,flags,parsestr) ((void)0)
#define CLASS_STICKY_ATTR(c,name,flags,parsestr) ((void)0)
#define CLASS_STICKY_ATTR_CLEAR(c,name) ((void)0)
#define CLASS_ATTR_BASIC(c, name, flags) ((void)0)
#define CLASS_ATTR_PAINT(c, name, flags) ((void)0)
#define CLASS_ATTR_ATOM(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_LONG(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_DOUBLE(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_CHAR(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_SYM(c,attrname,flags,structname,structmember) ((void)0)
#define CLASS_ATTR_DEFAULT_SAVE_PAINT(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_DEFAULT_SAVE(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_CATEGORY(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_ENUMINDEX(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_ALIAS(c,attrname,aliasname) ((void)0)
#define CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,attrname,flags,parsestr) ((void)0)
#define CLASS_ATTR_NOTATIONOBJ_SYMPTR(c,attrname,flags,structmember,maxcount,setter) ((void)0)
#define CLASS_ATTR_NOTATIONOBJ_CHARPTR(c,attrname,flags,structmember,maxcount,setter) ((void)0)
#define CLASS_ATTR_NOTATIONOBJ_ATOMPTR(c,attrname,flags,structmember,maxcount,setter) ((void)0)
#define CLASS_ATTR_NOTATIONOBJ_LONGPTR(c,attrname,flags,structmember,maxcount,setter) ((void)0)
#define CLASS_ATTR_NOTATIONOBJ_DBLPTR(c,attrname,flags,structmember,maxcount,setter) ((void)0)
#define CLASS_ATTR_INVISIBLE(c,attrname,flags) ((void)0)


t_max_err object_attr_setdisabled(t_object *o, t_symbol *attrname, long way)
{
    return MAX_ERR_GENERIC;
}


/** Attribute flags
 @ingroup attr
 
 @remark     To create a readonly attribute, for example,
 you should pass ATTR_SET_OPAQUE or ATTR_SET_OPAQUE_USER as a flag when you create your attribute.
 */
typedef enum {
    ATTR_FLAGS_NONE =        0x0000000,    ///< No flags
    ATTR_GET_OPAQUE =        0x00000001,    ///< The attribute cannot be queried by either max message when used inside of a CLASS_BOX object, nor from C code.
    ATTR_SET_OPAQUE =        0x00000002, ///< The attribute cannot be set by either max message when used inside of a CLASS_BOX object, nor from C code.
    ATTR_GET_OPAQUE_USER =    0x00000100, ///< The attribute cannot be queried by max message when used inside of a CLASS_BOX object, but <em>can</em> be queried from C code.
    ATTR_SET_OPAQUE_USER =    0x00000200, ///< The attribute cannot be set by max message when used inside of a CLASS_BOX object, but <em>can</em> be set from C code.
    ATTR_GET_DEFER =        0x00010000,    // Placeholder for potential future functionality: Any attribute queries will be called through a defer().
    ATTR_GET_USURP =        0x00020000,    // Placeholder for potential future functionality: Any calls to query the attribute will be called through the equivalent of a defer(), repeated calls will be ignored until the getter is actually run.
    ATTR_GET_DEFER_LOW =    0x00040000, // Placeholder for potential future functionality: Any attribute queries will be called through a defer_low().
    ATTR_GET_USURP_LOW =    0x00080000, // Placeholder for potential future functionality: Any calls to query the attribute will be called through the equivalent of a defer_low(), repeated calls will be ignored until the getter is actually run.
    ATTR_SET_DEFER =        0x01000000, // Placeholder for potential future functionality: The attribute setter will be called through a defer().
    ATTR_SET_USURP =        0x02000000,    // Placeholder for potential future functionality: Any calls to set the attribute will be called through the equivalent of a defer_low(), repeated calls will be ignored until the setter is actually run.
    ATTR_SET_DEFER_LOW =    0x04000000, // Placeholder for potential future functionality: The attribute setter will be called through a defer_low()
    ATTR_SET_USURP_LOW =    0x08000000,    // Placeholder for potential future functionality: Any calls to set the attribute will be called through the equivalent of a defer_low(), repeated calls will be ignored until the setter is actually run.
    ATTR_IS_JBOXATTR =        0x10000000,  // a common jbox attr
    ATTR_DIRTY =            0x20000000  // attr has been changed from its default value
} e_max_attrflags;

/** Class flags. If not box or polyglot, class is only accessible in C via known interface
 @ingroup class
 */
typedef enum {
    CLASS_FLAG_BOX =                    0x00000001L,    ///< for use in a patcher
    CLASS_FLAG_POLYGLOT =                0x00000002L,    ///< for use by any text language (c/js/java/etc)
    CLASS_FLAG_NEWDICTIONARY =            0x00000004L,    ///< dictionary based constructor
    CLASS_FLAG_REGISTERED =                0x00000008L,    ///< for backward compatible messlist implementation (once reg'd can't grow)
    CLASS_FLAG_UIOBJECT =                0x00000010L,    ///< for objects that don't go inside a newobj box.
    CLASS_FLAG_ALIAS =                    0x00000020L,    ///< for classes that are just copies of some other class (i.e. del is a copy of delay)
    CLASS_FLAG_DO_NOT_PARSE_ATTR_ARGS =    0x00000080L,     ///< override dictionary based constructor attr arg parsing
    CLASS_FLAG_DO_NOT_ZERO =            0x00000100L,     ///< don't zero the object struct on construction (for efficiency)
    CLASS_FLAG_NOATTRIBUTES =            0x00010000L,    ///< for efficiency
    CLASS_FLAG_OWNATTRIBUTES =            0x00020000L,    ///< for classes which support a custom attr interface (e.g. jitter)
    CLASS_FLAG_PARAMETER =                0x00040000L,    ///< for classes which have a parameter
    CLASS_FLAG_RETYPEABLE =                0x00080000L,    ///< object box can be retyped without recreating the object
    CLASS_FLAG_OBJECT_METHOD =            0x00100000L        ///< objects of this class may have object specific methods
} e_max_class_flags;


// jbox flags
// flags passed to box_new

// The following flags affect how the boxes are drawn
#define JBOX_DRAWFIRSTIN            (1<<0)            ///< draw first inlet                                                @ingroup jbox
#define JBOX_NODRAWBOX              (1<<1)            ///< don't draw the frame                                              @ingroup jbox
#define JBOX_DRAWINLAST             (1<<2)            ///< draw inlets after update method                                 @ingroup jbox

// JBOX_TRANSPARENT is unused -- box is always transparent by default
#define JBOX_TRANSPARENT            (1<<3)            ///< don't make transparent unless you need it (for efficiency)        @ingroup jbox

// Box growing: nogrow is clear -- box is not sizable.
// Default (none of following three flags) means box width is only sizable.
// JBOX_GROWY means that X and Y are sizable and the aspect ratio is fixed (or maybe it has to be square, like dial?).
// JBOX_GROWBOTH means that X and Y are independently sizable.
#define JBOX_NOGROW                 (1<<4)            ///< don't even draw grow thingie                 @ingroup jbox
#define JBOX_GROWY                  (1<<5)            ///< can grow in y direction by dragging        @ingroup jbox
#define JBOX_GROWBOTH               (1<<6)            ///< can grow independently in both x and y     @ingroup jbox

// Box interaction
#define JBOX_IGNORELOCKCLICK        (1<<7)            ///< box should ignore a click if patcher is locked     @ingroup jbox
#define JBOX_HILITE                 (1<<8)            ///< flag passed to jbox_new() to tell max that the UI object can receive the focus when clicked on -- may be replaced by JBOX_FOCUS in the future         @ingroup jbox
#define JBOX_BACKGROUND             (1<<9)            ///< immediately set box into the background            @ingroup jbox
#define JBOX_NOFLOATINSPECTOR       (1<<10)            ///< no floating inspector window                        @ingroup jbox

// textfield: give this flag for automatic textfield support
#define JBOX_TEXTFIELD              (1<<11)            ///< save/load text from textfield, unless JBOX_BINBUF flag is set                @ingroup jbox
#define JBOX_FIXWIDTH               (1<<19)            ///< give the box a textfield based fix-width (bfixwidth) method                @ingroup jbox
#define JBOX_FONTATTR               (1<<18)            ///< if you want font related attribute you must add this to jbox_initclass()    @ingroup jbox
#define JBOX_TEXTJUSTIFICATIONATTR  (1<<21)         ///< give your object a textjustification attr to control textfield             @ingroup jbox
#define JBOX_BINBUF                 (1<<14)            ///< save/load text from b_binbuf                                                @ingroup jbox

#define JBOX_MOUSEDRAGDELTA         (1<<12)            ///< hides mouse cursor in drag and sends mousedragdelta instead of mousedrag (for infinite scrolling like number)    @ingroup jbox

#define JBOX_COLOR                  (1<<13)            ///< support the "color" method for color customization                                                @ingroup jbox
#define JBOX_DRAWIOLOCKED           (1<<15)            ///< draw inlets and outlets when locked (default is not to draw them)                                @ingroup jbox
#define JBOX_DRAWBACKGROUND         (1<<16)            ///< set to have box bg filled in for you based on getdrawparams method or brgba attribute            @ingroup jbox
#define JBOX_NOINSPECTFIRSTIN       (1<<17)            ///< flag for objects such as bpatcher that have a different b_firstin,
///< but the attrs of the b_firstin should not be shown in the inspector                            @ingroup jbox

// JBOX_DEFAULTNAMES is unused -- box is attached automatically if needed
// Since JBOX_DEFAULTNAMES was unused and used a conflicting flag bit with JBOX_FONTATTR it is being removed.
// Just remove from your code if you have a compile error about JBOX_DEFAULTNAMES missing.
//#define JBOX_DEFAULTNAMES            (1<<18)            ///< flag instructing jbox_new to attach object to the defaults object for live defaults updating    @ingroup jbox

#define JBOX_FOCUS                    (1<<20)            ///< more advanced focus support (passed to jbox_initclass() to add "nextfocus" and "prevfocus" attributes to the UI object).  Not implemented as of 2009-05-11   @ingroup jbox
#define JBOX_BOXVIEW                (1<<23)            ///< enable jboxview methods   @ingroup jbox

#define JBOX_LEGACYCOLOR            (1<<22)            ///< add undocumented color N message to objects from Max 4 that used it   @ingroup jbox
#define JBOX_COPYLEGACYDEFAULT        (1<<24)            ///< if there is a legacy default, copy it instead of the regular default   @ingroup jbox
#define JBOX_NOLEGACYDEFAULT        (1<<25)            ///< if there is a legacy default, don't copy any default   @ingroup jbox


t_class *object_class(void *x)
{
    return NULL;
}

void jbox_initclass(t_class *c, long flags)
{
    ;
}

#define CLASS_METHOD_ATTR_PARSE(c,methodname,attrname,type,flags,parsestring) ((void)0)

long attr_args_offset(short ac, t_atom *av)
{
    return 0;
}

void attr_args_process(void *x, short ac, t_atom *av)
{
    ;
}



//// DICTIONARY STUFF

t_dictionary* dictionary_new(void)
{
    return NULL;
}

t_max_err dictionary_getdictionary(const t_dictionary *d, t_symbol *key, t_object **value)
{
    return MAX_ERR_GENERIC;
}

t_dictionary *object_dictionaryarg(long ac, t_atom *av)
{
    return NULL;
}


t_max_err dictionary_getatoms(const t_dictionary *d, t_symbol *key, long *argc, t_atom **argv)
{
    return MAX_ERR_GENERIC;
}
t_max_err dictionary_appendatoms(t_dictionary *d, t_symbol *key, long argc, t_atom *argv)
{
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_read(char *filename, short path, t_dictionary **d)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_write(t_dictionary *d, char *filename, short path)
{
    return MAX_ERR_GENERIC;
}

long dictionary_hasentry(const t_dictionary *d, t_symbol *key)
{
    return 0;
}

t_max_err dictionary_getlong(const t_dictionary *d, t_symbol *key, t_atom_long *value)
{
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_getfloat(const t_dictionary *d, t_symbol *key, double *value)
{
    return MAX_ERR_GENERIC;
}


t_max_err dictionary_appendstring(t_dictionary *d, t_symbol *key, const char *value)
{
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_getstring(const t_dictionary *d, t_symbol *key, const char **value)
{
    return MAX_ERR_GENERIC;
}



void attr_args_dictionary(t_dictionary *x, short ac, t_atom *av)
{
    ;
}

void attr_dictionary_process(void *x, t_dictionary *d)
{
    ;
}


// JBOX TEXT

t_max_err jbox_set_fontname(t_object *b, t_symbol *ps)
{
    return MAX_ERR_GENERIC;
}


t_max_err jbox_set_fontsize(t_object *b, double d)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_noactivate(t_object *tf, char c)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_editonclick(t_object *tf, char c)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_useellipsis(t_object *tf, char c)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_wantsreturn(t_object *tf, char c)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_wordwrap(t_object *tf, char c)
{
    return MAX_ERR_GENERIC;
}

t_max_err textfield_set_textmargins(t_object *tf, double left, double top, double right, double bottom)
{
    return MAX_ERR_GENERIC;
}


t_max_err textfield_set_textcolor(t_object *tf, t_jrgba *prgba)
{
    return MAX_ERR_GENERIC;
}





t_max_err object_free(void *x)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

void freeobject(t_object *op)
{
    ;
}

t_object *newobject_sprintf(t_object *patcher, const char *fmt, ...)
{
    return NULL;
}

t_max_err object_attach_byptr(void *x, void *registeredobject)
{
    return MAX_ERR_GENERIC;
}

t_max_err object_detach_byptr(void *x, void *registeredobject)
{
    return MAX_ERR_GENERIC;
}




t_max_err jbox_notify(t_jbox *b, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    return MAX_ERR_GENERIC;
}

t_max_err jbox_invalidate_layer(t_object *b, t_object *view, t_symbol *name)
{
    return MAX_ERR_GENERIC;
}

void jbox_redraw(t_jbox *b)
{
    ;
}

void jbox_grabfocus(t_jbox *b)
{
    ;
}






t_max_err object_method_typed(void *x, t_symbol *s, long ac, t_atom *av, t_atom *rv)
{
    return MAX_ERR_GENERIC;
}

method zgetfn(t_object *op, t_symbol *msg)
{
    return NULL;
}


t_class *class_new(const char *name, const method mnew, const method mfree, long size, const method mmenu, short type, ...)
{
    return NULL;
}

t_max_err class_register(t_symbol *name_space, t_class *c)
{
    return MAX_ERR_GENERIC;
}



/**    Enumeration of slanting options for font display.
 @ingroup    jfont            */
typedef enum _jgraphics_font_slant {
    JGRAPHICS_FONT_SLANT_NORMAL,        ///< Normal slanting (typically this means no slanting)
    JGRAPHICS_FONT_SLANT_ITALIC         ///< Italic slanting
    // JGRAPHICS_FONT_SLANT_OBLIQUE
} t_jgraphics_font_slant;


/**    Enumeration of font weight options for font display.
 @ingroup    jfont            */
typedef enum _jgraphics_font_weight {
    JGRAPHICS_FONT_WEIGHT_NORMAL,        ///< Normal font weight
    JGRAPHICS_FONT_WEIGHT_BOLD            ///< Bold font weight
} t_jgraphics_font_weight;


t_object* jpatcher_get_firstview(t_object *p)
{
    return NULL;
}

t_max_err jbox_get_rect_for_view(t_object *box, t_object *patcherview, t_rect *rect)
{
    return MAX_ERR_GENERIC;
}

#define ASSIST_INLET 1
#define ASSIST_OUTLET 2


long proxy_getinlet(t_object *master)
{
    return 0;
}

void *object_alloc(t_class *c)
{
    return NULL;
}

t_max_err jbox_new(t_jbox *b, long flags, long argc, t_atom *argv)
{
    return MAX_ERR_GENERIC;
}

t_max_err object_obex_lookup(void *x, t_symbol *key, t_object **val)
{
    return MAX_ERR_GENERIC;
}

void *proxy_new(void *x,long id,long *stuffloc)
{
    return NULL;
}

void *outlet_anything(void *o, t_symbol *s, short ac, t_atom *av)
{
    return NULL;
}

void *outlet_int(void *o, t_atom_long n)
{
    return NULL;
}

void *outlet_float(void *o, double f)
{
    return NULL;
}

void *outlet_list(void *o, t_symbol *s, short ac, t_atom *av)
{
    return NULL;
}

void *outlet_new(void *x, const char *s)
{
    return NULL;
}

void *outlet_bang(void *o){
    return NULL;
}

void *bangout(void *x)
{
    return NULL;
}

void *floatout(void *x)
{
    return NULL;
}

void *intout(void *x)
{
    return NULL;
}

void *listout(void *x)
{
    return NULL;
}


t_max_err object_attach_byptr_register(void *x, void *object_to_attach, t_symbol *reg_name_space)
{
    return MAX_ERR_GENERIC;
}

#define NOGOOD(o) (0)
#define ob_sym(x) (gensym("bach")) // for now


//// CLOCKS

void *clock_new(void *obj, method fn)
{
    return NULL;
}

void clock_set(void *obj,long when)
{
    ;
}


void schedule_delay(void *ob, method fun, long delay, t_symbol *sym, short argc, t_atom *argv)
{
    ;
}

void schedule_fdelay(void *ob, method fun, double delay, t_symbol *sym, short argc, t_atom *argv)
{
    ;
}

void schedule_defer(void *ob, method fun, long delay, t_symbol *sym, short argc, t_atom *arv)
{
    ;
}

void schedule_fdefer(void *ob, method fun, double delay, t_symbol *sym, short argc, t_atom *arv)
{
    ;
}

void clock_fdelay(void *c, double time)
{
    ;
}

void setclock_fdelay(t_object *s, void *c, double time)
{
    ;
}

void setclock_getftime(t_object *s, double *time)
{
    ;
}

void setclock_unset(t_object *x, void *c)
{
    ;
}



//// MUTEX

long systhread_mutex_lock(t_systhread_mutex pmutex)
{
    return 0;
}

long systhread_mutex_unlock(t_systhread_mutex pmutex)
{
    return 0;
}

long systhread_mutex_trylock(t_systhread_mutex pmutex)
{
    return 0;
    
}


#define DECLARE_BACH_ATTR(man, forced_position, name, displayed_label, owner_type, struct_name, struct_member, attr_type, attr_size, display_type, preprocess_flags, postprocess_flags) ((void)0)



void jbox_ready(t_jbox *b)
{
    ;
}

void jbox_free(t_jbox *b)
{
    ;
}




t_jgraphics* jbox_start_layer(t_object *b, t_object *view, t_symbol *name, double width, double height)
{
    return NULL;
}

t_max_err jbox_end_layer(t_object *b, t_object *view, t_symbol *name)
{
    return MAX_ERR_GENERIC;
}

t_max_err jbox_paint_layer(t_object *b, t_object *view, t_symbol *name, double x, double y)
{
    return MAX_ERR_GENERIC;
}


t_object* patcherview_get_jgraphics(t_object *pv)
{
    return NULL;
}


void jmouse_setposition_box(t_object *patcherview, t_object *box, double bx, double by)
{
    ;
}

void evnum_incr(void)
{
    ;
}

t_object* jbox_get_textfield(t_object *b)
{
    return NULL;
}




/**    Bit mask values for various meta-key presses on the keyboard.
 @ingroup    jmouse    */
typedef enum _modifiers {
    eCommandKey = 1,        ///< Command Key
    eShiftKey = 2,            ///< Shift Key
    eControlKey = 4,        ///< Control Key
    eAltKey = 8,            ///< Alt Key
    eLeftButton = 16,        ///< Left mouse button
    eRightButton = 32,        ///< Right mouse button
    eMiddleButton = 64,        ///< Middle mouse button
    ePopupMenu = 128,        ///< Popup Menu (contextual menu requested)
    eCapsLock = 256,        ///< Caps lock
    eAutoRepeat = 512        ///< Key is generated by key press auto-repeat
} t_modifiers;


/**    Enumeration of text justification options, which are specified as a bitmask.
 @ingroup    jgraphics            */
typedef enum _jgraphics_text_justification {
    JGRAPHICS_TEXT_JUSTIFICATION_LEFT = 1,            ///< Justify left
    JGRAPHICS_TEXT_JUSTIFICATION_RIGHT = 2,            ///< Justify right
    JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED = 4,        ///< Centered horizontally
    JGRAPHICS_TEXT_JUSTIFICATION_TOP = 8,             ///< Justified to the top
    JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM = 16,        ///< Justified to the bottom
    JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED = 32,    ///< Centered vertically
    JGRAPHICS_TEXT_JUSTIFICATION_HJUSTIFIED = 64,    ///< Horizontally justified
    JGRAPHICS_TEXT_JUSTIFICATION_CENTERED = JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED + JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED    ///< Shortcut for Centering both vertically and horizontally
} t_jgraphics_text_justification;



/**    Flags for setting text layout options.
 @ingroup    textlayout            */
typedef enum _jgraphics_textlayout_flags {
    JGRAPHICS_TEXTLAYOUT_NOWRAP = 1,        ///< disable word wrapping
    JGRAPHICS_TEXTLAYOUT_USEELLIPSIS = 3    ///< show ... if a line doesn't fit (implies NOWRAP too)
} t_jgraphics_textlayout_flags;



//// PATHS

/**
 Constants that determine the output of path_nameconform().
 @ingroup files
 @see #e_max_path_types
 @see path_nameconform()
 */
typedef enum {
    PATH_STYLE_MAX = 0,            ///< use PATH_STYLE_MAX_PLAT
    PATH_STYLE_NATIVE,            ///< use PATH_STYLE_NATIVE_PLAT
    PATH_STYLE_COLON,            ///< ':'  sep, "vol:"   volume, ":"   relative, "^:" boot
    PATH_STYLE_SLASH,            ///< '/'  sep, "vol:/"  volume, "./"  relative, "/"  boot
    PATH_STYLE_NATIVE_WIN        ///< '\\' sep, "vol:\\" volume, ".\\" relative, "\\" boot
} e_max_path_styles;


/**
 Constants that determine the output of path_nameconform().
 @ingroup files
 @see #e_max_path_styles
 @see path_nameconform()
 */
typedef enum {
    PATH_TYPE_IGNORE = 0,        ///< ignore
    PATH_TYPE_ABSOLUTE,            ///< absolute path
    PATH_TYPE_RELATIVE,            ///< relative path
    PATH_TYPE_BOOT,                ///< boot path
    PATH_TYPE_C74,                ///< Cycling '74 folder
    PATH_TYPE_PATH,                ///< path
    PATH_TYPE_DESKTOP,            ///< desktop
    PATH_TYPE_TILDE,            ///< "home"
    PATH_TYPE_TEMPFOLDER,        ///< /tmp
    PATH_TYPE_MAXDB                ///< combi: try PATH_TYPE_C74, PATH_TYPE_TILDE, PATH_TYPE_RELATIVE, PATH_TYPE_ABSOLUTE in that order
} e_max_path_types;


short path_topathname(const short path, const char *file, char *name)
{
    return 0;
}

short path_frompathname(const char *name, short *path, char *filename)
{
    return 0;
}

short path_frompotentialpathname(const char *name, short *path, char *filename)
{
    return 0;
}

short path_nameconform(const char *src, char *dst, long style, long type)
{
    return 0;
}

t_symbol* jpatcher_get_filename(t_object *p)
{
    return NULL;
}

t_object* jpatcher_get_parentpatcher(t_object *p)
{
    return NULL;
}

t_max_err jpatcher_get_rect(t_object *p, t_rect *pr)
{
    return MAX_ERR_GENERIC;
}

t_max_err patcherview_set_zoomfactor(t_object *pv, double d)
{
    return MAX_ERR_GENERIC;
}

t_max_err jbox_set_presentation_size(t_object *box, t_size *size)
{
    return MAX_ERR_GENERIC;
}

t_max_err jbox_set_patching_size(t_object *box, t_size *size)
{
    return MAX_ERR_GENERIC;
}




/**    Mouse cursor types.
 @ingroup jmouse            */
typedef enum _jmouse_cursortype {
    JMOUSE_CURSOR_NONE,                         ///< None
    JMOUSE_CURSOR_ARROW,                         ///< Arrow
    JMOUSE_CURSOR_WAIT,                         ///< Wait
    JMOUSE_CURSOR_IBEAM,                         ///< I-Beam
    JMOUSE_CURSOR_CROSSHAIR,                     ///< Crosshair
    JMOUSE_CURSOR_COPYING,                        ///< Copying
    JMOUSE_CURSOR_POINTINGHAND,                    ///< Pointing Hand
    JMOUSE_CURSOR_DRAGGINGHAND,                    ///< Dragging Hand
    JMOUSE_CURSOR_RESIZE_LEFTRIGHT,                ///< Left-Right
    JMOUSE_CURSOR_RESIZE_UPDOWN,                ///< Up-Down
    JMOUSE_CURSOR_RESIZE_FOURWAY,                ///< Four Way
    JMOUSE_CURSOR_RESIZE_TOPEDGE,                ///< Top Edge
    JMOUSE_CURSOR_RESIZE_BOTTOMEDGE,            ///< Bottom Edge
    JMOUSE_CURSOR_RESIZE_LEFTEDGE,                ///< Left Edge
    JMOUSE_CURSOR_RESIZE_RIGHTEDGE,                ///< Right Edge
    JMOUSE_CURSOR_RESIZE_TOPLEFTCORNER,            ///< Top-Left Corner
    JMOUSE_CURSOR_RESIZE_TOPRIGHTCORNER,        ///< Top-Right Corner
    JMOUSE_CURSOR_RESIZE_BOTTOMLEFTCORNER,        ///< Bottom-Left Corner
    JMOUSE_CURSOR_RESIZE_BOTTOMRIGHTCORNER        ///< Bottom-Right Corner
} t_jmouse_cursortype;



/**    Enumeration of color formats used by jgraphics surfaces.
 @ingroup    jgraphics            */
typedef enum _jgraphics_format {
    JGRAPHICS_FORMAT_ARGB32,        ///< Color is represented using 32 bits, 8 bits each for the components, and including an alpha component.
    JGRAPHICS_FORMAT_RGB24,            ///< Color is represented using 32 bits, 8 bits each for the components.  There is no alpha component.
    JGRAPHICS_FORMAT_A8                ///< The color is represented only as an 8-bit alpha mask.
    //    JGRAPHICS_FORMAT_A1                // not supported
} t_jgraphics_format;

//// IMPLEMENTED IN bach_graphics.c
t_jfont* jfont_create(const char *family, t_jgraphics_font_slant slant, t_jgraphics_font_weight weight, double size);
void jfont_destroy(t_jfont *f);
void jfont_text_measure(t_jfont *font, const char *text, double *width, double *height);
void jgraphics_set_source_jrgba(t_jgraphics *g, t_jrgba *color);
void jgraphics_set_source_rgba(t_jgraphics *g, double red, double green, double blue, double alpha);
char *charset_unicodetoutf8(unicodeChar *uni, long len, long *outlen);
unsigned short *charset_utf8tounicode(char *s, long *outlen);

t_jsurface* jgraphics_image_surface_create_from_resource(const void* moduleRef, const char *resname);
int jgraphics_image_surface_get_height(t_jsurface *s);
int jgraphics_image_surface_get_width(t_jsurface *s);
void jgraphics_surface_destroy(t_jsurface *s);

void jmouse_setcursor_surface(t_object *patcherview, t_object *box, t_jsurface *surface, int xHotSpot, int yHotSpot);
void jgraphics_image_surface_draw(t_jgraphics *g, t_jsurface *s, t_rect srcRect, t_rect destRect);
void jmouse_setcursor(t_object *patcherview, t_object *box, t_jmouse_cursortype type);

/// SHOULD BE BETTER IMPLEMENTED

t_jsurface* jgraphics_image_surface_create(t_jgraphics_format format, int width, int height)
{
    return NULL;
}

t_jgraphics* jgraphics_create(t_jsurface *target)
{
    return NULL;
}

void jgraphics_destroy(t_jgraphics *g)
{
    ;
}




////


#endif // _BACH_JUCEWRAPPER_H_


