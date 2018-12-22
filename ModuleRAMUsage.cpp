/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleRAMUsage.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:27:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:27:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleRAMUsage.hpp"

ModuleRAMUsage::ModuleRAMUsage() {}
ModuleRAMUsage::ModuleRAMUsage(ModuleRAMUsage const &) {}
ModuleRAMUsage::~ModuleRAMUsage()
{
	_data.clear();
}

std::vector<std::string> const *	ModuleRAMUsage::getData()
{
	this->_data.clear();

	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./info/raminfo" );
	std::ifstream				rifs("./info/raminfo");
	std::string					rline = "";
	std::vector<std::string>	ram;

	while (getline(rifs, rline, ' '))
		ram.push_back(rline);

	rifs.close();

	this->_data.push_back(ram.at(9));
	this->_data.push_back(ram.at(11).substr(1, ram.at(11).length()));
	this->_data.push_back(ram.at(13));

	return &_data;
}

ModuleRAMUsage &	ModuleRAMUsage::operator=(ModuleRAMUsage const &)
{
	return *this;
}
