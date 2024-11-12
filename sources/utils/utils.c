/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 13:52:52 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/12 14:01:07 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_map_from_n(t_map *map, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
}

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

void	free_array(char **strlist)
{
	int	i;

	i = 0;
	while (strlist[i])
	{
		free(strlist[i]);
		i++;
	}
	free(strlist);
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

void	print_error(t_whole *whole, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "player", ft_strlen(str)) == 0)
		ft_putstr_fd("the number of player is not correct!\n", 2);
	if (ft_strncmp(str, "open texture", ft_strlen(str)) == 0)
		ft_putstr_fd("can't open texture or permission denied\n", 2);
	if (ft_strncmp(str, "open", ft_strlen(str)) == 0)
		ft_putstr_fd("can't open the map or permission error!\n", 2);
	if (ft_strncmp(str, "no file", ft_strlen(str)) == 0)
		ft_putstr_fd("program need a file in format (.cub) to run!\n", 2);
	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
		ft_putstr_fd("memory allocation denied!\n", 2);
	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
		ft_putstr_fd("file extension is not correct!\n", 2);
	if (ft_strncmp(str, "Empty file", ft_strlen(str)) == 0)
		ft_putstr_fd("your given file is empty!\n", 2);
	if (ft_strncmp(str, "not enclosed", ft_strlen(str)) == 0)
		ft_putstr_fd("map is not enclosed by wall!\n", 2);
	if (ft_strncmp(str, "amount of player", ft_strlen(str)) == 0)
		ft_putstr_fd("amount of player doesn't coorect!\n", 2);
	if (ft_strncmp(str, "char after map", ft_strlen(str)) == 0)
		ft_putstr_fd("after map can't be any other element!\n", 2);
	if (ft_strncmp(str, "color", ft_strlen(str)) == 0)
		ft_putstr_fd("syntax color not correct!\n", 2);
	free_all(whole, 1);
}
