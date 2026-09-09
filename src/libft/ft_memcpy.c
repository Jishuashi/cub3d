/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:21:00 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/16 01:51:21 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*res;
	unsigned char		*lsrc;

	res = (unsigned char *)dest;
	lsrc = (unsigned char *)src;
	if (!res && !lsrc)
		return (dest);
	i = 0;
	while (i < n)
	{
		res[i] = lsrc[i];
		i++;
	}
	return (res);
}
