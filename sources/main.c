/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/14 09:34:48 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	just_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strncmp(str, "no file", ft_strlen(str)) == 0)
		ft_putstr_fd("program need a file in format (.cub) to run!\n", 2);
	if (ft_strncmp(str, "allocation", ft_strlen(str)) == 0)
		ft_putstr_fd("Memory allocation denied!\n", 2);
	if (ft_strncmp(str, "extension", ft_strlen(str)) == 0)
		ft_putstr_fd("map extension is not correct!\n", 2);
	exit(EXIT_FAILURE);
}

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
	{
		free(whole->map);
		free(whole);
		just_exit("extension");
	}
}

t_whole	*initialization_struct(char *map)
{
	t_whole		*whole;

	//whole = (t_whole *)malloc(sizeof(t_whole));
	//whole->map = (t_map *)malloc(sizeof(t_map));
	whole = ft_calloc(1, sizeof(t_whole));
	if (!whole)
		just_exit("allocation");
	whole->map = ft_calloc(1, sizeof(t_map));
	if (!whole->map)
	{
		free(whole);
		just_exit("allocation");
	}
	whole->given_map = map;
	return (whole);
}

int	main(int argc, char **argv)
{
	t_whole			*whole;

	if (argc != 2)
		just_exit("no file");
	else
	{
		whole = initialization_struct(&argv[1][0]);
		check_name_extantion(whole);
		if (check_file_cub(whole))
			return (1);
	}
	return (0);
}