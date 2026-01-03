# /*
# *  makefile
# *
# * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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

bisonparserV3 install:	bisonparserV3.l
		if [ -d "/opt/homebrew/opt/" ]; then\
			/opt/homebrew/opt/bison/bin/bison --version;\
			/opt/homebrew/opt/flex/bin/flex --version;\
			/opt/homebrew/opt/bison/bin/bison -d bisonparserV3.y;\
			/opt/homebrew/opt/flex/bin/flex -L -o bisonparserV3.c bisonparserV3.l;\
		else\
			/usr/local/opt/bison/bin/bison --version;\
			/usr/local/opt/flex/bin/flex --version;\
			/usr/local/opt/bison/bin/bison -d bisonparserV3.y;\
			/usr/local/opt/flex/bin/flex -L -o bisonparserV3.c bisonparser-b3.l;\
		fi;
		
		egrep -v "^#line" bisonparserV3.c >bisonparserV3_nolines.c
		egrep -v "^#line" bisonparserV3.lex.h >bisonparserV3_lex_nolines.h
		egrep -v "^#line" bisonparserV3.tab.c >bisonparserV3_tab_nolines.c
		egrep -v "^#line" bisonparserV3.tab.h >bisonparserV3_tab_nolines.h
clean:
			rm -f bisonparserV3.c
			rm -f bisonparserV3_nolines.c
			rm -f bisonparserV3.tab.c
			rm -f bisonparserV3_tab_nolines.c
			rm -f bisonparserV3.tab.h
			rm -f bisonparserV3_tab_nolines.h
			rm -f bisonparserV3.lex.h
			rm -f bisonparserV3_lex_nolines.h
