/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:37 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

void	error_close_window(t_whole *whole, int exit_code)
{
	mlx_close_window(whole->mlx);
	if (exit_code)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		free_all(whole, 1);
	}
	else
		free_all(whole, 0);
}

static void	*ft_draw_rect(t_whole *whole, uint32_t width, uint32_t height,
		uint32_t color)
{
	mlx_image_t	*image;
	uint32_t	x;
	uint32_t	y;

	image = mlx_new_image(whole->mlx, width, height);
	if (!image)
		error_close_window(whole, 1);
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

static void	put_background(t_whole *whole)
{
	whole->ceiling = ft_draw_rect(whole, whole->width,
			whole->height, whole->c_hex);
	if (!whole->ceiling)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->ceiling, 0, 0) == -1)
		error_close_window(whole, 1);
	whole->ground = ft_draw_rect(whole, whole->width,
			whole->height / 2, whole->g_hex);
	if (!whole->ground)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->ground, 0,
			whole->height / 2) == -1)
		error_close_window(whole, 1);
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

void	init_window(t_whole *whole)
{
	whole->mlx = mlx_init(whole->width, whole->height, "CUB3D", false);
	if (!whole->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		free_all(whole, 1);
	}
	init_pa(whole);
	put_background(whole);
	whole->ray = ft_calloc(1, sizeof(t_ray));
	if (!whole->ray)
		print_error(whole, "allocation");
	raycasting(whole);
	load_torch(whole);
}
