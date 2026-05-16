{
    "patcher": {
        "fileversion": 1,
        "appversion": {
            "major": 9,
            "minor": 1,
            "revision": 1,
            "architecture": "x64",
            "modernui": 1
        },
        "classnamespace": "box",
        "rect": [ 134.0, 172.0, 617.0, 539.0 ],
        "default_fontsize": 13.0,
        "boxes": [
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "hidden": 1,
                    "id": "obj-1",
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 248.0, 411.0, 128.0, 23.0 ],
                    "text": "bach.help.searchtag"
                }
            },
            {
                "box": {
                    "fontface": 0,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-17",
                    "linecount": 2,
                    "maxclass": "bach.hypercomment",
                    "numinlets": 1,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 248.0, 367.0, 157.0, 36.0 ],
                    "text": "For more information see #eval+depth+argument.",
                    "textcolor": [ 0.501960784313725, 0.501960784313725, 0.501960784313725, 1.0 ]
                }
            },
            {
                "box": {
                    "id": "obj-14",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 9.0, 254.0, 135.0, 23.0 ],
                    "text": "6000 6400 6700 7200"
                }
            },
            {
                "box": {
                    "id": "obj-15",
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 9.0, 358.0, 132.0, 23.0 ],
                    "text": "print items @popup 1"
                }
            },
            {
                "box": {
                    "code": "findaddrs($x1, 0, ($item, $target -> $item % 1200 == $target)) ",
                    "id": "obj-16",
                    "linecount": 3,
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 9.0, 289.0, 185.0, 52.0 ],
                    "saved_object_attributes": {
                        "embed": 1,
                        "versionnumber": 80001
                    },
                    "text": "bach.eval findaddrs($x1\\, 0\\, ($item\\, $target -> $item % 1200 == $target)) @out m"
                }
            },
            {
                "box": {
                    "id": "obj-2",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 9.0, 122.0, 50.0, 23.0 ],
                    "text": "1 2 3 1"
                }
            },
            {
                "box": {
                    "id": "obj-5",
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 9.0, 192.0, 98.0, 23.0 ],
                    "text": "print @popup 1"
                }
            },
            {
                "box": {
                    "code": "findaddrs($x1, 1) ",
                    "id": "obj-7",
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 9.0, 157.0, 215.0, 23.0 ],
                    "saved_object_attributes": {
                        "embed": 1,
                        "versionnumber": 80001
                    },
                    "text": "bach.eval findaddrs($x1\\, 1) @out m"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-6",
                    "linecount": 16,
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 230.0, 122.0, 344.0, 239.0 ],
                    "text": "Arguments:\nllll\nitems (default: null. The items argument is passed to the comparison function)\nfunction (default: null, standing for standard equality test)\nsize\ndepth\nminidx (default: 1)\nmaxidx (default: -1)\nidxreject (default: 0)\ndepthreject (default: 0)\nmaxcount (default: 0)\ndepthpolicy (default: 0)\nrecursive (default: 0)\nmindepth (default: 1)\nmaxdepth (default: -1)",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ]
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-76",
                    "linecount": 3,
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 9.0, 39.0, 484.0, 50.0 ],
                    "text": "The findaddrs() function retrieves the addresses of items from an llll, like the bach.find object.\nAn equality comparison function can be provided through the \"function\" argument.",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ]
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 11.0,
                    "id": "obj-11",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 6.0, 514.0, 585.0, 19.0 ],
                    "text": "See Also: find, finditems, lambda",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ],
                    "varname": "seealso"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 11.0,
                    "id": "obj-10",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 6.0, 495.0, 585.0, 19.0 ],
                    "text": "Objects: bach.eval, bach.diff, bach.intersection, bach.symdiff, bach.union, bach.classify",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ],
                    "varname": "objects"
                }
            },
            {
                "box": {
                    "fontface": 1,
                    "fontname": "Arial",
                    "fontsize": 15.0,
                    "id": "obj-13",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 6.0, 8.0, 222.0, 23.0 ],
                    "text": "findaddrs() function reference",
                    "varname": "title"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 11.0,
                    "id": "obj-12",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 6.0, 476.0, 585.0, 19.0 ],
                    "text": "Tags: evaluation, language, script, scripting, code, bell, built, in, function, findaddrs, find, search, address",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ],
                    "varname": "tags"
                }
            }
        ],
        "lines": [
            {
                "patchline": {
                    "destination": [ "obj-16", 0 ],
                    "source": [ "obj-14", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-15", 0 ],
                    "source": [ "obj-16", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-1", 0 ],
                    "hidden": 1,
                    "source": [ "obj-17", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-7", 0 ],
                    "source": [ "obj-2", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-5", 0 ],
                    "source": [ "obj-7", 0 ]
                }
            }
        ],
        "autosave": 0
    }
}