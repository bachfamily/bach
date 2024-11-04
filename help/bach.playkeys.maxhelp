{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 6,
			"revision" : 1,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 100.0, 100.0, 908.0, 548.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 5.0, 5.0 ],
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
		"showrootpatcherontab" : 0,
		"showontab" : 0,
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 100.0, 126.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 659.0, 376.0, 150.0, 21.0 ],
									"text" : "e.g."
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 105.0, 446.5, 162.0, 54.0 ],
									"text" : "Force reset of whole system – ONLY useful after Max crashes"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 269.0, 462.0, 108.0, 23.0 ],
									"text" : "forceresetmtsesp"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"linecount" : 9,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 708.0, 95.0, 197.0, 137.0 ],
									"text" : "Use options #1 or #2 for standard mtsesp. They will detune every midinote appropriately, but still they won't allow collisions of microtonal clusters. In this case, use option #3 or #4: they will possibly alter the midinotes to provide you with the most faithful rendering"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 688.0, 375.0, 108.0, 23.0 ],
									"text" : "plug \"Pianoteq 8\""
								}

							}
, 							{
								"box" : 								{
									"attr" : "mtsesp",
									"id" : "obj-7",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 444.571428571428555, 152.0, 259.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 553.0, 184.0, 153.0, 69.0 ],
									"text" : "MTS-ESP information is sent out if there's a \"midinote\" key"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 569.571428571428555, 361.0, 33.0, 23.0 ],
									"text" : "plug"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 618.571428571428555, 334.0, 153.0, 55.0 ],
									"text" : "Plug in any MTS-ESP compliant plugin"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "ezdac~",
									"numinlets" : 2,
									"numoutlets" : 0,
									"patching_rect" : [ 533.571428571428555, 444.0, 45.0, 45.0 ]
								}

							}
, 							{
								"box" : 								{
									"autosave" : 1,
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"fontsize" : 13.0,
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 8,
									"offset" : [ 0.0, 0.0 ],
									"outlettype" : [ "signal", "signal", "", "list", "int", "", "", "" ],
									"patching_rect" : [ 533.571428571428555, 409.0, 92.5, 23.0 ],
									"save" : [ "#N", "vst~", "loaduniqueid", 0, ";" ],
									"saved_attribute_attributes" : 									{
										"valueof" : 										{
											"parameter_invisible" : 1,
											"parameter_longname" : "vst~[1]",
											"parameter_modmode" : 0,
											"parameter_shortname" : "vst~[1]",
											"parameter_type" : 3
										}

									}
,
									"saved_object_attributes" : 									{
										"parameter_enable" : 1,
										"parameter_mappable" : 0
									}
,
									"snapshot" : 									{
										"filetype" : "C74Snapshot",
										"version" : 2,
										"minorversion" : 0,
										"name" : "snapshotlist",
										"origin" : "vst~",
										"type" : "list",
										"subtype" : "Undefined",
										"embed" : 1,
										"snapshot" : 										{
											"pluginname" : "Pianoteq 8.vstinfo",
											"plugindisplayname" : "Pianoteq 8",
											"pluginsavedname" : "",
											"pluginsaveduniqueid" : 1349793905,
											"version" : 1,
											"isbank" : 0,
											"isbase64" : 1,
											"blob" : "40722.CMlaKA....fQPMDZ....A.Ec3DG.HD......f3TVfLEckkla2EVdfPDHCwVXyMWZiEFa.........3o0PImUKYB..H.VFQETF6I..n....fLvHCMu.CNuHSLW.....UZg41azUVbffiKw3BLuHCLxLCL0DSM6Zjf2tL6OiiRhCJzlg3ftSFarEVgdB..zQFcM0PE..vE....NkEHSQWYo41cgkGHDAxPrE1byk1XgwF.....G....zzajElbzQmP....TgVZyABbxU1bkQGHuYlYkI2bfDFHBEDHsk1Xo41Yf.WYxMGbkMFcoYWYfbWZzgFHgAxXrE1byk1XgwFHy8VctQlK.....PT...vE....NkEHSQWYo41cgkGHDAxPrE1byk1XgwF.....xQA..bjTUUE...fA....AL.vMQkbqA..TvE.+KfFffTX4QlafzBHS8lagQWXfjlafbDHsElZuI2PvNjdBNCfxjSGfdDGX.4QAIGr.MBI.UyI.0yI.8yI.EjI.QD.CwmI.gjI.wD.C4mI.8TI.A0I.E0I.IUI.M0I.QUfV.jUp.zUQ.JRbTAr.ckAPhjLe.KPWoAnJwwBvBzTH.oRBI.fGcRGvBTRn.zNC.HR87Ar.MxCfNDG..nR+X.n6vQA2vAAPNjQFriMB.KP.P.j2fSM.tCO.LTQDbSOCx.n6vgA2vwCPtiN..5PbH.j2TyCCETO.tiP.LzPHbSPAZDnEwQEPVjPLAXQ.AAnGwADPdzQTApLb.PQbX.Ob7.jxXi.EkD.7nyG.dDPVvSPFHSOAlVQ+vAnCwADPNDQkA3P2b.nxvgB7vQCPJyMGvSMF.ZQbLAjEIjL.JSP.viPBtCnGwgB.VzNH.4QAEHH.djOc.5MbnvPb7.j2bB.ftCGD.4P7PwNvbDr.oBH.tCPF.KP9DAf2ziDvBjPN.3P.cAr.czI.wzI.E0I.UEI.k0N.skfG.TVl.DUn.zSl.jSp.TSf.DSm.TRk.zPk.jNn.jJl.D.lLDTB.JRb..Sbr.jHgDALEUEvND.N.HREIXEf5DGW.oS+..fLkCKf9DGW.4SIACnGwAEPdDP..pRb.AjJcD..9TPB3zOjbzPWnTQCd.nHwg.EwACPhDPBTjPP.6PQ3AfEIjKvNTElLDFnLzFeMjGm.pRb..rCABEPpjMB.HR2v.rCQBJCkh.fxDGU.ISCEArCsBH.pTOF.6PrDAnCwwCGwA..xTP..4PCY.rC0RBPdTQY.6PwX.fCMTHvNDNC.3Q.IBrCwyIC4CJC4iRC8iICEDICMjICQDJCQzCfdDGR.4QKY.rCYDHfBDGE.6PLI.n7vABPBjQMvyMN.6PUMAfG0yCfVDGE.6Pd4.jEIzEvNTYO.5Qb.AfEAD.fdD..bDGG.6PtEAjGIzEvNzclLze+.HOmX.nEwwCPVDTI.3QA4EnCwA..VDPS.4PLMAn8vwDP1iPM.HP.gSOAMHBCYSCfpDGX.oR8L.nBwAA9vQDP5SNFHDLpAnO1L3CvBDIb.pLbf.r.Ei..JjLT.oLn.Ar.kiI.wSD.JSNW.KP9XBPAYBPCYBPGYBPJUBPLcBPOIAfJoSEvBTU.Ljdj.zW.LjXj.TX.LjPl.jS.LDFH.pRbrfObP.jJkE.fJDGH.oOQMfPNQ.r.IC.CAvI.A.E.5CQ.HjQCtBnBwAB9vAAPJjSE3CR0.nPFAgOCEXNJsyAfxDGP.ISJMCnNwAB.xzPG.oSMsFnLwQBPxjVa.nS.o.n9vA.CwwCP5CPVLjPR.HS+vwPCkgO.M3.fNDGL3CG.vDGC.4PKofOHA.SaUCfCUDBLMzB9Hzfh.5PbTPRbr.jC4D.IgkAfBDGH3CGG.IPCgfOAsAfCcDG.MDAvBDOI.nO+zAr.AkH.k0I.0UfX.jWl.TXr.XRrXDr.4UIfNDGB.KPY8.jC0iAfBDGC3CGDnDGI.KPSY.j.Ai.9TC.J8yGvBzSM.3PBw.P8r.r.szA.5yOe.KPGoBPCU.nLwgB.pzNJ.ISC0.r.8CJ.sCAf5DGS.oSHs.r.oyI.gCCf9DGR.4SMkAfL8CAvBTLm.D.a.ZTb7.jQUkA.5TPH.pObHfPbz.jBoz..9DQ..oO7v.fQkDKBUzD9.jfrApObffPb.PTb7.j9zC.Qok.BEzJ.FEQHHTPS3CPCJAn2vgBPdSRB.pOb.vTbz.j9DD.Sc0K.dCQ.3CPT.KPcTBP3bBP+XBPAYBPEYBPKYBPScBPWUBPXkDfS0i.vBTUh.JVbX.r.oj.f5CGFbCGA.IVUYfOGIvMEUAr.wSF.dCPG3SPF.KPoHBP.rAnVwwCPZUTi.6PUXxPY7.nUwQEPVERH.6PczBfX4iKfNEGQ.4TK0AfV8CHvNDHd.XU+f.rCMhICkB..NEPW.ZTbz.rC4h.f5CGF.YT.8fO5.Ar.IB.CESI.5iO..KPy.vPwbBP6fBP+.vPxXBPCAvPzXBPFAvP4XBPJAvP5PBPLYBPM4DPLAvP6LBPJAvP7LAnUwwA.FUOH.YUGQ.r.YD.C8CAf5CGO.oO+LAr.ID.CIzEPdiIO.KP7.vPFMAf9Dj.fNEGQ.4THA.r.cC.CkzF.diHK.KP0.vPKYBP0.vPKQ.fU0CBfFEGQ.YTFk.r.MC.C0TG.NEPH.KPv.vPQQBPs.vPUk.nOwQEP9TS..XT+f.r.kB.CoEJ.cB.C4kI.YB.CM1G.9jPG.KPi.vPqcAn9vg.4vQCvBzG.LzbB.oO+XPN7P.nNwQEP5DQF.KP..vP6UxP+UAfNIzfI.pSbbAjNMjAf1CGI.nOyf.j87yL.5zPJ.JSbDAjLcTO.xDQ2.pSb7.jNQ0afxDGP.ISLkAfN0yR4zCG83CBLADAfpDGS.oRKc.n9vwDP5CN6.nO8LnPfJCGa.oLrrCfJYSgJHCI4.pRbLAjJoSf4.KPhTBPuvCP3XBP7HBP9XBP.YBPCwBPFYBPIYBPLcBPMMBPOcBPQcBPQ0DfJYQMfxDGY.IS2jDr.A0Af1DGY.YS5b.r.4zH.sjI.YjH.xTOD.KP9P.fM8yDfRDGM.KPvH.jD8DIvBDHN.pObb.MbH.fDUjBP5yKEPSKB.KP.vCf9XSBzXifSAJQbP.MbbfObX.jDwzCzPC.9nCS.5yOBPCPePjOAhBnEwgEPVTQ.A5Qbb.fEATCPdzQVAJMb.PQbr.Obn.jE0j.zbCB7bCS.dTP.viOIPSNA5VQ8PAnDwQDPRzSxAJMbrvNb.Aj63y.znBCfVDGT.YQFQ.fDsyI6HTBz3SfiUDO0.5QbDAjGcTN.djQKAZNbvAj4zxEfdDGT.4QBMHV.dzNy.ZKbn.RbTAjsPhAH8RDvBzJO.XNvTAr.ciI.0CJ.AjI.MjI.cTH.hzKA.KPKYBPMoCPOcBPPcBPPQBPM4AfsjBBvBzPe.JRbb.r.ACAflCGD.IRB8PN77.r.APfmAHRg.CnLwAEPxjPmAZQb.AfL4y.PVzQ..XNzHBn1vAEPZiMAtBfEA..PVjDqAJRb7.jHQD..VzNvYyNe.5Qb7.jGYkBfdCGS.HR8D.j2fSf7A3Q9jAnJwwCPpTRAN.nCwgCPNjSH.nR9z.nuvgEP9BMJ.3MvHHGvNjdL.5QbH.fC4CDPdzQJ.6PoYxPaQxPOcxPAcAnEwwCPVjR..6PvPAfG8CCfBCGF.6Ph7.jvfSEvNDGb.3KjHCrCAhICIhICQhICYxI.VTO..6PnnAnHwQCvNjJF.IRGEBrC8RICgSICETFfBDGB.HL+r.rCoj.PBDSG.HR4X.nwvwEPFSN..6PRYxPWgxPccxPlUxPxcxP8QxP+AEnEwQEPVjQO.HP9bVL1LCnxvgCCwwCPJCLBLDQ..XQ7LnWxPxCC4SFfJDGOXBGD.oPzbgInPDr.YyF.ZhMK.KP.cBPEAvPtkBPJAvPOMBPOAvPxXBPTAvPbXBPXAvP.XBPaYBPeUBPicBPpcBP+IEn4vQCPliTD.nPA0.r.UkI.QCJ.APfkATIl.DLl.TNn.jOl.TPl.jQj.TSn.jUl.TWl.jXk.TZl.zeUAXN9n.n6vwCPtiQCAJObDAj7rjL.tCOV.KPQcBPjb.nxvABNwAAPJSWI3DXK.KP.f.f7HjLxTzf3.pLbj.jxrUM.JCRBFAnOwQDP9jRr.nS7r.nQwgDPF0SPA3SBABnBwgAHwABPJjXGfjTU.XTA8CR.MnKfhDGN.IRP0BfHgTfqA5Pb7.jCgTD.JDOk.ZQb7.jEEkF.NzOLAJOb3.UbP.j77zATYFA.VTPBlGU8..nXwwCPhUSAl.fXIDCfFEGO.YTLInF.FUOh.JUbbAjTQTGvBjIl.zMi.DPb.pSbH.fT8yAvBzQH.oSM8Ar.4TC.xiNd.KPTcBPaAvPQTBPmAvPTbBP+8.fNA..f5DGg4ze..6PWzAnQwwDPFUSa.6PZTBPe0AnNAfBvBTS.LTGl.DQE.pRb3.jJ0TDvBjP.LjHF.XT8HBr.UD.CchI.gD.C0hI.sD.CEiI.4D.CQCI.AE.CUyI.IE.CciI.ME.CoCJ.QE.C4SCf5DGO.oSNo.r.QE.CQDI.4D.CwzF.pDOK.KP.AvPXcAnOwwC6vA.vBDJ.LTZD.4SNsvNCkBr.A..C0GG.5zNK.6P+w.f6DTf88DPH.pRbDAjJczV.pTNk.JObTASbH.j7bSCLwDK.xSPARFS9rAnHwQDPhzPzAHR9TAnGwgDPdTTd.pOb7.j97i..dTRChCnGwgCPdTUX.pLbDAf9vi.PJCP+.ZQbf.fG8SBPVDPv.XQAQBnGwwEPdDQeAZQbDAjEwTI.dDPgA5Mbz.j2Tj.fNDGQ.4PTA.fEoCBx3CK2PDgI.5Jb7AfCADAPtBIE9EfqPCKfpDGW.oRyTFr.ghH.cCJ.0yI.8SI.EzI.QDI.cjI.wjI.8TN.IkI.UkI.YUf+.zUn.JSbTAfJgBAPxDNJAZSbXAjMkyFvBjUm.HS2..r.E0I.Yj..1zOW.JQbn.r.oiAPRDQN.pObH.Mb.Aj9Pi.vBzIE.IMtzAfDMDAvBD.V.nO5v.M2HXefRDGDPCGD3CGI.IQD8.My.fO13CfDIzA93CBz7Sf4.ZQbTAjEoyM.VDPB.5QbLAjGMzYfVDGDPCGKvCGA.YQZY.M63.O93AfG4CE7HjBz.TfZUDO4.JQbDAjDwjdfVDGS.YQNA.nzvAA6vA..RzOQ.IM4.vN9LCf6.TFz.TfIUzMy.5QbTAjGgzM.dTQAFAnGwwA4vgEPdDNWjiDCREfGkiIfhDGMzBGP.IRvb.r.UBCP1RIa.KPvbBP4jAf4jhCvBTOl.DPl.zPl.zQl.TRl.DSl.zSZ.HRpv.r.EkI.MkI.E0I.oTBfhDGP.XKoT.jHwSBflCG..KP93Bj4rhBvBTLl.zKj.jLl.TMl.zMn.DNl.DNW.pRb3.r.gyAPpzOe.KPzz.fHcSDfxDGH.KPrz.jLsj..pzOW.KPdXBP.n.nEwQA.lCMH.pMbb.jEkDC.xzOD.oM0PDr.AxI.MRI.QxI.YxI.chM.VTLU.KPlnAnHwACvBDIH.IRI4Ar.EhI.A...ZyLn.5QbHvMbDAjGAEA2rCB.hDPBVBnHwQEPhDPG.3QdvCnJwQDPpTRE.HR6jDnuvg.CwwDPNzR.7ROH.3M5bgR97Gr.4gH.ARafdDGG.KPcP.fCkCBPdDRa.KP.TFnvvg.EwgIPBCP.TDTW.3Q+jwKvHnBEgyBfhDGS.IRFIEfv3SHfFCGI.DGO.YL3..PEI.fH0ifcAZQb7.f.ECBPVjOLAXL6XBnxvABCwA..VjNO.oL2.vPGM3I.JSKTApPbz.fCwCBPJDOK.pIbTAjl7RGvBzJl.TOG.nI67Ar.EjJ.UjI.oDJ.ME.CEFI.oE.CcSI.AF.CAvN.Q1I.k1I.A2H.8Wfz.ZNbz.j4DlB.JTPY.KPaUBP6bBP.LXa.AhI.IhI.QhI.cxI.kRI.sxI.4xE.liOG.5Nbj.r.MiAPtyQe.KP5XBP+jAn7vQCvBzPB.IOLQBr.Yj..tCPj.KPDEBnxvgAvBjJG.oLaA.nNwwCP5DXO.KP.H.f7HDLxHzfDApLb7.jxvzO.JCQBd.nOwwEP9DQs.nS8H.nQwQDPFkTVA3SAkAnBwA.HwwCPJzXBfjVd.XTAgBRAM3LfhDGM.IRVQEfH4SfX.5PbHAjCYzV.JTOO.ZQb7.jEsTH.NTP2.JUbX.Obb.jT4EB7jjI.VzOBVEUA8.nXwADPhUSAV.nQwA..hkPO.YTMQEr.8BI.oCJ.8iI.EDI.QzI.F0M..KPE4AnTwQBvBzPF.IUL8Ar.oiI.EBJ.A..CEwGf5DGG.KPpX.jNYkG.R0OB.KP7.vP.TBPCUBPIAvPQbBPOcBPXcBPfIBPkAvPTXBPZY.fNUiHvBDQ.LzEB.ZTbDAjQszDvBzIm.D.i.zIm.TN.LTFD.pRb3.jJ4DEvBTPG.HO7PPT9jAr.cD.CwgI.8jI.gEJ.UlI.IGI.8GUfxDGO.ISHkCnNwADP5jSE.nR73.r.AF.CMhI.MD.C8RB.xzO..5Sb.wNbD.jOcEC6PD.vBTG.LDPl.nSAA.r.A..C4DH.tCQF.6PYcxPjcxPvgyP4YxP+sEnJwwDPpzPdAnR6fvS1TBn7vgDPxiP..JSbTAjLQTK.xSQApBS.YDnHwwDPhzO+.HRE0CnGwwCPdzRg.pOb7.j93C..dzQCFDnGwADPdzRI.pLbPAjxDTKfVDGB.nO2TAjE8CF.dD...5QbDBfEITGPdDIzAZQbz.jE8j..dTPANPQ+3.nCwQCPNzTD.5Mbv.j2DzE.JyOsbyPD1CnqvQFPthKB.3P.U3QqvCUf9DGZ.4S5D3UvBDIm.zKl.TNl.TOn.zOj.jPl.TQl.jRl.zS3.jTm.TUk.zUl.TVl.jVl.zVKAzVm.DWAFAnQwwG.9TKF.YTj.EnRwQC.F0MJ.oT8XAr.oEI.MkI.kzI.JUO..KP9bAnJwAA2vACvBTLB.oREgvMrzAr.4AH.pTPG.KP.T3FfZDGDnDGQ.oQ2HfR9D3CvBjIl.jLn.jNm.TOk.zOk.TP6.zPh.3MfP.r.UDJ.cjI.kDI.ozEfJCGS.oL3HBr.czH.AjI.ACJ.8gI.ghI.YCI.0iI.EzI.QzJ.cjI.oDLfhDGH.nR9j.jHADBvBzQD.nQgj.nEwQFvBTRC.YQubAfH4CCvBzSa.XQ6r.r.gkI.40I.MVI.c1RfhDGA.KPj4.jHIzEvBjVf.pRbf.r.sTA.hzPH.oR9jAr.ciI.A.K.JSMQ.JRbDAjHkDAfNCGDTDGK.nR+f.jyLyAEYC.vBzGn.jMl.TPm.jRT.XQ9HAr.UE.CgmI.QF.CYFI.8G.CgkICcDJC4hICA..++B.PI2bUgVh..PR....J....LGckkla2EVdtkG.....a....bjbg4FYfLEckkla2EVdfPDHn3TY2ARVuI2Zo...........vI2as8F...P.....A....D....fB....yQWYo41cgkma4A....vF....GIWXtQFHSQWYo41cgkGHDABJNU1cfj0axsVJ...f+X...............................PkQ+++++C....................fb4EFaP....H...............7+++++ar81bQ....D....P.....FA..........A....D...............D...............D...............D...............D.....C....C8laiUlbzABRgwFa.....D...............D...............D...............D....................v..B..fkF.......QP...f+jF....alYBPP.5++6KiYl8u.2LS9POyL9CfyLyOHlYF+.JyL6KoYl8O.2LS9.kYl8CVyL6OZ....QB..9CfYloO.yLS+BZlY5KnYlouWg0Ly9CvLyrOTlYN.yiYl9Kn++uu.Lyr+hLyL+KIyLCv.tLS9h+++9K5gH5u.1ta9BhCg8CpIm4OHfG..AXBV1C.DjjOPWB8+hnzm9K.hQsuf7.R+.f90xKTIz1ufOfD+.7t69C1nF5OT9Rn+.5Lr+CPa3mu.XTC+B.T54CZtovOjbW++f0Vr7C1x33OzA15+hPyr7C3oOoOnzwY+.xP79C3FGwu3WK3+xKhP.TrOIHPTwVr+.3Ly7Ctpe8O.I5s9hvY18iqYFHPDalm+vzL6ADjYF+ufVlY+Rclw+CXl4CPh..A.ATyL7CfkYhu.Yl0+BzLS5K.yL6uHlYf+BfYl4Knyr6OJLy..q0LO.Dil4.P.jl48.LyL8KxLy7uZ....ALyL6CnYlwuPyLi.AkYl8inYlEPXlYl+BbyL4CIyLCvXlYl+BxLS.LhYlEvjYlI.iLyL+KIyLCvTlYN.O....P...............v.....................C....................L....P.....A....D........3O.....D..........afWT9L.f...XXA......nFD...3OXA...D4Tk7yUi86H+r1Ym7SA3ZxOQzvI+vkhm7SQXrxOeYqJ+3QDq7ikvqxOty7J+LBks7Cu.9xO.f5K+P14w7Cd0CyOyUfL+r6Xy7yP6XxOcvVG+zenb7yJfhxOgPyL+XIVy7CYeQyO6E9M+nXH37SKmuyOL3ZO+H4F87igO0yOUUaP+TyIC8SQUTzOTwXQ+v6EG8idUpzOF1GT+HyQT8S.nn0OWmvW+nFRi8yTOh1OpFCb+zPky8SOsn2Oo0Je+3X2A9CFYQ3O0Hpg+zLfH9SDjn3O6PAj+fsDT9ieYi4OEv0l+PuTf9yWYP5OVvSp+zqvr9y7kD6OI1Ts+zXV59i7H36OYOqu+nalA+SI7E7OVNxv+Ta0D+SpNY7OHUTx+XhrJ+iVXs7ORCHy+.aHO+iXbA8OwdVz+L9FQ+i5gB8OWKWz+TmJP+y6.D8OhkDz+.BZP+i.RB8OUkLz+HiQQ+ineC8OA..................n.C..fBD..XqP.....L.f...T...bBE..........................A..................n.C..fBD.....C.H...l........pAA..tJj..........D3..B..fI.......fZP..fqBI........3OABH.........RS...................B...7C...3OC.H...FV.......pAA...9CV....DuHy+bEmde2O3FYE.4rId8Cr5.BvEs6w+rBoe6SIojCvYYWO+dQ8I+6hQO5On2p3+bTfc+yiCAiOA6TG.Uzvl8KW+U7uNaWO9hRxF7qHHoyulaVL.aWY38yzEtlOccpa9Z17Y8C3fq7uzno3+pRJt+qg4vBv13D4+7Ns29KlXwuO3J0I.M9or.zPQP3OAT9N.+C7r5itQt2OnXc++VrXk+CLnOCvMzY5+PYC6.TrqIXOkzjK.ky6E+i3ONzO3bwM+LMgp.zxKRAPtLnN.A2yg1qj.OAP8.Lv+lRq936YZyBvl8GI.MoX2+q9Ce.vQCp3+1+2I5yqP0APpoIA.SvJw9iIWf.PQQL6+tzFM.DqsyAvciEE.iGgZ9yhzoCPfsvF.cur..74jJtOoqmN.ykg5.bM6u4ObMM0+dH7e96ERgfuxU2y+JIGI563L46ubhFn+rdQi9ajo62OKQXL+d70c.7..B..fgE......fZP...f+fE........PB.........3O...f+j.....f.....A...9C....P...f+....9K...3O.....C...AL...DvA....9K...3uN.....D....v.........9C........f+....AD....v.....A...AD...3u.....B...9K....P.....I.....f...P.C...ALB...f+B...9C....P...f+.....L...3u...f+....AD...DPK.....H....v...f+B...AL....v...f+....AL...3u.....A....H...3u...f+R....Dv...f+B....D....v.....GH....PJ.....L...3O.....B...9K...3O..........L....f...f+B...9C...3OF....AD...3O.....B....D....v...f+....9y......C...9K...3O...f+P....3u.........AD...DvC.H...FV.......pAA...9CV....6Myc+bkFER2OgBee+30iA9CeWf3O.UId+nGcE9S4dt3OFVVe+HEx98iQxP3O0SCi+bgT28y+om2OPg3e+Depn8S7HE3OY2fd+LvH28SIVh3O60bf+Xr+H9ivls3OvB5g+DwU68SJb81OBKpg+.Omw8Sy9c3O5P.f+n+EC9SRx01OUcge+jnpC9SdqR2O.Elg+DpA78SC.A3OtnXZ+zXVH9CmoU3OLG.b+ji.D9iIQ.3Os8Tb+Tnay8iqnf2OtjEf+bkUI9ihei3OLCRh+D3l.9yb+L3OaP4f+Dtxz8C2Yg2OFK4a+rXCG9iRFB2OFBdd+XkcC9CaEl2O9oif+PI9I9yr2W3Ox+mb+ju8J9yj8L3O8uVe+fICE9ivT02OhPsh+DxRy8S3zv1ODmqc+3i+K9yh8g1O76yc+LfEm8Cw6B3OmpYZ+bX+A9iWml3Oqe2g+jEPK9Cpeg2OBo5h+zXoz8i.....A....TE...PQwUWXrABck0FbkIWXsUlazo.UnUFHyQWXtQVXxQFHzUmao41Yr.xcnUlbkABcnUFHuMFcgYWYfj1bfPVZ1kFYkQFHo4FHwHCHkEWcgwFHyQWYvMmKL.......HKD..fzP..fkCA..HOD..n+P..fEDA..uPD..fDQ..PXDA..5QD..lHQ..fkDE..........D.......bODO....EA...XD.....+A........vA....DUlYgUGazA..........B....L.f...XoA......PDD...3OoA.........5..............3OA....D....P.....L....L.f...PK........9C...fP...ABA..fHD..PhP...PBA..DID...mP...cBA..DKD..XrPK.......fBTf...f.EH...DPAB....Tf...f+DH....P.........9y..B..fI.......fZP..fqBI........3OAN.f...XXA......nFD...3OXA...rW5X9yUSBmZ+7fSL9Sk7b3Onm1Z+HjfB9C5z52OtGuf+Dx9E9iFSi1OAUMb+bYHx8yGde3OhmRj+z93Q8iooB3OYQkh+HDkI9iJ2g1OEuwV+DzTJ9yXGJ0OuNzk+LIbl8Cx7A4O4zLl+b7h58iBMs2O3KNl+ziVV8iZqq2Oimma+rNrC9i7k83OW7Eb+38sI9yEKD4OVhtb+3iVx8Sx+T3OU8af+zr6M9i29Z1OI4Bc+3PuO9StTo3OoW2g+7M6l8CDYP3ODXmZ+TTAF9ilbl2OYUHS+.MOE9SQ3s2O.y7g+7eAm8iCfl1OI0qZ+.qIn8y45v3OxBQi+PaRN9imAh1O6TkW+HQ1E9yr6G2OwzMY+Pmkt8i22l3OfLtr+rvHp7i73uzOKkqW+vt7X8CuuX2OU10a+.GJC9SxDL3O5k4f+vCzs8SPMB2OFO0f+v7t.9ykyv1OvoVf+Pq6f8iRQL3OC.H...E..nGQA.........v..B..PA..5QT........f+.....v..B..PA..vIT..............9y..B..PA..vIT..........D...............zLyL2ayLybOA...................+B...7C...3OC.H...z........pAA..vID..fsPC........9if.....L.f...XB.......nFD..3pPB.........Pf...f+L.f...XB.......nFD..3pPB........9Sf...HBM.f...PH.......nFD...oP...pBA..zJD...rP...yBA..XKD..HtPH.........ff...f+P....DP...v.A..fDD...TP...f+L.f...PC.......nFD...mP...1BM........3OBN.f....C.......VLD..f7P..fEDQ....f.....C....L........3OB....AL.....A....L.f...XB.............3OB.........P....f+L.f...XB.............3OB........9SfC.H...DA.........XxjI4i+98yO...f+P..........AB...9SfC.H...l..............9i..........DH.....MyLS9....................7S.....MyLK.M.f...XB.......nFD..3pPB........9Sf...f+B...7y..B..fI........bP...jBI........3OAF....P.....A....v....vPu41XkIGcffTXrwlA....hMFZgwFa...v.A..vED...3OMyLi+.....fBWOBO.....nYlY3C.....MyLS+...uND...3O...f+D....fA.......f+....9y..B..fkF.......QP...f+jF...vv0i1OLhT358iET35g+....9y0iB2OeT3Z+fT358iYlY3OJb8f+v0iB9CRgq2OrGEd+PgqG9CtdT3OyLyb+fT358iYlY1OjBWe+PgqG9yv0i1O...f+Lb8H9SyLy3OT35g+PgqG9SAjBWe+v0iB9CRgq2O35Qg+7QgK9yGEt3OALb8n8yv0i1OEfqGE9yiBW2OWOJb+v0iB9iBWO3OJb8f+jPb8n3OT35g+fT358y0iB2OtdTX+nYlY8iT350OtdTX+rGEt8ydT31OmPJb87Cov02ORxES+b8nv8yiBW2OjBWe+XOJb8yGEt1OyLyb+ziBW8Cov02ORVCV+nv0C9iYlY3O6Qga+Lb8n8yv0i3O35Qg+PgqG9CWOJ3Ow0ih+7QgK9Cov02OMyLi+LyLy8yiBW2Ob8nf+Lb8H9y0iB2OMyLi+35QA9iYlY1OyLyb+PgqG9C...3OyLyb+fqGE9Sb8n3OMyLi+zLyL9CgC.H...z........pAA..vID..fsPC........9if.....L.f...XoA......PDD...3OoA........vjJb8H85fBWORO.....7nv0yqBWOZOJb8n8pv0ivaJb8XOov0i8B.....6QgauJb8H87nv0ySyLyTOrGEt8xdT31aAMyLy8nv0ivSJb8XuJb8H77nv006iBWWuBnv0ixK6QgaurGEt8hA.....ov0i89nv0ySyLybuJb8H7pv0izSyLyTuOJb87B....viBWOuJb8n77nv00SyLyTuOJb889nv00iBWOROov0i8zLyL2KLHWbuJb8H87nv0yqBWOBu.....nv0iziBWOROF.....PJb8XufoVN8nv0ivyiBWWOJb8H7pv0iv6EJb8n7nv0i1SJb8XuOJbc8nv0ivC6QgaOMyLS8zLyL2aJb8XuMyLS8nv0izqBWOJuMyLS89nv00SJb8XuOJbc8zLyL0qBWORuMyLS8nv0izC6QgaOov0i8zLyL0SyLyTODF..........A........7C....PC........9C...3O...f+L.f...PC.......nFD...mP...1BM........3OBN.f...PC.......nFD...mP...1BM........3OBN.f...XoA......PDD...3OoA.......9CzEtdD+HflYl0O...f+....9Ck...f+....9yA.......f+DWOJ5iYlY1OMyLy+nYlY5CB..............................................v..B..fkF.......QP...f+jF...vvgvwOeLyLy7CEtdzOrEqE+HrGr6SlYlwOov0C+35Qg7SEAEwOWlVF+PqMK7CDvCvOidgF+PbDo6CPhOvOJbHL+DJ1L7CvIutOFdx393cNG7ymnoyOys4G+zIjH7iZowwO4nHL+.DRK8yICpwOfT3Z+H.Lx7iszMyOyBNK+bh3u7yIh+xOA1bom7iQz9aS+HPDD9CcejxOig1G+3WFo8yN2DxOfcaF+rshT7yYnJyOeNtL+rgJg7SjVEzO9m6Q+j2Ad8CYOjxOinsA+L2le7SBBzxOBtiQ+TvSx7iRXczOAV+U+bQHE8SI.00OsXAh+LUeJ8iWM+vO4KmP+Hj6e8yXLTyO9oTY+rnMy8SAs+0Ozpmf+7IZ57yFCd7Oye2s+jMUs8CtWy0OfwoX+PpW.+SLA95OmIvt+X2i69y7aB8Oaoe2+vdnz+CdQV5O1kEu+vI9m8CTMf2OKwXn+LY8g9yZ774Oq88h+PRn89yPIW6OLPrU+jr9f9SPCx2OuE6s+DA268yDn47OYfnm+XlYl9S35Q6OyLyr+ziBW9SOJb6OJb8v+L.f...PC.......nFD...mP...1BM........3OBN.f...XXA......nFD...3OXA.......9yo1ZMf+zgDxD3OMidf+rBQB9CheJ3OCY0f+X4AD9StCS3OPoOg+LmdE9iBsW3Ooetg+PpmG9CKOf3O7BKh+b2YI9iSwn3OrSsh+f.IK9SAmu3O.2Ii+nhQM9idT03O.2Ii+b5hK9ytlj3OyoWg+zpyB9isVC3OH79e+fv6+8Cg...f+v3..B..fgE......fZP...f+fE...P6CA3OlXAt+8yz8x2On2be+TVw98ypd72O+7ke+PDE98CQ132OaR5e+DrH+8yEAB3OXUMf+vZO.9C6D62Old.f+fCK.9iiQ52OCvce+z9h98yBc62Oa70e+DaK+8CiTB3OR+Kf+ng1+8y5x12OCSne+31d98SHP.3Oyg9e+vOd88SMu22OBWle+7tp+8SZY72O474e+....9SwNA3OE6Df+DXYp+2Of.BK+8SPnA3O1I1e+vmo98C1I12OXrAf+....9S1W82OwA3e+fch88iXm32OXiFf+fyr+8iGq32OAwqe+3n4+8CIy22OrSre+LlL88ioAC3OHPOf+v6E.9C.Hq2Ojo8a+3I1g8iHvZ1OvkcZ+Pa5t8SwNw1OE6Dc+L1I18SmXm2Ochcd+HPwNw2O...f+....9CAvhHe+TrS.9ich82OE6Df+TrS.9if1I1e+DH6D62OA....jF.......QPC.H...1g.............9yg.........S.........f+.........DP...P.I....Dv...n.C..fBbf...f+b....3u...P.A....D....v...f+B...AL...DP...P.UA........n.C...9C..........A...9C....P...f.A....D...DP.....A.........P...f.A..fBD...DP...f+B....L...JP...v.A..fBD...JPL....BL...Nv...f.C........3u...f+....CD....P...f+....9K....P...P.C...A7B...v.C...9C..........A...9C...3u.....A...AL...3O.........9K...3uA.....L....vL..........v...n.C...9K....P...f.A........JP..........D...3O...f.C...BLA.....C...9K...DP..........Pf...f+D.....P.....M....3O...P.C...9K...3uI....AL...Pv...P.C..fBL...HP...n.A...BD...3O...f+B...9qB.....C...9K........3.C...AL....v...n.C....L...Dv...f+....9SA.....A...9K...3O...f+B...BL...HvG...fBL...Hv.....C........LP...P.A...AL...DvA...fBL...JvD....AL...Jv...f.C..fBL...RPC.H...1g.............9yg.......f.EH....PD....9C...DP.....C..fBL...JvAB...9y....f.A...9K...DP...P.I....Hv...f+B...9aA...f+....AL...Lv.....A...AD...DPAB...CTB.....C...AD...HP...P.A..fBD...HP...P.C...AD...3u...f+1.....v.....A..fBD....P...f+....AL...Jv...f+B...AL........P.A....D...3O...f+b.....P...f.C....L...Pv...f+B.........P.....U.....v...f+....BL........f+B...9KA.........AL....v...f+B...9aA...P.C.........P...f+...........I.....L...3u...P.A....L...Hv...f+B....L...Dv...f.C...Bbf.....H.....v...f+B...9qC...3.C....L...Pv.....C..fBL...Dv...P.A....D...JP...f+.........Jv...P.C...BL...HvE.....L...Hv...n.C...AL...Hv...f.G....DP...P.EH.....D....AD...3O..........L....vE.....D...3O...P.C...BD...DP...P.Q....HP...n.C....D...DP...P.M....Hv...f+B...AD...DPA.........SPC.H...1g.............9yg.......P.I....3u...P.A...ATf...P.G....Jv...n.K.....v...P.A...AT....f+....9SB...f+B....D...HP..........L...Lv.....A...AD....P.....M....HP...P.A....D....PH....9K...3O...P.A..fBD...HP...P.C...CD..........X....HP...P.A...9K....v...f+....AD...DPN.....D...3O...P.A...CD...3O........fBL....v.....A...AD....P...P.A...9C....P.....I...........C....rD.....A........3O...f+B...9C...3u...f.A........DP.....A...9C........P.A...9C....P.....C....D...3u...f+d....JP...P.A....D........P.A.........v.....q....Jv...P.C....L...Hv.........9C........f+....AL...3u...f+V....Hv.....C...AL...3u...n.C..fBrB.....C..fBL...Dv.....A...AD...Jv.....C..fBL...3u...n.C..fBrf...f+X....Hv...n.C...AD...Hv...P.C...BL...HvA....AL...DvB....BL...Jv...n.KH....vA...fBL...TPC.H...1g.............9yg.......n.W....Hv.....C...AD...3u...n.C..fBrf.....w.....v...f+.....L........f.A...9K...JP...n.C....D...HP...f+.....D....PAB....b......A....jB...P.A...9C...JP...f+B....D....v.........9C...DP...P.C...ArA.....C...9C...HP.....C...9K...3O...f+DH....vD....BL...3u.........9C...3OAB...9af...P.G....3u...f+J....Dv...f+B...9KA.....C...9K...Hv.....C....LA...f+B...9C....v...P.C...A7......A....L...3u...f+p.....v...f+....9K...3O........fBL........f+....AL...Hv...f.G.....v.....G....Hv...f.q....3u...f.A....D...3O.....A...BL...3O...v.C..fBL...Hv...f.GH...DvE...fBL...3u...P.A...9C..........L....Dv...f.A...AD...DPE.........Hv...f+B....D...DP...P.AA...3O...n.A..fBL...3u...P.A...CL...DP...f+.....D...3u.........CD....P...f.A...9C...HP...TAM.f...XGB............3OGB........P....f+....9y....P.A...BL...Jv...n.GH.....G....9C...LP.....A....L....P...P.A..........B.....D...3O...f+b.....P...f.A...9C...DP...f.A...9C...JP...n.AA...DP...f+B....L...3u...f.A...AD...3O...f.C..fBL...3O.........9C...HP...P.A....D..........r....Nv...P.C...AD....P...f+.....D....v...P.A....L....P...P.C...AbB...f+B........3u...f+.........HP...P.A.........P.....g....Hv.....A...AD...3u.....C...9C...Hv...f+....9y......C...9K....v.....u....3u...v.C...AL...Hv...v.C...AL...Hv...P.A....L...LP..........f....P.C....L....vD....BL...Jv.....A...BL...HvZ....AL...Hv...f+B....D...DP.........AD....P...f+B..fBL...Hv.....C....D....v...P.A....D..........A...AL........P.C....L...Dv...f+B...BL....v.....i....HP.........9C....v...f+.....D...HP...f+...fEz..B..fcH............f+bH.......HvD..........P...P.A..fBL...JvAB....PB...P.A...BD....P...f.C....D...JP...f+B..fCL....P.....EH...DPF....9C....P...P.A...9C...DP...f.A...BDC...f+B....L........P.A...BD...3u.....C...BL...3u...P.A...9C...DP...P.Y....3O...f.A...9K...Lv....AC...9K...3uC....AD...JP..........P....f+B...9aA...P.A...9C...Jv...P.A...9K...3uA.....D....PN.....L........f+....9K........f.A....D....v.........AL...DP...n.A...9K....P.....EH...3OD...fBD....v.........9K...3uM...fBL...Dv...f.A...CD....P...f.A...AD...Lv.....C........Jv...P.C...BL...HvF....AL...Hv...P.C.........P...f+B...96..........9C...Jv...n.W....Dv...f.C...9K...3O.....A....DB...P.A..fBL...Hv...P.C...BL...Lv...f.C....L....vD.....D..........A...9K...3uG.....D...DP...f+B....D..........C...9C...WPC.H...1g.............9yg.......n.S....3u.....A...AD...Jv...n.GH...DPO....BD....P...P.C...9C...HP.........BL..........A.........P...f.A...9C....P...P.A...ADB.....A...9C...Hv...n.C...CD...3O...v.A...9K...3uF..........P.........CD....P..........fA...f+B....L...Hv...P.A.........P.....U....3u...P.A...AL...3u...f+....9yB.....C...9C....v...f+B.........P...f+....AD...3u..........L....vM.....D...3O.....A...9K...HP.....C....D...3O...P.C..fBD...Hv...f+....AL...DvG....AD....v...f+B...CL...HP...n.A...9C...3OE....AL....P...P.C...9K...Dv...P.SA...Jv.....C...9K...Nv.....A........DP...f+B...AL....P...n.C...BL...Jv.....C...9K...DP...f+.....D........n.C..fBb....f.C...Bbf....Aa....Hv.........9K....P...f+B...9C...3OJ....AD...HP...P.C...9K...3O.........9K..........C...AD...XPC.H...1g.............9yg.......P.S....3O...P.A....D...Jv...n.G.....P.....c....HP.....A...9K...DP.........BL....P.....U....DP.....A...9C...DP.....A....j....n.A....D....PI..........v...f+....AD....P...3.C..fBL....v...f.A...BzA.....A...AD...3O.....A...AL...Jv...f+B...96A.....A...9C...3u...f+.....L...3O..........v....f+.........3O...f+D.....P.....Y....3u...P.A...BD...3O...P.A...9C...3OC.........3O...f+B...9qB...f.C....L........v.C....D....v..........L...Hv..........Pf.....q....HP...f+B...BD...Lv..........L...3u.....C..fBL...Hv...f.a....Dv...v.C...9K...3O...P.A..........M.....L...Dv...f.C..fBL...Dv...f.C...AD...3O...n.A....D...3u.....C...AL...DvI....CL...3u...P.C........3O.....A...9K........f+....9Sf.....EH.....A....9C...3OBB...Ab....f+....9S.........HFz..B..fcH............f+bH.......DPD....9C...HP...f+B..fBL...JvI....AD...Jv.........AL...DP...f.A..fBL........f+....9CA...f+B........HP.....A....j....n.A...BD...HPJ....9K...JP...P.A...BD...Jv...3.C........DP.....A...AD...DPF....BD...DP.....C...DL...3u...f.A...BDA.....A.........P...f.A...BDA...v.C...AL...3u.....A....j....P.C..........AB....Tf...f+f....DP...f.A...9K...Dv...f.C....D...3u.....A....TA.........BD...JP...n.C...9K...3uF.........3u...f.A...9C...DP.....A....jA...f+B...BL...3u.........AL...3u...f+d....Hv...P.C...BL....P...f+....AD..........DH...3OA...fBL...JvH....BL........P.C...9C....P.........AL...Jv...n.KH...HvB...fBL...3O...f+D....3u...f+V....Hv...f+....AD....v...P.C...Abf...f+J.........f.C...BbA...P.C...BL....v...f.C...AL...DvA.....L...YPC.H...1g.............9yg.......n.S.....P...P.A...BL...Lv...v.K....DP.....A....jA...f+....AD....v...f.C...9K...3O...f+3....HP...f+.....D...3u...f.A...CD...3O...f+B...AD...JP........fCL...Hv.....A....T....n.A..fBzD...f+....BD....v...v.C..fCL....P...P.A...BD....v.....A...9C...JP...f+B........Dv...f+.........Hv...f+B...9aB.....A........3O...f.A....D...LP...f+.....D...3u...f+FH.....Y....9C........f+B....L....P...P.C.........v...f+B...AL...HP...v.A....D...3u...f.C....L...3u.....C...BL...Dv...f.C....L...Dv...f+B...BD...HPK.....D........f+B...AD...Jv...f.C...9K...3O...P.A....D...3O...f+7....Jv...v.C....L...Hv...n.C...BL...Dv.....A...9C....P.....C.........P...f+.....L....vF.........3u...P.C...9K...Dv...f.C...Bb....P.C...Arf...f.I....3u...P.C...Abf...lAM.f...XGB............3OGB.......Bz..........BD...Jv...n.m....DP...P.C...9C...Dv...P.A....D...Lv...f+.....D....PH....9C...HP...P.A....D...HP..........L....P.....U....3O...P.C....L...3u...f+....9yB.....A...AD....P...P.A..fBL...Dv.....C...AD...3O...P.A....D....PAB....Pf...f+X...........A....L...3O..........D....PD.........DP...f+.....D....PO....9K...3O...P.A...9K........P.C...9C...Jv...f+B...AL....v...f.C..fBL....v...n.A..fBDA...v.A....D...Hv...f+....9iC...f+B..fBL....v...P.C........Lv...P.A...9C...HP..........L...3u...P.A..fBL...JvH....9K....P...f.A..fBD...DP...f+B...BL...Dv...P.G....Jv...n.G....Dv...P.i.....v...f.A...9C...3u.........9K........f+B...9KA...P.C...9K........f.C...B7f...P.GH...HvB....AL...Hv...f.W....Dv...f+.....L...Dv...f.C..fFz..B..fcH............f+bH.......DPAB...BT....n.C..fBr....f.A...AD...DPAB..fBj....f.C....D....PA....AD...DPAB....j....f+....AD...DPC....9C....P...P.A...AjA...n.C...AL...3O...n.A...CD....P.....c....HP.....C...AL...HP.........AD...3O...f+L....3u.....C..........B....9C..........DH....PN....9C...HP.........9C...JP...f+B...9C...DP...f+....AD...3O...P.A...9C....P.....AB...3O.....C....D..........A...AD...3O...n.A...9K...DP...f+B...9C....P...P.C...9K...Hv.....C...9K....v...P.A....D...JP.........9C....P...n.C....L...Dv.....A....L....P..........f....n.C...BL...HvS.....L...Nv...f+B...9C...Dv.........BL....v...f.C....L...3O...f+B...BL...Dv.....C....D....v...f+....CL...LvD....9K........n.C...CL...LvC....BL...Nv...v.C...C7A...3.C...BL....v...f+B..fBL...Lv...n.C..nFz..B..fcH............f+bH........vC....9C....P...n.C..fBbA...f+...fBD...Dv...f.A...AL...DvA....9C...3OAB...ATC.....A...9K....P...f+....9K...LP...P.A...CD....P...f+B...AD...LP...f+....9CD...P.A...BL...Lv...f.C...BD...DP...f+B....L...3u...f.A...9C...Dv...f+B........Dv...f+B...9qC..........D...3O.........BD........f+.....D...Dv.........9K..........A...9K...3uG.....L........v.C....L...Hv...f+....AD...DPE....BD...3O...v.C........Dv...P.e....Hv.....C...AL...Lv.........AD...3O...f+v.........f+...fBL...Hv...P.C........3u...f.A...AD...3O...f+B....L....vE....BL...Jv...v.C...BL...3O...f+L.........f+B....D....PAB...AjA...P.C...9K....v.........BL...3u...f+9....Jv...P.C...9C...3u...P.C........Dv.....A.........P.........9K........f+.....D....PC..........P...f+....9C...aPC.H...1g.............9yg.......P.Y.....P...f+B..fBL....P...f+B....D....PI....9C...Dv.....A...9C....P...f+....AD....P...f+....9SA.....C..fBD...DP...f+....AL...Dvo....AD....v.....A...AD....P...P.C.........v...f+B.........P...f.C...9C...3u.........AL...3O.....C...BL....v...n.A...9C........f.A....D....v.........9K....P...P.C...9C....P...f+....BD...Hv...P.C...AD........P.A....D...LP...v.4.....v...n.C.........v.........CL...3u.....C..fBL....v...P.A....D........f+B...9qB.........BL...Dv...f+....9K...HP..........D...Hv.....C....r....P.C..fBL...JvA....AL...DvAB...9CE........fBD....P...f+B....L...DP.....C...9K...3O.....C...CL...3u...f.C...9K....v...P.C........3u.........9C...3OA.....L....vD....AD....v.....A..........G.....D...3u...P.C..fBL...Dv.....C.............tAM.f...XGB............3OGB.......Cr....P.A...CL...LvG.....D...HP...P.C...BD....v.....A...9C...3OAB...AjC...f+B..fBD...3O.....C..fBD....P...f+B...AL...3u...P.A....L...DP...f.A....L....vB....9K...3O...f+HH.....i....AD...3u.....A...AD..........C...AD...HP.....A...AD...LP...f+.....D...3u.....A.........P...f+B........LP...f+....CD...3u.....A..fBD....P...f+B...BD....P.....C....D..........C...9C....v.....e....Jv...P.C...BL........P.C...AD...3O...f+D.....P.....E....Jv...n.2.....v........fBD...3u.....A........Hv...v.C...BL...Pv...v.C..fBL..........D....3O...f+L.....v...P.C...AD...DPA....9K...3uM....AL...3O.........AL...Hv.....C...AL........f+B....L...Dv...f+....9K...3uA.....L....vF.....D...3u.........9C........f+B...9q....P.C...9K...3uD.....L...Lv...f+B....L...bPC.H...1g.............9yg.......P.EH...LvF...fBL....P...P.A........3O.....C....rJ...f+....AD...3O.....C...9C...HP.....A....L....P.........AL....P...v.A...9C...HP.....A...9C...Jv...v.C....D...HP...f+B........3O.....C........Dv...f+....AL....v...f+B........LP...f+.........JP...f+....AL...3u...n.C....L...3O...f+.A...JP...f+....BD....v...P.A........Hv.........9K...LP.........BD...DP...v.C.........v.....K....Hv...P.C...AbA.....C.........P...f.A..........AB..fBLA..........L...Hv...f+....9Sf...P.Y....Hv.....C..fBL...Dv...n.C...9K...3uC...fBL...DP...f+B...9af.....L....Dv.....C..........T...fCL....P...f.C...9K........n.C....L...Dv...f.C...9K........P.A...9K....v...f.C...9K..........A...9K...3O...f+HH....vB....9K...3O...f+L.....P.....C...AL..fbPC.H...1g.............9yg.......P.EH...LvG....BL....P...P.C....D....v...f+.....D....PF....9C....P...v.A...BD........f.A...BDB........fBL...DP...v.A........HP.....A...AL...DvB....9K....P.....EH...HPT....9K........P.C...AD...3u...n.A...9C...DP...f+.....D....v...f.A...9K........f+...fBL...JP.....A...9C....P.....o....LP.....A...9C...3u...P.C........LP...f+....CD...3O...f+X.....v...f+....9K...Jv...P.C...9K...3uJ....AL...JP...P.A...9C...DP...f+.........Jv...f.C..........B....AD...3O...f+DH...3uA...........D....9K...Hv.........BL...HvK....9K...3O...P.A...9C...3u...v.A...BD...3O...P.A..fBL..........L....Jv.....C...BL...HvG...fBL....v...P.C..fBL....P...P.C...CL...LvA....BL...HvBB...CLA...f+....CL...3u...v.C...CbA...f.C...CL...Jv.....A...CL...LvAB..PGz..B..fcH............f+bH........PU....BD...Jv...P.A....D...Hv...P.A...AL........f+....AD...JP.........CD....v...P.A...CD...Dv...n.C....D...LP.....A....TA...f+....AL...3u.....A...9C...3OAB...Ar......C...9C...3OL....9K....P...P.C....D...HP.....A.........P...P.C........DP...f+....9iC.........AL...JP.....C...BD...3O.........AD........P.A....D...DP.........9C...3OA...........R.....L...Jv.....C........Lv.....A........HP...f+.........DP...f+...fBL...Hv.....A.........P...P.A...ATf...P.G....Lv...v.G....Jv...n.K.....v..........ff...f+V.....v...f+...fBD...DP...f+B...96A...P.C...9C....P...f.C...9K...Jv...P.C...Ar....f+B...AL...DvF.....D....v..........L...Dv.....C....rf.....D.....v.....GH...DvIB..XGz..B..fcH............f+bH.......3OL....BD...Jv...P.A....D...DP...f+....AD....P...f.A....D...DP..........vA.....A...AD....v...v.C....D...DP...f.A...BjB...f.C...CL...JP.....A...9K....P...v.A...9K...3O..........vB...P.C...BD...LP...f.A...AD..........A...9K....v.....A..........U....9C....P...f+....BD........f.A........3O...f+B....D...LP...f+....AL........f.C...9C...Hv...P.C...BL....v...f+B...9q......A...AD...DPB.....D...3O...f+D....Jv...n.O....DP...P.C...BD...HPV..........v...n.C...CL...Hv...P.C...9K...Dv.....A........3O...f+B...AL...3u.....A........Hv...P.C...BD...3O...f+B...CL...Lvg....BL...Jv.........AL........f+B...AD...3u.....C..fBL...3u.....C...AL........f+B.........v.........CL...3O...P.C....L...Lv...n.C...BL...Dv.....C..fBL....v...P.C....L...Dv...f+B..fGz..B..fcH............f+bH.......HPD....AD...Jv...f.A...AD...DPV....9K...DP.....A...9C....P...n.A...BD...3u...f.A...CD...3u.........BD...DP...f+..........v.....A...BD...DP...f.A...9C...3OAB....7....P.A...BD....P.....w....HP.........CD...DP.....A........DP.....A........LP...f+...........L....BL...Dv...f+....CD...3u...v.A...9K....P.....C...AD....v.....A....T....f+....9CB...f+B...BD....P...f.A....D...DP...n.C...9K...3uA.....D....PA....AD...DPC....BL...3u.....C....bf...f+xA....v...f+.........DP...f+.....D...HP...P.A....D........f+B...AD...HP.....C...AL........v.C....L........v.C..fBD...Lv.....C...BL...Dv.....A...AL...Jv...n.S.....P...v.C....L...Lv...v.WH...HvA....CL...LvB....AL...Lv...v.GH...HvC....CL...3u...v.C...Crf...5AM.f...XGB............3OGB.......BrD.....C...CL....v...f.C....D...Dv.....A..fBD....P...f+B...BD...3u...f.A...9C...Hv.....A..fBD...3O...f+L....Hv...f+...........C.....L....P...v.C...CbA..........L........f+.....D....PD.........HP...f.C...9K...3uQ.....L...3u...P.C....D...Nv...f.C....L...Hv...3.C....D....v...v.A...AD...3u...f.C........Hv...f.W....Jv.....C...BL...Jv.....A....Tf...f+z....DP...f+....CL...Dv.....C....D...JP...f+....9K...Hv...3.C..fBL...Lv...v.K....Jv...P.C...Abf....AO.....v...f+B....D....PK.........3u.....C...9K....P.....C...9K...DP.........9C...Hv...f.O.....v...f.A...AD...DPK....BL........f+....BD........f+.....D...DP...v.A...9C...3u...f+9....Dv.....A........Dv.........AD....v...f+....CD...DP...n.A...AD...HP.....A..fBD...JPA....CD...LPA...fBD...ePC.H...1g.............9yg.........Y....Jv...P.C...AD....P...P.C....D....PE....9C..........A........HP...f.g....Hv.....A...9K...DP...f+....AL....P...P.A...ADA...n.A....D........f+B...9aA...f.A...9C..........A...AD...DPK....9C....P...v.A....D....v.....A...BL...HP...f+B...AD..........f....3O...v.A...BD...JP..........D..........C....bC...f+.....L........P.C...BD....P...P.A...9C........P.C...BL...Dv...f+B...96B...f.A....D....v...f+....9K...Dv...f.C...AL........f.A...9C...3OG....BL....v...n.A...AL...DP.....C....D....PD.....L...3u...f.C...AL...DvE....9K...Dv.....C...9C...3u...f+Z...........C........Hv...P.C..........G....9K........f+....AL....v...f.C...AL...DvB....BL....v.....G....Dv...P.K...........C....7A...f+B...AL....v...P.C...BL....v...P.C...ALg...9AM.f...XGB............3OGB.......9yD...n.C...AD....P...P.A...CL....P...f.A....D...LP...f+....AD...JP.....C...AD...3u...n.A....D...Hv...f.A...BDC...f+B..fBD...3u.....C...9C....P...f+B...9C........v.A...9C...HP...f.EH...LPG....AD...HP...P.A...BL...Dv.........CL...LvF.....D...JP.....A...BD...3u.....A....T....P.C...A7A...f+B....L...3u...n.A...AD........P.A...Aj....n.C....L....vAB....fA...P.A...9K....v.........AL...Hv...f.O.....v...f+...........D....9K........f.A..........A....9C...3OC.........3O.....C....7A...P.C....L...Jv...f+.....D...Jv...f+B...9a....P.C...Ab....f+B...9KB..........L..........C...9C...3u...f+.....L....vBB...BLC...f+B...CL...3u...f.C..fBL..........C........3O..........L...Jv...n.q....Hv...3.C....L........P.C...BL...Lv...3.C...CL...Nv....BM.f...XGB............3OGB.......CrD...3.C....D...3u...P.A...9C........f+.........JP.....C........Lv...n.C....D...3O.....A...BL..........3.....v...f+....BL....v...P.C...AD...Hv.........BD...3u...n.A....L...3u...P.C...AbD...v.C...AL...3O...f+B....D...3u...n.C....D...3O.....C....D...Dv.........BL....v...f+.....L....vB..........P.....IA........f+B....D....v...v.C........HP.........AD...3u...v.C........Jv...P.C...BL...Dv...f+B...BL...HvE....9K...3O...P.A....D...3u...f+FA....P...f+....AL....v...f+B....L...Hv...P.C...9K...3O...f+B........Dv.........9K...Dv..........fA...f+....9K....v...P.C........3u...f+J.....P.....C....r....P.C....D....PE....9C....P...f+.....D...3O...f+PH....PBB...9S......A....zg...ABM.f...XGB............3OGB......fBjA...v.C...BD...Fv.....C........DP...P.EH....PA....AD...DPn.....D...JP.....A...AD...Hv...P.A..fBD...3O...f+B...9C...HP.....C...9K...3O...f.A...AD....P...n.A...9K...DP..........D....v...v.A....L...JP..........D...3O.....A...CD...Dv.....A...AL....v...n.C...9C....v.........AD...DPAB....z....f.C...AL..........H....3O...f.A...Bj......C...BL...HvF....AL...Jv...f+.....D...3O...P.A...AzB...f.A....D..........A...9C...HP.....A...CD...3O...f+B...AL...DvG....9C........f+B....D...HP...f+.....D....PAB...96C...P.C....L...HP...P.A....D...3O..........L...Dv...f+.....L...Dv.....C...9K...Jv...n.G....Hv...f.G...........D....Hv...f.KH...JvF....AL..........C...BL...Jv...f.C...BLg...n.G....Hv...f.KH..ffPC.H...1g.............9yg.......f.I....Lv.....A....jA...P.C...9C....P...f+...fBD..........H.....v...P.A...AjD...f+B...CL...HP...v.A....D...DP.........9C....P.........9C........f.A..fBD...DP.....A........3O...f+7....3u...f+....BD...3O...f.A....D...JP...f.A....D...DP...f+.........Hv...f+B..........C....AD..........A....TA...v.C...AL...3u...f+....AD...DPI.....D...Dv...f.C...9K....v...n.C.........v..........P....P.A...AjD.....A....L...Hv...P.A........3O...P.A....L...3u...n.C....D...Hv.....A...AL...3O.....C...9K....P.....o.........f+....AD...HP..........L...Dv.....C...AD...3u...f+V....Jv...f.C....L...Hv...P.C...A7....f.C...AL..........DH....vAB...Abf...f+F....Dv...P.OH....vB.........Dv...P.mH..vfPC.H...1g.............9yg.........U....Qv.....A...AD...3O.....A....Tf.....b.....P.........BD...3O...f.A...BL....P.....I....JP...P.C...ALH.........AD...HP.....A...BD........P.A....D...DP.....A...CD..........A....L...3u.....A...9C...LP...f+.........JP.....C...9K...3O...f+B....D...HP..........D........n.C...9K...3uB....BD..........bA....v...P.C...9K...Hv...f+B...9C...DP...f+B...9C....P...n.A...9K........n.A........3O...f+B....L...Hv...f+B....L...Dv...n.A..fBzB.........9C........f+....9K...DP...f.A...AD...3O.....A...9K...3uB.....L...Jv...n.G.....v.....GH...HvC..........P...f+B...9q......C...BL...HvE.........Jv.........AL...3u...f+N.....v.....A..........C.....L...3u...n.C..fB7....v.C..fBL...Lv...v.O....Hv...v.C..fCL...NvE....CL...Jv...P.C...CL...Pv....AGH...gPC.H...1g.............9yg.........XA...Pv...f+.....LMyL2u...v.A...9K...LP...f+B...AD...Jv.....C...9C...Dv...f.A..fBD...HP...P.C..fBL...3O.........9K...DP...P.k....JP...P.A...BD...DP...f.A...9C...Lv...P.A....L....vD.....D...DP.....A...9K...3uE....AL...Hv.....C...BL...DP...P.Q.........f+....AL...3u...f+F....3O...f+DH...JvE....AL........P.C....L...Dv...P.2.....v...f+B...AL...JP.....C...BL...JP.....C........Lv...P.C...CL....v.....u....Hv...f.A...9K...3O.........AL...Hv...f+B........HP...f+....9iA...f+B....D....v...f.C..fBL....v.....y.........v.C....L..........A...AD...3O.....C...BL...3u.........9C...3OD.........3O.........9C...3OA.....L....vA...........A....9C...3OCB....j..........9C...3OAB...9af.....X....3O...f+B....D...3O.....A.............EBM.f...XGB............3OGB.......BjBlYlg+B..fBD....v...f.A....D........P.A...BD...3u...P.A...AjC.....XlYF9K....P...P.A...CD...3O...P.A...9K...DP.....A..fBD...HP.....A...9C...3OD...fBD...HP...v.A...9C...3OD...fBD...LP...f+....AD...DPM....9K...DP..........D...DP...n.A....D...HP...f+B...AL...3u...P.A..........A.....L....vP....AL...Hv...f+B...9C........f+.....D...JP...f+....9K...DP...f.A...9C...3u...n.C...9C...3OK....AL....P...P.C...9K...Dv..........D...3u.....A...9C..........P.....P...f+B........Jv...n.WA....P..........L...Hv.....A...BD...DP...f+B....L...Jv...f.C........Lv.....A....L...Jv.....C....D....v...v.C..fCL...NvJ....DL...Hv...P.C...BL...Dv...v.C..fCL...Dv...v.C..fCL...NvA...PDL...QvBB...Ab....DAC..PDb...........fg...FBM.f...XGB............3OGB.......ADE...f+B....L...Hv...f+.....D...JP..........D..........A..fBD...Hv...P.A..fBL...LP.........9C....P...P.A...9C...3OBB...96....f.A....D...3O...f+L.....P.....C....D....PF....9C....P...f+.....D...DP.....A....zD...f.A...9K...DP.........9K...3O...P.A...BD...Hv...f+B...9C........P.A....D...3u..........D...DP...f.A...BT......A....zC.........9K...3O...f+B....D...JP...f+....9K....P...f+....9K....P...P.A...BD....v.....a....3O.....A...9K....v...f+B....L....vE....9K....v.........9C....v.....a.........P.C..fBL...3O.....C...BL...HvBB....b....f.C...Brj.....zH..vgPC.H...1g.............9yg....ZlY9+bA..........A...BD...JP...f+.........HP...f.C...CD...JP...v.C...AD........n.A...AD...3u.........AD..........C...AD...HP.....A....TA...P.A....D........n.A...9C...3OE....9K...3O.....C.........v.....W....DP.....A....L...Dv...f.C...BLA...f+B....L...Jv.....C....bf...n.i....Dv...f+B...AL...3O.....C..fBL...3O..........vA...n.C...CL....v...P.C...9K...3O...f+B...9af...f+L.....v.........9K...3uO....9C...Dv...f+....AL...Hv.....C...9C...3u...n.C........3O.........9K...Dv...f.C...Bb............A...f+B........3O..........v....f+B...9C..........D....3O...f+DH...3uB.....L..........D....3O...f+DH.....A.....D....PA....9C...3OA...........RB..fHz..B..fcH............f+bH.........K....AD....P...P.A..fBD........f+B....D...3u...P.A...9C...JP...n.Q.....v...P.C...9C....P.....Y....LP.....A........HP...f+B..........F....9C...Dv...P.A...CD....v...........A...f+....AL........f.A...BDA...f+B..fBL...Hv..........fC.....A..fBL...Dv...f.C....L...Hv.....A...9C...3u...f+....9K...Dv.....C...9C...3OL....CL...Hv...P.C...9C...3u...P.C..fBL...DP...f.C....L...DP...f+....9S...........fD...f+B....L...3u...f+....9K...Hv...f+B...AD....P...f+B.........v...f+....9K...3O...P.C...BL....v.....GH...3uBB....f....f+B...AL...DvD.....L...3O...f+B..........C.....L...3u..........vl...IBM.f...XGB............3OGB.......B7B.....A...9C...DP.....A...CD....P.....C...9K...3O........fBD...JPF.....D...DP...n.A....D...DP...f+....9CA...P.C........Hv...P.C...ALB...f.A..fBD........f+.....L...3u.....C...AD...DPBB...BLA...P.A..fBD...3O...........B...v.C....L...Dv...P.A....D...3u.....C..........AB...BT....P.C...ALA.....C...9K....v...f.C...B7B...P.C...9K....v.....A....L...Dv...f+....BL...3u...P.C....L....vBB...9a...........PA...f+....AL...3u.....C...9K...3uA.....L....vD.........3u.....C...9K...3uD....AL....v...P.C....L....vBB...9a......C....7f...P.G...........zI..fhPC.H...1g.............9yg........Ay....DP...f+B....D...3u...f.A........JP.....A...9K...JP...f+....BD...HPA.....D....PC.........3O.....A....Tf...P.m....3u.........CD...HP.....C....D...3O.....A...AD...DPBB...BLA...f.A....D...HP.....A....T....P.C...AbA...f+....AD........v.A...9C...3OD....BL...DP.........9C...3OA...........D....BL...3O...f.C..........L.....D..........A........Jv...f+B...BL....P...P.C...BL....v...f.C...Bbf...P.GH...JvB.....L..........L....3u...n.C...BL...HvA...fBL...JvH....BL........n.C...BL...Jv...f.C..fBL...Hv...f.KH...JvA...........iB..rHz..B..fcH............f+bH.......RvU....9C...Dv...n.A...9C....v...f.C...9K....P........fBD....v...f+.....L...HP.....A...AD...3O...P.A...9C........f+....9Sf...f+1.....P...v.C...BL...Dv...f.A...AD....P.....C........DP...v.A...AL...Jv...n.i....Dv...v.A....D...Hv...P.A...AL...3O...f+B...9q..........BL...HvC..........v...f.C...Br....f+...........F.....L...3u.....A....L...Hv..........v....n.C....L....P.....M....3u.....C...9K...3uF.........Hv.........9K....v..........f......C...9C...3OBB....Pf...f+J....3O.....A....Tf.....nJ...iPC.H...1g.............9yg.......DAO....Hv...f+...........J....AD...3u...P.A...AL........n.A...9K..........A...BD...HPAB....DB...n.A........Jv.....C...9K...Hv...n.C...CL...LvA.....D....PV....9K....v...f+B...BD...3u.....C....D...Dv...n.C...AD........f+.........DP...P.C.........v...P.C.........P...f+....AL...DvR....BL....v.........9C....P...f+.........Hv...n.C...9K...Dv.........9K...Dv...f+.....L........f+....9S......A....TA...P.A........3O...f+B...9C...3OC.....L..........A....Dg...P.E...........zJ..PiPC.H...1e.............9ye.......3.K....Dv...P.A...Az......alYF9K...HP...f.EB....P...P.C.........P.....C...AD...3u...f.A...AD...3O...f+B.........v...f+.....D...Dv.........9K...DP.....A...9K....v........fBD...Hv...n.C..fCL........f.A........DP.....C...9C...3OG....BL...Jv.........BL...3O.........9C...3OA....9K...3uE.........3O...f+B........Dv...P.i.........f.C...CL...3u.........AD....v..........vB...P.C...9K...3O...f+B........3u.........9C..........C..........C.....D....v...........q...NBM.f...X+A............3O+A......PD7......A...AD...3O...f+DH....PA....9K...3uH...fBD....P...f+....AD...JP...P.A....D...JP...n.w...........A...9K...HP...n.C........3u...f+.........Dv...P.A...9C...3OA....AL...DvAB.....E.....C....D........P.C....D...Dv...f.C...AD...3u.........9K...Hv.........AL..........A..fBD...Dv...f+B..fBL...JvF....AL...DP...f+B........Hv...f+B...9qA.....A...BL........P.C....L...Hv...f.G....Dv...P.K.....v...P.C...A7......C...AL....v.....GH.....tB..7Hz..B..f8G............f+7G.......LvA....AD...DPN.........LP...f+B...CD...DP...f.A........DP...f.A..fBD...HP.....A..fBD..........PA...3O.....A...9C...3u...P.C....D........f+.........3O...f.A...9C....v...P.C........3u.........9K...HP...P.C...ArC...f.C........3u.....A.........P...f+....AD...3O...n.C...AL...Hv...f+B..........D.....D........f.C....L....vA....9C...3OE.....L..........C...BL...Dv...P.GH...JvA....AL...DvB....BL...Jv...n.O....Dv.....C..........wB...Iz..B..fwF............f+vF.......LvC....9C...HP..........PA.....A...9K...DP...P.C....L....vZ....9C....P...f.A........3u...f+....AD...Dv...f+B....D...Dv.....A...AD....v...f.C...AD...Dv...v.C...9K...3O.........BD...3u.........9C...3u...f+9A........f+....AL...DP.....A...AD...3u..........L...Dv..........L...Dv...f.A...9C........n.C...9K....P.....C...9C...3u...P.C...9C........f+.....D........f+B....D...3O...f+DH....vA...........hB..DIz..B..fwF............f+vF.......NvJ.....L....P.....C...AL...HPzLyb+B...AD....v...f.C....D....PA....AD...DPAB....vB...v.A....L...Dv...f.C........3u...f.C...9K...HP...f.C..fCL...NvC.........Hv...f+B...9qA.....A...AL...Lv...3.C....L...3u...f+N....3O.....C...9K...3uM.....L...Hv...P.C...9K....v...P.A...AL....v...n.C...9C...Dv.....A...AD...DPB.....D...3O...f+DH....PB...fBD...DP...P.EH...HPAB....vo...RBM.f...XrA............3OrA........LC...P.C....D...IP...P.C...BD...DP.....A........DP...n.A...9C..........X....3u...P.A...AL...DP...f+B....D....PAB...Az....f+....AL....v.....m....Dv...f+B........DP.........AL...Hv..........D....PK....9K...DP...f+....9K...3O.....C....D...3O.....C...9C...Dv...P.G....3u...f+FH....vAB...Bbf.....K....Hv.....C....bf...P.KH.....qB..LIz..B..fYF............f+XF.......3OA....BD...HPH....AL..........C...9K...DP.....C...BD...3u...f+dA...HP.....A...CD...HP..........D...LP...f+B........HP...n.C....D...3O...f+B...BL...3u...P.A...BD........f+...fBL..........C....r......A...AL...DvA....9C...3OP.....L...3O...f.C........3u.....C........Lv...P.C...9C........f.C....L...Jv...P.C...CL...LvB....AL...Lv...v.G...........bJ...kPC.H...1U.............9yU.........g...........C...9iYlY3O...f+....9K........f+....9SA.....A...BD...3O...n.A..........I....BD...JP...f.A..fBL...3O...n.C....D........P.C...Abf...f+Z....3O...f.C...9C...Dv.....C...BD...HPF...fBL..........C...9C...3u..........Pf.....O....Hv.....C..........C....AL..........C....7A...f+B....L...3u.....C...AL...3u..........vl...UBM.f...XWA............3OWA.........A.....A...BD....P...f+....9CH.........9K...JP..........D........f+LyLCAD...Lv...v.A...BD...DP...f+B..fBD...Jv.........AL........f+....AL...3u.....C...AL....v...P.C...AD...Dv...f+.........3O...P.C...9K...3uAB...Ar....n.C...9K...3uAB..fBrB...f+B...AL...3u...P.C...9K...Jv.....C..fBL...Lv..........fm...VBM.f...XVA............3OVA.......AbBlYlg+B...9C........f.A...9K....v...P.A...9C...3u...f+BA....P...f+B....D...HP..........D...3O.........BL..........C..fCL...Hv..........L...Dv...P.W...........C...AL...3u...f+....9yC...n.C...CL...3u...f+....AL...Hv...f+..........v...P.C........3u...f+.........3u...f+J.....P..........Pn...WBM.f...XQA............3OQA.......AbK.yLS8....CL...Dv...n.A....D....v...f.A....L..........A...CD...3u...P.A..fBD...DP...P.C....L........f+B....D...Dv...f+B...9C....v...P.C....L...Hv...f+B...AD...3O.........9C...Hv.....C...9C...Hv........fBL...3u.....C........3u.....A...9C...3u...f+F............J...lPC.H...VS.............9SS....PyLy8tflYFHP.....C...9K...3O...P.A....D...3u.....A...AL...DP.....C....b....P.A...AzA.....C....D...Jv...f+B...9C...Jv...f+....9S......C....LD...f+B...9C..........C...9C...Qv.....C...AD...Dv...f.C....D...Hv...f+B....L...3O..........Pf...f+L.........f+...........cB..jIz..B..fED............f+DD.......3uH....BD...3O...P.A...AL...3O...P.A.........P.....EH...NvA....AD...DPB...fBL..........z....3u...f.A...BL...DP.....C...BL........f+B....L...Dv...f+B....D...Jv...n.q....3O.........9C...Dv...f+B........Dv.....A...9K...3O...f+H....HP...........k...ZBM.f...XAA............3OAA........bA.........9C...3u.........9C...3OQ...fBD....P...v.A....L....P...f+.........Hv.....A...BL...Jv...P.A...9C...3u...f+.....L...3u...f+J....Dv...f+B...9KB.........AL...3u.....A...9C...3u...v.C..fBL...JvE....AL...Hv...P.C..fBL..........XI..vlPC.H...FP.............9CP.......n.U....3O........fBD...DP..........Pf...v.s....3u...P.C.........v...n.A...BL....v...n.A...9C........f+B...9a......C....b....f+B...96C...f.C..fBL...3u...n.C...BL........P.A..fBL...3O...f+B.........P...f+B...9C..........bI...mPC.H...VN.............9SN.........UfYlY3O...f+pYl4+K........f+....9SD...P.C........3OZlY9+.....D...3O.....C...9C........P.C...AD....v...P.C...BL...3O.........9K...3uE....AL...3O...f.C........3u...f+J....3O...P.C...ALA..........L...3O..........fj...cBM.f...X4.............3O4.........vH.....A...BD....v...f.C...9C........P.C....L........f+...fBL...Hv.........9K........P.A...CL...3O...P.C..fBD...3u.....C...BL...DP.........BL....v.....A........3u.........CD...HP...n.A..........TB..3Iz..B..fYC............f+XC.......DvC.....L...3u...f+....9S...........vD...P.A........JP.....C........3O........fBL...JP...f+B....L...3u...f.A...9K....v....AC........Hv..........vA...f.C...9C....P...f+....9K....P..........vj...eBM.f...Xy.............3Oy........AT...........f......A...AD...DPX.....D...Hv.....A...AD...3u...f.C........Hv.....A..fBL...3O.....C...9C...Dv...f+.....L....P.....C...9K........f.C...AL........f+....9S...........fj...fBM.f...Xv.............3Ov........9Sf...P.EH...3uA.....L....vF....CL...HP...n.C...CL...3O...f+B...96C.....A...9C....P...f+....AL...3O...P.C........Dv...f+.....L...DP...f+B...AD....P.....E............I..HnPC.H...1J.............9yJ.......f.EH...JPF....9K...3O...n.C...AD...HP...........B...f+.........3O...f.C...AL....v.....A...BL...HvA...fBL...JvH....9C..........C...9K...DP...f+B....D..........zH..PnPC.H...1J.............9yJ.......f.Y....vO...f.C....D...DP.....C...AL...DvAB....r....f.C...9C...3OAB....f......A...9K...3uG...fBL...Dv...f+.....D...Dv...f+....AD...DPA...........OB..FJz..B..fgB............f+fB........PC....9C...3u...f.A...BzB.....C...9C....P.....C...AD...Hv.........BL....P...P.A....L....vC.........Jv.....C....r......A...9K...3uB.....L..........zH..fnPC.H...lI.............9iI.........I....DP...........A...P.C...9K...HP.....C....bf...n.u....3u...f+....AD........f+B........3u.........AL...3u..........vi..fhBM.f...Xi.............3Oi.......fAz......A.........P.....c....Dv...P.A....D....v...P.C...AD...Hv...f.e....3O........fBL...Nv...P.C...BL...3u...f+J.....v..........vh...iBM.f...Xh.............3Oh....7+++Bz.7++++....Br+++GP9++e.of+++CP...f+....BL...3u...fzB....T....v...f+H...9K...Hs...fzN.....v.........9K...3uA...........LB..NJz..B..fAB............f+.B...PyLyEPB....9C...3u...f+F....3O...f+X....DP...v.A..fCL...Dv.....C...9K...3uH.....L...Hv...P.C...BL...3O.........9K..........nH...oPC.H...VG.............9SG.......f.o...........A....L...Hv...f+....9K...Dv...f+....BL...3u...f+F.....v.....a....3O..........L...HP...P.A..........HB..RJz..B..fwA............f+vA.......DPL....9K....P...n.A...BD...Dv.....A........Dv...v.C....L...Lv..........Pf...n.O....3O...f.C..........HB..TJz..B..fsA............f+rA.......3uAB...A7A...f.A...9K........f.C....L..........C....7....P.C...9K..........L....3O...P.A..........HB..VJz..B..fkA............f+jA.......3uN.....L...3O.....A...AD...3O...P.C.........v...f+B...AL...3u...f+.........3O...f+D...........bH..foPC.H...FF.............9CF.......P.E....3O...f+z....Hv...f+B...CD....v...f+B....D...Dv.....A...9K....v.........9K..........bH..noPC.H...lE.............9iE.......f+d.....v...P.C........HP...f+.........3O...f+P....3u...f.C...9C...Hv...f.G...........XH..voPC.H...VE.............9SE.....yLS8H....Dv.....C....r....f+B..........G....9K...DP...f+B........3u...f+...........FB..dJz..B..fQA............f+PA.......DvAB....DB...P.C...BD...3O...f+B.........v...f+B...9C...3OB....AD..........TH...pPC.H...1D.............9yD.......f+HH...DvA....9K...3uG....BD..........C....D....v...P.C..........EB..hJz..B..fIA............f+HA.........AB...9q....f+....AL...DvA.....L....vA....9K...3uAB....fg...oBM.f...XQ.............3OQ........9iA.........AD...Jv.....C........3u...f+FH....PB....BD..........PH..XpPC.H...FD.............9CD.........M....3O.....A...9K...3uC.....D...3u..........f....f+...........DB..nJz..B..f8.............f+7........3OD.........3O...f+B..........E.....D....v...f+B...9C..........LH..npPC.H...lC.............9iC........+HflYl+u...........A...f+.....L...3u...f+....9S...........vf...qBM.f...XM.............3OM.........LB...f+B...BD....v..........L...3u.....A..........CB..tJz..B..fw.............f+v..........H....9K...Dv...f+.....L....P...f+B....D..........HH...qPC.H...FC.............9CC.........gvLyL.v...n.A....L..........C...9K...Dv..........ff..frBM.f...XK.............3OK.........Pf.....I.........f+B...9q....P.C..........BB..zJz..B..fo.............f+n........3uGPyLy8K....v...f+.....D........f+B..........AB..1Jz..B..fo.............f+n........DPF....9C...3u.....C...BL...Jv..........ff...tBM.f...XI.............3OI........9iA...f+B....L...3O.....A...9K..........DH..nqPC.H...VB.............9SB.......P.M.....P..........L....vAB....ff...uBM.f...XH.............3OH........BDA...P.C........3u..........ff..fuBM.f...XH.............3OH........9aA.........9C....v...P.A..........AB...Kz..B..fc.............f+b........3uE.....L...3O..........D.............BKz..B..fc.............f+b.........vD.....D...3O...f+B..........AB..DKz..B..fc.............f+b........JPD.........Hv...P.C..........AB..FKz..B..fc.............f+b........3OA...........B....9K..........DH..frPC.H...1A.............9yA.........S.....P...f+B...9C..........DH..nrPC.H...1A.............9yA.........D.....v.....G...........HH..vrPC.H...1A.............9yA.......f+N....DP.....C..........BB..NKz..B..fc.............f+b........3OAB....b...........ff...zBM.f...XG.............3OG.........fg..fzBM.f...XG.............3OG........9y....f+B....D..........HH..PsPC.H...1A.............9yA.......P.O...........A..........BB..VKz..B..fc.............f+b........DPB....BL..........LH..fsPC.H...FA.............9CA.......f+J....3O.............nsPC.H...FA.............9CA.......f+J....3O.............vsPC.H...FA.............9CA.......f+H....3u.............3sPC.H...FA.............9CA.......f+H....3u..............tPC.H...FA.............9CA.........I.....v.............HtPC.H...FA.............9CA.........L3rRzcOC.H...TE.......pAA...GD...dP...5AA...HD..ffP...FBA..jHD..PiP...PBA..LID...lP...bBA...JD..fnP...jBA..XJD...pP...pBA...KD..fsPU....LoLQ9y.Cxwi+HzmQ9yjxD4OSJSj+HXJK43OALoLQ9yjxD4ODjxRN9y4.t3Oorji+bNfK9y4.t3OAtJlW8SfHEZQ+HvpkkxOveR69D..........A....LyLy7iYlY5OA.........P.....yLyL+XlYl9S..........D....vLyLyOlYlo+D..........A....LyLy7iYlY5OA.........P.....yLyL+XlYl9S.............vKD.....N........7SyLybOMyLS9....7i..........L.f...RA........9C.....C.H..fT........f+P....f.....C....P....P.....A........9C...3OA....D....P.....A....D........3O.........BD..PqPFA....v..B..HE...............L.f...RA....................L.f...RA...............C....b....P..........3.....D.........jBWO1C...3O.........7K...mP.....................................................L....fB....A.........fC....P.............uP.....MyLy7C....P..fkCA....vLyLyO...f+...VTD....PyLyL+....AD...............v.....J....D..........N.....A............HBA........3O.....A..fJD...7u...v.A...9C..nWQ.....A...7C...DP................A....D........3O...PAC....v.....C.........P.....E....P....P.....C....XOJb.TqGE9O...v+...gML.....C....T........3O...bBC...KL...rv...vBW....fTI0YN.....................T...............................D..........D....D....v........H.oLyL8C...7O...MBA....v.....E.......vIL...3O...vBC...KL...rvE.........fTI0gN................E...............................A..........A....A....L.....zQgqOcT3p+jBWO9CNcMtPeQ+gCU....PA.......HAC...GL...mv...bBC..vIbA....WbaT4.....................PA..............................P..........P....P.....C....7Qgq6iT354Oov0i+...hKD..HqvE....T........bv...HAC..vIL...mv...bBW..........RkTm4................T...............................D..........D.........v.....35Qw+ziBW8iqGE9O................E.......vIL...mv...bBC..vIL...mvE...............................E...............................A....................D....v.....RgqG+vdT35qYlY5O...jAA...............D.........."
										}
,
										"snapshotlist" : 										{
											"current_snapshot" : 0,
											"entries" : [ 												{
													"filetype" : "C74Snapshot",
													"version" : 2,
													"minorversion" : 0,
													"name" : "Pianoteq 8",
													"origin" : "Pianoteq 8.vstinfo",
													"type" : "VST",
													"subtype" : "Instrument",
													"embed" : 0,
													"snapshot" : 													{
														"pluginname" : "Pianoteq 8.vstinfo",
														"plugindisplayname" : "Pianoteq 8",
														"pluginsavedname" : "",
														"pluginsaveduniqueid" : 1349793905,
														"version" : 1,
														"isbank" : 0,
														"isbase64" : 1,
														"blob" : "40722.CMlaKA....fQPMDZ....A.Ec3DG.HD......f3TVfLEckkla2EVdfPDHCwVXyMWZiEFa.........3o0PImUKYB..H.VFQETF6I..n....fLvHCMu.CNuHSLW.....UZg41azUVbffiKw3BLuHCLxLCL0DSM6Zjf2tL6OiiRhCJzlg3ftSFarEVgdB..zQFcM0PE..vE....NkEHSQWYo41cgkGHDAxPrE1byk1XgwF.....G....zzajElbzQmP....TgVZyABbxU1bkQGHuYlYkI2bfDFHBEDHsk1Xo41Yf.WYxMGbkMFcoYWYfbWZzgFHgAxXrE1byk1XgwFHy8VctQlK.....PT...vE....NkEHSQWYo41cgkGHDAxPrE1byk1XgwF.....xQA..bjTUUE...fA....AL.vMQkbqA..TvE.+KfFffTX4QlafzBHS8lagQWXfjlafbDHsElZuI2PvNjdBNCfxjSGfdDGX.4QAIGr.MBI.UyI.0yI.8yI.EjI.QD.CwmI.gjI.wD.C4mI.8TI.A0I.E0I.IUI.M0I.QUfV.jUp.zUQ.JRbTAr.ckAPhjLe.KPWoAnJwwBvBzTH.oRBI.fGcRGvBTRn.zNC.HR87Ar.MxCfNDG..nR+X.n6vQA2vAAPNjQFriMB.KP.P.j2fSM.tCO.LTQDbSOCx.n6vgA2vwCPtiN..5PbH.j2TyCCETO.tiP.LzPHbSPAZDnEwQEPVjPLAXQ.AAnGwADPdzQTApLb.PQbX.Ob7.jxXi.EkD.7nyG.dDPVvSPFHSOAlVQ+vAnCwADPNDQkA3P2b.nxvgB7vQCPJyMGvSMF.ZQbLAjEIjL.JSP.viPBtCnGwgB.VzNH.4QAEHH.djOc.5MbnvPb7.j2bB.ftCGD.4P7PwNvbDr.oBH.tCPF.KP9DAf2ziDvBjPN.3P.cAr.czI.wzI.E0I.UEI.k0N.skfG.TVl.DUn.zSl.jSp.TSf.DSm.TRk.zPk.jNn.jJl.D.lLDTB.JRb..Sbr.jHgDALEUEvND.N.HREIXEf5DGW.oS+..fLkCKf9DGW.4SIACnGwAEPdDP..pRb.AjJcD..9TPB3zOjbzPWnTQCd.nHwg.EwACPhDPBTjPP.6PQ3AfEIjKvNTElLDFnLzFeMjGm.pRb..rCABEPpjMB.HR2v.rCQBJCkh.fxDGU.ISCEArCsBH.pTOF.6PrDAnCwwCGwA..xTP..4PCY.rC0RBPdTQY.6PwX.fCMTHvNDNC.3Q.IBrCwyIC4CJC4iRC8iICEDICMjICQDJCQzCfdDGR.4QKY.rCYDHfBDGE.6PLI.n7vABPBjQMvyMN.6PUMAfG0yCfVDGE.6Pd4.jEIzEvNTYO.5Qb.AfEAD.fdD..bDGG.6PtEAjGIzEvNzclLze+.HOmX.nEwwCPVDTI.3QA4EnCwA..VDPS.4PLMAn8vwDP1iPM.HP.gSOAMHBCYSCfpDGX.oR8L.nBwAA9vQDP5SNFHDLpAnO1L3CvBDIb.pLbf.r.Ei..JjLT.oLn.Ar.kiI.wSD.JSNW.KP9XBPAYBPCYBPGYBPJUBPLcBPOIAfJoSEvBTU.Ljdj.zW.LjXj.TX.LjPl.jS.LDFH.pRbrfObP.jJkE.fJDGH.oOQMfPNQ.r.IC.CAvI.A.E.5CQ.HjQCtBnBwAB9vAAPJjSE3CR0.nPFAgOCEXNJsyAfxDGP.ISJMCnNwAB.xzPG.oSMsFnLwQBPxjVa.nS.o.n9vA.CwwCP5CPVLjPR.HS+vwPCkgO.M3.fNDGL3CG.vDGC.4PKofOHA.SaUCfCUDBLMzB9Hzfh.5PbTPRbr.jC4D.IgkAfBDGH3CGG.IPCgfOAsAfCcDG.MDAvBDOI.nO+zAr.AkH.k0I.0UfX.jWl.TXr.XRrXDr.4UIfNDGB.KPY8.jC0iAfBDGC3CGDnDGI.KPSY.j.Ai.9TC.J8yGvBzSM.3PBw.P8r.r.szA.5yOe.KPGoBPCU.nLwgB.pzNJ.ISC0.r.8CJ.sCAf5DGS.oSHs.r.oyI.gCCf9DGR.4SMkAfL8CAvBTLm.D.a.ZTb7.jQUkA.5TPH.pObHfPbz.jBoz..9DQ..oO7v.fQkDKBUzD9.jfrApObffPb.PTb7.j9zC.Qok.BEzJ.FEQHHTPS3CPCJAn2vgBPdSRB.pOb.vTbz.j9DD.Sc0K.dCQ.3CPT.KPcTBP3bBP+XBPAYBPEYBPKYBPScBPWUBPXkDfS0i.vBTUh.JVbX.r.oj.f5CGFbCGA.IVUYfOGIvMEUAr.wSF.dCPG3SPF.KPoHBP.rAnVwwCPZUTi.6PUXxPY7.nUwQEPVERH.6PczBfX4iKfNEGQ.4TK0AfV8CHvNDHd.XU+f.rCMhICkB..NEPW.ZTbz.rC4h.f5CGF.YT.8fO5.Ar.IB.CESI.5iO..KPy.vPwbBP6fBP+.vPxXBPCAvPzXBPFAvP4XBPJAvP5PBPLYBPM4DPLAvP6LBPJAvP7LAnUwwA.FUOH.YUGQ.r.YD.C8CAf5CGO.oO+LAr.ID.CIzEPdiIO.KP7.vPFMAf9Dj.fNEGQ.4THA.r.cC.CkzF.diHK.KP0.vPKYBP0.vPKQ.fU0CBfFEGQ.YTFk.r.MC.C0TG.NEPH.KPv.vPQQBPs.vPUk.nOwQEP9TS..XT+f.r.kB.CoEJ.cB.C4kI.YB.CM1G.9jPG.KPi.vPqcAn9vg.4vQCvBzG.LzbB.oO+XPN7P.nNwQEP5DQF.KP..vP6UxP+UAfNIzfI.pSbbAjNMjAf1CGI.nOyf.j87yL.5zPJ.JSbDAjLcTO.xDQ2.pSb7.jNQ0afxDGP.ISLkAfN0yR4zCG83CBLADAfpDGS.oRKc.n9vwDP5CN6.nO8LnPfJCGa.oLrrCfJYSgJHCI4.pRbLAjJoSf4.KPhTBPuvCP3XBP7HBP9XBP.YBPCwBPFYBPIYBPLcBPMMBPOcBPQcBPQ0DfJYQMfxDGY.IS2jDr.A0Af1DGY.YS5b.r.4zH.sjI.YjH.xTOD.KP9P.fM8yDfRDGM.KPvH.jD8DIvBDHN.pObb.MbH.fDUjBP5yKEPSKB.KP.vCf9XSBzXifSAJQbP.MbbfObX.jDwzCzPC.9nCS.5yOBPCPePjOAhBnEwgEPVTQ.A5Qbb.fEATCPdzQVAJMb.PQbr.Obn.jE0j.zbCB7bCS.dTP.viOIPSNA5VQ8PAnDwQDPRzSxAJMbrvNb.Aj63y.znBCfVDGT.YQFQ.fDsyI6HTBz3SfiUDO0.5QbDAjGcTN.djQKAZNbvAj4zxEfdDGT.4QBMHV.dzNy.ZKbn.RbTAjsPhAH8RDvBzJO.XNvTAr.ciI.0CJ.AjI.MjI.cTH.hzKA.KPKYBPMoCPOcBPPcBPPQBPM4AfsjBBvBzPe.JRbb.r.ACAflCGD.IRB8PN77.r.APfmAHRg.CnLwAEPxjPmAZQb.AfL4y.PVzQ..XNzHBn1vAEPZiMAtBfEA..PVjDqAJRb7.jHQD..VzNvYyNe.5Qb7.jGYkBfdCGS.HR8D.j2fSf7A3Q9jAnJwwCPpTRAN.nCwgCPNjSH.nR9z.nuvgEP9BMJ.3MvHHGvNjdL.5QbH.fC4CDPdzQJ.6PoYxPaQxPOcxPAcAnEwwCPVjR..6PvPAfG8CCfBCGF.6Ph7.jvfSEvNDGb.3KjHCrCAhICIhICQhICYxI.VTO..6PnnAnHwQCvNjJF.IRGEBrC8RICgSICETFfBDGB.HL+r.rCoj.PBDSG.HR4X.nwvwEPFSN..6PRYxPWgxPccxPlUxPxcxP8QxP+AEnEwQEPVjQO.HP9bVL1LCnxvgCCwwCPJCLBLDQ..XQ7LnWxPxCC4SFfJDGOXBGD.oPzbgInPDr.YyF.ZhMK.KP.cBPEAvPtkBPJAvPOMBPOAvPxXBPTAvPbXBPXAvP.XBPaYBPeUBPicBPpcBP+IEn4vQCPliTD.nPA0.r.UkI.QCJ.APfkATIl.DLl.TNn.jOl.TPl.jQj.TSn.jUl.TWl.jXk.TZl.zeUAXN9n.n6vwCPtiQCAJObDAj7rjL.tCOV.KPQcBPjb.nxvABNwAAPJSWI3DXK.KP.f.f7HjLxTzf3.pLbj.jxrUM.JCRBFAnOwQDP9jRr.nS7r.nQwgDPF0SPA3SBABnBwgAHwABPJjXGfjTU.XTA8CR.MnKfhDGN.IRP0BfHgTfqA5Pb7.jCgTD.JDOk.ZQb7.jEEkF.NzOLAJOb3.UbP.j77zATYFA.VTPBlGU8..nXwwCPhUSAl.fXIDCfFEGO.YTLInF.FUOh.JUbbAjTQTGvBjIl.zMi.DPb.pSbH.fT8yAvBzQH.oSM8Ar.4TC.xiNd.KPTcBPaAvPQTBPmAvPTbBP+8.fNA..f5DGg4ze..6PWzAnQwwDPFUSa.6PZTBPe0AnNAfBvBTS.LTGl.DQE.pRb3.jJ0TDvBjP.LjHF.XT8HBr.UD.CchI.gD.C0hI.sD.CEiI.4D.CQCI.AE.CUyI.IE.CciI.ME.CoCJ.QE.C4SCf5DGO.oSNo.r.QE.CQDI.4D.CwzF.pDOK.KP.AvPXcAnOwwC6vA.vBDJ.LTZD.4SNsvNCkBr.A..C0GG.5zNK.6P+w.f6DTf88DPH.pRbDAjJczV.pTNk.JObTASbH.j7bSCLwDK.xSPARFS9rAnHwQDPhzPzAHR9TAnGwgDPdTTd.pOb7.j97i..dTRChCnGwgCPdTUX.pLbDAf9vi.PJCP+.ZQbf.fG8SBPVDPv.XQAQBnGwwEPdDQeAZQbDAjEwTI.dDPgA5Mbz.j2Tj.fNDGQ.4PTA.fEoCBx3CK2PDgI.5Jb7AfCADAPtBIE9EfqPCKfpDGW.oRyTFr.ghH.cCJ.0yI.8SI.EzI.QDI.cjI.wjI.8TN.IkI.UkI.YUf+.zUn.JSbTAfJgBAPxDNJAZSbXAjMkyFvBjUm.HS2..r.E0I.Yj..1zOW.JQbn.r.oiAPRDQN.pObH.Mb.Aj9Pi.vBzIE.IMtzAfDMDAvBD.V.nO5v.M2HXefRDGDPCGD3CGI.IQD8.My.fO13CfDIzA93CBz7Sf4.ZQbTAjEoyM.VDPB.5QbLAjGMzYfVDGDPCGKvCGA.YQZY.M63.O93AfG4CE7HjBz.TfZUDO4.JQbDAjDwjdfVDGS.YQNA.nzvAA6vA..RzOQ.IM4.vN9LCf6.TFz.TfIUzMy.5QbTAjGgzM.dTQAFAnGwwA4vgEPdDNWjiDCREfGkiIfhDGMzBGP.IRvb.r.UBCP1RIa.KPvbBP4jAf4jhCvBTOl.DPl.zPl.zQl.TRl.DSl.zSZ.HRpv.r.EkI.MkI.E0I.oTBfhDGP.XKoT.jHwSBflCG..KP93Bj4rhBvBTLl.zKj.jLl.TMl.zMn.DNl.DNW.pRb3.r.gyAPpzOe.KPzz.fHcSDfxDGH.KPrz.jLsj..pzOW.KPdXBP.n.nEwQA.lCMH.pMbb.jEkDC.xzOD.oM0PDr.AxI.MRI.QxI.YxI.chM.VTLU.KPlnAnHwACvBDIH.IRI4Ar.EhI.A...ZyLn.5QbHvMbDAjGAEA2rCB.hDPBVBnHwQEPhDPG.3QdvCnJwQDPpTRE.HR6jDnuvg.CwwDPNzR.7ROH.3M5bgR97Gr.4gH.ARafdDGG.KPcP.fCkCBPdDRa.KP.TFnvvg.EwgIPBCP.TDTW.3Q+jwKvHnBEgyBfhDGS.IRFIEfv3SHfFCGI.DGO.YL3..PEI.fH0ifcAZQb7.f.ECBPVjOLAXL6XBnxvABCwA..VjNO.oL2.vPGM3I.JSKTApPbz.fCwCBPJDOK.pIbTAjl7RGvBzJl.TOG.nI67Ar.EjJ.UjI.oDJ.ME.CEFI.oE.CcSI.AF.CAvN.Q1I.k1I.A2H.8Wfz.ZNbz.j4DlB.JTPY.KPaUBP6bBP.LXa.AhI.IhI.QhI.cxI.kRI.sxI.4xE.liOG.5Nbj.r.MiAPtyQe.KP5XBP+jAn7vQCvBzPB.IOLQBr.Yj..tCPj.KPDEBnxvgAvBjJG.oLaA.nNwwCP5DXO.KP.H.f7HDLxHzfDApLb7.jxvzO.JCQBd.nOwwEP9DQs.nS8H.nQwQDPFkTVA3SAkAnBwA.HwwCPJzXBfjVd.XTAgBRAM3LfhDGM.IRVQEfH4SfX.5PbHAjCYzV.JTOO.ZQb7.jEsTH.NTP2.JUbX.Obb.jT4EB7jjI.VzOBVEUA8.nXwADPhUSAV.nQwA..hkPO.YTMQEr.8BI.oCJ.8iI.EDI.QzI.F0M..KPE4AnTwQBvBzPF.IUL8Ar.oiI.EBJ.A..CEwGf5DGG.KPpX.jNYkG.R0OB.KP7.vP.TBPCUBPIAvPQbBPOcBPXcBPfIBPkAvPTXBPZY.fNUiHvBDQ.LzEB.ZTbDAjQszDvBzIm.D.i.zIm.TN.LTFD.pRb3.jJ4DEvBTPG.HO7PPT9jAr.cD.CwgI.8jI.gEJ.UlI.IGI.8GUfxDGO.ISHkCnNwADP5jSE.nR73.r.AF.CMhI.MD.C8RB.xzO..5Sb.wNbD.jOcEC6PD.vBTG.LDPl.nSAA.r.A..C4DH.tCQF.6PYcxPjcxPvgyP4YxP+sEnJwwDPpzPdAnR6fvS1TBn7vgDPxiP..JSbTAjLQTK.xSQApBS.YDnHwwDPhzO+.HRE0CnGwwCPdzRg.pOb7.j93C..dzQCFDnGwADPdzRI.pLbPAjxDTKfVDGB.nO2TAjE8CF.dD...5QbDBfEITGPdDIzAZQbz.jE8j..dTPANPQ+3.nCwQCPNzTD.5Mbv.j2DzE.JyOsbyPD1CnqvQFPthKB.3P.U3QqvCUf9DGZ.4S5D3UvBDIm.zKl.TNl.TOn.zOj.jPl.TQl.jRl.zS3.jTm.TUk.zUl.TVl.jVl.zVKAzVm.DWAFAnQwwG.9TKF.YTj.EnRwQC.F0MJ.oT8XAr.oEI.MkI.kzI.JUO..KP9bAnJwAA2vACvBTLB.oREgvMrzAr.4AH.pTPG.KP.T3FfZDGDnDGQ.oQ2HfR9D3CvBjIl.jLn.jNm.TOk.zOk.TP6.zPh.3MfP.r.UDJ.cjI.kDI.ozEfJCGS.oL3HBr.czH.AjI.ACJ.8gI.ghI.YCI.0iI.EzI.QzJ.cjI.oDLfhDGH.nR9j.jHADBvBzQD.nQgj.nEwQFvBTRC.YQubAfH4CCvBzSa.XQ6r.r.gkI.40I.MVI.c1RfhDGA.KPj4.jHIzEvBjVf.pRbf.r.sTA.hzPH.oR9jAr.ciI.A.K.JSMQ.JRbDAjHkDAfNCGDTDGK.nR+f.jyLyAEYC.vBzGn.jMl.TPm.jRT.XQ9HAr.UE.CgmI.QF.CYFI.8G.CgkICcDJC4hICA..++B.PI2bUgVh..PR....J....LGckkla2EVdtkG.....a....bjbg4FYfLEckkla2EVdfPDHn3TY2ARVuI2Zo...........vI2as8F...P.....A....D....fB....yQWYo41cgkma4A....vF....GIWXtQFHSQWYo41cgkGHDABJNU1cfj0axsVJ...f+X...............................PkQ+++++C....................fb4EFaP....H...............7+++++ar81bQ....D....P.....FA..........A....D...............D...............D...............D...............D.....C....C8laiUlbzABRgwFa.....D...............D...............D...............D....................v..B..fkF.......QP...f+jF....alYBPP.5++6KiYl8u.2LS9POyL9CfyLyOHlYF+.JyL6KoYl8O.2LS9.kYl8CVyL6OZ....QB..9CfYloO.yLS+BZlY5KnYlouWg0Ly9CvLyrOTlYN.yiYl9Kn++uu.Lyr+hLyL+KIyLCv.tLS9h+++9K5gH5u.1ta9BhCg8CpIm4OHfG..AXBV1C.DjjOPWB8+hnzm9K.hQsuf7.R+.f90xKTIz1ufOfD+.7t69C1nF5OT9Rn+.5Lr+CPa3mu.XTC+B.T54CZtovOjbW++f0Vr7C1x33OzA15+hPyr7C3oOoOnzwY+.xP79C3FGwu3WK3+xKhP.TrOIHPTwVr+.3Ly7Ctpe8O.I5s9hvY18iqYFHPDalm+vzL6ADjYF+ufVlY+Rclw+CXl4CPh..A.ATyL7CfkYhu.Yl0+BzLS5K.yL6uHlYf+BfYl4Knyr6OJLy..q0LO.Dil4.P.jl48.LyL8KxLy7uZ....ALyL6CnYlwuPyLi.AkYl8inYlEPXlYl+BbyL4CIyLCvXlYl+BxLS.LhYlEvjYlI.iLyL+KIyLCvTlYN.O....P...............v.....................C....................L....P.....A....D........3O.....D..........afWT9L.f...XXA......nFD...3OXA...D4Tk7yUi86H+r1Ym7SA3ZxOQzvI+vkhm7SQXrxOeYqJ+3QDq7ikvqxOty7J+LBks7Cu.9xO.f5K+P14w7Cd0CyOyUfL+r6Xy7yP6XxOcvVG+zenb7yJfhxOgPyL+XIVy7CYeQyO6E9M+nXH37SKmuyOL3ZO+H4F87igO0yOUUaP+TyIC8SQUTzOTwXQ+v6EG8idUpzOF1GT+HyQT8S.nn0OWmvW+nFRi8yTOh1OpFCb+zPky8SOsn2Oo0Je+3X2A9CFYQ3O0Hpg+zLfH9SDjn3O6PAj+fsDT9ieYi4OEv0l+PuTf9yWYP5OVvSp+zqvr9y7kD6OI1Ts+zXV59i7H36OYOqu+nalA+SI7E7OVNxv+Ta0D+SpNY7OHUTx+XhrJ+iVXs7ORCHy+.aHO+iXbA8OwdVz+L9FQ+i5gB8OWKWz+TmJP+y6.D8OhkDz+.BZP+i.RB8OUkLz+HiQQ+ineC8OA..................n.C..fBD..XqP.....L.f...T...bBE..........................A..................n.C..fBD.....C.H...l........pAA..tJj..........D3..B..fI.......fZP..fqBI........3OABH.........RS...................B...7C...3OC.H...FV.......pAA...9CV....DuHy+bEmde2O3FYE.4rId8Cr5.BvEs6w+rBoe6SIojCvYYWO+dQ8I+6hQO5On2p3+bTfc+yiCAiOA6TG.Uzvl8KW+U7uNaWO9hRxF7qHHoyulaVL.aWY38yzEtlOccpa9Z17Y8C3fq7uzno3+pRJt+qg4vBv13D4+7Ns29KlXwuO3J0I.M9or.zPQP3OAT9N.+C7r5itQt2OnXc++VrXk+CLnOCvMzY5+PYC6.TrqIXOkzjK.ky6E+i3ONzO3bwM+LMgp.zxKRAPtLnN.A2yg1qj.OAP8.Lv+lRq936YZyBvl8GI.MoX2+q9Ce.vQCp3+1+2I5yqP0APpoIA.SvJw9iIWf.PQQL6+tzFM.DqsyAvciEE.iGgZ9yhzoCPfsvF.cur..74jJtOoqmN.ykg5.bM6u4ObMM0+dH7e96ERgfuxU2y+JIGI563L46ubhFn+rdQi9ajo62OKQXL+d70c.7..B..fgE......fZP...f+fE........PB.........3O...f+j.....f.....A...9C....P...f+....9K...3O.....C...AL...DvA....9K...3uN.....D....v.........9C........f+....AD....v.....A...AD...3u.....B...9K....P.....I.....f...P.C...ALB...f+B...9C....P...f+.....L...3u...f+....AD...DPK.....H....v...f+B...AL....v...f+....AL...3u.....A....H...3u...f+R....Dv...f+B....D....v.....GH....PJ.....L...3O.....B...9K...3O..........L....f...f+B...9C...3OF....AD...3O.....B....D....v...f+....9y......C...9K...3O...f+P....3u.........AD...DvC.H...FV.......pAA...9CV....6Myc+bkFER2OgBee+30iA9CeWf3O.UId+nGcE9S4dt3OFVVe+HEx98iQxP3O0SCi+bgT28y+om2OPg3e+Depn8S7HE3OY2fd+LvH28SIVh3O60bf+Xr+H9ivls3OvB5g+DwU68SJb81OBKpg+.Omw8Sy9c3O5P.f+n+EC9SRx01OUcge+jnpC9SdqR2O.Elg+DpA78SC.A3OtnXZ+zXVH9CmoU3OLG.b+ji.D9iIQ.3Os8Tb+Tnay8iqnf2OtjEf+bkUI9ihei3OLCRh+D3l.9yb+L3OaP4f+Dtxz8C2Yg2OFK4a+rXCG9iRFB2OFBdd+XkcC9CaEl2O9oif+PI9I9yr2W3Ox+mb+ju8J9yj8L3O8uVe+fICE9ivT02OhPsh+DxRy8S3zv1ODmqc+3i+K9yh8g1O76yc+LfEm8Cw6B3OmpYZ+bX+A9iWml3Oqe2g+jEPK9Cpeg2OBo5h+zXoz8i.....A....TE...PQwUWXrABck0FbkIWXsUlazo.UnUFHyQWXtQVXxQFHzUmao41Yr.xcnUlbkABcnUFHuMFcgYWYfj1bfPVZ1kFYkQFHo4FHwHCHkEWcgwFHyQWYvMmKL.......HKD..fzP..fkCA..HOD..n+P..fEDA..uPD..fDQ..PXDA..5QD..lHQ..fkDE..........D.......bODO....EA...XD.....+A........vA....DUlYgUGazA..........B....L.f...XoA......PDD...3OoA.........5..............3OA....D....P.....L....L.f...PK........9C...fP...ABA..fHD..PhP...PBA..DID...mP...cBA..DKD..XrPK.......fBTf...f.EH...DPAB....Tf...f+DH....P.........9y..B..fI.......fZP..fqBI........3OAN.f...XXA......nFD...3OXA...rW5X9yUSBmZ+7fSL9Sk7b3Onm1Z+HjfB9C5z52OtGuf+Dx9E9iFSi1OAUMb+bYHx8yGde3OhmRj+z93Q8iooB3OYQkh+HDkI9iJ2g1OEuwV+DzTJ9yXGJ0OuNzk+LIbl8Cx7A4O4zLl+b7h58iBMs2O3KNl+ziVV8iZqq2Oimma+rNrC9i7k83OW7Eb+38sI9yEKD4OVhtb+3iVx8Sx+T3OU8af+zr6M9i29Z1OI4Bc+3PuO9StTo3OoW2g+7M6l8CDYP3ODXmZ+TTAF9ilbl2OYUHS+.MOE9SQ3s2O.y7g+7eAm8iCfl1OI0qZ+.qIn8y45v3OxBQi+PaRN9imAh1O6TkW+HQ1E9yr6G2OwzMY+Pmkt8i22l3OfLtr+rvHp7i73uzOKkqW+vt7X8CuuX2OU10a+.GJC9SxDL3O5k4f+vCzs8SPMB2OFO0f+v7t.9ykyv1OvoVf+Pq6f8iRQL3OC.H...E..nGQA.........v..B..PA..5QT........f+.....v..B..PA..vIT..............9y..B..PA..vIT..........D...............zLyL2ayLybOA...................+B...7C...3OC.H...z........pAA..vID..fsPC........9if.....L.f...XB.......nFD..3pPB.........Pf...f+L.f...XB.......nFD..3pPB........9Sf...HBM.f...PH.......nFD...oP...pBA..zJD...rP...yBA..XKD..HtPH.........ff...f+P....DP...v.A..fDD...TP...f+L.f...PC.......nFD...mP...1BM........3OBN.f....C.......VLD..f7P..fEDQ....f.....C....L........3OB....AL.....A....L.f...XB.............3OB.........P....f+L.f...XB.............3OB........9SfC.H...DA.........XxjI4i+98yO...f+P..........AB...9SfC.H...l..............9i..........DH.....MyLS9....................7S.....MyLK.M.f...XB.......nFD..3pPB........9Sf...f+B...7y..B..fI........bP...jBI........3OAF....P.....A....v....vPu41XkIGcffTXrwlA....hMFZgwFa...v.A..vED...3OMyLi+.....fBWOBO.....nYlY3C.....MyLS+...uND...3O...f+D....fA.......f+....9y..B..fkF.......QP...f+jF...vv0i1OLhT358iET35g+....9y0iB2OeT3Z+fT358iYlY3OJb8f+v0iB9CRgq2OrGEd+PgqG9CtdT3OyLyb+fT358iYlY1OjBWe+PgqG9yv0i1O...f+Lb8H9SyLy3OT35g+PgqG9SAjBWe+v0iB9CRgq2O35Qg+7QgK9yGEt3OALb8n8yv0i1OEfqGE9yiBW2OWOJb+v0iB9iBWO3OJb8f+jPb8n3OT35g+fT358y0iB2OtdTX+nYlY8iT350OtdTX+rGEt8ydT31OmPJb87Cov02ORxES+b8nv8yiBW2OjBWe+XOJb8yGEt1OyLyb+ziBW8Cov02ORVCV+nv0C9iYlY3O6Qga+Lb8n8yv0i3O35Qg+PgqG9CWOJ3Ow0ih+7QgK9Cov02OMyLi+LyLy8yiBW2Ob8nf+Lb8H9y0iB2OMyLi+35QA9iYlY1OyLyb+PgqG9C...3OyLyb+fqGE9Sb8n3OMyLi+zLyL9CgC.H...z........pAA..vID..fsPC........9if.....L.f...XoA......PDD...3OoA........vjJb8H85fBWORO.....7nv0yqBWOZOJb8n8pv0ivaJb8XOov0i8B.....6QgauJb8H87nv0ySyLyTOrGEt8xdT31aAMyLy8nv0ivSJb8XuJb8H77nv006iBWWuBnv0ixK6QgaurGEt8hA.....ov0i89nv0ySyLybuJb8H7pv0izSyLyTuOJb87B....viBWOuJb8n77nv00SyLyTuOJb889nv00iBWOROov0i8zLyL2KLHWbuJb8H87nv0yqBWOBu.....nv0iziBWOROF.....PJb8XufoVN8nv0ivyiBWWOJb8H7pv0iv6EJb8n7nv0i1SJb8XuOJbc8nv0ivC6QgaOMyLS8zLyL2aJb8XuMyLS8nv0izqBWOJuMyLS89nv00SJb8XuOJbc8zLyL0qBWORuMyLS8nv0izC6QgaOov0i8zLyL0SyLyTODF..........A........7C....PC........9C...3O...f+L.f...PC.......nFD...mP...1BM........3OBN.f...PC.......nFD...mP...1BM........3OBN.f...XoA......PDD...3OoA.......9CzEtdD+HflYl0O...f+....9Ck...f+....9yA.......f+DWOJ5iYlY1OMyLy+nYlY5CB..............................................v..B..fkF.......QP...f+jF...vvgvwOeLyLy7CEtdzOrEqE+HrGr6SlYlwOov0C+35Qg7SEAEwOWlVF+PqMK7CDvCvOidgF+PbDo6CPhOvOJbHL+DJ1L7CvIutOFdx393cNG7ymnoyOys4G+zIjH7iZowwO4nHL+.DRK8yICpwOfT3Z+H.Lx7iszMyOyBNK+bh3u7yIh+xOA1bom7iQz9aS+HPDD9CcejxOig1G+3WFo8yN2DxOfcaF+rshT7yYnJyOeNtL+rgJg7SjVEzO9m6Q+j2Ad8CYOjxOinsA+L2le7SBBzxOBtiQ+TvSx7iRXczOAV+U+bQHE8SI.00OsXAh+LUeJ8iWM+vO4KmP+Hj6e8yXLTyO9oTY+rnMy8SAs+0Ozpmf+7IZ57yFCd7Oye2s+jMUs8CtWy0OfwoX+PpW.+SLA95OmIvt+X2i69y7aB8Oaoe2+vdnz+CdQV5O1kEu+vI9m8CTMf2OKwXn+LY8g9yZ774Oq88h+PRn89yPIW6OLPrU+jr9f9SPCx2OuE6s+DA268yDn47OYfnm+XlYl9S35Q6OyLyr+ziBW9SOJb6OJb8v+L.f...PC.......nFD...mP...1BM........3OBN.f...XXA......nFD...3OXA.......9yo1ZMf+zgDxD3OMidf+rBQB9CheJ3OCY0f+X4AD9StCS3OPoOg+LmdE9iBsW3Ooetg+PpmG9CKOf3O7BKh+b2YI9iSwn3OrSsh+f.IK9SAmu3O.2Ii+nhQM9idT03O.2Ii+b5hK9ytlj3OyoWg+zpyB9isVC3OH79e+fv6+8Cg...f+v3..B..fgE......fZP...f+fE...P6CA3OlXAt+8yz8x2On2be+TVw98ypd72O+7ke+PDE98CQ132OaR5e+DrH+8yEAB3OXUMf+vZO.9C6D62Old.f+fCK.9iiQ52OCvce+z9h98yBc62Oa70e+DaK+8CiTB3OR+Kf+ng1+8y5x12OCSne+31d98SHP.3Oyg9e+vOd88SMu22OBWle+7tp+8SZY72O474e+....9SwNA3OE6Df+DXYp+2Of.BK+8SPnA3O1I1e+vmo98C1I12OXrAf+....9S1W82OwA3e+fch88iXm32OXiFf+fyr+8iGq32OAwqe+3n4+8CIy22OrSre+LlL88ioAC3OHPOf+v6E.9C.Hq2Ojo8a+3I1g8iHvZ1OvkcZ+Pa5t8SwNw1OE6Dc+L1I18SmXm2Ochcd+HPwNw2O...f+....9CAvhHe+TrS.9ich82OE6Df+TrS.9if1I1e+DH6D62OA....jF.......QPC.H...1g.............9yg.........S.........f+.........DP...P.I....Dv...n.C..fBbf...f+b....3u...P.A....D....v...f+B...AL...DP...P.UA........n.C...9C..........A...9C....P...f.A....D...DP.....A.........P...f.A..fBD...DP...f+B....L...JP...v.A..fBD...JPL....BL...Nv...f.C........3u...f+....CD....P...f+....9K....P...P.C...A7B...v.C...9C..........A...9C...3u.....A...AL...3O.........9K...3uA.....L....vL..........v...n.C...9K....P...f.A........JP..........D...3O...f.C...BLA.....C...9K...DP..........Pf...f+D.....P.....M....3O...P.C...9K...3uI....AL...Pv...P.C..fBL...HP...n.A...BD...3O...f+B...9qB.....C...9K........3.C...AL....v...n.C....L...Dv...f+....9SA.....A...9K...3O...f+B...BL...HvG...fBL...Hv.....C........LP...P.A...AL...DvA...fBL...JvD....AL...Jv...f.C..fBL...RPC.H...1g.............9yg.......f.EH....PD....9C...DP.....C..fBL...JvAB...9y....f.A...9K...DP...P.I....Hv...f+B...9aA...f+....AL...Lv.....A...AD...DPAB...CTB.....C...AD...HP...P.A..fBD...HP...P.C...AD...3u...f+1.....v.....A..fBD....P...f+....AL...Jv...f+B...AL........P.A....D...3O...f+b.....P...f.C....L...Pv...f+B.........P.....U.....v...f+....BL........f+B...9KA.........AL....v...f+B...9aA...P.C.........P...f+...........I.....L...3u...P.A....L...Hv...f+B....L...Dv...f.C...Bbf.....H.....v...f+B...9qC...3.C....L...Pv.....C..fBL...Dv...P.A....D...JP...f+.........Jv...P.C...BL...HvE.....L...Hv...n.C...AL...Hv...f.G....DP...P.EH.....D....AD...3O..........L....vE.....D...3O...P.C...BD...DP...P.Q....HP...n.C....D...DP...P.M....Hv...f+B...AD...DPA.........SPC.H...1g.............9yg.......P.I....3u...P.A...ATf...P.G....Jv...n.K.....v...P.A...AT....f+....9SB...f+B....D...HP..........L...Lv.....A...AD....P.....M....HP...P.A....D....PH....9K...3O...P.A..fBD...HP...P.C...CD..........X....HP...P.A...9K....v...f+....AD...DPN.....D...3O...P.A...CD...3O........fBL....v.....A...AD....P...P.A...9C....P.....I...........C....rD.....A........3O...f+B...9C...3u...f.A........DP.....A...9C........P.A...9C....P.....C....D...3u...f+d....JP...P.A....D........P.A.........v.....q....Jv...P.C....L...Hv.........9C........f+....AL...3u...f+V....Hv.....C...AL...3u...n.C..fBrB.....C..fBL...Dv.....A...AD...Jv.....C..fBL...3u...n.C..fBrf...f+X....Hv...n.C...AD...Hv...P.C...BL...HvA....AL...DvB....BL...Jv...n.KH....vA...fBL...TPC.H...1g.............9yg.......n.W....Hv.....C...AD...3u...n.C..fBrf.....w.....v...f+.....L........f.A...9K...JP...n.C....D...HP...f+.....D....PAB....b......A....jB...P.A...9C...JP...f+B....D....v.........9C...DP...P.C...ArA.....C...9C...HP.....C...9K...3O...f+DH....vD....BL...3u.........9C...3OAB...9af...P.G....3u...f+J....Dv...f+B...9KA.....C...9K...Hv.....C....LA...f+B...9C....v...P.C...A7......A....L...3u...f+p.....v...f+....9K...3O........fBL........f+....AL...Hv...f.G.....v.....G....Hv...f.q....3u...f.A....D...3O.....A...BL...3O...v.C..fBL...Hv...f.GH...DvE...fBL...3u...P.A...9C..........L....Dv...f.A...AD...DPE.........Hv...f+B....D...DP...P.AA...3O...n.A..fBL...3u...P.A...CL...DP...f+.....D...3u.........CD....P...f.A...9C...HP...TAM.f...XGB............3OGB........P....f+....9y....P.A...BL...Jv...n.GH.....G....9C...LP.....A....L....P...P.A..........B.....D...3O...f+b.....P...f.A...9C...DP...f.A...9C...JP...n.AA...DP...f+B....L...3u...f.A...AD...3O...f.C..fBL...3O.........9C...HP...P.A....D..........r....Nv...P.C...AD....P...f+.....D....v...P.A....L....P...P.C...AbB...f+B........3u...f+.........HP...P.A.........P.....g....Hv.....A...AD...3u.....C...9C...Hv...f+....9y......C...9K....v.....u....3u...v.C...AL...Hv...v.C...AL...Hv...P.A....L...LP..........f....P.C....L....vD....BL...Jv.....A...BL...HvZ....AL...Hv...f+B....D...DP.........AD....P...f+B..fBL...Hv.....C....D....v...P.A....D..........A...AL........P.C....L...Dv...f+B...BL....v.....i....HP.........9C....v...f+.....D...HP...f+...fEz..B..fcH............f+bH.......HvD..........P...P.A..fBL...JvAB....PB...P.A...BD....P...f.C....D...JP...f+B..fCL....P.....EH...DPF....9C....P...P.A...9C...DP...f.A...BDC...f+B....L........P.A...BD...3u.....C...BL...3u...P.A...9C...DP...P.Y....3O...f.A...9K...Lv....AC...9K...3uC....AD...JP..........P....f+B...9aA...P.A...9C...Jv...P.A...9K...3uA.....D....PN.....L........f+....9K........f.A....D....v.........AL...DP...n.A...9K....P.....EH...3OD...fBD....v.........9K...3uM...fBL...Dv...f.A...CD....P...f.A...AD...Lv.....C........Jv...P.C...BL...HvF....AL...Hv...P.C.........P...f+B...96..........9C...Jv...n.W....Dv...f.C...9K...3O.....A....DB...P.A..fBL...Hv...P.C...BL...Lv...f.C....L....vD.....D..........A...9K...3uG.....D...DP...f+B....D..........C...9C...WPC.H...1g.............9yg.......n.S....3u.....A...AD...Jv...n.GH...DPO....BD....P...P.C...9C...HP.........BL..........A.........P...f.A...9C....P...P.A...ADB.....A...9C...Hv...n.C...CD...3O...v.A...9K...3uF..........P.........CD....P..........fA...f+B....L...Hv...P.A.........P.....U....3u...P.A...AL...3u...f+....9yB.....C...9C....v...f+B.........P...f+....AD...3u..........L....vM.....D...3O.....A...9K...HP.....C....D...3O...P.C..fBD...Hv...f+....AL...DvG....AD....v...f+B...CL...HP...n.A...9C...3OE....AL....P...P.C...9K...Dv...P.SA...Jv.....C...9K...Nv.....A........DP...f+B...AL....P...n.C...BL...Jv.....C...9K...DP...f+.....D........n.C..fBb....f.C...Bbf....Aa....Hv.........9K....P...f+B...9C...3OJ....AD...HP...P.C...9K...3O.........9K..........C...AD...XPC.H...1g.............9yg.......P.S....3O...P.A....D...Jv...n.G.....P.....c....HP.....A...9K...DP.........BL....P.....U....DP.....A...9C...DP.....A....j....n.A....D....PI..........v...f+....AD....P...3.C..fBL....v...f.A...BzA.....A...AD...3O.....A...AL...Jv...f+B...96A.....A...9C...3u...f+.....L...3O..........v....f+.........3O...f+D.....P.....Y....3u...P.A...BD...3O...P.A...9C...3OC.........3O...f+B...9qB...f.C....L........v.C....D....v..........L...Hv..........Pf.....q....HP...f+B...BD...Lv..........L...3u.....C..fBL...Hv...f.a....Dv...v.C...9K...3O...P.A..........M.....L...Dv...f.C..fBL...Dv...f.C...AD...3O...n.A....D...3u.....C...AL...DvI....CL...3u...P.C........3O.....A...9K........f+....9Sf.....EH.....A....9C...3OBB...Ab....f+....9S.........HFz..B..fcH............f+bH.......DPD....9C...HP...f+B..fBL...JvI....AD...Jv.........AL...DP...f.A..fBL........f+....9CA...f+B........HP.....A....j....n.A...BD...HPJ....9K...JP...P.A...BD...Jv...3.C........DP.....A...AD...DPF....BD...DP.....C...DL...3u...f.A...BDA.....A.........P...f.A...BDA...v.C...AL...3u.....A....j....P.C..........AB....Tf...f+f....DP...f.A...9K...Dv...f.C....D...3u.....A....TA.........BD...JP...n.C...9K...3uF.........3u...f.A...9C...DP.....A....jA...f+B...BL...3u.........AL...3u...f+d....Hv...P.C...BL....P...f+....AD..........DH...3OA...fBL...JvH....BL........P.C...9C....P.........AL...Jv...n.KH...HvB...fBL...3O...f+D....3u...f+V....Hv...f+....AD....v...P.C...Abf...f+J.........f.C...BbA...P.C...BL....v...f.C...AL...DvA.....L...YPC.H...1g.............9yg.......n.S.....P...P.A...BL...Lv...v.K....DP.....A....jA...f+....AD....v...f.C...9K...3O...f+3....HP...f+.....D...3u...f.A...CD...3O...f+B...AD...JP........fCL...Hv.....A....T....n.A..fBzD...f+....BD....v...v.C..fCL....P...P.A...BD....v.....A...9C...JP...f+B........Dv...f+.........Hv...f+B...9aB.....A........3O...f.A....D...LP...f+.....D...3u...f+FH.....Y....9C........f+B....L....P...P.C.........v...f+B...AL...HP...v.A....D...3u...f.C....L...3u.....C...BL...Dv...f.C....L...Dv...f+B...BD...HPK.....D........f+B...AD...Jv...f.C...9K...3O...P.A....D...3O...f+7....Jv...v.C....L...Hv...n.C...BL...Dv.....A...9C....P.....C.........P...f+.....L....vF.........3u...P.C...9K...Dv...f.C...Bb....P.C...Arf...f.I....3u...P.C...Abf...lAM.f...XGB............3OGB.......Bz..........BD...Jv...n.m....DP...P.C...9C...Dv...P.A....D...Lv...f+.....D....PH....9C...HP...P.A....D...HP..........L....P.....U....3O...P.C....L...3u...f+....9yB.....A...AD....P...P.A..fBL...Dv.....C...AD...3O...P.A....D....PAB....Pf...f+X...........A....L...3O..........D....PD.........DP...f+.....D....PO....9K...3O...P.A...9K........P.C...9C...Jv...f+B...AL....v...f.C..fBL....v...n.A..fBDA...v.A....D...Hv...f+....9iC...f+B..fBL....v...P.C........Lv...P.A...9C...HP..........L...3u...P.A..fBL...JvH....9K....P...f.A..fBD...DP...f+B...BL...Dv...P.G....Jv...n.G....Dv...P.i.....v...f.A...9C...3u.........9K........f+B...9KA...P.C...9K........f.C...B7f...P.GH...HvB....AL...Hv...f.W....Dv...f+.....L...Dv...f.C..fFz..B..fcH............f+bH.......DPAB...BT....n.C..fBr....f.A...AD...DPAB..fBj....f.C....D....PA....AD...DPAB....j....f+....AD...DPC....9C....P...P.A...AjA...n.C...AL...3O...n.A...CD....P.....c....HP.....C...AL...HP.........AD...3O...f+L....3u.....C..........B....9C..........DH....PN....9C...HP.........9C...JP...f+B...9C...DP...f+....AD...3O...P.A...9C....P.....AB...3O.....C....D..........A...AD...3O...n.A...9K...DP...f+B...9C....P...P.C...9K...Hv.....C...9K....v...P.A....D...JP.........9C....P...n.C....L...Dv.....A....L....P..........f....n.C...BL...HvS.....L...Nv...f+B...9C...Dv.........BL....v...f.C....L...3O...f+B...BL...Dv.....C....D....v...f+....CL...LvD....9K........n.C...CL...LvC....BL...Nv...v.C...C7A...3.C...BL....v...f+B..fBL...Lv...n.C..nFz..B..fcH............f+bH........vC....9C....P...n.C..fBbA...f+...fBD...Dv...f.A...AL...DvA....9C...3OAB...ATC.....A...9K....P...f+....9K...LP...P.A...CD....P...f+B...AD...LP...f+....9CD...P.A...BL...Lv...f.C...BD...DP...f+B....L...3u...f.A...9C...Dv...f+B........Dv...f+B...9qC..........D...3O.........BD........f+.....D...Dv.........9K..........A...9K...3uG.....L........v.C....L...Hv...f+....AD...DPE....BD...3O...v.C........Dv...P.e....Hv.....C...AL...Lv.........AD...3O...f+v.........f+...fBL...Hv...P.C........3u...f.A...AD...3O...f+B....L....vE....BL...Jv...v.C...BL...3O...f+L.........f+B....D....PAB...AjA...P.C...9K....v.........BL...3u...f+9....Jv...P.C...9C...3u...P.C........Dv.....A.........P.........9K........f+.....D....PC..........P...f+....9C...aPC.H...1g.............9yg.......P.Y.....P...f+B..fBL....P...f+B....D....PI....9C...Dv.....A...9C....P...f+....AD....P...f+....9SA.....C..fBD...DP...f+....AL...Dvo....AD....v.....A...AD....P...P.C.........v...f+B.........P...f.C...9C...3u.........AL...3O.....C...BL....v...n.A...9C........f.A....D....v.........9K....P...P.C...9C....P...f+....BD...Hv...P.C...AD........P.A....D...LP...v.4.....v...n.C.........v.........CL...3u.....C..fBL....v...P.A....D........f+B...9qB.........BL...Dv...f+....9K...HP..........D...Hv.....C....r....P.C..fBL...JvA....AL...DvAB...9CE........fBD....P...f+B....L...DP.....C...9K...3O.....C...CL...3u...f.C...9K....v...P.C........3u.........9C...3OA.....L....vD....AD....v.....A..........G.....D...3u...P.C..fBL...Dv.....C.............tAM.f...XGB............3OGB.......Cr....P.A...CL...LvG.....D...HP...P.C...BD....v.....A...9C...3OAB...AjC...f+B..fBD...3O.....C..fBD....P...f+B...AL...3u...P.A....L...DP...f.A....L....vB....9K...3O...f+HH.....i....AD...3u.....A...AD..........C...AD...HP.....A...AD...LP...f+.....D...3u.....A.........P...f+B........LP...f+....CD...3u.....A..fBD....P...f+B...BD....P.....C....D..........C...9C....v.....e....Jv...P.C...BL........P.C...AD...3O...f+D.....P.....E....Jv...n.2.....v........fBD...3u.....A........Hv...v.C...BL...Pv...v.C..fBL..........D....3O...f+L.....v...P.C...AD...DPA....9K...3uM....AL...3O.........AL...Hv.....C...AL........f+B....L...Dv...f+....9K...3uA.....L....vF.....D...3u.........9C........f+B...9q....P.C...9K...3uD.....L...Lv...f+B....L...bPC.H...1g.............9yg.......P.EH...LvF...fBL....P...P.A........3O.....C....rJ...f+....AD...3O.....C...9C...HP.....A....L....P.........AL....P...v.A...9C...HP.....A...9C...Jv...v.C....D...HP...f+B........3O.....C........Dv...f+....AL....v...f+B........LP...f+.........JP...f+....AL...3u...n.C....L...3O...f+.A...JP...f+....BD....v...P.A........Hv.........9K...LP.........BD...DP...v.C.........v.....K....Hv...P.C...AbA.....C.........P...f.A..........AB..fBLA..........L...Hv...f+....9Sf...P.Y....Hv.....C..fBL...Dv...n.C...9K...3uC...fBL...DP...f+B...9af.....L....Dv.....C..........T...fCL....P...f.C...9K........n.C....L...Dv...f.C...9K........P.A...9K....v...f.C...9K..........A...9K...3O...f+HH....vB....9K...3O...f+L.....P.....C...AL..fbPC.H...1g.............9yg.......P.EH...LvG....BL....P...P.C....D....v...f+.....D....PF....9C....P...v.A...BD........f.A...BDB........fBL...DP...v.A........HP.....A...AL...DvB....9K....P.....EH...HPT....9K........P.C...AD...3u...n.A...9C...DP...f+.....D....v...f.A...9K........f+...fBL...JP.....A...9C....P.....o....LP.....A...9C...3u...P.C........LP...f+....CD...3O...f+X.....v...f+....9K...Jv...P.C...9K...3uJ....AL...JP...P.A...9C...DP...f+.........Jv...f.C..........B....AD...3O...f+DH...3uA...........D....9K...Hv.........BL...HvK....9K...3O...P.A...9C...3u...v.A...BD...3O...P.A..fBL..........L....Jv.....C...BL...HvG...fBL....v...P.C..fBL....P...P.C...CL...LvA....BL...HvBB...CLA...f+....CL...3u...v.C...CbA...f.C...CL...Jv.....A...CL...LvAB..PGz..B..fcH............f+bH........PU....BD...Jv...P.A....D...Hv...P.A...AL........f+....AD...JP.........CD....v...P.A...CD...Dv...n.C....D...LP.....A....TA...f+....AL...3u.....A...9C...3OAB...Ar......C...9C...3OL....9K....P...P.C....D...HP.....A.........P...P.C........DP...f+....9iC.........AL...JP.....C...BD...3O.........AD........P.A....D...DP.........9C...3OA...........R.....L...Jv.....C........Lv.....A........HP...f+.........DP...f+...fBL...Hv.....A.........P...P.A...ATf...P.G....Lv...v.G....Jv...n.K.....v..........ff...f+V.....v...f+...fBD...DP...f+B...96A...P.C...9C....P...f.C...9K...Jv...P.C...Ar....f+B...AL...DvF.....D....v..........L...Dv.....C....rf.....D.....v.....GH...DvIB..XGz..B..fcH............f+bH.......3OL....BD...Jv...P.A....D...DP...f+....AD....P...f.A....D...DP..........vA.....A...AD....v...v.C....D...DP...f.A...BjB...f.C...CL...JP.....A...9K....P...v.A...9K...3O..........vB...P.C...BD...LP...f.A...AD..........A...9K....v.....A..........U....9C....P...f+....BD........f.A........3O...f+B....D...LP...f+....AL........f.C...9C...Hv...P.C...BL....v...f+B...9q......A...AD...DPB.....D...3O...f+D....Jv...n.O....DP...P.C...BD...HPV..........v...n.C...CL...Hv...P.C...9K...Dv.....A........3O...f+B...AL...3u.....A........Hv...P.C...BD...3O...f+B...CL...Lvg....BL...Jv.........AL........f+B...AD...3u.....C..fBL...3u.....C...AL........f+B.........v.........CL...3O...P.C....L...Lv...n.C...BL...Dv.....C..fBL....v...P.C....L...Dv...f+B..fGz..B..fcH............f+bH.......HPD....AD...Jv...f.A...AD...DPV....9K...DP.....A...9C....P...n.A...BD...3u...f.A...CD...3u.........BD...DP...f+..........v.....A...BD...DP...f.A...9C...3OAB....7....P.A...BD....P.....w....HP.........CD...DP.....A........DP.....A........LP...f+...........L....BL...Dv...f+....CD...3u...v.A...9K....P.....C...AD....v.....A....T....f+....9CB...f+B...BD....P...f.A....D...DP...n.C...9K...3uA.....D....PA....AD...DPC....BL...3u.....C....bf...f+xA....v...f+.........DP...f+.....D...HP...P.A....D........f+B...AD...HP.....C...AL........v.C....L........v.C..fBD...Lv.....C...BL...Dv.....A...AL...Jv...n.S.....P...v.C....L...Lv...v.WH...HvA....CL...LvB....AL...Lv...v.GH...HvC....CL...3u...v.C...Crf...5AM.f...XGB............3OGB.......BrD.....C...CL....v...f.C....D...Dv.....A..fBD....P...f+B...BD...3u...f.A...9C...Hv.....A..fBD...3O...f+L....Hv...f+...........C.....L....P...v.C...CbA..........L........f+.....D....PD.........HP...f.C...9K...3uQ.....L...3u...P.C....D...Nv...f.C....L...Hv...3.C....D....v...v.A...AD...3u...f.C........Hv...f.W....Jv.....C...BL...Jv.....A....Tf...f+z....DP...f+....CL...Dv.....C....D...JP...f+....9K...Hv...3.C..fBL...Lv...v.K....Jv...P.C...Abf....AO.....v...f+B....D....PK.........3u.....C...9K....P.....C...9K...DP.........9C...Hv...f.O.....v...f.A...AD...DPK....BL........f+....BD........f+.....D...DP...v.A...9C...3u...f+9....Dv.....A........Dv.........AD....v...f+....CD...DP...n.A...AD...HP.....A..fBD...JPA....CD...LPA...fBD...ePC.H...1g.............9yg.........Y....Jv...P.C...AD....P...P.C....D....PE....9C..........A........HP...f.g....Hv.....A...9K...DP...f+....AL....P...P.A...ADA...n.A....D........f+B...9aA...f.A...9C..........A...AD...DPK....9C....P...v.A....D....v.....A...BL...HP...f+B...AD..........f....3O...v.A...BD...JP..........D..........C....bC...f+.....L........P.C...BD....P...P.A...9C........P.C...BL...Dv...f+B...96B...f.A....D....v...f+....9K...Dv...f.C...AL........f.A...9C...3OG....BL....v...n.A...AL...DP.....C....D....PD.....L...3u...f.C...AL...DvE....9K...Dv.....C...9C...3u...f+Z...........C........Hv...P.C..........G....9K........f+....AL....v...f.C...AL...DvB....BL....v.....G....Dv...P.K...........C....7A...f+B...AL....v...P.C...BL....v...P.C...ALg...9AM.f...XGB............3OGB.......9yD...n.C...AD....P...P.A...CL....P...f.A....D...LP...f+....AD...JP.....C...AD...3u...n.A....D...Hv...f.A...BDC...f+B..fBD...3u.....C...9C....P...f+B...9C........v.A...9C...HP...f.EH...LPG....AD...HP...P.A...BL...Dv.........CL...LvF.....D...JP.....A...BD...3u.....A....T....P.C...A7A...f+B....L...3u...n.A...AD........P.A...Aj....n.C....L....vAB....fA...P.A...9K....v.........AL...Hv...f.O.....v...f+...........D....9K........f.A..........A....9C...3OC.........3O.....C....7A...P.C....L...Jv...f+.....D...Jv...f+B...9a....P.C...Ab....f+B...9KB..........L..........C...9C...3u...f+.....L....vBB...BLC...f+B...CL...3u...f.C..fBL..........C........3O..........L...Jv...n.q....Hv...3.C....L........P.C...BL...Lv...3.C...CL...Nv....BM.f...XGB............3OGB.......CrD...3.C....D...3u...P.A...9C........f+.........JP.....C........Lv...n.C....D...3O.....A...BL..........3.....v...f+....BL....v...P.C...AD...Hv.........BD...3u...n.A....L...3u...P.C...AbD...v.C...AL...3O...f+B....D...3u...n.C....D...3O.....C....D...Dv.........BL....v...f+.....L....vB..........P.....IA........f+B....D....v...v.C........HP.........AD...3u...v.C........Jv...P.C...BL...Dv...f+B...BL...HvE....9K...3O...P.A....D...3u...f+FA....P...f+....AL....v...f+B....L...Hv...P.C...9K...3O...f+B........Dv.........9K...Dv..........fA...f+....9K....v...P.C........3u...f+J.....P.....C....r....P.C....D....PE....9C....P...f+.....D...3O...f+PH....PBB...9S......A....zg...ABM.f...XGB............3OGB......fBjA...v.C...BD...Fv.....C........DP...P.EH....PA....AD...DPn.....D...JP.....A...AD...Hv...P.A..fBD...3O...f+B...9C...HP.....C...9K...3O...f.A...AD....P...n.A...9K...DP..........D....v...v.A....L...JP..........D...3O.....A...CD...Dv.....A...AL....v...n.C...9C....v.........AD...DPAB....z....f.C...AL..........H....3O...f.A...Bj......C...BL...HvF....AL...Jv...f+.....D...3O...P.A...AzB...f.A....D..........A...9C...HP.....A...CD...3O...f+B...AL...DvG....9C........f+B....D...HP...f+.....D....PAB...96C...P.C....L...HP...P.A....D...3O..........L...Dv...f+.....L...Dv.....C...9K...Jv...n.G....Hv...f.G...........D....Hv...f.KH...JvF....AL..........C...BL...Jv...f.C...BLg...n.G....Hv...f.KH..ffPC.H...1g.............9yg.......f.I....Lv.....A....jA...P.C...9C....P...f+...fBD..........H.....v...P.A...AjD...f+B...CL...HP...v.A....D...DP.........9C....P.........9C........f.A..fBD...DP.....A........3O...f+7....3u...f+....BD...3O...f.A....D...JP...f.A....D...DP...f+.........Hv...f+B..........C....AD..........A....TA...v.C...AL...3u...f+....AD...DPI.....D...Dv...f.C...9K....v...n.C.........v..........P....P.A...AjD.....A....L...Hv...P.A........3O...P.A....L...3u...n.C....D...Hv.....A...AL...3O.....C...9K....P.....o.........f+....AD...HP..........L...Dv.....C...AD...3u...f+V....Jv...f.C....L...Hv...P.C...A7....f.C...AL..........DH....vAB...Abf...f+F....Dv...P.OH....vB.........Dv...P.mH..vfPC.H...1g.............9yg.........U....Qv.....A...AD...3O.....A....Tf.....b.....P.........BD...3O...f.A...BL....P.....I....JP...P.C...ALH.........AD...HP.....A...BD........P.A....D...DP.....A...CD..........A....L...3u.....A...9C...LP...f+.........JP.....C...9K...3O...f+B....D...HP..........D........n.C...9K...3uB....BD..........bA....v...P.C...9K...Hv...f+B...9C...DP...f+B...9C....P...n.A...9K........n.A........3O...f+B....L...Hv...f+B....L...Dv...n.A..fBzB.........9C........f+....9K...DP...f.A...AD...3O.....A...9K...3uB.....L...Jv...n.G.....v.....GH...HvC..........P...f+B...9q......C...BL...HvE.........Jv.........AL...3u...f+N.....v.....A..........C.....L...3u...n.C..fB7....v.C..fBL...Lv...v.O....Hv...v.C..fCL...NvE....CL...Jv...P.C...CL...Pv....AGH...gPC.H...1g.............9yg.........XA...Pv...f+.....LMyL2u...v.A...9K...LP...f+B...AD...Jv.....C...9C...Dv...f.A..fBD...HP...P.C..fBL...3O.........9K...DP...P.k....JP...P.A...BD...DP...f.A...9C...Lv...P.A....L....vD.....D...DP.....A...9K...3uE....AL...Hv.....C...BL...DP...P.Q.........f+....AL...3u...f+F....3O...f+DH...JvE....AL........P.C....L...Dv...P.2.....v...f+B...AL...JP.....C...BL...JP.....C........Lv...P.C...CL....v.....u....Hv...f.A...9K...3O.........AL...Hv...f+B........HP...f+....9iA...f+B....D....v...f.C..fBL....v.....y.........v.C....L..........A...AD...3O.....C...BL...3u.........9C...3OD.........3O.........9C...3OA.....L....vA...........A....9C...3OCB....j..........9C...3OAB...9af.....X....3O...f+B....D...3O.....A.............EBM.f...XGB............3OGB.......BjBlYlg+B..fBD....v...f.A....D........P.A...BD...3u...P.A...AjC.....XlYF9K....P...P.A...CD...3O...P.A...9K...DP.....A..fBD...HP.....A...9C...3OD...fBD...HP...v.A...9C...3OD...fBD...LP...f+....AD...DPM....9K...DP..........D...DP...n.A....D...HP...f+B...AL...3u...P.A..........A.....L....vP....AL...Hv...f+B...9C........f+.....D...JP...f+....9K...DP...f.A...9C...3u...n.C...9C...3OK....AL....P...P.C...9K...Dv..........D...3u.....A...9C..........P.....P...f+B........Jv...n.WA....P..........L...Hv.....A...BD...DP...f+B....L...Jv...f.C........Lv.....A....L...Jv.....C....D....v...v.C..fCL...NvJ....DL...Hv...P.C...BL...Dv...v.C..fCL...Dv...v.C..fCL...NvA...PDL...QvBB...Ab....DAC..PDb...........fg...FBM.f...XGB............3OGB.......ADE...f+B....L...Hv...f+.....D...JP..........D..........A..fBD...Hv...P.A..fBL...LP.........9C....P...P.A...9C...3OBB...96....f.A....D...3O...f+L.....P.....C....D....PF....9C....P...f+.....D...DP.....A....zD...f.A...9K...DP.........9K...3O...P.A...BD...Hv...f+B...9C........P.A....D...3u..........D...DP...f.A...BT......A....zC.........9K...3O...f+B....D...JP...f+....9K....P...f+....9K....P...P.A...BD....v.....a....3O.....A...9K....v...f+B....L....vE....9K....v.........9C....v.....a.........P.C..fBL...3O.....C...BL...HvBB....b....f.C...Brj.....zH..vgPC.H...1g.............9yg....ZlY9+bA..........A...BD...JP...f+.........HP...f.C...CD...JP...v.C...AD........n.A...AD...3u.........AD..........C...AD...HP.....A....TA...P.A....D........n.A...9C...3OE....9K...3O.....C.........v.....W....DP.....A....L...Dv...f.C...BLA...f+B....L...Jv.....C....bf...n.i....Dv...f+B...AL...3O.....C..fBL...3O..........vA...n.C...CL....v...P.C...9K...3O...f+B...9af...f+L.....v.........9K...3uO....9C...Dv...f+....AL...Hv.....C...9C...3u...n.C........3O.........9K...Dv...f.C...Bb............A...f+B........3O..........v....f+B...9C..........D....3O...f+DH...3uB.....L..........D....3O...f+DH.....A.....D....PA....9C...3OA...........RB..fHz..B..fcH............f+bH.........K....AD....P...P.A..fBD........f+B....D...3u...P.A...9C...JP...n.Q.....v...P.C...9C....P.....Y....LP.....A........HP...f+B..........F....9C...Dv...P.A...CD....v...........A...f+....AL........f.A...BDA...f+B..fBL...Hv..........fC.....A..fBL...Dv...f.C....L...Hv.....A...9C...3u...f+....9K...Dv.....C...9C...3OL....CL...Hv...P.C...9C...3u...P.C..fBL...DP...f.C....L...DP...f+....9S...........fD...f+B....L...3u...f+....9K...Hv...f+B...AD....P...f+B.........v...f+....9K...3O...P.C...BL....v.....GH...3uBB....f....f+B...AL...DvD.....L...3O...f+B..........C.....L...3u..........vl...IBM.f...XGB............3OGB.......B7B.....A...9C...DP.....A...CD....P.....C...9K...3O........fBD...JPF.....D...DP...n.A....D...DP...f+....9CA...P.C........Hv...P.C...ALB...f.A..fBD........f+.....L...3u.....C...AD...DPBB...BLA...P.A..fBD...3O...........B...v.C....L...Dv...P.A....D...3u.....C..........AB...BT....P.C...ALA.....C...9K....v...f.C...B7B...P.C...9K....v.....A....L...Dv...f+....BL...3u...P.C....L....vBB...9a...........PA...f+....AL...3u.....C...9K...3uA.....L....vD.........3u.....C...9K...3uD....AL....v...P.C....L....vBB...9a......C....7f...P.G...........zI..fhPC.H...1g.............9yg........Ay....DP...f+B....D...3u...f.A........JP.....A...9K...JP...f+....BD...HPA.....D....PC.........3O.....A....Tf...P.m....3u.........CD...HP.....C....D...3O.....A...AD...DPBB...BLA...f.A....D...HP.....A....T....P.C...AbA...f+....AD........v.A...9C...3OD....BL...DP.........9C...3OA...........D....BL...3O...f.C..........L.....D..........A........Jv...f+B...BL....P...P.C...BL....v...f.C...Bbf...P.GH...JvB.....L..........L....3u...n.C...BL...HvA...fBL...JvH....BL........n.C...BL...Jv...f.C..fBL...Hv...f.KH...JvA...........iB..rHz..B..fcH............f+bH.......RvU....9C...Dv...n.A...9C....v...f.C...9K....P........fBD....v...f+.....L...HP.....A...AD...3O...P.A...9C........f+....9Sf...f+1.....P...v.C...BL...Dv...f.A...AD....P.....C........DP...v.A...AL...Jv...n.i....Dv...v.A....D...Hv...P.A...AL...3O...f+B...9q..........BL...HvC..........v...f.C...Br....f+...........F.....L...3u.....A....L...Hv..........v....n.C....L....P.....M....3u.....C...9K...3uF.........Hv.........9K....v..........f......C...9C...3OBB....Pf...f+J....3O.....A....Tf.....nJ...iPC.H...1g.............9yg.......DAO....Hv...f+...........J....AD...3u...P.A...AL........n.A...9K..........A...BD...HPAB....DB...n.A........Jv.....C...9K...Hv...n.C...CL...LvA.....D....PV....9K....v...f+B...BD...3u.....C....D...Dv...n.C...AD........f+.........DP...P.C.........v...P.C.........P...f+....AL...DvR....BL....v.........9C....P...f+.........Hv...n.C...9K...Dv.........9K...Dv...f+.....L........f+....9S......A....TA...P.A........3O...f+B...9C...3OC.....L..........A....Dg...P.E...........zJ..PiPC.H...1e.............9ye.......3.K....Dv...P.A...Az......alYF9K...HP...f.EB....P...P.C.........P.....C...AD...3u...f.A...AD...3O...f+B.........v...f+.....D...Dv.........9K...DP.....A...9K....v........fBD...Hv...n.C..fCL........f.A........DP.....C...9C...3OG....BL...Jv.........BL...3O.........9C...3OA....9K...3uE.........3O...f+B........Dv...P.i.........f.C...CL...3u.........AD....v..........vB...P.C...9K...3O...f+B........3u.........9C..........C..........C.....D....v...........q...NBM.f...X+A............3O+A......PD7......A...AD...3O...f+DH....PA....9K...3uH...fBD....P...f+....AD...JP...P.A....D...JP...n.w...........A...9K...HP...n.C........3u...f+.........Dv...P.A...9C...3OA....AL...DvAB.....E.....C....D........P.C....D...Dv...f.C...AD...3u.........9K...Hv.........AL..........A..fBD...Dv...f+B..fBL...JvF....AL...DP...f+B........Hv...f+B...9qA.....A...BL........P.C....L...Hv...f.G....Dv...P.K.....v...P.C...A7......C...AL....v.....GH.....tB..7Hz..B..f8G............f+7G.......LvA....AD...DPN.........LP...f+B...CD...DP...f.A........DP...f.A..fBD...HP.....A..fBD..........PA...3O.....A...9C...3u...P.C....D........f+.........3O...f.A...9C....v...P.C........3u.........9K...HP...P.C...ArC...f.C........3u.....A.........P...f+....AD...3O...n.C...AL...Hv...f+B..........D.....D........f.C....L....vA....9C...3OE.....L..........C...BL...Dv...P.GH...JvA....AL...DvB....BL...Jv...n.O....Dv.....C..........wB...Iz..B..fwF............f+vF.......LvC....9C...HP..........PA.....A...9K...DP...P.C....L....vZ....9C....P...f.A........3u...f+....AD...Dv...f+B....D...Dv.....A...AD....v...f.C...AD...Dv...v.C...9K...3O.........BD...3u.........9C...3u...f+9A........f+....AL...DP.....A...AD...3u..........L...Dv..........L...Dv...f.A...9C........n.C...9K....P.....C...9C...3u...P.C...9C........f+.....D........f+B....D...3O...f+DH....vA...........hB..DIz..B..fwF............f+vF.......NvJ.....L....P.....C...AL...HPzLyb+B...AD....v...f.C....D....PA....AD...DPAB....vB...v.A....L...Dv...f.C........3u...f.C...9K...HP...f.C..fCL...NvC.........Hv...f+B...9qA.....A...AL...Lv...3.C....L...3u...f+N....3O.....C...9K...3uM.....L...Hv...P.C...9K....v...P.A...AL....v...n.C...9C...Dv.....A...AD...DPB.....D...3O...f+DH....PB...fBD...DP...P.EH...HPAB....vo...RBM.f...XrA............3OrA........LC...P.C....D...IP...P.C...BD...DP.....A........DP...n.A...9C..........X....3u...P.A...AL...DP...f+B....D....PAB...Az....f+....AL....v.....m....Dv...f+B........DP.........AL...Hv..........D....PK....9K...DP...f+....9K...3O.....C....D...3O.....C...9C...Dv...P.G....3u...f+FH....vAB...Bbf.....K....Hv.....C....bf...P.KH.....qB..LIz..B..fYF............f+XF.......3OA....BD...HPH....AL..........C...9K...DP.....C...BD...3u...f+dA...HP.....A...CD...HP..........D...LP...f+B........HP...n.C....D...3O...f+B...BL...3u...P.A...BD........f+...fBL..........C....r......A...AL...DvA....9C...3OP.....L...3O...f.C........3u.....C........Lv...P.C...9C........f.C....L...Jv...P.C...CL...LvB....AL...Lv...v.G...........bJ...kPC.H...1U.............9yU.........g...........C...9iYlY3O...f+....9K........f+....9SA.....A...BD...3O...n.A..........I....BD...JP...f.A..fBL...3O...n.C....D........P.C...Abf...f+Z....3O...f.C...9C...Dv.....C...BD...HPF...fBL..........C...9C...3u..........Pf.....O....Hv.....C..........C....AL..........C....7A...f+B....L...3u.....C...AL...3u..........vl...UBM.f...XWA............3OWA.........A.....A...BD....P...f+....9CH.........9K...JP..........D........f+LyLCAD...Lv...v.A...BD...DP...f+B..fBD...Jv.........AL........f+....AL...3u.....C...AL....v...P.C...AD...Dv...f+.........3O...P.C...9K...3uAB...Ar....n.C...9K...3uAB..fBrB...f+B...AL...3u...P.C...9K...Jv.....C..fBL...Lv..........fm...VBM.f...XVA............3OVA.......AbBlYlg+B...9C........f.A...9K....v...P.A...9C...3u...f+BA....P...f+B....D...HP..........D...3O.........BL..........C..fCL...Hv..........L...Dv...P.W...........C...AL...3u...f+....9yC...n.C...CL...3u...f+....AL...Hv...f+..........v...P.C........3u...f+.........3u...f+J.....P..........Pn...WBM.f...XQA............3OQA.......AbK.yLS8....CL...Dv...n.A....D....v...f.A....L..........A...CD...3u...P.A..fBD...DP...P.C....L........f+B....D...Dv...f+B...9C....v...P.C....L...Hv...f+B...AD...3O.........9C...Hv.....C...9C...Hv........fBL...3u.....C........3u.....A...9C...3u...f+F............J...lPC.H...VS.............9SS....PyLy8tflYFHP.....C...9K...3O...P.A....D...3u.....A...AL...DP.....C....b....P.A...AzA.....C....D...Jv...f+B...9C...Jv...f+....9S......C....LD...f+B...9C..........C...9C...Qv.....C...AD...Dv...f.C....D...Hv...f+B....L...3O..........Pf...f+L.........f+...........cB..jIz..B..fED............f+DD.......3uH....BD...3O...P.A...AL...3O...P.A.........P.....EH...NvA....AD...DPB...fBL..........z....3u...f.A...BL...DP.....C...BL........f+B....L...Dv...f+B....D...Jv...n.q....3O.........9C...Dv...f+B........Dv.....A...9K...3O...f+H....HP...........k...ZBM.f...XAA............3OAA........bA.........9C...3u.........9C...3OQ...fBD....P...v.A....L....P...f+.........Hv.....A...BL...Jv...P.A...9C...3u...f+.....L...3u...f+J....Dv...f+B...9KB.........AL...3u.....A...9C...3u...v.C..fBL...JvE....AL...Hv...P.C..fBL..........XI..vlPC.H...FP.............9CP.......n.U....3O........fBD...DP..........Pf...v.s....3u...P.C.........v...n.A...BL....v...n.A...9C........f+B...9a......C....b....f+B...96C...f.C..fBL...3u...n.C...BL........P.A..fBL...3O...f+B.........P...f+B...9C..........bI...mPC.H...VN.............9SN.........UfYlY3O...f+pYl4+K........f+....9SD...P.C........3OZlY9+.....D...3O.....C...9C........P.C...AD....v...P.C...BL...3O.........9K...3uE....AL...3O...f.C........3u...f+J....3O...P.C...ALA..........L...3O..........fj...cBM.f...X4.............3O4.........vH.....A...BD....v...f.C...9C........P.C....L........f+...fBL...Hv.........9K........P.A...CL...3O...P.C..fBD...3u.....C...BL...DP.........BL....v.....A........3u.........CD...HP...n.A..........TB..3Iz..B..fYC............f+XC.......DvC.....L...3u...f+....9S...........vD...P.A........JP.....C........3O........fBL...JP...f+B....L...3u...f.A...9K....v....AC........Hv..........vA...f.C...9C....P...f+....9K....P..........vj...eBM.f...Xy.............3Oy........AT...........f......A...AD...DPX.....D...Hv.....A...AD...3u...f.C........Hv.....A..fBL...3O.....C...9C...Dv...f+.....L....P.....C...9K........f.C...AL........f+....9S...........fj...fBM.f...Xv.............3Ov........9Sf...P.EH...3uA.....L....vF....CL...HP...n.C...CL...3O...f+B...96C.....A...9C....P...f+....AL...3O...P.C........Dv...f+.....L...DP...f+B...AD....P.....E............I..HnPC.H...1J.............9yJ.......f.EH...JPF....9K...3O...n.C...AD...HP...........B...f+.........3O...f.C...AL....v.....A...BL...HvA...fBL...JvH....9C..........C...9K...DP...f+B....D..........zH..PnPC.H...1J.............9yJ.......f.Y....vO...f.C....D...DP.....C...AL...DvAB....r....f.C...9C...3OAB....f......A...9K...3uG...fBL...Dv...f+.....D...Dv...f+....AD...DPA...........OB..FJz..B..fgB............f+fB........PC....9C...3u...f.A...BzB.....C...9C....P.....C...AD...Hv.........BL....P...P.A....L....vC.........Jv.....C....r......A...9K...3uB.....L..........zH..fnPC.H...lI.............9iI.........I....DP...........A...P.C...9K...HP.....C....bf...n.u....3u...f+....AD........f+B........3u.........AL...3u..........vi..fhBM.f...Xi.............3Oi.......fAz......A.........P.....c....Dv...P.A....D....v...P.C...AD...Hv...f.e....3O........fBL...Nv...P.C...BL...3u...f+J.....v..........vh...iBM.f...Xh.............3Oh....7+++Bz.7++++....Br+++GP9++e.of+++CP...f+....BL...3u...fzB....T....v...f+H...9K...Hs...fzN.....v.........9K...3uA...........LB..NJz..B..fAB............f+.B...PyLyEPB....9C...3u...f+F....3O...f+X....DP...v.A..fCL...Dv.....C...9K...3uH.....L...Hv...P.C...BL...3O.........9K..........nH...oPC.H...VG.............9SG.......f.o...........A....L...Hv...f+....9K...Dv...f+....BL...3u...f+F.....v.....a....3O..........L...HP...P.A..........HB..RJz..B..fwA............f+vA.......DPL....9K....P...n.A...BD...Dv.....A........Dv...v.C....L...Lv..........Pf...n.O....3O...f.C..........HB..TJz..B..fsA............f+rA.......3uAB...A7A...f.A...9K........f.C....L..........C....7....P.C...9K..........L....3O...P.A..........HB..VJz..B..fkA............f+jA.......3uN.....L...3O.....A...AD...3O...P.C.........v...f+B...AL...3u...f+.........3O...f+D...........bH..foPC.H...FF.............9CF.......P.E....3O...f+z....Hv...f+B...CD....v...f+B....D...Dv.....A...9K....v.........9K..........bH..noPC.H...lE.............9iE.......f+d.....v...P.C........HP...f+.........3O...f+P....3u...f.C...9C...Hv...f.G...........XH..voPC.H...VE.............9SE.....yLS8H....Dv.....C....r....f+B..........G....9K...DP...f+B........3u...f+...........FB..dJz..B..fQA............f+PA.......DvAB....DB...P.C...BD...3O...f+B.........v...f+B...9C...3OB....AD..........TH...pPC.H...1D.............9yD.......f+HH...DvA....9K...3uG....BD..........C....D....v...P.C..........EB..hJz..B..fIA............f+HA.........AB...9q....f+....AL...DvA.....L....vA....9K...3uAB....fg...oBM.f...XQ.............3OQ........9iA.........AD...Jv.....C........3u...f+FH....PB....BD..........PH..XpPC.H...FD.............9CD.........M....3O.....A...9K...3uC.....D...3u..........f....f+...........DB..nJz..B..f8.............f+7........3OD.........3O...f+B..........E.....D....v...f+B...9C..........LH..npPC.H...lC.............9iC........+HflYl+u...........A...f+.....L...3u...f+....9S...........vf...qBM.f...XM.............3OM.........LB...f+B...BD....v..........L...3u.....A..........CB..tJz..B..fw.............f+v..........H....9K...Dv...f+.....L....P...f+B....D..........HH...qPC.H...FC.............9CC.........gvLyL.v...n.A....L..........C...9K...Dv..........ff..frBM.f...XK.............3OK.........Pf.....I.........f+B...9q....P.C..........BB..zJz..B..fo.............f+n........3uGPyLy8K....v...f+.....D........f+B..........AB..1Jz..B..fo.............f+n........DPF....9C...3u.....C...BL...Jv..........ff...tBM.f...XI.............3OI........9iA...f+B....L...3O.....A...9K..........DH..nqPC.H...VB.............9SB.......P.M.....P..........L....vAB....ff...uBM.f...XH.............3OH........BDA...P.C........3u..........ff..fuBM.f...XH.............3OH........9aA.........9C....v...P.A..........AB...Kz..B..fc.............f+b........3uE.....L...3O..........D.............BKz..B..fc.............f+b.........vD.....D...3O...f+B..........AB..DKz..B..fc.............f+b........JPD.........Hv...P.C..........AB..FKz..B..fc.............f+b........3OA...........B....9K..........DH..frPC.H...1A.............9yA.........S.....P...f+B...9C..........DH..nrPC.H...1A.............9yA.........D.....v.....G...........HH..vrPC.H...1A.............9yA.......f+N....DP.....C..........BB..NKz..B..fc.............f+b........3OAB....b...........ff...zBM.f...XG.............3OG.........fg..fzBM.f...XG.............3OG........9y....f+B....D..........HH..PsPC.H...1A.............9yA.......P.O...........A..........BB..VKz..B..fc.............f+b........DPB....BL..........LH..fsPC.H...FA.............9CA.......f+J....3O.............nsPC.H...FA.............9CA.......f+J....3O.............vsPC.H...FA.............9CA.......f+H....3u.............3sPC.H...FA.............9CA.......f+H....3u..............tPC.H...FA.............9CA.........I.....v.............HtPC.H...FA.............9CA.........L3rRzcOC.H...TE.......pAA...GD...dP...5AA...HD..ffP...FBA..jHD..PiP...PBA..LID...lP...bBA...JD..fnP...jBA..XJD...pP...pBA...KD..fsPU....LoLQ9y.Cxwi+HzmQ9yjxD4OSJSj+HXJK43OALoLQ9yjxD4ODjxRN9y4.t3Oorji+bNfK9y4.t3OAtJlW8SfHEZQ+HvpkkxOveR69D..........A....LyLy7iYlY5OA.........P.....yLyL+XlYl9S..........D....vLyLyOlYlo+D..........A....LyLy7iYlY5OA.........P.....yLyL+XlYl9S.............vKD.....N........7SyLybOMyLS9....7i..........L.f...RA........9C.....C.H..fT........f+P....f.....C....P....P.....A........9C...3OA....D....P.....A....D........3O.........BD..PqPFA....v..B..HE...............L.f...RA....................L.f...RA...............C....b....P..........3.....D.........jBWO1C...3O.........7K...mP.....................................................L....fB....A.........fC....P.............uP.....MyLy7C....P..fkCA....vLyLyO...f+...VTD....PyLyL+....AD...............v.....J....D..........N.....A............HBA........3O.....A..fJD...7u...v.A...9C..nWQ.....A...7C...DP................A....D........3O...PAC....v.....C.........P.....E....P....P.....C....XOJb.TqGE9O...v+...gML.....C....T........3O...bBC...KL...rv...vBW....fTI0YN.....................T...............................D..........D....D....v........H.oLyL8C...7O...MBA....v.....E.......vIL...3O...vBC...KL...rvE.........fTI0gN................E...............................A..........A....A....L.....zQgqOcT3p+jBWO9CNcMtPeQ+gCU....PA.......HAC...GL...mv...bBC..vIbA....WbaT4.....................PA..............................P..........P....P.....C....7Qgq6iT354Oov0i+...hKD..HqvE....T........bv...HAC..vIL...mv...bBW..........RkTm4................T...............................D..........D.........v.....35Qw+ziBW8iqGE9O................E.......vIL...mv...bBC..vIL...mvE...............................E...............................A....................D....v.....RgqG+vdT35qYlY5O...jAA...............D.........."
													}
,
													"fileref" : 													{
														"name" : "Pianoteq 8",
														"filename" : "Pianoteq 8.maxsnap",
														"filepath" : "~/Documents/Max 8/Snapshots",
														"filepos" : -1,
														"snapshotfileid" : "09a0adfccb3bfbb9efc19fc3b22175d1"
													}

												}
, 												{
													"filetype" : "C74Snapshot",
													"version" : 2,
													"minorversion" : 0,
													"name" : "Pianoteq 8",
													"origin" : "Pianoteq 8.vstinfo",
													"type" : "VST",
													"subtype" : "Instrument",
													"embed" : 0,
													"fileref" : 													{
														"name" : "Pianoteq 8",
														"filename" : "Pianoteq 8_20231128.maxsnap",
														"filepath" : "~/Documents/Max 8/Snapshots",
														"filepos" : -1,
														"snapshotfileid" : "529be11e851fd1e9a73179bd88d90b72"
													}

												}
 ]
										}

									}
,
									"text" : "vst~",
									"varname" : "vst~[1]",
									"viewvisibility" : 0
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 444.571428571428555, 248.0, 360.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80300
									}
,
									"text" : "bach.playkeys midinote velocity duration @out m @mtsesp 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 2,
									"outlettype" : [ "int", "" ],
									"patching_rect" : [ 444.571428571428555, 361.0, 108.0, 23.0 ],
									"text" : "midiformat"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 444.571428571428555, 331.0, 108.0, 23.0 ],
									"text" : "join"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "float", "float" ],
									"patching_rect" : [ 444.571428571428555, 287.0, 360.0, 23.0 ],
									"text" : "makenote"
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 80300,
									"clefs" : [ "FFGG" ],
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-1",
									"loop" : [ 0.0, 1000.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 119.0, 401.0, 302.666666666666629 ],
									"pitcheditrange" : [ "null" ],
									"showcents" : 1,
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 8,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "annotation", "]", "[", "type", "text", "]", "[", "key", "t", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4276041736, 1084407807, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085058048, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4276041736, 1085022207, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085006848, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2053073026, 1085328884, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084955648, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081262080, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4285504516, 1085456383, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084904448, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1846204023, 1085704403, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084853248, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4285504516, 1085763583, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084802048, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082310656, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4115608831, 1085815784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084750848, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082515456, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1679513257, 1085904721, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084699648, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082720256, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2053073026, 1085943284, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084648448, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082925056, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1846204023, 1086011603, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084597248, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083129856, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3387731526, 1086042180, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084546048, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083256832, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2502371982, 1086097652, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084494848, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083359232, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1325195721, 1086169680, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084443648, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083461632, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2659854221, 1086268576, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084392448, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083564032, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1846204023, 1086318803, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084341248, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083666432, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3778497404, 1086329545, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084290048, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083768832, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1693865763, 1086337058, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084238848, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083871232, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2371568462, 1086344324, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084147712, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083973632, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1251185991, 1086364794, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084045312, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084076032, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3737914909, 1086371217, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083942912, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084178432, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2057804416, 1086377460, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083840512, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084254208, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2855995722, 1086389441, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083738112, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084305408, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1139113931, 1086416834, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083635712, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084356608, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3654569527, 1086471376, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083533312, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084407808, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2371568462, 1086497924, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083430912, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084459008, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4018508179, 1086511778, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083328512, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084510208, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1282274088, 1086515111, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083226112, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084561408, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2057804416, 1086531060, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083068416, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084612608, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4238306907, 1086559879, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082863616, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084663808, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1918515241, 1086567842, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082658816, 100, 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ],
									"zoom" : 236.37109375
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 73.0, 679.0, 36.0 ],
									"text" : "If you want microtonal playback in an MTS-ESP-compliant vst~ plugin, you can simply activate the @mtsesp attribute and bach.playkeys will take care of sending all the appropriate detuning information"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"midpoints" : [ 346.928571428571445, 431.666666666666629, 429.5, 431.666666666666629, 429.5, 237.0, 454.071428571428555, 237.0 ],
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"midpoints" : [ 278.5, 506.0, 427.0, 506.0, 427.0, 244.0, 454.071428571428555, 244.0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-24", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"source" : [ "obj-26", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"midpoints" : [ 454.071428571428555, 356.0, 454.071428571428555, 356.0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 1 ],
									"midpoints" : [ 795.071428571428555, 321.0, 543.071428571428555, 321.0 ],
									"source" : [ "obj-28", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"midpoints" : [ 454.071428571428555, 339.0, 454.071428571428555, 339.0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 2 ],
									"source" : [ "obj-29", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 1 ],
									"source" : [ "obj-29", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-29", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 106.0, 351.0, 61.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p mts-esp",
					"varname" : "basic_tab[9]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-3",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 612.75, 445.0, 68.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 545.749999999999886, 348.5, 96.0, 55.0 ],
									"text" : "Marker onsets only"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 461.750000000000114, 348.5, 81.999999999999773, 55.0 ],
									"text" : "Measure onsets only"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-14",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 373.946532999999988, 348.5, 76.0, 55.0 ],
									"text" : "Notes and chords"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.06,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.000061000000002, 360.0, 172.0, 84.0 ],
									"text" : "No wrapping = a default behavior happens (e.g.: onsets are only output for notes, chords and rests)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 13.499969, 69.567627000000002, 665.267944000000057, 50.0 ],
									"text" : "You can wrap properties in a level of parenthesis to specify they only apply to a given category of notation items (\"note\", \"chord\", \"rest\", \"measure\", \"marker\", etc.).\nWith no wrapping, a default behavior is used."
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-12",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 13.571410999999999, 374.0, 50.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-10",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 533.75, 445.0, 68.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-9",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 405.75, 445.0, 68.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-6",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 277.75, 441.0, 68.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 277.75, 398.0, 403.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80104
									}
,
									"text" : "bach.playkeys onset [measure onset] [marker onset duration] @out t"
								}

							}
, 							{
								"box" : 								{
									"attr" : "playmeasures",
									"id" : "obj-8",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 131.0, 160.0, 23.0 ],
									"text_width" : 128.0
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 70909,
									"constraintbeamsinspaces" : 0,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-4",
									"loop" : [ "[", 1, 1, 0, "]", "[", 1, 2, 0, "]" ],
									"maxclass" : "bach.score",
									"numinlets" : 7,
									"numoutlets" : 9,
									"numvoices" : 1,
									"out" : "nnnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 172.0, 325.0, 90.0 ],
									"pitcheditrange" : [ "null" ],
									"playmeasures" : 1,
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 26.0 ],
									"whole_score_data_0000000000" : [ "score", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "markers", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1083960438, "freemarker", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3444077549, 1085974552, "freemarker2", "none", "]", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 100, 0, 0, "]", 0, "]", "]", 0, "]", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, 0, "]", 0, "]", "]", 0, "]", 0, "]" ],
									"whole_score_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 403.0, 116.0, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 365.0, 116.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1 ],
									"bwcompatibility" : 70906,
									"clefs" : [ "G", "G" ],
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0 ],
									"id" : "obj-1",
									"keys" : [ "CM", "CM" ],
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"midichannels" : [ 1, 1 ],
									"notationstyles" : [ "et", "" ],
									"numinlets" : 6,
									"numoutlets" : 8,
									"numparts" : [ 1, 1 ],
									"numvoices" : 2,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 365.0, 159.0, 267.0, 142.0 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]", "[", "]" ],
									"voicespacing" : [ 0.0, 17.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "[", "[", "region", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082966016, "_x_x_x_x_bach_float64_x_x_x_x_", 4294967294, 1083322367, "]", "[", "marker", 1, "]", "none", "]", "]", "[", "midichannels", 1, 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080819712, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082249216, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083416576, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082249216, 100, 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083600896, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081139200, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083736064, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081139200, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083994112, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081139200, 100, 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 13.571410999999999, 335.0, 170.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys onset @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"order" : 0,
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"order" : 1,
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-17", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-17", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-17", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"order" : 0,
									"source" : [ "obj-4", 7 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"order" : 1,
									"source" : [ "obj-4", 7 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 18.0, 110.0, 140.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p \"filter by notation item\"",
					"varname" : "basic_tab[8]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-16",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 347.0, 433.0, 308.0, 40.0 ],
									"text" : "As the previous one, but also accepts all standard routers"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-15",
									"linecount" : 2,
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 10.0, 433.0, 330.0, 38.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [pippo cents] [toto cents] [foo duration] @routers + [note pippo] [chord toto] [rest foo]"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 319.0, 246.0, 68.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 34.0, 132.0, 147.0, 23.0 ],
									"text" : "sel all, sendcommand 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 319.0, 193.0, 190.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [notecmd cents]"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 104.0, 425.0, 23.0 ],
									"text" : "[commands [1 [note notecmd] [chord chordcmd] [rest restcmd] [key c]]]"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1, 7 ],
									"bwcompatibility" : 70911,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-6",
									"loop" : [ 0.0, 1000.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 166.0, 273.0, 93.0 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "restcmd", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", "c", "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1081554651, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1071661316, "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1079608999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1071750084, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1078727215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", "[", "name", "pippo", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086160384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082525696, 100, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1071115603, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083027456, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1071661316, "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1079608999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1071750084, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1078727215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 7, "foo", "]", "]", "[", "name", "pluto", "]", 0, "]", "[", "name", "paperino", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1083424694, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082525696, 100, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1071115603, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083027456, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1071661316, "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1079608999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1071750084, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1078727215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", "[", "name", "pluto", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086211584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082525696, 100, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1071115603, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083027456, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1071661316, "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1079608999, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1071750084, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1078727215, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", "[", "name", "pluto", "]", 0, "]", "[", "name", "pippo", "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 353.642822000000024, 379.5, 308.0, 54.0 ],
									"text" : "Accept \"pippo\" command as note-command, \"toto\" command as chord-command, and \"foo\" as rest-command"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-8",
									"linecount" : 2,
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 10.0, 384.0, 330.0, 38.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [pippo cents] [toto cents] [foo duration] @routers [note pippo] [chord toto] [rest foo]"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 382.642822000000024, 323.5, 250.0, 54.0 ],
									"text" : "Tell bach.playkeys that pippo operates on notes (and hence handles other attributes accordingly)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 339.0, 363.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [pippo cents] @routers note [note pippo pluto]"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 282.0, 486.0, 36.0 ],
									"text" : "You might want to explicitly provide the information about the type of item the command refers to (note, chord, rest) via the routers attribute:"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 73.0, 679.0, 21.0 ],
									"text" : "bach.playkeys can intercept commands; in most cases, setting an llll with command name as firt element is enough:"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.881896999999981, 57.567627000000002 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-6", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 80.5, 316.0, 79.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p commands",
					"varname" : "basic_tab[7]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 461.0, 320.0, 21.0 ],
									"text" : "There is a bit more on routers: see the commands tab"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 341.5, 173.0, 34.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 633.5, 261.0, 24.0, 24.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 507.5, 261.0, 24.0, 24.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 507.5, 228.5, 146.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys play end"
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 70907,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-6",
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 341.5, 202.0, 151.0, 76.0 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080131584, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080950784, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081589760, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086147584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080262656, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082179584, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081114624, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082720256, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080049664, 100, 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 208.0, 324.0, 50.0 ],
									"text" : "In addition to these, also \"play\", \"stop\", \"pause\", \"end\" keys are allowed; they will report the corresponding actions with a bang:"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 2,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 255.0, 339.0, 207.0, 40.0 ],
									"text" : "Only accept notes and markers"
								}

							}
, 							{
								"box" : 								{
									"attr" : "routers",
									"id" : "obj-7",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 234.232116999999988, 376.0, 218.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 289.0, 648.0, 36.0 ],
									"text" : "bach.playkeys can interpret playout messages with the following routers: \"note\", \"chord\", \"marker\", \"tempo\", \"measure\". You can allow the reception of a subsection of these messages via the \"routers\" attribute:"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"linecount" : 2,
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 234.232116999999988, 410.0, 152.0, 38.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys onset @routers note marker"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"linecount" : 7,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 69.567627000000002, 683.0, 108.0 ],
									"text" : "Allowed properties to retrieve correspond to the following symbols:\n\"type\", \"onset\", \"symonset\", \"cents\", \"pitch\", \"duration\", \"symduration\", \"tail\", \"velocity\", \"midichannel\", \"tie\", \"voicenumber\", \"path\" (only meaningful if \"playoutfullpath\" is active for the notation object), \"chordindex\", \"noteindex\", \"measurenumber\" (these last three only meaningful for notes and chords if \"playoutfullpath\" is active for the notation object), \"breakpoints\", \"measureinfo\", \"name\", tempo\", \"quartertempo\" (be sure you have @playtempi 1 in your bach.score), \"slot\", \"playoffset\" (for partial played notes with @playpartialnotes set to 2), \"role\" for markers only, \"slots\" (outputs all slots)"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-6", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-8", 1 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 63.5, 287.0, 58.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p routers",
					"varname" : "basic_tab[6]"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 73.0, 641.0, 21.0 ],
									"text" : "There are shortcuts for picking dynamics-, articulations-, notehead- and lyrics-slots."
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-9",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 383.0, 285.0, 284.0, 69.0 ],
									"text" : "use these symbols as shortcuts for their corresponding slots, settable via attributes \n(by default they coincide with bach.roll's and bach.score's defaults)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 359.0, 360.0, 77.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print L"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 260.333344000000011, 360.0, 79.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print N"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 161.666655999999989, 360.0, 78.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print A"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 63.0, 360.0, 81.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print D"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 63.0, 308.0, 315.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys dynamics articulations notehead lyrics"
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 70909,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-7",
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 108.0, 526.0, 120.0 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1082140964, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 20, "[", "auto", "ff", "<<", "]", "]", "[", 22, "acc", "]", "[", 23, "plus", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083748352, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 20, "[", "auto", "ffff", "=", "]", "]", "[", 22, "acc", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1610612736, 1084382939, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086096384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081692160, 100, "[", "slots", "[", 21, "foo", "]", "[", 22, "acc", "acc", "]", "[", 23, "cross", "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-1", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-1", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-7", 6 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 51.5, 250.0, 48.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p more",
					"varname" : "basic_tab[5]"
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 450.125, 393.0, 114.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print AllSlots"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 329.625, 393.0, 101.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print Slot1"
								}

							}
, 							{
								"box" : 								{
									"attr" : "playmode",
									"id" : "obj-7",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 109.0, 151.0, 294.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 209.125, 393.0, 105.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print Cents"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 209.125, 352.0, 260.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys cents [slot 1] slots"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 156.0, 36.0, 23.0 ],
									"text" : "stop"
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
									"patching_rect" : [ 14.0, 156.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1 ],
									"bwcompatibility" : 7910,
									"constraintbeamsinspaces" : 0,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-4",
									"linkdynamicstoslot" : 0,
									"loop" : [ "[", 1, 1, 0, "]", "[", 1, 1, 0, "]" ],
									"maxclass" : "bach.score",
									"numinlets" : 7,
									"numoutlets" : 9,
									"numvoices" : 1,
									"out" : "nnnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 14.0, 224.0, 242.0, 103.0 ],
									"pitcheditrange" : [ "null" ],
									"playmode" : 0,
									"spacingwidth" : 1.8,
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 9.0 ],
									"vzoom" : 98.181815999999998,
									"whole_score_data_0000000000" : [ "score", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 2, "]", "[", "3/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 127, 0, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1078714003, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1071267218, "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 1078159132, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1078988071, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 127, 0, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071012448, "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1079589182, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1071394603, "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1078529046, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2509765109, 1067930412, "_x_x_x_x_bach_float64_x_x_x_x_", 2672424095, 1072122356, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 48560823, 1070885063, "_x_x_x_x_bach_float64_x_x_x_x_", 1622543201, 1070642699, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 64, 64, 103, "]", "]", 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 57, 0, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1079311746, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 57, 0, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1079311746, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 64, 64, 103, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 57, 0, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071012448, "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1079589182, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1071394603, "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1078529046, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 127, 0, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071328714, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1070738837, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079820379, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071682297, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1078898961, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1079311746, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "-1/4", 0, "]", "]", 0, "]", 0, "]" ],
									"whole_score_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 76.0, 645.0, 36.0 ],
									"text" : "bach.playkeys also works with playmode set to \"chordwise\". In this case, it outputs lists with all the requested parameters"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-1", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-4", 7 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 33.5, 220.0, 75.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p chordwise",
					"varname" : "basic_tab[3]"
				}

			}
, 			{
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 295.0, 190.0, 310.0, 55.0 ],
									"text" : "Output the default set of breakpoints whenever a note has no non-trivial mid-point breakpoints."
								}

							}
, 							{
								"box" : 								{
									"attr" : "defaultbreakpoints",
									"id" : "obj-3",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 270.767882999999983, 165.0, 239.0, 23.0 ],
									"text_width" : 170.0
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-13",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 13.499969, 69.567627000000002, 665.267944000000057, 21.0 ],
									"text" : "The nullmode attribute tells when a \"null\" should be output for an llll parameter (such as breakpoints or slots)."
								}

							}
, 							{
								"box" : 								{
									"attr" : "breakpointshavevelocity",
									"id" : "obj-11",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 295.0, 277.0, 239.0, 23.0 ],
									"text_width" : 170.0
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 311.767882999999983, 302.0, 286.0, 40.0 ],
									"text" : "Also output note velocity for default breakpoints"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-41",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 237.267883000000012, 438.0, 172.0, 23.0 ],
									"text" : "print Breakpoints @popup 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 48.0, 93.0, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 93.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1, 2, 3 ],
									"bwcompatibility" : 7910,
									"clefs" : [ "G", "F" ],
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0 ],
									"id" : "obj-1",
									"keys" : [ "CM", "CM" ],
									"linkdynamicstoslot" : 0,
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"midichannels" : [ 1, 2 ],
									"notationstyles" : [ "et", "" ],
									"numinlets" : 6,
									"numoutlets" : 8,
									"numparts" : [ 1, 1 ],
									"numvoices" : 2,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 122.0, 251.0, 175.0 ],
									"pitcheditrange" : [ "null" ],
									"showstems" : 0,
									"stafflines" : [ 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]", "[", "]" ],
									"voicespacing" : [ 0.0, 6.0, 8.0 ],
									"vzoom" : 120.0,
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1083071341, "[", "marker", 1, "]", "none", "]", "]", "[", "midichannels", 1, 2, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080705024, "[", "Cd6", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082384384, 127, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071849110, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083369472, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070031109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079670101, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070760484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072064421, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 64, 28, 98, "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081085952, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081221120, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079496704, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3219372987, "]", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082597376, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081085952, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083226112, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085443584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082222592, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083604992, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083000832, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3219757465, "]", "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 237.267883000000012, 394.0, 206.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys breakpoints @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.881896999999981, 57.567627000000002 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 27.0, 167.0, 83.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p breakpoints",
					"varname" : "basic_tab[4]"
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-25",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 336.767882999999983, 190.567626999999987, 328.0, 65.0 ],
									"text" : "E.g.: with nullmode 1, a \"null\" is output for (slot 1) key when a note having no slot 1 is played. However, nothing is output when a marker is played (markers have no slots)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 346.767882999999983, 296.567627000000016, 318.0, 36.0 ],
									"text" : "E.g.: with nullmode 2, a \"null\" is output for the (slot 1) key even when a marker is played"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-22",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 400.267882999999983, 254.567626999999987, 237.0, 40.0 ],
									"text" : "With nullmode 2, null is output for any key without a match"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-21",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 324.267882999999983, 266.567627000000016, 74.0, 23.0 ],
									"text" : "nullmode 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 302.767882999999983, 153.567626999999987, 74.0, 23.0 ],
									"text" : "nullmode 1"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 383.767882999999983, 134.567626999999987, 260.0, 54.0 ],
									"text" : "With nullmode 1 (default), null is always output for empty keys compatible with the output notation item"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 272.767882999999983, 106.567627000000002, 74.0, 23.0 ],
									"text" : "nullmode 0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 13.499969, 69.567627000000002, 665.267944000000057, 21.0 ],
									"text" : "The nullmode attribute tells when a \"null\" should be output for an llll parameter (such as breakpoints or slots)."
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-12",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 353.767882999999983, 106.567627000000002, 237.0, 25.0 ],
									"text" : "With nullmode 0, null is never output"
								}

							}
, 							{
								"box" : 								{
									"attr" : "nullmode",
									"id" : "obj-11",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 302.767882999999983, 416.0, 239.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-9",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 111.767882999999998, 340.0, 330.0, 69.0 ],
									"text" : "If you set the \"breakpointshavevelocity\" attribute to 1, when nullmode is 0 and when a note has no inner pitch breakpoints, the note velocity is output as last element along with the default breakpoint data"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "toggle",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 40.767882999999998, 383.0, 20.0, 20.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 40.767882999999998, 411.0, 167.0, 23.0 ],
									"text" : "breakpointshavevelocity $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-41",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 258.267882999999983, 487.0, 133.0, 23.0 ],
									"text" : "print Slot1 @popup 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 48.0, 93.0, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 93.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1, 2, 3 ],
									"bwcompatibility" : 7910,
									"clefs" : [ "G", "F" ],
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0 ],
									"id" : "obj-1",
									"keys" : [ "CM", "CM" ],
									"linkdynamicstoslot" : 0,
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"midichannels" : [ 1, 2 ],
									"notationstyles" : [ "et", "" ],
									"numinlets" : 6,
									"numoutlets" : 8,
									"numparts" : [ 1, 1 ],
									"numvoices" : 2,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 122.0, 251.0, 175.0 ],
									"pitcheditrange" : [ "null" ],
									"showstems" : 0,
									"stafflines" : [ 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]", "[", "]" ],
									"voicespacing" : [ 0.0, 6.0, 8.0 ],
									"vzoom" : 120.0,
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1083071341, "[", "marker", 1, "]", "none", "]", "]", "[", "midichannels", 1, 2, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080705024, "[", "Cd6", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082384384, 127, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071849110, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083369472, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070031109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079670101, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070760484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072064421, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 64, 28, 98, "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081085952, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081221120, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079496704, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3219372987, "]", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082597376, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081085952, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083226112, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085443584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082222592, 100, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083604992, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083000832, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3219757465, "]", "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 258.267882999999983, 455.0, 178.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [slot 1] @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 24.0, 141.0, 69.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p nullmode",
					"varname" : "basic_tab[2]"
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-10",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 294.0, 407.067627000000016, 108.0, 40.0 ],
									"text" : "Retrieve all slots"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 301.0, 383.567627000000016, 114.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print AllSlots"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-21",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 441.642822000000024, 392.567627000000016, 172.0, 69.0 ],
									"text" : "Use slot names (when \"outputslotnames\" is active for the notation object)"
								}

							}
, 							{
								"box" : 								{
									"attr" : "outputslotnames",
									"id" : "obj-19",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 421.5, 83.567627000000002, 203.0, 23.0 ],
									"text_width" : 127.5
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-4",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 382.0, 83.567627000000002, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 344.0, 83.567627000000002, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1, 2, 3 ],
									"bwcompatibility" : 7910,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-8",
									"linkdynamicstoslot" : 0,
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"outputslotnames" : 1,
									"patching_rect" : [ 344.0, 134.567626999999987, 310.0, 100.0 ],
									"pitcheditrange" : [ "null" ],
									"showstems" : 0,
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 6.0 ],
									"vzoom" : 96.039603999999997,
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "myfunction", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "mynumbers", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080705024, "[", "Cd6", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082384384, 127, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071849110, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070668639, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1078142266, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 112, 64, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083369472, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070031109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079670101, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070760484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072064421, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 3218932585, "]", "]", "[", 3, 64, 28, 98, "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 544.5, 355.067627000000016, 80.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print B"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 426.142822000000024, 355.067627000000016, 79.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print A"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 426.142822000000024, 283.567627000000016, 198.357178000000005, 38.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [slot \"amplitude envelope\" mynumbers]"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 48.0, 74.567627000000002, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 74.567627000000002, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1, 2, 3 ],
									"bwcompatibility" : 7910,
									"defaultnoteslots" : [ "null" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-3",
									"linkdynamicstoslot" : 0,
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"numinlets" : 6,
									"numoutlets" : 8,
									"numvoices" : 1,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 134.567626999999987, 310.0, 100.0 ],
									"pitcheditrange" : [ "null" ],
									"showstems" : 0,
									"stafflines" : [ 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]" ],
									"voicespacing" : [ 0.0, 6.0 ],
									"vzoom" : 96.039603999999997,
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085648384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082384384, 127, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071849110, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3511608479, 1066408386, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 459210337, 1071460017, "_x_x_x_x_bach_float64_x_x_x_x_", 486527785, 1079233955, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 112, 64, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086057984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082384384, 127, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071849110, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082081280, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070668639, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1078142266, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 3, 112, 64, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083359232, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082427392, 100, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070031109, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079670101, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1070760484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072064421, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078390328, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 3218932585, "]", "]", "[", 3, 64, 28, 98, "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-20",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 89.000061000000002, 379.567627000000016, 172.0, 40.0 ],
									"text" : "Set multiple slots at once"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 271.000061000000017, 344.567627000000016, 81.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print D"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 188.000060999999988, 344.567627000000016, 81.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print C"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 104.750068999999996, 344.567627000000016, 80.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print B"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 22.000091999999999, 344.567627000000016, 79.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print A"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "" ],
									"patching_rect" : [ 22.000091999999999, 307.067627000000016, 350.999969000000021, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys [slot 1 3 2 1] slots"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpname.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys" ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-17", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-3", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-5", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-5", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"source" : [ "obj-5", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-5", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-17", 0 ],
									"source" : [ "obj-8", 6 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 30.0, 192.0, 45.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p slots",
					"varname" : "basic_tab[1]"
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
					"patching_rect" : [ 299.0, 205.0, 170.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
					"text" : "js helpstarter.js bach.playkeys"
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-16",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 547.857177999999976, 421.5, 42.0, 21.0 ],
									"text" : "voice"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 495.0, 421.5, 53.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 574.0, 343.0, 68.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 285.0, 336.0, 51.0, 23.0 ],
									"text" : "routers"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 451.0, 421.5, 42.0, 21.0 ],
									"text" : "onset"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-13",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 398.142853000000002, 421.5, 50.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 593.142822000000024, 421.5, 101.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.print Slot1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 365.333312999999976, 421.5, 27.0, 21.0 ],
									"text" : "vel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 270.0, 421.5, 42.0, 21.0 ],
									"text" : "cents"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 2.142853, 407.5, 214.0, 54.0 ],
									"text" : "Each parameter is output from the corresponding outlet, as for bach.keys"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubblepoint" : 0.77,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-6",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 409.0, 123.0, 212.0, 54.0 ],
									"text" : "Select a note and press V (to play it in off-line mode), or use the \"play\" \"stop\" commands"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-28",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 359.0, 154.0, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 48.0, 152.0, 36.0, 23.0 ],
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 310.142853000000002, 421.5, 53.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"bubbleside" : 3,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 18.142852999999999, 362.5, 198.0, 40.0 ],
									"text" : "Set the parameters you need to extract in the object box"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"format" : 6,
									"id" : "obj-10",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 222.142853000000002, 421.5, 50.0, 23.0 ]
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
									"patching_rect" : [ 323.0, 154.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-7",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 10.0, 152.0, 35.0, 23.0 ],
									"text" : "play"
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 7910,
									"clefs" : [ "G", "G" ],
									"constraintbeamsinspaces" : 0,
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0 ],
									"id" : "obj-4",
									"keys" : [ "CM", "CM" ],
									"linkdynamicstoslot" : 0,
									"loop" : [ "[", 1, 1, 0, "]", "[", 1, 1, 0, "]" ],
									"maxclass" : "bach.score",
									"midichannels" : [ 1, 2 ],
									"notationstyles" : [ "et", "" ],
									"numinlets" : 7,
									"numoutlets" : 9,
									"numparts" : [ 1, 1 ],
									"numvoices" : 2,
									"out" : "nnnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 323.0, 185.0, 298.0, 142.0 ],
									"pitcheditrange" : [ "null" ],
									"showmeasurenumbers" : [ 1, 1 ],
									"spacingwidth" : 1.8,
									"stafflines" : [ 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"tonedivision" : 4,
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]", "[", "]" ],
									"voicespacing" : [ 0.0, 9.0, 0.0 ],
									"vzoom" : 98.181815999999998,
									"whole_score_data_0000000000" : [ "score", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", "a", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", "q", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 3, "[", "name", "slot longlist", "]", "[", "type", "intlist", "]", "[", "key", "w", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", "e", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 5, "[", "name", "slot long", "]", "[", "type", "int", "]", "[", "key", "r", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", "t", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", "y", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", "u", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 9, "[", "name", "spat", "]", "[", "type", "spat", "]", "[", "key", "i", "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 10, "[", "name", "slot 10", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "singleslotfortiednotes", 1, "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "notecmd", "]", "[", "chord", "chordcmd", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "markers", "[", "[", 2, 1, "9/16", "]", "[", "marker", 1, "]", "none", "]", "]", "[", "midichannels", 1, 2, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 127, 1, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085840384, 117, 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086019584, 127, 0, 0, "]", 0, "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301184, 57, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 127, 0, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1071328714, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "-1/4", 0, "]", "]", 0, "]", 0, "]", "[", "[", "[", "[", 4, 4, "]", "[", "]", "]", "[", "leveltype", 1, "]", "[", "[", "leveltype", 8, "]", "[", "1/4", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, 100, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, 100, 0, 0, "]", 0, "]", "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085942784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, 100, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, 100, 0, 0, "]", 0, "]", "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, "]", 0, "]", "]", "[", "[", "leveltype", 8, "]", "[", "[", "leveltype", 1, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086121984, 100, 0, 0, "]", 0, "]", "[", "1/16", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086173184, 100, 0, 0, "]", 0, "]", "]", "[", "1/8", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, 100, 0, 0, "]", 0, "]", "]", 0, "]", 0, "]" ],
									"whole_score_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"bgslots" : [ 1 ],
									"bwcompatibility" : 70906,
									"clefs" : [ "G", "G" ],
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0 ],
									"id" : "obj-1",
									"keys" : [ "CM", "CM" ],
									"loop" : [ 0.0, 0.0 ],
									"maxclass" : "bach.roll",
									"midichannels" : [ 1, 1 ],
									"notationstyles" : [ "et", "" ],
									"numinlets" : 6,
									"numoutlets" : 8,
									"numparts" : [ 1, 1 ],
									"numvoices" : 2,
									"out" : "nnnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "" ],
									"patching_rect" : [ 10.0, 185.0, 267.0, 142.0 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80300,
									"voicenames" : [ "[", "]", "[", "]" ],
									"voicespacing" : [ 0.0, 17.0, 17.0 ],
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "amplitude envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "duration", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "foo", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "slot 20", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "slot 21", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "slot 22", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "slot 23", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082966016, "[", "marker", 1, "]", "none", "]", "]", "[", "midichannels", 1, 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081393152, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082656768, 82, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1071052887, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083129856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1072003287, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3229794304, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1070069762, "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 1079462024, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1070987437, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078385705, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "fee", "]", "[", 3, 120, 71, 107, 107, 64, 63, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082656768, 82, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3758096384, 1071052887, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083129856, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1072003287, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 3229794304, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1070069762, "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 1079462024, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1070987437, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078385705, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "[", 2, "fee", "]", "[", 3, 120, 71, 107, 107, 64, 63, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083539456, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082454016, 100, 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080426496, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082451968, 62, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 1069702690, "_x_x_x_x_bach_float64_x_x_x_x_", 2684354560, 1079263195, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3221225472, 1071428373, "_x_x_x_x_bach_float64_x_x_x_x_", 1073741824, 1078431944, "_x_x_x_x_bach_float64_x_x_x_x_", 536870912, 1070956806, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083465728, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085814784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081135104, 78, 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083871232, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082451968, 65, "[", "slots", "[", 1, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 1067605538, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "_x_x_x_x_bach_float64_x_x_x_x_", 2147483648, 3218775998, "]", "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "" ],
									"patching_rect" : [ 222.142853000000002, 371.0, 371.0, 23.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"text" : "bach.playkeys cents velocity onset voicenumber [slot 1] @out t"
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpdetails.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "bach.playkeys", 100 ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 529.5, 104.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-1", 6 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"order" : 0,
									"source" : [ "obj-4", 7 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"order" : 1,
									"source" : [ "obj-4", 7 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-49", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-49", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-49", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"source" : [ "obj-49", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 85.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
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
					"jsarguments" : [ "bach.playkeys" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 10.0, 295.85601806640625, 57.599853515625 ]
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
							"major" : 8,
							"minor" : 6,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 908.0, 522.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [  ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 205.0, 205.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
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
		"parameters" : 		{
			"obj-13::obj-24" : [ "vst~[1]", "vst~[1]", 0 ],
			"parameterbanks" : 			{
				"0" : 				{
					"index" : 0,
					"name" : "",
					"parameters" : [ "-", "-", "-", "-", "-", "-", "-", "-" ]
				}

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "Pianoteq 8.maxsnap",
				"bootpath" : "~/Documents/Max 8/Snapshots",
				"patcherrelativepath" : "../../../Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "Pianoteq 8_20231128.maxsnap",
				"bootpath" : "~/Documents/Max 8/Snapshots",
				"patcherrelativepath" : "../../../Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "bach.playkeys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpname.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpstarter.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
