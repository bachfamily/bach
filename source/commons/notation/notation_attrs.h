/*
 *  notation_attrs.h
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


#ifndef _NOTATION_ATTRS_H_
#define _NOTATION_ATTRS_H_

#include "notation/notation.h"

#define DEFINE_NOTATIONOBJ_LONGPTR_GETTER(DATA_FIELD, COUNT_FIELD) \
t_max_err notation_obj_##DATA_FIELD##_getattr(t_notation_obj *x, t_object *attr, long *ac, t_atom **av) \
{ \
	long i; \
    char alloc; \
	lock_general_mutex(x); \
    atom_alloc_array(x->COUNT_FIELD, ac, av, &alloc); \
    for (i = 0; i < x->COUNT_FIELD; i++) { \
		atom_setlong((*av) + i, x->DATA_FIELD[i]); \
	} \
	unlock_general_mutex(x); \
	return MAX_ERR_NONE; \
}

#define DEFINE_NOTATIONOBJ_DBLPTR_GETTER(DATA_FIELD, COUNT_FIELD) \
t_max_err notation_obj_##DATA_FIELD##_getattr(t_notation_obj *x, t_object *attr, long *ac, t_atom **av) \
{ \
	long i; \
    char alloc; \
	lock_general_mutex(x); \
    atom_alloc_array(x->COUNT_FIELD, ac, av, &alloc); \
	for (i = 0; i < x->COUNT_FIELD; i++) { \
		atom_setfloat((*av) + i, x->DATA_FIELD[i]); \
	} \
	unlock_general_mutex(x); \
	return MAX_ERR_NONE; \
}

#define DEFINE_NOTATIONOBJ_SYMPTR_GETTER(DATA_FIELD, COUNT_FIELD) \
t_max_err notation_obj_##DATA_FIELD##_getattr(t_notation_obj *x, t_object *attr, long *ac, t_atom **av) \
{ \
	long i; \
    char alloc; \
	lock_general_mutex(x); \
    atom_alloc_array(x->COUNT_FIELD, ac, av, &alloc); \
	for (i = 0; i < x->COUNT_FIELD; i++) { \
		atom_setsym((*av) + i, x->DATA_FIELD[i]); \
	} \
	unlock_general_mutex(x); \
	return MAX_ERR_NONE; \
}

#define DEFINE_NOTATIONOBJ_CHARPTR_GETTER(DATA_FIELD, COUNT_FIELD) \
t_max_err notation_obj_##DATA_FIELD##_getattr(t_notation_obj *x, t_object *attr, long *ac, t_atom **av) \
{ \
	long i; \
    char alloc; \
	lock_general_mutex(x); \
    atom_alloc_array(x->COUNT_FIELD, ac, av, &alloc); \
	for (i = 0; i < x->COUNT_FIELD; i++) { \
		atom_setlong((*av) + i, x->DATA_FIELD[i]); \
	} \
	unlock_general_mutex(x); \
	return MAX_ERR_NONE; \
}
/*
*ac = x->COUNT_FIELD; \
*av = (t_atom *) sysmem_newptr(x->COUNT_FIELD * sizeof(t_atom)); \
*/

#define DEFINE_NOTATIONOBJ_ATOMPTR_GETTER(DATA_FIELD, COUNT_FIELD) \
t_max_err notation_obj_##DATA_FIELD##_getattr(t_notation_obj *x, t_object *attr, long *ac, t_atom **av) \
{ \
	long i; \
    char alloc; \
	lock_general_mutex(x); \
    atom_alloc_array(x->COUNT_FIELD, ac, av, &alloc); \
	for (i = 0; i < x->COUNT_FIELD; i++) { \
		(*av)[i] = x->DATA_FIELD[i]; \
	} \
	unlock_general_mutex(x); \
	return MAX_ERR_NONE; \
}

/*
#define CLASS_ATTR_NOTATIONOBJ_LONGPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_new(attrname, USESYM(long), (flags), (method)notation_obj_##structmember##_getattr, (method)setter, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_DBLPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_new(attrname, USESYM(float64), (flags), (method)notation_obj_##structmember##_getattr, (method)setter, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_SYMPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_new(attrname, USESYM(symbol), (flags), (method)notation_obj_##structmember##_getattr, (method)setter, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_CHARPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_new(attrname, USESYM(char), (flags), (method)notation_obj_##structmember##_getattr, (method)setter, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_ATOMPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_new(attrname, USESYM(atom), (flags), (method)notation_obj_##structmember##_getattr, (method)setter, calcoffset(t_notation_obj, structmember)))
*/
 

#define CLASS_ATTR_NOTATIONOBJ_LONGPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_array_new(attrname, USESYM(long), maxcount, (flags), (method)notation_obj_##structmember##_getattr, (method)setter, 0, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_DBLPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_array_new(attrname, USESYM(float64), maxcount, (flags), (method)notation_obj_##structmember##_getattr, (method)setter, 0, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_SYMPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_array_new(attrname, USESYM(symbol), maxcount, (flags), (method)notation_obj_##structmember##_getattr, (method)setter, 0, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_CHARPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_array_new(attrname, USESYM(char), maxcount, (flags), (method)notation_obj_##structmember##_getattr, (method)setter, 0, calcoffset(t_notation_obj, structmember)))

#define CLASS_ATTR_NOTATIONOBJ_ATOMPTR(c,attrname,flags,structmember,maxcount,setter) \
class_addattr((c), attr_offset_array_new(attrname, USESYM(atom), maxcount, (flags), (method)notation_obj_##structmember##_getattr, (method)setter, 0, calcoffset(t_notation_obj, structmember)))


#endif // _NOTATION_ATTRS_H_
