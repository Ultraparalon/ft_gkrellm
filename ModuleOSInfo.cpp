/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleOSInfo.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:44:38 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 19:44:40 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleOSInfo.hpp"

ModuleOSInfo::ModuleOSInfo() {}
ModuleOSInfo::ModuleOSInfo(ModuleOSInfo const &) {}
ModuleOSInfo::~ModuleOSInfo()
{
	_data.clear();
}

std::vector<std::string> const *	ModuleOSInfo::getData()
{
	this->_data.clear();
	
	struct utsname	uts;
	uname(&uts);

	this->_data.push_back(uts.sysname);
	this->_data.push_back(uts.release);

	return &_data;
}

ModuleOSInfo &	ModuleOSInfo::operator=(ModuleOSInfo const &)
{
	return *this;
}
