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
		"rect" : [ 34.0, 79.0, 860.0, 529.0 ],
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
					"id" : "obj-63",
					"linecount" : 7,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 299.0, 428.0, 100.0 ],
					"text" : "The clumpsy advice says: you should have considered it before! But yet, if you don't have a lot of notes, or if notes share the same envelopes, you can change an envelope and then copy-paste it to the other notes.\nHow do we copy-paste? Easy! Open the \"source\" slot windows and press Cmd+C (mac) or Ctrl+C (win) - add Shift if you want to copy the content of ALL slots. Then close the window and select the destination notes. Finally, press Cmd+V (mac) or Ctrl+V (win)."
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
					"linecount" : 68,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -668.0, 129.0, 609.0, 920.0 ],
					"text" : "roll [ slotinfo [ 1 [ name amplienv ] [ type function ] [ key a ] [ range -120. 10. ] [ slope -0.5 ] [ representation dB ] [ ysnap [ ] ] [ domain 0. 1. ] [ domainslope 0. ] [ width temporal ] ] [ 2 [ name filetoplay ] [ type filelist ] [ key s ) ( width 150. ) ) ( 3 ( name loop ) ( type int ) ( key l ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 4 ( name \"slot floatlist\" ) ( type floatlist ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 5 ( name \"slot long\" ) ( type int ) ( key 0 ) ( range 0. 127. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 6 ( name \"slot float\" ) ( type float ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 7 ( name \"slot text\" ) ( type text ) ( key 0 ) ( width 100. ) ) ( 8 ( name filelist ) ( type filelist ) ( key 0 ) ( width 150. ) ) ( 9 ( name spat ) ( type spat ) ( key 0 ) ( range 0. 10. ) ( slope 0. ) ( representation ) ( width temporal ) ) ( 10 ( name \"slot 10\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 11 ( name \"slot 11\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 12 ( name \"slot 12\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 13 ( name \"slot 13\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 14 ( name \"slot 14\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 15 ( name \"slot 15\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 16 ( name \"slot 16\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 17 ( name \"slot 17\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 18 ( name \"slot 18\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 19 ( name \"slot 19\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 20 ( name \"slot 20\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 21 ( name \"slot 21\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 22 ( name \"slot 22\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 23 ( name \"slot 23\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 24 ( name \"slot 24\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 25 ( name \"slot 25\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 26 ( name \"slot 26\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 27 ( name \"slot 27\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 28 ( name \"slot 28\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 29 ( name \"slot 29\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 30 ( name \"slot 30\" ) ( type none ) ( key 0 ) ( width 100. ) ) ) ( commands ( 1 notecmd chordcmd 0 ) ( 2 notecmd chordcmd 0 ) ( 3 notecmd chordcmd 0 ) ( 4 notecmd chordcmd 0 ) ( 5 notecmd chordcmd 0 ) ) ( clefs FG ) ( keys CM ) ( voicenames <none> ) ( markers ) ( midichannels 1 ) ( ( 86.666626 ( 6900. 5881. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.115888 0.964286 0. ) ( 0.5 1. 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 1956.666016 ( 7400. 3725. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 4445.332031 ( 6000. 3697. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 6394.269531 ( 5000. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7240.285156 ( 7000. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 7840.78125 ( 4100. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7981.191406 ( 7900. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 8686.796875 ( 6100. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 9287.289062 ( 4700. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 9427.703125 ( 7000. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 10133.3125 ( 6700. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 10874.210938 ( 7600. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) 0 )"
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
					"patching_rect" : [ 6.0, 71.0, 515.0, 22.0 ],
					"text" : "[slotinfo [1 [range -120 10] [representation dB] [temporalmode relative] [width auto] [slope -0.5]]]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 418.0, 396.0, 60.0 ],
					"text" : "Tip: in a function slot you cannot horizontally move a point beyond its neighbour points. This is often handy, but sometimes it could be unwanted: if you keep the Alt key pressed and move the point, you'll be able to move it where you want, deleting neighbours points!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-36",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 575.0, 303.0, 265.0, 22.0 ],
					"saved_object_attributes" : 					{
						"versionnumber" : 80005
					}
,
					"text" : "bach.join 6 @inwrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-31",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 250.0, 427.0, 47.0 ],
					"text" : "But, after the slot conversion... alas! Of course the y values inside the slots (still ranging from 0 to 1) are not correct any more! How do we get them right?\nWell, there is a clumpsy and a clean advice to do this."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"local" : 1,
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 564.0, 429.0, 45.0, 45.0 ],
					"varname" : "autohelp_dac"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"id" : "obj-46",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 523.0, 435.0, 38.0, 32.0 ],
					"text" : "start audio",
					"varname" : "autohelp_dac_text"
				}

			}
, 			{
				"box" : 				{
					"angle" : 0.0,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"border" : 2,
					"bordercolor" : [ 0.392157, 0.792157, 0.117647, 1.0 ],
					"id" : "obj-47",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 516.0, 424.0, 100.0, 55.0 ],
					"varname" : "startwinwdow_panel"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 15.380371999999999,
					"id" : "obj-21",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 439.0, 354.120818999999983, 112.0, 41.0 ],
					"text" : "important stuff\nhas changed"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-40",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 540.0, 362.0, 31.0, 20.0 ],
					"text" : "___"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-41",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 558.0, 368.0, 19.0, 20.0 ],
					"text" : ">"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 568.0, 409.0, 85.0, 22.0 ],
					"text" : "loadmess 128"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 575.0, 340.0, 81.0, 22.0 ],
					"text" : "prepend note"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"interpinlet" : 1,
					"maxclass" : "gain~",
					"multichannelvariant" : 0,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 575.0, 396.0, 126.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.252846000000002,
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 575.0, 366.413788000000011, 254.0, 27.0 ],
					"text" : "poly~ \"Slot Machines (l) - poly\" 10"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-43",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 6,
					"outlettype" : [ "", "", "", "", "", "" ],
					"patching_rect" : [ 575.0, 262.5, 265.0, 22.0 ],
					"saved_object_attributes" : 					{
						"versionnumber" : 80005
					}
,
					"text" : "bach.playkeys cents velocity duration [slot 1 2 3]"
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
					"loop" : [ 0, 1000 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 6.0, 96.0, 724.0, 148.833331499999986 ],
					"pitcheditrange" : [ "null" ],
					"showvelocity" : 1,
					"stafflines" : [ 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80005,
					"voicenames" : [ "<none>" ],
					"voicespacing" : [ -5.142858, 6.714285 ],
					"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplienv", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "filetoplay", "]", "[", "type", "filelist", "]", "[", "key", "s", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "loop", "]", "[", "type", "int", "]", "[", "key", "l", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 2, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 3, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 4, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 5, "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1649267, 1079356074, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 33535105, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 1346351988, 1072618350, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1649267, 1084134058, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085086208, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 4155879075, 1072343721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 1880439761, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2809527087, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2136351093, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 1068175546, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1085365588, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085071872, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 2004684575, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 1617106727, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 3885124337, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 1609685023, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 4024212558, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1085864516, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 4155879075, 1072343721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 1880439761, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2809527087, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2136351093, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 1068175546, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1086081096, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 2004684575, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 1617106727, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 3885124337, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 1609685023, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 4024212558, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086234824, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085277184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 4155879075, 1072343721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 1880439761, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2809527087, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2136351093, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 1068175546, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1086270768, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3597052290, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 4163300779, 1071802790, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1232827413, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 3753457819, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3844717284, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 797420808, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2763897354, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 3819978273, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1175103052, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 2963458715, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086388070, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 2004684575, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 1617106727, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 3885124337, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 1609685023, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 4024212558, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4294692418, 1086464932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2036295535, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 4155879075, 1072343721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 62122407, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 1880439761, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2809527087, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3965938441, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 2136351093, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 169049913, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 1068175546, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", 2, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086482906, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3597052290, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 4163300779, 1071802790, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1232827413, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 3753457819, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3844717284, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 797420808, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2763897354, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 3819978273, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1175103052, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 2963458715, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086573224, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1700394732, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 2004684575, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4064344732, 1070113230, "_x_x_x_x_bach_float64_x_x_x_x_", 1617106727, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2365324389, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 3885124337, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2410954122, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 1609685023, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 24464134, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 4031634261, 1070912333, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1932941442, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 4024212558, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample2.aif", "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample3.aif", 3, "]", "[", 3, 0, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 274878, 1086668059, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3597052290, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 4163300779, 1071802790, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1232827413, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 3753457819, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3844717284, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 797420808, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2763897354, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 3819978273, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1175103052, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 2963458715, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "Macintosh HD:/Users/danieleghisi/Documents/Max 7/Packages/bach/media/Slot Machines - sample1.aif", 1, "]", "[", 3, 1, "]", "]", 0, "]", 0, "]", 0, "]" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 34.960937999999999
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
					"patching_rect" : [ 210.0, 584.0, 81.0, 22.0 ],
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
					"patching_rect" : [ 210.0, 636.5, 186.0, 22.0 ],
					"text" : "linksections 1 1 l \"Slot Machines\""
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
					"patching_rect" : [ 210.0, 609.0, 69.0, 22.0 ],
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
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 381.0, 499.0, 296.0, 20.0 ],
					"text" : "And the clean advice? I really need to maintain data...",
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
					"patching_rect" : [ 180.0, 7.74086, 371.0, 25.0 ],
					"text" : "- decibels handling and copy and paste"
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
					"text" : "Slot Machines (l)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-13",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 40.0, 694.0, 33.0 ],
					"text" : "We can take advantage of what we learned, and convert our previous 1st slot into a decibel-slot. We just need to send the properties which should change (no need of sending again name or type!)."
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
					"patching_rect" : [ 5.0, 629.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 5.0, 604.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 5.0, 579.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 5.0, 554.0, 140.0, 22.0 ],
					"text" : "Slot Machines (k)",
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
					"patching_rect" : [ 5.0, 529.0, 40.0, 22.0 ],
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
					"patching_rect" : [ 5.0, 504.0, 151.0, 20.0 ],
					"text" : "Back to section (k)",
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
					"patching_rect" : [ 687.0, 629.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 687.0, 604.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 687.0, 579.0, 140.0, 22.0 ],
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
					"patching_rect" : [ 687.0, 554.0, 140.0, 22.0 ],
					"text" : "Slot Machines (m)",
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
					"patching_rect" : [ 687.0, 529.0, 40.0, 22.0 ],
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
					"patching_rect" : [ 687.0, 504.0, 151.0, 20.0 ],
					"text" : "Continue to section (m)",
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
					"midpoints" : [ 219.5, 662.5, 201.5, 662.5, 201.5, 604.0, 219.5, 604.0 ],
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
					"destination" : [ "obj-23", 0 ],
					"hidden" : 1,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 1 ],
					"order" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"order" : 1,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"midpoints" : [ 619.785714285714334, 249.916655999999989, 584.5, 249.916655999999989 ],
					"source" : [ "obj-27", 6 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-36", 0 ]
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
					"destination" : [ "obj-36", 5 ],
					"source" : [ "obj-43", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 4 ],
					"source" : [ "obj-43", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 3 ],
					"source" : [ "obj-43", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 2 ],
					"source" : [ "obj-43", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 1 ],
					"source" : [ "obj-43", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-43", 0 ]
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
				"name" : "Slot Machines (l) - poly.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/docs/tutorial-patchers",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "gizmo_loadme.maxpat",
				"bootpath" : "C74:/help/msp",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.slot2curve.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.times.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.x2dx.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
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
, 			{
				"name" : "bach.playkeys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.trans.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.lace.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.gt.mxo",
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
 ],
		"autosave" : 0
	}

}
