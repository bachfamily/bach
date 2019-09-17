{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 54.0, 44.0, 912.0, 456.0 ],
		"bglocked" : 0,
		"defrect" : [ 54.0, 44.0, 912.0, 456.0 ],
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
					"text" : "Finally, we have to define the rules for each constraint we have formally defined. In practice: [bach.constraints] will try to output from the lambda outlet some values possibilities for the two variables, preceded by the constraints name – well, yes, It is \"physically\" so: you really have messages like \"fifth 6000 6200\" or \"fifth 6000 5900\" coming out from the lambda outlet, put a [bach.print] if you're curious!!\nAll we have to do is then to tell [bach.constraints] if the given configuration is acceptable to us or not: we have to define the RULE for the constraint. In our case, we want that the difference between the two cents (in absolute value) be exactly 700 (mod 1200), so we simply put it into a bach.expr. This will give 1 if the configuration must be accepted, 0 if it must be rejected, which is exactly what [bach.constraints] expect to receive from its lambda inlet (so we just plug it in, paying attention to use the @out t, since the lambda inlet expects an integer value, not a llll)",
					"linecount" : 12,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 388.0, 243.0, 472.0, 172.0 ],
					"numoutlets" : 0,
					"id" : "obj-46",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 367.0, 245.0, 25.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-45",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "In the middle inlet, [bach.constraints] expect a \"formal\" definition of the constraints by assigning a name and a scope. In practice: we need to give a name for each constraints we want to define, followed by a set of variables on which the constraint will act. In our case we just want a single constraint (which we've named \"fifth\"), and we want it to act on the first and second variable, so we append the list \"(1 2)\". The outer level of parenthesis is needed since one might have more than one constraint.",
					"linecount" : 5,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 341.0, 166.0, 565.0, 75.0 ],
					"numoutlets" : 0,
					"id" : "obj-44",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 318.0, 189.0, 25.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-43",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "First of all we need to define how many variables the problem has, and which is the range of possible values (domain) for each variable. In our case, we want to find TWO elements of the list, thus we'll have two variables; and each element can be any element inside the list, so the domain for each variable will be the entire list. What we simply need to input in the left inlet is an llll containing all the domains (one for each variable). In our case, it's simply twice the same domain, so we get by quite easily with [bach.repeat]. Notice that sending the domains will trigger the result, which we DON'T want to do right now, since we have much more to define...",
					"linecount" : 7,
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 332.0, 62.0, 514.0, 103.0 ],
					"numoutlets" : 0,
					"id" : "obj-42",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 306.0, 101.0, 25.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-41",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<< And here we have the solution! (if any)",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 120.0, 376.0, 232.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-38",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Constraint rules",
					"frgb" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 240.0, 259.0, 117.0, 21.0 ],
					"numoutlets" : 0,
					"id" : "obj-34",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Constraint names and scopes",
					"frgb" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 119.0, 188.0, 203.0, 21.0 ],
					"numoutlets" : 0,
					"id" : "obj-33",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Domains",
					"frgb" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 236.0, 121.0, 65.0, 21.0 ],
					"numoutlets" : 0,
					"id" : "obj-29",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print Found",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 10.0, 377.0, 101.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-31",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys fifth",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 89.0, 283.0, 87.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-30",
					"outlettype" : [ "", "bang" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[fifth [1 2]]",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 50.0, 190.0, 66.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-28",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.repeat 2 @inwrap 1",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 10.0, 115.0, 145.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-26",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.expr abs($i2 - $i1) % 1200 == 700 @out t",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 89.0, 334.0, 260.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-37",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.pick 1 2",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 89.0, 307.0, 260.0, 20.0 ],
					"numoutlets" : 2,
					"id" : "obj-35",
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "6000 6200 6300 6500 5900 7200 7300 7800 4000",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 10.0, 93.0, 277.0, 18.0 ],
					"numoutlets" : 1,
					"id" : "obj-24",
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.constraints",
					"numinlets" : 3,
					"fontname" : "Arial",
					"patching_rect" : [ 10.0, 258.0, 98.0, 20.0 ],
					"numoutlets" : 3,
					"id" : "obj-23",
					"outlettype" : [ "", "float", "" ],
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
					"patching_rect" : [ 244.0, 503.0, 81.0, 18.0 ],
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
					"text" : "linksections 1 1 c \"God Solve The Queens\"",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 243.5, 558.0, 288.0, 20.0 ],
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
					"patching_rect" : [ 243.5, 530.5, 69.0, 20.0 ],
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
					"text" : "Let's get back to our example of finding a fifth inside a sequence of pitches, and see how we can solve it with [bach.constraints].",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 39.0, 687.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-16",
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Uhm... there was MORE than one solution to our problem. Why did we get just one? And always the same!",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 421.0, 418.0, 314.0, 34.0 ],
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
					"text" : "- revisiting the first example",
					"numinlets" : 1,
					"fontname" : "Arial Italic",
					"patching_rect" : [ 279.0, 6.74086, 313.0, 26.0 ],
					"numoutlets" : 0,
					"id" : "obj-50",
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "God Solve The Queens (c)",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 1.924051, 292.0, 32.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"numinlets" : 1,
					"border" : 1,
					"patching_rect" : [ 40.0, 181.0, 276.0, 37.0 ],
					"numoutlets" : 0,
					"id" : "obj-25",
					"background" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"numinlets" : 1,
					"border" : 1,
					"patching_rect" : [ 88.0, 245.0, 277.0, 120.0 ],
					"numoutlets" : 0,
					"id" : "obj-22",
					"background" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"numinlets" : 1,
					"border" : 1,
					"patching_rect" : [ 4.0, 85.0, 297.0, 58.0 ],
					"numoutlets" : 0,
					"id" : "obj-21",
					"background" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numinlets" : 1,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 556.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 531.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 506.0, 140.0, 20.0 ],
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
					"text" : "God Solve The Queens [b]",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 481.0, 152.0, 18.0 ],
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
					"patching_rect" : [ 5.0, 456.0, 40.0, 20.0 ],
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
					"text" : "Back to section (b)",
					"patching_rect" : [ 5.0, 431.0, 151.0, 20.0 ],
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
					"patching_rect" : [ 757.0, 556.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 757.0, 531.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 757.0, 506.0, 140.0, 20.0 ],
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
					"text" : "God Solve The Queens [d]",
					"numinlets" : 2,
					"fontname" : "Arial",
					"patching_rect" : [ 757.0, 481.0, 152.0, 18.0 ],
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
					"patching_rect" : [ 757.0, 456.0, 40.0, 20.0 ],
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
					"text" : "Continue to section (d)",
					"patching_rect" : [ 757.0, 431.0, 151.0, 20.0 ],
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
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-23", 2 ],
					"hidden" : 0,
					"midpoints" : [ 98.5, 358.0, 359.5, 358.0, 359.5, 255.0, 98.5, 255.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 2 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-23", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-23", 0 ],
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
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 1 ],
					"destination" : [ "obj-37", 1 ],
					"hidden" : 0,
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
					"midpoints" : [ 253.0, 584.0, 237.0, 584.0, 237.0, 525.5, 253.0, 525.5 ]
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
