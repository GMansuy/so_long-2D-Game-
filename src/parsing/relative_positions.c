/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:21 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 11:18:01 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	find_p(t_map *map, int *p_x, int *p_y)
{
	while (map->layout[*p_y])
	{
		*p_x = 0;
		while (map->layout[*p_y][*p_x])
		{
			if (map->layout[*p_y][*p_x] == 'P')
				return (1);
			(*p_x)++;
		}
		(*p_y)++;
	}
	return (0);
}

static void	set_relative(t_map *map, int p_x, int p_y)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < map->height / 100)
	{
		x = 0;
		while (x < map->width / 100)
		{
			map->relative_x[i] = x - p_x;
			map->relative_y[i] = y - p_y;
			x++;
			i++;
		}
		y++;
	}
}

int	get_relative_positions(t_map *map)
{
	int	p_x;
	int	p_y;
	int	map_size;

	map_size = (map->width / 100) * (map->height / 100);
	p_x = 0;
	p_y = 0;
	map->relative_x = (int *) malloc(sizeof(int) * map_size + 1);
	if (!map->relative_x)
		return (perr_msg("malloc", 0));
	map->relative_y = (int *) malloc(sizeof(int) * map_size + 1);
	if (!map->relative_y)
		return (perr_msg("malloc", 0));
	find_p(map, &p_x, &p_y);
	map->base_p[0] = p_x;
	map->base_p[1] = p_y;
	set_relative(map, p_x, p_y);
	return (1);
}
