/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 13:55:24 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:07:50 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

void	ft_lst_map_clear(t_map_list **lst)
{
	t_map_list	*temp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	free_char_p_whole(t_whole *whole)
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

void	ft_free_map(t_whole *whole, t_map *map)
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

void	free_texture(t_whole *whole)
{
	if (whole)
	{
		if (whole->ea_texture)
			mlx_delete_texture(whole->ea_texture);
		if (whole->no_texture)
			mlx_delete_texture(whole->no_texture);
		if (whole->we_texture)
			mlx_delete_texture(whole->we_texture);
		if (whole->so_texture)
			mlx_delete_texture(whole->so_texture);
		if (whole->op_texture)
			mlx_delete_texture(whole->op_texture);
		if (whole->de_texture)
			mlx_delete_texture(whole->de_texture);
	}
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
	if (whole && whole->list_clue)
		ft_lst_map_clear(&whole->list_clue);
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
