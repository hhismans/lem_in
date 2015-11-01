/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 11:42:34 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 09:47:18 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>

int		is_correct_syntax2(const char *str, t_type *type)
{
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
	return (0);
}

int		is_correct_syntax3(const char *str, char **split, t_node **list)
{
	freetab(split);
	split = ft_strsplit(str, '-');
	if (tablen(split) == 2)
	{
		if (add_edge(*list, split[0], split[1]))
		{
			freetab(split);
			return (EDGE);
		}
	}
	return (0);
}

int		is_correct_syntax(const char *str, t_node **list, t_type *type)
{
	char	**split;
	int		ret;

	if ((ret = is_correct_syntax2(str, type)))
		return (ret);
	split = ft_strsplit(str, ' ');
	if (tablen(split) == 3 && !ft_contain(split[0], '-') &&
			!name_exist(*list, split[0]))
	{
		add_cell(list, split, *type);
		freetab(split);
		return (NODE);
	}
	else if (tablen(split) == 1)
		ret = is_correct_syntax3(str, split, list);
	if (ret == EDGE)
		return (ret);
	else
	{
		ft_putstr_fd("Syntax error : ", 2);
		ft_putendl_fd(str, 2);
	}
	freetab(split);
	return (FALSE);
}

int		endmain(int error, t_node *list, int nbrofants)
{
	t_pathlist		*pathlist;
	t_path			*tmp;

	if (error == FALSE)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
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

int		main(void)
{
	char	*str;
	t_node	*list;
	int		error;
	int		nbrofants;
	t_type	type;

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
			break ;
	}
	endmain(error, list, nbrofants);
	while  (1);
	return (0);
}
