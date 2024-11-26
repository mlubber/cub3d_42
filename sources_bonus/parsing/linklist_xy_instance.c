/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linklist_xy_instance.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:55:45 by adakheel      #+#    #+#                 */
/*   Updated: 2024/11/26 12:08:13 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d.h"

static t_map_list	*ft_lst_map_last(t_map_list *lst)
{
	while (lst)
	{
		if (lst && lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static void	ft_lst_map_add_back(t_map_list **lst,
t_map_list *new, t_whole *whole)
{
	t_map_list	*temp;

	if (lst && new)
	{
		if (*lst)
		{
			temp = ft_lst_map_last(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
	else
		print_error(whole, "allocation");
}

static t_map_list	*ft_lst_map_new(int x, int y, int instance)
{
	t_map_list	*new;

	new = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->instance = instance;
	new->open = false;
	new->next = NULL;
	return (new);
}

void	make_node(int x, int y, int instance, t_whole *whole)
{
	if (!whole->list_clue)
	{
		whole->list_clue = ft_lst_map_new(x, y, instance);
		if (!whole->list_clue)
			print_error(whole, "allocation");
	}
	else
	{
		ft_lst_map_add_back(&whole->list_clue,
			ft_lst_map_new(x, y, instance), whole);
	}
}
