/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ath.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:37:03 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 14:57:19 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_life(t_data *data)
{
	if (data->life <= 1)
		render_asset(data, &data->asset.heart[0], 100, 0);
	else if (data->life <= 5)
		render_asset(data, &data->asset.heart[1], 100, 0);
	else if (data->life <= 12)
		render_asset(data, &data->asset.heart[2], 100, 0);
	else if (data->life <= 20)
		render_asset(data, &data->asset.heart[3], 100, 0);
}

void	render_moves(t_data *data, int moves, int off, int unit)
{
	if (moves / unit == 0)
		render_asset(data, &data->asset.nbr[0], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 1)
		render_asset(data, &data->asset.nbr[1], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 2)
		render_asset(data, &data->asset.nbr[2], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 3)
		render_asset(data, &data->asset.nbr[3], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 4)
		render_asset(data, &data->asset.nbr[4], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 5)
		render_asset(data, &data->asset.nbr[5], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 6)
		render_asset(data, &data->asset.nbr[6], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 7)
		render_asset(data, &data->asset.nbr[7], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 8)
		render_asset(data, &data->asset.nbr[8], WINDOW_WIDTH - 150 - off, 50);
	else if (moves / unit == 9)
		render_asset(data, &data->asset.nbr[9], WINDOW_WIDTH - 150 - off, 50);
}

int	count_moves(t_data *data)
{
	int	moves;

	moves = data->moves / 10;
	render_moves(data, moves % 10, 0, 1);
	if (moves >= 10)
		render_moves(data, moves % 100, 100, 10);
	if (moves >= 100)
		render_moves(data, moves % 1000, 200, 100);
	if (moves >= 1000)
		render_moves(data, moves, 300, 1000);
	return (0);
}
