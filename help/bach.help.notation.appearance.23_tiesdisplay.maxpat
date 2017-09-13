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
		"rect" : [ 90.0, 79.0, 617.0, 539.0 ],
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
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 341.0, 477.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Also see #tie+edit to know more about editing tied notes.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-24",
					"linecount" : 3,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 36.0, 477.0, 50.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "If #duration+lines are shown you can display a single duration line for tied elements if you set the \"dlspansties\" attribute to 1 or 2 (this latter also allows to hide ties and tied notes)",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "dlspansties",
					"id" : "obj-8",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 109.0, 248.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubblepoint" : 0.24,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 313.0, 135.0, 175.0, 55.0 ],
					"style" : "",
					"text" : "Try to click on this duration line and drag it up",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgslots" : [ 1, 2, 3, 4, 5, 6, 7 ],
					"breakpointshavenoteheads" : 1,
					"breakpointshavevelocity" : 1,
					"bwcompatibility" : 7910,
					"clefs" : [ "F8", "F8" ],
					"constraintbeamsinspaces" : 0,
					"defaultnoteslots" : [ "null" ],
					"dlspansties" : 1,
					"enharmonictable" : [ "default", "default" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-1",
					"keys" : [ "CM", "CM" ],
					"linkdynamicstoslot" : 0,
					"linklyricstoslot" : 7,
					"loop" : [ "(", 1, 1, 0, ")", "(", 1, 1, 0, ")" ],
					"maxclass" : "bach.score",
					"midichannels" : [ 1, 2 ],
					"numinlets" : 7,
					"numoutlets" : 9,
					"numparts" : [ 1, 1 ],
					"numvoices" : 2,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 165.0, 519.0, 164.666672 ],
					"pitcheditrange" : [ "null" ],
					"showdurations" : 1,
					"showmarkers" : 0,
					"showmeasurenumbers" : [ 0, 0 ],
					"showrhythmictreelocks" : 0,
					"showstemsforbeamedrests" : 0,
					"showvelocity" : 1,
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"tonedivision" : 4,
					"versionnumber" : 70909,
					"voicenames" : [ "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 17.0, 11.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "patchfile", ")", "(", "type", "filelist", ")", "(", "key", "p", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 2, "(", "name", "InstanceID", ")", "(", "type", "int", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078853632, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078853632, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "llll", ")", "(", "key", 0, ")", "(", "color", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072211593, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071952200, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068106054, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 5, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3226894336, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3218708889, ")", "(", "representation", "dB", ")", "(", "grid", ")", "(", "ysnap", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 6, "(", "name", "oscillation period", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076887552, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 7, "(", "name", "oscillation", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "grid", ")", "(", "ysnap", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 8, "(", "name", "stretch mode", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "Frequency", "Pitch", ")", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", ")", ")", "(", "commands", "(", 1, "(", "note", "opennote", ")", "(", "chord", "openchord", ")", "(", "rest", "rest", ")", "(", "key", "o", ")", ")", "(", 2, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "markers", "(", "(", 1, 1, 0, ")", "(", "pos", 1, ")", "none", ")", "(", "(", 1, 5, 0, ")", "(", "pos", 2, ")", "none", ")", ")", "(", "midichannels", 1, 2, ")", "(", "articulationinfo", ")", "(", "noteheadinfo", ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 130, ")", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084638208, 100, 1, "(", "breakpoints", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069297398, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082617856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 14, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070242141, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078525952, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070710436, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083666432, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 65, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070982853, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084024832, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 44, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", ")", "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084638208, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 1, ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084638208, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 1, ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084638208, 100, 0, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 1, ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 13, 16, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 0, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 1, ")", "(", 3, 9, 12, 14, 17, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", ")", 0, ")", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 130, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084843008, 100, 1, "(", "breakpoints", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070979219, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082720256, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 100, ")", ")", "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084843008, 100, 0, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", "(", "-3/16", 0, ")", ")", "(", "-1/2", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 2, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 2, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 0, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 2, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3224886538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 13, 16, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 1, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")" ],
					"whole_score_data_0000000001" : [ 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 100, 0, "(", "slots", "(", 1, "Macintosh HD:/Users/danieleghisi/MusicaMia/Presentazioni/2016_09_ICMC_cagemeta/vt_arpeggiator.maxpat", 1, ")", "(", 2, 2, ")", "(", 3, 6, 8, 11, 13, ")", "(", 4, "1/16", ")", "(", 5, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 6, 8, ")", "(", 7, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069563097, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977553, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070769860, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071191953, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071120384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072168960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071969429, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071112061, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072213897, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072177281, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072458365, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070952277, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 2 ],
					"zoom" : 102.109375
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
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"style" : "",
					"text" : "See Also: change+pitch, tie, slot+tie",
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
					"patching_rect" : [ 6.0, 498.0, 585.0, 19.0 ],
					"style" : "",
					"text" : "Objects: bach.score",
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
					"patching_rect" : [ 6.0, 8.0, 306.0, 23.0 ],
					"style" : "",
					"text" : "Ties display",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 595.0, 31.0 ],
					"style" : "",
					"text" : "Tags: appearance, display single, duration, line, span, dlspansties, dl, tie, edittiedelementstogether, together, sequence, hide, hidden",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.score.mxo",
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
