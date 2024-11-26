/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_pressed.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:19:14 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:49 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

int	check_door_open(t_whole *whole, int ray_x, int ray_y)
{
	t_map_list	*temp;

	temp = door_node(whole, ray_x, ray_y);
	if (temp)
	{
		if (temp->open)
			return (1);
		else
			return (0);
	}
	return (0);
}

t_map_list	*door_node(t_whole *whole, int x, int y)
{
	t_map_list	*temp;

	temp = whole->list_clue;
	while (temp)
	{
		if (temp->x == x && temp->y == y)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

static void	check_door_instance(t_whole *whole, int ray_x, int ray_y)
{
	t_map_list	*temp;

	temp = door_node(whole, ray_x, ray_y);
	if (temp)
	{
		if (temp->open)
		{
			temp->open = false;
			whole->map->tiles[temp->y][temp->x].symbol = 'D';
		}
		else
		{
			temp->open = true;
			whole->map->tiles[temp->y][temp->x].symbol = '0';
		}
		raycasting(whole);
	}
}

static void	space_pressed(t_whole *whole, int p_x, int p_y, t_map_list *temp)
{
	while (temp)
	{
		if (whole->pa > 1.25 * PI && whole->pa < 1.75 * PI)
		{
			if (temp->x == p_x && temp->y == p_y - 1)
				return (check_door_instance(whole, p_x, p_y - 1));
		}
		if (whole->pa > 0.75 * PI && whole->pa < 1.25 * PI)
		{
			if (temp->x == p_x - 1 && temp->y == p_y)
				return (check_door_instance(whole, p_x - 1, p_y));
		}
		if (whole->pa > 0.25 * PI && whole->pa < 0.75 * PI)
		{
			if (temp->x == p_x && temp->y == p_y + 1)
				return (check_door_instance(whole, p_x, p_y + 1));
		}
		if (whole->pa > 1.75 * PI || whole->pa < 0.25 * PI)
		{
			if (temp->x == p_x + 1 && temp->y == p_y)
				return (check_door_instance(whole, p_x + 1, p_y));
		}
		temp = temp->next;
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_whole		*whole;
	t_map_list	*temp;
	int			p_x;
	int			p_y;

	whole = param;
	temp = whole->list_clue;
	p_x = (int)(whole->player_x / TILE);
	p_y = (int)(whole->player_y / TILE);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		space_pressed(whole, p_x, p_y, temp);
}
