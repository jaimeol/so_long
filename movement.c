/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:32:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/14 14:32:50 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_map *scene, int dir)
{
	scene->game.map[scene->game.y_p][scene->game.x_p] = '0';
	if (dir == 0)
		scene->game.y_p += 1;
	if (dir == 1)
		scene->game.y_p -= 1;
	if (dir == 2)
		scene->game.x_p -= 1;
	if (dir == 3)
		scene->game.x_p += 1;
	scene->game.map[scene->game.y_p][scene->game.x_p] = 'P';
}

int	keyhook(int keycode, t_map *scene)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		movement(scene, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		movement(scene, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		movement(scene, 2);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		movement(scene, 3);
	/*if (keycode == KEY_ESCAPE)
		exit_game*/
	return (0);
}
