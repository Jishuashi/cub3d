/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:15:30 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/10 01:27:40 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	check_map_format(t_file *file, int *map_line)
{
	size_t				i;
	t_parsed			parsed;
	int					nb_keys;

	parsed.file = file;
	parsed.used_key = (char **)ft_calloc(sizeof(char *), 7);
	if (!parsed.used_key)
		return (0);
	nb_keys = 0;
	i = 0;
	while (i < file->len)
	{
		parsed.sp_l = ft_split(file->lines[i], ' ');
		if (!parsed.sp_l)
			return (free(parsed.used_key), free_file(file), 0);
		if (parsed.sp_l[0] && parsed.sp_l[1])
			parsed.sp_l[1] = trim_nl(parsed.sp_l[1]);
		check_key(&parsed, &nb_keys, parsed.used_key);
		check_color(&parsed);
		free_parsed(&parsed);
		if (check_if_map(&parsed, nb_keys))
			return ((*map_line = i), 1);
		i++;
	}
	return (free(parsed.used_key), 1);
}

void	check_key(t_parsed	*par, int *nb_key, char **u_keys)
{
	static char			*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					i;
	int					e;

	i = 0;
	e = -1;
	while (id[i])
	{
		if (*nb_key < 6 && !ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])))
		{
			while (++e < *nb_key)
				if (!ft_strncmp(par->sp_l[0], u_keys[e], ft_strlen(u_keys[e])))
					err_duplicate(par);
			if (ft_strlen(par->sp_l[0]) == 2)
				if (!check_file(par->sp_l[1]))
					return (free_file(par->file)
						, ft_print_err(par->sp_l[1], " File not found\n")
						, free_parsed(par), free(par->used_key), exit (1));
			u_keys[*nb_key] = id[i];
			*nb_key += 1;
		}
		i++;
	}
}

int	check_if_map(t_parsed *parsed, int nb_keys)
{
	if (parsed->sp_l[0] && parsed->sp_l[0][0] == '1'
		&& nb_keys == 6)
		return (1);
	else if (parsed->sp_l[0] && parsed->sp_l[0][0] == '1'
		&& nb_keys != 6)
	{
		ft_print_err("", "Too much or less key\n");
		free(parsed->used_key);
		free_parsed(parsed);
		exit(1);
	}
	return (0);
}
