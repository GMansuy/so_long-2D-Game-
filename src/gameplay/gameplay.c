/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:40:31 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 11:14:07 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_data *data)
{
	ft_printf("Goodbye !\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free_all(data);
	exit(0);
}

int	move(t_data *data)
{
	int	signal;

	signal = 1;
	if (data->move_up == 1)
		signal = move_up(data);
	if (data->move_down == 1)
		signal = move_down(data);
	if (data->move_left == 1)
		signal = move_left(data);
	if (data->move_right == 1)
		signal = move_right(data);
	return (signal);
}

void	blocked(t_data *data)
{
	if (data->move_up == 3 && data->move_down != 1)
		data->move_up = 1;
	if (data->move_down == 3 && data->move_up != 1)
		data->move_down = 1;
	if (data->move_left == 3 && data->move_right != 1)
		data->move_left = 1;
	if (data->move_right == 3 && data->move_left != 1)
		data->move_right = 1;
	if (data->move_up == 1)
		data->move_down = (data->move_down == 1 || data->move_down == 3) * 3;
	if (data->move_down == 1)
		data->move_up = (data->move_up == 1 || data->move_up == 3) * 3;
	if (data->move_left == 1)
		data->move_right = (data->move_right == 1 || data->move_right == 3) * 3;
	if (data->move_right == 1)
		data->move_left = (data->move_left == 1 || data->move_left == 3) * 3;
}

int	key_release(int keysym, t_data *data)
{
	if (data->move_up == 2)
		data->move_up = 0;
	if (data->move_down == 2)
		data->move_down = 0;
	if (data->move_left == 2)
		data->move_left = 0;
	if (data->move_right == 2)
		data->move_right = 0;
	if (keysym == XK_w || keysym == 17)
		data->move_up = 2;
	else if (keysym == XK_s)
		data->move_down = 2;
	else if (keysym == XK_a)
		data->move_left = 2;
	else if (keysym == XK_d)
		data->move_right = 2;
	return (1);
}

int	key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (data->asset.dead)
		return (1);
	else if (keysym == XK_w)
	{
		data->move_down = (data->move_down == 1 || data->move_down == 3) * 3;
		data->move_up = 1;
	}
	else if (keysym == XK_s)
	{
		data->move_up = (data->move_up == 1 || data->move_up == 3) * 3;
		data->move_down = 1;
	}
	else if (keysym == XK_a)
	{
		data->move_right = (data->move_right == 1 || data->move_right == 3) * 3;
		data->move_left = 1;
	}
	else if (keysym == XK_d)
	{
		data->move_left = (data->move_left == 1 || data->move_left == 3) * 3;
		data->move_right = 1;
	}
	return (1);
}
