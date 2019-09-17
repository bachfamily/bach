{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 221.0, 44.0, 900.0, 652.0 ],
		"bglocked" : 0,
		"defrect" : [ 221.0, 44.0, 900.0, 652.0 ],
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
					"text" : "The [clip] is needed, since\nunfortunately Max does not support objects bigger than 32767 pixels...",
					"linecount" : 4,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 336.0, 469.0, 151.0, 62.0 ],
					"id" : "obj-35",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "clip 0 32767",
					"fontsize" : 12.0,
					"numinlets" : 3,
					"numoutlets" : 1,
					"patching_rect" : [ 483.0, 474.0, 75.0, 20.0 ],
					"id" : "obj-26",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess set 0",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 483.0, 351.0, 91.0, 20.0 ],
					"id" : "obj-29",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "bach objects send a \"domain\" notifications when domain changes through the playout. It sends a \"domain X Y\" message, where X and Y are the starting and ending ms of the current window.\nWe intercept this notification, and ask to have the same values in pixels (\"getdomainpixels\").\nThe \"length\" is asked only when a roll is loaded/read/updated, or when it is changed via the interface (dragging the scrollbar doesn't change the global length!)",
					"linecount" : 14,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 281.0, 204.0, 200.0 ],
					"id" : "obj-82",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Let's apply in practice our previous formulas:",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 8.0, 40.0, 248.0, 20.0 ],
					"id" : "obj-81",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "when \"done\" is sent (end loading/reading/ updating), we get domains and length anew",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 585.0, 318.0, 241.0, 34.0 ],
					"id" : "obj-80",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Try to zoom in/out (Cmd+Scroll) on the roll and drag its scrollbar to see how the function reacts accordingly. ",
					"linecount" : 3,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 650.0, 473.0, 232.0, 48.0 ],
					"id" : "obj-78",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The offset is updated when the domain changes",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 48.0, 506.0, 168.0, 34.0 ],
					"id" : "obj-76",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "offsets are negative",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 87.0, 485.0, 121.0, 20.0 ],
					"id" : "obj-75",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* -1.",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 485.0, 33.0, 20.0 ],
					"id" : "obj-73",
					"outlettype" : [ "float" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t f f",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 469.0, 435.0, 32.5, 20.0 ],
					"id" : "obj-72",
					"outlettype" : [ "float", "float" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t f f",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 455.0, 306.0, 32.5, 20.0 ],
					"id" : "obj-71",
					"outlettype" : [ "float", "float" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "$1",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 396.0, 32.5, 18.0 ],
					"id" : "obj-70",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 731.0, 278.0, 20.0, 20.0 ],
					"id" : "obj-68",
					"outlettype" : [ "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "when something changes, we get domains and length anew",
					"linecount" : 6,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 752.0, 209.0, 93.0, 89.0 ],
					"id" : "obj-66",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b f",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 500.0, 387.0, 32.5, 20.0 ],
					"id" : "obj-64",
					"outlettype" : [ "bang", "float" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "getdomainpixels",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 237.0, 329.0, 97.0, 18.0 ],
					"id" : "obj-63",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t l l b",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 3,
					"patching_rect" : [ 210.0, 305.0, 46.0, 20.0 ],
					"id" : "obj-60",
					"outlettype" : [ "", "", "bang" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr $f1 * $f3 / $f2",
					"fontsize" : 12.0,
					"numinlets" : 3,
					"numoutlets" : 1,
					"patching_rect" : [ 469.0, 411.0, 109.0, 20.0 ],
					"id" : "obj-51",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "getdomainpixels, getdomain, getlength",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 577.0, 359.0, 216.0, 18.0 ],
					"id" : "obj-50",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr $f2 - $f1",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 224.0, 362.0, 81.0, 20.0 ],
					"id" : "obj-46",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr $f2 - $f1",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 332.0, 354.0, 81.0, 20.0 ],
					"id" : "obj-41",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr ($f1 / $f2) * $f3",
					"fontsize" : 12.0,
					"numinlets" : 3,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 461.0, 117.0, 20.0 ],
					"id" : "obj-40",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys domain domainpixels length done @out t",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 5,
					"patching_rect" : [ 210.0, 280.0, 508.0, 20.0 ],
					"id" : "obj-39",
					"outlettype" : [ "", "", "", "", "bang" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"automessage" : [  ],
					"fontsize" : 12.0,
					"midichannels" : [ 1, 2, 3, 4 ],
					"zoom" : 26.74712,
					"hidevoices" : [ 0, 0, 0, 0 ],
					"numinlets" : 6,
					"keys" : [ "CM", "CM", "CM", "CM" ],
					"bgslots" : [  ],
					"numoutlets" : 8,
					"clefs" : [ "G", "G", "Alto", "F" ],
					"vzoom" : 66.666664,
					"voicespacing" : [ 0.0, 17.0, 17.0, 17.0, 17.0 ],
					"patching_rect" : [ 7.0, 76.0, 743.0, 188.333328 ],
					"id" : "obj-38",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"fontname" : "Arial",
					"versionnumber" : 6500,
					"stafflines" : [ 5, 5, 5, 5 ],
					"popupmenuslots" : [  ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"voicenames" : [ "<none>", "<none>", "<none>", "<none>" ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, 4, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 54866, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4572, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083702152, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4572, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084130804, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084250635, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084393519, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084536403, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4592, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084607845, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084679287, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4568, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084822170, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4592, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4568, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085036496, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085107938, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4568, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085250822, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4592, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085370653, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085406374, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4592, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085477816, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584979, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085620700, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 62496, 1081319233, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085701072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 47232, 1080556424, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 1760, 1080883016, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085809510, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 28080, 1081203565, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085882653, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 6096, 1081557373, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086085072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086120793, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086156514, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4568, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086299398, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086329927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086419229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086437090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086454950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086526392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086544253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086562113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086740718, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086776439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086847880, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086883601, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086955043, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086972904, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086990764, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 54880, 1082510693, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087637480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087646410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087664270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087673201, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087691061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087699991, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087717852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087726782, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087744643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087771433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087798224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087825015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087851805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087878596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087905387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087932177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 62480, 1083416385, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088048270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 62480, 1083416385, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088155433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 62480, 1083416385, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088262596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, "_x_x_x_x_bach_float64_x_x_x_x_", 62480, 1083416385, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402560, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086415360, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086428160, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325760, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 39808, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088556567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 18272, 1085727863, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088744102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088770893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088779823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088784288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088793219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088797684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088806614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088811079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088815544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088820009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088833405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088837870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088846800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088860195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088886986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088900381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 64000, 1081290656, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088914670, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 45824, 1080585001, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 30208, 1080870769, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088928288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 22144, 1081196761, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088937378, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 768, 1081513147, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088957870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 54784, 1082510693, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089091823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089096288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089145405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089149870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089198986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089203451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089239172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608 ],
					"whole_roll_data_0000000001" : [ 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089243637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089265963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089270428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089292753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089297219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089332939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089337405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089359730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089364195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4736, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089440102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089444567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4736, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089453498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089466893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376960, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364160, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089508864, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089511097, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089515562, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089522260, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089535655, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089537888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089542353, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089544585, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089549050, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325760, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089555748, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089557981, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325760, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089562446, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089569143, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089571376, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 38912, 1081329439, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089576439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 34304, 1080617660, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 23680, 1082133071, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089587841, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 41984, 1081523353, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089593662, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 61024, 1085107938, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39626, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39624, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 13712, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 50296, 1082903623, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086013630, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086049351, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086227956, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086263677, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086299398, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086329927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086383508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 33, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 38, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086490671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 39, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 40, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086597834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 24384, 1083082228, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086740718, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086758578, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086776439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086847880, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086865741, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086883601, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086955043, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086972904, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086990764, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087080067, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087133648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087151508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087187229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087240811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087294392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087347974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087387433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087414224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087441015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087467805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087476736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087494596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087521387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087548177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087574968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087601759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087619619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 41152, 1084250635, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 54880, 1082510693, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087958968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087967898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087985759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087994689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088012550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088039340, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088066131, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088075061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088092922, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088101852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088119712, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088146503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088173294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088200084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088209015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088226875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088253666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088280456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088307247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088316177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088334038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088360829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088387619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088414410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088458335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088471730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 62432, 1083416385, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088556567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088569963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 62472, 1085513537, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088730707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088757498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088761963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088784288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088788753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088793219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088797684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39808, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088837870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088842335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088846800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 44176, 1084884682, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088953405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088957870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088966800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338560, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089091823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089096288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089145405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089149870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089198986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089203451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 54784, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_" ],
					"whole_roll_data_0000000002" : [ 4608, 1080127773, 92, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4736, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089466893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089470911, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089475376, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089522260, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089524492, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089528957, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089531190, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089535655, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089537888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 55040, 1082510693, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089562446, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 31488, 1082995477, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 29568, 1083163875, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089595894, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089598127, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089600359, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 5120, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089602592, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089604824, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089613755, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089615987, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089618220, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089627150, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089629383, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089631615, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39626, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39626, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085406374, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39632, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 13712, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 50296, 1082903623, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086085072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39632, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 54872, 1082510693, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086419229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086454950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1081176349, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086526392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086544253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086562113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086704997, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086812160, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 62, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086919322, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 64, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087026485, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087080067, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087133648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087151508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087187229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087240811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087294392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087347974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087387433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087414224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087441015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087467805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087476736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087494596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087521387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087548177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087574968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087601759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1084322077, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 39584, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087825015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 39648, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087994689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 62464, 1083416385, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088101852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088119712, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088146503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088173294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088200084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088209015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088226875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088253666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088280456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088307247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088316177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088334038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088360829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1081176349, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088387619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088431544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088444939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39808, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 10656, 1084822170, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088645870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088650335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088659265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 47248, 1084750728, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088757498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088761963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088770893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088775358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088779823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1084322077, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088855730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088860195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 21376, 1082090805, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 51776, 1082875046, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088966800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1083273501, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1083273501, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 54784, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4736, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 41152, 1084250635, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 31488, 1082995477, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 32256, 1083457209, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089600359, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089607057, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089618220, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089620452, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089624917, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089627150, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089631615, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 4608 ],
					"whole_roll_data_0000000003" : [ 1080127773, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39627, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39626, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39628, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39624, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 13712, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 12192, 1083898618, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086227956, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086263677, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086383508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 33, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086490671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086597834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086704997, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086812160, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4576, 1082224925, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4544, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086919322, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4560, 1082224925, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087026485, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087619619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087646410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087673201, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087699991, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087726782, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085328384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087967898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088048270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088075061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088155433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088262596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088565498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088569963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088578893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088592288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088596753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088605684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088619079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088623544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088632474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088659265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088663730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088672660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 32000, 1083987920, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088730707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088744102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 62480, 1084464961, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088828939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088833405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088900381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 21376, 1082090805, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 18624, 1082135113, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088937378, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, "_x_x_x_x_bach_float64_x_x_x_x_", 768, 1081513147, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 4480, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 54784, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085405184, "_x_x_x_x_bach_float64_x_x_x_x_", 54784, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085124608, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085073408, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089332939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089337405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 54848, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089359730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089364195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 54912, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4736, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 39552, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 39616, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39424, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4864, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 39744, 1083845036, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089531190, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 62464, 1083416385, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 39680, 1082796460, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 31488, 1082995477, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 29568, 1083163875, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089595894, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 4096, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089598127, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089607057, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 5120, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089609290, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089611522, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4352, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089620452, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 5120, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089622685, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089624917, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 4608, 1082224925, 45, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 4 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "function_width = pixel_width_of_the_whole_roll's_length = total_length * domain_pixels / domain \nfunction_offset = (domain_start / total_length) * function_width",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 260.0, 40.0, 533.0, 34.0 ],
					"id" : "obj-28",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The width is updated either when the length has changed or when the domain has changed",
					"linecount" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 503.0, 437.0, 282.0, 34.0 ],
					"id" : "obj-21",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "patching_rect 0. 217. $1 63.",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 483.0, 502.0, 159.0, 18.0 ],
					"id" : "obj-30",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "offset $1 -217",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 514.0, 84.0, 18.0 ],
					"id" : "obj-23",
					"outlettype" : [ "" ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bpatcher",
					"numinlets" : 2,
					"args" : [  ],
					"numoutlets" : 0,
					"patching_rect" : [ 31.0, 548.0, 713.0, 64.0 ],
					"offset" : [ 0.0, -217.0 ],
					"id" : "obj-14",
					"name" : "Graphical Synchronization (c) - bpatcher.maxpat"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "0 Hz",
					"fontsize" : 8.913287,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 743.0, 571.5, 40.0, 17.0 ],
					"id" : "obj-20",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "-500 Hz",
					"fontsize" : 8.913287,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 743.0, 599.5, 40.0, 17.0 ],
					"id" : "obj-18",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "500 Hz",
					"fontsize" : 8.913287,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 743.0, 542.5, 40.0, 17.0 ],
					"id" : "obj-17",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 318.0, 632.0, 81.0, 18.0 ],
					"id" : "obj-19",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 c \"Graphical Synchronization\"",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 318.0, 684.5, 254.0, 20.0 ],
					"id" : "obj-198",
					"outlettype" : [ "" ],
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
					"numoutlets" : 2,
					"patching_rect" : [ 318.0, 657.0, 69.0, 20.0 ],
					"id" : "obj-90",
					"outlettype" : [ "", "" ],
					"fontname" : "Arial",
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "What happens at startup, when I load my patch?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 586.0, 618.0, 168.0, 34.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- syncronization in action",
					"fontsize" : 16.787033,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 304.0, 7.74086, 491.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Graphical Synchronization (c)",
					"fontsize" : 22.256727,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 304.0, 32.0 ],
					"id" : "obj-3",
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
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 752.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"outlettype" : [ "" ],
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
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 727.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"outlettype" : [ "" ],
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
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 702.0, 140.0, 20.0 ],
					"id" : "obj-5",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Graphical Synchronization [b]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 677.0, 167.0, 18.0 ],
					"id" : "obj-7",
					"outlettype" : [ "" ],
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
					"numoutlets" : 2,
					"patching_rect" : [ 5.0, 652.0, 40.0, 20.0 ],
					"id" : "obj-8",
					"outlettype" : [ "bang", "bang" ],
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"fontface" : 2,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontsize" : 12.0,
					"text" : "Back to section (b)",
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numoutlets" : 3,
					"patching_rect" : [ 5.0, 627.0, 151.0, 20.0 ],
					"id" : "obj-10",
					"outlettype" : [ "", "", "int" ],
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 745.0, 752.0, 140.0, 20.0 ],
					"id" : "obj-11",
					"outlettype" : [ "" ],
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
					"numoutlets" : 1,
					"patching_rect" : [ 745.0, 727.0, 140.0, 20.0 ],
					"id" : "obj-12",
					"outlettype" : [ "" ],
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
					"numoutlets" : 1,
					"patching_rect" : [ 745.0, 702.0, 140.0, 20.0 ],
					"id" : "obj-13",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Graphical Synchronization [d]",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 745.0, 677.0, 167.0, 18.0 ],
					"id" : "obj-16",
					"outlettype" : [ "" ],
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
					"numoutlets" : 2,
					"patching_rect" : [ 745.0, 652.0, 40.0, 20.0 ],
					"id" : "obj-22",
					"outlettype" : [ "bang", "bang" ],
					"fontname" : "Arial",
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"fontface" : 2,
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontsize" : 12.0,
					"text" : "Continue to section (d)",
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numoutlets" : 3,
					"patching_rect" : [ 745.0, 627.0, 151.0, 20.0 ],
					"id" : "obj-25",
					"outlettype" : [ "", "", "int" ],
					"fontname" : "Arial",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
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
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 1 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-22", 0 ],
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
					"source" : [ "obj-73", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-73", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-72", 1 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
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
					"midpoints" : [ 327.5, 710.5, 309.5, 710.5, 309.5, 652.0, 327.5, 652.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-71", 0 ],
					"destination" : [ "obj-40", 1 ],
					"hidden" : 0,
					"midpoints" : [ 464.5, 418.5, 268.5, 418.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-72", 0 ],
					"destination" : [ "obj-40", 2 ],
					"hidden" : 0,
					"midpoints" : [ 478.5, 455.0, 317.5, 455.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-51", 0 ],
					"destination" : [ "obj-72", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-71", 1 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 2 ],
					"destination" : [ "obj-71", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-70", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-70", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 1 ],
					"destination" : [ "obj-46", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 2 ],
					"destination" : [ "obj-63", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-68", 0 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [ 740.5, 317.0, 586.5, 317.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-46", 0 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [ 233.5, 384.0, 509.5, 384.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 1 ],
					"destination" : [ "obj-51", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-63", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 0.431373 ],
					"midpoints" : [ 246.5, 428.0, 832.5, 428.0, 832.5, 73.0, 16.5, 73.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-51", 2 ],
					"hidden" : 0,
					"midpoints" : [ 341.5, 379.0, 568.5, 379.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-50", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 0.431373 ],
					"midpoints" : [ 586.5, 428.0, 832.0, 428.0, 832.0, 73.0, 16.5, 73.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 3 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 1 ],
					"destination" : [ "obj-41", 0 ],
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
					"source" : [ "obj-38", 7 ],
					"destination" : [ "obj-68", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 6 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-60", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-14", 1 ],
					"hidden" : 0,
					"midpoints" : [ 492.5, 536.0, 734.5, 536.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [ 219.5, 540.0, 40.5, 540.0 ]
				}

			}
 ]
	}

}
