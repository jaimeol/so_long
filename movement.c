/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:32:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/20 15:50:41 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->y_p - 1][game->x_p] == '1')
		return ;
	if (game->map[game->y_p - 1][game->x_p] == 'C')
		game->c_num--;
	if (game->map[game->y_p - 1][game->x_p] == 'E'
	&& game->c_num == 0)
		exit_game(game);
	if (game->map[game->y_p - 1][game->x_p] == 'E'
	&& game->c_num != 0)
		return ;
	game->map[game->y_p][game->x_p] = '0';
	game->map[game->y_p - 1][game->x_p] = 'P';
	game->y_p--;
	game->player_dir = 0;
}
void	move_down(t_game *game)
{
	if (game->map[game->y_p + 1][game->x_p] == '1')
		return ;
	if (game->map[game->y_p + 1][game->x_p] == 'C')
		game->c_num--;
	if (game->map[game->y_p + 1][game->x_p] == 'E'
	&& game->c_num == 0)
		exit_game(game);
	if (game->map[game->y_p + 1][game->x_p] == 'E'
	&& game->c_num != 0)
		return ;
	game->map[game->y_p][game->x_p] = '0';
	game->map[game->y_p + 1][game->x_p] = 'P';
	game->y_p++;
	game->player_dir = 1;
}

void	move_right(t_game *game)
{
	if (game->map[game->y_p][game->x_p + 1] == '1')
		return ;
	if (game->map[game->y_p][game->x_p + 1] == 'C')
		game->c_num--;
	if (game->map[game->y_p][game->x_p + 1] == 'E'
	&& game->c_num == 0)
		exit_game(game);
	if (game->map[game->y_p][game->x_p + 1] == 'E'
	&& game->c_num != 0)
		return ;
	game->map[game->y_p][game->x_p] = '0';
	game->map[game->y_p][game->x_p + 1] = 'P';
	game->x_p++;
	game->player_dir = 2;
}

void	move_left(t_game *game)
{
	if (game->map[game->y_p][game->x_p - 1] == '1')
		return ;
	if (game->map[game->y_p][game->x_p - 1] == 'C')
		game->c_num--;
	if (game->map[game->y_p][game->x_p - 1] == 'E'
	&& game->c_num == 0)
		exit_game(game);
	if (game->map[game->y_p][game->x_p - 1] == 'E'
	&& game->c_num != 0)
		return ;
	game->map[game->y_p][game->x_p] = '0';
	game->map[game->y_p][game->x_p - 1] = 'P';
	game->x_p--;
	game->player_dir = 3;
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	if (keycode == KEY_ESCAPE)
		exit_game(game);
	return (0);
}
