# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 11:38:36 by ablabib           #+#    #+#              #
#    Updated: 2025/11/03 17:15:34 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

SRC = main.cpp Serializer.cpp 

HEADER = Serializer.hpp DataStruct.hpp  

OBJC = $(SRC:.cpp=.o)

CPP = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 

all: $(NAME)

$(NAME): $(OBJC)
	$(CPP) $(CXXFLAGS) $(SRC) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
