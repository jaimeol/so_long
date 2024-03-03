/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/03 12:56:08 by jolivare         ###   ########.fr       */
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
		printf("Hola\n");
		while (j <= game->x_large)
		{
			if (game->map[0][j] != '1' || game->map[game->y_large][j] != '1')
				wall_error();
			j++;
		}
		i++;
	}
}
