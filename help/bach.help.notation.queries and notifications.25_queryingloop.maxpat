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
		"rect" : [ 262.0, 44.0, 617.0, 539.0 ],
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
					"id" : "obj-3",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 472.5, 214.0, 124.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "see #loop+interface",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-14",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 26.0, 172.0, 447.0, 84.0 ],
					"text" : "If you change the loop extremes, or if you show/hide the loop, as via Cmd+L (mac) or Ctrl+L (win), or if you turn it on or off,  a notification is sent in the form \"loop on/off\". When the loop is made active, also the loop region extremes are output, as if a \"getloop\" message was automatically sent"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"linecount" : 5,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 76.0, 83.0, 525.61908, 80.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Answer for bach.roll is in the form: loop <loop_start_ms> <loop_end_ms>\nAnswer for bach.score is in the form:\nloop <loop_start_ms> <loop_end_ms> <loop_start_timepoint> <loop_end_timepoint>\nwhere each #timepoint is in the form \n(<measure_number> <sym_onset_in_measure> <voice_number>)",
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
					"numoutlets" : 0,
					"patching_rect" : [ 470.5, 424.0, 138.0, 21.0 ],
					"text" : "print Score @popup 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-20",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 13.380936, 424.0, 127.0, 21.0 ],
					"text" : "print Roll @popup 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-19",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 409.0, 392.5, 195.0, 21.0 ],
					"text" : "bach.keys loop @keep 1 @out t"
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
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 13.380936, 392.5, 195.0, 21.0 ],
					"text" : "bach.keys loop @keep 1 @out t"
				}

			}
, 			{
				"box" : 				{
					"cautionaryaccidentalsdecay" : 2563,
					"clefs" : [ "G", "F" ],
					"constraintbeamsinspaces" : 0,
					"enharmonictable" : [ "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-6",
					"keys" : [ "CM", "CM" ],
					"loop" : [ "(", 1, 1, 0, ")", "(", 2, 2, "3/4", ")" ],
					"maxclass" : "bach.score",
					"midichannels" : [ 1, 2 ],
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 2,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 295.0, 241.0, 313.0, 139.333328 ],
					"pitcheditrange" : "null",
					"showloop" : 1,
					"showmeasurenumbers" : [ 1, 1 ],
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "<none>", "<none>" ],
					"voicespacing" : [ -3.0, 21.5 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, 2, ")", "(", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 60, 0, 1, ")", "(", "1/4", 18, "4/5", ")", ")", ")", "(", "leveltype", 9, ")", "(", "(", "leveltype", 18, ")", "(", "1/3", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085851355, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", "(", "1/20", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086107355, 127, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", "(", "1/4", 6, "1/4", 1, ")", "(", "1/4", 82, "2/3", ")", ")", ")", "(", "leveltype", 9, ")", "(", "(", "leveltype", 18, ")", "(", "1/3", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086078098, 127, 0, 0, ")", 0, ")", "(", "1/3", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086078098, 127, 0, 0, ")", 0, ")", "(", "1/3", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086078098, 127, 0, 0, ")", 0, ")", ")", 0, ")", 0, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085341184, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085569755, 127, 0, 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085289984, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085520384, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 127, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 9, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085341184, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085569755, 127, 0, 0, ")", 0, ")", "(", "(", "leveltype", 8, ")", "(", "-1/4", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085289984, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085520384, 127, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 127, 0, 0, ")", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 76.0, 58.0, 223.0, 25.0 ],
					"text" : "Retrieve the loop region extremes"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "G", "F" ],
					"enharmonictable" : [ "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-1",
					"keys" : [ "CM", "CM" ],
					"loop" : [ 382.353302, 2290.443359 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 1, 2 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 2,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 241.0, 280.0, 139.333328 ],
					"pitcheditrange" : "null",
					"showloop" : 1,
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "<none>", "<none>" ],
					"voicespacing" : [ 0.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, 2, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079984710, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081663488, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082612472, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081663488, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086134784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081663488, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084065527, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085532672, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084460826, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085776384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084652881, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086357760, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084814381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085981184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083871232, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085703618, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085776384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084073984, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085878784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084073984, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086166988, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081663488, 127, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081461173, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083417876, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085289984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085571584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084239686, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, 127, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085545984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, 127, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 108.799896
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 7.0, 61.0, 53.0, 19.0 ],
					"text" : "getloop"
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
					"text" : "See Also: showloop, useloop, loop+interface, timepoint+syntax",
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
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 299.0, 23.0 ],
					"text" : "Loop query and notifications",
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
					"patching_rect" : [ 6.0, 476.0, 598.0, 19.0 ],
					"text" : "Tags: query, queries, notify, notification, loop, region, getloop",
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
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 32.0, 592.0, 21.0 ],
					"text" : "The loop region extremes can be retrieven via the \"getloop\" message.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 6 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 16.5, 200.5, 304.5, 200.5 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-6", 7 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
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
 ]
	}

}
