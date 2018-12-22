/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCPUUsage.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:27:07 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:27:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleCPUUsage.hpp"

ModuleCPUUsage::ModuleCPUUsage() {}
ModuleCPUUsage::ModuleCPUUsage(ModuleCPUUsage const &) {}
ModuleCPUUsage::~ModuleCPUUsage()
{
	this->_data.clear();
}

std::vector<std::string> const *	ModuleCPUUsage::getData()
{
	this->_data.clear();

	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./info/raminfo" );
	std::ifstream				rifs("./info/raminfo");
	std::string					rline = "";
	std::vector<std::string>	cpu;

	while (getline(rifs, rline, ' '))
		cpu.push_back(rline);

	rifs.close();

	this->_data.push_back(cpu.at(2));
	this->_data.push_back(cpu.at(4));
	this->_data.push_back(cpu.at(6));

	return &_data;
}

ModuleCPUUsage &	ModuleCPUUsage::operator=(ModuleCPUUsage const &)
{
	return *this;
}
