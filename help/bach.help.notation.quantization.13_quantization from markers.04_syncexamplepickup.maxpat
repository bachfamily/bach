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
		"rect" : [ 383.0, 106.0, 811.0, 568.0 ],
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
					"format" : 6,
					"id" : "obj-22",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 394.0, 391.0, 59.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 203.214294, 438.0, 98.0, 23.0 ],
					"style" : "",
					"text" : "loadmess clear"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.28,
					"fontsize" : 13.0,
					"id" : "obj-23",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 455.5, 384.0, 156.0, 40.0 ],
					"style" : "",
					"text" : "Outputs added pickup time in milliseconds"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 394.0, 338.0, 154.0, 23.0 ],
					"style" : "",
					"text" : "bach.keys pickup @out t"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 378.5, 110.0, 37.0, 23.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 455.5, 179.916672, 52.0, 23.0 ],
					"style" : "",
					"text" : "pipe 0."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 435.5, 146.0, 39.0, 23.0 ],
					"style" : "",
					"text" : "t l l"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 435.5, 110.0, 35.0, 23.0 ],
					"style" : "",
					"text" : "play"
				}

			}
, 			{
				"box" : 				{
					"attr" : "tempohandling",
					"id" : "obj-37",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 42.0, 259.0, 254.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"linecount" : 4,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 37.0, 602.0, 65.0 ],
					"sendto" : "bach.help.filtertags",
					"style" : "",
					"text" : "If your automatic quantization gives birth to a pickup measure, even if #tempohandling is set to \"Set From Barlines\" or \"Set From Divisions\", you will end up having a constant offset between the original and the resulting score. This offset is output from bach.quantize's rightmost outlet. In this example, we use such offset to play the original roll together with its quantization.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "int" ],
					"patching_rect" : [ 334.214294, 438.0, 108.0, 23.0 ],
					"style" : "",
					"text" : "bach.ezmidiplay"
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
					"patching_rect" : [ 24.0, 209.0, 37.0, 23.0 ],
					"style" : "",
					"text" : "auto"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 24.0, 110.0, 61.0, 23.0 ],
					"style" : "",
					"text" : "quantize"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 24.0, 304.0, 108.0, 23.0 ],
					"style" : "",
					"text" : "bach.quantize"
				}

			}
, 			{
				"box" : 				{
					"constraintbeamsinspaces" : 0,
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-8",
					"keys" : [ "Em" ],
					"loop" : [ "(", 1, 1, 0, ")", "(", 1, 1, 0, ")" ],
					"maxclass" : "bach.score",
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 1,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 24.0, 341.0, 355.0, 82.666667 ],
					"pitcheditrange" : "null",
					"presentation_rect" : [ 0.0, 0.0, 0.0, 82.666667 ],
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7830,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ -2.4, 17.6 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 2, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 18350, 1079971348, ")", ")", ")", "(", "leveltype", 1, ")", "(", "-3/4", 0, ")", "(", "(", "leveltype", 24, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 52, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 52, 1, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 52, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 62, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 52, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 1, 0, ")", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 52, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 62, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 1, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 62, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 1, 0, ")", 0, ")", ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 62, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 90, 1, 0, ")", 0, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 90, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 90, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 90, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 1, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 62915, 1079726735, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 57, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 0, 0, ")", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 57, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 73, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 57, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 73, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 73, 0, 0, ")", 0, ")", ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 85, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 13107, 1079886643, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 85, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 1, 0, ")", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 1, 0, ")", 0, ")", ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 88, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 95, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 88, 1, 0, ")", 0, ")", ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 78, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 88, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 39322, 1079863705, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 88, 1, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 88, 0, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", 0, ")", ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 46, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 65, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 46, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 95, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 65, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 46, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 65, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 46, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 65, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 65, 0, 0, ")", 0, ")", ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 10486, 1079875010, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 0, 0, ")", 0, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 1, 0, ")", 0, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 69, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 69, 1, 0, ")", 0, ")", ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 69, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 39322, 1079863705, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 69, 0, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 43, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "-1/24", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 44, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 42, 1, 0, ")", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 44, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 42, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 77, 1, 0, ")", 0, ")", ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 34079, 1079910072, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 77, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 73, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 1, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 282, ")", "(", "tupletinfo", "2/3", "1/16", 1, 2, ")", "(", "(", "leveltype", 2, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 49, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 52, 1, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 49, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 52, 0, 0, ")", 0, ")", ")", "(", "-1/8", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 46, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 46, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 44, 0, 0, ")", 0, ")", "(", "-3/16", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 10486, 1079875010, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 40, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 49, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/8", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 36, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 55, 0, 0, ")", 0, ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 83, 0, 0, ")", 0, ")", "(", "-1/32", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 58, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 81, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 81, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 57, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 65, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 65, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 48, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 41943, 1079830282, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 0, 0, ")", 0, ")", "(", "-3/32", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 48, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 73, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 52, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 77, 0, 0, ")", 0, ")", "(", "-1/32", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 54, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 83, 0, 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 46, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 46, 0, 0, ")", 0, ")", "(", "-1/16", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 46, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 52, 0, 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", "_x_x_x_x_bach_float64_x_x_x_x_", 39322, 1079863705, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 0, 0, ")", 0, ")", "(", "-3/32", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 55, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 73, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 54, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 83, 0, 0, ")", 0, ")", "(", "-1/32", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 77, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 52, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 36, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 36, 0, 0, ")", 0, ")", "(", "-1/32", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 83, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_" ],
					"whole_score_data_0000000001" : [ 0, 1086224384, 83, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 42, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 85, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", "(", "(", "leveltype", 282, ")", "(", "tupletinfo", "2/3", "1/16", 1, 2, ")", "(", "(", "leveltype", 2, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 62, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 85, 0, 0, ")", 0, ")", "(", "-1/24", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 90, 0, 0, ")", 0, ")", ")", "(", "-1/24", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 90, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 105, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 105, 1, 0, ")", 0, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 105, 0, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, 105, 1, 0, ")", 0, ")", ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, 105, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, 105, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 95, 1, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 95, 0, 0, ")", 0, ")", ")", "(", "-1/32", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 100, 1, 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 18, ")", "(", "(", "leveltype", 2, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 100, 1, 0, ")", 0, ")", "(", "1/24", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 100, 0, 0, ")", 0, ")", ")", "(", "-1/24", 0, ")", ")", "(", "-1/8", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 2 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-7",
					"keys" : [ "Em" ],
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 68.5, 150.833344, 329.0, 81.166656 ],
					"pitcheditrange" : "null",
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7830,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ -13.2, 25.4 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 2, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "groups", ")", "(", "markers", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1082744831, "(", "marker", 1, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1084583935, "(", "marker", 2, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1085492223, "(", "marker", 3, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1086008319, "(", "marker", 4, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1086427647, "(", "marker", 5, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1086687231, "(", "marker", 6, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1086948351, "(", "marker", 7, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1087203327, "(", "marker", 8, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1087418111, "(", "marker", 9, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1087550975, "(", "marker", 10, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1087681535, "(", "marker", 11, ")", "barline", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1087812095, "(", "marker", 12, ")", "barline", ")", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2360, 1081205216, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 26480, 1081685745, 52, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 7616, 1081616326, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 11024, 1081960144, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 8384, 1081980776, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 48768, 1082098991, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 12576, 1081755164, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 46664, 1082678736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 16252, 1083211706, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 4718, 1082740936, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 13896, 1083203028, 90, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 27788, 1083909415, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 5768, 1083233399, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 47712, 1083922432, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083272448, 100, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 42468, 1084565279, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 61344, 1084040395, 81, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22020, 1084580466, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 21496, 1084014363, 90, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 50856, 1085361096, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 11808, 1081390714, 57, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 21504, 1081546907, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 24642, 1085415330, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 12320, 1081633681, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22020, 1085420754, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 2880, 1081598971, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 43516, 1085484750, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 18872, 1083341867, 78, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 40894, 1085490171, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 1312, 1083337528, 88, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 58720, 1085751577, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 25696, 1082255183, 81, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 30934, 1085754832, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 14144, 1082333280, 95, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 20972, 1085883908, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 6816, 1082185764, 78, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 21232, 1082359312, 88, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 19923, 1086008104, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 59768, 1083853832, 81, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 49288, 1083875525, 95, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 34604, 1086366270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 25664, 1081321295, 46, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 2880, 1081598971, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 29098, 1086391218, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 3136, 1081720455, 77, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 31200, 1081703100, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22806, 1086424571, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 23592, 1083359221, 73, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 33032, 1083393931, 100, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22282, 1086554461, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 18624, 1082229151, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 41157, 1086556088, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 16512, 1082341957, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 50070, 1086618998, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 16768, 1082463440, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 28574, 1086622795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 30400, 1082272538, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 37487, 1086685706, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 44032, 1083615204, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56361, 1086687332, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 24112, 1083602188, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 8651, 1086880946, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 26176, 1081564262, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65273, 1086885827, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 12352, 1081633681, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 61604, 1086913759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 31168, 1081703100, 69, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 31232, 1081703100, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 61603, 1086947654, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 23328, 1082246506, 73, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 2368, 1082289893, 81, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 47973, 1087002972, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 14400, 1082454763, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 13893, 1087005684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 256, 1082402699, 90, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 20185, 1087074018, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 512, 1080484741, 49, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 2560, 1080658288, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56885, 1087133675, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 16515, 1087135844, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 30409, 1087202009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 30144, 1082151055, 40, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 27776, 1082142377, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 34865, 1087301258, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 7040, 1080554160, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 53739, 1087302883, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 31719, 1087334882, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 61, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 37486, 1087363626, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 58, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 512, 1080484741, 81, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1442, 1087383926, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 17170, 1087385281, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 49676, 1087399382, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 48, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 34210, 1087417821, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 18624, 1082229151, 69, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 30400, 1082272538, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 32637, 1087468529, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 48, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 4588, 1087485885, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 52, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33948, 1087499714, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 54, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22938, 1087515713, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 35520, 1087516798, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 21364, 1087532525, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 46, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 29228, 1087550152, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 13920, 1082211796, 77, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 16256, 1082220474, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 21364, 1087600318, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 30802, 1087601131, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 27656, 1087617808, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080415322, 54, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 5636, 1087632858, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 50724, 1087648043, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 10354, 1087650213, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33424, 1087663500, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 49152, 1087664856, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 128, 1080415322, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 44434, 1087681397, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 5120, 1080727707, 81, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 3072, 1080901255, 90, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 46006, 1087698480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 42, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 1280, 1080450031, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 19268, 1087713123, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 28704, 1087713937, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 7040, 1080554160, 85, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1966, 1087728580, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 128, 1080415322, 77, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 128, 1080588869, 90, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 62784, 1087745120, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 12544, 1080935964, 90, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 10112, 1080866545, 105, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 48628, 1087760849, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 81, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 12032, 1080692998, 105, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 31326, 1087776306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 77, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 40764, 1087777119, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, "_x_x_x_x_bach_float64_x_x_x_x_", 1408, 1080623579, 105, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 20316, 1087792305, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080385536, 69, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4992, 1080727707, 95, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 54919, 1087812235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083272448, 85, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 29360, 1083320173, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 58.65625
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
					"text" : "See Also: tempohandling",
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
					"text" : "Objects: bach.roll, bach.score, bach.quantize",
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
					"patching_rect" : [ 6.0, 8.0, 312.0, 23.0 ],
					"style" : "",
					"text" : "Synchronization and pickup measures",
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
					"patching_rect" : [ 6.0, 476.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "Tags: quantize, quantization, marker, barline, sync, synchronization, original, content, pickup, measure",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
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
					"patching_rect" : [ 92.5, 110.0, 20.0, 20.0 ],
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
					"id" : "obj-19",
					"ignoreclick" : 1,
					"legacytextcolor" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 473.5, 110.0, 20.0, 20.0 ],
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
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 403.5, 378.0, 568.0, 378.0, 568.0, 170.0, 498.0, 170.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.815676, 0.0, 0.024589, 0.9 ],
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.815676, 0.0, 0.024589, 0.9 ],
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.815676, 0.0, 0.024589, 0.9 ],
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.815676, 0.0, 0.024589, 0.9 ],
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-7", 6 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.ezmidiplay.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
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
				"name" : "bach.gcd.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.mcapprox.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.quantize.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.is.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.geq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
