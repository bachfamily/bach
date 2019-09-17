{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 49.0, 45.0, 788.0, 477.0 ],
		"bglocked" : 0,
		"defrect" : [ 49.0, 45.0, 788.0, 477.0 ],
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
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 334.0, 582.0, 81.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 i \"Through The Looking Glass\"",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 333.5, 637.0, 258.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 333.5, 609.5, 69.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t l clear",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 394.0, 289.0, 49.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "", "clear" ],
					"id" : "obj-20",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ -231.0, 46.0, 60.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"id" : "obj-60",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess clear",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ -113.0, 314.0, 91.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-59",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "score [ [ [ [ 4 4 ] [ ] ] [ 1/12 [ 7500. 127 0 0 ] 0 ] [ 1/12 [ 6400. 127 0 0 ] 0 ] [ 1/12 [ 7100. 127 0 0 ] 0 ] [ 1/8 [ 7200. 127 0 0 ] 0 ] [ 1/8 [ 6500. 127 0 0 ] 0 ] [ 3/16 [ 8100. 127 0 0 ] 0 ] [ 1/16 [ 6900. 127 0 0 ] 0 ] [ 1/8 [ 7200. 127 0 0 ) 0 ) ( 1/8 ( 8300. 127 1 0 ) 0 ) 0 ) ( ( ( 4 4 ) ( ) ) ( 1/4 ( 8300. 127 1 0 ) 0 ) ( 1/12 ( 8300. 127 0 0 ) 0 ) ( 1/6 ( 8300. 127 0 0 ) 0 ) ( 1/6 ( 7285.710938 127 0 0 ) 0 ) ( 1/12 ( 6400. 127 1 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) ( 1/28 ( 6400. 127 0 0 ) 0 ) 0 ) )",
					"linecount" : 13,
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ -271.0, 85.0, 257.0, 184.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-58",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Basically the third option is what we would need/expect. But, as you'll surely have noticed, we would expect ties to be reversed as well!",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 497.0, 333.0, 264.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-54",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "reverse measures and also rhythms inside the measures.",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 581.0, 295.0, 184.0, 34.0 ],
					"numoutlets" : 0,
					"id" : "obj-52",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "maxdepth 3",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 505.0, 296.0, 73.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-53",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "only reverse measures!\n(N.B.: be careful, it does not reverse ties!! Thus the 7-plet is retranscribed, since two notes will be tied!)",
					"linecount" : 5,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 581.0, 218.0, 184.0, 75.0 ],
					"numoutlets" : 0,
					"id" : "obj-48",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "maxdepth 2",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 505.0, 219.0, 73.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-47",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "does nothing: it reverses voices, but we have just a voice!",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 580.0, 165.0, 154.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-46",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "maxdepth 1",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 504.0, 170.0, 73.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-44",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "dump",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 3.0, 168.0, 41.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-42",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"patching_rect" : [ 3.0, 289.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"id" : "obj-40"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"vzoom" : 83.63636,
					"numvoices" : 1,
					"popupmenuslots" : [  ],
					"fontsize" : 12.0,
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnnn",
					"bgslots" : [  ],
					"stafflines" : 5,
					"numinlets" : 7,
					"loop" : "null",
					"patching_rect" : [ 3.0, 319.0, 488.0, 92.0 ],
					"preventedit" : [  ],
					"automessage" : [  ],
					"numoutlets" : 9,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 6999,
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"voicespacing" : [ 0.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "[bach.rev] is the object we need: it reverses an llll, until a certain level of depth. By default, it reverses all levels, but one might choose to reverse only until a certain level. Do you remember what levels were in score? Level 1 concerns voices, level 2 concerns measures, level 3 concerns chords, level 4 concerns notes. As far as the duration are concerned, they only go until level 3.",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 3.0, 118.0, 720.0, 48.0 ],
					"numoutlets" : 0,
					"id" : "obj-89",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.rev 3",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 179.0, 286.0, 67.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-87",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"vzoom" : 83.63636,
					"numvoices" : 1,
					"popupmenuslots" : [  ],
					"fontsize" : 12.0,
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnnn",
					"bgslots" : [  ],
					"stafflines" : 5,
					"numinlets" : 7,
					"loop" : "null",
					"patching_rect" : [ 3.0, 188.0, 488.0, 92.0 ],
					"preventedit" : [  ],
					"automessage" : [  ],
					"numoutlets" : 9,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 6999,
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"id" : "obj-86",
					"fontname" : "Arial",
					"voicespacing" : [ 0.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", "q", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", "w", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", "e", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", "r", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", "t", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", "y", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", "u", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", "i", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 24, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 127, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 127, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 127, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "3/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 127, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 127, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 127, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 127, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 18, ")", "(", "1/3", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 127, 0, 0, ")", 0, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 127, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/6", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086092726, 127, 0, 0, ")", 0, ")", "(", "1/12", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 24, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", "(", "1/28", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 127, 0, 0, ")", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Some more bach objects might be useful when dealing with score transformations. Up to now, what we did was just to modify the list of midicents in different ways. But, of course, one might want to deal with other parameters as well. For example, one might want to perform a retrogradation of a given melody. And things get immediately slightly more complicated, due to the fact that [bach.score] has a measure-wise syntax.\nThis means that, for instance, in order to reverse a score one might just want to simply exploit an object to reverse lllls.",
					"linecount" : 5,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 4.0, 42.0, 717.0, 75.0 ],
					"numoutlets" : 0,
					"id" : "obj-16",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Uhm... I find a lot of tie and pitch issues. Plus, I'd expect that a tied note would be reversed in its overall duration, considering the tie. How do I do that?",
					"linecount" : 3,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 324.0, 429.0, 325.0, 48.0 ],
					"numoutlets" : 0,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-256",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 1.0, 16.0, 444.0, 20.0 ],
					"numoutlets" : 0,
					"id" : "obj-49",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- naive retrogradation",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"patching_rect" : [ 309.0, 6.74086, 383.0, 26.0 ],
					"numoutlets" : 0,
					"id" : "obj-50",
					"fontname" : "Arial Italic"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Through The Looking Glass (i)",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"patching_rect" : [ 2.0, 1.924051, 318.0, 32.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 577.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 552.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 527.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Through The Looking Glass [h]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 5.0, 502.0, 174.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 477.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-6",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Back to section (h)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 5.0, 452.0, 151.0, 20.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"id" : "obj-8",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 633.0, 577.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 633.0, 552.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 633.0, 527.0, 140.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Through The Looking Glass [j]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"patching_rect" : [ 633.0, 502.0, 170.0, 18.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 633.0, 477.0, 40.0, 20.0 ],
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-15",
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Continue to section (j)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"patching_rect" : [ 633.0, 452.0, 151.0, 20.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"outlettype" : [ "", "", "int" ],
					"id" : "obj-18",
					"fontname" : "Arial"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 1 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-19", 0 ],
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
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 1 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 1 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 0.0, 0.094118, 1.0, 0.768627 ],
					"midpoints" : [ 433.5, 312.0, 12.5, 312.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-38", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 5 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-59", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 4 ],
					"destination" : [ "obj-38", 4 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 2 ],
					"destination" : [ "obj-38", 2 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 1 ],
					"destination" : [ "obj-38", 1 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 0.317647 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-87", 0 ],
					"destination" : [ "obj-38", 3 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-87", 0 ],
					"hidden" : 0,
					"color" : [ 0.396078, 0.098039, 0.098039, 0.258824 ],
					"midpoints" : [ 513.5, 192.0, 501.0, 192.0, 501.0, 284.0, 188.5, 284.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 0 ],
					"destination" : [ "obj-87", 0 ],
					"hidden" : 0,
					"color" : [ 0.396078, 0.098039, 0.098039, 0.258824 ],
					"midpoints" : [ 514.5, 241.0, 501.0, 241.0, 501.0, 284.0, 188.5, 284.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-53", 0 ],
					"destination" : [ "obj-87", 0 ],
					"hidden" : 0,
					"color" : [ 0.396078, 0.098039, 0.098039, 0.258824 ],
					"midpoints" : [ 514.5, 323.0, 500.5, 323.0, 500.5, 283.0, 188.5, 283.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 3 ],
					"destination" : [ "obj-87", 0 ],
					"hidden" : 0,
					"color" : [ 0.301961, 0.172549, 0.172549, 0.27451 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 0.317647 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-86", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 8 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 0,
					"midpoints" : [ 481.5, 281.0, 496.0, 281.0, 496.0, 166.0, 12.5, 166.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-86", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-58", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [ 343.0, 663.0, 327.0, 663.0, 327.0, 604.5, 343.0, 604.5 ]
				}

			}
 ]
	}

}
