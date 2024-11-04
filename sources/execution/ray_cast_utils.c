/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:45:16 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/04 15:43:20 by mlubbers      ########   odam.nl         */
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

void	set_ray_to_draw(t_whole *whole)
{
	if (whole->ray->h_dist < whole->ray->v_dist)
	{
		whole->ray->rx = whole->ray->h_rx;
		whole->ray->ry = whole->ray->h_ry;
		whole->ray->r_dist = whole->ray->h_dist;
	}
	else
	{
		whole->ray->rx = whole->ray->v_rx;
		whole->ray->ry = whole->ray->v_ry;
		whole->ray->r_dist = whole->ray->v_dist;
	}
}
