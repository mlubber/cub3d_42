/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_allocation_filling.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 10:52:20 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/17 12:25:20 by adakheel      ########   odam.nl         */
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
		whole->map->tiles[j][i].symbol = '\0';
		free(str);
		j++;
	}
	close (fd);
	printf("end of fill map\n");
	// //printing the map
	// i = 0;
	// printf("whole->map_lines are (%d)\n", whole->map_lines);
	// while (i < whole->map_lines)
	// {
	// 	j = 0;
	// 	while (whole->map->tiles[i][j].symbol != '\0')
	// 	{
	// 		printf("%c", whole->map->tiles[i][j].symbol);
	// 		j++;
	// 	}
	// 	printf("end\n");
	// 	i++;
	// }
	// printf("end printing map\n");
}

void	allocate_maplines_escape_line_before_map(t_whole *whole \
	, char *line, int fd, int j)
{
	whole->map->tiles = (t_tile **)malloc(whole->map_lines * sizeof(t_tile *));
	if (!whole->map->tiles)
		ft_free_exit(whole, "allocation");
	while (j < whole->number_of_line_before_map)
	{
		line = get_next_line(fd);
		if (j != whole->number_of_line_before_map)
			free(line);
		j++;
	}
}

void	allocate_m_map(t_whole *whole, int i)
{
	int			fd;
	char		*line;

	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		exit (1);
	allocate_maplines_escape_line_before_map(whole, NULL, fd, 0);
	while (i < whole->map_lines)
	{
		whole->map->tiles[i] = (t_tile *)malloc(whole->column * sizeof(t_tile));
		if (!whole->map->tiles[i])
			ft_free_map_exit(whole, "allocation");
		i++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		exit (1);
	fill_map(whole, 0, 0, fd);
	call_check_map_and_check_result(whole, 0);
}
