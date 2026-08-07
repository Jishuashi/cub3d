/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:15:30 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/07 20:02:48 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	check_map_format(t_file *file)
{
	size_t				i;
	t_parsed			parsed;
	char				**used_keys;


	parsed.file = file;
	i = 0;
	used_keys = (char **)malloc(sizeof(char *) * 6);
	if (!used_keys)
		return (0);
	used_keys[0] = "";
	while (i < file->len)
	{
		parsed.line = i;
		parsed.split_line = ft_split(file->lines[i], ' ');
		check_key()
		i++;
	}
	return (free(used_keys), 1);
}

void	check_key(t_parsed	*parsed, int *nb_key, char **used_keys)
{
	static const char	*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					idx;
	char				*line;

	line = parsed->file->lines[idx];
	idx = parsed->line;
}
