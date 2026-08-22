/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 01:57:59 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 02:38:13 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static	char	*get_textures(t_file *file, char *key, int i_line);

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
	res->no = get_textures(file, "NO", i_line);
	if (!res->no)
		return (free_textures(res), NULL);
	res->so = get_textures(file, "SO", i_line);
	if (!res->so)
		return (free_textures(res), NULL);
	res->ea = get_textures(file, "EA", i_line);
	if (!res->ea)
		return (free_textures(res), NULL);
	res->we = get_textures(file, "WE", i_line);
	if (!res->we)
		return (free_textures(res), NULL);
	return (res);
}

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
		if (!ft_strncmp(split[0], key, ft_strlen(key)))
		{
			res = split[1];
			res[ft_strlen(res) - 1] = '\0';
			return (free(split[0]), free(split), res);
		}
		free_double(split);
		i++;
	}
	return (NULL);
}

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
	if (assets)
		free(assets);
}
