# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 05:41:14 by logkoege          #+#    #+#              #
#    Updated: 2024/12/04 16:54:49 by logkoege         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread 	

SRC = philo.c				\
		philo_parsing.c		\
		philo_utils.c		\
		init.c				\
		philo_things.c		\
		philo_utils2.c		\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

