/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/13 17:54:43 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_line(char *line, t_list **list)
{
	t_list	*node;
	t_list	*aux;

	node = (t_list *) malloc (sizeof (t_list));
	if (!node)
		return ;
	node->content = line;
	node->next = NULL;
	aux = *list;
	if (*list)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
	else
		*list = node;
	(*list)->size++;
}

int	read_file(void)
{
	int	fd;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	create_map(t_game *game,t_list *list, int size)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof (char *) * (size + 1));
	while (i < size)
	{
		game->map[i] = list->content;
		i++;
		list = list->next;
	}
	game->columns = ft_strlen(game->map[0]);
	game->rows =  size;
	game->map[i] = NULL;
}

void	read_map(t_game *game)
{
	t_list	*list;
	int		fd;
	char	*line;
	
	fd = read_file();
	list  = NULL;
	game->map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_line(line, &list);
	}
	create_map (game, list, list->size);
	free (list);
	checker(game);
}
