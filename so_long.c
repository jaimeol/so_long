/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/08 11:19:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_window window;
	window.mlx = mlx_init();
	if (!window.mlx)
	{
		ft_printf("Fallo\n");
		return (1);
	}
	check_format(argv[1]);
    t_game *game;
    char *map_file = argv[1];
    char *map_content = read_map(map_file, &game);
	checker(game);
	(*game).map = create_map(map_file, &game);
	window.win = mlx_new_window(window.mlx, (*game).x_large, (*game).y_large, "juego");
	mlx_loop(window.mlx);
	free(window.mlx);
	free(map_content);
	argc = 0;
	exit (0);
}