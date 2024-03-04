# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:24:32 by jolivare          #+#    #+#              #
#    Updated: 2024/03/04 14:55:57 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = get_next_line.c get_next_line_utils.c read_map.c check.c \
			utils.c Map_errors.c Item_errors.c checker.c flood.c\
			

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OPENGL- framework Appkit
INCLUDES = -I/opt/X11/include -Imlx
REMOVE = rm -f
CC = cc

all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(REMOVE) $(OBJECTS)
fclean: clean
	$(REMOVE) $(NAME)
re: fclean all

.PHONY: all clean fclean re