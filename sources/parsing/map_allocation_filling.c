/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_allocation_filling.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 10:52:20 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/22 14:10:06 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	fill_with_space(t_whole *whole, int i, int j)
{
	while (i < whole->column)
	{
		whole->map->tiles[j][i].symbol = ' ';
		i++;
	}
	return (i);
}

int	fill_with_string(t_whole *whole, char *str, int i, int j)
{
	while (str[i] && str[i] != '\n')
	{
		whole->map->tiles[j][i].symbol = str[i];
		i++;
	}
	return (i);
}

void	fill_map(t_whole *whole, int i, int j, int fd)
{
	char	*str;

	while (j++ < whole->number_of_line_before_map)
	{
		str = get_next_line(fd);
		free(str);
	}
	j = 0;
	while (j < whole->map_lines)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		i = 0;
		if (str[i] && str[i] != '\n')
			i = fill_with_string(whole, str, i, j);
		if (i < whole->column)
			i = fill_with_space(whole, i, j);
		free(str);
		j++;
	}
	close (fd);
	print_map(whole);
}

void	allocate_m_map(t_whole *whole, int i, char *line_to_free)
{
	int			fd;

	whole->map->tiles = (t_tile **)malloc(whole->map_lines * sizeof(t_tile *));
	if (!whole->map->tiles)
		print_error(whole, "allocation");
	while (i < whole->map_lines)
	{
		whole->map->tiles[i] = (t_tile *)malloc(whole->column * sizeof(t_tile));
		if (!whole->map->tiles[i])
		{
			ft_free_map_from_n(whole->map, i);
			print_error(whole, "allocation");
		}
		i++;
	}
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		print_error(whole, "open");
	fill_map(whole, 0, 0, fd);
	call_check_map_and_result(whole, 0, line_to_free);
}
