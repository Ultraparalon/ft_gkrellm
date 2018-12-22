/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCPUInfo.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:26:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:26:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleCPUInfo.hpp"

ModuleCPUInfo::ModuleCPUInfo() {}
ModuleCPUInfo::ModuleCPUInfo(ModuleCPUInfo const &) {}
ModuleCPUInfo::~ModuleCPUInfo()
{
	this->_data.clear();
}

std::vector<std::string> const *	ModuleCPUInfo::getData()
{
	this->_data.clear();

	char buf[128];
	size_t buflen = 128;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	std::string convert = buf;

	this->_data.push_back(convert.substr(0, convert.find("M) ") + 2));
	this->_data.push_back(convert.substr(convert.find("M) ") + 3, convert.length()));

	return &_data;
}

ModuleCPUInfo &	ModuleCPUInfo::operator=(ModuleCPUInfo const &)
{
	return *this;
}
