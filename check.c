/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/14 18:33:44 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		if (game->map[i][j] != '1' || game->map[i][ft_strlen(rows) - 1] != '1')
		{
			perror("Error\nEl mapa no está rodeado de muros\n");
			exit (1);
		}
		while (j < game->columns)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != 1 && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C')
			{
				perror("Error\n");
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