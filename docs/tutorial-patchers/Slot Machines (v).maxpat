{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 124.0, 44.0, 898.0, 472.0 ],
		"bglocked" : 0,
		"defrect" : [ 124.0, 44.0, 898.0, 472.0 ],
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
					"text" : "If you evaluate or play a note, you see that the content of a spat slot comes in the form (t d a i) (t d a i) ... where t is time (0 to 1, 0 = beginning of the note, 1 = end of the note), d is distance (within the chosen range), a is angle (in degrees) and i is interpolation type (0 for circular, default, and 1 for linear)",
					"linecount" : 6,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 431.0, 353.0, 304.0, 89.0 ],
					"numinlets" : 1,
					"id" : "obj-36",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.print SpatSlot",
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 732.0, 406.0, 112.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-34",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys 6 @maxdepth 2",
					"fontsize" : 12.0,
					"outlettype" : [ "", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 732.0, 379.0, 153.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-33",
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys slots",
					"fontsize" : 12.0,
					"outlettype" : [ "", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 732.0, 356.0, 93.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-32",
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We're keeping the 1th and 6th slot in the background",
					"linecount" : 2,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 633.0, 239.0, 185.0, 34.0 ],
					"numinlets" : 1,
					"id" : "obj-30",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"fontsize" : 12.0,
					"velocityhandling" : 1,
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"zoom" : 20.0,
					"popupmenuslots" : [  ],
					"voicespacing" : [ -5.142858, 7.035713 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"bgslots" : [ 1, 6 ],
					"fontname" : "Arial",
					"patching_rect" : [ 430.0, 238.0, 371.0, 113.523804 ],
					"versionnumber" : 6500,
					"numinlets" : 6,
					"id" : "obj-27",
					"automessage" : [  ],
					"legend" : 0,
					"numoutlets" : 8,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplienv", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", -120, -60, -30, -15, 0, 10, ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "Loop On", "Loop Off", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "routing", ")", "(", "type", "floatmatrix", ")", "(", "key", "m", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "(", "(", "fshift", "transp", "degrade", "OUT", ")", "(", "sfiles", "fshift", "degrade", "spat", ")", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, ")", ")", "(", 6, "(", "name", "surround pan", ")", "(", "type", "spat", ")", "(", "key", "s", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068630016, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65045, 1071884602, "_x_x_x_x_bach_float64_x_x_x_x_", 42336, -1070414810, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 49065, 1072098561, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22432, 1072455159, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", "(", 5, "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56494, -1070257443, "_x_x_x_x_bach_float64_x_x_x_x_", 6568, -1069905679, "_x_x_x_x_bach_float64_x_x_x_x_", 54422, -1069040561, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 3224, -1070252828, "_x_x_x_x_bach_float64_x_x_x_x_", 36502, -1069538658, "_x_x_x_x_bach_float64_x_x_x_x_", 34594, -1069322283, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 34152, -1069530744, "_x_x_x_x_bach_float64_x_x_x_x_", 29598, -1068934246, "_x_x_x_x_bach_float64_x_x_x_x_", 65474, -1069238435, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33378, -1069374785, "_x_x_x_x_bach_float64_x_x_x_x_", 60358, -1069028959, "_x_x_x_x_bach_float64_x_x_x_x_", 35168, -1072012124, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", ")", ")", "(", 6, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 14977, 1070814036, "_x_x_x_x_bach_float64_x_x_x_x_", 36408, 1075946382, "_x_x_x_x_bach_float64_x_x_x_x_", 45365, 1082127830, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 29876, 1071697389, "_x_x_x_x_bach_float64_x_x_x_x_", 50969, 1074852295, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 52264, 1072165423, "_x_x_x_x_bach_float64_x_x_x_x_", 50970, 1075507655, "_x_x_x_x_bach_float64_x_x_x_x_", 35157, -1068280230, 1, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65535, 1084062378, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 29365, 1070840781, "_x_x_x_x_bach_float64_x_x_x_x_", 53248, 1074622170, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", "(", 5, "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56494, -1070257443, "_x_x_x_x_bach_float64_x_x_x_x_", 6568, -1069905679, "_x_x_x_x_bach_float64_x_x_x_x_", 54422, -1069040561, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 3224, -1070252828, "_x_x_x_x_bach_float64_x_x_x_x_", 36502, -1069538658, "_x_x_x_x_bach_float64_x_x_x_x_", 34594, -1069322283, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 34152, -1069530744, "_x_x_x_x_bach_float64_x_x_x_x_", 29598, -1068934246, "_x_x_x_x_bach_float64_x_x_x_x_", 65474, -1069238435, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33378, -1069374785, "_x_x_x_x_bach_float64_x_x_x_x_", 60358, -1069028959, "_x_x_x_x_bach_float64_x_x_x_x_", 35168, -1072012124, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", ")", ")", "(", 6, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 60301, 1069748225, "_x_x_x_x_bach_float64_x_x_x_x_", 50973, 1075343815, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 41065, 1071657271, "_x_x_x_x_bach_float64_x_x_x_x_", 29128, 1075453041, "_x_x_x_x_bach_float64_x_x_x_x_", 17333, 1080615754, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1116, 1072192168, "_x_x_x_x_bach_float64_x_x_x_x_", 29128, 1075780721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Domain values are by default from 0. to 1., you can change them, but that would make less sense than with function slots: indeed, spat slots are by design thought to be temporal.",
					"linecount" : 3,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 8.0, 241.0, 361.0, 48.0 ],
					"numinlets" : 1,
					"id" : "obj-26",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Inside the slot window, a spat slot looks similar to a functino slot, except that points are kind of big clocks pointing towards the top. The idea is that vertical position is the distance with respect to the listener (low values are nearest), but you also can change the direction angle of the source, by Ctrl+Click&drag on each point. \nIf you do this, you immediately see the segments become curved, following the \"ideal\" circular path of sound to get from one angle position to another. If you continue to twist angles, you can make sound turn more than once around the listener.",
					"linecount" : 7,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 380.0, 121.0, 489.0, 103.0 ],
					"numinlets" : 1,
					"id" : "obj-24",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "the range refers to a distance (e.g. in meters)",
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 382.0, 91.0, 301.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-22",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "By default the interpolation type between two spatial points is thought as circular (i.e. the sound whirls around listeners), but you can switch to a linear interpolation between spat points by alt+clicking on them: immediately the circular path become linear.\nOnce again, consider that bach doesn't make any DSP treatment: all you see and all you get is CONTROL values. It's up to you to operate properly with them, e.g. to let them handle a [vbap] object or an Ircam [spat~] object",
					"linecount" : 7,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 9.0, 291.0, 421.0, 103.0 ],
					"numinlets" : 1,
					"id" : "obj-29",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[slotinfo [6 [name \"surround pan\" ] [type spat] [range 0 10] [key s]]]",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 7.0, 90.0, 371.0, 18.0 ],
					"numinlets" : 2,
					"id" : "obj-39",
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"fontsize" : 12.0,
					"velocityhandling" : 1,
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"zoom" : 20.0,
					"popupmenuslots" : [  ],
					"voicespacing" : [ -5.142858, 7.035713 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"bgslots" : [  ],
					"fontname" : "Arial",
					"patching_rect" : [ 7.0, 126.0, 371.0, 113.523804 ],
					"versionnumber" : 6500,
					"numinlets" : 6,
					"id" : "obj-45",
					"automessage" : [  ],
					"numoutlets" : 8,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplienv", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", -120, -60, -30, -15, 0, 10, ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "Loop On", "Loop Off", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "routing", ")", "(", "type", "floatmatrix", ")", "(", "key", "m", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "(", "(", "fshift", "transp", "degrade", "OUT", ")", "(", "sfiles", "fshift", "degrade", "spat", ")", ")", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, ")", ")", "(", 6, "(", "name", "surround pan", ")", "(", "type", "spat", ")", "(", "key", "s", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1068630016, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65045, 1071884602, "_x_x_x_x_bach_float64_x_x_x_x_", 42336, -1070414810, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 49065, 1072098561, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 22432, 1072455159, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", "(", 5, "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56494, -1070257443, "_x_x_x_x_bach_float64_x_x_x_x_", 6568, -1069905679, "_x_x_x_x_bach_float64_x_x_x_x_", 54422, -1069040561, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 3224, -1070252828, "_x_x_x_x_bach_float64_x_x_x_x_", 36502, -1069538658, "_x_x_x_x_bach_float64_x_x_x_x_", 34594, -1069322283, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9706, -1069116638, "_x_x_x_x_bach_float64_x_x_x_x_", 34152, -1069530744, "_x_x_x_x_bach_float64_x_x_x_x_", 29598, -1068934246, "_x_x_x_x_bach_float64_x_x_x_x_", 65474, -1069238435, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33378, -1069374785, "_x_x_x_x_bach_float64_x_x_x_x_", 60358, -1069028959, "_x_x_x_x_bach_float64_x_x_x_x_", 35168, -1072012124, "_x_x_x_x_bach_float64_x_x_x_x_", 9968, -1069475718, ")", ")", ")", "(", 6, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 58137, 1070894271, "_x_x_x_x_bach_float64_x_x_x_x_", 50970, 1075179975, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 7212, 1070712604, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "It is worthed to get a glimpse on the spatialization slot. If you work with stereo soundfiles, of course a float \"panning\" slot might be largely enough; yet handling surround panning in most other situations can be a hard work. That's where the spat-type of slot comes to help: it provides an easy interface for dealing temporally with the ”position\" of a sound source. ",
					"linecount" : 3,
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 4.0, 38.0, 719.0, 48.0 ],
					"numinlets" : 1,
					"id" : "obj-13",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 180.0, 494.0, 81.0, 18.0 ],
					"numinlets" : 2,
					"id" : "obj-19",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 v \"Slot Machines\"",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 180.0, 546.5, 189.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-198",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"fontsize" : 12.0,
					"outlettype" : [ "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 180.0, 519.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-90",
					"hidden" : 1,
					"numoutlets" : 2,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "A last example? An astonishing one?! (sarcasm...)",
					"fontsize" : 12.0,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 456.0, 446.0, 296.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-61",
					"fontface" : 2,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"fontsize" : 12.0,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-87",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- surround spatialization control",
					"fontsize" : 16.787033,
					"fontname" : "Arial Italic",
					"patching_rect" : [ 184.0, 7.74086, 371.0, 26.0 ],
					"numinlets" : 1,
					"id" : "obj-2",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (v)",
					"fontsize" : 22.256727,
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 2.924051, 184.0, 32.0 ],
					"numinlets" : 1,
					"id" : "obj-3",
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 572.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-1",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 547.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-4",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 522.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-5",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines [u]",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 497.0, 140.0, 18.0 ],
					"numinlets" : 2,
					"id" : "obj-7",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"fontsize" : 12.0,
					"outlettype" : [ "bang", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 5.0, 472.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-8",
					"hidden" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"fontsize" : 12.0,
					"outlettype" : [ "", "", "int" ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Back to section (u)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 5.0, 447.0, 151.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-10",
					"fontface" : 2,
					"numoutlets" : 3
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 743.0, 572.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-11",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 743.0, 547.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-12",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 743.0, 522.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-14",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines [w]",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 743.0, 497.0, 140.0, 18.0 ],
					"numinlets" : 2,
					"id" : "obj-16",
					"hidden" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"fontsize" : 12.0,
					"outlettype" : [ "bang", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 743.0, 472.0, 40.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-17",
					"hidden" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"fontsize" : 12.0,
					"outlettype" : [ "", "", "int" ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Continue to section (w)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 743.0, 447.0, 151.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-20",
					"fontface" : 2,
					"numoutlets" : 3
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
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
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 1 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-17", 0 ],
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
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 6 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
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
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 189.5, 572.5, 171.5, 572.5, 171.5, 514.0, 189.5, 514.0 ]
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
 ]
	}

}
