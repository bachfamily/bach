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
		"rect" : [ 132.0, 79.0, 800.0, 741.0 ],
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
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-3",
					"linecount" : 2,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "xml" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 317.0, 620.0, 36.0 ],
					"showhand" : 0,
					"text" : "The xmlornament, xmltechnical and xmlarticulations tags handle MusicXML export as \"ornament\", \"technical\" (default: \"none\") and/or \"articulations\" (default: \"custom\" = set up a \"other-articulations\" tag)",
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
					"id" : "obj-2",
					"linecount" : 7,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "– " ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 211.5, 612.0, 108.0 ],
					"showhand" : 0,
					"text" : "The following specifications will refer to unzoomed situations, and will be scaled according to the zoom:\n– mainxshift, mainyshift: x and y shift of positioning for the main character (positive y shift moves up)\n– flippedxshift, flippedyshift: x and y shift of positioning for the flipped character\n– mainheight, flippedheight: height of the main and flipped characters\n– mainycenter, flippedycenter: position of the vertical center of the articulation for main and flipped char\n– outsidestaffynudge: additional y shift to push articulation farther from staff\n– extyshift: horizontal offset for the beginning of the articulation extensions",
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
					"id" : "obj-1",
					"linecount" : 4,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "– " ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 151.0, 612.0, 65.0 ],
					"showhand" : 0,
					"text" : "The following specifications determine the characters used:\n– mainchar: symbol or unicode value determining the main articulation character (above notes)\n– flippedchar: symbol or unicode value determining the flipped articulation character (below notes)\n– extchar: symbol or unicode value of the articulation extension, if any (e.g.: the tilde in a trill line)",
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
					"id" : "obj-14",
					"linecount" : 6,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "· " ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 258.0, 377.0, 361.0, 94.0 ],
					"showhand" : 0,
					"text" : "· copywhencloned: copy articulation while copying notes\n· copywhenclonedtosamechord: ...also when copying\n                                                   notes into the same chord\n· copywhensplit: copy articulation to all notes when notes\n                        are split, or retranscribed as tied sequences\n· shiftwithbeams: shift vertically according to beams",
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
					"id" : "obj-8",
					"linecount" : 7,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "· " ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 365.0, 612.0, 108.0 ],
					"showhand" : 0,
					"text" : "Symbols must be among the following ones:\n· avoidlines: avoid staff lines\n· outsidestaff: always place outside staff\n· centerovernote: center over the notehead\n· centeroverstem: center over the stem\n· spanties: articulation extension spans \n                 sequences of tied notes",
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
					"id" : "obj-7",
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "option" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 348.0, 612.0, 21.0 ],
					"showhand" : 0,
					"text" : "Finally, one can assign an option specification, possibly followed by a list of symbols, to set some flags. ",
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
					"id" : "obj-9",
					"linecount" : 8,
					"linkend" : [ ".", ":", "!", "?", "\u003b", "(", ")", "[", "]", "{", "}" ],
					"linkstart" : [ "– " ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 33.0, 612.0, 123.0 ],
					"showhand" : 0,
					"text" : "The possible fields to be assigned to a newly defined articulation are the following ones:\n– fullname: a symbol defining the articulation full name (e.g. \"myfermata\")\n– shortname: a symbol defining the articulation short name (e.g. \"myf\")\n– alias: up to 5 other names which will be mapped on the articulation when found in articulation slots\n– font: a symbol containing the font name, or \"default\" (in order to use the defined \"articulationsfont\")\n– basept: the basic font size (corresponding to a no-vzoom situation). \n– position: one of the following symbols: \"abovenote\", \"belownote\", \"noteside\", \"stemsidenearnotehead\", \"stemsidenearflag\", \"manual\", determining the position of the articulation",
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
					"patching_rect" : [ 6.0, 514.0, 602.0, 19.0 ],
					"style" : "",
					"text" : "See Also: articulationinfo, custom+articulation",
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
					"text" : "Custom articulations specifications",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 602.0, 80.0 ],
					"style" : "",
					"text" : "Tags: articulation, define, custom, specification, syntax, spec, xml, export, musicxml, xshift, yshift, fullname, shortname, alias, font, basept, position, pt, mainchar, char, flippedchar, mainxshift, mainyshift, flippedxshift, flippedyshift, mainheight, flippedheight, height, center, ycenter, mainycenter, flippedycenter, outsidestaffynudge, extyshift, xmlornament, xmltechnical, xmlarticulations, ornament, technical, articulation, option, avoid, avoidlines, outside, staff, outsidestaff, center, centerovernote, note, centeroverstem, stemp, spanties, tie, span, copy, cloned, copywhencloned, copywhenclonedsamechord, split, copywhensplit, shift, beam, shiftwithbeams, extchar, extension",
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
