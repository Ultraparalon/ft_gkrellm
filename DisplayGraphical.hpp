
#pragma once

# include "IMonitorDisplay.hpp"
# include "clockMap.hpp"
# include <list>
# include <string>

class						DisplayGraphical : public IMonitorDisplay
{

public:

	DisplayGraphical();
	DisplayGraphical(DisplayGraphical const & copy);
	~DisplayGraphical();

	DisplayGraphical &		operator=(DisplayGraphical const & copy);

	void					init();
	void					render();

private:

	WINDOW *				_win;
	std::list<int> *		_cpuUserData;
	std::list<int> *		_cpuSystData;
	std::list<int> *		_cpuIdleData;
	int						_ramUsed;
	int						_ramWire;
	int 					_ramFree;

	void					drawBar
								(int row, int column, int value,
								 int maxWidth, int colorPair) const;
	void					drawGraph
								(int row, int column,
								 std::list<int> const * values, int maxWidth,
								 int maxHeight, int colorPair) const;
	void					drawClock(int row, int column,
									  std::string const & time) const;

};
