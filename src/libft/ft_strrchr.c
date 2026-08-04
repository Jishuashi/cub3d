/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:11:04 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/16 16:32:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (c == 0)
		return ((char *)(str + i));
	while (1)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
