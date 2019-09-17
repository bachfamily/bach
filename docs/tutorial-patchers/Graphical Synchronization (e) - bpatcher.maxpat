{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 46.0, 506.0, 713.0, 64.0 ],
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
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 502.0, 332.0, 25.0, 25.0 ],
					"id" : "obj-10",
					"numoutlets" : 0,
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We add an automatic listdump when a \"flat\" message is sent and when the function is changed",
					"linecount" : 3,
					"numinlets" : 1,
					"patching_rect" : [ 545.0, 124.0, 215.0, 48.0 ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "listdump",
					"numinlets" : 2,
					"patching_rect" : [ 537.0, 182.0, 55.0, 18.0 ],
					"id" : "obj-6",
					"fontname" : "Arial",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clear, 0 0, 1000 0, listdump",
					"numinlets" : 2,
					"patching_rect" : [ 337.0, 166.0, 154.0, 18.0 ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "route flat",
					"numinlets" : 1,
					"patching_rect" : [ 337.0, 137.0, 57.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"numinlets" : 1,
					"patching_rect" : [ 13.0, 124.0, 69.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 13.0, 94.0, 25.0, 25.0 ],
					"id" : "obj-2",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 337.0, 104.0, 25.0, 25.0 ],
					"id" : "obj-1",
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
					"numinlets" : 1,
					"bordercolor" : [ 0.0, 0.0, 0.0, 0.0 ],
					"bgcolor" : [ 0.964706, 0.905882, 0.905882, 0.243137 ],
					"patching_rect" : [ 0.0, 217.0, 1914.474731, 63.0 ],
					"linecolor" : [ 0.890196, 0.043137, 0.043137, 1.0 ],
					"presentation" : 1,
					"id" : "obj-101",
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"pointcolor" : [ 0.866667, 0.058824, 0.058824, 1.0 ],
					"legend" : 0,
					"addpoints" : [ 0.0, 0.0, 0, 1000.0, 0.0, 0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-101", 2 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-101", 3 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1904.974731, 292.0, 868.0, 292.0, 868.0, 178.0, 546.5, 178.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [ 546.5, 208.0, 9.5, 208.0 ]
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
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [ 346.5, 203.0, 9.5, 203.0 ]
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
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 1 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [ 384.5, 160.0, 504.0, 160.0, 504.0, 203.0, 9.5, 203.0 ]
				}

			}
 ]
	}

}
