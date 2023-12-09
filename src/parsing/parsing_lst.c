/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:41:24 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/20 11:19:49 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_lst(t_link *node)
{
	t_link	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	error_free_lst(t_link *node)
{
	t_link	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
	}
}

t_link	*add_link_back(t_link *node)
{
	t_link	*new;

	new = malloc(sizeof(t_link));
	if (!new)
		return (perr_msg("malloc", 0), NULL);
	node->next = new;
	new->next = NULL;
	return (new);
}

t_link	*init_lst(t_link *node)
{
	node = malloc(sizeof(t_link));
	if (!node)
		return (perr_msg("malloc", 0), NULL);
	node->next = NULL;
	return (node);
}
