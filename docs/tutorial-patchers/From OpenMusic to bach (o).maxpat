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
		"rect" : [ 110.0, 138.0, 963.0, 417.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-37",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 828.549988, 222.75, 130.0, 69.0 ],
					"text" : "Don't forget to add a wrap level for the voice, if needed"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-36",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 234.549988, 306.75, 285.0, 98.0 ],
					"text" : "bach needs as many onsets as the chords you wish. We need then to get rid of the final element, which only corresponds to the end of the score, not to a chord. We do that by slicing it out at right, and only taking the left part of the list"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 583.400024, 222.75, 78.0, 20.0 ],
					"text" : "bach.slice -1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 745.400024, 246.75, 76.0, 20.0 ],
					"text" : "bach.wrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.400024, 246.75, 76.0, 20.0 ],
					"text" : "bach.wrap 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 629.400024, 171.0, 214.0, 18.0 ],
					"text" : "1000 2000 500 500 500 250 250 1000"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.400024, 171.0, 32.5, 18.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.400024, 198.0, 65.0, 20.0 ],
					"text" : "bach.dx2x"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 664.400024, 198.0, 255.0, 18.0 ],
					"text" : "(6000 6200 6400 6500 6700 6900 7100 7200)"
				}

			}
, 			{
				"box" : 				{
					"data" : [ 9007, "png", "IBkSG0fBZn....PCIgDQRA..ATN...fuHX....vBNbg3....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wY6c+GbaUdmuG+s3FSrC3z5.gTLsWGvgaSn0Jk3llvO2UN6kRnyMh1kztCwzRnyZmo2sAmxRngKj1MvRtIbY.m1KiSXZc5kXtC0AZbtERJaSBMvPcVpBKxcpCKNTaZs8FahTQBhjwZ349GR1V1VV1RV+3H4OulwSh0Q577UVOOmu5bNeOOGaFiwfHhHhj0cdY6.PDQDQBSIkEQDQrHTRYQDQDKBkTVDQDwhPIkEQDQrHTRYQDQDKBkTVDQDwhXVI6K77NuyCcINKVA1rYiO9i+3rcXj1nwZhj6JQ29TRmT1XLZCEhkfMa1x1gPZkFqIRtqDc6SIcRYQx0jt2iy788XWDI8SIkkYLR26wY99drKhj9oB8RDQDwhHksmx9O0gY6O9wY0+fsxMTZggevf8SauYazs2OhKYIWGKqrhG5YyIO5w3c7.WwxcD0iOcVVLDy1OD82UG7NuaObFuvk+EWNUTZ5o8C1+o4Ma6sw6GcArjq6ZnrhGyet82CmpOXQkW5HeP3uKN5wdS7vExxcTEit4iyxlpsePub5NOCCF8SrnEvhKqjIsM720I4Xu96.y6JvQUKiIo4kzjXNVifbp15lKqhxGymKo6wZoqwSSw1eZzedJOdJCzFA81Ecdl.i5wJ5hVHkM+BirZl3wdS0wk96uK57cdW59Ld4Bt7uH2PEkN7x710o4LAh9cXAbQKrbhz7z0IOJu963g4cEKmpVVYSPKjYZivxL8264U1KO5y6i6ZaajJxTavyjjF8KsayV.ii5O9vOhGWMZ.LfCiS6XbVuqHKoOSCNw.1MU6ztAvTeq8MMW13MQsuOW0G9ws6v3vNF.yNNdpu8c0XcgaGGNM1AS8t7M5mvfcX1BXfcX7LbP2pwIXvtSiS6X.mlgCs3srDn8G98ez+3rAiuIoM7zZCF.icmUarCFbTuINMeF0Tsa7zn6dVc8OYi070Wmli2TcFvto0Q0MK8OVK8LdJIZ+Dr+bhLdJSzFtp2w3ZCmM3JxpYhG6MkGWFvU3kiciSGg+apicLTeHel5sy3Z+FbGtyTqM3Lb7Tcj+s9Vi8ahLQaXxz826yTuCLT2glv3YxjnaWHkjTNbm1pMsO3PORml5.C0zzHIbhHP6gSVdjHumO91ravQiFeSikMdSb66qiCYZw0P+AePSK0QJu8Gr6VL.lZZz8D7WOellpIRGSGML75n8FcZfsEYPUelsAFGM3dRWVhz99b2fAbLlNySV6GvznSLrkiD9I54HiZ.U1VxlTtSWGwzbyMaNhqNynwwzY8N9wZdL6X3MxUsI5u6WlXrV5X7TB09IU+4Da7TlnMb2fCC1qOFuGi2XuDXbYf1MM0rKyPca5rk5LfSi6.Fiw3yzfCL1GdGmh90413DLaIxGF8c7sE0qKKzFYg96C1QSS3m+SEYgjxALMWMF1VTeyc2MLlMbLB2M5zf85GNYY3Mx3z3xWxurwJds+X0dTq2TU66tAmFb1jIl8oLFiqFbXfcXb0ZCQMPzmoQGXruiQ9Fhtp2Qjj1waYIV6OzFXbMtEFm1Hxflcz5Pu68Xp29DuAlLsjIobh7MyS0wQxudG+XMiYPSec1goCWMarOlMbjIFqMVohwSI9X8Dr+bBNdJSzFgSJGikEuwdSiwkC1diQknIbBSGwHg439BI9Z03XJ9ExSOsQ1n+delc.FmM19j9dNVRzsKL8KzqPcy+x9flt8kO7C04qcHf8wRpzF1rYCa1tU18qzU3E5yGrxEN74An3O0+E.egOeMI6xFi319iJ16hlWeK3bS2DkjxZe+7ZGpEnk0wJVZj1up6mWoqf.P+uxNoxMLWbEXyrrOw.f6QdkCbVXkK9hG92+Te9UBmcfIcYIR6yfC.bLprHarzkVE2+tNH8DZxZ+AwGvU7oJZn2874+JvYGHV+0OGPv1X6anE1xQ5iC7zGf9N91nk6d6zVvrcfMIhwXMXVL+xJmxupqfKZrO+LvXsQGeonwSIR6mT8mSjwSYl1XvA.buAlqMarzptC10AOIgah3M1KYGWFhe8+m0CN+lrzhG48wwt6Jw1RWJUcG2OG7j8G44N.vR4hGtI9LrRf2evPYo1Hazee97MZtFZ4H+dxDahX5mTNv6Qq3fEeYENxiMfOnlFoiW1GAFzGtZ5xYC2354D9gAAr+4t7QJro4cY3Hx+MYW13Dm1eXg5hcdSKjs5nAdp6bwo112GTSiGme8qFf.95llV514FWydvev13abi2Ga6HOFW4f94z879.uOc60OgHbWyO2keICuZl27+TCmzNdKaJ29.Eek2Fs2dGzc2cyy2Xc7mtambYa8vSZ6CN3JVvPeFOKleYNHizCMMv+a+ZzBNv4xmO.L+uvMgCZgW6s8OIuxrrXMVKNxHi0FRJb7Thz9Ia+4DY7TlnMtxa6on8N5jt6tSZrtkyc6rR15g6IxRi2XuDcbYHN5NuIV81cRqO0cR3WYwbaOe6zQmcS2G74otk+mvYkWBGtmPQ9vXwbIi7gAkYOdq+LUaLdoy9aK3y94f88NDfzuzxkD0f.btKjxKoXJbVEyxt8+Apliwu4s8RAyFbeTWC2uIT2t3X.E.I8xRj1GfP8eBpsfEx8szlvyQqk4G40kpZ+ANKbtKrTlewERgEWJ2dcMAtO.+A+vRsami8veMt9q+54qsosBrUVx79GwseX1WDbTWcO75oy1NJXe1.weYIR6SwkxhWb4TZokR4KaM7CazIrc23eRaiig6NG5cePZ6PGClZ4FrfR1u8etkLwXMH0OdJgZ+jr+bhLdJSzFEWZ4r3xKiRKsLV1Z9NzjCX6t+SQVZ7F6kHiK6m8VaArp6ao312AXEyejkTZ4KlxKqTJsrxYMa7+ANA92+O7G4CiWktGZnQnN4UcGug9Yh1H1xT82S6RpCRdzGm7A6vTCXZpiQNgKCchyar0tMFyfl1aYKCeNdCzQSF.Sys6wXLdBWXHQN+mI6xFq309dbEd8PcMY5ziGSe80so6t6Kk19s2T0FnFSqc6yXFbhetAbWuApe3Guilp1.0Yb6YPiwW6l5h57XDukkHseGGpISKs1gwiu.FOc2poNF477LwsQ.SSUig5Z13wXL9Zu4v+8s8I5rlmYMU6FOzyymq5Gy4uKfoA6X1gqwVVfom3HoWuwXrlwXLABDvDnuiabfcyQ51mYvACWLEYhwZoiwSIR6mb8mSrwSo+1vm4HM1no0N5y3KP.SmsF98e8t7Xh+XuDXboGWgK9UpyzZ2dLd5qOS2c2swS.iwDncSiM1hoi97XBDvio0lpajyw6fsapFL00bjhWq45BuszX2YH82FlrS+8NZtZCU2rYJTlRiShtcgTRgd0jSLrkiOpk6toHWRND9xRpIWiTn9Ce45.gSdz2fS6kMVST66tgpi5wGY4CUv.ol12ioo5rOxy09VLt7L9mqO20OlJtrOSi0D0qqlFi5xaHdKap29czbci98d0MX5bvoPaL7.tv+TSCslTcPSGR3jxisP.irQg5s5Iki4XsvEPSzelFcwzjtGqktFOMUa+jt+bBLdJ82FALMG83UvTc8GejjBwar2TbbY397i+RRZGs5wXBz9nVG.l5OxHWQBib4kF4xXZht7zx.sQ1o+dlsPurE4EkvrYy1vSYgAO8yPQKZczR2CxZJMpIHif9wafPTTIkLtCEQH+dwaPn34m5V13Dm1OdRUseH+dwenYQIkjXW04981OAoPleLdcwaYS41OTH762OglUQTRwi+cwD2Fgva+dgBKNlutrkn6KNkddgNE2QAKgKtY2732VEbp8uIVxZeOZOvSyhmFuslpwwzY8Ngi0hiLxXsrY6mz8mSfwSYf1HTnf32e.lUQkv3ah3M1K0LtLTP+3eh1dYH+zu2fTXwyOFwlEqMRw8254vahKa0uGsO3SyhShoaqDc6Bojjx.bzGZorpstRb6a2YtY9DQHIRJC38j6k4U45GdYMzZeTazm.rzXbLcWuZrlHYF9O0yvbWx5XKGpadjatzI+EDCYsjxPP5uKOLqETJkXc1IJYFfjIoLPJ6almnwwze8pwZhjIDza+3IvrnzRKIoWGYwjxhjcjzIkyRwgUY8Jhj9knieSg25FCxoa6M4s61KWvkrDtlkUFg5uK57ri8J6p.trEUNgu2Ljtu4S.DpeN4wcQeTBWYEKkxmez6Zwzu8G2jrdA.bQrnxm+H+wMXOzVmPEKdLG9iTvDYeba+P9oqN5j2smtw6GUBewqaET5TsMh0xB0C6cqOJ9VYsrw0r3XGPVXgmHYRe2dE0stQQjosjpbxLiohxhpB.c5z9vSkbwtxLGZRDO8eymv3wkoZv.NMU6jDnMlpsuuvy8ri683P2jIBX5qy1MMUWzO1PAcpXhrO9suq5CG61ibSo.bL0Zi3rr9ZM7jy+g51pT60ompd1iGOFOd7XLlONxOYOoi2ehHYFI532TPR4AMGptvkQ9jM2312Qh55UNCbymXnID9ti76GYKL7WXH009i1Q1BibMt4q0QRT5bzyqsopIx9309cbnlipz96zrEv3bJzFwu8Gzzb0idN8MaKUmz5d+duf4d+dufY261X18tMlrcRYa1rEyK0D8i9Q+X8+wlMaIz38oeRYetLNYpLQRzgoNvTcycXLlLwMehvSd+NpejjYAhZhOOcLg7OXmgu38GYxcvmoyN5v3pksLlqG4T2DYe7a+Q+2iFG9tzxzq8CeWbYpcC+HSX39ho.QmP9286B+S3DyhjJE9HvLxQjQjvl1Syl9670oEf0ujUL74raS69UF2zu5odleHOA0wCeakG9AR627IJjE7Yfi85swPynwE9ouJFdJUMkOg7Gje9CrVntV3qW9Pm25horxKmq5xG+bdaJaxxOts+HB00KyieLXS2zUNsa+4eM2N0v93jcM1Okys40q2jZYhjL178bH19C+ao4lKg8rmrczHVEof495A.pgi24ul.CFftc0DOwFtQ10IiZiXAOIe+0sO1xQtWJKxCkIt4Sr7ZODN225Xt1rQUUsTrMuaD2L2Ta6Gg+19Yrt8AG59Wy3pdtXkLOkcymXJz9g54nbSKb0b402J24hKd529y5RXY1gS+dYhom8rGWtB+SGu0KlsCEIOylumCA.K5ydKTYkPkUhkJwbHumhCe3Wg9yulN3yIL8SJGIiSokMeJbVERoK6qSSNg1dGOC+TNwt9GoE1AappQp93LwMehBK6l4.l.zcmcx9dtWk1aoNfqhOSwo5InbuzX0a.6633bySw4ehT1jk+jz98ex8RAW1pXoM4lCrwUjlZ+7CkTxHWKhc7Vu3v+L1kIxzQtvQjw8S+cX0q9Fogea+S9SVRsR1i68vuz.tMUClparUS.iw3YrSJ58cDCL94U3LwMeBiYPim97XBLX.SmtZxXGLa4PcmRa+vuE2lgwbC2NrAMABLno6iuCCrMSmABXhL2omxlr7iW66Jx7+ccM4x3wmGSec2so697M8a+Aa2TCXZNlm65LuoQ23XZnyq7P+jsKzKI+hGOdFWwDt6cGtem037K2ooNrapoNGI8MgAI4kRtjn73toHWxMLbRfvFLb0.WcSwrHkR227ILFOl5iJt1VKiNwVpo8CWUyU2XLpN5HEAGQ8yHe4jT0MehIp8mfKWpgKfsju88jGWnWCs9rRWRTR9lOdbewuQ9BfYe9bsCCNZxDHfKicbXN9T4xNQRYRoSyld8NQSl5Srz8MehvS.5PwkTbLmoTxDSH+wSp5lOQlq86h621B4O0T67z2t0XBDIUOiWoYPKI8JbeqgNuxCYmO1sjMBlwHDGr1Bv4bZl1qcd73KYUPKcxtWSYS9KURIzzroj.7yybGyk0susQ2lGjja5YO0SIkkbKC02x1vmCYKSMK3+DbqyckP0UC9gh8sO1GMfuiVK5deRlgRJKIffzSWdnHK1MBAkTVxEYE6m009qkEtu+JLG31C+.AOIUUTkTWBbqBUldTRYImW5HobplFqHik0aan9Y2UMW55A5iGopgtLNBx9uihXeWuaNPsUjUitYJTRYImmUuuXxFe5FbQ9Oqb+VI6PGOBQrvzFsyeouzkDKofYzKQDQDIUHo2S4z88lVQlpT+PQj7EI84TVltL306eA.JojOIfRrjeI7vpQ9LNwtjWF4Rk4SF4QT+i7MV8ZgPxNz4TNKI5Ijd.polrYzHoCI6mwa9ddww75zFtEYlBcNkyBhditVw6PLxzWxdW.J18MzdIKxLEJobFVtvcHFY5IY+LV8MDQzguNKykqv+a3aQfWSVMVjzij8yX02PjYdTR4LrwdO6chVlj6JY+LV8MDQzguNKHV2MXrF2gXjTkc9XqNFO1j+Ybr6aL90kHR9IcIQkEM5K6EULO4WzkDkDe5RhRhEkTNKQCHEYlMsM.IVz4TVDKIC1rM5ytj1.tH4+TRYQ.B48Tb7SzIeD.7Qv4+o45pZYYvar6gS3N1DwCuTkPVjYDTgdIBPf+3KwpV8p4W85t40e8VogMUIy8N1K9yFAytMi7iHxLJ5bJmknymj0h+StKl65mMl2r1vOPO6GaWVKz9fOMKNsb7jF4y9IZuiY2FnVaXLeLpPux+nsAHwhN70h.PAyFbuA1z82EEQ.Zc6OA121QRSIjigwtWw0pjvhLSjRJKxvbxxW4MxExGQYa68XCacWbh+gpXEoj4si3eNiGUR3gRPqDyhLiiRJKB.CN.Xe070VyMSg.rlaA1eA7R+6dYEolrxiHdmq3nRDG9vVKhLShRJKB.E.3tONSvPr.Bg+29WxS5FtuKtnjbEFmyY7DsGvpvtDYFOkTVD.X1.akEVzVG9Q1Vyt41KuvTypexR3pCUsHBJorH.PwUTKFSsoj0kMawHAq16XQjo.kTVjzgoRx1IJQs1qYQlwRIkEwhQWWxhLyklQuDQDQrHTRYQDQDKBc3qEwpHKdtjiYwoIhjwojxhXQjsmrPz7vrHYe5vWKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnB8RjrIM6cIhDEkTNKRWFJYVVwpKdjJtV8EDQTR4rFqXBh7Y5K.IhjKvlQYGjY.rYyVF6KBkHeA.qxdJmI+6iHxDS6orHoXJ4lHRxRUesHhHhEgRJKhHhXQnjxhLMDpmixCsyCSvrcfHhjWPIkEYZHv+wuisdetIP1NPDQxKnjxhjTBg+f.ETHPgIUES5us8y8uqCS+Z2rEQhPIkEIA0+IdFpxVAL2hrwbse2fiYC3m8uop3VenQNT1mbuahkV6do+IX8T.e.a+tWMWRQ13928gomwjb1+odFpx1sxAOcjE38DrokVE69jSzZTDIWmRJKRhn+Cykrx0giVbiu.9vcy0Amc.fh41t++I7s0Uye+yzFc8JODUt92jG+gql4OAqpBq3NIfmN4HMsCZcCqlKanjy9Cu7hW7sy1q2GNWzcSa8eZ147VIGcc+ST6xln0nHRtNM4gHyHjplbLN89uCVzCc8D3MqkBAB11tnH6fOyFoXffmd+TzhVKfcZoiSvZJuPH3I4VKpRZIx5vQ8t3nabYiacepC9PrDmaEvAtBbTVVg.DjCtoUfymvMTWKD3wWCENseWLdZxCQDqAM4gHRB3bms6Q86ypfYCLvv+dgycdXGvMv4OqHCuJzNOsGODZnWSQEG0ZHHm9DuD+3s6jmnEntczD2U0+2nhgy7VHW37B++rWz4qArhjmSG9ZQR.W4ey2Db+r7RmpeB5uGdwleVv9rCuvfmhZujUwJa1Es1ncV8BWOs4GfYQwkTBkD4mhKLbp0fmd+XyVQrnU9SYw2kK7LngGey2NUT5HIsO0yTKqZqUgqNZE6ae0r981Vl+MsHRFi9h2hj.Jr7+NNxNN.qZIWxHOniuAfW16e2RXO00BAtskQg7jz3QlK1cd834n0RIwZkUzUvwc2M2PEkFy1xea6kkrt8PycDfkUdg7jtaj4Z2NKeIdXiqHlqQQjbb5bJKyHjpOmoA85k.ypXJo37iuWqNmxhXMnjxxLBJoS7o+9Hh0fNmxhHhHVDJorHYA1rYKgtuKKhLyP9wIDSjbLCcnh850K.TRIpvsDQTRYQxZ1787h.vh9r2B.TSMYynQDwJPG9ZQxBhNgbkUBUVIrm8jkCJQjrNkTVjLrgNj0I5xDQx+oCesHYYtbE9e63sdQfqIqFKhHYW55TVRQFoajWu+E.njR9jQs7LckFa8ims+vu13hmc9X2RVKdrZ+8QwihmYhTRYIEIb2nMeOGBH5hWZntWYmMZX0imNdqWX33IykPdhiGq1eeT7n3YlFkTVRQLiZ.ZkUF9Qc4ZnApY9MZjqDOqcsdnjRlmkIdrZ+8QwihmYRTgdIoDCcHrRzkktjKEOYiMfkK82GEOJdlIQE5kjVX0JdIEOwmhm3SwS7Y0hmbYJorjRDcQdDdfYrWVlhhm3SwS7o3I9rZwS9Dc3qkTlc9XqdJ8XYJJdhOEOwmhm3ypEO4KTgdkm37NuyS258DQlwxlMa7we7GmsCioMc3qySXLFkTVDYFq7k65Z5vWKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHIsyctyksCg7JJo7LR94U16t3g10AomPY6XQDIWkWudYdyad30q2rcnj2XVY6.Px7Za2eGtwMrO.v0rcyApshrbDIhjKJXvfLv.CPvfAy1gRdCsmxyz3+D7fQRHCPKa3Gyoz3IQjHzgiN6RIkmg4TO2OlV..mrscrEf8vK8GzgdRDQGNZq.c3qmQwOm7Hg2K4sbnmjG7lKkahWfZd0+HabYkjkiMQjrMc3ny9zdJOiRHdutAXKT6MWJ.LmBuHH3fY0nRDI8QGN5bKJo7LIAOC+wiANp+1nrHOzf.tOb63OaFWhHoE5vQm6QG957H81auw+I7guK+q.WW4yIxy8Oydu6iA27Z3L81KePlHHEQFkyctywblybRKq6yblyv.CL.c0UWSoCI8YNyYF0+lpe9xjylwXLY6fPl9rYyV1NDDQjrp7gzYZOkyi7FuwavBVvBhyy3C4YusqjO3+46x2tjWgUUw5ncfpepWic9UVXFJJEI2R5dOYu5q9pmBicyLq+z8yOcpzRKMq19oJJobdjErfEvkdoWZbeNq5aVMO3g9+xas86i1A.GrdmWCW57yDQnH4V750KW9ke4zau8RIkj9tBElJicyjq+z8yWlXJo7LMC3lV19HSdH121CPUJgrHwjtDgjLMkTNOxjUrEm8D+Dre2ti5QtYdj0tjIu.wDwBKce3ki9ey2W+SsmeH9vO7Cg+SW.ev6e1DZ8KSNUnW4ITgdIhLSW9P5Lsmx4Qlvhs3rmfaqhuJuVTOzRdnivQ91KIiEahjNX0JTpby0+n2y2I5421y9c4KuomaLu1uHvuSE5UJjRJmGI1EaQ+ry0EcBYGTS0mk4r3xTgYjhjNO7oxTiUqPoxUV+m5v6huypuaNVjeu5s87w94GrM173RHCvEE20uj3zL5UdtSt6uG22wF42apiixt2w8wQ+Wd6rWPkGQyXRh0SH762K9CF+aV5mbu2AKIpDx.rus9+J1O4AGL1y5eW0eMm+rmMEVXgIavJig1S47HisXKB1wufJi51z389yaCGy4eie1O4kw8ddJtte+0B.Ww0sVp4t9aYQehrS2gb48zLQmwjjTKqVgRksW+cbreBe+08fCejw9Za9mD60ev14QV+9X7N+I34+WhQxhp4W8beKJuf0RvfAUAilhnB8JOgJzKQjY5xGRmo8TNOxnJ1hPcx1+Oes7i.fp43u8F4+2U9k3QGyqYIPjIQD.tV9EsueVwmHyDuf0ZFAJYjqG+45rFEJUhZpUXUIjfsy28JVEi+r99WC7xie8Gyme07qZemTdA4lG4JUnWhkynJ1B+8x6F4wqokGlufuV3FA.GzRGOGe5ma8r+u3SwiTUwbhmYarx0scfWiccvN3na9FxtwdNnb83OWWtRgXMkKrpDk+dIlmA4q5Ky4e5eKkUVYiYFI6RowNak+qO6KQeCLaJe4+Mr5adYn6p5YeJob9pBfhA.67Mtgxn6e9QAflZuEVS4Ei2qoRdgCcJdjptAVws+Hzw4GfEs1mfic32.ua9FzfSQRwN4duCpbLmG2IrvpRTETPjw6QqFb8peeV7r2XL2y2hKaET6lWQpo8kTFkTNOxnJNiO7838.fqDB1K8+98C7.rrOwGPu89APIkyfG32PGe2EwE.Lmq6awCrjmfGdffb1d6kLUIKkqeqeKWO9y0kd96eZXFqJQKrpD1EyO3e8WREG72v6MvrYgegafpbTAehf8x6GDd+2+8mlqeISQE5UdBUnWhHyzkOjNS6obdjwVLG+4W5GvW5NeJt168Wv92zBXykds7Y+ksw2dYWDPPd165qv4u0Wfu5BKD3Oy1K8KwO5lebd6e52fKHCEy45EJUtd7maJMTnTjlmwpxCKrJqFUnWhkyXKVjK8a8OS8+rmh69Q+p7ippSdZOGmplWEbtVbyirlJXUq9SwO88uPtzKc9bx89C4GArk68qyhxBErTtdgRkqG+4JRaEJUZeFqREVkL0njx40lOarE27Gmqc19pWHmsgiyy5oS9MO0ivs9leUp+qbqbzG+4Y+teUV68sOntlYKUke7sMSuBge+9gBFeo0HoOo0BkJdyXUm9kSIyXUpvpjoBkTNORrKVjKlM+tuAW4itE9uugaj8rA3u+de.pX1uHanxeDtAVKv28+8ujM8UWFePu8xGjEh4bkBkZJOiIIoVo6BkRyXUhEgJzq7DpPuDQloKeHcl1S47H8zSOI3qHDO6cUCWxi9SwwEkVBoIrcSGEpSZUhNiIIoVpPojIgJzKwxYxKDkf32+fTPQESgQ9j+FcLadgOrPt8OelojSRaEpS5VBOiIIoVpPojYV5V5nw..f.ZmDQAQEzguNOgMa1h6gtwaa6m+V6qMRxP6zPqGhZWQo38UdHV+a7U3.abYo8XLVEpCbs.uF8zSOV6jxAai6nH6L5nuFb4Y2r3Yq8TSjrsIaaf4JzdJOifeZ4AWaT22TcyFpYe70eyMSwkVNbn9RqstGOdXf2+ei+4oXg5TXgEZ81qyBqfmryV45i4dpoDxhHoFJo7LAg7Pe9Fyi4tW7DBJYdyC9SdHHP531T94N24nzRKkAFXfI3Y7x.vUe0W8vOxrm8rwiGOVt89TWRKhHoamW1N.jLfYMOF9twnc6g+259xT9rfi9nql+3xqHsjPFf4Lm4Pu81K87NGgu13VZ0b3+POzQGcPO8zyv+zau8Z4RHKhHYB5bJmmXROmxmb2LuJ2P3ewY8z9S5je+OdMr1suRbGX2TQ5JqbT720I3YTg5HhjFjubNkUR47DSkNjda6frsG7A4IZwM.3bKMR8a8NorLPBYQDIcRIkEKk7kNjhHRxHeYaf5bJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVD5FRQdBa1rgMa1x1ggHhjUjur8OMidIoHizMxq2+B.TRIexnVdld.ihGEOJdl4DO4OzdJKoTa9dND.rnO6s..0TS1867o3I9T7DeJdhOqV7jOPmSYIkI5AnUVITYkvd1S16aLq3QwihmYNwS9BkTVRIF5PXknKKcQwS7o3I9T7DeVs3IehN70RZgKWg+2NdqWD3ZxpwBn3Yxn3I9T7DeVs3IWlRJKoDQWjGgGXF6kkon3I9T7DeJdhOqV7jOQG9ZIkYmO1pmROVlhhm3SwS7o3I9rZwS9BcIQIoHVsKQBEOJdT7LyIdxenjxhHhHVD5vWKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQnjxhHhHVDJorHhHhEgRJKhHhXQ7+20tAj4IO8VX.....PRE4DQtJDXBB" ],
					"embed" : 1,
					"id" : "obj-21",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 119.0, 486.0, 181.5 ],
					"pic" : "Macintosh HD:/Users/danieleghisi/Desktop/Screen shot 2014-01-20 at 16.10.40.png"
				}

			}
, 			{
				"box" : 				{
					"bubblepoint" : 1.0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-65",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 42.0, 909.0, 36.0 ],
					"text" : "If you know how to build a CHORD-SEQ, it is not that hard to build a bach.roll. Once you've input all the parameters you need, just remember that you need to send a bang in the left inlet to rebuild it. That's more or less what we have been doing in all the previous sections! Yet, there are a few caveats."
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 533.028564, 118.0, 92.0, 25.0 ],
					"text" : "Click to go!"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 502.0, 94.0, 174.0, 21.0 ],
					"text" : "bach translation"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 502.0, 117.0, 29.0, 29.0 ]
				}

			}
, 			{
				"box" : 				{
					"additionalstartpad" : 22.0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-53",
					"loop" : [ 0.0, 0.0 ],
					"maxclass" : "bach.roll",
					"numinlets" : 6,
					"numoutlets" : 8,
					"numvoices" : 1,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 502.400024, 273.0, 424.0, 96.5 ],
					"pitcheditrange" : "null",
					"showdurations" : 0,
					"stafflines" : 5,
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 7300,
					"voicenames" : [ "(", ")" ],
					"voicespacing" : -8.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "amplitude envelope", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "ysnap", "(", ")", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 7, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 8, "(", "name", "filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", ")", "(", 9, "(", "name", "spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "width", "temporal", ")", "(", "height", "auto", ")", ")", "(", 10, "(", "name", "slot 10", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 20, "(", "name", "slot 20", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 21, "(", "name", "slot 21", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 22, "(", "name", "slot 22", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 23, "(", "name", "slot 23", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", ")", ")", "(", "commands", "(", 1, "note", "chord", 0, ")", "(", 2, "note", "chord", 0, ")", "(", 3, "note", "chord", 0, ")", "(", 4, "note", "chord", 0, ")", "(", 5, "note", "chord", 0, ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, ")", "(", 0, ")" ],
					"whole_roll_data_count" : [ 1 ],
					"zoom" : 38.154297
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"frgb" : 0.0,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2.0, 94.0, 146.0, 21.0 ],
					"text" : "OpenMusic tutorial 22"
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
					"patching_rect" : [ 199.0, 391.0, 81.0, 18.0 ],
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
					"patching_rect" : [ 199.0, 443.5, 250.0, 20.0 ],
					"text" : "linksections 1 1 o \"From OpenMusic to bach\""
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
					"patching_rect" : [ 199.0, 416.0, 69.0, 20.0 ],
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
					"patching_rect" : [ 577.5, 389.5, 208.0, 21.0 ],
					"text" : "And what about voices and polys?",
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
					"text" : "-  building a bach.roll"
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
					"text" : "From OpenMusic to bach (o)"
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
					"patching_rect" : [ 5.0, 517.0, 140.0, 18.0 ],
					"text" : "pcontrol",
					"varname" : "pcontrolA"
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
					"patching_rect" : [ 5.0, 492.0, 140.0, 18.0 ],
					"text" : "prepend load",
					"varname" : "prependA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-34",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 467.0, 140.0, 18.0 ],
					"text" : "tosymbol",
					"varname" : "tosymbolA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-38",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 5.0, 442.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (n)",
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
					"patching_rect" : [ 5.0, 417.0, 40.0, 18.0 ],
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
					"patching_rect" : [ 5.0, 392.0, 151.0, 20.0 ],
					"text" : "Back to section (n)",
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
					"patching_rect" : [ 808.0, 517.0, 140.0, 18.0 ],
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
					"patching_rect" : [ 808.0, 492.0, 140.0, 18.0 ],
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
					"patching_rect" : [ 808.0, 467.0, 140.0, 18.0 ],
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
					"patching_rect" : [ 808.0, 442.0, 140.0, 18.0 ],
					"text" : "From OpenMusic to bach (p)",
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
					"patching_rect" : [ 808.0, 417.0, 40.0, 18.0 ],
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
					"patching_rect" : [ 808.0, 392.0, 151.0, 20.0 ],
					"text" : "Continue to section (p)",
					"varname" : "textbuttonB"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 208.5, 469.5, 190.5, 469.5, 190.5, 411.0, 208.5, 411.0 ],
					"source" : [ "obj-198", 0 ]
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
					"destination" : [ "obj-53", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
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
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 3 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-33", 0 ]
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
					"destination" : [ "obj-34", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-38", 0 ]
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
					"destination" : [ "obj-38", 0 ],
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
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 511.5, 151.875, 673.900024, 151.875 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-71", 0 ]
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
				"name" : "bach.dx2x.maxpat",
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
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
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
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
 ]
	}

}
