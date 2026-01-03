grammar pitch;



pch: NOTENAME ACCIDENTAL? (UPLUS|UMINUS)* UINT dev? EOF;

dev: ((UPLUS|UMINUS)* UINT) 't' #devInt
| ((UPLUS|UMINUS)* urat) 't' #devRat
;

urat: UINT '/' (UPLUS|UMINUS)* UINT
;

UINT: [0-9]+;

NOTENAME: ([a-g]|[A-G]);
ACCIDENTAL: ([#bxdq^v]+);

UPLUS: '+';
UMINUS: '-';