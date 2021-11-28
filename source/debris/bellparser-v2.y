program: clause
;

item: number
| symbol
| clause
| OPEN clause CLOSED
| PUSH clause POP
; // produces evaluation

value: item
| variable
; // produces evaluation 

lvalue: variable 
| lvalue NTH value
| lvalue DOT value
; // gather everything in an n-ary lvalue (necessary for use as lvalue)
// produces reference

fakelvalue: item DOT value
| item NTH value
| fakelvalue DOT value
| fakelvalue NTH value
; // gather everything in an n-ary richlvalue (necessary for use as lvalue)
// produces reference

rvalue: item
| lvalue // converts reference into evaluation
| fakelvalue // converts reference into evaluation
; // produces evaluation

product: rvalue
| product TIMES rvalue
| product DIV rvalue
| product DIVDIV rvalue
| product REM rvalue
;

sum: product
| sum PLUS product
| sum MINUS product
; // optionally: gather everything in an n-ary sum

shift: sum
| shift LSHIFT product
| shift RSHIFT product
;

range: shift
| range SHIFT range
;

repetition: range
| repetition REPEAT range
;

equality: repetition EQ repetition
| equality EQ repetition
; // optionally: gather everything in an n-ary equality

nonequality: repetition NEQ repetition
| nonequality NEQ repetition
;

less: repetition LT repetition
| repetition LEQ repetition
| less LT repetition
| less LEQ repetition
; // optionally: gather everything in an n-ary inequality

greater: repetition GT repetition
| repetition LEQ repetition
| greater GT repetition
| greater GEQ repetition
; // optionally: gather everything in an n-ary inequality

comparison: equality
| nonequality
| less
| greater
;

bitand: repetition
| comparison
| bitand BITAND comparison
;

bitxor: bitand
| bitxor BITXOR bitand
;

bitor: bitxor
| bitor BITOR bitxor
;

logand: bitor
| logand LOGAND bitor
| logand LOGANDEXT bitor
;

logxor: logand
| logxor LOGAND logand
| logxor LOGANDEXT logand
;

logor: logxor
| logor LOGOR logxor
| logor LOGOREXT logxor
;

simpleexpr: logor
;

chain: simpleexpr
| chain simpleexpr
; // optionally: gather everything in an n-ary chain

function: funargs LIFT liftedargs FUNDEF chain

assignable: chain
| function
;

// with right-associativity:
assignment: lvalue ASSIGN assignable
| assignment ASSIGN assignable
| assignment AOP assignable
;

nofake: assignable
| assignment
;

fakeassignment: richlvalue ASSIGN nofake
| richlvalue AOP nofake
;

forloop: FOR forarglist DO allstuff
; // or all the other variants

whileloop: WHILE sequence DO allstuff
; // or all the other variants

if: IF sequence THEN allstuff
; 

allstuff: nofake
| fakeassignment
| forloop
| whileloop
| if
;

clause: allstuff
| clause NULLIFY
;











