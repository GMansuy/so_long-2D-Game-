/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_trgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:45:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/20 13:46:44 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	convert_trgb(int color, int x, int y)
{
	int	t;
	int	rgb[3];

	t = get_t(color);
	rgb[0] = get_r(color);
	rgb[1] = get_g(color);
	rgb[2] = get_b(color);
	darken(rgb, x, y);
	return (t << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
