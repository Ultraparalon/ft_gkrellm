/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleTime.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:29:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:29:47 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"

class ModuleTime : public IMonitorModule
{
	std::vector<std::string>	_data;

public:
	ModuleTime();
	ModuleTime(ModuleTime const &);
	~ModuleTime();

	std::vector<std::string> const *	getData();

	ModuleTime &	operator=(ModuleTime const &);
	
};
