/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 09:02:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/29 09:34:11 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	collision_check(t_whole *whole, double x, double y)
{
	if (whole->map->tiles[(int)(y / TILE)][(int)(x / TILE)].symbol != '1')
	{
		whole->player_x = x;
		whole->player_y = y;
		whole->image->instances[0].x = (int)whole->player_x;
		whole->image->instances[0].y = (int)whole->player_y;
	}
}

static void	move(t_whole *whole, double x, double y, char direction)
{
	if (direction == 'U')
	{
		x = whole->player_x - (whole->pdx / TILE);
		y = whole->player_y - (whole->pdy / TILE);
	}
	else if (direction == 'D')
	{
		x = whole->player_x + (whole->pdx / TILE);
		y = whole->player_y + (whole->pdy / TILE);
	}
	else if (direction == 'L')
	{
		x = whole->player_x - (whole->pdy / TILE);
		y = whole->player_y + (whole->pdx / TILE);
	}
	else
	{
		x = whole->player_x + (whole->pdy / TILE);
		y = whole->player_y - (whole->pdx / TILE);
	}
	collision_check(whole, x, y);
}

static void	rotate(t_whole *whole, char direction)
{
	if (direction == 'L')
	{
		whole->pa -= 0.1;
		if (whole->pa < 0)
			whole->pa += 2 * PI;
	}
	else
	{
		whole->pa += 0.1;
		if (whole->pa > 2 * PI)
			whole->pa -= 2 * PI;
	}
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
}

void	ft_hook(void *param)
{
	t_whole	*whole;
	double	temp_x;
	double	temp_y;

	whole = (t_whole *)param;
	temp_x = whole->player_x;
	temp_y = whole->player_y;
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
}