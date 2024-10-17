
#include "../../include/cub3d.h"


// int	ft_lst_map_size(t_map_list *lst)
// {
// 	int		total_node;

// 	total_node = 0;
// 	while (lst)
// 	{
// 		total_node++;
// 		lst = lst->next;
// 	}
// 	return (total_node);
// }

// t_map_list	*ft_lst_map_last(t_map_list *lst)
// {
// 	while (lst)
// 	{
// 		if (lst && lst->next == NULL)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// void	ft_lst_map_add_back(t_map_list **lst, t_map_list *new, t_whole *whole)
// {
// 	t_map_list	*temp;

// 	if (lst && new)
// 	{
// 		if (*lst)
// 		{
// 			temp = ft_lst_map_last(*lst);
// 			temp->next = new;
// 		}
// 		else
// 			*lst = new;
// 	}
// 	else
// 		ft_free_map_list_exit(whole, "allocation");
// }

// t_map_list	*ft_lst_map_new(int x, int y, int instance)
// {
// 	t_map_list	*new;

// 	new = (t_map_list *)malloc(sizeof(t_map_list));
// 	if (!new)
// 		return (NULL);
// 	new->x = x;
// 	new->y = y;
// 	new->instance = instance;
// 	new->next = NULL;

// 	return (new);
// }

// void	make_node(int x, int y, int instance, t_whole *whole)
// {
// 	if (!whole->list_clue)
// 	{
// 		whole->list_clue = ft_lst_map_new(x, y, instance);
// 		if (!whole->list_clue)
// 			ft_free_map_exit(whole, "allocation");
// 	}
// 	else
// 	{
// 		ft_lst_map_add_back(&whole->list_clue, ft_lst_map_new(x, y, instance), whole);
// 	}
// }


// int	check_next_char(t_whole *whole, int y, int x)
// {
// 	int	oldx;

// 	oldx = x;
// 	//printf("in check next char\n");
// 	while (whole->map->tiles[y][x].symbol && whole->map->tiles[y][x].symbol == ' ')
// 		x++;
// 	if (whole->map->tiles[y][x].symbol != '1' && whole->map->tiles[y][x].symbol != '\0')
// 		return (1);
// 	while (y < whole->map_lines && whole->map->tiles[y][oldx].symbol == ' ')
// 	{
// 		y++;
// 	}
	
// 	// while (whole->map->tiles[y][oldx].symbol && whole->map->tiles[y][oldx].symbol == ' ')
// 	// 	y++;
// 	if (y < whole->map_lines)
// 	{
// 		if (whole->map->tiles[y][oldx].symbol != '1' && whole->map->tiles[y][oldx].symbol != '\0')
// 			return (1);
// 	}
// 	return (0);
// }



// int	check_edges(t_whole *whole, int y, int x)
// {

// 	while (x < whole->column)
// 	{
// 		if (whole->map->tiles[0][x].symbol != '1' && whole->map->tiles[0][x].symbol != ' ')
// 			return (1);
// 		x++;
// 	}
// 	//printf("tttt\n");
// 	x = 0;
// 	while (x < whole->column)
// 	{
// 		if (whole->map->tiles[whole->map_lines - 1][x].symbol != '1' && whole->map->tiles[whole->map_lines - 1][x].symbol != ' ')
// 			return (1);
// 		x++;
// 	}
// 	//printf("tttt\n");
// 	while (y < whole->map_lines)
// 	{
// 		if (whole->map->tiles[y][0].symbol != '1' && whole->map->tiles[y][0].symbol != ' ')
// 			return (1);
// 		y++;
// 	}
// 	y = 0;
// 	//printf("tttt\n");
// 	//last column
// 		while (y < whole->map_lines)
// 	{
// 		if (whole->map->tiles[y][whole->column -1 ].symbol != '1' && whole->map->tiles[y][whole->column - 1].symbol != ' ')
// 			return (1);
// 		y++;
// 	}
// 	//printf("tttt\n");
// 	return (0);

// }


// int	check_next_char_plusx(t_whole *whole, int y, int x)
// {
// 	//printf("check_next_char_plusx\n");
// 	//printf("y is (%d)\n", y);
// 	//printf("x is (%d)\n", x);
// 	while (x < whole->column && whole->map->tiles[y][x].symbol == ' ')
// 		x++;
// 	if (x >= whole->column)
// 		x = whole->column - 1;
// 	//printf("tiles is (%c)\n", whole->map->tiles[y][x].symbol);
// 	if (whole->map->tiles[y][x].symbol == '1' || whole->map->tiles[y][x].symbol == ' ' ||  whole->map->tiles[y][x].symbol == '\0')
// 		return (0);
// 	else
// 		return (1);
// }

// int	check_next_char_minx(t_whole *whole, int y, int x)
// {
// 	while (x >= 0 && whole->map->tiles[y][x].symbol == ' ')
// 		x--;
// 	if (x < 0)
// 		x = 0;
// 	if (whole->map->tiles[y][x].symbol == '1' || whole->map->tiles[y][x].symbol == ' ')
// 		return (0);
// 	else
// 		return (1);
// }

// int	check_next_char_plusy(t_whole *whole, int y, int x)
// {
// 	while (y < whole->map_lines && whole->map->tiles[y][x].symbol == ' ')
// 		y++;
// 	if (y >= whole->map_lines)
// 		y = whole->map_lines - 1;
// 	if (whole->map->tiles[y][x].symbol == '1' || whole->map->tiles[y][x].symbol == ' ')
// 		return (0);
// 	else
// 		return (1);
// }

// int	check_next_char_miny(t_whole *whole, int y, int x)
// {
// 	while (y >= 0 && whole->map->tiles[y][x].symbol == ' ')
// 		y--;
// 	if (y < 0)
// 		y = 0;
// 	if (whole->map->tiles[y][x].symbol == '1' || whole->map->tiles[y][x].symbol == ' ')
// 		return (0);
// 	else
// 		return (1);
// }


// int check_map(t_whole *whole)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	//printf("here\n");
// 	while (y < whole->map_lines)
// 	{
// 		x = 0;
// 		while (whole->map->tiles[y][x].symbol != '\0')
// 		{
// 			if (whole->map->tiles[y][0].symbol != ' ' && whole->map->tiles[y][0].symbol != '1')
// 				return (1);
// 			if (whole->map->tiles[y][x + 1].symbol == '\0')
// 			{
// 				if (whole->map->tiles[y][x].symbol != '1')
// 					return (1);
// 			}
// 			if (whole->map->tiles[y][x].symbol == ' ')
// 			{
// 				if (check_next_char(whole, y, x))
// 				{
// 					//printf("invalid map\n");
// 					return (1);
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// int	other_char_inside_map(t_whole *whole)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < whole->map_lines)
// 	{
// 		x = 0;
// 		while (x < whole->column)
// 		{
// 			if (!ft_strchr("NSEW01 ", whole->map->tiles[y][x].symbol))
// 				return (1);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// int	is_player_double(t_whole *whole)
// {
// 	int	y;
// 	int	x;
// 	int	player;

// 	y = 0;
// 	player = 0;
// 	while (y < whole->map_lines)
// 	{
// 		x = 0;
// 		while (x < whole->column)
// 		{
// 			if (ft_strchr("NSEW", whole->map->tiles[y][x].symbol))
// 				player++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (player == 0 || player > 1)
// 		return (1);
// 	return (0);
// }

// int	dfs(t_whole *whole, bool **visited, int x, int y)
// {
// 	int	result;

// 	result = 0;
// 	if (whole->access_all_zeros == whole->all_zeros)
// 		return (1);
// 	if (visited[y][x] || x < 0 || x >= whole->column - 1 || y < 0 ||
// 		y >= whole->map_lines - 1 || whole->map->tiles[y][x].symbol == '1')
// 		return (0);
// 	visited[y][x] = true;
// 	if (whole->map->tiles[y][x].symbol == '0')
// 		whole->access_all_zeros++;
// 	result |= dfs(whole, visited, x + 1, y);
// 	result |= dfs(whole, visited, x - 1, y);
// 	result |= dfs(whole, visited, x, y + 1);
// 	result |= dfs(whole, visited, x, y - 1);
// 	return (result);
// }


// void	count_all_zero(t_whole *whole)
// {
// 	int	y;
// 	int	x;
// 	int	count;

// 	y = 0;
// 	count = 0;
// 	while (y < whole->map_lines)
// 	{
// 		x = 0;
// 		while (x < whole->column)
// 		{
// 			if (ft_strchr("0", whole->map->tiles[y][x].symbol))
// 				count++;
// 			if (ft_strchr("NSEW", whole->map->tiles[y][x].symbol))
// 			{
// 				whole->x = x;
// 				whole->y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	whole->all_zeros = count;
// }

// void	ft_free_visited_array(t_whole *whole, bool **visit)
// {
// 	int	i;

// 	i = 0;
// 	while (i < whole->line)
// 	{
// 		free(visit[i]);
// 		i++;
// 	}
// 	free(visit);
// }

// int	is_player_reach_everywhere(t_whole *whole)
// {
// 	int		i;
// 	int		result;
// 	bool	**visited;

// 	i = 0;
// 	visited = ft_calloc(whole->map_lines, sizeof(bool *));
// 	while (i < whole->map_lines)
// 	{
// 		visited[i] = ft_calloc(whole->column, sizeof(bool));
// 		i++;
// 	}
// 	count_all_zero(whole);
// 	result = dfs(whole, visited, whole->x, whole->y);
// 	ft_free_visited_array(whole, visited);
// 	if (result == 0)
// 		return (1);
// 	return (0);
// }


// int check_map(t_whole *whole)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	if (is_player_double(whole))
// 		return (3);
// 	if (other_char_inside_map(whole))
// 		return (2);
// 	if (check_edges(whole, 0, 0))
// 		return (1);
// 	while (y < whole->map_lines)
// 	{
// 		x = 0;
// 		while (x < whole->column)
// 		{
// 			if (whole->map->tiles[y][x].symbol == ' ')
// 			{
// 				if (check_next_char_plusx(whole, y, x))
// 					return (1);
// 				if (check_next_char_minx(whole, y, x))
// 					return (1);
// 				if (check_next_char_plusy(whole, y, x))
// 					return (1);
// 				if (check_next_char_miny(whole, y, x))
// 					return (1);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (is_player_reach_everywhere(whole))
// 		return (4);
// 	return (0);
// }

// int	fill_with_string(t_whole *whole, char *str, int i, int j)
// {
// 	while (str[i] && str[i] != '\n')
// 	{
// 		whole->map->tiles[j][i].symbol = str[i];
// 		i++;
// 	}
// 	return (i);
// }

// int	fill_with_space(t_whole *whole, int i, int j)
// {
// 	while (i < whole->column)
// 	{
// 		whole->map->tiles[j][i].symbol = ' ';
// 		i++;
// 	}
// 	return (i);
// }


// void	fill_map(t_whole *whole, int i, int j, int fd)
// {
// 	char	*str;

// 	while (j++ < whole->number_of_line_before_map)
// 	{
// 		str = get_next_line(fd);
// 		free(str);
// 	}
// 	j = 0;
// 	while (j < whole->map_lines)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		i = 0;
// 		if (str[i] && str[i] != '\n')
// 			i = fill_with_string(whole, str, i, j);
// 		if (i < whole->column)
// 			i = fill_with_space(whole, i, j);
// 		whole->map->tiles[j][i].symbol = '\0';
// 		free(str);
// 		j++;
// 	}
// 	close (fd);
// 	printf("end of fill map\n");
// 	// //printing the map
// 	// i = 0;
// 	// printf("whole->map_lines are (%d)\n", whole->map_lines);
// 	// while (i < whole->map_lines)
// 	// {
// 	// 	j = 0;
// 	// 	while (whole->map->tiles[i][j].symbol != '\0')
// 	// 	{
// 	// 		printf("%c", whole->map->tiles[i][j].symbol);
// 	// 		j++;
// 	// 	}
// 	// 	printf("end\n");
// 	// 	i++;
// 	// }
// 	// printf("end printing map\n");
// }

// void	allocate_maplines_escape_line_before_map(t_whole *whole, char *line, int fd, int j)
// {
// 	whole->map->tiles = (t_tile **)malloc(whole->map_lines * sizeof(t_tile *));
// 	if (!whole->map->tiles)
// 		ft_free_exit(whole, "allocation");
// 	while (j < whole->number_of_line_before_map)
// 	{
// 		line = get_next_line(fd);
// 		if (j != whole->number_of_line_before_map)
// 			free(line);
// 		j++;
// 	}
// }

// void	call_check_map_and_check_result(t_whole *whole, int i)
// {
// 	i = check_map(whole);
// 	if (i)
// 	{
// 		if (i == 1)
// 			printf("Error, map is not enclosed by wall\n");
// 		if (i == 2)
// 			printf("Error, map has invalid characters\n");
// 		if (i == 3)
// 			printf("Error, amount of player doesn't coorect\n");
// 		if (i == 4)
// 			printf("Error, player doesn'e access everywher\n");
// 		exit(1);
// 	}
// }

// void	allocate_m_map(t_whole *whole, int i)
// {
// 	int			fd;
// 	char		*line;

// 	fd = open(whole->given_map, O_RDONLY);
// 	if (fd < 0)
// 		exit (1);
// 	allocate_maplines_escape_line_before_map(whole, NULL, fd, 0);
// 	while (i < whole->map_lines)
// 	{
// 		whole->map->tiles[i] = (t_tile *)malloc(whole->column * sizeof(t_tile));
// 		if (!whole->map->tiles[i])
// 			ft_free_map_exit(whole, "allocation");
// 		i++;
// 		line = get_next_line(fd);
// 		free(line);
// 	}
// 	close(fd);
// 	fd = open(whole->given_map, O_RDONLY);
// 	if (fd < 0)
// 		exit (1);
// 	fill_map(whole, 0, 0, fd);
// 	call_check_map_and_check_result(whole, 0);
// }

