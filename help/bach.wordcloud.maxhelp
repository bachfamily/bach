{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 10,
			"architecture" : "x86"
		}
,
		"rect" : [ 349.0, 104.0, 627.0, 519.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 5.0, 5.0 ],
		"gridsnaponopen" : 1,
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
		"showrootpatcherontab" : 0,
		"showontab" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 0.0, 26.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-8",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 463.0, 314.5, 142.0, 40.0 ],
									"text" : "Spread factor for spacing words"
								}

							}
, 							{
								"box" : 								{
									"attr" : "space",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 329.0, 324.0, 124.0, 21.0 ],
									"text_width" : 71.0
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-5",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 350.0, 236.0, 187.0, 40.0 ],
									"text" : "bang to rebuild (makes sense if vscatter is > 0)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 323.0, 246.0, 20.0, 20.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 274.0, 192.5, 285.0, 40.0 ],
									"text" : "Amount of random scatter of vertical positioning for single words (in single lines)"
								}

							}
, 							{
								"box" : 								{
									"attr" : "vscatter",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 105.605469, 202.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-14",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 283.0, 142.5, 170.0, 40.0 ],
									"text" : "Vertical alignment of words in single lines"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-13",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 113.0, 170.0, 25.0 ],
									"text" : "Global vertical alignment"
								}

							}
, 							{
								"box" : 								{
									"attr" : "valign",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 37.0, 113.0, 211.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "linevalign",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 54.0, 152.0, 223.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-6",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 248.0, 81.0, 170.0, 25.0 ],
									"text" : "Horizontal alignment"
								}

							}
, 							{
								"box" : 								{
									"attr" : "align",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 17.0, 83.0, 221.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"fontsizeslope" : -0.3,
									"id" : "obj-1",
									"linevalign" : 3,
									"maxclass" : "bach.wordcloud",
									"maxfontsize" : 18.0,
									"minfontsize" : 10.0,
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 17.0, 236.0, 297.0, 230.0 ],
									"space" : 4.0,
									"valign" : 3,
									"whole_wordcloud_data_0000000000" : [ "(", "absolute value", "accept", "action", "add", "addition", "address", "adjoint", "adjugate", "amplitude", "angle", "appearance", "append", "approximate", "arrange", "articulation", "assemble", "automatic", "average", "barline", "base", "basis", "beat", "belong", "binomial coefficient", "bit field", "body", "boundary", "box", "branch", "breakpoint function", "build", "calculate", "cardinality", "cartesian", "cell", "cent", "change", "channel", "chord", "chunk", "circle", "classical", "clip", "clock", "cofactor", "color", "column", "combination", "combinations", "combine", "complement", "compute", "compute", "concatenate", "condition", "constraint", "construct", "content", "convert", "coordinate", "coprime", "copy", "count", "crop", "cross product", "curve", "curve~", "cut", "decode", "delay", "denominator", "derivative", "derive", "detect", "determinant", "diagonal", "diagram", "dictionary", "difference", "discrete", "display", "distance", "divide", "division", "draw", "drip", "duplicate", "duration", "duration line", "each", "echelon form", "edit", "eigenvalue", "eigenvector", "element", "enharmonicity", "entry", "equal", "equation", "error", "expand", "exponent", "export", "expression", "extend", "extra", "extract", "factorial", "family", "fill", "filter", "filtercoeff~", "find", "flat", "floating point", "flow", "force", "format", "Fourier", "fraction", "frequency", "front", "function", "gathered syntax", "Gauss elimination", "generator", "glissando", "grace notes", "graph", "graphic", "greatest common divisor", "grid", "group", "header", "hexagone", "histogram", "identity", "if", "image", "imaginary", "import", "include", "index", "information", "insert", "integer", "integral function", "integrate", "interpolate", "interval", "interval function", "interval structure", "interval vector", "inverse", "inversion", "invert", "iterate", "iteration", "jit.cellblock", "join", "just intonation", "k-deck", "keep", "kernel", "key", "keychain", "kurtosis", "lambda loop", "lattice", "leaf", "least common multiple", "legato", "length", "let through", "limit", "line", "linear", "linear independence", "linear system", "line~", "look up", "loop", "magnitude", "main", "map", "marker", "matrix", "matrix", "matrixctrl", "maximum", "mean", "measure", "measured", "measureinfo", "measurewise", "median", "memory", "message", "metro", "microtone", "MIDI", "midicent", "minimal units", "minimum", "minus", "modify", "modulo", "moment", "monophonic", "multiplication", "multiply", "MusicXML", "name", "nearest", "negative", "norm", "normal form", "normalize", "note", "noteoff", "noteon", "nullity", "number", "occurrence", "onset", "open", "OpenMusic", "operator", "order", "organize", "orthogonal", "outline", "parameter", "parametric", "parenthesis", "part", "pass", "period", "periodicity", "phase", "pick", "pitch", "pitch-class", "pitch breakpoint", "plain", "play", "playout", "plot", "plus", "polar", "pool", "position", "power", "prepend", "prime", "prime form", "probability", "product", "proportional", "prune", "quantize", "quotient", "radius", "raise", "random", "range", "rank", "ratio", "rational", "real", "rectangle", "reduce", "reject", "remainder", "repeat", "repetition", "replace", "rescale", "rest", "retain", "retrieve", "retrograde", "reverse", "rhythm", "rhythmic tree", "rotate", "round", "route", "row", "sample", "sampling", "scalar", "score", "search", "secondary", "select", "separate", "separator", "sequence", "series", "set", "shift", "sign", "simplify", "singular", "size", "skewness", "slice", "slot", "smooth", "snap", "solve", "sort", "span", "spat", "split", "square", "square root", "standard deviation", "start", "statistics", "steop", "step", "stream", "stretch", "subtract", "subtraction", "sum", "summation", "swap", "symmetrical", "tag", "take", "talea", "tempo", "threshold", "tie", "ties", "time signature", "times", "tonnetz", "trace", "transcribe", "transform", "transpose", "transposition", "tree", "triad", "trim", "type", "unbox", "unitary", "unpack", "unwrap", "urn", "value", "variance", "vector", "vector product", "velocity", "versor", "voice", "voicewise", "weight", "well-shaped", "wrap", "write", "Z-relation", ")", "(", 1, 2, 3, 2, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 7, 6, 34, 1, 4, 1, 13, 3, 1, 7, 1, 1, 2, 1, 1, 1, 1, 5, 2, 1, 2, 1, 25, 8, 1, 2, 2, 1, 1, 27, 5, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 4, 2, 2, 1, 4, 3, 7, 6, 1, 3, 1, 2, 2, 10, 2, 1, 1, 5, 1, 1, 18, 3, 1, 1, 1, 1, 2, 3, 2, 1, 1, 2, 10, 1, 1, 1, 6, 1, 4, 1, 1, 2, 2, 2, 1, 2, 4, 1, 4, 1, 4, 1, 4, 1, 1, 3, 3, 3, 3, 1, 1, 1, 2, 1, 1, 2, 2, 1, 3, 2, 1, 3, 1, 2, 1, 6, 1, 2, 3, 2, 2, 3, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 3, 1, 2, 3, 2, 1, 1, 1, 4, 1, 1, 3, 3, 7, 16, 2, 5, 1, 3, 4, 5, 2, 1, 1, 1, 2, 5, 5, 12, 1, 5, 1, 1, 10, 5, 1, 5, 1, 1, 3, 2, 2, 2, 3, 1, 6, 1, 1, 1, 41, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2, 8, 12, 14, 3, 2, 1, 2, 1, 1, 3, 3, 2, 3, 1, 2, 3, 2, 3, 6, 1, 1, 2, 3, 2, 6, 2, 3, 4, 4, 2, 1, 2, 2, 1, 3, 4, 1, 2, 3, 1, 2, 1, 2, 3, 2, 4, 1, 3, 3, 1, 1, 1, 3, 2, 1, 5, 3, 1, 7, 1, 5, 2, 2, 1, 1, 3, 1, 2, 8, 1, 3, 1, 1, 1, 1, 3, 5, 2, 1, 2, 7, 1, 3, 2, 2, 1, 3, 7, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 3, 2, 4, 1, 2, 1, 1, 3, 1, 1, 2, 1, 1, 8, 1, 7, 1, 5, 2, 2, 2, 4, 3, 1, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.wordcloud" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 341.210938, 53.625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 148.0, 73.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p alignment",
					"varname" : "basic_tab[4]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 0.0, 26.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-10",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 73.0, 607.0, 36.0 ],
									"text" : "Here we display all the words of Lewis Carroll's Alice in the Wonderland, each weighted with its number of occurrences in the entire book.",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 10.0, 115.0, 64.0, 23.0 ],
									"text" : "loadbang"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-7",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 432.0, 150.0, 150.0, 54.0 ],
									"text" : "Change the font size range to display more/less words"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 251.0, 133.0, 95.0, 21.0 ],
									"text" : "loadmess 4 28"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"listmode" : 1,
									"maxclass" : "rslider",
									"min" : 1,
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 251.0, 162.0, 170.0, 26.0 ],
									"size" : 50.0
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 251.0, 200.0, 175.0, 22.0 ],
									"text" : "minfontsize $1, maxfontsize $2"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "query" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 6,
											"minor" : 1,
											"revision" : 10,
											"architecture" : "x86"
										}
,
										"rect" : [ 0.0, 0.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
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
										"boxes" : [ 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-37",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "bang", "query" ],
													"patching_rect" : [ 50.0, 100.0, 57.0, 20.0 ],
													"text" : "t b query"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-36",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 3,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 160.5, 120.0, 46.0, 20.0 ],
													"text" : "uzi 1 0"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-30",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 187.5, 150.0, 46.0, 18.0 ],
													"text" : "line $1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-6",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 101.0, 294.0, 181.0, 21.0 ],
													"text" : "jstrigger (a[0].toLowerCase())"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-13",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 325.0, 121.0, 20.0 ],
													"text" : "bach.collect"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-10",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 101.0, 262.0, 49.0, 20.0 ],
													"text" : "zl nth 1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-8",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 5,
													"outlettype" : [ "", "", "", "", "" ],
													"patching_rect" : [ 74.0, 232.0, 100.0, 20.0 ],
													"text" : "regexp [a-zA-Z]+"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 74.0, 204.0, 49.0, 20.0 ],
													"text" : "zl iter 1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-16",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 74.0, 169.0, 61.0, 21.0 ],
													"text" : "route set"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-7",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-9",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 74.0, 40.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-11",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 160.5, 40.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-12",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 50.0, 405.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-14",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 113.75, 405.0, 25.0, 25.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-6", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-11", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-12", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-13", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-2", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-16", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-8", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-14", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-30", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-30", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-36", 2 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-13", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-37", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-14", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-37", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-13", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-6", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-37", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-7", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-8", 2 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-16", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-9", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 10.0, 183.0, 108.0, 23.0 ],
									"saved_object_attributes" : 									{
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"default_fontsize" : 12.0,
										"description" : "",
										"digest" : "",
										"fontface" : 0,
										"fontname" : "Arial",
										"fontsize" : 12.0,
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p retrieve_words"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-39",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 10.0, 140.0, 34.0, 34.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "bang", "int" ],
									"patching_rect" : [ 130.0, 183.0, 80.0, 23.0 ],
									"text" : "text alice.txt"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 6,
											"minor" : 1,
											"revision" : 10,
											"architecture" : "x86"
										}
,
										"rect" : [ 694.0, 45.0, 451.0, 553.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
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
										"boxes" : [ 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-4",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 119.0, 439.169922, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 50.0, 408.169922, 88.0, 21.0 ],
													"text" : "bach.pick 1 2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 377.0, 72.0, 21.0 ],
													"text" : "bach.trans"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-8",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 80.5, 323.0, 161.0, 21.0 ],
													"text" : "bach.join @outwrap 1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 80.5, 230.0, 88.0, 21.0 ],
													"text" : "bach.filternull"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-53",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 80.5, 259.169922, 155.0, 21.0 ],
													"text" : "t l l"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-51",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "bang", "" ],
													"patching_rect" : [ 50.0, 173.169922, 49.5, 21.0 ],
													"text" : "t b l"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-50",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 216.5, 289.169922, 79.0, 21.0 ],
													"text" : "bach.length"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-49",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 80.5, 289.169922, 119.0, 21.0 ],
													"text" : "bach.pick 1 @out t"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-44",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 351.169922, 80.0, 21.0 ],
													"text" : "bach.collect"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-43",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 3,
													"outlettype" : [ "", "", "" ],
													"patching_rect" : [ 80.5, 201.169922, 216.0, 21.0 ],
													"text" : "bach.iter @maxdepth 1 @unwrap 1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-19",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "null" ],
													"patching_rect" : [ 50.0, 99.169922, 44.0, 21.0 ],
													"text" : "t l null"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-31",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 192.0, 165.169922, 36.0, 19.0 ],
													"text" : "1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-39",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "bang" ],
													"patching_rect" : [ 192.0, 137.169922, 86.0, 21.0 ],
													"text" : "bach.change"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-40",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 50.0, 145.169922, 122.0, 21.0 ],
													"text" : "bach.split @keep 2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-29",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 4,
													"outlettype" : [ "", "", "", "" ],
													"patching_rect" : [ 50.0, 66.169922, 129.0, 21.0 ],
													"text" : "bach.sort @out nxxx"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-98",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 24.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-99",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 50.0, 439.169922, 25.0, 25.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-19", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-19", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-19", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-29", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-3", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-99", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-31", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-40", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-51", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-40", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-43", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-2", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-44", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-8", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-49", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-53", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-5", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-8", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-50", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-43", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-51", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-44", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-51", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-49", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-53", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-50", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-53", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-44", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-8", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-98", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 10.0, 210.0, 116.0, 23.0 ],
									"saved_object_attributes" : 									{
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"default_fontsize" : 12.0,
										"description" : "",
										"digest" : "",
										"fontface" : 0,
										"fontname" : "Arial",
										"fontsize" : 12.0,
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p build_wordcloud"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Courier",
									"fontsize" : 13.0,
									"fontsizeslope" : -0.4,
									"id" : "obj-1",
									"maxclass" : "bach.wordcloud",
									"maxfontsize" : 29.0,
									"minfontsize" : 5.0,
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 247.0, 567.0, 225.0 ],
									"whole_wordcloud_data_0000000000" : [ "(", "a", "abide", "able", "about", "above", "absence", "absurd", "accept", "acceptance", "accepted", "accepting", "access", "accessible", "accident", "accidentally", "accordance", "account", "accounting", "accounts", "accusation", "accustomed", "ache", "across", "act", "active", "actual", "actually", "ada", "added", "adding", "addition", "additional", "additions", "address", "addressed", "addresses", "addressing", "adjourn", "adoption", "advance", "advantage", "adventures", "advice", "advisable", "advise", "affair", "affectionately", "afford", "afore", "afraid", "after", "afterwards", "again", "against", "age", "agent", "ago", "agony", "agree", "agreed", "agreement", "ah", "ahem", "air", "airs", "ak", "alarm", "alarmed", "alas", "alice", "alive", "all", "allow", "almost", "alone", "along", "aloud", "already", "also", "alteration", "altered", "alternate", "alternately", "altogether", "always", "am", "among", "an", "ancient", "and", "anger", "angrily", "angry", "animal", "animals", "ann", "annoy", "annoyed", "another", "answer", "answered", "answers", "antipathies", "anxious", "anxiously", "any", "anyone", "anything", "anywhere", "appealed", "appear", "appearance", "appeared", "appearing", "appears", "applause", "apples", "applicable", "apply", "approach", "arch", "archbishop", "arches", "archive", "are", "argue", "argued", "argument", "arguments", "arise", "arithmetic", "arm", "arms", "around", "arranged", "array", "arrived", "arrow", "arrum", "as", "ashamed", "ask", "askance", "asked", "asking", "asleep", "assembled", "assistance", "associated", "at", "ate", "atheling", "atom", "attached", "attempt", "attempted", "attended", "attending", "attends", "audibly", "australia", "authority", "available", "avoid", "away", "awfully", "axes", "axis", "b", "baby", "back", "backs", "bad", "bag", "balanced", "balls", "bank", "banks", "banquet", "bark", "barking", "barley", "barrowful", "based", "bat", "bathing", "bats", "bawled", "be", "beak", "bear", "beast", "beasts", "beat", "beating", "beau", "beauti", "beautiful", "beautifully", "beautify", "became", "because", "become", "becoming", "bed", "beds", "been", "before", "beg", "began", "begged", "begin", "beginning", "begins", "begun", "behead", "beheaded", "beheading", "behind", "being", "believe", "believed", "belong", "belongs", "beloved", "below", "belt", "bend", "bent", "besides", "best", "better", "between", "bill", "binary", "bird", "birds", "birthday", "bit", "bite", "bitter", "blacking", "blades", "blame", "blasts", "bleeds", "blew", "blow", "blown", "blows", "body", "boldly", "bone", "bones", "book", "books", "boon", "boots", "bore", "both", "bother", "bottle", "bottom", "bough", "bound", "bowed", "bowing", "box", "boxed", "boy", "brain", "branch", "branches", "brass", "brave", "breach", "bread", "break", "breath", "breathe", "breeze", "bright", "brightened", "bring", "bringing", "bristling", "broke", "broken", "brother", "brought", "brown", "brush", "brushing", "burn", "burning", "burnt", "bursting", "busily", "business", "busy", "but", "butter", "buttercup", "buttered", "butterfly", "buttons", "by", "c", "cackled", "cake", "cakes", "calculate", "calculated", "call", "called", "calling", "calmly", "came", "camomile", "can", "canary", "candle", "cannot", "canterbury", "canvas", "capering", "capital", "card", "cardboard", "cards", "care", "carefully", "cares", "carried", "carrier", "carroll", "carry", "carrying", "cart", "cartwheels", "case", "cat", "catch", "catching", "caterpillar", "cats", "cattle", "caucus", "caught", "cauldron", "cause", "caused", "cautiously", "cease", "ceiling", "centre", "certain", "certainly", "chains", "chance", "chanced", "change", "changed", "changes", "changing", "chapter", "character", "charge", "charges", "charitable", "charities", "chatte", "cheap", "cheated", "check", "checked", "checks", "cheeks", "cheered", "cheerfully", "cherry", "cheshire", "chief", "child", "childhood", "children", "chimney", "chimneys", "chin", "choice", "choke", "choked", "choking", "choose", "choosing", "chop", "chorus", "chose", "christmas", "chrysalis", "chuckled", "circle", "circumstances", "city", "civil", "claim", "clamour", "clapping", "clasped", "classics", "claws", "clean", "clear", "cleared", "clearer", "clearly", "clever", "climb", "clinging", "clock", "close", "closed", "closely", "closer", "clubs", "coast", "coaxing", "codes", "coils", "cold", "collar", "collected", "collection", "come", "comes", "comfits", "comfort", "comfortable", "comfortably", "coming", "commercial", "committed", "common", "commotion", "company", "compilation", "complained", "complaining", "completely", "compliance", "comply", "complying", "compressed", "computer", "computers", "concept", "concerning", "concert", "concluded", "conclusion", "condemn", "conduct", "confirmation", "confirmed", "confused", "confusing", "confusion", "conger", "conqueror", "conquest", "consented", "consequential", "consider", "considerable", "considered", "considering", "constant", "consultation", "contact", "contain", "containing", "contempt", "contemptuous", "contemptuously", "content", "continued", "contract", "contradicted", "contributions", "conversation", "conversations", "convert", "cook", "cool", "copied", "copies", "copy", "copying", "copyright", "corner", "corners", "corporation", "corrupt", "cost", "costs", "could", "couldn", "counting", "countries", "country", "couple", "couples", "courage", "course", "court", "courtiers", "coward", "crab", "crash", "crashed", "crawled", "crawling", "crazy", "created", "creating", "creation", "creature", "creatures", "credit", "creep", "crept", "cried", "cries", "crimson", "critical", "crocodile", "croquet", "croqueted", "croqueting", "cross", "crossed", "crossly", "crouched", "crowd", "crowded", "crown", "crumbs", "cry", "crying", "cucumber", "cunning", "cup", "cupboards", "cur", "curiosity", "curious", "curiouser", "curled", "curls", "curly", "currants", "current", "curtain", "curtsey", "curtseying", "curving", "cushion", "custard", "custody", "cut", "cutting", "d", "dainties", "daisies", "daisy", "damage", "damaged", "damages", "dance", "dancing", "dare", "daresay", "dark", "darkness", "data", "date", "dates", "daughter", "day", "days", "dead", "deal", "dear", "dears", "death", "decided", "decidedly", "declare", "declared", "deductible", "deep", "deepest", "deeply", "defect", "defective", "defects", "delay", "deletions", "delight", "delighted", "delightful", "demand", "denial", "denied", "denies", "deny", "denying", "depends", "derision", "derivative", "derive", "derived", "deserved", "despair", "desperate", "desperately", "despite", "destroy", "detach", "determine", "diamonds", "did", "didn", "die", "died", "different", "difficult", "difficulties", "difficulty", "dig", "digging", "diligently", "dinah", "dinn", "dinner", "dipped", "direct", "directed", "direction", "directions", "directly", "director", "disagree", "disappeared", "disappointment", "disclaim", "disclaimer", "disclaimers", "discontinue", "discover", "discovered", "disgust", "dish", "dishes", "disk", "dismay", "disobey", "display", "displaying", "dispute", "distance", "distant", "distraction", "distribute", "distributed", "distributing", "distribution", "distributor", "dive", "do", "dodged", "dodo", "does", "doesn", "dog", "dogs", "doing", "domain", "don", "donate", "donation", "donations", "done", "donors", "door", "doors", "doorway", "dormouse", "doth", "double", "doubled", "doubling", "doubt", "doubtful", "doubtfully", "down", "downloading", "downward", "downwards", "doze", "dozing", "dr", "draggled", "draw", "drawing", "drawling", "dreadful", "dreadfully", "dream", "dreamed", "dreaming", "dreamy", "dressed", "drew", "dried", "driest", "drink", "drinking", "dripping", "drive", "drop", "dropped", "dropping", "drowned", "drunk", "dry", "duchess", "duck", "dull", "dunce", "e", "each", "eager", "eagerly", "eaglet", "ear", "earls", "earnestly", "ears", "earth", "easily", "easy", "eat", "eaten", "eating", "eats", "ebook", "ebooks", "edgar", "edge", "edition", "editions", "educational", "educations", "edwin", "eel", "eels", "effect", "effort", "efforts", "egg", "eggs", "ein", "either", "elbow", "elbows", "elect", "electronic", "electronically", "elegant", "eleventh", "else", "elsie", "em", "email", "emphasis", "employee", "employees", "empty", "encourage", "encouraged", "encouraging", "end", "ending", "energetic", "engaged", "england", "english", "engraved", "enjoy", "enormous", "enough", "ensuring", "entangled", "entirely", "entity", "entrance", "equipment", "errors", "escape", "especially", "esq", "est", "even", "evening", "ever", "every", "everybody", "everything", "evidence", "evidently", "exact", "exactly", "examining", "excellent", "except", "exclaimed", "exclamation", "exclusion", "execute", "executed", "executes", "execution", "executioner", "executions", "executive", "exempt", "existence", "exists", "expected", "expecting", "expend", "expense", "expenses", "experiment", "explain", "explained", "explanation", "explanations", "exporting", "express", "expressing", "expression", "extent", "extraordinary", "extras", "extremely", "eye", "eyelids", "eyes", "f", "face", "faces", "facility", "fact", "fading", "failure", "faint", "fainting", "faintly", "fair", "fairbanks", "fairly", "fairy", "fall", "fallen", "falling", "familiarly", "family", "fan", "fancied", "fancy", "fancying", "fanned", "fanning", "far", "farm", "farmer", "farther", "fashion", "fast", "faster", "fat", "father", "favoured", "favourite", "fear", "feared", "feathers", "federal", "fee", "feeble", "feebly", "feel", "feeling", "feelings", "fees", "feet", "fell", "fellow", "fellows", "felt", "fender", "ferrets", "fetch", "few", "fidgeted", "field", "fifteen", "fifteenth", "fifth", "fig", "fight", "fighting", "figure", "figures", "file", "files", "filled", "fills", "financial", "find", "finding", "finds", "fine", "finger", "finish", "finished", "finishing", "fire", "fireplace", "first", "fish", "fishes", "fit", "fitness", "fitted", "five", "fix", "fixed", "flame", "flamingo", "flamingoes", "flapper", "flappers", "flashed", "flat", "flavour", "flew", "flinging", "floor", "flower", "flowers", "flown", "flung", "flurry", "flustered", "fluttered", "fly", "flying", "folded", "folding", "follow", "followed", "following", "follows", "fond", "foolish", "foot", "footman", "footmen", "footsteps", "for", "forehead", "forepaws", "forget", "forgetting", "forgot", "forgotten", "fork", "form", "format", "formats", "forth", "fortunately", "forty", "forwards", "found", "foundation", "fountains", "four", "fourteenth", "fourth", "france", "free", "freely", "french", "friend", "friends", "fright", "frighten", "frightened", "frog", "from", "front", "frontispiece", "frowning", "frying", "fulcrum", "full", "fumbled", "fun", "funny", "fur", "furious", "furiously", "furrow", "furrows", "further", "fury", "future", "gained", "gallons", "game", "games", "garden", "gardeners", "gather", "gave", "gay", "gazing", "gbnewby", "general", "generally", "generations", "gently", "geography", "get", "getting", "giddy", "girl", "girls", "give", "given", "giving", "glad", "glanced", "glaring", "glass", "globe", "gloomily", "gloves", "go", "goals", "goes", "going", "golden", "goldfish", "gone", "good", "goose", "got", "govern", "graceful", "grammar", "grand", "grant", "granted", "grass", "gratefully", "grave", "gravely", "gravy", "grazed", "great", "green", "gregory", "grew", "grey", "grief", "grin", "grinned", "grinning", "grins", "gross", "ground", "group", "grow", "growing", "growl", "growled", "growling", "growls", "grown", "grumbled", "grunt", "grunted", "gryphon", "guard", "guess", "guessed", "guests", "guilt", "guinea", "gutenberg", "had", "hadn", "hair", "half", "hall", "hand", "handed", "hands", "handsome", "handwriting", "hanging", "happen", "happened", "happening", "happens", "happy", "hard", "hardly", "hare", "harm", "harmless", "hart", "has", "hasn", "haste", "hastily", "hat", "hatching", "hate", "hated", "hatter", "hatters", "have", "haven", "having", "he", "head", "heads", "heap", "hear", "heard", "hearing", "heart", "hearth", "hearthrug", "hearts", "heavy", "hedge", "hedgehog", "hedgehogs", "hedges", "heels", "height", "held", "help", "helped", "helpless", "her", "herald", "here", "hers", "herself", "hid", "hide", "high", "highest", "him", "himself", "hint", "hippopotamus", "his", "hiss", "histories", "history", "hit", "hjckrrh", "hm", "hoarse", "hoarsely", "hold", "holder", "holding", "holiday", "hollow", "home", "honest", "honour", "hookah", "hope", "hoped", "hopeful", "hopeless", "hoping", "hot", "hour", "hours", "house", "housemaid", "houses", "how", "however", "howled", "howling", "http", "humble", "humbly", "hundred", "hundreds", "hung", "hungry", "hunting", "hurried", "hurriedly", "hurry", "hurrying", "hurt", "hush", "hypertext", "i", "idea", "identification", "identify", "idiot", "idiotic", "if", "ignorant", "ii", "iii", "ill", "imagine", "imitated", "immediate", "immediately", "immense", "impatient", "impatiently", "impertinent", "implied", "important", "imposed", "impossible", "improve", "in", "inaccurate", "incessantly", "inches", "incidental", "inclined", "include", "included", "includes", "including", "incomplete", "increasing", "indeed", "indemnify", "indemnity", "indicate", "indicating", "indignant", "indignantly", "indirect", "indirectly", "individual", "information", "infringement", "injure", "ink", "inkstand", "inquired", "inquisitively", "inside", "insolence", "instance", "instantly", "instead", "insult", "intellectual", "interest", "interesting", "internal", "international", "interpreted", "interrupt", "interrupted", "interrupting", "into", "introduce", "introduced", "invalidity", "invent", "invented", "invitation", "invited", "involved", "inwards", "irritated", "irs", "is", "isn", "it", "its", "itself", "iv", "ix", "jack", "jar", "jaw", "jaws", "jelly", "jogged", "join", "joined", "journey", "joys", "judge", "judging", "jumped", "jumping", "juror", "jurors", "jury", "jurymen", "just", "justice", "keep", "keeping", "kept", "kettle", "key", "kick", "kid", "kill", "killing", "kills", "kind", "kindly", "king", "kings", "kiss", "kissed", "kitchen", "knave", "knee", "kneel", "knelt", "knew", "knife", "knock", "knocked", "knocking", "knot", "know", "knowing", "knowledge", "known", "knows", "knuckles", "label", "labelled", "lacie", "lad", "ladder", "lady", "laid", "lake", "lamps", "land", "languid", "lap", "large", "larger", "largest", "lark", "last", "lasted", "lastly", "late", "lately", "later", "latin", "latitude", "laugh", "laughed", "laughing", "laughter", "law", "laws", "lay", "lazily", "lazy", "leaders", "leading", "leaning", "leant", "leap", "learn", "learned", "learning", "learnt", "least", "leave", "leaves", "leaving", "led", "ledge", "left", "lefthand", "legal", "legally", "legs", "length", "less", "lessen", "lesson", "lessons", "lest", "let", "letter", "letters", "lewis", "liability", "liable", "library", "license", "licensed", "licking", "lie", "lieu", "life", "lifted", "like", "liked", "likely", "likes", "limbs", "limitation", "limited", "line", "lines", "linked", "links", "lips", "listen", "listened", "listeners", "listening", "lit", "literary", "little", "live", "lived", "livery", "lives", "living", "lizard", "lobster", "lobsters", "located", "locations", "lock", "locked", "locks", "lodging", "london", "lonely", "long", "longed", "longer", "longitude", "look", "looked", "looking", "loose", "lory", "lose", "losing", "lost", "lot", "loud", "louder", "loudly", "love", "loveliest", "lovely", "loving", "low", "lower", "lowing", "luckily", "lullaby", "lying", "m", "ma", "mabel", "machine", "machines", "mad", "made", "magic", "magpie", "main", "maintaining", "majesty", "make", "makes", "making", "mallets", "man", "manage", "managed", "managing", "manner", "manners", "many", "maps", "march", "marched", "mark", "marked", "marmalade", "mary", "master", "matter", "matters", "maximum", "may", "maybe", "mayn", "me", "meal", "mean", "meaning", "means", "meant", "meanwhile", "measure", "meat", "medium", "meekly", "meet", "meeting", "melan", "melancholy", "memorandum", "memory", "mentioned", "merchantibility", "mercia", "merely", "merrily", "messages", "met", "method", "methods", "mice", "michael", "middle", "might", "mile", "miles", "milk", "millennium", "mind", "minded", "minding", "mine", "mineral", "minute", "minutes", "mischief", "miserable", "miss", "missed", "mission", "mississippi", "mistake", "mixed", "mock", "moderate", "modern", "modification", "modified", "moment", "money", "month", "moon", "moral", "morals", "morcar", "more", "morning", "morsel", "most", "mostly", "mournful", "mournfully", "mouse", "mouth", "mouths", "move", "moved", "moving", "much", "muchness", "muddle", "multiplication", "murder", "muscular", "mushroom", "music", "must", "mustard", "muttered", "muttering", "my", "myself", "mystery", "name", "named", "names", "narrow", "nasty", "natural", "near", "nearer", "nearly", "neat", "neatly", "necessarily", "neck", "need", "needn", "needs", "negligence", "neighbour", "neighbouring", "neither", "nervous", "nest", "network", "never", "nevertheless", "new", "newby", "newsletter", "newspapers", "next", "nibbled", "nibbling", "nice", "nicely", "night", "nile", "nine", "no", "nobody", "nodded", "noise", "noises", "non", "none", "nonproprietary", "nonsense", "nor", "normans", "north", "northumbria", "nose", "not", "note", "nothing", "notice", "noticed", "noticing", "notifies", "notion", "now", "nowhere", "number", "numerous", "nurse", "nursing", "obliged", "oblong", "obsolete", "obstacle", "obtain", "obtaining", "occasional", "occasionally", "occur", "occurred", "odd", "of", "off", "offend", "offended", "offer", "offers", "office", "officer", "officers", "official", "often", "oh", "ointment", "old", "older", "oldest", "on", "once", "one", "ones", "oneself", "onions", "online", "only", "open", "opened", "opening", "opinion", "opportunities", "opportunity", "opposite", "or", "orange", "order", "ordered", "ordering", "organized", "original", "originator", "ornamented", "other", "others", "otherwise", "ou", "ought", "our", "ours", "ourselves", "outdated", "outside", "over", "overcome", "overhead", "owed", "owl", "own", "owner", "owns", "oyster", "pace", "pack", "page", "pages", "paid", "paint", "painting", "pair", "pairs", "pale", "panted", "panther", "panting", "paper", "paperwork", "paragraph", "paragraphs", "parchment", "pardon", "pardoned", "paris", "part", "particular", "particularly", "partner", "partners", "parts", "party", "pass", "passage", "passed", "passing", "passion", "passionate", "past", "pat", "patience", "patiently", "patriotic", "patted", "pattering", "pattern", "pause", "paused", "paw", "paws", "pay", "paying", "payments", "pebbles", "peeped", "peeping", "peering", "pegs", "pence", "pencil", "pencils", "pennyworth", "people", "pepper", "perfectly", "perform", "performances", "performing", "perhaps", "periodic", "permanent", "permission", "permitted", "persisted", "person", "personal", "persons", "pet", "pg", "pglaf", "phrase", "physical", "picked", "picking", "picture", "pictured", "pictures", "pie", "piece", "pieces", "pig", "pigeon", "pigs", "pinch", "pinched", "pine", "pink", "piteous", "pitied", "pity", "place", "placed", "places", "plain", "plainly", "plan", "planning", "plate", "plates", "play", "played", "players", "playing", "pleaded", "pleasant", "pleasanter", "please", "pleased", "pleases", "pleasing", "pleasure", "plenty", "pocket", "pointed", "pointing", "poison", "poker", "poky", "politely", "pool", "poor", "pop", "pope", "porpoise", "position", "positively", "possessed", "possession", "possibility", "possible", "possibly", "posted", "pounds", "pour", "poured", "powdered", "practically", "practice", "pray", "precious", "prepare", "present", "presented", "presently", "presents", "preserve", "pressed", "pressing", "pretend", "pretending", "pretexts", "pretty", "prevent", "previous", "principal", "print", "printed", "prison", "prisoner", "prize", "prizes", "problem", "proceed", "processing", "procession", "processions", "produce", "produced", "producing", "production", "professor", "profit", "profits", "prohibition", "project", "prominently", "promise", "promised", "promising", "promoting", "promotion", "pronounced", "proofread", "proper", "property", "proposal", "proprietary", "prosecute", "protect", "protection", "proud", "prove", "proved", "proves", "provide", "provided", "providing", "provision", "provisions", "provoking", "public", "puffed", "pulled", "pulling", "pun", "punching", "punished", "punitive", "puppy", "purple", "purpose", "purring", "push", "puss", "put", "putting", "puzzle", "puzzled", "puzzling", "quadrille", "quarrel", "quarrelled", "quarrelling", "queen", "queens", "queer", "queerest", "question", "questions", "quick", "quicker", "quickly", "quiet", "quietly", "quite", "quiver", "rabbit", "rabbits", "race", "railway", "raised", "raising", "ran", "rapidly", "rapped", "rat", "rate", "rather", "rats", "rattle", "rattling", "raven", "ravens", "raving", "raw", "re", "reach", "reaching", "read", "readable", "readily", "reading", "ready", "real", "reality", "really", "rearing", "reason", "reasonable", "reasons", "receipt", "receive", "received", "receiving", "recognised", "recovered", "red", "redistribute", "redistributing", "redistribution", "reduced", "reeds", "reeling", "references", "refreshments", "refund", "refused", "registered", "regular", "regulating", "relief", "relieved", "remain", "remained", "remaining", "remark", "remarkable", "remarked", "remarking", "remarks", "remedies", "remember", "remembered", "remembering", "reminding", "remove", "removed", "renamed", "repeat", "repeated", "repeating", "replace", "replacement", "replied", "reply", "reported", "reports", "representations", "request", "require", "required", "requirements", "research", "resource", "respect", "respectable", "respectful", "rest", "resting", "restrictions", "result", "retire", "return", "returned", "returning", "returns", "revenue", "rich", "riddle", "riddles", "ridge", "ridges", "ridiculous", "right", "righthand", "rightly", "ring", "ringlets", "riper", "rippling", "rise", "rises", "rising", "roared", "roast", "rock", "rome", "roof", "room", "roots", "rope", "rose", "roses", "rosetree", "roughly", "round", "row", "royal", "royalties", "royalty", "rubbed", "rubbing", "rude", "rudeness", "rule", "rules", "rumbling", "run", "running", "rush", "rushed", "rustled", "rustling", "s", "sad", "sadly", "safe", "sage", "said", "salmon", "salt", "same", "sand", "sands", "sang", "sat", "saucepan", "saucepans", "saucer", "savage", "save", "saves", "saw", "say", "saying", "says", "scale", "scaly", "scattered", "school", "schoolroom", "scolded", "scrambling", "scratching", "scream", "screamed", "screaming", "scroll", "sea", "seals", "seaography", "search", "seaside", "seated", "second", "secondly", "secret", "section", "sections", "secure", "see", "seeing", "seem", "seemed", "seems", "seen", "seldom", "sell", "send", "sending", "sends", "sensation", "sense", "sent", "sentence", "sentenced", "series", "seriously", "serpent", "serpents", "service", "set", "setting", "settle", "settled", "settling", "seven", "several", "severely", "severity", "sh", "shade", "shake", "shakespeare", "shaking", "shall", "shan", "shape", "shaped", "share", "shared", "sharing", "shark", "sharks", "sharp", "sharply", "she", "shedding", "sheep", "shelves", "shepherd", "shifting", "shilling", "shillings", "shingle", "shining", "shiny", "shiver", "shock", "shoes", "shook", "shore", "short", "shorter", "should", "shoulder", "shoulders", "shouldn", "shouted", "shouting", "show", "shower", "showing", "shriek", "shrieked", "shrieks", "shrill", "shrimp", "shrink", "shrinking", "shut", "shutting", "shy", "shyly", "side", "sides", "sigh", "sighed", "sighing", "sight", "sign", "signed", "signifies", "signify", "silence", "silent", "simple", "simpleton", "simply", "since", "sing", "singers", "singing", "sink", "sir", "sister", "sisters", "sit", "site", "sits", "sitting", "six", "sixpence", "sixteenth", "size", "sizes", "skimming", "skirt", "skurried", "sky", "slate", "slates", "sleep", "sleepy", "slightest", "slipped", "slippery", "slowly", "small", "smaller", "smallest", "smile", "smiled", "smiling", "smoke", "smoking", "snail", "snappishly", "snatch", "sneeze", "sneezed", "sneezes", "sneezing", "snorting", "snout", "so", "sob", "sobbed", "sobbing", "sobs", "soft", "softly", "soldier", "soldiers", "solemn", "solemnly", "soles", "solicit", "solicitation", "solid", "some", "somebody", "somehow", "someone", "somersault", "something", "sometimes", "somewhere", "son", "song", "soo", "soon", "sooner", "soothing", "sorrow", "sorrowful", "sorrows", "sorry", "sort", "sorts", "sound", "sounded", "sounds", "soup", "sour", "spades", "speak", "speaker", "speaking", "special", "specific", "specified", "spectacles", "speech", "speed", "spell", "spite", "splash", "splashed", "splashing", "splendidly", "spoke", "spoken", "spoon", "spot", "sprawling", "spread", "spreading", "squeaked", "squeaking", "squeeze", "squeezed", "staff", "stairs", "stalk", "stamping", "stand", "standing", "star", "staring", "start", "started", "startled", "state", "statements", "states", "station", "status", "stay", "stays", "steady", "steam", "sternly", "stick", "sticks", "stiff", "stigand", "still", "stingy", "stirring", "stockings", "stole", "stolen", "stood", "stool", "stoop", "stop", "stopped", "stopping", "stored", "story", "straight", "straightened", "straightening", "strange", "strength", "stretched", "stretching", "strict", "strings", "struck", "stuff", "stupid", "stupidest", "stupidly", "subdued", "subject", "subjects", "submitted", "subscribe", "succeeded", "such", "sudden", "suddenly", "suet", "suit", "sulkily", "sulky", "summer", "sun", "supple", "support", "suppose", "suppress", "suppressed", "sure", "surprise", "surprised", "survive", "swallow", "swallowed", "swallowing", "swam", "swamp", "sweet", "swim", "swimming", "synonymous", "t", "table", "tail", "tails", "take", "taken", "takes", "taking", "tale", "talk", "talking", "taller", "tarts", "taste", "tasted", "tastes", "taught", "tax", "taxes", "tea", "teaching", "teacup", "teacups", "teapot", "tears", "teases", "teeth", "telescope", "telescopes", "tell", "telling", "tells", "temper", "ten", "terms", "terribly", "terrier", "terror", "than", "thank", "thanked", "that", "thatched", "the", "their", "theirs", "them", "themselves", "then", "there", "therefore", "these", "they", "thick", "thimble", "thin", "thing", "things", "think", "thinking", "thirteen", "thirty", "this", "thistle", "thoroughly", "those", "though", "thought", "thoughtfully", "thoughts", "thousand", "three", "threw", "throat", "throne", "through", "throughout", "throw", "throwing", "thrown", "thump", "thunder", "thunderstorm", "thus", "tide", "tidy", "tie", "tied", "tight", "till", "tillie", "time", "times", "timid", "timidly", "tinkling", "tiny", "tipped", "tiptoe", "tired", "tis", "tittered", "to", "toast", "today", "toes", "toffee", "together", "told", "tomorrow", "tone", "tones", "tongue", "too", "took", "top", "tops", "tortoise", "toss", "tossing", "touch", "tougher", "towards", "toys", "trademark", "trampled", "transcribe", "transcription", "treacle", "treading", "treat", "treated", "treatment", "tree", "trees", "tremble", "trembled", "trembling", "tremulous", "trial", "trials", "trickling", "tricks", "tried", "trims", "triumphantly", "trot", "trotting", "trouble", "true", "trumpet", "trusts", "truth", "truthful", "try", "trying", "tucked", "tulip", "tumbled", "tumbling", "tunnel", "tureen", "turkey", "turn", "turned", "turning", "turns", "turtle", "turtles", "tut", "twelfth", "twelve", "twentieth", "twenty", "twice", "twinkle", "twinkled", "twinkling", "twist", "two", "txt", "types", "u", "ugh", "uglification", "uglify", "uglifying", "ugly", "unable", "uncivil", "uncomfortable", "uncomfortably", "uncommon", "uncommonly", "uncorked", "under", "underneath", "understand", "undertone", "undo", "undoing", "uneasily", "uneasy", "unenforceability", "unfolded", "unfortunate", "unhappy", "uniform", "unimportant", "united", "unjust", "unless", "unlink", "unlocking", "unpleasant", "unrolled", "unsolicited", "until", "untwist", "unusually", "unwillingly", "up", "updated", "upon", "upright", "upset", "upsetting", "upstairs", "us", "use", "used", "useful", "user", "using", "usual", "usually", "usurpation", "ut", "v", "vague", "vanished", "vanishing", "variations", "variety", "various", "vegetable", "velvet", "venture", "ventured", "verdict", "verse", "verses", "version", "very", "vi", "viewing", "vii", "viii", "vinegar", "violates", "violence", "violent", "violently", "virus", "visit", "voice", "voices", "void", "volunteer", "volunteers", "vote", "vulgar", "w", "wag", "wags", "waist", "waistcoat", "wait", "waited", "waiting", "wake", "walk", "walked", "walking", "walks", "walrus", "wander", "wandered", "wandering", "want", "wanted", "wants", "warning", "warranties", "warranty", "was", "wash", "washing", "wasn", "waste", "wasting", "watch", "watched", "watching", "water", "waters", "waving", "way", "ways", "we", "weak", "wearily", "web", "week", "weeks", "welcome", "well", "went", "wept", "were", "weren", "west", "wet", "what", "whatever", "whatsoever", "when", "whenever", "where", "whereupon", "wherever", "whether", "which", "while", "whiles", "whiskers", "whisper", "whispered", "whispers", "whistle", "whistling", "white", "whiting", "who", "whoever", "whole", "whom", "whose", "why", "wide", "wider", "widest", "wife", "wig", "wild", "wildly", "will", "william", "win", "wind", "window", "wine", "wings", "wink", "winter", "wise", "wish", "with", "within", "without", "witness", "wits", "woke", "woman", "won", "wonder", "wondered", "wonderful", "wondering", "wonderland", "wood", "wooden", "word", "words", "wore", "work", "works", "world", "worm", "worried", "worry", "worse", "worth", "would", "wouldn", "wow", "wrapping", "wretched", "wriggling", "write", "writhing", "writing", "written", "wrong", "wrote", "www", "x", "xi", "xii", "yards", "yawned", "yawning", "ye", "year", "years", "yelled", "yelp", "yer", "yes", "yesterday", "yet", "you", "young", "your", "yours", "yourself", "youth", "zealand", "zigzag", "zip", ")", "(", 813, 2, 1, 125, 2, 1, 3, 1, 1, 2, 1, 10, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 5, 1, 2, 1, 1, 1, 29, 1, 1, 4, 1, 1, 2, 1, 1, 1, 1, 5, 3, 13, 3, 3, 1, 1, 1, 1, 1, 14, 50, 3, 103, 11, 6, 1, 2, 1, 10, 1, 19, 5, 1, 15, 1, 1, 2, 1, 4, 493, 4, 227, 5, 8, 9, 6, 8, 3, 4, 1, 2, 1, 1, 6, 13, 17, 14, 73, 1, 1041, 2, 13, 6, 3, 4, 4, 1, 1, 24, 12, 4, 2, 1, 4, 17, 90, 4, 29, 3, 1, 3, 1, 11, 2, 1, 1, 3, 3, 1, 2, 1, 4, 5, 15, 84, 1, 1, 4, 1, 1, 1, 17, 7, 3, 1, 1, 1, 2, 2, 324, 2, 16, 1, 31, 8, 9, 2, 1, 8, 253, 1, 1, 3, 1, 1, 2, 1, 3, 1, 2, 1, 3, 2, 2, 35, 2, 2, 2, 3, 14, 48, 1, 4, 1, 1, 1, 3, 1, 2, 3, 1, 1, 3, 2, 2, 1, 4, 1, 183, 1, 2, 2, 2, 4, 3, 4, 2, 24, 2, 2, 2, 20, 7, 2, 1, 1, 44, 51, 8, 67, 2, 17, 15, 6, 9, 1, 5, 1, 15, 23, 12, 1, 1, 2, 2, 9, 2, 3, 1, 4, 17, 16, 8, 16, 1, 4, 9, 1, 21, 2, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 2, 1, 1, 1, 9, 1, 1, 6, 2, 21, 1, 10, 7, 1, 4, 7, 1, 4, 1, 3, 1, 2, 2, 1, 1, 2, 11, 2, 4, 2, 2, 8, 3, 3, 5, 1, 3, 8, 1, 7, 1, 1, 1, 2, 1, 1, 1, 4, 14, 1, 193, 4, 1, 2, 1, 2, 86, 7, 1, 4, 3, 1, 1, 13, 17, 1, 1, 43, 1, 86, 1, 3, 5, 2, 1, 1, 4, 1, 2, 4, 4, 4, 2, 6, 1, 4, 3, 2, 1, 1, 6, 52, 4, 2, 43, 18, 1, 5, 3, 3, 7, 2, 3, 1, 1, 1, 6, 18, 1, 4, 1, 19, 11, 3, 3, 25, 1, 7, 2, 1, 1, 1, 1, 1, 2, 3, 1, 2, 5, 1, 1, 9, 2, 14, 1, 12, 7, 1, 9, 4, 1, 3, 1, 1, 1, 2, 9, 2, 2, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 2, 4, 1, 1, 2, 14, 2, 1, 1, 1, 1, 3, 1, 2, 2, 1, 2, 4, 54, 2, 2, 1, 2, 1, 9, 1, 1, 2, 1, 1, 1, 1, 1, 2, 7, 6, 3, 1, 2, 2, 2, 2, 2, 3, 3, 1, 1, 1, 1, 4, 5, 5, 1, 2, 1, 1, 1, 5, 2, 4, 4, 3, 1, 4, 2, 1, 1, 1, 3, 2, 11, 1, 1, 2, 11, 3, 1, 17, 2, 3, 7, 11, 4, 14, 4, 1, 1, 1, 4, 2, 95, 9, 1, 1, 3, 2, 1, 4, 34, 23, 3, 1, 4, 4, 1, 1, 1, 2, 2, 4, 1, 4, 11, 1, 1, 2, 22, 1, 2, 1, 1, 13, 1, 1, 5, 3, 1, 1, 4, 5, 3, 5, 4, 2, 3, 1, 2, 2, 1, 8, 23, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 6, 1, 2, 1, 1, 1, 3, 1, 4, 21, 2, 7, 1, 3, 2, 1, 2, 1, 1, 34, 11, 6, 15, 27, 3, 3, 3, 4, 3, 1, 1, 9, 1, 4, 5, 3, 1, 1, 1, 4, 2, 1, 1, 1, 2, 2, 3, 1, 3, 2, 3, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 80, 17, 2, 1, 13, 3, 1, 4, 1, 4, 1, 15, 2, 3, 2, 1, 3, 5, 4, 3, 1, 2, 3, 1, 1, 3, 1, 1, 1, 1, 1, 5, 2, 1, 1, 1, 1, 4, 2, 10, 3, 2, 7, 5, 7, 7, 1, 1, 121, 1, 15, 14, 21, 4, 4, 6, 8, 75, 6, 1, 14, 18, 1, 36, 2, 1, 46, 1, 1, 1, 1, 4, 2, 3, 123, 1, 1, 1, 1, 1, 2, 1, 9, 2, 3, 3, 7, 10, 1, 1, 1, 1, 5, 1, 1, 7, 2, 2, 3, 1, 5, 1, 1, 3, 12, 50, 5, 4, 2, 33, 11, 4, 9, 3, 9, 2, 3, 5, 4, 4, 3, 17, 1, 2, 1, 7, 11, 1, 4, 8, 6, 1, 2, 2, 1, 1, 3, 2, 3, 2, 5, 1, 13, 4, 1, 1, 28, 2, 1, 1, 19, 1, 4, 3, 2, 1, 2, 1, 1, 1, 3, 32, 1, 1, 1, 1, 6, 1, 1, 1, 24, 1, 3, 3, 4, 1, 4, 1, 4, 1, 1, 1, 25, 2, 26, 17, 11, 14, 10, 2, 1, 12, 1, 2, 8, 9, 1, 1, 1, 9, 2, 5, 7, 3, 1, 2, 1, 1, 1, 3, 1, 1, 2, 4, 12, 2, 5, 2, 1, 1, 1, 1, 1, 2, 2, 2, 7, 1, 31, 11, 17, 7, 2, 11, 1, 1, 2, 2, 1, 1, 1, 1, 1, 8, 4, 2, 1, 1, 11, 2, 7, 1, 1, 1, 12, 1, 1, 1, 2, 5, 3, 1, 5, 1, 1, 5, 1, 1, 3, 9, 3, 1, 10, 7, 3, 4, 22, 7, 6, 2, 27, 1, 2, 8, 11, 2, 1, 1, 2, 1, 2, 2, 1, 3, 1, 2, 2, 3, 1, 1, 22, 4, 1, 3, 5, 9, 18, 2, 4, 1, 58, 7, 1, 3, 2, 2, 8, 3, 1, 1, 6, 2, 1, 1, 1, 2, 1, 2, 1, 4, 2, 2, 1, 1, 1, 1, 2, 3, 1, 5, 1, 4, 9, 3, 4, 5, 1, 12, 13, 1, 2, 205, 2, 1, 3, 4, 3, 8, 1, 5, 4, 2, 10, 1, 2, 1, 38, 30, 6, 6, 1, 2, 1, 8, 4, 6, 4, 2, 2, 1, 7, 3, 58, 3, 1, 6, 2, 5, 21, 1, 4, 3, 3, 1, 1, 1, 1, 5, 3, 3, 1, 1, 19, 5, 17, 8, 1, 13, 1, 1, 3, 6, 8, 2, 4, 1, 59, 23, 3, 5, 3, 19, 3, 2, 12, 1, 1, 10, 1, 1, 12, 62, 1, 10, 30, 9, 2, 20, 28, 2, 51, 1, 1, 1, 4, 2, 1, 4, 1, 4, 3, 1, 1, 50, 6, 1, 1, 1, 2, 7, 3, 2, 2, 1, 5, 1, 16, 12, 4, 2, 2, 1, 7, 1, 1, 4, 69, 1, 4, 3, 3, 2, 7, 95, 207, 8, 6, 29, 10, 23, 3, 15, 1, 2, 4, 11, 8, 1, 7, 2, 10, 16, 49, 1, 1, 2, 14, 4, 1, 19, 2, 1, 3, 1, 75, 1, 104, 11, 11, 154, 57, 11, 2, 18, 36, 4, 2, 2, 1, 11 ],
									"whole_wordcloud_data_0000000001" : [ 3, 3, 8, 3, 1, 1, 7, 4, 15, 1, 1, 291, 2, 60, 4, 94, 2, 1, 25, 1, 47, 7, 2, 1, 115, 1, 1, 10, 2, 1, 1, 4, 1, 12, 5, 4, 2, 1, 5, 2, 7, 10, 4, 1, 1, 2, 3, 7, 2, 5, 19, 1, 1, 77, 22, 1, 3, 20, 1, 2, 1, 1, 1, 4, 3, 13, 2, 13, 1, 4, 3, 1, 639, 17, 1, 1, 1, 2, 125, 1, 2, 2, 4, 1, 1, 3, 3, 1, 1, 6, 1, 2, 7, 1, 5, 1, 497, 1, 1, 12, 1, 2, 1, 2, 1, 8, 1, 1, 20, 1, 1, 1, 1, 1, 6, 1, 1, 4, 9, 1, 1, 1, 1, 2, 1, 2, 1, 3, 5, 8, 2, 2, 1, 5, 1, 1, 1, 1, 12, 3, 76, 3, 1, 1, 2, 2, 3, 2, 1, 1, 1, 2, 157, 13, 750, 73, 17, 2, 2, 2, 2, 1, 3, 2, 1, 15, 4, 2, 1, 4, 1, 6, 4, 1, 4, 27, 6, 58, 1, 18, 4, 13, 2, 11, 6, 5, 1, 1, 1, 9, 3, 83, 1, 2, 1, 5, 12, 7, 1, 1, 15, 2, 1, 2, 3, 2, 116, 2, 3, 1, 3, 1, 2, 1, 1, 1, 1, 4, 2, 1, 1, 1, 2, 2, 36, 7, 1, 1, 34, 4, 1, 6, 1, 4, 1, 2, 1, 2, 3, 1, 4, 11, 5, 1, 1, 1, 1, 2, 1, 1, 11, 2, 2, 3, 11, 11, 10, 1, 4, 1, 18, 4, 2, 1, 3, 1, 3, 2, 4, 11, 1, 28, 6, 2, 4, 3, 1, 1, 18, 1, 1, 2, 2, 18, 1, 111, 7, 7, 2, 1, 3, 5, 3, 1, 2, 3, 1, 9, 1, 1, 3, 1, 15, 141, 11, 4, 3, 5, 2, 6, 10, 11, 4, 2, 2, 1, 2, 1, 1, 2, 38, 3, 4, 3, 34, 50, 38, 4, 10, 1, 2, 3, 1, 8, 2, 3, 4, 1, 2, 1, 21, 2, 1, 2, 1, 8, 7, 3, 4, 1, 1, 23, 37, 1, 1, 2, 1, 16, 34, 14, 10, 1, 7, 10, 5, 1, 2, 1, 15, 1, 51, 1, 4, 8, 1, 4, 4, 11, 1, 1, 29, 1, 2, 86, 1, 13, 11, 10, 5, 1, 1, 1, 5, 4, 3, 1, 1, 8, 2, 1, 3, 2, 3, 2, 1, 2, 5, 1, 1, 4, 2, 8, 27, 4, 4, 3, 5, 12, 1, 1, 13, 2, 22, 13, 1, 2, 4, 3, 5, 1, 3, 2, 72, 1, 1, 1, 1, 34, 3, 2, 1, 9, 2, 1, 63, 5, 1, 14, 3, 1, 1, 48, 12, 5, 3, 7, 4, 59, 3, 2, 1, 1, 1, 8, 4, 59, 4, 2, 3, 62, 9, 2, 19, 1, 2, 2, 2, 6, 16, 5, 16, 1, 2, 1, 7, 1, 4, 1, 1, 1, 1, 2, 6, 1, 3, 52, 1, 9, 1, 1, 1, 34, 2, 3, 7, 2, 4, 1, 10, 117, 12, 1, 3, 1, 1, 6, 1, 11, 4, 1, 1, 3, 10, 198, 2, 44, 13, 8, 1, 1, 2, 70, 2, 11, 1, 3, 3, 3, 1, 1, 1, 3, 2, 1, 1, 1, 2, 2, 749, 91, 1, 12, 3, 2, 2, 1, 4, 3, 8, 41, 1, 23, 2, 2, 243, 34, 127, 1, 1, 2, 4, 60, 7, 11, 3, 2, 2, 9, 1, 178, 1, 4, 6, 3, 1, 1, 1, 2, 58, 12, 4, 1, 19, 14, 1, 2, 1, 9, 46, 1, 1, 1, 4, 15, 5, 2, 2, 1, 6, 5, 1, 7, 1, 2, 6, 1, 6, 1, 4, 3, 8, 1, 14, 3, 3, 6, 1, 2, 7, 10, 1, 2, 2, 1, 18, 2, 4, 5, 1, 3, 1, 2, 3, 2, 3, 2, 1, 3, 1, 2, 1, 3, 5, 1, 2, 3, 2, 3, 2, 1, 1, 2, 1, 1, 2, 22, 11, 5, 1, 1, 3, 20, 1, 1, 8, 4, 3, 10, 3, 2, 1, 2, 1, 4, 2, 3, 2, 1, 1, 4, 4, 5, 5, 12, 14, 2, 2, 3, 1, 1, 1, 1, 2, 9, 1, 2, 2, 1, 6, 1, 4, 2, 10, 1, 4, 2, 4, 1, 1, 27, 9, 2, 2, 2, 2, 6, 1, 4, 3, 1, 1, 7, 13, 30, 1, 1, 3, 2, 1, 1, 1, 1, 1, 3, 5, 1, 1, 1, 1, 1, 1, 5, 1, 2, 3, 1, 2, 3, 1, 3, 1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 1, 4, 2, 9, 2, 2, 1, 6, 1, 1, 3, 1, 1, 1, 1, 1, 1, 92, 2, 2, 1, 2, 2, 1, 2, 1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 3, 7, 4, 4, 2, 2, 1, 9, 1, 1, 1, 1, 1, 1, 1, 8, 2, 5, 3, 1, 1, 34, 4, 1, 11, 4, 6, 1, 1, 2, 96, 1, 16, 1, 20, 5, 2, 2, 2, 2, 6, 67, 1, 59, 1, 3, 2, 2, 1, 17, 2, 1, 1, 10, 27, 1, 1, 2, 2, 1, 2, 2, 1, 4, 3, 19, 2, 1, 5, 8, 3, 1, 14, 1, 12, 2, 1, 3, 3, 6, 1, 1, 2, 3, 1, 2, 5, 2, 1, 1, 3, 1, 10, 1, 2, 4, 1, 2, 1, 2, 4, 3, 14, 2, 16, 3, 4, 3, 18, 5, 2, 1, 1, 6, 2, 8, 12, 3, 1, 5, 35, 8, 1, 1, 1, 1, 1, 1, 4, 2, 1, 2, 2, 2, 17, 2, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 40, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 7, 15, 1, 1, 5, 4, 1, 1, 50, 2, 3, 2, 3, 1, 3, 3, 1, 7, 5, 1, 4, 9, 2, 1, 1, 1, 3, 3, 7, 3, 1, 614, 1, 3, 30, 1, 1, 2, 20, 2, 1, 1, 7, 1, 1, 17, 69, 17, 4, 2, 1, 1, 7, 1, 1, 1, 1, 2, 7, 1, 3, 20, 1, 1, 4, 1, 1, 6, 2, 1, 9, 1, 1, 84, 1, 7, 29, 5, 18, 1, 3, 2, 3, 2, 2, 2, 4, 12, 1, 1, 1, 15, 4, 1, 28, 1, 1, 3, 1, 7, 6, 4, 2, 2, 1, 1, 1, 4, 34, 7, 1, 2, 3, 2, 3, 1, 1, 6, 5, 591, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 2, 1, 10, 10, 6, 5, 3, 33, 4, 4, 9, 13, 2, 3, 2, 2, 5, 1, 1, 5, 2, 1, 5, 6, 2, 1, 1, 19, 5, 4, 5, 4, 13, 1, 3, 1, 1, 18, 10, 5, 2, 3, 5, 11, 3, 2, 1, 7, 10, 2, 10, 5, 1, 11, 3, 1, 2, 15, 2, 1, 1, 2, 8, 5, 9, 5, 7, 2, 4, 1, 8, 13, 4, 6, 3, 4, 3, 1, 3, 4, 2, 2, 2, 1, 2, 8, 1, 1, 175, 1, 1, 3, 6, 1, 1, 1, 10, 3, 5, 1, 2, 1, 1, 61, 9, 1, 1, 1, 27, 5, 5, 1, 10, 7, 31, 3, 1, 3, 2, 1, 1, 24, 3, 5, 8, 4, 25, 1, 1, 19, 2, 5, 1, 1, 3, 3, 5, 1, 1, 1, 1, 1, 2, 1, 24, 2, 2, 2, 1, 4, 1, 1, 2, 1, 1, 2, 5, 1, 2, 7, 1, 1, 4, 4, 2, 2, 10, 1, 16, 1, 5, 6, 2, 1, 1, 1, 4, 2, 2, 1, 13, 2, 2, 1, 3, 1, 7, 1, 2, 8, 4, 1, 1, 15, 2, 1, 1, 5, 1, 2, 2, 1, 1, 3, 4, 7, 1, 2, 1, 9, 1, 1, 1, 4, 53, 4, 15, 1, 4, 2, 3, 3, 2, 1, 6, 19, 1, 5, 28, 6, 7, 1, 1, 1, 1, 9, 2, 1, 6, 2, 1, 1, 19, 9, 3, 27, 4, 4, 9, 5, 17, 22, 2, 10, 2, 3, 1, 4, 6, 1, 26, 1, 3, 2, 2, 14, 2, 1, 4, 1, 42, 2, 3, 8, 7, 20, 1, 1, 1, 32, 4, 2, 385, 1, 2167, 61, 1, 109, 4, 111, 112, 2, 20, 183, 2, 6, 2, 60, 39, 58, 12, 1, 1, 198, 2, 2, 12, 13, 81, 4, 2, 2, 33, 2, 2, 1, 17, 1, 4, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 24, 1, 84, 7, 4, 11, 1, 5, 1, 2, 9, 5, 2, 958, 2, 1, 4, 1, 12, 8, 2, 52, 2, 6, 27, 28, 10, 1, 5, 1, 3, 1, 1, 1, 1, 11, 1, 1, 1, 12, 1, 1, 2, 1, 8, 9, 1, 3, 8, 2, 13, 1, 1, 1, 20, 2, 3, 1, 2, 6, 4, 4, 1, 1, 1, 14, 15, 3, 2, 1, 2, 1, 1, 1, 14, 20, 13, 4, 78, 2, 2, 2, 5, 2, 4, 7, 9, 1, 6, 2, 42, 1, 1, 5, 4, 4, 1, 2, 2, 1, 1, 6, 1, 2, 1, 1, 23, 2, 9, 3, 2, 1, 2, 1, 1, 2, 3, 3, 1, 3, 11, 1, 8, 1, 1, 2, 3, 1, 5, 1, 1, 1, 112, 1, 30, 2, 5, 1, 1, 19, 30, 21, 2, 3, 6, 7, 2, 1, 1, 2, 1, 7, 2, 1, 1, 3, 2, 1, 3, 6, 5, 5, 6, 1, 173, 2, 1, 2, 2, 1, 1, 1, 2, 5, 1, 7, 59, 4, 2, 3, 6, 2, 2, 1, 2, 1, 1, 2, 1, 14, 12, 2, 4, 12, 6, 2, 1, 1, 2, 2, 14, 4, 2, 1, 4, 2, 401, 3, 3, 15, 2, 3, 8, 2, 3, 5, 1, 5, 72, 2, 48, 3, 1, 9, 4, 2, 1, 69, 108, 1, 96, 2, 1, 3, 186, 6, 1, 88, 2, 22, 1, 2, 15, 71, 32, 2, 4, 4, 5, 1, 1, 2, 32, 13, 78, 1, 19, 3, 2, 52, 3, 1, 2, 1, 3, 3, 2, 44, 7, 2, 2, 11, 4, 2, 3, 1, 3, 27, 265, 6, 43, 13, 1, 1, 2, 36, 20, 1, 3, 10, 8, 10, 1, 14, 26, 1, 61, 39, 9, 1, 2, 1, 3, 5, 101, 15, 12, 1, 4, 1, 6, 1, 10, 12, 6, 3, 3, 2, 2, 3, 2, 2, 2, 1, 4, 2, 2, 1, 7, 18, 4, 29, 613, 6, 91, 4, 13, 6, 1, 1, 1, ")" ],
									"whole_wordcloud_data_count" : [ 2 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.wordcloud" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 338.86972, 57.567627 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 116.5, 238.5, 567.5, 238.5 ],
									"source" : [ "obj-15", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-16", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-28", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-39", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-39", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 208.0, 66.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p example",
					"varname" : "basic_tab[3]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 0.0, 26.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-11",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 384.5, 308.5, 150.0, 54.0 ],
									"text" : "You can disable this behavior by setting autofit to 0!"
								}

							}
, 							{
								"box" : 								{
									"attr" : "autofit",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 221.0, 323.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"fontsizeslope" : -0.3,
									"id" : "obj-7",
									"maxclass" : "bach.wordcloud",
									"maxfontsize" : 18.0,
									"minfontsize" : 10.0,
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 221.0, 363.0, 161.0, 78.0 ],
									"space" : 4.0,
									"valign" : 3,
									"whole_wordcloud_data_0000000000" : [ "(", "absolute value", "accept", "action", "add", "addition", "address", "adjoint", "adjugate", "amplitude", "angle", "appearance", "append", "approximate", "arrange", "articulation", "assemble", "automatic", "average", "barline", "base", "basis", "beat", "belong", "binomial coefficient", "bit field", "body", "boundary", "box", "branch", "breakpoint function", "build", "calculate", "cardinality", "cartesian", "cell", "cent", "change", "channel", "chord", "chunk", "circle", "classical", "clip", "clock", "cofactor", "color", "column", "combination", "combinations", "combine", "complement", "compute", "compute", "concatenate", "condition", "constraint", "construct", "content", "convert", "coordinate", "coprime", "copy", "count", "crop", "cross product", "curve", "curve~", "cut", "decode", "delay", "denominator", "derivative", "derive", "detect", "determinant", "diagonal", "diagram", "dictionary", "difference", "discrete", "display", "distance", "divide", "division", "draw", "drip", "duplicate", "duration", "duration line", "each", "echelon form", "edit", "eigenvalue", "eigenvector", "element", "enharmonicity", "entry", "equal", "equation", "error", "expand", "exponent", "export", "expression", "extend", "extra", "extract", "factorial", "family", "fill", "filter", "filtercoeff~", "find", "flat", "floating point", "flow", "force", "format", "Fourier", "fraction", "frequency", "front", "function", "gathered syntax", "Gauss elimination", "generator", "glissando", "grace notes", "graph", "graphic", "greatest common divisor", "grid", "group", "header", "hexagone", "histogram", "identity", "if", "image", "imaginary", "import", "include", "index", "information", "insert", "integer", "integral function", "integrate", "interpolate", "interval", "interval function", "interval structure", "interval vector", "inverse", "inversion", "invert", "iterate", "iteration", "jit.cellblock", "join", "just intonation", "k-deck", "keep", "kernel", "key", "keychain", "kurtosis", "lambda loop", "lattice", "leaf", "least common multiple", "legato", "length", "let through", "limit", "line", "linear", "linear independence", "linear system", "line~", "look up", "loop", "magnitude", "main", "map", "marker", "matrix", "matrix", "matrixctrl", "maximum", "mean", "measure", "measured", "measureinfo", "measurewise", "median", "memory", "message", "metro", "microtone", "MIDI", "midicent", "minimal units", "minimum", "minus", "modify", "modulo", "moment", "monophonic", "multiplication", "multiply", "MusicXML", "name", "nearest", "negative", "norm", "normal form", "normalize", "note", "noteoff", "noteon", "nullity", "number", "occurrence", "onset", "open", "OpenMusic", "operator", "order", "organize", "orthogonal", "outline", "parameter", "parametric", "parenthesis", "part", "pass", "period", "periodicity", "phase", "pick", "pitch", "pitch-class", "pitch breakpoint", "plain", "play", "playout", "plot", "plus", "polar", "pool", "position", "power", "prepend", "prime", "prime form", "probability", "product", "proportional", "prune", "quantize", "quotient", "radius", "raise", "random", "range", "rank", "ratio", "rational", "real", "rectangle", "reduce", "reject", "remainder", "repeat", "repetition", "replace", "rescale", "rest", "retain", "retrieve", "retrograde", "reverse", "rhythm", "rhythmic tree", "rotate", "round", "route", "row", "sample", "sampling", "scalar", "score", "search", "secondary", "select", "separate", "separator", "sequence", "series", "set", "shift", "sign", "simplify", "singular", "size", "skewness", "slice", "slot", "smooth", "snap", "solve", "sort", "span", "spat", "split", "square", "square root", "standard deviation", "start", "statistics", "steop", "step", "stream", "stretch", "subtract", "subtraction", "sum", "summation", "swap", "symmetrical", "tag", "take", "talea", "tempo", "threshold", "tie", "ties", "time signature", "times", "tonnetz", "trace", "transcribe", "transform", "transpose", "transposition", "tree", "triad", "trim", "type", "unbox", "unitary", "unpack", "unwrap", "urn", "value", "variance", "vector", "vector product", "velocity", "versor", "voice", "voicewise", "weight", "well-shaped", "wrap", "write", "Z-relation", ")", "(", 1, 2, 3, 2, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 7, 6, 34, 1, 4, 1, 13, 3, 1, 7, 1, 1, 2, 1, 1, 1, 1, 5, 2, 1, 2, 1, 25, 8, 1, 2, 2, 1, 1, 27, 5, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 4, 2, 2, 1, 4, 3, 7, 6, 1, 3, 1, 2, 2, 10, 2, 1, 1, 5, 1, 1, 18, 3, 1, 1, 1, 1, 2, 3, 2, 1, 1, 2, 10, 1, 1, 1, 6, 1, 4, 1, 1, 2, 2, 2, 1, 2, 4, 1, 4, 1, 4, 1, 4, 1, 1, 3, 3, 3, 3, 1, 1, 1, 2, 1, 1, 2, 2, 1, 3, 2, 1, 3, 1, 2, 1, 6, 1, 2, 3, 2, 2, 3, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 3, 1, 2, 3, 2, 1, 1, 1, 4, 1, 1, 3, 3, 7, 16, 2, 5, 1, 3, 4, 5, 2, 1, 1, 1, 2, 5, 5, 12, 1, 5, 1, 1, 10, 5, 1, 5, 1, 1, 3, 2, 2, 2, 3, 1, 6, 1, 1, 1, 41, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2, 8, 12, 14, 3, 2, 1, 2, 1, 1, 3, 3, 2, 3, 1, 2, 3, 2, 3, 6, 1, 1, 2, 3, 2, 6, 2, 3, 4, 4, 2, 1, 2, 2, 1, 3, 4, 1, 2, 3, 1, 2, 1, 2, 3, 2, 4, 1, 3, 3, 1, 1, 1, 3, 2, 1, 5, 3, 1, 7, 1, 5, 2, 2, 1, 1, 3, 1, 2, 8, 1, 3, 1, 1, 1, 1, 3, 5, 2, 1, 2, 7, 1, 3, 2, 2, 1, 3, 7, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 3, 2, 4, 1, 2, 1, 1, 3, 1, 1, 2, 1, 1, 8, 1, 7, 1, 5, 2, 2, 2, 4, 3, 1, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-6",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 259.0, 127.5, 150.0, 54.0 ],
									"text" : "Try to unlock this patch and resize the wordcloud!"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-4",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 74.0, 513.0, 36.0 ],
									"text" : "When there's no space for putting all the words, bach.wordcloud will automatically choose the most important one, dropping the other ones. ",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"fontsizeslope" : -0.3,
									"id" : "obj-1",
									"maxclass" : "bach.wordcloud",
									"maxfontsize" : 18.0,
									"minfontsize" : 10.0,
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 119.0, 236.0, 71.0 ],
									"space" : 4.0,
									"valign" : 3,
									"whole_wordcloud_data_0000000000" : [ "(", "absolute value", "accept", "action", "add", "addition", "address", "adjoint", "adjugate", "amplitude", "angle", "appearance", "append", "approximate", "arrange", "articulation", "assemble", "automatic", "average", "barline", "base", "basis", "beat", "belong", "binomial coefficient", "bit field", "body", "boundary", "box", "branch", "breakpoint function", "build", "calculate", "cardinality", "cartesian", "cell", "cent", "change", "channel", "chord", "chunk", "circle", "classical", "clip", "clock", "cofactor", "color", "column", "combination", "combinations", "combine", "complement", "compute", "compute", "concatenate", "condition", "constraint", "construct", "content", "convert", "coordinate", "coprime", "copy", "count", "crop", "cross product", "curve", "curve~", "cut", "decode", "delay", "denominator", "derivative", "derive", "detect", "determinant", "diagonal", "diagram", "dictionary", "difference", "discrete", "display", "distance", "divide", "division", "draw", "drip", "duplicate", "duration", "duration line", "each", "echelon form", "edit", "eigenvalue", "eigenvector", "element", "enharmonicity", "entry", "equal", "equation", "error", "expand", "exponent", "export", "expression", "extend", "extra", "extract", "factorial", "family", "fill", "filter", "filtercoeff~", "find", "flat", "floating point", "flow", "force", "format", "Fourier", "fraction", "frequency", "front", "function", "gathered syntax", "Gauss elimination", "generator", "glissando", "grace notes", "graph", "graphic", "greatest common divisor", "grid", "group", "header", "hexagone", "histogram", "identity", "if", "image", "imaginary", "import", "include", "index", "information", "insert", "integer", "integral function", "integrate", "interpolate", "interval", "interval function", "interval structure", "interval vector", "inverse", "inversion", "invert", "iterate", "iteration", "jit.cellblock", "join", "just intonation", "k-deck", "keep", "kernel", "key", "keychain", "kurtosis", "lambda loop", "lattice", "leaf", "least common multiple", "legato", "length", "let through", "limit", "line", "linear", "linear independence", "linear system", "line~", "look up", "loop", "magnitude", "main", "map", "marker", "matrix", "matrix", "matrixctrl", "maximum", "mean", "measure", "measured", "measureinfo", "measurewise", "median", "memory", "message", "metro", "microtone", "MIDI", "midicent", "minimal units", "minimum", "minus", "modify", "modulo", "moment", "monophonic", "multiplication", "multiply", "MusicXML", "name", "nearest", "negative", "norm", "normal form", "normalize", "note", "noteoff", "noteon", "nullity", "number", "occurrence", "onset", "open", "OpenMusic", "operator", "order", "organize", "orthogonal", "outline", "parameter", "parametric", "parenthesis", "part", "pass", "period", "periodicity", "phase", "pick", "pitch", "pitch-class", "pitch breakpoint", "plain", "play", "playout", "plot", "plus", "polar", "pool", "position", "power", "prepend", "prime", "prime form", "probability", "product", "proportional", "prune", "quantize", "quotient", "radius", "raise", "random", "range", "rank", "ratio", "rational", "real", "rectangle", "reduce", "reject", "remainder", "repeat", "repetition", "replace", "rescale", "rest", "retain", "retrieve", "retrograde", "reverse", "rhythm", "rhythmic tree", "rotate", "round", "route", "row", "sample", "sampling", "scalar", "score", "search", "secondary", "select", "separate", "separator", "sequence", "series", "set", "shift", "sign", "simplify", "singular", "size", "skewness", "slice", "slot", "smooth", "snap", "solve", "sort", "span", "spat", "split", "square", "square root", "standard deviation", "start", "statistics", "steop", "step", "stream", "stretch", "subtract", "subtraction", "sum", "summation", "swap", "symmetrical", "tag", "take", "talea", "tempo", "threshold", "tie", "ties", "time signature", "times", "tonnetz", "trace", "transcribe", "transform", "transpose", "transposition", "tree", "triad", "trim", "type", "unbox", "unitary", "unpack", "unwrap", "urn", "value", "variance", "vector", "vector product", "velocity", "versor", "voice", "voicewise", "weight", "well-shaped", "wrap", "write", "Z-relation", ")", "(", 1, 2, 3, 2, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 7, 6, 34, 1, 4, 1, 13, 3, 1, 7, 1, 1, 2, 1, 1, 1, 1, 5, 2, 1, 2, 1, 25, 8, 1, 2, 2, 1, 1, 27, 5, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 4, 2, 2, 1, 4, 3, 7, 6, 1, 3, 1, 2, 2, 10, 2, 1, 1, 5, 1, 1, 18, 3, 1, 1, 1, 1, 2, 3, 2, 1, 1, 2, 10, 1, 1, 1, 6, 1, 4, 1, 1, 2, 2, 2, 1, 2, 4, 1, 4, 1, 4, 1, 4, 1, 1, 3, 3, 3, 3, 1, 1, 1, 2, 1, 1, 2, 2, 1, 3, 2, 1, 3, 1, 2, 1, 6, 1, 2, 3, 2, 2, 3, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 3, 1, 2, 3, 2, 1, 1, 1, 4, 1, 1, 3, 3, 7, 16, 2, 5, 1, 3, 4, 5, 2, 1, 1, 1, 2, 5, 5, 12, 1, 5, 1, 1, 10, 5, 1, 5, 1, 1, 3, 2, 2, 2, 3, 1, 6, 1, 1, 1, 41, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2, 8, 12, 14, 3, 2, 1, 2, 1, 1, 3, 3, 2, 3, 1, 2, 3, 2, 3, 6, 1, 1, 2, 3, 2, 6, 2, 3, 4, 4, 2, 1, 2, 2, 1, 3, 4, 1, 2, 3, 1, 2, 1, 2, 3, 2, 4, 1, 3, 3, 1, 1, 1, 3, 2, 1, 5, 3, 1, 7, 1, 5, 2, 2, 1, 1, 3, 1, 2, 8, 1, 3, 1, 1, 1, 1, 3, 5, 2, 1, 2, 7, 1, 3, 2, 2, 1, 3, 7, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 3, 2, 4, 1, 2, 1, 1, 3, 1, 1, 2, 1, 1, 8, 1, 7, 1, 5, 2, 2, 2, 4, 3, 1, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.wordcloud" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 341.210938, 53.625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 117.0, 53.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p autofit",
					"varname" : "basic_tab[1]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 349.0, 130.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-16",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 460.0, 444.5, 139.0, 40.0 ],
									"text" : "Corner roundness radius"
								}

							}
, 							{
								"box" : 								{
									"attr" : "rounded",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 306.382812, 454.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-1",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 435.0, 113.5, 184.0, 54.0 ],
									"text" : "You can also define a mapping slope for the font size (-1 to 1, 0 being linear)"
								}

							}
, 							{
								"box" : 								{
									"attr" : "borderwidth",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 339.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "bordercolor",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 194.5, 163.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "clickcolor",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 290.303894, 193.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "hovercolor",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-14",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 265.657227, 206.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "fontsizeslope",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.0, 130.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "minfontsize",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.0, 88.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "maxfontsize",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 280.0, 109.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-17",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 460.0, 387.0, 108.0, 54.0 ],
									"text" : "Show hand over hovered word"
								}

							}
, 							{
								"box" : 								{
									"attr" : "showhand",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 397.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "bgcolor",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-13",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 241.010605, 206.0, 21.0 ],
									"text_width" : 124.0
								}

							}
, 							{
								"box" : 								{
									"attr" : "textcolor",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 299.882812, 218.749115, 206.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "fontface",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 130.0, 206.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "fontname",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 101.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-31",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 433.0, 157.0, 19.0 ]
								}

							}
, 							{
								"box" : 								{
									"clickcolor" : [ 0.178238, 0.788043, 0.0, 1.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"fontsizeslope" : -0.3,
									"hovercolor" : [ 0.030087, 0.268828, 0.45, 1.0 ],
									"id" : "obj-19",
									"maxclass" : "bach.wordcloud",
									"maxfontsize" : 18.0,
									"minfontsize" : 10.0,
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 211.0, 260.0, 200.0 ],
									"space" : 4.0,
									"textcolor" : [ 0.25, 0.080135, 0.086031, 1.0 ],
									"valign" : 3,
									"whole_wordcloud_data_0000000000" : [ "(", "absolute value", "accept", "action", "add", "addition", "address", "adjoint", "adjugate", "amplitude", "angle", "appearance", "append", "approximate", "arrange", "articulation", "assemble", "automatic", "average", "barline", "base", "basis", "beat", "belong", "binomial coefficient", "bit field", "body", "boundary", "box", "branch", "breakpoint function", "build", "calculate", "cardinality", "cartesian", "cell", "cent", "change", "channel", "chord", "chunk", "circle", "classical", "clip", "clock", "cofactor", "color", "column", "combination", "combinations", "combine", "complement", "compute", "compute", "concatenate", "condition", "constraint", "construct", "content", "convert", "coordinate", "coprime", "copy", "count", "crop", "cross product", "curve", "curve~", "cut", "decode", "delay", "denominator", "derivative", "derive", "detect", "determinant", "diagonal", "diagram", "dictionary", "difference", "discrete", "display", "distance", "divide", "division", "draw", "drip", "duplicate", "duration", "duration line", "each", "echelon form", "edit", "eigenvalue", "eigenvector", "element", "enharmonicity", "entry", "equal", "equation", "error", "expand", "exponent", "export", "expression", "extend", "extra", "extract", "factorial", "family", "fill", "filter", "filtercoeff~", "find", "flat", "floating point", "flow", "force", "format", "Fourier", "fraction", "frequency", "front", "function", "gathered syntax", "Gauss elimination", "generator", "glissando", "grace notes", "graph", "graphic", "greatest common divisor", "grid", "group", "header", "hexagone", "histogram", "identity", "if", "image", "imaginary", "import", "include", "index", "information", "insert", "integer", "integral function", "integrate", "interpolate", "interval", "interval function", "interval structure", "interval vector", "inverse", "inversion", "invert", "iterate", "iteration", "jit.cellblock", "join", "just intonation", "k-deck", "keep", "kernel", "key", "keychain", "kurtosis", "lambda loop", "lattice", "leaf", "least common multiple", "legato", "length", "let through", "limit", "line", "linear", "linear independence", "linear system", "line~", "look up", "loop", "magnitude", "main", "map", "marker", "matrix", "matrix", "matrixctrl", "maximum", "mean", "measure", "measured", "measureinfo", "measurewise", "median", "memory", "message", "metro", "microtone", "MIDI", "midicent", "minimal units", "minimum", "minus", "modify", "modulo", "moment", "monophonic", "multiplication", "multiply", "MusicXML", "name", "nearest", "negative", "norm", "normal form", "normalize", "note", "noteoff", "noteon", "nullity", "number", "occurrence", "onset", "open", "OpenMusic", "operator", "order", "organize", "orthogonal", "outline", "parameter", "parametric", "parenthesis", "part", "pass", "period", "periodicity", "phase", "pick", "pitch", "pitch-class", "pitch breakpoint", "plain", "play", "playout", "plot", "plus", "polar", "pool", "position", "power", "prepend", "prime", "prime form", "probability", "product", "proportional", "prune", "quantize", "quotient", "radius", "raise", "random", "range", "rank", "ratio", "rational", "real", "rectangle", "reduce", "reject", "remainder", "repeat", "repetition", "replace", "rescale", "rest", "retain", "retrieve", "retrograde", "reverse", "rhythm", "rhythmic tree", "rotate", "round", "route", "row", "sample", "sampling", "scalar", "score", "search", "secondary", "select", "separate", "separator", "sequence", "series", "set", "shift", "sign", "simplify", "singular", "size", "skewness", "slice", "slot", "smooth", "snap", "solve", "sort", "span", "spat", "split", "square", "square root", "standard deviation", "start", "statistics", "steop", "step", "stream", "stretch", "subtract", "subtraction", "sum", "summation", "swap", "symmetrical", "tag", "take", "talea", "tempo", "threshold", "tie", "ties", "time signature", "times", "tonnetz", "trace", "transcribe", "transform", "transpose", "transposition", "tree", "triad", "trim", "type", "unbox", "unitary", "unpack", "unwrap", "urn", "value", "variance", "vector", "vector product", "velocity", "versor", "voice", "voicewise", "weight", "well-shaped", "wrap", "write", "Z-relation", ")", "(", 1, 2, 3, 2, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 7, 6, 34, 1, 4, 1, 13, 3, 1, 7, 1, 1, 2, 1, 1, 1, 1, 5, 2, 1, 2, 1, 25, 8, 1, 2, 2, 1, 1, 27, 5, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 4, 2, 2, 1, 4, 3, 7, 6, 1, 3, 1, 2, 2, 10, 2, 1, 1, 5, 1, 1, 18, 3, 1, 1, 1, 1, 2, 3, 2, 1, 1, 2, 10, 1, 1, 1, 6, 1, 4, 1, 1, 2, 2, 2, 1, 2, 4, 1, 4, 1, 4, 1, 4, 1, 1, 3, 3, 3, 3, 1, 1, 1, 2, 1, 1, 2, 2, 1, 3, 2, 1, 3, 1, 2, 1, 6, 1, 2, 3, 2, 2, 3, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 3, 1, 2, 3, 2, 1, 1, 1, 4, 1, 1, 3, 3, 7, 16, 2, 5, 1, 3, 4, 5, 2, 1, 1, 1, 2, 5, 5, 12, 1, 5, 1, 1, 10, 5, 1, 5, 1, 1, 3, 2, 2, 2, 3, 1, 6, 1, 1, 1, 41, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2, 8, 12, 14, 3, 2, 1, 2, 1, 1, 3, 3, 2, 3, 1, 2, 3, 2, 3, 6, 1, 1, 2, 3, 2, 6, 2, 3, 4, 4, 2, 1, 2, 2, 1, 3, 4, 1, 2, 3, 1, 2, 1, 2, 3, 2, 4, 1, 3, 3, 1, 1, 1, 3, 2, 1, 5, 3, 1, 7, 1, 5, 2, 2, 1, 1, 3, 1, 2, 8, 1, 3, 1, 1, 1, 1, 3, 5, 2, 1, 2, 7, 1, 3, 2, 2, 1, 3, 7, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 3, 2, 4, 1, 2, 1, 1, 3, 1, 1, 2, 1, 1, 8, 1, 7, 1, 5, 2, 2, 2, 4, 3, 1, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.wordcloud" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 341.210938, 53.625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 175.0, 84.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p appearance",
					"varname" : "basic_tab[2]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 299.0, 205.0, 178.0, 20.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
					"text" : "js helpstarter.js bach.wordcloud"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 0.0, 26.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-18",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 376.125, 343.0, 101.25, 40.0 ],
									"text" : "Save data with patcher"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "preset",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "preset", "int", "preset", "int" ],
									"patching_rect" : [ 290.0, 348.5, 76.0, 29.0 ],
									"preset_data" : [ 										{
											"number" : 1,
											"data" : [ 5, "obj-1", "bach.wordcloud", "begin_preset", 50, 56, "obj-1", "bach.wordcloud", "restore_preset", 0, 50, "Bach", 6, "Beethoven", 9, "Mozart", 5, "Boulez", 5, "Schönberg", 9, "Webern", 4, "Berg", 4, "Brahms", 10, "Mahler", 8, "Machaut", 2, "Desprez", 8, "Perotinus", 8, "Spontini", 8, "Iommelli", 8, "Traetta", 2, "Schubert", 3, "Schumann", 1, "Mendelssohn", 10, "Brückner", 6, "Stravinsky", 10, "Lachenmann", 2, "Berio", 6, "Ligeti", 9, "Kurtag", 5, "Sciarrino", 6, 4, "obj-1", "bach.wordcloud", "end_preset" ]
										}
, 										{
											"number" : 2,
											"data" : [ 5, "obj-1", "bach.wordcloud", "begin_preset", 50, 56, "obj-1", "bach.wordcloud", "restore_preset", 0, 50, "Bach", 7, "Beethoven", 10, "Mozart", 3, "Boulez", 9, "Schönberg", 4, "Webern", 3, "Berg", 10, "Brahms", 8, "Mahler", 2, "Machaut", 1, "Desprez", 5, "Perotinus", 3, "Spontini", 2, "Iommelli", 7, "Traetta", 9, "Schubert", 5, "Schumann", 6, "Mendelssohn", 8, "Brückner", 6, "Stravinsky", 5, "Lachenmann", 9, "Berio", 6, "Ligeti", 6, "Kurtag", 3, "Sciarrino", 2, 4, "obj-1", "bach.wordcloud", "end_preset" ]
										}
, 										{
											"number" : 3,
											"data" : [ 5, "obj-1", "bach.wordcloud", "begin_preset", 50, 56, "obj-1", "bach.wordcloud", "restore_preset", 0, 50, "Bach", 5, "Beethoven", 6, "Mozart", 9, "Boulez", 3, "Schönberg", 3, "Webern", 6, "Berg", 3, "Brahms", 9, "Mahler", 5, "Machaut", 1, "Desprez", 5, "Perotinus", 3, "Spontini", 1, "Iommelli", 9, "Traetta", 2, "Schubert", 1, "Schumann", 5, "Mendelssohn", 6, "Brückner", 6, "Stravinsky", 10, "Lachenmann", 3, "Berio", 6, "Ligeti", 2, "Kurtag", 5, "Sciarrino", 5, 4, "obj-1", "bach.wordcloud", "end_preset" ]
										}
 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 330.0, 436.0, 87.0, 21.0 ],
									"text" : "loadmess set"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-12",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 73.0, 192.0, 56.0, 25.0 ],
									"text" : "clear"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 34.0, 193.0, 32.5, 19.0 ],
									"text" : "null"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-21",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 170.125, 460.0, 238.0, 25.0 ],
									"text" : "Words are output when clicked upon"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 463.0, 148.0, 19.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 25.0, 239.5, 168.0, 40.0 ],
									"text" : "Send the plain list of the words in the left inlet"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "" ],
									"patching_rect" : [ 260.0, 192.0, 165.0, 21.0 ],
									"text" : "t b l"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-15",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 440.0, 239.5, 154.0, 54.0 ],
									"text" : "Send the plain list of the weights (metrics) in the right inlet"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 260.0, 218.5, 125.0, 21.0 ],
									"text" : "bach.arithmser 1 10"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 406.0, 218.5, 78.0, 21.0 ],
									"text" : "bach.length"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 260.0, 249.0, 165.0, 21.0 ],
									"text" : "bach.random"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-14",
									"linecount" : 3,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 125.0, 486.0, 48.0 ],
									"text" : "Bach Beethoven Mozart Boulez Schönberg Webern Berg Brahms Mahler Machaut Desprez Perotinus Spontini Iommelli Traetta Schubert Schumann Mendelssohn Brückner Stravinsky Lachenmann Berio Ligeti Kurtag Sciarrino"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-13",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 453.125, 383.5, 101.25, 40.0 ],
									"text" : "Save data with patcher"
								}

							}
, 							{
								"box" : 								{
									"attr" : "embed",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 295.125, 393.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.29,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"frgb" : 0.0,
									"id" : "obj-22",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 445.125, 296.0, 173.0, 40.0 ],
									"text" : "Weight range is mapped to this font size range."
								}

							}
, 							{
								"box" : 								{
									"attr" : "minfontsize",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 290.0, 296.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"attr" : "maxfontsize",
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 290.0, 317.0, 150.0, 21.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-1",
									"maxclass" : "bach.wordcloud",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 288.0, 269.0, 161.0 ],
									"whole_wordcloud_data_0000000000" : [ "(", "Bach", "Beethoven", "Mozart", "Boulez", "Schönberg", "Webern", "Berg", "Brahms", "Mahler", "Machaut", "Desprez", "Perotinus", "Spontini", "Iommelli", "Traetta", "Schubert", "Schumann", "Mendelssohn", "Brückner", "Stravinsky", "Lachenmann", "Berio", "Ligeti", "Kurtag", "Sciarrino", ")", "(", 2, 10, 7, 5, 6, 5, 4, 9, 3, 9, 8, 4, 7, 8, 2, 3, 9, 1, 2, 10, 7, 1, 5, 2, 6, ")" ],
									"whole_wordcloud_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpdetails.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.wordcloud", 93 ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 519.25, 115.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-16", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"disabled" : 0,
									"hidden" : 1,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-7", 0 ]
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
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 85.0, 50.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p basic",
					"varname" : "basic_tab"
				}

			}
, 			{
				"box" : 				{
					"border" : 0,
					"filename" : "helpname.js",
					"id" : "obj-4",
					"ignoreclick" : 1,
					"jsarguments" : [ "bach.wordcloud" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 10.0, 341.210938, 53.625 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 10,
							"architecture" : "x86"
						}
,
						"rect" : [ 0.0, 26.0, 627.0, 493.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
						"gridsnaponopen" : 1,
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
						"showontab" : 1,
						"boxes" : [  ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 205.0, 205.0, 50.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 13.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p ?",
					"varname" : "q_tab"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "helpname.js",
				"bootpath" : "/Applications/Max 6.1/Cycling '74/help-resources",
				"patcherrelativepath" : "../../../../../../../Applications/Max 6.1/Cycling '74/help-resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "/Applications/Max 6.1/Cycling '74/help-resources",
				"patcherrelativepath" : "../../../../../../../Applications/Max 6.1/Cycling '74/help-resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.random.maxpat",
				"bootpath" : "/Users/danieleghisi/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "helpstarter.js",
				"bootpath" : "/Applications/Max 6.1/Cycling '74/help-resources",
				"patcherrelativepath" : "../../../../../../../Applications/Max 6.1/Cycling '74/help-resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.split.maxpat",
				"bootpath" : "/Users/danieleghisi/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.change.maxpat",
				"bootpath" : "/Users/danieleghisi/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "/Users/danieleghisi/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.wordcloud.mxo",
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
				"name" : "bach.args.mxo",
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
				"name" : "bach.arithmser.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.sort.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.trans.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
