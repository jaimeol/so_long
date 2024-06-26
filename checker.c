/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:54:34 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/24 10:42:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	check_char(game);
	check_walls(game);
	check_width(game);
	check_coins(game);
	check_exit(game);
	check_player(game);
	check_path(game);
}

void	check_player(t_game *game)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (game->map[i])
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

void	assign_player_pos(t_game *game)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 1;
	while (i < game->y_large)
	{
		j = 1;
		while (j < game->x_large - 1)
		{
			if (game->map[i][j] == 'P')
			{
				game->y_p = i;
				game->x_p = j;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_game *game)
{
	char	**aux_map;
	int		i;
	int		j;

	i = 0;
	aux_map = duplicate_map(game);
	assign_player_pos(game);
	flood_map(game->y_p, game->x_p, aux_map);
	while (i < game->y_large)
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
	free_map(aux_map);
}

void	check_format(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b'
		|| argv[i - 4] != '.')
		format_error();
}
