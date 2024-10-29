/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 08:21:42 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/29 11:20:21 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	put_player(void *param)
{
	t_whole		*whole;
	uint32_t	i;
	uint32_t	y;
	uint32_t	colour;

	whole = (t_whole *)param;
	i = 0;
	while (i < whole->image->width)
	{
		y = 0;
		while (y < whole->image->height)
		{
			colour = ft_pixel(255, 255, 0,
					255);
			mlx_put_pixel(whole->image, i, y, colour);
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
