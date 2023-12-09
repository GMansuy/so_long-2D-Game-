/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:48:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 11:16:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	null_terminate_lines(char **layout)
{
	int	x;
	int	y;

	y = 0;
	while (layout[y])
	{
		x = 0;
		while (layout[y][x] != '\n' && layout[y][x])
			x++;
		if (layout[y][x] == '\n')
			layout[y][x] = '\0';
		y++;
	}
}

static void	set_size(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->layout[0][x])
		x++;
	data->map->width = x * 100;
	y = 0;
	while (data->map->layout[y])
		y++;
	data->map->height = y * 100;
}

int	parsing(t_data *data, char *map_name)
{
	int	fd;

	if (!ber_check(map_name))
		return (msg("map : File extension must be .ber\n", 0));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (perr_msg("open", 0));
	data->map = malloc (sizeof(t_map));
	if (!data->map)
		return (close(fd), perr_msg("malloc", 0));
	data->map->layout = NULL;
	data->map->relative_x = NULL;
	data->map->relative_y = NULL;
	if (!get_map_layout(data->map, fd))
		return (close(fd), 0);
	if (!data->map->layout[0])
		return (close(fd), msg("map : Invalid file\n", 0));
	null_terminate_lines(data->map->layout);
	set_size(data);
	close(fd);
	if (!layout_map_check(data->map->layout, data))
		return (0);
	if (!get_relative_positions(data->map))
		return (0);
	return (1);
}
