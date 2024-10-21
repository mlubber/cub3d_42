/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 08:34:07 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	data->image = mlx_new_image(data->mlx, 128, 128);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_data	*init_struct(char *map)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error_exit("alloc");
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
	{
		free(data);
		error_exit("alloc");
	}
	data->input_map = map;
	return (data);
}

int	compare_and_store(char *line, char *prefix)
{
	if (!ft_strncmp(line, prefix, ft_strlen(prefix)))
	{
		printf("compare");
		return (1);
	}
	return (0);
}

int	save_element(char *line)
{
	int	result;

	result = compare_and_store(line, "NO ");
	result = compare_and_store(line, "SO ");
	result = compare_and_store(line, "WE ");
	result = compare_and_store(line, "EA ");
	result = compare_and_store(line, "F ");
	result = compare_and_store(line, "C ");

	return (result);
}

void	check_element(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_whitespace(line[i]) && line[i] != '\n')
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		{
			save_element(line);
			break ;
		}
		i++;
	}
}

void	check_file(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->input_map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		check_element(line);
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	printf("\n");
}
