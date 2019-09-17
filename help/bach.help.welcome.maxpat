{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 549.0, 79.0, 617.0, 539.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 13.0,
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
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 225.0, -65.5, 160.0, 23.0 ],
					"text" : "bubble 1, textcolor 0 0 0 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 362.0, -129.0, 40.0, 23.0 ],
					"text" : "defer"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 1.0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-4",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 354.0, 393.0, 40.0 ],
					"text" : "You might want to edit a certain page and copy some content: don't hesitate to open the patch separately and do that!"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.78,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 404.0, 447.0, 54.0 ],
					"text" : "You will often find references of tags to be searched, either directly in the help text (marked with a #, and clickable), or in the \"Also search for\" zone. Don't hesitate to click on them for more information!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 555.5, -73.0, 160.0, 23.0 ],
					"text" : "bubble 0, textcolor 0 0 0 0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 362.0, -101.0, 44.0, 23.0 ],
					"text" : "sel all"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 362.0, -155.0, 156.0, 22.0 ],
					"text" : "r bach.help.sendtobpatcher"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.0,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 210.0, 5.0, 245.0, 40.0 ],
					"text" : "Tutorials are a very good way to start!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 154.5, 141.0, 215.0, 23.0 ],
					"text" : "Welcome to the Help Center of",
					"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 21.5, 59.0, 371.0, 50.0 ],
					"text" : "Use + to jointly search multiple tags.\nUse spaces to search either one of the tags.\nExamples: \"keys\", \"marker+role\", \"measureinfo\", \"undo redo\"...",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"data" : [ 7870, "", "IBkSG0fBZn....PCIgDQRA..A7C...fKHX....fWa4QH....DLmPIQEBHf.B7g.YHB..dTWRDEDU3wY6ctGebUUsG+2u84LyjGzzljlLORnQJEwKHdUQQP8B9DDtvUAUdHuAgJklL8AutfRHf7nTZSlYRKFEnBHnhxUTPdHBHxU4wUDn1BHVf1RyL4Qe.8Ux73r+c+ijVSZSayyBUlue9jO4ybN68ZuNm4bVyZu2q8ZiXwieyHOuufFik3ll6BWXkiT4DNXj6HRkU0Q3vgmzngd8uZDtxpZNRkU0QjHQ1+2s0k7riwHww+tsRjmcOPfRJzZMiXAITNHpvyym6nfZ8ubPpIzy8Gm72edOLFYf261JQd18.oFc9tlLWO+KsFUj2+hgTOuSQlM+8m2CyH2Kf7jm7jm8.Iuwu7jm779Rxa7KO4IOuuj7F+xyXIF.vwHY6fw1meYuswXIi0xOO6DxOaT4YTiJqbRS1gYOFHdDfX+oXIhJG.6.BufwfmnqLc86V6ZW65GJxcuqXu2WO58kEvgAf8GDkQQ+..BnaPrFH72I0ySwmp0NZcwCUcOTnP0Xj4yCfOiDNHPLQJ5BnMIfkCo+OR9+VTIE8TKaYKK8PU9..UErpOujNRA7o.Q0TLfnRCvNIzR.welN7wZs0VW0vQ94YnQdie4YXiT.B.L4Rm7361W2WCnWs85L1JEvqIfWl.9gvjDz4JwoEvsfViTQjqMYmIGLwWpajfQZHm7tXR5CPqmBul.eEArY.P.UB.h.fSAfmsHPjfQtKKsyrs1ZqycUCTQE0DxmIaCP7bAfifVO.dEB7RBHCIKmBG.L7X..1z5650hDLxbR1dxaavdeJTnp+jzZSHfOk.5hfuBfVp.5FfEQgpEvoSvyWYwlhTYj4jrijWyfU94Y3QdieCRBFL393Zc+Orz9gIXYhZ8xpWv3y7fISlbMuaqeua.Y5MFNb3I0sW5GFj+aPJNEusV6r0k.z+PnJTnPU.q6QRfq.FrvHAi7kRmK8Ysl0rlMrijejfQVH.OO.sDI62KctzO9NxqwHQhTtxwCmv9eCxSkxYeBGN7WNUpTadGI+Pgp9HL1b2A.mjjdPYXyYxz8eZ.ZCSnPg1ei07MHXc.7ViDLxw5qaemyJdmU716H4633r9pBU0wHoeiHWLfNI5hGKYxV2tmWhDIR4vSeYAdUj7piDLxdmr8jm+NR14YjSdie6BBEJzAPKuDBdBxnwwdGBKBBZHPNrhPgBcAs0VaOz6xp5ta7b7bpR.+b.3Qg+8V6H4Nr6l85E1cENb3eEs75.Xz.tAJdJSYJe0ApajgBU0QCgySROm+z9NpclQF.fd+AneU0UW8C6kU2OA9hxybZ.3GNPkOXvp9bFq9shxOj4zR0Qq20NQ711ZqsWA.WSEUTyOxGyMe.dJYCjsvCFG7+0yimO6.UGuL3ySpag.yKUGIubfcbL01q9+ylzjlzijKs28CvyKTEU8Ts0Yq24N65NOCexOgG6DhDLxERwmljmI.F2.VHhZnk2UnPgpY2q18tGDPRJGLnE.XrFuCevNNaoRkZyIaO4LDv7.3Qs40u4qZ.aCqpE.v.FcWY3qurpUsptnz2q2OdbCTYpnhZBYftKPTDj9Fo5XU6LCe8iN6bEskr8V+VRXQf7qjpxT0M.Zu..LFr.B9CS1QxKE6DCe8kUtxUtNi3E..KotDj2AkwLxa7aGP3JBeU.nYBVxtprjrTJdRi8Z06UPVRF.jeRXzIMXFasskTs25kBg+pHtnscMvFJTnJH4QKnk0ZGs9LCUY6KsuWQRcAhpFny6xbWIAiHfqNUGo90CU4C.jSYpSPsIhqbxkN4scIhZAfARq13mWxPU1qpiU82DzyQxObnPg1ugi9kmcM4M9M.DIXjSjFV+PpRBuObQ9q6NUpTO+vrxdB1qlftJG+188DN4bl.jdJ.NnmTg9xFc2nGAsX.Byl8t78NBANSIsJKxciCScGc1YmaTBMCw11j+rUOPkQf2xpV0p5ZX1DOM.fCb1mgqNlmcN4codanhJpXufvMLTiNMB9FiMZz6Ig..jbP2cwABKs+diLqATeM.7eCfb..st5V+G.3vGtx0O8uefnXJka6ZSi8KAhhnP71au8MMrUd.zVGIu1CFG7M973421tz1iSEV6SMbkMsHIL.RZW1yi7L7XLy3242R3hx81Yb16MulM0PCvNV0Ni13y36yCfg5u1tQO58qFCTGmxKu7hJrvByMB7fXTGI5PBOmbNuvHQNs2d6aJbkQdNBdzACFr51au8kOXq6TlxTBr10t1.NNiqH+J23rvNNZXoh7.ovLA.D19m6jQeF.BOxGYjn6agAdxNDAHrNtqc3JWQlk.PRiUAI966YT0324zT0eXQuugwfC2KC+.rH+9asnHq4riy+rwha9VmwPO3S2sivGbn50mfh0d6s+liFMe4kW93763+3H4wJoCB.k5k0KcjfQ9G.3mmr8j2NFfWp28hb.vp8OA+qEqdjJK9l..txMD.V91d1pKq5p7b8NbR9ojv9QfJEXIaZCatjBbKrDvbEI.vdc1h.PD+FBTNA2tmuE3jIfLF6Xtm5ivr5RdidiwLpX76TiUU09.tZii22xwkAbH.6YBufjpxJ7Q77vocNIhbp2VsI+MiFs4XFDsNDqwut3wU70f1G4McjPQNSY0kSxOH..Y+d9ex.3nBWY3it3RJ9zGtqxfQIHD17xV1x1ttUNLjT2..Vq0WeObMiulIjMP1q1C1ymzD..B.qRDqARIgveCTqABqABqEFrZYUJ3hWozRKss0s52tcPN.ios1KIjijint7lm87YDa76rle3+CR7S76SSx0AvwwBiAvz66sR.VqPNGtW4xhVtvDQ9SKn126FTvtAbejbcm6MA20c8URKr3RJdViTCQSYJSIvlV+l9AP3r1FCdaGj7at4Mt4+..V3HoMGoHhBNfC3.bd4W9kGQ4HPBUB.gbc5dKGq5pqtrLYx9Pj7PfzCAna10y8urxUuxNQuiK3NizoSWR.eELvSlmP2jzkDENRz67rmOinY68rZp5OIc3862mljOeB97I3eG8mqfe+Hjmi9DiVJ+XAqbkqbcxQeSHrzcPQ7jzias1iNUGotvQAOvLaZ8a5GSxyZPWCgu5HrMGgPO.TwpW8pKcjJIILE.XcbTpsbLaV6URxCQ.WapNRdLIaO48uxUuxTXPX3aWCWA.nmGm7HWV4YOYF1d9c9sDtnza1tHe9w3ccDbcD74J35B3XzV87yJ.qEfaI+dHi+QGUeriToR87UTQEGpO56XgvgAhIJnM.gWghOYpNS8hiVsUjJib9f3jGJ0QR910kZrC1SxJv0QNeT.Lrm3fZFeMSHCy9wgzq1ZqISA.DLXvhg3oJnUEoivMjZHOJD.EUTQtdYr9Aw1MlaD5Y.3YZr1uB.9iCWcG.H7DC+wogSSP+7Tcj5QGIxJO69YXa7aSahGa.e7.cLBNaw3mSOF+bcDLFA.AYIx4Y.gf0pzl.ZIih5+XFc1YmaD.+rd+aLgZpolBx1U1nCip9WF0UlgFB.fFdZXDX7KSfLGCgoDPcen2U.gTfffdSDhOvNXYisKIaVLEGxBf19z1uG8dXibx.fynhJp355864gGFy4Bhy0fQVH+jm2cXX2sWGwiwX.LFAGCfiAv3zigOe97P.edHfOK74yBetVXb.bL7WNuyXzYVQ2BgBEplpprpCMXvfetPgB8Iqt5pKazT9ikjYSYN.P7gFJ0QRcKiVzXkNMzfmRnPgFVCiQM0TSAD7JjTZGqyVClYiISu6+EXX2CAGXqC.PCvRJq81ae4j3NHYU9nuqX31FgCGdRj3LDzhas8VG1wyWdd2ig+X9QTNg.YOcokld5tqiiEtNB98YQ.+V35ZgwQfTK2oPuKdzPoKu7xGWjfQtvvAC+mMxrDQ8zNv4ILx7bdY8VRjJiLmpqt52yOf1FGyDFxUh3R6cQ1+tFBzQRcKomxXc9kSZhSJ7PUFY5J2B.4AHfq4s57sd8sb7.ABztjVkj9DCvxFaWR3JqJJDOdI0JHGPCnVZubHrbPdYQBE4LGpsQEUTwdQq4t.vdQgYgQkwhLO6tYXa7iz97.8LLd8c9I2xmMrGuBI.fvxcM3qcce8UmZ6kzPiHUF4KFvIvyfdV2sGF.1q9oWfgAwk3kw6Gi2qmobcwqAgAcHWHnqMU6ohOVpRCVHoOZwrDkWVmbOUvfUeHCl5Uy3qYBgqrpEQhyAP2WacjbN887qXEqnaBb2jrrt828fd4mUc0UWV3fQlOIZBFMM.rXHTz.U11ZqsNIwIKo0Aweb3JqJJFjuKDL3deftF+OB.9rP5FR1QxGavpi448VLrM94yXtEI0pTOSpADfDgmkvZIxliHSVCr43u1Kq2m6J+5c9RiTkMTkgNMA8aAwArqJKIOwPgB8YGos4XI8lwdSrqJmjVk0ZOiTsm56taPs10zyuo43430pq04HA.bfd1vUV0hBEp5Ce.7XigCGdRQpLx2IafbuDINK.cWFeluEF.ulL9MyQ.uH.O+HAi7vgqH7QVy3qY67RtrxJqjfAq9PBGrpq1lQuJAmoDlYx1Rd6jnKBr2UWY0GTMiulITYkSZxnO+Ncqs25yBq9RRZIjnoHUF4YpphpNiHQhr2XaduXxkN4wGthve1vUV0BcfcwD3SKfqMYGI+uGv6ObjGfxJePNOlyvdBOtknstpyNVnizS7F87zWvyAE5YAnGAfYc4xg+nii9gW5wstGbzPQiTYjunnVz.E096Pr3iCfmbzn8GqHYGI+tgCF9cn3E.9OSNBBJGDdUA8yrvdKczYGiBgQ8nExAfPJvd8VctxWORjHeJjS0ChKvHbVc6O8FiTYjU.x0I.CfBRK2WP.A8OHwYkrsj29NR5qZUqZsUTQMGsKy0HIOYZ3QksfbaLbfHKmjuM5owKEj6Mf5IUiQ7nT3JS9OyBLO.HNAKzh8BjMsK3R.vmrusSpUm5uVVYk8YB3qvKBfSCFb6viHRkQdSQzNExJhIzMR+AHLiC.PROtg76mr8Vehcj9yd6wgjugsALCjo2sQj7IejwHFQA47hh11KCficZ+nJlhqE6aFOVnQZMjXYW9Wesi3t3tEBFLXwRZACICe.vPy6LZoCig3kp8T2vjKcx2b2959.DTPYTZIsxp6n5Wa3NimikHi8hgGu9BKxMIvVSDm0EIRj4pb3nI0gKfoPoxPOKEuUHpeig72WzdUziMXhMxN6bEsAfSopJp5FrF7UHzgPvZPOxTh7cHzKHw+hA3w217IXx1Sd6QBFA.3PIXFqvS.r8g9RuYs4qbRSZRMls6rGAIOBQdP.pR.3PgMIfGT.Oqivimryj65dv3gFDs2rw0NrmbOGOmeZNl64jqd0gqLxyNmQkk21BOuNWF.V1ngrFHbo6QKn8eWWx+IRJsqbeOsWe8k2Xcuw6fdSiQag1GMVybiAzVas8xCzwSlL4agdxbxCX1Sd3Pqc15KAfgyPlXS1dxEAfA0LiuxUtx0Af6q2+FQjb0IeM.7ZiDY7Vq4sRBfjiTcIO6X1ivkZqrG1vnZ2VemEw7jm7jm9xdDF+fFZYwDA8z9S6+xGqTm7jm7rmO6QX7SFc+C9BiGlN73FJ66C4IO448erGgwu1Zqs+H.ttcZgD5zJ62MYGIO12utURlm7jmAO6wjF6S1dxqHRvHOC.NGAcP.nHHrA.7Zf32454duIWSx7CPbdxSdFTrGgmeagjsm79S1dxi2eA9+voyl9CUbIE+QR0QpiKU6oRz6rikm7LlfjX80Wu+7oU9gGszRK9tm64dFVq3p5qud25qu9QcG01iwyu9xJVwJ5F.cu10Nr2hDxytYtm64dbR1d6eSWxGX5Se5C+Loxvf5qudSYkUwo3ym4Am1zl15FNxn4latrRm3Du4a7Fu0yE.aXTVE2iilRj3dn0byQidg6vf8tuzU5z02cpNVL.tmgZaUVYS7hAPm.3VFp0cmwdTd9km8b4DOwSzSBW3F84a295stgFZvJZmgmm2vNYW333Xovj0D7x+NC.nzlATEC5JHVkk1gbhp..P.g.vfusFjrGome44cOleyMefTZZTX7PvCj+8BC3qoRKszzs1VamS5.AtmKapScqqrlFiG+jLRsI57EfTUEjN6U0X73uvLqqt6XgKbgklNqWsvf8iBBPKov.AZdpScpatwla9vgTgPJrA3yYA7YjyBbbzaj0S0RhZHzlrdtyelybZ+8VZoEeat6LWng5iJPWBsIK4O1XsKUvbwBnROwKuw3weoYVWc+nFarwIPGeyDP6KgxYEew2dsqdgMzPCY..hGO9gHfyVfiSDuU2dd2qAZ.83KVrXGrElyhDkJhtgzCLy5p69..lybtkwUPQcUmD1eQPJsLurYSL6YO601XhDGF8XojnTA8k.PgVp6TYy9zN9BDUTSF.oomWSyXFyXIyOd7+Si07Nj5PrF7wnEVQ9mmYcSuksd+t4l+TzpyTPimvrYJ7.QiN8eM.PhDI9f4rnVRTJDxBp+2n0V6sQREKVrRD4LA390y2qZwTp4nQilNVrl+pj1TVfu..NL44dIV48hT4dgVZoEeaNc1KfRGrLvPo1nTrnQitp9dOhTcC.eMFO94Y.9LBzEPOwLpqtas26gArzoNP8Q54YA9l4x3KwEcQSc0x.O.r4lZpo8iz8.rz5PwiCD9.3q620zzV7nuwFa7CPGe0JXCAfz.3OLy5p6N..ZJd7SCVmECi2oCvIk+Wwxyfl4tvEVoQpEB768L7prN7FAv9zU5rW5IdhmnG.m9dkMa+R.AT7aC3DTF7XjXsT3OQqyKNu4Muxxjq2s6Sx4QYaD.UzU2Ytm5qudWZseZJbqjraYs2D.tWQ6c3Ys2fA7orFd8B30ni8taokV70clLeOB7uSfFor0Co6kBM54y2DIr+d.71T3oE4yeCszx3ow8W.XyAq2M.oXDXeJq7Jtc.fXwVvm2BdaVf+n0vq2X4yXDtT.Fbuxlse4HvXwVvmWvbqf5OSYuN.7SHXcwRjn1XwhEHPAc8+HoBorM5HcSBFOGW+22blysLNJ8wjQ8jKCk27D0sa.mqie++.KrOmwZudiEu.Ll6dQKZQEXf4ngQ+T.j1Bbixfe.o9hMEu4lA.ZLd7i1X0B.wiZjtVJuegLptFikXF0We8t4DtUC3SZcctRHyBE3oDKQhKnkVZwmHuG..qgWugZ9.lHhlehjnk1upElaVx7NfrYWWuUmt.+KZFyXF+it6NyEQoC0Pc8Hmy2G.sIZtqEsnEUPeuOIX7.LmKI2fmwLWQr.Pd1MEO9oIIJi4NIPDi0NeJ6M.X2jq+L+x4N24VrAHK.RaLlZD0cRfOAgsEOh4PJlIWt+mEsnEUPyM2bMz39yA0+vA3ZLR+PRdrMEu4an2mFuPX7tQJyqHhaNume4YPSw.YyZs0t10t1+VEUTwDkjImPqFpO...A1X2j8OfzI5xC1UOqoW2ero3IViWtzO9rm8rWaSwiOSHrhYFs1qtOk9EZJVhGnzRq3HAUWvhGcF0U6Vxj1KooDI91vZdrnQm9C26wVZSwRbhaLa1ZHv842gulw33KSlLiijqA.Af0VXznQexlhmXc.dO4rpM5phEq4yQTa10XZLqmma2EVnJwy6pxjy6wiEK1gZo2ERxu+Lqste1VamlVPRXr+zs8dhfc1vfanOk8kiEK1xDMGFLluE.V2Lpst9lMddoFiGexETTWmh.6hBOYznSeKYB5kzXhDecHt7YUWs+1sHulRj3TVWWcEwH4IC9MyntZWvVDV80W+yWZ4S7YiGO99XAhBwu6Lpaq2ed4DIRrDOhGnjPg9EHatRjQ9Y5z1081u8KUQEU70xkyKbWYx70AoM8lKb998uAmdrt6cMzw4Qap4lOTB1Mg8olQz5t4s65mpLA3G.ABD.qbZSqt40TSM8HKe4KeaVXBpPI7vy7e98IZLd7aAjGVrXK7uCCpRdYO+tKpHEXyal4xkaA97Wvg4FHv2zZwl5Y+fzZD4qNy5pquKfg+VSwSbeu8F1vWAheDC0Smo6z2YwEWr+063jZuxl8hyJ8nIRjHtGfGsl6JZzoem.461adFBTXgE1UVOuiuzxm3kkySaV.qATkY6y1.oub411jGf0cKisrfwue+E..PfOnnd1ssMDvew3nC..oEvp5ujPWRXqwvY80WuADc4yZ8jz3xQyhf0KMMlMHX5PPY4VLFKXx43TPOhQShfUlySymN9XAoyhLRB.K1533GVThCzesuMsqqdkbVrRiwrs6eJkHioeq83d6x2unwDIlOkFfsb.yyJqlBAeUw9eMRgLpmA2+edOQnamrYonikP+o9dtFZngLMEO9J8HOHJ3WJW+1H4qs1ZS1TrDajRAn0b5f1KGN9NqIT9DM4rZcVW2qxwSQrDSLPAcMOvdyDMRhPKkVqDcr1s49wVXcqYMWQokMwum0fqOSVOeMFuYIfG3.OvCr+IbWAOZ5+5+mjBVjiT0.fRniybJHcVCb7AeN9.fVKIeGR3Zs.dj9LC3V3fddB7g.QHQ9A7EnvlxjyhBxYgGr4H3yIo.fb8.daccom23WdFz71qeSmMI9HqaMq9D2xXiEKVyeUK0w0aQb7775W2BIP0RN88X8jQWHecHbvaaaPhOp5YV81WP4z+yQJi15P0bfG3Axjs0tURSPzbcVhZmUs0t0WRaLdyGFxziwOQPQlF.fFzljdkYFstyuuxuwDINph746uzc5LY8.NPzmjSf0Z2WAV8F1f+9k+AIwFf0d..XqurOuladJFKNFiUur.+Ba20nzACC9qRVxsIg6RHJ0+8aXxd2JljL.5PAvcuky0RKs3qqzYljwZWpnIKf6GF3elQLl6BWXkLmWQxyqXqCbmUs0dx..whEqD.muAsJF.ucP82mQc01u6GwhE6HcbbVRNKBfcvjiN9xK+yNi5p86A.Te806ujJpXRNV8qSlrikBf9knWos+Wq8D1PzPvjh5slQs0M09d9lZp4Oq0l40c746PA.bjxJvs+YFX9XVX+IDrPH6JmQc0dC887yOd7+yHgBsxjoZ2mj6VuNboPAaqvxy+ZhEHfWlLifbLG1nHF23G+3KedyadooOeeTAcYPbCIRjnbOKdC53a5IRjXAYHKxwZONA7uQjqGuunJ1Zc9zM2byK1yy61A4C1T73yDV68B.H5bN.XBE52+ir4tybEvvsYbirEIsM+fsPwjzJfrNVSUM1XiuA.lfw3dJB5SHWu8u95q+ePnBbs1OS73we1rYxbON97eVMkHQTZs2qjLvXNYJbD.3wsPMSwaZ9wi+NHWtWg98ueVqtHBTXwE2c+7r0RDmByKVrl2jmWlWxwwIj7TLP8yJojw8SdmMrgyoo3wuLWi4m1Mo00ZOAJ7wg0dQh77j3199Wgzn9m98EJtGcTaBhmbrXM+r4767GLVaIckISC.3uFMZzWuw3wuYZvMEKVrY3448ZNNNQTVuavB7KXtrq1356IhGO9zsV6eywwgddZB.5s6p.++lBRm46DKVhYkyu6OWVqw0y6aHfixyy6IAMEBfAbGCzH9saJdymf7xdSFiYSvyabhNcS50u3PSFTHj11sU.efpr0tlNdlRKehNMEO92Wdd2hqqalbRGAfsVath+ubT5.z.+vhzfXeZLdyeWZy8yIYWV5bVRpJatrODBDXwtV9qZLd72T4x8GcbbJRvTGDJboKcoOTokWdwD4b5iti4OPWT44e8fVmatzRKcXEma..gCW4cCoGz33adN97OWJdLVhZMv9xVK+rNFTKIqLmTbGO88.4xE3rvV5FG4bEsmVVKNwnQi1IkNdINYYLyWFy7IUwNDe8oN0olUT+eDneaLPRleMsNuwV97RW5RkH+kdddqfxNaQ6IQiaizw2U.vURYNSizQWVYk4ix4pgvw6Id5yd1ydsv5chPX+ELwfwYtPbbcEv+2ZpScpYmYc08PVnKwHd9z0MAs3zMPyUByKc5z8yy1YVasOhAZFViNU55lPzbYD7GMi5pagm8Ye1c6ZLm.fIXVqcdNddMBw8SVuSHZznqGjKVT8ON4j4Q01kBuzunmj3poPXPLQaHmb4Zz3oqEhuXgA7+c..lYc0ceB5xAc9N8pKWBn9YyLZsyYVyZVojgmuE7Lfwo4bRwEPMtj0cYScpuCk8jrFruNYxE20ydS.nB+ttmRznQSKneuQNC39Xsr4lln1.cbminYgVxKhhWUznQ6W2uMV96L.+s9crdj4i1PCMX8xl4TjXAz3NOOflHvgY.N0K5hl5pgL+YZsuHfyDHzCZDdUYLWkfIFAB4XvwO6YO6tl8zm9x7HNSCvQSW2DfNeePsx0s1UOsFZnAKE+kVqssAwi54IO6Xpu952gQJv6lqBhQ6UBvP4ZYr95to3M+iZLVyWvHUWFqzyc1yDiFDKVymZSwRLn1JYGLWi4C0k7LrngFZXGllwH41kwj2cQCMzvn5No1P4ZY2v08ZnQadjpKiU54N6YhQI1nLXPkzRFLWi++fJXkwknqa0OC....PRE4DQtJDXBB" ],
					"embed" : 1,
					"id" : "obj-1",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 158.5, 169.0, 336.0, 51.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Documents/bach_STUFF/logo/Bach_46x319.png"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.22,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 7.0, 5.0, 191.0, 54.0 ],
					"text" : "If you have a precise idea on what you want to search, write some tags here"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-50",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 287.0, 281.0, 40.0 ],
					"text" : "If you prefer to have a sistematic look at the documentation run through the list of topics."
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
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"text" : "See Also: ",
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
					"text" : "Objects: bach.roll, bach.score, bach.slot, bach.quantize, bach.eval, all",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "objects"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"hidden" : 1,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 158.5, 123.0, 259.0, 23.0 ],
					"text" : "Welcome to the bach Help Center",
					"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ],
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 585.0, 19.0 ],
					"text" : "Tags: welcome, help",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"source" : [ "obj-3", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"source" : [ "obj-8", 0 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0,
		"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ]
	}

}
