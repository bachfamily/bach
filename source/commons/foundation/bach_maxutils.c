/*
 *  bach_maxutils.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#include "foundation/bach_maxutils.h"

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

