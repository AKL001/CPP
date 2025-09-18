NAME = megaphone

SRCS = megaphone.cpp

OBJCS = $(SRCS:.cpp=.o)

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)


$(NAME) : $(OBJCS)
	$(CPP) $(CPPFLAGS) $(OBJCS) -o $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
