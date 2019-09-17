{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 246.0, 47.0, 849.0, 475.0 ],
		"bglocked" : 0,
		"defrect" : [ 246.0, 47.0, 849.0, 475.0 ],
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
					"text" : "Right click on the bpatcher, then choose Object and click on \"New View...\" in order to see the bpatcher patcher, properly commented!",
					"id" : "obj-38",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 298.0, 734.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "function_width = pixel_width_of_the_whole_roll's_length = total_length * domain / domain_pixels\nfunction_offset = (domain_start / total_length) * function_width",
					"linecount" : 2,
					"id" : "obj-28",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 108.0, 392.0, 525.0, 34.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Since we have the \"getlength\", \"getdomain\" and \"getdomainpixels\" commands, we can retrieve the total length of the roll, the domain and the pixel width of the domain. This will help us calculating the needed values:",
					"linecount" : 2,
					"id" : "obj-24",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 357.0, 711.0, 34.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "via the patching_rect message we handle the function stretch, i.e. we change its y-width (all the remaining values will not change: they refer to the position of the function within the bpatcher patch)",
					"linecount" : 4,
					"id" : "obj-21",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 539.0, 155.0, 276.0, 62.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"id" : "obj-31",
					"fontname" : "Arial",
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 183.0, 50.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"id" : "obj-22",
					"fontname" : "Arial",
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"patching_rect" : [ 377.0, 156.0, 50.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "slider",
					"size" : 3000.0,
					"id" : "obj-11",
					"outlettype" : [ "" ],
					"patching_rect" : [ 377.0, 136.0, 232.0, 17.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "patching_rect 0. 217. $1 63.",
					"id" : "obj-30",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"patching_rect" : [ 377.0, 179.0, 159.0, 18.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "via the offset message we'll shift the function properly (217 is the vertical position of the function in the bpatcher patch)",
					"linecount" : 3,
					"id" : "obj-29",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 90.0, 178.0, 252.0, 48.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "- 600",
					"id" : "obj-27",
					"fontname" : "Arial",
					"outlettype" : [ "int" ],
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 160.0, 38.0, 20.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "slider",
					"size" : 601.0,
					"id" : "obj-26",
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 140.0, 232.0, 17.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "offset $1 -217",
					"id" : "obj-23",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 208.0, 84.0, 18.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bpatcher",
					"id" : "obj-14",
					"offset" : [ 0.0, -217.0 ],
					"name" : "Graphical Synchronization (b) - bpatcher.maxpat",
					"args" : [  ],
					"patching_rect" : [ 5.0, 230.0, 738.0, 64.0 ],
					"numinlets" : 2,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "0 Hz",
					"id" : "obj-20",
					"fontname" : "Arial",
					"fontsize" : 8.913287,
					"patching_rect" : [ 741.0, 253.5, 40.0, 17.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "-500 Hz",
					"id" : "obj-18",
					"fontname" : "Arial",
					"fontsize" : 8.913287,
					"patching_rect" : [ 741.0, 281.5, 40.0, 17.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "500 Hz",
					"id" : "obj-17",
					"fontname" : "Arial",
					"fontsize" : 8.913287,
					"patching_rect" : [ 741.0, 224.5, 40.0, 17.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Try to combine the two sliders, and you see that you can definitely get the results we need. All we need to do is to retrieve and scale properly the function zoom and function offset.",
					"linecount" : 2,
					"id" : "obj-15",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 318.0, 707.0, 34.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Encapsulating the function in a bpatcher object lets us shift it and stretch it if we need. The following function is ",
					"id" : "obj-12",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 105.0, 707.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"id" : "obj-19",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 318.0, 446.0, 81.0, 18.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 b \"Graphical Synchronization\"",
					"id" : "obj-198",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 318.0, 498.5, 254.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"id" : "obj-90",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 318.0, 471.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 2,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "I know how to use a bpatcher. Move on!",
					"linecount" : 2,
					"id" : "obj-61",
					"fontname" : "Arial",
					"fontface" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontsize" : 12.0,
					"patching_rect" : [ 578.0, 441.0, 138.0, 34.0 ],
					"numinlets" : 1,
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
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- use of bpatcher",
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"patching_rect" : [ 304.0, 7.74086, 491.0, 26.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Graphical Synchronization (b)",
					"id" : "obj-3",
					"fontname" : "Arial",
					"fontsize" : 22.256727,
					"patching_rect" : [ 5.0, 2.924051, 304.0, 32.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "First of all, we need a way to see just a portion of our [function] object; more precisely: the part of the function related to the [bach.roll]'s domain.\nThe common Max way to achieve such a result is to use a [bpatcher]. A [bpatcher] allows you to see a portion of an existing patch, and also to scroll this portion when needed (which will be very useful to us).\nSo as a very first thing, we save our function object into another separate patch, called \"Graphical Synchronization (b) - bpatcher.maxpat\".",
					"linecount" : 4,
					"id" : "obj-13",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 43.0, 799.0, 62.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"id" : "obj-1",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 575.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"id" : "obj-4",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 550.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"id" : "obj-5",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 525.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Graphical Synchronization [a]",
					"id" : "obj-7",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 500.0, 167.0, 18.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"id" : "obj-8",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 475.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"id" : "obj-10",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "int" ],
					"fontface" : 2,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 450.0, 151.0, 20.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"numinlets" : 1,
					"text" : "Back to section (a)",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"id" : "obj-16",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 575.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"id" : "obj-25",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 550.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"id" : "obj-32",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 525.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Graphical Synchronization [c]",
					"id" : "obj-34",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 500.0, 166.0, 18.0 ],
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"id" : "obj-35",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 475.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"id" : "obj-37",
					"fontname" : "Arial",
					"outlettype" : [ "", "", "int" ],
					"fontface" : 2,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"fontsize" : 12.0,
					"patching_rect" : [ 694.0, 450.0, 151.0, 20.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"numinlets" : 1,
					"text" : "Continue to section (c)",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 1 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-35", 0 ],
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
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
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
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-14", 1 ],
					"hidden" : 0,
					"midpoints" : [ 386.5, 221.0, 733.5, 221.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 327.5, 524.5, 309.5, 524.5, 309.5, 466.0, 327.5, 466.0 ]
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
 ]
	}

}
