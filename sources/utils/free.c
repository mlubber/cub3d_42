/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 07:35:31 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/22 07:57:39 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	malloc_or_open_failed(t_data *data, int num)
{
	if (num == 1)
		printf("Error, malloc failed\n");
	else
		printf("Error, open failed\n");
	free_all(data, 1);
}

static void	free_all_data(t_data *data)
{
	if (!data)
		return ;
	if (data->ceiling_str)
		free(data->ceiling_str);
	if (data->floor_str)
		free(data->floor_str);
	if (data->no_str)
		free(data->no_str);
	if (data->so_str)
		free(data->so_str);
	if (data->we_str)
		free(data->we_str);
	if (data->ea_str)
		free(data->ea_str);
	data->ceiling_str = NULL;
	data->floor_str = NULL;
	data->no_str = NULL;
	data->so_str = NULL;
	data->we_str = NULL;
	data->ea_str = NULL;
}

// void	free_map(t_data *data, t_map *map)
// {
// 	int	i;

// 	printf("free_map\n");
// 	if (data && data->map && data->map->tiles)
// 	{
// 		i = 0;
// 		while (i < data->map_lines)
// 		{
// 			free(map->tiles[i]);
// 			i++;
// 		}
// 		free(map->tiles);
// 	}
// }

void	free_all(t_data *data, int exit_code)
{
	printf("free_all\n");
	if (data)
		free_all_data(data);
	// if (data && data->map)
	// 	free_map(data, data->map);
	if (data && data->map)
		free(data->map);
	if (data)
		free(data);
	if (exit_code)
		exit(1);
	exit(0);
}
