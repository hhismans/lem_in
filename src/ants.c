/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 11:42:34 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 08:40:11 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"

int		pathlen(t_path *path)
{
	int ret;

	ret = 0;
	while (path)
	{
		path = path->next;
		ret++;
	}
	return (ret);
}

void	insert_ants(t_path *path, int name)
{
	int		*tmpname;
	int		len;
	int		i;
	t_path	*begin;

	begin = path;
	len = pathlen(path);
	tmpname = malloc(len * sizeof(int));
	ft_bzero(tmpname, sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		tmpname[i] = path->antsname;
		path = path->next;
	}
	path = begin->next;
	i = 0;
	while (path)
	{
		path->antsname = tmpname[i];
		path = path->next;
		i++;
	}
	begin->antsname = name;
	free(tmpname);
}

int		displaypath(t_path *path)
{
	int		stillants;
	int		ret;

	stillants = 0;
	ret = 0;
	while (path)
	{
		if (path->antsname)
		{
			ft_putchar('L');
			ft_putnbr(path->antsname);
			ft_putchar('-');
			ft_putstr(path->node->name);
			ft_putstr(" ");
			stillants = 1;
			ret = 1;
		}
		path = path->next;
	}
	return (ret);
}

int		stillants(t_pathlist *lpath)
{
	t_path *tmp;

	while (lpath)
	{
		tmp = lpath->path;
		while (tmp)
		{
			if (tmp->antsname)
				return (1);
			tmp = tmp->next;
		}
		lpath = lpath->next;
	}
	return (0);
}

void	finishants(t_pathlist *lpath)
{
	t_pathlist	*tmp;
	int			startline;

	startline = 1;
	tmp = lpath;
	while (stillants(lpath))
	{
		tmp = lpath;
		while (tmp)
		{
			insert_ants(tmp->path, 0);
			displaypath(tmp->path);
			tmp = tmp->next;
			startline = 0;
		}
	}
}
