/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCPUUsage.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:27:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:27:02 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleCPUUsage : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleCPUUsage();
	ModuleCPUUsage(ModuleCPUUsage const &);
	~ModuleCPUUsage();

	std::vector<std::string> const *	getData();

	ModuleCPUUsage &	operator=(ModuleCPUUsage const &);
	
};
