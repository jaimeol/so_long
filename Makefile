# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:24:32 by jolivare          #+#    #+#              #
#    Updated: 2024/02/10 16:49:51 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = 

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

re: fclean all

.PHONY: all clean fclean re