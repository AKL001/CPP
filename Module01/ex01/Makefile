NAME = zombieHorde

SRC = 	Zombie.cpp zombieHorde.cpp main.cpp 

HEADER = Zombie.hpp 

OBJCS = $(SRC:.cpp=.o)

CPP = c++

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME) : $(OBJCS) 
	$(CPP) $(FLAGS) $(OBJCS) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
