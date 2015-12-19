# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 14:22:25 by cattouma          #+#    #+#              #
#    Updated: 2015/12/19 15:59:30 by cattouma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog
SRCS = main.c get_next_line.c
LIBS = libft/libft.a
FlAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) $(SRCS) $(LIBS)
clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
