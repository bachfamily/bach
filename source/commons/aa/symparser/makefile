symparser:	symparser.l
			/opt/local/bin/bison --version
			/opt/local/bin/flex --version
			/opt/local/bin/bison -d symparser.y
			/opt/local/bin/flex -o symparser.c symparser.l
			
clean:		
			rm -f symparser.c
			rm -f symparser.tab.c
			rm -f symparser.tab.h
			rm -f symparser.lex.h