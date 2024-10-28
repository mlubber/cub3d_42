/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/28 06:52:04 by link          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_name_extention(t_whole *whole)
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
		free_all(whole, 0);
	}
	return (0);
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
