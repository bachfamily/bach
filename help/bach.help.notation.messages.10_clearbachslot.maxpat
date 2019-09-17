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
		"rect" : [ 579.0, 79.0, 617.0, 539.0 ],
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
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 235.0, 167.0, 145.0, 25.0 ],
					"presentation_rect" : [ 221.0, 167.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear active slot only"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-31",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 148.0, 167.0, 76.0, 23.0 ],
					"presentation_rect" : [ 148.0, 167.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear active"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 283.0, 205.5, 118.0, 40.0 ],
					"presentation_rect" : [ 161.0, 188.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear slot named \"lyrics\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 205.5, 214.0, 72.0, 23.0 ],
					"presentation_rect" : [ 86.0, 187.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear lyrics"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-25",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 179.0, 121.0, 118.0, 25.0 ],
					"presentation_rect" : [ 100.0, 133.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear slot 1 only"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 106.0, 121.0, 50.0, 23.0 ],
					"presentation_rect" : [ 60.0, 136.0, 0.0, 0.0 ],
					"style" : "",
					"text" : "clear 1"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 75.0, 68.0, 103.0, 25.0 ],
					"style" : "",
					"text" : "clear all slots"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 35.0, 71.0, 40.0, 23.0 ],
					"style" : "",
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Courier",
					"fontsize" : 11.0,
					"id" : "obj-2",
					"maxclass" : "bach.slot",
					"numinlets" : 1,
					"numoutlets" : 3,
					"out" : "nn",
					"outlettype" : [ "", "", "bang" ],
					"patching_rect" : [ 162.0, 298.0, 200.0, 100.0 ],
					"textcolor" : [ 0.1, 0.1, 0.1, 1.0 ],
					"versionnumber" : 7900,
					"whole_uislot_data_0000000000" : [ "slot", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", ")", "(", "slots", "(", 1, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 62068, 1069492039, "_x_x_x_x_bach_float64_x_x_x_x_", 3404, 1078887251, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 45424, 1070274310, "_x_x_x_x_bach_float64_x_x_x_x_", 37449, 1078076562, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 24619, 1070990005, "_x_x_x_x_bach_float64_x_x_x_x_", 34045, 1079206207, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 56520, 1071500423, "_x_x_x_x_bach_float64_x_x_x_x_", 7660, 1079314299, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 10056, 1071805564, "_x_x_x_x_bach_float64_x_x_x_x_", 43407, 1078454883, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 2, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 22129, 1072666012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 9362, 1070745892, "_x_x_x_x_bach_float64_x_x_x_x_", 45109, 1070459917, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 16297, 1071905428, "_x_x_x_x_bach_float64_x_x_x_x_", 26385, 1072257476, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 25534, 1067096303, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", "(", 3, 87, 91, 24, 71, 71, 45, 78, 36, ")", "(", 4, "_x_x_x_x_bach_float64_x_x_x_x_", 22469, 1072004183, "_x_x_x_x_bach_float64_x_x_x_x_", 35577, 1072213898, "_x_x_x_x_bach_float64_x_x_x_x_", 1872, 1069577479, "_x_x_x_x_bach_float64_x_x_x_x_", 13107, 1070805811, "_x_x_x_x_bach_float64_x_x_x_x_", 18725, 1071944265, ")", "(", 5, 69, ")", "(", 6, "_x_x_x_x_bach_float64_x_x_x_x_", 14910, 1071883236, ")", "(", 7, "Michelle, ma belle", ")", "(", 9, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 12136, 1067644548, "_x_x_x_x_bach_float64_x_x_x_x_", 44258, 1075784504, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 52769, 1073918856, "_x_x_x_x_bach_float64_x_x_x_x_", 52169, 3229629402, 0, ")", ")", ")" ],
					"whole_uislot_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"style" : "",
					"text" : "See Also: addslot",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "seealso"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 495.0, 585.0, 19.0 ],
					"style" : "",
					"text" : "Objects: bach.slot",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "objects"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 403.0, 23.0 ],
					"style" : "",
					"text" : "Clearing slots in bach.slot",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "Tags: message, clear, slot, erase",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 32.0, 603.0, 21.0 ],
					"style" : "",
					"text" : "In bach.slot, the clear message clears either all the data, or a specific slot:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.slot.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
