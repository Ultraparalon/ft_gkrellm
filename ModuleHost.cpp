/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleHost.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:28:25 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:28:26 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleHost.hpp"

ModuleHost::ModuleHost() {}
ModuleHost::ModuleHost(ModuleHost const &) {}
ModuleHost::~ModuleHost()
{
	_data.clear();
}

std::vector<std::string> const *	ModuleHost::getData()
{
	this->_data.clear();

	char hostname[255];
	char username[255];
	gethostname(hostname, 255);
	getlogin_r(username, 255);

	this->_data.push_back(hostname);
	this->_data.push_back(username);

	return &_data;
}

ModuleHost &	ModuleHost::operator=(ModuleHost const &)
{
	return *this;
}
