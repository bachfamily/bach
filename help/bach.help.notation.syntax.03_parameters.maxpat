{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 6,
			"architecture" : "x64"
		}
,
		"rect" : [ 560.0, 44.0, 617.0, 539.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 298.0, 450.0, 126.0, 21.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "(see #measureinfo).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-9",
					"linecount" : 3,
					"linkend" : [ ":", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 421.0, 596.0, 51.0 ],
					"showhand" : 0,
					"text" : "– Measureinfo (only for bach.score, assigned to measures): this parameter specifies all the time \n   signature and tempo information about each measure. Also this might contains more specifications,\n   such as barline types, measure width, and so on",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-7",
					"linecount" : 2,
					"linkend" : [ ":", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 385.0, 588.0, 36.0 ],
					"showhand" : 0,
					"text" : "– Ties (only for bach.score, assigned to notes): this parameter specifies whether a given note starts \n   a tie (in which case, it has to be 1), or not (in which case it has to be 0).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-6",
					"linecount" : 3,
					"linkend" : [ ":", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 334.0, 595.0, 51.0 ],
					"showhand" : 0,
					"text" : "– Velocity (assigned to notes): this parameter is a representation of the dynamic of the note, mapped\n   on a scale ranging from 1 (softest notes) to 127 (loudest). This choice of range is a traditional MIDI \n   choice; 0 is not allowed as a velocity choice, since it often represents note-off in MIDI environments.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-5",
					"linecount" : 2,
					"linkend" : [ ":", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 298.0, 580.0, 36.0 ],
					"showhand" : 0,
					"text" : "– Onset (only for bach.roll, assigned to chords): this parameter specifies the point at which a chord\n   begins, in milliseconds.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-2",
					"linecount" : 4,
					"linkend" : [ ":", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 233.0, 600.0, 65.0 ],
					"showhand" : 0,
					"text" : "– Duration (assigned to notes in bach.roll, assigned to chords in bach.score): this parameter specifies\n   the duration of a note or a chord. For bach.roll, this duration is an absolute duration in milliseconds.\n   For bach.score, this duration is a symbolic duration, representing the rational value of the chord with\n   respect to the whole chord (e.g. 1/4 for a quarter, 1/8 for an eight note, and so on).",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hyperlinkcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-3",
					"linecount" : 8,
					"linkend" : [ ".", ":", "\u002c", "\u003b", "[", "]", "{", "}" ],
					"linkstart" : [ "–" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 112.0, 609.0, 123.0 ],
					"showhand" : 0,
					"text" : "– Cents (assigned to notes): this parameter specifies the pitch of the note, measured in MIDI cents, or \n   midicents, or simply cents. Midicents are a finer version of the Max note MIDI number: each standard \n   semitonal note has as midicents its MIDI note number multiplied by 100. Middle C has 6000 midicents\n   (shortened in 6000mc), and then each semitone corresponds to 100mc, so that the C# over it has\n   6100mc, the D right above 6200, the C one octave higher 7200, and so on. \n   The interest of using midicents instead of MIDI note numbers is that they can represent notes without\n   approximation in most standard microtonal systems. For instance, 6050 is middle C quartertone sharp,\n   6025 is middle C eighthtone sharp, and so on.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"underline" : 0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 512.0, 602.0, 19.0 ],
					"text" : "See Also: separate+syntax, show+velocity, measureinfo",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "seealso"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 494.0, 602.0, 19.0 ],
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
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 8.0, 299.0, 23.0 ],
					"text" : "The notation items parameters",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 602.0, 19.0 ],
					"text" : "Tags: separate, syntax, cent, cents, duration, onset, velocity, velocities, tie, ties, measureinfo, parameter, item, notation",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"linecount" : 5,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, 32.0, 602.0, 79.0 ],
					"sendto" : "bach.help.filtertags",
					"text" : "bach has a standard range of parameters, specifying the basic characteristic of notes, chords and measures. These standard parameters have, in bach.roll and bach.score, dedicated inlets and outlets, so that they can be set or retrieved via their separate syntax (see #separate+syntax). Also, each parameter is a property of a specific notation item (e.g.: the pitch is a property of a note, not of a chord). The complete list of standard parameters is the following one:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
