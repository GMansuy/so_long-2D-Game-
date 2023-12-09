/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:49:07 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 11:06:13 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	game_main_loop(t_data *data)
{
	usleep(10000);
	if (!data->win_ptr)
		return (0);
	if (!move(data) || !collision(data) || data->asset.dead == 3)
	{
		sleep(1);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		return (data->win_ptr = NULL, 0);
	}
	blocked(data);
	render_background(data, &(data->asset.background[0]));
	set_render(data);
	shader(data);
	render_life(data);
	count_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (1);
}

static int	game_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &game_main_loop, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key, data);
	mlx_hook(data->win_ptr, 17, NoEventMask, &close_window, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &key_release, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}

int	game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (msg("mlx : error\n", 0));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Little red guy in a random dungeon");
	if (!data->win_ptr)
		return (msg("mlx : error\n", 0));
	data->img.mlx_img = mlx_new_image(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.mlx_img)
		return (msg("mlx : error\n", 0));
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	system("cvlc sound/abyss.mp3 & 1> /dev/null");
	if (!get_assets(data))
		return (0);
	if (!game_hooks(data))
		return (0);
	return (1);
}
