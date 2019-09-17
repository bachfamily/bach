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
		"rect" : [ 77.0, 44.0, 791.0, 498.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-34",
					"linecount" : 9,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 303.0, 246.0, 137.0 ],
					"text" : "Also, in bach there's no concept of \"miniview\", just because there's nothing hidden: all you can see is all you can edit: double clicking on a bach notation editor will do nothing at all.\nIf you need to hide a bach.roll or a bach.score (for clarity, for efficiency, for your own good reason), just encapsulate it inside a subpatch."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 63.607239,
					"frgb" : 0.0,
					"id" : "obj-33",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 406.0, 320.0, 74.0, 78.0 ],
					"text" : "}"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 63.607239,
					"frgb" : 0.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 406.0, 162.0, 74.0, 78.0 ],
					"text" : "}"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 461.0, 297.0, 162.0, 21.0 ],
					"text" : "bach.score"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-29",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 461.0, 141.0, 162.0, 21.0 ],
					"text" : "bach.roll"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "FG" ],
					"constraintbeamsinspaces" : 0,
					"enharmonictable" : [ "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-27",
					"keys" : [ "CM", "CM" ],
					"loop" : [ "(", 1, 1, 0, ")", "(", 1, 1, 0, ")" ],
					"maxclass" : "bach.score",
					"midichannels" : [ 1, 2 ],
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 2,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 461.0, 297.0, 312.0, 147.0 ],
					"pitcheditrange" : "null",
					"showmeasurenumbers" : [ 1, 1 ],
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, 2, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", -1, 0, ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", -1, 0, ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "G", "G" ],
					"enharmonictable" : [ "default", "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0 ],
					"id" : "obj-25",
					"keys" : [ "CM", "CM", "CM" ],
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 1, 2, 3 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 3,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 461.0, 141.0, 312.0, 141.5 ],
					"pitcheditrange" : "null",
					"stafflines" : [ 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")", "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 17.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, ")", "(", 0, ")", "(", 0, ")", "(", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-24",
					"linecount" : 10,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 141.0, 239.0, 152.0 ],
					"text" : "However, bach regroups the chord-seq and multi-seq functionalities into the single bach.roll object, and – symmetrically – the voice and poly functionalities into the bach.score object. Indeed, both bach editors are capable to deal with a custom number of voices, so that – for bach – a chord-seq is nothing but a special case of a multi-seq, having just one voice."
				}

			}
, 			{
				"box" : 				{
					"data" : [ 8279, "png", "IBkSG0fBZn....PCIgDQRA...LJ..DPMHX....vhj.kZ....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6clGeTUkl+9opJ0RBTYERfjvp.QVTABBhfMKhnfDUDkE0VaW533FscyHhJiSbDUTFlwepcihaC1hr5Jzfhnhs6JQgQGUTT1EBgjJ6aUkhe+QsukjZ+lh2mOIepactmk2aUeqy48btm64n5jm7jmDAAE.pi2FfffCDwnfhAQLJnXPDiBJFDwnfhAQLJnXHoneQbRLYpJ.HiLRGPU6FeG3Y5bP6mdo7hjkWrintXbgKXq.v.JX5.PwEGpoqiMbnR4EYKuXIQ0loW3B1BfsO.JrPnvBgUtxNR5b8Amqz09+BVJuHa4EqIpIFMYxTHdtpBwyIkWjr7hGDC7YzFkVpsW26d1BvXkz0IKcwBhZhwLxHCmGa6B2+my2z4x4ZeSW5dGco7hRkW7fnpOiO1xmdGJLeiyz5PgIkWzs7h0nJXm0NpTo7b7UH1SzXxdERMSe822hcdrKwoJbbnZ+DFnx9e1dEUprMBWtElJGUTqx8zpxd43HLUNBwi7VkJ3j1Ou8PbTj9V13prccr8Xp12xzYZ8xdcjZU9ILb21vw0qi70UdYOGbU9pT4i85g841ms9d8YOdd+YqWWK96yNGQRsGg4lcpx00wcdYyfnAxcfQPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFCBVwV1jeC+o1zaEvz7Du0qGsLmDNDwnfhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwna7LaaKsejDhZHhQAEChXTPwfHF6fDn69xecys0ce4MhVlSBIhXrCvJ1xl8a3+sM6eAJ3RHVc80GUroDQDwXPvsL8hB5zjVW5RTvRRLIlsj30YlaY5yv0xahabqynHTgJ+1T87ujKCPZpNXPpYLLQ7YLxgHFCCDeFirHhwnLhOicbDwXXvsNih31lwk32yM+K4xb52nPGCQLZmP8VAJ9LF4PDi.Oy11ZHktNhOiBcbDwnabySs8Wer8G2dQ9uoZ.l+kLyP0bNkCYbFAt4oNMHDVqxcLNi9CwewfGolQAEChXTPwPjqYZqMQUG+3TWCshgtjJolUlXPmFZs9poVK5H8zRwUTarJpoIcjQltFCNy0VIUbrxo4V0QWxoGz8L6pyyYowpnt5MC.pznitjVFn2MKu4ppfFL2JfJTqKYRtqohAsc.a1bcT1gNJM1Bn0X5jY26NcIY0.lolSTIVrZOd120.zmd1zUC1+8ayUywNzgotFTQxYjM416rEedBShHe9Y9D+Da+oWGGEnOmQAT62tGpDXB+K2KYs2WgWa6mIW2+93Qu83W4tWMu5VGNW++gsvJ+adS13q8UP+GNC03w3+6kOFYMgqlYcgCCs.l9lMv527u3QYNtaXQLpBxBnY9g+mGgO7ndZSC9huYl7jNcmko2zxw2EqYou.kStLfg0E1628y.ChqaYymb3Hrk+ikwA8JMS4tWNip2oPSG5y3+doqBn.Fw3Smu4i+BHuoQw20LIaCg0GkmRSDPL1.+3qsNNZ1Sg4bymKcEP8LakC+9qli2TqzcCo.4n2C+ATmjagU+OyFesuh7N+afhlz.PMvvGx1X0qY07cC49YD8JETmDPOJha9OMdzopI9oW+em2YK+.mQA1DyZRA51kbmb0iuWnRkENxm+FrgW8YvXtkv3KHM+XyMyOs4WfxK75X9WynrIXU0B6cyaFysBnUC5AlxBWFE1qt349.CUymuzUAC5x4NtyohQTwTm5v4Qu+mg24eNb98Sseg+GomhRX6ynUSGfu53vDt7QiqFVSh7m7UyP6gq5k7PL5V8U0r+e.3bYBSp+NiSZCaBL4ACeZo6GqNioie2jL8dnmGbLOsCWUHok7NmYwLmbt7kOaoTW.r6Vq.5Uu6I5bFhdFvLlE4Z2ahlAPius0as7egOCXlW6Tbd8lT2GIEesigC7ZeElr5SRD5fD10L1RckCbgz6t4cVkD50ohFvHT1lYqqauN+hu1e7Gg9MH.n9x+Jx5BuU7r9K8zqwLN3+wDluLauGZBK.parB1ym+QvH98nIfVkZ563lF79akZadxzUeZqVO4N9Qw6tgkxaT4Ey.6WdjU25IYja2IY6+hnq.aeU+MNP2RF.ZthFY3W2sRea5X.yl9mom+NN6gLJfsSCs.YJMUGRD1hQKM1DjcaMY.ZAnPF4jFC5rZEMZgx65OxNpvQ5ACo6qrJICo316zCGaq772i86TxPtb9iy4LaaiWuQ5Fo.zL+uO8hX660d3CX1bG253o6i8Zn3de1rue5f7a67CXqe2OCblLmG7lnOo.lAF9jtHFUuSwVGYZUEojtVr7q0C4krukm1THajYnS3PXKFSN8rfiuSproQQO7y2QPyPNCfbxNGzX22K087zgCY6rF61f4He4Aw74liaMYBk+suKz+qvdS20.8nH9i+owSi6903kW6mwQJejLvrCT2Sfp99ufSP2IYs5YHW+CyfNoc+9zn0d4nlTyevbV4ODTwEwTUUCe5cde7KkUK8oe1Zlt+8t+jUt57vmQKY2C3HkxIZdxjqaEes66a33zeRQmeLFgNDgsOiZxdvbNYeb9Guz6ywLUKlsXglq8Dr22Ycr6izny34tqTVs4QF.j9PFGYcr2js9A+H02rUrZsQJa2ai25SfINCa8l1F19cSFCeVL6hxjsr7+JGnJW45gqqZZrw5n1JNL6YGqlW7U9LNua6BIc0PR5SACIa+e8ZAZfc+BOK69GODMzPyXwrYp4v+LeBPlc0Var5Apnhxog5plZptZpoxJoIyPR4LblTd6gUsh+AkWcSX0pYpdeeIq4o1NEb0iiLjQtMjIBza5TXH2vsi5ssY9GO0G6J3BFOWZ55gSnGR1yhQsF8fiVg6ReXly+Z3e9DuLq58bDidvDtg61UGfznGRIIm+xoGi6pnn5dJdiGYcLuRtbzjJv6+hrx2214yejmOy7u7fz2bc0kJOw.YOrrX0Oyx3ccKzIbS2KCOW8fYMnEXmq7gXmtc9I8utbFS+Lx4rfRf09r7b2iqIJwHup6gK57jdRGNDR62zAbK9sUKX1pURRqdzXeqxMX1hes1byXwpZzlhdTGS1heshklsvIARxfATSvsE+Z0rYZ936hG+gddtrEubFfwVvp9LnKFzjvuE+pX1uoCbtkDZATG7y4..Pi9jaidHGMPMIoWe.lpCcfTqUKoj2YxrunBX8KYA.v4e2ONma+jY2cnfbGrBaLv.uz+B26zsfUUZHIshSigJhXLBgZsZC4VDDrQH4ynffhvmwf2HNIlLUE.jQFoCsqGZtxeOSmCZ+zKkWjr7hcD0aldgKv1cMY.EXaJ8WbwgZ55X+HPJuHa4EKIp5s8BWfsm3tATvzovBgBKDV4J6Hoy0GbtRW6+KXo7hrkWrlnlXzjISg34pJDOmTdQxxKdPLq2zkVpsW26d1BvXkz0IKcwBhZhwLxHCmGa6B2+my2z4x4ZeSW5dGco7hRkW7fnpOiO1x884P1eg4ablVGJLo7htkWrlfdbFCdRzG5iD8xK1QLPLJHzwPtQpBJFDwnfhAQLJnXPDiBJFDwnfhgDv4ynsAGv0vXD3ADVYPvNTMItj.JFC8Y1R7fNS1ZzlDtlo8+LTINaTAfPcV3jnRBkXLTmYKwC5LYqwJRHal1AJ4Ynh2zYxViVjPIFC0Y1R7fNS1ZrhDplog.MCUBscwfnMg5rvIQE4oCTHjPQ7zABD3k2D6Gp1Og0QVdSbr3Z34RvQzb4Mw8isGyfX4MwQpU4mvRzWdShFjv0LsPmWDwnfhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwX6v1+1QisGkAe+ea6ZT9IE1N2VJcD39p4fP6iHFETLHhQAEChXTPwfHFETLHhwn.a4qGY71D5TRB0y.SjAW8.d6e64DvXsscc19M7s90EFwsnSUPpYL.7deWaHD2s+EhBgGhXrcXJmwWh84cOduziL0g+U9D+oMxRY5i7qiI1VhFRyz9fMQ24OruvymCD2N+TOqc57YIweH9LFZH0LFgQ7YLzQDiQIldgRS0AKhXzGNIO17OHttGzdxRus8im2iZOYZi7qY5i7ave9XJz1HhQAEChXLrwUsjK4e4Wh2FSmZDwnfhAQLJnXPDidwiM+CGuMgSYQDitwxtyCEuMgSoQDiBJFDwnabWOduXgOQ9dEpqdKuzae+ALsK4V90nnkcpAhXzKBjOiK81OP.SyCcK6KZYNmRQDXhRXg5NQUXUeZjVp5bFp0VpkZppELjU2H4jrRCUZBLlIcQmFmwowJKGqFyhtpSCMVU4zp9rvXxNLIqzXEUPSVcewtD6KVnZHktpiFqqI6wUGolSF3Jm8FyT0gODUWWKnVeWI8rygz5pd.nISmfFaoUPkJd9G4n1iuQdr4e6dkGyBHMl+ie1Dn6rxhe5929ebIDPBewXKkwG8zu.GkB4JuuKlTUCfUNz69ew1JEFyMd2bV4qge9IeRZ9lVDiI+TbjP1yi+Dz7MeubN4qg89e9+iO9BuEt0yqW1OuY90W++hc32V+NMt76XL7OexWgS.voc9bs2vzHCs9IplKicbOKkuFX.C6Ln5u6aobfI+WVFirWv2+bO.u+uE3KugCrKfgNoiS4evqxSbmuCy79uKN8dXvdLTw8sh96ZksUHjI7EipUiMMPo7S662wnNMiP8GlcZeqjvQEg5xA7tpKc4fSGEzzeHujbOB5Yn2zivPQEX4H7F2+SR+u8RX34mhykN34sf54IWdRbaEOVzpx+OkxUtqMyWy4x0tzYS20ZaYDtxc+NbfVLCnEMo.celKj+vD5ssb0skQ4Ct4ai0tsAwben4SeSSCbISlO7O+.75O+mxe99lLF7S4ID5DQ7YzLmASd1Sjc+JeCMCbhc+AvXlD8AnU6woU+jN+EVfPueByhY.rzl4iU.5YOHc2p0Lyy5hX38sqNeexI4mF3sVN+31fgW70ReRy9GSZ6Ai69tV3Hqm8Wo0fv5E5HDglbssPZ8cDLR9uYO+RdT21Mv39SCje3K9fHS1Czr+BztFpsZfL0dNX3nafm3EqfIMr9S2xIaxrG8Di5sIvzX.N3FVEu9O1Ma4USUPZm6efIO3ZYWLH98CJSOxujxs.NafpptIHyT7t3DBChPhwlwZRFYvW03Y0uxpgIdiL9zzv+qOwSiOuKXpcr83De9Kxpesuy96FFW8CcijS9mK2980G9087ST1A1IevZ+V.XB2xCxYOHCzZS.icRbtSrOf4VQkJPcWRGqMUgMazm1NLPW8NHgHBQrG6.qV.C8aDLrrOL8ZD4CVNJl8JNMa1Lt2faKkg81QiLjYgWE2xvc34nFzYunzkQ9b5iMeFLpXhWIbvs8mXC+ekwYOn9..8N+dSN4jKfa9LZNKFH+DG9XMSN81MmDpce7A.yLM+0aIgvgH63LpNCFyMesjuQ7RjoitMjbXWuvGwIpuErZ0BU8yeJeNP5o45K5iXpZpu9Zn1ZpgZqpJZr41VoZtwl.rfYy1hmZs5QexIi9jSFCIqG0.G+ieY19m8CTUcMfEyloISGfe8sgdkiq52N3wqf5pqZpo5polJqj5ZvLnMWF8klGa+wVA682pFqVsRSUtO9vm7ofy7po2YJhwHMQjZF86WKp0fMOpr0zbOF+Uw4VwqvqtrOyYTN6qZ9zWi198fZi.e5emU8otxh7lwsykct4CngtBnws1LMejOlm6oeG.34V7A3pdn+.c2OFRJ8dPX5IdFdgW0UXCdFEykN1bAZFMoA7gqjU7gtNe2uz6hq+76K4OkEvUxZYCO7835ji9p3NttyCwawHOgz10V3rCYYsklvhUHICoPRpcDbzeGxxhkl4jVUgZc5II0A4Nj0IMi4FJm2eQKAtoEy4WfQZzpdRyngSY2grTLaWagCZzkLZhCOdHIoUuWhjf.0ZQWWyiy9lKhm8YVB6BH6Yd2biWP+hzl4ozHO2zAAYcFSmE8jW.laUEIoS7YLRiHFCVTqEcpka8Wz.YK9UHjPQ3yXzvHhrXy9LYpJfNC6p8mzMaMcNU9YsNgrY5EtfsB.Cn.a6p8EWb7zZZa5LYqQaR3lbst+kagEBEVHrxUFmMp.vBWvV.5bXqwBRnDilLYJjNW7fNS1ZrhDxlocPo1mSk6cOaAXrwUao8nyjsFsHgRL5dmUr8kp+OmRfNS1ZrhDploA3wV9z7SXSONXIsO9ytTp1ZrffdbFU9HCsSmUR.EiBcVIgqYZgNuHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAECw8GHKGOVl1lx8P3Ns6k7SYkeACwUwn6OD6.Tbwg2S.gjeJq7KXIt8Lv38po.X6YGNTWdOj7SYkegBwEeFizqlBR9orxuPk3tOiPje0TPxOkU90QItHFizqlBR9orxuPk31P63+USAeWMHj7qyY9EJDRcfQV8ZEBF5nRrPtYZ+u8a34ws0VvgOaqD9rMRzdaCG1duZGaUENC20w9aq3v0VggqskBuO183.prucb3oc3948HOba62PkOWSdVFtNTkamyysXC22VNrEtqOW7n7722A9aqEwwwdu8bDnsMj.brZe99v2sIDGaSGcTj6.ifhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwnfhAQLJnXPDiBJFDwnfhAEwL8tyMmjktw06Sn26rmq8ijoaWGEolwvD+IDA3gW+Z4gV2ZiwVSmaDwXPyIc9u2BwZ2zln1MsIOBaIqaMdjFg.iHFCQV5qtAmG6sHzaAoPGCQLFlT6l1DFKpHOByXQE42ZIEZaDwXXfCwl2hNQDFZHhwHHdWCoPvgHFi.3PD5nFQQTFZHiyXHxhl0UhQiKgZqcw932nSQowkvhWw7v0XMJi4XagHFCZb8nwtnmpOAryJFKpHtuULW+jdg.gHFCZbMVgKci1Fdm.0rriA8dwyYdtEpT6XfPDig.OpaiwXISLvwqjcX60krt0vhm67BbDE.DwXXQIS7CnjRVjsiK4KbE9NbcdaueRwZSqSIhXLDwSg3R8PvUxD+.JYGSRDgAIhXLLnjRVpsW8RzUxNljyZE824E7Ox3LFj7nu5F8IrRl3G3pIY2N1cVxZWST215riHFETLHhQAEChXLJi3uXGGQLFhzQDYhPL3P5McXfCwl2cXQDggFhXLBfGiwnHDCYjloETLH0LFjb2y5JITWf4kIIQaSDPLZkFLYB5RljhNOqnsISm.qcISRQmF.ngJOJUTdsfdCjd14Spc0VwaskZolZZxdpzQpYmtSCyZi0PEkcBZxpFRN0LH8rRGcZflqpBZvrUO1sCzXHMRKUCg+kjPbgHhX7HadE7Q832yMbA80UvVNJ+im7Yof+38vv5YSrmMuL9vRgbOyQQWJam7ykAiXNymwLjtQq0rOd2mXCTA.8aBL2q6BHyj.S+36yZd4sCzeFzPfe56+UfQv7dvKiCupkwGcLOsj7uj6jYMt7C+KIg3BQ.wXRzqINAXU6hpO+9R51pDjFNvOPkLd5eO0QC66i4CKEF00t.FY+RETMMNs2dk71qaSz2665ImtclLq4WOq7IRhhugQiFU.Mte11KucxZJ2HW4jF.ZTAWf0p4qdp2hlMCZRAxpn4yUOt7w28GFgNiDQ5.igdd5bZ7srui1f8PrvQJ8iI2K9LHErPYe+GAENOFd+LZ+7IQelxUv.Ye7K6qJ.nUy1RmE6wn5ecWTAiloddmlKiTc5b125bn65sWtZzDILeAEBQlNvjT1LnwAac2GlyJ+BPcSGh+4dfoN8tAzH0TJLlh6mmJ+j5NCbrvWbh5.x.rqqbDmFN9AIqK7JHCusvjziVUMiFCvQdi0xl+oLsEdyURZidd76FdtQjKIgXOQrdS2sgNcXkeAllVAnee6Bx9hnGFUCXgV.RwmJwTi9jyg.U4r4FOFFxHvUb2ZS.id7L5yqWPKVA.McM8HvUhP7hH13LpM6AvYw94fG7nb3c9sb5+tBvVqoISZ8E1+9pvqTTK6+8KCi9pRAftz89yQJ8mnw1nLyK27I6t2CxNu7H67xitkdxQjqEg3CQvA8NM5+zOC95+9yxmr+BXP8KM6gqidOwKfe6seF958TFlsZkVaoJ1668R7Mb5LpglC.zRSMCzJsXwVsbYMroPdG6s4s1xto55aDKVZl5qX+74O2532rqPOR4UR80WC0VSMTaUln9FMG4tbDh4DQGz6zF3PHS9VXLifrba39Lz6wwrmKr90tB1oi.yYTLi+7zoa5.y+1mwe+4dO.3kdfCxUTxUS1I2Wlw+5Mxm+ZOOq9gckW8ahykgqGpNUfOYU77ehqy0soeGb0SnOQxKIgXHg79McnsE+ZEyM0BV0nEC5z1g2hesZoErZEzn2.pQ1he8a4of2hei562zgFpQqgjC56Jl5jzaarGERnQlnDBJFDwnfhgP1mQAgNJQUeFCA8a.wjIS.PFY3X.qCOgtjeJq7KXHtNeFW3B1B.LfBlN.TbwgmHWxOkU9ErDRMSGIv8K7BKzVXkVJTbwR9kHjegBwkNv3noff8bR904H+BUTDO1AkVpsW26d1BvXk7KAK+5nDWDiYjQFNO11Er+OmjecNyuPk313L9XKe59IroI4WBR9EJD25.iCT5CMgjewtg1ItKFEDbfb6.ETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfhXV6DYw1MTxjIaKnTwxazenwIcyVSmSkWPQS.EivBWvVAbeFKGOsl1lNS1ZzlDtloc+K2BKDJrPXkqLNaTA.umc0JYaMVPBkXToLik6HzYxViUjP1LsChWyX4PgNS1ZzhDJwnRYFK2QnyjsFqHgpYZv+yNY+MKlUB3+YWsxzViEDzStVY0jP.hrKjCNHjZl1+KGdtVxz7covy1wdr7q4mkjM2WF7be4myV43HLGKdb9tbs4uk.OeVR572RdmqBv9xem+Vp2Zuk9t1XYkCGWudtb24p7csr2oxwR7mGetfWm2c6xqi82xcmWWKAbotSkiuA77ydO+9x1xbWzfDtloE57hHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAEChXTPwfHFETLHhQAECITymwXAKcCqy4w2yrmCmJ+.TEoQpYrc4jN+eoabcdblGY8qyuoPHzPDicPV5FWO.T6l1jy+A3gW+ZvcAqPniHFCBpcSaBiEUD.XrnhbJHEhLHhwfDGBRQHF4QDiAItWynPjEo2zdwi8Zaz4w28rtBbza4EcEyFiFuApsVW0HZz3Mv892lqy2uj0tFmG+uMuqx9QRus6nH0L5FK6M1nGu+Qe0Mh8G.D.UrnmZxXrnhb9+872lry3tj0sFOR6CtlWI5avIXDROcfIhOPVK6MeU.7vWvfsoX+k1+s4cMIjOPVQimNPolQ2ns5sbISz+owQ3ROsCeDeF8h1p2xNDdkrC+KNkdZGdH0L5EAp2xkrCeiaI6vyvkdZGdH0LZm65xtBepUyXQEwcOqqDTAO5F2fGBOGGeuydtnRkuMMarnhbqG0BcDDwna3PP5.aCsSayCu90x8Mm4xhmy77HshPL3Q5MMp3+zdOoiVb+y6ZjdS2AP7YzNsWukiVoUvERyztQa0a4EcEy11ANpgydkFOx5Wa6lVgNFRMi1oiza4nQZEbg3yHddGX7l6dVy1Ceu7Ler8xCau1QuwVmXT6zWKwmw1Folw1gG8UWOg5jmUt+zAGQ.wnEpyzIn5SbBp5DlntFZwmXzPkGkCsm8vg12Anl5s3w4Zrpxo1F8JrJKmpqoYuJl5wzwp.yVCeK1aBTshN3Q23FB34BTshN3AWyKGR1zohD9cfokx3i9qu.G0sfxbLWNy3BOCzS8rmMuL9vRgbOyQQWJam7ykAiXNymQOztCzB6c4OAexEdybKmWubl9F16ax5dyT4pVxbHC6+b4fu8Cxa8KWBEemiOrMYAkIguXTsZzBbN2zhXn8TGMr+Ok072eM94ybfz+l9b9vRgQcsKfQ1uTAUSiS6sWIu851D8cw2.4nCzzOHOMZ7HKyZzylQ+lKkObmimKaz4i0J1Eu0m.Wx8LVzG1FrubWW5rb4SV.VFkc5+jWbuydds6xnrPGiHhOilA.aselReGJCCnUrPYe+GAENOFd+LZOlIQelxUv.Yer2esp1HGSky51Jhi7FagxZtQ16VWKYUzsRuSUbwMQlH32t1xplN5g36.zowB0TJLlB6mmERRcmANV32NQcsYtoM2QyEM5ekM9.O.u62Odtnyo2QNSUPQRDYPuSA3yetkxma+8C9huQJHaUTJPJZ7N1pQex4P6+6fj3zl70SVe4KReuwemSeGERbIhHFMCbVy6V4LxuqnNICnWqJfVHs9B+79pfgkcOcK10x9e+xv3L8Qk5KojJoBjRxQCOEETZDw7YL4tjJ5MX.sNk25n2S7B32d6mgudOkgYqVo0Vph89duDeCmNENzbbl9iTUMTe80Rs0VC0VUUzXyNF+lVw1.EEEFOGAEGQfZF0fV.09QVan2iiYOWX8qcErSGAlynXF+4oS2zYO0oB7ouLuzm5Jc4MiamKcr4Angt.nweYtPBGwnaGnUL2TKXUiVLnSqh71AJ6PVD2ucfwnYsiZzZHYYH2DZSj1+DTLHhQAECxV7qPHghvmwngQDYwl8Yxjsa2nxeWs+jtYqoyoxNVmP9XGrvErU.X.EXaWsu3himVSaSmIaMZSBmOit+kagEBEVHrxUFmMp.vBWvV.5bXqwBRnDilLYJjNW7fNS1ZrhDxlocPokZ608tms.L13pszdzYxViVjPIFcuyJ19R0+mSIPmIaMVQBUyz.7XKeZ9IroGGrj1G+YWJUaMVPPONiJejg1oyJIfhQgNqjv0LsPmWDwnfhAQLJnXPDiBJFDwnfhg++.yaSBspVk....BjDQAQkMRtt4deJ.....IUjSD4pPfIH" ],
					"embed" : 1,
					"id" : "obj-22",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 250.0, 133.0, 185.0, 311.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2013-12-23 at 15.40.08.png"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-10",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 96.0, 771.0, 36.0 ],
					"text" : "bach is explicitly inspired by Lisp-based environments such as OpenMusic, which is the reason why you will find many analogies between the two worlds. For instance, OpenMusic and bach share – more or less – the same set of notation editors."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-47",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 46.0, 771.0, 50.0 ],
					"text" : "This tutorial is dedicated to people who want to switch from OpenMusic to bach. We'll take some OpenMusic patches and we will show how they can be easily translated into bach patches. All the OpenMusic examples we will use are part of the OpenMusic tutorials, which you can find in OpenMusic's Help menu (\"Import tutorial patches\", and then \"OM-tutorials\")."
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
					"patching_rect" : [ 199.0, 499.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 551.5, 249.0, 20.0 ],
					"text" : "linksections 0 1 a \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 524.0, 69.0, 20.0 ],
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
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"hidden" : 1,
					"id" : "obj-61",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 406.0, 477.0, 42.0, 20.0 ],
					"text" : "Ok ok",
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
					"patching_rect" : [ 305.0, 7.74086, 317.0, 25.0 ],
					"text" : "- new to bach, but skilled in OpenMusic?"
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
					"text" : "From OpenMusic to bach (a)"
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
					"patching_rect" : [ 636.0, 598.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
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
					"patching_rect" : [ 636.0, 573.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 636.0, 548.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 636.0, 523.0, 162.0, 18.0 ],
					"text" : "From OpenMusic to bach [b]",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 636.0, 498.0, 40.0, 20.0 ],
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
					"id" : "obj-19",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 636.0, 473.0, 151.0, 20.0 ],
					"text" : "Continue to section (b)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
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
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
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
					"source" : [ "obj-17", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 577.5, 190.5, 577.5, 190.5, 519.0, 208.5, 519.0 ],
					"source" : [ "obj-198", 0 ]
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
				"name" : "Screen shot 2013-12-23 at 15.40.08.png",
				"bootpath" : "/Users/danieleghisi/Desktop",
				"patcherrelativepath" : "../../../../../../Users/danieleghisi/Desktop",
				"type" : "PNG ",
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
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
