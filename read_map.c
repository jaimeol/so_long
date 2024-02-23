/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/23 18:54:19 by jolivare         ###   ########.fr       */
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
	return(NULL);
}

char	**create_map(char *str, t_game *map)
{
	char	**line;
	int		i;
	int		j;
	
	i = 0;
	line = (char **)malloc(sizeof(char *) * (map->map_size + 1));
	if (!line)
		return (NULL);
	while (i < map->y_large)
	{
		j = 0;
		line[i] = (char *)malloc(sizeof(char) * (map->x_large));
		if (!line[i])
			return (free_map(line));
		while (j < map->x_large)
		{
			line[i][j] = str[(i * map->x_large + j)];
			j++;
		}
		i++;
	}
	line[i] = NULL;
	return (line);
}

char	*read_map(char *map)
{
	int		fd;
	char	*line;
	char	*str;
	char	*aux;
	
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	str = "";
	while (line != NULL)
	{
		aux = ft_strjoin(str, line);
		str = aux;
		free (line);
		line = get_next_line(fd);
	}
	if (line)
		free (line);
	close(fd);
	return (str);
}

int main(int argc, char *argv[])
{
	int i;
	if (argc == 1)
	{
		perror("No has pasado ningún mapa");
		exit (1);
	}
    t_game *game = (t_game *)malloc(sizeof(t_game));
    game->x_large = 14;
    game->y_large = 6;
    game->map_size = 72;
    char *map_file = argv[1];
    char *map_content = read_map(map_file);
	game->map = create_map(map_content, game);
	//checker(game);
	i = 0;
	printf("Mapa:\n");
	while ((game->map)[i])
	{
		printf("%s",game->map[i]);
		i++;
	}
	free(map_content);
    free(game);
    return 0;
}
