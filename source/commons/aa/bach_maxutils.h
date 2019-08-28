//
//  bach_maxutils.h
//  lib_bach
//
//  Created by Andrea Agostini on 20/08/2019.
//

#ifndef bach_maxutils_h
#define bach_maxutils_h

#include <ext.h>

t_patcher *obj_getpatcher(t_object *x);

t_patcher *patcher_getparentpatcher(t_patcher *p);

t_bool is_patcher_contained_in(t_patcher *is, t_patcher *of);

// use this instead of object_method_direct

#define object_method_direct_cpp(rt, sig, x, s, ...) ((rt (*)sig)object_method_direct_getmethod((t_object *)x, s))((t_object*)object_method_direct_getobject((t_object *)x, s), __VA_ARGS__)

#endif /* bach_maxutils_h */
