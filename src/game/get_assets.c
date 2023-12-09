/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:09:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 11:50:22 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	import_asset(t_data *data, t_img *obj_img, char *path)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	obj_img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&(width), &(height));
	obj_img->addr = mlx_get_data_addr(obj_img->mlx_img, &obj_img->bpp,
			&obj_img->line_len, &obj_img->endian);
	return (1);
}

static char	*add_suffix(char *path, int i)
{
	char	c[2];
	char	*tmp;
	char	*complete_path;

	c[0] = '_';
	c[1] = i + '0';
	tmp = ft_strjoin(path, c);
	if (!tmp)
		return (NULL);
	complete_path = ft_strjoin(tmp, ".xpm");
	return (free(tmp), complete_path);
}

static int	get_asset_path(t_data *data, t_obj *obj, char *path, int iter)
{
	int		i;
	int		fd;
	char	*complete_path;

	i = 0;
	while (i < iter)
	{
		complete_path = add_suffix(path, i);
		if (!complete_path)
			return (msg("malloc : error\n", 0));
		fd = open(complete_path, O_RDONLY);
		if (fd < 0)
			return (free(complete_path), msg("error : unknown asset path\n", 0));
		close(fd);
		import_asset(data, &obj[i].obj_img, complete_path);
		if (!get_xpm_data(&obj[i], complete_path))
		{
			mlx_destroy_image(data->mlx_ptr, obj[i].obj_img.mlx_img);
			return (free(complete_path), 0);
		}
		free(complete_path);
		i++;
	}
	return (1);
}

int	get_more_assets(t_data *data)
{
	if (!get_asset_path(data, data->asset.heart, HEART, 4))
		return (0);
	if (!get_asset_path(data, data->asset.bonus, CHEST, 2))
		return (0);
	if (!get_asset_path(data, data->asset.statue, STATUE, 2))
		return (0);
	if (!get_asset_path(data, data->asset.obs, OBSTACLE, 1))
		return (0);
	if (!get_asset_path(data, data->asset.background, BCKG_PATH, 9))
		return (0);
	if (!get_asset_path(data, data->asset.end, DOOR_STAIRS_PATH, 1))
		return (0);
	if (!get_asset_path(data, data->asset.g, G, 1))
		return (0);
	if (!get_asset_path(data, data->asset.pickup, PICKUP, 3))
		return (0);
	return (1);
}

int	get_assets(t_data *data)
{
	if (!get_asset_path(data, data->asset.still, STILL, 5))
		return (0);
	if (!get_asset_path(data, data->asset.lstill, LSTILL, 5))
		return (0);
	if (!get_asset_path(data, data->asset.walk, WALK, 8))
		return (0);
	if (!get_asset_path(data, data->asset.lwalk, LWALK, 8))
		return (0);
	if (!get_asset_path(data, data->asset.spike, SPIKE, 5))
		return (0);
	if (!get_asset_path(data, data->asset.hit, HIT, 2))
		return (0);
	if (!get_asset_path(data, data->asset.death, DEATH, 5))
		return (0);
	if (!get_asset_path(data, data->asset.nbr, NBR, 10))
		return (0);
	if (!get_more_assets(data))
		return (0);
	return (1);
}
