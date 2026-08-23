/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 02:52:06 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 15:40:23 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

/**
 * Finds a color directive and joins its space-separated value tokens.
 *
 * @param file Parsed map file.
 * @param i_line Number of header lines to inspect.
 * @param key Color directive to find.
 * @return Allocated color value, or NULL on failure.
 */
static char	*get_color_val(t_file *file, int i_line, char *key)
{
	int		i;
	char	**split;
	char	*val;

	i = 0;
	while (i < i_line)
	{
		split = ft_split(file->lines[i], ' ');
		if (!split)
			return (NULL);
		if (split[0] && !ft_strncmp(split[0], key, ft_strlen(key)))
		{
			if (!split[1])
				return (free_double(split), NULL);
			val = reduce_space_val(&split[1]);
			return (free_double(split), val);
		}
		free_double(split);
		i++;
	}
	return (NULL);
}

/**
 * Allocates and parses one color directive from the map header.
 *
 * @param file Parsed map file.
 * @param i_line Number of header lines to inspect.
 * @param key Color directive to parse.
 * @return Allocated colors, or NULL on failure.
 */
t_colors	*parse_color(t_file *file, int i_line, char *key)
{
	t_colors	*res;

	res = (t_colors *)malloc(sizeof(t_colors));
	if (!res)
		return (NULL);
	res = get_colors(res, file, i_line, key);
	if (!res)
		return (NULL);
	return (res);
}

/**
 * Retrieves a color value and stores its three RGB components.
 *
 * @param colors Color structure to fill.
 * @param file Parsed map file.
 * @param i_line Number of header lines to inspect.
 * @param key Color directive to parse.
 * @return The filled structure, or NULL on failure.
 */
t_colors	*get_colors(t_colors *colors, t_file *file, int i_line, char *key)
{
	char	*val;

	val = get_color_val(file, i_line, key);
	if (!val)
		return (free(colors), NULL);
	colors = set_colors(colors, val);
	if (!colors)
		return (free(val), NULL);
	return (free(val), colors);
}

/**
 * Splits a comma-separated color value into red, green and blue components.
 *
 * @param colors Color structure to fill.
 * @param val Comma-separated RGB value.
 * @return The filled structure, or NULL when the format is invalid.
 */
t_colors	*set_colors(t_colors *colors, char *val)
{
	char	**split;

	if (!colors || !val)
		return (free(colors), NULL);
	if (ft_strlen(val) > 0 && val[ft_strlen(val) - 1] == '\n')
		val[ft_strlen(val) - 1] = '\0';
	split = ft_split(val, ',');
	if (!split)
		return (free(colors), NULL);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_double(split);
		return (free(colors), NULL);
	}
	colors->red = ft_atoi(split[0]);
	colors->green = ft_atoi(split[1]);
	colors->blue = ft_atoi(split[2]);
	return (free_double(split), colors);
}
