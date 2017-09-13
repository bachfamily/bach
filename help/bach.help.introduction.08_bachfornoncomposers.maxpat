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
		"rect" : [ 651.0, 44.0, 617.0, 539.0 ],
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
					"fontsize" : 11.0,
					"frgb" : 0.0,
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
					"frgb" : 0.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 495.0, 585.0, 19.0 ],
					"text" : "Objects: all",
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
					"patching_rect" : [ 6.0, 7.0, 282.0, 23.0 ],
					"text" : "bach for a non-composer",
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
					"text" : "Tags: introduction, bach, non, composer, non-composer, llll",
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
					"linecount" : 25,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 39.0, 600.0, 370.0 ],
					"text" : "While bach has been conceived as a computer-aided composition tool, most of its components have a much more general scope.\n\nIn fact, you can forget about the most specifically musical objects (basically, the ones grouped under the \"musical notation\" header), maybe wonder why we have been so eager about prime and rational numbers (musicians really need them, maybe you don't) and take advantage of the llll, which is quite a powerful data type indeed.\n\nConsider the following points:\n- bach objects processing lllls can deal with much larger collections of data than standard objects processing Max lists\n- lllls provide you with a way of structuring your data in a very flexible and general way\n- every element of a llll has a unique address, and at any time you can retrieve, insert, substitute or delete single elements of a llll by means of it\n- you have powerful and flexible tools for sorting and filtering your data\n- you can easily set up key-based data storage and access\n- you can easily perform iterative operations upon lllls\n- last but not least, bach is extremely light-weight: besides the memory required by the lllls you're actually using, and the (very small) amount of memory needed by the externals themselves, bach has no inherent cost upon your system; it doesn't set up scheduled operations (except when it plays a roll or a score); it doesn't interfere with Max's threading model; lllls either safely traverse regular Max objects or are politely refused, but don't ever mess up things even when used improperly.\n\nIn fact, a single llll can be seen as a data collection comparable to a whole coll (definitely not the same thing, though), but traveling through regular patch cords and accessible in very intuitive way.",
					"textcolor" : [ 0.25, 0.25, 0.25, 1.0 ]
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [  ]
	}

}
