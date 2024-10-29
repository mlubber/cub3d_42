/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/29 11:21:14 by mlubbers      ########   odam.nl         */
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

int	main(int argc, char **argv)
{
	t_whole	*whole;
	char 	*line;

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
		mlx_loop(whole->mlx);
		mlx_terminate(whole->mlx);
		free_all(whole, 0);
	}
	return (EXIT_SUCCESS);
}
