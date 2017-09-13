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
		"rect" : [ 56.0, 44.0, 987.0, 495.0 ],
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
					"bubblepoint" : 0.04,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-38",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 129.5, 395.666687, 260.0, 40.0 ],
					"text" : "If an object has more than one voice, there'll be one list for each voice!"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-35",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 382.5, 274.0, 79.0, 19.0 ],
					"text" : "dump cents"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"patching_rect" : [ 591.0, 333.0, 118.0, 21.0 ],
					"text" : "bach.portal @out t"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 591.0, 369.5, 329.0, 19.0 ],
					"text" : "( ( 5300. ) ( 4700. ) ( 4200. ) ) ( ( 7100. ) )"
				}

			}
, 			{
				"box" : 				{
					"clefs" : [ "F", "G" ],
					"enharmonictable" : [ "default", "default" ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0 ],
					"id" : "obj-30",
					"keys" : [ "CM", "CM" ],
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 1, 2 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 2,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 382.5, 303.333344, 184.0, 132.333328 ],
					"pitcheditrange" : "null",
					"stafflines" : [ 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")", "(", ")" ],
					"voicespacing" : [ 0.0, 17.0 ],
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, 2, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081753600, 93, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081753600, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085430784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081630720, 88, 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082740736, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 113, 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 65534, 1080426495, "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086045184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082126336, 100, 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 1 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubblepoint" : 0.92,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-27",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 306.5, 50.0, 260.0, 113.0 ],
					"text" : "But if lllls always drop the external level of parenthesis, why these representations look EXACTLY the same?!?\n(Except for the fact that for bach cents are floating point values, whereas OM outputs them as integers?)"
				}

			}
, 			{
				"box" : 				{
					"bubblepoint" : 0.1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-19",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.0, 289.5, 351.0, 94.0 ],
					"text" : "The answer is extremely simple: remember that bach has no MULTI-SEQ or POLY objects? That's because bach.roll et bach.score both support multiple voices. Thus, the outermost level of parenthesis you see in bach llll does NOT represent the external level of an OM's list, but rather it represents the fact that there is ONE voice in the object."
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
					"patching_rect" : [ 573.0, 39.0, 79.0, 19.0 ],
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
					"patching_rect" : [ 677.571411, 200.0, 118.0, 21.0 ],
					"text" : "bach.portal @out t"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.0, 233.5, 329.0, 34.0 ],
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
					"patching_rect" : [ 306.5, 50.0, 260.0, 113.0 ],
					"text" : "But if lllls always drop the external level of parenthesis, why these representations look EXACTLY the same?!?\n(Except for the fact that for bach cents are floating point values, whereas OM outputs them as integers?)"
				}

			}
, 			{
				"box" : 				{
					"data" : [ 9682, "png", "IBkSG0fBZn....PCIgDQRA..Bf.....4HX....P+ky8r....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6c+GeaUeeuG+k1hII.NfCERiAVBjvJgaiRIdzvOJrICERJOt3zVnr1n7Xk1hbV2Ehy5HolKj8XNLRcncAG535DFyY2EyiapSJ0ze3ze33NSu45zNGZU1sNc3z3zhrabH1fEIVdx2889GR1VRGIcjrjsjse+7wi7vQ5bz46W8862yW8Q574bNNLFiAQDQDQhvuWttBHhHhH4eT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEyJWWArZrqaS82+6..EUzkGwxcnxWkuJ+oskuHR9h7v.DBYyeol.fk9A9X.fGOStWvGU4qxWketq7EQx8xKODCQN4TIk.kTBrm8L48MWT4qxWketq7EQxOj2EfvH+rlo6xT4qxWk+T+xWDI+Qd6gXXDs2dn+14u56Abap7U4qxeFT4Khj6j2EfPjIDUnIkh+xT4qxWk+zuxWDI+Qd2gX.fc70VSJ8bp7U4qxe5W4KhjevgwXRZ5I+q+0+Za2H6YO6gpqt5rVkRDQ.vgCG7e9e9elqqFhLiTJcHFVxRtd.3G9C+QQ87ezO58..aYKfMwYHhHoMGNzYOgH4Jo0gXXj.Bh8+KhHhHSujRAHD4ubvG8idOQEbPr+pBhHhHxTeo7ufP7BDPAGHhHhL8Td4YwfHhHhjakxAHDubNP4gfHhHxzSoT.BwlyAwlSBhHhHxzKo0gXHx.CT9GHhHhL8ksWnj9xe4ubJsg9JekuRVoBIhHivgCG5ZrhH4H1Fff1AUDIWQy+HRtiNKFDQDQDKT.BxzBW3BWHWWExHS0q+hHS+n.Djo75u+9Y9ye9ze+8mqqJiKS0q+hHSOo.Djo7BDH.CMzPDHPfbcUYbYpd8WDY5IEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEY4.D7yqu2cw110qQ2Cmc2xhHhHxjmYkM2XGe2eQtqMrO.n8Y6kuU4KOat4EQDQjIIYueAA+GkmNbvA.z3F95bBcZcKhHhLkTVK.gSbvuNMB.kQUUWIvd3G7K0UFNQDQjohxRGhA+brlC8qGTYSuHO8pKl6kuKd9ImhGekEkcJBQhxv32uenfBy0Ujwoo50eQjo6xR+BBCya6CfJo7UWL.bwy4Jf.AyNadQhvINztnTGEv7l27Ydys.17+Pa45pTZYpd8WDYlgrS.BANCmpEvUMOHKJ7SEDv6g5.+YkBPjPN1dWOKaMajVh3412V+p4r5S5Zpd8WDYliT5PLzSO8j7U37+F9o.2wRt3vq6awd2XKvpe.NSO8v6k40SQf.cvy9H6KNK3h.fyblyL4VeRWS0q+hHyn3vXLljtBNbLYUWDQDKrYJJQjIHozufva7FuAKXAKHIqw4Y+O3Mv68U9M74K504tW95nC.2uzQXG2+hyJUTQHPG7XW+cyAi5Icy2uicvRJ3BbwW7EmvW5EtPxW9DAKkYFT+mop3hKNWWEDYFqT5WPn6t6lEtvElzMzw2854oO8xovsuEB8in5hl68vT5Ul8prh3+zGkWY++.5cnYyRtk6g0r5UhcmmL82e+rvEtP5omdnnhlbNqZRTYNdp+yj4vgC8KHHRNR16Jo3PdowsO1wW0YUOkBNPx5JbQqhx27pRqWSf.AXngFh.Al7txcknxb7T+EQjbgTJ.A6RdpyczWFmazaDOyp4YenkYexMJxjfQF+lpIAX13vQjtkoHhjuQIonHRdMcHFDI2HyRRwycTdvk+w4HQ7TKaaMSye9kkkpdhj4NyYNC27MeyoPx1ldq6jw1YlNkjhhj6jRAHrfErf3jjhmkcrtHCNvEdbeNt3abQ1lPihjKD+wwY95NYrcDQjIai6qjhGa2+krkHtbvUemGlcW8V3v+v2LaTuDQDQjbnwURJFnyWkRh3V67S7MNNtt3eN+Su7OFu64k3N92tc.35uiGBOetOIK8xxdmrDhjtRmDFLUV2.m+7vkbILmrTYJhH4iTRJJhjWSIonH4FoeRJNbWr8+famW..bSqu4iy29F9v7bw7ZVFPGi9namWsiCvptrrQUVjzS1IIEOOubw2.z7Q3RetuFK9EdAV0kjcJSIwTRJJRtS5mjh96geS3m2SiOCenAZj6B.bQicdPtlC9Hbf+nWhmszB4nuRUbqqa6.Ggc8Zcxg27cNA7VPjTSlkjh9YdNg4U7h3hl8v76UvkxBWXgY0xTDQxmj9IoXAPnoEcxCemKBe+rCC.02Qi7.KoHttaqD9t+nS.LGV0m4YoyFp..Z4PuA8m0p1hLYatLOfc1v2le1oZjxV77XWGS2LyEQl9J8SRwy+171.vM.A5gy9tmE3oXkW16QO87dPQKgfeq+E57wVJWBvEeG+Y7TK644YFJ.mqmdXx6hcqLy1vb9yed32+R38d2yAjIIo3vbr8+brCuPGd2.ibMC8r83id54xhZ8FOkoHhjORIonHRdMkjhhjaLttRJ9V+f+Z9ve1Wha+IdUNvlV.at3amOv24374W4U.Df8+4tetns9c4iu34.7Vr8h+v7Bqdm7l+iOLIIutDIic78+Xbea5fw7r+Q.+qIIgAi9a9aM4BOO6+ycCroCAO1e+eOc+WTOd9MGfkOqLoLkTgRRQQxgL1.vzc2cGyy1qoFWX.LU1TWFSesZbAlJazqwXLFu03xTQS8ZLFio857DZ8Z1mcEkHYlA8ZbSnwkQ+u6KAiiMlNZpFiqHVW2U8MS3X9p.Ssczko9xbaZO33uLkTWJLEkHxDjw4URwqjGuQuTAv1Wyho7uAr+95hUdhuNqcaGh48QVKGt9uIGXGqmRdj8.Uz.UVp9l.xDrfAItoM3M8mvEM6YyblSzWZiN1dWOKaMajHtffx915WMAa74vU4DH3v7eLv93u5I1EG6rCm3xbY2w34cfHhj2HCtcO+9Xy+l2fa34pj+hMbWrmM.O5S7Tr7Y+8XCk7B3E3g.dr+9uCa5iuRdud5g2KqV0sW1311qLERf2INCncy2+f+YrjBdHBDHvX2BxCzAO6irOKqMbQ.wYLeft3jdgmy4RC83V1Hu58burvaJ9k4qT6+U9L+waUIonHxTVJIEEQxqYyTThHSPxra2yIzvr+OmGtpm6eDWWw3rlkgzUxNIoBzAO10e2DcpE5lueG6fkTPne4owtmKbdd4G7F3oOBrrkAczAr2e5ax8dMINka03urCkjhhj6jA2tmiT.76OHEL2BYNg2h2kqYy287ygOyGrnrP0b7SWI6j3agTWWswGc++.5cnYyRtk6g0r5URQ.8e5SyrV3bngUrN9f+3CSoEAe5mtZd50rE132rKJ7u8oXI23RIEtPJpwehHSYkw2lE6+3GfOoyGJbhd4jZaqIJeUEy0cakP6G8TvpxsAHHRhT3hVEku4UEyy5m+4EuXvamLuq6pofv6grjU+WRct1BCEbX76yO+GS1UVQDYR137rXXD9owm9ghHKv8xF7rO5GnvhWB765My17RdgKbgKjqqBStbByqf4xEge5uuQNGEFjdaAd2fyka5gKkKOmVAEQjIdYV.BC2G8NPLOm2dnuggYM+4C+19zkV4o35u+9Y9ye9ze+yTtSZjn64BExZZrAtmq8p3NK+wY4ovgWPDQlJKyNDCyZ9L5UhdmNAudgJtOVxrfC+bqgScKdYNI60K48BDH.CMzPDHvLgP8Flit2sxN8Bdi3dtPffCC.K+AdPae8986GJPQOHhL0WFdHFJjO0Ws1P+WudgxpgNdhkwAdxUvcucOrOOKOyqghLoYP94+O29nAF.PYUTC2y0a+G3ehCsKJ0QALu4Mel2bKfM+Oz1DW0TDQlDjgAH.EsxxoOuMREk4DZbirrqdwrO1DcM3tY45mOPlhY1yKzeqr95wMtXqO2iyJuxj+CskdWQFEQjoFxfqjh.DfN9IMSKutW9+8GderspWGyeAWG27ptUtn96gdxhUzzU7us8lYlIdkYbhncLe188+337DMtbt7q8F3ZV874s6oG5IY6kjtWQFEQjoHzURQQj7Z5JonH4FiyqjhA3Uerqm+hC9nzbG+MrrvYpXfybTdha9iO5Umtm3abb1zGYXdwG7l4YNB7nuTq72b+KM69NHJ1ca6c7al5UFuYbuuCzE675ucdtHdpm56zAewUdYIX8s+JxnL9oqjhhj6L9tRJ18gX2GDv00xUdEWJEUT3qfhKbsTm253fNeD.349TuBk26CxwORnW1K8nMweq4Y4JyxuIfPII1WLhiCr6p9lwutmglodkwalw6a+r6RiN3..txEd0rvDdYSLwWQFEQjoxFWmlim8D+rPY5cKaEmW0VAbRCccTdvEMGJ7FJA2.gNpramezu8SyZcCMtOvS8e5IjfCN1dWOkDywAVIIlLdLT3+NxYsaicM.OvhR9YwP7uhLJhHSsMtRRwN79KhYM7xKu+ivcr9kALWJY0v9NTnk7SZ68XG6na5dGgd7n2tcyVljRRrYZIq2Hlo899V9BOEzxyv595+TJulp42O36QO8LYeiJWDQx8TRJJhjWSIonH4Fi6a2yu0w9tzPi+TdGlCK8Cee7It+Uxk.v6dT9bK6iS3e.Ap9Uqme5GecgRhqUuSdy+wGlDeSxcbXRJIwlYkrdSbI6Y9uyyKV7M.e+2fR94eGl2m3yyxxpCXkzgRRQQxcF22tmW38+E3Vt+ufk08rc9uOZvAfGVycrbN9HOb1WNKXgKjr6Eh1I2jDKakrd4qWSElrR1y7YepFaff27GjUduenbcUQDQxYx3a2yQaXZ+aV+nOpxldRV9UtH965nMdn+8yy+k67txxAGDxTsjDq+96mEtvERO8zCEUT9S9tqj8LD6umKHhHS+kgWIEiw49IrsmOzUx9k8n6k+7UbQgRJwK6Ofa4V.BbVx14n3jkrYx5clybFFZng3zm9z4O2DjzUDPQDQhfRRQQj7ZJIEEI2XbmjhQY32hW7O8CyybDX0OU87heQWSStMOOwjrd4kI7nth.J4gTRJJRty3NIEGwvm8n7DEeq77.U2TGr4UeiYy5WNyjQx5kek3e5JBnHhHiICRRw.brC7bTxCsUnrpn8W7IXkEO832MHSSVu.98CEV3TteEkoZI6oHhHSbFGIoX.5nkF3oW2V3Hb6ryuwQ3g+HKFn+orIfXTxfj06ceq2hYcMEx+q69yyG3ad.9HI396yLsqNghHhL0iRRQQj7ZJIEEI2H6jjhSmLtSVuyyKe22.W5teCtnmsRtjpdAt2qI9WB9xKSRQQxCojTTjbmLNIEm9Y7lrdCy0T.rye7QoztODO+G9Fnl1GfGekI9RC0Lq1UQDQlJIKekTb5gzOY8Flit2sxN8Bd8tgP2JrABDb3nVG+98CELQbsjTDQDI6J6dkTbFqyy+xKs8QCL.fU+naiOzk7dzSOAnyVdY9xq6o4HgW1mXyuLfZWEQDI+kRRQQj7ZJIEEI2Hk9ED5t6tmnqGSCbN1YwKm2Wq+TtzmsZV5ddAV9vwKgGA3OA3GqjTTDanjTTjbmTJ.AkHcohKkk3D3xmOydnCxW4u6t3q932FCGuU8ltOtnS9+gEsnEkWc2bTDQDYDozgXP+Deof.mjsM2kxVi3op9e4mvw+i+HD8kcIOzde6lab159afH1Qy+HRtiNKFxJ7yt+XQGb..y4RcxK1Ua7Qh6oLoBNPDQj7WJ.grjgB+WmNAudgF6Z.dfEUHft+FHhHxTO+d45JvzCEx8u4pAfu396h5c6lELec8NPDQjotT.BYIKY0+kTmKffCiee94+HWWgDQDQx.J.grlAo2Vf2M3b4ld3R4xy0UGQDQjLfNKFxhN9qc.BdaqkUdkJ0NDIaPy+HRtiBPPDIukl+QjbGcHFDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKlkcqfCGNvgCGSF0EQDIJZtGQxcbXLFSttRDswpN82+6..EUzkGwxmnmvPkuJeU94txWDIegs+BB4Ja9K0D.rzOvGC.73YxMNFU9p7U4m6JeQjbu7xbPHxImJoDnjRf8rmIuu4hJeU9p7yckuHR9g7t.DF4m0LcWlJeU9p7m5W9hH4OxaODCin81C82N+UeOfaSkuJeU9yfJeQjbm7t.DhLgnBMoT7WlJeU9p7m9U9hH4Ox6NDC.riu1ZRomSkuJeU9S+JeQj7C5zbLgkuC5u+9ygket98uJeU95zbTjYxxCCPH+fCGNPMMhHhLSUd4gXPDQDQxsT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrHu618b9DGNzMlFQhktGkHxLCJ.gDPSBJhUJnYQl4PGhAQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhENL5tRjHRBM1zC82+6..EUzkGwx0MuIQltR2MGEQr0l+RMA.K8C7w..Odz2qPjo6zgXPDIohL3fRJAJoDXO6Q+xAhLcmBPPDIgF4vJjtKSDYpOcHFDQRYs2dn+14u56Aba4z5hHxDKEffHRBEYBIFJnf3uLQjoezgXPDIo1wWaMozyIhL8xD9o4nCGJYlDQDQx2X2G+OobHF5t6tmLJFQDQDIETbwEa65nCwfHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhE4EWnjRkroTDQDQRMYiydv7h.D.6OeLEQDQD6kst9CoCwfHhHhXgBPPDQDQrHuN.g969rLbRdbtxv9OKm0ept194zcmxq7DnzqdjuzV6u6tIPJttC2e2zeptxSnTa8jkol6KN0rsNezTy9eq0izY7vjo71.DN6quMl+UWK9i2iCbR1Q4kS4i9u0S4a60FccY3SytVeo3vgiP+aEqkce3SFcALb2r2MMx5rB10ghY4.G+.aazswZexCP+ge9Aey53pl2l3j1Nq9v7ZkOOV7K+Ki44Cvg1Q4r9Hqy.m701Aqe8Q79ZSahMU95YGu1X0M+m7Pr9UD98UoahWu6nqDIb4AdSdfqddr2ia+NHw11O1F+3rs0uV11ANwnOU+m3P7jQzVuh0uMNZ2wLTOCZq+ku7Uyb21qaacF+GiGb9WM+aCBP.N7t1DqOhwHqe8kyqcxnqWIpLS0kmsaqsq+OvIeMJOxkW9lXSap7XF6aSacRV93qsFf.7568IGa+MGNXaiNlM6zWjn15LYewyd7CL11zgCJ8Ies3OIcbF2mr5zXE4DPas+SvtJOx41VeLskIquHjLcbeTrat3vsCux1V+XsykuCNdLazwacZ71+a29ZYi4hSX+ebleHkGOLYyLACvzc2cmz+YoZLnWSYfopl8E+GOP6lx.CNcYb61swcYkYJqhFLCDwq2iKOl5atcSGda1TYYX.mlV6azUvzfGLfKSCs2gooZba.L0z9nqfwWSUY.LdpqUSGsVmAv3rplCuz9L05BCU0ZReu2aqUYfxLsOPzOuulpz.XvUsl9h348VmGC3z3zY3+AF.iqpaK7661B89trZLd6rMSUtv.dLcLnIkVdmM3w.UX5JYU5XaqGaAl58Dt9TS6i9rsWsSCtpzzTadMs2TsFWfApx3KhWWlzVGr2lM.lZ8FSiXTBZZzCF7zfIza0AB0+P3wGtcaJykaSCcL11H48u1u7Ih1Z65+Gva35wHK2UnkiyZBONxt15ju7wWaswzV0tL.lJpqUSmcztogZpvTQcdGogJi6KRda83aewQZKwcMl16rCSaMUqwSE0E09iizlEuw81tu3DQacvNMUBFnLSCs0goi1axTsGOlF5bzB0l9hrv39XY2bwFio0pbZ.ml5Z1qway0FZbs65Gc7SlUmFe8+1suVFOWrM8+wN+PpMdH0Mt9b23scxJ0lrbEMzf7pL8lfGaFrciKvTi2AMohfcDZPU0sEd2eeMY.LU1zHeL1.l5biA2iLoWelZbgAOMZBFdM5pwJLfKSaiNASsF.Si9BZhqfcYpDLtp0azOeuMGZfEXnr5LIa3PnxzoootBUFcVuaC3w3cr8rB89H7GvX2xMA6z3ALtqKl5TDrzVGVmMFNnFvTVsiMQYvAGvDYKPG04Np1orQacyUF5CAisNMhAB2+1PWirEB8gRVZ6Gkcko80oIx15QDa+u02FsZbBF202Qz0gD0Vaaew3nsN7DktposD8Jxv9B6aqS+8EGYx6JSd.blDOt219+If15daNzGTVWGIXdOa6Kx7w8VX6bwCXpqLLT8Xscdq0UDA0l40ow8bwQvt80R24hss+ONyOX23gzwz2.DB2vUQicE+GaLoc.B81bncxaNbKenn2JyzdDubu0VlAbGpCefPa+JZZrxLXWMFNBvQ+jOSUIYP2fcDZPaSQMnMbzttpxTeMkYvYsIN.gvQl6NhuIVckE5WcXrWS3uclmFMAsc4gzVMtLP0w4aJYheaswXL9ZJzGDUailZcGy2jJF9hcx8rPa8HOtgthe+caU4LleMlvenTMIXBA6JSaqSSfs0QTGKijEfQ3OjyY0iNghcs011WXR+159Zq5PiyCWIBZY90LruHkZqSy8EGzqwMXbWemgqyI3CVR33d6qSY+15AMM3NzGfLPnJsI1Zss8EY7393HUCPvUUg+10CXpsLLTYyYw5z3Yt3naWR59Zo8bwoV+eryOX23gzQ1J.g7ubPv+ayaBbcWy7i+iAHXP.XiNWEqu7swAN5IsjjWCe1SvgOzg3U10l3pt6sSEM3kRuxPK6Bm6LQtY.fqXQ2DfOtPPveW+LZA3FupwJyYsfqix.9YmvW3m4pXEdfVN1uJtG2xtN1OAnRbV7XWpIN9deb1PKNo4C9zrp4EtdlflgCu8GgFoRdlO6xG84FZ..W2DEFw5M64A7lcg+TX4.bStdXfCwoh2gGOds0bV1wZVCdcUKuX42Ky1Wbdci5z7xO8yCbq79manmIazVOqEbMTFvu92MHV4medKdw0ZucJJhmcnyAsrQmT5ZKmc7JGlyFQCsckYpTmlXZqGS75+i5ker8vCsGnt8+3DdXsss01s7PuOSu15S8yOBfSZstPG26BJvAqX86hSDw64Lou.Rk15zbewAu.9.t3296R4qvAETPA3vwZ4UN1Yi3Uk7w81Umx9s0A4b9A7dX1d4khiBJfBb3fMs6Wez2y10WjMF2agsyEWH+o0zHzxVYYysTVaoyiMbppnqpJMKVmR+4hijc6qMdlKNU5+ic9gjOdH2HuK.A+m5nzBN4CdsEF2GC.EdSTSqsRqMuMVNGfG5VWJ26Nd8nFXN7E5hu8q9pzz254Af29WepnlXBfBJXr++7W7hB8bQr7gBF4KHTupu29cC+3Yw0sxxf15l30cFzuOv4hFc.TfS9J37Q1GU07OhRKBBNz..vbiyqMvIeEt6s6kpa6IXQwrLmW1kD4ZxusQf4M6QuhWY2xCoE50u0PShWa8Q20ixV75l1ar7H1Yn.KuVBbZ1QoKls5sLZ1WUrnX1WLiZqm0UvMAbne9orVtC2KmnkwdMgTHO39ZiVasY9Bkdwrk0c2bUE7jDSdwYS+q8KOa2VO5VJI8+gzMOeIaDpnIbeiywxRsqsNoKOMaqKfBA7x1Oz6mN5sO70QS3beajkU1tCmHYYm9hj2Vmd6KFpsG1yF+V7QqqKFnuNotJNEqqj6gCGdRhTYbepz+mMaqmM.zHCda+Mz6.8Q6MTIO+FtKp70Nc3sqc8Egjoi6iRJLWr+eWO.fSWmiFaAv6awI8E8.fLqNkd8+Qxt80xj4hA62WLp4GR13gbj7t.DFikeSfH9+Exxuy6j6rzGfMu6eAMWkKZYK+0zdDeqk4rnUyN28t4e9vF70ZMrusTFO62KzNRAGJ7JEwmoDJJyPOUAEDZnzru3H5pCutq3O78ONdu3m+oGcc.vVelGkRKsTV1FZA7tAl6JJmiE02v7rrqOw5fxpi+7UUjksj2+uuUDQIOGt1x.FXnQacra4gdy6zl5a301+QwyFaDXe7Ws90Rok9w3QZIz2FbEku2wxT4ydTV+bWLagpniA9VTZDQpmcZqGlAAlW7BLgYE2frJd4qh67NKkOyiuSFva8.amC9KBMMockYp1+mUaqGUx6+A336cKrUbRyO4piZxH6Zqsa4iTeRm15fC4GvIsdvGma7JKhhuwUy+85bCsre92CO.IS5KFgss0ogBu1OHNA7zvKwCtxEQgEsD9rOY0.d4e8W6OkG2mr5zDQa8P.3pVp5ydmbkEVDq7AqjZcAOeC+uI.12WjsF2GSqYxmKt+Wm64V2.tqyK+hC+KvWa0iK1C28h2HmHvDUcJUY29Zi+4hSo9eKyOjrwC4F4cAHT30cy3Du7u8aGLtONdJ9ZmWR2lEem2KtA9Em32A.W6MWBvo3chX1kfusOfak2egvbV5JwMPSsO1OqV.e+LZDXEKdAi7Lbpi0Hbcuu39ATEL64AdOM8A.yk6Y6MSSM2LMs4MvS8TalZ73DvC0W8miqMhMvoescxV7B0tsOYLQ7NWVzJ.ZqqHFy4meaifyUeyTjsKezJFvUvUUn0etMKs0y854q2TSzTyMwl2vF3odpuHU3DvUUry+atBU+F9j7jW0sx9JqNF3vOM2XLgomUZqG9BbJfa+CcMVanm07YQtf39qZLx6qqIzDIuS+g9UarqLsuNMAzVGVh6+Cq+WmM9H6CmU+0G8PlMB6Zqsa4.oca80dy2NfWB2zF5s8EcwwqlG58cZ1WjZs0oy9h.Edk3D3Lm6BisRyoHbMx+21w81Wmx9skNSwlP..PA8kDQAQ0EvUr.fyEYPQED5WU3ZmOyB66Kx7w81K14h8+V+R7BT18F5mmu3U8Ynw1pF3M4cClspSoY+eX1su13et3Tr+O14GR13gbkLNaHx5IKQelZbhwSCclfGaLlf8Y5rKelACFzLPWsYpvYnLRtyQxAkf9Ls0Z6ldGXPSvA6yzZsdBmQoijnKgxpUbWqwWPio21q2.XbWWGiVDgxv7xLM00.Fy.cXp1UrYXZnsQEME6oCXXgyh0FSPVw1QsgRRwnSGkdMUG98R71pCFNqlqrAuFiYPSq0TVTkgcK2XBeJGUV8l3mFLwosN5ZfotXxH8Pm0BXbWSSl1aqMSqs1po0Va2z2nEYl2VOXm0GJwGia19YLcTu6HxJZiwXBZ70YmldGXPyfC5yzXUgZGp2xoCVhKSaqSSHs0Iu+Ox165ialraWas88EocacvNLd.Cdp0z0.AMC1a6lJcFY15m48E12Vm96K1bkNMPYlF6nWSvf8YZp5xRx6aqi6S05T1rsdf1CkrcUTe6lAMAMc0ZsQm4711Wj4i6svl4hC1UCF.iqpZvz6fAMAGnKS8U3L5j0KiqSim4hsaesLat3To+O14Gra7P5H8+b2Drcx7pR1uh5q4JMPYiN.J1GaFnMCgO0i.L3pBSq9hXByvYVajqimZZNpIpC5qYi6HVtqpZLlynfdM04wYDaiJLQbp6G9zdwyXAkXQ3rNthlh6R8VaYwjErlQyVVWUm3yo2NarpndeUSq9R8kG9zhKxqAAwxRacTBkotkEQ195sV2Q2WPny82HOsnxr15AL04JhrdNtUq1Lt.S0sMxTF8YpIp5iSS0M0QLunj2+Z+xm.Zqss+e.S8tiIX3XXWacxW93os1XFrylF6T2ELTV0lw97+rQeQxaqGW6KFzmoVOQOlsAuIpux53d6pSgJhreas2FpLpxzSssE0YyPx6KLlrw39XqiIctXiwzQiUGy7CkESaclUmFW8+1suVVXt3j1+aY9gTX7PZXZc.BiNQ3nmFSw9XiYf9503ymOiudi+oeSvAGvzWu9L974yz2fIZ1zAL95pqDtMLFioOe9Lc4q2n+Vf81rwYL63F+Wbncvqp0rwY15XBNPult5xmouDb1vD+kG9Tyoxlrb5QEMqs0YEiy15P6761jnS86QD5hOkaSGi7MWFrOSu97Y74qWSh59STYlNKeJYacBV93ssN5so0OMIa0WD215Lbew97EZNhAFmc.1su3DQa8HkYuIpRmj9hQjoi6ijcyEOZcZjw.Yy5Td9bwwu+257Co53gT0z7.DLFSvNM0VUCQ7SYFyiygFva8lpaH1uETBV2NZvTURtX4LoYPulpprtT6hvQdTas25qwzTJddA2Vc0Z4pVYNgZqmzLkbeQyTy157QSI6+iy7Coy3gTQ1J.AGg2XSXb3vAc2c2IccJt3hYBtZHhHhLiP15ycy6NKFDQDQjbOEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKh+s2pb.GNbjqqBhHhHRX4EAHX2oigHhHhL4RGhAQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKlTtYMIhHhH4Wr6i+mvOMG0coQQlJar8e6u+2A.JpnKOhkqu.fHSWkWbcPPDI+1l+RMA.K8C7w..OdTf+hLcmxAAQjjJxfCJoDnjRf8rG8KGHxzcJ.AQjDZjCqP5tLQjo9zgXPDIk0d6g9am+puGvskSqKhHSrT.BhHITjIjXnfBh+xDQl9QGhAQjjZGes0jROmHxzKS3WGDDQlJSmlihLSkBPPDQDQrPGhAQDQDwBEffHhHhXgBPPDQDQrPAHHhHhHVn.DDQDQDKT.BhHhHhEJ.AQDQDwBEffHhHhXgBPPDQDQr3+OaMolBpWG8vC....PRE4DQtJDXBB" ],
					"embed" : 1,
					"id" : "obj-25",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 39.0, 535.0, 228.5 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 14.33.06.png"
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
					"patching_rect" : [ 573.0, 67.0, 385.0, 121.833328 ],
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
					"patching_rect" : [ 199.0, 475.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 527.5, 246.0, 20.0 ],
					"text" : "linksections 1 1 l \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 500.0, 69.0, 20.0 ],
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
					"patching_rect" : [ 555.5, 454.0, 257.0, 36.0 ],
					"text" : "Ok, I get it. The structure for a bach.roll is: voices, chords, notes. Good.",
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
					"patching_rect" : [ 290.0, 7.74086, 317.0, 25.0 ],
					"text" : "- ...multivoice!"
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
					"text" : "From OpenMusic to bach (l)"
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
					"patching_rect" : [ 5.0, 595.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
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
					"patching_rect" : [ 5.0, 570.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 545.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-37",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 520.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (k)",
					"varname" : "messageA"
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
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 495.0, 40.0, 18.0 ],
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
					"id" : "obj-41",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 5.0, 470.0, 151.0, 20.0 ],
					"text" : "Back to section (k)",
					"varname" : "textbuttonA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-42",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 595.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-43",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 570.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
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
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 545.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-46",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 520.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (m)",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-47",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 832.0, 495.0, 40.0, 18.0 ],
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
					"id" : "obj-49",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 832.0, 470.0, 151.0, 20.0 ],
					"text" : "Continue to section (m)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 553.5, 190.5, 553.5, 190.5, 495.0, 208.5, 495.0 ],
					"source" : [ "obj-198", 0 ]
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
					"source" : [ "obj-26", 0 ]
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
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 2 ]
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
					"destination" : [ "obj-33", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-39", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-44", 0 ]
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
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-47", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-49", 0 ]
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
 ]
	}

}
