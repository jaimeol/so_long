/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/20 14:35:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	mlx_destroy_window(&game->win.mlx, &game->win.win);
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

int main(int argc, char *argv[])
{
	t_window	window;
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
	game->map = (char **)malloc(sizeof(char *) * (game->x_large));
    read_map(map_file, &game);
	game->map = create_map(map_file, &game);
	checker(game);
	window.win = mlx_new_window(window.mlx, game->x_large *  64, game->y_large *  64, "juego");
	initialize(&window, &game->image);
	mlx_clear_window(window.mlx, window.win);
	mlx_hook(window.win, 2, 0, keyhook, game);
	mlx_hook(window.win, 17, 0, (void *)exit_game, game);
	mlx_loop_hook(window.mlx, render, game);
	mlx_loop(window.mlx);
	exit (0);
}