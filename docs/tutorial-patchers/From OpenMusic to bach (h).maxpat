{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 7,
			"architecture" : "x64"
		}
,
		"rect" : [ 44.0, 88.0, 838.0, 476.0 ],
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
					"attr" : "continuouslyoutputbangifchanged",
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-34",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 555.0, 236.5, 257.400024, 21.0 ],
					"text_width" : 216.0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-30",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 467.0, 372.0, 355.0, 50.0 ],
					"text" : "We won't put the red cable in the following sections. Nevertheless, know that everything we'll do will be easily modifiable to work in realtime, thanks to that red cable!"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-32",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 571.400024, 264.0, 201.0, 55.0 ],
					"text" : "The bang can also be sent continuously while dragging"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-28",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 512.400024, 113.0, 260.0, 40.0 ],
					"text" : "There's no more need to click the bang to go, just modify the \"A\" chord"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 290.0, 92.0, 182.0, 21.0 ],
					"text" : "bach translation (improved)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 290.399994, 113.0, 29.0, 29.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-69",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 319.028564, 177.0, 19.0, 19.0 ],
					"text" : "A"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-68",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 457.828552, 333.0, 18.0, 19.0 ],
					"text" : "D"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-67",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 442.828552, 308.0, 18.0, 19.0 ],
					"text" : "C"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-66",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 476.828552, 282.0, 19.0, 19.0 ],
					"text" : "B"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-64",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 423.828552, 273.0, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "dump" ],
					"patching_rect" : [ 290.399994, 148.0, 62.0, 21.0 ],
					"text" : "t b dump"
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 22.0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-53",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 320.028564, 333.0, 136.0, 89.0 ],
					"pitcheditrange" : "null",
					"showdurations" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7400,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ -8.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-52",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 366.828552, 305.0, 76.0, 21.0 ],
					"text" : "bach.+ 200"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 333.399994, 177.0, 136.0, 89.0 ],
					"pitcheditrange" : "null",
					"preventedit" : [ "(", "chord", "create", "delete", "onset", ")", "marker", "dilationrectangle", "inspector", "popup", "slotinfo", "lyrics", "loop", "zoom" ],
					"showdurations" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7400,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ -8.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080459264, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080246272, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080246272, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080246272, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080246272, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 92.0, 174.0, 21.0 ],
					"text" : "OpenMusic tutorial 1"
				}

			}
, 			{
				"box" : 				{
					"data" : [ 9882, "png", "IBkSG0fBZn....PCIgDQRA...DO..DPUHX....fOwjPQ....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6c+GUTcdtnG+6jJAjb.CXhdjzSTC5Ig1xjJT+Elj6YLsIXbcCZq1zqRNMpUzSyQC1bEKcI1VzqDvlajXpqfdMZuWImkQLlwFCzz.zZxwqjTLsC8FrGoUqUXJfxDYDY3vz7d+iY32CLHN+Xum44yZ4Bl89c1yiv9g869Y+te2FTJkBgPnacaA6.PHD2ZjjXgPmSRhEBcNIIVHz4jjXgPmSRhEBcNIIVHz4FWvN.5SeWtZa19T.Ht3ty9sdCCo8CrcCc8Z6smP3angRhcImmub.XF2+S..YkkmGKJCsc5ysmPbqRS0c59uiepoBolJru8Mzifkyy+Ndnc5usmP3KnYRh6oqmdac1rYaDZms988Z6smP3qn45NcOpsVWesg+v6.L+P91IDiUZlj39WjHW6v640EWbwMBsKNO9dzhaOgvWQyzcZ.J5EWznbYOwnbYZ6smP3KXHPeqH9m9S+Iu1l8su8QgEVX.HZzNLXv.e1m8YA6vPnCET5NchIde.vu7W9dCX4esu1WE.1xVfvsayYCFjqirXrIn1c5dRZG72KDhQufRRb+OB7W6q8UGPB7fO5rPHFYAsiD6ojUIAVHt4oopNsPHt4EzRh8z4.KmWrPbyKnjDO3yAdvmirPHF8Bpcmt+Iux4CKDiMA7A6w2+6+8GUs6EdgWvOGIZKFLXHr6ZiK7MB3IwxNqdl7yEwXkTcZgPmSimDam2+PuLa+kOAM4LXGKBg1jl4VQzSpqjuKOx5OL.TajV3sVWxA4HRHzdztmSr8ZXIwNOL26Bxh56rDdfn7iAWPjbNwhwJMa2oO2wdE2IvYP9ElKv93c+DY5sQHFLMZ2osyYqzU2nys78Rdom.OFmjr9fKvFSQlcLDh9SidjXmbkFAHWVW5I..QG0DAGcGTiJgPKRalD6nYtP0fohWFS08h5FvRE0i8fYbIDZPAktSa0p0QtAcbI9PfEjXzta6k4POW0P5OIMa0JWOPDjBgNQPo5zBOSpNsXrHnbj3O9i+Xl7jm7HzhN3HKalb8W3Rrl3dedzjWI0Cj49OMEs3oEfhx.qDRHgfcHHzoBJGItolZhoLkoLhsqtRdZx6OmLwTvVvUcpMQksTEK7tCDQYfmbchEiUZzKwDPWVvbAGt2WZL+sFxl.KD2JBJIwM2byi35uZMG.iOmk9sjzYmKOIuWPLgHLjTXKMDo6zhwBsUgstZMrrjWJmteKJosWIUtljBXwVvhTXKwXUPIIdxSdxdnvVsRQqr+IvlHqLuJQ+.S0qEASHBmoYFwVmsjuGao59dcoMTEkT3Vnpe44CdAkPnCnIJrkiFNNot99pD8lei5vTz+V9YG3Wgk8seVvuOM.39VvxIqU+MXFSP6VTcgHPSJrkFhTXKwXQvuvVNuHEbuowd.fL4Tmei7ym4bXWC58jDP889pz330WFycBAl3MPPJrkXrJ3WXK6V4RtWdVl2Ae41Myi..lvbCGiO+wVEk8U1O6bgwPMud9LuUV.vo4kOQCTUNObvH7EBMkQtvVN+irICFXck8G8eQPDPL.fQdpGdpz3GUE.TZ8l4ISLNl97SkS9dmCHJl6J1IMbzrAfpq3iQlmODBubj3VO0qytAX6GicrrbvWMpGGPgs53JbE.XlfCqz50ZEXqjxDtNVsdcHtDo625WSCaXFbG.QufuMaMocyN5xAW0pUb3ihIgPuZDJrkcJ4AikqUnYpaQYvhZnSVQh25yRcRgsFdRgsDiECaRry+bYDwz92oE0KQcax.OZ7mBUd25mCpACFFxH15xu6Oj47L6mz17worMMYxIgz39e65XMoLQ.GbjUuXt8scRV5zhB3xTPByg8j9Kw4esmh63VNhzFRHgDjjXwXiZXbl7MpH2xUs2cmpFJOeEjkp9tGtVO5AnZpolFzRaQUrIT.pbK+hJUamRYBT4Z1hRoTJKEaRkc4snTJkp1Clkq1UYi25AiFxH7qBgXD448b5tdUVfBiFUFAkQiFU.pBOUK25efdLIVoTsaQkMtRjy5UOkpk1tn5nElkJi7KWcwZKVYLyWUczByTAnH6ipZ+VNRzVjjXwXkG6NcSUrItmhlMcW0J5sxWm8kWHoV02gNeqUvsxYF6otS2KmMyw2Ut7r6oB.XsadqL4HuF+lcrGpvcS1vO8sYSKMkaoXPKR5NsXrxCIw14PKLVZof1Hm412b7rylNAQbO6lZauJRIlagOPovVCKIIVLVDTF1kdeN1ZvbxQVcVLoc8ZXZh9sPKnRNRrXrJ3Ohs7HGX2d2Dw3ignbGgOhoH4jcDEq3KIOAHDh9SybqH1Ca0UFKzv3I1XikwGwCRI0zD.L84mJ0VyEBxQmPn8nwRhsi47VN8caEag0m0gwFPLIjH7WaI3EZBgFk1JI1YazR6CZYVrRaNgwEe7veoMYXVJDCh1JIdbwSu2cgFM55qY+3j33fp10h3ByN4PtKsjPbqRakDSL7M+Iupqu0hEHih3v26Y3a8XSmGsfr3vYkbvM7DBMHM4S.Ba0cBxOu7X2l6atm9w1iE9E+qgtIwxS.BwXklLIF.rWCKI14g4dWPVTemkvCDh1eZIIVLVow5NceN2wdE2IvYP9ElKv93c+jf6z.vMtwMBpe9BgmnQShsyYqz0reYtkuWxKmcxYJzHG3CBdWmXa1rQ7wGO1rIymHBsEMZRrStRi.jKqKcWSfbQG0DAGcGzhHGNbPWc0ENbHWjKg1h1LI1QybgpASEuLlp6E0MfkJpG6Ay3RHzfzDSd7CQGWhODXAIFs6mDhWlC8bUCo+jzrUqb8.QPNH8DydM1Eh.LYxiWCQpNsXrH3O4w6QcvQV1L45uvkXMw897nIuRpGHy8eZJZwSK.EkCTyM2LyZVyZLbaTN5HSd7hwJM5shH7n+yYRdk+uwenfs39I+fIVUFymo3ql2bGiFMwtPDHocexj0kELWPeOj0Ll+VYgA4DXgPKRSVXqqVyAv3yYoeKIc14xSxcQtBNjBaIzpjBaogHE1RLVnsJr0Uqgkk7R4z8aQIs8Jox0jT.K1FNRgsDZUZnBa0JEsx9m.ahrx7pD8CL0fXgjbhc61gH5a58TJrkPqQyLhsNaIeO1ReyKOTZCUQIEtEp5Wd9fR7btJdYVngHH1XimXGeDjy+qyDThCgvazDE1xQCGmTWeeUhdyuQcXJ5eK+rC7qvx91OK32mF.beKX4j0p+FLiI3eC65NxF3w2zwFvxN711oGicgHXSJrkFhTXKwXQvuvVNuHEbuowd.fL4Tmei7ym4bXWC58jD3dPe.PZb75Ki4NA785nNV8Le7derwzqYjCzPQRgsDZOAtG6Stvfefp0dspL54Aol4KpZu1hc8PSCSJyMzlp1ByPkaksnTpNUmozbcuNTlJ7T9m.rSKpLc+Yz2+VqphOoog+gAmOPP3WEhPDA+BaEA3p1uF4od3oRieTU.Po0almLw3X5yOUN46cNfnXtqXmzvQyF.pthOF+xsmeTIydu3Y3Gslmfo26B2OGtLovVBsofegs53JbE.XlfCqz50ZEXqjxDtNVsdcHtDo625WSCaXFbG.QufuMaMocyN5xAW0pU+x7PccGeW7iNv6LfkIE1RnUIE1RCI.+qBQHhfegs.t769CYNOy9IsMebJaSSlbRHMt+2tNVSJSDvAGY0KlaeamjkNsn.tLEjvbXOo+Rb9W6o3N70AmTXKgdSf9jvwiEGpEUwlbUDobK+hJUamRYBT4Z1hRoTJKEaRkc4snTJkp1Clkq1UYi9m.TJrkPmI3WXK.3tYilsP1.Ernow5dC3HscQR4buBKY6UPrOzRnpReSJqnmlTW09frOJ4tP+zQtjBaIzYzVOjwc1LGeW4xytGWclcsadqL4HuF+lcrmd6d6F9ouMaZoo3WelL4oQrE7U.9M90tSGf+UgHDgTXKMDIIVLVnIJrk24jir5rXR650vzD8agkKRgsD5LZnaEw9yA1s2MQL9XHJ2Q3iXJRNYGQwJ9Rw4eCNGWg6ZHKbsTwIxlz+BEI2JhBMGMRgs5is5JiEZX7Darwx3i3AojZZB.l97SkZqI.7XbQJrkPmQikDaGy4sb561J1BqOqCiMfXRHQ3u1R.IJNe0uB+nC7Nz++jwg21OIf7YKD2rzVy1kNaiVZePKyhUZyIDW7wC+k1vA32pLcas0FccseK+OV0g8vZucfANrKiJpnHt37ycuWH7BsUR73hmdu6BMZDrXAx9wIwwAUsqEwElsE+VB7MtwMHgDRft5pqgoE+J.XVyZV8tjHiLRZqs1H5ni1OEUhaV21scaZ1p7avfA9rO6y78a2fwkXZjdHia6rkP7otdWuHiho98lA+9W4IY4ELOrzYIjre7BDaylMb7oeL+q22ixaNf0jIU7IEwLt8aLfDVe4QhkGx39FZ4eN5uhMMWRL.1p6Djed4wtM6ZtmNibOHEusmgo5OGgG8i8+bM75G4cokthjDm8WkEkdJ3u6zrVdmO8Ds7OGCoRhG9q0pCp+CpjpeeKbsnhhIcW2EwO4oyrl67XZ944UqfMYDa4aHIwA.xH1Z3oU24SOIbLIViLhsbvw2v8wydr0Rk0+iII2U2xQy0vlm0RomQw7lei5XSOjS16xlE63zvZ2+o3Gu3YDnCe+BYDa46Yu0+LW7OcIZrYabGS+qvCmb++YrcNaUUyepM39lsIRYpwLJWmFT.5tkpW3oamuFKWYDTXJekkVZW0Y28sp1sbv9cKAlqpgV5aN4BxU0RfM78aBB+pHjTu+bryZcsOEFUYXx3flW1ZQ8pY3ZcYlgq0U7YZYTrNeTr4ioIRhaox7Gz8uqQ0QuXmtV4ft+de0ZsnNXltmX8J0RfN78ajjXei9RhqWU5QqU0ywCtn4rUPFJKcpTcVuqCLTo6bySkuQElNnpc0HuNeVr4Esa4UGX9fobUmoktG11G7mis.p2xuaPsvBG3HmlE7zIALdRMc3vtuiD9fybcJpnlnohb85f4SJQgFVTO.qXY88x64e7AA9cbitgyel2BLVLyx8iJ2u7hWCrs2hya+YHhQXcoDv5UcW.ERKpbHNGMwgW68v7NXFnxYtdr0Akj39OfIFNUrkGkD1xPW9ge1z3vOqeHnDgvbx68+dUPFGjGLF37s2NLuoQO4jw72+OB7VzMPDiv5BX5Fv3DHNfwEUB72eWfoIL7CnHMRgsfKe1SxQM+g7oDEyXNONe8Emhq4OqqUCqNok16sFXgGuT9vktRWE6xeMOaEDHE1xewIUUziwhJHCNSKOCQg6bju3z6am+3uGL49aGo0EvDQjfk8x11dKzYsaicaNaZTk7v1bMysh3TV72gYu3uyPZaqM7ezu6s2rXQKHYpqmWF4cxjmxTPiW6PQPSqbn0MIV09xFKs+Rjr6cThHRvR40hiMlLQA3rwZoZfH7x5Bb5BvHyaA+Sv+P9rayaie7gVMk7LCShrO370uovM0jMW2pxy1XumfetkeQkRoTsT+YTlMWopg1F9S1WuIH7qhPR89yw1pUkMnfrUmow1Ts0RKpFarQUacpTc1PoJ.0QquMkR0lxb1nHiRUcpF404yhMun8ZKVgwWs2Oy1qsPETnpsgo8ZhBaMrt5Gv12sqgdYRq8P7u7f2tqBYMg6kYOa.GshTWKgmX+xeD6F.1My6d1cuKuvyzF4L2UPsG7iH0jh28Ryhyzx2z0MWShiv5BTh.vx0vNPTNsyu8CNMXbQCa2lkQrkFR.9WEgjtYFUTNsaCaNfXt63FRR5HsN+crYutRHViquuEXLaN0IJfGdXt4AzXicZ2bdY162ZNriSCou0RYueWSA1+RXPfL1o8MBGuUD0LE1pGNasF1bByicCTX40SNo+.A1fSnq46RRTXy1mB.wE2cBnc6AoF5VCxAmsrcQpKeaPF4Ss6cyjRBg5G+UnUkyyWN.Li6+I.frxJXFMiLMPgsbP8UeTxakagSSZ7Ruwo4odnoAXSJZkHnHmm20SDyYb+OAolpqksu8ocSj0XiXqSyl9lowlBnQiPzGa1F9m501rYSSNmpoYFwVg6jQrk1Ts055qM7GdGf4GTikgilqvVBQvT+ORqqDWOuNsDM17NsPD7UzK9DipkoUnMuNwggjqSr1SOmerV+RLIiXKMDIIV6PKOWcMXRgszHjBaIFqjBaID5bRgsDBcNIIVHz4jjXgPmSRhEBcNIIVHz4jjXgPmSRhEBcNIIVHz4jjXgPmSRhEBcN4FfPiveMSHJFaja.hQvv+Cl9V9.mkA6wfS981rQnVe6ID9FZnY6RWF5rLnmS5GsyFgZ8smPbqRScNw8eG+TSERMUXe6anGAavyFgtZm9a6ID9BZlj3d55o2Vm2lMB0KaOgvWQy0c5dLZmkACUZmVmTPRsKMSRb+KRzPmkAuy988itYiPs91SORuTs1vMZltSCPQu3hFkKazMaDp02dBguP.+5DO7tYuDNda1HTtDS9R5oqaZ3FMTR7MGYmp.K4m2ZWZptSKDhadRRrPnyIIwBgNmjDKD5bRRrPnyIIwBgNmlYDaMVHCEPeK4RHoOoaShkc37sj+fn9kzcZgPmSRhEBcNIIVHz4jjXgPmSRhEBcNIIVHz4jjXgPmS2d+DKtU4sI4.7x5kqqrVgtcvdH7M717n8ncd1VD7HcmNLl2lGsGsyy1hfKIINLk2lGsGsyy1hfOo6zB.uO+XGpL+YGJRRhCSMZmGsGMqWDbIcmNLl2lGsGsyy1hfK4RLEl3JW4JCZI88q8O2myUGx9a+Mmd78540OvBbcW20ccKGihwFo6zgs5KI7u829aCYY8m2VuH3RRhEto36+CdlgrzWXmGx82IIvZUx4DKFQoj5Wz+rgcZmVapIZ0lC+y1OLhjDKB3ZplCggHhkIsnEwjhe77f+fSf8fcPoiIIwh.qVqh6YdqhhOUin9c+NTcZg4UPd7u2jmKplv6jyIVDPU2a9xfoCRVObBtVPTISIpeWvMnz4jj3vTe+ev2dT0tG6wm8PJ3kqhcM1JzU2c0NFS2HQMld2BOQ5Ns3lleqXWhwDIIVDPEQjfkJrfTSZeGIIVDPk7WOGn5UwOqlVcs.m+Q1jgGjJjBaMlIIwh.q6NcZ7TuJqedSBCKbgXHhYPUYmGKHAo7LiUxXmNLgmF6zC9baerGe1C488t+hOxiauyV6mLfWeSO1ocZmlZrMH13Ig3h4l68JF.4O+E1xvfRD87vtDfyV6+O74C6xwECILUI40WP5NsPnyIIwBgNmjDKD5bRgsBSLzBaMXt1MvSCjiQy4DKSJ.AORRrvMuMYxK2OwZUR0oECfLYwq+HmSrnWxjEu9jjDK.79jIuP6R5NsvijIKd8CIIV.byMYxKzVjtSK5kLYwqOIWhIga8rafArYyFfbIlzKjtSKbyURpACFP9655KR2oEBcNIIVHz4jjXgPmSRhEBcNIIVHz4jjXgPmSRhEBcNIIVHz4jjXgPmSRhEBcNYrSGx5lc51QMn1Mz0qs2dgujwNcHtQ6zsyPam9b6ENR5NcHrQ6zsSNO+63g1o+1dgqjj3PTi1oamdtsC8b6r0uuWau8BmIcmNLwnc51ITocgSjj3PTi1oam3hKtQncw4w2iVb6ENS5NcHrQ6zsSQu3SLJWl1d6EtRtDS5b21scaxLwgaFLXfO6y9rfcXDvIcmVmSoTRRraFLDddsiktSKD5bRRrPnyIIwBgNmjDGVwNu+gdY19KeBZxYvNVD9JRgsBiTWIeWdj0eX.n1HsvastjCxQjvWPtDS5bi5I6c60vRhcdXt2EjE02YI7.Q4GCt.rv0I9do6zgIN2wdE2IvYP9ElKv93c+DYrGGJP5NcXA6b1Jc0M5bKeujW5IviwIIqO3BrwTjgtndmbj3vBN4JMBPtrtzS..hNpIBN5NnFUBeCIINbfil4BUClJdYLU2Kpa.KUTO1ClwkvmP5NcH.qVsNxMniKwGBrfDi1cauLG54pFR+IoYqV45AhfT32HUmVmKbc7BObBG2cVNRbHfO9i+Xl7jm7HzhN3HKalb8W3Rrl3dedzjWI0Cj49OMEs3oEfhR+uDRHgfcHDTHGIVmyfACzTSMwTlxTFw1UWIOM48mSlXJXK3pN0lnxVphEd2AhnLvHb85DKGINbQWVvbAGt2WZL+sFRk.GNSRhCAzbyMOhq+p0b.L9bV52RRmct7j7dAwD5BR2o04jBaMPgi6NKGINDvvVXqqVCKK4kxo62hRZ6URkqIo.VrEHEtVXKIINDvjm7j8PgsZkhVY+SfMQVYdUh9AlpWKBlPeQFwVgnNaIeO1R0885RanJJovsPU+xyG7BJgegbj3P.CtvVNZ33j556qRza9MpCSQ+a4mcfeEV129YA+9z.f6aAKmrV82fYLAY2.8LovV5bRgsFnvwcmk+DbHfATXKmWjBt2zXO.PlbpyuQ94ybNrqA8dRBn9deUZb75Ki4Ng.S75uHE1RnaMfBaY2JWx8xyx7N3K2tYdD.vDla3X74O1pnrux9YmKLFp40ym4sxB.NMu7IZfpx4gCJwu3ViTXqPMQ.w..F4od3oRieTU.Po0almLw3X5yOUN46cNfnXtqXmzvQyF.pthOFYd9PeRNRbHfATXqNtBWA.lI3vJsdsVA1JoLgqiUqWGhKQ59s90zvFlA2APzK3ayVSZ2ritbvUsZEGAk+GHtUHE1RmSJr0.ENt6rbj3P.CdDac428Gxbdl8SZa93T1llL4jPZb+uccrlTlHfCNxpWL291NIKcZQAbYJHg4vdR+k37u1SwcDz9ewstv0BagRnqAnZpolFzRaQUrIT.pbK+hJUamRYBT4Z1hRoTJKEaRkc4snTJkp1Clkq1UYiA3H22Kbc2YovVgjta1nYKjMPAKZZrt2.NRaWjTN2qvR1dED6CsDppz2jxJ5oI0UsOH6iRtKLL8nXg.jyIVmyfACC+M.gyl436JWd18TA.r1MuUlbjWieyN1CU3tIa3m91roklBgByg7IjPBgkmSrjDqyIE1ZfBG2cVJrUH.uOGaMXN4HqNKlztdMLMQ+VXEvEtVXKIINDfmuUD6OGX2d2Dw3ignb+a7GwTjbxNhhU7kjm.D5cRgsBwYqtxXgFFOwFarL9HdPJoll.foO+To1ZtPPN5D9BRRbHM6XNukSe2VwVX8YcXrADSBIB+0VBdglvmQRhCk4rMZo8AsLKVoMmv3hOd3uzlLLKCAHIwgxFW7z6cWnQit9Z1ONINNnpcsHtvrSNj3RKEtSRhCoECeyexq55asXAxnHN78dF9VO1z4QKHKNbVIGbCOgOgbch04FMOAHrU2IH+7xicatu4d5GaOV3W7uFbShuwMtAQGcz9rsW35S.BIIVmaz9XbA60vRhcdXt2EjE02YI7.Ao9SaylMlxTlBVsZk3hy2bYtBWShktSGl3bG6Ubm.mA4WXt.6i28SBdSC.Nb3ft5pKb3PaWZM60UBFLXnu+svMwINm1Z5SPRhCKXmyVoqY+xbKeujWN6jyTnQNvGHWmXuqKfBoEkht6rMp86.Yjz2f2WCkGKIwgEbxUZDfbYco6ZnIFcTSDbzcPMpzOhhn.FWTwQJqn.JMip4EMWWvNn5kjDGNvQybgpASEuLlp6E0MfkJpG6Ay3RWJJRdgl3BsbifcfzKYrSGBvaOUDoiKwGBrfDi18SBwKygdtpgzeRZ1pUttONdbzQGvcbGi30ftmX1qwtVTjfVZTxHUmVmStUDGHe8ty1q6kIViP6pM5dVD0Au9RFOuwRpm25Yd.e5m0Xkbj3P.d+VQrCNxxlIW+EtDqIt2mGM4UR8.Yt+SSQKdZ9nnnCNPByDp7z72sqWjosm8vbGgIrqlatYl0rl0X31nb34+tUDuF1c3jH51FezquUVoYSbl+OZiDXPRhCI38aEQ3Q+myj7J+ei+PAaw8S9ASrpLlOS4t8UQgch0HDaBSkaORmbaQ72wTlRLd8cMZh8fqHA1F2y32lqWZJaJudyLWu+es.FIINbQWVvbA88PVyX9akE5yRfAX7DKvKczeNK7BlY2SKVJt11Yiong1aeLHljWGJ05B1gwHRRhCA3shCc0ZN.FeNK8aIoyNWdRtKxkufSN6Q1EEYAp2x5omOoVs1HVsNgAztN5nC3ycGb8qc0QUrK7NovV5bRgsFnvwcmkiDGBXXKNzUqgkk7R4z8aQIs8Jox0jjONB5fir5Yxlp.1vO8mRSOaoj0kJijcu2UcGYC73a5XC587U.9M5jBaosIIwg.7bwgZkhVY+SfMQVYdUh9AlpeoPRYWdKX2vjXRKbwLuL9+xcMkovTFGfi5Hmgj.CvDGgXWbyPFwVgnNaIeO1ReyKOTZCUQIEtEp5Wdd+zmXTLIi.c6j+y1OL+227KyYa0Izc2ddTgkzB7SwQ3G4Hwg.FbwgbzvwI002Wkn27aTGlh92xO6.+Jrru8yB98oA.22BVNYs5uAyXBiscCFvHyxwE4OZA1kwY3ZkU+bb7u5iwT9BepG1IKSd8W8+Jq3+x1jBa4CHE1RmSJr0.ENt6rbj3P.Cn3PNuHEbuowd.fL4Tmei7ym4bXWC58jD3dPe.PZb75Ki4NAFE7zHypCNvxlI4cZHojf5qGNzGdddrOeeCYqFp9.78WYd8dN5e8bN.uYQqQJrkuP.8w2lvmiA+TQr8ZUYfqmHhYY9hp1qsXEfBLoL2PapZKLCUtU1hRo5TclRy085PYpvSMJ+DaWUrQTGr9FUklQFJyWrckRoTMTdgJ.0qV+EUklYlpyzdeuiZOXl894z2+RaXdhNdq8yhvQRgsB0DAtGn9F4od3oRieTU.Po0almLw3X5yOUN46cNfnXtqXmzvQyF.pthOlQ284deiLqO5BlIioEKu7YsSho+83fl.51I1azN+m8zbG0wKspC6gsi9djbokHcmNDv.JNTGWgq..yDbXkVuVq.akTlv0wp0qCwkHc+V+ZZXCyf6.H5E7sYqIsa1QWN3pVs5k6vtQZjYMN9iUCX0Nol9Wgta1JVuNPGVcGOCxL+yhoh..fAEkDQAQEdPngegTXKe.ovV5bRgsFnvwcmkiDGBXvEG5xu6Oj47L6mz17worMMYxIgz39e65XMoLQ.GbjUuXt8scRV5zhB3xTPByg8j9Kw4esmhQ3tGDuMxrFNe3qtRVR9UOnkJiXKelf74jKtEgGKNTKphM4p.R4V9EUp1NkxDnx0rEkRoTVJ1jJ6xaQoTJUsGLKWsqxFGkehsnxumBXkQlpZ61KMuSKpLGRQsPAOtTXKeDovVgjta1nYKjMPAKZZrt2.NRaWjTN2qvR1dED6CsDppz2jxJ5oI0UsOH6iRtKbzdTrgYjYMbjQrkemzc5P.dt3P2E4boOlYtqb4YW+iv9VOr1MuURNx2g0m5dvBvxA1vO8sYSKMEt9nct1Z3FYVoLLWjYGxH1xeSJrkNmTXqAJbb2Y4Hwg.t4KNjSNxpyhIsqWCSS7l4Sx6iLqgiLhs7iBxmSt3VDiphC0op81aW0Y+JBUsElgJ+yz1M8m2HMxrFNxH1x+RJrUHNa0UFKzv3I1XikwGwCRI0zD.L84mJ0VyM+iwkgcjYMbjQrkemjDGRyNlya4z2Un0BqOqCiMfXRHQ3u1xXXa1IsTMbstGOegmZgbmdq4CW0o+B+Sb6QFIQEk7XN+VkbNwgxb1Fsz9fVlEqzlSHt3iG9KsgCXDeRMLTwvhLeT59eXRjRJabDaYas0FccsOkO2PVSlTQYealwsubb3vQuSXeQEUT9rGyogSjj3PYiKd58B+XzHXwBj8iShiCpZWKhKLaK2jIvtj7StLu1labiaPBIj.c0UWdXsGlz+BCsK1QFYjzVas4SeviGNPtDS5bd6gLtsyVBwm55c8hLJl52aF76ekmjkWv7vRmkPx9wdyZylsapm+v2pGINb8gLtjDqy4sjX.rU2IH+7xica108cTF4dPJdaOCSMD6zQkjXgtjACFFgq0pCp+CpjpeeKbsnhhIcW2EwO4oyrl67XZiw4UKsrDRHAIIVn+HiXqAJbb24Pu+bbXngdjXGb7Mbe7rGasTY8+XRxc0sbzbMr4YsT5YVfdyuQcroGxI6cYyhcbZXs6+T7iW7LBzguOiLhsD5R3oQ8TikqLBJLkuxRKCbjZ0tkC1uQMUtpFZou4jKHWUKA1v2mJbc2YYvdDBp0y8Qtl5bpdaXbRtFoVk8mcUk3XlYpjYusr.du+RDrD2KHqR+ugO8AknHfP5NcHfAe67Uuke2fZgENvQNMK3oSBX7jZ5vgqv0Z9fybcJpnlnohb8Ze2SJQQfhTXKcNovVCT33tyxQhCA3oKwzkO6I4nl+P9ThhYLmGmu9hSw07m00pgUmzRw8AhoviWJe3RWoqhcMplmsztBWKrkjDGBvSOYAmxh+NL6E+cFRaasg+idSfgrXQKHYpqmWF4cxjmxTj6uHcFIINrhSp8MKs2Wka4+.R9tmJ+Oq+Lr7+iN3K9vOhj.qCIIwg.F0ySUW8CX6610PuLo0dH9Wdva2Ugrlv8xrmMfiVQpqk9iTXKcNovVCT33tyxQhCA304oJmWl89slC63zP5asT1620zX5VPTqSJrkP2xSE1pGNasF1bByicCTX40SNo+.A1fS32IiXqPVN3rkschXRyicmQ9TaicJIvgnjiDGBXfE1xA0W8QIuUtENMowK8Fmlm5glFfMonUgnjBaoyIE1ZfBG2cVNRbH.e4DvtdlTXKgt0HUXKQnOovVBgNmbj3P.xSVvvaRgsz4jBaMPgi6NKGINDfTXKWjBaIzsjBaEdSJrkPnyIIwBgNmjDKD5bRRrPnyIIwBgNmjDKD5bRRrPnyIIwBgNmjDKD5bRRrPnyIIwBgNmbWLoyI2ESCT33tyxM.gN2vuSaeK2lsOE.hKt6reqevI+pA0tgtds81K7kjDGhKmmub.XF2+S..YkkmS5GZ6zmauvQx4DGBq+63mZpPpoB6aeC8HX477uiGZm9a6EtRRhCQ0SWO815rYy1HzNa86601auvYR2oCSTast9ZC+g2AX9g7sKbhjDGhp+EIx0N7ddcwEWbiP6hyiuGs31Kblzc5PXE8hKZTtrmXTtLs81KbkbchCYo0ujPxkXxWQRhEBcNo6zBgNmjDKD5bRRrPnyIIwBgNmjDKD5bRRrPnyIIwBgNmjDKD5bRRrPnyIIwBgN2+eDSKrWZre2WL.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-21",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 113.0, 288.399994, 332.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-07-22 at 15.26.41.png"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-56",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 47.0, 794.0, 36.0 ],
					"text" : "Very well. We can translate a simple OM patch to bach. Yet, the idea at the very base of bach is that user actions can be intercepted so that modification can be performed in realtime – with no need for a \"bang\" or \"evaluation V\" key."
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
					"patching_rect" : [ 199.0, 479.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 531.5, 250.0, 20.0 ],
					"text" : "linksections 1 1 h \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 504.0, 69.0, 20.0 ],
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
					"patching_rect" : [ 476.828552, 444.0, 191.0, 21.0 ],
					"text" : "I like bach's djay nay say kwah!",
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
					"patching_rect" : [ 298.0, 7.74086, 317.0, 25.0 ],
					"text" : "- bach's je ne sais quoi"
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
					"text" : "From OpenMusic to bach (g)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 576.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 551.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 526.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 501.0, 162.0, 18.0 ],
					"text" : "From OpenMusic to bach [g]",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 476.0, 40.0, 20.0 ],
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
					"id" : "obj-9",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 451.0, 151.0, 20.0 ],
					"text" : "Back to section (g)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.0, 576.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.0, 551.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.0, 526.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-15",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.0, 501.0, 158.0, 18.0 ],
					"text" : "From OpenMusic to bach [i]",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 683.0, 476.0, 40.0, 20.0 ],
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
					"id" : "obj-18",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 683.0, 451.0, 151.0, 20.0 ],
					"text" : "Continue to section (i)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-16", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 557.5, 190.5, 557.5, 190.5, 499.0, 208.5, 499.0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
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
					"destination" : [ "obj-52", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.8, 0.0, 0.0, 0.9 ],
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 459.899994, 268.0, 496.899994, 268.0, 496.899994, 143.0, 299.899994, 143.0 ],
					"source" : [ "obj-25", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-34", 0 ]
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
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-52", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-7", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-9", 0 ]
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
				"name" : "Screen shot 2014-07-22 at 15.26.41.png",
				"bootpath" : "/Users/danieleghisi/Desktop",
				"patcherrelativepath" : "../../../../../../Users/danieleghisi/Desktop",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
