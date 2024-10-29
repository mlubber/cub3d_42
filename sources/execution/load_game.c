/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 12:00:12 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/28 14:19:09 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	load_player(t_whole *whole)
{
	int	i;
	int	j;

	i = 0;
	while (i < whole->map_lines)
	{
		j = 0;
		while (j < whole->column)
		{
			if (whole->map->tiles[i][j].symbol == 'N' || whole->map->tiles[i][j].symbol == 'S' || whole->map->tiles[i][j].symbol == 'W' || whole->map->tiles[i][j].symbol == 'E')
			{
				if (mlx_image_to_window(whole->mlx, whole->img_we, j \
				* 80, i * 80) == -1 || mlx_image_to_window(whole->mlx, whole->img_ea, j \
				* 80, i * 80) == -1)
					print_error(whole, "allocation");
				whole->player_dir = whole->map->tiles[i][j].symbol;
			}
			j++;
		}
		i++;
	}
}

void	load_back_wall(t_whole *whole)
{
	int				i;
	int				j;

	i = 0;
	while (i < whole->map_lines)
	{
		j = 0;
		while (j < whole->column)
		{
			if (whole->map->tiles[i][j].symbol == '1')
			{
				if (mlx_image_to_window(whole->mlx, whole->img_no, j \
				* 80, i * 80) == -1)
					print_error(whole, "allocation");
			}
			if (whole->map->tiles[i][j].symbol == '0')
			{
				if (mlx_image_to_window(whole->mlx, whole->img_we, j \
				* 80, i * 80) == -1)
					print_error(whole, "allocation");
			}
			j++;
		}
		i++;
	}
}

void	make_image(t_whole *whole)
{
	// printf("player x is (%f)\n", whole->x);
	// printf("player y is (%f)\n", whole->y);
	// printf("player pa is (%f)\n", whole->pa);
	// printf("player pdx is (%f)\n", whole->pdx);
	// printf("player pdy is (%f)\n", whole->pdy);
	whole->mlx = mlx_init(whole->column * 80, whole->map_lines * 80, "cub3d", false);
	if (!whole->mlx)
		print_error(whole, "allocation");
	whole->t_ea = mlx_load_png(whole->cub_t_ea);
	whole->t_no = mlx_load_png(whole->cub_t_no);
	whole->t_so = mlx_load_png(whole->cub_t_so);
	whole->t_we = mlx_load_png(whole->cub_t_we);
	if (!whole->t_ea || !whole->t_no || !whole->t_so || !whole->t_we)
		print_error(whole, "allocation");
	whole->img_ea = mlx_texture_to_image(whole->mlx, whole->t_ea);
	whole->img_so = mlx_texture_to_image(whole->mlx, whole->t_so);
	whole->img_no = mlx_texture_to_image(whole->mlx, whole->t_no);
	whole->img_we = mlx_texture_to_image(whole->mlx, whole->t_we);
	if (!whole->img_ea || !whole->img_no || !whole->img_so || !whole->img_we)
		print_error(whole, "allocation");
	load_back_wall(whole);
	load_player(whole);
	whole->pdx = cos((whole->pa) * 5);
	whole->pdy = sin((whole->pa) * 5);
	if (whole->player_dir == 'N')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'S')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'W')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'E')
		whole->pa = 0.5 * PI;
	printf("all done\n");
}
