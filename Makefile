# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:24:32 by jolivare          #+#    #+#              #
#    Updated: 2024/09/24 17:53:31 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = src/get_next_line.c src/get_next_line_utils.c src/read_map.c src/check.c \
			src/utils.c src/Map_errors.c src/item_errors.c src/checker.c src/flood.c\
			src/so_long.c src/initialize.c src/render.c src/movement.c src/render_direction.c \

PRINTF = ../printf/libftprintf.a

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OPENGL -framework Appkit -g
INCLUDES = -I/opt/X11/include -Imlx
REMOVE = rm -f
CC = cc

all: makelib $(NAME)

makelib:
	$(MAKE) -C printf

$(NAME): $(OBJECTS) $(PRINTF)
	$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	make clean -sC printf
	$(REMOVE) $(OBJECTS)
fclean: clean
	make fclean -sC printf
	$(REMOVE) $(NAME)
re: fclean all

.PHONY: all clean fclean re

clear:
	clear

r: run
run: clear all
	./$(NAME) maps/map.ber