# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 10:57:41 by vkaidans          #+#    #+#              #
#    Updated: 2018/10/13 10:57:42 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC =	main.cpp \
		ModuleCPUInfo.cpp ModuleCPUUsage.cpp ModuleHost.cpp \
		ModuleNetwork.cpp ModuleRAMUsage.cpp ModuleTime.cpp ModuleOSInfo.cpp \
		DisplayBomj.cpp DisplayGraphical.cpp DisplayInfo.cpp DisplayBar.cpp \
		NcursCat.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -lncurses $(FLAGS) $(OBJ) -lncurses -o $@
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created ft_gkrellm"

$(OBJ): %.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned ft_gkrellm"

fclean: clean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned ft_gkrellm"

re: fclean all

.PHONY: all clean fclean all
