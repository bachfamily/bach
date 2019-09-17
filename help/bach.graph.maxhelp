{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 100.0, 100.0, 807.0, 562.0 ],
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
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"hidden" : 1,
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 438.0, 73.0, 77.0, 21.0 ],
									"style" : "",
									"text" : "loadmess 1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 1.0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 323.0, 109.0, 207.0, 25.0 ],
									"style" : "",
									"text" : "Allow mousehovering on points"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 1.0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 521.0, 206.0, 239.0, 69.0 ],
									"style" : "",
									"text" : "You can perform all editing provided that you leave the \"modify\" attribute to 1. Set it to 0 if you want prevent the user to edit stuff."
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-30",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 267.59375, 274.5, 175.0, 54.0 ],
									"style" : "",
									"text" : "Cmd+click (mac) or Ctrl+click (win) on a point to delete it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-29",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 267.59375, 336.0, 191.0, 40.0 ],
									"style" : "",
									"text" : "...or click on a point and drag to move it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 259.59375, 243.0, 191.0, 25.0 ],
									"style" : "",
									"text" : "Alt+click to add a point",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "toggle",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 489.09375, 263.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "toggle",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 294.296875, 114.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 489.09375, 292.0, 67.0, 23.0 ],
									"style" : "",
									"text" : "modify $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 294.296875, 143.0, 100.0, 23.0 ],
									"style" : "",
									"text" : "mousehover $1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 287.296875, 478.0, 451.0, 25.0 ],
									"style" : "",
									"text" : "When you click on a point, the point index and the (X Y) values are output"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 137.09375, 478.0, 142.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Notifications"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 31.59375, 143.0, 44.0, 23.0 ],
									"style" : "",
									"text" : "dump"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 259.59375, 442.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 14.59375, 444.0, 106.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Dump"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"graphtype" : 3,
									"id" : "obj-25",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 14.59375, 206.0, 264.0, 230.0 ],
									"presentation_rect" : [ 45.0, 45.0, 260.0, 260.0 ],
									"showmode" : 1,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 63551, 3222154767, "_x_x_x_x_bach_float64_x_x_x_x_", 42741, 1073696233, "_x_x_x_x_bach_float64_x_x_x_x_", 53621, 3221578845, "_x_x_x_x_bach_float64_x_x_x_x_", 8548, 1074152136, "_x_x_x_x_bach_float64_x_x_x_x_", 19860, 3221058404, "_x_x_x_x_bach_float64_x_x_x_x_", 62687, 1073605053, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1073487872, "_x_x_x_x_bach_float64_x_x_x_x_", 14247, 1073901389, "_x_x_x_x_bach_float64_x_x_x_x_", 27804, 1074309926, "_x_x_x_x_bach_float64_x_x_x_x_", 2849, 1074402882, "_x_x_x_x_bach_float64_x_x_x_x_", 11916, 1074568098, "_x_x_x_x_bach_float64_x_x_x_x_", 59837, 1073468282, "_x_x_x_x_bach_float64_x_x_x_x_", 13902, 1072852371, "_x_x_x_x_bach_float64_x_x_x_x_", 51289, 1073057970, "_x_x_x_x_bach_float64_x_x_x_x_", 15888, 1072058243, "_x_x_x_x_bach_float64_x_x_x_x_", 8548, 1073103560, "_x_x_x_x_bach_float64_x_x_x_x_", 11916, 1072614306, "_x_x_x_x_bach_float64_x_x_x_x_", 39891, 1072510886, "_x_x_x_x_bach_float64_x_x_x_x_", 29789, 1073249559, "_x_x_x_x_bach_float64_x_x_x_x_", 39891, 1072510886, "_x_x_x_x_bach_float64_x_x_x_x_", 29789, 1073249559, "_x_x_x_x_bach_float64_x_x_x_x_", 37042, 1073422692, "_x_x_x_x_bach_float64_x_x_x_x_", 31775, 1072971527, "_x_x_x_x_bach_float64_x_x_x_x_", 2849, 1072830018, "_x_x_x_x_bach_float64_x_x_x_x_", 31775, 1072971527, "_x_x_x_x_bach_float64_x_x_x_x_", 39891, 1073559462, "_x_x_x_x_bach_float64_x_x_x_x_", 33761, 1072693496, "_x_x_x_x_bach_float64_x_x_x_x_", 39891, 1073559462, "_x_x_x_x_bach_float64_x_x_x_x_", 11916, 1072614306, "_x_x_x_x_bach_float64_x_x_x_x_", 54138, 1073194740, "_x_x_x_x_bach_float64_x_x_x_x_", 57593, 1073289278, "_x_x_x_x_bach_float64_x_x_x_x_", 28494, 1073012379, "_x_x_x_x_bach_float64_x_x_x_x_", 11916, 1072614306, "_x_x_x_x_bach_float64_x_x_x_x_", 22795, 1074311702, "_x_x_x_x_bach_float64_x_x_x_x_", 61564, 1072733215, "_x_x_x_x_bach_float64_x_x_x_x_", 39891, 1074083750, "_x_x_x_x_bach_float64_x_x_x_x_", 41705, 1072892090, "_x_x_x_x_bach_float64_x_x_x_x_", 48440, 1073969775, "_x_x_x_x_bach_float64_x_x_x_x_", 3972, 1072931808, "_x_x_x_x_bach_float64_x_x_x_x_", 2849, 1073878594, "_x_x_x_x_bach_float64_x_x_x_x_", 29789, 1073249559, "_x_x_x_x_bach_float64_x_x_x_x_", 28494, 1074060955, "_x_x_x_x_bach_float64_x_x_x_x_", 13902, 1072852371, "_x_x_x_x_bach_float64_x_x_x_x_", 31343, 1074197726 ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "graphtype",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 14.59375, 113.0, 230.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 0 ],
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"midpoints" : [ 498.59375, 320.0, 472.34375, 320.0, 472.34375, 196.0, 24.09375, 196.0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-25", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-25", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-23", 0 ],
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 271.0, 154.0, 20.0 ],
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
					"text" : "p \"editing and notifications\"",
					"varname" : "basic_tab[4]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"id" : "obj-21",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 76.0, 441.0, 21.0 ],
									"style" : "",
									"text" : "You can customize the grid type as well as the intervals between grid lines.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "showunitcircle",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 515.0, 170.0, 137.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "showxyaxis",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 229.0, 136.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "gridtype",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 229.0, 115.0, 188.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "gridthetastep",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 449.0, 136.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "gridrstep",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 449.0, 115.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"graphcolor" : [ 0.0, 0.070588, 0.458824, 1.0 ],
									"graphtype" : 1,
									"id" : "obj-7",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 449.0, 202.0, 269.0, 260.0 ],
									"showunitcircle" : 1,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 8860, 1065474799, "_x_x_x_x_bach_float64_x_x_x_x_", 11673, 1058848785, "_x_x_x_x_bach_float64_x_x_x_x_", 60524, 1066523097, "_x_x_x_x_bach_float64_x_x_x_x_", 54875, 1060945788, "_x_x_x_x_bach_float64_x_x_x_x_", 24860, 1067107344, "_x_x_x_x_bach_float64_x_x_x_x_", 52695, 1062218538, "_x_x_x_x_bach_float64_x_x_x_x_", 40300, 1067570562, "_x_x_x_x_bach_float64_x_x_x_x_", 37510, 1063042344, "_x_x_x_x_bach_float64_x_x_x_x_", 35606, 1067861714, "_x_x_x_x_bach_float64_x_x_x_x_", 39246, 1063678570, "_x_x_x_x_bach_float64_x_x_x_x_", 33505, 1068152172, "_x_x_x_x_bach_float64_x_x_x_x_", 56339, 1064314936, "_x_x_x_x_bach_float64_x_x_x_x_", 31632, 1068441798, "_x_x_x_x_bach_float64_x_x_x_x_", 42336, 1064696812, "_x_x_x_x_bach_float64_x_x_x_x_", 29147, 1068614699, "_x_x_x_x_bach_float64_x_x_x_x_", 31235, 1065137113, "_x_x_x_x_bach_float64_x_x_x_x_", 48708, 1068758473, "_x_x_x_x_bach_float64_x_x_x_x_", 16570, 1065494457, "_x_x_x_x_bach_float64_x_x_x_x_", 16056, 1068901625, "_x_x_x_x_bach_float64_x_x_x_x_", 53823, 1065772813, "_x_x_x_x_bach_float64_x_x_x_x_", 15508, 1069044085, "_x_x_x_x_bach_float64_x_x_x_x_", 60383, 1066080145, "_x_x_x_x_bach_float64_x_x_x_x_", 16035, 1069185785, "_x_x_x_x_bach_float64_x_x_x_x_", 12321, 1066409073, "_x_x_x_x_bach_float64_x_x_x_x_", 29348, 1069326658, "_x_x_x_x_bach_float64_x_x_x_x_", 51194, 1066591564, "_x_x_x_x_bach_float64_x_x_x_x_", 11597, 1069466634, "_x_x_x_x_bach_float64_x_x_x_x_", 38927, 1066788382, "_x_x_x_x_bach_float64_x_x_x_x_", 7889, 1069576583, "_x_x_x_x_bach_float64_x_x_x_x_", 58472, 1066999466, "_x_x_x_x_bach_float64_x_x_x_x_", 26713, 1069645574, "_x_x_x_x_bach_float64_x_x_x_x_", 17610, 1067224748, "_x_x_x_x_bach_float64_x_x_x_x_", 53618, 1069714015, "_x_x_x_x_bach_float64_x_x_x_x_", 17099, 1067457262, "_x_x_x_x_bach_float64_x_x_x_x_", 40474, 1069781874, "_x_x_x_x_bach_float64_x_x_x_x_", 9086, 1067583992, "_x_x_x_x_bach_float64_x_x_x_x_", 64134, 1069849117, "_x_x_x_x_bach_float64_x_x_x_x_", 36630, 1067717707, "_x_x_x_x_bach_float64_x_x_x_x_", 49347, 1069915710, "_x_x_x_x_bach_float64_x_x_x_x_", 31833, 1067858365, "_x_x_x_x_bach_float64_x_x_x_x_", 57483, 1069981621, "_x_x_x_x_bach_float64_x_x_x_x_", 48911, 1068005921, "_x_x_x_x_bach_float64_x_x_x_x_", 18559, 1070046817, "_x_x_x_x_bach_float64_x_x_x_x_", 5159, 1068160328, "_x_x_x_x_bach_float64_x_x_x_x_", 12304, 1070111266, "_x_x_x_x_bach_float64_x_x_x_x_", 58279, 1068321536, "_x_x_x_x_bach_float64_x_x_x_x_", 41323, 1070174934, "_x_x_x_x_bach_float64_x_x_x_x_", 37002, 1068489495, "_x_x_x_x_bach_float64_x_x_x_x_", 8993, 1070237790, "_x_x_x_x_bach_float64_x_x_x_x_", 38601, 1068581547, "_x_x_x_x_bach_float64_x_x_x_x_", 24847, 1070299802, "_x_x_x_x_bach_float64_x_x_x_x_", 13725, 1068672195, "_x_x_x_x_bach_float64_x_x_x_x_", 46234, 1070360938, "_x_x_x_x_bach_float64_x_x_x_x_", 51477, 1068766136, "_x_x_x_x_bach_float64_x_x_x_x_", 27663, 1070421166, "_x_x_x_x_bach_float64_x_x_x_x_", 44377, 1068863337, "_x_x_x_x_bach_float64_x_x_x_x_", 45458, 1070480456, "_x_x_x_x_bach_float64_x_x_x_x_", 47221, 1068963769, "_x_x_x_x_bach_float64_x_x_x_x_", 61900, 1070538775, "_x_x_x_x_bach_float64_x_x_x_x_", 14645, 1069067400, "_x_x_x_x_bach_float64_x_x_x_x_", 41734, 1070596094, "_x_x_x_x_bach_float64_x_x_x_x_", 39087, 1069174196, "_x_x_x_x_bach_float64_x_x_x_x_", 42678, 1070624238, "_x_x_x_x_bach_float64_x_x_x_x_", 33620, 1069284123, "_x_x_x_x_bach_float64_x_x_x_x_", 55978, 1070651851, "_x_x_x_x_bach_float64_x_x_x_x_", 32105, 1069397146, "_x_x_x_x_bach_float64_x_x_x_x_", 1129, 1070678918, "_x_x_x_x_bach_float64_x_x_x_x_", 50719, 1069513228, "_x_x_x_x_bach_float64_x_x_x_x_", 30957, 1070705425, "_x_x_x_x_bach_float64_x_x_x_x_", 46498, 1069589926, "_x_x_x_x_bach_float64_x_x_x_x_", 46905, 1070731356, "_x_x_x_x_bach_float64_x_x_x_x_", 14218, 1069650970, "_x_x_x_x_bach_float64_x_x_x_x_", 43139, 1070756697, "_x_x_x_x_bach_float64_x_x_x_x_", 61494, 1069713486, "_x_x_x_x_bach_float64_x_x_x_x_", 42298, 1070781435, "_x_x_x_x_bach_float64_x_x_x_x_", 25217, 1069777455, "_x_x_x_x_bach_float64_x_x_x_x_", 12348, 1070805553, "_x_x_x_x_bach_float64_x_x_x_x_", 23077, 1069842855, "_x_x_x_x_bach_float64_x_x_x_x_", 22866, 1070829040, "_x_x_x_x_bach_float64_x_x_x_x_", 109, 1069909665, "_x_x_x_x_bach_float64_x_x_x_x_", 47221, 1070851879, "_x_x_x_x_bach_float64_x_x_x_x_", 42684, 1069977864, "_x_x_x_x_bach_float64_x_x_x_x_", 62259, 1070874059, "_x_x_x_x_bach_float64_x_x_x_x_", 13530, 1070047430, "_x_x_x_x_bach_float64_x_x_x_x_", 48623, 1070895565, "_x_x_x_x_bach_float64_x_x_x_x_", 10421, 1070118340, "_x_x_x_x_bach_float64_x_x_x_x_", 19121, 1070916384, "_x_x_x_x_bach_float64_x_x_x_x_", 5381, 1070190571, "_x_x_x_x_bach_float64_x_x_x_x_", 5999, 1070936503, "_x_x_x_x_bach_float64_x_x_x_x_", 35672, 1070264100, "_x_x_x_x_bach_float64_x_x_x_x_", 3530, 1070955909, "_x_x_x_x_bach_float64_x_x_x_x_", 24128, 1070338902, "_x_x_x_x_bach_float64_x_x_x_x_", 58985, 1070974588, "_x_x_x_x_bach_float64_x_x_x_x_", 10075, 1070414954, "_x_x_x_x_bach_float64_x_x_x_x_", 49757, 1070992529, "_x_x_x_x_bach_float64_x_x_x_x_", 64836, 1070492230, "_x_x_x_x_bach_float64_x_x_x_x_", 60629, 1071009720, "_x_x_x_x_bach_float64_x_x_x_x_", 17438, 1070570706, "_x_x_x_x_bach_float64_x_x_x_x_", 47065, 1071026146, "_x_x_x_x_bach_float64_x_x_x_x_", 16908, 1070623225, "_x_x_x_x_bach_float64_x_x_x_x_", 26306, 1071041798, "_x_x_x_x_bach_float64_x_x_x_x_", 6125, 1070663624, "_x_x_x_x_bach_float64_x_x_x_x_", 6501, 1071056663, "_x_x_x_x_bach_float64_x_x_x_x_", 8899, 1070704582, "_x_x_x_x_bach_float64_x_x_x_x_", 43748, 1071070729, "_x_x_x_x_bach_float64_x_x_x_x_", 22964, 1070746088, "_x_x_x_x_bach_float64_x_x_x_x_", 30592, 1071083985, "_x_x_x_x_bach_float64_x_x_x_x_", 13579, 1070788128, "_x_x_x_x_bach_float64_x_x_x_x_", 64688, 1071096420, "_x_x_x_x_bach_float64_x_x_x_x_", 593, 1070830686, "_x_x_x_x_bach_float64_x_x_x_x_", 18212, 1071108024, "_x_x_x_x_bach_float64_x_x_x_x_", 30705, 1070873751, "_x_x_x_x_bach_float64_x_x_x_x_", 8783, 1071118784, "_x_x_x_x_bach_float64_x_x_x_x_", 31809, 1070917306, "_x_x_x_x_bach_float64_x_x_x_x_", 64887, 1071128691, "_x_x_x_x_bach_float64_x_x_x_x_", 5146, 1070961338, "_x_x_x_x_bach_float64_x_x_x_x_", 31309, 1071137735, "_x_x_x_x_bach_float64_x_x_x_x_", 27797, 1071005832, "_x_x_x_x_bach_float64_x_x_x_x_", 39223, 1071145906, "_x_x_x_x_bach_float64_x_x_x_x_", 62402, 1071050774, "_x_x_x_x_bach_float64_x_x_x_x_", 30682, 1071153193, "_x_x_x_x_bach_float64_x_x_x_x_", 29548, 1071096148, "_x_x_x_x_bach_float64_x_x_x_x_", 38501, 1071159587, "_x_x_x_x_bach_float64_x_x_x_x_", 8583, 1071141939, "_x_x_x_x_bach_float64_x_x_x_x_", 38993, 1071165080, "_x_x_x_x_bach_float64_x_x_x_x_", 39193, 1071188132, "_x_x_x_x_bach_float64_x_x_x_x_", 30135, 1071169661, "_x_x_x_x_bach_float64_x_x_x_x_", 44743, 1071234711, "_x_x_x_x_bach_float64_x_x_x_x_", 4669, 1071173323, "_x_x_x_x_bach_float64_x_x_x_x_", 4987, 1071281661, "_x_x_x_x_bach_float64_x_x_x_x_", 12018, 1071176056, "_x_x_x_x_bach_float64_x_x_x_x_", 47134, 1071328966, "_x_x_x_x_bach_float64_x_x_x_x_", 44214, 1071177852, "_x_x_x_x_bach_float64_x_x_x_x_", 58524, 1071376609, "_x_x_x_x_bach_float64_x_x_x_x_", 5326, 1071178704, "_x_x_x_x_bach_float64_x_x_x_x_", 62601, 1071424576, "_x_x_x_x_bach_float64_x_x_x_x_", 23951, 1071178603, "_x_x_x_x_bach_float64_x_x_x_x_", 43914, 1071472848, "_x_x_x_x_bach_float64_x_x_x_x_", 57680, 1071177542, "_x_x_x_x_bach_float64_x_x_x_x_", 5058, 1071521411, "_x_x_x_x_bach_float64_x_x_x_x_", 32216, 1071175514, "_x_x_x_x_bach_float64_x_x_x_x_", 55202, 1071570248, "_x_x_x_x_bach_float64_x_x_x_x_", 53977, 1071172511, "_x_x_x_x_bach_float64_x_x_x_x_", 2424, 1071619341, "_x_x_x_x_bach_float64_x_x_x_x_", 38460, 1071168527, "_x_x_x_x_bach_float64_x_x_x_x_", 42198, 1071656673, "_x_x_x_x_bach_float64_x_x_x_x_", 62719, 1071163556, "_x_x_x_x_bach_float64_x_x_x_x_", 7889, 1071681451, "_x_x_x_x_bach_float64_x_x_x_x_", 63481, 1071157592, "_x_x_x_x_bach_float64_x_x_x_x_", 9263, 1071706332, "_x_x_x_x_bach_float64_x_x_x_x_", 58294, 1071150627, "_x_x_x_x_bach_float64_x_x_x_x_", 47869, 1071731307, "_x_x_x_x_bach_float64_x_x_x_x_", 35595, 1071142658, "_x_x_x_x_bach_float64_x_x_x_x_", 17831, 1071756368, "_x_x_x_x_bach_float64_x_x_x_x_", 35866, 1071133678, "_x_x_x_x_bach_float64_x_x_x_x_", 5436, 1071781506, "_x_x_x_x_bach_float64_x_x_x_x_", 28607, 1071123682, "_x_x_x_x_bach_float64_x_x_x_x_", 65160, 1071806713, "_x_x_x_x_bach_float64_x_x_x_x_", 41902, 1071112666, "_x_x_x_x_bach_float64_x_x_x_x_", 60058, 1071831978, "_x_x_x_x_bach_float64_x_x_x_x_", 18313, 1071100625, "_x_x_x_x_bach_float64_x_x_x_x_", 23190, 1071857295, "_x_x_x_x_bach_float64_x_x_x_x_", 50593, 1071087555, "_x_x_x_x_bach_float64_x_x_x_x_", 55171, 1071882653, "_x_x_x_x_bach_float64_x_x_x_x_", 12366, 1071073451, "_x_x_x_x_bach_float64_x_x_x_x_", 17908, 1071908043, "_x_x_x_x_bach_float64_x_x_x_x_", 23752, 1071058311, "_x_x_x_x_bach_float64_x_x_x_x_", 5578, 1071933457, "_x_x_x_x_bach_float64_x_x_x_x_", 46339, 1071042131, "_x_x_x_x_bach_float64_x_x_x_x_", 17968, 1071958886, "_x_x_x_x_bach_float64_x_x_x_x_", 47571, 1071024908, "_x_x_x_x_bach_float64_x_x_x_x_", 13768, 1071984321, "_x_x_x_x_bach_float64_x_x_x_x_", 12129, 1071006638, "_x_x_x_x_bach_float64_x_x_x_x_", 14084, 1072009752, "_x_x_x_x_bach_float64_x_x_x_x_", 60850, 1070987321, "_x_x_x_x_bach_float64_x_x_x_x_", 57514, 1072035170, "_x_x_x_x_bach_float64_x_x_x_x_", 20388, 1070966952, "_x_x_x_x_bach_float64_x_x_x_x_", 4689, 1072060566, "_x_x_x_x_bach_float64_x_x_x_x_", 15010, 1070945531, "_x_x_x_x_bach_float64_x_x_x_x_", 42201, 1072085931, "_x_x_x_x_bach_float64_x_x_x_x_", 47603, 1070923057, "_x_x_x_x_bach_float64_x_x_x_x_", 48766, 1072111256, "_x_x_x_x_bach_float64_x_x_x_x_", 10337, 1070899526, "_x_x_x_x_bach_float64_x_x_x_x_", 49759, 1072136531, "_x_x_x_x_bach_float64_x_x_x_x_", 58236, 1070874940, "_x_x_x_x_bach_float64_x_x_x_x_", 54090, 1072161747, "_x_x_x_x_bach_float64_x_x_x_x_", 33722, 1070849296, "_x_x_x_x_bach_float64_x_x_x_x_", 57698, 1072186895, "_x_x_x_x_bach_float64_x_x_x_x_", 38207, 1070822595, "_x_x_x_x_bach_float64_x_x_x_x_", 14927, 1072211966, "_x_x_x_x_bach_float64_x_x_x_x_", 52478, 1070794836, "_x_x_x_x_bach_float64_x_x_x_x_", 37790, 1072236950, "_x_x_x_x_bach_float64_x_x_x_x_", 46699, 1070766020, "_x_x_x_x_bach_float64_x_x_x_x_", 34544, 1072261837, "_x_x_x_x_bach_float64_x_x_x_x_", 54779, 1070736147, "_x_x_x_x_bach_float64_x_x_x_x_", 30584, 1072286619, "_x_x_x_x_bach_float64_x_x_x_x_", 15642, 1070705218, "_x_x_x_x_bach_float64_x_x_x_x_", 55400, 1072311286, "_x_x_x_x_bach_float64_x_x_x_x_", 35942, 1070673234, "_x_x_x_x_bach_float64_x_x_x_x_", 52148, 1072335829, "_x_x_x_x_bach_float64_x_x_x_x_", 24885, 1070640196, "_x_x_x_x_bach_float64_x_x_x_x_", 4303, 1072360238, "_x_x_x_x_bach_float64_x_x_x_x_", 11180, 1070606107, "_x_x_x_x_bach_float64_x_x_x_x_", 15025, 1072384504, "_x_x_x_x_bach_float64_x_x_x_x_", 54851, 1070545842, "_x_x_x_x_bach_float64_x_x_x_x_", 9403, 1072408618, "_x_x_x_x_bach_float64_x_x_x_x_", 40107, 1070473470, "_x_x_x_x_bach_float64_x_x_x_x_", 40391, 1072432569, "_x_x_x_x_bach_float64_x_x_x_x_", 27543, 1070399008, "_x_x_x_x_bach_float64_x_x_x_x_", 16613, 1072456350, "_x_x_x_x_bach_float64_x_x_x_x_", 11408, 1070322463, "_x_x_x_x_bach_float64_x_x_x_x_", 29472, 1072479950, "_x_x_x_x_bach_float64_x_x_x_x_", 29817, 1070243841, "_x_x_x_x_bach_float64_x_x_x_x_", 32174, 1072503360, "_x_x_x_x_bach_float64_x_x_x_x_", 49556, 1070163150, "_x_x_x_x_bach_float64_x_x_x_x_", 48092, 1072526571, "_x_x_x_x_bach_float64_x_x_x_x_", 29360, 1070080396, "_x_x_x_x_bach_float64_x_x_x_x_", 54318, 1072549574, "_x_x_x_x_bach_float64_x_x_x_x_", 30233, 1069995589, "_x_x_x_x_bach_float64_x_x_x_x_", 62442, 1072572358, "_x_x_x_x_bach_float64_x_x_x_x_", 44927, 1069908737, "_x_x_x_x_bach_float64_x_x_x_x_", 1155, 1072594916, "_x_x_x_x_bach_float64_x_x_x_x_", 5146, 1069819849, "_x_x_x_x_bach_float64_x_x_x_x_", 53786, 1072617237, "_x_x_x_x_bach_float64_x_x_x_x_", 32090, 1069728937, "_x_x_x_x_bach_float64_x_x_x_x_", 6798, 1072639312, "_x_x_x_x_bach_float64_x_x_x_x_", 12860, 1069636011, "_x_x_x_x_bach_float64_x_x_x_x_", 31823, 1072661133, "_x_x_x_x_bach_float64_x_x_x_x_", 20895, 1069534644, "_x_x_x_x_bach_float64_x_x_x_x_", 15452, 1072682690, "_x_x_x_x_bach_float64_x_x_x_x_", 602, 1069340804, "_x_x_x_x_bach_float64_x_x_x_x_", 60759, 1072698610, "_x_x_x_x_bach_float64_x_x_x_x_", 30619, 1069143009, "_x_x_x_x_bach_float64_x_x_x_x_", 46660, 1072709111, "_x_x_x_x_bach_float64_x_x_x_x_", 23463, 1068941283, "_x_x_x_x_bach_float64_x_x_x_x_", 55783, 1072719466, "_x_x_x_x_bach_float64_x_x_x_x_", 27927, 1068735655, "_x_x_x_x_bach_float64_x_x_x_x_", 62842, 1072729670, "_x_x_x_x_bach_float64_x_x_x_x_", 29301, 1068526154, "_x_x_x_x_bach_float64_x_x_x_x_", 7766, 1072739720, "_x_x_x_x_bach_float64_x_x_x_x_", 32418, 1068126675, "_x_x_x_x_bach_float64_x_x_x_x_", 28520, 1072749611, "_x_x_x_x_bach_float64_x_x_x_x_", 42329, 1067692362, "_x_x_x_x_bach_float64_x_x_x_x_", 25595, 1072759339, "_x_x_x_x_bach_float64_x_x_x_x_", 26622, 1067050610, "_x_x_x_x_bach_float64_x_x_x_x_", 64363, 1072768898, "_x_x_x_x_bach_float64_x_x_x_x_", 6392, 1065901968, "_x_x_x_x_bach_float64_x_x_x_x_", 41362, 1072778284, "_x_x_x_x_bach_float64_x_x_x_x_", 51813, 3210481141, "_x_x_x_x_bach_float64_x_x_x_x_", 55201, 1072787494, "_x_x_x_x_bach_float64_x_x_x_x_", 50384, 3213874666, "_x_x_x_x_bach_float64_x_x_x_x_", 39173, 1072796523, "_x_x_x_x_bach_float64_x_x_x_x_", 25862, 3214822884, "_x_x_x_x_bach_float64_x_x_x_x_", 30779, 1072805366, "_x_x_x_x_bach_float64_x_x_x_x_", 11208, 3215357066, "_x_x_x_x_bach_float64_x_x_x_x_", 28461, 1072814019, "_x_x_x_x_bach_float64_x_x_x_x_", 6520, 3215842803, "_x_x_x_x_bach_float64_x_x_x_x_", 24295, 1072822479, "_x_x_x_x_bach_float64_x_x_x_x_", 13458, 3216159086, "_x_x_x_x_bach_float64_x_x_x_x_", 14965, 1072830740, "_x_x_x_x_bach_float64_x_x_x_x_", 31693, 3216408954, "_x_x_x_x_bach_float64_x_x_x_x_", 55446, 1072838798, "_x_x_x_x_bach_float64_x_x_x_x_", 24311, 3216662257, "_x_x_x_x_bach_float64_x_x_x_x_", 26678, 1072846650, "_x_x_x_x_bach_float64_x_x_x_x_", 49001, 3216918952, "_x_x_x_x_bach_float64_x_x_x_x_", 33610, 1072854291, "_x_x_x_x_bach_float64_x_x_x_x_", 13498, 3217105081, "_x_x_x_x_bach_float64_x_x_x_x_", 56346, 1072861718, "_x_x_x_x_bach_float64_x_x_x_x_", 6235, 3217236752, "_x_x_x_x_bach_float64_x_x_x_x_", 32945, 1072868925, "_x_x_x_x_bach_float64_x_x_x_x_", 18222, 3217370050, "_x_x_x_x_bach_float64_x_x_x_x_", 45133, 1072875909, "_x_x_x_x_bach_float64_x_x_x_x_", 54381, 3217504950, "_x_x_x_x_bach_float64_x_x_x_x_", 16073, 1072882667, "_x_x_x_x_bach_float64_x_x_x_x_", 54819, 3217641429, "_x_x_x_x_bach_float64_x_x_x_x_", 33230, 1072889194, "_x_x_x_x_bach_float64_x_x_x_x_", 44335, 3217779459, "_x_x_x_x_bach_float64_x_x_x_x_", 50122, 1072895486, "_x_x_x_x_bach_float64_x_x_x_x_", 56244, 3217919017, "_x_x_x_x_bach_float64_x_x_x_x_", 14482, 1072901539, "_x_x_x_x_bach_float64_x_x_x_x_", 23674, 3218060075, "_x_x_x_x_bach_float64_x_x_x_x_", 28591, 1072907350, "_x_x_x_x_bach_float64_x_x_x_x_", 13959, 3218141175, "_x_x_x_x_bach_float64_x_x_x_x_", 16465, 1072912915, "_x_x_x_x_bach_float64_x_x_x_x_", 24049, 3218213164, "_x_x_x_x_bach_float64_x_x_x_x_", 10988, 1072918230, "_x_x_x_x_bach_float64_x_x_x_x_", 30098, 3218285862, "_x_x_x_x_bach_float64_x_x_x_x_", 11389, 1072923292, "_x_x_x_x_bach_float64_x_x_x_x_", 44230, 3218359255, "_x_x_x_x_bach_float64_x_x_x_x_", 65432, 1072928096, "_x_x_x_x_bach_float64_x_x_x_x_", 4165, 3218433328, "_x_x_x_x_bach_float64_x_x_x_x_", 51040, 1072932640, "_x_x_x_x_bach_float64_x_x_x_x_", 39817, 3218508068, "_x_x_x_x_bach_float64_x_x_x_x_", 8275, 1072936919, "_x_x_x_x_bach_float64_x_x_x_x_", 21697, 3218583458, "_x_x_x_x_bach_float64_x_x_x_x_", 37723, 1072940931, "_x_x_x_x_bach_float64_x_x_x_x_", 27025, 3218659484, "_x_x_x_x_bach_float64_x_x_x_x_", 26375, 1072944672, "_x_x_x_x_bach_float64_x_x_x_x_", 17662, 3218736130, "_x_x_x_x_bach_float64_x_x_x_x_", 52058, 1072948139, "_x_x_x_x_bach_float64_x_x_x_x_", 37965, 3218813381, "_x_x_x_x_bach_float64_x_x_x_x_", 23623, 1072951327, "_x_x_x_x_bach_float64_x_x_x_x_", 12876, 3218891221, "_x_x_x_x_bach_float64_x_x_x_x_", 63280, 1072954235, "_x_x_x_x_bach_float64_x_x_x_x_", 61203, 3218969634, "_x_x_x_x_bach_float64_x_x_x_x_", 57264, 1072956859, "_x_x_x_x_bach_float64_x_x_x_x_", 10889, 3219048603, "_x_x_x_x_bach_float64_x_x_x_x_", 12282, 1072959195, "_x_x_x_x_bach_float64_x_x_x_x_", 14309, 3219128111, "_x_x_x_x_bach_float64_x_x_x_x_", 37190, 1072961241, "_x_x_x_x_bach_float64_x_x_x_x_", 49110, 3219168231, "_x_x_x_x_bach_float64_x_x_x_x_", 14477, 1072962993, "_x_x_x_x_bach_float64_x_x_x_x_", 43796, 3219208500, "_x_x_x_x_bach_float64_x_x_x_x_", 9246, 1072964449, "_x_x_x_x_bach_float64_x_x_x_x_", 48580, 3219249013, "_x_x_x_x_bach_float64_x_x_x_x_", 38526, 1072965606, "_x_x_x_x_bach_float64_x_x_x_x_", 7536, 3219289762, "_x_x_x_x_bach_float64_x_x_x_x_", 51985, 1072966461, "_x_x_x_x_bach_float64_x_x_x_x_", 36466, 3219330737, "_x_x_x_x_bach_float64_x_x_x_x_", 57605, 1072967011, "_x_x_x_x_bach_float64_x_x_x_x_", 37328, 3219371931, "_x_x_x_x_bach_float64_x_x_x_x_", 63820, 1072967253, "_x_x_x_x_bach_float64_x_x_x_x_", 16800, 3219413333, "_x_x_x_x_bach_float64_x_x_x_x_", 33782, 1072967185, "_x_x_x_x_bach_float64_x_x_x_x_", 58983, 3219454935, "_x_x_x_x_bach_float64_x_x_x_x_", 47568, 1072966804, "_x_x_x_x_bach_float64_x_x_x_x_", 16171, 3219496727, "_x_x_x_x_bach_float64_x_x_x_x_", 16103, 1072966108, "_x_x_x_x_bach_float64_x_x_x_x_", 30414, 3219538701, "_x_x_x_x_bach_float64_x_x_x_x_", 60061, 1072965095, "_x_x_x_x_bach_float64_x_x_x_x_", 49142, 3219580847, "_x_x_x_x_bach_float64_x_x_x_x_", 45619, 1072963761, "_x_x_x_x_bach_float64_x_x_x_x_", 37339, 3219623154, "_x_x_x_x_bach_float64_x_x_x_x_", 45700, 1072962104, "_x_x_x_x_bach_float64_x_x_x_x_", 32620, 3219665615, "_x_x_x_x_bach_float64_x_x_x_x_", 21986, 1072960123, "_x_x_x_x_bach_float64_x_x_x_x_", 41589, 3219708219, "_x_x_x_x_bach_float64_x_x_x_x_", 37601, 1072957815, "_x_x_x_x_bach_float64_x_x_x_x_", 38016, 3219750955, "_x_x_x_x_bach_float64_x_x_x_x_", 16685, 1072955178, "_x_x_x_x_bach_float64_x_x_x_x_", 61043, 3219793816, "_x_x_x_x_bach_float64_x_x_x_x_", 33088, 1072952210, "_x_x_x_x_bach_float64_x_x_x_x_", 18692, 3219836790, "_x_x_x_x_bach_float64_x_x_x_x_", 13347, 1072948909, "_x_x_x_x_bach_float64_x_x_x_x_", 46692, 3219879867, "_x_x_x_x_bach_float64_x_x_x_x_", 32831, 1072945273, "_x_x_x_x_bach_float64_x_x_x_x_", 44831, 3219923038, "_x_x_x_x_bach_float64_x_x_x_x_", 24677, 1072941301, "_x_x_x_x_bach_float64_x_x_x_x_", 27379, 3219966292, "_x_x_x_x_bach_float64_x_x_x_x_", 14913, 1072936990, "_x_x_x_x_bach_float64_x_x_x_x_", 40544, 3220009619, "_x_x_x_x_bach_float64_x_x_x_x_", 31083, 1072932339, "_x_x_x_x_bach_float64_x_x_x_x_", 38541, 3220053008, "_x_x_x_x_bach_float64_x_x_x_x_", 11367, 1072927346, "_x_x_x_x_bach_float64_x_x_x_x_", 43944, 3220096451, "_x_x_x_x_bach_float64_x_x_x_x_", 41178, 1072922010, "_x_x_x_x_bach_float64_x_x_x_x_", 826, 3220139935, "_x_x_x_x_bach_float64_x_x_x_x_", 64610, 1072916330, "_x_x_x_x_bach_float64_x_x_x_x_", 52525, 3220180173, "_x_x_x_x_bach_float64_x_x_x_x_", 53119, 1072910303, "_x_x_x_x_bach_float64_x_x_x_x_", 51366, 3220201941, "_x_x_x_x_bach_float64_x_x_x_x_", 40951, 1072903929, "_x_x_x_x_bach_float64_x_x_x_x_", 22552, 3220223715, "_x_x_x_x_bach_float64_x_x_x_x_", 26710, 1072897207, "_x_x_x_x_bach_float64_x_x_x_x_", 3831, 3220245488, "_x_x_x_x_bach_float64_x_x_x_x_", 2561, 1072890135, "_x_x_x_x_bach_float64_x_x_x_x_", 8383, 3220267256, "_x_x_x_x_bach_float64_x_x_x_x_", 44961, 1072882713, "_x_x_x_x_bach_float64_x_x_x_x_", 58087, 3220289012, "_x_x_x_x_bach_float64_x_x_x_x_", 7541, 1072874939, "_x_x_x_x_bach_float64_x_x_x_x_", 56428, 3220310753, "_x_x_x_x_bach_float64_x_x_x_x_", 60762, 1072866812, "_x_x_x_x_bach_float64_x_x_x_x_", 24273, 3220332471, "_x_x_x_x_bach_float64_x_x_x_x_", 46174, 1072858332, "_x_x_x_x_bach_float64_x_x_x_x_", 42239, 3220354163, "_x_x_x_x_bach_float64_x_x_x_x_", 3993, 1072849498, "_x_x_x_x_bach_float64_x_x_x_x_", 29602, 3220375821, "_x_x_x_x_bach_float64_x_x_x_x_", 38484, 1072840310, "_x_x_x_x_bach_float64_x_x_x_x_", 14178, 3220397442, "_x_x_x_x_bach_float64_x_x_x_x_", 44895, 1072830766, "_x_x_x_x_bach_float64_x_x_x_x_", 40144, 3220419018, "_x_x_x_x_bach_float64_x_x_x_x_", 18332, 1072820866, "_x_x_x_x_bach_float64_x_x_x_x_", 40395, 3220440546, "_x_x_x_x_bach_float64_x_x_x_x_", 26596, 1072810611, "_x_x_x_x_bach_float64_x_x_x_x_", 164, 3220462018, "_x_x_x_x_bach_float64_x_x_x_x_", 43080, 1072799999, "_x_x_x_x_bach_float64_x_x_x_x_", 17549, 3220483430, "_x_x_x_x_bach_float64_x_x_x_x_", 32507, 1072789030, "_x_x_x_x_bach_float64_x_x_x_x_", 63340, 3220504776, "_x_x_x_x_bach_float64_x_x_x_x_", 26886, 1072777704, "_x_x_x_x_bach_float64_x_x_x_x_", 28848, 3220526050, "_x_x_x_x_bach_float64_x_x_x_x_", 60221, 1072766022, "_x_x_x_x_bach_float64_x_x_x_x_", 60736, 3220547247, "_x_x_x_x_bach_float64_x_x_x_x_", 27030, 1072753983, "_x_x_x_x_bach_float64_x_x_x_x_", 2032, 3220568362, "_x_x_x_x_bach_float64_x_x_x_x_", 54159, 1072741587, "_x_x_x_x_bach_float64_x_x_x_x_", 35474, 3220589388, "_x_x_x_x_bach_float64_x_x_x_x_", 9187, 1072728834, "_x_x_x_x_bach_float64_x_x_x_x_", 37684, 3220610319, "_x_x_x_x_bach_float64_x_x_x_x_", 45634, 1072715726, "_x_x_x_x_bach_float64_x_x_x_x_", 2353, 3220631151, "_x_x_x_x_bach_float64_x_x_x_x_", 21895, 1072702261, "_x_x_x_x_bach_float64_x_x_x_x_", 24079, 3220651878, "_x_x_x_x_bach_float64_x_x_x_x_", 43591, 1072683635, "_x_x_x_x_bach_float64_x_x_x_x_", 38236, 3220672493, "_x_x_x_x_bach_float64_x_x_x_x_", 20742, 1072655285, "_x_x_x_x_bach_float64_x_x_x_x_", 36795, 3220692992, "_x_x_x_x_bach_float64_x_x_x_x_", 1548, 1072626227, "_x_x_x_x_bach_float64_x_x_x_x_", 37965, 3220713368, "_x_x_x_x_bach_float64_x_x_x_x_", 22333, 1072596461, "_x_x_x_x_bach_float64_x_x_x_x_", 5202, 3220733616, "_x_x_x_x_bach_float64_x_x_x_x_", 15774, 1072565990, "_x_x_x_x_bach_float64_x_x_x_x_", 42139, 3220753731, "_x_x_x_x_bach_float64_x_x_x_x_", 62472, 1072534815, "_x_x_x_x_bach_float64_x_x_x_x_", 10280, 3220773706, "_x_x_x_x_bach_float64_x_x_x_x_", 24302, 1072502939, "_x_x_x_x_bach_float64_x_x_x_x_", 10183, 3220793536, "_x_x_x_x_bach_float64_x_x_x_x_", 745, 1072470362, "_x_x_x_x_bach_float64_x_x_x_x_", 21007, 3220813215, "_x_x_x_x_bach_float64_x_x_x_x_", 34997, 1072437088, "_x_x_x_x_bach_float64_x_x_x_x_", 8043, 3220832738, "_x_x_x_x_bach_float64_x_x_x_x_", 52433, 1072403119, "_x_x_x_x_bach_float64_x_x_x_x_", 38240, 3220852099, "_x_x_x_x_bach_float64_x_x_x_x_", 31123, 1072368458, "_x_x_x_x_bach_float64_x_x_x_x_", 9505, 3220871293, "_x_x_x_x_bach_float64_x_x_x_x_", 10733, 1072333107, "_x_x_x_x_bach_float64_x_x_x_x_", 41033, 3220890313, "_x_x_x_x_bach_float64_x_x_x_x_", 5188, 1072297070, "_x_x_x_x_bach_float64_x_x_x_x_", 16320, 3220909155, "_x_x_x_x_bach_float64_x_x_x_x_", 15281, 1072260349, "_x_x_x_x_bach_float64_x_x_x_x_", 47094, 3220927812, "_x_x_x_x_bach_float64_x_x_x_x_", 10029, 1072222949, "_x_x_x_x_bach_float64_x_x_x_x_", 22008, 3220946279, "_x_x_x_x_bach_float64_x_x_x_x_", 7580, 1072184871, "_x_x_x_x_bach_float64_x_x_x_x_", 8438, 3220964551, "_x_x_x_x_bach_float64_x_x_x_x_", 58879, 1072146121, "_x_x_x_x_bach_float64_x_x_x_x_", 64362, 3220982621, "_x_x_x_x_bach_float64_x_x_x_x_", 2968, 1072106702, "_x_x_x_x_bach_float64_x_x_x_x_", 49064, 3221000485, "_x_x_x_x_bach_float64_x_x_x_x_", 42224, 1072066617, "_x_x_x_x_bach_float64_x_x_x_x_", 21224, 3221018136, "_x_x_x_x_bach_float64_x_x_x_x_", 40492, 1072025872, "_x_x_x_x_bach_float64_x_x_x_x_", 43655, 3221035570, "_x_x_x_x_bach_float64_x_x_x_x_", 34289, 1071984470, "_x_x_x_x_bach_float64_x_x_x_x_", 48849, 3221052781, "_x_x_x_x_bach_float64_x_x_x_x_", 56566, 1071942417, "_x_x_x_x_bach_float64_x_x_x_x_", 26270, 3221069764, "_x_x_x_x_bach_float64_x_x_x_x_", 59571, 1071899716, "_x_x_x_x_bach_float64_x_x_x_x_", 5993, 3221086512, "_x_x_x_x_bach_float64_x_x_x_x_", 2246, 1071856373, "_x_x_x_x_bach_float64_x_x_x_x_", 34087, 3221103021, "_x_x_x_x_bach_float64_x_x_x_x_", 36845, 1071812392, "_x_x_x_x_bach_float64_x_x_x_x_", 7520, 3221119285, "_x_x_x_x_bach_float64_x_x_x_x_", 8362, 1071767779, "_x_x_x_x_bach_float64_x_x_x_x_", 22734, 3221135299, "_x_x_x_x_bach_float64_x_x_x_x_", 36519, 1071722540, "_x_x_x_x_bach_float64_x_x_x_x_", 57147, 3221151058, "_x_x_x_x_bach_float64_x_x_x_x_", 17638, 1071676680, "_x_x_x_x_bach_float64_x_x_x_x_", 30889, 3221166556, "_x_x_x_x_bach_float64_x_x_x_x_", 25799, 1071615736, "_x_x_x_x_bach_float64_x_x_x_x_", 51086, 3221181788, "_x_x_x_x_bach_float64_x_x_x_x_", 31470, 1071521566, "_x_x_x_x_bach_float64_x_x_x_x_", 51036, 3221196749, "_x_x_x_x_bach_float64_x_x_x_x_", 32512, 1071426188, "_x_x_x_x_bach_float64_x_x_x_x_", 2776, 3221211433, "_x_x_x_x_bach_float64_x_x_x_x_", 5130, 1071329616, "_x_x_x_x_bach_float64_x_x_x_x_", 23255, 3221225654, "_x_x_x_x_bach_float64_x_x_x_x_", 60626, 1071231862, "_x_x_x_x_bach_float64_x_x_x_x_", 5727, 3221232712, "_x_x_x_x_bach_float64_x_x_x_x_", 1195, 1071132940, "_x_x_x_x_bach_float64_x_x_x_x_", 15436, 3221239625, "_x_x_x_x_bach_float64_x_x_x_x_", 62256, 1071032863, "_x_x_x_x_bach_float64_x_x_x_x_", 10952, 3221246389, "_x_x_x_x_bach_float64_x_x_x_x_", 24668, 1070931645, "_x_x_x_x_bach_float64_x_x_x_x_", 30334, 3221253002, "_x_x_x_x_bach_float64_x_x_x_x_", 39746, 1070829299, "_x_x_x_x_bach_float64_x_x_x_x_", 39309, 3221259461, "_x_x_x_x_bach_float64_x_x_x_x_", 22536, 1070725840, "_x_x_x_x_bach_float64_x_x_x_x_", 29307, 3221265765, "_x_x_x_x_bach_float64_x_x_x_x_", 39429, 1070621284, "_x_x_x_x_bach_float64_x_x_x_x_", 37134, 3221271911, "_x_x_x_x_bach_float64_x_x_x_x_", 39631, 1070435193, "_x_x_x_x_bach_float64_x_x_x_x_", 20137, 3221277896, "_x_x_x_x_bach_float64_x_x_x_x_", 11368, 1070221778, "_x_x_x_x_bach_float64_x_x_x_x_", 45085, 3221283719, "_x_x_x_x_bach_float64_x_x_x_x_", 45530, 1070006260, "_x_x_x_x_bach_float64_x_x_x_x_", 3711, 3221289375, "_x_x_x_x_bach_float64_x_x_x_x_", 1679, 1069788670, "_x_x_x_x_bach_float64_x_x_x_x_", 34060, 3221294864, "_x_x_x_x_bach_float64_x_x_x_x_", 12739, 1069569040, "_x_x_x_x_bach_float64_x_x_x_x_", 8622, 3221300183, "_x_x_x_x_bach_float64_x_x_x_x_", 11989, 1069147290, "_x_x_x_x_bach_float64_x_x_x_x_", 54817, 3221305330, "_x_x_x_x_bach_float64_x_x_x_x_", 37606, 1068700075, "_x_x_x_x_bach_float64_x_x_x_x_", 10073, 3221310302, "_x_x_x_x_bach_float64_x_x_x_x_", 8199, 1067999024, "_x_x_x_x_bach_float64_x_x_x_x_", 39219, 3221315098, "_x_x_x_x_bach_float64_x_x_x_x_", 60103, 1066728094, "_x_x_x_x_bach_float64_x_x_x_x_", 54284, 3221319714, "_x_x_x_x_bach_float64_x_x_x_x_", 47047, 3212578291, "_x_x_x_x_bach_float64_x_x_x_x_", 33361, 3221324149, "_x_x_x_x_bach_float64_x_x_x_x_", 4707, 3215039847, "_x_x_x_x_bach_float64_x_x_x_x_", 58283, 3221328401, "_x_x_x_x_bach_float64_x_x_x_x_", 38051, 3215971609, "_x_x_x_x_bach_float64_x_x_x_x_", 5088, 3221332467, "_x_x_x_x_bach_float64_x_x_x_x_", 20496, 3216446495, "_x_x_x_x_bach_float64_x_x_x_x_", 789, 3221336346, "_x_x_x_x_bach_float64_x_x_x_x_", 9713, 3216919327, "_x_x_x_x_bach_float64_x_x_x_x_", 7550, 3221340035, "_x_x_x_x_bach_float64_x_x_x_x_", 22864, 3217213343, "_x_x_x_x_bach_float64_x_x_x_x_", 41032, 3221343533, "_x_x_x_x_bach_float64_x_x_x_x_", 8859, 3217453081, "_x_x_x_x_bach_float64_x_x_x_x_", 39370, 3221346837, "_x_x_x_x_bach_float64_x_x_x_x_", 40659, 3217694420, "_x_x_x_x_bach_float64_x_x_x_x_", 37569, 3221349945, "_x_x_x_x_bach_float64_x_x_x_x_", 36701, 3217937321, "_x_x_x_x_bach_float64_x_x_x_x_", 57004, 3221352856, "_x_x_x_x_bach_float64_x_x_x_x_", 15157, 3218130743, "_x_x_x_x_bach_float64_x_x_x_x_", 37182, 3221355568, "_x_x_x_x_bach_float64_x_x_x_x_", 28040, 3218253694, "_x_x_x_x_bach_float64_x_x_x_x_", 5823, 3221358078, "_x_x_x_x_bach_float64_x_x_x_x_", 1360, 3218377363, "_x_x_x_x_bach_float64_x_x_x_x_", 28043, 3221360385, "_x_x_x_x_bach_float64_x_x_x_x_", 42299, 3218501731, "_x_x_x_x_bach_float64_x_x_x_x_", 65164, 3221362487, "_x_x_x_x_bach_float64_x_x_x_x_", 12276, 3218626774, "_x_x_x_x_bach_float64_x_x_x_x_", 4803, 3221364382, "_x_x_x_x_bach_float64_x_x_x_x_", 11851, 3218752473, "_x_x_x_x_bach_float64_x_x_x_x_", 58354, 3221366069, "_x_x_x_x_bach_float64_x_x_x_x_", 20134, 3218878804, "_x_x_x_x_bach_float64_x_x_x_x_", 18024, 3221367546, "_x_x_x_x_bach_float64_x_x_x_x_", 61379, 3219005747, "_x_x_x_x_bach_float64_x_x_x_x_", 59921, 3221368812, "_x_x_x_x_bach_float64_x_x_x_x_", 55230, 3219130798, "_x_x_x_x_bach_float64_x_x_x_x_", 12510, 3221369863, "_x_x_x_x_bach_float64_x_x_x_x_", 30602, 3219194847, "_x_x_x_x_bach_float64_x_x_x_x_", 39063, 3221370700, "_x_x_x_x_bach_float64_x_x_x_x_", 41648, 3219259166, "_x_x_x_x_bach_float64_x_x_x_x_", 46667, 3221371321, "_x_x_x_x_bach_float64_x_x_x_x_", 26616, 3219323746, "_x_x_x_x_bach_float64_x_x_x_x_", 49538, 3221371723, "_x_x_x_x_bach_float64_x_x_x_x_", 11369, 3219388574, "_x_x_x_x_bach_float64_x_x_x_x_", 44363, 3221371906, "_x_x_x_x_bach_float64_x_x_x_x_", 9032, 3219453639, "_x_x_x_x_bach_float64_x_x_x_x_", 52590, 3221371869, "_x_x_x_x_bach_float64_x_x_x_x_", 41834, 3219518928, "_x_x_x_x_bach_float64_x_x_x_x_", 1514, 3221371609, "_x_x_x_x_bach_float64_x_x_x_x_", 21814, 3219584430, "_x_x_x_x_bach_float64_x_x_x_x_", 33541, 3221371125, "_x_x_x_x_bach_float64_x_x_x_x_", 12895, 3219650133, "_x_x_x_x_bach_float64_x_x_x_x_", 63523, 3221370417, "_x_x_x_x_bach_float64_x_x_x_x_", 20645, 3219716024, "_x_x_x_x_bach_float64_x_x_x_x_", 25521, 3221369482, "_x_x_x_x_bach_float64_x_x_x_x_", 29205, 3219782092, "_x_x_x_x_bach_float64_x_x_x_x_", 22133, 3221368320, "_x_x_x_x_bach_float64_x_x_x_x_", 21187, 3219848323, "_x_x_x_x_bach_float64_x_x_x_x_", 48264, 3221366930, "_x_x_x_x_bach_float64_x_x_x_x_", 44821, 3219914706, "_x_x_x_x_bach_float64_x_x_x_x_", 9827, 3221365309, "_x_x_x_x_bach_float64_x_x_x_x_", 64028, 3219981228, "_x_x_x_x_bach_float64_x_x_x_x_", 36930, 3221363459, "_x_x_x_x_bach_float64_x_x_x_x_", 48594, 3220047876, "_x_x_x_x_bach_float64_x_x_x_x_", 42596, 3221361376, "_x_x_x_x_bach_float64_x_x_x_x_", 40698, 3220114637, "_x_x_x_x_bach_float64_x_x_x_x_", 33898, 3221359060, "_x_x_x_x_bach_float64_x_x_x_x_", 32240, 3220179198, "_x_x_x_x_bach_float64_x_x_x_x_", 61033, 3221356511, "_x_x_x_x_bach_float64_x_x_x_x_", 4156, 3220212672, "_x_x_x_x_bach_float64_x_x_x_x_", 516, 3221353727, "_x_x_x_x_bach_float64_x_x_x_x_", 964, 3220246185, "_x_x_x_x_bach_float64_x_x_x_x_", 24104, 3221350708, "_x_x_x_x_bach_float64_x_x_x_x_", 20676, 3220279728, "_x_x_x_x_bach_float64_x_x_x_x_", 49100, 3221347452, "_x_x_x_x_bach_float64_x_x_x_x_", 19841, 3220313296, "_x_x_x_x_bach_float64_x_x_x_x_", 4703, 3221343959, "_x_x_x_x_bach_float64_x_x_x_x_", 52305, 3220346881, "_x_x_x_x_bach_float64_x_x_x_x_", 62042, 3221340228, "_x_x_x_x_bach_float64_x_x_x_x_", 61947, 3220380477, "_x_x_x_x_bach_float64_x_x_x_x_", 41110, 3221336259, "_x_x_x_x_bach_float64_x_x_x_x_", 49019, 3220414078, "_x_x_x_x_bach_float64_x_x_x_x_", 25859, 3221332050, "_x_x_x_x_bach_float64_x_x_x_x_", 19404, 3220447677, "_x_x_x_x_bach_float64_x_x_x_x_", 24413, 3221327602, "_x_x_x_x_bach_float64_x_x_x_x_", 43496, 3220481266, "_x_x_x_x_bach_float64_x_x_x_x_", 50324, 3221322913, "_x_x_x_x_bach_float64_x_x_x_x_", 30307, 3220514840, "_x_x_x_x_bach_float64_x_x_x_x_", 34698, 3221317983, "_x_x_x_x_bach_float64_x_x_x_x_", 2443, 3220548391, "_x_x_x_x_bach_float64_x_x_x_x_", 27625, 3221312812, "_x_x_x_x_bach_float64_x_x_x_x_", 18694, 3220581913, "_x_x_x_x_bach_float64_x_x_x_x_", 33235, 3221307399, "_x_x_x_x_bach_float64_x_x_x_x_", 5459, 3220615398, "_x_x_x_x_bach_float64_x_x_x_x_", 2334, 3221301745, "_x_x_x_x_bach_float64_x_x_x_x_", 20315, 3220648840, "_x_x_x_x_bach_float64_x_x_x_x_", 47879, 3221295848, "_x_x_x_x_bach_float64_x_x_x_x_", 28935, 3220682233, "_x_x_x_x_bach_float64_x_x_x_x_", 30994, 3221289708, "_x_x_x_x_bach_float64_x_x_x_x_", 46484, 3220715568, "_x_x_x_x_bach_float64_x_x_x_x_", 24601, 3221283325, "_x_x_x_x_bach_float64_x_x_x_x_", 52372, 3220748839, "_x_x_x_x_bach_float64_x_x_x_x_", 15927, 3221276700, "_x_x_x_x_bach_float64_x_x_x_x_", 5156, 3220782040, "_x_x_x_x_bach_float64_x_x_x_x_", 27311, 3221269831, "_x_x_x_x_bach_float64_x_x_x_x_", 21841, 3220815163, "_x_x_x_x_bach_float64_x_x_x_x_", 65205, 3221262719, "_x_x_x_x_bach_float64_x_x_x_x_", 65170, 3220848201, "_x_x_x_x_bach_float64_x_x_x_x_", 28128, 3221255364, "_x_x_x_x_bach_float64_x_x_x_x_", 55394, 3220881147, "_x_x_x_x_bach_float64_x_x_x_x_", 32166, 3221247765, "_x_x_x_x_bach_float64_x_x_x_x_", 11962, 3220913994, "_x_x_x_x_bach_float64_x_x_x_x_", 39562, 3221239924, "_x_x_x_x_bach_float64_x_x_x_x_", 27587, 3220946735, "_x_x_x_x_bach_float64_x_x_x_x_", 35408, 3221231840, "_x_x_x_x_bach_float64_x_x_x_x_", 7905, 3220979364, "_x_x_x_x_bach_float64_x_x_x_x_", 62572, 3221221553, "_x_x_x_x_bach_float64_x_x_x_x_", 27529, 3221011872, "_x_x_x_x_bach_float64_x_x_x_x_", 53397, 3221204414, "_x_x_x_x_bach_float64_x_x_x_x_", 56263, 3221044254, "_x_x_x_x_bach_float64_x_x_x_x_", 52813, 3221186790, "_x_x_x_x_bach_float64_x_x_x_x_", 37163, 3221076501, "_x_x_x_x_bach_float64_x_x_x_x_", 30251, 3221168683, "_x_x_x_x_bach_float64_x_x_x_x_", 53384, 3221108607, "_x_x_x_x_bach_float64_x_x_x_x_", 40975, 3221150092, "_x_x_x_x_bach_float64_x_x_x_x_", 58090, 3221140565, "_x_x_x_x_bach_float64_x_x_x_x_", 3843, 3221131019, "_x_x_x_x_bach_float64_x_x_x_x_", 18333, 3221172367, "_x_x_x_x_bach_float64_x_x_x_x_", 47998, 3221111465, "_x_x_x_x_bach_float64_x_x_x_x_", 13030, 3221204007, "_x_x_x_x_bach_float64_x_x_x_x_", 51977, 3221091431, "_x_x_x_x_bach_float64_x_x_x_x_", 43519, 3221230474, "_x_x_x_x_bach_float64_x_x_x_x_", 13212, 3221070918, "_x_x_x_x_bach_float64_x_x_x_x_", 28461, 3221246121, "_x_x_x_x_bach_float64_x_x_x_x_", 2476, 3221049928, "_x_x_x_x_bach_float64_x_x_x_x_", 59529, 3221261676, "_x_x_x_x_bach_float64_x_x_x_x_", 30678, 3221028461, "_x_x_x_x_bach_float64_x_x_x_x_", 48091, 3221277136, "_x_x_x_x_bach_float64_x_x_x_x_", 24202, 3221006519, "_x_x_x_x_bach_float64_x_x_x_x_", 4121, 3221292497, "_x_x_x_x_bach_float64_x_x_x_x_", 39814, 3220984105, "_x_x_x_x_bach_float64_x_x_x_x_", 32801, 3221307755, "_x_x_x_x_bach_float64_x_x_x_x_", 63293, 3220961218, "_x_x_x_x_bach_float64_x_x_x_x_", 9026, 3221322907, "_x_x_x_x_bach_float64_x_x_x_x_", 47086, 3220937863, "_x_x_x_x_bach_float64_x_x_x_x_", 43205, 3221337950, "_x_x_x_x_bach_float64_x_x_x_x_", 55641, 3220914039, "_x_x_x_x_bach_float64_x_x_x_x_", 33855, 3221352880, "_x_x_x_x_bach_float64_x_x_x_x_", 59419, 3220889750, "_x_x_x_x_bach_float64_x_x_x_x_", 10338, 3221367693, "_x_x_x_x_bach_float64_x_x_x_x_", 32846, 3220864997, "_x_x_x_x_bach_float64_x_x_x_x_", 19854, 3221382386, "_x_x_x_x_bach_float64_x_x_x_x_", 28348, 3220839783, "_x_x_x_x_bach_float64_x_x_x_x_", 16849, 3221396956, "_x_x_x_x_bach_float64_x_x_x_x_", 29618, 3220814109, "_x_x_x_x_bach_float64_x_x_x_x_", 16427, 3221411398, "_x_x_x_x_bach_float64_x_x_x_x_", 42879, 3220787979, "_x_x_x_x_bach_float64_x_x_x_x_", 52262, 3221425710, "_x_x_x_x_bach_float64_x_x_x_x_", 32722, 3220761395, "_x_x_x_x_bach_float64_x_x_x_x_", 4019, 3221439889, "_x_x_x_x_bach_float64_x_x_x_x_", 30156, 3220734359, "_x_x_x_x_bach_float64_x_x_x_x_", 14487, 3221453929, "_x_x_x_x_bach_float64_x_x_x_x_", 19483, 3220706875, "_x_x_x_x_bach_float64_x_x_x_x_", 54071, 3221467829, "_x_x_x_x_bach_float64_x_x_x_x_", 62870, 3220678944, "_x_x_x_x_bach_float64_x_x_x_x_", 8172, 3221481585, "_x_x_x_x_bach_float64_x_x_x_x_", 6983, 3220650570, "_x_x_x_x_bach_float64_x_x_x_x_", 24776, 3221495193, "_x_x_x_x_bach_float64_x_x_x_x_", 17056, 3220621756, "_x_x_x_x_bach_float64_x_x_x_x_", 7438, 3221508650, "_x_x_x_x_bach_float64_x_x_x_x_", 37751, 3220592506, "_x_x_x_x_bach_float64_x_x_x_x_", 22519, 3221521952, "_x_x_x_x_bach_float64_x_x_x_x_", 15748, 3220562821, "_x_x_x_x_bach_float64_x_x_x_x_", 47213, 3221535097, "_x_x_x_x_bach_float64_x_x_x_x_", 32324, 3220532707, "_x_x_x_x_bach_float64_x_x_x_x_", 40696, 3221548080, "_x_x_x_x_bach_float64_x_x_x_x_", 18071, 3220502165, "_x_x_x_x_bach_float64_x_x_x_x_", 10170, 3221560899, "_x_x_x_x_bach_float64_x_x_x_x_", 33013, 3220471200, "_x_x_x_x_bach_float64_x_x_x_x_", 5555, 3221573550, "_x_x_x_x_bach_float64_x_x_x_x_", 63601, 3220439815, "_x_x_x_x_bach_float64_x_x_x_x_", 42219, 3221586030, "_x_x_x_x_bach_float64_x_x_x_x_", 57457, 3220408014, "_x_x_x_x_bach_float64_x_x_x_x_", 16698, 3221598335, "_x_x_x_x_bach_float64_x_x_x_x_", 65097, 3220375801, "_x_x_x_x_bach_float64_x_x_x_x_", 7895, 3221610463, "_x_x_x_x_bach_float64_x_x_x_x_", 29900, 3220343180, "_x_x_x_x_bach_float64_x_x_x_x_", 45692, 3221622410, "_x_x_x_x_bach_float64_x_x_x_x_", 12915, 3220310154, "_x_x_x_x_bach_float64_x_x_x_x_", 1672, 3221634172, "_x_x_x_x_bach_float64_x_x_x_x_", 786, 3220276728, "_x_x_x_x_bach_float64_x_x_x_x_", 60066, 3221645747, "_x_x_x_x_bach_float64_x_x_x_x_", 17718, 3220242907, "_x_x_x_x_bach_float64_x_x_x_x_", 64398, 3221657132, "_x_x_x_x_bach_float64_x_x_x_x_", 17646, 3220208693, "_x_x_x_x_bach_float64_x_x_x_x_", 32871, 3221668323, "_x_x_x_x_bach_float64_x_x_x_x_", 30590, 3220171290, "_x_x_x_x_bach_float64_x_x_x_x_", 6967, 3221679317, "_x_x_x_x_bach_float64_x_x_x_x_", 61272, 3220101323, "_x_x_x_x_bach_float64_x_x_x_x_", 18962, 3221690111, "_x_x_x_x_bach_float64_x_x_x_x_", 21479, 3220030601, "_x_x_x_x_bach_float64_x_x_x_x_", 46714, 3221700702, "_x_x_x_x_bach_float64_x_x_x_x_", 48196, 3219959131, "_x_x_x_x_bach_float64_x_x_x_x_", 20627, 3221711087, "_x_x_x_x_bach_float64_x_x_x_x_", 14203, 3219886925, "_x_x_x_x_bach_float64_x_x_x_x_", 13215, 3221721263, "_x_x_x_x_bach_float64_x_x_x_x_", 25798, 3219813991, "_x_x_x_x_bach_float64_x_x_x_x_", 20844, 3221731227, "_x_x_x_x_bach_float64_x_x_x_x_", 26000, 3219740339, "_x_x_x_x_bach_float64_x_x_x_x_", 57912, 3221740976, "_x_x_x_x_bach_float64_x_x_x_x_", 11019, 3219665980, "_x_x_x_x_bach_float64_x_x_x_x_", 38542, 3221750507, "_x_x_x_x_bach_float64_x_x_x_x_", 8530, 3219590924, "_x_x_x_x_bach_float64_x_x_x_x_", 35050, 3221759817, "_x_x_x_x_bach_float64_x_x_x_x_", 15558, 3219515182, "_x_x_x_x_bach_float64_x_x_x_x_", 60542, 3221768904, "_x_x_x_x_bach_float64_x_x_x_x_", 27619, 3219438763, "_x_x_x_x_bach_float64_x_x_x_x_", 30398, 3221777763, "_x_x_x_x_bach_float64_x_x_x_x_", 28688, 3219361680, "_x_x_x_x_bach_float64_x_x_x_x_", 33161, 3221786394, "_x_x_x_x_bach_float64_x_x_x_x_", 8807, 3219283942, "_x_x_x_x_bach_float64_x_x_x_x_", 58160, 3221794792, "_x_x_x_x_bach_float64_x_x_x_x_", 9901, 3219205562, "_x_x_x_x_bach_float64_x_x_x_x_", 31318, 3221802955, "_x_x_x_x_bach_float64_x_x_x_x_", 8746, 3219124782, "_x_x_x_x_bach_float64_x_x_x_x_", 27387, 3221810880, "_x_x_x_x_bach_float64_x_x_x_x_", 593, 3218965519, "_x_x_x_x_bach_float64_x_x_x_x_", 2740, 3221818565, "_x_x_x_x_bach_float64_x_x_x_x_", 28691, 3218805040, "_x_x_x_x_bach_float64_x_x_x_x_", 31067, 3221826007, "_x_x_x_x_bach_float64_x_x_x_x_", 22217, 3218643368, "_x_x_x_x_bach_float64_x_x_x_x_", 58413, 3221833204, "_x_x_x_x_bach_float64_x_x_x_x_", 14140, 3218480528, "_x_x_x_x_bach_float64_x_x_x_x_", 28899, 3221840152, "_x_x_x_x_bach_float64_x_x_x_x_", 24838, 3218316544, "_x_x_x_x_bach_float64_x_x_x_x_", 52855, 3221846850, "_x_x_x_x_bach_float64_x_x_x_x_", 16424, 3218151441, "_x_x_x_x_bach_float64_x_x_x_x_", 26985, 3221853294, "_x_x_x_x_bach_float64_x_x_x_x_", 39251, 3217890744, "_x_x_x_x_bach_float64_x_x_x_x_", 16658, 3221859483, "_x_x_x_x_bach_float64_x_x_x_x_", 16345, 3217556213, "_x_x_x_x_bach_float64_x_x_x_x_", 23541, 3221865413, "_x_x_x_x_bach_float64_x_x_x_x_", 31849, 3217219595, "_x_x_x_x_bach_float64_x_x_x_x_", 55460, 3221871083, "_x_x_x_x_bach_float64_x_x_x_x_", 29050, 3216730720, "_x_x_x_x_bach_float64_x_x_x_x_", 39179, 3221876491, "_x_x_x_x_bach_float64_x_x_x_x_", 43221, 3216049455, "_x_x_x_x_bach_float64_x_x_x_x_", 34319, 3221881633, "_x_x_x_x_bach_float64_x_x_x_x_", 63525, 3214558140, "_x_x_x_x_bach_float64_x_x_x_x_", 26889, 3221886508, "_x_x_x_x_bach_float64_x_x_x_x_", 35784, 1066373037, "_x_x_x_x_bach_float64_x_x_x_x_", 22828, 3221891113, "_x_x_x_x_bach_float64_x_x_x_x_", 42047, 1068303907, "_x_x_x_x_bach_float64_x_x_x_x_", 47765, 3221895446, "_x_x_x_x_bach_float64_x_x_x_x_", 22507, 1069097462, "_x_x_x_x_bach_float64_x_x_x_x_", 52425, 3221899506, "_x_x_x_x_bach_float64_x_x_x_x_", 26775, 1069672218, "_x_x_x_x_bach_float64_x_x_x_x_", 50879, 3221903289, "_x_x_x_x_bach_float64_x_x_x_x_", 34080, 1070023598, "_x_x_x_x_bach_float64_x_x_x_x_", 32256, 3221906794, "_x_x_x_x_bach_float64_x_x_x_x_", 38303, 1070376574, "_x_x_x_x_bach_float64_x_x_x_x_", 38693, 3221910020, "_x_x_x_x_bach_float64_x_x_x_x_", 49837, 1070663592, "_x_x_x_x_bach_float64_x_x_x_x_", 15694, 3221912963, "_x_x_x_x_bach_float64_x_x_x_x_", 21228, 1070841590, "_x_x_x_x_bach_float64_x_x_x_x_", 24255, 3221915623, "_x_x_x_x_bach_float64_x_x_x_x_", 26444, 1071020299, "_x_x_x_x_bach_float64_x_x_x_x_", 27764, 3221917996, "_x_x_x_x_bach_float64_x_x_x_x_", 29879, 1071199690, "_x_x_x_x_bach_float64_x_x_x_x_", 39621, 3221920082, "_x_x_x_x_bach_float64_x_x_x_x_", 61144, 1071379733, "_x_x_x_x_bach_float64_x_x_x_x_", 41220, 3221921879, "_x_x_x_x_bach_float64_x_x_x_x_", 23196, 1071560399, "_x_x_x_x_bach_float64_x_x_x_x_", 63028, 3221923385, "_x_x_x_x_bach_float64_x_x_x_x_", 14607, 1071693164, "_x_x_x_x_bach_float64_x_x_x_x_", 35007, 3221924598, "_x_x_x_x_bach_float64_x_x_x_x_", 10016, 1071784074, "_x_x_x_x_bach_float64_x_x_x_x_", 61307, 3221925516, "_x_x_x_x_bach_float64_x_x_x_x_", 16853, 1071875249, "_x_x_x_x_bach_float64_x_x_x_x_", 4570, 3221926139, "_x_x_x_x_bach_float64_x_x_x_x_", 37977, 1071966674, "_x_x_x_x_bach_float64_x_x_x_x_", 17789, 3221926464, "_x_x_x_x_bach_float64_x_x_x_x_", 22896, 1072058334, "_x_x_x_x_bach_float64_x_x_x_x_", 57170, 3221926490, "_x_x_x_x_bach_float64_x_x_x_x_", 20618, 1072150213, "_x_x_x_x_bach_float64_x_x_x_x_", 13922, 3221926216, "_x_x_x_x_bach_float64_x_x_x_x_", 61332, 1072242295, "_x_x_x_x_bach_float64_x_x_x_x_", 5754, 3221925641, "_x_x_x_x_bach_float64_x_x_x_x_", 27399, 1072334564, "_x_x_x_x_bach_float64_x_x_x_x_", 41190, 3221924762, "_x_x_x_x_bach_float64_x_x_x_x_", 36257, 1072427004, "_x_x_x_x_bach_float64_x_x_x_x_", 39303, 3221923579, "_x_x_x_x_bach_float64_x_x_x_x_", 21834, 1072519600, "_x_x_x_x_bach_float64_x_x_x_x_", 7797, 3221922090, "_x_x_x_x_bach_float64_x_x_x_x_", 20639, 1072612335, "_x_x_x_x_bach_float64_x_x_x_x_", 51329, 3221920294, "_x_x_x_x_bach_float64_x_x_x_x_", 55605, 1072699220, "_x_x_x_x_bach_float64_x_x_x_x_", 13028, 3221918191, "_x_x_x_x_bach_float64_x_x_x_x_", 35340, 1072745703, "_x_x_x_x_bach_float64_x_x_x_x_", 59517, 3221915779, "_x_x_x_x_bach_float64_x_x_x_x_", 61457, 1072792230, "_x_x_x_x_bach_float64_x_x_x_x_", 46299, 3221913057, "_x_x_x_x_bach_float64_x_x_x_x_", 44210, 1072838794, "_x_x_x_x_bach_float64_x_x_x_x_", 22433, 3221910025, "_x_x_x_x_bach_float64_x_x_x_x_", 7475, 1072885386, "_x_x_x_x_bach_float64_x_x_x_x_", 39060, 3221906680, "_x_x_x_x_bach_float64_x_x_x_x_", 61615, 1072931999, "_x_x_x_x_bach_float64_x_x_x_x_", 47822, 3221903023, "_x_x_x_x_bach_float64_x_x_x_x_", 32963, 1072978624, "_x_x_x_x_bach_float64_x_x_x_x_", 19854, 3221899053, "_x_x_x_x_bach_float64_x_x_x_x_", 59669, 1073025252, "_x_x_x_x_bach_float64_x_x_x_x_", 22817, 3221894769, "_x_x_x_x_bach_float64_x_x_x_x_", 55364, 1073071875, "_x_x_x_x_bach_float64_x_x_x_x_", 59001, 3221890170, "_x_x_x_x_bach_float64_x_x_x_x_", 5835, 1073118484, "_x_x_x_x_bach_float64_x_x_x_x_", 57337, 3221885256, "_x_x_x_x_bach_float64_x_x_x_x_", 48894, 1073165072, "_x_x_x_x_bach_float64_x_x_x_x_", 18949, 3221880026, "_x_x_x_x_bach_float64_x_x_x_x_", 8581, 1073211629, "_x_x_x_x_bach_float64_x_x_x_x_", 53762, 3221874479, "_x_x_x_x_bach_float64_x_x_x_x_", 21134, 1073258146, "_x_x_x_x_bach_float64_x_x_x_x_", 45673, 3221868616, "_x_x_x_x_bach_float64_x_x_x_x_", 22989, 1073304617, "_x_x_x_x_bach_float64_x_x_x_x_", 60049, 3221862436, "_x_x_x_x_bach_float64_x_x_x_x_", 603, 1073351030, "_x_x_x_x_bach_float64_x_x_x_x_", 51442, 3221855938, "_x_x_x_x_bach_float64_x_x_x_x_", 17496, 1073397379, "_x_x_x_x_bach_float64_x_x_x_x_", 50838, 3221849122, "_x_x_x_x_bach_float64_x_x_x_x_", 17485, 1073443655, "_x_x_x_x_bach_float64_x_x_x_x_", 45704, 3221841989, "_x_x_x_x_bach_float64_x_x_x_x_", 58368, 1073489848, "_x_x_x_x_bach_float64_x_x_x_x_", 11246, 3221834537, "_x_x_x_x_bach_float64_x_x_x_x_", 57038, 1073535950, "_x_x_x_x_bach_float64_x_x_x_x_", 27111, 3221826767, "_x_x_x_x_bach_float64_x_x_x_x_", 28195, 1073581952, "_x_x_x_x_bach_float64_x_x_x_x_", 20394, 3221818679, "_x_x_x_x_bach_float64_x_x_x_x_", 28705, 1073627846, "_x_x_x_x_bach_float64_x_x_x_x_", 52269, 3221810272, "_x_x_x_x_bach_float64_x_x_x_x_", 3057, 1073673622, "_x_x_x_x_bach_float64_x_x_x_x_", 33794, 3221801548, "_x_x_x_x_bach_float64_x_x_x_x_", 53125, 1073719273, "_x_x_x_x_bach_float64_x_x_x_x_", 50282, 3221792505, "_x_x_x_x_bach_float64_x_x_x_x_", 41047, 1073753306, "_x_x_x_x_bach_float64_x_x_x_x_", 48834, 3221783145, "_x_x_x_x_bach_float64_x_x_x_x_", 61125, 1073775993, "_x_x_x_x_bach_float64_x_x_x_x_", 2836, 3221773467, "_x_x_x_x_bach_float64_x_x_x_x_", 17232, 1073798603, "_x_x_x_x_bach_float64_x_x_x_x_", 28963, 3221763472, "_x_x_x_x_bach_float64_x_x_x_x_", 42823, 1073821132, "_x_x_x_x_bach_float64_x_x_x_x_", 63163, 3221753160, "_x_x_x_x_bach_float64_x_x_x_x_", 54409, 1073843577, "_x_x_x_x_bach_float64_x_x_x_x_", 12970, 3221742532, "_x_x_x_x_bach_float64_x_x_x_x_", 31369, 1073865932, "_x_x_x_x_bach_float64_x_x_x_x_", 58227, 3221731588, "_x_x_x_x_bach_float64_x_x_x_x_", 44659, 1073888194, "_x_x_x_x_bach_float64_x_x_x_x_", 51409, 3221720329, "_x_x_x_x_bach_float64_x_x_x_x_", 33599, 1073910357, "_x_x_x_x_bach_float64_x_x_x_x_", 49026, 3221708755, "_x_x_x_x_bach_float64_x_x_x_x_", 51181, 1073932418, "_x_x_x_x_bach_float64_x_x_x_x_", 7760, 3221696868, "_x_x_x_x_bach_float64_x_x_x_x_", 59556, 1073954372, "_x_x_x_x_bach_float64_x_x_x_x_", 21496, 3221684667, "_x_x_x_x_bach_float64_x_x_x_x_", 61547, 1073976215, "_x_x_x_x_bach_float64_x_x_x_x_", 50447, 3221672154, "_x_x_x_x_bach_float64_x_x_x_x_", 43283, 1073997942, "_x_x_x_x_bach_float64_x_x_x_x_", 59704, 3221659329, "_x_x_x_x_bach_float64_x_x_x_x_", 54807, 1074019548, "_x_x_x_x_bach_float64_x_x_x_x_", 42841, 3221646194, "_x_x_x_x_bach_float64_x_x_x_x_", 34968, 1074041031, "_x_x_x_x_bach_float64_x_x_x_x_", 61413, 3221632749, "_x_x_x_x_bach_float64_x_x_x_x_", 35108, 1074062384, "_x_x_x_x_bach_float64_x_x_x_x_", 38142, 3221618996, "_x_x_x_x_bach_float64_x_x_x_x_", 54512, 1074083604, "_x_x_x_x_bach_float64_x_x_x_x_", 24545, 3221604935, "_x_x_x_x_bach_float64_x_x_x_x_", 11274, 1074104687, "_x_x_x_x_bach_float64_x_x_x_x_", 25326, 3221590568, "_x_x_x_x_bach_float64_x_x_x_x_", 44393, 1074125627, "_x_x_x_x_bach_float64_x_x_x_x_", 34890, 3221575897, "_x_x_x_x_bach_float64_x_x_x_x_", 32389, 1074146422, "_x_x_x_x_bach_float64_x_x_x_x_", 23639, 3221560921, "_x_x_x_x_bach_float64_x_x_x_x_", 31667, 1074167066, "_x_x_x_x_bach_float64_x_x_x_x_", 5102, 3221545644, "_x_x_x_x_bach_float64_x_x_x_x_", 61030, 1074187554, "_x_x_x_x_bach_float64_x_x_x_x_", 52719, 3221530065, "_x_x_x_x_bach_float64_x_x_x_x_", 18212, 1074207884, "_x_x_x_x_bach_float64_x_x_x_x_", 4042, 3221514187, "_x_x_x_x_bach_float64_x_x_x_x_", 55218, 1074228050, "_x_x_x_x_bach_float64_x_x_x_x_", 32024, 3221498012, "_x_x_x_x_bach_float64_x_x_x_x_", 35744, 1074248048, "_x_x_x_x_bach_float64_x_x_x_x_", 51609, 3221481540, "_x_x_x_x_bach_float64_x_x_x_x_", 39892, 1074267874, "_x_x_x_x_bach_float64_x_x_x_x_", 58852, 3221464774, "_x_x_x_x_bach_float64_x_x_x_x_", 15004, 1074287524, "_x_x_x_x_bach_float64_x_x_x_x_", 26218, 3221447715, "_x_x_x_x_bach_float64_x_x_x_x_", 13765, 1074306993, "_x_x_x_x_bach_float64_x_x_x_x_", 9369, 3221430364, "_x_x_x_x_bach_float64_x_x_x_x_", 35722, 1074326277, "_x_x_x_x_bach_float64_x_x_x_x_", 6792, 3221412725, "_x_x_x_x_bach_float64_x_x_x_x_", 61469, 1074345373, "_x_x_x_x_bach_float64_x_x_x_x_", 30853, 3221394799, "_x_x_x_x_bach_float64_x_x_x_x_", 16548, 1074364275, "_x_x_x_x_bach_float64_x_x_x_x_", 62754, 3221376587, "_x_x_x_x_bach_float64_x_x_x_x_", 57644, 1074382980, "_x_x_x_x_bach_float64_x_x_x_x_", 22405, 3221358092, "_x_x_x_x_bach_float64_x_x_x_x_", 752, 1074401483, "_x_x_x_x_bach_float64_x_x_x_x_", 15364, 3221339316, "_x_x_x_x_bach_float64_x_x_x_x_", 53221, 1074419781, "_x_x_x_x_bach_float64_x_x_x_x_", 4973, 3221320260, "_x_x_x_x_bach_float64_x_x_x_x_", 31001, 1074437869, "_x_x_x_x_bach_float64_x_x_x_x_", 23805, 3221300928, "_x_x_x_x_bach_float64_x_x_x_x_", 9462, 1074455744, "_x_x_x_x_bach_float64_x_x_x_x_", 6999, 3221281322, "_x_x_x_x_bach_float64_x_x_x_x_", 47872, 1074473400, "_x_x_x_x_bach_float64_x_x_x_x_", 33919, 3221261443, "_x_x_x_x_bach_float64_x_x_x_x_", 35304, 1074490835, "_x_x_x_x_bach_float64_x_x_x_x_", 60795, 3221241295, "_x_x_x_x_bach_float64_x_x_x_x_", 50538, 1074508044, "_x_x_x_x_bach_float64_x_x_x_x_", 58257, 3221216286, "_x_x_x_x_bach_float64_x_x_x_x_", 55687, 1074525023, "_x_x_x_x_bach_float64_x_x_x_x_", 44397, 3221174924, "_x_x_x_x_bach_float64_x_x_x_x_", 36792, 1074541768, "_x_x_x_x_bach_float64_x_x_x_x_", 22388, 3221133038, "_x_x_x_x_bach_float64_x_x_x_x_", 1057, 1074558276, "_x_x_x_x_bach_float64_x_x_x_x_", 20142, 3221090632, "_x_x_x_x_bach_float64_x_x_x_x_", 26498, 1074574542, "_x_x_x_x_bach_float64_x_x_x_x_", 33698, 3221047713, "_x_x_x_x_bach_float64_x_x_x_x_", 35667, 1074590563, "_x_x_x_x_bach_float64_x_x_x_x_", 7064, 3221004285, "_x_x_x_x_bach_float64_x_x_x_x_", 13737, 1074606334, "_x_x_x_x_bach_float64_x_x_x_x_", 40590, 3220960353, "_x_x_x_x_bach_float64_x_x_x_x_", 14741, 1074621853, "_x_x_x_x_bach_float64_x_x_x_x_", 42012, 3220915925, "_x_x_x_x_bach_float64_x_x_x_x_", 20969, 1074637114, "_x_x_x_x_bach_float64_x_x_x_x_", 65304, 3220871005, "_x_x_x_x_bach_float64_x_x_x_x_", 47950, 1074652115, "_x_x_x_x_bach_float64_x_x_x_x_", 27297, 3220825599, "_x_x_x_x_bach_float64_x_x_x_x_", 35597, 1074666852, "_x_x_x_x_bach_float64_x_x_x_x_", 47454, 3220779714, "_x_x_x_x_bach_float64_x_x_x_x_", 49180, 1074681321, "_x_x_x_x_bach_float64_x_x_x_x_", 34807, 3220733355, "_x_x_x_x_bach_float64_x_x_x_x_", 2917, 1074695518, "_x_x_x_x_bach_float64_x_x_x_x_", 30042, 3220686529, "_x_x_x_x_bach_float64_x_x_x_x_", 19689, 1074709441, "_x_x_x_x_bach_float64_x_x_x_x_", 57755, 3220639242, "_x_x_x_x_bach_float64_x_x_x_x_", 49931, 1074723084, "_x_x_x_x_bach_float64_x_x_x_x_", 13674, 3220591500, "_x_x_x_x_bach_float64_x_x_x_x_", 59690, 1074736446, "_x_x_x_x_bach_float64_x_x_x_x_", 46115, 3220543311, "_x_x_x_x_bach_float64_x_x_x_x_", 847, 1074749522, "_x_x_x_x_bach_float64_x_x_x_x_", 55660, 3220494681, "_x_x_x_x_bach_float64_x_x_x_x_", 21470, 1074762308, "_x_x_x_x_bach_float64_x_x_x_x_", 17871, 3220445616, "_x_x_x_x_bach_float64_x_x_x_x_", 63762, 1074774802, "_x_x_x_x_bach_float64_x_x_x_x_", 14983, 3220396123, "_x_x_x_x_bach_float64_x_x_x_x_", 28527, 1074787001, "_x_x_x_x_bach_float64_x_x_x_x_", 43017, 3220346210, "_x_x_x_x_bach_float64_x_x_x_x_", 23365, 1074794650, "_x_x_x_x_bach_float64_x_x_x_x_", 53455, 3220295883, "_x_x_x_x_bach_float64_x_x_x_x_", 2812, 1074800448, "_x_x_x_x_bach_float64_x_x_x_x_", 33302, 3220245150, "_x_x_x_x_bach_float64_x_x_x_x_", 49050, 1074806094, "_x_x_x_x_bach_float64_x_x_x_x_", 58936, 3220194018, "_x_x_x_x_bach_float64_x_x_x_x_", 17746, 1074811585, "_x_x_x_x_bach_float64_x_x_x_x_", 57976, 3220108092, "_x_x_x_x_bach_float64_x_x_x_x_", 1608, 1074816920, "_x_x_x_x_bach_float64_x_x_x_x_", 55075, 3220004276, "_x_x_x_x_bach_float64_x_x_x_x_", 40961, 1074822097, "_x_x_x_x_bach_float64_x_x_x_x_", 14739, 3219899706, "_x_x_x_x_bach_float64_x_x_x_x_", 17000, 1074827116, "_x_x_x_x_bach_float64_x_x_x_x_", 12469, 3219794398, "_x_x_x_x_bach_float64_x_x_x_x_", 55091, 1074831974, "_x_x_x_x_bach_float64_x_x_x_x_", 24697, 3219688367, "_x_x_x_x_bach_float64_x_x_x_x_", 61547, 1074836669, "_x_x_x_x_bach_float64_x_x_x_x_", 7694, 3219581630, "_x_x_x_x_bach_float64_x_x_x_x_", 31956, 1074841202, "_x_x_x_x_bach_float64_x_x_x_x_", 64086, 3219474201, "_x_x_x_x_bach_float64_x_x_x_x_", 16663, 1074845569, "_x_x_x_x_bach_float64_x_x_x_x_", 42513, 3219366097, "_x_x_x_x_bach_float64_x_x_x_x_", 5211, 1074849770, "_x_x_x_x_bach_float64_x_x_x_x_", 14359, 3219257335, "_x_x_x_x_bach_float64_x_x_x_x_", 57121, 1074853803, "_x_x_x_x_bach_float64_x_x_x_x_", 55901, 3219147931, "_x_x_x_x_bach_float64_x_x_x_x_", 23369, 1074857667, "_x_x_x_x_bach_float64_x_x_x_x_", 50489, 3218947481, "_x_x_x_x_bach_float64_x_x_x_x_", 37867, 1074861361, "_x_x_x_x_bach_float64_x_x_x_x_", 49182, 3218726202, "_x_x_x_x_bach_float64_x_x_x_x_", 9212, 1074864883, "_x_x_x_x_bach_float64_x_x_x_x_", 16735, 3218503740, "_x_x_x_x_bach_float64_x_x_x_x_", 12926, 1074868232, "_x_x_x_x_bach_float64_x_x_x_x_", 28566, 3218280127, "_x_x_x_x_bach_float64_x_x_x_x_", 11030, 1074871407, "_x_x_x_x_bach_float64_x_x_x_x_", 11397, 3218031054, "_x_x_x_x_bach_float64_x_x_x_x_", 12796, 1074874406, "_x_x_x_x_bach_float64_x_x_x_x_", 45153, 3217579437, "_x_x_x_x_bach_float64_x_x_x_x_", 20986, 1074877229, "_x_x_x_x_bach_float64_x_x_x_x_", 7289, 3217125728, "_x_x_x_x_bach_float64_x_x_x_x_", 25473, 1074879874, "_x_x_x_x_bach_float64_x_x_x_x_", 25210, 3216308833, "_x_x_x_x_bach_float64_x_x_x_x_", 43938, 1074882339, "_x_x_x_x_bach_float64_x_x_x_x_", 32277, 3214674718, "_x_x_x_x_bach_float64_x_x_x_x_", 12770, 1074884625, "_x_x_x_x_bach_float64_x_x_x_x_", 34618, 1067191786, "_x_x_x_x_bach_float64_x_x_x_x_", 52148, 1074886730, "_x_x_x_x_bach_float64_x_x_x_x_", 3627, 1068832724, "_x_x_x_x_bach_float64_x_x_x_x_", 56501, 1074888652, "_x_x_x_x_bach_float64_x_x_x_x_", 64795, 1069653209, "_x_x_x_x_bach_float64_x_x_x_x_", 51822, 1074890391, "_x_x_x_x_bach_float64_x_x_x_x_", 20920, 1070117952, "_x_x_x_x_bach_float64_x_x_x_x_", 8873, 1074891946, "_x_x_x_x_bach_float64_x_x_x_x_", 39829, 1070584278, "_x_x_x_x_bach_float64_x_x_x_x_", 29504, 1074893315, "_x_x_x_x_bach_float64_x_x_x_x_", 59133, 1070824103, "_x_x_x_x_bach_float64_x_x_x_x_", 53868, 1074894498, "_x_x_x_x_bach_float64_x_x_x_x_", 64613, 1071058735, "_x_x_x_x_bach_float64_x_x_x_x_", 5773, 1074895495, "_x_x_x_x_bach_float64_x_x_x_x_", 2549, 1071294045, "_x_x_x_x_bach_float64_x_x_x_x_", 48220, 1074896303, "_x_x_x_x_bach_float64_x_x_x_x_", 3949, 1071529995, "_x_x_x_x_bach_float64_x_x_x_x_", 31396, 1074896922, "_x_x_x_x_bach_float64_x_x_x_x_", 41212, 1071705608, "_x_x_x_x_bach_float64_x_x_x_x_", 33393, 1074897352, "_x_x_x_x_bach_float64_x_x_x_x_", 9707, 1071824165, "_x_x_x_x_bach_float64_x_x_x_x_", 27349, 1074897592, "_x_x_x_x_bach_float64_x_x_x_x_", 17175, 1071942983, "_x_x_x_x_bach_float64_x_x_x_x_", 50994, 1074897640, "_x_x_x_x_bach_float64_x_x_x_x_", 37374, 1072062043, "_x_x_x_x_bach_float64_x_x_x_x_", 26439, 1074897496, "_x_x_x_x_bach_float64_x_x_x_x_", 6330, 1072181326, "_x_x_x_x_bach_float64_x_x_x_x_", 16354, 1074897160, "_x_x_x_x_bach_float64_x_x_x_x_", 44834, 1072300811, "_x_x_x_x_bach_float64_x_x_x_x_", 64374, 1074896631, "_x_x_x_x_bach_float64_x_x_x_x_", 16099, 1072420479, "_x_x_x_x_bach_float64_x_x_x_x_", 12708, 1074895907, "_x_x_x_x_bach_float64_x_x_x_x_", 54480, 1072540309, "_x_x_x_x_bach_float64_x_x_x_x_", 17617, 1074894990, "_x_x_x_x_bach_float64_x_x_x_x_", 31856, 1072660282, "_x_x_x_x_bach_float64_x_x_x_x_", 58610, 1074893877, "_x_x_x_x_bach_float64_x_x_x_x_", 60596, 1072736813, "_x_x_x_x_bach_float64_x_x_x_x_", 14019, 1074892569, "_x_x_x_x_bach_float64_x_x_x_x_", 48097, 1072796911, "_x_x_x_x_bach_float64_x_x_x_x_", 40559, 1074891064, "_x_x_x_x_bach_float64_x_x_x_x_", 25692, 1072857051, "_x_x_x_x_bach_float64_x_x_x_x_", 11538, 1074889363, "_x_x_x_x_bach_float64_x_x_x_x_", 24696, 1072917221, "_x_x_x_x_bach_float64_x_x_x_x_", 45066, 1074887465, "_x_x_x_x_bach_float64_x_x_x_x_", 2409, 1072977411, "_x_x_x_x_bach_float64_x_x_x_x_", 24956, 1074885370, "_x_x_x_x_bach_float64_x_x_x_x_", 64150, 1073037611, "_x_x_x_x_bach_float64_x_x_x_x_", 14645, 1074883078, "_x_x_x_x_bach_float64_x_x_x_x_", 14443, 1073097811, "_x_x_x_x_bach_float64_x_x_x_x_", 56626, 1074880587, "_x_x_x_x_bach_float64_x_x_x_x_", 5350, 1073158000, "_x_x_x_x_bach_float64_x_x_x_x_", 12548, 1074877898, "_x_x_x_x_bach_float64_x_x_x_x_", 52229, 1073218168, "_x_x_x_x_bach_float64_x_x_x_x_", 33627, 1074875010, "_x_x_x_x_bach_float64_x_x_x_x_", 54611, 1073278304, "_x_x_x_x_bach_float64_x_x_x_x_", 22817, 1074871923, "_x_x_x_x_bach_float64_x_x_x_x_", 57969, 1073338398, "_x_x_x_x_bach_float64_x_x_x_x_", 54590, 1074868638, "_x_x_x_x_bach_float64_x_x_x_x_", 34721, 1073398440, "_x_x_x_x_bach_float64_x_x_x_x_", 48282, 1074865153, "_x_x_x_x_bach_float64_x_x_x_x_", 34914, 1073458419, "_x_x_x_x_bach_float64_x_x_x_x_", 5509, 1074861469, "_x_x_x_x_bach_float64_x_x_x_x_", 49778, 1073518323, "_x_x_x_x_bach_float64_x_x_x_x_", 25078, 1074857586, "_x_x_x_x_bach_float64_x_x_x_x_", 45863, 1073578144, "_x_x_x_x_bach_float64_x_x_x_x_", 29707, 1074853503, "_x_x_x_x_bach_float64_x_x_x_x_", 36933, 1073637869, "_x_x_x_x_bach_float64_x_x_x_x_", 56353, 1074849221, "_x_x_x_x_bach_float64_x_x_x_x_", 61395, 1073697489, "_x_x_x_x_bach_float64_x_x_x_x_", 61440, 1074844740, "_x_x_x_x_bach_float64_x_x_x_x_", 31952, 1073749408, "_x_x_x_x_bach_float64_x_x_x_x_", 27248, 1074840059, "_x_x_x_x_bach_float64_x_x_x_x_", 3679, 1073779097, "_x_x_x_x_bach_float64_x_x_x_x_", 41683, 1074835179, "_x_x_x_x_bach_float64_x_x_x_x_", 41381, 1073808717, "_x_x_x_x_bach_float64_x_x_x_x_", 23576, 1074830100, "_x_x_x_x_bach_float64_x_x_x_x_", 49066, 1073838263, "_x_x_x_x_bach_float64_x_x_x_x_", 10907, 1074824821, "_x_x_x_x_bach_float64_x_x_x_x_", 38338, 1073867729, "_x_x_x_x_bach_float64_x_x_x_x_", 28789, 1074819345, "_x_x_x_x_bach_float64_x_x_x_x_", 15459, 1073897111, "_x_x_x_x_bach_float64_x_x_x_x_", 61348, 1074813669, "_x_x_x_x_bach_float64_x_x_x_x_", 13034, 1073926402, "_x_x_x_x_bach_float64_x_x_x_x_", 61899, 1074807795, "_x_x_x_x_bach_float64_x_x_x_x_", 3054, 1073955598, "_x_x_x_x_bach_float64_x_x_x_x_", 1265, 1074801724, "_x_x_x_x_bach_float64_x_x_x_x_", 18557, 1073984694, "_x_x_x_x_bach_float64_x_x_x_x_", 19677, 1074795454, "_x_x_x_x_bach_float64_x_x_x_x_", 24302, 1074013683, "_x_x_x_x_bach_float64_x_x_x_x_", 53643, 1074787576, "_x_x_x_x_bach_float64_x_x_x_x_", 60001, 1074042561, "_x_x_x_x_bach_float64_x_x_x_x_", 55687, 1074774249, "_x_x_x_x_bach_float64_x_x_x_x_", 87, 1074071322, "_x_x_x_x_bach_float64_x_x_x_x_", 56725, 1074760530, "_x_x_x_x_bach_float64_x_x_x_x_", 43342, 1074099961, "_x_x_x_x_bach_float64_x_x_x_x_", 19888, 1074746418, "_x_x_x_x_bach_float64_x_x_x_x_", 31072, 1074128472, "_x_x_x_x_bach_float64_x_x_x_x_", 17372, 1074731916, "_x_x_x_x_bach_float64_x_x_x_x_", 17987, 1074156850, "_x_x_x_x_bach_float64_x_x_x_x_", 3912, 1074717024, "_x_x_x_x_bach_float64_x_x_x_x_", 63332, 1074185090, "_x_x_x_x_bach_float64_x_x_x_x_", 58305, 1074701744, "_x_x_x_x_bach_float64_x_x_x_x_", 28098, 1074213187, "_x_x_x_x_bach_float64_x_x_x_x_", 44390, 1074686077, "_x_x_x_x_bach_float64_x_x_x_x_", 32733, 1074241135, "_x_x_x_x_bach_float64_x_x_x_x_", 1976, 1074670023, "_x_x_x_x_bach_float64_x_x_x_x_", 1880, 1074268929, "_x_x_x_x_bach_float64_x_x_x_x_", 22448, 1074653586, "_x_x_x_x_bach_float64_x_x_x_x_", 64800, 1074296564, "_x_x_x_x_bach_float64_x_x_x_x_", 2246, 1074636765, "_x_x_x_x_bach_float64_x_x_x_x_", 41184, 1074324033, "_x_x_x_x_bach_float64_x_x_x_x_", 60371, 1074619563, "_x_x_x_x_bach_float64_x_x_x_x_", 43440, 1074351333, "_x_x_x_x_bach_float64_x_x_x_x_", 47167, 1074601981, "_x_x_x_x_bach_float64_x_x_x_x_", 31661, 1074378458, "_x_x_x_x_bach_float64_x_x_x_x_", 44757, 1074584020, "_x_x_x_x_bach_float64_x_x_x_x_", 24739, 1074405402, "_x_x_x_x_bach_float64_x_x_x_x_", 24025, 1074565684, "_x_x_x_x_bach_float64_x_x_x_x_", 49204, 1074432161, "_x_x_x_x_bach_float64_x_x_x_x_", 34486, 1074546973, "_x_x_x_x_bach_float64_x_x_x_x_", 21612, 1074458729, "_x_x_x_x_bach_float64_x_x_x_x_", 9263, 1074527889, "_x_x_x_x_bach_float64_x_x_x_x_", 22667, 1074485100, "_x_x_x_x_bach_float64_x_x_x_x_", 37392, 1074508435, "_x_x_x_x_bach_float64_x_x_x_x_", 44495, 1074511271, "_x_x_x_x_bach_float64_x_x_x_x_", 54630, 1074488612, "_x_x_x_x_bach_float64_x_x_x_x_", 62494, 1074537235, "_x_x_x_x_bach_float64_x_x_x_x_", 1442, 1074468423, "_x_x_x_x_bach_float64_x_x_x_x_", 37713, 1074562987, "_x_x_x_x_bach_float64_x_x_x_x_", 54936, 1074447869, "_x_x_x_x_bach_float64_x_x_x_x_", 45512, 1074588523, "_x_x_x_x_bach_float64_x_x_x_x_", 17207, 1074426953, "_x_x_x_x_bach_float64_x_x_x_x_", 5638, 1074613837, "_x_x_x_x_bach_float64_x_x_x_x_", 22850, 1074405678, "_x_x_x_x_bach_float64_x_x_x_x_", 61257, 1074638924, "_x_x_x_x_bach_float64_x_x_x_x_", 9760, 1074384046, "_x_x_x_x_bach_float64_x_x_x_x_", 33524, 1074663779, "_x_x_x_x_bach_float64_x_x_x_x_", 50364, 1074362058, "_x_x_x_x_bach_float64_x_x_x_x_", 47964, 1074688398, "_x_x_x_x_bach_float64_x_x_x_x_", 36130, 1074339718, "_x_x_x_x_bach_float64_x_x_x_x_", 38077, 1074712774, "_x_x_x_x_bach_float64_x_x_x_x_", 25909, 1074317029, "_x_x_x_x_bach_float64_x_x_x_x_", 26168, 1074736904, "_x_x_x_x_bach_float64_x_x_x_x_", 13274, 1074293993, "_x_x_x_x_bach_float64_x_x_x_x_", 638, 1074760782, "_x_x_x_x_bach_float64_x_x_x_x_", 30246, 1074270612, "_x_x_x_x_bach_float64_x_x_x_x_", 44615, 1074784403, "_x_x_x_x_bach_float64_x_x_x_x_", 63268, 1074246890, "_x_x_x_x_bach_float64_x_x_x_x_", 62588, 1074799081, "_x_x_x_x_bach_float64_x_x_x_x_", 43760, 1074222830, "_x_x_x_x_bach_float64_x_x_x_x_", 564, 1074810627, "_x_x_x_x_bach_float64_x_x_x_x_", 44219, 1074198434, "_x_x_x_x_bach_float64_x_x_x_x_", 50355, 1074822038, "_x_x_x_x_bach_float64_x_x_x_x_", 24919, 1074173705, "_x_x_x_x_bach_float64_x_x_x_x_", 45705, 1074833311, "_x_x_x_x_bach_float64_x_x_x_x_", 48618, 1074148648, "_x_x_x_x_bach_float64_x_x_x_x_", 61009, 1074844443, "_x_x_x_x_bach_float64_x_x_x_x_", 46040, 1074123263, "_x_x_x_x_bach_float64_x_x_x_x_", 8768, 1074855433, "_x_x_x_x_bach_float64_x_x_x_x_", 49752, 1074097556, "_x_x_x_x_bach_float64_x_x_x_x_", 15284, 1074866277, "_x_x_x_x_bach_float64_x_x_x_x_", 44599, 1074071529, "_x_x_x_x_bach_float64_x_x_x_x_", 1425, 1074876974, "_x_x_x_x_bach_float64_x_x_x_x_", 24773, 1074045186, "_x_x_x_x_bach_float64_x_x_x_x_", 40858, 1074887521, "_x_x_x_x_bach_float64_x_x_x_x_", 61059, 1074018529, "_x_x_x_x_bach_float64_x_x_x_x_", 53636, 1074897917, "_x_x_x_x_bach_float64_x_x_x_x_", 50735, 1073991564, "_x_x_x_x_bach_float64_x_x_x_x_", 14383, 1074908157, "_x_x_x_x_bach_float64_x_x_x_x_", 2443, 1073964292, "_x_x_x_x_bach_float64_x_x_x_x_", 19310, 1074918241, "_x_x_x_x_bach_float64_x_x_x_x_", 4015, 1073936718, "_x_x_x_x_bach_float64_x_x_x_x_", 15176, 1074928167, "_x_x_x_x_bach_float64_x_x_x_x_", 4874, 1073908845, "_x_x_x_x_bach_float64_x_x_x_x_", 41632, 1074937931, "_x_x_x_x_bach_float64_x_x_x_x_", 2863, 1073880678, "_x_x_x_x_bach_float64_x_x_x_x_", 3670, 1074947532, "_x_x_x_x_bach_float64_x_x_x_x_", 45965, 1073852219, "_x_x_x_x_bach_float64_x_x_x_x_", 22298, 1074956968, "_x_x_x_x_bach_float64_x_x_x_x_", 49288, 1073823474, "_x_x_x_x_bach_float64_x_x_x_x_", 52361, 1074966236, "_x_x_x_x_bach_float64_x_x_x_x_", 17157, 1073794445, "_x_x_x_x_bach_float64_x_x_x_x_", 12372, 1074975335, "_x_x_x_x_bach_float64_x_x_x_x_", 15546, 1073765137, "_x_x_x_x_bach_float64_x_x_x_x_", 32682, 1074984262, "_x_x_x_x_bach_float64_x_x_x_x_", 51984, 1073729283, "_x_x_x_x_bach_float64_x_x_x_x_", 35247, 1074993015, "_x_x_x_x_bach_float64_x_x_x_x_", 18085, 1073669574, "_x_x_x_x_bach_float64_x_x_x_x_", 20872, 1075001592, "_x_x_x_x_bach_float64_x_x_x_x_", 27495, 1073609331, "_x_x_x_x_bach_float64_x_x_x_x_", 14959, 1075009992, "_x_x_x_x_bach_float64_x_x_x_x_", 11431, 1073548563, "_x_x_x_x_bach_float64_x_x_x_x_", 64677, 1075018211, "_x_x_x_x_bach_float64_x_x_x_x_", 8097, 1073487278, "_x_x_x_x_bach_float64_x_x_x_x_", 24957, 1075026249, "_x_x_x_x_bach_float64_x_x_x_x_", 6153, 1073425485, "_x_x_x_x_bach_float64_x_x_x_x_", 50552, 1075034102, "_x_x_x_x_bach_float64_x_x_x_x_", 14137, 1073363193, "_x_x_x_x_bach_float64_x_x_x_x_", 24235, 1075041770, "_x_x_x_x_bach_float64_x_x_x_x_", 28336, 1073300410, "_x_x_x_x_bach_float64_x_x_x_x_", 18041, 1075049251, "_x_x_x_x_bach_float64_x_x_x_x_", 31655, 1073237147, "_x_x_x_x_bach_float64_x_x_x_x_", 17617, 1075056542, "_x_x_x_x_bach_float64_x_x_x_x_", 23676, 1073173411, "_x_x_x_x_bach_float64_x_x_x_x_", 23520, 1075063641, "_x_x_x_x_bach_float64_x_x_x_x_", 17351, 1073109212, "_x_x_x_x_bach_float64_x_x_x_x_", 4787, 1075070547, "_x_x_x_x_bach_float64_x_x_x_x_", 3321, 1073044560, "_x_x_x_x_bach_float64_x_x_x_x_", 32109, 1075077259, "_x_x_x_x_bach_float64_x_x_x_x_", 13169, 1072979464, "_x_x_x_x_bach_float64_x_x_x_x_", 489, 1075083773, "_x_x_x_x_bach_float64_x_x_x_x_", 21072, 1072913933, "_x_x_x_x_bach_float64_x_x_x_x_", 55073, 1075090089, "_x_x_x_x_bach_float64_x_x_x_x_", 11816, 1072847978, "_x_x_x_x_bach_float64_x_x_x_x_", 15951, 1075096205, "_x_x_x_x_bach_float64_x_x_x_x_", 19658, 1072781608, "_x_x_x_x_bach_float64_x_x_x_x_", 29768, 1075102120, "_x_x_x_x_bach_float64_x_x_x_x_", 7930, 1072714832, "_x_x_x_x_bach_float64_x_x_x_x_", 23011, 1075107830, "_x_x_x_x_bach_float64_x_x_x_x_", 31927, 1072602077, "_x_x_x_x_bach_float64_x_x_x_x_", 53773, 1075113336, "_x_x_x_x_bach_float64_x_x_x_x_", 35499, 1072466967, "_x_x_x_x_bach_float64_x_x_x_x_", 54339, 1075118635, "_x_x_x_x_bach_float64_x_x_x_x_", 33870, 1072331107, "_x_x_x_x_bach_float64_x_x_x_x_", 12855, 1075123725, "_x_x_x_x_bach_float64_x_x_x_x_", 38452, 1072194518, "_x_x_x_x_bach_float64_x_x_x_x_", 3924, 1075128606, "_x_x_x_x_bach_float64_x_x_x_x_", 28036, 1072057220, "_x_x_x_x_bach_float64_x_x_x_x_", 2266, 1075133276, "_x_x_x_x_bach_float64_x_x_x_x_", 63245, 1071919236, "_x_x_x_x_bach_float64_x_x_x_x_", 3436, 1075137733, "_x_x_x_x_bach_float64_x_x_x_x_", 30744, 1071780585, "_x_x_x_x_bach_float64_x_x_x_x_", 58051, 1075141976, "_x_x_x_x_bach_float64_x_x_x_x_", 3324, 1071637908, "_x_x_x_x_bach_float64_x_x_x_x_", 22607, 1075146004, "_x_x_x_x_bach_float64_x_x_x_x_", 53789, 1071358071, "_x_x_x_x_bach_float64_x_x_x_x_", 9634, 1075149814, "_x_x_x_x_bach_float64_x_x_x_x_", 54509, 1071077029, "_x_x_x_x_bach_float64_x_x_x_x_", 29536, 1075153407, "_x_x_x_x_bach_float64_x_x_x_x_", 17503, 1070794828, "_x_x_x_x_bach_float64_x_x_x_x_", 3491, 1075156780, "_x_x_x_x_bach_float64_x_x_x_x_", 2891, 1070426926, "_x_x_x_x_bach_float64_x_x_x_x_", 16009, 1075159932, "_x_x_x_x_bach_float64_x_x_x_x_", 50774, 1069858148, "_x_x_x_x_bach_float64_x_x_x_x_", 20447, 1075162862, "_x_x_x_x_bach_float64_x_x_x_x_", 35962, 1069027113, "_x_x_x_x_bach_float64_x_x_x_x_", 45760, 1075165569, "_x_x_x_x_bach_float64_x_x_x_x_", 45215, 1067077825, "_x_x_x_x_bach_float64_x_x_x_x_", 52217, 1075168052, "_x_x_x_x_bach_float64_x_x_x_x_", 47731, 3215321817, "_x_x_x_x_bach_float64_x_x_x_x_", 25666, 1075170310, "_x_x_x_x_bach_float64_x_x_x_x_", 48762, 3216805112, "_x_x_x_x_bach_float64_x_x_x_x_", 47867, 1075172341, "_x_x_x_x_bach_float64_x_x_x_x_", 44340, 3217496285, "_x_x_x_x_bach_float64_x_x_x_x_", 14982, 1075174144, "_x_x_x_x_bach_float64_x_x_x_x_", 24830, 3218076030, "_x_x_x_x_bach_float64_x_x_x_x_", 52512, 1075175719, "_x_x_x_x_bach_float64_x_x_x_x_", 45533, 3218368513, "_x_x_x_x_bach_float64_x_x_x_x_", 53533, 1075177065, "_x_x_x_x_bach_float64_x_x_x_x_", 35895, 3218659845, "_x_x_x_x_bach_float64_x_x_x_x_", 43946, 1075178180, "_x_x_x_x_bach_float64_x_x_x_x_", 47017, 3218951838, "_x_x_x_x_bach_float64_x_x_x_x_", 63702, 1075179063, "_x_x_x_x_bach_float64_x_x_x_x_", 46445, 3219186382, "_x_x_x_x_bach_float64_x_x_x_x_", 22552, 1075179715, "_x_x_x_x_bach_float64_x_x_x_x_", 38313, 3219332967, "_x_x_x_x_bach_float64_x_x_x_x_", 54324, 1075180133, "_x_x_x_x_bach_float64_x_x_x_x_", 44807, 3219479812, "_x_x_x_x_bach_float64_x_x_x_x_", 58776, 1075180318, "_x_x_x_x_bach_float64_x_x_x_x_", 59122, 3219626892, "_x_x_x_x_bach_float64_x_x_x_x_", 3641, 1075180268, "_x_x_x_x_bach_float64_x_x_x_x_", 616, 3219774182, "_x_x_x_x_bach_float64_x_x_x_x_", 3577, 1075179983, "_x_x_x_x_bach_float64_x_x_x_x_", 14067, 3219921660, "_x_x_x_x_bach_float64_x_x_x_x_", 44731, 1075179462, "_x_x_x_x_bach_float64_x_x_x_x_", 37424, 3220069301, "_x_x_x_x_bach_float64_x_x_x_x_", 10035, 1075178704, "_x_x_x_x_bach_float64_x_x_x_x_", 38775, 3220196988, "_x_x_x_x_bach_float64_x_x_x_x_", 5008, 1075177709, "_x_x_x_x_bach_float64_x_x_x_x_", 38560, 3220270934, "_x_x_x_x_bach_float64_x_x_x_x_", 804, 1075176477, "_x_x_x_x_bach_float64_x_x_x_x_", 12020, 3220344926, "_x_x_x_x_bach_float64_x_x_x_x_", 39483, 1075175006, "_x_x_x_x_bach_float64_x_x_x_x_", 53084, 3220418949, "_x_x_x_x_bach_float64_x_x_x_x_", 18226, 1075173296, "_x_x_x_x_bach_float64_x_x_x_x_", 59695, 3220492993, "_x_x_x_x_bach_float64_x_x_x_x_", 35360, 1075171348, "_x_x_x_x_bach_float64_x_x_x_x_", 14509, 3220567045, "_x_x_x_x_bach_float64_x_x_x_x_", 52779, 1075169160, "_x_x_x_x_bach_float64_x_x_x_x_", 53605, 3220641092, "_x_x_x_x_bach_float64_x_x_x_x_", 54218, 1075166731, "_x_x_x_x_bach_float64_x_x_x_x_", 60119, 3220715122, "_x_x_x_x_bach_float64_x_x_x_x_", 43829, 1075164063, "_x_x_x_x_bach_float64_x_x_x_x_", 25749, 3220789123, "_x_x_x_x_bach_float64_x_x_x_x_", 15948, 1075161154, "_x_x_x_x_bach_float64_x_x_x_x_", 165, 3220863082, "_x_x_x_x_bach_float64_x_x_x_x_", 26912, 1075158005, "_x_x_x_x_bach_float64_x_x_x_x_", 18667, 3220936986, "_x_x_x_x_bach_float64_x_x_x_x_", 41114, 1075154615, "_x_x_x_x_bach_float64_x_x_x_x_", 7763, 3221010822, "_x_x_x_x_bach_float64_x_x_x_x_", 9820, 1075150983, "_x_x_x_x_bach_float64_x_x_x_x_", 59580, 3221084580, "_x_x_x_x_bach_float64_x_x_x_x_", 51548, 1075147111, "_x_x_x_x_bach_float64_x_x_x_x_", 25549, 3221158244, "_x_x_x_x_bach_float64_x_x_x_x_", 12916, 1075142997, "_x_x_x_x_bach_float64_x_x_x_x_", 65508, 3221228638, "_x_x_x_x_bach_float64_x_x_x_x_", 48240, 1075138641, "_x_x_x_x_bach_float64_x_x_x_x_", 59863, 3221265359, "_x_x_x_x_bach_float64_x_x_x_x_", 54994, 1075134045, "_x_x_x_x_bach_float64_x_x_x_x_", 35964, 3221302015, "_x_x_x_x_bach_float64_x_x_x_x_", 62143, 1075129207, "_x_x_x_x_bach_float64_x_x_x_x_", 38017, 3221338600, "_x_x_x_x_bach_float64_x_x_x_x_", 63929, 1075124129, "_x_x_x_x_bach_float64_x_x_x_x_", 32064, 3221375106, "_x_x_x_x_bach_float64_x_x_x_x_", 19766, 1075118809, "_x_x_x_x_bach_float64_x_x_x_x_", 2344, 3221411529, "_x_x_x_x_bach_float64_x_x_x_x_", 20242, 1075113248, "_x_x_x_x_bach_float64_x_x_x_x_", 62678, 3221447861, "_x_x_x_x_bach_float64_x_x_x_x_", 29107, 1075107447, "_x_x_x_x_bach_float64_x_x_x_x_", 56603, 3221484097, "_x_x_x_x_bach_float64_x_x_x_x_", 53286, 1075101405, "_x_x_x_x_bach_float64_x_x_x_x_", 22777, 3221520229, "_x_x_x_x_bach_float64_x_x_x_x_", 19708, 1075095124, "_x_x_x_x_bach_float64_x_x_x_x_", 16672, 3221556251, "_x_x_x_x_bach_float64_x_x_x_x_", 14371, 1075088602, "_x_x_x_x_bach_float64_x_x_x_x_", 9245, 3221592158, "_x_x_x_x_bach_float64_x_x_x_x_", 31425, 1075081842, "_x_x_x_x_bach_float64_x_x_x_x_", 57988, 3221627943, "_x_x_x_x_bach_float64_x_x_x_x_", 18699, 1075074842, "_x_x_x_x_bach_float64_x_x_x_x_", 28919, 3221663598, "_x_x_x_x_bach_float64_x_x_x_x_", 22903, 1075067604, "_x_x_x_x_bach_float64_x_x_x_x_", 47947, 3221699119, "_x_x_x_x_bach_float64_x_x_x_x_", 41275, 1075060129, "_x_x_x_x_bach_float64_x_x_x_x_", 42957, 3221734499, "_x_x_x_x_bach_float64_x_x_x_x_", 38214, 1075052416, "_x_x_x_x_bach_float64_x_x_x_x_", 13529, 3221769731, "_x_x_x_x_bach_float64_x_x_x_x_", 61437, 1075044466, "_x_x_x_x_bach_float64_x_x_x_x_", 44966, 3221804809, "_x_x_x_x_bach_float64_x_x_x_x_", 64232, 1075036280, "_x_x_x_x_bach_float64_x_x_x_x_", 13, 3221839727, "_x_x_x_x_bach_float64_x_x_x_x_", 23619, 1075027858, "_x_x_x_x_bach_float64_x_x_x_x_", 1366, 3221874479, "_x_x_x_x_bach_float64_x_x_x_x_", 26724, 1075019202, "_x_x_x_x_bach_float64_x_x_x_x_", 712, 3221909057, "_x_x_x_x_bach_float64_x_x_x_x_", 63030, 1075010312, "_x_x_x_x_bach_float64_x_x_x_x_", 5556, 3221943457, "_x_x_x_x_bach_float64_x_x_x_x_", 46927, 1075001189, "_x_x_x_x_bach_float64_x_x_x_x_", 46457, 3221977671, "_x_x_x_x_bach_float64_x_x_x_x_", 4733, 1074991834, "_x_x_x_x_bach_float64_x_x_x_x_", 13820, 3222011694, "_x_x_x_x_bach_float64_x_x_x_x_", 33214, 1074982247, "_x_x_x_x_bach_float64_x_x_x_x_", 19733, 3222045518, "_x_x_x_x_bach_float64_x_x_x_x_", 29291, 1074972429, "_x_x_x_x_bach_float64_x_x_x_x_", 38031, 3222079139, "_x_x_x_x_bach_float64_x_x_x_x_", 43097, 1074962383, "_x_x_x_x_bach_float64_x_x_x_x_", 1958, 3222112549, "_x_x_x_x_bach_float64_x_x_x_x_", 9006, 1074952107, "_x_x_x_x_bach_float64_x_x_x_x_", 30517, 3222145743, "_x_x_x_x_bach_float64_x_x_x_x_", 34372, 1074941605, "_x_x_x_x_bach_float64_x_x_x_x_", 62036, 3222178714, "_x_x_x_x_bach_float64_x_x_x_x_", 707, 1074930876, "_x_x_x_x_bach_float64_x_x_x_x_", 7822, 3222211457, "_x_x_x_x_bach_float64_x_x_x_x_", 50239, 1074919921, "_x_x_x_x_bach_float64_x_x_x_x_", 32381, 3222243964, "_x_x_x_x_bach_float64_x_x_x_x_" ],
									"whole_graph_data_0000000001" : [ 57179, 1074908743, "_x_x_x_x_bach_float64_x_x_x_x_", 20610, 3222275139, "_x_x_x_x_bach_float64_x_x_x_x_", 49931, 1074897342, "_x_x_x_x_bach_float64_x_x_x_x_", 39911, 3222291149, "_x_x_x_x_bach_float64_x_x_x_x_", 11251, 1074885720, "_x_x_x_x_bach_float64_x_x_x_x_", 34929, 3222307032, "_x_x_x_x_bach_float64_x_x_x_x_", 39475, 1074873877, "_x_x_x_x_bach_float64_x_x_x_x_", 30615, 3222322786, "_x_x_x_x_bach_float64_x_x_x_x_", 18922, 1074861816, "_x_x_x_x_bach_float64_x_x_x_x_", 8282, 3222338407, "_x_x_x_x_bach_float64_x_x_x_x_", 44520, 1074849537, "_x_x_x_x_bach_float64_x_x_x_x_", 54797, 3222353893, "_x_x_x_x_bach_float64_x_x_x_x_", 28064, 1074837042, "_x_x_x_x_bach_float64_x_x_x_x_", 47855, 3222369240, "_x_x_x_x_bach_float64_x_x_x_x_", 58697, 1074824333, "_x_x_x_x_bach_float64_x_x_x_x_", 56049, 3222384445, "_x_x_x_x_bach_float64_x_x_x_x_", 10676, 1074811410, "_x_x_x_x_bach_float64_x_x_x_x_", 11957, 3222399507, "_x_x_x_x_bach_float64_x_x_x_x_", 36552, 1074798276, "_x_x_x_x_bach_float64_x_x_x_x_", 33743, 3222414421, "_x_x_x_x_bach_float64_x_x_x_x_", 25541, 1074779465, "_x_x_x_x_bach_float64_x_x_x_x_", 18807, 3222429184, "_x_x_x_x_bach_float64_x_x_x_x_", 3858, 1074752360, "_x_x_x_x_bach_float64_x_x_x_x_", 16263, 3222443795, "_x_x_x_x_bach_float64_x_x_x_x_", 55941, 1074724843, "_x_x_x_x_bach_float64_x_x_x_x_", 1634, 3222458250, "_x_x_x_x_bach_float64_x_x_x_x_", 32467, 1074696915, "_x_x_x_x_bach_float64_x_x_x_x_", 36257, 3222472546, "_x_x_x_x_bach_float64_x_x_x_x_", 59332, 1074668582, "_x_x_x_x_bach_float64_x_x_x_x_", 24738, 3222486680, "_x_x_x_x_bach_float64_x_x_x_x_", 29262, 1074639845, "_x_x_x_x_bach_float64_x_x_x_x_", 52843, 3222500650, "_x_x_x_x_bach_float64_x_x_x_x_", 13839, 1074610710, "_x_x_x_x_bach_float64_x_x_x_x_", 60395, 3222514452, "_x_x_x_x_bach_float64_x_x_x_x_", 22851, 1074581179, "_x_x_x_x_bach_float64_x_x_x_x_", 28346, 3222528085, "_x_x_x_x_bach_float64_x_x_x_x_", 28805, 1074551257, "_x_x_x_x_bach_float64_x_x_x_x_", 24134, 3222541545, "_x_x_x_x_bach_float64_x_x_x_x_", 60441, 1074520947, "_x_x_x_x_bach_float64_x_x_x_x_", 39607, 3222554830, "_x_x_x_x_bach_float64_x_x_x_x_", 37300, 1074490254, "_x_x_x_x_bach_float64_x_x_x_x_", 13974, 3222567936, "_x_x_x_x_bach_float64_x_x_x_x_", 1582, 1074459181, "_x_x_x_x_bach_float64_x_x_x_x_", 41776, 3222580862, "_x_x_x_x_bach_float64_x_x_x_x_", 25838, 1074427732, "_x_x_x_x_bach_float64_x_x_x_x_", 44124, 3222593604, "_x_x_x_x_bach_float64_x_x_x_x_", 59839, 1074395912, "_x_x_x_x_bach_float64_x_x_x_x_", 17277, 3222606160, "_x_x_x_x_bach_float64_x_x_x_x_", 43664, 1074363725, "_x_x_x_x_bach_float64_x_x_x_x_", 5894, 3222618527, "_x_x_x_x_bach_float64_x_x_x_x_", 25899, 1074331175, "_x_x_x_x_bach_float64_x_x_x_x_", 62885, 3222630703, "_x_x_x_x_bach_float64_x_x_x_x_", 24524, 1074298267, "_x_x_x_x_bach_float64_x_x_x_x_", 64268, 3222642685, "_x_x_x_x_bach_float64_x_x_x_x_", 24383, 1074265005, "_x_x_x_x_bach_float64_x_x_x_x_", 34040, 3222654471, "_x_x_x_x_bach_float64_x_x_x_x_", 45744, 1074231394, "_x_x_x_x_bach_float64_x_x_x_x_", 61056, 3222666058, "_x_x_x_x_bach_float64_x_x_x_x_", 22493, 1074197439, "_x_x_x_x_bach_float64_x_x_x_x_", 4280, 3222677444, "_x_x_x_x_bach_float64_x_x_x_x_", 14050, 1074163143, "_x_x_x_x_bach_float64_x_x_x_x_", 34388, 3222688625, "_x_x_x_x_bach_float64_x_x_x_x_", 31075, 1074128512, "_x_x_x_x_bach_float64_x_x_x_x_", 45394, 3222699601, "_x_x_x_x_bach_float64_x_x_x_x_", 64624, 1074093551, "_x_x_x_x_bach_float64_x_x_x_x_", 32964, 3222710368, "_x_x_x_x_bach_float64_x_x_x_x_", 57298, 1074058264, "_x_x_x_x_bach_float64_x_x_x_x_", 62817, 3222720924, "_x_x_x_x_bach_float64_x_x_x_x_", 13174, 1074022657, "_x_x_x_x_bach_float64_x_x_x_x_", 25332, 3222731267, "_x_x_x_x_bach_float64_x_x_x_x_", 50595, 1073986735, "_x_x_x_x_bach_float64_x_x_x_x_", 28060, 3222741394, "_x_x_x_x_bach_float64_x_x_x_x_", 4625, 1073950502, "_x_x_x_x_bach_float64_x_x_x_x_", 49427, 3222751304, "_x_x_x_x_bach_float64_x_x_x_x_", 21565, 1073913964, "_x_x_x_x_bach_float64_x_x_x_x_", 32822, 3222760993, "_x_x_x_x_bach_float64_x_x_x_x_", 49007, 1073877126, "_x_x_x_x_bach_float64_x_x_x_x_", 27642, 3222770460, "_x_x_x_x_bach_float64_x_x_x_x_", 56324, 1073839993, "_x_x_x_x_bach_float64_x_x_x_x_", 48990, 3222779703, "_x_x_x_x_bach_float64_x_x_x_x_", 3786, 1073802571, "_x_x_x_x_bach_float64_x_x_x_x_", 49148, 3222788719, "_x_x_x_x_bach_float64_x_x_x_x_", 18503, 1073764865, "_x_x_x_x_bach_float64_x_x_x_x_", 131, 3222797507, "_x_x_x_x_bach_float64_x_x_x_x_", 50237, 1073711939, "_x_x_x_x_bach_float64_x_x_x_x_", 21698, 3222806063, "_x_x_x_x_bach_float64_x_x_x_x_", 20726, 1073635425, "_x_x_x_x_bach_float64_x_x_x_x_", 29929, 3222814387, "_x_x_x_x_bach_float64_x_x_x_x_", 10514, 1073558377, "_x_x_x_x_bach_float64_x_x_x_x_", 20276, 3222822476, "_x_x_x_x_bach_float64_x_x_x_x_", 28477, 1073480806, "_x_x_x_x_bach_float64_x_x_x_x_", 1578, 3222830328, "_x_x_x_x_bach_float64_x_x_x_x_", 46359, 1073402723, "_x_x_x_x_bach_float64_x_x_x_x_", 39490, 3222837941, "_x_x_x_x_bach_float64_x_x_x_x_", 41993, 1073324141, "_x_x_x_x_bach_float64_x_x_x_x_", 15671, 3222845314, "_x_x_x_x_bach_float64_x_x_x_x_", 6024, 1073245069, "_x_x_x_x_bach_float64_x_x_x_x_", 19995, 3222852444, "_x_x_x_x_bach_float64_x_x_x_x_", 43065, 1073165522, "_x_x_x_x_bach_float64_x_x_x_x_", 64571, 3222859330, "_x_x_x_x_bach_float64_x_x_x_x_", 45505, 1073085510, "_x_x_x_x_bach_float64_x_x_x_x_", 36848, 3222865970, "_x_x_x_x_bach_float64_x_x_x_x_", 54011, 1073005045, "_x_x_x_x_bach_float64_x_x_x_x_", 22462, 3222872362, "_x_x_x_x_bach_float64_x_x_x_x_", 61153, 1072924140, "_x_x_x_x_bach_float64_x_x_x_x_", 14424, 3222878504, "_x_x_x_x_bach_float64_x_x_x_x_", 46231, 1072842806, "_x_x_x_x_bach_float64_x_x_x_x_", 56973, 3222884395, "_x_x_x_x_bach_float64_x_x_x_x_", 44585, 1072761057, "_x_x_x_x_bach_float64_x_x_x_x_", 37182, 3222890033, "_x_x_x_x_bach_float64_x_x_x_x_", 50073, 1072664561, "_x_x_x_x_bach_float64_x_x_x_x_", 41674, 3222895416, "_x_x_x_x_bach_float64_x_x_x_x_", 678, 1072499473, "_x_x_x_x_bach_float64_x_x_x_x_", 32734, 3222900544, "_x_x_x_x_bach_float64_x_x_x_x_", 27952, 1072333629, "_x_x_x_x_bach_float64_x_x_x_x_", 23302, 3222905413, "_x_x_x_x_bach_float64_x_x_x_x_", 4478, 1072167054, "_x_x_x_x_bach_float64_x_x_x_x_", 29519, 3222910024, "_x_x_x_x_bach_float64_x_x_x_x_", 52436, 1071999773, "_x_x_x_x_bach_float64_x_x_x_x_", 62720, 3222914374, "_x_x_x_x_bach_float64_x_x_x_x_", 43302, 1071831813, "_x_x_x_x_bach_float64_x_x_x_x_", 29454, 3222918462, "_x_x_x_x_bach_float64_x_x_x_x_", 38167, 1071663199, "_x_x_x_x_bach_float64_x_x_x_x_", 63521, 3222922286, "_x_x_x_x_bach_float64_x_x_x_x_", 63341, 1071343245, "_x_x_x_x_bach_float64_x_x_x_x_", 44511, 3222925846, "_x_x_x_x_bach_float64_x_x_x_x_", 39587, 1071003560, "_x_x_x_x_bach_float64_x_x_x_x_", 6539, 3222929140, "_x_x_x_x_bach_float64_x_x_x_x_", 62157, 1070662726, "_x_x_x_x_bach_float64_x_x_x_x_", 60537, 3222932167, "_x_x_x_x_bach_float64_x_x_x_x_", 49794, 1070045498, "_x_x_x_x_bach_float64_x_x_x_x_", 26494, 3222934925, "_x_x_x_x_bach_float64_x_x_x_x_", 31870, 1069171590, "_x_x_x_x_bach_float64_x_x_x_x_", 20504, 3222937414, "_x_x_x_x_bach_float64_x_x_x_x_", 9347, 1066734756, "_x_x_x_x_bach_float64_x_x_x_x_", 30246, 3222939632, "_x_x_x_x_bach_float64_x_x_x_x_", 32301, 3215953814, "_x_x_x_x_bach_float64_x_x_x_x_", 51517, 3222941578, "_x_x_x_x_bach_float64_x_x_x_x_", 49075, 3217191230, "_x_x_x_x_bach_float64_x_x_x_x_", 64598, 3222943251, "_x_x_x_x_bach_float64_x_x_x_x_", 64958, 3217884422, "_x_x_x_x_bach_float64_x_x_x_x_", 46846, 3222944651, "_x_x_x_x_bach_float64_x_x_x_x_", 11016, 3218329448, "_x_x_x_x_bach_float64_x_x_x_x_", 21193, 3222945776, "_x_x_x_x_bach_float64_x_x_x_x_", 56963, 3218677527, "_x_x_x_x_bach_float64_x_x_x_x_", 9251, 3222946625, "_x_x_x_x_bach_float64_x_x_x_x_", 46812, 3219026264, "_x_x_x_x_bach_float64_x_x_x_x_", 19830, 3222947198, "_x_x_x_x_bach_float64_x_x_x_x_", 28528, 3219251961, "_x_x_x_x_bach_float64_x_x_x_x_", 7070, 3222947493, "_x_x_x_x_bach_float64_x_x_x_x_", 19645, 3219426903, "_x_x_x_x_bach_float64_x_x_x_x_", 60104, 3222947511, "_x_x_x_x_bach_float64_x_x_x_x_", 41886, 3219602090, "_x_x_x_x_bach_float64_x_x_x_x_", 37562, 3222947249, "_x_x_x_x_bach_float64_x_x_x_x_", 44054, 3219777493, "_x_x_x_x_bach_float64_x_x_x_x_", 22936, 3222946708, "_x_x_x_x_bach_float64_x_x_x_x_", 411, 3219953085, "_x_x_x_x_bach_float64_x_x_x_x_", 27716, 3222945888, "_x_x_x_x_bach_float64_x_x_x_x_", 24578, 3220128835, "_x_x_x_x_bach_float64_x_x_x_x_", 56182, 3222944786, "_x_x_x_x_bach_float64_x_x_x_x_", 37970, 3220240806, "_x_x_x_x_bach_float64_x_x_x_x_", 7332, 3222943403, "_x_x_x_x_bach_float64_x_x_x_x_", 54980, 3220328798, "_x_x_x_x_bach_float64_x_x_x_x_", 3560, 3222941738, "_x_x_x_x_bach_float64_x_x_x_x_", 39127, 3220416826, "_x_x_x_x_bach_float64_x_x_x_x_", 31763, 3222939792, "_x_x_x_x_bach_float64_x_x_x_x_", 18119, 3220504876, "_x_x_x_x_bach_float64_x_x_x_x_", 10781, 3222937562, "_x_x_x_x_bach_float64_x_x_x_x_", 15069, 3220592935, "_x_x_x_x_bach_float64_x_x_x_x_", 22820, 3222935050, "_x_x_x_x_bach_float64_x_x_x_x_", 41862, 3220680986, "_x_x_x_x_bach_float64_x_x_x_x_", 53292, 3222932255, "_x_x_x_x_bach_float64_x_x_x_x_", 12183, 3220769016, "_x_x_x_x_bach_float64_x_x_x_x_", 25356, 3222929176, "_x_x_x_x_bach_float64_x_x_x_x_", 28457, 3220857010, "_x_x_x_x_bach_float64_x_x_x_x_", 63376, 3222925813, "_x_x_x_x_bach_float64_x_x_x_x_", 60493, 3220944953, "_x_x_x_x_bach_float64_x_x_x_x_", 2137, 3222922166, "_x_x_x_x_bach_float64_x_x_x_x_", 60723, 3221032831, "_x_x_x_x_bach_float64_x_x_x_x_", 42140, 3222918236, "_x_x_x_x_bach_float64_x_x_x_x_", 56974, 3221120630, "_x_x_x_x_bach_float64_x_x_x_x_", 60478, 3222914021, "_x_x_x_x_bach_float64_x_x_x_x_", 23586, 3221208333, "_x_x_x_x_bach_float64_x_x_x_x_", 1926, 3222909523, "_x_x_x_x_bach_float64_x_x_x_x_", 26999, 3221260700, "_x_x_x_x_bach_float64_x_x_x_x_", 39417, 3222904740, "_x_x_x_x_bach_float64_x_x_x_x_", 22876, 3221304435, "_x_x_x_x_bach_float64_x_x_x_x_", 44920, 3222899673, "_x_x_x_x_bach_float64_x_x_x_x_", 38587, 3221348101, "_x_x_x_x_bach_float64_x_x_x_x_", 9086, 3222894322, "_x_x_x_x_bach_float64_x_x_x_x_", 48057, 3221391690, "_x_x_x_x_bach_float64_x_x_x_x_", 33156, 3222888688, "_x_x_x_x_bach_float64_x_x_x_x_", 49964, 3221435195, "_x_x_x_x_bach_float64_x_x_x_x_", 24117, 3222882770, "_x_x_x_x_bach_float64_x_x_x_x_", 41757, 3221478608, "_x_x_x_x_bach_float64_x_x_x_x_", 10523, 3222876569, "_x_x_x_x_bach_float64_x_x_x_x_", 7618, 3221521922, "_x_x_x_x_bach_float64_x_x_x_x_", 30192, 3222870085, "_x_x_x_x_bach_float64_x_x_x_x_", 51060, 3221565130, "_x_x_x_x_bach_float64_x_x_x_x_", 48489, 3222863318, "_x_x_x_x_bach_float64_x_x_x_x_", 15451, 3221608225, "_x_x_x_x_bach_float64_x_x_x_x_", 38099, 3222856269, "_x_x_x_x_bach_float64_x_x_x_x_", 33683, 3221651198, "_x_x_x_x_bach_float64_x_x_x_x_", 23663, 3222848938, "_x_x_x_x_bach_float64_x_x_x_x_", 39528, 3221694043, "_x_x_x_x_bach_float64_x_x_x_x_", 25498, 3222841327, "_x_x_x_x_bach_float64_x_x_x_x_", 9952, 3221736752, "_x_x_x_x_bach_float64_x_x_x_x_", 33580, 3222833434, "_x_x_x_x_bach_float64_x_x_x_x_", 18997, 3221779318, "_x_x_x_x_bach_float64_x_x_x_x_", 11456, 3222825261, "_x_x_x_x_bach_float64_x_x_x_x_", 37988, 3221821733, "_x_x_x_x_bach_float64_x_x_x_x_", 61335, 3222816809, "_x_x_x_x_bach_float64_x_x_x_x_", 4083, 3221863990, "_x_x_x_x_bach_float64_x_x_x_x_", 29161, 3222808079, "_x_x_x_x_bach_float64_x_x_x_x_", 26377, 3221906082, "_x_x_x_x_bach_float64_x_x_x_x_", 57100, 3222799070, "_x_x_x_x_bach_float64_x_x_x_x_", 6776, 3221948001, "_x_x_x_x_bach_float64_x_x_x_x_", 51649, 3222789784, "_x_x_x_x_bach_float64_x_x_x_x_", 51663, 3221989740, "_x_x_x_x_bach_float64_x_x_x_x_", 33433, 3222780222, "_x_x_x_x_bach_float64_x_x_x_x_", 34577, 3222031292, "_x_x_x_x_bach_float64_x_x_x_x_", 57910, 3222770384, "_x_x_x_x_bach_float64_x_x_x_x_", 13204, 3222072649, "_x_x_x_x_bach_float64_x_x_x_x_", 34678, 3222760272, "_x_x_x_x_bach_float64_x_x_x_x_", 57529, 3222113804, "_x_x_x_x_bach_float64_x_x_x_x_", 35018, 3222749886, "_x_x_x_x_bach_float64_x_x_x_x_", 13133, 3222154750, "_x_x_x_x_bach_float64_x_x_x_x_", 39273, 3222739228, "_x_x_x_x_bach_float64_x_x_x_x_", 49915, 3222195479, "_x_x_x_x_bach_float64_x_x_x_x_", 41354, 3222728299, "_x_x_x_x_bach_float64_x_x_x_x_", 29842, 3222235985, "_x_x_x_x_bach_float64_x_x_x_x_", 51690, 3222717099, "_x_x_x_x_bach_float64_x_x_x_x_", 58669, 3222275154, "_x_x_x_x_bach_float64_x_x_x_x_", 64186, 3222705630, "_x_x_x_x_bach_float64_x_x_x_x_", 4855, 3222295172, "_x_x_x_x_bach_float64_x_x_x_x_", 52571, 3222693893, "_x_x_x_x_bach_float64_x_x_x_x_", 32036, 3222315068, "_x_x_x_x_bach_float64_x_x_x_x_", 61900, 3222681889, "_x_x_x_x_bach_float64_x_x_x_x_", 29538, 3222334837, "_x_x_x_x_bach_float64_x_x_x_x_", 1682, 3222669620, "_x_x_x_x_bach_float64_x_x_x_x_", 24055, 3222354477, "_x_x_x_x_bach_float64_x_x_x_x_", 58519, 3222657088, "_x_x_x_x_bach_float64_x_x_x_x_", 12461, 3222373983, "_x_x_x_x_bach_float64_x_x_x_x_", 23999, 3222644292, "_x_x_x_x_bach_float64_x_x_x_x_", 52900, 3222393353, "_x_x_x_x_bach_float64_x_x_x_x_", 28500, 3222631236, "_x_x_x_x_bach_float64_x_x_x_x_", 23410, 3222412582, "_x_x_x_x_bach_float64_x_x_x_x_", 59296, 3222617920, "_x_x_x_x_bach_float64_x_x_x_x_", 30967, 3222431667, "_x_x_x_x_bach_float64_x_x_x_x_", 32622, 3222604346, "_x_x_x_x_bach_float64_x_x_x_x_", 28475, 3222450605, "_x_x_x_x_bach_float64_x_x_x_x_", 26386, 3222590516, "_x_x_x_x_bach_float64_x_x_x_x_", 15623, 3222469392, "_x_x_x_x_bach_float64_x_x_x_x_", 18412, 3222576431, "_x_x_x_x_bach_float64_x_x_x_x_", 36514, 3222488024, "_x_x_x_x_bach_float64_x_x_x_x_", 47502, 3222562094, "_x_x_x_x_bach_float64_x_x_x_x_", 39396, 3222506499, "_x_x_x_x_bach_float64_x_x_x_x_", 11254, 3222547504, "_x_x_x_x_bach_float64_x_x_x_x_", 56470, 3222524813, "_x_x_x_x_bach_float64_x_x_x_x_", 17947, 3222532666, "_x_x_x_x_bach_float64_x_x_x_x_", 48191, 3222542962, "_x_x_x_x_bach_float64_x_x_x_x_", 47497, 3222517579, "_x_x_x_x_bach_float64_x_x_x_x_", 1310, 3222560943, "_x_x_x_x_bach_float64_x_x_x_x_", 35759, 3222502247, "_x_x_x_x_bach_float64_x_x_x_x_", 17928, 3222578753, "_x_x_x_x_bach_float64_x_x_x_x_", 54352, 3222486671, "_x_x_x_x_bach_float64_x_x_x_x_", 2157, 3222596388, "_x_x_x_x_bach_float64_x_x_x_x_", 62136, 3222470854, "_x_x_x_x_bach_float64_x_x_x_x_", 57630, 3222613845, "_x_x_x_x_bach_float64_x_x_x_x_", 14465, 3222454796, "_x_x_x_x_bach_float64_x_x_x_x_", 23018, 3222631121, "_x_x_x_x_bach_float64_x_x_x_x_", 3089, 3222438501, "_x_x_x_x_bach_float64_x_x_x_x_", 45093, 3222648212, "_x_x_x_x_bach_float64_x_x_x_x_", 33200, 3222421969, "_x_x_x_x_bach_float64_x_x_x_x_", 26645, 3222665115, "_x_x_x_x_bach_float64_x_x_x_x_", 27886, 3222405205, "_x_x_x_x_bach_float64_x_x_x_x_", 45591, 3222681828, "_x_x_x_x_bach_float64_x_x_x_x_", 59875, 3222388209, "_x_x_x_x_bach_float64_x_x_x_x_", 41105, 3222698346, "_x_x_x_x_bach_float64_x_x_x_x_", 24420, 3222370984, "_x_x_x_x_bach_float64_x_x_x_x_", 11361, 3222714667, "_x_x_x_x_bach_float64_x_x_x_x_", 64082, 3222353532, "_x_x_x_x_bach_float64_x_x_x_x_", 1605, 3222730787, "_x_x_x_x_bach_float64_x_x_x_x_", 41763, 3222335855, "_x_x_x_x_bach_float64_x_x_x_x_", 13026, 3222746703, "_x_x_x_x_bach_float64_x_x_x_x_", 27986, 3222317957, "_x_x_x_x_bach_float64_x_x_x_x_", 28816, 3222762413, "_x_x_x_x_bach_float64_x_x_x_x_", 33385, 3222299838, "_x_x_x_x_bach_float64_x_x_x_x_", 25598, 3222777913, "_x_x_x_x_bach_float64_x_x_x_x_", 34906, 3222281503, "_x_x_x_x_bach_float64_x_x_x_x_", 35539, 3222793200, "_x_x_x_x_bach_float64_x_x_x_x_", 2120, 3222251857, "_x_x_x_x_bach_float64_x_x_x_x_", 61979, 3222808271, "_x_x_x_x_bach_float64_x_x_x_x_", 29661, 3222214332, "_x_x_x_x_bach_float64_x_x_x_x_", 44667, 3222823123, "_x_x_x_x_bach_float64_x_x_x_x_", 5208, 3222176387, "_x_x_x_x_bach_float64_x_x_x_x_", 5417, 3222837753, "_x_x_x_x_bach_float64_x_x_x_x_", 39990, 3222138028, "_x_x_x_x_bach_float64_x_x_x_x_", 45753, 3222852158, "_x_x_x_x_bach_float64_x_x_x_x_", 25769, 3222099261, "_x_x_x_x_bach_float64_x_x_x_x_", 65437, 3222866336, "_x_x_x_x_bach_float64_x_x_x_x_", 9462, 3222060090, "_x_x_x_x_bach_float64_x_x_x_x_", 52922, 3222880283, "_x_x_x_x_bach_float64_x_x_x_x_", 43390, 3222020521, "_x_x_x_x_bach_float64_x_x_x_x_", 30216, 3222893997, "_x_x_x_x_bach_float64_x_x_x_x_", 36726, 3221980560, "_x_x_x_x_bach_float64_x_x_x_x_", 44605, 3222907474, "_x_x_x_x_bach_float64_x_x_x_x_", 1141, 3221940212, "_x_x_x_x_bach_float64_x_x_x_x_", 10403, 3222920713, "_x_x_x_x_bach_float64_x_x_x_x_", 36157, 3221899483, "_x_x_x_x_bach_float64_x_x_x_x_", 55542, 3222933710, "_x_x_x_x_bach_float64_x_x_x_x_", 54351, 3221858379, "_x_x_x_x_bach_float64_x_x_x_x_", 61902, 3222946462, "_x_x_x_x_bach_float64_x_x_x_x_", 33751, 3221816905, "_x_x_x_x_bach_float64_x_x_x_x_", 37255, 3222958967, "_x_x_x_x_bach_float64_x_x_x_x_", 10811, 3221775068, "_x_x_x_x_bach_float64_x_x_x_x_", 7856, 3222971223, "_x_x_x_x_bach_float64_x_x_x_x_", 11826, 3221732873, "_x_x_x_x_bach_float64_x_x_x_x_", 20847, 3222983226, "_x_x_x_x_bach_float64_x_x_x_x_", 53719, 3221690328, "_x_x_x_x_bach_float64_x_x_x_x_", 59644, 3222994975, "_x_x_x_x_bach_float64_x_x_x_x_", 18382, 3221647436, "_x_x_x_x_bach_float64_x_x_x_x_", 2881, 3223006466, "_x_x_x_x_bach_float64_x_x_x_x_", 56662, 3221604206, "_x_x_x_x_bach_float64_x_x_x_x_", 19628, 3223017697, "_x_x_x_x_bach_float64_x_x_x_x_", 14731, 3221560644, "_x_x_x_x_bach_float64_x_x_x_x_", 24380, 3223028666, "_x_x_x_x_bach_float64_x_x_x_x_", 46493, 3221516755, "_x_x_x_x_bach_float64_x_x_x_x_", 26270, 3223039370, "_x_x_x_x_bach_float64_x_x_x_x_", 52954, 3221472546, "_x_x_x_x_bach_float64_x_x_x_x_", 61489, 3223049808, "_x_x_x_x_bach_float64_x_x_x_x_", 46760, 3221428023, "_x_x_x_x_bach_float64_x_x_x_x_", 36050, 3223059975, "_x_x_x_x_bach_float64_x_x_x_x_", 65487, 3221383194, "_x_x_x_x_bach_float64_x_x_x_x_", 2979, 3223069871, "_x_x_x_x_bach_float64_x_x_x_x_", 28504, 3221338065, "_x_x_x_x_bach_float64_x_x_x_x_", 21327, 3223079493, "_x_x_x_x_bach_float64_x_x_x_x_", 61000, 3221292642, "_x_x_x_x_bach_float64_x_x_x_x_", 55646, 3223088839, "_x_x_x_x_bach_float64_x_x_x_x_", 42059, 3221246933, "_x_x_x_x_bach_float64_x_x_x_x_", 46308, 3223097907, "_x_x_x_x_bach_float64_x_x_x_x_", 28994, 3221176415, "_x_x_x_x_bach_float64_x_x_x_x_", 19476, 3223106694, "_x_x_x_x_bach_float64_x_x_x_x_", 32656, 3221083890, "_x_x_x_x_bach_float64_x_x_x_x_", 39532, 3223115198, "_x_x_x_x_bach_float64_x_x_x_x_", 43834, 3220990833, "_x_x_x_x_bach_float64_x_x_x_x_", 3730, 3223123418, "_x_x_x_x_bach_float64_x_x_x_x_", 53058, 3220897258, "_x_x_x_x_bach_float64_x_x_x_x_", 65063, 3223131352, "_x_x_x_x_bach_float64_x_x_x_x_", 26066, 3220803179, "_x_x_x_x_bach_float64_x_x_x_x_", 44545, 3223138996, "_x_x_x_x_bach_float64_x_x_x_x_", 60652, 3220708611, "_x_x_x_x_bach_float64_x_x_x_x_", 60854, 3223146351, "_x_x_x_x_bach_float64_x_x_x_x_", 47922, 3220613567, "_x_x_x_x_bach_float64_x_x_x_x_", 17615, 3223153413, "_x_x_x_x_bach_float64_x_x_x_x_", 19509, 3220518062, "_x_x_x_x_bach_float64_x_x_x_x_", 45105, 3223160180, "_x_x_x_x_bach_float64_x_x_x_x_", 1515, 3220422111, "_x_x_x_x_bach_float64_x_x_x_x_", 61076, 3223166652, "_x_x_x_x_bach_float64_x_x_x_x_", 32448, 3220325728, "_x_x_x_x_bach_float64_x_x_x_x_", 23179, 3223172826, "_x_x_x_x_bach_float64_x_x_x_x_", 19548, 3220228929, "_x_x_x_x_bach_float64_x_x_x_x_", 20643, 3223178701, "_x_x_x_x_bach_float64_x_x_x_x_", 46508, 3220086559, "_x_x_x_x_bach_float64_x_x_x_x_", 8352, 3223184274, "_x_x_x_x_bach_float64_x_x_x_x_", 46448, 3219891383, "_x_x_x_x_bach_float64_x_x_x_x_", 34822, 3223189545, "_x_x_x_x_bach_float64_x_x_x_x_", 33212, 3219695463, "_x_x_x_x_bach_float64_x_x_x_x_", 46406, 3223194512, "_x_x_x_x_bach_float64_x_x_x_x_", 54360, 3219498829, "_x_x_x_x_bach_float64_x_x_x_x_", 53662, 3223199173, "_x_x_x_x_bach_float64_x_x_x_x_", 48270, 3219301513, "_x_x_x_x_bach_float64_x_x_x_x_", 4336, 3223203527, "_x_x_x_x_bach_float64_x_x_x_x_", 18, 3219078771, "_x_x_x_x_bach_float64_x_x_x_x_", 17934, 3223207573, "_x_x_x_x_bach_float64_x_x_x_x_", 44526, 3218681593, "_x_x_x_x_bach_float64_x_x_x_x_", 64080, 3223211308, "_x_x_x_x_bach_float64_x_x_x_x_", 12190, 3218283235, "_x_x_x_x_bach_float64_x_x_x_x_", 1883, 3223214733, "_x_x_x_x_bach_float64_x_x_x_x_", 26409, 3217687775, "_x_x_x_x_bach_float64_x_x_x_x_", 45511, 3223217844, "_x_x_x_x_bach_float64_x_x_x_x_", 5794, 3216742263, "_x_x_x_x_bach_float64_x_x_x_x_", 17294, 3223220642, "_x_x_x_x_bach_float64_x_x_x_x_", 26191, 3213405580, "_x_x_x_x_bach_float64_x_x_x_x_", 9513, 3223223126, "_x_x_x_x_bach_float64_x_x_x_x_", 35059, 1068858004, "_x_x_x_x_bach_float64_x_x_x_x_", 29729, 3223225293, "_x_x_x_x_bach_float64_x_x_x_x_", 8611, 1070009389, "_x_x_x_x_bach_float64_x_x_x_x_", 5662, 3223227143, "_x_x_x_x_bach_float64_x_x_x_x_", 32034, 1070706856, "_x_x_x_x_bach_float64_x_x_x_x_", 18254, 3223228675, "_x_x_x_x_bach_float64_x_x_x_x_", 34590, 1071111706, "_x_x_x_x_bach_float64_x_x_x_x_", 41731, 3223229888, "_x_x_x_x_bach_float64_x_x_x_x_", 64290, 1071517228, "_x_x_x_x_bach_float64_x_x_x_x_", 42416, 3223230781, "_x_x_x_x_bach_float64_x_x_x_x_", 31789, 1071784014, "_x_x_x_x_bach_float64_x_x_x_x_", 42765, 3223231353, "_x_x_x_x_bach_float64_x_x_x_x_", 1808, 1071987348, "_x_x_x_x_bach_float64_x_x_x_x_", 19338, 3223231604, "_x_x_x_x_bach_float64_x_x_x_x_", 57668, 1072190921, "_x_x_x_x_bach_float64_x_x_x_x_", 27655, 3223231532, "_x_x_x_x_bach_float64_x_x_x_x_", 2490, 1072394700, "_x_x_x_x_bach_float64_x_x_x_x_", 29410, 3223231137, "_x_x_x_x_bach_float64_x_x_x_x_", 55577, 1072598651, "_x_x_x_x_bach_float64_x_x_x_x_", 11632, 3223230419, "_x_x_x_x_bach_float64_x_x_x_x_", 32216, 1072747994, "_x_x_x_x_bach_float64_x_x_x_x_", 4339, 3223229376, "_x_x_x_x_bach_float64_x_x_x_x_", 39043, 1072850093, "_x_x_x_x_bach_float64_x_x_x_x_", 62015, 3223228008, "_x_x_x_x_bach_float64_x_x_x_x_", 58424, 1072952228, "_x_x_x_x_bach_float64_x_x_x_x_", 12049, 3223226315, "_x_x_x_x_bach_float64_x_x_x_x_", 57836, 1073054383, "_x_x_x_x_bach_float64_x_x_x_x_", 18538, 3223224295, "_x_x_x_x_bach_float64_x_x_x_x_", 53096, 1073156542, "_x_x_x_x_bach_float64_x_x_x_x_", 60670, 3223221950, "_x_x_x_x_bach_float64_x_x_x_x_", 20046, 1073258688, "_x_x_x_x_bach_float64_x_x_x_x_", 29436, 3223219278, "_x_x_x_x_bach_float64_x_x_x_x_", 52552, 1073360803, "_x_x_x_x_bach_float64_x_x_x_x_", 49263, 3223216279, "_x_x_x_x_bach_float64_x_x_x_x_", 43391, 1073462872, "_x_x_x_x_bach_float64_x_x_x_x_", 41320, 3223212953, "_x_x_x_x_bach_float64_x_x_x_x_", 65140, 1073564878, "_x_x_x_x_bach_float64_x_x_x_x_", 35670, 3223209300, "_x_x_x_x_bach_float64_x_x_x_x_", 8955, 1073666803, "_x_x_x_x_bach_float64_x_x_x_x_", 52413, 3223205319, "_x_x_x_x_bach_float64_x_x_x_x_", 57705, 1073755227, "_x_x_x_x_bach_float64_x_x_x_x_", 10433, 3223201011, "_x_x_x_x_bach_float64_x_x_x_x_", 19534, 1073806084, "_x_x_x_x_bach_float64_x_x_x_x_", 56744, 3223196375, "_x_x_x_x_bach_float64_x_x_x_x_", 23034, 1073856876, "_x_x_x_x_bach_float64_x_x_x_x_", 5650, 3223191412, "_x_x_x_x_bach_float64_x_x_x_x_", 42921, 1073907594, "_x_x_x_x_bach_float64_x_x_x_x_", 50132, 3223186121, "_x_x_x_x_bach_float64_x_x_x_x_", 4752, 1073958229, "_x_x_x_x_bach_float64_x_x_x_x_", 58476, 3223180503, "_x_x_x_x_bach_float64_x_x_x_x_", 41297, 1074008774, "_x_x_x_x_bach_float64_x_x_x_x_", 11778, 3223174558, "_x_x_x_x_bach_float64_x_x_x_x_", 42612, 1074059220, "_x_x_x_x_bach_float64_x_x_x_x_", 9425, 3223168287, "_x_x_x_x_bach_float64_x_x_x_x_", 6501, 1074109558, "_x_x_x_x_bach_float64_x_x_x_x_", 38967, 3223161689, "_x_x_x_x_bach_float64_x_x_x_x_", 8191, 1074159779, "_x_x_x_x_bach_float64_x_x_x_x_", 34613, 3223154764, "_x_x_x_x_bach_float64_x_x_x_x_", 51154, 1074209877, "_x_x_x_x_bach_float64_x_x_x_x_", 27540, 3223147514, "_x_x_x_x_bach_float64_x_x_x_x_", 59287, 1074259841, "_x_x_x_x_bach_float64_x_x_x_x_", 60346, 3223139939, "_x_x_x_x_bach_float64_x_x_x_x_", 10188, 1074309664, "_x_x_x_x_bach_float64_x_x_x_x_", 62027, 3223132039, "_x_x_x_x_bach_float64_x_x_x_x_", 11613, 1074359337, "_x_x_x_x_bach_float64_x_x_x_x_", 11146, 3223123815, "_x_x_x_x_bach_float64_x_x_x_x_", 57649, 1074408852, "_x_x_x_x_bach_float64_x_x_x_x_", 59432, 3223115268, "_x_x_x_x_bach_float64_x_x_x_x_", 53994, 1074458199, "_x_x_x_x_bach_float64_x_x_x_x_", 25840, 3223106398, "_x_x_x_x_bach_float64_x_x_x_x_", 45288, 1074507372, "_x_x_x_x_bach_float64_x_x_x_x_", 30525, 3223097205, "_x_x_x_x_bach_float64_x_x_x_x_", 53997, 1074556361, "_x_x_x_x_bach_float64_x_x_x_x_", 40398, 3223087692, "_x_x_x_x_bach_float64_x_x_x_x_", 53596, 1074605159, "_x_x_x_x_bach_float64_x_x_x_x_", 30223, 3223077858, "_x_x_x_x_bach_float64_x_x_x_x_", 10287, 1074653756, "_x_x_x_x_bach_float64_x_x_x_x_", 38136, 3223067705, "_x_x_x_x_bach_float64_x_x_x_x_", 56640, 1074702144, "_x_x_x_x_bach_float64_x_x_x_x_", 50259, 3223057233, "_x_x_x_x_bach_float64_x_x_x_x_", 11084, 1074750315, "_x_x_x_x_bach_float64_x_x_x_x_", 41718, 3223046444, "_x_x_x_x_bach_float64_x_x_x_x_", 5069, 1074794330, "_x_x_x_x_bach_float64_x_x_x_x_", 43316, 3223035338, "_x_x_x_x_bach_float64_x_x_x_x_", 12745, 1074818186, "_x_x_x_x_bach_float64_x_x_x_x_", 36908, 3223023917, "_x_x_x_x_bach_float64_x_x_x_x_", 16636, 1074841922, "_x_x_x_x_bach_float64_x_x_x_x_", 7388, 3223012182, "_x_x_x_x_bach_float64_x_x_x_x_", 57182, 1074865532, "_x_x_x_x_bach_float64_x_x_x_x_", 20034, 3223000134, "_x_x_x_x_bach_float64_x_x_x_x_", 12785, 1074889012, "_x_x_x_x_bach_float64_x_x_x_x_", 61097, 3222987774, "_x_x_x_x_bach_float64_x_x_x_x_", 37717, 1074912360, "_x_x_x_x_bach_float64_x_x_x_x_", 34978, 3222975104, "_x_x_x_x_bach_float64_x_x_x_x_", 13740, 1074935570, "_x_x_x_x_bach_float64_x_x_x_x_", 48829, 3222962126, "_x_x_x_x_bach_float64_x_x_x_x_", 46120, 1074958639, "_x_x_x_x_bach_float64_x_x_x_x_", 1823, 3222948840, "_x_x_x_x_bach_float64_x_x_x_x_", 37785, 1074981562, "_x_x_x_x_bach_float64_x_x_x_x_", 51745, 3222935248, "_x_x_x_x_bach_float64_x_x_x_x_", 44829, 1075004335, "_x_x_x_x_bach_float64_x_x_x_x_", 58550, 3222921352, "_x_x_x_x_bach_float64_x_x_x_x_", 36700, 1075026955, "_x_x_x_x_bach_float64_x_x_x_x_", 36425, 3222907153, "_x_x_x_x_bach_float64_x_x_x_x_", 43390, 1075049417, "_x_x_x_x_bach_float64_x_x_x_x_", 41663, 3222892654, "_x_x_x_x_bach_float64_x_x_x_x_", 34089, 1075071717, "_x_x_x_x_bach_float64_x_x_x_x_", 20485, 3222877855, "_x_x_x_x_bach_float64_x_x_x_x_", 50587, 1075093852, "_x_x_x_x_bach_float64_x_x_x_x_", 10388, 3222862758, "_x_x_x_x_bach_float64_x_x_x_x_", 5675, 1075115817, "_x_x_x_x_bach_float64_x_x_x_x_", 39288, 3222847366, "_x_x_x_x_bach_float64_x_x_x_x_", 62857, 1075137609, "_x_x_x_x_bach_float64_x_x_x_x_", 50706, 3222831680, "_x_x_x_x_bach_float64_x_x_x_x_", 24595, 1075159223, "_x_x_x_x_bach_float64_x_x_x_x_", 51234, 3222815702, "_x_x_x_x_bach_float64_x_x_x_x_", 21843, 1075180656, "_x_x_x_x_bach_float64_x_x_x_x_", 21952, 3222799434, "_x_x_x_x_bach_float64_x_x_x_x_", 14330, 1075201904, "_x_x_x_x_bach_float64_x_x_x_x_", 52400, 3222782879, "_x_x_x_x_bach_float64_x_x_x_x_", 1387, 1075222963, "_x_x_x_x_bach_float64_x_x_x_x_", 41983, 3222766037, "_x_x_x_x_bach_float64_x_x_x_x_", 25459, 1075243828, "_x_x_x_x_bach_float64_x_x_x_x_", 17388, 3222748912, "_x_x_x_x_bach_float64_x_x_x_x_", 33090, 1075264497, "_x_x_x_x_bach_float64_x_x_x_x_", 17711, 3222731506, "_x_x_x_x_bach_float64_x_x_x_x_", 51954, 1075284966, "_x_x_x_x_bach_float64_x_x_x_x_", 5898, 3222713820, "_x_x_x_x_bach_float64_x_x_x_x_", 27669, 1075305230, "_x_x_x_x_bach_float64_x_x_x_x_", 3546, 3222695858, "_x_x_x_x_bach_float64_x_x_x_x_", 41090, 1075325286, "_x_x_x_x_bach_float64_x_x_x_x_", 55713, 3222677621, "_x_x_x_x_bach_float64_x_x_x_x_", 53464, 1075345131, "_x_x_x_x_bach_float64_x_x_x_x_", 25980, 3222659112, "_x_x_x_x_bach_float64_x_x_x_x_", 30802, 1075364760, "_x_x_x_x_bach_float64_x_x_x_x_", 8460, 3222640333, "_x_x_x_x_bach_float64_x_x_x_x_", 54028, 1075384170, "_x_x_x_x_bach_float64_x_x_x_x_", 45883, 3222621287, "_x_x_x_x_bach_float64_x_x_x_x_", 20742, 1075403358, "_x_x_x_x_bach_float64_x_x_x_x_", 6316, 3222601976, "_x_x_x_x_bach_float64_x_x_x_x_", 52792, 1075422319, "_x_x_x_x_bach_float64_x_x_x_x_", 11348, 3222582404, "_x_x_x_x_bach_float64_x_x_x_x_", 35590, 1075441051, "_x_x_x_x_bach_float64_x_x_x_x_", 40260, 3222562571, "_x_x_x_x_bach_float64_x_x_x_x_", 58803, 1075459549, "_x_x_x_x_bach_float64_x_x_x_x_", 20547, 3222542482, "_x_x_x_x_bach_float64_x_x_x_x_", 53436, 1075477811, "_x_x_x_x_bach_float64_x_x_x_x_", 12166, 3222522139, "_x_x_x_x_bach_float64_x_x_x_x_", 1458, 1075495832, "_x_x_x_x_bach_float64_x_x_x_x_", 26656, 3222501545, "_x_x_x_x_bach_float64_x_x_x_x_", 61864, 1075513609, "_x_x_x_x_bach_float64_x_x_x_x_", 5813, 3222480703, "_x_x_x_x_bach_float64_x_x_x_x_", 23019, 1075531140, "_x_x_x_x_bach_float64_x_x_x_x_", 25500, 3222459614, "_x_x_x_x_bach_float64_x_x_x_x_", 46672, 1075548420, "_x_x_x_x_bach_float64_x_x_x_x_", 4144, 3222438284, "_x_x_x_x_bach_float64_x_x_x_x_", 16452, 1075565446, "_x_x_x_x_bach_float64_x_x_x_x_", 29911, 3222416713, "_x_x_x_x_bach_float64_x_x_x_x_", 45921, 1075582215, "_x_x_x_x_bach_float64_x_x_x_x_", 61966, 3222394906, "_x_x_x_x_bach_float64_x_x_x_x_", 48871, 1075598723, "_x_x_x_x_bach_float64_x_x_x_x_", 54351, 3222372866, "_x_x_x_x_bach_float64_x_x_x_x_", 9598, 1075614968, "_x_x_x_x_bach_float64_x_x_x_x_", 44032, 3222350594, "_x_x_x_x_bach_float64_x_x_x_x_", 35107, 1075630947, "_x_x_x_x_bach_float64_x_x_x_x_", 6942, 3222328096, "_x_x_x_x_bach_float64_x_x_x_x_", 57970, 1075646655, "_x_x_x_x_bach_float64_x_x_x_x_", 6175, 3222305374, "_x_x_x_x_bach_float64_x_x_x_x_", 40939, 1075662090, "_x_x_x_x_bach_float64_x_x_x_x_", 43285, 3222282430, "_x_x_x_x_bach_float64_x_x_x_x_", 27936, 1075677250, "_x_x_x_x_bach_float64_x_x_x_x_", 11041, 3222244491, "_x_x_x_x_bach_float64_x_x_x_x_", 40483, 1075692130, "_x_x_x_x_bach_float64_x_x_x_x_", 9766, 3222197740, "_x_x_x_x_bach_float64_x_x_x_x_", 16115, 1075706728, "_x_x_x_x_bach_float64_x_x_x_x_", 54624, 3222150567, "_x_x_x_x_bach_float64_x_x_x_x_", 50156, 1075721041, "_x_x_x_x_bach_float64_x_x_x_x_", 13783, 3222102980, "_x_x_x_x_bach_float64_x_x_x_x_", 23110, 1075735065, "_x_x_x_x_bach_float64_x_x_x_x_", 60154, 3222054984, "_x_x_x_x_bach_float64_x_x_x_x_", 54863, 1075748799, "_x_x_x_x_bach_float64_x_x_x_x_", 30258, 3222006587, "_x_x_x_x_bach_float64_x_x_x_x_", 15874, 1075762240, "_x_x_x_x_bach_float64_x_x_x_x_", 27498, 3221957796, "_x_x_x_x_bach_float64_x_x_x_x_", 60835, 1075775383, "_x_x_x_x_bach_float64_x_x_x_x_", 42733, 3221908618, "_x_x_x_x_bach_float64_x_x_x_x_", 21906, 1075788228, "_x_x_x_x_bach_float64_x_x_x_x_", 33828, 3221859060, "_x_x_x_x_bach_float64_x_x_x_x_", 20104, 1075800770, "_x_x_x_x_bach_float64_x_x_x_x_", 6926, 3221809130, "_x_x_x_x_bach_float64_x_x_x_x_", 863, 1075813008, "_x_x_x_x_bach_float64_x_x_x_x_", 33822, 3221758834, "_x_x_x_x_bach_float64_x_x_x_x_", 28269, 1075824939, "_x_x_x_x_bach_float64_x_x_x_x_", 9803, 3221708181, "_x_x_x_x_bach_float64_x_x_x_x_", 26733, 1075836560, "_x_x_x_x_bach_float64_x_x_x_x_", 4862, 3221657177, "_x_x_x_x_bach_float64_x_x_x_x_", 41974, 1075843422, "_x_x_x_x_bach_float64_x_x_x_x_", 28741, 3221605831, "_x_x_x_x_bach_float64_x_x_x_x_", 34700, 1075848919, "_x_x_x_x_bach_float64_x_x_x_x_", 62977, 3221554149, "_x_x_x_x_bach_float64_x_x_x_x_", 37705, 1075854257, "_x_x_x_x_bach_float64_x_x_x_x_", 32580, 3221502141, "_x_x_x_x_bach_float64_x_x_x_x_", 53682, 1075859436, "_x_x_x_x_bach_float64_x_x_x_x_", 46308, 3221449813, "_x_x_x_x_bach_float64_x_x_x_x_", 35713, 1075864454, "_x_x_x_x_bach_float64_x_x_x_x_", 53435, 3221397173, "_x_x_x_x_bach_float64_x_x_x_x_", 62319, 1075869309, "_x_x_x_x_bach_float64_x_x_x_x_", 33031, 3221344230, "_x_x_x_x_bach_float64_x_x_x_x_", 38313, 1075874002, "_x_x_x_x_bach_float64_x_x_x_x_", 59682, 3221290991, "_x_x_x_x_bach_float64_x_x_x_x_", 35174, 1075878530, "_x_x_x_x_bach_float64_x_x_x_x_", 51430, 3221237464, "_x_x_x_x_bach_float64_x_x_x_x_", 25743, 1075882892, "_x_x_x_x_bach_float64_x_x_x_x_", 36884, 3221141844, "_x_x_x_x_bach_float64_x_x_x_x_", 61482, 1075887089, "_x_x_x_x_bach_float64_x_x_x_x_", 55836, 3221033689, "_x_x_x_x_bach_float64_x_x_x_x_", 40235, 1075891117, "_x_x_x_x_bach_float64_x_x_x_x_", 32592, 3220925007, "_x_x_x_x_bach_float64_x_x_x_x_", 47307, 1075894978, "_x_x_x_x_bach_float64_x_x_x_x_", 13832, 3220815816, "_x_x_x_x_bach_float64_x_x_x_x_", 24465, 1075898669, "_x_x_x_x_bach_float64_x_x_x_x_", 26839, 3220706132, "_x_x_x_x_bach_float64_x_x_x_x_", 11928, 1075902190, "_x_x_x_x_bach_float64_x_x_x_x_", 44166, 3220595971, "_x_x_x_x_bach_float64_x_x_x_x_", 45585, 1075905539, "_x_x_x_x_bach_float64_x_x_x_x_", 44326, 3220485352, "_x_x_x_x_bach_float64_x_x_x_x_", 37005, 1075908717, "_x_x_x_x_bach_float64_x_x_x_x_", 37387, 3220374291, "_x_x_x_x_bach_float64_x_x_x_x_", 29257, 1075911721, "_x_x_x_x_bach_float64_x_x_x_x_", 58338, 3220262804, "_x_x_x_x_bach_float64_x_x_x_x_", 41929, 1075914552, "_x_x_x_x_bach_float64_x_x_x_x_", 61662, 3220124925, "_x_x_x_x_bach_float64_x_x_x_x_", 29466, 1075917207, "_x_x_x_x_bach_float64_x_x_x_x_", 57011, 3219900356, "_x_x_x_x_bach_float64_x_x_x_x_", 18217, 1075919688, "_x_x_x_x_bach_float64_x_x_x_x_", 32667, 3219675041, "_x_x_x_x_bach_float64_x_x_x_x_", 28775, 1075921992, "_x_x_x_x_bach_float64_x_x_x_x_", 53132, 3219449016, "_x_x_x_x_bach_float64_x_x_x_x_", 45639, 1075924120, "_x_x_x_x_bach_float64_x_x_x_x_", 28427, 3219222315, "_x_x_x_x_bach_float64_x_x_x_x_", 33987, 1075926070, "_x_x_x_x_bach_float64_x_x_x_x_", 14654, 3218861629, "_x_x_x_x_bach_float64_x_x_x_x_", 3455, 1075927842, "_x_x_x_x_bach_float64_x_x_x_x_", 3069, 3218405740, "_x_x_x_x_bach_float64_x_x_x_x_", 53189, 1075929434, "_x_x_x_x_bach_float64_x_x_x_x_", 19857, 3217817683 ],
									"whole_graph_data_count" : [ 2 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "gridystep",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 136.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "gridxstep",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-2",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 115.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-40",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 202.0, 260.0, 260.0 ],
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3222536192, "_x_x_x_x_bach_float64_x_x_x_x_", 46496, 1075880548, "_x_x_x_x_bach_float64_x_x_x_x_", 32604, 3222533567, "_x_x_x_x_bach_float64_x_x_x_x_", 31129, 1075883006, "_x_x_x_x_bach_float64_x_x_x_x_", 65208, 3222530943, "_x_x_x_x_bach_float64_x_x_x_x_", 9685, 1075885421, "_x_x_x_x_bach_float64_x_x_x_x_", 32276, 3222528319, "_x_x_x_x_bach_float64_x_x_x_x_", 2247, 1075887792, "_x_x_x_x_bach_float64_x_x_x_x_", 64880, 3222525695, "_x_x_x_x_bach_float64_x_x_x_x_", 29816, 1075890118, "_x_x_x_x_bach_float64_x_x_x_x_", 31948, 3222523071, "_x_x_x_x_bach_float64_x_x_x_x_", 10963, 1075892399, "_x_x_x_x_bach_float64_x_x_x_x_", 64552, 3222520447, "_x_x_x_x_bach_float64_x_x_x_x_", 49779, 1075894634, "_x_x_x_x_bach_float64_x_x_x_x_", 31620, 3222517823, "_x_x_x_x_bach_float64_x_x_x_x_", 978, 1075896824, "_x_x_x_x_bach_float64_x_x_x_x_", 64224, 3222515199, "_x_x_x_x_bach_float64_x_x_x_x_", 16084, 1075898968, "_x_x_x_x_bach_float64_x_x_x_x_", 31292, 3222512575, "_x_x_x_x_bach_float64_x_x_x_x_", 39073, 1075901065, "_x_x_x_x_bach_float64_x_x_x_x_", 63896, 3222509951, "_x_x_x_x_bach_float64_x_x_x_x_", 20916, 1075903115, "_x_x_x_x_bach_float64_x_x_x_x_", 30964, 3222507327, "_x_x_x_x_bach_float64_x_x_x_x_", 1053, 1075905118, "_x_x_x_x_bach_float64_x_x_x_x_", 63568, 3222504703, "_x_x_x_x_bach_float64_x_x_x_x_", 55768, 1075907074, "_x_x_x_x_bach_float64_x_x_x_x_", 30636, 3222502079, "_x_x_x_x_bach_float64_x_x_x_x_", 47932, 1075908982, "_x_x_x_x_bach_float64_x_x_x_x_", 63240, 3222499455, "_x_x_x_x_bach_float64_x_x_x_x_", 30056, 1075910841, "_x_x_x_x_bach_float64_x_x_x_x_", 30308, 3222496831, "_x_x_x_x_bach_float64_x_x_x_x_", 55455, 1075912653, "_x_x_x_x_bach_float64_x_x_x_x_", 62912, 3222494206, "_x_x_x_x_bach_float64_x_x_x_x_", 52876, 1075914415, "_x_x_x_x_bach_float64_x_x_x_x_", 29980, 3222491582, "_x_x_x_x_bach_float64_x_x_x_x_", 26723, 1075916129, "_x_x_x_x_bach_float64_x_x_x_x_", 62584, 3222488958, "_x_x_x_x_bach_float64_x_x_x_x_", 58555, 1075917793, "_x_x_x_x_bach_float64_x_x_x_x_", 29652, 3222486334, "_x_x_x_x_bach_float64_x_x_x_x_", 44345, 1075919408, "_x_x_x_x_bach_float64_x_x_x_x_", 62256, 3222483710, "_x_x_x_x_bach_float64_x_x_x_x_", 19420, 1075920972, "_x_x_x_x_bach_float64_x_x_x_x_", 29324, 3222481086, "_x_x_x_x_bach_float64_x_x_x_x_", 22512, 1075922486, "_x_x_x_x_bach_float64_x_x_x_x_", 61928, 3222478462, "_x_x_x_x_bach_float64_x_x_x_x_", 23188, 1075923950, "_x_x_x_x_bach_float64_x_x_x_x_", 28996, 3222475838, "_x_x_x_x_bach_float64_x_x_x_x_", 43732, 1075925363, "_x_x_x_x_bach_float64_x_x_x_x_", 61600, 3222473214, "_x_x_x_x_bach_float64_x_x_x_x_", 16685, 1075926725, "_x_x_x_x_bach_float64_x_x_x_x_", 28668, 3222470590, "_x_x_x_x_bach_float64_x_x_x_x_", 33430, 1075928035, "_x_x_x_x_bach_float64_x_x_x_x_", 61272, 3222467966, "_x_x_x_x_bach_float64_x_x_x_x_", 740, 1075929294, "_x_x_x_x_bach_float64_x_x_x_x_", 28340, 3222465342, "_x_x_x_x_bach_float64_x_x_x_x_", 16003, 1075930501, "_x_x_x_x_bach_float64_x_x_x_x_", 60944, 3222462718, "_x_x_x_x_bach_float64_x_x_x_x_", 19342, 1075931656, "_x_x_x_x_bach_float64_x_x_x_x_", 28012, 3222460094, "_x_x_x_x_bach_float64_x_x_x_x_", 33303, 1075932759, "_x_x_x_x_bach_float64_x_x_x_x_", 60616, 3222457470, "_x_x_x_x_bach_float64_x_x_x_x_", 7097, 1075933809, "_x_x_x_x_bach_float64_x_x_x_x_", 27684, 3222454846, "_x_x_x_x_bach_float64_x_x_x_x_", 51785, 1075934806, "_x_x_x_x_bach_float64_x_x_x_x_", 60288, 3222452221, "_x_x_x_x_bach_float64_x_x_x_x_", 17844, 1075935750, "_x_x_x_x_bach_float64_x_x_x_x_", 27356, 3222449597, "_x_x_x_x_bach_float64_x_x_x_x_", 53493, 1075936641, "_x_x_x_x_bach_float64_x_x_x_x_", 59960, 3222446973, "_x_x_x_x_bach_float64_x_x_x_x_", 46612, 1075937478, "_x_x_x_x_bach_float64_x_x_x_x_", 27028, 3222444349, "_x_x_x_x_bach_float64_x_x_x_x_", 47411, 1075938261, "_x_x_x_x_bach_float64_x_x_x_x_", 59632, 3222441725, "_x_x_x_x_bach_float64_x_x_x_x_", 33426, 1075938991, "_x_x_x_x_bach_float64_x_x_x_x_", 26700, 3222439101, "_x_x_x_x_bach_float64_x_x_x_x_", 65414, 1075939666, "_x_x_x_x_bach_float64_x_x_x_x_", 59304, 3222436477, "_x_x_x_x_bach_float64_x_x_x_x_", 47704, 1075940287, "_x_x_x_x_bach_float64_x_x_x_x_", 26372, 3222433853, "_x_x_x_x_bach_float64_x_x_x_x_", 10511, 1075940854, "_x_x_x_x_bach_float64_x_x_x_x_", 58976, 3222431229, "_x_x_x_x_bach_float64_x_x_x_x_", 62208, 1075941365, "_x_x_x_x_bach_float64_x_x_x_x_", 26044, 3222428605, "_x_x_x_x_bach_float64_x_x_x_x_", 11584, 1075941822, "_x_x_x_x_bach_float64_x_x_x_x_", 58648, 3222425981, "_x_x_x_x_bach_float64_x_x_x_x_", 36305, 1075942224, "_x_x_x_x_bach_float64_x_x_x_x_", 25716, 3222423357, "_x_x_x_x_bach_float64_x_x_x_x_", 38296, 1075942570, "_x_x_x_x_bach_float64_x_x_x_x_", 58320, 3222420733, "_x_x_x_x_bach_float64_x_x_x_x_", 45315, 1075942861, "_x_x_x_x_bach_float64_x_x_x_x_", 25388, 3222418109, "_x_x_x_x_bach_float64_x_x_x_x_", 20326, 1075943097, "_x_x_x_x_bach_float64_x_x_x_x_", 57992, 3222415485, "_x_x_x_x_bach_float64_x_x_x_x_", 61698, 1075943276, "_x_x_x_x_bach_float64_x_x_x_x_", 25060, 3222412860, "_x_x_x_x_bach_float64_x_x_x_x_", 11172, 1075943400, "_x_x_x_x_bach_float64_x_x_x_x_", 57664, 3222410236, "_x_x_x_x_bach_float64_x_x_x_x_", 42482, 1075943468, "_x_x_x_x_bach_float64_x_x_x_x_", 24732, 3222407612, "_x_x_x_x_bach_float64_x_x_x_x_", 2368, 1075943479, "_x_x_x_x_bach_float64_x_x_x_x_", 57336, 3222404988, "_x_x_x_x_bach_float64_x_x_x_x_", 59892, 1075943434, "_x_x_x_x_bach_float64_x_x_x_x_", 24404, 3222402364, "_x_x_x_x_bach_float64_x_x_x_x_", 42622, 1075943333, "_x_x_x_x_bach_float64_x_x_x_x_", 57008, 3222399740, "_x_x_x_x_bach_float64_x_x_x_x_", 15564, 1075943175, "_x_x_x_x_bach_float64_x_x_x_x_", 24076, 3222397116, "_x_x_x_x_bach_float64_x_x_x_x_", 5691, 1075942961, "_x_x_x_x_bach_float64_x_x_x_x_", 56680, 3222394492, "_x_x_x_x_bach_float64_x_x_x_x_", 51718, 1075942690, "_x_x_x_x_bach_float64_x_x_x_x_", 23748, 3222391868, "_x_x_x_x_bach_float64_x_x_x_x_", 54821, 1075942362, "_x_x_x_x_bach_float64_x_x_x_x_", 56352, 3222389244, "_x_x_x_x_bach_float64_x_x_x_x_", 20128, 1075941976, "_x_x_x_x_bach_float64_x_x_x_x_", 23420, 3222386620, "_x_x_x_x_bach_float64_x_x_x_x_", 33606, 1075941534, "_x_x_x_x_bach_float64_x_x_x_x_", 56024, 3222383996, "_x_x_x_x_bach_float64_x_x_x_x_", 39888, 1075941035, "_x_x_x_x_bach_float64_x_x_x_x_", 23092, 3222381372, "_x_x_x_x_bach_float64_x_x_x_x_", 10854, 1075940478, "_x_x_x_x_bach_float64_x_x_x_x_", 55696, 3222378748, "_x_x_x_x_bach_float64_x_x_x_x_", 46207, 1075939864, "_x_x_x_x_bach_float64_x_x_x_x_", 22764, 3222376124, "_x_x_x_x_bach_float64_x_x_x_x_", 12835, 1075939193, "_x_x_x_x_bach_float64_x_x_x_x_", 55368, 3222373500, "_x_x_x_x_bach_float64_x_x_x_x_", 33658, 1075938464, "_x_x_x_x_bach_float64_x_x_x_x_", 22436, 3222370875, "_x_x_x_x_bach_float64_x_x_x_x_", 56511, 1075937678, "_x_x_x_x_bach_float64_x_x_x_x_", 55040, 3222368251, "_x_x_x_x_bach_float64_x_x_x_x_", 10358, 1075936834, "_x_x_x_x_bach_float64_x_x_x_x_", 22108, 3222365627, "_x_x_x_x_bach_float64_x_x_x_x_", 24572, 1075935932, "_x_x_x_x_bach_float64_x_x_x_x_", 54712, 3222363003, "_x_x_x_x_bach_float64_x_x_x_x_", 55907, 1075934973, "_x_x_x_x_bach_float64_x_x_x_x_", 21780, 3222360379, "_x_x_x_x_bach_float64_x_x_x_x_", 37266, 1075933956, "_x_x_x_x_bach_float64_x_x_x_x_", 54384, 3222357755, "_x_x_x_x_bach_float64_x_x_x_x_", 23994, 1075932882, "_x_x_x_x_bach_float64_x_x_x_x_", 21452, 3222355131, "_x_x_x_x_bach_float64_x_x_x_x_", 9992, 1075931749, "_x_x_x_x_bach_float64_x_x_x_x_", 54056, 3222352507, "_x_x_x_x_bach_float64_x_x_x_x_", 3498, 1075930559, "_x_x_x_x_bach_float64_x_x_x_x_", 21124, 3222349883, "_x_x_x_x_bach_float64_x_x_x_x_", 34826, 1075929311, "_x_x_x_x_bach_float64_x_x_x_x_", 53728, 3222347259, "_x_x_x_x_bach_float64_x_x_x_x_", 30556, 1075928006, "_x_x_x_x_bach_float64_x_x_x_x_", 20796, 3222344635, "_x_x_x_x_bach_float64_x_x_x_x_", 12910, 1075926642, "_x_x_x_x_bach_float64_x_x_x_x_", 53400, 3222342011, "_x_x_x_x_bach_float64_x_x_x_x_", 34484, 1075925221, "_x_x_x_x_bach_float64_x_x_x_x_", 20468, 3222339387, "_x_x_x_x_bach_float64_x_x_x_x_", 44958, 1075923742, "_x_x_x_x_bach_float64_x_x_x_x_", 53072, 3222336763, "_x_x_x_x_bach_float64_x_x_x_x_", 17466, 1075922205, "_x_x_x_x_bach_float64_x_x_x_x_", 20140, 3222334139, "_x_x_x_x_bach_float64_x_x_x_x_", 6918, 1075920611, "_x_x_x_x_bach_float64_x_x_x_x_", 52744, 3222331515, "_x_x_x_x_bach_float64_x_x_x_x_", 9250, 1075918958, "_x_x_x_x_bach_float64_x_x_x_x_", 19812, 3222328890, "_x_x_x_x_bach_float64_x_x_x_x_", 14772, 1075917248, "_x_x_x_x_bach_float64_x_x_x_x_", 52416, 3222326266, "_x_x_x_x_bach_float64_x_x_x_x_", 59032, 1075915481, "_x_x_x_x_bach_float64_x_x_x_x_", 19484, 3222323642, "_x_x_x_x_bach_float64_x_x_x_x_", 9063, 1075913656, "_x_x_x_x_bach_float64_x_x_x_x_", 52088, 3222321018, "_x_x_x_x_bach_float64_x_x_x_x_", 2482, 1075911773, "_x_x_x_x_bach_float64_x_x_x_x_", 19156, 3222318394, "_x_x_x_x_bach_float64_x_x_x_x_", 32160, 1075909833, "_x_x_x_x_bach_float64_x_x_x_x_", 51760, 3222315770, "_x_x_x_x_bach_float64_x_x_x_x_", 52682, 1075907836, "_x_x_x_x_bach_float64_x_x_x_x_", 18828, 3222313146, "_x_x_x_x_bach_float64_x_x_x_x_", 18806, 1075905781, "_x_x_x_x_bach_float64_x_x_x_x_", 51432, 3222310522, "_x_x_x_x_bach_float64_x_x_x_x_", 52511, 1075903669, "_x_x_x_x_bach_float64_x_x_x_x_", 18500, 3222307898, "_x_x_x_x_bach_float64_x_x_x_x_", 17744, 1075901499, "_x_x_x_x_bach_float64_x_x_x_x_", 51104, 3222305274, "_x_x_x_x_bach_float64_x_x_x_x_", 10215, 1075899273, "_x_x_x_x_bach_float64_x_x_x_x_", 18172, 3222302650, "_x_x_x_x_bach_float64_x_x_x_x_", 58282, 1075896990, "_x_x_x_x_bach_float64_x_x_x_x_", 50776, 3222300026, "_x_x_x_x_bach_float64_x_x_x_x_", 17988, 1075894649, "_x_x_x_x_bach_float64_x_x_x_x_", 17844, 3222297402, "_x_x_x_x_bach_float64_x_x_x_x_", 55458, 1075892252, "_x_x_x_x_bach_float64_x_x_x_x_", 50448, 3222294778, "_x_x_x_x_bach_float64_x_x_x_x_", 12736, 1075889798, "_x_x_x_x_bach_float64_x_x_x_x_", 17516, 3222292154, "_x_x_x_x_bach_float64_x_x_x_x_", 16355, 1075887288, "_x_x_x_x_bach_float64_x_x_x_x_", 50120, 3222289529, "_x_x_x_x_bach_float64_x_x_x_x_", 34880, 1075884721, "_x_x_x_x_bach_float64_x_x_x_x_", 17188, 3222286905, "_x_x_x_x_bach_float64_x_x_x_x_", 23846, 1075882098, "_x_x_x_x_bach_float64_x_x_x_x_", 49792, 3222284281, "_x_x_x_x_bach_float64_x_x_x_x_", 2708, 1075879418, "_x_x_x_x_bach_float64_x_x_x_x_", 16860, 3222281657, "_x_x_x_x_bach_float64_x_x_x_x_", 63850, 1075876683, "_x_x_x_x_bach_float64_x_x_x_x_", 49464, 3222279033, "_x_x_x_x_bach_float64_x_x_x_x_", 51466, 1075873891, "_x_x_x_x_bach_float64_x_x_x_x_", 16532, 3222276409, "_x_x_x_x_bach_float64_x_x_x_x_", 24464, 1075871044, "_x_x_x_x_bach_float64_x_x_x_x_", 32735, 3222273523, "_x_x_x_x_bach_float64_x_x_x_x_", 61610, 1075868141, "_x_x_x_x_bach_float64_x_x_x_x_", 32407, 3222268275, "_x_x_x_x_bach_float64_x_x_x_x_", 64246, 1075865183, "_x_x_x_x_bach_float64_x_x_x_x_", 32079, 3222263026, "_x_x_x_x_bach_float64_x_x_x_x_", 15375, 1075862169, "_x_x_x_x_bach_float64_x_x_x_x_", 31752, 3222257778, "_x_x_x_x_bach_float64_x_x_x_x_", 39742, 1075859100, "_x_x_x_x_bach_float64_x_x_x_x_", 31423, 3222252530, "_x_x_x_x_bach_float64_x_x_x_x_", 2781, 1075855977, "_x_x_x_x_bach_float64_x_x_x_x_", 31095, 3222247282, "_x_x_x_x_bach_float64_x_x_x_x_", 24681, 1075852798, "_x_x_x_x_bach_float64_x_x_x_x_", 30767, 3222242034, "_x_x_x_x_bach_float64_x_x_x_x_", 9052, 1075849565, "_x_x_x_x_bach_float64_x_x_x_x_", 30439, 3222236786, "_x_x_x_x_bach_float64_x_x_x_x_", 21192, 1075846277, "_x_x_x_x_bach_float64_x_x_x_x_", 30111, 3222231538, "_x_x_x_x_bach_float64_x_x_x_x_", 8637, 1075842936, "_x_x_x_x_bach_float64_x_x_x_x_", 29783, 3222226290, "_x_x_x_x_bach_float64_x_x_x_x_", 43661, 1075839540, "_x_x_x_x_bach_float64_x_x_x_x_", 29455, 3222221041, "_x_x_x_x_bach_float64_x_x_x_x_", 12752, 1075833206, "_x_x_x_x_bach_float64_x_x_x_x_", 29127, 3222215793, "_x_x_x_x_bach_float64_x_x_x_x_", 38344, 1075826200, "_x_x_x_x_bach_float64_x_x_x_x_", 28799, 3222210545, "_x_x_x_x_bach_float64_x_x_x_x_", 53732, 1075819087, "_x_x_x_x_bach_float64_x_x_x_x_", 28471, 3222205297, "_x_x_x_x_bach_float64_x_x_x_x_", 59810, 1075811868, "_x_x_x_x_bach_float64_x_x_x_x_", 28143, 3222200049, "_x_x_x_x_bach_float64_x_x_x_x_", 40708, 1075804543, "_x_x_x_x_bach_float64_x_x_x_x_", 27815, 3222194801, "_x_x_x_x_bach_float64_x_x_x_x_", 27794, 1075797113, "_x_x_x_x_bach_float64_x_x_x_x_", 27487, 3222189553, "_x_x_x_x_bach_float64_x_x_x_x_", 28042, 1075789578, "_x_x_x_x_bach_float64_x_x_x_x_", 27159, 3222184305, "_x_x_x_x_bach_float64_x_x_x_x_", 13395, 1075781938, "_x_x_x_x_bach_float64_x_x_x_x_", 26831, 3222179056, "_x_x_x_x_bach_float64_x_x_x_x_", 36684, 1075774195, "_x_x_x_x_bach_float64_x_x_x_x_", 26503, 3222173808, "_x_x_x_x_bach_float64_x_x_x_x_", 15354, 1075766349, "_x_x_x_x_bach_float64_x_x_x_x_", 26175, 3222168560, "_x_x_x_x_bach_float64_x_x_x_x_", 35016, 1075758399, "_x_x_x_x_bach_float64_x_x_x_x_", 25847, 3222163312, "_x_x_x_x_bach_float64_x_x_x_x_", 58710, 1075750348, "_x_x_x_x_bach_float64_x_x_x_x_", 25519, 3222158064, "_x_x_x_x_bach_float64_x_x_x_x_", 24948, 1075742194, "_x_x_x_x_bach_float64_x_x_x_x_", 25191, 3222152816, "_x_x_x_x_bach_float64_x_x_x_x_", 6892, 1075733940, "_x_x_x_x_bach_float64_x_x_x_x_", 24863, 3222147568, "_x_x_x_x_bach_float64_x_x_x_x_", 39454, 1075725585, "_x_x_x_x_bach_float64_x_x_x_x_", 24535, 3222142319, "_x_x_x_x_bach_float64_x_x_x_x_", 7584, 1075717129, "_x_x_x_x_bach_float64_x_x_x_x_", 24207, 3222137071, "_x_x_x_x_bach_float64_x_x_x_x_", 54489, 1075708575, "_x_x_x_x_bach_float64_x_x_x_x_", 23879, 3222131823, "_x_x_x_x_bach_float64_x_x_x_x_", 2512, 1075699921, "_x_x_x_x_bach_float64_x_x_x_x_", 23551, 3222126575, "_x_x_x_x_bach_float64_x_x_x_x_", 14902, 1075691169, "_x_x_x_x_bach_float64_x_x_x_x_", 23223, 3222121327, "_x_x_x_x_bach_float64_x_x_x_x_", 8134, 1075682320, "_x_x_x_x_bach_float64_x_x_x_x_", 22895, 3222116079, "_x_x_x_x_bach_float64_x_x_x_x_", 43036, 1075673374, "_x_x_x_x_bach_float64_x_x_x_x_", 22567, 3222110831, "_x_x_x_x_bach_float64_x_x_x_x_", 56346, 1075664331, "_x_x_x_x_bach_float64_x_x_x_x_", 22239, 3222105583, "_x_x_x_x_bach_float64_x_x_x_x_", 46830, 1075655192, "_x_x_x_x_bach_float64_x_x_x_x_", 21911, 3222100334, "_x_x_x_x_bach_float64_x_x_x_x_", 60645, 1075645958, "_x_x_x_x_bach_float64_x_x_x_x_", 21583, 3222095086, "_x_x_x_x_bach_float64_x_x_x_x_", 41498, 1075636630, "_x_x_x_x_bach_float64_x_x_x_x_", 21255, 3222089838, "_x_x_x_x_bach_float64_x_x_x_x_", 4378, 1075627209, "_x_x_x_x_bach_float64_x_x_x_x_", 20926, 3222084590, "_x_x_x_x_bach_float64_x_x_x_x_", 8620, 1075617694, "_x_x_x_x_bach_float64_x_x_x_x_", 20599, 3222079342, "_x_x_x_x_bach_float64_x_x_x_x_", 61388, 1075608086, "_x_x_x_x_bach_float64_x_x_x_x_", 20271, 3222074094, "_x_x_x_x_bach_float64_x_x_x_x_", 17122, 1075598387, "_x_x_x_x_bach_float64_x_x_x_x_", 19943, 3222068846, "_x_x_x_x_bach_float64_x_x_x_x_", 62866, 1075588597, "_x_x_x_x_bach_float64_x_x_x_x_", 19615, 3222063598, "_x_x_x_x_bach_float64_x_x_x_x_", 19955, 1075578717, "_x_x_x_x_bach_float64_x_x_x_x_", 19286, 3222058349, "_x_x_x_x_bach_float64_x_x_x_x_", 18060, 1075568747, "_x_x_x_x_bach_float64_x_x_x_x_", 18959, 3222053101, "_x_x_x_x_bach_float64_x_x_x_x_", 51231, 1075558689, "_x_x_x_x_bach_float64_x_x_x_x_", 18631, 3222047853, "_x_x_x_x_bach_float64_x_x_x_x_", 54326, 1075548542, "_x_x_x_x_bach_float64_x_x_x_x_", 18303, 3222042605, "_x_x_x_x_bach_float64_x_x_x_x_", 41208, 1075538308, "_x_x_x_x_bach_float64_x_x_x_x_", 17975, 3222037357, "_x_x_x_x_bach_float64_x_x_x_x_", 42497, 1075527988, "_x_x_x_x_bach_float64_x_x_x_x_", 17646, 3222032109, "_x_x_x_x_bach_float64_x_x_x_x_", 39563, 1075517581, "_x_x_x_x_bach_float64_x_x_x_x_", 17319, 3222026861, "_x_x_x_x_bach_float64_x_x_x_x_", 25882, 1075507090, "_x_x_x_x_bach_float64_x_x_x_x_", 16991, 3222021613, "_x_x_x_x_bach_float64_x_x_x_x_", 64640, 1075496515, "_x_x_x_x_bach_float64_x_x_x_x_", 16663, 3222016364, "_x_x_x_x_bach_float64_x_x_x_x_", 15068, 1075485856, "_x_x_x_x_bach_float64_x_x_x_x_", 16335, 3222011116, "_x_x_x_x_bach_float64_x_x_x_x_", 41518, 1075475115, "_x_x_x_x_bach_float64_x_x_x_x_", 16006, 3222005868, "_x_x_x_x_bach_float64_x_x_x_x_", 4848, 1075464291, "_x_x_x_x_bach_float64_x_x_x_x_", 15678, 3222000620, "_x_x_x_x_bach_float64_x_x_x_x_", 29920, 1075453387, "_x_x_x_x_bach_float64_x_x_x_x_", 15351, 3221995372, "_x_x_x_x_bach_float64_x_x_x_x_", 20947, 1075442403, "_x_x_x_x_bach_float64_x_x_x_x_", 15023, 3221990124, "_x_x_x_x_bach_float64_x_x_x_x_", 25344, 1075431339, "_x_x_x_x_bach_float64_x_x_x_x_", 14695, 3221984876, "_x_x_x_x_bach_float64_x_x_x_x_", 4320, 1075420197, "_x_x_x_x_bach_float64_x_x_x_x_", 14366, 3221979628, "_x_x_x_x_bach_float64_x_x_x_x_", 58754, 1075408978, "_x_x_x_x_bach_float64_x_x_x_x_", 14038, 3221974379, "_x_x_x_x_bach_float64_x_x_x_x_", 61922, 1075397681, "_x_x_x_x_bach_float64_x_x_x_x_", 13711, 3221969131, "_x_x_x_x_bach_float64_x_x_x_x_", 9714, 1075386309, "_x_x_x_x_bach_float64_x_x_x_x_", 13383, 3221963883, "_x_x_x_x_bach_float64_x_x_x_x_", 39897, 1075374862, "_x_x_x_x_bach_float64_x_x_x_x_", 13055, 3221958635, "_x_x_x_x_bach_float64_x_x_x_x_", 54902, 1075363341, "_x_x_x_x_bach_float64_x_x_x_x_", 12726, 3221953387, "_x_x_x_x_bach_float64_x_x_x_x_", 62239, 1075351746, "_x_x_x_x_bach_float64_x_x_x_x_", 12398, 3221948139, "_x_x_x_x_bach_float64_x_x_x_x_", 53002, 1075340080, "_x_x_x_x_bach_float64_x_x_x_x_", 12071, 3221942891, "_x_x_x_x_bach_float64_x_x_x_x_", 8248, 1075328341, "_x_x_x_x_bach_float64_x_x_x_x_", 11743, 3221937642, "_x_x_x_x_bach_float64_x_x_x_x_", 33354, 1075316533, "_x_x_x_x_bach_float64_x_x_x_x_", 11415, 3221932394, "_x_x_x_x_bach_float64_x_x_x_x_", 30557, 1075304654, "_x_x_x_x_bach_float64_x_x_x_x_", 11086, 3221927146, "_x_x_x_x_bach_float64_x_x_x_x_", 23781, 1075292707, "_x_x_x_x_bach_float64_x_x_x_x_", 10758, 3221921898, "_x_x_x_x_bach_float64_x_x_x_x_", 21746, 1075280693, "_x_x_x_x_bach_float64_x_x_x_x_", 10430, 3221916650, "_x_x_x_x_bach_float64_x_x_x_x_", 9148, 1075268611, "_x_x_x_x_bach_float64_x_x_x_x_", 10103, 3221911402, "_x_x_x_x_bach_float64_x_x_x_x_", 499, 1075256464, "_x_x_x_x_bach_float64_x_x_x_x_", 9775, 3221906154, "_x_x_x_x_bach_float64_x_x_x_x_", 25512, 1075244252, "_x_x_x_x_bach_float64_x_x_x_x_", 9446, 3221900906, "_x_x_x_x_bach_float64_x_x_x_x_", 46152, 1075231976, "_x_x_x_x_bach_float64_x_x_x_x_", 9118, 3221895657, "_x_x_x_x_bach_float64_x_x_x_x_", 1936, 1075219637, "_x_x_x_x_bach_float64_x_x_x_x_", 8790, 3221890409, "_x_x_x_x_bach_float64_x_x_x_x_", 49076, 1075207236, "_x_x_x_x_bach_float64_x_x_x_x_", 8463, 3221885161, "_x_x_x_x_bach_float64_x_x_x_x_", 10510, 1075194774, "_x_x_x_x_bach_float64_x_x_x_x_", 8135, 3221879913, "_x_x_x_x_bach_float64_x_x_x_x_", 2864, 1075182252, "_x_x_x_x_bach_float64_x_x_x_x_", 7806, 3221874665, "_x_x_x_x_bach_float64_x_x_x_x_", 12259, 1075169672, "_x_x_x_x_bach_float64_x_x_x_x_", 7478, 3221869417, "_x_x_x_x_bach_float64_x_x_x_x_", 57324, 1075157033, "_x_x_x_x_bach_float64_x_x_x_x_", 7150, 3221864169, "_x_x_x_x_bach_float64_x_x_x_x_", 21976, 1075144337, "_x_x_x_x_bach_float64_x_x_x_x_", 6823, 3221858921, "_x_x_x_x_bach_float64_x_x_x_x_", 10011, 1075131585, "_x_x_x_x_bach_float64_x_x_x_x_", 6495, 3221853672, "_x_x_x_x_bach_float64_x_x_x_x_", 41852, 1075118778, "_x_x_x_x_bach_float64_x_x_x_x_", 6166, 3221848424, "_x_x_x_x_bach_float64_x_x_x_x_", 11062, 1075105917, "_x_x_x_x_bach_float64_x_x_x_x_", 5838, 3221843176, "_x_x_x_x_bach_float64_x_x_x_x_", 31670, 1075093003, "_x_x_x_x_bach_float64_x_x_x_x_", 5510, 3221837928, "_x_x_x_x_bach_float64_x_x_x_x_", 62276, 1075080038, "_x_x_x_x_bach_float64_x_x_x_x_", 5182, 3221832680, "_x_x_x_x_bach_float64_x_x_x_x_", 52175, 1075067021, "_x_x_x_x_bach_float64_x_x_x_x_", 4855, 3221827432, "_x_x_x_x_bach_float64_x_x_x_x_", 19707, 1075053955, "_x_x_x_x_bach_float64_x_x_x_x_", 4526, 3221822184, "_x_x_x_x_bach_float64_x_x_x_x_", 62846, 1075040839, "_x_x_x_x_bach_float64_x_x_x_x_", 4198, 3221816936, "_x_x_x_x_bach_float64_x_x_x_x_", 40035, 1075027676, "_x_x_x_x_bach_float64_x_x_x_x_", 3870, 3221811687, "_x_x_x_x_bach_float64_x_x_x_x_", 35247, 1075014467, "_x_x_x_x_bach_float64_x_x_x_x_", 3542, 3221806439, "_x_x_x_x_bach_float64_x_x_x_x_", 34639, 1075001212, "_x_x_x_x_bach_float64_x_x_x_x_", 3215, 3221801191, "_x_x_x_x_bach_float64_x_x_x_x_", 59911, 1074987912, "_x_x_x_x_bach_float64_x_x_x_x_", 2886, 3221795943, "_x_x_x_x_bach_float64_x_x_x_x_", 37533, 1074974569, "_x_x_x_x_bach_float64_x_x_x_x_", 2558, 3221790695, "_x_x_x_x_bach_float64_x_x_x_x_", 59344, 1074961183, "_x_x_x_x_bach_float64_x_x_x_x_", 2230, 3221785447, "_x_x_x_x_bach_float64_x_x_x_x_", 51348, 1074947756, "_x_x_x_x_bach_float64_x_x_x_x_", 1902, 3221780199, "_x_x_x_x_bach_float64_x_x_x_x_", 30583, 1074934289, "_x_x_x_x_bach_float64_x_x_x_x_", 1575, 3221774951, "_x_x_x_x_bach_float64_x_x_x_x_", 32502, 1074920782, "_x_x_x_x_bach_float64_x_x_x_x_", 1246, 3221769702, "_x_x_x_x_bach_float64_x_x_x_x_", 36594, 1074907238, "_x_x_x_x_bach_float64_x_x_x_x_", 918, 3221764454, "_x_x_x_x_bach_float64_x_x_x_x_", 21461, 1074893656, "_x_x_x_x_bach_float64_x_x_x_x_", 590, 3221759206, "_x_x_x_x_bach_float64_x_x_x_x_", 18162, 1074880039, "_x_x_x_x_bach_float64_x_x_x_x_", 262, 3221753958, "_x_x_x_x_bach_float64_x_x_x_x_", 30948, 1074866387, "_x_x_x_x_bach_float64_x_x_x_x_", 65470, 3221748710, "_x_x_x_x_bach_float64_x_x_x_x_", 21980, 1074852701, "_x_x_x_x_bach_float64_x_x_x_x_", 65143, 3221743462, "_x_x_x_x_bach_float64_x_x_x_x_", 25604, 1074838983, "_x_x_x_x_bach_float64_x_x_x_x_", 64814, 3221738214, "_x_x_x_x_bach_float64_x_x_x_x_", 64562, 1074825233, "_x_x_x_x_bach_float64_x_x_x_x_", 64486, 3221732965, "_x_x_x_x_bach_float64_x_x_x_x_", 64845, 1074811453, "_x_x_x_x_bach_float64_x_x_x_x_", 64158, 3221727717, "_x_x_x_x_bach_float64_x_x_x_x_", 31263, 1074797644, "_x_x_x_x_bach_float64_x_x_x_x_", 63830, 3221722469, "_x_x_x_x_bach_float64_x_x_x_x_", 50308, 1074777213, "_x_x_x_x_bach_float64_x_x_x_x_", 63503, 3221717221, "_x_x_x_x_bach_float64_x_x_x_x_", 19486, 1074749484, "_x_x_x_x_bach_float64_x_x_x_x_", 63174, 3221711973, "_x_x_x_x_bach_float64_x_x_x_x_", 43886, 1074721704, "_x_x_x_x_bach_float64_x_x_x_x_", 62846, 3221706725, "_x_x_x_x_bach_float64_x_x_x_x_", 30783, 1074693874, "_x_x_x_x_bach_float64_x_x_x_x_", 62518, 3221701477, "_x_x_x_x_bach_float64_x_x_x_x_", 59892, 1074665997, "_x_x_x_x_bach_float64_x_x_x_x_", 62190, 3221696229, "_x_x_x_x_bach_float64_x_x_x_x_", 65030, 1074638075, "_x_x_x_x_bach_float64_x_x_x_x_", 61862, 3221690980, "_x_x_x_x_bach_float64_x_x_x_x_", 37966, 1074610110, "_x_x_x_x_bach_float64_x_x_x_x_", 61534, 3221685732, "_x_x_x_x_bach_float64_x_x_x_x_", 33730, 1074582105, "_x_x_x_x_bach_float64_x_x_x_x_", 61206, 3221680484, "_x_x_x_x_bach_float64_x_x_x_x_", 43031, 1074554062, "_x_x_x_x_bach_float64_x_x_x_x_", 60878, 3221675236, "_x_x_x_x_bach_float64_x_x_x_x_", 59516, 1074525983, "_x_x_x_x_bach_float64_x_x_x_x_", 60550, 3221669988, "_x_x_x_x_bach_float64_x_x_x_x_", 14341, 1074497871, "_x_x_x_x_bach_float64_x_x_x_x_", 60222, 3221664740, "_x_x_x_x_bach_float64_x_x_x_x_", 36859, 1074469727, "_x_x_x_x_bach_float64_x_x_x_x_", 59894, 3221659492, "_x_x_x_x_bach_float64_x_x_x_x_", 58515, 1074441555, "_x_x_x_x_bach_float64_x_x_x_x_", 59566, 3221654244, "_x_x_x_x_bach_float64_x_x_x_x_", 5213, 1074413356, "_x_x_x_x_bach_float64_x_x_x_x_", 59238, 3221648995, "_x_x_x_x_bach_float64_x_x_x_x_", 53975, 1074385132, "_x_x_x_x_bach_float64_x_x_x_x_", 58910, 3221643747, "_x_x_x_x_bach_float64_x_x_x_x_", 36481, 1074356887, "_x_x_x_x_bach_float64_x_x_x_x_", 58582, 3221638499, "_x_x_x_x_bach_float64_x_x_x_x_", 21211, 1074328621, "_x_x_x_x_bach_float64_x_x_x_x_", 58254, 3221633251, "_x_x_x_x_bach_float64_x_x_x_x_", 42669, 1074300339, "_x_x_x_x_bach_float64_x_x_x_x_", 57926, 3221628003, "_x_x_x_x_bach_float64_x_x_x_x_", 26363, 1074272041, "_x_x_x_x_bach_float64_x_x_x_x_", 57598, 3221622755, "_x_x_x_x_bach_float64_x_x_x_x_", 40712, 1074243731, "_x_x_x_x_bach_float64_x_x_x_x_", 57270, 3221617507, "_x_x_x_x_bach_float64_x_x_x_x_", 24022, 1074215410, "_x_x_x_x_bach_float64_x_x_x_x_", 56942, 3221612259, "_x_x_x_x_bach_float64_x_x_x_x_", 35192, 1074187080, "_x_x_x_x_bach_float64_x_x_x_x_", 56614, 3221607010, "_x_x_x_x_bach_float64_x_x_x_x_", 45213, 1074158745, "_x_x_x_x_bach_float64_x_x_x_x_", 56286, 3221601762, "_x_x_x_x_bach_float64_x_x_x_x_", 56004, 1074130407, "_x_x_x_x_bach_float64_x_x_x_x_", 55958, 3221596514, "_x_x_x_x_bach_float64_x_x_x_x_", 22378, 1074102067, "_x_x_x_x_bach_float64_x_x_x_x_", 55630, 3221591266, "_x_x_x_x_bach_float64_x_x_x_x_", 36005, 1074073728, "_x_x_x_x_bach_float64_x_x_x_x_", 55302, 3221586018, "_x_x_x_x_bach_float64_x_x_x_x_", 50569, 1074045393, "_x_x_x_x_bach_float64_x_x_x_x_", 54974, 3221580770, "_x_x_x_x_bach_float64_x_x_x_x_", 184, 1074017063, "_x_x_x_x_bach_float64_x_x_x_x_", 54646, 3221575522, "_x_x_x_x_bach_float64_x_x_x_x_", 49034, 1073988742, "_x_x_x_x_bach_float64_x_x_x_x_", 54318, 3221570274, "_x_x_x_x_bach_float64_x_x_x_x_", 54822, 1073960431, "_x_x_x_x_bach_float64_x_x_x_x_", 53990, 3221565025, "_x_x_x_x_bach_float64_x_x_x_x_", 15609, 1073932132, "_x_x_x_x_bach_float64_x_x_x_x_", 53662, 3221559777, "_x_x_x_x_bach_float64_x_x_x_x_", 58344, 1073903848, "_x_x_x_x_bach_float64_x_x_x_x_", 53334, 3221554529, "_x_x_x_x_bach_float64_x_x_x_x_", 34725, 1073875582, "_x_x_x_x_bach_float64_x_x_x_x_", 53006, 3221549281, "_x_x_x_x_bach_float64_x_x_x_x_", 35206, 1073847335, "_x_x_x_x_bach_float64_x_x_x_x_", 52678, 3221544033, "_x_x_x_x_bach_float64_x_x_x_x_", 51783, 1073819110, "_x_x_x_x_bach_float64_x_x_x_x_", 52350, 3221538785, "_x_x_x_x_bach_float64_x_x_x_x_", 34842, 1073790909, "_x_x_x_x_bach_float64_x_x_x_x_", 52022, 3221533537, "_x_x_x_x_bach_float64_x_x_x_x_", 16478, 1073762735, "_x_x_x_x_bach_float64_x_x_x_x_", 51694, 3221528288, "_x_x_x_x_bach_float64_x_x_x_x_", 10984, 1073727356, "_x_x_x_x_bach_float64_x_x_x_x_", 51366, 3221523040, "_x_x_x_x_bach_float64_x_x_x_x_", 29180, 1073671127, "_x_x_x_x_bach_float64_x_x_x_x_", 51038, 3221517792, "_x_x_x_x_bach_float64_x_x_x_x_", 46591, 1073614965, "_x_x_x_x_bach_float64_x_x_x_x_", 50710, 3221512544, "_x_x_x_x_bach_float64_x_x_x_x_", 15466, 1073558874, "_x_x_x_x_bach_float64_x_x_x_x_", 50382, 3221507296, "_x_x_x_x_bach_float64_x_x_x_x_", 9242, 1073502859, "_x_x_x_x_bach_float64_x_x_x_x_", 50054, 3221502048, "_x_x_x_x_bach_float64_x_x_x_x_", 25913, 1073446924, "_x_x_x_x_bach_float64_x_x_x_x_", 49726, 3221496800, "_x_x_x_x_bach_float64_x_x_x_x_", 56832, 1073391074, "_x_x_x_x_bach_float64_x_x_x_x_", 49398, 3221491552, "_x_x_x_x_bach_float64_x_x_x_x_", 27892, 1073335314, "_x_x_x_x_bach_float64_x_x_x_x_", 49070, 3221486303, "_x_x_x_x_bach_float64_x_x_x_x_", 6524, 1073279648, "_x_x_x_x_bach_float64_x_x_x_x_", 48742, 3221481055, "_x_x_x_x_bach_float64_x_x_x_x_", 19334, 1073224081, "_x_x_x_x_bach_float64_x_x_x_x_", 48414, 3221475807, "_x_x_x_x_bach_float64_x_x_x_x_", 4881, 1073168616, "_x_x_x_x_bach_float64_x_x_x_x_", 48086, 3221470559, "_x_x_x_x_bach_float64_x_x_x_x_", 32827, 1073113260, "_x_x_x_x_bach_float64_x_x_x_x_", 47758, 3221465311, "_x_x_x_x_bach_float64_x_x_x_x_", 3266, 1073058015, "_x_x_x_x_bach_float64_x_x_x_x_", 47430, 3221460063, "_x_x_x_x_bach_float64_x_x_x_x_", 6039, 1073002887, "_x_x_x_x_bach_float64_x_x_x_x_", 47102, 3221454815, "_x_x_x_x_bach_float64_x_x_x_x_", 29532, 1072947880, "_x_x_x_x_bach_float64_x_x_x_x_", 46774, 3221449567, "_x_x_x_x_bach_float64_x_x_x_x_", 2178, 1072892998, "_x_x_x_x_bach_float64_x_x_x_x_", 46446, 3221444318, "_x_x_x_x_bach_float64_x_x_x_x_", 35781, 1072838246, "_x_x_x_x_bach_float64_x_x_x_x_", 46118, 3221439070, "_x_x_x_x_bach_float64_x_x_x_x_", 18901, 1072783629, "_x_x_x_x_bach_float64_x_x_x_x_", 45790, 3221433822, "_x_x_x_x_bach_float64_x_x_x_x_", 2274, 1072729151, "_x_x_x_x_bach_float64_x_x_x_x_", 45462, 3221428574, "_x_x_x_x_bach_float64_x_x_x_x_", 390, 1072656384, "_x_x_x_x_bach_float64_x_x_x_x_", 45134, 3221423326, "_x_x_x_x_bach_float64_x_x_x_x_", 54540, 1072548009, "_x_x_x_x_bach_float64_x_x_x_x_", 44806, 3221418078, "_x_x_x_x_bach_float64_x_x_x_x_", 20550, 1072439938, "_x_x_x_x_bach_float64_x_x_x_x_", 44478, 3221412830, "_x_x_x_x_bach_float64_x_x_x_x_", 2564, 1072332179, "_x_x_x_x_bach_float64_x_x_x_x_", 44150, 3221407582, "_x_x_x_x_bach_float64_x_x_x_x_", 8268, 1072224742, "_x_x_x_x_bach_float64_x_x_x_x_", 43822, 3221402333, "_x_x_x_x_bach_float64_x_x_x_x_", 8524, 1072117635, "_x_x_x_x_bach_float64_x_x_x_x_", 43493, 3221397085, "_x_x_x_x_bach_float64_x_x_x_x_", 10830, 1072010867, "_x_x_x_x_bach_float64_x_x_x_x_", 43166, 3221391837, "_x_x_x_x_bach_float64_x_x_x_x_", 16182, 1071904446, "_x_x_x_x_bach_float64_x_x_x_x_", 42838, 3221386589, "_x_x_x_x_bach_float64_x_x_x_x_", 55482, 1071798381, "_x_x_x_x_bach_float64_x_x_x_x_", 42510, 3221381341, "_x_x_x_x_bach_float64_x_x_x_x_", 45096, 1071692680, "_x_x_x_x_bach_float64_x_x_x_x_", 42182, 3221376093, "_x_x_x_x_bach_float64_x_x_x_x_", 35244, 1071530034, "_x_x_x_x_bach_float64_x_x_x_x_", 41853, 3221370845, "_x_x_x_x_bach_float64_x_x_x_x_", 16232, 1071320141, "_x_x_x_x_bach_float64_x_x_x_x_", 41526, 3221365597, "_x_x_x_x_bach_float64_x_x_x_x_", 44252, 1071111027, "_x_x_x_x_bach_float64_x_x_x_x_", 41198, 3221360348, "_x_x_x_x_bach_float64_x_x_x_x_", 39184, 1070902710, "_x_x_x_x_bach_float64_x_x_x_x_", 40870, 3221355100, "_x_x_x_x_bach_float64_x_x_x_x_", 29236, 1070695205, "_x_x_x_x_bach_float64_x_x_x_x_", 40542, 3221349852, "_x_x_x_x_bach_float64_x_x_x_x_", 46480, 1070380964, "_x_x_x_x_bach_float64_x_x_x_x_", 40213, 3221344604, "_x_x_x_x_bach_float64_x_x_x_x_", 33344, 1069969306, "_x_x_x_x_bach_float64_x_x_x_x_", 39886, 3221339356, "_x_x_x_x_bach_float64_x_x_x_x_", 2080, 1069559372, "_x_x_x_x_bach_float64_x_x_x_x_", 39558, 3221334108, "_x_x_x_x_bach_float64_x_x_x_x_", 34656, 1068754872, "_x_x_x_x_bach_float64_x_x_x_x_", 39230, 3221328860, "_x_x_x_x_bach_float64_x_x_x_x_", 57472, 1067320143, "_x_x_x_x_bach_float64_x_x_x_x_", 38902, 3221323611, "_x_x_x_x_bach_float64_x_x_x_x_", 36992, 3214106449, "_x_x_x_x_bach_float64_x_x_x_x_", 38573, 3221318363, "_x_x_x_x_bach_float64_x_x_x_x_", 45408, 3216056832, "_x_x_x_x_bach_float64_x_x_x_x_", 38246, 3221313115, "_x_x_x_x_bach_float64_x_x_x_x_", 52992, 3216858479, "_x_x_x_x_bach_float64_x_x_x_x_", 37918, 3221307867, "_x_x_x_x_bach_float64_x_x_x_x_", 10832, 3217343729, "_x_x_x_x_bach_float64_x_x_x_x_", 37590, 3221302619, "_x_x_x_x_bach_float64_x_x_x_x_", 57152, 3217740685, "_x_x_x_x_bach_float64_x_x_x_x_", 37262, 3221297371, "_x_x_x_x_bach_float64_x_x_x_x_", 43288, 3218107702, "_x_x_x_x_bach_float64_x_x_x_x_", 36933, 3221292123, "_x_x_x_x_bach_float64_x_x_x_x_", 26104, 3218304183, "_x_x_x_x_bach_float64_x_x_x_x_", 36606, 3221286875, "_x_x_x_x_bach_float64_x_x_x_x_", 39280, 3218499643, "_x_x_x_x_bach_float64_x_x_x_x_", 36278, 3221281626, "_x_x_x_x_bach_float64_x_x_x_x_", 12184, 3218694067, "_x_x_x_x_bach_float64_x_x_x_x_", 35950, 3221276378, "_x_x_x_x_bach_float64_x_x_x_x_", 1648, 3218887438, "_x_x_x_x_bach_float64_x_x_x_x_", 35622, 3221271130, "_x_x_x_x_bach_float64_x_x_x_x_", 15440, 3219079741, "_x_x_x_x_bach_float64_x_x_x_x_", 35293, 3221265882, "_x_x_x_x_bach_float64_x_x_x_x_", 58828, 3219199641, "_x_x_x_x_bach_float64_x_x_x_x_", 34966, 3221260634, "_x_x_x_x_bach_float64_x_x_x_x_", 47288, 3219294703, "_x_x_x_x_bach_float64_x_x_x_x_", 34638, 3221255386, "_x_x_x_x_bach_float64_x_x_x_x_", 28920, 3219389209, "_x_x_x_x_bach_float64_x_x_x_x_", 34310, 3221250138, "_x_x_x_x_bach_float64_x_x_x_x_", 7996, 3219483151, "_x_x_x_x_bach_float64_x_x_x_x_", 33982, 3221244890, "_x_x_x_x_bach_float64_x_x_x_x_", 59944, 3219576523, "_x_x_x_x_bach_float64_x_x_x_x_", 33653, 3221239641, "_x_x_x_x_bach_float64_x_x_x_x_", 3656, 3219669316, "_x_x_x_x_bach_float64_x_x_x_x_", 33326, 3221234393, "_x_x_x_x_bach_float64_x_x_x_x_", 31996, 3219761525, "_x_x_x_x_bach_float64_x_x_x_x_", 32997, 3221229145, "_x_x_x_x_bach_float64_x_x_x_x_", 7228, 3219853141, "_x_x_x_x_bach_float64_x_x_x_x_", 65340, 3221222323, "_x_x_x_x_bach_float64_x_x_x_x_", 41088, 3219944157, "_x_x_x_x_bach_float64_x_x_x_x_", 64684, 3221211826, "_x_x_x_x_bach_float64_x_x_x_x_", 1668, 3220034567, "_x_x_x_x_bach_float64_x_x_x_x_", 64026, 3221201330, "_x_x_x_x_bach_float64_x_x_x_x_", 42244, 3220124364, "_x_x_x_x_bach_float64_x_x_x_x_", 63372, 3221190834, "_x_x_x_x_bach_float64_x_x_x_x_", 27896, 3220195218, "_x_x_x_x_bach_float64_x_x_x_x_", 62714, 3221180338, "_x_x_x_x_bach_float64_x_x_x_x_", 10290, 3220239493, "_x_x_x_x_bach_float64_x_x_x_x_", 62060, 3221169841, "_x_x_x_x_bach_float64_x_x_x_x_", 28270, 3220283450, "_x_x_x_x_bach_float64_x_x_x_x_", 61404, 3221159345, "_x_x_x_x_bach_float64_x_x_x_x_", 63688, 3220327088, "_x_x_x_x_bach_float64_x_x_x_x_", 60746, 3221148849, "_x_x_x_x_bach_float64_x_x_x_x_", 54060, 3220370401, "_x_x_x_x_bach_float64_x_x_x_x_", 60092, 3221138353, "_x_x_x_x_bach_float64_x_x_x_x_", 10946, 3220413388, "_x_x_x_x_bach_float64_x_x_x_x_", 59434, 3221127856, "_x_x_x_x_bach_float64_x_x_x_x_", 58898, 3220456045, "_x_x_x_x_bach_float64_x_x_x_x_", 58780, 3221117360, "_x_x_x_x_bach_float64_x_x_x_x_", 1358, 3220498368, "_x_x_x_x_bach_float64_x_x_x_x_", 58124, 3221106864, "_x_x_x_x_bach_float64_x_x_x_x_", 52226, 3220540355, "_x_x_x_x_bach_float64_x_x_x_x_", 57466, 3221096368, "_x_x_x_x_bach_float64_x_x_x_x_", 45508, 3220582002, "_x_x_x_x_bach_float64_x_x_x_x_", 56812, 3221085871, "_x_x_x_x_bach_float64_x_x_x_x_", 6776, 3220623306, "_x_x_x_x_bach_float64_x_x_x_x_", 56154, 3221075375, "_x_x_x_x_bach_float64_x_x_x_x_", 54744, 3220664264, "_x_x_x_x_bach_float64_x_x_x_x_", 55500, 3221064879, "_x_x_x_x_bach_float64_x_x_x_x_", 25646, 3220704874, "_x_x_x_x_bach_float64_x_x_x_x_", 54844, 3221054383, "_x_x_x_x_bach_float64_x_x_x_x_", 506, 3220745131, "_x_x_x_x_bach_float64_x_x_x_x_", 54186, 3221043886, "_x_x_x_x_bach_float64_x_x_x_x_", 30684, 3220785033, "_x_x_x_x_bach_float64_x_x_x_x_", 53532, 3221033390, "_x_x_x_x_bach_float64_x_x_x_x_", 44952, 3220824577, "_x_x_x_x_bach_float64_x_x_x_x_", 52874, 3221022894, "_x_x_x_x_bach_float64_x_x_x_x_", 3490, 3220863761, "_x_x_x_x_bach_float64_x_x_x_x_", 52220, 3221012397, "_x_x_x_x_bach_float64_x_x_x_x_", 36214, 3220902580, "_x_x_x_x_bach_float64_x_x_x_x_", 51564, 3221001901, "_x_x_x_x_bach_float64_x_x_x_x_", 41542, 3220941033, "_x_x_x_x_bach_float64_x_x_x_x_", 50906, 3220991405, "_x_x_x_x_bach_float64_x_x_x_x_", 55670, 3220979117, "_x_x_x_x_bach_float64_x_x_x_x_", 50252, 3220980909, "_x_x_x_x_bach_float64_x_x_x_x_", 16324, 3221016829, "_x_x_x_x_bach_float64_x_x_x_x_", 49594, 3220970412, "_x_x_x_x_bach_float64_x_x_x_x_", 34928, 3221054165, "_x_x_x_x_bach_float64_x_x_x_x_", 48940, 3220959916, "_x_x_x_x_bach_float64_x_x_x_x_", 62730, 3221091125, "_x_x_x_x_bach_float64_x_x_x_x_", 48284, 3220949420, "_x_x_x_x_bach_float64_x_x_x_x_", 65258, 3221127704, "_x_x_x_x_bach_float64_x_x_x_x_", 47626, 3220938924, "_x_x_x_x_bach_float64_x_x_x_x_", 49260, 3221163900, "_x_x_x_x_bach_float64_x_x_x_x_", 46972, 3220928427, "_x_x_x_x_bach_float64_x_x_x_x_", 7760, 3221199711, "_x_x_x_x_bach_float64_x_x_x_x_", 46314, 3220917931, "_x_x_x_x_bach_float64_x_x_x_x_", 22655, 3221230303, "_x_x_x_x_bach_float64_x_x_x_x_", 45660, 3220907435, "_x_x_x_x_bach_float64_x_x_x_x_", 46618, 3221247819, "_x_x_x_x_bach_float64_x_x_x_x_", 45002, 3220896939, "_x_x_x_x_bach_float64_x_x_x_x_", 33539, 3221265139, "_x_x_x_x_bach_float64_x_x_x_x_", 44346, 3220886442, "_x_x_x_x_bach_float64_x_x_x_x_", 3521, 3221282261, "_x_x_x_x_bach_float64_x_x_x_x_", 43692, 3220875946, "_x_x_x_x_bach_float64_x_x_x_x_", 35287, 3221299184, "_x_x_x_x_bach_float64_x_x_x_x_", 43034, 3220865450, "_x_x_x_x_bach_float64_x_x_x_x_", 57304, 3221315907, "_x_x_x_x_bach_float64_x_x_x_x_", 42380, 3220854954, "_x_x_x_x_bach_float64_x_x_x_x_", 23517, 3221332429, "_x_x_x_x_bach_float64_x_x_x_x_", 41722, 3220844457, "_x_x_x_x_bach_float64_x_x_x_x_", 15006, 3221348749, "_x_x_x_x_bach_float64_x_x_x_x_", 41066, 3220833961, "_x_x_x_x_bach_float64_x_x_x_x_", 5193, 3221364866, "_x_x_x_x_bach_float64_x_x_x_x_", 40412, 3220823465, "_x_x_x_x_bach_float64_x_x_x_x_", 9615, 3221380778, "_x_x_x_x_bach_float64_x_x_x_x_", 39754, 3220812969, "_x_x_x_x_bach_float64_x_x_x_x_", 30297, 3221396484, "_x_x_x_x_bach_float64_x_x_x_x_", 39100, 3220802472, "_x_x_x_x_bach_float64_x_x_x_x_", 56803, 3221411984, "_x_x_x_x_bach_float64_x_x_x_x_", 38442, 3220791976, "_x_x_x_x_bach_float64_x_x_x_x_", 58500, 3221427276, "_x_x_x_x_bach_float64_x_x_x_x_", 37786, 3220781480, "_x_x_x_x_bach_float64_x_x_x_x_", 33372, 3221442360, "_x_x_x_x_bach_float64_x_x_x_x_", 37132, 3220770984, "_x_x_x_x_bach_float64_x_x_x_x_", 47936, 3221457234, "_x_x_x_x_bach_float64_x_x_x_x_", 36474, 3220760487, "_x_x_x_x_bach_float64_x_x_x_x_", 5999, 3221471897, "_x_x_x_x_bach_float64_x_x_x_x_", 35820, 3220749991, "_x_x_x_x_bach_float64_x_x_x_x_", 63708, 3221486349, "_x_x_x_x_bach_float64_x_x_x_x_", 35162, 3220739495, "_x_x_x_x_bach_float64_x_x_x_x_", 52547, 3221500588, "_x_x_x_x_bach_float64_x_x_x_x_", 34506, 3220728999, "_x_x_x_x_bach_float64_x_x_x_x_", 7235, 3221514614, "_x_x_x_x_bach_float64_x_x_x_x_", 33852, 3220718502, "_x_x_x_x_bach_float64_x_x_x_x_", 29188, 3221528426, "_x_x_x_x_bach_float64_x_x_x_x_", 33194, 3220708006, "_x_x_x_x_bach_float64_x_x_x_x_", 9665, 3221542023, "_x_x_x_x_bach_float64_x_x_x_x_", 32540, 3220697510, "_x_x_x_x_bach_float64_x_x_x_x_", 64552, 3221555403, "_x_x_x_x_bach_float64_x_x_x_x_", 31882, 3220687014, "_x_x_x_x_bach_float64_x_x_x_x_", 42431, 3221568567, "_x_x_x_x_bach_float64_x_x_x_x_", 31226, 3220676517, "_x_x_x_x_bach_float64_x_x_x_x_", 6311, 3221581514, "_x_x_x_x_bach_float64_x_x_x_x_", 30572, 3220666021, "_x_x_x_x_bach_float64_x_x_x_x_", 50700, 3221594242, "_x_x_x_x_bach_float64_x_x_x_x_", 29914, 3220655525, "_x_x_x_x_bach_float64_x_x_x_x_", 43741, 3221606751, "_x_x_x_x_bach_float64_x_x_x_x_", 29260, 3220645029, "_x_x_x_x_bach_float64_x_x_x_x_", 15284, 3221619040, "_x_x_x_x_bach_float64_x_x_x_x_", 28602, 3220634532, "_x_x_x_x_bach_float64_x_x_x_x_", 11253, 3221631109, "_x_x_x_x_bach_float64_x_x_x_x_", 27946, 3220624036, "_x_x_x_x_bach_float64_x_x_x_x_", 4041, 3221642957, "_x_x_x_x_bach_float64_x_x_x_x_", 27292, 3220613540, "_x_x_x_x_bach_float64_x_x_x_x_", 55564, 3221654583, "_x_x_x_x_bach_float64_x_x_x_x_", 26634, 3220603044, "_x_x_x_x_bach_float64_x_x_x_x_", 12023, 3221665986, "_x_x_x_x_bach_float64_x_x_x_x_", 25980, 3220592547, "_x_x_x_x_bach_float64_x_x_x_x_", 41042, 3221677167, "_x_x_x_x_bach_float64_x_x_x_x_", 25322, 3220582051, "_x_x_x_x_bach_float64_x_x_x_x_", 45145, 3221688123, "_x_x_x_x_bach_float64_x_x_x_x_", 24666, 3220571555, "_x_x_x_x_bach_float64_x_x_x_x_", 48609, 3221698855, "_x_x_x_x_bach_float64_x_x_x_x_", 24008, 3220561058, "_x_x_x_x_bach_float64_x_x_x_x_", 50420, 3221709363, "_x_x_x_x_bach_float64_x_x_x_x_", 23354, 3220550562, "_x_x_x_x_bach_float64_x_x_x_x_", 64137, 3221719645, "_x_x_x_x_bach_float64_x_x_x_x_", 22700, 3220540066, "_x_x_x_x_bach_float64_x_x_x_x_", 17018, 3221729702, "_x_x_x_x_bach_float64_x_x_x_x_", 22042, 3220529570, "_x_x_x_x_bach_float64_x_x_x_x_", 32621, 3221739532, "_x_x_x_x_bach_float64_x_x_x_x_", 21386, 3220519073, "_x_x_x_x_bach_float64_x_x_x_x_", 48319, 3221749135, "_x_x_x_x_bach_float64_x_x_x_x_", 20728, 3220508577, "_x_x_x_x_bach_float64_x_x_x_x_", 12878, 3221758511, "_x_x_x_x_bach_float64_x_x_x_x_", 20074, 3220498081, "_x_x_x_x_bach_float64_x_x_x_x_", 8717, 3221767659, "_x_x_x_x_bach_float64_x_x_x_x_", 19420, 3220487585, "_x_x_x_x_bach_float64_x_x_x_x_", 36702, 3221776580, "_x_x_x_x_bach_float64_x_x_x_x_", 18762, 3220477088, "_x_x_x_x_bach_float64_x_x_x_x_", 53257, 3221785272, "_x_x_x_x_bach_float64_x_x_x_x_", 18106, 3220466592, "_x_x_x_x_bach_float64_x_x_x_x_", 63163, 3221793735, "_x_x_x_x_bach_float64_x_x_x_x_", 17448, 3220456096, "_x_x_x_x_bach_float64_x_x_x_x_", 5950, 3221801969, "_x_x_x_x_bach_float64_x_x_x_x_", 16794, 3220445600, "_x_x_x_x_bach_float64_x_x_x_x_", 25581, 3221809974, "_x_x_x_x_bach_float64_x_x_x_x_", 16140, 3220435103, "_x_x_x_x_bach_float64_x_x_x_x_", 9418, 3221817749, "_x_x_x_x_bach_float64_x_x_x_x_", 15482, 3220424607, "_x_x_x_x_bach_float64_x_x_x_x_", 34759, 3221825295, "_x_x_x_x_bach_float64_x_x_x_x_", 14826, 3220414111, "_x_x_x_x_bach_float64_x_x_x_x_", 19059, 3221832610, "_x_x_x_x_bach_float64_x_x_x_x_", 14168, 3220403615, "_x_x_x_x_bach_float64_x_x_x_x_", 15614, 3221839695, "_x_x_x_x_bach_float64_x_x_x_x_", 13514, 3220393118, "_x_x_x_x_bach_float64_x_x_x_x_", 40529, 3221846549, "_x_x_x_x_bach_float64_x_x_x_x_", 12860, 3220382622, "_x_x_x_x_bach_float64_x_x_x_x_", 20882, 3221853173, "_x_x_x_x_bach_float64_x_x_x_x_", 12202, 3220372126, "_x_x_x_x_bach_float64_x_x_x_x_", 60575, 3221859566, "_x_x_x_x_bach_float64_x_x_x_x_", 11546, 3220361630, "_x_x_x_x_bach_float64_x_x_x_x_", 40905, 3221865728, "_x_x_x_x_bach_float64_x_x_x_x_", 10888, 3220351133, "_x_x_x_x_bach_float64_x_x_x_x_", 63156, 3221871659, "_x_x_x_x_bach_float64_x_x_x_x_", 10234, 3220340637, "_x_x_x_x_bach_float64_x_x_x_x_", 29245, 3221877359, "_x_x_x_x_bach_float64_x_x_x_x_", 9580, 3220330141, "_x_x_x_x_bach_float64_x_x_x_x_", 64398, 3221882828, "_x_x_x_x_bach_float64_x_x_x_x_", 8922, 3220319645, "_x_x_x_x_bach_float64_x_x_x_x_", 12341, 3221888066, "_x_x_x_x_bach_float64_x_x_x_x_", 8266, 3220309148, "_x_x_x_x_bach_float64_x_x_x_x_", 34635, 3221893072, "_x_x_x_x_bach_float64_x_x_x_x_", 7608, 3220298652, "_x_x_x_x_bach_float64_x_x_x_x_", 20410, 3221897848, "_x_x_x_x_bach_float64_x_x_x_x_", 6954, 3220288156, "_x_x_x_x_bach_float64_x_x_x_x_", 34703, 3221902392, "_x_x_x_x_bach_float64_x_x_x_x_", 6300, 3220277660, "_x_x_x_x_bach_float64_x_x_x_x_", 35920, 3221906706, "_x_x_x_x_bach_float64_x_x_x_x_", 5642, 3220267163, "_x_x_x_x_bach_float64_x_x_x_x_", 42111, 3221910788, "_x_x_x_x_bach_float64_x_x_x_x_", 4986, 3220256667, "_x_x_x_x_bach_float64_x_x_x_x_", 25111, 3221914640, "_x_x_x_x_bach_float64_x_x_x_x_", 4328, 3220246171, "_x_x_x_x_bach_float64_x_x_x_x_", 56896, 3221918261, "_x_x_x_x_bach_float64_x_x_x_x_", 3674, 3220235675, "_x_x_x_x_bach_float64_x_x_x_x_", 52749, 3221921651, "_x_x_x_x_bach_float64_x_x_x_x_", 3016, 3220225178, "_x_x_x_x_bach_float64_x_x_x_x_", 28784, 3221924811, "_x_x_x_x_bach_float64_x_x_x_x_", 2362, 3220214682, "_x_x_x_x_bach_float64_x_x_x_x_", 21833, 3221927742, "_x_x_x_x_bach_float64_x_x_x_x_", 1706, 3220204186, "_x_x_x_x_bach_float64_x_x_x_x_", 64969, 3221930442, "_x_x_x_x_bach_float64_x_x_x_x_", 1048, 3220193690, "_x_x_x_x_bach_float64_x_x_x_x_", 21994, 3221932913, "_x_x_x_x_bach_float64_x_x_x_x_", 394, 3220183193, "_x_x_x_x_bach_float64_x_x_x_x_", 1871, 3221935154, "_x_x_x_x_bach_float64_x_x_x_x_", 65008, 3220168498, "_x_x_x_x_bach_float64_x_x_x_x_", 42350, 3221937166, "_x_x_x_x_bach_float64_x_x_x_x_", 63696, 3220147506, "_x_x_x_x_bach_float64_x_x_x_x_", 45844, 3221938950, "_x_x_x_x_bach_float64_x_x_x_x_", 62392, 3220126513, "_x_x_x_x_bach_float64_x_x_x_x_", 33114, 3221940505, "_x_x_x_x_bach_float64_x_x_x_x_", 61072, 3220105521, "_x_x_x_x_bach_float64_x_x_x_x_", 59412, 3221941832, "_x_x_x_x_bach_float64_x_x_x_x_", 59760, 3220084528, "_x_x_x_x_bach_float64_x_x_x_x_", 55238, 3221942932, "_x_x_x_x_bach_float64_x_x_x_x_", 58448, 3220063536, "_x_x_x_x_bach_float64_x_x_x_x_", 50490, 3221943805, "_x_x_x_x_bach_float64_x_x_x_x_", 57136, 3220042543, "_x_x_x_x_bach_float64_x_x_x_x_", 61104, 3221944450, "_x_x_x_x_bach_float64_x_x_x_x_", 55832, 3220021551, "_x_x_x_x_bach_float64_x_x_x_x_", 31454, 3221944870, "_x_x_x_x_bach_float64_x_x_x_x_", 54512, 3220000558, "_x_x_x_x_bach_float64_x_x_x_x_", 29108, 3221945064, "_x_x_x_x_bach_float64_x_x_x_x_", 53200, 3219979566, "_x_x_x_x_bach_float64_x_x_x_x_", 36606, 3221945032, "_x_x_x_x_bach_float64_x_x_x_x_", 51888, 3219958573, "_x_x_x_x_bach_float64_x_x_x_x_", 61188, 3221944776, "_x_x_x_x_bach_float64_x_x_x_x_", 50576, 3219937581, "_x_x_x_x_bach_float64_x_x_x_x_", 38210, 3221944295, "_x_x_x_x_bach_float64_x_x_x_x_", 49272, 3219916588, "_x_x_x_x_bach_float64_x_x_x_x_", 52518, 3221943591, "_x_x_x_x_bach_float64_x_x_x_x_", 47952, 3219895596, "_x_x_x_x_bach_float64_x_x_x_x_", 25900, 3221942664, "_x_x_x_x_bach_float64_x_x_x_x_", 46640, 3219874603, "_x_x_x_x_bach_float64_x_x_x_x_", 50238, 3221941514, "_x_x_x_x_bach_float64_x_x_x_x_", 45328, 3219853611, "_x_x_x_x_bach_float64_x_x_x_x_", 55676, 3221940143, "_x_x_x_x_bach_float64_x_x_x_x_", 44016, 3219832618, "_x_x_x_x_bach_float64_x_x_x_x_", 59040, 3221938550, "_x_x_x_x_bach_float64_x_x_x_x_", 42712, 3219811626, "_x_x_x_x_bach_float64_x_x_x_x_", 9458, 3221936737, "_x_x_x_x_bach_float64_x_x_x_x_", 41392, 3219790633, "_x_x_x_x_bach_float64_x_x_x_x_", 17676, 3221934705, "_x_x_x_x_bach_float64_x_x_x_x_", 40080, 3219769641, "_x_x_x_x_bach_float64_x_x_x_x_", 51584, 3221932453, "_x_x_x_x_bach_float64_x_x_x_x_", 38768, 3219748648, "_x_x_x_x_bach_float64_x_x_x_x_", 15462, 3221929983, "_x_x_x_x_bach_float64_x_x_x_x_", 37456, 3219727656, "_x_x_x_x_bach_float64_x_x_x_x_", 16418, 3221927296, "_x_x_x_x_bach_float64_x_x_x_x_", 36144, 3219706663, "_x_x_x_x_bach_float64_x_x_x_x_", 31566, 3221924392, "_x_x_x_x_bach_float64_x_x_x_x_", 34832, 3219685671, "_x_x_x_x_bach_float64_x_x_x_x_", 24604, 3221921272, "_x_x_x_x_bach_float64_x_x_x_x_", 33520, 3219664678, "_x_x_x_x_bach_float64_x_x_x_x_", 53026, 3221917937, "_x_x_x_x_bach_float64_x_x_x_x_", 32208, 3219643686, "_x_x_x_x_bach_float64_x_x_x_x_", 38358, 3221914388, "_x_x_x_x_bach_float64_x_x_x_x_", 30896, 3219622693, "_x_x_x_x_bach_float64_x_x_x_x_", 51416, 3221910626, "_x_x_x_x_bach_float64_x_x_x_x_", 29584, 3219601701, "_x_x_x_x_bach_float64_x_x_x_x_", 64022, 3221906651, "_x_x_x_x_bach_float64_x_x_x_x_", 28272, 3219580708, "_x_x_x_x_bach_float64_x_x_x_x_", 19226, 3221902465, "_x_x_x_x_bach_float64_x_x_x_x_", 26960, 3219559716, "_x_x_x_x_bach_float64_x_x_x_x_", 23423, 3221898068, "_x_x_x_x_bach_float64_x_x_x_x_", 25648, 3219538723, "_x_x_x_x_bach_float64_x_x_x_x_", 5084, 3221893462, "_x_x_x_x_bach_float64_x_x_x_x_", 24336, 3219517731, "_x_x_x_x_bach_float64_x_x_x_x_", 19744, 3221888647, "_x_x_x_x_bach_float64_x_x_x_x_", 23024, 3219496738, "_x_x_x_x_bach_float64_x_x_x_x_", 21697, 3221883625, "_x_x_x_x_bach_float64_x_x_x_x_", 21712, 3219475746, "_x_x_x_x_bach_float64_x_x_x_x_", 19888, 3221878396, "_x_x_x_x_bach_float64_x_x_x_x_", 20400, 3219454753, "_x_x_x_x_bach_float64_x_x_x_x_", 28264, 3221872962, "_x_x_x_x_bach_float64_x_x_x_x_", 19088, 3219433761, "_x_x_x_x_bach_float64_x_x_x_x_", 7213, 3221867324, "_x_x_x_x_bach_float64_x_x_x_x_", 17776, 3219412768, "_x_x_x_x_bach_float64_x_x_x_x_", 58289, 3221861482, "_x_x_x_x_bach_float64_x_x_x_x_", 16464, 3219391776, "_x_x_x_x_bach_float64_x_x_x_x_", 20300, 3221855438, "_x_x_x_x_bach_float64_x_x_x_x_", 15152, 3219370783, "_x_x_x_x_bach_float64_x_x_x_x_", 39669, 3221849192, "_x_x_x_x_bach_float64_x_x_x_x_", 13840, 3219349791, "_x_x_x_x_bach_float64_x_x_x_x_", 17964, 3221842747, "_x_x_x_x_bach_float64_x_x_x_x_", 12528, 3219328798, "_x_x_x_x_bach_float64_x_x_x_x_", 33801, 3221836104, "_x_x_x_x_bach_float64_x_x_x_x_", 11216, 3219307805, "_x_x_x_x_bach_float64_x_x_x_x_", 35225, 3221829262, "_x_x_x_x_bach_float64_x_x_x_x_", 9904, 3219286813, "_x_x_x_x_bach_float64_x_x_x_x_", 47817, 3221822225, "_x_x_x_x_bach_float64_x_x_x_x_", 8592, 3219265820, "_x_x_x_x_bach_float64_x_x_x_x_", 46596, 3221814992, "_x_x_x_x_bach_float64_x_x_x_x_", 7280, 3219244828, "_x_x_x_x_bach_float64_x_x_x_x_", 16069, 3221807565, "_x_x_x_x_bach_float64_x_x_x_x_", 5968, 3219223835, "_x_x_x_x_bach_float64_x_x_x_x_", 1864, 3221799946, "_x_x_x_x_bach_float64_x_x_x_x_", 4656, 3219202843, "_x_x_x_x_bach_float64_x_x_x_x_", 22931, 3221792136, "_x_x_x_x_bach_float64_x_x_x_x_", 3344, 3219181850, "_x_x_x_x_bach_float64_x_x_x_x_", 40982, 3221784135, "_x_x_x_x_bach_float64_x_x_x_x_", 2032, 3219160858, "_x_x_x_x_bach_float64_x_x_x_x_", 52743, 3221775946, "_x_x_x_x_bach_float64_x_x_x_x_", 720, 3219139865, "_x_x_x_x_bach_float64_x_x_x_x_", 42957, 3221767570, "_x_x_x_x_bach_float64_x_x_x_x_", 64352, 3219109426, "_x_x_x_x_bach_float64_x_x_x_x_", 60308, 3221759007, "_x_x_x_x_bach_float64_x_x_x_x_", 61728, 3219067441, "_x_x_x_x_bach_float64_x_x_x_x_", 23135, 3221750261, "_x_x_x_x_bach_float64_x_x_x_x_", 59104, 3219025456, "_x_x_x_x_bach_float64_x_x_x_x_", 41410, 3221741331, "_x_x_x_x_bach_float64_x_x_x_x_", 56480, 3218983471, "_x_x_x_x_bach_float64_x_x_x_x_", 9871, 3221732219, "_x_x_x_x_bach_float64_x_x_x_x_", 53856, 3218941486, "_x_x_x_x_bach_float64_x_x_x_x_", 45211, 3221722927, "_x_x_x_x_bach_float64_x_x_x_x_", 51232, 3218899501, "_x_x_x_x_bach_float64_x_x_x_x_", 63472, 3221713456, "_x_x_x_x_bach_float64_x_x_x_x_", 48608, 3218857516, "_x_x_x_x_bach_float64_x_x_x_x_", 5027, 3221703808, "_x_x_x_x_bach_float64_x_x_x_x_", 45984, 3218815531, "_x_x_x_x_bach_float64_x_x_x_x_", 51839, 3221693983, "_x_x_x_x_bach_float64_x_x_x_x_", 43360, 3218773546, "_x_x_x_x_bach_float64_x_x_x_x_", 50653, 3221683985, "_x_x_x_x_bach_float64_x_x_x_x_", 40736, 3218731561, "_x_x_x_x_bach_float64_x_x_x_x_", 42701, 3221673814, "_x_x_x_x_bach_float64_x_x_x_x_", 38112, 3218689576, "_x_x_x_x_bach_float64_x_x_x_x_", 65013, 3221663471, "_x_x_x_x_bach_float64_x_x_x_x_", 35488, 3218647591, "_x_x_x_x_bach_float64_x_x_x_x_", 9793, 3221652959, "_x_x_x_x_bach_float64_x_x_x_x_", 32864, 3218605606, "_x_x_x_x_bach_float64_x_x_x_x_", 697, 3221642278, "_x_x_x_x_bach_float64_x_x_x_x_", 30240, 3218563621, "_x_x_x_x_bach_float64_x_x_x_x_", 40917, 3221631431, "_x_x_x_x_bach_float64_x_x_x_x_", 27616, 3218521636, "_x_x_x_x_bach_float64_x_x_x_x_", 47204, 3221620419, "_x_x_x_x_bach_float64_x_x_x_x_", 24992, 3218479651, "_x_x_x_x_bach_float64_x_x_x_x_", 7798, 3221609244, "_x_x_x_x_bach_float64_x_x_x_x_", 22368, 3218437666, "_x_x_x_x_bach_float64_x_x_x_x_", 2171, 3221597907, "_x_x_x_x_bach_float64_x_x_x_x_", 19744, 3218395681, "_x_x_x_x_bach_float64_x_x_x_x_", 17108, 3221586410, "_x_x_x_x_bach_float64_x_x_x_x_", 17120, 3218353696, "_x_x_x_x_bach_float64_x_x_x_x_", 17986, 3221574755, "_x_x_x_x_bach_float64_x_x_x_x_", 14496, 3218311711, "_x_x_x_x_bach_float64_x_x_x_x_", 13123, 3221562943, "_x_x_x_x_bach_float64_x_x_x_x_", 11872, 3218269726, "_x_x_x_x_bach_float64_x_x_x_x_", 45788, 3221550976, "_x_x_x_x_bach_float64_x_x_x_x_", 9248, 3218227741, "_x_x_x_x_bach_float64_x_x_x_x_", 48373, 3221538856, "_x_x_x_x_bach_float64_x_x_x_x_", 6624, 3218185756, "_x_x_x_x_bach_float64_x_x_x_x_", 17572, 3221526584, "_x_x_x_x_bach_float64_x_x_x_x_", 4000, 3218143771, "_x_x_x_x_bach_float64_x_x_x_x_", 51869, 3221514163, "_x_x_x_x_bach_float64_x_x_x_x_", 1376, 3218101786, "_x_x_x_x_bach_float64_x_x_x_x_", 54835, 3221501594, "_x_x_x_x_bach_float64_x_x_x_x_", 63040, 3218039858, "_x_x_x_x_bach_float64_x_x_x_x_", 21771, 3221488879, "_x_x_x_x_bach_float64_x_x_x_x_", 57792, 3217955888, "_x_x_x_x_bach_float64_x_x_x_x_", 57852, 3221476019, "_x_x_x_x_bach_float64_x_x_x_x_", 52544, 3217871918, "_x_x_x_x_bach_float64_x_x_x_x_", 62266, 3221463017, "_x_x_x_x_bach_float64_x_x_x_x_", 47296, 3217787948, "_x_x_x_x_bach_float64_x_x_x_x_", 61508, 3221449874, "_x_x_x_x_bach_float64_x_x_x_x_", 42048, 3217703978, "_x_x_x_x_bach_float64_x_x_x_x_", 12226, 3221436593, "_x_x_x_x_bach_float64_x_x_x_x_", 36800, 3217620007, "_x_x_x_x_bach_float64_x_x_x_x_", 56761, 3221423174, "_x_x_x_x_bach_float64_x_x_x_x_", 31552, 3217536037, "_x_x_x_x_bach_float64_x_x_x_x_", 51796, 3221409620, "_x_x_x_x_bach_float64_x_x_x_x_", 26304, 3217452067, "_x_x_x_x_bach_float64_x_x_x_x_", 8611, 3221395933, "_x_x_x_x_bach_float64_x_x_x_x_", 21056, 3217368097, "_x_x_x_x_bach_float64_x_x_x_x_", 3213, 3221382115, "_x_x_x_x_bach_float64_x_x_x_x_", 15808, 3217284127, "_x_x_x_x_bach_float64_x_x_x_x_", 15188, 3221368167, "_x_x_x_x_bach_float64_x_x_x_x_", 10560, 3217200157, "_x_x_x_x_bach_float64_x_x_x_x_", 23033, 3221354091, "_x_x_x_x_bach_float64_x_x_x_x_", 5312, 3217116187, "_x_x_x_x_bach_float64_x_x_x_x_", 28376, 3221339890, "_x_x_x_x_bach_float64_x_x_x_x_", 64, 3217032217, "_x_x_x_x_bach_float64_x_x_x_x_", 9151, 3221325566, "_x_x_x_x_bach_float64_x_x_x_x_", 55168, 3216865327, "_x_x_x_x_bach_float64_x_x_x_x_", 63973, 3221311120, "_x_x_x_x_bach_float64_x_x_x_x_", 44672, 3216697387, "_x_x_x_x_bach_float64_x_x_x_x_", 26892, 3221296554, "_x_x_x_x_bach_float64_x_x_x_x_", 34176, 3216529446, "_x_x_x_x_bach_float64_x_x_x_x_", 59938, 3221281870, "_x_x_x_x_bach_float64_x_x_x_x_", 23680, 3216361506, "_x_x_x_x_bach_float64_x_x_x_x_", 60867, 3221267071, "_x_x_x_x_bach_float64_x_x_x_x_", 13184, 3216193566, "_x_x_x_x_bach_float64_x_x_x_x_", 48851, 3221252158, "_x_x_x_x_bach_float64_x_x_x_x_", 2688, 3216025626, "_x_x_x_x_bach_float64_x_x_x_x_", 20914, 3221237133, "_x_x_x_x_bach_float64_x_x_x_x_", 49920, 3215732781, "_x_x_x_x_bach_float64_x_x_x_x_", 110, 3221218525, "_x_x_x_x_bach_float64_x_x_x_x_", 28928, 3215396900, "_x_x_x_x_bach_float64_x_x_x_x_", 26052, 3221188041, "_x_x_x_x_bach_float64_x_x_x_x_", 7936, 3215061020, "_x_x_x_x_bach_float64_x_x_x_x_", 61230, 3221157346, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 3214516265, "_x_x_x_x_bach_float64_x_x_x_x_", 3185, 3221126444, "_x_x_x_x_bach_float64_x_x_x_x_", 60416, 3213803569, "_x_x_x_x_bach_float64_x_x_x_x_", 26338, 3221095339, "_x_x_x_x_bach_float64_x_x_x_x_", 18432, 3212083232, "_x_x_x_x_bach_float64_x_x_x_x_", 42046, 3221064035, "_x_x_x_x_bach_float64_x_x_x_x_", 18432, 1064599584, "_x_x_x_x_bach_float64_x_x_x_x_", 1845, 3221032537, "_x_x_x_x_bach_float64_x_x_x_x_", 60416, 1066319921, "_x_x_x_x_bach_float64_x_x_x_x_", 61075, 3221000849, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 1067032617, "_x_x_x_x_bach_float64_x_x_x_x_", 13214, 3220968974, "_x_x_x_x_bach_float64_x_x_x_x_", 7936, 1067577372, "_x_x_x_x_bach_float64_x_x_x_x_", 26734, 3220936918, "_x_x_x_x_bach_float64_x_x_x_x_", 28928, 1067913252, "_x_x_x_x_bach_float64_x_x_x_x_", 63203, 3220904684, "_x_x_x_x_bach_float64_x_x_x_x_", 49920, 1068249133, "_x_x_x_x_bach_float64_x_x_x_x_", 8455, 3220872277, "_x_x_x_x_bach_float64_x_x_x_x_", 2688, 1068541978, "_x_x_x_x_bach_float64_x_x_x_x_", 58244, 3220839701, "_x_x_x_x_bach_float64_x_x_x_x_", 13184, 1068709918, "_x_x_x_x_bach_float64_x_x_x_x_", 47848, 3220806961, "_x_x_x_x_bach_float64_x_x_x_x_", 23680, 1068877858, "_x_x_x_x_bach_float64_x_x_x_x_", 19572, 3220774060, "_x_x_x_x_bach_float64_x_x_x_x_", 34176, 1069045798, "_x_x_x_x_bach_float64_x_x_x_x_", 62262, 3220741003, "_x_x_x_x_bach_float64_x_x_x_x_", 44672, 1069213739, "_x_x_x_x_bach_float64_x_x_x_x_", 12826, 3220707794, "_x_x_x_x_bach_float64_x_x_x_x_", 55168, 1069381679, "_x_x_x_x_bach_float64_x_x_x_x_", 3003, 3220674439, "_x_x_x_x_bach_float64_x_x_x_x_", 64, 1069548569, "_x_x_x_x_bach_float64_x_x_x_x_", 16551, 3220640940, "_x_x_x_x_bach_float64_x_x_x_x_", 5312, 1069632539, "_x_x_x_x_bach_float64_x_x_x_x_", 29912, 3220607303, "_x_x_x_x_bach_float64_x_x_x_x_", 10560, 1069716509, "_x_x_x_x_bach_float64_x_x_x_x_", 15650, 3220573532, "_x_x_x_x_bach_float64_x_x_x_x_", 15808, 1069800479, "_x_x_x_x_bach_float64_x_x_x_x_", 5451, 3220539631, "_x_x_x_x_bach_float64_x_x_x_x_", 21056, 1069884449, "_x_x_x_x_bach_float64_x_x_x_x_", 16275, 3220505606, "_x_x_x_x_bach_float64_x_x_x_x_", 26304, 1069968419, "_x_x_x_x_bach_float64_x_x_x_x_", 36457, 3220471459, "_x_x_x_x_bach_float64_x_x_x_x_", 31552, 1070052389, "_x_x_x_x_bach_float64_x_x_x_x_", 6415, 3220437197, "_x_x_x_x_bach_float64_x_x_x_x_", 36800, 1070136359, "_x_x_x_x_bach_float64_x_x_x_x_", 56297, 3220402823, "_x_x_x_x_bach_float64_x_x_x_x_", 42048, 1070220330, "_x_x_x_x_bach_float64_x_x_x_x_", 17721, 3220368341, "_x_x_x_x_bach_float64_x_x_x_x_", 47296, 1070304300, "_x_x_x_x_bach_float64_x_x_x_x_", 44816, 3220333757, "_x_x_x_x_bach_float64_x_x_x_x_", 52544, 1070388270, "_x_x_x_x_bach_float64_x_x_x_x_", 50990, 3220299075, "_x_x_x_x_bach_float64_x_x_x_x_", 57792, 1070472240, "_x_x_x_x_bach_float64_x_x_x_x_", 58766, 3220264299, "_x_x_x_x_bach_float64_x_x_x_x_", 63040, 1070556210, "_x_x_x_x_bach_float64_x_x_x_x_", 21114, 3220229434, "_x_x_x_x_bach_float64_x_x_x_x_", 1376, 1070618138, "_x_x_x_x_bach_float64_x_x_x_x_", 31946, 3220194485, "_x_x_x_x_bach_float64_x_x_x_x_", 4000, 1070660123, "_x_x_x_x_bach_float64_x_x_x_x_", 16970, 3220142015, "_x_x_x_x_bach_float64_x_x_x_x_", 6624, 1070702108, "_x_x_x_x_bach_float64_x_x_x_x_", 50695, 3220071805, "_x_x_x_x_bach_float64_x_x_x_x_", 9248, 1070744093, "_x_x_x_x_bach_float64_x_x_x_x_", 45171, 3220001453, "_x_x_x_x_bach_float64_x_x_x_x_", 11872, 1070786078, "_x_x_x_x_bach_float64_x_x_x_x_", 3995, 3219930969, "_x_x_x_x_bach_float64_x_x_x_x_", 14496, 1070828063, "_x_x_x_x_bach_float64_x_x_x_x_", 47524, 3219860361, "_x_x_x_x_bach_float64_x_x_x_x_", 17120, 1070870048, "_x_x_x_x_bach_float64_x_x_x_x_", 7247, 3219789639, "_x_x_x_x_bach_float64_x_x_x_x_", 19744, 1070912033, "_x_x_x_x_bach_float64_x_x_x_x_", 63378, 3219718811, "_x_x_x_x_bach_float64_x_x_x_x_", 22368, 1070954018, "_x_x_x_x_bach_float64_x_x_x_x_", 1280, 3219647888, "_x_x_x_x_bach_float64_x_x_x_x_", 25008, 1070996003, "_x_x_x_x_bach_float64_x_x_x_x_", 36194, 3219576879, "_x_x_x_x_bach_float64_x_x_x_x_", 27616, 1071037988, "_x_x_x_x_bach_float64_x_x_x_x_", 61132, 3219505792, "_x_x_x_x_bach_float64_x_x_x_x_", 30240, 1071079973, "_x_x_x_x_bach_float64_x_x_x_x_", 4734, 3219434636, "_x_x_x_x_bach_float64_x_x_x_x_", 32864, 1071121958, "_x_x_x_x_bach_float64_x_x_x_x_", 55265, 3219363422, "_x_x_x_x_bach_float64_x_x_x_x_", 35488, 1071163943, "_x_x_x_x_bach_float64_x_x_x_x_", 29286, 3219292158, "_x_x_x_x_bach_float64_x_x_x_x_", 38128, 1071205928, "_x_x_x_x_bach_float64_x_x_x_x_", 48642, 3219220853, "_x_x_x_x_bach_float64_x_x_x_x_", 40736, 1071247913, "_x_x_x_x_bach_float64_x_x_x_x_", 35793, 3219149517, "_x_x_x_x_bach_float64_x_x_x_x_", 43360, 1071289898, "_x_x_x_x_bach_float64_x_x_x_x_", 52377, 3219027999, "_x_x_x_x_bach_float64_x_x_x_x_", 45984, 1071331883, "_x_x_x_x_bach_float64_x_x_x_x_", 42180, 3218885258, "_x_x_x_x_bach_float64_x_x_x_x_", 48608, 1071373868, "_x_x_x_x_bach_float64_x_x_x_x_", 5744, 3218742510, "_x_x_x_x_bach_float64_x_x_x_x_", 51248, 1071415853, "_x_x_x_x_bach_float64_x_x_x_x_", 30898, 3218599773, "_x_x_x_x_bach_float64_x_x_x_x_", 53856, 1071457838, "_x_x_x_x_bach_float64_x_x_x_x_", 30620, 3218457067, "_x_x_x_x_bach_float64_x_x_x_x_", 56480, 1071499823, "_x_x_x_x_bach_float64_x_x_x_x_", 34612, 3218314409, "_x_x_x_x_bach_float64_x_x_x_x_", 59104, 1071541808, "_x_x_x_x_bach_float64_x_x_x_x_", 24508, 3218171818, "_x_x_x_x_bach_float64_x_x_x_x_", 61728, 1071583793, "_x_x_x_x_bach_float64_x_x_x_x_", 64989, 3217978881, "_x_x_x_x_bach_float64_x_x_x_x_", 64368, 1071625778, "_x_x_x_x_bach_float64_x_x_x_x_", 27472, 3217694078, "_x_x_x_x_bach_float64_x_x_x_x_", 720, 1071656217, "_x_x_x_x_bach_float64_x_x_x_x_", 35300, 3217409520, "_x_x_x_x_bach_float64_x_x_x_x_", 2032, 1071677210, "_x_x_x_x_bach_float64_x_x_x_x_", 4842, 3217125244, "_x_x_x_x_bach_float64_x_x_x_x_", 3344, 1071698202, "_x_x_x_x_bach_float64_x_x_x_x_", 65296, 3216651406, "_x_x_x_x_bach_float64_x_x_x_x_", 4656, 1071719195, "_x_x_x_x_bach_float64_x_x_x_x_", 29924, 3216084202, "_x_x_x_x_bach_float64_x_x_x_x_", 5976, 1071740187, "_x_x_x_x_bach_float64_x_x_x_x_", 9712, 3215052977, "_x_x_x_x_bach_float64_x_x_x_x_", 7280, 1071761180, "_x_x_x_x_bach_float64_x_x_x_x_", 36352, 3209807956, "_x_x_x_x_bach_float64_x_x_x_x_", 8592, 1071782172, "_x_x_x_x_bach_float64_x_x_x_x_", 20608, 1067494628, "_x_x_x_x_bach_float64_x_x_x_x_", 9904, 1071803165, "_x_x_x_x_bach_float64_x_x_x_x_", 4912, 1068560407, "_x_x_x_x_bach_float64_x_x_x_x_", 11216, 1071824157, "_x_x_x_x_bach_float64_x_x_x_x_", 39024, 1069122951, "_x_x_x_x_bach_float64_x_x_x_x_", 12536, 1071845150, "_x_x_x_x_bach_float64_x_x_x_x_", 37740, 1069615931, "_x_x_x_x_bach_float64_x_x_x_x_", 13840, 1071866143, "_x_x_x_x_bach_float64_x_x_x_x_", 64808, 1069896014, "_x_x_x_x_bach_float64_x_x_x_x_", 15152, 1071887135, "_x_x_x_x_bach_float64_x_x_x_x_", 33536, 1070175448, "_x_x_x_x_bach_float64_x_x_x_x_", 16464, 1071908128, "_x_x_x_x_bach_float64_x_x_x_x_", 8, 1070454196, "_x_x_x_x_bach_float64_x_x_x_x_", 17776, 1071929120, "_x_x_x_x_bach_float64_x_x_x_x_", 42916, 1070664159, "_x_x_x_x_bach_float64_x_x_x_x_", 19096, 1071950113, "_x_x_x_x_bach_float64_x_x_x_x_", 64116, 1070802794, "_x_x_x_x_bach_float64_x_x_x_x_", 20400, 1071971105, "_x_x_x_x_bach_float64_x_x_x_x_", 9688, 1070941031, "_x_x_x_x_bach_float64_x_x_x_x_", 21712, 1071992098, "_x_x_x_x_bach_float64_x_x_x_x_", 40048, 1071078853, "_x_x_x_x_bach_float64_x_x_x_x_", 23024, 1072013090, "_x_x_x_x_bach_float64_x_x_x_x_", 10512, 1071216242, "_x_x_x_x_bach_float64_x_x_x_x_", 24336, 1072034083, "_x_x_x_x_bach_float64_x_x_x_x_", 16108, 1071353179, "_x_x_x_x_bach_float64_x_x_x_x_", 25656, 1072055075, "_x_x_x_x_bach_float64_x_x_x_x_", 65440, 1071489648, "_x_x_x_x_bach_float64_x_x_x_x_", 26960, 1072076068, "_x_x_x_x_bach_float64_x_x_x_x_", 62560, 1071625630, "_x_x_x_x_bach_float64_x_x_x_x_", 28272, 1072097060, "_x_x_x_x_bach_float64_x_x_x_x_", 15752, 1071702889, "_x_x_x_x_bach_float64_x_x_x_x_", 29584, 1072118053, "_x_x_x_x_bach_float64_x_x_x_x_", 61096, 1071770366, "_x_x_x_x_bach_float64_x_x_x_x_", 30896, 1072139045, "_x_x_x_x_bach_float64_x_x_x_x_", 2760, 1071837573, "_x_x_x_x_bach_float64_x_x_x_x_", 32216, 1072160038, "_x_x_x_x_bach_float64_x_x_x_x_", 40330, 1071904501, "_x_x_x_x_bach_float64_x_x_x_x_", 33520, 1072181030, "_x_x_x_x_bach_float64_x_x_x_x_", 51454, 1071971141, "_x_x_x_x_bach_float64_x_x_x_x_", 34832, 1072202023, "_x_x_x_x_bach_float64_x_x_x_x_", 40986, 1072037485, "_x_x_x_x_bach_float64_x_x_x_x_", 36144, 1072223015, "_x_x_x_x_bach_float64_x_x_x_x_", 52948, 1072103523, "_x_x_x_x_bach_float64_x_x_x_x_", 37456, 1072244008, "_x_x_x_x_bach_float64_x_x_x_x_", 4508, 1072169247, "_x_x_x_x_bach_float64_x_x_x_x_", 38776, 1072265000, "_x_x_x_x_bach_float64_x_x_x_x_", 31000, 1072234649, "_x_x_x_x_bach_float64_x_x_x_x_", 40080, 1072285993, "_x_x_x_x_bach_float64_x_x_x_x_", 30808, 1072299719, "_x_x_x_x_bach_float64_x_x_x_x_", 41392, 1072306985, "_x_x_x_x_bach_float64_x_x_x_x_", 48686, 1072364448, "_x_x_x_x_bach_float64_x_x_x_x_", 42704, 1072327978, "_x_x_x_x_bach_float64_x_x_x_x_", 54468, 1072428830, "_x_x_x_x_bach_float64_x_x_x_x_", 44016, 1072348970, "_x_x_x_x_bach_float64_x_x_x_x_", 35168, 1072492854, "_x_x_x_x_bach_float64_x_x_x_x_", 45336, 1072369963, "_x_x_x_x_bach_float64_x_x_x_x_", 6396, 1072556513, "_x_x_x_x_bach_float64_x_x_x_x_", 46640, 1072390955, "_x_x_x_x_bach_float64_x_x_x_x_", 8220, 1072619797, "_x_x_x_x_bach_float64_x_x_x_x_", 47952, 1072411948, "_x_x_x_x_bach_float64_x_x_x_x_", 20122, 1072682699, "_x_x_x_x_bach_float64_x_x_x_x_", 49264, 1072432940, "_x_x_x_x_bach_float64_x_x_x_x_", 27965, 1072719228, "_x_x_x_x_bach_float64_x_x_x_x_", 50576, 1072453933, "_x_x_x_x_bach_float64_x_x_x_x_", 22997, 1072750284, "_x_x_x_x_bach_float64_x_x_x_x_", 51896, 1072474925, "_x_x_x_x_bach_float64_x_x_x_x_", 15039, 1072781136, "_x_x_x_x_bach_float64_x_x_x_x_", 53200, 1072495918, "_x_x_x_x_bach_float64_x_x_x_x_", 2612, 1072811780, "_x_x_x_x_bach_float64_x_x_x_x_", 54512, 1072516910, "_x_x_x_x_bach_float64_x_x_x_x_", 42030, 1072842211, "_x_x_x_x_bach_float64_x_x_x_x_", 55824, 1072537903, "_x_x_x_x_bach_float64_x_x_x_x_", 55216, 1072872427, "_x_x_x_x_bach_float64_x_x_x_x_", 57136, 1072558895, "_x_x_x_x_bach_float64_x_x_x_x_", 21754, 1072902422, "_x_x_x_x_bach_float64_x_x_x_x_", 58456, 1072579888, "_x_x_x_x_bach_float64_x_x_x_x_", 30480, 1072932193, "_x_x_x_x_bach_float64_x_x_x_x_", 59760, 1072600880, "_x_x_x_x_bach_float64_x_x_x_x_", 59402, 1072961735, "_x_x_x_x_bach_float64_x_x_x_x_", 61072, 1072621873, "_x_x_x_x_bach_float64_x_x_x_x_", 8214, 1072991045, "_x_x_x_x_bach_float64_x_x_x_x_", 62384, 1072642865, "_x_x_x_x_bach_float64_x_x_x_x_", 48466, 1073020118, "_x_x_x_x_bach_float64_x_x_x_x_", 63704, 1072663858, "_x_x_x_x_bach_float64_x_x_x_x_", 46334, 1073048952, "_x_x_x_x_bach_float64_x_x_x_x_", 65016, 1072684850, "_x_x_x_x_bach_float64_x_x_x_x_", 23706, 1073077541, "_x_x_x_x_bach_float64_x_x_x_x_", 392, 1072699545, "_x_x_x_x_bach_float64_x_x_x_x_", 19142, 1073105881, "_x_x_x_x_bach_float64_x_x_x_x_", 1048, 1072710042, "_x_x_x_x_bach_float64_x_x_x_x_", 3810, 1073133970, "_x_x_x_x_bach_float64_x_x_x_x_", 1704, 1072720538, "_x_x_x_x_bach_float64_x_x_x_x_", 48792, 1073161802, "_x_x_x_x_bach_float64_x_x_x_x_", 2364, 1072731034, "_x_x_x_x_bach_float64_x_x_x_x_", 22892, 1073189375, "_x_x_x_x_bach_float64_x_x_x_x_", 3020, 1072741530, "_x_x_x_x_bach_float64_x_x_x_x_", 166, 1073216684, "_x_x_x_x_bach_float64_x_x_x_x_", 3672, 1072752027, "_x_x_x_x_bach_float64_x_x_x_x_", 1034, 1073243726, "_x_x_x_x_bach_float64_x_x_x_x_", 4328, 1072762523, "_x_x_x_x_bach_float64_x_x_x_x_", 49612, 1073270497, "_x_x_x_x_bach_float64_x_x_x_x_", 4984, 1072773019, "_x_x_x_x_bach_float64_x_x_x_x_", 22886, 1073296992, "_x_x_x_x_bach_float64_x_x_x_x_", 5644, 1072783515, "_x_x_x_x_bach_float64_x_x_x_x_", 12546, 1073323209, "_x_x_x_x_bach_float64_x_x_x_x_", 6300, 1072794012, "_x_x_x_x_bach_float64_x_x_x_x_", 19550, 1073349144, "_x_x_x_x_bach_float64_x_x_x_x_", 6952, 1072804508, "_x_x_x_x_bach_float64_x_x_x_x_", 29954, 1073374793, "_x_x_x_x_bach_float64_x_x_x_x_", 7608, 1072815004, "_x_x_x_x_bach_float64_x_x_x_x_", 12986, 1073400152, "_x_x_x_x_bach_float64_x_x_x_x_", 8264, 1072825500, "_x_x_x_x_bach_float64_x_x_x_x_", 37840, 1073425218, "_x_x_x_x_bach_float64_x_x_x_x_", 8924, 1072835997, "_x_x_x_x_bach_float64_x_x_x_x_", 50362, 1073449987, "_x_x_x_x_bach_float64_x_x_x_x_", 9580, 1072846493, "_x_x_x_x_bach_float64_x_x_x_x_", 30250, 1073474456, "_x_x_x_x_bach_float64_x_x_x_x_", 10232, 1072856989, "_x_x_x_x_bach_float64_x_x_x_x_", 4454, 1073498622, "_x_x_x_x_bach_float64_x_x_x_x_", 10888, 1072867485, "_x_x_x_x_bach_float64_x_x_x_x_", 47598, 1073522480, "_x_x_x_x_bach_float64_x_x_x_x_", 11544, 1072877982, "_x_x_x_x_bach_float64_x_x_x_x_", 7108, 1073546027, "_x_x_x_x_bach_float64_x_x_x_x_", 12204, 1072888478, "_x_x_x_x_bach_float64_x_x_x_x_", 1612, 1073569260, "_x_x_x_x_bach_float64_x_x_x_x_", 12860, 1072898974, "_x_x_x_x_bach_float64_x_x_x_x_", 53890, 1073592176, "_x_x_x_x_bach_float64_x_x_x_x_", 13512, 1072909470, "_x_x_x_x_bach_float64_x_x_x_x_", 38044, 1073614771, "_x_x_x_x_bach_float64_x_x_x_x_", 14168, 1072919967, "_x_x_x_x_bach_float64_x_x_x_x_", 6156, 1073637042, "_x_x_x_x_bach_float64_x_x_x_x_", 14824, 1072930463, "_x_x_x_x_bach_float64_x_x_x_x_", 42316, 1073658985, "_x_x_x_x_bach_float64_x_x_x_x_", 15484, 1072940959, "_x_x_x_x_bach_float64_x_x_x_x_", 37206, 1073680598, "_x_x_x_x_bach_float64_x_x_x_x_", 16140, 1072951455, "_x_x_x_x_bach_float64_x_x_x_x_", 38340, 1073701877, "_x_x_x_x_bach_float64_x_x_x_x_", 16792, 1072961952, "_x_x_x_x_bach_float64_x_x_x_x_", 61806, 1073722819, "_x_x_x_x_bach_float64_x_x_x_x_", 17448, 1072972448, "_x_x_x_x_bach_float64_x_x_x_x_", 10326, 1073742622, "_x_x_x_x_bach_float64_x_x_x_x_", 18104, 1072982944, "_x_x_x_x_bach_float64_x_x_x_x_", 15962, 1073752751, "_x_x_x_x_bach_float64_x_x_x_x_", 18764, 1072993440, "_x_x_x_x_bach_float64_x_x_x_x_", 59638, 1073762707, "_x_x_x_x_bach_float64_x_x_x_x_", 19420, 1073003937, "_x_x_x_x_bach_float64_x_x_x_x_", 15889, 1073772488, "_x_x_x_x_bach_float64_x_x_x_x_", 20072, 1073014433, "_x_x_x_x_bach_float64_x_x_x_x_", 48211, 1073782093, "_x_x_x_x_bach_float64_x_x_x_x_", 20728, 1073024929, "_x_x_x_x_bach_float64_x_x_x_x_", 11968, 1073791520, "_x_x_x_x_bach_float64_x_x_x_x_", 21384, 1073035425, "_x_x_x_x_bach_float64_x_x_x_x_", 29308, 1073800768, "_x_x_x_x_bach_float64_x_x_x_x_", 22044, 1073045922, "_x_x_x_x_bach_float64_x_x_x_x_", 7895, 1073809836, "_x_x_x_x_bach_float64_x_x_x_x_", 22700, 1073056418, "_x_x_x_x_bach_float64_x_x_x_x_", 3839, 1073818721, "_x_x_x_x_bach_float64_x_x_x_x_", 23352, 1073066914, "_x_x_x_x_bach_float64_x_x_x_x_", 52572, 1073827423, "_x_x_x_x_bach_float64_x_x_x_x_", 24008, 1073077410, "_x_x_x_x_bach_float64_x_x_x_x_", 57414, 1073835939, "_x_x_x_x_bach_float64_x_x_x_x_", 24664, 1073087907, "_x_x_x_x_bach_float64_x_x_x_x_", 63408, 1073844270, "_x_x_x_x_bach_float64_x_x_x_x_", 25324, 1073098403, "_x_x_x_x_bach_float64_x_x_x_x_", 64461, 1073852413, "_x_x_x_x_bach_float64_x_x_x_x_", 25980, 1073108899, "_x_x_x_x_bach_float64_x_x_x_x_", 64581, 1073860367, "_x_x_x_x_bach_float64_x_x_x_x_", 26632, 1073119396, "_x_x_x_x_bach_float64_x_x_x_x_", 65507, 1073868131, "_x_x_x_x_bach_float64_x_x_x_x_", 27288, 1073129892, "_x_x_x_x_bach_float64_x_x_x_x_", 46170, 1073875703, "_x_x_x_x_bach_float64_x_x_x_x_", 27944, 1073140388, "_x_x_x_x_bach_float64_x_x_x_x_", 65016, 1073883082, "_x_x_x_x_bach_float64_x_x_x_x_", 28604, 1073150884, "_x_x_x_x_bach_float64_x_x_x_x_", 26408, 1073890267, "_x_x_x_x_bach_float64_x_x_x_x_", 29260, 1073161381, "_x_x_x_x_bach_float64_x_x_x_x_", 28513, 1073897257, "_x_x_x_x_bach_float64_x_x_x_x_", 29912, 1073171877, "_x_x_x_x_bach_float64_x_x_x_x_", 47475, 1073904050, "_x_x_x_x_bach_float64_x_x_x_x_", 30568, 1073182373, "_x_x_x_x_bach_float64_x_x_x_x_", 6377, 1073910645, "_x_x_x_x_bach_float64_x_x_x_x_", 31224, 1073192869, "_x_x_x_x_bach_float64_x_x_x_x_", 32302, 1073917041, "_x_x_x_x_bach_float64_x_x_x_x_", 31884, 1073203366, "_x_x_x_x_bach_float64_x_x_x_x_", 49546, 1073923237, "_x_x_x_x_bach_float64_x_x_x_x_", 32540, 1073213862, "_x_x_x_x_bach_float64_x_x_x_x_", 19577, 1073929232, "_x_x_x_x_bach_float64_x_x_x_x_", 33192, 1073224358, "_x_x_x_x_bach_float64_x_x_x_x_", 41309, 1073935024, "_x_x_x_x_bach_float64_x_x_x_x_", 33848, 1073234854, "_x_x_x_x_bach_float64_x_x_x_x_", 49475, 1073940612, "_x_x_x_x_bach_float64_x_x_x_x_", 34504, 1073245351, "_x_x_x_x_bach_float64_x_x_x_x_", 28539, 1073945996, "_x_x_x_x_bach_float64_x_x_x_x_", 35164, 1073255847, "_x_x_x_x_bach_float64_x_x_x_x_", 21251, 1073951175, "_x_x_x_x_bach_float64_x_x_x_x_", 35820, 1073266343, "_x_x_x_x_bach_float64_x_x_x_x_", 62813, 1073956146, "_x_x_x_x_bach_float64_x_x_x_x_", 36472, 1073276839, "_x_x_x_x_bach_float64_x_x_x_x_", 40664, 1073960910, "_x_x_x_x_bach_float64_x_x_x_x_", 37128, 1073287336, "_x_x_x_x_bach_float64_x_x_x_x_", 4088, 1073965465, "_x_x_x_x_bach_float64_x_x_x_x_", 37788, 1073297832, "_x_x_x_x_bach_float64_x_x_x_x_", 6102, 1073969810, "_x_x_x_x_bach_float64_x_x_x_x_", 38444, 1073308328, "_x_x_x_x_bach_float64_x_x_x_x_", 1890, 1073973944, "_x_x_x_x_bach_float64_x_x_x_x_", 39100, 1073318824, "_x_x_x_x_bach_float64_x_x_x_x_", 334, 1073977867, "_x_x_x_x_bach_float64_x_x_x_x_", 39752, 1073329321, "_x_x_x_x_bach_float64_x_x_x_x_", 9844, 1073981577, "_x_x_x_x_bach_float64_x_x_x_x_", 40408, 1073339817, "_x_x_x_x_bach_float64_x_x_x_x_", 40602, 1073985073, "_x_x_x_x_bach_float64_x_x_x_x_", 41068, 1073350313, "_x_x_x_x_bach_float64_x_x_x_x_", 32098, 1073988356, "_x_x_x_x_bach_float64_x_x_x_x_", 41724, 1073360809, "_x_x_x_x_bach_float64_x_x_x_x_", 33598, 1073991423, "_x_x_x_x_bach_float64_x_x_x_x_", 42380, 1073371306, "_x_x_x_x_bach_float64_x_x_x_x_", 47718, 1073994274, "_x_x_x_x_bach_float64_x_x_x_x_", 43032, 1073381802, "_x_x_x_x_bach_float64_x_x_x_x_", 61276, 1073996908, "_x_x_x_x_bach_float64_x_x_x_x_", 43688, 1073392298, "_x_x_x_x_bach_float64_x_x_x_x_", 1346, 1073999324, "_x_x_x_x_bach_float64_x_x_x_x_", 44348, 1073402794, "_x_x_x_x_bach_float64_x_x_x_x_", 9594, 1074001522, "_x_x_x_x_bach_float64_x_x_x_x_", 45004, 1073413291, "_x_x_x_x_bach_float64_x_x_x_x_", 51894, 1074003501, "_x_x_x_x_bach_float64_x_x_x_x_", 45660, 1073423787, "_x_x_x_x_bach_float64_x_x_x_x_", 42814, 1074005260, "_x_x_x_x_bach_float64_x_x_x_x_", 46312, 1073434283, "_x_x_x_x_bach_float64_x_x_x_x_", 26168, 1074006799, "_x_x_x_x_bach_float64_x_x_x_x_", 46968, 1073444779, "_x_x_x_x_bach_float64_x_x_x_x_", 18434, 1074008116, "_x_x_x_x_bach_float64_x_x_x_x_", 47628, 1073455276, "_x_x_x_x_bach_float64_x_x_x_x_", 39236, 1074009211, "_x_x_x_x_bach_float64_x_x_x_x_", 48284, 1073465772, "_x_x_x_x_bach_float64_x_x_x_x_", 1242, 1074010083, "_x_x_x_x_bach_float64_x_x_x_x_", 48940, 1073476268, "_x_x_x_x_bach_float64_x_x_x_x_", 49220, 1074010733, "_x_x_x_x_bach_float64_x_x_x_x_", 49592, 1073486764, "_x_x_x_x_bach_float64_x_x_x_x_", 37544, 1074011159, "_x_x_x_x_bach_float64_x_x_x_x_", 50248, 1073497261, "_x_x_x_x_bach_float64_x_x_x_x_", 46648, 1074011360, "_x_x_x_x_bach_float64_x_x_x_x_", 50908, 1073507757, "_x_x_x_x_bach_float64_x_x_x_x_", 37862, 1074011336, "_x_x_x_x_bach_float64_x_x_x_x_", 51564, 1073518253, "_x_x_x_x_bach_float64_x_x_x_x_", 22852, 1074011087, "_x_x_x_x_bach_float64_x_x_x_x_", 52220, 1073528749, "_x_x_x_x_bach_float64_x_x_x_x_", 26778, 1074010612, "_x_x_x_x_bach_float64_x_x_x_x_", 52872, 1073539246, "_x_x_x_x_bach_float64_x_x_x_x_", 41710, 1074009911, "_x_x_x_x_bach_float64_x_x_x_x_", 53528, 1073549742, "_x_x_x_x_bach_float64_x_x_x_x_", 35848, 1074008983, "_x_x_x_x_bach_float64_x_x_x_x_", 54188, 1073560238, "_x_x_x_x_bach_float64_x_x_x_x_" ],
									"whole_graph_data_0000000001" : [ 18516, 1074007827, "_x_x_x_x_bach_float64_x_x_x_x_", 54844, 1073570735, "_x_x_x_x_bach_float64_x_x_x_x_", 29834, 1074006444, "_x_x_x_x_bach_float64_x_x_x_x_", 55500, 1073581231, "_x_x_x_x_bach_float64_x_x_x_x_", 55058, 1074004833, "_x_x_x_x_bach_float64_x_x_x_x_", 56152, 1073591727, "_x_x_x_x_bach_float64_x_x_x_x_", 60168, 1074002993, "_x_x_x_x_bach_float64_x_x_x_x_", 56808, 1073602223, "_x_x_x_x_bach_float64_x_x_x_x_", 17632, 1074000925, "_x_x_x_x_bach_float64_x_x_x_x_", 57468, 1073612720, "_x_x_x_x_bach_float64_x_x_x_x_", 53374, 1073998628, "_x_x_x_x_bach_float64_x_x_x_x_", 58124, 1073623216, "_x_x_x_x_bach_float64_x_x_x_x_", 59610, 1073996101, "_x_x_x_x_bach_float64_x_x_x_x_", 58780, 1073633712, "_x_x_x_x_bach_float64_x_x_x_x_", 18678, 1073993344, "_x_x_x_x_bach_float64_x_x_x_x_", 59432, 1073644208, "_x_x_x_x_bach_float64_x_x_x_x_", 54852, 1073990357, "_x_x_x_x_bach_float64_x_x_x_x_", 60088, 1073654705, "_x_x_x_x_bach_float64_x_x_x_x_", 17486, 1073987141, "_x_x_x_x_bach_float64_x_x_x_x_", 60748, 1073665201, "_x_x_x_x_bach_float64_x_x_x_x_", 37296, 1073983694, "_x_x_x_x_bach_float64_x_x_x_x_", 61404, 1073675697, "_x_x_x_x_bach_float64_x_x_x_x_", 24134, 1073980016, "_x_x_x_x_bach_float64_x_x_x_x_", 62060, 1073686193, "_x_x_x_x_bach_float64_x_x_x_x_", 6792, 1073976108, "_x_x_x_x_bach_float64_x_x_x_x_", 62712, 1073696690, "_x_x_x_x_bach_float64_x_x_x_x_", 4126, 1073971969, "_x_x_x_x_bach_float64_x_x_x_x_", 63368, 1073707186, "_x_x_x_x_bach_float64_x_x_x_x_", 17296, 1073967599, "_x_x_x_x_bach_float64_x_x_x_x_", 64028, 1073717682, "_x_x_x_x_bach_float64_x_x_x_x_", 12056, 1073962998, "_x_x_x_x_bach_float64_x_x_x_x_", 64684, 1073728178, "_x_x_x_x_bach_float64_x_x_x_x_", 22162, 1073958166, "_x_x_x_x_bach_float64_x_x_x_x_", 65340, 1073738675, "_x_x_x_x_bach_float64_x_x_x_x_", 46188, 1073953103, "_x_x_x_x_bach_float64_x_x_x_x_", 32996, 1073745497, "_x_x_x_x_bach_float64_x_x_x_x_", 65490, 1073947808, "_x_x_x_x_bach_float64_x_x_x_x_", 33324, 1073750745, "_x_x_x_x_bach_float64_x_x_x_x_", 52158, 1073942283, "_x_x_x_x_bach_float64_x_x_x_x_", 33654, 1073755993, "_x_x_x_x_bach_float64_x_x_x_x_", 32570, 1073936526, "_x_x_x_x_bach_float64_x_x_x_x_", 33982, 1073761242, "_x_x_x_x_bach_float64_x_x_x_x_", 9900, 1073930539, "_x_x_x_x_bach_float64_x_x_x_x_", 34310, 1073766490, "_x_x_x_x_bach_float64_x_x_x_x_", 7714, 1073924320, "_x_x_x_x_bach_float64_x_x_x_x_", 34636, 1073771738, "_x_x_x_x_bach_float64_x_x_x_x_", 38096, 1073917870, "_x_x_x_x_bach_float64_x_x_x_x_", 34964, 1073776986, "_x_x_x_x_bach_float64_x_x_x_x_", 59770, 1073911190, "_x_x_x_x_bach_float64_x_x_x_x_", 35294, 1073782234, "_x_x_x_x_bach_float64_x_x_x_x_", 57400, 1073904279, "_x_x_x_x_bach_float64_x_x_x_x_", 35622, 1073787482, "_x_x_x_x_bach_float64_x_x_x_x_", 45352, 1073897138, "_x_x_x_x_bach_float64_x_x_x_x_", 35950, 1073792730, "_x_x_x_x_bach_float64_x_x_x_x_", 61516, 1073889766, "_x_x_x_x_bach_float64_x_x_x_x_", 36276, 1073797978, "_x_x_x_x_bach_float64_x_x_x_x_", 20150, 1073882164, "_x_x_x_x_bach_float64_x_x_x_x_", 36604, 1073803227, "_x_x_x_x_bach_float64_x_x_x_x_", 13506, 1073874333, "_x_x_x_x_bach_float64_x_x_x_x_", 36934, 1073808475, "_x_x_x_x_bach_float64_x_x_x_x_", 13744, 1073866272, "_x_x_x_x_bach_float64_x_x_x_x_", 37262, 1073813723, "_x_x_x_x_bach_float64_x_x_x_x_", 23678, 1073857981, "_x_x_x_x_bach_float64_x_x_x_x_", 37590, 1073818971, "_x_x_x_x_bach_float64_x_x_x_x_", 21004, 1073849462, "_x_x_x_x_bach_float64_x_x_x_x_", 37916, 1073824219, "_x_x_x_x_bach_float64_x_x_x_x_", 23724, 1073840714, "_x_x_x_x_bach_float64_x_x_x_x_", 38244, 1073829467, "_x_x_x_x_bach_float64_x_x_x_x_", 14610, 1073831737, "_x_x_x_x_bach_float64_x_x_x_x_", 38574, 1073834715, "_x_x_x_x_bach_float64_x_x_x_x_", 52452, 1073822533, "_x_x_x_x_bach_float64_x_x_x_x_", 38902, 1073839963, "_x_x_x_x_bach_float64_x_x_x_x_", 45746, 1073813101, "_x_x_x_x_bach_float64_x_x_x_x_", 39230, 1073845212, "_x_x_x_x_bach_float64_x_x_x_x_", 40840, 1073803442, "_x_x_x_x_bach_float64_x_x_x_x_", 39556, 1073850460, "_x_x_x_x_bach_float64_x_x_x_x_", 41558, 1073793557, "_x_x_x_x_bach_float64_x_x_x_x_", 39888, 1073855708, "_x_x_x_x_bach_float64_x_x_x_x_", 15562, 1073783445, "_x_x_x_x_bach_float64_x_x_x_x_", 40214, 1073860956, "_x_x_x_x_bach_float64_x_x_x_x_", 22140, 1073773108, "_x_x_x_x_bach_float64_x_x_x_x_", 40542, 1073866204, "_x_x_x_x_bach_float64_x_x_x_x_", 2388, 1073762545, "_x_x_x_x_bach_float64_x_x_x_x_", 40870, 1073871452, "_x_x_x_x_bach_float64_x_x_x_x_", 18572, 1073751758, "_x_x_x_x_bach_float64_x_x_x_x_", 41196, 1073876700, "_x_x_x_x_bach_float64_x_x_x_x_", 49860, 1073739669, "_x_x_x_x_bach_float64_x_x_x_x_", 41528, 1073881949, "_x_x_x_x_bach_float64_x_x_x_x_", 44028, 1073717199, "_x_x_x_x_bach_float64_x_x_x_x_", 41854, 1073887197, "_x_x_x_x_bach_float64_x_x_x_x_", 9676, 1073694283, "_x_x_x_x_bach_float64_x_x_x_x_", 42182, 1073892445, "_x_x_x_x_bach_float64_x_x_x_x_", 64616, 1073670922, "_x_x_x_x_bach_float64_x_x_x_x_", 42510, 1073897693, "_x_x_x_x_bach_float64_x_x_x_x_", 50108, 1073647118, "_x_x_x_x_bach_float64_x_x_x_x_", 42836, 1073902941, "_x_x_x_x_bach_float64_x_x_x_x_", 24656, 1073622873, "_x_x_x_x_bach_float64_x_x_x_x_", 43168, 1073908189, "_x_x_x_x_bach_float64_x_x_x_x_", 17808, 1073598186, "_x_x_x_x_bach_float64_x_x_x_x_", 43494, 1073913437, "_x_x_x_x_bach_float64_x_x_x_x_", 27220, 1073573060, "_x_x_x_x_bach_float64_x_x_x_x_", 43822, 1073918685, "_x_x_x_x_bach_float64_x_x_x_x_", 61916, 1073547497, "_x_x_x_x_bach_float64_x_x_x_x_", 44150, 1073923934, "_x_x_x_x_bach_float64_x_x_x_x_", 35888, 1073521497, "_x_x_x_x_bach_float64_x_x_x_x_", 44476, 1073929182, "_x_x_x_x_bach_float64_x_x_x_x_", 35828, 1073495063, "_x_x_x_x_bach_float64_x_x_x_x_", 44808, 1073934430, "_x_x_x_x_bach_float64_x_x_x_x_", 45772, 1073468195, "_x_x_x_x_bach_float64_x_x_x_x_", 45134, 1073939678, "_x_x_x_x_bach_float64_x_x_x_x_", 46404, 1073440896, "_x_x_x_x_bach_float64_x_x_x_x_", 45462, 1073944926, "_x_x_x_x_bach_float64_x_x_x_x_", 29796, 1073413167, "_x_x_x_x_bach_float64_x_x_x_x_", 45790, 1073950174, "_x_x_x_x_bach_float64_x_x_x_x_", 61456, 1073385011, "_x_x_x_x_bach_float64_x_x_x_x_", 46116, 1073955422, "_x_x_x_x_bach_float64_x_x_x_x_", 61468, 1073356428, "_x_x_x_x_bach_float64_x_x_x_x_", 46448, 1073960670, "_x_x_x_x_bach_float64_x_x_x_x_", 25936, 1073327420, "_x_x_x_x_bach_float64_x_x_x_x_", 46774, 1073965919, "_x_x_x_x_bach_float64_x_x_x_x_", 33664, 1073297990, "_x_x_x_x_bach_float64_x_x_x_x_", 47102, 1073971167, "_x_x_x_x_bach_float64_x_x_x_x_", 37526, 1073268139, "_x_x_x_x_bach_float64_x_x_x_x_", 47430, 1073976415, "_x_x_x_x_bach_float64_x_x_x_x_", 31228, 1073237870, "_x_x_x_x_bach_float64_x_x_x_x_", 47756, 1073981663, "_x_x_x_x_bach_float64_x_x_x_x_", 1092, 1073207183, "_x_x_x_x_bach_float64_x_x_x_x_", 48088, 1073986911, "_x_x_x_x_bach_float64_x_x_x_x_", 56386, 1073176082, "_x_x_x_x_bach_float64_x_x_x_x_", 48414, 1073992159, "_x_x_x_x_bach_float64_x_x_x_x_", 17640, 1073144568, "_x_x_x_x_bach_float64_x_x_x_x_", 48742, 1073997407, "_x_x_x_x_bach_float64_x_x_x_x_", 35222, 1073112644, "_x_x_x_x_bach_float64_x_x_x_x_", 49070, 1074002655, "_x_x_x_x_bach_float64_x_x_x_x_", 10902, 1073080311, "_x_x_x_x_bach_float64_x_x_x_x_", 49396, 1074007904, "_x_x_x_x_bach_float64_x_x_x_x_", 50046, 1073047572, "_x_x_x_x_bach_float64_x_x_x_x_", 49728, 1074013152, "_x_x_x_x_bach_float64_x_x_x_x_", 44212, 1073014429, "_x_x_x_x_bach_float64_x_x_x_x_", 50054, 1074018400, "_x_x_x_x_bach_float64_x_x_x_x_", 22924, 1072980884, "_x_x_x_x_bach_float64_x_x_x_x_", 50382, 1074023648, "_x_x_x_x_bach_float64_x_x_x_x_", 28838, 1072946940, "_x_x_x_x_bach_float64_x_x_x_x_", 50710, 1074028896, "_x_x_x_x_bach_float64_x_x_x_x_", 41544, 1072912598, "_x_x_x_x_bach_float64_x_x_x_x_", 51036, 1074034144, "_x_x_x_x_bach_float64_x_x_x_x_", 14966, 1072877862, "_x_x_x_x_bach_float64_x_x_x_x_", 51368, 1074039392, "_x_x_x_x_bach_float64_x_x_x_x_", 28730, 1072842734, "_x_x_x_x_bach_float64_x_x_x_x_", 51694, 1074044640, "_x_x_x_x_bach_float64_x_x_x_x_", 29528, 1072807216, "_x_x_x_x_bach_float64_x_x_x_x_", 52022, 1074049889, "_x_x_x_x_bach_float64_x_x_x_x_", 13872, 1072771310, "_x_x_x_x_bach_float64_x_x_x_x_", 52350, 1074055137, "_x_x_x_x_bach_float64_x_x_x_x_", 63430, 1072735020, "_x_x_x_x_bach_float64_x_x_x_x_", 52676, 1074060385, "_x_x_x_x_bach_float64_x_x_x_x_", 35726, 1072698347, "_x_x_x_x_bach_float64_x_x_x_x_", 53008, 1074065633, "_x_x_x_x_bach_float64_x_x_x_x_", 49288, 1072629343, "_x_x_x_x_bach_float64_x_x_x_x_", 53334, 1074070881, "_x_x_x_x_bach_float64_x_x_x_x_", 36692, 1072554486, "_x_x_x_x_bach_float64_x_x_x_x_", 53662, 1074076129, "_x_x_x_x_bach_float64_x_x_x_x_", 63596, 1072478879, "_x_x_x_x_bach_float64_x_x_x_x_", 53990, 1074081377, "_x_x_x_x_bach_float64_x_x_x_x_", 53992, 1072402530, "_x_x_x_x_bach_float64_x_x_x_x_", 54316, 1074086626, "_x_x_x_x_bach_float64_x_x_x_x_", 26632, 1072325444, "_x_x_x_x_bach_float64_x_x_x_x_", 54648, 1074091874, "_x_x_x_x_bach_float64_x_x_x_x_", 1620, 1072247626, "_x_x_x_x_bach_float64_x_x_x_x_", 54974, 1074097122, "_x_x_x_x_bach_float64_x_x_x_x_", 6848, 1072169082, "_x_x_x_x_bach_float64_x_x_x_x_", 55302, 1074102370, "_x_x_x_x_bach_float64_x_x_x_x_", 51868, 1072089817, "_x_x_x_x_bach_float64_x_x_x_x_", 55630, 1074107618, "_x_x_x_x_bach_float64_x_x_x_x_", 5900, 1072009838, "_x_x_x_x_bach_float64_x_x_x_x_", 55956, 1074112866, "_x_x_x_x_bach_float64_x_x_x_x_", 34064, 1071929151, "_x_x_x_x_bach_float64_x_x_x_x_", 56288, 1074118114, "_x_x_x_x_bach_float64_x_x_x_x_", 19764, 1071847761, "_x_x_x_x_bach_float64_x_x_x_x_", 56614, 1074123362, "_x_x_x_x_bach_float64_x_x_x_x_", 5648, 1071765674, "_x_x_x_x_bach_float64_x_x_x_x_", 56942, 1074128611, "_x_x_x_x_bach_float64_x_x_x_x_", 13428, 1071682897, "_x_x_x_x_bach_float64_x_x_x_x_", 57270, 1074133859, "_x_x_x_x_bach_float64_x_x_x_x_", 62704, 1071554201, "_x_x_x_x_bach_float64_x_x_x_x_", 57596, 1074139107, "_x_x_x_x_bach_float64_x_x_x_x_", 8040, 1071385923, "_x_x_x_x_bach_float64_x_x_x_x_", 57928, 1074144355, "_x_x_x_x_bach_float64_x_x_x_x_", 44200, 1071216301, "_x_x_x_x_bach_float64_x_x_x_x_", 58254, 1074149603, "_x_x_x_x_bach_float64_x_x_x_x_", 49392, 1071045350, "_x_x_x_x_bach_float64_x_x_x_x_", 58582, 1074154851, "_x_x_x_x_bach_float64_x_x_x_x_", 57312, 1070873081, "_x_x_x_x_bach_float64_x_x_x_x_", 58910, 1074160099, "_x_x_x_x_bach_float64_x_x_x_x_", 5392, 1070699507, "_x_x_x_x_bach_float64_x_x_x_x_", 59236, 1074165347, "_x_x_x_x_bach_float64_x_x_x_x_", 29360, 1070453189, "_x_x_x_x_bach_float64_x_x_x_x_", 59568, 1074170596, "_x_x_x_x_bach_float64_x_x_x_x_", 47344, 1070100903, "_x_x_x_x_bach_float64_x_x_x_x_", 59894, 1074175844, "_x_x_x_x_bach_float64_x_x_x_x_", 46304, 1069746089, "_x_x_x_x_bach_float64_x_x_x_x_", 60222, 1074181092, "_x_x_x_x_bach_float64_x_x_x_x_", 16928, 1069230026, "_x_x_x_x_bach_float64_x_x_x_x_", 60550, 1074186340, "_x_x_x_x_bach_float64_x_x_x_x_", 6592, 1068510444, "_x_x_x_x_bach_float64_x_x_x_x_", 60880, 1074191588, "_x_x_x_x_bach_float64_x_x_x_x_", 60032, 1066695621, "_x_x_x_x_bach_float64_x_x_x_x_", 61208, 1074196836, "_x_x_x_x_bach_float64_x_x_x_x_", 23424, 3214411711, "_x_x_x_x_bach_float64_x_x_x_x_", 61534, 1074202084, "_x_x_x_x_bach_float64_x_x_x_x_", 21024, 3216061822, "_x_x_x_x_bach_float64_x_x_x_x_", 61862, 1074207332, "_x_x_x_x_bach_float64_x_x_x_x_", 35168, 3216800642, "_x_x_x_x_bach_float64_x_x_x_x_", 62190, 1074212581, "_x_x_x_x_bach_float64_x_x_x_x_", 21504, 3217287648, "_x_x_x_x_bach_float64_x_x_x_x_", 62520, 1074217829, "_x_x_x_x_bach_float64_x_x_x_x_", 44112, 3217661697, "_x_x_x_x_bach_float64_x_x_x_x_", 62848, 1074223077, "_x_x_x_x_bach_float64_x_x_x_x_", 55504, 3218038022, "_x_x_x_x_bach_float64_x_x_x_x_", 63174, 1074228325, "_x_x_x_x_bach_float64_x_x_x_x_", 32112, 3218248168, "_x_x_x_x_bach_float64_x_x_x_x_", 63502, 1074233573, "_x_x_x_x_bach_float64_x_x_x_x_", 5000, 3218438563, "_x_x_x_x_bach_float64_x_x_x_x_", 63830, 1074238821, "_x_x_x_x_bach_float64_x_x_x_x_", 7320, 3218630050, "_x_x_x_x_bach_float64_x_x_x_x_", 64160, 1074244069, "_x_x_x_x_bach_float64_x_x_x_x_", 4656, 3218822617, "_x_x_x_x_bach_float64_x_x_x_x_", 64488, 1074249317, "_x_x_x_x_bach_float64_x_x_x_x_", 54896, 3219016247, "_x_x_x_x_bach_float64_x_x_x_x_", 64814, 1074254566, "_x_x_x_x_bach_float64_x_x_x_x_", 25844, 3219169623, "_x_x_x_x_bach_float64_x_x_x_x_", 65142, 1074259814, "_x_x_x_x_bach_float64_x_x_x_x_", 51584, 3219267479, "_x_x_x_x_bach_float64_x_x_x_x_", 65470, 1074265062, "_x_x_x_x_bach_float64_x_x_x_x_", 51792, 3219365843, "_x_x_x_x_bach_float64_x_x_x_x_", 264, 1074270310, "_x_x_x_x_bach_float64_x_x_x_x_", 2756, 3219464709, "_x_x_x_x_bach_float64_x_x_x_x_", 592, 1074275558, "_x_x_x_x_bach_float64_x_x_x_x_", 34900, 3219564069, "_x_x_x_x_bach_float64_x_x_x_x_", 920, 1074280806, "_x_x_x_x_bach_float64_x_x_x_x_", 55404, 3219663913, "_x_x_x_x_bach_float64_x_x_x_x_", 1248, 1074286054, "_x_x_x_x_bach_float64_x_x_x_x_", 47156, 3219764236, "_x_x_x_x_bach_float64_x_x_x_x_", 1572, 1074291303, "_x_x_x_x_bach_float64_x_x_x_x_", 61044, 3219865027, "_x_x_x_x_bach_float64_x_x_x_x_", 1904, 1074296551, "_x_x_x_x_bach_float64_x_x_x_x_", 32624, 3219966281, "_x_x_x_x_bach_float64_x_x_x_x_", 2232, 1074301799, "_x_x_x_x_bach_float64_x_x_x_x_", 11152, 3220067988, "_x_x_x_x_bach_float64_x_x_x_x_", 2560, 1074307047, "_x_x_x_x_bach_float64_x_x_x_x_", 16816, 3220170140, "_x_x_x_x_bach_float64_x_x_x_x_", 2888, 1074312295, "_x_x_x_x_bach_float64_x_x_x_x_", 56484, 3220224813, "_x_x_x_x_bach_float64_x_x_x_x_", 3212, 1074317543, "_x_x_x_x_bach_float64_x_x_x_x_", 52382, 3220276322, "_x_x_x_x_bach_float64_x_x_x_x_", 3544, 1074322791, "_x_x_x_x_bach_float64_x_x_x_x_", 21738, 3220328042, "_x_x_x_x_bach_float64_x_x_x_x_", 3872, 1074328039, "_x_x_x_x_bach_float64_x_x_x_x_", 46381, 3220379969, "_x_x_x_x_bach_float64_x_x_x_x_", 4200, 1074333288, "_x_x_x_x_bach_float64_x_x_x_x_", 10731, 3220432097, "_x_x_x_x_bach_float64_x_x_x_x_", 4528, 1074338536, "_x_x_x_x_bach_float64_x_x_x_x_", 11852, 3220484424, "_x_x_x_x_bach_float64_x_x_x_x_", 4852, 1074343784, "_x_x_x_x_bach_float64_x_x_x_x_", 57543, 3220536944, "_x_x_x_x_bach_float64_x_x_x_x_", 5184, 1074349032, "_x_x_x_x_bach_float64_x_x_x_x_", 35293, 3220589654, "_x_x_x_x_bach_float64_x_x_x_x_", 5512, 1074354280, "_x_x_x_x_bach_float64_x_x_x_x_", 16693, 3220642550, "_x_x_x_x_bach_float64_x_x_x_x_", 5840, 1074359528, "_x_x_x_x_bach_float64_x_x_x_x_", 46515, 3220695626, "_x_x_x_x_bach_float64_x_x_x_x_", 6168, 1074364776, "_x_x_x_x_bach_float64_x_x_x_x_", 4747, 3220748880, "_x_x_x_x_bach_float64_x_x_x_x_", 6492, 1074370024, "_x_x_x_x_bach_float64_x_x_x_x_", 898, 3220802306, "_x_x_x_x_bach_float64_x_x_x_x_", 6824, 1074375273, "_x_x_x_x_bach_float64_x_x_x_x_", 55268, 3220855900, "_x_x_x_x_bach_float64_x_x_x_x_", 7152, 1074380521, "_x_x_x_x_bach_float64_x_x_x_x_", 49170, 3220909658, "_x_x_x_x_bach_float64_x_x_x_x_", 7480, 1074385769, "_x_x_x_x_bach_float64_x_x_x_x_", 10915, 3220963576, "_x_x_x_x_bach_float64_x_x_x_x_", 7808, 1074391017, "_x_x_x_x_bach_float64_x_x_x_x_", 15037, 3221017649, "_x_x_x_x_bach_float64_x_x_x_x_", 8132, 1074396265, "_x_x_x_x_bach_float64_x_x_x_x_", 23074, 3221071873, "_x_x_x_x_bach_float64_x_x_x_x_", 8464, 1074401513, "_x_x_x_x_bach_float64_x_x_x_x_", 58922, 3221126244, "_x_x_x_x_bach_float64_x_x_x_x_", 8792, 1074406761, "_x_x_x_x_bach_float64_x_x_x_x_", 62410, 3221180757, "_x_x_x_x_bach_float64_x_x_x_x_", 9120, 1074412009, "_x_x_x_x_bach_float64_x_x_x_x_", 6078, 3221230439, "_x_x_x_x_bach_float64_x_x_x_x_", 9448, 1074417258, "_x_x_x_x_bach_float64_x_x_x_x_", 59732, 3221257831, "_x_x_x_x_bach_float64_x_x_x_x_", 9772, 1074422506, "_x_x_x_x_bach_float64_x_x_x_x_", 55442, 3221285288, "_x_x_x_x_bach_float64_x_x_x_x_", 10104, 1074427754, "_x_x_x_x_bach_float64_x_x_x_x_", 44780, 3221312806, "_x_x_x_x_bach_float64_x_x_x_x_", 10432, 1074433002, "_x_x_x_x_bach_float64_x_x_x_x_", 45412, 3221340385, "_x_x_x_x_bach_float64_x_x_x_x_", 10760, 1074438250, "_x_x_x_x_bach_float64_x_x_x_x_", 18590, 3221368021, "_x_x_x_x_bach_float64_x_x_x_x_", 11088, 1074443498, "_x_x_x_x_bach_float64_x_x_x_x_", 45530, 3221395713, "_x_x_x_x_bach_float64_x_x_x_x_", 11412, 1074448746, "_x_x_x_x_bach_float64_x_x_x_x_", 47636, 3221423458, "_x_x_x_x_bach_float64_x_x_x_x_", 11744, 1074453994, "_x_x_x_x_bach_float64_x_x_x_x_", 33500, 3221451254, "_x_x_x_x_bach_float64_x_x_x_x_", 12072, 1074459243, "_x_x_x_x_bach_float64_x_x_x_x_", 20217, 3221479099, "_x_x_x_x_bach_float64_x_x_x_x_", 12400, 1074464491, "_x_x_x_x_bach_float64_x_x_x_x_", 22842, 3221506990, "_x_x_x_x_bach_float64_x_x_x_x_", 12728, 1074469739, "_x_x_x_x_bach_float64_x_x_x_x_", 45643, 3221534926, "_x_x_x_x_bach_float64_x_x_x_x_", 13052, 1074474987, "_x_x_x_x_bach_float64_x_x_x_x_", 9918, 3221562903, "_x_x_x_x_bach_float64_x_x_x_x_", 13384, 1074480235, "_x_x_x_x_bach_float64_x_x_x_x_", 11515, 3221590920, "_x_x_x_x_bach_float64_x_x_x_x_", 13712, 1074485483, "_x_x_x_x_bach_float64_x_x_x_x_", 55544, 3221618974, "_x_x_x_x_bach_float64_x_x_x_x_", 14040, 1074490731, "_x_x_x_x_bach_float64_x_x_x_x_", 55372, 3221647064, "_x_x_x_x_bach_float64_x_x_x_x_", 14368, 1074495980, "_x_x_x_x_bach_float64_x_x_x_x_", 29519, 3221675186, "_x_x_x_x_bach_float64_x_x_x_x_", 14696, 1074501228, "_x_x_x_x_bach_float64_x_x_x_x_", 38050, 3221703339, "_x_x_x_x_bach_float64_x_x_x_x_", 15024, 1074506476, "_x_x_x_x_bach_float64_x_x_x_x_", 54822, 3221731520, "_x_x_x_x_bach_float64_x_x_x_x_", 15352, 1074511724, "_x_x_x_x_bach_float64_x_x_x_x_", 37659, 3221759727, "_x_x_x_x_bach_float64_x_x_x_x_", 15680, 1074516972, "_x_x_x_x_bach_float64_x_x_x_x_", 65272, 3221787957, "_x_x_x_x_bach_float64_x_x_x_x_", 16008, 1074522220, "_x_x_x_x_bach_float64_x_x_x_x_", 16553, 3221816209, "_x_x_x_x_bach_float64_x_x_x_x_", 16336, 1074527468, "_x_x_x_x_bach_float64_x_x_x_x_", 37313, 3221844480, "_x_x_x_x_bach_float64_x_x_x_x_", 16664, 1074532716, "_x_x_x_x_bach_float64_x_x_x_x_", 24903, 3221872768, "_x_x_x_x_bach_float64_x_x_x_x_", 16992, 1074537965, "_x_x_x_x_bach_float64_x_x_x_x_", 31152, 3221901070, "_x_x_x_x_bach_float64_x_x_x_x_", 17320, 1074543213, "_x_x_x_x_bach_float64_x_x_x_x_", 10673, 3221929383, "_x_x_x_x_bach_float64_x_x_x_x_", 17648, 1074548461, "_x_x_x_x_bach_float64_x_x_x_x_", 28539, 3221957707, "_x_x_x_x_bach_float64_x_x_x_x_", 17976, 1074553709, "_x_x_x_x_bach_float64_x_x_x_x_", 9721, 3221986038, "_x_x_x_x_bach_float64_x_x_x_x_", 18304, 1074558957, "_x_x_x_x_bach_float64_x_x_x_x_", 13246, 3222014375, "_x_x_x_x_bach_float64_x_x_x_x_", 18632, 1074564205, "_x_x_x_x_bach_float64_x_x_x_x_", 47917, 3222042714, "_x_x_x_x_bach_float64_x_x_x_x_", 18960, 1074569453, "_x_x_x_x_bach_float64_x_x_x_x_", 19330, 3222071054, "_x_x_x_x_bach_float64_x_x_x_x_", 19288, 1074574701, "_x_x_x_x_bach_float64_x_x_x_x_", 4690, 3222099392, "_x_x_x_x_bach_float64_x_x_x_x_", 19616, 1074579950, "_x_x_x_x_bach_float64_x_x_x_x_", 3365, 3222127725, "_x_x_x_x_bach_float64_x_x_x_x_", 19944, 1074585198, "_x_x_x_x_bach_float64_x_x_x_x_", 15040, 3222156053, "_x_x_x_x_bach_float64_x_x_x_x_", 20272, 1074590446, "_x_x_x_x_bach_float64_x_x_x_x_", 52159, 3222184371, "_x_x_x_x_bach_float64_x_x_x_x_", 20600, 1074595694, "_x_x_x_x_bach_float64_x_x_x_x_", 21015, 3222212679, "_x_x_x_x_bach_float64_x_x_x_x_", 20928, 1074600942, "_x_x_x_x_bach_float64_x_x_x_x_", 61221, 3222240973, "_x_x_x_x_bach_float64_x_x_x_x_", 21256, 1074606190, "_x_x_x_x_bach_float64_x_x_x_x_", 32728, 3222269252, "_x_x_x_x_bach_float64_x_x_x_x_", 21584, 1074611438, "_x_x_x_x_bach_float64_x_x_x_x_", 58194, 3222285780, "_x_x_x_x_bach_float64_x_x_x_x_", 21912, 1074616686, "_x_x_x_x_bach_float64_x_x_x_x_", 51558, 3222299900, "_x_x_x_x_bach_float64_x_x_x_x_", 22240, 1074621935, "_x_x_x_x_bach_float64_x_x_x_x_", 62035, 3222314009, "_x_x_x_x_bach_float64_x_x_x_x_", 22568, 1074627183, "_x_x_x_x_bach_float64_x_x_x_x_", 34616, 3222328105, "_x_x_x_x_bach_float64_x_x_x_x_", 22896, 1074632431, "_x_x_x_x_bach_float64_x_x_x_x_", 26801, 3222342188, "_x_x_x_x_bach_float64_x_x_x_x_", 23224, 1074637679, "_x_x_x_x_bach_float64_x_x_x_x_", 47939, 3222356256, "_x_x_x_x_bach_float64_x_x_x_x_", 23552, 1074642927, "_x_x_x_x_bach_float64_x_x_x_x_", 29054, 3222370308, "_x_x_x_x_bach_float64_x_x_x_x_", 23880, 1074648175, "_x_x_x_x_bach_float64_x_x_x_x_", 54180, 3222384344, "_x_x_x_x_bach_float64_x_x_x_x_", 24208, 1074653423, "_x_x_x_x_bach_float64_x_x_x_x_", 1188, 3222398361, "_x_x_x_x_bach_float64_x_x_x_x_", 24536, 1074658671, "_x_x_x_x_bach_float64_x_x_x_x_", 33846, 3222412358, "_x_x_x_x_bach_float64_x_x_x_x_", 24864, 1074663920, "_x_x_x_x_bach_float64_x_x_x_x_", 44517, 3222426335, "_x_x_x_x_bach_float64_x_x_x_x_", 25192, 1074669168, "_x_x_x_x_bach_float64_x_x_x_x_", 13530, 3222440291, "_x_x_x_x_bach_float64_x_x_x_x_", 25520, 1074674416, "_x_x_x_x_bach_float64_x_x_x_x_", 39992, 3222454224, "_x_x_x_x_bach_float64_x_x_x_x_", 25848, 1074679664, "_x_x_x_x_bach_float64_x_x_x_x_", 43978, 3222468133, "_x_x_x_x_bach_float64_x_x_x_x_", 26176, 1074684912, "_x_x_x_x_bach_float64_x_x_x_x_", 57581, 3222482017, "_x_x_x_x_bach_float64_x_x_x_x_", 26504, 1074690160, "_x_x_x_x_bach_float64_x_x_x_x_", 56165, 3222495875, "_x_x_x_x_bach_float64_x_x_x_x_", 26832, 1074695408, "_x_x_x_x_bach_float64_x_x_x_x_", 50693, 3222509705, "_x_x_x_x_bach_float64_x_x_x_x_", 27160, 1074700657, "_x_x_x_x_bach_float64_x_x_x_x_", 47858, 3222523508, "_x_x_x_x_bach_float64_x_x_x_x_", 27488, 1074705905, "_x_x_x_x_bach_float64_x_x_x_x_", 9030, 3222537280, "_x_x_x_x_bach_float64_x_x_x_x_", 27816, 1074711153, "_x_x_x_x_bach_float64_x_x_x_x_", 4600, 3222551023, "_x_x_x_x_bach_float64_x_x_x_x_", 28144, 1074716401, "_x_x_x_x_bach_float64_x_x_x_x_", 39359, 3222564733, "_x_x_x_x_bach_float64_x_x_x_x_", 28472, 1074721649, "_x_x_x_x_bach_float64_x_x_x_x_", 7640, 3222578411, "_x_x_x_x_bach_float64_x_x_x_x_", 28800, 1074726897, "_x_x_x_x_bach_float64_x_x_x_x_", 40303, 3222592054, "_x_x_x_x_bach_float64_x_x_x_x_", 29128, 1074732145, "_x_x_x_x_bach_float64_x_x_x_x_", 63871, 3222605663, "_x_x_x_x_bach_float64_x_x_x_x_", 29456, 1074737393, "_x_x_x_x_bach_float64_x_x_x_x_", 13567, 3222619235, "_x_x_x_x_bach_float64_x_x_x_x_", 29784, 1074742642, "_x_x_x_x_bach_float64_x_x_x_x_", 44835, 3222632771, "_x_x_x_x_bach_float64_x_x_x_x_", 30112, 1074747890, "_x_x_x_x_bach_float64_x_x_x_x_", 22409, 3222646268, "_x_x_x_x_bach_float64_x_x_x_x_", 30440, 1074753138, "_x_x_x_x_bach_float64_x_x_x_x_", 56353, 3222659725, "_x_x_x_x_bach_float64_x_x_x_x_", 30768, 1074758386, "_x_x_x_x_bach_float64_x_x_x_x_", 53404, 3222673142, "_x_x_x_x_bach_float64_x_x_x_x_", 31096, 1074763634, "_x_x_x_x_bach_float64_x_x_x_x_", 53050, 3222686517, "_x_x_x_x_bach_float64_x_x_x_x_", 31424, 1074768882, "_x_x_x_x_bach_float64_x_x_x_x_", 37573, 3222699850, "_x_x_x_x_bach_float64_x_x_x_x_", 31752, 1074774130, "_x_x_x_x_bach_float64_x_x_x_x_", 2443, 3222713139, "_x_x_x_x_bach_float64_x_x_x_x_", 32080, 1074779378, "_x_x_x_x_bach_float64_x_x_x_x_", 24868, 3222726383, "_x_x_x_x_bach_float64_x_x_x_x_", 32408, 1074784627, "_x_x_x_x_bach_float64_x_x_x_x_", 2780, 3222739581, "_x_x_x_x_bach_float64_x_x_x_x_", 32736, 1074789875, "_x_x_x_x_bach_float64_x_x_x_x_", 47256, 3222752733, "_x_x_x_x_bach_float64_x_x_x_x_", 16532, 1074792761, "_x_x_x_x_bach_float64_x_x_x_x_", 20978, 3222765836, "_x_x_x_x_bach_float64_x_x_x_x_", 49464, 1074795385, "_x_x_x_x_bach_float64_x_x_x_x_", 57719, 3222778890, "_x_x_x_x_bach_float64_x_x_x_x_", 16860, 1074798009, "_x_x_x_x_bach_float64_x_x_x_x_", 31185, 3222791895, "_x_x_x_x_bach_float64_x_x_x_x_", 49792, 1074800633, "_x_x_x_x_bach_float64_x_x_x_x_", 4778, 3222804848, "_x_x_x_x_bach_float64_x_x_x_x_", 17188, 1074803257, "_x_x_x_x_bach_float64_x_x_x_x_", 23836, 3222817749, "_x_x_x_x_bach_float64_x_x_x_x_", 50120, 1074805881, "_x_x_x_x_bach_float64_x_x_x_x_", 36752, 3222830596, "_x_x_x_x_bach_float64_x_x_x_x_", 17516, 1074808506, "_x_x_x_x_bach_float64_x_x_x_x_", 10437, 3222843390, "_x_x_x_x_bach_float64_x_x_x_x_", 50448, 1074811130, "_x_x_x_x_bach_float64_x_x_x_x_", 43501, 3222856128, "_x_x_x_x_bach_float64_x_x_x_x_", 17844, 1074813754, "_x_x_x_x_bach_float64_x_x_x_x_", 18341, 3222868810, "_x_x_x_x_bach_float64_x_x_x_x_", 50776, 1074816378, "_x_x_x_x_bach_float64_x_x_x_x_", 37276, 3222881435, "_x_x_x_x_bach_float64_x_x_x_x_", 18172, 1074819002, "_x_x_x_x_bach_float64_x_x_x_x_", 4289, 3222894002, "_x_x_x_x_bach_float64_x_x_x_x_", 51104, 1074821626, "_x_x_x_x_bach_float64_x_x_x_x_", 56276, 3222906509, "_x_x_x_x_bach_float64_x_x_x_x_", 18500, 1074824250, "_x_x_x_x_bach_float64_x_x_x_x_", 8732, 3222918956, "_x_x_x_x_bach_float64_x_x_x_x_", 51432, 1074826874, "_x_x_x_x_bach_float64_x_x_x_x_", 44070, 3222931342, "_x_x_x_x_bach_float64_x_x_x_x_", 18828, 1074829498, "_x_x_x_x_bach_float64_x_x_x_x_", 21094, 3222943665, "_x_x_x_x_bach_float64_x_x_x_x_", 51760, 1074832122, "_x_x_x_x_bach_float64_x_x_x_x_", 27000, 3222955926, "_x_x_x_x_bach_float64_x_x_x_x_", 19156, 1074834746, "_x_x_x_x_bach_float64_x_x_x_x_", 9204, 3222968122, "_x_x_x_x_bach_float64_x_x_x_x_", 52088, 1074837370, "_x_x_x_x_bach_float64_x_x_x_x_", 59801, 3222980253, "_x_x_x_x_bach_float64_x_x_x_x_", 19484, 1074839994, "_x_x_x_x_bach_float64_x_x_x_x_", 41899, 3222992318, "_x_x_x_x_bach_float64_x_x_x_x_", 52416, 1074842618, "_x_x_x_x_bach_float64_x_x_x_x_", 65110, 3223004316, "_x_x_x_x_bach_float64_x_x_x_x_", 19812, 1074845242, "_x_x_x_x_bach_float64_x_x_x_x_", 40696, 3223016247, "_x_x_x_x_bach_float64_x_x_x_x_", 52744, 1074847867, "_x_x_x_x_bach_float64_x_x_x_x_", 20246, 3223028108, "_x_x_x_x_bach_float64_x_x_x_x_", 20140, 1074850491, "_x_x_x_x_bach_float64_x_x_x_x_", 7150, 3223039899, "_x_x_x_x_bach_float64_x_x_x_x_", 53072, 1074853115, "_x_x_x_x_bach_float64_x_x_x_x_", 27240, 3223051620, "_x_x_x_x_bach_float64_x_x_x_x_", 20468, 1074855739, "_x_x_x_x_bach_float64_x_x_x_x_", 65342, 3223063269, "_x_x_x_x_bach_float64_x_x_x_x_", 53400, 1074858363, "_x_x_x_x_bach_float64_x_x_x_x_", 64328, 3223074846, "_x_x_x_x_bach_float64_x_x_x_x_", 20796, 1074860987, "_x_x_x_x_bach_float64_x_x_x_x_", 52141, 3223086349, "_x_x_x_x_bach_float64_x_x_x_x_", 53728, 1074863611, "_x_x_x_x_bach_float64_x_x_x_x_", 3558, 3223097778, "_x_x_x_x_bach_float64_x_x_x_x_", 21124, 1074866235, "_x_x_x_x_bach_float64_x_x_x_x_", 26454, 3223109132, "_x_x_x_x_bach_float64_x_x_x_x_", 54056, 1074868859, "_x_x_x_x_bach_float64_x_x_x_x_", 20584, 3223120409, "_x_x_x_x_bach_float64_x_x_x_x_", 21452, 1074871483, "_x_x_x_x_bach_float64_x_x_x_x_", 54015, 3223131610, "_x_x_x_x_bach_float64_x_x_x_x_", 54384, 1074874107, "_x_x_x_x_bach_float64_x_x_x_x_", 15378, 3223142733, "_x_x_x_x_bach_float64_x_x_x_x_", 21780, 1074876731, "_x_x_x_x_bach_float64_x_x_x_x_", 49238, 3223153777, "_x_x_x_x_bach_float64_x_x_x_x_", 54712, 1074879355, "_x_x_x_x_bach_float64_x_x_x_x_", 5073, 3223164742, "_x_x_x_x_bach_float64_x_x_x_x_", 22108, 1074881979, "_x_x_x_x_bach_float64_x_x_x_x_", 62494, 3223175626, "_x_x_x_x_bach_float64_x_x_x_x_", 55040, 1074884603, "_x_x_x_x_bach_float64_x_x_x_x_", 42337, 3223186429, "_x_x_x_x_bach_float64_x_x_x_x_", 22436, 1074887227, "_x_x_x_x_bach_float64_x_x_x_x_", 24998, 3223197151, "_x_x_x_x_bach_float64_x_x_x_x_", 55368, 1074889852, "_x_x_x_x_bach_float64_x_x_x_x_", 47764, 3223207789, "_x_x_x_x_bach_float64_x_x_x_x_", 22764, 1074892476, "_x_x_x_x_bach_float64_x_x_x_x_", 60763, 3223218344, "_x_x_x_x_bach_float64_x_x_x_x_", 55696, 1074895100, "_x_x_x_x_bach_float64_x_x_x_x_", 10403, 3223228814, "_x_x_x_x_bach_float64_x_x_x_x_", 23092, 1074897724, "_x_x_x_x_bach_float64_x_x_x_x_", 50288, 3223239200, "_x_x_x_x_bach_float64_x_x_x_x_", 56024, 1074900348, "_x_x_x_x_bach_float64_x_x_x_x_", 27596, 3223249499, "_x_x_x_x_bach_float64_x_x_x_x_", 23420, 1074902972, "_x_x_x_x_bach_float64_x_x_x_x_", 14356, 3223259711, "_x_x_x_x_bach_float64_x_x_x_x_", 56352, 1074905596, "_x_x_x_x_bach_float64_x_x_x_x_", 48595, 3223269837, "_x_x_x_x_bach_float64_x_x_x_x_", 23748, 1074908220, "_x_x_x_x_bach_float64_x_x_x_x_", 2808, 3223279873, "_x_x_x_x_bach_float64_x_x_x_x_", 56680, 1074910844, "_x_x_x_x_bach_float64_x_x_x_x_", 38487, 3223289821, "_x_x_x_x_bach_float64_x_x_x_x_", 24076, 1074913468, "_x_x_x_x_bach_float64_x_x_x_x_", 8266, 3223299680, "_x_x_x_x_bach_float64_x_x_x_x_", 57008, 1074916092, "_x_x_x_x_bach_float64_x_x_x_x_", 33877, 3223309447, "_x_x_x_x_bach_float64_x_x_x_x_", 24404, 1074918716, "_x_x_x_x_bach_float64_x_x_x_x_", 31662, 3223319124, "_x_x_x_x_bach_float64_x_x_x_x_", 57336, 1074921340, "_x_x_x_x_bach_float64_x_x_x_x_", 43078, 3223325666, "_x_x_x_x_bach_float64_x_x_x_x_", 24732, 1074923964, "_x_x_x_x_bach_float64_x_x_x_x_", 16650, 3223330412, "_x_x_x_x_bach_float64_x_x_x_x_", 57664, 1074926588, "_x_x_x_x_bach_float64_x_x_x_x_", 11372, 3223335112, "_x_x_x_x_bach_float64_x_x_x_x_", 25060, 1074929212, "_x_x_x_x_bach_float64_x_x_x_x_", 13783, 3223339764, "_x_x_x_x_bach_float64_x_x_x_x_", 57992, 1074931837, "_x_x_x_x_bach_float64_x_x_x_x_", 35446, 3223344369, "_x_x_x_x_bach_float64_x_x_x_x_", 25388, 1074934461, "_x_x_x_x_bach_float64_x_x_x_x_", 60378, 3223348927, "_x_x_x_x_bach_float64_x_x_x_x_", 58320, 1074937085, "_x_x_x_x_bach_float64_x_x_x_x_", 55990, 3223353437, "_x_x_x_x_bach_float64_x_x_x_x_", 25716, 1074939709, "_x_x_x_x_bach_float64_x_x_x_x_", 47498, 3223357898, "_x_x_x_x_bach_float64_x_x_x_x_", 58648, 1074942333, "_x_x_x_x_bach_float64_x_x_x_x_", 59203, 3223362311, "_x_x_x_x_bach_float64_x_x_x_x_", 26044, 1074944957, "_x_x_x_x_bach_float64_x_x_x_x_", 53685, 3223366675, "_x_x_x_x_bach_float64_x_x_x_x_", 58976, 1074947581, "_x_x_x_x_bach_float64_x_x_x_x_", 65509, 3223370989, "_x_x_x_x_bach_float64_x_x_x_x_", 26372, 1074950205, "_x_x_x_x_bach_float64_x_x_x_x_", 5147, 3223375254, "_x_x_x_x_bach_float64_x_x_x_x_", 59304, 1074952829, "_x_x_x_x_bach_float64_x_x_x_x_", 50598, 3223379470, "_x_x_x_x_bach_float64_x_x_x_x_", 26700, 1074955453, "_x_x_x_x_bach_float64_x_x_x_x_", 53834, 3223383635, "_x_x_x_x_bach_float64_x_x_x_x_", 59632, 1074958077, "_x_x_x_x_bach_float64_x_x_x_x_", 59214, 3223387750, "_x_x_x_x_bach_float64_x_x_x_x_", 27028, 1074960701, "_x_x_x_x_bach_float64_x_x_x_x_", 33298, 3223391814, "_x_x_x_x_bach_float64_x_x_x_x_", 59960, 1074963325, "_x_x_x_x_bach_float64_x_x_x_x_", 51254, 3223395828, "_x_x_x_x_bach_float64_x_x_x_x_", 27356, 1074965949, "_x_x_x_x_bach_float64_x_x_x_x_", 22313, 3223399790, "_x_x_x_x_bach_float64_x_x_x_x_", 60288, 1074968573, "_x_x_x_x_bach_float64_x_x_x_x_", 2864, 3223403700, "_x_x_x_x_bach_float64_x_x_x_x_", 27684, 1074971198, "_x_x_x_x_bach_float64_x_x_x_x_", 48579, 3223407559, "_x_x_x_x_bach_float64_x_x_x_x_", 60616, 1074973822, "_x_x_x_x_bach_float64_x_x_x_x_", 64330, 3223411366, "_x_x_x_x_bach_float64_x_x_x_x_", 28012, 1074976446, "_x_x_x_x_bach_float64_x_x_x_x_", 45082, 3223415121, "_x_x_x_x_bach_float64_x_x_x_x_", 60944, 1074979070, "_x_x_x_x_bach_float64_x_x_x_x_", 52401, 3223418823, "_x_x_x_x_bach_float64_x_x_x_x_", 28340, 1074981694, "_x_x_x_x_bach_float64_x_x_x_x_", 57644, 3223422472, "_x_x_x_x_bach_float64_x_x_x_x_", 61272, 1074984318, "_x_x_x_x_bach_float64_x_x_x_x_", 45022, 3223426069, "_x_x_x_x_bach_float64_x_x_x_x_", 28668, 1074986942, "_x_x_x_x_bach_float64_x_x_x_x_", 46862, 3223429612, "_x_x_x_x_bach_float64_x_x_x_x_", 61600, 1074989566, "_x_x_x_x_bach_float64_x_x_x_x_", 45502, 3223433102, "_x_x_x_x_bach_float64_x_x_x_x_", 28996, 1074992190, "_x_x_x_x_bach_float64_x_x_x_x_", 3982, 3223436539, "_x_x_x_x_bach_float64_x_x_x_x_", 61928, 1074994814, "_x_x_x_x_bach_float64_x_x_x_x_", 25482, 3223439921, "_x_x_x_x_bach_float64_x_x_x_x_", 29324, 1074997438, "_x_x_x_x_bach_float64_x_x_x_x_", 51714, 3223443249, "_x_x_x_x_bach_float64_x_x_x_x_", 62256, 1075000062, "_x_x_x_x_bach_float64_x_x_x_x_", 17739, 3223446524, "_x_x_x_x_bach_float64_x_x_x_x_", 29652, 1075002686, "_x_x_x_x_bach_float64_x_x_x_x_", 4448, 3223449743, "_x_x_x_x_bach_float64_x_x_x_x_", 62584, 1075005310, "_x_x_x_x_bach_float64_x_x_x_x_", 61030, 3223452908, "_x_x_x_x_bach_float64_x_x_x_x_", 29980, 1075007934, "_x_x_x_x_bach_float64_x_x_x_x_", 25090, 3223456019, "_x_x_x_x_bach_float64_x_x_x_x_", 62912, 1075010558, "_x_x_x_x_bach_float64_x_x_x_x_", 61309, 3223459074, "_x_x_x_x_bach_float64_x_x_x_x_", 30308, 1075013183, "_x_x_x_x_bach_float64_x_x_x_x_", 18088, 3223462074, "_x_x_x_x_bach_float64_x_x_x_x_", 63240, 1075015807, "_x_x_x_x_bach_float64_x_x_x_x_", 27007, 3223465019, "_x_x_x_x_bach_float64_x_x_x_x_", 30636, 1075018431, "_x_x_x_x_bach_float64_x_x_x_x_", 51332, 3223467908, "_x_x_x_x_bach_float64_x_x_x_x_", 63568, 1075021055, "_x_x_x_x_bach_float64_x_x_x_x_", 21950, 3223470742, "_x_x_x_x_bach_float64_x_x_x_x_", 30964, 1075023679, "_x_x_x_x_bach_float64_x_x_x_x_", 36459, 3223473519, "_x_x_x_x_bach_float64_x_x_x_x_", 63896, 1075026303, "_x_x_x_x_bach_float64_x_x_x_x_", 31558, 3223476241, "_x_x_x_x_bach_float64_x_x_x_x_", 31292, 1075028927, "_x_x_x_x_bach_float64_x_x_x_x_", 42858, 3223478907, "_x_x_x_x_bach_float64_x_x_x_x_", 64224, 1075031551, "_x_x_x_x_bach_float64_x_x_x_x_", 3538, 3223481516, "_x_x_x_x_bach_float64_x_x_x_x_", 31620, 1075034175, "_x_x_x_x_bach_float64_x_x_x_x_", 64848, 3223484069, "_x_x_x_x_bach_float64_x_x_x_x_", 64552, 1075036799, "_x_x_x_x_bach_float64_x_x_x_x_", 62238, 3223486566, "_x_x_x_x_bach_float64_x_x_x_x_", 31948, 1075039423, "_x_x_x_x_bach_float64_x_x_x_x_", 27624, 3223489006, "_x_x_x_x_bach_float64_x_x_x_x_", 64880, 1075042047, "_x_x_x_x_bach_float64_x_x_x_x_", 43860, 3223491389, "_x_x_x_x_bach_float64_x_x_x_x_", 32276, 1075044671, "_x_x_x_x_bach_float64_x_x_x_x_", 31228, 3223493716, "_x_x_x_x_bach_float64_x_x_x_x_", 65208, 1075047295, "_x_x_x_x_bach_float64_x_x_x_x_", 55779, 3223495985 ],
									"whole_graph_data_count" : [ 2 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"order" : 1,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"order" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"order" : 1,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"order" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 217.0, 41.0, 20.0 ],
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
					"text" : "p grid",
					"varname" : "basic_tab[1]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 17.0, 211.0, 101.0, 21.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-34",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 280.59375, 435.0, 262.0, 40.0 ],
									"style" : "",
									"text" : "A bang is output each time the user changes something via mouse"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 195.0, 478.0, 365.0, 40.0 ],
									"style" : "",
									"text" : "Upon dump, vectors are output in an interleaved list of X's and Y's. Just use bach.group if you need a grouped list."
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-33",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 348.59375, 360.0, 272.0, 69.0 ],
									"style" : "",
									"text" : "Change the position of a single vector: the vector index and the new X Y coordinates are expected (this message moves the 2nd vector to the position X = 0, Y = 1)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-32",
									"linecount" : 5,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 352.59375, 261.0, 158.0, 83.0 ],
									"style" : "",
									"text" : "Remove a certain vector from its index\n(this message removes the first introduced vector)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-31",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 342.59375, 211.0, 167.0, 40.0 ],
									"style" : "",
									"text" : "Add a vector with given X Y coordinates"
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-30",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 511.59375, 275.5, 218.0, 54.0 ],
									"style" : "",
									"text" : "or Cmd+click (mac) or Ctrl+click (win) on a the tip of the arrow of a vector to delete it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-29",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 627.0, 360.0, 102.59375, 69.0 ],
									"style" : "",
									"text" : "...or click on the arrow tip and drag to move it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 525.0, 211.0, 191.0, 40.0 ],
									"style" : "",
									"text" : "...or you can Alt+click to add a vector",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.59375, 385.0, 61.0, 23.0 ],
									"style" : "",
									"text" : "set 2 0 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.59375, 293.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "remove 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-23",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.59375, 211.0, 55.0, 23.0 ],
									"style" : "",
									"text" : "add 4 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-24",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.59375, 237.0, 65.0, 23.0 ],
									"style" : "",
									"text" : "add 1.5 1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 195.0, 120.125, 229.0, 40.0 ],
									"style" : "",
									"text" : "You might want to use vectors with graphtype 3 or 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 107.0, 130.625, 80.0, 23.0 ],
									"style" : "",
									"text" : "graphtype 3"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 56.625, 78.0, 21.0 ],
									"style" : "",
									"text" : "loadmess 3"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-5",
									"items" : [ "Line", ",", "Points", ",", "Line&Points", ",", "Vectors" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 85.625, 108.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 112.625, 92.0, 23.0 ],
									"style" : "",
									"text" : "showmode $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 64.0, 497.0, 123.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Grouped"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 64.0, 472.0, 87.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.group 2"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 171.0, 171.0, 350.0, 25.0 ],
									"style" : "",
									"text" : "dump will retrieve the list of X's and Y's of all the vectors"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 123.0, 76.125, 240.0, 40.0 ],
									"style" : "",
									"text" : "You can choose to show points as vectors via the \"showmode\" attribute"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 122.0, 172.0, 44.0, 23.0 ],
									"style" : "",
									"text" : "dump"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 255.0, 438.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 439.0, 137.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Interleaved"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"graphtype" : 3,
									"id" : "obj-3",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 198.0, 264.0, 230.0 ],
									"presentation_rect" : [ 45.0, 45.0, 260.0, 260.0 ],
									"showmode" : 3,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-3", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"order" : 0,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"order" : 1,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"hidden" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"hidden" : 1,
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 297.0, 59.0, 20.0 ],
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
					"text" : "p vectors",
					"varname" : "basic_tab[9]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"attr" : "clickedcolor",
									"id" : "obj-37",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 579.0, 225.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"attr" : "showclicked",
									"id" : "obj-35",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 579.0, 200.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-24",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 645.0, 158.0, 151.59375, 40.0 ],
									"style" : "",
									"text" : "The same, without triggering any output"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 628.0, 121.0, 124.59375, 40.0 ],
									"style" : "",
									"text" : "Click on a point via message"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 579.0, 166.5, 64.0, 23.0 ],
									"style" : "",
									"text" : "setclick 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 579.0, 137.5, 47.0, 23.0 ],
									"style" : "",
									"text" : "click 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 137.09375, 471.0, 68.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.59375, 215.0, 101.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-34",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 287.59375, 441.0, 411.0, 25.0 ],
									"style" : "",
									"text" : "A bang is output each time the user changes something via mouse"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-33",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 358.0, 364.0, 270.0, 69.0 ],
									"style" : "",
									"text" : "Change the position of a single point: the point index and the new X Y coordinates are expected (this message moves the 2nd point to the position X = 0, Y = 1)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-32",
									"linecount" : 5,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 358.0, 280.0, 151.59375, 83.0 ],
									"style" : "",
									"text" : "Remove a certain point from its index\n(this message removes the first introduced point)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-31",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 349.59375, 215.0, 151.59375, 40.0 ],
									"style" : "",
									"text" : "Add a point with given X Y coordinates"
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-30",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 515.0, 294.5, 175.0, 54.0 ],
									"style" : "",
									"text" : "or Cmd+click (mac) or Ctrl+click (win) on a point to delete it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-29",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 633.59375, 364.0, 89.0, 69.0 ],
									"style" : "",
									"text" : "...or click on a point and drag to move it",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
									"bubble" : 1,
									"bubblepoint" : 0.0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 364.59375, 251.0, 232.0, 25.0 ],
									"style" : "",
									"text" : "...or you can Alt+click to add a point",
									"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 252.59375, 112.0, 310.0, 25.0 ],
									"style" : "",
									"text" : "Try to switch from type 3 to type 4 and vice versa"
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
									"patching_rect" : [ 287.59375, 389.0, 61.0, 23.0 ],
									"style" : "",
									"text" : "set 2 0 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 287.59375, 312.0, 66.0, 23.0 ],
									"style" : "",
									"text" : "remove 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 287.59375, 215.0, 55.0, 23.0 ],
									"style" : "",
									"text" : "add 4 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 287.59375, 241.0, 65.0, 23.0 ],
									"style" : "",
									"text" : "add 1.5 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 31.59375, 501.5, 123.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Grouped"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 31.59375, 471.0, 87.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.group 2"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 164.796875, 492.0, 359.0, 40.0 ],
									"style" : "",
									"text" : "Upon dump, points are output in an interleaved list of X's and Y's. Just use bach.group if you need a grouped list."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 88.59375, 168.0, 455.0, 36.0 ],
									"style" : "",
									"text" : "You can use dump with any kind of graphtype: with pseudo-continuous graph types, dump will output the interleaved list of all the sampled X Y couples",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 81.09375, 143.0, 420.0, 25.0 ],
									"style" : "",
									"text" : "dump outputs the interleaved list of X and Y for all the defined points"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 31.59375, 143.0, 44.0, 23.0 ],
									"style" : "",
									"text" : "dump"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 259.59375, 442.0, 20.0, 20.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 14.59375, 444.0, 137.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.print Interleaved"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"graphtype" : 4,
									"id" : "obj-25",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 14.59375, 206.0, 264.0, 230.0 ],
									"presentation_rect" : [ 45.0, 45.0, 260.0, 260.0 ],
									"showmode" : 2,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "graphtype",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 14.59375, 113.0, 230.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-68",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 70.625, 750.0, 36.0 ],
									"style" : "",
									"text" : "graphtype 3 and 4 allow you to define single points, without any function formula. \nThey are essentially the same: only the first ones comes with a cartesian lattice, and the second with a polar one.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-25", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"order" : 0,
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-25", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-23", 0 ],
									"order" : 1,
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"hidden" : 1,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"hidden" : 1,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"hidden" : 1,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"hidden" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"hidden" : 1,
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 247.0, 130.0, 20.0 ],
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
					"text" : "p \"user defined points\"",
					"varname" : "basic_tab[8]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"hidden" : 1,
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 32.0, 270.0, 98.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-64",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 297.0, 374.0, 217.0, 50.0 ],
									"style" : "",
									"text" : "Be careful to choose the right mint and maxt in order to display the portion of curve you want",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 451.0, 291.0, 155.0, 69.0 ],
									"style" : "",
									"text" : "Set the minimum and maximum sampled values of the free variable T"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 382.0, 270.0, 85.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 10"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 297.0, 270.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-58",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 382.0, 336.0, 58.0, 23.0 ],
									"style" : "",
									"text" : "maxt $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-57",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 382.0, 303.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-56",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 297.0, 303.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-53",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 297.0, 336.0, 54.0, 23.0 ],
									"style" : "",
									"text" : "mint $1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-36",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 89.0, 207.0, 103.0, 25.0 ],
									"style" : "",
									"text" : " bang to plot"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 52.0, 202.0, 35.0, 35.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 203.0, 165.5, 216.0, 25.0 ],
									"style" : "",
									"text" : "Define formulas for both X and Y"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-46",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 38.59375, 159.0, 153.40625, 38.0 ],
									"style" : "",
									"text" : "exprx sin($f1+cos($f1)), expry sin($f1*$f1)"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"graphtype" : 2,
									"id" : "obj-40",
									"maxclass" : "bach.graph",
									"maxt" : 10.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 14.59375, 251.0, 260.0, 260.0 ],
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "graphtype",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 14.59375, 119.0, 230.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-68",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 75.625, 504.0, 36.0 ],
									"style" : "",
									"text" : "In parametric mode, you separately set the expressions for X = f(T) and Y = g(T), where $f1 corresponds to T (the free \"time\" variable)",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-15",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 203.0, 209.5, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "2",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-20",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 426.0, 167.5, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "1",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-56", 0 ],
									"hidden" : 1,
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-57", 0 ],
									"hidden" : 1,
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"hidden" : 1,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-53", 0 ],
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"source" : [ "obj-57", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 183.0, 77.0, 20.0 ],
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
					"text" : "p parametric",
					"varname" : "basic_tab[7]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 281.0, 101.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 495.0, 317.0, 155.0, 69.0 ],
									"style" : "",
									"text" : "Set the minimum and maximum sampled values of the angle Theta (in radians)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 407.59375, 305.0, 125.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 12.56636"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 308.0, 305.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-65",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 407.59375, 368.0, 83.0, 23.0 ],
									"style" : "",
									"text" : "maxtheta $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-66",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 407.59375, 335.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-67",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 308.0, 335.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 308.0, 368.0, 79.0, 23.0 ],
									"style" : "",
									"text" : "mintheta $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-64",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 308.0, 411.0, 227.0, 50.0 ],
									"style" : "",
									"text" : "Be careful to choose the right mintheta and maxtheta in order to display the portion of curve you want",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-36",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 73.0, 229.0, 139.0, 25.0 ],
									"style" : "",
									"text" : "Finally bang to plot!"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 36.0, 224.0, 35.0, 35.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 328.0, 203.0, 220.0, 25.0 ],
									"style" : "",
									"text" : "Define value of the $f2 parameter"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 212.0, 162.0, 192.0, 25.0 ],
									"style" : "",
									"text" : "Define formula for the radius"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 255.0, 105.5, 235.59375, 40.0 ],
									"style" : "",
									"text" : "Graph type can be changed. In the basic tab, our graph was Cartesian"
								}

							}
, 							{
								"box" : 								{
									"attr" : "graphtype",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"lock" : 1,
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 14.59375, 115.0, 230.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-71",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 274.59375, 203.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-47",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 35.59375, 165.0, 166.0, 23.0 ],
									"style" : "",
									"text" : "exprr $f2 + $f1 * log($f2+2)"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"graphcolor" : [ 0.0, 0.070588, 0.458824, 1.0 ],
									"graphtype" : 1,
									"id" : "obj-41",
									"maxclass" : "bach.graph",
									"maxtheta" : 12.56636,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 14.59375, 267.0, 279.0, 249.203888 ],
									"presentation_rect" : [ 336.0, 542.0, 260.0, 260.0 ],
									"showunitcircle" : 1,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-68",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 69.5, 614.0, 21.0 ],
									"style" : "",
									"text" : "In polar mode, you set the expression for R = f(Theta), where $f1 corresponds to Theta (angle in radians)",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-11",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 215.0, 231.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "3",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-20",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 409.0, 165.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "1",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-15",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 554.0, 206.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "2",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-67", 0 ],
									"hidden" : 1,
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-66", 0 ],
									"hidden" : 1,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"hidden" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-65", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-65", 0 ],
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-67", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 1 ],
									"source" : [ "obj-71", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 147.0, 47.0, 20.0 ],
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
					"text" : "p polar",
					"varname" : "basic_tab[6]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"id" : "obj-14",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 294.0, 386.0, 142.0, 23.0 ],
									"style" : "",
									"text" : "expry cos($f1*$f2+$f3)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 294.0, 357.0, 113.0, 23.0 ],
									"style" : "",
									"text" : "expry $f1*$f2+$f3"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 549.5, 219.0, 105.0, 36.0 ],
									"style" : "",
									"text" : "Steps 1 and 2 can be swapped",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 524.5, 339.5, 87.5, 54.0 ],
									"style" : "",
									"text" : "Try with different formulas"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-34",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 294.0, 431.0, 286.0, 65.0 ],
									"style" : "",
									"text" : "If more parameters than needed are given, only the needed number of parameters will be considered. If less parameters than needed are given, the remaining ones will be 0's.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.0,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 294.0, 234.0, 231.0, 69.0 ],
									"style" : "",
									"text" : "We had two parameters in our formulas ($f2 and $f3), so a list with two elements is expected"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 33.0, 258.0, 101.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-36",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 86.0, 208.0, 139.0, 25.0 ],
									"style" : "",
									"text" : "Finally bang to plot!"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-25",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 342.0, 111.5, 320.0, 40.0 ],
									"style" : "",
									"text" : "First set the formula for y, which now can involve $f2, $f3... all considered to be parameters"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 49.0, 203.0, 35.0, 35.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-69",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 386.0, 158.5, 200.0, 54.0 ],
									"style" : "",
									"text" : "Then introduce the values of the parameters (corresponding to $f2, $f3...)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 294.0, 330.5, 220.0, 23.0 ],
									"style" : "",
									"text" : "expry $f1 + sin($f2+$f1) * ($f3 + 1.2)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-5",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 327.0, 175.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 267.0, 201.0, 79.0, 23.0 ],
									"style" : "",
									"text" : "pak f f"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-3",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 267.0, 175.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 26.0, 122.0, 304.0, 23.0 ],
									"style" : "",
									"text" : "expry \"-pow($f1, $f2+1) +4*cos($f1-2) * ($f3 + 1.1)\""
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 26.0, 248.0, 260.0, 260.0 ],
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-68",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 71.625, 539.0, 21.0 ],
									"style" : "",
									"text" : "Formula can have user-defined parameters, whose values must be input from the right inlet.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-10",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 228.0, 210.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "3",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-20",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 670.5, 122.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "1",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-15",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 592.0, 175.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "2",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 1 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"hidden" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 116.0, 81.0, 20.0 ],
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
					"text" : "p parameters",
					"varname" : "basic_tab[5]"
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
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 505.0, 54.5, 114.0, 54.0 ],
									"style" : "",
									"text" : "Click the messages to... paint!"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 269.0, 42.625, 101.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 284.0, 300.0, 213.0, 23.0 ],
									"style" : "",
									"text" : "expry \"3*exp(-pow($f1, 2)/2)\", bang"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"graphcolor" : [ 0.74902, 0.619608, 0.094118, 1.0 ],
									"gridtype" : 1,
									"id" : "obj-9",
									"linewidth" : 3.0,
									"maxclass" : "bach.graph",
									"maxt" : 1000.0,
									"maxtheta" : 520.566406,
									"maxx" : 4.0,
									"maxy" : 4.0,
									"minx" : -4.0,
									"miny" : -1.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 284.0, 326.0, 199.0, 189.724579 ],
									"presentation_rect" : [ 264.0, 328.0, 260.0, 260.0 ],
									"showlabels" : 0,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 300.0, 252.0, 23.0 ],
									"style" : "",
									"text" : "exprx 14*sin(14*$f1), expry tan($f1), bang"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"graphcolor" : [ 0.086275, 0.47451, 0.164706, 1.0 ],
									"graphtype" : 2,
									"gridtype" : 0,
									"id" : "obj-6",
									"maxclass" : "bach.graph",
									"maxt" : 1000.0,
									"maxtheta" : 520.566406,
									"maxx" : 10.0,
									"maxy" : 10.0,
									"minx" : -10.0,
									"miny" : -10.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 326.0, 199.0, 189.724579 ],
									"presentation_rect" : [ 22.0, 328.0, 260.0, 260.0 ],
									"showlabels" : 0,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 72.0, 99.0, 23.0 ],
									"style" : "",
									"text" : "exprr $f1, bang"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-47",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 284.0, 72.0, 192.0, 23.0 ],
									"style" : "",
									"text" : "exprr $f2 + sin(4*$f1)*$f1, bang"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"graphcolor" : [ 0.145098, 0.215686, 0.501961, 1.0 ],
									"graphtype" : 1,
									"id" : "obj-1",
									"maxclass" : "bach.graph",
									"maxt" : 1000.0,
									"maxtheta" : 100.0,
									"maxx" : 20.0,
									"maxy" : 20.0,
									"minx" : -20.0,
									"miny" : -20.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 284.0, 98.0, 199.0, 189.724579 ],
									"presentation_rect" : [ 22.0, 44.0, 236.0, 225.0 ],
									"showlabels" : 0,
									"showxyaxis" : 0,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"graphcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
									"graphtype" : 1,
									"gridtype" : 0,
									"id" : "obj-41",
									"maxclass" : "bach.graph",
									"maxt" : 1000.0,
									"maxtheta" : 520.566406,
									"maxx" : 500.0,
									"maxy" : 500.0,
									"minx" : -500.0,
									"miny" : -500.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 98.0, 199.0, 189.724579 ],
									"presentation_rect" : [ 366.0, 572.0, 260.0, 260.0 ],
									"showlabels" : 0,
									"showxyaxis" : 0,
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-4",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 236.3806, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"hidden" : 1,
									"order" : 3,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"order" : 2,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 335.0, 37.0, 20.0 ],
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
					"text" : "p fun",
					"varname" : "basic_tab[3]"
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
					"patching_rect" : [ 294.0, 205.0, 154.0, 20.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
					"style" : "",
					"text" : "js helpstarter.js bach.graph"
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
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 100.0, 126.0, 807.0, 536.0 ],
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
									"bubblepoint" : 0.3,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-23",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 307.5, 376.0, 186.0, 55.0 ],
									"style" : "",
									"text" : "Change the display and sampling range on the X axis"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.38,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 500.5, 376.0, 143.0, 55.0 ],
									"style" : "",
									"text" : "Change the display range on the Y axis"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 560.5, 431.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 500.5, 431.0, 82.0, 23.0 ],
									"style" : "",
									"text" : "loadmess -5"
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
									"patching_rect" : [ 560.5, 467.0, 60.0, 23.0 ],
									"style" : "",
									"text" : "maxy $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-16",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 560.5, 439.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-17",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 500.5, 439.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 500.5, 467.0, 56.0, 23.0 ],
									"style" : "",
									"text" : "miny $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 371.0, 431.0, 78.0, 23.0 ],
									"style" : "",
									"text" : "loadmess 5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 311.0, 431.0, 82.0, 23.0 ],
									"style" : "",
									"text" : "loadmess -5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-58",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 371.0, 467.0, 60.0, 23.0 ],
									"style" : "",
									"text" : "maxx $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-57",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 371.0, 439.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-56",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 311.0, 439.0, 50.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-53",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 311.0, 467.0, 56.0, 23.0 ],
									"style" : "",
									"text" : "minx $1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 466.0, 237.0, 137.0, 69.0 ],
									"style" : "",
									"text" : "You can add the \"bang\" at the end of the message to plot immediately"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-10",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 307.5, 292.0, 155.0, 22.0 ],
									"style" : "",
									"text" : "expry sin($f1*30)/$f1, bang"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-9",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 307.5, 266.0, 138.0, 22.0 ],
									"style" : "",
									"text" : "expry $f1*sin($f1), bang"
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
									"patching_rect" : [ 307.5, 186.0, 319.0, 36.0 ],
									"style" : "",
									"text" : "The syntax for the formula is exactly like the one in bach.expr, $f1 always being the free variable",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-21",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 307.5, 237.0, 93.0, 22.0 ],
									"style" : "",
									"text" : "expry $f1, bang"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 34.0, 254.0, 101.0, 23.0 ],
									"style" : "",
									"text" : "loadmess clear"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-36",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 86.0, 201.0, 170.0, 25.0 ],
									"style" : "",
									"text" : "...then bang to plot!"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-25",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 236.0, 157.0, 248.0, 25.0 ],
									"style" : "",
									"text" : "First set the formula for y: y = f($f1)..."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 49.0, 196.0, 35.0, 35.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 26.0, 160.0, 207.0, 23.0 ],
									"style" : "",
									"text" : "expry \"-pow($f1, 3) +4*cos($f1-2)\""
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "bach.graph",
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 26.0, 243.0, 260.0, 260.0 ],
									"versionnumber" : 80001,
									"whole_graph_data_0000000000" : [ "null" ],
									"whole_graph_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpdetails.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.graph", 100 ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 661.0, 129.0 ]
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-20",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 491.5, 160.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "1",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"background" : 1,
									"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
									"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
									"fontface" : 1,
									"hint" : "",
									"id" : "obj-15",
									"ignoreclick" : 1,
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 263.0, 204.0, 20.0, 20.0 ],
									"rounded" : 60.0,
									"style" : "",
									"text" : "2",
									"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
									"textoncolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ],
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"hidden" : 1,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"hidden" : 1,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"midpoints" : [ 570.0, 495.0, 271.75, 495.0, 271.75, 233.0, 35.5, 233.0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"midpoints" : [ 510.0, 495.0, 272.75, 495.0, 272.75, 233.0, 35.5, 233.0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-56", 0 ],
									"hidden" : 1,
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-57", 0 ],
									"hidden" : 1,
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"hidden" : 1,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"midpoints" : [ 320.5, 495.0, 272.0, 495.0, 272.0, 233.0, 35.5, 233.0 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-53", 0 ],
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"source" : [ "obj-57", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"midpoints" : [ 380.5, 495.0, 270.0, 495.0, 270.0, 233.0, 35.5, 233.0 ],
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 85.0, 50.0, 20.0 ],
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
					"jsarguments" : [ "bach.graph" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 10.0, 245.1875, 53.625 ]
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
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 807.0, 536.0 ],
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
					"patching_rect" : [ 205.0, 205.0, 50.0, 20.0 ],
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
				"name" : "helpstarter.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.graph.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.group.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
