/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_animation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 07:42:26 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/26 07:50:08 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	load_torch_2(t_whole *whole)
{
	whole->texture = mlx_load_png("./textures/torch_04.png");
	whole->torch_04 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_04)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_05.png");
	whole->torch_05 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_05)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_06.png");
	whole->torch_06 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_06)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_07.png");
	whole->torch_07 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_07)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	mlx_image_to_window(whole->mlx, whole->torch_04, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_05, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_06, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_07, 3400, 300);
}

void	load_torch(t_whole *whole)
{
	whole->texture = mlx_load_png("./textures/torch_00.png");
	whole->torch_00 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_00)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_01.png");
	whole->torch_01 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_01)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_02.png");
	whole->torch_02 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_02)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_03.png");
	whole->torch_03 = mlx_texture_to_image(whole->mlx, whole->texture);
	if (!whole->torch_03)
	{
		mlx_close_window(whole->mlx);
		printf("%s\n", mlx_strerror(mlx_errno));
		return ;
	}
	mlx_delete_texture(whole->texture);
	mlx_image_to_window(whole->mlx, whole->torch_00, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_01, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_02, 3400, 300);
	mlx_image_to_window(whole->mlx, whole->torch_03, 3400, 300);
	load_torch_2(whole);
}

static void	set_torch_to_false(t_whole *whole)
{
	whole->torch_00->enabled = false;
	whole->torch_01->enabled = false;
	whole->torch_02->enabled = false;
	whole->torch_03->enabled = false;
	whole->torch_04->enabled = false;
	whole->torch_05->enabled = false;
	whole->torch_06->enabled = false;
	whole->torch_07->enabled = false;
}

void	animation(void *param)
{
	struct timeval	tv;
	t_whole			*whole;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_usec / 1000;
	whole = (t_whole *)param;
	set_torch_to_false(whole);
	if (milliseconds < 125)
		whole->torch_00->enabled = true;
	else if (milliseconds < 250)
		whole->torch_01->enabled = true;
	else if (milliseconds < 375)
		whole->torch_02->enabled = true;
	else if (milliseconds < 500)
		whole->torch_03->enabled = true;
	else if (milliseconds < 625)
		whole->torch_04->enabled = true;
	else if (milliseconds < 750)
		whole->torch_05->enabled = true;
	else if (milliseconds < 875)
		whole->torch_06->enabled = true;
	else if (milliseconds < 1000)
		whole->torch_07->enabled = true;
}
