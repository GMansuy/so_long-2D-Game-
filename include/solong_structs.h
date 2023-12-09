/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:59:11 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 16:51:03 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_STRUCTS_H
# define SOLONG_STRUCTS_H

typedef struct s_verif
{
	int	zero;
	int	un;
	int	c;
	int	e;
	int	p;
}	t_verif;

typedef struct s_map
{
	char	**layout;
	int		*relative_x;
	int		*relative_y;
	int		width;
	int		height;
	int		base_p[2];
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_obj
{
	t_img	obj_img;
	char	**xpm_data;	
}	t_obj;

typedef struct s_asset
{
	int		count;
	int		change;
	int		count_obs;
	int		change_obs;
	int		l_count;
	int		l_change;
	int		count_walk;
	int		change_walk;
	int		count_l_walk;
	int		change_l_walk;
	int		count_spike;
	int		spike_status;
	int		spike_dir;
	int		damage;
	int		count_hit;
	int		hit_status;
	int		dead;
	int		count_death;
	int		death_status;
	t_obj	curr_still;
	t_obj	curr_pick;
	t_obj	curr_spike;
	t_obj	still[5];
	t_obj	lstill[5];
	t_obj	walk[8];
	t_obj	lwalk[8];
	t_obj	spike[5];
	t_obj	hit[2];
	t_obj	death[5];
	t_obj	nbr[10];
	t_obj	heart[4];	
	t_obj	bonus[2];
	t_obj	statue[2];
	t_obj	obs[2];
	t_obj	background[9];
	t_obj	end[2];
	t_obj	g[2];
	t_obj	pickup[3];
}	t_asset;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		key_pressed;
	int		count_pick;
	int		change_pick;
	int		pick_position;
	int		**is_visited;
	int		error_recurs;
	int		stat_delay;
	int		moves;
	int		life;
	int		offset_x;
	int		offset_y;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	t_verif	*verif;
	t_map	*map;
	t_img	img;
	t_asset	asset;
}	t_data;

#endif
