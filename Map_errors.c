/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:11:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/22 12:36:39 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	width_error(void)
{
	ft_printf ("Error: Las líneas deben tener la misma longitud\n");
	exit (1);
}

void	wall_error(void)
{
	ft_printf("Error: El mapa debe estar rodeado de muros\n");
	exit (1);
}

void	char_error(void)
{
	ft_printf("Error: El mapa debe estar compuesto solo por 1, 0, P, E y C\n");
	exit (1);
}

void	path_error(void)
{
	ft_printf("Error: El mapa debe poder completarse\n");
	exit (1);
}

void	format_error(void)
{
	ft_printf("Error: El formato del mapa debe ser .ber\n");
	exit (1);
}
