/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:57:52 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/12 14:02:15 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through the list ’lst’ and applies the
	function ’f’ to the content of each node.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function to apply to each
	node’s content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
