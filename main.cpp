/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 10:57:47 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/13 10:57:48 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

#include "DisplayBomj.hpp"
#include "DisplayGraphical.hpp"
#include "DisplayInfo.hpp"
#include "DisplayBar.hpp"

void	proccesUnit(IMonitorDisplay * display)
{
	display->init();
	display->render();

	delete display;
}

void	choice(std::string const & str)
{
	if (str == "-bomj")
		proccesUnit(new DisplayBomj());
	else if (str == "-info")
		proccesUnit(new DisplayInfo());
	else if (str == "-graph")
		proccesUnit(new DisplayGraphical());
	else if (str == "-bar")
		proccesUnit(new DisplayBar());
	else
		std::cout << "No such parametr!\n";
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		choice(argv[1]);
	}
	else
	{
		std::cout << "usage: ft_gkrellm [param]\n";
		std::cout << "       -bomj\n";
		std::cout << "       -bar\n";
		std::cout << "       -graph\n";
		std::cout << "       -info\n";
	}

	


    return 0;
}
