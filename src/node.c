/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 13:13:13 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 06:51:41 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_node		*new_cell(char *name, int x, int y, t_type type)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	(node)->name = ft_strdup(name);
	(node)->x = x;
	(node)->y = y;
	(node)->edge = NULL;
	(node)->next = NULL;
	(node)->father = NULL;
	(node)->cost = INT_MAX;
	(node)->visited = 0;
	node->type = type;
	return (node);
}

int			name_exist(t_node *list, char *str)
{
	while (list)
	{
		if (!ft_strcmp(list->name, str))
		{
			ft_putstr_fd("Error, name already exist: ", 2);
			ft_putendl_fd(str, 2);
			return (1);
		}
		list = list->next;
	}
	return (0);
}

t_node		*add_cell(t_node **list, char **str, t_type type)
{
	t_node *tmp;

	if (*list == NULL)
	{
		*list = new_cell(str[0], ft_atoi(str[1]), ft_atoi(str[2]), type);
	}
	else
	{
		tmp = new_cell(str[0], ft_atoi(str[1]), ft_atoi(str[2]), type);
		tmp->next = *list;
		*list = tmp;
	}
	return (*list);
}
