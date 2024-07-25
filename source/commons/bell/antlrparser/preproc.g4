parser grammar preproc;

options { tokenVocab=preprocLexer; }

@parser::header {
    #include "ext.h"
    #include "llll_commons.h"
}

@parser::members {
    std::string output;
    bool error = false;
    bool included = false;
}

code: (transcribe|include)* EOF
;

transcribe: DONTLOOKHERE { output += $DONTLOOKHERE.text; }
| ANY { output += $ANY.text; }
| WHITESPACE { output += $WHITESPACE.text; }
;

include: INCLUDE FILENAME CLOSE { 
    t_fourcc filetype[] = {'TEXT', 'BELL'};
    t_fourcc outtype;
    char *filename = (char *) bach_newptr(MAX_PATH_CHARS + 1);
    short path;
    auto s = $FILENAME.text;
    strncpy_zero(filename, s.c_str(), MAX_PATH_CHARS);    // must copy symbol before calling locatefile_extended
    if (locatefile_extended(filename, &path, &outtype, filetype, 2)) { // non-zero: not found
        object_error(nullptr, "include(%s): file not found", s.c_str());
    } else {
        t_filehandle fh;
        if (path_opensysfile(filename, path, &fh, READ_PERM)) {
            object_error(nullptr, "error opening %s", filename);
            error = true;
        } else {
            // allocate some empty memory to receive text
            char **texthandle = sysmem_newhandle(0);
            sysfile_readtextfile(fh, texthandle, 0, TEXT_NULL_TERMINATE); 
            size_t size = sysmem_handlesize(texthandle);
            //post("the file has %ld characters", size);
            sysfile_close(fh);
            output += *texthandle;
            if (!isspace(output.back()))
                output += ' ';
            sysmem_freehandle(texthandle);
            included = true;
        }  
    } 
}
;

