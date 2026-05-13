NAME = find
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean re fclean