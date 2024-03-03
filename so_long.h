/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:09:31 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/03 12:19:21 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_game
{
	char 	**map;
	int		y_large;
	int		x_large;
	int		x_p;
	int		y_p;
	int		map_size;
}	t_game;

int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int i);
char	*get_next_line(int fd);
void	checker(t_game *game);
char	*ft_strdup(const char *s);
void	assign_dimensions(t_game *game, char **map);
char	*ft_substr(char const *s, int start, int len);
void	width_error(void);
char	*erase_newline(char *str);
void	check_width(t_game *game);
void	wall_error(void);
void	check_walls(t_game *game);

#endif