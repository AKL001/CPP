# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 15:28:56 by ablabib           #+#    #+#              #
#    Updated: 2025/11/03 17:50:43 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

HEADER = ClapTrap.hpp ScavTrap.hpp

OBJC = $(SRC:.cpp=.o)

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJC)
	$(CPP) $(FLAGS) $(OBJC) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re