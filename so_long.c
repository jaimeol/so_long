/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/09 16:48:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_window window;
	t_map	new_map;
	window.mlx = mlx_init();
	if (argc != 2)
	{
		ft_printf("Error: Número de argumentos inválido\n");
		exit (1);
	}
	if (!window.mlx)
	{
		ft_printf("Fallo\n");
		return (1);
	}
	check_format(argv[1]);
    t_game *game;
    char *map_file = argv[1];
    char *map_content = read_map(map_file, &game);
	(*game).map = create_map(map_file, &game);
	checker(game);
	initialize_wall(window.mlx, &new_map);
	window.win = mlx_new_window(window.mlx, ((*game).x_large) *  64, ((*game).y_large) * 64 * 2, "juego");
	mlx_loop(window.mlx);
	free (map_content);
	exit (0);
}