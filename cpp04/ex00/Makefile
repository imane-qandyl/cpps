CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Animal

SRC = main.cpp\
	Cat.cpp\
	Dog.cpp\
	animal.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all