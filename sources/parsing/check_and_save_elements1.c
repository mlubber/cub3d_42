/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_save_elements1.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:07 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/21 15:18:42 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	empty_line_found(t_whole *whole, int fd, int i, int j)
{
	int		temp_map_line;
	char	*line;

	line = NULL;
	temp_map_line = i;
	while (i < whole->map_lines - 1)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j != 0)
		{
			free(line);
			read_line_until_end(fd);
			print_error(whole, "char after map");
		}
		i++;
		free(line);
	}
	whole->map_lines = temp_map_line;
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
		if (i + 1 != whole->number_of_line_before_map)
			free(line);
		i++;
	}
	return (line);
}

int	check_empty_line_inseide_and_after_map(t_whole *whole, char *line, int i, int j)
{
	int	fd;

	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		malloc_or_open_failed(whole, 2);
	line = escape_lines_before_map(whole, line, 0, fd);
	while (i < whole->map_lines)
	{
		j = 0;
		while (line && line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j == 0)
			return (free(line), empty_line_found(whole, fd, i, 0));
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (0);
}

void	take_map_lines_and_column(t_whole *whole, char *line, int fd)
{
	int	i;
	int	j;
	int	longest;

	longest = 0;
	i = 1;
	while (1)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		if (longest < j)
			longest = j;
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	whole->map_lines = i;
	whole->column = longest + 1;
}

int	check_scenario(t_whole *whole, char *line, int fd)
{
	if (whole->cub_color_C && whole->cub_color_F && whole->cub_t_EA && \
		whole->cub_t_NO && whole->cub_t_SO && whole->cub_t_WE)
	{
		take_map_lines_and_column(whole, line, fd);
		if (check_empty_line_inseide_and_after_map(whole, line, 0, 0))
			return (1);
		allocate_m_map(whole, 0, fd);
	}
	else
	{
		read_line_until_end(fd);
		print_error_with_line(whole, "Error, line is not matched with any of elements : ", line);
	}
	return (0);
}

int	process_element(t_whole *whole, char *line, int i, int fd)
{
	int		result;
	char	*temp;

	result = check_is_already_saved(whole, &line[i], i);
	if (result)
	{
		if (result == 1)
			temp = "Error, the key of line is not matched with any elements: ";
		if (result > 1)
			temp = "Error, this key of line is duplicated: ";
		read_line_until_end(fd);
		print_error_with_line(whole, temp, line);
	}
	return (0);
}

int	element_or_scenario(t_whole *whole, char *line, int i, int fd)
{
	if (line[i] && (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C'))
	{
		process_element(whole, line, i, fd);
	}
	else
	{
		check_scenario(whole, line, fd);
	}
	return (0);
}


void	check_file_cub(t_whole *whole, int i, int fd, char *line)
{
	whole->number_of_line_before_map = -1;
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		malloc_or_open_failed(whole, 2);
	while (1)
	{
		i = 0;
		line = NULL;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		whole->number_of_line_before_map++;
		while (line[i] && is_white_space(line[i]) && line[i] != '\n')
			i++;
		if (line[i] && line[i] != '\n')
		{
			whole->empty_file = 1;
			if (element_or_scenario(whole, line, i, fd))
				return ;
		}
		free(line);
	}
	if (!whole->empty_file)
		print_error(whole, "Empty file");
	close(fd);
}
