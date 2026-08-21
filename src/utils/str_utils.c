/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 00:55:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:26:12 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/**
 * Removes trailing newline characters from a string.
 *
 * The function trims the '\n' characters from the input string and frees the
 * original buffer once the cleaned copy is created.
 *
 * @param str String to trim.
 * @return Newly allocated trimmed string, or NULL on failure.
 */
char	*trim_nl(char *str)
{
	char	*res;

	if (!str)
		return (NULL);
	res = ft_strtrim(str, "\n");
	if (!res)
		return (NULL);
	free(str);
	return (res);
}

/**
 * Verifies whether a string contains only digits.
 *
 * @param str String to validate.
 * @return 1 if all characters are digits, 0 otherwise.
 */
int	check_int_str(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	free_src(char **src, size_t i)
{
	while (src[i])
	{
		free(src[i]);
		src[i] = NULL;
		i++;
	}
}

/**
 * Concatenates all non-empty strings from a split array into one string.
 *
 * The resulting string is built from the provided tokens and the source entries
 * are freed afterward.
 *
 * @param src NULL-terminated array of strings to merge.
 * @return A concatenated string, or NULL on allocation failure.
 */
char	*reduce_space_val(char **src)
{
	char	*temp;
	char	*res;
	size_t	i;

	if (!src || !*src)
		return (NULL);
	res = ft_strdup("");
	if (!res)
		return (free_src(src, 0), NULL);
	i = 0;
	while (src[i])
	{
		temp = res;
		res = ft_strjoin(temp, src[i]);
		free(temp);
		if (!res)
			return (free_src(src, i), NULL);
		free(src[i]);
		src[i] = NULL;
		i++;
	}
	return (res);
}
