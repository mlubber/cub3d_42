/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_casting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:42:52 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 04:57:21 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_hit_wall_vertical(t_whole *whole, int i)
{
	int	t_rx;
	int	t_ry;

	whole->ray->v_dist = 10000000;
	while (i < whole->column)
	{
		t_rx = (int)(whole->ray->v_rx) / TILE;
		t_ry = (int)(whole->ray->v_ry) / TILE;
		if ((t_rx >= 0 && t_rx < whole->column) && (t_ry >= 0
				&& t_ry < whole->rows)
			&& (whole->map->tiles[t_ry][t_rx].symbol == '1'))
		{
			whole->ray->v_dist = calculate_distance(whole->player_x,
					whole->player_y, whole->ray->v_rx, whole->ray->v_ry);
			break ;
		}
		else
		{
			whole->ray->v_rx += whole->ray->v_xo;
			whole->ray->v_ry += whole->ray->v_yo;
		}
		if (t_rx < 0 || t_rx > whole->column || t_ry < 0 || t_ry > whole->rows)
			break ;
		i++;
	}
}

void	calculate_ray_vertical_line(t_whole *whole)
{
	whole->ray->v_tan = -tan(whole->ray->ra);
	if (whole->ray->ra > P2 && whole->ray->ra < P3)
	{
		whole->ray->v_rx = ((int)whole->player_x / TILE * TILE) - 0.0001;
		whole->ray->v_ry = ((whole->player_x - whole->ray->v_rx)
				* whole->ray->v_tan) + whole->player_y;
		whole->ray->v_xo = -TILE;
		whole->ray->v_yo = -whole->ray->v_xo * whole->ray->v_tan;
	}
	if (whole->ray->ra < P2 || whole->ray->ra > P3)
	{
		whole->ray->v_rx = ((int)whole->player_x / TILE * TILE) + TILE;
		whole->ray->v_ry = ((whole->player_x - whole->ray->v_rx)
				* whole->ray->v_tan) + whole->player_y;
		whole->ray->v_xo = TILE;
		whole->ray->v_yo = -whole->ray->v_xo * whole->ray->v_tan;
	}
}

void	check_hit_wall_horizonal(t_whole *whole, int i)
{
	int	t_rx;
	int	t_ry;

	whole->ray->h_dist = 10000000;
	while (i < whole->rows)
	{
		t_rx = (int)(whole->ray->h_rx) / TILE;
		t_ry = (int)(whole->ray->h_ry) / TILE;
		if ((t_rx >= 0 && t_rx < whole->column) && (t_ry >= 0
				&& t_ry < whole->rows)
			&& (whole->map->tiles[t_ry][t_rx].symbol == '1'))
		{
			whole->ray->h_dist = calculate_distance(whole->player_x,
					whole->player_y, whole->ray->h_rx, whole->ray->h_ry);
			break ;
		}
		else
		{
			whole->ray->h_rx += whole->ray->h_xo;
			whole->ray->h_ry += whole->ray->h_yo;
		}
		if (t_rx < 0 || t_rx > whole->column || t_ry < 0 || t_ry > whole->rows)
			break ;
		i++;
	}
}

void	calculate_ray_horizonal_line(t_whole *whole)
{
	whole->ray->h_tan = -1 / tan(whole->ray->ra);
	if (whole->ray->ra > PI)
	{
		whole->ray->h_ry = ((int)whole->player_y / TILE * TILE) - 0.0001;
		whole->ray->h_rx = ((whole->player_y - whole->ray->h_ry)
				* whole->ray->h_tan) + whole->player_x;
		whole->ray->h_yo = -TILE;
		whole->ray->h_xo = -whole->ray->h_yo * whole->ray->h_tan;
	}
	if (whole->ray->ra < PI)
	{
		whole->ray->h_ry = ((int)whole->player_y / TILE * TILE) + TILE;
		whole->ray->h_rx = ((whole->player_y - whole->ray->h_ry)
				* whole->ray->h_tan) + whole->player_x;
		whole->ray->h_yo = TILE;
		whole->ray->h_xo = -whole->ray->h_yo * whole->ray->h_tan;
	}
}

void	draw_v_line(t_whole *whole, int width, int height, int r)
{
	int	x;
	int	y;
	int	colour;

	x = 0;
	y = 0;
	if (whole->ray->horizontal == true && (whole->ray->ra > PI
			&& whole->ray->ra < (2 * PI)))
		colour = 0x000098FF;
	else if (whole->ray->horizontal == true && (whole->ray->ra > 0
			&& whole->ray->ra < PI))
		colour = 0x000098FF;
	else if (whole->ray->vertical == true && (whole->ray->ra > (0.5 * PI)
			&& whole->ray->ra < (1.5 * PI)))
		colour = 0x0035D0FF;
	else
		colour = 0x0035D0FF;
	while (y < height)
	{
		mlx_put_pixel(whole->ray_image, ((r * width) + x) + whole->width,
			(whole->height / 2 - height / 2) + y, colour);
		y++;
		if (y + 1 == height)
		{
			y = 0;
			x++;
			if (x == width)
				break ;
		}
	}
}

void	raycasting(t_whole *whole)
{
	int	r;
	int	wall;

	r = 0;
	whole->ray->r_dist = 0;
	if (whole->ray_image)
		mlx_delete_image(whole->mlx, whole->ray_image);
	// if (whole->minimap)
	// 	mlx_delete_image(whole->mlx, whole->minimap);
	whole->ray->ra = whole->pa - (DR * 30);
	change_degrees(whole);
	whole->ray_image = mlx_new_image(whole->mlx, whole->width + 1920,
			whole->height * 2);
	// draw_ray(whole, 0);
	while (r < 240)
	{
		calculate_ray_vertical_line(whole);
		check_hit_wall_vertical(whole, 0);
		calculate_ray_horizonal_line(whole);
		check_hit_wall_horizonal(whole, 0);
		set_ray_to_draw(whole);
		// draw_ray(whole, 0);
		if ((int)whole->ray->r_dist != 0)
			wall = (whole->height * TILE) / (int)whole->ray->r_dist;
		else
			wall = whole->height;
		if (wall > whole->height)
			wall = whole->height;
		draw_v_line(whole, 8, wall, r);
		r++;
		whole->ray->ra += (0.25 * DR);
		change_degrees(whole);
	}
	draw_mini_map(whole, 0xFFFFFFFF);
	mlx_image_to_window(whole->mlx, whole->ray_image, 0, 0);
	// put_mini_map(whole);
	// printf("raycasting %d\n", whole->ray_image->instances->z);
	whole->ray_image->instances->z = 464;
	// printf("torch %d\n", whole->torch_00->instances->z);
}
