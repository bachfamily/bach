{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 2,
			"architecture" : "x86"
		}
,
		"rect" : [ 455.0, 44.0, 617.0, 539.0 ],
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
					"bubble" : 1,
					"bubblepoint" : 0.33,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-21",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 295.0, 197.5, 311.0, 84.0 ],
					"text" : "If you don't want this behaviour, by adding  an \"onset\" symbol as first argument, you can dump only notes having the onset within the defined time region, and thus avoid dumping of partial notes",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-20",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 47.0, 161.5, 553.0, 36.0 ],
					"text" : "By default, when one of the time region extremes cuts a duration line, a portion of the note is still output on the subroll. In other words: all partial notes are by default output.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 295.0, 284.0, 199.0, 19.0 ],
					"text" : "subroll onset [1 2 5] [1000 3000]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 453.0, 70.0, 147.0, 36.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "see #body, #header and #dump+message",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-16",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 264.0, 133.0, 182.0, 25.0 ],
					"text" : "This dumps clefs and body"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 132.0, 459.0, 91.0, 20.0 ],
					"text" : "loadmess clear"
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
					"patching_rect" : [ 38.0, 133.0, 224.0, 19.0 ],
					"text" : "subroll [4 5] [1000 3000] [clefs body]"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-5",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 220.5, 108.0, 269.0, 25.0 ],
					"text" : "This dumps body (musical content) only"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 18.5, 111.0, 193.0, 19.0 ],
					"text" : "subroll [4 5] [1000 3000] [body]"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "G", "F" ],
					"enharmonictable" : [ "default", "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0 ],
					"id" : "obj-4",
					"keys" : [ "CM", "CM", "CM" ],
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 5, 2, 5 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 3,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 295.0, 326.333344, 296.0, 146.0 ],
					"pitcheditrange" : "null",
					"stafflines" : [ 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7100,
					"voicenames" : [ "<none>", "<none>", "<none>" ],
					"voicespacing" : [ 0.0, 17.0, 17.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "temporal", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "temporal", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 5, 2, 5, ")", "(", 0, ")", "(", 0, ")", "(", 0, ")" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 70.0
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-7",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 163.0, 68.0, 281.5, 40.0 ],
					"text" : "This dumps, additionally to the musical content, all header information (default)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 68.0, 153.0, 19.0 ],
					"text" : "subroll [4 5] [1000 3000]"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "G", "FG", "F", "F" ],
					"enharmonictable" : [ "default", "default", "default", "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0, 0, 0 ],
					"id" : "obj-14",
					"keys" : [ "CM", "CM", "CM", "CM", "CM" ],
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 5, 2, 3, 4, 5 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 5,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 208.0, 271.0, 249.333344 ],
					"pitcheditrange" : "null",
					"stafflines" : [ 5, 5, 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7100,
					"voicenames" : [ "(", ")", "(", ")", "(", ")", "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 17.0, 17.0, 17.0, 17.0, 2.0 ],
					"vzoom" : 69.481094,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 5, 2, 3, 4, 5, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079984128, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085955584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086057984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083287552, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082613760, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083794432, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084395008, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084901888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082818560, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082818560, 127, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082628096, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083748352, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086134784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086185984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084325888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085929984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085981184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083594752, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084878848, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085469184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085520384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080131584, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085252608, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082136576, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083256832, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083901952, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084356608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084525568, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084855808, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085201408, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085289984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081868288, 127, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 70.0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"text" : "See Also: subroll, body, header, dump+message",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "seealso"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 495.0, 585.0, 19.0 ],
					"text" : "Objects: bach.roll",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "objects"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 403.0, 23.0 ],
					"text" : "Options for subroll extraction",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 585.0, 19.0 ],
					"text" : "Tags: message, subroll, extract, portion, roll, option",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-76",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 32.0, 585.0, 36.0 ],
					"text" : "As for the \"dump\" message, also for the \"subroll\" message you can explicitely decide what to dump via an optional last parameter.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 15.5, 466.333344, 286.0, 466.333344, 286.0, 321.333344, 304.5, 321.333344 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
