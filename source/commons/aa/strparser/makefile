strparser:	strparser.l
			/opt/local/bin/bison --version
			/opt/local/bin/flex --version
			/opt/local/bin/bison -d strparser.y
			/opt/local/bin/flex -o strparser.c strparser.l 
			
						
clean:		
			rm -f strparser.c
			rm -f strparser.tab.c
			rm -f strparser.tab.h
			