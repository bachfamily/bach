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
		"rect" : [ 486.0, 44.0, 617.0, 539.0 ],
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
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 57.0, 177.0, 210.0, 21.0 ],
					"presentation_rect" : [ 52.0, 177.0, 0.0, 0.0 ],
					"text" : "Save the resulting file in .txt format",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-1",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 57.0, 83.0, 195.0, 69.0 ],
					"presentation_rect" : [ 6.0, 227.0, 0.0, 0.0 ],
					"text" : "Connect the score editor to the \"export-bach\" box, and validate this latter (select it and press V)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-25",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 30.0, 262.0, 38.0, 19.0 ],
					"text" : "read"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-23",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 26.5, 420.0, 565.0, 21.0 ],
					"text" : "Open measured scores with bach.score and proportionally notated ones with bach.roll.",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-22",
					"loop" : [ "(", 1, 0, 1, ")", "(", 1, 0, 1, ")" ],
					"maxclass" : "bach.score",
					"numinlets" : 7,
					"numoutlets" : 9,
					"numvoices" : 1,
					"out" : "nnnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 30.0, 299.0, 442.0, 110.0 ],
					"pitcheditrange" : "null",
					"showdurations" : 1,
					"spacingwidth" : 10.0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7100,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : [ 0.0, 26.0 ],
					"whole_score_data_0000000000" : [ "score", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 3, "(", "name", "slot longlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 5, "(", "name", "slot long", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "singleslotfortiednotes", 1, ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", "(", "(", "(", 3, 4, ")", "(", "(", "1/4", 60, ")", ")", ")", "(", "leveltype", 1, ")", "(", "(", "leveltype", 9, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, 100, 0, "(", "breakpoints", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 44690, 1069632947, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1065335984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 53508, 1070280009, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1064471976, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 21641, 1070605927, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1063510016, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 16516, 1070831916, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1066131936, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 33200, 1071056982, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082252304, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 45653, 1071394579, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083401779, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 35742, 1071695458, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083884607, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1063550977, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", 0, ")", 0, ")", ")", "(", "(", "leveltype", 9, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085379584, 100, 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, 100, 0, "(", "breakpoints", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1083389951, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086351360, 100, 0, "(", "breakpoints", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, -1064062976, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086466560, 100, 0, 0, ")", 0, ")", ")", "(", "(", "leveltype", 9, ")", "(", "1/4", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086070784, 100, 0, 0, ")", 0, ")", ")", 0, ")", 0, ")" ],
					"whole_score_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 74.0, 259.0, 323.0, 25.0 ],
					"text" : "Just open the saved file via the \"read\" message"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 16357, "", "IBkSG0fBZn....PCIgDQRA..A7C....1HX....PmPRdI....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6clGWSbs1G+2jD1TQPQDvqJfnnfRaA2A0pfsdQ6pnk6Uz5ZUa05UEsq1V2n1Vkq81pVqJZ0pTWJz95ZspXUTTbi5FnnBtxhHJpfry48ORxjYRlDBjgrPNe8SLybly7LOyYl7vyY64vPHDBnPgBEqLjXpU.JTnPwT.03GEJTrJgZ7iBEJVkPM9QgBEqRnF+nPghUITieTnPwpDpwOJTnXUB03GEJTrJgZ7iBEJVkPM9QgBEqRnF+nPghUITieTnPwpDpwOJTnXUhrFBgtwMtQricrCDd3gCO8zSz291W3hKtzPbozal1zlFt0stkVO928ceG5PG5.uzxKu7v2+8eOhIlX..vO7C+.71auw+7e9OaP0UJTnzvina7aaaaaXUqZU3O9i+.2+92GyZVyBUTQEX3Ce3h8kpNwJW4Jwa+1uM18t2Md3CeHui89u+6im7jmnw4Lm4LGrksrEVieN3fCvVas0nnuTnPoAFhHiWd4E4q+5ulWZSaZSSruL0KhM1XIsrksrNcN5pHZUqZUFpJQgBESDhda94hKtfUrhUfSe5Syl168dumXeYLKXYKaYlZUfBEJ0SDcie+vO7CnrxJCCbfCD+3O9i..ve+8mWddzidDF23FGBHf.vG+weLuisicrCz8t2cz291WbjibD1zu28tGF0nFEN6YOKBJnfPd4kG..1912NBJnfP3gGNtwMtQcVeuxUtBBJnfX2+Lm4L3EewWDu1q8ZXCaXC7x6bm6bw29seK..F5PGJxJqrv+3e7OXOdVYkEF7fGLBHf.vm8YeFuycsqcs3Lm4LXTiZT3C+vOrNqmTnPQjogvcx6d26R70WeI.fDP.Av6XO5QOhDRHgPN24NGgPHjt0stQl8rmMgPHjksrkQF9vGNgPHjTSMURyZVyHIlXhDBgPVzhVDA.j+5u9Kx5V25HDBgr90udx7m+7IDBgjRJoPb2c2IO7gOTq5UrwFKgggg3niNx9wAGbfDXfARHDBI+7ymXiM1PN5QOJgPHjKcoKwqZuu4a9l7pRO2ic6aeaRu6cuI24N2gPHDRjQFIYfCbfDBgPxLyLI.f74e9mS9q+5uHaaaaqNUdRgBEwmFDieJY8qe8D2byMdF.iLxHIewW7Er6urksLx28ceGgPHj10t1QxKu7XO1G+weLwe+8Wkxpls5N0oNQ5Se5CuO28t2Uq5iPs424O+4YM9su8sOhDIR3cbtWyQNxQpUieidzilL8oOc18O4IOIwN6rijQFYvl2CdvCpUciBEJFWD8d68ZW6ZnScpS..X7ie7nMsoMXXCaX3V25VvSO8DG4HGAu3K9hr4O5nilc66bm6.2byM18m3DmHVxRVhNuVG9vGlWUOA.XXX3sOQGqQSO2y8b3bm6b..3wO9w5wcnvb4KeYdCAld26dixKubTRIkTukIEJTZ3Pzayu4N24hBJn.18GxPFBui2l1zF7y+7Oyt+8t28ve9m+I..ZcqaMhO93YO1SdxSPW5RWz50poMso75zg0u90iBKrPPj6QK6G8gEu3Eilzjl.BgnywCn1vau8FokVZ7RyN6rCMoIMoNKKJTnzvina76Mey2DidziFW3BW...Ke4KGAFXfvSO8D..KcoKEW3BW.iZTiB6ZW6BQDQDncsqc..XricrXVyZVH2byE..KXAK.+2+6+UqWqoO8oiUu5UiUrhUfu4a9F76+9uqyAS80u90QM0TCuzxM2bwZW6ZwMu4MQvAGLZQKZAV4JWI..RHgD.fbip..UWc07FOfN4jS3AO3A3Tm5TXdyad33G+33.G3...XyadyX.CX.vO+7iM+UWc05QIHEJTLJH10iN2bykru8sOxbm6bIAETPjINwIpQdRLwDIMqYMi3jSNQt3EuHui80e8WSr2d6IN6ryjcsqcwltiN5HA.joN0oxK+qXEqfHUpTxjlzjzodMxQNRRfAFnV+ricrC17NjgLDx.Fv.Homd5jO+y+bRgEVHgPHr4UIewW7Ejm+4edRlYlIgPHjyctyQZaaaKggggL9wOd17su8sOB.HLLL0VwGEJTLRvPHzEsbJTnX8AMvFPgBEqRnF+nPghUITieTnPwpDQab9Ey5VmFownkcXTOipmd8Lul77KvAEJ+FlrI7SWn7qkCHJ4moVtmzi7JX9YzgbLz7at79jd99AfvOSLmddKX9qGOSpuxdXC6czxYp+HZF+XGXwDB6OO41SJLb1gcS0JXIb1fQf7x4Kd4UizE3kcsmeRcL+ZpKroSzR5hgtSDHcs7CO06Bq5R949iZh.4EDARWs7xlNQfzU9Zh5oSzR50k7yHPYrhcLduOoi7WKOC48diQ54Ma50omgxSQedlv0PqP1CLz2OLDDOiefA.DPXX37CE0MDplWKF5ONpKurWWyu1LLqMcogT2EwenZIaXlM85ngY0TQ4GqA78o59enmnQd47kEggYs8LogxvbkUVIrwFafgfH54G.AL3UCNX8H2Ft8aMbK1HP85ZJBJpY88pHpblh6S85Z2.oXlp6WMttFAEQrtDYjQx.PtwO.XPF.EYO+jeS1McLkznPgBk5C8su8.e7mLY..TVYkwld80.n30auLLZDPAL17C+vOXRu9TZbSJojB17l2roVMrpQ9bxffRJoDTVYkgJqrRVu.qqHhd9QgBEJM7PH.EWbwZjdc0CPwu2dolAoPgRC.Dnp2BzV3mqtX.TTayOhHzQFTnPgh1fnnm2UeEXjK5qAPQs2dar402Mu4MwidziPfAFHaZG8nGEMsoMEcu6c2DpYTnX8BA.EVXg5LO5iAPQb5swH+eMRr+MpQMJjTRIwyvm2d6MZSaZCRN4jYWblnPghQBBXCPwkTRInzRKEkVZon7xKGUTQEnxJqDUUUUnlZpQuhclM.s4mkOcoKcA6ZW6hMb7C.bxSdR7hu3KhN1wNhYNyYBO7vCLkoLESnVRgBECAQyyOFvznnRuImbxnUspU7L7A.DSLwfAO3AyteqZUqv4O+4M1pmIAFECioFS+ANJVlPHZNKPpuHdF+XZb382jlzjP3gGN7zSOQG6XGQlYlI.jGB7egW3EXymCN3.d1ydloRMMYjQFYXpUAiNETPAHmbxwp74s4Fb6wWCEQt2dMMrksrEbsqcM1WNezidD9lu4a3sxuUPAEfu+6+dAO+EtvExtclYlIF6XGK9zO8SAf7EgnxKubAOuFCF60EojRJX5Se57Rye+8GIjPBX3Ce3lHsx3RTQEE10t1EJt3hQu5UuvDm3DM0pj0MhnQFwaoqjQo4OiqAgwMtwgMtwMB.vtjX1hVzB7Ue0Wwy3mqt5JOibZiVzhVf1111xteEUTA..BHf.vctycP25V2.f7oWiSN4jnceXtwzm9zYWHmBN3fwRW5RQ7wGOV4JWIhHhHvhW7hY+CDMVIrvBCIkTRr6WYkUBIRng.SSEDE+SNFtcFQdFdX7a2OkF9jHQBhJpnzZ9xKu7vhVzhD7XJ+QNf7kvxUrhUv5wixtLe9ye93K9hu.gGd3.Pt2kbWY1ZrP7wGOlyblC6Jn2xV1xXWakCN3fge94Gl9zmNl27lGRO8zwV1xVLkpaCJEUTQPpTo.P9xp5DlvDfc1YmIVqrtQ437SLPzV.i99srU..DVOBB92YeECQpWDYjQh8u+8ie5m9I7FuwavlNCCidul8pN95qu3fG7f3zm9zH4jSFe629s..nyctyHgDR.6ZW6BctyctQUU+xN6rwblybPhIlH.jOTeV1xVF7vCOzHuIkTRHhHh.EUTQHv.CDIjPBvau81XqxMHDRHgva+RJoDvvv.arwFTVYkgxJqL3pqthie7iahzPqW5ce5NhdtSB..Or.F3pqthV1xVhVzhV.GczQzrl0L3fCN.6ryNHSlL1+vk1PzipKFa1111lnKSkcxQ6ae6QDQDAa5W8pWE.fspuMFP81szau8FKaYKSmF1CMzPQ5omNFwHFARIkTXaGvgNzg1PqtM3rzktTsdrKdwKhbxIGLjgLDinFQgKDQrk0D434GZrMIOrpH5niFKaYKSuxqGd3AN9wONlzjlDhKt3vvF1v3UEYKUBtVhGkMsoMsVyCkFRHhlgFQeFdXNPPAEDb0UWQJojhoVULaonhJBAETP7RSeM7wk0st0wddyYNyASZRSRTzOJTz.h45PcwLZXebtycNSsJXVS1YmMBKrvP1YmMBMzPwgNzgLH4EczQC+7yODQDQf3hKNjQFYfe8W+UAauPyc316tpyku7kQt4lKRJojPngFpQTqnnDwZ.NCz.rFdXt38GEgIszRCgFZnnnhJBCe3CGIjPBhhbG5PGJRO8zQDQDAu1AzRyHQLwDiVO1ie7iQokVJRM0Ts3tuZLfXONhoQ0EqHRJojPXgEF..l3DmHVm.K2nFBd6s23bm6bHpnhBwGe7HrvBCqXEq.SaZSSTuNMjnKufSIkTPVYkEF8nGsQTinvEwzyOQct8RM9Y9RhIlHqguniNZQ2vGW1xV1BV7hWL.jOXoUeVhPgR8EhH1peh7Z3gnIMJhHwEWbrCYmEu3EWu5Xi5Je5m9oHgDR.1au8XkqbkHrvBicfSaohxd1NojRxh+dwhEQLvFHtU6U8EiSJlbhM1Xwblyb..L5UAc3Ce3rUCNojRBcu6cGadya1rt8xZdyatVOVIkTBxLyLY8fF.vO+7Cd6s2Z7cikA8s4FluKZ4TaelUvsG32xV1BF0nFkQWG7yO+v4N24PDQDAaUuMmaGPcMHmWvBV.bzQGACCCdxSdBxM2bQFYjAxHiLvd26d0H+JMBJjARJ0ODyo2l3NTWnKgGlMvcLNt8sucLxQNRSn1.jPBIf4Mu4gXhIFL8oOcjc1YaTp9ccEcEfZCHf.znCOxHiLP1YmsFey8iPCeFO7vCddIpbatQNbJBi4237Cxq0aC438qfBJ.t5pqMXxuwDe1m8YraapM7ojEu3EC+82eDUTQgXiMVjQFYfsrks.mc1YSspUuwO+7C94meBN09TZ7SHCj4latZscCc1Ymg+96O7xKuf+96OOiiVxkUhAhTnH..hcHspAzyuLyLSLkoLEL3AO3F8gRICkDSLQjTRIAO7vCjSN4XpUGdLpQMJ3me9gnhJJr28tWDTPAgMu4Ma1LkwhM1X05wt4MuId3CeHxO+70qowmRu5DpMNUVkYgLPVTQEgTRIEAmgR1au8ZscFsDGT40EDayKhVTcY8+5NA.PvOu+nKcpihgH4w.G3.wQNxQf6t6Nsm1pEBJnfPZoklYcaqA.11ADP9zjybHPg1xV1RsdLkKNN1Zqs5boSzPonhJBomd53l27lH8zSmmwwhJpHsdd1au8ZzoKMl5.ld1qtioOywCv.T5ikYFEUWXXD2QfHGt90uNN+4OO7wGePSZRSnSuHcPbwEGRKszfe94mYsgO.9sC3jlzjPFYjgIuc.0kQMi0fb1YmcFAGbvZ0a3zRKMAqNM2NfQHzVmuXIYXjv9eFNhavLsAp89N1wNFr0VaQBIj.bvAGvZVyZnF+zBJaqOkCxXycDpc.2yd1ioVsLqIv.CTqcLhRiepWcZteDBtc.C2uM+5YZyv17SdvCUrjFet90uNF4HGId9m+4QlYlIN8oOcCyExBmXhIFjat4hPCMTKp.s5nF0nfWd4EF8nGM16d2K5PG5.RHgDn87Y8.cYvRac9hRuF0VyI4gGdn0pSar6.Fyx.a..CXXHF7Xvg6.HUIW6ZWCsnEs.gEVXnfBJ.25V2Rv7oKpnhJPEUTAHDBbzQGMHcLojRB1ZqsvImbRi07CSEUUUU3XG6X.PdH1utV9XNP6ZW6vSdxSP1YmMBJnfPW6ZWgat4loVsXQYfMXCaXClZUQzPowrJpnB1EB7m8rmw6akFFEpCXjISFbvAGPSZRSfCN3.ZZSaJr2d6QSaZSgLYhn4kF.DMs6xmOMzsWHPXnCAQg5I20rl0fHiLR3jSNgEsnEgl27lWm5w2su8siKbgKffCNXr28tW1dqq9FQlSJojPyZVyPm6bmwwN1wPlYlIBO7vQ3gGN5ZW6Z8RlFJqd0qF0TSMn+8u+X9ye9lDcPrX0qd0XG6XG3xW9x3EdgW.SXBSvTqR.PUHsh652r0.EVXgHu7xC2912F4latHu7xC25V2B4kWdn3hKFO8oOEO8oOUiyyVasEt6t6vSO8j22su8sGt3hK0Y83C+n4Jpd9IJ81ahIlHNdJo.aatKXb+62BctS9HF5FKe8W+0XxSdxH4jSFiYLiAKcoKESdxSVuN26e+6CO8zSzgNzAb4KeYboKcIDRHg.u81a72+8eWu0orxJKrgMrAjd5oy1ik.xaOlINwIZT6rgryNazgNzA..jd5oaF1NM0chKt3XCLphYn2xPfFUWzjhJpHdUelauTqqdlFPyoFXs0AL8rWcGScFiC..UVrMl1d6snhJBIlXhvc2cGC3EGDR8uungHNshO93C15V2Jl+7mOJu7x0aCe.xW0sl7jmLqK328t2EUUUUvSO8zf0KmbxIjPBIfhJpHrxUtR1dZUYjLQoQvFx1th6fJeZSaZMJL7AHOja4me9gQLhQfDSLQ13CXik6uFK3ryNq2c.i5Cx655TCjHlQ0.Xfd9EarwB+82eDd3gi+ucsGj5eeQL1+8HQ+Ctu392+90KYJT6J7m+4ehkrjkfJpnB7Fuwaf4N24Vmk6t28twZVyZPQEUDBIjPPzQGMZUqZU8RGA.xImbve8W+kFyW1SbhSfcsqcgibjivllu95KdkW4U3sXHIVvc0Fam6bm0qpSXNSwEWL9jO4SvYO6YA.vW9keI65yrwF5BXj3xMu4MQt4lK624jSNraKDcumAho99iC..UUhsFrmeFjwuLxHCryctS7Vu0agKbozwo96Kg29eOBzkN0w58zPQnkNvLyLSTZokB6ryN3qu9Vm6vhG+3GCIRj.6s2dTPAEf6d26BGczQCxKhxJqL7vG9Pzl1zFAOdUUUExKu7v8u+8QYkUFa5t4lavc2cGMsoMsdes4B2+Xg4xrjngfrxJKjWd4A.4qpdlhNY5oO8orKckTZXo7xKGkUVYnzRKk86NzQuvTl93.C.p5YFtwOCpZuJMdDe7wilzT4FjLzd6k65g5cu6cQO6YOQokVJ..V3BWH9fO3CpSx6zm9zH7vCGd6s23Tm5T3t28tHxHiDojRJFzZuZVYkERLwDYCWT5h8t28h3hKNjXhIh7yOeje94ydLCsIWCIjPXuWZLa7CP9hK+zm9zwsu8sQ+5W+L5KX5z17yzRO5k7EbKwphuFbvL0O+7CSbhSDG3v+knNFmu3EuHdoW5kPd4kGZUqZEBIjPpWCrYu7xKTd4kCu81ajWd4gSbhSfKe4KiHiLRwSYqEF5PGJRHgDPN4jiFC93IMoIUqMLr1P4b.U4LBnwNSaZSCG5PGBN6ryH93iGAETPZcP6RoQHD4NKHVA2.QIRN6t6ti2dhSEc64L7g5hR9pu5qPlYlI7vCOv2+8eOhIlXz5z1QW3pqthjSNYzqd0KroMsIbxSdRrpUsJr0stUQQOqK3gGdnwPzIt3hCd3gGXkqbk0Y4ozymnhJJQQ+rDP4BldvAGLRKszf+96ufMXNkFmHlyiBQKvFrscc.P.PP94C5bm7odacNrvBCEUTQ3bm6bfggAO2y8brMh+UtxUPW5RWpWxsrxJCDBARjHA1Ymc0KYvkRKsTTPAEf1291WukQUUUEt90uNajWwImbBcricDN4jS504mVZogG8nGg.CLPzhVzh5sdXoxUtxUXK65XG6nA8rPeP4fb1c2cuA85PQ9jRnzRKEkTRInrxJCkTRIn8d1V7NSar.L.jRsy7IvFHOVNa31Q+zO8SwhVzhfDIRPTQEEF23FGt28tG1912NxImbPAET.71auQjQFIF3.GndIyqcsqgku7kibxIGL9wOd75u9qav5Yt4lKRN4jwa8VukAKqzRKMr5UuZb8qecb1ydVDd3gWqskXwEWLd8W+0QyZVyL4AC.SI6XG6fsrqScpS5UavVewZcPN2Pg5Cd5ae6ayN3oqnhJzH+s2y1ZlFXCDoktxPCMT75u9qi9129hktzkBYxjg0t10h8t28xZIOyLyDqZUqB8su8EgGd30pLe7ieLxO+7QO5QOvTlxTfqt5pA2icYkUVryiVCkPCMTDczQytdaru8sOru8sO1iKjWzwEWb..HxHizpNHODZnghW8UeUDQDQf8su8gG+3G2fsfoau81irxJKq5x65Jbiagp+M2QAg5n97I1O+7CwrDwMXcHxKZ4pL+ke94WumWlEWbwXXCaXvM2bCojRJXaaaaX3Ce3HxHiDd4kW33G+3XNyYNX0qd05kwuyblyf.CLP7du26g4N24hO4S9DyxgqPzQGM6.iN93iWm4U4wMEqKGlazXYAS2REcEwp0EBYfSWAlgXVxhYcDPL5YAwMd9A.v.bfCb.bwKdw5kwuTRIE3hKtfhKtXjRJofe629M3qu9hYO6YizSOcb3CeXzu90O7Nuy6fe8W+UAGTzbonhJBG8nGESdxSFQEUTvEWbAW7hWzfC29JGPl010u9f5F+D5ZnL3JXu812fnCVhrhUrBrfEr.7m+4ehvBKLL6YOaQcfkqbPNaMVdq9fPl625BWbwE3kWdAO7vC3kWdg1zl1.O8zS3kWdIX9ezidjNKeUVGHwv3mn0gGIrmCCBH346hWnS9zg5sbBIjPPVYkEbvAGfGd3Ad7ieLdvCd.7wGePwEWLpnhJPKaYKQwEWLxLyLQPAEjNkWlYlIryN6fSN4DxHiLfLYxP6ae6M3nERsMHmMTpnhJvYNyY.flCd47yOebiabC3latAe7QbmG0MF3t28t31291.P9HQP47d1Pow9fbt7xKGO6YOi22JGjw5B6s2dXmc1AGbvAXu81y6awjxpnTLw28sA.fjJr2LpCOXTV0WCyl7wO9wwINwIvV1xVvJVwJPgEVHhIlXvm8YeFdvCd.NwINAd629swoN0ovBVvBp0.e4t28tYWKVCKrvfKt3B93O9iM3PldcYPNWeQYXdeTiZT7BTBgEVX3F23FH93imV0NsPhIlHhHhHPd4kGa0fMzXOWigA4rxpiJzpMmtvbXY3r68LHy30sWQh9129hCcnCg8t28hgNzghoN0oh0rl0fnhJJ14L7gO7gwq7JuRsJKk4ofBJ...0TSM5bcZPeoCcnCMnF9.jW82DSLQrxUtRdF+RJojf81aO0vmNX3Ce3rsCXRIkD72e+wu9q+pUwfAWWKml5BKgvbu4651qHZWd7ie7Xqacq3BW3BHpnhBe3G9g.P9b8cgKbgfPHrg7H8gcricf24cdG.HOxPaIPngFJ7yO+PFYjA65Vhxd40ZZfMWewO+7i0.XhIlHBIjPLaVnjLTzUzRQWvsiErLWfiHhlUFQqM+988IOJlzUeaO5jO0+BR0i.wkTRI3l27lryu2RKsTDTPAIZAF.yct6cuKxLyLgqt5JBHf.v4O+4QgEVHd9m+4azEAWZHIqrxhsw4ae6aO5XGq6qvfF6A4bIkTBunprxHsrPiANtvMZJq7aksCmkLE83GgwM0w.v.XSkNX9zleLLxGhyFpKo0VDZ9nG8nPhDIne8qeF3UxxgvCObTPAEfoN0oh25sdKXqs1h+6+8+ZpUKKNNzgND9xu7Kwsu8sgGd3A9jO4SPyZVyz6yugXPNe8qec1A3qxuyKu7PgEVnVOGwNBIaovb9.EMyj41fbV9hVtgqU0V6X4latY00P+u+6+9H1Xikc3uLhQLBqp6ewhPCMTLhQLBDUTQgTSMULyYNy5zBld8YPNWeizwpuF7xsppM1Wbx0EDwvCKEX1uzUdgKbA7se62hINwIhPBIDz0t1UdAJTqAl1zlFhM1XY6YaZ68U+Iv.CDomd5XXCaXXu6cu7hej02V.xPLvosNXvZ1.mtPdzbVbjkHunkKVRSNYjQFnO8oOnzRKEae6amcrsUSM0HtWHybT1XzUVYk.P9LZfhgwd1ydvblybPrwFKuz+ke4Wz54L24NW1ktflzjlvZrSWF3b1Ym4YTye+8Gd4kWve+82nurORgOh6PcggHpd+8G+wev1QGkTRI3d26dlUKkgTrrYYKaYZX7SW8Db4kWNxM2bQ5omNuzoF3LdXVtt8xv.PHha0d6d26N61CcnCEAETP3JW4JM3gtHJVOndUce1ydlVyq+96ObyM2vfG7fMoKb2VyHhM4mXunkKdJF.v.Fv.vLm4LQt4lKdu268vgNzgPhIlH9lu4aDwqhkAhUzqkR8m0st0YwOCOr3Q7ZxOy617C.X4Ke43fG7f3AO3APlLYH5nil54GEJVkPDwg3bCQa90..M3QRwXwvF1vz5wdzidDd1ydF9ke4Wp04TNEwGBLamda.PjayOJTL1vcNTqNYjQFHu7xCCZPCxHpQTTGyup8BFpsOJV7nqgQjyN6LxJqrnC0HSEDN81qHXqQTV81.f7Y3g7MDMQRgBEJMTH5yvCpoOJVxjVZoo0ikYlYh6cu6gzRKMDXfAZD0JJJgHhM5m3GF6oPwBFcMHmKojRP4kWNRHgDv4N24LhZEEkvt5sIBlaD4fYpH1ULTnXBPWF0ZLDIms3wrLvFv.PnV9nPgRCHlmqauTCeTnPoADBjOLmM6FmeximehlznPwj.cPNaliY4zaSwL7f5AHEKYnCxYyaLOW81jOVWDKwQghIA5fb1LGyxPZEXZHhqATnPgBKlkd9Ie.NSvXFyXzZVzqHxfde2QpaYWmWKMkR8WtZ4LqWsUQseFBlC8Ow54UlTeDoVxtdJDcjMh9jo5BDc+t5x+e+u5t.gn7XQiSnNc5ZjYse1F76pBH.cIS8sNihYncSbmgGfAe4R9N.noRR38CF0dYfn9KGDtIq07qobU6kVAdIl+Z..G4Z.5k7zD3kRhFmoV0KPDPSIpsOegyWu3ULPTKY0zCgzKNBm+kUO0K0FCBpK2ZUuzXLLPTSjFxyJ0tCD5cShZ6yQLD0zKCDfk+..vGPlDQAQEM+CYZpq0ldoOkA016150yJN4kuJpmOqzldo02AzS8RfeCwEFsti3g3OCOT7xhpY7AQQXnQw9Lp5rZFkkXbW1KUr7LQfx1QTw9Dnph0JjMgvoCVXTbcgp3JHgaGvPTIKnTtDNWWFNWWcnWJuVJOeE2g7lgKDBAG+nGV09bJm5W+GH60h2KKbmZfDE2ILbNNQ4wIJUX17p7dh8NPodwvdGw9tMih6KVMi.dkIDvsW64nWDNGmidwFMKXTU9n5YEG8hS42IO4wUUfv4Z0q9FL+6e0JqqqOqj+ND+xZgdVwvd+q33bhPGruCw48GBa1UZHjgidANkgZ+cHAe1vPPZm9rr5EWBrmcG7hbHLbJiT9rQn2g39rgqAGF16.UOaD5cHMJC49aHEWWB+mU016P79MHm6eA9SDpTWgR2.QzVzxO1wtHpaV7kuuhrweek+Ou+PG++pmFRVm+0bg+qd7JpIZVzKnGdZSu37iqqjwkAopmg90+AvSmRN4jAiT6Pm6RWUWS0xe0TX8RvWVHpsO+LxWtD01Wg.DnDT3xPCvqgqk4UgCx3ttKK+5b7icL7rJpFczWeqU8RvmUpoWrRtVdVw+Rwcec7tIQs80gdoRFpcDAp8R1W+FnUN1bzWNqnb..ob7iiG7jGCu7oCpNC09cTsoWZbD85cH9kW056P5gdoZWAeBJndoNL.nU10bCdQKWzhpKLLPQ69o7eJ1mQ09LPw9LJC48JRU49LJyE+7Bk6qTRJxKmqDG4p94yUtJNl7D4kWnldw.kmqpqETWu3kWU5ke90MjdFWGt4lavWe8E95quvM2bComQlnK90MdkAfy4yuLTsxKt2AbtuTUFppLPyxP0JAYz7Yip6ed2oZ9rhSYMX3ec.m7Jjdw.fN4amweegKhV6lanS95K5jucFt4l6HsKbIzoN2Ys+NjFOq.+mUbeGnN7rRklBMuNZ6cHk6K3yJv+YE2x.AKCUk2NzwNhTO6Yfat0Z3am5D7sScBt05ViTO6Yf2czGtusyQufF5kP+lSimMZ7NDT674WdowuuE5cHsTFH36lB8NDzTO43qqbDvwm5KFT0dqolZPM0TCpt5pwy+7diJqrRTQEUfxJqLTVYkgRKsTTRIkfRdVI3oO8o3oO8onrxJSTTbycbsUMGG8HGFu7K+x..3nG4vn0sxIbuacESrlY5o8+COPJGKY1xlTNVxvy+gGnjGVfIVyLbT+GqZ7i2ZgN2AevoNwIYKaN0IOI5RG7A1VY0FWsQaYstdCYFiAY7ShDIPhDIfggARjHARkJk8iLYxX+XiM1.arwFXqs1hJpnBwR2MqwUWcE+1u8arUu6fG7f3Mey2zDqUlGPKazNzxFiGhVa9w0KvJqrRs5En0hwO.fKe4KCWbwE..TXgEht10tVKmg0CzxFsCsrotQ8sM+DMieJo5pqF0TSMnppph0.X4kWNqAvpppJw7xY1ypW8pA.vTm5TMwZh4GzxFsCsrotgYgwO.c6En0lwujUDYf6OMx+RgRCJlEF+ThPdAVc00mFt0xl3229Pu6V2fOsqclZUwjwG9UeE95O5izYdJrvBw2rl0fu9i+XijVYYw527lwD3DHU+vkrDZYkZTWL9IdSuMAPpTorcosxNGolZpog7RZVxPBIDbfSdR3q2dCaswFSs5XR36VvBX29124Nn8B7GBZaaaKJrzRgCN3fwT0LpbhTSE8s28tdctczauQYkUFZQKZA..9tEtPwT0La4b+8eKXMF6UO5gAI2FTie.Z1ivViF+7o8sGYmatXOG6X3e8O+mlZ0wjxCe3CweewKhN0wNp07Xmc1YD0HiK+5e9mXfCX.0dFEfWaXCCietyEaXoKUj0Jya5au6MV1O+yXNbha.G8XGCW5xWFcOnfp2xU7V5JqEDZHvzX3yQN1wvpW+5wV111fLYxPN4jCVx29s3bokF9fEsHHSlL7e97OG+yPBAItychD16dgLYxvHlwLvQRNY7GG3.3W90eE2912Fe028c3N24Nl76IC8ya8e9OXoqXE3XojBFwLlAjISF92yblPlLYn0st0PhDIPlLYHsyedD2O+yXaIlHhY4KGxjI+uEmat4h4rvExJOkaO94NWHSlL79e1mAYxjg24C+PS98Zs84eMyYh4uzkhYnPmYXXXS+89zOExjICQMqYg+u8rGDyxWN1X7wyVF9jm7D71QGMjISFV45VGjISFdZ4kCYxjgajUVXLyd1PlLYXjyXFXEqcsXqIj.hdAK.4latXryYNr5vrm+7gLYxv3Tj1zl27fLYxvD+fOvjW9nue..u8CcfCD8tW8Rm4u1nA2yOtHQhQyVqQipppJjwMuIVxG8QPpTo3y91uEaVQT+3V28tPpTonMt5p7iMiYf4+ceGdYEACyWdvCF..u1TlBJu7xg6t3Bt4suM5nN7JxR.+Zaaw7hNZ..7+15Vk+G8T7G+..6XB8+twMhsuxUB.fsmXhrG2Ku7Bd3hKPpTo3zm4LnUN4DV2F2HdwW3EfToRQUUWM94e4Wv7du2qVaWGSMq5y+bbhScJL7W+0YSSpTo3ql0rvgO1wfToRQ4UWMdqgOb7V.3CWzhfToRAgPPFW4JXxQDAjJUJNQ5oiYq3dUpTove+7CfgARkJE1ISFhd5SG..IN0oBu7xK3lSNAoRkhic7iCOZUqv513Fw.CLP1xusr8siO8ceWy9xOtvUWUu8OqOz3yZjQlgNjgfU+0eMFqhFy+IkUFd3CeH..9WiXD..nTEypkd77OOjHSF1xd2KOYP.vTlvDvTlvDv+vCOLdJuIlx3zNNu0vGtf4ozxJC1YqsrkO..qO1XwSJtXrz0tVihdZJXm+3OhMuqcgycoKA.fw+puZ8RNOqzRg81YGuxue5+9ewCd3Cw2t90KZ5qwfXVyZX+jqHLSwnF+LP9wMrA7nhJBcUQC3+VCZPXFKbgXoe+2ieeW6B..Yme93N24NX26ae3CG6XgL09qst1rlg4L+4iY84eN7yO+L52CMDr68sOb0LyDt07lqwwJ7QOB6+.G.8tycFSZNyAKboKEomQF7xSUUWMxK+7w.5W+vot5Uw29C+.l0m+4..XFyadXFScp3oV.SUxm7zmhJ4XjuppqF6+.G.E9vGpwHennhJhMua8W+U7ASdx3t2+9H6ryFCUQaE6VyaNdzidD.zLXdvkpqoFb+6ee7xCdv33W9x7J+l0m+4X1SaZ3IV.keb4Sm7jY+zJ8rps5hFzg5BEgonm9TrxssMD0PGJ7pMswTqNhNezhWL9p4MOSsZPoQDwrt0gOcRShWZW6ZWCcpScpdKSpmel.b1QGwf6cu0n5uMVvZbrbRogmBKrP1sOyYOK9yjS1fjG0yOSHw8a+Fb1QGQDJ53CJTnnIG9HGAUTYkZjdG6PGfOcnCBbF5GTielXhYcqCQL3Ait3kWlZUgBEqJnU60DyaLnAgDN3AM0pAEJVcPM9Yhoq93C5X6ZG1nhdFlBEJFGnF+LCHxgLDb27yGmI8zM0pBEJVMPM9YlPjCYHX+ojBJ9YOyTqJTnXU.03mYBcrcsCuPm6bi1g+BEJlaPM9YFwv5e+QwO6Y3uNyYL0pBEJM5gZ7yLinF1vvw+6+F4wY.cRgBEwGpwOyLb2EWPHuvKfsrm8XpUEJTZTC03mYHCrG8.1amcXOF3z2gBEJZGpwOyTF6q9p3uu5UwMyIGSspPgRiRnF+LSoYMoIXHAGLs2eoPoABpwOyX5g+9i15laXa6e+lZUwjSgEVHVzhVjnJyye9yi28ceWQUlTrbfFXCr.Hl0sN7FCZPnq93ioVULY7AevGfktzkpy.3Yckd0qdgKe4KiRJoDQSlTrbf54mE.uwfFD98CeXSsZzfxCe3CwCdvCz5w+lu4aD8q468dumnKSJVNPM9YAPW8wGzEu7pQcvOXFyXFn3hK1TqFTrhfZ7yBgHF7fwcyOej5EunnK6qbkqfAMnAg.BH.r8suc1zCHf.X+7W+0ewtM.PlYlIF23FGRO8zQO6YOwfG7fQ1YmMO499u+6i.BH.Dd3gi7yOe1zSJojvLlwLvhVzhvPG5Pw92+9wV1xVPe5SePBIjfN00MsoMgQNxQh9zm9fSe5Syl9pV0pPe5SeP.AD.lwLlgFm267NuCBHf.vrl0r3kdM0TC99u+6Q+6e+ge94mN89jRiLHTrXH66cOxhW6ZIO5IOQzjYt4lKYricrjbxIGBgPH8qe8irsssMBgPHW4JWg3t6tS9jO4SH25V2hz291Wx8t28HDBg7Mey2P..Yu6cuDBgPl0rlEwGe7gUtAFXfjsu8sSHDBYcqacj1291St0stEgPHjfCNXR.AD.Iqrxhr5UuZBgPH.fjc1YqScE.j7yOeBgPHae6am3t6tSdvCd.4Dm3DDoRkRd3CeH4gO7gDmbxIRhIlH64MfAL.RpolJgPHjd1ydRlvDl.gPHjMrgMPbvAGXyGCCC4O9i+ndTJRwRDpwOKL9iiebxJ15VEM48u9W+KhWd4EoO8oOrehN5nYO9ctycHMoIMgL5QOZMNWt+sy7yOehToRI28t2kr+8uehToR4k2.BH.xm7IeBgPHjO5i9HRXgElFxReL9oj6e+6SjHQBIszRiWdxN6rIN6ryjUspUQHDB4cdm2gLiYLC1iu5UuZRLwDCgPja7qIMoI7j+N24N0oNPowCF0EsbJFNCI3fwk1zlvgRMUDVu6sAKuie7iiILgIf4O+4K3waaaaKd8W+0wQO5Q0obZcqaMpt5pQM0TCuEZFkzoN0IbiabC8RmXXX3sOQfd30UWcEDBA0TSMro8hu3KhW5kdId46Dm3DHxHijc+oLkonW5.kF+PayOKPF6q8Z3jW7h3tbZGs5KsrksD6d26lc+TSMUDWbwwt+oO8owPFxPv.Fv.PHgDhVkS1YmMbzQGgc1YGbxIm.gP30FfUVYknC54hMCQdMRX+HD24N2AMoIMAN4jSHyLyDN3fCH1XiEyadyCx3rlt5t6tie629M18yO+7wN24N0K8fRianF+r.oUN6LFXO5gnL6OV6ZWKtxUtBhLxHwt10tvG+weLF5PGJ..t5UuJlwLlAF6XGKV7hWLN8oOMV7hWLuy+rm8r..XcqacnO8oOn0st0nm8rmvM2bC+3O9i..392+9nvBKjsiHprxJ44wF.PW5RWv8t28vEtvEzo9dhSbB..rxUtRLlwLF3iO9fbxIGTd4kCO8zSTXgEhpppJ1kOyu3K9BjYlYh27MeSryctSLxQNR3khEKJgFeeO8oOstT7QwRFSXUtoXfr5crCxukTRFrbN24NGoYMqYDO8zSxMtwMXSmgggz7l2bxCdvCH6bm6j..B.HibjijPHxairkrjkPjJUJIpnhRC4NjgLDBCCCwGe7gb6aea1zUJGtb8qech2d6M4m9oeRq54u+6+Noe8qej.CLPxZW6Z4cr92+9SZRSZBYUqZUjYNyYRZRSZBI93imPHDx92+9IN5nijl27ly1wGDh7NkIv.CjjbxIS14N2I69TrNfNCOrforJp.wtoMgHGxPPGaW6L5WeFFFQcFWPghwDZ0dsfwdasECI3foy8WJTpGPM9YgSO72e3UaZiQ2.3y8bOGZUqZEBO7vMpWWJTDKnU6sQBwrt0gg0+9iWnyc1TqJTnXQ.cb90HgHF7fQBG7fnKd6Mr2Vaq07Gy5VG..XT7eLpsM..C2s0U9X2mnaYvnJ+BkO1iwYadWSccL8Pu0o9vUt5HeptlD.FfWYXSFTrLgVs2FIzEu7Bc0Gez609CILRj2gEP03pqF0Fec7RCbRCpkO18ApA.DB+O0PDHMt4C5Q9UOen1xul5sxs048o54S86U17K+5PwxEpwuFQ7FCZP3AEUDN9e+20ZdYXXfDv.ILLfAJLBBCzfj5eTSdZJCALDoKirZwvkvFqztdqg9.839TKFeqrxJavddRogEZ0dajQTCcnXi6ZWnyd4EZkyNq07IQgWeuRvACdNvnzcFNyvL9S1LgQv7XnxfoVNdsICANg5jLzRlY.vkRW9z8SowOarwF8PxTLmfZ7qQFs0M2PeBH.rk8tW7eF0nzZ93N+Y8sKcQtAPN0iiW+fI+fJ+R4+oH6D17P3ug7yfqX3IS1bWKxT01ZHSBQk3q25Ege0W4ISg0w2b3CEe3G8N..nrxJi8ToF.srfVs2FgnLfGr+TRQq4QBiDHgQBT5di7F8mg8iDIRTjGFvHgALJ1VhhsYXj.IRXTz1gR.iD4UgVhhzYX2VgLXkohpZKQh.xjgiLYTHSIBHSUxfUlRTJSExPBG8RoLkvQlRTcckHQcYp3dQhD46ySlLxsipncEKojRPYkUFprxJoUA1BCpmeMRYru5qhUtssgt5iOnst4lFGWomeb6USMyj7+igy1DB.CiRWnX.gQQO7RX.XT5cHihdHUgWULJZUQEaS..CgvQlDE4WggEFh7qp7LxQlJ8rigs2kUISBXTrs77vUlD4pGOYJea9xj68BTSlDE26pjO.DL5SS8.zx.pmeMRwYGcDCrG8Pqg9dkdfUWgggiGhR33gnBOuzzqJtddwwCQEay5QnDIpISFAjoDAjIWu4TWlJ0SM8PTcu4jv4dQcODYTyCQ1NKA.O9wOFEWbwTO.s.g54WiXB4EdAbkryF+9gOLdiAMHdGStGLppxqgvx+wUiHesWCsoMsAfA3m17VPYUTAdTYkgO5ceWNdyAddHxPT51IWupHJxuBcSgGhDEdvoau4TJSUdyozCTUxTk2bJamS11+jmLUccYTHekxDPUn15QO5QZsbg5An4MTieMxIpgMLD6l1Dt5oNEBLv.wK+xuL.j2leJLWXvWipIpLFbfCdPzrl1TLtQOZUYfiAEhxpRqlAE9Ukt1qRq7pRC0jIWCk5p54BWkVtUOW2FeU0+GJWyORM0TQYkUFFkZcxD0.n4Kzp81HG6s0VLr92e.H+GpJWfhXq5JfA+Ab1NyryV64kggs5108NnfSmdTG6fBFcTkVM6zCIBHSUaKQhD1N7fnnCON3AOHb0UWA.PEUTAprxJQUUUEpolZXiqfTL+fZ7yJ.ky22QMpQgl0rlgku7kqWs42Z23Fw513Fw5+4elMsjSNYrp3hC6HwDE7bdb0Uiqle9XO6ae0pdoYOLqp89zr8D42FhL7LRIQ.iT7aOQ9xjqwW0koPsQIeiuxGfyxmkGG5PGBgEVXZ3wGEyenF+rxvO+7CW6ZWic3pvc9wx8y2sl0.WbxI7Nicrnfm9Tv.fCe3Cibu+8wzl3DgLoRwlhOdM77yIoRQmcyM7JgGd82aRA7PThZdHp8N8PyNnfQO8PT8N8PhfxTYUuk+wUWcE94meFiGcTDYnF+rhHszRCaZSaBu+6+97lZaBgc1XCtVN4fKc4KiA0id..fSjQFn3m8LD2O+y3QO4InJiTU5padH1v2iy.pl6vst0sFezG8QHszRynTVPQ7f1gGVIbiabCbzidTLkoLE3t6tijuPF5L+Sc7iGaKgDvumbxnqsoM..fHSFBtG8f0Sm7xKuFb8Vmvvwzsfc5gPiePXv83LfhuXju.I0111VDWbwgJpnBi3MOECEpmeVIzu90O7e9O+G3t6tC.tyvCgq54JiKN7uhHB7ZAGLtbd4AF.Hqppv9NxQj2wFW8pXm+wenQ0d0l7LZeT5cnN7liQO8PTac5Afpp8B.zhVzBDQDQf1YBVJAnT+gZ7yJg29sead6qzHg13okWN9+18twYuvEfKJVJHeyvBCkVSMXgqYMHgCcHLkwMN..TIgfcevCB.fRprRbaQXI0TLgaUlMroDmhA4rh4br5wA3W8UeUSzcHk5CzH4rUJa3W2IHfffe9thN2oNZpUGyBTOvKndPSP4X6quA2KLsYNd..T1SjAWc0UzxV1RzhVzB3niNhl0rlAGbvAXmc1AYxjAoRkZTuOnnePayOqTzkWeVqvqLgyfnV0L8P47QFZ30GEKOnF+rRggQBTLAuDg43QiXT1oGJ1lSzzhhENTieVoHgQdaWMlwLF9GfabwSyCvMr3IbNHZIc.MrXnwUQHCJBXYt1LVyn0cDOYTCg0tHEKTnF+rRQ4TaaFe37XmpVDEyaK0W2K.uvEOzR5J6..MWWOfZxS37B9oonJl75EYEanbzqvn11JyC2dcV9wDdgURYdzoLzR9nU60xGpwOqTTFXC5Y25DunZrp+mSZDHb5Z7klFDHB3IHu7STOcMRPNFpGfhgLTryXF8nwje+wIrmpTrXfZ7yJEtA0.O6jO7OHgiQHtUClvKCZX.q1Ba8Zq2S4WkZ0MpxUl08PNuP2K7sGSzx8k5xTMS+TO+r3gZ7yJEIbZ7dg7PhctSvNyFfVi5wDEoWayVBs26oLJlwDphfy7kopqq5wmuZKBQyduvJSCObZQTbaPM+YYCcPNakh7A8qp0vCsQpolJh4q9Jvv.7YKXAZI..nuQeEgCQT5y70U+h9J00H5R8KbZAveFdPwxDpmeVonJXlpctwMtA9x+2+C+ewGO..F0HGIdkHiD6daaSdFTyCQHf2bpGPQAT4gnxpzpzCQUATTnCODq84qq9uFhnxatZKBQycMDAPdfMfaGiPwxCpmeVoblScBEd+o84I6m8keI99u7KY2uqcsqXXgFJ17V1RsN2Z0m3yWssJpwO5qHQu7lyvinK0158gJO+tPZWxn+bih3A03mUHaZSaB1Pp.W9B+MzluKW8pWEkVVYvSu7hW5g9huH9xUsp51Ej2bqkuAE0qRqlwROgqRKiFFJ0dUZ0V74q1hPzBa7UtGgWOyafl6PKwIO4IqeODnXxgVsWqHxKu7v1111P.AD.ZgKsBocwqB.gM+E+12N5nmdpww7vc2QEUUExK2bgGd3Q8WY3MyIj+eB2AE5pSOz206CkxrttFhnp547VuOje0QO5Q2ACjf8rm8fgMrggVzhVT+KOnXzg54mUD+3O9ivWe8EgFZn.P0Z3gPb8acKzVALt4ryNipqtZ7rm8LQW+XTyCQwHjyq458Q8sSOTccAT0augDRH3ke4WF6RKKQnTLeg54mUDu8a+1XSaZSnssssJZqONdeoFUWc07lcEbQ43dynzX+ZwCQ8qSO3NzbpcOD0cmdve39nrqduxUtBN24NG6phGEKGnF+rhvau8FSXBS.ae6aGUUcMPBicPas4WabyM7zRJQviIggAxjY5d0gezWQUUZU06vPQUZaX5wY.4ys2qjwUvNtvNvK8Rujg0D.TLIPq1qUFsqcsCQGcz3Lm6BJ5HBg601PCIDb0abCMROubyE1HSFZgyNq8d70T7gWDbVnN8P75wYEyFY7WG6uvfG7fQqZUqZXdXQoAEpmeVoLwIMMcNN+d8W8Uw2sgMnQ5W+F2.8Nf.fyN6bCo5YvH2IMtdHpxaNCdQNm.3sOc.cnicvndOQQbg54mUJbCi8ZyapwOxQhEtjkvKsU8S+D9k0rFSumd02OJ8Nji2b00E4b.vNE2nX4B03mUJpV.iDtM+..Fy+9eC6syN7+onmLe2YOaLm28cMRZnwAtUYVeWjyAfhEsbp0OKYnF+rRg8G7P2dJ8Qyd1vA6sGL.XxiYLnmcu6ldu2LFezgGhrA1.psOKZns4mUJrQ0EFfPBY.B29ebBGTy+KVfFGTye7yIDPIvFD0yKABmN+CKbNzhkG0CIVZjNegHbqdxITYw5WrZNHWiwZn9PoACpmeVoH2qOIrgwdFE+iel.z9.gVwLsfQsS.p7dRcKG7yNC6NZjN60l6Yx+pvvnHCZpU7jM2z0TUYfF2B.faufqb1bnZC4P87yxGpmeVonbALZww7s7Bu77Ci8JGGb5WHnuVyKm7y65v43Eb+74cdJ89zEWcUGgVekoAMjmv4E5odpLcv9MqQQ4CiPJVvPM9Ykh5AyThhoxJQg+NpFMa7qAIOug.i7Y5Aip7QDHeDN6wUtrxTw09TodRXCCAs2SOA3D9nt8stMt0MuI5dO6oFWG4duovPEC2TgZ4kQ00lc3tHz8jZ4ki1pxvH0tWiAnF+rRQY0YE13j1M3oSiiDnbXvoUYJrbkuke92Mj2cxFQFYjJDmbu4V8OrJ3Ya9GblYGpabRM4ovXJDPW03ZWWxK2yQoGrTrXgZ7yJhpqtZTc0UipppJ7WW9DH6TSU9LVfPPM0TCpolZPUUUEprxJQEUTApnhJPUUUkQUGu+8uO5TG8AcqacC..W5RWB+VhIhV25VaT0C8kHhHBSsJPodB03mUDRkJkcrr0u.CDyJpnPkUVIJu7xQ4kWNJszRQokVJJojRPwEWLJt3hQ4kWtQUGe5SeJt10tFF7fGL..9se62v69tuKbzQGMp5AkF+PM9YkgDIRvRV+5Q+BLP7+15VwrF0nfDIRfToRgToRgLYxfLYxfM1XCr0VaQEUTgQU+bwEWv8t28vEu3EAfbuU8xKuLp5.EqCnF+rBY.AED..5efABas0VViebM7YpL9A.zu90OjZpoxts497HlhkITieVYD6l1D5kh1SiggA+u3iGyLpnTMstTyKPica9A.3jSNgCbfC...O8zSi90mh0ALD5purUEGJ0Tgs1XC69UTYkHrd2adc3gxN8n7xK2jX7yRGarwF3fCN.6ryNHSlLHUpTSsJQQ.nd9YkgmsoM..3jW7hnOAD.a57WCcU4EXM0TioRUoPoAEpwOqL5X6ZG..xsfBX2lKb6QXpwOJMlgZ7ihFv0KPZqhPowJTieTzJz1phRiYnQ0EJTnXUB03GEJTrJgZ7yJEOb0USsJPghIE537iBEJVkP87iBEJVkPM9QgBEqRnF+nPghUITieTnPwpDpwOJTnXUB03GEJTrJgZ7iBEJVkPM9QgBEqR9+guyMjrSjaVrA....PRE4DQtJDXBB" ],
					"embed" : 1,
					"id" : "obj-20",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 252.0, 59.0, 270.886353, 185.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2012-06-04 at 14.46.54.png"
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
					"patching_rect" : [ 6.0, 514.0, 585.0, 19.0 ],
					"text" : "See Also: export+pwgl",
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
					"text" : "Objects: bach.roll, bach.score",
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
					"patching_rect" : [ 6.0, 8.0, 282.0, 23.0 ],
					"text" : "PWGL import",
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
					"text" : "Tags: data, pwgl, import",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ],
					"varname" : "tags"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-76",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 32.0, 600.0, 21.0 ],
					"text" : "PWGL is able to export scores in bach format. To export a PWGL score to bach:",
					"textcolor" : [ 0.5, 0.5, 0.5, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
					"border" : 0,
					"bordercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hint" : "",
					"id" : "obj-3",
					"ignoreclick" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.5, 107.5, 20.0, 20.0 ],
					"rounded" : 60.0,
					"text" : "1",
					"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
					"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"bgcolor" : [ 1.0, 0.788235, 0.470588, 1.0 ],
					"border" : 0,
					"bordercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hint" : "",
					"id" : "obj-15",
					"ignoreclick" : 1,
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 402.0, 260.0, 20.0, 20.0 ],
					"rounded" : 60.0,
					"text" : "2",
					"textcolor" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
					"textovercolor" : [ 0.2, 0.2, 0.2, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.score.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
