/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:21:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/22 16:21:25 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_error(void)
{
	ft_printf("Error: Debe haber un jugador\n");
	exit (1);
}
void	coin_error(void)
{
	ft_printf("Error: El mapa debe de tener al menos una moneda\n");
	exit (1);
}

void	exit_error(void)
{
	ft_printf("Error: El mapa debe tener una salida\n");
	exit (1);
}