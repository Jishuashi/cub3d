/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 01:57:59 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 15:40:23 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static	char	*get_textures(t_file *file, char *key, int i_line);

/**
 * Parses all texture paths and color definitions from the file header.
 *
 * @param file Parsed map file.
 * @param i_line Number of header lines to inspect.
 * @return Allocated assets, or NULL on failure.
 */
t_assets	*parse_textures(t_file *file, int i_line)
{
	t_assets	*res;

	res = (t_assets *)malloc(sizeof(t_assets));
	if (!res)
		return (NULL);
	res->no = NULL;
	res->so = NULL;
	res->ea = NULL;
	res->we = NULL;
	res->floor = NULL;
	res->ceiling = NULL;
	res->no = get_textures(file, "NO", i_line);
	res->so = get_textures(file, "SO", i_line);
	res->ea = get_textures(file, "EA", i_line);
	res->we = get_textures(file, "WE", i_line);
	if (!res->no || !res->so || !res->we || !res->ea)
		return (free_textures(res), NULL);
	res->floor = parse_color(file, i_line, "F");
	res->ceiling = parse_color(file, i_line, "C");
	if (!res->floor || !res->ceiling)
		return (free_textures(res), NULL);
	return (res);
}

/**
 * Finds one texture path in the file header.
 *
 * @param file Parsed map file.
 * @param key Texture directive to find.
 * @param i_line Number of header lines to inspect.
 * @return Allocated texture path, or NULL if it cannot be read.
 */
static	char	*get_textures(t_file *file, char *key, int i_line)
{
	int		i;
	char	**split;
	char	*res;

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
			res = split[1];
			res[ft_strlen(res) - 1] = '\0';
			return (free(split[0]), free(split), res);
		}
		free_double(split);
		i++;
	}
	return (NULL);
}

/**
 * Frees all texture paths, colors and the assets structure.
 *
 * @param assets Assets structure to release; NULL is accepted.
 */
void	free_textures(t_assets *assets)
{
	if (!assets)
		return ;
	if (assets->no)
		free(assets->no);
	if (assets->so)
		free(assets->so);
	if (assets->ea)
		free(assets->ea);
	if (assets->we)
		free(assets->we);
	if (assets->floor)
		free(assets->floor);
	if (assets->ceiling)
		free(assets->ceiling);
	if (assets)
		free(assets);
}
