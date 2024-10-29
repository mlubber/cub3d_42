/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   depth_first_search.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 10:06:38 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/28 14:46:17 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/cub3d.h"

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
// 	while (i < whole->map_lines)
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
