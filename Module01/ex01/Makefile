NAME = zombieHorde

SRC = 	Zombie.cpp zombieHorde.cpp main.cpp 

HEADER = Zombie.hpp 

OBJCS = $(SRC:.cpp=.o)

CPP = c++

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME) : $(OBJCS) $(HEADER)
	$(CPP) $(CPPFLAGS) $(OBJCS) -o $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
