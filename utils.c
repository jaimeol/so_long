/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:31 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/17 18:50:33 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (i > 0)
	{
		dest[j] = s[j];
		i--;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*erase_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

char	**duplicate_map(t_game *game)
{
	int		i;
	char	**aux_map;

	i = 0;
	aux_map = (char **)malloc(sizeof(char *) * (game->y_large));
	while (i < game->y_large)
	{
		aux_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	aux_map[i] = NULL;
	return (aux_map);
}
