{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 1,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 486.0, 79.0, 617.0, 539.0 ],
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
					"id" : "obj-21",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 8.0, 436.0, 589.0, 36.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "All these options are both available for bach.roll and bach.score. For bach.score, there's one more option, the tempo ramp sampling rate (see #temporampsamplingrate).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-18",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 34.0, 255.0, 361.0, 21.0 ],
					"showhand" : 0,
					"text" : "– resolution (default: 960): the number of MIDI ticks per beat.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-16",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 34.0, 233.0, 453.0, 21.0 ],
					"showhand" : 0,
					"text" : "– format (default: 1): the MIDI file format (0 = single track, 1 = multiple tracks)",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 385.0, 267.5, 225.0, 54.0 ],
					"text" : "This only exports voices 1 and 3, in a MIDI file of format 1, and with a resolution of 1920 ticks per beat"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 26.0, 285.0, 363.0, 23.0 ],
					"text" : "exportmidi foo.mid @voices 1 3 @format 1 @resolution 1920"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-8",
					"linecount" : 4,
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 34.0, 165.0, 582.0, 65.0 ],
					"showhand" : 0,
					"text" : "– voices (default: null): if a list of voices is provided, then only the specified voices will be exported.\n    If no list is provided, then all the voices of the score will be exported. Ranges can also be\n    expressed, as sublists. For example, [voices [1 3 5]] will export the first, third and fifth voice,\n    while [voices [[1 5] 8]] will export all the voices from 1 to 5, and the 8th voice..",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
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
					"patching_rect" : [ 23.0, 96.0, 578.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "In addition you can have the following options, set via message attributes",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-4",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 23.0, 119.0, 490.0, 21.0 ],
					"showhand" : 0,
					"text" : "– exportmarkers (default: 1): if non-0, all the markers in the score will be exported.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 252.0, 140.0, 349.0, 25.0 ],
					"text" : "Export the score as \"foo.mid\", but don't export markers"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 23.0, 142.0, 227.0, 23.0 ],
					"text" : "exportmidi foo.mid @exportmarkers 0"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 91.0, 53.0, 370.0, 40.0 ],
					"text" : "Open a dialog to choose the MIDI file name and location to be exported, then export with default settings"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 8.0, 59.0, 70.0, 23.0 ],
					"text" : "exportmidi"
				}

			}
, 			{
				"box" : 				{
					"bwcompatibility" : 70909,
					"cautionaryaccidentalsdecay" : 2563,
					"clefs" : [ "G", "FG", "FG" ],
					"constraintbeamsinspaces" : 0,
					"defaultnoteslots" : [ "null" ],
					"enharmonictable" : [ "default", "default", "default" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0 ],
					"id" : "obj-2",
					"keys" : [ "Bm", "Bm", "Bm" ],
					"linkarticulationstoslot" : 0,
					"linkdynamicstoslot" : 0,
					"linklyricstoslot" : 7,
					"loop" : [ "[", 1, 1, 0, "]", "[", 1, 1, 0, "]" ],
					"maxclass" : "bach.score",
					"midichannels" : [ 1, 1, 1 ],
					"numinlets" : 7,
					"numoutlets" : 9,
					"numparts" : [ 1, 1, 1 ],
					"numvoices" : 3,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 8.0, 322.0, 585.0, 108.333327999999995 ],
					"pitcheditrange" : [ "null" ],
					"showmeasurenumbers" : [ 1, 1, 1 ],
					"stafflines" : [ 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80100,
					"voicenames" : [ "[", "]", "[", "]", "[", "]" ],
					"voicespacing" : [ 0.0, 17.0, 17.0, 26.0 ],
					"vzoom" : 70.0,
					"whole_score_data_0000000000" : [ "score", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "]", "[", "commands", "[", 1, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 2, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 3, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 4, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 5, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "]", "[", "markers", "[", "[", 1, 1, "29/100", "]", "[", "marker", 1, "]", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085699584, "[", "marker", 2, "]", "none", "]", "]", "[", "midichannels", 1, 1, 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "[", "[", 2, 4, "]", "[", "[", "1/4", 60, "]", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 92, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 92, 0, 0, "]", 0, "]", "]", 0, "]", 0, "]", "[", "[", "[", "[", 2, 4, "]", "[", "[", "1/4", 60, "]", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085277184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "[", "leveltype", 1, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 60, 0, 0, "]", 0, "]", "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 60 ],
					"whole_score_data_0000000001" : [ 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "[", "leveltype", 1, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, "]", 0, "]", "[", "1/32", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 60, 0, 0, "]", 0, "]", "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 60, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 60, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 60, 0, 0, "]", 0, "]", "]", 0, "]", 0, "]", "[", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "1/2", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "1/2", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, "]", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "1/2", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "1/2", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 100, 0, 0, "]", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", "[", "[", "[", 2, 4, "]", "[", "]", "]", "[", "-1/2", 0, "]", 0, "]", 0, "]" ],
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
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"text" : "See Also: import+midi, temporampsamplingrate",
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
					"patching_rect" : [ 6.0, 495.0, 585.0, 19.0 ],
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
					"patching_rect" : [ 6.0, 8.0, 282.0, 23.0 ],
					"text" : "MIDI export",
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
					"patching_rect" : [ 6.0, 476.0, 585.0, 19.0 ],
					"text" : "Tags: data, midi, export, exportmidi, markers, exportmarkers, format, resolution, voices, file",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 32.0, 589.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Both bach.roll and bach.score can export MIDI files, via the \"exportmidi\" message.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
