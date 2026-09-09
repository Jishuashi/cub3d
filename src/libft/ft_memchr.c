/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:58:42 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/17 13:04:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	uc;

	p_s = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*p_s == uc)
			return ((void *)p_s);
		p_s++;
	}
	return (NULL);
}
