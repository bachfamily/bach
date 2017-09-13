{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 265.0, 44.0, 900.0, 640.0 ],
		"bglocked" : 0,
		"defrect" : [ 265.0, 44.0, 900.0, 640.0 ],
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
					"maxclass" : "message",
					"text" : "flat",
					"patching_rect" : [ 791.0, 466.0, 32.5, 18.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "<<< All the freqshift process is inside!!! Have a look",
					"patching_rect" : [ 146.0, 456.0, 310.0, 20.0 ],
					"id" : "obj-42",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "when we change the function, its content in list form is output. Thus we perform apply_freqshift",
					"patching_rect" : [ 81.0, 573.0, 512.0, 20.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "we flatten the frequency shift function at startup",
					"linecount" : 2,
					"patching_rect" : [ 653.0, 450.0, 150.0, 34.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b l",
					"patching_rect" : [ 46.0, 574.0, 32.5, 20.0 ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "here the original data is contained in the whole roll gathered syntax.",
					"linecount" : 4,
					"patching_rect" : [ 81.0, 353.0, 109.0, 62.0 ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p apply_freqshift",
					"patching_rect" : [ 24.0, 453.888885, 110.0, 22.0 ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"numinlets" : 3,
					"fontsize" : 13.652807,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 386.0, 205.0, 1005.0, 580.0 ],
						"bglocked" : 0,
						"defrect" : [ 386.0, 205.0, 1005.0, 580.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "<< Clipping negative midicents",
									"patching_rect" : [ 375.0, 571.0, 174.0, 20.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "maximum 0.",
									"patching_rect" : [ 297.0, 571.0, 76.0, 20.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "float", "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess roll",
									"patching_rect" : [ 29.0, 697.0, 81.0, 20.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we don't recompose header and body, since we just need to change the body, so we just prepend a \"roll\" symbol",
									"linecount" : 2,
									"patching_rect" : [ 180.0, 730.0, 332.0, 34.0 ],
									"id" : "obj-68",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we recollect all the chords, paying attention not to forget the red cable, where the information about levels travels!",
									"linecount" : 2,
									"patching_rect" : [ 229.0, 690.0, 332.0, 34.0 ],
									"id" : "obj-67",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b l",
									"patching_rect" : [ 283.0, 346.0, 32.5, 20.0 ],
									"id" : "obj-66",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "muted/solo/locked flag",
									"patching_rect" : [ 421.0, 625.0, 130.0, 20.0 ],
									"id" : "obj-65",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "notes",
									"patching_rect" : [ 306.0, 624.0, 40.0, 20.0 ],
									"id" : "obj-64",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "onset",
									"patching_rect" : [ 237.0, 624.0, 40.0, 20.0 ],
									"id" : "obj-63",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.reg",
									"patching_rect" : [ 183.0, 623.0, 57.0, 20.0 ],
									"id" : "obj-61",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"saved_object_attributes" : 									{
										"embed" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we recompose the chord",
									"patching_rect" : [ 433.0, 646.0, 163.0, 20.0 ],
									"id" : "obj-60",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we recompose the note",
									"patching_rect" : [ 457.0, 595.0, 163.0, 20.0 ],
									"id" : "obj-59",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we shift the pitch by the desired amount of Hz",
									"linecount" : 4,
									"patching_rect" : [ 213.0, 481.0, 80.0, 62.0 ],
									"id" : "obj-58",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we'll plug back later all the rest",
									"linecount" : 2,
									"patching_rect" : [ 444.0, 439.0, 95.0, 34.0 ],
									"id" : "obj-57",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "and take\ncents",
									"linecount" : 2,
									"patching_rect" : [ 244.0, 430.0, 95.0, 34.0 ],
									"id" : "obj-54",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we iterate on each note",
									"linecount" : 2,
									"patching_rect" : [ 220.0, 377.0, 95.0, 34.0 ],
									"id" : "obj-50",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "freqshift",
									"patching_rect" : [ 318.0, 458.0, 53.0, 20.0 ],
									"id" : "obj-49",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "...which is the amount of Hz to be added to each note",
									"linecount" : 2,
									"patching_rect" : [ 411.0, 509.0, 163.0, 34.0 ],
									"id" : "obj-45",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "...we obtain the corresponding y...",
									"linecount" : 2,
									"patching_rect" : [ 587.0, 493.0, 150.0, 34.0 ],
									"id" : "obj-41",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we query the corresponding y...",
									"patching_rect" : [ 547.0, 419.0, 177.0, 20.0 ],
									"id" : "obj-40",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "we rescale the onset with respect to the total duration ($f1/$f2) and then multiply by 1000, to have the corresponding x-value for our function (which has domain = 1000).",
									"linecount" : 7,
									"patching_rect" : [ 548.0, 290.0, 153.0, 103.0 ],
									"id" : "obj-38",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "list of notes in (cents duration velocity flag) format",
									"linecount" : 3,
									"patching_rect" : [ 177.0, 290.0, 116.0, 48.0 ],
									"id" : "obj-33",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Here we rebuild the function when it arrives in list format",
									"linecount" : 3,
									"patching_rect" : [ 760.0, 304.0, 116.0, 48.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Here we have: (NOTE1) (NOTE2) ... onset",
									"patching_rect" : [ 354.0, 255.0, 465.0, 20.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "the last element of each voice is a long flag (which informs us about voices being muted/soloed/locked). We don't care, we just want chords, and chords are the lllls at level 2, so we iterate until level 2 and let only chord lllls through with [bach.filter l]",
									"linecount" : 4,
									"patching_rect" : [ 352.0, 135.0, 377.0, 62.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Here we flat the first level, and slice the last \"flag\" element",
									"patching_rect" : [ 361.0, 231.0, 318.0, 20.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Here we have: (onset (NOTE1) (NOTE2)... flag)",
									"patching_rect" : [ 346.0, 203.0, 467.0, 20.0 ],
									"id" : "obj-18",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "First of all, we slice the object header. We'll plug it back only at the end!",
									"patching_rect" : [ 166.0, 40.0, 400.0, 20.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Here we iterate on the whole roll structure, in order to retrieve.",
									"linecount" : 2,
									"patching_rect" : [ 101.0, 3.0, 228.0, 34.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.filter l",
									"patching_rect" : [ 283.0, 150.0, 69.0, 20.0 ],
									"id" : "obj-46",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.filternull @out t",
									"patching_rect" : [ 370.0, 358.0, 120.0, 20.0 ],
									"id" : "obj-48",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.filternull @out t",
									"patching_rect" : [ 731.0, 355.0, 120.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 524.0, 295.0, 25.0, 25.0 ],
									"id" : "obj-37",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"comment" : "Total length"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.iter @maxdepth 1 @unwrap 1",
									"patching_rect" : [ 297.0, 386.0, 200.0, 20.0 ],
									"id" : "obj-35",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.slice -1",
									"patching_rect" : [ 283.0, 229.0, 78.0, 20.0 ],
									"id" : "obj-34",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.append 3 @outwrap 1",
									"patching_rect" : [ 183.0, 646.0, 247.0, 20.0 ],
									"id" : "obj-32",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l l",
									"patching_rect" : [ 356.0, 311.0, 32.5, 20.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.expr 1000*$f1/$f2 @out t",
									"patching_rect" : [ 370.0, 335.0, 173.0, 20.0 ],
									"id" : "obj-30",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 731.0, 322.0, 25.0, 25.0 ],
									"id" : "obj-25",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"comment" : "Function in list form"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl iter 2",
									"patching_rect" : [ 731.0, 407.0, 49.0, 20.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l clear",
									"patching_rect" : [ 731.0, 380.0, 62.0, 20.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "clear" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "function",
									"patching_rect" : [ 731.0, 446.0, 114.0, 53.0 ],
									"id" : "obj-20",
									"numinlets" : 1,
									"range" : [ -400.0, 400.0 ],
									"numoutlets" : 4,
									"outlettype" : [ "float", "", "", "bang" ],
									"addpoints" : [ 0.0, 0.0, 0, 1000.0, 0.0, 0 ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "onset",
									"patching_rect" : [ 376.0, 289.0, 40.0, 20.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.slice -1",
									"patching_rect" : [ 283.0, 288.0, 78.0, 20.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.rot 1",
									"patching_rect" : [ 283.0, 257.0, 64.0, 20.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.flat 1",
									"patching_rect" : [ 283.0, 203.0, 66.0, 20.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Then we prepare the iteration on the CHORDS. Remember that the levels are: VOICES CHORDS NOTES, so chords is level 2, and we have to iterate until @maxdepth 2",
									"linecount" : 3,
									"patching_rect" : [ 417.0, 78.0, 342.0, 48.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.append 2 @outwrap 1",
									"patching_rect" : [ 297.0, 595.0, 158.0, 20.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.slice 1 @out t",
									"patching_rect" : [ 297.0, 418.0, 158.0, 20.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.append @triggers 2",
									"patching_rect" : [ 29.0, 728.0, 145.0, 20.0 ],
									"id" : "obj-53",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b l clear",
									"patching_rect" : [ 263.0, 65.0, 59.0, 20.0 ],
									"id" : "obj-52",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "", "clear" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.collect",
									"patching_rect" : [ 155.0, 697.0, 74.0, 20.0 ],
									"id" : "obj-51",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.iter @maxdepth 2",
									"patching_rect" : [ 283.0, 96.0, 135.0, 20.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.sliceheader",
									"patching_rect" : [ 63.0, 40.0, 101.0, 20.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 63.0, 11.0, 25.0, 25.0 ],
									"id" : "obj-55",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"comment" : "Whole roll in"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 29.0, 757.0, 25.0, 25.0 ],
									"id" : "obj-56",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : "Whole roll out"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.f2mc @out t",
									"patching_rect" : [ 297.0, 538.0, 105.0, 20.0 ],
									"id" : "obj-44",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 0",
									"patching_rect" : [ 297.0, 510.0, 32.5, 20.0 ],
									"id" : "obj-43",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.mc2f @out t",
									"patching_rect" : [ 297.0, 478.0, 105.0, 20.0 ],
									"id" : "obj-42",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "panel",
									"bgcolor" : [ 1.0, 0.960784, 0.627451, 1.0 ],
									"patching_rect" : [ 291.0, 457.0, 119.0, 111.0 ],
									"border" : 1,
									"id" : "obj-47",
									"background" : 1,
									"numinlets" : 1,
									"numoutlets" : 0
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-44", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-56", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-51", 0 ],
									"destination" : [ "obj-53", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-43", 1 ],
									"hidden" : 0,
									"color" : [ 0.0, 0.780392, 0.12549, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-44", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-42", 0 ],
									"destination" : [ "obj-43", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-46", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-46", 0 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-52", 2 ],
									"destination" : [ "obj-51", 2 ],
									"hidden" : 0,
									"color" : [ 0.109804, 0.505882, 0.882353, 0.388235 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-52", 0 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [ 272.5, 113.0, 164.5, 113.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 2 ],
									"destination" : [ "obj-51", 2 ],
									"hidden" : 0,
									"color" : [ 0.698039, 0.070588, 0.070588, 1.0 ],
									"midpoints" : [ 408.5, 133.0, 921.0, 133.0, 921.0, 679.0, 219.5, 679.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-37", 0 ],
									"destination" : [ "obj-30", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-55", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-34", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 1 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 1 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 1 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [ 783.5, 435.0, 740.5, 435.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-52", 1 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-48", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"color" : [ 0.0, 0.780392, 0.12549, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-30", 0 ],
									"destination" : [ "obj-48", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-42", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 1 ],
									"destination" : [ "obj-11", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-32", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-34", 1 ],
									"destination" : [ "obj-32", 2 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.0, 0.0, 0.27451 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-32", 0 ],
									"destination" : [ "obj-51", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-61", 1 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.0, 0.0, 0.27451 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-61", 0 ],
									"destination" : [ "obj-32", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-66", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-66", 1 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-66", 0 ],
									"destination" : [ "obj-61", 0 ],
									"hidden" : 0,
									"midpoints" : [ 292.5, 368.0, 192.5, 368.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 1 ],
									"destination" : [ "obj-52", 0 ],
									"hidden" : 0,
									"midpoints" : [ 154.5, 62.0, 272.5, 62.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-34", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "At startup, after object is loaded, we make a backup in the [bach.reg]",
					"linecount" : 4,
					"patching_rect" : [ 469.0, 381.0, 122.0, 62.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "gate 1 1",
					"patching_rect" : [ 340.0, 383.0, 54.0, 20.0 ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.reg",
					"patching_rect" : [ 24.0, 384.0, 57.0, 20.0 ],
					"id" : "obj-47",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"saved_object_attributes" : 					{
						"embed" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t dump 0",
					"patching_rect" : [ 340.0, 406.0, 57.0, 20.0 ],
					"id" : "obj-43",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "dump", "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bach.keys done length @out t",
					"patching_rect" : [ 375.0, 360.0, 169.0, 20.0 ],
					"id" : "obj-41",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "We have encapsulated the sync process",
					"linecount" : 3,
					"patching_rect" : [ 776.0, 346.0, 106.0, 48.0 ],
					"id" : "obj-40",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"patching_rect" : [ 791.0, 442.0, 60.0, 20.0 ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p synchronize",
					"patching_rect" : [ 643.0, 353.0, 122.0, 24.0 ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 15.450188,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 640.0, 480.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "clip 0 32767",
									"patching_rect" : [ 323.0, 296.0, 75.0, 20.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess set 0",
									"patching_rect" : [ 323.0, 173.0, 91.0, 20.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "* -1.",
									"patching_rect" : [ 50.0, 307.0, 33.0, 20.0 ],
									"id" : "obj-73",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t f f",
									"patching_rect" : [ 309.0, 257.0, 32.5, 20.0 ],
									"id" : "obj-72",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "float", "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t f f",
									"patching_rect" : [ 295.0, 128.0, 32.5, 20.0 ],
									"id" : "obj-71",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "float", "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "$1",
									"patching_rect" : [ 50.0, 218.0, 32.5, 18.0 ],
									"id" : "obj-70",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"patching_rect" : [ 571.0, 100.0, 20.0, 20.0 ],
									"id" : "obj-68",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b f",
									"patching_rect" : [ 340.0, 209.0, 32.5, 20.0 ],
									"id" : "obj-64",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "getdomainpixels",
									"patching_rect" : [ 77.0, 151.0, 97.0, 18.0 ],
									"id" : "obj-63",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l l b",
									"patching_rect" : [ 50.0, 127.0, 46.0, 20.0 ],
									"id" : "obj-60",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "expr $f1 * $f3 / $f2",
									"patching_rect" : [ 309.0, 233.0, 109.0, 20.0 ],
									"id" : "obj-51",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "getdomainpixels, getdomain, getlength",
									"patching_rect" : [ 417.0, 181.0, 216.0, 18.0 ],
									"id" : "obj-50",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "expr $f2 - $f1",
									"patching_rect" : [ 64.0, 184.0, 81.0, 20.0 ],
									"id" : "obj-46",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "expr $f2 - $f1",
									"patching_rect" : [ 172.0, 176.0, 81.0, 20.0 ],
									"id" : "obj-41",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "expr ($f1 / $f2) * $f3",
									"patching_rect" : [ 50.0, 283.0, 117.0, 20.0 ],
									"id" : "obj-40",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bach.keys domain domainpixels length done @out t",
									"patching_rect" : [ 50.0, 102.0, 508.0, 20.0 ],
									"id" : "obj-39",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 12.0,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "patching_rect 0. 217. $1 63.",
									"patching_rect" : [ 323.0, 324.0, 159.0, 18.0 ],
									"id" : "obj-30",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "offset $1 -217",
									"patching_rect" : [ 50.0, 336.0, 84.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 12.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-27",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 571.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-31",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 50.0, 414.0, 25.0, 25.0 ],
									"id" : "obj-32",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 242.0, 414.0, 25.0, 25.0 ],
									"id" : "obj-33",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 323.0, 414.0, 25.0, 25.0 ],
									"id" : "obj-34",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-73", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-40", 0 ],
									"destination" : [ "obj-73", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-72", 1 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-71", 0 ],
									"destination" : [ "obj-40", 1 ],
									"hidden" : 0,
									"midpoints" : [ 304.5, 240.5, 108.5, 240.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-72", 0 ],
									"destination" : [ "obj-40", 2 ],
									"hidden" : 0,
									"midpoints" : [ 318.5, 277.0, 157.5, 277.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-51", 0 ],
									"destination" : [ "obj-72", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-71", 1 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 2 ],
									"destination" : [ "obj-71", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-70", 0 ],
									"destination" : [ "obj-40", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 0 ],
									"destination" : [ "obj-70", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 1 ],
									"destination" : [ "obj-46", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 2 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-68", 0 ],
									"destination" : [ "obj-50", 0 ],
									"hidden" : 0,
									"midpoints" : [ 580.5, 139.0, 426.5, 139.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-46", 0 ],
									"destination" : [ "obj-64", 0 ],
									"hidden" : 0,
									"midpoints" : [ 73.5, 206.0, 349.5, 206.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-64", 1 ],
									"destination" : [ "obj-51", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-64", 0 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-41", 0 ],
									"destination" : [ "obj-51", 2 ],
									"hidden" : 0,
									"midpoints" : [ 181.5, 201.0, 408.5, 201.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 3 ],
									"destination" : [ "obj-50", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 1 ],
									"destination" : [ "obj-41", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-39", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-68", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-32", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-63", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-50", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-30", 0 ],
									"destination" : [ "obj-34", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "What's still missing is the fact that, as we change the function. Since we always need to apply the frequency shift enveloppe on the original data, we'll need to keep somewhere a backup copy of these data. We decide to do this in the gathered syntax (in order to give you a slightly more complicated example). You could surely do the same thing with the separate inlets syntax. The copy is taken at startup, and it's not changed any more.\nFirst of all we set the function flat at the beginning (thus we send a \"flat\" message to the right bpatcher inlet: this message is handled inside!). Then we need to apply the freqshift on the backup copy of our data when the function is changed. So, inside the bpatcher, we output the function in list content; in the main patch we retrieve the function data and apply the frequency shift. Finally, we reconstruct the whole roll.",
					"linecount" : 7,
					"patching_rect" : [ 5.0, 38.0, 793.0, 103.0 ],
					"id" : "obj-81",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bach.roll",
					"versionnumber" : 6750,
					"patching_rect" : [ 22.0, 148.0, 743.0, 190.333328 ],
					"voicespacing" : [ 0.0, 17.0, 17.0, 17.0, 17.0 ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"zoom" : 63.109375,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"stafflines" : [ 5, 5, 5, 5 ],
					"automessage" : [  ],
					"vzoom" : 66.666664,
					"hidevoices" : [ 0, 0, 0, 0 ],
					"numinlets" : 6,
					"voicenames" : [ "<none>", "<none>", "<none>", "<none>" ],
					"fontsize" : 12.0,
					"out" : "nnnnnnn",
					"numvoices" : 4,
					"midichannels" : [ 1, 2, 3, 4 ],
					"numoutlets" : 8,
					"keys" : [ "CM", "CM", "CM", "CM" ],
					"bgslots" : [  ],
					"clefs" : [ "G", "G", "G", "F" ],
					"popupmenuslots" : [  ],
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", ")", ")", "(", "commands", "(", 1, "notecmd", "chordcmd", 0, ")", "(", 2, "notecmd", "chordcmd", 0, ")", "(", 3, "notecmd", "chordcmd", 0, ")", "(", 4, "notecmd", "chordcmd", 0, ")", "(", 5, "notecmd", "chordcmd", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, 4, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083702152, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084130804, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084250635, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084393519, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084536403, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084607845, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084679287, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084822170, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085036496, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085107938, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085250822, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085370653, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085406374, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085477816, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584979, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085620700, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081319233, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085701072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080556424, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080883016, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085809510, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081203565, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085882653, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081557373, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086085072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086120793, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086156514, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086299398, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086329927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086419229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086437090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086454950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086526392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086544253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086562113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086740718, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086776439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086847880, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086883601, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086955043, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086972904, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086990764, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087637480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087646410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087664270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087673201, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087691061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087699991, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087717852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087726782, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087744643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087771433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087798224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087825015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087851805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087878596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087905387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087932177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088048270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088155433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088262596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376835, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402474, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086415215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086428013, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325682, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351253, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088556567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085727863, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088744102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088770893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088779823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070571, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088784288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088793219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088797684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088806614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088811079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088815544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088820009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088833405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088837870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088846800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088860195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088886986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070571, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088900381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081290656, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088914670, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080585001, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080870769, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088928288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081196761, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088937378, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081513147, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088957870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376835, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086402474, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089091823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089096288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349 ],
					"whole_roll_data_0000000001" : [ 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089145405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089149870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089198986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089203451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089239172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089243637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089265963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089270428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089292753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089297219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089332939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089337405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089359730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089364195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089440102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089444567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089453498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891294, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089466893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086376835, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086364014, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089508864, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089511097, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089515562, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891294, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089522260, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089535655, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089537888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089542353, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089544585, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089549050, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325682, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089555748, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089557981, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086325682, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089562446, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089569143, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089571376, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081329439, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089576439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080617660, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082133071, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089587841, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081523353, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089593662, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085107938, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082903623, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086013630, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086049351, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086227956, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086263677, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086299398, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086329927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 31, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086383508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 33, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086490671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086597834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083082228, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086740718, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086758578, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086776439, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086847880, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086865741, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086883601, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086955043, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086972904, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086990764, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087080067, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087133648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087151508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087187229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087240811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087294392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087347974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087387433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891294, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087414224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087441015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087467805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087476736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087494596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087521387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087548177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087574968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087601759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087619619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084250635, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087958968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087967898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087985759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087994689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088012550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088039340, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088066131, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088075061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088092922, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088101852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088119712, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088146503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088173294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088200084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088209015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088226875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088253666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088280456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088307247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088316177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088334038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088360829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088387619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088414410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088458335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088471730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198494, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088556567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088569963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198494, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088730707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088757498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088761963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088784288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088788753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088793219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088797684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088837870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088842335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088846800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084884682, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088953405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088957870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088966800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086275258, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089091823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089096288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089145405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089149870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089198986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089203451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984 ],
					"whole_roll_data_0000000002" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089466893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089470911, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089475376, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089522260, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089524492, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089528957, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089531190, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086249423, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089535655, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086223791, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089537888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089562446, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082995477, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083163875, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089595894, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089598127, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089600359, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089602592, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089604824, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089613755, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089615987, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089618220, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089627150, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089629383, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089631615, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085406374, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082903623, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085977909, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086085072, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086347787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086419229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086454950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086526392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173012, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086544253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086562113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086704997, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086812160, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086919322, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087026485, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087080067, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087097927, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 73, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087133648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087151508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087187229, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087205090, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087240811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087258671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087294392, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087312253, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087347974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087365834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087387433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087396363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087414224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087423154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087441015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087449945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087467805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087476736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087494596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087503526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087521387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087530317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087548177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087557108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087574968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087583898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087601759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087610689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084322077, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087825015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087994689, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088101852, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088119712, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088146503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088173294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088200084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088209015, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088226875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088253666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088280456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088307247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088316177, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088334038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088360829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088387619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088431544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088444939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891294, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088529777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084822170, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088645870, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088650335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088659265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084750728, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088757498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088761963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088766428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088770893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088775358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088779823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084322077, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088855730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088860195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082090805, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082875046, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088962335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 37, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088966800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 41, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083273501, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089319544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089324009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089346335, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089350800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089373126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089377591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089482074, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089495469, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089497702, "(" ],
					"whole_roll_data_0000000003" : [ "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089502167, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089504399, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084250635, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082995477, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083457209, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089600359, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089607057, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121735, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089618220, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089620452, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089624917, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019428, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089627150, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086044390, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089631615, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096091, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084893612, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085299211, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085513537, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082975065, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085750188, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083898618, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086192235, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086227956, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086263677, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086365648, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086383508, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 33, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086401369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 34, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086472811, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 38, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086490671, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 39, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086508532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086579974, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086597834, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086615694, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086633555, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 47, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086669276, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086687136, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086704997, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086722857, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086794299, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086812160, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086830020, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086901462, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 62, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086919322, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086937183, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087008625, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 68, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087026485, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 69, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087044346, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087062206, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087115787, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087169369, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085762523, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087222950, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087276532, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712228, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087330113, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087378503, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087405294, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087432084, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087458875, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712228, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087485666, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087512456, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087539247, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087566038, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087592829, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087619619, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087646410, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087673201, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085300388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087699991, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087726782, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 57, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087753573, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 61, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087780363, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087807154, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087833945, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087860736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085300388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087887526, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085323843, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087914317, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087941108, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085300388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087967898, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 46, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088021480, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 48, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088048270, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088075061, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085350443, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088128643, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085350443, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088155433, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 53, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088182224, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 54, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088235805, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088262596, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088289387, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429090, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 66, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088342968, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429090, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 72, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088369759, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 75, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088396550, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 70, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088422614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088436009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088449405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 55, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088462800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 50, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088476195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088489591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085582822, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 52, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088502986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 59, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088516381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 67, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088543172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 60, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088565498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088569963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088578893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088592288, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 43, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088596753, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088605684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 40, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088619079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088623544, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 35, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088632474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 32, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088659265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088663730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088672660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083987920, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088730707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088744102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084464961, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088824474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088828939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088833405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088851265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085222620, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088864660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085300388, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088873591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085350443, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088878056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088891451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088900381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088904846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082090805, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088920921, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082135113, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088937378, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081513147, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088948939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 30, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088971265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 42, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088975730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 44, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088984660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 49, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088989126, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 51, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1088998056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089002521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 58, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089011451, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 63, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089015916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 65, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089024846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 71, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089029312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 74, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089038242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 80, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089042707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 83, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089051637, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429090, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 89, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089056102, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089065032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089069498, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085350443, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089078428, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089082893, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085350443, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089105219, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085659789, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089109684, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089118614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429090, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089123079, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085403122, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089132009, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429090, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089136474, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085403122, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089158800, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089163265, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089172195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089176660, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089185591, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085119568, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089190056, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085069618, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089212381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089216846, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089225777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 76, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089230242, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089252567, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089257032, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089279358, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089283823, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089306149, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085736290, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089310614, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089332939, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089337405, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089359730, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089364195, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082510693, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089386521, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085607588, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089390986, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089399916, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085633322, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089404381, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089413312, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085556590, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089417777, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 127, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089426707, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 92, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089431172, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085480089, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089457963, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085505064, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089477608, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081747884, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089484306, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081176349, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089488771, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089491004, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083845036, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089517795, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089531190, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085762523, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416385, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089551283, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085941657, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082796460, 56, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089564678, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891294, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082995477, 64, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089579628, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083163875, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089595894, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865139, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089598127, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085915991, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089607057, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089609290, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089611522, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089620452, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089622685, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085788891, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080127773, 45, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1089624917, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085813779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082224925, 45, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 4 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "bpatcher",
					"patching_rect" : [ 46.0, 506.0, 713.0, 64.0 ],
					"id" : "obj-14",
					"name" : "Graphical Synchronization (e) - bpatcher.maxpat",
					"numinlets" : 2,
					"offset" : [ 0.0, -217.0 ],
					"numoutlets" : 1,
					"args" : [  ],
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "0 Hz",
					"patching_rect" : [ 758.0, 531.5, 40.0, 17.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 8.913287,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "-500 Hz",
					"patching_rect" : [ 758.0, 559.5, 40.0, 17.0 ],
					"id" : "obj-18",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 8.913287,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "500 Hz",
					"patching_rect" : [ 758.0, 502.5, 40.0, 17.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 8.913287,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "wclose",
					"text" : "clean, wclose",
					"patching_rect" : [ 318.0, 617.0, 81.0, 18.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "linksections 1 1 e \"Graphical Synchronization\"",
					"patching_rect" : [ 318.0, 669.5, 254.0, 20.0 ],
					"id" : "obj-198",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "thispatcher",
					"patching_rect" : [ 318.0, 642.0, 69.0, 20.0 ],
					"id" : "obj-90",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"hidden" : 1,
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Are we done? This is not a great interface to deal with...",
					"linecount" : 2,
					"frgb" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"patching_rect" : [ 574.0, 601.0, 168.0, 34.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "_________________________________________________________________",
					"patching_rect" : [ 5.0, 19.0, 444.0, 20.0 ],
					"id" : "obj-87",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- changing the roll via freqshifts",
					"patching_rect" : [ 304.0, 7.74086, 491.0, 26.0 ],
					"id" : "obj-2",
					"fontname" : "Arial Italic",
					"numinlets" : 1,
					"fontsize" : 16.787033,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Graphical Synchronization (e)",
					"patching_rect" : [ 5.0, 2.924051, 304.0, 32.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 22.256727,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"bgcolor" : [ 0.901961, 0.686275, 0.686275, 1.0 ],
					"patching_rect" : [ 315.0, 348.0, 272.0, 94.0 ],
					"border" : 1,
					"id" : "obj-28",
					"background" : 1,
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolA",
					"text" : "pcontrol",
					"patching_rect" : [ 5.0, 740.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependA",
					"text" : "prepend load",
					"patching_rect" : [ 5.0, 715.0, 140.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolA",
					"text" : "tosymbol",
					"patching_rect" : [ 5.0, 690.0, 140.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageA",
					"text" : "Graphical Synchronization (d)",
					"patching_rect" : [ 5.0, 665.0, 167.0, 18.0 ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerA",
					"text" : "t b b",
					"patching_rect" : [ 5.0, 640.0, 40.0, 20.0 ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonA",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"patching_rect" : [ 5.0, 615.0, 151.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"text" : "Back to section (d)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "pcontrolB",
					"text" : "pcontrol",
					"patching_rect" : [ 745.0, 740.0, 140.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "prependB",
					"text" : "prepend load",
					"patching_rect" : [ 745.0, 715.0, 140.0, 20.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "tosymbolB",
					"text" : "tosymbol",
					"patching_rect" : [ 745.0, 690.0, 140.0, 20.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"varname" : "messageB",
					"text" : "Graphical Synchronization (f)",
					"patching_rect" : [ 745.0, 665.0, 163.0, 18.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "triggerB",
					"text" : "t b b",
					"patching_rect" : [ 745.0, 640.0, 40.0, 20.0 ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"hidden" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "textbutton",
					"varname" : "textbuttonB",
					"bgovercolor" : [ 0.64, 0.65, 0.72, 1.0 ],
					"patching_rect" : [ 745.0, 615.0, 151.0, 20.0 ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"text" : "Continue to section (f)",
					"bordercolor" : [ 0.63, 0.7, 0.75, 1.0 ],
					"bgoncolor" : [ 0.51, 0.59, 0.64, 1.0 ],
					"numinlets" : 1,
					"fontface" : 2,
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ]
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
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 1 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 1 ],
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
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-14", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 2 ],
					"destination" : [ "obj-14", 1 ],
					"hidden" : 0,
					"color" : [ 0.905882, 0.298039, 0.807843, 0.431373 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"color" : [ 0.905882, 0.298039, 0.807843, 0.431373 ],
					"midpoints" : [ 652.5, 493.0, 55.5, 493.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 1 ],
					"destination" : [ "obj-33", 2 ],
					"hidden" : 0,
					"color" : [ 0.329412, 0.768627, 0.431373, 0.25098 ],
					"midpoints" : [ 69.0, 598.0, 137.0, 598.0, 137.0, 450.0, 124.5, 450.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 1 ],
					"destination" : [ "obj-33", 1 ],
					"hidden" : 0,
					"midpoints" : [ 459.5, 445.0, 79.0, 445.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-24", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-47", 0 ],
					"hidden" : 0,
					"color" : [ 0.329412, 0.768627, 0.431373, 0.25098 ],
					"midpoints" : [ 55.5, 600.0, 20.0, 600.0, 20.0, 373.0, 33.5, 373.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 1 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [ 387.5, 431.0, 327.0, 431.0, 327.0, 376.0, 349.5, 376.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
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
, 			{
				"patchline" : 				{
					"source" : [ "obj-198", 0 ],
					"destination" : [ "obj-90", 0 ],
					"hidden" : 1,
					"midpoints" : [ 327.5, 695.5, 309.5, 695.5, 309.5, 637.0, 327.5, 637.0 ]
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
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 1.0, 0.0, 0.0, 1.0 ],
					"midpoints" : [ 33.5, 484.0, 12.5, 484.0, 12.5, 138.0, 31.5, 138.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 6 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-47", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 0.647059, 0.67451, 0.113725, 1.0 ],
					"midpoints" : [ 349.5, 446.0, 776.0, 446.0, 776.0, 143.0, 31.5, 143.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 6 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 7 ],
					"destination" : [ "obj-35", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 1 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"color" : [ 0.647059, 0.67451, 0.113725, 1.0 ],
					"midpoints" : [ 704.0, 388.0, 775.75, 388.0, 775.75, 144.0, 31.5, 144.0 ]
				}

			}
 ]
	}

}
