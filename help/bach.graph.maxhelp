{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 1,
			"revision" : 11,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
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
		"assistshowspatchername" : 0,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"patching_rect" : [ 438.0, 73.0, 77.0, 23.0 ],
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
									"patching_rect" : [ 489.09375, 263.0, 20.0, 20.0 ]
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
									"patching_rect" : [ 294.296875, 114.0, 20.0, 20.0 ]
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
									"parameter_enable" : 0,
									"patching_rect" : [ 259.59375, 442.0, 20.0, 20.0 ]
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
									"showmode" : 1,
									"versionnumber" : 80104,
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
									"patching_rect" : [ 14.59375, 113.0, 230.0, 23.0 ]
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
									"patching_rect" : [ 10.0, 10.0, 236.380599999999987, 57.567627000000002 ]
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
					"patching_rect" : [ 10.0, 271.0, 154.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 76.0, 441.0, 21.0 ],
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
									"patching_rect" : [ 515.0, 170.0, 137.0, 23.0 ]
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
									"patching_rect" : [ 229.0, 136.0, 150.0, 23.0 ]
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
									"patching_rect" : [ 229.0, 115.0, 188.0, 23.0 ]
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
									"patching_rect" : [ 449.0, 136.0, 150.0, 23.0 ]
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
									"patching_rect" : [ 449.0, 115.0, 150.0, 23.0 ]
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
									"versionnumber" : 80104,
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
									"patching_rect" : [ 10.0, 136.0, 150.0, 23.0 ]
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
									"patching_rect" : [ 10.0, 115.0, 150.0, 23.0 ]
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
									"versionnumber" : 80104,
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
									"patching_rect" : [ 10.0, 10.0, 236.360000610351562, 57.599853515625 ]
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
					"patching_rect" : [ 10.0, 217.0, 41.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"patching_rect" : [ 17.0, 211.0, 101.0, 23.0 ],
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
									"patching_rect" : [ 10.0, 56.625, 78.0, 23.0 ],
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
									"patching_rect" : [ 10.0, 85.625, 108.0, 23.0 ]
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
									"parameter_enable" : 0,
									"patching_rect" : [ 255.0, 438.0, 20.0, 20.0 ]
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
									"showmode" : 3,
									"versionnumber" : 80104,
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
									"patching_rect" : [ 10.0, 10.0, 236.380599999999987, 57.567627000000002 ]
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
					"patching_rect" : [ 10.0, 297.0, 59.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"attr" : "clickedcolor",
									"id" : "obj-37",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 579.0, 225.0, 150.0, 23.0 ]
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
									"patching_rect" : [ 579.0, 200.0, 150.0, 23.0 ]
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
									"parameter_enable" : 0,
									"patching_rect" : [ 259.59375, 442.0, 20.0, 20.0 ]
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
									"showmode" : 2,
									"versionnumber" : 80104,
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
									"patching_rect" : [ 14.59375, 113.0, 230.0, 23.0 ]
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
									"patching_rect" : [ 10.0, 10.0, 236.380599999999987, 57.567627000000002 ]
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
					"patching_rect" : [ 10.0, 247.0, 130.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"patching_rect" : [ 382.0, 303.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 297.0, 303.0, 50.0, 23.0 ]
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
									"parameter_enable" : 0,
									"patching_rect" : [ 52.0, 202.0, 35.0, 35.0 ]
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
									"versionnumber" : 80104,
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
									"patching_rect" : [ 14.59375, 119.0, 230.0, 23.0 ]
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
									"patching_rect" : [ 10.0, 10.0, 236.360000610351562, 57.599853515625 ]
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
					"patching_rect" : [ 10.0, 183.0, 77.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 313.59375, 262.0, 166.0, 23.0 ],
									"text" : "exprr $f2 + $f1 * log($f2+2)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 486.0, 246.5, 248.0, 54.0 ],
									"text" : "\"expr\" is an alias of \"expry\" for cartesian graphs and of \"exprr\" for polar graphs (see \"polar\" tab)"
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
									"patching_rect" : [ 20.0, 281.0, 101.0, 23.0 ],
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
									"patching_rect" : [ 407.59375, 335.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 308.0, 335.0, 50.0, 23.0 ]
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
									"parameter_enable" : 0,
									"patching_rect" : [ 36.0, 224.0, 35.0, 35.0 ]
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
									"patching_rect" : [ 14.59375, 115.0, 230.0, 23.0 ]
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
									"patching_rect" : [ 274.59375, 203.0, 50.0, 23.0 ]
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
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 14.59375, 267.0, 279.0, 249.203888000000006 ],
									"showunitcircle" : 1,
									"versionnumber" : 80104,
									"whole_graph_data_0000000000" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 2700399908, 1066159298, "_x_x_x_x_bach_float64_x_x_x_x_", 2426316567, 1059506359, "_x_x_x_x_bach_float64_x_x_x_x_", 1845976199, 1067207434, "_x_x_x_x_bach_float64_x_x_x_x_", 1864505701, 1061603393, "_x_x_x_x_bach_float64_x_x_x_x_", 2713230368, 1067791905, "_x_x_x_x_bach_float64_x_x_x_x_", 567512344, 1062838380, "_x_x_x_x_bach_float64_x_x_x_x_", 4218958676, 1068254249, "_x_x_x_x_bach_float64_x_x_x_x_", 4153062050, 1063700072, "_x_x_x_x_bach_float64_x_x_x_x_", 1106741503, 1068607329, "_x_x_x_x_bach_float64_x_x_x_x_", 924311094, 1064421869, "_x_x_x_x_bach_float64_x_x_x_x_", 3675819944, 1068837511, "_x_x_x_x_bach_float64_x_x_x_x_", 1873377331, 1064934336, "_x_x_x_x_bach_float64_x_x_x_x_", 734430790, 1069067035, "_x_x_x_x_bach_float64_x_x_x_x_", 4100052192, 1065446405, "_x_x_x_x_bach_float64_x_x_x_x_", 3274559524, 1069295789, "_x_x_x_x_bach_float64_x_x_x_x_", 4274791362, 1065795335, "_x_x_x_x_bach_float64_x_x_x_x_", 1684339327, 1069523666, "_x_x_x_x_bach_float64_x_x_x_x_", 3597891228, 1066190455, "_x_x_x_x_bach_float64_x_x_x_x_", 115832059, 1069649038, "_x_x_x_x_bach_float64_x_x_x_x_", 698014723, 1066516716, "_x_x_x_x_bach_float64_x_x_x_x_", 3986822, 1069761935, "_x_x_x_x_bach_float64_x_x_x_x_", 3599050072, 1066760270, "_x_x_x_x_bach_float64_x_x_x_x_", 3820797244, 1069874229, "_x_x_x_x_bach_float64_x_x_x_x_", 3259010740, 1067026710, "_x_x_x_x_bach_float64_x_x_x_x_", 2678050123, 1069985868, "_x_x_x_x_bach_float64_x_x_x_x_", 1980924242, 1067315951, "_x_x_x_x_bach_float64_x_x_x_x_", 1316373902, 1070096797, "_x_x_x_x_bach_float64_x_x_x_x_", 2628792918, 1067539134, "_x_x_x_x_bach_float64_x_x_x_x_", 986618999, 1070206962, "_x_x_x_x_bach_float64_x_x_x_x_", 2342625891, 1067706414, "_x_x_x_x_bach_float64_x_x_x_x_", 3805896143, 1070316309, "_x_x_x_x_bach_float64_x_x_x_x_", 1917198986, 1067884946, "_x_x_x_x_bach_float64_x_x_x_x_", 4228520826, 1070424786, "_x_x_x_x_bach_float64_x_x_x_x_", 2736571989, 1068074673, "_x_x_x_x_bach_float64_x_x_x_x_", 1991588714, 1070532340, "_x_x_x_x_bach_float64_x_x_x_x_", 3693979986, 1068275535, "_x_x_x_x_bach_float64_x_x_x_x_", 3235198736, 1070617506, "_x_x_x_x_bach_float64_x_x_x_x_", 1253332379, 1068487469, "_x_x_x_x_bach_float64_x_x_x_x_", 3336948912, 1070670280, "_x_x_x_x_bach_float64_x_x_x_x_", 1199631353, 1068604675, "_x_x_x_x_bach_float64_x_x_x_x_", 684720469, 1070722514, "_x_x_x_x_bach_float64_x_x_x_x_", 1615537659, 1068721610, "_x_x_x_x_bach_float64_x_x_x_x_", 3866215117, 1070774180, "_x_x_x_x_bach_float64_x_x_x_x_", 3107509149, 1068843974, "_x_x_x_x_bach_float64_x_x_x_x_", 638112025, 1070825255, "_x_x_x_x_bach_float64_x_x_x_x_", 1540211738, 1068971729, "_x_x_x_x_bach_float64_x_x_x_x_", 905320379, 1070875711, "_x_x_x_x_bach_float64_x_x_x_x_", 2482037959, 1069104833, "_x_x_x_x_bach_float64_x_x_x_x_", 2390671218, 1070925523, "_x_x_x_x_bach_float64_x_x_x_x_", 4066823292, 1069243244, "_x_x_x_x_bach_float64_x_x_x_x_", 3549093598, 1070974666, "_x_x_x_x_bach_float64_x_x_x_x_", 1332176391, 1069386919, "_x_x_x_x_bach_float64_x_x_x_x_", 3596726395, 1071023115, "_x_x_x_x_bach_float64_x_x_x_x_", 3444479561, 1069535810, "_x_x_x_x_bach_float64_x_x_x_x_", 2539861181, 1071070845, "_x_x_x_x_bach_float64_x_x_x_x_", 3987987505, 1069618695, "_x_x_x_x_bach_float64_x_x_x_x_", 1203709685, 1071117831, "_x_x_x_x_bach_float64_x_x_x_x_", 2624185538, 1069698286, "_x_x_x_x_bach_float64_x_x_x_x_", 1260989464, 1071164048, "_x_x_x_x_bach_float64_x_x_x_x_", 4223995395, 1069780411, "_x_x_x_x_bach_float64_x_x_x_x_", 965354072, 1071209472, "_x_x_x_x_bach_float64_x_x_x_x_", 3216618550, 1069865045, "_x_x_x_x_bach_float64_x_x_x_x_", 3769530594, 1071254078, "_x_x_x_x_bach_float64_x_x_x_x_", 3369044098, 1069952160, "_x_x_x_x_bach_float64_x_x_x_x_", 1173452576, 1071297844, "_x_x_x_x_bach_float64_x_x_x_x_", 633943555, 1070041729, "_x_x_x_x_bach_float64_x_x_x_x_", 2816826124, 1071340744, "_x_x_x_x_bach_float64_x_x_x_x_", 358150923, 1070133722, "_x_x_x_x_bach_float64_x_x_x_x_", 2146973239, 1071382756, "_x_x_x_x_bach_float64_x_x_x_x_", 132245235, 1070228110, "_x_x_x_x_bach_float64_x_x_x_x_", 2215997835, 1071423856, "_x_x_x_x_bach_float64_x_x_x_x_", 2705738840, 1070324862, "_x_x_x_x_bach_float64_x_x_x_x_", 2823020479, 1071464021, "_x_x_x_x_bach_float64_x_x_x_x_", 3133290097, 1070423948, "_x_x_x_x_bach_float64_x_x_x_x_", 541083314, 1071503229, "_x_x_x_x_bach_float64_x_x_x_x_", 1691541520, 1070525336, "_x_x_x_x_bach_float64_x_x_x_x_", 1628719144, 1071541456, "_x_x_x_x_bach_float64_x_x_x_x_", 1955935443, 1070612544, "_x_x_x_x_bach_float64_x_x_x_x_", 581538447, 1071578681, "_x_x_x_x_bach_float64_x_x_x_x_", 1717040583, 1070665490, "_x_x_x_x_bach_float64_x_x_x_x_", 1633239680, 1071614881, "_x_x_x_x_bach_float64_x_x_x_x_", 3905282116, 1070719536, "_x_x_x_x_bach_float64_x_x_x_x_", 2948312839, 1071647353, "_x_x_x_x_bach_float64_x_x_x_x_", 2090858007, 1070774666, "_x_x_x_x_bach_float64_x_x_x_x_", 3547146629, 1071664396, "_x_x_x_x_bach_float64_x_x_x_x_", 1130774553, 1070830861, "_x_x_x_x_bach_float64_x_x_x_x_", 2234462438, 1071680895, "_x_x_x_x_bach_float64_x_x_x_x_", 7336309, 1070888103, "_x_x_x_x_bach_float64_x_x_x_x_", 1404202738, 1071696839, "_x_x_x_x_bach_float64_x_x_x_x_", 436825145, 1070946373, "_x_x_x_x_bach_float64_x_x_x_x_", 4087846758, 1071712217, "_x_x_x_x_bach_float64_x_x_x_x_", 2593658823, 1071005652, "_x_x_x_x_bach_float64_x_x_x_x_", 1081785663, 1071727021, "_x_x_x_x_bach_float64_x_x_x_x_", 834926929, 1071065922, "_x_x_x_x_bach_float64_x_x_x_x_", 1024225831, 1071741239, "_x_x_x_x_bach_float64_x_x_x_x_", 900136513, 1071127162, "_x_x_x_x_bach_float64_x_x_x_x_", 342402373, 1071754862, "_x_x_x_x_bach_float64_x_x_x_x_", 2751588352, 1071189352, "_x_x_x_x_bach_float64_x_x_x_x_", 444282588, 1071767880, "_x_x_x_x_bach_float64_x_x_x_x_", 594987124, 1071252473, "_x_x_x_x_bach_float64_x_x_x_x_", 3435279895, 1071780283, "_x_x_x_x_bach_float64_x_x_x_x_", 80281091, 1071316503, "_x_x_x_x_bach_float64_x_x_x_x_", 3539844824, 1071792063, "_x_x_x_x_bach_float64_x_x_x_x_", 1143119338, 1071381421, "_x_x_x_x_bach_float64_x_x_x_x_", 4292701464, 1071803210, "_x_x_x_x_bach_float64_x_x_x_x_", 2321496836, 1071447206, "_x_x_x_x_bach_float64_x_x_x_x_", 1370184652, 1071813716, "_x_x_x_x_bach_float64_x_x_x_x_", 777778986, 1071513837, "_x_x_x_x_bach_float64_x_x_x_x_", 4076119379, 1071823570, "_x_x_x_x_bach_float64_x_x_x_x_", 911002857, 1071581291, "_x_x_x_x_bach_float64_x_x_x_x_", 992959369, 1071832766, "_x_x_x_x_bach_float64_x_x_x_x_", 747339642, 1071647109, "_x_x_x_x_bach_float64_x_x_x_x_", 2942168518, 1071841293, "_x_x_x_x_bach_float64_x_x_x_x_", 4292365635, 1071681625, "_x_x_x_x_bach_float64_x_x_x_x_", 45085475, 1071849145, "_x_x_x_x_bach_float64_x_x_x_x_", 2739043526, 1071716520, "_x_x_x_x_bach_float64_x_x_x_x_", 387993506, 1071856312, "_x_x_x_x_bach_float64_x_x_x_x_", 2137987228, 1071751781, "_x_x_x_x_bach_float64_x_x_x_x_", 4262505184, 1071862786, "_x_x_x_x_bach_float64_x_x_x_x_", 3626609844, 1071787396, "_x_x_x_x_bach_float64_x_x_x_x_", 4175572748, 1071868561, "_x_x_x_x_bach_float64_x_x_x_x_", 3441282145, 1071823354, "_x_x_x_x_bach_float64_x_x_x_x_", 2039187261, 1071873629, "_x_x_x_x_bach_float64_x_x_x_x_", 1519579323, 1071859643, "_x_x_x_x_bach_float64_x_x_x_x_", 590091298, 1071877982, "_x_x_x_x_bach_float64_x_x_x_x_", 1512744210, 1071896250, "_x_x_x_x_bach_float64_x_x_x_x_", 3399241304, 1071881612, "_x_x_x_x_bach_float64_x_x_x_x_", 2208364326, 1071933163, "_x_x_x_x_bach_float64_x_x_x_x_", 1996180949, 1071884514, "_x_x_x_x_bach_float64_x_x_x_x_", 1838096507, 1071970370, "_x_x_x_x_bach_float64_x_x_x_x_", 1647930842, 1071886680, "_x_x_x_x_bach_float64_x_x_x_x_", 2385534563, 1072007858, "_x_x_x_x_bach_float64_x_x_x_x_", 4188013878, 1071888103, "_x_x_x_x_bach_float64_x_x_x_x_", 1009315310, 1072045615, "_x_x_x_x_bach_float64_x_x_x_x_", 3730188974, 1071888778, "_x_x_x_x_bach_float64_x_x_x_x_", 2941198533, 1072083627, "_x_x_x_x_bach_float64_x_x_x_x_", 3856825725, 1071888698, "_x_x_x_x_bach_float64_x_x_x_x_", 24543280, 1072121883, "_x_x_x_x_bach_float64_x_x_x_x_", 447343153, 1071887858, "_x_x_x_x_bach_float64_x_x_x_x_", 792523538, 1072160368, "_x_x_x_x_bach_float64_x_x_x_x_", 3161154581, 1071886250, "_x_x_x_x_bach_float64_x_x_x_x_", 416930693, 1072199070, "_x_x_x_x_bach_float64_x_x_x_x_", 1085836228, 1071883871, "_x_x_x_x_bach_float64_x_x_x_x_", 2196709679, 1072237975, "_x_x_x_x_bach_float64_x_x_x_x_", 1399536500, 1071880714, "_x_x_x_x_bach_float64_x_x_x_x_", 391912528, 1072277071, "_x_x_x_x_bach_float64_x_x_x_x_", 3608670663, 1071876774, "_x_x_x_x_bach_float64_x_x_x_x_", 1712477842, 1072316343, "_x_x_x_x_bach_float64_x_x_x_x_", 3850179625, 1071872047, "_x_x_x_x_bach_float64_x_x_x_x_", 3857454487, 1072355778, "_x_x_x_x_bach_float64_x_x_x_x_", 3488547281, 1071866528, "_x_x_x_x_bach_float64_x_x_x_x_", 4119110574, 1072395363, "_x_x_x_x_bach_float64_x_x_x_x_", 532738227, 1071860213, "_x_x_x_x_bach_float64_x_x_x_x_", 3692186319, 1072435084, "_x_x_x_x_bach_float64_x_x_x_x_", 2527759845, 1071853096, "_x_x_x_x_bach_float64_x_x_x_x_", 3393320469, 1072474927, "_x_x_x_x_bach_float64_x_x_x_x_", 791304971, 1071845175, "_x_x_x_x_bach_float64_x_x_x_x_", 3675549004, 1072514878, "_x_x_x_x_bach_float64_x_x_x_x_", 484754099, 1071836445, "_x_x_x_x_bach_float64_x_x_x_x_", 347938567, 1072554924, "_x_x_x_x_bach_float64_x_x_x_x_", 3439320444, 1071826902, "_x_x_x_x_bach_float64_x_x_x_x_", 1770155113, 1072595049, "_x_x_x_x_bach_float64_x_x_x_x_", 3866878549, 1071816544, "_x_x_x_x_bach_float64_x_x_x_x_", 3097455315, 1072635240, "_x_x_x_x_bach_float64_x_x_x_x_", 1250442260, 1071805368, "_x_x_x_x_bach_float64_x_x_x_x_", 3475443422, 1072675483, "_x_x_x_x_bach_float64_x_x_x_x_", 349519581, 1071793370, "_x_x_x_x_bach_float64_x_x_x_x_", 880040452, 1072704506, "_x_x_x_x_bach_float64_x_x_x_x_", 2615310399, 1071780547, "_x_x_x_x_bach_float64_x_x_x_x_", 413858413, 1072724658, "_x_x_x_x_bach_float64_x_x_x_x_", 1900647573, 1071766898, "_x_x_x_x_bach_float64_x_x_x_x_", 1647633232, 1072744814, "_x_x_x_x_bach_float64_x_x_x_x_", 1644549388, 1071752420, "_x_x_x_x_bach_float64_x_x_x_x_", 3620234763, 1072764967, "_x_x_x_x_bach_float64_x_x_x_x_", 1991774526, 1071737111, "_x_x_x_x_bach_float64_x_x_x_x_", 961112361, 1072785111, "_x_x_x_x_bach_float64_x_x_x_x_", 4092018709, 1071720969, "_x_x_x_x_bach_float64_x_x_x_x_", 1077851518, 1072805237, "_x_x_x_x_bach_float64_x_x_x_x_", 1513980741, 1071703994, "_x_x_x_x_bach_float64_x_x_x_x_", 2689059700, 1072825338, "_x_x_x_x_bach_float64_x_x_x_x_", 1723969891, 1071686183, "_x_x_x_x_bach_float64_x_x_x_x_", 127089189, 1072845408, "_x_x_x_x_bach_float64_x_x_x_x_", 319642222, 1071667536, "_x_x_x_x_bach_float64_x_x_x_x_", 525693322, 1072865438, "_x_x_x_x_bach_float64_x_x_x_x_", 2508145408, 1071648051, "_x_x_x_x_bach_float64_x_x_x_x_", 2353006953, 1072885421, "_x_x_x_x_bach_float64_x_x_x_x_", 3268715733, 1071610786, "_x_x_x_x_bach_float64_x_x_x_x_", 4009326157, 1072905350, "_x_x_x_x_bach_float64_x_x_x_x_", 1317134559, 1071568466, "_x_x_x_x_bach_float64_x_x_x_x_", 3834979823, 1072925218, "_x_x_x_x_bach_float64_x_x_x_x_", 2843319849, 1071524469, "_x_x_x_x_bach_float64_x_x_x_x_", 118226039, 1072945018, "_x_x_x_x_bach_float64_x_x_x_x_", 705051498, 1071478797, "_x_x_x_x_bach_float64_x_x_x_x_", 3988073451, 1072964740, "_x_x_x_x_bach_float64_x_x_x_x_", 2710193266, 1071431449, "_x_x_x_x_bach_float64_x_x_x_x_", 767516434, 1072984380, "_x_x_x_x_bach_float64_x_x_x_x_", 1555721132, 1071382428, "_x_x_x_x_bach_float64_x_x_x_x_", 1521103151, 1073003928, "_x_x_x_x_bach_float64_x_x_x_x_", 600851894, 1071331735, "_x_x_x_x_bach_float64_x_x_x_x_", 113241010, 1073023378, "_x_x_x_x_bach_float64_x_x_x_x_", 984990254, 1071279372, "_x_x_x_x_bach_float64_x_x_x_x_", 3280962384, 1073042721, "_x_x_x_x_bach_float64_x_x_x_x_", 1630100888, 1071225342, "_x_x_x_x_bach_float64_x_x_x_x_", 577162662, 1073061952, "_x_x_x_x_bach_float64_x_x_x_x_", 3537569940, 1071169648, "_x_x_x_x_bach_float64_x_x_x_x_", 3033327755, 1073081061, "_x_x_x_x_bach_float64_x_x_x_x_", 1199685769, 1071112295, "_x_x_x_x_bach_float64_x_x_x_x_", 217894015, 1073100043, "_x_x_x_x_bach_float64_x_x_x_x_", 4075411228, 1071053285, "_x_x_x_x_bach_float64_x_x_x_x_", 3193963296, 1073118888, "_x_x_x_x_bach_float64_x_x_x_x_", 2231100780, 1070992625, "_x_x_x_x_bach_float64_x_x_x_x_", 1577679642, 1073137591, "_x_x_x_x_bach_float64_x_x_x_x_", 700213440, 1070930319, "_x_x_x_x_bach_float64_x_x_x_x_", 2200990340, 1073156143, "_x_x_x_x_bach_float64_x_x_x_x_", 2302936835, 1070866372, "_x_x_x_x_bach_float64_x_x_x_x_", 3349901559, 1073174537, "_x_x_x_x_bach_float64_x_x_x_x_", 3350231330, 1070800791, "_x_x_x_x_bach_float64_x_x_x_x_", 3362474598, 1073192766, "_x_x_x_x_bach_float64_x_x_x_x_", 2232293966, 1070733583, "_x_x_x_x_bach_float64_x_x_x_x_", 636888082, 1073210823, "_x_x_x_x_bach_float64_x_x_x_x_", 3711572877, 1070664754, "_x_x_x_x_bach_float64_x_x_x_x_", 2229433439, 1073228699, "_x_x_x_x_bach_float64_x_x_x_x_", 3480925593, 1070592530, "_x_x_x_x_bach_float64_x_x_x_x_", 2387736358, 1073246388, "_x_x_x_x_bach_float64_x_x_x_x_", 1866447879, 1070448438, "_x_x_x_x_bach_float64_x_x_x_x_", 4033646380, 1073263882, "_x_x_x_x_bach_float64_x_x_x_x_", 3060393150, 1070301153, "_x_x_x_x_bach_float64_x_x_x_x_", 1591414333, 1073281175, "_x_x_x_x_bach_float64_x_x_x_x_", 3082805446, 1070150694, "_x_x_x_x_bach_float64_x_x_x_x_", 2470567122, 1073298258, "_x_x_x_x_bach_float64_x_x_x_x_", 2074299668, 1069997080, "_x_x_x_x_bach_float64_x_x_x_x_", 1304132225, 1073315125, "_x_x_x_x_bach_float64_x_x_x_x_", 4286371563, 1069840330, "_x_x_x_x_bach_float64_x_x_x_x_", 1431490625, 1073331768, "_x_x_x_x_bach_float64_x_x_x_x_", 890876911, 1069680467, "_x_x_x_x_bach_float64_x_x_x_x_", 2021477835, 1073348180, "_x_x_x_x_bach_float64_x_x_x_x_", 66381333, 1069487502, "_x_x_x_x_bach_float64_x_x_x_x_", 2375338749, 1073364354, "_x_x_x_x_bach_float64_x_x_x_x_", 2099664182, 1069155450, "_x_x_x_x_bach_float64_x_x_x_x_", 1934698169, 1073380283, "_x_x_x_x_bach_float64_x_x_x_x_", 1794774839, 1068817307, "_x_x_x_x_bach_float64_x_x_x_x_", 289512462, 1073395960, "_x_x_x_x_bach_float64_x_x_x_x_", 2321907498, 1068447300, "_x_x_x_x_bach_float64_x_x_x_x_", 1480967964, 1073411377, "_x_x_x_x_bach_float64_x_x_x_x_", 3365399648, 1067746948, "_x_x_x_x_bach_float64_x_x_x_x_", 1124487881, 1073426528, "_x_x_x_x_bach_float64_x_x_x_x_", 4263070924, 1066619075, "_x_x_x_x_bach_float64_x_x_x_x_", 3597486161, 1073441405, "_x_x_x_x_bach_float64_x_x_x_x_", 2771869961, 3211148122, "_x_x_x_x_bach_float64_x_x_x_x_", 572389943, 1073456003, "_x_x_x_x_bach_float64_x_x_x_x_", 2905057134, 3214490272, "_x_x_x_x_bach_float64_x_x_x_x_", 1089241973, 1073470313, "_x_x_x_x_bach_float64_x_x_x_x_", 2018094991, 3215459320, "_x_x_x_x_bach_float64_x_x_x_x_", 1498731635, 1073484329, "_x_x_x_x_bach_float64_x_x_x_x_", 1798406790, 3216100250, "_x_x_x_x_bach_float64_x_x_x_x_", 2649835202, 1073498044, "_x_x_x_x_bach_float64_x_x_x_x_", 1217878247, 3216485188, "_x_x_x_x_bach_float64_x_x_x_x_", 1307619615, 1073511452, "_x_x_x_x_bach_float64_x_x_x_x_", 2479802998, 3216875705, "_x_x_x_x_bach_float64_x_x_x_x_", 3045848282, 1073524545, "_x_x_x_x_bach_float64_x_x_x_x_", 523181283, 3217151452, "_x_x_x_x_bach_float64_x_x_x_x_", 779812357, 1073537318, "_x_x_x_x_bach_float64_x_x_x_x_", 928619098, 3217352190, "_x_x_x_x_bach_float64_x_x_x_x_", 543764425, 1073549763, "_x_x_x_x_bach_float64_x_x_x_x_", 1099687922, 3217555616, "_x_x_x_x_bach_float64_x_x_x_x_", 23672354, 1073561874, "_x_x_x_x_bach_float64_x_x_x_x_", 2321679507, 3217761694, "_x_x_x_x_bach_float64_x_x_x_x_", 1449670275, 1073573644, "_x_x_x_x_bach_float64_x_x_x_x_", 2105902466, 3217970388, "_x_x_x_x_bach_float64_x_x_x_x_", 3013630136, 1073585067, "_x_x_x_x_bach_float64_x_x_x_x_", 1403587514, 3218130702, "_x_x_x_x_bach_float64_x_x_x_x_", 3171590538, 1073596137, "_x_x_x_x_bach_float64_x_x_x_x_", 1531176447, 3218237608, "_x_x_x_x_bach_float64_x_x_x_x_", 651171970, 1073606848, "_x_x_x_x_bach_float64_x_x_x_x_", 3204812887, 3218345764, "_x_x_x_x_bach_float64_x_x_x_x_", 3048878703, 1073617192, "_x_x_x_x_bach_float64_x_x_x_x_", 2069451997, 3218455151, "_x_x_x_x_bach_float64_x_x_x_x_", 1067612698, 1073627165, "_x_x_x_x_bach_float64_x_x_x_x_", 546383588, 3218565748, "_x_x_x_x_bach_float64_x_x_x_x_", 2883678410, 1073636759, "_x_x_x_x_bach_float64_x_x_x_x_", 3554278832, 3218677533, "_x_x_x_x_bach_float64_x_x_x_x_", 4089225271, 1073645969, "_x_x_x_x_bach_float64_x_x_x_x_", 1345773828, 3218790487, "_x_x_x_x_bach_float64_x_x_x_x_", 584308611, 1073654790, "_x_x_x_x_bach_float64_x_x_x_x_", 3884096611, 3218904586, "_x_x_x_x_bach_float64_x_x_x_x_", 1468894459, 1073663214, "_x_x_x_x_bach_float64_x_x_x_x_", 2205682675, 3219019810, "_x_x_x_x_bach_float64_x_x_x_x_", 3280100910, 1073671236, "_x_x_x_x_bach_float64_x_x_x_x_", 3546315797, 3219132227, "_x_x_x_x_bach_float64_x_x_x_x_", 2884085864, 1073678851, "_x_x_x_x_bach_float64_x_x_x_x_", 3070605634, 3219190929, "_x_x_x_x_bach_float64_x_x_x_x_", 1777939209, 1073686053, "_x_x_x_x_bach_float64_x_x_x_x_", 1217581901, 3219250159, "_x_x_x_x_bach_float64_x_x_x_x_", 1801577947, 1073692836, "_x_x_x_x_bach_float64_x_x_x_x_", 2987395399, 3219309904, "_x_x_x_x_bach_float64_x_x_x_x_", 849577228, 1073699195, "_x_x_x_x_bach_float64_x_x_x_x_", 3963292675, 3219370153, "_x_x_x_x_bach_float64_x_x_x_x_", 1467837677, 1073705124, "_x_x_x_x_bach_float64_x_x_x_x_", 3206442117, 3219430894, "_x_x_x_x_bach_float64_x_x_x_x_", 2270316374, 1073710618, "_x_x_x_x_bach_float64_x_x_x_x_", 3266062509, 3219492114, "_x_x_x_x_bach_float64_x_x_x_x_", 2240591053, 1073715672, "_x_x_x_x_bach_float64_x_x_x_x_", 1599819470, 3219553801, "_x_x_x_x_bach_float64_x_x_x_x_", 738386777, 1073720281, "_x_x_x_x_bach_float64_x_x_x_x_", 3469258952, 3219615941, "_x_x_x_x_bach_float64_x_x_x_x_", 1800998243, 1073724439, "_x_x_x_x_bach_float64_x_x_x_x_", 475700972, 3219678523, "_x_x_x_x_bach_float64_x_x_x_x_", 1264769688, 1073728142, "_x_x_x_x_bach_float64_x_x_x_x_", 635937370, 3219741532, "_x_x_x_x_bach_float64_x_x_x_x_", 3951271225, 1073731384, "_x_x_x_x_bach_float64_x_x_x_x_", 2623549302, 3219804955, "_x_x_x_x_bach_float64_x_x_x_x_", 2198693359, 1073734162, "_x_x_x_x_bach_float64_x_x_x_x_", 75188137, 3219868780, "_x_x_x_x_bach_float64_x_x_x_x_", 1637804213, 1073736470, "_x_x_x_x_bach_float64_x_x_x_x_", 3076915783, 3219932991, "_x_x_x_x_bach_float64_x_x_x_x_", 4018154772, 1073738303, "_x_x_x_x_bach_float64_x_x_x_x_", 3816158254, 3219997576, "_x_x_x_x_bach_float64_x_x_x_x_", 2919105606, 1073739658, "_x_x_x_x_bach_float64_x_x_x_x_", 2363387088, 3220062521, "_x_x_x_x_bach_float64_x_x_x_x_", 935608215, 1073740530, "_x_x_x_x_bach_float64_x_x_x_x_", 2389213340, 3220127811, "_x_x_x_x_bach_float64_x_x_x_x_", 1094099414, 1073740914, "_x_x_x_x_bach_float64_x_x_x_x_", 1293347730, 3220185164, "_x_x_x_x_bach_float64_x_x_x_x_", 2563278412, 1073740806, "_x_x_x_x_bach_float64_x_x_x_x_", 489363956, 3220218133, "_x_x_x_x_bach_float64_x_x_x_x_", 659765243, 1073740203, "_x_x_x_x_bach_float64_x_x_x_x_", 3907770474, 3220251252, "_x_x_x_x_bach_float64_x_x_x_x_", 4033541111, 1073739099, "_x_x_x_x_bach_float64_x_x_x_x_", 1318899723, 3220284516, "_x_x_x_x_bach_float64_x_x_x_x_", 313692551, 1073737493, "_x_x_x_x_bach_float64_x_x_x_x_", 3651995225, 3220317915, "_x_x_x_x_bach_float64_x_x_x_x_", 3358444330, 1073735378, "_x_x_x_x_bach_float64_x_x_x_x_", 52094876, 3220351444, "_x_x_x_x_bach_float64_x_x_x_x_", 1720853323, 1073732753, "_x_x_x_x_bach_float64_x_x_x_x_", 836343439, 3220385093, "_x_x_x_x_bach_float64_x_x_x_x_", 1603690428, 1073729613, "_x_x_x_x_bach_float64_x_x_x_x_", 3140975656, 3220418855, "_x_x_x_x_bach_float64_x_x_x_x_", 1094752021, 1073725955, "_x_x_x_x_bach_float64_x_x_x_x_", 3813020315, 3220452723, "_x_x_x_x_bach_float64_x_x_x_x_", 3056782101, 1073721775, "_x_x_x_x_bach_float64_x_x_x_x_", 3712149005, 3220486689, "_x_x_x_x_bach_float64_x_x_x_x_", 2247494498, 1073717071, "_x_x_x_x_bach_float64_x_x_x_x_", 3422668307, 3220520745, "_x_x_x_x_bach_float64_x_x_x_x_", 2504268747, 1073711839, "_x_x_x_x_bach_float64_x_x_x_x_", 3260555887, 3220554883, "_x_x_x_x_bach_float64_x_x_x_x_", 3863976337, 1073706076, "_x_x_x_x_bach_float64_x_x_x_x_", 3280571825, 3220589095, "_x_x_x_x_bach_float64_x_x_x_x_", 2567609126, 1073699780, "_x_x_x_x_bach_float64_x_x_x_x_", 3283443814, 3220623373, "_x_x_x_x_bach_float64_x_x_x_x_", 3949708756, 1073692947, "_x_x_x_x_bach_float64_x_x_x_x_", 2823124742, 3220657709, "_x_x_x_x_bach_float64_x_x_x_x_", 967955748, 1073685576, "_x_x_x_x_bach_float64_x_x_x_x_", 1214121309, 3220692095, "_x_x_x_x_bach_float64_x_x_x_x_", 4272263003, 1073677662, "_x_x_x_x_bach_float64_x_x_x_x_", 1833859470, 3220726522, "_x_x_x_x_bach_float64_x_x_x_x_", 3554288423, 1073669205, "_x_x_x_x_bach_float64_x_x_x_x_", 3540216084, 3220760982, "_x_x_x_x_bach_float64_x_x_x_x_", 1911286299, 1073660202, "_x_x_x_x_bach_float64_x_x_x_x_", 679051773, 3220795468, "_x_x_x_x_bach_float64_x_x_x_x_", 2965212174, 1073650650, "_x_x_x_x_bach_float64_x_x_x_x_", 271678027, 3220829970, "_x_x_x_x_bach_float64_x_x_x_x_", 2276687671, 1073640548, "_x_x_x_x_bach_float64_x_x_x_x_", 547682302, 3220864480, "_x_x_x_x_bach_float64_x_x_x_x_", 233693509, 1073629894, "_x_x_x_x_bach_float64_x_x_x_x_", 3837553535, 3220898989, "_x_x_x_x_bach_float64_x_x_x_x_", 2055251313, 1073618685, "_x_x_x_x_bach_float64_x_x_x_x_", 3695564416, 3220933490, "_x_x_x_x_bach_float64_x_x_x_x_", 615126010, 1073606921, "_x_x_x_x_bach_float64_x_x_x_x_", 2087483722, 3220967974, "_x_x_x_x_bach_float64_x_x_x_x_", 2215089984, 1073594599, "_x_x_x_x_bach_float64_x_x_x_x_", 808542302, 3221002432, "_x_x_x_x_bach_float64_x_x_x_x_", 818467562, 1073581719, "_x_x_x_x_bach_float64_x_x_x_x_", 1491389438, 3221036855, "_x_x_x_x_bach_float64_x_x_x_x_", 3823174062, 1073568278, "_x_x_x_x_bach_float64_x_x_x_x_", 1319136209, 3221071235, "_x_x_x_x_bach_float64_x_x_x_x_", 2000066108, 1073554277, "_x_x_x_x_bach_float64_x_x_x_x_", 1623353330, 3221105563, "_x_x_x_x_bach_float64_x_x_x_x_", 3855686666, 1073539713, "_x_x_x_x_bach_float64_x_x_x_x_", 3597218126, 3221139830, "_x_x_x_x_bach_float64_x_x_x_x_", 1275417787, 1073524587, "_x_x_x_x_bach_float64_x_x_x_x_", 4008710897, 3221174028, "_x_x_x_x_bach_float64_x_x_x_x_", 3885993712, 1073508896, "_x_x_x_x_bach_float64_x_x_x_x_", 3798760849, 3221208148, "_x_x_x_x_bach_float64_x_x_x_x_", 403452834, 1073492642, "_x_x_x_x_bach_float64_x_x_x_x_", 4044751783, 3221233826, "_x_x_x_x_bach_float64_x_x_x_x_", 1585350356, 1073475822, "_x_x_x_x_bach_float64_x_x_x_x_", 2358873184, 3221250795, "_x_x_x_x_bach_float64_x_x_x_x_", 1578473693, 1073458437, "_x_x_x_x_bach_float64_x_x_x_x_", 3596492920, 3221267711, "_x_x_x_x_bach_float64_x_x_x_x_", 3690947976, 1073440486, "_x_x_x_x_bach_float64_x_x_x_x_", 1583092950, 3221284571, "_x_x_x_x_bach_float64_x_x_x_x_", 3214548527, 1073421970, "_x_x_x_x_bach_float64_x_x_x_x_", 2988905127, 3221301369, "_x_x_x_x_bach_float64_x_x_x_x_", 311663748, 1073402889, "_x_x_x_x_bach_float64_x_x_x_x_", 1563338711, 3221318102, "_x_x_x_x_bach_float64_x_x_x_x_", 17234718, 1073383242, "_x_x_x_x_bach_float64_x_x_x_x_", 3909033361, 3221334764, "_x_x_x_x_bach_float64_x_x_x_x_", 3650638283, 1073363029, "_x_x_x_x_bach_float64_x_x_x_x_", 3716321672, 3221351352, "_x_x_x_x_bach_float64_x_x_x_x_", 227447546, 1073342253, "_x_x_x_x_bach_float64_x_x_x_x_", 3242348167, 3221367861, "_x_x_x_x_bach_float64_x_x_x_x_", 820742218, 1073320912, "_x_x_x_x_bach_float64_x_x_x_x_", 430465285, 3221384287, "_x_x_x_x_bach_float64_x_x_x_x_", 4202818542, 1073299007, "_x_x_x_x_bach_float64_x_x_x_x_", 1799447562, 3221400624, "_x_x_x_x_bach_float64_x_x_x_x_", 1141480699, 1073276541, "_x_x_x_x_bach_float64_x_x_x_x_", 972981054, 3221416869, "_x_x_x_x_bach_float64_x_x_x_x_", 171043990, 1073253513, "_x_x_x_x_bach_float64_x_x_x_x_", 158838408, 3221433017, "_x_x_x_x_bach_float64_x_x_x_x_", 1823605320, 1073229924, "_x_x_x_x_bach_float64_x_x_x_x_", 1563294631, 3221449063, "_x_x_x_x_bach_float64_x_x_x_x_", 2924959143, 1073205776, "_x_x_x_x_bach_float64_x_x_x_x_", 3100521102, 3221465003, "_x_x_x_x_bach_float64_x_x_x_x_", 890387352, 1073181071, "_x_x_x_x_bach_float64_x_x_x_x_", 2691924134, 3221480833, "_x_x_x_x_bach_float64_x_x_x_x_", 2315290095, 1073155809, "_x_x_x_x_bach_float64_x_x_x_x_", 2565492677, 3221496548, "_x_x_x_x_bach_float64_x_x_x_x_", 1500918678, 1073129993, "_x_x_x_x_bach_float64_x_x_x_x_", 670252328, 3221512144, "_x_x_x_x_bach_float64_x_x_x_x_", 1929654308, 1073103624, "_x_x_x_x_bach_float64_x_x_x_x_", 3565563094, 3221527615, "_x_x_x_x_bach_float64_x_x_x_x_", 3380421000, 1073076704, "_x_x_x_x_bach_float64_x_x_x_x_", 655717905, 3221542959, "_x_x_x_x_bach_float64_x_x_x_x_", 1928872628, 1073049236, "_x_x_x_x_bach_float64_x_x_x_x_", 2849056024, 3221558169, "_x_x_x_x_bach_float64_x_x_x_x_", 2832353820, 1073021221, "_x_x_x_x_bach_float64_x_x_x_x_", 3907669678, 3221573242, "_x_x_x_x_bach_float64_x_x_x_x_", 3349961553, 1072992662, "_x_x_x_x_bach_float64_x_x_x_x_", 1926656499, 3221588174, "_x_x_x_x_bach_float64_x_x_x_x_", 1332282002, 1072963562, "_x_x_x_x_bach_float64_x_x_x_x_", 3633505475, 3221602959, "_x_x_x_x_bach_float64_x_x_x_x_", 3810998734, 1072933922, "_x_x_x_x_bach_float64_x_x_x_x_", 2917680948, 3221617594, "_x_x_x_x_bach_float64_x_x_x_x_", 1228633690, 1072903747, "_x_x_x_x_bach_float64_x_x_x_x_", 2309880457, 3221632074, "_x_x_x_x_bach_float64_x_x_x_x_", 1797701323, 1072873038, "_x_x_x_x_bach_float64_x_x_x_x_", 101554133, 3221646395, "_x_x_x_x_bach_float64_x_x_x_x_", 1435224233, 1072841799, "_x_x_x_x_bach_float64_x_x_x_x_", 3234226940, 3221660551, "_x_x_x_x_bach_float64_x_x_x_x_", 941759834, 1072810033, "_x_x_x_x_bach_float64_x_x_x_x_", 1534113343, 3221674540, "_x_x_x_x_bach_float64_x_x_x_x_", 1705461333, 1072777743, "_x_x_x_x_bach_float64_x_x_x_x_", 2076271292, 3221688356, "_x_x_x_x_bach_float64_x_x_x_x_", 1406009422, 1072744933, "_x_x_x_x_bach_float64_x_x_x_x_", 3419210335, 3221701995, "_x_x_x_x_bach_float64_x_x_x_x_", 2603316549, 1072711606, "_x_x_x_x_bach_float64_x_x_x_x_", 4199233384, 3221715453, "_x_x_x_x_bach_float64_x_x_x_x_", 3997498292, 1072662285, "_x_x_x_x_bach_float64_x_x_x_x_", 3134838323, 3221728726, "_x_x_x_x_bach_float64_x_x_x_x_", 2342114096, 1072593588, "_x_x_x_x_bach_float64_x_x_x_x_", 3326080354, 3221741809, "_x_x_x_x_bach_float64_x_x_x_x_", 264609224, 1072523881, "_x_x_x_x_bach_float64_x_x_x_x_", 3669024999, 3221754698, "_x_x_x_x_bach_float64_x_x_x_x_", 3242182015, 1072453171, "_x_x_x_x_bach_float64_x_x_x_x_", 3155094600, 3221767389, "_x_x_x_x_bach_float64_x_x_x_x_", 726512065, 1072381469, "_x_x_x_x_bach_float64_x_x_x_x_", 875438206, 3221779878, "_x_x_x_x_bach_float64_x_x_x_x_", 499489099, 1072308782, "_x_x_x_x_bach_float64_x_x_x_x_", 320258494, 3221792160, "_x_x_x_x_bach_float64_x_x_x_x_", 2899142569, 1072235119, "_x_x_x_x_bach_float64_x_x_x_x_", 793225651, 3221804231, "_x_x_x_x_bach_float64_x_x_x_x_", 815118108, 1072160491, "_x_x_x_x_bach_float64_x_x_x_x_", 1710781026, 3221816087, "_x_x_x_x_bach_float64_x_x_x_x_", 1158734131, 1072084906, "_x_x_x_x_bach_float64_x_x_x_x_", 2606460472, 3221827724, "_x_x_x_x_bach_float64_x_x_x_x_", 3383109639, 1072008374, "_x_x_x_x_bach_float64_x_x_x_x_", 3135203738, 3221839138, "_x_x_x_x_bach_float64_x_x_x_x_", 3772840428, 1071930906, "_x_x_x_x_bach_float64_x_x_x_x_", 3077648986, 3221850325, "_x_x_x_x_bach_float64_x_x_x_x_", 4028388029, 1071852512, "_x_x_x_x_bach_float64_x_x_x_x_", 2344411530, 3221861281, "_x_x_x_x_bach_float64_x_x_x_x_", 2670345325, 1071773203, "_x_x_x_x_bach_float64_x_x_x_x_", 980345852, 3221872002, "_x_x_x_x_bach_float64_x_x_x_x_", 3623318107, 1071692989, "_x_x_x_x_bach_float64_x_x_x_x_", 3463757298, 3221882483, "_x_x_x_x_bach_float64_x_x_x_x_", 2354467927, 1071579093, "_x_x_x_x_bach_float64_x_x_x_x_", 1530758767, 3221892722, "_x_x_x_x_bach_float64_x_x_x_x_", 2911242851, 1071415115, "_x_x_x_x_bach_float64_x_x_x_x_", 4244248171, 3221902713, "_x_x_x_x_bach_float64_x_x_x_x_", 1867930837, 1071249397, "_x_x_x_x_bach_float64_x_x_x_x_", 3638356133, 3221912454, "_x_x_x_x_bach_float64_x_x_x_x_", 2930069418, 1071081962, "_x_x_x_x_bach_float64_x_x_x_x_", 492414540, 3221921941, "_x_x_x_x_bach_float64_x_x_x_x_", 3363280688, 1070912835, "_x_x_x_x_bach_float64_x_x_x_x_", 40131862, 3221931169, "_x_x_x_x_bach_float64_x_x_x_x_", 2568096120, 1070742041, "_x_x_x_x_bach_float64_x_x_x_x_", 3383778105, 3221940134, "_x_x_x_x_bach_float64_x_x_x_x_", 4128706354, 1070543114, "_x_x_x_x_bach_float64_x_x_x_x_", 3203313093, 3221948834, "_x_x_x_x_bach_float64_x_x_x_x_", 2360266206, 1070195010, "_x_x_x_x_bach_float64_x_x_x_x_", 940326364, 3221957265, "_x_x_x_x_bach_float64_x_x_x_x_", 2660289115, 1069843726, "_x_x_x_x_bach_float64_x_x_x_x_", 2507114838, 3221965422, "_x_x_x_x_bach_float64_x_x_x_x_", 2519776079, 1069431113, "_x_x_x_x_bach_float64_x_x_x_x_", 1110831976, 3221973303, "_x_x_x_x_bach_float64_x_x_x_x_", 1283329652, 1068716151, "_x_x_x_x_bach_float64_x_x_x_x_", 3027282347, 3221980903, "_x_x_x_x_bach_float64_x_x_x_x_", 3654817457, 1067491370, "_x_x_x_x_bach_float64_x_x_x_x_", 1835080284, 3221988220, "_x_x_x_x_bach_float64_x_x_x_x_", 3639264860, 3213245272, "_x_x_x_x_bach_float64_x_x_x_x_", 4189386788, 3221995249, "_x_x_x_x_bach_float64_x_x_x_x_", 74412183, 3215715119, "_x_x_x_x_bach_float64_x_x_x_x_", 4056008779, 3222001988, "_x_x_x_x_bach_float64_x_x_x_x_", 664938656, 3216587259, "_x_x_x_x_bach_float64_x_x_x_x_", 4190107560, 3222008433, "_x_x_x_x_bach_float64_x_x_x_x_", 3422610366, 3217181199, "_x_x_x_x_bach_float64_x_x_x_x_", 3255137079, 3222014581, "_x_x_x_x_bach_float64_x_x_x_x_", 1226792956, 3217555910, "_x_x_x_x_bach_float64_x_x_x_x_", 121618651, 3222020429, "_x_x_x_x_bach_float64_x_x_x_x_", 104779449, 3217933284, "_x_x_x_x_bach_float64_x_x_x_x_", 2460849410, 3222025972, "_x_x_x_x_bach_float64_x_x_x_x_", 2387421290, 3218196501, "_x_x_x_x_bach_float64_x_x_x_x_", 978837988, 3222031209, "_x_x_x_x_bach_float64_x_x_x_x_", 1662468244, 3218387758, "_x_x_x_x_bach_float64_x_x_x_x_", 3779747087, 3222036135, "_x_x_x_x_bach_float64_x_x_x_x_", 2955931659, 3218580252, "_x_x_x_x_bach_float64_x_x_x_x_", 2009823238, 3222040749, "_x_x_x_x_bach_float64_x_x_x_x_", 928479713, 3218773952, "_x_x_x_x_bach_float64_x_x_x_x_", 4220766403, 3222045046, "_x_x_x_x_bach_float64_x_x_x_x_", 1321009688, 3218968824, "_x_x_x_x_bach_float64_x_x_x_x_", 2013585096, 3222049025, "_x_x_x_x_bach_float64_x_x_x_x_", 4046656105, 3219146577, "_x_x_x_x_bach_float64_x_x_x_x_", 106922428, 3222052682, "_x_x_x_x_bach_float64_x_x_x_x_", 3134103329, 3219245136, "_x_x_x_x_bach_float64_x_x_x_x_", 3455669835, 3222056013, "_x_x_x_x_bach_float64_x_x_x_x_", 2452825808, 3219344231, "_x_x_x_x_bach_float64_x_x_x_x_", 74573361, 3222059018, "_x_x_x_x_bach_float64_x_x_x_x_", 1383936700, 3219443845, "_x_x_x_x_bach_float64_x_x_x_x_", 3991341166, 3222061691, "_x_x_x_x_bach_float64_x_x_x_x_", 2762263940, 3219543960, "_x_x_x_x_bach_float64_x_x_x_x_", 3710428770, 3222064032, "_x_x_x_x_bach_float64_x_x_x_x_", 4304646, 3219644560, "_x_x_x_x_bach_float64_x_x_x_x_", 871095025, 3222066038, "_x_x_x_x_bach_float64_x_x_x_x_", 2891093889, 3219745625, "_x_x_x_x_bach_float64_x_x_x_x_", 1660774549, 3222067705, "_x_x_x_x_bach_float64_x_x_x_x_", 3221736797, 3219847139, "_x_x_x_x_bach_float64_x_x_x_x_", 3933438818, 3222069031, "_x_x_x_x_bach_float64_x_x_x_x_", 596686943, 3219949084, "_x_x_x_x_bach_float64_x_x_x_x_", 1507781644, 3222070015, "_x_x_x_x_bach_float64_x_x_x_x_", 2431421976, 3220051440, "_x_x_x_x_bach_float64_x_x_x_x_", 1350260990, 3222070653, "_x_x_x_x_bach_float64_x_x_x_x_", 2495481736, 3220154190, "_x_x_x_x_bach_float64_x_x_x_x_", 2103388830, 3222070943, "_x_x_x_x_bach_float64_x_x_x_x_", 3348171726, 3220217105, "_x_x_x_x_bach_float64_x_x_x_x_", 2678745062, 3222070883, "_x_x_x_x_bach_float64_x_x_x_x_", 1514457847, 3220268846, "_x_x_x_x_bach_float64_x_x_x_x_", 2260009059, 3222070471, "_x_x_x_x_bach_float64_x_x_x_x_", 2269834183, 3220320755, "_x_x_x_x_bach_float64_x_x_x_x_", 305942777, 3222069705, "_x_x_x_x_bach_float64_x_x_x_x_", 3195802731, 3220372823, "_x_x_x_x_bach_float64_x_x_x_x_", 848291961, 3222068582, "_x_x_x_x_bach_float64_x_x_x_x_", 1529483180, 3220425041, "_x_x_x_x_bach_float64_x_x_x_x_", 3904735609, 3222067100, "_x_x_x_x_bach_float64_x_x_x_x_", 2761055602, 3220477398, "_x_x_x_x_bach_float64_x_x_x_x_", 1186752139, 3222065259, "_x_x_x_x_bach_float64_x_x_x_x_", 3461489659, 3220529885, "_x_x_x_x_bach_float64_x_x_x_x_", 1872205398, 3222063055, "_x_x_x_x_bach_float64_x_x_x_x_", 4175134318, 3220582492, "_x_x_x_x_bach_float64_x_x_x_x_", 2543303898, 3222060487, "_x_x_x_x_bach_float64_x_x_x_x_", 837558709, 3220635210, "_x_x_x_x_bach_float64_x_x_x_x_", 74180418, 3222057554, "_x_x_x_x_bach_float64_x_x_x_x_", 1963283189, 3220688027, "_x_x_x_x_bach_float64_x_x_x_x_", 223451075, 3222054253, "_x_x_x_x_bach_float64_x_x_x_x_", 2883922568, 3220740934, "_x_x_x_x_bach_float64_x_x_x_x_", 456916742, 3222050583, "_x_x_x_x_bach_float64_x_x_x_x_", 2936085612, 3220793921, "_x_x_x_x_bach_float64_x_x_x_x_", 2834980996, 3222046542, "_x_x_x_x_bach_float64_x_x_x_x_", 1174520399, 3220846978, "_x_x_x_x_bach_float64_x_x_x_x_", 1130209169, 3222042130, "_x_x_x_x_bach_float64_x_x_x_x_", 675274724, 3220900094, "_x_x_x_x_bach_float64_x_x_x_x_", 2304570000, 3222037344, "_x_x_x_x_bach_float64_x_x_x_x_", 4249001022, 3220953258, "_x_x_x_x_bach_float64_x_x_x_x_", 741980643, 3222032184, "_x_x_x_x_bach_float64_x_x_x_x_", 1564404485, 3221006462, "_x_x_x_x_bach_float64_x_x_x_x_", 4020402312, 3222026647, "_x_x_x_x_bach_float64_x_x_x_x_", 3516407266, 3221059693, "_x_x_x_x_bach_float64_x_x_x_x_", 2849303476, 3222020734, "_x_x_x_x_bach_float64_x_x_x_x_", 3579943423, 3221112942, "_x_x_x_x_bach_float64_x_x_x_x_", 1136607135, 3222014443, "_x_x_x_x_bach_float64_x_x_x_x_", 3588336115, 3221166198, "_x_x_x_x_bach_float64_x_x_x_x_", 3105906406, 3222007772, "_x_x_x_x_bach_float64_x_x_x_x_", 857040514, 3221219451, "_x_x_x_x_bach_float64_x_x_x_x_", 413620900, 3222000722, "_x_x_x_x_bach_float64_x_x_x_x_", 2686113871, 3221249080, "_x_x_x_x_bach_float64_x_x_x_x_", 2215766280, 3221993290, "_x_x_x_x_bach_float64_x_x_x_x_", 572430945, 3221275687, "_x_x_x_x_bach_float64_x_x_x_x_", 810154050, 3221985477, "_x_x_x_x_bach_float64_x_x_x_x_", 3174545807, 3221302275, "_x_x_x_x_bach_float64_x_x_x_x_", 1703039973, 3221977281, "_x_x_x_x_bach_float64_x_x_x_x_", 158360155, 3221328841, "_x_x_x_x_bach_float64_x_x_x_x_", 2136103609, 3221968702, "_x_x_x_x_bach_float64_x_x_x_x_", 2575281075, 3221355377, "_x_x_x_x_bach_float64_x_x_x_x_", 3973104341, 3221959739, "_x_x_x_x_bach_float64_x_x_x_x_", 4212034947, 3221381879, "_x_x_x_x_bach_float64_x_x_x_x_", 816671368, 3221950393, "_x_x_x_x_bach_float64_x_x_x_x_", 3070053303, 3221408342, "_x_x_x_x_bach_float64_x_x_x_x_", 3779736498, 3221940661, "_x_x_x_x_bach_float64_x_x_x_x_", 1370051400, 3221434760, "_x_x_x_x_bach_float64_x_x_x_x_", 2832394308, 3221930545, "_x_x_x_x_bach_float64_x_x_x_x_", 1261667596, 3221461127, "_x_x_x_x_bach_float64_x_x_x_x_", 1163142566, 3221920044, "_x_x_x_x_bach_float64_x_x_x_x_", 533130179, 3221487438, "_x_x_x_x_bach_float64_x_x_x_x_", 2295418285, 3221909157, "_x_x_x_x_bach_float64_x_x_x_x_", 1205852478, 3221513687, "_x_x_x_x_bach_float64_x_x_x_x_", 1499036501, 3221897885, "_x_x_x_x_bach_float64_x_x_x_x_", 949184387, 3221539869, "_x_x_x_x_bach_float64_x_x_x_x_", 2971367795, 3221886227, "_x_x_x_x_bach_float64_x_x_x_x_", 1675057843, 3221565978, "_x_x_x_x_bach_float64_x_x_x_x_", 2658712097, 3221874184, "_x_x_x_x_bach_float64_x_x_x_x_", 952786798, 3221592009, "_x_x_x_x_bach_float64_x_x_x_x_", 1142377752, 3221861756, "_x_x_x_x_bach_float64_x_x_x_x_", 603759429, 3221617956, "_x_x_x_x_bach_float64_x_x_x_x_", 3639792522, 3221848942, "_x_x_x_x_bach_float64_x_x_x_x_", 2411250336, 3221643813, "_x_x_x_x_bach_float64_x_x_x_x_", 2825678926, 3221835744, "_x_x_x_x_bach_float64_x_x_x_x_", 3830253869, 3221669575, "_x_x_x_x_bach_float64_x_x_x_x_", 307868281, 3221822162, "_x_x_x_x_bach_float64_x_x_x_x_", 2287272249, 3221695237, "_x_x_x_x_bach_float64_x_x_x_x_", 2333243816, 3221808195, "_x_x_x_x_bach_float64_x_x_x_x_", 3775090137, 3221720792, "_x_x_x_x_bach_float64_x_x_x_x_", 2608714291, 3221793845, "_x_x_x_x_bach_float64_x_x_x_x_", 1382796555, 3221746236, "_x_x_x_x_bach_float64_x_x_x_x_", 3776825436, 3221779112, "_x_x_x_x_bach_float64_x_x_x_x_", 1070464351, 3221771562, "_x_x_x_x_bach_float64_x_x_x_x_", 236597572, 3221763998, "_x_x_x_x_bach_float64_x_x_x_x_", 199205857, 3221796765, "_x_x_x_x_bach_float64_x_x_x_x_", 3913967667, 3221748501, "_x_x_x_x_bach_float64_x_x_x_x_", 420982487, 3221821839, "_x_x_x_x_bach_float64_x_x_x_x_", 1312686001, 3221732625, "_x_x_x_x_bach_float64_x_x_x_x_", 3388559557, 3221846778, "_x_x_x_x_bach_float64_x_x_x_x_", 759456963, 3221716369, "_x_x_x_x_bach_float64_x_x_x_x_", 2170507545, 3221871578, "_x_x_x_x_bach_float64_x_x_x_x_", 2339599332, 3221699734, "_x_x_x_x_bach_float64_x_x_x_x_", 2730986957, 3221896232, "_x_x_x_x_bach_float64_x_x_x_x_", 2192375407, 3221682722, "_x_x_x_x_bach_float64_x_x_x_x_", 2459871901, 3221920735, "_x_x_x_x_bach_float64_x_x_x_x_", 1101217701, 3221665334, "_x_x_x_x_bach_float64_x_x_x_x_", 3062622820, 3221945081, "_x_x_x_x_bach_float64_x_x_x_x_", 198983869, 3221647571, "_x_x_x_x_bach_float64_x_x_x_x_", 1975332358, 3221969265, "_x_x_x_x_bach_float64_x_x_x_x_", 968108756, 3221629434, "_x_x_x_x_bach_float64_x_x_x_x_", 959649278, 3221993281, "_x_x_x_x_bach_float64_x_x_x_x_", 945718876, 3221610925, "_x_x_x_x_bach_float64_x_x_x_x_", 1812808210, 3222017123, "_x_x_x_x_bach_float64_x_x_x_x_", 2313578305, 3221592045, "_x_x_x_x_bach_float64_x_x_x_x_", 2077666182, 3222040786, "_x_x_x_x_bach_float64_x_x_x_x_", 3308094718, 3221572796, "_x_x_x_x_bach_float64_x_x_x_x_", 3637646954, 3222064264, "_x_x_x_x_bach_float64_x_x_x_x_", 2515156588, 3221553180, "_x_x_x_x_bach_float64_x_x_x_x_", 4131820871, 3222087552, "_x_x_x_x_bach_float64_x_x_x_x_", 3164899428, 3221533198, "_x_x_x_x_bach_float64_x_x_x_x_", 1254890572, 3222110645, "_x_x_x_x_bach_float64_x_x_x_x_", 246531852, 3221512853, "_x_x_x_x_bach_float64_x_x_x_x_", 1352146762, 3222133536, "_x_x_x_x_bach_float64_x_x_x_x_", 1982828898, 3221492145, "_x_x_x_x_bach_float64_x_x_x_x_", 2244622071, 3222156220, "_x_x_x_x_bach_float64_x_x_x_x_", 4059913813, 3221471077, "_x_x_x_x_bach_float64_x_x_x_x_", 1824049629, 3222178692, "_x_x_x_x_bach_float64_x_x_x_x_", 2511674308, 3221449652, "_x_x_x_x_bach_float64_x_x_x_x_", 2352854098, 3222200946, "_x_x_x_x_bach_float64_x_x_x_x_", 2309140058, 3221427871, "_x_x_x_x_bach_float64_x_x_x_x_", 1879239781, 3222222977, "_x_x_x_x_bach_float64_x_x_x_x_", 179985149, 3221405737, "_x_x_x_x_bach_float64_x_x_x_x_", 2832145706, 3222244779, "_x_x_x_x_bach_float64_x_x_x_x_", 1787697339, 3221383251, "_x_x_x_x_bach_float64_x_x_x_x_", 3436328446, 3222266347, "_x_x_x_x_bach_float64_x_x_x_x_", 255970300, 3221360417, "_x_x_x_x_bach_float64_x_x_x_x_", 1006171325, 3222280862, "_x_x_x_x_bach_float64_x_x_x_x_", 1937664643, 3221337236, "_x_x_x_x_bach_float64_x_x_x_x_", 638258209, 3222291404, "_x_x_x_x_bach_float64_x_x_x_x_", 644089879, 3221313712, "_x_x_x_x_bach_float64_x_x_x_x_", 4172976644, 3222301820, "_x_x_x_x_bach_float64_x_x_x_x_", 3413822621, 3221289846, "_x_x_x_x_bach_float64_x_x_x_x_", 191894312, 3222312110, "_x_x_x_x_bach_float64_x_x_x_x_", 446878439, 3221265643, "_x_x_x_x_bach_float64_x_x_x_x_", 3104277449, 3222322268, "_x_x_x_x_bach_float64_x_x_x_x_", 3758289187, 3221241103, "_x_x_x_x_bach_float64_x_x_x_x_", 1609972020, 3222332294, "_x_x_x_x_bach_float64_x_x_x_x_", 4159493578, 3221206991, "_x_x_x_x_bach_float64_x_x_x_x_", 1651560313, 3222342184, "_x_x_x_x_bach_float64_x_x_x_x_", 3321043360, 3221156588, "_x_x_x_x_bach_float64_x_x_x_x_", 647035229, 3222351936, "_x_x_x_x_bach_float64_x_x_x_x_", 992634346, 3221105532, "_x_x_x_x_bach_float64_x_x_x_x_", 377174119, 3222361547, "_x_x_x_x_bach_float64_x_x_x_x_", 2425516758, 3221053828, "_x_x_x_x_bach_float64_x_x_x_x_", 2693036864, 3222371014, "_x_x_x_x_bach_float64_x_x_x_x_", 652980409, 3221001484, "_x_x_x_x_bach_float64_x_x_x_x_", 928489538, 3222380336, "_x_x_x_x_bach_float64_x_x_x_x_", 2257049503, 3220948505, "_x_x_x_x_bach_float64_x_x_x_x_", 1377491549, 3222389509, "_x_x_x_x_bach_float64_x_x_x_x_", 1595428521, 3220894899, "_x_x_x_x_bach_float64_x_x_x_x_", 1821701742, 3222398531, "_x_x_x_x_bach_float64_x_x_x_x_", 2272947776, 3220840672, "_x_x_x_x_bach_float64_x_x_x_x_", 122846932, 3222407400, "_x_x_x_x_bach_float64_x_x_x_x_", 4253129852, 3220785831, "_x_x_x_x_bach_float64_x_x_x_x_", 2815081382, 3222416112, "_x_x_x_x_bach_float64_x_x_x_x_", 3854517979, 3220730384, "_x_x_x_x_bach_float64_x_x_x_x_", 3632565567, 3222424666, "_x_x_x_x_bach_float64_x_x_x_x_", 2336799319, 3220674338, "_x_x_x_x_bach_float64_x_x_x_x_", 691740526, 3222433060, "_x_x_x_x_bach_float64_x_x_x_x_", 1601886905, 3220617700, "_x_x_x_x_bach_float64_x_x_x_x_", 788689741, 3222441290, "_x_x_x_x_bach_float64_x_x_x_x_", 4189830347, 3220560477, "_x_x_x_x_bach_float64_x_x_x_x_", 2221653414, 3222449354, "_x_x_x_x_bach_float64_x_x_x_x_", 389686097, 3220502679, "_x_x_x_x_bach_float64_x_x_x_x_", 3383334977, 3222457250, "_x_x_x_x_bach_float64_x_x_x_x_", 2594890333, 3220444311, "_x_x_x_x_bach_float64_x_x_x_x_", 2763260901, 3222464976, "_x_x_x_x_bach_float64_x_x_x_x_", 2349083313, 3220385383, "_x_x_x_x_bach_float64_x_x_x_x_", 3245095236, 3222472529, "_x_x_x_x_bach_float64_x_x_x_x_", 406240909, 3220325903, "_x_x_x_x_bach_float64_x_x_x_x_", 3519039230, 3222479907, "_x_x_x_x_bach_float64_x_x_x_x_", 2430931989, 3220265878, "_x_x_x_x_bach_float64_x_x_x_x_", 2379119252, 3222487108, "_x_x_x_x_bach_float64_x_x_x_x_", 1813538238, 3220205318, "_x_x_x_x_bach_float64_x_x_x_x_", 3020460715, 3222494129, "_x_x_x_x_bach_float64_x_x_x_x_", 2280090080, 3220111566, "_x_x_x_x_bach_float64_x_x_x_x_", 156678282, 3222500969, "_x_x_x_x_bach_float64_x_x_x_x_", 2898887171, 3219988355, "_x_x_x_x_bach_float64_x_x_x_x_", 1496989423, 3222507624, "_x_x_x_x_bach_float64_x_x_x_x_", 161868043, 3219864126, "_x_x_x_x_bach_float64_x_x_x_x_", 1978672276, 3222514093, "_x_x_x_x_bach_float64_x_x_x_x_", 2811796297, 3219738895, "_x_x_x_x_bach_float64_x_x_x_x_", 949180463, 3222520374, "_x_x_x_x_bach_float64_x_x_x_x_", 3579872394, 3219612682, "_x_x_x_x_bach_float64_x_x_x_x_", 2168372324, 3222526464, "_x_x_x_x_bach_float64_x_x_x_x_", 649153253, 3219485506, "_x_x_x_x_bach_float64_x_x_x_x_", 925821319, 3222532362, "_x_x_x_x_bach_float64_x_x_x_x_", 1937841616, 3219357384, "_x_x_x_x_bach_float64_x_x_x_x_", 1222880142, 3222538065, "_x_x_x_x_bach_float64_x_x_x_x_", 3612513291, 3219228336, "_x_x_x_x_bach_float64_x_x_x_x_", 2889955914, 3222543571, "_x_x_x_x_bach_float64_x_x_x_x_", 1626684119, 3219068445, "_x_x_x_x_bach_float64_x_x_x_x_", 1588668918, 3222548879, "_x_x_x_x_bach_float64_x_x_x_x_", 1053105322, 3218806763, "_x_x_x_x_bach_float64_x_x_x_x_", 1698894482, 3222553986, "_x_x_x_x_bach_float64_x_x_x_x_", 193765271, 3218543347, "_x_x_x_x_bach_float64_x_x_x_x_", 3435981804, 3222558890, "_x_x_x_x_bach_float64_x_x_x_x_", 199060980, 3218278237, "_x_x_x_x_bach_float64_x_x_x_x_", 2852854990, 3222563590, "_x_x_x_x_bach_float64_x_x_x_x_", 127942440, 3217943204, "_x_x_x_x_bach_float64_x_x_x_x_", 432028523, 3222568084, "_x_x_x_x_bach_float64_x_x_x_x_", 1792246529, 3217406454, "_x_x_x_x_bach_float64_x_x_x_x_", 1087667516, 3222572369, "_x_x_x_x_bach_float64_x_x_x_x_", 2078766486, 3216701961, "_x_x_x_x_bach_float64_x_x_x_x_", 1282725043, 3222576444, "_x_x_x_x_bach_float64_x_x_x_x_", 3414738935, 3215249549, "_x_x_x_x_bach_float64_x_x_x_x_", 1915861726, 3222580307, "_x_x_x_x_bach_float64_x_x_x_x_", 2499325898, 1066992320, "_x_x_x_x_bach_float64_x_x_x_x_", 4028474202, 3222583956, "_x_x_x_x_bach_float64_x_x_x_x_", 12250336, 1068957743, "_x_x_x_x_bach_float64_x_x_x_x_", 216733906, 3222587391, "_x_x_x_x_bach_float64_x_x_x_x_", 2570331552, 1069804227, "_x_x_x_x_bach_float64_x_x_x_x_", 403341398, 3222590608, "_x_x_x_x_bach_float64_x_x_x_x_", 949554306, 1070358532, "_x_x_x_x_bach_float64_x_x_x_x_", 1774682599, 3222593606, "_x_x_x_x_bach_float64_x_x_x_x_", 723246492, 1070755776, "_x_x_x_x_bach_float64_x_x_x_x_", 1667634298, 3222596384, "_x_x_x_x_bach_float64_x_x_x_x_", 80557274, 1071035503, "_x_x_x_x_bach_float64_x_x_x_x_", 1866410975, 3222598940, "_x_x_x_x_bach_float64_x_x_x_x_", 1190160121, 1071316449, "_x_x_x_x_bach_float64_x_x_x_x_", 14485189, 3222601273, "_x_x_x_x_bach_float64_x_x_x_x_", 583160680, 1071598569, "_x_x_x_x_bach_float64_x_x_x_x_", 2501319533, 3222603380, "_x_x_x_x_bach_float64_x_x_x_x_", 797636241, 1071763244, "_x_x_x_x_bach_float64_x_x_x_x_", 2989334840, 3222605261, "_x_x_x_x_bach_float64_x_x_x_x_", 757201771, 1071905408, "_x_x_x_x_bach_float64_x_x_x_x_", 3890525603, 3222606914, "_x_x_x_x_bach_float64_x_x_x_x_", 101757086, 1072048089, "_x_x_x_x_bach_float64_x_x_x_x_", 3483310856, 3222608338, "_x_x_x_x_bach_float64_x_x_x_x_", 66983715, 1072191263, "_x_x_x_x_bach_float64_x_x_x_x_", 209227669, 3222609532, "_x_x_x_x_bach_float64_x_x_x_x_", 1062167409, 1072334906, "_x_x_x_x_bach_float64_x_x_x_x_", 1264564975, 3222610493, "_x_x_x_x_bach_float64_x_x_x_x_", 2687293563, 1072478994, "_x_x_x_x_bach_float64_x_x_x_x_", 1127198979, 3222611221, "_x_x_x_x_bach_float64_x_x_x_x_", 3750347650, 1072623503, "_x_x_x_x_bach_float64_x_x_x_x_", 3033073779, 3222611714, "_x_x_x_x_bach_float64_x_x_x_x_", 3289893180, 1072730828, "_x_x_x_x_bach_float64_x_x_x_x_", 1797948203, 3222611972, "_x_x_x_x_bach_float64_x_x_x_x_", 2078669472, 1072803467, "_x_x_x_x_bach_float64_x_x_x_x_", 998852514, 3222611993, "_x_x_x_x_bach_float64_x_x_x_x_", 2952855561, 1072876279, "_x_x_x_x_bach_float64_x_x_x_x_", 90745170, 3222611776, "_x_x_x_x_bach_float64_x_x_x_x_", 3820954195, 1072949252, "_x_x_x_x_bach_float64_x_x_x_x_", 2997976827, 3222611319, "_x_x_x_x_bach_float64_x_x_x_x_", 2240211227, 1073022374, "_x_x_x_x_bach_float64_x_x_x_x_", 935920954, 3222610623, "_x_x_x_x_bach_float64_x_x_x_x_", 4015786667, 1073095631, "_x_x_x_x_bach_float64_x_x_x_x_", 2477214756, 3222609685, "_x_x_x_x_bach_float64_x_x_x_x_", 1735246583, 1073169012, "_x_x_x_x_bach_float64_x_x_x_x_", 3488427624, 3222608505, "_x_x_x_x_bach_float64_x_x_x_x_", 547786278, 1073242503, "_x_x_x_x_bach_float64_x_x_x_x_", 16371901, 3222607083, "_x_x_x_x_bach_float64_x_x_x_x_", 993869353, 1073316091, "_x_x_x_x_bach_float64_x_x_x_x_", 1174382631, 3222605416, "_x_x_x_x_bach_float64_x_x_x_x_", 3309790675, 1073389763, "_x_x_x_x_bach_float64_x_x_x_x_", 3373860306, 3222603504, "_x_x_x_x_bach_float64_x_x_x_x_", 3142390781, 1073463507, "_x_x_x_x_bach_float64_x_x_x_x_", 3210487610, 3222601347, "_x_x_x_x_bach_float64_x_x_x_x_", 148755927, 1073537310, "_x_x_x_x_bach_float64_x_x_x_x_", 1760479569, 3222598944, "_x_x_x_x_bach_float64_x_x_x_x_", 2301033618, 1073611157, "_x_x_x_x_bach_float64_x_x_x_x_", 286866785, 3222596294, "_x_x_x_x_bach_float64_x_x_x_x_", 126557535, 1073685037, "_x_x_x_x_bach_float64_x_x_x_x_", 240713343, 3222593396, "_x_x_x_x_bach_float64_x_x_x_x_", 2686280449, 1073750379, "_x_x_x_x_bach_float64_x_x_x_x_", 3262301758, 3222590249, "_x_x_x_x_bach_float64_x_x_x_x_", 1885810680, 1073787331, "_x_x_x_x_bach_float64_x_x_x_x_", 2592350102, 3222586854, "_x_x_x_x_bach_float64_x_x_x_x_", 1148230784, 1073824279, "_x_x_x_x_bach_float64_x_x_x_x_", 252999344, 3222583210, "_x_x_x_x_bach_float64_x_x_x_x_", 1700189838, 1073861216, "_x_x_x_x_bach_float64_x_x_x_x_", 2753930374, 3222579315, "_x_x_x_x_bach_float64_x_x_x_x_", 366294025, 1073898136, "_x_x_x_x_bach_float64_x_x_x_x_", 3913545032, 3222575170, "_x_x_x_x_bach_float64_x_x_x_x_", 2459196539, 1073935031, "_x_x_x_x_bach_float64_x_x_x_x_", 2039851076, 3222570775, "_x_x_x_x_bach_float64_x_x_x_x_", 309983359, 1073971896, "_x_x_x_x_bach_float64_x_x_x_x_", 4226410601, 3222566128, "_x_x_x_x_bach_float64_x_x_x_x_", 3338199605, 1074008722, "_x_x_x_x_bach_float64_x_x_x_x_", 583482438, 3222561231, "_x_x_x_x_bach_float64_x_x_x_x_", 3697398870, 1074045504, "_x_x_x_x_bach_float64_x_x_x_x_", 2893638766, 3222556081, "_x_x_x_x_bach_float64_x_x_x_x_", 2050265911, 1074082235, "_x_x_x_x_bach_float64_x_x_x_x_", 1662967660, 3222550680, "_x_x_x_x_bach_float64_x_x_x_x_", 3278998633, 1074118907, "_x_x_x_x_bach_float64_x_x_x_x_", 481651246, 3222545027, "_x_x_x_x_bach_float64_x_x_x_x_", 3605785004, 1074155514, "_x_x_x_x_bach_float64_x_x_x_x_", 3139867624, 3222539121, "_x_x_x_x_bach_float64_x_x_x_x_", 3483112031, 1074192049, "_x_x_x_x_bach_float64_x_x_x_x_", 743656633, 3222532964, "_x_x_x_x_bach_float64_x_x_x_x_", 3304233186, 1074228505, "_x_x_x_x_bach_float64_x_x_x_x_", 1780422110, 3222526554, "_x_x_x_x_bach_float64_x_x_x_x_", 3408629533, 1074264875, "_x_x_x_x_bach_float64_x_x_x_x_", 2054855393, 3222519892, "_x_x_x_x_bach_float64_x_x_x_x_", 4087496344, 1074301152, "_x_x_x_x_bach_float64_x_x_x_x_", 1869462203, 3222512978, "_x_x_x_x_bach_float64_x_x_x_x_", 1294287065, 1074337330, "_x_x_x_x_bach_float64_x_x_x_x_", 1730215947, 3222505812, "_x_x_x_x_bach_float64_x_x_x_x_", 3830117126, 1074373400, "_x_x_x_x_bach_float64_x_x_x_x_", 2347141092, 3222498394, "_x_x_x_x_bach_float64_x_x_x_x_", 3284550165, 1074409357, "_x_x_x_x_bach_float64_x_x_x_x_", 339891697, 3222490725, "_x_x_x_x_bach_float64_x_x_x_x_", 4105947747, 1074445193, "_x_x_x_x_bach_float64_x_x_x_x_", 1123161522, 3222482804, "_x_x_x_x_bach_float64_x_x_x_x_", 2132232173, 1074480902, "_x_x_x_x_bach_float64_x_x_x_x_", 1727285176, 3222474632, "_x_x_x_x_bach_float64_x_x_x_x_", 1776374311, 1074516476, "_x_x_x_x_bach_float64_x_x_x_x_", 3683572323, 3222466209, "_x_x_x_x_bach_float64_x_x_x_x_", 3147128803, 1074551908, "_x_x_x_x_bach_float64_x_x_x_x_", 139799922, 3222457537, "_x_x_x_x_bach_float64_x_x_x_x_", 2054688649, 1074587192, "_x_x_x_x_bach_float64_x_x_x_x_", 1630371745, 3222448614, "_x_x_x_x_bach_float64_x_x_x_x_", 2901257897, 1074622320, "_x_x_x_x_bach_float64_x_x_x_x_", 1716897265, 3222439442, "_x_x_x_x_bach_float64_x_x_x_x_", 1506868742, 1074657286, "_x_x_x_x_bach_float64_x_x_x_x_", 2758273995, 3222430021, "_x_x_x_x_bach_float64_x_x_x_x_", 2294951146, 1074692082, "_x_x_x_x_bach_float64_x_x_x_x_", 3026025364, 3222420352, "_x_x_x_x_bach_float64_x_x_x_x_", 1118177307, 1074726702, "_x_x_x_x_bach_float64_x_x_x_x_", 999468851, 3222410436, "_x_x_x_x_bach_float64_x_x_x_x_", 2444056769, 1074761138, "_x_x_x_x_bach_float64_x_x_x_x_", 3955812309, 3222400272, "_x_x_x_x_bach_float64_x_x_x_x_", 1090402041, 1074792892, "_x_x_x_x_bach_float64_x_x_x_x_", 2200472766, 3222389863, "_x_x_x_x_bach_float64_x_x_x_x_", 2431477516, 1074809916, "_x_x_x_x_bach_float64_x_x_x_x_", 3426898032, 3222379208, "_x_x_x_x_bach_float64_x_x_x_x_", 3238626671, 1074826838, "_x_x_x_x_bach_float64_x_x_x_x_", 2651839480, 3222368309, "_x_x_x_x_bach_float64_x_x_x_x_", 1529174516, 1074843655, "_x_x_x_x_bach_float64_x_x_x_x_", 3690192862, 3222357166, "_x_x_x_x_bach_float64_x_x_x_x_", 3937219142, 1074860362, "_x_x_x_x_bach_float64_x_x_x_x_", 1975093845, 3222345781, "_x_x_x_x_bach_float64_x_x_x_x_", 4241683355, 1074876957, "_x_x_x_x_bach_float64_x_x_x_x_", 1737712249, 3222334154, "_x_x_x_x_bach_float64_x_x_x_x_", 549074385, 1074893437, "_x_x_x_x_bach_float64_x_x_x_x_", 3122235439, 3222322286, "_x_x_x_x_bach_float64_x_x_x_x_", 3886310712, 1074909796, "_x_x_x_x_bach_float64_x_x_x_x_", 2185713763, 3222310179, "_x_x_x_x_bach_float64_x_x_x_x_", 3843877160, 1074926033, "_x_x_x_x_bach_float64_x_x_x_x_", 3782768017, 3222297833, "_x_x_x_x_bach_float64_x_x_x_x_", 2938457476, 1074942144, "_x_x_x_x_bach_float64_x_x_x_x_", 90518540, 3222285251, "_x_x_x_x_bach_float64_x_x_x_x_", 3730926691, 1074958125, "_x_x_x_x_bach_float64_x_x_x_x_", 1346163832, 3222270816, "_x_x_x_x_bach_float64_x_x_x_x_", 239310455, 1074973974, "_x_x_x_x_bach_float64_x_x_x_x_", 538003612, 3222244709, "_x_x_x_x_bach_float64_x_x_x_x_", 3711481713, 1074989685, "_x_x_x_x_bach_float64_x_x_x_x_", 531461862, 3222218135, "_x_x_x_x_bach_float64_x_x_x_x_", 3973346437, 1075005257, "_x_x_x_x_bach_float64_x_x_x_x_", 218603800, 3222191097, "_x_x_x_x_bach_float64_x_x_x_x_", 3791471365, 1075020686, "_x_x_x_x_bach_float64_x_x_x_x_", 3197719542, 3222163597, "_x_x_x_x_bach_float64_x_x_x_x_", 1696101501, 1075035969, "_x_x_x_x_bach_float64_x_x_x_x_", 592505317, 3222135640, "_x_x_x_x_bach_float64_x_x_x_x_", 573978289, 1075051102, "_x_x_x_x_bach_float64_x_x_x_x_", 1115804583, 3222107227, "_x_x_x_x_bach_float64_x_x_x_x_", 3376252132, 1075066081, "_x_x_x_x_bach_float64_x_x_x_x_", 1003726834, 3222078362, "_x_x_x_x_bach_float64_x_x_x_x_", 236456037, 1075080905, "_x_x_x_x_bach_float64_x_x_x_x_", 1194326446, 3222049048, "_x_x_x_x_bach_float64_x_x_x_x_", 2833114732, 1075095568, "_x_x_x_x_bach_float64_x_x_x_x_", 3031364806, 3222019288, "_x_x_x_x_bach_float64_x_x_x_x_", 1442937003, 1075110069, "_x_x_x_x_bach_float64_x_x_x_x_", 3967992427, 3221989086, "_x_x_x_x_bach_float64_x_x_x_x_", 3598380786, 1075124403, "_x_x_x_x_bach_float64_x_x_x_x_", 1860285502, 3221958446, "_x_x_x_x_bach_float64_x_x_x_x_", 4025734958, 1075138568, "_x_x_x_x_bach_float64_x_x_x_x_", 3555669907, 3221927370, "_x_x_x_x_bach_float64_x_x_x_x_", 1827834408, 1075152561, "_x_x_x_x_bach_float64_x_x_x_x_", 3416494171, 3221895863, "_x_x_x_x_bach_float64_x_x_x_x_", 486898272, 1075166378, "_x_x_x_x_bach_float64_x_x_x_x_", 498228438, 3221863929, "_x_x_x_x_bach_float64_x_x_x_x_", 3572392728, 1075180015, "_x_x_x_x_bach_float64_x_x_x_x_", 2842681943, 3221831570, "_x_x_x_x_bach_float64_x_x_x_x_", 1858950522, 1075193471, "_x_x_x_x_bach_float64_x_x_x_x_", 1706369868, 3221798792, "_x_x_x_x_bach_float64_x_x_x_x_", 3393954151, 1075206741, "_x_x_x_x_bach_float64_x_x_x_x_", 1623375886, 3221765598, "_x_x_x_x_bach_float64_x_x_x_x_", 3435567141, 1075219823, "_x_x_x_x_bach_float64_x_x_x_x_", 3223495176, 3221731992, "_x_x_x_x_bach_float64_x_x_x_x_", 1635395177, 1075232714, "_x_x_x_x_bach_float64_x_x_x_x_", 3230167808, 3221697979, "_x_x_x_x_bach_float64_x_x_x_x_", 2041267152, 1075245410, "_x_x_x_x_bach_float64_x_x_x_x_", 3048267996, 3221663563, "_x_x_x_x_bach_float64_x_x_x_x_", 215102904, 1075257909, "_x_x_x_x_bach_float64_x_x_x_x_", 171945565, 3221628749, "_x_x_x_x_bach_float64_x_x_x_x_", 415539948, 1075270207, "_x_x_x_x_bach_float64_x_x_x_x_", 1067225801, 3221593540, "_x_x_x_x_bach_float64_x_x_x_x_", 2715776662, 1075282301, "_x_x_x_x_bach_float64_x_x_x_x_", 3989760069, 3221557941, "_x_x_x_x_bach_float64_x_x_x_x_", 3006304201, 1075294189, "_x_x_x_x_bach_float64_x_x_x_x_", 3277335279, 3221521958, "_x_x_x_x_bach_float64_x_x_x_x_", 1587559388, 1075305868, "_x_x_x_x_bach_float64_x_x_x_x_", 2232240497, 3221485595, "_x_x_x_x_bach_float64_x_x_x_x_", 3172628839, 1075317334, "_x_x_x_x_bach_float64_x_x_x_x_", 233752517, 3221448857, "_x_x_x_x_bach_float64_x_x_x_x_", 4005036434, 1075328585, "_x_x_x_x_bach_float64_x_x_x_x_", 1325381239, 3221411748, "_x_x_x_x_bach_float64_x_x_x_x_", 451352065, 1075339619, "_x_x_x_x_bach_float64_x_x_x_x_", 1327201898, 3221374274, "_x_x_x_x_bach_float64_x_x_x_x_", 1888751822, 1075350431, "_x_x_x_x_bach_float64_x_x_x_x_", 717915006, 3221336440, "_x_x_x_x_bach_float64_x_x_x_x_", 642888907, 1075361020, "_x_x_x_x_bach_float64_x_x_x_x_", 336961313, 3221298251, "_x_x_x_x_bach_float64_x_x_x_x_", 2055289840, 1075371382, "_x_x_x_x_bach_float64_x_x_x_x_", 1381528512, 3221259712, "_x_x_x_x_bach_float64_x_x_x_x_", 3011125668, 1075381515, "_x_x_x_x_bach_float64_x_x_x_x_", 2217031549, 3221216186, "_x_x_x_x_bach_float64_x_x_x_x_", 531736365, 1075391417, "_x_x_x_x_bach_float64_x_x_x_x_", 2842650743, 3221137742, "_x_x_x_x_bach_float64_x_x_x_x_", 367136749, 1075401084, "_x_x_x_x_bach_float64_x_x_x_x_", 553421980, 3221058632, "_x_x_x_x_bach_float64_x_x_x_x_", 4113666928, 1075410513, "_x_x_x_x_bach_float64_x_x_x_x_", 542842902, 3220978866, "_x_x_x_x_bach_float64_x_x_x_x_", 626590581, 1075419704, "_x_x_x_x_bach_float64_x_x_x_x_", 97803568, 3220898456, "_x_x_x_x_bach_float64_x_x_x_x_", 382346133, 1075428652, "_x_x_x_x_bach_float64_x_x_x_x_", 1476614263, 3220817413, "_x_x_x_x_bach_float64_x_x_x_x_", 1121300696, 1075437355, "_x_x_x_x_bach_float64_x_x_x_x_", 3312051670, 3220735749, "_x_x_x_x_bach_float64_x_x_x_x_", 735123188, 1075445811, "_x_x_x_x_bach_float64_x_x_x_x_", 604196041, 3220653477, "_x_x_x_x_bach_float64_x_x_x_x_", 1564201306, 1075454017, "_x_x_x_x_bach_float64_x_x_x_x_", 1892994738, 3220570607, "_x_x_x_x_bach_float64_x_x_x_x_", 1810134567, 1075461971, "_x_x_x_x_bach_float64_x_x_x_x_", 3481010801, 3220487152, "_x_x_x_x_bach_float64_x_x_x_x_", 4128073916, 1075469670, "_x_x_x_x_bach_float64_x_x_x_x_", 2310736827, 3220403125, "_x_x_x_x_bach_float64_x_x_x_x_", 2744201830, 1075477113, "_x_x_x_x_bach_float64_x_x_x_x_", 251834265, 3220318538, "_x_x_x_x_bach_float64_x_x_x_x_", 637959882, 1075484297, "_x_x_x_x_bach_float64_x_x_x_x_", 4093267314, 3220233402, "_x_x_x_x_bach_float64_x_x_x_x_", 954448496, 1075491219, "_x_x_x_x_bach_float64_x_x_x_x_", 3825957967, 3220118569, "_x_x_x_x_bach_float64_x_x_x_x_", 2711769421, 1075497877, "_x_x_x_x_bach_float64_x_x_x_x_", 3448914085, 3219946185, "_x_x_x_x_bach_float64_x_x_x_x_", 803310467, 1075504270, "_x_x_x_x_bach_float64_x_x_x_x_", 2807376584, 3219772783, "_x_x_x_x_bach_float64_x_x_x_x_", 3179873898, 1075510394, "_x_x_x_x_bach_float64_x_x_x_x_", 3131303624, 3219598389, "_x_x_x_x_bach_float64_x_x_x_x_", 787138565, 1075516249, "_x_x_x_x_bach_float64_x_x_x_x_", 2521621961, 3219423030, "_x_x_x_x_bach_float64_x_x_x_x_", 1927604995, 1075521831, "_x_x_x_x_bach_float64_x_x_x_x_", 227849731, 3219246733, "_x_x_x_x_bach_float64_x_x_x_x_", 2198004089, 1075527139, "_x_x_x_x_bach_float64_x_x_x_x_", 1850920216, 3219010728, "_x_x_x_x_bach_float64_x_x_x_x_", 1671318652, 1075532171, "_x_x_x_x_bach_float64_x_x_x_x_", 3626237483, 3218654542, "_x_x_x_x_bach_float64_x_x_x_x_", 603940562, 1075536925, "_x_x_x_x_bach_float64_x_x_x_x_", 2369005803, 3218296644, "_x_x_x_x_bach_float64_x_x_x_x_", 3732734193, 1075541398, "_x_x_x_x_bach_float64_x_x_x_x_", 2229675997, 3217794434, "_x_x_x_x_bach_float64_x_x_x_x_", 3097234550, 1075545590, "_x_x_x_x_bach_float64_x_x_x_x_", 1440878939, 3217072122, "_x_x_x_x_bach_float64_x_x_x_x_", 3811489123, 1075549498, "_x_x_x_x_bach_float64_x_x_x_x_", 2902060738, 3215341959, "_x_x_x_x_bach_float64_x_x_x_x_", 2591229793, 1075553121, "_x_x_x_x_bach_float64_x_x_x_x_", 2813934341, 1067858769, "_x_x_x_x_bach_float64_x_x_x_x_", 640752960, 1075556457, "_x_x_x_x_bach_float64_x_x_x_x_", 1777781325, 1069594421, "_x_x_x_x_bach_float64_x_x_x_x_", 3654867234, 1075559503, "_x_x_x_x_bach_float64_x_x_x_x_", 3946926253, 1070328396, "_x_x_x_x_bach_float64_x_x_x_x_", 345973620, 1075562260, "_x_x_x_x_bach_float64_x_x_x_x_", 4018190081, 1070830546, "_x_x_x_x_bach_float64_x_x_x_x_", 1100656435, 1075564724, "_x_x_x_x_bach_float64_x_x_x_x_", 721397090, 1071200101, "_x_x_x_x_bach_float64_x_x_x_x_", 3621798334, 1075566894, "_x_x_x_x_bach_float64_x_x_x_x_", 3266738949, 1071570849, "_x_x_x_x_bach_float64_x_x_x_x_", 1520336027, 1075568770, "_x_x_x_x_bach_float64_x_x_x_x_", 1928484091, 1071793702, "_x_x_x_x_bach_float64_x_x_x_x_", 1496917929, 1075570349, "_x_x_x_x_bach_float64_x_x_x_x_", 762586543, 1071980181, "_x_x_x_x_bach_float64_x_x_x_x_", 1868823037, 1075571630, "_x_x_x_x_bach_float64_x_x_x_x_", 3235805947, 1072167166, "_x_x_x_x_bach_float64_x_x_x_x_", 1161617405, 1075572612, "_x_x_x_x_bach_float64_x_x_x_x_", 2873135227, 1072354628, "_x_x_x_x_bach_float64_x_x_x_x_", 2405809452, 1075573293, "_x_x_x_x_bach_float64_x_x_x_x_", 973142580, 1072542536, "_x_x_x_x_bach_float64_x_x_x_x_", 253601799, 1075573673, "_x_x_x_x_bach_float64_x_x_x_x_", 1167284678, 1072712053, "_x_x_x_x_bach_float64_x_x_x_x_", 2455346835, 1075573749, "_x_x_x_x_bach_float64_x_x_x_x_", 1196599038, 1072806406, "_x_x_x_x_bach_float64_x_x_x_x_", 4091326989, 1075573521, "_x_x_x_x_bach_float64_x_x_x_x_", 2211845224, 1072900935, "_x_x_x_x_bach_float64_x_x_x_x_", 458205257, 1075572989, "_x_x_x_x_bach_float64_x_x_x_x_", 1190941968, 1072995625, "_x_x_x_x_bach_float64_x_x_x_x_", 4250407259, 1075572149, "_x_x_x_x_bach_float64_x_x_x_x_", 3348477065, 1073090459, "_x_x_x_x_bach_float64_x_x_x_x_", 2611925023, 1075571003, "_x_x_x_x_bach_float64_x_x_x_x_", 672144402, 1073185423, "_x_x_x_x_bach_float64_x_x_x_x_", 87430184, 1075569549, "_x_x_x_x_bach_float64_x_x_x_x_", 1998881789, 1073280499, "_x_x_x_x_bach_float64_x_x_x_x_", 1443808224, 1075567785, "_x_x_x_x_bach_float64_x_x_x_x_", 2961556847, 1073375672, "_x_x_x_x_bach_float64_x_x_x_x_", 3081590110, 1075565711, "_x_x_x_x_bach_float64_x_x_x_x_", 3180382286, 1073470926, "_x_x_x_x_bach_float64_x_x_x_x_", 1626215599, 1075563327, "_x_x_x_x_bach_float64_x_x_x_x_", 1979581635, 1073566245, "_x_x_x_x_bach_float64_x_x_x_x_", 2519258712, 1075560631, "_x_x_x_x_bach_float64_x_x_x_x_", 2694074257, 1073661612, "_x_x_x_x_bach_float64_x_x_x_x_", 2839811238, 1075557623, "_x_x_x_x_bach_float64_x_x_x_x_", 4193154675, 1073749417, "_x_x_x_x_bach_float64_x_x_x_x_", 4190598841, 1075554302, "_x_x_x_x_bach_float64_x_x_x_x_", 2339139250, 1073797125, "_x_x_x_x_bach_float64_x_x_x_x_", 4109221880, 1075550668, "_x_x_x_x_bach_float64_x_x_x_x_", 3504058481, 1073844832, "_x_x_x_x_bach_float64_x_x_x_x_", 364259005, 1075546721, "_x_x_x_x_bach_float64_x_x_x_x_", 2403783414, 1073892531, "_x_x_x_x_bach_float64_x_x_x_x_", 3841265969, 1075542458, "_x_x_x_x_bach_float64_x_x_x_x_", 2231881320, 1073940213, "_x_x_x_x_bach_float64_x_x_x_x_", 4184094452, 1075537881, "_x_x_x_x_bach_float64_x_x_x_x_", 1780806858, 1073987870, "_x_x_x_x_bach_float64_x_x_x_x_", 4155647679, 1075532989, "_x_x_x_x_bach_float64_x_x_x_x_", 4037964825, 1074035493, "_x_x_x_x_bach_float64_x_x_x_x_", 2458988212, 1075527782, "_x_x_x_x_bach_float64_x_x_x_x_", 3306970923, 1074083075, "_x_x_x_x_bach_float64_x_x_x_x_", 2328208990, 1075522259, "_x_x_x_x_bach_float64_x_x_x_x_", 2393716864, 1074130607, "_x_x_x_x_bach_float64_x_x_x_x_", 2939394418, 1075516420, "_x_x_x_x_bach_float64_x_x_x_x_", 4022663815, 1074178080, "_x_x_x_x_bach_float64_x_x_x_x_", 3706442258, 1075510265, "_x_x_x_x_bach_float64_x_x_x_x_", 2253167247, 1074225487, "_x_x_x_x_bach_float64_x_x_x_x_", 4281876958, 1075503794, "_x_x_x_x_bach_float64_x_x_x_x_", 3960602655, 1074272818, "_x_x_x_x_bach_float64_x_x_x_x_", 262654141, 1075497008, "_x_x_x_x_bach_float64_x_x_x_x_", 3072880171, 1074320066, "_x_x_x_x_bach_float64_x_x_x_x_", 370759795, 1075489905, "_x_x_x_x_bach_float64_x_x_x_x_", 2051627144, 1074367222, "_x_x_x_x_bach_float64_x_x_x_x_", 684094487, 1075482486, "_x_x_x_x_bach_float64_x_x_x_x_", 3308626715, 1074414277, "_x_x_x_x_bach_float64_x_x_x_x_", 1816988338, 1075474751, "_x_x_x_x_bach_float64_x_x_x_x_", 622281772, 1074461224, "_x_x_x_x_bach_float64_x_x_x_x_", 330869761, 1075466701, "_x_x_x_x_bach_float64_x_x_x_x_", 618874679, 1074508053, "_x_x_x_x_bach_float64_x_x_x_x_", 1619728047, 1075458335, "_x_x_x_x_bach_float64_x_x_x_x_", 1304177464, 1074554756, "_x_x_x_x_bach_float64_x_x_x_x_", 2730762047, 1075449654, "_x_x_x_x_bach_float64_x_x_x_x_", 659855243, 1074601325, "_x_x_x_x_bach_float64_x_x_x_x_", 954789558, 1075440659, "_x_x_x_x_bach_float64_x_x_x_x_", 944923782, 1074647751, "_x_x_x_x_bach_float64_x_x_x_x_", 2416613527, 1075431349, "_x_x_x_x_bach_float64_x_x_x_x_", 112324918, 1074694026, "_x_x_x_x_bach_float64_x_x_x_x_", 600573774, 1075421726, "_x_x_x_x_bach_float64_x_x_x_x_", 405390156, 1074740141, "_x_x_x_x_bach_float64_x_x_x_x_", 2120695402, 1075411789, "_x_x_x_x_bach_float64_x_x_x_x_", 4069420107, 1074786087, "_x_x_x_x_bach_float64_x_x_x_x_", 951185963, 1075401540, "_x_x_x_x_bach_float64_x_x_x_x_", 236672870, 1074811129, "_x_x_x_x_bach_float64_x_x_x_x_", 4196496230, 1075390978, "_x_x_x_x_bach_float64_x_x_x_x_", 2385506426, 1074833921, "_x_x_x_x_bach_float64_x_x_x_x_", 2026762173, 1075380106, "_x_x_x_x_bach_float64_x_x_x_x_", 1036599987, 1074856617, "_x_x_x_x_bach_float64_x_x_x_x_", 2037712172, 1075368923, "_x_x_x_x_bach_float64_x_x_x_x_", 3791883214, 1074879211, "_x_x_x_x_bach_float64_x_x_x_x_", 3480987792, 1075357430, "_x_x_x_x_bach_float64_x_x_x_x_", 1090880348, 1074901701, "_x_x_x_x_bach_float64_x_x_x_x_", 1559191269, 1075345629, "_x_x_x_x_bach_float64_x_x_x_x_", 573762734, 1074924081, "_x_x_x_x_bach_float64_x_x_x_x_", 310822966, 1075333520, "_x_x_x_x_bach_float64_x_x_x_x_", 1314864098, 1074946347, "_x_x_x_x_bach_float64_x_x_x_x_", 4020337808, 1075321103, "_x_x_x_x_bach_float64_x_x_x_x_", 2415938192, 1074968495, "_x_x_x_x_bach_float64_x_x_x_x_", 38222347, 1075308382, "_x_x_x_x_bach_float64_x_x_x_x_", 3009485472, 1074990521, "_x_x_x_x_bach_float64_x_x_x_x_", 1730569146, 1075295355, "_x_x_x_x_bach_float64_x_x_x_x_", 2262082715, 1075012421, "_x_x_x_x_bach_float64_x_x_x_x_", 1234293097, 1075282025, "_x_x_x_x_bach_float64_x_x_x_x_", 3672682234, 1075034190, "_x_x_x_x_bach_float64_x_x_x_x_", 3816681281, 1075268392, "_x_x_x_x_bach_float64_x_x_x_x_", 2191043758, 1075055825, "_x_x_x_x_bach_float64_x_x_x_x_", 2105355750, 1075254459, "_x_x_x_x_bach_float64_x_x_x_x_", 1400938412, 1075077321, "_x_x_x_x_bach_float64_x_x_x_x_", 1857798688, 1075240226, "_x_x_x_x_bach_float64_x_x_x_x_", 638582218, 1075098674, "_x_x_x_x_bach_float64_x_x_x_x_", 486192184, 1075225695, "_x_x_x_x_bach_float64_x_x_x_x_", 3585905997, 1075119879, "_x_x_x_x_bach_float64_x_x_x_x_", 4236918510, 1075210866, "_x_x_x_x_bach_float64_x_x_x_x_", 1094020749, 1075140934, "_x_x_x_x_bach_float64_x_x_x_x_", 2420342133, 1075195743, "_x_x_x_x_bach_float64_x_x_x_x_", 1251322129, 1075161833, "_x_x_x_x_bach_float64_x_x_x_x_", 1770088684, 1075180326, "_x_x_x_x_bach_float64_x_x_x_x_", 3617018039, 1075182572, "_x_x_x_x_bach_float64_x_x_x_x_", 672736502, 1075164617, "_x_x_x_x_bach_float64_x_x_x_x_", 3519424838, 1075203148, "_x_x_x_x_bach_float64_x_x_x_x_", 2052168530, 1075148617, "_x_x_x_x_bach_float64_x_x_x_x_", 649227724, 1075223557, "_x_x_x_x_bach_float64_x_x_x_x_", 484075227, 1075132329, "_x_x_x_x_bach_float64_x_x_x_x_", 3357770018, 1075243793, "_x_x_x_x_bach_float64_x_x_x_x_", 3670150473, 1075115753, "_x_x_x_x_bach_float64_x_x_x_x_", 2890567141, 1075263854, "_x_x_x_x_bach_float64_x_x_x_x_", 2372634750, 1075098893, "_x_x_x_x_bach_float64_x_x_x_x_", 3455390352, 1075283735, "_x_x_x_x_bach_float64_x_x_x_x_", 478355212, 1075081750, "_x_x_x_x_bach_float64_x_x_x_x_", 750737407, 1075303433, "_x_x_x_x_bach_float64_x_x_x_x_", 2113047574, 1075064325, "_x_x_x_x_bach_float64_x_x_x_x_", 3443969995, 1075322942, "_x_x_x_x_bach_float64_x_x_x_x_", 3050600196, 1075046621, "_x_x_x_x_bach_float64_x_x_x_x_", 3109836734, 1075342260, "_x_x_x_x_bach_float64_x_x_x_x_", 3597089443, 1075028640, "_x_x_x_x_bach_float64_x_x_x_x_", 3563723, 1075361383, "_x_x_x_x_bach_float64_x_x_x_x_", 4294900902, 1075010384, "_x_x_x_x_bach_float64_x_x_x_x_", 3064133153, 1075380305, "_x_x_x_x_bach_float64_x_x_x_x_", 1626805564, 1074991856, "_x_x_x_x_bach_float64_x_x_x_x_", 4147749552, 1075399024, "_x_x_x_x_bach_float64_x_x_x_x_", 899860283, 1074973057, "_x_x_x_x_bach_float64_x_x_x_x_", 3800904314, 1075417536, "_x_x_x_x_bach_float64_x_x_x_x_", 3359459675, 1074953989, "_x_x_x_x_bach_float64_x_x_x_x_", 2673691923, 1075435837, "_x_x_x_x_bach_float64_x_x_x_x_", 1893277767, 1074934656, "_x_x_x_x_bach_float64_x_x_x_x_", 1523050391, 1075453923, "_x_x_x_x_bach_float64_x_x_x_x_", 2504968893, 1074915059, "_x_x_x_x_bach_float64_x_x_x_x_", 1215990484, 1075471790, "_x_x_x_x_bach_float64_x_x_x_x_", 2838151034, 1074895201, "_x_x_x_x_bach_float64_x_x_x_x_", 2732813286, 1075489434, "_x_x_x_x_bach_float64_x_x_x_x_", 765115820, 1074875085, "_x_x_x_x_bach_float64_x_x_x_x_", 2875348139, 1075506852, "_x_x_x_x_bach_float64_x_x_x_x_", 2975494304, 1074854712, "_x_x_x_x_bach_float64_x_x_x_x_", 2860079500, 1075524040, "_x_x_x_x_bach_float64_x_x_x_x_", 3500107358, 1074834086, "_x_x_x_x_bach_float64_x_x_x_x_", 4026358457, 1075540994, "_x_x_x_x_bach_float64_x_x_x_x_", 889477870, 1074813210, "_x_x_x_x_bach_float64_x_x_x_x_", 3544600008, 1075557711, "_x_x_x_x_bach_float64_x_x_x_x_", 2507397091, 1074792085, "_x_x_x_x_bach_float64_x_x_x_x_", 3009367525, 1075574187, "_x_x_x_x_bach_float64_x_x_x_x_", 1814319708, 1074751031, "_x_x_x_x_bach_float64_x_x_x_x_", 4147539970, 1075590418, "_x_x_x_x_bach_float64_x_x_x_x_", 3494727735, 1074707806, "_x_x_x_x_bach_float64_x_x_x_x_", 231495819, 1075606402, "_x_x_x_x_bach_float64_x_x_x_x_", 336115863, 1074664103, "_x_x_x_x_bach_float64_x_x_x_x_", 1852018881, 1075622133, "_x_x_x_x_bach_float64_x_x_x_x_", 233040154, 1074619926, "_x_x_x_x_bach_float64_x_x_x_x_", 2561644743, 1075637609, "_x_x_x_x_bach_float64_x_x_x_x_", 2921475780, 1074575281, "_x_x_x_x_bach_float64_x_x_x_x_", 352564340, 1075652827, "_x_x_x_x_bach_float64_x_x_x_x_", 4270463164, 1074530175, "_x_x_x_x_bach_float64_x_x_x_x_", 1954640008, 1075667782, "_x_x_x_x_bach_float64_x_x_x_x_", 573669047, 1074484615, "_x_x_x_x_bach_float64_x_x_x_x_", 1363598774, 1075682472, "_x_x_x_x_bach_float64_x_x_x_x_", 1430797098, 1074438605, "_x_x_x_x_bach_float64_x_x_x_x_", 1318879172, 1075696893, "_x_x_x_x_bach_float64_x_x_x_x_", 3974208810, 1074392152, "_x_x_x_x_bach_float64_x_x_x_x_", 421719483, 1075711042, "_x_x_x_x_bach_float64_x_x_x_x_", 1455198774, 1074345264, "_x_x_x_x_bach_float64_x_x_x_x_", 1728061815, 1075724915, "_x_x_x_x_bach_float64_x_x_x_x_", 420121138, 1074297946, "_x_x_x_x_bach_float64_x_x_x_x_", 4161565701, 1075738509, "_x_x_x_x_bach_float64_x_x_x_x_", 3526694958, 1074250204, "_x_x_x_x_bach_float64_x_x_x_x_", 2516534398, 1075751822, "_x_x_x_x_bach_float64_x_x_x_x_", 950161463, 1074202047, "_x_x_x_x_bach_float64_x_x_x_x_", 345720719, 1075764850, "_x_x_x_x_bach_float64_x_x_x_x_", 444065411, 1074153480, "_x_x_x_x_bach_float64_x_x_x_x_", 1373273286, 1075777589, "_x_x_x_x_bach_float64_x_x_x_x_", 1566380106, 1074104510, "_x_x_x_x_bach_float64_x_x_x_x_", 907659266, 1075790037, "_x_x_x_x_bach_float64_x_x_x_x_", 4265290202, 1074055144, "_x_x_x_x_bach_float64_x_x_x_x_", 3024366677, 1075802190, "_x_x_x_x_bach_float64_x_x_x_x_", 285024818, 1074005391, "_x_x_x_x_bach_float64_x_x_x_x_", 3388843694, 1075814046, "_x_x_x_x_bach_float64_x_x_x_x_", 3226317030, 1073955255, "_x_x_x_x_bach_float64_x_x_x_x_", 2144183677, 1075825602, "_x_x_x_x_bach_float64_x_x_x_x_", 1297372872, 1073904746, "_x_x_x_x_bach_float64_x_x_x_x_", 3913882517, 1075836854, "_x_x_x_x_bach_float64_x_x_x_x_", 259075182, 1073853870, "_x_x_x_x_bach_float64_x_x_x_x_", 2459833864, 1075843388, "_x_x_x_x_bach_float64_x_x_x_x_", 1945600408, 1073802634, "_x_x_x_x_bach_float64_x_x_x_x_", 787068512, 1075848707, "_x_x_x_x_bach_float64_x_x_x_x_", 4259794491, 1073751046, "_x_x_x_x_bach_float64_x_x_x_x_", 3831652051, 1075853869, "_x_x_x_x_bach_float64_x_x_x_x_", 2336945249, 1073656406, "_x_x_x_x_bach_float64_x_x_x_x_", 1404819790, 1075858875, "_x_x_x_x_bach_float64_x_x_x_x_", 4049991873, 1073551869, "_x_x_x_x_bach_float64_x_x_x_x_", 597083856, 1075863722, "_x_x_x_x_bach_float64_x_x_x_x_", 2999298418, 1073446675, "_x_x_x_x_bach_float64_x_x_x_x_", 9724858, 1075868409, "_x_x_x_x_bach_float64_x_x_x_x_", 2099103927, 1073340839, "_x_x_x_x_bach_float64_x_x_x_x_", 2640974389, 1075872934, "_x_x_x_x_bach_float64_x_x_x_x_", 647449050, 1073234377, "_x_x_x_x_bach_float64_x_x_x_x_", 3002378705, 1075877297, "_x_x_x_x_bach_float64_x_x_x_x_", 2905966832, 1073127304, "_x_x_x_x_bach_float64_x_x_x_x_", 4950821, 1075881497, "_x_x_x_x_bach_float64_x_x_x_x_", 909725126, 1073019638, "_x_x_x_x_bach_float64_x_x_x_x_", 1255372432, 1075885531, "_x_x_x_x_bach_float64_x_x_x_x_", 226599246, 1072911394, "_x_x_x_x_bach_float64_x_x_x_x_", 1582376206, 1075889399, "_x_x_x_x_bach_float64_x_x_x_x_", 2766830831, 1072802588, "_x_x_x_x_bach_float64_x_x_x_x_", 217817640, 1075893100, "_x_x_x_x_bach_float64_x_x_x_x_", 659729418, 1072693229, "_x_x_x_x_bach_float64_x_x_x_x_", 797861388, 1075896632, "_x_x_x_x_bach_float64_x_x_x_x_", 726606417, 1072473473, "_x_x_x_x_bach_float64_x_x_x_x_", 2774216373, 1075899994, "_x_x_x_x_bach_float64_x_x_x_x_", 364232553, 1072252695, "_x_x_x_x_bach_float64_x_x_x_x_", 1415288667, 1075903186, "_x_x_x_x_bach_float64_x_x_x_x_", 3979812584, 1072030928, "_x_x_x_x_bach_float64_x_x_x_x_", 692219146, 1075906206, "_x_x_x_x_bach_float64_x_x_x_x_", 4260473056, 1071808208, "_x_x_x_x_bach_float64_x_x_x_x_", 395100050, 1075909053, "_x_x_x_x_bach_float64_x_x_x_x_", 2955689630, 1071524467, "_x_x_x_x_bach_float64_x_x_x_x_", 429043154, 1075911726, "_x_x_x_x_bach_float64_x_x_x_x_", 2635103074, 1071075420, "_x_x_x_x_bach_float64_x_x_x_x_", 815262833, 1075914224, "_x_x_x_x_bach_float64_x_x_x_x_", 3942048127, 1070624674, "_x_x_x_x_bach_float64_x_x_x_x_", 1692141084, 1075916546, "_x_x_x_x_bach_float64_x_x_x_x_", 2217663662, 1069748506, "_x_x_x_x_bach_float64_x_x_x_x_", 3316274289, 1075918691, "_x_x_x_x_bach_float64_x_x_x_x_", 1026278747, 1067768598, "_x_x_x_x_bach_float64_x_x_x_x_", 1768534171, 1075920659, "_x_x_x_x_bach_float64_x_x_x_x_", 2486592392, 3216072275, "_x_x_x_x_bach_float64_x_x_x_x_", 1839979232, 1075922448, "_x_x_x_x_bach_float64_x_x_x_x_", 1525533335, 3217465379, "_x_x_x_x_bach_float64_x_x_x_x_", 4147943452, 1075924057, "_x_x_x_x_bach_float64_x_x_x_x_", 113108168, 3218230731, "_x_x_x_x_bach_float64_x_x_x_x_", 842040434, 1075925487, "_x_x_x_x_bach_float64_x_x_x_x_", 4105131759, 3218690167, "_x_x_x_x_bach_float64_x_x_x_x_", 1374919236, 1075926735, "_x_x_x_x_bach_float64_x_x_x_x_", 2254148503, 3219139559, "_x_x_x_x_bach_float64_x_x_x_x_", 2438425770, 1075927801, "_x_x_x_x_bach_float64_x_x_x_x_", 1014013046, 3219370435, "_x_x_x_x_bach_float64_x_x_x_x_", 849417370, 1075928685, "_x_x_x_x_bach_float64_x_x_x_x_", 4252005121, 3219601833, "_x_x_x_x_bach_float64_x_x_x_x_", 2140590044, 1075929385, "_x_x_x_x_bach_float64_x_x_x_x_", 2005897239, 3219833718, "_x_x_x_x_bach_float64_x_x_x_x_", 3381481762, 1075929901, "_x_x_x_x_bach_float64_x_x_x_x_", 669485029, 3220066051, "_x_x_x_x_bach_float64_x_x_x_x_", 1769259104, 1075930233, "_x_x_x_x_bach_float64_x_x_x_x_", 771900016, 3220237845, "_x_x_x_x_bach_float64_x_x_x_x_", 3219483299, 1075930379, "_x_x_x_x_bach_float64_x_x_x_x_", 431682334, 3220354403, "_x_x_x_x_bach_float64_x_x_x_x_", 892084417, 1075930340, "_x_x_x_x_bach_float64_x_x_x_x_", 1353773841, 3220471128, "_x_x_x_x_bach_float64_x_x_x_x_", 961954817, 1075930114, "_x_x_x_x_bach_float64_x_x_x_x_", 3071156123, 3220588001, "_x_x_x_x_bach_float64_x_x_x_x_", 1144881166, 1075929701, "_x_x_x_x_bach_float64_x_x_x_x_", 476045017, 3220705004, "_x_x_x_x_bach_float64_x_x_x_x_", 3583193485, 1075929100, "_x_x_x_x_bach_float64_x_x_x_x_", 1013273609, 3220822116, "_x_x_x_x_bach_float64_x_x_x_x_", 1961588875, 1075928312, "_x_x_x_x_bach_float64_x_x_x_x_", 3219061582, 3220939318, "_x_x_x_x_bach_float64_x_x_x_x_", 2982671909, 1075927335, "_x_x_x_x_bach_float64_x_x_x_x_", 1029676655, 3221056592, "_x_x_x_x_bach_float64_x_x_x_x_", 597832882, 1075926170, "_x_x_x_x_bach_float64_x_x_x_x_", 975085080, 3221173917, "_x_x_x_x_bach_float64_x_x_x_x_", 1777711570, 1075924815, "_x_x_x_x_bach_float64_x_x_x_x_", 358990489, 3221258373, "_x_x_x_x_bach_float64_x_x_x_x_", 743031215, 1075923271, "_x_x_x_x_bach_float64_x_x_x_x_", 3123801611, 3221317057, "_x_x_x_x_bach_float64_x_x_x_x_", 440050398, 1075921537, "_x_x_x_x_bach_float64_x_x_x_x_", 3061979993, 3221375738, "_x_x_x_x_bach_float64_x_x_x_x_", 3951221298, 1075919612, "_x_x_x_x_bach_float64_x_x_x_x_", 778352506, 3221434406, "_x_x_x_x_bach_float64_x_x_x_x_", 1610857981, 1075917498, "_x_x_x_x_bach_float64_x_x_x_x_", 1062175551, 3221493050, "_x_x_x_x_bach_float64_x_x_x_x_", 1070454797, 1075915193, "_x_x_x_x_bach_float64_x_x_x_x_", 9359996, 3221551661, "_x_x_x_x_bach_float64_x_x_x_x_", 1529406954, 1075912697, "_x_x_x_x_bach_float64_x_x_x_x_", 2209502248, 3221610228, "_x_x_x_x_bach_float64_x_x_x_x_", 2325446337, 1075910010, "_x_x_x_x_bach_float64_x_x_x_x_", 3573211362, 3221668742, "_x_x_x_x_bach_float64_x_x_x_x_", 2935119461, 1075907132, "_x_x_x_x_bach_float64_x_x_x_x_", 4224239686, 3221727193, "_x_x_x_x_bach_float64_x_x_x_x_", 2974242033, 1075904063, "_x_x_x_x_bach_float64_x_x_x_x_", 4211776119, 3221785571, "_x_x_x_x_bach_float64_x_x_x_x_", 2198329982, 1075900803, "_x_x_x_x_bach_float64_x_x_x_x_", 3517737055, 3221843866, "_x_x_x_x_bach_float64_x_x_x_x_", 503006830, 1075897352, "_x_x_x_x_bach_float64_x_x_x_x_", 2064086295, 3221902068, "_x_x_x_x_bach_float64_x_x_x_x_", 2219354584, 1075893709, "_x_x_x_x_bach_float64_x_x_x_x_", 4015150539, 3221960166, "_x_x_x_x_bach_float64_x_x_x_x_", 3229371541, 1075889875, "_x_x_x_x_bach_float64_x_x_x_x_", 605124696, 3222018152, "_x_x_x_x_bach_float64_x_x_x_x_", 3851209858, 1075885850, "_x_x_x_x_bach_float64_x_x_x_x_", 210243081, 3222076014, "_x_x_x_x_bach_float64_x_x_x_x_", 249552520, 1075881635, "_x_x_x_x_bach_float64_x_x_x_x_", 2586399700, 3222133742, "_x_x_x_x_bach_float64_x_x_x_x_", 1615769859, 1075877228, "_x_x_x_x_bach_float64_x_x_x_x_", 3171562834, 3222191327, "_x_x_x_x_bach_float64_x_x_x_x_", 103411467, 1075872631, "_x_x_x_x_bach_float64_x_x_x_x_", 1683178180, 3222248759, "_x_x_x_x_bach_float64_x_x_x_x_", 893215837, 1075867843, "_x_x_x_x_bach_float64_x_x_x_x_", 3210312596, 3222290037, "_x_x_x_x_bach_float64_x_x_x_x_", 718487927, 1075862865, "_x_x_x_x_bach_float64_x_x_x_x_", 4251460689, 3222318584, "_x_x_x_x_bach_float64_x_x_x_x_", 750190469, 1075857697, "_x_x_x_x_bach_float64_x_x_x_x_", 1675542220, 3222347040, "_x_x_x_x_bach_float64_x_x_x_x_", 2302141410, 1075852339, "_x_x_x_x_bach_float64_x_x_x_x_", 3937771944, 3222375398, "_x_x_x_x_bach_float64_x_x_x_x_", 2536186541, 1075846792, "_x_x_x_x_bach_float64_x_x_x_x_", 2324561711, 3222403655, "_x_x_x_x_bach_float64_x_x_x_x_", 3052249179, 1075841056, "_x_x_x_x_bach_float64_x_x_x_x_", 1022077156, 3222431805, "_x_x_x_x_bach_float64_x_x_x_x_", 2596971474, 1075831288, "_x_x_x_x_bach_float64_x_x_x_x_", 4235127688, 3222459842, "_x_x_x_x_bach_float64_x_x_x_x_", 2617538196, 1075819063, "_x_x_x_x_bach_float64_x_x_x_x_", 3306061981, 3222487763, "_x_x_x_x_bach_float64_x_x_x_x_", 1635653673, 1075806463, "_x_x_x_x_bach_float64_x_x_x_x_", 2488374255, 3222515562, "_x_x_x_x_bach_float64_x_x_x_x_", 3997348791, 1075793488, "_x_x_x_x_bach_float64_x_x_x_x_", 1770641671, 3222543234, "_x_x_x_x_bach_float64_x_x_x_x_", 1450373275, 1075780141, "_x_x_x_x_bach_float64_x_x_x_x_", 1175301926, 3222570774, "_x_x_x_x_bach_float64_x_x_x_x_", 3208895870, 1075766421, "_x_x_x_x_bach_float64_x_x_x_x_", 762466474, 3222598177, "_x_x_x_x_bach_float64_x_x_x_x_", 1593644494, 1075752331, "_x_x_x_x_bach_float64_x_x_x_x_", 633735932, 3222625438, "_x_x_x_x_bach_float64_x_x_x_x_", 2096505252, 1075737871, "_x_x_x_x_bach_float64_x_x_x_x_", 936017255, 3222652552, "_x_x_x_x_bach_float64_x_x_x_x_", 1905463083, 1075723043, "_x_x_x_x_bach_float64_x_x_x_x_", 1865341671, 3222679514, "_x_x_x_x_bach_float64_x_x_x_x_", 2789230088, 1075707848, "_x_x_x_x_bach_float64_x_x_x_x_", 3670682939, 3222706319, "_x_x_x_x_bach_float64_x_x_x_x_", 2506986478, 1075692288, "_x_x_x_x_bach_float64_x_x_x_x_", 2362807898, 3222732963, "_x_x_x_x_bach_float64_x_x_x_x_", 3397939835, 1075676364, "_x_x_x_x_bach_float64_x_x_x_x_", 2602995011, 3222759440, "_x_x_x_x_bach_float64_x_x_x_x_", 3790964282, 1075660078, "_x_x_x_x_bach_float64_x_x_x_x_", 526980212, 3222785746, "_x_x_x_x_bach_float64_x_x_x_x_", 2299090498, 1075643432, "_x_x_x_x_bach_float64_x_x_x_x_", 928638521, 3222811875, "_x_x_x_x_bach_float64_x_x_x_x_", 2113944840, 1075626427, "_x_x_x_x_bach_float64_x_x_x_x_", 83924204, 3222837823, "_x_x_x_x_bach_float64_x_x_x_x_", 2415235523, 1075609065, "_x_x_x_x_bach_float64_x_x_x_x_", 2934545515, 3222863584, "_x_x_x_x_bach_float64_x_x_x_x_" ],
									"whole_graph_data_0000000001" : [ 2665089700, 1075591348, "_x_x_x_x_bach_float64_x_x_x_x_", 1616929164, 3222889155, "_x_x_x_x_bach_float64_x_x_x_x_", 2607372292, 1075573278, "_x_x_x_x_bach_float64_x_x_x_x_", 1235820046, 3222914530, "_x_x_x_x_bach_float64_x_x_x_x_", 2266953724, 1075554857, "_x_x_x_x_bach_float64_x_x_x_x_", 2688201966, 3222939704, "_x_x_x_x_bach_float64_x_x_x_x_", 1948926818, 1075536087, "_x_x_x_x_bach_float64_x_x_x_x_", 2667081095, 3222964673, "_x_x_x_x_bach_float64_x_x_x_x_", 2237772697, 1075516970, "_x_x_x_x_bach_float64_x_x_x_x_", 2255196793, 3222989432, "_x_x_x_x_bach_float64_x_x_x_x_", 3996475803, 1075497508, "_x_x_x_x_bach_float64_x_x_x_x_", 2633822548, 3223013976, "_x_x_x_x_bach_float64_x_x_x_x_", 4070620845, 1075477704, "_x_x_x_x_bach_float64_x_x_x_x_", 791558489, 3223038301, "_x_x_x_x_bach_float64_x_x_x_x_", 3877340731, 1075457560, "_x_x_x_x_bach_float64_x_x_x_x_", 2412983646, 3223062401, "_x_x_x_x_bach_float64_x_x_x_x_", 814344739, 1075437079, "_x_x_x_x_bach_float64_x_x_x_x_", 407559968, 3223086273, "_x_x_x_x_bach_float64_x_x_x_x_", 1143732457, 1075416262, "_x_x_x_x_bach_float64_x_x_x_x_", 683165972, 3223109911, "_x_x_x_x_bach_float64_x_x_x_x_", 2810986133, 1075395112, "_x_x_x_x_bach_float64_x_x_x_x_", 674978737, 3223133311, "_x_x_x_x_bach_float64_x_x_x_x_", 4033716399, 1075373632, "_x_x_x_x_bach_float64_x_x_x_x_", 2234082415, 3223156468, "_x_x_x_x_bach_float64_x_x_x_x_", 3300422931, 1075351825, "_x_x_x_x_bach_float64_x_x_x_x_", 3041227452, 3223179378, "_x_x_x_x_bach_float64_x_x_x_x_", 3664172318, 1075329693, "_x_x_x_x_bach_float64_x_x_x_x_", 905478417, 3223202037, "_x_x_x_x_bach_float64_x_x_x_x_", 4151323862, 1075307239, "_x_x_x_x_bach_float64_x_x_x_x_", 2357815091, 3223224439, "_x_x_x_x_bach_float64_x_x_x_x_", 4055107290, 1075284466, "_x_x_x_x_bach_float64_x_x_x_x_", 1179947728, 3223246581, "_x_x_x_x_bach_float64_x_x_x_x_", 2934183424, 1075261377, "_x_x_x_x_bach_float64_x_x_x_x_", 4177757318, 3223268457, "_x_x_x_x_bach_float64_x_x_x_x_", 611155014, 1075237975, "_x_x_x_x_bach_float64_x_x_x_x_", 1120144824, 3223290065, "_x_x_x_x_bach_float64_x_x_x_x_", 1465995494, 1075214262, "_x_x_x_x_bach_float64_x_x_x_x_", 3397340496, 3223311398, "_x_x_x_x_bach_float64_x_x_x_x_", 1549559128, 1075190242, "_x_x_x_x_bach_float64_x_x_x_x_", 537408591, 3223327539, "_x_x_x_x_bach_float64_x_x_x_x_", 1466845759, 1075165918, "_x_x_x_x_bach_float64_x_x_x_x_", 2923265716, 3223337925, "_x_x_x_x_bach_float64_x_x_x_x_", 2080347461, 1075141293, "_x_x_x_x_bach_float64_x_x_x_x_", 4044400044, 3223348168, "_x_x_x_x_bach_float64_x_x_x_x_", 213346251, 1075116371, "_x_x_x_x_bach_float64_x_x_x_x_", 3464300696, 3223358266, "_x_x_x_x_bach_float64_x_x_x_x_", 1533032540, 1075091154, "_x_x_x_x_bach_float64_x_x_x_x_", 828575227, 3223368217, "_x_x_x_x_bach_float64_x_x_x_x_", 3368804076, 1075065646, "_x_x_x_x_bach_float64_x_x_x_x_", 161661591, 3223378018, "_x_x_x_x_bach_float64_x_x_x_x_", 3300320495, 1075039851, "_x_x_x_x_bach_float64_x_x_x_x_", 1278627522, 3223387667, "_x_x_x_x_bach_float64_x_x_x_x_", 3450542763, 1075013772, "_x_x_x_x_bach_float64_x_x_x_x_", 4081860837, 3223397162, "_x_x_x_x_bach_float64_x_x_x_x_", 1893822860, 1074987413, "_x_x_x_x_bach_float64_x_x_x_x_", 4267813771, 3223406502, "_x_x_x_x_bach_float64_x_x_x_x_", 1243815406, 1074960777, "_x_x_x_x_bach_float64_x_x_x_x_", 1918637561, 3223415685, "_x_x_x_x_bach_float64_x_x_x_x_", 61472833, 1074933868, "_x_x_x_x_bach_float64_x_x_x_x_", 1503870460, 3223424708, "_x_x_x_x_bach_float64_x_x_x_x_", 1442862860, 1074906689, "_x_x_x_x_bach_float64_x_x_x_x_", 3292178833, 3223433569, "_x_x_x_x_bach_float64_x_x_x_x_", 132102912, 1074879245, "_x_x_x_x_bach_float64_x_x_x_x_", 3353020280, 3223442267, "_x_x_x_x_bach_float64_x_x_x_x_", 3993986429, 1074851538, "_x_x_x_x_bach_float64_x_x_x_x_", 2148228353, 3223450800, "_x_x_x_x_bach_float64_x_x_x_x_", 3946955720, 1074823574, "_x_x_x_x_bach_float64_x_x_x_x_", 238682156, 3223459166, "_x_x_x_x_bach_float64_x_x_x_x_", 4025571142, 1074795356, "_x_x_x_x_bach_float64_x_x_x_x_", 2580896977, 3223467362, "_x_x_x_x_bach_float64_x_x_x_x_", 4101621852, 1074743377, "_x_x_x_x_bach_float64_x_x_x_x_", 1348764521, 3223475388, "_x_x_x_x_bach_float64_x_x_x_x_", 730194107, 1074685950, "_x_x_x_x_bach_float64_x_x_x_x_", 1704951967, 3223483241, "_x_x_x_x_bach_float64_x_x_x_x_", 3069781261, 1074628038, "_x_x_x_x_bach_float64_x_x_x_x_", 327646215, 3223490920, "_x_x_x_x_bach_float64_x_x_x_x_", 3811518674, 1074569651, "_x_x_x_x_bach_float64_x_x_x_x_", 2591989016, 3223498422, "_x_x_x_x_bach_float64_x_x_x_x_", 379572376, 1074510798, "_x_x_x_x_bach_float64_x_x_x_x_", 1096791302, 3223505747, "_x_x_x_x_bach_float64_x_x_x_x_", 3515934731, 1074451485, "_x_x_x_x_bach_float64_x_x_x_x_", 1435872391, 3223512892, "_x_x_x_x_bach_float64_x_x_x_x_", 2915459964, 1074391723, "_x_x_x_x_bach_float64_x_x_x_x_", 724743188, 3223519856, "_x_x_x_x_bach_float64_x_x_x_x_", 1580290759, 1074331520, "_x_x_x_x_bach_float64_x_x_x_x_", 487011746, 3223526637, "_x_x_x_x_bach_float64_x_x_x_x_", 2929559111, 1074270884, "_x_x_x_x_bach_float64_x_x_x_x_", 2360903340, 3223533233, "_x_x_x_x_bach_float64_x_x_x_x_", 2203969962, 1074209825, "_x_x_x_x_bach_float64_x_x_x_x_", 3805763916, 3223539643, "_x_x_x_x_bach_float64_x_x_x_x_", 3640105072, 1074148351, "_x_x_x_x_bach_float64_x_x_x_x_", 2398481268, 3223545866, "_x_x_x_x_bach_float64_x_x_x_x_", 3284905204, 1074086472, "_x_x_x_x_bach_float64_x_x_x_x_", 129888999, 3223551900, "_x_x_x_x_bach_float64_x_x_x_x_", 1874841676, 1074024197, "_x_x_x_x_bach_float64_x_x_x_x_", 3406185727, 3223557742, "_x_x_x_x_bach_float64_x_x_x_x_", 535137256, 1073961535, "_x_x_x_x_bach_float64_x_x_x_x_", 1575500056, 3223563393, "_x_x_x_x_bach_float64_x_x_x_x_", 773873941, 1073898495, "_x_x_x_x_bach_float64_x_x_x_x_", 1289012345, 3223568850, "_x_x_x_x_bach_float64_x_x_x_x_", 181054093, 1073835087, "_x_x_x_x_bach_float64_x_x_x_x_", 732516037, 3223574112, "_x_x_x_x_bach_float64_x_x_x_x_", 1012484404, 1073771320, "_x_x_x_x_bach_float64_x_x_x_x_", 2512666052, 3223579177, "_x_x_x_x_bach_float64_x_x_x_x_", 3187426631, 1073672584, "_x_x_x_x_bach_float64_x_x_x_x_", 773404527, 3223584045, "_x_x_x_x_bach_float64_x_x_x_x_", 1217586551, 1073543674, "_x_x_x_x_bach_float64_x_x_x_x_", 2672105808, 3223588713, "_x_x_x_x_bach_float64_x_x_x_x_", 2777934157, 1073414104, "_x_x_x_x_bach_float64_x_x_x_x_", 2611061762, 3223593181, "_x_x_x_x_bach_float64_x_x_x_x_", 2337787806, 1073283895, "_x_x_x_x_bach_float64_x_x_x_x_", 3713587705, 3223597447, "_x_x_x_x_bach_float64_x_x_x_x_", 3635274823, 1073153066, "_x_x_x_x_bach_float64_x_x_x_x_", 645402709, 3223601511, "_x_x_x_x_bach_float64_x_x_x_x_", 2484456779, 1073021638, "_x_x_x_x_bach_float64_x_x_x_x_", 1090695406, 3223605370, "_x_x_x_x_bach_float64_x_x_x_x_", 3942048631, 1072889630, "_x_x_x_x_bach_float64_x_x_x_x_", 4278496379, 3223609023, "_x_x_x_x_bach_float64_x_x_x_x_", 819290117, 1072757064, "_x_x_x_x_bach_float64_x_x_x_x_", 983866330, 3223612471, "_x_x_x_x_bach_float64_x_x_x_x_", 3171602820, 1072554669, "_x_x_x_x_bach_float64_x_x_x_x_", 3593834405, 3223615710, "_x_x_x_x_bach_float64_x_x_x_x_", 582482977, 1072287423, "_x_x_x_x_bach_float64_x_x_x_x_", 3158871256, 3223618741, "_x_x_x_x_bach_float64_x_x_x_x_", 347845221, 1072019182, "_x_x_x_x_bach_float64_x_x_x_x_", 3753752037, 3223621562, "_x_x_x_x_bach_float64_x_x_x_x_", 1524137241, 1071749988, "_x_x_x_x_bach_float64_x_x_x_x_", 1003822846, 3223624173, "_x_x_x_x_bach_float64_x_x_x_x_", 29308584, 1071315096, "_x_x_x_x_bach_float64_x_x_x_x_", 3560918243, 3223626571, "_x_x_x_x_bach_float64_x_x_x_x_", 2852480273, 1070773150, "_x_x_x_x_bach_float64_x_x_x_x_", 3039649062, 3223628757, "_x_x_x_x_bach_float64_x_x_x_x_", 2558941205, 1069863011, "_x_x_x_x_bach_float64_x_x_x_x_", 4083210003, 3223630729, "_x_x_x_x_bach_float64_x_x_x_x_", 558121619, 1067496760, "_x_x_x_x_bach_float64_x_x_x_x_", 2889557071, 3223632487, "_x_x_x_x_bach_float64_x_x_x_x_", 1618408809, 3216573102, "_x_x_x_x_bach_float64_x_x_x_x_", 97300572, 3223634030, "_x_x_x_x_bach_float64_x_x_x_x_", 4139903477, 3217898206, "_x_x_x_x_bach_float64_x_x_x_x_", 786673172, 3223635356, "_x_x_x_x_bach_float64_x_x_x_x_", 2767363089, 3218538317, "_x_x_x_x_bach_float64_x_x_x_x_", 1595572840, 3223636465, "_x_x_x_x_bach_float64_x_x_x_x_", 2754449802, 3219088878, "_x_x_x_x_bach_float64_x_x_x_x_", 3605386075, 3223637356, "_x_x_x_x_bach_float64_x_x_x_x_", 1308824828, 3219384445, "_x_x_x_x_bach_float64_x_x_x_x_", 3751951009, 3223638029, "_x_x_x_x_bach_float64_x_x_x_x_", 2739964235, 3219660812, "_x_x_x_x_bach_float64_x_x_x_x_", 3416365810, 3223638483, "_x_x_x_x_bach_float64_x_x_x_x_", 4235750250, 3219937656, "_x_x_x_x_bach_float64_x_x_x_x_", 4130871118, 3223638717, "_x_x_x_x_bach_float64_x_x_x_x_", 3918952204, 3220195914, "_x_x_x_x_bach_float64_x_x_x_x_", 3284708225, 3223638731, "_x_x_x_x_bach_float64_x_x_x_x_", 957821034, 3220334747, "_x_x_x_x_bach_float64_x_x_x_x_", 2714854676, 3223638524, "_x_x_x_x_bach_float64_x_x_x_x_", 4220631159, 3220473750, "_x_x_x_x_bach_float64_x_x_x_x_", 116866030, 3223638096, "_x_x_x_x_bach_float64_x_x_x_x_", 2855942443, 3220612903, "_x_x_x_x_bach_float64_x_x_x_x_", 1930529282, 3223637445, "_x_x_x_x_bach_float64_x_x_x_x_", 2845101227, 3220752182, "_x_x_x_x_bach_float64_x_x_x_x_", 1865752890, 3223636572, "_x_x_x_x_bach_float64_x_x_x_x_", 1248200423, 3220891565, "_x_x_x_x_bach_float64_x_x_x_x_", 2378104581, 3223635476, "_x_x_x_x_bach_float64_x_x_x_x_", 3399804700, 3221031028, "_x_x_x_x_bach_float64_x_x_x_x_", 1784585428, 3223634157, "_x_x_x_x_bach_float64_x_x_x_x_", 1450057830, 3221170550, "_x_x_x_x_bach_float64_x_x_x_x_", 2854214863, 3223632614, "_x_x_x_x_bach_float64_x_x_x_x_", 2222742055, 3221267789, "_x_x_x_x_bach_float64_x_x_x_x_", 4218720839, 3223630847, "_x_x_x_x_bach_float64_x_x_x_x_", 4140165551, 3221337573, "_x_x_x_x_bach_float64_x_x_x_x_", 373138710, 3223628857, "_x_x_x_x_bach_float64_x_x_x_x_", 3865580, 3221407353, "_x_x_x_x_bach_float64_x_x_x_x_", 3151220586, 3223626641, "_x_x_x_x_bach_float64_x_x_x_x_", 402823811, 3221477115, "_x_x_x_x_bach_float64_x_x_x_x_", 3071276398, 3223624201, "_x_x_x_x_bach_float64_x_x_x_x_", 2931840294, 3221546848, "_x_x_x_x_bach_float64_x_x_x_x_", 3696432671, 3223621536, "_x_x_x_x_bach_float64_x_x_x_x_", 789678604, 3221616542, "_x_x_x_x_bach_float64_x_x_x_x_", 160290019, 3223618647, "_x_x_x_x_bach_float64_x_x_x_x_", 4262147950, 3221686183, "_x_x_x_x_bach_float64_x_x_x_x_", 642227007, 3223615532, "_x_x_x_x_bach_float64_x_x_x_x_", 2075676596, 3221755762, "_x_x_x_x_bach_float64_x_x_x_x_", 598037028, 3223612192, "_x_x_x_x_bach_float64_x_x_x_x_", 60329344, 3221825266, "_x_x_x_x_bach_float64_x_x_x_x_", 4235178602, 3223608626, "_x_x_x_x_bach_float64_x_x_x_x_", 3978280687, 3221894682, "_x_x_x_x_bach_float64_x_x_x_x_", 3038325732, 3223604836, "_x_x_x_x_bach_float64_x_x_x_x_", 2352317720, 3221964001, "_x_x_x_x_bach_float64_x_x_x_x_", 1539531430, 3223600821, "_x_x_x_x_bach_float64_x_x_x_x_", 833978742, 3222033210, "_x_x_x_x_bach_float64_x_x_x_x_", 138691075, 3223596581, "_x_x_x_x_bach_float64_x_x_x_x_", 737143549, 3222102297, "_x_x_x_x_bach_float64_x_x_x_x_", 3693782203, 3223592115, "_x_x_x_x_bach_float64_x_x_x_x_", 3341453271, 3222171250, "_x_x_x_x_bach_float64_x_x_x_x_", 46305836, 3223587426, "_x_x_x_x_bach_float64_x_x_x_x_", 1310851794, 3222240059, "_x_x_x_x_bach_float64_x_x_x_x_", 2971209690, 3223582511, "_x_x_x_x_bach_float64_x_x_x_x_", 2235944138, 3222291379, "_x_x_x_x_bach_float64_x_x_x_x_", 637503257, 3223577373, "_x_x_x_x_bach_float64_x_x_x_x_", 583765636, 3222325621, "_x_x_x_x_bach_float64_x_x_x_x_", 2853092993, 3223572010, "_x_x_x_x_bach_float64_x_x_x_x_", 2755174106, 3222359772, "_x_x_x_x_bach_float64_x_x_x_x_", 2410243734, 3223566424, "_x_x_x_x_bach_float64_x_x_x_x_", 778244180, 3222393828, "_x_x_x_x_bach_float64_x_x_x_x_", 855521708, 3223560615, "_x_x_x_x_bach_float64_x_x_x_x_", 3869383196, 3222427781, "_x_x_x_x_bach_float64_x_x_x_x_", 4194938479, 3223554582, "_x_x_x_x_bach_float64_x_x_x_x_", 4077887656, 3222461627, "_x_x_x_x_bach_float64_x_x_x_x_", 1419197678, 3223548328, "_x_x_x_x_bach_float64_x_x_x_x_", 2060048629, 3222495360, "_x_x_x_x_bach_float64_x_x_x_x_", 3158455751, 3223541851, "_x_x_x_x_bach_float64_x_x_x_x_", 2788492456, 3222528973, "_x_x_x_x_bach_float64_x_x_x_x_", 3027643211, 3223535153, "_x_x_x_x_bach_float64_x_x_x_x_", 2671592100, 3222562461, "_x_x_x_x_bach_float64_x_x_x_x_", 3396267100, 3223528234, "_x_x_x_x_bach_float64_x_x_x_x_", 2442687098, 3222595818, "_x_x_x_x_bach_float64_x_x_x_x_", 2503479475, 3223521095, "_x_x_x_x_bach_float64_x_x_x_x_", 2869438277, 3222629038, "_x_x_x_x_bach_float64_x_x_x_x_", 3047954072, 3223513736, "_x_x_x_x_bach_float64_x_x_x_x_", 463185608, 3222662116, "_x_x_x_x_bach_float64_x_x_x_x_", 3597865342, 3223506158, "_x_x_x_x_bach_float64_x_x_x_x_", 368177936, 3222695045, "_x_x_x_x_bach_float64_x_x_x_x_", 2885741004, 3223498362, "_x_x_x_x_bach_float64_x_x_x_x_", 3481000463, 3222727819, "_x_x_x_x_bach_float64_x_x_x_x_", 4103286104, 3223490348, "_x_x_x_x_bach_float64_x_x_x_x_", 2159937917, 3222760434, "_x_x_x_x_bach_float64_x_x_x_x_", 2016309407, 3223482118, "_x_x_x_x_bach_float64_x_x_x_x_", 1704141758, 3222792883, "_x_x_x_x_bach_float64_x_x_x_x_", 144392354, 3223473672, "_x_x_x_x_bach_float64_x_x_x_x_", 3178091103, 3222825160, "_x_x_x_x_bach_float64_x_x_x_x_", 2170725674, 3223465010, "_x_x_x_x_bach_float64_x_x_x_x_", 3415921783, 3222857260, "_x_x_x_x_bach_float64_x_x_x_x_", 3351917477, 3223456134, "_x_x_x_x_bach_float64_x_x_x_x_", 3615687802, 3222889177, "_x_x_x_x_bach_float64_x_x_x_x_", 3402609239, 3223447045, "_x_x_x_x_bach_float64_x_x_x_x_", 753750940, 3222920906, "_x_x_x_x_bach_float64_x_x_x_x_", 2200194039, 3223437744, "_x_x_x_x_bach_float64_x_x_x_x_", 474003334, 3222952440, "_x_x_x_x_bach_float64_x_x_x_x_", 4079440833, 3223428231, "_x_x_x_x_bach_float64_x_x_x_x_", 4207281920, 3222983773, "_x_x_x_x_bach_float64_x_x_x_x_", 652253637, 3223418509, "_x_x_x_x_bach_float64_x_x_x_x_", 585745347, 3223014902, "_x_x_x_x_bach_float64_x_x_x_x_", 872042454, 3223408577, "_x_x_x_x_bach_float64_x_x_x_x_", 4101885185, 3223045818, "_x_x_x_x_bach_float64_x_x_x_x_", 968523487, 3223398437, "_x_x_x_x_bach_float64_x_x_x_x_", 3573217474, 3223076518, "_x_x_x_x_bach_float64_x_x_x_x_", 1627131087, 3223388090, "_x_x_x_x_bach_float64_x_x_x_x_", 801280214, 3223106996, "_x_x_x_x_bach_float64_x_x_x_x_", 3693564740, 3223377537, "_x_x_x_x_bach_float64_x_x_x_x_", 1985982467, 3223137245, "_x_x_x_x_bach_float64_x_x_x_x_", 3878307530, 3223366780, "_x_x_x_x_bach_float64_x_x_x_x_", 550010249, 3223167261, "_x_x_x_x_bach_float64_x_x_x_x_", 3346018109, 3223355820, "_x_x_x_x_bach_float64_x_x_x_x_", 2912895653, 3223197037, "_x_x_x_x_bach_float64_x_x_x_x_", 3419992352, 3223344658, "_x_x_x_x_bach_float64_x_x_x_x_", 2725468208, 3223226569, "_x_x_x_x_bach_float64_x_x_x_x_", 1286596646, 3223333296, "_x_x_x_x_bach_float64_x_x_x_x_", 2348935429, 3223255851, "_x_x_x_x_bach_float64_x_x_x_x_", 1464116918, 3223320845, "_x_x_x_x_bach_float64_x_x_x_x_", 4269180392, 3223284877, "_x_x_x_x_bach_float64_x_x_x_x_", 2808784182, 3223297326, "_x_x_x_x_bach_float64_x_x_x_x_", 2511046918, 3223313643, "_x_x_x_x_bach_float64_x_x_x_x_", 1920396413, 3223273415, "_x_x_x_x_bach_float64_x_x_x_x_", 2058691173, 3223332383, "_x_x_x_x_bach_float64_x_x_x_x_", 3012804962, 3223249114, "_x_x_x_x_bach_float64_x_x_x_x_", 1691713021, 3223346497, "_x_x_x_x_bach_float64_x_x_x_x_", 2019161331, 3223224427, "_x_x_x_x_bach_float64_x_x_x_x_", 3815395331, 3223360472, "_x_x_x_x_bach_float64_x_x_x_x_", 3770249754, 3223199356, "_x_x_x_x_bach_float64_x_x_x_x_", 1425942802, 3223374307, "_x_x_x_x_bach_float64_x_x_x_x_", 518058158, 3223173906, "_x_x_x_x_bach_float64_x_x_x_x_", 479351464, 3223387998, "_x_x_x_x_bach_float64_x_x_x_x_", 1998901185, 3223148078, "_x_x_x_x_bach_float64_x_x_x_x_", 2713603721, 3223401542, "_x_x_x_x_bach_float64_x_x_x_x_", 1071978209, 3223121877, "_x_x_x_x_bach_float64_x_x_x_x_", 1355756406, 3223414938, "_x_x_x_x_bach_float64_x_x_x_x_", 3782385539, 3223095305, "_x_x_x_x_bach_float64_x_x_x_x_", 2598823349, 3223428182, "_x_x_x_x_bach_float64_x_x_x_x_", 3589498756, 3223068367, "_x_x_x_x_bach_float64_x_x_x_x_", 4128975285, 3223441272, "_x_x_x_x_bach_float64_x_x_x_x_", 2839940263, 3223041066, "_x_x_x_x_bach_float64_x_x_x_x_", 3717500911, 3223454206, "_x_x_x_x_bach_float64_x_x_x_x_", 4175721286, 3223013405, "_x_x_x_x_bach_float64_x_x_x_x_", 3517790174, 3223466981, "_x_x_x_x_bach_float64_x_x_x_x_", 1942329346, 3222985389, "_x_x_x_x_bach_float64_x_x_x_x_", 1477404971, 3223479595, "_x_x_x_x_bach_float64_x_x_x_x_", 3661532619, 3222957020, "_x_x_x_x_bach_float64_x_x_x_x_", 4224975197, 3223492044, "_x_x_x_x_bach_float64_x_x_x_x_", 4259490175, 3222928303, "_x_x_x_x_bach_float64_x_x_x_x_", 1302377621, 3223504328, "_x_x_x_x_bach_float64_x_x_x_x_", 3244481320, 3222899242, "_x_x_x_x_bach_float64_x_x_x_x_", 3821412431, 3223516442, "_x_x_x_x_bach_float64_x_x_x_x_", 409745195, 3222869841, "_x_x_x_x_bach_float64_x_x_x_x_", 1516088868, 3223528386, "_x_x_x_x_bach_float64_x_x_x_x_", 126201755, 3222840103, "_x_x_x_x_bach_float64_x_x_x_x_", 1399276962, 3223540156, "_x_x_x_x_bach_float64_x_x_x_x_", 2750217978, 3222810032, "_x_x_x_x_bach_float64_x_x_x_x_", 1994836893, 3223551750, "_x_x_x_x_bach_float64_x_x_x_x_", 326288907, 3222779634, "_x_x_x_x_bach_float64_x_x_x_x_", 1929473411, 3223563166, "_x_x_x_x_bach_float64_x_x_x_x_", 2354437320, 3222748911, "_x_x_x_x_bach_float64_x_x_x_x_", 4229609389, 3223574401, "_x_x_x_x_bach_float64_x_x_x_x_", 1428019488, 3222717869, "_x_x_x_x_bach_float64_x_x_x_x_", 3438376120, 3223585454, "_x_x_x_x_bach_float64_x_x_x_x_", 3295988664, 3222686511, "_x_x_x_x_bach_float64_x_x_x_x_", 2797360395, 3223596322, "_x_x_x_x_bach_float64_x_x_x_x_", 1090532444, 3222654843, "_x_x_x_x_bach_float64_x_x_x_x_", 1363565798, 3223607003, "_x_x_x_x_bach_float64_x_x_x_x_", 1094266814, 3222622868, "_x_x_x_x_bach_float64_x_x_x_x_", 2601195413, 3223617494, "_x_x_x_x_bach_float64_x_x_x_x_", 1262739177, 3222590591, "_x_x_x_x_bach_float64_x_x_x_x_", 1498582726, 3223627794, "_x_x_x_x_bach_float64_x_x_x_x_", 4106619693, 3222558016, "_x_x_x_x_bach_float64_x_x_x_x_", 1749877802, 3223637900, "_x_x_x_x_bach_float64_x_x_x_x_", 3804038905, 3222525149, "_x_x_x_x_bach_float64_x_x_x_x_", 2871946346, 3223647810, "_x_x_x_x_bach_float64_x_x_x_x_", 3377646945, 3222491994, "_x_x_x_x_bach_float64_x_x_x_x_", 206154241, 3223657523, "_x_x_x_x_bach_float64_x_x_x_x_", 1806852693, 3222458556, "_x_x_x_x_bach_float64_x_x_x_x_", 2100004481, 3223667035, "_x_x_x_x_bach_float64_x_x_x_x_", 2614850516, 3222424839, "_x_x_x_x_bach_float64_x_x_x_x_", 4139084118, 3223676345, "_x_x_x_x_bach_float64_x_x_x_x_", 980762454, 3222390849, "_x_x_x_x_bach_float64_x_x_x_x_", 2033699400, 3223685452, "_x_x_x_x_bach_float64_x_x_x_x_", 916503490, 3222356590, "_x_x_x_x_bach_float64_x_x_x_x_", 210525889, 3223694353, "_x_x_x_x_bach_float64_x_x_x_x_", 2378828437, 3222322067, "_x_x_x_x_bach_float64_x_x_x_x_", 3224371284, 3223703045, "_x_x_x_x_bach_float64_x_x_x_x_", 1266233500, 3222287286, "_x_x_x_x_bach_float64_x_x_x_x_", 2874952605, 3223711528, "_x_x_x_x_bach_float64_x_x_x_x_", 306459466, 3222230455, "_x_x_x_x_bach_float64_x_x_x_x_", 3978360252, 3223719799, "_x_x_x_x_bach_float64_x_x_x_x_", 3689402191, 3222159888, "_x_x_x_x_bach_float64_x_x_x_x_", 2893862790, 3223727857, "_x_x_x_x_bach_float64_x_x_x_x_", 1565466437, 3222088836, "_x_x_x_x_bach_float64_x_x_x_x_", 410430736, 3223735700, "_x_x_x_x_bach_float64_x_x_x_x_", 446401766, 3222017308, "_x_x_x_x_bach_float64_x_x_x_x_", 1748338763, 3223743325, "_x_x_x_x_bach_float64_x_x_x_x_", 2990046324, 3221945314, "_x_x_x_x_bach_float64_x_x_x_x_", 3675846061, 3223750731, "_x_x_x_x_bach_float64_x_x_x_x_", 3698618320, 3221872866, "_x_x_x_x_bach_float64_x_x_x_x_", 3100692838, 3223757917, "_x_x_x_x_bach_float64_x_x_x_x_", 1796789056, 3221799975, "_x_x_x_x_bach_float64_x_x_x_x_", 1366608942, 3223764881, "_x_x_x_x_bach_float64_x_x_x_x_", 1224767642, 3221726651, "_x_x_x_x_bach_float64_x_x_x_x_", 4254834274, 3223771620, "_x_x_x_x_bach_float64_x_x_x_x_", 2041365962, 3221652905, "_x_x_x_x_bach_float64_x_x_x_x_", 510781504, 3223778135, "_x_x_x_x_bach_float64_x_x_x_x_", 416913433, 3221578749, "_x_x_x_x_bach_float64_x_x_x_x_", 500219450, 3223784422, "_x_x_x_x_bach_float64_x_x_x_x_", 1510990796, 3221504193, "_x_x_x_x_bach_float64_x_x_x_x_", 1850990602, 3223790480, "_x_x_x_x_bach_float64_x_x_x_x_", 2285310408, 3221429249, "_x_x_x_x_bach_float64_x_x_x_x_", 2339346829, 3223796308, "_x_x_x_x_bach_float64_x_x_x_x_", 86319171, 3221353929, "_x_x_x_x_bach_float64_x_x_x_x_", 4186328109, 3223801904, "_x_x_x_x_bach_float64_x_x_x_x_", 1227721676, 3221278243, "_x_x_x_x_bach_float64_x_x_x_x_", 1174249414, 3223807268, "_x_x_x_x_bach_float64_x_x_x_x_", 3311273114, 3221178935, "_x_x_x_x_bach_float64_x_x_x_x_", 122903057, 3223812397, "_x_x_x_x_bach_float64_x_x_x_x_", 3946827822, 3221026172, "_x_x_x_x_bach_float64_x_x_x_x_", 3711032109, 3223817289, "_x_x_x_x_bach_float64_x_x_x_x_", 1983078796, 3220872749, "_x_x_x_x_bach_float64_x_x_x_x_", 1887714963, 3223821945, "_x_x_x_x_bach_float64_x_x_x_x_", 29762270, 3220718689, "_x_x_x_x_bach_float64_x_x_x_x_", 1938431780, 3223826362, "_x_x_x_x_bach_float64_x_x_x_x_", 1374823241, 3220564015, "_x_x_x_x_bach_float64_x_x_x_x_", 2716532064, 3223830539, "_x_x_x_x_bach_float64_x_x_x_x_", 1378744960, 3220408752, "_x_x_x_x_bach_float64_x_x_x_x_", 3234416347, 3223834475, "_x_x_x_x_bach_float64_x_x_x_x_", 343572128, 3220252924, "_x_x_x_x_bach_float64_x_x_x_x_", 2664758701, 3223838169, "_x_x_x_x_bach_float64_x_x_x_x_", 2698813699, 3220016213, "_x_x_x_x_bach_float64_x_x_x_x_", 341704474, 3223841620, "_x_x_x_x_bach_float64_x_x_x_x_", 3296629729, 3219702441, "_x_x_x_x_bach_float64_x_x_x_x_", 57010270, 3223844826, "_x_x_x_x_bach_float64_x_x_x_x_", 2475930359, 3219387685, "_x_x_x_x_bach_float64_x_x_x_x_", 1471256733, 3223847786, "_x_x_x_x_bach_float64_x_x_x_x_", 2790867169, 3219015668, "_x_x_x_x_bach_float64_x_x_x_x_", 114970406, 3223850500, "_x_x_x_x_bach_float64_x_x_x_x_", 393268117, 3218382515, "_x_x_x_x_bach_float64_x_x_x_x_", 274621676, 3223852966, "_x_x_x_x_bach_float64_x_x_x_x_", 471635943, 3217415636, "_x_x_x_x_bach_float64_x_x_x_x_", 2108792949, 3223855183, "_x_x_x_x_bach_float64_x_x_x_x_", 3374248602, 3214118873, "_x_x_x_x_bach_float64_x_x_x_x_", 1649222455, 3223857151, "_x_x_x_x_bach_float64_x_x_x_x_", 1608253994, 1069614427, "_x_x_x_x_bach_float64_x_x_x_x_", 3686723475, 3223858868, "_x_x_x_x_bach_float64_x_x_x_x_", 3551941949, 1070744498, "_x_x_x_x_bach_float64_x_x_x_x_", 297338513, 3223860335, "_x_x_x_x_bach_float64_x_x_x_x_", 1484739160, 1071385004, "_x_x_x_x_bach_float64_x_x_x_x_", 908074105, 3223861549, "_x_x_x_x_bach_float64_x_x_x_x_", 751439388, 1071835674, "_x_x_x_x_bach_float64_x_x_x_x_", 2233066345, 3223862510, "_x_x_x_x_bach_float64_x_x_x_x_", 1140620942, 1072157042, "_x_x_x_x_bach_float64_x_x_x_x_", 1159392063, 3223863218, "_x_x_x_x_bach_float64_x_x_x_x_", 390867941, 1072478891, "_x_x_x_x_bach_float64_x_x_x_x_", 3337885131, 3223863671, "_x_x_x_x_bach_float64_x_x_x_x_", 2375912416, 1072747208, "_x_x_x_x_bach_float64_x_x_x_x_", 1709153988, 3223863870, "_x_x_x_x_bach_float64_x_x_x_x_", 1253736132, 1072908536, "_x_x_x_x_bach_float64_x_x_x_x_", 2274211464, 3223863813, "_x_x_x_x_bach_float64_x_x_x_x_", 3480726391, 1073070026, "_x_x_x_x_bach_float64_x_x_x_x_", 2620436217, 3223863500, "_x_x_x_x_bach_float64_x_x_x_x_", 319172754, 1073231654, "_x_x_x_x_bach_float64_x_x_x_x_", 512276927, 3223862931, "_x_x_x_x_bach_float64_x_x_x_x_", 4167074877, 1073393391, "_x_x_x_x_bach_float64_x_x_x_x_", 2481927991, 3223862104, "_x_x_x_x_bach_float64_x_x_x_x_", 1331615645, 1073555214, "_x_x_x_x_bach_float64_x_x_x_x_", 2355205460, 3223861020, "_x_x_x_x_bach_float64_x_x_x_x_", 3586970819, 1073717094, "_x_x_x_x_bach_float64_x_x_x_x_", 2727067085, 3223859678, "_x_x_x_x_bach_float64_x_x_x_x_", 2621462704, 1073810415, "_x_x_x_x_bach_float64_x_x_x_x_", 2077364970, 3223858078, "_x_x_x_x_bach_float64_x_x_x_x_", 2319041631, 1073891374, "_x_x_x_x_bach_float64_x_x_x_x_", 3361405515, 3223856219, "_x_x_x_x_bach_float64_x_x_x_x_", 4226643897, 1073972322, "_x_x_x_x_bach_float64_x_x_x_x_", 1125643538, 3223854102, "_x_x_x_x_bach_float64_x_x_x_x_", 2980175199, 1074053247, "_x_x_x_x_bach_float64_x_x_x_x_", 2983085248, 3223851725, "_x_x_x_x_bach_float64_x_x_x_x_", 1700197408, 1074134135, "_x_x_x_x_bach_float64_x_x_x_x_", 3844021327, 3223849089, "_x_x_x_x_bach_float64_x_x_x_x_", 3411333083, 1074214972, "_x_x_x_x_bach_float64_x_x_x_x_", 3096403158, 3223846194, "_x_x_x_x_bach_float64_x_x_x_x_", 2461704329, 1074295746, "_x_x_x_x_bach_float64_x_x_x_x_", 311352637, 3223843040, "_x_x_x_x_bach_float64_x_x_x_x_", 1712207994, 1074376443, "_x_x_x_x_bach_float64_x_x_x_x_", 3833543812, 3223839625, "_x_x_x_x_bach_float64_x_x_x_x_", 3956018826, 1074457049, "_x_x_x_x_bach_float64_x_x_x_x_", 716848623, 3223835952, "_x_x_x_x_bach_float64_x_x_x_x_", 3338121856, 1074537552, "_x_x_x_x_bach_float64_x_x_x_x_", 3969363668, 3223832018, "_x_x_x_x_bach_float64_x_x_x_x_", 2544676946, 1074617938, "_x_x_x_x_bach_float64_x_x_x_x_", 1014158692, 3223827826, "_x_x_x_x_bach_float64_x_x_x_x_", 4222606134, 1074698193, "_x_x_x_x_bach_float64_x_x_x_x_", 934242319, 3223823374, "_x_x_x_x_bach_float64_x_x_x_x_", 2399205743, 1074778305, "_x_x_x_x_bach_float64_x_x_x_x_", 113118492, 3223818663, "_x_x_x_x_bach_float64_x_x_x_x_", 4130760377, 1074824329, "_x_x_x_x_bach_float64_x_x_x_x_", 3709886952, 3223813692, "_x_x_x_x_bach_float64_x_x_x_x_", 3608131907, 1074864221, "_x_x_x_x_bach_float64_x_x_x_x_", 4184639896, 3223808463, "_x_x_x_x_bach_float64_x_x_x_x_", 3072033950, 1074904021, "_x_x_x_x_bach_float64_x_x_x_x_", 2773500607, 3223802976, "_x_x_x_x_bach_float64_x_x_x_x_", 3819656811, 1074943722, "_x_x_x_x_bach_float64_x_x_x_x_", 898859930, 3223797231, "_x_x_x_x_bach_float64_x_x_x_x_", 2862404889, 1074983318, "_x_x_x_x_bach_float64_x_x_x_x_", 169516218, 3223791228, "_x_x_x_x_bach_float64_x_x_x_x_", 1520663139, 1075022802, "_x_x_x_x_bach_float64_x_x_x_x_", 2380783986, 3223784967, "_x_x_x_x_bach_float64_x_x_x_x_", 1133668314, 1075062167, "_x_x_x_x_bach_float64_x_x_x_x_", 924636719, 3223778450, "_x_x_x_x_bach_float64_x_x_x_x_", 3064353724, 1075101406, "_x_x_x_x_bach_float64_x_x_x_x_", 2264589335, 3223771676, "_x_x_x_x_bach_float64_x_x_x_x_", 114264539, 1075140514, "_x_x_x_x_bach_float64_x_x_x_x_", 165908984, 3223764647, "_x_x_x_x_bach_float64_x_x_x_x_", 2298216157, 1075179482, "_x_x_x_x_bach_float64_x_x_x_x_", 1465401844, 3223757362, "_x_x_x_x_bach_float64_x_x_x_x_", 2489413821, 1075218305, "_x_x_x_x_bach_float64_x_x_x_x_", 301560859, 3223749823, "_x_x_x_x_bach_float64_x_x_x_x_", 2194117319, 1075256976, "_x_x_x_x_bach_float64_x_x_x_x_", 3884289394, 3223742029, "_x_x_x_x_bach_float64_x_x_x_x_", 2966569319, 1075295488, "_x_x_x_x_bach_float64_x_x_x_x_", 2430018408, 3223733983, "_x_x_x_x_bach_float64_x_x_x_x_", 2118892050, 1075333835, "_x_x_x_x_bach_float64_x_x_x_x_", 3521301390, 3223725684, "_x_x_x_x_bach_float64_x_x_x_x_", 1315886448, 1075372010, "_x_x_x_x_bach_float64_x_x_x_x_", 2041868102, 3223717134, "_x_x_x_x_bach_float64_x_x_x_x_", 2284928706, 1075410006, "_x_x_x_x_bach_float64_x_x_x_x_", 1651254170, 3223708333, "_x_x_x_x_bach_float64_x_x_x_x_", 2525865628, 1075447817, "_x_x_x_x_bach_float64_x_x_x_x_", 1899660514, 3223699282, "_x_x_x_x_bach_float64_x_x_x_x_", 3905809737, 1075485436, "_x_x_x_x_bach_float64_x_x_x_x_", 2522650199, 3223689982, "_x_x_x_x_bach_float64_x_x_x_x_", 4074062110, 1075522857, "_x_x_x_x_bach_float64_x_x_x_x_", 3440846194, 3223680434, "_x_x_x_x_bach_float64_x_x_x_x_", 761933543, 1075560074, "_x_x_x_x_bach_float64_x_x_x_x_", 464630013, 3223670640, "_x_x_x_x_bach_float64_x_x_x_x_", 377528132, 1075597079, "_x_x_x_x_bach_float64_x_x_x_x_", 2473645071, 3223660599, "_x_x_x_x_bach_float64_x_x_x_x_", 830717745, 1075633866, "_x_x_x_x_bach_float64_x_x_x_x_", 1351627971, 3223650314, "_x_x_x_x_bach_float64_x_x_x_x_", 127913971, 1075670429, "_x_x_x_x_bach_float64_x_x_x_x_", 2050750162, 3223639785, "_x_x_x_x_bach_float64_x_x_x_x_", 671865524, 1075706761, "_x_x_x_x_bach_float64_x_x_x_x_", 1116320301, 3223629014, "_x_x_x_x_bach_float64_x_x_x_x_", 676546019, 1075742856, "_x_x_x_x_bach_float64_x_x_x_x_", 3866160473, 3223618001, "_x_x_x_x_bach_float64_x_x_x_x_", 2761901919, 1075778707, "_x_x_x_x_bach_float64_x_x_x_x_", 2915245104, 3223606749, "_x_x_x_x_bach_float64_x_x_x_x_", 1073754481, 1075814309, "_x_x_x_x_bach_float64_x_x_x_x_", 3944948411, 3223595258, "_x_x_x_x_bach_float64_x_x_x_x_", 1381714796, 1075844315, "_x_x_x_x_bach_float64_x_x_x_x_", 4227619943, 3223583530, "_x_x_x_x_bach_float64_x_x_x_x_", 3258851636, 1075861856, "_x_x_x_x_bach_float64_x_x_x_x_", 1215899651, 3223571567, "_x_x_x_x_bach_float64_x_x_x_x_", 3429269499, 1075879263, "_x_x_x_x_bach_float64_x_x_x_x_", 1132001309, 3223559369, "_x_x_x_x_bach_float64_x_x_x_x_", 1368889594, 1075896533, "_x_x_x_x_bach_float64_x_x_x_x_", 1787160760, 3223546938, "_x_x_x_x_bach_float64_x_x_x_x_", 918427843, 1075913662, "_x_x_x_x_bach_float64_x_x_x_x_", 1170856444, 3223534276, "_x_x_x_x_bach_float64_x_x_x_x_", 1695824572, 1075930647, "_x_x_x_x_bach_float64_x_x_x_x_", 1745031274, 3223521384, "_x_x_x_x_bach_float64_x_x_x_x_", 3393568321, 1075947485, "_x_x_x_x_bach_float64_x_x_x_x_", 1853381361, 3223508264, "_x_x_x_x_bach_float64_x_x_x_x_", 1486077019, 1075964174, "_x_x_x_x_bach_float64_x_x_x_x_", 15515324, 3223494918, "_x_x_x_x_bach_float64_x_x_x_x_", 116939701, 1075980710, "_x_x_x_x_bach_float64_x_x_x_x_", 3516049834, 3223481346, "_x_x_x_x_bach_float64_x_x_x_x_", 3511312819, 1075997089, "_x_x_x_x_bach_float64_x_x_x_x_", 2633935699, 3223467552, "_x_x_x_x_bach_float64_x_x_x_x_", 3093339891, 1076013310, "_x_x_x_x_bach_float64_x_x_x_x_", 706327839, 3223453537, "_x_x_x_x_bach_float64_x_x_x_x_", 3258266987, 1076029369, "_x_x_x_x_bach_float64_x_x_x_x_", 1242751478, 3223439302, "_x_x_x_x_bach_float64_x_x_x_x_", 4194875143, 1076045263, "_x_x_x_x_bach_float64_x_x_x_x_", 3629172090, 3223424849, "_x_x_x_x_bach_float64_x_x_x_x_", 1887771273, 1076060990, "_x_x_x_x_bach_float64_x_x_x_x_", 3127002072, 3223410181, "_x_x_x_x_bach_float64_x_x_x_x_", 1004570001, 1076076546, "_x_x_x_x_bach_float64_x_x_x_x_", 3756978738, 3223395299, "_x_x_x_x_bach_float64_x_x_x_x_", 2013260308, 1076091928, "_x_x_x_x_bach_float64_x_x_x_x_", 1118240813, 3223380206, "_x_x_x_x_bach_float64_x_x_x_x_", 1184462193, 1076107134, "_x_x_x_x_bach_float64_x_x_x_x_", 3862080364, 3223364902, "_x_x_x_x_bach_float64_x_x_x_x_", 3478573101, 1076122160, "_x_x_x_x_bach_float64_x_x_x_x_", 3626056923, 3223349391, "_x_x_x_x_bach_float64_x_x_x_x_", 1073163259, 1076137005, "_x_x_x_x_bach_float64_x_x_x_x_", 802656523, 3223333675, "_x_x_x_x_bach_float64_x_x_x_x_", 3429965587, 1076151664, "_x_x_x_x_bach_float64_x_x_x_x_", 486299500, 3223312886, "_x_x_x_x_bach_float64_x_x_x_x_", 2937342744, 1076166136, "_x_x_x_x_bach_float64_x_x_x_x_", 1037938212, 3223280643, "_x_x_x_x_bach_float64_x_x_x_x_", 682282451, 1076180418, "_x_x_x_x_bach_float64_x_x_x_x_", 725852055, 3223248002, "_x_x_x_x_bach_float64_x_x_x_x_", 2157607627, 1076194506, "_x_x_x_x_bach_float64_x_x_x_x_", 1630862183, 3223214967, "_x_x_x_x_bach_float64_x_x_x_x_", 84269917, 1076208399, "_x_x_x_x_bach_float64_x_x_x_x_", 1856468220, 3223181543, "_x_x_x_x_bach_float64_x_x_x_x_", 183301236, 1076222093, "_x_x_x_x_bach_float64_x_x_x_x_", 4116139357, 3223147734, "_x_x_x_x_bach_float64_x_x_x_x_", 3998076964, 1076235585, "_x_x_x_x_bach_float64_x_x_x_x_", 2845711124, 3223113546, "_x_x_x_x_bach_float64_x_x_x_x_", 306497895, 1076248875, "_x_x_x_x_bach_float64_x_x_x_x_", 1380495852, 3223078983, "_x_x_x_x_bach_float64_x_x_x_x_", 3777796380, 1076261957, "_x_x_x_x_bach_float64_x_x_x_x_", 3362532055, 3223044049, "_x_x_x_x_bach_float64_x_x_x_x_", 3435012607, 1076274831, "_x_x_x_x_bach_float64_x_x_x_x_", 4147777264, 3223008750, "_x_x_x_x_bach_float64_x_x_x_x_", 1311767208, 1076287494, "_x_x_x_x_bach_float64_x_x_x_x_", 3688080895, 3222973091, "_x_x_x_x_bach_float64_x_x_x_x_", 3864376315, 1076299942, "_x_x_x_x_bach_float64_x_x_x_x_", 2233231982, 3222937077, "_x_x_x_x_bach_float64_x_x_x_x_", 499046979, 1076312175, "_x_x_x_x_bach_float64_x_x_x_x_", 327918770, 3222900713, "_x_x_x_x_bach_float64_x_x_x_x_", 2228596765, 1076324188, "_x_x_x_x_bach_float64_x_x_x_x_", 3103600264, 3222864003, "_x_x_x_x_bach_float64_x_x_x_x_", 3019743507, 1076335980, "_x_x_x_x_bach_float64_x_x_x_x_", 3095486809, 3222826954, "_x_x_x_x_bach_float64_x_x_x_x_", 1269918431, 1076347549, "_x_x_x_x_bach_float64_x_x_x_x_", 1714171990, 3222789571, "_x_x_x_x_bach_float64_x_x_x_x_", 4104190937, 1076358891, "_x_x_x_x_bach_float64_x_x_x_x_", 652439620, 3222751859, "_x_x_x_x_bach_float64_x_x_x_x_", 1607402728, 1076370006, "_x_x_x_x_bach_float64_x_x_x_x_", 1881952105, 3222713823, "_x_x_x_x_bach_float64_x_x_x_x_", 1185824269, 1076380890, "_x_x_x_x_bach_float64_x_x_x_x_", 3354918389, 3222675469, "_x_x_x_x_bach_float64_x_x_x_x_", 1799248762, 1076391541, "_x_x_x_x_bach_float64_x_x_x_x_", 3295644322, 3222636803, "_x_x_x_x_bach_float64_x_x_x_x_", 2552803930, 1076401957, "_x_x_x_x_bach_float64_x_x_x_x_", 197063692, 3222597831, "_x_x_x_x_bach_float64_x_x_x_x_", 2698808230, 1076412136, "_x_x_x_x_bach_float64_x_x_x_x_", 1407152427, 3222558557, "_x_x_x_x_bach_float64_x_x_x_x_", 1638605731, 1076422076, "_x_x_x_x_bach_float64_x_x_x_x_", 1650520937, 3222518988, "_x_x_x_x_bach_float64_x_x_x_x_", 3219346685, 1076431774, "_x_x_x_x_bach_float64_x_x_x_x_", 204661474, 3222479130, "_x_x_x_x_bach_float64_x_x_x_x_", 2850876850, 1076441229, "_x_x_x_x_bach_float64_x_x_x_x_", 896276680, 3222438988, "_x_x_x_x_bach_float64_x_x_x_x_", 392408280, 1076450439, "_x_x_x_x_bach_float64_x_x_x_x_", 3507624054, 3222398568, "_x_x_x_x_bach_float64_x_x_x_x_", 154265511, 1076459401, "_x_x_x_x_bach_float64_x_x_x_x_", 3772746369, 3222357877, "_x_x_x_x_bach_float64_x_x_x_x_", 2309674195, 1076468113, "_x_x_x_x_bach_float64_x_x_x_x_", 1963588193, 3222316921, "_x_x_x_x_bach_float64_x_x_x_x_", 2896460916, 1076476574, "_x_x_x_x_bach_float64_x_x_x_x_", 2886130380, 3222275705, "_x_x_x_x_bach_float64_x_x_x_x_", 2408663973, 1076484782, "_x_x_x_x_bach_float64_x_x_x_x_", 1688183607, 3222194425, "_x_x_x_x_bach_float64_x_x_x_x_", 1503218249, 1076492735, "_x_x_x_x_bach_float64_x_x_x_x_", 2219613139, 3222110993, "_x_x_x_x_bach_float64_x_x_x_x_", 1001583056, 1076500431, "_x_x_x_x_bach_float64_x_x_x_x_", 1185732217, 3222027080, "_x_x_x_x_bach_float64_x_x_x_x_", 1891345380, 1076507868, "_x_x_x_x_bach_float64_x_x_x_x_", 1441940796, 3221942698, "_x_x_x_x_bach_float64_x_x_x_x_", 1032830844, 1076515045, "_x_x_x_x_bach_float64_x_x_x_x_", 1986763728, 3221857860, "_x_x_x_x_bach_float64_x_x_x_x_", 4045558616, 1076521959, "_x_x_x_x_bach_float64_x_x_x_x_", 2248539273, 3221772579, "_x_x_x_x_bach_float64_x_x_x_x_", 3834932391, 1076528610, "_x_x_x_x_bach_float64_x_x_x_x_", 2077053318, 3221686868, "_x_x_x_x_bach_float64_x_x_x_x_", 2068578448, 1076534996, "_x_x_x_x_bach_float64_x_x_x_x_", 1735088120, 3221600740, "_x_x_x_x_bach_float64_x_x_x_x_", 587886515, 1076541115, "_x_x_x_x_bach_float64_x_x_x_x_", 1889886096, 3221514208, "_x_x_x_x_bach_float64_x_x_x_x_", 1409458728, 1076546965, "_x_x_x_x_bach_float64_x_x_x_x_", 3604530971, 3221427285, "_x_x_x_x_bach_float64_x_x_x_x_", 2431564578, 1076552545, "_x_x_x_x_bach_float64_x_x_x_x_", 4034279541, 3221339985, "_x_x_x_x_bach_float64_x_x_x_x_", 1730503413, 1076557854, "_x_x_x_x_bach_float64_x_x_x_x_", 712747521, 3221252322, "_x_x_x_x_bach_float64_x_x_x_x_", 1856939615, 1076562890, "_x_x_x_x_bach_float64_x_x_x_x_", 265967554, 3221103144, "_x_x_x_x_bach_float64_x_x_x_x_", 1247308334, 1076567652, "_x_x_x_x_bach_float64_x_x_x_x_", 1117324939, 3220926442, "_x_x_x_x_bach_float64_x_x_x_x_", 2815062511, 1076572138, "_x_x_x_x_bach_float64_x_x_x_x_", 1210006108, 3220749094, "_x_x_x_x_bach_float64_x_x_x_x_", 1067055313, 1076576348, "_x_x_x_x_bach_float64_x_x_x_x_", 2754328114, 3220571127, "_x_x_x_x_bach_float64_x_x_x_x_", 3579632536, 1076580279, "_x_x_x_x_bach_float64_x_x_x_x_", 37257222, 3220392570, "_x_x_x_x_bach_float64_x_x_x_x_", 935088786, 1076583932, "_x_x_x_x_bach_float64_x_x_x_x_", 878774496, 3220213449, "_x_x_x_x_bach_float64_x_x_x_x_", 1082604230, 1076587304, "_x_x_x_x_bach_float64_x_x_x_x_", 1686916942, 3219890690, "_x_x_x_x_bach_float64_x_x_x_x_", 3569610004, 1076590394, "_x_x_x_x_bach_float64_x_x_x_x_", 803206484, 3219530364, "_x_x_x_x_bach_float64_x_x_x_x_", 3837895301, 1076593202, "_x_x_x_x_bach_float64_x_x_x_x_", 1230727573, 3219169080, "_x_x_x_x_bach_float64_x_x_x_x_", 1814652112, 1076595727, "_x_x_x_x_bach_float64_x_x_x_x_", 3889008701, 3218485470, "_x_x_x_x_bach_float64_x_x_x_x_", 1913555479, 1076597967, "_x_x_x_x_bach_float64_x_x_x_x_", 3517840105, 3217439082, "_x_x_x_x_bach_float64_x_x_x_x_", 150911754, 1076599922, "_x_x_x_x_bach_float64_x_x_x_x_", 2148836465, 3206755576 ],
									"whole_graph_data_count" : [ 2 ]
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
									"patching_rect" : [ 10.0, 10.0, 236.360000610351562, 57.599853515625 ]
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
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
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
					"patching_rect" : [ 10.0, 147.0, 47.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"parameter_enable" : 0,
									"patching_rect" : [ 49.0, 203.0, 35.0, 35.0 ]
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
									"patching_rect" : [ 327.0, 175.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 267.0, 175.0, 50.0, 23.0 ]
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
									"versionnumber" : 80104,
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
									"patching_rect" : [ 10.0, 10.0, 236.360000610351562, 57.599853515625 ]
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
					"patching_rect" : [ 10.0, 116.0, 81.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"maxtheta" : 520.566406000000029,
									"maxx" : 4.0,
									"maxy" : 4.0,
									"minx" : -4.0,
									"miny" : -1.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 284.0, 326.0, 199.0, 189.724579000000006 ],
									"showlabels" : 0,
									"versionnumber" : 80104,
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
									"maxtheta" : 520.566406000000029,
									"maxx" : 10.0,
									"maxy" : 10.0,
									"minx" : -10.0,
									"miny" : -10.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 326.0, 199.0, 189.724579000000006 ],
									"showlabels" : 0,
									"versionnumber" : 80104,
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
									"patching_rect" : [ 284.0, 98.0, 199.0, 189.724579000000006 ],
									"showlabels" : 0,
									"showxyaxis" : 0,
									"versionnumber" : 80104,
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
									"maxtheta" : 520.566406000000029,
									"maxx" : 500.0,
									"maxy" : 500.0,
									"minx" : -500.0,
									"miny" : -500.0,
									"numinlets" : 2,
									"numoutlets" : 3,
									"out" : "nn",
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 10.0, 98.0, 199.0, 189.724579000000006 ],
									"showlabels" : 0,
									"showxyaxis" : 0,
									"versionnumber" : 80104,
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
									"patching_rect" : [ 10.0, 10.0, 236.380599999999987, 57.567627000000002 ]
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
					"patching_rect" : [ 10.0, 335.0, 37.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
					"patching_rect" : [ 294.0, 205.0, 154.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
									"patching_rect" : [ 516.0, 315.5, 248.0, 54.0 ],
									"presentation_linecount" : 3,
									"text" : "\"expr\" is an alias of \"expry\" for cartesian graphs and of \"exprr\" for polar graphs (see \"polar\" tab)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 311.0, 331.0, 198.0, 23.0 ],
									"text" : "expr \"-pow($f1, 3) +4*cos($f1-2)\""
								}

							}
, 							{
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
									"patching_rect" : [ 560.5, 439.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 500.5, 439.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 371.0, 439.0, 50.0, 23.0 ]
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
									"patching_rect" : [ 311.0, 439.0, 50.0, 23.0 ]
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
									"text" : "You can add the \"bang\" at the end of the message to plot immediately"
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
									"patching_rect" : [ 307.5, 292.0, 168.0, 23.0 ],
									"text" : "expry sin($f1*30)/$f1, bang"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 307.5, 266.0, 150.0, 23.0 ],
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
									"text" : "The syntax for the formula is exactly like the one in bach.expr, $f1 always being the free variable",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
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
									"patching_rect" : [ 307.5, 237.0, 101.0, 23.0 ],
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
									"patching_rect" : [ 236.0, 138.0, 248.0, 25.0 ],
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
									"parameter_enable" : 0,
									"patching_rect" : [ 49.0, 196.0, 35.0, 35.0 ]
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
									"patching_rect" : [ 26.0, 141.0, 205.0, 23.0 ],
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
									"versionnumber" : 80104,
									"whole_graph_data_0000000000" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3222536192, "_x_x_x_x_bach_float64_x_x_x_x_", 3732628608, 1080033407, "_x_x_x_x_bach_float64_x_x_x_x_", 4019814236, 3222533567, "_x_x_x_x_bach_float64_x_x_x_x_", 2395955977, 1080021688, "_x_x_x_x_bach_float64_x_x_x_x_", 3744661176, 3222530943, "_x_x_x_x_bach_float64_x_x_x_x_", 2301458189, 1080009885, "_x_x_x_x_bach_float64_x_x_x_x_", 3469508116, 3222528319, "_x_x_x_x_bach_float64_x_x_x_x_", 2281052648, 1079998126, "_x_x_x_x_bach_float64_x_x_x_x_", 3194355056, 3222525695, "_x_x_x_x_bach_float64_x_x_x_x_", 1731162704, 1079986411, "_x_x_x_x_bach_float64_x_x_x_x_", 2919201996, 3222523071, "_x_x_x_x_bach_float64_x_x_x_x_", 50397011, 1079974740, "_x_x_x_x_bach_float64_x_x_x_x_", 2644048936, 3222520447, "_x_x_x_x_bach_float64_x_x_x_x_", 934534656, 1079963112, "_x_x_x_x_bach_float64_x_x_x_x_", 2368895876, 3222517823, "_x_x_x_x_bach_float64_x_x_x_x_", 3786608163, 1079951527, "_x_x_x_x_bach_float64_x_x_x_x_", 2093742816, 3222515199, "_x_x_x_x_bach_float64_x_x_x_x_", 3716920887, 1079939986, "_x_x_x_x_bach_float64_x_x_x_x_", 1818589756, 3222512575, "_x_x_x_x_bach_float64_x_x_x_x_", 132998753, 1079928489, "_x_x_x_x_bach_float64_x_x_x_x_", 1543436696, 3222509951, "_x_x_x_x_bach_float64_x_x_x_x_", 1034574496, 1079917034, "_x_x_x_x_bach_float64_x_x_x_x_", 1268283636, 3222507327, "_x_x_x_x_bach_float64_x_x_x_x_", 1538767880, 1079905622, "_x_x_x_x_bach_float64_x_x_x_x_", 993130576, 3222504703, "_x_x_x_x_bach_float64_x_x_x_x_", 1059971359, 1079894253, "_x_x_x_x_bach_float64_x_x_x_x_", 717977516, 3222502079, "_x_x_x_x_bach_float64_x_x_x_x_", 3309866322, 1079882926, "_x_x_x_x_bach_float64_x_x_x_x_", 442824456, 3222499455, "_x_x_x_x_bach_float64_x_x_x_x_", 3412537219, 1079871642, "_x_x_x_x_bach_float64_x_x_x_x_", 167671396, 3222496831, "_x_x_x_x_bach_float64_x_x_x_x_", 789389224, 1079860401, "_x_x_x_x_bach_float64_x_x_x_x_", 4187485632, 3222494206, "_x_x_x_x_bach_float64_x_x_x_x_", 3454131078, 1079849201, "_x_x_x_x_bach_float64_x_x_x_x_", 3912332572, 3222491582, "_x_x_x_x_bach_float64_x_x_x_x_", 2242986611, 1079838044, "_x_x_x_x_bach_float64_x_x_x_x_", 3637179512, 3222488958, "_x_x_x_x_bach_float64_x_x_x_x_", 879480885, 1079826929, "_x_x_x_x_bach_float64_x_x_x_x_", 3362026452, 3222486334, "_x_x_x_x_bach_float64_x_x_x_x_", 3089553133, 1079815855, "_x_x_x_x_bach_float64_x_x_x_x_", 3086873392, 3222483710, "_x_x_x_x_bach_float64_x_x_x_x_", 4011636744, 1079804823, "_x_x_x_x_bach_float64_x_x_x_x_", 2811720332, 3222481086, "_x_x_x_x_bach_float64_x_x_x_x_", 3081575500, 1079793833, "_x_x_x_x_bach_float64_x_x_x_x_", 2536567272, 3222478462, "_x_x_x_x_bach_float64_x_x_x_x_", 4032637663, 1079782884, "_x_x_x_x_bach_float64_x_x_x_x_", 2261414212, 3222475838, "_x_x_x_x_bach_float64_x_x_x_x_", 2010627941, 1079771977, "_x_x_x_x_bach_float64_x_x_x_x_", 1986261152, 3222473214, "_x_x_x_x_bach_float64_x_x_x_x_", 753770275, 1079761111, "_x_x_x_x_bach_float64_x_x_x_x_", 1711108092, 3222470590, "_x_x_x_x_bach_float64_x_x_x_x_", 4002786596, 1079750285, "_x_x_x_x_bach_float64_x_x_x_x_", 1435955032, 3222467966, "_x_x_x_x_bach_float64_x_x_x_x_", 2616008041, 1079739501, "_x_x_x_x_bach_float64_x_x_x_x_", 1160801972, 3222465342, "_x_x_x_x_bach_float64_x_x_x_x_", 339191581, 1079728758, "_x_x_x_x_bach_float64_x_x_x_x_", 885648912, 3222462718, "_x_x_x_x_bach_float64_x_x_x_x_", 920630728, 1079718055, "_x_x_x_x_bach_float64_x_x_x_x_", 610495852, 3222460094, "_x_x_x_x_bach_float64_x_x_x_x_", 3816200588, 1079707392, "_x_x_x_x_bach_float64_x_x_x_x_", 335342792, 3222457470, "_x_x_x_x_bach_float64_x_x_x_x_", 4189369943, 1079696770, "_x_x_x_x_bach_float64_x_x_x_x_", 60189732, 3222454846, "_x_x_x_x_bach_float64_x_x_x_x_", 1501147681, 1079686189, "_x_x_x_x_bach_float64_x_x_x_x_", 4080003968, 3222452221, "_x_x_x_x_bach_float64_x_x_x_x_", 3805061659, 1079675647, "_x_x_x_x_bach_float64_x_x_x_x_", 3804850908, 3222449597, "_x_x_x_x_bach_float64_x_x_x_x_", 1977366248, 1079665146, "_x_x_x_x_bach_float64_x_x_x_x_", 3529697848, 3222446973, "_x_x_x_x_bach_float64_x_x_x_x_", 4076791754, 1079654684, "_x_x_x_x_bach_float64_x_x_x_x_", 3254544788, 3222444349, "_x_x_x_x_bach_float64_x_x_x_x_", 984816845, 1079644263, "_x_x_x_x_bach_float64_x_x_x_x_", 2979391728, 3222441725, "_x_x_x_x_bach_float64_x_x_x_x_", 765417446, 1079633881, "_x_x_x_x_bach_float64_x_x_x_x_", 2704238668, 3222439101, "_x_x_x_x_bach_float64_x_x_x_x_", 2895273236, 1079623538, "_x_x_x_x_bach_float64_x_x_x_x_", 2429085608, 3222436477, "_x_x_x_x_bach_float64_x_x_x_x_", 2558744946, 1079613235, "_x_x_x_x_bach_float64_x_x_x_x_", 2153932548, 3222433853, "_x_x_x_x_bach_float64_x_x_x_x_", 3532785985, 1079602971, "_x_x_x_x_bach_float64_x_x_x_x_", 1878779488, 3222431229, "_x_x_x_x_bach_float64_x_x_x_x_", 1007082729, 1079592747, "_x_x_x_x_bach_float64_x_x_x_x_", 1603626428, 3222428605, "_x_x_x_x_bach_float64_x_x_x_x_", 3058900204, 1079582561, "_x_x_x_x_bach_float64_x_x_x_x_", 1328473368, 3222425981, "_x_x_x_x_bach_float64_x_x_x_x_", 588319955, 1079572415, "_x_x_x_x_bach_float64_x_x_x_x_", 1053320308, 3222423357, "_x_x_x_x_bach_float64_x_x_x_x_", 1677987075, 1079562307, "_x_x_x_x_bach_float64_x_x_x_x_", 778167248, 3222420733, "_x_x_x_x_bach_float64_x_x_x_x_", 1528347535, 1079552238, "_x_x_x_x_bach_float64_x_x_x_x_", 503014188, 3222418109, "_x_x_x_x_bach_float64_x_x_x_x_", 3932492789, 1079542207, "_x_x_x_x_bach_float64_x_x_x_x_", 227861128, 3222415485, "_x_x_x_x_bach_float64_x_x_x_x_", 4096298448, 1079532215, "_x_x_x_x_bach_float64_x_x_x_x_", 4247675364, 3222412860, "_x_x_x_x_bach_float64_x_x_x_x_", 1523333746, 1079522262, "_x_x_x_x_bach_float64_x_x_x_x_", 3972522304, 3222410236, "_x_x_x_x_bach_float64_x_x_x_x_", 14868853, 1079512347, "_x_x_x_x_bach_float64_x_x_x_x_", 3697369244, 3222407612, "_x_x_x_x_bach_float64_x_x_x_x_", 3374914611, 1079502469, "_x_x_x_x_bach_float64_x_x_x_x_", 3422216184, 3222404988, "_x_x_x_x_bach_float64_x_x_x_x_", 2525327411, 1079492630, "_x_x_x_x_bach_float64_x_x_x_x_", 3147063124, 3222402364, "_x_x_x_x_bach_float64_x_x_x_x_", 1275619453, 1079482829, "_x_x_x_x_bach_float64_x_x_x_x_", 2871910064, 3222399740, "_x_x_x_x_bach_float64_x_x_x_x_", 3438063069, 1079473065, "_x_x_x_x_bach_float64_x_x_x_x_", 2596757004, 3222397116, "_x_x_x_x_bach_float64_x_x_x_x_", 4237762059, 1079463339, "_x_x_x_x_bach_float64_x_x_x_x_", 2321603944, 3222394492, "_x_x_x_x_bach_float64_x_x_x_x_", 3197559241, 1079453651, "_x_x_x_x_bach_float64_x_x_x_x_", 2046450884, 3222391868, "_x_x_x_x_bach_float64_x_x_x_x_", 4138041825, 1079444000, "_x_x_x_x_bach_float64_x_x_x_x_", 1771297824, 3222389244, "_x_x_x_x_bach_float64_x_x_x_x_", 2292644632, 1079434387, "_x_x_x_x_bach_float64_x_x_x_x_", 1496144764, 3222386620, "_x_x_x_x_bach_float64_x_x_x_x_", 1487524088, 1079424811, "_x_x_x_x_bach_float64_x_x_x_x_", 1220991704, 3222383996, "_x_x_x_x_bach_float64_x_x_x_x_", 1256660887, 1079415272, "_x_x_x_x_bach_float64_x_x_x_x_", 945838644, 3222381372, "_x_x_x_x_bach_float64_x_x_x_x_", 1136831548, 1079405770, "_x_x_x_x_bach_float64_x_x_x_x_", 670685584, 3222378748, "_x_x_x_x_bach_float64_x_x_x_x_", 667612393, 1079396305, "_x_x_x_x_bach_float64_x_x_x_x_", 395532524, 3222376124, "_x_x_x_x_bach_float64_x_x_x_x_", 3686350546, 1079386876, "_x_x_x_x_bach_float64_x_x_x_x_", 120379464, 3222373500, "_x_x_x_x_bach_float64_x_x_x_x_", 1148298175, 1079377485, "_x_x_x_x_bach_float64_x_x_x_x_", 4140193700, 3222370875, "_x_x_x_x_bach_float64_x_x_x_x_", 1191386696, 1079368130, "_x_x_x_x_bach_float64_x_x_x_x_", 3865040640, 3222368251, "_x_x_x_x_bach_float64_x_x_x_x_", 3366425858, 1079358811, "_x_x_x_x_bach_float64_x_x_x_x_", 3589887580, 3222365627, "_x_x_x_x_bach_float64_x_x_x_x_", 2932073616, 1079349529, "_x_x_x_x_bach_float64_x_x_x_x_", 3314734520, 3222363003, "_x_x_x_x_bach_float64_x_x_x_x_", 3739740312, 1079340283, "_x_x_x_x_bach_float64_x_x_x_x_", 3039581460, 3222360379, "_x_x_x_x_bach_float64_x_x_x_x_", 1053721502, 1079331074, "_x_x_x_x_bach_float64_x_x_x_x_", 2764428400, 3222357755, "_x_x_x_x_bach_float64_x_x_x_x_", 3026036164, 1079321900, "_x_x_x_x_bach_float64_x_x_x_x_", 2489275340, 3222355131, "_x_x_x_x_bach_float64_x_x_x_x_", 631657077, 1079312763, "_x_x_x_x_bach_float64_x_x_x_x_", 2214122280, 3222352507, "_x_x_x_x_bach_float64_x_x_x_x_", 2028250344, 1079303661, "_x_x_x_x_bach_float64_x_x_x_x_", 1938969220, 3222349883, "_x_x_x_x_bach_float64_x_x_x_x_", 2491405212, 1079294595, "_x_x_x_x_bach_float64_x_x_x_x_", 1663816160, 3222347259, "_x_x_x_x_bach_float64_x_x_x_x_", 1594503841, 1079285565, "_x_x_x_x_bach_float64_x_x_x_x_", 1388663100, 3222344635, "_x_x_x_x_bach_float64_x_x_x_x_", 3208721627, 1079276570, "_x_x_x_x_bach_float64_x_x_x_x_", 1113510040, 3222342011, "_x_x_x_x_bach_float64_x_x_x_x_", 2618125344, 1079267611, "_x_x_x_x_bach_float64_x_x_x_x_", 838356980, 3222339387, "_x_x_x_x_bach_float64_x_x_x_x_", 3699542069, 1079258687, "_x_x_x_x_bach_float64_x_x_x_x_", 563203920, 3222336763, "_x_x_x_x_bach_float64_x_x_x_x_", 1742689472, 1079249799, "_x_x_x_x_bach_float64_x_x_x_x_", 288050860, 3222334139, "_x_x_x_x_bach_float64_x_x_x_x_", 630044176, 1079240946, "_x_x_x_x_bach_float64_x_x_x_x_", 12897800, 3222331515, "_x_x_x_x_bach_float64_x_x_x_x_", 4246906068, 1079232127, "_x_x_x_x_bach_float64_x_x_x_x_", 4032712036, 3222328890, "_x_x_x_x_bach_float64_x_x_x_x_", 3596495020, 1079223344, "_x_x_x_x_bach_float64_x_x_x_x_", 3757558976, 3222326266, "_x_x_x_x_bach_float64_x_x_x_x_", 2569753004, 1079214596, "_x_x_x_x_bach_float64_x_x_x_x_", 3482405916, 3222323642, "_x_x_x_x_bach_float64_x_x_x_x_", 765472957, 1079205883, "_x_x_x_x_bach_float64_x_x_x_x_", 3207252856, 3222321018, "_x_x_x_x_bach_float64_x_x_x_x_", 2080231143, 1079197204, "_x_x_x_x_bach_float64_x_x_x_x_", 2932099796, 3222318394, "_x_x_x_x_bach_float64_x_x_x_x_", 1823482745, 1079188560, "_x_x_x_x_bach_float64_x_x_x_x_", 2656946736, 3222315770, "_x_x_x_x_bach_float64_x_x_x_x_", 3897428259, 1079179950, "_x_x_x_x_bach_float64_x_x_x_x_", 2381793676, 3222313146, "_x_x_x_x_bach_float64_x_x_x_x_", 3617141229, 1079171375, "_x_x_x_x_bach_float64_x_x_x_x_", 2106640616, 3222310522, "_x_x_x_x_bach_float64_x_x_x_x_", 595466779, 1079162835, "_x_x_x_x_bach_float64_x_x_x_x_", 1831487556, 3222307898, "_x_x_x_x_bach_float64_x_x_x_x_", 3037985264, 1079154328, "_x_x_x_x_bach_float64_x_x_x_x_", 1556334496, 3222305274, "_x_x_x_x_bach_float64_x_x_x_x_", 1973204582, 1079145856, "_x_x_x_x_bach_float64_x_x_x_x_", 1281181436, 3222302650, "_x_x_x_x_bach_float64_x_x_x_x_", 1317327034, 1079137418, "_x_x_x_x_bach_float64_x_x_x_x_", 1006028376, 3222300026, "_x_x_x_x_bach_float64_x_x_x_x_", 694375672, 1079129014, "_x_x_x_x_bach_float64_x_x_x_x_", 730875316, 3222297402, "_x_x_x_x_bach_float64_x_x_x_x_", 4026124117, 1079120643, "_x_x_x_x_bach_float64_x_x_x_x_", 455722256, 3222294778, "_x_x_x_x_bach_float64_x_x_x_x_", 2352222350, 1079112307, "_x_x_x_x_bach_float64_x_x_x_x_", 180569196, 3222292154, "_x_x_x_x_bach_float64_x_x_x_x_", 3894962457, 1079104004, "_x_x_x_x_bach_float64_x_x_x_x_", 4200383432, 3222289529, "_x_x_x_x_bach_float64_x_x_x_x_", 3994501968, 1079095735, "_x_x_x_x_bach_float64_x_x_x_x_", 3925230372, 3222286905, "_x_x_x_x_bach_float64_x_x_x_x_", 2288727162, 1079087500, "_x_x_x_x_bach_float64_x_x_x_x_", 3650077312, 3222284281, "_x_x_x_x_bach_float64_x_x_x_x_", 2713246926, 1079079298, "_x_x_x_x_bach_float64_x_x_x_x_", 3374924252, 3222281657, "_x_x_x_x_bach_float64_x_x_x_x_", 616484436, 1079071130, "_x_x_x_x_bach_float64_x_x_x_x_", 3099771192, 3222279033, "_x_x_x_x_bach_float64_x_x_x_x_", 4234506939, 1079062994, "_x_x_x_x_bach_float64_x_x_x_x_", 2824618132, 3222276409, "_x_x_x_x_bach_float64_x_x_x_x_", 331280409, 1079054893, "_x_x_x_x_bach_float64_x_x_x_x_", 803962847, 3222273523, "_x_x_x_x_bach_float64_x_x_x_x_", 1443302551, 1079046824, "_x_x_x_x_bach_float64_x_x_x_x_", 253656727, 3222268275, "_x_x_x_x_bach_float64_x_x_x_x_", 2929922327, 1079038788, "_x_x_x_x_bach_float64_x_x_x_x_", 3998317903, 3222263026, "_x_x_x_x_bach_float64_x_x_x_x_", 153201334, 1079030786, "_x_x_x_x_bach_float64_x_x_x_x_", 3448011784, 3222257778, "_x_x_x_x_bach_float64_x_x_x_x_", 1362807632, 1079022816, "_x_x_x_x_bach_float64_x_x_x_x_", 2897705663, 3222252530, "_x_x_x_x_bach_float64_x_x_x_x_", 1926203620, 1079014879, "_x_x_x_x_bach_float64_x_x_x_x_", 2347399543, 3222247282, "_x_x_x_x_bach_float64_x_x_x_x_", 1508506632, 1079006975, "_x_x_x_x_bach_float64_x_x_x_x_", 1797093423, 3222242034, "_x_x_x_x_bach_float64_x_x_x_x_", 4072480036, 1078999103, "_x_x_x_x_bach_float64_x_x_x_x_", 1246787303, 3222236786, "_x_x_x_x_bach_float64_x_x_x_x_", 698654920, 1078991265, "_x_x_x_x_bach_float64_x_x_x_x_", 696481183, 3222231538, "_x_x_x_x_bach_float64_x_x_x_x_", 3595150781, 1078982213, "_x_x_x_x_bach_float64_x_x_x_x_", 146175063, 3222226290, "_x_x_x_x_bach_float64_x_x_x_x_", 1205133761, 1078966666, "_x_x_x_x_bach_float64_x_x_x_x_", 3890836239, 3222221041, "_x_x_x_x_bach_float64_x_x_x_x_", 2174027251, 1078951183, "_x_x_x_x_bach_float64_x_x_x_x_", 3340530119, 3222215793, "_x_x_x_x_bach_float64_x_x_x_x_", 1568958542, 1078935765, "_x_x_x_x_bach_float64_x_x_x_x_", 2790223999, 3222210545, "_x_x_x_x_bach_float64_x_x_x_x_", 3052229278, 1078920411, "_x_x_x_x_bach_float64_x_x_x_x_", 2239917879, 3222205297, "_x_x_x_x_bach_float64_x_x_x_x_", 1701424793, 1078905122, "_x_x_x_x_bach_float64_x_x_x_x_", 1689611759, 3222200049, "_x_x_x_x_bach_float64_x_x_x_x_", 1189261308, 1078889897, "_x_x_x_x_bach_float64_x_x_x_x_", 1139305639, 3222194801, "_x_x_x_x_bach_float64_x_x_x_x_", 898661523, 1078874736, "_x_x_x_x_bach_float64_x_x_x_x_", 588999519, 3222189553, "_x_x_x_x_bach_float64_x_x_x_x_", 217698876, 1078859639, "_x_x_x_x_bach_float64_x_x_x_x_", 38693399, 3222184305, "_x_x_x_x_bach_float64_x_x_x_x_", 2834541294, 1078844605, "_x_x_x_x_bach_float64_x_x_x_x_", 3783354575, 3222179056, "_x_x_x_x_bach_float64_x_x_x_x_", 3852525237, 1078829635, "_x_x_x_x_bach_float64_x_x_x_x_", 3233048455, 3222173808, "_x_x_x_x_bach_float64_x_x_x_x_", 2675033011, 1078814729, "_x_x_x_x_bach_float64_x_x_x_x_", 2682742335, 3222168560, "_x_x_x_x_bach_float64_x_x_x_x_", 3005467686, 1078799886, "_x_x_x_x_bach_float64_x_x_x_x_", 2132436215, 3222163312, "_x_x_x_x_bach_float64_x_x_x_x_", 4257292906, 1078785106, "_x_x_x_x_bach_float64_x_x_x_x_", 1582130095, 3222158064, "_x_x_x_x_bach_float64_x_x_x_x_", 1554006805, 1078770390, "_x_x_x_x_bach_float64_x_x_x_x_", 1031823975, 3222152816, "_x_x_x_x_bach_float64_x_x_x_x_", 2908984586, 1078755736, "_x_x_x_x_bach_float64_x_x_x_x_", 481517855, 3222147568, "_x_x_x_x_bach_float64_x_x_x_x_", 3455647655, 1078741145, "_x_x_x_x_bach_float64_x_x_x_x_", 4226179031, 3222142319, "_x_x_x_x_bach_float64_x_x_x_x_", 2627305215, 1078726617, "_x_x_x_x_bach_float64_x_x_x_x_", 3675872911, 3222137071, "_x_x_x_x_bach_float64_x_x_x_x_", 4157126182, 1078712151, "_x_x_x_x_bach_float64_x_x_x_x_", 3125566791, 3222131823, "_x_x_x_x_bach_float64_x_x_x_x_", 3193208720, 1078697748, "_x_x_x_x_bach_float64_x_x_x_x_", 2575260671, 3222126575, "_x_x_x_x_bach_float64_x_x_x_x_", 3478420372, 1078683407, "_x_x_x_x_bach_float64_x_x_x_x_", 2024954551, 3222121327, "_x_x_x_x_bach_float64_x_x_x_x_", 170499326, 1078669129, "_x_x_x_x_bach_float64_x_x_x_x_", 1474648431, 3222116079, "_x_x_x_x_bach_float64_x_x_x_x_", 1316860868, 1078654912, "_x_x_x_x_bach_float64_x_x_x_x_", 924342311, 3222110831, "_x_x_x_x_bach_float64_x_x_x_x_", 2084763100, 1078640757, "_x_x_x_x_bach_float64_x_x_x_x_", 374036191, 3222105583, "_x_x_x_x_bach_float64_x_x_x_x_", 1941145150, 1078626664, "_x_x_x_x_bach_float64_x_x_x_x_", 4118697367, 3222100334, "_x_x_x_x_bach_float64_x_x_x_x_", 357628414, 1078612633, "_x_x_x_x_bach_float64_x_x_x_x_", 3568391247, 3222095086, "_x_x_x_x_bach_float64_x_x_x_x_", 1105451939, 1078598663, "_x_x_x_x_bach_float64_x_x_x_x_", 3018085127, 3222089838, "_x_x_x_x_bach_float64_x_x_x_x_", 3665505433, 1078584754, "_x_x_x_x_bach_float64_x_x_x_x_", 2467779006, 3222084590, "_x_x_x_x_bach_float64_x_x_x_x_", 3228296423, 1078570907, "_x_x_x_x_bach_float64_x_x_x_x_", 1917472887, 3222079342, "_x_x_x_x_bach_float64_x_x_x_x_", 3578818834, 1078557121, "_x_x_x_x_bach_float64_x_x_x_x_", 1367166767, 3222074094, "_x_x_x_x_bach_float64_x_x_x_x_", 4211617321, 1078543396, "_x_x_x_x_bach_float64_x_x_x_x_", 816860647, 3222068846, "_x_x_x_x_bach_float64_x_x_x_x_", 330753064, 1078529733, "_x_x_x_x_bach_float64_x_x_x_x_", 266554527, 3222063598, "_x_x_x_x_bach_float64_x_x_x_x_", 29638283, 1078516130, "_x_x_x_x_bach_float64_x_x_x_x_", 4011215702, 3222058349, "_x_x_x_x_bach_float64_x_x_x_x_", 2816164633, 1078502587, "_x_x_x_x_bach_float64_x_x_x_x_", 3460909583, 3222053101, "_x_x_x_x_bach_float64_x_x_x_x_", 3907634964, 1078489105, "_x_x_x_x_bach_float64_x_x_x_x_", 2910603463, 3222047853, "_x_x_x_x_bach_float64_x_x_x_x_", 2820661887, 1078475684, "_x_x_x_x_bach_float64_x_x_x_x_", 2360297343, 3222042605, "_x_x_x_x_bach_float64_x_x_x_x_", 3371131377, 1078462323, "_x_x_x_x_bach_float64_x_x_x_x_", 1809991223, 3222037357, "_x_x_x_x_bach_float64_x_x_x_x_", 789264000, 1078449023, "_x_x_x_x_bach_float64_x_x_x_x_", 1259685102, 3222032109, "_x_x_x_x_bach_float64_x_x_x_x_", 3194414113, 1078435782, "_x_x_x_x_bach_float64_x_x_x_x_", 709378983, 3222026861, "_x_x_x_x_bach_float64_x_x_x_x_", 1530261088, 1078422602, "_x_x_x_x_bach_float64_x_x_x_x_", 159072863, 3222021613, "_x_x_x_x_bach_float64_x_x_x_x_", 3924509520, 1078409481, "_x_x_x_x_bach_float64_x_x_x_x_", 3903734039, 3222016364, "_x_x_x_x_bach_float64_x_x_x_x_", 1329112336, 1078396421, "_x_x_x_x_bach_float64_x_x_x_x_", 3353427919, 3222011116, "_x_x_x_x_bach_float64_x_x_x_x_", 1879970184, 1078383420, "_x_x_x_x_bach_float64_x_x_x_x_", 2803121798, 3222005868, "_x_x_x_x_bach_float64_x_x_x_x_", 832120997, 1078370479, "_x_x_x_x_bach_float64_x_x_x_x_", 2252815678, 3222000620, "_x_x_x_x_bach_float64_x_x_x_x_", 2034536700, 1078357597, "_x_x_x_x_bach_float64_x_x_x_x_", 1702509559, 3221995372, "_x_x_x_x_bach_float64_x_x_x_x_", 750213838, 1078344775, "_x_x_x_x_bach_float64_x_x_x_x_", 1152203439, 3221990124, "_x_x_x_x_bach_float64_x_x_x_x_", 836002191, 1078332012, "_x_x_x_x_bach_float64_x_x_x_x_", 601897319, 3221984876, "_x_x_x_x_bach_float64_x_x_x_x_", 1857661926, 1078319308, "_x_x_x_x_bach_float64_x_x_x_x_", 51591198, 3221979628, "_x_x_x_x_bach_float64_x_x_x_x_", 3384789530, 1078306663, "_x_x_x_x_bach_float64_x_x_x_x_", 3796252374, 3221974379, "_x_x_x_x_bach_float64_x_x_x_x_", 695808788, 1078294078, "_x_x_x_x_bach_float64_x_x_x_x_", 3245946255, 3221969131, "_x_x_x_x_bach_float64_x_x_x_x_", 1957797833, 1078281551, "_x_x_x_x_bach_float64_x_x_x_x_", 2695640135, 3221963883, "_x_x_x_x_bach_float64_x_x_x_x_", 2456642873, 1078269083, "_x_x_x_x_bach_float64_x_x_x_x_", 2145334015, 3221958635, "_x_x_x_x_bach_float64_x_x_x_x_", 1776864527, 1078256674, "_x_x_x_x_bach_float64_x_x_x_x_", 1595027894, 3221953387, "_x_x_x_x_bach_float64_x_x_x_x_", 3801574568, 1078244323, "_x_x_x_x_bach_float64_x_x_x_x_", 1044721774, 3221948139, "_x_x_x_x_bach_float64_x_x_x_x_", 3827530463, 1078232031, "_x_x_x_x_bach_float64_x_x_x_x_", 494415655, 3221942891, "_x_x_x_x_bach_float64_x_x_x_x_", 1449993278, 1078219798, "_x_x_x_x_bach_float64_x_x_x_x_", 4239076831, 3221937642, "_x_x_x_x_bach_float64_x_x_x_x_", 562683381, 1078207623, "_x_x_x_x_bach_float64_x_x_x_x_", 3688770711, 3221932394, "_x_x_x_x_bach_float64_x_x_x_x_", 767801189, 1078195506, "_x_x_x_x_bach_float64_x_x_x_x_", 3138464590, 3221927146, "_x_x_x_x_bach_float64_x_x_x_x_", 1670949457, 1078183447, "_x_x_x_x_bach_float64_x_x_x_x_", 2588158470, 3221921898, "_x_x_x_x_bach_float64_x_x_x_x_", 2881087937, 1078171446, "_x_x_x_x_bach_float64_x_x_x_x_", 2037852350, 3221916650, "_x_x_x_x_bach_float64_x_x_x_x_", 4010487678, 1078159503, "_x_x_x_x_bach_float64_x_x_x_x_", 1487546231, 3221911402, "_x_x_x_x_bach_float64_x_x_x_x_", 379717736, 1078147619, "_x_x_x_x_bach_float64_x_x_x_x_", 937240111, 3221906154, "_x_x_x_x_bach_float64_x_x_x_x_", 197467994, 1078135792, "_x_x_x_x_bach_float64_x_x_x_x_", 386933990, 3221900906, "_x_x_x_x_bach_float64_x_x_x_x_", 3085666036, 1078124022, "_x_x_x_x_bach_float64_x_x_x_x_", 4131595166, 3221895657, "_x_x_x_x_bach_float64_x_x_x_x_", 79430161, 1078112311, "_x_x_x_x_bach_float64_x_x_x_x_", 3581289046, 3221890409, "_x_x_x_x_bach_float64_x_x_x_x_", 3691793148, 1078100656, "_x_x_x_x_bach_float64_x_x_x_x_", 3030982927, 3221885161, "_x_x_x_x_bach_float64_x_x_x_x_", 669014407, 1078089060, "_x_x_x_x_bach_float64_x_x_x_x_", 2480676807, 3221879913, "_x_x_x_x_bach_float64_x_x_x_x_", 3530139617, 1078077520, "_x_x_x_x_bach_float64_x_x_x_x_", 1930370686, 3221874665, "_x_x_x_x_bach_float64_x_x_x_x_", 3322312264, 1078066038, "_x_x_x_x_bach_float64_x_x_x_x_", 1380064566, 3221869417, "_x_x_x_x_bach_float64_x_x_x_x_", 3980463520, 1078054613, "_x_x_x_x_bach_float64_x_x_x_x_", 829758446, 3221864169, "_x_x_x_x_bach_float64_x_x_x_x_", 852426950, 1078043246, "_x_x_x_x_bach_float64_x_x_x_x_", 279452327, 3221858921, "_x_x_x_x_bach_float64_x_x_x_x_", 2173725945, 1078031935, "_x_x_x_x_bach_float64_x_x_x_x_", 4024113503, 3221853672, "_x_x_x_x_bach_float64_x_x_x_x_", 3297720560, 1078020681, "_x_x_x_x_bach_float64_x_x_x_x_", 3473807382, 3221848424, "_x_x_x_x_bach_float64_x_x_x_x_", 3875427106, 1078009484, "_x_x_x_x_bach_float64_x_x_x_x_", 2923501262, 3221843176, "_x_x_x_x_bach_float64_x_x_x_x_", 3560500933, 1077998344, "_x_x_x_x_bach_float64_x_x_x_x_", 2373195142, 3221837928, "_x_x_x_x_bach_float64_x_x_x_x_", 2009186274, 1077987261, "_x_x_x_x_bach_float64_x_x_x_x_", 1822889022, 3221832680, "_x_x_x_x_bach_float64_x_x_x_x_", 3175233122, 1077976234, "_x_x_x_x_bach_float64_x_x_x_x_", 1272582903, 3221827432, "_x_x_x_x_bach_float64_x_x_x_x_", 2424944667, 1077965264, "_x_x_x_x_bach_float64_x_x_x_x_", 722276782, 3221822184, "_x_x_x_x_bach_float64_x_x_x_x_", 3716995543, 1077954350, "_x_x_x_x_bach_float64_x_x_x_x_", 171970662, 3221816936, "_x_x_x_x_bach_float64_x_x_x_x_", 2422511502, 1077943493, "_x_x_x_x_bach_float64_x_x_x_x_", 3916631838, 3221811687, "_x_x_x_x_bach_float64_x_x_x_x_", 714807026, 1077929257, "_x_x_x_x_bach_float64_x_x_x_x_", 3366325718, 3221806439, "_x_x_x_x_bach_float64_x_x_x_x_", 2974697682, 1077907767, "_x_x_x_x_bach_float64_x_x_x_x_", 2816019599, 3221801191, "_x_x_x_x_bach_float64_x_x_x_x_", 2380641872, 1077886390, "_x_x_x_x_bach_float64_x_x_x_x_", 2265713478, 3221795943, "_x_x_x_x_bach_float64_x_x_x_x_", 2577845715, 1077865125, "_x_x_x_x_bach_float64_x_x_x_x_", 1715407358, 3221790695, "_x_x_x_x_bach_float64_x_x_x_x_", 2920800802, 1077843972, "_x_x_x_x_bach_float64_x_x_x_x_", 1165101238, 3221785447, "_x_x_x_x_bach_float64_x_x_x_x_", 2768146384, 1077822931, "_x_x_x_x_bach_float64_x_x_x_x_", 614795118, 3221780199, "_x_x_x_x_bach_float64_x_x_x_x_", 1482563934, 1077802002, "_x_x_x_x_bach_float64_x_x_x_x_", 64488999, 3221774951, "_x_x_x_x_bach_float64_x_x_x_x_", 2725638569, 1077781184, "_x_x_x_x_bach_float64_x_x_x_x_", 3809150174, 3221769702, "_x_x_x_x_bach_float64_x_x_x_x_", 1572850874, 1077760478, "_x_x_x_x_bach_float64_x_x_x_x_", 3258844054, 3221764454, "_x_x_x_x_bach_float64_x_x_x_x_", 1693339481, 1077739883, "_x_x_x_x_bach_float64_x_x_x_x_", 2708537934, 3221759206, "_x_x_x_x_bach_float64_x_x_x_x_", 2464892115, 1077719399, "_x_x_x_x_bach_float64_x_x_x_x_", 2158231814, 3221753958, "_x_x_x_x_bach_float64_x_x_x_x_", 3268805524, 1077699026, "_x_x_x_x_bach_float64_x_x_x_x_", 1607925694, 3221748710, "_x_x_x_x_bach_float64_x_x_x_x_", 3489777740, 1077678764, "_x_x_x_x_bach_float64_x_x_x_x_", 1057619575, 3221743462, "_x_x_x_x_bach_float64_x_x_x_x_", 2515800008, 1077658613, "_x_x_x_x_bach_float64_x_x_x_x_", 507313454, 3221738214, "_x_x_x_x_bach_float64_x_x_x_x_", 4033015645, 1077638572, "_x_x_x_x_bach_float64_x_x_x_x_", 4251974630, 3221732965, "_x_x_x_x_bach_float64_x_x_x_x_", 3140709478, 1077618642, "_x_x_x_x_bach_float64_x_x_x_x_", 3701668510, 3221727717, "_x_x_x_x_bach_float64_x_x_x_x_", 3531067943, 1077598822, "_x_x_x_x_bach_float64_x_x_x_x_", 3151362390, 3221722469, "_x_x_x_x_bach_float64_x_x_x_x_", 309200593, 1077579113, "_x_x_x_x_bach_float64_x_x_x_x_", 2601056271, 3221717221, "_x_x_x_x_bach_float64_x_x_x_x_", 1467866962, 1077559513, "_x_x_x_x_bach_float64_x_x_x_x_", 2050750150, 3221711973, "_x_x_x_x_bach_float64_x_x_x_x_", 2117562867, 1077540023, "_x_x_x_x_bach_float64_x_x_x_x_", 1500444030, 3221706725, "_x_x_x_x_bach_float64_x_x_x_x_", 1666279483, 1077520643, "_x_x_x_x_bach_float64_x_x_x_x_", 950137910, 3221701477, "_x_x_x_x_bach_float64_x_x_x_x_", 3819392884, 1077501372, "_x_x_x_x_bach_float64_x_x_x_x_", 399831790, 3221696229, "_x_x_x_x_bach_float64_x_x_x_x_", 3694651527, 1077482211, "_x_x_x_x_bach_float64_x_x_x_x_", 4144492966, 3221690980, "_x_x_x_x_bach_float64_x_x_x_x_", 706967248, 1077463160, "_x_x_x_x_bach_float64_x_x_x_x_", 3594186846, 3221685732, "_x_x_x_x_bach_float64_x_x_x_x_", 2863271453, 1077444217, "_x_x_x_x_bach_float64_x_x_x_x_", 3043880726, 3221680484, "_x_x_x_x_bach_float64_x_x_x_x_", 992600027, 1077425384, "_x_x_x_x_bach_float64_x_x_x_x_", 2493574606, 3221675236, "_x_x_x_x_bach_float64_x_x_x_x_", 3105720194, 1077406659, "_x_x_x_x_bach_float64_x_x_x_x_", 1943268486, 3221669988, "_x_x_x_x_bach_float64_x_x_x_x_", 35280449, 1077388044, "_x_x_x_x_bach_float64_x_x_x_x_", 1392962366, 3221664740, "_x_x_x_x_bach_float64_x_x_x_x_", 4090404346, 1077369536, "_x_x_x_x_bach_float64_x_x_x_x_", 842656246, 3221659492, "_x_x_x_x_bach_float64_x_x_x_x_", 1811938206, 1077351138, "_x_x_x_x_bach_float64_x_x_x_x_", 292350126, 3221654244, "_x_x_x_x_bach_float64_x_x_x_x_", 1216979182, 1077332848, "_x_x_x_x_bach_float64_x_x_x_x_", 4037011302, 3221648995, "_x_x_x_x_bach_float64_x_x_x_x_", 1733991860, 1077314666, "_x_x_x_x_bach_float64_x_x_x_x_", 3486705182, 3221643747, "_x_x_x_x_bach_float64_x_x_x_x_", 2792630374, 1077296592, "_x_x_x_x_bach_float64_x_x_x_x_", 2936399062, 3221638499, "_x_x_x_x_bach_float64_x_x_x_x_", 3823625838, 1077278626, "_x_x_x_x_bach_float64_x_x_x_x_", 2386092942, 3221633251, "_x_x_x_x_bach_float64_x_x_x_x_", 4258673651, 1077260768, "_x_x_x_x_bach_float64_x_x_x_x_", 1835786822, 3221628003, "_x_x_x_x_bach_float64_x_x_x_x_", 3530320706, 1077243018, "_x_x_x_x_bach_float64_x_x_x_x_", 1285480702, 3221622755, "_x_x_x_x_bach_float64_x_x_x_x_", 1071852525, 1077225376, "_x_x_x_x_bach_float64_x_x_x_x_", 735174582, 3221617507, "_x_x_x_x_bach_float64_x_x_x_x_", 612147603, 1077207841, "_x_x_x_x_bach_float64_x_x_x_x_", 184868462, 3221612259, "_x_x_x_x_bach_float64_x_x_x_x_", 1585629814, 1077190413, "_x_x_x_x_bach_float64_x_x_x_x_", 3929529638, 3221607010, "_x_x_x_x_bach_float64_x_x_x_x_", 3427122637, 1077173092, "_x_x_x_x_bach_float64_x_x_x_x_", 3379223518, 3221601762, "_x_x_x_x_bach_float64_x_x_x_x_", 1276768769, 1077155879, "_x_x_x_x_bach_float64_x_x_x_x_", 2828917398, 3221596514, "_x_x_x_x_bach_float64_x_x_x_x_", 3159786178, 1077138772, "_x_x_x_x_bach_float64_x_x_x_x_", 2278611278, 3221591266, "_x_x_x_x_bach_float64_x_x_x_x_", 4216551178, 1077121772, "_x_x_x_x_bach_float64_x_x_x_x_", 1728305158, 3221586018, "_x_x_x_x_bach_float64_x_x_x_x_", 3882354460, 1077104879, "_x_x_x_x_bach_float64_x_x_x_x_", 1177999038, 3221580770, "_x_x_x_x_bach_float64_x_x_x_x_", 1592320655, 1077088093, "_x_x_x_x_bach_float64_x_x_x_x_", 627692918, 3221575522, "_x_x_x_x_bach_float64_x_x_x_x_", 1076262495, 1077071413, "_x_x_x_x_bach_float64_x_x_x_x_", 77386798, 3221570274, "_x_x_x_x_bach_float64_x_x_x_x_", 1768633119, 1077054839, "_x_x_x_x_bach_float64_x_x_x_x_", 3822047974, 3221565025, "_x_x_x_x_bach_float64_x_x_x_x_", 3103380305, 1077038371, "_x_x_x_x_bach_float64_x_x_x_x_", 3271741854, 3221559777, "_x_x_x_x_bach_float64_x_x_x_x_", 218866168, 1077022010, "_x_x_x_x_bach_float64_x_x_x_x_", 2721435734, 3221554529, "_x_x_x_x_bach_float64_x_x_x_x_", 1137623383, 1077005754, "_x_x_x_x_bach_float64_x_x_x_x_", 2171129614, 3221549281, "_x_x_x_x_bach_float64_x_x_x_x_", 996438542, 1076989604, "_x_x_x_x_bach_float64_x_x_x_x_", 1620823494, 3221544033, "_x_x_x_x_bach_float64_x_x_x_x_", 3521075834, 1076973559, "_x_x_x_x_bach_float64_x_x_x_x_", 1070517374, 3221538785, "_x_x_x_x_bach_float64_x_x_x_x_", 3846295171, 1076957620, "_x_x_x_x_bach_float64_x_x_x_x_", 520211254, 3221533537, "_x_x_x_x_bach_float64_x_x_x_x_", 1400641477, 1076941787, "_x_x_x_x_bach_float64_x_x_x_x_", 4264872430, 3221528288, "_x_x_x_x_bach_float64_x_x_x_x_", 4201299526, 1076926058, "_x_x_x_x_bach_float64_x_x_x_x_", 3714566310, 3221523040, "_x_x_x_x_bach_float64_x_x_x_x_", 3084177811, 1076910435, "_x_x_x_x_bach_float64_x_x_x_x_", 3164260190, 3221517792, "_x_x_x_x_bach_float64_x_x_x_x_", 1768567426, 1076894917, "_x_x_x_x_bach_float64_x_x_x_x_", 2613954070, 3221512544, "_x_x_x_x_bach_float64_x_x_x_x_", 3649288955, 1076871455, "_x_x_x_x_bach_float64_x_x_x_x_", 2063647950, 3221507296, "_x_x_x_x_bach_float64_x_x_x_x_", 1051749100, 1076840838, "_x_x_x_x_bach_float64_x_x_x_x_", 1513341830, 3221502048, "_x_x_x_x_bach_float64_x_x_x_x_", 3172638484, 1076810429, "_x_x_x_x_bach_float64_x_x_x_x_", 963035710, 3221496800, "_x_x_x_x_bach_float64_x_x_x_x_", 256278200, 1076780230, "_x_x_x_x_bach_float64_x_x_x_x_", 412729590, 3221491552, "_x_x_x_x_bach_float64_x_x_x_x_", 4017670255, 1076750238, "_x_x_x_x_bach_float64_x_x_x_x_", 4157390766, 3221486303, "_x_x_x_x_bach_float64_x_x_x_x_", 397635070, 1076720456, "_x_x_x_x_bach_float64_x_x_x_x_", 3607084646, 3221481055, "_x_x_x_x_bach_float64_x_x_x_x_", 1102197236, 1076690881, "_x_x_x_x_bach_float64_x_x_x_x_", 3056778526, 3221475807, "_x_x_x_x_bach_float64_x_x_x_x_", 652691219, 1076661514, "_x_x_x_x_bach_float64_x_x_x_x_", 2506472406, 3221470559, "_x_x_x_x_bach_float64_x_x_x_x_", 2155344274, 1076632354, "_x_x_x_x_bach_float64_x_x_x_x_", 1956166286, 3221465311, "_x_x_x_x_bach_float64_x_x_x_x_", 121186914, 1076603402, "_x_x_x_x_bach_float64_x_x_x_x_", 1405860166, 3221460063, "_x_x_x_x_bach_float64_x_x_x_x_", 1940669574, 1076574656, "_x_x_x_x_bach_float64_x_x_x_x_", 855554046, 3221454815, "_x_x_x_x_bach_float64_x_x_x_x_", 2113639548, 1076546117, "_x_x_x_x_bach_float64_x_x_x_x_", 305247926, 3221449567, "_x_x_x_x_bach_float64_x_x_x_x_", 3723958779, 1076517784, "_x_x_x_x_bach_float64_x_x_x_x_", 4049909102, 3221444318, "_x_x_x_x_bach_float64_x_x_x_x_", 1259416558, 1076489658, "_x_x_x_x_bach_float64_x_x_x_x_", 3499602982, 3221439070, "_x_x_x_x_bach_float64_x_x_x_x_", 2086348518, 1076461737, "_x_x_x_x_bach_float64_x_x_x_x_", 2949296862, 3221433822, "_x_x_x_x_bach_float64_x_x_x_x_", 679615994, 1076434022, "_x_x_x_x_bach_float64_x_x_x_x_", 2398990742, 3221428574, "_x_x_x_x_bach_float64_x_x_x_x_", 97226305, 1076406512, "_x_x_x_x_bach_float64_x_x_x_x_", 1848684622, 3221423326, "_x_x_x_x_bach_float64_x_x_x_x_", 3390182648, 1076379206, "_x_x_x_x_bach_float64_x_x_x_x_", 1298378502, 3221418078, "_x_x_x_x_bach_float64_x_x_x_x_", 717367391, 1076352106, "_x_x_x_x_bach_float64_x_x_x_x_", 748072382, 3221412830, "_x_x_x_x_bach_float64_x_x_x_x_", 3705066346, 1076325209, "_x_x_x_x_bach_float64_x_x_x_x_", 197766262, 3221407582, "_x_x_x_x_bach_float64_x_x_x_x_", 2497082464, 1076298517, "_x_x_x_x_bach_float64_x_x_x_x_", 3942427438, 3221402333, "_x_x_x_x_bach_float64_x_x_x_x_", 114261618, 1076272029, "_x_x_x_x_bach_float64_x_x_x_x_", 3392121317, 3221397085, "_x_x_x_x_bach_float64_x_x_x_x_", 3864346210, 1076245743, "_x_x_x_x_bach_float64_x_x_x_x_", 2841815198, 3221391837, "_x_x_x_x_bach_float64_x_x_x_x_", 3866927742, 1076219661, "_x_x_x_x_bach_float64_x_x_x_x_", 2291509078, 3221386589, "_x_x_x_x_bach_float64_x_x_x_x_", 3118007660, 1076193782, "_x_x_x_x_bach_float64_x_x_x_x_", 1741202958, 3221381341, "_x_x_x_x_bach_float64_x_x_x_x_", 309918931, 1076168106, "_x_x_x_x_bach_float64_x_x_x_x_", 1190896838, 3221376093, "_x_x_x_x_bach_float64_x_x_x_x_", 2716019469, 1076142631, "_x_x_x_x_bach_float64_x_x_x_x_", 640590717, 3221370845, "_x_x_x_x_bach_float64_x_x_x_x_", 420680818, 1076117359, "_x_x_x_x_bach_float64_x_x_x_x_", 90284598, 3221365597, "_x_x_x_x_bach_float64_x_x_x_x_", 678819916, 1076092288, "_x_x_x_x_bach_float64_x_x_x_x_", 3834945774, 3221360348, "_x_x_x_x_bach_float64_x_x_x_x_", 2145889577, 1076067418, "_x_x_x_x_bach_float64_x_x_x_x_", 3284639654, 3221355100, "_x_x_x_x_bach_float64_x_x_x_x_", 3467608392, 1076042749, "_x_x_x_x_bach_float64_x_x_x_x_", 2734333534, 3221349852, "_x_x_x_x_bach_float64_x_x_x_x_", 3279756950, 1076018281, "_x_x_x_x_bach_float64_x_x_x_x_", 2184027413, 3221344604, "_x_x_x_x_bach_float64_x_x_x_x_", 207975059, 1075994014, "_x_x_x_x_bach_float64_x_x_x_x_", 1633721294, 3221339356, "_x_x_x_x_bach_float64_x_x_x_x_", 1457494623, 1075969946, "_x_x_x_x_bach_float64_x_x_x_x_", 1083415174, 3221334108, "_x_x_x_x_bach_float64_x_x_x_x_", 1338102388, 1075946078, "_x_x_x_x_bach_float64_x_x_x_x_", 533109054, 3221328860, "_x_x_x_x_bach_float64_x_x_x_x_", 2738776822, 1075922409, "_x_x_x_x_bach_float64_x_x_x_x_", 4277770230, 3221323611, "_x_x_x_x_bach_float64_x_x_x_x_", 4242587616, 1075898939, "_x_x_x_x_bach_float64_x_x_x_x_", 3727464109, 3221318363, "_x_x_x_x_bach_float64_x_x_x_x_", 126498196, 1075875669, "_x_x_x_x_bach_float64_x_x_x_x_", 3177157990, 3221313115, "_x_x_x_x_bach_float64_x_x_x_x_", 1836005867, 1075852596, "_x_x_x_x_bach_float64_x_x_x_x_", 2626851870, 3221307867, "_x_x_x_x_bach_float64_x_x_x_x_", 2955449007, 1075820467, "_x_x_x_x_bach_float64_x_x_x_x_", 2076545750, 3221302619, "_x_x_x_x_bach_float64_x_x_x_x_", 3767923206, 1075775113, "_x_x_x_x_bach_float64_x_x_x_x_", 1526239630, 3221297371, "_x_x_x_x_bach_float64_x_x_x_x_", 3160279624, 1075730154, "_x_x_x_x_bach_float64_x_x_x_x_", 975933509, 3221292123, "_x_x_x_x_bach_float64_x_x_x_x_", 2454112338, 1075685589, "_x_x_x_x_bach_float64_x_x_x_x_", 425627390, 3221286875, "_x_x_x_x_bach_float64_x_x_x_x_", 2946415964, 1075641417, "_x_x_x_x_bach_float64_x_x_x_x_", 4170288566, 3221281626, "_x_x_x_x_bach_float64_x_x_x_x_", 1614239733, 1075597638, "_x_x_x_x_bach_float64_x_x_x_x_", 3619982446, 3221276378, "_x_x_x_x_bach_float64_x_x_x_x_", 3999213457, 1075554250, "_x_x_x_x_bach_float64_x_x_x_x_", 3069676326, 3221271130, "_x_x_x_x_bach_float64_x_x_x_x_", 2732337518, 1075511254, "_x_x_x_x_bach_float64_x_x_x_x_", 2519370205, 3221265882, "_x_x_x_x_bach_float64_x_x_x_x_", 3303415731, 1075468648, "_x_x_x_x_bach_float64_x_x_x_x_", 1969064086, 3221260634, "_x_x_x_x_bach_float64_x_x_x_x_", 2585850631, 1075426432, "_x_x_x_x_bach_float64_x_x_x_x_", 1418757966, 3221255386, "_x_x_x_x_bach_float64_x_x_x_x_", 1721179616, 1075384605, "_x_x_x_x_bach_float64_x_x_x_x_", 868451846, 3221250138, "_x_x_x_x_bach_float64_x_x_x_x_", 1823744808, 1075343166, "_x_x_x_x_bach_float64_x_x_x_x_", 318145726, 3221244890, "_x_x_x_x_bach_float64_x_x_x_x_", 3980332770, 1075302114, "_x_x_x_x_bach_float64_x_x_x_x_", 4062806901, 3221239641, "_x_x_x_x_bach_float64_x_x_x_x_", 659882456, 1075261450, "_x_x_x_x_bach_float64_x_x_x_x_", 3512500782, 3221234393, "_x_x_x_x_bach_float64_x_x_x_x_", 1482934360, 1075221171, "_x_x_x_x_bach_float64_x_x_x_x_", 2962194661, 3221229145, "_x_x_x_x_bach_float64_x_x_x_x_", 3156507520, 1075181277, "_x_x_x_x_bach_float64_x_x_x_x_", 528809788, 3221222323, "_x_x_x_x_bach_float64_x_x_x_x_", 2358652564, 1075141768, "_x_x_x_x_bach_float64_x_x_x_x_", 3723164844, 3221211826, "_x_x_x_x_bach_float64_x_x_x_x_", 33072804, 1075102643, "_x_x_x_x_bach_float64_x_x_x_x_", 2622552602, 3221201330, "_x_x_x_x_bach_float64_x_x_x_x_", 1388781216, 1075063900, "_x_x_x_x_bach_float64_x_x_x_x_", 1521940364, 3221190834, "_x_x_x_x_bach_float64_x_x_x_x_", 3014858369, 1075025539, "_x_x_x_x_bach_float64_x_x_x_x_", 421328122, 3221180338, "_x_x_x_x_bach_float64_x_x_x_x_", 1470049810, 1074987560, "_x_x_x_x_bach_float64_x_x_x_x_", 3615683180, 3221169841, "_x_x_x_x_bach_float64_x_x_x_x_", 1872366648, 1074949961, "_x_x_x_x_bach_float64_x_x_x_x_", 2515070940, 3221159345, "_x_x_x_x_bach_float64_x_x_x_x_", 718885226, 1074912742, "_x_x_x_x_bach_float64_x_x_x_x_", 1414458698, 3221148849, "_x_x_x_x_bach_float64_x_x_x_x_", 3065288444, 1074875901, "_x_x_x_x_bach_float64_x_x_x_x_", 313846460, 3221138353, "_x_x_x_x_bach_float64_x_x_x_x_", 1050704493, 1074839439, "_x_x_x_x_bach_float64_x_x_x_x_", 3508201514, 3221127856, "_x_x_x_x_bach_float64_x_x_x_x_", 3962156225, 1074803353, "_x_x_x_x_bach_float64_x_x_x_x_", 2407589276, 3221117360, "_x_x_x_x_bach_float64_x_x_x_x_", 3454041678, 1074744889, "_x_x_x_x_bach_float64_x_x_x_x_", 1306977036, 3221106864, "_x_x_x_x_bach_float64_x_x_x_x_", 2839873197, 1074674222, "_x_x_x_x_bach_float64_x_x_x_x_", 206364794, 3221096368, "_x_x_x_x_bach_float64_x_x_x_x_", 2985374446, 1074604304, "_x_x_x_x_bach_float64_x_x_x_x_", 3400719852, 3221085871, "_x_x_x_x_bach_float64_x_x_x_x_", 727655712, 1074535134, "_x_x_x_x_bach_float64_x_x_x_x_", 2300107610, 3221075375, "_x_x_x_x_bach_float64_x_x_x_x_", 1426694023, 1074466709, "_x_x_x_x_bach_float64_x_x_x_x_", 1199495372, 3221064879, "_x_x_x_x_bach_float64_x_x_x_x_", 1784860313, 1074399028, "_x_x_x_x_bach_float64_x_x_x_x_", 98883132, 3221054383, "_x_x_x_x_bach_float64_x_x_x_x_", 2731224044, 1074332089, "_x_x_x_x_bach_float64_x_x_x_x_", 3293238186, 3221043886, "_x_x_x_x_bach_float64_x_x_x_x_", 831028514, 1074265891, "_x_x_x_x_bach_float64_x_x_x_x_", 2192625948, 3221033390, "_x_x_x_x_bach_float64_x_x_x_x_", 1170009410, 1074200431, "_x_x_x_x_bach_float64_x_x_x_x_", 1092013706, 3221022894, "_x_x_x_x_bach_float64_x_x_x_x_", 173949128, 1074135708, "_x_x_x_x_bach_float64_x_x_x_x_", 4286368764, 3221012397, "_x_x_x_x_bach_float64_x_x_x_x_", 2787976792, 1074071719, "_x_x_x_x_bach_float64_x_x_x_x_", 3185756524, 3221001901, "_x_x_x_x_bach_float64_x_x_x_x_", 1001169302, 1074008464, "_x_x_x_x_bach_float64_x_x_x_x_", 2085144282, 3220991405, "_x_x_x_x_bach_float64_x_x_x_x_", 3910767375, 1073945939, "_x_x_x_x_bach_float64_x_x_x_x_", 984532044, 3220980909, "_x_x_x_x_bach_float64_x_x_x_x_", 3361889205, 1073884144, "_x_x_x_x_bach_float64_x_x_x_x_", 4178887098, 3220970412, "_x_x_x_x_bach_float64_x_x_x_x_", 4011760691, 1073823076, "_x_x_x_x_bach_float64_x_x_x_x_", 3078274860, 3220959916, "_x_x_x_x_bach_float64_x_x_x_x_", 1854345696, 1073762734, "_x_x_x_x_bach_float64_x_x_x_x_", 1977662620, 3220949420, "_x_x_x_x_bach_float64_x_x_x_x_", 2799377934, 1073664406, "_x_x_x_x_bach_float64_x_x_x_x_", 877050378, 3220938924, "_x_x_x_x_bach_float64_x_x_x_x_", 1282024054, 1073546611, "_x_x_x_x_bach_float64_x_x_x_x_", 4071405436, 3220928427, "_x_x_x_x_bach_float64_x_x_x_x_", 3583240356, 1073430254, "_x_x_x_x_bach_float64_x_x_x_x_", 2970793194, 3220917931, "_x_x_x_x_bach_float64_x_x_x_x_", 1093960844, 1073315333, "_x_x_x_x_bach_float64_x_x_x_x_", 1870180956, 3220907435, "_x_x_x_x_bach_float64_x_x_x_x_", 2233221946, 1073201842, "_x_x_x_x_bach_float64_x_x_x_x_", 769568714, 3220896939, "_x_x_x_x_bach_float64_x_x_x_x_", 2382413962, 1073089778, "_x_x_x_x_bach_float64_x_x_x_x_", 3963923770, 3220886442, "_x_x_x_x_bach_float64_x_x_x_x_", 1064188714, 1072979137, "_x_x_x_x_bach_float64_x_x_x_x_", 2863311532, 3220875946, "_x_x_x_x_bach_float64_x_x_x_x_", 1941512892, 1072869914, "_x_x_x_x_bach_float64_x_x_x_x_", 1762699290, 3220865450, "_x_x_x_x_bach_float64_x_x_x_x_", 4226802514, 1072762105, "_x_x_x_x_bach_float64_x_x_x_x_", 662087052, 3220854954, "_x_x_x_x_bach_float64_x_x_x_x_", 1067048248, 1072618167, "_x_x_x_x_bach_float64_x_x_x_x_", 3856442106, 3220844457, "_x_x_x_x_bach_float64_x_x_x_x_", 995229872, 1072408182, "_x_x_x_x_bach_float64_x_x_x_x_", 2755829866, 3220833961, "_x_x_x_x_bach_float64_x_x_x_x_", 1423656320, 1072201000, "_x_x_x_x_bach_float64_x_x_x_x_", 1655217628, 3220823465, "_x_x_x_x_bach_float64_x_x_x_x_", 3809467872, 1071996612, "_x_x_x_x_bach_float64_x_x_x_x_", 554605386, 3220812969, "_x_x_x_x_bach_float64_x_x_x_x_", 699865280, 1071795011, "_x_x_x_x_bach_float64_x_x_x_x_", 3748960444, 3220802472, "_x_x_x_x_bach_float64_x_x_x_x_", 3000483592, 1071547700, "_x_x_x_x_bach_float64_x_x_x_x_", 2648348202, 3220791976, "_x_x_x_x_bach_float64_x_x_x_x_", 520576008, 1071155587, "_x_x_x_x_bach_float64_x_x_x_x_", 1547735962, 3220781480, "_x_x_x_x_bach_float64_x_x_x_x_", 2884377184, 1070768991, "_x_x_x_x_bach_float64_x_x_x_x_", 447123724, 3220770984, "_x_x_x_x_bach_float64_x_x_x_x_", 2366777008, 1070179696, "_x_x_x_x_bach_float64_x_x_x_x_", 3641478778, 3220760487, "_x_x_x_x_bach_float64_x_x_x_x_", 3541654336, 1069309418, "_x_x_x_x_bach_float64_x_x_x_x_", 2540866540, 3220749991, "_x_x_x_x_bach_float64_x_x_x_x_", 1412292096, 1066867017, "_x_x_x_x_bach_float64_x_x_x_x_", 1440254298, 3220739495, "_x_x_x_x_bach_float64_x_x_x_x_", 2204244928, 3216014386, "_x_x_x_x_bach_float64_x_x_x_x_", 339642058, 3220728999, "_x_x_x_x_bach_float64_x_x_x_x_", 1007316208, 3217241335, "_x_x_x_x_bach_float64_x_x_x_x_", 3533997116, 3220718502, "_x_x_x_x_bach_float64_x_x_x_x_", 1964216496, 3217949078, "_x_x_x_x_bach_float64_x_x_x_x_", 2433384874, 3220708006, "_x_x_x_x_bach_float64_x_x_x_x_", 1990462984, 3218362894, "_x_x_x_x_bach_float64_x_x_x_x_", 1332772636, 3220697510, "_x_x_x_x_bach_float64_x_x_x_x_", 2058488568, 3218706008, "_x_x_x_x_bach_float64_x_x_x_x_", 232160394, 3220687014, "_x_x_x_x_bach_float64_x_x_x_x_", 2539252672, 3219043772, "_x_x_x_x_bach_float64_x_x_x_x_", 3426515450, 3220676517, "_x_x_x_x_bach_float64_x_x_x_x_", 584611452, 3219252263, "_x_x_x_x_bach_float64_x_x_x_x_", 2325903212, 3220666021, "_x_x_x_x_bach_float64_x_x_x_x_", 2477825940, 3219415824, "_x_x_x_x_bach_float64_x_x_x_x_", 1225290970, 3220655525, "_x_x_x_x_bach_float64_x_x_x_x_", 2204593832, 3219576740, "_x_x_x_x_bach_float64_x_x_x_x_", 124678732, 3220645029, "_x_x_x_x_bach_float64_x_x_x_x_", 3952978668, 3219735020, "_x_x_x_x_bach_float64_x_x_x_x_", 3319033786, 3220634532, "_x_x_x_x_bach_float64_x_x_x_x_", 3665053324, 3219890675, "_x_x_x_x_bach_float64_x_x_x_x_", 2218421546, 3220624036, "_x_x_x_x_bach_float64_x_x_x_x_", 1922905552, 3220043715, "_x_x_x_x_bach_float64_x_x_x_x_", 1117809308, 3220613540, "_x_x_x_x_bach_float64_x_x_x_x_", 4122337540, 3220185522, "_x_x_x_x_bach_float64_x_x_x_x_", 17197066, 3220603044, "_x_x_x_x_bach_float64_x_x_x_x_", 3362925036, 3220259442, "_x_x_x_x_bach_float64_x_x_x_x_", 3211552124, 3220592547, "_x_x_x_x_bach_float64_x_x_x_x_", 1642453590, 3220332070, "_x_x_x_x_bach_float64_x_x_x_x_", 2110939882, 3220582051, "_x_x_x_x_bach_float64_x_x_x_x_", 4242203956, 3220403410, "_x_x_x_x_bach_float64_x_x_x_x_", 1010327642, 3220571555, "_x_x_x_x_bach_float64_x_x_x_x_", 3733578680, 3220473469, "_x_x_x_x_bach_float64_x_x_x_x_", 4204682696, 3220561058, "_x_x_x_x_bach_float64_x_x_x_x_", 1453386298, 3220542252, "_x_x_x_x_bach_float64_x_x_x_x_", 3104070458, 3220550562, "_x_x_x_x_bach_float64_x_x_x_x_", 3209303868, 3220609763, "_x_x_x_x_bach_float64_x_x_x_x_", 2003458220, 3220540066, "_x_x_x_x_bach_float64_x_x_x_x_", 2100420284, 3220676009, "_x_x_x_x_bach_float64_x_x_x_x_", 902845978, 3220529570, "_x_x_x_x_bach_float64_x_x_x_x_", 4287434656, 3220740994, "_x_x_x_x_bach_float64_x_x_x_x_", 4097201034, 3220519073, "_x_x_x_x_bach_float64_x_x_x_x_", 3223229454, 3220804725, "_x_x_x_x_bach_float64_x_x_x_x_", 2996588792, 3220508577, "_x_x_x_x_bach_float64_x_x_x_x_", 1128066338, 3220867207, "_x_x_x_x_bach_float64_x_x_x_x_", 1895976554, 3220498081, "_x_x_x_x_bach_float64_x_x_x_x_", 399992906, 3220928445, "_x_x_x_x_bach_float64_x_x_x_x_", 795364316, 3220487585, "_x_x_x_x_bach_float64_x_x_x_x_", 3615166444, 3220988444, "_x_x_x_x_bach_float64_x_x_x_x_", 3989719370, 3220477088, "_x_x_x_x_bach_float64_x_x_x_x_", 643257770, 3221047212, "_x_x_x_x_bach_float64_x_x_x_x_", 2889107130, 3220466592, "_x_x_x_x_bach_float64_x_x_x_x_", 3007477468, 3221104752, "_x_x_x_x_bach_float64_x_x_x_x_", 1788494888, 3220456096, "_x_x_x_x_bach_float64_x_x_x_x_", 935173042, 3221161072, "_x_x_x_x_bach_float64_x_x_x_x_", 687882650, 3220445600, "_x_x_x_x_bach_float64_x_x_x_x_", 2012786549, 3221216176, "_x_x_x_x_bach_float64_x_x_x_x_", 3882237708, 3220435103, "_x_x_x_x_bach_float64_x_x_x_x_", 2708142524, 3221247771, "_x_x_x_x_bach_float64_x_x_x_x_", 2781625466, 3220424607, "_x_x_x_x_bach_float64_x_x_x_x_", 955688340, 3221274117, "_x_x_x_x_bach_float64_x_x_x_x_", 1681013226, 3220414111, "_x_x_x_x_bach_float64_x_x_x_x_", 4106723558, 3221299863, "_x_x_x_x_bach_float64_x_x_x_x_", 580400984, 3220403615, "_x_x_x_x_bach_float64_x_x_x_x_", 3429098814, 3221325014, "_x_x_x_x_bach_float64_x_x_x_x_", 3774756042, 3220393118, "_x_x_x_x_bach_float64_x_x_x_x_", 3165674601, 3221349572, "_x_x_x_x_bach_float64_x_x_x_x_", 2674143804, 3220382622, "_x_x_x_x_bach_float64_x_x_x_x_", 3354524137, 3221373540, "_x_x_x_x_bach_float64_x_x_x_x_", 1573531562, 3220372126, "_x_x_x_x_bach_float64_x_x_x_x_", 4123963604, 3221396921, "_x_x_x_x_bach_float64_x_x_x_x_", 472919322, 3220361630, "_x_x_x_x_bach_float64_x_x_x_x_", 1397638760, 3221419719, "_x_x_x_x_bach_float64_x_x_x_x_", 3667274376, 3220351133, "_x_x_x_x_bach_float64_x_x_x_x_", 4074439044, 3221441935, "_x_x_x_x_bach_float64_x_x_x_x_", 2566662138, 3220340637, "_x_x_x_x_bach_float64_x_x_x_x_", 3963762294, 3221463574, "_x_x_x_x_bach_float64_x_x_x_x_", 1466049900, 3220330141, "_x_x_x_x_bach_float64_x_x_x_x_", 1555345325, 3221484639, "_x_x_x_x_bach_float64_x_x_x_x_", 365437658, 3220319645, "_x_x_x_x_bach_float64_x_x_x_x_", 1724314333, 3221505132, "_x_x_x_x_bach_float64_x_x_x_x_", 3559792714, 3220309148, "_x_x_x_x_bach_float64_x_x_x_x_", 846291638, 3221525057, "_x_x_x_x_bach_float64_x_x_x_x_", 2459180472, 3220298652, "_x_x_x_x_bach_float64_x_x_x_x_", 3977264496, 3221544416, "_x_x_x_x_bach_float64_x_x_x_x_", 1358568234, 3220288156, "_x_x_x_x_bach_float64_x_x_x_x_", 3378739115, 3221563214, "_x_x_x_x_bach_float64_x_x_x_x_", 257955996, 3220277660, "_x_x_x_x_bach_float64_x_x_x_x_", 4287525938, 3221581453, "_x_x_x_x_bach_float64_x_x_x_x_", 3452311050, 3220267163, "_x_x_x_x_bach_float64_x_x_x_x_", 3440875548, 3221599137, "_x_x_x_x_bach_float64_x_x_x_x_", 2351698810, 3220256667, "_x_x_x_x_bach_float64_x_x_x_x_", 1961343911, 3221616269, "_x_x_x_x_bach_float64_x_x_x_x_", 1251086568, 3220246171, "_x_x_x_x_bach_float64_x_x_x_x_", 1061779400, 3221632852, "_x_x_x_x_bach_float64_x_x_x_x_", 150474330, 3220235675, "_x_x_x_x_bach_float64_x_x_x_x_", 2045268037, 3221648889, "_x_x_x_x_bach_float64_x_x_x_x_", 3344829384, 3220225178, "_x_x_x_x_bach_float64_x_x_x_x_", 2010102434, 3221664384, "_x_x_x_x_bach_float64_x_x_x_x_", 2244217146, 3220214682, "_x_x_x_x_bach_float64_x_x_x_x_", 2439643535, 3221679340, "_x_x_x_x_bach_float64_x_x_x_x_", 1143604906, 3220204186, "_x_x_x_x_bach_float64_x_x_x_x_", 612304208, 3221693761, "_x_x_x_x_bach_float64_x_x_x_x_", 42992664, 3220193690, "_x_x_x_x_bach_float64_x_x_x_x_", 2486360240, 3221707649, "_x_x_x_x_bach_float64_x_x_x_x_", 3237347722, 3220183193, "_x_x_x_x_bach_float64_x_x_x_x_", 1225013985, 3221721009, "_x_x_x_x_bach_float64_x_x_x_x_", 4273470960, 3220168498, "_x_x_x_x_bach_float64_x_x_x_x_", 2966089277, 3221733843, "_x_x_x_x_bach_float64_x_x_x_x_", 2072246480, 3220147506, "_x_x_x_x_bach_float64_x_x_x_x_", 1052109758, 3221746156, "_x_x_x_x_bach_float64_x_x_x_x_", 4165989304, 3220126513, "_x_x_x_x_bach_float64_x_x_x_x_", 1799975820, 3221757950, "_x_x_x_x_bach_float64_x_x_x_x_", 1964764816, 3220105521, "_x_x_x_x_bach_float64_x_x_x_x_", 3025992333, 3221769229, "_x_x_x_x_bach_float64_x_x_x_x_", 4058507632, 3220084528, "_x_x_x_x_bach_float64_x_x_x_x_", 2635658423, 3221779997, "_x_x_x_x_bach_float64_x_x_x_x_", 1857283152, 3220063536, "_x_x_x_x_bach_float64_x_x_x_x_", 2918481113, 3221790257, "_x_x_x_x_bach_float64_x_x_x_x_", 3951025968, 3220042543, "_x_x_x_x_bach_float64_x_x_x_x_", 1957878088, 3221800013, "_x_x_x_x_bach_float64_x_x_x_x_", 1749801496, 3220021551, "_x_x_x_x_bach_float64_x_x_x_x_", 2220940752, 3221809268, "_x_x_x_x_bach_float64_x_x_x_x_", 3843544304, 3220000558, "_x_x_x_x_bach_float64_x_x_x_x_", 1968319248, 3221818026, "_x_x_x_x_bach_float64_x_x_x_x_", 1642319824, 3219979566, "_x_x_x_x_bach_float64_x_x_x_x_", 3843967714, 3221826290, "_x_x_x_x_bach_float64_x_x_x_x_", 3736062640, 3219958573, "_x_x_x_x_bach_float64_x_x_x_x_", 1990044302, 3221834065, "_x_x_x_x_bach_float64_x_x_x_x_", 1534838160, 3219937581, "_x_x_x_x_bach_float64_x_x_x_x_", 3521540665, 3221841353, "_x_x_x_x_bach_float64_x_x_x_x_", 3628580984, 3219916588, "_x_x_x_x_bach_float64_x_x_x_x_", 2756262402, 3221848159, "_x_x_x_x_bach_float64_x_x_x_x_", 1427356496, 3219895596, "_x_x_x_x_bach_float64_x_x_x_x_", 2689440978, 3221854486, "_x_x_x_x_bach_float64_x_x_x_x_", 3521099312, 3219874603, "_x_x_x_x_bach_float64_x_x_x_x_", 2108598483, 3221860338, "_x_x_x_x_bach_float64_x_x_x_x_", 1319874832, 3219853611, "_x_x_x_x_bach_float64_x_x_x_x_", 4183240158, 3221865718, "_x_x_x_x_bach_float64_x_x_x_x_", 3413617648, 3219832618, "_x_x_x_x_bach_float64_x_x_x_x_", 3579701702, 3221870631, "_x_x_x_x_bach_float64_x_x_x_x_", 1212393176, 3219811626, "_x_x_x_x_bach_float64_x_x_x_x_", 3640758966, 3221875080, "_x_x_x_x_bach_float64_x_x_x_x_", 3306135984, 3219790633, "_x_x_x_x_bach_float64_x_x_x_x_", 3500457907, 3221879069, "_x_x_x_x_bach_float64_x_x_x_x_", 1104911504, 3219769641, "_x_x_x_x_bach_float64_x_x_x_x_", 2378805073, 3221882602, "_x_x_x_x_bach_float64_x_x_x_x_", 3198654320, 3219748648, "_x_x_x_x_bach_float64_x_x_x_x_", 3876449493, 3221885682, "_x_x_x_x_bach_float64_x_x_x_x_", 997429840, 3219727656, "_x_x_x_x_bach_float64_x_x_x_x_", 3089486790, 3221888314, "_x_x_x_x_bach_float64_x_x_x_x_", 3091172656, 3219706663, "_x_x_x_x_bach_float64_x_x_x_x_", 3789025808, 3221890501, "_x_x_x_x_bach_float64_x_x_x_x_", 889948176, 3219685671, "_x_x_x_x_bach_float64_x_x_x_x_", 1241008347, 3221892248, "_x_x_x_x_bach_float64_x_x_x_x_", 2983690992, 3219664678, "_x_x_x_x_bach_float64_x_x_x_x_", 3680726076, 3221893557, "_x_x_x_x_bach_float64_x_x_x_x_", 782466512, 3219643686, "_x_x_x_x_bach_float64_x_x_x_x_", 2247721420, 3221894434, "_x_x_x_x_bach_float64_x_x_x_x_", 2876209328, 3219622693, "_x_x_x_x_bach_float64_x_x_x_x_", 1050222175, 3221894882, "_x_x_x_x_bach_float64_x_x_x_x_", 674984848, 3219601701, "_x_x_x_x_bach_float64_x_x_x_x_", 4279894757, 3221894904, "_x_x_x_x_bach_float64_x_x_x_x_", 2768727664, 3219580708, "_x_x_x_x_bach_float64_x_x_x_x_", 3326589100, 3221894506, "_x_x_x_x_bach_float64_x_x_x_x_", 567503184, 3219559716, "_x_x_x_x_bach_float64_x_x_x_x_", 2547780882, 3221893691, "_x_x_x_x_bach_float64_x_x_x_x_", 2661246000, 3219538723, "_x_x_x_x_bach_float64_x_x_x_x_", 2088332514, 3221892463, "_x_x_x_x_bach_float64_x_x_x_x_", 460021520, 3219517731, "_x_x_x_x_bach_float64_x_x_x_x_", 2175082348, 3221890826, "_x_x_x_x_bach_float64_x_x_x_x_", 2553764336, 3219496738, "_x_x_x_x_bach_float64_x_x_x_x_", 3116458380, 3221888784, "_x_x_x_x_bach_float64_x_x_x_x_", 352539856, 3219475746, "_x_x_x_x_bach_float64_x_x_x_x_", 1007116480, 3221886342, "_x_x_x_x_bach_float64_x_x_x_x_", 2446282672, 3219454753, "_x_x_x_x_bach_float64_x_x_x_x_", 612439670, 3221883503, "_x_x_x_x_bach_float64_x_x_x_x_", 245058192, 3219433761, "_x_x_x_x_bach_float64_x_x_x_x_", 2483225533, 3221880271, "_x_x_x_x_bach_float64_x_x_x_x_", 2338801008, 3219412768, "_x_x_x_x_bach_float64_x_x_x_x_", 2955267451, 3221876651, "_x_x_x_x_bach_float64_x_x_x_x_", 137576528, 3219391776, "_x_x_x_x_bach_float64_x_x_x_x_", 2738862428, 3221872647, "_x_x_x_x_bach_float64_x_x_x_x_", 2231319344, 3219370783, "_x_x_x_x_bach_float64_x_x_x_x_", 2623409053, 3221868263, "_x_x_x_x_bach_float64_x_x_x_x_", 30094864, 3219349791, "_x_x_x_x_bach_float64_x_x_x_x_", 3476964830, 3221863503, "_x_x_x_x_bach_float64_x_x_x_x_", 2123837680, 3219328798, "_x_x_x_x_bach_float64_x_x_x_x_", 1950828341, 3221858372, "_x_x_x_x_bach_float64_x_x_x_x_", 4217580496, 3219307805, "_x_x_x_x_bach_float64_x_x_x_x_", 3363982742, 3221852873, "_x_x_x_x_bach_float64_x_x_x_x_", 2016356016, 3219286813, "_x_x_x_x_bach_float64_x_x_x_x_", 227793111, 3221847012, "_x_x_x_x_bach_float64_x_x_x_x_", 4110098832, 3219265820, "_x_x_x_x_bach_float64_x_x_x_x_", 2310303599, 3221840791, "_x_x_x_x_bach_float64_x_x_x_x_", 1908874352, 3219244828, "_x_x_x_x_bach_float64_x_x_x_x_", 2276017449, 3221834216, "_x_x_x_x_bach_float64_x_x_x_x_", 4002617168, 3219223835, "_x_x_x_x_bach_float64_x_x_x_x_", 1455211510, 3221827291, "_x_x_x_x_bach_float64_x_x_x_x_", 1801392688, 3219202843, "_x_x_x_x_bach_float64_x_x_x_x_", 1253504776, 3221820020, "_x_x_x_x_bach_float64_x_x_x_x_", 3895135504, 3219181850, "_x_x_x_x_bach_float64_x_x_x_x_", 3151353982, 3221812407, "_x_x_x_x_bach_float64_x_x_x_x_", 1693911024, 3219160858, "_x_x_x_x_bach_float64_x_x_x_x_", 113607096, 3221804458, "_x_x_x_x_bach_float64_x_x_x_x_", 3787653840, 3219139865, "_x_x_x_x_bach_float64_x_x_x_x_", 2358787739, 3221796175, "_x_x_x_x_bach_float64_x_x_x_x_", 3172858720, 3219109426, "_x_x_x_x_bach_float64_x_x_x_x_", 2998830067, 3221787564, "_x_x_x_x_bach_float64_x_x_x_x_", 3065377056, 3219067441, "_x_x_x_x_bach_float64_x_x_x_x_", 3808348447, 3221778629, "_x_x_x_x_bach_float64_x_x_x_x_", 2957895392, 3219025456, "_x_x_x_x_bach_float64_x_x_x_x_", 2339194183, 3221769375, "_x_x_x_x_bach_float64_x_x_x_x_", 2850413728, 3218983471, "_x_x_x_x_bach_float64_x_x_x_x_", 509841493, 3221759806, "_x_x_x_x_bach_float64_x_x_x_x_", 2742932064, 3218941486, "_x_x_x_x_bach_float64_x_x_x_x_", 309864414, 3221749926, "_x_x_x_x_bach_float64_x_x_x_x_", 2635450400, 3218899501, "_x_x_x_x_bach_float64_x_x_x_x_", 3799373870, 3221739739, "_x_x_x_x_bach_float64_x_x_x_x_", 2527968736, 3218857516, "_x_x_x_x_bach_float64_x_x_x_x_", 223545805, 3221729252, "_x_x_x_x_bach_float64_x_x_x_x_", 2420487072, 3218815531, "_x_x_x_x_bach_float64_x_x_x_x_", 371782536, 3221718467, "_x_x_x_x_bach_float64_x_x_x_x_", 2313005408, 3218773546, "_x_x_x_x_bach_float64_x_x_x_x_", 2217390441, 3221707389, "_x_x_x_x_bach_float64_x_x_x_x_", 2205523744, 3218731561, "_x_x_x_x_bach_float64_x_x_x_x_", 3801890989, 3221696023, "_x_x_x_x_bach_float64_x_x_x_x_", 2098042080, 3218689576, "_x_x_x_x_bach_float64_x_x_x_x_", 3234423064, 3221684374, "_x_x_x_x_bach_float64_x_x_x_x_", 1990560416, 3218647591, "_x_x_x_x_bach_float64_x_x_x_x_", 2986105797, 3221672446, "_x_x_x_x_bach_float64_x_x_x_x_", 1883078752, 3218605606, "_x_x_x_x_bach_float64_x_x_x_x_", 1299492794, 3221660244, "_x_x_x_x_bach_float64_x_x_x_x_", 1775597088, 3218563621, "_x_x_x_x_bach_float64_x_x_x_x_", 777888913, 3221647772, "_x_x_x_x_bach_float64_x_x_x_x_", 1668115424, 3218521636, "_x_x_x_x_bach_float64_x_x_x_x_", 4089758541, 3221635034, "_x_x_x_x_bach_float64_x_x_x_x_", 1560633760, 3218479651, "_x_x_x_x_bach_float64_x_x_x_x_", 1083192755, 3221622037, "_x_x_x_x_bach_float64_x_x_x_x_", 1453152096, 3218437666, "_x_x_x_x_bach_float64_x_x_x_x_", 3145010287, 3221608783, "_x_x_x_x_bach_float64_x_x_x_x_", 1345670432, 3218395681, "_x_x_x_x_bach_float64_x_x_x_x_", 250440734, 3221595279, "_x_x_x_x_bach_float64_x_x_x_x_", 1238188768, 3218353696, "_x_x_x_x_bach_float64_x_x_x_x_", 3912147379, 3221581527, "_x_x_x_x_bach_float64_x_x_x_x_", 1130707104, 3218311711, "_x_x_x_x_bach_float64_x_x_x_x_", 4229897795, 3221567534, "_x_x_x_x_bach_float64_x_x_x_x_", 1023225440, 3218269726, "_x_x_x_x_bach_float64_x_x_x_x_", 4249639586, 3221553304, "_x_x_x_x_bach_float64_x_x_x_x_", 915743776, 3218227741, "_x_x_x_x_bach_float64_x_x_x_x_", 2782962433, 3221538842, "_x_x_x_x_bach_float64_x_x_x_x_", 808262112, 3218185756, "_x_x_x_x_bach_float64_x_x_x_x_", 2996357838, 3221524152, "_x_x_x_x_bach_float64_x_x_x_x_", 700780448, 3218143771, "_x_x_x_x_bach_float64_x_x_x_x_", 3820603681, 3221509239, "_x_x_x_x_bach_float64_x_x_x_x_", 593298784, 3218101786, "_x_x_x_x_bach_float64_x_x_x_x_", 4245044733, 3221494108, "_x_x_x_x_bach_float64_x_x_x_x_", 971634240, 3218039858, "_x_x_x_x_bach_float64_x_x_x_x_", 3316899996, 3221478764, "_x_x_x_x_bach_float64_x_x_x_x_", 756670912, 3217955888, "_x_x_x_x_bach_float64_x_x_x_x_", 140564251, 3221463212, "_x_x_x_x_bach_float64_x_x_x_x_", 541707584, 3217871918, "_x_x_x_x_bach_float64_x_x_x_x_", 2466838465, 3221447455, "_x_x_x_x_bach_float64_x_x_x_x_", 326744256, 3217787948, "_x_x_x_x_bach_float64_x_x_x_x_", 922416175, 3221431500, "_x_x_x_x_bach_float64_x_x_x_x_", 111780928, 3217703978, "_x_x_x_x_bach_float64_x_x_x_x_", 3368906421, 3221415350, "_x_x_x_x_bach_float64_x_x_x_x_", 4191784896, 3217620007, "_x_x_x_x_bach_float64_x_x_x_x_", 542374441, 3221399012, "_x_x_x_x_bach_float64_x_x_x_x_", 3976821568, 3217536037, "_x_x_x_x_bach_float64_x_x_x_x_", 412353645, 3221382489, "_x_x_x_x_bach_float64_x_x_x_x_", 3761858240, 3217452067, "_x_x_x_x_bach_float64_x_x_x_x_", 2411310080, 3221365786, "_x_x_x_x_bach_float64_x_x_x_x_", 3546894912, 3217368097, "_x_x_x_x_bach_float64_x_x_x_x_", 1728872674, 3221348909, "_x_x_x_x_bach_float64_x_x_x_x_", 3331931584, 3217284127, "_x_x_x_x_bach_float64_x_x_x_x_", 2195992840, 3221331862, "_x_x_x_x_bach_float64_x_x_x_x_", 3116968256, 3217200157, "_x_x_x_x_bach_float64_x_x_x_x_", 3399295161, 3221314650, "_x_x_x_x_bach_float64_x_x_x_x_", 2902004928, 3217116187, "_x_x_x_x_bach_float64_x_x_x_x_", 680324888, 3221297279, "_x_x_x_x_bach_float64_x_x_x_x_", 2687041600, 3217032217, "_x_x_x_x_bach_float64_x_x_x_x_", 2314659620, 3221279752, "_x_x_x_x_bach_float64_x_x_x_x_", 649189248, 3216865327, "_x_x_x_x_bach_float64_x_x_x_x_", 3741343108, 3221262075, "_x_x_x_x_bach_float64_x_x_x_x_", 219262592, 3216697387, "_x_x_x_x_bach_float64_x_x_x_x_", 447019866, 3221244254, "_x_x_x_x_bach_float64_x_x_x_x_", 4084303232, 3216529446, "_x_x_x_x_bach_float64_x_x_x_x_", 850065022, 3221226292, "_x_x_x_x_bach_float64_x_x_x_x_", 3654376576, 3216361506, "_x_x_x_x_bach_float64_x_x_x_x_", 1060007627, 3221190918, "_x_x_x_x_bach_float64_x_x_x_x_", 3224449920, 3216193566, "_x_x_x_x_bach_float64_x_x_x_x_", 3108166124, 3221154463, "_x_x_x_x_bach_float64_x_x_x_x_", 2794523264, 3216025626, "_x_x_x_x_bach_float64_x_x_x_x_", 3478134121, 3221117758, "_x_x_x_x_bach_float64_x_x_x_x_", 434225920, 3215732781, "_x_x_x_x_bach_float64_x_x_x_x_", 2185796337, 3221080813, "_x_x_x_x_bach_float64_x_x_x_x_", 3869339904, 3215396900, "_x_x_x_x_bach_float64_x_x_x_x_", 3627804202, 3221043637, "_x_x_x_x_bach_float64_x_x_x_x_", 3009486592, 3215061020, "_x_x_x_x_bach_float64_x_x_x_x_", 3695075921, 3221006241, "_x_x_x_x_bach_float64_x_x_x_x_", 4299264, 3214516265, "_x_x_x_x_bach_float64_x_x_x_x_", 2656091902, 3220968635, "_x_x_x_x_bach_float64_x_x_x_x_", 864152576, 3213803569, "_x_x_x_x_bach_float64_x_x_x_x_", 860312702, 3220930829, "_x_x_x_x_bach_float64_x_x_x_x_", 3439413248, 3212083232, "_x_x_x_x_bach_float64_x_x_x_x_", 3031523473, 3220892832, "_x_x_x_x_bach_float64_x_x_x_x_", 3439413248, 1064599584, "_x_x_x_x_bach_float64_x_x_x_x_", 1086333957, 3220854656, "_x_x_x_x_bach_float64_x_x_x_x_", 864152576, 1066319921, "_x_x_x_x_bach_float64_x_x_x_x_", 4197310955, 3220816309, "_x_x_x_x_bach_float64_x_x_x_x_", 4299264, 1067032617, "_x_x_x_x_bach_float64_x_x_x_x_", 136626446, 3220777804, "_x_x_x_x_bach_float64_x_x_x_x_", 3009486592, 1067577372, "_x_x_x_x_bach_float64_x_x_x_x_", 2519044156, 3220739148, "_x_x_x_x_bach_float64_x_x_x_x_", 3869339904, 1067913252, "_x_x_x_x_bach_float64_x_x_x_x_", 3555618319, 3220700353, "_x_x_x_x_bach_float64_x_x_x_x_", 434225920, 1068249133, "_x_x_x_x_bach_float64_x_x_x_x_", 4116796652, 3220661429, "_x_x_x_x_bach_float64_x_x_x_x_", 2794523264, 1068541978, "_x_x_x_x_bach_float64_x_x_x_x_", 845843399, 3220622387, "_x_x_x_x_bach_float64_x_x_x_x_", 3224449920, 1068709918, "_x_x_x_x_bach_float64_x_x_x_x_", 3337026661, 3220583235, "_x_x_x_x_bach_float64_x_x_x_x_", 3654376576, 1068877858, "_x_x_x_x_bach_float64_x_x_x_x_", 4069158841, 3220543985, "_x_x_x_x_bach_float64_x_x_x_x_", 4084303232, 1069045798, "_x_x_x_x_bach_float64_x_x_x_x_", 4173705492, 3220504647, "_x_x_x_x_bach_float64_x_x_x_x_", 219262592, 1069213739, "_x_x_x_x_bach_float64_x_x_x_x_", 548182207, 3220465232, "_x_x_x_x_bach_float64_x_x_x_x_", 649189248, 1069381679, "_x_x_x_x_bach_float64_x_x_x_x_", 3034316470, 3220425748, "_x_x_x_x_bach_float64_x_x_x_x_", 2687041600, 1069548569, "_x_x_x_x_bach_float64_x_x_x_x_", 56596022, 3220386208, "_x_x_x_x_bach_float64_x_x_x_x_", 2902004928, 1069632539, "_x_x_x_x_bach_float64_x_x_x_x_", 1570222761, 3220346620, "_x_x_x_x_bach_float64_x_x_x_x_", 3116968256, 1069716509, "_x_x_x_x_bach_float64_x_x_x_x_", 404682446, 3220306996, "_x_x_x_x_bach_float64_x_x_x_x_", 3331931584, 1069800479, "_x_x_x_x_bach_float64_x_x_x_x_", 2326785693, 3220267345, "_x_x_x_x_bach_float64_x_x_x_x_", 3546894912, 1069884449, "_x_x_x_x_bach_float64_x_x_x_x_", 269128874, 3220227679, "_x_x_x_x_bach_float64_x_x_x_x_", 3761858240, 1069968419, "_x_x_x_x_bach_float64_x_x_x_x_", 98157494, 3220188007, "_x_x_x_x_bach_float64_x_x_x_x_", 3976821568, 1070052389, "_x_x_x_x_bach_float64_x_x_x_x_", 2570136100, 3220119783, "_x_x_x_x_bach_float64_x_x_x_x_", 4191784896, 1070136359, "_x_x_x_x_bach_float64_x_x_x_x_", 2398050580, 3220040479, "_x_x_x_x_bach_float64_x_x_x_x_", 111780928, 1070220330, "_x_x_x_x_bach_float64_x_x_x_x_", 3095717133, 3219961226, "_x_x_x_x_bach_float64_x_x_x_x_", 326744256, 1070304300, "_x_x_x_x_bach_float64_x_x_x_x_", 3867703851, 3219882045, "_x_x_x_x_bach_float64_x_x_x_x_", 541707584, 1070388270, "_x_x_x_x_bach_float64_x_x_x_x_", 3998929160, 3219802957, "_x_x_x_x_bach_float64_x_x_x_x_", 756670912, 1070472240, "_x_x_x_x_bach_float64_x_x_x_x_", 2851127428, 3219723983, "_x_x_x_x_bach_float64_x_x_x_x_", 971634240, 1070556210, "_x_x_x_x_bach_float64_x_x_x_x_", 4154274175, 3219645143, "_x_x_x_x_bach_float64_x_x_x_x_", 593298784, 1070618138, "_x_x_x_x_bach_float64_x_x_x_x_", 3118134741, 3219566459, "_x_x_x_x_bach_float64_x_x_x_x_", 700780448, 1070660123, "_x_x_x_x_bach_float64_x_x_x_x_", 3608577064, 3219487951, "_x_x_x_x_bach_float64_x_x_x_x_", 808262112, 1070702108, "_x_x_x_x_bach_float64_x_x_x_x_", 964139435, 3219409641, "_x_x_x_x_bach_float64_x_x_x_x_", 915743776, 1070744093, "_x_x_x_x_bach_float64_x_x_x_x_", 3467297664, 3219331548, "_x_x_x_x_bach_float64_x_x_x_x_", 1023225440, 1070786078, "_x_x_x_x_bach_float64_x_x_x_x_", 2276118770, 3219253695, "_x_x_x_x_bach_float64_x_x_x_x_", 1130707104, 1070828063, "_x_x_x_x_bach_float64_x_x_x_x_", 1485451248, 3219176102, "_x_x_x_x_bach_float64_x_x_x_x_", 1238188768, 1070870048, "_x_x_x_x_bach_float64_x_x_x_x_", 1886939815, 3219069260, "_x_x_x_x_bach_float64_x_x_x_x_", 1345670432, 1070912033, "_x_x_x_x_bach_float64_x_x_x_x_", 1086104652, 3218915240, "_x_x_x_x_bach_float64_x_x_x_x_", 1453152096, 1070954018, "_x_x_x_x_bach_float64_x_x_x_x_", 436367081, 3218761866, "_x_x_x_x_bach_float64_x_x_x_x_", 1560633776, 1070996003, "_x_x_x_x_bach_float64_x_x_x_x_", 4175680474, 3218609179, "_x_x_x_x_bach_float64_x_x_x_x_", 1668115424, 1071037988, "_x_x_x_x_bach_float64_x_x_x_x_", 3724906229, 3218457223, "_x_x_x_x_bach_float64_x_x_x_x_", 1775597088, 1071079973, "_x_x_x_x_bach_float64_x_x_x_x_", 3450403796, 3218306039, "_x_x_x_x_bach_float64_x_x_x_x_", 1883078752, 1071121958, "_x_x_x_x_bach_float64_x_x_x_x_", 3476942831, 3218155669, "_x_x_x_x_bach_float64_x_x_x_x_", 1990560416, 1071163943, "_x_x_x_x_bach_float64_x_x_x_x_", 3655923916, 3217932567, "_x_x_x_x_bach_float64_x_x_x_x_", 2098042096, 1071205928, "_x_x_x_x_bach_float64_x_x_x_x_", 1721581006, 3217635336, "_x_x_x_x_bach_float64_x_x_x_x_", 2205523744, 1071247913, "_x_x_x_x_bach_float64_x_x_x_x_", 1633929429, 3217339985, "_x_x_x_x_bach_float64_x_x_x_x_", 2313005408, 1071289898, "_x_x_x_x_bach_float64_x_x_x_x_", 3924949114, 3217046598, "_x_x_x_x_bach_float64_x_x_x_x_", 2420487072, 1071331883, "_x_x_x_x_bach_float64_x_x_x_x_", 1142232942, 3216479354, "_x_x_x_x_bach_float64_x_x_x_x_", 2527968736, 1071373868, "_x_x_x_x_bach_float64_x_x_x_x_", 2994906703, 3215819296, "_x_x_x_x_bach_float64_x_x_x_x_", 2635450416, 1071415853, "_x_x_x_x_bach_float64_x_x_x_x_", 1742150020, 3214408673, "_x_x_x_x_bach_float64_x_x_x_x_", 2742932064, 1071457838, "_x_x_x_x_bach_float64_x_x_x_x_", 2728174328, 1065716011, "_x_x_x_x_bach_float64_x_x_x_x_", 2850413728, 1071499823, "_x_x_x_x_bach_float64_x_x_x_x_", 2648430552, 1067883841, "_x_x_x_x_bach_float64_x_x_x_x_", 2957895392, 1071541808, "_x_x_x_x_bach_float64_x_x_x_x_", 2008250034, 1068751057, "_x_x_x_x_bach_float64_x_x_x_x_", 3065377056, 1071583793, "_x_x_x_x_bach_float64_x_x_x_x_", 918503414, 1069305615, "_x_x_x_x_bach_float64_x_x_x_x_", 3172858736, 1071625778, "_x_x_x_x_bach_float64_x_x_x_x_", 3994248156, 1069701208, "_x_x_x_x_bach_float64_x_x_x_x_", 3787653840, 1071656217, "_x_x_x_x_bach_float64_x_x_x_x_", 2698622233, 1069973128, "_x_x_x_x_bach_float64_x_x_x_x_", 1693911024, 1071677210, "_x_x_x_x_bach_float64_x_x_x_x_", 2790115815, 1070242242, "_x_x_x_x_bach_float64_x_x_x_x_", 3895135504, 1071698202, "_x_x_x_x_bach_float64_x_x_x_x_", 4154313966, 1070508466, "_x_x_x_x_bach_float64_x_x_x_x_", 1801392688, 1071719195, "_x_x_x_x_bach_float64_x_x_x_x_", 3400766017, 1070683906, "_x_x_x_x_bach_float64_x_x_x_x_", 4002617176, 1071740187, "_x_x_x_x_bach_float64_x_x_x_x_", 1145652103, 1070814003, "_x_x_x_x_bach_float64_x_x_x_x_", 1908874352, 1071761180, "_x_x_x_x_bach_float64_x_x_x_x_", 4053265296, 1070942528, "_x_x_x_x_bach_float64_x_x_x_x_", 4110098832, 1071782172, "_x_x_x_x_bach_float64_x_x_x_x_", 3769164930, 1071069441, "_x_x_x_x_bach_float64_x_x_x_x_", 2016356016, 1071803165, "_x_x_x_x_bach_float64_x_x_x_x_", 620011408, 1071194700, "_x_x_x_x_bach_float64_x_x_x_x_", 4217580496, 1071824157, "_x_x_x_x_bach_float64_x_x_x_x_", 3620745801, 1071318261, "_x_x_x_x_bach_float64_x_x_x_x_", 2123837688, 1071845150, "_x_x_x_x_bach_float64_x_x_x_x_", 416988270, 1071440085, "_x_x_x_x_bach_float64_x_x_x_x_", 30094864, 1071866143, "_x_x_x_x_bach_float64_x_x_x_x_", 241869741, 1071560128, "_x_x_x_x_bach_float64_x_x_x_x_", 2231319344, 1071887135, "_x_x_x_x_bach_float64_x_x_x_x_", 1929204461, 1071661510, "_x_x_x_x_bach_float64_x_x_x_x_", 137576528, 1071908128, "_x_x_x_x_bach_float64_x_x_x_x_", 3930807391, 1071719688, "_x_x_x_x_bach_float64_x_x_x_x_", 2338801008, 1071929120, "_x_x_x_x_bach_float64_x_x_x_x_", 2342804846, 1071776914, "_x_x_x_x_bach_float64_x_x_x_x_", 245058200, 1071950113, "_x_x_x_x_bach_float64_x_x_x_x_", 2042787694, 1071833166, "_x_x_x_x_bach_float64_x_x_x_x_", 2446282672, 1071971105, "_x_x_x_x_bach_float64_x_x_x_x_", 3687522150, 1071888423, "_x_x_x_x_bach_float64_x_x_x_x_", 352539856, 1071992098, "_x_x_x_x_bach_float64_x_x_x_x_", 3716490234, 1071942665, "_x_x_x_x_bach_float64_x_x_x_x_", 2553764336, 1072013090, "_x_x_x_x_bach_float64_x_x_x_x_", 2945356598, 1071995871, "_x_x_x_x_bach_float64_x_x_x_x_", 460021520, 1072034083, "_x_x_x_x_bach_float64_x_x_x_x_", 2274525654, 1072048020, "_x_x_x_x_bach_float64_x_x_x_x_", 2661246008, 1072055075, "_x_x_x_x_bach_float64_x_x_x_x_", 2692657398, 1072099091, "_x_x_x_x_bach_float64_x_x_x_x_", 567503184, 1072076068, "_x_x_x_x_bach_float64_x_x_x_x_", 985206996, 1072149064, "_x_x_x_x_bach_float64_x_x_x_x_", 2768727664, 1072097060, "_x_x_x_x_bach_float64_x_x_x_x_", 2622824657, 1072197917, "_x_x_x_x_bach_float64_x_x_x_x_", 674984848, 1072118053, "_x_x_x_x_bach_float64_x_x_x_x_", 290007193, 1072245631, "_x_x_x_x_bach_float64_x_x_x_x_", 2876209328, 1072139045, "_x_x_x_x_bach_float64_x_x_x_x_", 3953347547, 1072292183, "_x_x_x_x_bach_float64_x_x_x_x_", 782466520, 1072160038, "_x_x_x_x_bach_float64_x_x_x_x_", 2210297220, 1072337555, "_x_x_x_x_bach_float64_x_x_x_x_", 2983690992, 1072181030, "_x_x_x_x_bach_float64_x_x_x_x_", 947329373, 1072381725, "_x_x_x_x_bach_float64_x_x_x_x_", 889948176, 1072202023, "_x_x_x_x_bach_float64_x_x_x_x_", 1868549082, 1072424672, "_x_x_x_x_bach_float64_x_x_x_x_", 3091172656, 1072223015, "_x_x_x_x_bach_float64_x_x_x_x_", 2499128480, 1072466376, "_x_x_x_x_bach_float64_x_x_x_x_", 997429840, 1072244008, "_x_x_x_x_bach_float64_x_x_x_x_", 483697782, 1072506817, "_x_x_x_x_bach_float64_x_x_x_x_", 3198654328, 1072265000, "_x_x_x_x_bach_float64_x_x_x_x_", 2179691598, 1072545973, "_x_x_x_x_bach_float64_x_x_x_x_", 1104911504, 1072285993, "_x_x_x_x_bach_float64_x_x_x_x_", 1185911749, 1072583825, "_x_x_x_x_bach_float64_x_x_x_x_", 3306135984, 1072306985, "_x_x_x_x_bach_float64_x_x_x_x_", 4115717931, 1072620351, "_x_x_x_x_bach_float64_x_x_x_x_", 1212393168, 1072327978, "_x_x_x_x_bach_float64_x_x_x_x_", 535630236, 1072655533, "_x_x_x_x_bach_float64_x_x_x_x_", 3413617648, 1072348970, "_x_x_x_x_bach_float64_x_x_x_x_", 1623395304, 1072689348, "_x_x_x_x_bach_float64_x_x_x_x_", 1319874840, 1072369963, "_x_x_x_x_bach_float64_x_x_x_x_", 2905797354, 1072707512, "_x_x_x_x_bach_float64_x_x_x_x_", 3521099312, 1072390955, "_x_x_x_x_bach_float64_x_x_x_x_", 3690456108, 1072723023, "_x_x_x_x_bach_float64_x_x_x_x_", 1427356496, 1072411948, "_x_x_x_x_bach_float64_x_x_x_x_", 2526693462, 1072737821, "_x_x_x_x_bach_float64_x_x_x_x_", 3628580976, 1072432940, "_x_x_x_x_bach_float64_x_x_x_x_", 3145342089, 1072751895, "_x_x_x_x_bach_float64_x_x_x_x_", 1534838160, 1072453933, "_x_x_x_x_bach_float64_x_x_x_x_", 763790293, 1072765236, "_x_x_x_x_bach_float64_x_x_x_x_", 3736062648, 1072474925, "_x_x_x_x_bach_float64_x_x_x_x_", 3562455205, 1072777832, "_x_x_x_x_bach_float64_x_x_x_x_", 1642319824, 1072495918, "_x_x_x_x_bach_float64_x_x_x_x_", 2621640557, 1072789675, "_x_x_x_x_bach_float64_x_x_x_x_", 3843544304, 1072516910, "_x_x_x_x_bach_float64_x_x_x_x_", 1987928694, 1072800754, "_x_x_x_x_bach_float64_x_x_x_x_", 1749801488, 1072537903, "_x_x_x_x_bach_float64_x_x_x_x_", 1495924079, 1072811059, "_x_x_x_x_bach_float64_x_x_x_x_", 3951025968, 1072558895, "_x_x_x_x_bach_float64_x_x_x_x_", 1064825024, 1072820580, "_x_x_x_x_bach_float64_x_x_x_x_", 1857283160, 1072579888, "_x_x_x_x_bach_float64_x_x_x_x_", 700019633, 1072829307, "_x_x_x_x_bach_float64_x_x_x_x_", 4058507632, 1072600880, "_x_x_x_x_bach_float64_x_x_x_x_", 494673098, 1072837230, "_x_x_x_x_bach_float64_x_x_x_x_", 1964764816, 1072621873, "_x_x_x_x_bach_float64_x_x_x_x_", 631306228, 1072844339, "_x_x_x_x_bach_float64_x_x_x_x_", 4165989296, 1072642865, "_x_x_x_x_bach_float64_x_x_x_x_", 1383364994, 1072850624, "_x_x_x_x_bach_float64_x_x_x_x_", 2072246488, 1072663858, "_x_x_x_x_bach_float64_x_x_x_x_", 3116780970, 1072856075, "_x_x_x_x_bach_float64_x_x_x_x_", 4273470968, 1072684850, "_x_x_x_x_bach_float64_x_x_x_x_", 1996555226, 1072860683, "_x_x_x_x_bach_float64_x_x_x_x_", 3237347720, 1072699545, "_x_x_x_x_bach_float64_x_x_x_x_", 2873201968, 1072864437, "_x_x_x_x_bach_float64_x_x_x_x_", 42992664, 1072710042, "_x_x_x_x_bach_float64_x_x_x_x_", 2104411547, 1072867328, "_x_x_x_x_bach_float64_x_x_x_x_", 1143604904, 1072720538, "_x_x_x_x_bach_float64_x_x_x_x_", 441474775, 1072869346, "_x_x_x_x_bach_float64_x_x_x_x_", 2244217148, 1072731034, "_x_x_x_x_bach_float64_x_x_x_x_", 3030795510, 1072870480, "_x_x_x_x_bach_float64_x_x_x_x_", 3344829388, 1072741530, "_x_x_x_x_bach_float64_x_x_x_x_", 2235523988, 1072870722, "_x_x_x_x_bach_float64_x_x_x_x_", 150474328, 1072752027, "_x_x_x_x_bach_float64_x_x_x_x_", 3406852968, 1072870061, "_x_x_x_x_bach_float64_x_x_x_x_", 1251086568, 1072762523, "_x_x_x_x_bach_float64_x_x_x_x_", 3410663243, 1072868488, "_x_x_x_x_bach_float64_x_x_x_x_", 2351698808, 1072773019, "_x_x_x_x_bach_float64_x_x_x_x_", 3513897071, 1072865993, "_x_x_x_x_bach_float64_x_x_x_x_", 3452311052, 1072783515, "_x_x_x_x_bach_float64_x_x_x_x_", 796084466, 1072862567, "_x_x_x_x_bach_float64_x_x_x_x_", 257955996, 1072794012, "_x_x_x_x_bach_float64_x_x_x_x_", 1035695237, 1072858199, "_x_x_x_x_bach_float64_x_x_x_x_", 1358568232, 1072804508, "_x_x_x_x_bach_float64_x_x_x_x_", 1531708972, 1072852880, "_x_x_x_x_bach_float64_x_x_x_x_", 2459180472, 1072815004, "_x_x_x_x_bach_float64_x_x_x_x_", 3989945071, 1072846600, "_x_x_x_x_bach_float64_x_x_x_x_", 3559792712, 1072825500, "_x_x_x_x_bach_float64_x_x_x_x_", 1639577791, 1072839351, "_x_x_x_x_bach_float64_x_x_x_x_", 365437660, 1072835997, "_x_x_x_x_bach_float64_x_x_x_x_", 709378279, 1072831122, "_x_x_x_x_bach_float64_x_x_x_x_", 1466049900, 1072846493, "_x_x_x_x_bach_float64_x_x_x_x_", 3249239492, 1072821903, "_x_x_x_x_bach_float64_x_x_x_x_", 2566662136, 1072856989, "_x_x_x_x_bach_float64_x_x_x_x_", 2836591330, 1072811686, "_x_x_x_x_bach_float64_x_x_x_x_", 3667274376, 1072867485, "_x_x_x_x_bach_float64_x_x_x_x_", 1757640487, 1072800461, "_x_x_x_x_bach_float64_x_x_x_x_", 472919320, 1072877982, "_x_x_x_x_bach_float64_x_x_x_x_", 2418794662, 1072788218, "_x_x_x_x_bach_float64_x_x_x_x_", 1573531564, 1072888478, "_x_x_x_x_bach_float64_x_x_x_x_", 3053041953, 1072774948, "_x_x_x_x_bach_float64_x_x_x_x_", 2674143804, 1072898974, "_x_x_x_x_bach_float64_x_x_x_x_", 2016252734, 1072760642, "_x_x_x_x_bach_float64_x_x_x_x_", 3774756040, 1072909470, "_x_x_x_x_bach_float64_x_x_x_x_", 2083469150, 1072745290, "_x_x_x_x_bach_float64_x_x_x_x_", 580400984, 1072919967, "_x_x_x_x_bach_float64_x_x_x_x_", 1860280320, 1072728883, "_x_x_x_x_bach_float64_x_x_x_x_", 1681013224, 1072930463, "_x_x_x_x_bach_float64_x_x_x_x_", 79086872, 1072711412, "_x_x_x_x_bach_float64_x_x_x_x_", 2781625468, 1072940959, "_x_x_x_x_bach_float64_x_x_x_x_", 4085672694, 1072692485, "_x_x_x_x_bach_float64_x_x_x_x_", 3882237708, 1072951455, "_x_x_x_x_bach_float64_x_x_x_x_", 597884190, 1072653230, "_x_x_x_x_bach_float64_x_x_x_x_", 687882648, 1072961952, "_x_x_x_x_bach_float64_x_x_x_x_", 820691414, 1072611790, "_x_x_x_x_bach_float64_x_x_x_x_", 1788494888, 1072972448, "_x_x_x_x_bach_float64_x_x_x_x_", 3258819608, 1072568147, "_x_x_x_x_bach_float64_x_x_x_x_", 2889107128, 1072982944, "_x_x_x_x_bach_float64_x_x_x_x_", 2388235552, 1072522284, "_x_x_x_x_bach_float64_x_x_x_x_", 3989719372, 1072993440, "_x_x_x_x_bach_float64_x_x_x_x_", 1543487512, 1072474182, "_x_x_x_x_bach_float64_x_x_x_x_", 795364316, 1073003937, "_x_x_x_x_bach_float64_x_x_x_x_", 35214664, 1072423823, "_x_x_x_x_bach_float64_x_x_x_x_", 1895976552, 1073014433, "_x_x_x_x_bach_float64_x_x_x_x_", 1742465628, 1072371188, "_x_x_x_x_bach_float64_x_x_x_x_", 2996588792, 1073024929, "_x_x_x_x_bach_float64_x_x_x_x_", 2230153280, 1072316260, "_x_x_x_x_bach_float64_x_x_x_x_", 4097201032, 1073035425, "_x_x_x_x_bach_float64_x_x_x_x_", 1636285704, 1072259021, "_x_x_x_x_bach_float64_x_x_x_x_", 902845980, 1073045922, "_x_x_x_x_bach_float64_x_x_x_x_", 379300012, 1072199453, "_x_x_x_x_bach_float64_x_x_x_x_", 2003458220, 1073056418, "_x_x_x_x_bach_float64_x_x_x_x_", 3455302772, 1072137537, "_x_x_x_x_bach_float64_x_x_x_x_", 3104070456, 1073066914, "_x_x_x_x_bach_float64_x_x_x_x_", 3260445436, 1072073257, "_x_x_x_x_bach_float64_x_x_x_x_", 4204682696, 1073077410, "_x_x_x_x_bach_float64_x_x_x_x_", 1067977024, 1072006595, "_x_x_x_x_bach_float64_x_x_x_x_", 1010327640, 1073087907, "_x_x_x_x_bach_float64_x_x_x_x_", 2735464332, 1071937532, "_x_x_x_x_bach_float64_x_x_x_x_", 2110939884, 1073098403, "_x_x_x_x_bach_float64_x_x_x_x_", 1527081048, 1071866052, "_x_x_x_x_bach_float64_x_x_x_x_", 3211552124, 1073108899, "_x_x_x_x_bach_float64_x_x_x_x_", 3885540848, 1071792136, "_x_x_x_x_bach_float64_x_x_x_x_", 17197064, 1073119396, "_x_x_x_x_bach_float64_x_x_x_x_", 3664393308, 1071715768, "_x_x_x_x_bach_float64_x_x_x_x_", 1117809304, 1073129892, "_x_x_x_x_bach_float64_x_x_x_x_", 2914893648, 1071629189, "_x_x_x_x_bach_float64_x_x_x_x_", 2218421544, 1073140388, "_x_x_x_x_bach_float64_x_x_x_x_", 611683616, 1071466539, "_x_x_x_x_bach_float64_x_x_x_x_", 3319033788, 1073150884, "_x_x_x_x_bach_float64_x_x_x_x_", 2810186992, 1071298879, "_x_x_x_x_bach_float64_x_x_x_x_", 124678732, 1073161381, "_x_x_x_x_bach_float64_x_x_x_x_", 3919176952, 1071126176, "_x_x_x_x_bach_float64_x_x_x_x_", 1225290968, 1073171877, "_x_x_x_x_bach_float64_x_x_x_x_", 3253970088, 1070948396, "_x_x_x_x_bach_float64_x_x_x_x_", 2325903208, 1073182373, "_x_x_x_x_bach_float64_x_x_x_x_", 745296984, 1070765505, "_x_x_x_x_bach_float64_x_x_x_x_", 3426515448, 1073192869, "_x_x_x_x_bach_float64_x_x_x_x_", 2476092080, 1070558840, "_x_x_x_x_bach_float64_x_x_x_x_", 232160396, 1073203366, "_x_x_x_x_bach_float64_x_x_x_x_", 3220150768, 1070172408, "_x_x_x_x_bach_float64_x_x_x_x_", 1332772636, 1073213862, "_x_x_x_x_bach_float64_x_x_x_x_", 3026566528, 1069775551, "_x_x_x_x_bach_float64_x_x_x_x_", 2433384872, 1073224358, "_x_x_x_x_bach_float64_x_x_x_x_", 623884576, 1069188885, "_x_x_x_x_bach_float64_x_x_x_x_", 3533997112, 1073234854, "_x_x_x_x_bach_float64_x_x_x_x_", 515727232, 1068207195, "_x_x_x_x_bach_float64_x_x_x_x_", 339642056, 1073245351, "_x_x_x_x_bach_float64_x_x_x_x_", 844469248, 1063667843, "_x_x_x_x_bach_float64_x_x_x_x_", 1440254300, 1073255847, "_x_x_x_x_bach_float64_x_x_x_x_", 1652956800, 3215551062, "_x_x_x_x_bach_float64_x_x_x_x_", 2540866540, 1073266343, "_x_x_x_x_bach_float64_x_x_x_x_", 2897135072, 3216666787, "_x_x_x_x_bach_float64_x_x_x_x_", 3641478776, 1073276839, "_x_x_x_x_bach_float64_x_x_x_x_", 217667760, 3217309780, "_x_x_x_x_bach_float64_x_x_x_x_", 447123720, 1073287336, "_x_x_x_x_bach_float64_x_x_x_x_", 1335997120, 3217781469, "_x_x_x_x_bach_float64_x_x_x_x_", 1547735964, 1073297832, "_x_x_x_x_bach_float64_x_x_x_x_", 834800128, 3218171927, "_x_x_x_x_bach_float64_x_x_x_x_", 2648348204, 1073308328, "_x_x_x_x_bach_float64_x_x_x_x_", 3754414848, 3218418755, "_x_x_x_x_bach_float64_x_x_x_x_", 3748960444, 1073318824, "_x_x_x_x_bach_float64_x_x_x_x_", 3322521128, 3218671124, "_x_x_x_x_bach_float64_x_x_x_x_", 554605384, 1073329321, "_x_x_x_x_bach_float64_x_x_x_x_", 3509709488, 3218929065, "_x_x_x_x_bach_float64_x_x_x_x_", 1655217624, 1073339817, "_x_x_x_x_bach_float64_x_x_x_x_", 1663110712, 3219160465, "_x_x_x_x_bach_float64_x_x_x_x_", 2755829868, 1073350313, "_x_x_x_x_bach_float64_x_x_x_x_", 2704537084, 3219295055, "_x_x_x_x_bach_float64_x_x_x_x_", 3856442108, 1073360809, "_x_x_x_x_bach_float64_x_x_x_x_", 1567208160, 3219432479, "_x_x_x_x_bach_float64_x_x_x_x_", 662087052, 1073371306, "_x_x_x_x_bach_float64_x_x_x_x_", 1044844824, 3219572752, "_x_x_x_x_bach_float64_x_x_x_x_", 1762699288, 1073381802, "_x_x_x_x_bach_float64_x_x_x_x_", 3593059488, 3219715889, "_x_x_x_x_bach_float64_x_x_x_x_", 2863311528, 1073392298, "_x_x_x_x_bach_float64_x_x_x_x_", 2738151812, 3219861907, "_x_x_x_x_bach_float64_x_x_x_x_", 3963923772, 1073402794, "_x_x_x_x_bach_float64_x_x_x_x_", 255741624, 3220010821, "_x_x_x_x_bach_float64_x_x_x_x_", 769568716, 1073413291, "_x_x_x_x_bach_float64_x_x_x_x_", 1874599772, 3220162645, "_x_x_x_x_bach_float64_x_x_x_x_", 1870180956, 1073423787, "_x_x_x_x_bach_float64_x_x_x_x_", 47805828, 3220247146, "_x_x_x_x_bach_float64_x_x_x_x_", 2970793192, 1073434283, "_x_x_x_x_bach_float64_x_x_x_x_", 4275191040, 3220325991, "_x_x_x_x_bach_float64_x_x_x_x_", 4071405432, 1073444779, "_x_x_x_x_bach_float64_x_x_x_x_", 935297318, 3220406316, "_x_x_x_x_bach_float64_x_x_x_x_", 877050380, 1073455276, "_x_x_x_x_bach_float64_x_x_x_x_", 793146614, 3220488126, "_x_x_x_x_bach_float64_x_x_x_x_", 1977662620, 1073465772, "_x_x_x_x_bach_float64_x_x_x_x_", 1555204254, 3220571429, "_x_x_x_x_bach_float64_x_x_x_x_", 3078274860, 1073476268, "_x_x_x_x_bach_float64_x_x_x_x_", 753783678, 3220656233, "_x_x_x_x_bach_float64_x_x_x_x_", 4178887096, 1073486764, "_x_x_x_x_bach_float64_x_x_x_x_", 41533696, 3220742545, "_x_x_x_x_bach_float64_x_x_x_x_", 984532040, 1073497261, "_x_x_x_x_bach_float64_x_x_x_x_", 896008968, 3220830372, "_x_x_x_x_bach_float64_x_x_x_x_", 2085144284, 1073507757, "_x_x_x_x_bach_float64_x_x_x_x_", 324257716, 3220919722, "_x_x_x_x_bach_float64_x_x_x_x_", 3185756524, 1073518253, "_x_x_x_x_bach_float64_x_x_x_x_", 3747296358, 3221010601, "_x_x_x_x_bach_float64_x_x_x_x_", 4286368764, 1073528749, "_x_x_x_x_bach_float64_x_x_x_x_", 3524863586, 3221103018, "_x_x_x_x_bach_float64_x_x_x_x_", 1092013704, 1073539246, "_x_x_x_x_bach_float64_x_x_x_x_", 429864730, 3221196980, "_x_x_x_x_bach_float64_x_x_x_x_", 2192625944, 1073549742, "_x_x_x_x_bach_float64_x_x_x_x_", 1823998853, 3221258982, "_x_x_x_x_bach_float64_x_x_x_x_", 3293238188, 1073560238, "_x_x_x_x_bach_float64_x_x_x_x_" ],
									"whole_graph_data_0000000001" : [ 356312643, 3221307518, "_x_x_x_x_bach_float64_x_x_x_x_", 98883132, 1073570735, "_x_x_x_x_bach_float64_x_x_x_x_", 2374538325, 3221356836, "_x_x_x_x_bach_float64_x_x_x_x_", 1199495372, 1073581231, "_x_x_x_x_bach_float64_x_x_x_x_", 1467359577, 3221406941, "_x_x_x_x_bach_float64_x_x_x_x_", 2300107608, 1073591727, "_x_x_x_x_bach_float64_x_x_x_x_", 4019131327, 3221457835, "_x_x_x_x_bach_float64_x_x_x_x_", 3400719848, 1073602223, "_x_x_x_x_bach_float64_x_x_x_x_", 3439933514, 3221509523, "_x_x_x_x_bach_float64_x_x_x_x_", 206364796, 1073612720, "_x_x_x_x_bach_float64_x_x_x_x_", 1640273839, 3221562008, "_x_x_x_x_bach_float64_x_x_x_x_", 1306977036, 1073623216, "_x_x_x_x_bach_float64_x_x_x_x_", 441028537, 3221615293, "_x_x_x_x_bach_float64_x_x_x_x_", 2407589276, 1073633712, "_x_x_x_x_bach_float64_x_x_x_x_", 1573326808, 3221669381, "_x_x_x_x_bach_float64_x_x_x_x_", 3508201512, 1073644208, "_x_x_x_x_bach_float64_x_x_x_x_", 2383476734, 3221724276, "_x_x_x_x_bach_float64_x_x_x_x_", 313846456, 1073654705, "_x_x_x_x_bach_float64_x_x_x_x_", 127835026, 3221779982, "_x_x_x_x_bach_float64_x_x_x_x_", 1414458700, 1073665201, "_x_x_x_x_bach_float64_x_x_x_x_", 562652839, 3221836501, "_x_x_x_x_bach_float64_x_x_x_x_", 2515070940, 1073675697, "_x_x_x_x_bach_float64_x_x_x_x_", 764126959, 3221893837, "_x_x_x_x_bach_float64_x_x_x_x_", 3615683180, 1073686193, "_x_x_x_x_bach_float64_x_x_x_x_", 2013231190, 3221951993, "_x_x_x_x_bach_float64_x_x_x_x_", 421328120, 1073696690, "_x_x_x_x_bach_float64_x_x_x_x_", 1205720086, 3222010973, "_x_x_x_x_bach_float64_x_x_x_x_", 1521940360, 1073707186, "_x_x_x_x_bach_float64_x_x_x_x_", 3736978418, 3222070779, "_x_x_x_x_bach_float64_x_x_x_x_", 2622552604, 1073717682, "_x_x_x_x_bach_float64_x_x_x_x_", 2027141116, 3222131416, "_x_x_x_x_bach_float64_x_x_x_x_", 3723164844, 1073728178, "_x_x_x_x_bach_float64_x_x_x_x_", 1290862610, 3222192886, "_x_x_x_x_bach_float64_x_x_x_x_", 528809788, 1073738675, "_x_x_x_x_bach_float64_x_x_x_x_", 2357422400, 3222255192, "_x_x_x_x_bach_float64_x_x_x_x_", 2962194660, 1073745497, "_x_x_x_x_bach_float64_x_x_x_x_", 835354309, 3222296193, "_x_x_x_x_bach_float64_x_x_x_x_", 3512500780, 1073750745, "_x_x_x_x_bach_float64_x_x_x_x_", 2087056404, 3222328187, "_x_x_x_x_bach_float64_x_x_x_x_", 4062806902, 1073755993, "_x_x_x_x_bach_float64_x_x_x_x_", 3065331205, 3222360604, "_x_x_x_x_bach_float64_x_x_x_x_", 318145726, 1073761242, "_x_x_x_x_bach_float64_x_x_x_x_", 1856483120, 3222393446, "_x_x_x_x_bach_float64_x_x_x_x_", 868451846, 1073766490, "_x_x_x_x_bach_float64_x_x_x_x_", 796584567, 3222426714, "_x_x_x_x_bach_float64_x_x_x_x_", 1418757964, 1073771738, "_x_x_x_x_bach_float64_x_x_x_x_", 2176523108, 3222460409, "_x_x_x_x_bach_float64_x_x_x_x_", 1969064084, 1073776986, "_x_x_x_x_bach_float64_x_x_x_x_", 3947053248, 3222494533, "_x_x_x_x_bach_float64_x_x_x_x_", 2519370206, 1073782234, "_x_x_x_x_bach_float64_x_x_x_x_", 4013787208, 3222529088, "_x_x_x_x_bach_float64_x_x_x_x_", 3069676326, 1073787482, "_x_x_x_x_bach_float64_x_x_x_x_", 237222997, 3222564076, "_x_x_x_x_bach_float64_x_x_x_x_", 3619982446, 1073792730, "_x_x_x_x_bach_float64_x_x_x_x_", 3317678959, 3222599496, "_x_x_x_x_bach_float64_x_x_x_x_", 4170288564, 1073797978, "_x_x_x_x_bach_float64_x_x_x_x_", 2435592452, 3222635352, "_x_x_x_x_bach_float64_x_x_x_x_", 425627388, 1073803227, "_x_x_x_x_bach_float64_x_x_x_x_", 3906267195, 3222671644, "_x_x_x_x_bach_float64_x_x_x_x_", 975933510, 1073808475, "_x_x_x_x_bach_float64_x_x_x_x_", 1115148266, 3222708375, "_x_x_x_x_bach_float64_x_x_x_x_", 1526239630, 1073813723, "_x_x_x_x_bach_float64_x_x_x_x_", 287676516, 3222745545, "_x_x_x_x_bach_float64_x_x_x_x_", 2076545750, 1073818971, "_x_x_x_x_bach_float64_x_x_x_x_", 3309474578, 3222783155, "_x_x_x_x_bach_float64_x_x_x_x_", 2626851868, 1073824219, "_x_x_x_x_bach_float64_x_x_x_x_", 3431439146, 3222821208, "_x_x_x_x_bach_float64_x_x_x_x_", 3177157988, 1073829467, "_x_x_x_x_bach_float64_x_x_x_x_", 2449674348, 3222859705, "_x_x_x_x_bach_float64_x_x_x_x_", 3727464110, 1073834715, "_x_x_x_x_bach_float64_x_x_x_x_", 2115625664, 3222898647, "_x_x_x_x_bach_float64_x_x_x_x_", 4277770230, 1073839963, "_x_x_x_x_bach_float64_x_x_x_x_", 4136153028, 3222938035, "_x_x_x_x_bach_float64_x_x_x_x_", 533109054, 1073845212, "_x_x_x_x_bach_float64_x_x_x_x_", 1583673826, 3222977872, "_x_x_x_x_bach_float64_x_x_x_x_", 1083415172, 1073850460, "_x_x_x_x_bach_float64_x_x_x_x_", 371081322, 3223018158, "_x_x_x_x_bach_float64_x_x_x_x_", 1633721296, 1073855708, "_x_x_x_x_bach_float64_x_x_x_x_", 2071962025, 3223058894, "_x_x_x_x_bach_float64_x_x_x_x_", 2184027414, 1073860956, "_x_x_x_x_bach_float64_x_x_x_x_", 3920686355, 3223100082, "_x_x_x_x_bach_float64_x_x_x_x_", 2734333534, 1073866204, "_x_x_x_x_bach_float64_x_x_x_x_", 3107471582, 3223141724, "_x_x_x_x_bach_float64_x_x_x_x_", 3284639654, 1073871452, "_x_x_x_x_bach_float64_x_x_x_x_", 1073448636, 3223183821, "_x_x_x_x_bach_float64_x_x_x_x_", 3834945772, 1073876700, "_x_x_x_x_bach_float64_x_x_x_x_", 3510766366, 3223226373, "_x_x_x_x_bach_float64_x_x_x_x_", 90284600, 1073881949, "_x_x_x_x_bach_float64_x_x_x_x_", 3182830993, 3223269383, "_x_x_x_x_bach_float64_x_x_x_x_", 640590718, 1073887197, "_x_x_x_x_bach_float64_x_x_x_x_", 1399255319, 3223312852, "_x_x_x_x_bach_float64_x_x_x_x_", 1190896838, 1073892445, "_x_x_x_x_bach_float64_x_x_x_x_", 1860504553, 3223339702, "_x_x_x_x_bach_float64_x_x_x_x_", 1741202958, 1073897693, "_x_x_x_x_bach_float64_x_x_x_x_", 1390335681, 3223361897, "_x_x_x_x_bach_float64_x_x_x_x_", 2291509076, 1073902941, "_x_x_x_x_bach_float64_x_x_x_x_", 2026180130, 3223384323, "_x_x_x_x_bach_float64_x_x_x_x_", 2841815200, 1073908189, "_x_x_x_x_bach_float64_x_x_x_x_", 2188513589, 3223406981, "_x_x_x_x_bach_float64_x_x_x_x_", 3392121318, 1073913437, "_x_x_x_x_bach_float64_x_x_x_x_", 276262890, 3223429872, "_x_x_x_x_bach_float64_x_x_x_x_", 3942427438, 1073918685, "_x_x_x_x_bach_float64_x_x_x_x_", 3256810304, 3223452995, "_x_x_x_x_bach_float64_x_x_x_x_", 197766262, 1073923934, "_x_x_x_x_bach_float64_x_x_x_x_", 896261323, 3223476353, "_x_x_x_x_bach_float64_x_x_x_x_", 748072380, 1073929182, "_x_x_x_x_bach_float64_x_x_x_x_", 119256903, 3223499945, "_x_x_x_x_bach_float64_x_x_x_x_", 1298378504, 1073934430, "_x_x_x_x_bach_float64_x_x_x_x_", 3534212998, 3223523771, "_x_x_x_x_bach_float64_x_x_x_x_", 1848684622, 1073939678, "_x_x_x_x_bach_float64_x_x_x_x_", 843463934, 3223547834, "_x_x_x_x_bach_float64_x_x_x_x_", 2398990742, 1073944926, "_x_x_x_x_bach_float64_x_x_x_x_", 3203081177, 3223572132, "_x_x_x_x_bach_float64_x_x_x_x_", 2949296862, 1073950174, "_x_x_x_x_bach_float64_x_x_x_x_", 273282573, 3223596668, "_x_x_x_x_bach_float64_x_x_x_x_", 3499602980, 1073955422, "_x_x_x_x_bach_float64_x_x_x_x_", 3168189792, 3223621440, "_x_x_x_x_bach_float64_x_x_x_x_", 4049909104, 1073960670, "_x_x_x_x_bach_float64_x_x_x_x_", 1506241960, 3223646451, "_x_x_x_x_bach_float64_x_x_x_x_", 305247926, 1073965919, "_x_x_x_x_bach_float64_x_x_x_x_", 2064989807, 3223671700, "_x_x_x_x_bach_float64_x_x_x_x_", 855554046, 1073971167, "_x_x_x_x_bach_float64_x_x_x_x_", 3011382782, 3223697188, "_x_x_x_x_bach_float64_x_x_x_x_", 1405860166, 1073976415, "_x_x_x_x_bach_float64_x_x_x_x_", 2491796289, 3223722916, "_x_x_x_x_bach_float64_x_x_x_x_", 1956166284, 1073981663, "_x_x_x_x_bach_float64_x_x_x_x_", 2927093867, 3223748884, "_x_x_x_x_bach_float64_x_x_x_x_", 2506472408, 1073986911, "_x_x_x_x_bach_float64_x_x_x_x_", 2422789539, 3223775093, "_x_x_x_x_bach_float64_x_x_x_x_", 3056778526, 1073992159, "_x_x_x_x_bach_float64_x_x_x_x_", 3359081189, 3223801543, "_x_x_x_x_bach_float64_x_x_x_x_", 3607084646, 1073997407, "_x_x_x_x_bach_float64_x_x_x_x_", 3801017137, 3223828235, "_x_x_x_x_bach_float64_x_x_x_x_", 4157390766, 1074002655, "_x_x_x_x_bach_float64_x_x_x_x_", 1793566274, 3223855170, "_x_x_x_x_bach_float64_x_x_x_x_", 412729588, 1074007904, "_x_x_x_x_bach_float64_x_x_x_x_", 3951657701, 3223882347, "_x_x_x_x_bach_float64_x_x_x_x_", 963035712, 1074013152, "_x_x_x_x_bach_float64_x_x_x_x_", 3985451310, 3223909768, "_x_x_x_x_bach_float64_x_x_x_x_", 1513341830, 1074018400, "_x_x_x_x_bach_float64_x_x_x_x_", 4175283093, 3223937433, "_x_x_x_x_bach_float64_x_x_x_x_", 2063647950, 1074023648, "_x_x_x_x_bach_float64_x_x_x_x_", 2486874443, 3223965343, "_x_x_x_x_bach_float64_x_x_x_x_", 2613954070, 1074028896, "_x_x_x_x_bach_float64_x_x_x_x_", 1161379524, 3223993498, "_x_x_x_x_bach_float64_x_x_x_x_", 3164260188, 1074034144, "_x_x_x_x_bach_float64_x_x_x_x_", 2420532927, 3224021898, "_x_x_x_x_bach_float64_x_x_x_x_", 3714566312, 1074039392, "_x_x_x_x_bach_float64_x_x_x_x_", 4171799279, 3224050544, "_x_x_x_x_bach_float64_x_x_x_x_", 4264872430, 1074044640, "_x_x_x_x_bach_float64_x_x_x_x_", 8491850, 3224079438, "_x_x_x_x_bach_float64_x_x_x_x_", 520211254, 1074049889, "_x_x_x_x_bach_float64_x_x_x_x_", 684729956, 3224108578, "_x_x_x_x_bach_float64_x_x_x_x_", 1070517374, 1074055137, "_x_x_x_x_bach_float64_x_x_x_x_", 4050790337, 3224137965, "_x_x_x_x_bach_float64_x_x_x_x_", 1620823492, 1074060385, "_x_x_x_x_bach_float64_x_x_x_x_", 3643166300, 3224167601, "_x_x_x_x_bach_float64_x_x_x_x_", 2171129616, 1074065633, "_x_x_x_x_bach_float64_x_x_x_x_", 1569596079, 3224197486, "_x_x_x_x_bach_float64_x_x_x_x_", 2721435734, 1074070881, "_x_x_x_x_bach_float64_x_x_x_x_", 4214223612, 3224227619, "_x_x_x_x_bach_float64_x_x_x_x_", 3271741854, 1074076129, "_x_x_x_x_bach_float64_x_x_x_x_", 762892434, 3224258003, "_x_x_x_x_bach_float64_x_x_x_x_", 3822047974, 1074081377, "_x_x_x_x_bach_float64_x_x_x_x_", 1857983133, 3224288636, "_x_x_x_x_bach_float64_x_x_x_x_", 77386796, 1074086626, "_x_x_x_x_bach_float64_x_x_x_x_", 943841556, 3224319520, "_x_x_x_x_bach_float64_x_x_x_x_", 627692920, 1074091874, "_x_x_x_x_bach_float64_x_x_x_x_", 36718262, 3224350655, "_x_x_x_x_bach_float64_x_x_x_x_", 1177999038, 1074097122, "_x_x_x_x_bach_float64_x_x_x_x_", 2714969249, 3224376620, "_x_x_x_x_bach_float64_x_x_x_x_", 1728305158, 1074102370, "_x_x_x_x_bach_float64_x_x_x_x_", 3109602582, 3224392439, "_x_x_x_x_bach_float64_x_x_x_x_", 2278611278, 1074107618, "_x_x_x_x_bach_float64_x_x_x_x_", 36271718, 3224408385, "_x_x_x_x_bach_float64_x_x_x_x_", 2828917396, 1074112866, "_x_x_x_x_bach_float64_x_x_x_x_", 3057672734, 3224424456, "_x_x_x_x_bach_float64_x_x_x_x_", 3379223520, 1074118114, "_x_x_x_x_bach_float64_x_x_x_x_", 253002768, 3224440655, "_x_x_x_x_bach_float64_x_x_x_x_", 3929529638, 1074123362, "_x_x_x_x_bach_float64_x_x_x_x_", 1167706022, 3224456980, "_x_x_x_x_bach_float64_x_x_x_x_", 184868462, 1074128611, "_x_x_x_x_bach_float64_x_x_x_x_", 2453809498, 3224473432, "_x_x_x_x_bach_float64_x_x_x_x_", 735174582, 1074133859, "_x_x_x_x_bach_float64_x_x_x_x_", 754899637, 3224490012, "_x_x_x_x_bach_float64_x_x_x_x_", 1285480700, 1074139107, "_x_x_x_x_bach_float64_x_x_x_x_", 1296132637, 3224506719, "_x_x_x_x_bach_float64_x_x_x_x_", 1835786824, 1074144355, "_x_x_x_x_bach_float64_x_x_x_x_", 704441818, 3224523554, "_x_x_x_x_bach_float64_x_x_x_x_", 2386092942, 1074149603, "_x_x_x_x_bach_float64_x_x_x_x_", 4188484072, 3224540516, "_x_x_x_x_bach_float64_x_x_x_x_", 2936399062, 1074154851, "_x_x_x_x_bach_float64_x_x_x_x_", 4063881685, 3224557607, "_x_x_x_x_bach_float64_x_x_x_x_", 3486705182, 1074160099, "_x_x_x_x_bach_float64_x_x_x_x_", 1228137727, 3224574827, "_x_x_x_x_bach_float64_x_x_x_x_", 4037011300, 1074165347, "_x_x_x_x_bach_float64_x_x_x_x_", 865748572, 3224592175, "_x_x_x_x_bach_float64_x_x_x_x_", 292350128, 1074170596, "_x_x_x_x_bach_float64_x_x_x_x_", 3858349954, 3224609651, "_x_x_x_x_bach_float64_x_x_x_x_", 842656246, 1074175844, "_x_x_x_x_bach_float64_x_x_x_x_", 2489830957, 3224627257, "_x_x_x_x_bach_float64_x_x_x_x_", 1392962366, 1074181092, "_x_x_x_x_bach_float64_x_x_x_x_", 1921252798, 3224644992, "_x_x_x_x_bach_float64_x_x_x_x_", 1943268486, 1074186340, "_x_x_x_x_bach_float64_x_x_x_x_", 3011062500, 3224662856, "_x_x_x_x_bach_float64_x_x_x_x_", 2493574608, 1074191588, "_x_x_x_x_bach_float64_x_x_x_x_", 2315176645, 3224680850, "_x_x_x_x_bach_float64_x_x_x_x_", 3043880728, 1074196836, "_x_x_x_x_bach_float64_x_x_x_x_", 677000412, 3224698974, "_x_x_x_x_bach_float64_x_x_x_x_", 3594186846, 1074202084, "_x_x_x_x_bach_float64_x_x_x_x_", 3227512826, 3224717227, "_x_x_x_x_bach_float64_x_x_x_x_", 4144492966, 1074207332, "_x_x_x_x_bach_float64_x_x_x_x_", 2205483542, 3224735611, "_x_x_x_x_bach_float64_x_x_x_x_", 399831790, 1074212581, "_x_x_x_x_bach_float64_x_x_x_x_", 2727363278, 3224754125, "_x_x_x_x_bach_float64_x_x_x_x_", 950137912, 1074217829, "_x_x_x_x_bach_float64_x_x_x_x_", 1312534791, 3224772770, "_x_x_x_x_bach_float64_x_x_x_x_", 1500444032, 1074223077, "_x_x_x_x_bach_float64_x_x_x_x_", 3063270153, 3224791545, "_x_x_x_x_bach_float64_x_x_x_x_", 2050750150, 1074228325, "_x_x_x_x_bach_float64_x_x_x_x_", 189983156, 3224810452, "_x_x_x_x_bach_float64_x_x_x_x_", 2601056270, 1074233573, "_x_x_x_x_bach_float64_x_x_x_x_", 2076089910, 3224829489, "_x_x_x_x_bach_float64_x_x_x_x_", 3151362390, 1074238821, "_x_x_x_x_bach_float64_x_x_x_x_", 918360665, 3224848658, "_x_x_x_x_bach_float64_x_x_x_x_", 3701668512, 1074244069, "_x_x_x_x_bach_float64_x_x_x_x_", 1791781830, 3224867958, "_x_x_x_x_bach_float64_x_x_x_x_", 4251974632, 1074249317, "_x_x_x_x_bach_float64_x_x_x_x_", 1174811018, 3224887390, "_x_x_x_x_bach_float64_x_x_x_x_", 507313454, 1074254566, "_x_x_x_x_bach_float64_x_x_x_x_", 4129338509, 3224906953, "_x_x_x_x_bach_float64_x_x_x_x_", 1057619574, 1074259814, "_x_x_x_x_bach_float64_x_x_x_x_", 2825943654, 3224926649, "_x_x_x_x_bach_float64_x_x_x_x_", 1607925694, 1074265062, "_x_x_x_x_bach_float64_x_x_x_x_", 2313792136, 3224946477, "_x_x_x_x_bach_float64_x_x_x_x_", 2158231816, 1074270310, "_x_x_x_x_bach_float64_x_x_x_x_", 3340860992, 3224966437, "_x_x_x_x_bach_float64_x_x_x_x_", 2708537936, 1074275558, "_x_x_x_x_bach_float64_x_x_x_x_", 2354033352, 3224986530, "_x_x_x_x_bach_float64_x_x_x_x_", 3258844056, 1074280806, "_x_x_x_x_bach_float64_x_x_x_x_", 89128475, 3225006756, "_x_x_x_x_bach_float64_x_x_x_x_", 3809150176, 1074286054, "_x_x_x_x_bach_float64_x_x_x_x_", 1570997724, 3225027114, "_x_x_x_x_bach_float64_x_x_x_x_", 64488996, 1074291303, "_x_x_x_x_bach_float64_x_x_x_x_", 3228719266, 3225047605, "_x_x_x_x_bach_float64_x_x_x_x_", 614795120, 1074296551, "_x_x_x_x_bach_float64_x_x_x_x_", 1485629917, 3225068230, "_x_x_x_x_bach_float64_x_x_x_x_", 1165101240, 1074301799, "_x_x_x_x_bach_float64_x_x_x_x_", 1349357345, 3225088988, "_x_x_x_x_bach_float64_x_x_x_x_", 1715407360, 1074307047, "_x_x_x_x_bach_float64_x_x_x_x_", 3527016652, 3225109879, "_x_x_x_x_bach_float64_x_x_x_x_", 2265713480, 1074312295, "_x_x_x_x_bach_float64_x_x_x_x_", 130341882, 3225130905, "_x_x_x_x_bach_float64_x_x_x_x_", 2816019596, 1074317543, "_x_x_x_x_bach_float64_x_x_x_x_", 445589220, 3225152064, "_x_x_x_x_bach_float64_x_x_x_x_", 3366325720, 1074322791, "_x_x_x_x_bach_float64_x_x_x_x_", 868865959, 3225173357, "_x_x_x_x_bach_float64_x_x_x_x_", 3916631840, 1074328039, "_x_x_x_x_bach_float64_x_x_x_x_", 2086100007, 3225194784, "_x_x_x_x_bach_float64_x_x_x_x_", 171970664, 1074333288, "_x_x_x_x_bach_float64_x_x_x_x_", 483206463, 3225216346, "_x_x_x_x_bach_float64_x_x_x_x_", 722276784, 1074338536, "_x_x_x_x_bach_float64_x_x_x_x_", 1031090921, 3225238042, "_x_x_x_x_bach_float64_x_x_x_x_", 1272582900, 1074343784, "_x_x_x_x_bach_float64_x_x_x_x_", 105882296, 3225259873, "_x_x_x_x_bach_float64_x_x_x_x_", 1822889024, 1074349032, "_x_x_x_x_bach_float64_x_x_x_x_", 2668904574, 3225281838, "_x_x_x_x_bach_float64_x_x_x_x_", 2373195144, 1074354280, "_x_x_x_x_bach_float64_x_x_x_x_", 791943129, 3225303939, "_x_x_x_x_bach_float64_x_x_x_x_", 2923501264, 1074359528, "_x_x_x_x_bach_float64_x_x_x_x_", 3722119390, 3225326174, "_x_x_x_x_bach_float64_x_x_x_x_", 3473807384, 1074364776, "_x_x_x_x_bach_float64_x_x_x_x_", 3522256261, 3225348545, "_x_x_x_x_bach_float64_x_x_x_x_", 4024113500, 1074370024, "_x_x_x_x_bach_float64_x_x_x_x_", 840786240, 3225371052, "_x_x_x_x_bach_float64_x_x_x_x_", 279452328, 1074375273, "_x_x_x_x_bach_float64_x_x_x_x_", 616888941, 3225393694, "_x_x_x_x_bach_float64_x_x_x_x_", 829758448, 1074380521, "_x_x_x_x_bach_float64_x_x_x_x_", 3490661535, 3225416471, "_x_x_x_x_bach_float64_x_x_x_x_", 1380064568, 1074385769, "_x_x_x_x_bach_float64_x_x_x_x_", 2901612252, 3225429580, "_x_x_x_x_bach_float64_x_x_x_x_", 1930370688, 1074391017, "_x_x_x_x_bach_float64_x_x_x_x_", 1945897420, 3225441105, "_x_x_x_x_bach_float64_x_x_x_x_", 2480676804, 1074396265, "_x_x_x_x_bach_float64_x_x_x_x_", 1339863520, 3225452698, "_x_x_x_x_bach_float64_x_x_x_x_", 3030982928, 1074401513, "_x_x_x_x_bach_float64_x_x_x_x_", 1395859026, 3225464359, "_x_x_x_x_bach_float64_x_x_x_x_", 3581289048, 1074406761, "_x_x_x_x_bach_float64_x_x_x_x_", 2424440775, 3225476088, "_x_x_x_x_bach_float64_x_x_x_x_", 4131595168, 1074412009, "_x_x_x_x_bach_float64_x_x_x_x_", 439460498, 3225487886, "_x_x_x_x_bach_float64_x_x_x_x_", 386933992, 1074417258, "_x_x_x_x_bach_float64_x_x_x_x_", 43020594, 3225499752, "_x_x_x_x_bach_float64_x_x_x_x_", 937240108, 1074422506, "_x_x_x_x_bach_float64_x_x_x_x_", 1540626325, 3225511686, "_x_x_x_x_bach_float64_x_x_x_x_", 1487546232, 1074427754, "_x_x_x_x_bach_float64_x_x_x_x_", 941240121, 3225523689, "_x_x_x_x_bach_float64_x_x_x_x_", 2037852352, 1074433002, "_x_x_x_x_bach_float64_x_x_x_x_", 2842237785, 3225535760, "_x_x_x_x_bach_float64_x_x_x_x_", 2588158472, 1074438250, "_x_x_x_x_bach_float64_x_x_x_x_", 3249593964, 3225547900, "_x_x_x_x_bach_float64_x_x_x_x_", 3138464592, 1074443498, "_x_x_x_x_bach_float64_x_x_x_x_", 2462838707, 3225560109, "_x_x_x_x_bach_float64_x_x_x_x_", 3688770708, 1074448746, "_x_x_x_x_bach_float64_x_x_x_x_", 780145017, 3225572387, "_x_x_x_x_bach_float64_x_x_x_x_", 4239076832, 1074453994, "_x_x_x_x_bach_float64_x_x_x_x_", 2793351180, 3225584733, "_x_x_x_x_bach_float64_x_x_x_x_", 494415656, 1074459243, "_x_x_x_x_bach_float64_x_x_x_x_", 208146615, 3225597149, "_x_x_x_x_bach_float64_x_x_x_x_", 1044721776, 1074464491, "_x_x_x_x_bach_float64_x_x_x_x_", 1908898274, 3225609633, "_x_x_x_x_bach_float64_x_x_x_x_", 1595027896, 1074469739, "_x_x_x_x_bach_float64_x_x_x_x_", 3893934893, 3225622186, "_x_x_x_x_bach_float64_x_x_x_x_", 2145334012, 1074474987, "_x_x_x_x_bach_float64_x_x_x_x_", 2160504354, 3225634809, "_x_x_x_x_bach_float64_x_x_x_x_", 2695640136, 1074480235, "_x_x_x_x_bach_float64_x_x_x_x_", 1294763913, 3225647501, "_x_x_x_x_bach_float64_x_x_x_x_", 3245946256, 1074485483, "_x_x_x_x_bach_float64_x_x_x_x_", 1586933897, 3225660262, "_x_x_x_x_bach_float64_x_x_x_x_", 3796252376, 1074490731, "_x_x_x_x_bach_float64_x_x_x_x_", 3326320894, 3225673092, "_x_x_x_x_bach_float64_x_x_x_x_", 51591200, 1074495980, "_x_x_x_x_bach_float64_x_x_x_x_", 2506406272, 3225685992, "_x_x_x_x_bach_float64_x_x_x_x_", 601897320, 1074501228, "_x_x_x_x_bach_float64_x_x_x_x_", 3709804049, 3225698961, "_x_x_x_x_bach_float64_x_x_x_x_", 1152203440, 1074506476, "_x_x_x_x_bach_float64_x_x_x_x_", 2928447751, 3225712000, "_x_x_x_x_bach_float64_x_x_x_x_", 1702509560, 1074511724, "_x_x_x_x_bach_float64_x_x_x_x_", 448548413, 3225725109, "_x_x_x_x_bach_float64_x_x_x_x_", 2252815680, 1074516972, "_x_x_x_x_bach_float64_x_x_x_x_", 850650770, 3225738287, "_x_x_x_x_bach_float64_x_x_x_x_", 2803121800, 1074522220, "_x_x_x_x_bach_float64_x_x_x_x_", 124787619, 3225751535, "_x_x_x_x_bach_float64_x_x_x_x_", 3353427920, 1074527468, "_x_x_x_x_bach_float64_x_x_x_x_", 2850405314, 3225764852, "_x_x_x_x_bach_float64_x_x_x_x_", 3903734040, 1074532716, "_x_x_x_x_bach_float64_x_x_x_x_", 721583639, 3225778240, "_x_x_x_x_bach_float64_x_x_x_x_", 159072864, 1074537965, "_x_x_x_x_bach_float64_x_x_x_x_", 2611863296, 3225791697, "_x_x_x_x_bach_float64_x_x_x_x_", 709378984, 1074543213, "_x_x_x_x_bach_float64_x_x_x_x_", 214563977, 3225805225, "_x_x_x_x_bach_float64_x_x_x_x_", 1259685104, 1074548461, "_x_x_x_x_bach_float64_x_x_x_x_", 2402579226, 3225818822, "_x_x_x_x_bach_float64_x_x_x_x_", 1809991224, 1074553709, "_x_x_x_x_bach_float64_x_x_x_x_", 868694570, 3225832490, "_x_x_x_x_bach_float64_x_x_x_x_", 2360297344, 1074558957, "_x_x_x_x_bach_float64_x_x_x_x_", 190415141, 3225846228, "_x_x_x_x_bach_float64_x_x_x_x_", 2910603464, 1074564205, "_x_x_x_x_bach_float64_x_x_x_x_", 650153037, 3225860036, "_x_x_x_x_bach_float64_x_x_x_x_", 3460909584, 1074569453, "_x_x_x_x_bach_float64_x_x_x_x_", 2530251194, 3225873914, "_x_x_x_x_bach_float64_x_x_x_x_", 4011215704, 1074574701, "_x_x_x_x_bach_float64_x_x_x_x_", 1818072659, 3225887863, "_x_x_x_x_bach_float64_x_x_x_x_", 266554528, 1074579950, "_x_x_x_x_bach_float64_x_x_x_x_", 3090959055, 3225901882, "_x_x_x_x_bach_float64_x_x_x_x_", 816860648, 1074585198, "_x_x_x_x_bach_float64_x_x_x_x_", 2336417969, 3225915972, "_x_x_x_x_bach_float64_x_x_x_x_", 1367166768, 1074590446, "_x_x_x_x_bach_float64_x_x_x_x_", 4132048700, 3225930132, "_x_x_x_x_bach_float64_x_x_x_x_", 1917472888, 1074595694, "_x_x_x_x_bach_float64_x_x_x_x_", 170762320, 3225944364, "_x_x_x_x_bach_float64_x_x_x_x_", 2467779008, 1074600942, "_x_x_x_x_bach_float64_x_x_x_x_", 3620576570, 3225958665, "_x_x_x_x_bach_float64_x_x_x_x_", 3018085128, 1074606190, "_x_x_x_x_bach_float64_x_x_x_x_", 1880032099, 3225973038, "_x_x_x_x_bach_float64_x_x_x_x_", 3568391248, 1074611438, "_x_x_x_x_bach_float64_x_x_x_x_", 3822889185, 3225987481, "_x_x_x_x_bach_float64_x_x_x_x_", 4118697368, 1074616686, "_x_x_x_x_bach_float64_x_x_x_x_", 1143478498, 3226001996, "_x_x_x_x_bach_float64_x_x_x_x_", 374036192, 1074621935, "_x_x_x_x_bach_float64_x_x_x_x_", 2716495849, 3226016581, "_x_x_x_x_bach_float64_x_x_x_x_", 924342312, 1074627183, "_x_x_x_x_bach_float64_x_x_x_x_", 237320157, 3226031238, "_x_x_x_x_bach_float64_x_x_x_x_", 1474648432, 1074632431, "_x_x_x_x_bach_float64_x_x_x_x_", 2581808086, 3226045965, "_x_x_x_x_bach_float64_x_x_x_x_", 2024954552, 1074637679, "_x_x_x_x_bach_float64_x_x_x_x_", 1446611908, 3226060764, "_x_x_x_x_bach_float64_x_x_x_x_", 2575260672, 1074642927, "_x_x_x_x_bach_float64_x_x_x_x_", 1414006705, 3226075634, "_x_x_x_x_bach_float64_x_x_x_x_", 3125566792, 1074648175, "_x_x_x_x_bach_float64_x_x_x_x_", 2772077279, 3226090575, "_x_x_x_x_bach_float64_x_x_x_x_", 3675872912, 1074653423, "_x_x_x_x_bach_float64_x_x_x_x_", 1514774143, 3226105588, "_x_x_x_x_bach_float64_x_x_x_x_", 4226179032, 1074658671, "_x_x_x_x_bach_float64_x_x_x_x_", 2226871327, 3226120672, "_x_x_x_x_bach_float64_x_x_x_x_", 481517856, 1074663920, "_x_x_x_x_bach_float64_x_x_x_x_", 904153019, 3226135828, "_x_x_x_x_bach_float64_x_x_x_x_", 1031823976, 1074669168, "_x_x_x_x_bach_float64_x_x_x_x_", 2133338484, 3226151055, "_x_x_x_x_bach_float64_x_x_x_x_", 1582130096, 1074674416, "_x_x_x_x_bach_float64_x_x_x_x_", 1912268508, 3226166354, "_x_x_x_x_bach_float64_x_x_x_x_", 2132436216, 1074679664, "_x_x_x_x_bach_float64_x_x_x_x_", 534862819, 3226181725, "_x_x_x_x_bach_float64_x_x_x_x_", 2682742336, 1074684912, "_x_x_x_x_bach_float64_x_x_x_x_", 2591175491, 3226197167, "_x_x_x_x_bach_float64_x_x_x_x_", 3233048456, 1074690160, "_x_x_x_x_bach_float64_x_x_x_x_", 4082548366, 3226212681, "_x_x_x_x_bach_float64_x_x_x_x_", 3783354576, 1074695408, "_x_x_x_x_bach_float64_x_x_x_x_", 1011600810, 3226228268, "_x_x_x_x_bach_float64_x_x_x_x_", 38693400, 1074700657, "_x_x_x_x_bach_float64_x_x_x_x_", 2267186656, 3226243926, "_x_x_x_x_bach_float64_x_x_x_x_", 588999520, 1074705905, "_x_x_x_x_bach_float64_x_x_x_x_", 3854645338, 3226259656, "_x_x_x_x_bach_float64_x_x_x_x_", 1139305640, 1074711153, "_x_x_x_x_bach_float64_x_x_x_x_", 1780758555, 3226275459, "_x_x_x_x_bach_float64_x_x_x_x_", 1689611760, 1074716401, "_x_x_x_x_bach_float64_x_x_x_x_", 643739494, 3226291334, "_x_x_x_x_bach_float64_x_x_x_x_", 2239917880, 1074721649, "_x_x_x_x_bach_float64_x_x_x_x_", 748385419, 3226307281, "_x_x_x_x_bach_float64_x_x_x_x_", 2790224000, 1074726897, "_x_x_x_x_bach_float64_x_x_x_x_", 2401099295, 3226323300, "_x_x_x_x_bach_float64_x_x_x_x_", 3340530120, 1074732145, "_x_x_x_x_bach_float64_x_x_x_x_", 1614976655, 3226339392, "_x_x_x_x_bach_float64_x_x_x_x_", 3890836240, 1074737393, "_x_x_x_x_bach_float64_x_x_x_x_", 2994761485, 3226355556, "_x_x_x_x_bach_float64_x_x_x_x_", 146175064, 1074742642, "_x_x_x_x_bach_float64_x_x_x_x_", 2557030864, 3226371793, "_x_x_x_x_bach_float64_x_x_x_x_", 696481184, 1074747890, "_x_x_x_x_bach_float64_x_x_x_x_", 615150506, 3226388103, "_x_x_x_x_bach_float64_x_x_x_x_", 1246787304, 1074753138, "_x_x_x_x_bach_float64_x_x_x_x_", 1779328221, 3226404485, "_x_x_x_x_bach_float64_x_x_x_x_", 1797093424, 1074758386, "_x_x_x_x_bach_float64_x_x_x_x_", 2071765308, 3226420940, "_x_x_x_x_bach_float64_x_x_x_x_", 2347399544, 1074763634, "_x_x_x_x_bach_float64_x_x_x_x_", 1811611526, 3226437468, "_x_x_x_x_bach_float64_x_x_x_x_", 2897705664, 1074768882, "_x_x_x_x_bach_float64_x_x_x_x_", 1320050689, 3226454069, "_x_x_x_x_bach_float64_x_x_x_x_", 3448011784, 1074774130, "_x_x_x_x_bach_float64_x_x_x_x_", 2607660319, 3226469547, "_x_x_x_x_bach_float64_x_x_x_x_", 3998317904, 1074779378, "_x_x_x_x_bach_float64_x_x_x_x_", 468964620, 3226477921, "_x_x_x_x_bach_float64_x_x_x_x_", 253656728, 1074784627, "_x_x_x_x_bach_float64_x_x_x_x_", 850189804, 3226486331, "_x_x_x_x_bach_float64_x_x_x_x_", 803962848, 1074789875, "_x_x_x_x_bach_float64_x_x_x_x_", 3916258236, 3226494777, "_x_x_x_x_bach_float64_x_x_x_x_", 2824618132, 1074792761, "_x_x_x_x_bach_float64_x_x_x_x_", 1243305352, 3226503261, "_x_x_x_x_bach_float64_x_x_x_x_", 3099771192, 1074795385, "_x_x_x_x_bach_float64_x_x_x_x_", 1588509222, 3226511781, "_x_x_x_x_bach_float64_x_x_x_x_", 3374924252, 1074798009, "_x_x_x_x_bach_float64_x_x_x_x_", 825345163, 3226520338, "_x_x_x_x_bach_float64_x_x_x_x_", 3650077312, 1074800633, "_x_x_x_x_bach_float64_x_x_x_x_", 3418447763, 3226528931, "_x_x_x_x_bach_float64_x_x_x_x_", 3925230372, 1074803257, "_x_x_x_x_bach_float64_x_x_x_x_", 948799837, 3226537562, "_x_x_x_x_bach_float64_x_x_x_x_", 4200383432, 1074805881, "_x_x_x_x_bach_float64_x_x_x_x_", 2178528811, 3226546229, "_x_x_x_x_bach_float64_x_x_x_x_", 180569196, 1074808506, "_x_x_x_x_bach_float64_x_x_x_x_", 2986160819, 3226554933, "_x_x_x_x_bach_float64_x_x_x_x_", 455722256, 1074811130, "_x_x_x_x_bach_float64_x_x_x_x_", 3546514946, 3226563674, "_x_x_x_x_bach_float64_x_x_x_x_", 730875316, 1074813754, "_x_x_x_x_bach_float64_x_x_x_x_", 4035760841, 3226572452, "_x_x_x_x_bach_float64_x_x_x_x_", 1006028376, 1074816378, "_x_x_x_x_bach_float64_x_x_x_x_", 336476202, 3226581268, "_x_x_x_x_bach_float64_x_x_x_x_", 1281181436, 1074819002, "_x_x_x_x_bach_float64_x_x_x_x_", 1217540606, 3226590120, "_x_x_x_x_bach_float64_x_x_x_x_", 1556334496, 1074821626, "_x_x_x_x_bach_float64_x_x_x_x_", 2564356233, 3226599009, "_x_x_x_x_bach_float64_x_x_x_x_", 1831487556, 1074824250, "_x_x_x_x_bach_float64_x_x_x_x_", 263774115, 3226607936, "_x_x_x_x_bach_float64_x_x_x_x_", 2106640616, 1074826874, "_x_x_x_x_bach_float64_x_x_x_x_", 3089020238, 3226616899, "_x_x_x_x_bach_float64_x_x_x_x_", 2381793676, 1074829498, "_x_x_x_x_bach_float64_x_x_x_x_", 2634948535, 3226625900, "_x_x_x_x_bach_float64_x_x_x_x_", 2656946736, 1074832122, "_x_x_x_x_bach_float64_x_x_x_x_", 3382835879, 3226634938, "_x_x_x_x_bach_float64_x_x_x_x_", 2932099796, 1074834746, "_x_x_x_x_bach_float64_x_x_x_x_", 1225569365, 3226644014, "_x_x_x_x_bach_float64_x_x_x_x_", 3207252856, 1074837370, "_x_x_x_x_bach_float64_x_x_x_x_", 647539102, 3226653127, "_x_x_x_x_bach_float64_x_x_x_x_", 3482405916, 1074839994, "_x_x_x_x_bach_float64_x_x_x_x_", 1839759783, 3226662277, "_x_x_x_x_bach_float64_x_x_x_x_", 3757558976, 1074842618, "_x_x_x_x_bach_float64_x_x_x_x_", 699893972, 3226671465, "_x_x_x_x_bach_float64_x_x_x_x_", 4032712036, 1074845242, "_x_x_x_x_bach_float64_x_x_x_x_", 1717177125, 3226680690, "_x_x_x_x_bach_float64_x_x_x_x_", 12897800, 1074847867, "_x_x_x_x_bach_float64_x_x_x_x_", 792571378, 3226689953, "_x_x_x_x_bach_float64_x_x_x_x_", 288050860, 1074850491, "_x_x_x_x_bach_float64_x_x_x_x_", 2418657522, 3226699253, "_x_x_x_x_bach_float64_x_x_x_x_", 563203920, 1074853115, "_x_x_x_x_bach_float64_x_x_x_x_", 2499788462, 3226708591, "_x_x_x_x_bach_float64_x_x_x_x_", 838356980, 1074855739, "_x_x_x_x_bach_float64_x_x_x_x_", 1237013557, 3226717967, "_x_x_x_x_bach_float64_x_x_x_x_", 1113510040, 1074858363, "_x_x_x_x_bach_float64_x_x_x_x_", 3128100912, 3226727380, "_x_x_x_x_bach_float64_x_x_x_x_", 1388663100, 1074860987, "_x_x_x_x_bach_float64_x_x_x_x_", 4082657599, 3226736831, "_x_x_x_x_bach_float64_x_x_x_x_", 1663816160, 1074863611, "_x_x_x_x_bach_float64_x_x_x_x_", 12086189, 3226746321, "_x_x_x_x_bach_float64_x_x_x_x_", 1938969220, 1074866235, "_x_x_x_x_bach_float64_x_x_x_x_", 4009475682, 3226755847, "_x_x_x_x_bach_float64_x_x_x_x_", 2214122280, 1074868859, "_x_x_x_x_bach_float64_x_x_x_x_", 3399950130, 3226765412, "_x_x_x_x_bach_float64_x_x_x_x_", 2489275340, 1074871483, "_x_x_x_x_bach_float64_x_x_x_x_", 2690362975, 3226775015, "_x_x_x_x_bach_float64_x_x_x_x_", 2764428400, 1074874107, "_x_x_x_x_bach_float64_x_x_x_x_", 2094481776, 3226784656, "_x_x_x_x_bach_float64_x_x_x_x_", 3039581460, 1074876731, "_x_x_x_x_bach_float64_x_x_x_x_", 1827976518, 3226794335, "_x_x_x_x_bach_float64_x_x_x_x_", 3314734520, 1074879355, "_x_x_x_x_bach_float64_x_x_x_x_", 2108440435, 3226804052, "_x_x_x_x_bach_float64_x_x_x_x_", 3589887580, 1074881979, "_x_x_x_x_bach_float64_x_x_x_x_", 3155410637, 3226813807, "_x_x_x_x_bach_float64_x_x_x_x_", 3865040640, 1074884603, "_x_x_x_x_bach_float64_x_x_x_x_", 895421251, 3226823601, "_x_x_x_x_bach_float64_x_x_x_x_", 4140193700, 1074887227, "_x_x_x_x_bach_float64_x_x_x_x_", 4141892845, 3226833432, "_x_x_x_x_bach_float64_x_x_x_x_", 120379464, 1074889852, "_x_x_x_x_bach_float64_x_x_x_x_", 235414097, 3226843303, "_x_x_x_x_bach_float64_x_x_x_x_", 395532524, 1074892476, "_x_x_x_x_bach_float64_x_x_x_x_", 2288401890, 3226853211, "_x_x_x_x_bach_float64_x_x_x_x_", 670685584, 1074895100, "_x_x_x_x_bach_float64_x_x_x_x_", 1940480693, 3226863158, "_x_x_x_x_bach_float64_x_x_x_x_", 945838644, 1074897724, "_x_x_x_x_bach_float64_x_x_x_x_", 3718240358, 3226873143, "_x_x_x_x_bach_float64_x_x_x_x_", 1220991704, 1074900348, "_x_x_x_x_bach_float64_x_x_x_x_", 3560418865, 3226883167, "_x_x_x_x_bach_float64_x_x_x_x_", 1496144764, 1074902972, "_x_x_x_x_bach_float64_x_x_x_x_", 1702823229, 3226893230, "_x_x_x_x_bach_float64_x_x_x_x_", 1771297824, 1074905596, "_x_x_x_x_bach_float64_x_x_x_x_", 2678348297, 3226903331, "_x_x_x_x_bach_float64_x_x_x_x_", 2046450884, 1074908220, "_x_x_x_x_bach_float64_x_x_x_x_", 2432093460, 3226913471, "_x_x_x_x_bach_float64_x_x_x_x_", 2321603944, 1074910844, "_x_x_x_x_bach_float64_x_x_x_x_", 1206282916, 3226923650, "_x_x_x_x_bach_float64_x_x_x_x_", 2596757004, 1074913468, "_x_x_x_x_bach_float64_x_x_x_x_", 3540283831, 3226933867, "_x_x_x_x_bach_float64_x_x_x_x_", 2871910064, 1074916092, "_x_x_x_x_bach_float64_x_x_x_x_", 1090755100, 3226944124, "_x_x_x_x_bach_float64_x_x_x_x_", 3147063124, 1074918716, "_x_x_x_x_bach_float64_x_x_x_x_", 2696436144, 3226954419, "_x_x_x_x_bach_float64_x_x_x_x_", 3422216184, 1074921340, "_x_x_x_x_bach_float64_x_x_x_x_", 18426044, 3226964754, "_x_x_x_x_bach_float64_x_x_x_x_", 3697369244, 1074923964, "_x_x_x_x_bach_float64_x_x_x_x_", 1899939186, 3226975127, "_x_x_x_x_bach_float64_x_x_x_x_", 3972522304, 1074926588, "_x_x_x_x_bach_float64_x_x_x_x_", 6583950, 3226985540, "_x_x_x_x_bach_float64_x_x_x_x_", 4247675364, 1074929212, "_x_x_x_x_bach_float64_x_x_x_x_", 3186117903, 3226995991, "_x_x_x_x_bach_float64_x_x_x_x_", 227861128, 1074931837, "_x_x_x_x_bach_float64_x_x_x_x_", 3108726034, 3227006482, "_x_x_x_x_bach_float64_x_x_x_x_", 503014188, 1074934461, "_x_x_x_x_bach_float64_x_x_x_x_", 36840892, 3227017013, "_x_x_x_x_bach_float64_x_x_x_x_", 778167248, 1074937085, "_x_x_x_x_bach_float64_x_x_x_x_", 2825158732, 3227027582, "_x_x_x_x_bach_float64_x_x_x_x_", 1053320308, 1074939709, "_x_x_x_x_bach_float64_x_x_x_x_", 3150851632, 3227038191, "_x_x_x_x_bach_float64_x_x_x_x_", 1328473368, 1074942333, "_x_x_x_x_bach_float64_x_x_x_x_", 1283386947, 3227048840, "_x_x_x_x_bach_float64_x_x_x_x_", 1603626428, 1074944957, "_x_x_x_x_bach_float64_x_x_x_x_", 1789575441, 3227059528, "_x_x_x_x_bach_float64_x_x_x_x_", 1878779488, 1074947581, "_x_x_x_x_bach_float64_x_x_x_x_", 648684594, 3227070256, "_x_x_x_x_bach_float64_x_x_x_x_", 2153932548, 1074950205, "_x_x_x_x_bach_float64_x_x_x_x_", 2432322737, 3227081023, "_x_x_x_x_bach_float64_x_x_x_x_", 2429085608, 1074952829, "_x_x_x_x_bach_float64_x_x_x_x_", 3124584588, 3227091830, "_x_x_x_x_bach_float64_x_x_x_x_", 2704238668, 1074955453, "_x_x_x_x_bach_float64_x_x_x_x_", 3006967606, 3227102677, "_x_x_x_x_bach_float64_x_x_x_x_", 2979391728, 1074958077, "_x_x_x_x_bach_float64_x_x_x_x_", 2363418922, 3227113564, "_x_x_x_x_bach_float64_x_x_x_x_", 3254544788, 1074960701, "_x_x_x_x_bach_float64_x_x_x_x_", 1480349321, 3227124491, "_x_x_x_x_bach_float64_x_x_x_x_", 3529697848, 1074963325, "_x_x_x_x_bach_float64_x_x_x_x_", 646646979, 3227135458, "_x_x_x_x_bach_float64_x_x_x_x_", 3804850908, 1074965949, "_x_x_x_x_bach_float64_x_x_x_x_", 153690943, 3227146465, "_x_x_x_x_bach_float64_x_x_x_x_", 4080003968, 1074968573, "_x_x_x_x_bach_float64_x_x_x_x_", 295364375, 3227157512, "_x_x_x_x_bach_float64_x_x_x_x_", 60189732, 1074971198, "_x_x_x_x_bach_float64_x_x_x_x_", 1368067532, 3227168599, "_x_x_x_x_bach_float64_x_x_x_x_", 335342792, 1074973822, "_x_x_x_x_bach_float64_x_x_x_x_", 3670730501, 3227179726, "_x_x_x_x_bach_float64_x_x_x_x_", 610495852, 1074976446, "_x_x_x_x_bach_float64_x_x_x_x_", 3209858386, 3227190894, "_x_x_x_x_bach_float64_x_x_x_x_", 885648912, 1074979070, "_x_x_x_x_bach_float64_x_x_x_x_", 289478122, 3227202103, "_x_x_x_x_bach_float64_x_x_x_x_", 1160801972, 1074981694, "_x_x_x_x_bach_float64_x_x_x_x_", 3806117738, 3227213351, "_x_x_x_x_bach_float64_x_x_x_x_", 1435955032, 1074984318, "_x_x_x_x_bach_float64_x_x_x_x_", 1184047004, 3227224641, "_x_x_x_x_bach_float64_x_x_x_x_", 1711108092, 1074986942, "_x_x_x_x_bach_float64_x_x_x_x_", 1324961842, 3227235971, "_x_x_x_x_bach_float64_x_x_x_x_", 1986261152, 1074989566, "_x_x_x_x_bach_float64_x_x_x_x_", 248257145, 3227247342, "_x_x_x_x_bach_float64_x_x_x_x_", 2261414212, 1074992190, "_x_x_x_x_bach_float64_x_x_x_x_", 2565874205, 3227258753, "_x_x_x_x_bach_float64_x_x_x_x_", 2536567272, 1074994814, "_x_x_x_x_bach_float64_x_x_x_x_", 7474892, 3227270206, "_x_x_x_x_bach_float64_x_x_x_x_", 2811720332, 1074997438, "_x_x_x_x_bach_float64_x_x_x_x_", 1485223141, 3227281699, "_x_x_x_x_bach_float64_x_x_x_x_", 3086873392, 1075000062, "_x_x_x_x_bach_float64_x_x_x_x_", 3029024027, 3227293233, "_x_x_x_x_bach_float64_x_x_x_x_", 3362026452, 1075002686, "_x_x_x_x_bach_float64_x_x_x_x_", 671435528, 3227304809, "_x_x_x_x_bach_float64_x_x_x_x_", 3637179512, 1075005310, "_x_x_x_x_bach_float64_x_x_x_x_", 3332580034, 3227316425, "_x_x_x_x_bach_float64_x_x_x_x_", 3912332572, 1075007934, "_x_x_x_x_bach_float64_x_x_x_x_", 2755382620, 3227328083, "_x_x_x_x_bach_float64_x_x_x_x_", 4187485632, 1075010558, "_x_x_x_x_bach_float64_x_x_x_x_", 3570351195, 3227339782, "_x_x_x_x_bach_float64_x_x_x_x_", 167671396, 1075013183, "_x_x_x_x_bach_float64_x_x_x_x_", 1820748841, 3227351523, "_x_x_x_x_bach_float64_x_x_x_x_", 442824456, 1075015807, "_x_x_x_x_bach_float64_x_x_x_x_", 2142471534, 3227363305, "_x_x_x_x_bach_float64_x_x_x_x_", 717977516, 1075018431, "_x_x_x_x_bach_float64_x_x_x_x_", 584187232, 3227375129, "_x_x_x_x_bach_float64_x_x_x_x_", 993130576, 1075021055, "_x_x_x_x_bach_float64_x_x_x_x_", 1787213060, 3227386994, "_x_x_x_x_bach_float64_x_x_x_x_", 1268283636, 1075023679, "_x_x_x_x_bach_float64_x_x_x_x_", 1805653858, 3227398901, "_x_x_x_x_bach_float64_x_x_x_x_", 1543436696, 1075026303, "_x_x_x_x_bach_float64_x_x_x_x_", 991311520, 3227410850, "_x_x_x_x_bach_float64_x_x_x_x_", 1818589756, 1075028927, "_x_x_x_x_bach_float64_x_x_x_x_", 3993692175, 3227422840, "_x_x_x_x_bach_float64_x_x_x_x_", 2093742816, 1075031551, "_x_x_x_x_bach_float64_x_x_x_x_", 2580143921, 3227434873, "_x_x_x_x_bach_float64_x_x_x_x_", 2368895876, 1075034175, "_x_x_x_x_bach_float64_x_x_x_x_", 1405667221, 3227446948, "_x_x_x_x_bach_float64_x_x_x_x_", 2644048936, 1075036799, "_x_x_x_x_bach_float64_x_x_x_x_", 833052086, 3227459065, "_x_x_x_x_bach_float64_x_x_x_x_", 2919201996, 1075039423, "_x_x_x_x_bach_float64_x_x_x_x_", 1227851448, 3227471224, "_x_x_x_x_bach_float64_x_x_x_x_", 3194355056, 1075042047, "_x_x_x_x_bach_float64_x_x_x_x_", 2958386967, 3227483425, "_x_x_x_x_bach_float64_x_x_x_x_", 3469508116, 1075044671, "_x_x_x_x_bach_float64_x_x_x_x_", 2100787258, 3227495669, "_x_x_x_x_bach_float64_x_x_x_x_", 3744661176, 1075047295, "_x_x_x_x_bach_float64_x_x_x_x_", 3323895031, 3227507955, "_x_x_x_x_bach_float64_x_x_x_x_", 4019814236, 1075049919, "_x_x_x_x_bach_float64_x_x_x_x_", 1354701440, 3227518606, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075052544, "_x_x_x_x_bach_float64_x_x_x_x_", 318379927, 3227524792 ],
									"whole_graph_data_count" : [ 2 ]
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
									"patching_rect" : [ 491.5, 141.0, 20.0, 20.0 ],
									"rounded" : 60.0,
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
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
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
					"patching_rect" : [ 10.0, 85.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
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
							"major" : 8,
							"minor" : 1,
							"revision" : 11,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
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
						"assistshowspatchername" : 0,
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
						"tags" : ""
					}
,
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
