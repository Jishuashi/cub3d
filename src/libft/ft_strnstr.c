/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:58:54 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/17 14:12:41 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	find_len;

	if (to_find[0] == '\0')
		return ((char *)str);
	find_len = ft_strlen(to_find);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (i + find_len > len)
			return (NULL);
		j = 0;
		while (j < find_len && str[i + j] == to_find[j])
			j++;
		if (j == find_len)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
