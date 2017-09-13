{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 44.0, 44.0, 872.0, 588.0 ],
		"bglocked" : 0,
		"defrect" : [ 44.0, 44.0, 872.0, 588.0 ],
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
					"maxclass" : "button",
					"id" : "obj-144",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 488.0, 435.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "expr \"random(-100, 100)/1000.\"",
					"id" : "obj-140",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 488.0, 458.0, 178.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "won't change the x value (it'll add 0!), and will multiply the y value by 1.1 (stretch), and will randomize a little bit the slope, adding each time a random value between -0.1 and 0.1",
					"linecount" : 3,
					"id" : "obj-139",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 488.0, 506.0, 344.0, 48.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Analogously, this ",
					"id" : "obj-138",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 383.0, 455.0, 102.0, 20.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 1 2 (0 plus) ( 1.1 times ) ( $1 plus )",
					"id" : "obj-137",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 488.0, 486.0, 284.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "will take the 2nd point of the function in the 1st slot, set its x value to 0.4, its slope to 0, and add 10 (decibels) to its y value.",
					"linecount" : 2,
					"id" : "obj-136",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 510.0, 344.0, 34.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 1 2 0.4 (10 plus) 0",
					"id" : "obj-134",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 51.0, 492.0, 197.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "This works also for filelist slots. If position = 0, the new is appended at the end of the list. Last parameter deals with the active element. \nSet it to 0 to have the newly \"MaxMSP.app\" as active file.\nSet it to -1 to have NO active file\nSet it to any number n > 0 to set the n-th file active",
					"linecount" : 6,
					"id" : "obj-133",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 535.0, 320.0, 324.0, 89.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 2 1 MaxMSP.app 0",
					"id" : "obj-132",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 331.0, 321.0, 201.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If a slot is single-valued, still add a position integer, namely 1. Here we change the third 0/1 slot",
					"linecount" : 3,
					"id" : "obj-131",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 659.0, 217.0, 200.0, 48.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"id" : "obj-129",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 523.0, 214.0, 20.0, 20.0 ],
					"outlettype" : [ "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 3 1 $1",
					"id" : "obj-127",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 523.0, 237.0, 134.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "this also works with function slots (e.g. our first slot), provided that we correctly wrap each point",
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 282.0, 193.0, 515.0, 20.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "addslot (1 (0. 0. 0.) (0.5 20 0.) (1. 100 0.))",
					"id" : "obj-1",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 50.0, 192.0, 231.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Actually the \"changeslotvalue\" message supports also a slightly more complicate syntax: you can replace any value by a list containing (value modification). For instance:",
					"linecount" : 3,
					"id" : "obj-26",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 444.0, 352.0, 48.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "use this to only change the active file",
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 463.0, 412.0, 207.0, 20.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 2 0 0 2",
					"id" : "obj-124",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 326.0, 412.0, 137.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 2 0 MaxMSP.app 0",
					"id" : "obj-125",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 331.0, 349.0, 201.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "You can change also a single point in function slots, here we change the second point to the new triplet of (0.4 -120 0) \nNotice that no parenthesis are needed: just x, y, slope.",
					"linecount" : 3,
					"id" : "obj-33",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 530.0, 269.0, 332.0, 48.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 1 2 0.4 -120 0",
					"id" : "obj-126",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 353.0, 275.0, 175.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "You can change a specific slot value. Syntax requires: slot number, position, new value\nHere we are changing the 1st value of the 4th slot.",
					"linecount" : 3,
					"id" : "obj-31",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 207.0, 213.0, 294.0, 48.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "changeslotvalue 4 1 0.1",
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 69.0, 222.0, 137.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "add (or reset completely) a 4th slot slot, in the usual slot syntax, and fills it with three float values (thus, one should expect this slot being a floatlist slot...)",
					"linecount" : 2,
					"id" : "obj-23",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 162.0, 158.0, 431.0, 34.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "addslot (4 0.5 0.4 0.4)",
					"id" : "obj-24",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 32.0, 166.0, 127.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "completely erase the 2nd slot",
					"id" : "obj-123",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 75.0, 139.0, 167.0, 20.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "eraseslot 2",
					"id" : "obj-121",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 6.0, 140.0, 69.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"id" : "obj-62",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ -669.0, 101.0, 60.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "roll ( slotinfo ( 1 ( name amplienv ) ( type function ) ( key a ) ( range -120. 10. ) ( slope -0.5 ) ( representation dB ) ( ysnap ( ) ) ( domain 0. 1. ) ( domainslope 0. ) ( width temporal ) ) ( 2 ( name filetoplay ) ( type filelist ) ( key s ) ( width 150. ) ) ( 3 ( name loop ) ( type int ) ( key l ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 4 ( name \"slot floatlist\" ) ( type floatlist ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 5 ( name \"slot long\" ) ( type int ) ( key 0 ) ( range 0. 127. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 6 ( name \"slot float\" ) ( type float ) ( key 0 ) ( range 0. 1. ) ( slope 0. ) ( representation ) ( width 100. ) ) ( 7 ( name \"slot text\" ) ( type text ) ( key 0 ) ( width 100. ) ) ( 8 ( name filelist ) ( type filelist ) ( key 0 ) ( width 150. ) ) ( 9 ( name spat ) ( type spat ) ( key 0 ) ( range 0. 10. ) ( slope 0. ) ( representation ) ( width temporal ) ) ( 10 ( name \"slot 10\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 11 ( name \"slot 11\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 12 ( name \"slot 12\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 13 ( name \"slot 13\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 14 ( name \"slot 14\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 15 ( name \"slot 15\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 16 ( name \"slot 16\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 17 ( name \"slot 17\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 18 ( name \"slot 18\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 19 ( name \"slot 19\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 20 ( name \"slot 20\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 21 ( name \"slot 21\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 22 ( name \"slot 22\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 23 ( name \"slot 23\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 24 ( name \"slot 24\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 25 ( name \"slot 25\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 26 ( name \"slot 26\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 27 ( name \"slot 27\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 28 ( name \"slot 28\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 29 ( name \"slot 29\" ) ( type none ) ( key 0 ) ( width 100. ) ) ( 30 ( name \"slot 30\" ) ( type none ) ( key 0 ) ( width 100. ) ) ) ( commands ( 1 notecmd chordcmd 0 ) ( 2 notecmd chordcmd 0 ) ( 3 notecmd chordcmd 0 ) ( 4 notecmd chordcmd 0 ) ( 5 notecmd chordcmd 0 ) ) ( clefs FG ) ( keys CM ) ( voicenames <none> ) ( markers ) ( midichannels 1 ) ( ( 86.666626 ( 6900. 5881. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.115888 0.964286 0. ) ( 0.5 1. 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 1956.666016 ( 7400. 3725. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 4445.332031 ( 6000. 3697. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 6394.269531 ( 5000. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7240.285156 ( 7000. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 7840.78125 ( 4100. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 7981.191406 ( 7900. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 8686.796875 ( 6100. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 9287.289062 ( 4700. 1151. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.036366 0.833333 0. ) ( 0.5 1. 0.5 ) ( 0.536582 0.452381 0. ) ( 0.549746 0.619047 0. ) ( 0.549746 0.380952 0. ) ( 0.82618 0.880952 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" 2 ) ( 3 1 ) ) 0 ) 0 ) ( 9427.703125 ( 7000. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) ( 10133.3125 ( 6700. 1123. 127 ( slots ( 1 ( 0. 0. 0. ) ( 0.073069 0.587301 0. ) ( 0.192438 0.277778 0. ) ( 0.218965 0.325397 0. ) ( 0.265386 0.992063 0. ) ( 0.265386 0.563492 0. ) ( 0.378124 0.325397 0. ) ( 0.490862 0.65873 0.5 ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif\" \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif\" 3 ) ( 3 0 ) ) 0 ) 0 ) ( 10874.210938 ( 7600. 2620. 89 ( slots ( 1 ( 0. 0. 0. ) ( 0.189463 0.575397 0. ) ( 0.307885 0.40873 0. ) ( 0.360517 0.789682 0. ) ( 0.557885 0.003968 0. ) ( 0.623675 0.384921 0. ) ( 1. 0. 0. ) ) ( 2 \"Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif\" 1 ) ( 3 1 ) ) 0 ) 0 ) 0 )",
					"linecount" : 67,
					"id" : "obj-60",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ -668.0, 95.0, 618.0, 929.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"bgslots" : [  ],
					"voicenames" : "<none>",
					"presentation_rect" : [ 0.0, 0.0, 0.0, 127.571426 ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"numinlets" : 6,
					"zoom" : 17.070312,
					"automessage" : [  ],
					"numvoices" : 1,
					"clefs" : [ "FG" ],
					"numoutlets" : 8,
					"versionnumber" : 7000,
					"out" : "nnnnnnn",
					"loop" : "null",
					"patching_rect" : [ 6.0, 306.0, 310.0, 127.571426 ],
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"fontsize" : 12.0,
					"velocityhandling" : 1,
					"voicespacing" : [ -5.142858, 6.714285 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"popupmenuslots" : [  ],
					"stafflines" : 5,
					"preventedit" : [  ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplienv", ")", "(", "type", "function", ")", "(", "key", "a", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1067581440, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1075838976, ")", "(", "representation", "dB", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "filetoplay", ")", "(", "type", "filelist", ")", "(", "key", "s", ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 3, "(", "name", "loop", ")", "(", "type", "int", ")", "(", "key", "l", ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079356074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085733120, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1069394646, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072618350, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084134058, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085086208, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085365589, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085071872, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085864517, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086081097, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086234824, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085277184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086270769, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086388070, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086464933, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083309056, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1067622032, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072343722, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071721390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071444943, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071894331, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071748996, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071145348, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072328721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072443586, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", 2, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086482906, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086573224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083280384, 127, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1068676262, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071827755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070113231, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070712605, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070335755, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072676602, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070660629, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071777824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071133487, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070912334, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071606344, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071977552, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071644672, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample2.aif", "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample3.aif", 3, ")", "(", 3, 0, ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086668059, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084520448, 89, "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070088274, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071802791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070838883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071261857, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071059637, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072252179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071766065, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1064321215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071904037, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071161995, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "Macintosh HD:/Applications/Max5/Cycling '74/bach/tutorials/Slot Machines - sample1.aif", 1, ")", "(", 3, 1, ")", ")", 0, ")", 0, ")", 0, ")" ],
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
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 643.0, 81.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 n \"Slot Machines\"",
					"id" : "obj-198",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 210.0, 695.5, 190.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"id" : "obj-90",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 210.0, 668.0, 69.0, 20.0 ],
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0,
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "This is just fine for simple changes...",
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 511.0, 562.0, 204.0, 20.0 ],
					"fontface" : 2,
					"fontsize" : 12.0,
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"id" : "obj-87",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- modifying slot values (directly)",
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 189.0, 7.74086, 371.0, 26.0 ],
					"fontsize" : 16.787033
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Slot Machines (n)",
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 2.924051, 190.0, 32.0 ],
					"fontsize" : 22.256727
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "If you find the previous way of modifying slots a bit annoying, you have to consider that the operation you require IS a bit annoying. Plus: the mechanism we've exposed is the most general one, so you can easily change the part of the patch in the blue panel, in order to perform any other more complicate operation on the slot data.\nBut we're totally aware that dumping and reconstructing everything can be tiring if one has to perform very simple operations, thus we have set some other systems to modify the slot data. Those systems are selection-based systems, which means that they operate only on the slots of the selected notes. Consider sending a [select all message], thus, if you want to modify the whole content.",
					"linecount" : 6,
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 40.0, 776.0, 89.0 ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"id" : "obj-6",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 688.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"id" : "obj-7",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 663.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"id" : "obj-8",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 638.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Slot Machines (m)",
					"id" : "obj-10",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 5.0, 613.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 5.0, 588.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"id" : "obj-14",
					"fontname" : "Arial",
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Back to section (m)",
					"numoutlets" : 3,
					"patching_rect" : [ 5.0, 563.0, 151.0, 20.0 ],
					"fontface" : 2,
					"outlettype" : [ "", "", "int" ],
					"fontsize" : 12.0,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"id" : "obj-15",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 717.0, 688.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"id" : "obj-16",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 717.0, 663.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"id" : "obj-17",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 717.0, 638.0, 140.0, 20.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Slot Machines (o)",
					"id" : "obj-20",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 717.0, 613.0, 140.0, 18.0 ],
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"id" : "obj-21",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 717.0, 588.0, 40.0, 20.0 ],
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"id" : "obj-25",
					"fontname" : "Arial",
					"numinlets" : 1,
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"text" : "Continue to section (o)",
					"numoutlets" : 3,
					"patching_rect" : [ 717.0, 563.0, 151.0, 20.0 ],
					"fontface" : 2,
					"outlettype" : [ "", "", "int" ],
					"fontsize" : 12.0,
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
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
					"source" : [ "obj-21", 1 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
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
					"source" : [ "obj-11", 1 ],
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
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 219.5, 721.5, 201.5, 721.5, 201.5, 663.0, 219.5, 663.0 ]
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
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-137", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-140", 0 ],
					"destination" : [ "obj-137", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-144", 0 ],
					"destination" : [ "obj-140", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-134", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-132", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 340.5, 343.0, 321.0, 343.0, 321.0, 303.0, 15.5, 303.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-125", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 340.5, 371.0, 321.0, 371.0, 321.0, 303.0, 15.5, 303.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-124", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [ 335.5, 439.0, 321.5, 439.0, 321.5, 303.0, 15.5, 303.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-126", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-127", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-129", 0 ],
					"destination" : [ "obj-127", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-121", 0 ],
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
 ]
	}

}
