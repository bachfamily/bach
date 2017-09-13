/**
	@file	bach_doc_substitutions.h
	@brief	Line substitutions for documentation with Doctor Max
	
	by Daniele Ghisi
*/

	
#define llllobj_class_add_out_attr
CLASS_ATTR_SYM(c, "out", 0, t_llllobj_object, l_outtypes);
CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_obj_setout);
CLASS_ATTR_STYLE(c, "out", 0, "text");
CLASS_ATTR_LABEL(c, "out", 0, "Outlet Types");
CLASS_ATTR_CATEGORY(c, "out", 0, "Behavior");
CLASS_ATTR_BASIC(c, "out", 0);
// @description @copy BACH_DOC_OUT
