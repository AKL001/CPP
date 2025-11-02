# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 11:38:36 by ablabib           #+#    #+#              #
#    Updated: 2025/11/02 14:29:35 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

SRC = main.cpp ScalarConverter.cpp

HEADER = ScalarConverter.hpp  

OBJC = $(SRC:.cpp=.o)

CPP = c++

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