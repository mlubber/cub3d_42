/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_save_elements2.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:14 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/17 15:46:26 by adakheel      ########   odam.nl         */
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
	while (line[newi] && !is_white_space(line[newi]) && line[newi] != '\n')
		newi++;
	*which = ft_substr(line, i, newi - i);
	if (line)
		free(line);
	line = NULL;
	return (0);
}

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
		exit(1);
	if (!ft_strncmp(sub, "F ", 2))
		return (free(sub), save_element(&whole->cub_color_F, line, i));
	if (!ft_strncmp(sub, "C ", 2))
		return (free(sub), save_element(&whole->cub_color_C, line, i));
	free(sub);
	sub = ft_substr(line, 0, 3);
	if (!sub)
		exit(1);
	if (!ft_strncmp(sub, "NO ", 3))
		return (free(sub), save_element(&whole->cub_t_NO, line, i));
	if (!ft_strncmp(sub, "SO ", 3))
		return (free(sub), save_element(&whole->cub_t_SO, line, i));
	if (!ft_strncmp(sub, "WE ", 3))
		return (free(sub), save_element(&whole->cub_t_WE, line, i));
	if (!ft_strncmp(sub, "EA ", 3))
		return (free(sub), save_element(&whole->cub_t_EA, line, i));
	free(sub);
	return (1);
}
