lexer grammar preprocLexer;

@lexer::members {
    bool noInclude;
}

DONTLOOKHERE: ('"' ( '\\"' | ~["] )* ~'\\' '"' 
| '\'' ( '\\\'' | ~['] )* ~[\\] '\''
| '""'
| '\'\''
| '#(' .*? ')#'
| ('##'|'#!') .*? ('\n'|EOF))
{ noInclude = true; }
;

WHITESPACE: [ \u0001\t\r\n]+ { noInclude = false; }
;

INCLUDE: { !noInclude }? 'include' ([ \u0001\t]*) '(' -> mode(INCLUDE_MODE)
;

ANY: .+? { noInclude = true; }
;

mode INCLUDE_MODE;

CLOSE: ([ \u0001\t]*) ')' { noInclude = true; } -> mode(DEFAULT_MODE)
;

FILENAME: (~')')+
;
