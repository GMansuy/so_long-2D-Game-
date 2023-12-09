/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:27:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 13:24:23 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_pixel(t_img *asset, int x, int y, int *color)
{
	char	*pixel;

	pixel = asset->addr + (y * asset->line_len + x * (asset->bpp / 8));
	*color = *(int *)pixel;
	return (1);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	if (pixel)
		*(int *)pixel = color;
}

void	render_asset(t_data *data, t_obj *object, int x, int y)
{
	int	color;
	int	i;
	int	j;

	i = y;
	while (i < y + 100)
	{
		j = x;
		while (j < x + 100)
		{
			if (j < 0 || j > WINDOW_WIDTH || i < 0 || i > WINDOW_HEIGHT)
				j++ ;
			else
			{
				get_pixel(&object->obj_img, j - x, i - y, &color);
				if (!object->xpm_data)
					img_pix_put(&data->img, j, i, color);
				else if (!(object->xpm_data[i - y][j - x] == ' '))
					img_pix_put(&data->img, j, i, color);
				j++;
			}
		}
		++i;
	}
}

static void	render_bckg_asset(t_data *data, t_obj *object, int x, int y)
{
	int	color;
	int	i;
	int	j;
	int	output[2];

	i = y - 1;
	while (++i < y + 100)
	{
		j = x - 1;
		while (++j < x + 100)
		{
			get_pixel(&object->obj_img, j - x, i - y, &color);
			output[0] = j + data->offset_x % 1000;
			output[1] = i + data->offset_y % 1000;
			if (output[0] < 0)
				output[0] += WINDOW_WIDTH;
			else if (output[0] > WINDOW_WIDTH)
				output[0] -= WINDOW_WIDTH;
			if (output[1] < 0)
				output[1] += WINDOW_HEIGHT;
			else if (output[1] > WINDOW_HEIGHT)
				output[1] -= WINDOW_HEIGHT;
			img_pix_put(&data->img, output[0], output[1], color);
		}
	}
}

void	render_background(t_data *data, t_obj *object)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			render_bckg_asset(data, object, x, y);
			x += 100;
		}
		y += 100;
	}
}
