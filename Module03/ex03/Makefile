# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 15:28:56 by ablabib           #+#    #+#              #
#    Updated: 2025/10/16 14:42:26 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRC = main.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp

HEADER = ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp ScavTrap.hpp

OBJC = $(SRC:.cpp=.o)

CPP = c++
# FLAGS = -Wall -Wshadow -std=c++98
# -Wshadow -> to check if we have the same name atttribut in diamond and claptrap , private attributs
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJC)
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re