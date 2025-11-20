NAME = MutantStack

SRC = main.cpp 
HEADER =  MutantStack.hpp  MutantStack.tpp
OBJ = $(SRC:.cpp=.o)	

CPPFLAGS = -Wall -Werror -Wextra 

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
