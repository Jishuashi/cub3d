/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:00:48 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/12 14:03:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in the list.
 * 
 * @param lst The beginning of the list.
 * @return The length of the list 
 */
int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*node;

	res = 0;
	node = lst;
	if (!lst)
		return (0);
	while (node->next != NULL)
	{
		res++;
		node = node->next;
	}
	res++;
	return (res);
}
