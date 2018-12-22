/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:19:24 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:25 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursCat.hpp"

NcursCat::NcursCat() : _posy(0), _posx(0) {}
NcursCat::NcursCat(int	y, int x) : _posy(y), _posx(x) {}
NcursCat::NcursCat(NcursCat const & obj)	{	*this = obj;	}
NcursCat::~NcursCat() {}

void	drawRainbow(int posy, int posx, int color)
{
	attron(COLOR_PAIR(color));
	mvwprintw(stdscr, posy + 1, posx, "          ");
	mvwprintw(stdscr, posy + 2, posx, "          ");
	mvwprintw(stdscr, posy, posx + 10, "          ");
	mvwprintw(stdscr, posy + 1, posx + 10, "          ");
	mvwprintw(stdscr, posy + 1, posx + 20, "          ");
	mvwprintw(stdscr, posy + 2, posx + 20, "          ");
	mvwprintw(stdscr, posy, posx + 30, "          ");
	mvwprintw(stdscr, posy + 1, posx + 30, "          ");
}

void	drawCandy(int posy, int posx)
{
	attron(COLOR_PAIR(17));
	for (int y = posy; y < 14 + posy; y++)
		mvwprintw(stdscr, y, posx, "                                          ");
	attron(COLOR_PAIR(18));
	for (int y = posy + 1; y < 13 + posy; y++)
		mvwprintw(stdscr, y, posx + 2, "                                      ");
	attron(COLOR_PAIR(17));
	mvwprintw(stdscr, posy + 1, posx + 2, "  ");
	mvwprintw(stdscr, posy + 12, posx + 2, "  ");
	mvwprintw(stdscr, posy + 1, posx + 38, "  ");
	attron(COLOR_PAIR(16));
	mvwprintw(stdscr, posy + 3, posx + 6, "  ");
	mvwprintw(stdscr, posy + 2, posx + 16, "  ");
	mvwprintw(stdscr, posy + 2, posx + 24, "  ");
	mvwprintw(stdscr, posy + 6, posx + 8, "  ");
	mvwprintw(stdscr, posy + 8, posx + 4, "  ");
	mvwprintw(stdscr, posy + 7, posx + 12, "  ");
	mvwprintw(stdscr, posy + 10, posx + 10, "  ");
}

void	drawHead(int posy, int posx)
{
	attron(COLOR_PAIR(15)); //gray head
	mvwprintw(stdscr, posy, posx + 2, "    ");
	mvwprintw(stdscr, posy, posx + 24, "    ");
	mvwprintw(stdscr, posy + 1, posx + 2, "      ");
	mvwprintw(stdscr, posy + 1, posx + 22, "      ");
	mvwprintw(stdscr, posy + 2, posx + 2, "        ");
	mvwprintw(stdscr, posy + 2, posx + 20, "        ");
	mvwprintw(stdscr, posy + 3, posx + 2, "                          ");
	mvwprintw(stdscr, posy + 4, posx, "                              ");
	mvwprintw(stdscr, posy + 5, posx, "                              ");
	mvwprintw(stdscr, posy + 6, posx, "                              ");
	mvwprintw(stdscr, posy + 7, posx, "                              ");
	mvwprintw(stdscr, posy + 8, posx + 2, "                          ");
	mvwprintw(stdscr, posy + 9, posx + 4, "                      ");
	attron(COLOR_PAIR(18)); //pink chiks
	mvwprintw(stdscr, posy + 6, posx + 2, "    ");
	mvwprintw(stdscr, posy + 7, posx + 2, "    ");
	mvwprintw(stdscr, posy + 6, posx + 26, "    ");
	mvwprintw(stdscr, posy + 7, posx + 26, "    ");
	attron(COLOR_PAIR(22)); // white eyes
	mvwprintw(stdscr, posy + 4, posx + 6, "  ");
	mvwprintw(stdscr, posy + 4, posx + 22, "  ");
	attroff(COLOR_PAIR(22)); // black cover
	mvwprintw(stdscr, posy - 1, posx + 2, "    ");
	mvwprintw(stdscr, posy - 1, posx + 24, "    ");
	mvwprintw(stdscr, posy - 1, posx + 20, "  ");
	mvwprintw(stdscr, posy, posx, "  ");
	mvwprintw(stdscr, posy, posx + 6, "  ");
	mvwprintw(stdscr, posy, posx + 20, "    ");
	mvwprintw(stdscr, posy, posx + 28, "  ");
	mvwprintw(stdscr, posy + 1, posx, "  ");
	mvwprintw(stdscr, posy + 1, posx + 8, "  ");
	mvwprintw(stdscr, posy + 1, posx + 20, "  ");
	mvwprintw(stdscr, posy + 1, posx + 28, "  ");
	mvwprintw(stdscr, posy + 2, posx, "  ");
	mvwprintw(stdscr, posy + 2, posx + 10, "          ");
	mvwprintw(stdscr, posy + 2, posx + 28, "  ");
	mvwprintw(stdscr, posy + 3, posx, "  ");
	mvwprintw(stdscr, posy + 3, posx + 28, "  ");
	mvwprintw(stdscr, posy + 4, posx - 2, "  ");
	mvwprintw(stdscr, posy + 4, posx + 8, "  ");
	mvwprintw(stdscr, posy + 4, posx + 24, "  ");
	mvwprintw(stdscr, posy + 4, posx + 30, "  ");
	mvwprintw(stdscr, posy + 5, posx - 2, "  ");
	mvwprintw(stdscr, posy + 5, posx + 6, "    ");
	mvwprintw(stdscr, posy + 5, posx + 16, "  ");
	mvwprintw(stdscr, posy + 5, posx + 22, "    ");
	mvwprintw(stdscr, posy + 5, posx + 30, "  ");
	mvwprintw(stdscr, posy + 6, posx - 2, "  ");
	mvwprintw(stdscr, posy + 6, posx + 30, "  ");
	mvwprintw(stdscr, posy + 7, posx - 2, "  ");
	mvwprintw(stdscr, posy + 7, posx + 8, "  ");
	mvwprintw(stdscr, posy + 7, posx + 14, "  ");
	mvwprintw(stdscr, posy + 7, posx + 20, "  ");
	mvwprintw(stdscr, posy + 7, posx + 30, "  ");
	mvwprintw(stdscr, posy + 8, posx, "  ");
	mvwprintw(stdscr, posy + 8, posx + 8, "              ");
	mvwprintw(stdscr, posy + 8, posx + 28, "  ");
	mvwprintw(stdscr, posy + 9, posx + 2, "  ");
	mvwprintw(stdscr, posy + 9, posx + 26, "  ");
}

void	drawCover(int posy, int posx)
{
	mvwprintw(stdscr, posy, posx + 4, "                                      ");
	mvwprintw(stdscr, posy + 1, posx + 2, "  ");
	mvwprintw(stdscr, posy + 1, posx + 42, "  ");
	mvwprintw(stdscr, posy + 2, posx, "  ");
	mvwprintw(stdscr, posy + 2, posx + 44, "  ");
	mvwprintw(stdscr, posy + 3, posx + 44, "  ");
	for (int y = 3; y < 14; y++)
		mvwprintw(stdscr, posy + y, posx, "  ");
	mvwprintw(stdscr, posy + 14, posx + 2, "  ");
	mvwprintw(stdscr, posy + 15, posx + 4, "                                              ");
}

void	drawAnime(int posy, int posx)
{
	if (rand() & 1)
	{
		mvwprintw(stdscr, posy, posx + 2, "    ");
		mvwprintw(stdscr, posy + 1, posx, "  ");
		mvwprintw(stdscr, posy + 1, posx + 6, "  ");
		mvwprintw(stdscr, posy + 2, posx, "  ");
		mvwprintw(stdscr, posy + 2, posx + 6, "      ");
		mvwprintw(stdscr, posy + 3, posx + 2, "  ");
		mvwprintw(stdscr, posy + 4, posx + 4, "    ");
		mvwprintw(stdscr, posy + 5, posx + 8, "    ");
		mvwprintw(stdscr, posy + 7, posx + 10, "  "); // legs
		mvwprintw(stdscr, posy + 8, posx + 8, "  ");
		mvwprintw(stdscr, posy + 9, posx + 6, "  ");
		mvwprintw(stdscr, posy + 9, posx + 14, "  ");
		mvwprintw(stdscr, posy + 10, posx + 6, "  ");
		mvwprintw(stdscr, posy + 10, posx + 12, "  ");
		mvwprintw(stdscr, posy + 10, posx + 16, "  ");
		mvwprintw(stdscr, posy + 10, posx + 22, "  ");
		mvwprintw(stdscr, posy + 10, posx + 42, "  ");
		mvwprintw(stdscr, posy + 10, posx + 48, "  ");
		mvwprintw(stdscr, posy + 10, posx + 52, "  ");
		mvwprintw(stdscr, posy + 10, posx + 58, "  ");
		mvwprintw(stdscr, posy + 11, posx + 6, "      ");
		mvwprintw(stdscr, posy + 11, posx + 16, "      ");
		mvwprintw(stdscr, posy + 11, posx + 42, "      ");
		mvwprintw(stdscr, posy + 11, posx + 52, "      ");
		attron(COLOR_PAIR(15)); // grey
		mvwprintw(stdscr, posy + 1, posx + 2, "    ");
		mvwprintw(stdscr, posy + 2, posx + 2, "    ");
		mvwprintw(stdscr, posy + 3, posx + 4, "        ");
		mvwprintw(stdscr, posy + 4, posx + 8, "    ");
		mvwprintw(stdscr, posy + 8, posx + 10, "    ");
		mvwprintw(stdscr, posy + 9, posx + 8, "      ");
		mvwprintw(stdscr, posy + 10, posx + 8, "    ");
		mvwprintw(stdscr, posy + 10, posx + 18, "    ");
		mvwprintw(stdscr, posy + 10, posx + 44, "    ");
		mvwprintw(stdscr, posy + 10, posx + 54, "    ");
	}
	else
	{
		mvwprintw(stdscr, posy + 2, posx + 8, "    ");
		mvwprintw(stdscr, posy + 3, posx + 4, "    ");
		mvwprintw(stdscr, posy + 4, posx + 2, "  ");
		mvwprintw(stdscr, posy + 4, posx + 10, "  ");
		mvwprintw(stdscr, posy + 5, posx + 2, "  ");
		mvwprintw(stdscr, posy + 5, posx + 8, "  ");
		mvwprintw(stdscr, posy + 6, posx + 4, "    ");
		mvwprintw(stdscr, posy + 8, posx + 10, "  "); // legs
		mvwprintw(stdscr, posy + 9, posx + 8, "  ");
		mvwprintw(stdscr, posy + 10, posx + 8, "  ");
		mvwprintw(stdscr, posy + 10, posx + 14, "  ");
		mvwprintw(stdscr, posy + 10, posx + 18, "  ");
		mvwprintw(stdscr, posy + 10, posx + 24, "  ");
		mvwprintw(stdscr, posy + 10, posx + 44, "  ");
		mvwprintw(stdscr, posy + 10, posx + 50, "  ");
		mvwprintw(stdscr, posy + 10, posx + 54, "  ");
		mvwprintw(stdscr, posy + 10, posx + 60, "  ");
		mvwprintw(stdscr, posy + 11, posx + 10, "      ");
		mvwprintw(stdscr, posy + 11, posx + 20, "      ");
		mvwprintw(stdscr, posy + 11, posx + 46, "      ");
		mvwprintw(stdscr, posy + 11, posx + 56, "      ");
		attron(COLOR_PAIR(15));
		mvwprintw(stdscr, posy + 3, posx + 8, "    ");
		mvwprintw(stdscr, posy + 4, posx + 4, "      ");
		mvwprintw(stdscr, posy + 5, posx + 4, "    ");
		mvwprintw(stdscr, posy + 8, posx + 12, "  ");
		mvwprintw(stdscr, posy + 9, posx + 10, "      ");
		mvwprintw(stdscr, posy + 10, posx + 10, "    ");
		mvwprintw(stdscr, posy + 10, posx + 20, "    ");
		mvwprintw(stdscr, posy + 10, posx + 46, "    ");
		mvwprintw(stdscr, posy + 10, posx + 56, "    ");
	}
}

void	NcursCat::nyanCat()
{
	attron(COLOR_PAIR(12)); //Background
	for (int y = _posy; y < 27 + _posy; y++)
		mvwprintw(stdscr, y, _posx, "                                                                                                                    ");

	drawRainbow(_posy + 5, _posx, 13); //Rainbow
	drawRainbow(_posy + 7, _posx, 14);
	drawRainbow(_posy + 9, _posx, 17);
	drawRainbow(_posy + 11, _posx, 11);
	drawRainbow(_posy + 13, _posx, 19);
	drawRainbow(_posy + 15, _posx, 16);

	drawCandy(_posy + 4, _posx + 42);
	drawHead(_posy + 8, _posx + 64);
	drawCover(_posy + 3, _posx + 40);
	drawAnime(_posy + 9, _posx + 28);
}

NcursCat &	NcursCat::operator=(NcursCat const & obj)
{
	_posy = obj._posy;
	_posx = obj._posx;
	return *this;
}
