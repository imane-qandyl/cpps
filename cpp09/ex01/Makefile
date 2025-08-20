NAME = RPN

SRC = main.cpp \
	  RPN.cpp 
	  
OBJ = $(SRC:.cpp=.o)

CPP = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@ $(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all