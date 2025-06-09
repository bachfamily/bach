/*
 *  patrons.h
 * (This file has been generated automatically by Doctor Max. You may not want to edit this file directly).
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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

void post_institutional_supporters()
{
	post("- Haute école de musique de Genève - CME");
	post("- IRCAM (Paris)");
}

void post_top_supporters()
{
	post("- Brian Berry");
	post("- Felipe Tovar-Henao");
	post("- Jean-Baptiste Barrière");
	post("- John Crooks");
	post("- Paul V. Miller");
	post("- Sean Ferguson");
	post("- Seidenberg");
	post("- Yan Maresz");
	post("- Yoshiaki Onishi");
}

void post_ordinary_supporters()
{
	post("Alberto Barberis, Alonso Huerta, Anders Tveit, Andrea Nicoli, Andrew Milne, Balint Bolcso, Billy Newman, Bob Falesch, ");
	post("Brian Kirkbride, Brooks, Bruno Schaer, Charles Baker, Chris Chandler, Christopher Lane, Christopher Michael Trapani, ");
	post("DianArpeggio, Diego Torres, Dionysios, Douglas Geers, Erik Halvorsen, Florent Caron Darras, Francisco Colasanto, ");
	post("Gabriel José Bolaños, Graham Hadfield, Gratkowski, Guido, Gustavo Chritaro, Hannes Kerschbaumer, Hans Tutschku, Ishino Hiroaki, ");
	post("Jack Hamill, Jean-Julien Filatriau, Jim Dunn, Joost Van kerkhoven, Jose Miguel Fernandez, Joshua Cook, José Martínez, ");
	post("Julien Vincenot, Kabuki, Kenn Kumpf, Kenneth Stewart, Kobedrums, Kwan Leung LING, Larry Nelson, Laurie Radford, ");
	post("Leonardo Matteucci, Leonid Zvolinsky, Liam Fisher, Ljubomir Nikolic, Lotus Open Factory, Louis Goldford, Luca Morino, ");
	post("Lucie Jones, Luigi Pizzaleo, Marc Garcia Vitoria, Marlon Schumacher, Matias Brizuela, Matthew Goodheart, Matías Rosales, ");
	post("Michael Monhart, Michele Tadini, Nicholas Brown, Nicola Evangelisti, Orjan Sandred, Pierre Alexandre Tremblay, Pierre Relaño, ");
	post("Reso Kiknadze, Robert Appleton, Robert White, Roméo Monteiro, Rubik Ernő Zoltán, Samir Amarouch, Seth, Seth Cluett, ");
	post("Seth Shafer, Solaris, Stefan Lienenkämper, Storyflower, Timothy Roy, Vens R., Viktor Velthuijs, Wolfgang Schnitzer, akio, ");
	post("ignatius, johnmatter, millot, scott mc laughlin, tokaku mushroom.");
}
void post_all_patrons()
{
	post("Alberto Barberis, Alonso Huerta, Anders Tveit, Andrea Nicoli, Andrew Milne, Balint Bolcso, Billy Newman, Bob Falesch, ");
	post("Brian Berry, Brian Kirkbride, Brooks, Bruno Schaer, Charles Baker, Chris Chandler, Christopher Lane, Christopher Michael Trapani, ");
	post("DianArpeggio, Diego Torres, Dionysios, Douglas Geers, Erik Halvorsen, Felipe Tovar-Henao, Florent Caron Darras, ");
	post("Francisco Colasanto, Gabriel José Bolaños, Graham Hadfield, Gratkowski, Guido, Gustavo Chritaro, Hannes Kerschbaumer, ");
	post("Hans Tutschku, Haute école de musique de Genève - CME, Ishino Hiroaki, Jack Hamill, Jean-Baptiste Barrière, ");
	post("Jean-Julien Filatriau, Jim Dunn, John Crooks, Joost Van kerkhoven, Jose Miguel Fernandez, Joshua Cook, José Martínez, ");
	post("Julien Vincenot, Kabuki, Kenn Kumpf, Kenneth Stewart, Kobedrums, Kwan Leung LING, Larry Nelson, Laurie Radford, ");
	post("Leonardo Matteucci, Leonid Zvolinsky, Liam Fisher, Ljubomir Nikolic, Lotus Open Factory, Louis Goldford, Luca Morino, ");
	post("Lucie Jones, Luigi Pizzaleo, Marc Garcia Vitoria, Marlon Schumacher, Matias Brizuela, Matthew Goodheart, Matías Rosales, ");
	post("Michael Monhart, Michele Tadini, Nicholas Brown, Nicola Evangelisti, Orjan Sandred, Paul V. Miller, Pierre Alexandre Tremblay, ");
	post("Pierre Relaño, Reso Kiknadze, Robert Appleton, Robert White, Roméo Monteiro, Rubik Ernő Zoltán, Samir Amarouch, ");
	post("Sean Ferguson, Seidenberg, Seth, Seth Cluett, Seth Shafer, Solaris, Stefan Lienenkämper, Storyflower, Timothy Roy, Vens R., ");
	post("Viktor Velthuijs, Vinet, Wolfgang Schnitzer, Yan Maresz, Yoshiaki Onishi, akio, ignatius, johnmatter, millot, scott mc laughlin, ");
	post("tokaku mushroom, ");
}
