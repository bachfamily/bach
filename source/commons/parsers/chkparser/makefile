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

chkparser install:	chkparser.l
			/usr/local/opt/flex/bin/flex --version
			/usr/local/opt/flex/bin/flex -o chkparser.c chkparser.l 
			egrep -v "^#line" chkparser.c >bach_chkparser.c
						
clean:		
			rm -f chkparser.c
			rm -f bach_chkparser.c
			
