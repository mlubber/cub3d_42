/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 13:23:45 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 13:24:22 by mlubbers      ########   odam.nl         */
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
			colour = ft_pixel(rand() % 0xFF, rand() % 0xFF, rand() % 0xFF,
					rand() % 0xFF);
			mlx_put_pixel(data->image, i, y, colour);
			y++;
		}
		i++;
	}
}

void	*ft_draw_rect(mlx_t *mlx, uint32_t width, uint32_t height,
		uint32_t color)
{
	mlx_image_t	*image;
	uint32_t	x;
	uint32_t	y;

	image = mlx_new_image(mlx, width, height);
	x = 0;
	y = 0;
	while (y < height)
	{
		mlx_put_pixel(image, x, y, color);
		if (y + 1 == height)
		{
			y = 0;
			x++;
			if (x + 1 == width)
				break ;
		}
		y++;
	}
	return (image);
}
