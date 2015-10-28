/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:34:07 by hhismans          #+#    #+#             */
/*   Updated: 2015/10/26 13:52:00 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

enum {FALSE, COMMAND, NODE, EDGE, COMMENTARY};

typedef enum e_type
{
	STANDART,
	START,
	END
}			t_type;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	t_type			type;
	struct s_edge	*edge;
	struct s_node	*next;
}					t_node;


typedef struct		s_edge
{
	struct s_node	*node;
	struct s_edge	*next;
}					t_edge;

t_edge		*new_edge(t_node *node);
t_edge		*edge_pushfront(t_edge **edge, t_node *node);
int			add_edge(t_node *node, char *name1, char *name2);
t_node		*new_cell(char *name, int x, int y, t_type type);
t_node		*add_cell(t_node **list, char **str, t_type type);
void		freetab(char **tab);
int			tablen(char **tab);
int			ft_contain(char *str, char c);
int			name_exist(t_node *list, char *str);

#endif
