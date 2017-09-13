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
		"rect" : [ 60.0, 44.0, 971.0, 461.0 ],
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
					"embed" : 1,
					"enablevscroll" : 1,
					"id" : "obj-26",
					"maxclass" : "bpatcher",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 6,
							"architecture" : "x86"
						}
,
						"rect" : [ 62.0, 83.0, 964.0, 380.0 ],
						"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-6",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 628.0, 465.0, 32.5, 18.0 ],
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.54,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-43",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 667.571411, 504.5, 250.0, 54.0 ],
									"text" : "...and we can do analogously with the \"outwrap\" attribute, adding the level of parentheses related to voices"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-41",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "" ],
									"patching_rect" : [ 485.0, 548.0, 32.5, 20.0 ],
									"text" : "t b l"
								}

							}
, 							{
								"box" : 								{
									"additionalstartpad" : 10.0,
									"clefs" : "FG",
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-21",
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
									"patching_rect" : [ 485.0, 578.0, 456.0, 112.571426 ],
									"pitcheditrange" : "null",
									"stafflines" : 5,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 7300,
									"voicenames" : [ "(", ")" ],
									"voicespacing" : [ -8.428572, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
									"whole_roll_data_count" : [ 1 ],
									"zoom" : 41.962891
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.15,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-40",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 676.071411, 413.5, 264.0, 54.0 ],
									"text" : "Instead of adding a bach.wrap, you can add levels of parentheses to incoming stuff via the \"inwrap\" attribute..."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-39",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 697.0, 930.071411, 50.0 ],
									"text" : "We might think to translate the x-append object in a bach.append object. A crucial point is that this would not work - at least not in this patch. The reason is due to the fact that x-append requires the evaluation of random data: each time that F is evaluated, a different data is set in one of x-append inlets. But in bach information goes from top to bottom, so that bach.append is \"static\": if you append 4 times the result of a random process, that will always be the SAME result!"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-37",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 587.0, 465.0, 32.5, 18.0 ],
									"text" : "700"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-36",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 546.0, 465.0, 32.5, 18.0 ],
									"text" : "500"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "" ],
									"patching_rect" : [ 546.0, 438.0, 101.0, 20.0 ],
									"text" : "sel 2 4"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 512.0, 490.0, 57.0, 20.0 ],
									"text" : "bach.+ 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "int" ],
									"patching_rect" : [ 498.5, 137.0, 66.5, 20.0 ],
									"text" : "t b i"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-30",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 518.5, 113.0, 25.0, 19.0 ],
									"text" : "G"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "int" ],
									"patching_rect" : [ 471.5, 111.0, 46.0, 20.0 ],
									"text" : "uzi 5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-29",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 632.5, 522.0, 25.0, 19.0 ],
									"text" : "(G)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 485.0, 522.0, 142.0, 20.0 ],
									"text" : "bach.collect @outwrap 1"
								}

							}
, 							{
								"box" : 								{
									"data" : [ 33480, "png", "IBkSG0fBZn....PCIgDQRA..ArL..HfnHX....PtQbOR....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6c2GeTUdm+++0wMiIC1L3.EPS5ZPtokXWlHjRA0hcSvVIReHXWr1JPaoVCzVp.0BTXA1VvJEztXPqEvZkVA1hf2D1pgZExVZKEpFTl76qgVBJXkjRhjHYTxjloN+9iYRxjISxjDlaOy6m9XdPx4bly4ZlLlO455745ykgWud8hHhHhzstj3cCPDQDIQmBVJhHhDFJXoHhHRXnfkhHhHggBVJhHhDFJXoHhHRXnfkhHhHgQZw6FPrWGSqzFa7cA.61u7.1uQO9rarwFC54zyGO3MnqS3O9N21r2qN9N+bhludDQjTOofAK8Yo2aY.vn9X2B.Tbwgu1Lrz68E5GOmfuN8m1V+44Dcd8HhHohRIGF1.Crje9P94Cacq8bOpBLvxE2yo+z1RLd8HhHopR4BV11PU1W1WaCUYeYewtmSr40iHhjJKkcXXaSEU36eq9u7B.WmdN8xmiHhjJIkKXYfI+hufCgdecd6cjjMc84D5DvI18bhMudDQjTYobCCK.a3GWTuZacd+2RD54z0sE91V+44D4e8HhHopLLSKQWuwa7Fg8X15V2Jqe8qOFzZLWLLL3C9fOHd2LDQj3BS2vvNxQNB.329aeoNs8Oym4l.fksLvD82GDyXXnLkUDI0kocXXaK3XvesHhHRekoKXYf8n7y7YtoNEnL3daJhHhzaX5BVBgNnnBTJhHR+koLXYuiK98aaSr1MsWpwS7tsHhHRhLSWB9.g9dT9Y9L2Tm5cYka4axMN+sC.UjtSdt4M1XV6SDQjjKltdVF78nL36gI.35HrJ+AJAnz4+Hbb2wrlnHhHIYLcAKaSfAIC99Ud7m9QnT.X5rl0ubfsxK95plnJhHRnYpJJAeuu22qWcbNNy5YVaGVdYmg6epYwQ1PdTbFOAG6dFeTtEl7xvvPyOUQjTVlp6Y45W+56E+B8FYSEtdfky7lZV.v.xXvf6Vi5sOQDQRNYZGF1tk6yxaVNTPIyjb7uoVAbtupvU7rcIhHRBKSUOKAn1ZqsmOf2+s3OCbCib.9O12lssvxgodqb1Zqk2KVzHEQDIoho5dVp5WZzkI5iJhHRehoqmku5q9pLrgMrd3Hde10LGMu2O5s3tr+6YJicVTEvrerCwFl1viQsxjOYkUVw6lfHhD2X55YYM0TCW4Udk83wU4VlCq5zikLW2xv2rsr.1ecGfBGRrnUlbRYCqHRpLSWOK6UZwIkttNJJANVyJUfRQDQ5Vltfkm8rmsG2+4NxiiiE5LfsLUt+aO2vmXPhHhjxxzMLrRziI5iJhHRehoqmkcaB9btivLG6swgBXS4t18y9uqbiYssjYJAeDQRkY5BVNrgMrPjfO0yFlUfAJKfhm84X.iImvlLPhHhHoDUvmitkuCKq7N99cT8AXKqeYbfe6IheMJQDQRZX55YYvI3i6peVxOfkiqk7TURAC303W73+e3bqOF2v+eWO.Lha31o3u1+AiZflt2RDQD4hjRvGoWyD8QEQDoOwz0MpNkfOdNEq6ptddX.X1bvSbO7+N5OIOPPOmbApp8u654YqZOLwAFaZu.7tu66x0dsWKu1q8Zb4W9kG6tv8AJAeDQRkY5BV1oD7wUs7V92dwkdebsMUJ2H.T.kV8SyG4omK64S7Xb+ElIGYmqgIMq0AbH1zdqlCrzIGSa2+i+w+fK+xubkvQhHRBHycB9XAxD.bvcL4b3Lu7A.fcTUobqizNW80kOO+KcbfLXh248S06dQ.P466Uow3UaVDQjDNltdV1oD748eGdG.Xzf6Zo9yWOvJY7C78n1ZeOv9Ho0m62Q0e6QwkALfa3qvJy8g39ZwMmq1ZwcLtMGtpOjHhHwGJAejdMSzGUDQj9DSWOKCtB971u3+Eexu5iw0ujmk8r3gwRy554i8qqj6Z7CFvM65qMMtzU+7baCOCf2l0k0mjGdpajS7yuCtrXTa9rm8rLtwMtdwxKV7iRvGQjTYltfkAWAetxuxOjR9EOFK7AtMd3BOEOYCGjBGzX4Bk5j6+VGKSonqfe94+PbkW4P3na66yCCr7k7EXTwgDsIzUeHQDQh2L2I3C.LDtmRcxh.VWQCm48TvtZ3TL9i+HLi0tOr8olAGXGOC6YCyg7m6VgEsaVdgpWThHhzASWOKCcRx7gYou0qxnefky2Z92Hac9vcujUxXS+EX94+v3D31A91+jeMK91FOuWs0x6EGZyJAeDQjDSJAejdMSzGUDQj9DSWOK66IIiG10WqXF5C7yofAGYZCU93YwMuJ.91bn2Z4L7v7trRvGQDIwloKXY3SRF23xUqXwZljg+W82XAoyy+9Yvc9uY+h956936zefRvgiGlq+9lDMsk6zewQHPdvkKWfkN1iRvGQDIwTJPB9zgFqbOTngUrYyFVsjGa4H0..W80kOUbj2LhbMNzu7mwh18AYyydQr0WpJV9VmEO8wc0oi436aSTngErYaPXypEV5O6vQjqsHhHQGoPAKcQoq51oik0RmL+h2NMBjYViD960cweI73lqeMGfMNyqkVNyax+Hiwv860Ke0wzQuGO51lC4VzBCnc.ae0O3E+0VDQjnlTmfkdZf5ZJns4rVZvCj1fFD72ZneWd673pdp2MT4i9EYM+oFA7.jIWl0NNlFZnAp8MO.+v4t8PbFtT.e26xZq8uwINQU7V0Ve+r0HhHRjVpSvxzFDsupa4vgu+cQ2LiLM3.OPQ7lSXrjQe7T5o9ixApzEMehMycroi.omIVuT.rBkuc9tKYsr2i6hKbgKPVYkEYMhovyDxyz+G.LtwMNxJqqhO5G8ZHmrFJ20C9aiY0mVQDQ5doNAKIS9BO3l88kNcBSeCr8q5v7E+rWMSYcEy1Kdr84yXyuwyyhetSfkALPxdfC.KoCM+NUyllyDYg.k+PqlScAOLfAL.ps1Zol2X+746xYYVrie2qFxy+OeIqii4Jj6RDQjXHSW1v1SrO94QCNuRVypVEOToKkYWpus+Ye3EvX6qcqD.KoyUOzARFVSmsWV4LkqwIqateR5bXWeuEa2tcvdgrsScXbr10vu3weA7kRQ6fx1+D5lKfs9QiRDQjHMSWQInlZpI7S+BWGgYXaRTZ6anXpp4svX5EALcWyw4DjMiMqLwcka.qNpj0rnyvpenNRYmwA7p.+WGtA99SrySGkits4P9c49V5.vYWuXNJg5N18vP.BbpljYFw9+FGCCCUTBDQRYkBMLrc33O8i3OP4zYMqe4.akW706MK2yml6N6bwQ1eJ9SGaOLQGKCX6cJPIErHJ4L+U971+W4p+3cDn7jm7j7ZGY2rxPlfOsFxqVQS6ek2q1Z4f6bsbCALUSl2l985dYJhHwPof8rzE6bN1XVaGVdYmg6epYwQ1PdTbFOAG6dFeOd9qbaEhi45Ov3m9K.+tmp884XQkvLOvBI8s2LKcrt4NLrSUe4kv+42YULkraggLjgDAdE1lajC2zuiI10JcPTi5YoHRprTvdV5g24L.rbl2T8UB2FPFCFbG5d209y5z6AGysbJd1SmmnBm7fm0efxkueN0AWCW8XJfaewECteCt+aMedJfJ+kO.at72jO7G9Cya7FuAu5geJJpKm4owO7mtgt4pd87uGxsewWogDQDo2K0KXo6yxaVNTPIyjb7uoVAbtupnGS7TKif867LLuIjI+sVGN26qdFdse85X5WQVj8PFJYRqzJmkksnUxC7+9Fs+zFzP80ixq9puZt1Id6rqScX9920svU29Q77T0Y5leL7wu9POcVbTHiHF1qRQDIUmoKaXC6xb06+V7mAtgQ5a5b.uMaagkCS8V4rgXo4xy4pjCW2Uw377rrp+7jYsWZy35cNC013.wlUOT+aebd0J++w1m+7os6FYa8Q8Zu0uKyygG+WGep7Ye.99O9Kzoqw1uumHDMzYyuY6EwVGWvU2mYyuYW2NdpsVpMDOKQDQh7Lc2yRI5wD8QEQDoOwz0yxvuLW89rqYNZduezawcY+2yTF6rnJfY+XGhMLsg20itxGku8qcK7yK32SVq9evFG8NYwObUrpexJYseq6qiCLWfpfYusCwF9r1YA49oYL652vb+nCiKKi1OY70F8My9B9hLpkBUuAsDcIhHInLcAK6MKyUS4KOaVUY+O7WV2xnJ.n.l6zuNtxPjvptemLYe27ixOaQmA1W4rX+Q5r7gtLeegiYyxcrcN7mpBJI8sPYiYTj14ODm770wyL0wwEJ8TrwaMm1NY7g6xUnX12dWDS8Z1f+19P5l4SY7cdVJhHoxR8RvG.ZwIkttk098XzwZVIEFp.kmr6mKk+62z74fqaRj0G5R3Fu6GFas.s1zYok2+XbG4NCNl+C8p+HCpimWFikG8TGlMu90vZVy5YGkUAM3cK33x8s6ST9OqSKcWsMeJCdI8RyyRQDI1xz0EkvkfOm6HONNVXfUKmox8e641ojvoMu+IOdmpqN4d2qkO2eXUj9JuGFkQyTwYNL0bnCSQe5Sx3WwUy+7Zudxr42mVZ6LO6UxXtz2kZqMfzF5RuJt0470A7v6+9uOm6M+a7dm+b.vmdVqtSW+stvuGe7luRV326o6x1u0aYOL9KKLuYHhHRDgRvGoWyD8QEQDoOwz0yxtMIYN2QXli813PArobW69Y+2Ut834yckONey+7mls9o+Sr3+z0x27R2HSY2ik0eM+ApNu4hsW3PTvF9Z7aF6MxHN3I3NF0kA3lmbleS9n+heNSLnd+U4t91byK9oC5pbM.udWu3eruAE9W9obff2dtqkJ2+cwf6wVdjkRvGQjTYltfkgNAepmMLq.CTV.EO6yw.FSNgMYfb+N1nEuvGz56xSuraFeg41G7e2.achowldlmGa4LY1Tm50UizxgpAaC6J4JCr3A3tRVZWBTBvkGhsULU7+8MXiW4Osqa+OtR92TQ7QDQhYLcAKCkitkuCKKf7yYGUe.tSq6j79Am.l4H69mnm54PG5ko7UuPFdP6JCK.3AHStLqA+DyjurycgsfqxNs1ZnqRP4NUnpCw5+OWBsj9GlQNgahhl53wNvidpCymZWuH00R5cZ6hHhD6X5tmkAOLrtq9YYD232p8ueIOUkr3OkGdwG+Q4qtpGiq+5ud.XD2vsSwes+CF0.63ue38q7wYz27p53Bzo4R4vAbyim0Hnr6dIT7bJlO6nBSF23tJ91iXJz49VNa14u6d4N+ziKgedVZh9nhHhzmX5BVJQOlnOpHhH8IltggsS8NyyoXcW00yCC.ylCdh6g+2Q+I4AB543uCi9c87rUsGl3.A384HO5WgUj9Oh8Ok+Des8esrX1Huz31HK9i8VcpZ7r1eyI3tFa+atbb1ydVF23FGOyirTdvErg1u2pydsOKq4tlXnKl5wXJAeDQRkY5BV1oD7wUs7V92dwkdebsMUJ2H.T.kV8SyG4omK64S7Xb+ElIGYmqgIMq0AbH1zdqlWX1CgSP1L0uvcv1J6x4C8gfVtzAxG6SLCpYHYyUNrKzd03Y2U0.ybL806jXGUjm174WPmWpt19p1DKXgGHlttUJhHRWYtqfOV.ewYbvcL4b3LuruIgwNppTt0QZmq95xmm+kNNPFLw679o5cuH.n78c.9xYmKNx9SwqT+4oz28BXcvWGeyq6ekbJbd7UGalPlimmzaCTRASm+0g22BTFbE4Yoa9o5lizV+8UtHhHQPltdV1oJ3y6+N7N.vnA20R8mudfUx3G364qp5Xejz5y86n5u8n3x.FvM7UXk49Pbe+smjcC.NYxqaZ772+fodiKiaXTDTk9wMtaoEN9K+ZL3OR.EL8dPnlmkaeMaMzGbteBtr2qVpM30MLQDQhoTB9H8ZlnOpHhH8IwudV54jrXKihKr6pYK8zbcrOJ3oewa+h+W7I+pOFW+RdV1yhGFKMqqmO1utRtqwOX.2rqu1z3RW8yysM7L.da9gY8I4mbCeedtoVI+ww8iXwWy6Q0uSFLpOx.67E58OJybzet1SFmdUB9Dlknq+yE9M3eboClgesSlBKXrLvPcNhSTB9HhjRyabRc6eMdA7hi06stHz4DvaM0TSvWIukT.dA7t7xNkWuMbPuE.dWdoN850qWuNKo.uKpr571ZcU3cyq8q3EvaNeq8404lms20b3F59KVSU3s.7cdmdwq2aE00Z3afM6z6r8+b53Qwd22qWS2z1SbDG+nhHhD2Em5YoKdlEuZVeYkRkEMc9sm7d3NGYzZBRLDtmRcxaZyAqqngy417AYWMbJ9cO18yLN1sQISaFbfM9L7q90+Tl+O4XvWdtLowlEVRGZtwlgtqd4X8JXkk9DXa5+RV8OYoL9dy6j9WhtBth73NDq3IhHhj3HtbOK8b58fkg+GoNuajJWrASYPGDuqZxWzm2PUAe53hdVd1GX47sdXeCB5cujUxvR+77J22C29vhNhuziwKs3FXDq9evFG8NYwObUgY3U69BldeQayyRUAeDQjDSwkfkGYs4wjZd8zzZ92otW5AXTE81TUqagwbQ1OWkfOQWJXoHRppXevROGm4YIW1pCG3voSvgCb5zIq+f0wRm7PtnN08XOK69FDa+Kdq7HG70Zu.Fztq+t4Y+IqhINrtKJtGd6pNEYl6ntnRFmjkJ3iBVJhjpJlGrrl8sXxdCSfVOvc1dp3dzMUH4efuNM+b24EUfACCCpolZByxtkab4pUrXMSxveC3OrPGL4MUY6GgiEUBy7.Kjz2dyrzwFsBU0QE748Zr9tIaSKfC2ThQE7wvvPAKEQRYEiqfOt3E2vCw5WWQcZNq3XlKBJ8mwqGx0upHmFqbOTngUrYyFVsjGa4H0..ibxi0WsxY46mScv0vUOlB31WbwPqQm1gpfOhHRxkXbvxL4qd.urzI14LLMsrtU758.L9nZOnbQoq51oik0RmL+h2NMBLjwMMtw4Nel9UjEYOjgRlzJsxYYYe2GfiVumHZq3naaNjaQKLf1Ar807yC8A6nPFQBPuJEQjTcltxcW2xSCTWSAsMm0RCd.6CZPP8Wf2870yYp4zr84Oe1N.TJuzar.F+Pt3WtkangFnky+Z7Cm61CwduzPrsuJU7+cObwcWbEQDIRH0IXYZCpijvwgCvoSXQ2LiLM3.quHd8ALMdiUeiL7fdZYX4h+RegKbAxJqrnkVZoaNhWoKaI8z+eXLo+S.FvEeCPDQjKJl6UcjNIS9BO3l88kNcBSuDpZI4xdVQdLk0e87FO0y2wg5v2+TboUy8L9K9dUNfAL.ps1Zol2X+746xdmM6328p.9JUe0TSMTSM0Ps0VKCX.JPoHhjHH0omk.1G+7nAmWIqYUqhGpzERtktPl9xeB9+cnl3ie8GBbLaVtisyg+TUPIouEJaXCJxcssaGrWHa6TGlOa2TAe5zZwoHhHILLcAK6zRzUm3lp9C6mx+8N4e9QuYV65mECZXWMiahSB6CrEd1UtKVQ5Ey2dJikWc+uC0xaw6LjyRs05Nx1.uzqhacNe8NZU0Va6s4tusKhHR7jVhtjdMSzGUDQj9DSWOK6ZE7wMO62dD7sd56l8W0Ofb8mkOtO6QXIi61nskg4E9C+VTxeehrh+zWl6+Uf69wNH+foMpnRar5xeb9dyZUsWod97K8w4Y1vckvWaXEQjTUltdV1kJ3SM6i7xtHbVvZv4tVDi1dGUtGWUtMr4Xt9OvuI+li9k3QG+joT.X4Tm26OhO0MN51lC42koOx0CbndQ0GJ9QUvGQjTYl9rgs9i+x3DfxWMNFpuJ2ydNsu6CYliNelc6G4ixa5cfLC+an3c7kh7ywQ2UxFC47rTUd.QDIQloaXXCNIYpx4wB5HbxiuqCwMLmbArR9SE1t+0nq+vgeO1vFpgZ1fuuu1H85L46WKuSn19nxCp92nD7QDQRPY5FFVI5wD8QEQDoOwz0yxPkjLu8Qed1co+YdWxfQ8IuY97Sa7bY.b9ivWK2aq8E+40+r6f+7sMKeI8yT2Hm3meGbQrlNGRu+aeTdl8963cZIcF90NYJrfwh6jjE+YQDIUkoKXYnlX+W4z95Lgo806xwVe0+01CTBESQ2vXo8EpqzubF1UdkQ96l3UNMV5DlVm1TaC1qJJAhHRhISWvxdOOTwyri1+tkW1JXrCIG9uq5vb6+02mO9juQk1MhHh.XBCV1qSRly8GXsOjS.H26da7Mx6R8kPOC7pXBS.vc8DoyumtipfOhHRhMkfORulI5iJhHRehoqmkgMIY7717newOI22gfotxcvi9MKfLhcMO.UAeDQjjMltdV1SUAGO0eDVxPmDODv5KqJV5TGSrsAhpfOhHRxHSeE7wG2bz8rVrLzIwCM80PEmo43RfRUAeDQjjSltggsyIIiapp7cypl0x3Pb8rwm5PbGepgCzXLK4c5DUAeDQjjRltggUhdLQeTQDQ5SLc8rLQNIY.UAeDQjjQltdVlHmjLcmZqsVxJqrRna6JAeDQRkkhjfOhHhH8eltggMYLIYTE7QDQRrY5FFVI5wD8QEQDoOwz0yxD4jjo6bVkfOhHRBMSWvxj4k4pj41tHhXloD7QDQDILTvRQDQjvPAKEQDQBCErTDQDILLcI3SxCO3xkKvhVwQDQjDcpmkwAGeeahBMrfMaCBaVsvR+YGNd2jDQDoGndVFiEpE+4su5GLN0ZDQDo2PAKiQZngFnky+Z7CC4h+7kBz4xcWFYjA1saOF05DQDomX5J2cIhqbGW3BWfAMnAQKszRu94jd5oSCMz.CX.CHJ1x58zpNhHRpL0yxXfALfAPs0VKte2WkELhovyzo8Na12quAF0kdgNEXLiLxHgIPoHhjpS8rLFy0oOB6bWuH00R5LxIbSTzTGOICC1p5YoHRpLSWvxtuXj6lp9C6mx+8N47YjAC8C+gYPC6pYbSbRL7ApNXGNYkUVJXoHRJKSWvRI5wD8QEQDoOwz0kpt1yR27re6Qv25oua1eU+.xcf925YOBKYb2FOs+iZIOUkr3OkGdzYNNtuCA28icP9ASaTw5leBKsDcIhjJyz0yxtbOKqYejW1EgyBVCN20hXz1yjL7+mH3pxsgMGy0+AtbpttYx8Nz7oT+eecdueFRr8kPBKcOKEQRkY5qfO0e7WFm.T9pwwPsgUK4wdNsa.HyQmOyt8ibc7R+MKLC+an3c7kTfRQDQ.LgCCafSre.px4wB5HbxiuqCwMLmbArR9SE1997sm+vgeO1vFpgZ1fuuu1ZqMp2dEQDIwmoaXXknGSzGUDQj9DSWOKC0TG4sO5yytK8Oy6RFLpO4MymeZimKCfyeD9Z4da3uikr9mcG7musY4Koel5F4D+76v2wIJAeDQRoY5BVNrgMrtTTBtxo80YBS6q2kis9p+qsGnDJlhtgwRks8soe4Lrq7JQKfVhHhX5BV164gJdlcz92s7xVAicH4v+cUGla+u997wm7Mp.khHh.XBCVFbB9zsN2ef09PNAfbu6sw2HuK0WB8LvqhILA.20ixuGQDQ.kfORePz9iJWxkbIQ8qgggAevG7Aw0qoHRxGSWOK69ZCqeddadzu3mj66PvTW4N3Q+lEPFwtlWRqXQB930q2XRfq380TDI4ioKXYnRvm13o9ivRxZR7P.qurpXoScLw1FmHhHIkL8UvGebyQ2yZwxPmDOzzWCUbllUfRQDQ50Lc8rryI3iapp7cypl0x3Pb8rwm5PbGepgCznRdGQDQ50TB9H8Zwh6sWaWC2MVCm3udRNSiuO1yNWxar4DQt2xAWP3CUAhuliWIjctjUlA92R5hidfx4MZ.FwDJfwmSuehEohPuHI+Lc8rLrI3izuDSqfOtOJ2xfxmxAl9zKfRKsbX5al5dt4EUKt8tcUOm509sj6MNKVygafUMQ692S8rkYLTleoNX1SG19s6jRNbcbOSTkZeQRUX5BV1SI3ijjHsAy2b2GlWXlSjL.Z7HafAMocwa3ZdLjnXkh3XOzPYRq12WOPKcrc2G+4Y9kB6utiQgCAJds4wMt7mm4dfupJbEhjhHEIAejjJokCyzefR.Ryhuuxhkt+oDIbMy+TTc0UvxAbGv1OwgeNvQILN+cj7Zm1cAk+bbBWQ21iHRhCSWOK60UvGIgm6StWt66dUr8xcxZJ6TL9n7DhMygjCYNjgQNNfyG3NZpIXRCu8dQl4U7QAdNZM51bDQRfX5BVNtwMt3cSPhPRaP4wB9AajOUd2GyeC6hu7MsTxIp+I1VoktrEvwG+p63+YYPYSAQ6lgHRBESWvxZpol3cSvTJdrDckl8bXhSNGl3jyhxLxkc47tYoi2d3ehWjRGvc.+uFVRGbVVE39dFKY.34LUP4.Q4QEVDIAhoKXoRtGS.2Gmc9qNE2vzlHCKS3k+UajRo.V9nitAJ831MdvEmG3ce2FviGqjVZownuouNL+Ywu93SmYNF3Edj4BSeGbMJ6dDIkgoKXoXN7xysHlU6emC17AKiIFkCN4bqeQxegk56alxvYcETBMbf6A6i7Nohm3kI+bGj+irXNbceAUSgEIEhoqnDXhd4jPIV7davWCOtcgqVgLyLyH1eUWuonDzc73pQZzMj4Pr2mBTpOWJRxOErT5UhGAKiEWCsDcIhzanggURo0WCh0XiMB.1se492hJwhhjJPAKkDFFFFQ8566Ey4eo26K..i5icK.PwEqQwPjTEZXXkdkDm2a6nMzXiuKPf8xChV8zKv.k4muusUQEPwEGUtbhHIXTOKkjRK8dKCH1zKu1F50tae1sG8m6mhHwWp1vJIcBLPY94C4mOr0sF6t2gUTguGU+WdgX10TDI9xT0yxXw87JUUhx6qsMzqc29hF8xKvyYvAHUuJEI0foJXYuKyFu3tmW88rgzaPWmve7ctsEteYbr90ShkJpv2+5KH10E0tNa3GeKseeK6XaEE0tdhHIVLUAK6K5O2yq9S1P10qS+os0edNQmWOwaA9GBz0d4c4Ae3QTOv+8zngFZHlbsDQRrXpxF1dGuc4ddAskYido65YU+IaHiMOmX2qmDC99354cPKS...H.jDQAQUaulaSG8xK50y3DmLBVDIVKkqmk8m64U+IaHicOmXyqmDMa3GeKgXHjEQjniTtfkAq+bOuzyIdxWOGUu7DQhkR4BV1etmW8mrgL18bhMudDe5KYErBlKh4QJ48rD5e2yqPmMj87u7rqOmaIrsut115omSr80ShhK1oxhYnnvKhD6jxFrD56S0BCCiPjMjZpijrwrrBpHhD6jBFrr+S+BPyAErTDouRk6NQDQjvP8rrOP8VH4WzeXm6qC6tHRxfTtrgURcEKpXQ8mpujHRhOMLrRJgfqXQQiUpjPeMhnWBQj3DErLLZakLIQYU2P56BWEKJY4ZHhD+nggsWP2mRykXQEKJ4ppHIhDNJXoX5EKpXQppHIh4lFFVIkPnpBRQ50ixPeMBWEaRDIYfl5HggltHlKZpiHhzenfkggBVJhHhtmkhzG7R4bkgb62zoqw+WodRJhYj5YYXndVlpy2O6eobxpK6ogsrCFz7lUW19Mc5Zi5sJQjXKErrKt3VEODyk.6IY2EbLTT.SQLWT1v1MV58VFq699Sr6caOhWoWjjGuza82a+qGTQSgQDv2GnF1xN5xwKhXdndV1Ed6T88L+78s0JpnsZIpBblJ4kx4J6T.P+eb.ukse9DEMEp.nBfa5pth1Ota5ptB0yRQLYTB9Dj1F50taeZBlm5Y7ks+1G901BHlu+.kA5ltpqHF2xDQhUTvxvPksLIv6SYaADCr2lJHoHleJXYPBLYd5ZYK6xC9vkTX4iugikdYR+Hhj7RI3SHDpxfVjtznIIwBJoefNRvGQDyIkfOcgl5HoxZaphzVQFHv4WYCaYG7IJZJ7F.uD95Yoc.BXXXaa5knD7QDyEErTh3bU4Vvli42wFJXQT5itZt0wjHlbTdCYAGHjBnGkAFrbD.uQP22RErTDyEMLrRTPK.qm575kVatAp3qCSO2+C98IXqAxuTNWYuOPIPifudQ5Ovnc+ecfAJuoSWqBTJhITJXB93qizFFcc3T80I691vrZr9NNduK6C5yOeyqLHCfzxvNi+NWG63orxOtzJYxe0wFuaX8n1t2igpR8X+ptBZ7s969BRFjNpMrhHlQofAKCcfx11tWudwX8ctC29BBFhiOniyX8WBdWlFU6tJCFagEv5q6Bw6FR6BrXCbS3qWi4CLB+2SxQ3+3ZqnCzlej2OfWJmr5zzEQAJEw7KkLXYOI3.fsssW4604sku2PG.U5FoC3Nd2H5rPMmIa6dP1V.xJH34QogFlUQRAo6YY+TEFWRW5wY20CTwMUVV4b0Ccfw6FRmz1Pt1VvvJvWOL69.khHopTOKuHogcs6bdb41CVZsQd4ctRlUoEvgexwDuaTchpLOhH8Voj8rr6lsL8kYQiFF1dR5.qlrsZAq1FJ23tF.kUUoLwLi2sqdVCaYGsWnzGeY6WEZ.Qj1o4YYWDtD7QY6pYPfqSks6s96sOLr2DzohMPaz8qTjTSZXX6BivLzpcruJL5HnZG8zTASSVzV01YDu0em2naNlQ7V+cdkx1OPnmNIhHoFRACV5edVFPuG6O8bLv.ks88ZnYSdbSmt1tz6xtTyD7e+KUPRQjTx6YYnlejcvKfWLLnKOBrWkRxu.GR0Qf+UPjPXDu0ema5z0n4SoHovhOAK83h5qoFpuwDrIdme8TQKPLWtoSWCiv6GvaPGqfHsy+8rbDZDCDIkWLOXYMGYaXXwFCsnhXnCxJ4sh8hqXciHBH3gbUCAaxJC.CtIud4l7mqa4CbSd+.+AR819wn6GsHothsYCa8G.igNEJ4fmg6YxYAtqj4Yc1bamoBlZVwpaeZWy1Uny22xdpGjJ2gEQjTOwzfkUtkYficMCZ9.eUxHVcQ6hvkfOJXoHhHcVLMaXasklvwTcDGCTBsMTZc+zCwquhodDZUIQDQjjeojYCafpvvnSOZ6dS40Kc4gu8E5rksssKohbyueKaf8dxjw69tHRuQLMXokzAm6yYbdwmva6OpHD8dz217GPb8Fc5gBFJgVq7pyeYbr2wS7tgHhDkDSCVN1O+RgxmK+hiTuuM34jrXi7Xe0D6+kLAWTABdec2R0ED56oolVIQCtwkqt+Ospy6ySOdrgkGO31c2+4P2tbQn1qGW95MY5Nfzszo8fKWt59+vP2tHvKmmf9dQjDKw1ggcHSkybvMy7mzPwnvBwvxn3.KZUbCwrLgURVb5CrILLrhMaVwvXwbj58EI436YELiEuVVbgFXylUxadage+A1FEZXw22u3c10JwS6bwdV7bXs6burkULGxKuESk0ebVQdFXXwBVsZAiYrVprw.uVafULCCrZyFVxaEbz1N4dpgct3BwhMaXXXi46DxveJ.39zGf4XXAa1rgUi7XaGwewLv8wYEyXNr1MrXLrZCqVxisrueO6bEEhE+e+NOZ225EQheh42yxrl77vaqMwYdhmfyzPSbrMNSRvWLJjXLOmdOL7orP17gOEs1ZCr+RdSlzPWM0.z54dcJ8gpfaXcUScm5vLosNetwEeLVYUmgyTUovCMKdpJ696c34N11Y0y5gfIMWdjG4KxUj4fY5OhSpqgln4lNCOQlqFGeuW.OsesND+aKuJp6LUvxctNVySUI.bfUmMy5XEfy5ZhlpyIKGvMd.NMKe3SAdhCRSs1JUu+YwbmT19G8jKvqW51ohVtAptt53vOwjX9Eci76xYkblFNCktbXVe2RSzVirEQHdkfOokIYkSNjk83WXxdpHBDtBLPnlsMZwaIxo5+Xo.kvcNwbHszrSgEuZJfmm+lK+YTcIqkYNwQxPxIOttBfB9leMJbLYQVi4yx2zAb9V8.tOJyvv.C+OJbSGE.Z4bv5qnTl2sVHSdxSjgjgcFv6eHV4bmNS7SUDyc6.mnVbQGWq6bhiggj034KURA7lm+BfmSxtVGTRIKgwNjLIygLZxwgu1t6iWNODEvh+hSlLSKMFYgeCJA3k+a9Bf2DEvpW9LYjCYHj2jFOvzYA2Ugjk8r3y9ktKn7ln43v64hH8rTvw+ri6sX9d6ZR9zVfRuK6CByR0kD07OBpmgoYoyeu6V8+EsRK.zRPeO.Y3fmrgFZ+9Lll0Lg1CC0wMGrl8sDbTzwX2U7D7fNxApZSXyQKc7+Xz90B78UV.OmmS.L9Pzzas0V.NWW1d5AdLMCjIzZq.zTGeeas0PbdEQhuR4m5H460amdDXoMy6x71oGcZegbZknj7IRXTS9K.737aprd.ObzsuAJmB4JrF5iuqgl.HMxztcr6+QlYD5PPM0v6.LIlv0jMz3w4o+4ONTP5g7XaWFWCe8oCO5y8hTuaWTSk+Z1kSHCfLy8SyrwIO4utR7.T+QeZVHvHthteTTZsa2iHRhB8GwJIbRaj2IN2wKiCGC0+VJfRq5QImzflB5XS2Fb0AjFpoC8387K38OlhVLES9LbqqC.lcwE.17ErLn9yFv2mAegGsL9YYWDCc0cr+YPZPZigM4bG7u6vQ6G+ZJsJlYNo0kFlEKoCXCKAdgbzCMdQj3lXasgUj9.Otcgql8fU61ixU8IOzXitvZl1oa5.Z27zbSitZlLsauq+Um92WZVsSlw2RVkHRDfBVJhHhDFIw2yR2ruMsV16Ii2IZuJ0YhHhYWRSvRWGcSXXro.lv4sxecgqli8Nw6DsWk5LQDwrKwMXoG23Jf5+k0A.P5zoDhzALvAXkK1RclGOt6wRMlJ0Yox7RiM1HM1XinZCrHotRrBV5ubfsgMrXLrXEaVsvh2Ykf6iyRtiEBLetkByiBm2NwEP5CFNv+yCvL7WpyJrOVpydkisGJzv.KVrhUKFLm0tm1e9pTmI.rz6sLV288mX261NacqZpAIRppDqfk9KGXGpkafpNScTwtWDOzrVEUxXXAqe4.qgGc6uDa++pHekHOaPouNbuUeFNkycS48wRcV1C8ei0UQ0zPSMSSm4vvpuc9d68z.pTmIvRu2W..F0G6VH+7g7yG15ViyMJQj3hDt4YYST.O3xmIiIMfYLGJfuKWnUXzYeE.P1YMD+0RVWzxaBkr8kvjGYF.eN1bfk5Lq4So9OmETREbf6YzcTpyFu+IHtm54X6cyL24tGdS.m.EbpyAji+RcVIbmSbL.vWpjBX1AVpybtDF6Px.vWoN67zQoNqhu3jIyzfLK7aPIrLd4+lKl5f5301HSCxNvRcVZ3qTmsNek5LMSCh+7Mrqc+9ra2dLr0HhDukvErD5nbfE3MJr0VAbz0Jqh6VaK7ResTm4g8sjgRQGXMTwdeIbjyPv4lJj4FXW6ToNS7qhJ78uU+WdAfqKt1VDQh8RvFF1tmEKoCNKiWqFW3pwPmvMcn2Tpy7PCuIvzl.WSN1owie.dxGubFb35VmJ0YoDBrmiU+Wdg1eD79DQRMjzDrLibmJqufR4Fy1F192eBeI3SPGSXpnmAs+LnnU+Dv5JBqFVXn4tIdmAC17mVqgqTmM3UOcFpUajsiamxAHfRc1AtcGXwvfgl+b6nTmE74Sk5rDda3GeK8psIhX9kzUAeb6xEXMy9VYIqm3wEM5Bxzdl8sg.Uk5rTFsc+Ksa+xQEKeQRMkzErTjXICCCsVkJhj7LLrhHhHwKJXoHhHRXnYpPWzwPt0XiuKPa2qp1n6YkHhjpQAK6FK8dKCvW0aAfhKV22JQDIUkFF1PHv.kcTlyTOJEQjTUJXYPZanW6q6SDQDyKMLrggJyYhHhnfkAIvj4osxaVn1mHhHoNzvvFBa3GWTuZahHhjZPUvmtns2NLBpLmQ6aWRcnJ3iHBnggMD7ELT+RRQDQZiFFVQDQjvPAKEQDQBCMLrQXFF5dZJhHlMJXYTftWmhHh4hFFVQDQjvPAKEQDQBCErTDQDILTvRQDQjvPI3CJCVEQDomofk9oLXUDQjtiFFVQDQjvPAKEQDQBCErTDQDILTvRQDQjvPAKEQDQBCErTDQDILTvRQDQjvPAKEQDQBCCuo3yF+FarQ.vt8K2+V5qUymNd6qwFe2fNW8mymHhHIZRoqfOK8deA.XTeraA.Jt39+e2vRu2xhXmKQDQRrjxNLrAFnL+7g7yG15V6e8BLv.kWrmKQDQR7jRFrrsgdsutuPe7ua+ZehHhj7HkdXXaSEU36eq9u7B.WWBy4RDQjDCojAKsa2d6esufZgde8tyUGIySWOWWdvGtHhHIgRIGFV.1vO9VBw1Jpedt55yq+dtDQDIwil5HZpiHhHRXjxGrTDQDIbRIumk8rN9aGLLB8nT606GDv2odNJhHlcJXYPBL.Y9ao3vdLpi4hHh4mBVFTOI6t.jAJviwvvP8zTDQL4RYyF1f0aCTFr72Rwc6v0JhHh4f5YIcefxJl2VC4wG7w1V.yN2CSQDQLKR4yFVCCitD7qsfjcWOM6t8Ww71ptGlhHhITJcvxtKPYuc3XC0wp.lhHh4iFF1.DbvuvMLr4ukh6SAWEQDI4jxLE+5t.k4ukh6zi.2Wa6u6BpJhHh4PJaOKC0Pv1ldp2hAFvLTGiuj8wPCEqHhXhjP0yRWUtMLLLB3wL3Hth9W2.C7EpdXF3i1DXOJUuKEQDysDrdV1DvZ3TMuDFTqshGfLyL90Z5tD3Q2iRQDI0RBVvR.GCkryHCRKiLh2sDQDQDfDtfkoCNmOycdGkAbgyxGY5+HV0LGS7tQIhHRJtDrfks.TLycAKfKu0KfkAOr3ZqITSMjvkfOhHhX9jPUTBbczMgs4lNMer4QrXPXCLiXCWR9Drf2efO2Dn2REQDIBHwpmkV.bVGm0saFTqs5aSVyjLhwsxfyzU0CRQDI0VB0TGARGX0LbqVwlMaXylM1pyFiIW4fm9Ggp.DDr1lNIJXpHhXtkPMLrwCAWbB5toKRnn5BqHhjZHkOXI3sKKQWgaUGIT7En7CPK9yhHh4iBVhuW9gZMsr2Fzri.kfBVJhHlOJXIc7xuutHP29YnSK5yJXoHhX1nfkAwvnifcAG37UJdynfghHRpmDqoNRBf.6kngwkzksIhHRpG0yRQDQjvHAadVJhHhj3QCCaBtK4RtjH5b2zvvfO3CzvJKhH8EJXYBNud8FwCVJhHReiFF19MWro7LXCGM1TN9DQDI9wzFrziaW3xsmPuS2tvk6P9rvkKWDpmkG2tCZ6VHc.rXsW2lb2MmaQDQRrkbGrz8wYEyXdry8tSVwbJj7l2NwkmZXaKNOrX0F1rZgBW6dwU6G6bXsqcdXX0F1rZvZ26Ia+TU+Q1F4YXAa1rgEiYvdOtK.3j6YEXXXfEqVwhgAqcOU5e6Km46DV1ruExynP1VktBYS736YELiEuAVwLLvpMaXIuUf5LpHhjbI4dpi39nLCq4SoErH18J+7LrKaHz3uJWlNkRCa7Vwt6SxZsNJ9q6tZdxO24YFVymLWeo78m60QqUrYxsn8v9qqBJr0WBirWF6tp+Ol4Xryo22ZY3E81TcqagAU8Q3MsLBFc1YhqW+WQ14OWJ8TsxsNrSyZsNJZtTmr3OwfIsAkE1CwhvYkaYF3X9vNN7OhOy+5EXiYmOu9lcxyMuw1qdIZXXz98rrwSeRNaysFvdsvfG9HYH8gE+y.OehHhz6jzmfOMQATwKrQFeF.dNNyaR.E777.KtbZ1pUdSfRq5c3I+bVnIJfU+ctUFYZ.ScArFVMuxa3hbN4yB3je6u7A3O1by36Y8lTSyPNCd.7xabk7ce9Cy4vI.bpy4BxYnLTGv4+HCmgjUl.tXKEZi4Wt+FVAallNv7n0VZBGkTB24DGC.7kJo.l84uP+3UpKdxacTrPmcdqa1YSLuwlY+37IhHRuURevR.ZsUfL.7zJW.X4KZdrf7FHM6ARadKfGaPCB308cvdv+q5loY7sBZ15+3r.KmErfEv.ZtYfzXAKY.LnLOMq1lCd90ra16K8fjyP7vVxaPbd+W2V.xvRashL4qTZC7EZ6lRllUZODl6N5Mn+kz590qyzGL3njJ3X2y36WOeQDQ5eRtumkAKibY5ECq6gdIZxV1LxbxFKM4je6KeF+GP4b7STOd73hJ26iy5n.9zeT6LpBlMv5nLmMQ14jCYOTK37E+sbl2sY9a.SaBSfbrCG+.kxi5zWbY.rMX34J+0vk+jIJiLsic69ejYeXrQ6CFbT4rJhHROwbErjzXlkTMkj8NH2AYECKVIaGEwIeOe60FvrbLTrXwFNl9d3IpXWLQ6PZ4LSptrRXYEkKVsXAq1xlh9kmDxXLr3mnXVWQCGCK1H2MseFLP5VRCHS9rqb8T9BuQrY0F+ziE5D7I39P1+5SoOsbNn7ElOF4kGENmUvdOZ8WDmMQDQ5sRtSvmdfaWtnUrf0Lyv2nt59nTn0uKOXSG.GVbCYjQHFCZ23pwVwRlVIiz5Xudb0HtvZn6sna23BHyLhN8jLvDxolSdbZNMaXkl4UJ86yzW31oryzJSMqd+noqD7QDQ56LsAK6BWGACaShC1jWlbRT9vz8A2NNyvHWJrhF3dFu8Hv4SDQjtiIaXX6AYlG0cl5XBIQAJ6D2Gmsss8xIquQb6tQNxN2BkRALwQ26CTJhHR+ioHaX6cxfgjUzYnRiUN1bmNyMfuuj8eJlXxZveQDIIRpyvv1u4kFa7cA.61ubfXagHO3gM0iaW3pYOX0tc5Og90vvJhH8cJXYXrz68E.fQ8wtE.n3hisW+HcvMErTDQ56Rctmk8CAFnL+7g7yG15ViyMJQDQh4TvxtQiM18U67dZehHhX9jBkfOWbpnBe+a0+kW.35hqsEQDQhsTvxtgc6cLkL7EfLz6SDQDyOkfOgQa22x1rge7sDSu9WxkbIQ7D74C9fOHhc9DQjTAJXYuPa2ix3wTGI7huSsEQDIUfFF1vHQepVrz6sLf32TaQDQREnrgMIllZKhHRrgBVljRSsEQDI1QCCqIglZKhHRziBVljRSsEQDI1QYCaXXXz+ytzXwasw6o1hHhjJPAKiRhkYQah8TaQDQR9oggMIWh9TaQDQLCTvxj.WLCErHhHW7TvxjDp2ihHR7ilmkhHhHggRvmHtHasZsyIuCWzmOQDQ56zvvFgEIqUqAVN67ctzeWiHhDOnggMBJRVqVC84R8pTDQhGTvxHjHYsZU08UQDIwhFF1njHYsZU08UQDI9RAKiPhj0pUU2WEQjDKZXXifBUcYs+VqVC84pn904RDQjKNZpiDwooNhHhX1nfkhHhHggtmkwXcWcd0q2OnsiH10XDQDoWQAKi57hgQG2Z372RnqRAAdLcD3DTvSQDI9SCCaTlggQ2Ffr6Tw71p5ooHhj.QYCaDm21ezeBTB958Yf8zTDQj3KMLrQIFFWRHCTVw7Bc8uK3iss.lpi+hHR7mBVFEDp.ksEjr65oYn1uu.lFJfoHhDmo6YYDVnF50Jl2V60CGanNVe2CS8iIQDIdQ8rLJK3fegaXXyeKE2mBtJhHRzmxhjnntKPY9ao3N8Hv80196tfphHhD6odVFA0SY+ZO0aw.CXFpiQ26RQDI9R8rLJIv.egpGlA9nMA1iR06RQDIwgoomktpbaXywbCXKSmC2zywDyLt0jBotKAdz8nTDQRbYZBVBMArFNUyKgA0Zq.f0Dr.khHhjbx7DrrU.GCkgkQFjQFYDuaMhHhXhXdtmkVRGbVF+p8tW16d1C66n0DuaQgTntWjgKAeDQDI9x7zyR.nI9am5Tzja2XaPSHle085si5AafyWxfm6jcWx6DbR.EXPTkIrhHR7iIJXYKfi6fkbOyiDwAgM3LcU8fTDQRdXdFFV.b1BsFuaCAH3dPFpBPPvZa5jnfohHRhCSSsg0UkaBayFZ5X2Cw2jf0aWJj5c2zEITTcgUDQR7XZBVl3v2amgJfIz8q5HghBTJhHIFTvxHtNd6r+rTcE3w406G.XDwaghHhz2nfkQYcW8hMbkxNeAJAErTDQh+TvxnNe2Cy1DbfyWo3sDqaPhHhzGYhl5HIp57pEhggudJ1QOGEQDIQmBVFioNxKhHIeLWyyRQDQjn.ErTDQDILTvRQDQjvPAKSn3hMkmAa3nMFuaHhHhD.ErrOviaW3xsmPuS2tvk6P9rvkKWDpmkG2tCZ6VHc.rXsW2lb2MmaQDQhbTvxf493rhYLO14d2IqXNERdyam3xSMrsEmGVrZCaVsPgqcu3p8icNr10NOLrZCaVMXs68jsepp+Hai7LrfMa1vhwLXuG2E.bx8rBLLLvhUqXwvf0tmJ8u8ky7cBKa12B4YTHaqRWgrId78rBlwh2.qXFFX0lMrj2JPcFUDQhh7JcVyU3c5fWJXQd289On2Cd3p7V5hvKKpTuM30qWuMWs20.dm8tqt8ic1quTuUWWcdqpr03Eb3c+00pWumoLufCu6tpF750qWumpr03EJ1a0s50aCUcXuUTccdap4l8dlJdBu.dK8Ts194d4k5zacm4Ldan4P2Dct4o6Elt2cb3p7V2Ypv6xAuSeyNiYuEIhHoZz7rLDZhBnhWXiL9L.7bbl2j.J344AVb4zrUq7l.kV06vS94rPST.q96bqLxz.l5BXMrZdk2vE4bxmEvI+1e4Cver4lw2y5MollgbF7.3k23J4697GlygS.3TmyEjyPYnNfy+QFNCIqLAbwVJzFyub+MrB1LMcf4QqszDNJoDtyINF.3KURAL6yegX8aShzitjK4RRnmWwFFF7AefJNHRuiBV1MZsUfL.7zJW.X4KZdrf7FHM6ARadKfGaPCB308cvdv+6jMSy.oCz5+3r.KmErfEv.ZtYfzXAKY.LnLOMq1lCd90ra16K8fjyP7vVxaPbd+W2V.xvRashL4qTZC7EZ6lRll0NV9wb2wJ2ouup8mjHID750aBevRQ5sz8rLbxHWldwv5dnWhlrkMiLmrwRSN429xmw+ATNG+D0iGOtnx893rNJfO8G0NipfYCrNJyYSjcN4P1C0BNeweKm4cal+FvzlvDHG6vwOPo7nN8EWF.aCFdtxeMb4OYhxHS6X2t+GYlQnaihHhDUofkgUZLyRplRxdGj6frhgEqjsih3jumu8ZCXVNFJVrXCGSeO7DUrKlncHsblIUWVIrrhxEqVrfUaYSQ+xSBYLFV7STLqqngigEaj6l1OCFHcKoAjIe1UtdJeg2H1rZie5wBcB9DbeHUeJEQjnKspizG31kKZEKXMyL7MpqtOJEZ86xC1zAvgE2PFYDhw01MtZrUrjoUxHsN1qGWMhKrF5dK51Mt.xLC0SRI4kggQB+vvlH29jDKJX4ECWGACaShC1jWlblg+vEIUR6AibWOm7TmiVCZ+1xdTjUloA3hidfx4MZ.FwDJfwmSf+OS8z9hPsOQ5EzvvdwHy7ntyTGSPAJEoa45DOCiJ2bI2fdr8W2EP8rkYXi7mxpnzsuJxe31XSGod+OydZehDaodVJhDUzs8bq9CfwPmB6npl4yyuBq4NW1ecdovg.+90lG2X4KllNvWEKGeac69hD+8opmkReg5YYLmW.uzXiMRiMpxtijpwC6ckSAl8t4yOlL3DG94.Gkv3Fhu8dsS6tfxeNNgK5w8IRrllmkwAK8dKC.F0G6V.fhKNd1ZDI1w8IeJl9VgRO0L7McoZpIXRCu8dJl4U7QAdNZEvROrOQh0TOKiwBLPY94C4mOr0sFmaTwHWxkbIXXXDyebIWh9XdhAW7qt6YAKe+bq436uSuU.Ge7qti+p8AkME3+K6o8IRrl9sHwP8zvtlJLjrsUQWhGOj3uFOxOk4VtCN3RJr8sYIcv4Apf1Vvd7blJnb7M2g6o8IRrlBVFGUQE9dT8e4Eh2MEQhxpgGYRKiBJ4IXx16Xqi9l95Poyke8waDnQdgGYtvz+5bMY1y6SjXMcOKigrauieKQvAHCbehX1Ty9dDVMyFmEO9Ns8LF4cREOwKS94NH+aoXNbceAe2OydZehDiooNRLm21uuksYC+3aIN0VhshWopulh.wG8k2283pQZzMj4Pr2kfg8z9hUsOQTvxXNu.FseOJSk5QYf+xoFO8I4rMGXdMZgAO7QxPx.hzUzE8KEi680JZJ...B.IQTPTMRzeeOQu8IIVTvx3fT0+mzNdc6hMkmMVnyNu+M6rIl2XcyVlwPY9k5fYOcX6k5jRNbcbOSbH3qhtzc6q2bckXIsdVJlIJXYbPp5u7NvfkaoPa7nynBN18z46gk6dnpszeqnKopueaN3ejHZ7cARsFIFIwhxFVItYvgXaphtHAao2aYrt66Owt2s8Tl4jrj3QAKk3hVNGT9ByGi7xiBmyJXuG0eAxNjUskl7U0V5o8IlRoxEwCIwhl5HRbPlLymoJlVZ1vJMyqT52mom+PoryzJCEUQWDeBWQ7PCIqDKodVJwEYMxwvHyIKxJmQxsdO+mLcf+5e2kpnKR2REwCIdRAKkXO2Gmsss8xIquQb6tQNxN2BkRALwQaWUzEocAWDOZ6Qv6SjXAMLrwIFFFw6lPb0wl6zYtA78kr+SwDyDHynSEcIU+86HsXU1EugebQorEwCIwhl5HwAopSkgfec6wsKb0rGrZuuU0V5qUzkT02uiVhsuel5VDOjDKJXYbPp5u7Vk6NygX86m5meRh.cOKEQDQBCcOKEQhqz8SVRFnfkhHwcZXVkDcZXXEQDQBC0yx3Dy1PO0a5YfggQb40sY68ZQjXOkMrwAlsr6K595Qq5DIR5XJbb492xE2eHRj97IRzh5YojvKvhoM.EWb7r0j5Zo2qupmSG+b3h6OPJRe9DIZR2yRIglV0IRLDXfsN94P+uWfQ5ymHQaJXojvJbq5DRrQj9mC5mqRxHMLrRRiJpv2+5qXZecw01RprH8OGzOWkjAJXojvJ3UchtaeRzUj9mC5mqRxHMLrRBsM7iKJDaSq5DwZg587P8yl304SjnMM0QhCzTGouPq5DWrdm24chXmq+k+k+E.3e9O83eKWbIkSj978g+ve3KpmuHcGMLrRBNCS2ebQxr+4+7e5+qhLYtZj97IRzhBVJhDw78VwWoKa6Gc+aKfuSAEkjS5dVJhDUM97+3w6lfHWzTOKkDNpVtJhjnQAKkDR5dTJhjHQCCqHhHRXnoNRbfYK6NizudLau+DuEIm5HAJTIySu0O59+EQvVRGzTGQhVTOKkKJM1XizPCMfu4C4Ee.tH84KY26UYIX3Xy7dw6FRD13y+Zh2MAQ5Sz8rT52zR1TLRksDuaAhjxS8rT5WzR1jHRpDErT5yzR1jHRpFMLrxEMsjMkZ5Gc++htbuG+r27D5xw8h+lWNV0jDIpQAKih5wIWeR7Du2N.emmGHDKwRCZPw8yW7jQT51rlIKpe+bqm5ifsjN6nU75c566tLj8nU7+y+WEc+buQLtb54UIgVJCMLrQYd85MjOHI+Q2tDKkfb9hKOv2u7LR9et3g.dHbcQbNRkDoe+WuuJsQ8rLETjZd2szk+I6zRrjuy6EQR9DgOefIYd2M13cCPDQAKkKJZIaJ55CM1EhWmw6VgHhBVJQUZIaJ0xO592lVkQDSIErTh4Fe9e7.R3CIZK1NTzd4sN8YowFeW.vtc6wvqsHQOJXoHRD0Ru2x.BrRLEOaMhDYnrgMIjqJ2DF4sEb0wVXKEZvlNpqd3YIRzWfAJ6nRLEmaThDAnfkIqb145EZKmCbim3TiQDUIlDyMMLrIqbjNVZ+arR5.tiesFfd+R1zm8lm.euU7U6z1hVKYSR7ipDShYhBVlTJcv4tXSaIcFHsP5zBk4DJLd2rtHL97ultTMXjjKAlLOcoRLoD8QRxoggMokMF5f+PL3AOXFzfsQlw6liH3upK0ks00pyjHIaTOKSJ0B3nH9hybljA.3lZcLWNebtUIB3K3Xa2iR0iRwrPAKSV4rEZE7GrrUzxCrjXv.CCCe0+XQLQTvxjUN572lNP79GmZIaRDwrxvq9S.iZRT+KriTER8diPkgru3u4kiYKYSwzpWigQ6q9HoxRT+bejlAFZ0GIEhRvGQDQjvPAKEQDQBCErTDQDILz8rLJJQ8d2DKumkf2PtjMo6Yo4Uh5m6izz8rL0hBVFEkp7KM5Y9d8mRrjMofk.oNetWAKSsnoNhD0okrIQjjc5dVJQUZIaRDwLPAKknFsjMIhXVnggUhYzR1j4jgQzMIsDIQfBVJQMZIaJ0QpPB8Ho1zvvJQUZIaRDwLPScjnnTkTnum4EvH0XIaJEcpijp94bM0QRsnggUhxzR1jHRxOMLrhHhHggBVJhHhDFZXXkHNMUBDQLaTvRIpP2iRQDyDMLrhHhHggBVJhHhDFJXoHhHRXnhRv++s24d7QQ00C7uQySffAj.lnTdqDzDdD4g.RLfhfVMUqnsRzVeEQ7APUfRKf0fHMH8GDDUDU.eDQDAEEELU.ATZ.aLXvRrBEPDRfDbC4AjERj42eraR1Gyr6N6ir6lb994y9AxcN6cNy4d24L268LmqWmVP6eipPiIefXLWRy8f8QZuAo8Vn4OR.93Cnk5923zdRS4+0FutaY7bXR6szdKz7GYZX8xzRc+azxab130cy8QYHs2R6cKi1aAwYoWkVp6eix0s9NVvNx0s9NlPyCjog0GRK08uQ45VttaIPK0q6VpHNK8hzRc+aTttkqa0NVyMZodcKXBYZX8xzRc+aTsqQ0rEM2PZusrLo8Vn4KMIu5Hm7jmzWeJBfvj47BuPSCZ+W9kewepLM4bgW3EB.+xuTm4RZtGzGR6MHs2sTnCcnC9aUvugLMrdcLcyhVZ+HpdZ75t49MMqGo81DR6sPyajogUPPPPPvIHNKEDDDDDbBxzvJH3.hM1Xa3+WVYkZQ4czEKukxzSJHz7FYjkBBBBBBNAIZXEDzf5GUokibzT4czhxscjiJ1HSY9TcTPnojVxQCqLxRAAAAAAmf3rTPPPPPvIHNKEDDDDDbBxZVJH3.jngUPnQj0rTPPPPPPPSjQVJHHHH3RHirTPPPPPPPSjL3ifftv52iRvcVKS4cuTPHXC6GYYcForxJixqxnePcDDDDDDB7vJmkEuiESHgEEc75udZeaihQ9W9HpxeoYBBAnXYF7wznDCogOlJqTKjq9xKqgQTZYD1JHHDbPiNKKaKboiXRj81OFJe62hRMERe+jkyWUbcN3qKHHHHHz7mFVyxu+SVLjVNjw0FuoBhLQV329g9K8RPPPPPHfgFbVdlJqjjFYuIR.pyHFMOfxHiLR+ilIHHHHHDffpu5H680eHhJpnHpnhhE+MxpVJHXIVtljlV+QkF9XpLK2URpu7XsXWLQhFVAgfMZvYYqZaaovOrPLBj3C+VnnTIKMIvHxZVJHHHHzxlFlF1deyS.tuwxh2wnYZWa7.0wYKDnV+mxIHD3gob8pViNTukKHHDbPiSCarigCu4rY5i3RIj9NR5aHsmIQZz6NDkeT8DDDDDD7+Xetgstpn3RM.g0V5XrsyqjhejbCqfffPvOsjyMr16KLznI93i1OnJBBBBBBAlHIRcAAAAAAmf3rTPPPPPvIHNKEDDDDDbBhyRAg.Qp6n7FKXYbHYy+QPHf.wYofPfHFOAKOqbvfjSPDDBHPbVJHXl5L5f7UkwpoZMFkmwpqFUOTcFoZs9RTmlGyX00AgFFsm16XEVPPnICwYoPyN1+ZmKobuKngov7TEtJtsTdRx+TpK+g934RrwFKw04NSbwFKK3i2moCXb+L268QXAK3II1N2M5VmikEroCY9PeL268NSVvLuM5b25FcN1aiMcnpMWi0Q9qZlDabclt0sNSr21BX+UCP07wy7QXlKYIbuwFGcqaclaalqk5Uq5NY9L2ThkN2s3H1NOJ9Rhlv7Q1HAAA8g3rTnYG8529vL9pxhAMk0xwO9NHsQ8DLprlJIGi5x2tdOF17tKhC8S+D6cyKlrt+TXSGsNfZ3+tw2m+Wj2.6tnhXmqd5j087GYGmrNpqVCrwM9JD4vmIEs+8xpmNbOCZobbfiuk+Fi4Ihhct+Rnrx9IV8v9XF5T+XpCvv+484U1sQl3t2KErskyW9JSf0uupANNKJgwv+9VdK16gNDEsskCTkjsIEDBPvajfdDDBvnCjwp1Ik04gRhuO7vu0t4wFxk.TMuws0MdpuzrXCeAbnO3OPaZWTTvqLOd5b+2X.Sip7HFpF5.TECmmZBigtEJvHePlNYw29iUS+i5rPeV.O3XRlHAF4CNcHqoywp9w3vq4U.FNuwK92fZhBNx9fM9iT8KCm0.L249XLjtEIvMvB5CTUc0QcG5qHKFNa9wFCWRj.cuKLb+fkSPPPcDmkBMOIxn4h5Cv9fnBu9IyrMbWu09Is5WXxPij1vQYtIjB4N8kSNq8Y3x5Pc7FozKrZioqNL+KEibVfF2gWOaiqwYcmoAgO2oAl78yDdf9Ss0TKD1efG6+KFpefsmqNilqk53rlKyXMUCDci+fLT4mlBBARHSCqPyPpl09HIxyb0Kmcu4Evhtq9yp1mo0SLx1DCwDi4OsIRvXMbTfQOf9ykECr+crQV99fvant9R1+AOI0UW0ruM81rHFNWSOL61aeGgibxpwX0GmMsxmA5y3oGsoMbsi6dgEsF9gphjN2sNSrgZfu5eV.UqhlVOs4xGJ2AajO8K1GUa7TT3m+o7kfrlkBBAHHO9pPyN12plJS38eX1cI2BcKTXaKNORIkIxku+2z90sLxdwir36kQcW8mEAvXuCFNPDlGYWz.SHkDXB.PeXwadsjbLP0EGAvqPJI7Jlpm97vro0d+DCPL2xyv5l6SysOzDZ3zL7o+Vby.Q.bNKN8M72g1K9qq6oo+2dJjUCGcrdMahfffmg865H9.jccDg.cpq5SQ0DooQaVOFKjaqyOMOyg9.5SnFgHirgmtr58sL51i.GZaYPnUajHs760v2uZptNHxHaiKOqp0Y7TTswPIlXZiGeMIH3sQ10QDDZgSnsow0TrApqV9R9RNCPnQZiyv5NGrOSKmYaTyQI.Q1FzqKuPiLFhQipSPPv+gLxRAAMwHm73USatjNfc9uLdJNd0vkzAMdeTDDZFhLxRAAAUHR5vkn0nFiAsNjffPyOZRFYofPyWL8ymxK2Td3ocsqc9SkQPPvGgLxRAAOjo8jaD.54UbS.PFY3O0FAAAeAx6YoffGfkNJSNYH4jgksL+rRIHH30QbVJH3lTd4k6VGSPPH3CYZXED7Rje9l92C7e+TfqwupKBBBdWDmkBBtIVFLOlbPp9wDDDB9QlFVAAOf4+OrOkzM++wM4GzDAAAeIxqNhffGgBPHMrFkxHJEDZdhLMrBBdDgPHgDBxybJHz7FwYofPKPtfK3BZQ5fOjPBgye9y6uUCgfPDmkBBs.QQQoEqyRAeC9qG.qo5AfDmkBBBBBdL9qG.qo5AfjngUPPPPPvIHNKEDDDDDbBxzvJHHPUe+lXdKb6L1md1bswGIPU7MaYqbPCP2GXpLftDsFey5nre7.bviTLmnbnaW8.Iw3qWViT7+6vTYsVJeTz0d2Ey6OnpeNJdGqjmecUx8m4SPhZcZEDZpQQPPviHX7mQVqyGSYFfRpYucy+coJKMMTfjTROsjT.TxNuRUsdpL+rU.THoTURMIT.TxZ6lksx7TR0zKhpEeRSI+Jc14nTkrSEEl7F8wW2BdSTy1drhJT4XUVqMkVoR9ad8JqYMqWI+CWoMGqJGbLW+75KP54HH3gDLdCXK0YSN7RWoHy2SqlhVgBfxlM66Z6YljBotBE0t0UkGXiJqO+5cxUqx5mLMJaM4qjFnjc91+Mc14n1CjiBjpRdt18KcYBFaqBVvRaaMUVpRQaOGE.kLyyfER4nGR5DJu7s5ZOjlVmWeIxZVJHzhFi7YKbRPlYPuMunL6OuODRJa5erl969cyO.r0Oj8Wk8e6n6wX3VGfYAITt79lF7yURcVJTX1+8b14HzdbCjEak4s1u2KbMJzTy2tnNRBiX7.vEYQ6uwu+SXBqG1boeKu0G9sr8LShIMiOgp.L98eJOxGo9wBDPbVJHzRl5NF+y2Fx4tGXikUYkvP5J0ubgQeIWNPkTqZeeqpqej0beqmzlxnoc.TasTIvjRpsz291Wtm+xh4aJqNW7bDK20Zxf0u4uCid9UoPSL8YBGlCbf7YFfUseN5gj1ede.j3hboGRyefDfOBBsjolSRdjJO7kFYCEUKPRWY2Z7lCs+RIUmUO08iL+Q2UlcpKkR+i81TYQ2Gd0BKhPu31B0bbV+eKYRtiGmCq7btz4nSWwUBu8Aol2BhDgfIhN1tPzw1I5RRPEVd.UeHoOjZABqhJgqoapdr.AjQVJHHXEgEAT3VxugQDT2wxmshpylpoiW1t3gCqqL89lCF1xCSrMbjnoGI1a5R7wSW5w.3I9aq.3S33Uo+ygPvH0xYsqDseHoZARrO57gzZBQbVJHzRln5.Cgsx2erFmrrdc8OHr96iM78kCTNe5RtOHsGj9nxqwQ4ey6PXcbHrrImCGd1ik5JqXJt3xvHfw+2lXkeztnrxqBiU8i7NK49fjlH8IZW6bbr+6WCo2cj2djfWh.vxIvzQOjTXQ.6MP9AnZRBiHAglwDL9ynF04ZTxIMTXFa2pim+JlrEutGYnjWo1F9+lnvkltMuZHzPTrVyAViMkmgxlObMt34nTkr.kzVQQ9nqaAuMVZaqslZTpoliojURnLiMeXkZq0TaaMGvTDxtlhLnnnXvTzSmVNJ0nnnTy909Xt540WhzyQPvCIX7FvVpy0eCr0eLqcHVakFTJsTCN8lUNlZUpoRCJFLn96.hVmiiswIa0qyh2hfw1pfErz1le1oY8CJkZ1J0+Bj3nGRxUeHMsNu9RjM+YAAOjfw8yRa04sLm9xnl8PnvJeE+dVyopu+cnsILdlwFOFO2Xh2qV2AisUAKnGaacUUNkaDhN11YWva4ni4omWOAwYoffGRv3MfsWmMRY+nABsSwS67ygdpwxKCC0DJwGe6750cvXaUvB9Kaq3rTPHHgfwa.GLpydCZodc2TPycmkRzvJHHHHH3DjjRffffffGSHgDRS1Fwrsm2lBDmkBBBBBdLm+7mWmeiFm5zxK+T.P6Zm2ecp8VHNKEDDDD7aLsmbi.POuhaB.xHC+o1nMR.9HH3gDLFzHWvEbAAc5r2fPBID2XDPB9FTrxQYxIapz7yOvzgoLxRAgVf3+bXnXwTtECPS+ZbIDXP88CT+XkGvMkrhyRAAglLBVlxMgldxOeS+6A9ueJv03W0E0PbVJHHzjvzdxOEv5obaYKSbX1RESyrfIL4fzxiEXMpRPdOKEDDZBn7xK2sNlPyal++XrpT1M4GzDmiLxRAAglbBzmxMglNl++3lZ3AlBDGQY8HNKEDD74X4MACFlxMglBLEbWAKQStLMrBBBMIn1zqEnNkaBB1h7dVJH3gDr7jwAJz3TtIu5HsDQszSWvvuejogUPPnIC4AKDffCmi1h3rTPnYB9ijXsfPKEDmkBBMiHX7I1EDBFPVyRgfLL0cMPYWJv50eCZ5WCNwdXMh8vZD6g2BYjkBAcDnjxzrLizXRO7OO2oXOrUOD6g05gXO7FHu5HBAUX6tTPxIaJko0zqGVm51LoGM8OkrXOrUOD6g05gXO7VHNKEBZHPIkoI5gnGhdD7oGdJxzvJDzRfRJSSzCQOD8H3SOzKhyRgfFBTRYZhdH5gnGAe5gmhLMrBAUDnrKEndpaydcy2qGh8vYmSwdXaYsbsGdBxqNhft4fG7fNUlksrkQVYkUSf1HHHH3dDRHgv4O+4cIYkQVJ3Vzidzc5QO5NG7fGzpO0WNX5EjW9z78SwEWL.TbwEGPHeKsOdh8rlJqjZj1WTTb8wJJNKE7Htga35U8+K3ZblybFep7szvWaeZNX+OMUvxFdZryfm.Q0swa1dINKEbK9m+yOug++MbCWuUNJs7XBZS4kWNsu8s2kCed8JeKM701mfe6+oAf2snxosc6RIrl4g2o2t8RbVJ31nlSQwQoqiQiF4rm8rXznQeh7szvWaeBNs+0QUUUNUYrtFJoMgEEgSUTtgp7i5kuGuc6k3rTPnYLMGl1PeIAZ1Guo978aZwLxPBi1111SaiJLl1qsG.XYebt70GZ8jVWaKK9aBtbX5OauDmkBtMpsFkx5VF3Pf8zFZ+Hdbb4deBzrOdS84aV48PBicRrUKJ6sm8T.fhd9oyhJzTYFq0Ss+5scz8ae82sWhyRA2BaWiRaWCy.UBzFIguDOcZnLVUU3Klvw8u0WiqyhQ77vKdGXD0FITd9fydiDnMsp0qOm5m+Y2xtarppnXCFnjCsEl6881pHwQs5uFyCMGFT6azokds+ZIuup80e2dINKE7HrzIYf95U5uexzfEJ+G+Qphx8YQLYJie1rMK96kMomlUuT0FIzB79m7.Xp3nlblkys9GzkcuhidTphxYIC8WSWiKdhu6ih04BeuM8pyhwjXm4Lm4LZLRTss+NR9lqsuMyiGJAeAKaYKioOcS++O2F+iSe5AtNLcmmL8Lm4LzpV0Jel7AZblyTJuUW6J09u1ipQLowppBhNZhTkuq5GqNppppfvhFL9MZdde2GQsQBEs9u.Bvv06OTEu+fFD.zltDmlQppZ132ePCh1V3AnC83WwG9IeH8+WJfGyNGloSNa69Y7oLR9qq6SI9k85zyk8BLv1DIs5B9erPUGIZi1eqNuF2qFx+KZd00bn8UbVJnaxJqrz0KyavJkWd4DWbwQIkThKkCK0q7AZTd4kSbWRmYFWI7C+wIRW6QrzICltIY4+3ORncosrhg+a4p9hsvHs3xqhidTZSbQZ2w99MsXlnEilH8YNW0OwWYxv+Yq1WdBCCJ5y7pWiMkn69CI.TDDNm1TjpFciNSbj8mDf1ZNBWqSIThqaijE8UeHi3K2E49+8dzuk7d7T2w.vXIG..Z6EECs5rqk+9+2HXA+kIR6psVTMLeLa+OMUvZF93a77pk7WwUA+2cYe4MSZekogUPPCZo8pcXz3OyYO24nvZfcDxuv9+w5iXxR3s5ZWYE60fpi178Gzfr6XpNMcO6pU4rdej+meuzA6JOC1zZePu10l+.80eHJZi4+2d9wMYSjpVkCs+sAXgq4isHBWKgOXX+FBYrO.iaHWCi4FG.sC.ikA.SeTCk6aqvVWzj3yOXUPXgoxX7xfMs1eOfJuWlZI+6dWpbc07o8UFYofffYLErG4cPnX1E+j4RMVacDYRMN5EaG0ioQ1DFmuNC7CEcH5YrGRi.L4msqjG7098bAG+WXBe5aRW1z+BC0dgDaOShTF40P6O6I.fSbhSzf7QFYjAkiZ2wTG6ZkylkUjo+5UM+uVEopMX+qjh+oehp5dbTe60xJBJZ1S.yA3JkVxwHxDf1bpp3Lm8jbvu+.zyKCdw6Zn1cl+4e5vTxu5RX16dCj352Fm7bgxkbEIyHF4fHzJL0C37UTMm4rkx99l+MWTrskXaWGrP9voK86ZY.8Kd92q34rq9u2WZbMaZeEmkBBBVQwV7+S7tyhqu6wRgXZzKi7PqmE001R14WIiKNSxb5SCOdBcgpA3S5tCp4iYWIu1CNZdMmnO8u+8ug+eDQDAFLXHndcgsmZXOu47nHKJIsImMWe2q+ARhh1B72etovYV+GwOs9OB.ROyb.vpu2EbgWHy8WOPS+wHLa21Tuz7LO+wM.luSztm91Gs45IWW4hwJdyIdS7lNQlfk1WYZXEZVfu50bnoC0d+ypipppLJ4jk0D7dGVGeypy1tRS8QuOp8SxjEVHT3rmPCuedUTsQpejM+8ifIGkMPhbc1US2FoaJ9UXb+o+DigqlWeaaiMusujBJn.dmmQssMpqF.x6q9JJZ+6mCVbwTRIkXyMRU+81Su8GLVUUbJU+N568BzQmWGcrHZai++eKCkY+7OACH1Po9Qc9bEB+2258ZXz9.71ydwM7+mQN4P5jJatjRXCK7wIAap+ott8xG8hSViy9PYQ+8aWkxiSS42vOTLEWbwTbwGge3G1GecA4wSY+.WMyUSl+EsaeKnfBLWWp09pW7cumthyRgfZ70ulCMEr+s9ZV89m8vKdG7saZwLjPBi111NR7w1QZaTgwS5SeuCqg+yZVpUkjbOtZFb2Bi87lyqgo3qdlcJcjoszUoQc0Ml8+IOVZVYRlYlE4rw7wfx53utDSiL4jqZMTD+adfTRgQkxv4k272xZe5OUk5wzM71vC9mXI+lL3PQFmUSQmVu2d5MQgW7QKhWX32Ly7Zr96nm2KPG0Or9WsCs0on4O9gkxTM+WibLV5jpF1yJmG6W0yZL.vTA5x.FFiMsKk11tH4nezKX0nMA34u8D48NwuRCsOB1zeVsW1jRzP9XoCWRbTw2tFFe7+Jt7KuOLv9ODN90+rZHezrymSs12KF.5Tm5DwEWbDWbw4QSAqu98zUlFVgfXLE3CT3ABhRLzV7pTXlTF+rsRhkMowwx3D19EYUtz6kl80uqR3lGcSpWJbliMDFamyiWa9uJon16IBvam4ao9ARZTbU8YvjZeFbi5iwSw6OHSSm2VK4mrR7k8TYykoZEYJ8rsu1GCWQLwZU662rx6gjsYcQe6YaZ+S8cKpbtLM6OXo8wThEe1CZTDSpoQWZUzVEfR1W+ZY+cb+v5e0NbbezHoCliF1yU4Z4ol5h3YdhwS+hKLhnMZ7ULGMocHAfZMRkFdal7e5pXTZ1dsb0OvUlLUpVzppEIMRpds2CCwV6Sluq5xeUISHem6FMrtV+Y80d4dHirTH3FaC7j.DTaJ2r8Ieerm+U03aauiRSX500469tui8rm8PQEUjUIXAO6Iqil6Z46E.B6XvtHO9aeAr0EMMp6gdC5ipeG0t8QZjyKLBN1d1CevKNcFXC5S63MiQqy8IUIzeZjJp337CGe+r0O5iXaaaaNHC0DNP8Ajho.aww1mcC.QzCH5KvHmq1x4HG7GcZ8ehSbBJojRnjRJow52Q8CSvE5iZrTNo4gCNkcBacQSgQz8NRaipcr4jeV6lVUHcxYo2B.TPQvDRp27H6.1wK7mYsw7Dn9pTp16AYJ7bO7uvOnp7ps9yovRlQj7bpZeT+Z6pSnJpvtRGCu3bGBPi8m2yd1CG5PGpAIzgLmoB..f.PRDEDUbk9yFbXFKxAsWtCJBB5j.mtM0prhjPIoLWpxjSBE.kryuRMkt3hKVAPo3hK1kpc2U98WbQJYmTpJa1PiGK+UjtBl714U+Dd3gqb5SeZMp+gpS8eO9Dcze9IzvivA1mqQAPI9XQoCcx8p+HhHBkSe5JTseX88GVXBNqOZkJKMU+usJP4SYkUlK0e9zm9zJQDQDtQ60oavxCt98xjQVJDjho.ev1.OwySLzdBZreApYFO4pUorTXfpV22Bu35Lsle4latTPAEv912933G+3tTFXwkv3Isqne2auWJtn2RkQVlFKwr97Gr4HS50VNpENGpyP4duigQT1U9kYdEsrlI7xqg4.zW6Nx34Y9y2uckN00sWGXeNN.TbYvIsXv7+008gXe3tLdxYaE..ETvWyO7C6kB16d4GNzgXuu2eWi9gM9pcncez5nppNEUbdUTuF3ZY71Txje2Bnf7zJNSSjNaWY2Hy80LsFyqZUqhbyMWxM2b4Mdi2fU8lymgYm7WG+448L1U5cN6Wlb2vqvHs6HifquGZo+IybV9pXUqZUrpUkCKe4uFqdceH4lai8my6q1Fa8q1FEtuefNzlRboLJzEzpVQIkTBEevMqR6U5Vzd4kBfHW1spffYzW2lJU19JxVIyrWuxwp0apE1+z3oM4rUxuzFOIEswrUR0himdlqypmL0Yn+QVteSijX6EnjSZoor9CadDDUluRZp8jtIjoBfRV+0opjYlYojyFyWwfhhRkGNOkEMiLTtkQOZk63ddBkkYtbM0GmT+tl9WoRVC0953OsihUcTOyK+Ja3501OCcRKQ4Vb1S3aw++Z6kqMpfTd3EpjeokqjcRn7xadCJ2+U1ak69OkoY6l55OfRFy+0TWeBWc4+MycqJkc37T9aOvMozMU5+zeajeX1n+02OTM6ik8Qss+oleZi5k2yQ+ntr7yyhQ5pV+gJObdJKMqLsnen51y5GUbkpXeR62eypqOIksRopb8Vu8bi4LCkd4JsWl6Oq1L2Xu96Z+9UO2KSbVJnazSGrBWZiSmRZKsPunVToxJRyT8NibxQIcRUIeKbF6clVR85r7HJ.JIL0rrdJ2poPkzsSWxPYS6yKMsvdk5uRk4X9liw2JS+6ibM2rx1qrRkrM6rLIyWS0+P.Z4rDFnxXbEm.t3mqfKW4lZn8UqoduRkENFspiApbM55blpxa7xp0+oCN76Ya+PKsO1dLWeZ4uOkmZ3Zcr13P4su8x85OjPBVWOZq+IoRYYnjuAsjev5n+SFJaZelrmyYy6TYEoktx10dEWb4qW8burfh3GTHHkp1EyZBMNcJqeBKgu+O7JzaMhVO8govs+mBoizwALLtpz1HfoE7+rUrGmtf+0i8YLD8FMo0KeT7Mq94ALseAVen6a3jkQIk2A6xPJ8c.WNm+neGfo.b3Dm3DTQEUPUUUEQDQDVT+mmZp4LDdTwvEZdZ8pW9HhHBhHhHHpnrOipLxTShydBWICoz306ndzYxr14yR+NCjxM8aouidDDR40x.evYBa8YY7KY27vYOONW4GkO+P+Lm7m9WZXSNOW8yOGtz8T.FNCDSmSftbYgyWMsml+opxeoDCGiSoQscwWQTDcapkOa04vV+50yqWHTTgMlwZN5A2GecHshq7wV.romRkZ3bTiF0s5bB9GOxVUob6mlZSLLtc9JtfnZG845hj8k+tH1eU2ITZMPiuZGWUZajJLXfRNsV8OMwcL7AxEz6gR+52f4R5TXT4Wc.3K2gJRFB.zOfeYT2N8JzyQu+MifKu7KD9xWiTmzayM8NKmeHuOm2K+KfyeNSVgsssswEewllj6idziRTQY+jfetycNN+.tMXme.8abOKiZKahB25mvQp9jzgKpFVhp5uo211q3pGDso5pH1jGEW9k1Jx8EmLqZVpIuV1yVysu12jj29+BCmKb57UNXF4H6GQb1RArN.ttzK9BTU+gF6260xPPtraUAAy3pcaJpgmlLMkLyZFlGEfAm+EcYpTYoIgxRK7.JqHUTFwi97JgEd35ZTKVtf+5cZasU9A2Mqq6a1MzGe8GGe8tFE.koLm4p7WF9spj6w0e.THeZ7yuaVuqBfRVIXpO5RGAJWvEFpeWuZI+wSBvmPL+EDDbYBIjPbgccjp3ctm1x3eaXFa7X7biId1076KYD4J3aehA3cTDi+OlST8DKeKEe5bOHObOOjFaQQOIiOk9SAET.cpScBnwmzTs2SKXn.6jhKtXhKNqylIpKuId7W7Eo7G88YJ0tE5VUkiQiFovU+XLloX6K9cR.ERt4lKwFarTYkURUUUEgGd3r+b+67nKXKNT9HhHBhLxHIxHUen5m3Dmf92e8b8NXfcwL+rBXzGZ6Dyc+DbY0UNFM9yLq36EutcmgtAbHaJKUdz+3Y4EW4NUUmrmj39djdyG9xuGtRP8O7qB9xuCtq6Yfr525qs4ncE3v1T1n4EW0ukU96eXrUZsXniMI14FsMMLzF5JUaWsC2Huy+7QYc2vsx6aeMArSlJvyaQoybceH661+M1z+bbrj08P7X29nan8EfCdvCx4JeK7fO3KZN7wpm33ONmYwJm0D4kdoWpgQKctycNhKtX3kFcZ7g1oOldQNW0pVUCirrjRJgvCObKj47XzXMbte4B4WN2oXhSbJba+44QRk88zpgOFhtlxocsoZVx8NM9Jqp6gvebJoxJW37XFyXFz11Z5k1shJpfKp00vxmU1pjXEtHvtWpjqib11BoOMjQipiyblyP3s5hnnOZwbuOs0uqnSesEvjtlNYQI0Q0UWMDZa3zU7yZ1+udbs6kYF27Q5EZAiq0swf405ZFJG1bIElcpJIkUddIsP8vs2x.PvkWveUWyOTfaTmxmpoQRr8cqjSZo23Zn50peMjWCbz06c5f5+y16QrS9esCjeJ2YZJSX5yyjcVSc29O2PV6PwfRkJKMEWejAYm+AUxDTFrKJ+7Lulw2kNF8wUqZ4oorluXClz6TRwh.uxQ5+nz3ZnRcGPJaNqIpL1qOUkQNxaR4QmSNJGzIsuNp8xUmoj5mYE65Onn+ee4J1+jusmRYqNH.8rcla7FAzmdbAJNKEzMtTGrZJRYxfRpYmeCEke1opPpqPwIqKuKh1AdhV3YQSZsJUVoAkJqoVGH+LM4rby6TYEohx0Nw4or8iTi9iVUuRzs5nq2cnjnuRezRVa9LoQeWlCPiJUx9ZcMmXlZeqTYoWIJ8UMYLGXR0GPJu6+4HNt8pUpbN9O6PcYupEprWUsmNP+M2evU6iZc6kE82zc6q96+3SCHNszmnM8uO9K9htX.5oW4GpSsm5wYoDfOBtEkThV4MRyb5ivtAFVOZkYYOJqbRaEFysxIJoDaR71tGVG3IYwEVa0TRIZWypsf+.fwSoRdeLcdmkdKb2oLaxacKhE7Xym5mXwze5EYNzJrlQlZqYKEYZ+BD.15LXDuzLzV9a3RYKE4p5iCjWCz95sBUx8NMd8pW6iUxqgtCC.3a.f6HkQQ3muByacTslAd+Y.6XYZJ+uIkToWwzdSsuG5v7+9Ov2pxY3Ztgww+Z8qgTtiIvuLmkxu6JMkKT0x92odbcbh89E.vuezikKKpVwEd9yot9+cSgmdQllaPasOpq+vHugtwVLGoWtRez5qW65uMmOfLefAisS1t61e1d4KRiLxi8ADmiP25yFtet6TFIsMttQuGS64jkTBkDpizmgA7U5PdS5uqZOcFxZVJnaBID0t0ifffPvGtpKPYjkBtEVtn4pyoY02Qun5+9Q3AZ2NXTINdJBH8WcmL+atqdIs3z7Rw2K3yJfj2yFns29CPBs1VYpiSe5SCWXqoZUVve6wB4KMO5+PtSUjYXjJeEa0k0Ssj+5.9B60GiEwi28QwZcU40.0BvGSaEWOOScJVuyTLyMTD+1K0n9rOtj8rdpfoDeBrZaJclanHl3.B0h1w0SX23cwUzV3E6dBrHfw8.Sjg0k3Hwe+uic9G5EyZmpGZHVNZTqo+zIJPkLta6ALvvA59SLMFPGhlD+8O.Ibg5z9a7a3F69ul8pg7SFnMZ1G0U5uMF1v9WNCn01Hutr+Z0e.M5uMddms8Tb2MDPbWbCm2VGo5tMzr90ReNx+l9Oja0pxl4FJhI1mhUQeRm24edmb22fqJ+34cxMMt6Q6X6Y7wGuS0yFvkmvVAAyfKtNFEtzzURaFYYQ.ejpxlK06pKEt90X0h7aId5qBR5ybAputIW0SoLV0JuyCUex6WVyRsy7QN6k31yxHRUpLkdq94UQwT63Ze2EZU8+qu6op.VGfIGXiYo.ZrlkWwDzXsCuGkNpV4QLVE.kk9BK059PtwZLqZl3wr7adkupp8Qc49aNIC33MRxFpkQdpu92VNYZ04Mir2tRM5r9sGmmgf7zLJjyrmJJR.9H3iwkcVls0YzijxbyMAZmIza.Knt78UkxxPI+hUOi4jewEnRTZps7Zlgc7oY7Gsy7QN5lcdd.fzXF1w8BPi5oVkUjhZQCaFJapfMqd60gVqU2D0zmDTVRddI6uazdoq9aZlAb7dYjJGU+1+IUk7TINk7lYHn5olJqzriY2IiBos8rdziyRYZXEbKb1h9+y650IoIY46p1X34FWBNOvf7Fn2.VPS4M89X8Wmziv4B+hoq86ZYjolHWDvSu6MPhez13jmMBKJ+zjBvE+fOBWzQ9ez865II8wps7F0JfHnCVHeXDWuSlQj5.4BqvR4qyklVL0p+a7k2KSc8IRLctWbYiIF9oC78z1HLMsd5y9nu..45l2VfMom.5Ps5+z7+1Fjxa9lz+2ckXrWCkANHqsmp0d8Fu9LYAuy+juKuefd8fOKYN8aiv8Z1eKk+Bo8cMAF1HuVh1nVA7hN6ucpsvi6SC.GszmZ0nlhfSdhRv13TRy5WC563mLryEwsO2Ok3y40sJ3mp3nGkPurn4cG08SWdqky0z9Vai7uJm6TGiCb9VSqY+5ydZrDbmaCIA3iftQBvGAAglK3pt.kQVJ3Vn4h3+y6h6HwaCKyeKILmMyle.629Z8YnZ.KjNuy1dRKBXAmEfCNPduDNJfH16pebtwoXaHlb0.+aUpogxF1+6aN.Pbg523g4O28gh8avSlpeek8Q2AzgdqeMsmmlWeT8h17JEP3O2Ln0Y9BL5Kq0dU6+SMtixBVyQro7nApxysmdj82EBHHsp++4sxceC1FfLoymUz7IwKRG0uFbhSbH5e+GFS9cxkT9ocYQvOcZlyU2Kd4hs8azefBTol5GoxdrI.5br8Q81WGi3rTvsnScpS1kB3fxX9i2RGkoRFo+yzpd2EUj0WRbrhCmG2vpykROaDziAd8L1wL.LZdtWrW20q7dWrq9MtWllp+PNbUJCfXoCcJNhSib+t00eU7JWmZNJALuCR5arOUwacG2pckFabWJw0sd6Us+1KecbYgAK7K1Eir3MwhFTuH67qjwEmFxqa6es7N14nDfn.pxKXOcO6+2uoEyDG6jZvIR5YtN2p9y5uNUNaDcngxamtqeGyXSr2L5e+MzXAF2C6wNGk.prqmZhtvr9OKk6ZCtn8Qy1WmfKu5lBBlAsBRfkZ8hrmyATTTNVNJIkwFa5URUP+a4V5Sdul9nUzXpUzdZQz8YYlJQq.7Q6LNiqDssNq90BWKfNbI6itjuVk7VwLTRxlq0rxyf2y96jns02skv4KCHK+U8WqRdu78ozVeV+eE6ZecUjQVJ3VX6h3a7.e.Iaw1w0Teu8RpsZO7Fu9WPgK6UYXemorZS2G13Hi6+2ROunl9td5M.Dzq7dM8QqLdxRFI28MrT6J+yV83ntRJgcr0Wm+73mUCir+1m1qqZ8qcFmwwYHnC3h0uV3n.5PM7NsWmls8pyCqB0rGZNzuVWMm3DZEPSZjAkFUbrk+qsklNe1JRgGZHukMk2Kdt08b7Wt4M5y5uo+.1wWGPPdi5+zrs2XETocROduV+esyxTNFI.eDzMR.9HHHzbAW0EnLxRA2BqVz75NLy6WMTdA.Hc199eB93dMHq1Vhf52ffpmgxGTz6yfuHZxP2YXDcJueSezaF+wIYbFeWFERq.5PK48VsW+LKL9DoCae2zlmKK54xdARLTun8zmq+VhGDvNdq.lxkx3OAGsWRF7QvmB1tN.VrF.Yr9CqTY9Y2vKu75OfAk7yJMkYr4RUTTpQIublQCqUPpYs8lT8NnYMK0q7d4LNiuNiBo1V9jttd0s7VuIgmpyxXQ95c8E2Td8jAez6V.ld0GGkweBlZuziKP627ADDzKgYJH4gj3tt1tvw9ZSaZw4Tz54V6Q6naWSx7Ie92CDIC9teNNvZlL.r0MUfKsg+J3DBKLrOPXyfMs1GTS4uTcJutpemPhWbS7DZYrTJsPXBI0StusBacQShO+fUos7d4qWuAeyJuGRvhHOEf2d1KPS4itKClGdZyhYMqowcaQDr5sX+acI72d8O0ps9aGoO5h.z1KYZXEbKrZQyO8I4j.Pu.ikPYUTFvLY.Wj4.3nc8fZ+vswAd7dRqAZ0v9CLyDVDO6YMxOWRIXrIVmC3CvGcKeG7AYHHOQdKw5oMz6KeinU.i7V2QuX11H64p3m4DmnZMpe8ZO0i93Fx6qCXm.J8w+0d4Lj.7QP2HA3iffPyEbUWfxHKEbKrcQyOZtOMC5O9pLzo9A79SoSLs3GJWwF1KOv.tX.ir56+lI7Y+IbacMRfix7heP7BiYgr+keW3fX7vqRvY.93C1RlvwYnlfA4UCstdO7VeIF53eVxZ66l1j87niy54nes06ZOce4C.BXG8JuF5ymUz7oGgcFZUqZkSqaGU+dV6k998hDfOB9TP0EMuTkrMu0OMiMdXEECaWIUPYFquPEEEEkByNUkIuQSu5v4uhLLI2lOVSpdGrEfO9rsjIU2kLPAtwfC4060qRsJqHUT9au7rTtBeR.o3dxGHEvN5Ud0zG8h2t8xc1R9ziKPwYoftQyNfUVnxjqOpXW51UJ0vgUVSVYnjVlaT4v4msRRouTk0jk4L+wjWihiyeKdeBlbV5Sy.KtQzy5UjuOySI7HhPwfACdV8q2qWkJUdBUcF68xnM5UdecF1w8kWqLfSik6Y3JY.J82d4IaIetJxzvJ3Vn9hl2Al1QJfd87yfGcBifkMA3gl5LIwH9TlPxu.EBLNfG+E2.S41F.UWRInc9aw2oyA7A3iOOCrnQFBZo2B2cJy1mI+ms1+.8HrwgQiFsdqZSu0uF3H649T8azbL.Ybe40JCMk25VDK3wleCkm9b9.x7AFLQ5RmUmW+db6kWaK4ywHA3iftQBvGAAglK3pt.kQVJ3Vn+fdoNV88mAc74WNodw9L0xgDXDfO95.5v2DPPdi520Pu0u6ZO8lYbFug9DnEvN.LPfuVkZZLrg8ub61R3zDcmgozY6kWYKOyEPWS2rPPNUprzTQI678rUKDWZcRpQoxJqTwxk3H+rRSIy7bmPAv6f+dMK80AzgOKff7R0uyvcBPC8XO8cYbF2SeBXBXGOZWtwEvMVSZ81doW6Y80udbAJNKaQQkJYmDJYkum4vxY+.0PgqwhaZjjxRyyTTuZX6YpjV146QmaOA+oyxf2sLIuW86H7j.zvWHuZDbFvNtf7pFMxYnroB1rJWSYnn6aenU8uu.i9ytJxzvJ3koJV+rFmEokqBYBY71bme6zH536ArwR8i5VSOFLXfyVwdXttX.HDYjQR6ZmqmbxZoU+0TSMDUHG1mIefl8wWiACF3rmsCL6cuARb8aiSdtvoK86ZY.8qyT8wNF.7DO38Rsg0N57UNXF4H6GwYrDrL9r.sutzp9GYpIwYUIfi7usWNFwYof2k5LPo1tYzUXIXnNncsu8vOY.iftijtfQNyYNCwGe7b1ydVMj3K.f92+92PIQDQDXvfAW5E6tkX86X7b4CjrO9Zbt9ahE+ZuoSqK0ttb05Ovo8xwHIRcAuKg1dZXW2JojL8uS9FoGgBa44GKGZfI1hvQI.spUshRJoDJ9fala2tilN4rsB.LErTEWbwTbwESIkThKeiTmU+aZeEyANvAZnt810uuV+Uq9O3AOnWS9.c6iulFzeKt9q+y9129H2byE.xM2bofBJfBJn.1291mpxq10kip+hKtXJn.Ou8060d4bjQV1BiH.LVqu7LDM24BVJSH4I.EVHjV1TzTSf2+uzWF27xfBqIQe4IOfi10t1AsajrxCmGid04RomMB5w.udF6XF.FMOWVcpSch3hKNud86MlrO+o9qc82Muh7AC1GeMZMElwEWbDSLw..W0UcUdV6qSvyae0o9XQ60DltsorcGfKu5lBAoTix1WwJT19wpUQQoTkY.JqnnZ7nZDWXQ1MT35UlbZI0vhnm1LVgxg8rSqGimkASD8wSkO3Tezq828au7M0uuVebeBDze83BTFYYydBEJ8MYDW58Y5OSMaJs2d9DgpcVCwHE8kalstiB4Wt7aj4j03o8cpaz+AODBu7RnDM9VME3tYvD+0VzUfl93oxGroO5096osWd69C9Z8wSwW2+2Upe8fjAeZgPUkULFpML5T7w5wqYnjAeDDDZtfq5BTbVJnaBIjPTIqgXjO3w6NO5ZeH1bQOCIXNJeLdhcwT6+s0P1xXpu2dYJCuNdo6n+7r6DdnWc67L2bOaRza8mAStNTMCizrRe70Y7mfP8wqjwYbf7ZfWq+fuVe7R3q6+6p0uK6BzkmvVAAyfZqCvw1nRRfBoloRgkZcl6oxBWgEuXwyP4.kZYF8XF5Kaf3An6LXhV6RF9K8Qm6BGNCecF+InUe706JK5U+8V6hK5r+reaMKahsmtJxqNhfWgx99ulBAXqylj5XaIpv5Ku+OZD.htWIS5MH473y+ov32XtfLx42SrM8pq0DVXDscElA4+k+YJ2fgl9WhbMzmMs1GzqcJ9lUdOjvXmjEIOB3sm8B7Z0ePs9nW6uut8Ru8OCz5OqW7K1SmiDfOBtE1tn4EU32ZiDExqu5cxvtmD.hhjGC71axzQ9x7pl4O+ho34a5uKw1zAhOBsWv+NvSu6MPhez13jmMB5Z+tVFYpIxEYrDpvHTQEUDPnOF8VAbgeZKhJnQezs826zd485e5c5O6+BvmlN64ze1m2k0WYMKEzMR.9HHHzbAW0EnLxRA2B0Vj8i9MeBqY86lSQjzyAcib627.n0.Twt39S31v7.KIqOHG18sMdSKv9XVH6e42Et5t8imfuNfE705iuM.VRmOqn4SOB6LtbFQwWqO95srJ8hut8JXu+out98ExGe7w6x5q3rTvsPsrnQb27Cx.uY6WWgxNvOzfiRHCF6vRj8V+eFQLzo3hysVCA2k.sLphd0GOW+iiUb373F7RYzFek93tYrEec6quVeB16e5qqe+k8TbVJ3ioNxec4zveMiM9WHwX6B+eEkGi6GNMW40NBerix5npppBBqozcriHvPehtKClGdZC1upCVhZ5i+LAVzzQfQ+g.WBbrOhyRA2BWdQ++4uj4rnBAfDdnUxiz2vMEPOWzuhANP.ikY218i2hl5LfiuVe70AbgdwemgWB10m.s9m1h+1dFn86EI.eDzMR.9HHHzbAI.eD7o3zEYutixK86FDO6NgwLyb3klXpMcaMW9oLxiuVej..oYh9Dn0+TCZ1lAer.I.eD743nEMutx1ESM9gvh.xZiEwzFSuaZUtpJg5Tq7DFITzWzzG.EdY8QB.jfb8Qq9C84FI7+2+htzktDPk3.ZxsmAn+dQxfOBdQLx279ygv53PXQokI4erZZ5cTBMIY.GcQfl9H3eIXOC63qI.82KxHKEbKrdQyMRQacMLqwOc1ICkE9d6j6Z3cEnbeVv63X7wY.G+j9HA3SyE8w+jwnzKMeyfOtGR.9Hnaj.7QPPn4BR.9H3SIPIHDzCA6AHSvt96qq+VZ5iuA2eKRyyp+KtgxacjgZmrsNxPkL3iPvIAZAYhdHPS2CzBfE8R.e.0zLWe7V78aZwLQK14WROy0A38zesp+J22Gyep+ytgxyH6syDu7BXJVHaFYuc9yiqmtk9HYvGAAA+.95LphV0eikGcjxss717Mq7dHYa14W7laQZNp9SY7y1pxW1jFGKiSXSYOM25XyA+IRuNA2h.kfLQODrGfL9a82WmwYzp9yacKhE7XyugxSeNe.Y9.C1t2a2fm.7I.CuzVjl9q+Z03Kn14KBLTlDfOBAYHA3iffPyEj.7QvmRwEWr+VEzMAZAbQPS.i3qy3LZV+CD3qU4KLF1v9WNCvl80MI.ebS7RaYa5t92y8wK0uQw5sp7eMihMvlUQW5nQI.eDBBIXHfEzh.s.tHfOfQ70YbFMyXKClKnnulyaa4IMVFTOiiX0n5j.7Qu3c2x1zS8eMGNOdGaJOzebW1UV6fFdmsk.7QPPHvDGjwY5cDOgmOxCsp+MmAOe7Kg201x+hmPSGkBtG95srMspeUKO.a6iqdDmkBMqvfACb1ydVUOlZK3ejQFoOM8hoW8olZpgnhJJ6js7xKmicriA.e228cM7chHhHHlXhwN48pWWQlHuzgyigq5HO7PGkNo9W1gyiqyhxGxf5JQYrDUyLTdi1WuU6k2ReZoQfr8WBvGAcSHgDhKun3MkblybFZe6aul+XSMhHhHvfACd9ni7R5i2Be40k+Bec6aSQ6Uyw1EuE9C6udtWl3rTP2Dn5rDLMBLiFMZQI0Q0UWMDZa3zpjQR70Ooud0GiFMRjQFocxWwoqixK63L5QOZxM2bI1XaGm4LmgvaU64R6zEa24s45HX70sudq1K+U+sfcZps+55dYJBB5jfktMEswrURETv7mzybcJ.JEWbwAE5iVxusbxzpxyH6sqTSS70Rf.951WuU6k+p+VvNME1e8burfi65IDPQvfyx7WQ5M7ilF+LT+1Muzq93H4s+SpJ4UYS9kjeEec6q2r8RbVpeZpr+54dYR.9HzrBCFLvYqXOLWWLijzjDfO5PepolZHpPNrFxWsFmkv4jGuDJwhC2bc5tkBQLa..f.OkDQAQ070sud21ql99aA6DHa+k0rTP2DntlkR.9zHMGCjDI.eZdiDfOBM6HP0YIXN.ANUA7XceTrNqNR5ro8Me5Y3VmQRZRBvGcnOFMZjH4PpH+3HmbGGu4nuS9LqJ+NYS6aQjjMu8HMWGAiut8060d4e5uErSSs8WbVJ3SIP1YY8TkFYAjfE8QK4Cztt7W3qsCdq1KA2ilJ6u3rTvmRvfyRAAAAmgdtW1E3i0EAAAAAgfdDmkBBBBBBNAwYoffffffSPbVJHHHHH3DDmkBBBBBBNAwYoffffffSPR2cB5lPBIDBIjP72pgffffGgdtOl7dVJDjgotqkW9o.vumMTJu7xMqG0mBcZpeHBwdXMh8vZD6g2BYjkBAcLsmbi.POuhaB.xHC+kd7o1nG9mm6TrG1pGh8vZ8PrGdCj0rTHnBK+gexICImLrrk4OziF+gei5QS+SIK1Ca0CwdXsdH1CuEhyRgfFpeJbz6wD8PzCQOD8vSQlFVgfVxOeS+6A9ueJv0H5gnGhdH5gOCwYoPPCVFbBl9gl5GSzCQOD8PzCuMxzvJDTw7+GiUkxtI+fdX+4TMcy2qGh8vYmSwdXaYsbsGdBxqNhPPFRnvaMh8vZD6g0H1CuEhyRAAAAAAmfLMrBBBBBBNAwYoffffffSPbVJHHHHH3DDmkBBBBBBNAwYoffffffSPbVJHHHHH3DDmkBBBBBBNAwYoffffffSPbVJHHHHH3DDmkBBBBBBNAwYoffffffSPbVJHHHHH3DDmkBBBBBBNAwYoffffffS3+GrVUMWPHH+WI.....jTQNQjqBAlf" ],
									"embed" : 1,
									"id" : "obj-20",
									"maxclass" : "fpic",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 4.0, 28.5, 459.0, 668.0 ],
									"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 15.24.38.png"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-18",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 565.0, 149.0, 170.0, 69.0 ],
									"text" : "To repeat a process 5 times, we use an uzi, then we collect the results with bach.collect"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-16",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 473.5, 168.0, 25.0, 19.0 ],
									"text" : "F"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 648.0, 403.0, 25.0, 19.0 ],
									"text" : "(F)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-7",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 676.071411, 336.0, 233.0, 69.0 ],
									"text" : "bach.random accepts in the right inlet the number of elements to be picked randomly. This replaces the topmost \"repeat-n\" object."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-5",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 653.5, 361.0, 19.0, 19.0 ],
									"text" : "C"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-4",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 695.5, 257.0, 19.0, 19.0 ],
									"text" : "D"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-17",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 758.0, 63.0, 73.0, 18.0 ],
									"text" : "dump cents"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "bang" ],
									"patching_rect" : [ 471.5, 75.0, 34.0, 20.0 ],
									"text" : "t b b"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 471.5, 39.0, 29.0, 29.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "int" ],
									"patching_rect" : [ 498.5, 168.0, 46.0, 20.0 ],
									"text" : "uzi 5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 512.0, 403.0, 135.0, 20.0 ],
									"text" : "bach.collect @inwrap 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "int" ],
									"patching_rect" : [ 570.0, 231.0, 32.5, 20.0 ],
									"text" : "t b i"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 583.5, 257.0, 112.0, 20.0 ],
									"text" : "expr random(3\\, 11)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 570.0, 333.0, 57.0, 20.0 ],
									"saved_object_attributes" : 									{
										"embed" : 0
									}
,
									"text" : "bach.reg"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 782.571411, 254.0, 56.0, 20.0 ],
									"text" : "bach.flat"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 570.0, 361.0, 81.0, 20.0 ],
									"text" : "bach.random"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"frgb" : 0.0,
									"id" : "obj-69",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 863.0, 93.5, 19.0, 19.0 ],
									"text" : "A"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-28",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 506.5, 39.0, 92.0, 25.0 ],
									"text" : "Click to go!"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-19",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 471.5, 7.0, 174.0, 21.0 ],
									"text" : "bach translation"
								}

							}
, 							{
								"box" : 								{
									"additionalstartpad" : 42.260006,
									"clefs" : "FFGG",
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
									"patching_rect" : [ 758.0, 92.0, 105.0, 155.0 ],
									"pitcheditrange" : "null",
									"preventedit" : [ "(", "chord", "create", "delete", "onset", ")" ],
									"showdurations" : 0,
									"stafflines" : 5,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 8,
									"versionnumber" : 7300,
									"voicenames" : [ "(", ")" ],
									"voicespacing" : [ -23.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085022208, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085636096, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085862400, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085943296, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086011392, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086123008, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086169600, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086212096, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086250496, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086285824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086318592, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086337024, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 100, 0, ")", 0, ")", 0, ")" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-24",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 4.0, 7.0, 411.0, 21.0 ],
									"text" : "OpenMusic tutorial 11: random notes from a harmonic spectrum"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-25", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-31", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-31", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-34", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-32", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-33", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-36", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-34", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-34", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-41", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-41", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 2.0, 39.0, 964.0, 379.5 ]
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
					"patching_rect" : [ 199.0, 432.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 484.5, 248.0, 20.0 ],
					"text" : "linksections 1 0 s \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 457.0, 69.0, 20.0 ],
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
					"hidden" : 1,
					"id" : "obj-61",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 453.0, 511.0, 339.0, 36.0 ],
					"text" : "Ok: when random process are repeated more than once, a substantial rewriting is needed.",
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
					"patching_rect" : [ 290.0, 7.74086, 317.0, 25.0 ],
					"text" : "- a more complicate example"
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
					"text" : "From OpenMusic to bach (s)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 561.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 536.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 511.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 486.0, 160.0, 18.0 ],
					"text" : "From OpenMusic to bach (r)",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 461.0, 40.0, 20.0 ],
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
					"id" : "obj-9",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 436.0, 151.0, 20.0 ],
					"text" : "Back to section (r)",
					"varname" : "textbuttonA"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 510.5, 190.5, 510.5, 190.5, 452.0, 208.5, 452.0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
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
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-3", 0 ]
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
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-7", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-9", 0 ]
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
				"name" : "bach.random.maxpat",
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
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.step.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
