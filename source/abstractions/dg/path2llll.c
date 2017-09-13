/**
	@file
	path2llll.c
	
	@name 
	bach.path2llll
	
	@realname 
	bach.path2llll

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Obtain full directory tree in llll form
	
	@description
	Converts a directory path into an llll containing the full information about its files and subfolders.
	Subfolders are represented by sublists, whose first elements are the subfolder names.
	
	@discussion
	The output of <o>bach.path2llll</o> can be connected with a <o>bach.tree</o> object, with the
	<m>firsteleminllllisllllname</m> attribute set to 1.

	@category
	bach, bach abstractions, bach llll

	@keywords
	convert, file, folder, path, name, tree, import, full, directory, subfolder, hierarchy
	
	@seealso
	folder, bach.tree, bach.dict2llll, dropfile
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method symbol @digest Obtain directory tree
// @description A symbol is considered to be the path to the folder which has to be inspected.
// All the files and subfolder contained in the entered folder are organized in llll form and output, 
// under the convention that each subfolder are represented by a sublist whose first element
// is the subfolder name. Left outlet outputs such tree in llll form. Right outlet outputs the same tree
// where each element retains its full path. As always, right outlets fires before the left one.

// @method bang @digest Output directory tree
// @description Output the directory tree of the most recently received input path.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "fullinitpath", 0, t_path2llll, full_init_path); 
CLASS_ATTR_STYLE_LABEL(c,"fullinitpath",0,"onoff","Preserve Full Initial Path");
CLASS_ATTR_BASIC(c,"fullinitpath",0);
// @description Toggle the ability to preserve, in the left-outlet output llll, the full path of the initial
// root folder. Default is 0, meaning that the only preserved item is the root folder name. 
// This attribute does not affect the llll fired from the right-outlet, where such path is always preserved.

CLASS_ATTR_CHAR(c, "folderpos", 0, t_path2llll, folderpos); 
CLASS_ATTR_STYLE_LABEL(c,"folderpos",0,"enumindex","Folder And Files Position");
CLASS_ATTR_ENUMINDEX(c,"folderpos", 0, "Mixed Folders First Files First");
// @description Sets the file ordering type: Mixed (0), Folders First (1), Files First (2).

CLASS_ATTR_CHAR(c, "filesonly", 0, t_path2llll, filesonly); 
CLASS_ATTR_STYLE_LABEL(c,"filesonly",0,"onoff","Files Only");
// @description Toggles the ability to drop folder names from output llll.

CLASS_ATTR_SYM_VARSIZE(c, "types", 0, t_path2llll, folderpos, folderpos_numfiletypes, MAX_FILETYPES);
CLASS_ATTR_STYLE_LABEL(c,"types",0,"text","File Types");
CLASS_ATTR_BASIC(c,"fullinitpath",0);
// @description The word <m>types</m>, followed by one or more four-letter filetype codes, sets the file
// types that the object will look for in the specified folder (see the <o>folder</o> object for more information).

CLASS_ATTR_CHAR(c, "nosort", 0, t_path2llll, no_sort); 
CLASS_ATTR_STYLE_LABEL(c,"nosort",0,"onoff","Avoid File-Specific Sorting");
// @description Toggle the ability to avoid file-specific sorting of the symbols, where files are compared
// ignoring the case, and where some elements such as underscores, spaces or tilde will come before any letter
// in the file ordering. Default is 0. Toggle this attribute to drastically reduce computation time, if you have
// folders containing a lot of data.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type symbol @digest The directory path

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The directory tree
// @out 1 @type llll @digest The directory tree with full element paths


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name pathname @optional 1 @type symbol @digest Root path name 
// @description A symbol as argument specifies the initial path name.