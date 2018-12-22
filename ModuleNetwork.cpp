/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleNetwork.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:29:25 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:29:26 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleNetwork.hpp"

ModuleNetwork::ModuleNetwork() {}
ModuleNetwork::ModuleNetwork(ModuleNetwork const &) {}
ModuleNetwork::~ModuleNetwork()
{
	_data.clear();
}

std::vector<std::string> const *	ModuleNetwork::getData()
{
	this->_data.clear();

	std::system("nettop -J bytes_in,bytes_out -x -l1 > ./info/netinfo");
	std::ifstream				nifs("./info/netinfo");
	std::string					nline = "";
	std::vector<std::string>			net;

	long	packet_in = 0;
	long	packet_out = 0;
	int		i = 0;

	while (getline(nifs, nline, ' '))
	{
		if (nline != "" && (nline.find_first_not_of("0123456789") == std::string::npos))
		{
			if (i % 2 == 0)
				packet_in = packet_in + stol(nline);
			else
				packet_out = packet_out + stol(nline);
			i++;
		}
	}

	std::stringstream 			convert;

	convert << "Packets In: " << packet_in;
	this->_data.push_back(convert.str());
	convert.str("");

	convert << "Packets Out: " << packet_out;
	this->_data.push_back(convert.str());

	nifs.close();

	return &_data;
}

ModuleNetwork &	ModuleNetwork::operator=(ModuleNetwork const &)
{
	return *this;
}
