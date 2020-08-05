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

exprparser install:	exprparser.l
			/usr/local/opt/bison/bin/bison --version
			/usr/local/opt/flex/bin/flex --version
			/usr/local/opt/flex/bin/flex -L -o exprparser.c exprparser.l
			egrep -v "^#line" exprparser.c >bach_exprparser.c
			egrep -v "^#line" exprparser.lex.h >bach_exprparser_lex.h
						
clean:		
			rm -f exprparser.c
			rm -f exprparser.tab.c
			rm -f exprparser.tab.h
			rm -f exprparser.lex.h
			rm -f bach_exprparser.c
			rm -f bach_exprparser_lex.h
