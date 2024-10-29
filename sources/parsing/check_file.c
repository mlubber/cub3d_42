/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:07 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/28 07:10:42 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	check_file(t_whole *whole, int i, int fd, char *line)
{
	whole->number_of_line_before_map = -1;
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		print_error(whole, "open");
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
			element_or_scenario(whole, line, i, fd);
		}
		free(line);
	}
	if (!whole->empty_file)
		print_error(whole, "Empty file");
	close(fd);
}
