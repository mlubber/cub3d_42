/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linklist_xy_instance.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 14:55:45 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/21 10:03:55 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


// int	ft_lst_map_size(t_map_list *lst)
// {
// 	int		total_node;

// 	total_node = 0;
// 	while (lst)
// 	{
// 		total_node++;
// 		lst = lst->next;
// 	}
// 	return (total_node);
// }

// t_map_list	*ft_lst_map_last(t_map_list *lst)
// {
// 	while (lst)
// 	{
// 		if (lst && lst->next == NULL)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// void	ft_lst_map_add_back(t_map_list **lst, t_map_list *new, t_whole *whole)
// {
// 	t_map_list	*temp;

// 	if (lst && new)
// 	{
// 		if (*lst)
// 		{
// 			temp = ft_lst_map_last(*lst);
// 			temp->next = new;
// 		}
// 		else
// 			*lst = new;
// 	}
// 	else
// 		ft_free_map_list_exit(whole, "allocation");
// }

// t_map_list	*ft_lst_map_new(int x, int y, int instance)
// {
// 	t_map_list	*new;

// 	new = (t_map_list *)malloc(sizeof(t_map_list));
// 	if (!new)
// 		return (NULL);
// 	new->x = x;
// 	new->y = y;
// 	new->instance = instance;
// 	new->next = NULL;

// 	return (new);
// }

// void	make_node(int x, int y, int instance, t_whole *whole)
// {
// 	if (!whole->list_clue)
// 	{
// 		whole->list_clue = ft_lst_map_new(x, y, instance);
// 		if (!whole->list_clue)
// 			ft_free_map_exit(whole, "allocation");
// 	}
// 	else
// 	{
// 		ft_lst_map_add_back(&whole->list_clue, ft_lst_map_new(x, y, instance), whole);
// 	}
// }
