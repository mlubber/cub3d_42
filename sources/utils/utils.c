/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 10:49:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 07:01:40 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *param)
{
	t_data		*data;
	uint32_t	i;
	uint32_t	y;
	uint32_t	colour;

	data = (t_data *)param;
	i = 0;
	while (i < data->image->width)
	{
		y = 0;
		while (y < data->image->height)
		{
			colour = ft_pixel(rand() % 0xFF, rand() % 0xFF,
					rand() % 0xFF, rand() % 0xFF);
			mlx_put_pixel(data->image, i, y, colour);
			y++;
		}
		i++;
	}
}

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "alloc", ft_strlen(str)) == 0)
		ft_putstr_fd("Memory allocation failed\n", 2);
	if (ft_strncmp(str, "arg", ft_strlen(str)) == 0)
		ft_putstr_fd("Program only needs map path as argument\n", 2);
	if (ft_strncmp(str, "ext", ft_strlen(str)) == 0)
		ft_putstr_fd("Wrong map extension\n", 2);
	exit(EXIT_FAILURE);
}

void	check_extension(t_data *data)
{
	int	i;

	i = 0;
	while (data->input_map[i] && data->input_map[i] != '.')
		i++;
	if (data->input_map[i] == '.'
		&& ft_strncmp(&data->input_map[i], ".cub",
			ft_strlen(&data->input_map[i])) == 0)
		return ;
	else
	{
		free(data->map);
		free(data);
		error_exit("ext");
	}
}

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
