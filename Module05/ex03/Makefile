# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 11:38:36 by ablabib           #+#    #+#              #
#    Updated: 2025/11/01 11:39:16 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

SRC = $(wildcard *.cpp)

HEADER = $(wildcard *.hpp) 

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