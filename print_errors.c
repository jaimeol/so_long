/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:11:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/03 19:51:55 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	width_error(void)
{
	printf ("Error: Las líneas deben tener la misma longitud\n");
	exit (1);
}

void	wall_error(void)
{
	printf("Error: El mapa debe estar rodeado de muros\n");
	exit (1);
}

void	char_error(void)
{
	printf("Error: El mapa solo puede estar compuesto por los caracteres 1, 0, P, E y C\n");
	exit (1);
}

void	coin_error(void)
{
	printf("Error: El mapa debe de tener al menos una moneda\n");
	exit (1);
}

void	exit_error(void)
{
	printf("Error: El mapa debe tener una salida\n");
	exit (1);
}
