grammar parsetest;

@lexer::members {

    //// MEMBERS

    bool noParams = true;
    bool noUnary = false;
    
    bool followedBySpace() {
        int c = _input->LA(2);
        switch (c) { 
            case ' ':
                return true;
            default:
                return false;
        }
    }

    bool notUnary() {
        return noUnary || followedBySpace();
    }

    //// MEMBERS END
}


// parser rules

program: sequence EOF
;

sequence: (list nullify?)+ 
;

item: NUMBER #itemNumber
| OPEN sequence CLOSED #itemSequence
| funcall #itemFuncall
;

var: VAR
;

lvalueSpecs: (nullify? NTH (item|var|conditional))+
;

lvalue: var lvalueSpecs?
;

fakeLvalue: item lvalueSpecs
;

assignment: (UPLUS|UMINUS)* (lvalue | fakeLvalue) ASSIGN list
;

reference: lvalue | fakeLvalue
;

term: (UPLUS|UMINUS)* item #itemTerm
| (UPLUS|UMINUS)* reference #referenceTerm
;

expression: term (nullify? (PLUS|MINUS) term)* (nullify? (PLUS|MINUS) assignment)?
;

list: (expression | lvalue)+ (assignment | conditional)? #listOther
| assignment #listOnlyAssignment
| conditional #listOnlyConditional
;

funcall: (UPLUS|UMINUS)* FUNCTION PARAMS list CLOSED
;

conditional: (UPLUS|UMINUS)* IF sequence THEN list #ifthen
| (UPLUS|UMINUS)* IF sequence THEN sequence ELSE list #ifthenelse
;

nullify: NULLIFY 
;

// lexer rules


NUMBER: [0-9]+ { std::cout << "number\n"; noParams = false; noUnary = true; };

IF: 'if' { noParams = true; noUnary = false; };

THEN: 'then' { noParams = true; noUnary = false; };

ELSE: 'else' { noParams = true; noUnary = false; };

FUNCTION: 'sin' | 'cos' | 'sqrt' { noParams = noUnary = false; };

VAR: [a-z] { noParams = false; noUnary = true; };

CLOSED: ')' { noParams = false; noUnary = true; };

NTH: ':' { noParams = true; noUnary = false; };

TIMES: '*' { noParams = true; noUnary = false; };

NULLIFY: ';' { noParams = true; noUnary = false; };

ASSIGN: '=' { noParams = true; noUnary = false; };

EOL: '\n' { noParams = true; noUnary = false; };

WHITESPACE: [ \t] { noParams = true; noUnary = false; } -> channel(HIDDEN);

PLUS: { notUnary() }? '+' { printf("plus!\n"); noParams = true; noUnary = false; };
UPLUS: '+' { printf("uplus!\n"); noParams = true; noUnary = false; };

MINUS: { notUnary() }? '-' { noParams = true; noUnary = false; };
UMINUS: '-' { noParams = true; noUnary = false; };

OPEN: { noParams }? '(' { noParams = true; noUnary = false; };
PARAMS: { !noParams }? '(' { noParams = true; noUnary = false; };
