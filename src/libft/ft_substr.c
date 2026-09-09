/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:25:16 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/17 16:11:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 	Allocates memory (using malloc(3)) and returns a
	substring from the string ’s’.
	The substring starts at index ’start’ and has a
	maximum length of ’len
 * @param s The original string from which to create the substring.
 * @param start The starting index of the substring within ’s’
 * @param sublen The maximum length of the substring
 * @return The substring.
	NULL if the allocation fails
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	sublen;
	char			*substr;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	sublen = ft_strlen(s + start);
	if (sublen < len)
		len = sublen;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
