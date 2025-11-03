# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 11:38:32 by ablabib           #+#    #+#              #
#    Updated: 2025/11/03 17:50:10 by ablabib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Forms

SRC = main.cpp Bureaucrat.cpp  AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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