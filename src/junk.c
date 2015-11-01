
/*void	debugdisplay(t_path *path)
{
	while (path)
	{
		printf("path = %s\n", path->node->name);
		path = path->next;
	}
}*/
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

int get_data(int *nbrofants, t_node **list, t_type *type)
{
	char *str;
	int error;

	get_next_line(0, &str);
	*nbrofants = ft_atoi(str);
	free(str);
	while (get_next_line(0, &str))
	{
		error = is_correct_syntax(str, list, type);
		ft_putendl(str);
		free(str);
		if (error != COMMAND)
			*type = STANDART;
		if (error == FALSE)
			break;
	}
	return (error);
}

