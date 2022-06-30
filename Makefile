# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 03:34:15 by fleduc            #+#    #+#              #
#    Updated: 2022/06/30 11:24:24 by fleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FRAME = -framework OpenGL -framework AppKit

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = so_long.c check_map.c make_map.c setter.c change_map.c place_ground.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) -lmlx libft/libft.a $(FRAME) $(OBJS) -o $(NAME)
	@echo "███████████████████████████████████▀█"
	@echo "█─▄▄▄▄█─▄▄─█▄─▄███─▄▄─█▄─▀█▄─▄█─▄▄▄▄█"
	@echo "█▄▄▄▄─█─██─██─██▀█─██─██─█▄▀─██─██▄─█"
	@echo "▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀"

clean:
	@$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
