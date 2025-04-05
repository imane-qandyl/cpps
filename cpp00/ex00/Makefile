# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 11:57:45 by imqandyl          #+#    #+#              #
#    Updated: 2025/04/04 12:18:28 by imqandyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re