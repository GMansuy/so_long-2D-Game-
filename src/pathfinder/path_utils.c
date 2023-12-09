/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:03:12 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/20 12:24:46 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//free_path

void	free_path(t_path *node, int move)
{
	if (!node)
		return ;
	if (node->up && move != 2)
		free_path(node->up, 1);
	if (node->down && move != 1)
		free_path(node->down, 2);
	if (node->left && move != 4)
		free_path(node->left, 3);
	if (node->right && move != 3)
		free_path(node->right, 4);
	free(node);
}

t_path	*init_path(t_path *node, t_data *data)
{
	node = malloc(sizeof(t_path));
	if (!node)
		return (perr_msg("malloc", 0), NULL);
	node->up = NULL;
	node->down = NULL;
	node->left = NULL;
	node->right = NULL;
	node->x = data->map->base_p[0];
	node->y = data->map->base_p[1];
	node->c = 'P';
	node->visited = 0;
	return (node);
}

t_path	*discover_x(t_path *old, t_path *new, int diff, t_data *data)
{
	new = malloc(sizeof(t_path));
	if (!new)
		return (perr_msg("malloc", 0), NULL);
	new->x = diff + old->x;
	new->y = old->y;
	new->c = data->map->layout[new->y][new->x];
	new->up = NULL;
	new->down = NULL;
	new->left = NULL;
	new->right = NULL;
	new->visited = 0;
	if (diff < 0)
		new->right = old;
	else
		new->left = old;
	return (new);
}

t_path	*discover_y(t_path *old, t_path *new, int diff, t_data *data)
{
	new = malloc(sizeof(t_path));
	if (!new)
		return (perr_msg("malloc", 0), NULL);
	new->y = diff + old->y;
	new->x = old->x;
	new->c = data->map->layout[new->y][new->x];
	new->up = NULL;
	new->down = NULL;
	new->left = NULL;
	new->right = NULL;
	new->visited = 0;
	if (diff < 0)
		new->down = old;
	else
		new->up = old;
	return (new);
}

int	is_visited(t_data *data, t_path *node)
{
	if (data->is_visited[node->y][node->x] == 1)
		return (1);
	else
		return (0);
}
