/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:10:06 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/12 14:02:05 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and all its
	successors, using the function ’del’ and free(3).
	Finally, set the pointer to the list to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
	the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
	free(*lst);
	lst = NULL;
}
