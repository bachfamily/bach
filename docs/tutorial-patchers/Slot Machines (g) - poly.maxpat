{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 512.0, 47.0, 637.0, 544.0 ],
		"bglocked" : 0,
		"defrect" : [ 512.0, 47.0, 637.0, 544.0 ],
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
					"text" : "we transpose with gizmo~",
					"linecount" : 2,
					"numinlets" : 1,
					"presentation_rect" : [ 36.0, 346.0, 0.0, 0.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 37.0, 372.0, 94.0, 34.0 ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "we convert cents into a dilation factor for gizmo~",
					"linecount" : 2,
					"numinlets" : 1,
					"presentation_rect" : [ 216.0, 508.0, 0.0, 0.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 161.0, 348.0, 142.0, 34.0 ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr pow(2.\\,($f1-6000)/1200)",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 158.0, 379.0, 164.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pfft~ gizmo_loadme 2048 4",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 27.0, 405.0, 150.0, 20.0 ],
					"outlettype" : [ "signal" ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~ 1.",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 27.0, 321.0, 78.0, 20.0 ],
					"outlettype" : [ "signal" ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "we rescale velocity",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 93.0, 276.0, 136.0, 20.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale 0 127 0. 1.5 1.06",
					"numinlets" : 6,
					"numoutlets" : 1,
					"patching_rect" : [ 86.0, 294.0, 132.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "pick removes automatically the first ( ... ) level if any",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 343.0, 71.0, 291.0, 20.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we have the filelist content",
					"numinlets" : 1,
					"presentation_rect" : [ 294.0, 97.0, 0.0, 0.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 294.0, 99.0, 179.0, 20.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "duration turns off the system when needed",
					"linecount" : 5,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 184.0, 95.0, 69.0, 75.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b f",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 145.0, 98.0, 38.5, 20.0 ],
					"outlettype" : [ "bang", "float" ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "delay",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 145.0, 125.0, 39.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t 1 l b",
					"numinlets" : 1,
					"numoutlets" : 3,
					"patching_rect" : [ 262.0, 209.0, 46.0, 20.0 ],
					"outlettype" : [ "int", "", "bang" ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend open",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 262.0, 184.0, 85.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we recover the active file path!",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 357.0, 154.0, 156.0, 34.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "last element is the active file index",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 350.0, 117.0, 150.0, 34.0 ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.pick -1",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 276.0, 123.0, 75.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.nth @out t",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 262.0, 160.0, 95.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t l l",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 262.0, 99.0, 32.5, 20.0 ],
					"outlettype" : [ "", "" ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "sfplay~",
					"numinlets" : 2,
					"numoutlets" : 2,
					"patching_rect" : [ 27.0, 294.0, 49.0, 20.0 ],
					"outlettype" : [ "signal", "bang" ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"save" : [ "#N", "sfplay~", "", 1, 120960, 0, "", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "automatic mute/busy state handling",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 456.0, 357.0, 125.0, 34.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we have: midicents, velocity, duration, amplitude envelope, filenames, loop",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 37.0, 37.0, 320.0, 34.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "we turn on and off the adsr",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 391.0, 269.0, 158.0, 20.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "As you might notice, we are completely ignoring the amplitude envelope, up to this point. Don't worry, we'll get there very soon.",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 24.0, 493.0, 365.0, 34.0 ],
					"id" : "obj-18",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess mute 1",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 413.0, 340.0, 102.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1.",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 356.0, 270.0, 32.5, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "0.",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 316.0, 270.0, 32.5, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-15",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispoly~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 398.0, 372.0, 58.0, 20.0 ],
					"outlettype" : [ "int", "int" ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 27.0, 441.0, 219.5, 20.0 ],
					"outlettype" : [ "signal" ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "adsr~ 10. 10. 0.8 300.",
					"numinlets" : 5,
					"numoutlets" : 4,
					"patching_rect" : [ 333.0, 299.0, 125.0, 20.0 ],
					"outlettype" : [ "signal", "signal", "", "" ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.pick 1 2 3 4 5 6 @out t",
					"numinlets" : 1,
					"numoutlets" : 6,
					"patching_rect" : [ 27.0, 71.0, 313.0, 20.0 ],
					"outlettype" : [ "", "", "", "", "", "" ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "out~ 1",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 27.0, 468.0, 44.0, 20.0 ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"saved_object_attributes" : 					{
						"attr_comment" : ""
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "in 1",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 27.0, 11.0, 30.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"saved_object_attributes" : 					{

					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "loop $1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 27.0, 264.0, 50.0, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 0.52549 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-34", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 1 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-33", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 5 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"color" : [ 0.113725, 0.964706, 0.003922, 0.388235 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 2 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-8", 1 ],
					"hidden" : 0,
					"midpoints" : [ 342.5, 435.5, 237.0, 435.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 1 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 4 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-10", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 2 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 1 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 2 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 1 ],
					"destination" : [ "obj-26", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
