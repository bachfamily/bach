{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 30.0, 49.0, 766.0, 485.0 ],
		"bglocked" : 0,
		"defrect" : [ 30.0, 49.0, 766.0, 485.0 ],
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
					"text" : "Once more, it is worth to stress that there's NO signal passing through bach objects, just control values, which will be helpful to handle your own filtering system!",
					"linecount" : 2,
					"id" : "obj-11",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 7.0, 425.0, 739.0, 34.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Now open the second slot: we have defined it as a \"dynfilter\" slot. As you see, the information is a \"surface\", which on the horizontal axis has the progressive time (from the beginning to the note, to its end), and on the vertical axis the frequency. Dark zones are zones where frequencies have more gain; pale zones are zones where the frequencies are dampened. What you see is a sequence of interpolated lowpass filter: as you can see, the pale grey area (dampened) is above the green area (undampened), which is the set of frequency which will pass through.\nThe red thin vertical rectangles you see can be considered as \"breakpoints\": actually they are the ONLY defined filters, and all the remaining part is an interpolation between them. You can click & drag to move filters - vertical drag will change their cutoff frequency, which is shown via the little red square. You can also change the filter type, by right-clicking on them - this will however change the type for all the filters of the slot! It doesn't make that much sense to interpolate between a bandpass and a lowpass filter, does it?",
					"linecount" : 9,
					"id" : "obj-38",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 7.0, 291.0, 737.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Open the first slot: we have defined it as a \"filter\" slot. As you see, it appears like a [filtergraph~] object, and you will be able to drag the graph to change the cutoff frequency (frequency is on the horizontal axis, amplitude on the vertical one, like in [filtergraph~]).\n\nChanging the filter type is also allowed: do this by right-clicking on the slot window, and choosing the type you wish to have!",
					"linecount" : 9,
					"id" : "obj-36",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 406.0, 159.0, 300.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"voicespacing" : [ -5.25, 17.0 ],
					"id" : "obj-34",
					"numvoices" : 1,
					"fontsize" : 12.0,
					"popupmenuslots" : [  ],
					"voicenames" : [ "(", ")" ],
					"out" : "nnnnnnn",
					"numinlets" : 6,
					"stafflines" : 5,
					"preventedit" : [  ],
					"bgslots" : [  ],
					"numoutlets" : 8,
					"automessage" : [  ],
					"versionnumber" : 6999,
					"fontname" : "Arial",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"loop" : "null",
					"patching_rect" : [ 9.0, 159.0, 396.0, 127.666664 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "mybiquad", ")", "(", "type", "filter", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1070071808, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1077411840, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087735936, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 13107, 1071854387, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "dynfilter", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087735936, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 13107, 1071854387, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079984128, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083266048, 100, "(", "slots", "(", 1, "_x_x_x_x_bach_float64_x_x_x_x_", 22454, 1059569994, "_x_x_x_x_bach_float64_x_x_x_x_", 22454, 1060618570, "_x_x_x_x_bach_float64_x_x_x_x_", 22454, 1059569994, "_x_x_x_x_bach_float64_x_x_x_x_", 59316, -1073760718, "_x_x_x_x_bach_float64_x_x_x_x_", 11968, 1072656982, "(", "lowpass", "_x_x_x_x_bach_float64_x_x_x_x_", 42361, 1080539597, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 32728, 1073270072, ")", ")", "(", 2, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3959, 1068925371, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 64611, 1061414523, "_x_x_x_x_bach_float64_x_x_x_x_", 64611, 1062463099, "_x_x_x_x_bach_float64_x_x_x_x_", 64611, 1061414523, "_x_x_x_x_bach_float64_x_x_x_x_", 40155, -1073795405, "_x_x_x_x_bach_float64_x_x_x_x_", 948, 1072591182, "(", "lowpass", "_x_x_x_x_bach_float64_x_x_x_x_", 25533, 1081467938, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", ")", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3841, 1071448004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 46443, 1065884052, "_x_x_x_x_bach_float64_x_x_x_x_", 46443, 1066932628, "_x_x_x_x_bach_float64_x_x_x_x_", 46443, 1065884052, "_x_x_x_x_bach_float64_x_x_x_x_", 25626, -1075871846, "_x_x_x_x_bach_float64_x_x_x_x_", 17721, -1076003534, "(", "lowpass", "_x_x_x_x_bach_float64_x_x_x_x_", 49547, 1084691660, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 53775, 1068715672, ")", ")", ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 30079, 1072411484, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 34221, 1040579179, "_x_x_x_x_bach_float64_x_x_x_x_", 34221, 1041627755, "_x_x_x_x_bach_float64_x_x_x_x_", 34221, 1040579179, "_x_x_x_x_bach_float64_x_x_x_x_", 9279, -1073742318, "_x_x_x_x_bach_float64_x_x_x_x_", 61231, 1072692261, "(", "lowpass", "_x_x_x_x_bach_float64_x_x_x_x_", 29783, 1071036781, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 58480, 1069254144, ")", ")", ")", ")", "(", 3, 57, 83, 28, ")", "(", 4, "_x_x_x_x_bach_float64_x_x_x_x_", 7865, 1070774353, "_x_x_x_x_bach_float64_x_x_x_x_", 44565, 1072043130, "_x_x_x_x_bach_float64_x_x_x_x_", 62916, 1071497871, ")", "(", 5, 80, ")", "(", 6, "_x_x_x_x_bach_float64_x_x_x_x_", 31458, 1069211975, ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "They basically implement a static or dynamic sequence of biquad filters (so when we say \"filter\" actually we mean \"biquad filter\"), for which they will be able to provide you the coefficients, exactly as the [filtergraph~] object does.",
					"linecount" : 2,
					"id" : "obj-26",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 122.0, 730.0, 34.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"id" : "obj-19",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 315.0, 470.0, 81.0, 18.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 0 1 a \"Filter Filter Little Star\"",
					"id" : "obj-198",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 315.0, 522.5, 225.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"id" : "obj-90",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"hidden" : 1,
					"patching_rect" : [ 315.0, 495.0, 69.0, 20.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Great. But how?!?!",
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"patching_rect" : [ 494.0, 462.0, 111.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "When dealing with synthesis or sampling, it might be extremely useful to incorporate information about filters inside each note. Of course this can already be done with numeric slots (e.g. floatlist slots), handling all the parameters of the filter. Nevertheless, having a more friendly interface and structure would really help. That's what \"filter\" and \"dynfilter\" slots are for!",
					"linecount" : 3,
					"id" : "obj-20",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 76.0, 739.0, 48.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"id" : "obj-87",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- how I wonder what you are!",
					"id" : "obj-2",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial Italic",
					"patching_rect" : [ 251.0, 7.74086, 477.0, 26.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Filter Filter Little Star (a)",
					"id" : "obj-3",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 2.924051, 249.0, 32.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "A specific and particular type of slot is the \"filter\" or \"dynfilter\" slot. It deserves a bit more of attention, so we've decided to dedicate to it a small tutorial.",
					"linecount" : 2,
					"id" : "obj-13",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 43.0, 718.0, 34.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"id" : "obj-1",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 611.0, 585.0, 140.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"id" : "obj-4",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 611.0, 560.0, 140.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"id" : "obj-5",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 611.0, 535.0, 140.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Filter Filter Little Star [b]",
					"id" : "obj-7",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"hidden" : 1,
					"patching_rect" : [ 611.0, 510.0, 140.0, 18.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"id" : "obj-8",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1,
					"patching_rect" : [ 611.0, 485.0, 40.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"id" : "obj-10",
					"fontface" : 2,
					"fontsize" : 12.0,
					"text" : "Continue to section (b)",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 3,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "", "", "int" ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"patching_rect" : [ 611.0, 460.0, 151.0, 20.0 ]
				}

			}
 ],
		"lines" : [ 			{
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
					"midpoints" : [ 324.5, 548.5, 306.5, 548.5, 306.5, 490.0, 324.5, 490.0 ]
				}

			}
 ]
	}

}
