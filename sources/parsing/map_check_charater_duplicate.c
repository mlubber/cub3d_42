/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_charater_duplicate.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 10:49:33 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/29 11:05:41 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	other_char_inside_map(t_whole *whole)
{
	int	y;
	int	x;

	y = 0;
	while (y < whole->map_lines)
	{
		x = 0;
		while (x < whole->column)
		{
			if (!ft_strchr("NSEW01 ", whole->map->tiles[y][x].symbol))
			{
				printf("Error, this character: (%c) is invalid\n",
					whole->map->tiles[y][x].symbol);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_player_double(t_whole *whole)
{
	int	y;
	int	x;
	int	player;

	y = 0;
	player = 0;
	while (y < whole->map_lines)
	{
		x = 0;
		while (x < whole->column)
		{
			if (ft_strchr("NSEW", whole->map->tiles[y][x].symbol))
			{
				whole->player_x = (double)x * TILE;
				whole->player_y = (double)y * TILE;
				player++;
				whole->player_dir = whole->map->tiles[y][x].symbol;
			}
			x++;
		}
		y++;
	}
	if (player == 0 || player > 1)
		return (1);
	return (0);
}

int	call_checker_function(t_whole *whole)
{
	if (is_player_double(whole))
		return (3);
	if (other_char_inside_map(whole))
		return (2);
	if (check_edges(whole))
		return (1);
	return (0);
}

int	check_map(t_whole *whole, int y, int x)
{
	y = call_checker_function(whole);
	if (y)
		return (y);
	while (y < whole->map_lines)
	{
		x = 0;
		while (x < whole->column)
		{
			if (whole->map->tiles[y][x].symbol == ' ')
			{
				if (check_next_char(whole, y, x, 0) || check_next_char(whole
						, y, x, 1) || check_next_char(whole, y, x, 2)
					|| check_next_char(whole, y, x, 3))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	call_check_map_and_result(t_whole *whole, int i, char *line)
{
	i = check_map(whole, 0, 0);
	if (i)
	{
		free(line);
		if (i == 1)
			print_error(whole, "not enclosed");
		if (i == 3)
			print_error(whole, "amount of player");
		free_all(whole, 1);
	}
}
