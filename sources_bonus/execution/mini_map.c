/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 10:54:00 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 12:09:06 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static void	rotate_point(t_point *p, int x, int y, double angle)
{
	double	translated_x;
	double	translated_y;
	double	rotated_x;
	double	rotated_y;

	translated_x = p->x - x;
	translated_y = p->y - y;
	rotated_x = translated_x * cos(angle) - translated_y * sin(angle);
	rotated_y = translated_x * sin(angle) + translated_y * cos(angle);
	p->x = rotated_x + x;
	p->y = rotated_y + y;
}

static void	draw_filled_triangle(mlx_image_t *img, t_point p1, t_point p2,
		t_point p3)
{
	double	w1;
	double	w2;
	int		y;
	int		x;

	y = fmin(fmin(p1.y, p2.y), p3.y);
	while (y <= fmax(fmax(p1.y, p2.y), p3.y))
	{
		x = fmin(fmin(p1.x, p2.x), p3.x);
		while (x <= fmax(fmax(p1.x, p2.x), p3.x))
		{
			w1 = ((p2.y - p3.y) * (x - p3.x) + (p3.x - p2.x) * (y - p3.y))
				/ ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y
						- p3.y));
			w2 = ((p3.y - p1.y) * (x - p3.x) + (p1.x - p3.x) * (y - p3.y))
				/ ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y
						- p3.y));
			if (w1 >= 0 && w2 >= 0 && (1 - w1 - w2) >= 0)
			{
				mlx_put_pixel(img, x, y, 0xFF0000FF);
			}
			x++;
		}
		y++;
	}
}

static void	draw_rotated_triangle(mlx_image_t *img, int x, int y, double angle)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;

	p1.x = x;
	p1.y = y - 16;
	p2.x = x - 8;
	p2.y = y + 4;
	p3.x = x + 8;
	p3.y = y + 4;
	rotate_point(&p1, x, y, angle);
	rotate_point(&p2, x, y, angle);
	rotate_point(&p3, x, y, angle);
	draw_filled_triangle(img, p1, p2, p3);
}

static void	put_pixel_map(t_whole *whole, int row, int col, uint32_t color)
{
	int		map_x;
	int		map_y;

	map_x = (((int)whole->player_x - TILE * 5 / 2) + col) / TILE;
	map_y = (((int)whole->player_y - TILE * 3 / 2) + row) / TILE;
	if (map_y >= 0 && map_y < whole->rows && map_x >= 0
		&& map_x < whole->column)
	{
		if (whole->map->tiles[map_y][map_x].symbol == '1')
			mlx_put_pixel(whole->ray_image, whole->mm_x + col,
				whole->mm_y + row, color);
		else if (whole->map->tiles[map_y][map_x].symbol == 'D')
			mlx_put_pixel(whole->ray_image, whole->mm_x + col,
				whole->mm_y + row, 0xFFFF00FF);
		else
			mlx_put_pixel(whole->ray_image, whole->mm_x + col,
				whole->mm_y + row, 0x000000FF);
	}
	else
		mlx_put_pixel(whole->ray_image, whole->mm_x + col,
			whole->mm_y + row, 0x000000FF);
}

void	draw_mini_map(t_whole *whole, uint32_t color)
{
	int		row;
	int		col;

	row = 0;
	while (row < TILE * 3)
	{
		col = 0;
		while (col < TILE * 5)
		{
			put_pixel_map(whole, row, col, color);
			col++;
		}
		row++;
	}
	draw_rotated_triangle(whole->ray_image, whole->mm_x + TILE * 5 / 2,
		whole->mm_y + TILE * 3 / 2, whole->pa + 0.5 * PI);
}
