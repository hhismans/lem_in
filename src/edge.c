/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 13:10:02 by hhismans          #+#    #+#             */
/*   Updated: 2015/10/28 20:45:01 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_edge	*new_edge(t_node *node)
{
	t_edge *ret;

	ret = malloc(sizeof(t_edge));
	ret->node = node;
	ret->next = NULL;
	return (ret);
}

t_edge	*edge_pushfront(t_edge **edge, t_node *node)
{
	t_edge *tmp;

	if (*edge)
	{
		tmp = new_edge(node);
		tmp->next = *edge;
		*edge = tmp;
	}
	else
	{
		*edge = new_edge(node);
		tmp = *edge;
	}
	return (tmp);
}

int		edge_exist(t_edge *list, t_node *node)
{
	while (list)
	{
		if (node == list->node)
		{
			ft_putstr_fd("Error, edge already exist: ", 2);
			return (1);
		}
		list = list->next;
	}
	return (0);
}

int		add_edge(t_node *node, char *name1, char *name2)
{
	char	*tmpstr;
	t_node	*tmpnode;

//	if (!edge_exist(node, node))
	while (node)
	{
		if (!ft_strcmp(name1, node->name) || !ft_strcmp(name2, node->name))
		{
			tmpnode = node;
			tmpstr = (!ft_strcmp(name1, node->name)) ? name2 : name1;
			while (node->next)
			{
				node = node->next;
				if (!ft_strcmp(tmpstr, node->name))
				{
					edge_pushfront(&(tmpnode->edge), node);
					edge_pushfront(&(node->edge), tmpnode);
					return (1);
				}
			}
			break ;
		}
		node = node->next;
	}
	ft_putstr_fd("Error name not found for this edge: ", 2);
	return (0);
}
