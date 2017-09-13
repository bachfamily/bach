{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 37.0, 222.0, 679.0, 498.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 5.0, 5.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"showrootpatcherontab" : 0,
		"showontab" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 679.0, 472.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 69.567627, 651.0, 50.0 ],
									"presentation_rect" : [ 287.0, 45.5, 0.0, 0.0 ],
									"style" : "",
									"text" : "If you provide two arguments (minimum and maximum), and you input an integer list, all elements between min and max are output (even though they have occurrence 0).\nThis is a sort of \"integer\" mode. Use the \"auto\" symbol to automatically compute minimum/maximum.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 215.0, 413.5, 217.0, 40.0 ],
									"style" : "",
									"text" : "The corresponding numbers are output through the right outlet"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 438.0, 432.5, 99.0, 23.0 ],
									"style" : "",
									"text" : "bach.print Data"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-22",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 193.0, 355.5, 250.0, 54.0 ],
									"style" : "",
									"text" : "A histogram of the incoming data is output, telling how many times a given number appears in the original list"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpargs.js",
									"id" : "obj-7",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.histo" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 457.0, 308.0, 182.676926, 69.0 ],
									"presentation_rect" : [ 457.0, 319.0, 182.676926, 69.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.16,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 130.0, 192.0, 55.0 ],
									"style" : "",
									"text" : "Send the list containing integer numbers in the first inlet"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 138.0, 241.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 403.0, 237.0, 84.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 11"
								}

							}
, 							{
								"box" : 								{
									"candycane" : 12,
									"ghostbar" : 30,
									"id" : "obj-25",
									"maxclass" : "multislider",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 365.0, 169.0, 79.0 ],
									"setminmax" : [ 0.0, 12.0 ],
									"size" : 6,
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 403.0, 258.0, 68.0, 21.0 ],
									"style" : "",
									"text" : "maximum",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 208.0, 258.0, 64.0, 21.0 ],
									"style" : "",
									"text" : "minimum",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 450.0, 276.0, 36.0, 23.0 ],
									"style" : "",
									"text" : "auto"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-14",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 256.0, 276.0, 37.0, 23.0 ],
									"style" : "",
									"text" : "auto"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 395.0, 276.0, 53.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 193.0, 276.0, 53.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 138.0, 180.0, 414.0, 84.0 ],
									"style" : "",
									"text" : "Use second and third inlets to define minimum and maximum. Values below minimum and over maximum are not taken into account. \"auto\" (default) uses the list detected minimum or maximum (so that in the resulting list there will be no zeros at the beginning or at the end)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 477.0, 379.5, 192.0, 50.0 ],
									"style" : "",
									"text" : "If no argument is provided, \"auto\" is the default both for minimum and for maximum",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 10.0, 180.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"linecount" : 2,
									"maxclass" : "textedit",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 210.0, 101.0, 59.0 ],
									"style" : "",
									"text" : "1 2 4 4 7 2 11 0 4 4 4 1 "
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 10.0, 276.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "route text"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 10.0, 308.0, 447.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo 0 11 @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.histo" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 220.299164, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-28", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 30.0, 151.0, 99.0, 22.0 ],
					"presentation_rect" : [ 15.0, 126.0, 0.0, 0.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p \"integer mode\"",
					"varname" : "basic_tab[3]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 679.0, 472.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 170.0, 368.0, 136.0, 54.0 ],
									"style" : "",
									"text" : "You can use it in combination with bach.wordcloud"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 315.0, 307.0, 268.0, 23.0 ],
									"style" : "",
									"text" : "buddy"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 315.0, 140.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"linecount" : 8,
									"maxclass" : "textedit",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 315.0, 170.0, 284.0, 54.0 ],
									"style" : "",
									"text" : "Bach Beethoven Mozart Beethoven Mozart Boulez Schönberg Webern Webern Webern Webern Berg Brahms Brahms Mahler Machaut Desprez Perotinus Spontini Iommelli Traetta Schubert Schumann Mendelssohn Brückner Stravinsky Lachenmann Berio Stravinsky Lachenmann Berio  Stravinsky Lachenmann Berio  Ligeti Kurtag Sciarrino Brahms"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 315.0, 236.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "route text"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 315.0, 268.0, 268.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "bach.wordcloud",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 315.0, 340.0, 268.0, 110.0 ],
									"whole_wordcloud_data_0000000000" : [ "(", "Bach", "Beethoven", "Berg", "Berio", "Boulez", "Brahms", "Brückner", "Desprez", "Iommelli", "Kurtag", "Lachenmann", "Ligeti", "Machaut", "Mahler", "Mendelssohn", "Mozart", "Perotinus", "Schubert", "Schumann", "Schönberg", "Sciarrino", "Spontini", "Stravinsky", "Traetta", "Webern", ")", "(", 1, 2, 1, 3, 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 4, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 307.0, 145.0, 23.0 ],
									"style" : "",
									"text" : "bach.print Occurrences"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 75.0, 600.0, 36.0 ],
									"style" : "",
									"text" : "If you don't set any arguments, all elements are uniquely output as in a dictionary from the right outlet, and their occurrences from the left outlet.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 170.0, 307.0, 99.0, 23.0 ],
									"style" : "",
									"text" : "bach.print Data"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 10.0, 140.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"linecount" : 3,
									"maxclass" : "textedit",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 170.0, 137.0, 54.0 ],
									"style" : "",
									"text" : "foo foo foo 1 2 3 fee foo 1 4 toto titi tutu tutu 2 foo"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 10.0, 236.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "route text"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 10.0, 268.0, 179.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.histo" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 220.299164, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-17", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-23", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 21.0, 118.0, 57.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p default",
					"varname" : "basic_tab[2]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 679.0, 472.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 312.0, 203.0, 87.0, 23.0 ],
									"style" : "",
									"text" : "loadmess set"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 325.0, 163.0, 250.0, 25.0 ],
									"presentation_rect" : [ 322.0, 161.0, 0.0, 0.0 ],
									"style" : "",
									"text" : "Only operate at the first level of depth"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-22",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 300.0, 131.0, 250.0, 25.0 ],
									"style" : "",
									"text" : "Operate till last level of depth (default)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 214.0, 131.0, 83.0, 23.0 ],
									"presentation_rect" : [ 229.0, 169.0, 0.0, 0.0 ],
									"style" : "",
									"text" : "maxdepth -1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 243.0, 163.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "maxdepth 1"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 7.0,
									"id" : "obj-16",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 192.0, 285.0, 466.0, 16.0 ],
									"presentation_rect" : [ 14.0, 421.0, 0.0, 0.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 7.0,
									"id" : "obj-15",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 13.0, 289.0, 165.0, 16.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 18.0, 131.0, 24.0, 24.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 18.0, 163.0, 127.0, 23.0 ],
									"presentation_rect" : [ 23.0, 146.0, 0.0, 0.0 ],
									"reg_data_0000000000" : [ "(", "massive", "attack", ")", "(", "attack", "unfinished", ")", "(", "unfinished", "sympathy", ")", "(", "i", "know", ")", "(", "know", "that", ")", "(", "that", "i've", ")", "(", "i've", "been", ")", "(", "been", "mad", ")", "(", "mad", "in", ")", "(", "in", "love", ")", "(", "love", "before", ")", "(", "and", "how", ")", "(", "how", "it", ")", "(", "it", "could", ")", "(", "could", "be", ")", "(", "be", "with", ")", "(", "with", "you", ")", "(", "really", "hurt", ")", "(", "hurt", "me", ")", "(", "me", "baby", ")", "(", "really", "cut", ")", "(", "cut", "me", ")", "(", "me", "baby", ")", "(", "how", "can", ")", "(", "can", "you", ")", "(", "you", "have", ")", "(", "have", "a", ")", "(", "a", "day", ")", "(", "day", "without", ")", "(", "without", "a", ")", "(", "a", "night", ")", "(", "you're", "the", ")", "(", "the", "book", ")", "(", "book", "that", ")", "(", "that", "i", ")", "(", "i", "have", ")", "(", "have", "opened", ")", "(", "and", "now", ")", "(", "now", "i've", ")", "(", "i've", "got", ")", "(", "got", "to", ")", "(", "to", "know", ")", "(", "know", "much", ")", "(", "much", "more", ")", "(", "the", "curiousness", ")", "(", "curiousness", "of", ")", "(", "of", "your", ")", "(", "your", "potential", ")", "(", "potential", "kiss", ")", "(", "has", "got", ")", "(", "got", "my", ")", "(", "my", "mind", ")", "(", "mind", "and", ")", "(", "and", "body", ")", "(", "body", "aching", ")", "(", "really", "hurt", ")", "(", "hurt", "me", ")", "(", "me", "baby", ")", "(", "really", "cut", ")", "(", "cut", "me", ")", "(", "me", "baby", ")", "(", "how", "can", ")", "(", "can", "you", ")", "(", "you", "have", ")", "(", "have", "a", ")", "(", "a", "day", ")", "(", "day", "without", ")", "(", "without", "a", ")", "(", "a", "night", ")", "(", "you're", "the", ")", "(", "the", "book", ")", "(", "book", "that", ")", "(", "that", "i", ")", "(", "i", "have", ")", "(", "have", "opened", ")", "(", "and", "now", ")", "(", "now", "i've", ")", "(", "i've", "got", ")", "(", "got", "to", ")", "(", "to", "know", ")", "(", "know", "much", ")", "(", "much", "more", ")", "(", "like", "a", ")", "(", "a", "soul", ")", "(", "soul", "without", ")", "(", "without", "a", ")", "(", "a", "mind", ")", "(", "in", "a", ")", "(", "a", "body", ")", "(", "body", "without", ")", "(", "without", "a", ")", "(", "a", "heart", ")", "(", "i'm", "missing", ")", "(", "missing", "every", ")", "(", "every", "part", ")", "(", "like", "a", ")", "(", "a", "soul", ")", "(", "soul", "without", ")", "(", "without", "a", ")", "(", "a", "mind", ")", "(", "in", "a", ")", "(", "a", "body", ")", "(", "body", "without", ")", "(", "without", "a", ")", "(", "a", "heart", ")", "(", "i'm", "missing", ")", "(", "missing", "every", ")", "(", "every", "part", ")", "(", "like", "a", ")", "(", "a", "soul", ")", "(", "soul", "without", ")", "(", "without", "a", ")", "(", "a", "mind", ")", "(", "in", "a", ")", "(", "a", "body", ")", "(", "body", "without", ")", "(", "without", "a", ")", "(", "a", "heart", ")", "(", "i'm", "missing", ")", "(", "missing", "every", ")", "(", "every", "part", ")", "(", "like", "a", ")", "(", "a", "soul", ")", "(", "soul", "without", ")", "(", "without", "a", ")", "(", "a", "mind", ")", "(", "in", "a", ")", "(", "a", "body", ")", "(", "body", "without", ")", "(", "without", "a", ")", "(", "a", "heart", ")", "(", "like", "a", ")", "(", "a", "soul", ")", "(", "soul", "without", ")", "(", "without", "a", ")", "(", "a", "mind", ")", "(", "in", "a", ")", "(", "a", "body", ")", "(", "body", "without", ")", "(", "without", "a", ")", "(", "a", "heart", ")", "(", "i'm", "missing", ")", "(", "missing", "every", ")", "(", "every", "part", ")", "(", "massive", "attack", ")", "(", "attack", "what", ")", "(", "what", "your", ")", "(", "your", "soul", ")", "(", "soul", "sings", ")", "(", "don't", "be", ")", "(", "be", "afraid", ")", "(", "open", "your", ")", "(", "your", "mouth", ")", "(", "mouth", "and", ")", "(", "and", "say", ")", "(", "say", "what", ")", "(", "what", "your", ")", "(", "your", "soul", ")", "(", "soul", "sings", ")", "(", "sings", "to", ")", "(", "to", "you", ")", "(", "your", "mind", ")", "(", "mind", "can", ")", "(", "can", "never", ")", "(", "never", "change", ")", "(", "unless", "you", ")", "(", "you", "ask", ")", "(", "ask", "it", ")", "(", "it", "to", ")", "(", "lovingly", "re-arrange", ")", "(", "the", "thoughts", ")", "(", "thoughts", "that", ")", "(", "that", "make", ")", "(", "make", "you", ")", "(", "you", "blue", ")", "(", "the", "things", ")", "(", "things", "that", ")", "(", "that", "bring", ")", "(", "bring", "you", ")", "(", "you", "down", ")", "(", "only", "do", ")", "(", "do", "harm", ")", "(", "harm", "to", ")", "(", "to", "you", ")", "(", "and", "so", ")", "(", "so", "make", ")", "(", "make", "your", ")", "(", "your", "choice", ")", "(", "choice", "joy", ")", "(", "the", "joy", ")", "(", "joy", "belongs", ")", "(", "belongs", "to", ")", "(", "to", "you", ")", "(", "and", "when", ")", "(", "when", "you", ")", "(", "you", "do", ")", "(", "you'll", "find", ")", "(", "find", "the", ")", "(", "the", "one", ")", "(", "one", "you", ")", "(", "you", "love", ")", "(", "love", "is", ")", "(", "is", "you", ")", "(", "you'll", "find", ")", "(", "find", "you", ")", "(", "you", "love", ")", "(", "love", "you", ")", "(", "don't", "be", ")", "(", "be", "ashamed", ")", "(", "ashamed", "never", ")", "(", "to", "open", ")", "(", "open", "your", ")", "(", "your", "heart", ")", "(", "heart", "and", ")", "(", "and", "pray", ")", "(", "say", "what", ")", "(", "what", "your", ")", "(", "your", "soul", ")", "(", "soul", "sings", ")", "(", "sings", "to", ")", "(", "to", "you", ")", "(", "so", "no", ")", "(", "no", "longer", ")", "(", "longer", "pretend", ")", "(", "that", "you", ")", "(", "you", "can't", ")", "(", "can't", "feel", ")", "(", "feel", "it", ")", "(", "it", "near", ")", "(", "that", "tickle", ")", "(", "tickle", "on", ")", "(", "on", "your", ")", "(", "your", "hand", ")", "(", "that", "tingle", ")", "(", "tingle", "in", ")", "(", "in", "your", ")", "(", "your", "ear", ")", "(", "ask", "it,", ")", "(", "because", "it", ")", "(", "it", "loves", ")", "(", "loves", "you", ")", "(", "you", "dear", ")", "(", "it's", "your", ")", "(", "your", "most", ")", "(", "most", "precious", ")", "(", "precious", "king", ")", "(", "if", "only", ")", "(", "only", "you", ")", "(", "you", "could", ")", "(", "could", "hear", ")", "(", "and", "when", ")", "(", "when", "you", ")", "(", "you", "do", ")", "(", "you'll", "find", ")", "(", "find", "the", ")", "(", "the", "one", ")", "(", "one", "you", ")", "(", "you", "need", ")", "(", "need", "is", ")", "(", "is", "you", ")", "(", "you'll", "find", ")", "(", "find", "you", ")", "(", "you", "love", ")", "(", "love", "you", ")", "(", "masterplan", "crimson", ")", "(", "crimson", "rider", ")", "(", "as", "far", ")", "(", "far", "as", ")", "(", "as", "the", ")", "(", "the", "eye", ")", "(", "eye", "can", ")", "(", "can", "see", ")", "(", "sharp", "dressed", ")", "(", "dressed", "fools", ")", "(", "fools", "with", ")", "(", "with", "their", ")", "(", "their", "crazy", ")", "(", "crazy", "rules", ")", "(", "rules", "here", ")", "(", "and", "blinding", ")", "(", "blinding", "advice", ")", "(", "advice", "from", ")", "(", "from", "all", ")", "(", "all", "my", ")", "(", "my", "friends", ")", "(", "reaching", "for", ")", "(", "for", "perfection", ")", "(", "i", "take", ")", "(", "take", "off", ")", "(", "off", "in", ")", "(", "in", "the", ")", "(", "the", "night", ")", "(", "it", "won't", ")", "(", "won't", "be", ")", "(", "be", "long,", ")", "(", "i'll", "be", ")", "(", "be", "fighting", ")", "(", "fighting", "there", ")", "(", "when", "dawn", ")", "(", "dawn", "is", ")", "(", "is", "breaking", ")", "(", "holy", "fire", ")", "(", "fire", "i'm", ")", "(", "i'm", "not", ")", "(", "not", "scared", ")", "(", "scared", "of", ")", "(", "of", "you", ")", "(", "i'll", "take", ")", "(", "take", "you", ")", "(", "you", "to", ")", "(", "to", "burn", ")", "(", "watch", "out", ")", "(", "out", "for", ")", "(", "for", "your", ")", "(", "your", "enemy", ")", "(", "death", "can", ")", "(", "can", "be", ")", "(", "be", "seconds", ")", "(", "seconds", "away", ")", "(", "live", "for", ")", "(", "for", "now", ")", "(", "now", "like", ")", "(", "like", "there's", ")", "(", "there's", "no", ")", "(", "no", "tomorrow", ")", "(", "and", "forward", ")", "(", "forward", "we", ")", "(", "we", "ride", ")", "(", "ride", "in", ")", "(", "in", "this", ")", "(", "this", "warlike", ")", "(", "warlike", "machine", ")", "(", "there'll", "be", ")", "(", "be", "no", ")", "(", "no", "returning", ")", "(", "holy", "fire", ")", "(", "fire", "i'm", ")", "(", "i'm", "not", ")", "(", "not", "scared", ")", "(", "scared", "of", ")", "(", "of", "you", ")", "(", "i'll", "take", ")", "(", "take", "you", ")", "(", "you", "to", ")", "(", "to", "burn", ")", "(", "crimson", "rider,", ")", "(", "i", "am", ")", "(", "am", "the", ")", "(", "the", "baron", ")", "(", "baron", "of", ")", "(", "of", "the", ")", "(", "the", "sky", ")", "(", "come", "feel", ")", "(", "feel", "the", ")", "(", "the", "wind", ")", "(", "wind", "turn", ")", "(", "holy", "fire", ")", "(", "fire", "i'm", ")", "(", "i'm", "not", ")", "(", "not", "scared", ")", "(", "scared", "of", ")", "(", "of", "you", ")", "(", "i'll", "take", ")", "(", "take", "you", ")", "(", "you", "to", ")", "(", "to", "burn", ")", "(", "crimson", "rider,", ")", "(", "i", "am", ")", "(", "am", "the", ")", "(", "the", "baron", ")", "(", "baron", "of", ")", "(", "of", "the", ")", "(", "the", "sky", ")", "(", "come", "feel", ")", "(", "feel", "the", ")", "(", "the", "wind", ")", "(", "wind", "turn", ")", "(", "and", "when", ")", "(", "when", "life", ")", "(", "life", "is", ")", "(", "is", "evil", ")", "(", "i'll", "fly", ")", "(", "fly", "my", ")", "(", "my", "wings", ")", "(", "wings", "across", ")", "(", "across", "the", ")", "(", "the", "sky", ")", "(", "is", "it", ")", "(", "it", "our", ")", "(", "our", "destiny", ")", "(", "killing", "our", ")", "(", "our", "brothers", ")", "(", "masterplan", "headbanger's", ")", "(", "headbanger's", "ballroom", ")", "(", "she's", "got", ")", "(", "got", "fear", ")", "(", "fear", "in", ")", "(", "in", "her", ")", "(", "her", "mind,", ")", "(", "killing", "pain", ")", "(", "pain", "all", ")", "(", "all", "the", ")", "(", "the", "time", ")", "(", "and", "the", ")", "(", "the", "loneliness", ")", "(", "loneliness", "makes", ")", "(", "makes", "her", ")", "(", "her", "feel", ")", "(", "feel", "hollow", ")", "(", "she", "will", ")", "(", "will", "stay", ")", "(", "stay", "out", ")", "(", "out", "of", ")", "(", "of", "sight,", ")", "(", "from", "the", ")", "(", "the", "bright", ")", "(", "bright", "daylight", ")", "(", "to", "forget", ")", "(", "forget", "all", ")", "(", "all", "her", ")", "(", "her", "troubles", ")", "(", "troubles", "for", ")", "(", "for", "a", ")", "(", "a", "while", ")", "(", "she", "just", ")", "(", "just", "wants", ")", "(", "wants", "to", ")", "(", "to", "dream", ")", "(", "dream", "away", ")", "(", "sick", "and", ")", "(", "and", "tired", ")", "(", "tired", "of", ")", "(", "of", "the", ")", "(", "the", "games", ")", "(", "games", "that", ")", "(", "that", "people", ")", "(", "people", "play", ")", "(", "hoping", "for", ")", "(", "for", "a", ")", "(", "a", "better", ")", "(", "better", "day", ")", "(", "she", "needs", ")", "(", "needs", "something", ")", "(", "something", "to", ")", "(", "to", "believe", ")", "(", "believe", "in", ")", "(", "in", "in", ")", "(", "in", "a", ")", "(", "a", "life", ")", "(", "life", "so", ")", "(", "so", "unreal", ")", "(", "down", "to", ")", "(", "to", "the", ")", "(", "the", "headbanger's", ")", "(", "headbanger's", "ballroom", ")", "(", "ballroom", "she", ")", "(", "she", "will", ")", "(", "will", "go", ")", "(", "seeking", "shelter", ")", "(", "shelter", "from", ")", "(", "from", "the", ")", "(", "the", "storm", ")", "(", "there", "she", ")", "(", "she", "can", ")", "(", "can", "party", ")", "(", "party", "till", ")", "(", "till", "the", ")", "(", "the", "rising", ")", "(", "rising", "of", ")", "(", "of", "the", ")", "(", "the", "sun", ")", "(", "a", "night", ")", "(", "night", "creature", ")", "(", "creature", "on", ")", "(", "on", "the", ")", "(", "the", "run", ")", "(", "he", "comes", ")", "(", "comes", "out", ")", "(", "out", "in", ")", "(", "in", "the", ")", "(", "the", "night,", ")", "(", "he", "is", ")", "(", "is", "one", ")", "(", "one", "with", ")", "(", "with", "the", ")", "(", "the", "moonlight", ")", "(", "been", "looking", ")", "(", "looking", "for", ")", "(", "for", "love", ")", "(", "love", "to", ")", "(", "to", "rely", ")", "(", "rely", "on", ")", "(", "she'll", "be", ")", "(", "be", "painting", ")", "(", "painting", "her", ")", "(", "her", "lips,", ")", "(", "black", "jade", ")", "(", "jade", "on", ")", "(", "on", "her", ")", "(", "her", "fingertips", ")", "(", "trying", "to", ")", "(", "to", "catch", ")", "(", "catch", "him", ")", "(", "him", "with", ")", "(", "with", "a", ")", "(", "a", "smile", ")", "(", "when", "her", ")", "(", "her", "eyes", ")", "(", "eyes", "begin", ")", "(", "begin", "to", ")", "(", "to", "glow,", ")", "(", "there's", "a", ")", "(", "a", "fire", ")", "(", "fire", "from", ")", "(", "from", "deep", ")", "(", "deep", "down", ")", "(", "down", "below", ")", "(", "getting", "ready", ")", "(", "ready", "for", ")", "(", "for", "the", ")", "(", "the", "show", ")", "(", "she", "just", ")", "(", "just", "wants", ")", "(", "wants", "to", ")", "(", "to", "be", ")", "(", "be", "near", ")", "(", "near", "him,", ")", "(", "cause", "she", ")", "(", "she", "knows", ")", "(", "knows", "he's", ")", "(", "he's", "the", ")", "(", "the", "one", ")", "(", "down", "at", ")", "(", "at", "the", ")", "(", "the", "headbanger's", ")", "(", "headbanger's", "ballroom", ")", "(", "ballroom", "they", ")", "(", "they", "will", ")", "(", "will", "dance", ")", "(", "finding", "shelter", ")", "(", "shelter", "from", ")", "(", "from", "the", ")", "(", "the", "storm", ")", "(", "they're", "not", ")", "(", "not", "different", ")", "(", "different", "only", ")", "(", "only", "dreamers", ")", "(", "dreamers", "on", ")", "(", "on", "the", ")", "(", "the", "run", ")", "(", "dark", "creatures", ")", "(", "creatures", "of", ")", "(", "of", "the", ")", "(", "the", "sun", ")", "(", "down", "at", ")", "(", "at", "the", ")", "(", "the", "headbanger's", ")", "(", "headbanger's", "ballroom", ")", "(", "ballroom", "they", ")", "(", "they", "will", ")", "(", "will", "dance", ")", "(", "black", "leather", ")", "(", "leather", "witches", ")", "(", "witches", "and", ")", "(", "and", "their", ")", "(", "their", "boys", ")", "(", "where", "they", ")", "(", "they", "can", ")", "(", "can", "party", ")", "(", "party", "till", ")", "(", "till", "the", ")", "(", "the", "rising", ")", "(", "rising", "of", ")", "(", "of", "the", ")", "(", "the", "sun", ")", "(", "night", "creatures", ")", "(", "creatures", "on", ")", "(", "on", "the", ")", "(", "the", "run", ")", "(", "masterplan", "heroes", ")", "(", "are", "we", ")", "(", "we", "caught", ")", "(", "caught", "between", ")", "(", "between", "good", ")", "(", "good", "and", ")", "(", "and", "bad", ")", "(", "it's", "all", ")", "(", "all", "just", ")", "(", "just", "said", ")", "(", "said", "and", ")", "(", "and", "done", ")", "(", "longing", "for", ")", "(", "for", "a", ")", "(", "a", "better", ")", "(", "better", "way", ")", "(", "the", "feeling", ")", "(", "feeling", "is", ")", "(", "is", "so", ")", "(", "so", "strong", ")", "(", "try", "to", ")", "(", "to", "mend", ")", "(", "mend", "your", ")", "(", "your", "broken", ")", "(", "broken", "ways", ")", "(", "why", "should", ")", "(", "should", "we", ")", "(", "we", "live", ")", "(", "live", "within", ")", "(", "within", "a", ")", "(", "a", "haze", ")", "(", "we're", "the", ")", "(", "the", "heroes", ")", "(", "heroes", "of", ")", "(", "of", "a", ")", "(", "a", "new", ")", "(", "new", "world", ")", "(", "the", "masterplan's", ")", "(", "masterplan's", "rising", ")", "(", "send", "freedom", ")", "(", "freedom", "all", ")", "(", "all", "over", ")", "(", "over", "the", ")", "(", "the", "globe", ")", "(", "willing", "now", ")", "(", "now", "to", ")", "(", "to", "pay", ")", "(", "pay", "the", ")", "(", "the", "price", ")", "(", "just", "call", ")", "(", "call", "it", ")", "(", "it", "by", ")", "(", "by", "the", ")", "(", "the", "name", ")", "(", "unlock", "the", ")", "(", "the", "gate", ")", "(", "gate", "to", ")", "(", "to", "paradise", ")", "(", "it's", "time", ")", "(", "time", "to", ")", "(", "to", "stop", ")", "(", "stop", "the", ")", "(", "the", "game", ")", "(", "how", "can", ")", "(", "can", "we", ")", "(", "we", "fly", ")", "(", "fly", "with", ")", "(", "with", "broken", ")", "(", "broken", "wings", ")", "(", "realize", "we're", ")", "(", "we're", "strong", ")", "(", "strong", "like", ")", "(", "like", "kings", ")", "(", "we're", "the", ")", "(", "the", "heroes", ")", "(", "heroes", "of", ")", "(", "of", "a", ")", "(", "a", "new", ")", "(", "new", "world", ")", "(", "the", "masterplan's", ")", "(", "masterplan's", "rising", ")", "(", "rising", "and", ")", "(", "and", "dreams", ")", "(", "dreams", "will", ")", "(", "will", "come", ")", "(", "come", "true", ")", "(", "sending", "freedom", ")", "(", "freedom", "like", ")", "(", "like", "a", ")", "(", "a", "warming", ")", "(", "warming", "rain", ")", "(", "we", "show", ")", "(", "show", "you", ")", "(", "you", "the", ")", "(", "the", "magic", ")", "(", "magic", "you've", ")", "(", "you've", "never", ")", "(", "never", "seen", ")", "(", "seen", "arise", ")", "(", "arise", "above", ")", "(", "above", "you", ")", "(", "we", "must", ")", "(", "must", "cast", ")", "(", "cast", "aside", ")", "(", "aside", "our", ")", "(", "our", "misery", ")", "(", "let's", "search", ")", "(", "search", "for", ")", "(", "for", "final", ")", "(", "final", "liberty", ")" ],
									"reg_data_count" : [ 1 ],
									"saved_object_attributes" : 									{
										"embed" : 1
									}
,
									"style" : "",
									"text" : "bach.reg @embed 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 70.0, 582.0, 36.0 ],
									"style" : "",
									"text" : "You can send to bach.histo also a complex-structured llll, and it operate according to the maxdepth attribute.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 17.0, 237.0, 483.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.histo" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 220.299164, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 40.0, 191.0, 72.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p in-depth",
					"varname" : "basic_tab[1]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 299.0, 205.0, 149.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
					"style" : "",
					"text" : "js helpstarter.js bach.histo"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 37.0, 248.0, 679.0, 472.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 297.0, 353.0, 145.0, 23.0 ],
									"style" : "",
									"text" : "bach.print Occurrences"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 297.0, 319.0, 125.0, 23.0 ],
									"style" : "",
									"text" : "bach.print Elements"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 1.0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 570.0, 234.5, 91.0, 40.0 ],
									"presentation_rect" : [ 377.0, 153.0, 0.0, 0.0 ],
									"style" : "",
									"text" : "See tab \"integers\""
								}

							}
, 							{
								"box" : 								{
									"candycane" : 12,
									"ghostbar" : 30,
									"id" : "obj-25",
									"maxclass" : "multislider",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 450.0, 338.5, 169.0, 79.0 ],
									"setminmax" : [ 0.0, 12.0 ],
									"size" : 12,
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 450.0, 153.5, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"linecount" : 2,
									"maxclass" : "textedit",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 450.0, 183.5, 101.0, 59.0 ],
									"style" : "",
									"text" : "1 2 4 4 7 2 11 0 4 4 4 1 "
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 450.0, 249.5, 66.0, 23.0 ],
									"style" : "",
									"text" : "route text"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 450.0, 281.5, 140.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo 0 11 @out t"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-22",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 293.0, 266.5, 87.0, 40.0 ],
									"style" : "",
									"text" : "See tab \"symbols\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 16.0, 314.0, 268.0, 23.0 ],
									"style" : "",
									"text" : "buddy"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 16.0, 147.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"linecount" : 11,
									"maxclass" : "textedit",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 16.0, 177.0, 220.0, 54.0 ],
									"style" : "",
									"text" : "Bach Beethoven Mozart Beethoven Mozart Boulez Schönberg Webern Webern Webern Webern Berg Brahms Brahms Mahler Machaut Desprez Perotinus Spontini Iommelli Traetta Schubert Schumann Mendelssohn Brückner Stravinsky Lachenmann Berio Stravinsky Lachenmann Berio  Stravinsky Lachenmann Berio  Ligeti Kurtag Sciarrino Brahms"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 16.0, 243.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "route text"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 16.0, 275.0, 268.0, 23.0 ],
									"style" : "",
									"text" : "bach.histo"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "bach.wordcloud",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 16.0, 347.0, 268.0, 110.0 ],
									"whole_wordcloud_data_0000000000" : [ "(", "Bach", "Beethoven", "Berg", "Berio", "Boulez", "Brahms", "Brückner", "Desprez", "Iommelli", "Kurtag", "Lachenmann", "Ligeti", "Machaut", "Mahler", "Mendelssohn", "Mozart", "Perotinus", "Schubert", "Schumann", "Schönberg", "Sciarrino", "Spontini", "Stravinsky", "Traetta", "Webern", ")", "(", 1, 2, 1, 3, 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 4, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpdetails.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.histo", 100 ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 609.0, 127.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"order" : 1,
									"source" : [ "obj-13", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"order" : 1,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"order" : 0,
									"source" : [ "obj-13", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"order" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-17", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-23", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 85.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p basic",
					"varname" : "basic_tab"
				}

			}
, 			{
				"box" : 				{
					"border" : 0,
					"filename" : "helpname.js",
					"id" : "obj-4",
					"ignoreclick" : 1,
					"jsarguments" : [ "bach.histo" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 10.0, 220.299164, 57.567627 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 679.0, 472.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"boxes" : [  ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 205.0, 205.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p ?",
					"varname" : "q_tab"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "helpname.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.histo.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.repeat.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.-.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.split.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.change.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "helpstarter.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpargs.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.wordcloud.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.sort.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.subs.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.arithmser.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
