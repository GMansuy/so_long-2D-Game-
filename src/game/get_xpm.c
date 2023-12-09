/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:01:41 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/21 12:13:38 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	read_xpm(t_link **lst, int fd, int *line_nb)
{
	t_link	*node;

	*lst = init_lst(*lst);
	if (!*lst)
		return (0);
	node = *lst;
	(node)->line = get_next_line(fd);
	while ((node)->line)
	{
		node = add_link_back(node);
		if (!node)
			return (error_free_lst(*lst), 0);
		(node)->line = get_next_line(fd);
		(*line_nb)++;
	}
	return (1);
}

int	lst_to_obj(t_link *lst, t_obj *obj, int line_nb)
{
	int	i;

	obj->xpm_data = (char **) malloc(sizeof(char *) * line_nb + 1);
	if (!obj->xpm_data)
		return (0);
	while (lst && ft_strncmp(lst->line, "/* pixels */", 12) != 0)
		lst = lst->next;
	lst = lst->next;
	i = 0;
	while (lst && ft_strncmp(lst->line, "};", 2) != 0)
	{
		obj->xpm_data[i] = ft_strdup(lst->line + 1);
		if (!obj->xpm_data[i])
			return (0);
		lst = lst->next;
		i++;
	}
	obj->xpm_data[i] = NULL;
	return (1);
}

int	get_xpm_data(t_obj *obj, char *path)
{
	t_link	*lst;
	int		fd;
	int		line_nb;

	lst = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perr_msg("open", 0));
	line_nb = 0;
	if (!read_xpm(&lst, fd, &line_nb))
		return (close(fd), perr_msg("malloc", 0));
	close(fd);
	if (!lst_to_obj(lst, obj, line_nb))
		return (error_free_lst(lst), perr_msg("malloc", 0));
	return (error_free_lst(lst), 1);
}
