/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCPUInfo.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:26:39 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:26:41 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleCPUInfo : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleCPUInfo();
	ModuleCPUInfo(ModuleCPUInfo const &);
	~ModuleCPUInfo();

	std::vector<std::string> const *	getData();

	ModuleCPUInfo &	operator=(ModuleCPUInfo const &);
	
};
