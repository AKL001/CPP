
NAME = printMemory

SRC = main.cpp 

OBJC = $(SRC:.cpp=.o)

CPP = c++

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all