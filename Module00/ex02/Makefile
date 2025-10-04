# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 16:38:45 by ablabib           #+#    #+#              #
#    Updated: 2025/10/04 08:16:18 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bank

HEADERS = Account.hpp

SRCS =  Account.cpp tests.cpp

OBJCS = $(SRCS:.cpp=.o)

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJCS) $(HEADERS)
	$(CPP) $(CPPFLAGS) $(OBJCS) -o $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
