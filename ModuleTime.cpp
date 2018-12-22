/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleTime.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:29:50 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:29:51 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleTime.hpp"

ModuleTime::ModuleTime() {}
ModuleTime::ModuleTime(ModuleTime const &) {}
ModuleTime::~ModuleTime()
{
	_data.clear();
}

std::vector<std::string> const *	ModuleTime::getData()
{
	this->_data.clear();

	time_t				sec = time(NULL);
	struct tm 			*date = localtime(&sec);
	std::stringstream	tmp;
	std::string 		sdate;

	tmp << date->tm_year + 1900;
	tmp << '.' << std::setfill('0') << std::setw(2) << date->tm_mon + 1;
	tmp << '.' << std::setfill('0') << std::setw(2) << date->tm_mday;
	this->_data.push_back(tmp.str());
	tmp.str("");
	tmp << std::setfill('0') << std::setw(2) << date->tm_hour;
	tmp << ':' << std::setfill('0') << std::setw(2) << date->tm_min;
	tmp << ':' << std::setfill('0') << std::setw(2) << date->tm_sec;
	this->_data.push_back(tmp.str());

	return &_data;
}

ModuleTime &	ModuleTime::operator=(ModuleTime const &)
{
	return *this;
}
