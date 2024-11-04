/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/04 07:57:01 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	put_map(t_whole *whole)
{
	int	i;
	int	j;

	whole->wall = ft_draw_rect(whole->mlx, 80, 80, 0xFFFFFFFF);
	if (!whole->wall)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	whole->floor = ft_draw_rect(whole->mlx, 80, 80, 0x000000FF);
	if (!whole->floor)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < whole->map_lines)
	{
		j = 0;
		while (j < whole->column)
		{
			if (whole->map->tiles[i][j].symbol == '1')
			{
				if (mlx_image_to_window(whole->mlx, whole->wall, j * 80, i * 80) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
			}
			else if (whole->map->tiles[i][j].symbol == '0' || whole->map->tiles[i][j].symbol == ' ')
			{
				if (mlx_image_to_window(whole->mlx, whole->floor, j * 80, i * 80) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
			}
			else
			{
				if (mlx_image_to_window(whole->mlx, whole->floor, j * 80, i * 80) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
			}
			j++;
		}
		i++;
	}
	whole->image = mlx_new_image(whole->mlx, 10, 10);
	if (!whole->image)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(whole->mlx, whole->image,
			(int)whole->player_x,
			(int)whole->player_y) == -1)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	whole->line = ft_draw_line(whole->mlx, whole->width, whole->height, 0xFF0000FF);
	if (!whole->line)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(whole->mlx, whole->line,
			(int)whole->player_x + 5,
			(int)whole->player_y + 5) == -1)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	init_pa(t_whole *whole)
{
	if (whole->player_dir == 'W')
		whole->pa = 0;
	if (whole->player_dir == 'N')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'E')
		whole->pa = PI;
	if (whole->player_dir == 'S')
		whole->pa = 1.5 * PI;
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
}

int	init_window(t_whole *whole)
{
	whole->mlx = mlx_init(whole->width, whole->height, "CUB3D", false);
	if (!whole->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	init_pa(whole);
	check_textures(whole, 'S');
	if (put_map(whole) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
