/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:10 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 14:48:55 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_surround(t_data *data, t_path *node)
{
	if (!node->up)
	{
		node->up = discover_y(node, node->up, -1, data);
		if (!node->up)
			return (0);
	}
	if (!node->down)
	{
		node->down = discover_y(node, node->down, 1, data);
		if (!node->down)
			return (0);
	}
	if (!node->left)
	{
		node->left = discover_x(node, node->left, -1, data);
		if (!node->left)
			return (0);
	}
	if (!node->right)
	{
		node->right = discover_x(node, node->right, 1, data);
		if (!node->right)
			return (0);
	}
	return (1);
}

static int	explore_map(t_data *data, t_path *node)
{
	if (!node)
		return (0);
	if (is_visited(data, node))
		return (1);
	node->visited = 1;
	data->is_visited[node->y][node->x] = 1;
	if (node->c == 'E')
		return (1);
	if (!get_surround(data, node))
		return (data->error_recurs = 1, 0);
	if (node->up && node->up->c != '1' && !node->up->visited)
		if (!explore_map(data, node->up))
			return (data->error_recurs = 1, 0);
	if (node->down && node->down->c != '1' && !node->down->visited)
		if (!explore_map(data, node->down))
			return (data->error_recurs = 1, 0);
	if (node->left && node->left->c != '1' && !node->left->visited)
		if (!explore_map(data, node->left))
			return (data->error_recurs = 1, 0);
	if (node->right && node->right->c != '1' && !node->right->visited)
		if (!explore_map(data, node->right))
			return (data->error_recurs = 1, 0);
	if (data->error_recurs == 1)
		return (0);
	return (1);
}

static int	verify_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height / 100)
	{
		j = 0;
		while (j < data->map->width / 100)
		{
			if (data->map->layout[i][j] == 'E' && data->is_visited[i][j] == 0)
				return (0);
			if (data->map->layout[i][j] == 'C' && data->is_visited[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	init_path_checking(t_data *data)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = data->map->height / 100;
	width = data->map->width / 100;
	data->error_recurs = 0;
	data->is_visited = (int **) malloc(sizeof(int *) * height + 1);
	if (!data->is_visited)
		return (msg("malloc : error\n", 0));
	i = -1;
	while (++i < data->map->height / 100)
	{
		j = -1;
		data->is_visited[i] = (int *) malloc(sizeof(int) * width + 1);
		if (!data->is_visited[i])
			return (msg("malloc : error\n", 0));
		while (++j < data->map->width / 100)
			data->is_visited[i][j] = 0;
	}
	return (1);
}

int	find_path(t_data *data)
{
	t_path	*node;

	node = NULL;
	node = init_path(node, data);
	if (!init_path_checking(data))
		return (0);
	if (!explore_map(data, node))
		return (0);
	free_path(node, 0);
	if (verify_path(data))
		return (1);
	else
		return (msg("map : no valid path\n", 0));
}
