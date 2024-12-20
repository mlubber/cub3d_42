/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 13:55:24 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/12 13:51:53 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_char_p_whole(t_whole *whole)
{
	if (!whole)
		return ;
	if (whole->cub_color_c)
		free(whole->cub_color_c);
	if (whole->cub_color_f)
		free(whole->cub_color_f);
	if (whole->cub_t_ea)
		free(whole->cub_t_ea);
	if (whole->cub_t_no)
		free(whole->cub_t_no);
	if (whole->cub_t_so)
		free(whole->cub_t_so);
	if (whole->cub_t_we)
		free(whole->cub_t_we);
}

static void	ft_free_map(t_whole *whole, t_map *map)
{
	int	i;

	i = 0;
	if (whole && whole->map && whole->map->tiles)
	{
		while (i < whole->rows)
		{
			free(map->tiles[i]);
			i++;
		}
		free(map->tiles);
	}
}

void	print_error_with_line(t_whole *whole, char *text, char *line)
{
	char	*to_print;

	to_print = NULL;
	if (!line)
		to_print = text;
	else
	{
		to_print = ft_strjoin(text, line);
		if (!to_print && errno == 12)
			print_error(whole, "allocation");
	}
	printf("%s", to_print);
	free(to_print);
	free(line);
	free_all(whole, 1);
}

static void	free_texture(t_whole *whole)
{
	if (whole->ea_texture)
		mlx_delete_texture(whole->ea_texture);
	if (whole->no_texture)
		mlx_delete_texture(whole->no_texture);
	if (whole->we_texture)
		mlx_delete_texture(whole->we_texture);
	if (whole->so_texture)
		mlx_delete_texture(whole->so_texture);
}

void	free_all(t_whole *whole, int exit_code)
{
	if (whole)
	{
		free_char_p_whole(whole);
		free_texture(whole);
	}
	if (whole && whole->map)
		ft_free_map(whole, whole->map);
	if (whole && whole->map)
		free(whole->map);
	if (whole && whole->ray)
		free(whole->ray);
	if (whole)
		free(whole);
	if (exit_code)
		exit(1);
	exit(0);
}
