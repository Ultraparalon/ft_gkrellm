/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleNetwork.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:29:29 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:29:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleNetwork : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleNetwork();
	ModuleNetwork(ModuleNetwork const &);
	~ModuleNetwork();

	std::vector<std::string> const *	getData();

	ModuleNetwork &	operator=(ModuleNetwork const &);
	
};