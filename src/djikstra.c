/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:21:33 by hhismans          #+#    #+#             */
/*   Updated: 2015/10/30 08:47:10 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>

/*
** return the node with node->type == type
*/
static t_node *find_type(t_node *graph, t_type type)
{
	while (graph && graph->type != type)
		graph = graph->next;
	return (graph);
}

/*
** set all link node
*/

static void maj_dist(t_node *graph)
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

static t_node *find_lowercost(t_edge *rest)
{
	int		lowercost;
	t_node	*ret;
	lowercost = rest->node->cost;
	rest = rest->next;
	while (rest)
	{
		if (rest->node->cost < lowercost)
		{
			lowercost = rest->node->cost;
			ret = rest->node;
		}
		rest = rest->next;
	}
	return (ret);
}

static 	t_edge *pop(t_edge **list, t_node *elem)
{
	t_edge prev;

	if (prev)
	while (*list)
	{
		if ((*list)->node->name == elem->name)
		{
		}
	}
	return (*list);
}

static	t_edge *createHeap(t_node *graph)
{
	while
}
/*
** NAME			:	DJIKSTRA
** DESCRIPTION	:	Receive FIRST node of the graph, and find the shortest path
**					between start and end nodes.
** INPUT		:	t_node graph representation
** RETURN VALUE	:	t_edge representation of the path.
*/
void djikstra(t_node *graph)
{
	t_node *end;
	t_node *lowercost;
	t_edge *Heap;

	graph = find_type(graph, START);
	end = find_type(graph, END);

	graph->cost = 0;
	if (graph && end)
	{
		while (graph->name != end->name) // tant que le nom n'est pas end
		{
			maj_dist(graph);
			
			/*while (graph->edge) // tant qu'il exite des liaisons avec ce node
			{
				if (!graph->edge->node->visited
						&& graph->cost + 1 < graph->edge->node->cost)
				{
					graph->edge->node->cost = 0;
				}
				graph->edge = graph->edge->next;
			}*/
		}
	}
	else
	{
		ft_putendl_fd("Error : end or start not found", 2);
	}
}
