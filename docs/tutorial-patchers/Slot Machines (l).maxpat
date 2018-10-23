{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 13.0, 71.0, 842.0, 529.0 ],
		"bglocked" : 0,
		"defrect" : [ 13.0, 71.0, 842.0, 529.0 ],
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
					"text" : "The clumpsy advice says: you should have considered it before! But yet, if you don't have a lot of notes, or if notes share the same envelopes, you can change an envelope and then copy-paste it to the other notes.\nHow do we copy-paste? Easy! Open the \"source\" slot windows and press Cmd+C (mac) or Ctrl+C (win) - add Shift if you want to copy the content of ALL slots. Then close the window and select the destination notes. Finally, press Cmd+V (mac) or Ctrl+V (win).",
					"linecount" : 7,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 7.0, 299.0, 425.0, 103.0 ],
					"id" : "obj-63",
					"fontname" : "Arial",
					"presentation_rect" : [ 7.0, 303.0, 0.0, 0.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ -669.0, 101.0, 60.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-62",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "roll [ slotinfo [ 1 [ name amplienv ] [ type function ] [ key a ] [ range -120. 10. ] [ slope -0.5 ] [ representation dB ] [ ysnap [ ] ] [ domain 0. 1. ] [ domainslope 0. ] [ width temporal ] ] [ 2 [ name filetoplay ] [ type filelist ] [ key s ) ( width 150. ) ) ( 3 ( name loop ) ( type int ) ( key l ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 4 ( name \"slot floatlist\" ) ( type floatlist ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 5 ( name \"slot long\" ) ( type int ) ( key 0 ) ( range 0. 127. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 6 ( name \"slot float\" ) ( type float ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 7 ( name \"slot text\" ) ( type text ) ( key 0 ) ( width 100. ) ) ( 8 ( name filelist ) ( type filelist ) ( key 0 ) ( width 150. ) ) ( 9 ( name spat ) ( type spat ) ( key 0 ) ( range 0. 10. ) ( slope 0. ) ( representation ) ( width temporal ) ) ( 10 ( name \"slot 10\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 11 ( name \"slot 11\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 12 ( name \"slot 12\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 13 ( name \"slot 13\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 14 ( name \"slot 14\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 15 ( name \"slot 15\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 16 ( name \"slot 16\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 17 ( name \"slot 17\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 18 ( name \"slot 18\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 19 ( name \"slot 19\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 20 ( name \"slot 20\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 21 ( name \"slot 21\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 22 ( name \"slot 22\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 23 ( name \"slot 23\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 24 ( name \"slot 24\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 25 ( name \"slot 25\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 26 ( name \"slot 26\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 27 ( name \"slot 27\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 28 ( name \"slot 28\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 29 ( name \"slot 29\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 30 ( name \"slot 30\" ) ( type none ) ( key 0 ) ( width 100. ) ) ) ( commands ( 1 notecmd chordcmd 0 ) ( 2 notecmd chordcmd 0 ) ( 3 notecmd chordcmd 0 ) ( 4 notecmd chordcmd 0 ) ( 5 notecmd chordcmd 0 ) ) ( clefs FG ) ( keys CM ) ( voicenames <none> ) ( markers ) ( midichannels 1 ) ( ( 86.666626 ( 6900. 5881. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.115888 0.964286 0. ) ( 0.5 1. 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 1956.666016 ( 7400. 3725. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 4445.332031 ( 6000. 3697. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 6394.269531 ( 5000. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7240.285156 ( 7000. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 7840.78125 ( 4100. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7981.191406 ( 7900. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 8686.796875 ( 6100. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 9287.289062 ( 4700. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 9427.703125 ( 7000. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 10133.3125 ( 6700. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 10874.210938 ( 7600. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) 0 )",
					"linecount" : 68,
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ -668.0, 129.0, 605.0, 943.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-60",
					"fontname" : "Arial",
					"hidden" : 1,
					"presentation_rect" : [ -64.0, 17.0, 0.0, 0.0 ],
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "[slotinfo [1 [range -120 10] [representation dB] [width temporal] [slope -0.5]]]",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 6.0, 74.0, 420.0, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-56",
					"fontname" : "Arial",
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Tip: in a function slot you cannot horizontally move a point beyond its neighbour points. This is often handy, but sometimes it could be unwanted: if you keep the Alt key pressed and move the point, you'll be able to move it where you want, deleting neighbours points!",
					"linecount" : 4,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 7.0, 418.0, 396.0, 62.0 ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys 1 2 3 @maxdepth 2",
					"linecount" : 2,
					"numoutlets" : 4,
					"fontsize" : 12.0,
					"patching_rect" : [ 683.0, 278.0, 101.0, 34.0 ],
					"outlettype" : [ "", "", "", "bang" ],
					"id" : "obj-44",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.join 6 @inwrap 1",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 575.0, 318.0, 182.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"numinlets" : 6
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "But, after the slot conversion... alas! Of course the y values inside the slots (still ranging from 0 to 1) are not correct any more! How do we get them right?\nWell, there is a clumpsy and a clean advice to do this.",
					"linecount" : 3,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 7.0, 250.0, 427.0, 48.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "ezdac~",
					"varname" : "autohelp_dac",
					"numoutlets" : 0,
					"patching_rect" : [ 564.0, 434.0, 45.0, 45.0 ],
					"local" : 1,
					"id" : "obj-45",
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"varname" : "autohelp_dac_text",
					"text" : "start audio",
					"linecount" : 2,
					"numoutlets" : 0,
					"fontsize" : 11.595187,
					"patching_rect" : [ 523.0, 440.0, 38.0, 33.0 ],
					"id" : "obj-46",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"varname" : "startwinwdow_panel",
					"border" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 516.0, 429.0, 100.0, 55.0 ],
					"bordercolor" : [ 0.392157, 0.792157, 0.117647, 1.0 ],
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"id" : "obj-47",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "important stuff\nhas changed",
					"linecount" : 2,
					"numoutlets" : 0,
					"fontsize" : 15.380372,
					"patching_rect" : [ 439.0, 359.120819, 112.0, 42.0 ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "___",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 540.0, 367.0, 31.0, 20.0 ],
					"id" : "obj-40",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : ">",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 558.0, 373.0, 19.0, 20.0 ],
					"id" : "obj-41",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 128",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 568.0, 414.0, 85.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend note",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 575.0, 345.0, 81.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "gain~",
					"numoutlets" : 2,
					"patching_rect" : [ 575.0, 401.0, 126.0, 20.0 ],
					"outlettype" : [ "signal", "int" ],
					"id" : "obj-23",
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "poly~ \"Slot Machines (l) - poly\" 10",
					"numoutlets" : 1,
					"fontsize" : 16.252846,
					"patching_rect" : [ 575.0, 371.413788, 254.0, 25.0 ],
					"outlettype" : [ "signal" ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.unpacknote",
					"numoutlets" : 9,
					"fontsize" : 12.0,
					"patching_rect" : [ 575.0, 254.0, 163.5, 20.0 ],
					"outlettype" : [ "float", "int", "float", "int", "", "", "", "int", "" ],
					"id" : "obj-43",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"clefs" : [ "FG" ],
					"numoutlets" : 8,
					"zoom" : 34.960938,
					"velocityhandling" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 6.0, 96.0, 724.0, 148.833328 ],
					"versionnumber" : 6500,
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"voicespacing" : [ -5.142858, 6.714285 ],
					"automessage" : [  ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"popupmenuslots" : [  ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 148.833328 ],
					"numinlets" : 6,
					"bgslots" : [  ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplienv", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072618350, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084134058, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085086208, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085365589, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085071872, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085864517, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086081097, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086234824, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085277184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086270769, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086388070, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086464933, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086482906, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086573224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086668059, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 210.0, 584.0, 81.0, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 l \"Slot Machines\"",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 210.0, 636.5, 186.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-198",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numoutlets" : 2,
					"fontsize" : 12.0,
					"patching_rect" : [ 210.0, 609.0, 69.0, 20.0 ],
					"outlettype" : [ "", "" ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "And the clean advice? I really need to maintain data...",
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numoutlets" : 0,
					"fontface" : 2,
					"fontsize" : 12.0,
					"patching_rect" : [ 381.0, 499.0, 296.0, 20.0 ],
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- decibels handling and copy and paste",
					"numoutlets" : 0,
					"fontsize" : 16.787033,
					"patching_rect" : [ 180.0, 7.74086, 371.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (l)",
					"numoutlets" : 0,
					"fontsize" : 22.256727,
					"patching_rect" : [ 5.0, 2.924051, 184.0, 32.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We can take advantage of what we learned, and convert our previous 1st slot into a decibel-slot. We just need to send the properties which should change (no need of sending again name or type!).",
					"linecount" : 2,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 40.0, 694.0, 34.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 624.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 599.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 574.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines [k]",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 549.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"numoutlets" : 2,
					"fontsize" : 12.0,
					"patching_rect" : [ 5.0, 524.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"numoutlets" : 3,
					"fontface" : 2,
					"fontsize" : 12.0,
					"text" : "Back to section (k)",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 5.0, 499.0, 151.0, 20.0 ],
					"outlettype" : [ "", "", "int" ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 674.0, 624.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-42",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 674.0, 599.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-48",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 674.0, 574.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-49",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines [m]",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patching_rect" : [ 674.0, 549.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-51",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"numoutlets" : 2,
					"fontsize" : 12.0,
					"patching_rect" : [ 674.0, 524.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"id" : "obj-52",
					"fontname" : "Arial",
					"hidden" : 1,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"numoutlets" : 3,
					"fontface" : 2,
					"fontsize" : 12.0,
					"text" : "Continue to section (m)",
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"patching_rect" : [ 674.0, 499.0, 151.0, 20.0 ],
					"outlettype" : [ "", "", "int" ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"id" : "obj-54",
					"fontname" : "Arial",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"numinlets" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-23", 0 ],
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
					"source" : [ "obj-56", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 0 ],
					"destination" : [ "obj-48", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-51", 0 ],
					"destination" : [ "obj-49", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-54", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 1 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-37", 0 ],
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
					"midpoints" : [ 219.5, 662.5, 201.5, 662.5, 201.5, 604.0, 219.5, 604.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 1 ],
					"destination" : [ "obj-36", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 2 ],
					"destination" : [ "obj-36", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 2 ],
					"destination" : [ "obj-36", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 1 ],
					"destination" : [ "obj-36", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-36", 3 ],
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
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-45", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 6 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
					"midpoints" : [ 619.785706, 249.916656, 584.5, 249.916656 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 6 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
