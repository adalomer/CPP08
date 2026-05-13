NAME = span
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
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