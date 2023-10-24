{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 5,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 440.0, 117.0, 632.0, 559.0 ],
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
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 6.0, 71.0, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 101.5, 210.0, 411.0, 36.0 ],
					"presentation_linecount" : 2,
					"sendto" : "bach.help.filtertags",
					"text" : "If you need more digits (10, 11, 12), you should perhaps consider creating a font with those digits as a single character",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"id" : "obj-15",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 292.5, 353.833353666666767, 19.0, 47.0 ],
					"text" : "T\nA\nB"
				}

			}
, 			{
				"box" : 				{
					"accidentalsgraphic" : 0,
					"bwcompatibility" : 80300,
					"clefs" : [ "None" ],
					"defaultnoteslots" : [ "null" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-14",
					"loop" : [ "[", 1, 1, 0, "]", "[", 1, 2, 0, "]" ],
					"maxclass" : "bach.score",
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 1,
					"out" : "nnnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "" ],
					"patching_rect" : [ 289.0, 337.166687000000024, 239.0, 90.333333333333329 ],
					"pitcheditrange" : [ "null" ],
					"stafflines" : [ 6 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80300,
					"voicenames" : [ "[", "]" ],
					"voicespacing" : [ -18.000000000000004, 11.428571428571423 ],
					"whole_score_data_0000000000" : [ "score", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 24, "[", "name", "annotation", "]", "[", "type", "text", "]", "[", "key", "t", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "[", "[", "fullname", "one", "]", "[", "shortname", "one", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 49, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "two", "]", "[", "shortname", "two", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 50, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "three", "]", "[", "shortname", "three", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 51, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "four", "]", "[", "shortname", "four", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 52, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "five", "]", "[", "shortname", "five", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 53, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "six", "]", "[", "shortname", "six", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 54, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "seven", "]", "[", "shortname", "seven", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 55, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "eight", "]", "[", "shortname", "eight", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 56, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "nine", "]", "[", "shortname", "nine", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 57, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "zero", "]", "[", "shortname", "zero", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 48, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "]", "[", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "-1/4", 0, "]", "]", "[", "[", "leveltype", 9, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, "[", "slots", "[", 23, "five", "]", "]", 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, "[", "slots", "[", 23, "three", "]", "]", 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, "[", "slots", "[", 23, "two", "]", "]", 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, "[", "slots", "[", 23, "five", "]", "]", 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 100, 0, "[", "slots", "[", 23, "seven", "]", "]", 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, "[", "slots", "[", 23, "four", "]", "]", 0, "]", 0, "]", "]", 0, "]", 0, "]" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 179.166687000000024, 223.0, 22.0 ],
					"text" : "bach.prepend noteheadinfo @outwrap 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 103.166687000000024, 536.0, 22.0 ],
					"text" : "[ one `1 ] [ two `2 ] [ three `3 ] [ four `4 ] [ five `5 ] [ six `6 ] [ seven `7 ] [ eight `8 ] [ nine `9 ] [ zero `0 ]"
				}

			}
, 			{
				"box" : 				{
					"code" : "for $l in $l1 with @unwrap 1 collect [[ 'fullname' $l:1 ] [ 'shortname' $l:1 ] [ 'basept' 9] [ 'opaque' 1] [ 'font' 'Arial bold' ] [ 'char' $l:2 ] [ 'yshift' -24] [ 'xshift' -3] [ 'width' 0.] ] ",
					"id" : "obj-3",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 138.166687000000024, 538.0, 35.0 ],
					"saved_object_attributes" : 					{
						"embed" : 1,
						"versionnumber" : 80300
					}
,
					"text" : "bach.eval for $l in $l1 with @unwrap 1 collect [[ 'fullname' $l:1 ] [ 'shortname' $l:1 ] [ 'basept' 9] [ 'opaque' 1] [ 'font' 'Arial bold' ] [ 'char' $l:2 ] [ 'yshift' -24] [ 'xshift' -3] [ 'width' 0.] ]"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"id" : "obj-6",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 12.0, 365.0, 19.0, 47.0 ],
					"text" : "T\nA\nB"
				}

			}
, 			{
				"box" : 				{
					"attr" : "showstems",
					"id" : "obj-4",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 22.0, 289.166687000000024, 184.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"accidentalsgraphic" : 0,
					"automessage" : [ "dumpselection" ],
					"bwcompatibility" : 7910,
					"clefs" : [ "None" ],
					"defaultnoteslots" : [ "null" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"notifycontinuously" : 1,
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "" ],
					"outputpitchesplayout" : 2,
					"patching_rect" : [ 6.0, 337.166687000000024, 270.0, 87.666666666666742 ],
					"pitcheditrange" : [ "null" ],
					"showdurations" : 0,
					"showstems" : 0,
					"stafflines" : [ 6 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80300,
					"voicenames" : [ "[", "]" ],
					"voicespacing" : [ -11.142856999999999, 1.571429 ],
					"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "changenotehead", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "[", "[", "fullname", "one", "]", "[", "shortname", "one", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 49, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "two", "]", "[", "shortname", "two", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 50, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "three", "]", "[", "shortname", "three", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 51, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "four", "]", "[", "shortname", "four", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 52, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "five", "]", "[", "shortname", "five", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 53, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "six", "]", "[", "shortname", "six", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 54, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "seven", "]", "[", "shortname", "seven", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 55, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "eight", "]", "[", "shortname", "eight", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 56, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "nine", "]", "[", "shortname", "nine", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 57, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "[", "[", "fullname", "zero", "]", "[", "shortname", "zero", "]", "[", "alias", "]", "[", "font", "Arial bold", "]", "[", "basept", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1075970048, "]", "[", "char", 48, "]", "[", "xshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3221749760, "]", "[", "yshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224895488, "]", "[", "xshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "yshiftsmall", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "dlstartxshift", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "opaque", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "]", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1227133536, 1079761746, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 23, "one", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1840700268, 1081390811, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 23, "one", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2454267024, 1082116388, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 23, "three", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2454267025, 1083230500, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 23, "four", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1227133512, 1083765906, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079001088, 100, "[", "slots", "[", 23, "nine", "]", "]", 0, "]", 0, "]", 0, "]" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 33.0, 609.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "By using custom noteheads you can simulate tablatures:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
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
					"text" : "See Also: noteheadinfo, custom+notehead+specification",
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
					"text" : "Tablatures",
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
					"text" : "Tags: notehead, define, custom, syntax, spec, example, tablature, tab, guitar, fret",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eval.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.prepend.maxpat",
				"bootpath" : "~/Documents/Max 8/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.reg.mxo",
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
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
