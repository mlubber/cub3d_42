/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 10:49:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/15 10:49:58 by mlubbers      ########   odam.nl         */
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
