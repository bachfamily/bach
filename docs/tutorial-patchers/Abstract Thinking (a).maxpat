{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 246.0, 47.0, 756.0, 309.0 ],
		"bglocked" : 0,
		"defrect" : [ 246.0, 47.0, 756.0, 309.0 ],
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
					"text" : "First of all: don't call them \"bach\"",
					"fontsize" : 18.773539,
					"frgb" : [ 0.72549, 0.023529, 0.023529, 1.0 ],
					"numinlets" : 1,
					"textcolor" : [ 0.72549, 0.023529, 0.023529, 1.0 ],
					"patching_rect" : [ 222.0, 91.934067, 282.0, 28.0 ],
					"numoutlets" : 0,
					"id" : "obj-12",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "NOT",
					"fontsize" : 12.0,
					"frgb" : [ 0.72549, 0.023529, 0.023529, 1.0 ],
					"underline" : 1,
					"numinlets" : 1,
					"textcolor" : [ 0.72549, 0.023529, 0.023529, 1.0 ],
					"patching_rect" : [ 417.0, 120.0, 36.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-29",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "As you'll understand, if everybody started to call all his own libraries (or externals) with the names such bach.foo, bach.dothis, bach.ilikethat, we would very quickly arrive to a very confuse and unclear situation. Thus, the name \"bach\" has to remain for the official releases; if you build your own abstractions or libraries, and make them public, just choose some other name!",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 219.0, 681.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-27",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "bach might soon have also a public API (if you don't know what it means, just ignore this paragraph), so if you know how to build an external, you will be able to make it deal with lllls, as any of the bach objects. Yet, it'll be YOUR external!",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 183.0, 711.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-26",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 2,
					"patching_rect" : [ 318.0, 331.0, 81.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-19",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 0 1 a \"Abstract Thinking\"",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 318.0, 383.5, 207.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-198",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 318.0, 356.0, 69.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-90",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "I'm not bach. bach is not me.\nSo who the hell is bach?",
					"linecount" : 2,
					"fontface" : 2,
					"fontsize" : 12.0,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"patching_rect" : [ 430.0, 270.0, 168.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-61",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "As a very first thing - we better say it clearly - we STRONGLY RECOMMEND          to use the \"bach\" name for any of your own libraries or abstractions. Indeed, you might want to spread them or even to get them public, and that would create a big confusion about what's the official bach release, and what's your own library's content. Using bach objects and dealing with lllls doesn't mean, thus, that the object has to have a \"bach\" name. On the contrary.",
					"linecount" : 4,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 120.0, 732.0, 62.0 ],
					"numoutlets" : 0,
					"id" : "obj-20",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-87",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- or how to make good bach abstractions, subpatches, libraries",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"patching_rect" : [ 219.0, 7.74086, 477.0, 26.0 ],
					"numoutlets" : 0,
					"id" : "obj-2",
					"fontname" : "Arial Italic"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Abstract Thinking (a)",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 2.924051, 220.0, 32.0 ],
					"numoutlets" : 0,
					"id" : "obj-3",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The bach library is quite flexible and contains a lot of ready-made abstractions to accomplish some common tasks. Yet, our imagination is damned poor! And you might constantly use a certain process for which there's no bach abstraction ready.\nIn this case you're totally allowed to build an abstraction, or even a set of abstractions (your own library).",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 43.0, 704.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 596.0, 400.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-1",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 596.0, 375.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-4",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 596.0, 350.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-5",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Abstract Thinking (b)",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 2,
					"patching_rect" : [ 596.0, 325.0, 140.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-7",
					"fontname" : "Arial",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"fontsize" : 12.0,
					"hidden" : 1,
					"numinlets" : 1,
					"patching_rect" : [ 596.0, 300.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-8",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"fontface" : 2,
					"fontsize" : 12.0,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numinlets" : 1,
					"patching_rect" : [ 596.0, 275.0, 151.0, 20.0 ],
					"numoutlets" : 3,
					"id" : "obj-10",
					"text" : "Continue to section (b)",
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"outlettype" : [ "", "", "int" ]
				}

			}
 ],
		"lines" : [ 			{
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
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-90", 0 ],
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
 ]
	}

}
