/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/25 15:46:41 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_name_extention(t_whole *whole)
{
	int	i;

	i = 0;
	while (whole->given_map[i] && whole->given_map[i] != '.')
		i++;
	if (whole->given_map[i] == '.' && ft_strncmp(&whole->given_map[i], ".cub",
			ft_strlen(&whole->given_map[i])) == 0)
		return ;
	else
		print_error(whole, "extension");
}

t_whole	*initialization_struct(char *map)
{
	t_whole	*whole;

	whole = ft_calloc(1, sizeof(t_whole));
	if (!whole)
		print_error(whole, "allocation");
	whole->map = ft_calloc(1, sizeof(t_map));
	if (!whole->map)
		print_error(whole, "allocation");
	whole->given_map = map;
	return (whole);
}

void	ft_key(mlx_key_data_t key_data, void *param)
{
	(void)param;
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
		printf("space has been pressed\n");
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_RELEASE)
		printf("space has been released\n");
}

void	ft_mouse(enum mouse_key button, enum action action,
		enum modifier_key mods, void *param)
{
	t_whole	*whole;
	int32_t	mouse_x;
	int32_t	mouse_y;

	whole = (t_whole *)param;
	(void)mods;
	mlx_get_mouse_pos(whole->mlx, &mouse_x, &mouse_y);
	if (action == MLX_PRESS)
	{
		printf("Mouse pressed: Button %d at (%d, %d)\n", button, mouse_x,
			mouse_y);
	}
	else if (action == MLX_RELEASE)
	{
		printf("Mouse released: Button %d at (%d, %d)\n", button, mouse_x,
			mouse_y);
	}
}

// static void	ft_image_clear(mlx_image_t *image, uint32_t color)
// {
// 	uint32_t	y;
// 	uint32_t	x;

// 	if (!image || !image->pixels)
// 		return ;
// 	y = 0;
// 	while (y < image->height)
// 	{
// 		x = 0;
// 		while (x < image->width)
// 		{
// 			((uint32_t *)image->pixels)[y * image->width + x] = color;
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	put_mini_map(void *param)
{
	t_whole	*whole;

	whole = (t_whole *)param;
	// if (!whole->minimap)
	// {
	// 	whole->minimap = ft_draw_rect(whole->mlx, 250, 150, 0xFFFFFF88);
	// 	mlx_image_to_window(whole->mlx, whole->minimap, whole->width + 50, whole->height - 200);
	// }
	// else
	// {
	// 	ft_image_clear(whole->minimap, 0xFFFFFFFF);
	// 	whole->minimap = ft_draw_rect(whole->mlx, 250, 150, 0xFFFFFF88);
	// }
	mlx_delete_image(whole->mlx, whole->minimap);
	whole->minimap = ft_draw_rect(whole->mlx, 250, 150, 0xFFFFFF88);
	mlx_image_to_window(whole->mlx, whole->minimap, whole->width + 50, whole->height - 200);
}
void	set_torch_to_false(t_whole *whole)
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

int	main(int argc, char **argv)
{
	t_whole	*whole;
	char	*line;

	line = NULL;
	whole = NULL;
	if (argc != 2)
		print_error(whole, "no file");
	else
	{
		whole = initialization_struct(&argv[1][0]);
		check_name_extention(whole);
		check_file(whole, 0, 0, line);
		hexconvert(whole, 0, 0, 0);
		check_textures(whole, 'C');
		if (init_window(whole) == 1)
			return (EXIT_FAILURE);
		mlx_loop_hook(whole->mlx, put_player, whole);
		mlx_loop_hook(whole->mlx, ft_hook, whole);
		mlx_loop_hook(whole->mlx, animation, whole);
		// mlx_loop_hook(whole->mlx, put_mini_map, whole);
		mlx_loop(whole->mlx);
		mlx_terminate(whole->mlx);
		free_all(whole, 0);
	}
	return (EXIT_SUCCESS);
}
