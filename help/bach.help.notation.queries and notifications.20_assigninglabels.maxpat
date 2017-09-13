{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 1,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 571.0, 79.0, 617.0, 539.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
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
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-32",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 407.88092, 442.0, 156.0, 23.0 ],
					"style" : "",
					"text" : "getdomain (label george)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 218.0, 442.0, 180.0, 23.0 ],
					"style" : "",
					"text" : "testdomain (label ringo) 1000"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-31",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 442.0, 182.0, 23.0 ],
					"style" : "",
					"text" : "timetopixel (label john) (1 1/8)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 12.0, 287.5, 295.0, 36.0 ],
					"style" : "",
					"text" : "The label is sent right after the answer router, for instance as: numchord <label> <content>.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 461.00592, 300.5, 126.0, 23.0 ],
					"style" : "",
					"text" : "print Ans @popup 1"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.31,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-27",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 108.0, 364.0, 199.0, 40.0 ],
					"style" : "",
					"text" : "we sum all the chords in all the measure and voices"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "int" ],
					"patching_rect" : [ 440.38092, 364.0, 110.0, 23.0 ],
					"style" : "",
					"text" : "bach.sum @out t"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "int" ],
					"patching_rect" : [ 315.0, 364.0, 110.0, 23.0 ],
					"style" : "",
					"text" : "bach.sum @out t"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-24",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 147.0, 324.0, 160.0, 40.0 ],
					"style" : "",
					"text" : "Each query is separately retrieved"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-23",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 493.38092, 394.0, 33.0, 21.0 ],
					"style" : "",
					"text" : "fee"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 367.5, 394.0, 33.0, 21.0 ],
					"style" : "",
					"text" : "foo"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-16",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 440.38092, 394.0, 53.0, 23.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 315.0, 394.0, 53.0, 23.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "bang" ],
					"patching_rect" : [ 315.0, 333.5, 130.38092, 23.0 ],
					"style" : "",
					"text" : "bach.keys foo fee"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 218.0, 112.0, 169.0, 25.0 ],
					"style" : "",
					"text" : "...and then this message"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 190.0, 84.0, 160.0, 25.0 ],
					"style" : "",
					"text" : "Send this message..."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 57.380936, 115.0, 154.0, 23.0 ],
					"style" : "",
					"text" : "getnumchords (label fee)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.380936, 89.0, 155.0, 23.0 ],
					"style" : "",
					"text" : "getnumchords (label foo)"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 7.0, 419.0, 589.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "This works exactly in the same way for all querying commands, both for bach.roll and for bach.score:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 315.0, 300.5, 138.0, 23.0 ],
					"style" : "",
					"text" : "bach.keys numchords"
				}

			}
, 			{
				"box" : 				{
					"cautionaryaccidentalsdecay" : 2563,
					"clefs" : [ "G", "FG" ],
					"constraintbeamsinspaces" : 0,
					"enharmonictable" : [ "default", "default" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-6",
					"keys" : [ "Bm", "Bm" ],
					"linklyricstoslot" : 0,
					"loop" : [ "(", 1, 1, 0, ")", "(", 1, 1, 0, ")" ],
					"maxclass" : "bach.score",
					"midichannels" : [ 1, 1 ],
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 2,
					"out" : "nnnnnnnt",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 13.380936, 150.0, 582.0, 136.0 ],
					"pitcheditrange" : "null",
					"showmeasurenumbers" : [ 1, 1 ],
					"slotwinzoom" : 250.0,
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7830,
					"voicenames" : [ "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 17.0, 17.0 ],
					"vzoom" : 70.0,
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "directions", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "dyns", ")", "(", "type", "text", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "(", "note", "notecmd", ")", "(", "chord", "chordcmd", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 2, "(", "note", "notecmd", ")", "(", "chord", "chordcmd", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "notecmd", ")", "(", "chord", "chordcmd", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "notecmd", ")", "(", "chord", "chordcmd", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "notecmd", ")", "(", "chord", "chordcmd", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "markers", "(", "(", 1, 1, "29/100", ")", "(", "marker", 1, ")", "none", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085699584, "(", "marker", 2, ")", "none", ")", ")", "(", "midichannels", 1, 1, ")", "(", "(", "(", "(", 2, 4, ")", "(", "(", "1/4", 60, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 7, "A certain direction", ")", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, "(", "slots", "(", 8, "f", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 7, "Another direction", ")", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "f", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 94, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 96, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 98, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 100, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 102, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 104, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 106, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 108, 0, "(", "slots", "(", 8, "mf", ")", ")", 0, ")", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0 ],
					"whole_score_data_0000000001" : [ ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085277184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 1, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 1, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 1, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 68, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 68, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 68, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 76, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 76, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 76, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 76, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 84, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 84, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, "(", "slots", "(", 8, "mp", ")", ")", 0, ")", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 2 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 514.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "See Also: timetopixel, testdomain, getdomain",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "seealso"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 495.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "Objects: bach.roll, bach.score",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "objects"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 299.0, 23.0 ],
					"style" : "",
					"text" : "Assigning labels to queries",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 598.0, 19.0 ],
					"style" : "",
					"text" : "Tags: query, queries, label, labeling, assign, retrieve, thread",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 32.0, 599.0, 50.0 ],
					"style" : "",
					"text" : "You can assign a label to each different query to retrieve them separately. This can be useful, for instance, to keep track of queries coming from different threads. To do so, just prepend a (label <labelname>) llll right after the querying command.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
					"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0,
					"hint" : "",
					"id" : "obj-9",
					"ignoreclick" : 1,
					"legacytextcolor" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 119.5, 333.5, 20.0, 20.0 ],
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
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
					"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0,
					"hint" : "",
					"id" : "obj-20",
					"ignoreclick" : 1,
					"legacytextcolor" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 355.5, 87.0, 20.0, 20.0 ],
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
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
					"bgoncolor" : [ 0.55, 0.55, 0.55, 1.0 ],
					"fontface" : 1,
					"fontsize" : 13.0,
					"hint" : "",
					"id" : "obj-15",
					"ignoreclick" : 1,
					"legacytextcolor" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 393.0, 116.0, 20.0, 20.0 ],
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
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 227.5, 470.0, 5.190468, 470.0, 5.190468, 140.0, 22.880936, 140.0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 20.5, 470.0, 6.690468, 470.0, 6.690468, 140.0, 22.880936, 140.0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 417.38092, 470.0, 5.13092, 470.0, 5.13092, 140.0, 22.880936, 140.0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-6", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-6", 7 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.sum.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filter.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.is.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
