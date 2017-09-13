{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 6,
			"architecture" : "x64"
		}
,
		"rect" : [ 305.0, 44.0, 617.0, 539.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-9",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 38.0, 67.0, 142.0, 40.0 ],
					"text" : "Toggle the display of all barlines"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 6.0, 77.0, 20.0, 20.0 ]
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
					"patching_rect" : [ 6.0, 109.163635, 104.0, 19.0 ],
					"text" : "showbarlines $1"
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
					"patching_rect" : [ 57.0, 138.836365, 183.0, 40.0 ],
					"text" : "Draw, when possible, barlines across the voices"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.29,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-5",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 83.0, 221.0, 162.0, 69.0 ],
					"text" : "When barlines don't coincide for all voices, nothing happens"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "G", "G" ],
					"constraintbeamsinspaces" : 0,
					"enharmonictable" : [ "default", "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0 ],
					"id" : "obj-15",
					"keys" : [ "CM", "CM", "CM" ],
					"loop" : [ "(", 1, 1, 1, ")", "(", 1, 1, 1, ")" ],
					"maxclass" : "bach.score",
					"measurenumberfontsize" : 12.0,
					"midichannels" : [ 1, 2, 3 ],
					"minmeaswidth" : 50.0,
					"minmeaswidthpersymunit" : 90.0,
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 3,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 271.163635, 602.0, 200.836365 ],
					"pitcheditrange" : "null",
					"showmeasurenumbers" : [ 1, 1, 1 ],
					"spacingwidth" : 1.6,
					"stafflines" : [ 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7200,
					"voicenames" : [ "<none>", "<none>", "<none>" ],
					"voicespacing" : [ 0.0, 26.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 110, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", "(", "barline", "t", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 55, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "-1/2", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 110, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 6, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "-1/2", 0, ")", 0, ")", "(", "(", "(", 6, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "-1/2", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -154.0, 120.836365, 77.0, 21.0 ],
					"text" : "loadmess 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 32.0, 149.836365, 20.0, 20.0 ]
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
					"patching_rect" : [ 32.0, 186.0, 179.0, 19.0 ],
					"text" : "drawbarlinesacrossstaves $1"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "G", "G" ],
					"constraintbeamsinspaces" : 0,
					"enharmonictable" : [ "default", "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0 ],
					"id" : "obj-3",
					"keys" : [ "CM", "CM", "CM" ],
					"loop" : [ "(", 1, 1, 1, ")", "(", 1, 1, 1, ")" ],
					"maxclass" : "bach.score",
					"measurenumberfontsize" : 12.0,
					"midichannels" : [ 1, 2, 3 ],
					"minmeaswidth" : 50.0,
					"minmeaswidthpersymunit" : 90.0,
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 3,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 234.0, 73.163635, 374.0, 191.0 ],
					"pitcheditrange" : "null",
					"showmeasurenumbers" : [ 1, 1, 1 ],
					"spacingwidth" : 1.6,
					"stafflines" : [ 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7200,
					"voicenames" : [ "<none>", "<none>", "<none>" ],
					"voicespacing" : [ 0.0, 26.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 110, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", "(", "barline", "p", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", "(", "barline", "t", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 110, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 110, ")", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 1, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 0, 0, "(", "graphic", 6000, 0, ")", 0, ")", 0, ")", ")", "(", "-1/16", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-21",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 31.0, 606.0, 36.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "When barline coincide in all voices, you can choose to mark such coincidence by drawing a single long barline across all the staves. This is handled via the \"drawbarlinesacrossstaves\" attribute.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
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
					"patching_rect" : [ 6.0, 514.0, 602.0, 19.0 ],
					"text" : "See Also: measure+number",
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
					"patching_rect" : [ 6.0, 495.0, 602.0, 19.0 ],
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
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 299.0, 23.0 ],
					"text" : "Barlines",
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
					"patching_rect" : [ 6.0, 476.0, 602.0, 19.0 ],
					"text" : "Tags: appearance, barline, across, staff, staves, show, hide, showbarlines, drawbarlinesacrossstaves",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
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
 ]
	}

}
