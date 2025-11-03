# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 11:38:36 by ablabib           #+#    #+#              #
#    Updated: 2025/11/03 18:40:25 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Identify

SRC = main.cpp Base.cpp
HEADER = Base.hpp A.hpp B.hpp C.hpp

OBJC = $(SRC:.cpp=.o)

CPP = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJC)
	$(CPP) $(CXXFLAGS) $(OBJC) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
