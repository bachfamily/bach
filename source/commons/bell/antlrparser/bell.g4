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
        post("noUnary %d\n", noUnary);
        post("fbs %d\n", followedBySpace());
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
;

sequence: list
| nullified+ list? 
;

nullified: list NULLIFY+
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

expr: expr POW expr #exprPow 
| (UPLUS|UMINUS)* item #exprUnary
| (UPLUS|UMINUS)* var #exprVar
| expr op=(TIMES|DIV|DIVDIV) expr #exprTimesDiv
| expr op=(PLUS|MINUS) expr #exprPlusMinus
| {!ending}? (UPLUS|UMINUS)* lvalue #exprLvalue
| {!ending}? (UPLUS|UMINUS)* fakeLvalue #exprFakeLvalue
;

eexpr: expr POW listEnd #eexprPow 
| (UPLUS|UMINUS)* listEnd #eexprUnary
| expr op=(TIMES|DIV|DIVDIV) listEnd #eexprTimesDiv
| expr op=(PLUS|MINUS) listEnd #eexprPlusMinus
| {ending}? (UPLUS|UMINUS)* lvalue #eexprLvalue
| {ending}? (UPLUS|UMINUS)* fakeLvalue #eexprFakeLvalue
;

assignment: lvalue ASSIGN list #trueAssignment
| fakeLvalue ASSIGN list #fakeAssignment
;

conditional: IF sequence THEN list #ifthen
| IF sequence THEN sequence ELSE list #ifthenelse
;

listEnd: conditional
| assignment
;

list: expr+
| expr* eexpr
| expr* listEnd
;



// lexer rules

UINT: [0-9]+ { std::cout << "UINT\n"; noParams = false; noUnary = true; };

UFLOAT: (((([0-9]* '.' [0-9]+) | ([0-9]+ '.')) 
          (([eE]([-+]?)[0-9]+)?)) |
         ([0-9]+[eE]([-+]?)[0-9]+)) 
        { std::cout << "UFLOAT\n"; noParams = false; noUnary = true; };

UPITCH: NOTENAME ACCIDENTAL? [+-]* UINT ([+-]* (UINT|RAT) 't')?
 { std::cout << "PITCH\n"; noParams = false; noUnary = true; };

fragment NOTENAME: ([a-g]|[A-G]);
fragment ACCIDENTAL: ([#bxdq^v]+);
fragment RAT: UINT '/' [+-]* UINT;

IF: 'if' { noParams = true; noUnary = false; };

THEN: 'then' { noParams = true; noUnary = false; };

ELSE: 'else' { noParams = true; noUnary = false; };

FOR: 'for' { noParams = true; noUnary = false; };

DO: 'do' { noParams = true; noUnary = false; };

FUNCTION: 'sin' | 'cos' | 'sqrt' { noParams = noUnary = false; };

INLET: '$'[lx][0-9]+ { noParams = false; noUnary = true; };

GLOBALVAR: [a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])? { noParams = false; noUnary = true; };
PATCHERVAR: '#'[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])? { noParams = false; noUnary = true; };
LOCALVAR: '$'[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])? { noParams = false; noUnary = true; };


PUSH: '[' { noParams = true; noUnary = false; };

POP: ']' { noParams = false; noUnary = true; };

CLOSED: ')' { noParams = false; noUnary = true; };

NTH: ':' { noParams = true; noUnary = false; };

KEY: '.' { noParams = true; noUnary = false; };

NULLIFY: ';' { noParams = true; noUnary = false; };

ASSIGN: '=' { noParams = true; noUnary = false; };

WHITESPACE: [ \t\r\n] { noParams = true; noUnary = false; } -> channel(HIDDEN);
NEWATOM: [\u0001] { noParams = true; noUnary = false; (*codeac)++; } -> channel(HIDDEN);

POW: '**' { noParams = true; noUnary = false; };

TIMES: '*' { noParams = true; noUnary = false; };

DIVDIV: '//' { noParams = true; noUnary = false; };
DIV: '/' { noParams = true; noUnary = false; };

PLUS: { notUnary() }? '+' { post("plus!\n"); noParams = true; noUnary = false; };
UPLUS: '+' { post("uplus!\n"); noParams = true; noUnary = false; };

MINUS: { notUnary() }? '-' { post("minus!\n"); noParams = true; noUnary = false; };
UMINUS: '-' { post("uminus!\n"); noParams = true; noUnary = false; };

OPEN: { noParams }? '(' { noParams = true; noUnary = false; };
PARAMS: { !noParams }? '(' { noParams = true; noUnary = false; };
