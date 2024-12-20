/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/12 14:24:13 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		check_name_extension(whole);
		check_file(whole, 0, 0, line);
		hexconvert(whole, 0, 0, 0);
		if (init_window(whole) == 1)
			free_all(whole, 1);
		mlx_loop_hook(whole->mlx, ft_hook, whole);
		mlx_loop(whole->mlx);
		mlx_terminate(whole->mlx);
		free_all(whole, 0);
	}
	return (EXIT_SUCCESS);
}
