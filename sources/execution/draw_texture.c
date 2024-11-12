/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 09:58:26 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/12 14:02:23 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	texture_offset(t_whole *whole)
{
	double	off_set;

	if (whole->ray->horizonal)
		off_set = ((whole->ray->rx / TILE) - ((int)whole->ray->rx / TILE))
			* whole->which_texture->width;
	else
		off_set = ((whole->ray->ry / TILE) - ((int)whole->ray->ry / TILE))
			* whole->which_texture->width;
	return ((int)off_set);
}

static uint32_t	find_pixels_color(int y, int x, mlx_texture_t *texture)
{
	int		pixel_index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	pixel_index = (y * texture->width + x) * 4;
	r = texture->pixels[pixel_index];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	scale_and_put_pixel(t_whole *whole, int start_x, int y, int x)
{
	int			dy;
	int			dx;
	uint32_t	screen_x;
	uint32_t	screen_y;

	dy = 0;
	while (dy < whole->scale)
	{
		dx = 0;
		screen_y = (whole->height / 2) - (whole->wall_height / 2)
			+ (int)(y * whole->scale + dy);
		if ((int)screen_y > whole->height || screen_y < 0)
			break ;
		while (dx < x)
		{
			screen_x = start_x + (int)(x + dx);
			if (screen_x >= 0 && screen_x < whole->ray_image->width
				&& screen_y >= 0 && screen_y < whole->ray_image->height)
				mlx_put_pixel(whole->ray_image, screen_x, screen_y,
					whole->color);
			dx += 1;
		}
		dy += 1;
	}
}

void	draw_texture(t_whole *whole, int start_x)
{
	uint32_t	y;
	uint32_t	x;
	int			offset;

	y = 0;
	offset = texture_offset(whole);
	while (y < whole->which_texture->height)
	{
		x = 0;
		while (x < 8)
		{
			whole->color = find_pixels_color(y, offset, whole->which_texture);
			scale_and_put_pixel(whole, start_x, y, x);
			x++;
		}
		y++;
	}
	mlx_image_to_window(whole->mlx, whole->ray_image, 0, 0);
}
