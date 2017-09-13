{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 9,
			"architecture" : "x64"
		}
,
		"rect" : [ 280.0, 44.0, 617.0, 539.0 ],
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
					"fontsize" : 33.916553,
					"frgb" : 0.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 371.0, 396.399994, 42.0, 44.0 ],
					"text" : "|"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Times Roman",
					"fontsize" : 23.712709,
					"frgb" : 0.0,
					"id" : "obj-17",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 390.0, 416.899994, 54.0, 30.0 ],
					"text" : "= 72"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "November for bach",
					"fontsize" : 34.701706,
					"frgb" : 0.0,
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 366.0, 395.399994, 152.0, 66.0 ],
					"text" : "U ."
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-14",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 446.0, 401.25, 140.0, 54.0 ],
					"text" : "The tempo value is the number after the equal sign"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-9",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 226.0, 401.25, 140.0, 54.0 ],
					"text" : "The tempo figure is the one before the equal sign"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubblepoint" : 0.09,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-3",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 320.0, 176.25, 259.0, 54.0 ],
					"text" : "Toggles the tempo interpolation towards next tempo (rall. if next tempo is slower, acc. if next tempo is faster)",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.690217, 0.690217, 0.690217, 1.0 ],
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-16",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 93.5, 233.0, 174.0, 55.0 ],
					"text" : "These are instructions to navigate in the inspector",
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
					"patching_rect" : [ 313.0, 152.25, 290.0, 25.0 ],
					"text" : "Set tempo symbolic onset inside the measure",
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
					"patching_rect" : [ 312.0, 130.125, 121.0, 25.0 ],
					"text" : "Set tempo value",
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
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 312.0, 108.125, 123.0, 25.0 ],
					"text" : "Set tempo figure",
					"textcolor" : [ 0.501961, 0.0, 0.0, 1.0 ]
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
					"patching_rect" : [ 6.0, 514.0, 594.0, 19.0 ],
					"text" : "See Also: tempo, measureinfo",
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
					"patching_rect" : [ 6.0, 8.0, 403.0, 23.0 ],
					"text" : "Tempo inspector",
					"varname" : "title"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"frgb" : 0.0,
					"id" : "obj-12",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 476.0, 585.0, 31.0 ],
					"text" : "Tags: editing, edit, interface, inspector, external, dedicated, tempo, figure, value, symbolic, onset, accelerando, rallentando, navigate, interpolation",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"data" : [ 34926, "png", "IBkSG0fBZn....PCIgDQRA..Bb...DvhHX....vT6DSA....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6cdGdTT01G9d66lMYSuPHUBgTnWBRGBEQD6.J1au1PdQ80duWPQEQQ+D6hffzAATT58hzagRnjFo2qaY99icyRJa1rIDpdtut1qY2y4Lm4Ylc18427bdNy.BDHPf.ABDHPf.ABDHPf.ABDHPf.ABDHPf.ABDHPf.ABDHPf.ABDHPf.ABDHPf.ABDbdCYWrMfyybk99m.ABDH3hGRWrMfyWb4nyyKGsYABDHPv+t4xJgDWJ6n8RYaSf.ABDHnkfKIEMbolC3yE64Rs8EABDHPv+93bwY+kLBEtTvgZSwFDhGDHPf.AWL4Bky+KpBEtX4vzU2ttR6DN8EHPf.AWpgq3b2UE.bAWnvEZGqmqN6ap1qP3f.ABDH37EMUm1Nq8sjhINm4BkyyFa6zP02RF4.gPAABDHPv4JsjWseC0lFacOuKR3BgCylZj.ZtQNnt0IDCHPf.ABNeSccT2biNfip6bMRCMaNe5.skPTfqDQAQdIHPf.ABtPRSMp.MkHDbIgHgyWNMOWuB+FpMmK4ifPff.ABDH3bkykP9K0.swUDDbAUfv4CGltZ9CzXhBblfflaTFDHPf.ABZInkJZ.MVDFbUQBsnBDZocb1bEF3JhBbk0o4ZOBDHPf.AMDMUGxNygeC84ly53p1SSlVRmjMm7CnwDE3Ju2U6WWAgnAABDH3euzbuIE0Tbl2Xu2U62yqBDZobF1RHLnwDBzTp2Y1kP.f.ABDHnoRK0vE3J0eQWfPKgixyEgAMEQAMzxFp8NyFEBDDHPf.AtJMkDHrwF1fFZoiduqj.imWDHbt5jro5H1UhVPyo75t8ZphADhEDHPf.AUSScFIT2q1ulswUb36Jk6n5blM0Pk4Rnr4thtHthv.msTFfJ.8.ta680rNWI5AM0gcPf.ABDH.Z5CaPCIZn5xqBnLfR.LVi5bjunZVd0qurF38s3bt3bzUmJh078MlPf59d0.d+Vu0a0sDSLwgGTPAMTMZzDw4fMKPf.ABDbAmJpnhSjUVYs50rl07Guxq7J6BHWrJV.pejCNWFJh5RyR.QKo3.WYlEH2Ak6HgAU+Yudm24c580e8W+ypRkpDLZzHVrX4bvjEHPf.ABtvib4xQkJUXznwcrjkrjO7UdkWYy.EXq55FggFZXFpoCvykganQo4NrBNSTQSYpHVWw.xqS4dz6d26gKIIkP4kWdyzTEHPf.ABt3hEKVvjISnPghdzyd1yqAX+.EQsGlf5d0uUOzBM1vJ3rgXnYM7CsT4bfqjveMzPIT2W0rN0FLXXnFMZrExLEHPf.ABt3gEKVvau8dH.Sg566TNN9J+kUik3f1TSZQxEgVBwAtZzAbTYMj3.41dubYxjEtyFJAIIILYxDUVYkTTt4xwW4JI6CeXLUQE.fBsZIfXiknFxPvfu9hFMZPoRkHSVCqmol8Y44lC4upUREIcHjJqLqFuatg1XhCuG7PPmu90j6y7JJG1TRqkjy7nTooxvhjDZUoi1FXLz6XFH9Xv05SABDHPvkVHWtbrXwBxkK2YMKbr5mqZw.M13k2PBDZNQRvkn434wUx0flqvf59JxsrksrCmYLFMZjxKubN4V1J6e1yFObWO9FPf3UqCFjfBRKMxIqrnjRKgNbaikH50UgNc5PkJUMZeVv12LEsfYgNCdfWAGL5CNLjISFkj9oovzSmxJrHLbyiEuRn2tbetqiuMVxtlK5MnG+Cxe7ya+wrEyjSdYQNYlMkURkbCcczz0n5Yi1mBtTEyjZR6iR0GEwDhGWFzuBDH3BM8pW8pG.mfZmuAM1KpyRWMQEczmcJmqQN37kv.6QNnwR.wJqrRN4V2JGZ5Smvz6NwFPfztgObB45FIRlMSpK424HqXEjTUUwgl9zAYPa5cuQgBENsOKXGagxl2ORPA4AgDu+3WuG.d2mqCYxUPAadoj8F+KR4fkSNy6GAYxPdO6Si1m65XakEt8eEuZsmDVjsh90tDoewNTJuxRYUGXYr8SrYxHkbX9aalfjDcucN2NEboJUvVt2GkIMguiMM13tH1ukw5+pOh8G68wikX3sf1g.ABZAnoD4fpowhfPKVzCZphCZnHM3JQfnoJLvkDGTTN4vw+s4RaUqlNJSAAVdEXH4jwz11NXwBFRNYZW4Uhmxjy9Tqli+ayE+hNZzFRHMXeVZNYSkKaFzpvzR3sUG57WNpLkElOygAYxQgwrva+kgl3bCUpLRVKaFTZahFsgDZC1m4VX1rrcLe7rUdP.QX.8dnhhLmCGOmCRklJmRo.L3oVrnzSjKAKaGymHBrsnUaC2mBtzE88B5kdss3ytllZ+ZoxSPAlkco6r7wbArgees3ceGAs2O0WrsFABtPR095p98MEABNiFRTPSRrPK8MAoFa5I5LAAPMhXfskJLa1rS2fotgMhWVLS2TplfvB5KrPzbfCfhRJALaF2N8oQQIEiZ.UJUSQlphT2vFw2wL5FrOKaqqB8Ffn6ren1CcnxcEnzR1Hk4NA.klOC3oBjK2.QqWEkt8rnrstJ7pU2UC1ma+vaBEpkS3sOPbycMnRiBxWJSRpncgYKlnbkEhNuzfB2jia5zxQyKM19g2DA4WCamBtTEyXQBjrHGylMiYylAEJ3bOFPV627s0uX1LlcZ+pgA9T+HC.YXpppZvVcQEK4y28QeDWS7CkX8VDkLA+qBET6HGTs.AGMqEbDNK+CNm4bQbPcGxfZVtiFNg5VuyDJXO5AM1U7n5nGi1qRMAIWNdoPN5jKCkEWLxN5QA.oppDMJjiJTBVjn8xfzN1wc5UR4d9IQqh1az5umnwfanTuNTnQNJTjKfDJbWFJUY.k5TgbspIrnMxYJHIm1mYUdpDZrAgeA5MZznFUJUfREPUxJ.KxA2bWEpM6AlLYlJcyHkGqYxJmTuz8J9D3DrX8WnUcB9qo8g7NyXW.sgGYhuMismACXl8sj+OlvmLWasuqL9O9YXTcKXaetJNzJmES5c9AR1VI+uuaYb8sQNR.dUUprkE8877exeAzFF+G+dLptEnCriRYV89ZYJO5Wxpus3fpRlo9XeOg8H2.4u3mmeXi.c8N4Kes6m37xpi4z24RXRO8mvtr0CO+2sLtl1nizW62xj1eH7PIT.i64+Z.nu24avy7eFHdYqs4dn+f2cbSz55106ju9MueZmG1b3W9oYIe+z3Sl6Fs05qmuaIilk+D2KGE3nu633yOV770K6+Q6zUE66O9YlvDmgs1NLdiudbLv1YcKc5UNUl7gih6uCYwDdief17HeIeWK5v2HPvEDp1eW0NzsTiO6nnwW2gKvYyfAGMLCMIZJhCZrgNvYhEpdYcuOF3LgAxATzXNG0mW9DfJU3oFMnWsRqIvmRkfBEfb4fIynvrIjazHRUZj.pnRJH27bpSWOTWAFZkOnwGCn1S8nxMMHWiJjIWNxjICElUgkpLhbspAkJwPqLQIkmGlcReVklJIjf8Au7vCToRIpTHGkxjiRExsNSFrnFSVrfQKVPqFiTQvlIshbtcJ3RUjPk6vV+zWhsN5WheYVOMGbFuMu2yem36O76LjvjQUVBjOaVKktzJX0Scj7FO8FIwUNJ7B3ny+sXbScib8OymwmOhNPEYbbpzfRrXwrs98YYqI7PLsY8Cbju49YRO8ey.V4siu0yNjgGI.IXPu0yiLKmJRdi7IO+FIwm9yXVOVU7M20yx2s5AvGdisELeZ94m9SP0yLMV6MGE4bjSi4.zfEKVvbUoytl6LXbycj7Q+vrvySsJd323MnLu9BlzsDGUc5UxnG2D4d9nYwWzScrfm8F4Qd8.32mz0gNyYx2cs2Kyj1wKMs4wPhRKm93mAe0GF2yq9Fru6+Mny20yysDqW3iFKjzbeKlvT2H+2ubdL51qksMiOlm8QtYdoe32YHgoC4VpfcM2Ixtl6H4il1uP6hLXwuSDb4HUG4fpEE.mMhA00OpTMZqib56phAbYwBmq2DjblfAG47utqasR9Pp+vJHuwFVA0ZzhF4fNCtiJc5.s5.2zA5zAxjAUVITVYnp7xQW4Uf1hJF0RR3r9UoF0nzfan1K2QsA8nPqZjqVEnz5UAIyrYjWkQjoTEHSNJKnBjooDm1mtoQGtoSG50pC0JUfFEJPibknQgR.IpvrIpvrIpxhELpPIEqsRzoQqS6SAWphYprXfGdZbvw2CJrjJI9W6cXqKYLrhcmJCp0QS+um+CxpnPJnjxvS0.bPxrjaBOTbBVvT2HLj2kW6N5MUTb43UTcBprDJsppnRIfg75rgO6lQYQUfeC55gUtGxojaEuzUe6PB.IaCsgLIJE3V+nExqNjfo3JKmD.VkFUVq2nLTBrsCtWRpGAS6iKNjJuXJynDRHC3d3O12yfukVBl6zCx6t9owKu0iQg2X6HscuBfgP+aqZRIaiD2MbqvqrdNYIifPSaKLSfGdZeMitSpo3JsPbcxWpn3RPQ6hiVCDYbwPXgpjJxe+rfotQ54SOKdftGDEVtEFz3dFt0osJaG6ZCVnTfgvz2v6SrJKkJqnLJqJwuSDbYG0zeWcEHTybPvQQInlzX27iZVQOnk9lfjyDM3vYiPcVVOwBM1UDnNxvopLx.kd4M3g6fGdb1W.TVYPwECEWLJKtDppppPS.A5zqzvjA+wnb0nvc8nvMcHWqJPisHRHCjYzLxTn.IEJPoDXTgZLYvem1mA3YfXohpPmJ0nQoRbSgJbSoZzpTER.UXrJJ0TUTgYiTAxwREPfd4b6TvkpXcXE5oWp4zomk0hLUj0ewqREVrTDq9G+Bdgor.f1PaiF.YnQlErfBTBL39DI4mUdV+2A62cPsfTwPOulXoxTOCk.TXok.3g00sdmpXw55aQxVjCjnDfDZsVRKq7.pB48DPxV8pZCO0LeGx9NdEd3k8EPmuMl7ycmDqupQRpXncggT5oStR.HmP6QOgE3FprTAklcQ.6fG5lWosscz.cAcxrfL27F.bSdQjUAZnV6R4ULECXt3bonhbCLofp.1VdYRl4acXDp3LJo8CF9sceJJcDQfjTIPOuFBpxzI2RZA95RffKNT8EDW27MntkU2jUrtN5czvLbA6lfjqLaDpa6ZnnF3JyTgpOn0nhCzDebjSVYhYu7Bkd4I3omfWdA50aMxAkUFnUKnQCVTpjbxNaTGWrNWbPfwSAklDgqVMxzp1pv.Up.UJsZdxLAxjgbjgLMlovRLho.i2o8Y39DMGN2cfJIEnSgZbSoZzqTKZTZ89XfBTX6pyjgIiRTbNkQb90Cg3fKKwBRRfjBN62eVrF0I8pjnnirBdgor.d64uQton8fSuvWhQ9pkhjEKXw1OIW0NNDSn28F00seAjJqDpzhm0nbIqqqCDGfDHgEq1gEq+eg4RKEKdoCvh0DmrZwAVJABYX7s665HmCtJdga6+wSN+3XYOXOQRB.SXxrEaI.YEbnsrMvyASUVTiu96IvXXY660HTa1DXl7SOCxyXwVWiRpDKVpy8sCa+ElJkJrZCxUha.8zW2qw49YwgVEztmps3lEKTfDPAFozJsfX9MH3xXp1OGT67M.Z3K31QQOnoN0Eco10RdGRzUhZPcamiDFzjFVA25TGo7idLNlLn8d6sUgAd3A3laVafJUVy8.4x43EVHRgDBZ6TGoLmzuZhtOT9dNBomYoDtOd.JsF0.YxUfjDHSoRq+YoJIR+L4P4ljix36CUYpg6yH8NNRo38Q1mtP7pcAiZ4pPkbUnTlJ.ITI2BZjqBiXgrNUVnSsVhzm3wX4haczW9gYT5Nr82+aXc99fjPjpY2KXxrZZGSsuQfwj1..TRJIwdxIKl0q96.IPgEWEA5SXbqOehrzI9170s4cYr8KbpLySQFDBcKJ2sMLAVrObSls50lpLal5eJc0Cqfj8Y2f0Uu5gUqNC6PUYveupsSa5R7DrA+ni.aSiGVmwERA.G4C369SuXz8MZJK4Uy6uVXjueWPuYi3QeuE3ydQF+qDLuvX5KdonbR+TYiewFC9D4.4A4S3+6ImLtOo6itGjFR6TohOw1I7WxpMswcbP5z.ZG5zGF2v3ZGOxjdWVUHuB8NX0bzMtPlEvy2w.rteZ0nsZWm29NTffy6TyKFVpFkUcDD.WK4Can1cNE8fli3flS9F3nxZrgXPNtf3fRkjv8DGHYtqcgapTQ35zgb2bCznwZjCjIGISl3TkUFYpTE56e+nHylc5UjWpjDtEwvHiTWOp8xcZUj9gLjWii3xvBx3LmoDNSpEgwvGFkYz48oTYRzsVOL1el+M45dQnKD+vhbILaKZQVr.lLIQNoUHElSIjPHCipJqJQjCtrDKVy4fnUwJdlGfOvVoO22uL5fhRor3GAOXB+HS7Id..3QdkmjDdmIySe2eE+ey6wnc2zqwmUoa7DS9kY4S055Nrm6qnyQ3l0HRTiblQtRqhfUHyQhCrTam+lkPOfJEXa8sfxZ1eRV3fS50sauD8nYZisSX1boVCkOIhrc9BbWel0pSbbSkmu+9Pd4TFx8p+7WS+M4kt6WmGdQ1Z.CkoLm1h6kpkGd0+J7b2NS5Y1js55GewraOl0GF263Rjw+EuHq6KhfO5WmLIbO+e79U977hO4CXeO4I+rEvMEgbxrHiHWo+VGJDg3.AWdiiFVgpEJTSQBMknGTWZ1hEZtCWfiV1PyDgFJeBjg0r0rtKqYcQufErfk5LCyhEKXvfATlUVPRGg.hLR70SCnSqV.YTdkUPdEUDYexSgk1FElBH.Jpnhb5885p6S4EbZTm6lIvH8FeBz.t4tUAGkWZkj2YJhLOY9To28BKdElK2mEKkGIk25veu0iOda.2bSK.TZYUPt4UHYkWoDmeCDCx7oQ6SAWphR7MP+wMsJQlLSTRQUhR8FPVQmgLKrBPodBNXevTIkhB8FfJq.4TEkiBpH6roLIU3SPAhdKUQol.M5cCEUjColcEDPXgf1JykSmo0P0q2+Pve8PtmNUJtd5HUV61K2CBMLeoxbRkrJwDfR7OrPPm85cmPByOLWVYToIvfGpofLSmBpvBYuo2kGdMijM7U2DJKsHpToFzqnBxHi7wjsslFC9Sf9nkRJpTTpTCt4lhyZWp8ffCxWLURQXRoFz6lRJH0TnXSxw6V0ZzZtTpD0XJuyPQlTieAGDpLUAUZxDZza.oRylyjWomce1spH0Skk8ss.AWtwMey27HANJfYN685fpeecWZoNKq66q4sR4ZlHiNZYceuC4bIWBp6mqoHg59dGFU.brHgZVW6l27l2RblgIYKrpFLX.ubyMJdO6E0kWN5rkyAkUVoXTqV7nSchBJqLJpnhrZzMxCII68odsjaRa.slOCd5gLPlLJpXnb4AhuwzWJnzJZx8o6dpmij4toPiohBkFQRBLaTEFT2ZhMntRIEVpK0mBtzEYJT.lMiDJPkJ4HYxHlp0OGkgRUJQxjQLKAxTpBkXAi0XnojoTIJkAVLYxVnzuvfBkJQtLvnwy558Lq6E3w+rgxuLugh6pTgboZaqmEYnRkRjjrfIGTuRUpPls5p4tjBkpPdc1+sZGxvhsiQBDbkDiZTi55ANBVclW8KGIJn5WNRjPMEBTy2WSwBz.e1o3Jddpaabk7GnwhZPi8pZwBsaNyYNKtwLvpeBXoRkJ7zSOwc2c29CrHiFMRIkTBEVXgXznQW4ok0kU8o.AWHPdk4vwy2MhHH2b4qnPf.AMLiYLi4Fvp3fpECXwEd4JQOnlBAp4x5JHvoBDZId1JT2HIzPqmq9pIMUFqFy1xifrxJKxImbpUcU2GRRRHSlqeel+xk9Tffy2nv6nnGAZh7xqXw37KPPKC0MmCpN2.b1KnwyefFKoEcIZoe1JTsA3nnKT22ScZScizfL.4UGNdWgpaqyRhwlR+c4TeJPv4Spp37HqK1Fg.AWYQ872QsS1PG4uzQ2BkqlVTmFsjhCNWF9gFLBByd1ytEzDEHPf.ABtjf5JHnghRfixyuF6Ypv4Lsj2mCp66an10PIvnCGZgDSLwV.STf.ABDH3RGVvBVPcuOGTWeflqSYM1TRzQQVnYy4ygUnluuoFEgZNSFnKJ634AyTf.ABDH3BO61z9fy5qCp88z.W0uI37aLRmSbtjN7tRhHVc6p66cVnSpaTEDHPf.ABtRCm8TJttkCN1WpyvU8Q6TiyUngRRhFpM0cGow14clpIABDHPffqjvU8+4L+hMj3AGssZr1TKZotx7FZC1XFhi14q1lp4MSIABDHPffqjvQ96bUm8Nq9VD+lsjgsug1gbkbPngFWEwvJHPf.ABtRjZJH.ZXehNymI0nLbP4MaNejPhUiiB+QcqyUFhgFDSlMwbV67Ptb4baCZLsT18EDJnjBvK28pEq+pzXUL+0u.GVm2d3MWSBWcKx14jm4jr4Ct0Fr9nBtMzyXSnEYacgfRJuDl65lOwFZLzq3upFoskxF1+FH4LNAVrXgPCHT5dzckP7OjZ0tSblSxet8UPEUUAcucci92w9Uq5+ysuBxq37AfA1o9Sv9EL.jcAYyeuyUA.tqSOWeuutVpcyKYHkrRgUtqUSui+pHlPiwosMmByg0s2MPp4jJpUplvBHT5c78Bu8v6Z0tcdzcwF12FAfg08gPbgGm85VzFWLkUY4LvN2eB12fq05snMsDJqhxXHcavDfW92f1QIkWBKYyKEeM3CWcOFVScWtIwOuhegV4aPLrtOzyqaGAWRPC4yyQSswZtNR0Y8OubSwo4JNn4pRogb32rx4.yVLyh1zhQgbEW1HNH4LRlo86eGinmCmA14Azh0uFMYjEsIGemlNh.inESbPp4jVCtc.HwtLnKqDG78+wOxlNvlwrEyNUbPpYmJuwO+1TR4kTqx+0UMKtmgc2bsW00.X8tb4aO82kxprLB0+PHxfhnd80p2yZ4jm4j.fZkpXTC3V.fcbj+w9wV+8z+qHEG7oyaJjdtoSq8q0NUbvNO5t3Sl6jwj4Z+nUZVq923IG0DnaQ2U.Hy7yjOb1SBExUPnADJEWmueRO2LXs6ccXxrQt6gcW1KOibOC+5plEpTnjaev2lSs4RqnLVzlVLQEbTmWEGLqUOaV11VNcpMcTHN3eGzT760bxAuZJznIKf378TYzUJyQBMthMgD2392DmLySddq+UqTMuyC7V0oLUsX8eWaaW3CeXqOTe2QR6feasyktEcWYrIZ8OXcWq9Vrs04SRIqT3mVwzY+m7.tT6euY9ATR4kP2aW23VG3nwS8dxtN1t4mVwz4m+qoS3AFFsOh3I+RxmxprLB12f4idjI5z9TgbEruSb.6hC1+IO.Jjq.yVtx6FT7AN4A46V9OP54ldi11bJLGl77lBlLahqsmifg08ghREJXc6c8Lu0Oe9vYOI91m9qwcctSZ4Xs+tpX6IS3VFe85q90w9xZ265XyGbK0RbvVOr0ne02Nz2F0d7xcu3kuyWD2z3lqt61jHmBygYtpYwlNvlOuz+BtjkFJx.MTc3jxZwowDG3JazlZRSzTFeklzNcAkT.e57lBcLx1iOd3K+0+7WTbYEyf5xfXT8+lQlLYTPIEvu72yjik9wwnIiDj2AxnG3nHtvhE.9pE+0jWw4w026qiYs5eiRqnD5Q65N21ftUTqRM.jdtoyO8mSmSk0oIT+CgQzyqw9Ux.vIx3DLqU+ajR1of657f90g9vMzmqmsbvsZOj7KZSKlLxKC6NUWzFWLaX+ajxprbB0+P31FzXHxVEI.rpcsZV6dWOCpyCfeeKKCExUvaduuN5zns9GrkAgEPnM3wnij5QYAaXgbpLOEd6gOzyX5AirWiDkJTPYUTFSb1ShXBIZJt7RXuIuOF8.tERrKCx95qWqdzaS.vwS+3.faZbqVay7JJOl1R+VNcVoPP9DHCoqCl91g9..qd2qg0rm0wXFvnXE+yewwR6XzZ+ZMi6FdTV919S1v92HtqycFah2p8iou6Lde7xcunKQ0Yl25W.xjIi90g9vM02az9SsxLyOKlyZmKIkxQPqZsDe3wwXS71b3wH.l5h++H8bRmqJ1dxVO71ZviW.r0CsMxq37wGO7lm8VeZ6kmXWFDUTUE7SqX5Lm0NO7wCe3KVzWZ8XPw4wq+SuEOv0beDdfg4v9sMspMb3TNLlLaBkJTx9Rd+zlV0FNZZGsVsK+hymu92+FNcVoPfdG.CoaCl9UCmZ+41WAqZ2ql7JJezqSO8I9dynFvMiB4JH+hKfe4umAGOijsd9tOAxXFvnI1vrdU6e8uOMRO2yvSOlmBCt4A4Wb9L44+4DheAyCMx+CIkRRLyUMa5Ub8jcjz+PVEjE+uQ+TDZ.gv7W+BYa1N10gHaO2wfuc6+Fot7N+x6g65bmtDUmY2GeON838p10ZnJSUQWhpybOW8YcnOpAbKjSQ4vp28ZYNqcdz011El4J+U.3.m5f75+zawKeGuPsrgNFYGvS8FHuhymCe5jrueukCY0tq933tN1tYwaZIjdtoSv9FL8qC8kgzsAC.kUQoL20MeBwufIpfaC.TTYEyWujoQp4jJJjqfN0lNxXS71PqZqmus8j1AKcKKmrKLaBKfP4du56lf7IHGt+9y+0uv1O7Nnecnurg8uQmdrQvUTzP96Zn7Pntqai87UnwhVfSaSKcBI1XJZZnnDTy0uYmXElLahjRIIV5VVNKaqKinBNJJohRYtqad7OGYm.vWrvujsd3sQBwzCFPm5OmLySw6Mi2mBJo..H4LNAG3jGfIOuOif7IP.Xoac47C+4OB.EUZQ7bS6E4vojDcO5tRtEkKe3rmD6436EvZ3me4u+U4vobXhO73wjYiLyUMKVzFWLVjrX+YlfEKVvrsGrRSY9eA+5pmMkUY4DQfgyAO0g3k+9WiCdpCB.YWXNjTJIw2u7e.SlMhFUpaPmdlsXgkr4euVuJo7RAfjRIIdye9sYuIuOhHnHnzxKgec0ylorfO215ZljRIIV919C15g1JRRRDfWAzj9NvrEy7De4+i8ch8SWaamozJJkOegS09XBmaQ4OIli2...H.jDQAQ0QRojDe3rmDZToAeM3G66D6mm7KeZ1ax6k3CONNcVmlOa9eNUYrJa18QXqGZa78+wORDAENkVQoL60LGV3FWDf0bA34l1yyF1+FwOO8EUJUwetiUvK7suXCZm8uC8kO9Q+P5S66citOczzNF.jPL0e3R5Q65N.jR1o..xqwiXa4Mxia61Gg0wFeemX+bjTOJUYpJ6kUMRRRLgo9T1OdVdkkyWrvuj0s20C.qeeafe3O+I.nOsu2XwhEl+FVf85+hENU1dR6fDhoGz+N1ONQFmj2cluOEUp0GI3mHiSRRojDlLYD.LZ62PmLySC.EWVIVEHrxekzyMCJshxHz.Bgua4eOyeCK.C5MPXAFF+w1WASZNeRCtudi88FXJiexzlV0FmdLAvt3ndFaOqWccuNGuqVbnLYxZvi2UK.XyGbK.VGJhSdlSh2t6McHx1yF2+lXhy5iH4LNAsM31RF4cF9lk8cLCaBOpxjwZcLAfwOkIv+bzcRDAFAd3lG7GaeE7+sjoA.+yQ1Ie7b9TxsnbnKQ0YNVZGimaZuHEWVwNz95Za6Bu++4cXj85ZaziMBthCWw+myDHT2OeYQBIVWbEgANqstLVjLyae+uI5znC8Z0yh1zhIsbRidDS2I8bSGExUfOd3MIDSBbUwl.ZUqsVIGnEIIt2q9dXfcd.Tkwp3g9jGg0r60wcNj6fEu4eGSlMwCbM2OCtqChBKsPdzO8wYwaZIz4n5DKZSKAKRR7PW6+g90w9ZOREFzaf9z9dywS+3rzstbt49cSLvNO.NUlmlMcvMi+d5OS5QmHZTogccrcyDm0Gwu72yj26AeG61U7gGOu3c77NMrylLax9epUMIDSOvcc5YNqcdX1hYF+MNN5WG6KFMYjW4GdM11g2NG9zIQqskXbFMah2++7dDrusx9e95p76aYYXzjQt8AOVtw9b8TdkUviN4wwh1zRnec7rWsae6Pe3QttGhTxJEd1o8BHIIwqeOuJ5zniTyNUNYlmhrKLG61TUlphW9NeAhIzXHibOCO8+2yX+33B1vBoRiUw00qQxcMz6..lxB9B1zA1L+41WAC2A4aQ0+QbxYbhFceprJJC.7Tum0qtpKqzJJEub2Kdha4+x3+7mfV4SP752yq5z9M9vimEtwEy9Ow9QuV2qUYUyR17uiQSFYrIdqbS88FohppfGcxVOea.cp+DWXwx3uowY6Jj8D+1ruLiU9qjY9YB.oUiy26YrIPuhqmnSiNLn2PiteWS7vMO3SG2mfREJnvRJjUu60Rq8q07Z28q.XcHRV+91.m3Lmzg4YwXS7Vc4sU4UVN.3oCrQCtYsrbKJW5Ra6LlrXhI8aeBcIpNyid8OrC6u90w9wR25xYiGXSb+Wy8ZOpA8214iyZ0Ve9s7x24KR6BIZJqhx3Il5Swuu4kxHRX30q+V1VWNUYpJF4Ucsb2C6NwhEK7MK6awOC9A.KXCKD.dw634IXeClNGUm3Sl6jY4a6O4VGznqW+Ucj4Ngs7PQv+ZvYCotiJutkcdky2yVgZtrt04pImXSl.7JPzoQG.3k6V+yailsdkQCsaCkeasygeZESmeZESmV4SqXncav0S0dGhr8.fZUpI5VGM6+jGfLyOKRM6TAfUriUv52m0qNStb4jZNoA.oYaYaBNRaaeuX72z3ZPaM4LRF.5bTcBMpz.X8JITqTMm7LmrVOcFqNjnJjqnA6O0JUyKd6OWsJyaO7A.Nd5V2VUmvfpTpht11txox7zjbFmvtiX204Ng3eqavsgyn5iOqeuqmcercCX8peq93R0DpsL7Wmsww0eu7292Y50YcXKpYxnoTgR6IvVq7MH70fujcg4PwkUr88qDhoG1aeOiIA1zA1rK47uwvOO8E.JnzBpWc4UbdVsYs5QmFsTZEkTu1zPzlVEIZTog8chCf611miO73qUap97pMruMZO5TRRVrOV694oeT9w1MSaoeKGM0iQQkYMh.U+39dXcaHLm0MO6muGrushg1sgv0dUinVaGIaQWTRxwOlviLnHQisv0mls7FnvRKj27mea.HmByE.ROmzcn3flB9ZvWNV5G2dz7pI4aaVd3qAec49Kxfhff8MXRO2zYemX+rEaQPnucnOTXoER1ElC93g2ztPhF.bSqazgH6.a9fagSblSVuYiRJ1NGu5gXPtb47HW2CWu5+lk9c.VmIQ.tT9VH3eU3pIgniB++4TxF5JzTEG3pNqaJILQSdVJzXnR4Y2sjKq1ibxsz+aht11NylO3V4fm5fb7zSlo+2y.ObyCFPm5u81UVEkY+OfpVXgFUpQtbq8WbgGGA4s0gcnWwcU1uBaUJs9GnUVUk16qSjwIHHeZkCGJ.01ZeUlpxdYlsXFSlMgZUZp0Ut6JIDkLYTqoxUs1VpTS4UUNUZrR6iKakFsZmUOVot51ogn5i2sKj1Yer16UbVmE.FsE5Z.jaSfS06dpT37SEMY1DUZrJ6NnpxT0emnA0pTYqrydLzQ6WMWBy19wlNvl4Atl6qV0skCYMGRB0+FNOObFcHh1y+bzchJEJI1PisdgFWgsy2hNjnIh.CG3rGOqxXUL607arzstbRHldvCOx+C4Ubd78+wOR0+DZTC3VnaQ2U17A2JG3TGjjSOY94+5WvfaFpUjbpdHtpnFm2VSbS6YOmPls91WC9X2Vpl55Hs4PXADJa8vaiMcfMaeb+qll6w692w9xrWybXwaZIbhybRB0+PI7.CmxqrBfZetIf8gzxQ+ls5yAq4wpSmUJ3s6dgGt4g8uyp4wlA1o9iOF7oIYyB9WCMUef0UPfqJPnIIj3b8YqfiduyZeSIzHs3yVgRqnT9347oLyUMKt0AMFdmG3srGtybKJ2Z01kss+.vpZ+jR4HnWqdBvq.nsAGEf0qjc3Ib0De3wwNNx+X2wT00+26bUHIIQRojDu328J7l+r0YPP0NEqzXkXxrIhKLqND15g1FmJySgjjDKXCKDKRVnSso1Ovoj6jHF3JzdaWU57V+BvhEKjdtYvF2+l.fN0lNXucJUz72Nss0V2+sHYggmvUSOho6rsj1NEWdIn5bbVS7G19NYmGcWTXoERn9GBpUol1Gg0n7rvMrHLY1LkUQYrrssb.qIj14J8nccmHBJBJo7R3c9k2iimdxjSg4xet8UvbV67.facPipY02wEt0Dg0nYSzgHiud0GksymjjjX3Ib0zyXSfskz1onxJB0pTyANo07R41S71nGwzcxtvbr1djnjxO6462Vhig28AdK6g0t5y20p1ZzZR2VjH1SCjrf07bhnBtMHWlLxu3BnucnuL7DtZNYlmhimQx1i.x4BiZ.2BxPFG3TGju92+FRM6TI8byfYrxe0ddCLlAV+vy6LpNuC12I1OvYGRAcZzRaZUan3xKgka67qik1wXWGa23tN2IxfpeNRz1faK.r5cuZrXwB4Wb97F+zaxC8IOJRRR1+Nyeu7mgmvUiaZci8l79bZD+D7uRbUebMzvu2XsutuuIwExbNvQ3rwboEerUzqUOZUqksmzN3Il5SQ.d4OGKsigB4JXHcs1WgxNR5eX6IsCJqBqIy2sMnwfZUp4p6wvXSGXyrjM+6ryitKxu37n7Jqv97R9l62MxVNzVYk6ZUrwCrIpnJqWYR0yJA+rEMheZESmsc3syqbWuD29fGKyXk+JO+27RnQkFpzXk3um9y8Lr6tEc++NFxX4vojD+w1+SV8tWi8qt99G98hed5WClvTMEFXmF.qcOqi0rm0RRobDJo7ho3xKg9199bN0uxkImEu4emkt0kaOz420PuS.3F6y0yF12F4.m5fb+ezCZKYOMyf57.oGwz8y48I.9ei9I48m4DY+m7.7xe+Yyk.UJTxXGxsWugCvUo80X8hKr5Gwm92w9a+34gSIIJs7Rn3xKgdGeurtNgGGmLySw6NyO.eM3q8guofRJ.20oGMpzX878u3ov+Zb99f6Zh.Pmipib3TNLexbmL94ouH4BWWgNM5XrIdaLyUMKdho9T3odCjdtYPrgFaSJb+NiW6ddE9347or5cuFV8tWi8xcSiaLta3QaxhP72K+IlPZGIk5Q.v9rmAfG3ZtWduY9A7SqX5LqU+a1+cwieiOF5zn094aUS+5Xe4u9m+ljR8Hbee3ChYKlwrEyL1DuUjISF2yvtKd4u+03imymRn9GBojcpnQkZtmqtk82yBth.G4u6Bd9E3HZLorMzzongBChLp+8HZGUtbGrzQu7eDiXD2PPxCrAMP4xkS7gEGwGdbHgDpUph3BOtZjUzR3iAeH9viC+8xe5Q65Ng3eHnRoJTqTMcK5txSNpIXOAs9q+4uonxJh299eCTHWAA6aq3NF7saOq1UqRMCnS8GO06IJjqfnBNJt2q9treU9pUolgz0DQmF2vS2LPGhHddfq49seEhgFPnnTgB7RuWz4n5DQEbTDSnsitGc2PkRkDj2AQ+5PeYb2vihGt4g08.IIBz6.H9viCepycGtpQBqWcW7gGm8okYcwMstwf5x.wS2Lfdc5oyQ0Itmgcm1yAAYHCEJTP7gGu8H.zX3s6dQbgEm8bTPgBELfNM.Ln2.ZTohvBLbtiAe6bUw0S66KA3k+V2WL3CHYM2GhK73rOFtHAQDT3De3wgV0ZYAaXQHWtbd+G7coRiURTA2Ft+geuDeMF9jA20AQ.dE.towMht0QwXF3n4558Hcg8.ILn2.wGdbzJeaUC1J8Z0yv6wvveO8i.8NPB12VQ+5Pe4dt56x9LVvZuY8bv3q04f0YKJAQEbjDe3wiuF7EYxf3CON5c78FkJTX6ywSzgzVTpPACryC.Ocy.ZTolvBLbt8DGq8aXScLxNfG5bGYHi1zp1v+8lFGZTol.8N.ht0skdzttSq8q0nRkZ6mu+Ti9IretUbgEKtqyCzpVKsO734gF4ChZUZH9vhk1zpHAYVSFw3CKd62IGAHlPig3CONznRCtqycFbWRj68pu6F8pikjjH.u82omKCf+d5GCtqCF+8xOBvq.Hh.CmA14AvCbM2+YOOwFd3lGDeDwWu6.h0k.7J.BvK+omw1yZEUNeL3CCryC.cp0gGt4AWUbIv+4Ze.64f.HgZUpI9vhy5wDrlDgd4tW3tN8DcqilwLfQwf5x.Arljp8o88AO0a.III5V65FOx08vN8tvnsCNnSiVhO73avo+pfqL3LVxhku7kuDfbv5eeaw1Ro5745VtidUMt5PF3RhNZrF0bDGnf563WA01ouRa0orFeVQMdU8micJSYJeaWTV6vqe9jm8qeARI6T3qdhoh2dzxc6MVPym64Cte.3mege3hrkHPf.Am6raS6iILgI7e.NLfY.S1VZtFe1hskR03yU+xL0W.gYZbQDMzx5w46GrQtRhHJPf.ABDHn13JIl34MtPmyANa5Z3n5ufKd3gG4CREUUYKRhUInkgmerO6EaSPf.ABZoog724rou3ELZoEGzPN+ar1TyxunFQgnsONiBtTg1GQyKY+DHPffKCvUlIetxzWrE8ddv46gUPf.ABDHPvkYbwdpL5xjzoShMsOwSsLABDHPvkmzmN1ahIrF9QU9kRbYi3fXBKlKaNnJPf.ABDb4LhgUPf.ABDHPPsPHNPf.ABDHPPs3xBwA4TXt06Aih.ABDHPvkSXzjQ6OASuTmKKDGHPf.ABDH3BGBwABDHPf.ABpEBwABDHPf.ABpEW1LUFaHlyZmKlLatdk6lFcbi88FHoTRhcdzcSmipiM6GqtBDHnoytN1tIoTRB204NCni829S9zpYOGeujcgYyP61P.fUu60PZ4jNA4Sf1KSf.AWb3xdwAKdy+tCSVQub2Ktw9dCbrzNNKZSK19iBUAWYfEKVH4LRFObyfsGMtfNMZuXaVBrwOshoyVOzVYvccvbrzNNye8KjI9PuG9WiGawqauqmt2ttA.u1O9lTkopnGsqarlcuV9ysuB9nGYhWrLeAB9WOW1KNnZd666MPi5y5bPoBqOW46U7WEgEXXDj2AdwxzDbdfOegSkTxJEhrUQB.sM3nX3Ib0WjsJA.jaQ4xx21ev6+fui8uedme48XYa6O3du561d61ax6kGXD2GG3jGjSjQx7UO4Wh65zyMz6qmGcxONa8PaiqJtddwZ2Pff+UyULhCBw+PPmFc0q7jR4H7m63uXncav1upk+dmqj+dmqBKVrvP5ZhjaQ4QRodDdlw7TnVkFduY9A3s6dwSNpI..6M48w7V+BnOw2KFdBWM+0+rR1v92HI14Axh27uiZkp3MuuWGSlMw2s7efik1wwC27f9199v0dUWyEziC+a.SlMwNNx+vT+uSAC5MPQkVTsDFJ3hKd6t2LwG58I7.CydYxjICKVrX+yImQxDjOAgds5wrEyHAnPt0TfRtb4HWtbwzWVffKhbEi3fkus+DUJO6tSeZeuwWC9R9EmOIkRRz011Y.X86aC7sK66wfaFHgX5AKcqKmBJo.pxTUXxrYTqRhjRII72S+r2WEUZQjTJIQTspM.PVEjEIkRRjb5GGeL3CZT4NZTogW7aeYRO2LnusuOjaQ4wO+WSmxqrLF0.tkKrGLtBlLyOK9pE+0XwhE97ENUdhaYB7UK4qs+XcdVqd17OGYWDZ.gvv6wvXuIuOFy.GM+1ZlKwGdbzgHaOf0vd2212GhHnvYpK5qHgX5AKbiKlG+FeTpnpJ32V6bojxKgt11tvnGvnPohqX9ox4cjKWtcgA+yQ1IaOocPZ4jNOzH+O1aytO1doyQ0I.qO0M6Za6Bu2LmH8JtdxtO9dHr.BkdFaBWTreABDbEj3feasyoVeN5VGM9Zv250t+X6q..dpQ+DDWXwRgkVHO9TlPyZa1o1zId1a6owrEyr4CtERO2LXvcIQd3qy5eB9DS8oXoacYbi88FDNWZgvGO7ltz1NgA8dvCbM2GmHiSPgkVH.7+sjogjjDu088FbnSeHd+e8C4ZRX3.vZ265nWweU16mUsqUy00qqkSk4o4.m7f3odO4gG4CR4UVNe9B+Rdla8+Qn9GBScQeEqXG+EW6UMhKJ6uWty1N71Iy7yBsp0PNElMAXK5c6436g6bn2A.HIIgZkpofRxmSk0oIqBxhP8OTjI6h1StcAB9WOWw3w5EF6ygFUps+4vBHTG1tyj2Y.fnacaA.O06IsxmfHkrSsA6aKRVbX4wDZ6..ExUPZ4jN.bfSc.dye9sAfxpnLJqxxofRJ.+pQjHDz7QkRUjY9YRrgFCd4tWr18rNZavQQ54lg0gZXBeNZToltEcWwWC9RaacTTPIEPQkUj8yIRM6zvMMtguF7kcjz+PfdG.22vuG.3cmw6ShcYfnVoZxL+rHtvhk8ch8KDGzL4wtgGA.9s0LW9r4+4L0I7EXxrQRI6TncgDM.Lu0u.NwYNAe7i9QnVkZLZxHu0zeGl9e8K7.i39uXZ9BD7uVthQbPLg1NGlyA0E0JUSoTJkUQY1mZUkVQo0qc0b5QVowpbXeoSia1eubaWkSXADFcHBqgtl3tJ6aSAsbbrzNNCpyCz56S+3z8n6FGM0iR6BI5ZIPrvRKjnZUa3XocbhpUQYu7ij5QoM1RTtjy3Dz2NzG60cnSeXzqUOya8y2dYwFp3oAZSgRJuDRKmzsKdFfdDS2X9aXATXoEvwR63zo1zI60chLNAcsscE019tSkRUjPL8fMcfsbA21EHPfU9W2MAo3BOV.X1qYNjew4yB1vBIuhy2d8ZToA4xjSwkWLEWVwHIIwdSduNrupdFQ.PTAa04S4UVNCq6CkA14AvtN1tI0bRqdyuaAMepzXUjR1oZ+38wSOYZaqiBsp0RoUTl81skCtUTqTMd6g2b5rNscw..r18rVZaqst9GK8iWqo3pLf6Zn2AS3lGOS3lGOA4cP0Z3HDz3jZ1owq+SuI4VzYuGxezTOF5TqCeM3K643mMeC.HPuCjSm0oqUejR1oRfdGvELaVf.A0lqXhbfqxsm3sw9OwAXk6ZUrxcsJBvq.vOC9RN03Ox5bTchccrcyS8UOCZTooVWMZCQmipSzi10c1wQ9G9uewShjjExq374F6yMb9b24ecjb5GmvCLLTpPI4Wb9TR4kPH9GBs1uVy2rruiYrxeEspzvp18ZHpfsl.oVjjH0bRk8ch8yF12FonxJlnBNJpzXkjcAYWqgfpWw2K9oULct5dLLVytWKkVQoLZ2EITZSgXCKF5Za6Bu+LmHW6UMBxq37X9qegLta3QAf8j7dYz0HIcuo9di7Le8ywTVvWPWhpybnSeH1dR6f299diKR6ABDHPQiTuLmrr47RtSVV2Wx.7eDiXD2fAidfV0ZPgbGXtRRDW3wRbgEKJTT+5kjjvOO8k3BON72S+PuV8LvNOPZkOAQOho6bOC6tYC62pCiao+2DpUplt01thJkpPuV8zm12aFah2JtoQGwGd7DjOAhLYxHPuCf3COd71curus5S66MA3U.nUkFBz6f3l56Mv0zyg2HGhEzTn3xKlv7OLBw+PnnxJlV4aPzlV0FjISF8ui8mbJLWZkuAgQSFoMsJRhIz1QjAEIYjWFjSg4x00qqEcZzQ2ZaWo7JKG+8J.6hH.naQ2Uxu37Y+m3.DW3wxcOr6RjXbMC5WG5KxjIiCcpCiREJ3dF1cSWZamonxJlBJNe5SMFJGcZzxf6xfHqBxhjy3D3sG9vicCOBA4SPWD2CDHnkGKVrPkFqjhTWLKe4KeI.4.HAXw1Ro5745VdC8h579yYZr+0qoJNnlN1cjCeE0YoxZrTQMdUc4wMkoLkuIjRCFO0a.UJUctruB.e17+bNVZGm90w9xM1mqmzxIcdye9sQmFc70O0WdN2+Bt3v2trumV6WvLhddMjY9YwK+8uJuy8+lBGLBDH3RFLZxHEVZQjp9zYBSXBODvgvp..S.lqwKS0nbK1JqlKq6Ko57dmIfvQKqG+qaXEt5dLL14Q2EKXCKjErgEZu76a326EQqRv4JCoaCludISiktkkgREJ4Atl6SHLPf.ABZl7uNwAwEVrL0ILE1+IN.EVZgnRoZZeDwQfhauxWVSjAEAevC8dWrMCABDH3JB9Wm3..bWm6hLPWf.ABDHnA3xBwAt6m6nSqNTp7xByUf.ABDHndnzjRLqyBT9EaKow4xBussa.whB4JDYMt.ABDH3xVjjjvrEyb3+7HWrMkFkKKDGj7lNFtqUuHxABDHPffKawjISThCti7doH+q6Njn.ABDHPf.miPbf.ABDHPffZgPbf.ABDHPffZwk0Ch+p11pIkLa3G0xWcuFFsx+KcuQ3jeQEvhW6R.f6dj2ExkKqd0oTgRtyq81cZ+7aqXtTdkkWu9PffKFblbxj8bTG+vJq+cou3lNqOMSW01VMmJiSiud4K8sy8Ae8xmKjlo.ABbBWVKNXC6dSrsCrsFr9N2tNcIs3.uM3E+81VI4WT9zwn6HcK1tXutMr6Mxb964xU0gd1n8yhW2RnfhKf65ZuSZ76H1BDb9kyj6Y3O13eTqxxqn7I+hxid0Aq2eQdhO5+gEKVn2cpWruisOl9R+El3DdeZSHQ5ntTf.AWf4xZwAO1XdDtmq6t.fo9aeIG5DGlGcTOBcnssG.Bx2K8uqGlXOFDyeUKf0uy0WKwAab2aD.FTOFzEIK6RalyeMO5Q7cmHacDWrMEA0gtDSmoKw7w1+rjjDi5YuUdrw7n3oGFXs+y5Hq7xje9s9QTox5yKkO5m9Xl0eNadoG7EtXY1BDHnFbYs3.+81O72a+..sp0B.A3S.DQvgauMqeWajkr1kP1EjCQDbD7Xi9QH.e7G.lzO+ITZ4kxMNnaje8OlEYl2YXvIjHinuifOalSgSelTH7VEN+u65IwaCdwAS9P7iK4mIwdLPNY5mhst+sRf9DD28HuS6BR.X6GXGL2+d9jVVoRnAEJCNgDYX8ZnNbeXPcefL+Us.V6NWGOwc7eAfBKtH1+wO.Jjqf9209RQkVLe+h9ANXxGhJprBBz2.XzCYTbUcr9QUnxppjW8qdC7yKe44t2mA.9mCsKl8J9MFPW6OW2.tV.XS6YKrn0rXxLuLIxfifGdTODsxuKcixRMovhKhYr7YxXF1ntXaJBbAlzO+IDejwwH560..gETX73253rKL.ff7KH1yQb7PQHPffK7bEcBItwcuIl3O9gjWQ4S2iqabvjOHO56MNJuhJ.fikxwXmGdWL4YNYhH3voJiF429q4xi8dONdn2C7yKeYWIsK91E7c.PwkVLGL4Cx2rfui8cr8QbQFGGH4CvK8EuLokU5.VGG02bZuMIm1wIlHhgTxLU9re8y4m+8ewg1XaBIRBKnPoJiUwV221ArNjB.jXBCB.9zeYx72ackDYvQP2iqabrTNNu22+ATV4kUu9yrEKbvjOHG4TG0dYETb9bvjOHYkeV.vV22138992mbJHa5Q7cmCexCyi+A+WJtzRZANpe9kryOGdqu4sQgbELs4+s.vAN9g3k9hWg+6DeRl9RmAlMaF.10g2Myb4+JSeoyfG68FO+vh9INcFovq++8lL9OXBrs8uC.3eN3NY1+4uwmNiOiwOwmfEt5Eae6UdEUvG8SeL+2I9j7Ze0aR14myE9c5Ki4PIeXV6NWGO1XdT6kEYqif9009Z+ykUdYrxssJ5Vrc8hgIJPf.GvUzhCl8J9M.3ce72lweaiiG+VeLpxXUr30d1+72rEy7j2wSviMlGgqsei..5dbcim+9dV9e20SA.m9LoTq90aO7lo7rSlm+9dVtmQd2XQRhkrteGIII94k9KHCY7di+c4UenWlu9k+RzqSOy8umK4WTANzNSrGIB.qeWqG.13drMjBceP.vsNrwvycuOKu3C77L9aabzlVGIlsXlrxO6l0wkY8myF.dqG6MY7213X721iSUFqhkrtkzr5uKj3k6dRrQDKComClae3ikCb7Cwjl9GyCdiO.e5SOIRMyTYY1Fu6+4P6jUrk+h1GU64cF2aw7V07429q4v3usGmg2mgae+c6GbG7WaUecXQC...B.IQTPTckLlgNZd4G3EYN+8b43ojL.73ev+kN2tNym+7SlD6wf3Ul5qhjTK1iL8q3YN+87X.cq+z5.B1g0WYUUwaNs2Asp0xcLhwdA15DHPPCwUzhCN8YRAYHiOcFSlWXJuDyakK.f5MCGBKnv..cZzA.QDbD.f6t4N.XxroZ093aSb1uaM1on6H.jVVoQdElO4TPN3m29Qzg0V.PuN8z4n6DVjjH4TS1g14f5w.Af0sy0SQkVL68n6Cu7vK5RLcB.Bz2.I0LSgm4SedtkmYLjzordq2zrEytzwAKVpsyrpE674y5K3ElxKwb+644viKWJhJUpHsrRiNz11iG5cmYr7YvU2qggF0Z3L4lIcrscf8er8C.G4zGkwLzwP2hsKXQxBpUphGYTOL++r28c7QQch+e7WaJ6lduADRBjBjF8tHEQonH1QkSEw5omGdVNOOOuySOKeOO8teG1wJdJHVvBRuHEkdumD5oAjDRumr6u+XSVxDRAjlAe+7wi4wr6mY1Y9LyBYduelOyLA6ePTas0PP9Y+TRk1gSi67puCBOzNP6BNL5VrIydyXe78qXNz0n5Bibf1OkPCuuCkBKoHxsf7tfs82VR9EU.qamqiqZvWUSN8BJtPdh+6SRM0VMu7C++cdt1IhzRZS2mCZMNYxD1bxIFbONQSXdE8eDDr+AaX9p+.80+ravUWretPM0L87+xq7DO0LptlpA.KlsfEylAfpptJCyekUWI.3tat2jKuf8OHRryIxN2+N4k+n+E.bY80dqITasV4Q+2ONETbAL9q3l3ttl6juXQeIqeWanYqefw.MUVUkFllSNYBSXxv9kQzuKifpq+a7KcobnT49ug6C.1wd2A95kuL84OCGSOgNm.f8C5+j24ST2q2KcsScEu8zdfuTOTZjXzI5308Mw933ymeQ4iGt4Aqau6fd1fNIZM0TCUTUEXwUKma2.uHwOskUQP9EHIFc7mzzx7XYwe8MeFhp8QwSNom.yMn+GHhbg2E0sbPbQFG0ZsVBOzvYrC4pvhYKr0T2Ft5p4ynk6l18lHiilI.rn0tX.H1NFCd4gWDc3clBKoP99ULW.XOGHE1zt2L93oODc3ctYWl025AaI0sZ+88196yN2rI2BxkHaWDLgwbKDSGigLywd+anoZdaKtZAmLYhBKoPJtzRvpUar4T1rg4oKQ1ErgMBKnvXrC4pvc2bmsj5VwEm+keVwil2w.rQ6BNLrYyFlL4D280bW7DS7w4Il3iSXAFFWR2GDGLqCged6GA3q+.PpGJUhKh3brbRK88RWhLN16g2G.3rSNC.4UvwIkCkJ8HttSYUTFVav93Ut4ehN09nvGu7972FbaX65.6htGW2OoxKs7R4Iesmhd10dvSeOOkBFHxu.8K+iFbF3dut6gG++2Sve+cdNhHrNxAy5P3o6dx8cC26Yzx0MKt6nSKVToEQP9EDWyvFG.7aug6m+1a+24s+p2gOZ1SiJppBbxjIdra+Qwh4l+WbdY8cX7Fe9aB.QDVGcb8dGZ.gPv9GL6Ki8yi+e9SjWg4Q4UXukKxu37OokiyN6D8nK8jMsmMw8+BO.lc0UGWIG06dtt6lG4UeL9Gu6KPjsKBNXVGB2cyct2q6dNi1ub9P5GMcrX1M1RJaidzktwk1yAy690uGi4RFMKb0KhxqrbBzu.XS6YyDWDw53ykV56kqZv1uRMJorRH6bylXhHZlyJmGgDPH7deyGPO6ROY5ye5Lwwd63smdwP68P3+MmOkvCIbxI+b38+1Ofm499qWn1zay4.YdPF0.uhSp7Ocdyf7KJeJn3B3E+fWxQ4A6evb+mg+eSQjyNbtUltoVX7OmAmZgwMdvDPviYLiYbgXIXL6hYbxoVngNrYuWPmTLIgOd4C.Dfu9yP60PvWu7Ea1rw.5V+4OLgISP9EniOVbQFKIGSR3hytfMa1HX+ChjhI45tbGsgKN6BIESRzkHiiLOVlrhMsRFRutTlvXtUp0ZsLvtM.d3acx3oGdBX+TDb48aD3tE2wWu7kA08AwCN9GftFUbMUs1AWb1EBxufI5v6LWQ+uBZevsC.b1Ym4R59f.afYWckwbIigqa3WKA3i+DZfgQXAEJ1rAIzotRxwjLlLYh9kTewrKlwKO7hgzqgvsO1aCOcyCRJljocAEF94seLzdOD7ya+.f9kT+3gu0I63R77Wx726.nhppfpqtJhKx3nuIzGxofbYaoscRN1j4tu1IgISlnvRKhtDYWbbutnvRJj9mT+vMKVnvRJhvBLL5Rjwwb+o4w.Rt+z4NzYV+NWOiYPilKu+i..hrcQR6BJLV4l+QJq7x3gt4GjHZWGuPt42lRkUUI8rK8.+8wOCkmWAGmnCuyDfO9i+MXHX+Bl3hL1lYoIRaeVsZkppoZNVU4v7l27lMPt.1.rV2XaM58Mt7lafF85yXs1sSuS2vAM7.6M0A7ctQicoAictAC0Wd7SYJS4cSx6D9Ewir40t80w+38dAth9e4NtmDHss8fuzCwCcy+NRnym74EWDQNap9GYy6n3cwjm7juWfci8..0.TaCFpoAkastxZ33FOXqQutkBPzTiOIWT2mCDokTc0USYUTNwzwXtPWUDQjeQ4h59bvYaw2o344evmi.8MvVelkewyUWckO5Ye+KzUCQD4WbT3fSC93k2zitbx89ZQDQjKlzlHbP.QDn8KQuVpCIJhHh7KXVsZEyU6FryKz0jVWahvAl8zBt5hqXxI83HVDQj1lrY0F1po0mueInMQ3f87C6Be8zGG24BEQDQZqo5ZplBKsHvyKz0jVmZmdQDQDw.ENPDQDQLPgCDQDQDCZSzmCZIe9x9RCO5hcxImvcytQbgGGcMhtbZsrJnjBvOureqdMkzSgMk1VnacNYRLpDNqVmaNqZmqlCczCyv6wPIr.BqYmustusw51y5nnxJlvBHLhOhtRuhsmmWpiMTkUWIVsZC2s3VqOyxuZM+0u.5Sb8lf703S8ystusQNElCWduFggxWxlVJgGb3zkN1x2xwEQN2oMe3fua0y1vim3FZT8YjLoQOwSskyplMyd0yg28wda.XeYc.91U8cXwUKm2BGr9T1.qdWqgj5ThMY3fZpsVdkO+UYK6aqFJe1q96I4NkDO70+6wK2857Vccpe+6wyNw+Ftao8mWVmRaOKbCKhOZAeLwz9nOovAqXaqjdGWuLT1lRay7ty884NG0cnvAhbATa9vA064mzygYWMiUq0x9y9fL047trfMrPt9K8ZwWO8sE+rVsZkouzOCuc+DOJd6WW6KcLjvIL+C8bbM+T2murOmsrushud5K2+XuWhK73H67xhoNm2msefcvmr3oyu8puuyK0kuaUeOEWdwmWVWWHM6UOGRLp3oysq4ebaKmrpptJdqY+Nr8Crilcd1192F20XtSCk8xy7UH.u8+bbsSDo0bQS3fvCtCNdzDGUXQwmu7ufBJo.JrzhvWO8kLxISlwO7YbnibHrAz9.aG+lQbqDUXQw+4q9u.P4UUNOyzdNt6wLIxJ2rXdqeALhdNbB1O6OsBSMiz3q+wugCczCg+dG.8qq8kqp+WIt3ryXylM96e7+fHBoizsNmLe+ZlC4TPNz2tzWt8q31vEms+.v7KWwWwZ285ovRKDe7vaFR2tTF2ft5Sosw4s9E..+9q82QRcJQ.H1vik+5s+W39+2O.KaqKmaZn2.A5Sf7LS64HhP5HcuyciYu5umbJLG5SW5C2wUb63hyNSoUTJy7G9b1wA2EUTU4Df2Av0eoWmgSOwbVybYk63mnxppjnaem4tF8chGt4Ae4J9JxHmL.fW+aeStx9OFFbRWxY9Wh+BSIkWJe5RlNe1S+oWnqJs4L20MOptlp4kt6mme+q+GNoou+r2OgEPX3oam3Z55eMyWkac32LqY2q87YUUDoIbQS3fsefcfqN6J0XsFRI8TofRJ.+8xeZWcMO+y+ouHkVdIL3jGLkTdIr9T1.S4qeC92Ov+Bq1rB.1rYCqVshMa133EmOojdJz8N2M.68Agm8iedLYxDcO5tQl4lIyXoeFGH6Cve3Flri44vG8vrk8tE5Yr8jLyMKVvFVHsOv1wn56H46V0r4KWwrH1NDKIDY7rlcuVl9R+LhHjHnGwzx2VlO3QNHUWS03oad5HXP87wCuItvikTxHUNzQOLA5SfmTcIq7xlEtgEQ6Cr8L59NR93E9IrhssRFYetB7wCuYwaZo7Je9qxKd2OOQEVT7kq3q3KWwrHpPihDhrqrzMuL1e16m+8C7JX0pMrU2CyKq1rgMam0dJgdJwpUqLm0NW1PJaDa.ituijAk3.Ar2GThOhtxh2zRHq7xhQzqKiQ22QAXuItW91VI1rYig1sKkQ02QBX+6suX4eEEUVwzyX5A2zPuAJpzh3+7USAytXlOb9S6T9zSI1cU8+JwUWb0P+Apg1xd2FcO5t438KZiKghJqHtlKYbJbfH+BvEMgCd0u3+X38QEZTbei8twUWbkZpsF9cWyCfUqVo6Q2MJo7RYWGZ2bz7OJ.7X23ivDdwaGOr3A+iI82AfcdvcYX484K6KwpMq76uleGWRRChpptJ9Kevei0r60RJomBwEt8yOZ4UUNu788RDreAS3A0A9f4+QjYtYB.8oK8Ae8zW5e78C2L6Ft3ryLm0NOG0iVR4UVN.M6oHwWurWddEk2I9LUUN+y66kHD+BlNFb379y6CcTWxJurvjIH.eBf9FWuYfIN.rZ0JgGb3TSs0x2spuGOcyS9GS5uiqt3J93ou70+32v5SYCL9gcir8CrCRKyzXxW6ui1Gz429bvmr3oSAkV.O4s9DTTYEyyLsmkNDT6IxPijkusUvtO7t4AG2ukxprL9qe3emQ22QwgOV5rfMrHd9I8bTQUkyS+gOCQ29noVq0xT952fG+ldD5XHcj276daVv5WHipuijtFQWH7f6.2zPugyqaeWLn0tgks08sU9MW9D.r+uYe+48AL0G4sNeT0DQNEbQS3fG5ZdPNVA4vr9wuF2M6FSbT2tiySrKN6B96k+rvMrPlwR+LN3QOzo8xeuYsO.nucoO.fYWMSuhsmjdNoyANxAcDNvCKd33zPT+AxqttNLYH9ELaYuag+yW9eYuYsOJshRAnY+0UMTf00YtJnj7axomewEXe974DOwH8vh6DRiqK0TM.LhddYr2L2GyXoeFyXoeFA4SfLrdLTtF+CkbJHGpplpvImbhWb5+e.X+t5EPV4lEb5cQfbVU9EmOKeaqf2XxSA2L6Ftawc5YL8fccnciud5K4UTd7rS7YHHeCjLxISGcPSyt3JGuniyR17R3J58kyyNwmAe7va9We9qxv59PvrqV3n4eLhOhtxV2213pFvURV4lE8O99cdqSd9qEUTUEjdNoSbgGK1rYi+0L+2LoQMQbyraTU0UgMaPs0VK0TaM3hyWz7mnDoMkKZ9ed8oK8F2L6Fd5lG7gKXZ7RS+exKeeuDgEPXbrBxgm58eZb2h6bsWx33AhLdd4Y9pb7hN9o7x2hqVnxpqjppoZL6pY.nxpqvwzpmqtbhcoN6jyFVFu4291rpcsZtzjGLS95dHRKyz3KWwrvjoV+YFQH9ELtY1MJqxxYy6cKzyX5giokWQ4QZYlF.DYnQ3nbWb9D+5sF+PqZX8XnDW3wxp10ZXGGXmNpKN6jyNZhdOcySFP782vmKpvhrUqqmKsur1Ocoiw4n+k.PoUTJVb0B6Kq8SrcHVBptGo16Kq8QmBKJ.Hr.BimZB+I9xULK91e563AF2ukdEaOYOGdO3gEO3qV4rbr7p+RfceYuelvHt0yeab+JwV221na0c55NxwOJG7nGjObAGjObASyw7bvidPV8tVCO+c8bWnplh7qZWzcSPZT8cjjbmRhppoJdiu09kkXpYjJUUSUzyX5AioeiFuc2aJrzBc7Yp+.m0TaMX0p0l7Rir9KmwYsxuFqVsRV4lE+zNVM.jbmR9TptsyCY+Qw0cM56jtGc23HG29oS3T8T1eiC45AfW6qecV6tWG4Wb9r8CrCdgO09ute38XXFZ4fVx+cVuFuybdWtx9MZ96S7uxCb02O.jWQGmf7MH70SeonRKjdFaOYT8cjjeI4SJYjpiNPlS0EnoxpqpYuTROWnrJKiZq8DszRwkULae+6fj5TRNBNTu8m8AH51GMkTdI7Ve26PrgGK+4I7mXhi5N3iWzmXelLYha6xm.S95dHl708PDl+gw.SX.jWQ4QEUUAc377oL4WC159NQ+MHD+Cl2bxulggHBIBF+PuQdha4OdAtlJxudcQSKGzPO5M9GXR+q6gzxLMVzFWB8ttdf+x15xIuhxiCdjChEWsPo0Vpia7QA5SfjWQ4wD+mShG8ldjSZYdqW1sPJomByccyikr4kRkUWI.LoQMQBx2.Ok5TdIDYBr5csFdp2+uhEWsPNElC.jeybpBZrQ22QSV4lMKcK+fiqvh5kbmRheyHlvozxAfP8OTV8tVCOxa8Xzgf5.6O6CfSlLwH54kgyN4LSbj2Nu927l73u8SP6BLLNzQOLgGTGbbspGnuABY.+sO5Y3pFvUxsL7a9TdcelnGQ2c9eK5SXYaY4Dp+gvmtjYvUMfqjP7KX1WV6ig18g3Xd2aV6iadX2DdXwCRI8T3qVwrnGwzC1WV6mNFb3.v.SX.7wK5SXj84JX4acETbYEyMNjqmcdncg6lcmsu+cPxcNoyKaa+ZwV2+1bDz0Ymbl.7I.CS2YmbBObyC7wCuapOtHx4AN2JS2TKL9myfSsv3FOXBH3wLlwLNep1abyrkSpY5A6WgAIDY7DeDw6X5t5hqDaGhkvBHTb1ImnaQ2M5Qz8.Wb1Yr3pEt4gMd5aW5CgEPnDheghOd5Cw0gXvlMaDQHQPehq23k6dRf9D.IDY7DreAimt4ICs6CEe8zG7zcOoGQ2ct8q31necsumXmkIHgHi2wud0F1uRBRHx3o8A1d5Sb8AmcxIb1YmIonRj68ptGb2haDp+gXu4usY+RxLgHS.ub+jerc4jSNQuiqWz8N2MB12fwWu7kdGWuYbC5p4lG1M43zcTu3inqzkNdhNHf2d3MIDUBz9.aOI0oDIl1GCt5hK3hytR25bR7.i6AH7f6..zwP5H8L1dfmt6EN4jSL3jGL2+XuWGMmercHFpo1ZIz.BkdGauHr.N+b+fvhYKzut1W17d2BG5nGlQzqQvk0ygCXuUD5Ur8zQcr3xJh9zkdiEWsvfRbfrur2Gae+6ff8KXtsKeB3rSNSOiomjewGmcbfcRW6XW3NF4siISlvOu7kppoJJupJH1vi47x11EkrAlLYh3iLd7vhGTTYESAEmOCJoA0herNEVTmxsBlHsUX0pUpr5JoHyEy7l27lMPtX+PEVqarsF89FWdyMPid8YrV6jce5FNngGXuoNfuyMZrKMXryMXn9xieJSYJua3k1d8HaVDQj1zp+Q1bFdlESdxS9dA1M1C.TCPsMXnlFTt05Jqgia7fsF85VJ.QSM9jbQWeNPDQDQNynvAhHhHhAJbfHhHhXPahqVgXGbbX1Uy3jIkkQDQj1lrZyJgTcUjwly5BcUoU0lHbPkkTIlLex2TgDQDQZqnVq0RkUU4E5pwoj1DgCJ5HEhU27DWboMQ0Uje0pjxJgBJtvVeFaE95ku3sm51VsbwkZpoFJotaa9+RmNZqHxYMKdsKkOaAyDe7xme1KihKsHtgQbCbiW90eVrlIhb5PgCDQNqZD86x3du969m8m+C+to05yjHx4Ts4CG7Iyc5FtW66jSNgGt4NcMp3Iwni+TZYTVEkyWrnuj.7M.t5gbUjS94xb+w4QGBoCb48+xZxOSkUUIu7zdEt5gLV5QW5tixW3pWLYma1DWjww.6V+axO64ByYkyibKH2lc5W8PFKA3q+mxKuxqnB97E8E.vsckS.mc1d+8n1ZsxmL2OEe7zGttK6ZNypzMP9EU.96iem0VdhHh7yWa9vAe4h+pl8A+yXuzqhe6Mdes5xnhJqfuXweIQ09n3pGxUQ9EkOewh+R5S78tYCGr6CjBqcGqia+ptMGkUYUUxT9rWC.7ya+NuFNXoqeojxgRsYm9P68PNsBGTQU12m.1eRSNgwX+oSnMaV4KV7WR6Ct8mUBGjWAGmWeluAgFXnmReWUuhJsX7zMObDZQDQjydZyGNnd+6G8UvrqlwpUqr2z2GS4ydM99UNGtkQcy3m29dVe8sq8uK7xcuHp1ehGgwKbMKF.bxjSTPwEvZ295n+I2uy5q6lxieGOlidA6+2G9OIiikIOwDebhHL6OBmaev+7e5BN84+YbEC3JHX+C5rRcsg19d2AqeWafwdoW0o0m6N+aShO7u+A3q2M+41dG6cmb3ijNW4fG8YZ0TDQ9UkKZBGDQXcD2rX+AtSmCuS7+l6mP9EkOETbA3m29R5GIC9nYOM1elG.a1rQGCMblz3tS5b3c5m05aG6amjXzIXnrEr5EB.2xntYl97mAyeUK3jBGruz2OS66+ebnrODd6o2L79LTtgQbhNd0J13JY9qdgbnrODA6evbqi5Vn+I2WZMsKnvb755e.LEVfgYH7xt1+tYlK7y4.YdPB1+fYPcefbsC6ZvYma86eDSYFuF+iG7YaxoURYkva9EuMobvTvOu8ig16gx3F5XAf27yeaNX1GhgzyKkwNjqjcr2cxGOmOAOc2Stiq513yVvmA.qZqqliW3w4ot6mrUqKVsZio9zuSKFL.foO+YvUOjqtUWdhHhXzEM2Ug1bJakMtqMwZ2953C+1oQ9EkOA3S.zg59EyO0a7zro8rY5YW5AwFQLr4T1Bu7zdke1quctucRRQehGkuodnz3fYcPhKhXYBi4VvUWbk0uqMPdEbbGyygyNcdjW8QYm6amjbLIQM0TMe32MM9hE8U.vRV2R4k+3WgLOVlzmD5M4jeN7Odummsl51+YWOq21Ra67jS4oXqotMhoiwPAEW.e328Q7u+j+SK945RjwQP9EDaNksvJ1zO1jyyi7pONqXSqj36T73rytvTm06xLWn89qv0Nrqgcs+cwa+UuC4jet7Re3+jcs+cwXFznwlMaXstG001vFVsY8TZaY86b8rrMtb.3+MmOksjxV4k9f+I+tW52yrWwb.f2XluE64fovrV5rnvhKhiWX97em9qwC7hODO6TedJr3h.reoE8O+n+EqXiqjG5e9vjxASk+uO7kY1qXN7.u3Cwq7w+aJqhxOkpWhHxEKtnIbvK79uHOy67r7OduWfuZoyhnCuy72t2mFWc0UpolZ3wtsGkm9d9KL4a8g3gu0eOd4tWjctY+yZckxASkZsVqgVNXgqYQ.vk02gaX77W0BbLOe4R9JrZyFOzM+63wuiGkW52+hLrdOTGm1iuXQ1OG+u3C877H+lGlm7NeBF0.GI1NEOnYK4SlymhUaV4wu8Gk+188W3M+yuNgGR3r7MsBR8Po0he1+vDlLf8VOnwVwlVIYma1LlAMZd763Q4ke3WhP7ODl0R+ZpsVqz9PZG220eu.v8+BO.EVRgbUC9JoeI0G5b3chILZ68kgKo6Chm9ddpSosk0uqMfo5d9ftj0sDl4B+btmq6t4QusGgOptd59P68PvaO7l+7jdR70ae3Q+2ONwFQr75+oovP60P3Ed+WD.NPVGjsk11YOGLE9827uipqoFV0VWMd5lG7+6weUpr5JYlK7yOkpWhHxEKtn4zJ7X21ixwN9QYFKXl3tE24dut6kXhHZ.vEWbg.8M.99UNGlVcmZgyDaeu6.yt3JwEYrNJag0cJENV94vWt3YQUUWE.LuUMe9MWo8C.d3ijN.DaDw..96ie732wiBX+p.HiikId5tmzgPr2ZGIGaRjbrmn0INSjV56ESXhA1sAB.VLal9kTeIiklA6M88YXaow5QW5NCsWCgkuoUvTm06YXZ0uMs4T1BO4Trev8xqrLJs7RI+hxmf7OPF2PGK+3V9I1092Ed5tm7.2z8elssb3zXH85R43ElO4VPd7pOxqPf9E.kUQY3smdC.G83GkXiHFBvW+Yd+z7IH+BhtEaxjctYSLcLZR8voQs0ZkTNXpDVfgw8cC2C.7M+v2xf59.4x5m8vcCuOCi49iy6Lp9JhHs0bQS3fA1s9iaVbCOc2Kd6u5c3u81OCuwe50ncAGFGMuiwC+JOBd3lGL9q3lH4XRhmcp+Cxqf79Yst1092MIFchNd+hVyRbz73yZoesg4sgcLw56K.M71m49Re+z9faOt6la3hytPkUUI1rYCSlLQkUUIYm6QH7P5vY7cGRKtZgpqoZptlpvYms22LpnxJ..2qquZzR9CSXxr7MsBl+plugxq+4cQm6PmnawlL.L3dbI.fYy12dKuhJXW6eW.PokWJqY6qkAj7OuqjiZq0J6Ki8SbQDKaM0sQBcJdBzu..repchsiwbhWGg8.O6Xu6Da1rwzm+LbrbFT2GHN4jI1a56kg0mg5n7TObZz636ki2meQEfmt64Oq5pHhzV0EMmVg5M1gbkzytzCpp5p3Uq67ou6CrGpp5pnuIzGF2PGK93oOTPwEbJuLyN2iv2uh4v1Ry949em6emjjgvA1OkB2y0dW7ud3+oigq+xtNfSbpE5RjwAXu0DrYyF6Z+6lG9UdD9SSwdmvKtHiiZpsFV7ZWB.L2eb97P+yIya+USE.9g0uL99ULGpt5pOs2uTeKPL84+YXylMx3nYxJ2r89PPO5ROZ0Ouqt5JO3M8.NBAUu5awgxpnLtpK8JYD8aDrtctAR+nYfO08q3e1o9b.1u43.vy+duH0Vq8SUhS0c9AprpJolZZ5KI0FJsCmFcLT6c9zTNTpDemOw8xh8l9dcDHXuouWhKhSzZHWZOuDdhI937DS7wYPcafLrdOLLYxDobnTI4XL12QbwYWc79kuwkSeRn2sZ8RDQtXxEMsbPC8muqmjw+mtE1yA2Cy6mlO8KQ6Ww.KZsKlbxOG1WF6G2L6FkTdIjeQsdHgCj4A4s+poxohouMA..f.PRDEDUnF3HwGO8gRKuTRrtNiXFGMS10A1Mlc0LW6vMdc+2gP6.yZoeMqeWafbyOOF+UbSrxM+iL+Us.V9FWNkW2ubehi8N.f69ZlDO0q+z7emwqwTm06Q4UVtgoO84+YjctYyv66vvUWckSG203lTccPuul49iyiJpx959gt4e2o7MenqbvilEslEQZouWGk0mD5M8Kw9w51453td16kZqsVNdQGmadjiG.l0R+F6WYGcNQdjeyCiYWLy7V074Ym5+fm6AdFB1+fAfEu1kvZ19ZYFuzmzh0gTObZNBjj1gSiQMvQ5XZobnT4NuZ66qN7QRmLOVlDWjwxP50kxa9EuMcLrHHyikI+u47I7t+02gJqpRN5wOpiqnihJoXNdQGmkuwki+93GqXSqD.tr91z2qKDQjKV0Z2AYL0Bi+4L3TKLtwCl.BdLiYLiKDKAiYWLiSNcxMzgMaPxwjHIEcRNtg33pKtRW6T7ztfBCmL4L8J9dPeRnO3hytfalciaer2FCnaCf1GTXztfZG93kO3pKtPRQmDwEYrXyF3gatSRwjLcpCQA.95kOjbLIQsVsREUVNianiEmc1Yx7XYQv9GDibfWAQ1tHMT2rX1BA3afDSGil.7M.ZWvgwnGznvC27D+7xO5VrciG3F+sjXL16XiA4WfLzdMD7xCOwOu8i9lPe3ou6mBe7xaGKytDYbjTzIgKsvM+Ga1r2uFRJ5jvC28..71Su3J5+kiud4Kd4gWz2D5C220cOzujZlKSRa1u4GkbrISLcLZGEmPmRv99hXS1QKgLzdODBIfPwcKtQ6CtcL9qX7L1K8JAfsjxVI4XRjIL5aEu7vKRJljvUWbgf7KPBstK0R+71e7vM2o6w0c5dbcCS02aCaBEVRQDemhmPBHXJpjhneI0OGWBqEVRQLntM.b0UWIX+Bl8m49omcomDUGhjvCoCrpstZLYxDOwD+i3q29PgEWDgEXnN5CH6Xe6hLOVl7fi+AXoq+GHX+ClGb7O.tpG3Wmx1yASgxpnLCmZlSWaIkshEWsPBc9T6NbpHsUX0pUpplp4XUkCyadya1.4BXCvZcis0n223xatAZzqOi07+UXiS+TMbPCOvdSc.emazXWZvXmavP8kG+TlxTd2j7NA7ROUFkywlw7mIEUZQb+2v8dgtpzl027CeG4jeNmwOaE71Cu0CdI4hN0+TYbGEuKl7jm78BrarG.nFfZavPMMnbq0UVCG23AaM50sT.hlZ7I4ht9bfH+bkS94PhcNgVeFEQjKxoeJtH0Yx25CcgtJHhH+hfBGHhbVUdElmiqrmeNx434f2d3cqOihHmynvAhHm0DjeARN4mKSedyn0m4lQ00TCC373SzTQjSlBGHhbVyf64kvf64kbgtZHhbFpMQ3fhysXL4o8KQQQDQj1hptlpo3RKFrbgtlz5ZSDNn1ZpEq0XEqbl+.HRDQD4BAq0XkZqo11DgCzkxnHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFzl3pUP90oZsVKkVQY3yuxua4UVEkQU0T0IUtEWsf6Vb2w6OxwOBkTdIDp+g1j2gAqo1Z4HGOarZyFg4enX1UymSq2hHscovAmkjag4xx25J3FFxI+jja6GXGTbYEyfRbfW.pYsccjieTdgO8E4Me3W+b55IkzSgry6HLrdLzyoqmet9vELMV6tWGVZzAyGdOFNSXD2BEVZg7+MiWlBKsP7yK+I67xlAlv.39F683XdW0NWM+uE8o3qW9hSlLwwJHGdfq99o2w8y+Qq74ZokQZjdNYvk0ygegtpHxu5nvAmkjVl6kzxbuM4zVxlVJ8H5tedtF01Wn9GBO2c9rmyWO+vVVNcJrnNmudNSLtAc0biMQvS.9pU90DYnQxu8puO.nzJJkmXp+YV0NWMCJwAxtNzt38l6GvSea+Y5b65Lf8.q+qY9p7ut++Ig5eHm21NNcrxc7SDjOAdgtZHxuJ4bqLcSsv3eNCN0Bia7fIffGyXFy37oZuwMyVvYmZsp6om23aeKbxIm3Cl2GwbW67wrqlIxPiD.NzQOLu6bdO95e7a3vGKcRHx3wEmcgOXdeHkVQYDQnQPoUTJ+qY9pDQHcjOYweJYka1jeI4aHHv51y5Ygabwb3icX7yK+nCA0AV5l+A9nE9wrzMuLp0ZMDc6s+Gre6YOUpn5J3c992ikskkQGBp8rt8rAl5bdO1S56gDiJQL6pYd6YOUJrzB4cmy6wOrkkSX9GJg3Wv.v9xZ+7Ve2ay2spYyANxAIwHS3b5cVxku0UvtO7t4KW9WwrW8b33EmOIEUhN1dxsn73c99oRP9FDA3S.7IKd5L8k9YrwT2DsKv1Q.d6OyZkeCkTQIzgfZO.jR5ox7V27HhP5HSeoyf9Ge+.f4u9ExzV3GyOrkkQEUUIwzgnwjIS71ydpz9.amilR+sm8ToCA0A7xcO4KWwWwGsfOlkt4efxqpB5RGiyP8eK6cqL20MONzQOLd5tmDQHQvJ29OxGL+OhkrokPEUUIwFdL.vGLuOjRpnTdu49Ar3MsXB0+PYq6e67ty48Xq6eajTmRBKtZg2edeHGu3iy6OO6Ki.8IPBKfv.fzOV57le6ayW+ieK6Mq8QhQk.lcokad+0mxFvK28hDhL9lb5qb6+Hd4tWN92clcwLcNrnHXeCBe8zWd+48gLvDF.CJwA43yDp+gf+d4OgEPn3gadXX4UU0UwGL+OhYrzOieZmqlnBKR72K+38m2GRP0sLA38l6GPv9FD1rYiOYwSmstuswL+gOmtzwtvWr7ujsrusxLW1WP+5Z+nvRKh2d1SkubEeE6Mq8QRQkHt5hqr1cuNRMiTYQabI7oKYFNlVJomJe2p+dR+XYfEWMaH7VQkULSaA+OxL2LYpy48YyosYRHx34SWxL3SV7z43EmOI2oj.r2hdu0reG9xU7UjVl60v96YsxulOdQeBycsyiTyHMRHx3whqVXmGbWN9+PojQpDaGhA2s3NezBlF95ke3uW9A.e37mF96ke3rSNyGN+owtO7tY5KcFzm35CkUYo7Vem80aJompi+uq7qaVsZkJqtRJxbwLu4MuYCjKfM.q0M1VideiKu4FnQu9L1E0cHw7JJO1992QyN8cencyh23R3AF28ysdY2LScNuGEWVwTU0Uwe989KLx9bE7Olzyhmt4Iu1W+F.vv5wP4s+9oRQkULuw29Vzov5DQDRDbE89xIxPifqevWqg0Q25bxDS6ilg2igQ25bx7ia+mX9qeg7PWyCxidi+AVxl9AV41+Q.XOomBqdWqgG8FeX5SW5Cu3z++vlMq7W9MOIEWVwrzMuT6y2g2C+3N9I9a29ek6bj2Nu7LeExqn7n3xJl+9G+bLl9MZdt67uimt4Iu7LekSo8UUUcUrpct5S68wGM+iwWr7ujaZn2HO6DeF1wA1Ae+ZlC.jZFoxlSaybGi71IxPif256dGrZyJO6D+abUC3J44+jWjxqrbBKfPY9qaANVlKcy+.A5SfTQUUxdN7d.feXKKiEtgExCe8SlG4FdXVw1WIycsyyw5o7ppvwmeOomBUTU4rwT2Daa+amm4NdZd7w+nrnMtX1e162P8OgHimtFQW4RS9Rn2w1a1PJaju9G+Ft+wdu7Gu4Gi0t60xh13hsudxburhssR9C2vumg1sgv+5yeEJtrh4Iu0m.a1rwBVu8sgzxHMV5lWF+kI7jbuW48vq8MuAYkWV1+2Uu+SyH50kwKbWOGg3Wv77exKdJseN0LRkueMywvPtElG.b0CXr7S6XU7nu0iyGN+owl26VnKcrKzwP5H.r+rO.cMhtbRKyg0igRP9FzIU9aM62gpqsZ96S7Y35G70xy+IuHUVcUjVFoQoUTZCpSoQYUVFUWS0rzM+CXwUKbiC8FvhYKrzM+C3tY24FGx0iOd3M+w24OwfRbf7B20ySGCNb9my7eA.4TXNLsE9wLfD5OO8u4OSNEjKye8KfXCOVRtSIw.Rn+Lf3M9PXp5Zphks0kQU0TE+0a6ovEmcg+z69mYfIL.9ii+wXYac4rurr+87SL0mjAlv.3EtqmmHCMR9+lwKC.KZiKlstuswe5V9i7b24emBKsPlSc+6o+6rdMtkgOddo64Ewa28lucUy192qYtOJorRbTORKyznjxKkZpsVVw1VIfItwgbC3u29we5ceJ5WW6Kuvc87DSGhgW3SO09dVjeo3h5vAA5SfrjMuTV6tWWyNOW8.GKA5Sfz8n6F93gOjeIEvx15xoKcLN7zMOHybyjdGWuXiosIJqhxnysqybsWx33odu+BETRALgQbK3jSNgmt4It3rKmTGAyMytgqt3JdXwCbyra7CacYzut1GJrzBIuhxkAjP+p6OrX2n66nHPeBjdGaOwjIm3pFvUhed4GIDY7jWQG2w7cyCa73tE2H1vikdGWuXM6Zsrxs+Sz+t1O5Ur8DObyCtkgeybvibHNVA4zh6mxsvb4klw+j3BOtVb9ZNCN4ASLcHZb2habsWx0vp14ZNw1S+FEI2ojvCKdvZ18Zo+csejYtYh6lci3BOVV91VICJwARZYtWNdcaeqXaqjg18gXXcrxs+ibyCa7DjuAR.9D.25vuYVw1WIsDObycx93Ggku0UPU0TIS4g9ONZV85Y1UyX1Ey3gEOvcK1+9oOw0GJqhRImBxg9Ge+XEa6GcL+irOWg8uehqWTU0Uy0eoWK94kejXTIX36mwOzaDObyC5T6hhADe+X06bM7i6XUzin6N8qq8E2s3N2zPuQxsv73vGK8Vceb4UVN4VXdFFptlpAfN0tnXJOz+gqevWGUVck7ty48Xxu9evwxs5ZpFWb9Tq0iptlpY8orAt0geK3k6dR2ita72t8+BN6TK+mJLYxD2zPuA5Sb89jd+p20ZncADFA6aPjYtYPBQFOoerz4n4eT.nactazsNmLA3S.zqX6A4UTdXwUyX1Uy3tY2LzoKanqYPiC+7xORpSIQbcLNRLpDncAFFQDRGIuhxi0t60Qf9DDg3WvjYtYP7QzExJurIq7xlAmzkvicSOBt5hqbjieDb2h6TbYEC.tawMV1VWN64v6gINxamIM5I1p62rYyFieX2H8sK8gMjxFwGO7g1EPXjYtYPbgGC4VXdjQNYbJ8cfH+RPa59bv51y5Ya6uketwWUMUw+cVSgGe7OF8J1ddRS2K28xwqc1ImvlMajeIEP9kT.e+ZlqioMf36OkUY43gadP+5Z+3KWwr3R61kdZWmyu37Y2GdOjQNY5nrHp6W3Afm00DuN4jS3t4S7GEcxjw+3r+d6uiW6iG9PwkWBVsVKAzfxcwYmwGO8l7KNeGm1gFqhppfm8i+G3pKtx27SeaKV28vhGLgQbKmT4AXnt3MkT9I90Ud6t2N1tcwYWb7qvAvcKti20s+e38XX7i63mH.eBf9zkdimt4IETRgNl27Kt.7qtlyE.+7xOJnjBb7da1ZPqoU2qSHxD32d02G+vVVFewJ9JB12f4QtwIS6Cr8M61X9EmOkVdYbrBNlix5TXQ5300+8iISlvMyt4nbmL4jg5P.9DvI1GT22OMdek84yeJnjBL7uAZJcO5t2j84.a1rwFScSziX5NCN4KgAm7kfMa138l6GvmurufGe7OJg5enbz7OJwEdrF9raH0MR6Cr8z9.amixpnpJnlZqA+7xWGkU+oZqtUng0c87vh6FN8UtawcbwY6+4k7Kt.Jo7RL7+m5Vm6FUWSM12+39IBT6rSNiUasdKiZwU2br9b1ImvMWcyvzsYyFETRATVkkYX8lbmRhZqsFNxwOBuw29VXCHxPifZsVK02hrO0D9yrnMtXdmu+cohpJmwOrwyn66Hsu.LYbcTOytZFKtZ+Fle9kT.UTUEFVuIFUB0sNDosg1zgC5WW6K8qq8sEmmW8K9O7W9MOEIFUBM4zMYxzIUVH9ELA4Sf7GtgIC.UVcUrvMrH70Se.fW6qect0geyL60LG5eW6KQcJzY1rU2e3ID+BgdGWu3J58kC.GH6CX3WbZhSt9zTNxwOhiNRVl4lICNoKgppoZ1TZaxw7TR4kxwK53DbSzzw0yMytwKd2OOS4qecF2ft5lMDQKI67NhiWmQtYR6p67qCmX+aP9FDVsZkINxa2QvlUsyUSGCNb.XXceH7Ny48vOO8kKuWi3jVGg3WvjQNY3nOCjQNYPP9Zut5rSNS00co9Uq0ZovRKBv99VWbxE9ii+wnlZqkW+adCVxlVJ29UbaFV1lLY76mnaem4pG3XAfCerzIybOQPtS0uexNurcb.+LyMSRLpDwK27jcbvc5Xdpp5p3HG+nmQc5NSlLwGL+Oh6Zz2I8oKm3Ws2410IV2dVO.LnDG.KZiKgAk3.czucJuxJ3cmy6ycOlIYHbf2d3Mta1cxNuro800GPdqu6c35F70fSN4LUUWqUX0pUCgyZIg3ev3o6d53+OAvrW8bNofRmz1FlNiNApA6Wv3gE2MrdmyZlKA3S.7em0qwP51kx3FzUC.Sag+OJuxxo7JqfMk1l31t7Ivsc4SfMk1l40+l2jQ22QhKN6LUVUk.0G9nvlb8FheAialsXX8N20NOBTctRoMj1zgCZM4UTdb0CbrmzuXp0L7dLLlwRmIe5RlAcuyciEuokPkUWIW8.uJl9R9LBzm.4ZtjwQ.9D.u7LeUdyG90vCKdP54jgidHdC4tE2YCorQhLzHXrC3p3+2rlBta1cbyra7IK9S4ZtjwcZus8+VzmPsVuU1e1Gvd3fjuDLgIl4x9bl4x9BhOhtxbVyboucouDfOAPF4jAybYeAO1M8HmzxxaO7l+7s9mX8orgeVgCV8tVCctcch.8IPlwRmI+9q82cRyiYWMyX52n3+7USgqevWKGI+ixmurufW99dI.nSsqSXylUN3QOjiCx0PicfWESYVuFd5lm3jSNwzV3+i6bT2A.DUXQwW+SeKkUY47S6bUN53WUUS07Vy9cXhi71c78SSElzMytylSaKz410Ytx9OFd4Y9J3k6dgud5KexhmNirOW9o89jouzYfqt3JoerzI0LRiG5ZePr3pElwOLS9jEOc5dzci4utEPRQkHsOn1yQy+X7QKXZ7GG+igSMQS3uiCrSpo1ZLTVP9FHWduFA2xvGOS4qecFYetBZW.gQtEkGKbCKxwAmFUeGEaH0MweeZOGWVOGN0TaMrf0uPhK7Xax8Gic.WIuy2+tb8W50QpYjJG3HGjf7MX5TXQx2spYSM0VCqaOquIqmMk9DWuYFKcl7dy8Cn+cse7S6bUjQNYvUOvqpE+btawM1192FcI73Zx9LQqoWw1SlwRmIu6bdOFP7CfUuq0vAO5A4pFvUR.dG.olQZjVFowAO5gXU6b0jXTIf6VbiEswkvwK1dGKdK6aqN5vvQEZTL60LGLYxDaH0MhUaM8SI1tGc2vrKV3sm8T4RRbPrtTVOolQpbk8eLm1aChbgxE0WsBdXwiVMsdrgGiglGN1NX+8inmWFG5nGh8j9dHlNDMS3xtEp0Zsr2r1K2vPtd7vhGDYnQfISNgISlHtviCa1rRgkV3I0qx6XvcjiUPN16Q4wzcRtSIwNN3NIqbyjQ02QYHLQLsOZb2h6XC6857F165Czm.ncA1Nl+5W.WykLN14A2Et3rK7.i62h6lcCSlLwk0ygy9yd+jZFoQxcJItkgOdLYxDUUSUrrsr7l8ZF2jISDdvc3zZ+K.67f6ptegoMNzQOL2xvGOIzfVoI512YGmy3tGc2vcytylRayTi0Z3tGyjHT+C0w7FV.gQRQkng5gYWMSbgGGg5eHjTmRjsrusQ1GOatkgeSzyX5A.jbmRliW7w4.YueFQOGNcJrNQjgFIgGb3zovhhss+sS5GKcFceGYSdvvvCJbxqnbwcKtS2itaz8n6N67P6hzOV5b48dDLztYu+OXyFz410I7zMOAafqt3BcMhtV2RwFA3S.zgfZOKdSKgqreigTxHUrYyJO339sNN8UWVOFNG5nGjTROUhOxtxsdY2JN4jSTcMUyh2zR4x68HZxVyxhYy3jSNYXvCKdRmZWTDYnQRuhsWjQNoygOV53lYKbmiZhDaGreUV3hyNykl7fwEmbg8m8AnnRKhgz8gv3G1M0jemlPjwiGV7fMj5Fwrql4AuleKlcwURLpDnvRKh8k09Xnc6RI1NDKQDRGwcKdfYWbktzwt3X+TCeu8s6gQV4lE65v6l1GX63tGycgyN6L1rY+eWWeqTXylMBz2.o8A1d5PPgSdEcbrX1hiNWYc6paz9d6mlsF9uahLzHwGO8gKqmC2w5Mr.Ci68Juab1YmI4NmDGqfiwNNvNI.eBfaZH2.0ZsVhoCQyfRbfrur2O64voPv9FDSbT2At3rKjXjIPIkWL6My8wkj3fH9H5JgGb300eibl3aP84x54vIqimM65P6lf8MHtuwduNNMKxud0V5pUn0ZizS2vAM7.6M0A7ctQicoAictAC0Wd7SYJS4cCuz1iud5y4zKIu1R9CuwixCeCS9z5ZyuvRKjYrzY53Zg+rkOeYeIUWa07aFwsdVc41V1S9tOESbT2ggCVzZJo7RYZK7i42cMOv4vZlHxERUWS0TXoEQFdlESdxS9dA1M1C.TCPsMXnlFTt05Jqgia7fsF85VJ.QSM9jnnrsA4acWa0mN7xcu3tF8cdVut3tE2w0Z0+Lpg70Sew0Syeknmt4A2yUdWmipQhHxoG8W0aC5Ym3e6z9y3rSNeV+lHEPqddi+0n+7D9Sm1eFSlL4n2tKhHWncQ884.QDQD4zmBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHhAJbfHhHhXfBGHhHhHFnvAhHhHmmbj7NxE5pvojeIFNvVcChHhHWzHqbxhsbvs13h+E4w7NaGNno1.abYM2NglZGzu31gIhHhb5JiikIqauafIMoIUeQM0w6ZoiO1Ruu4J6msy2sbfsF85FNHhHhbQmLNVlr1zVG24jtSxdaY0ZydycrwyqGm7bc3.aMZbiKWDQD4hVoezzYsosNlzjtSJXOG+mSeNn4N944ziidtHbvO2JdSkRRgHDQDoMoCcjCy5Ra8LoIcmTTpE139bvYii4cNKnvE5NjXSsgoPAhHhzl1gNxgYC6cCLo6ZRTTpER5GKiF2mCpWyc5CtfdbvS0vAmspjmNazJjfHhHs4zjACR8j5yAmpGi6rcXgSokyYRKGb5zQIZsdgYSMHhHhzlxAy9fMYvfIcWShB1ywIqbytwejSmiAdpb7wyJchQW949AaE1.L0DutwySyc4XbR6fpo1ZOKWEEQDQN6IiikIqutfA4sqbOo2enibX15A2JIGY2fVOLvo5k134jeL8oa3fl6.8M271Tu2VidciKqwkC.kVQom50RQDQjyixJ2rYqGbqbW20cwg13Aaw2u98sAn06ycszwLoYdeK4zJDwYyVN3TI3Pysyn9wMdmfM.xvyV85BUDQD4BGOgjira1Ovumsx6sqoNdWqcLxVyYsVQn0NXtol30lZvqcpIJ24F7ZmZPYN0nAmaP4N2n26RcutKMwzZpOuolX42v5SCqeMr923whHhHM2udugG.u1F7dqMZn9xpstgFNsZavPJ0MtllXZM2m2ZCV20utr0n5CMX5zDk23sySxYiVN3zoECZbYMWkr9okFMcnhFNtwACZX.EvXPgFGNndJbfHhH0qoZ99FOzvC71vCV2TADZ33FOOs1wAas51oR8+d3Fsb..vA0mDQAQ0z14hNjX8UpFe.2lqiWzb8Ty52wZpAell5KFmZTYN0fOmoF85lqkCDQDQpWq0xAM2wqZ76abYzByeK0AEatxoEJ+LRqENn4ZUf5KukZ0.aMZ5MUhnl6btzTSu9C723PCMWPg5W2szkqYyEjQDQje85TskCZpC32TgDZpVankNdWyET3TokEZ771bySKFn3b0kxXiq.MLLQykHqwsPPCC.z3fA025.0qwuGNwA7++2dmAK233v.QwN6++mbVOWVVCRa.PPJJGmIuWUtjDEkLjufVMHoUmCrhs....Q4oFayDJnkSPONSrP12QUaG2o.kSINv+F3paAcbdP+QVKUflnOx4.UffePQ9vdVffF2....lM24.ydNIejPfGR6VPez6UlvjpX73BGNsyAYBCpdnyTg4G6.ZaQBALo8+w9r.DFPh...zgNkUHS.P19lE6ZP0XOvr37kQw4QcSXGwAYtAj0mHQBY6G8ih28fHgAlDO5TqLx4.DG...PF63bPl3.UDf5Zvr7emPTvxBGVQbfJJHyR9r9kUJAsDAYtG3K2f45iYO6XvXajyAZehdF...3mKYV62w4.Ujvr9Uc+phin3UaqS+B4t+uUP2NN2L0QYyFgAdQCi6wXVIntHDsPMgn....lQlk99D3lk6bvCo8Yylgp7iQwjIm6XbxEAI0IgHGDp9gVEEn6qLDCnkZPcKnpjBHR....knDuYtFT4LPjvfYybgYehhSSN+kEL7JbNPOVELDMaETQAQiy.y9iy.eX+ojC9UDQK3XbN...fNnu.qeecMKHavGFILnRjvrRGLqeGgSNUFUGChJkfe+NJv7jMPDeXOOyFxJwPlyA....JYNGXVbYExbDHafJ10sfL2Cxb33x7J9uUnRrf2o.cajXfQa9RXDMdBhJqf1eyvAA...dlpxJ32eV4EdX89CZZ1.UrJtph+sYUwAYkEHKfhJufNKDL64G3pxI3mwB9opnu7AZexJk.hC...Po5MxiRZWs9E3KyvrxKjIxHqrCYNJnwdzwkzQbPjy.yDInAS10O1pKvQ9eP8BD72OsLBi6Ukv.K33n3C..fetDkXspDCQkRPSbq+MKmMtCz7cQI0iDCTE6y5ySbxAjXU4E7NB7KWadmDzxLL5uYO6zfeJJNqLB9+3kxVDj....xnxsfw4mslEDMNDxDSTsFITkX+xkSXvUVgD6HFXP0LTXzlJDvOUEM4XuiA5zTzKTv2eyPb....qSlk954pRnOSXPVIFL64bpUkSP6Wz0Ok6XcNvrOmjtpVHQa8Vp7K6yCBwJGCFhGzYpP1zXzChE...XvLq7iRbqSgwYBExVvj59wrmimsECnbGSkQ+wQBGL64wXfuzB54MK1Y.+JenNUFmM6DziQb....Cpdic+9QkUvrO+RtqTtgn1m4lPULtMcEGTUBgp9Mq7BlEKDvKXXr.GUU9.+26C28wr707.sM....OQIfiD.nGO6SzBkTlf.MdxJmPWQAs52tNGnNCD0VjPA+XIvSzzazOtBTgCYquAQeu+mEKLP2G...vSjnfw9QGm8F9pyBp.fYyzA850XpRDyVNIbGKex92b2GT5a1qnCBwgPfOb6axwYkQnaYEl0N...+7HKOUUYExr7OSTfY4kTHSnQ120QJkfmq9W1bl6AQWaG7hBzxC3m0BOjyqeL4Zy1p8C...n6anOy8.eehJ6vrAw3LgBYwblqAsEQbmCHQypGThUnKkx9OeXOKDHRnfErUAQA...jwrDwYNGnsE0uc+D881IlWhqt7IW0mcDH7v97hjTlq.c12RZiwb....cH5swG6GkTNJo8LwAi16LfFsf6kFacdVlxNIGqrjOyR+n2juJoeU6Q2yJmBhDLL6YB..fetz4EYqrwui3.83tsGcOih6K4nvtIEqd66SIPP6yr6i1Vm3qpM...9YRThzpjscRd2QjfdtcEFL6bS4TqPhlUmf0WNhnRL3KgP10lM9BzRcjUZgn8A...5vrDwYhEhJGQVB+JACYe2Uw41bWSkwnYuPk.gtiGAMwuJLIRrfI8Q2G...nhYImiR1Gctr9sivfK4LvLtRRxUR.mY6e01rAR3rsY8OKNA...pniffr1mIbXlngN2iNw4Rb0jj6HPXr+JiMgnsY62YLFnfXA...FzIg5LQAY6Oy8fnqaW2C11Qg6VbfdbWABYWWWABciG...fNzYz+upvfNmqqXf2JwAY2iYIjWQHvpmuaLA...rJcRBWk7ekyOqzEqDSKwcINHp8YNJrhiC6zuJP3....CVIw5NuY+Ny7gtGOq8VbxjhWwAA+w6bMchkNmC...Hhpjsq5lP1w6bMchkk4tEGjctcDIT88v3J...fuJtRR6SIJny4ZycjD8jI06TlfYOCHT...fSSm0lmYseRmAN5Zcv+dxa1+ypIq6lzWevIoO...eUzMY7tS2vUbK33bmIXWst+6NNAnjB...7Uyor9e0wQvsHZ3tSjtqk+mbgKBwB...bZ1w4fU6ytkt3x7pRbd0j8qFmHH...fWEqlj9pNAb6kX3UmD8jusOB....3cmSlr+kMtC9pRv9JcB.QD...bZtRh5S5zvsv6Phy63+2A...fuRtZB8Wtf.OuiIVeGiI...f6juTw.JeWRD+cINA...lwakPfH9aKo6eaOO...78g29j9.....................................7FvucKW0SJv5dy6.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-1",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 39.0, 516.0, 406.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2013-07-13 at 20.15.00.png"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [  ]
	}

}
