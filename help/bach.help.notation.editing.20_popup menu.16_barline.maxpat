{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 2,
			"architecture" : "x86"
		}
,
		"rect" : [ 238.0, 45.0, 617.0, 539.0 ],
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
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubblepoint" : 0.12,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-14",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 340.5, 226.0, 40.0 ],
					"text" : "Solid barline (single barline, but thicker than the normal one)",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 315.5, 302.0, 25.0 ],
					"text" : "Hidden barline (use it for \"no barline\" situations)",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 296.5, 98.0, 25.0 ],
					"text" : "Final barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 277.5, 111.0, 25.0 ],
					"text" : "Double barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-5",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 258.5, 114.0, 25.0 ],
					"text" : "Pointed barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 236.5, 115.0, 25.0 ],
					"text" : "Dashed barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 216.5, 150.0, 25.0 ],
					"text" : "Normal single barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-2",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 278.0, 108.5, 273.0, 84.0 ],
					"text" : "The default barline depends on the position of the barline inside the score: if at the end, it will be displayed as final, otherwise it will displayed as the standard single barline."
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 267.0, 197.5, 180.0, 25.0 ],
					"text" : "Default (automatic) barline",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"data" : [ 14749, "png", "IBkSG0fBZn....PCIgDQRA..ArE...v4HX.....rvV+U....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6cmGWTU1++3+0LCyHH6ah.tlK2JnjJlPZV4ZJfUV4BhfZ5soejxkr31rDyc+ZtjZlBp2knPnVoonRJohYJJHY3RpnHKJt.HHL.wr86O324bOKmYXFlgYX48yGOlGLyY65Z1dy0bctNWu4oPgBEfPHDRCJ9V5J.gPHsDPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlATvVBgPLCrRaqHlXhwbVOHDBoIsYNyYpy0SsrkPHDy.s1xVFd5omvKu7xjWvJTn.73wyjebIDBwb4gO7gnvBKTu115LXqWd4E72e+041nuWDZ73wiMHqb4xAe9TCqIDRSa5avVJZGgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.qrzU.BgX58O+y+f8u+8iBKrPLxQNRzm9zGKcURmZpUeqOnV1RZxqzRKEiabii8VokVpktJYQ8K+xu.O7vCDQDQfnhJJz291Wr+8ueKc0RqZpUequnfsjl7hKt3vXG6XwANvAvnF0nvt28tszUIKlKdwKh25sdKTVYkoxxiIlXrP0HcqoV80XPcifA5t28tHszRCW5RWBm+7mGomd5n3hKFt3hKV5pVKVe3G9gr2+1291n28t2VvZiokg7yqKojRvK+xuLmqyau8tAoLMFlp5aSEMXAaqt5pwYO6YwfG7fQqacqanJlFTkTRI3RW5RHszRiM.awEWrktZQzhcsqcgacqag0t10ZoqJlD+xu7KHhHhfsUeQEUTHwDSDie7i2fNN74yGQEUTl0xzXXH02lRZvB1FP.AfrxJK7Vu0age9m+4FphwjhInJSf0ryNaKcUhnmhN5nQAET.NzgNjktpXRv7yqUWLwDiAE3yFarA6ae6C93iOlsxzXXH02lbTnE6XG6PwN1wNTjd5oqsMgkb4xU41hW7hU..1aW7hWTgb4xY2VEJTnPlLY04w0bo3hKVk5qtt0ktzEESZRSRwl1zlTjbxIq..JJt3hszOEZQa26d2Jd0W8UUbpScJEm5TmRQ1YmsktJohpqtZE6YO6QwZW6ZUjYlYp0saYKaY58mCAfhkrjknPgBEJDKVrAse1Zqsrk4rl0rLn8c6ae6F8yy27MeSCpL+ke4WpGupadjd5oyFqrtvSgBEJ3JHLSGT6u+9C+82+5JfM68kHQBbxImPUUUEFxPFBd1ydFdkW4Uvl27lAOd7fBEJ.Od7fb4xAe9MNN+bkTRIvUWcUik6hKtfALfAf.BH.DP.AfALfAnx1wreTe1ZYkPBIfacqaw93W4UdEL7gObKXM5+Q8eVN.pyeVt197He97QVYkkVa0mw74w5aYxvXdd1T96OYjQFHiLx...yblyTmaqIuaDNxQNBppppPPAEDN5QOJDKVLF7fGrotXZPz+92eLvANP1.qcsqc0RWkH5gPCMTKcUfSlxeVtk3mWqukYigteno.SdvVl9LaKaYK..vVasEt4la3gO7gM5OCiImbxMY+OrMlzbc.patGY.qcsqEYkUVvWe8EScpSEsssssdUuMDFZY1RaDEXLL4Aau8suMBN3fQm6bmYWlGd3AxN6roW7aAnwvYytgfkXjALiYLCy9+72TUlMWGQAFCSdmlVPAEf28ceWUV1su8sogLUK.MWGf5lpmW1XiM3fG7fMOOS6JokxySCU85DjwiGuFzJUqZUqf0VasVWuDIRfToRA.fPgBgUVYbMPWtb4n7xKG1au8FzIsq9teFJEJT.IRj.EJT.qrxJHPffFrxp9h40BtHTnP8ZrVarOO+sp+MLTqGpIsLpuOuX1uV0pVwdxfEIRjd84DKwmGM1xzb97Tcp+OAaHod3RC4DjYxG5W8u+8WQ4kWN6iYFNKW5RWhcaUnv3F5WScpSUA.T3omdpPpTo06iCClg9kgNDtpu6mg3vG9vJbzQGUYnvjXhI1fUd0WZa3ywmOeEW+5WuN2eSwyyLZUFZLLDkKWtBYxjoPlLYJNzgNjFkwO7C+.65451Se5S05yqrxJq5b+d5SepNO9lx8swTYx06CZ6yLF62eXBiclybFUdO5Lm4LF0wUeXHC8KSdyw5d26Nd1ydF..d7ieL1vF1.DJTH5e+6uIqLt4MuI..1zl1TixV4YpzT+mkqu+bRi84oBEJp8FTn5iUn.xkKGJTn.W7hWDu8a+1bVFxkKWm2354UhIlH5QO5Qcte00w1TuuVpxT4WyU90clapuMsDYxOAY93iOH+7yGssssESdxSFkVZo3Mdi2vjVF27l2DCYHCAie7iGyctyEe8W+0lzieiAlhyxqwLp.pu6q47rYq7WZYB1p9WtYJiAMnAw4wvKu7hy.pLXV2pV0pv0t10fO93ChHhHfGd3gdseZKfstTe22FKkIS2Lp3++wTu5XFu8szB5ZxC1FP.Af+7O+SDczQiTRIE..L24NWS1w+1291npppBqbkqDAFXf3gO7gMKC1pM56Y40XN64Fy9ZtNa1pGnkQokVJprxJgDIRXWm1lxE4ymOBMzPw8u+80Z4v7ZvvG9vYOwuUUUU5beTd+xO+7wye9y041Zp1WKQYxrs4me9n7xKG73wiM.KyeY5aaGczQUtvlZowjGrsicriXzidzrm.qANvAhQMpQYxN9m5TmBqYMqAKZQKBokVZn8su8lricicliAYdigAndc87T8Vtx72xUTNJqrxfBEJPYkUFpolZXW+IO4I4rbrxJqX61KsUVm7jmDxjISmamoZ+ZpVlRkJkyQbjHQhfiN5H6IkzImbRk8U4+1bWStQiP0UWMr1ZqQEUTAjISF3wiGbvAGLpxybb1eUTOOK3F5Y40XFU.lh80bd1rUW7UEORc9ohQLhQnw5T+i4FxmgqusDyXZAWysx7jm7jXaaaap79ZKsQiP8pkspWfJTn.O+4OGCX.C.2912lc4G9vGFiYLig8wF6biP5omNdgW3EfKt3B5e+6OxHiLP6ZW6Pd4kW84oAKlqQ66e+6aP+DX8c+X9Y4UUUUrKSeutwe3CeX8pNoN974i+7O+Sc1pXSw9VeeMTeedx0Iag41ws+3XBSXBrsnU48ohJp.1YmcFbvDl80Vas0fCPWe1ulqk4DlvDvLlwLPG5PGX6pgm8rmg1zl1fbxIG3hKtTu+mDLwUN6YOKd8W+0YW9YNyYvq8ZuV85X1PvjMZDBIjPTIP6W+0esJAZMV4jSNFbfmFCZLLhBLlAYdioAnt5AZUd4JTn.xgbMBzRZbnlZpAxjIiySLVKktSvjzmsevG7A32+8em8wKe4KGN5nilhCMqUu5UCmc1YbgKbA..7vG9P.TaGzunEsHrrksLHTnPSZYxEkOK8ADP.5basjW23Fy0Uuk3ZxWeodPVlgXjb4xgbXXmA9lqprxJg.ABf.AB.e97azL7HYFwB74ym88MFsDNoYFcv1DSLQDarwx93u669NDQDQfkrjkXrGZUndKASN4jQgEVHr2d6wpW8pMokk1v0zHW8g435F2XFU.VhqIeCg5ikS4xkCYxjAYPlktp0n.SPMlQjA.TIvqkJ.rToRgLY09dDS.Wfl+snkgQ0MBEUTQ38e+2m8wqYMqAQDQD.ng8Ev7xKObu6cO.T6ENwe9m+YCVYwPacGfgpwzOKuoDt9omJGnUtb4Fcv1+9u+act9JpnBU528lRjISFjHQBpt5pQkUVIJu7xQkUVIpt5pgDIRXCB1PWGT98KtzbNvaStQi..fXwhYeyhOe9fOe9vZqs1f6XelQG.e97QkUVoNOqnLi9A0QWe7Vt5Kfpe47ap9afmGySstcZ6yGETPAXKaYKXpScpnm8rmZceG6XGK5RW5B9pu5qzq51ie7iwu9q+JBO7vMnmGLLlQUP8UC0nQPgBE3se629+0kOxkCoRkB4xkSiFg5p.u+8uO6znnGd3AJrvBA.vG+weL13F2Hm6WHgDB1+92OrwFapWiFAFSaZSCe228cvSO8D4me9F7OIhqQG..z4YR2SO8DO5QORkkUWmk956HJP48sgZDRzXYe028S8KETlaxjICxjICRkJEI4YRvN6riy8Uamw7LyLSrrksLrgMrAUlVPUeeuzktD5Se5Ct90uNJt3hQG6XG04yKEJTfadyahryNaMpSp2BOs0px5ynJPaZnJSc8ZqxkkLYxP0UWMmk6ctycfat4F6nTvPeN2rezHrgMrA16+e+u+W..Lu4MO1.shDIBssssEt4lara2QO5QwDm3DquEIKiYtQn91c.gDRHp7Xp6.rLT+xwUk.uFX2Hb1ydVL6YOa70e8WyYfVkczidT7Zu1qg23MdC7S+zOwt7bxIGrl0rF1Ge26dWr10tVTZokhDRHAbiabCrwMtQTc0UiLxHCLm4LGDVXgg0rl0fxJqLyxOeGn19rUnPgvZqsFst0sF1au8n0st0vZqsFBEJznm05zmtoPaOWaobo6VueElYTA7xu7KiQMpQgadyahMu4MCas0Vr28tWjWd4g4Lm4fm7jmf7yOeL1wNV.TaqJO6YOqQUoUetQvPrnEsHNWdDQDgNaYUrwFK1xV1Bl7jmLV8pWMt28tG6yIRCKtFZPLAZA9emPHlIhF8w4N24PTQEE13F2H5PG5fN21RJoD7G+weffBJHDbvAqRv1xKubjUVYw93JpnBbsqcM3fCNfPBIDz4N2YL9wOd7zm9T7we7Gi24cdGroMsIXs0ViniNZ18iqfgMzcWmxkos1ZqQUlUUUU0Y++xmOez291WLkoLE70e8Wiyd1yhJpnB1u20beHfUuGMBW+5WG..SZRSB..wGe7PnPgHkTRACX.C...O4IOA.0NLm9we7GwBW3BwF1vFvZVyZp24kLictQfqSBh9N5.hLxHQjQFoAUeIlFZarYpxHRPOaY6ctycvm7IeB9fO3Cz5PySYm3Dm.iXDi.RkJEcnCc.cpScBG8nGUiesix3ymOr2d6gPgBgCN3.N3AOHd0W8Uw.Fv.f.ABvrm8rwXFyXPEUTA7zSt6m4l5TeDPbpScJzyd1SXkUVwdS8VT2bdHfUuaYKykH6K8RuD.pMH1Dm3DYCzBnYmsu90ud3kWdYTid.0maDLTT2Azzl1lx9Xl0uTWwEWLVwJVA63.urxJCyd1yF94meXZSaZ5UYdhSbBjQFYfwN1whwN1whm7jmfe7G+QsV+TFOd7fPgBQYkUFZaaaK6Oe2N6rCN4jSF7bXPiU74yWmcSAS28oqodwl6pWsrU4fnAFXfprt3hKNUd7l27l47Xnq9ZUemaD.p8LIq7jag9vZqsFxjIC74yGVYkUXZSaZ58W7LDL+L2N0oNUuN690m80RTlJuut6t6ry8CL2ZHJStZo6+O7+i8yEL96+9uQxImLRJojP+6e+wJVwJfLYxvhVzhzXa45Xe0qdUTUUUgCdvCxtrpqtZDRHgfqbkq.4xkipqtZ1iU94mOjKWNDKVL6wRpTovc2cGomd5ra2ye9yQQEUDr2d60Z8noBlSPkToRYm.pTGynQfOe9ZzHLSQKY45Xn7IKyTwX9mB06QivF23FwBVvBPRIkDF8nGMRHgDP4kWtJC+gSbhS.d73wNe1xiGOrpUsJDczQipqtZC9ja0PM2HzPow7Y2ugZekKW0KYVWc0ULfAL.DP.Avlh3U9XqOkIWiDAlAHuDIRXucztbTMNy+CZPCByctyEqe8qGyctyE26d2CQFYjrmPr55rzmbxIigO7gqxYa2N6rCCe3CGm3Dm.ezG8Qn3hKFG5PGBd3gG3HG4HfOe9vN6rCt6t6392+9HszRCSbhSDwEWbH93iGu3K9hXe6aeXXCaXsnl0594e9mQO5QOfPgBYuIPf.1tSfIPrgNhDZ1OZDl+7mOr1ZqYu5wBMzPwe7G+gJai+96O6XPiw8t28P+5W+L3+aVS04FgV5Jt3hwwO9wwRW5RwnG8ngqt5J5V25FBKrvvl27l03yG0Etl.ZXVt1tbce228cgSN4Dt28tGb0UWw68dumdOv96XG6Hm8M6TlxTPG5PGfc1YG1912Nd3CeHxKu7vm+4eNdm24c..P+6e+w68duGxM2bg.ABv92+9g.ABPJojBF1vFFV5RWpA8buoNkuDc016iMmYTWttwEWbX7ie7HwDSDSXBS.qZUqBqe8qGKXAK.73wCt6t6nnhJhc6qolZvt10tvN24NM3xpwxbi.gat3hKPlLY3RW5RHszRi8u28t2UisM6ryFYmc1H93i2nJSM9hqVFMB73wCu4a9l3W+0eEKdwKVkKiUtn7I1YZSaZb9Kv5V25F5V25F..5QO5A5QO5A65XFcCBDHPkKnAGbvAL8oOcC6IYyHb8OHaIwnB19du26gUu5UiHhHBHTnP7Nuy6fHiLRr6cuazm9zGzu90O1ssrxJCicriECe3CGSe5S2fSaGMFlaDH5Fe97QfAFnJ8iewEWLafWlfvkTRIlzxstB1B.DbvAi28ceWMtZ+ZLLmAzRQKoVwxEidhnIpnhBcnCc.Se5SGwEWbX6ae6X5Se5PrXwPhDIvEWbAKcoKE6XG6.AGbv0qV0pNtlaDLj7qEw7wUWcEidziFidzilcYYmc1rAfO+4Oud2UBZa71p9x3hKt3BavTJvpkAWuuo78aNOru.ZjN2HPH0Wbk9aHVdJTn.ibjizRWMLZVj4FAc8XkIVrXDarwh4Mu4YzYpglZXNS6EWbwpbh8jKWNRO8zQlYlItxUtBxLyLQlYlImCaF02W8sLMFFZY1PS8Qh.yk9oDIRfToRQM0TCpolZvMu4Mg81aukt5RzhjRJIzyd1SHRjHHRjHXkUVwNhDX90FJOhDZtwjmvGUms1ZqVyqUsTbkqbEb26d25LvJw3IQhDXkUVw9kUoRkx9kXkwLxCTuqDXFunLqiOe9btLSQ8T8Snqx0UkGFZbUlL0GEJTPmX3lHZvC1R.mIfP0wmOez+92ez291Wzu90O1+Zn8qnKt3RK1S.APsAljISFrxpZ+nsb4xYuOCoRkxN0ZpNoRkxFrVhDIfOe9btLtv7q1TtuGUueHYBbq96QJmECXdLSPT0KSl80JqrhMnL0+yM9YRC19S+zOgTSMU7xu7KiILgIXJOzMqXpBrRzDSvQ.n0fPBDHPmmUblfiLAN4ZYp+ybUnPAaPdlVnJPf.HUpTMZ4oPgB0X3modc0JqrhsqSTurTdYLcIGowOSVv14Mu4wdo4t4MuYblybF7se62B.fd1ydhacqaoxXQrkD+82ez+92eJvpYBSqakISFDIRjFqW4fnlJpeLYZkp9booxzkB5ZJHjqxSWqmz3iIIX6Se5SwV1xVTYY6XG6.adyaFBEJDuvK7B31291s3B11R+mzaoHPf.TSM0Xz8sJWu2oq2O4ymO6btAS2BTW+SUlVXyj0PT9jCwiGOUZENWs3l4wjF+LICGfpqtZM9PXqZUqX+4S27l2DcoKcwTTTDhdgGOd0qIvGleVtxedtzRKUk9YkGOdpL4yvP4fsL2utBDxiGOHRjHUNq773wiMkwnbfVlfxUTQErqio7XHVrX73G+XcVlO5QOhchxgX9XRB11912dUtZw..V4JWI68SKsz3L2NQHMDXBJpqrff5CuHkOoSJ2+qkVZoXLiYLHt3hSkS71wN1wvxW9x03XxDrjYFkSa35eDnbcRnPgpTOXpi23F2.yd1yFVYkUpDXmwZVyZPkUVoNe844O+4pjoUHlGlrA552+8eOb0UWQ+6e+QZokFVvBV.ppppv+2+2+GV3BWH8ScHMpndKeU9m6yLSTo7mY28t2MdzidjJKiqOSybbpqVVyU2Knde7pd8P40yiGOMl7sSO8zAOd7pyT7S26d2gXwhwe8W+kN2NhokI6Dj4qu9h+5u9KDUTQgktzkhW9keYHQhD7Mey2PAZIlUJ2BSSkoN0ohEsnEwNeMqdqhSHgDPJojBDHP.F8nGMaJS5K+xuD95qu3m+4eFyadyCG+3GGAFXfHgDR.VYkUXtyct3u9q+BG8nGEcsqcEQEUTvVasE4kWdXaaaaHmbxA1Ymc3Mey2Du0a8V5rNFe7wiPCMT..jat4hibji.GbvAjRJo.GczQrfEr.zoN0I.T6jne7wGO7yO+LYuFQzMS5kvkmd5I1yd1CRJojvm+4eN9xu7Ko.sDKBtFI.FioO8oCYxjgu669NMV2AO3AwINwIvZW6ZwxW9xwO7C+.N7gOL.pM68lVZogO5i9Hz4N2YjYlYhTRIErt0sNLnAMHDYjQBgBEhsrksfhKtXbjibD..rvEtPLvANPDWbwg4Lm4f0st0oyr5fLYxvEtvEX6NuJqrR1.5aZSaBctycVktNve+8GolZplrWeH0sl2WurDhIzpW8pw12910XxpOojRByYNyAt4lavCO7.yZVyBIkTRrqOzPCEADP.rYZ5ILgI.2byMLnAMHHRjHLtwMN3pqth90u9wl291zl1DBIjPPIkTBpnhJfHQhzYFg9t28tvSO8Tktmvd6sGSZRSBN6ryXDiXDrGafZSGTt3hK392+9lhWZH5A5JHiPzScricDevG7A3y9rOCu669trKunhJhMPJ.fat4FJt3hYeriN5nJGGl72Ge97UYJeT4gz0QNxQvgO7gQG5PGPu5UupyVoKVrXMt3ITtbYNweJSnPg04ISiX5PsrkPL.L4pNkm3y81auUYRR+d26dnssssrO1Py4V4jSNHgDR.IlXhX6ae6XlyblnlZpQmWoXN6ryH+7yWuedHSlLTXgEZv4uOR8G0xVBw.spUsJL9wOd1wNd3gGNV0pVEDIRDTnPA15V2JhN5nq2GelVj96+9uCu81aDWbwAgBEhpqtZstOcpScBVas03AO3Avau8tNKibyMW3ryNCu7xq5c8jXXDrTsjHjXliF8xKuLYugTWWe4DhtndNqR8obwhJpHMxDClBVYkUpLmN6niNhtzktfN24NiW3EdAzgNzA3me9gKbgKfBJn.Lu4MOUF2495quvFarg8w8pW8h8w1XiMnW8pWrO+7xKuP25V2Pe6aewEtvEPt4lKF+3GO5cu6MbwEWfqt5JryN63bbqme94CYxjwdkZZqs1Be7wG10q7iSIkTfyN6LFzfFjI7UJcqpppBt6t6ZLAtyUxdroRrgBKrPTXgEB.nw79s5pWSd3pSeujTaoMe1RLMLj4yVict7sor6e+6inhJJjXhIVma667NuC15V2pYsksEWbwM6lOaMjIObJZGgzLQm5TmvfG7fwYNyYz418q+5uhQMpQQcgfYF0msDRyHyYNyoNmxEG1vFF8qJs.nfsDRyHLW8b5BM8dZYP+6MBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlATvVBQGTnPAJojRXuUd4kaRNtkVZo5Ls8nOppppPUUUkVW+Ce3C4b8JueJOA5PZXQAaIDcn7xKGAETPXhSbhHzPCEgDRHXTiZT3G9gevnNtSaZSC4jSNF0wH1XiEIjPBZc8e5m9opLmLn79wLqkclybl57JNiXZPWTCDhd3m+4eF1Zqs..HqrxBKbgKDt3hKXjibjV3ZF213F2H6zAotDZnghoLkofW+0e8F9JUKbTvVBw.06d2aLiYLCjXhIhQNxQBIRjfXhIFb9yedHWtbzm9zGL+4OezpV0Jb1ydVDWbwgJpnB7hu3KhO5i9H1f1W9xWFaXCa.kWd4XxSdx3Mdi2..09S6+1u8awCe3CY2GlVnt8sucjZpoBu81aXs0VC6ryNMpeUUUU3jm7j3C+vOjcY6XG6.m8rmEd4kWvFargsNz5V2Zz291WbricLDTPA0P+RWKZT2HPH0C8t28F2912F..6ZW6B4kWdH1XiEaYKaA23F2.G6XGCUUUU3K+xuDe9m+436+9uGkWd43fG7frGiKe4KiniNZ7ge3GhUrhUfxJqLHQhDDQDQfwMtwgctycBGbvArjkrD..r28tWjd5oissssgIMoIgye9yyYc6hW7hnm8rmro.88su8gKe4Kiu4a9FDVXgow94u+9iycty0P7xDQITKaIj5AQhDAIRj..fIMoIA974CYxjgG8nGAas0V7rm8L1oNvCcnCggLjgfUrhUnxD.S3gGN7vCOfGd3AbyM2vie7iw0u90ge94Gr2d6w8u+8wfG7fQbwEGDKVLN0oNElwLlAbxImPe6ae0ZWXjc1YiNzgNv93ScpSg2+8ee3ryNCmc1YM1u1291i6cu60.7pDQYTvVBod3AO3Aro9lae6aiUtxUB6ryNz0t1U14hUQhDgXhIFjXhIhO6y9LHWtbrvEtPLrgML.TaBYjASNB6oO8onnhJB6ae6iccCYHCAhEKFkVZovEWbgc4t6t6bV2ppppXaUKPsi7Amc1Y1G2l1zFUlCpsxJqfXwhMlWNH5ApaDHDCjb4xwANvAvPG5PA.vF1vFvrl0rPbwEGhN5ngSN4DjISFJojRve8W+E9O+m+CRJojvG7Ae.10t1kNO1d4kWnMsoMXkqbkXkqbkH5niF93iOvImbBsqcsSkQvPAET.mGC0yGYsqcsSkrnq56WAETfJAiIMLnV1RH5gcu6cCgBEhZpoFb4KeYHSlLr10tV.Ta1zMiLx.d6s2HyLyDW9xWFd5omvFarAwFar34O+4vWe8EYjQFpjlZ3RHgDB1111F1xV1BF3.GH9oe5mPUUUEBKrvvjm7jwW9keIr2d6QgEVHN24NGlzjljFGCe7wGb7ieb1GO4IOYrzktT3fCNfG+3GiyctygINwIxt97xKu5rdQLdTKaIDcnUspUX5Se5vZqsFBDH.N3fCXlyblXO6YOriPfUu5UC6s2dbnCcH3latgu4a9Fz0t1UXiM1fctychxKubbricL3qu9hEsnEA.fILgInRWBL9wOd1TJV+eK+..PFHkDQAQ0yANvAfc1YGNwINA7yO+vZVyZ..PfAFHV4JWItvEt.ppppv5V25Pe5SeznN2m9zGTd4kihJpH..DP.AvtehEKFqacqC8su8kc6SO8zY6ZCRCGJGjQZzixAYFt8t28hm8rmoxv+hK25V2BqZUqBe+2+8M30IJGjQHjlcl7jmLN24NWclhb1yd1CV7hWrYpV0xF0msDRyTIjPB0YKDW1xVFklbLSpyfsO7gOrAofY5NABotvzMBp2UBRkJUktSHmbxAN4jSV5paiJ0UKaAfQOg3nuxN6rgLYxTo6CrxJq3rKDZpDavPhOVmAaKrvBQgEVnQUgHDiAy4DfIXKyeY56Vl.uO5QOB8qe8yBWaIbQgBEH6ryFUTQErAXUtuZ4wiG6eAPSlfsFBpOaIDBwLPqiFABowBZzHz7PywQifgfZYKgPHlATvVBgPLCnfsDBgXFPAaIDcP8bPlgj6vpqbDlw5AO3An5pqVmaCkiwZ7ftnFHDcfIGj4fCNvdYlKQhDDbvAiO4S9Dctue228c..X1yd15b613F2Hl8rmMr1ZqMn5VTQEE16d2qN2lTRIETPAEfW60dMC5XSL8nfsDhdP4bPVgEVHl1zlFBLv.wfG7f059Dd3gqWG6DSLQLqYMKCp9rt0sNL8oO85b6BKrvvzl1znfsMBPAaIDCjmd5I5d26NdvCd...t10tFhIlXPQEUD7yO+vbm6bgM1XCaVqMjPBAKe4KGu1q8Z3.G3.nrxJCSXBS.AGbvXSaZS..3S9jOAqXEq.YkUVXO6YOn7xKG94me3i9nORi7LVUUUEN8oOMVvBV...NxQNBpt5pw4N24PIkTBFxPFBafXas0V3me9gie7iiQO5QaldEhvEpOaID8.yX7slZpAW4JWA+4e9mvO+7CkTRIHxHiDSZRSBwFarnUspU3S+zOE..4me9rSh2YlYl3G+weDKYIKAe3G9gXMqYM3YO6YrY.2EsnEgV0pVgniNZrnEsH78e+2iJqrRbfCb.MpK+we7GvWe8kcNMH+7yGwDSLXNyYNHlXhAolZppreTNFqwApksDhdXDiXD..PnPgvKu7Be7G+wvGe7A6ae6CCe3CGAFXf..HxHiDiXDi.O8oOUiiQ3gGNb2c2g6t6Nb0UWQQEUD5V25F..bwEWfUVYErxJqvgO7gwPFxPvxV1x3bZHU8bLF.PvAGL9W+q+E..l1zlFhO93w3F23..kiwZrfB1RH5gSdxSBas0VMB9UTQEA2byM1GKTnP3niNhhKtXMNFN3fCr2Wf.AZLOPKTnP1bV1hW7hgb4xw7m+70HAMVYkUpwISS47QlyN6LJqrxT43VYkUZ.OaIMDntQfPzCLWJopyau8Vk7BVYkUFJt3hgGd3gFaq1tDTYV9yd1yvUu5UQTQEERJojvrm8r4LmkodNFCn1TaCibxIGz912d1GWPAEPyFZMBPsrkPLBu0a8VXm6bmH1XiE94meXe6aeXjibjFTBTzVasEwGe73se62F6ZW6BkUVYnW8pW3JW4JvWe8Uis2We8Em5TmRkkkbxIi+0+5eAWc0UricrCrxUtR10kat4R4XrFAnV1RH5.SNHSnPgbtdgBEhDSLQvmOejRJofgO7gikrjk..fW5kdI7RuzKAfZywXZKmi8ke4Whm+7mCYxjgXiMVHVrXbricLz8t2cNyhB8oO8AkVZonjRJgcYu8a+13oO8o3hW7hXcqacpLUSlQFYfgO7ga7uXPLJzr9EoQOZV+RSLCOr4Lm4fssssAd73w4EOwe+2+MVyZVC6EXgkDMqeQHjlbhHhHvu8a+F..ryN6zXr3xfxwXMdPsrkznG0xVtISlLUxtAZaaZrjiwZo2xV5DjQHMQoOAQarDnkPci.gPHlETvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgnCpmCxJu7xMIGWYxjoxLykxLlbWFW4brG+3GCwhEWuNdDSGJXKgnCL4frINwIhPCMTDRHgfQMpQge3G9Ai53dm6bG7u+2+aNW2N24NQbwEmAeLSM0TQJojB..RO8zwIO4IA.PEUTAV25VW8uxRLInKpABQOnbNHKqrxBKbgKDt3hKZLWyZIs0stU7e+u+W..bnCcHDP.A..ftzkt.IRjfLyLSz291WKYUrEMpksDhAp28t2XFyXFHwDSD.01UCwGe7X5Se5Xlybl3m+4elcaWxRVBd7ieL6i+hu3KvSdxS..XmkulzjlDV7hWLJpnhznrpt5pwW8UeEBKrvvBVvBvsu8s4rNkbxIC+7yOXqs1hyd1yhLyLSjPBIfSe5SC.fwLlwf3iOdS1qADCGErkPpG5cu6MafuCdvChSbhSf0t10hku7kie3G9Ab3CeX.TatGS49e8JW4Jn5pqF..O3AO.Vas0H1XiEd5om3y+7OWixI5niFBDH.6bm6DSXBS.evG7AnlZpQisK0TSkcZULf.B.95quXLiYLroqm90u9Q4gLKLJXKgTOHRjHHQhD..jTRIg4Lm4.2byM3gGdfYMqYgjRJo57Xzl1zFDd3gCas0VLyYNSb8qecUZc6ye9yQpolJF5PGJxImbf81aO5Uu5EN1wNlFGq6cu6wlcFr1ZqgHQhfc1YGrwFaXqud3gGbdBzHlGTe1RH0CO3AO.ssssE.ZlGxbyM23LGjoNkyaXLAGUdTCTTQEAgBEh8u+8ytLGbvAXu81qwwRrXwZcBNW4xfFUBVNTvVBw.IWtbbfCb.LzgNT.TadH6t28tnKcoK.n1VYxDH1JqrB+y+7O..nlZpQkg60Ce3CYueIkTBDKVL7zSOYWVaaaagToRwBW3BYSyNm7jmjsbTlyN6LJnfBPO5QO.Ps40L0m8TyO+7obQlEDErkPzC6d26FBEJD0TSM3xW9xPlLYXsqcs.n1TT9pV0pfHQhfBEJvV25VQzQGM..5d26N10t1Edy27MwwN1wToUoUUUUXoKcoHnfBBwEWbXhSbhPjHQrqu0st038du2CKZQKBSaZSC4jSNX26d2Xu6cuZT+7wGePt4lK6is0Vaw4N24P26d2QO5QOPt4lKr2d60HEnSLeDrzktzkZoqDDh9fYRDWaSl3EUTQn0st0l7xUf.AvJqrB74yGst0sFiXDi.ezG8QnUspU..nCcnCvO+7CW3BW.ETPAXdyadrmrpANvAh7yOejc1YiwMtwgN24Nidzid.qs1Zzt10N3iO9fe629MLjgLDDZngxVlsqcsCd4kW3ke4WF1XiM3bm6bPgBE3+7e9OrsZVYVas03XG6XH3fCF.0NbudvCd.bvAGPG6XGwoO8ogCN3.dkW4UL4u9nuppppf6t6tJSV3bMog2bcxCmxTCjF8nL0f9YpScpHpnhB8rm8Ti0MtwMNr90udKZKaaomoFnQi.gzLwhW7hwd1ydzX4ojRJXnCcnTWHXgQsrkznG0xV8GW4bL8IWkYNzRukszIHiPZFgqbNFkGxZbf5FABgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPHDy.JXKgPHlAzP+hPpCkTRIZrLgBEB6s2dTZokB6s2958vqpt1ekmfadvCd.Ju7xg81aOb1YmaPtzjIMbnV1RH5fLYxPPAEDlvDl.BMzPYuwLQeOsoMMb+6e+58wOhHh.4me9bttSe5Siybly..fie7iioLkofu9q+ZTQEUf0u90WuKShkA0xVBQOr28tW3gGdnwx2wN1AbwEWZPJysssswd42lYlYhoLkofvCOb.TaRbLqrxB8t28tAorIldTvVBwHr8sucLiYLCHQhDbjibD3fCNfTRIE3niNhO9i+XzwN1QHQhDDSLwf+3O9CHSlLzm9zGL+4Oe1YMLtjTRIg90u9AarwFbnCcHbgKbA7W+0eAfZmRGCIjPP7wGOV8pWs45oJwHQci.gnGN1wNF9we7GYuUQEU.f+WNFSrXwHgDR.BEJDaZSaBcpScBaXCa..0NW3lWd4gcricfst0shadyaVmoMmyctyA+82e..LxQNRzm9zGLpQMJL1wNV..3u+9iTSM0FvmwDSMJXKgnGxImbvctycXuwURWzAGb.gFZnvYmcFiXDifMK5FZnghu3K9BHWtbTXgEhV25Vim8rmoyxS4bJVqacqQqZUqfc1YGryN6XWlSN4jQ0ewDyKpaDHD8vblyb3rOaUliN5H68sxJqfb4xA.vctycvJVwJfc1YG5ZW6J3yutaiiXwhgUVo6udJTnPUxbujF2nfsDRCr0u90iYNyYhQO5QC.fO6y9LHSlLctOL4Trt0stw45kJUJdzidDkSwZBgB1RHMvbyM2PlYlIZe6aOxLyLQ5omNmo1FkodNESc4latvYmcVkDDIowMJGjQZxvRkCx.p8DRobxXTY8pW8B1XiMvVasE93iOrKm4wu5q9p3F23F3pW8pnqcsqXxSdxfGOdnacqaPgBEr6uxDIRDRN4jQPAED6x5XG6Ha5OOkTRAN6ryXPCZPM.OaaXP4fLJSMPZjqkZlZH7vCGewW7En6cu6ZrtwN1whu4a9F3kWdYApY0OszyTCznQfPZjRa4Tre8W+UDTPA0jJPKgZYKoIfVpsrEP64Trlho5FpksDBoQKJmh07AErkPHDy.JXKgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RHDhY.ErkPpCkTRIryfWLpt5pYmSaqpppz5ruUokVJmS5LRkJEO+4O2jWWu6cuK..Jqrx3rbqt5pwCdvCL4kKotQAaIDc3e9m+AAETPZL+ydnCcHvLshrqcsKNuRu..lzjlDd7ierFK+5W+5HxHizjVWSM0TQJojB..lwLlAxN6r0Xar1ZqQTQEkIsbI5GJXKgXjlxTlBBKrvrzUCr0stU8pdLiYLCrt0sNyPMhnLZJVjPLRm9zmFBDH.AGbv3QO5QXyady3t28tXXCaXprcokVZ3a+1uEBDH.uzK8RprtCe3CijRJInPgBDTPAwl9aVwJVAd0W8UwANvAPYkUFF+3GOBIjPznNjbxIC+7yOXqs1xtrLxHCr4MuYTVYkgvBKL14S2AO3Ai0t10hHiLRMlswHMbnfsDhdHlXhAVas0rO91291rA1xKu7fPgBA.vm7IeBF1vFF9rO6yP7wGOJojRX2lO6y9LrwMtQzt10N7IexmvdrRN4jwANvAvW8UeEDJTHVvBV.r1ZqwnG8nwUu5UwSdxSvRVxRPt4lKl+7mOF3.GnFYz2TSMUMltEuzktDVxRVBJnfBvbm6bQ.AD.bwEWf.ABPu6cuw4O+4wvG9vaPd8hnIpaDHD8fqt5JZSaZC6M6s2dM1lbyMW7nG8HLkoLEXmc1goO8oyFP929seCCcnCE94mevEWbA+6+8+lc+9ke4WvPFxPPIkTBd7ieLF5PGJN9wON65m7jmLb2c2Q+6e+gat4FJpnhznrUNmko794gGd.+82e3omdxlSz..Ze6aOm8oKogC0xVBQO7tu66pxLJl.ABP5omtJaSokVJbxImXmwpDHP.byM2XWmxsFkYR.G.nnhJBW4JWA26d2icYcsqck89pmay3Zh5SrXwrstlgx+CAABDnxHpfxeYleTvVBwDocsqc3IO4InxJqDst0sF+y+7OriDg10t1gKcoKwts4me9r22au8FCdvClseZu0stkJifA8Y5FjImk0idzC8ptle94q07aFogA0MBDhIhqt5JF5PGJhN5nQZokFV1xVF65BN3fw0t10v28ceGN+4OOhIlXXWWXgEF1wN1ARN4jQpolJ97O+yM3wfackyxTWd4kmJovGRCOJGjQZxvRkCx3wiG72e+03mo2l1zFzktzE.TaqS8xKuvfG7fQ4kWNtzktDFyXFC5d26N7wGefs1ZKF0nFERO8zQgEVHl5TmJb2c2QO6YOgWd4EdoW5kvku7kw8u+8w3F23XOwUJTn.95qurOu3wiG7wGez34o0VaMN1wNFBN3f051wTOJojRPBIj.l27lmYctwkxAYTlZfzHWK4L0fgXpScpHpnhB8rm8Tma21111fc1YGhHhHLS0rZQYpABgzrf1xYYp6zm9zl8.sDpksjl.nV1p+pq7SFyqiVhTqC0xVBgzrQcEDkGOdTNLyBgB1RHDhY.ErkPHDy.JXKgPHlATvVBgPLCnfsDBgXFPAaIDBwLfB1RH5g+4e9G72+8eiryNaMxGYZix4lLskSvpqbQlXwh4Ls5nbY7vG9P8p9PrrnfsDRcHkTRAuwa7FXkqbkXwKdwHnfBBYjQF049ESLwf3iOd.TapngIYLprqe8qi4Lm4n0iw5V25XSrjbwFarAe5m9o5wyBhkFMEKRH5P0UWMV9xWN1912N6zW3wO9wwRVxRvu7K+hdeABrsssM3jSNYPk8UtxUfToRYmrazloN0ohMtwMh4O+4aPGeh4EErkPzAIRjfZpoFUl8rdi23MXujgEHP.t10tFhIlXPQEUD7yO+vbm6b0H2dsicrCL0oNUzt10NclKxTV7wGOF23FG.p8xvc6ae637m+7PjHQHjPBAu268d..30e8WGaXCa.yZVyhxoXMhQci.gnC1au8H7vCGgEVXXAKXAH93iG4kWdHjPBAhDIBkTRIHxHiDSZRSBwFarnUspUb9y5u5UuJprxJYyEYye9yGqacqCW9xWlyxUgBE32+8eG8qe8C.01UF23F2.wFarXMqYM36+9uG2+92G.0l8F5QO5ARKszZvdcfX7nfsDRcX1yd1Xu6cunu8su3hW7hHrvBCKe4KGxkKGG+3GGCe3CGAFXfvVasEQFYjHqrxBO8oOkyi0oO8owPFxPvK9huHbwEWvLm4L4b6t6cuKZaaaK6bnqs1ZKt+8uON9wONjJUJNxQNB5Tm5D612912dN6SXRiGTvVBQGd7ieLtwMtA5XG6HBO7vwl27lwO8S+Dt3EuHxHiLPQEUDadFCn1b6kiN5HJt3h473odtHS48UYpmSwFzfFDVvBV.tvEt.l7jmLlxTlBJrvBUobEKVrw9zkz.hB1RH5vst0svW7EeApolZXWlGd3AbwEWP0UWM71auQN4jC65JqrxPwEWL7vCO373o91qbtHSYN6ryprtqcsqAGczQr90udbxSdR3t6tiibjinxwwYmctd+7jzviB1RH5vfFzff6t6Nd+2+8w9129vgNzgvG+weL3wiGBLv.wa8VuEt5UuJhM1XQZokF9hu3KvHG4H0ZfufCNXb8qec1bQVrwFKmaWG5PGfc1YGxKu7..PkUVIV1xVFNyYNCtzktDxM2bgu95K61mWd4oxiIM9P4fLRSFVhbPFe97QHgDBrxJqvcu6cwie7iwK9huH9zO8SgHQhf.ABvXFyXvMu4MQVYkEBLv.Y6GVd73Au81a3omdxlKwbzQGwnG8nwku7kYyEYsoMsgyTYSAET.jHQB5YO6I71auwK7Bu.t3EuHxImbP3gGNBLv.APsoB8CdvCh4N24B97a719IJGjQYpARibsTyTC4kWdXgKbgX+6e+5b617l2Lb0UWQXgElYplU+PYpABoIJluP1b8KmcnCc.u9q+5329seSqaiLYxv4O+4azGnkgxuW0b78LcgZYKoQOk65.YxjA4xkCoRkxdS4V1p7Y5u4f5JmgYIyoXFpRJoDMZYKyMltTn4b2HPsrkzjWy4ufVW4LrlR4TrlyuOoOnfsjlrTuaDZo9k3lJT+8oVZueQAaIMon9YrV4u3xmOeHRjHKbMjvEQhDwdxu.z96iMmQAaIMIw0WZEIRDr2d6sv0LBWr2d6gHQhZQ25VJXKoIIk+RKyPFxN6rC24N2At3hKpbotRrbDJTHbwEWvctycfc1YGmio1VJnoXQRSJp2pHkC35t6tCIRjfryNaTUUUgZpoFHQhD1wiqToRYGMCL+kYTNPLLJ+5txWfBLit.gBEBgBEBQhDAarwF3jSNA2c2cNCz1RInKErkzj.Od7TInHyWNU9Ku74yGd3gGvYmclM.KyekISlJAaUNPa8MXa8Y+ZtDTgqeYASvVl+JTnP1+pbe1xrOLGG0OtMWQAaIM5wDnU4.tLegUtb4p7kclIza.nx1xbSf.AlrfssjwUvV0acq.ABXuBwT+RyE.pbByXNlJ+2lanfsjlTX9BNSvW974CEJTnxW1YBdJTnPUBHnbWHvrMTv15G06F.kCnxbS4V4pbfVk62V0OVMmQAaIM4v0vFR8.sJucBDH.RkJUmspkB3p+zVelybi4JBS4fsJGvsk3v9BfB1RZBQ8exoxsrkKLe4WlLYraG0EBlNbErk4eto7jKixAa00r7Uy8ftTvVRSBbcBxT9Dsv01yzetLsnkqfsDiCWAaUtKcTuqETd4bEfs4b.WJXKoIGkGIBLAT4ZaXVmxAZUeNwEf5Bg5Csckfod.WtB7p71zRnEsLnfsjlTTeDInbfWkwUPVl+BPmXLSEttjo01e4pOaU93zbGErkzjgxiBA.nx8A9eAbUe6zVKZYPAcMbb8y+UuEt.PiV5pqKngl6AbofsjlrT9KoLsbk4KzLCGLlkwU2FnbPVJfq9SWiMV0+0FZqaFT+3zR.M4gSZxQaAM0V+wx0iIlVb0ZUs0utLKiq+1bFErkzjDWsJUaAX4ZaT+9j5m55J.qtBxp98aNiB1RZxRaANqq.qzG4M8zVvy5J3ZKk.s.TvVRy.55DdosOdSer2zQaAL0UP0VRAYY7+2ezpwu2oeZy.....PRE4DQtJDXBB" ],
					"embed" : 1,
					"id" : "obj-1",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 147.0, 350.0, 234.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2013-06-21 at 01.32.19.png"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
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
					"frgb" : 0.0,
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
					"frgb" : 0.0,
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
					"frgb" : 0.0,
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
					"frgb" : 0.0,
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 585.0, 19.0 ],
					"text" : "Tags: editing, edit, interface, popup, menu, contextual, right, click, two, finger, tap, measure, barline",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "Screen shot 2013-06-21 at 01.32.19.png",
				"bootpath" : "/Users/danieleghisi/Desktop",
				"patcherrelativepath" : "../../../../../Users/danieleghisi/Desktop",
				"type" : "PNG ",
				"implicit" : 1
			}
 ]
	}

}
