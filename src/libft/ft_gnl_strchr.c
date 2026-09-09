/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:01:54 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:02:34 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strchr(const char *str, int c)
{
	if (c > 255)
		c %= 256;
	if (!str && c != '\0')
		return (NULL);
	while (*str)
	{
		if (*str == c)
			break ;
		str++;
	}
	if (*str == '\0' && c == '\0')
		return ((char *)str);
	if (*str == '\0')
		return (NULL);
	return ((char *)str);
}
