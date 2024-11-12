/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/12 14:48:49 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	error_close_window(t_whole *whole)
{
	mlx_close_window(whole->mlx);
	printf("%s\n", mlx_strerror(mlx_errno));
	return (EXIT_FAILURE);
}

static void	*ft_draw_rect(t_whole *whole, uint32_t width, uint32_t height,
		uint32_t color)
{
	mlx_image_t	*image;
	uint32_t	x;
	uint32_t	y;

	image = mlx_new_image(whole->mlx, width, height);
	if (!image)
		error_close_window(whole);
	x = 0;
	y = 0;
	while (y < height)
	{
		mlx_put_pixel(image, x, y, color);
		y++;
		if (y + 1 == height)
		{
			y = 0;
			x++;
			if (x == width)
				break ;
		}
	}
	return (image);
}

static int	put_background(t_whole *whole)
{
	whole->ceiling = ft_draw_rect(whole, whole->width,
			whole->height, whole->c_hex);
	if (!whole->ceiling)
		return (error_close_window(whole));
	if (mlx_image_to_window(whole->mlx, whole->ceiling, 0, 0) == -1)
		return (error_close_window(whole));
	whole->ground = ft_draw_rect(whole, whole->width,
			whole->height / 2, whole->g_hex);
	if (!whole->ground)
		return (error_close_window(whole));
	if (mlx_image_to_window(whole->mlx, whole->ground, 0,
			whole->height / 2) == -1)
		return (error_close_window(whole));
	return (0);
}

static void	init_pa(t_whole *whole)
{
	if (whole->player_dir == 'E')
		whole->pa = 0;
	if (whole->player_dir == 'S')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'W')
		whole->pa = PI;
	if (whole->player_dir == 'N')
		whole->pa = 1.5 * PI;
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
}

int	init_window(t_whole *whole)
{
	whole->mlx = mlx_init(whole->width, whole->height, "CUB3D", false);
	if (!whole->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	init_pa(whole);
	if (put_background(whole) == 1)
		return (EXIT_FAILURE);
	whole->ray = ft_calloc(1, sizeof(t_ray));
	if (!whole->ray)
		print_error(whole, "allocation");
	raycasting(whole);
	return (EXIT_SUCCESS);
}
