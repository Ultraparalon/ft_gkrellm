/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:24:46 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 17:24:47 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <vector>
# include <unistd.h>
# include <ctime>
# include <sys/utsname.h>
# include <sys/types.h>
# include <sys/sysctl.h>

class IMonitorModule
{
public:
	virtual	~IMonitorModule() {};

	virtual	std::vector<std::string> const *	getData() = 0;
	
};
