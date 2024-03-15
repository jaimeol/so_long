# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:24:32 by jolivare          #+#    #+#              #
#    Updated: 2024/03/15 16:02:39 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = get_next_line.c get_next_line_utils.c read_map.c check.c \
			utils.c Map_errors.c item_errors.c checker.c flood.c\
			so_long.c initialize.c render.c movement.c

PRINTF = printf/libftprintf.a

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OPENGL -framework Appkit
#INCLUDES = -I/opt/X11/include -Imlx
REMOVE = rm -f
CC = cc

all: makelib $(NAME)

makelib:
	$(MAKE) -sC printf

mlx/libmlx.a:
	make -C mlx/

$(NAME): $(OBJECTS) printf/libftprintf.a mlx/libmlx.a
	$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME) -Lprintf/ -lftprintf

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