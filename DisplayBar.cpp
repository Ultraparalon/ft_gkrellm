/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayBar.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:03:09 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 15:03:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayBar.hpp"

DisplayBar::DisplayBar() {}
DisplayBar::DisplayBar(DisplayBar const &) {}
DisplayBar::~DisplayBar() {}

static void	initColor()
{
    start_color();
    init_pair(1, 8, COLOR_BLACK);
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(20, COLOR_BLUE, COLOR_BLACK);
    init_pair(30, COLOR_RED, COLOR_BLACK);
    init_pair(40, COLOR_CYAN, COLOR_BLACK);
    init_pair(11, COLOR_BLACK, COLOR_GREEN);
    init_pair(12, COLOR_BLACK, COLOR_BLUE);
    init_pair(13, COLOR_BLACK, COLOR_RED);
    init_pair(14, COLOR_BLACK, COLOR_CYAN);
    init_pair(15, COLOR_BLACK, 8); //dark gray
    init_pair(16, COLOR_BLACK, 54); //purle
    init_pair(17, COLOR_BLACK, 3); //yellow
    init_pair(18, COLOR_BLACK, 9); //pink
    init_pair(19, COLOR_BLACK, 12); //light blue
    init_pair(21, COLOR_BLACK, 7); //light blue
    init_pair(22, COLOR_BLACK, COLOR_WHITE); //white
    init_pair(2, 8, 8);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, 167, COLOR_BLACK);
    init_pair(5, 28, COLOR_BLACK);
    init_pair(6, 160, COLOR_BLACK);
}

void	DisplayBar::init()
{
	initscr();
	curs_set(0);
	noecho();
	initColor();
}

static void	input()
{
	int ch = getch();

	switch (ch) {
		case '1':	init_pair(12, COLOR_BLACK, COLOR_BLUE);		break;
		case '2':	init_pair(12, COLOR_BLACK, COLOR_GREEN);	break;
		case '3':	init_pair(12, COLOR_BLACK, COLOR_RED);		break;
		case '4':	init_pair(12, COLOR_BLACK, 3);				break;
		case '5':	init_pair(12, COLOR_BLACK, 54);				break;
		case '6':	init_pair(12, COLOR_BLACK, 53);				break;
		case '7':	init_pair(12, COLOR_BLACK, 12);				break;
		case '8':	init_pair(12, COLOR_BLACK, COLOR_MAGENTA);	break;
		case '9':	init_pair(12, COLOR_BLACK, 8);				break;
		case '0':	init_pair(12, COLOR_BLACK, COLOR_WHITE);	break;
		case 'q':
				endwin();
				exit(0);
				break;
	}
}

static void	drawBorders()
{
	attron(COLOR_PAIR(12));
	for (int y = 0; y <= 16; y++)
		for (int x = 0; x <= 115; x++)
		{
			if (y == 0 || x == 0 || x == 115 || y == 16)
			mvaddch(y, x, ' ');
		}
	attroff(COLOR_PAIR(12));
}

static void	drawBar(int y, int x, int val)
{
	attron(COLOR_PAIR(15));
	mvwprintw(stdscr, y, x, "                                                                                                    ");
	attron(COLOR_PAIR(11));
	for (int i = 0; i < val; i++)
		mvaddch(y, x + i, ' ');
	attroff(COLOR_PAIR(11));
}

static void	drawBar(int y, int x, int val, int val2)
{
	attron(COLOR_PAIR(15));
	mvwprintw(stdscr, y, x, "                                                                                                    ");
	for (int i = 0; i < 100; i++)
		mvaddch(y, x + i, ' ');
	attron(COLOR_PAIR(11));
	for (int i = 0; i < val; i++)
		mvaddch(y, x + i, ' ');
	attron(COLOR_PAIR(17));
	for (int i = val; val2; i++, val2--)
		mvaddch(y, x + i, ' ');
	attroff(COLOR_PAIR(17));
}

void	DisplayBar::render()
{
	NcursCat	nya(17, 0);

	IMonitorModule * cpuInfo = new ModuleCPUInfo();
	IMonitorModule * cpuUsage = new ModuleCPUUsage();
	IMonitorModule * ramUsage = new ModuleRAMUsage();
	IMonitorModule * host = new ModuleHost();
	IMonitorModule * network = new ModuleNetwork();
	IMonitorModule * osInfo = new ModuleOSInfo();
	IMonitorModule * time = new ModuleTime();

	std::vector<std::string> const * vec_cpuInfo = cpuInfo->getData();
	std::vector<std::string> const * vec_cpuUsage = cpuUsage->getData();
	std::vector<std::string> const * vec_ramUsage = ramUsage->getData();
	std::vector<std::string> const * vec_host = host->getData();
	std::vector<std::string> const * vec_network = network->getData();
	std::vector<std::string> const * vec_osInfo = osInfo->getData();
	std::vector<std::string> const * vec_time = time->getData();

    nodelay(stdscr, true);
	for (;;)
	{
		clear();

		cpuUsage->getData();
		ramUsage->getData();
		network->getData();
		time->getData();

		drawBorders();

		mvwprintw(stdscr, 1, 2, "CPU:");
		mvwprintw(stdscr, 2, 4, (*vec_cpuInfo)[0].c_str());
		mvwprintw(stdscr, 3, 4, (*vec_cpuInfo)[1].c_str());
		mvwprintw(stdscr, 4, 4, "User:   ");
		drawBar(4, 12, std::stoi((*vec_cpuUsage)[0]));
		mvwprintw(stdscr, 5, 4, "System: ");
		drawBar(5, 12, std::stoi((*vec_cpuUsage)[1]));

		mvwprintw(stdscr, 7, 2, "RAM:");
		mvwprintw(stdscr, 8, 4, "Total Capacity: 8192MB");
		drawBar(9, 12, (std::stoi((*vec_ramUsage)[0]) - std::stoi((*vec_ramUsage)[1])) / 82, std::stoi((*vec_ramUsage)[1]) / 82);
		mvwprintw(stdscr, 9, 4, "Used:   ");

		mvwprintw(stdscr, 11, 2, "NETWORK:");
		mvwprintw(stdscr, 12, 4, (*vec_host)[0].c_str());
		mvwprintw(stdscr, 13, 4, "User: %s", (*vec_host)[1].c_str());
		mvwprintw(stdscr, 14, 4, (*vec_network)[0].c_str());
		mvwprintw(stdscr, 15, 4, (*vec_network)[1].c_str());

		mvwprintw(stdscr, 11, 42, "OS:");
		mvwprintw(stdscr, 12, 44, (*vec_osInfo)[0].c_str());
		mvwprintw(stdscr, 13, 44, (*vec_osInfo)[1].c_str());

		mvwprintw(stdscr, 11, 99, (*vec_time)[0].c_str());
		mvwprintw(stdscr, 12, 99, (*vec_time)[1].c_str());

		nya.nyanCat();


		input();
		refresh();
	}

	delete cpuInfo;
	delete cpuUsage;
	delete ramUsage;
	delete host;
	delete network;
	delete osInfo;
	delete time;
}

DisplayBar &	DisplayBar::operator=(DisplayBar const &)
{
	return *this;
}
