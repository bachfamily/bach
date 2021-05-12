/*
 *  bach_doc_groups.h
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
	@file	bach_doc_groups.h
	@brief	Grouping definitions for doxygen documentation
*/


/*! \mainpage Public bach 0.7 API documentation.
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */
 
 
/**
	@defgroup	datatypes	Data types
	All the bach data types
   
	@defgroup math	Mathematical
	Mathematical tools.
	A certain number of mathematical structures, functions and utilities, is required within the bach framework.
	
	@{
	
		@defgroup rational Rational
		Tools to handle with the #t_rational data type.
		Rationals are a fundamental type in the bach environment, for instance used in accidentals, score symbolic durations, tuplet ratios...

		@defgroup geometry Geometry
		Geometrical tools.
	
		@defgroup linear_algebra Linear Algebra
		Tools for linear algebra and matrix calculus.
		The bach environment comes with a little library for matrix calculus. A matrix is nothing but an llll having depth 2, and possibly "well-shaped",
		meaning that every llll at the first level (line) has the same number of elements (which, "in vertical”, form the columns).
		An important linearalgebraic function, such as llll_trans(), is not in this category, but rather in the standard llll commons functions,
		for convenience reasons. 

		@defgroup musical_set_theory Musical Set Theory
		Musical Set Theory tools.
		The bach environment comes with a library for the Musical Set Theory. Here you can find all the tools needed for it to work.
		The abbreviation "pc" stands for pitch class, "pcset" stands for pitch-class set. Pcsets are always represented by lllls (which sometimes, when
		explicit inside the function documentation, can contain also structured trees of pcsets, where actual pcsets are the "last depth-1 leaf").
		Each pitch class is an element of the ring Z/nZ, where n is the "modulo" (often appearing as function argument), i.e. the number of equally–spaced 
		pitches in the octave; for instance the semitonal grid corresponds to 12, the quartertonal grid to 24, and so on. Of course, the so-built ring
		has no pitch-specific characteristics, so one can completely use it (for instance) to represents patterns in a rhythmic grid with n equal divisions,
		and so on.  


	@}
	
	@defgroup paint	Paint
	Common paint tools and wrappers.
	
	@{

		@defgroup text_writing	Text Writing
		Tools to write text.
		
		@defgroup colors	Colors
		Tools to work with colors.

	@}

	@defgroup llll_objects	llll objects utilities
	Tools to handle the llll objects.

	@defgroup llll_utilities	llll utilities
	Tools for advanced llll handling.

	@defgroup notation		Notation
	Tools for handling with music notation.
	A general important remark must be done: throughout all bach notation functions and tools, some names of fields, functions or defines are marked
	have a weird "u" inside their name. This "u" stands for "unscaled". Every unscaled value does NOT represent the ACTUAL graphic value, but is the 
	graphic value computed for a base zoom: zoom_y = 1, zoom_x = 1. For instance, bach computes the score spacing once for all, when the score is
	inserted or changed. If the user changes the vertical or horizontal zoom, nothing about the spacing is recomputed, but only rescaled with respect
	to the current zooms. The unscaled values are thus the values computed for default zoom, and they need to be changed proportionally to the zoom_y 
	(and, if needed, also to zoom_x), in order to be used on the actual graphic surface.


	@{
	
		@defgroup attributes_and_bach_inspector		Attributes And Bach Inspector
		Common tools for dealing with bach attributes and inspecting them.
		
		
		@{

			@defgroup attributes		Attributes
			Tools for dealing with bach attributes.


			@defgroup bach_inspector		Bach Inspector
			Tools for dealing with the external bach inspector.
		
		@}
		
		@defgroup notation_data		Data Setting Or Retrieval
		Tools to handle the notation data set or get.
		
		
		@defgroup notation_data_send	Data Outputting
		Tools to handle outputting and dumping of musical information.
		
		
		@defgroup notation_free		Free
		Functions for freeing notation structures.
		
		
		@defgroup rhythmic_trees		Rhythmic Tree
		Tools for rhythmic tree handling.
		A few words are necessary to understand the behaviour of the rhythmic trees in the code.
		The rhythmic tree is a tree structure accounting for the correct nesting of rhythm groups, and thus chiefly for 
		tuplets identifications and for beam handling. The idea is that, for each measure, not only we have our linear sequence 
		of #t_chord structures, but we also have a llll accounting for their relationships. For instance, if the linear sequence is, say,
		ch1 ch2 ch3 ch4 ch5 (where each chi will be a pointer to a #t_chord), a rhythmic tree structure could be
		[(ch1 ch2) (ch3 (ch4 ch5))], meaning that the first two chords are for some reason requested to be together (e.g. they might be two
		8ths beamed together), and so on. Sometimes we'll replace the chi chords with their symbolic duration values (which is of course
		the most important parameter when dealing with rhythm) just for the sake of exemplification. We'll write, thus, for instance
		[(1/8 1/8) (1/8 (1/16 1/16))]

		The <rhythmic_tree> field of each measure, thus, contains a llll (composed only of #H_OBJ pointers to chord) whose elements 
		are gathered in such a way that mirrors the requested beaming and tuplet structure. Any sub-llll of this rhythmic tree will be 
		referred, in the function, as a "box" or a "rhythmic tree level".

		As you might understand, a great deal of job is required for any operation to keep those two representation up to date one to the other.
		Tree operations (such as chord splitting or merging) are directly performed on the tree when possible (and this impacts of course the linear
		representation); other chiefly linear operations (such as speedy edit) will instead require a global or local tree recomputation.

		This recomputation can be of course handled in very different way. First of all we have to notice that the tree structure is NOT
		a precise mirror of the beaming or tuplet nesting (this might be possible with some additional improved data for each level), but
		is more a "suggestion". For instance, the rhythm [(1/8 (1/32 1/32)) 1/4] does by no means tell us how many beams must be referred 
		to each level: although it is quite straightforward that the level (1/8 (1/32 1/32)) should have 1 beam, we don't know if the level
		(1/32 1/32) should have just a second beam (and then each 32th note will have an additional "tick") or should have two more beams
		(and thus all chords are completely beamed, with no single ticks). You might think that explicitely enter (1/8 ((1/32 1/32)))
		might solve the issue (with the equation 1 beam = 1 level) but this is both redundant for the user and trick for the machine: since
		tuplets and beamings are BOTH dealt with via the rhythmic tree, tuplet elements might NOT need beamings, and thus a clear confusion
		is quickly born. Of course, levels might also be meaningless (as far as tuplet or beamings are concerned), just think about something like
		[(1/4 1/4) (1/4 1/4)] 

		No, in bach the rhythmic tree is not an EXACT translation of tuplets and beamings, rather a SUGGESTION for the algorithms to detect 
		their own beams and tuplets. This suggestion might be more or less forced (e.g. see #k_RHYTHM_LEVEL_FORCE_TUPLET), but they remain
		suggestions. To help in the translation, you have some parameters handled by some enums, namely e_rhythmic_tree_modes, 
		e_beams_over_rests, e_rests_within_beam_handling, e_tree_to_beams_correspondences. For instance, e_rhythmic_tree_modes tell
		bach if he has to consider the input tree untouchable (#k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED), or should completely trash it
		and rebuild another one anew (#k_RHYTHMIC_TREE_HANDLING_IGNORE), or any flavour between those two extremes - most importantly 
		#k_RHYTHMIC_TREE_HANDLING_REFINE (which roughly speaking only create levels INSIDE existing levels, but won't destroy existing
		levels, unless very special cases) and #k_RHYTHMIC_TREE_HANDLING_PROCESS which is like the REFINE brother, but allows a little more:
		levels can also be destroyed or grouped in some occasions.

		What is quite clear, is that any level of the tree (when we speak of levels, we will always refer to any sub-llll of the tree, 
		which might also be the llll of the tree itsself) will be associated to some properties, such as its type (is it a level that 
		the user has inserted? or has it been created by the refinement algorithms?) or its beam number or its being a tuplet and its
		tuplet information. All this is stored inside the l_thing fields of each llll level (included the original rhythmic tree whole llll)
		as a #t_rhythm_level_properties structure, accounting for all the properties we need to handle with beaming and tuplet levels.

		When a tree needs to be recalculated, two functions are called, inside the perform_analysis_and_change function:
		- process_rhythmic_tree(), in charge for setting up the tree and 
		  correctly filling all the #t_rhythm_level_properties for each level 
		- build_beams_structures(), in charge for translating the #t_rhythm_level_properties of each level
		  into "real" beams and tuplets (i.e. #t_beam structure, and tupletinfos)
		(Between the two functions some operations need to be done, such as recomputing chord parameters...)

		Most of the following functions are the one recalled in these two functions. A certain number of the formers are indeed fun_fn functions
		for funall, and they are ony used inside llll_funall, and thus performed on each subelement or on each sublevel of a given function.

		@{

			@defgroup tuplets		Tuplets
			Tools for dealing with tuplets.
		
		@}
		
		@defgroup spacing		Spacing
		Tools for dealing with the music spacing.


		@defgroup settings		Settings
		General define constants for the notation behaviour.


		@defgroup operations		Operations
		Functions operating on scores.
		
		@{

			@defgroup score_operations		bach.score Operations
			Functions operating on bach.score's hierarchies and structures.
		
			@{
				@defgroup tempi_operations		Measures Operations
				Functions operating on bach.score's #t_measure (and #t_measure_end_barline) structures.

				@defgroup ts_operations		Time Signatures Operations
				Functions operating on bach.score's #t_timesignature structures.
			
				@defgroup tempi_operations		Tempi Operations
				Functions operating on bach.score's #t_tempo structures.
			
			@}
		@}
		
		@defgroup import_export		Import And Export
		Tools for importing/exporting music data.


		@defgroup ids		IDs
		Tools to handle the notation item IDs.
		IDs are POSITIVE INTEGERS (so 0 is NOT assigned as an ID, rather it means that the ID has not been assigned to a given notation item).
		IDs are assigned and retrieven via the shashtable API functions, like shashtable_insert(), shashtable_retrieve() and so on.
		IDS are chiefly used to handle undo situtations and with the "lambda" message (in order to get it thread safe). All notation items whose information
		can be undone (at the present time: voices, measures and chords) are given an unique ID. Also IDs are given to notes, since their content can be output
		via the playout to make a lambda loop (and the ID guarantees the thread-safety).
		Also IDs are used to guarantee measure-attachment for the markers in [bach.score] 
 
 
		@defgroup names		Names
		Tools to handle the names of the notation items.


		@defgroup iterators		Iterators
		Tools to handle iterated modifications on musical data.
		The idea is that one can easily perform a modification on the selected elements of the notation object simply by calling the
		proper iterator with the required function as an argument.
 
 
		@defgroup interface		Interface
		Tools to handle notation interface events.
		
		@{

			@defgroup notation_actions		Actions
			Tools to handle the actions upon notation data.


			@defgroup slot_interface		Slot Interface
			Tools to handle slot window interface events.


			@defgroup textfield		Text Field
			Tools to deal with the notation object's text field.
			The text field is the standard text field coming with the Max API, and can be used for "in-place" editing of different texts,
			such as markers name, voice names, lyrics, llll or text slot content.
			Notice that there is a single textfield which is moved/stretched accordingly to the position and size of the text we need
			to display, and whose font is changed according to the different usages.
			

			@defgroup editor			External Editor
			Tools to deal with the notation object's external editor.
			The external editor is the standard editor coming with the Max API, and can be used to show and edit the 
			content of text and llll slots.


			@defgroup selection		Selection
			Tools to handle the selection mechanism.
			The selection mechanism in bach are handled via two linked lists of #t_notation_item structures.
			Notice that each notation item has as its first field this structure, and inside this structure there are the links for
			binding this item along two different linked lists: 
			 - the "selection" linked list, containing the elements which are currently selected
			 - the "preselection" linked list, mainly containing the elements which are being selected
			Neither of these two lists has a particular order (elements are just appended one after the other).  
 			After each selection operation, it is a good rule to call for the function move_preselecteditems_to_selection(),
 			whose task is to void the preselection list, by making its element "flow” to the selection list. How this flowing is
 			performed is specified in the <mode> argument: in fact, one might want to say that if an already selected item
 			is also preselected, when the flowing is performed it could be UN-selected (this is what happens when you drag a
 			selection rectangle), or just kept selected (this is what happens if you use the "sel" message), and so on. 
 			In each #t_notation_obj structure there are the heads and tails of each of the two lists: <firstselecteditem> and <lastselecteditem>,
 			and <firstpreselecteditem> and <lastpreselecteditem>.
 			The number of selected items is contained in the field <num_selecteditems>; the current selection type (the overall type 
 			of the selected elements) is contained in the <selection_type> field.


			@defgroup prevent_edit		Prevent Editing 
			Tools for prevent the editing of given elements.

			@defgroup undo		Undo
			Tools to handle the undo/redo system.
			The undo systems involves undo ticks and undo markers. Undo ticks are "elementary" operations that need to be performed.
			Each operation can be decomposed into elementary operations. For instance, shiftings 10 chords will be decomposed into the 
			10 elementary operations involving the change of each one of the chords. 
			Each elementary operation is codified in a #t_undo_redo_information structure, whose memory is allocated, and then stored
			as a #H_OBJ element inside the <undo_llll> field of the notation object structure. Each new operation is prepended in the list,
			so that newest changes are always at first places. At the end of ALL elementary operations belonging to the same interface event, 
			an undo marker is placed. An undo marker is nothing but an integer naming the overall interface operation (constituted by the 
			sequence of elementary operation). So, for instance, after our 10 selected chords being shifted up, we might place a marker, identifiable by being a #H_LONG, 
			like #k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION. This is linked via the #undo_op_to_string() function, with the label appearing 
			in the Max window when the undo is performed (if the undo is verbose).

			When an undo step is asked for, the algorithm takes the first marker, and perform subsequently all the elementary undo operations contained
			in the #t_undo_redo_information structures stored AFTER the marker, until the next marker is achieved.
			The correct new information is symmetrically stored in the <redo_llll> field of the notation object structure, which behaves exactly the same.
			If our information in our undo list is [#k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION m10 m9 m8 m7 m6 m5 m4 m3 m2 m1 #k_UNDO_OP_MOUSEDRAG_CHANGE n1 n2 n3] ... 
			where m_i and n_i are the elementary modifications, then the undo algorithm will memorize #k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION, perform m10, 
			"reverse" m10 (i.e. will find the opposite modification) and prepend it to the redo list, perform m9, reverse it and then prepend it to the redo list...
			until m1 is performed, reversed and prepend it to the redo list. Then the original #k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION marker is prepended to the redo list, which 
			now looks like [#k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION m1 m2 m3 m4 m5 m6 m7 m8 m9 m10]
			When a redo step is asked for, the exactly opposite operation is done. This has to be handled in each notation object's particular undo/redo routine.
			
			Each elementary operation involves a notation item having an ID (which is indeed an "undo"-ID, since it is only used for undo). This ID comes
			from storing the element into an hashtable. Currently, the smallest element being handled by undo is the chord; this means that if you change a note,
			the elementary undo information will still be the information involving the whole chord, and so on. Four types of elementary modification can be asked for: #k_UNDO_MODIFICATION_CHANGE (which will store the whole information about the item, and will change it), #k_UNDO_MODIFICATION_ADD (which, be careful, is usually
			stored when a notation item is DELETED, and which contain the ID and the information to rebuild it), #k_UNDO_MODIFICATION_DELETE (which, in turns, is used when
			a notation item is ADDED, and will need no content, just the ID of the object to delete), #k_UNDO_MODIFICATION_CHANGE_FLAG (which only stores the flag of the 
			notation elements - and of its sons - and then will ask only to change the flag; this is used for instance when something is locked or muted), and
			#k_UNDO_MODIFICATION_CHANGE_NAME (which only stores the names of notation elements, in a llll).
			
			We stress once again that the elementary operations are not the operations that were performed, but the operation that HAVE to be performed by the
			undo routine. On the other hand, the undo marker represent the operation that were actually performed.
 
            All items currently being in the undo list ('ticked') are collected in the t_notation_obj::undo_notation_items_under_tick llll; the l_thing field
            of each element contains the type of undo modification (one of the #e_undo_modification_types)


			@defgroup popup_menus		Popup Menus
			Tools to handle the contextual popup menus.
			Popup menus are contextual menus which pop up when the right mouse is pressed. There are different menus depending on the
			notation element on which the mouse has been pressed.
		
			
			@defgroup attributes		Attributes And bach Inspector
			Tools to handle the bach specific attributes, shown in the bach inspector (Shift+Return to show/hide).
			
			The inspector is a standard tool in bach: some of the fields of the most common notation items, as well as some of the slotinfo fields, have a "public
			value", meaning that they represent some important properties (and not some graphic representation parameters, or some utility value stocked for computational purpose).
			Those parameters are usually defined as attributes within the bach framework.
			An attribute is, indeed, a field of a structure having a "public value". To declare this, the macro you need to use is DECLARE_BACH_ATTR().
			Indeed, some common attributes to notation objects (and also some peculiar ones, for convenience purposes) are declared in the notation_obj_bach_attribute_declares()
			routine. Each declared attributes must be associated with a name (a symbol, a good rule is that it has to be the same symbol as the router in the gathered syntax
			assigning the same field via message), with a label (displayed in the bach inspector), with a owner type (the structure to which the attribute is referred, e.g. k_SLOTINFO
			or k_CHORD), the structure name directly owning the attribute field, the structure member corresponding to the attribute field,
			an attribute type (the type of the variable of the field, one of the #e_bach_attr_types and the attribute size (in case the attribute is a vector attribute), the way to display
			the values in the inspector (one of the #e_bach_attr_display_types, similar to the Max standard ones).
			
			Attributes are stored in the notation object attr_manager field: a #t_bach_attr_manager structure holding (for each one of the #e_element_types) the number of attributes
			associated to it, and the attributes themselves, as #t_bach_attribute structures.
			
			Once an attribute has been defined, it can be retrieved via bach_attribute_get(). And we can also specify further information, such as (in case the display type was an enumindex)
			the enumindex configuration. For instance, have a look at the following code:			 
			@code
			DECLARE_BACH_ATTR(r_ob, -1, _llllobj_sym_type, "Type", k_SLOTINFO, t_slotinfo, slot_type, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
			get_slottypes_as_sym_list(r_ob, slottypes);
			bach_attribute_add_enumindex(bach_attribute_get(r_ob, k_SLOTINFO, _llllobj_sym_type), 16, slottypes);
			@endcode
			
			Each attribute is retrieved via a default bach getter (bach_default_get_bach_attr()), and set via a default bach setter (bach_default_set_bach_attr()). 
			Before each setting a default preprocess operation is performed (bach_default_preprocess()) and after each setting a default postprocess operation is performed
			(bach_default_postprocess()). Of course, these functions can be defined as custom functions, so that bach will use the defined functions instead of the default ones.
			One can do this via void bach_attribute_add_functions(), provided that the function be in the correct form of #bach_getter_fn or #bach_setter_fn or #bach_attr_process_fn.
			For instance, setting a "mute" attribute for a note requires to check the correct scheduling (what if the newly muted note was to be played next?), and we can thus define
			@code
			DECLARE_BACH_ATTR(r_ob, -1, _llllobj_sym_mute, "Mute", k_NOTE, t_note, muted, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
			bach_attribute_add_functions(bach_attribute_get(r_ob, k_NOTE, _llllobj_sym_mute), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn);
			@endcode
			
			The function bach_set_attr() and bach_get_attr() set and get the bach attributes starting from the usual GIMME Max signature, and using the proper setter/getter
			(the defined one, or the default one if there is no defined one - i.e. the attribute setter/getter fields are NULL, which is of course the default).
			It is worth noticing that the default bach set/get/preprocess/postprocess routines are by no means trivial: they take into account the single cases for each bach 
			notation item (do we need to recompute measure spacing? do we need to recompute chord parameters? and so on...).
			
			Moreover, each attribute has an <inactive> field containing a pointer to a bach_inactive_fn() function, returning 1 if the attribute
			should be inactive, 0 otherwise. Inactive attributes appear greyed in the inspector, and cannot be changed. If this field is NULL (default),
			a default bach inactive function is used. For instance, the "mute" attribute is inactive on rests, so inside the bach_inactive_fn() function 
			one should simply check if the element is a rest or not, and then return 1 or 0 accordingly. (This is something, by the way, the default bach inactive function does automatically.)
			
			The bach inspector is external (in a separate window).
			To open the bach inspector for a given element, call the function open_bach_inspector(), to close the bach inspector, use close_bach_inspector().
			Notice that the bach inspector is NOT only for notation items, but also for different things, such as slotinfo.
		@}
		
		@defgroup slots			Slots
		Tools to handle slot-related stuff.
		Slots are the standard bach way to deal with notes metadata. Each note has up to #CONST_MAX_SLOTS slots, which can contain
		different kinds of material, depending on the slot type (see #e_slot_types).
		
		@{
		
			@defgroup filters		Filters
			Tools to handle the filter-typed slots.
			Some slot can be of type filter, which means that they can either contain representations for a single biquad filter, or an 
			interpolated sequence of biquad filters. Here you find the functions to deal with them.
		
		@}


		@defgroup voicenames		Voice Names
		Tools to handle voice names.

	
		@defgroup lyrics		Lyrics
		Tools to handle lyrics.
		Lyrics are linked to a given (text) slot, but do not concide (as memory) with the slot content. 
		They are rather represented by the #t_lyrics structure, representing a piece of lyrics associated to a given chord.
		Whenever the linked slot content is changed, or the lyrics are changed via the interface, everything is kept up to date, which 
		means that the slot and/or the #t_lyrics structure fields are changed accordingly. 
		If a chord has no lyrics, its lyrics field is still defined, but the field #t_label in the #t_lyrics structure will be NULL. 

	
		@defgroup breakpoints		Breakpoints
		Tools to handle breakpoints.


		@defgroup midichannels		Midichannels
		Tools to handle the midichannels.

	
		@defgroup articulations		Articulations
		Tools to handle articulations.

		
		@defgroup lock_solo_mute		Lock, Solo, Mute
		Tools to handle locking, solo-ing or muting elements.


		@defgroup play		Play
		Tools to handle playing.


		@defgroup spectral		Symbolic frequency analysis
		Tools to handle symbolic spectral analysis.
		
		These functions are chiefly used by [bach.rhythmogram], but could be useful to other purposes in the future. 

	
		@defgroup conversions		Conversions
		Tools to handle conversions.


		@defgroup notation_utilities		Notation Utilities
		Various utilities for dealing with symbolic notation.


		@defgroup notation_graphics		Notation Graphic
		Tools to handle the notation graphic material.
		
		@{
		
			@defgroup typographical		Typography
			Tools to handle typographical stuff.
	
			@defgroup notation_paint		Notation Painting
			High level functions to paint notation objects.

			@defgroup slot_graphic			Slot Graphic
			High level functions to handle slot graphic and paint.

			@defgroup notation_text			Notation Text Writing
			High level functions to write text inside notation UI objects.

			@defgroup notation_colors		Notation Colors
			High level tools to handle notation colors.
		
		@}
	
	@}

	@defgroup miscellanea	Miscellanea
	Everything that could not be put in any of the previous categories.
 */
