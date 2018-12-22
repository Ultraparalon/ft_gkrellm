/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleRAMUsage.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:27:39 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:27:40 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleRAMUsage : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleRAMUsage();
	ModuleRAMUsage(ModuleRAMUsage const &);
	~ModuleRAMUsage();

	std::vector<std::string> const *	getData();

	ModuleRAMUsage &	operator=(ModuleRAMUsage const &);
	
};
