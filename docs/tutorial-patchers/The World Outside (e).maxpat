{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 94.0, 44.0, 742.0, 583.0 ],
		"bglocked" : 0,
		"defrect" : [ 94.0, 44.0, 742.0, 583.0 ],
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
					"text" : "(Notice the \"A\" marker: it is an ordinary marker which was contained in the midi file. There are a few others, marking different sections of the piece)",
					"linecount" : 6,
					"id" : "obj-27",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 541.0, 364.0, 162.0, 89.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "select all, legato, clearselection",
					"id" : "obj-28",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 315.0, 491.0, 177.0, 18.0 ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Tip: sometimes is advisable to pre-treat the roll data before quantizing. Something which could help a proper representation inside a score, is to send previously a \"legato\" message to the roll (forcing all chords to end when the next one begins). To have a complete legato, you should send something like\nAlternatively (or in addition), if you need a precise quantization, you might want to choose the EXHAUSTIVE algorithm as [bach.quantize] algorithm in the inspector (but beware: this might take much more time than the GREEDY algorithm!)",
					"linecount" : 5,
					"id" : "obj-23",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 463.0, 669.0, 75.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If you use \"markmeasures 1\", the barlines are always marked in roll by the presence of markers. This helps [bach.quantize] to understand the metric of the musical data, and infer the proper measureinfo.",
					"linecount" : 8,
					"id" : "obj-50",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 499.0, 194.0, 154.0, 117.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess clear",
					"id" : "obj-48",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ -108.0, 340.0, 91.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.score",
					"out" : "nnnnnnnn",
					"id" : "obj-47",
					"bgslots" : [  ],
					"fontname" : "Arial",
					"stafflines" : 5,
					"preventedit" : [  ],
					"automessage" : [  ],
					"versionnumber" : 6999,
					"presentation_rect" : [ 0.0, 0.0, 0.0, 96.0 ],
					"fontsize" : 12.0,
					"numinlets" : 7,
					"voicespacing" : [ -1.0, 13.0 ],
					"numoutlets" : 9,
					"loop" : [ "(", 1, ")", "(", 1, ")" ],
					"patching_rect" : [ 10.0, 365.0, 526.0, 96.0 ],
					"numvoices" : 1,
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"keys" : [ "GM" ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"popupmenuslots" : [  ],
					"voicenames" : [ "(", ")" ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<< give \"auto\" as measureinfo, and [bach.quantize] will interpret automatically the special roll markers! ",
					"id" : "obj-46",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 50.0, 317.0, 588.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "auto",
					"id" : "obj-44",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 10.0, 318.0, 34.0, 18.0 ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.quantize @minimalunits 1/16",
					"id" : "obj-26",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 3,
					"numoutlets" : 1,
					"patching_rect" : [ 10.0, 340.0, 194.0, 20.0 ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "You might have already noticed that, when you read a MIDI file in [bach.roll], a few of those markers may show up (for instance specifying a time-signature, and a tempo). If you want to quantize the MIDI file, the best way to go is to force the import to show all the measure markers, by adding the specification \"(markmeasures 1)\" to the read message:",
					"linecount" : 3,
					"id" : "obj-25",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 114.0, 726.0, 48.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<< \"read\", and then \"quantize\"!",
					"id" : "obj-24",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 433.0, 163.0, 181.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "quantize",
					"id" : "obj-22",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 369.0, 163.0, 56.0, 18.0 ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "A MIDI file is not a traditionally notated score: the MIDI representation is more akin to the [bach.roll] representation, that's why you can import easily the MIDI file in a [bach.roll]. If you want to turn it into measured notation, you need to quantize it. Yet, since a MIDI file contains some additional information, there's an easy way to do that, which takes advantage of the fact that markers, in [bach.roll], can have special \"roles\", representing time signatures, tempi, barlines, divisions (have a look at the marker's inspector, if you're curious!). [bach.quantize], which is in charge for quantization tasks, is able to interpret these markers properly, and quantize accordingly.",
					"linecount" : 5,
					"id" : "obj-21",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 41.0, 725.0, 75.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read \"Real Time Stories [g] - bach.mid\" [markmeasures 1]",
					"id" : "obj-69",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 10.0, 163.0, 319.0, 18.0 ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"out" : "nnnnnnn",
					"id" : "obj-67",
					"bgslots" : [  ],
					"fontname" : "Arial",
					"stafflines" : 5,
					"preventedit" : [  ],
					"zoom" : 44.921875,
					"automessage" : [  ],
					"versionnumber" : 6999,
					"presentation_rect" : [ 0.0, 0.0, 0.0, 118.0 ],
					"fontsize" : 12.0,
					"numinlets" : 6,
					"voicespacing" : [ -6.0, 40.0 ],
					"numoutlets" : 8,
					"loop" : [ 0.0, 0.0 ],
					"patching_rect" : [ 10.0, 189.0, 485.0, 118.0 ],
					"numvoices" : 1,
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"keys" : [ "GM" ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"popupmenuslots" : [  ],
					"voicenames" : [ "(", ")" ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"id" : "obj-19",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 183.0, 588.0, 81.0, 18.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 e \"The World Outside\"",
					"id" : "obj-198",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 183.0, 640.5, 214.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"id" : "obj-90",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 183.0, 613.0, 69.0, 20.0 ],
					"outlettype" : [ "", "" ],
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "MIDI sucks. What about compatibility with other CAC environments?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 355.0, 544.0, 220.0, 34.0 ],
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"id" : "obj-87",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- MIDI import to bach.score",
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 230.0, 7.74086, 211.0, 26.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The World Outside (e)",
					"id" : "obj-3",
					"fontname" : "Arial",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 229.0, 32.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"id" : "obj-1",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 683.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"id" : "obj-4",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 658.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"id" : "obj-5",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 633.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "The World Outside [d]",
					"id" : "obj-7",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 608.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"id" : "obj-8",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 5.0, 583.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"id" : "obj-10",
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Back to section (d)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 3,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"patching_rect" : [ 5.0, 558.0, 151.0, 20.0 ],
					"outlettype" : [ "", "", "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"id" : "obj-11",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 587.0, 683.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"id" : "obj-12",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 587.0, 658.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"id" : "obj-13",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 587.0, 633.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "The World Outside [f]",
					"id" : "obj-15",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 587.0, 608.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"id" : "obj-16",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 587.0, 583.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"id" : "obj-18",
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"text" : "Continue to section (f)",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 3,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"patching_rect" : [ 587.0, 558.0, 151.0, 20.0 ],
					"outlettype" : [ "", "", "int" ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-67", 0 ],
					"destination" : [ "obj-26", 1 ],
					"hidden" : 0,
					"midpoints" : [ 19.5, 311.0, 47.0, 311.0, 47.0, 337.0, 107.0, 337.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-47", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-19", 0 ],
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
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 1 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-5", 0 ],
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
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-69", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 0,
					"midpoints" : [ 19.5, 184.5, 19.5, 184.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 0,
					"midpoints" : [ 378.5, 184.5, 19.5, 184.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-90", 0 ],
					"destination" : [ "obj-198", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 192.5, 666.5, 174.5, 666.5, 174.5, 608.0, 192.5, 608.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-67", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-47", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
