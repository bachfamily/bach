{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 70.0, 48.0, 802.0, 485.0 ],
		"bglocked" : 0,
		"defrect" : [ 70.0, 48.0, 802.0, 485.0 ],
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
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 334.0, 582.0, 81.0, 18.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 0 p \"Through The Looking Glass\"",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 333.5, 637.0, 262.0, 20.0 ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 333.5, 609.5, 69.0, 20.0 ],
					"id" : "obj-15",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "In our case, we are performing a random permutation (and [bach.scramble] is our object!!) only on the chord pitches.",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 436.0, 249.0, 193.0, 62.0 ],
					"id" : "obj-41",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.fromc&r",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 319.0, 300.0, 82.0, 20.0 ],
					"id" : "obj-40",
					"fontname" : "Arial",
					"numinlets" : 3,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.scramble",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 319.0, 275.0, 89.0, 20.0 ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "[bach.fromc&r] needs the connection in its last inlet in order to reconstruct properly the interleaved list of chord and rests.",
					"linecount" : 3,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 373.0, 235.0, 48.0 ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "rest info",
					"numoutlets" : 0,
					"patching_rect" : [ 125.0, 324.0, 63.0, 20.0 ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 113.0, 193.0, 100.0, 18.0 ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1/4 1/4 -1/8 1/4 -1/8",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 115.0, 132.0, 115.0, 18.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 193.0, 100.0, 18.0 ],
					"id" : "obj-88",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "chord1 chord2 REST1 chord3 REST2",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 27.0, 109.0, 211.0, 18.0 ],
					"id" : "obj-87",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.toc&r @out t",
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 27.0, 156.0, 107.0, 20.0 ],
					"id" : "obj-84",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "For example:",
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 88.0, 150.0, 20.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "chord info",
					"numoutlets" : 0,
					"patching_rect" : [ 19.0, 324.0, 63.0, 20.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p do_other_stuff",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 115.0, 306.0, 97.0, 20.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 50.0, 94.0, 195.0, 228.0 ],
						"bglocked" : 0,
						"defrect" : [ 50.0, 94.0, 195.0, 228.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "you can put\nwhatever you want\nhere: you're acting\nonly on the \"rest\"-elements",
									"linecount" : 5,
									"numoutlets" : 0,
									"patching_rect" : [ 60.0, 58.0, 114.0, 75.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numoutlets" : 0,
									"patching_rect" : [ 32.0, 138.0, 25.0, 25.0 ],
									"id" : "obj-2",
									"numinlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 32.0, 32.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"numinlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 12.0,
						"fontname" : "Arial",
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p do_stuff",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 9.0, 306.0, 63.0, 20.0 ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 50.0, 94.0, 195.0, 228.0 ],
						"bglocked" : 0,
						"defrect" : [ 50.0, 94.0, 195.0, 228.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "you can put\nwhatever you want\nhere: you're acting\nonly on the \"chord\"-elements",
									"linecount" : 5,
									"numoutlets" : 0,
									"patching_rect" : [ 54.0, 58.0, 114.0, 75.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numoutlets" : 0,
									"patching_rect" : [ 32.0, 138.0, 25.0, 25.0 ],
									"id" : "obj-2",
									"numinlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 32.0, 32.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"numinlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 12.0,
						"fontname" : "Arial",
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.fromc&r",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 9.0, 353.0, 230.0, 20.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"numinlets" : 3,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The typical configuration of the process is:",
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 256.0, 235.0, 20.0 ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.toc&r",
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 9.0, 280.0, 230.0, 20.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess clear",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 276.0, 375.0, 91.0, 20.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "if you want, you can do the same thing on velocities!",
					"linecount" : 3,
					"numoutlets" : 0,
					"patching_rect" : [ 592.0, 313.0, 148.0, 48.0 ],
					"id" : "obj-100",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.toc&r",
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 319.0, 247.0, 82.0, 20.0 ],
					"id" : "obj-95",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "preset",
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 725.0, 94.0, 44.0, 18.0 ],
					"id" : "obj-23",
					"numinlets" : 1,
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-1", "bach.score", "begin_preset", 835, 256, "obj-1", "bach.score", "restore_preset", 0, 250, "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", 256, "obj-1", "bach.score", "restore_preset", 250, 250, ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 256, "obj-1", "bach.score", "restore_preset", 500, 250, 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "clefs", "G", ")", "(", "keys", "CM", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 127, 0, 0, ")", 0, ")", "(", "-1/20", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 91, "obj-1", "bach.score", "restore_preset", 750, 85, 1086019584, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 127, 0, 0, ")", 0, ")", "(", "-1/8", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 127, 1, 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 127, 0, 0, ")", 0, ")", "(", "3/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, ")", 0, ")", 0, ")", ")", 4, "obj-1", "bach.score", "end_preset" ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-1", "bach.score", "begin_preset", 795, 256, "obj-1", "bach.score", "restore_preset", 0, 250, "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", 256, "obj-1", "bach.score", "restore_preset", 250, 250, ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 256, "obj-1", "bach.score", "restore_preset", 500, 250, 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "clefs", "G", ")", "(", "keys", "CM", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "-1/12", 0, ")", "(", "-1/16", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 127, 0, 0, ")", 0, ")", "(", "-1/4", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086065664, 100, 0, 0, ")", 0, ")", "(", "-1/8", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "-1/4", 0, ")", "(", "3/20", 51, "obj-1", "bach.score", "restore_preset", 750, 45, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 100, 0, 0, ")", 0, ")", "(", "1/10", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 1, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, ")", 0, ")", "(", "-1/5", 0, ")", "(", "-1/4", 0, ")", 0, ")", ")", 4, "obj-1", "bach.score", "end_preset" ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "dump",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 271.0, 94.0, 41.0, 18.0 ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.beatbox",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 271.0, 335.0, 318.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 6,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.beatunbox",
					"numoutlets" : 6,
					"outlettype" : [ "", "", "", "", "", "" ],
					"patching_rect" : [ 271.0, 214.0, 256.5, 20.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "As you may correctly point out, all these chord and rest abstractions are handy, but one might need to do its OWN operation. That's where the general [bach.toc&r] and [bach.fromc&r] abstraction come to help. The first one splits the info about chords and rests, the second one puts them together anew, possibly after some transformation.",
					"linecount" : 3,
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 39.0, 750.0, 48.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"stafflines" : 5,
					"preventedit" : [  ],
					"numoutlets" : 9,
					"automessage" : [  ],
					"zoom" : 101.171875,
					"versionnumber" : 6999,
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"loop" : [ "(", 1, ")", "(", 1, ")" ],
					"patching_rect" : [ 271.0, 364.0, 492.0, 89.666664 ],
					"id" : "obj-5",
					"voicespacing" : [ 0.0, 5.6 ],
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"vzoom" : 81.515152,
					"numvoices" : 1,
					"popupmenuslots" : [  ],
					"numinlets" : 7,
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnnn",
					"fontsize" : 12.0,
					"bgslots" : [  ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"stafflines" : 5,
					"preventedit" : [  ],
					"numoutlets" : 9,
					"automessage" : [  ],
					"zoom" : 107.03125,
					"versionnumber" : 6999,
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"loop" : [ "(", 1, ")", "(", 1, ")" ],
					"patching_rect" : [ 271.0, 114.0, 497.0, 91.666664 ],
					"id" : "obj-1",
					"voicespacing" : [ 0.0, 15.2 ],
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"vzoom" : 83.333328,
					"numvoices" : 1,
					"popupmenuslots" : [  ],
					"numinlets" : 7,
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnnn",
					"fontsize" : 12.0,
					"bgslots" : [  ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 24, ")", "(", "(", "leveltype", 2, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", ")", "(", "-1/12", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/16", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 127, 0, 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086065664, 100, 0, 0, ")", 0, ")", "(", "-1/8", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "3/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 100, 0, 0, ")", 0, ")", "(", "1/10", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, ")", 0, ")", "(", "-1/5", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Cool!",
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 372.0, 540.0, 271.0, 20.0 ],
					"id" : "obj-256",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"hidden" : 1,
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 16.0, 444.0, 20.0 ],
					"id" : "obj-49",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- permutation",
					"numoutlets" : 0,
					"patching_rect" : [ 322.0, 6.74086, 313.0, 26.0 ],
					"id" : "obj-50",
					"fontname" : "Arial Italic",
					"numinlets" : 1,
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Through The Looking Glass (p)",
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 1.924051, 324.0, 32.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 585.0, 140.0, 20.0 ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 560.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 535.0, 140.0, 20.0 ],
					"id" : "obj-6",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Through The Looking Glass [o]",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 510.0, 174.0, 18.0 ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 485.0, 40.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3,
					"text" : "Back to section (o)",
					"outlettype" : [ "", "", "int" ],
					"patching_rect" : [ 5.0, 460.0, 151.0, 20.0 ],
					"id" : "obj-14",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 1 ],
					"destination" : [ "obj-95", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 2 ],
					"destination" : [ "obj-95", 1 ],
					"hidden" : 0,
					"color" : [ 0.196078, 0.627451, 0.098039, 0.682353 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 2 ],
					"destination" : [ "obj-11", 2 ],
					"hidden" : 0,
					"color" : [ 0.196078, 0.627451, 0.098039, 0.682353 ],
					"midpoints" : [ 375.5, 242.0, 427.0, 242.0, 427.0, 328.0, 400.100006, 328.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 1 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [ 343.0, 663.0, 327.0, 663.0, 327.0, 604.5, 343.0, 604.5 ]
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
					"source" : [ "obj-95", 2 ],
					"destination" : [ "obj-40", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 1 ],
					"destination" : [ "obj-40", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-11", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-84", 1 ],
					"destination" : [ "obj-33", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-84", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-87", 0 ],
					"destination" : [ "obj-84", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-84", 0 ],
					"destination" : [ "obj-88", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 1 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 2 ],
					"destination" : [ "obj-20", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-20", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 8 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 758.5, 204.0, 782.0, 204.0, 782.0, 91.0, 280.5, 91.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"color" : [ 0.768627, 0.701961, 0.082353, 1.0 ],
					"midpoints" : [ 734.5, 112.5, 280.5, 112.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
