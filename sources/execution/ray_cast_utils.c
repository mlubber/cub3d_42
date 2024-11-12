/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:45:16 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/12 13:48:48 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	calculate_distance(double ax, double ay, double bx, double by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

void	change_degrees(t_whole *whole)
{
	if (whole->ray->ra < 0)
		whole->ray->ra += (2 * PI);
	if (whole->ray->ra > 2 * PI)
		whole->ray->ra -= (2 * PI);
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

static void	choose_texture(t_whole *whole)
{
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
	if ((int)whole->ray->r_dist != 0)
		whole->wall_height = (whole->height * TILE) / (int)whole->ray->r_dist;
	if (whole->wall_height > 3000)
		whole->wall_height = 3000;
	whole->scale = (double)whole->wall_height
		/ (double)whole->which_texture->height;
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
	choose_texture(whole);
}
