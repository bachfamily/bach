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
    return jbox_get_patcher(jpatcher_get_box(p));
}

t_bool is_patcher_contained_in(t_patcher *is, t_patcher *in)
{
    for (is = patcher_getparentpatcher(is);
         is && is != in;
         is = patcher_getparentpatcher(is));
    
    return is == in;
}

