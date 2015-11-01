/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 08:34:08 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 08:41:28 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"

void	ants(t_pathlist *lpath, int nbrofants)
{
	int			antsname;
	t_pathlist	*tmp;
	int			startline;
	int			turn;

	antsname = 1;
	turn = 0;
	while (antsname <= nbrofants)
	{
		tmp = lpath;
		startline = 1;
		while (tmp && antsname <= nbrofants)
		{
			insert_ants(tmp->path, antsname);
			displaypath(tmp->path);
			tmp = tmp->next;
			antsname++;
			startline = 0;
		}
		ft_putstr("\n");
		turn++;
	}
	finishants(lpath);
	ft_putendl("");
}
