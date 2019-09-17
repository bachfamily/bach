{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 494.0, 79.0, 617.0, 539.0 ],
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
					"bubblepoint" : 0.71,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-32",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 440.0, 230.0, 173.0, 54.0 ],
					"style" : "",
					"text" : "Here we add a \"display\" filter with the given biquad coefficients"
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
					"patching_rect" : [ 212.0, 261.0, 225.0, 23.0 ],
					"style" : "",
					"text" : "addslot [8 0.98 -1.96 0.98 -1.96 0.96]"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"linecount" : 3,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 371.0, 583.0, 50.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "The t parameter is the relative time position of the point (corresponding to the X coordinate). If the slot window width is \"temporal\", which is the default for function slots (see #syntax+slotinfo), this parameter ranges from 0. (notehead) to 1. (tail).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-25",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 21.0, 421.0, 291.0, 54.0 ],
					"style" : "",
					"text" : "A filter sequence containing 3 filters: a highpass (at the notehead), a display filter (in the middle), and a lowpass (at the note tail)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-27",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 319.0, 431.0, 279.0, 38.0 ],
					"style" : "",
					"text" : "addslot [9 [0. highpass 600 3 10] [0.5 0.98 -1.96 0.98 -1.96 0.96] [1. lowpass 600 -5 0.1]]"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 225.5, 223.0, 40.0 ],
					"style" : "",
					"text" : "We add a highpass slot at 600Hz, with a 3dB gain, and Q = 10"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 80.0, 351.0, 502.0, 21.0 ],
					"style" : "",
					"text" : "<a0> <a1> <a2> <b1> <b2> [<filtertype> <freq_Hz> <gain_dB> <Q>]"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-23",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.0, 337.0, 291.0, 21.0 ],
					"style" : "",
					"text" : "<a0> <a1> <a2> <b1> <b2>"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 248.0, 322.0, 291.0, 21.0 ],
					"style" : "",
					"text" : "<filtertype> <freq_Hz> <gain_dB> <Q>"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-17",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 181.0, 307.0, 182.0, 21.0 ],
					"style" : "",
					"text" : "[<t> <filter_content>]"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"linecount" : 4,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 307.0, 583.0, 65.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "where each llll is in the form                                                  and the filter content is in one the forms explained above for the filter slot: either                                                                                  or\n                                                    . As before, the output syntax for the filter content is a combination of the two:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 100.0, 288.0, 377.0, 21.0 ],
					"style" : "",
					"text" : "<FILTER1_LLLL> <FILTER2_LLLL> <FILTER3_LLLL>..."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-8",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 288.0, 94.0, 21.0 ],
					"showhand" : 0,
					"text" : "– slot dynfilter:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 59.0, 208.0, 502.0, 21.0 ],
					"style" : "",
					"text" : "<a0> <a1> <a2> <b1> <b2> [<filtertype> <freq_Hz> <gain_dB> <Q>]"
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
					"patching_rect" : [ 15.0, 189.0, 526.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "The output syntax is, on the other hand, a combination of the two",
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
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 154.0, 277.0, 21.0 ],
					"showhand" : 0,
					"text" : "2.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-3",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 70.0, 277.0, 21.0 ],
					"showhand" : 0,
					"text" : "1.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 187.0, 154.0, 291.0, 21.0 ],
					"style" : "",
					"text" : "<a0> <a1> <a2> <b1> <b2>"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 171.0, 598.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "i.e. the coefficients exactly as in the biquad~ object. This will set automatically the type to \"display\".",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 653.0, 95.0, 138.0, 22.0 ],
					"style" : "",
					"text" : "loadmess (0 1 2) (3 4 5)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 653.0, 125.0, 111.0, 22.0 ],
					"style" : "",
					"text" : "bach.m2jitcellblock"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 229.0, 236.0, 182.0, 23.0 ],
					"style" : "",
					"text" : "addslot [8 highpass 600 3 10]"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"linecount" : 4,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 89.0, 598.0, 65.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "where filtertype is any of the following symbols, defining the filter type: \"lowpass\", \"highpass\", \"bandpass\", \"bandstop\", \"peaknotch\", \"lowshelf\", \"highshelf\" \"allpass\".\nThe frequency is the cutoff frequency, measured in Hertz. The gain is given in decibels. Q is the resonance factor or the slope factor, depending on the filter type (as for filtergraph~).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-19",
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 52.0, 277.0, 21.0 ],
					"showhand" : 0,
					"text" : "– slot filter: two syntaxes are admitted in input:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Courier New",
					"fontsize" : 13.0,
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 158.0, 70.0, 291.0, 21.0 ],
					"style" : "",
					"text" : "<filtertype> <freq_Hz> <gain_dB> <Q>"
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
					"patching_rect" : [ 6.0, 514.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "See Also: syntax+slot+content, addslot",
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
					"patching_rect" : [ 6.0, 495.0, 602.0, 19.0 ],
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
					"patching_rect" : [ 6.0, 8.0, 299.0, 23.0 ],
					"style" : "",
					"text" : "Slot content (4)",
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
					"text" : "Tags: syntax, slot, content, filter, dynfilter",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 32.0, 602.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "Here's the fourth part of the complete list for slot content syntax:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"hidden" : 1,
					"source" : [ "obj-30", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.m2jitcellblock.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
