{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 6,
			"architecture" : "x86"
		}
,
		"rect" : [ 56.0, 44.0, 933.0, 534.0 ],
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
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 392.0, 365.0, 18.0, 19.0 ],
					"text" : "F"
				}

			}
, 			{
				"box" : 				{
					"bubblepoint" : 1.0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-65",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 531.0, 371.0, 343.0, 79.0 ],
					"text" : "Notice that bach translation requires more object than OM's original patch. This is mainly due to the fact that bach has no NOTE and CHORD objects, and bach.roll plays the role of all of them, so that the appropriate levels of parenthesis must be always be kept into account"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-63",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 485.0, 336.0, 76.0, 20.0 ],
					"text" : "bach.wrap 2"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 1.0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-60",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 576.0, 297.0, 283.0, 25.0 ],
					"text" : "Level of parentheses must be re-input "
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.24,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-59",
					"linecount" : 7,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 236.399994, 201.5, 247.0, 112.0 ],
					"text" : "In OM non-real-time paradigm it doesn't matter how cables go out . In bach realtime paradigm, information flow from the top to the bottom, so the order of operations is crucial. That's why using a trigger is always a good idea."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-69",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 467.0, 173.333328, 19.0, 19.0 ],
					"text" : "A"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-66",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 616.5, 173.333328, 19.0, 19.0 ],
					"text" : "B"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 485.0, 197.0, 56.0, 20.0 ],
					"text" : "bach.flat"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 1.0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-34",
					"linecount" : 8,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 635.5, 90.0, 289.0, 127.0 ],
					"text" : "Although bach.roll can be tweaked to display single notes or single chord, it is still a bach.roll: differently from OM's note, its outlet output information with the appropriate levels of parenthesis for voices and chords. If we want to retrieve the simple pitch of the note, we have to get rid of all levels of parenthesis, via bach.flat."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 571.5, 197.0, 56.0, 20.0 ],
					"text" : "bach.flat"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 485.0, 308.0, 86.0, 21.0 ],
					"text" : "bach.append"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 609.0, 276.0, 18.0, 19.0 ],
					"text" : "D"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 485.0, 221.0, 46.0, 20.0 ],
					"text" : "t l l l"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 552.0, 276.0, 50.0, 21.0 ],
					"text" : "bach.+"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.0, 247.0, 47.0, 21.0 ],
					"text" : "bach.-"
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 10.0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-21",
					"legend" : 0,
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 553.5, 129.0, 82.0, 63.333332 ],
					"pitcheditrange" : "null",
					"preventedit" : [ "(", "note", "create", "delete", "onset", ")", "marker", "dilationrectangle", "inspector", "popup", "slotinfo", "lyrics", "loop", "zoom" ],
					"showdurations" : 0,
					"showstems" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : -19.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080967168, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"data" : [ 9953, "png", "IBkSG0fBZn....PCIgDQRA...TM..DPpHX....fFWOWi....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6c2GdTUcunG+6nIlAjDRPBHwRQD3ngyMiERUQ.kSfpFzm1.svwyUwWvWBn0WfZIX7B5QrJF.aAz50fWE7HTuTfhQqDpsApHkKPa.cRuDsfETgDIAmf4EyfYj04Ol7dljLSxd1u96yySdfreaVYm8urV6e60dsboTJEBgPybNFcAPHrajfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFSBpDBMVLFcAPuTUUUA.IkThMtDW15sOx0RuUqppNc69rB0mmpcaWGWuwd7LNNhfpbdjsA.i7RuQ.H6r65t6nUe66Mx4QJLr9r531YtNdFIaey+Z8EjomNjd5vZVSm+W0r5aeuQqufsq9rBcYx7b7LZ15fplZxT3tNq912azTSp5t0EtkIi53YF3HZ9WSJt3f+6Q93sAb019su2Hb+rL6amQvVGTkTRI07+O3I+PuN6x12az5a5uieVI1p+e3UlLpimYfst4e.rrm6FCwxlpsc66MB0wMzKKTkovqbpGGOilKq7a96+7e9O61sYMqYMjWd4oCkFimKWt3rm8rc413TNmENmKhVr7M+aDi3R.f+3e7O0lkecW2O..V3BAK7e2Hh3xU3kILmv4rv8bQzfso4eMcAQ6++hNmbNK5vxGT05+Z60cc+f1bwQ6+KwhfjyYQWV9fJHzWHHWbz0jyYQO1hfJgvLwVDTEp6GniKqFd+0sZdpU+VTV.8obYlEdmyD8DV9fp1e+.s+9EZRI4e+bsy9g4we3r39ekRz0xnYS3dNSzyX4CpZRquvnC2aPM6iEO20272VvbeA9H+5UIy7pKOmI5wrzO72G8QezvZ6tyK6Dj5rWOPVrj7FMO9BWJqpXe7PiUa6pOFMWtb0sOeov8b1y9rOqVTjLLgy4hn1msUNnJ7NwUC+laKAt00C4V3I3YxLE12xtbx18Z4CenwpKkS8R3b9vHuXSOYj+bZaZ9WmK.m5D.jKyIyT.f959B.+MXnkJqAI4N8DV9toT2x+I4n6DxXUyfg03hZ.v61KkZx4pHdirrYxUR92OWai2KZww4k2bNoYvkHqAKePU4kWdWuA08YrefILh9131dbV2CuSHyeDmr7xoV8nPZEEpj6bG4yk41.KSVEJKLBNZfHe0puBmyYgiRW6rZ7XlkZI4kqBPsph80a+UltwHuz1xWS0AO3AYvCdvcwVTGabFihZe1Oi6No2moj1sRo.y5k2CK6ltXcpTpORIkTzniTMbfhBVKUtE9hr3LSgqm2gr28QscYLMZvxGTM3AOXFxPFRWtMS41mEKtv2fOdoKjRAfLX1Yc0Ljj0iRnUjjbmdCGP1+.NiWJXoKjltCAOKYQLYIfpy0UI2wHKWVDV9ZpN4IOYWt9ubeuBddXusZIYxyLyT69DbXiII2oyUSI4SBdlaKKHibYuabIbUIG9gJV9G9qns5tec5jNm0StztlRVMI3wOUnxgj7WFq+duHlcZ6EUNWUXeLr70T0oIp3K2GyHsoydZ0hR8oJhht6T0sxldKbSTgSH4N83j1z.fm9SR.w3NEtvABYz+9FQGBKePUnSTQkrras0ATYP1y5KouW1v51jZ3DHI2oKDabf2WjG+opf5K9wYkELONgJxdn21xDUbf7+Yrvc1x2ugirCxOuExN9iG13JTVMN1j6bF.OLtI7uQFSaI.qjmbcQ1qJjkulp1mnB+GYqjdq5I.K32VBYz2OfW6U9y3cMuLS3uOd.3RlvLI665mvH6uk+TPDSRtSWnA.OSjqexWCt4ZnZOwQBoWHO6clFg6SnSRTgMijnhVzaSTQxApg2+EuMt1WYpT8GNmvtehZ4+yzs4ltCbLV52c777.vrXWG9g3sG0Uxxa29jJz38I.v3YqktYtp9qOk2nodchJLcI2I.0UWcv4d9b9tirKU648tj3.dXFjqEF7a8LO10acGQVGu1v5fTZ..UYkUVKKn5hUY0XefK6BNlp5hWUi8esLTEbDephyKKUtEUgRopWs2Mjay8WtLxaWF1OCZov4Wmc3bVypPkWFsteDlgJ6Y4QMuMcDsufFFJsvUoxnU8owrW0tT0GA6uQdos8Jnp9hUyBTfGUQ9TpReorT.pMTZ0JkRo7sqkn7jaKAPGYSyK3uzxXUJqSWEsy0aBpJ9klUqBnPsginTpSrAkmrKLJTR6ZEu11VVZJHeuUG9GCiLnxx27u1bS20cJNE.LJve4T4WUIvhXr8uVJu7ZgjFAM7luGG4AGImOPemvcvhRck7KNie9xxKGmxvVgoN4N9KkmY1qODqHNN0IKmxs.cmCiOQEA9DlerijudSGg7mwHhnc0IcS2gqt6WmNoyYF0k1FdPUk63oXPS4wAO4QEeXNDIOJDWtb0ga593u6SvUdmuLieAakMO+ASNoLdtzeeIb2i8B.7yFuqahy6weGl9E6F33rzTtRd9L+Ub3W8l4705e3zYojRJgUPkoN4N9KkG7RlBaoMKbV7GJcYjVD74ENmKhZLrFdpTJkpZ0K4AUdEVfZVfZCGIRtUzN69CpPspFug6bK7XJkucox.T4VfWkRoTdWUFp4UXEJkRoJdsYGb6J5DZwOLFtv4Wmc3blIL4NUer8pdo7VhZIKIO0FJr3dz86ZjWZanAUMbrMof4opPoTEMOTrjH6WTgNnRoTU6UMultP4k1kpBeGSso7xVk0RJTcrhWkxyrdI0lxqwaFddaREA2+qoVOJnxllbGiLnxPSTQw+WOEjad3NfeF1MrDXpqmOJ2qgKKBJUgt2ALPx4yNHiZ44xOctWKqYtv8tfEQZwsMla5OOdAlIvC9q+8L+oOVp0l+5LzdRxchxLrv4FJUkMnviGkGP4wiGEfJucUQXeHvDLlPX19RNmE9mKhVLrDUT11mOWzxtBZXG2RycqiCr5IS563dn927VHbFzdb4xEkUVYQ3mb.13ckMCZ4uJYbAQ3t1qzy6c.gqdThJvdlbGGXhJpVs1LPk2daaqxa3DEnfLTEGl2jS3U7qWUc0UqpugVVRw4kkZI6U+tifdauCHbENmO.mQxcLrKsU1fdTQWwm2M0pKl8ndo8F7BAe6ZIprVUw5QQTS5c.gqddPkx1kbGiLnxx2iJ5b0PAKdlryl+duL2rWO+6eXNDeJi.Jrhn5mtOe93Le0GvSGxdGv4wo9h116.b61MIkj9L7eII2IJyvBm0.cYwugi0tNHJJXdpizfRo7UnJqYsgnRSvTJkpt5pSEWbwEQ2TcbwEmpt5pqW84FN+5LRJSV8uLJ12ZphY.z7Cf2iGvqWXd2.iHFXGKepbzqvaXkLjdh912fiBQ9O8A4AtjovuqMqcVr8CsL7jXa2G2tcSe6ajMVHzSYcRtSOm1MvhF4L7toTuQ2McoT0AxmAjdiC2TYsJJ8Eyh+9K7iXlKcb3s97IMcXbAulOce7a136REmINFwU7CXpYN1v9MHMRocSkN9olZZfX6S7zThJOvxlFuyjVKK9prFiPsF5TFjgUGoFHbJ997VfZdY4o4lDjUtqUcrnU69LXgy4itaaLCI2QKXjWZaqqoxoo2WSUMrtok.ytfVsHO4guOLGh+S9MLiWY.7lOSlZV4MZRlz2DlCA7QEU2tk4sb7E.hY.C.9beR2RJLHAUhVz9j6.sK4NoE0Rtichz7OaDsHQElgj6nEjl+ILMRZryAedKf4kkGnfGlTunKl0y74XVn.JilTSkMhL6z2BolJgvFQBpDBMl8saJIBIWtb4HFQkLxeFkfJGlyd1y1Iqok6+nppNM.jTRstCJ19KRUsa6535M1imwQBpDsQNORg.vHuzaD.xN6Pey9cb6LWGOijkN6emy4bNNhLYEtb4xUWTST2Q0lKXSO8fKs3ha5B2VpIHmGYacx1YNNdFMKchJN6YOKpfu8xc6W974Ce97gRc1F+x9s887.pVZRU2stpppptX6ppU+ei43YF3HZ9Wq+KgP22jAq91qEJt3f+6Q93sAb0V1syHX6CpBUSKVyZb0EsY2Zu88Ts9l9CdgZnWWqek+631kTH2G873YFXoa9W2IbaZgcY66sV1yM0vbY2XXtLi43Yzr80T0ZQZSFr5aeOwxdto1Iort8a2M1bfcWucg6wSa2NijsNnJbaZgcY66cZI6Ygywt66acQ1wCb0MaWjd7LN15l+AgeyHrKauv3YoeNUQhN1TkN+4Z3xkK74yWXu8Q5wWO19nMmRucumvwDTEIjKX5dx4nNmsu4eBgdSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFyV2MkDgGmvXVgdRBp5D1sKz5tGTq7fb0NRPUmvNcQlc6OPX1I2SkPnwjfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFS5QE1VA6QHUU0oadPrIxVunmRBprw5tomlvc5qQDYjl+YS09oclzSGVyZB+0K54jfJantaLXWuGi1cZjl+4.zciA6l4okFqHInxFJRFC1i9iQ6NORy+ro5torlvcJsQD4jg84PvpMjFepScpPrzfk+y8bC1Xju8a+1Hb8sXfCbfQVAJPMTYE0.8Y.jbRtir80FPpox1xEfK91u8a6j.lta88Lksu0gqXSfAM0oxfFPe3xer2hZzrit0fDTIzNUtCtnwMaV0tNApO7CQUuWF2RWL+kxBXzkLckz7uPvdz7OsS317uRxeZ3YiSi52wchyqQesPpoRnYZ3LUimL83nCn.InRHzbxyopSXTCqWZQyNezG6N5w66y9LuVOdeiMNv6a5E+4LVGcsURMUcBkRo6eYFL9I785w6aZ+3bfcNads8UYvED3SX9ttb1tCKQERPkP6jblbhc8RL2wMHbM4IiqXGI6XdKlIjhypAQNqeZEQcobMyAUC2BkcBePBCfTRJditHo6jfJg1Kl3Ikg47BlZhz7OgPiIAUBgFS5QEgfQ0iJ5oetgpGUzaxh2d9KePa99HtC05vIAUgfcHnRKIAUQFo4eBgFSBpDBMlDTIDZL4dpBAq18TEdZYvyDjwhhnI4g+5fHCdl5Co4eNDxfmo9QBpb.jAOS8kz7OGHYvyL5xwETYTu7gFoHYv0Tz643x9mYdPcIZm8ultuplHCdlQGRPkIRzOk5tZ9dnjZnhdbbM+y4xko9OnXmHY+SHzXRPkPnwjfJgPiIAUBgFSBpDBMlDTIDZLIk5VHNwdChUjDTYwHOmIyOo4eBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIuOUlDs7dNkXiKwUDsdg4g7bpLAx4QB9Jt2xPGlJhVuvbQZ9mAq0ALsLzg4JrWuv7QBpLPc2PGlLzhYMIM+yDo6F5vjgVLqAInx.EICcXxPKl0gz7OCVnFlvV1yM0vd8ByGIk55ntZFO7bO2yE.91uMPiKwUDsdPlwCMKjl+YR7se6213+KzY1q6Vuv7PBpLMBV64i9X2YGVyy9LqCIXx5PtmJKfwl9+pQWDDQ.InRHzXRPkPnwjfJgPiIoTWG09Tp+nO1cziOVO6y7ZcXYRJ0MGjZprnFa5i1nKBhNgDT4.USI4iKWtZ4qIOedqOR5ftZEInxQ5L.4QEJEMTuOJ9dfrR8mv6KwUZBInxwxMtAhwcRL1aYorgr1IOWAkXzEJaAoGUXfd1m405v8Fc82vUzgs6c+C+0nbIwMoM4LHuJ95n7miyfDTYvNPwGpw+Wm2MkZ61EkDGf+n6GgSgz7OAfeJovcxvGT+M5BhsfTSki0WQM9CPrMTE+0eyh3VKHC16qeYFcgxVPpoxQJNfGmKpOwReRXPbsaruTXoEvUEuQWtrGjdTgNpqdIEa5dpfP2qzCm6oR5QElCRPkIkL3YZcI2SkIjL3YZsI2SkIiL3YZ8IAUlHxfmo8fz7OSLYvyzZRBpLQhjAWSg4kz7OSFYvyz5SpoRG4xU3mvAe97Az5TpKrJjfJclU3YjI5cbPO7WEUU0oAZ5u9quooVdXtNGNlZpx4QJDn0OPU87yVdXtNINhDUD5GnpQ9YK0RYmY6CpLxGnp7vbclbLM+qIF4CTUdXtNC19fJi7ApJOLWmIaey+fN6Ap1wkoee1xCy0NyPRodW+x5Esn3bO2fULGb1HTeSVP3LSHFsHu7h5Kaey+ZgKCc1HTlIDcNbDM+SHzSRPkPnwbPM+KzRN4ja9+WYkUzpkOnHZ4Ry5DMQpoRHzXNnr+0QMUKUkUVIsdHBqoZi5pZhZYeqHjq2LQx9m9RpoRHzXRPkPnwjfJgPi4numJvYj8O4dpzWRMUBgFywWSkSfTSk9RpoRHzXN9dTQmo2euVl26wRDc0ipoplRVGtb4pUeMM1WMZcQSHrl5Q2SUMkrZRvyWwwpeALfFZf..wGe7gc0dly6op21iJZ+9VYTnL1yH2Sk9pm27OOChKxsahwsaMr3HDVe8vfp3.uykYOmCPe+5Sx2IqmkEOCYRXVHfdbP0Y.xlY+.O.I1vWSrWvf0zBkPXk0yBpZ.vyXY7okF1mF+0x8LUYkURxImb6t2pf2yUj2SKDNM8rfpXA7VAmzueFPCMDbQ8IdbKInWH5oY+KeRvybayxVUw93gFa3MV1YNy9m8kj8O8kzMkb.jfJ8kzMkDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUFk.GmWaEqgi52nKHBslDTYT7eRd071.9Bz8apvZwQETEvue5zqg8WK01I0Z3u1ZIjqJfepsy1IBzoqyesAfXhkAv.55BrvRxRFTc3s7zLoaeEM2zoS68MX5S5Qn3SG5s+nu8SSxImLCYnCkgjbxrh29PAWg+CySe62GqXEOBIOzgyvGZxrhsezFW0ayse6KhUrnoyPG9vYnIOc19QqswiX.J9MVDIOjgxvG9PI4ouBNbs.TKu8htOVzK7Bb6IODF9vGJSeQaglJVANUw7zSJYF5vGBIOzovtIdhMJcNRXbrjAUi5mLGt0Zxiqb9agu3KdexZJODSIuEP5IF5sOoKKSJZ+kxQ+7OmRJZ0j2cMI19wC.TOebgalOw80w9KsT1yFWH4ca2Iu+oBPfF7QgElOtm3hnzCWBabgvsckuDeAvWri+Sx7g5C64vkSkU94rwI71L9E71D.v2++MS962O2+9KgC9duJ6N+4RAGpVfufUlZl729guNkbziRou2qBTCMnam0D5EKZWfcfj8arGpbnimz1LLmWe+7.i6BApkWa5Cme9tabyl3J3na8NneI0GNX9Kkm3c+a3if0R8Y9pEFHTCSje9byjgGCvjuGVH4wG9o0xX5yYfQuBtmLSG2.S9dVHj2B4D09.brMkOvD4090+mP88A9rCAE9oT6+a3L9fm9oe.F2vcCbcrhQC0DH.AN5eg7XhTzCjIWnafKYXLQC3LmH5yhFTA3Nd5+nANDzmyqoFQ0Ot4W+vjUS23TLtoebbd5TmDu6BeU1vVdR9NCL.u1jFEsYH0H.MdlvOmAZ0qyxYZ4dvB70MuweSc.y6tXt28Xng5a.h8N3A9kIRSUT9MA723QI.mowk4u9ZAZ0PNPLV2S8htlkr4ePsrk6KMdxu+qx9KZErxadL7FGJ3863teIRhI13W8yM3udNNv0O1wv2IQ3vueg7pGBNulOV6lC+OOEABTKGZ6qmUxD4pGQigGG5y3yNUs3u1ufsutmDF8sxH5W+3Zl4sCqbS7OpwMCc3CkjiwG+k+3Ao1PTRaR+9WFOyfBYa+4CQs9OMd+SaicCx8TYCYI+ykG5MV.ycyyg8W9OjgGC7dqduLoIc+7ub3+qNdeUtGE22puclxMOFVI.ScFLQf3Zrlh3Al6jRkfuHKilUWzVH8DgZKKNf7YRoleviynmCaeK2EIBj3O7I428zOA+3wmZyeLSbguN2DPb.eSq93a96iYT7+528DLle7jHulWqLK0aG4Xd0OBT6ooVbGr1ql32KSenOAO4Q2JiNF+fa2M+WYp8PqggeevQeurIlZ8i69Eh2wY+0RsA.2t6WX2Zt.9OM05OFRLw90q+YJbIu5G5KKYMU8DwzuVtmmlEnA1M6luF53nBUfuANTva2pegJfB.28iHMzHF2IRh1mwf.QH3XpoJz7yo9hZoeW3.63Xsg+SyWTKbgCrSxSuEhTSk9xwTSUn4lAdgcVsPIRmsJgnqXH0TYEUUUUA.IkTS0bIiU5hPygWSU3ImGYa.vHuzaD.xNa4uCI5bVzmSk9o0ATomNjd5vZViTKknyIAUcglZxWjtNgylz7uHPwEG7eOxGuMfq1PKKByKInpKjTRsL3fFLPJzqSHZMo4ecik8b2XHVlz8hDcNIk5gAWtbgOe9.jTpK5dRPUXvkKWHmlDgKo4eBgFSRTQWvkKoIdhHmDT0Mjl8IhTRy+DBMlDTIDZLaa1+5s8pbY+kdkeOks7dp5s8pbY+kdkeugsqlp12qxgf8YuryV1e8X+E1r6op21qxk8W5U9ZAaYy+ZRusWkK6eua+cprUAU81dUtr+RuxWKXqZ9Gz66U4x9K8J+dKSchJNmy4bjdzfEiKWt3rm8rFcwvPYpa9mRojfJKFo+RZCa9mPXzjfJgPiYiBppg2ecqlmZ0uEkISN0BCjo9dphDkj+8y0N20C.EGmWdy4jlAWhDNUl5r+E1uF60rOlVBiiBZdAYSo0mOWlLVnq6jgd.aRy+9ns7BMFPkEKIubAVCu6gjtUivXXCZ9WMbfhB1rubK7EYwYlBWOuCYu6ixCMVoW.Hze1fZpBvoNA.4xbxLE.nutu.veCFZoR3bY8Cp7eRN5NgLV0LXXMtnF.7t8Ra6LPuPnSL8M+q7xKuq2f59L1OvDFQeabaONq6g2Ij4OhSVd4c4LFuPDMX5y9mv5wDeIktvzWS0AO3AYvCdvcwVTGabFihZe1Oi6No2moj1sRo.y5k2CK6ltXcpTJZRJojhQWDLbl9ZpJqrxXHCYHc41UR92FK9SSi3W5BIXd.yfhpXGL4j0iRon0jmSkEnlpvxY7RAKc8M+sdVxhj.JggwzGTcxSdxtb8e49dE77vda0RxjmYlo18I3PHhRL8M+SX8XhujRWX5qopSSTwWtOlQZSm8zpEk5SUDEc2opakMQGIIpvBDTM3AO3PjnhJYY2ZqCnxfrm0WReurg0sI0PHh1rj8nhCj+OiEtyV99MbjcP94sP1we7vFWgRHZjoulp1mnB+GYqj9baISeK32VBYz2OfW6U9y3cMuLS3uOd.3RlvLI665mvH6uo+GQgMijnBglyDeIktvz+mwaShJBbLV52c777.vrXWG9g3sG0Uxxa29jJPoM+cimsV5l4p5u9Tdc5jDU.nLw.TkUVYsrfpKVkEn.TYWvwTUW7pT.JHCUAGwmp37xRkaQUnTp5U6cC4135PkQd6xv9YvowjeIktvZknhXg3A.ObyWyv3D+0c..anzB3GMhjX3Wc57N+oOBvMW0s7LbjMMO.Xma+fHuGvB8hou4esIQE0cJNE.LJve4T4WUIvhXr8uVJu7ZgjFAM7luGG4AGImOPemvcvhRck7KNie9xxKG+FxOABmFIQEBMmI9RJcgoulp12iJN969Dbk24Ky3WvVYyyevjSJimK82WB28Xu..+rw65l37d72goewtANNKMkqjmOyeEG9UuYNeC6mBmCIQEXtuqRZehJTJkRUgZUYDLAD4V3wTJe6RkAnxs.uJkRo7tpLTyqvJTJkRU7ZyN31UzIz4RtykI+RJcg0JQE.Px7PE3k4ArzodwLmeKrQeGiw9Qu.S6o1NILwowN1vuiMuraizm8Zf4sIxcxxe8TneL82SUm1gZCbR15xyke5yuc.3dWvhXvw8U729EOOauwM4A+0+dl+zGKxXpo9IkTRwweOUl9fJg0iI9RJcgkKQEcu.rw6JaFzxeUx3BhZEKQmPRTgEHnJzu5GslepolFH19DOta7mlqMi33cpyM2x+CYDpUn+rfIpnEUUxlYxt5CIjPBzmXubxeekA.C+pSmh22QM3RmvoxBGTUCEr3YRKuVUdYtYudpBH9TFA7EUXbEMgil0MnJfOpn51sLukiu.PLCX.vm6S5VRBCg0MnJlAPyuMGd7D7em2MvHhA1wxmJG8JRSRktvPXcCpHd92WwKE7+50Kj0xX8e28x+w0OblxRyl0msLSJJLFl9mSU2MB0VUIuEKYwKlUVPKi8eW+y6k+vCHAUFAYDp0FDTAHSOolHRPkF17uZJYc3xkqV80zXe5zDDkL8jJLSzvG9a0.KgiU+BX.MDbVLrOwqcG8NmL8jJLWztfpF.7LHFra231sd1tKY5IUXtncY+K13.uEx+225s3s17lY6GnLM6P2kjomTgIiF22+plO+XGip86mDFvUnIGwtaV+PldRElMZV1+pojUSByJNp+Cmil8PWkW8CqImd1+z1Zp7dFZ.zzdxfL8jZsHu5GZcPkGM8nADNu5GvTt8YwhK7M3iW5BabjoMClcVWMCQlMEEF.MKnJ9zdHTenVczhPxzSpvDwz+RJJSOoBqFSe2TRX8XhujRWX5qoRldRsVjDUXABpjomTgUik78oRldRElYl9ZpjomTgUijnBglyDeIktvz+mwshSOom9zmlu2266wG7Ae.IlXh52GrIfjnBL2SQCXQmdRKqrx5jYrD6OS9kT5BqUhJjomTgEfou4eVwomzlJyc6qshvVRRTgPyYhujRWX5qoxJN8jdxSdRFyXFSOXFKw5SRTAl66pDK5zSpjnBmMqUhJ.jomTgYmou4eg9l8GH47YGjQs7b4mN2qk0L2fSOooE21Xto+73EXlzxzSZs57XUgjnBmMIQEBMmI9RJcgoulJq3zSpjnBmMSePk0Y5IM.0TSMPrsLr7FNiuFB6GKXhJZgYY5I8i19pYxthkDRX.jPehkb9+rWc6yVX9XgCpLGSOoGXc2FoN0GtUkCX8O9JzkOag4jou4ecptX5IMoVM8jFsFU284yGm4q9.d5Yu9Pr1yCnsY+ysa2jTRxDlfSf0Mnp8SOod81tomTuQs.pu9q+ZRIkT3Lm4LcxV7mAfwbKR2r5..fALlDQAQElwz7RhKt3vmOez2912nToRXVXga9W6mdRWEktfTYyO1kG0mdR6aeCNtsW1+rH9wcXsyhM7dGDHXlKKqrxnrxJixKubIfxgvz+bphzomzrxcsrpG+NYX5zr4SMe5932rw2kJNSbLhq3GvTybr3u7xIkTRI7lEHsYjYRQKPPUm+rd7So6tH1466kuxsaFz.GHCXvCmwbUiiK1fGWJb5OmJS7kT5BSePkv5wDeIktvzmnhN9W68yVevKge5VtWJpzmjTaLaE9O49XAiY5rkF2pE7aKg4Ow.7hyXL7K1Cbuu7t3IuoQpKkYmdMUNdFSmiO7Pnd8INQgJOfhLVhxaEUqpugVVU0dWayiKEPtpiTQKioEPtpJzoxs7pe3rY4x9WkezeEu.ryGGOCJXOoXyeZvWT93GU5Lql2xkxe5yiko03BxdC+OQlHPD5ASey+Z+qOQoda+70iWdkMtGlvskJPeH8Lg0u8fqY26sVV1xJixVVvuWKlIP7WWcv4e9c4y.Sd0Ob1jDUHzbl3KozEl9ZpB0M6e7C7NroB1OmF2Lxq7F3GeSiM33OwWsOtqTmNMVQE4s0Mv9m9sFL4E8pwoh53URYTPQ6g9s7miK94edtpt3.IIpvYyzGTEpWehgbS2CWwMcOcXaq7H+ilCnfrYpSHMJoouMtDYvCYHDeG1qvQMjfGHgTFFmWbA3bhseLjgz8GI4U+vYxxknhNW.J92sgl+tbK7wHsjSieYo6kBJnHNxZmUOLfBf9PB.+pM817WOZAj0Em.q9.0nAkYgcjoulpv9l8+xcySsxfcUoTu20w8c4mWvDSz+uKWwU.3uR5Y4oH.GXiKmk4EJ06booIB0JK+DTd48uMaWc0UGbtmO09UeYjU1E1JRhJDZNS7kT5BSeMUc6M6G337h+GWI+h8.YtnMvKd+YnwuxG0wFuqQw72N7f+5eMk8S2.Y+YalzZ7LWIa7A4Fl+VZ2978A9aRhJbnL8AUc0M6Gnx8wBRYbrRf7JrTxIyKKpTFlWgUPMtFDCZx2DiKq+eLvgLDFRL.9Kgb5P.E.WP2V1E1WVzDU3mCr4mhXGz3XkYsDJ9D0G0BnBxMCxCPCA3apd87yWvp4.UF.ZnABY5JF8+FmWbwga25z6ehvTwzWSUauYe+T5N2DK9VWH6gwyu52tGt4Idw.U0CSBQXx+w3S7BK2SicH2c9vr0ev0yPF8oCwIvYweXK2AiH1Yhe+90jdwgvZQRTgPyYhujRWX5qox3uY+53UlwnXw6ARMUnzRg0s+Cy0+czq4PDqEIQEVfZpLCuR5ex1WFibpKjWpziQ7O8hXDu3qyU0yeRx1ZxqSukMQE5qQj4Oi0lAPCAnlSTCeiQWfDlZl9l+YN5UB0wmrSfxqgzy76SCmrbJWOmFQDVJl9l+IrdLwWRoKL80TY7IpPDIjDUXABpjdkfvpQRTgPnwjfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFSBpDBMlDTIDZLSee+qye0OLuSOoBmM4U+Pn4LwWRoKL8+Icq3zSpSl7pef4dtjDK5zSpSlI+RJcgkKQExzSpvryz27Oy1zSpPzcjDUHzbl3KozEl9ZpLGSOohvkjnBKPPk4X5IUHBel9fpvWnldRGF+xR2Ky7eTG+qWy0JATBcgoOnx3mdREhHijnBglyDeIktvzWSkwO8jJhDRhJr.AUlgomTgHRX45QEAo2SOoBQ3yzWSkoX5IUHh.RhJDZNS7kT5BSeMUxr9g0hjnBKPPkLqeHrZrnIpPHLuL80TYNldREhvmjnBglyDeIktvzWSUYkUlQWDDQ.IQEVfZpLwEOQHH+NSRTgPn4jfJgPiIAUBgFSBpDBMlDTIDZLScJ0c4xk7rprXjeeYxSoduQUUUE.jTRI13RhreYK6eua+cxL00T0SkyirM.XjW5MB.Ymcj82Mj8u2s+Nc1tZpZ8EDomdvkUbwP1YK6udr+BaVhJZpIKQ55j8Wa1eQP1xl+0jhKN3+djOda.Wsr+5796TYqBpRJojZ9+G7BgPuNY+iN6uHHaUy+.XYO2MFhkMUY+0o8WXCSTQSL5TJ6z2emLaaPkPXTrcM+SHLZRPkPnwjfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgFSBpDBMlDTIDZLInRHzXRPkPnwjfJgPiIAUBgF6+FOC0QJDDTegB.....IUjSD4pPfIH" ],
					"embed" : 1,
					"id" : "obj-43",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 67.0, 221.0, 409.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 12.45.01.png"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 447.028564, 68.0, 92.0, 25.0 ],
					"text" : "Click to go!"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 416.0, 44.0, 174.0, 21.0 ],
					"text" : "bach translation"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 416.0, 67.0, 29.0, 29.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-68",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 467.0, 308.0, 18.0, 19.0 ],
					"text" : "E"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-67",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 630.0, 247.0, 18.0, 19.0 ],
					"text" : "C"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "dump" ],
					"patching_rect" : [ 416.399994, 100.0, 69.600006, 21.0 ],
					"text" : "t b dump"
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 22.0,
					"clefs" : "FFGG",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-53",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 416.399994, 365.0, 100.0, 144.0 ],
					"pitcheditrange" : "null",
					"showdurations" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : -8.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 10.0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"legend" : 0,
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 467.0, 129.0, 82.0, 63.333332 ],
					"pitcheditrange" : "null",
					"preventedit" : [ "(", "note", "create", "delete", "onset", ")", "marker", "dilationrectangle", "inspector", "popup", "slotinfo", "lyrics", "loop", "zoom" ],
					"showdurations" : 0,
					"showstems" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : -19.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080967168, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 44.0, 290.0, 21.0 ],
					"text" : "OpenMusic tutorial 2: reversion of an interval"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 199.0, 535.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 587.5, 246.0, 20.0 ],
					"text" : "linksections 1 1 i \"From OpenMusic to bach\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-51",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 199.0, 560.0, 69.0, 20.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 700.0, 7.74086, 56.0, 20.0 ],
					"text" : "onecopy"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-87",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 19.0, 444.0, 20.0 ],
					"text" : "_________________________________________________________________"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-61",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 552.0, 473.0, 193.171448, 50.0 ],
					"text" : "I don't get the parenthesis stuff. Does bach have parentheses? Where? I don't see them!",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"frgb" : 0.0,
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 286.0, 7.74086, 317.0, 25.0 ],
					"text" : "- a second example"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 22.256727,
					"frgb" : 0.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 2.924051, 300.0, 31.0 ],
					"text" : "From OpenMusic to bach (i)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 634.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-36",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 609.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 584.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-39",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 559.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (h)",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 534.0, 40.0, 18.0 ],
					"text" : "t b b",
					"varname" : "triggerA"
				}

			}
, 			{
				"box" : 				{
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-42",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 509.0, 151.0, 20.0 ],
					"text" : "Back to section (h)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-44",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 778.0, 634.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-45",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 778.0, 609.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-46",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 778.0, 584.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-48",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 778.0, 559.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (j)",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-49",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 778.0, 534.0, 40.0, 18.0 ],
					"text" : "t b b",
					"varname" : "triggerB"
				}

			}
, 			{
				"box" : 				{
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-52",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 778.0, 509.0, 151.0, 20.0 ],
					"text" : "Continue to section (j)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 613.5, 190.5, 613.5, 190.5, 555.0, 208.5, 555.0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-21", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-40", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-49", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-198", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-71", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "linksections.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/docs/tutorial-patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.-.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/patchers",
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
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.append.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
