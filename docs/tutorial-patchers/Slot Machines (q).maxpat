{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 98.0, 44.0, 805.0, 474.0 ],
		"bglocked" : 0,
		"defrect" : [ 98.0, 44.0, 805.0, 474.0 ],
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
					"maxclass" : "number",
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"patching_rect" : [ 637.0, 376.0, 50.0, 20.0 ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "bgslotfontsize $1",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.0, 399.0, 101.0, 18.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We've added a 5th slots for some remarks, but the font is unreadable... You can increase it:",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 635.0, 309.0, 150.0, 62.0 ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If you need, you can define a general minimum width for slot windows (only for non-temporal slots)",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 438.0, 224.0, 166.0, 62.0 ],
					"id" : "obj-53",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "slotminimumwindowwidth 300",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 590.0, 257.0, 169.0, 18.0 ],
					"id" : "obj-52",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "dial",
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 677.0, 155.0, 34.0, 34.0 ],
					"id" : "obj-51",
					"size" : 101.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Once you have done this, the slots 1 2 and 3 appear (with their names!) in the context menu",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 46.0, 246.0, 258.0, 34.0 ],
					"id" : "obj-50",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "popupmenuslots 1 2 3",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 131.0, 222.0, 129.0, 18.0 ],
					"id" : "obj-47",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "But yet, also in the default contex menu that you find by right-clicking, there's an entry labelled \"Slots\", but unfortunately it's by default greyed! Why? Well, because we let you define which slots you want to be displayed in that tab; you can do it like this:",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 32.0, 159.0, 365.0, 62.0 ],
					"id" : "obj-46",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "There are also a few parameters you can customize, to find more at ease with the slot windows:",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 439.0, 117.0, 305.0, 34.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Right-click will show the usual context menu (default situation)",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 108.0, 125.0, 238.0, 34.0 ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "rightclickslot 0",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 22.0, 131.0, 86.0, 18.0 ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Right-click will make 1st slot pop out. ",
					"numoutlets" : 0,
					"patching_rect" : [ 92.0, 106.0, 319.0, 20.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If you want to work with notes behind the slot window, it might be useful that it be more transparent than it is. You can handle this via the \"slotwinalpha\" attribute:",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 438.0, 150.0, 234.0, 62.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "slotwinalpha $1",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 677.0, 192.0, 93.0, 18.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ -669.0, 101.0, 60.0, 20.0 ],
					"id" : "obj-62",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "roll [ slotinfo [ 1 [ name amplienv ] [ type function ] [ key a ] [ range -120. 10. ] [ slope -0.5 ] [ representation dB ] [ ysnap [ ] ] [ domain 0. 1. ] [ domainslope 0. ] [ width temporal ] ] [ 2 [ name filetoplay ] [ type filelist ] [ key s ) ( width 150. ) ) ( 3 ( name loop ) ( type int ) ( key l ) ( range 0. 1. ) ( slope 0. ) ( representation ( \"Loop On\" \"Loop Off\" ) ) ( width 100. ) ) ( 4 ( name \"slot floatlist\" ) ( type floatlist ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 5 ( name remarks ) ( type text ) ( key r ) ( width 100. ) ) ( 6 ( name \"slot float\" ) ( type float ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 7 ( name \"slot text\" ) ( type text ) ( key 0 ) ( width 100. ) ) ( 8 ( name filelist ) ( type filelist ) ( key 0 ) ( width 150. ) ) ( 9 ( name spat ) ( type spat ) ( key 0 ) ( range 0. 10. ) ( slope 0. ) ( representation ) ( width temporal ) ) ( 10 ( name \"slot 10\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 11 ( name \"slot 11\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 12 ( name \"slot 12\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 13 ( name \"slot 13\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 14 ( name \"slot 14\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 15 ( name \"slot 15\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 16 ( name \"slot 16\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 17 ( name \"slot 17\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 18 ( name \"slot 18\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 19 ( name \"slot 19\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 20 ( name \"slot 20\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 21 ( name \"slot 21\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 22 ( name \"slot 22\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 23 ( name \"slot 23\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 24 ( name \"slot 24\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 25 ( name \"slot 25\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 26 ( name \"slot 26\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 27 ( name \"slot 27\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 28 ( name \"slot 28\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 29 ( name \"slot 29\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 30 ( name \"slot 30\" ) ( type none ) ( key 0 ) ( width 100. ) ) ) ( commands ( 1 notecmd chordcmd 0 ) ( 2 notecmd chordcmd 0 ) ( 3 notecmd chordcmd 0 ) ( 4 notecmd chordcmd 0 ) ( 5 notecmd chordcmd 0 ) ) ( clefs FG ) ( keys CM ) ( voicenames <none> ) ( markers ) ( midichannels 1 ) ( ( 86.666626 ( 6900. 5881. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.115888 -0.315882 0. ) ( 0.5 0. 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 2042.380249 ( 5700. 3725. 89 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7240.285156 ( 7000. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 7981.191406 ( 7900. 2620. 89 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 9427.703125 ( 7000. 2620. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.189463 -4.8 0. ) ( 0.307885 -7.771267 0. ) ( 0.360517 -2.050955 0. ) ( 0.557885 -48.028564 0. ) ( 0.623675 -8.292564 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 10133.3125 ( 6700. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 10874.210938 ( 7600. 2620. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.189463 -4.8 0. ) ( 0.307885 -7.771267 0. ) ( 0.360517 -2.050955 0. ) ( 0.557885 -48.028564 0. ) ( 0.623675 -8.292564 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 13745.332031 ( 7000. 3697. 127 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ) 0 ) 0 ) ( 15694.269531 ( 6000. 1151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 17140.78125 ( 4500. 5151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 17986.796875 ( 7100. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 18587.289062 ( 5700. 1151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) 0 )",
					"linecount" : 61,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -668.0, 135.0, 624.0, 846.0 ],
					"id" : "obj-60",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "rightclickslot 1",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 105.0, 86.0, 18.0 ],
					"id" : "obj-56",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"numoutlets" : 8,
					"bgslots" : [  ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 137.833328 ],
					"automessage" : [  ],
					"preventedit" : [  ],
					"zoom" : 20.0,
					"clefs" : [ "FG" ],
					"voicenames" : "<none>",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"stafflines" : 5,
					"loop" : "null",
					"patching_rect" : [ 6.0, 294.0, 625.0, 137.833328 ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7000,
					"out" : "nnnnnnn",
					"numvoices" : 1,
					"slotminimumwindowwidth" : 300.0,
					"velocityhandling" : 1,
					"numinlets" : 6,
					"voicespacing" : [ -5.142858, -2.714287 ],
					"fontsize" : 12.0,
					"backgroundslots" : [  ],
					"popupmenuslots" : [ 1, 2, 3 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplienv", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", "(", "Loop On", "Loop Off", ")", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "remarks", ")", "(", "type", "text", ")", "(", "key", "r", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1076611223, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084221829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085086208, 89, "(", "slots", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086081097, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072529989, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071234936, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1078872045, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072435759, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072889410, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086270769, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086482906, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072483533, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071704633, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1073715109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069022296, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071606325, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086573224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072529989, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071234936, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1078872045, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072435759, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072889410, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086668059, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072483533, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071704633, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1073715109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1069022296, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071606325, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087035562, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085071872, 127, "(", "slots", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087285026, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074178422, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071935652, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072649857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071594525, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074684541, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087421746, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085546240, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074178422, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071935652, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072649857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071594525, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074684541, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087475891, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072529989, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071234936, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1078872045, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072435759, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071415070, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072889410, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087514322, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074178422, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071935652, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1072649857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1071594525, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1074684541, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 210.0, 515.0, 81.0, 18.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 q \"Slot Machines\"",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 210.0, 567.5, 190.0, 20.0 ],
					"id" : "obj-198",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 210.0, 540.0, 69.0, 20.0 ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "I want to precisely define an horizontal segment of function while dragging points. What can I do?",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 349.0, 439.0, 296.0, 34.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- some more graphics and interface",
					"numoutlets" : 0,
					"patching_rect" : [ 184.0, 7.74086, 371.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"numinlets" : 1,
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (q)",
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 184.0, 32.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We believe that a good interface makes a good software, and thus we're strongly concerned about considering customizable interface possibilities. For instance, if somebody often uses, say, the amplitude slot, he might want to make it pop out more easily than selecting the note and pressing a key. This can be done via right clicking, provided that we tell bach what we want to do:",
					"linecount" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 40.0, 621.0, 62.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 574.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 549.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 524.0, 140.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines [p]",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 499.0, 140.0, 18.0 ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 474.0, 40.0, 20.0 ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"text" : "Back to section (p)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"patching_rect" : [ 5.0, 449.0, 151.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 574.0, 140.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 549.0, 140.0, 20.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 524.0, 140.0, 20.0 ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines [r]",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 499.0, 140.0, 18.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"numinlets" : 2,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 650.0, 474.0, 40.0, 20.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"numinlets" : 1,
					"hidden" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"text" : "Continue to section (r)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"patching_rect" : [ 650.0, 449.0, 151.0, 20.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0
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
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 686.5, 221.0, 418.0, 221.0, 418.0, 289.0, 15.5, 289.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 599.5, 289.5, 15.5, 289.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-51", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 140.5, 243.5, 15.5, 243.5 ]
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
					"midpoints" : [ 219.5, 593.5, 201.5, 593.5, 201.5, 535.0, 219.5, 535.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-56", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-60", 0 ],
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
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 646.5, 423.0, 633.0, 423.0, 633.0, 289.0, 15.5, 289.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
