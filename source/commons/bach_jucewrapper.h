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
typedef unsigned short unicodeChar;
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


t_max_err dictionary_read(char *filename, short path, t_dictionary **d)
{
    // TO DO
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_write(t_dictionary *d, char *filename, short path)
{
    return MAX_ERR_GENERIC;
}


t_max_err object_free(void *x)
{
    // TO DO
    return MAX_ERR_GENERIC;
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



short wind_advise_explain(t_object *w, char *note, char *explanation, char *b1, char *b2, char *b3)
{
    return 0;
}

void *object_new(t_symbol *name_space, t_symbol *classname, ...)
{
    // TO DO
    return NULL;
}

t_max_err dictionary_appendstring(t_dictionary *d, t_symbol *key, const char *value)
{
    return MAX_ERR_GENERIC;
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


t_max_err sysfile_writetextfile(t_filehandle f, t_handle htext, t_sysfile_text_flags flags)
{
    return MAX_ERR_GENERIC;
}

t_max_err dictionary_getstring(const t_dictionary *d, t_symbol *key, const char **value)
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

t_class *object_class(void *x)
{
    return NULL;
}

long attr_args_offset(short ac, t_atom *av)
{
    return 0;
}

void attr_args_process(void *x, short ac, t_atom *av)
{
    ;
}


t_dictionary* dictionary_new(void)
{
    return NULL;
}


t_max_err jbox_notify(t_jbox *b, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    return MAX_ERR_GENERIC;
}

t_max_err jbox_invalidate_layer(t_object *b, t_object *view, t_symbol *name)
{
    return MAX_ERR_GENERIC;
}

t_max_err object_method_typed(void *x, t_symbol *s, long ac, t_atom *av, t_atom *rv)
{
    return MAX_ERR_GENERIC;
}

method zgetfn(t_object *op, t_symbol *msg)
{
    return NULL;
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




#endif // _BACH_JUCEWRAPPER_H_


