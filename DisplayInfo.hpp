/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 10:57:11 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 10:57:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorDisplay.hpp"

class DisplayInfo : public IMonitorDisplay
{
public:
	DisplayInfo();
	DisplayInfo(DisplayInfo const &);
	~DisplayInfo();

	void	init();
	void	render();

	DisplayInfo &	operator=(DisplayInfo const &);
	
};
