grammar bell;

@lexer::header { 
#include "ext.h" 
}

@lexer::members {

    //// MEMBERS

    bool noParams = true;
    bool noUnary = false;
    long *codeac = 0;

    bool followedBySpace() {
        size_t c = _input->LA(2);
        switch (c) {
            case ' ':
            case '\x01':
            case '\t':
            case '\n':
            case '\r':
                return true;
            default:
                return false;
        }
    }

    bool notUintRange() {
        int i = 2;
        size_t c;

        do {
            c = _input->LA(i);
              if ((c < '0' || c > '9') && c != '.')
                return true;
            i++;
        } while (c != '.');

        if (_input->LA(i) == '.' && _input->LA(i+1) == '.' && _input->LA(i+2) != '.')
            return false;
        else
            return true;
    }

    bool notUnary() {
        return noUnary || followedBySpace();
    }

    void setCodeac(long* c) { codeac = c; }

    //// MEMBERS END
}

@parser::members { 
    
    bool ending = false;

}


// parser rules

everything: program
;

program: EOF #programEOF
| sequence EOF #programSequence
| sequence NAMEDPARAM #programSequenceNamedparam
| NAMEDPARAM #programNamedparam
;

sequence: list
| nullified+ list? 
;

nullified: list NULLIFY+
;

whileloop: WHILE sequence kind=(DO|COLLECT) list
;

argsByNameList: NAMEDPARAM sequence (','? NAMEDPARAM sequence)*
;

argsByPositionList: sequence (',' sequence)*
;

simpleFuncall: (item|var) PARAMS CLOSED
| (item|var) PARAMS argsByPositionList CLOSED
| (item|var) PARAMS argsByNameList CLOSED
| (item|var) PARAMS argsByPositionList ','? argsByNameList CLOSED
| simpleFuncall PARAMS CLOSED
| simpleFuncall PARAMS argsByPositionList CLOSED
| simpleFuncall PARAMS argsByNameList CLOSED
| simpleFuncall PARAMS argsByPositionList ','? argsByNameList CLOSED
;

dataFlowItem: item|var|simpleFuncall
;

funcall: simpleFuncall
| dataFlowItem ('.' simpleFuncall)+
;


funarg: LOCALVAR (ASSIGN list)? #funargVar
| ELLIPSIS #funargEllipsis
;

funargList: funarg (',' funarg)*
;

liftedargList: LIFT (LOCALVAR ',')* LOCALVAR
;

fundef: funargList liftedargList? FUNDEF list
;


item: UINT #itemUint
| UFLOAT #itemUfloat
| UPITCH #itemUpitch
| BTSYMBOL #itemBtSymbol
| (DQSYMBOL|SQSYMBOL) #itemQSymbol
| BIF #itemBIF
| OF #itemOF
| type=(INLET|INTINLET|FLOATINLET|RATINLET|PITCHINLET) #itemInlet
| DIRINLET #itemDirInlet
| BACHNULL #itemNull
| BACHNIL #itemNil
| OPEN sequence CLOSED #itemSequence
| PUSH sequence POP #itemSublist
;

var: LOCALVAR #varLocal
| PATCHERVAR #varPatcher
| GLOBALVAR #varGlobal
;

lvalueSpecs: {ending = false;} ((NTH|KEY) (item|var))+
| {ending = true;} ((NTH|KEY) (item|var))* ((NTH|KEY) (conditional))
;

lvalue: var lvalueSpecs?
;

fakeLvalue: item lvalueSpecs
;

listEnd: conditional
| assignment
| whileloop
| fundef
;

expr: (item|var|funcall|listEnd) #exprSimple
| lvalue #exprLvalue
| fakeLvalue #exprFakeLvalue
| expr PICK expr #exprBinary
| <assoc=right> expr op=POW expr #exprBinary 
| (UPLUS|UMINUS)+ expr #exprUPlusMinus
| expr op=(TIMES|DIV|DIVDIV|REM) expr #exprBinary
| expr op=(PLUS|MINUS) expr #exprBinary
| expr op=(LSHIFT|RSHIFT) expr #exprBinary
| expr op=RANGE expr #exprBinary
| expr op=REPEAT expr #exprBinary
| expr op=(EQUAL|NEQ) expr #exprBinary
| expr op=(LT|GT|LEQ|GEQ) expr #exprBinary
| expr op=BITAND expr #exprBinary
| expr op=BITXOR expr #exprBinary
| expr op=BITOR expr #exprBinary
| expr op=(LOGAND|LOGANDEXT) expr #exprBinary
| expr op=LOGXOR expr #exprBinary
| expr op=(LOGOR|LOGOREXT) expr #exprBinary
| op=(LOGNOT|BITNOT) expr #exprNot
;

assignment: lvalue op=(ASSIGN|APOW|ATIMES|ADIVDIV
    |ADIV|AREM|APLUS|AMINUS|ALOGAND|ALOGANDEXT
    |ALOGXOR|ALOGOR|ALOGOREXT|ABITAND|ABITXOR
    |ABITOR|ALSHIFT|ARSHIFT|ACONCAT|ARCONCAT|ANTH) list #trueAssignment
| fakeLvalue op=(ASSIGN|APOW|ATIMES|ADIVDIV
    |ADIV|AREM|APLUS|AMINUS|ALOGAND|ALOGANDEXT
    |ALOGXOR|ALOGOR|ALOGOREXT|ABITAND
    |ABITXOR|ABITOR|ALSHIFT|ACONCAT
    |ARCONCAT|ARSHIFT) list #fakeAssignment
| OUTLET ASSIGN list #outletAssignment
| DIROUTLET ASSIGN list #dirOutletAssignment
;

conditional: IF sequence THEN list #ifthen
| IF sequence THEN sequence ELSE list #ifthenelse
;

list: expr+
;



// lexer rules

RANGE: '...' { noParams = true; noUnary = false; };

UINT: [0-9]+ { noParams = false; noUnary = true; };

UFLOAT: { notUintRange()}? (((([0-9]* '.' [0-9]+) | ([0-9]+ '.')) 
          (([eE]([-+]?)[0-9]+)?)) |
         ([0-9]+[eE]([-+]?)[0-9]+)) 
        { noParams = false; noUnary = true; };

UPITCH: NOTENAME ACCIDENTAL? [+-]* UINT ([+-]* (UINT|RAT) 't')?
 { noParams = false; noUnary = true; };

fragment NOTENAME: ([a-g]|[A-G]);
fragment ACCIDENTAL: ([#bxdq^v]+);
fragment RAT: UINT '/' [+-]* UINT;

BTSYMBOL: '`' (~[ \t\r\n\u0001])+ { noParams = true; noUnary = true; };
DQSYMBOL: '"' ( '\\"' | ~["] )* ~'\\' '"' { noParams = true; noUnary = true; };
SQSYMBOL: '\'' ( '\\\'' | ~['] )* ~[\\] '\'' { noParams = true; noUnary = true; };

BACHNULL: 'null' { noParams = false; noUnary = false; };
BACHNIL: 'nil' { noParams = false; noUnary = false; };

IF: 'if' { noParams = true; noUnary = false; };

THEN: 'then' { noParams = true; noUnary = false; };

ELSE: 'else' { noParams = true; noUnary = false; };

WHILE: 'while' { noParams = true; noUnary = false; };
FOR: 'for' { noParams = true; noUnary = false; };
DO: 'do' { noParams = true; noUnary = false; };
COLLECT: 'collect' { noParams = true; noUnary = false; };

INLET: '\\'? '$'[lx][0-9]+ { noParams = false; noUnary = true; };
INTINLET: '\\'? '$i'[0-9]+ { noParams = false; noUnary = true; };
RATINLET: '\\'? '$r'[0-9]+ { noParams = false; noUnary = true; };
FLOATINLET: '\\'? '$f'[0-9]+ { noParams = false; noUnary = true; };
PITCHINLET: '\\'? '$p'[0-9]+ { noParams = false; noUnary = true; };

OUTLET: '\\'? '$o'[0-9]+ { noParams = false; noUnary = true; };

DIRINLET: '\\'? '$dx'[0-9]+ { noParams = false; noUnary = true; };
DIROUTLET: '\\'? '$do'[0-9]+ { noParams = false; noUnary = true; };

BIF: 
    ('length'|'depth'|'is'|'nth'|'sort'|'contains'|'rev'|'rot'|'trans'|'flat'|'slice'|'left'|'right'|'subs'|'insert'|'find'|'finditems'|'findaddrs'|'scramble'|'minmax'|'perm'|'comb'|'cartesianprod'|'wrap'|'group'|'delace'|'thin'|'classify'|'union'|'intersection'|'symdiff'|'diff'|'primeser'|'arithmser'|'geomser'|'map'|'reduce'|'apply'
    |'cos'|'sin'|'tan'|'exp'|'log'|'acos'|'asin'|'atan'|'cosh'|'sinh'|'tanh'|'exp2'|'log2'|'sqrt'|'ceil'|'acosh'|'asinh'|'atanh'|'log10'|'floor'|'round'|'trunc'|'fmod'|'atan2'|'hypot'|'pow'|'int'|'rat'|'num'|'den'|'abs'|'sgn'|'float'|'pitch'|'degree'|'octave'|'alter'|'cents'|'mod'|'min'|'max'|'random'|'bessel'|'approx'|'enharm'|'makepitch'|'makepitchsc'|'mc2f'|'f2mc'|'minimum'|'maximum'|'sum'|'prod'
    |'outlet'|'inlet'
    |'#+'|'#-'|'#u-'|'#*'|'#/'|'#//'|'#%'|'#=='|'#!='|'#<'|'#>'|'#<='|'#>='|'#&'|'#^'|'#|'|'#&&'|'#^^'|'#||'|'#&&&'|'#|||'|'#<<'|'#>>') { noParams = false; noUnary = true; };

OF: ('directout'|'directin'|'print') { noParams = false; noUnary = true; };

GLOBALVAR: ID { noParams = false; noUnary = true; };
PATCHERVAR: '#' ID { noParams = false; noUnary = true; };
LOCALVAR: '\\'? '$' ID { post("localvar"); noParams = false; noUnary = true; };
NAMEDPARAM: '\\'? '@' ID { noParams = true; noUnary = true; };

fragment ID: [a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?;


PUSH: '[' { noParams = true; noUnary = false; };

POP: ']' { noParams = false; noUnary = true; };

CLOSED: ')' { noParams = false; noUnary = true; };

NTH: ':' { noParams = true; noUnary = false; };
PICK: '::' { noParams = true; noUnary = false; };
KEY: '.' { noParams = true; noUnary = false; };
ANTH: ':=' { noParams = true; noUnary = false; };
APICK: '::=' { noParams = true; noUnary = false; };

NULLIFY: ';' { noParams = true; noUnary = false; };

ASSIGN: '=' { noParams = true; noUnary = false; };

WHITESPACE: [ \t\r\n] { noParams = true; noUnary = false; } -> channel(HIDDEN);
NEWATOM: [\u0001] { noParams = true; noUnary = false; (*codeac)++; } -> channel(HIDDEN);

POW: '**' { noParams = true; noUnary = false; };
APOW: '**=' { noParams = true; noUnary = false; };

TIMES: '*' { noParams = true; noUnary = false; };
ATIMES: '*=' { noParams = true; noUnary = false; };

DIVDIV: '//' { noParams = true; noUnary = false; };
ADIVDIV: '//=' { noParams = true; noUnary = false; };
DIV: '/' { noParams = true; noUnary = false; };
ADIV: '/=' { noParams = true; noUnary = false; };

REM: '%' { noParams = true; noUnary = false; };
AREM: '%' { noParams = true; noUnary = false; };

PLUS: { notUnary() }? '+' { noParams = true; noUnary = false; };
APLUS: '+=' { noParams = true; noUnary = false; };
UPLUS: '+' { noParams = true; noUnary = false; };

MINUS: { notUnary() }? '-' { noParams = true; noUnary = false; };
AMINUS: '-=' { noParams = true; noUnary = false; };
UMINUS: '-' { noParams = true; noUnary = false; };

EQUAL: '==' { noParams = true; noUnary = false; };

NEQ: '!=' { noParams = true; noUnary = false; };

LOGNOT: '!' { noParams = true; noUnary = false; };

BITNOT: '~' { noParams = true; noUnary = false; };

LT: '<' { noParams = true; noUnary = false; };

GT: '>' { noParams = true; noUnary = false; };

LEQ: '<=' { noParams = true; noUnary = false; };

GEQ: '>=' { noParams = true; noUnary = false; };

BITAND: '&' { noParams = true; noUnary = false; };
ABITAND: '&=' { noParams = true; noUnary = false; };

BITXOR: '^' { noParams = true; noUnary = false; };
ABITXOR: '^=' { noParams = true; noUnary = false; };

BITOR: '|' { noParams = true; noUnary = false; };
ABITOR: '|=' { noParams = true; noUnary = false; };

LOGAND: '&&' { noParams = true; noUnary = false; };
LOGANDEXT: '&&&' { noParams = true; noUnary = false; };
ALOGAND: '&&=' { noParams = true; noUnary = false; };
ALOGANDEXT: '&&&=' { noParams = true; noUnary = false; };

LOGXOR: '^^' { noParams = true; noUnary = false; };
ALOGXOR: '^^=' { noParams = true; noUnary = false; };

LOGOR: '||' { noParams = true; noUnary = false; };
ALOGOR: '||=' { noParams = true; noUnary = false; };

LOGOREXT: '|||' { noParams = true; noUnary = false; };
ALOGOREXT: '|||=' { noParams = true; noUnary = false; };

LSHIFT: '<<' { noParams = true; noUnary = false; };
ALSHIFT: '<<=' { noParams = true; noUnary = false; };

RSHIFT: '>>' { noParams = true; noUnary = false; };
ARSHIFT: '>>=' { noParams = true; noUnary = false; };

REPEAT: ':*' { noParams = true; noUnary = false; };
AREPEAT: ':*=' { noParams = true; noUnary = false; };

AAPPLY: '.=' { noParams = true; noUnary = false; };
ACONCAT: '_=' { noParams = true; noUnary = false; };
ARCONCAT: '!_=' { noParams = true; noUnary = false; };

OPEN: { noParams }? '(' { noParams = true; noUnary = false; };
PARAMS: { !noParams }? '(' { noParams = true; noUnary = false; };

FUNDEF: '->' { post("fundef"); noParams = true; noUnary = false; };
LIFT: '-^' { noParams = true; noUnary = false; };
ELLIPSIS: '<...>' { noParams = true; noUnary = false; };

ANYTHING: .+?;
