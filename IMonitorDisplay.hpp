/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:25:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:25:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <ncurses.h>
# include <vector>

#include "IMonitorModule.hpp"
#include "ModuleCPUInfo.hpp"
#include "ModuleCPUUsage.hpp"
#include "ModuleHost.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleOSInfo.hpp"
#include "ModuleRAMUsage.hpp"
#include "ModuleTime.hpp"

#include "NcursCat.hpp"

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay() {};

	virtual void	init() = 0;
	virtual void	render() = 0;
	
};
