/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 13:52:52 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:07:41 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

void	read_line_until_end(int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}

int	check_split(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (!ft_isdigit(split[i][j]))
			{
				free_array(split);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		free_array(split);
		return (1);
	}
	return (0);
}

void	set_offset(t_whole *whole)
{
	if (whole->pdx < 0)
		whole->xo = -(TILE / 3);
	else
		whole->xo = (TILE / 3);
	if (whole->pdy < 0)
		whole->yo = -(TILE / 3);
	else
		whole->yo = (TILE / 3);
}

void	close_out(void *param)
{
	t_whole	*whole;

	whole = (t_whole *)param;
	error_close_window(whole, 0);
}
