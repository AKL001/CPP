# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 07:21:07 by ablabib           #+#    #+#              #
#    Updated: 2025/10/04 07:21:08 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde

SRC = 	Zombie.cpp zombieHorde.cpp main.cpp 

HEADER = Zombie.hpp 

OBJCS = $(SRC:.cpp=.o)

CPP = c++

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME) : $(OBJCS) 
	$(CPP) $(FLAGS) $(OBJCS) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
