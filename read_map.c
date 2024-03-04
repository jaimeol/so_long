/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/04 14:45:38 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

char	**create_map(char *file, t_game **game)
{
	char	**map;
	int		i;
	char	*aux_map;
	int		width;
	
	i = 0;
	int fd = open(file, O_RDONLY);
	aux_map = NULL;
	map = (char **)malloc(sizeof(char *) * ((*game)->y_large));
	if (!map)
		return (NULL);
	while (i < (*game)->y_large)
	{
		map[i] = (char *)malloc(sizeof(char) * (*game)->x_large);
		if  (!map[i])
			free_map(map);
		aux_map = get_next_line(fd);
		map[i] = erase_newline(aux_map);
		width = ft_strlen(map[i]);
		printf ("largo del mapa: %d\n", width);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	*read_map(char *map, t_game **game)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	
	height = 0;
	width = 0;
	(*game) = (t_game *)malloc(sizeof(t_game));
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	erase_newline(line);
	width = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;
	}
	line = NULL;
	(*game)->x_large = width;
	(*game)->y_large = height;
	(*game)->map_size = (width * height);
	close(fd);
	return (line);
}

int main(int argc, char *argv[])
{
	//int i = 0;
	if (argc == 1)
	{
		printf("No has pasado ningún mapa");
		exit (1) ;
	}
    t_game *game;
    char *map_file = argv[1];
    char *map_content = read_map(map_file, &game);
	game->map = create_map(map_file, &game);
	/*while ((*game).map[i])
	{
		printf("%s\n", (*game).map[i]);
		i++;
	}*/
	checker(game);
	flood_map(game);
	free(map_content);
    return (0);
}
