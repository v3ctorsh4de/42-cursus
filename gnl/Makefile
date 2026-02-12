# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 16:28:28 by jreyes-s          #+#    #+#              #
#    Updated: 2026/02/12 16:44:32 by jreyes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	get_next_line.a

CC =	cc
CFLAGS =	-Wall -Wextra -Werror

SRCS =	get_next_line.c get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
