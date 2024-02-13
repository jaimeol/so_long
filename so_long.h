/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:09:31 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/13 17:15:38 by jolivare         ###   ########.fr       */
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

typedef struct s_list
{
	struct s_list	*next;
	char			*content;
	int				size;
}	t_list;

typedef struct s_game
{
	char 	**map;
	int		columns;
	int		rows;
	int		x_p;
	int		y_p;
}	t_game;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int i);
char	*get_next_line(int fd);
void	add_line(char *line, t_list **list);
int		read_file(void);
void	create_map(t_game *game,t_list *list, int size);
void	read_map(t_game *game);
void	print_map(t_game *map);
void	checker(t_game *game);

#endif