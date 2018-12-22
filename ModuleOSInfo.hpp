/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleOSInfo.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:44:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 19:44:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleOSInfo : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleOSInfo();
	ModuleOSInfo(ModuleOSInfo const &);
	~ModuleOSInfo();

	std::vector<std::string> const *	getData();

	ModuleOSInfo &	operator=(ModuleOSInfo const &);
	
};
