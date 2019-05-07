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
		"rect" : [ 151.0, 79.0, 941.0, 639.0 ],
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
					"hidden" : 1,
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 331.0, -103.0, 29.5, 22.0 ],
					"text" : "$1"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 460.0, -34.0, 29.5, 22.0 ],
					"text" : "t b l"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 331.0, -65.0, 39.0, 22.0 ],
					"text" : "zl.join"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"linkend" : [ ":,;()[]{}" ],
					"linkstart" : [ "s" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 695.0, 110.0, 87.0, 21.0 ],
					"text" : "supporting us"
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
					"patching_rect" : [ 976.0, 184.0, 307.0, 35.0 ],
					"text" : ";\rmax launchbrowser http://www.patreon.com/bachproject"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"id" : "obj-25",
					"linkend" : [ ":,;()[]{}" ],
					"linkstart" : [ "w" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 663.0, 32.0, 209.0, 23.0 ],
					"text" : "www.patreon.com/bachproject"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 15.0,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 713.0, 11.0, 159.0, 23.0 ],
					"text" : "Support us on Patreon"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 14158, "png", "IBkSG0fBZn....PCIgDQRA..BDG..H.VHX....PCt.qw....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6cuGjmmcVee+8yy46uYlcWIC5BWkVIwEcwFARbwFDXCxXic.IbLFLkiKP3TtrAhchiI1wNtRbvNgDRUoL1UY6XbLwbyIFKTUNkffk4l.rtQrAIffD6BXwpUfwRHUwQZ2Y59647j+37s6YDxyrBMauc+cl2upcmom9x762z+596uO84bdddhppBIIIIsar9.uUxy66DRRRR525LDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmjjjzNjg3jjjj1gLDmziGF07++.ekOwb6dhZdaV.UUOwb6uGr84nhS9Tz0+y2n4edvJcN4yi2363M9wN9f9n+2upJnt9sUALFCVoN8uuSueUef22Fia7wuw0+6SRZyx48c.o6HjEEIwnnxffATIDm82tyajAEEQAQvVvgX9x2Eqphf.FEQDPrt8itlDj.i46STDUPEMV19TZT84mLiSd+gZ6ymIw1G2iwmfihAi4GcUTUPFI4XK5VDP0IhFDaOlMu4IRnFaOdF41697eKU.ULHocF8YNIsG3JwI83hbFbKiqma6Ij.T4VfsjfFDMppnmAwSL2AtPKhfJ5TY.wfpVXPPcxk9VShnQwBqQd5mwFzAZLpDHo5yUOCXFFqeR5pGiaeRRZLWTsFYlTrEB6j6SQRuV2d+uQIQd7VF85z0UsmAQDj93qzc8LDmzso4Vg0AxS2lspBf0m.t0GyUGpJpX.LHhhrJHb6Tme9HXTGAURUPVsSi+Ts4iWAqrr8oqQwVf3Uxs2wHRVXFdJhfH+PLBU0YPmLgqwwbxiWAA0X.jDEzhEt9lzdxiaCfCvnCYPFy2diS1lVu7szc6b6TktMEih1K5OLIGA0BUqHFcp3xT0Qms23URvJUDDwkIpqwO321+y7R+c8oxVZg6xkP0mgjpiIyCTUeFRisUpq5DrbZlnLW4n21u.KW88y5C+1Ie2uGpei2Mikqx5a8WlnMWItVDLdL94fimwyjk64IwQO4mDW5i694Z26GIGdlOK3Y9wC228NeeHnFqD4BQ.idR1lQ5RFTYinNlhCvXP0lgJOYizkzcuLDmzsqrHYkAKPzgQad1lFGwoKkyYknnnMOKdQGNYE35i4R1b29hsOJprMWtzHgsvRU0u94Y6c7No+K7yP+c9ul024CQ9POLDAGEC5aakYzVnphLCpAj4xb0Wia8psFO7Cy0ZCxA7nu4eRZ8fq01VQv68Rvy7Sf3S74Q62wmAsm4yf3dtOp1JCBxBFURlC50AZ4XddKqADisyzmjtalg3jtsL190jkZvZ1HqAiHlay43LdKMi42BWIjwBibqJFaamQu61scFEqSJTgLg28uN8el2B0a8mg9u7+Ovi7nm9YpkL43.HGDaGAtHZvnXgfiYvAR5UmQ.QcquD5HfbLuerTPOKxQMOlaOx0fG3mm7W7sww+.uJNJuL4G2yj7E+6j7S+yj3Y7bHhNTMZzoWEsHop179VrhWBW5tadE.oaaITEqI.i41fUEiHmgFNqUcxJXDcx9VEpBOwTcrW3MfQP7d+2vQ+P+Pb7C9Vn8v+Zr1JVVmm0rAIYETIbzXP1fVOoGPa.clUu5ZLKF30nSTIsALdLN2gUjzFIiwbQRokL1ZiHsBVyjduHyKAQmwu5aG9Ue6bz+rWEbkCb4OsWBwK5yh1m5mAU11VAwsEVzUhS5tdFhS51x1SjdRe8XDPt0tupS52GmgpspnLFyCQeKNsMXbmP.tB11p3woqH1IsyEtwV7wVa2..hfXTvidD8W+OHq+juNpG9eMqYBclaEYMXjW+xeiX1L2RBXvbaTY9v4IM8iSWYt55usGqsqNpSd+198anu90is+thXqPEl2NC1V8tG4X5ugebFuwWKs682Fwm8mG4WzeP5OkO1axEt21FVhYQbrcjHOoUnLNoAlzGDQmQLHiK+X+ffjtvxPbR5BqYaagSqDyJX6Loc89v2n.xA4XFb4nG7sR60+CyQ+j+D.KD8Ygejyl+FClUO7Vboyu+w8gfQ.Ykzej2G7i9Z33W6qgK8I+7X8y4KjkWxm+VaSI1BttPjC5jzhYE2RsrU7FylPSEPz.3vr3kuCHnuzcyLDmjtvZtsgiY0XdRytMBFiquS0Y.EMV+49WQ7C+ZX719YYDChpwZ6Hx7vbqOqi2p3yCyy01N4LCNh4VzekZginn+fuMFO3CxQ+e88vk+BeYjeNedD26SlJm8ztrN4L.FmtZbAmtrbzij7CkFUrjtvyPbR5BqfDFIqYwRrRUGHhYuvqnAUm9a30wwe+uRFu22EYOn1lhEi1f13.QTLhhFMZjLFC54rwL+AOpzt3oQiCQwUYkEBVoSKBpei2KW6U9cS666UQ966O.G989xgKeevVw3RzNcK8GQQRQDIYGnEWeZVHocKCwIoKvlK41RETiFQaEFs4xv8K7V4ZeuemTuieYprXgFiVxxH3X5bnf0Xb53ppFAiQmQqHyjV+5m8sKtlaOZufjEFQvxH43nykhjJZrd02O7p+mxQ+v+.boW9WAG9Be4aM+44T6nphLhYdtpnZPxIU+xE9OAHoaACwIoKrNYdz1iio0tz7.6+deW7nem+sY7.uMVHXDKvXk0rnMpY0iBTij11YdaDAibPzBZ0rvGhVvE8cTcNcW2ZaLAzFIUlzJlaGbsRqRhrX8QtFqeu+eP+G4GjCe0+on8b+Tlm8u1Iyu01rUzrM1VGTOgT7zR5rig3jzEVAy.XsXg58+Hb0W6+mb3U+8AQwAVlg6pY+ZakhJKBlshiQtRiF8ZVMqQMnNo4+FE8Zk3B9k.6QNKHgpXYLn2JFiNWO+41pxMZyphlhw69cR825al1K7Si1er+io8TeZjz1pl2hiiAGh7BdIcHoOTbw9JXR5tZUUyC1+C71X8a+uG464WmihEJB5z2FLUIibvAfdUDwrpSOcNZDyorvHx4bGczohFQrPcAeo3VnnuspYr0hRVpDJnEyPYPt0tRBFrxg1Un26j+ruEN5A+KQ9k9kykeo+GvHZD0fCwxoaspI4j12LDmjN2cxXvZt1XACNljCDO56m56+Uw0dsul4TKfFKif01rutEasdjjf97z7OaptbR+bKoOe0.mzy1Za2lWrCvAPeq42ka0XJb89N2rISeiu2EIMFiAQDzont1Uo8J+N4p+z+jbk+D+mR8zd5ySYWkywyFsYE.WGSEMFEzhsjci5rerwIoaK9ygIoyMEGyJ8ss.MYYqwukbfw63syU+V9qyw+HuFNTEQuwRjrFqbnLbwGJhZ1S75O3ai2+2zeAF+zuIxQRO5PrEfavrpeAZaeZsp5zQ3ljt3xUhSRmaBNvBCHVopksl6ax3G56mq9p9GQECHRVmSOKVxUnZbL0bbVYVtasL3nJnUP9nWkG4+0+Fbu+N+cS6O1eR3dV3jksLxhpmDsAyEnrSD9y3KcQmg3jz4lp1pjzZYtycOx03Zeu+Cod8+KfXP1i4xCUPKFLXgV0oGoC.9ODD8UZYQKZrNfCM3+uexWO22u5CS70+Wf1S8ih4zgsAM3XVYIN.wx1HA679eAR5VweTKIctIhFifYAF79eer9s7MR+M7iucdsfZYPUcZYQMBx0UFz3PErtc11zMWlIqwBGWyJRsORtunX7vOLiuo+RvC8PvVSStFvAVly62pn9.OvcR5BHCwIoyM8Zkjf3geHd++U+yxUe32N01ngZ1yLZrjIiJHaPOW.5ziAKFx3w1X1ZRVpEVoCihqRPwwb7i9H7n+O9eIW6M8iPDAYtxw01XNivwxkzNfg3jz4lVrv3c7Pbs+V+0HdzinEIKYRqeR6yXvw8YOeqWEKi4bRs1BxoasNKDwBcVAfHJtbkLhKQqGTQx365ak023qipV3PLaMKy0ga8b9dujdrXHNIct4n2vOLG8M+eM82+iPVPLRpQP0fwXLGf6wB4XgDnhhEfQ0nMNbde2+BuJGv3XZQPeDDQiU5y9NWVPELphq9c72li9t96sMOUmgiun2Hjkjg3jzYsAvrstM2.zsgN+wugWKqemeaa80r4YiaD07LxUy.Gy9.270MXVMpyV76bntqasnX1+2HokyI+.jjUwfjLfk5.Qzf2vOAG8c824jOxseecddEGyysX0OY0OGtNcRW.XHNIclYPmJW25GYyU4YPQ+M9iw367ev48cOMV2pBXnnCu9WOW863a8FJJ0EhJYMqYUD2t9aoUFhV57lg3jzYlnRhwB8nn159+82z+Bt524+Kdlqt.n2BVoHnXkhdDDuoebN5U9syISmU5vBAy0vactZdUd82tjN2XHNIclIh.xAKDyUx4c7N4nW42N4naDfK.ZqyUZiHHInxqQmFie7+Yzei+XTbL0xrJhCRFL6ebEc7oOjN+42EJoyXI8ZP8Pucdz+l+Uo8HWiJZ3ket.n0mSECfFMBtLiwUYzabsuiuUN9M8FIpNMVn334LbMKhpYKHQ5B.uJpjNCsEP3QuFG8s92f7QdThbrELvP.m+ZDEaELRmneDKbIxpHhfw+3+2X7vuCHfnNvnC0rNgA2NboycFhSRmYpJopNW8a4aj0eiecBZLfsVcgNuMF84JpUIUjyJYMhSqP30itFW8u4eMFOx6iQsRdxyXjENxyjN+YHNIclIB3Ze2eqDui2AYtPmZt0pQiF8y66d20KyjpJxXknfVAjChrSqFrzg5QeTN9a4aZ99xrALyvUQU5h.CwIoOrMeJ8Yqlny3zd.Ga8Vr02vOB8W2OA8433jnMGATU02pvQcd5j9F2X6oB5QBifZznGIiXPazX7q9KyQ+S9NIhXKHWvMVcp0VS.bPmggykdBiWEUReXKJlG18QQVIU.TyIBv5u1uLG+O46lVzABR5rN5zi41odRKGQWbkrM0GVSV+Q+mw3m9e4rJVqw1Yia.0bEWKJxpQR6zl6rjNaYHNI8gsJ1V8sbqEhDCViAIMN5a+e.iq89XvApnnWEWhEZiUFzIsIibgWEyo7PsLnphq9+9eW38+9Ix7zwyEUet1bQvwLlKFabRaHQRmkLDmj9vVPBYetsbag2Vnw0d0uRZui2NK8KATzpUhHXc.GcHnMRNxPb6.ymhH.xbgw66Qo+2+uEiX1m3FLahyy.cCNPxHJp9Xqy.JoyRFhSR2FV45Uo3b0ZpekGh0Wy+T5wf01JDqziEhQPKJtzZROgK4gi+Bup5j.43.zKZA7n+BuYF+P+ymEDQ0H541VqNW8skJHxj4dqKoyRFhSR2FV3XV2Z7qKDQvU+t96xgQPLBhJIGKrTIwRi0wfZImyTUeN9K7N4IHVqNQtNeLMuDW8G36Adz+cyGCi4Yirex6cvoaupjNaYHNI8gshAGXA11Nsi+9eUTuyGhiGcpLXTvHFzyNLV4xsKQbzfV0HFsy6695wvbdplDw7264JsADOxwb0uiuMh5XVyhwV6IY1y45DefEupjNiXHNI8gsf75Ug3i9nbse3e.xJoE0bRatMRmxQwZBWKVYzFTAr17fueQ2gpQa.jATMhJoGAAE0O2ah0G3syxVS.dzmMejSRvYGjQ5rmealj9P1ruhAiwXqGRbRWAK4peueGr7nuOFQLGYSvV+Ga1Gxxw7+gjnXN300EZ8Xqu9NlA2lMTlsX6iFG+J+6SEGXLFaSygsGSqjXXSFQ5rlWEUR+VVjypPDRVpN8G5Wg30+5Y.TQwfjHb6RuSW7v+pr959w19CasYlsUm09.nzYOCwIoapwIcs09V+fK1VGlpt9ZxDM5upua54rFECNZthccOTT2oaDcVeMeOjQxHNFXLWk0sw3kjNaYHNIcSkDypMrkyUVYKbVTysVckhwC7V33G3mmfUpHf3xTwJY5kWtSWlGnd2uat1q+0RxAf4jafZAaSbRm87prR5l5j4hZ.aCHSfLnhYkHdfhi+9d0DTLph9VueqphtCdo63U8inmGH+9dk.qvnlyW0.JN979tmzc7LDmjtolCWo5z3XmrEY8.NlN0C7.zevedF4fnVfFLFqbHlarptCWtP1Ohq9ddOTuwWOv14fb.AdlHkNqYHNIcSMFCxsAnTrMiT6wrdSOLf02vODvfkdN2B0ArPvZs.N6Lui2fioUG3PD7Hu5+wPB8ZkHG3SuHc1yuKSR2T4MtZZwbU4BJxATum+e4323qGHoZchJoh4pzsTFf6tAswAFAzSHdu+6n+S+FoEKTkc6WomHXHNIcyky8Os1d4jNMlqxxwuoW6oua0nwM1+25wrevo6rMhYX8VMnFCFuoeh44gLFyjcR5LkeWljtoJl0yvVO3GFKT0BjcV+Q99Ouu6oyYsJophJBxL3n27+Rh2y+VVFMe1Eom.32lIoapN8SqOgnRHgHFLdy+Trb0G878NmN2UwfkD584JxsjIG859wg35qRmjN6XHNIcSkrr0S35DQv5Vcpd7a7GiiGV8o2sa.rNFjKMpXk0Qv3m7mfQbLoUmpzYNCwIoapbDLpwV6hXvBA7HOJqu4eJZo8At610hZNd0FEYuQzJ5u62EwC8NmS3CIclxPbR5lphBxqukpLJVey+qXIggEe3c8FiYsuTsX1je6Plv0di+XP4J0JcVyPbR5lJhfXNOFluhLX7y9lnWAtPbZDKy1KxnSOmiZsbzY4m4mhxu.Q5Lmg3jzMW0AVlE0.ICNl9+xeJRFLBWJt65EGSa.EIYetk6q4BW687tnd3eky66cR2wyPbR5lKZyI0vIKpxa9mlQadf1adv0uqWTKLhAsQROGTUPTCVpf3A94opBFmL11Vgwbt55ZzI83CCwIoasLnh4S7d0G3mG.ZQfEmpfSN5ayyDWVAYlLhAW8s7+MDAUDL1ZPzUdxVzKoGOXHNI8XJh.phkG7sQi.pjxQqk1hiMhNsdvHJnGzqUpeo2FAqrBzFAUUD.ECFqcbrbIc6yPbR5wzXrR7HWkieG+qIhj0Zc1ZIzc0pZkn.nwnJZQQOOlk5.YOX8A+k4Pw13aqwfNTA4RaNAPjzsECwIoatQALHxEVemucVnQwJQKmmUNcWs4VnlPbL.zqZ6bxA8Hn+NdPHGPkDwXV7CQMaEIdlJktsYHNIcqUIEEiG7swHqssR0.bZZVXCKzWJxZN4FhnHnHdauUnRNNVoHgFDjDMvEhS51mg3jzMWFT0JIAK+J+hLFy4oZRCrEiHlsdlJFjCXDEswAFTzpU5+ZODin3.KDLlUmJCptesiziGLDmjtoJ1JpAfq8NeHZmLTy6kGKcc5WaPcxViNHhfkpQwBiei2M4fsZXHg7FVINKQUoaaFhSR2TytGQCXk587dXPBYiQzYjd4i61cx1pOhhSVUtNC5TLBHIX8W7meN91Xb53TcP4rUU5wAdUXIcqMf5A9koHHphnfHZDcawH5Vqph169cOGcaUQtE5KoQktTbR2tLDmjtoJ.x04JtTGS0V.lCfqEqtP8XIKt168cQEysYkrNs+BZDNoaeFhSR2TAP0W33ew2BMVn06.AirQOWOuu6oK5FEs+suKpsUhipr+BJ83HCwIoaoncLKrvZdU5QBzoUCJVNuuqoK3hnQ+89dH2FKWT4VS90xhQ5wCFhSR2TEPMNvwO7CRi6gjAUjyBbvmHVOV5CVhitdMLjAyImpsYDoGOXHNIcSE.QNn89VoWGSORhnHYPa3kOzigVx5C8NHCnpSZGIaUxZyu9Q51keWjjdLjLVNhCi41mVUw5IaOlzsvXLX8pu+Y+FjfNCh5FBzIoaKdnVjzMUU0LrVOnmcZ0Iah5fQzbzIoao432J152fP6zF9qjd7fqDmjt0FE8G7AnB1lapAQzXLr5TkjNOYHNIcSUwX1TViUhJoSmVL60W1pHjjNeYHNIcSki1r2dwAfA4R6zZRMs5TkjNWYHNIIIocHCwIoapQ1gHn3XfjwZ+zKZL7xGRRmq7pvR5lJpjXTPsPECZznuUXCmLCLkjz4CCwIoasLn8bedDEPLH1JrgLsCEIIcdxPbR5l5zF5aqnMZzijJfJRR6Qb5CAIPUcppNcTaUL6AgR51ig3jzigA45k33b1W3hHXgxmDVOlZUx3I8j.xYK+skLFCJJm3GRONvPbR5lp.pQR+IsPKNPqFTUvfjdZKFQ2ZiLX4i9iknfiYvnFj4LPm+P.R29LDmjtoBfHOlCOymKcdTFjD0XqGw4kOzsVLJh3JTYvARZU.iZ90UtRbR217pvR5Vp5GXkUVFWgVM.lmMt.G6V5VquTvGyGK0XcN8OBfrXLFvvUhS51kg3jzMUADsUN7I+hnyJ8VCnHGcZCqNUcqkCfOhmxbKTKXrs5aYlyw4ljtsXHNIcSE.LVla8UbfnOW8sAIqXehS2ZUUDOm6GpjJRX.UET01WaIoaKFhSR2ZIDOuOQBJpHlsXjpS0Zm22yzEdIw87jfXFZqAPDDAtcpRONvPbR5l55SkgEhm5SkjAQzoQCKNUkETAjUvb8YGDQLK7kXtps4m7ye68dbZXNX.tcpR21LDmjtohns0mQfCOymEUbfpZyClNlh6tciXrcV2tdeeaLVm0t7Xg7Y7wMKlgQwfaXOTqBWGNoaeFhSR2TmzXVoJN99+Dnp4pyksAQXgMnjHBJNFXtVbs1Ap.FAzdZOSxpQEPPCFaMI5J8LwI83.CwIoapLSJBF4fq77dATQmCbfAKLrEibWuVTzqAAGXL.xfpeLPNCq87dALp4VrFr81i4uObs3jtsYHNIcSUUQDPRC93d1vHXkqALHqCm228z4rZjDQQxbRLLV6DrPRvRrxxG+m370SMKjgQwf4WW4ZwIc6yPbR5lJhhXrEl6I+j4x2+yhVdEpJf5ny66d5b1HJfAAMpp3PKXDcFiUVyq.+1+j3nQ+zhfoxf1V3MWGNoaeFhSR2B4rhBKnCbzy8SgdcLsnCksXDMqUgwXPDEi9rXXxL4xuvOMBV3PjmNoFBtd0o55vIc6yPbR5Vpnlqfxn3Ju3OchZtpK0hqkhFjURlyulXj4rGBVAiWvmxbNoV.QPcRygdTN2Tkdbhg3jzsvrERDvrgf8b+TItx8.4kn0MD2c6Rf0J21VUHnCzHYP6E8YN6EbYrsBbamgxLvm5Q5wG9cRR5lpHgrlsVjrSBjO+e6TUQ2t86c8FznkIQ02Fv8IPGdZOcxmxGy48cOo63YHNIcSEa4zFLfX1t8aunOSZEP4kOtaWEcxwJCRVpKMaqH.0m1mItioRm87pvR5la6JDMRhs+P6E+6jiiNCCwcWunRVWlUbZmAGBXPwUdI+dYbxYfSRmY7pvR5VXPUImLjjpBh649X4y8yiComIt65EIKqEGyfVz4HfCO0OVp6+9Is5kkNyYHNIcqEPPPU84VjMfkO0OW5k6W1c8phixXq8hznECZeg+Al8MN6DbRm4LDmTud9Z+..fE4mDQAQktE15q9wbzIQGHgkW7mEKejeTmy22z4sFAGFAT84n0pVX4E84.UQXHeoybFhSR2T01uT01rtrM2R0Uf3y6kbNeuSm25rROGzpCLZP6k76Fd5OMhnyvsaW5Lmg3jzMUr8KQDy4m51qaYTjeQ+QnUyxWc970CZmL3yYr8+5NZwBKijiZPRAe1eALOGkMBmICRm4LDmj9sjSNqSsCGHeIuTp.FwrxDWqNYlTULmup5NZiZthaY+Hpmw8yk9j+c.rMycOmuuIc2.CwIoaoppS+eXtpbU.DAGd4eEzFPVIWqBxLoWqzhhlWd4NdKU.iUVZWgkufuDpbNUTKerW5ID9cZR5VJh3CZVWFaM925o8zI9b+bIpfCADiZaUXVXzb6TuSWOBF4AheaOIN748E.i041pd5VpKoyRFhSR+V1oqNGGykdY+GQOKVInZcBtD83HhtOI9c7hNU0o8G5ULatu4bra44gS5IFFhSReH4jUi6F2V0bbf3o8THeIe9zpUpQiFcnNPOLD2c5RZzdpezr7R9blMilp.NvH15EMR5LkeWljtktwyC2INc6Uy4ub4uj+vDbfhj0JIhAQXG6+Nc4nX4q7qA1pJ4fFU0IowpM6WoybFhSR2TUUePmIta7kmOM8.d5erTegeQj4wD.QeP3rU8Nd4y64wxK5yBX.QCBnu8kGKN6TkNy4UYkzM0u4BZ3CR0opjnfq7x9iRcuOYpssRKKHYPt0y3RVAFDQREy1PgtXqUPt0pXxJt9ioUPECZeEesDai59nOn.ZzfQArbddWW5tBFhSReXKhFQvrkibk6iK8G4ONQ0frXDy5SrGIYkTwknZA05JKUxvUp6BudLlEuP.8rnmqTsjJGboufuXxm0GCCJhwbUYiBnJpfOnsfWRO9yqhJoaKUePLf0ryxK4kR97+jHyjAEswBIA8DNJtF4.hkfNChzBe3huba0XGj8hr2n2KFW4d3vK6KmiIHq1rnFZI8QeqOBNbkVkdBfg3jzG1ppSzRHWoU.ifq7J9yRrbujjzObsYKnXDb49kXPmkdQEqjcu7yEcUL2H7HZTsFrL3.MtxWyWO7jtWNTaUjZFTTzZs4JyYKFQ5IDdUTI8gsfFvJEK.IDA0S8oS7G9KCxAw3xTbLinyZLXotDGuDTwB8zC99EcswLnd1KJlsPlwK9EQ6S8yZNV01BvMnlmctw72CRFtPqRm4LDmj9v1nFaA3.hhhNEEK+deYr7bedT0Js5xTzmaqJqDEjigyV0cfJCxJYz5zpA4S6oyUdEe8mN10pb9XXT.autSjoO8hzYM+tLI8gsSdd5.nF.jji4q7vep+hDW4IQOGPbXthNUiplyd0zsb6BupJFwXV4owAVdE+YHtm6c11YFaiWqwrMzTvbTrQwvdDmzSHLDmjtMjymLGHxsCAet8muumDW9q+OOsQRRQDM5sqMap+NWM2ExBF47Lws7E+kwxy64NCnMpshWXFHGlA4YLOOby.59XrzYMCwIoaOmrkZW+Ub8W548oP9x+CQTymzm9kHxUhJ25tX57zVdaZDzhZ6ULCekLXDwrhheQeljeo+Q.RRZPFmV8oe.8RvLtguPvmdQ5rleWljN6LJtzK6OFwK4yGFAK.wnnh7CZ6TuwYx5u4oDgNaLOSaCNNf0AjiNYkDYmLVnpAKOymEW9q5qeNANJ.VoptmoQoK.LDmjN6jECfK8G8qg79eNzCnhFsZvu4K+bRnsSlUq1rXO6kELNoOukcBNvHfdzYsFDOoqvxW0WG08bujwJDCpZYqpjc13JcdyPbR5LybnnCbk6iq7m+uL4S6iDx1oyWSc9ZDPFEsBVnQUEsnHVaD228x87e1+sLd1OahHgdBjTQAwfgOFJctyPbR5LSTIQL67Dw87QvxW6eYhCKrTM5aU0naa54mwXLW0SVoWAiHnFAQVb3K+qh39eNzpfi2F2VLJFDvHI6V3BRm2LDmjNybxYtpX.CX49eVr7W7uFiKefkFzqgaa54obVPCiXvfNIcFshCe0+mvxK4ye1G.ii4PsPv7wpbrxZtMoNjz4J+tPIclIX6ruU0VGgEN7w8r4J+E9FYbkKOaQE0+dpxQ8Dh41c2lmKtLoGvgupuVN7Y+RopYwmj0AFw14TLShXgEOObRWHXHNIc1YDWusudRHsLHdlOGt2+y+F4RW5Rm1hRzS7RJ5z4P.UGtmup+zb3k7RohNQLliTqZPQQTIIWuevYKhQ57mg3jzYmL1lFSM9MOfFhm0yg1+EeiLt2so4.CNoGkcR2qnQb5p00hhrfhfxo8vGRlSIia70L9.97bazHApQvk+Z9ZI9b+BYkiIFsSm5BYlzHudOfK.xX1u3jz4JCwIoyM4y34v88m6+NtzS6igi5PLBF4fJOhrfNEwVAPbbTaivqNAcGsSeHHh1rg8VwoSXgw1qOYP+vQrdkKyk959yQ947RIXvxXYq6g3SOHcQmeWpjN+jqD2+yhC+U9l3xOy6mQqSRik0KQOGjUPeKr1gQa1vfGyRk3fMa1GSQTLXk9xbJYTUxHSFbLCRpK8j499F9qS7h9r21U6DxhiqwIGgQIcAlg3jz4lhEJ5T22SlCeC+2P6y9KfbcPOm0AQm0SGETiZknA8H4.GnagP7XqCsXgnGzHoGqbnOXotD7we+bu+U9ef59eVyIc5X.EbLCNDoUMrzNvx48c.Ic2qXTDjPNf66Iygu5+LT2+m.4q7eDiJomyJnboBFYQNJ5QvwUmHlG1dcyUYAUmVDT0QzpCziNseWeNbuek+Iotu6gb.UTD4L31ARpNjdj2jtvyPbR57SdRKFY1JRZAvK8KlidVehz+69MSbsqQTE8VBCXDAQAKAz4CdzcoOPGFyAsPPaNqSaqbkurWAwu+WF.D8woagcULqf3QPzlm3PWqSoK17JfR5bzrJIC1Zlrw.hAG9jd9be+2+2g7E9hg5RPcLDqrTAYAqTfqB2io0ViQFTiU39e1bk+x+OQ96+K9zvYUKIqFvbZL.qLxNPR3b0R5BOuJnjNGkaM424ppUTPzl8Xj68xbku9+Rbo+nekv87Q.UNqV04TamzPbOllKxYQ8E8GjK+M7Wk7Y7bN8rtU.TcFLWkyHJntdqCoBGqVRWz41oJoK.xsecFfHRXd4oAK+99Rn8o+Yxw+C+133eoeN5EDsEnO6ab8Dl8+rFQeknkTQiwXc6u2wGvsSVysksxfXbwNnRDEwXaKmaIQcLi3RjihJm8ANXl4co233khkwfAMfN4S4ilK+07mBd9epWeqQKliXqQCx170Gvrq7ci21dn3jtnyPbR5BrjQGxOxOVN7M7eEseleJN5e72E7ddWL15hsIAL5rBrzNvZLHGChnQTcnRpLHYvJC5aIUhZvE8KA1I4P.iXPVGC0B8nSjPLRHW.5TCXbnncbwHgFMhW1WFKu7ursyCWwI6NZRihi25nxtZlR6YWruBljtqVUEQqnpfHZz9T+L3ddtuPN5G4Uy3G8Gf5Qu57sUGnsDzWW4P1n2NhV+RmVgqQ0Y8j9fVEzJXDW7CvjbLqa+a+3BtTjzXVkoqQmZTyohQjDqP0f72wmAW9O9eBFejOcxsUhLhjXLC81SnwAncwdUHkziMCwIoKrhBFUts8pqTwBwUtBGd4eEvK42GqeeeOLdiuNFKysN8RKPuuB0BGWisQNUM2twQxZBDc5A6i1SRsPKFzKn0J50QTjLphpZDKPMfjN77eAb3K9KikWvKB.RFLJH2NqgAvHWYTGliZqnbc3j14LDmjtvpxhjYuNq3.QLnh41Lt7Tdpvq3qiK+k9UvUe0uRZuo2HGUGwkZMFcXzBnfpFrPwHKhJnhjkJXMpK7SkfH6z6IQLHVO.shr5DLHZCXrvk9jeAj+g9JIdtOexZvXV9GDiY32p5PzlAW6GXoMCGeA+e5R5CAFhSRWXEaqUzfjYso1fpyRrBz3PETO0OZtxWyWO0K+q.9Q+mywu9eXhqcMFiY+m6.KLh4VpNhf1f44JiUfKcd9OuGS0nQlw7Lr0JFiAYFzif7S6yfK+R+RfWvucxQxbEGCxJoBHNoO5EMfwbhMzFjLnpAvkrQvIsyYHNIcg1fslQKssUPZ1RLpbKARMaMFwS6ihK8e3WEW5K4qfie8+PLdsuF5u22KUetha8nQaTL1VMujKOaoIWfkLXDEspMqJ266do8Y+6g64K5kAOkOpa3cbPUaUw51djttsJlA0VQLzoUIirQlKyyHmitLocMCwIoKzxpAwffY.tf5jdPxb0lp.xfwnSdXg5v8vguvWN76+Kk963Wh0ezePFu42DwidM5QPi44AqFWrCvAyliRr1X7o+h4Ru3WBKeN+d1hcNl8+sXaqQyDBHiXqo8BKayMqpX1K9FygaePNayH4JIGNu9mljdbfg3jzEamTUom7h+le4sUdJyka3ce9Va2+yl1q3qi9W8eZ3m4sv5a40Q8S+SQ+nGgb1laYPREiYEqRRUPCXDbZOkadBxlssjwVLpXjTzIyjp5jLCK0qZVUsQPQeNuRS3PErd5pgUD0bpSLWYvjEJNNJNTA8Jo8hdwzdw+tX4S6Sm0682FKihAchpA8j0khEB19uqK+.Wcs3jUaKCf3z9BmA3j1+LDmjtC1xLTVjvK5ER7hdwDuhfK8q71Y8m6eEiG3mk1uvCLmSnQPih0ZPDGn3ZaajaPPiwHXzJZ0fHBVyilaKYuyHFrFIWZLW4vdNqbf1VHsnRNtVowB81fw.xLn0gwXvgrAOyOAtxy84AOuOEt7K9yhiYkERfjkwMNAEJnEmDGSR2EyPbR5NVCNlLZTcf7vrUbDM3Yc+bom8yAdYe4yFg6uvu.i24uD8e0eEZ+F+aX7VePx1kXDyhonOFDKI4ZQukjDDUPuWjjzFMH5rRPjChJnEEcp4zUnE.M5bz7768Q8wxk9neFr9I7Iv877dwzdV2O0kW.NPQmYAYjLpbt.Z4ffXNOSyfdMnwE+lUrjNa4U.jzcrNYKCiDViNKUidsRKVXPQtFTKCZufW.4y+4ygHn5CnkLdW+ZLdO+FTuiGh10dTp22+N3W+cxktVmiOrPqeD0uzCL2d0Qm03xzdleTj2yGAsZvw0f3I+TX4i+YSOFr77egPrR7I8BI6qTsEVhAEclMAkhFqDiEFLHySpH2NAKylZbFT.sX.ilCbAo6xYHNIcGqAcxpQQwBs4Yequ.QQlErTDDLFqDmbl5x4Ikq8Q8wQ6o+wAO+W3rHBxfQuS1ZbkshJXaxweZqPYVDACnRlsotBFAKmbr5nlutkSRekv14mKJfXAxA4Hl22iffKAihXaE3hHHFKFfSRdY.IcmqbzXD8sVSxfXL6UZyVqw77lEURjKDLOqZEysEE15LGai1p5jyh13jw.1bbXMeOWmAAiAUMmPBTcBBxDHFyAVeN+3nx4GW0AZTi4VvBCpp1l0qMliXhAUNaeHsH2ZXwW7qrVIc1yUhSR2AatRam1ZMRnwrcbrN67bypPEnpfLmaS4R.L5ysuLSnlqJV0SFsZ68e1pRhSBClaqDGvrjQaTEvIEjv1JtMCtM.ZvVHvHxSCzcZ0lNJVWVIGMhnSDyVFRbR4kdRy7UR20xPbR5NWasUip1ZoGw1pvMBZagkhnHNs4AGzi0YPubNoChssRsXVSDAaa0Yka8esZdt0xkS60GyraEQ1AV1p90w7sDaMt3s2wJFy.drER6jOdfk5vo4zpZq47V8s1FhA3jtamg3jzczlKb0IKu0Lnz1hws8hwGvetE23kEys21GX67H4FJpfLH9Mcozq2q5tgdW2MD5JtgWHtwa7OnO9a30cR+daaE4jj7GkSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbRRRR6PFhSRRRZGxPbR2VFyeqp4umETEIEDwY+Mez.5j07kydQrcWg5V7wIIocuky66.R6eCHBVFEqYRxfwIA3Fiy1a5HAZLBHown0ohY9sHF3OmljzctLDmzskDXPxf0HgpyfFTchBp7rND0LjXLJFIDi97O2GP6L9lVRRmqLDmzsqQvfERNBpEpVQLJp7xPczY6sckDrREAAMhXEpDZ41xwc1dyKIoyOQUkmbFoaCEPTcHZLnHInphH5b1+yIMuEoJHpSyrUUPDEtcpRR2YZ8AdqdEdoaWArUfACxsXTy.TOQrP24++sucLNxMPL.PPRc++mr03.sF1ANbuCnWT0GXhjPKpgOKxvtydtlYtlyYetSdGOdCvmLukGdKdMQr6yeWJzejYbeOyNyN2yY90ycwa24q6ybrdp.7QSDG7Nbuydel4ZeMKtqY1u4MS804NuNuc9ZlcmyLyY+yz.AfOUVrA3c35+sAA+.eiz+dt6yY976c2wVM.vmMShC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..BRDG..DjHN..HHQb..PPh3..ffDwA..AIhC..B52.jb6F1uogDgC....PRE4DQtJDXBB" ],
					"embed" : 1,
					"forceaspect" : 1,
					"id" : "obj-23",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 879.0, 11.0, 48.0, 46.079999999999998 ],
					"pic" : "/Users/danieleghisi/Downloads/icons.jpg"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -436.57144199999999, 389.0, 81.0, 21.0 ],
					"text" : "offset 0 -5381"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-20",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 460.0, -68.0, 146.0, 22.0 ],
					"text" : "sprintf symout (build %ld)"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 460.0, -95.0, 133.0, 22.0 ],
					"text" : "r bach_getbuildnumber"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-19",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 331.0, -34.0, 72.0, 22.0 ],
					"text" : "prepend set"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-17",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 40.0, -65.0, 251.0, 49.0 ],
					"text" : ";\rbach sendversion bach_getversion;\rbach sendbuildnumber bach_getbuildnumber"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 40.0, -97.0, 60.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 331.0, -132.0, 106.0, 22.0 ],
					"text" : "r bach_getversion"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"linkend" : [ ":,;()[]{}" ],
					"linkstart" : [ "w" ],
					"maxclass" : "bach.hypercomment",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 696.0, 95.0, 131.0, 21.0 ],
					"text" : "www.bachproject.net"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -93.571426000000002, 336.0, 81.0, 21.0 ],
					"text" : "offset 0 -3272"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 250.0, 9.0, 174.0, 19.0 ],
					"text" : "v0.8.0.5 beta (build 1557090826)",
					"textcolor" : [ 0.10980399698019, 0.10980399698019, 0.10980399698019, 1.0 ],
					"varname" : "autohelp_top_digest[3]"
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
					"patching_rect" : [ 16.0, 12.0, 354.0, 52.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Documents/bach_STUFF/logo/Bach_46x319.png"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -174.571426000000002, 336.0, 81.0, 21.0 ],
					"text" : "offset 0 -2628"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-10",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 876.0, 247.0, 259.0, 35.0 ],
					"text" : ";\rmax launchbrowser http://www.bachproject.net"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -244.0, 97.0, 72.0, 22.0 ],
					"text" : "loadmess 0"
				}

			}
, 			{
				"box" : 				{
					"handoff" : "",
					"hidden" : 1,
					"hilite" : 0,
					"id" : "obj-26",
					"maxclass" : "ubutton",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "bang", "bang", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 969.0, 23.0, 92.0, 35.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 552.0, 50.0, 87.0, 31.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-7",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 993.333333333333371, 81.0, 453.0, 35.0 ],
					"text" : ";\rmax launchbrowser http://creativecommons.org/licenses/by-nc-sa/3.0/"
				}

			}
, 			{
				"box" : 				{
					"data" : [ 2779, "", "IBkSG0fBZn....PCIgDQRA...fE...vGHX....vXHq.3....DLmPIQEBHf.B7g.YHB..JHYRDEDUnEX6Z0FaSccF94dsAM5Dd9eaSNHLBso3HshCEnkNZi85VmZoo45k.EZnCalVaWYcIoDBai7kABzXBywqeoMsl30tpVsREluV6Bc3aHnEm3jXynEmerJaTRToZSyAGzTI9i28iqum3archCsczw5izQ2iOe7bO2my64q2i4HhzvwwcU7E3yBvwA.B.3z8bJvyyCdddnRkJvyqBp34AupzO44AGGO343.GGW5pB.h.ABTJBonTHUJoPxjIkdlJIRlLERkJIKuTTJV4IhRSCwheq.1TEaF..b.fjEWUpTIE3UMSbUpjxiWUZQlCbb7YpuoEmzBaJIwLYxzgLimToHmJUJlvloPeqB1TEaFpAfRwUkZnVwSovIO9ofWudwfCNHlJ1TJHZoZVJV25VGL+cLixe3GBISoB77Ij5PRxCNvAo9xY.khjFI.HMFhSRbGwe.34s7fPgBon7FLX.BUJfUu1RKnOtOuvCG.n+7YeGnVsZlnpVsZofJ0nWwyAGOqCLwDSTPMHc5zgF9EMfxJ6dQhjIQxjIPhDoCISfDIRxrvyzR9Cm3Cwy04yiQCMJ..LYxDLZzH..BFLHDEEA.PwFJF6rlchu1W+qly2+U9vOBufqW3yE7roJ1rj.+t8dFnVk5YDV0KBKRsZzRSsBOGyCqBZ0pEBBBPud8nrxJC..81auHRjHviGOXxImjUVAKBn9F1EVxssDjHQBDOQBjHQbjHQBkSYPovUidU7SexmFwhECBBBvoSmPud8JZrQhDA0UWcviGOPiFMnMGsk0G00hcMTyNq8yM7HOOLc19NK0W+mi52e+zPA8SW38BRBVDHHM3kzpUK0ZqsRQiFklKzc2cSZ0pkUuhMTLc996iFJ3Pjug5m5q+yQd66rzYD6gdm+xaSmtmSQm3sONYvfAB.jUqVUvmLOy9cHy8ad7+nhPwFJNm73xoS5Qejs7IhmwFaLxW+8S95ueZrwFqf3A.DO.fpzyAqVkJnVkRKWiFMh.ABfVZoEnUq1rFFjIrZ0JBGNLanzngFEc33HJlKmmsiDoci32meDJTHHHHfF18tmS9keGBBBXzPihQ7Gfk9H9CfQCMJVcokh69tVOK8ecmchm0gCbxSeZrm52MFe7wKHdxr87GdkWAl1v8fp2xVQ0aYqvzFtGbld5YN4ISP84qOx2P9nQtvvjqmyEyxwnQiyqUatPznQIiFMx3w0y6hF4uMBMvv9ny6qOx64krhe628OQFJQx5Mb3vEL+gCGl..YvfAl0h7nfh+FeSZkKWOU12dCzS9iebB.Tqs1JcnCdHB.zQey2rf3Qt83q+9k36NWO8i1tMpgcUOsxkqmV4x0Stb5Lu7jCKXIqXGOqC.HMea2c287Z0lKnUqV30qWVccbHGo2KcZKXtz6olmGgtTHXxjorliylMaLqba1roHO850CSlLoXk8Pgj3o7xKGaZyaFiO933L8zCV4x0i+8TWCa6w1Ftz6+9nxpppf3Qud8HVrXHTfKB.fJD9A324tKzdGGF6s4l..f6t5Nu7HCd.jdXqzVwj2sPs0VKan9MBzpUKb5zI..lXhIvIOwoXGXQRj4XaSKWuG2tcmy3xHW0wnQivwQ5.GxQ630diWGUVUU3CtbD33HcfksrkA2c0MBcoKUP7Hi19URFb+1e+KyR66c+2O..hEKF9nqbk7xCPZAV1ZxqWu.PRbpolZXERTTDVrXAlMaFlMaF1saOu40YmcxxypUqLqXum0aFVubfieFA9yBbm20cg163vXrwFCMrq5QoeqaGu0QOJJ+A2HpdKakMG5bAMZz.WtbgaSyRwK8RuTNKyG+wWeN4P5fFbbfmiCCN3f..PPPfILhhhvrYyJpjnnHDEEQM0TCrXwRV4cgKbAzc2cy3xsa2XvAGT5DfoEVIwURfCFLXVMLqVsxrbsZ0ZV4mq5L6zhEKFNSO8f163vv5krgxevMB.fA74CC3yGJpnh.2hTOm7rH0pQC0WOtskrDVZC3yGK9x0u771d.XVvRevxmPaUqZUrBTWc0A.o4YBGNL750KzqWO1912NyR1nQiHb3v3XG6XJ1iL.XwmJ1TRuGvkwSfRJoDHJJhHQhnngI2AM63.R6AUTTDFLXfklACFxhmexi+Dns8ser5aeUn5srU7AWNBprppP6cbXT811VAwy3iONZs4Vvi9HaAssu8i1129QyM1H..18d1SdaOJDXvAECWyb9D4dFqVsxlLOb3vvpUqr7jO7gff.KOYj4hWRFsJO17ldDoEcj6HKDHWVgJEXoIGOSdZuiCCa6XG3J+y+A96gCCWNch81bSnxppB1Ov9QoqcMyKO11wNfscrC..zcWcgt6pKb8O95Xik+PXqU+n4s8HirGe7eYr9MrdXnDCviGOvlMaYYsNaHe5ohMTrB+.r50VJJ1PwJ3onhJB6s4lvWZIKAiL7v3mUas2P7r2laBe+G3AvkubD.HMpyPIkLm7HCIKXRoWrxb9DYqY2tciImbRDLXPrhUrBX2tcVdxGSNy7jQlCYkNal71imAM0ZSPiFMvsa2vhEKr5PY3ksHQh.KVrfN6rSnQiFryZ1YVeL64W1PN4YW6td7Zuwq+Ihm0r10fJqpJTYUUACkTRAwCPZm83ejAwhW7hwFt66ASEaJX0pUlkjGOdxZgL.ooLpnhJxadx0ut5pCc1YmXoZVJN+esOL8zSioiOMhmHNhGOgjyfRl.Q+WShCZ+fr8RZznQXznQnUqVHJJx5zmOmzbsXWCsePGLmzbyjGlydFX3AvhW7hg8lsCOGyCzpUKhFMJqfhhhvkKWLm4XxjIzRKsv5.b4xEqrYlG.vJVwJPjHQv88cuObDmcfqO8zH9rDXY+FmJYJ3e.+3XG8luaF+zfGl.6an9whVzhw4O24QMOsz9ec5zIpMi4rtQfa2tYmB6.G7.3A23CfoiOMlNdbjHdbDOwrD3b3.9+WFaphMKMGr7U5XxbYPmNc..vtc6Ys0oEBlbxIYqtpSmtzNhO8sXjJERkdtXJ8UNcqJ3A.RQoPxjR2i19aae.PRfrXwhBe7VnXxImDlMalU2F94Mj1A6ImQjy3JiXKxNqEauUAD.nFaoQx+HCRAuX.5w9gOlBOpEHPfEjmtxzSZBVDnfWL.4ejAo8019Xo++QgY9QsOSMzPA7SAuAb3dznQoVasUENbesqaszEdufzPA8SM1Ri2r+PuoDXWauLZpkFQEVDfZ0pwQbbD7puxqxxagdkQ12eqHQhDXfAFDO0S7TX9PlSOHexRhHEmxb1+Ne7ju5H+NJTGMku1zBhiYGZpkFkrjuX.pK2uLoSmtBtGSmNcjqmyEE7hAngB5mdweyKVv0kHZNimYZyGOyW8KDtxUYVnbjkErLp8YpAUuspYW0in2dwIN9Ilyqs+gEdXXxTYrKz73G+D3.1OPAzGKgbYsjYdKDqNNNt79bgfYasN6EgmO9xq.C.r56nTzTKMihVltLtMhLc2HTruU4+3ISL933W0gSbtdO2B9i4SxTC4iG.jk.uPE6b0IUHbLmBrLt2xtWrwx2Hti0bG3qnQS5+5TxuYoWzUiECCOzv3zm7zKXgMyOBVC6SAK3b86Ex7my2ZBepIveAtwAOQzW9lci3VXv8efsp5.NAVz1iC....PRE4DQtJDXBB" ],
					"embed" : 1,
					"hidden" : 1,
					"id" : "obj-82",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 972.0, 26.0, 88.0, 32.0 ],
					"pic" : "Macintosh_HD:/Users/danieleghisi/Documents/Libraries/Max/bach/prove_in_vista_della_0.2/bach_objects/license/cc88x31.png",
					"presentation" : 1,
					"presentation_rect" : [ 551.0, 51.0, 88.0, 32.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -418.57144199999999, 335.0, 81.0, 21.0 ],
					"text" : "offset 0 -4856"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-44",
					"maxclass" : "newobj",
					"numinlets" : 9,
					"numoutlets" : 9,
					"outlettype" : [ "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "" ],
					"patching_rect" : [ -480.0, 285.0, 449.0, 21.0 ],
					"text" : "sel 0 1 2 3 4 5 6 7"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -262.57144199999999, 335.0, 81.0, 21.0 ],
					"text" : "offset 0 -1090"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-51",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -337.57144199999999, 335.0, 81.0, 21.0 ],
					"text" : "offset 0 -3785"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595186999999999,
					"hidden" : 1,
					"id" : "obj-52",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ -480.0, 335.0, 58.0, 21.0 ],
					"text" : "offset 0 0"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 13.0,
					"gradient" : 0.7,
					"htabcolor" : [ 0.640313, 0.730429, 0.465685, 1.0 ],
					"id" : "obj-40",
					"maxclass" : "tab",
					"multiline" : 0,
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 6.0, 131.0, 930.0, 26.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 316.0, 203.0, 556.0, 226.0 ],
					"rounded" : 0.0,
					"spacing_x" : 10.0,
					"spacing_y" : 0.0,
					"tabcolor" : [ 0.337255, 0.45098, 0.156863, 0.058824 ],
					"tabs" : [ "Help Center", "What's new", "Explorer", "Tutorials", "Feedback", "Licence and credits" ],
					"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ],
					"valign" : 2
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 972.0, 156.0, 56.0, 22.0 ],
					"text" : "onecopy"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 66.0, 931.0, 65.0 ],
					"text" : "bach is a suite of Max objects and abstractions for computer-aided composition. At the highest level of the bach system are two interactive notation objects: bach.roll and bach.score, communicating with the rest of the bach system via Lisp-like-linked-lists (lllls for short). lllls are nested lists, allowing for much more complex data structures than standard Max lists. For any information, and to check for updates, visit the official website:                                   .\nIf bach is free, it is also thanks to generous supporters on Patreon. If you can, please help us maintining it and consider                        for as little as 2$/month."
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.94, 0.94, 0.94, 1.0 ],
					"bgmode" : 2,
					"border" : 0,
					"clickthrough" : 0,
					"embed" : 1,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-53",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "bach.overviewswitch.maxpat",
					"numinlets" : 1,
					"numoutlets" : 0,
					"offset" : [ 0.0, 0.0 ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 0,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 519.0, 196.0, 887.0, 624.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-274",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 567.5, 3676.0, 307.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://www.patreon.com/bachproject"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-329",
									"linkend" : [ ":,;()[]{}" ],
									"linkstart" : [ "w" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 284.0, 3628.100586000000476, 183.0, 21.0 ],
									"text" : "www.patreon.com/bachproject"
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-330",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 2.0, 5883.0, 184.0, 22.0 ],
									"text" : "BachEvaluationLanguageForLllls"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-316",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 453.0, 5566.0615234375, 233.0, 51.0 ],
									"text" : "We have a scripting language now, meant to make the implementation of processes in bach easier!"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-315",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5572.60986328125, 427.0, 37.0 ],
									"text" : "bell: bach evaluation language on lllls"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"hidden" : 1,
									"id" : "obj-147",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 114.0, 5868.0, 54.0, 37.0 ],
									"text" : "Lllls"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-129",
									"linecount" : 5,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 220.5, 5481.07861328125, 525.0, 78.0 ],
									"text" : "Yes, we decided to switch to using square brackets by default, but don't worry! ALL backward compatibility is preserved, and you can still go on using round parentheses if you liked them so much – and you can always display round parentheses via bach.textout.\nAlso, our internal llll parsing has been completely rewritten. We have improved some important points, and if you ever are annoyed by backticks, you should definitely read this"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-146",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5487.8232421875, 197.0, 65.0 ],
									"text" : "Lllls have square brackets!"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"id" : "obj-384",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 16.0, 5814.0, 635.0, 40.0 ],
									"text" : "...but this is just the tip of the iceberg. \nAs usual, have a look at the History.txt file to know what else has changed.",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-382",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.0, 5739.314453125, 277.0, 24.0 ],
									"text" : "Now voices can be displayed on the same staff"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-383",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5733.44677734375, 69.0, 37.0 ],
									"text" : "Parts"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-381",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.0, 5778.43212890625, 236.0, 24.0 ],
									"text" : "A brand new system to navigate scores"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-379",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 188.0, 5686.6748046875, 334.0, 51.0 ],
									"text" : "Some modules have been deprecated in favour of new ones, and you'll need to change some of your habits! In exchange for that, your bach life will be easier ;-)"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-378",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.0, 5645.20947265625, 363.0, 51.0 ],
									"text" : "Slots have improved! They support dynamics, articulations, noteheads, lyrics. Also you can use temporal slots in the new \"milliseconds\" mode"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"fontsize" : 12.0,
									"id" : "obj-377",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 125.0, 5618.91064453125, 231.0, 24.0 ],
									"text" : "Yes, we do have REAL pitches now :-)"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-375",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5692.93359375, 156.0, 37.0 ],
									"text" : "NewModules"
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-374",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 193.5, 5860.0, 198.0, 22.0 ],
									"text" : "sprintf symout WhatsNew0.8.1_%s"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-373",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5653.033203125, 67.0, 37.0 ],
									"text" : "Slots"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-371",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5613.1328125, 93.0, 37.0 ],
									"text" : "Pitches"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 25.257102,
									"id" : "obj-370",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.0, 5773.34716796875, 70.0, 37.0 ],
									"text" : "GoTo"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 33.493256000000002,
									"id" : "obj-367",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 16.0, 5398.0, 525.0, 44.0 ],
									"text" : "What's new in bach 0.8.1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"id" : "obj-368",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 16.0, 5442.0, 550.0, 40.0 ],
									"text" : "Here's a collection of things that you need to know when upgrading to bach 0.8.1\nClick on each message to open the corresponding scrolldown primer!",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-362",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 193.5, 5891.0, 81.0, 22.0 ],
									"text" : "prepend load"
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-335",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 193.5, 5923.0, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-145",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 171.0, 3648.0, 453.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://creativecommons.org/licenses/by-nc-sa/3.0/"
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-134",
									"linecount" : 8,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 918.0, 3656.0, 261.0, 116.0 ],
									"text" : ";\rmax launchbrowser https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=ANCMP3NUGY8C6&lc=US&item_name=bach%3a%20automated%20composer%27s%20helper&currency_code=EUR&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 14.0,
									"hidden" : 1,
									"id" : "obj-144",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 918.0, 3625.201172000000042, 110.0, 24.798828 ],
									"text" : "Donate now!",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-132",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 222.0, 3584.899413999999979, 77.0, 35.0 ],
									"text" : ";\rbach donors"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 14.0,
									"id" : "obj-124",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 222.0, 3554.100586000000021, 110.0, 24.798828 ],
									"text" : "bach donors",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-123",
									"linecount" : 6,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 3556.0, 903.0, 94.0 ],
									"text" : "bach would also like to thank all the                                 , as well as all the other people who have donated money to the project.\n\nDiscover all donors by sending the                          message (donors are credited for donations greater than or equal to 50€).\n\n\nPlease consider supporting us on Patreon: visit ",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-93",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 620.5, 3534.0, 229.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://www.smufl.org/"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-61",
									"linkend" : [ ":", "\u003b", "\u002c", "(", ")", "[", "]", "{", "}" ],
									"linkstart" : [ "S" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 376.0, 3452.0, 55.0, 21.0 ],
									"text" : "SMUFL",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-56",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 641.5, 3502.0, 370.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://www.klemm-music.de/notation/november/"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-58",
									"linkend" : [ ":", "\u003b", "\u002c", "(", ")", "[", "]", "{", "}" ],
									"linkstart" : [ "w" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 310.5, 3466.0, 275.0, 21.0 ],
									"text" : "www.klemm-music.de/notation/november/",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-59",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 600.0, 3596.0, 287.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://www.poeticprocessing.net"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-60",
									"linkend" : [ ":", "\u003b", "\u002c", "(", ")", "[", "]", "{", "}" ],
									"linkstart" : [ "w" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 439.5, 3408.0, 185.0, 21.0 ],
									"text" : "www.poeticprocessing.net",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "panel",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 966.631591999999955, 128.0, 128.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"enablehscroll" : 0,
									"enablevscroll" : 0,
									"id" : "obj-53",
									"lockeddragscroll" : 0,
									"maxclass" : "bpatcher",
									"name" : "bach.explorer.maxpat",
									"numinlets" : 0,
									"numoutlets" : 0,
									"offset" : [ 0.0, 0.0 ],
									"patching_rect" : [ 2.0, 4856.625, 962.0, 476.0 ],
									"viewvisibility" : 1
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-28",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1463.631591999999955, 81.0, 19.0 ],
									"text" : "Series",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-29",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 257.0, 1481.0, 114.0, 57.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 257.0, 1442.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.arithmser", "bach.geomser", "bach.primeser" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-38",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1480.0, 114.0, 58.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-52",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1464.0, 125.0, 74.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-57",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 575.0, 3770.0, 43.0, 22.0 ],
									"text" : "set $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-54",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 303.0, 4083.063477000000148, 86.0, 20.0 ],
									"text" : "Sections:",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ],
									"textjustification" : 2
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-55",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 389.0, 4083.0634765625, 525.0, 20.0 ],
									"text" : "13",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-51",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 602.0, 4322.063476999999693, 39.0, 22.0 ],
									"text" : "zl rev"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 602.0, 4290.0, 55.0, 22.0 ],
									"text" : "pack s s"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-42",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 602.0, 4258.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 602.0, 4358.537108999999873, 142.0, 22.0 ],
									"text" : "sprintf symout \"%s (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.0, 4394.0, 81.0, 22.0 ],
									"text" : "prepend load"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.0, 4417.0, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-30",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 303.0, 4103.063476999999693, 86.0, 20.0 ],
									"text" : "Topics:",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ],
									"textjustification" : 2
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-14",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 389.0, 4103.0634765625, 522.0, 20.0 ],
									"text" : "displaying lllls, creating lllls, modifying lllls, handling lllls",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 790.0, 3745.0, 74.0, 22.0 ],
									"text" : "prepend set"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ -307.499969000000021, 3867.0, 69.0, 22.0 ],
									"text" : "delay 1500"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-133",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 0,
											"revision" : 4,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 50.0, 94.0, 640.0, 480.0 ],
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
										"boxes" : [ 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-10",
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 190.929687999999999, 163.0, 103.0, 21.0 ],
													"text" : "bach.replace 96"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 226.929687999999999, 327.0, 73.0, 20.0 ],
													"text" : "fromsymbol"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 190.929687999999999, 327.0, 32.5, 18.0 ],
													"text" : "set"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "bang", "" ],
													"patching_rect" : [ 190.929687999999999, 289.0, 55.0, 20.0 ],
													"text" : "sel null"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-38",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 336.929687999999999, 100.0, 102.0, 21.0 ],
													"text" : "loadmess 44 32"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-37",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 236.929687999999999, 100.0, 84.0, 21.0 ],
													"text" : "loadmess 32"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-29",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "bang" ],
													"patching_rect" : [ 190.929687999999999, 191.0, 117.0, 21.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.portal @out t"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-27",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 226.929687999999999, 361.861205999999981, 79.0, 21.0 ],
													"text" : "prepend set"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-19",
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 190.929687999999999, 129.0, 139.0, 21.0 ],
													"text" : "bach.replace 32 44 32"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 190.929687999999999, 260.0, 46.0, 21.0 ],
													"text" : "itoa"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 13.0,
													"id" : "obj-16",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "list" ],
													"patching_rect" : [ 190.929687999999999, 79.0, 46.0, 21.0 ],
													"text" : "atoi"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-39",
													"index" : 1,
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 190.929687999999999, 40.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-40",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 190.929687999999999, 420.861205999999981, 25.0, 25.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-2", 0 ],
													"source" : [ "obj-1", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 0 ],
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-19", 0 ],
													"source" : [ "obj-16", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-1", 0 ],
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 0 ],
													"source" : [ "obj-19", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-27", 0 ],
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"source" : [ "obj-27", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-29", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-19", 1 ],
													"source" : [ "obj-37", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-19", 2 ],
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-16", 0 ],
													"source" : [ "obj-39", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 687.0, 3745.0, 58.0, 23.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p format"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-125",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 445.0, 4322.063476999999693, 81.0, 22.0 ],
									"text" : "prepend help"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-128",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 445.0, 4347.063476999999693, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"drop" : 0,
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-122",
									"linecount" : 2,
									"linkend" : [ " ", "\u002c" ],
									"linkstart" : [ "b" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 389.0, 4163.063476999999693, 525.0, 33.0 ],
									"text" : "bach.tree, bach.print, bach.portal, bach.reg, bach.length, bach.depth, bach.nth, bach.find, bach.filternull, bach.roll, bach.score",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-121",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 303.0, 4163.063476999999693, 86.0, 20.0 ],
									"text" : "Elements:",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ],
									"textjustification" : 2
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-119",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ -307.499969000000021, 3938.0, 44.0, 22.0 ],
									"text" : "click 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-91",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 0,
											"revision" : 4,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
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
										"boxes" : [ 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-59",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 56.0, 293.0, 98.0, 20.0 ],
													"text" : "prepend append"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-58",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "clear" ],
													"patching_rect" : [ 56.0, 206.0, 49.0, 20.0 ],
													"text" : "t l clear"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-57",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 3,
													"outlettype" : [ "", "", "" ],
													"patching_rect" : [ 56.0, 233.0, 101.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.iter @out tx"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-54",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 56.0, 266.0, 46.0, 20.0 ],
													"text" : "itoa"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-53",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 157.0, 64.0, 20.0 ],
													"text" : "bach.+ 96"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-52",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 100.0, 32.5, 18.0 ],
													"text" : "1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-47",
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 126.0, 90.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.arithmser"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-60",
													"index" : 1,
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 94.0, 44.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-61",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 51.0, 373.0, 25.0, 25.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-53", 0 ],
													"source" : [ "obj-47", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-47", 0 ],
													"source" : [ "obj-52", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-58", 0 ],
													"source" : [ "obj-53", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-59", 0 ],
													"source" : [ "obj-54", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-54", 0 ],
													"source" : [ "obj-57", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-57", 0 ],
													"source" : [ "obj-58", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-61", 0 ],
													"source" : [ "obj-58", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-61", 0 ],
													"source" : [ "obj-59", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-47", 1 ],
													"order" : 0,
													"source" : [ "obj-60", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-52", 0 ],
													"order" : 1,
													"source" : [ "obj-60", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 587.5, 3745.0, 89.0, 22.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p build_umenu"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-46",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 389.0, 3864.0, 471.0, 47.0 ],
									"text" : "In this tutorial you'll move your first steps with the Lisp-like linked lists (lllls for short), which are the standard communication mechanism throughout all the bach environment",
									"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-45",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 296.0, 4290.0, 74.0, 22.0 ],
									"text" : "prepend set"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"patching_rect" : [ 296.0, 4258.0, 109.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 70911
									}
,
									"text" : "bach.portal @out t"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-43",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 519.0, 3745.0, 74.0, 22.0 ],
									"text" : "prepend set"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 33.493256000000002,
									"id" : "obj-41",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 389.0, 3795.0, 525.0, 44.0 ],
									"text" : "Hello World"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 33.493256000000002,
									"id" : "obj-40",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 362.0, 3795.0, 36.0, 44.0 ],
									"text" : "–"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 33.493256000000002,
									"id" : "obj-39",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 288.0, 3795.0, 74.0, 44.0 ],
									"text" : "1",
									"textjustification" : 2
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 450.5, 3745.0, 74.0, 22.0 ],
									"text" : "prepend set"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 382.0, 3745.0, 74.0, 22.0 ],
									"text" : "prepend set"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 7,
									"outlettype" : [ "", "", "", "", "", "", "bang" ],
									"patching_rect" : [ 382.0, 3715.0, 372.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 70911
									}
,
									"text" : "bach.keys digest description title numsections seealso topics @out t"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 382.0, 3689.0, 75.0, 22.0 ],
									"text" : "bach.lookup"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"id" : "obj-25",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 2.0, 3795.0, 80.0, 23.0 ],
									"text" : "Tutorials"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"id" : "obj-17",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 661.0, 4216.600585999999566, 169.0, 23.0 ],
									"text" : "or go directly to section:"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 15.0,
									"id" : "obj-19",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 389.0, 4210.201172000000042, 263.0, 35.798828 ],
									"text" : "Start tutorial from the beginning",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"id" : "obj-20",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 389.0, 3839.0, 525.0, 23.0 ],
									"text" : "First steps with the bach nested lists (lllls)",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"fontsize" : 15.0,
									"id" : "obj-21",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 830.0, 4216.600585999999566, 81.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ -290.499969000000021, 3782.899902000000111, 32.5, 22.0 ],
									"text" : "t l l"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "bang" ],
									"patching_rect" : [ -307.499969000000021, 3721.899902000000111, 53.0, 23.0 ],
									"text" : "t b b b"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ -307.499969000000021, 3694.899902000000111, 145.0, 22.0 ],
									"text" : "loadmess bang @defer 1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 0,
											"revision" : 4,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 561.0, 44.0, 337.0, 212.0 ],
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
										"boxes" : [ 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-1",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 75.5, 181.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-4",
													"index" : 1,
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 75.5, 52.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-6",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 4,
													"outlettype" : [ "dictionary", "", "", "" ],
													"patching_rect" : [ 75.5, 92.125, 204.0, 20.0 ],
													"saved_object_attributes" : 													{
														"embed" : 0,
														"parameter_enable" : 0,
														"parameter_mappable" : 0
													}
,
													"text" : "dict bach.tutorials bach.tutorials.json"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-12",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.5, 122.0, 76.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.dict2llll"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-1", 0 ],
													"source" : [ "obj-12", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-6", 0 ],
													"source" : [ "obj-4", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-12", 0 ],
													"source" : [ "obj-6", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ -290.499969000000021, 3754.399902000000111, 111.0, 23.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p gettutorialdictllll"
								}

							}
, 							{
								"box" : 								{
									"hidden" : 1,
									"id" : "obj-22",
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ -307.499969000000021, 3669.899902000000111, 20.0, 20.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 0,
											"revision" : 4,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 661.0, 44.0, 644.0, 654.0 ],
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
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-8",
													"maxclass" : "button",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"parameter_enable" : 0,
													"patching_rect" : [ 149.0, 441.0, 20.0, 20.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-4",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 149.0, 464.0, 32.5, 20.0 ],
													"text" : "int"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 149.0, 486.0, 136.0, 20.0 ],
													"text" : "sprintf symout %d – %s"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-2",
													"index" : 1,
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 57.5, 11.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-33",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 227.0, 409.0, 32.5, 20.0 ],
													"text" : "t l l"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-31",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "bang" ],
													"patching_rect" : [ 227.0, 435.0, 125.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.keys title @out t"
												}

											}
, 											{
												"box" : 												{
													"comment" : "The help dictionary in llll form",
													"id" : "obj-21",
													"index" : 2,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 247.25, 596.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-16",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 3,
													"outlettype" : [ "bang", "", "" ],
													"patching_rect" : [ 57.5, 46.0, 46.0, 20.0 ],
													"text" : "t b l l"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-11",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 71.0, 104.0, 32.5, 20.0 ],
													"text" : "t l l"
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
													"patching_rect" : [ 71.0, 195.0, 44.0, 20.0 ],
													"text" : "gate 2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-9",
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 12.5, 528.0, 361.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.collect 2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-7",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 105.5, 165.0, 109.0, 20.0 ],
													"text" : "expr ($i1 == 3) + 1"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 105.5, 138.0, 70.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.depth"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 3,
													"outlettype" : [ "", "", "" ],
													"patching_rect" : [ 71.0, 76.0, 184.0, 20.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 70911
													}
,
													"text" : "bach.iter @maxdepth -3 @out nt"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-17",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 17.5, 596.0, 25.0, 25.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-11", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 1 ],
													"source" : [ "obj-1", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 3 ],
													"source" : [ "obj-1", 2 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-33", 0 ],
													"source" : [ "obj-10", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 2 ],
													"order" : 0,
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 1 ],
													"order" : 1,
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 1 ],
													"source" : [ "obj-11", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"source" : [ "obj-11", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-1", 0 ],
													"source" : [ "obj-16", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"source" : [ "obj-16", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-16", 0 ],
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 1 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 1 ],
													"order" : 0,
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-8", 0 ],
													"order" : 1,
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-31", 0 ],
													"source" : [ "obj-33", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 2 ],
													"source" : [ "obj-33", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"source" : [ "obj-4", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-7", 0 ],
													"source" : [ "obj-5", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 0 ],
													"source" : [ "obj-7", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 0 ],
													"source" : [ "obj-8", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-9", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-21", 0 ],
													"source" : [ "obj-9", 1 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ -290.499969000000021, 3815.899902000000111, 87.0, 23.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p helpllll2tree"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"hidden" : 1,
									"id" : "obj-7",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 308.0, -126.375, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595186999999999,
									"hidden" : 1,
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 308.0, -97.375, 67.0, 21.0 ],
									"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
									"text" : "thispatcher"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"hidden" : 1,
									"id" : "obj-360",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 53.0, -30.375, 140.0, 23.0 ],
									"text" : "loadmess all @defer 1"
								}

							}
, 							{
								"box" : 								{
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"enablehscroll" : 0,
									"enablevscroll" : 0,
									"id" : "obj-361",
									"lockeddragscroll" : 0,
									"maxclass" : "bpatcher",
									"name" : "bach.help.home.maxpat",
									"numinlets" : 1,
									"numoutlets" : 0,
									"offset" : [ 0.0, 0.0 ],
									"patching_rect" : [ 2.0, -0.375, 962.0, 476.0 ],
									"viewvisibility" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-270",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 814.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-271",
									"items" : [ "(Seen", "elements:)", ",", "bach.constraints", ",", "bach.group", ",", "bach.cartesianprod", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- constraint satisfaction problems", ",", "- threading", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.==", ",", "bach.!=", ",", "bach.join", ",", "bach.arithmser", ",", "bach.beatbox", ",", "bach.belong", ",", "bach.comb", ",", "bach.expr", ",", "bach.ezmidiplay", ",", "bach.filternull", ",", "bach.flat", ",", "bach.iter", ",", "bach.keys", ",", "bach.lace", ",", "bach.mean", ",", "bach.pick", ",", "bach.post", ",", "bach.print", ",", "bach.repeat", ",", "bach.roll", ",", "bach.score", ",", "bach.slice", ",", "bach.trans", ",", "bach.urn", ",", "bach.wrap" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 814.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-272",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 818.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-273",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 814.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-354",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 144.0, 814.536986999999954, 275.0, 20.0 ],
									"text" : "- how to deal with constraint satisfaction problems"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-355",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 814.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-356",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 817.536986999999954, 250.0, 22.0 ],
									"text" : "sprintf symout \"God Solve The Queens (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-357",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 814.536986999999954, 149.0, 20.0 ],
									"text" : "God Solve The Queens"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-346",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 909.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-347",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "bach.score", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- undo system", ",", "- lock, mute, solo", ",", "- copy/paste", ",", "- snapping to pitch grid", ",", "- snapping to temporal grid", ",", "- prevent editing" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 909.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-348",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 913.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-349",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 909.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-350",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 67.0, 909.536986999999954, 345.0, 20.0 ],
									"text" : "- discover how to customize or prevent editing"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-351",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 909.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-352",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 912.536986999999954, 174.0, 22.0 ],
									"text" : "sprintf symout \"Edit Path (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-353",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 909.536986999999954, 63.0, 20.0 ],
									"text" : "Edit Path"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-338",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 738.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-339",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "bach.roll", ",", "bach.omtree2bachtree", ",", "bach.bachtree2omtree", ",", "<separator>", ",", "(Technical", "topics:)", ",", "- MusicXML import/export", ",", "- MIDI import/export", ",", "- Communication with OpenMusic", ",", "- Communication with PWGL", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.wrap", ",", "bach.print" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 738.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-340",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 745.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-341",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 738.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-342",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 119.0, 738.536986999999954, 345.0, 20.0 ],
									"text" : "- import, export and communication with other softwares"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-343",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 738.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-344",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 745.0, 225.0, 22.0 ],
									"text" : "sprintf symout \"The World Outside (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-345",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 738.536986999999954, 161.0, 20.0 ],
									"text" : "The World Outside"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-136",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 682.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-137",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- bach inspector" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 682.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-138",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 689.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-139",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 682.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-140",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 141.0, 682.536986999999954, 342.0, 20.0 ],
									"text" : "- meet the bach-specific inspector"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-141",
									"items" : [ "a", ",", "b", ",", "c" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 682.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-142",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 689.0, 244.0, 22.0 ],
									"text" : "sprintf symout \"Inspector As A Gadget (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-143",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 682.536986999999954, 139.0, 20.0 ],
									"text" : "Inspector As A Gadget"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-4",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 795.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-23",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "<separator>", ",", "(Technical", "topics:)", ",", "- rhythmic trees", ",", "- grace notes", ",", "- inspector for grace notes", ",", "- linear edit for grace notes", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.print", ",", "bach.beatbox", ",", "bach.ezmidiplay", ",", "bach.wrap" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 795.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-34",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 799.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-68",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 795.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-96",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.0, 795.536986999999954, 345.0, 20.0 ],
									"text" : "- how to get the grace notes handling simple"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-97",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 795.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-98",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 799.0, 210.0, 22.0 ],
									"text" : "sprintf symout \"A Mazing Grace (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-103",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 795.536986999999954, 133.0, 20.0 ],
									"text" : "A Mazing Grace"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-104",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 776.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-105",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "<separator>", ",", "(Technical", "topics:)", ",", "- rhythmic trees", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.wrap", ",", "bach.tree", ",", "bach.print", ",", "bach.slice" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 776.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-106",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 783.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-111",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 776.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-112",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 162.0, 776.536986999999954, 345.0, 20.0 ],
									"text" : "- handle beams and tuplets finely with rhythmic trees"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-126",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p", ",", "q" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 776.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-130",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 783.0, 267.0, 22.0 ],
									"text" : "sprintf symout \"Beams Through The Trees (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-131",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 776.536986999999954, 161.0, 20.0 ],
									"text" : "Beams Through The Trees"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-69",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1249.631591999999955, 117.0, 19.0 ],
									"text" : "Conversions",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-70",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 401.0, 1268.0, 140.0, 77.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 405.0, 766.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.mc2n", "bach.n2mc", "bach.bachtree2omtree", "bach.omtree2bachtree" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-71",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1266.0, 139.0, 82.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-79",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1250.0, 143.0, 102.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-265",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 519.0, 1568.631591999999955, 120.0, 19.0 ],
									"text" : "Musical set theory",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-266",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 519.0, 1586.0, 109.0, 173.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 508.0, 1358.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.mod+", "bach.mod-", "bach.modtimes", "bach.pcsetinfo", "bach.mc2pc", "bach.pc2mc", "bach.compl", "bach.istruct", "bach.ifunc" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-267",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 519.0, 1585.0, 110.0, 174.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-269",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 519.0, 1569.0, 122.0, 190.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-173",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 650.0, 1568.631591999999955, 117.0, 19.0 ],
									"text" : "Matrix calculus",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-177",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 650.0, 1586.0, 121.0, 319.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 510.0, 1045.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.det", "bach.rank", "bach.inv", "bach.mrandom", "bach.idmatrix", "bach.idvector", "bach.ker", "bach.im", "bach.wellshape", "bach.mpow", "bach.m2jitcellblock", "bach.m2matrixctrl", "bach.matrixctrl2m", "bach.getrow", "bach.getcol", "bach.norm", "bach.normalize" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-262",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 650.0, 1585.0, 122.0, 321.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-263",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 650.0, 1569.0, 134.0, 337.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-107",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 368.0, 1568.631591999999955, 117.0, 19.0 ],
									"text" : "Music data handling",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-108",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 368.0, 1586.0, 130.0, 419.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 362.0, 1046.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.unpacknote", "bach.mc2f", "bach.f2mc", "bach.score2roll", "bach.chordrev", "bach.chordrot", "bach.restrot", "bach.tierev", "bach.fromc&r", "bach.toc&r", "bach.slot2line", "bach.slot2curve", "bach.slot2function", "bach.slot2filtercoeff", "bach.dl2line", "bach.dl2curve", "bach.mcapprox", "bach.sliceheader", "bach.mono", "bach.combinevoices", "bach.transcribe", "bach.ezmidiplay" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-109",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 368.0, 1585.0, 129.0, 421.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-110",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 368.0, 1569.0, 143.0, 437.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-86",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 235.0, 1699.631591999999955, 113.0, 19.0 ],
									"text" : "Elements",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-87",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 235.0, 1717.0, 118.0, 108.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 371.0, 1150.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.replace", "bach.lookup", "bach.random", "bach.wrandom", "bach.urn", "bach.wurn" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-101",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 235.0, 1716.0, 118.0, 109.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-102",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 235.0, 1700.0, 125.0, 125.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-82",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 518.0, 1765.631591999999955, 108.0, 19.0 ],
									"text" : "More llll utilities",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-83",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 518.0, 1783.0, 111.0, 204.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 234.0, 1137.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.prepend", "bach.repeat", "bach.mapelem", "bach.change", "bach.period", "bach.belong", "bach.nearest", "bach.counter", "bach.pad", "bach.dict2llll", "bach.split" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-84",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 518.0, 1782.0, 112.0, 205.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-85",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 518.0, 1766.0, 123.0, 221.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-76",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 236.0, 1568.631591999999955, 108.0, 19.0 ],
									"text" : "Iterate and filter",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-77",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 236.0, 1586.0, 110.0, 106.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 234.0, 1046.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.filter", "bach.filternull", "bach.sieve", "bach.drip", "bach.randomdrip", "bach.dsort" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-80",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 236.0, 1585.0, 110.0, 108.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-81",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 236.0, 1569.0, 124.0, 126.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-72",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1884.631591999999955, 108.0, 19.0 ],
									"text" : "Statistics",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-73",
									"maxclass" : "tab",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 1902.0, 208.0, 73.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 7.0, 1317.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.mean", "bach.median", "bach.variance", "bach.stdev", "bach.skewness", "bach.kurtosis", "bach.histo" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-74",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1901.0, 208.0, 75.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-75",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1885.0, 222.0, 91.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-5",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1568.631591999999955, 131.0, 19.0 ],
									"text" : "Mathematics",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-65",
									"maxclass" : "tab",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 1586.0, 214.0, 292.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 7.0, 1031.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.+", "bach.-", "bach.*", "bach./", "bach.!-", "bach.!/", "bach.%", "bach.pow", "bach.abs", "bach.clip", "bach.minimum", "bach.maximum", "bach.sum", "bach.prod", "bach.fact", "bach.bin", "bach.coprime", "bach.coprimeser", "bach.bitdecode", "bach.interp", "bach.scale", "bach.autoscale", "bach.gcd", "bach.lcm", "bach.x2dx", "bach.dx2x", "bach.cartopol", "bach.poltocar", "bach.round", "bach.fft" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.078431 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-66",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1585.0, 214.0, 293.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.490196, 0.266667, 0.266667, 0.035294 ],
									"bordercolor" : [ 0.623529, 0.4, 0.25098, 1.0 ],
									"hidden" : 1,
									"id" : "obj-67",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1569.0, 222.0, 309.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-325",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1299.631591999999955, 117.0, 19.0 ],
									"text" : "Miscellanea",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-326",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 558.0, 1317.0, 108.0, 107.631591999999998 ],
									"presentation" : 1,
									"presentation_rect" : [ 524.0, 781.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.shelf", "bach.write", "bach.read", "bach.pipe", "bach.defer", "bach.deferlow" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-327",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1316.0, 108.0, 108.631591999999998 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-328",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1300.0, 117.0, 124.631591999999998 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-321",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1357.631591999999955, 117.0, 19.0 ],
									"text" : "Musical set theory",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-322",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 401.0, 1375.0, 104.0, 92.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 399.0, 771.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.circle", "bach.primeform", "bach.ivec", "bach.zsearch", "bach.tonnetz" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-323",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1374.0, 105.0, 93.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-324",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1358.0, 117.0, 109.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-317",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1094.631591999999955, 117.0, 19.0 ],
									"text" : "Matrix calculus",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-318",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 558.0, 1112.0, 121.0, 183.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 399.0, 772.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.minfo", "bach.diag", "bach.trace", "bach.submatrix", "bach.mtimes", "bach.eig", "bach.gausselim", "bach.linearsolve", "bach.adj", "bach.extractbasis" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-319",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1111.0, 122.0, 183.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-320",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 558.0, 1095.0, 134.0, 199.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-282",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1390.631591999999955, 81.0, 19.0 ],
									"text" : "Comparisons",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-277",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1279.631591999999955, 73.0, 19.0 ],
									"text" : "List content",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-290",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1317.631591999999955, 115.0, 19.0 ],
									"text" : "Elements",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-286",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 130.0, 1094.631591999999955, 118.0, 19.0 ],
									"text" : "llll operations",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-64",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1094.631591999999955, 131.0, 19.0 ],
									"text" : "Do (almost) nothing",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-311",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1169.631591999999955, 117.0, 19.0 ],
									"text" : "Music data handling",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-312",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 401.0, 1187.0, 106.0, 53.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 399.0, 708.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.quantize", "bach.beatbox", "bach.beatunbox" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-313",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1186.0, 107.0, 55.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-314",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1170.0, 119.0, 74.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-307",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1094.631591999999955, 117.0, 19.0 ],
									"text" : "Music notation",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-308",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 401.0, 1112.0, 107.0, 49.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 399.0, 576.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.roll", "bach.score", "bach.slot" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-309",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1111.0, 107.0, 51.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-310",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 401.0, 1095.0, 119.0, 67.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-303",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1316.631591999999955, 81.0, 19.0 ],
									"text" : "Mathematics",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-304",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 257.0, 1334.0, 114.0, 124.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 259.0, 796.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.ratnum", "bach.prime", "bach.factorize", "bach.expr", "bach.float2rat", "bach.graph", "bach.weights" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-305",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1334.0, 114.0, 124.368408000000002 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-306",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1317.0, 125.0, 141.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-302",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1204.0, 81.0, 19.0 ],
									"text" : "Sets",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-299",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 257.0, 1221.368408000000045, 117.0, 87.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 259.0, 707.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.union", "bach.intersection", "bach.diff", "bach.symdiff", "bach.cartesianprod" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-300",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1220.368408000000045, 117.0, 88.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-301",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1204.368408000000045, 130.0, 106.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-295",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1094.631591999999955, 136.0, 19.0 ],
									"text" : "Sort and combinatorial",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-296",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 257.0, 1112.0, 115.0, 86.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 257.0, 576.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.sort", "bach.perm", "bach.scramble", "bach.comb", "bach.constraints" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-297",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1111.0, 115.0, 87.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-298",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 1095.0, 130.0, 103.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Arial",
									"fontsize" : 11.0,
									"id" : "obj-294",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1414.631591999999955, 108.0, 19.0 ],
									"text" : "Iterate and search",
									"textcolor" : [ 0.337255001068115, 0.450980007648468, 0.156863003969193, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-291",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 129.0, 1432.0, 97.0, 101.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 134.0, 865.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.iter", "bach.step", "bach.collect", "bach.find", "bach.keys", "bach.thin" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-292",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1431.0, 97.0, 103.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-293",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1415.0, 111.0, 119.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-287",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 129.0, 1335.0, 97.0, 70.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 134.0, 759.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.nth", "bach.subs", "bach.insert", "bach.pick" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-288",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1334.0, 98.0, 71.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-289",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 129.0, 1318.0, 112.0, 87.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-283",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 130.0, 1112.0, 95.0, 188.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 141.0, 576.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.rev", "bach.rot", "bach.wrap", "bach.flat", "bach.join", "bach.slice", "bach.lace", "bach.delace", "bach.trans", "bach.group", "bach.reshape" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-284",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 130.0, 1111.0, 95.0, 193.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-285",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 130.0, 1095.0, 111.0, 209.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-279",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 1408.0, 83.0, 102.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 135.0, 691.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.==", "bach.!=", "bach.<", "bach.<=", "bach.>", "bach.>=" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-280",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1407.0, 81.0, 102.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-281",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1391.0, 94.0, 120.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-62",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 1112.0, 83.0, 153.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 68.0, 552.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.reg", "bach.portal", "bach.args", "bach.print", "bach.post", "bach.tree", "bach.value", "bach.pv", "bach.shelf" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"button" : 1,
									"htabcolor" : [ 0.333333, 0.482353, 0.482353, 0.0 ],
									"id" : "obj-278",
									"maxclass" : "tab",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 1297.0, 97.0, 84.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 135.0, 576.0, 556.0, 226.0 ],
									"spacing_x" : 10.0,
									"tabcolor" : [ 0.517647, 0.415686, 0.160784, 0.0 ],
									"tabs" : [ "bach.is", "bach.contains", "bach.length", "bach.depth", "bach.minmax" ],
									"textcolor" : [ 0.2, 0.2, 0.2, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-264",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1111.0, 83.0, 157.631592000000012 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.337255, 0.45098, 0.156863, 0.121569 ],
									"border" : 1,
									"bordercolor" : [ 0.337255, 0.45098, 0.156863, 1.0 ],
									"id" : "obj-276",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1296.0, 98.0, 86.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-275",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1280.0, 112.0, 102.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"bgcolor" : [ 0.25098, 0.360784, 0.623529, 0.035294 ],
									"bordercolor" : [ 0.25098, 0.360784, 0.623529, 1.0 ],
									"hidden" : 1,
									"id" : "obj-268",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 1095.0, 112.0, 173.631592000000012 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-220",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 889.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-224",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- filter and dynfilter slots", ",", "- dumpselection message", ",", "- changeslotvalue message", ",", "- lambda message", ",", "- using command", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.unpacknote", ",", "bach.keys", ",", "bach.keys", ",", "bach.reg", ",", "bach.slice", ",", "bach.nth", ",", "bach.print", ",", "bach.mc2f" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 889.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-225",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 893.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-229",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 889.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-236",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 133.0, 889.536986999999954, 345.0, 20.0 ],
									"text" : "- meet the filter and dynfilter slots"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-243",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 889.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-250",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 892.536986999999954, 236.0, 22.0 ],
									"text" : "sprintf symout \"Filter Filter Little Star (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-257",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 889.536986999999954, 131.0, 20.0 ],
									"text" : "Filter Filter Little Star"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-201",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 651.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-203",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 651.0, 200.0, 22.0 ],
									"text" : "sprintf symout \"Slot Machines (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-194",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 644.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-195",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "bach.tree", ",", "bach.keys", ",", "bach.slot2curve", ",", "bach.slot2line", ",", "bach.filternull", ",", "bach.m2matrixctrl", ",", "bach.score", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- defining the slotinfo", ",", "- interface for slots", ",", "- dealing with slots", ",", "- modifying slot values", ",", "- slots in background", ",", "- using commands", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.print", ",", "bach.unpacknote", ",", "bach.join", ",", "bach.pick", ",", "bach.nth", ",", "bach.iter", ",", "bach.collect", ",", "bach.flat", ",", "bach.wrap" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 644.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-196",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 644.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-197",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 96.0, 644.536986999999954, 263.0, 20.0 ],
									"text" : "- discovering the magical world of slots"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-198",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p", ",", "q", ",", "r", ",", "s", ",", "t", ",", "u", ",", "v", ",", "w", ",", "x" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 644.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-200",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 644.536986999999954, 170.0, 20.0 ],
									"text" : "Slot Machines"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-193",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 870.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-192",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 851.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-191",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 757.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-187",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 833.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-188",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 719.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-189",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 700.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-190",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 663.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-185",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 626.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-186",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 607.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-184",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 588.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-181",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 0,
											"revision" : 4,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 50.0, 94.0, 250.0, 160.0 ],
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
										"boxes" : [ 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-16",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 52.0, 92.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-12",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 52.0, 67.0, 125.0, 20.0 ],
													"text" : "sprintf symout %s.%s"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-3",
													"index" : 1,
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 27.0, 15.0, 25.0, 25.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 11.595186999999999,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 5,
													"outlettype" : [ "", "", "", "", "" ],
													"patching_rect" : [ 27.0, 44.0, 117.0, 20.0 ],
													"text" : "regexp (\\\\w+)\\\\.(\\\\S+)"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-12", 0 ],
													"source" : [ "obj-1", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-16", 0 ],
													"source" : [ "obj-12", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-1", 0 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 700.0, 935.0, 143.0, 22.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"tags" : ""
									}
,
									"text" : "p only_take_bach_things"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-179",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 700.0, 958.0, 81.0, 22.0 ],
									"text" : "prepend help"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-178",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "bach.read", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- zooming interface commands", ",", "- querying length, domain, pixels", ",", "- synchronizing roll and bpatcher", ",", "- roll notifications", ",", "- the done notification", ",", "- read and write messages", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.keys", ",", "bach.iter", ",", "bach.filter", ",", "bach.flat", ",", "bach.slice", ",", "bach.rot", ",", "bach.expr", ",", "bach.filternull", ",", "bach.mc2f", ",", "bach.f2mc", ",", "bach.join", ",", "bach.reg", ",", "bach.collect", ",", "bach.ezmidiplay", ",", "bach.mcapprox" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 870.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-176",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- using commands", ",", "- using lambda messages", ",", "- dumpselection message", ",", "- changeslotvalue message", ",", "- changing background slots fontsize", ",", "- continuous bangs while mousedragging", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.unpacknote", ",", "bach.mc2f", ",", "bach.-", ",", "bach.abs", ",", "bach.minmax" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 851.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-174",
									"items" : [ "(Seen", "elements:)", ",", "bach.portal", ",", "bach.args", ",", "<separator>", ",", "(Technical", "topics:)", ",", "- out argument and subpatches", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.rev", ",", "bach.join", ",", "bach.clear", ",", "bach.sliceheader", ",", "bach.iter", ",", "bach.slice", ",", "bach.filter", ",", "bach.mc2f", ",", "bach.f2mc", ",", "bach.join", ",", "bach.collect", ",", "bach.keys", ",", "bach.+", ",", "bach.repeat", ",", "bach.print" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 757.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-171",
									"items" : [ "(Seen", "elements:)", ",", "bach.m2jitcellblock", ",", "bach.wellshape", ",", "bach.minfo", ",", "bach.mrandom", ",", "bach.diag", ",", "bach.idmatrix", ",", "bach.trans", ",", "bach.expr", ",", "bach.mtimes", ",", "bach.mpow", ",", "bach.graph", ",", "bach.eig", ",", "bach.ker", ",", "bach.extractbasis", ",", "bach.norm", ",", "bach.det", ",", "bach.inv", ",", "bach.rank", ",", "bach.im", ",", "bach.linearsolve", ",", "<separator>", ",", "(Linearalgebraic", "topics:)", ",", "- matrix definition and operations", ",", "- matrix transposition", ",", "- eigenvalues and eigenvectors", ",", "- kernel of a matrix", ",", "- linear combinations", ",", "- spaces, basis and dimensions", ",", "- orthogonality, orthonormality", ",", "- determinant of a matrix", ",", "- inverse matrix", ",", "- rank of a matrix", ",", "- image of a matrix", ",", "- solving linear systems", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.collect", ",", "bach.wrap", ",", "bach.print", ",", "bach.reg", ",", "bach.length" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 833.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-167",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "<separator>", ",", "(Seen", "notation", "topics:)", ",", "- handling enharmonicity", ",", "- handling syncopation thresholds", ",", "- using slots as probabilities", ",", "- assigning slotinfo", ",", "- assigning slot values to the whole score", ",", "- querying number of chords", ",", "- flatting a single level of an llll", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.ezmidiplay", ",", "bach.mapelem", ",", "bach.repeat", ",", "bach.*", ",", "bach.keys", ",", "bach.flat", ",", "bach.wrap", ",", "bach.join", ",", "bach.iter", ",", "bach.reg", ",", "bach.beatbox", ",", "bach.nthrandom", ",", "bach.length" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 719.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-160",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "bach.score", ",", "bach.transcribe", ",", "bach.quantize", ",", "<separator>", ",", "(Seen", "notation", "topics:)", ",", "- tips for faster real time use of bach", ",", "- disabling undo", ",", "- hiding legend", ",", "- redrawing modes", ",", "- playing modes", ",", "- realtime transcription", ",", "- addchord message", ",", "- selection handling", ",", "- tail message", ",", "- inscreenpos message", ",", "- using int slots as colors", ",", "- linking note colors to slot content", ",", "- a first look to quantization", ",", "- how to get a realtime fast quantization", ",", "- continuous score generation", ",", "- retrieving some notifications", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.flat", ",", "bach.length", ",", "bach.join", ",", "bach.wrap", ",", "bach.collect", ",", "bach.repeat" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 700.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-149",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "bach.ezmidiplay", ",", "bach.unpacknote", ",", "bach.keys", ",", "bach.slot2curve", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- playing", ",", "- defining slotinfo", ",", "- using slots", ",", "- keeping slots in background", ",", "- retreiving slots content at playtime", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.mc2f", ",", "bach.wrap", ",", "bach.pick", ",", "bach.filternull", ",", "bach.iter", ",", "bach.collect" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 663.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-183",
									"items" : [ "(Seen", "elements:)", ",", "bach.roll", ",", "bach.score", ",", "bach.expr", ",", "bach.mc2f", ",", "bach.f2mc", ",", "bach.beatunbox", ",", "bach.beatbox", ",", "bach.rev", ",", "bach.tierev", ",", "bach.chordrev", ",", "bach.rot", ",", "bach.chordrot", ",", "bach.toc&r", ",", "bach.fromc&r", ",", "bach.scramble", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- dump message", ",", "- roll selection", ",", "- in place modifications", ",", "- accidentals display", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.+", ",", "bach.iter", ",", "bach.collect", ",", "bach.filternull", ",", "bach.flat", ",", "bach.join", ",", "bach.wrap", ",", "bach.repeat" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 626.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-182",
									"items" : [ "(Seen", "elements:)", ",", "bach.iter", ",", "bach.collect", ",", "bach.mapelem", ",", "bach.step", ",", "bach.find", ",", "bach.replace", ",", "bach.keys", ",", "bach.filter", ",", "bach.sieve", ",", "bach.is", ",", "bach.filternull", ",", "bach.thin", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.wrap", ",", "bach.flat", ",", "bach.join", ",", "bach.slice", ",", "bach.trans", ",", "bach.x2dx", ",", "bach.+", ",", "bach./", ",", "bach.==", ",", "bach.reg", ",", "bach.rot", ",", "bach.print", ",", "bach.reg", ",", "bach.unpacknote", ",", "bach.slot2curve" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 607.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-180",
									"items" : [ "(Seen", "elements:)", ",", "bach.score", ",", "bach.unpacknote", ",", "bach.ezmidiplay", ",", "<separator>", ",", "(Notation", "topics:)", ",", "- score separate syntax", ",", "- clear message", ",", "- building a score from separate parameters", ",", "- changing measure information", ",", "- ties handling", ",", "- playing" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 588.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-175",
									"items" : [ "(Seen", "elements:)", ",", "bach.print", ",", "bach.tree", ",", "bach.portal", ",", "bach.reg", ",", "bach.length", ",", "bach.depth", ",", "bach.nth", ",", "bach.find", ",", "bach.filternull", ",", "bach.roll", ",", "bach.score", ",", "<separator>", ",", "(Also", "used:)", ",", "bach.expr", ",", "bach.*", ",", "bach.==", ",", "bach.pow", ",", "bach.ratnum" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 676.0, 569.536986999999954, 127.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-172",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 870.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-165",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 870.536986999999954, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-166",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 165.0, 870.536986999999954, 322.0, 20.0 ],
									"text" : "- synchronize domain and zoom with other objects"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-168",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 870.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-169",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 874.536986999999954, 265.0, 22.0 ],
									"text" : "sprintf symout \"Graphical Synchronization (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-170",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 870.536986999999954, 163.0, 20.0 ],
									"text" : "Graphical Synchronization"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-157",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 855.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-158",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 851.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-159",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 104.0, 851.536986999999954, 345.0, 20.0 ],
									"text" : "- how to keep slots or parameters always up-to-date"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-161",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 851.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-162",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 854.536986999999954, 209.0, 22.0 ],
									"text" : "sprintf symout \"Lambda Scores (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-163",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 851.536986999999954, 100.0, 20.0 ],
									"text" : "Lambda Scores"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-49",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 764.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-63",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 757.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-90",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 117.0, 757.536986999999954, 345.0, 20.0 ],
									"text" : "- how to make good abstractions, subpatches, custom libraries"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-150",
									"items" : [ "a", ",", "b", ",", "c", ",", "d" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 757.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-152",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 764.0, 218.0, 22.0 ],
									"text" : "sprintf symout \"Abstract Thinking (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-156",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 757.536986999999954, 133.0, 20.0 ],
									"text" : "Abstract Thinking"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-254",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 630.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-255",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 626.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-256",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 171.0, 626.536986999999954, 263.0, 20.0 ],
									"text" : "- reversions, rotations, symmetries, taleas & co."
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-258",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 626.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-259",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 630.0, 273.0, 22.0 ],
									"text" : "sprintf symout \"Through The Looking Glass (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-260",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 626.536986999999954, 170.0, 20.0 ],
									"text" : "Through The Looking Glass"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-247",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 837.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-248",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 833.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-249",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 102.0, 833.536986999999954, 345.0, 20.0 ],
									"text" : "- an overview on the bach matrix calculus library"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-251",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p", ",", "q" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 833.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-252",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 837.0, 205.0, 22.0 ],
									"text" : "sprintf symout \"Into The Matrix (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-253",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 833.536986999999954, 133.0, 20.0 ],
									"text" : "Into The Matrix"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-240",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 726.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-241",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 719.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-242",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 111.0, 719.536986999999954, 345.0, 20.0 ],
									"text" : "- using musical data to build larger structures"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-244",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 719.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-245",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 726.0, 217.0, 22.0 ],
									"text" : "sprintf symout \"The Minimal Way (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-246",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 719.536986999999954, 133.0, 20.0 ],
									"text" : "The Minimal Way"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-233",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 707.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-234",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 700.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-235",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 114.0, 700.536986999999954, 278.0, 20.0 ],
									"text" : "- tips, tricks and examples of real-time bach usage"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-237",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 700.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-238",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 707.0, 220.0, 22.0 ],
									"text" : "sprintf symout \"Real Time Stories (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-239",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 700.536986999999954, 133.0, 20.0 ],
									"text" : "Real Time Stories"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-226",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 670.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-227",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 663.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-228",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 136.0, 663.536986999999954, 342.0, 20.0 ],
									"text" : "- use playout data to synthesize sounds"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-230",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 663.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-231",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 670.0, 239.0, 22.0 ],
									"text" : "sprintf symout \"The Gift Of Synthesis (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-232",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 663.536986999999954, 133.0, 20.0 ],
									"text" : "The Gift Of Synthesis"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-217",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 611.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-218",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 607.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-219",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 68.0, 607.536986999999954, 298.0, 20.0 ],
									"text" : "- iterating, collecting, finding elements, filtering lllls"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-221",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l", ",", "m", ",", "n", ",", "o", ",", "p", ",", "q", ",", "r", ",", "s", ",", "t", ",", "u", ",", "v", ",", "w" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 607.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-222",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 611.0, 174.0, 22.0 ],
									"text" : "sprintf symout \"Iterations (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-223",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 607.536986999999954, 86.0, 20.0 ],
									"text" : "Iterations"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-210",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 592.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-211",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 588.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-212",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 89.0, 588.536986999999954, 143.0, 20.0 ],
									"text" : "- an introduction to score"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-214",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 588.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-215",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 592.0, 194.0, 22.0 ],
									"text" : "sprintf symout \"Brother John (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-216",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 588.536986999999954, 86.0, 20.0 ],
									"text" : "Brother John"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-204",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 864.0, 573.0, 32.5, 22.0 ],
									"text" : "a"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-202",
									"legacytextcolor" : 1,
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 480.0, 569.536986999999954, 85.341797, 19.798828 ],
									"text" : "Start tutorial",
									"usebgoncolor" : 1,
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-199",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 81.0, 569.536986999999954, 322.0, 20.0 ],
									"text" : "- first steps with the bach nested lists (lllls)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-153",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 573.0, 569.536986999999954, 54.0, 20.0 ],
									"text" : "Section:"
								}

							}
, 							{
								"box" : 								{
									"allowdrag" : 0,
									"id" : "obj-24",
									"items" : [ "a", ",", "b", ",", "c", ",", "d", ",", "e", ",", "f", ",", "g", ",", "h", ",", "i", ",", "j", ",", "k", ",", "l" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 624.0, 569.536986999999954, 46.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-164",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 904.0, 573.0, 187.0, 22.0 ],
									"text" : "sprintf symout \"Hello World (%s)\""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-154",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1065.0, 948.0, 81.0, 22.0 ],
									"text" : "prepend load"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-155",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1065.0, 971.0, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial Bold",
									"fontsize" : 12.0,
									"id" : "obj-151",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 569.536986999999954, 80.0, 20.0 ],
									"text" : "Hello World"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-148",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 549.282227000000034, 780.0, 20.0 ],
									"text" : "To help your discovery of bach, we have prepared for you a certain number of tutorials (divided into different sections), ordered by difficulty."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-127",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 525.727233999999953, 2927.090819999999894, 259.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://www.bachproject.net"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-120",
									"linkend" : [ ":,;()[]{}" ],
									"linkstart" : [ "w" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 442.090912000000003, 2682.818115000000034, 131.0, 21.0 ],
									"text" : "www.bachproject.net"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-117",
									"linkend" : [ ":,;()[]{}" ],
									"linkstart" : [ "f" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 499.0, 2713.0, 165.0, 21.0 ],
									"text" : "feedback@bachproject.net"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-118",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 640.545409999999947, 2778.27270499999986, 296.0, 35.0 ],
									"text" : ";\rmax launchbrowser mailto:feedback@bachproject.net"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-116",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1035.5, 1349.0, 56.0, 22.0 ],
									"text" : "bach.leq"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-114",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1022.0, 1325.0, 46.0, 22.0 ],
									"text" : "bach.lt"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-100",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1008.5, 1300.0, 60.0, 22.0 ],
									"text" : "bach.geq"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-99",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 995.0, 1279.0, 50.0, 22.0 ],
									"text" : "bach.gt"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-95",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 981.5, 1257.0, 60.0, 22.0 ],
									"text" : "bach.neq"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-94",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 968.0, 1233.0, 53.0, 22.0 ],
									"text" : "bach.eq"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 7,
									"outlettype" : [ "", "", "", "", "", "", "" ],
									"patching_rect" : [ 968.0, 1203.0, 100.0, 22.0 ],
									"text" : "route 0 1 2 3 4 5"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-48",
									"linecount" : 14,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 3277.0, 903.0, 224.0 ],
									"text" : "bach is a completely independent project by composers Andrea Agostini and Daniele Ghisi. \n\nbach includes the Kiss FFT library (distributed under BSD licence), the Mini-XML library (distributed under LGPLv2.0 license), the GPC library (free for non-commercial usage), and the IRCAM SDIF library (distributed under LGPLv2.1 license). All the files needed to recompile the relevant parts of the bach library (namely the bach.score, bach.readsdif, bach.writesdif externals) are available through the downloads section of the bach website.\n\nThanks to Jeremie Garcia for testing the Windows version, to Carlos Agon and Jean Bresson for the OpenMusic compatibility, and to Mika Kuuskankare for the PWGL compatibility. Thanks to Sara Adhitya and Andrew Pask for being the voice of bach in our video tutorials.\n\nThe official bach font is \"November for bach\", created by Robert Piéchaud (                                          ) and automatically loaded at bach startup. \"November for bach\" is a light version of the famous November font. The full November font covers a wide range of music symbols, from Renaissance to the XXI century, and gives a unique, warm and lively look to your music scores. It is fully compatible with Finale, Sibelius and other notation softwares, and, in addition, is the first commercial music font fully compliant with             . \nYou can purchase November from this web address: \n",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"handoff" : "",
									"hilite" : 0,
									"id" : "obj-12",
									"maxclass" : "ubutton",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "bang", "bang", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 7.0, 3502.0, 92.0, 35.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 582.0, 80.0, 87.0, 31.0 ]
								}

							}
, 							{
								"box" : 								{
									"data" : [ 2779, "", "IBkSG0fBZn....PCIgDQRA...fE...vGHX....vXHq.3....DLmPIQEBHf.B7g.YHB..JHYRDEDUnEX6Z0FaSccF94dsAM5Dd9eaSNHLBso3HshCEnkNZi85VmZoo45k.EZnCalVaWYcIoDBai7kABzXBywqeoMsl30tpVsREluV6Bc3aHnEm3jXynEmerJaTRToZSyAGzTI9i28iqum3archCsczw5izQ2iOe7bO2my64q2i4HhzvwwcU7E3yBvwA.B.3z8bJvyyCdddnRkJvyqBp34AupzO44AGGO343.GGW5pB.h.ABTJBonTHUJoPxjIkdlJIRlLERkJIKuTTJV4IhRSCwheq.1TEaF..b.fjEWUpTIE3UMSbUpjxiWUZQlCbb7YpuoEmzBaJIwLYxzgLimToHmJUJlvloPeqB1TEaFpAfRwUkZnVwSovIO9ofWudwfCNHlJ1TJHZoZVJV25VGL+cLixe3GBISoB77Ij5PRxCNvAo9xY.khjFI.HMFhSRbGwe.34s7fPgBon7FLX.BUJfUu1RKnOtOuvCG.n+7YeGnVsZlnpVsZofJ0nWwyAGOqCLwDSTPMHc5zgF9EMfxJ6dQhjIQxjIPhDoCISfDIRxrvyzR9Cm3Cwy04yiQCMJ..LYxDLZzH..BFLHDEEA.PwFJF6rlchu1W+qly2+U9vOBufqW3yE7roJ1rj.+t8dFnVk5YDV0KBKRsZzRSsBOGyCqBZ0pEBBBPud8nrxJC..81auHRjHviGOXxImjUVAKBn9F1EVxssDjHQBDOQBjHQbjHQBkSYPovUidU7SexmFwhECBBBvoSmPud8JZrQhDA0UWcviGOPiFMnMGsk0G00hcMTyNq8yM7HOOLc19NK0W+mi52e+zPA8SW38BRBVDHHM3kzpUK0ZqsRQiFklKzc2cSZ0pkUuhMTLc996iFJ3Pjug5m5q+yQd66rzYD6gdm+xaSmtmSQm3sONYvfAB.jUqVUvmLOy9cHy8ad7+nhPwFJNm73xoS5Qejs7IhmwFaLxW+8S95ueZrwFqf3A.DO.fpzyAqVkJnVkRKWiFMh.ABfVZoEnUq1rFFjIrZ0JBGNLanzngFEc33HJlKmmsiDoci32meDJTHHHHfF18tmS9keGBBBXzPihQ7Gfk9H9CfQCMJVcokh69tVOK8ecmchm0gCbxSeZrm52MFe7wKHdxr87GdkWAl1v8fp2xVQ0aYqvzFtGbld5YN4ISP84qOx2P9nQtvvjqmyEyxwnQiyqUatPznQIiFMx3w0y6hF4uMBMvv9ny6qOx64krhe628OQFJQx5Mb3vEL+gCGl..YvfAl0h7nfh+FeSZkKWOU12dCzS9iebB.Tqs1JcnCdHB.zQey2rf3Qt83q+9k36NWO8i1tMpgcUOsxkqmV4x0Stb5Lu7jCKXIqXGOqC.HMea2c287Z0lKnUqV30qWVccbHGo2KcZKXtz6olmGgtTHXxjorliylMaLqba1roHO850CSlLoXk8Pgj3o7xKGaZyaFiO933L8zCV4x0i+8TWCa6w1Ftz6+9nxpppf3Qud8HVrXHTfKB.fJD9A324tKzdGGF6s4l..f6t5Nu7HCd.jdXqzVwj2sPs0VKan9MBzpUKb5zI..lXhIvIOwoXGXQRj4XaSKWuG2tcmy3xHW0wnQivwQ5.GxQ630diWGUVUU3CtbD33HcfksrkA2c0MBcoKUP7Hi19URFb+1e+KyR66c+2O..hEKF9nqbk7xCPZAV1ZxqWu.PRbpolZXERTTDVrXAlMaFlMaF1saOu40YmcxxypUqLqXum0aFVubfieFA9yBbm20cg163vXrwFCMrq5QoeqaGu0QOJJ+A2HpdKakMG5bAMZz.WtbgaSyRwK8RuTNKyG+wWeN4P5fFbbfmiCCN3f..PPPfILhhhvrYyJpjnnHDEEQM0TCrXwRV4cgKbAzc2cy3xsa2XvAGT5DfoEVIwURfCFLXVMLqVsxrbsZ0ZV4mq5L6zhEKFNSO8f163vv5krgxevMB.fA74CC3yGJpnh.2hTOm7rH0pQC0WOtskrDVZC3yGK9x0u771d.XVvRevxmPaUqZUrBTWc0A.o4YBGNL750KzqWO1912NyR1nQiHb3v3XG6XJ1iL.XwmJ1TRuGvkwSfRJoDHJJhHQhnngI2AM63.R6AUTTDFLXfklACFxhmexi+Dns8ser5aeUn5srU7AWNBprppP6cbXT811VAwy3iONZs4Vvi9HaAssu8i1129QyM1H..18d1SdaOJDXvAECWyb9D4dFqVsxlLOb3vvpUqr7jO7gff.KOYj4hWRFsJO17ldDoEcj6HKDHWVgJEXoIGOSdZuiCCa6XG3J+y+A96gCCWNch81bSnxppB1Ov9QoqcMyKO11wNfscrC..zcWcgt6pKb8O95Xik+PXqU+n4s8HirGe7eYr9MrdXnDCviGOvlMaYYsNaHe5ohMTrB+.r50VJJ1PwJ3onhJB6s4lvWZIKAiL7v3mUas2P7r2laBe+G3AvkubD.HMpyPIkLm7HCIKXRoWrxb9DYqY2tciImbRDLXPrhUrBX2tcVdxGSNy7jQlCYkNal71imAM0ZSPiFMvsa2vhEKr5PY3ksHQh.KVrfN6rSnQiFryZ1YVeL64W1PN4YW6td7Zuwq+Ihm0r10fJqpJTYUUACkTRAwCPZm83ejAwhW7hwFt66ASEaJX0pUlkjGOdxZgL.ooLpnhJxadx0ut5pCc1YmXoZVJN+esOL8zSioiOMhmHNhGOgjyfRl.Q+WShCZ+fr8RZznQXznQnUqVHJJx5zmOmzbsXWCsePGLmzbyjGlydFX3AvhW7hg8lsCOGyCzpUKhFMJqfhhhvkKWLm4XxjIzRKsv5.b4xEqrYlG.vJVwJPjHQv88cuObDmcfqO8zH9rDXY+FmJYJ3e.+3XG8luaF+zfGl.6an9whVzhw4O24QMOsz9ec5zIpMi4rtQfa2tYmB6.G7.3A23CfoiOMlNdbjHdbDOwrD3b3.9+WFaphMKMGr7U5XxbYPmNc..vtc6Ys0oEBlbxIYqtpSmtzNhO8sXjJERkdtXJ8UNcqJ3A.RQoPxjR2i19aae.PRfrXwhBe7VnXxImDlMalU2F94Mj1A6ImQjy3JiXKxNqEauUAD.nFaoQx+HCRAuX.5w9gOlBOpEHPfEjmtxzSZBVDnfWL.4ejAo8019Xo++QgY9QsOSMzPA7SAuAb3dznQoVasUENbesqaszEdufzPA8SM1Ri2r+PuoDXWauLZpkFQEVDfZ0pwQbbD7puxqxxagdkQ12eqHQhDXfAFDO0S7TX9PlSOHexRhHEmxb1+Ne7ju5H+NJTGMku1zBhiYGZpkFkrjuX.pK2uLoSmtBtGSmNcjqmyEE7hAngB5mdweyKVv0kHZNimYZyGOyW8KDtxUYVnbjkErLp8YpAUuspYW0in2dwIN9Ilyqs+gEdXXxTYrKz73G+D3.1OPAzGKgbYsjYdKDqNNNt79bgfYasN6EgmO9xq.C.r56nTzTKMihVltLtMhLc2HTruU4+3ISL933W0gSbtdO2B9i4SxTC4iG.jk.uPE6b0IUHbLmBrLt2xtWrwx2Hti0bG3qnQS5+5TxuYoWzUiECCOzv3zm7zKXgMyOBVC6SAK3b86Ex7my2ZBepIveAtwAOQzW9lci3VXv8efsp5.NAVz1iC....PRE4DQtJDXBB" ],
									"embed" : 1,
									"id" : "obj-92",
									"maxclass" : "fpic",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "jit_matrix" ],
									"patching_rect" : [ 9.0, 3504.0, 88.0, 32.0 ],
									"pic" : "Macintosh_HD:/Users/danieleghisi/Documents/Libraries/Max/bach/prove_in_vista_della_0.2/bach_objects/license/cc88x31.png"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-78",
									"linkend" : [ "\u003b" ],
									"linkstart" : [ "C" ],
									"maxclass" : "bach.hypercomment",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 99.0, 3518.0, 479.0, 21.0 ],
									"text" : "Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-9",
									"linecount" : 2,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ -73.0, 3701.0, 453.0, 35.0 ],
									"text" : ";\rmax launchbrowser http://creativecommons.org/licenses/by-nc-sa/3.0/"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-115",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 99.0, 3502.0, 478.0, 21.0 ],
									"text" : "Please be aware that bach is currently licensed under a ",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-113",
									"linecount" : 23,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 7.0, 2640.0, 922.0, 341.0 ],
									"text" : "bach is an experimental project. It is very likely to contain minor and major bugs, and you are likely to find out that some basic feature is missing, or very uncomfortable to exploit.\n\nIf you use bach, you might find really useful to join the forum of our website                                   . In this community you can discuss topics concerning the bach environment, as well as report bugs and submit features requests. This is the most appropriate context for all these things, since all users can benefit from everyone's experiences. Still, if you want to contact us privately, you can do it at                                             .\n\nThe ideal bug report should contain:\n- the sequence of operation after which the bug has happened - have you been able to reproduce the bug by repeating the same sequence?\n- the exact nature of the bug: what would have been the expected behaviour, and what you have obtained instead.\n- if there has been a crash, a copy of the contents of the crash report window - don't send it to Apple, it's our problem, not theirs.\n- if possible, a copy of the patch in which the bug has happened.\n- if possible, the exact input data that have caused the bug.\n\nIf you want to submit a feature request, please consider the fact that this doesn't necessarily mean that the feature will be implemented. It can be technically impossible, it could require major changes to the overall architecture of the work, it could disrupt another functionality, it could be obtained by patching with some workaround, it could be to difficult for us to implement or we could simply not like it. But be assured that even the craziest feature request will be seriously considered and reflected upon!\n\nGeneral commentaries about the work are also welcome - especially if positive ;) - we need your advice to know in which direction the development should be pushed.\n\nThank you for your feedback!",
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 573.0, 2012.0, 81.0, 22.0 ],
									"text" : "prepend help"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 573.0, 2037.0, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-88",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 997.0, 1440.0, 81.0, 22.0 ],
									"text" : "prepend help"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidden" : 1,
									"id" : "obj-89",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 997.0, 1465.0, 53.0, 22.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"bgcolor" : [ 0.98, 0.98, 0.98, 1.0 ],
									"clickedstripcolor" : [ 0.640313, 0.730429, 0.465685, 1.0 ],
									"clickedtextcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"firsteleminllllisllllname" : 1,
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 15.0,
									"hinset" : 0.0,
									"id" : "obj-3",
									"maxclass" : "bach.tree",
									"mode" : 1,
									"numinlets" : 1,
									"numoutlets" : 5,
									"onlyclickonleaves" : 1,
									"out" : "nnnn",
									"outlettype" : [ "", "", "", "", "bang" ],
									"patching_rect" : [ 2.0, 3818.0, 286.0, 428.0 ],
									"preventedit" : 1,
									"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ],
									"tree_openstate_data_0000000000" : [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
									"tree_openstate_data_count" : [ 1 ],
									"versionnumber" : 80005,
									"vinset" : 0.0,
									"whole_tree_data_0000000000" : [ "1 – Hello World", "2 – Brother John", "3 – Iterations", "4 – Through The Looking Glass", "5 – Slot Machines", "6 – The Gift Of Synthesis", "7 – Inspector As A Gadget", "8 – Real Time Stories", "9 – The Minimal Way", "10 – The World Outside", "11 – From OpenMusic to bach", "12 – Abstract Thinking", "13 – Beams Through The Trees", "14 – A Mazing Grace", "15 – God Solve The Queens", "16 – Into The Matrix", "17 – Lambda Scores", "18 – Graphical Synchronization", "19 – Filter Filter Little Star", "20 – Edit Path", "21 – Standalone Applications" ],
									"whole_tree_data_count" : [ 1 ]
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-358",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 910.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-337",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 871.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-135",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 834.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-209",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 758.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-213",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 720.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-207",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 683.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-208",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 645.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-206",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 608.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-205",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 570.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
, 							{
								"box" : 								{
									"angle" : 0.0,
									"background" : 1,
									"bgcolor" : [ 0.443137, 0.533333, 0.305882, 0.145098 ],
									"id" : "obj-261",
									"maxclass" : "panel",
									"mode" : 0,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ -56.0, 796.0, 905.0, 20.0 ],
									"proportion" : 0.39
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"hidden" : 1,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"hidden" : 1,
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-100", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-105", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-130", 0 ],
									"hidden" : 1,
									"source" : [ "obj-106", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-108", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-119", 0 ],
									"hidden" : 1,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-106", 0 ],
									"hidden" : 1,
									"source" : [ "obj-111", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-114", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-116", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-118", 0 ],
									"hidden" : 1,
									"source" : [ "obj-117", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"hidden" : 1,
									"source" : [ "obj-119", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"hidden" : 1,
									"source" : [ "obj-12", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-127", 0 ],
									"hidden" : 1,
									"source" : [ "obj-120", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-125", 0 ],
									"hidden" : 1,
									"source" : [ "obj-122", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-132", 0 ],
									"source" : [ "obj-124", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-128", 0 ],
									"hidden" : 1,
									"source" : [ "obj-125", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-130", 0 ],
									"hidden" : 1,
									"source" : [ "obj-126", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"hidden" : 1,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-130", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-122", 0 ],
									"hidden" : 1,
									"source" : [ "obj-133", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-137", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-142", 0 ],
									"hidden" : 1,
									"source" : [ "obj-138", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-138", 0 ],
									"hidden" : 1,
									"source" : [ "obj-139", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-142", 0 ],
									"hidden" : 1,
									"source" : [ "obj-141", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-142", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-134", 0 ],
									"hidden" : 1,
									"source" : [ "obj-144", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-147", 0 ],
									"hidden" : 1,
									"source" : [ "obj-146", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-147", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-149", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"hidden" : 1,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 1 ],
									"hidden" : 1,
									"source" : [ "obj-15", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-152", 0 ],
									"hidden" : 1,
									"source" : [ "obj-150", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-152", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-155", 0 ],
									"hidden" : 1,
									"source" : [ "obj-154", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-162", 0 ],
									"hidden" : 1,
									"source" : [ "obj-157", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-157", 0 ],
									"hidden" : 1,
									"source" : [ "obj-158", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"hidden" : 1,
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-160", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-162", 0 ],
									"hidden" : 1,
									"source" : [ "obj-161", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-162", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-164", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-169", 0 ],
									"hidden" : 1,
									"source" : [ "obj-165", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-167", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-169", 0 ],
									"hidden" : 1,
									"source" : [ "obj-168", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-169", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-171", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-165", 0 ],
									"hidden" : 1,
									"source" : [ "obj-172", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-174", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-175", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-176", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-177", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-178", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-155", 0 ],
									"hidden" : 1,
									"source" : [ "obj-179", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"hidden" : 1,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-180", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-179", 0 ],
									"hidden" : 1,
									"source" : [ "obj-181", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-182", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-183", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-42", 0 ],
									"hidden" : 1,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-195", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-201", 0 ],
									"hidden" : 1,
									"source" : [ "obj-196", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-203", 0 ],
									"hidden" : 1,
									"source" : [ "obj-198", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"hidden" : 1,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-203", 0 ],
									"hidden" : 1,
									"source" : [ "obj-201", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-204", 0 ],
									"hidden" : 1,
									"source" : [ "obj-202", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-203", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-164", 0 ],
									"hidden" : 1,
									"source" : [ "obj-204", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"hidden" : 1,
									"source" : [ "obj-21", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-215", 0 ],
									"hidden" : 1,
									"source" : [ "obj-210", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-210", 0 ],
									"hidden" : 1,
									"source" : [ "obj-211", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-215", 0 ],
									"hidden" : 1,
									"source" : [ "obj-214", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-215", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-222", 0 ],
									"hidden" : 1,
									"source" : [ "obj-217", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-217", 0 ],
									"hidden" : 1,
									"source" : [ "obj-218", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"hidden" : 1,
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-222", 0 ],
									"hidden" : 1,
									"source" : [ "obj-221", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-222", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-224", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-250", 0 ],
									"hidden" : 1,
									"source" : [ "obj-225", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-231", 0 ],
									"hidden" : 1,
									"source" : [ "obj-226", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-226", 0 ],
									"hidden" : 1,
									"source" : [ "obj-227", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-225", 0 ],
									"hidden" : 1,
									"source" : [ "obj-229", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-23", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-231", 0 ],
									"hidden" : 1,
									"source" : [ "obj-230", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-231", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-238", 0 ],
									"hidden" : 1,
									"source" : [ "obj-233", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-233", 0 ],
									"hidden" : 1,
									"source" : [ "obj-234", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-238", 0 ],
									"hidden" : 1,
									"source" : [ "obj-237", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-238", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-164", 0 ],
									"hidden" : 1,
									"source" : [ "obj-24", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-245", 0 ],
									"hidden" : 1,
									"source" : [ "obj-240", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-240", 0 ],
									"hidden" : 1,
									"source" : [ "obj-241", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-250", 0 ],
									"hidden" : 1,
									"source" : [ "obj-243", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-245", 0 ],
									"hidden" : 1,
									"source" : [ "obj-244", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-245", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-252", 0 ],
									"hidden" : 1,
									"source" : [ "obj-247", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-247", 0 ],
									"hidden" : 1,
									"source" : [ "obj-248", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-250", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-252", 0 ],
									"hidden" : 1,
									"source" : [ "obj-251", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-252", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-259", 0 ],
									"hidden" : 1,
									"source" : [ "obj-254", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-254", 0 ],
									"hidden" : 1,
									"source" : [ "obj-255", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-259", 0 ],
									"hidden" : 1,
									"source" : [ "obj-258", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-259", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"hidden" : 1,
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-266", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-271", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-356", 0 ],
									"hidden" : 1,
									"source" : [ "obj-272", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-272", 0 ],
									"hidden" : 1,
									"source" : [ "obj-273", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-278", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 0 ],
									"hidden" : 1,
									"source" : [ "obj-279", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-283", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-287", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-29", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-291", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-296", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-299", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-3", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-44", 0 ],
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-3", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-304", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-308", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"hidden" : 1,
									"source" : [ "obj-31", 5 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-133", 0 ],
									"hidden" : 1,
									"source" : [ "obj-31", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-32", 0 ],
									"hidden" : 1,
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-35", 0 ],
									"hidden" : 1,
									"source" : [ "obj-31", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-43", 0 ],
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-31", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 1 ],
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-31", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-57", 0 ],
									"hidden" : 1,
									"order" : 1,
									"source" : [ "obj-31", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-91", 0 ],
									"hidden" : 1,
									"order" : 0,
									"source" : [ "obj-31", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-312", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-330", 0 ],
									"hidden" : 1,
									"source" : [ "obj-315", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-318", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"hidden" : 1,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-322", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-326", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-274", 0 ],
									"hidden" : 1,
									"source" : [ "obj-329", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-36", 0 ],
									"hidden" : 1,
									"source" : [ "obj-33", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-330", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-339", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-98", 0 ],
									"hidden" : 1,
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-344", 0 ],
									"hidden" : 1,
									"source" : [ "obj-340", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-340", 0 ],
									"hidden" : 1,
									"source" : [ "obj-341", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-344", 0 ],
									"hidden" : 1,
									"source" : [ "obj-343", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-344", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-181", 0 ],
									"hidden" : 1,
									"source" : [ "obj-347", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-352", 0 ],
									"hidden" : 1,
									"source" : [ "obj-348", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-348", 0 ],
									"hidden" : 1,
									"source" : [ "obj-349", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 0 ],
									"hidden" : 1,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-352", 0 ],
									"hidden" : 1,
									"source" : [ "obj-351", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-352", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-356", 0 ],
									"hidden" : 1,
									"source" : [ "obj-355", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-356", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"hidden" : 1,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-361", 0 ],
									"hidden" : 1,
									"source" : [ "obj-360", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-335", 0 ],
									"hidden" : 1,
									"source" : [ "obj-362", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-370", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-371", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-373", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-362", 0 ],
									"hidden" : 1,
									"source" : [ "obj-374", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-375", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-374", 0 ],
									"hidden" : 1,
									"source" : [ "obj-383", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"hidden" : 1,
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-41", 0 ],
									"hidden" : 1,
									"source" : [ "obj-43", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-45", 0 ],
									"hidden" : 1,
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-39", 0 ],
									"hidden" : 1,
									"source" : [ "obj-45", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-51", 0 ],
									"hidden" : 1,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-152", 0 ],
									"hidden" : 1,
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-100", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-114", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-116", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 5 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-94", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-95", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-99", 0 ],
									"hidden" : 1,
									"source" : [ "obj-50", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 0 ],
									"hidden" : 1,
									"source" : [ "obj-51", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-55", 0 ],
									"hidden" : 1,
									"source" : [ "obj-57", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-56", 0 ],
									"hidden" : 1,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"hidden" : 1,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"hidden" : 1,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-93", 0 ],
									"hidden" : 1,
									"source" : [ "obj-61", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-62", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"hidden" : 1,
									"source" : [ "obj-63", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-65", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-34", 0 ],
									"hidden" : 1,
									"source" : [ "obj-68", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"hidden" : 1,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-70", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-73", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-77", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"hidden" : 1,
									"source" : [ "obj-78", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-83", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"source" : [ "obj-87", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-89", 0 ],
									"hidden" : 1,
									"source" : [ "obj-88", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"hidden" : 1,
									"source" : [ "obj-91", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-94", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-95", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-98", 0 ],
									"hidden" : 1,
									"source" : [ "obj-97", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-154", 0 ],
									"hidden" : 1,
									"source" : [ "obj-98", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-88", 0 ],
									"hidden" : 1,
									"source" : [ "obj-99", 0 ]
								}

							}
 ],
						"bgcolor" : [ 0.94, 0.94, 0.94, 1.0 ]
					}
,
					"patching_rect" : [ 6.0, 159.0, 929.0, 476.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 113.274520874023438, 128.0, 143.0, 93.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"angle" : 0.0,
					"background" : 1,
					"border" : 1,
					"bordercolor" : [ 0.803922, 0.898039, 0.909804, 0.0 ],
					"grad1" : [ 0.980392, 0.980392, 0.980392, 1.0 ],
					"grad2" : [ 0.490196, 0.65098, 0.219608, 1.0 ],
					"id" : "obj-12",
					"maxclass" : "panel",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 6.0, 930.0, 57.0 ],
					"proportion" : 0.39,
					"prototypename" : "bach",
					"varname" : "autohelp_top_panel"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"hidden" : 1,
					"source" : [ "obj-18", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"hidden" : 1,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"hidden" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"hidden" : 1,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"hidden" : 1,
					"source" : [ "obj-26", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"hidden" : 1,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"hidden" : 1,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"hidden" : 1,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-52", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"source" : [ "obj-44", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"hidden" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"hidden" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"hidden" : 1,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"hidden" : 1,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.help.home.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/help",
				"patcherrelativepath" : "../help",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.help.welcome.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/help",
				"patcherrelativepath" : "../help",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.lookup.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.replace.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.sum.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filter.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.change.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.histo.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.repeat.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.-.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.split.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.explorer.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/help",
				"patcherrelativepath" : "../help",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.explorer.welcome.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/help",
				"patcherrelativepath" : "../help",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.sieve.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.keychain.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.prepend.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.belong.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.random.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "icons.jpg",
				"bootpath" : "~/Downloads",
				"patcherrelativepath" : "../../../../../Downloads",
				"type" : "JPEG",
				"implicit" : 1
			}
, 			{
				"name" : "bach.tree.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.hypercomment.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.depth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
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
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.find.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.subs.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.rev.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.is.mxo",
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
				"name" : "bach.contains.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.dict2llll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.intersection.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.sort.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.leq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.mapelem.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.arithmser.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wordcloud.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.lt.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.geq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.gt.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.minmax.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.thin.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.trans.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.step.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0,
		"bgcolor" : [ 0.941176, 0.941176, 0.941176, 1.0 ]
	}

}
