/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:28:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 10:53:35 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	the_end(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < map->height / 100)
	{
		i = 0;
		while (i < map->width / 100)
		{
			if (map->layout[j][i] == 'C')
				return (3);
			i++;
		}
		j++;
	}
	system("cvlc sound/Success3.wav &");
	return (ft_printf("GGWP!\n"), 0);
}

int	death(t_data *data)
{
	if (data->asset.dead)
		return (1);
	if (data->life == 0)
	{
		data->asset.dead = 1;
		system("cvlc sound/GameOver2.wav &");
		return (ft_printf("YOU DIED!\n"), 1);
	}
	else
	{
		if (data->life % 5 == 0)
			system("cvlc sound/Hit.wav &");
		data->asset.damage = 1;
		return (data->life--, 1);
	}
}

int	check_hitbox(t_data *data, int x, int y, int obj_hitbox)
{
	int	abs_x;
	int	abs_y;
	int	i;

	abs_x = get_abs(data, x, y, 'x') + obj_hitbox;
	abs_y = get_abs(data, x, y, 'y') + obj_hitbox;
	i = 0;
	while (i < 80 - obj_hitbox)
	{
		if ((abs_x > PLAYER && abs_x < HITBOX
				&& abs_y > PLAYER + 40 && abs_y < HITBOX)
			|| (abs_x + i > PLAYER && abs_x + i < HITBOX
				&& abs_y + i > PLAYER + 40 && abs_y + i < HITBOX)
			|| (abs_x + i > PLAYER && abs_x + i < HITBOX
				&& abs_y > PLAYER + 40 && abs_y < HITBOX)
			|| (abs_x > PLAYER && abs_x < HITBOX
				&& abs_y + i > PLAYER + 40 && abs_y + i < HITBOX))
			return (0);
		i++;
	}
	return (1);
}

static int	collision_options(t_data *data, int x, int y)
{
	if (data->map->layout[y][x] == '1')
		if (!check_hitbox(data, x, y, 20))
			return (3);
	if (data->map->layout[y][x] == 'C')
	{
		if (!check_hitbox(data, x, y, 20))
		{
			system("cvlc sound/Gold1.wav &");
			if (data->count_pick != 0)
				return (data->map->layout[y][x] = 'B', 2);
			return (data->map->layout[y][x] = 'A', 2);
		}
	}
	if (data->map->layout[y][x] == 'E')
		if (!check_hitbox(data, x, y, 20))
			return (the_end(data->map));
	if (data->map->layout[y][x] == 'S')
		if (!check_hitbox(data, x, y, 20) && data->asset.spike_status > 2)
			return (death(data));
	return (4);
}

int	collision(t_data *data)
{
	int	x;
	int	y;
	int	signal;

	y = 0;
	while (y < data->map->height / 100)
	{
		x = 0;
		while (x < data->map->width / 100)
		{
			signal = collision_options(data, x, y);
			if (signal != 4)
				return (signal);
			x++;
		}
		y++;
	}
	return (1);
}
