# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 07:26:28 by imqandyl          #+#    #+#              #
#    Updated: 2025/04/11 07:26:38 by imqandyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = zombie

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all