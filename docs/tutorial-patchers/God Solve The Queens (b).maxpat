{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 54.0, 44.0, 709.0, 389.0 ],
		"bglocked" : 0,
		"defrect" : [ 54.0, 44.0, 709.0, 389.0 ],
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
					"text" : "Small",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 38.0, 293.482819, 37.0, 18.0 ],
					"numoutlets" : 0,
					"id" : "obj-42",
					"fontsize" : 10.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Small",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 7.0, 291.482819, 42.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-41",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The last couple of inlet/outlet will be needed to concretely define the constraints, in a lambda-cycle, as you often may have seen inside the bach framework",
					"linecount" : 5,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 507.0, 264.0, 196.0, 75.0 ],
					"numoutlets" : 0,
					"id" : "obj-40",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 484.0, 264.0, 25.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-38",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 383.0, 212.0, 19.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-36",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we'll tell on which constraints have to be defined on which variables ",
					"linecount" : 2,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 420.0, 220.0, 236.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-35",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 383.0, 245.0, 21.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-33",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 383.0, 237.0, 19.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-34",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 383.0, 228.0, 21.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-32",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here we'll enter the information about the domain of each variable",
					"linecount" : 2,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 381.0, 186.0, 222.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-30",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 422.0, 245.0, 19.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-27",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "v",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 383.0, 220.0, 19.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-26",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "(                          small note: since [bach.constraints] is more general than our [bach.comb] or [bach.urn] usage, this also entails that sometimes it could be slower. In other words: sometimes we might have more efficients way to solve a constraint satisfaction problem than [bach.constraints], but this should really be of secondary importance to you, right now. If ever you'll have too long computations with [bach.constraints], at that moment you might want to restate the problem differently, or even by using different objects.)",
					"linecount" : 5,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 295.482819, 426.0, 52.0 ],
					"numoutlets" : 0,
					"id" : "obj-25",
					"fontsize" : 8.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.constraints",
					"numinlets" : 3,
					"fontname" : "Arial",
					"patching_rect" : [ 380.0, 264.0, 98.0, 20.0 ],
					"numoutlets" : 3,
					"id" : "obj-23",
					"outlettype" : [ "", "float", "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Well, well... we're lucky! In the bach library, there's an object in charge for solving this precise class of problems (so called CSP: constraint satisfaction problems). Its name is [bach.constraints].",
					"linecount" : 2,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 149.0, 696.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-22",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The point is: we'd really love to have an easy way to state the problem, to define the domains of each variable, and to formalize the constraints. Then, all we'd have to do is to wait for a solution! And what a marvel would be if we could formalize our constraints by simple patching!... ",
					"linecount" : 3,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 101.0, 696.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-29",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The basic idea behind [bach.constraints] is that all you have to do is properly define domain and constraints. Once you've done this, the object takes fully in charge all the combinatorial work which we did ourselves before (with [bach.comb] or [bach.urn]). That is: once we have a standard way to define problems, we don't have to bother about which objects are the best to achieve the result: we just use bach.constraints, as a more general tool!",
					"linecount" : 7,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 190.0, 360.0, 103.0 ],
					"numoutlets" : 0,
					"id" : "obj-21",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 229.0, 357.0, 81.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-19",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 b \"God Solve The Queens\"",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 228.5, 412.0, 289.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-39",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 228.5, 384.5, 69.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-15",
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0,
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Conditions (constraints) might be more complicate than the ones we have seen, and one might of course ask for more than one condition on the same set of data. For instance, we might want to find a sequence of non-repeated notes, in which there are NO intervals of fifth. If we are smart enough, we can find a way to achieve this by modifying the previous example. Yet, what if we asked to find a sequence of non-repeated notes where all the melodic intervals are different? ",
					"linecount" : 4,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 39.0, 696.0, 62.0 ],
					"numoutlets" : 0,
					"id" : "obj-16",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "How would we solve the previous problems using [bach.constraints]?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 351.0, 352.0, 224.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-256",
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
					"fontname" : "Arial",
					"patching_rect" : [ 3.0, 16.0, 444.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-49",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- meet bach.constraints",
					"numinlets" : 1,
					"fontname" : "Arial Italic",
					"patching_rect" : [ 280.0, 6.74086, 313.0, 26.0 ],
					"numoutlets" : 0,
					"id" : "obj-50",
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "God Solve The Queens (b)",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 1.924051, 293.0, 32.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 489.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-1",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 464.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-2",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 439.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-3",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "God Solve The Queens [a]",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 414.0, 152.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-5",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 389.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-6",
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"numinlets" : 1,
					"fontname" : "Arial",
					"text" : "Back to section (a)",
					"patching_rect" : [ 5.0, 364.0, 151.0, 20.0 ],
					"numoutlets" : 3,
					"id" : "obj-8",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 554.0, 489.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-9",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 554.0, 464.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-10",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 554.0, 439.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-11",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "God Solve The Queens [c]",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 554.0, 414.0, 151.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-14",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 554.0, 389.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-17",
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"numinlets" : 1,
					"fontname" : "Arial",
					"text" : "Continue to section (c)",
					"patching_rect" : [ 554.0, 364.0, 151.0, 20.0 ],
					"numoutlets" : 3,
					"id" : "obj-20",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 1 ],
					"destination" : [ "obj-14", 0 ],
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
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 1 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [ 238.0, 438.0, 222.0, 438.0, 222.0, 379.5, 238.0, 379.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
