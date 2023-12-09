/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:51:08 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/22 17:43:51 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (msg("usage: ./so_long <map.ber>\n", 1));
	init_data(&data);
	if (!parsing(&data, argv[1]))
		return (free_all(&data), 2);
	if (!find_path(&data))
		return (free_all(&data), 3);
	if (!game(&data))
		return (free_all(&data), 4);
	return (free_all(&data), 0);
}
