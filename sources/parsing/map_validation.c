/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 15:00:12 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/29 11:17:13 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_textures(t_whole *whole, char c)
{
	whole->texture = mlx_load_png(whole->cub_t_no);
	if (whole->texture == NULL)
		free_all(whole, 1);
	if (c == 'S')
		whole->no_img = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png(whole->cub_t_so);
	if (whole->texture == NULL)
		free_all(whole, 1);
	if (c == 'S')
		whole->so_img = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png(whole->cub_t_we);
	if (whole->texture == NULL)
		free_all(whole, 1);
	if (c == 'S')
		whole->we_img = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png(whole->cub_t_ea);
	if (whole->texture == NULL)
		free_all(whole, 1);
	if (c == 'S')
		whole->ea_img = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
}

int	check_edge_line(t_tile **tiles, int index, int limit, int is_row)
{
	int		i;
	char	symbol;

	i = 0;
	while (i < limit)
	{
		if (is_row)
			symbol = tiles[index][i].symbol;
		else
			symbol = tiles[i][index].symbol;
		if (symbol != '1' && symbol != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_edges(t_whole *whole)
{
	if (check_edge_line(whole->map->tiles, 0, whole->column, 1) || \
	check_edge_line(whole->map->tiles, whole->map_lines - 1, whole->column, 1))
		return (1);
	if (check_edge_line(whole->map->tiles, 0, whole->map_lines, 0) || \
	check_edge_line(whole->map->tiles, whole->column - 1, whole->map_lines, 0))
		return (1);
	return (0);
}

void	check_next_char_out_bounds(t_whole *whole, int *y, int *x)
{
	if (*x < 0)
		*x = 0;
	else if (*x >= whole->column)
		*x = whole->column - 1;
	if (*y < 0)
		*y = 0;
	else if (*y >= whole->map_lines)
		*y = whole->map_lines - 1;
}

int	check_next_char(t_whole *whole, int y, int x, int direction)
{
	while (x >= 0 && x < whole->column && y >= 0 && y < whole->map_lines \
		&& whole->map->tiles[y][x].symbol == ' ')
	{
		if (direction == 0)
			x++;
		else if (direction == 1)
			x--;
		else if (direction == 2)
			y++;
		else if (direction == 3)
			y--;
	}
	check_next_char_out_bounds(whole, &y, &x);
	if (whole->map->tiles[y][x].symbol == '1' || whole->map->tiles[y][x].symbol \
		== ' ' || whole->map->tiles[y][x].symbol == '\0')
		return (0);
	else
		return (1);
}
