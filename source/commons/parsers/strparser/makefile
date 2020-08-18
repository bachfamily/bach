# /*
# *  makefile
# *
# * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
# *
# * This program is free software: you can redistribute it and/or modify it
# * under the terms of the GNU General Public License
# * as published by the Free Software Foundation,
# * either version 3 of the License, or (at your option) any later version.
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# * See the GNU General Public License for more details.
# * You should have received a copy of the GNU General Public License
# * along with this program.
# * If not, see <https://www.gnu.org/licenses/>.
# *
# */

strparser install:	strparser.l
			/usr/local/opt/bison/bin/bison --version
			/usr/local/opt/flex/bin/flex --version
			/usr/local/opt/bison/bin/bison -d strparser.y
			/usr/local/opt/flex/bin/flex -L -o strparser.c strparser.l
			egrep -v "^#line" strparser.c >bach_strparser.c
			egrep -v "^#line" strparser.lex.h >bach_strparser_lex.h
			egrep -v "^#line" strparser.tab.c >bach_strparser_tab.c
			egrep -v "^#line" strparser.tab.h >bach_strparser_tab.h
			
						
clean:		
			rm -f ../strparser.c
			rm -f strparser.tab.c
			rm -f strparser.tab.h
			rm -f strparser.lex.h
			rm -f bach_strparser.c
			rm -f bach_strparser_lex.h
			rm -f bach_strparser_tab.c
			rm -f bach_strparser_tab.h
			
