/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 16:57:16 by hhismans          #+#    #+#             */
/*   Updated: 2015/10/26 17:00:45 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

int			tablen(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != NULL)
		;
	return (i);
}

void		freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int			ft_contain(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
