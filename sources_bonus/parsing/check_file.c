/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:20:07 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:30 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static void	check_textures(t_whole *whole)
{
	whole->de_texture = mlx_load_png("./textures/door_texture.png");
	if (whole->de_texture == NULL)
		free_all(whole, 1);
	whole->op_texture = mlx_load_png("./textures/open_texture.png");
	if (whole->op_texture == NULL)
		free_all(whole, 1);
	whole->no_texture = mlx_load_png(whole->cub_t_no);
	if (whole->no_texture == NULL)
		free_all(whole, 1);
	whole->so_texture = mlx_load_png(whole->cub_t_so);
	if (whole->so_texture == NULL)
		free_all(whole, 1);
	whole->we_texture = mlx_load_png(whole->cub_t_we);
	if (whole->we_texture == NULL)
		free_all(whole, 1);
	whole->ea_texture = mlx_load_png(whole->cub_t_ea);
	if (whole->ea_texture == NULL)
		free_all(whole, 1);
}

void	check_name_extension(t_whole *whole)
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

static int	element_or_scenario(t_whole *whole, char *line, int i, int fd)
{
	if (line[i] && (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C'))
	{
		process_element(whole, line, i, fd);
	}
	else
	{
		check_scenario(whole, line, fd);
	}
	return (0);
}

void	check_file(t_whole *whole, int i, int fd, char *line)
{
	whole->number_of_line_before_map = -1;
	fd = open(whole->given_map, O_RDONLY);
	if (fd < 0)
		print_error(whole, "open");
	while (1)
	{
		i = 0;
		line = NULL;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		whole->number_of_line_before_map++;
		while (line[i] && is_white_space(line[i]) && line[i] != '\n')
			i++;
		if (line[i] && line[i] != '\n')
		{
			whole->empty_file = 1;
			element_or_scenario(whole, line, i, fd);
		}
		free(line);
	}
	if (!whole->empty_file)
		print_error(whole, "Empty file");
	close(fd);
	check_textures(whole);
}
