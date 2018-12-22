/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayBomj.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:49:30 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 20:49:31 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayBomj.hpp"

DisplayBomj::DisplayBomj() {}
DisplayBomj::DisplayBomj(DisplayBomj const &) {}
DisplayBomj::~DisplayBomj() {}

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

void	DisplayBomj::init()
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
	for (int y = 0; y < 27; y++)
		for (int x = 0; x < 36; x++)
		{
			if (y == 0 || x == 0 || x == 35 || y == 26 || y == 7 || y == 13 || y == 19 || y == 23)
			mvaddch(y, x, ' ');
		}
	attroff(COLOR_PAIR(12));
}

void	DisplayBomj::render()
{
	NcursCat nya(0, 36);

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

		attron(COLOR_PAIR(4));

		cpuUsage->getData();
		ramUsage->getData();
		network->getData();
		time->getData();

		drawBorders();

		mvwprintw(stdscr, 1, 2, "CPU:");
		mvwprintw(stdscr, 2, 4, (*vec_cpuInfo)[0].c_str());
		mvwprintw(stdscr, 3, 4, (*vec_cpuInfo)[1].c_str());
		mvwprintw(stdscr, 4, 4, "User:   %s", (*vec_cpuUsage)[0].c_str());
		mvwprintw(stdscr, 5, 4, "System: %s", (*vec_cpuUsage)[1].c_str());
		mvwprintw(stdscr, 6, 4, "Idle:   %s", (*vec_cpuUsage)[2].c_str());

		mvwprintw(stdscr, 8, 2, "RAM:");
		mvwprintw(stdscr, 9, 4, "Max Capacity: 8192MB");
		mvwprintw(stdscr, 10, 4, "Used:   %s%s", (*vec_ramUsage)[0].c_str(), "B");
		mvwprintw(stdscr, 11, 4, "Wired:  %s%s", (*vec_ramUsage)[1].c_str(), "B");
		mvwprintw(stdscr, 12, 4, "Unused: %s%s", (*vec_ramUsage)[2].c_str(), "B");

		mvwprintw(stdscr, 14, 2, "NETWORK:");
		mvwprintw(stdscr, 15, 4, (*vec_host)[0].c_str());
		mvwprintw(stdscr, 16, 4, "User: %s", (*vec_host)[1].c_str());
		mvwprintw(stdscr, 17, 4, (*vec_network)[0].c_str());
		mvwprintw(stdscr, 18, 4, (*vec_network)[1].c_str());

		mvwprintw(stdscr, 20, 2, "OS:");
		mvwprintw(stdscr, 21, 4, (*vec_osInfo)[0].c_str());
		mvwprintw(stdscr, 22, 4, (*vec_osInfo)[1].c_str());

		mvwprintw(stdscr, 24, 2, (*vec_time)[0].c_str());
		mvwprintw(stdscr, 25, 2, (*vec_time)[1].c_str());

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

DisplayBomj &	DisplayBomj::operator=(DisplayBomj const &)
{
	return *this;
}
