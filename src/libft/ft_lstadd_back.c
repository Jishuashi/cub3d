/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:26:01 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/12 14:01:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param lst The address of a pointer to the first node of
	a list
 * @param new The address of a pointer to the node to be
	added
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (!node)
		*lst = new;
	else
		node->next = new;
}
