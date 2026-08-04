/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:14:27 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/19 01:42:19 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	char		*res;
	size_t		m_len;

	m_len = (len * size);
	if (m_len < size && m_len < len)
		return (NULL);
	if (len == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (NULL);
	res = malloc(m_len);
	if (!res)
		return (NULL);
	ft_bzero(res, m_len);
	return (res);
}
