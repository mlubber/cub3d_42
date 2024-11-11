/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 09:02:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/11 07:32:06 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	collision_check(t_whole *whole, double x, double y)
{
	int		i;
	int		x_incr;
	int		y_incr;

	x_incr = (int)whole->player_x - (int)x;
	y_incr = (int)whole->player_y - (int)y;
	if (whole->map->tiles[(int)(y / TILE)][(int)(x / TILE)].symbol != '1')
	{
		whole->player_x = x;
		whole->player_y = y;
		// whole->image->instances[0].x = (int)whole->player_x;
		// whole->image->instances[0].y = (int)whole->player_y;
		// printf("inst_x: %d\n", whole->image->instances[0].x);
		// printf("inst_y: %d\n", whole->image->instances[0].y);
		i = 0;
		while (i < whole->k)
		{
			whole->wall->instances[i].x += x_incr;
			whole->wall->instances[i].y += y_incr;
			i++;
		}
		i = 0;
		while (i < whole->l)
		{
			whole->floor->instances[i].x += x_incr;
			whole->floor->instances[i].y += y_incr;
			i++;
		}
		whole->moved = true;
	}
}

static void	move(t_whole *whole, double x, double y, char direction)
{
	if (direction == 'U')
	{
		x = whole->player_x + whole->pdx;
		y = whole->player_y + whole->pdy;
	}
	else if (direction == 'D')
	{
		x = whole->player_x - whole->pdx;
		y = whole->player_y - whole->pdy;
	}
	else if (direction == 'L')
	{
		x = whole->player_x + whole->pdy;
		y = whole->player_y - whole->pdx ;
	}
	else
	{
		x = whole->player_x - whole->pdy;
		y = whole->player_y + whole->pdx;
	}
	collision_check(whole, x, y);
}

static void	rotate(t_whole *whole, char direction)
{
	if (direction == 'L')
	{
		whole->pa -= 0.05;
		if (whole->pa < 0)
			whole->pa += 2 * PI;
	}
	else
	{
		whole->pa += 0.05;
		if (whole->pa > 2 * PI)
			whole->pa -= 2 * PI;
	}
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
	whole->moved = true;
}

void	ft_hook(void *param)
{
	t_whole	*whole;
	double	temp_x;
	double	temp_y;

	whole = (t_whole *)param;
	temp_x = whole->player_x;
	temp_y = whole->player_y;
	whole->moved = false;
	if (mlx_is_key_down(whole->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(whole->mlx);
	if (mlx_is_key_down(whole->mlx, MLX_KEY_W))
		move(whole, temp_x, temp_y, 'U');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_S))
		move(whole, temp_x, temp_y, 'D');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_A))
		move(whole, temp_x, temp_y, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_D))
		move(whole, temp_x, temp_y, 'R');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_LEFT))
		rotate(whole, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_RIGHT))
		rotate(whole, 'R');
	if (whole->moved)
		raycasting(whole);
}
