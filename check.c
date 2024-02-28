/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/28 17:17:59 by jolivare         ###   ########.fr       */
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
		while (j <= game->x_large - 1)
		{
			printf ("caracter comprobado: %c\n", game->map[i][j]);
			printf ("Y_large: %d\nJ: %d\n", game->y_large, j);
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != '\n')
			{
				printf("Error: El mapa solo puede estar compuesto por 0, 1, P, C o E\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	width_error(void)
{
	printf ("Error: Las líneas deben tener la misma longitud\n");
	exit (1);
}
