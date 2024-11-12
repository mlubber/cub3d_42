/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_scenario.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 14:14:52 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/12 12:48:29 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	empty_line_found(t_whole *whole, int fd, int i, char *line_to_free)
{
	int		temp_map_line;
	char	*line;
	int		j;

	temp_map_line = i;
	while (i++ < whole->rows - 1)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j != 0)
		{
			free(line_to_free);
			free(line);
			read_line_until_end(fd);
			print_error(whole, "char after map");
		}
		free(line);
	}
	whole->rows = temp_map_line;
	close(fd);
	return (0);
}

char	*escape_lines_before_map(t_whole *whole, char *line, int i, int fd)
{
	while (i < whole->number_of_line_before_map)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	line = get_next_line(fd);
	return (line);
}

int	check_for_empty_lines(t_whole *whole, char *line_to_free, int i, int j)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		print_error(whole, "open");
	line = escape_lines_before_map(whole, line, 0, fd);
	while (i < whole->rows)
	{
		j = 0;
		while (line && line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j == 0)
			return (free(line), empty_line_found(whole, fd, i, line_to_free));
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	return (0);
}

void	take_rows_and_column(t_whole *whole, char *line, int fd, int i)
{
	int		j;
	int		longest;
	char	*temp_line;

	temp_line = ft_strdup(line);
	if (!temp_line)
		print_error(whole, "allocation");
	longest = 0;
	while (1)
	{
		j = 0;
		while (temp_line[j] && temp_line[j] != '\n')
			j++;
		if (longest < j)
			longest = j;
		i++;
		free(temp_line);
		temp_line = NULL;
		temp_line = get_next_line(fd);
		if (!temp_line)
			break ;
	}
	close(fd);
	whole->rows = i;
	whole->column = longest;
}

int	check_scenario(t_whole *whole, char *line, int fd)
{
	if (whole->cub_color_c && whole->cub_color_f && whole->cub_t_ea && \
		whole->cub_t_no && whole->cub_t_so && whole->cub_t_we)
	{
		take_rows_and_column(whole, line, fd, 0);
		if (check_for_empty_lines(whole, line, 0, 0))
			return (1);
		whole->width = whole->column * TILE;
		// whole->height = whole->rows * TILE;
		// if (whole->height < 1080)
		whole->height = 1080;
		allocate_m_map(whole, 0, line);
	}
	else
	{
		read_line_until_end(fd);
		print_error_with_line(whole, "Error, no elements match line: ", line);
	}
	return (0);
}
