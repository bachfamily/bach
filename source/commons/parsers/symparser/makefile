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

symparser install:	symparser.l
			/usr/local/opt/bison/bin/bison --version
			/usr/local/opt/flex/bin/flex --version
			/usr/local/opt/bison/bin/bison -ld symparser.y
			/usr/local/opt/flex/bin/flex -L -o symparser.c symparser.l
			egrep -v "^#line" symparser.c >bach_symparser.c
			egrep -v "^#line" symparser.lex.h >bach_symparser_lex.h
			egrep -v "^#line" symparser.tab.c >bach_symparser_tab.c
			egrep -v "^#line" symparser.tab.h >bach_symparser_tab.h
			
clean:		
			rm -f symparser.c
			rm -f symparser.tab.c
			rm -f symparser.tab.h
			rm -f symparser.lex.h
			rm -f bach_symparser.c
			rm -f bach_symparser_lex.h
			rm -f bach_symparser_tab.c
			rm -f bach_symparser_tab.h
			
