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
                    "fontface": 0,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-14",
                    "maxclass": "bach.ratnum",
                    "maximum": "none",
                    "minimum": "none",
                    "numinlets": 1,
                    "numoutlets": 2,
                    "out": "n",
                    "outlettype": [ "", "bang" ],
                    "patching_rect": [ 70.0, 91.0, 50.0, 23.0 ],
                    "text": "4/1"
                }
            },
            {
                "box": {
                    "format": 6,
                    "id": "obj-9",
                    "maxclass": "flonum",
                    "numinlets": 1,
                    "numoutlets": 2,
                    "outlettype": [ "", "bang" ],
                    "parameter_enable": 0,
                    "patching_rect": [ 13.0, 91.0, 50.0, 23.0 ]
                }
            },
            {
                "box": {
                    "id": "obj-2",
                    "maxclass": "number",
                    "numinlets": 1,
                    "numoutlets": 2,
                    "outlettype": [ "", "bang" ],
                    "parameter_enable": 0,
                    "patching_rect": [ 215.0, 91.0, 50.0, 23.0 ]
                }
            },
            {
                "box": {
                    "id": "obj-5",
                    "maxclass": "newobj",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 13.0, 170.0, 98.0, 23.0 ],
                    "text": "print @popup 1"
                }
            },
            {
                "box": {
                    "code": "foldratio($x1, $x2) ",
                    "id": "obj-7",
                    "maxclass": "newobj",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 13.0, 136.0, 221.0, 23.0 ],
                    "saved_object_attributes": {
                        "embed": 1,
                        "versionnumber": 80900
                    },
                    "text": "bach.eval foldratio($x1\\, $x2) @out m"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-6",
                    "linecount": 3,
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 408.0, 129.5, 189.0, 50.0 ],
                    "presentation_linecount": 3,
                    "text": "Arguments:\nratio (default: null)\npseudo-octave (default: null)",
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
                    "patching_rect": [ 9.0, 39.0, 451.0, 50.0 ],
                    "text": "The foldratio() function is a sort of multiplicative modulo. It \"folds\" a rational or floating point number, dividing or multipying it by the modulo enough times so that it finally lies between 1 and the modulo.",
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
                    "text": "See Also: degree, octave, alter, pitchkeys, jisharps, etsharps",
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
                    "patching_rect": [ 6.0, 8.0, 214.0, 23.0 ],
                    "text": "foldratio() function reference",
                    "varname": "title"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 11.0,
                    "id": "obj-12",
                    "linecount": 2,
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 6.0, 476.0, 585.0, 31.0 ],
                    "text": "Tags: evaluation, language, script, scripting, code, bell, built, in, function, pitch, just, intonation, fold, ratio, foldratio, modulo",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ],
                    "varname": "tags"
                }
            }
        ],
        "lines": [
            {
                "patchline": {
                    "destination": [ "obj-7", 0 ],
                    "source": [ "obj-14", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-7", 1 ],
                    "source": [ "obj-2", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-5", 0 ],
                    "source": [ "obj-7", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-7", 0 ],
                    "source": [ "obj-9", 0 ]
                }
            }
        ],
        "autosave": 0
    }
}