/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:43:36 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 12:01:50 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define PLAYER 450
# define HITBOX 550

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"
# include "solong_structs.h"
# include "solong_path.h"
# include "my_lst.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>

//init.c
void	init_data(t_data *data);
//msg.c
int		msg(char *msg, int err);
int		perr_msg(char *msg, int err);
//free.c
void	free_all(t_data *data);

//--------------------------------------             1 _ PARSING

int		parsing(t_data *data, char *map_name);
//parsing_read_map.c
int		get_map_layout(t_map *map, int fd);
//parsing_check_map.c
int		ber_check(char *file_name);
int		layout_map_check(char **layout, t_data *data);
//parsing_lst.c
t_link	*add_link_back(t_link *node);
t_link	*init_lst(t_link *node);
void	free_lst(t_link *node);
void	error_free_lst(t_link *node);
//parsing_relative_positions.c
int		get_relative_positions(t_map *map);

//----------------------------------------           2 _ PATH
//path.c
int		find_path(t_data *data);
//path_utils.c
int		is_visited(t_data *data, t_path *node);
t_path	*discover_x(t_path *old, t_path *new, int diff, t_data *data);
t_path	*discover_y(t_path *old, t_path *new, int diff, t_data *data);
t_path	*init_path(t_path *node, t_data *data);
void	free_path(t_path *node, int move);

//----------------------------------------           3 _ GAME

//game.c
int		game(t_data *data);
int		close_window(t_data *data);
//get_assets.c
int		get_assets(t_data *data);
int		get_xpm_data(t_obj *obj, char *path);

//-----------------------------------------         4_GRAPHICS

//render.c
void	render_asset(t_data *data, t_obj *object, int x, int y);
void	render_background(t_data *data, t_obj *object);
//set_render.c
void	set_render(t_data *data);
int		get_abs(t_data *data, int x, int y, char c);
int		get_pixel(t_img *asset, int x, int y, int *color);
//shader.c
void	darken(int *rgb, int x, int y);
void	shader(t_data *data);
void	chest_anim(t_data *data, int x, int y);
//convert_trgb.c
int		convert_trgb(int color, int x, int y);
//ath.c
void	render_life(t_data *data);
int		count_moves(t_data *data);
//anim_still_walk.c
void	choose_still(t_asset *player);
void	choose_l_still(t_asset *player);
void	choose_walk(t_asset *player);
void	choose_l_walk(t_asset *player);
//anim_hit_spike.c
void	choose_hit(t_asset *player);
t_obj	*choose_spike(t_asset *spike);
void	death_anim(t_asset *player);

//----------------------------------------              4 _ GAMEPLAY
//gameplay.c
int		key(int keysym, t_data *data);
int		key_release(int keysym, t_data *data);
int		move(t_data *data);
void	blocked(t_data *data);
//collision.c
int		collision(t_data *data);
int		check_hitbox(t_data *data, int x, int y, int obj_hitbox);
//moves.c
void	are_you_blocked(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);

#endif
