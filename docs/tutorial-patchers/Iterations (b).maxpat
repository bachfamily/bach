{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 274.0, 51.0, 715.0, 562.0 ],
		"bglocked" : 0,
		"defrect" : [ 274.0, 51.0, 715.0, 562.0 ],
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
					"text" : "(also as argument)",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 600.0, 140.0, 109.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-39",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "number of times",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 601.0, 126.0, 97.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-38",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 551.0, 126.0, 50.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"id" : "obj-36",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print Repeated",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 399.0, 175.0, 119.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-33",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[1 [20 40]] [55 [66]] 44",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 399.0, 126.0, 133.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-32",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.repeat 5",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 399.0, 151.0, 171.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-30",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Moreover, for very simple iterative tasks you might find some other useful bach objects. For example, should you need just to repeat an incoming llll a certain number of times, consider using [bach.repeat]:",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 139.0, 384.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-26",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"patching_rect" : [ 92.0, 333.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"patching_rect" : [ 420.0, 334.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"id" : "obj-31"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "So we have seen that the standard configuration for a bach iteration exactly imitates the behaviour of the ordinary Max iteration: some preliminary tasks (cleaning up the collector, preparing the final bang), an element-wise iteration, some modifications, and the collection of the elements. Finally, a bang to the collector.\nNotice only these two little differences:\n- the clearing of the collector is NOT performed by sending a \"zlclear\" in the first inlet, but by sending a \"clear\" to the right inlet.\n- banging again [bach.collect] will always return the last collected list, unlike [zl group], which is emptied by a bang.",
					"linecount" : 6,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 431.0, 682.0, 89.0 ],
					"numoutlets" : 0,
					"id" : "obj-29",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "In these simple cases, iterations are elementary, but non trivial, and expr-like objects cannot be of any help.",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 409.0, 645.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-28",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "or, in the bach-version:",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 262.0, 296.0, 132.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-27",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t i i",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 468.0, 332.0, 32.5, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"id" : "obj-25",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t i i",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 154.0, 326.0, 32.5, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"id" : "obj-24",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[1 [20 40]] [55 [66]] 44",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 440.0, 255.0, 133.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-23",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.iter @out t",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 468.0, 308.0, 95.0, 20.0 ],
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"id" : "obj-117",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.collect",
					"fontsize" : 12.0,
					"numinlets" : 3,
					"patching_rect" : [ 440.0, 359.0, 74.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-119",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print NewList",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 440.0, 384.0, 109.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-121",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b l clear",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 440.0, 278.0, 74.0, 20.0 ],
					"numoutlets" : 3,
					"outlettype" : [ "bang", "", "clear" ],
					"id" : "obj-122",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zl iter 1",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 154.0, 302.0, 49.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"id" : "obj-114",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zl group",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 110.0, 356.0, 53.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"id" : "obj-110",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1 20 40 55 66 44",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 110.0, 254.0, 101.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-107",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print NewList",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 110.0, 384.0, 80.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-108",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b l zlclear",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 110.0, 278.0, 107.0, 20.0 ],
					"numoutlets" : 3,
					"outlettype" : [ "bang", "", "zlclear" ],
					"id" : "obj-109",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "a a b b c c d d ...",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 249.0, 212.0, 99.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-15",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "a b c d ...",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 30.0, 211.0, 60.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-14",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "What we want to say is that iterations can be much more general than those simple ones. Imagine that, starting from a list                     one wanted to build a list like                               . This cannot be done via [vexpr] or [bach.expr], thus one has to do something like:",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 197.0, 645.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-11",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print NewList",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 492.0, 97.0, 80.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-128",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.+ 10 @out t",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 492.0, 71.0, 102.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-129",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[1 [20 40]] [55 [66]] 44",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 492.0, 49.0, 133.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-130",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print NewList",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 364.0, 97.0, 80.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-127",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "vexpr $i1 + 10",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 364.0, 71.0, 86.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-126",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1 20 40 55 66 44",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 364.0, 49.0, 101.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-125",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 239.5, 584.0, 81.0, 18.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-89",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 b Iterations",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 239.5, 636.5, 155.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-198",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 239.5, 609.0, 69.0, 20.0 ],
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "", "" ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Why on earth has [bach.iter] one outlet more than [iter]?",
					"linecount" : 2,
					"fontsize" : 12.0,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"patching_rect" : [ 369.0, 523.0, 169.0, 34.0 ],
					"numoutlets" : 0,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"fontface" : 2
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
					"text" : "- expr is not (always) the solution",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"patching_rect" : [ 137.0, 7.74086, 256.0, 26.0 ],
					"numoutlets" : 0,
					"id" : "obj-2",
					"fontname" : "Arial Italic"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Iterations (b)",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 2.924051, 135.0, 32.0 ],
					"numoutlets" : 0,
					"id" : "obj-3",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Well, yes: you could have used [vexpr] or [bach.+] to obtain the same results, but only because both [vexpr] and [bach.+] has an engine which is able to perform a certain kind of iterations (in the case of [bach.+], this engine is [bach.expr], which is inside the abstraction).",
					"linecount" : 5,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 43.0, 340.0, 75.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB[1]",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 533.0, 551.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-67",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB[2]",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 533.0, 551.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-75",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 662.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-1",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 637.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-4",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 612.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-5",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Iterations [a]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 5.0, 587.0, 140.0, 18.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-7",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 562.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-8",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"fontsize" : 12.0,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 537.0, 151.0, 20.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"numoutlets" : 3,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"text" : "Back to section (a)",
					"fontface" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 560.0, 662.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-12",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 560.0, 637.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-16",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 560.0, 612.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-17",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Iterations [c]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 560.0, 587.0, 140.0, 18.0 ],
					"numoutlets" : 1,
					"hidden" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-19",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 560.0, 562.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"hidden" : 1,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-20",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"fontsize" : 12.0,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"patching_rect" : [ 560.0, 537.0, 151.0, 20.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"numoutlets" : 3,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"text" : "Continue to section (c)",
					"fontface" : 2
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-89", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
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
					"source" : [ "obj-20", 1 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-20", 0 ],
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
					"midpoints" : [ 249.0, 662.5, 231.0, 662.5, 231.0, 604.0, 249.0, 604.0 ]
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
					"source" : [ "obj-125", 0 ],
					"destination" : [ "obj-126", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-126", 0 ],
					"destination" : [ "obj-127", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-129", 0 ],
					"destination" : [ "obj-128", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-130", 0 ],
					"destination" : [ "obj-129", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-107", 0 ],
					"destination" : [ "obj-109", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-110", 0 ],
					"destination" : [ "obj-108", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-109", 1 ],
					"destination" : [ "obj-114", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-109", 0 ],
					"destination" : [ "obj-110", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-109", 2 ],
					"destination" : [ "obj-110", 0 ],
					"hidden" : 0,
					"color" : [ 0.0, 0.65098, 1.0, 1.0 ],
					"midpoints" : [ 207.5, 354.0, 119.5, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-122", 0 ],
					"destination" : [ "obj-119", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-122", 1 ],
					"destination" : [ "obj-117", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-122", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-119", 0 ],
					"destination" : [ "obj-121", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-122", 2 ],
					"destination" : [ "obj-119", 2 ],
					"hidden" : 0,
					"color" : [ 0.0, 0.65098, 1.0, 1.0 ],
					"midpoints" : [ 504.5, 303.0, 571.0, 303.0, 571.0, 351.0, 504.5, 351.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-117", 2 ],
					"destination" : [ "obj-119", 2 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-114", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-110", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 1 ],
					"destination" : [ "obj-110", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-117", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-119", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 1 ],
					"destination" : [ "obj-119", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-119", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-110", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-30", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
