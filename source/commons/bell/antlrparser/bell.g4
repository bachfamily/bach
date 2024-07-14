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
        int c = _input->LA(2);
        post("%c", c);
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

funcall: FUNCTION PARAMS sequence CLOSED
;

item: UINT #itemUint
| UFLOAT #itemUfloat
| UPITCH #itemUpitch
| INLET #itemInlet
| OPEN sequence CLOSED #itemSequence
| PUSH sequence POP #itemSublist
| funcall #itemFuncall
;

var: LOCALVAR #varLocal
| PATCHERVAR #varPatcher
| GLOBALVAR #varGlobal
;

lvalueSpecs: {ending = false;} (NTH (item|var))+
| {ending = true;} (NTH (item|var))* (NTH (conditional))
;

lvalue: var lvalueSpecs?
;

fakeLvalue: item lvalueSpecs
;

expr: (item|var) #exprSimple
| {!ending}? lvalue #exprLvalue
| {!ending}? fakeLvalue #exprFakeLvalue
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

eexpr: {ending}? lvalue #eexprLvalue
| {ending}? fakeLvalue #eexprFakeLvalue
| expr op=POW listEnd #eexprBinary 
| (UPLUS|UMINUS)+ eexpr #eexprUPlusMinus
| expr op=(TIMES|DIV|DIVDIV) listEnd #eexprBinary
| expr op=(PLUS|MINUS) listEnd #eexprBinary
| expr op=(LSHIFT|RSHIFT) listEnd #eexprBinary
| expr op=RANGE listEnd #eexprBinary
| expr op=REPEAT listEnd #eexprBinary
| expr op=(EQUAL|NEQ) listEnd #eexprBinary
| expr op=(LT|GT|LEQ|GEQ) listEnd #eexprBinary
| expr op=BITAND listEnd #eexprBinary
| expr op=BITXOR listEnd #eexprBinary
| expr op=BITOR listEnd #eexprBinary
| expr op=(LOGAND|LOGANDEXT) listEnd #eexprBinary
| expr op=LOGXOR listEnd #eexprBinary
| expr op=(LOGOR|LOGOREXT) listEnd #eexprBinary
| op=(LOGNOT|BITNOT) eexpr #eexprNot
;

assignment: lvalue ASSIGN list #trueAssignment
| fakeLvalue ASSIGN list #fakeAssignment
;

conditional: IF sequence THEN list #ifthen
| IF sequence THEN sequence ELSE list #ifthenelse
;

listEnd: conditional
| assignment
| whileloop
;

list: expr+
| expr* eexpr
| expr* listEnd
;



// lexer rules

UINT: [0-9]+ { noParams = false; noUnary = true; };

UFLOAT: (((([0-9]* '.' [0-9]+) | ([0-9]+ '.')) 
          (([eE]([-+]?)[0-9]+)?)) |
         ([0-9]+[eE]([-+]?)[0-9]+)) 
        { noParams = false; noUnary = true; };

UPITCH: NOTENAME ACCIDENTAL? [+-]* UINT ([+-]* (UINT|RAT) 't')?
 { noParams = false; noUnary = true; };

fragment NOTENAME: ([a-g]|[A-G]);
fragment ACCIDENTAL: ([#bxdq^v]+);
fragment RAT: UINT '/' [+-]* UINT;

IF: 'if' { noParams = true; noUnary = false; };

THEN: 'then' { noParams = true; noUnary = false; };

ELSE: 'else' { noParams = true; noUnary = false; };

WHILE: 'while' { noParams = true; noUnary = false; };
FOR: 'for' { noParams = true; noUnary = false; };
DO: 'do' { noParams = true; noUnary = false; };
COLLECT: 'collect' { noParams = true; noUnary = false; };

FUNCTION: 'sin' | 'cos' | 'sqrt' { noParams = noUnary = false; };

INLET: '$'[lx][0-9]+ { noParams = false; noUnary = true; };

GLOBALVAR: ID { noParams = false; noUnary = true; };
PATCHERVAR: '#' ID { noParams = false; noUnary = true; };
LOCALVAR: '$' ID { noParams = false; noUnary = true; };
NAMEDPARAM: '@' ID { noParams = true; noUnary = true; };

fragment ID: [a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?;


PUSH: '[' { noParams = true; noUnary = false; };

POP: ']' { noParams = false; noUnary = true; };

CLOSED: ')' { noParams = false; noUnary = true; };

NTH: ':' { noParams = true; noUnary = false; };
PICK: '::' { noParams = true; noUnary = false; };
KEY: '.' { noParams = true; noUnary = false; };

NULLIFY: ';' { noParams = true; noUnary = false; };

ASSIGN: '=' { noParams = true; noUnary = false; };

WHITESPACE: [ \t\r\n] { noParams = true; noUnary = false; } -> channel(HIDDEN);
NEWATOM: [\u0001] { noParams = true; noUnary = false; (*codeac)++; } -> channel(HIDDEN);

POW: '**' { noParams = true; noUnary = false; };

TIMES: '*' { noParams = true; noUnary = false; };

DIVDIV: '//' { noParams = true; noUnary = false; };
DIV: '/' { noParams = true; noUnary = false; };

PLUS: { notUnary() }? '+' { noParams = true; noUnary = false; };
UPLUS: '+' { noParams = true; noUnary = false; };

MINUS: { notUnary() }? '-' { noParams = true; noUnary = false; };
UMINUS: '-' { noParams = true; noUnary = false; };

REM: '%' { noParams = true; noUnary = false; };

EQUAL: '==' { noParams = true; noUnary = false; };

NEQ: '!=' { noParams = true; noUnary = false; };

LOGNOT: '!' { noParams = true; noUnary = false; };

BITNOT: '~' { noParams = true; noUnary = false; };

LT: '<' { noParams = true; noUnary = false; };

GT: '>' { noParams = true; noUnary = false; };

LEQ: '<=' { noParams = true; noUnary = false; };

GEQ: '>=' { noParams = true; noUnary = false; };

BITAND: '&' { noParams = true; noUnary = false; };

BITXOR: '^' { noParams = true; noUnary = false; };

BITOR: '|' { noParams = true; noUnary = false; };

LOGAND: '&&' { noParams = true; noUnary = false; };

LOGANDEXT: '&&&' { noParams = true; noUnary = false; };

LOGXOR: '^^' { noParams = true; noUnary = false; };

LOGOR: '||' { noParams = true; noUnary = false; };

LOGOREXT: '|||' { noParams = true; noUnary = false; };

LSHIFT: '<<' { noParams = true; noUnary = false; };

RSHIFT: '>>' { noParams = true; noUnary = false; };

RANGE: '...' { noParams = true; noUnary = false; };

REPEAT: ':*' { noParams = true; noUnary = false; };

OPEN: { noParams }? '(' { noParams = true; noUnary = false; };
PARAMS: { !noParams }? '(' { noParams = true; noUnary = false; };

ANYTHING: .+?;
