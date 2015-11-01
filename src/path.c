/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:34:07 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 08:42:23 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_pathlist	*newpathlist(t_path *data)
{
	t_pathlist *tmp;

	tmp = malloc(sizeof(t_pathlist));
	tmp->path = data;
	tmp->next = NULL;
	return (tmp);
}

t_pathlist	*pathlist_pushfront(t_pathlist **pathl, t_path *path)
{
	t_pathlist *tmp;

	if (*pathl)
	{
		tmp = newpathlist(path);
		tmp->next = *pathl;
		*pathl = tmp;
	}
	else
	{
		*pathl = newpathlist(path);
		tmp = *pathl;
	}
	return (tmp);
}

t_path		*newpath(t_node *node)
{
	t_path *tmp;

	tmp = malloc(sizeof(t_path));
	tmp->antsname = 0;
	tmp->node = node;
	tmp->next = NULL;
	return (tmp);
}

t_path		*path_pushfront(t_path **path, t_node *node)
{
	t_path *tmp;

	if (*path)
	{
		tmp = newpath(node);
		tmp->next = *path;
		*path = tmp;
	}
	else
	{
		*path = newpath(node);
		tmp = *path;
	}
	return (tmp);
}

t_pathlist	*pushbacklpath(t_pathlist **list, t_path *path)
{
	t_pathlist *tmp;

	tmp = *list;
	if (!*list)
	{
		*list = newpathlist(path);
		return (*list);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newpathlist(path);
	return (tmp);
}
