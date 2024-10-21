
#include "../../include/cub3d.h"

// void	just_exit(char *str)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	if (ft_strncmp(str, "no file", ft_strlen(str)) == 0)
// 		ft_putstr_fd("program need a file in format (.cub) to run!\n", 2);
// 	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
// 		ft_putstr_fd("Memory allocation denied!\n", 2);
// 	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
// 		ft_putstr_fd("map extension is not correct!\n", 2);
// 	exit(EXIT_FAILURE);
// }


// void	ft_lst_map_clear(t_map_list **lst)
// {
// 	t_map_list	*temp;

// 	if (!lst || !*lst)
// 		return ;
// 	while (lst && *lst)
// 	{
// 		temp = (*lst)->next;
// 		free(*lst);
// 		*lst = temp;
// 	}
// }


// void	ft_free_exit(t_whole *whole, char *str)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
// 		ft_putstr_fd("map extension is not correct!\n", 2);
// 	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
// 		ft_putstr_fd("the number of exit is not correct!\n", 2);
// 	else if (ft_strncmp(str, "player", ft_strlen(str)) == 0)
// 		ft_putstr_fd("the number of player is not correct!\n", 2);
// 	else if (ft_strncmp(str, "coins", ft_strlen(str)) == 0)
// 		ft_putstr_fd("there must be at least one collectible!\n", 2);
// 	else if (ft_strncmp(str, "position", ft_strlen(str)) == 0)
// 		ft_putstr_fd("position of player is not correct!\n", 2);
// 	if (ft_strncmp(str, "rectangle", ft_strlen(str)) == 0)
// 		ft_putstr_fd("map should be rectangle!\n", 2);
// 	if (ft_strncmp(str, "open", ft_strlen(str)) == 0)
// 		ft_putstr_fd("can't open the map or permission error!\n", 2);
// 	free(whole->map);
// 	free(whole);
// 	exit(EXIT_FAILURE);
// }

// void	ft_free_exit(t_whole *whole, char *str, char *to_print)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
// 		ft_putstr_fd("map extension is not correct!\n", 2);
// 	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
// 		ft_putstr_fd("the number of exit is not correct!\n", 2);
// 	else if (ft_strncmp(str, "player", ft_strlen(str)) == 0)
// 		ft_putstr_fd("the number of player is not correct!\n", 2);
// 	else if (ft_strncmp(str, "coins", ft_strlen(str)) == 0)
// 		ft_putstr_fd("there must be at least one collectible!\n", 2);
// 	else if (ft_strncmp(str, "position", ft_strlen(str)) == 0)
// 		ft_putstr_fd("position of player is not correct!\n", 2);
// 	if (ft_strncmp(str, "rectangle", ft_strlen(str)) == 0)
// 		ft_putstr_fd("map should be rectangle!\n", 2);
// 	if (ft_strncmp(str, "open", ft_strlen(str)) == 0)
// 		ft_putstr_fd("can't open the map or permission error!\n", 2);
// 	if (ft_strncmp(str, "not matched", ft_strlen(str)) == 0)
// 		ft_putstr_fd("the key of line is not matched with any elements: \n", 2);
// 	if (to_print)
// 		ft_putstr_fd(to_print, 2);
// 	free(whole->map);
// 	free(whole);
// 	exit(EXIT_FAILURE);
// }

// void	ft_free_map_exit(t_whole *whole, char *str)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
// 		ft_putstr_fd("Memory allocation denied!\n", 2);
// 	ft_free_map(whole ,whole->map);
// 	free(whole->map);
// 	free(whole);
// 	exit(EXIT_FAILURE);
// }

// void	ft_free_map_list_exit(t_whole *whole, char *str)
// {
// 	if (ft_strlen(str) > 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
// 			ft_putstr_fd("Memory allocation denied!\n", 2);
// 		if (ft_strncmp(str, "wall", ft_strlen(str)) == 0)
// 			ft_putstr_fd("map should surrounded by walls!\n", 2);
// 		if (ft_strncmp(str, "symbol", ft_strlen(str)) == 0)
// 			ft_putstr_fd("your map has invalid symbol!\n", 2);
// 		if (ft_strncmp(str, "access", ft_strlen(str)) == 0)
// 			ft_putstr_fd("player doesn't have access to collect \
// 				all & exit!\n", 2);
// 	}
// 	ft_lst_map_clear(&whole->list_clue);
// 	ft_free_map(whole, whole->map);
// 	if (whole && whole->map)
// 	{
// 		free(whole->map);
// 		free(whole);
// 	}
// 	exit(EXIT_FAILURE);
// }

void	malloc_or_open_failed(t_whole *whole, int num)
{
	if (num == 1)
		printf("Error, malloc failed\n");
	else
		printf("Error, open failed\n");
	free_all(whole, 1);
}

void	free_char_p_whole(t_whole *whole)
{
	printf("free_char_p_whole\n");
	if (!whole)
		return ;
	if (whole->cub_color_C)
		free(whole->cub_color_C);
	if (whole->cub_color_F)
		free(whole->cub_color_F);
	if (whole->cub_t_EA)
		free(whole->cub_t_EA);
	if (whole->cub_t_NO)
		free(whole->cub_t_NO);
	if (whole->cub_t_SO)
		free(whole->cub_t_SO);
	if (whole->cub_t_WE)
		free(whole->cub_t_WE);
	whole->cub_color_C = NULL;
	whole->cub_color_F = NULL;
	whole->cub_t_EA = NULL;
	whole->cub_t_NO = NULL;
	whole->cub_t_SO = NULL;
	whole->cub_t_WE = NULL;
}


void	ft_free_map_from_n(t_map *map, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
}


void	ft_free_map(t_whole *whole, t_map *map)
{
	int	i;

	i = 0;
	printf("ft_free_map\n");
	if (whole && whole->map && whole->map->tiles)
	{
		while (i < whole->map_lines)
		{
			free(map->tiles[i]);
			i++;
		}
		free(map->tiles);
	}
}

void	print_error_with_line(t_whole *whole, char *text, char *line)
{
	char	*to_print;

	to_print = NULL;
	if (!line)
		to_print = text;
	else
	{
		to_print = ft_strjoin(text, line);
		if (!to_print && errno == 12)
			malloc_or_open_failed(whole, 1);
	}
	printf("%s", to_print);
	free(to_print);
	free(line);
	free_all(whole, 1);
}


void	print_error(t_whole *whole, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "player", ft_strlen(str)) == 0)
		ft_putstr_fd("the number of player is not correct!\n", 2);
	else if (ft_strncmp(str, "position", ft_strlen(str)) == 0)
		ft_putstr_fd("position of player is not correct!\n", 2);
	if (ft_strncmp(str, "open", ft_strlen(str)) == 0)
		ft_putstr_fd("can't open the map or permission error!\n", 2);
	if (ft_strncmp(str, "no file", ft_strlen(str)) == 0)
		ft_putstr_fd("program need a file in format (.cub) to run!\n", 2);
	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
		ft_putstr_fd("Memory allocation denied!\n", 2);
	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
		ft_putstr_fd("map extension is not correct!\n", 2);
	if (ft_strncmp(str, "Empty file", ft_strlen(str)) == 0)
		ft_putstr_fd("your given file is empty!\n", 2);
	if (ft_strncmp(str, "not enclosed", ft_strlen(str)) == 0)
		ft_putstr_fd("map is not enclosed by wall!\n", 2);
	if (ft_strncmp(str, "amount of player", ft_strlen(str)) == 0)
		ft_putstr_fd("amount of player doesn't coorect!\n", 2);
	if (ft_strncmp(str, "char after map", ft_strlen(str)) == 0)
		ft_putstr_fd("Error, after map can't be any other element!\n", 2);
	free_all(whole, 1);
}

void	free_all(t_whole *whole, int exit_code)
{
	printf("free_all\n");
	if (whole)
		free_char_p_whole(whole);
	if (whole && whole->map)
		ft_free_map(whole, whole->map);
	if (whole && whole->map)
		free(whole->map);
	if (whole)
		free(whole);
	if (exit_code)
		exit(1);
	exit(0);
}
