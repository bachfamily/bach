{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 181.0, 44.0, 788.0, 434.0 ],
		"bglocked" : 0,
		"defrect" : [ 181.0, 44.0, 788.0, 434.0 ],
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
					"maxclass" : "message",
					"text" : "foo fee",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 228.0, 110.0, 47.0, 18.0 ],
					"id" : "obj-21",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we need to retrieve the \"C\" and not a part of the title! So our maxdepth has to be 2.",
					"linecount" : 4,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 534.0, 147.0, 150.0, 62.0 ],
					"id" : "obj-55",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "As usual, you can narrow the scope of the object by using the maxdepth and mindepth attributes:",
					"linecount" : 2,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 364.0, 88.0, 300.0, 34.0 ],
					"id" : "obj-53",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[pitch E] [title [key and lock]] [key C] [tempo 120]",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 365.0, 122.0, 273.0, 18.0 ],
					"id" : "obj-51",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "bang if nothing has been found",
					"linecount" : 2,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 210.0, 164.0, 118.0, 34.0 ],
					"id" : "obj-49",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 511.0, 176.0, 20.0, 20.0 ],
					"id" : "obj-38"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print found",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 365.0, 176.0, 97.0, 20.0 ],
					"id" : "obj-25",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys key @maxdepth 2",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 365.0, 151.0, 165.0, 20.0 ],
					"id" : "obj-44",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "For each key, only the first matching list is output. If no match has been found, a bang is output from the right outlet. So, be sure that you get the right match, possibly narrowing the scope via the @maxdepth and @mindepth attributes!",
					"linecount" : 2,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 12.0, 217.0, 716.0, 34.0 ],
					"id" : "obj-47",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 187.0, 164.0, 20.0, 20.0 ],
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print m",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 127.0, 164.0, 47.0, 20.0 ],
					"id" : "obj-35",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print s",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 67.0, 164.0, 42.0, 20.0 ],
					"id" : "obj-36",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print k",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 164.0, 42.0, 20.0 ],
					"id" : "obj-99",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys kirk spock mccoy @out t",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "bang" ],
					"patching_rect" : [ 7.0, 134.0, 199.0, 20.0 ],
					"id" : "obj-37",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[kirk 1 2 3 [spock 4 5 6]] [mccoy 7 8 9] [doctor mccoy] [kirk is the captain]",
					"linecount" : 2,
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 7.0, 93.0, 213.0, 32.0 ],
					"id" : "obj-33",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Via [bach.keys], one can easily plan a llll-messages routing systems in order to handle real time events. As an example consider the following scheme:",
					"linecount" : 2,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 13.0, 255.0, 568.0, 34.0 ],
					"id" : "obj-31",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : ";\rfwd [to_john 11] [to_george [attracts me like] [no other]] [to_ringo 7 7 7 7]",
					"linecount" : 2,
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 331.0, 403.0, 32.0 ],
					"id" : "obj-29",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print ToRingo",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 663.0, 366.0, 110.0, 20.0 ],
					"id" : "obj-28",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print ToGeorge",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 586.0, 341.0, 119.0, 20.0 ],
					"id" : "obj-27",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"patching_rect" : [ 509.0, 339.0, 50.0, 20.0 ],
					"id" : "obj-26",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys to_john to_george to_ringo @out t",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "bang" ],
					"patching_rect" : [ 509.0, 314.0, 250.0, 20.0 ],
					"id" : "obj-24",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r fwd",
					"numinlets" : 0,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 509.0, 289.0, 37.0, 20.0 ],
					"id" : "obj-23",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : ";\rfwd [to_john 20] [to_george [something in the air] [she moves]] [to_ringo 8 pus [garden]]",
					"linecount" : 2,
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 294.0, 483.0, 32.0 ],
					"id" : "obj-22",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 238.5, 402.0, 81.0, 18.0 ],
					"id" : "obj-89",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 t Iterations",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 238.5, 454.5, 152.0, 20.0 ],
					"id" : "obj-198",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 238.5, 427.0, 69.0, 20.0 ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Just for this?",
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numoutlets" : 0,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"patching_rect" : [ 551.0, 408.0, 79.0, 20.0 ],
					"id" : "obj-61",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- keying data",
					"numinlets" : 1,
					"fontsize" : 16.787033,
					"numoutlets" : 0,
					"patching_rect" : [ 132.0, 7.74086, 292.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Iterations (t)",
					"numinlets" : 1,
					"fontsize" : 22.256727,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 142.0, 32.0 ],
					"id" : "obj-3",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Another very useful object is [bach.keys]: it scans a llll and all its sublists for lists whose first element matches one of the requested keys. Typically, it plays the role of a [route] object to handle complex llll data. For example, one could imagine",
					"linecount" : 2,
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 43.0, 669.0, 34.0 ],
					"id" : "obj-13",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 534.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 509.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 484.0, 140.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Iterations [s]",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 459.0, 140.0, 18.0 ],
					"id" : "obj-7",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 434.0, 40.0, 20.0 ],
					"id" : "obj-8",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"patching_rect" : [ 5.0, 409.0, 151.0, 20.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"text" : "Back to section (s)",
					"id" : "obj-10",
					"fontname" : "Arial",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 633.0, 534.0, 140.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 633.0, 509.0, 140.0, 20.0 ],
					"id" : "obj-12",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 633.0, 484.0, 140.0, 20.0 ],
					"id" : "obj-14",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Iterations [u]",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 633.0, 459.0, 140.0, 18.0 ],
					"id" : "obj-16",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 633.0, 434.0, 40.0, 20.0 ],
					"id" : "obj-17",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"patching_rect" : [ 633.0, 409.0, 151.0, 20.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"text" : "Continue to section (u)",
					"id" : "obj-19",
					"fontname" : "Arial",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-89", 0 ],
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
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-89", 0 ],
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
					"source" : [ "obj-90", 0 ],
					"destination" : [ "obj-198", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 248.0, 480.5, 230.0, 480.5, 230.0, 422.0, 248.0, 422.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-89", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 1 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 2 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-99", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 3 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 2 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 1 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 1 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-51", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
