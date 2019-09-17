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
		"rect" : [ 56.0, 44.0, 901.0, 477.0 ],
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
					"id" : "obj-63",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 465.0, 386.0, 69.0, 21.0 ],
					"text" : "bach.print"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 465.0, 357.0, 80.0, 21.0 ],
					"text" : "bach.collect"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-59",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "int" ],
					"patching_rect" : [ 465.0, 289.5, 49.0, 21.0 ],
					"text" : "uzi 10"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-52",
					"linecount" : 10,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 660.5, 253.0, 207.0, 156.0 ],
					"text" : "In this case, we need to change the structure of the patch. We use uzi to send a sequence of 10 bangs. Each bang have expr to pick a random element. All these elements are then collected, and at the end (with the \"carry\" uzi bang) the collection is output."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-53",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 651.5, 289.5, 92.0, 20.0 ],
					"text" : "loadmess 8200"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"hidden" : 1,
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 548.5, 277.0, 100.0, 21.0 ],
					"text" : "loadmess 4200"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 465.0, 253.0, 20.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-56",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 610.5, 289.5, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-57",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 553.0, 289.5, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-58",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 495.5, 323.5, 134.0, 21.0 ],
					"text" : "expr random($i2\\, $i3)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-50",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 145.5, 357.0, 245.5, 50.0 ],
					"text" : "To translate this into bach, we can't use bach.repeat, which repeat statically an element or llll, not an operation!"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-49",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 112.0, 267.5, 325.0, 83.0 ],
					"text" : "If the random box is NOT in \"mode once\", this gets more complicated. Indeed in OM things go from bottom to top: repeat-n asks 10 times om-random for a random element; om-random returns each time a newly picked element. "
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-48",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 567.0, 182.5, 169.0, 25.0 ],
					"text" : "...and repeat it 10 times!"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-47",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 600.0, 111.5, 139.0, 40.0 ],
					"text" : "So we just pick a random element..."
				}

			}
, 			{
				"box" : 				{
					"data" : [ 4712, "png", "IBkSG0fBZn....PCIgDQRA...3G...vsHX.....0DqN8....DLmPIQEBHf.B7g.YHB..R7QRDEDU3wY6c9FaaccdG9gARvRYiZQNvFNVaQN1oY1oq2zZUi5hsrtahQPcRQ49PZPVhF1BZ.c9fQixRaB3PV.F2.7jaJ5XvPFURyHPyzGJTKlYPRzVikEfF5FCRo6BCPoGrrirGnqCcBULYPIcIge2Gt7OWQcIEoDI08eO.Bl264vy8bt+tm2y64btludDQDbwwwMrYWAbYyAWg2ghqv6PwU3cn3J7NTbEdGJtBuCEWg2gResSluga3FvrudOd73gqe8q2x42N1lZEZKgWDwRbSpcvN1lZEbM06PwU3cn3J7NTZqw3aDW5LmAF41Ymd6CnDW4BKx4u3k3CWFtsu3A3ysSu5xcNN8olmymA18ATY+i1po0Kn.m6c9u3WbtL7a+68Gve3cuWzpAV41TCPZCLJ6KEMf.HSFKiHhHYiGR.DTTEUEzRagzkycZIrODPQF2mh.Hgh0JoswpisV9yHQFGA7IAmLnnBBpgjzVv1TKUlajJP9jSqcCAjPwyJhHR1EmUhFuRiqnDcBDTiHYEQxmLh.HyUN4EBpzRosQpisb9yrf.HyVopmYtp0GqVapUX8OFet2gGdeOJAmKNQ7AEnD.3cOeU956eakyTebG2kO3iyRIfyF6DfRH9BkS9y+.eSX9SvYy07z5ETJ6GB.eZ1BZmXveKT.9zhkrrsolw5T3uDG+O5fjMTb9atGEt1G.F5tPoKvLOVT78T2GCCP1rvA2EUFky6NtCfrTbsRqGPei90X1fp7Mt8A4ddp+N9qe3CBAmi6em00trPsolw5R3OyTiyylHHuxe9mgbKeAtJvmjNE4JTpVlJcAN98sKdd0v7J+k6E.JBn7YusZOhr0QPs7GaVZ8DxsDK7imG+Qli+V0syuLJjX9eFI026zp0lZFqmwZRN8DkczQQTTTpNNu+HIDQDoX5XhePXhokL599IBqJ3Khju7wEWLh.pR7rMOs0Scrcye13SJvj5F+MkD.jfkcZ0J0lZoxbiWAxKgUPlLgVyKS7xN7MwzxRYxHoSmRRkJsjWDI+hZoMSxLhHYzbRx2zqYZa753Zm+JNhoc8EI+RyJJfDIYdKWapkJyMdEHqlvGW6FVhviW0BPs+TkXkeJOdjIzcd+RrzEqVRMKsMVcrUxeVYtP9WQ81e34j7Vv1TqfmxEbKgGOd5HanQobKyxE.uaaXFnMRqaTGqO+kJjikyUfA7tM71FU.yTapkJyMCguaxFU3MizMpitqUuCEWg2ghqv6PwU3cnzVaKqGOd5JuFPcRZ25mcrM0RkY63UemEgkW9S.fgG9l.L227WaztMVqMM7lYkYMoi7hXrd3Yd5YAfa+2+9A.+92rpIcNrRsoMkw3elm9s.ztAM1XvXiAu7KuYTS5bnWzsBsodtvu7xKutRyLiUrMsoYpuBwiq8uK9+9V.e4M05RmBqPapmK75c5Q6FiwoYkvJ1l1TFi+3eu6ukNmUhi+8NrAmy71l1DmNWsw+rOSmyit1j4rmdE1zFi2JrqXsGdrTsoMUm6VO+GbrahYeE75jroI7sqH1qDEqRO1MJtaRiCEWg2gxlpW8MmZUqUtYNUnyZ5ekyvnyW9lM1zW4t0hUuwGc9mS0u2AcqqgYCSsodi23iNaOQi2vH6cucvDK7ULu2to0dWCq2lqzovzapuB8hM9vJr4JcJLsBudG4V8FebS0m8040v5s4JcJLsl5gFswGq9barqgQaXTm8ZXFwc5bUuFNqoyYhEdW5lXZGieiSsmmO4n6zvbbnKbIcGYu6gWO13d7hgBdlollsdjGcUm+PW3W0KpTlFrQBuw8vajPaDNIw2T6U+5kSdwKW8ya8v2K6V2w5IyTSup76TvVNF+gt0crBwbL.t3kQlcN9hG9dINPbfCcjG0QJ5fMU3AX+yNWUS7UD2wJK554P25N5w0LyA19w30i9d2FI3tiwaiYLzrF3zw4H704vGTy4NmHVXgu1uhXmbzaogl2yL0zMzq9J9.3De.vxNF+IG8VZsLpSzOIZl5GFX2.mutw4cRiwa47pukE7xrLvvUD3Kd4pe975xi1R25rVxVKmvaDULUazJzM7stCVVmfqmUtV8NKrTl5O4n2R0ojcHz5MOV4zNOZluApt.MU3ePt9p7AvIYV2Hrb83qL+a8yIuxX1UD63r54o6zE55wx4UeEy5UD13n0yuYhtKqFKmodCO+ZthbNOm2VKrb83qmLSMc0w42+ry4HmS95AK2X70yVO78xx59Ltl4aIrb83qzid2W7xqXwYzytu3kIyTS616uIXo5wenK7qV037q5+uKkeXnUeqabpX45wqeZY6FPZvNss6KdYNzEtjidQZZFVJu5WIBmzi1ysUlN2g.3V2A69hWlcaUaV8HrzBeElo7C.eC455R2c5aMCKrv6xFAK2X7tzYvU3cn3fE9B7eN0w40OmIHzNuIfCV3Kxu3IdVduOpzZmUaHcAgu.4xUngotxzJ0z7tlTpDEJzXgqPtbXTpkxo0KeKJvV5eEoPtb4ng0nB4XEAL65N1RQmLdktzbgzEGUmnZbTM4LADeSDTlPUKME+gkElKhnVNuJ0EglWIYkYlXbI3zQkvAFWTTlPRjNoDPQ2aaoufRhL5uVSJA7UNMk.R7JEdwTxzSnthXDanxg147KMmLd0yqHQhkR66jOoDv23RvImnZZgmcAY5.pUOd53Mt1KhHd73wfXSa24OOd7zRZUGS3KtzLBfDN1RRwhYj4B4Sf.RJQjDg8IfOYlXKJoWpb33VYBYtjojTIiJJfDNQihs1YkvpZAw2vQmSVXgXR57okXKjPRmIqjOaJIx3H3OpTT20Z5XIkzohKA.wWXsva9bAPPMnjHcVIa5DR.pDLjWRl.jwirfjsXQYw4lT.jYSUTj7wEef3K3LxhoSKwh3uZ.GNUlTRz.JBpQZZDhtC2+pozpWqNVMJ4ziKPnZwe87wEUTjXYEIdHUQIThJIHQTQTCW63pQi5x2jq7zqZn3hHYkPJHSthftdQIwrgE+9TqE+5UCKYj5uVhjHjpnLYLQJtn3GjPIxupqqVHDWUhWU8xJgpD63yGWTQUhWNHPmOYXA7IIpbbhPBDpIVrLmBemaSZ9M04cbe8uxiKTr7GJx0.3Z0cL.CnvqkIS0wk6aPu.4KeTsASuz+92AkC+dLS7H7BJiBIeQFR4Z01wopWKP6S8CktJmEX+FT0KV7Z.e7pN+Vzmm7.dghEAHasiqTWMnbMyzwbt61u6GB3U4+38uBPIN8+5wYdtG1wfFm+UeaFf9v6vCyvk+y6.Fe6LalOB3fbf6bDX4yvO4e4UA0sXXdqx.2IOtO3kNwOkqTHGW58eC9QIfA.7tuuBiSBds238oDvUN8OgmDX26vaCKthMLEqAcrGT6aOOBIl9cQQY6kOiJQS9RLZeP15x6VFBtMctSuEnwdRaP568vOE9YL10fGC.F2uJLjlvWmcFcGO.OzKMK+fQNLa+4qk9eJ8A8sWdwDSyehhR07GLZRdvQ6aUUr96eK.CQ+5uPJMox2.tzYdeXj8wN8pWBxwoO07b9LvtOfJ6ezF+f2FlN8XLEymUxjISSc1oCckztNEa2uVdISlLhgesxoksCW40eaNe1zRxElVnhODUIsD1m1rDF2mleKghkdCcsZZ9Z6R1k1F8hQrf5mJYMgWyASj4Jq0KDTa1BMZtNsx0pY3fW4tMGtymXIVbw3DfUNJxYicBPIDegsoc7m+A9lv7mfy1kVQYWguGi2sMJ6YO2IiVueAYyBGbWTYTcu63N.x10bhzpMKjVFy8uTk5lBa0y.Je1aqlfr0QPsKVCrkBuUHvCnMSkZ296eKPhYiSgu0miA.JkJNyypmkRmBamodydfGnTgBTnPNtJvm7IYnTIsEl5ybnGGh9X7FmYYfk4s9mdLv2iyc1klQmspG+ZE3ALC+Tjm3keXF6Iipcv8tKNlZHxbpuECumGg3QdWFaeasbN8SrzODCzkpG1p24tkWdYN1e++MPMy7f1uE8Adtu7llv2NQfxR4VlkK.d21vqKQuUuV1pd71g.OPedGls0EWvtJX6Fi2oF3AZWrUl5qfGOdHSlL.lioy0KC1vs50x1J7lolkYT3scl5co0vV4bmYEOd7zyhF1s50wU36Ab8qe80NS0Q2dImcEdSH8hkb1cLdSF8pkb1U3MQzKi0stl5MwzMi0stBuIhd4RN6Zp2jQuZImcW4NSH8hkb1U3agxZyftsr3NFeKfMrugcpGuVynVHGei5LjTW3K2775a0IvV0i+Yd5YAzuhWlixxLhswqd8BUsU7Z8VVFs5YcpZp4.agv2IWwqd4pmsYhsxTeE5jq3U2b0y1LwVH7cxU7xN7Ba1JXKL0CFu5VFsJXsVYYzpms9JKyJtSmqIkmcd5b1Hg2k1AawX7sFBd7X7Hahbcra8nWKrwBulgL8h8XSY7pvnOOR0ey6s2OHXiEdMAsQhsdzmGOdtAchu8EaiW80SqJ50yXS4ugCIXmvF0iulOpMRzieDiW205yql36otd91KS+1HgWCiD8JBdir.XT5U54aWM6ailNmzPQuUM4aTdiejW1V50usqGudpWHWKS8iMk+15AEqL1VuXZjnO1T9Wwe5SqR5M5AD6D1ld7MyK9l0KVu3aTdpMVuMYDwxXK6wqWDMpmu9+pf9d5Ngd81ld7sBMx4MmvX50isrGuKqMtBuCEGkvazX2qkyc1UrsKfyZ4fW8Te55+ttKfiEk58X2I0ytQXaM0WuYciVrl5oxT7bBOXXqL0CqdgbZzT3LhFuN8fcyTusS3AiEenw6NmQrRQGbEdKBd73os2dV84yldaoJ1VguQaSKz7w4AmwKeosV3gl+xV9y8GV2Q1agtdrwBe8T60q1IzidsvAI7tnGa673co43J7NTbEdGJtBeUxwKdWd33m197qdQyvxH7kJjibEJYbhExQNCC.8kHWtbXz2pTgB0c99YK.z+fsbcpPCJaKAsYTpt6R9jR.e9koiNsDXbUQw+zR1hojHSnTMzaqFLpVn0NeRIfuwkfA8WMsfQWrZQkNVDQgJgraeRzjZAj6EmIP07CHAmIQ4yOg14TTEETkHILN.dmbl.huIlTB3qbYnDPhmwvrZpwjI7wEeff5DxLysfrPrjRzIPXhnRFQDI+hRPPFelEql2wmLprX5zRxYCJfhLW5hhjZVATjYRpoHKMaPA7KKVTjLIiIwWLsjMedIUbsX1dzkJVsrCDMgjNUJISdiqhIB6S.exzwRJoSEWB.huvI5Y2h5TX51O9rnR7256y9G.nzY3HGDP8M469TyS9AGjO.HZxOhW6q0OYQkm+u5qyd5C3qdTBxyyO+74Xzy8uAjf29G9c4mkOOZeqOfKkGF8luQd2u+yw29MiwGSB.XoONGL51Y6JvU+c2EaamdAxwT2yP7DyWthoFlrm5HT7ZYQITHdjuzdAf+rPpL9U+085aSaXLcBO.EKBZgT4h7qABLwQ3n20uC4KA8cjixqr0sB7K0xbIJ2JxSdzhRyE+MeHP.N5QOJ2X97.8wQ+N2Ha06E34GRg2L3L75m7EXzsUhotqsxUKecuFv.UCeyd4uHZFdnJCh22fUis6TnVTcW6ScqX9b2CysycCrO74GN1+3II6PivdFcD5OaBd62MU4LLOm4rWgRkxw6+5uJGCU9J2wvb6piCbLlMQVFYzQYjs2OI9ouMo9j77+A7.G3.L5vvYNUTdoDTMFtNzMCmX9+GxU1QxA7NLCOb4+71sBuuaNXtEd5iGLzhDZjoYeacP7z+fLhxg4bepVpCA7nJam96eHT78iIR7eDeogg9F8AYwYCwyd38wf82OCNzHb3e34fA1KOUD+brCuK7z+PruWbNtYfszee.d49dtIY9m7OlgFbH9meubFVipuus0qutFVl0puPtbTj9YPuCnYYuvo4dF7ayKj8TnzeAXfALXbqBja4hzu2AYf9pkZobKSNFz3dwEJPN.uCXu5gWOVFgeUj6cvyPGjExJb28fnurcCqqvSAtxkxg2cts0UbV2oiEV3cYifob5bcGp878J+EqrBNqWLCGjvqwpC.ANSCdl7oy0Yw3fYfypmdEbLBeEy6saZ1Ubbl5qfcM.Dzp3XDd8Nxs5.PvMUe1s83XL0CMJXFz4CemVAbPyi2c5b5wAI7tnGGkodWpgqv6PwU3cn3J7NTbEdGJtBuCEWg2ghqv6PwU3cn3J7NTbEdGJtBuCk+eCfNNK8MCVhJ.....IUjSD4pPfIH" ],
					"embed" : 1,
					"id" : "obj-46",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 253.0, 134.0, 176.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 15.47.34.png"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-42",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 543.0, 212.5, 171.0, 25.0 ],
					"text" : "Look at the Max window!"
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
					"patching_rect" : [ 600.0, 150.0, 79.0, 20.0 ],
					"text" : "loadmess 10"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-38",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 624.0, 61.0, 92.0, 20.0 ],
					"text" : "loadmess 8200"
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
					"patching_rect" : [ 489.0, 61.0, 111.0, 20.0 ],
					"text" : "loadmess set 4200"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 465.0, 61.0, 20.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-33",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 125.0, 82.5, 325.0, 69.0 ],
					"text" : "If the random box in OM is put in \"mode once\", things are quite easy. In our case, the random picking has just to be performed once, and then the result should be \"statically\" repeated 10 times."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 465.0, 214.0, 69.0, 21.0 ],
					"text" : "bach.print"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-30",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 544.0, 156.0, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 581.0, 93.0, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-28",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 465.0, 93.0, 53.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 465.0, 121.0, 135.0, 21.0 ],
					"text" : "expr random($i1\\, $i2)"
				}

			}
, 			{
				"box" : 				{
					"data" : [ 4725, "png", "IBkSG0fBZn....PCIgDQRA...rG....sHX.....s4MkG....DLmPIQEBHf.B7g.YHB..RvRRDEDU3wY6c9GaabddG+CCjfkyF8hbgMbs2hRrSyRRWuzZEi4hsftKwsnNonb+wpQVhF1BZ.c9CiVkk1zvgt.LtA3I2Tzwfg.pjlQfko+XQqXlAIQaMVV.pnaLHktqL.kdvJNxdftNzITwjEkzkD9Y+wwi7H0QQRIRp6We.DLu68ku+39duuuOuOG883SDQvCWA2vlcCviAGdhsKBOw1EgmX6hvSrcQ3I1tH7DaWDdhsKhg5jLcC2vMfU22K974iqe8q2w42I1mZGcjXKhXKtvzM3D6SsCuowcQ3I1tH7DaWDczZ1shKc1yB641X29GBnBW4BKw4u3k38WAt064.7o1seC4t.m4zKv4yA68.pr+w5zzFDTh28s9u3m9t4327242i+f68NPqEXm6SlfzAXV1VNdHAPlJQNQDQxmLh.HnnJpJnk1hYql6rRz.HfhLQ.EAPhjnSRqyoC6Jlj+bRrIPf.R3oBKpffZDIqMrO01xa8ToESOi1EAPhjLuHhH4WZNIdR8NTYI9jHnFSxKhTLcLAPluZxKFVoiRqq5HqWwN2hBfLmdSO270ZO1s9T6n6WytvawCcmOBgmOIwB.knB.3eeeQ9x6eGUyzPb62c.3CySEfyk3jfRD9LUS9S+feUXgSx4Jr1oMHnR92G.9k4Kochs9afBvurbEaaepUzkh8k3D+gGj7QRxe88ov0dOvzk8qbAl8QiSfm3Kvn.jOObvaA8Us7uqaGHOkaWZC.FZruDyEVkuxssUtum3uk+pG5fP344A1cS8KaTepUzUh8YmdB9VoByK9m8InvJWfqB7QYyPgRUpmoJWfS7EtEdF0n7h+E2A.TFP4Sdq0usX66A0pebsRafPgkYw+sEHXr44uQcm7yiCoV3GSZiiBsa8oVQ2r1Q5YlrpwJJhhhRs0sCFKkHhHkylPBBBSNijyv2OUTUg.wjhUOt7RwDPURlesSqanC6JqJ+4SNk.SYX8zLRHPBW0vS6Tepsk25uRKJQUPlJkVWJWxpFsM4Lxx4xIYylQxjIqTTDo3RZoMa5bhH4zLzIvLsMstpirNEaciozpeQJt7bhBHwRWz10mZa4s9qz7ZhcRsKRohNQsQ50+SURT8t4jwlzv4CJIxVtVIsVo0wcj08VuxKyGIXCs6fQmWJZC6SsCeUKz0De970SdnAUJrBqTB7uiQYjtHsNgtsM1b9qTp.qTnDi3eG3uKZ.Vo9TaKuAoX2OYiJ1VQ50sQOei6hvSrcQ3I1tH7DaWDczi3zmOe87ehL8Z511mSrO01xqSrFu2hvJq7Q.vnidS.V6K3sGsKe06SitY1XVS1P+3EVO7TO4b.vs869..PvfC5VPuG6ReZftl8S8juAf1EkwGGFeb3EdgAYKn2iQg1p2mFXh8Jqrx5JMqL1s9z.eZbcRlT6eW5+8M.9raVMidJV89z.SrMZ3h1ECySyNgcqOMPWy9De2GniNmchS7cOrImyZ1m1D15U80ybNa8xmg9j0aDsNC70rsCOsotCe1l9zlhAZqm+S30Owp6IsdECbwtaEtAkPXGFYtQw6Ag3hvSrcQroXM9ZS8lSiOvDc5sSq23NC58kuUhMMOn0NV8CWn2eOoQe02upCqDVxowM+gKzaGwY9Ckw4NpFrfhs9T2caZcWcXud.F8JrrSiqyf3gKX0e.F8JrbhsQiwV8CW3lZN6qy5vd8.L5UX4lFGZ0CWX0maiUGl8PY5s0gUCusd4h15kETr8negkaMay37m+7sMOO8S+z7JuxqfwYFN0X61z7dnKbICG4bGI2L1BwFZTv+7e9CA.u4adJSyqYhbtomgsezGYUoenK7K5kMSKMVRCzVKzEZy3Ti8wqIj4ldlFRSWnM663Vv1I1sZzL.m5hWt1m29gue1qgiMh9MBmpEo6Tw1LMdmvgt4c0f.NN.W7xHyMO2ygueRBjD3PG8QbcBM3vDa.1+byWes4pB53UEZibnadWC3V1lONNw13Zy5BpwQwtQQVGa2Z1FMPasLVqYFGsQ8tYrchcWSSFsAq1Rc2B1BOncjibjNJeAeqeTsOma5Y3dN78y4ANEZirGE.CSiqu2a2xdssEhsQ538EaXDsQwdu.muo0scKhssw.st04Gq.LptndwKW6yFc7plaS8bWps.80dMy6Xidy6hULHxFoQei6dvVLM9oF6iWa6SGBsQsiWMsyi1Ty.0bZhN+8x0WkexcKSYaF1lQ1lsmY80f0E3jr58Q6lE2lw1r0K8or0EyjnMBesDZOZDayz3ld913YL2lAXsCayH6lI2zyTac68O27tVGkzMXaVytY19gueVwvmwaJ71hsYjs9H28dwK2fCSLxdu3kI2zy3MJuEXKFYenK7KV051q5+2FUuAnU+hT7vFMx13Vn1Kfzhmf0du3k4PW3RtVGmrVXKrFuQDNkOs6Q0250g.3l2E68hWl8Z25NCPrkhsNyVUz+JhwnGu2VsZE1Pw1i0K1l0r8XiimX6hvEJ1k3GM8I3Ue2M4Pd6l.tPwtL+zG+awO6Cpz9r5vnGJ1knPgRsL0FSqxZl21RkJTpTqEqREJfYoVof1n4sn.aY3FRgBEJPKaQkJPCAR3lN11PuHFOt77QLD2ImrVbmL8rgj.SFVlTUKMkfQkEmOlnVMuJME4Zaj7xrSNgDdl3RzPSHJJSJoxlVBoXHtXFHrjJmw5ZJITfpooDRRpW3kyHyLoZCwTyHUC4sEWddYhZmWQhkHi12oXZITfIjvSMYszhN2hxLgTqc7LIacqWDQ74ymIwxy9ye974qs5zFVrKu7rBfDMwxR4x4j4iDPfPRFQjTQCHP.Y1DKIYWtZnIVYRY9zYjLoiKJfDMUqhyv4knpZA5znwmWVbwDR1hYkDKlRxlKuTLeFI1DHDLtT1PcMShzR1LIkPfDHpVndd9PHnFVRkMujOaJID5AL1kkIAYhXKJ4KWVVZ9oD.YtLkEoXRI.HABOqrT1rRhXAqETVyjKiDOjhfZr0Lx41iFK0QzI00Ft0jdlIDHR83OcwjhJJRh7hjLhpnDIkdBRLUD0n0OtVT5s5EV86RUijTDIuDQAYpFB5zkkTyEUBFPsd76VMpjSZttDIUDUQYpDhTdIIHHQRUbU0qV3TVURVSwxKQzic1ESJpnJIqFbbKlNp.AjT5GmJh.QViYlrdh8F+Ag7qaxp1gFtwiKUt5GJy0.3ZMcL.invKmKWs0YGZq9AJV8n5KNdo+iuIJG9mwrIiwypLFj94XaJWq9SyoVcoEc5gggJWkyAreSZ5kKeMfObUmeKFySQ.+P4x.ju9w5sUSJWqJaXCzts68H.uD+muyU.pvY9WNAKv8wt1p44e0WZAXH7O5nLZ0+7Oh4WBym6C.NHG3t1CrxY4G7O8Rf5VLMu0Xj6hGK.77m7GxUJUfK8NuF+qofQ.7emeNlfT7xu16PEfqble.ecf8tK+sr3J2xTr9rguwbn88vjZl2FEkcV8LpDO8yyXCA4aJuaYavsZvL3s.s1BXSR+NN7SPPFmaYqGG.lHnJrMMwto4SLb7HbjmeN9964vrymod5+wLDLzcvykZF9iTTpk+vwSyexXCspF1vCuEfswvFqHk0nw2BtzYeGXO2I61uwK8E3LmdANeNXuGPk8OVquYaCQuZMixEyK4xkaMMXoGUSZ0S2Fn4KWTxkKmX5WqZZ46wMdiWdKlOqjdwYDzsInFYknAzrteh.Z1gDIQ1MTc0x7z0kpGcLFEfDgMtsu5hslQhHyWUeWLrlU9sZOJcRc0JbgdPayg65wWlkVJIgnwUHNWhSBJQ3yrCsi+zO3WEV3jbt9f2b8D6AD92wXru8cWLVyqymOObvaA8Uo8uqaGHeewPP6zNG5Hr1uwBMrcyZmAT9j2ZcgX66A09Ts6nDa6vKKdscXT+x9vaARMWRJ809TLBPkLIYAV8tK5E3XlF2p+xhuRoRTpTAtJvG8Q4nREMmE8INziAweTdsytBvJ7F+iOJD3w3t5C69xQLxtcur3sBuVoS8BODi+0iqcv8eKbb0Hj6zeMFceOLIi81L9ct8p4LHIxdDFoOzFbD+FzVYkU33+c+2.0mBGzdWhG5a+Y2zD6tIR9UovJrRIv+NFccIzcRc4HFY6DdYwOj+QYG8IGmoiiYMa23KK9tEGwz353ymOxkKGf0XqWCx.xZmTWNNw1J0crZhsiYZbOZONBCzrp3ymuAVTBtSpGOwtOx0u90aelZh9o6d8DaKD8a285slsEgAg6d8DaK.CpXCp2z3VP5WwFTOw1BvfxcudSiaQXP3tWOOnYgne6tWOwdMJqMC5mxg2Z1qANnwA.NhQ1ZM+5ge4MpAMRSgxYqyOsoMJNhQ1O0SNGfQOOYMJKqF1dqwMJN087z5srLyKV8pV5lO1ZwtW54oAkWr1LwQLMtN8ROO0u7h0lI1ZwtW54ImvOZw1gsdZbvbuLYl2n5rxxLuXs9JKqHda8xjxyot0KGfX6QmhsdM6NCAe9Le0JQtNNoQtsCGnXqMQkQAd7oM2yHFyiT6cVtyU7cfhslH1JA1HFyiOe2fAA2Yhs2Z7loSE5lY7oC1xo6cJ3.FYW29xVIzIOp497r47pI39ZZDtyYZcGfXqgYBstH2pQ5lkt9Hbm3T5NfsdIsTn6zoyMKuIO5K33rV2wLx1HMKdsaZ7wmNXWcygcEGmEIsRnGe5fM7mwzzSuU2T3Tv1Oxdsr9dsFsZTvMKO0W61luJmAbTirMJblMB23e5XbDsSezssejcmPqL.youFcy3nFY6wZimX6hvUH1lsVb6LPyIhiyoJsyHslo4zM9c8bphMhlsz1sLBtU33lFu4orMyAJMi91wb52L3HlFGVsyUZ01sLiV6WbvIMMtiQrAyEbn0O0KynQgF7DaKL974qqeTmFymC6xQC33D6V8HOg0dcav4+CPzQJ1vZ+CN7mDLpgibthay3.E6lo9OkXm9H21gKPr8PGG29r8n03I1tH7DaWDdhME34taebhy3Ld6JrVX4E6JkJPgRULOwREnfoAf6JTnPAL6aUoTolN+vrE.FtEQ2cSqVyKaKOcYj6s+PwzRn.AkYhOiDZBUQI3LR9xYjXSpTKLDqFNtVXFtXZITfIjvgCVKsvwWpVQkMQLQA8vWb.IdZsfS7RyFpV9Ajvylp54mT6bJphBpRrTlGLiSOaHIvjSIgBTsLTBIIyYZVsrXQD6jR.PPcRY14WTVLQZI9jHLYbImHhTbIILHSL6R0x6DSEWVJaVI8bgEPQlOaYQxLm.Jxro0TgkmKr.AkkJKRtzIjjKkUxWrnjIoVLqN9xkqU1ghmRxlIijqEAL8TQCHP.YlDokrYRJg.IPzTCrKQ8BrLOO67nRx236w9GAnxY4nGDP80467DKPwstUdOf3o+.d4uzvjGUdl+xuL6aHfu3wHLOC+jyWfwd2+cfT7l+yeG9wEKh12583REgw9X2Hu826ay230SvGRJ.X4Or.L1NYmJvU+suE1wt8CTfouuswiuP0FlZTxe5iR4qkGkHQ3g+8uC.3OMhJSb0e0f9xzFBKiXCP4xfVnlsL+JfPSdTN1c+aQwJvPG8X7hae6.+bsLWgps9hTDsnWa4e86CDhicriwMVrHvPbru4Mx18eAdlsovqGdVd0S8rL1Npvz2814pUq2qALRsvZqe9yimiinun7PasVrslR0ip0ZepeDKb6eXMMPaj6j.Agi+ObJxus8v9FaOLb9T7luclpYXAN64tBUpTf24UeINNp74t8Q41Tm.33LWp7rmwFi8rygI0O7MIyGUj+OfG7.GfwFEN6oiyymhZw7xs8wfStv+CEpZL3H9GkQGs5e96Gg.0MI1rWGQDQjhIEUTkDFsMp3RRjITZznp30Wyt94UjXIyV6qszbQZ36fZXYohhjLVcC5HvDhJHQqZLVl4mpVZSkvbqtREQUTlJYKO1Nfk223kJTfxLLa0+HZyZW5Lbea8avyl+znLbIXjQLYsnRTXkxLr+sxHCUO0JEVgBrUyGsVpDE.7OhCZjbSX4E6UQg2Bea6frXdg6sOGUZcZX+DaJwUtTA7u6czWBn3NYrghsGqWrTa8p+P86ka7MWnNtmeLCt.wViU+Ri28Mgl0be18XL+EPu6YDsNNdwVep6tMMmHtlow0wI9RiuSwwK1FMFa0uz3uolytiFG+z3PqdAz2aC8g1AbA6y1aqW53BDaOzwULMtGZ3I1tH7DaWDdhsKBOw1EgmX6hvSrcQ3I1tH7DaWD++7r58fZCnwne.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-25",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 61.0, 134.0, 184.0 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 15.43.42.png"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 465.0, 184.0, 98.0, 21.0 ],
					"text" : "bach.repeat 10"
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
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 40.0, 689.0, 21.0 ],
					"text" : "Random processes are more delicate to handle during conversion."
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
					"patching_rect" : [ 199.0, 445.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 497.5, 249.0, 20.0 ],
					"text" : "linksections 1 1 q \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 470.0, 69.0, 20.0 ],
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
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 508.5, 452.0, 257.0, 21.0 ],
					"text" : "What about the other locking modes?",
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
					"text" : "- random processes and \"mode once\""
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
					"text" : "From OpenMusic to bach (q)"
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
					"patching_rect" : [ 5.0, 577.0, 140.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 552.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 527.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-34",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 502.0, 162.0, 18.0 ],
					"text" : "From OpenMusic to bach [p]",
					"varname" : "messageA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 5.0, 477.0, 40.0, 20.0 ],
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
					"patching_rect" : [ 5.0, 452.0, 151.0, 20.0 ],
					"text" : "Back to section (p)",
					"varname" : "textbuttonA"
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
					"patching_rect" : [ 746.0, 577.0, 140.0, 20.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolB"
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
					"patching_rect" : [ 746.0, 552.0, 140.0, 20.0 ],
					"text" : "prepend load",
					"varname" : "prependB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-45",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 746.0, 527.0, 140.0, 20.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-64",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 746.0, 502.0, 160.0, 18.0 ],
					"text" : "From OpenMusic to bach [r]",
					"varname" : "messageB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-65",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 746.0, 477.0, 40.0, 20.0 ],
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
					"id" : "obj-67",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 746.0, 452.0, 151.0, 20.0 ],
					"text" : "Continue to section (r)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 523.5, 190.5, 523.5, 190.5, 465.0, 208.5, 465.0 ],
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
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
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
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-35", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-41", 0 ]
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
					"source" : [ "obj-45", 0 ]
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
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-59", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-64", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-65", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-65", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-67", 0 ]
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
				"name" : "bach.repeat.maxpat",
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
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
