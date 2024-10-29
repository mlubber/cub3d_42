/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_element.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:14 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/24 14:14:30 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	save_line_in_whole(char **which, char *line, int i)
{
	int	newi;

	while (line[i] && is_white_space(line[i]))
		i++;
	newi = i;
	while (line[newi] && line[newi] != '\n')
		newi++;
	*which = ft_substr(line, i, newi - i);
	return (0);
}


// int	save_line_in_whole(char **which, char *line, int i)
// {
// 	int	newi;

// 	while (line[i] && is_white_space(line[i]))
// 		i++;
// 	newi = i;
// 	while (line[newi] && !is_white_space(line[newi]) && line[newi] != '\n')
// 		newi++;
// 	*which = ft_substr(line, i, newi - i);
// 	return (0);
// }

int	save_element(char **element, char *line, int i)
{
	if (*element == NULL)
		return (save_line_in_whole(element, line, i + 2));
	return (2);
}

int	check_is_already_saved(t_whole *whole, char *line, int i)
{
	char	*sub;

	sub = ft_substr(line, 0, 2);
	if (!sub)
		print_error(whole, "allocation");
	if (!ft_strncmp(sub, "F ", 2))
		return (free(sub), save_element(&whole->cub_color_f, line, i));
	if (!ft_strncmp(sub, "C ", 2))
		return (free(sub), save_element(&whole->cub_color_c, line, i));
	free(sub);
	sub = ft_substr(line, 0, 3);
	if (!sub)
		print_error(whole, "allocation");
	if (!ft_strncmp(sub, "NO ", 3))
		return (free(sub), save_element(&whole->cub_t_no, line, i));
	if (!ft_strncmp(sub, "SO ", 3))
		return (free(sub), save_element(&whole->cub_t_so, line, i));
	if (!ft_strncmp(sub, "WE ", 3))
		return (free(sub), save_element(&whole->cub_t_we, line, i));
	if (!ft_strncmp(sub, "EA ", 3))
		return (free(sub), save_element(&whole->cub_t_ea, line, i));
	free(sub);
	return (1);
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
