/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_moved.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:25:28 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:09:01 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static void	rotate_mouse(t_whole *whole, char direction)
{
	if (direction == 'L')
	{
		whole->pa -= (0.005 * abs(whole->delta_spin));
		if (whole->pa < 0)
			whole->pa += 2 * PI;
	}
	else
	{
		whole->pa += (0.005 * abs(whole->delta_spin));
		if (whole->pa > 2 * PI)
			whole->pa -= 2 * PI;
	}
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
	whole->moved = true;
}

void	mouse_move_callback(double x, double y, void *param)
{
	t_whole	*whole;

	(void)y;
	whole = (t_whole *)param;
	whole->delta_spin = (int)x - whole->last_mouse_x;
	if (abs(whole->delta_spin) > 10)
	{
		if (whole->delta_spin > 0)
			whole->delta_spin = 10;
		else
			whole->delta_spin = -10;
	}
	if (whole->delta_spin > 0)
		rotate_mouse(whole, 'R');
	else if (whole->delta_spin < 0)
		rotate_mouse(whole, 'L');
	whole->last_mouse_x = (int)x;
}
