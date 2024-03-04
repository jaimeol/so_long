/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:54:34 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/04 16:47:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	check_width(game);
	check_walls(game);
	check_char(game);
	check_coins(&game);
	check_exit(game);
	check_player(game);
}

void	check_player(t_game *game)
{
	int	i;
	int	j;
	int	player;
	
	player = 0;
	i = 0;
	while(game->map[i])
	{
		j = 0;
		while (j != game->x_large - 1)
		{
			if (game->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		player_error();
}

void	assign_player_pos(t_game **game)
{
	int	i;
	int	j;
	int	player;
	
	player = 0;
	i = 0;
	while((*game)->map[i])
	{
		j = 0;
		while (j != (*game)->x_large - 1)
		{
			if ((*game)->map[i][j] == 'P')
			{
				(*game)->x_p = i;
				(*game)->y_p = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_map(t_game *game)
{
	int	i;
	int	j;
	int	k;
	char **aux_map;
	
	assign_player_pos(&game);
	i = 1;
	aux_map = game->map;
	while (aux_map[i])
	{
		j = 1;
		while (aux_map[i][j] != '1')
		{
			aux_map[i][j] = '1';
			j++;
		}
		i++;
		if (i == game->y_large)
			break;
	}
	reverse_flood(game);
	i = 0;
	while (aux_map[i])
	{
		j = 0;
		while (j != game->x_large - 1)
		{
			if (aux_map[i][j] != '1')
				path_error();
			j++;
		}
		i++;
	}
	k = 0;
	while (aux_map[k])
	{
		printf("%s\n", aux_map[k]);
		k++;
	}
}

void	reverse_flood(t_game *game)
{
	int	i;
	int	j;
	char **aux_map;

	i = 1;
	aux_map = game->map;
	while (aux_map[i])
	{
		j = game->x_large - 2;
		while (aux_map[i][j] != '1')
		{
			aux_map[i][j] = '1';
			j--;
		}
		i++;
		if (i == game->y_large)
			break;
	}
}
