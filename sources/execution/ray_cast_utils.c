/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:45:16 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/06 08:23:26 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	fix_fisheye(t_whole *whole, double dist)
{
	double	ca;

	ca = whole->pa - whole->ray->ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	return (dist * cos(ca));
}

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

void	set_ray_to_draw(t_whole *whole)
{
	if (whole->ray->h_dist < whole->ray->v_dist)
	{
		whole->ray->rx = whole->ray->h_rx;
		whole->ray->ry = whole->ray->h_ry;
		whole->ray->r_dist = fix_fisheye(whole, whole->ray->h_dist);
	}
	else
	{
		whole->ray->rx = whole->ray->v_rx;
		whole->ray->ry = whole->ray->v_ry;
		whole->ray->r_dist = fix_fisheye(whole, whole->ray->v_dist);
	}
}
