/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 09:02:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 12:09:10 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static int	clear_in_all_directions(t_whole *whole, int x, int y, char c)
{
	if (whole->map->tiles[(int)((y)
			/ TILE)][(int)((x + whole->xo) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y + whole->yo)
		/ TILE)][(int)((x) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y - whole->yo)
		/ TILE)][(int)((x - whole->xo) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - whole->xo)
		/ TILE)].symbol != c
		&& whole->map->tiles[(int)((y - whole->yo)
		/ TILE)][(int)((x) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y - whole->xo)
		/ TILE)][(int)((x + whole->yo) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x + whole->yo)
		/ TILE)].symbol != c
		&& whole->map->tiles[(int)((y - whole->xo)
		/ TILE)][(int)((x) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y + whole->xo)
		/ TILE)][(int)((x - whole->yo) / TILE)].symbol != c
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - whole->yo)
		/ TILE)].symbol != c
		&& whole->map->tiles[(int)((y + whole->xo)
		/ TILE)][(int)((x) / TILE)].symbol != c)
		return (1);
	return (0);
}

static void	collision_check(t_whole *whole, double x, double y, char c)
{
	set_offset(whole);
	if (whole->map->tiles[(int)((y + whole->yo)
			/ TILE)][(int)((x + whole->xo) / TILE)].symbol != c
		&& clear_in_all_directions(whole, x, y, c) == 1
		&& (whole->map->tiles[(int)((y + whole->yo)
			/ TILE)][(int)((x + whole->xo) / TILE)].symbol != 'D'))
	{
		whole->player_x = x;
		whole->player_y = y;
	}
	else if ((whole->map->tiles[(int)((y + whole->yo)
				/ TILE)][(int)((x + whole->xo) / TILE)].symbol == 'D'
		&& check_door_open(whole, (int)((x + whole->xo)
			/ TILE), (int)((y + whole->yo) / TILE))))
	{
		whole->player_x = x;
		whole->player_y = y;
	}
	whole->moved = true;
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
	collision_check(whole, x, y, '1');
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
	whole->moved = true;
}

void	ft_hook(void *param)
{
	t_whole	*whole;

	whole = (t_whole *)param;
	whole->moved = false;
	if (mlx_is_key_down(whole->mlx, MLX_KEY_ESCAPE))
		error_close_window(whole, 0);
	if (mlx_is_key_down(whole->mlx, MLX_KEY_W))
		move(whole, 0, 0, 'U');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_S))
		move(whole, 0, 0, 'D');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_A))
		move(whole, 0, 0, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_D))
		move(whole, 0, 0, 'R');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_LEFT))
		rotate(whole, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_RIGHT))
		rotate(whole, 'R');
	mlx_cursor_hook(whole->mlx, mouse_move_callback, whole);
	if (whole->delta_spin)
		whole->moved = true;
	if (whole->moved)
		raycasting(whole);
}
