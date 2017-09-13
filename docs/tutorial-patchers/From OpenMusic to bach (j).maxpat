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
					"bubble" : 1,
					"bubblepoint" : 0.1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-33",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 147.0, 369.833313, 353.0, 55.0 ],
					"text" : "YET – there is one important caveat, and the fact that the levels of parenthesis look EXACTLY the same is due to..."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 13.0, 530.583374, 128.0, 21.0 ],
					"text" : "bach.help.searchtag"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-38",
					"linecount" : 2,
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.0, 458.0, 902.0, 36.0 ],
					"text" : "The difference between native and text output formats is something that you have to know when approaching bach. \nIf this doesn't sound familiar to you, have a look at the \"Hello World\" tutorial, or look for #out in the help center"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-32",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 147.0, 283.833313, 353.0, 98.0 ],
					"text" : "bach's data structure is configured in ALMOST exactly the same way. When you send the \"dump cents\" message (only dumping the cents information), and you translate it from native to text, you can directly see that the output list has the very same levels of parenthesis."
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
					"patching_rect" : [ 533.0, 232.0, 79.0, 19.0 ],
					"text" : "dump cents"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 637.571411, 393.0, 118.0, 21.0 ],
					"text" : "bach.portal @out t"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 120.0, 425.0, 536.571411, 19.0 ],
					"text" : "( ( 5300. ) ( 4700. ) ( 4200. ) ( 5000. ) ( 7700. ) ( 6500. ) ( 6400. ) ( 5800. 6600. ) ( 7700. ) )"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-34",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 407.5, 103.5, 332.0, 113.0 ],
					"text" : "OpenMusic relies on the Lisp lists, which allow nested representation of data thanks to levels of parentheses. For instance, here's the list of midicent of the CHORD-SEQ. Notice that we have a first external level of parenthesis, then one level of parentheses for each chord, and one number for each note."
				}

			}
, 			{
				"box" : 				{
					"data" : [ 9858, "png", "IBkSG0fBZn....PCIgDQRA..Bf....v8HX.....dmxpg....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6c+GeaUeeuG+s1hII.NfCERiAVBjvJgaiRIdzvOJrICERfGWbZGL1ZTdrRaQNq6BwYcjTyExdLGFoNztfCcbcBi4r6h4wM0IkZZKNsqNt0zatNsygVkdqRGNMNsH6FGhcwhDKO469d+CIaKoirjs0QR1Vud93QdDqy4H88q99864q9ny4y4HGFiwH...fn76jqq....XpGBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vhYkqq.vtXTe88akjTQEc4RxAkOkOkedS4CX+H.gYH17WnIIIszOz8KIIOdn7o7o7yWJefLANECy.r4uvaHovSNURIRkThzd1CkOkOke9P4CjoP.BSy0We8MoVGkOkOk+z+xGHShSwvLLs2d3+uiewaHoaixmxmxOOp7ArSDfvzbEUTQi72gmTJwqixmxmxelW4CjIwoXXFfc7Ut+w0xn7o7o7m4U9.YJNLFiIWWIlI4W9K+koba1yd1ipt5pyB0F.jOwgCG5+7+7+LWWMvLDbJFx.VxRtdII8u9u98hY4e7O98HIosrEIhKC.1MGN39u.rObJFxfFNff3+a..fo5H.gLfnOxAe7O98DSvAweTE...lJh.DxPRTf.Db...ltf.D...fEDfPFRhx4.xCA..LcAAHjADeNGDeNI...LUGAHjAEcfAj+A..X5DtQIYy9hewu33Z69ReouTFtl.f7MNb3f6wJv1P.B1L1AE.4JL+CrSbJF...fEDf.PdnKbgKjqqBoko60efoCH.Af7L80WeZ9ye9pu95KWWUlTltW+Altf.D.xyDLXPM3fCpfAClqqJSJS2q+.SWP.B...vBBP....VP.B...vBBP....VP.B...vBBPHmJfdy8tKssc85pqgx00E..fQMqbcEHe1w28mW20F1mjjZe1d02n7kmiqQ...gwQPHWIvQ0yDI3.IoF2vWUmfKqa..LEAAHjibhC9UUiRRpLUU0UJo8nu6Om6Lb..XpANEC4DAzwZN7QOnxldI8LqtXcu5aKO+vSomXkEkiqaXlogTf.AjJnvbcEYRZ5d8GX5GNBB4DCo20ujTkp7UWrjjt34bERACkSqUXloSbncoRcTfl27lul2bKPa9ersbcUZBY5d8GX5JBPHWH3YzoZQxUMOjVTjEERRdOjOEHWVuvLNGauqWKaMaTsD0x12V+x4r5yD0z85OvzYbJFx.5t6tS9Fb9ek9QR5NVxEGYaeGs2M1hzpePclt6Vue1nRhY9B5SO2ituDrhKRRRm4LmI6VelnltW+AllygwXL45JwLINb3HWWE.PdLlRG1ENBBY.u0a8VZAKXAIYKNu1+CcC58+R+J8YK5M0cu70IeRx8KeDsiGXwYoZIlwKnO83W+cqCFyBcquiucnkTvEzEewW7X9TuvER95yDrTloQ8OeUwEWbttJfYP3HHXyb3vg5pqtzBW3BS51c7cud8Lmd4pvsuEE9fn5RM2ygUoWY1nVh7EAN8Q0qt+uq5YvYqkbK2iVypWoR00ISe80mV3BWn5t6tUQEkctpZFqxbxT+ym4vgCNBBv1vQPHWYPupwsO54W0YUOMAG.aWgKZUp7MupIzyIXvfZvAGTACl8tycMVk4jo9C.6AAHjAjpjm5bG8UjyM5MpkrZ8bO7xRcxMBjEL732waR.ZGmNhIZYBfLONEC1LRRQ.jKwT5vtvQPHCXLSRwycT8PK+SniD0hV11ZVM+YWVVqtAjJm4LmQ27MeyiijschssYiWm7cjjhvNQ.BY.KXAKHAIo3Y0NVWzAG3RdbeNcw23hRYBMBjKj3wwo+1lMdc.P5i6jhYIGa2+UZKQc6fq9NNr1c0aQG9e8sycUJ..fw.GAgLf3Szpfc7Zpjn9oc9I+ZGWtt3eh9mekuu7tmWV2wO61kjz0eGOr77Y9i0RuL5VPtyDIgAGOaavyedoK4RzbroxD.YGjjh1LRRQ.jKwT5vtvWUMCHlDsZnN01+8tc8hRRxsZ8seB8MugOpd93dNKSR9F4Q2tdMeGPq5xxN0WfnYOIo340qT7MH07Qzk97eEs3W7E0ptD6oLwXijTD1IBPHCHlDsJP25WEY4dZ7Y0Go+F0cIIIWpwNNntlC9n5.+AurdtRKTG8UqR2551tjNh10q2gN7luybR8GPJcSRw.ZdNklWwKRWzrGR+NEboZgKrPasLAPlEIoXlVARgmVzodj6bQx+O9vRRpdeMpGbIEoq61JQe6u2Ijzbzp9TOm5ngJjjTKG5sTe4p5LPZatZdRZmM7M0O9TMpxV77ztNF+XlCLcBGAgLfXRzpy+t5ckjzMHErac126rR5o0Jur2Wc286KUzRTnuwOPc73KUWhjt363OWO8xdA8rCFTmq6tU16lcKxuMjN+4Ouzu6kn2+8NmjRmjTbHcr8+7ZGdk74cCZ36Ynmsa+p6turX1tISYBfrCRRQaFIoH.xkXJcXW3HHjADehV8Ne2+F8Q+zurt8m70zA1zBzlK910G5acb8YW4UHofZ+elGPWzV+15Sr34Ho2Qau3OpdwUuS81+SOhRRdcAj1N99ebcea5fwsz+.I8ukjDFL1u4u0jK77Z+elaPa5PRO9+v+f55urd44Wc.s7YkNkIFOHIEgsx.akjLc0UWwszdL03RFIYproNMlda03RxTYidMFiw3sFWlJZpGiwXLsWmmvaWy9yx0bj2Y.uF2J73xX+28MFiiMFeMUiwUTaq6p95i4X9pjL05qSS8k41zdnIeYhwOlRG1IRRwrhqTOQidUERZ6qYwp7ulz96sSsxS7U0Z21gz79XqUGt9utNvNVuJ4Q2iTEMnJKkuI.xvBERILsAuo+HcQyd1ZNyI1asQGauqWKaMaTQcCAU6aqe4w3EeN5pbJoPCo+i92m9qexcoic1gF6xbY2wj4c..xf3TLjAj3Ds5CnM+qdKcCOek5ubC2k1yFjdrm7o0xm8anMTxKJuR5gkzi+O7szl9DqTue2cq2OKWusie1dwzHA+sIXB.256bv+bsjBdXELXvQ+IHOnO8bO59rr0RWjjRvX9fcpS5U54ctzvOtkMpW6dtWsvaJwk4qV6+U8o9C2JIoHvTHjjh1LRRQ.jKwT5vtvQPHCXhmnUCo8+Y7nq54+mjqqHiUsRJtS1gjJnO83W+cqXSsP2563aGZIED9HOM5u4BmWuxCcC5YNhzxVljOeR68G815dulwNkaY7m8fjTD1IBPHCH02M3Bp.ABoBlagZNQ5AtKWyVe6yOG8o9vEkUpiiEtS1gDagptNaSe78+cUOCNasja4dzZV8JUQRpuSeZMqENG0vJVm9ve+CqRKR5O6YpVOyZ1h13WuSU3e2SqkbiKUiiajhL9CXJDBPHKquie.8G67gijnWNUss0jJeUEqq61JQsezSIspba.B.ikBWzpT4adUwsz.5eYwKVxaGZdW2UqBhLixRV8ekpy0VzfgFRA7GP+GY6JK.RabULjUEPM9LObTYAtWsAO6S8IoBKdIR+ldxcUMXatvEtPttJjc4TZdELWcQJf5q2guFEFP8zhz6EZt5ldjR0kmSqf.Xxf.DxlFpW0S+wsLucqdGRZVye9R+5d4Vq7zb80WeZ9ye9pu9xW9kzXr9MWnPslFaP2y0dU5NK+IzxGGmdA.L0BmhgroYMeMxchdmNk75Uph6SKYVRG94WiN0s3UyIYOeLkWvfA0fCNnBFLeHTugzQ26V0N8J4MpeyEBFZHIIs7G7gR4yOPf.REPzC.SEwQPHqpP8m7kqM7e50qTY0HeO4xzAdpUn6d6dz97r7ba0CXBY.8S9et8QBLPRprJpQ2y0m5Ov+DGZWpTGEn4Mu4q4M2Bzl+GaKyUMAvjBAHjkUzJKW85sQUQYNkZbiZYW8h09zlTmCrasbN7AXZlYOuv+ek0WubKWZqO+SnUdkI+.SNwtiLBfbENECY.i8cCtfx2OrY0xa5U++98uOsspWml+BtNcyq5V0E0W2p6rZsLVI9ms2zS93clwLQ63TY22+iiqmrwkqK+ZuAcMqd95c6ta0cxlUYhdGYD.4LbmTzlwcRQ.jKwT5vtvQPHCv5cCtf50d7qW+kG7wTy99a0xhjohAOyQ0SdyehQt6z8jesiqM8wFRuzCcy5YOhzi8xsp+1GXoYvZZp9Y6cxKe8NiWd266fcpcd82td9nVzS+s7oO+JurwX6S8cjQL4wcRQXmH.gL.K2M355PZ2GTRttVckWwkphJJxcPwEtVUm25zAc9nRR54+SdUUdOOjN9QB+zd4GqI82YdNckYf53INztzmOpyCr6p95IttmlxWuy3ke79Nf1cowFbfjzUtvqVKbLusIN12QFAvTKDfPVvYOwONbld2xVkyqZqRxoZnyipGZQyQEdCkH2RJ7Ykc6568q+yzZcK039j7T+eVFI3fis20qRh67.SRhgIiAi7+CeU61Xm8qGbQI+pXHw2QFAvTMDfPFP7IZkOu+z31Bu5U1+Qzcr9kIo4pRVsz9NT307Ca680N1QWpqcD9wi7ysqcIKkjX4aIq2vx2deeKetmVpkmUq6q9iT40Ts9cC89p6ty1+PkCfLARRQaFIoH.xkXJcXW3HHjAjnDT6cN12VMz3OR+VMGszO58oO4CrRcIRRu2Q0mYYeBE4.Hnpes50O5SrtvIw0p2od6+oGQi8ORtSBYojDK+JY8xbI64TemWuTw2fz24sTI+jukl2m7ypkYqCXwDAIoHrSDfPFPhRPsE9.eNcKOvmyx1d1N92GI3.IOZM2wx0wG9gy9x0BV3Bk8dinM6ljX1Ux5MU8dpP1JYOmJ6OowFTna9CqUduejbcUA.1HBPHmZH09Wu9QdTkM8TZ4W4hzeuu1zC+ued8e4NuKaN3fvltkjX80WeZgKbgp6t6VEUzTm7cmj8LrT+at..lNh.Dx.F2In149gZauP36j8K6w1q9KVwEENoDureOcK2hjBdVY24nX1hclrdm4LmQCN3f5zm9zSc9QPh6Hf.XFNRRQaFIoH.xkXJcXW3HHjAjxDTan2Quze5GUO6QjV8SWudoOuqYH+LOmYRVuojI7H2Q.wTPjjhvNQ.BY.IKA0F5rGUOYw2pdAIUcS9zlW8MlcqbYHYij0apUh+wcDP.LyFAHj0DTG6.OuJ4g2pTYUo1eomTqr3YFG2fzMY8BFHfTgENs6nnLcKYOA.lHH.gLfXSPsfxWKMnmYcaQGQ2t14W6H5Q9XKVR8MsMADiQZjrdu267NZVWSg5+0c+Y0G5qe.8wFieeex2t6DB.LU.IonMijTD.4RLkNrKbDDx.lRkLcYZS5j0675Ut6aPW5teKcQOWk5Rp5E08dMI9Vv2TxjTDXJHRRQXmH.gLfoVISWl1jMY8FRWSAR676eTUZWGRuvG8FTMs2udhUN12ZnxuZWA.xsH.Aj1l3Iq2P5n6cqZmdk75cCg+ovVRACMTLaSf.AjJHSbujD..oBAHjAPxzkJmW+fWd6iDXfjzpersoOxk79p6tCpNZ4UzWbcOiNRj08I27qHIZWA.xlHIEsYjjh.HWhozgcgifPFPWc0UttJLMv4zNKd45Cz5ORW5yUsV5ddQs7gRTBOJI8GIouOIoHPJPRJB6DAHjAPhzMdboZINkzkOeM6AOn9R+82k9xOwsogRzldS2mtnS9+QKZQKZJ0uli..yjwoXvl4vgCNDeiGAOo11bWp1ZTKp5evOTG+O7ioXusK4Qs26t0MNa98M.HUX9GXm3HHfbf.Z22erAGHIMmK0odoNaSerDdISRvA..YSDf.xIFLx+6zojWuRM1Y+5AWTgRheeC..lJ32IWWAP9nB0Cr4pkjzme+cp5c6VKX9b+N..XpDBP.4DKY0+UpNWRJzPJf+.5+HWWg..PLH.AjiLf5oEo2Kzb0M8HkpKOWWc..PL3pXvlQVDO9c7W+.JzssVsxqjTgAvNv7OvNQ.B1L1AE.4JL+CrSbJF...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEDf....rf.D...fEyJWWAlowgCGxgCG45pA.xCwbOvN4vXLlbck.1Ai5queqjjJpnKWRY6IJn7o7o7yckOf8iifvLDa9KzjjjV5G59kjjGOT9T9T94KkOPl.4fvL.a9K7FRJ7jSkThTIkHsm8P4S4S4mOT9.YJDfvzb80WeSp0Q4S4S4O8u7Axj3TLLCS6sG9+63W7FR51n7o7o7yiJe.6DAHLMWQEUzH+c3IkR75n7o7o7m4U9.YRbJFlAXGek6ebsLJeJeJ+YdkOPlBWliyXj6uLqF9btledYlQ4S4yk4HlYg.DfsvgCGhgR..ybvoX....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vhYkqq.XlCGN3Wvto63GbK.LLBP.1B9fko+H.O.DMNEC...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....V3vvuxN.485qu9jjTQEc4QVB+vMAjuieMGAxys4uvaHIok9gteII4wCemA.voX.HuVzAGTRIRkThzd1CG8..P.B.4sF9zJLQWG.xOvoX..RRp81C++c7KdCIca4z5B.x8H.Af7TEUTQi72gCJHwqC.4m3TL.jGaGek6OAKaM4fZB.lpIstLGc3fjYB..XpF63NXPZeJF5pqtR6JA...rGEWbw1xqCmhA...XAAH....KH.A...XAAH....KH.A...XQF+FkjckMk...H6c0ClUtSJxunz...our48eHNEC...vBBP....VjyBPnutNqFJIONWYn.mUmMv3cqCnS203diyflX0ioJs0A5pKEbbtsC0WWpuw6FmQQac1xzy8Emd1VOUzzy9eq0iIx3goZxIAHb12baZ9WcsJPhdbvSpcTd4p7Q925U4a60GYa0PmV6Z8kJGNbD9eqXsZ2G9jwV.C0k16lFdaVg10gha8R53GXai7Zr1m5.puHKef2tNcUyaS5jobV8gzqW97zhekedbKOnNzNJWqO55rjN4quCs90G06qMsIsoxWu1wqOZcKvIOjV+Jh79pzMo2rqXqDi45C915Au54o8d7TuCR7s8i9hebss0uVssCbhQVTem3P5ohpsdEqea5ncE2P8zns9m+JWsl61dyTVmUfioGZ9Ws9YCHIETGdWaRqOpwHqe8kqW+jwVuFqxb7td6tsNU8+AO4qqxid8kuIsoMUdbi8SQacRV+jqsVRJndy89Tit+lCGZaiLl0d5KFq15zYewyd7CL5qoCGpzm50S7jzIXbexpSiVjYf15.mP6p7nmaa8w0Vlr9hvR2w8wHUyEGoc3U215Gsct7cniG2K5jsNMY6+S09Z1wbwiY+eBleXbOdXpHSZPRlt5pqj9OKEw.dMkIYppY+I9w82toLIib5x31sai6xJyTVEMX5OpmuGWdL02b6Feda1TYYxH4zzZuirAlF7HijKSCs6yzTMtMRxTS6irAF+MUkQRFO00pwWq0YjjwYUMGYs8Zp0kLppVS568dZsJiTYl16O1k6uoJMRxHW0Z5Mpk6sNOFImFmNi7OIijLtptsHuuaK766xpw3si1LU4RFIOFeCXFWquiF7XjpvzYxpzw2VO5JL06IR8ol1GYosWsSibUooo17ZZuoZMtjLRUY7G0yKcZqC0SyFIYp0abMhwHjoQOxHOMXB+Vs+v8OJx3C2tMk4xsoAei9Zj792Tu9LQacp5+62aj5wvq2U30Km0DYbTpZqS95mbs0FSaU6xHISE00poCesaZnlJLUTm2ganR69hj2VO41Wb31R4tFS6c3yzVS0Z7TQcwr+3vsYIZbeJ2WLSzVGpCSkRFoxLMzlOiu1axTsGOlF5XjBME8E1v393kp4hMFSqU4zH4zTWydMdat1viqcW+HieRu5zjq+OU6qk1yEmh9+3meX7MdX7aR84tS1xJaWQCOHuJSOiwiMCztwkjoFuCXFOB4K7fppaKxt+9axHISkMM7Gi0uoN2xH2COoWulZbIi7znITjsnyFqvH4xz1HSvTqQRlF8GxjPg5zTojwUsdic48zb3AVRFUVcljMbHbY5zzTmgKiNp2sQxiw6n6YE98QjOfIUq2DpCiGIi65hqNEEKs0QzQiQBpQxTVsiNQYnA52DcKfu5bGS6jczV2bkg+Pv3qSCq+H8uMz4vuBg+PIKs8iHUkYpqSYx15gEe+u02FsZbJYbWuuXqCiUacJ6KlDs0QlnzUMsMVOizruH0s0S78EGdx6JSd.blwdbeJ6+y.s08zb3OnrNeiw7doruH8G2aQJmKteSckIipdz1Nu05JpfZS+5zjdt3njp80lnyEmx9+DL+PpFOLQLyM.gHMbUzXmI9wFyDN.gdZN7N4MGokObzakYZOpmt2ZKyH4NbGd+ge8qnoQKyPc1XjH.G4S9LUkjAcC3K7f1lhYPajnccUko9ZJyHm0N1AHDIxb2Q8MwpqrvG0gQeNQ91YdZzDJkqOr1pwkQp5D7MkLIts1XLF+ME9ChpsQSsti6aREG+wO4tMzVO7ianyD2e2VUNi6nwD4CkpYLlPHUkYJqSYv15npikojEfQjOjyY0iLgRpZqSYegYh2V2aaUGdbdjJQHKyull8Eiq15I39hC303Vx3t9NhTmGiOXYLG2m55j82VOfoA2g+.j9CWoMwWqSYeQZOtOAFuAH3ppHe659M0VlLpxlsw5zjYt3XaWR59ZS34hGe8+wO+PpFOLQjMCPH6lCBAdW81R55tl4m3GKIEJjjj1nyUo0W91zAN5IsjjWCc1SnCenCoWcWaRW0cucUQCdUoWY30cgyclneYjjzUrnaRR90EBIEnyerZQR23UMZYNqEbcpLI8iOg+HK4pzJ7H0xw9EI77V14w9gRpR4r3QuMRb789DZCs3TMevmQqZdQpmiQyvg29ipFUk5Y+zKejkMX+Rx0MoBiZ6l87jza2oBLNVujzM45QjzgzoRzoGOQs05rZGqYMxqqZ0KU98pY6OAOuQbZ8JOyKHoaUev4FdI1Qa8rVv0nxjzu72LfrJf9Is3UtV6sqhhZoCdNoV1nSU5ZKW63UOrNaTMzopLGO0oLSa8nRT+eLO8isG8v6Qpt8+DJxv5T1Vmp0G984Dqs9T+jiHImp05BeduKn.GZEqeW5DQ8dNc5KjFOs0Sv8EG3Bxujt328aqxWgCUPAEHGNVqd0ic1ndVIebeppS1eacHct.Rx6g01KuT4nfBTANbnMs62bj2yopuvNF2aQJmKtP8mVSiRsrUsr4VpVaoySa3TUoNqpTarNMwmKNZoZesIybwim9+3meH4iGl5JqFfPfScT0hbpO70VXBerjjJ7lTMs1pZs4sokqCnG9VWpt2c7lwLvbnKzo9lu1qol9Fufjjd2e4ohYhIIoBJXz+d9KdQgWVTqevPQ+DB2q5+ceuHOdV55VYYRs0kRT2Yn.9kbtnQF.E7jupb9n6SU072SkVjTnA6WRRyMAO2fm7U0cucup51dRsn3VmyK6RhdK0utQIMuYOxcypTs9vZQ8DvZnIIps9n65wzV75Vs2X4QsyPAVdtJ3o0NJcwZqdKSM6uJsn31WLsZqm0UnaRRG5mbJqk6P8nSzxnOmvJTOz9ZSs1Zy5yU5Eqsrt6VWUAOkhKu3RQ+apWuc2VOxqTR5+CqK8BkrQoJZRtuw4XYsopsNoqeB1VWfJTRd01OzGT95oW42WSx491nVVY6NRhjYO8EIusdhsuX31do8rwug9300o5u2NTcUbJstRtGc3HSRLdF2Od5+sy15YKIoF0.21eq5o+dU6MTodgMbWpxW+zQdcSUeQXo639XLNlKNvuoaII4z04TisHIuuiNo+XG.jd0oIV+ezR09ZoybwRodewXleHYiGlBKGcYNZ4XBD0eWnV9cdm5NK8A0l28OUMWkK0xV9aT6Q8sVlyhVs14t2s9WNrQ9asFsusTldt2H7NRgFLxFE0moDNJyvKpfBBOTZ1WbTc0Q11U76+AmDuWBn+4GacRRZqO6ioRKsTsrMzhj2Mn4thx0wh4aXdVsqO45jJqN8Wrphr7J48+66DUTxyQWaYRp+AGo0IUqO7admon9FYqCbT4YiMJo8o+50uVUZo2udzVB+sAWQ46czLU9rGUqetKVaQUIe8+MToQEot8zVOjFPRyKQAlnYkvfrJd4qR24cVp9TOwNU+dqWRaWG7mFdZxTUli29eassdDIu+WR536cKZqxoZ9oVcLSFkp15Ts9gqOSj15PCFPRNUqG7IzMdkEohuwUq+604Vpk8q+8HCPRm9hgkx15IfBu1OrbJIOM7x5gV4hTgEsD8oeppkjW8u8KCLtG2mr5TlnsdPIIW0pp9z2otxBKRq7gpT05R5EZ3+sBpT2WXWi6iq0L4yE22ap64V2fbWmW8SO7OU9aqd4R6Q28h2nNQvLUcZ7JU6qM4mKdb0+aY9gjMdXpqrZ.BEdc2rbJu5m8qGHgONQJ9ZmWReMK9NuW4VR+zS7ajjz0dykHoSoeaTytD5c8KoaUevBklyRWobKolZezCqVP++X0njVwhWvvKQm5XMJccefD9ATEL64I48zpWIIMWcOauY0TyMql17FzS+zaV03woj7n5q9ynqMpWfS+56TawqTsa6ONtHdmqVzJjTacF0Xt.5W2njyUeyph094v..fAsjDQAQknTt9QpXR5JzUUn0C2lk154d85q1TSpolaRadCaPO8S+4UENkjqpzN+u4Jb8anSpm5ptUsuxpS8e3mQ2XbgoaKs0CcAcJIc6ejqwZC8rluVjKoDdTMF9800DdhjeaegOpMopLSccJCzVGwX2+GQeuo13itO4r5u5Hmxrgkp15TsdIMgaqu1a91kjWEooM7a6K5hSTMO766IXew3qsdhrunjJ7JkSIclycgQ2n4TjbM7emxw8otNY+s0EnqXAR5bQGTTAgOpBW670rTp6KR+w8oV7yEG3c94xqjJ6dCe34KdUeJ0XaUKo2VuWH6pNMA6+iHU6qM4mKdb1+G+7CIa7vTYY2jknWSMNkwSCcLFO1XLg50zQm9MCDJjo+NayTgyvYjbGCmCJg7aZq01M8z+.lPCzqo0Z8DIiRGNQWBmUqxcsF+gLldZudijLtqy2HEQ3LLuLSSc1uwzuOS0thOCSC+ZTQSwe4.FQjrXswwHqX8Ua3jTL1zQoGS0QdujnW0AhjUyU1fWiwLfo0ZJKlxHUq2XhbIGUV8lDmFLInsN1Zfot3xH8vW0Bx3tllLs2ValVasUSqs1to2QJxzusdfNpObhOlvr8yX7Uu6nxJZiwXBY72QGld5e.y.C32zXUgaGp2xkC1XWlorNkQZqSd+ezs20mvLYOUs0otuXB2VGxmwijQdp0zY+gLCzS6lJcFc15m98EotsdhuuXyU5zHUloQe8XBEpWSSUWVRdeacb+3sNYms082d3jsqh5a2LfIjoyVqM1LmOk8Eo+3dKRwbwg5rAijLtppASOCDxDp+NM0WgyXSVuztNMYlKNU6qkdyEOd5+ie9gTMdXhXh+4toQYksqn9atRiTYiL.J9Ga5uMihboGIIibUgoU+QMgYjLqM5swSMMGyD0g72rwcTq2UUMF2UTPOl573LpWiJLQco6G4xdwynAkXQjrNthlR3Z8VaYwkErlQxVVWUO1WSuczXUw79plV8O9WejKKtnuGDDOKs0wHbl5VVTY6q2ZcGaegBes+F8kEU50V2uoNWQk0yIrZ0lwkjo51FdJidM0DS8woo5l7E2SJ48uod8Yf15T1+2uod2wELbbRUacxW+jos1XFnilF8R2Uxnxp1L5m+aG8EIusdRsuXH+lZ8D6X1F7NV8UVG2mp5T3hv9aq81PkwTldpssXtZFRdegwXGi6iuNlz4hMFiuFqNt4GJKt15zqNMo5+S09Z1vbwIs+2x7CiiwCS.ynCPXjIBG4xXJ9GaL82aOF+98a72Shu7aBMP+ld6wuwue+ldGXrlMsei+N6bLeMLFioW+9Mc5umX+Vf8zrwYb63l3mb3cvqpU63JacTg5uGSmc52z6Xb0vj30G4Ryoxlrb4QEKqs01hIYac3c9caFqK86gE9lOkaiug+lKCzqoG+9M982iYr59Gqxbhr9oks0iw5mrs0w9ZZ8SSrq9hD1Vml6K1q+vyQz+jrCHU6KlIZqGtL6YrpzIouXXo639nkp4hGoNM7X.6rNMEet3D2+ac9gw63gwqY3AHXLlPcXpspFh5PYF2iyg52a8lpaH9uEzXrs9ZvTURtY4j0LfWSUUV236lvwTn1Zu0Wioow40Eba0Uqk6Zk4DzVm0LsbeQyzy15ohlV1+mf4GlHiGFOxlAH3HRANo3vgC0UWckzso3hKVoQQ...fHxletK+bOC...KH.A...XAAH....KH.A...XAAH....KR7OAV1LGNbjMJF...XSx3AHjpKGC...L0CmhA...XAAH....KH.A...XAAH....KH.A...XQZ+i0D...lZwN9wZJstLG4WoQfYF5qu9jjTQEc4QVBA+CjuKqbiRB.Scs4uvaHIok9gteII4wCA9C.xAAf7ZQGbPIkHURIR6YObzC..AH.j2Z3SqvDcc.H+.mhA.HIo1aO7+2wu3MjzskSqK.H2i.D.xSUTQEMxeGNnfDuN.jehSw.Pdrc7Ut+Drr0jCpI.Xplz59f..lYfKyQ.DOBP....VvoX....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vBBP....VP.B...vh++LrNV4iDPQJ0.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-25",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 42.0, 518.0, 236.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 14.01.44.png"
				}

			}
, 			{
				"box" : 				{
					"clefs" : "FG",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-24",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 533.0, 260.0, 385.0, 121.833328 ],
					"pitcheditrange" : "null",
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : 0.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081753600, 93, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081753600, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081630720, 88, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082740736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 113, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083881472, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 36, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084489728, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080459264, 113, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084581888, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085891584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080786944, 119, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084694528, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085865984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081589760, 78, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084889088, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085712384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080786944, 29, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080786944, 29, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085001728, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086198784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 61, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
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
					"text" : "linksections 1 1 j \"From OpenMusic to bach\""
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
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 548.828552, 495.0, 229.171448, 36.0 ],
					"text" : "... is due to WHAT??? \nWhat is the important caveat?!?!",
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
					"text" : "- parentheses"
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
					"text" : "From OpenMusic to bach (j)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-19",
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
					"id" : "obj-21",
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
					"id" : "obj-22",
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
					"id" : "obj-27",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 559.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (i)",
					"varname" : "messageA"
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
					"id" : "obj-36",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 509.0, 151.0, 20.0 ],
					"text" : "Back to section (i)",
					"varname" : "textbuttonA"
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
					"id" : "obj-40",
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
					"id" : "obj-41",
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
					"id" : "obj-43",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 778.0, 559.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (k)",
					"varname" : "messageB"
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
					"id" : "obj-46",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 778.0, 509.0, 151.0, 20.0 ],
					"text" : "Continue to section (k)",
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
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-22", 0 ]
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
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-30", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-44", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-46", 0 ]
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
 ],
		"dependency_cache" : [ 			{
				"name" : "linksections.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/docs/tutorial-patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.help.searchtag.maxpat",
				"bootpath" : "/Applications/Max 6.1/packages/bach/help",
				"patcherrelativepath" : "../../help",
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
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
