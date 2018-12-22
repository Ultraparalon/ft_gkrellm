/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleHost.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:28:29 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:28:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleHost : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleHost();
	ModuleHost(ModuleHost const &);
	~ModuleHost();

	std::vector<std::string> const *	getData();

	ModuleHost &	operator=(ModuleHost const &);
	
};
