/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:25:21 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/20 13:04:32 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	fill_map_layout(t_map *map, t_link *node)
{
	int	i;

	i = 0;
	while (node)
	{
		map->layout[i] = node->line;
		node = node->next;
		i++;
	}
	map->layout[i] = NULL;
}

static int	fill_node(t_link **node_first, int fd)
{
	int		line_nb;
	t_link	*node;

	node = *node_first;
	line_nb = 0;
	(node)->line = get_next_line(fd);
	line_nb = 0;
	while ((node)->line)
	{
		node = add_link_back(node);
		if (!node)
			return (-1);
		(node)->line = get_next_line(fd);
		line_nb++;
	}
	return (line_nb);
}

int	get_map_layout(t_map *map, int fd)
{
	t_link	*node;
	int		line_nb;

	node = NULL;
	node = init_lst(node);
	if (!node)
		return (0);
	line_nb = fill_node(&node, fd);
	if (line_nb == -1)
		return (error_free_lst(node), 0);
	map->layout = malloc (sizeof(char *) * (line_nb + 2));
	if (!map->layout)
		return (error_free_lst(node), perr_msg("malloc", 0));
	fill_map_layout(map, node);
	free_lst(node);
	return (1);
}
