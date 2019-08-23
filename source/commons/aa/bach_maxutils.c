//
//  bach_maxutils.c
//  lib_bach
//
//  Created by Andrea Agostini on 20/08/2019.
//

#include "bach_maxutils.h"

t_patcher *obj_getpatcher(t_object *x)
{
    t_object *p;
    object_obex_lookup(x, gensym("#P"), &p);
    return p;
}

t_patcher *patcher_getparentpatcher(t_patcher *p)
{
    t_object *box = jpatcher_get_box(p);
    t_patcher *parent;
    if (box) {
        parent = jbox_get_patcher(box);
    } else {
        object_method_direct_cpp(void, (t_object *, t_object **), p, _sym_getassoc, &box);
        if (box)
            parent = obj_getpatcher(box);
        else
            parent = nullptr;
    }
    return parent;
}

t_bool is_patcher_contained_in(t_patcher *is, t_patcher *in)
{
    for (is = patcher_getparentpatcher(is);
         is && is != in;
         is = patcher_getparentpatcher(is));
    
    return is == in;
}

