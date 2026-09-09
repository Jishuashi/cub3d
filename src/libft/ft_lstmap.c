/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:10:04 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/12 14:02:37 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through the list ’lst’, applies the
 	function ’f’ to each node’s content, and creates
 	a new list resulting of the successive applications
 	of the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function applied to each
	node’s content.
 * @param del The new list.
	NULL if the allocation fails.
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*res;
	void	*content;

	if (!lst || !del || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (content)
				del(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_node);
		lst = lst->next;
	}
	return (res);
}
