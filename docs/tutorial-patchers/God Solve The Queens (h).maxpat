{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 2,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 34.0, 79.0, 899.0, 521.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 447.0, 226.0, 56.0, 22.0 ],
					"style" : "",
					"text" : "deferlow"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-48",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 447.0, 249.0, 49.0, 22.0 ],
					"style" : "",
					"text" : "loop all"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 368.0, 173.0, 110.0, 47.0 ],
					"style" : "",
					"text" : "Choose your background music during wait:"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 439.0, 206.0, 42.0, 17.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-25", "bach.score", "begin_preset", 3199, 256, "obj-25", "bach.score", "restore_preset", 0, 250, "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 250, 250, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 500, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 750, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "clefs", "FG", ")", "(", "keys", "GM", ")", "(", "voicenames", "(", ")", ")", "(", "markers", ")", "(", "stafflines", 5, ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 3, 256, "obj-25", "bach.score", "restore_preset", 1000, 250, 4, ")", "(", "(", "1/4", 100, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 68, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 73, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 1250, 250, 1085609984, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 80, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 83, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, 256, "obj-25", "bach.score", "restore_preset", 1500, 250, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 77, 0, "(", "graphic", 5000, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 72, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 79, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, 256, "obj-25", "bach.score", "restore_preset", 1750, 250, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 78, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 84, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 86, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 86, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 67, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 2000, 250, 1086121984, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 75, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 74, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 72, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 72, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 2250, 250, 1085993984, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 76, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 69, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 70, 0, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 2500, 250, ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 80, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 69, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 1, 256, "obj-25", "bach.score", "restore_preset", 2750, 250, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 1, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 72, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 83, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 84, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 81, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 76, 0, 0, 205, "obj-25", "bach.score", "restore_preset", 3000, 199, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 66, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 75, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "3/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", 0, ")", 0, ")", 4, "obj-25", "bach.score", "end_preset" ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-25", "bach.score", "begin_preset", 1274, 256, "obj-25", "bach.score", "restore_preset", 0, 250, "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 250, 250, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 500, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 750, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "clefs", "FG", ")", "(", "keys", "EM", ")", "(", "voicenames", "(", ")", ")", "(", "markers", ")", "(", "stafflines", 5, ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 4, 256, "obj-25", "bach.score", "restore_preset", 1000, 250, 4, ")", "(", "(", "1/4", 132, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 100, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 100, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 100, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 100, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 100, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 4, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 100, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 100, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 100, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 100, 0, "(", "graphic", 6000, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 100, 0, "(", "graphic", 6000, "1/2", ")", 0, ")", 0, ")", "(", 30, "obj-25", "bach.score", "restore_preset", 1250, 24, "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 100, 0, 0, ")", 0, ")", ")", 0, ")", 0, ")", 4, "obj-25", "bach.score", "end_preset" ]
						}
, 						{
							"number" : 3,
							"data" : [ 5, "obj-25", "bach.score", "begin_preset", 21659, 256, "obj-25", "bach.score", "restore_preset", 0, 250, "score", "(", "slotinfo", "(", 1, "(", "name", "\"amplitude", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "\"slot", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "\"slot", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "\"slot", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "\"slot", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 250, 250, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "\"slot", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 500, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, 256, "obj-25", "bach.score", "restore_preset", 750, 250, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "\"slot", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "clefs", "FG", ")", "(", "keys", "AM", ")", "(", "voicenames", "(", ")", ")", "(", "markers", ")", "(", "stafflines", 5, ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 2, 256, "obj-25", "bach.score", "restore_preset", 1000, 250, 4, ")", "(", "(", "1/4", 120, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 1250, 250, "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 1500, 250, 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", 256, "obj-25", "bach.score", "restore_preset", 1750, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", 256, "obj-25", "bach.score", "restore_preset", 2000, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 2250, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 2500, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 2750, 250, 1086121984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 3000, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 91, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 3250, 250, 1086045184, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 68, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 68, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 3500, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 256, "obj-25", "bach.score", "restore_preset", 3750, 250, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 4000, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 4250, 250, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 256, "obj-25", "bach.score", "restore_preset", 4500, 250, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 4750, 250, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 256, "obj-25", "bach.score", "restore_preset", 5000, 250, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 5250, 250, 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 91, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 91, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 91, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 75, 256, "obj-25", "bach.score", "restore_preset", 5500, 250, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 68, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, 256, "obj-25", "bach.score", "restore_preset", 5750, 250, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 6000, 250, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084971008, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084971008, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 1, 4, ")", "(", ")", ")", "(", 256, "obj-25", "bach.score", "restore_preset", 6250, 250, "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 6500, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 6750, 250, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 7000, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 7250, 250, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 256, "obj-25", "bach.score", "restore_preset", 7500, 250, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 7750, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 8000, 250, "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 8250, 250, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 91, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 1, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 8500, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 68, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 68, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 1, 0, ")", 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 8750, 250, "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 9000, 250, "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 256, "obj-25", "bach.score", "restore_preset", 9250, 250, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", 256, "obj-25", "bach.score", "restore_preset", 9500, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 256, "obj-25", "bach.score", "restore_preset", 9750, 250, 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 1, 256, "obj-25", "bach.score", "restore_preset", 10000, 250, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 10250, 250, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, 256, "obj-25", "bach.score", "restore_preset", 10500, 250, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 91, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 91, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 91, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 1, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 10750, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 75, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 68, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 256, "obj-25", "bach.score", "restore_preset", 11000, 250, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 11250, 250, ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084971008, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084971008, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "1/2", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", 0, ")", "(", "(", "(", 1, 4, ")", "(", ")", ")", "(", "leveltype", 256, "obj-25", "bach.score", "restore_preset", 11500, 250, 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 1, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, 256, "obj-25", "bach.score", "restore_preset", 11750, 250, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 256, "obj-25", "bach.score", "restore_preset", 12000, 250, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 12250, 250, "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, 256, "obj-25", "bach.score", "restore_preset", 12500, 250, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 256, "obj-25", "bach.score", "restore_preset", 12750, 250, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 256, "obj-25", "bach.score", "restore_preset", 13000, 250, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, 98, 0, 0, 256, "obj-25", "bach.score", "restore_preset", 13250, 250, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 99, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 256, "obj-25", "bach.score", "restore_preset", 13500, 250, 101, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 101, 0, "(", "graphic", 7600, "1/2", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 101, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 103, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 105, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 105, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 105, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 107, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 109, 1, "(", "graphic", 5200, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 109, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 109, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 111, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 113, 0, "(", "graphic", 7600, "1/2", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", 256, "obj-25", "bach.score", "restore_preset", 13750, 250, "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 113, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 112, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 110, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 110, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 110, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 108, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 106, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 106, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 106, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 104, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 102, 1, 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 14000, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 102, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 102, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 256, "obj-25", "bach.score", "restore_preset", 14250, 250, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 94, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 89, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 89, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 89, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 80, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 80, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 76, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 71, 1, "(", "graphic", 5200, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 71, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 66, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 61, 0, 256, "obj-25", "bach.score", "restore_preset", 14500, 250, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 14750, 250, 1086173184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 15000, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 61, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 61, 1, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 61, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 15250, 250, 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 61, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 256, "obj-25", "bach.score", "restore_preset", 15500, 250, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 61, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 15750, 250, 1085891584, 61, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 60, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 59, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 59, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 59, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 58, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 56, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 56, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 56, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 55, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 54, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 54, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 54, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 53, 0, "(", "graphic", 7600, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 51, 0, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 16000, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 51, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", 256, "obj-25", "bach.score", "restore_preset", 16250, 250, "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 51, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 51, 256, "obj-25", "bach.score", "restore_preset", 16500, 250, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, 51, 0, "(", "graphic", 5200, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 51, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 51, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 51, 0, "(", "graphic", 6400, "1/2", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 256, "obj-25", "bach.score", "restore_preset", 16750, 250, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 62, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 51, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 87, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 51, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 51, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 17000, 250, "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", 256, "obj-25", "bach.score", "restore_preset", 17250, 250, "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 256, "obj-25", "bach.score", "restore_preset", 17500, 250, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", 256, "obj-25", "bach.score", "restore_preset", 17750, 250, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 256, "obj-25", "bach.score", "restore_preset", 18000, 250, 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, 101, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 105, 1, 256, "obj-25", "bach.score", "restore_preset", 18250, 250, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 105, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 105, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 109, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402560, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402560, 113, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402560, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, 256, "obj-25", "bach.score", "restore_preset", 18500, 250, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 113, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 256, "obj-25", "bach.score", "restore_preset", 18750, 250, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 113, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 19000, 250, 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 113, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 113, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 113, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 113, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 113, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 71, 0, 0, ")", 0, ")", ")", 256, "obj-25", "bach.score", "restore_preset", 19250, 250, "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 71, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 1, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 19500, 250, 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 1, 0, ")", 0, ")", 256, "obj-25", "bach.score", "restore_preset", 19750, 250, "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 71, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 71, 1, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 72, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 74, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 74, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 75, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 77, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 77, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 78, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 80, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 80, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 81, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 256, "obj-25", "bach.score", "restore_preset", 20000, 250, 1085789184, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 84, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 84, 0, 256, "obj-25", "bach.score", "restore_preset", 20250, 250, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 84, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 84, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 84, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 84, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 20500, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 85, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 87, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 87, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 87, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, 88, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 90, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 90, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 90, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 92, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 93, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, 93, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 93, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 95, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 98, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 256, "obj-25", "bach.score", "restore_preset", 20750, 250, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 98, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 61, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 61, 0, 0, ")", 256, "obj-25", "bach.score", "restore_preset", 21000, 250, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", "(", "1/4", 118, "3/10", ")", "(", "1/4", 116, "13/40", ")", "(", "1/4", 115, "3/8", ")", "(", "1/4", 113, "17/40", ")", "(", "1/4", 111, "19/40", ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 98, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 98, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 100, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 100, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 103, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 105, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 105, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, 105, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 108, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, 110, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 110, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 110, 0, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, 110, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 110, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 113, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 2, 4, ")", "(", "(", "1/4", 256, "obj-25", "bach.score", "restore_preset", 21250, 250, 109, ")", "(", "1/4", 108, "1/20", ")", "(", "1/4", 106, "1/10", ")", "(", "1/4", 104, "1/8", ")", "(", "1/4", 102, "7/40", ")", "(", "1/4", 101, "9/40", ")", "(", "1/4", 99, "11/40", ")", "(", "1/4", 97, "3/10", ")", "(", "1/4", 95, "7/20", ")", "(", "1/4", 94, "2/5", ")", "(", "1/4", 92, "9/20", ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, 110, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 110, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 113, 0, 0, ")", 0, ")", "(", "1/16", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084612608, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 113, 0, 0, ")", 0, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084612608, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 113, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "(", "leveltype", 2, ")", "(", "1/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084612608, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, 113, 0, 0, ")", 0, ")", "(", "3/32", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084868608, 113, 1, 165, "obj-25", "bach.score", "restore_preset", 21500, 159, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 113, 1, 0, ")", 0, ")", ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084868608, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 113, 1, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 1, 4, ")", "(", "(", "1/4", 61, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084868608, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 113, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 113, 0, 0, ")", 0, ")", "(", "-1/8", 0, ")", ")", 0, ")", 0, ")", 4, "obj-25", "bach.score", "end_preset" ]
						}
 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-27",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 488.0, 166.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-35",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 702.0, 375.889557, 54.0, 24.0 ],
					"style" : "",
					"text" : "STOP",
					"textcolor" : [ 0.85098, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-34",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 566.0, 164.0, 273.0, 20.0 ],
					"style" : "",
					"text" : "<< The score will play while algorithm is running!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "int" ],
					"patching_rect" : [ 782.0, 287.0, 97.0, 22.0 ],
					"style" : "",
					"text" : "bach.ezmidiplay"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 526.0, 166.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "play"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "FG" ],
					"constraintbeamsinspaces" : 0,
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"keys" : [ "GM" ],
					"legend" : 1,
					"loop" : [ "(", 1, 1, 0, ")", "(", 1, 14, "3/4", ")" ],
					"maxclass" : "bach.score",
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 1,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 526.0, 190.0, 312.0, 101.333333 ],
					"pitcheditrange" : [ "null" ],
					"showloop" : 1,
					"stafflines" : [ 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7900,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ 0.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 2, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 3, 4, ")", "(", "(", "1/4", 100, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 68, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 66, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 73, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 61, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 80, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 83, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 88, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 77, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085533184, 77, 0, "(", "graphic", 5000, "1/2", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 72, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 79, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 78, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 84, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 86, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 86, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 83, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 67, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 74, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 75, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 74, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 72, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 72, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 76, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 2, ")", "(", "3/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 74, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 81, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 70, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 69, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 68, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 70, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 82, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 74, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 80, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 73, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 84, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 69, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, 75, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 1, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 72, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 1, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, 77, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 84, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 82, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 83, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 73, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 85, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 84, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 8, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 1, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 81, 0, 0, ")", 0, ")", "(", "1/8", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 76, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 69, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 66, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 78, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 70, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 8, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, 71, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, 65, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 75, 0, 0, ")", 0, ")", ")", 0, ")", "(", "(", "(", 3, 4, ")", "(", ")", ")", "(", "leveltype", 1, ")", "(", "3/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, 80, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 79, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 73, 0, 0, ")", 0, ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-91",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 504.0, 93.0, 72.0, 22.0 ],
					"style" : "",
					"text" : "loadmess 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-90",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 2,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 34.0, 79.0, 519.0, 267.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 138.0, 151.0, 351.0, 22.0 ],
									"style" : "",
									"text" : "bach.expr mod($x2 - $x1\\, 1200) != mod($x4 - $x3\\, 1200) @out t"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-93",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 138.0, 124.0, 351.0, 22.0 ],
									"style" : "",
									"text" : "bach.pick 1 2 3 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 50.0, 100.0, 195.0, 22.0 ],
									"style" : "",
									"text" : "bach.keys diff intdiff"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 50.0, 151.0, 81.0, 22.0 ],
									"style" : "",
									"text" : "bach.!="
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 50.0, 124.0, 81.0, 22.0 ],
									"style" : "",
									"text" : "bach.pick 1 2"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-33",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-34",
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 89.0, 231.0, 25.0, 25.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-35", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-93", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-30", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-33", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-35", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-34", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-34", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 3 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-93", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-93", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-93", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-93", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 245.0, 287.0, 159.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p \"Handle Constraint Rules\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-89",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 137.0, 344.0, 297.0, 60.0 ],
					"style" : "",
					"text" : "Middle outlet shows the percentage of all possibilities which have already been explored (0 to 100). In our case, once a solution has been found, the research is stopped, so this number will probably be very small."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"format" : 6,
					"id" : "obj-87",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 150.0, 323.0, 72.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-82",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 451.0, 378.0, 410.0, 87.0 ],
					"style" : "",
					"text" : "Before doing stuff like that, you always have to               the research first.\nOtherwise, you'll surely get a hang, and you'll be forced to quit Max.\nWe know this is something on the edge of allowed Max stuff, yet it is very handy and very powerful. That's why we give you this possibility, but we also clearly warn you about possible side effects. If you don't change the lambda loop or close the patch while running, you are safe."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-80",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 452.0, 354.889557, 47.0, 24.0 ],
					"style" : "",
					"text" : "Don't",
					"textcolor" : [ 0.85098, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-81",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 494.0, 358.0, 344.0, 20.0 ],
					"style" : "",
					"text" : "close the patch or quit Max while [bach.constraints] is running. "
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-79",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 204.0, 237.0, 185.0, 33.0 ],
					"style" : "",
					"text" : "With @parallel 1 you can comfortably stop at any moment"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 22.864952,
					"id" : "obj-77",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 150.0, 237.727264, 54.0, 34.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-76",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 452.0, 335.889557, 47.0, 24.0 ],
					"style" : "",
					"text" : "Don't",
					"textcolor" : [ 0.85098, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-70",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 403.0, 92.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-65",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 527.0, 85.0, 326.0, 74.0 ],
					"style" : "",
					"text" : "When @parallel is 1, [bach.constraints] runs in its own thread, essentially without affecting Max's main thread and scheduler thread. This means that you can perform your search \"in background\" and at the same time play a [bach.roll] or a [bach.score]"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.867, 0.867, 0.867, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.79,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.867, 0.867, 0.867, 1.0 ],
					"bgfillcolor_color2" : [ 0.685, 0.685, 0.685, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"fontname" : "Arial",
					"fontsize" : 22.864952,
					"gradient" : 0,
					"id" : "obj-62",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 403.0, 115.727264, 116.0, 34.0 ],
					"style" : "",
					"text" : "parallel $1",
					"textcolor" : [ 0.8, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 49.0, 98.0, 88.0, 20.0 ],
					"style" : "",
					"text" : "<< bang to go!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-68",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 23.0, 327.0, 107.0, 22.0 ],
					"style" : "",
					"text" : "bach.print Found?"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-67",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 494.0, 339.0, 333.0, 20.0 ],
					"style" : "",
					"text" : "change the lambda loop while [bach.constraints] is running. "
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 19.545645,
					"id" : "obj-54",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 452.0, 308.889557, 431.0, 28.0 ],
					"style" : "",
					"text" : "What you MUST NOT do if you use @parallel 1",
					"textcolor" : [ 0.85098, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 232.0, 85.0, 79.0, 22.0 ],
					"style" : "",
					"text" : "loadmess 12"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 27.0, 188.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-59",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 2,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 121.0, 111.0, 640.0, 480.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 166.0, 77.0, 22.0 ],
									"style" : "",
									"text" : "bach.rev 2 2"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 143.0, 145.0, 22.0 ],
									"style" : "",
									"text" : "bach.group 2 @overlap 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-86",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 275.0, 116.0, 22.0 ],
									"style" : "",
									"text" : "bach.prepend intdiff"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 217.0, 66.0, 22.0 ],
									"style" : "",
									"text" : "bach.flat 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-53",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 193.0, 79.0, 22.0 ],
									"style" : "",
									"text" : "bach.comb 2"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-60",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 201.0, 242.0, 84.0, 22.0 ],
									"style" : "",
									"text" : "bach.flat -1 -1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 313.0, 155.0, 22.0 ],
									"style" : "",
									"text" : "bach.join @inwrap 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-73",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 284.0, 103.0, 22.0 ],
									"style" : "",
									"text" : "bach.prepend diff"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-72",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 159.0, 66.0, 22.0 ],
									"style" : "",
									"text" : "bach.flat 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-71",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 134.0, 79.0, 22.0 ],
									"style" : "",
									"text" : "bach.comb 2"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-68",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 100.0, 117.0, 22.0 ],
									"style" : "",
									"text" : "bach.arithmser 1 12"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-48",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-51",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.666664, 40.0, 25.0, 25.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-58",
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 367.5, 25.0, 25.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-53", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-68", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-48", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-68", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-51", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-60", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-52", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 210.5, 212.0 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-86", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-71", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-72", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-71", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-73", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-72", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-73", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-86", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 27.0, 213.0, 224.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p \"Define Constraints Name And Scope\""
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-256",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 376.0, 496.0, 371.0, 20.0 ],
					"style" : "",
					"text" : "Love the background music, I'll write a suite of background musics.",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 49.0, 434.0, 91.0, 22.0 ],
					"style" : "",
					"text" : "loadmess clear"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-106",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 206.0, 109.0, 31.0, 20.0 ],
					"style" : "",
					"text" : "n = "
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-102",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 232.0, 109.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-96",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "", "clear" ],
					"patching_rect" : [ 9.0, 378.0, 59.0, 22.0 ],
					"style" : "",
					"text" : "t b l clear"
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 10.0,
					"embed" : 0,
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-98",
					"legend" : 0,
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 9.0, 408.0, 336.0, 73.0 ],
					"pitcheditrange" : [ "null" ],
					"showdurations" : 0,
					"stafflines" : [ 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7900,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ -14.0, 17.0 ],
					"zoom" : 26.171875
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 9.0, 89.0, 37.0, 37.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 9.0, 163.0, 178.0, 22.0 ],
					"style" : "",
					"text" : "bach.repeat 12 @inwrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 4,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 9.0, 136.0, 173.0, 22.0 ],
					"style" : "",
					"text" : "bach.arithmser 6000 7100 100"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-23",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "", "float", "" ],
					"patching_rect" : [ 9.0, 280.0, 213.0, 35.0 ],
					"style" : "",
					"text" : "bach.constraints @random 1 @solutions 1 @parallel 1 @maxtime 0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-16",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 36.0, 868.0, 47.0 ],
					"style" : "",
					"text" : "Having [bach.constraints] run in the scheduler thread can be a solution to allow aborting. Yet if you need to use the scheduler thread in the meantime (e.g. for sequencing events), this can be a total mess. There is another way to deal with it, but it is a dangerous although powerful way, beyond the edge of the legalit (use it at your own risk!): You can have [bach.constraints] run in a completely different thread, its own thread. This allows you to continue working in parallel."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 244.0, 507.0, 81.0, 22.0 ],
					"style" : "",
					"text" : "clean, wclose",
					"varname" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 243.5, 562.0, 289.0, 22.0 ],
					"style" : "",
					"text" : "linksections 1 1 h \"God Solve The Queens \""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 243.5, 534.5, 69.0, 22.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"style" : "",
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-49",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 16.0, 444.0, 20.0 ],
					"style" : "",
					"text" : "_________________________________________________________________"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"id" : "obj-50",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 277.0, 6.74086, 484.0, 25.0 ],
					"style" : "",
					"text" : "- separate threads (fasten your seat belt)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 22.256727,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 1.924051, 287.0, 31.0 ],
					"style" : "",
					"text" : "God Solve The Queens (h)"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 621.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 596.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 571.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 546.0, 152.0, 22.0 ],
					"style" : "",
					"text" : "God Solve The Queens (g)",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 521.0, 40.0, 22.0 ],
					"style" : "",
					"text" : "t b b",
					"varname" : "triggerA"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.75, 0.75, 0.75, 1.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontface" : 2,
					"id" : "obj-8",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 496.0, 151.0, 20.0 ],
					"style" : "",
					"text" : "Back to section (g)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 744.0, 621.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 744.0, 596.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 744.0, 571.0, 140.0, 22.0 ],
					"style" : "",
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 744.0, 546.0, 148.0, 22.0 ],
					"style" : "",
					"text" : "God Solve The Queens (i)",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 744.0, 521.0, 40.0, 22.0 ],
					"style" : "",
					"text" : "t b b",
					"varname" : "triggerB"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.75, 0.75, 0.75, 1.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontface" : 2,
					"id" : "obj-20",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 744.0, 496.0, 151.0, 20.0 ],
					"style" : "",
					"text" : "Continue to section (i)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-17", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.070588, 0.615686, 0.235294, 0.243137 ],
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-68", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 448.5, 224.0, 502.5, 224.0, 502.5, 188.0, 535.5, 188.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-33", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 253.0, 588.0, 237.0, 588.0, 237.0, 529.5, 253.0, 529.5 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 456.5, 273.0, 523.5, 273.0, 523.5, 188.0, 535.5, 188.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.835294, 0.0, 0.0, 1.0 ],
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.070588, 0.615686, 0.235294, 0.243137 ],
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.835294, 0.0, 0.0, 1.0 ],
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-90", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-70", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-96", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 38.5, 403.5, 145.3, 403.5 ],
					"source" : [ "obj-96", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-96", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "linksections.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/docs/tutorial-patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.repeat.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.prepend.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.ezmidiplay.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.unpacknote.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filter.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.gcd.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.mcapprox.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.constraints.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.arithmser.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.comb.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.group.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.rev.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.is.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.geq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
