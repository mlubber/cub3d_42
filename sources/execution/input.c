/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 09:02:29 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 10:28:08 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	collision_check(t_whole *whole, double x, double y)
// {
// 	int		i;
// 	int		x_incr;
// 	int		y_incr;
// 	int		xo;
// 	int		yo;

// 	x_incr = (int)whole->player_x - (int)x;
// 	y_incr = (int)whole->player_y - (int)y;
// 	if (whole->pdx < 0)
// 		xo = -(TILE / 4);
// 	else
// 		xo = (TILE / 4);
// 	if (whole->pdy < 0)
// 		yo = -(TILE / 4);
// 	else
// 		yo = (TILE / 4);
// 	if (whole->map->tiles[(int)((y + yo) / TILE)][(int)((x + xo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y) / TILE)][(int)((x + xo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y + yo) / TILE)][(int)((x) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y - yo) / TILE)][(int)((x - xo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - xo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y - yo) / TILE)][(int)((x) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y - xo) / TILE)][(int)((x + yo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y) / TILE)][(int)((x + yo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y - xo) / TILE)][(int)((x) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y + xo) / TILE)][(int)((x - yo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - yo) / TILE)].symbol != '1'
// 		&& whole->map->tiles[(int)((y + xo) / TILE)][(int)((x) / TILE)].symbol != '1')
// 	{
// 		whole->player_x = x;
// 		whole->player_y = y;
// 		// whole->image->instances[0].x = (int)whole->player_x - 5;
// 		// whole->image->instances[0].y = (int)whole->player_y - 5;
// 		// printf("inst_x: %d\n", whole->image->instances[0].x);
// 		// printf("inst_y: %d\n", whole->image->instances[0].y);
// 		i = 0;
// 		while (i < whole->k)
// 		{
// 			// whole->wall->instances[i].x += x_incr;
// 			// whole->wall->instances[i].y += y_incr;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < whole->l)
// 		{
// 			// whole->floor->instances[i].x += x_incr;
// 			// whole->floor->instances[i].y += y_incr;
// 			i++;
// 		}
// 	}
// 	// else
// 	// {
// 	// 	if (whole->map->tiles[(int)((y) / TILE)][(int)((x + xo) / TILE)].symbol != '1')
// 	// 	{
// 	// 		whole->player_x = x;
// 	// 		// whole->image->instances[0].x = (int)whole->player_x - 5;
// 	// 	}
// 	// 	if (whole->map->tiles[(int)((y + yo) / TILE)][(int)((x) / TILE)].symbol != '1')
// 	// 	{
// 	// 		whole->player_y = y;
// 	// 		// whole->image->instances[0].y = (int)whole->player_y - 5;
// 	// 	}
// 	// }
// 	whole->image->instances[0].x = (int)whole->player_x - 5;
// 	whole->image->instances[0].y = (int)whole->player_y - 5;
// 	whole->moved = true;
// }

static int	clear_in_all_directions(t_whole *whole, int x, int y)
{
	if (whole->map->tiles[(int)((y)
			/ TILE)][(int)((x + whole->xo) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y + whole->yo)
		/ TILE)][(int)((x) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y - whole->yo)
		/ TILE)][(int)((x - whole->xo) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - whole->xo)
		/ TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y - whole->yo)
		/ TILE)][(int)((x) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y - whole->xo)
		/ TILE)][(int)((x + whole->yo) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x + whole->yo)
		/ TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y - whole->xo)
		/ TILE)][(int)((x) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y + whole->xo)
		/ TILE)][(int)((x - whole->yo) / TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y) / TILE)][(int)((x - whole->yo)
		/ TILE)].symbol != '1'
		&& whole->map->tiles[(int)((y + whole->xo)
		/ TILE)][(int)((x) / TILE)].symbol != '1')
		return (1);
	return (0);
}

// static void update_tile_visibility(t_whole *whole) {
//     int radius = 3 * TILE;  // 5-tile radius in pixels

//     for (int i = 0; i < whole->k; i++)
// 	{
//         int dx = abs(whole->wall->instances[i].x - (int)whole->player_x);
//         int dy = abs(whole->wall->instances[i].y - (int)whole->player_y);

//         // Enable if within the 5x5 square, otherwise disable
//         whole->wall->instances[i].enabled = (dx <= radius && dy <= radius);
//     }

//     for (int i = 0; i < whole->l; i++)
// 	{
//         int dx = abs(whole->floor->instances[i].x - (int)whole->player_x);
//         int dy = abs(whole->floor->instances[i].y - (int)whole->player_y);

//         whole->floor->instances[i].enabled = (dx <= radius && dy <= radius);
//     }
// }

static void	collision_check(t_whole *whole, double x, double y)
{
	int		i;
	int		x_incr;
	int		y_incr;

	x_incr = (int)(whole->player_x - x);
	y_incr = (int)(whole->player_y - y);
	if (whole->pdx < 0)
		whole->xo = -(TILE / 4);
	else
		whole->xo = (TILE / 4);
	if (whole->pdy < 0)
		whole->yo = -(TILE / 4);
	else
		whole->yo = (TILE / 4);
	if (whole->map->tiles[(int)((y + whole->yo)
			/ TILE)][(int)((x + whole->xo) / TILE)].symbol != '1'
		&& clear_in_all_directions(whole, x, y) == 1)
	{
		whole->player_x = x;
		whole->player_y = y;
		i = 0;
		while (i < whole->k)
		{
			// printf("instance_x: %d\n", whole->wall->instances[i].x / TILE);
			// printf("player_x: %d\n", (int)whole->player_x / TILE);
			// printf("instance_y: %d\n", whole->wall->instances[i].x / TILE);
			// printf("player_y: %d\n", (int)whole->player_y / TILE);
			// if (whole->wall->instances[i].y / TILE > ((int)whole->player_y / TILE))
			// 	whole->wall->instances[i].enabled = false;
			// whole->wall->instances[i].x += x_incr;
			// whole->wall->instances[i].y += y_incr;
			i++;
		}
		i = 0;
		while (i < whole->l)
		{
			// printf("instance_x: %d\n", whole->floor->instances[i].x / TILE);
			// printf("player_x: %f\n", whole->player_x / TILE);
			// printf("instance_y: %d\n", whole->floor->instances[i].x / TILE);
			// printf("player_y: %f\n", whole->player_y / TILE);
			// if ((whole->floor->instances[i].y) / TILE == (int)((whole->player_y) / TILE))
			// 	whole->floor->instances[i].enabled = false;
			// whole->floor->instances[i].x += x_incr;
			// whole->floor->instances[i].y += y_incr;
			i++;
		}
	}
	// update_tile_visibility(whole);
	whole->image->instances[0].x = (int)whole->player_x - 5;
	whole->image->instances[0].y = (int)whole->player_y - 5;
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
		y = whole->player_y - whole->pdx;
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

void	rotate_mouse(t_whole *whole, char direction)
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

void	ft_hook(void *param)
{
	t_whole	*whole;

	whole = (t_whole *)param;
	whole->moved = false;
	if (mlx_is_key_down(whole->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(whole->mlx);
	if (mlx_is_key_down(whole->mlx, MLX_KEY_W))
		move(whole, whole->player_x, whole->player_y, 'U');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_S))
		move(whole, whole->player_x, whole->player_y, 'D');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_A))
		move(whole, whole->player_x, whole->player_y, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_D))
		move(whole, whole->player_x, whole->player_y, 'R');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_LEFT))
		rotate(whole, 'L');
	if (mlx_is_key_down(whole->mlx, MLX_KEY_RIGHT))
		rotate(whole, 'R');
	mlx_cursor_hook(whole->mlx, mouse_move_callback, whole);
	if (whole->delta_spin)
		whole->moved = true;
	if (whole->moved)
		raycasting(whole);
	printf("hello world!\n");
}
