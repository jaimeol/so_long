/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/24 11:00:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	perror("error");
	exit (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**create_map(char *file, t_game *game)
{
	char	**map;
	int		i;
	char	*aux_map;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	aux_map = NULL;
	map = (char **)malloc(sizeof(char *) * game->y_large);
	if (!map)
		return (NULL);
	while (i < game->y_large)
	{
		aux_map = get_next_line(fd);
		map[i] = erase_newline(aux_map);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	*read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		print_error();
	free(line);
	erase_newline(line);
	width = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		height++;
	}
	line = NULL;
	game->x_large = width;
	game->y_large = height;
	close(fd);
	return (line);
}
