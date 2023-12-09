/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:18:23 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 16:54:10 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_asset(t_data *data)
{
	data->asset.count = 0;
	data->asset.change = 0;
	data->asset.l_count = 0;
	data->asset.l_change = 0;
	data->asset.count_walk = 0;
	data->asset.change_walk = 0;
	data->asset.count_l_walk = 0;
	data->asset.change_l_walk = 0;
	data->asset.curr_still = data->asset.still[0];
	data->asset.count_spike = 0;
	data->asset.spike_status = 0;
	data->asset.spike_dir = 1;
	data->asset.damage = 0;
	data->asset.hit_status = 0;
	data->asset.count_hit = 0;
	data->asset.dead = 0;
	data->asset.death_status = 0;
	data->asset.count_death = 0;
	data->asset.count = 0;
	data->asset.count = 0;
	data->asset.count = 0;
}

static void	init_game(t_data *data)
{
	data->moves = 0;
	data->life = 20;
	data->offset_x = 0;
	data->offset_y = 0;
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->stat_delay = 0;
	data->count_pick = 0;
	data->change_pick = 0;
	data->pick_position = 0;
	data->key_pressed = 0;
}

static void	loop_asset_null(t_obj *obj, int iter)
{
	int	i;

	i = -1;
	while (++i < iter)
		obj[i].xpm_data = NULL;
}

static void	init_xpm(t_asset *asset)
{
	loop_asset_null(asset->still, 5);
	loop_asset_null(asset->lstill, 5);
	loop_asset_null(asset->walk, 8);
	loop_asset_null(asset->lwalk, 8);
	loop_asset_null(asset->spike, 5);
	loop_asset_null(asset->hit, 2);
	loop_asset_null(asset->death, 5);
	loop_asset_null(asset->nbr, 10);
	loop_asset_null(asset->heart, 4);
	loop_asset_null(asset->bonus, 2);
	loop_asset_null(asset->statue, 2);
	loop_asset_null(asset->obs, 1);
	loop_asset_null(asset->background, 9);
	loop_asset_null(asset->end, 1);
	loop_asset_null(asset->g, 1);
	loop_asset_null(asset->pickup, 3);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.mlx_img = NULL;
	data->verif = NULL;
	data->map = NULL;
	data->is_visited = NULL;
	init_game(data);
	init_asset(data);
	init_xpm(&data->asset);
}
