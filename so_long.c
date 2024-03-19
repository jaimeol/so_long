/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/19 13:19:55 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

void	exit_game(t_game *game)
{
	mlx_destroy_window(&game->win.mlx, &game->win.win);
	exit (0);
}

int	initialize(t_window *window, t_image *map)
{
	initialize_wall(window->mlx, map);
	initialize_player(window->mlx, map);
	initialize_coin(window->mlx, map);
	initialize_exit(window->mlx, map);
	return (0);
}

int main(int argc, char *argv[])
{
	t_window	window;
	t_image		image;
    t_game 		*game;
	window.mlx = mlx_init();
	if (argc != 2)
	{
		ft_printf("Error: Número de argumentos inválido\n");
		exit (1);
	}
	if (!window.mlx)
	{
		ft_printf("Fallo de mlx\n");
		return (1);
	}
	check_format(argv[1]);
    char *map_file = argv[1];
	game = (t_game *)malloc(sizeof(t_game));
	game->map = (char **)malloc(sizeof(char *) * (game->x_large + 1));
    char *map_content = read_map(map_file, &game);
	game->map = create_map(map_file, &game);
	checker(game);
	window.win = mlx_new_window(window.mlx, game->x_large *  64, game->y_large *  64, "juego");
	mlx_clear_window(window.mlx, window.win);
	initialize(&window, &image);
	render(game, &window, &image);
	mlx_hook(window.win, 2, 0, keyhook, game);
	//mlx_hook(window.win, 17, 0, exit_game, game);
	mlx_loop_hook(window.mlx, render, game);
	mlx_loop(window.mlx);
	free (map_content);
	free (game->map);
	exit (0);
}