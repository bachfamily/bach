/*
 *  bach_doc_substitutions.h
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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

/**
	@file	bach_doc_substitutions.h
	@brief	Line substitutions for documentation with Doctor Max
*/

	
#define llllobj_class_add_out_attr
CLASS_ATTR_SYM(c, "out", 0, t_llllobj_object, l_outtypes);
CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_obj_setout);
CLASS_ATTR_STYLE(c, "out", 0, "text");
CLASS_ATTR_LABEL(c, "out", 0, "Outlet Types");
CLASS_ATTR_CATEGORY(c, "out", 0, "Behavior");
CLASS_ATTR_BASIC(c, "out", 0);
// @description @copy BACH_DOC_OUT


#define llllobj_class_add_default_bach_attrs
CLASS_ATTR_SYM(c, "out", 0, t_llllobj_object, l_outtypes);
CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_obj_setout);
CLASS_ATTR_STYLE(c, "out", 0, "text");
CLASS_ATTR_LABEL(c, "out", 0, "Outlet Types");
CLASS_ATTR_CATEGORY(c, "out", 0, "Behavior");
CLASS_ATTR_BASIC(c, "out", 0);
// @description @copy BACH_DOC_OUT


#define codableclass_add_standard_methods_and_attrs
// @method read @digest Read code from file
// @description Loads a file containing bell code into the object,
// keeping it even if it is invalid.
class_addmethod(c, (method)codableobj_forceread,   "forceread",            A_DEFSYM,    0);
//
// @method forceread @digest Read code from file even if incorrect
// @description Loads a file containing bell code into the object,
// but ignore it if the code is invalid.
class_addmethod(c, (method)codableobj_read,   "read",            A_DEFSYM,    0);
//
// @method readappend @digest Read code from file and append it
// @description Appends the contents of a file containing bell code
// to the code already owned by the object,
// but ignore it if the code is invalid.
class_addmethod(c, (method)codableobj_readappend,   "readappend",            A_DEFSYM,    0);
//
// @method forcereadappend @digest Read code from file and append it even if incorrect
// @description Appends the contents of a file containing bell code to the code already owned by the object,
// keeping it even if it is invalid.
class_addmethod(c, (method)codableobj_forcereadappend,   "forcereadappend",            A_DEFSYM,    0);
//
// @method write @digest Save code to file
// @description Writes the bell code into a file.
class_addmethod(c, (method)codableobj_write, "write", A_DEFSYM, 0);
//
CLASS_ATTR_ATOM_LONG(c, "maxtime",    0,    t_codableobj, c_maxtime);
CLASS_ATTR_LABEL(c, "maxtime", 0, "Maximum Duration Of Evaluation");
CLASS_ATTR_FILTER_MIN(c, "maxtime", 0);
// @description The <m>maxtime</m> attribute allows setting a maximum evaluation time
// in milliseconds for the bell code provided.
// If it is reached, the evaluation aborts and the code returns null.
// If <m>maxtime</m> is set to 0, there is no time limit.
// The default is 60000 ms (1 minute).


#define codableclass_add_extended_methods_and_attrs
// @method (doubleclick) @digest Edit bell code for <m>lambda</m> attribute
// @description Doubleclicking on the object forces a text editor to open up, where the bell code
// for the <m>lambda</m> attribute can be edited directly.
class_addmethod(c, (method)codableobj_dblclick,  "dblclick",        A_CANT, 0);
//
CLASS_ATTR_ATOM_LONG(c, "embed", 0, t_codableobj, c_embed);
CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
CLASS_ATTR_SAVE(c, "embed", 0);
// @description When set to 1, the bell code for the <m>lambda</m> attribute
// is saved with the patcher, even if not set in the object box.
//
CLASS_ATTR_CHAR_VARSIZE(c, "lambda", 0, t_codableobj, c_text, c_dummysize, 32767);
CLASS_ATTR_LABEL(c, "lambda", 0, "Bell Expression For Lambda Function");
CLASS_ATTR_ACCESSORS(c, "lambda", codableobj_lambda_get, codableobj_lambda_set);
// @description The <m>lambda</m> attribute allows setting a snipped of bell code
// to be called instead of the lambda loop. If the lambda attribute is set,
// the lambda loop will not be evaluated, and the provided code will be executed as well.
// For each lambda outlet of the object, an input pseudovariable is passed to the lambda loop,
// with their indices counted from left to right.
//
CLASS_ATTR_LLLL(c, "lambdaparams", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
CLASS_ATTR_LABEL(c, "lambdaparams", 0, "Extra Parameters To Lambda Function");
// @description The <m>lambdaparams</m> attribute allows setting the values
// of local variables to be passed to the bell code set by the <m>lambda</m> attribute.
// It is structured as an llll consisting of one or more sublists,
// each containing the name of a variable and its value to be passed to the code.
// For example, the llll <b>[ $foo 1 ] [ $bar [ 2 3 ] ]</b>
// will set the $foo and $bar local variables respectively to <b>1</b> and <b>[ 2 3 ]</b>.
