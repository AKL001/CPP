# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 17:51:06 by ablabib           #+#    #+#              #
#    Updated: 2025/11/03 17:51:07 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Op_overloading

SRC = main.cpp Fixed.cpp

HEADER = Fixed.hpp

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