/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:45:16 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:57 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

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

int	search_door_node(t_whole *whole, int y, int x)
{
	t_map_list	*node;

	node = whole->list_clue;
	while (node)
	{
		if (node->x == x && node->y == y)
			return (1);
		node = node->next;
	}
	return (0);
}
