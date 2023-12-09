/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:20:27 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 15:15:14 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	chest_anim(t_data *data, int x, int y)
{
	if (data->map->layout[y][x] == 'B')
	{
		if (data->count_pick == 0)
			data->map->layout[y][x] = 'A';
		return ;
	}
	render_asset(data, &data->asset.bonus[1], get_abs(data, x, y, 'x'),
		get_abs(data, x, y, 'y'));
	if (data->count_pick < 30)
	{	
		data->pick_position = data->count_pick * 2;
	}
	render_asset(data, &data->asset.pickup[data->change_pick],
		get_abs(data, x, y, 'x'),
		get_abs(data, x, y, 'y') - data->pick_position);
	data->count_pick += 8;
	if (data->count_pick >= 50)
	{
		data->map->layout[y][x] = '0';
		if (data->change_pick < 2)
			data->change_pick++;
		else
			data->change_pick = 0;
		data->count_pick = 0;
	}
}

void	darken(int *rgb, int x, int y)
{
	int	rayon;
	int	d_x;
	int	d_y;

	d_x = x - 500;
	if (d_x < 0)
		d_x *= -1;
	d_y = y - 500;
	if (d_y < 0)
		d_y *= -1;
	rayon = sqrt(d_x * d_x + d_y * d_y);
	rayon = rayon * 10 / 9;
	if (rayon > 100)
	{
		rgb[0] = rgb[0] * 100 / rayon;
		rgb[1] = rgb[1] * 100 / rayon;
		rgb[2] = rgb[2] * 100 / rayon;
	}
}

void	shader(t_data *data)
{
	int		x;
	int		y;
	char	*pixel;
	int		color;
	int		bp;

	bp = data->img.bpp / 8;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel = data->img.addr + (y * data->img.line_len + x * bp);
			color = *(int *)pixel;
			color = convert_trgb(color, x, y);
			*(int *)pixel = color;
			x ++;
		}
		y ++;
	}
}
