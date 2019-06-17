{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 5,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 98.0, 79.0, 805.0, 474.0 ],
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
					"id" : "obj-34",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 637.0, 376.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.0, 399.0, 101.0, 22.0 ],
					"text" : "bgslotfontsize $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 635.0, 309.0, 150.0, 60.0 ],
					"text" : "We've added a 5th slots for some remarks, but the font is unreadable... You can increase it:"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-53",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 438.0, 224.0, 166.0, 60.0 ],
					"text" : "If you need, you can define a general minimum width for slot windows (only for non-temporal slots)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-52",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 590.0, 257.0, 169.0, 22.0 ],
					"text" : "slotminimumwindowwidth 300"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 677.0, 155.0, 34.0, 34.0 ],
					"size" : 101.0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-50",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 46.0, 246.0, 258.0, 33.0 ],
					"text" : "Once you have done this, the slots 1 2 and 3 appear (with their names!) in the context menu"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-47",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 131.0, 222.0, 129.0, 22.0 ],
					"text" : "popupmenuslots 1 2 3"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-46",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 32.0, 159.0, 365.0, 60.0 ],
					"text" : "But yet, also in the default contex menu that you find by right-clicking, there's an entry labelled \"Slots\", but unfortunately it's by default greyed! Why? Well, because we let you define which slots you want to be displayed in that tab; you can do it like this:"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 439.0, 117.0, 305.0, 33.0 ],
					"text" : "There are also a few parameters you can customize, to find more at ease with the slot windows:"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-24",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 108.0, 125.0, 238.0, 33.0 ],
					"text" : "Right-click will show the usual context menu (default situation)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 22.0, 131.0, 86.0, 22.0 ],
					"text" : "rightclickslot 0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 92.0, 106.0, 319.0, 20.0 ],
					"text" : "Right-click will make 1st slot pop out. "
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-32",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 438.0, 150.0, 234.0, 60.0 ],
					"text" : "If you want to work with notes behind the slot window, it might be useful that it be more transparent than it is. You can handle this via the \"slotwinalpha\" attribute:"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 677.0, 192.0, 93.0, 22.0 ],
					"text" : "slotwinalpha $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ -669.0, 101.0, 60.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-60",
					"linecount" : 61,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -668.0, 135.0, 627.0, 826.0 ],
					"text" : "roll [ slotinfo [ 1 [ name amplienv ] [ type function ] [ key a ] [ range -120. 10. ] [ slope -0.5 ] [ representation dB ] [ ysnap [ ] ] [ domain 0. 1. ] [ domainslope 0. ] [ width temporal ] ] [ 2 [ name filetoplay ] [ type filelist ] [ key s ) ( width 150. ) ) ( 3 ( name loop ) ( type int ) ( key l ) ( range 0. 1. ) ( slope 0. ) ( representation ( \"Loop On\" \"Loop Off\" ) ) ( width 100. ) ) ( 4 ( name \"slot floatlist\" ) ( type floatlist ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 5 ( name remarks ) ( type text ) ( key r ) ( width 100. ) ) ( 6 ( name \"slot float\" ) ( type float ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 7 ( name \"slot text\" ) ( type text ) ( key 0 ) ( width 100. ) ) ( 8 ( name filelist ) ( type filelist ) ( key 0 ) ( width 150. ) ) ( 9 ( name spat ) ( type spat ) ( key 0 ) ( range 0. 10. ) ( slope 0. ) ( representation ) ( width temporal ) ) ( 10 ( name \"slot 10\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 11 ( name \"slot 11\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 12 ( name \"slot 12\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 13 ( name \"slot 13\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 14 ( name \"slot 14\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 15 ( name \"slot 15\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 16 ( name \"slot 16\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 17 ( name \"slot 17\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 18 ( name \"slot 18\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 19 ( name \"slot 19\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 20 ( name \"slot 20\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 21 ( name \"slot 21\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 22 ( name \"slot 22\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 23 ( name \"slot 23\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 24 ( name \"slot 24\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 25 ( name \"slot 25\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 26 ( name \"slot 26\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 27 ( name \"slot 27\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 28 ( name \"slot 28\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 29 ( name \"slot 29\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 30 ( name \"slot 30\" ) ( type none ) ( key 0 ) ( width 100. ) ) ) ( commands ( 1 notecmd chordcmd 0 ) ( 2 notecmd chordcmd 0 ) ( 3 notecmd chordcmd 0 ) ( 4 notecmd chordcmd 0 ) ( 5 notecmd chordcmd 0 ) ) ( clefs FG ) ( keys CM ) ( voicenames <none> ) ( markers ) ( midichannels 1 ) ( ( 86.666626 ( 6900. 5881. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.115888 -0.315882 0. ) ( 0.5 0. 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 2042.380249 ( 5700. 3725. 89 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7240.285156 ( 7000. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 7981.191406 ( 7900. 2620. 89 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 9427.703125 ( 7000. 2620. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.189463 -4.8 0. ) ( 0.307885 -7.771267 0. ) ( 0.360517 -2.050955 0. ) ( 0.557885 -48.028564 0. ) ( 0.623675 -8.292564 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 10133.3125 ( 6700. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 10874.210938 ( 7600. 2620. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.189463 -4.8 0. ) ( 0.307885 -7.771267 0. ) ( 0.360517 -2.050955 0. ) ( 0.557885 -48.028564 0. ) ( 0.623675 -8.292564 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 13745.332031 ( 7000. 3697. 127 ( slots ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ) 0 ) 0 ) ( 15694.269531 ( 6000. 1151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 17140.78125 ( 4500. 5151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 17986.796875 ( 7100. 1123. 127 ( slots ( 1 ( 0. -120. 0. ) ( 0.073069 -4.622784 0. ) ( 0.192438 -11.126038 0. ) ( 0.218965 -9.751724 0. ) ( 0.265386 -0.069215 0. ) ( 0.265386 -4.982243 0. ) ( 0.378124 -9.751724 0. ) ( 0.490862 -3.625851 0.5 ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 18587.289062 ( 5700. 1151. 89 ( slots ( 1 ( 0. -120. 0. ) ( 0.036366 -1.583628 0. ) ( 0.5 0. 0.5 ) ( 0.536582 -6.89 0. ) ( 0.549746 -4.165527 0. ) ( 0.549746 -8.382591 0. ) ( 0.82618 -1.100955 0. ) ( 1. -120. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) 0 )"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-56",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 105.0, 86.0, 22.0 ],
					"text" : "rightclickslot 1"
				}

			}
, 			{
				"box" : 				{
					"bgslots" : [ 1 ],
					"bwcompatibility" : 80005,
					"clefs" : [ "FG" ],
					"defaultnoteslots" : [ "null" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-27",
					"linkannotationtoslot" : 0,
					"linkarticulationstoslot" : 0,
					"linkdynamicstoslot" : 0,
					"linklyricstoslot" : 7,
					"loop" : [ 0.0, 1000.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 294.0, 625.0, 137.833330833333349 ],
					"pitcheditrange" : [ "null" ],
					"showvelocity" : 1,
					"slotminimumwindowwidth" : 300.0,
					"stafflines" : [ 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80005,
					"voicenames" : [ "<none>" ],
					"voicespacing" : [ -5.142858, -2.714287 ],
					"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplienv", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3219128320, "]", "[", "representation", "dB", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "filetoplay", "]", "[", "type", "filelist", "]", "[", "key", "s", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "loop", "]", "[", "type", "int", "]", "[", "key", "l", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "[", "Loop On", "Loop Off", "]", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "remarks", "]", "[", "type", "text", "]", "[", "key", "r", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 2, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 3, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 4, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 5, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1649267, 1079356074, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 33535105, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 584665308, 3218356073, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610509657, 1084221829, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085086208, 89, "[", "slots", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1086081096, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 381805413, 3222437307, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 226499395, 3223732360, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 23364622, 3216095251, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 468117076, 3222531537, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 726227430, 3222077886, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1086270768, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086482906, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3597052290, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 3222483763, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1232827413, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 70643622, 3223262663, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3844717284, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 408193692, 3221252187, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2763897354, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 4231195622, 3225944999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1175103052, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 4074240337, 3223360970, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086573224, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 381805413, 3222437307, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 226499395, 3223732360, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 23364622, 3216095251, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 468117076, 3222531537, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 726227430, 3222077886, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 274878, 1086668059, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3597052290, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 3222483763, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1232827413, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 70643622, 3223262663, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3844717284, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 408193692, 3221252187, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2763897354, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 4231195622, 3225944999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1175103052, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 4074240337, 3223360970, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2147346209, 1087035562, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085071872, 127, "[", "slots", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2147346209, 1087285026, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 1347451500, 3220788874, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 3223031644, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 3907939203, 3222317439, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 4155604197, 3223372770, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 4252361220, 3220282754, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087421746, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085546240, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 1347451500, 3220788874, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 3223031644, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 3907939203, 3222317439, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 4155604197, 3223372770, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 4252361220, 3220282754, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087475891, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 381805413, 3222437307, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 226499395, 3223732360, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 23364622, 3216095251, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 468117076, 3222531537, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4158078098, 3223552225, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 726227430, 3222077886, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2147346209, 1087514322, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 1347451500, 3220788874, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 3223031644, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 3907939203, 3222317439, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 4155604197, 3223372770, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 4252361220, 3220282754, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3227385856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", 0, "]" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 20.0
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
					"patching_rect" : [ 210.0, 515.0, 81.0, 22.0 ],
					"text" : "clean, wclose",
					"varname" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-198",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 210.0, 567.5, 190.0, 22.0 ],
					"text" : "linksections 1 1 q \"Slot Machines\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-90",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 210.0, 540.0, 69.0, 22.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-61",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 349.0, 439.0, 296.0, 33.0 ],
					"text" : "I want to precisely define an horizontal segment of function while dragging points. What can I do?",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-87",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"text" : "_________________________________________________________________"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033000000001,
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 184.0, 7.74086, 371.0, 25.0 ],
					"text" : "- some more graphics and interface"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 22.256727000000001,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 184.0, 31.0 ],
					"text" : "Slot Machines (q)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-13",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 40.0, 621.0, 60.0 ],
					"text" : "We believe that a good interface makes a good software, and thus we're strongly concerned about considering customizable interface possibilities. For instance, if somebody often uses, say, the amplitude slot, he might want to make it pop out more easily than selecting the note and pressing a key. This can be done via right clicking, provided that we tell bach what we want to do:"
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
					"patching_rect" : [ 5.0, 574.0, 140.0, 22.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 549.0, 140.0, 22.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 524.0, 140.0, 22.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-7",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 499.0, 140.0, 22.0 ],
					"text" : "Slot Machines (p)",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 474.0, 40.0, 22.0 ],
					"text" : "t b b",
					"varname" : "triggerA"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.75, 0.75, 0.75, 1.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"fontface" : 2,
					"id" : "obj-10",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 449.0, 151.0, 20.0 ],
					"text" : "Back to section (p)",
					"varname" : "textbuttonA"
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
					"patching_rect" : [ 650.0, 574.0, 140.0, 22.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 549.0, 140.0, 22.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 524.0, 140.0, 22.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.0, 499.0, 140.0, 22.0 ],
					"text" : "Slot Machines (r)",
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
					"patching_rect" : [ 650.0, 474.0, 40.0, 22.0 ],
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
					"patching_rect" : [ 650.0, 449.0, 151.0, 20.0 ],
					"text" : "Continue to section (r)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"source" : [ "obj-17", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 219.5, 593.5, 201.5, 593.5, 201.5, 535.0, 219.5, 535.0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"hidden" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 686.5, 221.0, 418.0, 221.0, 418.0, 289.0, 15.5, 289.0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 646.5, 423.0, 633.0, 423.0, 633.0, 289.0, 15.5, 289.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 140.5, 243.5, 15.5, 243.5 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 599.5, 289.5, 15.5, 289.5 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"hidden" : 1,
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"hidden" : 1,
					"source" : [ "obj-8", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-198", 0 ],
					"hidden" : 1,
					"source" : [ "obj-90", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "linksections.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/docs/tutorial-patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
