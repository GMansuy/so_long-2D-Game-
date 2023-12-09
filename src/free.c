/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:08:24 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 11:16:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_layout(t_data *data, char **layout, int **is_visited)
{
	int	i;

	i = 0;
	while (data->map->layout[i])
	{
		if (layout && layout[i])
			free(layout[i]);
		if (is_visited && is_visited[i])
			free(is_visited[i]);
		i++;
	}
	if (layout)
		free(layout);
	if (is_visited)
		free(is_visited);
}

static void	loop_asset_free(t_data *data, t_obj *obj, int iter)
{
	int	i;
	int	j;

	i = 0;
	while (i < iter)
	{
		if (!obj[i].xpm_data)
			return ;
		j = 0;
		while (obj[i].xpm_data[j])
		{
			free(obj[i].xpm_data[j]);
			j++;
		}
		free(obj[i].xpm_data);
		mlx_destroy_image(data->mlx_ptr, obj[i].obj_img.mlx_img);
		i++;
	}
}

static void	free_more_asset(t_data *data)
{
	if (data->asset.heart)
		loop_asset_free(data, data->asset.heart, 4);
	if (data->asset.bonus)
		loop_asset_free(data, data->asset.bonus, 2);
	if (data->asset.statue)
		loop_asset_free(data, data->asset.statue, 2);
	if (data->asset.obs)
		loop_asset_free(data, data->asset.obs, 1);
	if (data->asset.background)
		loop_asset_free(data, data->asset.background, 9);
	if (data->asset.end)
		loop_asset_free(data, data->asset.end, 1);
	if (data->asset.g)
		loop_asset_free(data, data->asset.g, 1);
	if (data->asset.pickup)
		loop_asset_free(data, data->asset.pickup, 3);
}

static void	free_asset(t_data *data)
{
	if (data->asset.still)
		loop_asset_free(data, data->asset.still, 5);
	if (data->asset.lstill)
		loop_asset_free(data, data->asset.lstill, 5);
	if (data->asset.walk)
		loop_asset_free(data, data->asset.walk, 8);
	if (data->asset.lwalk)
		loop_asset_free(data, data->asset.lwalk, 8);
	if (data->asset.spike)
		loop_asset_free(data, data->asset.spike, 5);
	if (data->asset.hit)
		loop_asset_free(data, data->asset.hit, 2);
	if (data->asset.death)
		loop_asset_free(data, data->asset.death, 5);
	if (data->asset.nbr)
		loop_asset_free(data, data->asset.nbr, 10);
	free_more_asset(data);
}

void	free_all(t_data *data)
{
	if (data->map)
	{
		if (data->map->layout)
			free_layout(data, data->map->layout, data->is_visited);
		if (data->map->relative_x)
			free(data->map->relative_x);
		if (data->map->relative_y)
			free(data->map->relative_y);
		free(data->map);
	}
	free_asset(data);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		system("pkill vlc");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
