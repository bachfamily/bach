{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 151.0, 44.0, 791.0, 515.0 ],
		"bglocked" : 0,
		"defrect" : [ 151.0, 44.0, 791.0, 515.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "closed bracket is incorporated in the \"...\" symbol, it is no more a valid llll for any of the bach objects. Thus, always pay attention to add a space BEFORE and AFTER each \" (double quote).",
					"linecount" : 3,
					"presentation_rect" : [ 8.0, 434.0, 0.0, 0.0 ],
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 431.0, 402.0, 48.0 ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : ", which is quite a big mess, since (as the",
					"presentation_rect" : [ 544.0, 412.0, 0.0, 0.0 ],
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 544.0, 412.0, 225.0, 20.0 ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.length",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 414.0, 435.0, 73.0, 20.0 ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"outlettype" : [ "int" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : ". What would it happen if we removed the final space",
					"presentation_rect" : [ 474.0, 394.0, 0.0, 0.0 ],
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 474.0, 394.0, 293.0, 20.0 ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[name \"Odd one out!]\"",
					"presentation_rect" : [ 343.0, 413.0, 0.0, 0.0 ],
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 414.0, 413.0, 130.0, 18.0 ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "right before the last bracket? Well, Max would rewrite the message like this:",
					"presentation_rect" : [ 8.0, 412.0, 0.0, 0.0 ],
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 412.0, 411.0, 20.0 ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[name \"Odd one out!\" ]",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 343.0, 395.0, 133.0, 18.0 ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Tip: be careful while writing in a Max message something like ",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 394.0, 344.0, 20.0 ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print 3rdSlot",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 240.0, 320.0, 105.0, 20.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print 4thSlot",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 299.0, 350.0, 104.0, 20.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys 3 4 @maxdepth 2",
					"numinlets" : 1,
					"numoutlets" : 3,
					"patching_rect" : [ 240.0, 293.0, 163.0, 20.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "bang" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys slots",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 240.0, 268.0, 93.0, 20.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"outlettype" : [ "", "bang" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Try to open the 4th slot now, and add some values. Again, values have been replaced by words, but beware! Exactly as the units of measurements, all representation are just a matter of screen display! The slot content is still numbers; indeed, if you play or evaluate the note, you'll realize that no symbol comes out in the 3rd or 4th slot  slot content.",
					"linecount" : 9,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 255.0, 232.0, 131.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.tree",
					"numinlets" : 1,
					"hinset" : 12.179997,
					"textdecayfactor" : 0.92,
					"maxdepth" : 4,
					"numoutlets" : 3,
					"patching_rect" : [ 410.0, 253.0, 368.0, 91.0 ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "" ],
					"firsteleminllllisllllname" : 1,
					"fontsize" : 12.0,
					"bgcolor" : [ 0.933333, 0.894118, 0.894118, 1.0 ],
					"whole_tree_data_0000000000" : [ "(", "slotinfo", "(", 3, "(", "name", "loop on/off", ")", "(", "type", "int", ")", "(", "range", 0, 1, ")", "(", "representation", "(", "Loop Off", "Loop On", ")", ")", ")", ")" ],
					"whole_tree_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[slotinfo [4 [name \"Odd one out!\" ] [type intlist] [range 1 5] [representation [John George Ringo Yoko Paul]]]]",
					"linecount" : 2,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 391.0, 201.0, 332.0, 32.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If now you open the slot window for the 3rd slot, you'll notice that words have replaced numbers.\nAnd you can surely think about something more complicated, such as this 4th slot:",
					"linecount" : 4,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 391.0, 137.0, 285.0, 62.0 ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[ slotinfo [ 3 [name \"loop on/off\" ] [type int] [range 0 1] [representation [ \"Loop Off\" \"Loop On\" ]]]]",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 11.0, 102.0, 524.0, 18.0 ],
					"id" : "obj-58",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"automessage" : [  ],
					"voicespacing" : [ -5.142858, 6.714285 ],
					"numinlets" : 6,
					"zoom" : 34.960938,
					"popupmenuslots" : [  ],
					"numoutlets" : 8,
					"patching_rect" : [ 11.0, 127.0, 374.0, 118.619049 ],
					"bgslots" : [  ],
					"id" : "obj-27",
					"versionnumber" : 6500,
					"fontname" : "Arial",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"velocityhandling" : 1,
					"fontsize" : 12.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop on/off", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "Loop Off", "Loop On", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "Odd one out!", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075052544, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "John", "George", "Ringo", "Yoko", "Paul", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513472, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 4570, 1070597716, "_x_x_x_x_bach_float64_x_x_x_x_", 37944, -1070178866, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 54195, 1070973895, "_x_x_x_x_bach_float64_x_x_x_x_", 4992, -1074241224, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56251, 1071367987, "_x_x_x_x_bach_float64_x_x_x_x_", 33264, -1071087937, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 35486, 1071775028, "_x_x_x_x_bach_float64_x_x_x_x_", 12640, 1074965670, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 37542, 1072169120, "_x_x_x_x_bach_float64_x_x_x_x_", 12640, 1074965670, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", "(", 4, 3, 4, ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 216.0, 539.0, 81.0, 18.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 o \"Slot Machines\"",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 216.0, 591.5, 190.0, 20.0 ],
					"id" : "obj-198",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 216.0, 564.0, 69.0, 20.0 ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Good, fine, but slots keep being a volatile entity: I don't see them, I don't hear them!",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 392.0, 475.0, 231.0, 34.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- more representations",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 187.0, 7.74086, 244.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (o)",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 2.924051, 184.0, 32.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We have seen the utility of having a \"represantation\" slot carrying an unit of measurement information. There are cases, though, where one uses integer values to mean some specific concepts or properties, which would better explained by words than by numbers. It is the case of our 3rd slot, which was a \"loop on/off\" slot: we might want to show the \"Loop On\" and \"Loop Off\" words instead of 0 and 1, in the slot window. We can do this by assigning as representation an llll containing those labels:",
					"linecount" : 4,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 40.0, 765.0, 62.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 610.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 585.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 560.0, 140.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines [n]",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 535.0, 140.0, 18.0 ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 5.0, 510.0, 40.0, 20.0 ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"numinlets" : 1,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Back to section (n)",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numoutlets" : 3,
					"patching_rect" : [ 5.0, 485.0, 151.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "int" ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 632.0, 610.0, 140.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 632.0, 585.0, 140.0, 20.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 632.0, 560.0, 140.0, 20.0 ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines [p]",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 632.0, 535.0, 140.0, 18.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 632.0, 510.0, 40.0, 20.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"numinlets" : 1,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Continue to section (p)",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numoutlets" : 3,
					"patching_rect" : [ 632.0, 485.0, 151.0, 20.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "int" ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 1 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 1 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 225.5, 617.5, 207.5, 617.5, 207.5, 559.0, 225.5, 559.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-90", 0 ],
					"destination" : [ "obj-198", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 6 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"color" : [ 0.639216, 0.105882, 0.105882, 0.403922 ],
					"midpoints" : [ 20.5, 123.0, 6.0, 123.0, 6.0, 250.0, 419.5, 250.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"color" : [ 0.639216, 0.105882, 0.105882, 0.403922 ],
					"midpoints" : [ 400.5, 237.0, 419.5, 237.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 400.5, 237.0, 387.5, 237.0, 387.5, 123.0, 20.5, 123.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 1 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [ 321.5, 315.0, 349.0, 315.0, 349.0, 345.0, 308.5, 345.0 ]
				}

			}
 ]
	}

}
