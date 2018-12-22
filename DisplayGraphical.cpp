
#include "DisplayGraphical.hpp"




DisplayGraphical::DisplayGraphical() :
	_win(newwin(80, 40, 0, 0)),
	_cpuUserData(new std::list<int>(60)),
	_cpuSystData(new std::list<int>(60)),
	_cpuIdleData(new std::list<int>(60)) { }

DisplayGraphical::DisplayGraphical(DisplayGraphical const & copy)
{ *this = copy; }
DisplayGraphical::~DisplayGraphical() { delwin(_win); }



DisplayGraphical & 	DisplayGraphical::operator=(DisplayGraphical const & copy)
{
	static_cast<void>(copy);
	return (*this);
}



void				DisplayGraphical::drawBar
						(int row, int column, int value,
						 int maxWidth, int colorPair) const
{
	std::string		fill;
	std::string		empty;

	value = static_cast<int>(
		static_cast<float>(value) * static_cast<float>(maxWidth - 2) / 100.0f);

	fill = std::string(value, ' ');
	empty = std::string(maxWidth - 2 - value, '-');

	mvaddch(row, column, '[');
	attron(COLOR_PAIR(colorPair));
	mvprintw(row, column + 1, "%s", fill.c_str());
	attron(COLOR_PAIR(4));
	mvprintw(row, column + value + 1, "%s]", empty.c_str());
}

static void			drawGraphBorder(int row, int column, int maxWidth,
								   int maxHeight, float maxVal)
{
	std::string		bott;

	for (int i = 0; i < maxHeight; ++i)
		mvaddch(row + i, column, '|');

	for (int i = 0; i < 4; ++i)
		mvprintw(
			row + i * (static_cast<float>(maxHeight) / 4.0f),
			column - 3,
			"%3d-",
			static_cast<int>(maxVal * (4.0f - i) / 4.0f));

	bott = std::string(maxWidth - 1, '-');
	mvprintw(row + maxHeight, column, "+%s", bott.c_str());
}

void				DisplayGraphical::drawGraph(int row, int column,
								 				std::list<int> const * values,
								 				int maxWidth, int maxHeight,
								 				int colorPair) const
{
	float							maxVal;
	float							maxHeightF;
	int								width;
	std::list<int>::const_iterator	begin;

	maxVal = static_cast<float>(
			*std::max_element(values->begin(), values->end()));

	drawGraphBorder(row, column, maxWidth, maxHeight, maxVal);

	begin = values->begin();
	width = std::min(static_cast<int>(values->size()), maxWidth);
	for (unsigned long i = 0; i < values->size() - width + 1; ++i)
		++begin;

	maxHeightF = static_cast<float>(maxHeight - 1);
	attron(COLOR_PAIR(colorPair));
	for (int i = 1; begin != values->end(); ++begin, ++i)
		for (int rowBegin = static_cast<int>(
				row + maxHeight - (static_cast<float>(
					*begin) / maxVal * maxHeightF));
			 rowBegin < row + maxHeight;
			 ++rowBegin)
			mvaddch(rowBegin, column + i, ' ');
	attroff(COLOR_PAIR(colorPair));
}

static void			drawBorders()
{
	attron(COLOR_PAIR(12));
	for (int y = 0; y <= 56; y++)
		for (int x = 0; x <= 154; x++)
		{
			if (y == 0 || x == 0 || x == 154 || y == 56 || x == 38)
				mvaddch(y, x, ' ');
			else if ((y == 12 && x > 38) || (y < 12 && x == 106))
				mvaddch(y, x, ' ');
		}
	attroff(COLOR_PAIR(12));
}

static void			drawDigit(int row, int column, int digit)
{
	for (int i = 0; ; ++i)
	{
		mvaddch(
			row + _clockMap[digit][i][1],
			column + _clockMap[digit][i][0],
			' ');
		if (_clockMap[digit][i][0] == 2 && _clockMap[digit][i][1] == 4)
			break ;
	}
}

void				DisplayGraphical::drawClock(int row, int column,
												std::string const & time) const
{
	int		hours;
	int 	min;
	int		sec;

	hours = std::atoi(time.c_str());
	min = std::atoi(&(time[3]));
	sec = std::atoi(&(time[6]));

	attron(COLOR_PAIR(12));
	drawDigit(row, column, hours / 10);
	drawDigit(row, column + 4, hours % 10);
	if (sec % 2)
	{
		mvaddch(row + 1, column + 8, ' ');
		mvaddch(row + 3, column + 8, ' ');
	}
	drawDigit(row, column + 10, min / 10);
	drawDigit(row, column + 14, min % 10);
	if (sec % 2)
	{
		mvaddch(row + 1, column + 18, ' ');
		mvaddch(row + 3, column + 18, ' ');
	}
	drawDigit(row, column + 20, sec / 10);
	drawDigit(row, column + 24, sec % 10);
	attroff(COLOR_PAIR(12));
}

static void			initColor()
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

void				DisplayGraphical::init()
{
	initscr();
	curs_set(0);
	noecho();
	initColor();
}

static void			input()
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

void				DisplayGraphical::render()
{
	NcursCat	nya(29, 39);

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
		drawBorders();

		cpuUsage->getData();
		ramUsage->getData();
		network->getData();
		time->getData();

		_cpuUserData->pop_front();
		_cpuSystData->pop_front();
		_cpuIdleData->pop_front();
		_cpuUserData->push_back(std::stoi((*vec_cpuUsage)[0]));
		_cpuSystData->push_back(std::stoi((*vec_cpuUsage)[1]));
		_cpuIdleData->push_back(std::stoi((*vec_cpuUsage)[2]));
		_ramUsed = std::stoi((*vec_ramUsage)[0]);
		_ramWire = std::stoi((*vec_ramUsage)[1]);
		_ramFree = std::stoi((*vec_ramUsage)[2]);

		attron(COLOR_PAIR(4));

		mvwprintw(stdscr, 2, 5, (*vec_cpuInfo)[0].c_str());
		mvwprintw(stdscr, 3, 5, (*vec_cpuInfo)[1].c_str());

		mvwprintw(stdscr, 5, 5, "User: %s", (*vec_cpuUsage)[0].c_str());
		drawGraph(7, 8, _cpuUserData, 25, 12, 11);
		attron(COLOR_PAIR(4));
		drawBar(20, 7, _cpuUserData->back(), 27, 11);

		mvwprintw(stdscr, 22, 5, "System: %s", (*vec_cpuUsage)[1].c_str());
		drawGraph(24, 8, _cpuSystData, 25, 12, 17);
		attron(COLOR_PAIR(4));
		drawBar(37, 7, _cpuSystData->back(), 27, 17);

		mvwprintw(stdscr, 39, 5, "Idle: %s", (*vec_cpuUsage)[2].c_str());
		drawGraph(41, 8, _cpuIdleData, 25, 12, 14);
		attron(COLOR_PAIR(4));
		drawBar(54, 7, _cpuIdleData->back(), 27, 14);

		mvwprintw(stdscr, 2, 45, "Max Capacity: 8192 MB");
		mvwprintw(stdscr, 5, 45, "Used:   %4d MB", _ramUsed);
		drawBar(5, 65, _ramUsed * 100 / 8192, 32, 13);
		mvwprintw(stdscr, 6, 45, "Wired:  %4d MB", _ramWire);
		drawBar(6, 65, _ramWire * 100 / 8192, 32, 17);
		mvwprintw(stdscr, 7, 45, "Unused: %4d MB", _ramFree);
		drawBar(7, 65, _ramFree * 100 / 8192, 32, 11);

		mvwprintw(stdscr, 2, 110, (*vec_host)[0].c_str());
		mvwprintw(stdscr, 3, 110, (*vec_host)[1].c_str());

		mvwprintw(stdscr, 9, 45, (*vec_network)[0].c_str());
		mvwprintw(stdscr, 10, 45, (*vec_network)[1].c_str());

		mvwprintw(stdscr, 5, 110, (*vec_osInfo)[0].c_str());
		mvwprintw(stdscr, 6, 110, (*vec_osInfo)[1].c_str());

		mvwprintw(stdscr, 8, 110, (*vec_time)[0].c_str());

		drawClock(18, 80, (*vec_time)[1]);

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