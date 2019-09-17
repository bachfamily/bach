{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 5,
			"architecture" : "x64"
		}
,
		"rect" : [ 12.0, 44.0, 805.0, 545.0 ],
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
					"fontsize" : 12.0,
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 300.0, 76.0, 20.0 ],
					"text" : "bach.wrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-36",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 458.0, 433.0, 291.0, 33.0 ],
					"text" : "This does not solve our issue: how can we formalize condition 3) ?"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-29",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 312.0, 327.0, 110.0, 21.0 ],
					"text" : "Constraint rules",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-45",
					"linecount" : 7,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 458.0, 330.0, 291.0, 100.0 ],
					"text" : "We start by stating constraint corresponding to condition 2): no two queens should be on the same row. This is nothing complicated: it just states that variables must have pairwise different values, which is the same constraint we have already encoutered several times, and we've usually called it \"diff\". Now we call it \"row\", but it's essentially the same thing."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-41",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 368.0, 225.0, 195.0, 21.0 ],
					"text" : "Constraint names and scopes",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 276.0, 107.0, 20.0 ],
					"text" : "bach.prepend row"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-38",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 252.0, 66.0, 20.0 ],
					"text" : "bach.flat 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 228.0, 79.0, 20.0 ],
					"text" : "bach.comb 2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 238.0, 199.0, 373.0, 20.0 ],
					"text" : "<< The domain for each of the n variables is from 1 to n (default = 8)"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-72",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 172.0, 202.0, 65.0, 21.0 ],
					"text" : "Domains",
					"textcolor" : [ 0.564706, 0.003922, 0.003922, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-65",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 121.0, 222.0, 107.0, 20.0 ],
					"text" : "number of queens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 10.0, 209.0, 36.0, 36.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-59",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 70.0, 222.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-57",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 73.0, 379.0, 240.0, 33.0 ],
					"text" : "<< Here we take the solution and translate it into messages for [matrixctrl]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-55",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 10.0, 274.0, 153.0, 20.0 ],
					"text" : "bach.repeat 8 @inwrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 4,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 10.0, 249.0, 139.0, 20.0 ],
					"text" : "bach.arithmser 1 8 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-35",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 166.0, 776.0, 33.0 ],
					"text" : "How can we model this problem? Since no two queens should be on the same column, we can have n variables, each representing the position of a queen on a column (thus from 1 to n). This guarantees condition 1), thus we'll need to state two constraints for conditions 2) and 3)."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-34",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 128.0, 93.0, 651.0, 74.0 ],
					"text" : "The n-queens puzzle can be restated as a constraint satisfaction problem. Indeed, in order for the queens not to eat each other, there are three rules they need to undergo:\n1) No two queens should be on the same column\n2) No two queens should be on the same row\n3) No two queens should be on the same diagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 5,
							"architecture" : "x64"
						}
,
						"rect" : [ 360.0, 44.0, 388.0, 323.0 ],
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
									"comment" : "",
									"id" : "obj-2",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 227.0, 25.0, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-35",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 227.0, 69.0, 155.0, 18.0 ],
									"text" : "columns $1, rows $1, clear"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "clear" ],
									"patching_rect" : [ 37.0, 55.0, 172.0, 20.0 ],
									"text" : "t l clear"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 78.0, 175.0, 32.5, 20.0 ],
									"text" : "- 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 37.0, 175.0, 32.5, 20.0 ],
									"text" : "- 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-40",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 37.0, 115.0, 66.0, 20.0 ],
									"text" : "bach.flat 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"patching_rect" : [ 37.0, 85.0, 135.0, 20.0 ],
									"text" : "bach.iter @maxdepth 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 37.0, 205.0, 100.0, 20.0 ],
									"text" : "pack 0 0 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"patching_rect" : [ 37.0, 145.0, 100.0, 20.0 ],
									"text" : "bach.iter @out t"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-30",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 37.0, 25.0, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-31",
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 37.0, 250.0, 25.0, 25.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 199.5, 236.0, 46.5, 236.0 ],
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-35", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-29", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 236.5, 243.0, 46.5, 243.0 ],
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-36", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-36", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-40", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 384.0, 58.0, 20.0 ],
					"saved_object_attributes" : 					{
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
					"text" : "p display"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "matrixctrl",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "list", "list" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 414.0, 95.0, 95.0 ],
					"presentation_rect" : [ 0.0, 0.0, 130.0, 130.0 ],
					"rows" : 8
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 315.0, 437.0, 81.0, 20.0 ],
					"text" : "bach.!="
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 315.0, 410.0, 81.0, 20.0 ],
					"text" : "bach.pick 1 2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "bang" ],
					"patching_rect" : [ 315.0, 385.0, 113.0, 20.0 ],
					"text" : "bach.keys row diag"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "", "float", "" ],
					"patching_rect" : [ 10.0, 358.0, 324.0, 20.0 ],
					"text" : "bach.constraints @solutions 1 @random 1"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 99516, "", "IBkSG0fBZn....PCIgDQRA..BfE..H.VHX....fulgI2....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6ctGbbcWd9+4b+b1qRqtYKa4jXGaKeIw4hct.w0wITBDZRa.RKkBTnPocxLos.Cszo+CC+UmLcxvuR6zFFnCTRXfDflBtjRRnPIItN33DRBD6bw1x2jsrtsR6ky8y42en48q+tajsURrhVs58yLZz5U6kyd1wZezy666yqRZZZJXXXXXXXXXtfg5B8A.CCCCCCCS6Fr.KFFFFFFFlKvvBrXXXXXXXXt.CKvhggggggg4BLr.KFFFFFFFlKvvBrXXXXXXXXt.CKvhggggggg4BLr.KFFlELRRRv4JJ9pWuNRSSQXXHpToB788QZZJRRRD2W5q2LO9LLLLyWnvAMJCCSqDx+Jo33Xnqq2vOOJJRHzJWtbmyGqjjDnnn.EEk4kiUFFFlyFr.KFFlVBlseUTRRBBCCQTTDTUUgppJTTTfggATUO+FvyBrXXXVnfEXwvvrfCUJulECEGGizzTXXXH92T4ACBBP974E2V4eUl7kYAVLLLKDne9uILLLLyOPBqlMmlZVvUZZJBBBfkkELLLPXXHRRRZ31K+c.Lmb4hgggY9.VfECCyBFxMqtrXHxoJMMM344ACCCnnn.eeenppBKKKnqq2f.KB1TdFFlVA3+7NFFlVJRRRDMxtllFbccguuOLLLfttNBBB..fss8rNEgjqWbYAYXXVHg6AKFFlELHmpnxAppphjjD366iff.7nO5ihm7IeRL5nih74yCUUUrpUsJbS2zMgK+xubXYYA.HDSIKpR95XwVLLLucCKvhggYdCeeeXYYIlDPGGGL8zSCaaanqqCUUU366C..MMM7pu5qhG5gdH7XO1igwGebL4jShpUqJxCKMMMjISFrrksLzWe8gMu4MiOvG3CfK6xtLzYmcBCCCTqVM333.WWWXaaKJ8HMIhZZZ..HHH.lllKXmaXXXZugEXwvvLuhmmGzzzfpppP7illlnre..uxq7J36889d36+8+930dsWSDEC0pUSzKVFFFB2sTUUgssM5niNfmmGV25VG9a+a+awV1xVv.CL.pToBxkKm39BfWWoDSRRdcYrECCCyEJXAVLLLyaDEEgnnHjllBGGGLwDSfN6rSQ.hdzidT7POzCg+i+i+C7RuzKgxkKCMMMg.LBRfUbbLBCCA.DkSj991111v5V25vce22Mt5q9pQ0pUQ1rYghhBzzzfhhBRSSQTTTCWGCCCy7Ar.KFFl4MpToBxmOOld5oQtb4PbbLBBBPTTDBBBv+1+1+F95e8uNd0W8UQ974giiCpWuNBCCENbQBzTUUEtPYXX.aaajjjfhEKhgGdX..jKWNb8W+0i+9+9+dbUW0UgnnHQDPPNYEGGCEEE18JFFl4U3oHjggYdCpDfJJJHHH.oooB2q91e6uM9ZesuFN1wNFxjICLMMwXiMFpVsJTTTfooIhhh.vLNXoqqKbcRd2DNxHi..HDb8S+o+Tbu268hgFZHnqqCcccg6U.PjH7LLLLymv+VFFFl4MrssgmmGLMMghhB777PgBEfhhB9VequEN5QOJ777fmmGld5oQRRBrssEhqHGqnnan4buhDrUrXQXXXf50qiLYxfu+2+6ie1O6mIJgnrHKZc6DGGu.cVgggYo.r.KFFl4MHgQTFVoppBOOO7S9I+D7xu7KKbXRWWGlllvxxRH1B.Mz6TTnjRM3dlLYP1rYA.P0pUESDXbbL777vK8RuDFYjQZnWtnUuC26ULLLy2vBrXXXl2HLLDYxjQHRx11FG9vGF+q+q+qHLLD0qWG.yDYB0pUCQQQB2ljcbhlBQpzd999nd85nVsZnXwhHIIQ3NlqqK5omdv27a9MwvCOLpToB.NyhilJUHKxhggY9DVfECCy7FjiSAAAHLLDggg3IexmDu3K9hv22WTpNRPURRhnzcjiUwwwMrjmIWn.loDgSM0THMMEttthxQN8zSiJUpfG3Ad.TnPA344gzzTjMaVwwBKvhggY9DVfECCy7F111h.9zwwA5553XG6XX7wGWz.7uUn4kCMI.iDy8XO1igQGcTnoogff.DGGCSSSwzIxvvvLeAKvhggYdCZ5AoR6YXXfJUpfff.QI.OWec9n4cPHccz524Tm5THIIQrrnoxLJ6TFCCCy7Ar.KFFl4Mj62IWWW..333fLYxHVZyWHd7AfX5.kER0SO8.SSSQhtqnnHB+TZOFxvvvLe.KvhggYdC4k3LQyQsvExmKpOsHgWQQQhfKkHNNVHFigggY9BVfECCy7FxS9miiiXR9788ufrnkmsdvRt7hFFFPSSCVVVPWWWD1ozkYXXXlufEXwvvLuAsVaHgMpppXEqXEnXwh..hR5c19Zt73SPNkoooIxIq2065cgt6ta.LSlZQhv.PCtZwvvvbgFVfECCy7FzDD555JBOzMtwMhUtxUdAsGrHwUzNJLa1rHe9731tsaCYxjAiO93HLLTHxBXlIbjgggY9BVfECCyaYNaS8G0P4NNNnPgBHLLDacqaE2xsbKHWtbhIIjJgGkR6jXoyGlllvwwQ33kmmGrssw3iONt4a9lwUdkWIhiiQmc1on2qxkKmXYSyvvvLeAKvhgg4BFMKxhx9p33XToREnnnft5pK7tdWuKrhUrhF5MpvvPQJtSAK54CJtGn.Msqt5B0pUC555XCaXCHSlLhTfmtcIIIPQQgcvhggYdEVfECCyETjEYUsZUjllBGGGjMaVQbMbYW1kgq4ZtFwRc1xxBVVVv22WrvmmK4TUu81KrrrDNg444gjjD79deuObG2wc.MMMwskbHSVjECCCy7Er.KFFl2xHGxmxkKjRxc40hSRRBV9xWN9q+q+qwN1wN.vLkRryN6D.y3JkggwbJnQmbxIwjSNIxlMKbbbPsZ0Pu81K9HejOBV25VGhiiEkoTdhFmuhJBFFFFBVfECCyaZZVDjbTI..QI+777PTTDzzzP1rYwTSMEV25VGty67NwMbC2.TUUwXiMlvkoZ0pAGGmy6yO0T6TYFW9xWNt4a9lw63c7NfuuuHA2IgV.P31EKxhggY9DVfECCyELZ1AqxkKCcccjISFwNBjVeNlll3Nti6.OvC7.3u7u7uD.y3rT974mykvKJJB555nb4xvzzD28ce23u6u6uC82e+HHH.555hdvJJJBggghGatDgLLLymvBrXXXdSyYaW.ReoqqCfYROcWWW366ivvPzUWcgvvPTqVMrpUsJbMWy0fUspU0PY7pWu9484OLLDpppnToR3ltoaBu2266EWxkbInZ0pHLLDSN4jhcQnppp33hbwhgggY9BkT92xvvv7lDZ58HBCCEAJplll3e655h74yCMMM7RuzKgQFYD7i9Q+HL5nihW60dML4jShwFaLTtbYXXXHJy34KLPMLLPXXHxjIiXpDcccwkbIWBtwa7Fw6+8+9w.CL.xkKWCqQGxEqKDoIOCCCyrAKvhgYQNIIIHNNtgRdQNAI2f2z0StJUoREjMa1FDHIGbmxLaNUQWO0eS111HHH.999BAMZZZv00Ettt3zm9zX26d23ge3GF+xe4uDSLwDMzKTxGazw8bE4E7r7Red0qd03C9A+fX6ae6XEqXEXfAF.YxjQzeV.y3tlooIbccESu3XiMFV1xV1b94+bAMMjzDMRutn9FS10tnnHQ52K+9BCCyhOXAVLLKhY5omFYxjoAgITYvRRRfttdC+LWWWQvdZZZJJWlb48.diIvhxWp33X344Accc333.OOO..7y+4+b7HOxifm64dNb3CeXLxHifvvPwDFRtJQtdonnfnnn4TLMHeLQhrjWtz999He97v11FaZSaBenOzGB6XG6.Ke4KGEKVDAAAHHH.4xkC0pUC0qWG8zSO..XjQFA80Weugd+nYZVbUym2lMRRRDu9mKM5OCCSqIr.KFlEw355BKKKgaUj6G.P3rDk8ST5nStNQA.JIJg3r8g+y1upfxspjjDjKWNwwT850wwO9ww8ce2Gd1m8Ywu5W8qDQ0fraZwwwBAgxtOMWCZTYls8XnhhBxmOunA26niNvZW6Zwsca2F9fevOnnuupToBzzzPlLYP0pUQTTDxmO+qyEo2rMFOIZR90I89f7iM0P9uUe9XXXV3gEXwvrHGpbZJJJhXNflXOpjWtttBADgggnd85PWWWHNq4xDJ6nUyhujuruuObbbPbbL788guuON4IOIdzG8QwW6q80vvCOLlZpoDMZt7skbtR10L545MaDJHerRmOHwM.y3jTRRBJTn.t3K9hwccW2E9ve3OLrssQsZ0PwhEEt7YXXHb+6r8bb9HHHngkLsllVCtY466CSSyFdcShvXwULLKtgEXwvrHlvvPgKUVVVHMME0pUSr1Yj6wpzzTgXLMMMXZZJD.H+g9MKvB30WVPR.TRRhv8Gccc7i9Q+Hbu268hW3EdADGGCKKqFbtgD9c1n4m2KDjISFXaaKR5cWWWnpph74yiN5nCbq25sha+1uc7NdGuCXZZh33XjMaVTtbYTnPgW2wVyW9bgmmmnrmx2uvvPDDDzfPNYGrRSSQPP.rrrtfcdfgg4sWXAVLLKhw22ugEiL4NjggALLLfmmWC4AUTTjnApqVsJbbbDBrlsxDNaBrjcdpZ0pv11F6e+6GO3C9f3AdfG.G6XGSTdMZU4..wyAUZr2NB5yN5nCDDDHbkB.hcPXXXHzzzPPP.txq7Jwm4y7Yv66889Ptb4DkbkNu1r.o2HtKIOnAz4.Y25n2yHAozjMRYEFCCyhSXAVLLKhINNV39DEhmpppnd85nb4xHHH.G6XGCdddhEb7F1vFPO8zClXhIDKCYxAEB4lWu4P4TNtCLLLvt10tvW4q7Uvu7W9KQkJUfooIbbbvDSLA5ryNQXXnH+q.NyD+c9RS8KTYUkhhBxjICrrrDMieXXH777P1rYQXXHhiiw.CL.9ze5OM9ze5OM5pqtDhGkEU8lQfk7fEDFFJhihnnHXZZht6taTpTIQoDoyMxB7XXXV7AKvhgYQLTStSMzN0iS6cu6E+7e9OGO7C+v30dsWSDZm80We3O4O4OA+w+w+whoqilzvYqWqZdJCANi.qjjD7C9A+.b+2+8i+q+q+KnooIlFO4FU2zzDFFFutjTuY2wZdREIAduQQ9XkhjAxkNYwNjqdSO8znToRXhIl.8zSO3dtm6AerO1GS3hk7wyaTAVwwwhxvljjf8u+8ie3O7GhexO4mfCcnCgUtxUha8VuU7A9.e.rwMtQnqqKJgKGSCLLKtQ6K9E+hewE5CBFFlYPdO9QhTn3OPdku..QIkpUqFz00gmmGrsswt28tw8bO2Ct+6+9wgO7gglllvIjwGeb7LOyyfQGcTr90udTpTIQNPQBfnUYi7DGRMQO80DSLAd5m9owe0e0eEdwW7EEtuPk0R1sJ4cA3aDASWH9a+nmS54kDsQNEEDDHtcjaUG4HGAoooXyadyhWOZZZXrwFSDNokKWVHZSVvnmmmvUQEEEwP.bfCb.be228gu5W8qhcsqcgW4UdEjllhSdxSh8u+8iidziJd+PQQAiM1Xhoxrd85vvv.SM0TvxxB999hUDDCCSqKr.KFlVHZdh5noLilNP5CxoxrUtbYTrXQg.FMMM7M+leS70+5ec355BSSSTudcwG7633f50qiCcnCg8rm8f0rl0fb4xghEKholZJL8zSirYyJbbhJ4W0pUaPjzy8bOGt669twHiLhXhDANi.QJ9AnHhfhiAh2tlPtlcbhDZImUXMW1vgGdXbhSbB7hu3Kha9luYQeZUrXQ366iIlXBzc2cKdrZNpIrrrfhhBJWtLbbbvi+3ON9G9G9Gv8e+2ON3AOHBBBDOuzTK97O+yigFZHbq25sh74yiZ0pIdeVt+shiiEtNN0TSI5mLFFlVO3+DHFlVXHQUSN4jXO6YO3W8q9UHNNFW0UcUX6ae6nyN6DCMzPv11FKaYKCG+3GG+leyuQrtYnXJHLLTTpNOOOTtbYru8sO7w+3ebricrC7I+jeRbC2vMfN6rS.LS.lZYYgN6rSL1Xigt6taTqVMjMaVLzPCgu3W7KhW4UdEwwI4fkbeUQtl0bhruPsG.a94TNSpnRjRSk4K8RuDN1wNF5pqtvm5S8ovxV1xDu9MMMEQ+.UVVcccDFFJJAIct9y+4+7X26d23W9K+k..vwwQbdILLDiO93..nPgBXngFBkKWFYylE80WenVsZhHbfNFmd5ogqqKJVrHGBoLLs3vBrXXZQPtum.lQHhkkENvAN.9e9e9evO3G7CvS8TOEhiiw1291wgO7gwsbK2BV6ZWqXRzBCCQ0pUgqqKJTn.ld5oEtePNRkjj.GGGw5r4G9C+g3Dm3D3i7Q9H387ddOB2YrrrDkcrRkJHe973ke4WFeouzWB6d26FkJUBSM0TBASyV7KLag+4aGSOXymSkOdjOtHwejXTaaaQY+ld5ow+u+e++vxV1xvccW2kH02srrvjSNoPjy3iONBBBPoRkPgBEvDSLAdjG4Qvt10tvi+3OtX+JRYPVkJU.vLqJmksrkgSdxShjjDTsZUgP0Se5Sim7IeRru8sOXXXfK9huXr8sucrl0rFToRE366+114PFFl2bvBrXXV.4bEjmz+9AevGD2+8e+hdCRQQA+hewu.6e+6GO8S+z3y9Y+r3xu7KWzqUc1YmvzzTDgCx8ejhhBLLLPbbLFe7wQRRBrsswy8bOG16d2Kdmuy2I9y+y+yw0dsWKRSSQGczgnjWm5TmB2y8bO369c+tnXwhXrwFSD4CTYxbbbfpppHKtneF.Z3XgNdlucxhdMKufmoyqxSHYRRBBBBPTTjHOw777fppJ9G+G+GwpV0pvse62NFczQQTTjHJGnRGpqqiQGcT7nO5ihG9geX7rO6yhSe5SizzTQuZQkfjttjjDL7vCKJAawhEQTTDd1m8YwW8q9Uwi7HOhXfAV9xWNd2u62M9ReouD5omdPbbLpWuNWhPFlVX3dvhgYAlYSfEccm7jmDekuxWA6cu6EwwwHe97vwwA0pUCUqVEG9vGF6YO6AkKWFqe8qG82e+X+6e+3ke4WFkKWVru+jazc4lkumd5ASO8zPQQAczQG3nG8n3AevGD+3e7OVjB6u1q8Z3Dm3D3a+s+1369c+tHLLDVVVv00sg8+mttN5qu9PGczgnjj.mYe70LjaMymHmuWxmaoKSMvNEMBMmUUNNN3Tm5T3PG5PXvAGDaXCa.NNNhXn..3oe5mF+fevO.e6u82FOzC8PX26d2X7wGGFFFBARz4HKKK333zP5xSwGQkJUvANvAvC+vOLd5m9owzSOsPbVkJUvAO3AQe80G13F2nPzay63PFFlVGXGrXXVfo4P8T1UqScpSgwFaLnqqKljLpQpylMKbccwK8RuDFZngvQNxQvce22MFczQwwN1wvpW8pwjSNIbccENLQNHkMaVXaaKlLMMMMb5SeZnoogRkJgidzihu7W9KCSSSroMsILzPCAWWWjjj.eeeTnPAXaaKlBOpDac1YmnyN6TDCBSN4jXhIl.UpTogLdhtOucbtUNtCnL+hJoIc7SPBeHgVgggnyN6D6ae6C+S+S+SvwwA4ymGu1q8Z3HG4HXngFBO0S8T34e9mG0qWWzSWZZZnVsZvxxB4xkC999hgAfdtod4h5sqzzT73O9iizzTjOedwDj533fLYxfZ0pgcsqcg26688JlvSFFlVWXAVLLsfPhrpWutnmcbbbPPP.xkKGBCCwDSLgP3U0pUw+x+x+B18t2sXEur10tVL7vCKJmDUZPx4HJCsHGtnoTqb4xHIIQ7g7O6y9rnqt5BAAAPQQAKaYKCm5TmRzH8zzERNUkKWNnnnfb4xIbqgD4QtC07TENegbYAIW7jSxcOOuFNmSA7I4NDcYSSS7fO3ChW3EdAzSO8f8u+8i33XTsZUQzVPmKoEqstttHU8ooBTNNLHmHIgVtttvwwAQQQBgeTezQSd3t28twTSME5omdP1rYm2O+wvv7lGVfECyBHx8Gj70QWe974wZVyZvq9puJBCCQWc0ElbxIENa355hLYxHDg8Zu1qgZ0pID2bsW60ht5pKru8sOwsA.BWcn8gGEDo.Pzr5UqVUbbQS6FvLtpAblrihDX..bjibDnpph95qODEEI5Ooff.LxHiHDs.LiKZ0pU6B94TYndcRSSCEJT.EKVDFFFnd85nVsZm0me42SjEgcfCb.bfCbfY81Ke6HwlztDTVvLE9pT1lYXX.WWWQIbomWJiy5pqtPTTDpUqlv0wrYy1PJ9yvvz5AKvhgoElAFX.QI7TTTvoO8oAvYb1.3Lhj.NyGrGDDfie7iiUu5Uiksrkgt6taQJpStg.zX+HQku6MhyRttthDQmJe3oN0oDSunssM5qu9Pu81qXZ6nRK91wjvQhqnxrQtE0r6UyWDEEIdclMaVDDD.UUUzau8hff.TsZUwdHTN07oRMRIQePP.5qu9ve1e1eFt7K+xQbbLbccEgQJCCSqGr.KFlEXjaB6lCfyRkJgO1G6iAeeerm8rGgPA4FGWNdDhiiEkf6vG9vXkqbk.3L8djbO.0bSlKm55yEn6Kk0VpppHe97HMMEm5TmRrq8HAhlllh935M6Zv4MJjSTzq450qKhJAWW248mepernxyFFFhMtwMhMsoMgidzihW3EdAw6ET3tJuLs6niNvIO4IQ974w1111ve3e3eH5niNPbbLmj6LLs3v+OTFlVTTTTPsZ0vcbG2AhiiwvCOLdwW7EEBwnlbmDUQhinPybhIl.O0S8TXkqbkvyyCFFFnPgBPQQAUpTQzyUxoa94JxHlMH2q777fooI5pqtDO9dddv22GCMzPhE.M8ZB3smRDBLyqCZ8xPB6lsL6Z9.48CYXXnXWCVtbYgCZZZZho8jDkRhe888ghhB9s+s+swG9C+gw.CLfno34cUHCSqMbLMvvzhfr3F5xUpTAYxjAqbkqDppp3.G3.XrwFS3LD4BCIphDXQIKd850Q974QTTDLLLPwhEEMlN0j5MWVvYyUqy1psQNvNSRRPgBEPbbLlZpoDGK0qWWrxezzzfuuORSSaXJDmufJ0F.DSkGIHUdhFmufZp8ff.Lv.CfAFX.bricLbvCdP..QS0C.QoDKTnPChdui63NvccW2Etoa5lDK1axsKtGrXXZcgcvhgoE.4cLnLczQGhw8+i9Q+nX4Ke439tu6COwS7DMzX5xkbiDMIW1IJ5AnOTtPgBPWWWD1nxKY5y0wHPiBvjcLC.3zm9zHJJBtttBWXndyhZJaxEG4lte9BpbjTNTQG+uckl7TjZTsZUnpphrYyBcccToREw6GjyV.mYBLIm81wN1A97e9OOt5q9pQXXnX4QK22cLLLslvBrXXZQQ14nxkKit5pKbm24cJb9Yu6cuHHHngdwgbqgDTkKWN344gJUpHlRMZBDsssEgboboBadAISLaefNIribCSVzD8yn6WXXnHc2e6ZYOSG2jqUxW2aGPSJXZZJN1wNlHtFJTn.pUqlvMOJg8o9TC.Xm6bm3S9I+j3pu5qF.y3lobxsSA4JCCSqIr.KFlVXnO3sToRvyyCAAA387ddOvvv.268du3IdhmP3HD.D8UUTTDz00Q1rYE2O.fZ0pIDDEDDH9NUtLYQHMuZalMnv3jtr70SkkjdLLMMESxHs2+lumjOpA7a1gN4Ujy7Ixkw0xxpgxkVqVMgnW.H1ijQQQXyady3u4u4uAW+0e8v00EtttnToR.Xl2CyjIy75wMCCyacTRYelYXZogbfgv00EkKWFUqVE2y8bO3wdrGSjMUjHmff.zau8hRkJgQFYDQStSkpqyN6DkJUBSLwDBwUTZiSk8yxxRbeno+C.BGnd6rTaKlQNRMHWmrssQ0pUghhBJTn.lbxIE2tssssguvW3Kf2065cgLYxbN6Ct2NcBjgg4MFbStyvzhC0CUxkRJSlLHe97XSaZS3RuzKESLwDXngFB.yj36zdAjZpbpernxzImb6TYEoGeRbkoo4qaZ0jEVw+sYyMH27n8GHkH9ggghzXmJo6uyuyuC9betOGtka4VDKSZRbcyBslsd1iggo0AtDgLLs3H6XD0n3FFFvvv.abiaDqd0qFVVVHSlL3W+q+0hDeOe973Dm3Dv22WDmBziUTTD777DB2n9vR1oLpzZjnL4dzRNfRYN6PBbIgwzjBRqeGpw06qu9v5W+5wm9S+owsbK2BTTTDIoubOwsPzGYLLLu4fKQHCSKLxe.KEmBxQqf7Nsau6cu3a7M9F3fG7fnmd5ACMzP3vG9vHJJRrbmqUqlXB+nUXCsfims.FsYgTxh8dil56KEwzzTz+azDcpqqiLYxHZ3+srksfeqeqeKbC2vMfa8VuU.LyZJhJmHE0DxNIJOonLLLslvNXwvzBC4Xk7j2I+gp555HNNFEJT.ae6aG0qWGOwS7DX3gGFSLwDutcbngggPjFkcUxSPXyLaYyE26UycjEfR6rQZvBhhhvEcQWD9LelOCt1q8ZEotOsqBSSSE6xvleLOWYSFCCSqAbT.yvzBCkwTxkwSVbipppvkDCCCbi23MhssssIb1BXlOXuVsZnRkJHLLDFFFh9Ap4GOJynHQcylPJ10p4NxkzE3LBhokz8Mey2L1912NV1xVF.lIJFnoLTV.EUt1lKSKCCSqKrCVLLsvPeHZyBgnK655h74yKJ+T974wfCNHV9xWNN8oOM788wjSNIpWuNBBBfooIxkKmXxAaVbEU1ulalZ4uKebwhsN2jllJJumhhhXsBYXXfssssgOxG4iHR+933XjMaVDFFh33XwhoVFVTECyhGXAVLLsvHGMByV+1jOedTudcwBfNMMEWzEcQ3xu7KGG6XGCppp3Dm3DX3gGVDACzWdddMT5Q59Cbl98RNDSkcPgEVM2Y1JoZwhEw67c9Nwl27lEqMnIlXBTpTInoogpUqBMMMjMa1YUTE8Xx8fECSqKr.KFlVXNeKzWOOOjISFgfGxsj0u90iolZJrvGLVQ...H.jDQAQ0Zu1qgImbxF14ettth3XfJC3YqA2o.Lk4MG4ymGSO8zBAxTvptwMtQbS2zMghEKBfYDL0YmcJZb8BEJ.fytiUjaXLLLstvBrXXVjC41jppJz00Qtb4vfCNHbbbP4xkQtb4DkgJHHPjCV.mYZzHNa6DQl2bPBTMLLDkFbkqbk3S7I9DXKaYKKvGcLLLymvBrXXVDigggneoncdmhhBJUpDxjICdtm64PgBEfiiChhhDBrnoHT1EDVT0EdnX1fVOPgggXqacq31tsaCEKVjK0JCSaL7TDxvrHF4bpRdM4Po29kdoWJ5t6tgttdCMvNvY5iG47rhmNsKrjjjf74yCOOOXZZBaaaby27MiN6rSTud8FRm8Y6KFFlEuvBrXXVjCkmU.mIlEnd94RuzKEWxkbIB2RTUUgiiiHDK4.Cc9E42ahiiw1111vN24NOqCs.CCS6Cr.KFlEwPhojm.PYQVc0UWX8qe8XUqZUhlZmxjI51Rv6XvK7nqqKbpRSSC29se6XfAF..mYwOyvvzdBKvhgYQNZZZhPCkV4MwwwHLLD555XiabiXSaZSnyN6TDfkTyWKu5aZtbgLu0gN2poogAGbPr8sucnqqCeeeNM7YXZygEXwvrHFJ.R0zzDouNcYfYDecwW7Ei0st0gt6ta333H9YTJwe1f6An25DDD.cccDEEgst0shK5htHQZtyvvzdCKvhgYQLx6ovl6+JCCCDFFh74yia3FtAbS2zMgJUp.aa6FJs3rUVPdeCdgApu2V0pVEd+u+2OJVrHlbxIQlLYfqq6B8gGCCy7Hr.KFl1XHgWc0UWXvAGDqbkqD555v11lCQz2FfJI6V25VwfCNHrssE8dEKfkgo8FVfECSaLzGhmMaVrl0rFzc2ci50qCMMM9C3ea.EEE333fctycJZtcBtW2XXZugEXwvzlSXXHTTTPGczAxlMKld5oEMdMy7KoooXMqYM35ttqCooovyyCoooHHH.111KzGdLLLyivBrXXZiwvvPzSV4ymGqXEq.FFFv22+7tmCYdqittN1912NFbvAgqqqHGxhhhfkk0B8gGCCy7H7ugkgoMF4TAOa1r3pu5qFqYMqAdddHLLbg9vqsmRkJga3FtAjKWNDEEACCCnqqijjDtDsLLs4vBrXXZyg50GKKKb8W+0ist0sxtWcAhy2ptYsqcs3xtrKCIIIvvv.oooHLLT3hHCCS6K7ukkgoMF4cZmppJFbvAwl27lQ974Q1rYWfO5V7y4Sf05W+5wJVwJPPP.rrrDKbaKKKNmwXXZygEXwvzlwYaYAGGGCEEEryctSrl0rFTqVsFBkTCCCXYYAUUUnqquPbnunCxcPUUUQI+nLDq2d6E23MdiHJJB111XxImDZZZHa1rnd85bOXwvzlCKvhgoMljjjFDZonnfksrkgq9puZzSO8zP.klllJxFqYSfFyYG57LEfq..W5kdoXKaYKnPgB.XlnxPSSiCwUFlkHvBrXXZiIMMUrO7n8UXO8zCt4a9lwZVyZfhhhXU6.bFWtXAVyMHGrjWWQ.yHP8ZtlqAW7EewHNNFAAAMbN97slhXXXV7CKvhgoMFJPQSRRfpppXxAuhq3Jv5W+5E6EOYAUz24fv7MFxKN6LYxfq5ptJXaaCWWWQCsS6fPt7fLLs+vBrXXZyIJJRHVJMMEwwwn+96GWwUbEhxWQNbAbFQYr.q4Fz9FjDWkllhUtxUh0t10BfYDSkISFwTDR2VdJBYXZugEXwvzlC4dEvLAeYTTDbbbvUbEWAVwJVg31PPkRjKg0bCJU7iiiQbbLLLLvUdkWI5u+9Eonubp4yNDxvrz.VfECSaLxMecXXXCeP+EewWLV8pWMLMMecNVQNsvbtgNGopphnnHjjj.GGGb8W+0id6sWgnqvvPDGGKFlf33XwRelggo8D92fxvzFSbbrPTkqqqnWqhiiQ1rYwxV1xdc8CjbzCvbtQVfEvLm6rssw5W+5gooIrssgooYCmSIAW74WFl1a3vtggoMFCCCwkKTnPCSLXmc1IV9xWN.fHgwkW.w7pz47CUZUeeeXaaCOOOXaaiN5nCQoYUTTZvsJCCiFdegggo8D9OghgYIBTirKOsfaYKaA82e+hfEMHHPz70xkSjY1gDQQk8C.XCaXCn+96mcnhgYIN7uAfgYIHjPqMu4MiUrhUH5SK.t4qeiBEdnQQQPSSCacqaEKaYKiCSTFlk3vBrXXVBfrnI4oCLe97nPgBHLLDlllhcjGEUCLmajOWR8e0F1vFfggABBBV.OxXXXVngEXwvrDl33XTrXQwkodFhxzIlyMT7L.LSDXzc2ciK5htHNlKXXX3lbmgYo.xBljENoqqiK9huXnooIZpcpuhjWfwLmcRRRfttNTUUwJW4JwJW4JQTTDGCCLLKwgcvhgYIHThiaaaiAGbPzUWcItd56rCLmeH2qLMMQTTD5u+9wxW9x4yeLLLr.KFlkJHuJW.lQDkttN5u+9Qmc1Iz00ggggnos4RDd9gNGoqqijjDTnPAXZZJx5JFFlktvBrXXVBgppJzzzfllFz00gllFJUpDV8pWMhhhDSBG.3rZZN.UFvpUqhrYyJ92FFFHJJZg7PiggYAFVfECyRb5omdvEcQWDrrrDqVG4l2l4ribY.ihhPtb4DmC4dvhgYoMr.KFlkvjjjft6tarl0rFjISFgnJZktvbtQdf.LLLvpV0pD+LNnQYXVZC+a.XXVBCs.nKUpDLMMghhBRRR3oGbNB4VEvLYJ15V25DI6NWhPFlk1vBrXXVBCUJPSSSQeYwMn8bGZvAhhhDKOaB1APFlk1vBrXXVBittNRSSEMztggAGu.uAPSSSb9piN5.YylUDxn7tbjgYoMbPixvv.CCCDFFhjjDdM47FfnnHQIAW0pVExmOO.39uhgggcvhgYIMQQQHMMEZZZv22WDSC555rSVyAhiigllFxkKGFXfAPgBEZvUKFFlktvBrXXZi47EXnZZZnVsZHe97niN5.QQQMrxbXN2XaaCOOO333fRkJAMMM344g50qy8wFCyRbXAVLLKQgVmKVVV33G+3v22ug3YfKy04mff.XXXfolZJr+8ueTsZUjllhb4xwSQHCyRb3eCJCyRPHWsBCCQbbLd1m8YQsZ0DM8NulblaPAJpmmGd0W8UQ4xkENWoqys3JCyRYXAVLLKwfDPkllh33XL4jSh8t28hZ0pIlhvzzTtDgyAjS79olZJbpScJnoogpUqBKKqE3iNFFlERXAVLLKgn4k8rssMN0oNEFZngD+LtAsm6jjjHFLfJUpfW9keYjMaVgyfLLLKcgEXwvzlCIXRtrejXpjjD7hu3KhJUp.fYJYH8y3Rbc9gh0BaaaTsZUru8sODGG2vZGhggYoIr.KFl1XlM2njcw5Ye1mE6ZW6BtttvxxRDRlb4AmannnHBUzvvP7DOwSfuy246fpUqxBTYXVhCKvhgYIDM6h0S9jOId7G+wQTTjXWDRSOH6.y4mzzTQ9gkllhm+4ed7O+O+OiibjivI4NCyRbXAVLLswHGU.T+UQevummGdhm3IfhhBz00QPP.RSSgkkELLL3IIbNPRRBRSSQPP.xkKGrrrvu427aPkJUP850WnO7XXXV.gEXwvzFy4JKqTUUghhBld5oQTTDxjICRRRP850avIKlyNNNNhRpVudcgaVSN4jrCVLLKwg+MnLLswH2f6TSsK6j0ke4WNJUpzq61xhClaDGGKDh566irYyhctych95qONlFXXVhCKvhgoMlYqI2oFXWWWG+d+d+d389deunPgBhraxxxBIIIbitOGHHH.ZZZBAoaaaaC+E+E+E3xtrKiO+wvrDGVfECyRDZNtFHGrty67NwfCNHBBBfttNLLLfuuO6h0bDxcPaaarsssMricrCjKWNQzWvvvrzDVfECSaNjfJpmqHnKeUW0UgMtwMBUUUjjjHV0KFFFu8evtHCcccQnhlOedboW5kJVcNNNNKzGdLLLKfvBrXXZyQdZ.UUUaHGr788QwhEwxV1xP974QPPfnuh3XZ37CUFPEEEXXXfd6sWQjMXZZt.ezwvvrPBKvhgoMFRH0Ya82XYYIVXw111hfFMSlLBmrXN6jjj.SSSXXXfvvPXaaCMMMnnnvwz.CyRb3nFlgoMFJowSRRfuuO.fHPQCCCE8a03iONJWtrPHFuOBmanpphff..LyDENxHifff.jjjHJ4JQRRBhiiQRRhnW2j+4yV4aYXXV7BKvhgoMlvvPnppBUU0F5IHZJAKWtLBBBPwhEEkNLMMEgggPWWugfJk40SZZpvsOOOO355BCCCgvVEEEgnJMMMw5yINNFdddyZTNvhqXXZOfEXwvzFC0n5T+Tkllh33XDGGizzTzQGc.fYDbEEEAcccXaaKb6h4bSZZJTUUgooIxmOuPDakJUPRRBJTn.hhhPTTj31IGqCrXJFl1WXAVLLswPBp.PCwtfggATUUQXXH788wK+xurnA3oRYwI494GaaaQJtK22ZlllvwwAIIIhrEKMMUz.7MOQmLLLsevBrXXZigxyJcccQ4pndDRSSCUpTAiN5n34dtmClllnd85v00EooohxYwb1QdBMCBBvniNJ788QRRBpToBhhhfkkk3bIkf9JJJ7tdjgoMG9OQkgoMFZwMqnnfnnHgiJNNNhXEnZ0pX3gGFQQQPQQANNNb+WMGw22Wzeaggg3PG5Pv00Ur3m6ryNQlLY.vLKWa4Iyj5MK5K43yfggYwO7ehJCSaLzdGj9PbJalBCCw3iONN5QOJ9u+u+uE8fkggArrrPXXHWBq4.zBxNMMEttt3IexmD+3e7OFaYKaAEKVD555niN5.YylE555HNNVHzMHHPzyVjiV7Tbxvz9fRJ+mLwvz1RPP.LMMQRRBpUqFbccwniNJdlm4Yvy7LOC9Y+reFNxQNBhhhfmmGTUUgllFBCCQ974408x4Aaaa344gN6rSjllhxkKiku7kKZ5895qObi23Mh22668g0u90Caa6FlVS4bJi5KK5KFFlE2vBrXXVDCk2RzD.RMzN0f5IIIX3gGFu3K9h3YdlmAO+y+73Ue0WECO7vX5omV7A7M+A9D7ud3by4SHjkkE777v5W+5wu+u+uOtlq4Zv1291QgBEfqqqnQ3SRRZn+r.PCNZwvvr3CVfECyhbnI+SSSSTpOSSSQOA8M9FeCb+2+8igGdXgHLpWrn3ZX1bUg47ybQ.jssMBCCQTTD5qu9vccW2Ety67NwF1vFDkWjEXwvz9A2j6LLsgDEEgibjif68duW789deOb7iebjjj.GGGQ+9La6ZPVb0EVHQRlllPWWGiLxH3gdnGBequ02BCO7vBAsbYAYXZ+faxcFlE4P8uCkcUZZZnb4x3we7GGemuy2Apppn6t6F.yLIa..555vzzTrlW.XwUuY37cNqXwhnZ0p..nmd5Addd327a9MHHH.W20cc3Vu0aE.XVEXwBtXXVbC6fECyhXncYmhhBBBBDkYpb4x3+7+7+TjESz9FrZ0phxI566ykEbdFRPabbLN0oNEpUqFRSSwIO4IwK+xurnDg.rfJFl1MXGrXXVDibIljEI466iW3EdAXXX.WWW..QYpnHBHNNFZZZrHq4Q788gtttHI2oUkiuuOJWtrPrqrCVbuWwvzd.KvhgYQLZZZhIHjRKbJOqnk7r7tGLHHPHjxxxRThvYSbEm13u0Ia1rnVsZhx2544IBvURzECCS6IbIBYXVjC0r5zhclBvxt5pKDGGCSSSXaaCfyrbhatDgMC2z0WXfRtcUUUQ4bMMMgkkk3eyNVwvzdBKvhgYQHzn8GFFBKKKToRE344gZ0pIVMKW1kcYHLLDFFFvyyClllnPgBPUUEVVVyoGel2ZPhW000EStYXXHRRRvF23FgggAhhhP850EKB5nnHQIbkeb3x3xvr3BVfECyhXnxMkOed333HJYXoRkvN24NEStlhhB777DgKZXXHxkK2B7Qe6OgggHSlLh2mJUpDxjIC15V2J5u+9gttNxjISCkKzvv.lllhvhkEUwvr3DVfECyhXbbbfmmGFarwP0pUQ0pUQ850QlLYv1111vfCNHTTTfkkErssaXWCJu3gYl+nd85vzzDlllX7wGGczQG3y9Y+r3ptpqBm9zmFAAAPWWGFFFHLLD999B2HaVbEWJQFlEOvM4NCyhXRSSgggAxmOOrrrPtb4DenboRkv0ccWGN7gOLN9wONzzzfllF.PCqUGl4OJUpDpVsJLLLDCMvN1wNvMey2LbbbDS1IvLSbH0ybz0EGGy8CGCyhTXGrXXVDyTSMkHovCCCEKzY.fd6sW749beN7G7G7GfhEKBEEEQ+9jISFtGqdafIlXB333fomdZTudcb629siuvW3KfhEKBfYlBzff.Tudc..QYdcccw3iON26ULLKhgcvhgYQLjiTAAAv22GYxjA555HJJRrZb5u+9QwhEQbbLBBBDARJKvZ9mb4xAaaanpphb4xgUu5Ui0t10BeeeQoAylMKLMMQbbLpUqlPvbmc1ovkwYyAKd5CYXZsgW1yLLKBo4cXWbbLhhhfkkEN1wNF1yd1CFYjQvd26dwK9huH90+5esXIPmjj.cccnnnHbNgY9AGGG355hBEJfnnHzUWcgctycBKKKTqVMze+8ieqeqeKrsssMjKWNnnnfrYyB.fZ0pIJsHkoYxBpXAVLLs1vBrXXVDhboipUqFNzgNDNvAN.N5QOJ9+9+9+vS8TOkngocccQtb4DNWQSTXtb4D6IOl4Gnja211FSN4jn2d6ULHBpppvvv.WxkbIBwUW8Ue03O5O5OBW60dsBgyj3JxsRBVfECSqMr.KFlVXlXhIPoRkPkJUDqbEUUUTsZUjKWN7Juxqfuw23afu6286hwFaLnoogpUqhvvPXaaKJwDIFSd22wL+irCTxqBG58AKKK355JbUzxxBCN3f3i9Q+n3C8g9Pnmd5AUpTAEJTPr1cn2aqToBxmO+B7qPFFlyFr.KFlVXpUqFBBBPlLYfppJBBBfkkEdoW5kv26688vi7HOBN7gOLFe7wEwwPPP.RRRDkCj9u3bCSuvv4RfEgppJLMMEq8nK4RtDL3fCh69tuaryctS366KJqX1rYgqqqHZGXXXZMgaxcFlVXnPpb5omF8zSOHHH.+hewu.228ce3QezGESM0TBmO.lIXKoRGQICtLr3p29gRvcYAVDVVVHJJRT5VxgpW4UdEbnCcHTsZUbxSdRba21sAfYbDqd85HIIAIIIr.KFlVXXAVLLsvL5nihd6sW355homdZ7u+u+uiG5gdH7K9E+BzQGcHDVEEEIRKbZQOSqRGlVWHgRzJxQWWGNNN.XlLv5m9S+oXzQGECN3fXvAGDlllvvv300OVLLLsdv4fECSKLzJTIHH.eyu42D2y8bOX26d2n2d6sgT+lbAwzzD.fSp8VLjaFc4KGFFBMMMnqqKVMNIIIHJJRrhidkW4UvW9K+kwwO9wESVnmmm31yvvzZB++PYXZgoPgBPQQAG6XGCOvC7.hoOKWtbnVsZhT+1xxBYylEppphkILOgYsNH2+aMWlVMMMgyTpppheNMkgZZZ3AdfG.6ZW6BEKVD999HMMkm.TFlVbXAVLLsvPKm4CdvChQFYDXaaiff.bzidTzc2cCeeeDEEgff.TqVM344AfY9P6LYxr.ezyLWv22G0qWWD9nTezQq1Hpo3+o+zepXRQylMqXc5vvvzZBKvhgoElhEKhCcnCgcsqcgwGebbhSbBbwW7EiBEJH1wclllM37A0eNTpfK+EyauHGPnxeQWO8dGvLuuYYYIRh+ff.gSUNNN3fG7f3q809ZPWWGSO8zv11dA9UGCCy4BVfECSKLgggXe6ae36+8+9hUayQNxQD8dUXXHBBBZXwMGGG+5x+JNdFVXPtI1k+htdpbt.y79F89J89G0Gc9993HG4HXW6ZW3Ue0WEYxjgWV2LLs3vBrXXZgQWWG6e+6GSM0Tv00ENNNhjXmmjr1engWv11Fggg3jm7jXjQFAQQQbStyvzhC++PYXZgIIIAiLxHhXWPSSSrnl4OfcwOyEWESSSgggARRRvjSNIbccgppJ6fECSKN7uglgoElff.TpTIjKWN..TsZUwJVgigg1eHWJiiiQZZJTUUgiiCLMMQPPvB7QGCCy4BVfECSKNKe4KGttthLthbzfo8jlaFd.zPO0wCq.CyhCXAVLLsvXYYghEKhff.wjmooowkGpMjYaROoRHRWOkyYwwwBA2LLLslvBrXXZgQUUEKe4KGaZSaB.yzz6555HHHfcxnMkliUCpm6rrrP+82O5ryNWfOBYXXlKvBrXXZwYfAF.ae6aG.PL8XT+3vzdC8dcTTDxkKGtjK4Rv.CL.zzz3dvigoEG92PyvzBSPP.V25VGd2u62MFXfAPRRhXhxrrrDK6YBcccwJWA.MDjk.304LhbPXRnppJbJ6r4R1bM3ROW2ll+YzwirCN555hDMe1NVeqxY60wb802rIxU9XjZRc49oRQQAVVVvvv.VVVv11VHjhRmc584ff.XYYgnnHrl0rF7I9DeBQZ9yAMJCSqM7tVfgoEF5CnW25VGtrK6xvQNxQfhhBxkKWCSTngggXAASnnn75lzL5C5IAKtttMH3RNDLoq6rI.Q96DMG6.mqXHX1bgit8z2ihhl0ma548r83e994Me6lqWeyHuyGomK55HgVZZZv11FZZZvyyqgPFEXl2iogVfRwceeeDFFht6taL5nih96ue7ddOuGb4W9kKVAR79ljgo0FVfECSKLwwwHHH.c0UW3ptpqB+u+u+uX7wGG4xkS7gwIIIhzb2vvP7g0AAAMjh3.mIYwIgKxMOMcYJR.j4rIjRdE8H2P1x29Y6mSe+MSy5Ker0rPO4mWp2klKPhKmsGiy2wB85kDm17iYbbrPHK85U1gQcccgvKeeegScFFFXzQGEVVV31u8aGerO1GCWzEcQHLLD555HNNlKSLCSKLr.KFlVXLMMQsZ0PoRkvsbK2Bd4W9kwi7HOBpUqlXJxLMMENcQWtVsZHJJR3TkrfHZABGEEI9.+333WmSLxhNHgDMK7Z1DHMa2+Y6mOa2F43I3rIRS91SBZlMQWMe8yUdibenfeUVnprnKMMsFbCjJ+poooXMGQo0dlLYfooIpWutXOD1e+8icricfO9G+ii0rl0HtOjikbbcvvz5BKvhgoEFxUJcccbEWwUfO0m5SAccc7XO1igSbhSfzzTjKWNzQGc.cccg.DKKKjKWNL93iKbxQ18DRbkssMhhhZnbcjXK5w6bIzgtOmMGujEDMaNX0biZKuq9lKHutflMmmlKkHrY2uZVT44hyWXeRBHIgUzqKOOODEEAGGGgSiToAiiiQ1rYwF1vFve5e5eJttq65vF23FEhqxlM6474jggo0.VfECSKL999v11FkKWF11135ttqCIIIHWtbXO6YO3fG7fv22GG8nGUHLxvvP3bEITJNNtAGqHmWnECM4thr3lYycnKzHmkSxkwjDZQGmDMeYee+4sis4BzwGctd1Vr1xmaoo.kDuRK6YRLWlLYPWc0E14N2Itsa61vN1wNPoRk.vLo3O0X6gggbNXwvzhiR574u8jgg4sDwwwPSSCSM0Tvvv.YxjA999XngFBuzK8RXe6ae3fG7f3PG5Pnd85MrZUHARlllv22Gm9zmFSN4jMTNJOOOw+Ne97..nVsZvyyqA2jjc.C3L8rUyS8Gc6omeZp3NaNbEFF1vzLR2VYQGM6ZlrvOZJJa1kL56zy+YCpQwatw4a1gtyF0qWG111vzzDooov22WTZVZBNylMK5qu9Ptb4DmSxlMKTUUQ4xkQwhEQoRkPe80GV9xWN5u+9wl1zlvke4WNbccaXZAUUUEOGrSVLLs1vBrXXZgg9.bZr7oxHkMaV366CMMMTtbY366CGGGQCSSkVLLLDoooX3gGF6YO6A6cu6Em7jmD..FFFXpolBlllnToRn6t6FZZZX5omFUpTQzr6T4qHAVxBhlMGbjcKiDJAL6kHrToRhonihjA51lll1vT2EEEIdboiMpWkjuOxNHc9b4Q1oulEXMWVn1ZZZHe97Ha1rHJJBUqVUDsBjaTqcsqEui2w6.qcsqUzSVTevQOmjf1hEKBMMMDDDfvvPjISFTudcwNHDnwoGjmhPFlVW3RDxvzBC4dgooo3C7cbbD4jD.DkPhfVLz.PLwYc2c2nmd5AczQGX+6e+hHZXjQFAVVVn2d6EqXEq.YylEdddv00UjKSToDolp111FIIIB2uNaNXQhsHwQjXKRblppp30DM8iTozHQTppphm6lE4Abldfhx+K55nojTNOuhhhDBNkyUKpjcmslimJmWbbLbbbPlLYPPP.JWtLRRRPWc0ELLLv3iONFZngvIO4IgllFV9xWtXfC5t6tEtVEDDHBJT5XVVHH4ZIIdsYmp3IGjgYwAr.KFlVXdq5PgoooXZ1xmOOxmOObbbDM1dlLYPlLYPGczAJUpDxkKG788gqqKRRRfsssvoHRP.4jB45RyN+Phpj6kKRbiboKAfnGj788Eq+GYGyZVLgryYjXSRvjgggPHE4xSTTDz00Eh4nW2z8m9YM6hE88jjDQ4+nlRmNGkllhwGebwq8Z0pgSdxShibjifBEJf74yiLYxfhEKBOOOTsZUgHRR.EW.AFl1WXAVLLsv7VUfE4vC4rjllFhhhvjSNIFYjQPPP.JTn.xkKGpTohnOhpWutXB+H2pHAVTPWRNwH+3StWQNXQk3S1EJ51QNjQBtHQOjfKJSnZNbTkEDQB5jSJc4F4mZ3exgJ4d6hd7jOW27iO0yTgggvyyCNNNniN5PbNbpolB111vvvPbNc3gGF999nu95CqcsqEabiaDCLv.Bgszqe4dTiggo8C9+cyvzFioooPrSgBEvpV0pvDSLANxQNBFarwDATpr6Sgggv00E999HWtbhR3A.QuRQhO788uPKZWK...B.IQTPTYPvfr6UMKjQNFInetsssXxGoDoOIIA0qWW3PlrHK.zviOMIdjnpl6OIYWyjWCMDxG+xB4ZV7UsZ0DSwWXXHzzzfqqKxjIi30kppJxjIC5ryNQoRkPmc1YCS9GA4bE6dECS6Mr.KFl1bHgNlllX0qd0HMMElll3zm9z..nqt5B81aunmd5A111hlptd85vzzTHthJYG0uPVVVhxmI2P6xBGbcca33PVLVZZpnbixM5NksWj6axtWImoWz5lgDQI26VjvNKKKgSYxuNnqKLLT3rF8bQMaubYBoRCRS.Hs9arrrPRRBFarwvXiMF788E8SFcdtToRhRLRBwnmeFFl1W3+GNCSaLxhQbbbfooI5ryNgiiC777Dwy.0yPzhGlJOXWc0ExjICLLLDONxY5zrIrRtTaxMHN4NFIHJNNFSO8zMDvlz8WNYzadREkSm9d5omF54J54B.hI1iRJc4lfmD3PNfQM+trXN.HdrMMMQGczQCtu433.EEELwDSfW4UdEbfCb.L5niJ5qrb4xge2e2eWr4MuYgPRRbWXX3qaQcyvvzdAKvhgoMFUUUgKK.yH5Ha1rhIQTdB.kcDJHH.dddhIkyxxBAAAhl6F.MD2.jKYjnJ4I2SNhEjEXkjjf74y2f.LY2mlsdthddo6+jSNYCITeyNEoqqKNlIAUToGIGjBBBDoo9rkGWTufQq2lJUp.EEEjOedjjjfScpSgie7iiQFYDL8zSKlPPRDkoooXWDRMUO.GwBLLs6vBrXXZiQNnJIgQ111HSlLv11FiLxHHSlLXhIlP7g+UpTAiM1XX5omF4ymWzGQzjvIOceM2j3zd1iJ2mbIDat+rHLMMgkkUCII+r0H6jSWzWQQQhocjNVjW70.yHFy00ULMgwwwhFum1mexBrHQhzwollFpTohvEKWWWQis2We8AeeeL0TSgSbhSfolZJQoFoWeVVVhAAfDdB.wsiggo8EVfECSaLTOHQBgnvqru95CEJT.CMzPX+6e+X5omFqZUqBEJT.999hUyimmG.NSyfKmQVTlNQtWQQ3fkkkPrlhhBbccEhxnGCfYDV433f74yib4xg33XToRE3551PudQkVjbASNxGjEpQhqbccgqqq313440P5zS2V5XQNVHZV7WbbrXZIoDwuVsZHa1rnVsZHNNFG9vGVziWjiciLxHHWtbhdIywwA0pUSTtSxUQNSqXXZegEXwvzFyrsziUTTfssM5ryNEoF9TSMEFe7wE2N4U9hr.jlmtOJerhiigttNbbbDSFHI3gVrwTngR2eSSSjMaVgaWQQQvyySreAUUUENl07WzwC4DjbZuSkmiJkHUZSxUK4vPktcM6rFU1TSSSDDDHD7IGYET4L877Dhun6quuO5niNDKgaB40+CKthgo8FVfECSaLx8sjrHqrYyhksrkgnnHL0TSIlXO49hhbZhbvgJIG4ZE0L70qWW3lC4PC0GWz2kcvRN80kEBIWBQ4XdPNY3adRDoiY51KGACDM+ZWFprjMK.kbeiNGPGCz0GFFhIlXhFVvyDlllnd85Xcqacn6t6V7bHGyDbDMvvz9CKvhgoMFYGS.NSOSYZZh95qOwpboVsZh6C4Ljmmmv8F.HBaSRfDI.od85nZ0phcfnbeMQMcN8bSqcGpeslszcW93U9xuQQdZDom+lyRqlucMu5ejatd4FmmdcJmj8zDHlllBCCCbEWwUHVf1j3SUUUt+qXXVh.KvhgoMFpzc.mwYFfYllvRkJgBEJfnnHwxcl5wH.HZpc5wILLTT5PRzC4bUy4QEw4RbjrPCx4qlW5xxk0q4kJcyO1y1BPVV3F4vE8bPk+TFYgcz+lZRcxsM4R9Qk1jh0hzzT355hd6sWrgMrAgXLpg4a9Xkggo8EVfECSaLM6LDUlNRfUWc0Ehhhv3iOtvMJOOOQuYQwzPyKbYpLWjaT.u9975rkX4xk5iftsyVlZctDoQBuZVXF8EUdN4qW91KK5Q9wT97GIxifDFRM1OkyVxtYsoMsIQntJG8DxmaXXXZugEXwvzFyr4TBkATczQGXvAGDEJT..PLcf.PjkSTDEz75ogPNynjetnRCJ2H2ylXqlaz6leLZ1MLRrxrI.S912rXuluOjXSx4oyExkRr4W6zOyxxBdddPUUE11135u9qGKe4KWb+HAUxQAQymyXXXZufEXwvzFSyt5Pnpphb4xgsrksfUrhUfW8UeU.Li6L0qWugHLX1JE2rIpA3Lk5iJU3r0z4MKToYW1ZtmwZ1QqY6w5r87H69zYygqy1qK55jyYKpGpn6OM4fx6YwLYxf0st0IRu8l68KYmrXXXZegEXwvzFC0uPMGU.TLIbQWzEgt5pKwG5644ACCCTqVMwhhtYNW8X0rc6OW2+YqGnNe+bYlMgUmsa646ee9dLnIcT94NSlLnd85hgAHHH.CLv.3xtrKCtttvwwogxAx6ePFlkNv+ucFlkvP6XO.HJWF88yk3ElYPdEDALiCfqXEqPruGYXXV5BmzcLLKgISlLXsqcsnPgBhbdhiQf4NggghctHUxQ57Im0ULLKsgEXwvrDFaaabkW4UhK8RuT.bl9Phmxs4FxIZebbLxmOO17l2LbbbDgTJCCyRSXAVLLKgQUUEabiaDaYKaQjYST7CLW5mpk5P6fPfYJS3pW8pwV25VQlLY3lXmgYINr.KFlkvjjjft6tar90u9F5YnlCLTlYG4orTUUEqe8qGqacqC.bCsyvrTGVfECyRXnjQuu95C4ymWjYST3YxbtQdc4n9+m8NSiMtNuN++bm8cNjyv88MsZqEaYoX4XGaGijlDCzDTjz5j17gDTf5z0DzOkZTfhBj9k9gzED2l1h.TzTfr.TfzDWfD3V2DaGYIuoZsPIJw80gb12ty9+Ov+mWdtWNCohjnHklyO.AKOZ3v6bm49dedOKOGKVvvCOLZqs1PoRkjg4rfPSNxJ.BBMwPE0tWudgWudgSmNMLO8D1YrYyFb4xErYyFBGNLrYyFJTnfHPUPnIGQfkfPSFlGsLEKVDG4HGAG7fGDEKVDZZZvoSmpg5rPigbCdccczSO8fm8YeVjKWNoIADDDDAVBBMyPNOdmc1IFe7wgKWtPwhEQ0pUgCGN1qO712C282OxQNBBEJD73wiZTCIHHz7hHvRPnIFZdA5ymObjibDzRKsfpUqhxkKKFM5sHVsZEtc6FO6y9rns1ZS83RJBEDZtQDXIHzDCYRlUpTAiN5nn2d6ENc5T83BaOTAt6ymObpScJXylMUmEJcQnfPyMh.KAglXrZ0JrXwBrZ0JFd3gwvCOLrYylgATrPiQSSCEJT.1rYCs0VanZ0pJuDSh.nfPyMxJnBBMwPhA..5niNv.CL.JVrHJWtrTn12BP0fEMOG0zzfMa1fMa1jlDPPnIGQfkfPSL7TA51saL1XiAWtbAKVrHFM5s.UqVEtc6Fm7jmDd85E1saWMeBkH.JHzbirBffPSLVsZEUqVE4ymGZZZXngFBs2d6vqWuh.qaApVsJBEJDN0oNEBEJD..xlMKpVsJb5z4d7QmffvdIh.KAglb3BAN8oOM9ze5OsjdqeE3ge3GFe7O9GGEJT.kKWFACFTN+IHHHBrDDZloPgBF53M+98iwGebDLXPoK3pCTp+nFCvtc6p4OnWudUF0p3gXBBBxJnBBMwP1L.uf1GZngTi6EgMgb+dZ9MB.TpTIzRKsnR0ZkJUPkJU1iOREDD1OfDAKAglXnHsTsZUTpTITrXQI5U6.0pUS8GRvUhDIPsZ0fa2tQsZ0DODSPPPDXIHzrSkJUPsZ0TdhkOe9PnPgfKWt1qOz12QsZ0LDopvgCigGdX0Pxl7PLwE2EDDDAVBBMwPQagpqHa1rAmNcht5pKYV5gsNXrMSKszBN3AOHb61MpToBxmOOpVsJra2983iTAAg8aHBrDDZhg6j6TJu750KNzgNj3iSXyzARvqCKKVrnFuP0pUCEJTPEcKwE2EDDjUPEDZxgDRUnPAXwhEDJTH7vO7CivgCuGejs+BRXkUqVU+4zm9zn81aG555voSmvqWuvhEKRz+DDDDAVBBMyPClXfMJ3cZvO+vO7Cid5omsX4.j0DzLAU350pUSIvpXwhHb3v3Idhm.EKVDtc6FkKWVctzlMahQsJHzjizpPBBM4TpTIkX.61sCGNbfVasUzc2cC.XHcWTQdCr4b36Ac3ueqTohgNrLTnPviGOp+ctMNTsZUYdNJHzDiDAKAglXHw.TcCQhlnQ8B8uA.UgdSOulgNkypUqJKWvhEKpgiMkV0fACp96lstAAAglajUADDZxgWSQ.aTKVUpTAszRKvtc6pnTQEBOIhnY.RfI0L.D0pUCNb3.1rYSUX6.aH9jGwKAAglWDAVBBMwPBCnthi96czQG3Tm5TpzeA.Co6pYQ7.WbI8dl7MrPgBoDXooooDiJN4tff.fHvRPnoFRXE4j6kKWFUqVEs1Zq3Dm3DvmOeJgE7H3P0XzC5veORBonzDN5niBOd7nNGRoakDk0Lb9QPPnwHBrDDZhgOGBonuTrXQ.rQ8E42ue0+NOpUMKQvhnZ0pJCYsVsZvtc63nG8npH7wqSMdjtDDDZdQ5hPAglXnnxP1OfEKVTE0M4p6MyErMuv9oZOip+p96ueX2tcToRETtbY3xkKkUN.flhNrTPPnwz7txofffJsVbQTd85EkKWF8zSO3gdnGBEKVDZZZnPgBJQCMSQvh68WzLHbngFBG3.G.ZZZvlMavsa2pnAROWYVNJHzbiDAKAAgs.IfxiGOJCHkSyR5u3Fwpc61UCy4CcnCgQGcz83iNAAg8yHQvRPPnt9ZkEKVfOe9Z5btcNTz8JWtrxc1qVsJFZngPas01d8gmffv9XDAVBBMwzn5DhDVDHP.X2tcUjbH6JfRs3C5X19JJUpDxmOuACFUPPPndHqPHHHnfWiUzfe1oSmp+cJRWMKEvM4v8.vPsp42ueCiLGAAAAyHBrDDD1BjXhvgCCOd7nhVEIthLaylAnH2Q1z.vlE6tfffPiPDXIHHnfKZRSSC974CNb3nor6AA1zbUsYyFz00Uu+ymO+VJ7eAAAANh.KAAg5BYAADjGOw8LqGzgJpcRXEYICVrXwPpSEDDDLyC9qPJHHzPL6N6lGGN8zSOXrwFC.a3GTEKVTktLGNbbO+38dMjK1qqqCqVshLYx.MMMDJTHIBVBBBaKh.KAAgFxfCNH5u+9gSmNUt5NUz2kJUZO9na2GZr3.rgfSOd7fd6sWbfCb.oH2EDD1VDAVBBBMj.ABffACphZE23MaFfWL+TQtGJTHL5niJE4tffv1hHvRPPngToREX2tcTtbYTnPglNAV.PMCBA.JTn.rZ0JZokVTCEaAAAg5gHvRPPngvMaTBRfUyPDbnZvhRGX4xkgSmNMLyAEDDDpGh.KAAgFRkJUfa2tMTGR7H57fNbO+hbu9N5nCTqVMoFrDDD1VDAVBBBMjJUp.WtbohjCg4++GTgJn+xkKiZ0pAGNbfwGe783iJAAg6GPDXIHHzPb5zIBDH.73wCra2tJxUjviGzgl8hzeb4xEFZngfMa1ZJRQpffvsOh.KAAgFRoRkP2c2sZb4TsZU3xkqs3YVOnBUj+jgi51sab3CeXnoo0zDEOAAgaOjhHPPPngX2tc3vgCXylMCQupYIBVTjqn5uxtc6vkKWR8WIHHri7f+VPEDDtivpUqvpUqnRkJPSSSUz2MKE5NU+UUqVEVsZUMhbZVDYJHHb6gHvRPPngPcOmMa1P4xkUBr.PSQJBA1zNJnNGzsa2.PDXIHHr8zbrBoffvsE0pUCd73A986G.FmcgMCFNJkJP61sCKVr.61sCOd7nF50BBBBMBYEBAAgFhEKVPas0FZu81MHpfGIqlAnB7uZ0pJQWMCBLEDDt8QDXIHHzPpToB74yGBFLnpfuAZd7AKRDE89lp+L9LJTPPPndHBrDDDZHzr2yoSmpH3zrXQC.acT4P1yfEKVZZDYJHHb6QywpjBBB2V3wiGToREXylM0PetVsZMMC53hEKBMMMjISF.rgwqVpTIUDsH6aPPPPvLh.KAAgsEdpAEDDDDt0PDXIHHrsvMZS9iIHHHHzXDAVBBBMDxGr3BrjHZIHHHryHBrDDD1VnB6VDUIHHHbqiHvRPPngHQvRPPP31CQfkffPCgl4fR2xIHHH7qFh.KAAgsEyQrRhfkfffvNis85C.AAg82TtbY3ymOCC64lEAVlcq8lk22BBB24HBrDDDZHRcWIHHHb6gjhPAAgFBU6U7+HHHHHryHBrDDD1VjBbWPPP3WcDAVBBBBBBBB2kQDXIHHrsTsZ0sTr2BBBBBaOh.KAAgFBIth+GAAAAgcFQfkffPCQDWIHHHb6gHvRPPngX0pUTtbYX0pU.rosMTqVM0i8fN7tmrVsZnZ0ppGWPPPnQHBrDDDZHUqVEVrXAUpTQEAKpqBqToxd7Qmfffv9WDAVBBBMDJRUzPelO7mEDDDDZLxpjBBBMDRfU0pUgMa1T0hkjdLAAAgsGQfkffPCgDRUrXQUMWIoFTPPPXmQDXIHHzPzzzPsZ0P73wUE2M.jnXIHHHrCHBrDDDZHZZZHa1rX0UWEEJTP8X.PrsAAAAgsAQfkffPCQSSC4ymGwiGGEKVDZZZMM1yffffvcBh.KAAgskxkKiRkJAMMMXylMTtb4llTDRcPIvFhM4oIsRkJxXDRPPngHBrDDDZHUqVEZZZJKZfDXzrXSClEOINZuffvsJMGqRJHHbaAYznTZAa1DXwQFYPBBB+pPy2pjBBB+JgUqVUBr3oFrYRnA8dtZ0pFRSnfffPiPDXIHHzPrZ0pRbAkpvlYHAVMShKEDDt8n4d0RAAgsEMMMTrXQTnPACiKmJUpzTTj6MpFrDAVBBB6Dh.KAAgFRsZ0P974Qtb4.vl0dEU76MaHQvRPP3VEQfkffPCoRkJPWWG555.vnIi1rltPQbkffvsBMmqPJHHbKQ4xkUFLJ.T9gkUqVQ4xk2iO518gJpedgsu95qavxJDDDDpGh.KAAgFhKWtTFpI.fMa1..ZZDWX0pUkMUXwhETtbYnqqCa1r0TlhTAAgacDAVBBBaKwiGGYyl0feX0rjlLpf9A1PTY5zowJqrB.PSQD7DDDt8QDXIHHzPpUqFVXgEPrXwLLxX.PSwLIz764b4xg4laNCQ0SPPPndHBrDDDZHUpTAQhDAYxjA.FSMXyPJxnB4m7CrZ0pg4medTpTIU5REDDDpGh.KAAgFhMa1P1rYQ0pUUC9Xtql+fNz6QxZFpUqFlYlYPxjIaZ6hRAAgaMjUHDDD1VJTnfxE24FLZyf.KRPIUuUVrXAKt3hHd73MEQvSPP31GQfkffPCoZ0pnXwhpZQhJ36lEwEZZZvlMapnU4vgCjKWNTrXwlhZPSPP31GQfkfPSLlckbxemn+jISFjMaVTqVMTrXQ3ymOTtbYDHPf8vi56cPFpJIvJe97nVsZ3F23FMEQvSPP31GQfkfPSLZZZaIZTziooog3wiiUVYEUpxnHXUpTo8hC28DJVrHJUpjxGrVd4kwJqrBJVr3d8glffv9XDAVBBMwvG8MbKIf9y5quNle942h6sSN59C5X2tc0e2gCG..HYxjHQhDRJBEDD1VDAVBBB..F5PPhb4xg0WeckfqxkKqDZ0LHvhNmPE4OYMC0pUyf3KAAAAyHBrDDDpqyrWqVMjOednqqCKVrnhxkY6Z3AYHgj0pUC555FFx0MKtYuffvsGh.KAglbL6V4.aT76T8FUtbYUwv2L58STjpnhZ2hEKnZ0pp5QSPPPndz7sZofffA30eEQkJUP4xkwUu5UgttNpTohJ5UMSV0.U6YTZBo2+kKWtoTroffvsNxJDBBMwvEVwELQC43omdZUpw3BLZVnVsZnb4xp2+jXzhEKJBrDDD1VjUHDDZhwbZ+HevxgCGnXwhHYxjpTjY0pUnqqCqVsBmNcp5nvGjwlManPgBvlMavpUqnToRviGOnToRnPgB60GdBBB6iQDXIHHTWpUqFJTnPcKl6lES1jduyOGToREjLYRwGrDDD1VDAVBBBJLKjHWtbnZ0pFLjTxk2aFfFx0TMnYylMTpTIrxJqfLYxrWe3IHHrOFQfkfPSL0K5TjPpJUpfLYxnDXwodO1ChXNEpVsZEUqVEKt3hHVrX6gGYBBB62QDXIHH..icSHUb2zr2idL.nJ16lAAV.aJ3jGEuHQhfUWc08xCKAAg84HBrDDZhw7fdFXSATUpTwvHwgRWFEQmlAAVZZZpzgRyhQKVrfToRgkWd483iNAAg8yHBrDDD.vV8CKpVq3BtnQFSyBjohBro.K61siBEJf0Vas83iNAAg8yz7rRoffv1h4nYwEVPhuZ1DXQu2A1TrEUGVRQtKHHrcz7rRoffvVfa0.kJUB1rYC555nZ0pHa1rvhEKvgCG08moYXV7QlppUqVQ974MjdzKcoKgb4xopSsRkJAcccTpTIwBGDDDDAVBBMy3xkK.rQ5.4Qlxtc6Ji0jGIKNMCBr3E3OUj6jXpToRg74yCa1ro92H2tmhxkffPyKh.KAglXrXwBJWtLzzzfCGNLTyUKszRnPgBFFMN0qn3ePFtnJZlDRuuiFMJxlMq54RhTsXwBrZ0ZSw4GAAgFiHvRPnIlpUqhJUpnhBCIjHd733Mdi2XKBr.ZNDVQvEXQQvid+mJUJ04lRkJo5vvpUqtE+yRPPn4CYE.AglX3BAJWtLJWtLrYyFRjHAdq25sPwhEMjpqlszdQQjhfmpvBEJ.KVr.a1rolKi7zp1LXiEBBBMFQfkfPSL7zYwm6fYxjAKszRaI8flsxglAHgR7nSQV0PxjIUhrHgXzyoYSLpfffQDAVBBMwv83JpiAKUpDRlLIxmOu54XN8X7G6AYHu+B.JgnjvoBEJfqbkqfhEKB61savJK3Q0RPPn4DQfkfPSLUpTQMHic5zIrXwBJTn.RkJEJUpD.ZrXplAAV7n0YNBUEKVDSLwDpBcub4xnToRvpUq..ao10DDDZtPDXIruAJ5.zMvnHq.rwMqxmOOxkKmJx.zyob4xpw5httt50KWtbph3ld9EKVTcSScccCsgewhEQgBET2nLe97He97pHVX90hp0FpPv4OFcLSGiEJT.EJTP83YylE4ymG555PWWW8dhd83dME86kNuvOecmB08f7WKe97g4medkQZRelvoYJEXEKVDZZZHWtbFDYkOed7e+e+ea36bz4xBEJ.2tcuWcH+qLMJ8uEJTvv2oM+7azqE+ZEAglUrsWe.HzbCOELliTBe7rX0pU0MrHQHkJUBNb3P0Eb.abCAccc3wiG3xkK0MBohN1pUqpz4TnPAUq2S0hDIhwlMavtc6PWWG27l2DwhESkhnJUpfvgCigFZHUZ0niaxjIMeiVx4usZ0Jb4xEb5zo5XtRkJJQUzwS0pUQtb4fGOdpajh3oi5NA50gJl6xkKCKVrfEWbQDMZz6nW6lAxlMKhEKF5pqtTedxc686G6jPtvImNcp96zFYnTfZwhECypRKVrXvOvDDZ1QDXIrmxNsfLUKKbytjVf2oSmF57MMMM3ymOjMaVnqqqVv2iGOpz1jISFjISF3wiGzRKsnhxT4xkQ1rYwbyMGlXhIvBKr.xkKGVc0Uwa+1uMtxUtBxkKGpUqFb61Md3G9gwoO8oQmc1I5qu9vIO4IwXiMFb61sAwVj3K2tcqDHVnPAjOed31sakaoawhEX2tcCtlN4n5067ycqhMmduye8sXwBhGO9c7qcy.QhDASM0TX7wGGVrXQ84hMa1T0018CvGGRbJTnfxzYsYy1VLPU61sq96lMkUAglcDAVB6oX9FP7EoA1L8Tj.DMMMTpTIkuC4vgCUMCQ2HHPf.FdMoQYBcShZ0pg3wiiXwhgevO3Gf3wiinQihXwhg4laNL8zSijISp94ozn41saUpDO+4OOtvEt.ra2N74yG5u+9wvCOLFYjQvi7HOBN8oOM5u+9Q1rYgSmNUuO73wipVmpVsJZokVTueoTF5vgC3vgC3xkKTrXQk.LtIWd2Zl.ZylMCoijDrFOdb30qWCFoovVYs0VC27l2DkKWFNb3PIV89QAFbO+hnZ0ppzWyEgQeelhZG+eWPPXCDAVB6ovWv1bGpwSEAcie5FWTDq.fJMZTJLnTys1ZqAcccTrXQjNcZL4jSh23MdCbkqbEDOdbnqqiToRgjIShBEJrkNkykKWJAO0pUSUSR1rYScyTpFphGONlXhIfUqVQKszBBGNLb5zIdhm3Ivy8bOGN9wONzzzfttNBFLHra2NJWtLRlLIb5zIra2Nb5zoJhWzM1rZ0pRHEcd5t8Mv4NTdwhEwbyMGtwMtgpKBEZLkJUBqu95pn6b+TTq.Pc+9D+u6wiG.rY5AIw97ZQiy8qhKED1MPDXIrqxsxNZMGMF9hzYylcKBtnZnhJFcpVqle94w0u90QznQQznQwhKtH9w+3ergQZBcCEpn4431sa3vgCUwtWnPA3wiGknMRnE8dhRGXtb4L75kISFDMZTTqVMLwDSfW9keYXylMbvCdP7TO0SgSbhSfAFX.zYmchCe3CqJfcd5VnycluwGuXjuabiL50hRgpUqVwUtxUvBKrPSSQremfMa1PgBETo1kRMHv8+cYIsoB97Ujdb9PvtQ+r2Kby9cZ8k62+LP39aDAVBaK61KfwKvcBdWywqKoRkJgb4xgrYyhUVYEr7xKi25sdKnqqiHQhfKe4Kiqd0qhrYyBqVshxkKCOd7fhEKpRkA0wWtc6VkdNRPUtb4Ptb4TB9HKKftYBcbPQSip0FMMM3zoSUTzneVpqFohWe5omV0V+gCGFm8rmEtb4B80We3Tm5T3zm9znmd5QctvoSmPWWWk5SfMRoJctg9+uSfWjxDSLwDHUpTpHxHzXrXwhJEqTyMPQbsQhO1Oi4T.52ueC+6z28ozsWpTICovldMjwEjffHvRXGX2Vf0JFxw...f.PRDEDUE0UR7w0BE8HpvyiEKFt3EuHd8W+0wjSNIRmNMRlLIhFMJxmOughbmDLPcEHcytJUpnJzb5F.oRkR4J27hKmhvEUb8zMP32zfdNj0KPQAhamBUpTAVsZE974CEKVDIRj.tb4B986GISlD+m+m+mpWuPgBg1auczRKsfAFX.7LOyyfm5odJUpF83wig5cA.2U5RM57V0pUQwhEgttNld5oQlLYfc61EAV6.bQz7HYw6r08yXtqc4atoZ0pHZznnPgBHZznXokVBqs1ZnZ0pn0VaEs0VaXzQGE1rYS0YrNb3PktTAglczpIUk3CzPBXL6F27cpVrXQ3xkK0hhjASVsZUkydCrYDbn5ChWaPTJq3EiMOcZbQJTsTQocHVrXpEuWc0UwjSNIdu268vMtwMv7yOuxLLIgROHeSexFInnV0Ymchm7IeR7DOwSfAFX.zc2ciAGbP3wiGjOedX2tcUjDz00U1YAInqs1ZyPwqa0pUCEYO8yBrQGgM8zSiO+m+yi2+8ee..Cd7jvVwiGO3C8g9P3u8u8uEG9vGdKVKBuVkL6mXls2.fsJxwkKWa6u+74yqhlDWPG85Ph9onnR1ZRpToP5zoQtb4T0gHUOgTydr7xKikWdYL+7yikVZI0rWjdssXwBBGNLZs0VQO8zC5s2dQu81KFbvAw.CL.BGNrpIPZokVTcyKesg5MqG4leKc9gFGQD7ZBiuoF9FqnOC301oYnqIpmPS5831UiZBBaGh.ql.L290lWvfDKooooLUQpNmL6uSzMkoHevSO.OpO7mC+F35553F23F3cdm2ASN4jvlMaX5omFevG7AXpolREUIRjFeDjzHyP79cL6CX7OenZLykKWvgCGn6t6Fm3Dm.G+3GG8zSO3Lm4LnkVZAACFTctlRUEc9lpcMR.M2DHSjHArYyFZokVfEKVvMtwMvm5S8ovMu4MgUqVUo+Rn93zoSDHP.789deO7LOyyfzoSCfMLqUJcyz0BjnVt3ApqVM2cnzm+l2Lg4atyEvw6tVRvA0PGqrxJHZznHc5zpH.S0J35quNVZokPhDILHRgdejNcZ0ZD1sa2f3CJhw72GjHdmNchwGeb31sazVasgN5nCzWe8ggGdXL3fChvgCiN6rSCqUPW6atdDoMlwO2w+dsYQZz5Pbe7xL702nWe96eyqSxE9Rm6MebJHvY+eLrEtiwbjq3crGu.t4oViDakKWN32ue3vgC0tAocRRK5x6tMx2pxmOOJVrHVd4kwku7kwEtvEvTSMEhEKFhEKFVc0UQ73wgKWtThBnE7naFooooRA2C5XtyrnVi2ue+PWWGIRj..a36RW7hWD1saGd85EG+3GG0pUCiLxH34dtmCm8rmEs0VanPgBawFHJVrHJVrHpToBra2Nb4xEBGNr5FK..qu95HQhDJqoPDXs830qWr1ZqgyctygScpSAmNcpt9gZBByhhLKH.vXTkMKhfGUK5Oz0vyM2bHYxjXokVByN6rXt4lCqrxJHQhDPWWGYylEoSmFIRj.YxjYKyGQyVq.ktXRDA2Oz3o+jtVkDvvi5CcLpqqi25sdKCu+Ii10qWuvsa2XfAF.ABD.s2d6n81aGczQGn6t6F8zSOns1ZCs1ZqpTjSaZfNN4+doRJfhZmKWtfc612hMmXtSg4VPAuyjoGimA.53ude9IHTOjHX8.NzBLlCCNg4tAhpaH.nbRb.nr9.yQmhV7NVrXHUpTX80WGW8pWEm6bmCW9xWVUT5zXqw7BXzB4zBW7alPOGdDddPLJVbgs.FEBSKxa0pU3wiGXwhEUcmY0pUUzA862O74yGrYyF5niNvS+zOMd5m9oQvfAQWc0E5omdTeVRP2Dj9c3ymO7i9Q+H7U9JeErxJqndbgFC4OZO0S8T3a8s9Vnu95S8cde97otQLO0U.aNCH409WwhEQlLYPxjIQxjIQtb4PlLYP5zowJqrBlc1YwzSOMlc1YwpqtJRmNMBDHfgw5DEkYh5Ifhh5CYaHlibJ8GRTB2JGnQRE.TBXL+5y2r.8b4QPkDmQ+9oeN5mkNm5zoSzd6sqlZBCMzPnu95Cc0UWHb3vvmOevue+viGOvmOeawzSaz5c7Hg40q2s7b4k7.ORh72mzyg+4mffYDAVMIP6LlWKH0pUCd73wPmjQK5ScGEYjmzOajHQvUu5Uw0t10PrXwv5quNtwMtAtxUtBhDIB.1z80qTohgPzSowfdNd73QsHMIZffVP17NtePTfEfwavP++.aNa6HKofWWJTAzmOedTnPACmSrXwhJ8UG9vGFG8nGE82e+XrwFCG6XGCCLv.voSmHa1rpaxjKWN7M9FeC7xu7Ki3wiC2tcKdg0NfllF5t6tgUqVwq7JuBNvAN.xlMKZs0VM77nq4nZiihf6DSLApToBxkKmpVDmc1YwhKtHhGOtx60neW7+K.11H7Rhq3BdLGAaOd7fxkKaHRkTMcwqYRyyAS56eTiPXdVYR+WJE+0adVBrgWyQ+6leeB.0wEUWhTjaIgUACFDs0Vanu95C80Wen6t6Fc1YmHTnPvmOeXfAFPs4sFU6TzF53QP1rXXyOF8dTpGKgsCIEgMIPE7Y85rIdAjZ0pUjKWNjOedjMaV7K9E+BbyadSL0TSgnQihHQhnRKAU.sjXJ.nVXlROBUSJzNSImCub4xHUpTa43fuqYy6N9AQpW5aoGWSSSY4DTwrS0kFYIDoSm1vM1nNhj7kq74yinQih27MeSTrXQDLXPb3CeXLxHi.e97gO7G9CiyblyfwGebrvBKfyctyo9LSDXsyzRKsfToRgxkKqFkRjWX88+9eeksgjHQBUjbSkJEhEKFRmNMlYlYLTP77MBcq.c8RirIA9enuSQQeVSaCObidcnM0TqVMUsbUuHfArofQd5kMG4KyeeleLROWy0UEIDhdLyylS.nlxB0qf4c61MZs0VQ3vgUodLPf.nyN6TUD980WenyN6DABD.Nc5TcMEuyGoZQkerWuMotc03EcdUn4EIBVOfC0YY75KfpEGpVoVZokPznQwZqsFtxUtBdu268vMu4MwZqsF750KhGOtxnN4K3RQph1MKEoENABD.4ymWE4J9BsbgcztH4KXuSXdw+6GgO+5pGtc6V0oT7nTwKH35kBHJ5CjIrR04F+2qllFb4xE9c+c+cwK8RuDd8W+0wK8RuDt90ut5lql+7TvHz3DJTnP3ke4WFe1O6mEIRj.yM2b3O4O4OAu+6+9pYOo4nOR04nYLKRAXqiPJhc56+6z2ub3vwVFGN7zYR9bkYgU+pZBslmHAj.JyE4O8uy++oMXvEeQBcpW4CX93ilRBjMR31sa0vf+PG5PviGOnu95CiO93n+96GACFDABD.974C.PMdq.1LEizZp6TJzE6pn4FIBVOfC0l2kJUBwiGWMLimbxIwpqtJN24NGVbwEQ1rYUtRMsnuSmNUQyvtc6aYmojMNvWPjhtB8XYylUcyZRjGuMr40Hl4TPPKfYNEB.O3zpzlGUIleeQEkNvloMsd2fi9rgRkHsadKVrfrYypDaYwhEUcuPyHwb4xA61siKe4KiEWbQTrXQ3ymOwhFtEfaICuxq7J3S7I9Dvsa23XG6X3O3O3O.+F+F+FpthiD6vMp15I.hDfbqrAB5yPyQ8hKFAXqCUc52Ic8GU+R7hTmCuCHo+exi4LK.i98w6tX9qIcsMIvjNt3mG30jX0pUM7cQ96Aa1rskqG3abiNuPQjmd8oBl+JW4JJwujvK2tcifAChfAChwFaLzSO8fgGdXDNbX31saUDwBGN7VpqQAANh.qGvoToRF1EUkJUP1rYwTSMkx4yohVmV3G.FpYAd5CnBilpIgRkJYnqBA1r0yIyVj+ZYtaoH3ozfSi1g39kHWsSB8nz0Q2.v7MQnlFf2gVzMeIASTZ+zz1nqJoZlidsoWGdwGS0PG4D7TwISy8Px45CEJDdoW5kfEKVvku7kQ974gEKVTckkv1itttxJClbxIwzSOMNvAN.xkKmgtgEXyl5f9NM84Buvv4Q2wbp2LKBCXiZvhO9n3WGYttoZz0L6TDopmfK9OS89Yq2lhZzuu5ccO+4vWeB.F1PFuQYn+M5wn0nnMwPWWPqywMnX5ZMJ8sKrvBPSSCm+7mWIBj5pQe97oLF3t5pKL3fCpDhQEkua2ta34SglGDAVOfC2v8BEJDZqs1vwN1wvm4y7YPpTofllFlZpova7FuAdq25sv7yOOxlMKRlLIhGOtJ8T7TYPudzqOOBK7ceSCz35svNWvFvlELJIF69kVg9VQnmYwkziooogfACp55L.rEwtNc5T4n8.P0MgzMDLmZG.i2Pj20m.aH3yiGOn0VaEs2d63Ye1mEczQGp5HhtwHk5HoKB2dHQR4ymGW4JWAu5q9pXvAGDABD.4xkSkhbpXzoTTQBd4W+Phkc3vgRHLMSKMmFX55ORLAWLLun1ePQjrYQlTg2CfsLeR4QUju9BEsN9OC0Ek70s3aHjajuQiFEISlDs1ZqpA8te+9QkJUfWudU1LAUWW4xkCd85cO3rkv9EDAVOfC2+WHQL1rYCtc6Fs2d6nToRXzQGEO6y9rp5xJVrX3se62FW3BW.qrxJHd73XlYlAyM2bHc5zFR0AE8DfM63MdsBw2IGu1InH0PXVfvCJ2XftwJOsH7TrxaB.fM8.Kx0sIQpTmbxiVEM9eH6yfeiUxmqd7G+wgttNrXwBdnG5gvm7S9IwwO9wUQwh51vkWdY0MyAvVtAkPioXwhvtc6HSlL3ce22Ee9O+mGABD.tc6FIRjPIXhp8Q9mSz0i7nNQiJJfMqgJByQ+0mOeaIhPz2O1uDk26TLuILfM2zBswgRkJskTjRQPD.FDbRaXjlQoTTtnH.SdYVkJUPqs1JFYjQvPCMDZu81wPCMDN9wONFarwfOe9PsZ0TiwJ5ZRJhW2OLpjD1cQ9FvC3PoHzb8ePKzP1z.UDzNc5DCN3fXvAGDO+y+7pVHegEV.SN4jXt4lCKrvB35W+5XpolBKrvBpzVQiiCZvGy6RI5XfWqP.aVyV7Z1f+GpM0ue8lET2TVuT+POFYLhTslPhrrXwh57GMu2ncN6zoSzZqshXwhob38Ce3CiQGcTzUWcgt6tazd6siidziht6taC0hWlLYfllF5ryNA.Ttq+LyLC.fRTmvsFjcjX0pUk+Uoqqiibjif+h+h+Bnqqi4laNboKcIL6ryh74yqDCPho4M9AWrM2mn3dUG8cHtMNvqyK9lUteFJBQj3Eyo9jLpXyQehGcWfM8YOdmT5vgCjMaVDLXPUp8FXfAvANvAPWc0Eb3vAN0oNE5s2dQqs15V7tLxo9ottjD0x2LkPyMh.qGvga9dzBP7K9ocEZ2tc3wiGUMVQopnZ0pviGOHb3v33G+3.XiaRu5pqhEWbQnqqi4medb9yedb9yedL+7yqloY4ymGtc6Vs6P9LMzgCGpTfQB+z00MTeRlGeFzw69I1ozXVnPAUZb3ceI4oOTQ.SQ8i5VJ9MHonW0RKsn7.nCcnCgicrigSbhS.61siN5nCLv.CffACZXQdplpH6VfZic5Fuz474medr3hKpJbXZNGJr8P2zl97ieS8wFaL70+5ecToREjNcZUJlVYkUvku7kwDSLAtvEt.JUpDRkJkx804PoH1bJBoOeoHiQhOnH4PW+d+t.KJBu.Fixc8DXBXb3wScIKI.ypUqJOyZzQGE80We3i8w9XnkVZA974S4qbgBERE48zoSq9675oCXitKjNWC.CMJ.IvSpEqlaDAVOfCuHP4QwB.pYMGUn5tc61PwiRBxnzVPOOWtboFkENc5D1rYCeguvW.QiFEwhECQhDAW5RWRcSD5lJqs1ZpBzlhdSlLYTh9nn8XtUv2uJtBXmKxcMMM04HdjGny6zygR8WsZ0TNXcqs1ppnZO1wNFdlm4Yv3iOt5yffACBfsZ3g7QhCs.eoRkLz8ZTA9Rh5VXgELL2BuUduIrw4U2tcCcccToRE0FUb4xEJTnf5ydKVr.e97oLw2Owm3SfzoSqbu84laNbkqbEb8qecrvBKnF2MKszR00g1oB8l9bEXyavSe1e+vXN5VoIQ.1ze8n2WTgqSVufl1FtBOM356omdPmc1Ib61M5t6twC8PODN9wONFd3gQas0lx5Enu+SPogmVexue+pGmNVMu9IuVE4dVmrAEAwGrd.GZm07BcFv3HxgJ.TtfFRzCUyHlC4MsvNUPzjvHJT7ztxaqs1Tt+9UtxUvryNKVZokvTSMElat4PpToLTyIzOOuVj.LVf36m9J6NEAK9NboyuNc5T4wPd73AiLxH3vG9vpTQzWe8gibjifQGcT32uejOednooAud8ph3kYu3gmlDJ5X.aLLmoT1RK9Cr4HQpVsZX80WGe4u7WF+ze5OEEJTvP2sc+dDP1sgtIOUvzOyy7L3u4u4uAG5PGR4ibj8X..CtlN8caxikL6OcYxjAu0a8VHZznXkUVAKu7xX5omF23F2.qrxJnZ0pJe3hd8b4xkglbfDwuekcRfUitV2lMavqWuHb3vHXvfHb3vHTnPniN5.iN5n3gdnGBCMzPnmd5QEQWtsOTq1FlXZ5zoMLLtALZQDz4O9iwOt3EdOeifzFnHuzRn4DQfUS.zBtbCnjWiSzLtidt7+NIbhd97atS07Ag4zX.rwMT3o4i102byMGld5oQlLYvUu5Uwu7W9Kwku7kQznQUB236LjKtZ+zWY2oaPPQYhragAGbPb5SeZbxSdRzUWcAMMMzau8hQFYD03UghxGIdhahqzMF3Q5i9bkN2P+ajsLPGizqE88AJEku669t3K7E9BpnlPoWR7AqcFe97gLYx.+98iBEJfQGcT7M9FeC7o+zeZjJUJ0nnA.pMoPWOYylMjKWNCBtA1HRTT8W40qWCQeLZznXt4lCQhDA5553W9K+kXxImDW+5WGwiGW8bueQf7Nc8CI9wmOeHb3vnqt5BCO7v3PG5PXngFB82e+vqWupn8RcsGu9F4dNFuoA3a7gVihN2Q0nE8Z.XzFZ3PhhoOS405kPyMh.Kg6H1IGcdmVjg5PtBEJ.cccDKVLbsqcMbgKbAbsqcMr7xKiToRgHQhf3wiqDPvauc5+2bQ.yeND7utS05T0pUUFqIEAGZQYpFNb5zIxkKGb4xE73wip3x4ogwtc6paBP+berO1GCm4LmAG4HGQc7EJTHDHP.CNQciXmt77V0JKL+5v2084O+4wm4y7YPjHQL3IPzbnTnwPBV83wCxkKG5niNvK9huH9y9y9yZXJh9UYI2c56Gqu95nb4xHSlLXkUVASN4j3RW5R3pW8pXkUVQMrnqW8cQP08m4t2s1+ey2jKdfhNCOkYzy0ue+pnu42ueCSO.Zi.VsZU8cp.ABfToRYnS9b3vAZu81Qu81KZqs1vi9nOJFYjQvQNxQPO8ziJZ4Nc5Dtb4xPDj3my3aHb6v7noxbWJJhjDtSPDXIbGwc5WepWJu.fZ7h32ueLwDSfyctyoFnzqs1ZXlYlAyO+7pncwquINTMbPQ2g6tzkKWFABD.YxjQ8uS0BVtb4ThWHAVNc5TIFTSSCm3Dm.iN5nvsa2pcXevCdPb7ieb0imJUJ3ymOCNgMcyjhEKdGWDr2p2.nQBrpToB929292ve3e3eHz00gCGNTQAgatiB0GRjsGOdTcQ6S9jOI9G+G+GwHiLRc+YtaJvxLTSQPQUIRjHX1YmESLwDXt4lSktwomdZrzRKoRmO2ZUb4xkxWonZuzLjMfjISFUg1ycDdpVontikDZQaFxtc6HPf.XjQFQEUpgFZHLzPCggGdXzWe8gVZoEjMaV0wCvl1w.IzpQmeuUOGadb6v+ul+6BB+phHvRXOEt4VBrYsNvqYEdWAQ2zXhIl.SO8zHWtbX5omFuy67NXhIlPUSE7aNTOmpmObW40eVf.A..PpToT6v1ue+HXvf3Dm3D3Tm5Tnmd5AgBEBd73AO7C+vFpyFtkXP1dAsSdp1nLmhh6EzHAVkKWF+w+w+w3e3e3ePEY.JRGhOXsyPeWi7.Nccczd6sie7O9GiG6wdr5dC55kJ8aWLe8CEoI92snwmDs4kXwhgabiaf4laNTpTIL0TSg24cdGbkqbEr1ZqopeHR7AIHhKxgtNpRkJJK.g57TxszCEJDhDIhxFD5u+9wQO5QwANvAPu81KBEJDFbvAge+9ge+9MDwOtQ6Z1ZF3m6ZjWSwSW9cBh.Kg6DjtHTXOEtqISv6THZwaplTpUqFZu81QO8zi54WrXQUZPhEKFt90uNdsW60va8VuERjHARkJExmOugBvmtIAcyQpFXnZ2viGO3.G3.3y849b3C8g9PpYOFUn4TjK3y8L53DXyFEfOZanTVRN3MUby6kjISFb4KeY..knTfMqWHQf01C2s84oklrLAJBpbtadSa928HQEbiHMa1rF5rMx+y5ryNwi+3Ot5684xkCISlDQhDASN4j3ce22EW+5WG27l2DYxjAIRj.4xkaKQyxgCGHe97JyT0qWupH4cricL7a+a+ai95qODNbXkEHDHP.k.PxrO40FEWjHuSaM2nM0aJQviB0s64YIlCB2sPhfkvdJjnIdQvy2ANMS2HgX7z1QygM9Nbc4xkp3vSmNMtzktD99e+uO9g+veHVYkUT6Hl6T1bGnml6eACFDm9zmFeyu42D81aunToRpnOkNcZUwKy2gMUWJ7lI..Ftw.uCunN96dAMJBVu4a9l3EdgWPE4BRj.kpPQf0Nic61UF5KMJh9NemuCd9m+420i.B4yYbizjCuHs4dpF4EcbKSg2.E4ymG4xkCEKVDQhDASO8zXlYlAKu7xX4kWFqrxJpMyPaXf7Zs.ABfCe3Ciu3W7KhO5G8ih95qO30qWUCznooskT8wutfe8O837+cRvn42u2shL3cyHLJzbiDAKg8TnHTUuVclV.l1kNYBpzMBH2yl2MP4xkCUqVENc5DACFT42Ml6DOJsGTDkneuzqUxjIwDSLA9pe0uJd9m+4wYO6YQmc1Ib5zo50zbWTRPQuvrySSctGEUi8C9Tzu7W9KQjHQTmOnTYVuA7qvVgJtcfMDFTsZUjJUJ7Zu1qgm4YdFCyhtciaVWuZ3iKPX80WGNb3.tb4R8cWfM1fBIHhD8P+bjWdQO2t6tab7ieb0we1rYwJqrBhDIBRkJEle94wEtvEva9luIVYkUP1rYw4O+4wMtwMvq7JuhJcf986G8zSOXvAGDc0UWn0VaU4iUz0Rl6VY5ZWBdpKMe9TDCIreCIBVB6prSe8Ja1rpcfyaicdqly8QHJMdzBrISlD555HWtbHZzn3ZW6Z38du2CSN4jHQhDX1YmEwiGG4ymWIJhJBX.nhzjSmNUdVkUqVU2zD.nu95SUzsm4LmAO2y8bpNZp6t6VcrvSMi45fgDrPoTjD1sSoI7t0MMZTDrdwW7Ew29a+sUo8jJtcJ5fRQtu8PBrb5zoAAoiM1X3a8s9V3oe5mV8X6T8XUO1oO+MmxNd2vwEgPQmj2HIj3et+PwqoKtUdPvS4IkZ9PgBgLYxfW8UeU7u9u9uhW8UeUjKWN0nng1bS0pUU0ynOe9fOe9PvfAQnPgPu81KFXfAvfCNHFXfAP6s2N73wCRmNM750K74ymJZwz5BbKufOhgtUNuVuyu06mQDsIbmfDAKg8T3FwG4qSjnJfM5lvUWcUr5pqhjISh74yinQihadyahYmcVLyLyfolZJrzRKo94JUpjZl9wSsHMBe3E8N0QeVrXQcSHZAcxCcVbwEw5quNz00wO8m9Swe2e2eGZqs1vIO4Iwu9u9utpKn5omdTF8HUb97zNR0+Utb4TQfauFtPJdj1.fpKwDZLTplc4xERlLIrZ0JBFLHlXhIvq+5utAAV6FTOOWhKPJc5zvtc6pMWPhR3G+T513CLbtupQ+8LYxf0WecjISFjLYRjISFTtbYL2bygyctygYmcVb0qdUjLYR3vgCjKWN31sa00d.aTR.Ku7xaQ3NINxlMaviGOvqWuvgCG3ge3GVMdaH2YOTnPpnS2VasoFYPTsTxOObmZCJBB2IHQv5dHlSC1cxqAAU6G7vny63FtSnysx.ZQTpye3sWMui9nhCmpCp5s.Fer1Pu+nEmqWMFwKFWJBRTZGlYlYTsSd974wryNKhDIBlYlYvhKtHRlLo5XibZ98ZrXwBdhm3IvYO6YQ2c2MNyYNCN8oOM.LNhM3uuIHC8jpKF5Fc.PIHiDhQhg3lE6N0IhT2ikMaV3ymOUKy6zoS7AevGfu7W9KiomdZDMZT.r4fdl9ra+tSfuWCINkFMNj2gooogW3EdA7c+teWUGolMaV079jpoO5yadzSI3lLai9CEQoFEcLdDpHqXf23H7HCqqqiDIRfkWdYrvBKfnQipZPjzoSi3wiiXwhgUWcUDIRDUQwy+8sa.2ZU.1Hpgc0UWpHe42uezVasgVZoEzRKsfN5nCzau8hvgCit6ta30qWUpT000Ud7F8YEePzSmWoqAoye7ZBiV2hahoziYt1w30OJ.LThB7wRF+yK900MJcnbSFl1LGuV6ngEOe8W5yG9mS2K6j4lQjHXcOf58EafaMgV6zOCs.KWTE+Bcp.TIAI7EmoA4LAWnDs..EgIpy9nKlo5lfVziW+DzwM8ZQoviRAwJqrhxlEdm24cPoRkP1rYQpToPrXwP73wQpToTQXxbQvS+N1ISN8dAACFDIRj.m6bmCu268dnToRXngFBG8nGENb3.+Q+Q+QHTnPn6t6VMWyJVrHxmOuZTZPK9Ss4Os.LvF2.mlQfjPKtieuSPelPCvYJJc55530dsWCKt3hpnTYV.sjdvcF56fbgy0S7OUOgz4eRLM0Iplcmed86Qul7ahRXNJMzFonMJQeWgKhKVrXX94mGyN6r3+8+8+E555HSlLHUpTHUpTHd73HQhDHSlLJOhCvnsHPBE1sSgF+5cZia4xkCKrvBHRjH3BW3B.XSaWQIlbsX...H.jDQAQ0hEKvkKWvue+vqWuHPf.HPf.JAXd85EszRKHb3vHPf.3W6W6WyP5FoMV3wiGUyuP+tA1rN630HFvlhZn0aoYQH+yCfsZCM7WedmFSme4u970.o0zoRof+ZUsZ05Venz4Od81Ir6hDAqcY3mdqWDrta3CNDl2AEeA.9w.s.AeDQvi3EeAfDIRnLUvF44L555Ha1rHc5zpEkoalewKdQb8qec7AevGfUVYE0uCZVqQdtC+2O2TNoH1PGmamohtW.cbQKnUnPAkELPKrN5nihG6wdL7HOxifCcnCgQFYDLv.C.Od7nJZWccc0fClJLZcccCQQh9LiLdwaEmfWWWGtc61Pw1SeN9W8W8Wg+7+7+bCylM52y9kyu62gtNgpsOJMbZZZ3rm8r3+3+3+PUee7wlC.TFoKAuILLWCe7AfN88.Jc1EKVTsAkzoSirYyphTyDSLAle94wktzkvMu4MUy0xBEJfzoSC.Xvw0Mi4gTN+3hNd4G+2sg1fEvlhP3ow1bmPxExvG0T70OnqOozl52ueDNbXzYmchd6sWLzPCgQFYDzYmcBOd7nlwi986GABDPMT5A1nIB3WyB.U51oiO53hKNhWSlbwUbpWDsnGi97mKBDXy0HLmUCyb2HaJB6Lh.q6Qb6D8pa0Wu5U.yzEgzEfl2IL+2Oe2slifAufrylMKhEKlZvylHQBjOedjHQBr3hKh4medr3hKhHQhfDIRfBEJnlkZjHAyy0K2tcav3B4iMiJUpXXGbbgXzto2qSgEUOW7ZagV7jZaeJRB0psw3DYrwFS4B7m4LmACO7vX3gGF.a1IjTTBozPPQpjawC4ym2vB60C9h3lc46+z+z+T7u+u+uqDzx8bHJcI6GhR39Y3yjSxRQzz1vPbGYjQve8e8eM9jexOo5lqTZDoywTJ94aLhGMZJMVISlDqu95HRjHHZznp5Qbs0VCISlDKu7xX94mGKszRp5jhvbAgSQxlt9lmhKyQWg2Qe7q83QUlX2RfEu4A3CsddYOv+cyiPSi99K85PaHhdexiBoc61Qe80G73wCBEJD5omdP+82O5pqtPvfAgSmNQqs1pZz9zZqspNdMe9z75sz4Ndp.oGybIEv+44aTpQkfAOSDMZSwB2aPDX8.B7zBv6Hu5AuK8nK.omqttNhFMJVd4kUyEv3wiiUWcUr1ZqgXwhgnQih0WecjNcZTnPgsjJI9N0nTfvCAuEKVTsANkBB9hFl++A1L5bl2U2dcZrnEpIiQku3NMBQHSdrVsZFDSZwhEzSO8fd6sW73O9iim8YeVbricLzZqsBWtboDUQczna2tQ0pUUQJ4VIEg7zrRske4xkw6+9uO989898vLyLCzzzLbbQ63Whj0NC2vXymOugTn40qW7bO2ygW9keYzc2cq7UJxs7og7b4xkgttNRlLIVc0UwryNqpNDme94UQahLR23wiizoSixkKC2tcukMe..C02E84Y8Rwe1rYA.1xM140An4HHw+NNW7ytw2UL6yczwgYQGbwIz2cqVspZleR++0acF9qIecFf5akJz5aVsZUk9Qp.7aqs1PnPgP6s2NBFLHFd3gU0BlOe9ThBIgtl+82n0roeNZivbqqoQkPA2CzD1aPDXcOjamvxxu.rd+rjQCRQ9g+yQQuf2cX7zIjKWNjISFL+7yiO3C9.bkqbEr3hKpp+IpdGxlMqAaKfewMc7PK3va4aRL..Lrq3F8UN9B2zBN7TtPuG3gfe+.jHKa1roRI.UnylWLmDgYNUANb3.d85Ed85ECN3f3i9Q+n3oe5mFgCGFiLxHvsa2Ha1rpNRrPgBHSlLns1ZaaO1nhamDXQ0b2+x+x+B9ZesuFxkKmgafQ65l99ivNCIzkhHD+Zu1auc7c+teW7rO6yhrYypFdx+ze5OEu1q8Z30e8W2v.OuPgBHWtbHc5zpMm.zXwK7MfX96algWX0lEOSWiwKQ.MMMCW2Wuiic6HXA.CqqX1e1nuq1nHBwgWqaz4JZFRZd.VSquvW+g9cSovkpOx5sgDJEj82e+JWt2oSmns1ZCG7fGDO5i9n3.G3.JO0yiGOvsa2F98A.kK4ysGC94.dM3xGJ27HpCT+64HoGb2GQf0tL7E6LKv5V4K3amPBd8zPQef5HOJMBQhDAoSmFQhDAKt3hXt4lyPm5YtKXnKLoWOpqm3B836lh1gI+8COD0zMTL28L7hF0r3IyoDv7MC3uF60cQHYKC7yQlodEmOufZoTy4xkKUgOSo2MTnP3S+o+z3nG8nn0VaEOxi7HX7wGW85rSW9Rh239J1xKuLdwW7Ew+0+0+kpVt3o6g++KKOr8Pe1RmaIQyzM5c4xEdoW5kvK9huHb3vgpd39leyuI9ZesulptrL+8XJBTj8FrcPQcgWmQ7q+3Qmzbjpnqe2onUxivB+0fmh9cquqv2PB86g9cUunmyEZ5xkqsrAmsaMU9lUozv2n2a70wMWubl+67TGyEnQc.Y+82OFXfALXGEszRKpZ+hFwPTTOo2mjGrYdSQTT332iod+cQj0tKRBZ2kg2kQD7adsSeA2bDgLGp6KdwKhkWdYL8zSiUVYEjLYRjHQBDIRDDKVLL2byo1gFe2tzhN7hwlKrgVvfpGn5syPZ2R7gnLcLS6DiJpVdcfva8XdscXdWn7yQ7cWCfs76buBxw1IesheiV5lO7a9w6FH5FiTcZQeFQuWqVsJVXgEv2467cP974QvfAwIO4IQmc1IN3AOH9TepOEN1wN1NdLlMaVTqVM3ymODOdb79u+6i23MdCDLXP0uW5bI+bJevOKTe3QuxbZvqUaiA980t10ToJNWtbvkKWHb3vJAT1rYS0Ioz2qo5Vbmh7.EgZyM6BUL5z0e7nNyqEKdc2wuoK88S95WlEzeu3lyz4Qyu+3GizwGAW.FEAcyulzOasZ0LLf14cCn4WW.XH5PTIVv88NdDfqVsJ74ym5yRdctRM1httNhGONld5oMT36j0RPy+TpVu5ryNQO8zC5t6tQvfAQO8zCZu81Q3vgUeWrdapmi4LEHr6gDAqcA3gomWqB7BeluKK9tenEkotJqRkJHQhDXokVB27l2DW5RWBW6ZWCqs1Znb4xHe97HUpTHQhDM7lgzE8.asXJMWqSB68XNsKTWCVrXQ0MLZs0VQqs1J74yGdpm5ovm6y84TCw2VZoEDIRDzQGcn5DwLYxnpMuu9W+qiuy246fJUpnDeIe9e2E55KmNch1auc7M9FeC7a8a8agLYx.ud8h3wiiuzW5KgW4UdEUDH3Bco0GHgQliNgbs68GPoLlmAf5kVU5+RMLAEwYtHWRzrEKVLz4hTzsZqs1vgNzgvQO5QwfCNHBEJDb3vA762uZyeT8uRoVT7AqcWjHXsKCEMBycyQgBEfttNJTn.VZokvBKrfxYjiFMJt90uNld5owEtvELTHizLDqd0W.cwIOEd7cpYtVajcur+CyelPE1d974Mzp24xkS0Qf23F2.e2u62EkKWFe7O9GGuvK7BJ++4ge3GFkKWFszRKnb4xX94mGu669tHQhDn6t6VUjyB6NToREr3hKhyctygO2m6yolP.ABD.G3.G.+re1OSsQIfM972sa2pnfP0HGfwNrkh7BE4DQj09S3Mzh4HGwSoLId1bWQSaFlO8InHeQNlOMn1sYyF94+7eNpUaS+zqZ0pnqt5BG3.G.m5TmBe3O7GFO5i9nniN53d6IhlTDAV6hPE9nEKVPlLYvUu5Uw6+9uOle94U0FyEu3EwRKsDlc1YQrXwTc8CE1eud8V2N0iRWVwhEMHhhW.3lq2BdH9o+eg8mvKxUBpyAqUqlpfn4yMw74yie3O7Ghe3O7GB+98im64dNDLXPbvCdP7BuvK.e97gDIRnJt2ToRsm7dqYBWtbgzoSiKe4KihEKp7sJcccjNcZUZ.4ctFMlm.1nFHIGXmdN7z5QHhr1+h4Zaj+3bAXjk5PkJ.O5kbqtA.JuILc5zF9dQpTofc61QO8zCFarwvC8PODBDH.5t6twHiLBN7gOL5t6tA.TEnuvtGh.qcA3hZnct3ymOL93iq104q8ZuF9+9+9+PznQUBi3cpB.LzF0b+1gZKaRbk4NXgd9znVgeLwWHlmpPBYQ58NpWgmRQsfWLxbWz1sa2Fpwt1ZqMXwhEr95qiexO4mfhEKhu1W6qgAFX.jISF7+7+7+fkVZIUsWIr6B4n2SM0T3Mey2Dm8rmEZZZnkVZQk9HxFOnz.poooL1WtHX9mWz2I3OFecGg8V3MwCulYIn59xtc6He97pNtl+bra2tpF8b4xkZcdxblKUpDBDH.750K5ryNwwN1wvYNyYvniNJZu81Qas0FBFLnxxW3YAgZrBZrIIr6fHvZWDRLCUOUtb4BO5i9n3QezGEewu3WDwiGGkJUBKrvB3JW4JXhIl.yM2bXkUVAwhESMTUoK930XEM.WqmQaRKTatM64hoL24XMR.lv8VL+4AkpWyEqK4iQYxjwPmbR++986G80WeHb3v33G+3nXwh3se62Fe6u82FyN6r.XizOxiPlvcexjIix1Nt7kuLdpm5oT2nihPAcyRd69yaPBOd7nJXcpvpoMpAHW6teByQUjKth27AziyGMVNc5DZZa3x9z2YHAQkJUBNb3PYaKiN5nnyN6DO1i8XX7wGWMYHnWaMMM0nYhawCzF4c61spwJD18PDXcGxN0IfzffkZWXpnhc4xE5u+9A.vvCOLd7G+wUWLEMZTL2bygUWcUbwKdQjNcZrvBKfolZJrzRKo7oJZP9ZNpF0yH5Hp2hw063WVfduCtP3.ABXHsuzBnTTqntTpRkJnu95CG3.G.81au3XG6X3i7Q9HXjQFAgBEB..oRkBKu7xptYilaZB6tPBlt5UupxjXKTn.N5QOJ9re1OKld5ow0u90UQqhbvepM7ykK2Vbzb9buCXqEOMfbM7dE7OG30AK8YEc8J.TiQIp1ZAfZ7831sabzidTzSO8fwGebL93iiAGbPzSO8ffACp7GKpikKTnfZ1wBrQICPhnLWdHz.lemlDDB2YHcQ3cH6jHEpaPnZsfB8eoRkPtb4TKlVuQp.vlNkb974UioFZrzr1ZqgevO3GfhEKpLMTdQwBroOMwEfwSk.2BE3G20ydID1cg+YQ8rwB543zoSUmE1SO8fO4m7ShSbhSfN5nCLxHift5pKkE.PQNUSSC+fevO.eouzWRsXKMnpkNQ6tOzmeABD.IRj...CN3f3e9e9eFejOxGQkZnnQihnQihUWcUkysewKdQ7Nuy6folZJzYmchXwhYX7IQQ+fWj6zeL2LKB26vrMW..CVy.kheMMMU8TRcUpOe9fWudQ+82OdrG6wvoO8owPCMDBFLnZFHRcaJvl2aIc5zHPf.puKvszBJ8ebyQkaqE7I4gvtCxY2cQ3WHQBc.1zf+nNJxbs0vgBuqa2tQ2c2M5u+9woO8oQsZa3L2+9+9+9PWWGqs1Z3F23FJGYe94mGoSmFqt5ppcLwsNhcpKBkhlcuAyhcoZ3gb64d5oGbpScJ7rO6yhSbhS.ud8ht6takHdWtboZPBqVspZRh74yikWdY028pVsJhGOtzIo6xTrXQzRKsfBEJfToRgHQhnpsRa1rg95qOzau8p9bnXwhHYxjHa1rnRkJ3W7K9E37m+73C9fO.YxjAYylEKu7xHSlLMzirjqa26ndQQjK50hEKvue+n6t6FgCGFG5PGBm7jmDO5i9nn6t6VMMGHgzTyPA.UZC4dRXas0FpTohxNVn54ilB.z06z2KnM7WuNaW3tORDrtGR8pOhcpS91ot7fa5cDzrKKSlL38du2C23F2.SO8zHd73HRjHXlYlAQhDQInim9I5BQx6rn1+kRYAcAp4NUjKbiOLYIaFfRyEOj4z+kJTW52IeXotWOtVL6QYzmcztR4y5O9mkTp739XCvlQfRSSSMliLOVNpVsJb5zopwHFYjQT6p8.G3.HXvf..p51ge7wONqUqFb3vARlLIxkKG9pe0uJ99e+uuZA65YBiB2cgpysN5nCr1Zqg+9+9+d7a9a9aptwHGt3Z5+R0cYwhEQhDIvbyMGt90uNtwMtAVc0UQpTov0t10vTSMkpoWn52xoSmpuWZ1Ay4l0Y8h3EOsVTz24c4FvFee07rHj6QWz057+861vu9grvD.XHJeTTiH+Gja5m7FDhu9G8ZYtt1LOVdHqSfZBoJUpn5pWa1rAmNchd6sWL93ii96ueU27cjibDL3fCBe97oNGUOmxemNmIo3e+MhD18.3WzdmdABegSdmo31saDLXPL93iaHm+whECSN4jX5omFoRkByN6rXlYlAW+5WGqt5pPWWWYnkkKWVMa83ESuSmNUEYcrXw1RMGvWvguXCuSXnNYodoDkVra+f.KtfPBR7BcrY9em+2ochRKJSE1JvliQHZGlzbH7Tm5T3we7GWU7pzmmzrJqdckDcbXVDe4xkgOe9v4O+4w0t10T2jf1E6d842Gzg9bOc5znVsZHUpTns1ZyvM+2NnM231sazRKsfAGbP7jO4Spt9IVrXpZ3ZlYlASN4j3C9fO.SM0TFZfAtO4QQKmftVkKNgOcGna3SBsnMBv+9GOJMbAC2K1+NeCdlsyF9nfhugBMsMc2d58G8+SF9JkBM50jDLw2vHUj5TWc6wiGbnCcH7nO5ihG5gdHL93iit6taL7vCiN5nCCo3iKFtdkpA83B2+hHv5dH0qvx2oKf1oEnnata94QKJCr4vHF.nyN6DgCGFm8rmE1rYS0ohIRj.YylEQhDAW8pWEu8a+13l27lHd73He97HSlLJq.fFNsDzMAHgSbQejAWRCwV9OiKWtTc4BEcL9LUb+hOcQKdyWDjOxK3QvhavqTwjxuQJ84fKWtvvCOL..N4IOIdxm7IwwN1wvPCMDZu81UKraNL9zmyzia9lbloRkJvoSm3m+y+4XxImD.aF0SIEA69TnPA0v4F.3pW8pHd73vsa2voSmpmm4tOiftwMecC55MJ5H81au3IdhmPUSNqs1Zp5156889dHRjHX1YmEKt3hHYxjnVsZaIhz7Q7D86gDCPQthDrwmCnjurwitycqMOdq.+7R8h.G.T0tDkZbxlCJVrHb5zoJR9bOEj9YxmOuZ5aPdNGEg4PgBgVZoEL5nihyblyfSdxSht6ta3wiGzRKsnlkf7iKyBpMWpFM5uKb+IRJB2iX6JN9a2WK9Bb7hjluyURPf4E+nHGQhjnEbSkJElat4vku7kw0t10vBKrfZA7LYxfabia..i6VsQikm58dkN9nE+3+7TMGrWBe9dUuNxjd+wuQC8dk1oK0YO986GG5PGBiM1X33G+33rm8rn+96G974yPAoxKPVpCxnaPvSiAciRh5ciNqVsh0VaM767676fW8UeUUzxpmMdHr6.YtnkKWFG7fGD+k+k+k34e9m2PmkUuzCtc0yCAsAE92C39jG0p9YxjAQiFEyLyL3RW5R38e+2GyN6rXokVB555HSlL0MhWz2Q3QFxkKWJwgISlT874hEnnhkISFCG+6lv23CgYargmZOa1roZd.5ZLyQqmRoeas0F5niNP6s2tpquerG6wvHiLhRfFEUeyhl3yXPYSMMWHBrtOGpUs4gdFXyEmKUpzVDIv8UKud8Ba1rYnPJovdSONulCJUpDVas0vryNKVc0UQxjIwhKtH9fO3CvktzkvhKtHxkKmgYo0N0kZlq8ARX39E3QMf+XjPE9f8kDvR2z6rm8r3QdjGAiM1XXfAF.G5PGBszRKvhEKvmOepVzFv3fjsdQtxb5SqmfUyBrra2N9Q+neD9JekuBVas0Th9DOv5dG7g.tllF9hewuH9m9m9mPwhEq62on+NvFCpa55adWfQvqAP56h0qtM4B2KTnfpf4u3EuHhEKFlc1YwjSNIt4MuIle94QrXwTlbIYFpTJ9ymOuZiO7nyZtdC4uO.t2HvhOK+nIgAs1BkVU9wne+9M3R5tb4R0Mt80WepFIYvAGDG7fGDczQGpqQoqyoq64BcoIsfa2t2hvO9whGOd1UOmHr2hHmdOlakT.tS+6lCqLufqoHqv6dDx+T762O.fJEdzhyzhB7HoPgO2lMapo4dkJUTyEQx1IhGOtZvTuzRKgW8UeUjOedjLYRUwVat0xoE2ntfgDrnooYXGv6UXtPgM+YFsa+PgBgwFaL73O9iiyd1yhwFaLzYmcht5pK.rgUaP2jhtA.23AoEmonOPh53+91NwU7mCIvJZzn3m8y9YX0UWstlSovtKd73QkZb61sixkKiqbkqfToRYvChZTpgnmS8p6OfMSUL2VU30iDEEJJZlzfB1sa2n0VaECMzPpHEmISFDOdbr95qi3wiib4xgexO4mfEVXALyLyfnQihzoSqVGwue+JWHm1PFEobZshcaQ7lq6PZCjz4IRfJ+bjCGNT1kSkJUvvCOLdnG5gvwN1wvXiM1+O16KOH6rrL6O2a28ceu6aulduSm8EffFRXcFDGQw0RG.sFQKlYbYDKqRqBwYbgQGKcJKmAwQQQmxRvQQDJ2cXPHDVRfr.Igr0ao22t66qce+8G424sete41oCDhzc36TUpjz8c8a448797bdNOn0VaEszRKpgkrr7976GuGTdOrL1KONyM2B.E4NNVbjF.pNt3D5Yv50Yb9RvR6qgrLQ7lY.T1Na4N1nQyISwMCRHCFvWW4tqkYHgOdFDm6pMWtbpAUL83m96ueUWOweV73wQlLYTYDhABMa17q6kHjBQWqH+c3vArZ0JZrwFwF1vFvN24Nw1111PWc0Eb61M.fZrVv.oRQBKMLTYFBkcWoLCYZuNfmenfi0BdMwS+zOM9ze5OMdoW5kNCsfosjm530dPBVxRA1RKsfu+2+6ia3FtA0iqRYuBn7x9KyvKulP5D3ZyxJe9jvQkx9Y5zoQM0TixvJAfJarLCPTalrCFoUvL8zSqHcwNhUtgIsZC8B40Z76C+NRYGPuFj1bRSM0D5s2dwpW8pge+9wMdi2HLa1Lb5zIb3vQYSEACFNsqpyxgx3.FLXPc7RNhyXVopt5pgUqVgQiFQrXwT1rhVoSPRo53hWnSvZENzF7sRBKkKpJIXwcXJsnA.nxrB0PAEos1RPxfozuU.Vni63isXwhkQXfOe1ESyO+7Xe6aeXjQFACN3fXjQFAm3Dm.G+3GGIRjPk98WOgbGxtb4BczQGXKaYKXqacqn81aGWy0bMvtc6k4XxxRPPSkkYOfDp3NaYYD.V3XuTybbveKecIYY4BXKFQ7e3O7GhO2m6ygDIR..nDcqd4A+KCHoVGNbnlhCVsZEe5O8mF28ce2kQ1YwHXo8moUH4xreBb56uka9gPRBg+Mu9VtwF40WTH6LaMjfW5zoQ73wUCu9AGbPLwDSfIlXBLxHif.ABnH+I+beg.xXYry+b3vAb3vAtjK4RPGczAV+5WO5s2dQ6s2NZrwFKKyfxr6Ky9K+9y6AomTwrBFOdbX0p0xrwF9ZxIs.KQobSoZyHs1yO53hGnSedENVLwiKg1c0JSaszggAJuiCOaD2HII4qsLHirS5jcrjbGlEKVDW60dsHWtbpxW8zO8Si6+9ue7XO1iob.6yFnVhn9k3L6xrYyHYxjnToRvoSmpcvmOedUm0UnPAX0pUk62WUUUAKVrnHe3ymOTUUUgq9puZb0W8UiN5nCrpUsJzc2cCmNcp5PLdrhmOzJ7b4wS4wd94mPdrm+edbcw7CMYlHLYxjprLFLb5oF.mqYTWWoSmVUZXGNbrrnDrWLCdcAKOLIwLyLyTVVlCGNLZngFTZxat4lScsQkHdI0r3Y69aden1LjwmK0vo1YjGe7xNcTtgL593szRK.3zaNHd73JWomyT08rm8fImbRLxHifvgCWlsDv2OpQsb4xo9LJ2bAONtXMBfOe9fMa1fOe9TVbRas0FLa1L5niNfa2tUMZBe+Yox48VZa7GtYG4vPl2GwML40q2JdNmG2jG63OWmD0arfNAq2fCY.O.nHAwEFrZ0pZWdLqSR2EWamnwELH4.onRk6TlhlchIlP8yFarwvi+3ON1291GhFM54TIB4uulZpA1rYCIRjPk0KJLX5qWFMtvfyspppRIzWNFJLZznx6v14N2Idyu42Lpu95Q80WOps1ZOCRlZIK85AjZ5P1V5FMZD80WeX26d2pNQTaFLd8t7quQ.LCU1saWIZ7zoSicsqcgm4YdFbMWy0fzoSqH6xLGWc0UiToRoDA8hQtZofVxWZyhTkJGo7wIEmujLG+8bdnVc0UCOd7nt+gDQ9G9G9GPgBEvryNK5u+9Qe80G5qu9vK+xuLFXfATFhLOVQ4MvM6H0uFM9X.f5pqNzRKsfa5ltIbUW0Ug0t10p17la2tUknKc5zJhNxRhyMHRi9jdZEy5N0nE2DIyRFONwlEQWGU53rAcBVuAGURzzRBVISlToQCpOANXRkBacwDesrq3ppppPpTovfCNHFXfAPvfAUCz5CdvChomdZ0NKoWzrTj.joeOSlLXt4lS84ko0mDgX453NkKUpD1wN1Apqt5fe+9Qu81Kt5q9pwkdoWZYcOI0rFKaGKwpYylecmjEIUwEC3BdEKVDO5i9nX26d2pySjLL+7qsE10wq8PVZ274yCmNcBCFNs8mLyLynxJDIXwrbwLxtXjnd0jIjJUhNsW+JKIozi2jcmp7ykzU24ygaXhwJb4xEb4xEZt4lw0e8WOLa1Llc1Yw.CL.dvG7AwS8TOE5u+9KSZAkJUBoRkRUhUpEQ9YjaVZ6ae63xtrKCd73QkEL1jN4xkSQPketHQIpapvgCq1rHyVkTFCRiJUpgMcsSoiyEneUxavgbL0v.GRRKL05LHmT.5UxClXfI5H7QhDAG5PGB6e+6Gm5TmBSM0TX7wGW4Z7rTckJURID0RkJoF2OmKfc5izgzAVnrYrKIqt5pQCMz.VyZVCdqu02J1zl1DLa1L13F2Hps1ZUGOxmOuxfYWqz1K...B.IQTPTAc3vgZgI1kirY.VtjteJrV43AIb3v3O8m9SX1YmE1rYqL27mcnn77oNtv.Ya6Cb5tZqXwhHe973O7G9C3Zu1qE986WY5kUWc0Hd73nppp5BZK7yqcylM6YzHKxrcJMhToX5kSe.fEb+b9clOFRZQNr4KTn.BEJDFYjQTd8FMnXfELtXd+K6TQtIG.fnQihSdxShO0m5Sg1ZqMTWc0A2tciMtwMhK+xubzYmcBGNbndMXFdIoOd+qOe9PoRm1PfyjIixpE38GrTlxiCDTOc5PGKFzE4tN.P4sPLCBQMJosrex19NTnPHYxjHb3vHPf.X7wGG80We3nG8nXzQGEyO+7XlYlAQiFUQNQ5N0kJUBVrXQ410bgH1scKkH2k6Hk+edIMCTu4MuYryctS7W8W8Wgd6sWXylM3xkKUlcjcikc61Kqa6jBTGXgLRvc095sO1vNQTqAGdzidT7NdGuCL93iC61si3wiq5TTJbWlUBcbgErjzlMaVQfmkp9du26Ee3O7GFQhDAVrXAVsZEQiFUcOgj7iDmqj6qT38E64J0HIkEfTCRZecIYdI4cRVgcVXhDIvXiMFN7gOLNwINABEJDRkJEBFLHlc1YQ0UWMBFLnhLFKWHMmUpCK9Yi2SSIKvLcSxOVrXA1saGtb4B974C8zSOX0qd0XaaaaXsqcsnt5pSsQIZDpjTo79bdbiw9pj4LetVlVc7FWnmAqk437k+6RE.HWtbk0xvb2qrSYjtpd974QnPgvPCMDFd3gQznQwwO9wwXiMFNwINAFe7wU6HV973h3r7b.mdQG61siLYxTVY6rZ0phrEyH0YC0TSMpc1Z2tcL2bygToRgZqsVr0stU74+7edzd6sC+98CWtboxlkrq+36K2sJK0Hy7CKCJ2gtVwq95IXCCH6jrnQihcsqcgPgBUF4QtnB2MtNtvCoeI4zoSjOedX0pUzTSMggGdX7q+0+Z7tdWuKUlVylMKb3vgRuQbfMKKaekD89hgJIxcfEhqPx4DRhDrLaZeeymOOxlMKxkKGhEKFBGNLlc1YwryNqxC7FbvAwryNKBFLn54xiCYylsLe5qlZpA1saur2GVta1zJ0TSMHWtbkY0I76mzfeoduBDH.BEJDdgW3EPM0TiZz032uezc2cist0shd6sWX2tczRKsf1auckr.XS2nsYAHQRYi+rTZvZoheqSP6hanSv5hbrT2fyzgSPBHLk86ae6CiO933Tm5TX7wGGiM1XpR8kMa1xxXjLvG02C24N2IJCFR+whZjh5iJSlLJO04bYX3x2SZzobwAtPQpTofACFJK3o70T93k5kgYDhsgMeujcbYkbb8+RCt6atPYpTovwO9wwi9nOJRlLIpt5pUkGU5aO74pm.6KrvlMaJRJbddB.DHP.TpTIbfCb.7TO0Sg29a+sqV.mYMZwzEo72ctb9SK4JoNo3047mSBY7dwnQih3wiiomdZLwDSfwGebL93iiomdZk4AGLXPksLv2ORJhYjR6mWSlLo5f2hEKVVGCS6kfWeJs6E9+488TugYylsLqVX94mGQiFUkA93wiinQihAGbPr28tW7fO3CBKVr.Od7flatYzQGcflZpITe80iN5nCrgMrAzYmcB61sqNFw+PxbZ84qWMPm.1E2PuDgKywE5afY.tvgCiAFX.7hu3KhibjifQGcTDOdbDOdbDLXPkdnjhdUFziuWRxVbWdZ8XGpYJIILo8Nn80Zo.yL.24oQiFUu10Vasn4laF1rYCd73As1ZqX8qe8X8qe8vjISn0VaU00cUWc0voSmkMdPnvckeNkZR47sKhVpuiK0uuPgBvhEKHQhDvoSmHb3vXW6ZW3i8w9XHVrXprP3vgCU4o3hDKG7Yr2n.YFR4DPvmOeHc5z31u8aG+6+6+6pNdkMnAKesTf4.KXwAmqDj0VZKVdM94He97HPf.3Tm5TXrwFCSM0TXhIlPkAJJA.1gtx6QYFQAfRahxGirTzjTD8WJolq38+RuhiipKlwKVxTYII46K.NiQODyJnLNCy1qbnxKOVRcWVas0p78tVasUrgMrAr5UuZzPCMnlcnUWc0JSEdwvRQPZoN+UIeMTGqbfNAqySn0H.0RvPqFdjlZGy9g7wH+2xz3ycEB.kCoK2Amz3O0lUJYFWX26LyLyfhEKhcu6ciicrig95qO0jhmkTxhEKpEfkDddkP9Y4Bj5rf+gmiLYxDb4xEpu95Qas0F5pqtPas0F74yG750KLYxDrYyFb5zIb4xEb5zIrYylRKHx1WGnbcZIe+qTWVxEbYvcRnSZZqwiGG1rYCFLXP4mR77KIVwySlLYB+a+a+a3K7E9Bn95qGgCGF.q7O+sREUJSST2fLqh986G268du3FtgaPQXgWOTnPAX1rYjISFX1rYDNbXTWc0gPgBoJkHu9QNqB401YylEgBEBABD.oRkBYxjAACFDCMzPXhIl.6ae6CwhECgBER4+aTGUZ6XvJUlwU5kZV62OfyzHVYGCa2tcXylM31sazQGcf1ZqMbMWy0nJ+Xc0UGZngFT2qJeM.VXHbyyUrqrkkrWJSC96jmW4OSd8jL6zrxCrzqT9DZ+tI2TqNtvAcBVuFAsKfosCsj6dSJhbJPSt6OIgMpACtiKo9CjZPfkFyrYypWizoSiPgBgCcnCgYmcVL8zSiomdZL3fChie7iiIlXBL+7yCmNcVV1oLa1bYt49hsv7JkKaHwmJsHAytiDjHD+CGUF0VasnwFaDszRKnwFaD0VasvlMaprdUe80ilatYzPCM.e97oJsfVG1V6bWT5YWxQoA2YcjHQTZUyiGOpqK3.aVNiHA.N3AOHt669twe7O9GUAoWIe9akNpjtm34KtQHGNbfa61tM70+5eckcDvqSjYHMc5zHe97HQhDngFZPcMCWzMYxjXhIl.G+3GGm7jmDyN6rHWtbXpolRUVe1EiLCNjbNyZDKMuLqYKVGydwPSRrTDrXVvXbARPB3zSEgrYyBOd7.+98iVasUrl0rFzQGcflatYTe80iMtwMBqVsB61sqNWJyFIP4dUlrSEYV0IwLVZR4FD44doU3.b5qURkJEpqt5NiycbsDNgAzwENnSv50.vEtzFHRJRbtKkJ0QJLaE.nLmUtXwhHc5zpNaSFftToRHc5zvhEKHUpTHb3v3nG8n34dtmCm7jmDwiGG4xkCCMzPHZznkoOIFbkk.isibkxfhL.5JwEnIQzEinA2cG+iVxwTjwUJqT.PM2wb4xE750Kb61MrYylR2YM1XinyN6DaYKaA8zSOviGOkQ5iAc0NlNzlEx.AB.Od7n7lGpYrppppxZTgOym4yfewu3WnVvsRVoA+253uLnRY2lKRZ0pUjKWNrt0sN7.OvCft6ta0B6YylUctdhIl.tc6FISlDyLyLXxImDG6XGCCN3fpgzbznQQnPgPnPgP73wUYCW6mAYWvp8yo79BVJY4ymuFWrbczh0v.Z+9wFgg2uI2XDaHHJHelwaOd7nhIzbyMiN6rSzc2cid5oGzd6siZqsVULbtQa5ufVrXQIre9YPNoG3l0XIOkhuWtAb43JhW2wysU56sNdsE5DrNOQktQTdQKEZobfgRxVbWGLCV7eyaBjDz.NsoexQQwTSMEBFLH9s+1eKBFLHBEJDBGNLBGNrpjgyO+7preH0Z.2gjzOmjZhh2fxRRc199tbGUp0pOa+e9b3e3wpEqTIKlQnxi0lMaVI3WtvjEKVfa2tgKWtPWc0Epqt5PWc0E5ryNQs0VqJ3Js0BfSqgmlatYUIAANc4A4qO8brq3JtBbpScJU1sVruuqTN+cw.pDAKtQK61siHQh.2tciO1G6ig67NuSTUUUAmNcpJGb1rYwC+vOL9o+zeJ5u+9UY4nPgBJgyWoR0IILIMWStPL2zlbiUxIuvYKyUWrb8yRQvhaz0fACpRySBM.ml.C0TJi6B.kQnlHQhxNVQg0Was0BmNch21a6sgUspUgUu5UilatY3vgC0TtP50fxRIJ6vQsqQH6zR5F974Woj.rTmG0Ifc9AcBVmmfWzxLeHGrxUWc0HQhDkUpHY4bHoG92.P08NzKYN7gOLBGNrxfNGXfAv.CL.lZpoTs7MIAQRATLnjXE+LJq4O.TKLSx.R+tRZreU5RjUpW1nMfAs1A4.nlONskXqRP5X7UZmhxc5pUv+.KD.WBa1rA+98Cud8hMrgM.CFLfFZnA0rpysa2viGO35ttqSMS3..drG6wvG9C+gUYu7rQlZk54uUpPqfz48pLKEVrXAM2by3W9K+kXyadypxWawhEL2bygW5kdIricrCUmhR8QxqO488T2mxR.x6kkk2BXAc3vWC40u7uqjFSuX6ZmyVIBYlk3OSl4O4TTP6Fl4wMRvgwHjDg4wdSlLozvEIas10tVUy4vtbjBpmZvkwp44aR7R5SX7br1plvXcK0jnPmf04GzIXsDXoN7HEXNe7bGpxWCZO.zslKVrHRjHA750KBDHfx+XN5QOJFd3gwryNKBGNLNwINARkJUYcHCE9nMa1P73wU6VB.k0VzTLk7yDetDLCIxxFH+dIKc4qziKKWvqjcqo8bF2c+h85AblypM973wRIANsY4jKhxz5yx9wEB46sYylUsgtWudQtb4v0e8WO9Q+nejpLCiM1X3tu66FO1i8XHd73Xt4lSE7sRXkx4uKVvhkEKpCFl8n+i+i+C7w+3ebjHQB0bKrpppBCO7v3FuwaDABD.974CoRkRY+FxNxiu1bCdz5D3hwRMawxMqUzzxtpawJQ3EaXwxfEgbfsCr.AYFWVtoUfEhQyMXwM3JEqNOOHkof1Xwqd0qV0Iz986GMzPCnmd5AaYKaAc2c2ptqT5MexQUj13RxMaetXyD5DrN+ftOX8Z.3hrxcCPi4TlJ9ToRgolZJDIRDkWx7a+s+1xzOQvfAK6hdoIRxaTXf4DIR.Od7fXwhobjXNE2KUpDRjHwYjcDBdiCyxkDbmPbfyd1d9K2C1pMyAUBx.b.kuK0yktjhOVYmIxfWU53qDR+AS6wTRJygCGpxTv.vWwUbEvtc6vfACHTnP3gdnGB+w+3eDIRjnLKwXw9tuR472EyfK1QxUEKVDO6y9r3Vu0aU8ymat4Ps0VK1zl1Dty67Nwm9S+oQwhEUCBZloR4XthYznXwhvtc6prWIsjCRPfwmja.nRYo5MxWmv6ipTbAVpWRJRRtgxAPVRWsPJYC.TVVn..5u+9KaNMRCUtt5pCd85EczQGJBWczQGvoSmvhEKvoSmvgCGpQ+CAEKOy.lNAqKrPmf04In.G4enHHIooibjifb4xggGdXru8sOb3CeXL6ryVlWuvRwIM8R4v6k6NQZWCFLb5tIiysLKVrnHwkKWNU1ojk8R1gPRQYJS2LIFxzPuRGZ+NTo.FU564hoMCBFXhY.rRo+mDhX54kDjjY5RJNUFvU50PoSmVkQp3wiid6sW7w9XeLUWHFOdb73O9iqHy4wiGDIRjkbPYqiW+.OmaylMkY3VpTILv.CfAGbPrwMtQjOedXwhEDNbXL+7yiFarQTSM0f3wii5qudkQxxEMkDnHwozoSq9+xXL7yfLCKxLcnUuluQE73kVRPjbhLyUbSPxGqrrrZqzgrxBx+sTxAL1uLdQ73wQrXw..v9129TUvvkKWvue+n81aGc2c2nwFaDc0UWngFZ.s2d6n95qWMLwY7esYnWGu1hk8DrjontToRp1KspppRQzfONYpUYJPkBRjDL.Vnq9jNYrrTNxtsf2jvE.kdeDCRMwDSfibjinFYLSO8zHRjH3odpm5r98i6pQ14d76I+dKCbxxMJ++yO+7pRCp80U6wRsjIju1ZMcxEq7R78ckHNW+be1zujDKFIFYV.zR9RBYW.I0qkLPsYylgCGNvTSMEV0pVE9m9m9mPtb4fKWtPgBEvC7.O.5u+9QoRkfKWtPjHQfYylOqDrVod9akJpzw64medjJUpxzg2gNzgvi7HOBtzK8RQ73wQc0UGhEKFb61shLeoRkTNetVMAwxRQs8PBVKUFY0946hgMW8JAK18CU53f16mWr6yNawO0BsqisXu+UxzX4FqYERN7gOr526ymOzPCMfVasUTe80qZnlst0shUu5UCOd7T1l+H4ZYES36CW2iZ7sRadU62CtVsbCqjbJ2zn1ioRC1U6q6JMrrmfkTiK.kOG3HwGoKAKEPNcEY4yet4lScCAEvn7BEouyv5iyQ9vryNqhf0K+xuLdgW3ET9MDMvO1dzxcFpCcrXfAg0ZaGL3hSmNgYylwTSMEra2Nld5ow6889dQCMz.RlLIN0oNkxVNj6Bl22nSjZ4MzZEBbgGJK.fE7HMRDykKWvjISpgjrr4IjaRSOClq7w4KQW1c4CMzPp0JMa1L74yG73wCrXwBV8pWM1912NtjK4RPqs1JrZ0p55Pud8hpqt5xr9AfERPg14xpVMpo0vq4mghEKVlDZjcLs70eoDg+xcrrmfEybD.NiwghbtcIg1ZgSy0i5ShisBBYqvB.k47M93iiXwhAylMiAGbP7G9C+AbfCb.0NDSlLoxqZ.VXwRNmsle94OuCxoSP6MNPdtlaJXt4lCACFD1saG0VasXMqYMX94mGgCGFVrXAG7fGDG4HGAYylU0PCRGlWGKuAIDwN2kMuB6JvLYx.GNbf3wiiQGcTk41FMZTk1ojyeOJtZt.oNVYiyWBVbsMYGmx415jSNILXv.N3AOH9e9e9efACFTiGn0u90i1aucbYW1kAqVsB+98iFarQ3xkK0HLxrYyJQ9KWCkWSKylEkpBMyZ5WX74HyfEulllr8JYrrmfE6pJdRkoImYrJSlLkMipnsCX1rYTSM0nlN8DTmJ7B.KVrf.ABficrigibjifIlXBDMZT073Z+6e+k04e7BUYJO0JJTVFyWKt3POCDWbCYacyzmyEL4bQylMaHc5zXzQGE28ce2nkVZAEJT.G7fGDG7fGDSN4jkMO13qo90NqL.2oO6TzrYyhrYyptFHYxjvkKWnwFaDlLYBgCGV4uc74xg5srCT0IXs7G+k3dTs5GS1XE7mQoJDIRDDIRD7hu3KpVayhEKnkVZAqYMqAs1Zqvue+nolZBM1Xi3JuxqDVrXQYF1Z04WpTofYylKyOtn9u355zNI3igVlCWWekLV1SvhFsWgBETVQ.c7VYFrHgK4.5khDkSq8BEJnBL8bO2ygm7IeRbhSbBjLYREgJdRG3zoozqWuJACavfA3vgixzGCmee7y.2MJu3TeX5piyFj5ugW6HaU6YmcVzbyMiXwhgVZoETWc0oVXMa1r3PG5PHa1rvqWuJ6YfFTn9BrK+gISlJyfeylMKN3AOHNvAN.14N2IJUpDBGNLxkKGtrK6xvi9nOJ9NemuCdrG6wJaxLTSM0.qVspHquRegIc7ZCXSLUI61fqiI0nrVmgmD+4rqD3zWuQyRlczXWc0EV8pWM5t6tQmc1IV0pVE750aYuejTEISQA2Ky9kL4ILqtqjwxdBV.KzodYylU4ZwVsZU4n0jvEybE.vLyLCFe7wUiIlidzihcsqcgicrigrYypFCML3jLsm7BOCFLf3wiqbW274yq5nKBYFrXFH.t3zP9zwq8PZiFrkpymOeYK5N+7yiK8RuTbK2xsfctycpJO9y+7OO5qu9JySc.fZjLUowghNVdAF+nXwhvlManXwh3fG7f3O+m+y3RtjKQ472bwnq4ZtFr8suc7m+y+Y7U9JeEL8zSiwFaLjHQBX0pU04c8xCewAVpyiK082ZmDGxtIUNNjHQKoA3BrP1uXoEYLENAAlbxIwPCMDNvANfJSXbvXa1rY7te2uazRKsft5pKzTSMAud8BWtboj9CKKtbF8JszB61s+p8P2xBrr2nQSlLoRSBjbkYylKaTxDHP.zWe8ggFZHLyLyfomdZbhSbBLv.CfQFYDUYESkJkJ3CS+n1KbHHK6rYypzzBYSyrXQS7SVhmJUxPcnikBxMGHSY91111v63c7Nv66889fa2tgSmNUVwwm3S7Ivi7HOhZTKkMaVX0pUU4kzIXs7GRuSS1kxW5kdo3i7Q9H3C8g9PvpUqHRjHnpppBtb4BwhECoSmFM0TS3q809Z3W9K+k3PG5PkM.3qolZTKVoi23BZeOLKVbsoWIwEjxVPq+4wWSojDXIqqpppTI9vnQivhEKnolZBqacqCqacqCM0TSngFZ.M0TSXUqZUvmOevgCGkoaLVMnUpaXXYeFrjjqXYBymOOdlm4Yvi8XOFFd3gQznQwvCOLFczQUDhXfJylMiDIRnLgS4qkrKGnsOTpTI0.xTalAH4IoaoCfyfXlr6sdkzpt53MdPdshbNw4xkKTWc0g+q+q+KzUWco7WsjIShb4xgcu6cigFZH0.ekMSAKANy.qNVdiRkJgZqsVjHQBjNcZ0t62yd1Cld5ogGOdva8s9Vgc61gISlPjHQfWudAvo02xW3K7ETcvbrXwJyHI0IWqCo31kYuR5qVTj5xNXEXACVUlHBoWJJy9tVxWxIH.voIhkNcZLzPCggGdX769c+NTrXQ3vgCTe80i5qudzXiMhMrgMfq7JuRr0stU32u++Bez50dT0W9K+k+xud+g3rAs0kkmvb3vA5omdvTSMEN0oNEBGNrRCCLyVTfdTv6TWVrCqjNYrzca46qQiFgUqVUAsXVFHIJY530ltU4tEzwabwhQxoRFQJvB63bSaZS3G8i9QXMqYM.nbON5kdoWB+te2uCG6XGCQiFUc+AsKD9u0sogk+P1kyRWX2nQiHVrXX26d23PG5PvqWupN1xoSmXt4lSU9jctycBqVshm7IeRUoWzN9a.NyM+oiK9g1y0jTEWahZ0TpcOlAIokeb1VOSJbd.T1ZgU58VVMHe97gZpoF3xkKr10tVb0W8UiK+xub3wiGU0qVIuQwk8kHTdRlWP.T978iC.08t28hm9oeZDLXPbpScJr6cu6xDYtc61U61mrwYWGx2K.nJeHGCEbp2yrHHcGYIVlenTGKCfj7Ccx6DIRnzeiACFv1291w8e+2O5t6tA.TWuRwl9XO1igG9geXbnCcnyaMZnikOP1YxDtc6FQhDANb3.0Vas3ptpqBum2y6Ac0UWnmd5QQzp5pqFeiuw2.eyu42DgCGVEyzrYykQ1RtHoNYKcPqPnRBgmRoQ5uZ.mo9hkicIs+NlAMfSutZs0VK5pqtPu81KZokVva9M+lUhimcBK8pqKFZTik8DrjVh.CTv5xxeOvBS9cZtniO93XO6YOnXwhX+6e+XO6YOXjQFAgCGVQ5xoSmpc8axjIUGSvTlx48EcYapmA1shFMZDYxjQwLWG53rARpRN6CMX3zC7YOd7fnQih26688huxW4qfVasUb3CeXbjibDL0TSgYlYFjLYRDHP.LxHif.ABfhEKdFN3uNVYgkhfLiq42uejJUJjNcZ31sazau8hq8ZuVb629si5qudTc0UC61siu+2+6iuzW5KgPgBAOd7fb4xobgas5uoRYYPG5..p4gH6DdYoBkZsRNH5kf9XU6s2NZokVv5W+5wF1vFP2c2MZs0VUdpUpToJyNFXBTnbHps1Z+K6W7WiwxdBVrbe.K3gFxRhTUUUgXwhoBvHmwd7jVjHQPvfAQznQwPCMD16d2Kd9m+4wvCOLJUpDld5oAvoK6HWvxtc6k4UHLEpzwYYWMxKBkD83m0k4GZ0wegg1rWw+jOed31saryctSbW20cgctychO6m8yhm9oeZL4jShDIRnzEnblWZ0pUcBVqvwRkE7lZpIL6rypbxcJ0gDIR.61siu7W9KiO6m8yhXwhAmNchhEKhuy246f64dtGkwjRWwlu9xR4nSv5M1nlZporraBT90j75Fo4YmJUJULH1zY974CNc5DlLYBM0TS3JuxqDWwUbEngFZ.tc6F0UWcmQGAJkxC2HP0UWcEMO7UpXYOAKRvQqAlA.kP6XoU3BPzxE3INlQJVq3BEJfnQihnQih8su8gW9keYze+8i95qObricLTrXQX0pUjISFU2bQaZfYrhj6jB8i+L.TVWUnCcHgLE7974CACFD6bm6D2+8e+viGO3G+i+w3G+i+wXvAGD.Kn+J48.zL9z6RrU1PtX1YKdAaFG1B8Teo986Gequ02Bu829aGgCGFd85EyO+73C8g9P32+6+8pRtHy.g1l1QG5.XAe3iYMct4lC974CYxjQstGga2tgOe9vN1wNP0UWM5niNvUbEWA15V2J73wiJ9jKWtNCsOqsKCsXwh5ZQoFp4FJVIik8Dr.VXPPJEfGvBAmJVrnxHPoYjlISFDKVLzPCMntfIc5zvfACJ+hgk9i5x5Dm3D3PG5PXrwFCG4HGAO8S+zX1YmU89IGfzrTOZGENZ0ykNt3FmKBvbwtEiAab5zI9NemuCt0a8VwS9jOI9fevOHhEKFrXwBhGOt5ZUYlq3tG0yf0JaToNQVBtPD.JaAJtwxpppJzRKsf68duWbS2zMgzoSCa1rgG8QeTbm24chScpSUV7JRvZEPXecbNfyWMXxrRIMWTsOGylMi5qudzbyMiN6rSrl0rFrl0rFzbyMiMsoMgZpoFXylMUBGxkKWYU5gD7k9DIu9UNNb35q7yc974OiYc3JMrr2lF.JeZZKaiTVdPNBcn2uvITeiM1nZVBRmNlY4hdDCYJWc0UiUu5UiN5nCTSM0f3wiiIlXBXvfA77O+yim7IeRbzidTL8zSi3wiC.nRmozuYXmXPF4muc.gdfvU1P64OY1qX1Tulq4ZvMcS2DBDH.Fd3gUVwfUqVA.TlwGC1vcCpShekOVp6uIoJYbOZiGbL5L5nih8su8g29a+sqxzvMbC2.9A+fe.Fe7wK64pKxccHAMhT45UNb3.d73Atb4BW+0e8n6t6FaXCa.s0Vant5pScsmVguKqlDyZEAqtiTqUlMaVYyL7ZbV9QSlLcQQoBW1SvhKjHY2RFwrkkoSuSFud73AEJT.YzVDc2A..f.PRDEDUxjQoKA9ZPcUwLYUnPAjLYRUYAc4xkZmg0We8vjISX8qe83C9A+fHWtbXfAF.6d26FG3.G.ACFDu7K+xpwVhL.H2s34KzKAzEOnRhbu4laFW20ccnpppB986W4yZ0We8XlYlAlMatL8I.rPYy4LJTGW7Blwbp+SiFMhhEKh3wiqlBEVrXA0UWcnPgBvoSmHa1rvkKW3K7E9BXO6YOpWqJ08W5wWdiMLZzH750KZt4lQKszB5ryNwV25Vwke4WN5s2dUMfCanKt4NslAJ0Rk14GnTC0.nLOZSqLaX25KsyAFyakJV1+ouRGfkm.YMZkSza9y4uiCB2J83jS0a46o780tc6J+3fB3Ke97He9732+6+8JhVuvK7BXfAFP4X7T2CZeMo1YnYnRF7jwOISxK73Evrt1.KrXMMJNo3U4EtLacKmw4pFTdk75HesVpQWDy5o7+yiqbQMfEJSsrCZ30Qj3NKWrT+exAuL0OCOuSwsey27MiRkJgzoSi5pqNktrnogxcWJ06G.zIW8F.HyRYkLsXpqz95qOEYb9bZpolfCGNvLyLC750KBDH.b4xERmNMb5zoJ69ReNhiMrBEJnzup1tOTKjZOU1t+.PUlHYbH4FLzdM8RA484RuW50Kb1Jwq1emzNCj9NEiMH0+D+doUCxx2Gd7iVZ.8qQRDmOVooeVSM0n5B0d6sWzZqsht6tar4MuYzYmcpDhN2HnUqVUeOrZ0pJq570SVBO45pK1OqRZoV6+Wd8zJcrrmf0xAnMs57BfpqtZby27Mq5pmYmcVL93iiie7ii8t28hCe3CqZudN6l.VPzxjHECbZwhkxVblA7jDq37dRJDQovm4mw2nIxdY4X0FDR6iSBsDVkkSA.kowNpAPY4pIQIYI73qAIgwzoyRIyfbNb3.uk2xaAFLXPEXapolBFMZDd73Q4mQ5PGKFxlMKLa1Ldlm4YvS9jOItxq7JUD9aqs1vsca2F91e6uMRmNcYK7FKVL.T98MRhPxel1x6HIjw6YpTy9veGP4lb54yF+VNVdyE6yAqxBOVI8SJsqmHO1KSNf1t+TFia94mWYiPFMZDNc5D4ymGoRkB.KLHwapolvl1zlvkcYWFVyZVCZs0VQas0FZpolfACFTlmMe+XEdjw5zwqNrhPj6udB4MFRQ1yedgBET+a4hroSmFyN6rHYxj3XG6XXO6YO3kdoWBiLxHHTnPpAMM2g.IMkJUJ0DG2mOeJm5VFHT6tDk2DvcHnknvxU7ZUFrdk9dJCTUocZRxuKFQUFzjyqRlIQ9yo30o450XiMB+98iFZnAzau8hK4RtDzSO8fDIRflZpIjOedDIRDbK2xsfm+4edTWc0gXwhsnBOUG5ffyus669tO729292BfSOFcra2Ndhm3IvG5C8gP73wUYCkjlb61MhFMpJqURRSRR.ZIPArPk.xmOeYa3jYZmaPjP68bDWrecsLlPkP0UWMrZ0pJS2LlMqPBAOFKW+Q1vBFLX.VrXAtc6FM0TSnyN6DM2by3u4u4uA0Vasn4laF0UWckkQJBR3UVAD9XjYaTGuxgNAqyAHIzrXr5ouXISyNe7jHVlLYvjSNIN7gOL1+92OFZngvQO5QwryNKhFMJ.fZz9TrXwynj.Re4xrYyvpUqksSTB4bgZkPIBuPdInMa1Jyoh0RNE3UemexESpolZfGOdP80WOZngFPCMz.ZokVP80WO1vF1.V0pVE5ryNgSmNA.Tc7JIUSWZOZzn3M8ldSHUpTnToSOBUj65WG5PKX4gpt5pwO3G7Cv66889JajgkNcZ7.OvCfhEKholZJL1XigScpSgwGeb0rKDn73DZkb.KsT0UWsp6tXbH61sqhUoUCpZKgm7eyMqdw9rZUKoRsjUpj6oyMIK0HGqVAAsv.ud8h0rl0fUu5UiFarQr5UuZbYW1kgN5nCEoYtoeFGQ1IejfL6NUYlrXrMcBVu5gNAqyQnc2c7BtDIRn1AB.JatExQwCIcI8zCN9SNxQNBhFMJN5QOJdtm64vQNxQPf.AP5zoKK3CSkK0lkLU9xcbJaAaRt6rgkym9ekbS8h0sdKl1HjolW19vbmhjTLCNwy+LiTbGgW1kcYvue+JBU7Otc6V89yOK4ymWsydp8OtPnEKVvy8bOGt8a+1QrXwTm+kNvsNzgVP+5ypUq3u6u6uCe0u5WEVrXANb3.4xkCYylU0g0YylE4xkCiN5nJarIe97XfAF.6e+6GG8nGEACFDEJTPQ5mMHj1rQwL7p0lZjOFfEzPqrrhUJKYuRt+c4JpTV5jeWIj2OaylMTnPA0Ft3F0AVPen74axjITWc0g0t10hst0sht6tazau8ht6tazbyMeF1XDGwRzbZkutkJUR0LDDUhrGKKoNAqWcPmf0q.nsTcxR1QF+xcfH0IUkloh7BcCFN835IZznHQhDXxImDO6y9rXO6YOXxImDSO8zHPf.nToRpE70lBdtKVYVtNWtwX4XYD0Jj0k5wpUDtRBTTSaxtWQ1x5TaIxyQ974Cd85ElMaFMzPCns1ZCaZSaBqYMqQIbXpaA2tcqxLEvB1zwbyMGxjIiZgHYWvx2addhKRcG2wcf+2+2+WL4jSBa1rAiFMhzoSqSvRGKJXIpc4xEb61Md5m9oQs0VKb3vAJVrnpSpyjIiRTxgCGFtb4RM62xmOuhn+7yOOhFMJFd3gwniNJd9m+4QhDIPf.AvLyLCBEJjROoL6HZu+qRYIFnxhgW63WQ9X0lc6ky2CH2jFPk0AZkJUH8zLfxaHGRR1kKWnmd5AaaaaCadyaVYUBtc6FVsZUkgdBt4a45KLyiTqVxOmYylsrLNJ+tnSv57G5DrdU.s5gh+es2fQWkW6yUJbzrYyp76Co4AxtRat4lCG5PGBOyy7L3ke4WFiLxHXhIl.gBEB4xkSMKn3MBxz6etbiwxwRHpUSYmMv.zxfWx.DZIaJS+tACFPWc0kRaTd85UM2rV6ZWKZngFfGOdJifFeOYG+vWeYJ7Yp146ozIi0lETRTKTnP3s81daXhIl.SN4jpLSrXK.oCc..0Ftnky789deOby27Mqr2gLYxnxfAajhb4xotuhKBKyrpbdvwMKjNcZDLXPLxHif96ueLzPCgfACh74yiomdZLxHifYmcVUVR.NcrN61sqzSjbCMxFzQtoGBoWBJwxQBWx3MxLXoUemxNKmkbMUpTppaTSM0fFarQr90udzau8hZqsV79e+ueXylM3vgCXwhkJFOj5.lcCOq7grhIz6GkqUw0KpzDRgydW5x55Drd0AcBVKAj2jTIvVwmDaXmhwZjyKp4hx.kuCOsWzyEl0VRR9bmbxIwgNzgvwN1wPvfAwe7O9GQf.ATA6jhfDXoIn7JsMo+KAjGuWp10coHXAbZQ.We80iVasUzQGcf1ZqMzPCM.mNchlZpIzQGcfUspUozDBWHf5iR1ITRaVnPgBvlMapEO3hcrrJ77ekDmJOuxx6bfCb.7te2uaLwDSnBpkNcZcBV53rB4jkn1ZqEWxkbI327a9Mk4GQLiUFLX.wiGGtb4pL88vXKRqCfOWd+.vYZRt79ifACholZJDLXPDNbXLwDSfAGbPLwDSfnQihHQhf.ABf3wiWVWwImEcKFAKIpT4DWNbeg1pV.TtdmjaPiYU2lMavhEKnwFaDadyaFaXCa.M0TSnmd5AaXCaPkARYVsjutxlogaHmDVYFqnVOIQJY1CAVXsAYSLH0gk1XU53UNzIX85LzFzPtX5RQtC.n+96GEJT.m7jmD+e+e+eXO6YOXlYlAYxjQ4iMEJTnLOKQtaU963iiDBLa1bYhYUKjARjBiDXgNYT5kTL6MLvuL6dTqQxRHPH0sgD78flQGIz5zoSzZqsh0t10hVasUbsW60BqVsBOd7nbmXKVrbFsMt7Xu7msTFc2YK3CO+wx7IKmBC3wt8569c+t3S8o9TvhEKn5pqFIRjnrxGnCcTIvFsfjx25V2J10t1EJTnfZjfIm2axravLfSHuWqRjpj3rc+Ay3Utb4PlLYPpTovLyLCFd3gw.CL.5u+9wXiMFhDIBlc1YUYWQlkWhZpoF08Jrr5ZmhAxpGnszbxgRL+7JqhfVyVUl0LFCiY0iY0oRkbSRxgmWXIXoyn2PCMfMrgMfsu8siMrgMfZqsVXylM3xkK3wimxzQKyrD0fE+ro87gNwmk2Pmf0qyP6twzRlXotAhNgq7FwwGeb7DOwSfcsqcgfAChImbRLwDSf3wiqBLUc0UCa1roFMAzVAXPkb4xgzoSWFo.oNlju+Uhfk119k61p5pqVUFA2tciXwhUQ8iY1rYX2tcDNbX..EwrpppJ3xkKzPCM.e97or.gd6sWr5UuZrpUsJ3ymO3vgCXxjIk1mjGGkZlie+jmKzpssyFVJBVwhEC1sa+LzkW1rYUAfiEKF9hewuHdvG7AUA94w.5oM5PGUBFMZDNb3.oSmFVrXA1rYC20ccW3S7I9DnPgBvhEKJq9P1nFjv.Kqj1XOUJFTkDvsVizUl4qhEKV13Ng2emOedUlgO3AOHlbxIUY7Jb3vHTnPX5omVYmMjLijTEIvHswDY4+kYLhed.PYwCppppJyrd0V8.iFMBKVrnljB7wnUFF72wXTlLYRI6fMsoMgMsoMg2za5MgN6rS31s6xl7H4xkClLYRIU.oVP0VhTYlC0dtQGKOgNAqkAXwVfm2je1.0XA2Io7FyhEKhXwhgQFYDbhSbBL3fChAFX.b7iebL3fChHQhnb+Y9ZvYSkEKVfSmNQf.ATuWxNsi+My7D+LKMVSo3MMXvfRmAYxjQk9apODY5nY.U.nHMw+lCczt5pKzbyMCud8VwL8Im0jZ+LKwhILUhyk.XKUFr.N84oBEJnzjRgBETcvyi+3ONti63NvHiLhJfOGBpWr2F6537Gd85UMSVA.5t6twC9fOH1xV1hhDkrLbjThr88IVrkCVrLXosAQzZiMoSmtret162HII96JUpDlXhIvK+xuLFbvAUc63TSMEFe7wwjSNIBDH.hFMJxlM6YLIF.NSumhjtjwUpDjkJkwd0RpSdbjyROylMi1ZqMr4MuYrl0rFzc2ciK4RtDroMsIjOe9xjUPoRkJ6+K+rJIPIaBfEKqU5jqV9CcBVKSPk14HvRmAkHQhnF5zTTiZK2FyXSoRkTCG1gFZHLyLyf+7e9Oi96ueL5nihrYypH8TrXQjJUJ3wiGUM5kltoVwapcTXv.pEKVT4UNj7F2kmEKVTDqrZ0JZokVvV1xVvkcYWF5omdfGOdP0UWsZ2fRRGbGr.k6.0L05xcXp8XqbWfZO9tXKjb1vYifE0mEydGGAIrjsQiFEe6u82Fequ02prQnDKgiNzwYCTSO7dzZqsVDJTH7O9O9OhuxW4q.+98qJkNK2U1rYQ974gKWtNiVy+r89Hg13.xrWe1dsjYRijMXIBIgBsipr4medDKVLkdtBGNLhFMJRkJEN1wNFlc1YwvCOLFarwPnPgPlLYTwpXVh4mUFeyfACpNgTRDSlEOYlt3mCloeOd7.a1rgO5G8ih5qudrt0sNzau8pZ1.NcGjjKkwcxjICRlLI762eYYmqRwupz4AcxUqLfNAqkQ3UaFTXWpIIcHetRALRvapKVrHld5owINwIvd26dwAO3AwTSMkReDISlT8ZQ+zA.J8ZY0pUUPIpOBtaLt6T9783wCZpolfWudge+9QSM0Dtwa7FQ80WOZrwFgKWtTuGbWbURWVZOlIOFoUDnxNoQ6wY4y8rQRZovY64xRv5xkKL2bygHQh.e97gpppJL0TSge1O6mge3O7GhScpSg74yWVyPHcxYcniJASlLoxDRgBEfGOdPznQge+9wG+i+wwsdq2JZu81gISlPxjIUYQV58R.KMwnWMPlsGfJWhqjISBylMq9bv3H7wKcJdFWfflmJ0oU5zowDSLANwINAN4IOIld5oQjHQT1KQznQUSFCd7RpOKI3T4HUpTn0VaEs2d6nkVZAaZSaBW0UcUXcqacvgCGJseJ+NK+LpUmaT34LaiRIAToR+8pcMAcr7.5DrVgiwGebX0pU0XYQVVIlEDo9JX1kLYxTYAvX5vKVrHhFMJ1+92Odpm5oPM0TCFd3gwQNxQvPCMTYYghhvV1EM70fAw339oiN5.ezO5GE2xsbKvue+nPgBpNkgAa3fpUqorJc0dY4Pk9ni12W97Ym3o0dFzF.6UaPqJUdRs+NV1OtiYe97g96ue7.OvCfe0u5WgidzihFarQDJTH02INDv0IYoiyFXFXYFQo9Fc5zIpolZv66889vsdq2Jtpq5p.voGgNLFfzote0Rv5b0NXjwfjYIhkHS1YaRKZPVtLoO1w+3zoyxtWVNT1Y7s3wii.ABfm8YeV7K9E+BbnCcH0igVgCvBw.LZznZvFey27Mia3FtAbkW4UBa1rohWYznQjJUJTUUUorOAYkCnEYv3jZEoOynnKWtJaCjRRoWHH8pi+xB8g87JbrpUsJTpTIUompolZfYylUyCLlUKYW1veGuIWZoDEJT.0We83ltoaB23MdinToRJ+uYjQFACLv.3vG9v3fG7fXvAGDVsZEYylsrtQT5f7QhDAEKVDISlDwiGGISlD974SEzQaoAjCI1ToRoB.IIFICjxEI3tX42Q9cylMakc7RaIJXZ7uPARtxnQivkKWHa1rXW6ZW3G+i+w3QdjGAyO+7puelMatLiEc4nIvpikWfW+vlcgBy1rYyXlYlAO3C9fHQhDX94mGae6aW4n6.K3SRKUiZb9jc2JUVdsP9ykc2KiMo0lSjOGNeEIwFsYwmxJHQhDvnQiJSUkwGj5JkuuxXDACFTo2KKVrnxtlMa1JyfgkBwmwAY2JmMaVjJUJUiEIyn0Y6X5Y6XuNVY.8LXsBGIRjP0Z+7FbRZP6brhoilcQjrCa3+mYYA3zYTxqWukomA.fPgBozs0ce22MBFLHBEJjpTEx.UVrXQoQjRkJA+98iMtwMhq65tNricrCTWc0g5pqN3xkKUGFwLPQAzJ69NYWPJ0+gVsTveGe7RQjJ61oyWrTK.wVjmcLzgNzgv23a7Mve3O7GfGOdPwhEgMa1PjHQTG+o6bqUjs5PGZAumzlMaHd73viGOX94mGwiGGd85EIRj.EKVD2vMbC3Nuy6D6XG6Pc+hUqVAvY5B4DZ6fsJ86pT444OeozhE2Hj1M.JE2MiGH6TYonv0Vdtb4xgnQih.ABfXwhgCbfCf8rm8fibjifIlXBDKVLU2VFNb3ynrbRsPwNfzkKWvtc6vtc6nyN6Dae6aGW5kdonwFaDVrXAVrXAd85ENb3..KLtzXEDjk2jcOHql.0gpTKbmKYDTGqLfNAqk4fBhl6Jhf2TxrVw.MZS2tLnAuAm1x.KwGCFPMCYvvocXbdi9byMmhjTxjIga2twbyMGN5QOJ9FeiuA1291G5u+9AvoCzyzta0pUUItjANj6ZbcqacX6ae6XqacqJS+ryN6T45zrKnjobm59JUpTpxLRhkjTlryjnsHv1VmY0Jc5zp+sbwA9Yi+sr7prTjRC8KQhDk0h1zLGYVEsa2Nlat4vK9huHt669twy8bOGhGOdYY5S6Nm0gNds.blWB.r10tV7Q9HeD7tdWuKTe80qtmh2Oy3ALqK79LFCfk.i+MInArPm2wGOi8jJUJ0XehMwgbyS.kalvxtmynQipY8pzDfkxavjISX1YmEiM1XX7wGG80WeXe6ae3EewWDSN4jKYihTI8WII2P6iQJh+ZpoFkEvr4MuYzZqsh0st0gt5pKzTSMozTpWudUhcmRYfwpXl1jBYmYASRRUtQxEivKIcJ0wFi+oUNDZWaPmH2EVnSvZE.joeFn7E8Y5lkihhEybL4h2xxqwV3lA7J8+ui9nfrqqt5PxjIQtb4vHiLB1yd1CFbvAwzSOMFZngPe80GRkJkRyPLM7x.1Dxa3kBv2tc6JQkRKXniN5.M2by3c9NemviGOJggK6FQ9YWFPWqdRhFMpRLp.mlTUlLYfISlfc61U9QkVAzJK+nzCcHgUdLKYxjprzQBUyO+7vgCGHUpTvoSmXngFB+1e6uEOxi7HX26d2viGOvpUqX1YmUctjmm0RzSG537ANb3.ISlTk4ZGNbf2y648f63NtCroMsI0htR+ZqlZpAwhESUdN1UwxrdIMgXYFmIXbFp0KY43KVrnZX2yMxsX5ijjujM.RlLYvQO5QwwN1wvK8Rujx.SmYlYP73wUk.kjZNaXoDQtryBkDe3mUYCDYxjI31sarpUsJzYmchFarQzZqsh1ZqMrt0sNzd6sqrlEIYTFaWloN.TV16kPpiKt4MFOpRY.S6m8kpIfzwqcPmf0xbHEQt1aZnNkXfGo.v4tEI3MgZ6DP9y.fRmT4ymGABD.CN3fXW6ZWXvAGDgCGFoRkBSM0Tp.1ZGgLz6oX11jcDjVvuKjXBIOZwhEkdt73wCpolZfGOdvV25Vwe8e8eM1xV1Bpqt5fGOdfa2tQgBETeexkKmpzZLPU0UWMhEKlx2ob3vgJiVx.XR8ioM.EEOub2jRRV7XQgBEP1rYgGOd.voGjp82e+3e8e8eE+xe4uD1saWU1vRkJoHgIg9si530RHuem9ulc61w1111vUcUWEt8a+1QKszh5dfb4xU18f7my4IHylDWfWZjnbgboPysZ0ppQaXVx48rZsYEYGzxRoMwDSnlUmu3K9h34dtmSYMCYylEIRj.Yxj4L17IvBtb+qTrTk1TBpwKsa.l+cUUUEra2tpyoau81wl27lw1111P2c2sZyYrSJkBsmjckuuZKkK2fnVKlfjn3wb94gOelovkZRUniyOnSvZYNHgA4t5j5IRqHsYfOfEL8So9FJU5zdyzTSMElXhIfACFP3vgwfCNHdgW3EvAO3AQvfAUByzue+JyF0rYypajYvKFHfYuAXAGMVRbZwfa2tQtb4TFxGG.pL3L8wFo1w762Othq3JvN1wNfe+9QGczA5niNTcNk7XgLM7rjpEJT.lLYprRb.T9nBgGSkhqUl4PY.uXwhghEKh5pqNUGO93O9ii8u+8iexO4mnDVapToT9OjACFPrXwd0cQgNzw4HXIByjICpt5pga2tQznQQ974Qc0UG5t6twsca2FdKuk2BZpolPgBEfa2tQlLYP974gYylUjHXowkFs44hPrkYWG.k4L5tc6trtBLUpTXhIl.80WeX7wGG6cu6EiN5n3jm7jHXvfnlZpQI8.4fklcFM.JqwYNeF0TRxZRxIxX.T5DZG2N7wArfu.RhXT6UVrXAtc6FqcsqEaaaaCqYMqA986G974CM1Xint5pS8bkFkJOVJsZBfEr7ARZRdtQVED4entwzwEFnSvZEBH4.YmBwcRJE9o1z0mLYRDKVLLzPCgicrigQFYDLyLyfQFYDL93iigFZHUoBMZznJ6JbmpLHCyHE80IfybzRHKOozzLIVrK0j5wf63xfACvtc6nPgBpr7vu2z2uXIK5t6tUZfXMqYMXyadynmd5Atc6VMS+3mCp8r4laN0Nekcej1tIRl8PsZwfGuXIT5qu9ve5O8mvvCOLd5m9owXiMlJKiUWc0JuvhkewoSmHRjHW.tZQG53zvtc6HUpTpMTP8BZ2tc0vW1gCGnqt5B27Mey35u9qGqcsqU8bkkJjYqhYBiC5bowByrVKMlXGNbnhGwMKQRCSO8zXpolRMiBGbvAQe80GNwINABEJD.VX.DKyJu1wtEuu8UZSgHIQct7XkYmB.JiRUVlNoFsXrKlQI4l3HXrDRFrolZBadyaF81auvjISns1ZCqe8qGc1YmvqWupWasynQYV.YV0kYjmeF3wecbgG5DrVlizoSqV7WlMEdyJa65b4xo5fFJzySdxShToRgXwhgwGebL0TSgrYypxDzbyMmJCUTLlxZyyaJIAHZNgb2WUUUUHXvf.XA2YmON.n5FtyFLZzHb5zoZ2X.P4DxLniMa1TdPS5zoUeN3umhMe94mG1saGs0Van81aGd85Eui2w6.c1Ymn81aGVsZUIfeYoMjGSAJe2p70mP1Z2DISlDuzK8R3du26EOzC8Pp.81saGNc5DISlTUhE5aOkJcZW0W+1OcbgDrAX38lxLhmMaVUGxM0TSA.fcricfO2m6ygq3JtB31sa08IYylUs4MtAGpeJfydGDVrXQUI4MXv.lYlYvd26dwy+7OOFYjQvzSOMFd3gUwR.VPuiLlfztYXYFkS8.YLM96jM7yhgkZCfmMBXx3ibSszGBqz6qraBIITYGTJIpwGOsuEZKDMzPCX0qd0XyadyniN5.aZSaBlMaFtb4Btc6V88gGCXCAvMGRszwXbZyhuNdsE5DrVA.4tAoQfN0TSgfAChfACh95qObvCdPze+8inQipFzpbQcl1XYlXn9qXPIJ.V99QBa.KHzyZpoFknJSjHAJUpTYCSVlFZ9brXwRYCS0ECURL7FMZD1rYSIpURTSaPd5+URsEHCTQMPrpUsJ0PWc8qe8n1ZqEFMZDqcsqsrtzT6BFRKcPlxcJ19vgCie9O+mim3IdB7jO4ShRkJglZpIkmeM2byAOd7.WtbgfACpzfEyX3RQ.UG537AUUUUviGOHRjHJR+r69b5zohDhACFfOe9vjSNILZzHdaus2F9betOGV+5WO73wCLXvfxyoXrDsYAgaRQd+2LyLCxjICFZngvt28twS7DOA5u+9UeVBDHPYVifrCCKVrnxm8jwGj2mJKcljTC+7sTyxyyGBV78Q99xuC76AspgzoSWVYD4wPYWVK6FbtISYC.H+NRQ0avfATas0hMrgMfssssgd5oGzPCMTV2LJqvfDZ27nNdsG5DrVliAFX.LwDSfAFX.L93iiYmcVLxHifSdxShwFarxB7TotPilNJACnVUUUozPAuAlVYfACFfMa1T6FT1gg78wfACpgLqzZAX5qookpEZ0qAuwWFfgCFYYG7Q8YQwuJ0Z.eLRw0KICIyLEypoYFVz...H.jDQAQ0WiM1HZokVvkdoWJZt4lw5V25v5W+5wpV0pThQm5afKZvOikJUBwhECQhDA228ce3m8y9YHTnPHa1rJMkkMaV30qWXvfAkQOxLFFMZTUvxJc7PG530JXylMkWrUSM0nF9x7eyLQSKKIc5znlZpANb3.qd0qF2wcbGXG6XGniN5PswKtoFoPoMZzHRmNMlbxIQe80GN4IOIlZpovANvAvHiLBFarwPgBETYaVJy.sYOF3LMnTRzPVldR9gk7RVZ+yU6N4bQBCxGq1t9kYFTV5MYFij5kRVlN94SNHtkwXYEKHAL4wCIjS6AZmMFMZDszRKnqt5BWxkbIvjISn1ZqEc0UWn2d6EszRKpXb5cQ3EVbQOAKdguTa.L.irjXxzZK8JDlZbsoxU97HAE4M17mwtxA.pLKw2adnmYKJYxjX3gGFu3K9h33G+3HTnPXzQGEACFDSO8zHQhD..mQPJcr3fcoHOm.rPY9La1LJVrnxjS6niNvV25VgEKVv0ccWGt5q9pA.fWudU94iUqVwHiLB90+5eMtu669v.CLvYHxUcniUZPtvs7eWe80iOym4yfa4VtEUFuXymvF5Xe6aeXW6ZW3jm7jHZzn3kdoWRkIcfSqkK54VRH2.kNdsEZ0RpEKVP80WOZngFPc0UmRD86bm6Dc0UWJITvXiUh3kVeKiciszdIjDkkSW.oVV4lWYYlkReQ6qsbRbTo0WWJbtPZ9BItnmfUlLYp33hgmnHgG4IYo3.AVHcsLCKr7aTL3xQjfLqJx4sGOLmJUJL6ryhvgCib4xgCe3CiCcnCgCbfCfYmcV0qcpToPgBEfSmNUt.NgVsXoikFxcVJSyNExqVMTbcW20Aud8hUu5Ui+4+4+Y3vgCDIRDDHP.bO2y8fG3Ad.XznQkn+0IXoiUxP6BM7+6ymODIRD7A9.e.7u7u7uft6tajJUJktmnw5dK2xsfcu6cijISVlo6R8Hw+lYgV1Ut530dPBVTGrrpErZDraLoFrLYxDZt4lwke4WN1wN1A5t6tgMa1fACFPyM2Lb61sRKczRfjlaJWiSZnpEKVrrtTTlfC5ei75.orUjqGKWeawtF8rAcBV+E.xRmoMkv7DobBtSQHxN.it+MynU1rYgYylgUqVUhPewL3yW3EdAbpScJL93iiHQhfQGcTb3CeXL5nipHPEKVL0PIlkfRZJn.kuqAYF2zIXszfkSTap7MZzH750KJTn.74yGlXhIPlLYvm7S9IwpV0pve+e+euRiYFMZDG9vGVMlajsttV8enCcrRDUZALtwQ+98id6sW7VdKuE7A9.e.rl0rFL2byg.AB.WtbgpqtZr28tW7POzCgu2266A61siDIR.WtbgjISV18cxRmouwjKLPVZUsqgHKwJiiQxM1rYSkwwzoSid5oGrksrErwMtQ32uezXiMpJynISlJqBObSrRirtToRkYjyxMixquzJDeY1tVLBPbswk6ZH6hdBV7BGYMrqjflkBAT9y4EEj4M8ZkLYxfnQihFZnAL+7yivgCiSbhSf8u+8iicrigfAChhEKhgGdXLwDSfnQiVl.FAN8tF3r1hD3n+yXvfAkfx0VhSotCNe74k2n.s57fdliL3Stb4vUdkWI9jexOIV+5WO13F2nZ2XISlDG5PGB+ze5OEOzC8PptuZ1YmUUlYs6z5h7aqzwEoP6BZ974SMtZnVB+HejOBtq65tPWc0ERmNMb3vARjHg59he9O+mia61tMX1rY0hvL6Fxx0e95SU5XwAImPsxos5JReBqlZpAlMatLuLjf1gAMKVa1rg0t10pFmYqZUqBc2c2Xiabin81aG1rYqLg9CT9n6QahB.PYkNTlcS99yWCYhEzIXsLAUps5k9oRtb4TcqFvB5qRxzlBBLTnPHd73HVrX3Tm5TXfAF.+2+2+2p1UNZznptlAXAi3iAUjVs.I54xkKUVwjsdL2U.ufSJ.RFbR1EJ5nxPp6JB4HuwpUqvnQin2d6EO7C+vngFZ.VrXAoRkBiM1Xnqt5B+leyuA268du3Ye1mUQ.uXwhn1ZqsrtfhPmfkNVICsY42oSmHc5zn5pqVQz55ttqCe8u9WGadyaFCN3fnmd5A0TSMHb3vvpUq36889d3q809ZpNokkDhcUrd1qtvBRDgUDgwijMI.vBDXjxlPlsIot4XYeIQYln.a1rolrFMzPCXcqacJiS0pUqvlMavmOevmOemAgHYhC36gbcR1jU.KL5fpjQptbEK6IXc99wSNJRjr5YIh3IOschwzSOMlXhIvfCNHLYxDFczQwi+3ON1yd1CRjHALa1rxBA3EsZaSXso.Ut6sJIRcJ7ZCFLT1r9R94WlFV8xRszP1oQRSPUdc0UdkWI9I+jeBZqs1TyQQZuB+9e+uGe9O+mGG4HGA986G.nLBwZISosKnzgNVoBdsMiKY0pUTnPAjHQB32uer0stUbO2y8nDHcf.Afc61gEKVfQiFw8du2K929292vzSOcYkDjKTqaQIW3f1Ndj+LYo23FE4iQZboLSVd85UYv0TRDDjzr10+jRvvkKWns1ZCaYKaAqcsqEMzPCvqWun4laFM2bynwFarrwqFAaHLN8P.NyxBxAS946woKj3hdBVxKhj9kT1rYQlLYPwhEw3iONNwINAFYjQP73wQf.AvQO5QwwO9wQznQUDjXYBYfBdAfzX4jsSLCNoct7QF5xQMiT2W74oUiUZSOpNVZvyEbXRO2byoZ0bWtbgK8RuT7M+leSzau8pFAGbGZ+te2uC2wcbGJyYLb3v.3zkMg65RqOeoSvRGWLAKVr.qVspl3.986GwiGG4xkC0VasXsqcs3gdnGB1saWMmOAfxCq9pe0uJd3G9gwgNzgTwFYYmRmNs98IWffV8KIyhkDTxKrRKDxrURsZQAxK6hdsD3jRuP95w0ylat4fEKVTlAc6s2Nb3vAZt4lQO8zC5niNP80WO750KrYyFBEJDb3vgJ1MIXw0KWpRDtTWectzIhmO3hdBVYylUM2pxjIClc1YwQO5Qwy+7OONwINARkJEJVrHhDIBld5oUL2YWRvtvfcVH.TmjsXwBRlLYEsoAFLQ6LpRVxpESr5xZRqUmXxGitFFVZX1rYkN23PrsPgBn1ZqEqZUqB+5e8uFszRKpf8lMaFgBEBSN4j3c9NemHYxjHYxjJeAimaRlLIrZ05Yz545DrzwESfaPgYrmYchcSsWudw+4+4+It4a9lQ5zoU9BkISlT5y5ttq6B2+8e+pASOi8o8dGc7ZGjqqnMaVUZMHoUKHkGCIDKkUCsNAY4dqzF+YIJYl9Y4JY0h30PLtqa2tgOe9P80WOZokVP80WOd+u+2Opqt5fOe9T1aDGia.Kcb1kpJOWnGYPUjfk7Go8eKIEHqMZkdNRWtUVdN9XnUGH6.AdRRdfgksiYRfc1UhDIfGOdJqKAiFMJFe7wQf.APtb4vniNJ5u+9wAO3AwfCNnRnlzCWVpS.j3j7O5XkC3NzxmOuZr.Y2tcrgMrAb+2+8iN9+OjnoHc862OhEKF9te2uK9hewunJ6iZulTuKN0wajgbXC2au8h64dtGbC2vMf4laNDJTH3wiGkHmCGNL9U+peE9ReouDhFMpJ6U1rYC4xk6LzEjtFFu3EZ6NvkJ9oGOdP0UWM750K5pqtvl1zlv5V25PyM2Lra2NZngFPs0VqZZCH0bMMqZY1zzZ5qEKVDwhECVsZENb3PIlesiRsWsXIyfE28+hMVDxlMqxSTj+NY5I4WPYlcz9Zps8M01EDxYKkrlsO2y8bXzQGECO7vX1YmEyLyL3Tm5T3Tm5THRjHviGOJMy.Td44nInc1fNAqU9fhqLQhDXt4lCW0UcU3K9E+h3pu5qF4xkqLivKc5z39tu6Ce8u9WWMNb30c5Dr9+wde4AGm20m+ydeuqVoU2V1Rx1qOisiOhuCINwMGjDJMDfTR4JsSojRfNvP6PnPl9a.ZoEBEZA5vLLMEZgzjABAHGP7Q7Q7U7QrkksrkOjrjrtVsq16c0pc+8GpOe0m80qrbhCwxxuOyrirk18ceO9d7434yyGcniw.W+l82yxKub7nO5ih669tODLXP0la81aunwFaDgBEB2y8bOn0VaE1rYCQiFsnn9qaf0zePaBjFXMYOmYzyXj3jMRaiFMhUrhUfJqrREetZrwFw7m+7QiM1Hb4xEhDIBb3vghuX.EKISiLxHvtc6Jk.fMBcNtTZWyaqq4qjTDJmDn0PCp9qYyl8RBGISwlrrb4wSNgRqprJqr.15FrZ0JhDIBd8W+0wq7JuBZu81QgBEP2c2M5u+9QjHQTmOSDIwkeORtNcYuAYvftwUWGCJEFDd73Ae0u5WEO9i+3..HVrXpMKxkKG9w+3eL92+2+2wvCOrpeKJS8KGCnmJPcbiLnCt1rYSkJvLYxfa4VtE7i+w+XzTSMgnQihxJqLzc2ciYLiYfsrksf22668UDkKz19a.zMvZ5JjAc4Jkb4rnunVcUJtGyBXxjISvqWunt5pCUUUUvgCGHXvfX1yd1XoKconolZBtc6VM10rYyJN2xiAM5hoE+p9ZNe97EtbWvLGoxb0JMJIZznJE8UqQRLbcrpDH4hc4xE.JVBExlMKFd3gw.CL.5u+9Q3vgQxjIwV25VQas0FN24Nm5BOd73pHOvaRkBjXyxT7Pi.ksxlK6MHwFo5S5u9CTewLYxDxjICVzhVD1912Nb61MFXfAPkUVIBGNLN3AOH9te2uK16d2qZrXM0TCFXfA.vk1mG0MvRG2HAsF8v0Oc61spKWDMZTTnPAr90ud789deOby27Mi3wiql6kJUJ7o9TeJ7Zu1qgDIRfJqrRL3fCpaf0MvXxLzRVgiRdHS9XwLbICnB2emqWSgB2qWunlZpAKXAK.Ke4KW0Xrc3vAl4LmIb3vAFZngfYylUsOsRwQq2JUdngQGczK6HYV4bxxnjVSRMpfjdKUpTHd73JQxztc6HZznvmOepOGe0UWcgSe5Sid6sWjHQBzau8h1aucbxSdRzYmcpZHt7FEiLlLMhTI0AFWaijssFskBrjL57g0U5MK8I7WeBNwjjz8IexmDO1i8XHSlLvsa2XO6YO3nG8n36+8+93zm9z.XLi8KqrxvvCOr53vm+5FXoiaDQoL5wnQin5pqFW7hWDABD.gBERs95l1zlv+1+1+Fps1ZgWudUbtZaaaaXSaZSJxOyhIR2.qomXxVmbx1+UReiRkIIo8..nnnhJo.j1OGyZQ1rYQSM0Ddeuu2GdzG8QwhW7hQ5zowPCMDb4xE73wSIOeuRsanHCrztIBOQH+njQ9QatyoLHHIUbnPgfGOdP73wQqs1J1291G5ryNQ1rYwfCNHtvEt.N5QOZQh2nTV+oR.mISFkZ.a2tc0uKSlLE0K.ogXxT5vp+RanE0pXrWNnOY+5WTVYko5ui974Cm5TmB4ymGkWd4n81aGetO2mC+1e6uEtb4BNc5DQiFUktCp+KkB5iIzwMRnTaTxxx2sa2JhsGIRDXznQzPCMf4Mu4gm64dN3xkKU5B26d2KV25VG74ympAPqaf0Mt3JMBVx2uj1NNb33RnvgV9xJA64rzVC61sqplw26688h+g+g+AL24NWDIRDDHP.U.ljmquULxxPgwf5hQqUhRIsmRfOAiTTznQUMuXJRm6YO6A6e+6Gm+7mWICBCLv.XjQFonxAkVRp0xSo.nQIQfZXDIeFiPkrJF0JOBrJBj2vk8NIs5XjNl9gpqtZDOdbr3EuX77O+yiJpnBbpScJ7Y9LeFbvCdP30qWzWe8obRHSlLpJWgoHD3RU3ZcniaTvDEIhpqtZzWe8ozsnt6takgVNb3PIFoKe4KW02596+6+6w+7+7+bQcTAcCrzQofTmtJEWXkPptAxpETROHdrj10Te80i95qOjKWN7m9m9mhu7W9KiErfEfgFZH30q2K43+VgKYlK0aRdxytvMMrJVrXnmd5QU0doRkBc1Ym3PG5P3XG6XpvDKkUAfwIEImPw9uGiR.4QkrwImOed31sajLYRDOdbEmp.fpBunlTY1rYE43kFSw7nxyedyVuEybiABDH.Fd3ggEKVvW+q+0gc61gYylwO9G+iw1291ge+9QWc0E74yGLa1LBGNLb4xErZ0ZQFWoCcniKELxUFLX.c2c2JgHk708HG4H3+3+3+.+nezOBISlDABD.UUUUEweFcniIBjD5xrlAboz8gfFRwzCRaMjYIiE2FsAomd5AyXFy.iN5n3+4+4+AIRj.ekuxWAye9yujY45JMyW.+eFXQg.iF0jLYREAFiGONNvAN.16d2qhuT8zSO3jm7jnqt5pjVywexa..3RRSmrCdK+LZCumjGLxdVjDSzum2Ltb+ccL8FL0x1rYCYxjAkUVYXG6XG3kdoWBtc6FgCGV0jsog8ISlDIRj3R5WZ5dUqiaTwDM1OWtbpJ3F.XvAGrnhOxpUqHUpTHYxjp1txF23FwBVvBv4O+4UEqjbyS84Y5PhRkxuKWZ.kuGfK01C4mOZznvoSm3hW7hvhEKvsa23W8q9UHVrX3a7M9F3VtkaAoSmVI33zXMJATSZDrFd3gQhDITUnWWc0E10t1E1912NZu81gUqVQnPgTShj4uDnXq4jbfhPexhNtVh3wiC+98iOwm3Sf65ttKjMaV76+8+dDOdbkiE.nnE2KEWD0gNzwjCIESLXv.RkJE73wCb5zIRmNMxkKGV1xVFl27lGN1wNlRcu0gNtVAYqzylMaHd73Xe6ae3q9U+p3Idhm.qYMqA4xkSI4OoRkBkWd4XfAF.ABD3RNdRitL+09ZeMb7iebzRKsfPgBor1iegRBtSMh.XrT4QxKp0fp2JbU4sRIOpCc7VE974CwiGGyXFy.YxjA6e+6G+hewu.1rYCUVYkpbuqsaD.L4pLrNzgNJMnQViN5n3jm7j3XG6XXgKbgpnIKqH8KGmZzM9RG+gDR9fmHQBUJESjHAd4W9kQxjIwS8TOEV9xWN5u+9ge+9Ub1sppppnNUC+ozFHiO0S8T3EewWDc1YmXjQFQwmIo3aI6eTxSnnQiVxS52JByoVh0WJh1qCc71ELUzbrLqtUGNb.mNcVTaSPR7QcnCcL4nTNHKi.rACFvANvAv9129Ty0FYjQPrXwTTRoTq0q63sNd2.bseJmOISlTE7HqVshcsqcgO2m6yg8t28B+98iXwhgb4xAe97gToRcI1pbIRYhUqVgMa1TxIOImNaPxxzABLlxp5xkKktBoCcLUFwiGG.iUIpri.jLYRDIRjhzWMB4+WeQdcniqNPCpndDRwl1oSm5NRqiq4f7y1lMaJ87jbC2nQivkKWXm6bmJirb4xExlMKra2tZukKGLxI.TjPo1P3vgC3vgihDZTfwDSzDIRbY0HHcnioJvpUqvgCGHRjHHYxjHc5zHSlLHd73EUwokp+XoafkNzwkGSTp83Osa2tp3QjueYAPMQGWcCuzwenA4.HsygpQ.CxzniNJ762O1291G9a+a+awt10tfYylQ5zoQf.AtDoaP6dFFkFOwblShbkJUpwdS+eUEhbRA0lJsQ.PG5XpFndqY2tcTUUUA2tcq5x.xFIp1l2r93Zcni2dPpIQzYbJTzYxjQU985PGWKgEKVTJ5tzdG92LXv.BGNLppppvANvAvW3K7EvK8RuDRlLoRGPIcpJkQVFSjHAJTnfJEJTz2LZzn5Km5GgLhUiN5nHc5zEcP02PRGSEwHiLBrYyFxlMKhEKlpqoyJhUZTktWy5PGu8gVO5SmNMrXwhRlTLZznhlI5y0zw0ZP44gbvRpD7LfSNb3.gCGFlLYBu4a9l3a8s9V3PG5PJt8p8kDFAfxnJ4lMxtWs1Mg.FeiHIIE0mvniohvjISvsa2vjISHWtbXtyctHVrXpB1vsa2pThSkClc.fK2jGcnio6XxF6K4gK83GX7dHGMrJRjHvlMaHWtbn+96WwAR5.eo9N0gN9CMJTnfJUfzfJhrYyhLYxfBEJn3kka2twN24NwW5K8kvK8RujhGVgBEBCN3fpiC+Ll.vSds4RSG53O7vsa2HUpTnxJqDqYMqA0We8niN5.czQGn6t6Fd85snvCyJaR10AzgNtQESlgNRk0lyWHkRHb5zIdfG3AP4kWNrXwB9O+O+OwO3G7CJxfLsem5NqqioJfsdOpSVrYP2UWcA61siYNyYhJpnBUqeJQhDHWtbvtc6POI35XZMXKQ3YdlmA81auHe97X8qe8vnQin7xKGQiFEVsZEd85Etc6F.PE0V8h3PG5XxAoRhrMjPijjY.o1ZqE986GEJT.d73on1fhdTh0wTQvrb..kxJvdf7N1wNv29a+swK9huHRkJErZ0JFYjQTcAmLYxnafkNldivgCiJqrRjOedzQGcfJqrR7ddOuGL+4OeLxHi.+98CWtbgQFYDDNbXUaQvkKWWqO00gNlRfKG8OHQ1YjrrXwhpxAoASO3C9f3C8g9Pvtc6XKaYK3odpmBIRj.974SW2C0wTZvwjrWFSNE50qWX1rYbzidT7u9u9uhm4YdFjISFX2tcEMSzMvRGS6AEWzBEJfO6m8yhN6rSX2tc7POzCAud8hvgCiXwhAiFMBe97AmNchrYyhrYyplToCcbiJtbF8HiRE4thc61QgBEPlLY..fCGNvpW8pgYylwfCNHb5zIRjHAra2NRlLYQcND42mdjrzwTAPtnSUSfoKjbO2sa23Mdi2.euu22CuzK8Rp2atb4FKxtFLX3I0COqNltBCFLfrYyBOd7.iFMhOxG4ifYNyYhZqsVTnPAzc2cizoSiDIR.2tcCylMqxgtUqVuDhtqCcbiNzVR5LBVRNnL5nih5qud7u7u7ufG4QdDE+r9m9m9mvd26dUEdBUCasGecnioBvtc6WBcQjc9CiFMB+98iyctygyctyg5pqNzXiMBKVrLF8TLa17Spu4gNltB61sqHwtKWtPxjIwpW8pgOe9vZW6ZwxW9xgEKVPas0FFZngfACF.6tAZKCWcnCcnoY1JzGQJRiiN5n3ltoaBerO1GC+Y+Y+YvkKWHSlLHVrX3y9Y+rpJ2JYxjWh.jp83qCcbsD1rYqHoafb5kDdOQhDHPf.HUpTniN5P0.narwF460zS9Vo4LqCcb8Fra2Nb61MhFMJhDIBduu22KBDH.LYxDZt4lwrm8rgSmNQxjIQnPgP5zogYylUDVTe9gNzw3PaqkB.pl3rMa1P4kWN9fevOHdxm7IgMa1PjHQfYylw2+6+8wK8RuDxkKGb3vgJE7SzwSG53ZMnFJxFTNqx7QFYD..3ymOzau8B2tcC2tciie7ii3wiiUtxUhJqrRXxoSmOIsLi4MzhEKpFZXlLYT8pP5IuEKVJxyC54B08DSlLUjdRnCc7tIjQchb8fFYcgKbATd4ki0t10Ba1rgnQih5qudrzktTbW20cgCe3CiKdwKB2tci3wiCGNbn7PmgI1fACE0jn0gNltBiFMBqVspVSmq+Stn3xkKjJUJ3ymO.LlyLekuxWAexO4mDVsZUIR0Nb3.qacqC974C4ymGs0VapptxgCGHSlLnlZpQo6PrWEpKSJ5XxfVsJTVUpjlG.EW.FTJQFczQUhNMvXsVMylMCSlLAGNbnLvxnQiHc5zp+uUqVQ1rYUsXGKVrflatY7POzCgG7AePzTSMM1bBCFLTvfACErXwRA.TvlMaEb5zYA.TvrYyErZ0ZAKVrTvfACE.PA.TvjISp+uYylUeV9xfACELYxTA61sWzuW+k9q2se40q2BABDnfa2tK.fBUTQEEVwJVQgssssUnPgBERkJUgLYxTnPgBEhFMZgCe3CW3m9S+oEpt5pKX2t8B974qfc61UyErZ0ZAiFMdM+5R+k9q2MdYylsh92d85UM92mOeELZzXgxKu7BUVYkEps1ZK7M+leyBISlrPgBEJzQGcTXvAGrPgBEJjOe9BoRkpP974KbnCcnBu+2+6u.vXyGc4xUACFLTvpUqEb3vgZeCtOj9K8WWtWzFlR8hqYa0p0BlMatnOmQiFKXxjoBNc5TsFuISlT+c61sWvkKWELYxTAqVsVvqWupwlFLXnPEUTQgfACV3S9I+jE9M+leSggFZnBEJTnvHiLRgHQhTXvAGrfgO7G9CWX3gGFW7hWDs2d6HSlLvrYyHUpTJK4n9lX1rYUzpjMIWfwUCdxtd92z8vWGuafKWZ773wiJrt974CCLv.nwFaD6d26F0UWcHd73vlMaHYxjvmOe3rm8rXMqYMHd73vjISE02onm7TLR0iTqNlNClFOVcTFMZToeUACFDlMaFW3BW.0We83a7M9FnwFaDye9yuHRvO7vCiJpnBDOdb3xkKXvfAzVasgO+m+yisrksfzoSixKubDIRDjOed31sajNc5KQYs0gNzhqDaLXTsLYxjRy1XOWF.p0yMXv.b4xkxVF1qkiDIB..b4xE73wCpqt5vsdq2Jtsa61vJW4JgKWtTiqohuyJNzP73wKjHQBzUWcgCbfCfScpSgyblyf8u+8iKdwKpNIMa1LrYylpGDpELja7K3xQTQcitzw6jPtXt1x8lxtfa2tQhDIvHiLBt669twRVxRvi+3ONpqt5PlLYTgIt2d6Eu9q+53q809Z3rm8rHWtbXjQFAiLxHE4TAeouAfNltCWtbgrYyNVq+vjIkyEABD.81auX9ye9nmd5A986GYylEequ02BO3C9f.XLGu49FCN3fnhJp.IRj.kUVY3rm8r3u9u9uFuxq7Jpp0hxihOe9vfCN303qbcb8NnSA4ymWkNOxiJpN6jBHTTQoDivz.52ueL+4Oert0sNb629siUrhUfZpoF02A2ifbzpPgBHUpTHYxjvPxjIK3vgC.Ldu2YngFBG4HGA81auXKaYKn0VaEs1ZqJU50lMapSXud8hDIRnTj2jISptvnUgRCpln+sNzwaWnsR+jBWXEUTAxkKGFd3gQyM2L9TepOEVvBV.tu669TPLEezL...B.IQTPT8KLWtbHUpTvnQi3PG5PXe6aeXO6YO3vG9vn2d6EVsZEEJTPoaOrwfpabkNtQ.jqT.iEM3BEJfXwhA.fpqtZTQEUfEu3EiVasUzRKsfa61tM7bO2yAOd7fQGcTE+U750KLXv.BEJjRjQaqs1vW6q80vO+m+yA.PYkUFhDIB73wCRkJkd2TPGWUvlMaEIRnb7DEDznQip3MNcjFXrw0yd1yFabiaDabiaDqe8qG974SE0KfwLrh78Rx6KZKD.fgLYxTf+hToRoH0KiR0fCNHhEKF5niNva7FuA1wN1ANxQNhpj1Ma1r585zoSUOcypUqpzMpMpB5FYoi2Ig1A0.i2DxYTmZngFvW+q+0wi7HOBxjICFczQQlLY.ctHd73HVrXHUpTns1ZC+ze5OE6bm6DCLv.ph5fGSsgXVG5X5JXzmXJVxlMKLXv.74yGJqrxPSM0DV0pVExjIC1912NZu81Q974we0e0eE969696P4kWNRmNMxmOOb5zI5omdTEbRjHQPUUUENxQNBdhm3Ivq7JuB73wCFd3gKh5I5PGSFJUknB.knexBdxpUqHWtbEQXcJaHNb3.KZQKBaXCa.aZSaBqXEq.0VaspHTkOedXwhEXylM0wmNbSv8bTFckOe9BLjuLUIFLXPwKEZ8G4gUhDIvIO4IwV25VwANvAPWc0E5niNTa1vIGNc5DYxj4RRaykyXKcni2NfFWIqrO9xfACn4laFekuxWAO7C+vniN5.0We83Lm4L3BW3BnxJqDMzPCpnx5wiGDNbX7i9Q+H7rO6yhSe5Si3wiiQGcTUE1xIaFMZT4wiNzwzQvJoxoSmHe97HQhDXFyXFXYKaYnhJp.CLv.XvAGDs2d6n7xKGm6bmC974Cd73AOvC7.31tsaC228cevhEK3hW7hvgCGvoSmXngFB0TSMn6t6F0We8XG6XG3a9M+l3Ue0WU8cyT0nCcLYPakDxemEKVTYUiUPX1rYUFKYwhEbS2zMg0rl0f0st0g0rl0f5qud.fh5PAT6q.FiOhxJJmNAX1rYUaxgedCiN5nEnUXTlFngTzKCWtbor7azQGUoXu4xkCc2c2X6ae6X+6e+3nG8n3vG9vpFenrcinseSoafkNdmBRweS54agBEPf.Av2869cw8e+2ORlLIb61Md1m8YwV25VQM0TC13F2HBFLnJburoOmISF7q+0+Z7i9Q+HbpScJzau8pHtnbBao3inNzwzEvH.3vgCX1rY3ymOroMsIEuqdgW3EP3vgUNcL5nihZpoFze+8CylMi.ABfO+m+yi+x+x+xhjrggFZHky7TXee5m9owi8XOFxlMaQsRGcniICkRhF.fxdEFopXwhAGNbf0rl0fa8VuUrvEtPrjkrDzTSMobXV1WMMZznxFF1x033VfhseghQJOeLZzHLTnDV3H+US1.b1q2RjHAhDIBN6YOK16d2Kd0W8Uwa9luIra2NhDIBRkJkR+f3lej.ZYxjQo8VbBW5zouD9awzWR9xHiRg7BVFVYcC3lZClVuIxfalFZt3Le1xnVQm.rXwBb4xEFd3gU8UvBEJfe3O7Gh63NtCTQEUfidzihm7IeRjISFTUUUgMrgMffAChQGcTDMZTjMaVTWc0gErfE.e97gToRgCbfCfm9oeZ7bO2yg3wiqHMuzYDIOQzNtTB8wh5XpHJE+E4uioryqWu3Nti6.qcsqEYylEG3.G.G6XGCc0UWW1ictb4PiM1HBFLHb61MBFLH9ze5OMpqt5vHiLhZceylMid5oG7Y+reV7a+s+VX1rYDOd72Mt70w0PHaT3z9..nVSUx26BEJnh5DWClGCZq.2WfeFtdrMa1PyM2L1zl1Dtm64dvhVzhfKWtP4kWN.JlRIx0oodepMxXWocafI0.qIKG3RCl3EZ5zoQznQQhDIvS+zOM5ryNwwO9wwYO6YwvCObQROuSmNUJmMyuOIdrUqVQxjIKY4vawhEUeliWzR4gPuJut9.Z8DPqWHrQvxE8oTgvm2zi33wiqd+VsZE986Geuu22CefOvG.FLX.6cu6Ee2u62E+re1OSQZwgGdXDOdb31sa3ymO30qWTYkUhlZpIDLXPTas0BCFLfScpSge8u9Wim64dNbricL04D2Xfiw3jYcdinioSXdyadXcqacngFZ.CO7vnkVZAG6XGC82e+SZCQ2mOeHWtbHYxjJ4cXsqcs3du26EeouzWB.PEUgQFYD7LOyyfOym4yLVEXou98zdPtsJWyjYjfAeQJXnznJIuX43D92n7RAL9X269tuarrksLTc0Uq3PEq7O.TRiq.f5u+1w3Jfq.CrlLut4DA4FiR9vPif5ryNwIO4IwIO4IwwO9ww92+9Qqs1p5Fpe+9UZUzniNpJJUbCLZ.mc61gEKVP5zoUuGfhMDT2.qqefTW0J0XMlGcNYh4OW92c3vgZRJyA92467cvi9nOJxjICZs0Vw27a9MwK9huHJqrxPf.APxjIQtb4P+82uRaSps1ZgWudQ0UWMV9xWNV9xWNBDH.BDH.xkKG1xV1Bd5m9owV25VQnPgTxRhLpZzXPork.nmRbcL0EZIHrTufZpolPiM1H74yG5omdPas0FFXfAthqtOmNcBCFLfLYx.61si74yiXwhgEtvEhe4u7WhFarQjJUJ3zoSXwhEDKVLb228ciVZoE31sazSO87GpKacLEARaG39.bcRJeGzAatFK.TcS.YEcWd4kia5ltIrxUtRL6YOab+2+8iJpnB3vgCE0mH+qj55YoVeVaTqj+7J9ZqTFXc0.dwJOgYzl.FKzeCMzPniN5.c2c2XG6XG3PG5P3nG8nHb3v.XrR0kU5Eipka2tUkSOvXUoX4kWNBEJzkvuK98puY1Ten0CBsfUwDaSGLJV1saWwApjISBWtboDDt669tO7BuvKfAFX...7HOxifssssA2tciJqrRDJTHDMZTjKWNUDXc3vA762Ob61M762OV3BWHV7hWLV9xWN762OZrwFgWudQKszB9u+u+uwu3W7KvoN0oTmerPQ.JV35jWeWtepCcbs.VrXonHHX1rY3zoS31sa3vgCUqsYngFB8zSOpz5whhZx1vQJHu7XFJTHXvfA7DOwSfuzW5KAa1roZ9ytb4BO9i+33G9C+g5BU8MHfo0SFrD9hMJbZTD4Ikjj4tb4ByblyDqd0qF24cdmXMqYMnt5pSI8BZacNDr5XAJM0Tj+7sKLeU8owXQvRZLC89QF5X5kOCcWEUTABDH.V0pVE9i9i9iPnPgvEtvEvN1wNv1291Qqs1JhEKlpbfGd3gUR9fa2tUQ3JTnPEYLmrw7pG4pqOfL8ZL0exA0RNNwlt4niNJhEKVQkyMiZTf.AvW9K+kQ1rYQUUUE9s+1eK1yd1ipBnxjIiZREizZ974QxjIQ5zoUMm1zoSit6tajLYRTWc0gPgBgJpnBXvfArt0sNjLYR3zoSzWe8gjISplGHkLBYEMxyQcCqzwTInsJXI2Unisc0UWHWtbEwOVY28XxP4kWtReEyjIiR6DykKGNxQNBhFMJJu7xUQ3xhEK3i+w+3XaaaaHe973zm9z+g5RWGSA.KdNtFOEqSYGDP9uoQ8UUUUnpppBACFDaXCa.20ccWXtyctprFvf5vTMBfhjVGtuA0zvIRlGtZgg74yqlk714.K4SEOFxiCshTdgRKRIy9ykKmJunwhECs2d6Xaaaa3zm9znkVZAs1ZqpHNX0pU3wiGDMZzhhZg76igZTmKLW+.oGCxEtsa2N.FmLjrEZP0d1jISviGOn95qG0TSMXwKdw3wdrGSU8GOxi7H3ke4WFd73ACN3fpJhko3iUYBa14zqFWtbAmNchJqrRLm4LGzPCM.qVsBGNbfpppJEY2aqs1PO8zCNyYNC5pqtTUTEaRtbBsdDU0wTYnUG4ja.IqTVNOzjISp1K0UBnwSwhESUwuqd0qFu5q9pvjISJtPFMZTLzPCg2+6+8iicri8N6EoNlRBs5XHqFU.nRs2HiLBLXv.pu95w5W+5wl27lwRVxRv7l27fMa1TjQm1SjNcZUgxYylMX2t8hdOLUjx.AI4A76T3pNBVrGUo8DkU7EM3RlaUY0DxVuCSCjISlvRVxRPvfAgISlvIO4IQGczA5pqtvK9huHN3AOHhGOtxZVRHd9.gS942q9lZSsA8ffFCKiFIqXT99rXwBJqrxP80WOV9xWNV7hWLVxRVBrXwBpt5pQM0TCpnhJTFg8S9I+DzZqshToRAa1rAe97gvgCCylMqJkbNYRx2OxSjToRgvgCi1ZqMXylMDHP.TWc0gFarQL6YOaTWc0g0t10hgFZHLm4LGblybFzd6siN6rSUTvjhPm75SG5XpBjbfQap5IWUXUeavfAEOYuRLtR5jgzIJqVshpqtZ0lmTMsc3vAZngFvC8PODZu81Uy+0wzWPd1RNSSd0ZwhEDMZTbS2zMg2y648f0rl0fktzkhlatY3vgCkrIvwPLSYLHLd73A.islapToTESGGSOQnTU.9a6qsq1HXQAWjforiF4vJsh2DjB1UlLYTb1xtc6pvUSwbztc6pOmUqVQWc0EBEJDFXfAvO6m8yvd26dQ+82OxjIipsJvEK.lXd8nioNPqQvjeUbB1bm6bgMa1vrl0rvpW8pwJVwJvLlwLfa2tU4jmiaot4L5nihm+4ed7O7O7Ofye9yifAChyblyfb4xgJpnBDMZTUSq0tc6pEw4wiaHvMG3XYZDue+9wbm6bQSM0Db4xEBDH.ps1ZgMa1Pu81KZs0VwoO8oQnPgPe80m55S5jgdpB0wTUPmYXW5PN9mqQy0wmrtYfzAXqVspbDOQhD3Nti6.uvK7BvpUqvrYyHQhDvjISvtc6XW6ZWXSaZS5B46zbvwQbedfw3f8rl0rPc0UG9K9K9KvBVvBPiM1XQZ0IyLFGWQaJXPaj8PVl4AZGhLcjRaWlHdXUJbkFsq2wI49aUbk90yMkjDfqPgB3UdkWA6cu6Em3Dm.u9q+5HTnPvoSmHYxjEoB8rZDHIoSkJUQ4qkgBmV1xx+OSlLvkKWEIs9bACZH3aW7tQD1Jk7UH2fmWCLhQT6P3.X5cA4lA.ToykdPHGbKI18niNJrYyVQo0CXbdeHallyXFy.0Vasn1ZqEyd1yFKZQKBM1XiXgKbg.Xb90I42D+NomKrZBey27MwS7DOA1111VQFHIG2bkdeWaDnzhpqtZ3wiGTc0UiFZnATc0UC61sirYyhToRgAGbPDNbXzc2ciKdwKhHQhTjJBK8PW2XKcLcCLc6zAX2tciToRgBEJf0t10hW3EdATVYkA.nZcU4xkCaaaaCO+y+7HTnP3nG8nns1ZSwiWYUkSNYJqzLIuLkUoLS+OWGhGGYELqcMFJV1zwKtdGOtS2aWV7dA4OMa52.ik1W5PKeNLxHindN30qW08LIOq3dr79O6mwyYNyAqZUqBqe8qGOvC7.vue+SpLfb4hD0TAL09rCWJa9kkBegBEv6+8+9wF23FA.P6s2NN0oNEZokVvK7Bu.5niNTSd3CZNYAXrM583wSQFIwIfxIeRoAfS.kUfvTcn0nJ4hPrkFIEwSfwstmUyIWPg8vO54gznUYnZAfZQI54JWHrlZpA2xsbKX4Ke4n1ZqEUWc0nwFaD0TSMvsa2pxmkGesmyRvEY44lQiFQSM0DZt4lwK8RujJJpk5Z+JwflIKBnrLxO6YOKZokVPkUVIpolZPUUUE73wC74yGb5zIrZ0phWVjT7ThSzgNltBa1rgDIRnF+KyvgISlPpTofGOdT83M5v6l27lwZW6ZQlLYPGczA5niNTUxH0gqd6sWUkmKMLRJSPjTzRBOqUZezVZ9.i6DHScIO9zIMo7rLcFzYQxCOSlLUjRlSJUPgDmsWOpElxheykKW.X7ljrKWtPkUVIti63NvJW4Jwsdq2Jpu95QgBEfa2twPCMTQ88uqGwT9HXMYa.MxHifToRAud8p7RYjQFAm9zmFoSmFO2y8bn0VaEm7jmDm8rmE.PIZYL5DLUQz..pTr.iOAikFJilCCM4T89kUoLlPx4BoZ3psLYAFWPWoWaz.KorIvnbwRnczQGEtb4BkUVYXjQFAyYNyAqYMqA27Meynt5pCkUVYnxJqDUUUUE40ozH5I64doVTLUpTpTa7s+1ea7E+hewKIMwZMv5pc3OUycY0rZxjIUK2wiGOp93VjHQTdDmMaVL7vCiDIRTxqIcnioCvgCGJcthN5v0IV5RWJ14N2oJEgrJuJTnPQoSjN+w2SjHQP+82OFd3gwHiLBN5QOJ1wN1AZokVP3vgUQOVqQAzvHowXR9gIMPiqAQGFKU5ijN.NcEb8M9RltX53srUxPmb49lTJbny5YylEUWc039tu6C268dun4laFM1XivlMaJwlk6m+NIWntVgq4Qv5JQGU36qTuW1pEjQVwoSmXgKbgvhEKXEqXEX3gGF81auXO6YO30dsWCG6XGCm6bmSI2C73PCoXJy32uzaENAUa9ampBs4JVlpUCFFqCiyPgKyMsUqVUbgZ3gGtHxlSiqnQWrhPqpppPs0VKZrwFwxV1xvBVvBvRW5RA.TjLWlxMschbIXjGmn+tLpbzvWY5.JqrxfGOdTx8AWXmGafwiF5UC32srqrmKWNDNbXk20Nb3PsXsQiFgSmNuhLhTG535cPdKx0XXEewBThTtfqgv4voRkBISlD974qnTJYxjITYkUhJqrR0Fvqd0qFezO5GE.iwCyVasUrsssMbvCdPX2tcL3fChN5nCzWe8oJBpBEJnbNloqOe97JdASPZGHW+Plpwo6FXQNLwdRIyXAMHkYlfYpvpUqpfQHo+PCMz.tsa61v8bO2CV4JWIpqt5TDU2tc6Jiu385ToRgDIRf.ABbM7p+pGWyMv5JAkJJLbyUNAlo+S9dIA6YeHJXvf3S7I9Dn2d6E6XG6.s1ZqX26d23Dm3DEU0WTWVhFMJ750qRVIj83Hoz7ekbtq87+caHWbfmKLkdrKiSCZXTnXO5iJnOWTxpUqn4laFyYNyAyYNyAUTQEJiops1ZUo2ibbS5QnLO8FMZDwhESYfhrLZYnm0ZDqV8JgbqBX77wmOe9h3G.eux9dEumb0FleZTk75jgPmWujCZ77fNBLUm+.5PGuS.Vw3btQhDIPYkUFtq65tJhzxx47Nc5D.iIaOL8hZaSJbs.4e2iGOXcqac31tsaS4bVas0FN7gOL5pqtPhDIP+82ON5QOJZs0VQ5zoUhbJOWYzW..hGOtxgSFAMt1+zciq.PQQmRd+mYrfo+kU.JoaRkUVIpnhJvse62Nt4a9lwZW6ZQyM2rJZ9YxjQs1urB+rYyF73wiZrx063ZdJBe6.YpcJk1YHUtUZffGOdJJDwzapvgCiyctygSdxShW9keYrsssMzWe8A..2tciLYxTDorY5yjS3ubnTQo3c6a4xJqrTBvJE6MRTbt.ha2tga2tA.PEUTAVxRVBV8pWMl+7mO762OLYxDV5RWpJm5zfA5ACixkjjiLT+LJNDznpRQDUs7vSdOUZDVpToTQj6EewWDexO4mT8rD3RkDBYIj+1EL0GZkkD44l76iokfgQWVp6WGNUTG53xBFgC5ziQiFQxjIwl1zlvO3G7CPyM2rZcC1uBkkQujuO.i2Df4uiQBSajw46QN+iqSjNcZbtycNzYmcBiFMhCe3CiW60dMb7iebEugHuijqaJ2yQZ3wkCWsTf4Z8ZBjCVLxeLiEbOQ1JjRjHgR2.CFLH9ve3OLV0pVEZngFfOe9fACFPxjIwHiLBb3vgx3oToRUTU.B.kCq4ymWs+yDgo5YA35RCr.FefGaFzjfcRvHXQs5hQRfcnaNIg4pOWtbHSlL3XG6X3Ye1mEG5PGBQhDA81auJQKi8+P5gkjCMkBkJBVuUtke0N.hQJhQ5ge2L24rJIoRjOiYLCUH3apolvl1zlvrm8rwrm8rgCGNTZVFItMW7Tt3izfNYp7jFTQwfiStjsTFYUAYylsRdOPqQLEJLVelxkKWHe973Tm5T367c9N3+8+8+EwiGuHI7fK.yvde0.9cqs5ing3xHrwqe424TkHbpCc7GBHixLSGX80WO9hewuHdrG6wTcVAIQzInyvkRdSjM8ctVBcdS1L3oAXzwF5bic61UqewMzykKGFd3gQas0lpxzCEJDRkJE5s2dwEu3EUQvmE+zen2f+cipL+xAYUlydIYlLYfEKVfa2tQjHQvBVvBPyM2Lt669twF1vFP80WOJu7xQznQgCGN.v3jgmQBjoAjofE.pJ0mQuhYM4p47+ZMlxafkjL0.kVZCjocga3IamCTmsjazQCyjUUHi.B.PjHQfKWtvq+5uNNxQNBN9wONN0oNENwINAFZngTQv5sxC32NFXMYxDvUx2IumI4ylc61gMa1vpV0pPyM2LppppvLlwLvRW5RQkUVIb61MppppJhmTRBwyE0b4xUQxz.+676V98q0HL92jQe7JgaaZI3tLpblLYBIRj.VrXAG9vGFejOxGACN3fp1pC8nliqtZG9OQGC4FKxJvDXb81RakaNEepnNzwaYvH0JMV5O9O9OF+i+i+in4laVYvCo2AcxketREAJYkHJkQA92XTvoi2RJGnU2kjsmKscjDiFGSniiEKFNyYNCN9wON5t6tQnPgvYO6YQ6s29j1JetZiP0enWSXx1egqWx6kL.Cye9yGKcoKE2zMcS3du26EM0TSvqWuHd73HQhDn5pqFIRjP4frzAZo7+HeN.L95lbbw06znXJuAVuahRUUY7A9vCOL5ryNw4O+4Ujnb26d2vlMaHTnPEo4GTz7BDHfpwlpk6O.iaPhjb1bPGvXgmMd73JCQ3BCbADJJmIRjPYDIv3QjiMQU2tcq3V1pW8pwF1vFTs9kEsnEoT8VYU.ROAudARiWkOG+Begu.9u9u9uP3vggGOdTF0jMaVUetTNQmbvnPgBEwcJcniaDg1BAoTyGj7yjQ22fACpnJ41sajLYRXznQ79deuO7E+heQrhUrBDNbXU5ilJEIBsNvw0LnQFjGWgBEB81auHSlLnkVZA+te2uCm3DmPstdrXwTFHxLrHIWOoL.WOhFURQxj6Sv6oQiFUIDqIRjPwyTlttRwIU1d4HMMjQbmQmpT5WH2eg7M1rYyn5pqFqXEq.24cdmXcqacXVyZVvmOeE8cWJZbbiLzMv5+CxMkk2RHWs3DA9SN45.G3.XaaaaJoffcM9PgBoTmdFsDl2YZHFOVxR8WqwX.EKgBxySYza3w2mOenpppBUTQEvoSm39tu6CyadyCMzPCppBjpjN0nFltPd7jFzc8xDEsFXw+cGczA9a9a9avu6286T8tRqVshxKubkFVwnlIijlACFToWVG53FULYovl5nGm2H07trYyhZpoFzSO8.GNbf+7+7+b7w+3ebL6YOa05OZ2Xdp.jWmRwIVRkAVs4RithGON.FyA2VZoEbnCcHryctSLxHifHQhfAFX.DKVL05LzoXFcMB1aTkbWUxWTmNcpxdPxjIKpJG0t+fMa1TZAF+aLyM7XPizjYBvrYyvpUqvsa2Xkqbk3tu66Fqe8qGyd1yVYTkbOK98oafUwP2.q+OnMxGDzyKBN3jFBwdhX974wd26dwq9puJNvAN.N3AOnpDWkdmLxHinhvD8rS98xHnXylMX0pUze+8q7.gSvrXwhh7mr230XiMh5pqNDLXPrrksLLiYLCkdK4wiGUXWkosibVStHhL8c7745An03X4hLG7fGDO4S9jXaaaapExn5RSAxi2So2jbgnRoAN5PG5XbPZBvM6c5zoRBCRjHAJu7xwce22M9ze5OMV6ZWK.fp+fBLwRvy0JHmuKMfPRwAszXHc5zpt+A6JHCN3fp9gWO8zCN5QOJN6YOKFXfAvEtvEv4O+4wwO9wQ1rYUYKfxV.qPOFEIZzJPooEgVdexyUZfkrRvofeN3fCpNdz3Le97gfAChEsnEg5qud7Q+neTTQEUTjZ6SsshFBxiQo94M5P2.KLwFWAboFXPuJ3eikgOK+TJ8.6YO6As0VankVZAG8nGEG8nGUQNPJPobfJPw7xQph7.iEBd1Mvqt5pwRW5RwRVxRPM0TCl6bmKpu95QEUTgJrtLRYISlDNc5DiLxHHYxjvrYypIWwiGGiN5nvqWuEImAxIMZIl9TYLQowfg.ee6ae3YdlmAO6y9rHTnPn7xKGiN5npzqJMnTaj7zdL0gNzwXPVnHRoGgQkYNyYN3C8g9P3gdnGBMzPCpx42jISJBiOU2.KZPkThd.FWlW3Zljn7zXFx0WVPT7dhACFPjHQPO8zCZqs1PpToPznQw92+9wK+xuLFZngTcXDoDvv0k38YZTKi.O4brrZoMXvf59c1rYUomjbTiFDSo14Nti6.24cdmXtyctJITfGelUCY6jSt+n7Y3TommWKwM7FXUpHeHGbPux3BCxvvR0okKRH8hgdEDMZTDNbXzRKsfsrksfctychyblyfXwho5QhLhVDd85E0TSMvlMaHXvfXwKdwXYKaYXlyblHPf.pz+QRGRoIPlOdNAi4OmoPjKrwdwnrJ8jgq+5wIHkZnLixnc61wINwIvO+m+ywy9rOKNwINgpbvYjp3hOxxQVqtgoCcbiLzttfa2tUbMhQjOWtbngFZ.qcsqEO7C+vXYKaYnwFaD.iEoGp6ULxMS0VuQaJB0tlHiTjrRBoiy.PkkBlZOIXJTIWrHepnwaCO7vHa1rn6t6FG3.G.acqaEQiFECO7vX3gGF80WepHZISQoLccRtTUnvXscFl9xxJqL02U0UWMlwLlA17l2LdfG3APvfAU6kHAuNY+2kQSKSlLJiGkXpzyxq03FdCrHzl6Z4OkUshbRljXz.i2ikjozKUpTvsa2JIgHZzn3zm9zXKaYKXW6ZW3Tm5THe97nxJqD0VasnlZpAqXEq.qcsqE0TSMHSlLvue+pIpzXLZXf1AyzKIoP7weO8FiQZiBHXgHjC..f.PRDEDUmWohRm75+5Inc3L0xFF19QGcT7q9U+J7+6+2+ObwKdQUX3YUlJqTRsoUUephNtQCWIQkfq2QIQXMqYM3ge3GFadyaFM2byEIyBzwS45nSkMvRtG.PooLA2GPakKxOOIstjaULpXjeT7dXznQUU3MQznQQO8zC5niNvQNxQv4N24Pe80GN9wON5qu9PpToTNVK+9IORI2SymOOZpolPvfAwl1zlvG9C+gQ0UWcQxcA.JpsEw.FnsoKmKWNjMaVkLLn89kNFC5FXIf1nWo8uUJgjj29jJRLQ5zoUabmNcZjISFUTiFczQQxjIwt10tfKWtv7l27PM0TiRQaYeYBX7M6kkQLIboVwUkdxHasOjaQ.PMwkU3So7.oTKvb8JxjICFbvAUMcYJbr6ZW6B+jexOA6ae6C82e+JEIlj+TlxToAV5SWzwMRPRQfRwuFYDxqpppv8bO2C9XerOFV4JWYQ7FR1lUXCAF35GCr3Z8xyUVowx1zkreKJq5aFkK94jE4jV5MHy9vniNpRHUYJ8XG1Xm6bm3we7GGCLv.JGu487BEJnJdojIShYLiYfG9geX7A9.e.DLXPUZCkRWQot9o7Gw.FPsrhUrtNt735m5v+cATpI4rGKIKAVoldHMJiC9YngMa1rZPIMZhGSJBpbBIC8pTYfGYjQfSmNKJ7rLRVREkmmWbALs4HmSrowE7ZgdMI46kz6xoCHUpTn95qGQiFsHcYYyady3ltoaB+hewu.+5e8uF6XG6PUAnjOC1rYSEZccniaDQohfk10G762O1vF1.9fevOHt0a8VQf.ATQphP1FqngCWOT.MYyl8RL.QBx0J.nLpQxWKspTtTms.FWFLXpFo3mVnPAE+YAFSPqo1Nx8UFZngfSmNuDdPIqHwQFYDTSM0fG8QeT7o+zeZTd4kqVai+c9hEukLRix1OmjetTvQ0FAKcTLl1GAKNfDX7I2RIHfg0FX7zuQqykpLLv3KRPhGROKjCNkgRlF3XvvXsrmt5pKL7vCigFZHbfCb.75u9qi8rm8fFarQrxUtRrl0rFrzktTLqYMKUZA4jEsQlRa+3RFgEIGAjS.zFAroSFRMQXxTpcSlLg23MdC7rO6yheyu42fybly.fwCSN8fTxwNskQsbAVfwEeT4hoRCzmlOkSGuKCsQUW96ki0nihrxXkjyV53nbMrQGcT3ymO0lv1saWQ74latYrl0rFEwnovDy0Wki0mNUB+x6oZWeQF8J4ZFx1qC2WfsnLYO9i223yDt9cgBEP3vgwwN1wvV1xVvV25VQas0FRjHgxAb4dA73awhEDOdbL6YOa7o9TeJr5UuZzbyMCGNbfxJqLEI7Y+.zue+He97HUpTvkKWEUQ0xBXfiengjxwNbuPxyW4dnZW6ahLb85YZpHwzNCrz9fgjTmbiRaqMQ10uo2.bPO+L.PQfbY6X.n3PnynCY1rYLzPCg1ZqM7Zu1qgb4xgKdwKhicrig1ZqMU+tB.JxdxTLVe80iksrkgUu5Ui4Lm4fMsoMoztJ42ibQRBNwVdNwIH.iWoh.iS9assWnoanT8dQIhEKFJqrxPtb4TjJ8fG7fn0VaEczQG..E0Ktj8HQo7VHwjU4g5UlnNdmBkRe7jnrxJSQOA99kF+KgVgljsRK1O5rYyFVvBV.V3BWHt4a9lUaV62ueX2tc05lRC2jNANUKUfucwDUkgRHifEeexNdAMJhFAATr1ZQigGbvAwwN1wv1291UUl9fCNnR5enAyLUq77iO+Ju7xQrXwP73wgSmNgKWtvJW4JUTRYVyZVXCaXCXFyXFJizj7qRaZQ0ZLu72mOedjLYRkFmwqao7VHcxTKe7J083q2GuLsw.KsUCn7AuLm2DRigHejjBAJk6fHQh.SlLA2tceIQ7JZznvhEKJgG8fG7fXe6ae3BW3Bn2d6Ec0UW3bm6b.X7HFwR40hEKviGOHb3vWRXkYY95vgCLyYNSLm4LGbK2xsfUtxUh4Lm4f.ABTz.XsdHvx6kdex2GESNZ330Cgn+pEkZiDI3FNbLfKWtP73wwK8RuDd9m+4wANvAvvCOrRVK3hY.iEoSsk8rLcszyOsF4oUP.0gNd6BFEAsiy0tYqLJ9zf.YD24eSFQFV4zrZy1vF1.dvG7AwhVzhTQukBUorp4XknIitKOmtdeCSfIlD7RCN3+WaqdiTAgfofj+8b4xgN6rS769c+NrsssMzau8h95qOzSO8n56szQOJiBkRRYXTD4yHpKYwiGGd73AEJTPEYqpqtZTd4ki4Mu4g69tuarrksL3xkKEGt3wjN0y0ujseHl0Gd8ZznQ00FcxmY7Qte7DYHktAVSgfbyJsOXjkZO2DT96iDIBJqrxTDOWVkd.iKTaVsZEoSmFm+7mGCO7vHVrXnyN6DO6y9rn2d6EgCGFoRkBwiGWI7n.P0elxmOuR7Pk5QhWudA.Tk8prawyIEzfnxJqLzbyMiUtxUh0st0gfAChErfETz8AdcROGomNxIwxzIdifQVWNvFDM.JphdxjICBGNLLYxD1111Fdtm64vd1ydv.CLPQalQu70J7e7EMzRKI4mFLsSGSAfLUbbiMYTsXDsYUgQPRYKAiNuWudUcChku7kiMsoMg0st0o3VEi3Oa96zQUY0TKqTNItdeCSfKMBVx407dAuNkNjSpkv6UzfrQFYDb9yed7Zu1qge+u+2iCe3Cid6sWjNcZX0pUUv.XwAHat0ZqXQ44mACFPf.AToQjF8vLYnMiLRxzSZqbO2y8.e97g5pqNTe80qxjhrqlHa50ryjPM.ysa2pqas50EEeadtJGanaf0TDH2vpTopQpXvbAF4+2gCGHa1rJuC750qxJ6HQhf1aucbxSdRU2T+fG7f3bm6bJsIwiGOHVrX..EogHbQMt.j1PyyAx7bhdkvIdLb6RB0yMwY9y83wCt+6+9QCMz.VzhVDl+7mOpolZT7Gho.joHPNIkoHrTUQ3MhfEHfLEpbwCWtbgLYxfCcnCgW8UeUr6cuazRKsfd5oGEOEX0Twm6zPYImLnQ8Z4pkNzwaWHMfQq7Gv0a33ZqVspZ6WrKFvOmMa1fe+9wbm6bw5W+5wse62NV3BWHpqt5TGOVvObSR1pUjaBxl0L2vVFYkoKPNmkY6Paqsg224ZGoSmFlLYBtb4B4ymGm+7mGs2d63Tm5TXe6ae30dsWCc0UW.X7nbQMKT1MI3ZIVsZEVsZEgCGF.3RLzh+a49STGGyjIiZ+j.ABfHQhnjiAa1rgnQip3+E2in4laFKaYKCyYNyA0We8HXvfXtyctnxJqrn6M7YuzveJNqzweog2STq1Q2.qoP3xEAKZfECYMiLD.TgLkCZiDIBNvAN.dsW60vEtvEfISlvINwIPmc1IRmNMrYyFRlLIFczQgSmNgMa1PjHQfa2tgSmNKpeTQgfiBvG4w.87fDn1ue+pHZoMbxxPoJK4WsbHytc6n5pqFyd1yFKcoKE2xsbKXEqXEXVyZVpPyRjMaV0hB5kZKJpwqx66T6rrZ0JFd3gKR.AymOO5u+9wq+5uN18t2M15V2JBGNLhFMpZQDY6NhM6asjPlO+lLNhoCcb4fLcexBbgi4HWbXzTYD5c4xE762OBDH.BFLHV8pWMV5RWJZt4lQUUUkJptL5DRGGkQHiNWv+FeuWtJu65cH2xTteSo3VTrXwTsKmN6rSrqcsKr8sucbnCcHzc2cib4xoLvgcqCl1O.n1qRF8GYjH42s1yE9+84ympChH6agtc6VMdfQsmeFowhtc6VwYXNVxoSmX1yd1Xdyad..XQKZQ387ddOX9ye9vgCGpTKxyUYwgIyZxHiLhx.8RUDDSGLNeZgAV.SLIO4fRZrCS8CSa2t10tvANvAvgNzgPznQwHiLhJEf.WZJ9XnU4.EFgHoPuwz9ENb3Rx2Fa1ro3NgzKR9Rlea1+njWmxqWFAE4wIPf.p1myccW2EBFLHV5RWJpqt5Tm+bR006Cfem.RtuwEJAJ1SPFVaFwurYyhAFX.zWe8gSdxShCbfCfVZoEblybFbwKdQ0BW74CWTja9vu2IiiX5PGWNPCYHepz1zkiGOtpIvyndOyYNSrt0sNrpUsJLyYNS3ymO3ymuhz7MFEVtljVodgQYoTUPKv3BQ4zwHjKWOlqKHSMnT2CiEKF15V2J9k+xeINzgNDFd3gUQCj6Yv0hYEoSis73wC5u+9K58nsHsn7MHyNhjec7842ueUeuk5yXpTofWudUGSxyTiFMBGNbnjhAYgSIKZJBWtbgJqrRTd4kiZpoFrpUsJba21sg4Lm4.SlLgJpnBk7S.LdwTPMejWe76X5zdRSqLvR9S9PZvAGDs2d6JIRn81aG6ZW6Bm3Dm.oRkRYQOWbR58EMNS9SF1aFlUJLkjT5ISlTMnzlMaJO.kDYmQBQFdeYJ.44uj+DxAmZaOBLjrjHhZ4ble+9UdotgMrAUeLjFLdiLRkJUII7OeFqUAl43EYn5YzGyjIC5niNv92+9w92+9wEtvEvIO4IUoSlFkSw.jKvpCc71Ex0p35DT8tc5zIV5RWJb61MVzhVDt0a8VwBVvBTUKMaSWTKmjoxgyGHWZ.fxYOsDclQ+foFSZvmVE.e5.JEI24ZugBEBm3Dm.uwa7F3Tm5T3W9K+kHQhDEI4OxnSQJpv8SHENXq6xmOeHUpTJGzzRLbtlhb+C48+xJqLDNbXEGisa2NhGOt560rYyJ5i3vgCkg0RCk43CFYeVcgIRjPcbjNKZ0pUUT61vF1.l27lGl6bmKBDH.lwLlAl6bmqR5O30g1WSWvUsAVzZZl1K4jSVxtj32VsZUkGX4FUZMdPdrmHtUQvnRQur5qu9v92+9wQNxQvfCNHN+4OON6YOKN6YOKRlLYQDAk43dxt9tVhIav1jYfj1v66ymOzbyMikrjkflZpI7POzCAud8hxJqLE2rjsKFNgVK+NXT7X4YSiMAFOsBR0ZV6w3x05IlJgI64u1JkhUMXznQQjHQva9luI5s2dQGczA5niNvYNyYvYO6YwPCMTQUcDvkxgFZDtz4AN9kapxE2.F2KPoAfZ83jiGtRibl1wWSTjhkGe4O09cq0QHYDPJ077IZt+DcNnshZYjmkQjg7CQtNjV8ihGGYU0c49tubbGQ96zlpX5YuL8R75lOGko.Td9vyea1rAOd7fJqrRLm4LGrrksLrvEtPTYkUhErfEnV2kQbpTmOSDtZW+4ZMjOmkQtGXbMrJSlLpThB.E2Y4uSZ3ozfQFIut5pKr+8uer28tWbjibDzd6si95qOUiX9xgq2oHvU50mACFPYkUFl4LmIVvBVfhuvadyaFUWc0vkKWpnqQ5YHmqvwpRQp0jISpnfw2C2SmbJipC.inprRF0N1tTFNe0hqZCrhFMpp533M.4B981auHPf.J99HGrJW7.X7vOyHCHI3sbwwb4xgnQih3wiiXwhg8rm8fctychN6rSDKVLDJTHze+8ijISpzADNYfUkAMPXxtQNU2.qqjOuzyI4B679whVzhvse62NV+5WOl+7mOprxJUg1mKLocS.IeAJTX71xf76QtYg1yoo5FVQbk77uTOiXqPhbcf++yctygCcnCgie7iiAFX.ze+8iHQhf95quhZ4E79Iu2yMak8MLxEPsQNf+esmeZMjnTm6Z8hbxDpUFUCo31NQFfvwgxTAHcvoT2GmnE83uWV12Sz2KWfkKLyyW5D.+bkxXK4eW9cveRmRjdve4tNjN3QmCkeFY5lHuYHXp9prxJQf.AfGOdvbm6bQs0VKZt4lwrl0rPs0VK762u57h2izJJw767pc8so5QaHYxjpMUAFe+Gdca0pUk1MALtZkyFXsSmNuj4CCN3fnmd5AgBEBO0S8THTnPnmd5ACLv.pnAQgflT2Xhv058WtZwj87mqOIcziR4gEKVPM0TC..BFLHduu22K13F2HBDHfZ8N+98WjiEZ4aHMjB.E0ty.FOclxFtsACiU0lbdEizlVmMJkiRust+7NUJBSmNcQdNKIC4HiLhJcbZSUFvXODXkuwMQ.FukxL7vCiAGbPL3fCht6tabzidTr6cuazZqsB2tcivgCqpBPY29VVMW.iO4QxgpIyS9q0S.dmz.PsCNAFiOXbCYGNbfYLiYfa9luYr10tVDLXPbK2xs.61sq7lqPgBE8rjEPfT6m.FmWStb4pnnTHSe4TcueAtxMvh2S0FAEfw6WaDRgeLYxjXfAF.m8rmEm5TmBm8rmEW7hWDgCGFoSmFQhDQEMLltRYjFMXvPIK+domwxVbA2bgd.JMNgFXHMjP5w9kyPiIJL+kJMnkxfaIAo0dr46oTmGSTpE36gNlwz+KilESuq1yCIlnHLvuOsJVtViH4mWa5kkbjRpeZFLX.Nc5DUTQEvmOen5pqF1saGABD.M0TSpzsTe80COd7nxL.iN0jsdgjmN2n.ltMZ3pTRI.Fu5xYzPX6Iiu+LYxfHQhft6tazRKsnJvkSe5SWDuoHjy2zRH8aDg14Ux4KbeeRwlrYyBOd7f67NuSb+2+8iLYxf4Lm4f4Mu4A+98WzwUVkhLxWLiJ4ymW8bDX7mCLPOxf0HW+gXJiAVrp4jxLfzCAZHEy4eg+OtsvnTwHKALdUoDJTH7lu4ah27MeSjHQBb1ydVbricLzQGcnRymzqYa1rAmNchQGczh5r3bwJ4D.oWlZWfc5HnwlZkGBlp.ldUIGiH+wrZ0JV0pVEBFLHV25VGV9xWNps1ZUQuh7yfFYwBIPp14LMwxMyAFeCmoKbzPF8FtwaoR2mLErRkgGX7H0lJUJEuMZs0VQu81KNyYNC5niNP+82OBEJDFZngPrXwTs3Bd7Iu5zFQGZzkbr.OG.l39LWob.QZLiLcVZeALtdxUp+16jP64j1qCtPJWygqaHifjVC0lnEWk+d4B2xVGBuuIG+yiMqDKa1rgZpoF30qWDHP.TUUUgpqtZzPCMfYNyYhJqrRTQEUnD8X9c.LtvAKGmo8YKMnDn36+RiYmtCNtWF0bYD1CGNrhP4b9qISlPrXwP1rYUFRs28tWbvCdPzQGcTjQpLxfZO9xT2qiwqBR47..nhjjzHLY..La1LV3BWHVxRVBlwLlApqt5vBVvBvBVvBPM0TSQN0xOelLYT8IQNOmiCnCQZ2qhmCuSiqZCrz1B.XzMnlqHC6tLBVoSmV07c6t6tw92+9w9129PGczAhFMJ5omdvEtvE..tjTd.L9B6xTlvKEFRXV8fxvtSOEkFANcGxMNlnzDIazmZMPljVr5pqFM0TSXEqXEXiabiXwKdwpP7BL1jEFY.1Ho4l.7XIGTqkn+SGf1HYwT9oMMMDLEBbAZYkLxw2TdO3bFRZ9DIRfScpSo5ukQhDACN3f3hW7h3hW7hpphUtghLBxZSmubgO4yeB92ko3hWeSTDrjBmKPwUKqACFJRnFKUzvjDtU64F2LTqgrxzSSNeR4Df+afh68axBIQd8pMxTxmw.iUAUzYDdNX1rY31sa3xkKr3EuX3xkKTVYkod42ue32ue31sakDu30qW31s6Koxd054urp0LZznpu.xlKeoFOp8Z5FIHaoLLRGj31ZEXXJyNjb56d26Fm+7munNigb7Kv3R2h16yZIz9MpfQTehnN..tD4ofjpmB1MixU97i0oMZrwFQc0UGra2NZt4lw8du2KV4JWoZeF2tcqlmmLYRTVYkg74GuM9Ho0Po3786jNeLoFXckXDBKKUNvkVLN7vCqjo+HQhfKbgKnJY823MdCrksrEbjibDUjPhDIhRnxzlliRIy9jjaxPuyPkKKCVBIA705s2zYHWPPt3rjDzZipA85lU2hzqMWtbgpppJDHP.UUhrhUrBDLXP31sa.L1hVoRkBkUVYpiKWLhahvykq2g1qiREdYsF5PiojQjfFloM8EZK9C53.OVxicxjIwfCNHFXfAP73wQe80GRjHgxfrjISp9+wiGWEgSJ0G78vHASmaXzHKUa+4xgIxn9ICbQtqjOmz4AoyTbQaZTIEtWIWP33a9LgK.KiVDSENqvK4boFarQLm4LGby27MifACB+98WTDDovEKSCHetwTZnEzwDYe8S9Y054szvR43HxCnRMdrTavLcEjCPzfahjISh3wiiKdwKhSbhSfW9keYryctSzSO8fzoSCmNcpL9RF8EIuTYamg22kFRncOrajgV9VCL18GJiMzXJowMbtOc9WRsGN9MPf.p0vprxJwccW2Etm64dPCMz...ps1ZUxlDm+SCe0lAkRQIgIy9mIa+qqZCrn.bxzavPRe9yedzRKsfN5nCL5nihSdxShssssg1aucEA1iEKVQ5oB4bE2fmKJJCAtLRU.EmhC4.ZFUFYZYjFIvEImLR7d8Nra29D5gtjGNxHYHIgrjaH.i+LfedpFvLO4ACFDKbgKDKaYKCM1Xin2d6EkUVYpMRXnY4ykq2Wfmi64l5.iy6FiFMp5WkkJBCZkpAI+EKEOmjFGWJNUIiZDc3wiGOJ0kleG7bloijueFcrXwhoZuFgBERcdRmi3boBEJTzmmFukLYR02ehDITed9R940Jjk75VRreddWJOKkUtLu2X0pUUJ3t4a9lQc0UGb4xkxfEtfM4iIMzkUamSmNUjvsxJqrnTzw0t34SM0Ti5+y4YLUjxHvc4FmmOed0FL7bQVvBx4jx4xkhSW.iaLOSQnL00xiCiNvzYv6CRGDBEJDN5QOJN1wNFN7gOLZs0Vw4O+4QxjIgYylgGOdPhDIT6Ew64.EOGkQPD3RWKU2vpwgbbGPwbvhfBesACFJhb5RhqSGA4eytc6HZznE4rJ6j.1rYCMzPC3Vu0aE0TSMn4laFACFDM1XivkKWvpUqp13i1nRBTbzrlrqsK6e+p0.KVEgW3BW.aaaaCG7fGTUQT81aunyN67RB8u7XpMUcZ8zSRhTom+RiBjKpQu+3lNZkNBoGwuc7r95UncPjzqWBs5qEv3b3RlNVYZSzRRXp6VzXq+j+j+DzTSMgYMqYAmNcVjwZ7Yz06P6lURiCztwHv37QXxPoRal7XM5niVTQJHeOZ+NzNOlG6I59u1qIsyU32ECqO8BkD3WFUMsFXISKnLsK.iGsAFAZOd7TTpI0ZjkLcr.nHCrb3vALXv.Zt4lga2tK59O+tKEGwztnYoLrSqwuZedVp6e7XISYhbbh76P5gsLpWxmWxphjWa79s1F0qLpY2HAx22d5oGr6cuarqcsKb7iebblybFzUWco3gmrG6wHT41saEGimnm+bMMoy+zYKlgkajQo3CJv3yoj7VjueF0Upz6j1Q.WZQ7vf6HaCd74gLB0..M1XiX1yd1n1ZqEye9yGKaYKCabiaT4.kzYCo8GWNbEYfkTjy.fh3yrwDyK5vgCiye9yirYyh95qOru8sOrksrEjHQBDNbXDIRDkZwBL4kPsNt9GxAXkhiLUUUUvqWuXYKaYXyadyXkqbkn5pqFd85Ed73Q0OGYzJYJDAFKD9bfOi5hLZMTHCkFXHi9FvMVUK00iPttPo92xmeSGRmrNJFrYqOzPCoLzzqWuEI+OzHk++s2W1yQ44Y1e58t+5VpkZg1.AxHwRDBAxrIKK.yhWIIkisG6Xm3obRpjJ2LWM0Tysyu+HxbyL0bwjpl3jLNwiIdCLX.g.KAHLqVf.s.HPBsfTuupt+cgx4UOcSKIrw1HjdOUQgTKot+j5uu2uy6447bdHIHplJUnSFACbsAFcBm+7mGs1Zq3XG6XXngFBSN4jpbRha.WiE9PxEgMbmSmNgggApt5pwN1wNvt28twS7DOgRcKe97o1.HUqWdtHIWyQQD8JlzVGllXhIx3wimrjBMc5zpxEbwKdQL7vCqNY8K9hu.ABD.VsZESLwDpgWYtllE396vHMVXhYxTfzCJTtcWtbAe97gZqsVzTSMgFarQTas0hxKubTVYkoTfj+rROnvcgmqI4u28tG750aVyWRYIH0DrleiYhfE+bMAqE1fDdhEKF74yG.fxKfKYIKQUVOoIyYyI.LkGEc4xkxxI23F2.m4LmAG5PGBm9zmF26d2C986W0s5roQ3lyzSSgE9He94jdzjk4MSlLp6OshUrBUX8xf4d0qd0njRJIqJgEJTHkg4kYQHsQfISllRAqToRgAGbPbkqbEbsqcMLv.Cfae6aiQFYDb5SeZL1XioTzh0bl06T9KAk4VJA9LIQnFKbfjfU97HC6pPZBa.n75vxV1xv5W+5wN1wNPiM1HV5RWJ750qxbvrKDkFKVVRphKtXUc2AldNOBLcKxqw7WjORURjOER0XgCBDHfxmfzCekWd4vhEKHTnPHSloFLwx6qHIWkJUJ7Ue0WgicrioxFQ1AsRPO0QBc74YgtGbWrCx+.X1WaQ1oo7yc5zI750Kpt5pQ0UWMpnhJvZVyZTQWD80IydqjISpTYkwnio29se6LiM1XXjQFA986GiO93pw3gEKVfGOdfe+9AvTs+nriIRjHQVSg6bUqh0iVSvZgOxW44.fZDHP+2.jsWuHAJCCCTbwEiktzkh0u90icsqcgMsoMgksrkkUv.RR6j3TvfAUMWASe9fACpVXdtTv5AwHiZ7cOlIkrzDrVXC1bDNb3.tc6V4YJVtERBhcWtUqVwPCMD9hu3KvYNyYvm7IehxdJxPcU5kG5oJYynPEMVnmChK1gTfmb6DTF6C.SGFsxycLYxjpKRAfxb8UUUUnhJp.FFF3ke4WV0HMNc5DEVXgJ6p3wiGXxqWuYnQUogyj2HDX51Tl0gjuPVrXQ84RChJ+mzLmZrvEx2ykP1UmL.SsYylJFGjllmeL6dqxKubrm8rGrxUtRzXiMpZCd5+J.n7IHUqRlGQOHlne11UiFe+h7QxRSv5wSju2+lIDLXPUDYvaNwQXiggAlXhIPe80G5ryNwwN1wPGczAtyctiR8ffAClUWPK8.LeLYDWPqHj6b5TiEdfVEgeL6fXYiBw6MIajNYHYCLcSCwxARBqlL+...H.jDQAQ0GiMZjMa1Pc0UGdwW7EQs0VKb3vwT2qB.YxMRDXK0GKVLUvewR7vK.loblJWeWoKQ3hCLSkHjpdlLYxr5nFFgFlMaNqttSFCDziDbD9Tas0h5pqNroMsIrsssMrl0rFDJTH3wiGjNcZDHP.XxjITPAEnlr8xfP8A42A8MwezhYacB86My+wbUx2bwctycfWudUQi.23te+9wku7kwQNxQvEtvEvYO6YwfCNnJgzkalRVxOVlG4lq3yIMGuriaWrzE4KVQtoPPtYJGMxtb7kI6VWGNbj0ngS1Aitb4RYvcdOKNoHLLLvJVwJfIKVrjg6bPlvwLWpb4xkp0oAlNuJ3MB4DJO21HW1EPZBVKNPtcQnD4lZ1TFV4vPMesQtSmNUD8Al57OZDwJpnBryctSrksrE7jO4ShBKrPEoe4vG+A83VSvZ9Alo0Jzu2L+F4SAx4ZceFlwISlDCO7vXngFBe7G+wpo5w.CLfxT5r7d.4er.MaSpibuOD6jLNCa0XgIx888Y6dT4JPDuejLhH38THI87QPmO2VsZElrZ0ZFpbEMnE2QfCGNPxjIUyZN9CFOdbL4jSBWtboFxy46fkGbZBVKdggggJs8oLq4NVi.xdASdQAUOUlqY.SO.gYKcmLYRr7kub77O+yicu6ciUspUoFVtxIod9P9HWouQ9iVnIX83IxGop4Rgn1ZqML5nihN5nC7+8+8+gIlXBbu6cO0OKKWH.TJLvMOICoV50pbgSmNUdqgd4LeSj.MVXh7keYRAgXRxyy0xsBJrLgxbLTFnu70fhG..UWsFJTnoJQ32S+tpgFeiQtDf3Gy1sFXptJxlManlZpAO0S8TX8qe8XyadyXUqZUnpppB.HqgKN6DQVCc4yMKqorINjRMSHyfmYxn+Znw7UH8tD+bVtdFjvxvbTFWJxw7i7FQwhES4yIV1edcke+9QWc0ENyYNC5omdv92+9w3iO9Tcbkool9F7ZOfryAsGTUwzPi4KPSvRiGKvLozTtw2fTNWKVrfJqrRTSM0fsrksflZpITe80iJqrRUJeKiwAVqcNZa.xdb1Pkb4iaxjorF0JRRUR03zPi4qfmGmKQFpxi7bZp1LvzgQM+YIALfo8NY73wgggAFarwvUu5UwW7EeAN5QOJN24NGFarwT98kiUIoR.4NYB3wk7+0Pi46PSvRiGKvL4Spb6ZHt.M2sMMOa5zoQwEWLV9xWNZngFvt28tQSM0D73wi5eRUrjo9q70mo4qMa1TC1ZB4rnSNa.0Pi4KHecMqr7Z4qqa43MRV5dpfUvfAgYylUQr.vTDr5qu9v8t28vu+2+6wUtxUvEu3EwniNppaAkyUNRRS5QSdMT9BBTMAKMdbAZBVZ7XAlI+Qk67SjkuvgCGvgCGXhIl..SG0Hzv7tb4BUTQEXiabiX0qd0XaaaaXiabinpppR4EQfoVLOVrXpwefa2tUGCQhDQMfR4t9IoLMAKMlugYiXhz3t4NyQYiLIUrB.pxGRRVW9xWFc2c2n6t6F+k+xeA81aunfBJ.ABDPQ9RNTj40r7w3wgTUMoWozDqz3wMnIXowiEHejUXWbvRzIGZn.Pk6VLmr3OS91EuWudUoJeKszB14N2Ipqt5P5zoUdMIb3vHd73pXKgcQqbzHH6DkDIRjUYUzPiGUXlBxU5aQYo4.ltz3rky44wbSElMaF986Gm5TmBs0Van6t6FczQGX3gGFVrXQkP6Liq30PrL7byJz6U5FgRiEhPSvRiGKvLoFjLNPjI9N2IL6dHZbVVZClTzT4I1oh.S04i974CEWbwn4laFM2byXG6XGnpppJq3eHVrXvvvPcrwmCFlcb24ZnwiZjq+k3+SxNbyILHNkHRjHpYsVnPgvfCNHN5QOJ9fO3CPnPgvMtwMTQ4CU.Kb3vnnhJBSN4jHZznpgqrzD670N2N.TNpqzPiGmglfkFyqwrkaI.P0lsxVlM27IwkKWvoSmHQhDHRjHY8bwLfid.gDtHgMRHqxJqDaXCa.M2byXqacqX0qd0vmOeXrwFCETPApDkmco3bEODZnw2mPRrR9wbyGwiGGoRkB1rYCNb3.oRkBgBEBVsZE23F2.82e+n81aGe3G9gnmd5A.Pc9NCgQWtbo57PYnBCLcJZCfrTcNVrXY4sKYimPRcyDxmZzZnw7InIXow7ZLWDr.lNy0jorKUyhAlqLCSxMPBk+LxvI0lMaYMby4zLnfBJ.adyaFM0TS3IexmD0VasnlZpAFFFpafwmacIB0X9.xkfE+bpxJ2XhYylQznQQ+82O5s2dwQNxQvm+4eN5t6tUyDPYHcxMSHivgzoSqdLCCCUtIluqSAl95N5gwGzvoVSvRi46PSvRiE03gsDdqXEq.974S0YhacqaEUUUUvvvPEpgxgNKCZUFjur8zAt+XmfcuE8HCAuAE8GiFKNfLFR3lGHgGYydPvMKH671bIXY0pUjLYR32uezau8hN5nCb7iebzUWcgwGebLzPCMqGSyUPhpI.owhYnIXowhZ7v1oe7FH1saGFFFvqWuXsqcsXW6ZWnolZBUUUUXoKcovvvPMP0MYxDhEKFhEKlxmJrLKrLl1saWMo2AfZHrKK0hFK7AKWct4oFIYyxoIGOYRh5zegrYMHQ8.ABfIlXBb8qecb5SeZb3CeXb4KeYbu6cOEwd9b8v.MAKMVLCMAKMz3g.VrXIqAOanPgTY6iWudQc0UG1vF1.17l2Lpu95wpW8pQIkTRVs5N8BCMdOCwQmNchgGdX31sa3vgCU1AwDulyLTMV3BYSXHCeSpHprrzxRvkLYRjJUJ3vgCEIrDIRfd5oGb5SeZzd6sid5oGzd6siPgBk0X9fmGxtHb1vbQ.SSvRiEyPSvRCMdHfa2tUFmmISsrbd7FUVsZEUUUUXMqYMXMqYMXqacqnolZBUVYkpx7EIRD..kZW986GFFF22HIQNeOkeMMVXBRxRZNbIwFp.JKaH.Tgs6jSNIFXfAPmc1IN9wON5niNPO8zCBDH..l5bM97kHQBkmCMa1Lb4xkdXHqgFODPSvRCMdHAa+bKVrnTYhJB3vgCUHKRktRlLI73wCVwJVAppppvt28twd1ydvxV1xfCGNfa2tyZD9DOdbDMZTjISFUGQBLkhD5tUbgMnG8jpVkaDjH630nQihgFZHzWe8ggFZH769c+Nbu6cOb26d2oF9r+8gmrrTgxyeousnBXZngFeyglfkFZ7P.YpWyaHwQGhKWtPf.Afa2tQpToP3vgypKCA.JrvBQ73wgGOdPCMz.1wN1A1111FVyZVCJqrxP5zogGOdTDoXohX4fz4r0BaPhTD4Ny.sXwB762O5u+9wUu5UwEu3EQmc1IN24NGFbvAgKWtTkXT9bPRaEWbwHQhDHVrXYk154lMUZngFe8glfkFZ7P.GNbj0Mi3M.kw+fGOdPpToPrXwfISlfKWtTA6HIkQ+TQ0s1vF1.dxm7IwN1wNPM0TCV0pVEJnfBTJKP0vziimEGfjpA.hEKFFe7wge+9w69tuKFXfAvW8UeEt90uNFarwTDurYyFhEKFb5zIb4xkJuqRjHgpYIhDIRVyGPpXV9hSAMzPiudPSvRCMdHAUDH2r8giCjzoSivgCqBxQR9hpRIyOH5iFpHlggAV9xWN13F2HZpolvV25VwZW6ZQwEWbd6tLMV3ApvTnPgv.CL.N0oNENzgNjRkpbCjSYNR41sakY0oQ3Io7zoSqH1SxU.Pk15LWpzPCM9lAMAKMzXdLjlVF.n3hKFaXCa.6bm6DaXCa.qe8qGkWd4YE2Cj3lziVx4LmblIJyIIoZXxb6hF3mecdy3zoSm0fwdwFnBOLtDHQE5eNlN5ToQVdW1An.S89RrXwTpHwNEjpYN3fCht6tazVasgSbhSft5pKL5nipTZRWFOMzX9KzDrzPi4wPZfYYIEMLLfggAJojRvF23FwN24Nwl1zlvJW4JQIkTBrXwBRlLIhEKlZ7mP+ZQiRmISl6yj7ISlDwiGGVsZENc5bFKQjTIjEaH2v7T93gCGVMjwY5kSxszf4.SMziCDH.JrvBUooNiGg6d26hie7iiCe3CiKcoKggGdXL3fCp7QkzOdZElzPi4uPSvRCMlmCdyW4rRTZZYdiae97g0rl0fm9oeZrqcsKTWc0gkrjkj0Pvlk8go+MetLYxDb3vgREFYXUJAIbQBVOHiyj4y3qywe99dCDHfJtLHwG92sHQhnFMS.SonEirCoxeQiFE81au3XG6X3S+zOEW9xWFiM1XHPf.J0u36GRCpaxjILwDS7P+2.MzPiuaflfkFZLOFxwrCGDt7l1rs7kyvMfoHE31saTXgEh8su8gZpoFroMsITWc0gRKsTk5VISlTMfdIwMYBdaxjIEQLB4Lraw9rVjkNkJBlJUJjHQB3zoS0XPxpUqpRExLRKRjHnmd5A82e+nqt5Bs1Zq3rm8rHPf.Yk2ULw+YIEY4DIn5XZngFyOglfkFZLOF4aNxMSeeriFY61yL3xkKWn7xKG0TSMngFZ.M0TSnolZB0TSMHRjHJRRR+BA.bu6cO3wimrd8kDtz4v0T+MhYWFvTpVY1rY06EgCGV82zQFYDbtycNbricLbxSdRze+8C+98iPgBAfo51znQipTPrvBKTQDlkaj4UEI0w2q0PCMl+AMAKMzXdNnxUrjbT4DylMC61smkBVoSmVM9cXWLxvOkDnJojRPkUVIJojRvK7Bu.1111FZrwFyJ4tc4x08MyCkioG.nto+bcrOeFec8vT998Id73pYII6BzImbRbu6cODJTHzd6siO4S9Db5SeZb26dWDMZzrFj278NpJnKWtTJcQELkGmTQSs+qzPi42PSvRCMlGC61smULNvapR+3HSa6bisAYNFQkvxsjRtc6Ftc6F0VasX6ae6XO6YOngFZ.974S04atc6VQdik8xjISpAQ7rg46Ag5bkySxAnr7+I3Hlgof9XiMFtxUtBZqs1P6s2NN8oOsJDOkoitUqVgCGNTYRE.TpQYXX.SlLoH6RO1kISFjHQB..E4ZYIC0PCMleAMAKMzXdLrZ0ZVQrPtw1.MPsLwukeO4R3B.YYRZ9byxOYxjITVYkgVZoEr8sucr0stUTQEUn7tkzePOHJXkqJXy2vbMLimMBVjj4PCMDtxUtBN9wONNxQNBt90uNBDH.hEKVViJIa1rA61sqJsGUhTNrukpDlISFXylMjHQBEwJ61seecTpFZnw7SnHXk6NyzxOqgFKdfzqWxOtgFZ.kVZonwFaTk8VKYIK4953PfoG5v.P4UKY4uRkJkpiHAfZ9JZ2tcUDEv43nc61+ZSNSpvGKgpjjII03vgirFtwb1OxXOfjahGOtxr5L+prXwBBFLHt8suMt6cuK98+9eOtwMtAtxUtBFbvAyJrXoOozPCMVXBa1rkU7ov05TaDEZBVZnwhdjOxUTgFfoTEymOen5pqVEzoO4S9jnhJp.Nb3.tb4JqATMI3PeEw77B.pQFDMWOIVQygC.E4Gud8NqG2bcJYWTJ+Zjzkr7oRerYxjIUW9IixBlCXjvW3vgwst0svW9keop7e80WeJhXR0C4P+V2geZnwBaHaJnzoSmkh3VsZUSvRCMzH+Dr.ldj+PUchDIBRkJEb3vAJt3hwK9huHV4JWIdxm7IQ80WuhvEIwjatZIGAKrrjRxIxNVTlJ5yFjITe994SlLoRUIfoSXca1rggGdXrjkrD3zoyrRT8Xwhg6bm6fqd0qht5pKzVasgyd1yh6bm6fjISphJi3wimUx3mO+xogFZrvDx0Mkc4KsAfI.jIW+EH2UnFZnwBeLSl31lMaYEE.rzezOQiO93vhEKn3hKFUUUUn95qGM2bynkVZAqcsqElLYBNc5DoSmFQhDA1saWEsCgCGVkMT.SQThJFQEudPHXI6xN9w7ejfE6xORBRR3hJpYylMze+8iCcnCg1ZqMLzPCgyd1yhvgCqLStSmNUdkhwTAesnO3j4UVjHQdHemQCMzX9Fx0KlR0p47l8umcgllUErzjrzPiE9HewOfT5a.n7EEC7RRfQ1shlMaFEUTQn7xKGEWbw3EdgW.acqaEM1XinvBKT44JtKOFyDb15wgOLvrm6WxiQoGvHIGYdcI+8fO2SN4jHZznHXvfX3gGFm3Dm.G7fGDW4JWAwhECACFD26d2S86D+8Tp9FCrU4qQtoaud8SMzXgCxGwJpxO2HmEKVTS1AMAKMzPiYLupb3vgxr1RCayzEmc8lTAG97wzl2rYyn5pqF6bm6D6ZW6BqacqCkUVYvvvPQ1hDeXZxyRrw.7b1NtkJuKGVxlLYBiN5nviGOpxVlHQBL93iiqe8qi95qO7+7+7+f95qOL7vCq7bVnPgfISlPQEUjJpDxM6o3wrrKO4WW10mZngFKbPtVn..p0bb3vgR8Jl6flLYxzrVhPMAKMzXgKx8Z97AoA0YG0weVo+oXI3HgrzoSCOd7fXwhoHejISFTbwEicricfcsqcgctycBe97gxJqLEYJRjipbMafd7hklipVwDP2sa2XhIl.80We3ZW6Zn6t6FW3BW.c1Ymn2d6U8yvmCylMCWtbgLYxnJcn73glvOd73y5fvldwPWhPMzXgAxmOUc5zIhDIhp6i45ENb3.EVXgZBVZnwhYLWDrb4xkJfQY2.xHHHc5zvkKWpHXfDTHQKSlLgnQiB.n7SkrLalLYBKaYKCUTQEngFZ.M2byXKaYKn5pqV4aKmNcNqG+lMaVEfmVrXQkyTACFDgBEBs0Va3zm9zn0VaEW6ZWSMblYGKZ2tcDIRDUzP..U4OkDk.llzF+8wgCGHb3vvpUqptIhCOasBVZnwBKjaGVC.kMG35jQiFEkVZo3G8i9Q3G+i+wvjEKVxHIRwmDIIK4tWo4MUtjOGOGngFZr3Dx.LUF1oxXQfIdtrKCYHZ5wiGTbwEiUu5Ui8t28hctych0t10BCCCEQK5UKVBPl0VgCGFYxjAW4JWAW6ZWCevG7An0VaESN4jXjQFA.PQFjlSmg.Ztw1..dfiYA8ZeZnwi2vgCGvhEKJk1o+M4FK4GC.0F3HWHoc.V5RWJ1291Gdq25svl1zlfSmNgo+s+s+sLW3BW.m+7mGiN5nptigDq3tVyMMoc3vArZ0JBFL3ir+vngFZL+ARBV7yY42xMo4IAozoSqVfKd73JxVFFFvvv.M2byngFZ.ae6aG0We8XIKYIJUqRjHArZ0J5qu9TCP41ZqMDOdb079ijmjKXRUoXmARSpJKsoLOqlMRTZBVZnwiufDllox8yYxZrXwTqMQEsoOLKqrxv1111vK+xuL10t1EV5RWppQfrbvCdv+e+nezOBaZSaBIRj.CN3fpP+KYxjSwB6uuPoKWtTxnmHQh6aRtm6BrZngFKNP9ttmkCjofN+mzmV974C986GIRj.Nb3PMe9X4GGYjQPAET.ps1ZwJW4JgOe9TkjyrYyviGOvrYyHTnPXngFB8zSOXrwFSsaT4lBkJUQynyMOR0zno6IYr7slllTkFZrv.R+a5zoS0l8nUGhEKlRjI1gyzhCETPA30dsWC+S+S+S3e8e8eEadyaF1saGSLwDpFzwTlLYxHWn4pW8p3C+vOD+s+1eCW5RWBiO93pCF4hTlMaFFFFHTnP.396lG8hPZnwhGLSjPXo8HgF4BZrLhISlDNb3.ETPAvhEKnnhJB6bm6DO2y8bX6ae6nvBKTUdOZKApf9jSNoxH4Nb3.ACFDW+5WGG3.G.G4HGA8zSO3t28tpAxL2oJIRYylMjJUJUW+.Lsg84lLk+9nWaSCMVXAFZvLI1kMwiGOdT9pjqYURIkfm+4ed7pu5qhctycBCCCjISFDMZTXylMXXXfzoSiQGcTXJZznYngRCFLH73wCrXwB5t6twQO5QwG7Ae.t90uN5u+9QpTofa2tUx4mqBVD5EgzPiEeXlZgY.n7dkTsHR3opppB0Vasnt5pCszRKnkVZAkUVYHd73JkrjiUmbiBARVB.HRjHHYxjpNA7jm7jnyN6Dm9zmFW8pWE23F2.986Oq0mb5zILLLTymPYo.3ZbZBVZnwBOXxjIUXAyHmgpXwMd41sajHQB3xkKr28tW71u8aicsqcghKtX..kkp3l0hFMJrZ05TJXEOd7LoRkRMvUAlJgkMYxDLLLvDSLANyYNC9nO5ivQNxQPWc0k5.guvxLhQu.jFZr3D4Zxc9wrbaT4phJpHTQEU.e97gW7EeQrksrErksrETRIkjUnfFIRD3wiG.L0hXISlDlMaVYaAhvgCqJqG2rHGJyEVXgHQhDHXvf3V25V3JW4Jnqt5Bs2d6niN5.lLYBgCGVoTEKEfrqIIzYCnFZrvCzBTxx.R+f5zoSXylMzTSMge6u82hW7EeQ0ZFd85EVsZUs1F6TZ1HMSN4jvje+9yH28lbfqFMZTDMZT3ymO..zYmch268dO7oe5mhd6sW0r6RFDgxEezcXnFZrvF4FyCz.6rDab73TbwEiksrkg5pqtrFkNbAJ9ylLYRDOdb3vgC3wiGDIRD0heT0KfoxgpXwhA2tcqTrhOOjXFk0WVtOVpv.ABfacqao1zXmc1I5u+9UqA9f1kz502zPiGeAmjDVrXQ44pLYx.GNbfJpnBTe80ie4u7Wh8su8oLDO693wGeb3wiG3zoSkUErYylZSgISlbJOXEMZTL4jSplyVISlDSN4jpE1X23vcN1SO8f8u+8iCbfCfSbhSfImbRUVzHglfkFZrvFReYBLcBtyNyqgFZ.MzPCX26d2nolZBqXEqPQRRZ.d94jDkTAKZVdpnDyYK94QhDAtc6VIMeznQgWudQxjIUKZJyHKYWExQbwHiLBt3EuHN9wONN4IOI5pqtvXiM18slVtPu9lFZ73Kra2tpajc3vAhFMJ73wC1291Gd8W+0wK7Bu.LLL..TCsdJlDmxETYcRVi9R2kKWSQvZ1N.XLvK2oJak4zoSiCe3CiVasU7we7GiqbkqfToRopgIM9E83PrXwTr7X.+YylMUIFAldpTKCjPMzPiuYfk6B.Ykmc7qQHMgNvzDkRlLo56iJBwwNS73wUkji9VZYKaYn4laVQlZW6ZWvoSmp1cVZm.Yxq+nBbcLdrjLYRb6aeazUWcg96ueb9yedbzidTzc2cCfoITwRAPhctb4RUV.plFILRUyjglJSJdtaX4LMiDOycHxpgFZb+PNbk45LzKkbCbbMGtllLFpb3vARkJEb5zIZokVv67NuC16d2KJojRxxh.4CyUhI7MhfkrafXm67Ue0WgO8S+Tr+8uebtycNUxH61saUmHJ6nHooT4GKyhBF1WbgaMzPiu9vvvHqw5hL.PIjA.p7l7whEKujvngNsa2NBEJDpu95QKszB15V2JZngFPM0TC74yGrXwBBEJjZHQKCXz4Kw4hL6q3u67wSjHAhDIBFd3gwfCNHN24NGNvAN.9xu7KUQKgc61UkzjJjQU+kkK0tc6HZznpc2xlEJPf.YEXp4NVdziZGMzXlgggghPEy0NRogazgdpB.JulyHXId73vhEKn4laF+pe0uB6ae6C974CYxjQY98YCOzDrjR+yOWNXSAldmwwiGGCMzP3zm9zX+6e+n0VaECLv.pf8i6TqfBJ...ACFTsvaton7CZRJqgFZL6P5IJRjhk0mJtXwhEDMZTkeDb5zoRQGpjL8ofWudwZW6ZwZVyZvq+5uNpnhJPkUVohz.WOP1wfRyqyio4SH2A1LWOhySPRpbxImD2912FG5PGR4E0adyap9aYxjIUaNrfBJ.986WoXH+6JaNnIlXB0ik6PhU2vPZnwbiby2N4n8hUIqnhJBlLYRs4FtVnUqVUdr5Mey2Dd73AgCGV0HM74b1v2ZDrjet7eT9MNpJ73wCLYxDtwMtAt10tF9C+g+.N9wON5omdTx2EMZTk5Wr6f3erb3vgJLunuKzPCM9lCRVRdsFUSpfBJ.QhDIq7ghk0hp5jJUJTPAEfMtwMhcsqcglatYrt0sNTVYkorC.vzypOpXCvzJfCL8ly.lN1FdTC5+BoxdbsG4h1btJlJUJXXXnT46ZW6ZniN5.e4W9k3rm8rn6t6FABDPsaZZ.V9ZvcRy2OjKhSRrbMUs58ZnwrCYV1QUm3FU30trQa750KBGNLhDIhpTf6ae6CEVXgvgCGJOVQU6iGOtx+UeSw2HBV7+Y1QvCBlaDTFtLYxf.ABfKe4KiO9i+X79u+6iu5q9J..30qWEAM4HxPJStUqV0KxngFODfDcjiCBd8Ia2XfotVyoSmpNsqfBJ.kUVYX0qd0nkVZAO6y9rXUqZUJYyYprSEp.lVEH4GSBa4NiSAxetY88Mnux3wgTsMfoUbiJpy13ljIMLLTkw6t28tnmd5AW4JWAe9m+43K+xuDiN5npcN6vgCUPFxFHxtc6JxTxxCR+WoUwWCMlcvFggqkQqNX2tcDNbX3xkK0PmeKaYK3W7K9E34dtmCKcoKEd73AgBEBoSmV87DJTHUNV8vh4jfEwLkALxVZNYxjpIKM.TihhnQiBylMC+98iCbfCf28ceWzd6smUJwyjYlKvyGalByTMzPi4FTkX1EvbmZrygI4HmNchBJn.30qWrl0rF7RuzKgcu6cixJqLX2tcE4HVNK.nLuszb7xxQBL8vYNelY+AQB9uOPtVdP5KKtXM+aE6THl4VzeaFFFp0sra2Nt6cuKFXfAvku7kQGczA5niNP+82uJjSkibC97R0B4.nlSWCMzPiYFxIzfKWtfYylUi3FFBw0Vas3UdkWAu9q+5X0qd0JaK42ueTXgEpTnliLmImbR32ueUDU8MEOTDrLYxTVsVM+5LZ4keMGNb.SlLgjIShgGdXbxSdR74e9miCbfCfwGebDHP...kxWLzulKSdp8nfFKlwbQPgplPhBr7W.PMZZV9xWN15V2J18t2MZt4lwS7DOgxyjRieyqskWeWPAEj00+.PMs4IIjY53b9.AKZxU5yXMa2C...B.IQTPTYLBVNS1UyRErRmNMBEJDrXwhpKBc3vgZ9GJyAGV9hwGebzUWcgN5nCb9yedboKcIzc2cCa1rk0Ze1rYSoxEMu6CCzqOpwiyXtVen3hKFQhDQ0QtNc5Ts4QNCS+g+veHdkW4UvF1vFTpOyqe4+jVifCDdYC97M93+qCAqbIWw+WZDdt3ZtlcUtiV93ISlDm4LmAG5PGB6e+6GW8pWU4QDtP9b0F2ZOZowhYLWWeHaOYtAmhKtX7zO8Sictych0st0gevO3GfUtxUp1IHeN4hVzOCx40EWThj2jcBLKAl7XSFCK.Sudx7gXZfPFOBT0N+98Cud8Bfo96AKQJ2cbxjIQrXwPAET.RmNMhFMppi.o8GjA4L+66st0svYO6YQ+82OZqs1P6s2Nt28tmhLG8s0bs77b800Jfowiy3AY8AtYD1otSN4jXiabi3G9C+g3Mey2DqbkqTEZwTEd4yKutmJumISlrZ.nGF7.Sv5aJx2tT4BT7qkISFbm6bG7we7Gi28ceWbtycNDMZTUGGxEb3eH3ByzqBxa.HyeFud8plr022u34j.0ZnwiRj6FUnWfnwKIgD4L7Kc5zvsa2JuGH6FPR.fdhbIKYIX8qe8Xu6cuXO6YOn1ZqE1saOuJLMSerFe6Ct66qe8qiidzihidziht5pKLxHifHQhnVWicYHI4Q+xQBurjGLieHQMZ6BylMqLqerXwTjjmqfTMeP5YMMANMdXfzFPx073mmNcZ0jkgalStoQ.jU1w8DOwSfe7O9Gi27MeS7TO0Sg3wiqVyLW+U98AdjQvJWeOPozGXfAPmc1I9a+s+FN3AOHt6cuqpSk3N.kpgIMvlUqVUCq5HQhnd7YB5jlWiG0faRfmKJmom.SGAJxuFebYm5IGWU1rYCKcoKEUUUUXcqacnwFaDO0S8TnlZpQ0kuL2Xn+CjPSv56OvN6T1ogCLv.3HG4Hns1ZCQiFEG+3GGCMzPvoSmvtc6pRJxNtlm6v06LLLTYTFvzp.PBY.PcSGVwfuNPV8BMAKM91.biD.HqRyyx0wDEfp5ZwhEXXXffACBmNchpqtZr28tW7S+o+TzRKs..fgGdX30q2rl0fK3HXkOHuYAGkEzf7js5ctycP2c2MNxQNB9jO4SvoO8ogEKVPQEUDhEKlx2CrsvyssloD+ZSxqw7YPIoAxdXIyGSZFZYY3rYyFb5zIBFLnxjzEWbwn1ZqEM0TSXG6XG3G7C9ApNkg6LjFSWRNShYirkFe2BYBSS+sd6aeaLv.Cft6tabpScJbricLzau8BylMC2tciIlXhr1zIKARl+dRwCLcLcvmaprIIp8MA77TMAKMdXgLa9x0FRb8QVBOp3EqRU0UWMdoW5kva7FuAZngFTkvmA+KqtEC82EMDr3K6DSLAra2txXnwhESYvcJi80t10vG9geH9K+k+BtvEtfRxaY9Yk6TuWOlczX9.lqKn444yz4pxNIiWWHmKeKcoKE0We8XG6XGXqacqXsqcsn7xKW87xwZCkcWlwKgBEBEWbw48XUSr56GLwDS.WtbkEgWopTIRjP8d3XiMFlXhIvniNJNxQNBd+2+8wctycvsu8sAvzapjY6EOGfkKTNxjjd8Z1vLoxu1hEZ7sAXSzHO+DH608j4PGOea8qe8Xaaaa3cdm2AKe4KGKe4KWYQHNvlYtZJ235hBBV.YmP7r7FwiGGQhDANb3P0cRACFTor0DSLANxQNB9i+w+HZs0VwniN58cyC9bw1NezQGU85vWW8hBZ78EdPRBXdSU1Rwxv3Lb3vJ+0vEgJojRPiM1HZngFvy+7OOpolZP0UWsJj83OKvzxsyMcPCnSURx074OHGyZ7sKn56L2vjczHe+mDv3lJyjIChDIB5pqtvIO4IQGczAt90uN5s2dge+9AvzqGxc9awhEk5+zSVOnihmYhjkdsTMdXfrAYjdLk2WmkHjeukVZoXaaaa3sdq2Buxq7JYItB+9kkDTxyP9+eu862iJBVDLEoojd490RjHAJpnh..Pf.ATsRYGczA9rO6yve8u9WwniNJBGNLb5zopjirCDy8Ov.HKurngFeWh4ZjvPkDjcoG2IGk11pUqnzRKEM1XiXO6YOnkVZAqd0qFd85EIRjHqY7Y73wUOWLHQkkdO2A5btcoilb02uHPf.pIbAvz2jfuuSaNvTplJyKM3axjIQ3vgwsu8swEtvEvYO6YwIO4IQmc1Ib3vgpTf1rYCFFFpREK2b5rA8lR036RHajCpZKOuzvv.QiFEFFFXu6cu327a9MXu6cuvkKWHd73pICC+XZGB1Qu4KI1+9bMtG4Dr.v80Z3rEm4N5RjHAhGONb4xkxjagBEBQiFE80We3fG7f3u9W+q3q9puR4AA1R5rFr4pfkljkFeef4pMic5zYVsuOUxxmOeXIKYInt5pCszRKX26d2XEqXEpEOnJTLuphEKlJj7XGmkLYR3xkqrFcDTMLh7E8JZ78KRmNs58OphIAUXhDvHQKfolkqLqwHA5XwhgDIRfgGdXzWe8gCbfCfqcsqgKcoKggFZHkZobpaLWmeJIWoWuTiusAKEnzafbCFEUTQHSlL30dsWC+ze5OE0We8vvvP0YgbyB4lAez9D4Ka6H99ZstG4Dr3N14PeVlFxbgGYcZk61W9Gv96ue7oe5mh+5e8uhScpSojIm6BTRvJ2NXTCM9tBOn43lSmNQkUVIV8pWMZrwFQKszB1vF1.73wC750qxOM.SeyV5uF.jkucjIDd9FAL75H4MqAzDrdT.omSkcRJ.xJk74ZcrSAo2RX2CRxY.S6I0DIRn1gee80GNwINANwINA5pqtv.CL.762+b1Eg7XQqhkFeW.decd9K6z0JqrRTSM0f+k+k+EzPCMfpqtZ00C7ZBp.urqCyWSCQrnjf0CJxkTD+imLb.4334Tm5T3O+m+y3PG5Pvue+Y0dmLes33ufcbfTJ9Yx3cZr3.4dQIO2B.224fbzyvaTwEIxjIiRFaR1gywNdNkYylQEUTAZpolv1291QCMz.V0pVE74yWVmCxWK4BFOp7TfFyuvbs9jUqVyZLlALUGZ2Ymcht5pKzUWcgN6rSb0qdU.frHxKmor7wXb4.LU4aBGNrREBlMg7qWPAEf3wiqtgHuNfkEmetl71i2H2L6iVcPN9Zjc4OeempQwIffEKVvRVxRPKszBd8W+0w1291QokVZVq0kKooG0AU7bgG6HXQHIXwbjwlMavkKWHYxj3N24NXvAGDs1Zq3O+m+ynyN6DFFFvsa2HTnPp.Xj63W1gMbDUnSI9EeHeY1lDRkh3+n4xoz0ReUwR4kLYRU4dpolZvy9rOKZpolv5W+5QUUUEJojRTjp3hQrT4yFoJMAqE2XtVihj8yU0eNpi762OFczQwUu5UQGczAN9wONt3Eunx6dIRj39tApLFH3XPSpbJIOQxZxtVjaF1lMavpUqpNC6wjaCoQdfL9XH3ZjxMIB.UvgKatBmNcpltD+7e9OGO8S+zvqWuJ6SjKAK9w.ysGWeTiGaHXIugFP1rYoBBLx7oY4RlLIhGON762ON5QOJ9O+O+OQqs1ZVYHDAW3gDsrXwBb4xkJr9zXwAx8BXYDIHmKej.NWvf2nf9eR18dd85EUWc0XSaZSJSpu7kubEQdprPt2rT1jFy0wqFKNwbkCUT8dYNnA.EAGfoHaQ+bALkcKXPOGIRDzau8pHbwbET1UhxiAFxowiGWU5R4XShQLBgVAqG+Q9HXQR4raUYvFynSfmGjISF7zO8SqLuNEAwgCGX7wGGETPAOVuAyGaHXAb+pIPOaIaIS9OtXRAET.BGNrJN86niNv68duGZs0Vw.CL.La1LBGNrZmV7lZzrwjD1iQ+YRiugHeW.yN2J2LZg6JWNjQYyWjNcZrhUrBrsssMr5UuZrsssMrsssMTRIkntYDMadnPgTSuc4HOAXZ+ClKzFSWiGTjuyU330gVff2DSNPqSkJEBGNL762ON3AOHN6YOKtwMtAt3EuHt8susZc1BKrPksJlbxIUm+Si2GKVLEoLVRcVRQoW.0qu93M3lIkQj.vTqywY.nKWtTUbp7xKGM2by3EewWD6cu6EqZUqR8bwnDo3hKVsQU4qyiS3wJBV4CwiGWkDrxZ7SvcrwRLRyyetycNb3CeX7e7e7efIlXBDNbXEialIM.SqhfdQfE9HeRPyROyaLvNSU1Fw7yqrxJQyM2Ldpm5oPiM1HpolZP4kWtZX+xnCgO2QiFU0wq70RpPV95DF.MAKM95A1HQx36HeeOrCCkihLR7xrYyXngFBm+7mG81au3Tm5T3S9jOAoSmFiO93..pwtDqlPhDIPIkThZdKBLsZGbsV5QQ8ZqOdhbyBMd9kTnCFh3gCGFd73AadyaFu4a9l3ke4WFkVZoHPf.p6KGLXPTRIk.GNbfQFYDTZok9n5WsuUvi8DrHjgLlbhXyNthw9f7wBEJD762ONvAN.d228cwoN0oPjHQfKWtTFe2ue+yXrNnCZuEVPV1YdSHRJR5gDfoLtImMbuzK8RXO6YOXkqbkXEqXEnxJqToB.KaHvzkUT50J9476ksaurywxEZBVZ7fB1x6LdOnxUTogbyGMdNpCGNfCGNPvfAUVp.XpMEX0pUDHP.bsqcMbkqbEbzidTb1ydVLzPCoHaw7Hjvtc6JuJxNgTu40G+QtdrJ2t3ij1A.pqt5vu9W+qwO+m+yQokVJRjHAlXhIPYkUlJ2pb61MRmNMBGNLLLLl2ah84By6IXMS2LgO9LciHRvhc0kT0fLYx.2tcqFJz1rYCiLxH3HG4H38du2Cm3Dm.iN5npcyMSw5flf0BKjKAKSlLkkr1VrXAkTRIX0qd0n95qGqXEqPQrxmOepNgAXp7KJTnPnnhJJq4DGk7lkXjK.IGTy7i4nOgHemqoIXowrgPgBoH2HAKmiriVkJ+SOx3vgC0ZlRUbkpqFJTHUpxevCdPbgKbAbiabCb8qecU32x7IjkRDXJRXgCGVSv5wXHGoMx6GZ2tcXXX.+98i0st0gW4UdE7Vu0ag0st0A+98iHQhfRJoDX2tcDIRD04RQhDA1saW0A1jX+iqXdOAK4adxrrR90kQkurLg7lYrzKxnX.XpxKRFy.Suqqyctyg+3e7OhO7C+PkeCxcPTxio44+4SiuFfpeJKSXxjIwxV1xvF1vFPSM0D17l2Lpqt5vxV1xfSmNUA1HmYbxaH4wiG0HfhcaHURUN.mYqvyWS90YWtNWGyZnwrAdNJyZH4nHAX5F7gQp.M.O8TngggJgskcDHvTlcW1Q1QhDAlLYB80We3vG9v3V25V3BW3B3K+xuDiLxH.39Gp4ZBVOdCYL1vyK750K74yGdm24cvO7G9Cwl27lUmCQUSYoj48q44gTbDdt1iyXdOAqGVLWswLUUfxlyNPzue+X7wGG+g+ve.e3G9g3zm9z..pVWFXJ4QkkBhuVL+XX4FYqRK6ZGlEW5b1Z1gj.gj7ibgY2tcq5XTKVrnpmO+mrCQkYll78Lo2nb5zIJszRQokVJd629swpW8pw5V25PEUTg57Cpxzi66vRCM9tDABD.QhDAW6ZWCe9m+43XG6Xn6t6FiO93HVrXvtc6pTrWtdHU5RtAY4ZsTIM..2tcC.n1HCq1fdCve6.45o78C.nh8C9478lZqsV7Vu0ag+g+g+Ar90u9Y84VRfZg3lEWvSvZt90Sp.FuvEXpSVhDIBJrvBw.CL.NwINAd+2+8wQNxQvDSLgZw.lVxzHygCGF.Su.gjLFvzD9XWJJ8ofF2OxmOMxcgSRnkONyXEFBnzadNc5T4Y.VNOJIsWudQEUTApqt5v1291wt28tw5W+5QjHQxZdVQxwbwfbK8hFZnQ1fkXmWybyadSb3CeXUla0e+8iPgBceg+LCxTfoMpOvTlo2lMaHPf.vsa2pq4opGbs47U0AM95At9KuOIylpToRAGNbf3wiCCCCXylMrjkrD7RuzKge4u7WhFarwrFTyOHPSvZAHRkJUVRSJIYA.32ueXxjI31saDMZTzd6si8u+8iO+y+bzUWcAOd7ffACp94jxkxK3Yq2KU9PZXZMlYLSFgk+MVF3r.HqKnc4xkprvr7HLvOsZ0JJrvBw5V25PiM1Hdlm4YvS9jOIppppfCGNTltjDn36cxDYm6RVCMzH+PlyaxLkCXp0dGYjQP6s2NZqs1vEtvEvUu5Uwcu6cUaLkqoRki4M1kalUNW5Xp0y0gmqQAjFyM73wSV+sjaZk1avmOe34dtmC+5e8uFO8S+zpRA9fnt+B8F1QSvRz57x38m0EV1B8LnzLa1L5s2dwYNyYv+0+0+EtwMtAt6cuqpTfrqy3M1AldwE1x+74aQ9e9effz+cxOmDqnWmhFMZVihC.j0nowtc6n7xKGM1Xi34dtmCaaaaCkWd4vmOepmCFkG.S20ebwZFXh45SJMzPi7iwGebXXXn7cCKSOyVNCCCUz3L3fChd6sWzSO8fScpSgu3K9Bbm6bGLwDS.foJEX73wUjrJrvBU4rEedAltb+Z6WL2XtH0v7qJc5zJKXv2y..d629swq7JuB1wN1gJWJYIaGbvAQkUV424+NLeFK5IXQHUiP1wfjzEWTvhEKJYoGYjQfKWtvANvAv68duGZqs1vsu8sA.TkUhJvPOBwGSZ5dMlcvVJGXZOywGO2RGJSVcfo18EModyM2L1912NV25VmJcgAltLeLjDYGlJAOmH2WuYJJEzPCMlF4KhRXlxwRLI6d1HQhfadyah6d26hCbfCfidzihgFZHDJTHDNbXDOdbL4jSBWtboHAXxjIDLXvr5FWMIqGNPOGyH8fp++S+o+T7O+O+OiMsoMkUlWQhtrgdVrCMAKfrLVIAugpEKVPf.ATYdTxjIwXiMFb5zIJpnhTkXLYxj3Tm5T3O8m9S3vG9vn2d6U4uJqVsl0.klRsJGrpZLyPNkzyWSKvNPgC11zoSiMrgMfcu6ciZqsVr4MuYrwMtQXXXnTMjksMd73p2ajiaIZlS9dHeMHIbpnkFZnwLiQFYDXXX.WtbkUVxIm9FwiGWc8KW2kJOGHP.0O6MtwMPas0F5niNv4O+4QO8zCBGNLhEKlxJFbiUFFFJueMaPe6u4FzSaETPA3m7S9I3W8q9UXyadypoWA.Tji485nEKXHi90AKjJa3hdBVrt9rK+xs7RiO93vsa2vtc6HTnPHd73nnhJBVsZUMlSjiBh3wii96uebfCb.7IexmfKe4KC+98mUMqkSq94RAqE4u8jUzIHMsJ+aI20jCGNvF23FwK9huHZpolvZVyZPUUUkZLzDJTHjISFTPAEnTUb7wGG97469dM4qgrijji+Aoga0kHTCMlcjISF0Faj4+VpToTy6UKVr.mNcpFB0Tge4bqi9eD.nmd5Am8rmEc2c233G+33xW9xXhIlPE8NVrXAiM1XOz2fdw95urTrM0TS3W7K9EXe6aeY8dVrXwfGOdTc3IyKvGl0E0DrV.BYa8xzOVN1R3BCxf4ipWk6nkfm30e+8iCe3Ciidzihie7iiwFarrRv6GjSdlqXlXgNj9fijcrZ0pJs8qs1ZwK+xuLd1m8YQEUTA750KJrvBAvzcBpc61UpTwLqhcwoLIhk9qR56K10LxYUIO1dbOmVzPiuKw3iOtJI3kUHPtdatgsK8qEyTKFRob1eJC8T.facqag6d26hye9yi8u+8iKdwKhXwhgPgBgPgBMqGey0ZvKzaDo4xhC6ae6Cu8a+13EdgWP4EKoe5rZ0JhFMp58M1LB41rXecflfkF4ERO5v+YylML1XigSe5Sq59v96uekxU7DbYYvjcaiL2lnwMoBXxLHI2iiusvChIHk9ihG2RRQREAkkeijUkgNHUlBXZCwZwhEUCDTQEUflatYricrCrpUsJ7rO6ydeFPWCMzXgKjqukqGqhGONt0stEN8oOMtzktD5t6twIO4IUkpjd2hdKxpUqJO0FKVLkJ4LVWBGNLrZ0pxdHbTqQhEEVXgHZznpFdQFeOyVWFmayO8cEnxf.SMESHAISlLor+.GL2wiGGwhECEVXg3Ye1mEO2y8b3e7e7eD1rYKKEojQajFyNzDr9VDRiwyOl4DBmqgTR6O5i9Hzd6sq9d.fZVcQEVb61MLa1LBEJz80cij.mzv24db7sAlKBKxAsct4NCINQkhRkJUVkDkiDAlgMjjDedHwpFZnAzRKsfsrksf0st0gZpoF3ymOkmqHAKIwNMzPiElH202lbxIUa5jCO8ToRgPgBgXwhgqd0qhd5oGzYmchO6y9LzWe8o7bY4kWtpzhTUa.nlYiKYIKQYbdYNcwWiYZsV61sCmNchfAC9052kusgLXrAld8ZtocdujXwhACCCricrC71u8ai8t28hxKubDKVLXylsrLrtNdZdvglf0CIjmrI8tij.DOQlr9CEJDt5UuJt10tF92+2+2w0u90wPCMD.fxGBL8hkFGj6NhF41pUqYcwyiJPUmjA1pbQHowU4Eq760ue+.X5ovdpTofa2tQ80WO1vF1.9Y+reFJqrxP4kWNb61s5mkcgj7us4FmCZngFK7f7VVbClREwoBSzSrLKtlbxIw.CL.t5UuJNxQNBNvAN.t28tGFd3gUycTVtK2tcCqVspVehM4BWukDNXByybhhMJCwiZKdPBURarvJqv60XylMr90ud7FuwafexO4mfpqtZ..UCCvFHfPSv5AGZBVOjP1x97ykDs.PVAfGS8cVVsfAChCdvCh+ze5Ogu3K9BLzPCo7xkMa1TFJjWnxRrwRlkK99d7Pv4wmTIMoBdRSpJuPkjDAlNeppu95wV1xVvV1xVvl1zlvxW9xyJHXY14vNNB.JurkK4pbeeQCMzXgAjquEHP.0L.UZ8.tFDiKG1QvbCboRkBCMzPHRjH3i9nOBG8nGEW6ZWSEyNVrXAACFDd73Qsldtdwj4bnrhBxjjmAd5i5awxNllj+38dRkJE1yd1Cd0W8Uwq9puJprxJUpAlNcZUDZvJKPnIX8fCMAqGRjuajKIYwgaI+54NBG3tkxjIC5ryNwG8QeDN7gOLtzktDFe7wUOmxgBb9HWk6I7ee81JS3d4.ylWPZ0pUDHP.0mK8TUQEUD750K1111FZpolvt10tPs0V68k9uxryQ1Ue7eRuAjqRhxGSCMzXgAjWeSRLxt7UhnQip1XGa5EqVspHdkLYR0rPbfAF.s1Zq3BW3Bn6t6FW7hWLqJKv4KKixEpZNUSW1gyb8pb8H121qKOWquUQEUf6d26pNlYoT28t2Md0W8Uwy+7OOV5RWJ73wCRjHARmNsZM3vgCqZl.4ea0Drdvglf0CIlIkRxUEK42ijH.OgWNHhGbvAwANvAvm8YeFN1wNlZmSzv3xxswe9bUP6aq2VePtPh6bi9efIqLW.hGOtb4BKe4KGM0TSXO6YOngFZ.UUUUYM.kYl4.Lk5dbgP4uO4yL6yjZdZngFKrPtqoJWGUt1GKqGK6mKWtxRA8XwhAmNcpHUvJCjJUJLv.Cn5FwO3C9.bzidTLwDSjUS6vWCtYR1kxz5BzX7xi4uMWalu9yFRmNMJpnh.vTVSot5pC+xe4uDu1q8ZXEqXEY44WFaPbtPxtwdlrdgln0bCMAqGRLakhhm.xIQtzTgrbW4lYHjjUjHQfe+9wG8QeDN0oNEN5QOJ5qu9TojKkrN2Zim6+dXwbcALIQQOXIUyh4QSc0UGdlm4YvN1wNPc0UGVxRVh52YFfcDwiGOqKbYKAKAWPkKZxGiPeQuFZrvE4ttlL3lkcmWtqcQ6DHUaW98EMZTUEGnJNoSmFABD.SLwDn6t6FG5PGBs1Zq3F23Fpr0SNSDk9zRlyg4if02FqOOWgcbgEVHBGNLVyZVCdm24cvq7JuBppppxphHjXXnPgfKWtTqoNWi5FMAq4FZBVOjXt75iLDRkJuH2UfL5EXG2A.kmsFczQwEtvEvgNzgvANvAvEu3EQxjIUoUr7XI2xn8vh45BXYW+QkrJqrxPiM1np6+pt5pQM0TCb61sRRdZxRR1jpxISJc9wL8mkwUwrofk9hdMzXgKx8ZcY5vCLswxo5UFFFJOEwR6wuGoBXlMaFNb3.ISlDQiFElLYBd73QsdBi0fjIShyblyfCdvCh6cu6gu7K+RzUWckkY5YoKkGyeWPxZtxwp5pqN75u9qi23MdCk40I4Jtwe1A2bF4FJTHX1r4r9cOWn835CFzDrlmf70Ah.Pk76LaUt8suMZs0Vwe4u7WvwO9wUIhLMOexjIU6nhSXdYlrHILQkmHAO4BLLkkIYH1kLx3hf+7EWbwn7xKGKe4KGabiaDszRKXCaXCnzRK89HnkOCoqgFZnw7AjaE.HAFYi6H6JuvgCiKdwKhwFaLbkqbE7+9+9+ht5pKUr7vl7gO2rbjlMaVEjpLw5Alty833lQZNcYmVyR5w02KszRQpToPvfAQlLYvpV0pvq8ZuF9Y+reFprxJgWudUl7mkJkDB036NnIXMOAyzta3EkxwDw3iONt4MuIFbvAwu6286v0u90Qu81KRlLIra2tJk4YGuHMeorjkbQiBJn.UJIC.0Ew.SSvSVhS61sCe97gRJoDricrCrksrE7TO0SgktzklURnCf6yz5RBVZRVZngFymPtavU5gT4iIyRJFoNABD.iN5nHQhDn81aG+2+2+2XjQFACLv.vue+peF5WUVNQow6SkJkhHDgrywkiTn3wiiBKrPX0pUDKVLDIRDr5UuZ7pu5qhW9keYzbyMiwFaLTXgEp7qa9RhcM9tCZBVySPtRFm6E3xXPPV9rIlXBbxSdR7AevGfVasULv.CnTrhjnn7uTEL97P0qb4x08803ExbTSXXXfUtxUh0t10hMtwMhsu8siMsoMoTNSl4Lr7e.2eRKmK4JMIKMzPi4SHedXM2DWW5uKtdbrXwTylOqVshfAChfAChyblyfVasUb1ydVbsqcML93iqRMd4z3fudFFY84itA..CLdRDEDUFvlMaJhWrCr4Ffc4xEra2NRmNMBFLHrYyFV5RWJd0W8UwO6m8yP80WuZMctVqzGvbS2rxGZ7cGzDrlm.4aC41FxxIOurKBsXwBhFMJb61M..NyYNC9fO3CvgNzgPWc0kZWS74jpfwx8kJUJTbwEiPgBgjISplkTjTUQEUDV+5WOpolZvS+zOMZpolvS7DOgZN.BLc.+wRL5xkK0hMABD.KYIKYF6jRM4JMzPi4aH2NQLea5k+evfAUapjccG61Pe97oH0DOdbbyadSzSO8f95qObpScJzVasggFZHkeuLa1bVAGM8.FSCdVoAlKhlLYBKaYKC+leyuA+nezOB0We8pQdC+eoxU4lmUxRcpw2MPSvZdDx2aETF27YpaoJUYxjQQdpu95Ce7G+w3vG9vn81aGgCGFgBERcQFCdNSlLgPgBo7.fa2tgWudQUUUEdlm4Yvy+7OOJqrxPIkTBJt3hUK1vcDwcfI+7LYxbeWHm6uaZhUZngFymwCpItIApXwhoFKZzeSz.4bjmwAMuKWtP3vgwMtwMvUu5UwG9geHN4IOIBGNLhGON762upTdQiFUM1zrXwhJY42vF1.Zt4lwu829aQM0TC.fxaUxgvLMtNqXAOlAl6NDWiGdnIXMOC491grsikcqG+ZzjhLqrjyMpnQihO6y9LbnCcH7Iexmf96ueU4+3B.974CKe4KGqYMqAaYKaA6YO6IqcBkNcZkBYzj6ReUELXP3zoS0qIMcuTwLMzPCMVHhadyahJpnBUjLHWSlqSmHQBUm6IiTBVlNFuMW5RWBG5PGBs2d6nqt5B27l2T4SK5q0UrhUf8rm8f23MdCrqcsK3zoSk+qJpnhfYylwvCOLrXwBJojRTjqjjoXIImqNDWiGdnIXMOGjrB+mbvFCj8nhffsILSIdlgKe9m+438e+2GW9xWF0TSMnkVZAMzPCn4laF0We8vlMaY4G.5+KRRhWnKa0YYWHBLcJFqMxtFZnwi6XlTxR93IRjP0s0zeSx0pCGNLLa1Lb5zIRjHAlbxIU1wfkyCXpNRjyc1Ke4KiCdvCh95qObtycNb6aear90ud7lu4ahm8YeVTRIkf3wiifAChRKsTU4JYYEYxxSkqx0Ku72AsI2+tEZBVyyA28C2sA20Cy9ElwK7hZpxkblXQRQwhECc2c2nu95CkUVYXiabipvwKW0ojlSm6dJeC7S4npHW01.v88yPnIdogFZ73NXvJ6zoyrFGXjnEGL8ryroWW4ZtzGsjXkbXLSbkqbE32uerhUrBTYkUpxoK9yPRZrjf1rYCiO93p.blGKTMKduj7EFqZ7sK9+Cvm3dKUVCoil.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-20",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 38.0, 119.466667, 128.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Downloads/full_10357.jpg"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-116",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 128.0, 35.0, 648.0, 60.0 ],
					"text" : "Let us take a little road away from music, just for a while – we'll get back very soon. Take a chessboard. Take eight queens, and put them on the chessboard, so that no queen can eat each other. The chess is 8x8, so one could hope to put at most 8 queens in such position. But if we extend our chessboard to a generic (square) chessboard, with n rows and n columns, we can hope to put at most n queens. This is commonly known as the n-queens puzzle."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-256",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 249.0, 506.0, 382.0, 33.0 ],
					"text" : "Indeed. The problem is not solved at all. It would be solved for Rooks, not for Queens! How do we formalize the diagonal condition?",
					"textcolor" : [ 0.0, 0.168627, 0.67451, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 244.0, 502.0, 81.0, 18.0 ],
					"text" : "clean, wclose",
					"varname" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 243.5, 557.0, 245.0, 20.0 ],
					"text" : "linksections 1 1 k \"God Solve The Queens\""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 243.5, 529.5, 69.0, 20.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-49",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 16.0, 444.0, 20.0 ],
					"text" : "_________________________________________________________________"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial Italic",
					"fontsize" : 16.787033,
					"frgb" : 0.0,
					"id" : "obj-50",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 276.0, 6.74086, 288.0, 25.0 ],
					"text" : "- and may the Bishop see it"
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
					"patching_rect" : [ 4.0, 1.924051, 368.0, 31.0 ],
					"text" : "God Solve The Queens (k)"
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"border" : 1,
					"id" : "obj-81",
					"maxclass" : "panel",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 201.0, 231.0, 97.0 ]
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"border" : 1,
					"id" : "obj-42",
					"maxclass" : "panel",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 245.0, 225.0, 318.0, 96.0 ]
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 0.556863, 0.180392, 0.180392, 0.113725 ],
					"border" : 1,
					"id" : "obj-31",
					"maxclass" : "panel",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 310.0, 329.0, 136.0, 147.0 ]
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
					"patching_rect" : [ 5.0, 641.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 616.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 591.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 566.0, 148.0, 18.0 ],
					"text" : "God Solve The Queens [j]",
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
					"patching_rect" : [ 5.0, 541.0, 40.0, 20.0 ],
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
					"id" : "obj-10",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 516.0, 151.0, 20.0 ],
					"text" : "Back to section (j)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 641.0, 641.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 641.0, 616.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 641.0, 591.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 641.0, 566.0, 148.0, 18.0 ],
					"text" : "God Solve The Queens [l]",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 641.0, 541.0, 40.0, 20.0 ],
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
					"id" : "obj-23",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 641.0, 516.0, 151.0, 20.0 ],
					"text" : "Continue to section (l)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-18", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
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
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-22", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
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
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 253.0, 583.0, 237.0, 583.0, 237.0, 524.5, 253.0, 524.5 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 324.5, 463.0, 433.5, 463.0, 433.5, 348.0, 324.5, 348.0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.0, 0.0, 0.0, 0.337255 ],
					"destination" : [ "obj-32", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 79.5, 244.5, 153.5, 244.5 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-59", 0 ]
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
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
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
					"destination" : [ "obj-40", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 19.5, 271.0, 241.5, 271.0, 241.5, 218.0, 259.5, 218.0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"disabled" : 0,
					"hidden" : 0,
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
				"name" : "full_10357.jpg",
				"bootpath" : "/Users/danieleghisi/Downloads",
				"patcherrelativepath" : "../../../../../../Users/danieleghisi/Downloads",
				"type" : "JPEG",
				"implicit" : 1
			}
, 			{
				"name" : "bach.repeat.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.prepend.maxpat",
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
				"name" : "bach.constraints.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.arithmser.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.comb.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
