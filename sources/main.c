/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 12:53:27 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_name_extantion(t_whole *whole)
{
	int	i;

	i = 0;
	while (whole->given_map[i] && whole->given_map[i] != '.')
		i++;
	if (whole->given_map[i] == '.' && ft_strncmp(&whole->given_map[i], \
	".cub", ft_strlen(&whole->given_map[i])) == 0)
		return ;
	else
		print_error(whole, "extension");
}

t_whole	*initialization_struct(char *map)
{
	t_whole		*whole;

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
	t_whole			*whole;
	char			*line;
	// mlx_t			*mlx;

	// mlx = mlx_init(80, 80, "CUB3D", false);
	line = NULL;
	whole = NULL;
	if (argc != 2)
		print_error(whole, "no file");
	else
	{
		whole = initialization_struct(&argv[1][0]);
		check_name_extantion(whole);
		check_file_cub(whole, 0, 0, line);
		free_all(whole, 0);
	}
	return (0);
}
