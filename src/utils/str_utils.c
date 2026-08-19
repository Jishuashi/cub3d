/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 00:55:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/19 20:05:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*trim_nl(char *str)
{
	char	*res;

	if (!str)
		return (NULL);
	res = ft_strtrim(str, "\n");
	free (str);
	return (res);
}

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
