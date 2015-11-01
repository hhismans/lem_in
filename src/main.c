/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 11:42:34 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 06:53:02 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>

int			is_correct_syntax(const char *str, t_node **list, t_type *type)
{
	char **split;

	if (str[0] == '#')
	{
		if (!ft_strcmp(str, "##end"))
		{
			*type = END;
			return (COMMAND);
		}
		else if (!ft_strcmp(str, "##start"))
		{
			*type = START;
			return (COMMAND);
		}
		*type = STANDART;
		return (COMMENTARY);
	}
	split = ft_strsplit(str, ' ');
	if (tablen(split) == 3 && !ft_contain(split[0], '-') &&
			!name_exist(*list, split[0]))
	{
		add_cell(list, split, *type);
		freetab(split);
		return (NODE);
	}
	else if (tablen(split) == 1)
	{
		freetab(split);
		split = ft_strsplit(str,'-');
		if (tablen(split) == 2)
		{
			if (add_edge(*list, split[0], split[1]))
			{
				freetab(split); // a changer
				return (EDGE);
			}
		}
	}
	else
	{
		ft_putstr_fd("Syntax error : ", 2);
		ft_putendl_fd(str, 2);
	}
	freetab(split);
	return (FALSE);
}

void affichage(t_node *list)
{
	t_edge *tmp;

	char type [3][10];
	ft_bzero(type[0], 10);
	ft_bzero(type[1], 10);
	ft_bzero(type[2], 10);

	ft_strcpy(type[0], "standart");
	ft_strcpy(type[1], "start");
	ft_strcpy(type[2], "end");

	while (list)
	{
		tmp = list->edge;
		printf("nom = %s, x = %d, y = %d, type = %s\n", list->name, list->x, list->y, type[list->type]);
		while (tmp)
		{
			printf("edge to : %s\n", tmp->node->name);
			tmp = tmp->next;
		}
		list = list->next;
	}
}

int main(void)
{
	char *str;
	t_node *list;
	int error;
	int nbrofants;
	t_type type;
	t_pathlist *pathlist;

	type = STANDART;

	get_next_line(0, &str);
	nbrofants = ft_atoi(str);
	free(str);
	while (get_next_line(0, &str))
	{
		error = is_correct_syntax(str, &list, &type);
		ft_putendl(str);
		free(str);
		if (error != COMMAND)
			type = STANDART;
		if (error == FALSE)
			break;
	}
	if (error == FALSE)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	t_path *tmp;
	pathlist = NULL;
	while ((tmp = djikstra(list)))
		pathlist = pathlist_pushfront(&pathlist, tmp);
	if (pathlist)
	{
		ants(pathlist, nbrofants);
	}
	else
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	return (0);
}
