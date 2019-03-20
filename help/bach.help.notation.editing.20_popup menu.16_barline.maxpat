{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 238.0, 79.0, 617.0, 539.0 ],
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
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-16",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 441.0, 385.5, 118.0, 40.0 ],
					"presentation_linecount" : 3,
					"text" : "Barline only between voices",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 405.0, 369.5, 98.0, 25.0 ],
					"text" : "Small tick",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubblepoint" : 0.12,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 121.0, 347.5, 226.0, 40.0 ],
					"text" : "Solid barline (single barline, but thicker than the normal one)",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 51.0, 326.5, 302.0, 25.0 ],
					"text" : "Hidden barline (use it for \"no barline\" situations)",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 255.0, 299.5, 98.0, 25.0 ],
					"text" : "Final barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 242.0, 280.5, 111.0, 25.0 ],
					"text" : "Double barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 242.0, 260.5, 114.0, 25.0 ],
					"text" : "Pointed barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 232.5, 233.5, 115.0, 25.0 ],
					"text" : "Dashed barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 202.0, 214.5, 150.0, 25.0 ],
					"text" : "Normal single barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 242.0, 108.5, 273.0, 84.0 ],
					"text" : "The default barline depends on the position of the barline inside the score: if at the end, it will be displayed as final, otherwise it will displayed as the standard single barline."
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 159.0, 187.5, 180.0, 25.0 ],
					"text" : "Default (automatic) barline",
					"textcolor" : [ 0.50196099281311, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-76",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 34.0, 568.0, 36.0 ],
					"text" : "If you right-click or perform a two-finger tap on a measure barline, the associated popup menu appears, allowing you to choose the barline type.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
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
					"patching_rect" : [ 6.0, 514.0, 341.0, 19.0 ],
					"text" : "See Also: rhythmic",
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
					"patching_rect" : [ 6.0, 495.0, 585.0, 19.0 ],
					"text" : "Objects: bach.score",
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
					"patching_rect" : [ 6.0, 10.0, 403.0, 23.0 ],
					"text" : "Popup menu for measure barlines",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 585.0, 31.0 ],
					"text" : "Tags: editing, edit, interface, popup, menu, contextual, right, click, two, finger, tap, measure, barline, tick, double, single, point, pointed, final, hidden, solid, intervoices, voice, auto",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 37016, "png", "IBkSG0fBZn....PCIgDQRA..DvC..HvSHX.....jLPrs....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6cmGlaUV2+G+cxrzMJPAokBTZKEnHXYqrnPYozBVjVJnfJfKfrTDWXGE7QKUT5ihfH+3gUQPYQAWdrzJBO.1JTP1EJ0Jn.cAFJEj1Bca5rj76OtyYlIYlLSxLYljI88qqq4JSRN4bty1LI2mOmueiUSM0jDIIIIIIIoxHwK1C.IIIIIIIoBMmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wI7PRRRRRRRkcbBOjjjjjjjTYmJ6J234Lm4TnFGRRRRRRRR.vjm7j6xqCS3gjjjjjjjJ6zkR3QjpqtZ.Xq25stPr55wjLYxbZ4hEKV27HQRRRRRRZSWu+6+9.Pc0UWAacZBOjjjjjjjTYmBRBOhR1wTlxTJDqtdLlvCIIIIIIohuYO6YC.Ke4KufsNMgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNNgGRRRRRRRpriS3gjjjjjjjJ6TYwd.HIIIsorK+xub.XFyXFoc4m0YcV.vMey2bO8PRRRprfI7PRRRRRRRkcJOR3QsuM.73yaA.P06xAB.G3nFTQaHII0cnt5pC.d+2+8yoSe5m9oAfy3LNC.3i+w+38bCVI0tdtm64.ZNYGqacqC.pt5pAfpppJ.XBSXB.vm8y9Y6oGhRRR8pYBOjjjjjjjTYmd2I7n1WF.N+Are.v0lntzt5a+4WI.bp6qI8PRcu9vO7CAZcBKdrG6w.fXwhA.UTQEs4xkqmt10t17Zb0+92e.XO1i8.vDdHUJoO8oO.vy9rOKPyueMxzm9zAfm4YdF.S3gjjT9xDdHIIIIIIoxN8RS3Qs.vu6bORfVmriHm9gdU.v3W6UB.CuGXjIoRCMzPC.vBW3BAfZqM72Mpu95A57IrHySW4JWYZqWIob0XFyXZyK+8du2Cn4Z6whW7h6wFSRRRkSLgGRRRRRRRprSuxDdT6q7a.fS7VVQ6tbIV2LAfa9A+5.vUNosq6cfIoNTTMnnPkvhrc5G7AeP238BIoBukrjk..ibjiD.t8a+1AfQLhQTjFQRRR8tYBOjjjjjjjTYmdYI7XM.vu4aegs6RsmieOAfEL2E..WyOd1.vEOooA.1yVj54cDGwQ..yctysHORJMDOdX9l2psZq.fsdq25tkSO8S+z6FuWHoBgG4QdD.3HOxPsI6we7GG.F23FWQaLIIIUNvDdHIIIIIIoxN8pR3QCK8g.fSaVqrMu9uvM87.vcNscA.ttiXX.v4N2yF.9yu9WF.N4Q02t0woZeuvK7B.v69tuK.ra61tAz7djdfCbfEmAlDP+5W+.JbIr3JuxPWh5vO7CG.tnK5h.fsbK2R.HVrXEjwchDI.fUu5UCzbsLYcqacEj0ujJ79W+q+EPyI63ge3GF.NnC5f.f0u90C.UWc0.PkU1q5isIIIUzYBOjjjjjjjTYmdU6pfk9DObad48apgpX9MLs8MsKe7etoD9k4dW.v88H+a.3jGUa226UOin8vc1pkCUUUU.E9ZYPzdtevCdv.vPG5PAbOlUpKJADQIhHeed+du26E.F6XGK.7k9Reo1c4idcRgx0e8WOPy6g127MeS.3EewWDnv0UZV0pVEPyI8HR+6e+Afi+3O9B2cJIUPb0W8Um14iR5Qll9zmN.b4W9k2cOjjjjJqXBOjjjjjjjTYmdI6Z6ZAf+9ecVs409SuhOC.jYkeXD6eT0MOjvi49BuZp0VHgG8ovNHUAR80WO.7Nuy6j1oEZQIGXK1hs.n6qKYDc5.Fv.5VtezaQTxcN1i8XAZNwAcziaCZPg9pTEUTQmZ6929a+M.Xu1q8B.F+3GO.7AevG.zbBId4W9kS67EpSipgFO3C9f.tGZkTyt4a9lS6TIIIUXYBOjjjjjjjTYmdGI7ngZ.fW31VcZWbU64OB.9ziIKc0ipR+ra7eG1iq0m57lviMskLYRfl6pEQm95u9q2sr8hRnvlu4aN.LrgE5hPE5jjDkHh3wKslOynZkRT2J4TO0SMsqOJYOQIiXEqXE.vhVzhR6xy2SipUFO9i+3.vkbIWB.zPCMTPteIIIIIoRSkVeiHIIIIIIIoBfdGI7XCgi09EkH88Hae1yc.n00tilTe5mst+1K..KITRP3iYDOJJ5SeBOveFmwY..iabgZsRWsVITas01sO16JZrwFAZtaZDcZgVTxNxrqlDc4+fevO..NgS3D5V19YyF23FAfe5O8mB.W20cc.M+72ZVyZ5QGOk5F3.C+kstZheh5RLRRRRRapwDdHIIIIIIoxN8NR3QpZww.IVZW7DFWnaqz2VcCdO.31unuU5WbigZBv5sHdTTEkzfce22c.3K+k+xEj065W+5AxdBPt3K9hAfcZm1Ifl6ZG4aRRh5tGQ0.jRMIRj..V4JWYZm1+92e.3Mey2rnNtJVa+tpnZvxVsUaEPtmvh4Lm4..64dtm.vm+y+4a2kOZ8Wc0UWPF228ce2Ej0ijjjjTuMlvCIIIIIIIU1IVM0TSmd2TGsmKG5PGJ.LkoLkbaiFKVGuPRRRRaB5Y1wmF.NfkcfE4QhjjTWWtlL9YO6YC.Ke4KG.l7jmbWdaaBOjjjjjjjTYmhRM7Huq8AM7J.vz5S3Xf+VRDJBGS8ldd.3ONs8E.p80+c.P+14SrMWMw6+4A.+iOHzkHFcE413nXkHkoMsoA.2xsbKs6xEUiFFzfFT29XpP3HNhi..l6bmaOx1qxJCuLOpFLD83ztrK6BPWuKXj4oQauLcLGyw..SbhSD.N+y+7yoweT2Koq1EadrG6w.fK3Btf7Z6WnDc+9cdm2A.1u8a+.55Od22915p3SK0YebuPYS8sujxeO6veFfR2ZEkjJeD88bx7u2LxQNR.XIKYIs4s6YdlvemZ+2+8u6avIU.XBOjjjjjjjTYmdGcokJGA.bXm7VB.2xcE5BKy8EdK.n1ZCswkybWNo1c0T0Ata.v1GcutDeGmbe2280tW+gdnGJPumjcTrzPCMj1oQILH5zBsMey2bfVmDgktzkB.qXEgtETzLlmuIZXzidz.vlsYaVdMth1S+EK8oOg1hzoe5mNfIMPRpPxzfH08y5PnTuOlvCIIIIIIIU1o2QBOHbL5OlI7ICm8ttK.3C+4eW.3.ukWF.VPGDYiu54MI.XfoNeo59BIJIBqd0qtcWt64dtGflqls4ZWxoXqppBIxY7ie7.vvG9vA53ZPwpV0p.fFarwdtAamvG9geXZmt3Eu3zt9268BIT54e9muKscpt5pAx8jg7Fuwazk1dRRkphR2Pc0UGPy0rorUSk5MxDbHU70QuOzDfHU5wDdHIIIIIIoxN8p10G6xG+nS8agDdPhE..KnCtcQcmko8oFd2y.q.6sdq2pcu9oO8oC.iabiCn4ZAQTxGhGuzddrh1iaSZRgD2jq0xgnYUOJ4K4aWJ4Nuy6Dn4ZdxVsUaU6t7aXCaHOum0yJZOYF0mpiNMa5e+6e29XRRpmPM0TC.bxm7ICzbWnJahRZ2HFwH5VGWERIIYWJUGlHDott7MwFY99NS7gTwWo82LVRRRRRRRpSnWUBOpregtRwdRX1R6nZ1QjY9fWF.ra8Rt2NyYNy17xOoSJzEZl6bmKP16K1kqhlk7nDZDc5Nuy6bNc6egW3E.fINwIBzwIKIJgG4aRRx1oOwS7D.MWCSxrVs3diSRp8MsoMM.3VtkaIutcibjiD.ps1ZAZtqQUJok+Ofj4vmuIe+eF9+Xj5XYlHitZM6vDeHU7YBOjjjjjjjTYmdGYd3s+K.vILxOMPtmriw+iBGSuWxgrMcOiqBrDIR.z58bUzwb79rO6C.7q+0+5dzw0lp5W+5G.rC6vNj1ocVGywbL.sNgIQ0dkntPSgJQIYdZTWiQpPZSgtigJ9tnK5h.x+jcjoktzkB.65ttqc4wTWUtl3hNZ4xmjaXJOjxtXwhkyuGIJoFYa4yVRNLwGR877SjJIIIUFyI5PpiE89DmDBoxKwpolZ5z+Wv4Lm4..CcnCE.lxTlRtsQ8OjHIII0ld5c7o.fCbYe7h7HQRRpqKWm38YO6YCzb2mbxSdxc4ss0vCIIIIIIIU1onbHszgyvSCgiw1qXr6A.78Vv5xo06.Oq6F.V5Mex.vf5piiT5tSjxF23FAf9129l1kGUyEF3.GXNMNhpAHk5InIa0xhx0sqa+h61eS062E5sems6XDoTt6XnRWW1kE5xZYq6kkuJlGZG4Ss334F4yBDpwSs0sqPVWO5LKuTuY46mStiV9155y1soyrt5tks5QRT2sJacExm4YdF.X+2+8u6avIU.XM7PRRRpWfrMwDYd4cz46LaCodyZ4DIzUa0rYq00VpuCGk1TUI1DdrF.3d9ZG.PtmriHmzQdf.cbxNJ0rsa61l142xsbKAZtKgbC2vMjSqme4u7WB.mzIcR.tmTkTWW4X2wP8dDkvwtpG9ge3Bx5oyHeSiQxjIIYptQWz00QSzQgXBObhNT4rtiIkn8l3ir0MV5nwgSdhTgWI1DdHIIIoHYaxKRlLYqlviVtrckTdHsopLmngVd9neukml4kAg2q4DVHU5njZBOd463b.fS4Vd2N0s+odg+c3WNgQUnFRcqdu268.fUu5Um1kGc9pppp7Z8cZm1ok1o9gajJ+E8975pqN.nhJp..prxt1ede9ye9.vUe0WcWZ8DYPCp2V16JO0c85ktKQiqQO5QC.u5q9p4zsKJojKbgKD.19se66FFccM4RpLx1k0V+j45IWmvC+rBZSQ4ZM1nslPinI5nk+j4xjYRM5nyKotOkleBGIIIIAz5I5HQhDMcZzOYaBRZqeOaKizlJxkI7nsl7iXwhQ73wa5mny2VS.hjJMTRLgGq4kuC.XOOs6JmV9uvO6QAfevwrV.3z1kiG.9q+rGB.d8qbR.PodNO1lsYa.Z9XKdkqbk.MW6Nh1inOxi7H.vLlwLZ202HFwH.fa8Vu0B9XURkFpolZ.fS9jCcipG6wdr1c4G+3GemZ67.OvCzotcYSzeuS8rx2Wur3EuXfl++IkJhR3wi9ng+++rl0r.f28cCIBcvCdv.vTm5TAJMRzQWo.il4DUzxI5HQhDzXiMRCMzPS+diM1XScps16vbIeFWRki5rI6H5z3wiSEUTAUTQEDOdbprxJa52iGOdqt8c1jdXBPjJbJIlvCIIIIEzxhVZlI4ngFZfFarQpu95SaRNhJThs7Kn0V0R.mvCsor7ocw1VSBRxjIaZRFiGOdSu+rxJqjjISl1De3jUHUZnHOgGgZXwM9E9F4zR+8+yuF.7cmTT1MpE.9bG9lC.yctWK.b82bXOZ9E2+P+idK15PWPYvCIrGFGXe6hC6BrINwI1tW+3F23.53Dd7POTHgK1EDjJ+LsoMMf7uaoL24NW.3nO5iNutckCcGiMk0Ye8xHGY3+aVasg++ZoV29JJ4Fmy4bNE4QR1kqSbPtj7hLS2QCMz.abiajFZnAd+2+8AfMtwMRrXwngFZnqO3kT6JZhMh9aia8Vu0MUqgprxJaUGZoqVCOLoGRcclvCIIIoRLII8I6H5vXo95quoI2HaELQI08I58cISlj5qudRlLIUTQEYsFd36MkJtJpS3w6832N.7sVvZa2k6RmUFI6ng2F.tmuWXO7b1yM8tbx0d1gig2qMKquSYF+V.3ptzOC.rsknS6STTUG0nxspQRzw3bwdOy0aqK.H0Uzc+58K5htHf7eO0moUspUkWKe4b2wHWza8uiUnd8xRW5RALwfER4SM8nkGRKs7PYo95qm+y+4+P73wY8qe8sZc0dewJOjUj5Xcz6ghlrwVlnpDIRvPFxPRq.lFcp0rCohuR6O4ljjjzlHZ5PXIiZ3QTMCHptAjYpNxVAJUR4mb48Ps78cQStQluGss5ZRNYFREGwpolZ5z+2w4Lm4..CcnCE.lxTlRtsQ8M7RRRRso4OrGG.F2adHs55t+6+9AfALfAziNljTqst0sN.3XO1isHORjJskqSH+rm8rAfku7kC.SdxStKusi2wKhjjjj5IEkxCIII04UTNjVR9gOE.bbawAC.yJYioc8w56YA.uzptY.XL8Mbbx8fW1XAfidlKnfNdp7i8s.fkufYB.acFWewJQJ4ZU1ekqbk.vfFzf51GSsTmsK.D4G+i+w.vEewWbAaL0dNli4X.Ztq3b9m+42ircc6Wb29EpsaO8q2WxRVBPycMitp7Mp6W0UcU.v7m+7AfYMqYUPFGkZ5pOuVrqYRQtrK6x.fYNyYVPVekJGZD8ldcX9TiNx7xa4kkLYRdtc4YIYxjr10tVZngFnt5piMrgMPrXwnlZpoa5dfjxW8u+8G.V1xVFISlj90u9Q0UWcScrknCAsrUfgyVQGNeZetcUYdnwEI5yeD84Qxzy7LOC.r+6+9WvGSRERlvCIIIohjLmri1pFdDU7RaYgMzCOXohqV99vV9dzVV+NR680VqcjJJJJI7XMK4EAZcxNhbJ2XXOvNl9FN+pd5a.nvmriHMrveD.7ye3vd56acjinaY6jutu669Z2q+POzCEnmOYGEqtFgTwPw506Q0FotpG9ge3Bx5obS4V2LYfCbfEj0iudo6Saknircd.RRqmviVNIG9kljJthJZoQ+dlS3QKu9151zxyaWZQp6icoEIIIodHYNwGYeOA25kyI4PpzT1dOZa0oVZqVUqSzgT2mRpI7HVEiG.NsiY2RcIqA.l0LmQ6eCium.vTOrvYm0bCIAoh87K..W44DN1xV98FNFmu14tt1b0Liq7t.fu5Q9eA.addN9KTh5s2qd0qtcWt64dtGflqls4ZWxoyJQhD.vUe0WcAY8cHGRqq97cEQ+Cj5pqN.nhJp..prxRpWlqBrtqm2K1udOplPL8oOc.XFynC96forka4VB.KbgKD.19se6yqsa4tnZAQg540d5D1kMQudezidz.vq9puZNc670KcexmImnUSBBghVZlSBRgdBOx15qke4qnOSxq+5uNPyuFSQB+umMTW3+8zupqnSsVZrtMD9kp6G.z4VKpXosduZKe+U9N4Fl3CoBGqgGRRRR8vZq8Dblo6n6dBOjTgQG8d0bI8GRp6QI0t9NYx2G.ppoQUn6i7lKdis4xG0MW9aKKzMWNvs4U.foUQHwG2Ngjc7Um12D.F3zNA.XjGwtC.m6b+fzVeab9OF.rhMD9CPad+JNyp5a8VuU6d8Q6w2wMtwAzb0StwFC0Dk3w6dlGqksrkUPWeG8QezcoaeTkp+jO4SF.drG6wZ2ke7ie7cosmJMzS87doxq2u7K+xAfy7LOSfl6REu669t.vfG7fAfoN0oB3dnui7.OvCTPWeay1rMEz0WWUzde+QezGEvWuzSni9RKsWs6nkWdlegnnDdjKaibcLFkDtnOuPj1pKMDUeZt9q+5ohJpfy7LOylRPWdow2F.9eNjOG.76lz2A.dfu2j.f9k+qw11FB+M6Y8GBi6IbJgT0sYEp0eqDdr7AujPm.6INpeN.bESb3cp01a8n+..3Teli..djoOA.S5QuMYdHpEcHrzQI0HWqkGl7Co7WI0DdHIIIUNpMKLoYNIGQeYIS3gTuJY6PZIyIxnk5nBZpjJLJNS3Q8s8EGK1Vm9ETaHwGO+KWaat723y7S.fCrocv1H.fi7L1J.3V942F.7Du84..SZ61N.3adu+A.3VG7DAfERo0GfXlybls4keRmzIA.yctyEH68E6tKkJcMhoMsP2zIe6tBQOt0USVhJN5oeduT406Qh1S7my4bNEj02lp1Toal3qW58oUo6fzmjiNyDdDUKhps119yQ0u9ExWQK+RVO4S9jTas0xMbCgNj2UdkWI.rC6vN..qe8quMucYyG9udLhEKF2UxPs.g+bndD8RS6HIAI4fFRg4ihtwk+2HVL3Geag6yG8oTPVsY0G9O+CDKVL99O8wA.y9G24R1QjgezgzHOkq3y..+1S9.HYhjbRitXUQ4T9n8J.wNIFREWlvCIIIodPsWxMZuZ6Qg5PbomTw5K6ks8pdgb82cKVb+hxk5xdWVpsWt1hSHhT2qhxDdLvQFpgFSMV3HSbVIS+XIs9FZ+aeEC76C.SYLYtm55K.7wNrvwlLo1SvOzyENl+mzwlZ122lw..m5gGt8Wz79vTq3OB.zmJKN+gmn8DSl6A6QLhQ..6y9rO.vu9W+q6QGWQJ1cMhK5htHf7eO7moUspU0kt8Yyl5cIltq6+Eqm2K1udWcOralntaEpujcWMcGP1S1QTs9pkeQqG5gdH.3ZtlqA.tga3Fn1ZqsojczRabigZqVe6aeamsd3+E7D+hPssX7W5+O.XBK96A.S+AVTX6dZiI808aFRk2Ec6qE.9weuPGnqeMc8OTpqOr9uhSa..vW+T9Y.PhTo18HmQn5c7mSc6+fW39Id7XbUmy+M.L+jgOy0tLoPJn9dmWntPsyaQGU0LB0+s+vo++..mv0FRMbyYTN7YZ+WORny+88+tg5L2qmZbEeTGYXbO8KfDIRxDGcTmdZH.vIe0GO.7YNqv58SM2uLPwqyApbW2QJOrlcH00YWZQRRRpGRqZAscP84nXllixoujU7NLsDc96qo1eU4s1ZLkLQumz6n1VtTbhykhYrjJLhUSM0zoeW1blyb.Z9XceJSYJ41FsL5efJIIIUH8W1gGkjISxDpYhs55h5.OEJO9i+3DKVrlRwVTM6X+2+8uqshW6eG.lvTCoz66cegw8A8d2KIA9Tm6R.fac1WB.LxpCe1vZ+2+ujjjbrmeHoE2+bBo1MJgGs95OJ.XY+kaG.9Z+n0DtebSmAPL1cdB.Xpmw0B.S9BB0+sO2dGRw2e4ZBiu63eFJ5G+lGHb5GIK2sR9Au..LwOyMA.+jeeH8g6yVj5t8q7aBauu1sB.m4OJjviwOrv384+0mO.bs+iSE.9C2ZnFfzT2j4+7LgG297gjwb8yNr9+nEr1Yi5NLgILgh8PPpjVtNwdyd1yF.V9xWN.L4IO4t71dSir1KIII0KRxdnBpdasSnJO1iywxxum5R5Q24awHVIVAxWRZSEEkI7H5ej95+tPWWXmOwzO17iOfKE.dy0F1KC76ByF91ehWapEXOAfY8luD.braWFafZCy99Wr+GH.b284q..KZUgYYe25aX1+u9wOL.3aLuvwiYk6wE..q3kCy9ezQUY28+TLaGKre3GFpsHQcUfNZbDUCPJ2RPST2nYjibjEj0WW8Cx0Y6VHQ9w+3eL.bwW7E2kFG4qi4XNF.XhSLrGCO+y+76Tqmdp6+kZOuuolq5ptJ.X9ye9.vrl0rJlCmBFue06Rug6WsUQFMyy2dGFKISlro++czu+b69yB.u669tzPCMPs0VKqacqipppp7pdDs90u9rdcKbgKjALfAvO7G9CAfy9rOa.3vNrCqokIpFfjHiiYinOmQT2ZosrzmLTKNhk5yfc.Cq+.vV7QFO.bvMFRRwi8u+ljHQR1iCLUlJ179SrXwABi892+vsqosTqt9P0yX22iQQrXwI9HBsBvCZOB0djE+69a.Pk662F.t3S7fAfpSs5F0O8FIV7X7XGVXb9b0bJPR3Suq8uMues925cCyeRrPU0XHaYX45epAXia63.fq6lB+u18cu1wvkugPMIYOO3T0YtEEdLbfYd+aaGA.LNVb3wwUBjDFaVFOpzvq7JuB0We8LfAL.5ae6KUUUUDOd7z9I58MQ+dl+DIyyGcYs246JhVWY92th97WYqqP9LOSHMRc4zfI0MyZ3gjjjT2fNpXi1dGK+QI7n65X8Opvk1SIsuPWFa5LqkEIS19EEirc8czsKqqutg5lQxDgezldZq222VS5Y9b6kTmWQ8PZYTmvkA.WZE+R.XlMFR5Ph0MS.3bt4S..9iSKb969rtG.3TtkE..etyIrmhW3uIb7eNpn.Rz2vLRNtiMjLh6ZVg8D8SUSpDdzu4AzbxNh7M9NeAflS1QOksca21zNeT2.HZOmbC2vMjSqme4uL733IciggFf...H.jDQAQURmDPycYhd6hpQLcUO7C+vcoaeodWho6VO88+Rkm2kjZKczWHIe+BKsUKmsyzkVVwJVA.bi23MRCMz.ehOwmfFarwlR2WzeC9xtrKiXwhwdsW6EwiGmuvW3Kjy2Gpt5payKO38Af4cGORXcjJEqGyG+WzlK8S+a+q.vWb++z.c98DWT+9KYM0m14qH0DGsyGztAzbxNZR7p.fg1zDxzHzdG9IUkZuzWcHEwaaFgbYfCIj3jUM6PZgG24Lu1b0T49bgYYCDZUgqqoG66fwiJIjshQZK6RK4a2Zo8Vd6dKR4NS3gjjjTIf1KgGtWek5cniR3gj5YUjKZoCG.tzmIz6zm4XO6zt1Yc1iE.thgWC.7cu4voa6nNM.XBequE.ry8Kb5TOuPEy9F9ogZLv9eDGZpUT3X98OdaWG.rrkc4osch02yD.N2O8d2UuCkWdu268.fUu5Um1kGc9pppp7Z8cZm1ok1okK+w0njpL8oOc.ZpRx2QhRJyBW3BAfse629N01O5XW9pu5qtSc6yzgbHGRAY8jonmuqqt5.fJpHTQ3qrxt1ayKV2+K1OuKIULjLYxVUvRym+e9RW5RAf+5eMjbhG6wdL.3.NfCf5pqNtlq4Z.fFZHjjfK7BuPppppngFZnoCyk5qu91b6FUqwZuCGlM9lOG.bSudHYG+vew8B.61VDstBQhXiu0eA.N4yMTmVd12NTmoNv5SFpQFIC+urnjZzj5qs0GSLsPrLpqaMlpfktjW6sRc9QC.Ujwsq4DUj40j41OL9RT2SC.uyF9x.vNmJoGu1e5J.fYbWg11x0cO2OISljwL7AC.IeiviGG0Lpuc2LCno8beGLdTIgr0doaYBOjTwgI7PRRRpGTtlViVtbEhDdzV29tiuHVlqx1pDYjnUikxyuPXqdL2B6QYuNy6ukT2mRh1R6.22PhLdsYE1qD67TmYZW+26nC6g1+0OJjTiq4BtS.H42LjXiWYQgd89+5sF..rUotcUsq6dpeKb6l0LO2VbNf3eL.3g+mgDlris2gjZ2fsYa1lv1OUMFXkqbk.MW6NFzfBUSjG4QBGGrczd3dDiXD.vsdq2ZAerVJ3xu7KG.NyyLjHmnp0+69tuK.L3AG16IScpgJfdgZO6urksrBx5IxQezGcAY8TSMgDOcxm7ICz7dwKaF+3GemZ6Tru+WrddWRpTQ97khNfC3..fy4bNG.ZJQGW3EFpYDuwa7F.v4cdmGIRjfgNzg1zW7JJ0GQIDLJoc4yjh7x+4qGn4ZTwm3iF5RIspetrcGE.7UhGpSY+2OTn9rc+SL7Y4RTaH4GO7+3ngDIXR6Xniwb6mZX4iu2ma5qunjWrrk..K48CIDYaG89Pr3wo1q9+B.9ymvXHYhD7IGcXD8z28+O.3Eq7HAfu8va+tgR+211uyg0Xco9kJBcIlgmJYGUu1WC.toueHMxIVV3+YspTQXoeQA4HQH4GuCgsyGcGr6rzaP1pgGlrCohOS3gjjjTQf6g2bTpCgl74Cs1xunYxLaqt8fcnlz5NM8XaUUJy22K0ypjHgGQF0wdk.vJ+mgZuw2b2mB.bWIC6wg65aM0TmFV9y5RCIy33O5POOeW20PMu3I+cgtwxseEWSatchUQXOceeuzuC.Nhg221b45oDU4zylwMtv8uNJgGOzC8P.vttq6ZgYfUhJZO3Gs2q5tUp0sPl1zBIhJe6VJyctyEH+SXQox8+d5m2kj5I0x8Pbl0viNii63NN.3NuyPpXiR1wv1ggA.mvID5DdQo4nKqtk..y9NBoU8j+Ig50TqR1QSBcyji56LI.31m4rAfkeJWL.b4etvmk4xOivm86Gm5VsO6Sa+QW6yVF53c6c8gtixWYpgDgbOO52A.twucnto8USs99gQ2v36S372wEQhjI63z9NfTi6juD.7TuwpowDIYmGSHUt63A7YIVr3r2W8E..S8fSu6zb7mUnS5k7VeF.nlUGh3w1s0gmG9OK3u.whyqW49B.aQOb5iU2CqkGREOlvCIIIod.YaO6ls81au8N8Ph1p3cThp00TjNujck5zQ6TPVUuG456oitrdau2Vp2jRpDdDYP6VX19uyDg8Rv4+f2C.by+3vws4sL2vw44sjplbbKyLy0P66rtyPMt3yr6CpKOV6NE0cLF0nFUNs7idzgJOds0F1qFQG6spqoToagbQWzEAj+I6HSqZUqJuV9Rk6+RRaJoko7ny7kgh5zaQI83O8m9S.vkOiKmjISV3R1QjpGA.Lim7Ixqa1v+TWF.7jepzu7Qbd+R.X7SaC.PiDh5P+5WVF2C9f.fa3u83.PcopMFUGc+bpg+G57O5uF.rgnZmQp5lVN+nQEgZRxY98CC3S5FBcCmS5+Ijbj9siQii4E1NqMrgpH01o5TanK4zxbEGteNuq69.fi46GRly1YSZoWE6RKRkdbZjkjjjJwUn1CvtmjkJ7xmjaIodVwpolZ5zuabNyYN.MeL9OkoLkbai5rbJIIIk2dzG8QyqkOJUeUWcHgDCX.CnfOl1jTCuM.7ilzWF.1kaMzAw9ziry0UUV6+9dAfi6aDd95tdvyF.11tzfT8TlvDlPwdHHURKWm.vYO6T0yokub.XxSdxc4ssI7PRRRRRRRkcJJ0viNeDuBcqk0rlvw4XUoNdH6aks+ci07BWG.r4iMTyO52TCUL6U7+dp.vl0AaUSjhJlVxRVB.LxQNxBx5yHVpbwUcUWE.L+4Oe.XVyZVEygSAi2u5coT99UGUTBy7zneuk+jHQhVc9V9SiM1HMzPCrgMrAV25VGUUUUrl0rl7Zb1+924Rbf5H6L.7s+MWO.7reP3yn1Ye7dMwB0gsa92r2.vN4ya8prvEtPpu95Y.CX.zu90OprxJohJpf3wim1OwhEqoex77o0BiS86YdZl76nH0wLgGRRRRRRRprSIYWZIS0952O.bl6xmA.tqjMj10WwdFpL1+l6Jz8UNgwrMoc8UsEaWZmOwGVW2x3Tp6PTMxoq5ge3GtfrdjjTOiK6m7SHQhD7MNtif0s90yVOr8nMWtFaLzU2RlLzQPprxpxqsS80G9bQUUU040sKpUt1XCo+4xpLUmQIV73cokuTQTHcZng5S6xiAT0P+XTYUUwg1F2t5qu9LtjvJJpC5DVCPc0WOC5it+DCXqx5sEpppJS61kMMzX30AISD0dba6sqjzlBJM+OKRRRRRR8xDcHpIoRCk1I7n1WA.N2c8D.ZcxNhz3BBGSue1wFN+K8g+Q.XL8Mb99t8giKxuPrvc2e+l2sLZk5Vzm9zG.X5Se5.vLlwLxoa2VtkaIP33JEfse629tgQmjTWWs0VK.rzktT.XwKdw.vS8TOE.zPCs8++ubRa8kjNiS8qSCMz.2wsckTWc0y27alkDdjHrG8qtpb6i0EsUZHUJBh0I2i+QI0n4jCDDkNgphGsdi0oV9REQI6HyDVDkrlnqOJYM0Ec+IijqDkvklt+lJQMUWUamHm5qO508QI0niR1QpkKUxNhdbN546l2t4WBfjj5MyDdHIIIIIIoxNkzI738dxeK.bKIZ8wwXaIY8gjd77+6PELeLiYfcOCLohfK+xub.3LOyyDn4tUv69tuK.L3AOX.XpSMTSaLQGRpmRiopY.0TSM.MmPinSei23MZyKO5zku7kCj8NexQcTGU2wvtj2H159PCMTA0x.ndpijq6cfj8GR0YFhRLPrl1G94VxHhpYGUDO7w.SjH+RPSiIBau3wa6sW7TIaHQpjFjL09WKWW93wqHuFOQ0rhJipAHod7I5kSM1X5IvHRtl3gJpHZ7j93OdEgsWC0ma0jj3oFWMlyIXIp1aja0VkDYIoOQasVzufx3ZjjJeYBOjjjjjjjTYmR5Dd7lK746T2tOLiYZmUF1CRKHU0KWp2rnjabNmy4TjGIRpby68duGP9mPiksrkAz1cVB04EK0OG5Qc7rg0udtieyuhod7mdS6w+nZaR0UleebtpSc6i1O+M0LOx2wWrrkPfVmofNyxmqhmJIEMzX3winjbDUaSxL3PsNoC415OSMkPjJR+w+rs7QIQoixUQl0.j7UxTIvIVVRTSTRpx9yGRRkOLgGRRRRRRRprSIcBO1hOxPxqkOVUgZWv31kAk1k+ByNTKPVPpYx+3N58G.1rt5.TRRpDRTsz3ke4WFH2SnQzoqacqqmavpb19saCi0t10xK7WG.PLRzXBVQh9PxjgD.DuwN29uJJeCMsdZH2VOMmXhTIEHQr185yLAGczxm40mqRjH7wZitezXhJRaqGc4oB.AwHjDjX4YS.JpViPpt+W7nwaVRJSTsVgnGmiR.RV1tIhVtDwa20alRFKUWYogL6pKQO.20d8hZsssRS0lToN+KdRRRRRRRprSIcBOF9geLo9saocWtnjc7GWvcB.66.qE.d564RAfO9YeWgEL9dB.eiO8dVfGoRRkml27lG.r268dC.ibjircOcm1ocB.FwHFA.z+92+dpgp.9K+k+B.rm6Yo0+mKpKXri63NBzwuNJySi5BUappxT+ryi8fHV7JnwDMRxjIHVrRy8aU91CPJb8Ljz6NKQ0nhXYzUahVfL6hJcjnjcj45MaZLZ4SMtxVs8HRli67UzsJ59UyOtl59ehNWMRQRp2rRy+SojjjjjjjTWPIcBOpb6NV.34u8yB.F6o01I8H9Gcf.vK8qtH.36NyaEn4Z1Qjy6duW.3H1lvc6jYV1tkjTZh5BAuzK8RocZtZHCITKlx08jeTBQF1vFF.TYd18IT2in837PG5PAx+DZD87YGsGtU1EKVLF6duOTQ8qgFR08QJZMYiTa2l5FHYNPRlJYCYjzfbc46zCqTckjjIRe80TkrnS949x2jcDkjhlpcHYoaojonwWtt7sZ61TsII8GmacWowtyhj1zgexCIIIIIIIU1oWwtNaeO0aF.dsc7S..W34GR7wrVPXOO13BB0niu2BR+1U03CK2u6m8C.ficLaS29XURRMaEqXEoc5S8TOUNc6pnhP2DHJY.4aBQhRVRm8Xgub0fFTnKlkuIzHplrz2912drwpZs+9K8Rb.idDMc9nDAzc+57nDNDOiDSPpZHRScsjnKNiwS9t7QhpAFUjiI+HydRRqWq4VBMhjYdPhd7NaIEo4DLk90m482Vu74iMRRfMVekjHQB5aUUzz5IJXHQILIywYK2dMV+5C+RUg5rTEchQhjTuAlvCIIIIIIIU1oWQBOhLpi3TAf+3KENs10rJ.XM0tA.H0gZNUUUnldrMay.6QGeRRkKN3C9fAfIO4ICzbs7XwKdw.vRVxR.fO3C9ftkseiM1XZamnSm6bmaNc66W+5GPyISHJoBqd0qF.1xsbKKPizRCQOe8E+heQ.3S9I+j.sN4KawVrEEgQm5pRl5m+wyMe1ucYXTQ73DKQrtbBOxrqdjMYKIBQa1z5VL0+p.vOcBgWK1+q39.focXinMW9E+mC0esK4OGRw6cdceF.nuYtdyCYa7lu0Fib8wmbc6CPsKN73wW36G9ab20seR.g6us+3ai.v7tziD.d5I7q.fu0DGQds8iTyi78.fK4YOZ.3t+dS.vjdHoxOlvCIIIIIIIU1oWUBOxTeG3fR6TIIUXbPGzAk1oYyJW4JAf23MdCflS.RGc5RW5RAfMtwMVHG1MYCaHj7u+4+7el1oQNpi5n5V1tEK45yWp2oXQ+zuP8VHQhDgzcTBWiZpMUcr3w9tea.3.+eua.Xu25LxPP8qE.R9gsdcTBe2qSKY8g54Qx2N+tcq8eF5zfW2y9YAfaalinKMN1wi9hAfiblgNh38eROL.b76xl2kVuRRkZLgGRRRRRRRprSu5DdHIohqsZq1pzNc+1u8KmtcQ0df29sC6ly7MgH0TSM.Yu6GHUN57+JmFqYMqA.h2Pui8Y0v2ov6s+gyHT6JtiqKTyJFPGb6h03pIFvSee2H.Lya32m10eTm60A.m1IDR0Teq+0Afa6BuC.XfiMTGe90+7+..bremeJ.j3A9+.fgLwgC.OxUE5DfKM99B.e0e52D.FzKGVOW4OOT2fpXeBi6q7JNO.XWSUNbdiG41AfqaFoVOoR1R7QEpMFm6kc9.vgtqg+FYrphddqwN3QfHg5Nz+2ztA.3S9SlcX7k5Zq+sdH.3m7+7uAf8b2dW.3m+yefTi6v33hN+KA.93iLp91E5jUS8+93Afo809eAfI7+8kA.y4gjJWz63+VJIIIIIIIkGLgGRRpGWTWkX629sOsSOjC4Pxoaec0UG.rrksLfbOgHKZQKpKO1kTGa8ULI.3blYnqq76+bmI.baORnar7MaitKRKsv69b.fYdagDIbA2xuC.FYCuL.bymy4B.WI+B.36O0pAf28EeP.3O8xgs+oewgZUwGYjgLkL2Lt9+qa6t.fZ+a+b.3pN2PBGF9IF5hIW8sEpwEy5LtP.3Fe3OE.bE6wyB.W3LtI.3Kc0gZTx3FQU.vy8q9J.v0MycG.FaptwRd2ET9fWC.tSFQX6N5sIsqtw5C0qnmY92A.rfsJTyT9I2ymC.doaXZg6G+z8NrdZQWvAfOxnOL.HQs+L.3c1PpDdzu7cfJIUZxDdHIIIIIIoxNlvCII0qS0UG1at67NuyocpTuUwhEiXwh0T8so2tjIB0RhJFbHYAS6+9jAfS+acB.vgt+OG.L3p1rLtkuO.7B+7PM43Dt14..GxGMJYCi..N2ez+Hrdm9SA.e3TOzzVKmz0ER1wjGSppQQ8uJ.L2Lt98cWCWei86fCWwuHztX9Fe0PxN1oPfM339liE.tt5CmO1V9wAfu6OKrc2q8MLtZbCgtNynOfiKrfggY9mriT1vJdsTavPQCoeUmkELdX7Miud3w2QkJgF63YEpII28YWWae617AC.G.gGu+2u45.fccW6nprhjTuClvCIIIIIIIU1wDdHIIIotEMlJXAa0AEpgGSaeBcakq7+9WC.e6OQFEKh5Cckj+SptcxfqpOs45cKF1X.fDa7NAf2Y8gjVr9TAjo+8osyTQ1t95aHiEL57oR3Ql8TkMavaM.r14LS.3DN240lauJ2mKsMu7bUTWcIdeBcilssU0VivCvwqNzgr1lLt9NtWvDtiF83Bwx0tGijTuClvCIIIIIIIU1wDdHIIIotYgZ0wjl9UA.O3wEpsDWw7CQKnpws2s4sp+Y4Spt92ao.P79dz.v11+LVfNJoBcwjL7F+ouC.bs2Sn1hL8e0eB.1scbH.PxW+WA.ewYlkZmQNJY8I.fDa7IAZtKpLpLRxQrcH73ams4pz+XQavNa0FQRpzjI7PRRRRRRRkcLgGRRRRpmwV+I.fy8xlD.bAW4eF.RttTWeUi..NzSbf.vU9iBIkXO+YeE.X6aXw.v8ecgZ2QUi6G..8MyZvQl5nqOCcT9OZrtPjHhU4NB.aWpjcT0Z+W.v8bk2H.j3MCcMkUkZENn7aXP+FRTGnZts6xk7syyUbjFBOvrB1I.XWFlcmEIUdwDdHIIIIIIoxNlvCIIII0iZjG84A.ek+7eA.tqAjpcnPnFRL1y3W..mxaeJ.vEM46HsaeUi6a..WykNA.n53gZ5wPiEi1T08scu9JpLr8iEev.st1gjYksXGNvSF.18e1E..S6vu4zt9i5LBi6j21SC.qX0gHdDkviXaWaOLakMKTiPNzj+c.3EdsUB.iZLaUZKVGs9x10upW9+C.VVUG..LvpywwkjTuDlvCIIIIIIIU1IVM0TSxNdwZayYNyA.F5PGJ.LkoLkBynpGRxj41c8XYauEHIIoMIksOCQzkm4oQ+dK+IQhDs57s7mFZnAZngFn1Zqk0st0QUUUEqYMqA.dmFpp0a7xX0sgM..IRsu55a+5Swb3zBaD.pcsgDbDueg1ES0E3lcx67HSG.9F2+XAf695N1v1oSuFWO.7fm5QB.u5ocu.v4dX6PmdMtonssx5AfANvAR80WOCX.Cf9129RkUVIUVYkDOd7z9IVrXM8SlmukeeineOySyjeGEUtY1yd1.vxW9xAfIO4I2kWmlvCIIIIIIIU1wZ3gjjjjJoUc+5WwdHjEgjlz2Mq6cqrsi+r.fC56e7.vCu3IB.GyH6emZ8s1+0uC.tk27SC.2jI6PRkoLgGRRRRRRRpriI7PRRRRpTVEaO.7Uu6a..dgU+AothNWBO1vFGI.7CtqS..FbWazIIUxxDdHIIIIIIoxNlvCIIIIodA56v1O.3fFVWa8rMi4PBm1UGPRRk3LgGRRRRRRRpriS3gjjjjjjjJ63DdHIIIIIIoxNVCOjjjj5kYaqr9h8PPRRpjmI7PRRRRRRRkcbBOjjjjjjjTYGmvCIIIIIIIU1wZ3gjjjjjTYrU7ZOO.72dxWD.d82a0.PUCXKAfcZLGL.LgCd2.f90SO.yTiqA.Vw+Ib1gLjA1srYV8hCOt77uQ3wiJqLae83FBmrY6D.LtwNR.nhTW6auvm..dhW30AfMT4lC.6wm3vAfwNxsLGGPuB.7au+WC.N3O+jAfsq5LVr2L7737epE..q3CCW9VOh8..NjCergyWA4k0jZ89nOdX89gMDdkvv2y8C.F2dm986dCLgGRRRRRRRpriI7PRRRRRpLzq8f2D.b2O8JRcICA.1qwNZ.X8u0KC.O+ibugSe4CG.tjy9v.JFI8nN.3u9+bM.v7F5mC.l9ItacKasU8pgjYL+mdU41Mn5PGx5.Rkvi0+h2C.bqy5eC.a1NrK.v17duD.LmeU3z09UtD.3vFV1dDMjnkG7WEddXQqZy.fwzXpDdDsTuxb.fe1897oFO6..rW6b3ruz7CW+K8LuI.btW5wA.cT9R1vheT.3Z9UyO0kDdcxtuKqG.l2r9U.vysjOC.bgG2GqCVikNLgGRRRRRRRpriI7PRRRRRpLRcucH4BQI6n5QNQ.379RgZ0Qy4LHjffWYNgjfbuO+7.f+5hO..XRir3TMOZHDjB1r90mt0syHmz2D.l9jZ6q+0dvqC.t6TI.Yhe4i..5GuO.LmTI6fcH0iumd3w2JH739uclgGWm2bWD.LtuzXSc8o6M+q2G.zbPSpBnkeY8FAf+0yjJYGrW.sNAGSHUBPtlTI.4oV7mDn8ddLjnlm4ghR1QHgJm4+0IC.aWpA5Jd9PRVto4La.34OjOJ.L17sHgTDXBOjjjjjjjTYGS3gjjjjTuY0sgvIUD1KtUm26z0vdOdCaHbZ+5W0s2BqdApYAQIAXP.vwehYlrizsaGUHI.69Jd7vxsw0m5ZB2hM7lg028bWgDD7V0EcKCuVYrS9KC.SdrgpMQcu8SC.2zu7uC.Ccm6O.rnEs3z1t6vdERXxIebgjOrpm32..yesoVfmOT6Hl4JNb.37N8PxSVzeLj3f47RuUZqupGztGt+9k9zg6WaYmLABqNb+82lJxEC5.+R.vAG0tTpKb4KK0huWG7dBzxjaDpAFG7AENcQy6UAf+CisEWKz3JBON8KlW39wfFRn1crpnRtRSBu2rhsJj.i8ZzgGGxr1bLvseD.P0DF+0twFZ+6mQu2ecgysYiMrd2tLdXaH699FVuyIjnk2bUgWeL1st6o64THYBOjjjjjjjTYGS3gjjjjJLp60.foe3g816+WxDs4hEeTiC.9VW34A.G69r88.CtVH037hSMNOz65gAforS8umcbjxq86NW.35SdN.v0dhiN2tg09OAfyY7mN.7kmSXuyefcvwUeq2daK.bWSbJ.Pr+e2O.bF6aG0aGTomPzKd6ZRULH1rCD.FdGUJNpNz0QNwSejocwM99gjBbs+h4jZwBu28q7ICcoiOXggt6wueN2J.zv.Bu15S1mv1eU0EhpvpVTX8N0uzWIrhei4B.yJUWE4utWgjYbD6bHoDC5QBIAYco1dm33CcokU+DQI6X0.vj9RmM.ry848.f+zs96Af68FCIO3RtzPw4H2qDIgG+d5e+bRctPhJ9JSJ8GWX8qsEKMrMCpsq0HejcbDo9s+A.rpPXrXH8KTCP9C2zCFtfQFR5xWZhg6W+ra8EyXMERVxdO4Ps0Xua0VJjTiW7AenTiqPRQ14suiRfQpDfj5NxZ2Pss8hs9OnkKVupIQvDdHIIIohhXw8ihVJJV7XE6gfjTAQuoImQRRRR8B7dD1an+vewUB.61.BWdCrQ.3sdwPBBtvyNbb1WyU+6IQhj70FWOaROVWxjgeIVwsSCTUpxBvGrlb8VD1atO4O6BAfMbA2NPGmriru81B.3K8a9NDKFb3mz0..G07lA.rik9MhA0jv6wVypSc15B6w9NpRNjMK6YCc6knDCbzexT0Nh9DdM3G4fNb.XudwPsc3kl2KA.i+Sl95Yxe8PMvXu25TWvHOF.XAy+5AfZaLLBqdHgjdrGa1r.fWbq1I.XmGVnpW7luQ8Q2w.fkurkC.C6iMJ.33+5gDer9J1bf7IYGAM99gZNxClpzfrKSNbGYHYrb00ThGB0HksaPsccuowLNezW99UlycC.KJ0eq7rS08V1x29QSa4qnCKmNgGGdw+XnavLqEs1Ti6viCerNrDaDVfQuOg6GO8SGRHyu5ACuN5fFQ34k+589fs48idCbZ0kjjjT2lDIyskKdQLUAwhYhFhjLGe9RRp2fdSSNijjjj5MHVXuqtiiZ3.v1Uc5eK5cbGCIS31Yk.vW4a+KAfoN2KMr7MFNt++S290B.+f6Xdoc6G6jB0dhK4R9hg0Wpci6Rl+ul3wiykcg+L.30IYpk+L.fy6BOU.XmSsWSGPpI5329KCam+7C9GAf+dpa2o7sC0kfu5TC0qfnfN7eVzi..+nyX5.v7SUqR1kTiqu+EFFWiXyRcCZLb75+P+7eB.b4ot+T0g7YAfOcrE..aw9QNIwJeV.3Bm0VA.+hGMiZ9Qmb60mgcn.vELleD.7ql6RAf+qIN7bafoR.g8X+NrigWj+zKqu.4xW5KjEg2bgg5BCCcTot7nHFDpIGy5ltl1e0TUnHUrwltfvaB1hVUdbBWvfScN1x2O...B.IQTPTs5atxQDFG0mw4iLrC6yC.S7cCcykGYdgjf7RyKZIBqvcehmH.7oO3cFnkcOk12xd1mN0usC.vgzTjTRW0CbqSs0R0sV9OgjVLxsq8ijQ8uSHwL22ympFqLjPBVdqWLTqT96KJp1cDVeO27BKO689GV+acp0ep+F4bt0PxNd9Tc0k8JUxNNtwlYlTZeibReM.3y0u6E.9emWnFlb2Oc34ucergj2vyuHfNehgJFLgGRRRRprP7dvZBR7X9wnkjJ0YBOjjjjT2h5ar8O9HF497wAfjM9mAfOntPRIVx0cZ.vO7OcH.vMbe2OjDFRsg5DvO8TuX.3Z16OA.bsSHrWkiR1wm4FC682Cenqi3.21wel.vY02OJ.7WN+ACDsOlg+8CG5vC+je4cA.e0kE5fDm02Mb61yOdn6mbvwdR.XJm92E.NgK8+G.7GOvsBHNy8pCcKkuvYGte7.2UnKv7F2aHQKy3N2lv3+d9CjHILv23ARscB6e6COGS3waL+YC.UrSg5fvHxnPE7hc5sWXE8w+zS..t16Hb+87RkviMKyEWkr1psK7ZbVTHwBO4hOL.XBiLKU0h2+4.fewuOTqF1rCLTyMlZCqK0BDp0Dm4zCW91kwMeEu1BAfk2PH0Q8mEjSiyrlTflZGHomMiMrh+C.r06WHoGS+DCIZ48e6PWcYgOQ303y6QBI+XL6a38B6VGVLOBE8jW5umJ4E6dHsSCKaQCoOgBSTpxSD07tqO7KYjviZ9GgtyBUGRg0f6S3qeOjMKTyLpqtWMLdezWM04WaZ29EM+GC.1pcZeAfQNv2D.tmq9W..+65BI4Xxmcn62L1gzgE8i1z6+Zgjkrts+SA.W5zynCM89gWGMiTI7nxJ58LMBN0zRRRRpzVp4MIupuDIR6jbe6zoqgE49VJWqqIEJ8zaOIoRE8dlZFIIIIUVowL18tUk5zgOke..baewcA.9naWHKFa3CBGW8icbg5RvSUW336O1FCIVHplcTyxB6Ez0N78F.l1rCcdfS4+O6ceGmTUduGG+yYlcGXoHZPCQTQoHHpnfkqQCwfhEzHnwRrDKXPQQicicEKXLViZjnwZrahciIhDEhQioXL1xMFMHZPwJdifvtrkYN2+34L.yv1YWX2gOue8ZeMbZOmmydi6c1m8676WYqQxcXt.PxeSVlzMMYxkKlcXHIszfMN72DbjWP3uh5GtfpHNWLu6a8zg6W4g5CvAryaFvR+q7tGG64RpH35NjyE.d0OYO.f2ZpyF.lvTuNhyEyNLfj+5oCHTqONqG49.fGqg9FUwR9q.uw6wV.rrchhPs63kVAueqy.Ced8im6BZtyH0ASe+F6C.rk+gPWP4EtqPcpopw7c.fscPgz+T4GERlwu9g+8IWYHw.66NGRzwW6SB+2P7xu..7DOVnVSb.iN7+Fo54FRAzs7KCGms7.AfyXKasy7v+q40OoP67Wd6PWeYViXsAfzuTH4F+xWNDAjc4vmX34Y8By6d2yBS3PYM2h2QUgji7NIIKYKG1.ajSFHS+.fsK7ijXZOd3mw7O1fCIL+WveE.dvWN7eqtViL7yJ5ceS5JKm11UuCaMueHgMW1sGRFx26rCITYPYB+rt+xckOYGgye82tPs8nW+22Nb+CgUi5R9Yqe0AFR0Ve6Y35+GSK78uO3qERvxXFd36a+2+0zAfm7kC+zrzGcHkcCoKghCxidyIcokdDl2eiFJoPc.YBOjjjjTmFo5.81W6HMWjjzxyDdHIIIoUMpsVXY5Hr0lr.B8aMCu9KmxdA.e+Wolk6RAXTg+3lD26vmu867RBciki37Oc.3dyehoFA.bN2zE..iMoolrnjOiLcuKoJ7ixRxedz7GOCDlmwgjlDW6CB.Gvt9fM5i2m+Ygjl7J4Bi21WVZxUvmujveM5MaLCC.drurQGtk3S+fYE9GqWQuU9E+osI2urI+JB4pI741+8qJTKRFZmm+nthPWDYeN4PscnqO3iB.+koE5BGubQmcl9DRrwAd.6M.z+7AkXCB0ykiduB0Im67ICcuia30dxBt9dz+QA.ieraB.j9CmaxQJmFS9+WvEWKOV2MNjLA9mgDdbu2THsQG6Yev.vV+AgN6zybWgDr7LK8IIb78N7bOnlaIsHcgy1xJqo90jCWv1cHg6ybtkPxKd3a3JJ3rxj78kCez8uYMMVZp2RlI4aRM0LG.3e7tEd9eveIe2To9Gus7.OU.Xe1jvyyG7JgZvwqLrvOSLeBOFztE9uw2xYG5LUO9sTT23oGgz188l3X.x2Kf5bvkkVRRRRc3D0zmRKeLWI1EW.r3YHIsJlI7PRRRRsKJOc9ksn3ew+PhM9SOZ3ulX59mz4GpH74E+VF8I..u1287.fG9RFY338N7W87YunwB.2S9gqpPGVfALN.3E9SiG.9h471PD7Gd3eL.7ilT3J1tmYbEMexVOywkW1ZCe.4SOnvmq9ocOG.DGSEI+UXSy7Af27Mdehyki0b.gNkwGFE9qAGUVLQ0SkW8Cey2JY92jSA.3qt9CJbceYQIeoqgNjwlsBd+Rm72aOUlvmW+0yjcz4UEa..LlC+DAfcslPRMpr5jnDTVW.fdVQiGEh9t0gzVc1Ce2.furxpSt7PpmpHSQEKijjgL4IO5FZhElWm8jq2i16gGpAISdXgtFRMIIpHS5vq60wd1.vtUU34I+iS25YXbatktikHS3+l5Dmb8OeZPIe+8.Nwv0U0WFhMUcMyuutbCW+CInXxSdLEcjPBQlPKc9Uj7e+t3QmLg9ty9j7brmUU3OaISK74niDS3gjjjjJc0dFxhFnswDmqE0aXjjT6DS3gjjjjZak6UAf24e9uIWtbjs6gEFHa0gOG9+uy3t.fq4wBIy3jt08f3rwzqrg+ZsKHYUJ1xMO74Fuu8Nz4.9jW+I.fyaZgwYTgxN.UOuPmh3H9d+H.3btsP8JXraZnSKLzgjTzNRE9jmmtoVOhr0+Gnl0cy1QhhfrW8UB.O4K8+PbbN1usN74f+UdzKG.Ngqdl.vM+6BcthQ7cCcGle3TBO263Mcz.vZ8o+I.3AdrPxP50o1Dyq7xzC.XQyHjTipNxPM4nBV61j62m8NgOm+QqWHBH9WHszQ5LgDPzyV6ev9zgKrms5An0c+Zn6VlJpnQO9JaUzyNSU2hFVm4DcTLWvCIIII0tIUpTDEEVggnF32bNNayKFFoR07prGQMzMpMPwg5n0cuhHezSRE0dTsRVUe+jj5XvE7PRRRRsoVmjeo5KbRGV8d7ziHTCMtva4QHWtbrGawZkbjvq62EeP.vQb9eO.3AO+vQSMvcE.NvwDR9wCOy2..xc.ea.3mLwPBFNkuenSSbo4ugQgjdbt210QbbN5c4gjjrAMzhUjo7BNd4I0Mf0Xvgw8VN+PGn3nOwCD.tthtOmwM83PtbLrdjTIANtaD.F+IGpUIG7ttjpOB.LhjRzZysTYrAC6qC.4th+..7I0r+.vFkTGE1gV88K741+s9igwci2iPcTnGMy4kjTGMlPMIIIIsJQtUx05h33F390.0hiVMqgGRRcHDM24N2V8Og+IS5Cyq65tt.vXG6XaalUqjD2L++4VjQ+SRRRKiF58Pje+E+Z9+8x9Utb4VtsW1upqt5nt5piEu3EyhVzhn7xKmuLoC.r5hrIcThpR5BJUTQyqCLj+5pI45xzLutVrj6yBSZnAY5QyqdBTSUKD.xlNjchV9GW9v0e+GVnyY7gS5WRbtbb5ibcWwteK3U.fse2ON.3mMsPhYFQuZoyuUuzyd1Sps1Zo6cu6z0t1UJqrxnrxJiToRUvWQQQK4qh2dY+8Mx+uK90h4uihJ07q+0+Z.3i9nOB.1q8ZuVgGSS3gjjjjTmbQo7s0KIULqgGRRRRpCo7cThVZMjH+00bqIFsZ4mesvDZjohUzphQ3526y+DgHXWlvsC.G7LOa.nuEEkkl99EhByKd6mG.rFSLTCPLYGRpyNWJXIIIIoNqZiK+HRRkRLgGRRRRRcB0sjtFy88i+i.v7+hPwDou8tkVTPB03iza94..20NM71lInjzpXtfGRRRRRchsxta2HI0YgK3gjjjjTmRgh0w.F4nVAGmPw5X61kuwJ33HI0wh0vCIIIIIIIUxoMIgGe9m+4.Ksu41YQbbyqJOYOtVRRRKql58Pj+3K64sr6q3ufvGKg7amKWNxlMKYylkZpoFV7hWLkUVYLhQLh1omHI0ZMyYNSpqt5nqcsqjISFRmNMoSmlToRQTTDQQQjJosAme6k8q76Ou5ae0G+cTTol7qqPaIS3gjjjjjjjJ4zljviZpITQn+nO5iZKFNIIIoNzZtI7n3sanTdrr6KeROxmxiZqsVpt5pIc5zM6zoJoUd9rO6yHa1rzktzEJu7xKHcGKaJOfkOgG422x9ZdlvCoUblvCIIIIIIIUxIZtyct9mJPRRRpEngRZQikrihSywxVyNJNYGEmtiJqrRJu7xoqcsqsuOXRpEawKdwTas0R25V2VtTdTeI8XY2FnQqmG021M09kzRYBOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTImxVUOAjjjjjVsVMUEdIcE.PlzszAHK.TUUgWqnhLsUyLIoN0LgGRRRRRRRpjiI7PRRRRsMp9eC.W3Nej.vziyU+mWz.Afi7bOM.3H1ygC.s1bI7V223AfSplSG.l1327V4HERZwa7LOG.zquwX.f9UQqb3Zxa2aB.G+nOJ.3v90+A.3q26VZDOVH.bu653Bad8ON.bTa0ZthOGkj5DyDdHIIIIUBIx2gujDfI7PRRRRsw9L5O.Lka6RAfMo6g8WWxw+hY+GAfi8bNtv9WmGkbwwb7+OesV08quiLjTjqrt0uUNiSjct.vwL46E.tqYNlUrwqguQ.vK9SCIRoxS4N.ZMI6HudA.G18cNDEA6z26ZAfcalWH.zuV6vJI0Imq+qjjjjZ2jKt4cdohhZemHsFcDmSMg3l42ukjVcfI7PRRRRsshVC.neCre.PeKp3bzu9sd.vYMhaC.dz+8mC.SZa6C.7w+8m..tlS3J.fWHoVfrwiIjHjy+jNX.XP8JDcgOe1+Y.34pKjzggsdeA.7SN0G..F52YCAf68BtA.3chF..bjm6YB.e+8LTSQdlK8GDlfwK..Nhc4x.f6bZmE.T9Ke+DkJEm6oe8gwgvpKr0iITCNNoS8HByqdz3QpH6m+R.vo+3eE.31dlAWvw+OOyTCOm+tuD.5+BeJ.328J0B.iZ7gjyblSbm.xmuCnK8aGAfScXguucWybN.v4sK8qQmORRkpLgGRRRRpCmTo53kthnT9Vmkj5LwDdHIIIo1EUUSnVUPRfGR1h+uYMSREkhG7UBcEkcb7gjcT4r+0.v99C9w.v9cVgjT7PaSnHf7auzPBONh8Yw.vSLyPxJpddgZBxKWyNlbGBKLwG8pOY35e8c..txewcC.c4M+s.vILkIB.a1VG5NJa89eRDEkhA8z2C.b.W22k3bv5U6a..SLIYGeme18C.6z5tHRAb66aXbNltLT.3YOysuQ+9x69GCOmoGv2F.1nh5BL0V4GB.y54mI.rqW8u..N9SadPTJtpCMT6OlbOtY.3ZOjMM4JCCz18c14v9uyWD.N4jDdziFcVIIU5wkoVRRRRsKhn9SoQp5qMhjzAaiZOawHwIe0FHJY91.Md21bKoC+1Ps5WIIsbLgGRRRRpM05D+Z.vD2sQ1nmWYi36C.69l2a.38+MOax9C0LiSXbaC.juDfbTW0OinTQ7b6zD.fm6sOD.XyXMaz6ywdiW.4xEyNLjdF1wfBIqXjWQnFeLm4WEwDyNLjMA.5YRMHYnaZnVeTwBB0bi70riObNuO.7ka3vCOmOwCA.GRYqQiNOVhZVTXZrGaQX7afiWwde0.vgs84qwGgWO0eTn6wr+W7qC.Ukjvi7iy5LfPRShm6BadyGIoRTlvCIIII0oQbyssuHIoU6YBOjjjjTapOi9C.S9lu..XiyDVjh5xFphGk08uJ.rg8Kjri78zjYk75.+FCAXoI6XIREdqqq6RZWrYow9LprnjdzZ2yTzeiu5pqfimon8mWs4K5Hq8VA.24EGRVxQbA+P.39Vx7ZD.vYcimO.LtgsbY1n.e1Gj7jtdMzaEOzkYJas5V8dz0p+aI.DW2+K.7eSlmUrjZkR4.PtZ9K.v6W0gC.CswmVRRkbbAOjjjjT6lb4hgjEVHNtzNcFQQoH1ZrgjTGFtfGRRRRpsURMvXfCdiAfArbQ0n9kOPEu2rlax1gjdjtnyaQKYgSJ9HM1H2xWrkxyO7UERbQ7.FG.77u33AfuXNuMDAO+CG5pL+3i+dAfs64NE.nOMv3tNq+f.fOZg0z.mQnljDko9e99x2++.oRQTYaD.rVEcZooV.HUlsC.5qI6PRqlxZ3gjjjjTq0phPqjx2BujTygI7PRRRRsKVRMvnY5qNjQPTTJp9ZNO.32tuOFww4XLCIDQg+58MU.3UKaWAfybiB6upWunAJa82NbaximKoFdj6UAfW+eNGhxAqyZE55Li+PuL.3ru0GA.F6lNP.XnCIjDERE5BLM4avNS2AfEMi2JL+G+lCrLcqkjiufa8FAfWbmCIHYa50m..+pSOzcY51QbkgSung+yl8aB.QqWX90byAijToFWdXIIII0gQw0.innNduc0nnTqTmWohV5BzzDKkijjVFlvCIIII0gvZMrCF.twy7y.fIMw8A.tr7mPR2PYJ29oQNhoeYB+5+yhhjIj4gMngVThhNd4kkjAhJBcOlc7aFxZwUcbGD.r3a8QAfexQOJ.3TlPXd8ixOdQgjTbN25wPbbN5cS7btAC6qC.4txmG.9jZ1W.XixTzxYj6U.fS8.2sB1c4eySB.9USHTiNVZBNB0Dj29ECi6f1iuC.zilX9HIUppi2RlKIIII0Hx0hKbFqbJzF1gVjj5XIZtyctk18GLIIIo1XMT6Us38GuLsi07eke6b4xUv9yuctb4HWtbjMaVps1Zo5pqlJqrRJu7xoqcsqsuOXcvjslp.fpRpEHUTQH4EqrpIE0TS3FmontkR94UxgISKdd8k.vCbXgt9xbmzCPbtXN8Q90.f25gNY.3F4D.fqc+2H.npjuQTQE0eauId9gDg7M1iiG.l5S8h.vH5UydhoVgEu3ESs0VKcqacitzktP4kWNoSmlToRQpToHJJZIul+q7aCTv9yu8xp3sap8KokxDdHIIIIsJVTJ+kWkjZqYM7PRRRRcHkNSH4DqppAEEmri7xOupndOZyQnatLty+DfHXWOp6..N3YbVgCWy+A.9WIIIIe1QpnhFJCIgje7muiyG.ViIF5tKlrCIs5NS3gjjjjzpJ9gKWRpciI7PRRRRZUftM38F.t2K6OB.y+KBcYk0eTWN.b8rtMyQZg.Ppgc1.vcNpsrMbVJI04kK3gjjjjzpP4xY2cQRp8fK3gjjjjzpDgZxw.F4nJZ+CFHek9n4HTrN1tQ+MZKlTRRkLrFdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNkspdBHIIIIolVMUUC.johLM54kslpH4DAfzsqyJIoNtLgGRRRRRRRpjiI7PRRRRsMp9eC.W3Nej.vziyUumVpANR.3LN0SB.F2HVuUBStkWky9Q.fcexgjSL869f.fJZhqaVOzIC.WZMSB.tiCYHsOSvDy6uNUHJh84r9J.vzd1v7rp252C.uVMaB.rKC6qA.evyNE.X7uznAfm4B1Y.S5gjV8iI7PRRRRqRDE4aEsYIJpAOTpF4XRRqtyDdHIIIo1TeF8G.lxsco.vlz8v9qiEC.evq9qAfS+31O.XtW0CQtbwb7ibkbROpCHBHpbfleBHx1dMeJV0uG.bEm78A.WxCNCfX5AgDo7zS3BAfa6jtYfklviMbONQ.XbSY+AfG7f1VhIlCdvqwJoItjTGCtr5RRRRpcSt3l24kJkIUno0L+lojj.LgGRRRRpsVTHIA8af8C.5aQMUj90uSC.tc9+.fIb12E.r2y3rBmOyG.dgG3VAfyXpObAW+9cpWM.bb6+1C.UjjDhexQ8y.fs6xuD.XG5aWBWvRN94C.a1E8yAfQl7Ngy8duA.bu+7WF.tk672C.oGwA..+rK93Afg06Fu6nvBC2m64Ztvv0Ms2F.hRGpYIm2O+GB.6wltNM93jXVO8s..+4geF.vTRdd9OOyTAfqNWHoG7SFeX6049AfSaTaH.bvW09..6+w9n.vdNiCG.5Uy5tKI04mI7PRRRRpQD0FUmLRsRtlkD2biWijTIJS3gjjjjZWTaSTrK5+v+5.Pb1oA.yOIvBe5CD5dKmwsEJ9GS41d..XPYeS.3xm3oC.mcbHADW63B0fiY8N+Q.XcWXMDSL6.cI+LI43yF.1v5xBDCkEtt35lN.7Gl+4A.OvC88Af+z0cr.vwre8D.dhYdTMvSRHQJ20jBcmlaquSHr8id4DCT4K+f.vjlvXAft+nyD.1w9zEpeUA.u1C9m.f8dRgZxQ97k70F1NB.6VTHQGu62MjLl8cXe0BFk0cHeK.HW0WO.7gUkjvilpMzHIUhvE7PRRRRcnsjfJjq9ayss0haipUFM7nD0nGsdGKSqgjTKlK3gjjjjVkHacEtc474.vLu0PRLlvTeThyEytroqcxYDpIHm+U+OAf86bdQ.X968nJXbZhJswxK0H.fy8j2S.XCSFfM779I.Qbc69DAf4L+PBO5VQWd0y4OC.2z6TM.L4yeuHNNl0u6gDjvNMN.3PuzeE.7HO+6A.639O35e9j8+FteyNjLk9u18rfC2k9LD.XqFdWAfuX8FZ375cQQ2nmgZExH4cAf278qD.F5fK9IPRpzj0vCIIII0oxJ2zNz5tWEW2OVYW+NjjjI7PRRRRqpTWsgOcGIps1E..eJgO5JaP4cAxt7K3vWYCFF.DWy8..e3hGUy5108kq3iFRPQ59+MAf0q3ngjIjrhQlrXEu0G9kDSLaUQmV15pofsunwumM57XuJuIVDkZB0DjYEG99vFRRMGYo2wjYebAau7BOeKJdYOO+nwHoUe3RMKIIIIIIoRNlvCIIII0tn7zMzQBIh3O+n2J.jt+gtGRe6RgIvn6ohIN0xmHgJ+74PTTDo5xtFttxK59VV8eiWZRGJTt47Q.vBR1dIUBibgtkxGkbcqU2afpCRQIU4FepWfbDyH5QxNRGRfwb9G+SHWLKZs6a8ON4koW.vFrjOFLM32HaVGeoIaooFGIoRKlvCIIIIURo35mwJa4ZnO1H1oUjjVoxDdHIIIo1V4dU.3c9m+axkKlrcO7K5ms5PFJ9emwcC.+jG+K.fS7VFCwYioWcYM.fc+.VS.3G9iBm21dCGI.rd08d.v8eM2K.T9nt..nhxCccj7Ih3Ydwv8emV+Ps93sdneA.7JIKDwnWxDMDMj3ZeP.3te7cKLe1qMD.9q20kC.yt78G.Fd+5B.7E+0Beb61FsM.vtkb+utG34CudjgZCRMy5YAfC5XuD.X+tpP2mYn8svtuxRjds.fMd.g42mL+pR5Hu46tJIs2lEDdd9GycVgyqpMB.5SEII4HW379X5O.LzMvtyhjV8hK3gjjjjZ2jJUD4CbQC0nRhqmBSZQiBjTHSWUmdiVizoVwCUcavPHIsZGWvCIIII0lZcRVThK53Nh583oGw3.fIeyOL4xki8XKVqBN91eL+L.3XuvuO.b36w8TvwK+adb.vceV6D.jorv86vtxiF.NfS+z.fcapgyOyXNPfk1sU5dWSR.QcENud2G5XAfQc4gZtQT5QB.W88crjKNl9jbdeYwOPY5G.bZ28kRTTDW7gdN.vdbm4J3zF0QGRLxwrC8gFWnJhLvQGR.xM7TuF.LwscmAfzD1+ls+ea.nxK+h.fyZc1..3NNjME.l2aLCHJh2orPekoWMPIHQRpTkqUrjjjjVkHWtbM8I0BD2NUiLx0.E6z5cNzBN21ccBSCijTaon4N241A5mJKIII0wWC8K0V79yucbb7R9J+14xkqf8me6b4xQtb4Ha1rTas0R0UWMUVYkTd4kSW6ZWaeev5fplpBcKkrIcYjJpnIhpP1PWfYgUERpQO5QEM1YurWH.T0BCWeljqqk2aSxONg4MYBiSEYZgiz7dI.XG16qG.94OcnllLrdT3okM44kzguujlv88gOrPBP9WSHbcm6nVuV18WMKKdwKlZqsV5V25FcoKcgxKubRmNMoRkhToRE5nPIul+q7aCTv9yu8xpg9Xb0Y7i2kzJalvCIIIIIIIUxwZ3gjjjj5PKSEM2DZjHIoC8nGMw4s7WH.TQyNQHM03zhm.EZs2V.35Oh4C.m188x.vzm3VW3cKcgIdYAu8iSDQbMyYr.viXxNjzpoLgGRRRRRkXhwO05RRlvCIIIIoNv1lweK.v477eJ.IUni78xkkWUKNz0Xto6OzMbZpdBijToJS3gjjjjjjjJ4XBOjjjjj5HKSHiFiZzMurZzmsXGBu1tMgjj5bvDdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNkspdBHIIIIUJnlppA.xTQlhO..TEoCGmrjbh.jrWII0VyDdHIIIIIIoRNlvCIIII01n5+M.bg67QB.SONWid5oG3IB.O74E1demTHgDSaFGN.zi1i4X8IYdeFIy6Qe+SGhUVSyC..f.PRDEDU.1890sl0kOu+5TgnH1my5q..S6YOH.n1239Afu8w7SCmXz.AfK4L5G.LkWaz.vybA6LfI8PRpslI7PRRRRZEQTTCenTM7wjjT6KS3gjjjjZSUYxq6+kbS.vAMzdA.0UW9e4+5.f3xB6eMWiEA.W+0FNdEqbllKmEEGGdcwYAha5Kn52C.thS99.fK4AmAPL8HoFcLiG8NAfdL9eB.73ieD.Plx+u.vqeE6O.7fGz1RLwbvCdMZKdLjjTBS3gjjjjTahlwhjHIoUZLgGRRRRpMU9jRrwa7lB.8suM9a4r5O5e..O4LCIiXnawF..e5yLU.3p+6gZow.9+ta.3W8GVL.rM6yIC.m0Ie.g6SljDjTym..+l63ZAfK8NetBtea8XNN.3G9COT.nesx+Dfy5ouE.3OO7y..lRe6RX++1qF.Nuosfjy7T.fylPROthItc.vAeU6C.r+G6iB.6YRsKoWstoijjJhI7PRRRRsKhZjZagf3blHDIo1SlvCIIII0lp6IKzwK9rOC.rdawZA.0Vabxqgya.Cea.f07K+bHBl9SD5RK+vSJb7Zq7CAf+1iMS.XKSpIH2ygNO.XxS77Afaeq95.v4sKqW39dsee.3G8a9l.vT+kOFDGQeVbnarbsGYHQFWyVt8gsGSK8IrJ.30dv+D.r2SJzsYxjbz9sc6J.LxnPxM9rC+r.fiaL8GXocik0cHeK.HW0WO.7gUkjviUUEwDIoRLtfGRRRRpcUpjLEmOwGoVQyXbtFuc2tbhC2233FsgprBwzZHI0wiK3gjjjjZS0sjWm9MeQ.vuuANuy9dBI.YzMz6HslP2aoaGXnlXLgQuEEb3y6GbO.vO9SWXA6eC2qKA.t0CciAfg12vLpp4u9.vVOxtB.+oZylbEsvUAIanKqLmYGhpR+W6dVvgyz6MA.F4vC2mYz6gB.Ctee0BGmdtNgyi2E.dy2OzeaF5f6FRRZEm0vCIIIIsZiT91ekjVsgI7PRRRRsopL40S7W7z.vAM3d1vmLPkyt92e97WrAqyWodOd5LqY3eTS9phQ300dMCI13WcoiE.lvqTS8d8eqssQmVMrZlO.Lq3vGslMjrTXKoMLyqcI6KK0uPBQx2UaX4FGIIshvk3VRRRRsahWE8Kva+gQRRlvCIIII0lJehExzDm2JpkO2DeB.baGPnMu7pe2yE.dnKdj.Pe6c4.vLt3wA.2cqcsXxzK.XChx+2NLcCetMCceIUR0UrwQRRExDdHIIIIIIoRNlvCIIIIspUcz17YPIaHyGKH4iQyVtYgtzRe6c2AfO40eB.37l1B.fu0ll+5Zg27zqE.rwCHjXjOY9UkzobagcWkb0A.eL8G.F5FX2YQRpsjK3gjjjjVsPTp1uJ6QJyMsjTGNtfGRRRRpMU9ZRQ4k0LqIEIuizn9V3tapqd4Nd5v.ruWzAB.i+BNT.3gtfvgSMvcE.9tiIj7iGYluA.T0XCsqk0Ip4tfHU..CbzgtOyM7TuF.LwscmSlWgY1Z0mxazQYduwLfnHdmx1J.nWs2E8DIoUy3ZQKIIIIUfURcVll8BrHIoVin4N24Zy9VRRRpEHNt9e6SEu+7aGGGujuxuctb4JX+42NWtbjKWNxlMK0VasTc0USkUVIkWd4z0t1012GrRLYqoJ.npj14REUDRlQaVuPYduD.rC680C.+7m9tAfg0il5BCyqG9v91.v+ZBgq6bG050VMyzJQKdwKlZqsV5V25FcoKcgxKubRmNMoRkhToRQTTzRdM+W42Fnf8me6kUwa2T6WRKkI7PRRRRRRRkbrFdHIIIoRRoyDRzQSF3hVq0NT6Ot9iX9.voceuL.L8It0M5ksf29wIhHtl4LV.3QLYGRRsKLgGRRRRRqjEuxpNgHIsZLS3gjjjjzJfsY72B.bNO+mBjuBcjuWtr7pZw8C.to6eb.PeZOmbRRqFyDdHIIIIIIoRNlvCIIIIoUDYBYzXTit4kUi9rE6P301sIjjj.S3gjjjjjjjJA4BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ4T1p5IfjjjjjZZ0TUM.PlJxz5Ffrgquprgqu0NLRRcVXBOjjjjjjjTIGS3gjjjjZaT8+F.N9Qes.vO32MU.XnUT+m9rdpyA.99O4VC.O8T2O.XN223AfSplSG.l1327F81V4reD.X2mbHACS+tOH.nAtsqvW2Jay6uNUHJh84r9J.vzdpsA.t3cZ7.v27tmN.L1AzsFcbpad+Y.XW1+mD.tyoeE.vf5n8.KI0FwDdHIIII0QVTzp5YfjTmRlvCIIIIspQsUB.weYg6tui7z.fqrt0uYMLYJq7v37g0zht8s1qaklpeO.3JN46C.tjGbF.wzi34..KJNN4DS2rFtx5yNB.27jtc.XR27KA.+tSZaaaluRRcvXBOjjjjTmdQQst2Vaq85V0Htd2ajI.QRpdYBOjjjjT6hxyj+WPu9+ExKu7tWu6+ymcnVS7b00K.XXCXMAfY+6ue.XxmyM..uSpgC.6ytsH.H0lL15c7Z4WWU.vK+32F.bBW98UvQOjy75AfIr2gZoQEIIw3mbpO..LzuyFB.26Ejb+hF..bjm6YB.e+8LTSRZpbYLqm9V.f+7vOC.XJ8sKgCTc3ktmrPGOzcGpYJSaZON.7JIKLxgbl2L.Lo8tv62lMtSB.Vztc7.vKM9WD.11d0DSHIoNY5Lsj1RRRRRRRRMKlvCIIII0lp6wuF.7T+xGB.V2LEkviPoyf2e5+Q.HpmaUAGt54E1+KWSnlSrf29I.fC8b9o.vwdY2J.b4q67.fq8HCc6EFdg2lV60MqmXJ.vIbkeA.LkaK7brIomE.boiOjPhovcE1dL4.fO5UCc+jG502A.3J+E2M.zk272FFuoLQ.Xy15+..rC8ogdq3gDl7ZO3eB.16Ich.PlhNq78jk+8uadEb+N14LS.3Xtfv8aK95g62Nl+90iAA.m3.CIF4oeoPMAYa2k90.yGIoNmbAOjjjjTGd0WcpHNt9qoEsEW2xJWx42RutFnjazpDmqYLXsg2OIoRAtfGRRRRpcwa8Z+M.3yS1tpjW6dRo63SdkZC+iQT7UtlEr0G85y..JaDmE.bPeqMEXoId3rugifnnHF6UW6J30sP.3u8fgZZw+yjB0FiuwfBE2hrY+e.fIdpgtZxO3gBc4jEtGaSA22i8Fu.xkKlcXH8LriA8sAfQdEgZ7wbleUDSL6PeVihevCx9eCm2rCyq9u18rdOsJav6WXQdFYzc..eXx8ikb+BYCYC25v+Ghm9SWX8OOjj5jyZ3gjjjjjjjJ4XBOjjjjTapEEsk.vobYWNDGyfRW+cok+yvC0PiC8gZdi6.G0l.TO0xhd0a.H9CqYE65p58Af+dRxJ9qScR.vnmZ8OeJ+a9s.VZ2OYQIejW5dlh9aJVWcEb7hmGKmZlO.Lq3PsAYCIK02mWkV+8KLi66.B0xCVXS0uXjj5bxDdHIIIo1GszZdgjjTaHS3gjjjjZWTaMII6nhF33KoJTz77t+sYC.YOfACrzjUjstpow9630rutJ9p.vfiBmQetzeI.bZiZ8BmexoUym+d.v67oYHWLjIdQEcGq+DYzrkITyP1fn7yslJAFsz6W3I4+7ud6vlqeKYxII04gI7PRRRRRRRkbLgGRRRRpCsu5PFAQQonlq4hAfm4M2VxEmiQ2+Pee4gttaA.RsIG+J30EpoGC+vCIr3jl7cC.61u5DAfgz84A.2w3Nb.3AF9oGF2qZSa7Gfr0eMLoAkds.fMd.kC.ex7qhb4f7cWklb7Zx6Wnlk7YuwhAfAtU8nkM+jj5jvDdHIIIoN7hSJfm4kJ4i6QTTi+1YasWWghVl+0pl29bJeW6RRsXlvCIIIIsJR2AfndV3dKthUrVC6PAfa7TBcQkIMgwB.WTQmWYins451lweS.vI9wiG.NluyST37aDG..bK+n8hXhIS4yEXYq4FEISlBNd4k0T0jiPQOYfiN7Mla3odM.Xha6NGt+EMds36Wkg46LdmpAfwL30tIlORRcN4ZEKIIII0JD2fEJzU1cmF6FNRR0mn4N245OgTRRRpEHtAZ2pEu+7aGGGujuxuctb4JX+42NWtbjKWNxlMK0VasTc0USkUVIkWd4z0t1012GrNIxVSnFbTU1PxE5QEYZWutZpJbc0PK65VgMuWB.1g895Afe9SGpoHCaErja7AO2kB.G7ssI.vzuq8CnAalNpIr3EuXps1ZoacqazktzEJu7xIc5zjJUJRkJEQQQK407ekeafB1e9sWVEucSseIsTlvCIIIIIIIUxwZ3gjjjj5TIclPVDZoAcn0dcYpHbcqjx0wRs1aK.b8Gw7AfS69dY.X5SbqaciWcyA.t0y4o.fy7dNUhiiMYGRpjkI7PRRRRZ0PMzGMKIoRElvCIIIIoNv1lweK.v477eJ.TUx9aoIynl4uH.X2uoeI.r8CnasESOIoNrLgGRRRRRRRpjiI7PRRRRpirL8A.F0n6yJ1vz6gB.aeuWgmQRRcJXBOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTIGWvCIIIIIIIUxwE7PRRRRRRRkbbAOjjjjjjjTImxVUOAjjjjTosZppJ.Ha5z.PEYxrpb5zNpF.npZx+bltkc4YSt9rYRt91tYljzpiLgGRRRRRRRpjiI7PRRRRsol2+7o.fIeTSA.dEhK33Qksa.vUdOmA.rC8qaqP2uY8PmL.bo0LI.3N1mPxJNrc4H.fuy876.f8c.M98oxY+H.vtO4PRKl9ceP.PEM4LHb9O8YtW.vKrq2J.bI6R+ZlOAA0Mu+L.rK6+SB.24zuB.XPM8DPRR0CS3gjjjjZyEE0zuMyTQQqDlIRRZ0UlvCIIII01np2DXoI6Xnm+TAfKdGFD.TVcK..dkmHjbgS8fOc.3tlQ37FTqrlUjs3czsPxJtna3mFtu8tKMqwISYkC.weXMsn6+BdyGgHh3h+K6C.7DWdKKYG4UVe1Q.3lmzsC.S5leI.32cRaaqZ7jjVcmI7PRRRRJQyIYJRRpyAS3gjjjjZST2W7o.Kslc7c2rAC.8tW4qcF8..F0gGpcG+vnW..p8KSRTQuCQ73i+6OA.bMmPHIHuPbN.XiGywA.m+Icv.vf5UCzETp4iAfocaON.L7ycy.f9kb9y92e+.vjOma..dmTCG.1mcaQ.PpMYrMym34C.O1Qei.v99SB0.jdWzwm9O+xAfK7N+8Eb062ob8.vwc.aCvRqUHa13NI.XQ61wC.uz3eQ.Xa6UybZIII.S3gjjjjZmDsBTiNRkpyY88HYsYjjTG.lvCIIII0lnr0cyAficDcE.NqCbz.vVOlCD.10uQnVTr4a9V..emw+cK35qb1+Z.Xe+A+X.X+NqPBHdnso6.vu8RCI73H1mEC.OwLOp5ehDWM.7+9JOC.70V3oCDyBd6mF.NzyITaON1KKzMUt70cd.v0djmS35Gdy64Md9yF.to3PM6XpCt2Eb7O5OdKDkJhK5dCIW4m+POAPDq4mFRrwAdbmH.z2sbZ.vAO30Hbg8HTySNwAFp8HO8KMG.Xaagc8EIoU24BdHIIIoNLZuqgF0WpShiiqmyrc4tGdI2Jq6mjzp2bAOjjjjTajPBGN7oFpcFi3YlN.7PO5iA.+3y+WVvYOj847.fq8L1S.3i+6OK.T1HNK.3DFWn1Vju4sbTW0OinTQ7b6zD.fm6sOD.XyZlytO50mQAi+A8s1zBF+y9FNBhhhXrWcsMqwqpO4cCqgQTHYF8rntLyh97+K.Dm6K.fO3C9b.neCaWAfeyitc.PWW60nnQNTyS1vsNjrkm9SWXyZ9HIoBYM7PRRRRcZDa5HjjTyjI7PRRRRsIxtvPBF9jED9apMrcY+J30KnlPREd6W7gAfIbNSA.dpw9MIlX11jwYfeig.rzjWrDoBu000cIerTxBzxW.jANpModG+t0qPBUh+vZZdCTx6jNUlPRM9ZUT3gGz2NTiNNy+0kB.WxIO9BO92LTCRN6y3PAfg167ynP2jouCHTKOXgMP2nQRRMJS3gjjjjjjjJ4XBOjjjjTah2cFWB.bDW8FB.OwycJ.4qrGP5L8..F5nNX.3zF3cB.u4bC05hsJ47duYMW.HKgjdTb9FVzRJxnstjO7t+sP2UI6AL3BFkr0UMsn+df0ADA4p4u..ebUGN.Lnjjd7kyaQ.vvNhPWm4EO4PxQl8a+5.vccLgtByUrkec.3NNjMM+LA.9O+q2Nr4527mRRRZoLgGRRRRRqLkaU8DPRZ0ClvCIIII0lXi1t8E.hqMzET1+Ktu.vTG+NA.8oKUA.u4ye2.vU+NKF.l7f6C.7Um+HHJJEUeMgt2xuceeLhiywXFRHxD+06ap.vqVVnKmblaTX+U85EMQxt7sdV.9pCIL90bMWL.7Lu41Rt3bL59GlWOz0cK.PpM43aVOuUzm92nG+8dpPBWN16XT.v89aNN.X.aRn1br9Qgrk7eVtjpDRBxm8Fgu+LvspGMq4ijjJjI7PRRRRsqhJX8Gp+EiHu33Bi+PTTa6aWs3wOUx32VeepeQKy+x2FtjT6MS3gjjjjZSTVe1Q.3wuoymToRwkeLgZ5wDl10U3IFMP.3jt5G..1890kjCDpsG23Y9Y.vjl39..WV9qK0H.fob6mF4Hl9kIr.Byp3IRlP2NYCJZQLVqgE5FJ23o79gweBiE.tnheNFQi+btjGitGpNI6V7qA.+o24KHWbLCZXqE.Lr8+pAfu2Kcz.vgraOXQ2muO.bWiaHENvUFpgIy3cpF.FyfW6l2DRRREvkVVRRRRs4xkq4UnJhy1xKnE4Zwsh1VdqqURRc9EM24NW++CfjjjTKPbb8+1mJd+42NNNdIeke6b4xUv9yuctb4HWtbjMaVps1Zo5pqlJqrRJu7xoqcsqsuOXsSpopPMxHax1YpHT6MZpdrR1ZBWWUIWXEMyqq4ZoieXD6QEYZUiyG7LWJ.bHO5v.fmYpiC.JdzV52GB2uJZf62G7bgw6fusMA.l9csegyuUM6T6sEu3ESs0VKcqacitzktP4kWNoSmlToRQpToHJJZIul+q7aCTv9yu8xp3sap8KokxDdHIIIIIIoRNVCOjjjjT6p7I5nkJclv00d0iRZqF+0emNR.Xmm72E.dxYuK.v9NftUv40jeent4..2547T.vYdOmJwwwlrCIoVIS3gjjjjTGPMzGcJII07XBOjjjjjVQjtu.vYb++T.3uM+Ejbft0.WP8ql4uH.X2uoeI.r8Cnkc8RRpPlvCIIIIIIIUxwDdHIIII0Fna8aD.vN1Ju9L8dn.v1261nIjjzp4LgGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjiK3gjjjjjjjJ43BdHIIIIIIoRNtfGRRRRRRRpjSYqpm.RRRRRcnUSUgWRWA.jIcK6xylb8jIb8svKWRRsRlvCIIIIIIIUxwDdHIIIoUPgDL7vG+dA.W8qTUy6xRMB.3BN5JAfqM9z.foM9Mukc6q9eC.mwNej.v27tmN.L1AzsV13TrpdS.33G8QA.G1u9O..q8LCyyKslIA.2wgLjFcX9fmcJ.v3eoQC.OyEry.lzCIo1alvCIIIIIIIUxwDdHIIIoUPgZSwNet2N.Lh5JG.JaQuE.btS37.fc7xtE.3auwcG.V7hCmWOi9b.3JiW+UnYwhhiAfZqKKP7JvHkE.dwe5oC.UdJ2A.706cHSFuUKbz1v83DAfwMk8G.dvCZaIlXN3AuFq.yQII0TLgGRRRRp8QbtU0y.IIsZLS3gjjjjZSrV8cCCuleGYqF.V2nH.n2avFA.8suEVaMdue+uA.dt55E.LrArl.PcednFZbWS8GC.25zB0piTCbWAfK7r+A.vtLvhmI4qNF0..uvcbg.v472F..7.Wenlbz2FnHZj8yeI.3ze7uB.baOyfq+SrHy6u+H.vobhOK.bj20UB.67.5C.bvW09..6+w9n.vdNiCG.5UyZzkjTKkI7PRRRRcJkJpi2akMJUTCdr3bqHeLajjTKkI7PRRRRsOpqNfkVaMnApsFUOu+H.7x0riI6Y9.v8s2GK.bmeiiF.tqG5x.fO92eE.vYbzW..rQ+lSofwq6cMjrjW89Nmv4cqgZDx07HWH4HtAS1Qdu6e7WC.oGv2NL9UT+mWu5d3sR+ku6SC.i6GbU.v9ew2C.ryE0kXV2g7s.fbUe8.vGVURBOZfwWRRqXbAOjjjjTmBM6JBRCj7ibqPExzl3V1tMxRRp0xE7PRRRRqhslErUce5+K.bSw8C.t4y+vHlXFbOBGevG34C.+nd72AfzIIIYcRpUHWzAtGgSLJTbOtlG41HGwrC8oKMuoSMKB.FzdrE.46AMKU5LgtLye6AuF.33t7WE.1oyLzMWN0cY.0+31y0A.FIuK.7luek.vPGb2p+yWRRqP538AeTRRRRZYDuBlLi1yjcHIoNtLgGRRRRpCkZ9hON7YDIZM.fJJtlajt2.vnFWnasP0+65efheG.3+6+VCwwwPyLgGe1GLqv+X8Zf2pbbHgG4dmYB.uSxt68+cg.P17Syk6BqEXYpoIT+0zDII01vDdHIIIIIIoRNlvCIIII0wRYkW31KWTIBcwko+KdT.XcF8+C.TYxQOwa6w.fM4UNS.33OloB.a4LNK.neMQWZYcV+AA.ezBqo9OgZ+T.nGi+mB.2+tNO.XreuS..d7cXZ.v9N30ndu7tGkuDm1DSDIIsBwDdHIIIoRNwwM6d5R6.6YKRRcDXBOjjjjTGJcaC2Z.XbwWA.bC26K..S4vCI43y+S+JhRGwEdy2N.L08bj.Ks1XjoK8B.F9AdA.vtN0CC.tf6NTyO9Eieqa7IPRWXYQy3s.fpF+lCrzt0R9Zzw50iPaio28OLdW82Mj3iS+nuU.3qOiSA.5a9fbjKzMY9X5O.LzMvtyhjT6IS3gjjjj5TIJsInPRRMMS3gjjjjZmDpEGqSTiu.EKWkrHceAfi+tmBQQQbleuPs3X2tkB6nIS5pe..XDekv1aPTxeKu5pAHFRGRRwO3md7DkJhwdbgZrwL2sP2UYm5a820V1fg80AfbW4yC.eRM6K.rQYhp+4ahsehWK.rqO33Afo9jiC.tz8df.v7diY.QQ7NksU.Puxz.CjjjZSXBOjjjjzJIs7VvZbbieMwYquZ0wxeMw45.z9WahE9QRRsshl6bmaGfe5ujjjTmGMzuDdw6O+1wwwK4q7amKWtB1e9sykKG4xkirYyRs0VKUWc0TYkUR4kWNcsqcs88AqCqPUynpEVE.jthPsyHS6VSN4KAfG3vBIzXtS5AHNWLm9H+ZsxwKLue3C6aC.+qIb2.v4Np0aEaZpNDV7hWL0Vaszst0M5RW5BkWd4jNcZRkJEoRkhnnnk7Z9uxuMPA6O+1Kqh2to1ujVJS3gjjjjTSHJk+xkRRc1XM7PRRRRcvEhxQEIcEk1e8D.F24eBPDrqG0c..G7LNKfkoqqzLsf29wIhHtl4LV.3QLYGRRqTXBOz+e6cuGtbTWeGG+8r6dVHWvfFDpQLnIQhQJpgK1Jh9fJRQjFPQqhRKwKbInHnXMJJHVAsbQ6iHnBHhDAzJ7TZ8ZHZUQPzGodCuSAplZZUDpl1DSx4rmc5e7ami6YxL6kyYum2uddxyI6ryL6u4bXzLeOe988mjjjjxSGZxeG2oNQRRpkYBOjjjjjxvb2+iC.tw262..17ueb.XQKr8VdU111WL.7Q9jgdBx9zoFfRRpgrfGRRRRRMP0pYsRvHIoAcVvCIIIIoLEZVGK4vOhY0YYedJGV3qy1gijjZK1COjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHGK3gjjjjjjjF4XAOjjjjjjjzHmR86AfjjjjjF9M91FG.JOmxYuCSFd+sMY38ya2jj5TLgGRRRRRRRZjiI7PRRRRcF63W..Wvy8j.fmx08E.fW79+HlgmvsA.+vu7sC.K3Ydz.vhmyLeHNH3meSqF.Nqwey.v5W8eZebzL68Pe6qDhh33eqOJ.X8etCA.Vyy6jAfWzM7k.fUMu+M.3HeIeN.352vk..KaH+mmRZvkI7PRRRRcIQ86Af5Eh7myRZvjI7PRRRRcHS..+133NyoaxMA.m167FAf08UO5Ny4sOaQG94..WZk8sOORlkpknmK4ruI.3ceyeEfXl+bBE.4ccEeP.nzB2svWWvyF.t507w.f0b02M.7kNqCsWMhkztXLgGRRRRZ3fIIX.WGpPWRRcHlvCIIII0cUKI.+CuoOE.rhWz9A.234eE.v8GsD.3U81WK.7pOlkB.e4K50GN93+W.3jOx2K.b8q+sB.Kaxv48Fd+W..7gV+8B.QEOb.3cbU+s.vK3I+nCCiMF5EHm2k7U.fEs2+O.vmdCU.fS74uE.X2OlKEhi4Td5OlocY769geR.3ru08..txy+XAfs7c+L.v6+LC8jh6LtJ.7DO5yH74cVmXX7tfh.vC+.eK.31qr..3.WxdB.Ud3eJ.rtq7uG.9nq+eG.JrzmO.bAusv2ONxZWOrk165G1L.rgq5hCmuq+qMsquS3Mdoo5Ebi...DejDQAQ0.vY7RC8fil0ZMtua6Z.fu0S6s..W3hBI4fw2H.r9q8eA.dZu8C..Vbsq+CXUmE.r0i50A.28puK.3PWPS9.kjZSlvCIIIIMRpPzr3epaNoIIpP1auPNauSpcudlUW+RRi.LgGRRRRpKKzaO9u+9gUmia4dNL.3R+3eB.X29ogUyky7BOU.3.N3uN.bvujyhnnBrra6F.fW5G3uh3pvis7uG.V2peU.v0tnWS3025ESLve36by.vZdM+k.v7t0uJ.bHUBIE4N+tgUMjc+3CIlXsmcHgEOpJa..N2O32..No0cB.vbXb.3aeCWG.7aVwkB.EdfOK.7he8gDYbBu0PBItkCYd.vW3hBI73jO9sC.elu5qE.1wCEN+emwe1099SH4E2zwc5.v0+LOkv0ysDRzxu9qERNxa4TNe.3w+kdO.vcsl165+IdeWCQEh3ccikAfq5V9L.QrmOXHgEury3M..K5otd.3Dyc00Ir547Ct4uI.bbqIbbkSd63c..+3u2WF.9S1xalvzcoVBPl+x.f2vRCu91t6PhPNzibw474IIMyXAOjjjjT+QGtkOj+oKpy+gkbl6honnZat+M65emSmRsWWc1+8l3Nv4PRpSyBdHIIIodpS+Ce9TsZLG1xC8BCV1KD.N7KIziO13l2FwDygs7mD.rGQgjFrhmbnWeTXS2F.7Qt+PRBdmm2wRbbL667FKb9dNqB.NoK5SC.+S2wu..NjCp1.nvJAfq7LeEgyaslUQkGbOIJt.Sd4uI.3Gs4PBONzx+b.3FtisB.q8rVAPL+m2UHwGkVYnmhblqJz6KRR5vq8x9PDUHha+4DRfwseugOuCf8bZe+nxC9iCWOwgDNb0m2eMwDy9O+v6u+uryC.dOy+6B.S9K+Fynq+We4POKItZHgL+pe0CC.K9.C8HjO+s9mA.69dkWxNpYxeG.rwGHjbmmvdsGMd+2IyE.1uCNjDla6A2Rad7RRsFmXeRRRRZnWTpdtwLs+UDG0J4pn0SyvLI4Cwyfznzot9kjFkXBOjjjjFfk9AYGls03vCxOuxodX7JUl16WN01SLwjguNYkwm11eWq9XZ3m6wNVRADBIRHpXnGR7nJO88qzdef.+wdKwF9daB.dBy8qCQQ7er6mF.bP0VMR9s0Ntk9LW9zG2IJD9mZ+Xl5mgSRVEKY7e+uNL6Rpkjk4TL0NTbg.vQrpPRL9C05cHIZ0q+k8BC8Zi09ytH.3ce1qdZ62xdVgdLxa6sbR.vJV3NcEUa.G54H2WsUil8Kmqq7Et.WzRB+bfsj9Bd3znz8pRiJrzuRRRRCn7AnFP3OGTKx6YkFrXBOjjjjTOV6lHffwRBBPkIlpeaBvG9KdmTkXVYsddAECQAYi+neBTMlstWKJr8sG5UFEV7iA.dD6TvBB8hhC+0dr.vU7QCqhLy8QDV0RNl275.fETau+0095u391TsqpPROReZSRtxN+N0TZro+5cZ2BIpXCe7aMLJWwbm161pW++eOTHSJG3IGVUYtqyNjTlG3duG.Xcm14B.WxS8OG.ttWwSN6wa4v2AdbSMsYZ2DZDFe+xe18Fd491lGtjTKxDdHIIIogZUyq3I6hrxgLqu9a2kCFIogDlvCIIII0cMYSh4edue0Z8vipee.3d9IajnpvicEgUCkipVBC9.ep6H70W0yB.F+99WAfW9o+tAfS3xtUhqFyYTKnGw+WMd3ruGTnmX7Tu+POs3liBqNLW46YwSa+16kuRhhJvNd+uC.3K7h+mINtJG8xCK6Ke6a5JAfueoPu2XsO9v1218L8Ou4teGL.rp3KA.tha7NAfK7u4oC.O727SSTwHtfq9iEFGe1OUae8CvQcuuQ.3zuti..twO+Y..K4IE5kF6aTHoF+xlkXihOR.3ItjPxT9MadaTsJjr5qzzedSHYI+1e31AfkdPyuQ6rjzLlE7PRRRRiTJVn2Eh433oGOhntvpiRTw1quPz5W+QjL0hhlkA+tG9sbIoVlE7PRRRZ.2vSiPL7a7+Qmd7VNrZe73xqX.od+wJUKgAyYuAfm8yJjLhK6Ld4.v1u1PO03b9DWDQQQ72cRgdOwK35mdwGNhS4hAfS6v1mvFdfvWhVTStL1ikB.uriOzqJ9IaOrpkb.KX561i7.OQ.3Cu1PuwXMm5wC.u2jcnvJAfK7icNTkXVb4v2WtuzedECCnW2m3BIJJh09JWK.bTWyzmRJq48ER1wJWXHoIKqMu9m+S48A.ux69T.fWwQcySa+KsxWM.rtUs7zivTB+7XoOuPOO4J9h+..3TOzma3xoY+79OD54Iek6eGgw8xezDGObO8iFdtGUZWKVKVIIIoALY8vSCmOPUdODam6gaGFdP4b6wFYnYWOwSN8hZLLb82redObbMjuQm6WkF8DsoMsog6+WXjjjj5wx6AzRu8jWGGGO0eRdc0pUm11qFZBBTsZUpVsJUpTgJUpv3iONacqakwFaL1sca25hWUC9Fe7vp6Q4xo6wDgsussrsvKKGRfvb1o8q6ZxwCe9aKLbXNyILNZ+QwzudJNmPOtH+KmY10+3aaa0N5h0Fukaug4Cc2.vgcbWN.bU2VXUs4.aRK43Wc6WD.bhW6SB.1v5Ngvme68oOvXG6XGLwDSv7l27nb4xTpTIJUpDEJTfB0lqOEJTfnnno9SxqAl11Sdc8xq3IVTEolyDdHIII0CT+Czjd6sy9KoAWM5917t+26yk5drGdHIII0mk7PO4kbDefnfcNYGIpkPg42eWsOJVKYEy9QQ6d8Lyt9KOmYYlJ1qCE.t7Sdy.v4bSeG.XCm5Am89WYi.vG8b+h.vZug2DwwwCsI6ndM5dTKpgT+iI7PRRRpOvGBR6paXu2cLS388R8VlvCIIIoAXome+RCZNjUeM.v4dGOH.TqShrSI2X7MuU.3u3i7OB.OikL2dwvqqy6QkFbYBOjjjj5wZkGLxGfRZ3Sqdeq2aK0aXBOjjjjFfj0CLYwOz.sx6C.bDOu8ow61BWA.7LVXWeD0S48rRCtLgGRRRRC.x6AlLt7RC1Z18pduqT+iE7PRRRpM0oK.Qx4J8CLk0qKTv+4aRCBJTnPacuamhE.Up04+OlRRRRcIsyRUYd+VgKTn.EKVj33XhqFuK4Jagzfn5umrXwhSULxFkvilUrBKjgTmkE7PRRRZ.Q5eavIObTgBEHNNlwmXblXhI5mCQIUSkJUXGiuChiimJsGYcOrj5erfGRRRRcQsZRNxqGdjjvinnHhiioZ0pc+AsjZpJUpP0pUIJJZpDdznd3wrI4GRZlwUoEIIIoADoenmBEJLUAOJUpDae6aepBdDEEQ4xkIJJxhfH0CjjzpIlXBpVsJUpTgBEJPoRklpfG0OsVrHFR8eVvCIIIodfjG7IoGbj9AgR2aNRRzQxCTEGGyXiM1TOrURgNhHB7Ypj55pNYUhIlImbxot2brwFiRkJQoRkxsGdjrsrJBhEEQp6xBdHIII0gjtnFyjiOoPGo6eGEKVbpDcjDk9su8sO0wFGGO0Tdo9O+jsm7m1Y7YCRUCiZ0BHj0JpR5hQj2zTIoXGiM1XSKcGYsRszsuNjT9rfGRRRR8P0WTjrR4Q5GXJ42jbwhEmZaEJTfImbRlXhIXxImjpUqNUgNRldKoKzQ5hcjUwORWfCK3gFF0rdkQdeMqBejTDi5mdYIE4HYprjdEZoQKQscphgHoViE7PRRRZ.S8o7nPgBTsZ0oUvijljXoRklpfGoS2QdE7H48x5qoe+NMKfhfdWxEZVyCMqoVRVEln9hdTeZNR96IMU3j8KqOaI0eXAOjjjj5xpu.F02CORmxi52mr9sRm7fUI8uijBgjTni7RzQiR3QZVrC0KzuJ5Q5smUJLR+55mdY0m1izSikrNG4ctyabHoNKK3gjjjzLT6zyNpuXGMaeROsWZTeEH89mUJOpeL1rzbXAOTuP+NkGoecVS0jzo1n9BdjUQNx6bztiwY69Io+HK3gjjjTOTVEII81R2COp+AcRZhoUqVcp9FPxzdIcwOxqQk1no2RV6izvllUXi7964U7hzSWkrJ5QVGe8aK83wBXH08YAOjjjj5vZmjezniK8CMkzPRg+XgOR125ec5iuQaOuG5xBdngYMpXB4U7gl0SOx6OoaXooOGcxwtjZOVvCIIIodj75aGIuW8aK8C8znhSj97m0TZIqhvznUnkVYJ3HMHJq6SZVxNR96MZpozJSikVMsG16Nj5MrfGRRRR8PoKjPVEVHqBiT+6UeROpuHGMKYGY03TyhE5PiBZkBDl9qMKoG0uslsTz1rwiE6Pp6yBdHIII0GjdZkzpo5HuU1k5OuIE4H4Av5WKCsR8SMq.CYUvi5eulkzizutYaK84RRceVvCIIIoYoYZO6H4XyJgGIZTROZ0jcj04MqwqE9PihZ0jULSS5QylFKM6yscG+Rp0YAOjjjj5wpOQGYsLzlVqjziYRxNxZbIMpqSmziFssrNtrFCRp6vBdHIII0kznjejtnGM53SNG0+vRyjjcztI5vDengQsZu6nYutYI8nY6adetMKgIRpywBdHIII0mktvFo2V8uWVOb1LMYGM6ArrfGZXT6V3f7ReQqjzi5ecVE7nUJDhj5drfGRRRRcY4kvhzaOqBeT+1yq3FoS7Qdm+1MgGVPDMHZ1V7flMkVxZ6sRQPZ14zjcH06YAOjjjjF.zpI5n92K8w0rBbzrlVZ6xBdn9gNcAORu8VoXE4M0Vp+85DiUIM6XAOjjjj5PZTO6nUOt5mRJo+60u+4sBsT+6mWeBoQSalYx3VZXTVEznU5yFsRxNZkyU6L9jzLiE7PRRRZ.Sdo8Hq2qYEyn9hdjdeZUljCMLXl16NZzwmWALZ1TXwhUHMXvBdHIII0g0p8riFcbMKkFYkni5k291Jii7FWRiBZk+641c5szriocFGd+lTmiE7PRRRZ.U6TzirNVH+hZzn9ChzntVsXCsxTboU1OI0eXAOjjjj5wZ2jdzHcp9wgztRZ2BdzrW2JqFKs56KoNGK3gjjjz.p7ZZovNWniF0iOZzwIsqrV89f1corURCFrfGRRRRcIsSRNZ14HY+Z0GnpYelRJesSROloEMoceeI09rfGRRRRCIxJwGsZROxiq.KZWIc5UxEKRgzfMK3gjjjTWVqlziDciDeHoYeAOZmyQmd+jT6yBdHIIIMjJqki11o3IYs+R6JyochznEK3gjjjTORqzyNZm8q98URydch6mLYGRCNrfGRRRRivZmhmHsqJK9fznIK3gjjjTOVqNsSx6gvlIEuvGnSpypSzOPjT2Ug98.PRRRRRRRpSyDdHIII0m0oaznN8Ujl8lsIxvDcH0+YBOjjjjjjjzHGS3gjjjz.l1MwGM63kT2m22IM3wDdHIIIIIIoQNlvCIIIoAb1yNj5+LAGRCeLgGRRRRRRRZjiI7PRRRZHm+lmkjj1YlvCIIIIIIIMxwBdHIIIIIIoQNVvCIIIIIIIMxwBdHIIIIIIoQNVvCIIIIIIIMxwBdHIIIIIIoQN++KwP8sVJPsAG.....IUjSD4pPfIH" ],
					"embed" : 1,
					"id" : "obj-1",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 6.0, 108.5, 581.0, 333.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen Shot 2019-03-20 at 01.52.59.png"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "Screen Shot 2019-03-20 at 01.52.59.png",
				"bootpath" : "~/Desktop",
				"patcherrelativepath" : "../../../../../Desktop",
				"type" : "PNG",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
