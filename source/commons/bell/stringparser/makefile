# /*
# *  makefile
# *
# * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

stringparser install:	stringparser.l
		if [ -d "/opt/homebrew/opt/" ]; then\
			/opt/homebrew/opt/bison/bin/bison --version;\
			/opt/homebrew/opt/flex/bin/flex --version;\
			/opt/homebrew/opt/bison/bin/bison -d stringparser.y;\
			/opt/homebrew/opt/flex/bin/flex -L -o stringparser.c stringparser.l;\
		else\
			/usr/local/opt/bison/bin/bison --version;\
			/usr/local/opt/flex/bin/flex --version;\
			/usr/local/opt/bison/bin/bison -d stringparser.y;\
			/usr/local/opt/flex/bin/flex -L -o stringparser.c stringparser.l;\
		fi;
		
		egrep -v "^#line" stringparser.c >stringparser_nolines.c
		egrep -v "^#line" stringparser.lex.h >stringparser_lex_nolines.h
		egrep -v "^#line" stringparser.tab.c >stringparser_tab_nolines.c
		egrep -v "^#line" stringparser.tab.h >stringparser_tab_nolines.h
clean:		
			rm -f stringparser.c
			rm -f stringparser_nolines.c
			rm -f stringparser.tab.c
			rm -f stringparser_tab_nolines.c
			rm -f stringparser.tab.h
			rm -f stringparser_tab_nolines.h
			rm -f stringparser.lex.h
			rm -f stringparser_lex_nolines.h
