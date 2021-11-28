install:
	bison -ld --verbose -Wcounterexamples parsetest06.y
	flex -L -o parsetest.c lextest01.l
	gcc -lfl -o parsetest parsetest06.tab.c parsetest.c
