/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:09:11 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/17 17:07:51 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
	copy of ’s1’ with characters from ’set’ removed
	from the beginning and the end.
 * @param s1 The string to be trimmed.
 * @param set The string containing the set of characters
	to be removed.
 * @return The trimmed string.
   NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	srt;
	size_t	end;
	size_t	i;

	srt = 0;
	while (s1[srt] && ft_strchr(set, s1[srt]))
		srt++;
	end = ft_strlen(s1);
	while (end > srt && ft_strrchr(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(*s1) * (end - srt + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (srt < end)
		res[i++] = s1[srt++];
	res[i] = '\0';
	return (res);
}
