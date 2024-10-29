/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 08:21:42 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/29 15:42:16 by adakheel      ########   odam.nl         */
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

void	draw_ray(t_whole *whole)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		steps;
	int		i;
	// t_whole		*whole;

	// whole = (t_whole *)param;
	if (whole->ray_image != NULL)
		mlx_delete_image(whole->mlx, whole->ray_image);
	//mlx_image_t	*image;
	whole->ray_image = mlx_new_image(whole->mlx, whole->width, whole->height);

	// Starting point
	x0 = (int)(whole->player_x);
	y0 = (int)(whole->player_y);

	// Ending point of the ray
	x1 = (int)(whole->ray->rx);
	y1 = (int)(whole->ray->ry);

	// Calculate differences
	dx = x1 - x0;
	dy = y1 - y0;

	// Calculate the number of steps needed
	steps = fmax(abs(dx), abs(dy));  // max of the absolute differences

	// Calculate increment for each step
	float x_inc = (float)dx / (float)steps;
	float y_inc = (float)dy / (float)steps;

	// Draw the line using the increment
	for (i = 0; i <= steps; i++)
	{
		int pixel_x = (int)(x0 + i * x_inc);
		int pixel_y = (int)(y0 + i * y_inc);
		
		// Assuming mlx_put_pixel takes (mlx_ptr, x, y, color)
		mlx_put_pixel(whole->ray_image, pixel_x, pixel_y, 0xFFFFFF); // white color
	}
	mlx_image_to_window(whole->mlx, whole->ray_image, 0, 0);
}


void	calculate_ray(t_whole *whole)
{
	whole->ray->atan = -1 / tan(whole->ray->ra);
	if (whole->ray->ra > PI)
	{
		whole->ray->ry = (((int) whole->player_y >> 6) << 6) - 0.0001;
		whole->ray->rx = (whole->player_y - whole->ray->ry) * whole->ray->atan + whole->player_x;
		whole->ray->yo = -64;
		whole->ray->xo = -whole->ray->yo * whole->ray->atan;
	}
	if (whole->ray->ra < PI)
	{
		whole->ray->ry = (((int) whole->player_y >> 6) << 6) + 64;
		whole->ray->rx = (whole->player_y - whole->ray->ry) * whole->ray->atan + whole->player_x;
		whole->ray->yo = 64;
		whole->ray->xo = -whole->ray->yo * whole->ray->atan;
	}
	if (whole->ray->ra == 0 || whole->ray->ra == PI)
	{
		whole->ray->rx = whole->player_x;
		whole->ray->ry = whole->player_y;
		whole->ray->dof = 8;
	}
}


void	raycasting(void *param)
{
	printf("in ray casting\n");
	int			r;
	int			pos_ray_x;
	int			pos_ray_y;
	t_whole		*whole;

	whole = (t_whole *)param;
	if (whole->ray != NULL)
		free(whole->ray);
	whole->ray = ft_calloc(1, sizeof(t_ray));
	r = 0;
	whole->ray->ra = whole->pa;
	while (r < 1)
	{
		whole->ray->dof = 0;
		calculate_ray(whole);
		while (whole->ray->dof < 8)
		{
			pos_ray_x = (int)(whole->ray->rx) >> 6;
			pos_ray_y = (int)(whole->ray->ry) >> 6;
			printf("pos_ray_x is (%d)\n", pos_ray_x);
			printf("pos_ray_y is (%d)\n", pos_ray_y);
			if ((pos_ray_x > 0 && pos_ray_x < whole->column) && (pos_ray_y > 0 && pos_ray_y < whole->map_lines) && (whole->map->tiles[pos_ray_y][pos_ray_x].symbol == '1'))
				whole->ray->dof = 8;
			else
			{
				printf("here\n");
				whole->ray->rx += whole->ray->xo;
				whole->ray->ry += whole->ray->yo;
				printf("after update pos_ray_x is (%d)\n", pos_ray_x);
				printf("after update pos_ray_y is (%d)\n", pos_ray_y);
			}
			whole->ray->dof++;
		}
		r++;
		draw_ray(whole);
	}
}

