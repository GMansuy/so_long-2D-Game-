/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 14:45:10 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ber_check(char *file_name)
{
	int			i;

	i = 0;
	while (file_name[i])
		i++;
	if (ft_strncmp(file_name + i - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	is_rect(char **layout, int x, int y)
{
	int	base_size;
	int	row_size;

	base_size = 0;
	row_size = 0;
	while (layout[0][x])
	{
			base_size++;
			x++;
	}
	while (layout[y])
	{
		x = 0;
		row_size = 0;
		while (layout[y][x])
		{
			x++;
			row_size++;
		}
		if (row_size != base_size)
			return (msg("map : not a rectangle\n", 0));
		y++;
	}
	return (1);
}

static int	check_borders(char **layout, int x, int y)
{
	while (layout[0][x])
	{
		if (layout[0][x] != '1')
			return (msg("map : invalid borders\n", 0));
		x++;
	}
	x--;
	while (layout[y])
	{
		if (layout[y][0] != '1')
			return (msg("map : invalid borders\n", 0));
		if (layout[y][x] != '1')
			return (msg("map : invalid borders\n", 0));
		y++;
	}
	y--;
	x = 0;
	while (layout[y][x])
	{
		if (layout[y][x] != '1')
			return (msg("map : invalid borders\n", 0));
		x++;
	}
	return (1);
}

static int	check_chars(char **layout, int x, int y, t_verif *verif)
{
	while (layout[y])
	{
		x = 0;
		while (layout[y][x])
		{
			if (layout[y][x] == '0' || layout[y][x] == 'S')
				verif->zero++;
			else if (layout[y][x] == '1')
				verif->un++;
			else if (layout[y][x] == 'C')
				verif->c++;
			else if (layout[y][x] == 'E')
				verif->e++;
			else if (layout[y][x] == 'P')
				verif->p++;
			else
				return (msg("map : invalid character used\n", 0));
			x++;
		}
		y++;
	}
	if (verif->c < 1 || verif->e != 1 || verif->p != 1)
		return (msg("map : only one P / only one E / at least one C\n", 0));
	return (1);
}

int	layout_map_check(char **layout, t_data *data)
{
	int		x;
	int		y;
	t_verif	*verif;

	verif = malloc (sizeof(t_verif));
	if (!verif)
		return (0);
	data->verif = verif;
	verif->zero = 0;
	verif->un = 0;
	verif->c = 0;
	verif->e = 0;
	verif->p = 0;
	x = 0;
	y = 0;
	if (!is_rect(layout, x, y))
		return (free(verif), 0);
	if (!check_borders(layout, x, y))
		return (free(verif), 0);
	if (!check_chars(layout, x, y, verif))
		return (free(verif), 0);
	return (free(verif), 1);
}
