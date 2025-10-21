# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 15:28:56 by ablabib           #+#    #+#              #
#    Updated: 2025/10/21 10:47:09 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Materiaaaa

SRC = $(wildcard *.cpp)

HEADER = $(wildcard includes/*.hpp)

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