{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 97.0, 44.0, 854.0, 544.0 ],
		"bglocked" : 0,
		"defrect" : [ 97.0, 44.0, 854.0, 544.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "click on the score and then use the spacebar to play and stop!",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-29",
					"patching_rect" : [ 694.0, 169.0, 150.0, 48.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "It's worth noticing that the \"nullmode\" here is crucial: if a note has NO slot defined, a \"null\" is output, and we'll be able to intercept this in the poly, and set it to a default value! A good rule is to define the maxdepth when retrieving slots via [bach.keys], since the slot key could be also in some slot content!",
					"linecount" : 8,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-79",
					"patching_rect" : [ 605.0, 286.0, 225.0, 117.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "first slot always in background",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-57",
					"patching_rect" : [ 117.0, 318.0, 173.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "no slots in background",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-56",
					"patching_rect" : [ 104.0, 340.0, 150.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The 1st slot is named \"amplitude envelope\", it is a function-slot ranging from -120 to 10, the interface is mapped with an exponent of -0.5 (to obtain a pseudo-logarithmic mapping), popping up when \"a\" is pressed, whose slot window will be as large as the note duration, and whose unit of measurement will be dB.",
					"linecount" : 4,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-54",
					"patching_rect" : [ 378.0, 106.0, 448.0, 62.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "You can decide to keep some slots in the background using the \"bgslots\" attribute:\n",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-26",
					"patching_rect" : [ 6.0, 286.0, 277.0, 34.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "bgslots",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-22",
					"patching_rect" : [ 6.0, 339.0, 98.0, 18.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "bgslots 1",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-36",
					"patching_rect" : [ 6.0, 318.0, 108.0, 18.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"outlettype" : [ "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-37",
					"patching_rect" : [ -69.0, 111.0, 60.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "For example, we can handle a slot in charge for amplitude envelopes.",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-42",
					"patching_rect" : [ 4.0, 89.0, 588.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "( slotinfo ( 1 (name \"amplitude envelope\" ) (type function) (range -120 10) (slope -0.5) (key a) (width temporal) (representation dB)))",
					"linecount" : 2,
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-48",
					"patching_rect" : [ 4.0, 110.0, 369.0, 32.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnnn",
					"bgslots" : [ 1 ],
					"stafflines" : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"preventedit" : [  ],
					"zoom" : 208.984375,
					"automessage" : [  ],
					"fontsize" : 12.0,
					"versionnumber" : 6999,
					"voicespacing" : [ 0.0, 26.0 ],
					"numinlets" : 7,
					"vzoom" : 103.63636,
					"loop" : "null",
					"numvoices" : 1,
					"id" : "obj-52",
					"patching_rect" : [ 4.0, 167.0, 684.0, 114.0 ],
					"fontname" : "Arial",
					"numoutlets" : 9,
					"popupmenuslots" : [  ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "-1/8", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068869150, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072192181, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074880278, ")", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071773577, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 48059, -1075594309, ")", ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1074953411, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072393655, ")", ")", ")", 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068089278, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074511999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071974224, ")", ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064881709, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069177515, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1074805587, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075239791, ")", ")", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 127, 0, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3838, 1070562889, "_x_x_x_x_bach_float64_x_x_x_x_", 52480, 1073231818, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071974224, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070749989, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068413064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070871099, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069430089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1066222074, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070940310, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068282859, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070992214, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1070595674, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071044119, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068687178, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071182531, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069757072, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071269042, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068827142, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071390153, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1074221273, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071476660, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069062754, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071545866, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071392966, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071647176, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068413064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071716382, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071876778, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071725032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068524593, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071811542, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069508050, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071837494, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068282859, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 40704, 1072002690, "_x_x_x_x_bach_float64_x_x_x_x_", 49000, -1071424333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072393655, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072131624, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068827142, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072218131, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071392966, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071584752, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072339244, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068687178, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072417101, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071201840, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072094062, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072494960, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068413064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "we cannot use [pack] with a llll, thus we use bach.join to pack everything (in text format), and give it to the \"note\" message.",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-5",
					"patching_rect" : [ 79.0, 367.0, 272.0, 48.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.wrap 1",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-32",
					"patching_rect" : [ 455.0, 356.0, 76.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys 1 @nullmode 1 @maxdepth 2",
					"linecount" : 2,
					"outlettype" : [ "", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-33",
					"patching_rect" : [ 455.0, 318.0, 150.0, 34.0 ],
					"fontname" : "Arial",
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.join 4 @out t",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 4,
					"id" : "obj-24",
					"patching_rect" : [ 345.0, 379.0, 129.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "ezdac~",
					"varname" : "autohelp_dac",
					"numinlets" : 2,
					"id" : "obj-45",
					"patching_rect" : [ 334.0, 489.0, 45.0, 45.0 ],
					"numoutlets" : 0,
					"local" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"varname" : "autohelp_dac_text",
					"text" : "start audio",
					"linecount" : 2,
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"id" : "obj-46",
					"patching_rect" : [ 293.0, 495.0, 38.0, 33.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"varname" : "startwinwdow_panel",
					"border" : 2,
					"bordercolor" : [ 0.392157, 0.792157, 0.117647, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"id" : "obj-47",
					"patching_rect" : [ 286.0, 484.0, 100.0, 55.0 ],
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "our poly~ has changed to account for amplitude envelopes, have a look inside!!!",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-17",
					"patching_rect" : [ 81.0, 422.0, 238.0, 34.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "___",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-40",
					"patching_rect" : [ 310.0, 422.0, 31.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : ">",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-41",
					"patching_rect" : [ 328.0, 428.0, 19.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 128",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-4",
					"patching_rect" : [ 338.0, 459.0, 85.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend note",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-30",
					"patching_rect" : [ 345.0, 402.0, 81.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "gain~",
					"outlettype" : [ "signal", "int" ],
					"numinlets" : 2,
					"id" : "obj-21",
					"patching_rect" : [ 345.0, 456.0, 126.0, 20.0 ],
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "poly~ \"The Gift Of Synthesis (d) - poly\" 10",
					"outlettype" : [ "signal" ],
					"fontsize" : 16.252846,
					"numinlets" : 1,
					"id" : "obj-20",
					"patching_rect" : [ 345.0, 426.413788, 312.0, 25.0 ],
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.unpacknote",
					"outlettype" : [ "float", "int", "float", "int", "", "", "", "int", "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-43",
					"patching_rect" : [ 345.0, 294.0, 165.5, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 9
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "wclose",
					"text" : "delay 0",
					"outlettype" : [ "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-44",
					"patching_rect" : [ 251.5, 572.0, 49.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clean, wclose",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-19",
					"patching_rect" : [ 251.5, 598.0, 81.0, 18.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 d \"The Gift Of Synthesis\"",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-198",
					"patching_rect" : [ 251.5, 653.0, 228.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-51",
					"patching_rect" : [ 251.5, 625.5, 69.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 2,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Can we control partials as well?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-61",
					"patching_rect" : [ 587.0, 509.0, 123.0, 34.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-49",
					"patching_rect" : [ 1.0, 17.0, 444.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- amplitude envelopes",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"id" : "obj-50",
					"patching_rect" : [ 252.0, 7.74086, 309.0, 26.0 ],
					"fontname" : "Arial Italic",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The Gift Of Synthesis (d)",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"id" : "obj-13",
					"patching_rect" : [ 2.0, 2.924051, 254.0, 32.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "That was our very first step. Yet, the bach suite allows you to personalize and handle a lot of additional parameters.\nTypically, slots are very good friends when synthesizing data. Their content is flexible, customizable and allows you to define personal parameters to be handled dynamically.",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-16",
					"patching_rect" : [ 3.0, 40.0, 638.0, 48.0 ],
					"fontname" : "Arial",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-1",
					"patching_rect" : [ 5.0, 644.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-2",
					"patching_rect" : [ 5.0, 619.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-3",
					"patching_rect" : [ 5.0, 594.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "The Gift Of Synthesis (c)",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-7",
					"patching_rect" : [ 5.0, 569.0, 140.0, 18.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-8",
					"patching_rect" : [ 5.0, 544.0, 40.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"outlettype" : [ "", "", "int" ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Back to section (c)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"id" : "obj-10",
					"patching_rect" : [ 5.0, 519.0, 151.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 3
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-11",
					"patching_rect" : [ 699.0, 644.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-12",
					"patching_rect" : [ 699.0, 619.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-14",
					"patching_rect" : [ 699.0, 594.0, 140.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "The Gift Of Synthesis (e)",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-18",
					"patching_rect" : [ 699.0, 569.0, 141.0, 18.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-23",
					"patching_rect" : [ 699.0, 544.0, 40.0, 20.0 ],
					"hidden" : 1,
					"fontname" : "Arial",
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"outlettype" : [ "", "", "int" ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Continue to section (e)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"id" : "obj-27",
					"patching_rect" : [ 699.0, 519.0, 151.0, 20.0 ],
					"fontname" : "Arial",
					"numoutlets" : 3
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-24", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 1 ],
					"destination" : [ "obj-24", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 2 ],
					"destination" : [ "obj-24", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 1 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 1 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 1,
					"midpoints" : [ 261.0, 679.0, 245.5, 679.0, 245.5, 620.5, 261.0, 620.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-51", 0 ],
					"destination" : [ "obj-198", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 7 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
					"midpoints" : [ 595.375, 287.0, 354.5, 287.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-48", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-45", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 6 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
