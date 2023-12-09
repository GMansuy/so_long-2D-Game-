/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:41:34 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/19 12:08:07 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LST_H
# define MY_LST_H

typedef struct s_link
{
	char			*line;
	struct s_link	*next;
}			t_link;

typedef struct s_path
{
	int				x;
	int				y;
	int				visited;
	char			c;
	struct s_path	*up;
	struct s_path	*down;
	struct s_path	*left;
	struct s_path	*right;
}			t_path;

#endif
