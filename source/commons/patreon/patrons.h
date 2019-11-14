/*
 *  patrons.h
 * (This file has been generated automatically by Doctor Max. You may not want to edit this file directly).
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 @file    patrons.h
 @brief    Code to post current patrons
 */

#include "ext.h"

void post_top_supporters()
{
	post("- Francisco Colasanto");
	post("- Jean-Baptiste Barrière");
	post("- Julien Vincenot");
	post("- Michele Zaccagnini");
	post("- Seidenberg");
	post("- Yan Maresz");
}

void post_all_patrons()
{
	post("Alessandro Ratoci, audiophil, Chris Chandler, Chris Poovey, Christopher Michael Trapani, Daniel Lujan, Francisco Colasanto, ");
	post("Hans Leeuw, Hans Tutschku, Jean-Baptiste Barrière, Jean-Julien Filatriau, Joost Van kerkhoven, Julien Vincenot, linazero, ");
	post("Louis Goldford, Matthew Goodheart, Michele Zaccagnini, Nikola Kołodziejczyk, Pierre Alexandre Tremblay, Seidenberg, Tj Shredder, ");
	post("Tomislav Oliver, Vens R., Viktor Velthuijs, Yan Maresz.");
}
