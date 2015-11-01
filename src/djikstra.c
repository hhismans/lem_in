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
#include <unistd.h>

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

static t_node *find_lowestcost(t_edge *rest)
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

/*static 	t_edge *pop(t_edge **list, t_node *elem)
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
}*/

static void resetgraph(t_node *list)
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
static	t_edge *copylist(t_node *graph)
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
	{
		ft_putendl_fd("Error copylist graph == NULL", 2);
	}
	return (ret);
}

void putsedge(t_edge *list)
{
	while (list)
	{
//		printf("unvisited = %s\n", list->node->name);
		list = list->next;
	}
}

/*
** NAME			:	DJIKSTRA
** DESCRIPTION	:	Receive FIRST node of the graph, and find the shortest path
**					between start and end nodes.
** INPUT		:	t_node graph representation
** RETURN VALUE	:	t_edge representation of the path.
*/
t_path *djikstra(t_node *graph)
{
	t_node *end;
	t_edge *unvisited;
	t_path *ret;

	resetgraph(graph);
	unvisited = copylist(graph);
	putsedge(unvisited);
	end = find_type(graph, END);
	graph = find_type(graph, START);

	graph->cost = 0;
	unvisited = pop_edge(&unvisited, graph);
	if (graph && end)
	{
		while (graph && graph->name != end->name) //tant que le nom n'est pas end
		{
			maj_dist(graph);
			pop_edge(&unvisited, graph);
			
			graph = find_lowestcost(unvisited);
		}
	}
	else
	{
		ft_putendl_fd("Error : end or start not found", 2);
		printf("end : %p  start %p", end, graph);
	}
	ft_putendl_fd("we are out",2 );
	if (!graph)
	{
		ft_putstr("nopath found\n");
		return (NULL);
	}
	ret = NULL;
	while (graph->type != START)
	{
		if (graph->type != END)
			graph->visited = 1;
		ret = path_pushfront(&ret, graph);
		graph = graph->father;
	}
	debugdisplay(ret);
	return (ret);
}
/*
			while (graph->edge) // tant qu'il exite des liaisons avec ce node
			{
				if (!graph->edge->node->visited
						&& graph->cost + 1 < graph->edge->node->cost)
				{
					graph->edge->node->cost = 0;
				}
				graph->edge = graph->edge->next;
				*/
