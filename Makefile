# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:24:32 by jolivare          #+#    #+#              #
#    Updated: 2024/04/24 11:12:27 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = get_next_line.c get_next_line_utils.c read_map.c check.c \
			utils.c Map_errors.c item_errors.c checker.c flood.c\
			so_long.c initialize.c render.c movement.c render_direction.c \

PRINTF = printf/libftprintf.a

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