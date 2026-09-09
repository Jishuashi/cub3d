/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:17:41 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/14 15:41:07 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size == 0)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (i + dest_len < size - 1))
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	dst[i + dest_len] = '\0';
	if (dest_len < size)
		return (src_len + dest_len);
	return (size + src_len);
}
