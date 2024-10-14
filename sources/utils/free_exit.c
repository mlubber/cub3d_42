
#include "../../include/cub3d.h"

void	ft_lst_map_clear(t_map_list **lst)
{
	t_map_list	*temp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	ft_free_map(t_map *map, int line)
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

void	ft_free_exit(t_whole *whole, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
		ft_putstr_fd("map extension is not correct!\n", 2);
	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
		ft_putstr_fd("the number of exit is not correct!\n", 2);
	else if (ft_strncmp(str, "player", ft_strlen(str)) == 0)
		ft_putstr_fd("the number of player is not correct!\n", 2);
	else if (ft_strncmp(str, "coins", ft_strlen(str)) == 0)
		ft_putstr_fd("there must be at least one collectible!\n", 2);
	else if (ft_strncmp(str, "position", ft_strlen(str)) == 0)
		ft_putstr_fd("position of player is not correct!\n", 2);
	if (ft_strncmp(str, "rectangle", ft_strlen(str)) == 0)
		ft_putstr_fd("map should be rectangle!\n", 2);
	if (ft_strncmp(str, "open", ft_strlen(str)) == 0)
		ft_putstr_fd("can't open the map or permission error!\n", 2);
	free(whole->map);
	free(whole);
	exit(EXIT_FAILURE);
}

void	ft_free_map_exit(t_whole *whole, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
		ft_putstr_fd("Memory allocation denied!\n", 2);
	ft_free_map(whole->map, whole->line);
	free(whole->map);
	free(whole);
	exit(EXIT_FAILURE);
}

void	ft_free_map_list_exit(t_whole *whole, char *str)
{
	if (ft_strlen(str) > 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
			ft_putstr_fd("Memory allocation denied!\n", 2);
		if (ft_strncmp(str, "wall", ft_strlen(str)) == 0)
			ft_putstr_fd("map should surrounded by walls!\n", 2);
		if (ft_strncmp(str, "symbol", ft_strlen(str)) == 0)
			ft_putstr_fd("your map has invalid symbol!\n", 2);
		if (ft_strncmp(str, "access", ft_strlen(str)) == 0)
			ft_putstr_fd("player doesn't have access to collect \
				all & exit!\n", 2);
	}
	ft_lst_map_clear(&whole->list_clue);
	ft_free_map(whole->map, whole->line);
	if (whole && whole->map)
	{
		free(whole->map);
		free(whole);
	}
	exit(EXIT_FAILURE);
}

