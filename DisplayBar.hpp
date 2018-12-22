/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayBar.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:03:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 15:03:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorDisplay.hpp"

class DisplayBar : public IMonitorDisplay
{
public:
	DisplayBar();
	DisplayBar(DisplayBar const &);
	~DisplayBar();

	void	init();
	void	render();

	DisplayBar &	operator=(DisplayBar const &);
	
};
