/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:07:44 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 07:43:55 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	load_torch(t_whole *whole)
// {
// 	whole->texture = mlx_load_png("./textures/torch_00.png");
// 	whole->torch_00 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_00)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_01.png");
// 	whole->torch_01 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_01)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_02.png");
// 	whole->torch_02 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_02)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_03.png");
// 	whole->torch_03 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_03)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_04.png");
// 	whole->torch_04 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_04)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_05.png");
// 	whole->torch_05 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_05)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_06.png");
// 	whole->torch_06 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_06)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	whole->texture = mlx_load_png("./textures/torch_07.png");
// 	whole->torch_07 = mlx_texture_to_image(whole->mlx, whole->texture);
// 	if (!whole->torch_07)
// 	{
// 		mlx_close_window(whole->mlx);
// 		printf("%s\n", mlx_strerror(mlx_errno));
// 		return ;
// 	}
// 	mlx_delete_texture(whole->texture);
// 	mlx_image_to_window(whole->mlx, whole->torch_00, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_01, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_02, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_03, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_04, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_05, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_06, 3400, 300);
// 	mlx_image_to_window(whole->mlx, whole->torch_07, 3400, 300);
// }

int	put_map(t_whole *whole)
{
	int	i;
	int	j;

	whole->wall = ft_draw_rect(whole->mlx, TILE, TILE, 0xFFFFFFFF);
	if (!whole->wall)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	whole->floor = ft_draw_rect(whole->mlx, TILE, TILE, 0x000000FF);
	if (!whole->floor)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	i = 0;
	whole->k = 0;
	whole->l = 0;
	while (i < whole->rows)
	{
		j = 0;
		while (j < whole->column)
		{
			if (whole->map->tiles[i][j].symbol == '1')
			{
				if (mlx_image_to_window(whole->mlx, whole->wall, j * TILE, i * TILE) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
				whole->k++;
			}
			else if (whole->map->tiles[i][j].symbol == '0' || whole->map->tiles[i][j].symbol == ' ')
			{
				if (mlx_image_to_window(whole->mlx, whole->floor, j * TILE, i * TILE) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
				whole->l++;
			}
			else
			{
				if (mlx_image_to_window(whole->mlx, whole->floor, j * TILE, i * TILE) == -1)
				{
					mlx_close_window(whole->mlx);
					printf("%s\n", mlx_strerror(mlx_errno));
					return (EXIT_FAILURE);
				}
				whole->l++;
			}
			j++;
		}
		i++;
	}
	whole->ceiling = ft_draw_rect(whole->mlx, 1920, whole->height / 2, whole->c_hex);
	if (!whole->ceiling)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(whole->mlx, whole->ceiling, whole->width, 0) == -1)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	whole->ground = ft_draw_rect(whole->mlx, 1920, whole->height / 2, whole->g_hex);
	if (!whole->ground)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(whole->mlx, whole->ground, whole->width, whole->height / 2) == -1)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	whole->image = mlx_new_image(whole->mlx, 10, 10);
	if (!whole->image)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(whole->mlx, whole->image,
			(int)whole->player_x - 5,
			(int)whole->player_y - 5) == -1)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	load_torch(whole);
	// whole->texture = mlx_load_png("./textures/torch_00.png");
	// whole->torch_00 = mlx_texture_to_image(whole->mlx, whole->texture);
	// // whole->torch = ft_draw_rect(whole->mlx, 1920, whole->height / 2, 0x00FF00FF);
	// if (!whole->torch_00)
	// {
	// 	mlx_close_window(whole->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// mlx_delete_texture(whole->texture);
	// whole->minimap = ft_draw_rect(whole->mlx, 250, 150, 0xFFFFFF88);
	// if (!whole->minimap)
	// {
	// 	mlx_close_window(whole->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(whole->mlx, whole->minimap, whole->width + 50, whole->height - 200) == -1)
	// {
	// 	mlx_close_window(whole->mlx);
	// 	printf("%s\n", mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	return (EXIT_SUCCESS);
}

void	init_pa(t_whole *whole)
{
	if (whole->player_dir == 'E')
		whole->pa = 0;
	if (whole->player_dir == 'S')
		whole->pa = 0.5 * PI;
	if (whole->player_dir == 'W')
		whole->pa = PI;
	if (whole->player_dir == 'N')
		whole->pa = 1.5 * PI;
	whole->pdx = cos(whole->pa) * SPEED;
	whole->pdy = sin(whole->pa) * SPEED;
	whole->delta_spin = 0;
	whole->last_mouse_x = 0;
}

int	init_window(t_whole *whole)
{
	whole->mlx = mlx_init(whole->width + 1920, whole->height, "CUB3D", false);
	if (!whole->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	init_pa(whole);
	check_textures(whole, 'S');
	if (put_map(whole) == 1)
		return (EXIT_FAILURE);
	whole->ray = ft_calloc(1, sizeof(t_ray));
	if (!whole->ray)
		print_error(whole, "allocation");
	raycasting(whole);
	return (EXIT_SUCCESS);
}
