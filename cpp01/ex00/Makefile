# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 14:30:54 by imqandyl          #+#    #+#              #
#    Updated: 2025/04/09 18:25:41 by imqandyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = zombie

SRC = main.cpp\
	Zombie.cpp\
	newZombie.cpp\
	randomChump.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all