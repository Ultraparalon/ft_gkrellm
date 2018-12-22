/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 10:57:04 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 10:57:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayInfo.hpp"

DisplayInfo::DisplayInfo() {}
DisplayInfo::DisplayInfo(DisplayInfo const &) {}
DisplayInfo::~DisplayInfo() {}

void	DisplayInfo::init()	{}

void	DisplayInfo::render()
{
	IMonitorModule * cpuInfo = new ModuleCPUInfo();
	IMonitorModule * cpuUsage = new ModuleCPUUsage();
	IMonitorModule * ramUsage = new ModuleRAMUsage();
	IMonitorModule * host = new ModuleHost();
	IMonitorModule * network = new ModuleNetwork();
	IMonitorModule * osInfo = new ModuleOSInfo();
	IMonitorModule * time = new ModuleTime();

	std::vector<std::string> const * vec_cpuInfo = cpuInfo->getData();
	std::vector<std::string> const * vec_cpuUsage = cpuUsage->getData();
	std::vector<std::string> const * vec_ramUsage = ramUsage->getData();
	std::vector<std::string> const * vec_host = host->getData();
	std::vector<std::string> const * vec_network = network->getData();
	std::vector<std::string> const * vec_osInfo = osInfo->getData();
	std::vector<std::string> const * vec_time = time->getData();

	std::cout << (*vec_cpuInfo)[0] << std::endl;
	std::cout << (*vec_cpuInfo)[1] << std::endl;

	std::cout << "--------------------\n";
	std::cout << "User: " << (*vec_cpuUsage)[0] << std::endl;
	std::cout << "System: " << (*vec_cpuUsage)[1] << std::endl;
	std::cout << "Idle: " << (*vec_cpuUsage)[2] << std::endl;

	std::cout << "--------------------\n";
	std::cout << "Max Capacity: 8192MB\n";
	std::cout << "Used:   " << (*vec_ramUsage)[0] << "B\n";
	std::cout << "Wired:  " << (*vec_ramUsage)[1] << "B\n";
	std::cout << "Unused: " << (*vec_ramUsage)[2] << "B\n";

	std::cout << "--------------------\n";
	std::cout << (*vec_host)[0] << std::endl;
	std::cout << (*vec_host)[1] << std::endl;

	std::cout << "--------------------\n";
	std::cout << (*vec_network)[0] << std::endl;
	std::cout << (*vec_network)[1] << std::endl;
	
	std::cout << "--------------------\n";
	std::cout << (*vec_osInfo)[0] << std::endl;
	std::cout << (*vec_osInfo)[1] << std::endl;

	std::cout << "--------------------\n";
	std::cout << (*vec_time)[0] << std::endl;
	std::cout << (*vec_time)[1] << std::endl;

	delete cpuInfo;
	delete cpuUsage;
	delete ramUsage;
	delete host;
	delete network;
	delete osInfo;
	delete time;
}

DisplayInfo &	DisplayInfo::operator=(DisplayInfo const &)
{
	return *this;
}
