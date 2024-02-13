/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/13 13:23:15 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_file(void)
{
	int	fd;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	create_map()
