/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:34:07 by hhismans          #+#    #+#             */
/*   Updated: 2015/11/01 09:41:31 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INT_MAX 2147483647

typedef struct s_node		t_node;
typedef struct s_path		t_path;
typedef struct s_pathlist	t_pathlist;
typedef struct s_edge		t_edge;
enum
{
	FALSE,
	COMMAND,
	NODE,
	EDGE,
	COMMENTARY
};

typedef enum			e_type
{
	STANDART,
	START,
	END
}						t_type;

struct					s_node
{
	char				*name;
	int					x;
	int					y;
	t_type				type;
	int					cost;
	int					visited;
	struct s_node		*father;
	struct s_edge		*edge;
	struct s_node		*next;
};

struct					s_path
{
	int					antsname;
	struct s_node		*node;
	struct s_path		*next;
};

struct					s_pathlist
{
	struct s_path		*path;
	struct s_pathlist	*next;
};

struct					s_edge
{
	struct s_node		*node;
	struct s_edge		*next;
};

t_edge					*new_edge(t_node *node);
t_edge					*edge_pushfront(t_edge **edge, t_node *node);
int						add_edge(t_node *node, char *name1, char *name2);
t_node					*new_cell(char *name, int x, int y, t_type type);
t_node					*add_cell(t_node **list, char **str, t_type type);
void					freetab(char **tab);
int						tablen(char **tab);
int						ft_contain(char *str, char c);
int						name_exist(t_node *list, char *str);
t_edge					*pop_edge(t_edge **edge, t_node *node);
t_path					*djikstra(t_node *graph);
t_pathlist				*newpathlist(t_path *data);
t_path					*newpath(t_node *node);
t_path					*path_pushfront(t_path **path, t_node *node);
t_pathlist				*pushbacklpath(t_pathlist **list, t_path *path);
void					ants(t_pathlist *lpath, int nbrofants);
void					debugdisplay(t_path *path);
t_pathlist				*pathlist_pushfront(t_pathlist **pathl, t_path *path);
t_node					*find_type(t_node *graph, t_type type);
void					maj_dist(t_node *graph);
t_node					*find_lowestcost(t_edge *rest);
void					resetgraph(t_node *list);
t_edge					*copylist(t_node *graph);
int						pathlen(t_path *path);
void					insert_ants(t_path *path, int name);
int						displaypath(t_path *path);
int						stillants(t_pathlist *lpath);
void					finishants(t_pathlist *lpath);

#endif
