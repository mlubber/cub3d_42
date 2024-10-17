/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_save_elements1.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:07 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/17 15:54:11 by adakheel      ########   odam.nl         */
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
		while (line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j != 0)
		{
			printf("Error, after map can't be any other element\n");
			return (close(fd), free(line), 1);
		}
		i++;
		free(line);
	}
	whole->map_lines = temp_map_line;
	close(fd);
	return (0);
}

int	check_empty_line_inseide_and_after_map(t_whole *whole, char *line, int i, int j)
{
	int	fd;

	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (i < whole->number_of_line_before_map)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	i = 0;
	line = get_next_line(fd);
	while (i < whole->map_lines)
	{
		j = 0;
		while (line[j] && line[j] != '\n' && line[j] != '\0')
			j++;
		if (j == 0)
			return (free(line), empty_line_found(whole, fd, i, 0));
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	check_scenario(t_whole *whole, char *line, int fd)
{
	int	i;
	int	j;
	int	longest;

	longest = 0;
	if (whole->cub_color_C && whole->cub_color_F && whole->cub_t_EA && \
		whole->cub_t_NO && whole->cub_t_SO && whole->cub_t_WE)
	{
		i = 1;
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			j = 0;
			while (line[j] && line[j] != '\n')
				j++;
			if (longest < j)
				longest = j;
			i++;
			free(line);
		}
		close(fd);
		whole->map_lines = i;
		whole->column = longest + 1;
		if (check_empty_line_inseide_and_after_map(whole, line, 0, 0))
			return (1);
		allocate_m_map(whole, 0);
	}
	else
	{
		print_error(whole, "Error, line is not matched with any of elements : ", line);
		return (1);
	}
	return (0);
}

int	process_element(t_whole *whole, char *line, int i, int fd)
{
	int		result;
	char	*temp;

	fd = 0;
	result = check_is_already_saved(whole, &line[i], i);
	if (result)
	{
		if (result == 1)
			temp = "Error, the key of line is not matched with any elements: ";
		else
			temp = "Error, this key of line is duplicated: ";
		// temp = NULL;
		// while (1)
		// {
		// 	temp = get_next_line(fd);
		// 	printf("temp is (%s)\n", temp);
		// 	if (!temp)
		// 		break ;
		// 	free(temp);
		// }
		
		//close(fd);
		//get_next_line(fd);
		print_error(whole, temp, line);
	}
	return (0);
}

int	element_or_scenario(t_whole *whole, char *line, int i, int fd)
{
	if (line[i] && (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C'))
	{
		process_element(whole, line, i, fd);
		// if (process_element(whole, line, i))
		// {
		// 	free(line);
		// 	return (1);
		// }
	}
	else
	{
		if (check_scenario(whole, line, fd))
		{
			free(line);
			line = NULL;
			return (1);
		}
	}
	return (0);
}


int	check_file_cub(t_whole *whole, int i, int fd)
{
	char	*line;

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
			if (element_or_scenario(whole, line, i, fd))
				return (1);
		}
		if (line)
			free(line);
	}
	close(fd);
	return (0);
}
