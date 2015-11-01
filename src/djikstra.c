/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:21:33 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 08:38:52 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"
#include <stdio.h>
#include <unistd.h>

int		thereisdirectpath(t_node *start)
{
	t_edge *tmp;

	if (!start->visited)
	{
		start->visited = 1;
		tmp = start->edge;
		while (tmp)
		{
			if (tmp->node->type == END)
			{
				tmp->node->father = start;
				pop_edge(&(start->edge), tmp->node);
				return (1);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

t_node	*djikstraalgo(t_node *graph, t_node *end, t_edge *unvisited)
{
	while (graph && graph->name != end->name)
	{
		maj_dist(graph);
		pop_edge(&unvisited, graph);
		graph = find_lowestcost(unvisited);
	}
	return (graph);
}

t_path	*djikstra(t_node *graph)
{
	t_node *end;
	t_edge *unvisited;
	t_path *ret;

	resetgraph(graph);
	unvisited = copylist(graph);
	end = find_type(graph, END);
	graph = find_type(graph, START);
	graph->cost = 0;
	if (thereisdirectpath(graph))
		graph = end;
	unvisited = pop_edge(&unvisited, graph);
	if (graph && end && graph != end)
		graph = djikstraalgo(graph, end, unvisited);
	if (!graph)
		return (NULL);
	ret = NULL;
	while (graph->type != START)
	{
		if (graph->type != END)
			graph->visited = 1;
		ret = path_pushfront(&ret, graph);
		graph = graph->father;
	}
	return (ret);
}
