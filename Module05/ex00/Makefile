NAME = Bureaucrat

SRC = main.cpp Bureaucrat.cpp 

HEADER = Bureaucrat.hpp 

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