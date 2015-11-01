/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djikstra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 07:27:01 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 07:29:25 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>
#include <unistd.h>

/*
** return the node with node->type == type
*/
t_node	*find_type(t_node *graph, t_type type)
{
	while (graph && graph->type != type)
		graph = graph->next;
	return (graph);
}

/*
** set all link node
*/
void		maj_dist(t_node *graph)
{
	t_edge *tmp;

	tmp = graph->edge;
	while (graph->edge)
	{
		if (graph->cost + 1 < graph->edge->node->cost)
		{
			graph->edge->node->cost = graph->cost + 1;
			graph->edge->node->father = graph;
		}
		graph->edge = graph->edge->next;
	}
	graph->edge = tmp;
}

t_node	*find_lowestcost(t_edge *rest)
{
	int		lowercost;
	t_node	*ret;

	lowercost = rest->node->cost;
	ret = rest->node;
	while (rest)
	{
		if (rest->node->cost < lowercost)
		{
			lowercost = rest->node->cost;
			ret = rest->node;
		}
		rest = rest->next;
	}
	if (ret->cost == INT_MAX)
		ret = NULL;
	return (ret);
}

void		resetgraph(t_node *list)
{
	while (list)
	{
		list->father = NULL;
		list->cost = INT_MAX;
		list = list->next;
	}
}

/*
** WARNING MALLOC HERE
*/
t_edge	*copylist(t_node *graph)
{
	t_edge *ret;
	t_edge *tmp;

	ret = NULL;
	if (graph)
	{
		ret = new_edge(graph);
		graph = graph->next;
		tmp = ret;
		while (graph)
		{
			if (!graph->visited)
			{
				tmp->next = new_edge(graph);
				tmp = tmp->next;
			}
			graph = graph->next;
		}
	}
	else
		ft_putendl_fd("Error copylist graph == NULL", 2);
	return (ret);
}
