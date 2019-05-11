#usage sh addpatreonbutton.sh <helpdirectory>
#beware: will substitute files in-place!

#input: is it a file or a directory?
input=$1
if [[ -d $input ]]; then
    path="$input"/bach.*.maxhelp
elif [[ -f $input ]]; then
    path="$input"
else
    echo "$input is not valid"
    exit 1
fi


for file in $path; do

echo "Processing file $file..."

#canvas size
size=$(jq .patcher.rect[2] "$file" )

#Patreon button size + right pad
patreonbuttonsizepad=148 #138 + 10 pad

#needed x position for Patreon button
xpos=$(echo "$(($size-$patreonbuttonsizepad))")

#retrieve position of the basic tab in help file
basictabidx=$(jq '[ .patcher.boxes[] | .box.varname == "basic_tab" ] | index(true)' "$file" )

jq --arg xpos "$xpos" --arg basictabidx "$basictabidx" '.patcher.boxes[$basictabidx | tonumber].box.patcher.boxes |= 
[ 		{
			"box" : 			{
				"maxclass" : "bach.hypercomment",
				"varname" : "becomeapatronclick",
				"text" : "                  ",
				"fontsize" : 27.0,
				"numoutlets" : 1,
				"fontname" : "Arial",
				"hyperlinkcolor" : [ 0.341176470588235, 0.450980392156863, 0.16078431372549, 0.0 ],
				"outlettype" : [ "" ],
				"linkend" : [ ":,;()[]{}" ],
				"fontface" : 0,
				"patching_rect" : [ $xpos, 11.0, 145.0, 37.0 ],
				"linkstart" : [ " " ],
				"id" : "obj-912561374",
				"numinlets" : 1
			}

		}
, 		{
			"box" : 			{
				"maxclass" : "fpic",
				"varname" : "becomeapatronimg",
				"numoutlets" : 1,
				"outlettype" : [ "jit_matrix" ],
				"embed" : 1,
				"patching_rect" : [ $xpos, 10.451373331265277, 137.607843137254918, 32.341013824884797 ],
				"forceaspect" : 1,
				"pic" : "/Users/danieleghisi/Downloads/become_a_patron_button@2x.png",
				"id" : "obj-912561375",
				"numinlets" : 1,
				"autofit" : 1,
				"data" : [ 5753, "png", "IBkSG0fBZn....PCIgDQRA..AHK...fYHX....fqqRQj....DLmPIQEBHf.B7g.YHB..V.SRDEDU3wY6cmGkUTcmG.+6sp58ZPV5lktAYoYeeuQj8EUTAlfhQLBYvnwbFmnmIS1lwjSzIS7Ldlw3jSRNmLIyjMSF2ih3NhJBBJRDYqoaZPnk8kdCZfdA5tp5dm+3Ac20qp2V2ush46mygywtdUcq68Y8peUcu25WIt3CtREHhHh7ozxzU.hHhnNBFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMFHiHhHeMiLcEneasVnfvyO6HSOOjShFp0v.hQNVnOghfnu8GhbyChtkKvkZDxyeNnNS0PVVwPV5t.ZngNdCfHhnLpLdfrFsA.Td9YJn.hPPNWtlt.ia81f9bWHDcpyt+7tzUn2qB.F5HAl1rgRZC4d1ILe8+BPkmp8V8IhHJCKiGHKYPadKDAts6FhqoKw81Hzzg9jmFzlXQvdKa.Vq94.LaNEVKIhHJUveGHyv.Fq7a.iYN+1cQHzzgwbuYHFzvg4+yOC3b0lDqfDQDkp4emrGZ5HvC8vcnfXskdgCA47CdbfdzyjR4QDQT5guMPlwJtOnO5wmTKSQt8.A9l+S.AyIoVtDQDk53K6ZQsoOGXLmaJkT15CbvPc22KrdleWJo7upkgAP2yCht1c.kMTUUAPSMkbJacCfbyMTYqqCU80Abgyk7Jehxlwi+iI+Wfr.AQfaeEozcg9LlOr235f5DGKkteZKsaZIPezSH1qnRB04NKj0TEP0UB49KA3hWz60s64h.2y2rcWmr1z6BUo6NxqfP.sYs.nOkoCsQLFHBDvYU870BYUUB6suEH2xFAjxDZ+qMy4A8hlQnxNr6RVIkPdrCC6R1IjaXsw9G0w36BqM9NPU1dhZQHlXQvXt2bD+by+xSATS0w89LVh42+wIwDlBLl2s39Crsg4e3WBXY0g2GIRaUU+EfrxSCT4of7vGLtGW5DscHF3ffwskbNWg0ZeEnNb4IV6rtyAYMUCTcEPcpS.0ISrymjVN921Fl+4eMvkhv4P.fXhSEFycgN2rsuEH+zONtaKoZ9t.YZ23hfHuT63XIDBXbGeUX9qdhT59osz5+.g93lTBucpFpGlu+aA4FWm6YcYffsqx7JrKYGQ3Ai..8NeD3deHnOrQEwsWjaOfdt8.5iXzPcSKAM+ZuHT69yh8Nt24i.q5uG5ibrQtr0zf9fGFzG7vfZ1K.M+z+VnNPYQtLiw2EpK1.rhQfLiYL+nVFV4zYmeekJ+9OAXbCKNhcCu03mLT6d6c7cR6rspLMg8FeGXstWOpmLEnczN5R25Pe+6n7+n2Oz+QG3+mZW5tf0q97Pc5SF8ULMe7uZQ2NrdsWLx6qdkuqsUcru.I1kklZ46Fir.IoI2QrnM5I.jWORK6qNBQW5JBtrUf.Ov2MssO0l0BPN+nmHpAwBmnfqE47.eWncKKM5k8bWHx4Q9oQ8GwtJ6dlOB9seDXb22W6d7M0G2j.zzixJX.sj7XxlVjWOfVT9tzX5yKMVYbSDH.LtkaC47X+bfdmejWwr71Q7Pe7SAAejm.ZW2rh35jIN9W+FVLPuhx289.9p.Yhqs+PTv0ld1WBAzl3TSK6qjA8wMInsvuTJe+nMi4gfq5A79gNOND31taHFyD8tru9Yifq79gHmNEwsWo79dTDBALl+s.iuxWqcUuDctKPL7nb2kCajs61blj1zlMDZQ9m4ZiaR.cI9e9KSUDcKWD39+VQ7hI7KsiXQnoi.q7q64riNSc7uHP.DXYqLg2trI9ptVTL1jS2DDuzG6jfbyqOstOaK6idHX9a9ostfb5DDEzOXbKK0yqXyXVyGMu92Jlkayu9KB0wNbLWOUEgkwS5TmPfk48XNXev8A6suUnNzA.fBhALHDXw2gqK7PnogfeiuEZ5w9d.0UWaJ6Ni.e4+VuK6R1Ir1xFg5HkCzzkfXPCC5SXJP+FWBDBmY9E8Yt.XukMFZ7LRP5SrHXEgtmwUWqnTt12wq182+sC5SetNKypqDh76SK+svH.zJZlP9Qoliya94+CPc3Cd4cl.nG8B5ibrPed2hqwTUevCG1KbIP9duoqxo8zNT0VCr1v63Y8ReBE4X6uRYZWxN8tgTcUQrMB.z7u+WBY466J0FH5d2gneEBiEsLncsCvw5J5bWfwxVIr9S+5VWXF93e8oNCXsg01t9cS1.eUfLsd06z6Nrmo48W3rsbdx95pCpZpFle9dA9gONz6egNVcQAWantVn4nOvupidHn1eoIb0wXIeYH5ddtVt0GsdX8h+Y.Uq8Zt5jGGMsysg.eyuGzC6NvDWSWf1DlJjexG1ZY+kVt2k86+lg5+91bknpCTFrNPYPd3xQf68AgHPvVKag.Fq39g4S7nNpOdQVwIgVe6eK+s9DJBVq9Y8bc0F+Tb72pJNIDgcBp3U686+DkX.EB89MPGKy7utYD3FWLDcoqsrL8oO2TVfLUMUA0IOdqK3DGCVkrKXWxtPvu8i39DwiZbtBj0taGUVArV8y3Y8RzydC8vBjIO0wi35GKpK1nieqpp6BPcxSfl26tQNO5S5Zb80GxvQamZJYhi+Cmwx+Zv7+7GmPaS1B+UWKla58gUVKacLxrsfZu6x0hEZZ.cJxcKQGRA8A52vhbWU1eov5EdJu+QiYyv7Y+8P0zkb8Q5SnnV+i9zOnu.2yFM68UBrd0WvwOhaK4N+TXttW2cYOvACsYufH2VtLUENGzcQ98EnO8y8J1q7cbU0plaBpyVSLK+LsvuKF..09KExC57tN0G5H.B6j5oZpCTFjGbetVt1.GhqkkM2NhoFaD1E6wDbpWE.jykGOqLzw+t1tgLbnccyLg2trA9p.YorSRGI4jEOlHdzO5pFa.3BmOkr6zF0DfP28Mva89wnqLq8LP5wcenMxwzx3gnMkqGBOFaDKO5hovI276CkG2ApdQyHlaq8wOJTgMS4zlXQtVOsv5Ra4A1WzmXHYCDZPOrIUf5BmGpiTNrK18rTT+5mS5pl0Z8opS6ZYht1Mm+N2GzNhEU806ZYBg.nKcC.Yti+kUbRnpy44KBrrU.XDHBaQ1KeUfL04Sy4AwKbtz69Kd0ydA8o49Gr1a98RY6Rs95dR1nNSUPsunOk0A.r2y1C0O+q60PyO0uBM8u8vnoG9AAj1..dNdepZpDpOON59sFpG16ZatquCajgdHsiZEyFxxJ1whz8XB9nO9I6byJcWgFumrXhQOdHx0YOJXW7mAnTPVxNgx14ybkw0O6zY0C..hd3tq6UmuVfK05cv6GZGwh1.FjqkorsAN2YAPl63ekoILCaLDE8LencSKN162rL9pwHKcmPeko6.mgQqacGZssaUxoSPqu8C5yXdtlAc1G5.w0UvA.XbiKFpob8QekZnNX8FubK+onutGOHYbNYDjacyPt0MGwOWqedT1UVQbU1..xpbuth.ACMkhqz8U82V16YmNt5UsgLBftzUfFt7UQaD.ZiZbN2eksanO4oE20uv0d99OQoOcOtPmcd4S30XiPt+Rg93ZM.sH+9BwPFQqSLiTLQ+GHzFk6SfKOwQc72Y6siXQL9I64reVdzC0RBBHic7ul.xM8dPcyK0waNj.25sil9jODntKD20gLMeUfLYB9jw2QoN4Qi8JkBIxuuH389fQccTMTenWCMu8Zh6WCM5gMwE7rbOS0NNQpVecO1QIswI5xcwhyxtZOVwHHBqqnqcCpXDHSVVwPIksL0tEZZPabSFxsEJqEHBKqJHq3jNydGsCsmu+SH4jiq.sp5qCp1LlR167ScD...PeFyAVI6..F5s1UUBAPO6IzF43Qf+l6DBO5BK611MzYSsiXPehEAY98MzeH.zxMOHJbntpaWg06+Fs9GYri+E.W5Rv7cdUD7NWUqKsScFFK8tf0y+Gi+5PFl+JP1dKFJaKOGqlTA6cuizx9oiPdhi54UjkTYD.hdzK266ymD550bxABc2iOPhT1pyEg0Mdd+zUecPd3C53g6VehE0RfL8wG13is2NdJiJUSaxSyUJMxt3s6HEgI2yNfx11w285EMSX8ROSnYKaRRNOzOHtWW6Cc.H2v5Z4uylZGwhwBbOQnhDqstInJ9xmaISe7O.je36A0buIGOpL5y5Ff8FeWnN8Ih65QljuZLxvktnmSbfTA0EaH5o7krD5iZbH3pd.D3gerT2L1xxz0jh..PKAdQlFQMa54C4YhT1hH8fvFmIUU6837BVzF6jBknVAbcE01IgbeXpltGY4B6c8oNWPC0CYXGeK5RWgX7o2mUyqPU24g4e5W6X1u5GaGQixxDVevaCqmsMIj7rfi+gsEZNrG6.glFLV9phvFj8wWcGY..Vq60i3sqmLYt90lVuhNuXexi5LK7ekGnzwOYnOi46HSGn2+AA728cf4+wOJhSW2qv58dCHOUzuRKUSNCbIqpBnWnyoFsHYjVaTRfFq2U2qHRjmguHstMTm2KOLx8rSf63q159tScFhgOZnNa0NtJUUSWBpx+73udEAsmu+iadjJmTM2DTUWIPX2Usc46G5iwYhp1X5yClEm95IBkkIr235f05dMmI+ZeV6HVTW3bnom7eA3rmIrOHye7O.fpzcC6x1CzGaqOym5iYhvZLwQhLOKfuKPl5K9bXW71g9jttT29370B4Gr1TV4G2ZpI2Y.hidHXs6OCxSbLD7qbuN9H8ALHXO0Y.412ZTKV68WZB+.4pp5z.gEHC8tf3aiKnOPqvgB4Q9BfZbmgDjmoFnG93Dj.AI073GxJkJ9GCuJOkqLEg9XFOjgkMGj6uzjxE2zd99OdocctSkShf4fN8X+h3a6G+jC0kTM1PRo9Xehi.zPaJKkBpKTanIyPUmFxCcPfZOiqsKaqcDKM+luTK+VUT3PQvkdWN9bQ2yChdU.TgGHCYAG+eYlu7SCsG8m5nqNMV5cA6sk8jk6iDeWfL..yU+LPaXiJzybRRlRoPyuveLlYGiLM4GuAntyU4p+00F7viYfr1CuFzX89WHrF3fg53GIpaqwzmGLV7cDpbp+BPd3xg8QJGxO7cAt3Eg5.60UPRsALHf9zWfXM6szz87hZjm3nQ90aiGrKYGv3FWRK+snvgBs1j0H.7KcqXG64nRXD.ZScFP9QePRo9XslmucEzNaqcDKpCWdKsSUYk.4zlkirFC.fwxVomYNirgi+A.PkmB1a98fwMz5zuWevCOzcAmkyeMFYWwYpFM+69EtdFRRFLeiWBp8Dg7sV1DKyP+KLIkt6yCxSbDOWtdLxl8PSCZsYplK5Z2g9DJBAl2M2Re3auW2OKZBg.FwQRPV65lomSDEUBNoLrC6+mqU3PfXvCywxjkkcGHSz+Bck1xZO7JSZjN46aGJIrV6q5Zw5CY3PLA2yX0rgi+uBq29UB8h6rMhmGt5LMe4cjA.nJe+v7o9uPf66gbjqw5Hr9f2Fx20cJeIajXXizyrjs5LQO4l1do1yNg8wOBzG3fcrb8oLcHm29hXxUVeQKy0UlB.Xu0M0xrOS84k5p+4ABchH6cssH+Bur2Ef.Kc4tqq0eAXs92NNZUsYaJ+yg5hMBQmuF.DJePp2lAb29jGCn1ylPkY5lW2EippSCYLd+WoMwo5HmGpOzQBydWfmcCb5vUCsC4N9qPtj6v8ckc6q.lktam4Nwrfi+aQiMBy27kQvUd+srHulUkYa7sAx..j6Zan4ZpBAevuOD449pRhWJKSX9B+wn9P6lMQLxwhf2yC34mIOdJ5YeSof0K+zP+64rqQDZZH3JteXcs8G1exlB8VvUJAxMOXrjurq2rrgJJEr15lbrLyW5OAsG8Ic7rEILBffOz+LLekmCxOYisNKrzzgXTiCA+5OTnW+6gw7UegDerQj1vtrhgwT8NWy4UtsLqhPC5SycVsn4077PsmnOoGB78+Wc8tkS+5mCrW6ZRpUw3xUKsiKeWYAu++Am0m9MPXOsY2xi2wUjwO9uMje7Ff87VXR4thSW70Ax..TG+HnoG+GBia81f9BVjqWMDwhcwaGlu1KBTYG+UlQxl1.FDB7C+2acA5ZPqW4Gw2KVpyWKjkF6S3ly+3OJt1+Va6if0e9+t0xu78C6c+YdlUKLl+sBi4eqgx6aMcIH5VtQrbMei+BP386dUUB60+VvXQ2giEKzzQv65qA0ctJHO0wAZ5RPafC10yWzUXe3xgLrfjwK4d1APDBjYWZwdt71i162+QiXziyUpbR0zkfZekDys0dmepq..FSOyD.3pk1APjuqr.Kc4noc7WcNwgxBN9uEJYnKZ867ncrxIMxeNFYgqwFf0q9Bnoex2EVuyZB0MPQg570BqO9CPSO4OFl+1edVYPLfPyRK8BGbq+q+EF4fXJEZ9o+sslZkRQLe4+WXejH+NKRDLmnFDyZKa.x28M79ydmWG161iLENt7q18ALHnOrQEweDKO8If4S+ahRsO5BkkOrcsb0Ea3xum0xd4U2wI26tiqr8hziuyCkpmFdRotkHtZoc.fHNVYhdU.zlyM5Z4Y5i+aK0AJKh0krQ996HygZOKrdyUC7lqFl8r2Pzm9AQt4AzstCboKB04NKvYOSnt+5pHppqDM+JOabk.e6vp8rv7m8Sf8hVVnWblwY+mqrLg8lWOrVyyE4UxrYX969EvdZyBA9J2mi20TQsrkRXu92BVu0pAr5.S.nFZ.xu3fPeDi1whk6qDGYShrN4jCzmr6b2nWISVOU6Yf8Q9BnG1jaQe5yEVoyWzhWszNZiHdWYKdYnostImyN5L8w+gwbMOGzF2jS3d4JS3pq.Ys0YqApyVCh9iFr+jpg5grpJBM.3G9fPtkOL89vaKkPt10flKcWvX42CzF5H770PAvk+Q119XX81uBvYhu7Gm7y9DzzAJCFK+dB8l7MBWApRJg7HkCqU+rgd64lDXWxNbEHKaeZ2qMI2oxIkYywU2LeE165ScG.Xpy.Vub5KUOc0R6vgHLVYhtmGztgE44jKKSd7uC0TEr2vZgwsd6I+xNISbwGbkYzy0m2GG4LLeEyJOzIsr6WWFD.tlqAhgMJHxqWPzstCkkYnGf5pq.pppJtSlwdxHPnYnYuK.n64Bgldn29tm+rgxxFo3tRknLJd7ebgAxHhHxW6piI6AQDQ++VLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZY7.YQaNIJh5mRDQDkE7.QW6b5QrWIhHhnHHieGYDQDQcDLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9ZLPFQDQ9Z+e.4MpQv6X3UxH.....IUjSD4pPfIH" ]
			}

		}
, 		{
			"box" : 			{
				"maxclass" : "message",
				"varname" : "becomeapatronlaunch",
				"text" : ";\rmax launchbrowser https://www.patreon.com/bePatron?u=19939828",
				"linecount" : 2,
				"fontsize" : 12.0,
				"numoutlets" : 1,
				"fontname" : "Arial",
				"hidden" : 1,
				"outlettype" : [ "" ],
				"patching_rect" : [ $xpos, 51.0, 373.0, 35.0 ],
				"id" : "obj-912561376",
				"numinlets" : 2
			}

		}
 ] + . |  
			.patcher.boxes[$basictabidx | tonumber].box.patcher.lines |= [ 			{
				"patchline" : 				{
					"destination" : [ "obj-912561376", 0 ],
					"hidden" : 1,
					"source" : [ "obj-912561374", 0 ]
				}
			} ] + .' "$file" >> /tmp/patronizetmp.txt

mv /tmp/patronizetmp.txt "$file"

done

echo "Done!"