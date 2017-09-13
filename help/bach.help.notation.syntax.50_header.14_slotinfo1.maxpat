{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 101.0, 162.0, 945.0, 661.0 ],
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
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 467.0, 185.0, 93.0, 21.0 ],
					"presentation_rect" : [ 79.0, 185.0, 0.0, 0.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "#prevent+edit.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 478.0, 300.5, 59.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "#vzoom",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 348.0, 389.0, 195.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "See #edit+zsnap to know more.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 99.0, 374.5, 329.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "See #edit+ysnap to know more.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 126.0, 113.0, 327.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Refer to #slot+type to know more about each slot type.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 31.0, 542.0, 36.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Here are the basic parameter names (and expected contents) that can be set via the slotinfo (also see #slotinfo+example):",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-4",
					"linecount" : 23,
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 69.0, 598.0, 341.0 ],
					"showhand" : 0,
					"text" : "– name: the name you want to give to the slot (expected as an unique symbol).\n– type: one of the following symbols, defining the slot type: \"function\", \"int\", \"float\", \"intlist\", \"floatlist\", \"text\", \"filelist\", \"llll\", \"spat\", \"togglematrix\", \"intmatrix\", \"floatmatrix\", \"filter, \"dynfilter\", \"color\", \"3dfunction\", \"none\". \n– key: the character or the ASCII value of a key to be mapped as a hotkey for the slot\n– access: sets the accessibility of the slot content, and expects a symbol: \"readandwrite\" (default) allows reading and writing of slot content; \"readonly\" allows display of the slot window, but content can't be edited; \"none\" will even prevent the slot window to be displayed and slot content won't be accessible. If you're interested in preventing access to other notation items, see \n– range: followed by two numbers, sets the minimum and maximum values the slot may assume\n– slope: a parameter (-1 to 1, 0 = linear) to exponentially represent the displayed values of the slot\n– domain: followed by two numbers, for function slots, replaces the standard 0 to 1 domain with any input domain (input numbers are minimum and maximum)\n– domainslope: a slope (-1 to 1, 0 = linear) to exponentially rescale the domain display\n– zrange: as \"range\", but for the Z spatial dimension (used by the 3dfunction slot).\n– zslope: as \"slope\", but for the Z spatial dimention (used by the 3dfunction slot).\n– width: a value determining the width of the slot window (scaled according to the              ). Put the symbol \"temporal\" if you want the window to correspond exactly to the note length.\n– height: a value determining the height of the slot window (scaled according to the object's vertical zoom). You can also put \"auto\" if you want to leave an automatically calculated height (default).\n– ysnap: followed by a wrapped llll sets, for function and 3dfunction slots, some privileged Y points for point snapping.\n– zsnap: as \"ysnap\" but on the Z axis (for 3dfunction slots).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
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
					"patching_rect" : [ 6.0, 514.0, 611.0, 19.0 ],
					"style" : "",
					"text" : "See Also: interface+slotinfo, inspector, slot+slotinfo",
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
					"patching_rect" : [ 6.0, 500.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "Objects: bach.roll, bach.score",
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
					"patching_rect" : [ 6.0, 8.0, 368.0, 23.0 ],
					"style" : "",
					"text" : "Basic slotinfo parameters",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 602.0, 43.0 ],
					"style" : "",
					"text" : "Tags: header, syntax, slotinfo, parameter, slot, name, type, range, key, slope, width, height, ysnap, domain, domainslope, default, representation, zrange, zslope, singleslotfortiednotes, copywhensplit, follownotehead, trim, access, prevent, readonly, read, only, write, readandwrite, none, display, window, slotwindow",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
