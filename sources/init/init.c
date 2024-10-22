/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/22 08:09:41 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	// data->ceiling = ft_draw_rect(data->mlx, WIDTH + 1, HEIGHT, data->c_hex);
	// if (!data->ceiling)
	// {
	// 	mlx_close_window(data->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(data->mlx, data->ceiling, 0, 0) == -1)
	// {
	// 	mlx_close_window(data->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// data->floor = ft_draw_rect(data->mlx, WIDTH + 1, HEIGHT / 2, data->f_hex);
	// if (!data->floor)
	// {
	// 	mlx_close_window(data->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(data->mlx, data->floor, 0, HEIGHT / 2) == -1)
	// {
	// 	mlx_close_window(data->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	data->image = mlx_new_image(data->mlx, 32, 32);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, WIDTH / 2 - 16, HEIGHT / 2 - 16) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_data	*malloc_struct(char *map)
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

void	init_struct(t_data *data)
{
	data->c_hex = hexconvert(data->ceiling_str);
	data->f_hex = hexconvert(data->floor_str);
}

int	compare_and_store(t_data *data, char *line, char *prefix)
{
	if (!ft_strncmp(line, prefix, ft_strlen(prefix)))
	{
		if (prefix[0] == 'N')
			data->no_str = line + ft_strlen(prefix);
		if (prefix[0] == 'S')
			data->so_str = line + ft_strlen(prefix);
		if (prefix[0] == 'W')
			data->we_str = line + ft_strlen(prefix);
		if (prefix[0] == 'E')
			data->ea_str = line + ft_strlen(prefix);
		if (prefix[0] == 'C')
			data->ceiling_str = line + ft_strlen(prefix);
		if (prefix[0] == 'F')
			data->floor_str = line + ft_strlen(prefix);
		return (1);
	}
	return (0);
}

int	save_element(t_data *data, char *line)
{
	int	result;

	result = compare_and_store(data, line, "NO ");
	result = compare_and_store(data, line, "SO ");
	result = compare_and_store(data, line, "WE ");
	result = compare_and_store(data, line, "EA ");
	result = compare_and_store(data, line, "C ");
	result = compare_and_store(data, line, "F ");

	return (result);
}

void	check_element(t_data *data, char *line)
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
			save_element(data, line);
			break ;
		}
		else
		i++;
	}
}

void	check_file(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->input_map, O_RDONLY);
	if (fd < 0)
		malloc_or_open_failed(data, 2);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		check_element(data, line);
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	printf("\n");
	close(fd);
}
