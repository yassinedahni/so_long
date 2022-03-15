# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 21:29:22 by ydahni            #+#    #+#              #
#    Updated: 2022/03/15 05:00:55 by ydahni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
SRC = get_next_line_utils.c get_next_line.c so_long_utl.c \
so_long.c split.c so_long_utl_2.c so_long_paint.c so_long_moves.c \

all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(FLAGS) $(SRC) -o $(NAME)
	@tput setaf 2; echo "SO_LONG IS READY"

clean:
	@rm -f $(NAME)
	@tput setaf 1; echo "CLEAN COMPLET"
fclean: clean

re: fclean all