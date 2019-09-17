{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 215.0, 99.0, 927.0, 396.0 ],
		"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
		"bglocked" : 0,
		"defrect" : [ 215.0, 99.0, 927.0, 396.0 ],
		"openrect" : [ 0.0, 0.0, 927.0, 396.0 ],
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
					"text" : "We snap the start of the function at x = 0, since this will be handy when dealing with bpatcher offsets",
					"linecount" : 2,
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 8.0, 283.0, 288.0, 34.0 ],
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "The function has a standard domain of 1000.",
					"linecount" : 2,
					"id" : "obj-14",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 593.0, 283.0, 190.0, 34.0 ],
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "(2) The second inlet is dedicated to sending messages to the [function] object. We'll need to send messages changing its width, and probably a \"flat\" message which will make the function flat - so we already prepare this",
					"linecount" : 3,
					"id" : "obj-12",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 335.0, 60.0, 473.0, 48.0 ],
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "(1) The first inlet is dedicated to sending the \"offset\" message for the whole patch.\nIt has to be connected with the [thispatcher] object",
					"linecount" : 4,
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 13.0, 39.0, 231.0, 62.0 ],
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "In this bpatcher we handle the communication with the outside world:",
					"id" : "obj-9",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 15.0, 10.0, 397.0, 20.0 ],
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clear, 0 0, 1000 0",
					"id" : "obj-7",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 337.0, 175.0, 103.0, 18.0 ],
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "route flat",
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 337.0, 146.0, 57.0, 20.0 ],
					"numoutlets" : 2,
					"fontsize" : 12.0,
					"outlettype" : [ "", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 13.0, 133.0, 69.0, 20.0 ],
					"numoutlets" : 2,
					"fontsize" : 12.0,
					"outlettype" : [ "", "" ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"id" : "obj-2",
					"numinlets" : 0,
					"patching_rect" : [ 13.0, 103.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"id" : "obj-1",
					"numinlets" : 0,
					"patching_rect" : [ 337.0, 113.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "function",
					"presentation_rect" : [ 0.0, 0.0, 736.0, 63.0 ],
					"range" : [ -500.0, 500.0 ],
					"id" : "obj-101",
					"legend" : 0,
					"numinlets" : 1,
					"patching_rect" : [ 0.0, 217.0, 736.0, 63.0 ],
					"numoutlets" : 4,
					"presentation" : 1,
					"outlettype" : [ "float", "", "", "bang" ],
					"addpoints" : [ 0.0, 0.0, 0, 146.408844, 323.529419, 0, 229.281769, -264.705872, 0, 444.751373, 166.666672, 0, 610.497253, -421.568634, 0, 1000.0, 0.0, 0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-5", 1 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [ 384.5, 168.0, 453.0, 168.0, 453.0, 210.0, 9.5, 210.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [ 346.5, 204.0, 9.5, 204.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
