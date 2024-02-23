/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/23 18:47:09 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->x_large)
	{
		j = 0;
		if (game->map[i][j] != '1' || game->map[i][game->x_large - 1] != '1')
		{
			perror("Error\nEl mapa no está rodeado de muros\n");
			exit (1);
		}
		while (j < game->y_large)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != 1 && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C')
			{
				perror("Error: El mapa solo puede estar compuesto por 0,1,P,C o E\n");
				exit (1);
			}
			else
			{
				game->x_p = j;
				game->y_p = i;
			}
			j++;
		}
		i++;
	}
}