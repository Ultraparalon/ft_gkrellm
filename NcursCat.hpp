/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:19:32 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:33 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ncurses.h>
#include <iostream>

class NcursCat
{
	int	_posy;
	int	_posx;

public:
	NcursCat();
	NcursCat(int, int);
	NcursCat(NcursCat const &);
	~NcursCat();

	void	nyanCat();

	NcursCat &	operator=(NcursCat const &);
	
};
