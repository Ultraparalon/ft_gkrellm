/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayBomj.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:49:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 20:49:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorDisplay.hpp"

class DisplayBomj : public IMonitorDisplay
{
public:
	DisplayBomj();
	DisplayBomj(DisplayBomj const &);
	~DisplayBomj();

	void	init();
	void	render();

	DisplayBomj &	operator=(DisplayBomj const &);
	
};
