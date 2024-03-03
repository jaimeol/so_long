/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/03 17:42:03 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	checker(t_game *game)
{
}*/

void	check_width(t_game *game)
{
	int		i;
	int		check;
	int		width;
	
	i = 0;
	width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		check = ft_strlen(game->map[i]);
		if (check != width)
			width_error();
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		printf ("%d\n", game->x_large);
		while (j != game->x_large - 1)
		{
			if (game->map[0][j] != '1' || game->map[game->y_large - 1][j] != '1')
				wall_error();
			j++;
		}
		if (game->map[i][0] != '1' || game->map[i][game->x_large - 1] != '1')
			wall_error();
		i++;
	}
}

void	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (j != game->x_large - 1)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' 
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != '\n')
				char_error();
			j++;
		}
		i++;
	}
}
