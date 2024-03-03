/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:54:34 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/03 19:56:54 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	check_width(game);
	check_walls(game);
	check_char(game);
	check_coins(&game);
	check_exit(game);
}
