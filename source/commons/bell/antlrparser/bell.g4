grammar bell;

@lexer::header { 
#include "ext.h" 
}

@lexer::members {

    //// MEMBERS

    bool noParams = true;
    bool noUnary = false;
    
    bool followedBySpace() {
        int c = _input->LA(2);
        post("\c", c);
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

    //// MEMBERS END
}

@parser::members { 
    
    bool ending = false;

}


// parser rules

program: sequence EOF
;

sequence: list
| nullified+ list? 
;

nullified: list NULLIFY+
;

funcall: FUNCTION PARAMS sequence CLOSED
;

item: NUMBER #itemNumber
| OPEN sequence CLOSED #itemSequence
| PUSH sequence POP #itemSublist
| funcall #itemFuncall
;

var: VAR
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
| expr TIMES expr #exprTimes
| expr PLUS expr #exprPlus
| {!ending}? lvalue #exprLvalue
| {!ending}? fakeLvalue #exprFakeLvalue
;

eexpr: expr POW listEnd #eexprPow 
| (UPLUS|UMINUS)* listEnd #eexprUnary
| expr TIMES listEnd #eexprTimes
| expr PLUS listEnd #eexprPlus
| {ending}? lvalue #eexprLvalue
| {ending}? fakeLvalue #eexprFakeLvalue
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

NUMBER: [0-9]+ { std::cout << "number\n"; noParams = false; noUnary = true; };

IF: 'if' { noParams = true; noUnary = false; };

THEN: 'then' { noParams = true; noUnary = false; };

ELSE: 'else' { noParams = true; noUnary = false; };

FOR: 'for' { noParams = true; noUnary = false; };

DO: 'do' { noParams = true; noUnary = false; };

FUNCTION: 'sin' | 'cos' | 'sqrt' { noParams = noUnary = false; };

VAR: [a-z] { noParams = false; noUnary = true; };

PUSH: '[' { noParams = true; noUnary = false; };

POP: ']' { noParams = false; noUnary = true; };

CLOSED: ')' { noParams = false; noUnary = true; };

NTH: ':' { noParams = true; noUnary = false; };

KEY: '.' { noParams = true; noUnary = false; };

NULLIFY: ';' { noParams = true; noUnary = false; };

ASSIGN: '=' { noParams = true; noUnary = false; };

EOL: '\n' { noParams = true; noUnary = false; };

WHITESPACE: [ \t\u0001] { noParams = true; noUnary = false; } -> channel(HIDDEN);

POW: '**' { noParams = true; noUnary = false; };

TIMES: '*' { noParams = true; noUnary = false; };

PLUS: { notUnary() }? '+' { post("plus!\n"); noParams = true; noUnary = false; };
UPLUS: '+' { post("uplus!\n"); noParams = true; noUnary = false; };

MINUS: { notUnary() }? '-' { post("minus!\n"); noParams = true; noUnary = false; };
UMINUS: '-' { post("uminus!\n"); noParams = true; noUnary = false; };

OPEN: { noParams }? '(' { noParams = true; noUnary = false; };
PARAMS: { !noParams }? '(' { noParams = true; noUnary = false; };
