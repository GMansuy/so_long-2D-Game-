/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_still_walk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:08:56 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/20 13:44:49 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	choose_l_still(t_asset *player)
{
	if (player->l_count == 10)
	{
		player->l_change++;
		player->l_count = 0;
	}
	if (player->l_change == 0)
		player->curr_still = player->lstill[1];
	else if (player->l_change == 1)
		player->curr_still = player->lstill[2];
	else if (player->l_change == 2)
		player->curr_still = player->lstill[3];
	else if (player->l_change == 3)
		player->curr_still = player->lstill[4];
	else if (player->l_change == 4)
	{
		player->curr_still = player->lstill[0];
		player->l_change = 0;
	}
	player->l_count++;
}

void	choose_still(t_asset *player)
{
	if (player->count == 10)
	{
		player->change++;
		player->count = 0;
	}
	if (player->change == 0)
		player->curr_still = player->still[1];
	else if (player->change == 1)
		player->curr_still = player->still[2];
	else if (player->change == 2)
		player->curr_still = player->still[3];
	else if (player->change == 3)
		player->curr_still = player->still[4];
	else if (player->change == 4)
	{
		player->curr_still = player->still[0];
		player->change = 0;
	}
	player->count++;
}

void	choose_l_walk(t_asset *player)
{
	if (player->count_l_walk == 2)
	{
		player->change_l_walk++;
		player->count_l_walk = 0;
	}
	if (player->change_l_walk == 0)
		player->curr_still = player->lwalk[1];
	else if (player->change_l_walk == 1)
		player->curr_still = player->lwalk[2];
	else if (player->change_l_walk == 2)
		player->curr_still = player->lwalk[3];
	else if (player->change_l_walk == 3)
		player->curr_still = player->lwalk[4];
	else if (player->change_l_walk == 4)
		player->curr_still = player->lwalk[5];
	else if (player->change_l_walk == 5)
		player->curr_still = player->lwalk[6];
	else if (player->change_l_walk == 6)
		player->curr_still = player->lwalk[7];
	else if (player->change_l_walk == 7)
	{
		player->curr_still = player->lwalk[0];
		player->change_l_walk = 0;
	}
	player->count_l_walk++;
}

void	choose_walk(t_asset *player)
{
	if (player->count_walk == 2)
	{
		player->change_walk++;
		player->count_walk = 0;
	}
	if (player->change_walk == 0)
		player->curr_still = player->walk[1];
	else if (player->change_walk == 1)
		player->curr_still = player->walk[2];
	else if (player->change_walk == 2)
		player->curr_still = player->walk[3];
	else if (player->change_walk == 3)
		player->curr_still = player->walk[4];
	else if (player->change_walk == 4)
		player->curr_still = player->walk[5];
	else if (player->change_walk == 5)
		player->curr_still = player->walk[6];
	else if (player->change_walk == 6)
		player->curr_still = player->walk[7];
	else if (player->change_walk == 7)
	{
		player->curr_still = player->walk[0];
		player->change_walk = 0;
	}
	player->count_walk++;
}
