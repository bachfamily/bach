{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 6,
			"architecture" : "x86"
		}
,
		"rect" : [ 76.0, 44.0, 985.0, 458.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"boxes" : [ 			{
				"box" : 				{
					"embed" : 1,
					"enablevscroll" : 1,
					"id" : "obj-22",
					"maxclass" : "bpatcher",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 6,
							"architecture" : "x86"
						}
,
						"rect" : [ 78.0, 88.0, 969.0, 372.0 ],
						"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 550.5, 59.0, 94.0, 25.0 ],
									"text" : "bang to go"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-39",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 703.0, 471.0, 128.0, 21.0 ],
									"text" : "bach.help.searchtag"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-38",
									"linecount" : 17,
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 703.0, 213.0, 255.0, 253.0 ],
									"text" : "bach is capable to deal with rhythmic trees, as OM. Yet it does it in a VERY different way. If you want to know more, see the \"Beams Through The Trees\" tutorials.\nThe standard rhythm input expected by bach is simply a plain list of durations. In this example we input the Measureinfo (essentially the time signature, but could involve tempi and much more: see #measureinfo), and then a list of duration, having one level for each voice and one level for each measure.\nIndeed, differently from OM, bach.score expect one level of parenthesis for each measure. If you don't want that, have a look at bach.beatbox and bach.beatunbox."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 686.0, 106.0, 99.0, 21.0 ],
									"text" : "loadmess set 8"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 574.0, 106.0, 99.0, 21.0 ],
									"text" : "loadmess set 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 526.0, 428.0, 82.0, 21.0 ],
									"text" : "bach.wrap 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 526.0, 398.0, 52.0, 21.0 ],
									"text" : "pack i i"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 10.0,
									"frgb" : 0.0,
									"id" : "obj-31",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 554.0, 302.0, 19.0, 18.0 ],
									"text" : "B"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-30",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "int", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 647.0, 271.0, 53.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"linecount" : 3,
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 573.0, 302.0, 101.0, 50.0 ],
									"text" : "bach.repeat 3 @inwrap 1 @outwrap 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 10.0,
									"frgb" : 0.0,
									"id" : "obj-25",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 767.0, 183.0, 19.0, 18.0 ],
									"text" : "D"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 10.0,
									"frgb" : 0.0,
									"id" : "obj-23",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 485.0, 142.0, 19.0, 18.0 ],
									"text" : "C"
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"frgb" : 0.0,
									"id" : "obj-21",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 117.0, 51.0, 87.0, 20.0 ],
									"text" : "Time signature"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "bang", "int", "bang", "int" ],
									"patching_rect" : [ 506.0, 183.0, 92.0, 21.0 ],
									"text" : "t b i b i"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 573.0, 224.0, 62.0, 21.0 ],
									"saved_object_attributes" : 									{
										"embed" : 0
									}
,
									"text" : "bach.reg"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "bang" ],
									"patching_rect" : [ 506.0, 102.0, 37.0, 21.0 ],
									"text" : "t b b"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 506.0, 51.0, 37.0, 37.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 668.0, 183.0, 100.0, 21.0 ],
									"text" : "bach.expr 1/$i1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 573.0, 251.0, 80.0, 21.0 ],
									"text" : "bach.repeat"
								}

							}
, 							{
								"box" : 								{
									"constraintbeamsinspaces" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-3",
									"loop" : [ "(", 1, 1, 0, ")", "(", 1, 1, 0, ")" ],
									"maxclass" : "bach.score",
									"numinlets" : 7,
									"numoutlets" : 9,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
									"patching_rect" : [ 499.0, 471.0, 346.0, 95.0 ],
									"pitcheditrange" : "null",
									"stafflines" : 5,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 7300,
									"voicenames" : [ "(", ")" ],
									"voicespacing" : 0.0,
									"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
									"whole_score_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-7",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 625.0, 142.0, 94.0, 21.0 ],
									"text" : "Time signature"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "int", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 571.0, 142.0, 53.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "int", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 506.0, 142.0, 53.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-2",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 506.0, 13.0, 146.0, 21.0 ],
									"text" : "bach translation"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-24",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 6.0, 13.0, 146.0, 21.0 ],
									"text" : "OpenMusic tutorial 24"
								}

							}
, 							{
								"box" : 								{
									"data" : [ 23413, "png", "IBkSG0fBZn....PCIgDQRA..AvO..HfVHX....fx+Wee....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6c+GdTUem2++4nSLSpIHAYPBJ2XVgJXaFql1aPq.MPKKgtZft5R0BVcoMf62doXwEVPDaiftIqVAtZsP5VicEvZAVEbqA8dCrFrJn6PucRuIXALvpf0DLClIsYByANe+iYljIgIPHYx7qyqGWW4JSNmyblOmIybde97iy6O1LMMMQDQDQRqcQI5BfHhHhLvSA7EQDQr.T.eQDQDK.EvWDQDwBPA7EQDQr.T.eQDQDK.EvWDQDwBPA7EQDQr.T.eQDQDK.EvWDQDwBPA7EQDQr.T.eQDQDK.EvWDQDwBPA7EQDQr.T.eQDQDK.EvWDQDwBvdht.HhHR+iOuMgeCvQNNIGGI5RijrR0vWDQ5i7efMgMa151OSgmauGOzFrOl6Ys9f+Tw97FwdxKqel1vlsGjCXDdY9X8SI5OWa1rwZ2mWLZZe7XyzFCZHCigMrgwfxxFyshcfu376CRpAUCeQDoOJP.e.tXy64E4FtLHPf+B66kKiuyDlCiqkcx3y.7ALm0sM9AeoqfScpSE5IBiH+b5X+XbzZXAaCfUy1cuLF63cBjESeM6g8DHCx3juKEN0EvBqpF96cMX9KAfgOlr3UWQgrhVJi8bjEv0OD6bvc8KvUIECWU87720Xi+ugHI0T.eoOxOdaxGFXmbclq9fjXgkOWagikqIzWBF6mal7cVw8hWeFvPfV.JdxyfwO1d9aItewmAJoLJOmUvRd12fe33ucricFUAimQAfQFTBP9EdyTPAgayderi2CbMyYx3GkS.nfaawTa4GlpujAvCWIkkZR+zM92GSw1TXuQzldMs20iMa135W1Nvnmel8ZGc2OGSwVVLjgMLF1vFBYXaJr9ceT.n08UA1rUAdOO6i9BCuGl8tuCGSNFDI1oA10qtS18N2I6bGahG76euPQqgBGQv.7CB3MeiWk8t28xt28tC8Scc9cDiCyytjcwRu+Ev2+GTFT4yf6t2l7FAnE.BzVDKLCt7w.dd.WLyG7wXK6Xub3i6kIt30yie6p18xYSULKgyO6aG+Z1Rs+QHqQQI28cw3GUNm+mVuTS6dsLrI8.vB2L+WO9z6++C23.r7IcuLn0TMGateUxwnQdkm96y2YR2Fiow2iIcUec171frhEE9t6i1JSnPnMyEqO3JWPL7dXpcuGjSEdAW5UxWchEPr4aZd3AdjGDW.3wCd.fF3C8Zfyrfb.1vBJgMzkmSI3tkWlbyA75dqTIEg6uhSxMiuIkvJ3Wuqix3usQcddccvs+yZjsciOMq9YVA2wpWQnkOGp4H+Blxnzn2S5JUC+DJu7byMKJbIuMe9abB7EurCvDt5Awisyi2u2yetr5LXeQkUMs8z2N4FZc9NvNX9gFLPyb9qk57Zf+itCl40Oe1cSgq+rO1xCNSdvMcftre8en8vF.96uyoyHxMGxw40vc83+BJqDWz7m5CiV9H12+2Opiiucr14iMa1XJy8wX8UrLpX6G.LNLUL2Yxis1JXtWevxwC9b6qiZtefsuVlRnAlz0OykwdOtA9OvVXZtVBvRXFO3lnoCrIl472TGCNI+Q72GXKKi4WwyQEy0Fybs6Cvf8skGiq2lMrY654AW+N0fZxhosF1JSs3h40d22k2s1ZYc+.WLHaKiC3OVr2KB268838du2i2yzj.M6lRY07P+l5AB1G9k6tYLMMi3mWlaLG.LX2+5MBrKJbP1vVVEx1.V8y1aF3cF30qCts4+3ry2yj1ZoQ7T6FYNt1.S8d+U5y3xYyTRXNxlK0DJ2r4HVVKd1n4BKuZy15q6z1baVDEYV0FK2DvjR1nYfHWei0X5BLKprMZ5wSslK0El3pbyFCbHyRAy4rw56X6.LWmmV559OP8lyALAWlKs7pLqYOdLOVyc9J3yc4lvpMa1zzbOkWjI3xrpZ1i41VSol.lEsF2lls31rDH39u5ZMqdcAWWU02lYfCsQS.yEtwZMOzgbatl4fIkTkouVNRn8wbL27dNjoW2qwDVSGu20RD+sm0URvi84Tl41beLyCs4f6+0rs8X5tl0YBXVx57zWeGVRA0hm0Xhq00kuWUaYXxRqoeteWmITjo6t7E1.lUUDltJeOg99HlqwSO7M5V1iYQg97tGOtMc6wiYsadol.lUerH9la38i6l6xyEvbiGoKeC27PUUhItVSWNuhHllAuZSIAwc4tLcsF2w1cZatCEPN7OkXVSDm3HXvvxLOV3M+HayDvbaGIf4dJ2kIEsNyVLMMOx1J0DVn4Qh1KwQ1i4ZV3bh30.yhVXUlMZZZ5yypMgUa5qMOlyALWX0gekBXt44Pvi21BFveogWWf5MKIzIyBzb8laaa6wrESSy.s0rYsqonNN4Uf567j1s3IX.9vWNRj+sm0UTGGGllMaVtKLKZcc99r60oSHZ0z8OuXZZZ1XskcVWv8E99cclfKyMtGOl0WuGSOdb2wE2VVMGqiOqWZU0DLft6N+o9i0RnKFsTy56RL65MKELKopHtnznEv27HlKELonxLcerVLCDnMyFOTslKzUvKzuOWoAIsk5JzDIGWdTVnAFFfc688+0D71.xMUMuOG++kw3Xpy4Ynwcd+Dbb7lCvJ3Jssht7bNxm1FS61dPXIOM622cwG9rUhqx2CcuWDM74EeCoPt+m9449e5pvaSGk89a+kT78dur7u5D4ot1tVN9JCKbujZmq8VJB9rf+UK.C+JCsN6WIE6J3praOC93c8DLnR1Vm6nhlM1AZK.fm1IPTNlyHhGGncv0z+JA6eV+eD04A10BJDaKHhMpnhO2uIJo8bL3KqeuOxHiLA7v2YBthXotn7s4ge3TFA3+OQN.UduSkJ61ysn0rat6WtRbUVsz0Av+XY1k4ho9u8V38dJHTWwkAC5rd0GEq3H0vmdaSkBuxH99bIkgmptKTO3Kcm5C+DnLxD77tePWF04916SPFY7L8q9eqEJhG76diX29X4edOqA10CvOb80A.AZ+Xfq0PiABPKszFs07Qnlpqk6zUN3XrSixvCOaUUwF1Frj+1q+r120W0WigMnmHzHL1N457ZX52SYTUQvd9fSz4FFH3nJNyL5LT7IO5t55NKPmG4sG52GXqKhEr5bn1C0HsYZxw11BgOschN+c7dmul9SfqnrI1yfOGvB21gHPf1nk1ZiFqeOT8OdxwnArkjp5fU+KgxtgNFaK8ENF68zs9l2DSy2iEeaEDbfk53F44Oq0G7mcd+2B2yNM48djIdV62o7HuGl6b9cV1bT.uroI2+M10RqiQMEV+6EflO1Q3HG4XzXysg4K+HTP+4fRRao.9IPEbqKF1vcvOYmGN3B7UGqXBqfRppn9cvn.gpFbti+9olxbwFVfK1zA7yH+hEAd9k7F06kbxAd2m+AXpE+T7mL.XDLy0MGp7Ad.1lqx4abMmccDF22bI.qf6shcPS9MvvuONvNdFt2cA29W9upyMLm7YlEAKnheEG1meN5tWKS5If7OOU6HP6.LR9eMJmvw2K+KkrZ3xA+.AqZ+mQi9LB83kv11mWL7tO9gS8IfKOyydGZez7MKEV8p2JGsMGjSfiv5F2Dn3MbjKv2QkTe9wmeC76yGGcuOGEtDOT0L+hI5BULfcxcDihQMpQfybU85kygDVmIHlllllGol0z09Beoat+02xgFzd6IxNqLvgBM37Jy7XlsYVc4kzkWypb2Xma5wp1zEXNmp54A0lmMWVWd9.lktlZLawLTe3WvpM8YZZZ1rGyxJJ71Tj4bbEZP6Ep+86b.A1h45bgY4ta1rsCsMyhhb+tzNGrescnMGb4tViYKlGybcyIh22JhN52dOqoHSWkGwXinEOAO9CuecUlY8sbVGVRZrV7T0Y8Y10TSzFgJhj9xloooYb75KjnwvOd85CbjC4Fml4K76sIZ1.xIWmjSj8e3Q2B1t5GiZZ98XJmqlEzuWN9mzBAxHCFxPFQTlvN7yd2x+N+4anXlx0jKfAae9YvibMt48V7MdtKbF9noF8iigDbh.wvmOLxJGbXGL76GC61wgc6.F3sIufibI2bNei4AC71TiXXOGxM2bz8wuHhkiB3Kg3ms+XeeJYEa.VZMX93SoeuG2wCZihWMTVUajLe6xYIUd4TywdclxHT3VQDIdq+Gv233rke4qPqYFQ+m1d6DHCSNS.GzkE2V.LO8YvQ188s8RtpqfS8QeBQtws2d.xvDB3HChXoDHPFvYBPFcYaguzz+1LdkEpDQDwBIFTCeebzC2X2xu4A3zm5LblKIytd6RQ6bFxjL6Gaq8KISL9ymoa2GVFbpy.WRlcqlim9TXblKA6ccGyftxQgyyaS.KhHhj9PMouHhHhEfts7DQDQr.hIA7MZrN1ccMFK1UhHRJsK5htHrEZxeZf9mK5hTc1jduXxmV7+AuDS5Ed+XwtRDQRoY1CYVuApeDo2J1b4gWhC9ZNx37uchHhHRBgZOHQDQDK.cuokF5htnKJl0Te1rYiyblyDS1WhHhj3n.9oghk8smMa1hI6mKTwxKZomnKlQhWN9ApCtxwwHT9+PRfTS5KIkz.dRRG32WSbfcuItxw4he496OS50hz+EytbyAEq1QhHRZh2a0CiIrhfO9xz3ZVRvTl1KMjMa1hoMoeh3iHwiW2D0wljdKxOW4qoiRis7o7KGcgLX2Myhuwy0TPY+60RjyG0j9VHG+.Gfi6y37ughHwD43bTbMWy0wnbknKIhn.9VFGc6KiqbbiiMjR1Oh94v6cmrkMsE1wtO.ohGAhUV.ZOQWDDAEv2Rv+A1DWcIOA.3HiTsQIrWdt4lEidBqk5+n5ohIMNFzTVKMknKVhbAH3r9Yp128jzMJW5mty2d4aOtuCkUiappDvOoXMou2+.26Ffpa7k4QV7ivNatFXWO.0oH9RJ.C+9wuee7Y.m7jMigQJ12+jzJJW5mV63TwsLAZYMt4QlhKZuAHUqVFFs7I.Pqs3O3Bx5RwEPqAzINkjedp7aSVYckrDOvSL0qlLl1yf2DcgRrrhMm8W4R+jRGX8ygk3oLNzbGC97dzf0xnwigO+ilbbjZD329n9an5xJhhGcVTzBKiIzvJfxpgYLhTixuXsci2+Ki48mnKEhDj5C+zY4b8fqcw2+qcKbKesuUvZYT733g900mnKY8d9NB0tkcQoUUC+3hFF6eafmc86ndMx8DQjKHwj6C+V2WEbq+GShcshIDKJSR+Tzu2b8y5u9r3y1Par3BbzO2WC7B+55aeUvfJDZwbwjC.bbVlsqjr1Sy7Hiu+cOMq6gYYfP77yU5yvxEBUCeKi.g9UaI1hwEnL9bCCXI7ZGHXOe5+nd32BLxKKqDZ4RDQR0nNBMMjMa154I8lBGBK4BbekH4Xr+sTyZdal53FRGKqz0UCe6w16akBQDQTtzOsTOOCv0YS+406IAfbycvQr9Dav8nKGlx8udBT5ShWe9wQNNIGEqWDQtfoboukRv+Uu3EUM.L5qcF.PokF9i.IOA7UtzWRUEOlZmCSSwyxEBEv2RwrKA6KrvfK0s6vA8SdB3GONooNYojXkJ1haRpL0G9VHgOoROstbyM1NSd0ez6BDqSXJo954VbSjXKEv2Bys6f+9Pu+qBbSIzxR+gNgojpJZs3VkUZSeFVFPDSB3azXc71exUvDKXXwhcmL.IxZ+FLHezWWpDcBSIUUpTKtIoGTtz2hohmp3d0xREb9NgoHoRb6N3Oc+hwEIVQ4ReKn+kmbFz7IClHaRUqYezjtzEEh0P5XKtII2Te3aoDZPrYyF4lapeSdqSXJo5p3oJtitkJxkIx.AEvWRooSXJo59W9IESyMGs6xDQhsT.eIkW4O0L3jdS+5hBIcWm21nZ.5IwCJfujBK3ILsYyF4p7GkHhbNEyls7TtzWDQDI4kRstVP1vFljF8uca1.8wXIEk93qDuDypguHhHhj7RA7EQDQr.T.eQDQDKfXR.eiFqicWWiwhckHhHhL.P4ReQDQDKfXSS5qbouHhHRRM0G9hHhHV.JfuHhHhEfB3KhHhXAnbouEksHl3NR4YBjNc7HVLlI8eeLsJybZgEyB3qboepkzpu.qbSpjByFI2eeLY+hQjdOkK8sfTtzWjjGI6e7Ms67EVXpO7EQDQr.T.eQDQDK.EvWDQDwBP4ReQDQDK.kK8EQDQr.TtzWDQDwBP8guHhHhEfB3KhHhXAn.9hHhHV.JfuHhHhEPLKfuxk9hHhHIuTtz2BJsK2XmrmLxE4bHY+iuocmuvBSMouHhHhEfB3KhHhXAXOQW.DQDqIS758jzby.LXHoadmOT4ilgbMI4q7IWnhIA7MZrNd6O4JXhELrXwtSDQR6s3EUM.L5qcF.PoklHKMmsj8xmbgS4ReQDINawK5UABFLsvBgBKDprxDbgJBI6kOouQ4ReQDINxqWu8o0EujrW9j9N0G9hHRBja2A+8gd+WE3lRnkknIYu7I8dJfuHhDGkat41wiCFDM5qKQIYu7I8c51xSDQhyp3olQuZYIJI6kOouIljo8ZceUvs9eLI10JlPrnLICvR6xbVI6opLIg5Dm3DI5hPOvjK9hC1Hqm9zFj7caukrW9fgNzglnKBoThYMouxk9hHxEBab5Se5Ndbxmj8xmbgR4ReKHUCewJI4sF98Wc9YdmNidNPoolZLh+J8Knspg+EFMn8DQjTPQFjuv0G8rhSjaSSM0z.dYRRto.9hHRJgtVi9dJHejhbab5zYZeM9kyMMJ8EQjTH81f8cWgquzdro+EqAkK8EQjTD8Tvd2yO5481tusgC520Z5KVEwj.99+fWhIs8hvTA7EQjADQKXe3.88TM9i156Lnu5SeqlXSe3qbouHhLfwoSmQMX+4qo8Cu9tusAC56TA8sXzf1SDQRwz8.3mulzuv0WZu5BDjzaZP6IhHoP5of8Et9R6xOQttvqumtv.wZP0vWDQRhEslyOryUs16olyOx0ql02ZQ0vWDQRQDYv6nUS+H+IrHqYupku0lxk9hHRJtnUKd0m8R2ESB3m8MtX11MFK1SR7hszorrkInrFV5mzp46AQRBn9v2hJs5joZxyIsSZ0EjJRRB0G9hHRJtn027muAsmX8noGWKHM83JI6hkeFMcX5wMxQp+4af60cce8Q9bS0Gg9Z5w8Bixk9hHRJptOB7UM4kykXRS56+CdIlzK79whckHhHmCcu46iVR1o6Beq5oKHvZS4ReQDIIWSM0TWZV+tmpbOeA8i1srWpdy4KW3znzWDQRAzTSM1kYLut2b9Q96ykfA60ziqUjB3KhHoHhVPe37OM4FlB1aso.9hHRJjtGzG5c8ie3mqXco.9hHRJgNSFQg6S+v5dM92w2ZknrOozcJW5KhHofhr15NcNryZYhzcJw6XAoDuijrSIdGo2PIdmKLJ05JhHhXAn.9hHhHV.JfuHhHhEPLIfuQi0wtqSCVDQDI4SqT4jcxO0yISzEDIAS4ReQDIAxveqzpeinuR+sRq9i5yhVasUh1yxvu+tsb6jI.1czqKS96g8sjZK1zj9JW5KhH8L+GjUc2KhstisxptuYwjWzVoUi+DuvxmL4Mx7I+QlGy5I2As1w1de7jO4hv4Hym7GoSdxczPG6pS39EXxNyi7yOexy4cyNNXq.PCuxpvoSmj2HGI44zIO4qr+PKek7P6G9w22cxjcNKdg82ZTKhG7UVE28x+orp61IiL+7IuIuJTiBjdQ8guHhLfqMd+p+2XAq+2iq6ZIT9c4h27GU.2OKkC1TSzzG9N7UKet7O9JMDZa2BG1w2f2o954sdwkP4y8dX2mv.9S6jwM80wC8VGjlZpI98unKl6M+nzfAj6XmN07N0SCe3GRc0rVJ+uexriOxf7+Fyik.rvktJ1Zc+bJ9uJ6nVBCz76S0q+cXrOvaQ80UCKb+qlmba6Ot9tjLvRYZOQDINvG2B07BqDWN.LNHKZ5.2x+G9YK+Mosrxh+Gfpe+l4m+Mx.ebK7PKX5jucfo78XITNu2Qakq5H+Vf8y+0u4mwdaqMB9rNJeheXj4lE+90+D7nu9+MMSv.0+OM2JbUNw40A9Fw+KF5vyFnU9UyJedn2LTA6VdRZ3k9tXztOttUsJ9aKbL.vrV0sv84qs38aSx.HEvWDQhSBDtiwMBveAXgy+6x79h4PaAfL9tyiexfGLveLz1PnyP6m1Ab.Xbpl.VHyadyirZqMfLXd+.GL3r+HJO+IyqujmkMt0eLW0PM3WM4wfuPubsCbIcb19rY1O+AojvkE6Nni57epN649fORcUa5D0j9hHR7liOOy3tgUu9ZwW14Q9iLOr2x94M98ebnM3M4fevIvvnU1+N1.qlaga5ZFL4Ow6.X0ry86KTe0am8uq2fO9yZiOBXZ23MvUMX3f6tZd18CWRn8VNCAp9M+CzZnAHnirGLCdvg9I6d+f4SRsEyB3qbouHhzaYmacUuCqZ3aladLiDm4MRJXxylF9yAWaN.KXxii7xKel7beEVaM+BJbvf8q5V4cdwUwOd12LiLu7Xj4W.y92z.j4X39V6cypm8Mfy7xma9WTKCAHS61Axlh9gOJu4Ceqj+Hymm6+WzGzdcu4dUy+l9Q4ReKHkK8kjcVoboevaAN63HaGgZAeOLqQ9n7ia3k35r6Gb3HJAe8Sqmz.6Y6.G16bsFsdRZEGQuV698Sq.Y6H8oF8JW5egQWDmHhj.4H6tMp4MBvaxaxeAvdOFb1AYO3ydo1ydvDkEG5oDQe0KVRJfuHhjLI6u.0WW8z8qCPj9KEvWDQRp3fgN7zmlcWRdDS5CeiFqi29StBlXACKVTljAXpO7kjcoceFMtvDudClZ7xM2ACXKwVbjjNwjZ36+CdIlz1KBSEvWDQRHV7hpF.F80NC.nzRSjkFIYjxk9hHRJtEunWEHXv9BKDJrPnxJSvEJIoiR7NhHRJLud81mVmX8nAsmHhjFws6f+9Pu+qBbSIzxhjbQA7EQjTX4latc73fA4i95DQMouHhjhqhmZF8pkIVawrZ3qbouHhj3TwSMiN5y9f2VdhzUJW5aAk1cONq6C+zNoceFMNvlManSmKmKpI8EQDQr.T.eQDQDK.EvWDQDwBHlDv2nw5X200XrXWIhHhHC.hIA78+AuDS5Ed+XwtRDQDQF.nbouHhHhEf5CeQDQDK.EvWDQDwBP4ReQDY.jMa1RzEAQ.T.eQDY.mx.dRxfXVS5qbouHhHRxKkK8sfR6xS4JW5m1Ic5ynJG2KIKzf1SDQDwBPA7EQDQr.T.eQDQDKfXxnz2nw53s+jqfIVvvh558df8xtOBLwu93I2vuhFMwt+OciyB+5LVGGic96pmSEwy4TbobSe8IhyPau2CuW16wuL95SbrcVnMZhc9adA9O+CeFC+y+U3aVxWmqIW6X38vT6eH.SJhssoCraN.ikIN1b4v6sVNn2Ne0tzgMF9R230PNXvQ22aS8M9m6ZI4JuIlXAN62uOIhHhjnDWxk9M75KkRJdB7aNj+NVVS09zLohKls+g9v2AeQlZwEyK8ZuFu1q8Z7Zu1Kwleo2lO0H7V6iey2eBT7jlMus2vKyKqeZCioV8mwMNgqGdukvnGxsy97As0vlXpSZ63KhxvGt8Iwj17G.3ieaoSkJdsZ4cq8c4cq803QKbzbKO1tAZiscuShhW2KEpb7Z7Ruzl4+58+zXwaShHhHILwl6C+yStzOiAE7l16Y196w7G63A7ya7hOA.3.6.N.Wqi0+zyOpOeii9Z7L6pDJsnswFp9vLw65Z.e+QVvtfZZ9QXJ4Bba2F2vXqfFazOiIiK6rO3bTDtHTY7xKgm7oebtwPq5Qt67w13da79HeI.XM+yqm6er8s2JDQDQRFEeR7Ns.tlSovR90b3EOdtFeuGanxRYMK8uf+.FvmKSvyKxxp3yHq1aGnM3x957Od+SAG.ddwmgKupeAqovoPVt1J+y20hI2b97T0bfoNDaTRoKkY9MKlo8cWLivA3qty8gblzBu4N2KboP.7xa7Se.bszpIGfLub3Yd5kg+qIKBWT9Jy6ejoeMNhGuSIhEVvacMudOIMSyPtI3hS+lYviklalfGaJi6IIVwk.9AnEx+qr.louh42df+El6w+0zPYylwOrp306XqFDCeXCKTB7ocZ+RtzPK+n77KYWb8a9DbvSlIvCPMG8GxsOpb4dd9.Lgev+Iuwa7Z7zkLItWbQMM5luR.+fqtFftKs+vf1EOvJeBJYP.zBaaaPoaabc7lwke4CmgMrPkjVZmKU4iPQhKV7hpF.F80NC.nzRSjkl9mzoiEI8PbKTVKYdkLsErPJdyuLC5OtSl2hKiKaWqMzZaGbUL+C2y8bVEHe6aarZbwb11SviPNTDvF1lG9a9leDKcSWBO8iLcF63mNyewOAa+AyhU9uWO67u6KiKOuHMBjSj6LG.XP6sTB64UeYFenqI3nae9b0OxN3Ius6h1+TXl2YobOEnZzKR7TjAHKrvfKqxJSMCTt3E8p.oGGKR5i31sk2m9YvH9Zeat7UbGbuaXBTRA4Pfvigu..dZji4yO975Eud8hWu9vOFrqm9AnjM9uyy+7uLu7y+77pdVCa6Add9enYV8JVBa+vgFZdF9n4FfqLmOGjkStbpje41ObvUc7cxC7.6h4UzX5n7bp.cV1th7+B.sC.YB7YM8I32muPkCu3ymAhHCb750aeZcIiRmNVjzKwrZ3etxk9Y.b4N.bTHeu4.e5me1LJf8Qv.rYjwf.d.t5Asht77V2aUKUuAWb++jqoik4XbeSJkQyt9KMi6pdaJbzQ7JOm0vQ96tFvN7htqhgU3n4IBspRJuFJsfb.N6uvEfLAO6iiY.43BVvTuZ5RIon0QK6b9cs0BDQFv31cveen2+UAtoDZYo+Jc5XQRskxmK8M76kFatMxJmgPt4zslg2uWNdysQFYjCNcpv0gkNkmxATtzOMQ3lAu6p3olQbtjz+kNcrHoOR4C3KW3T.eI4jYG8ieXoxAH6dP+T4iEI8fB3aAo.9omNwo.joJd...H.jDQAQENQhtHzOE7+gW7EGrmFO8oOchrvDCXFwwhAoC2VdCcnCMQWDj9AcCmIhjjHX.wT+.8gYKhikT+f8Rpu3RtzWDQF3ErEBV1JClcOd7k+W2k0trU9ZgV9z5x1EVOs7NWmBZKo1hK4ReQDIYRzBpGsk0aVmHoJhM2G9mmbouHhjL5wW9z5nl8WHqSjTQwsDuiHhjrHxlue6ugSEbWrDzf1SDwR5wW9zX6ugS1yt2H6Y2bVA7Uy3KoaTM7EQrbV1JecV1JectsI2z4bv5Elp8ujNP0vWDIsT3QkOzyArO2A4+q6w0IRpnXVM7OW4ReQDIYRzt..UKdIcmxzdVPJS6kdJ0OS6II6Tl1K0l5CeQDQDK.EvWDQDwBPA7EQRuzdCT4JqjFZGv3jre26mSZjnKThj3ESB3azXcr65ZLVrqDQj9olYCqYCzrAP6GlIO8IyAZum25V8TINcVImLtU9DIwP4ReQjzLYvPXHAe3kVHM0TSLgKMhUa3G+QTieGYAPl3HNVBEIQP4ReQjzWsueV9LWN6uc.NI6rxEgy7FIiLOm379pjOp0CxO568v.OD24rlLyZQakVSvEYQFnnDuiHRZLCp82UKyx.Nw67yX1ObV7Ve3GS9Fmf29U1EsvXXdO5BY8yNSp3meOjC1I6DcQVjAHJfuHRZsvMuuiKyIvCyisxgycLkuL2Pw2AWU1f+g6D.xa3CUA6kzZZT5KhXIjsqRogeeMbGegKg8t4kvMLl7XqM3GCCfqKyDcwSjAbJfuHhkPC67Wwq8ICghuyRYkO8+J2MvG6yO1smIr+Z3O7mZkVOYqn6fOIckxk9hHVBYbplXAS+FHOmNw4HuY9um+Z4a6Zv33yOUdzaoZt0Bxm7KYSZP6IosTtz2BR4R+zSJW52aXf+V8iANH6r65PXxeqsBNxFGZjM0iTtzO0l9nsHhEhcbjczGZd8zxEIcg5CeQDQDK.EvWDQDwBHlzG9FMVGu8mbELwBFVrnLICvTe3KVSc9YDudCl47yM2AGw5sEmKOhDeES5Ce+evKwj1dQXp.9hHI4V7hpF.F80NC.nzR0EKJVCJW5KhXYDYv9BKDJrPnxJUM6EqA0G9hHVBgaF+Kz0IR5Bca4IhXI41cveen2+UAtoDZYQj3AEvWDwRHxAnWvf7QechjtRMouHhkQEOUw8pkIR5nXVM7UtzWDIUPEO0LvqWu.pl8h0hxk9VP59vWrxrYyF5zdhUjZReQDQDK.EvWDQDwBPA7EQrbrYyF1roDtiXsDSB3azXcr65ZLVrqDQjATlllpO7EKoXR.e+evKwjdg2OVrqDQDQjA.JW5aoXhWudoYuMCoEiR+fGOdaNc43QDQF3nLsmExYOKgkHKM8eoaGOx.stN8317YcghpO8kzaJfuEwhWTvTIZ3YIL.prxT2fjoaGOR7ildbEqJMJ8s.BmUwtPWWxpzsiGI9QSOthUlpguET51rDV51wiLv37M83lat4FGKMhD+obouEPjmH6rmkvR8NIW51wijXnKTTrZTtz2BIb+dGVEO0LRPkjXizsiGYflYGMoe2EbFySMsujdSA76ENwINQhtHDiXxEewAaTmSeZCR8OAW51wSmF5PGZhtHjFJ3o55dP+NmdbSe97iHQiB32Kj9DvWRUzWB3qOmd9z4o555EJFlB3e9nKDM0lFzdxEffmvbYq70AfGe4+0cYsKakuVnkOstrcg0SKuy0oS3JCj57yWm9zm9rVlHo6hIA7MZrNd6O4JXhELrXwtSRCDsf5KakudGA8i959qi55Do2QWPpHmKJW5KCnd7kOsdLH+4ZchLPpmtfzKjsWjTMJW5KCHhr1Ra+Mbpf6RRIcAohUh5CeY.yiu7ow1eCmrmcuQ1yt4rN4op0jjn73KeZrrU95rrU95LgI9cTfcwRPoVWY.Q3SldaStoyYeiFlNgqDu83KeZLgI9cXO6di8XS7qKJURmnZ3K8YgGDTPOGv9bGjWCROIwnyA12z31lbm01+b079hjpSA7kADgaxztuLQhWzEjJRWoboubAH3skTOchvtu7d61IR7ltfTwJRYZudAkAyj3Mko8jjQJS6kZSCZOQDQDK.EvWtv0dCT4JqjFZGv3jre26mSZbdeVhHhj.o.9RePyrg0rAZ1.n8Cyjm9j4.s2yacqdpDmNqjSF2JehkltfTQhpXR.eiFqicWWiwhckjRHCFBCI3CuzBoolZhIboQrZC+3OhSv5HK.xDGwwRnXkoKHUjnQ4Reo+o88yxm4xY+sCvIYmUtHbl2HYj44Dm2Wk7QsdP9QeuGF3g3Nm0jYVKZqzZBtHKo6zEjJRznbouzOYPs+tZoMC3D69mwre3r3s9vOlOtg53eeR4PKLFl2itPfkPE+7sxO+ebpjchtHKVG5BREoCJw6H8agqMkiKyIvCyisxgycLkuL2Pw2AWU1f+g6D.xa3CUA6k3rfWP5rLfS7NcdAo4abBd6WYWcbAoqe1YRE+76gbvt9Lpj1RCZOIlIaWkRC+9Z3N9BWB6cyKgaXL4wVavOFF.WWlI5hmXQ00KHc87XqbcT86bDxu36fqKaHug6DXPj2vGJCe3CNgVVEYfjB3KwLMryeEu1mLDJ9NKkU9z+qb2.erO+X2dlv9qg+vepUZ8jshFvzRhftfTwpSA7kXlLNUSrfoeCjmSm3bj2L+2yes7scMXb74mJO5sTM2ZA4S9krI0GoRBgtfTwpS4Re4BWlt3ka5kC8GQ73o+PzTSKD+s5GCbP1YG5iW1uJ9AuTS78ZsUvQ1ZzPKIDgufzED5uut4uVVpqAiCioxidKOD2ZA4CW2p3fuQonF1WRGoboeufxQ4R7lxk9CTLN6KHMD+gufTMTl6QJW5mZSezVDwBwNNxN5iC+dZ4hjtP8guHhHhEfpgeufZFqdqN6cHudClnRyM2H6MTaw4xiHhHgES5CeiFqi29StBlXACKVTljTVA+nzhWT0.vnu1Y..kVZ3Oho.9RhjtfTwZKlTCe+evKwj1dQXp.9VdQFruvBCtrJqzVDA8EIwpmufTQRuobouDyDtVSWnqSj3kteAoEVXvKHUDq.Mn8jALtcG7mC89uZhtnHhtfTwxSCZOIlIx9Cs6A46ZekJRhma2A+cvOqdSIzxhHwCpF9RLUEOUw8pkIR7V2ufzv+z80IR5JUCeIlqhmZF30qW.chTI4REOUwczO9QtLQrBTtzWhgBN3mrYyFJiMKIqzEjJVUJW5KwbJfujLSe9TrpTe3KhHhXAn.9hHhHV.JfuHhHhEPLIfuQi0wtqqwXwtRDQDQF.DSB36+CdIlzK79whckHhHhL.H1ba4obouzM1ro7SdjznBWDIQSIdGIlSA25pzoK9Ic5XQDqFEvWD4BhtfNQRMoQouHhHhEfB3KhHhXADyB3qbouHhHRxKkK8EY.V5TtaOc5XQDqF0j9hHhHV.JfuHhHhEfZReQFvXhWumDH77tdp88v9YOGxmZe7HhUSL49v2nw53s+jqfIVvvhE6NQRKr3EUM.L5qcF.PoklHKM8OKdQuJPjGKpdBhjpQ4ReQF.DY.xBKDJrPnxJSvEp9nnernZ2KRplXSe3qbouHcHbSeegttjQoSGKhX0oTqqHCvb6N3uOz6+p.2TBsrzekNcrHhUiB3KRLVt4laGONXfwnutTAoSGKhX0oaKOQF.TwSMid0xRED8ikhS.kDQj9iXxskWq6qBt0+iIwtVwDhEkIQ3Dm3DI5hPLfIW7EGrQzN8oMHU+1X6hu3KFH7wBjpe7LzgNzDcQPj3pXVS5qbouHcmMN8oOcGONUW5zwhHVQJw6HIkROpge+kIKakuN.73KeZcYMce4g+6v5ok208k0NvspguX0n9vWjTbQKndzVVuYchHouT.eQRS73KeZmUKAzaVmHh0fB3KRJtHa99s+FNUvcQjnR4ReQRC73KeZr82vI6Y2aj8r6dtO+EQrtTtzWjTbKakuNKakuN21ja5bNX8BS09WDqoXyskmxk9hLfJx.38T.6yePdq8nxWDqN0G9hjhKZW.fpEuHR2oLsmjTR2G9x.Mce3KVMpF9hHhHV.JfuHhHhEPLKfuxk9hL.n8FnxUVIMzNfwIY+t2Omz379rDQjyRLIfe123hYap+6EY.Pyrg0rAZ1.n8Cyjm9j4.s2yacqdpDmNqjSF2JehHoJhYyVdhHCDxfgvPB9vKsPZpol55pM7iebfiPeS1QV.jINhmEQQjTBpO7EIUQ66mkOyky9aGfSxNqbQ3LuQxHyyINuuJ4iZ8f7i9dOLvCwcNqIyrVzVo0DbQVDI4gpguHoLLn1eWsLKC3DuyOiY+vYwa8geL4abBd6WYWzBig48nKj0O6Lohe98PNXmrSzEYQjjFJfuHoPB279NtLm.OLO1JGN2wT9xbCEeGbUYC9GtS.HugOTErWDoKTS5KRJnrcUJM76qg63KbIr2MuDtgwjGasA+XX.bcYlnKdhHIgT.eQRA0vN+U7ZexPn36rTV4S+uxcC7w97ic6YB6uF9C+oVo0S1J5N3SDILEvWjTPYbplXAS+FHOmNw4HuY9um+Z4a6Zv33yOUdzaoZt0Bxm7KYSZP6IhzgXRtzWjXMkK86MLveq9w.Gjc1cc333u0VAGY2wsqmb1TtzWrZzoCDIkkcbjczGZd8zxEQrtTS5KhHhXAn.9hHhHV.8+9v233rke4qPqYFwsBT6sSfLL4LAbPWVbaAv7zmAGY2221K4ptBN0G8ID4F2d6AHCSHfiLHhkRf.Y.mI.YzK1Vx9Kw291GuRIoRJjfe00q2fYN+byM2DYgQDIIWLXP64iid3F61s+S.N8oNCm4RxjL5xRamyPljY+XaseIYhwe9Lz0M1fScF3RxraCIgSeJLNykf8dy1ZePLpQ4TCpAIEhIKdQUC.i9ZmA.TZoIxxiHRxLMJ8EIE0hWzqBDLXegEFbYtcqf9hHQm5CeQRA40q29z5DQrtTKXKRZ.2tC96C89uJvMkPKKohtnK5hHVzXm1rYiyblyDCJQhD6o.9hjBJxAnWvf7QecRuiooYLKfuHIqTS5KRJpJdphixxlQBnjHhjJPCZOQRYYBXqi9rW0ruuylMawrZ3GOOkpu5VOCx0BNqkWZ4alUt3aGmwsRB.Fbz5bSKC55nfQkyYs1lpaK73OxFnAxgBK9NXde2aiQz86CZCuru2tAx+ltQx0XeTTVExLc2LOvMpOaGKnZ3KRJKaXylMxM2bUvdKtpp0C06wCd73gZ1b4T4RtC99qut3bovfc3ZB35EO3YsF+GXSLLW2AMbcEyb969JrqETBW42eK3+r1xFnvIUHMX.3HedjMuYlxUc1W7fz2n.9hHRD7683T2d2M6XG6f8V2QiRPoAfWylN.aZsOGGnO8hUBE9UJfwVPATPAEvTt8EyFKBZn8.g14GkmaYyDa1rgsoLW1zdOdnke.dr4uL1zVVKSwlMrYaJr1cb3N1q9NvNX9SI3EUNy4uVpyanrshwwYSO1bCt+rYi4Ww1oIfCrokxB.XIExx1xA5RIb+a+6.EUEa4wmO29cc+r0ZVHrgiSaQtQFGlGaZAu+RKb7OH040G+we2uii0hA9O7VXtyesro0+fXylMlxbqfct2syCFp7M+0u2NxEL8T41+w2KO1bu9Pk64xVpqo9xa1o1LEQRYouBGazw6is41rnf8UhYIkTjIfIkrNyFuP2O8JsYdH2UaV1bbE70gRMqusKrxcKdVmI3xr5izhYaszhYKszh4QbuYyR.y4rw5MMMa1bcEgItVnY0t8XtsxKwDvbyGIfoYatMKALgRL2lm5MqYcywDvbcdZwzrwZLcAlEU1FM83oVyk5BSbUtYillldViKSnHyM6tdy52ylMKBLWZMGyr4CUs4b.SJobS2GoktTNCzRilM1R.y.szn4QpeOlkWBlLmMa10C2VLcus0XBtLKey0Z1rW2leMvrb2MG53L39t1Z2bvWGvboUUsYMatLS.yppusyQ4tMyMVRv+WV+QNj41JqHSvko6Kv2uS0oyVHRJLEvO1ni2GCbDyMu48zQfnl2S4lPQl6okd7oF88y4PaMeHypqprNuvhEtFyZ8bLy.lllsbrCY5o95Mq2iGyC0Xam++Nbfvy5mhL8Dvzrs5qJX.9CE9H5XlkAlkrNOcDvurZBe4LMatFWX5pb2ldVWIlPYlGKbY9HayDvbaGIfYidpwrZ2MZZZFvrslq2rLWX5p78XZZ1lYUEgYQqySOdrGb+FrLVT40ZFn6aP.OlEQQltCXZZ1Vv.9qti.9t53+CtWSQlTxFC97C3wrDvbMta9bTt8ZtNWXRoUYdnFayzLPyld1iGylOqBP5M0j9hHRX1GE2dDyoF1yH3ixHid9obgwKU90FMEeuqfqbc0Pyll7xO88yDKXDXG3fa3agqwMNFmKWL508dm2+NHWrs5OFMdriwwZrQpul0ArKp9saBB0p92wnyJTSYekrB.B0b+sPQLsuR3g1WtTz7JJziyAXEbkgZ19rt5R.fi7osgcZkW5dGF1rkAYMjwwJ7.4eYYPvDhdm66nof4+xXFnE7r4kxtVxOfZ6dqpaD74Fnst+LaG36vmOT24mAfqoL1f2W4FAnkN1tdpbew7sprJJpx6kQOrrvVFeMdg+uMgcK1MltB3KhHci+Cucl6TtdFTgO.kUcUbiwrYUqbnnGobJBXCKXpbuO3ZY2G33cz+ytt+2jVZoEZokVnskN9y6eGzkyUc0i.miXDLBmNYrS4ui03B13u+CIPfV.bQMGqMBzRKzVasfmZqlUTxXB8b2EeXyge08i6WdW.AHP6GCbsFZLP.Zok1nslOB0TcsbmtfmeNkPkeyMyQZtELMagpJBZo8y0wrOdtoXioDdPDZOGJ3u41oH7ve3CidVgL5WfkiNRbLABVbOKmqxcKW1DYaABPyGodptpuIOwBlJapNemqBdZGEvWDQ5F6C454G7ieZV2BKhUTwKxQMN+Omd4dlBt8EyNMCvQ7TC27e4kYRi6JICaSgJ1ztwmibHmbB9iC6f8yyeGVf.c80HyKGt7LyfbFy3oD7PUux6hQN4fuC9J3ZREyu8OE7.ZP.2wiuAZBno88uySuK31+xijQ9EKB77K4Mp2K4jC7tO+CvTK9o3OYD74MmO+eEiJ2b3n6dSbu6Bve..C3SgO8yZjtFFMGbMyhXWK3mxtOpOL76kcVYYrKJga4551cWR..1EG3f8sATWOWtajez3FMycCdH2QMVl927qiq9zqPJtDceJHhz2ouBGazyuOVuYIgF3X8u8SOKPyGwrlMVlITjYs8xwJPXA6a6R51fOqEyMNGLonxMOlooYi6oq8yeIkWSv99NTe3WTQctthV51BM9EZyr5xKoKOupbGru9cW0B6b4tJ0rrEVTG8ut6PC7OWk6taGitMWZQccbFrlZNRTdy3PAGnc3xbOM5wbNf4O2iOyV7rFSbsFyvu83YME04qQaA2t03tkyY4t9MuztrbWkVUudvXltPIdGQRgEuSzKoq538Q+GfM8qOBe0u434JxAd2e8+DS5dOH6okcx36E2N3Is++vuONdy9IqbxkbyITSC3eeLkrdHdx11IWWaMgObfyb65AoeuMQyFPN45jbr20k6yvN45LWriA970FYkSNXGvue+X2ginj21Mnoi2HA.xYXinK6utuc98CNbz26f8dpba3qINVy+Ex3yMDFgSq282uB3KRJrj1.LoXhLf+Cl03X0crFWrtZql4OwQbgseRE3auXaPSfZawjIZ8h8YIo.9hjBKkJ.SRrt+9ngee3K.jSnZs1W2OI0LZhc9xtYryb5LBK1nU2pRA7EIEVJU.ljXZ5wUrBz00IhX40aBR24jTzfCsDMU3JoVT.eQRwEqmC1UKFb1V7hdU.XzWavoe3RKUuGIodTS5KhzA0EAmsHC1WXv41Eb6FJszDXgRj9.k3cDQjdP3lw+BcchjLRMouHhzK41cveen2+UAtoDZYQjKTJfuHhzCxM2NS8qACxG80IRp.0j9hHx4PEO0LhxxJNATRDo+QCZOQjNnAsWzYylMZt4lAzskmj5RA7EQ5fB3Gc58EIcfZReQDQDK.EvWDQDwBPiReQjzZw5LQnHopT.eQjzdp+2EQMouHhHhkfB3KhHhXAnaKOQDfzwo+US758j.gOlR0OdDo+Q8guHRZ4z+5hWT0.QdLkHKMhj3olzWDKttO8uVXgPkUlZWa3neLkfKThjfo.9hXgkNN8ulNdLIRrfZReQjNjNN8ulNdLIRegB3KhEV53z+Z53wjHwBpI8EwhKcb5eM5GSm8xDwJQ2VdhzGchSbhDcQHl5hu3KF.N8oMBsjT6AtGXxEewAaDyfGSo5GOAMzgNzDcQPRQolzWDA.N8oOcnGkdDXDrkFdLIRemB3KhDW3zoynt7lZpwPORAkEYfjB3KhL.wDmNGVG+UgqO5Y9lH2lNC9C5B.DI1RA7EQFP3z4v5wf7QJxswoyg0sf9hHwJZT5KhDiX1wONc5rWEru6Jb8k1kZ7KhD6nZ3ml5htnKJtOGfaylMNyYNSb80TR9zS0r287idtss6aa3f9M0TSCHkOQrpT.+zTlllIj.9h0VzB1GNPeOUi+ns9fA8cpf9hDCo6C+zT1rYKgDvOY7iSFdO.0t2ivo.fSAWxUwWcJ2H4zO2uoa2G98WQqY7cO+J60Msez1V2yuREzuaz8guzWoZ3mjxv6A3+buMQge8IhS8eo9k1Z30YpE+.rvxJmgvIw8VdBJ1UUzxyeO86f9ROq6AvOeMoegquzKnKPPD4BiBkjjxyy+OPwOvtnrZajGYhQ+9WVt.3Zc7zOx7C934ciX6J2FGqp6gwpuALfnmB1GsZvG41pf9hLvQmtKozQ44efOkRWXQrhJeCV5Du89w+n7ywO7A4vG8X7mO0kx39p2DiJGK1+1yHSvyB3AW1QIKZi87DqFWkUiB1GCctFU9mq.3gWdOsMpu7EI1Q2VdIg7suWjUWzRXMOwShqM7L7195O6q0xUNZW7CV45nhhmDW8flF6rIiy+SLsSI7UlvjXBSnHlcYyAOqXsrWM0nOfHxf2Qql9Q9SXgqYe2erHRripiSRGC105WBb8alibjSxDXWrgccTl3sMp9zdKq7mMGpw6mqwoCfixxrc07huwQYJ290DSK0I0BzN3pX9V21zwA.21LfsjAu9ezKie7Z5RMdomFTdp46EI9P0vOYiO27rUBkbhsw+z+TU7WJBpb06f9Zk7sm6nBErGfgvnbAG7S+KwpRapgL.7zHeheC762OMU2Kyy3AtlglUhtjIhHwMpF9IYN5q8rrsR1HlO+cEbA9ePNVVExtN9731FQ+3eWFdYG+j+VVfm4f66pfXSgMkQl.qfqNqUzwRJayd3ttFG87SQDQRynZ3mTwG63Ypjkd+eiNWjiqi+g4.O6qTe+Z+9bSaHT7aMSpukmmazhcunkSAyuiDQT3edja2pcQOIdQqu4OeCZOQjXGk3cRS00jfiOdtYdKv+7d4dF6.WsZSVS7NCTTh2oqhbj5e9F3dcW2WejOWMB86Jk3cj9J0j9VBYwDWQkvUn+cKweceD3qZxKRhgZReKg1XqENA1zereb+8IxEft278QVi8dR2SBOhHwVpI8SSobo+.O0j9cm4YM44zS2JdQixi98NpI8k9JEvOMkB3OvSA76tf+uOZA8gdd1xKZTv9dlB3K8UJfeZJEvefmB32cc9+99xzjajaWSM0HfltkiFEvW5qT.+zTJf+.OEv+bqmxu9muzlavf8fB3GcJfuzWo.9ooT.+AdJf+4Sv9zOrtG7eGeqUEuKPoET.eouR2mVhHCPr0k9g2oyfSyycVCdQj3IEvWDItPCBOQRrT.+zT1rYCa1hu8AZ790SDQjdOEvOM0YNyY5COKS758j.Pt4NXzflRDQRen.9RGV7hpF.F80NC.nTkvyDQjzFJ05J.vhWzqBDLXegEBEVHT449tmRjXnVoxI6jepmSlnKHhj1RA7E750aeZch0gg+VoU+FQek9akV8G0mEs1ZqDsmkge+ca41IS.r26mMG82C6aQjnSA7kyha2A+4Pu+qlnKJR7j+Cxpt6EwV2wVYU22rXxKZqzpwehWX4Sl7FY9j+HyiY8j6fV6XauOdxmbQ3bj4S9izIO4NZnic0Ib+BLYm4Q94mO447tYGGrU.ngWYU3zoSxajij7b5jm7U1enkuRdn8C+366NYxNmEuv9aMpEwC9Jqh6d4+TV0c6jQle9j2jWEpQADo2Q8guPt4laGOt6A4ibcR5t138q9eiU6KKd1e3RXpetKm27GU.2OOOGrooyf82.O4H+ey+309N7y+Fsw6W8V3R+e+77N0uTL77bbyy9dX70WCSznVF2zWGO6acPt0wLX9nc9jbC27ix67wOE4N1oSMuy74uJuro0+3KQAScx7E+8eLS+aLOVBqm1W5pX9eogf8AmcTKgAZ98o50Ckri2h5qnMVeASkmbayh+su60EmeuRjTOJfu..U7Tyni9wOxkIVK93VnlWXk3xAfwAYQSG3V9+vOa4uIskUV7+.T862L+7uQF3iagGZASm7sCLkuGKgx48NZqbUG42Bre9u9M+L1aasQvm0Q4S7CiL2r32u9mfG80+uoYBV69+mlaEtJm375.ei3+ECc3YCzJ+pYkOOzaFpfcKOIM7ReWLZ2GW2pVE+sENF.XVq5V3970V79sIQRIo.9RGp3olQG8YevaKOwJJP3NF2H.+EfEN+uKy6KlCsE.x36NO9ICdv.+wPaCgNKheZGvAfwoZBXgLu4MOxps1.xf48Cbvfy9in77mLu9RdV13V+wbUC0fe0jGC9B8x0NvkzwYjxlY+7GjRBWVr6fNpy+o5rm6C9nLhwuCHR5I0G9RGrYyF4latgZFecO3a443yyLtaX0quV7kcdj+HyC6sredie+GGZCdSN3GbBLLZk8uiMvp4V3ltlAS9S7N.VM6b+9B0W81Y+65M3i+rp0WZ5O..rAEIQTPT03i.l1MdCbUCFN3tqlmc+vkDZukyPfpey+.sFZ.B5H6AyfGbnext2OX9DQhNEvWDoGXmacUuCqZ3aladLiDm4MRJXxylF9yAWaN.KXxii7xKel7beEVaM+BJbvf8q5V4cdwUwOd12LiLu7Xj4W.y92z.j4X39V6cypm8Mfy7xma9WTKCAHS61Axlh9gOJu4Ceqj+Hymm6+WzGzdcuIIUSTJRumls7jNX0ls65urRyVdAuE3riircDpE78vrF4ixOtgWhqytevginD70OsdRCrmsCbXuy0Zz5IoUbD8Zs62OsBjsCUi9dhls7j9JcAxhHmWNxtaiZdi.7l7l7W.r2iAmcP1QYnfXO6ASONBQbDQe0KhDSo.9hHW3x9KP80UOc+5.DQRdo.9hH8ANXnCWM6tHoRTe3KcP8guLvJ3ms5bFYTI0IQhmTM7EQhazLxnHIN51xSDItHxf8ZFYTj3OUCeoKrYK9lvcTWHXMb9lQFUy6Kx.OEvW5P7N3a79hKjjGtcG72AmrltoDZYQDqBEvWDY.mlQFEIwS8guHRbQEOUwQYYZFYTj3Eca4IIL51.zpwDvVDyHipl8hDOolzWDINwltHOQRfT.eQhAz.PTDIYmB3KRLhp4pHRxLMn8DQDQr.T.eQDQDK.MJ8k3nN+nVmSfJQNynmp0O3ZxfQDI0g5CeIt6rm.URculSMYvHhjpPMouDWE8IPkTsZ1GjlLXDQRkn.9RbS3l99BccIiNeSFLhHRxF0j9RBS5zDnR5zwhHR5IEvWhahb.5c1SfJCt6adRMMYvHhjpQMouDWE8IPkydYoBzjAiHRpDca4kh4Dm3DI5hP+PmeT6hu3fMtzoOsQDqOUav6E73oyikSmHKLwLCcnCMQWDDQF.nlzWhi5LfdmAGS0BxGofk8zk.8hHo2T.eIkzxV4qA.O9xmV2V9q2kkG9uCqmVdv08WGyKmhHRxB0G9RZqnETOZKqy08ZCjEGQDIgRA7kzdO9xm1Y0R.8l0IhHoST.eIsUjMe+1eCmJ3tHhkl5CeIs1iu7ow1eCmrmcuQ1yt6497WDQR2oZ3KosV1JecV1JectsI2z4bv5ElFzdhHoyTM7kTZQF.umZt9ycPd0D+hHVCpF9RZqnELWA3EQrpTl1KESpcl1SREnLsmHomTM7EQDQr.T.eQDQDK.EvWRM0dCT4JqjFZGv3jre26mSZbdeVhHhkkB3KonZlMrlMPyF.seXl7zmLGn8ddqa0Sk3zYkbx3V4SDQRtnaKOIEUFLDFRvGdoERSM0TWWsge7iCbD5S3NxBfLwQ7rHJhHIQTM7kTesueV9LWN6uc.NI6rxEgy7FIiLOm379pjOp0CxO568v.OD24rlLyZQakVSvEYQDIdS0vWRCXPs+tZYVFvIdmeFy9gyh25C+Xx23D71uxtnEFCy6QWHqe1YRE+76gbvNYmnKxhHRblB3KoEB279NtLm.OLO1JGN2wT9xbCEeGbUYC9GtS.HugOTErWDwRRMo+++s2cezQU8cdb7OiEj.BUCVJMTaAa.U5dHtR15CnxoAraAcqAWQsUiVenF3naUrsBG1iXcAKTviGMp0COrJ1COzRQrFeBWORXK3xBsafxfqAqgJXMIMIRFHOPFHy1e6eLgPRHSlGxct+tYtuecNbfbme7Keu+lu49M267ctCxnLz7JVe7d1hto+tyT6ZiySWx3xQa5iCqHQjzWeP1N7..rFJ3iLJebY+R8eT6v0z+dEqG+o920cHoZZJrFv.FjzGrE89+0lUyGoYw6fO.32PAejQYfmndM6ocIJmQLBMhuxjz+yrdF8cy6bTVWvT0O8p1r9NS3704W35oo8.fuC2K86mg6k9IhHJbygUDkkF5P6ZapDt4lkxZnc710CmNtW5CjYhC6gLPCPYMzdt07h01A.xzwkzG..vGfB9...9.7Z3iLVgBERRRYm84z9VBXufA.vx30vGYjl6O9sjjzXuvqURREWL+ds.veiKoOx3z4h84muT94KsxUxY2C.+MJ3iLJm7x3mrOF.PlNtj9HiV4kG8uq7CeKIcEVMV..rIJ3iLJYmc1c7uiVjumeL..+Ftj9HiyxdxqsG11zsPj..3cvaKOjQJPf.pgFZPR71xC.PhB9HCUf.ADo1..mBWRe...e.J3C..3CPAe...e.J3C..3Cv6CezuPf.zg8..8ETvG8aPW2C.j53R5C..3CPAe...e.J3C..3CPAe...e.ZZOesS0DbgBcDI04667R1+dOez3KTnizw8EeuES2V2r85UWEJTHI4k9rDn+S9lDe5JhLOTvGZt+3MKIowdgQ+Tlq3h8NcC+oGa1LZ5JucrE8iF39GOm5kiMaFM.NKtj99bc9.b4muT94KsxUZ6yzJpdN1rbP0tNWPs+Qr4keN0KGaVNn.bPTv2G6jW5xj8wbCm7xQmrOlafXK0P9FfcwkzGcn7xi92U9gukjtBqFKcGwVpgXK03kiMfTEE78w5bCSE8.a87iYCctgoN8XytMSEwVpg7M.6hKouO2xdxomPayF54X6ZsPjb55o3vaGad4mS8xwl234T.mP.C2fxcUmwYbFbOgG.Ir.ABn+1e6uY6v.Y.3R56xLFCE7APBiOoHgSgKoO..fO.E7A..7AnfO..fO.E78zBoxd68Y6f...Y.nfumVD0bCsY6f...Y.nfuW2YZ6....YBnfO..fO.E7A..7AnfO..fO.E7A..7AnfeFjvUues8x1tNPnHRRJzA1sd6x1sZxxwE..rOJ3mgn9suLcY22FUKmnEczVinv6+kz27deWch+5Kqq51WuBa6.D..VEe343UEIhBG4X5Dm11aR6uhORsoAJo1jF3WRi+hFldkmbGZdO5OWi6bGoxcTYo885aQ21RVkt9KqMcvMuDUUDob4Ya..eKNCeOnp29JzEOvApAO3wnE8m69Mdmv5nUUmpu95U80Wmpu9FkTc5PerzIpqZsqUbWZVqe+psiVkN9IZM5+i0tScHtt9..9ZbNedMg2ml2jmsB19Wd9m8P55iGoQ8G+CaS0oAKoVkN6yTS5pmfNmyOeccSaJZDWyYoe2iVsFxELNE8o2HREUfxMa2c2...dKTv2qY.edcA4IofRpvRTI2yD55imUtZVKXwm1+sa7tktkYLKMNUqthGcU5h9JCTe50Tnt8yWRSYI5G4FwN..7rBXLFisCB+j.ABn3tjGIrB0TaJ6rGVxM4gaRMMfgog0wuFWXEpIorGVVoRnB.OfD5XF.I.J36x3GdAPxfiY.mBMsmmVSZ6uzynE8LulpNhsiEjRhzjNvt2tJa66Sg70OG1jNv91k1tuec.vdnfuG19Vw8oIeWOndzGrPceuv9rc3fTPSU755EduZUyG3E0279eM4Wq00z91jdtMe.0xe4WogOyWhaFT.V.WReWVBe44ZZWZFe9KWk1wFJVUz5JzEwKGe+T6VSIv6pMYlq7yugIBcfWSOvxZVO+JtUkjcnhuEWRe3T3L78n1+ldt1K1WnV3RmujVodmOHjcCJjhBqW6g9IpfsTjutXe3p2tdtGaARSLWJ1CXATv2SpIs6srVIIM+M+7ZAycwZmKMO8Bu2Ga43BIu505enuq1+2YsZASYT1NXrmHQTVi5p0BVy6oKXC+Zc.aGO.9PTv2SJh9rpjjlul0zhVjXHYctRg69ccO30suUbu51d5F0Qd2mP29suHsee5GpA6+27v5hmwrzrlwUoO8NtckqsCH.eHdM7cYIzqGW38qGZviW6sjxUYOvDkjztelon7e06PMV1cxkCE8OENrZRCPCKKteekL30vGNE9IOKnlZpo2GPKeh98R5JycHsO1OUuzCtUooc8p1ZpQM6FAYZPjZ2kVziuV05fkF7EVjVv8bYY7IfG6XGSCYHCI9CLCWmWG5ul+BzeGmguKKPf.1ND.P+LbXZ3DxzOAKOo8rm8nQNxQ1KinEsgYNN07O+Sz8j810TmvsoJjTQqZGZYW2Xbonz4U4F9gZxOzlz3K5ozyU7koQMlwnyNCNCr1ZqUWxkbIIvy2Y1XcnuYTixG2rmvQkAe3VuqQNxQpbxImdcLS8NJRKXy+J8gKYdpBIIUftqBuBkyHbiHLcHhpntFjjzELjx0Tm7p0Nabu5h7AMjPh77se.qC.1EE78pNdPU5RVaGeYdK7QzT52VrWRpN8e8laURRktx0JoB0.sa.A.3qPAeKn1ZqsWe7CuqWP48fA6zVllV7MM932redXgq3E0iNzGQuzROnty4sVIcb8Y0VipICtCtN4yyw646LcrN.3MPS64xno8.PxhCSCm.mguEDylW5v6RybB2f1Qm1z3WzVzVtmw6Zwly6vZMScBZdi9ozddpuo16ye+5Ne1cHowqewVVutgwm41DWzrZQw5PeCMsGbJTv2B54lWpdsraqyE6KPEWzg0PtnQ2+tQmBeTc7KnPU3vJWO4OqbU0ZO4dXE59e7WWe62YAJ2TLKz1WsjVZokD58Xe5tY0r85fThcFntQS6Y60hDMm.vFnfuGwtWwORyaqm5qWWkkoacvqWW7+1GIMy9w2HRy5hzBd0Wsiub6SnJs04sUIUf1xFR8h8gBY+OHgF9vGtpolZT1YauORb7BqCRQiCatNbxXv17B4D.wBE7sft27Rgq72p7m8o5H+G92rOUvP9i5W9B+mJ3JWktx2eRRR5qck2jJ9tuQM19gu40qceuidtG6eUuv+c0sukspo9EucsiOYYZLovtyIWCi2kINYtbxoxXOzgNjBGtmuA46FMqVhtNbxw5zqEdk0gNO+oi8OmJm.vlno8bY19RNBf9e3vzvIz+6TEy.zkyVHxA0R9pSROqjjJRa6id.85i6R0Szs+OiWp8a.ORRSR+1JdYcYms6Du8Msn0Lywo4siaT+9peVcdRRG88zTG+Mqa7MpP22DSschz4Yn4Ti0MZVMat+kniysZZOas+kJiMYPS6AmBE7sftz7RMUi9j12dwk935uuwR0jkjTApzJ2jNuMcW5k+GVkV7TFl105Wnt7aaIRZG5YdsJUYy8psR7mbZRm8Hjj1j9AO12RuVIyRidneUMPIMhu5WV4jSe6VsWh1HXISCi4zi0MZVMat+kniystS6Yq8uTYr.toyv1Afu2.U6eb2lmtkqdzpp+PYRRZcUTpt9byVm+Ujudy2c+RJKcY25hUkabNRRZqu8dj8aQoDwf0n+54IIofqb1ZLCdJZJW0kqf4sTMyI3Ctu5B.3QvY3aAco4kZ4yzmIIowIEtFU+QqWROhl3Y2rpollkxNW01q96Tk+vwpyRRC4J+95QF+SqG+3g0gqoF0en0ft3adVRK49a+q1p1ZPIcumm9+poFkp26.SzFAKYZXLmdrtYS6Yi8uDcbtcS6416eoxXArAZZOWFMsG.RVbXZ3D3L7sft2TOe567S0kdmqRS5g+s5kenQp4NpIoK7M1mtmIdtRJr1vcec5Lez2T2vXxRRepVxntT8rS6ozG8h2hNKqsWjfZY2Zli6eR20uuZccmmzmtq0nu+MD8S.vI8Hugd46ahozzZ6ltxqzrZzzdo12Gam+jLno8fSgB9VP2apmb99+LUxubU5AehaPO6TNnVSCaSSY3SPGqzfZwW+DzTm9WRu3QGpxImQnc+ROldVIM+G9l0X6OzXPMkiFjjZ3yMTkSNCS4Li4pe21j9hSddZPiHm9byMY6ltxqzrZzzdo12Gam+.3lno87DFgdfRCp4HokL8wnY8aj1PCGTSb+Omlwhda84upYnxV2qnWdY2tx+tVozb1nl+T5m7a8OrwoePQRyK+eh1d0gkTDc3VNtjjtiBFmciM..eDNCeKnmapmufl6mrGMtmX959m8j0Jmsz89vOhlvfdKM67eVETR2jj9g+h2POzMLQ0bM0n9KexxVvB2gVTqSRS9KuxN11C+RaSe6uP6MlXJv1MckWoY0no8RsuO1N+AvFno8bYzzd.HYwgogSfyv2Bpt5pi+f5hHZC2cw5K9DunJ3bSKgT+DQTKszhzm6rTyG8vwoAohN15Nby5Ju7uQbGWxLmI1Xi5XG6XooO8zr89Wh98Opz85f81+R9bhjEMsGbLF3pRrk7VMM1XilVa6Tao7kVnYg6rgzVb40UwlKwTfjQs+mhV3qXjjo5pqNtiURl+bBLtjYN6swltY68uD86e5ls2+bqbBNLMbJjI4xh2O71PvM1oChjmY46rpnaeaKzTXIk6FgnmS4qtntbv2n+YR83AW64wJya7mRjwkLyYOO1zMau+kne+S2r89malSPAe3T3R56ozjJcA2j1ZGecPM6hWqt48NWMrQkqzlqyhwl6qgFZPG+n+Q8ytq01CO5YJoS0fTgBERANwGEiwJ0Pc0pZFZzwchl9e0OsOOmccrRRYkUVosOGz680hz+9Wht9dRoq0BmKmH8m+HkdyI.RVzzdtr.ABD6FvIxgzx9GGil2V67FmiprsmR41zaqY7.Mne8ZtUkkaDnV1wN1wzvG9v0wO9wscnjvFzfFjZngFb7WqZVKhxutNzqGy.HIvY36kLfgqN9vhMu7jBFTZNeak6.jJ6Ilt93uQPeQwdIogLjgnZpoFE9H6Q+KesopWoKOZQ5s+fkowdlmpQvNxQNhzw+S5QtjYbZi8UK+wzklyoF2wa780Bt7aVuQeXN69Xkhd1boiFSKdqEtw9Wht9dRoi0BmLmvMxejRe4D.oBNCeWV79s0Cs6Ungm+ri9EEVhp34KTu+yc85lVxkqfstBMA+RE+NooCsKs9M7NptiOHk623Zzzm1DUrtHoI5XSGyoav16edk0Bau+4lqCbF9voPAeWVh7Cug12qoEtfEnmtzfRRpv4uZUxidmZz9vh8.9cTvGNEJ36x3GdAPxfiY.mB2K8A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AnfO..fO.E7A..7AFfsC.+l.ABn.ABX6v..8SvwKfSIfwXL1NHfsbpm5CE5HRRJ6rOmN8319.MQiuSEaYayfoGX515lsWu5pPgBIoN+bpsiOx2.rINCen49i2rjjF6EdsRRp3h8N+NfmdrYynoq71w1aIo9KOm5kiMaFM.NKdM78457A3xOeo7yWZkqz1moUT8brY4fpcctfZ+iXyK+bpWN1rbPA3fnfuO1IuzkI6i4FN4kiNYeL2.wVpg7M.6hKoO5P4kG8uq7CeKIcEVMV5NhsTCwVpwKGa.oJJ36i04FlJ5A154GyF5bCSc5wlcalJhsTC4a.1EWReetk8jSOg1lMzyw10ZgH4z0Swg2N17xOm5kiMuwyo.NAda44qwaSp9Fda4kbHeCvlnfO..fO.WRe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3C3NE7izj1+t1kNPnHmbCJT80q5quo937jhaOo9VVupu9PpiHOzAzt109USoxTlFiSGcdbQwZ8zo1dhEDj+3nyiKh7GuQb5nyiKJcm+jVx25KLoY0syUajjQ4UjYyGrUio0flBkLR4Ec6EVhopTYdRwsaLGzLeISIk2Pb+dV9pKN5bHYTgK2TmwXZ8fawTbdQ21x2YhD4o+3LlySiUXVZQxnBWsowDYRrv3i05oSs83g7mdYdH+ItH+oWlGxeb77s9pzZA+1pZyFIYJYacZGpsFMUUU6K2sVto.IyFOXaI+7jBa2XLlctzBh9XkGmTj1pvTnxyrsFMFioRSQc7uippcVhQRlRiSrm1iyXMOsu1VXgxnBVd7+ABKO9Xsd5TaumP9SuLOj+DuHh7mdadH+oOs8zkzXA+VMqqPYxao6Lli3fad9FohMU1q6qwZdR1saLsFb4FohMkLmBMKcmw62bsNyBkLyYiAM0Uw5LREYpnawY4kTfQErZSq87D3RwYLlm1ZzTWiFSaUrbiTIw+GH7.iOVqmN016Jxe504wCjOjrim7GaDmj+3N4aNizWA+VKO5ugZLxWZL3xi9a1TYb1Mi07jra2ToYNRlkWQilJVdQlEF2D4SEiRpmS7abal7TAlx6scgzcbFu04xKIw9ABuv3i05oSs8Ni7m3LOsGhj+zyH+INyS6gH4Oo91SCRqMsWi5b0YNfd3Ahb.8Sxa1pjxaTWetYkxySxr8sunwpmtfkq+4wHcvCUkZs1ZUnP8VSCVuV+BlsJX9KWKrPo4M+UoC08FrXfmkNWI0VaNW7m7wYurNKIMvdO17TiOVqmN016Fxe584OZL16wlmZ7j+Xg3j7G2JeyIDqml56ZqMcXIMvdZANxwz4V7x02ahCK0mmjZ6Mo+xmVfxSaPWyk87RACpfZ7ZIEsZ03ZtS0SQQS69WoYWZwpxWcVJWMM0ZfwnE+V2hVw0O5tMxC6fwexGm855b+RwZ8zo1d6H+o2m+9sH+wMiSxebo7MGR56L7G1WSyTaUu4eHzo+XC3KoBKZRJ9maeuLOI01Glt0UTl1aYko8t28p0tzB0RKuQYVSLRhkjTXIcdZvRRZ3ZzEb5inoO3c0V00ouRu86sjtiydYcNhjhbrvRJrBKoHw4s.hsGerVOcps2Ej+z6yure9PxNdxerPbR9i6ju4TRmudAGrz4XjJ1TQ2dsIh95nHypi2qeeblmjc6mT4KMAZFkVqvrv1eaSHIixaNlfc9E9osnuVWEWZkNd7mTwYrlmVK2Tj5T7KYJrjxi8jX6wGq0SmZ68.xe5k4w14CI63I+wNwYrlGamOjriOcm+3.4aNgz76C+VMkNGYjJvrtsDzzPGIDsYZngDsMK5s4IY2dxpMSCUUk4fUUmoiFjs0FLA215hduDXNaLA6rxzcb5TyiEDq0SmZ6892bxebz4wBH+wCDmj+3N4a8co8a7NFiwT4N2no3BJvr5fISQ9DedR1s2WzZEqyTPAEaV21pzjruyIS2wY5X+McKVqmN01SDj+3ryiah7GuSbR9i6ju0WDvXLlzzqV....7H3COG...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...e.J3C..3CPAe...ef+e.sDa0XVZ4wS.....PRE4DQtJDXBB" ],
									"embed" : 1,
									"id" : "obj-1",
									"maxclass" : "fpic",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 6.0, 34.0, 503.0, 688.0 ],
									"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 16.20.18.png"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 3 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-35", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-39", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 2.0, 44.0, 969.0, 372.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 199.0, 432.0, 81.0, 18.0 ],
					"text" : "clean, wclose",
					"varname" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-198",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 199.0, 484.5, 250.0, 20.0 ],
					"text" : "linksections 1 1 p \"From OpenMusic to bach\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-51",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 199.0, 457.0, 69.0, 20.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 700.0, 7.74086, 56.0, 20.0 ],
					"text" : "onecopy"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-87",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 19.0, 444.0, 20.0 ],
					"text" : "_________________________________________________________________"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-61",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 722.5, 429.0, 97.0, 21.0 ],
					"text" : "Good  to know.",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"frgb" : 0.0,
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 290.0, 7.74086, 317.0, 25.0 ],
					"text" : "-  building a bach.score"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 22.256727,
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 2.924051, 300.0, 31.0 ],
					"text" : "From OpenMusic to bach (p)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-19",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 558.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 533.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 508.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-26",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 483.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach [o]",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 458.0, 40.0, 18.0 ],
					"text" : "t b b",
					"varname" : "triggerA"
				}

			}
, 			{
				"box" : 				{
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 433.0, 151.0, 20.0 ],
					"text" : "Back to section (o)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 830.0, 558.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 830.0, 533.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 830.0, 508.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-34",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 830.0, 483.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach [q]",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 830.0, 458.0, 40.0, 18.0 ],
					"text" : "t b b",
					"varname" : "triggerB"
				}

			}
, 			{
				"box" : 				{
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 830.0, 433.0, 151.0, 20.0 ],
					"text" : "Continue to section (q)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 510.5, 190.5, 510.5, 190.5, 452.0, 208.5, 452.0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-27", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-35", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-198", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-51", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "linksections.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/docs/tutorial-patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.repeat.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.help.searchtag.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/help",
				"patcherrelativepath" : "../../help",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
