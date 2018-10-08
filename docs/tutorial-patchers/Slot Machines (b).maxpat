{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 27.0, 56.0, 894.0, 337.0 ],
		"bglocked" : 0,
		"defrect" : [ 27.0, 56.0, 894.0, 337.0 ],
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
					"text" : "Possible slot type:",
					"id" : "obj-31",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 262.0, 105.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Want to store:",
					"id" : "obj-32",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 229.0, 94.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[note [ \"playing style\" text] [ \"treatment routing system\" togglematrix floatmatrix] [ \"FM modulant frequency\" float] [ \"RGBA note color\" floatlist] [ \"notehead information\" long] ]",
					"linecount" : 2,
					"outlettype" : [ "" ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"patching_rect" : [ 140.0, 189.0, 581.0, 32.0 ],
					"numinlets" : 2,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.tree",
					"outlettype" : [ "", "", "" ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"firsteleminllllisllllname" : 1,
					"patching_rect" : [ 108.0, 188.0, 770.0, 95.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"bgcolor" : [ 0.94902, 0.94902, 0.94902, 1.0 ],
					"numoutlets" : 3,
					"whole_tree_data_0000000000" : [ "(", "note", "(", "playing style", "text", ")", "(", "treatment routing system", "togglematrix", "floatmatrix", ")", "(", "FM modulant frequency", "float", ")", "(", "RGBA note color", "floatlist", ")", "(", "notehead information", "long", ")", ")" ],
					"whole_tree_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Possible slot type:",
					"id" : "obj-28",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 152.0, 105.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Want to store:",
					"id" : "obj-27",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 119.0, 94.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[note [lyrics text] [ \"amplitude envelope\" function] [ \"soundfile to play\" filelist] [ \"panning path\" float spat] [ \"a whole score\" llll] [ \"synth parameters\" intlist floatlist text llll] [ \"freqshift amount\" float ] ]",
					"linecount" : 2,
					"outlettype" : [ "" ],
					"id" : "obj-18",
					"fontname" : "Arial",
					"patching_rect" : [ 108.0, 82.0, 585.0, 32.0 ],
					"numinlets" : 2,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.tree",
					"outlettype" : [ "", "", "" ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"firsteleminllllisllllname" : 1,
					"patching_rect" : [ 108.0, 78.0, 770.0, 95.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"bgcolor" : [ 0.94902, 0.94902, 0.94902, 1.0 ],
					"numoutlets" : 3,
					"whole_tree_data_0000000000" : [ "(", "note", "(", "lyrics", "text", ")", "(", "amplitude envelope", "function", ")", "(", "soundfile to play", "filelist", ")", "(", "panning path", "float", "spat", ")", "(", "a whole score", "llll", ")", "(", "synth parameters", "intlist", "floatlist", "text", "llll", ")", "(", "freqshift amount", "float", ")", ")" ],
					"whole_tree_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"outlettype" : [ "" ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"patching_rect" : [ 318.0, 331.0, 81.0, 18.0 ],
					"numinlets" : 2,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 b \"Slot Machines\"",
					"outlettype" : [ "" ],
					"id" : "obj-198",
					"fontname" : "Arial",
					"patching_rect" : [ 318.0, 383.5, 190.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"outlettype" : [ "", "" ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"patching_rect" : [ 318.0, 356.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 2,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "I'm glad there are so many things to store, but how the hell do I store them?!?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"patching_rect" : [ 498.0, 294.0, 228.0, 34.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"id" : "obj-87",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- a type for each need",
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"patching_rect" : [ 187.0, 7.74086, 477.0, 26.0 ],
					"numinlets" : 1,
					"fontsize" : 16.787033,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (b)",
					"id" : "obj-3",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 2.924051, 184.0, 32.0 ],
					"numinlets" : 1,
					"fontsize" : 22.256727,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The slot content can be of various types, depending of what you need to store inside it. Here you find some possibilities of common stuff that a slot might contain, with the related required slot type for the slot.",
					"linecount" : 2,
					"id" : "obj-13",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 41.0, 718.0, 34.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"outlettype" : [ "" ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 437.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"outlettype" : [ "" ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 412.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"outlettype" : [ "" ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 387.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines [a]",
					"outlettype" : [ "" ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 362.0, 140.0, 18.0 ],
					"numinlets" : 2,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 337.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"text" : "Back to section (a)",
					"id" : "obj-36",
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 5.0, 312.0, 151.0, 20.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"outlettype" : [ "" ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"patching_rect" : [ 739.0, 437.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"outlettype" : [ "" ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"patching_rect" : [ 739.0, 412.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"outlettype" : [ "" ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"patching_rect" : [ 739.0, 387.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines [c]",
					"outlettype" : [ "" ],
					"id" : "obj-41",
					"fontname" : "Arial",
					"patching_rect" : [ 739.0, 362.0, 140.0, 18.0 ],
					"numinlets" : 2,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-42",
					"fontname" : "Arial",
					"patching_rect" : [ 739.0, 337.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"fontsize" : 12.0,
					"hidden" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"text" : "Continue to section (c)",
					"id" : "obj-44",
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 739.0, 312.0, 151.0, 20.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 1 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 1 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 327.5, 409.5, 309.5, 409.5, 309.5, 351.0, 327.5, 351.0 ]
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
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
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
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
