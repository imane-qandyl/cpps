CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ScalarConverter

SRC = ScalarConverter.cpp \
	main.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#$env:PATH += ";C:\msys64\ucrt64\bin" && mingw32-make