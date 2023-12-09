/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_hit_spike.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:21:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 15:18:25 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	death_anim(t_asset *player)
{
	if (player->count_death == 5)
	{
		player->death_status++;
		player->count_death = 0;
	}
	if (player->death_status == 0)
		player->curr_still = player->death[0];
	else if (player->death_status == 1)
		player->curr_still = player->death[1];
	else if (player->death_status == 2)
		player->curr_still = player->death[2];
	else if (player->death_status == 3)
		player->curr_still = player->death[3];
	else if (player->death_status == 4)
	{
		player->curr_still = player->death[4];
		player->dead = 3;
	}
	player->count_death++;
}

void	choose_hit(t_asset *player)
{
	if (player->count_hit == 2)
	{
		player->hit_status++;
		player->count_hit = 0;
	}
	if (player->hit_status == 0)
		player->curr_still = player->hit[0];
	else if (player->hit_status == 1)
	{
		player->curr_still = player->hit[1];
		player->hit_status = 0;
		player->count_hit = 0;
		player->damage = 0;
	}
	player->count_hit++;
}

void	spike_count(t_asset *player)
{	
	if (player->count_spike == 10)
	{
		if (player->spike_dir == 1)
			player->spike_status++;
		else
			player->spike_status--;
		player->count_spike = 0;
	}
}

t_obj	*choose_spike(t_asset *player)
{
	spike_count(player);
	if (player->spike_status == 0)
	{
		player->curr_spike = player->spike[0];
		player->spike_dir = 1;
	}
	else if (player->spike_status == 1)
		player->curr_spike = player->spike[1];
	else if (player->spike_status == 2)
		player->curr_spike = player->spike[2];
	else if (player->spike_status == 3)
		player->curr_spike = player->spike[3];
	else if (player->spike_status == 4)
	{
		player->curr_spike = player->spike[4];
		player->spike_dir = 0;
	}
	player->count_spike++;
	return (&player->curr_spike);
}
