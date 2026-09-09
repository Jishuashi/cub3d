/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:32:38 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 12:36:12 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
	new string, which is the result of concatenating
	’s1’ and ’s2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 * NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s1)
		return (ft_strdup((char *) s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && *s1)
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	while (i < len && *s2)
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
