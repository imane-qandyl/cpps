CXX = C:/msys64/ucrt64/bin/c++.exe
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME	= Form

SRCS =	main.cpp					\
		Bureaucrat.cpp				\
		Form.cpp					

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re