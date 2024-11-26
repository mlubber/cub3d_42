/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_animation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 08:19:46 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:42 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static void	torch_to_window(t_whole *whole)
{
	if (mlx_image_to_window(whole->mlx, whole->torch_00,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_01,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_02,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_03,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_04,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_05,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_06,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
	if (mlx_image_to_window(whole->mlx, whole->torch_07,
			whole->width - 600, whole->height / 2) == -1)
		error_close_window(whole, 1);
}

static void	load_torch_2(t_whole *whole)
{
	whole->texture = mlx_load_png("./textures/torch_04.png");
	whole->torch_04 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_05.png");
	whole->torch_05 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_06.png");
	whole->torch_06 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_07.png");
	whole->torch_07 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	if (!whole->torch_04 || !whole->torch_05
		|| !whole->torch_06 || !whole->torch_07)
		error_close_window(whole, 1);
	torch_to_window(whole);
}

void	load_torch(t_whole *whole)
{
	whole->texture = mlx_load_png("./textures/torch_00.png");
	whole->torch_00 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_01.png");
	whole->torch_01 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_02.png");
	whole->torch_02 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	whole->texture = mlx_load_png("./textures/torch_03.png");
	whole->torch_03 = mlx_texture_to_image(whole->mlx, whole->texture);
	mlx_delete_texture(whole->texture);
	if (!whole->torch_00 || !whole->torch_00
		|| !whole->torch_00 || !whole->torch_00)
		error_close_window(whole, 1);
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
