/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:59:03 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:09:18 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static void	tile_next_door_horizonal(t_whole *whole, int x, int y)
{
	if (y - 2 >= 0
		&& whole->ray->ra > 0 && whole->ray->ra < PI
		&& whole->map->tiles[y][x].symbol == '1'
		&& search_door_node(whole, y - 1, x)
		&& whole->map->tiles[y - 2][x].symbol == '1'
		&& check_door_open(whole, x, y - 1) == 1)
		whole->which_texture = whole->op_texture;
	else if (y + 2 < whole->rows
		&& whole->ray->ra > PI && whole->ray->ra < 2 * PI
		&& whole->map->tiles[y][x].symbol == '1'
		&& search_door_node(whole, y + 1, x)
		&& whole->map->tiles[y + 2][x].symbol == '1'
		&& check_door_open(whole, x, y + 1) == 1)
		whole->which_texture = whole->op_texture;
}

static void	tile_next_door_vertical(t_whole *whole, int x, int y)
{
	if (x + 2 < whole->column
		&& whole->map->tiles[y][x].symbol == '1'
		&& search_door_node(whole, y, x + 1)
		&& whole->map->tiles[y][x + 2].symbol == '1'
		&& check_door_open(whole, x + 1, y) == 1)
		whole->which_texture = whole->op_texture;
	else if (x - 2 >= 0
		&& whole->map->tiles[y][x].symbol == '1'
		&& search_door_node(whole, y, x - 1)
		&& whole->map->tiles[y][x - 2].symbol == '1'
		&& check_door_open(whole, x - 1, y) == 1)
		whole->which_texture = whole->op_texture;
}

static void	choose_texture(t_whole *whole, int x, int y)
{
	x = (int)(whole->ray->rx / TILE);
	y = (int)(whole->ray->ry / TILE);
	if (whole->ray->horizonal && whole->ray->ra > 0 && whole->ray->ra < PI)
		whole->which_texture = whole->no_texture;
	if (whole->ray->horizonal && whole->ray->ra > PI && whole->ray->ra < 2 * PI)
		whole->which_texture = whole->so_texture;
	if (whole->ray->vertical && (whole->ray->ra < 0.5 * PI
			|| whole->ray->ra > 1.5 * PI))
		whole->which_texture = whole->we_texture;
	if (whole->ray->vertical && whole->ray->ra > 0.5 * PI
		&& whole->ray->ra < 1.5 * PI)
		whole->which_texture = whole->ea_texture;
	if (search_door_node(whole, y, x) && check_door_open(whole, x, y) == 0)
		whole->which_texture = whole->de_texture;
	if (whole->ray->vertical)
		tile_next_door_vertical(whole, x, y);
	if (whole->ray->horizonal)
		tile_next_door_horizonal(whole, x, y);
	if ((int)whole->ray->r_dist != 0)
		whole->wall_height = (whole->height * TILE) / (int)whole->ray->r_dist;
	if (whole->wall_height > 3000)
		whole->wall_height = 3000;
	whole->scale = (double)whole->wall_height
		/ (double)whole->which_texture->height;
}

static double	fix_fisheye(t_whole *whole, double dist)
{
	double	ca;

	ca = whole->pa - whole->ray->ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	return (dist * cos(ca));
}

void	set_ray_to_draw(t_whole *whole)
{
	whole->ray->vertical = false;
	whole->ray->horizonal = false;
	if (whole->ray->h_dist < whole->ray->v_dist)
	{
		whole->ray->rx = whole->ray->h_rx;
		whole->ray->ry = whole->ray->h_ry;
		whole->ray->r_dist = fix_fisheye(whole, whole->ray->h_dist);
		whole->ray->horizonal = true;
	}
	else
	{
		whole->ray->rx = whole->ray->v_rx;
		whole->ray->ry = whole->ray->v_ry;
		whole->ray->r_dist = fix_fisheye(whole, whole->ray->v_dist);
		whole->ray->vertical = true;
	}
	choose_texture(whole, 0, 0);
}
