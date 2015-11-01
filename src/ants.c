/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 11:42:34 by hhismans          #+#    #+#             */
/*   Updated: 2015/10/29 18:34:15 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>

void	debugdisplay(t_path *path)
{
	while (path)
	{
		printf("path = %s\n", path->node->name);
		path = path->next;
	}
}
int	pathlen(t_path *path)
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
	int *tmpname;
	int len;
	int i;

	t_path *begin;

		//debugdisplay(path);
		begin = path;
		len = pathlen(path);
		tmpname = malloc(len * sizeof(int));
		ft_bzero(tmpname, sizeof(int) * len);
		i = 0;
		while (i < len)
		{
			tmpname[i] = path->antsname;
			path = path->next;
			i++;
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
	/*
	** prend path
	** t<path : antsname, s_node,*nest
	*/
	int	displaypath(t_path *path, int startline)
	{
		int stillants;
		int ret;
	//	t_path *debug = path;
		
		stillants = 0;
		ret = 0;
		while (path)
		{
			if (path->antsname)
			{
				if (!startline)
				{
					ft_putstr(" ");
					startline = 0;
				}
				ft_putchar('L');
				ft_putnbr(path->antsname);
				ft_putchar('-');
				ft_putstr(path->node->name);
				if (path->next && path->next->antsname)
					ft_putstr(" ");
				stillants = 1;
				ret = 1;
			}
			path = path->next;
		}
	/*	while (debug)
		{
			printf("path : %s   antsname %d\n", debug->node->name, debug->antsname);
			debug = debug->next;
		}*/
		return (ret);
	}

/*
** NAME			:	ANTS
** DESCRIPTION	:	receive tab of path, and display the
** 			path of ants on stdout
** INPUT		:	
** RETURN VALUE	:	
*/
void	ants(t_pathlist *lpath, int nbrofants)
{
	int		antsname;
	t_pathlist	*tmp;
	int		startline;
	int		turn;

	antsname = 1;
	turn = 0;
	while (antsname <= nbrofants)
	{
		tmp = lpath;
		startline = 1;
		while (tmp && antsname <= nbrofants)
		{
			insert_ants(tmp->path, antsname);
			displaypath(tmp->path, startline);
			tmp = tmp->next;
			antsname++;
			startline = 0;
		}
		ft_putstr("\n");
		turn++;
	}
}
