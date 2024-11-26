/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doors.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 14:22:01 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:17 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static int	check_round_door(t_whole *whole, int door_x, int door_y)
{
	if (whole->rows >= door_y + 1 && 0 <= door_y - 1)
	{
		if (whole->map->tiles[door_y + 1][door_x].symbol == '1' && \
		(whole->map->tiles[door_y - 1][door_x].symbol == '1'))
			return (1);
	}
	if (whole->column >= door_x + 1 && 0 <= door_x - 1)
	{
		if (whole->map->tiles[door_y][door_x + 1].symbol == '1' && \
		(whole->map->tiles[door_y][door_x - 1].symbol == '1'))
			return (1);
	}
	return (0);
}

static void	check_door_position(t_whole *whole)
{
	int			result;
	t_map_list	*temp;

	temp = whole->list_clue;
	while (temp)
	{
		result = check_round_door(whole, temp->x, temp->y);
		if (result == 0)
		{
			printf("door has to be between two wall\n");
			free_all(whole, 1);
		}
		temp = temp->next;
	}
}

void	make_list_door(t_whole *whole)
{
	int	y;
	int	x;
	int	instance;

	y = 0;
	instance = 0;
	while (y < whole->rows)
	{
		x = 0;
		while (x < whole->column)
		{
			if (whole->map->tiles[y][x].symbol == 'D')
				make_node(x, y, instance++, whole);
			x++;
		}
		y++;
	}
	check_door_position(whole);
}
