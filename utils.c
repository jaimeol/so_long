/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:31 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/28 18:32:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (len > (ft_strlen(s)) - start)
		len = (ft_strlen(s) - start);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i < len && *(s + i) != '\0')
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

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
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		ft_substr(str, 0, i);
	return (str);
}
