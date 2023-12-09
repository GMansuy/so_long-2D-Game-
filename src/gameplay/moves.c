/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:49:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 11:06:18 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_up(t_data *data)
{
	int	interact;

	data->offset_y += 10;
	interact = collision(data);
	if (interact == 3)
		return (data->move_up = 0, data->offset_y -= 10, 1);
	else
		data->moves++;
	if (!interact)
		return (0);
	return (1);
}

int	move_down(t_data *data)
{
	int	interact;

	data->offset_y -= 10;
	interact = collision(data);
	if (interact == 3)
		return (data->move_down = 0, data->offset_y += 10, 1);
	else
		data->moves++;
	if (!interact)
		return (0);
	return (1);
}

int	move_left(t_data *data)
{
	int	interact;

	data->offset_x += 10;
	interact = collision(data);
	if (interact == 3)
		return (data->move_left = 0, data->offset_x -= 10, 1);
	else
		data->moves++;
	if (!interact)
		return (0);
	return (1);
}

int	move_right(t_data *data)
{
	int	interact;

	data->offset_x -= 10;
	interact = collision(data);
	if (interact == 3)
		return (data->move_right = 0, data->offset_x += 10, 1);
	else
		data->moves++;
	if (!interact)
		return (0);
	return (1);
}
