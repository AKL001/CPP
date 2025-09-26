# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 16:38:18 by ablabib           #+#    #+#              #
#    Updated: 2025/09/26 16:38:19 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook

HEADERS = Contact.hpp PhoneBook.hpp 

SRCS =  PhoneBook.cpp Contact.cpp main.cpp

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
