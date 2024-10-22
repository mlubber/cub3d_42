/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/22 06:52:50 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->image->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->image->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->image->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->image->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_exit("arg");
	else
	{
		data = malloc_struct(&argv[1][0]);
		check_extension(data);
		check_file(data);
		init_struct(data);
		if (init_window(data) == 1)
			return (EXIT_FAILURE);
		mlx_loop_hook(data->mlx, ft_randomize, data);
		mlx_loop_hook(data->mlx, ft_hook, data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
		free(data);
	}
	return (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	printf("\nCUB3D Controls:\n");
// 	printf("\nW: move forward\n");
// 	printf("S: move backward\n");
// 	printf("A: strafe left\n");
// 	printf("D: strafe right\n");
// 	printf("<: rotate left\n");
// 	printf(">: rotate right\n");
// 	printf("sin(0.5) = %f\n", sin(0.5));
//     printf("cos(0.5) = %f\n", cos(0.5));
//     printf("tan(0.5) = %f\n", tan(0.5));
//     printf("asin(0.5) = %f\n", asin(0.5));
//     printf("acos(0.5) = %f\n", acos(0.5));
//     printf("atan(1.0) = %f\n", atan(1.0));
//     printf("atan2(1.0, 1.0) = %f\n", atan2(1.0, 1.0));
// 	printf("abbas was here\n");
// 	return (0);
// }
