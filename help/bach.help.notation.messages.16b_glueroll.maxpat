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
        "rect": [ 373.0, 100.0, 617.0, 539.0 ],
        "boxes": [
            {
                "box": {
                    "fontface": 0,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-14",
                    "linecount": 3,
                    "maxclass": "bach.hypercomment",
                    "numinlets": 1,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 171.01030552387238, 217.52576100826263, 378.35049426555634, 50.0 ],
                    "presentation_linecount": 2,
                    "sendto": "bach.help.filtertags",
                    "text": "If you input a third argument (after the two thresholds) this will be a transition smoothing time in milliseconds for envelopes and duration lines (also see #gluechord+envelope).",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ]
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-8",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 67.01030552387238, 217.52576100826263, 102.0, 23.0 ],
                    "presentation_linecount": 2,
                    "text": "glue 300 100 10"
                }
            },
            {
                "box": {
                    "bubble": 1,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-7",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 147.42267215251923, 186.34534990787506, 467.0, 25.0 ],
                    "presentation_linecount": 2,
                    "text": "Connect notes when they are tail-to-head at most 300ms and 100cents apart"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-6",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 57.73195552825928, 187.34534990787506, 84.0, 23.0 ],
                    "presentation_linecount": 2,
                    "text": "glue 300 100"
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-4",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 43.29896664619446, 155.67009437084198, 131.0, 23.0 ],
                    "presentation_linecount": 2,
                    "text": "glue selection 200 10"
                }
            },
            {
                "box": {
                    "accidentalsgraphic": 0,
                    "breakpointshavevelocity": 1,
                    "breakpointsize": 3.33,
                    "bwcompatibility": 80103,
                    "defaultnoteslots": [ "null" ],
                    "durationlinewidth": 4.0,
                    "fontface": 0,
                    "fontname": "Arial",
                    "fontsize": 12.0,
                    "id": "obj-2",
                    "loop": [ 0.0, 1000.0 ],
                    "maxclass": "bach.roll",
                    "notationstyles": [ "linpitch" ],
                    "numinlets": 6,
                    "numoutlets": 8,
                    "numvoices": 1,
                    "out": "nnnnnnnn",
                    "outlettype": [ "", "", "", "", "", "", "", "" ],
                    "patching_rect": [ 15.463916659355164, 282.4742109775543, 576.0, 187.04029898209993 ],
                    "pitcheditrange": [ "null" ],
                    "showledgerlines": 0,
                    "showstems": 0,
                    "showtails": 0,
                    "showvelocity": 4,
                    "stafflines": [ 5 ],
                    "textcolor": [ 0.0, 0.0, 0.0, 1.0 ],
                    "tonedivision": 8,
                    "versionnumber": 80900,
                    "voicenames": [ "[", "]" ],
                    "voicespacing": [ -12.585754928263825, 20.86597916483879 ],
                    "whole_roll_data_0000000000": [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "bufferAGP", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "annotation", "]", "[", "type", "text", "]", "[", "key", "t", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 2, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 3, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 4, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "[", 5, "[", "name", "command", "]", "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "marker", "marker", "]", "[", "start", "none", "]", "[", "end", "none", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "]", "[", "midichannels", 1, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4125071611, 1086276584, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 13, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 13, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 4091319094, 3211376699, "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1071309127, 45, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3153272672, 3228138782, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 18, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086224384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 45, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 45, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 71571522, 3222782862, "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1069589463, 56, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 748204480, 3228362130, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 80, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1855666802, 1086165203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 56, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 56, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2157212610, 1074309716, "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 3218331402, 20, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 709428736, 1077973126, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 56, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1086173684, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 20, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 20, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 541629807, 3227208230, "_x_x_x_x_bach_float64_x_x_x_x_", 481036337, 1070294106, 58, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 709428736, 3225456774, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 61, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081671680, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1855666802, 1086165203, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 58, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 58, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 422877978, 3227224602, "_x_x_x_x_bach_float64_x_x_x_x_", 1752346657, 1070919057, 65, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 985063232, 3228610031, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 28, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081835520, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1086096884, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, 65, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 65, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3405858390, 3224250613, "_x_x_x_x_bach_float64_x_x_x_x_", 1236950581, 1070268940, 60, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3305993216, 3224324182, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 73, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082310656, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086092880, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 60, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 60, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 667341721, 3225470895, "_x_x_x_x_bach_float64_x_x_x_x_", 446676599, 3218398511, 56, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2766916144, 3230376670, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 87, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082392576, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1085866484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 56, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 56, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 1689267673, 1078098618, "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 3218373345, 53, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2766916144, 1082893022, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 78, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 344548887, 1086226830, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 28, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 28, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 1689267673, 1078098618, "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 3218373345, 26, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2766916144, 1082893022, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 39, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082556416, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086092880, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 53, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 53, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 1069715292, 26, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 1069715292, 26, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 100217904, 1082981205, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917184, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 45, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 45, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3482447641, 3220562986, "_x_x_x_x_bach_float64_x_x_x_x_", 4226247819, 3218796969, 18, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2718330944, 3228090736, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086223155, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 22, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 22, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3482447641, 3220562986, "_x_x_x_x_bach_float64_x_x_x_x_", 4226247819, 3218796969, 9, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2718330944, 3228090736, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1886136290, 1086363436, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 15, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 15, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3482447641, 3220562986, "_x_x_x_x_bach_float64_x_x_x_x_", 4226247819, 3218796969, 6, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 2718330944, 3228090736, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 100217905, 1083063125, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1085866484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 18, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 18, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2338678650, 3227502886, "_x_x_x_x_bach_float64_x_x_x_x_", 3023656976, 3216930504, 47, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3615384560, 3230617507, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2921529265, 1086184743, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 9, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 9, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2338678650, 3227502886, "_x_x_x_x_bach_float64_x_x_x_x_", 3023656976, 3216930504, 23, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3615384560, 3230617507, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2958654910, 1086347824, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 6, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 6, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2338678650, 3227502886, "_x_x_x_x_bach_float64_x_x_x_x_", 3023656976, 3216930504, 15, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3615384560, 3230617507, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 1, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 100217904, 1083145045, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085609984, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 47, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 47, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3572038399, 1078021045, "_x_x_x_x_bach_float64_x_x_x_x_", 2130303779, 3218914410, 67, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3615384560, 1083133859, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 92, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083202986, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1085866484, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, 67, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 67, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 4091319094, 1076475963, "_x_x_x_x_bach_float64_x_x_x_x_", 2336462209, 3218335596, 30, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082925056, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 81, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3182684685, 1086350015, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080295424, 22, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 22, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 4091319094, 1076475963, "_x_x_x_x_bach_float64_x_x_x_x_", 2336462209, 3218335596, 10, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1082925056, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 27, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083366826, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1086096884, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 30, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 30, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3266160775, 3226867567, "_x_x_x_x_bach_float64_x_x_x_x_", 2370821947, 1071279767, 54, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3056102304, 3228809794, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 23, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086256384, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 7, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 7, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3266160775, 3226867567, "_x_x_x_x_bach_float64_x_x_x_x_", 2370821947, 1071279767, 13, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3056102304, 3228809794, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 5, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1890261362, 1086373165, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 15, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 15, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3266160775, 3226867567, "_x_x_x_x_bach_float64_x_x_x_x_", 2370821947, 1071279767, 27, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3056102304, 3228809794, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 11, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083448746, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086016080, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 54, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 54, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2129003540, 1079435664, "_x_x_x_x_bach_float64_x_x_x_x_", 2851858285, 3218985713, 27, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081262080, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 24, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086166784, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 10, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 10, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2129003540, 1079435664, "_x_x_x_x_bach_float64_x_x_x_x_", 2851858285, 3218985713, 5, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081262080, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 4, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086292560, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080623104, 27, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 27, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2129003540, 1079435664, "_x_x_x_x_bach_float64_x_x_x_x_", 2851858285, 3218985713, 13, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1081262080, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 12, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083653546, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086092880, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079246848, 27, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 27, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 2585253279, 1079255269, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1071275573, 36, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3305993216, 1076840534, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 67, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083735466, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2062535806, 1086096884, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 36, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 36, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3020072568, 3225427918, "_x_x_x_x_bach_float64_x_x_x_x_", 584115552, 3218536923, 8, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3056102304, 3228809794, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 21, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 172274444, 1086373319, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 18, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 18, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 3020072568, 3225427918, "_x_x_x_x_bach_float64_x_x_x_x_", 584115552, 3218536923, 4, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 3056102304, 3228809794, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1070805811, 10, "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2197592600, 1083776426, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1334658500, 1086016080, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 8, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 8, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 1580547965, 1070877114, 1, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 1580547965, 1070877114, 1, "]", "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1526322709, 1086361179, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078198272, 4, "[", "breakpoints", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, 4, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1070176665, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 1580547965, 1070877114, 1, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 1580547965, 1070877114, 1, "]", "]", 0, "]", 0, "]", 0, "]" ],
                    "whole_roll_data_count": [ 1 ],
                    "zoom": 212.9921875
                }
            },
            {
                "box": {
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-5",
                    "maxclass": "message",
                    "numinlets": 2,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 15.463916659355164, 111.34019994735718, 76.0, 23.0 ],
                    "text": "glue 200 10"
                }
            },
            {
                "box": {
                    "bubble": 1,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-16",
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 194.84534990787506, 155.67009437084198, 307.0, 25.0 ],
                    "text": "Same thing, but only operating on selected notes"
                }
            },
            {
                "box": {
                    "bubble": 1,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-3",
                    "linecount": 2,
                    "maxclass": "comment",
                    "numinlets": 1,
                    "numoutlets": 0,
                    "patching_rect": [ 93.81442773342133, 103.09277772903442, 410.309255361557, 40.0 ],
                    "text": "This will connect notes when the tail of the first and the head of the second are less than 200ms apart, and less than 10 cents apart."
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
                    "text": "See Also: gluechord, merge",
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
                    "text": "Objects: bach.roll",
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
                    "patching_rect": [ 6.0, 8.0, 403.0, 23.0 ],
                    "text": "Gluing or connecting notes in bach.roll",
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
                    "text": "Tags: message, glue, gluing, join, merge, connect, track, partial, glueing, note",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ],
                    "varname": "tags"
                }
            },
            {
                "box": {
                    "fontface": 0,
                    "fontname": "Arial",
                    "fontsize": 13.0,
                    "id": "obj-76",
                    "linecount": 4,
                    "maxclass": "bach.hypercomment",
                    "numinlets": 1,
                    "numoutlets": 1,
                    "outlettype": [ "" ],
                    "patching_rect": [ 6.0, 32.0, 606.0, 65.0 ],
                    "sendto": "bach.help.filtertags",
                    "text": "You can use the \"glue\" command to connect notes that are tip-to-head close together in bach.roll.\nThis works similarly to #merge, but differs from it in that this latter combines together notes whose onsets are close; instead, \"glue\" is meant to connect different notes into a single stream (a bit like a sequence of #gluechord commands).",
                    "textcolor": [ 0.5, 0.5, 0.5, 1.0 ]
                }
            }
        ],
        "lines": [
            {
                "patchline": {
                    "destination": [ "obj-2", 0 ],
                    "source": [ "obj-4", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-2", 0 ],
                    "source": [ "obj-5", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-2", 0 ],
                    "source": [ "obj-6", 0 ]
                }
            },
            {
                "patchline": {
                    "destination": [ "obj-2", 0 ],
                    "source": [ "obj-8", 0 ]
                }
            }
        ],
        "autosave": 0
    }
}