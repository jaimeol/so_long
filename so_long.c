/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/17 17:32:08 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

int	exit_game(t_game *game)
{
	free_map (game->map);
	exit (0);
}

void	initialize(t_window *window, t_image *map)
{
	initialize_wall(window->mlx, map);
	initialize_player(window->mlx, map);
	initialize_coin(window->mlx, map);
	initialize_exit(window->mlx, map);
	initialize_road(window->mlx, map);
}

int	render(t_game *game, t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	render_wall(game, &game->image, window);
	render_player(game, &game->image, window);
	render_coin(game, &game->image, window);
	render_exit(game, &game->image, window);
	render_road(game, &game->image, window);
	return (0);
}

void	leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	t_window	window;
	t_game		game;
	char		*map_file;

	atexit(leaks);
	window.mlx = mlx_init();
	if (argc != 2)
		args_error();
	if (!window.mlx)
		mlx_error();
	check_format(argv[1]);
	map_file = argv[1];
	read_map(map_file, &game);
	game.map = create_map(map_file, &game);
	checker(&game);
	game.steps = 0;
	game.player_dir = 1;
	window.win = mlx_new_window(window.mlx, game.x_large * 64,
			game.y_large * 64, "Kachao");
	initialize(&window, &game.image);
	mlx_hook(window.win, 2, 0, keyhook, &game);
	mlx_hook(window.win, 17, 0, exit_game, &game);
	mlx_loop_hook(window.mlx, render, &game);
	mlx_loop(window.mlx);
	exit (0);
}
