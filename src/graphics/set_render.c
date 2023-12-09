/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:13:53 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 15:06:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_abs(t_data *data, int x, int y, char c)
{
	int	abs;

	if (c == 'x')
	{
		abs = data->map->relative_x[((data->map->width / 100) * y) + x];
		abs *= 100;
		abs += PLAYER;
		abs += data->offset_x;
	}
	if (c == 'y')
	{
		abs = data->map->relative_y[((data->map->width / 100) * y) + x];
		abs *= 100;
		abs += PLAYER;
		abs += data->offset_y;
	}
	return (abs);
}

void	player_status(t_data *data)
{
	if (data->asset.dead)
		death_anim(&data->asset);
	else if (data->asset.damage)
		choose_hit(&data->asset);
	else if (data->move_up == 1 || data->move_right == 1)
		choose_walk(&data->asset);
	else if (data->move_down == 1 || data->move_left == 1)
		choose_l_walk(&data->asset);
	else if (data->move_down == 2 || data->move_left == 2)
		choose_l_still(&data->asset);
	else
		choose_still(&data->asset);
	render_asset(data, &data->asset.curr_still, PLAYER, PLAYER);
}

static void	choose_more(t_data *data, int x, int y)
{
	if (data->map->layout[y][x] == '1')
		render_asset(data, &data->asset.obs[0], get_abs(data, x, y, 'x'),
			get_abs(data, x, y, 'y'));
	else if (data->map->layout[y][x] == 'A')
		chest_anim(data, x, y);
	else if (data->map->layout[y][x] == 'B')
	{
		chest_anim(data, x, y);
		render_asset(data, &data->asset.bonus[0], get_abs(data, x, y, 'x'),
			get_abs(data, x, y, 'y'));
	}
}

void	choose_asset(t_data *data, int x, int y)
{
	if (data->map->layout[y][x] == 'C')
		render_asset(data, &data->asset.bonus[0], get_abs(data, x, y, 'x'),
			get_abs(data, x, y, 'y'));
	else if (data->map->layout[y][x] == 'E')
		render_asset(data, &data->asset.end[0], get_abs(data, x, y, 'x'),
			get_abs(data, x, y, 'y'));
	else if (data->map->layout[y][x] == 'S')
		render_asset(data, &data->asset.curr_spike, get_abs(data, x, y, 'x'),
			get_abs(data, x, y, 'y'));
	else
		choose_more(data, x, y);
}

void	set_render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	choose_spike(&data->asset);
	while (y < data->map->height / 100)
	{
		x = 0;
		while (x < data->map->width / 100)
		{
			choose_asset(data, x, y);
			x++;
		}
		y++;
	}
	player_status(data);
}
