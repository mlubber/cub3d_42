
#include "../../include/cub3d.h"


int	ft_lst_map_size(t_map_list *lst)
{
	int		total_node;

	total_node = 0;
	while (lst)
	{
		total_node++;
		lst = lst->next;
	}
	return (total_node);
}

t_map_list	*ft_lst_map_last(t_map_list *lst)
{
	while (lst)
	{
		if (lst && lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lst_map_add_back(t_map_list **lst, t_map_list *new, t_whole *whole)
{
	t_map_list	*temp;

	if (lst && new)
	{
		if (*lst)
		{
			temp = ft_lst_map_last(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
	else
		ft_free_map_list_exit(whole, "allocation");
}

t_map_list	*ft_lst_map_new(int x, int y, int instance)
{
	t_map_list	*new;

	new = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->instance = instance;
	new->next = NULL;

	return (new);
}

void	make_node(int x, int y, int instance, t_whole *whole)
{
	if (!whole->list_clue)
	{
		whole->list_clue = ft_lst_map_new(x, y, instance);
		if (!whole->list_clue)
			ft_free_map_exit(whole, "allocation");
	}
	else
	{
		ft_lst_map_add_back(&whole->list_clue, ft_lst_map_new(x, y, instance), whole);
	}
}



void	fill_map(t_whole *whole)
{
	char	*str;
	int		fd;
	int		i;
	int		j;
	int		instance;

	j = 0;
	instance = 0;
	printf("fill map\n");
	fd = open(whole->given_map, O_RDONLY);
	while (j < whole->number_of_line_before_map + 1)
	{
		str = get_next_line(fd);
		if (j != whole->number_of_line_before_map)
			free(str);
		j++;
	}
	j = 0;
	while (1)
	{
		//printf("str is (%s)", str);
		if (str == NULL)
			break ;
		i = 0;
		while (str[i] && str[i] != '\n')
		{
			whole->map->tiles[j][i].symbol = str[i];
			// if (whole->map->tiles[j][i].symbol == 'C')
			// 	make_node(i, j, instance++, whole);
			i++;
		}
		whole->map->tiles[j][i].symbol = '\0';
		free(str);
		str = get_next_line(fd);
		j++;
	}
	free(str);
	close (fd);
	printf("end of fill map\n");
	i = 0;
	while (i < whole->map_lines)
	{
		j = 0;
		while (whole->map->tiles[i][j].symbol != '\0')
		{
			printf("%c", whole->map->tiles[i][j].symbol);
			j++;
		}
		printf("\n");
		i++;
	}
	
}

void	allocate_m_map(t_whole *whole)
{
	int			i;
	int			j;
	int			fd;
	char		*line;

	i = 0;
	j = 0;
	whole->map->tiles = (t_tile **)malloc(whole->map_lines * sizeof(t_tile *));
	if (!whole->map->tiles)
		ft_free_exit(whole, "allocation");
	fd = open(whole->given_map, O_RDONLY);
	while (j < whole->number_of_line_before_map + 1)
	{
		line = get_next_line(fd);
		if (j != whole->number_of_line_before_map)
			free(line);
		j++;
	}
	while (i < whole->map_lines)
	{
		j = 0;
		while (line && line[j] != '\n' && line[j] != '\0')
			j++;
		whole->map->tiles[i] = (t_tile *)malloc(j + 1 * sizeof(t_tile));
		if (!whole->map->tiles[i])
			ft_free_map_exit(whole, "allocation");
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fill_map(whole);
	//check_map(whole);
}