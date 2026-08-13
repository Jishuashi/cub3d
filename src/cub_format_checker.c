/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_format_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:15:30 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/13 19:31:59 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	check_map_format(t_file *file, int *map_line)
{
	size_t				i;
	t_parsed			par;
	int					nb_keys;

	par.file = file;
	par.used_key = (char **)ft_calloc(sizeof(char *), 7);
	if (!par.used_key)
		return (0);
	nb_keys = 0;
	i = 0;
	while (i < file->len)
	{
		par.sp_l = ft_split(file->lines[i], ' ');
		if (!par.sp_l)
			return (free(par.used_key), free_file(file), 0);
		if (par.sp_l[0] && par.sp_l[1])
			par.sp_l[1] = trim_nl(par.sp_l[1]);
		check_key(&par, &nb_keys, par.used_key);
		if (check_if_map(&par, nb_keys) == 1)
			return (free_parsed(&par), free(par.used_key), *map_line = i, 1);
		check_color(&par);
		free_parsed(&par);
		i++;
	}
	return (check_no_map(nb_keys, i, file, par.used_key), 1);
}

void	check_key(t_parsed	*par, int *nb_key, char **u_keys)
{
	static char			*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					i;
	int					e;

	i = 0;
	e = -1;
	if (*nb_key < 6)
		err_map_pos(par);
	while (id[i])
	{
		if (*nb_key < 6 && !ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])))
		{
			while (++e < *nb_key)
				if (!ft_strncmp(par->sp_l[0], u_keys[e], ft_strlen(u_keys[e])))
					err_duplicate(par);
			if (ft_strlen(par->sp_l[0]) == 2)
				if (!check_file(par->sp_l[1]))
					err_file(par);
			u_keys[*nb_key] = id[i];
			*nb_key += 1;
		}
		i++;
	}
}

int	check_if_map(t_parsed *par, int nb_keys)
{
	static char			*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					i;

	if (!par->sp_l)
		return (0);
	if (par->sp_l[0] && par->sp_l[0][0] == '1' && nb_keys == 6)
		return (1);
	if (nb_keys == 6 && par->sp_l[0] && par->sp_l[0][0] != '\n')
	{
		i = 0;
		while (id[i])
		{
			if (!ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i]))
				&& ft_strlen(par->sp_l[0]) == ft_strlen(id[i]))
				return (0);
			else
				i++;
		}
		ft_print_err("", " Invalid char in map or invalid key\n");
		return (free(par->used_key), free_file(par->file)
			, free_parsed(par), exit(1), 1);
	}
	return (0);
}

void	check_no_map(int nb_keys, int current, t_file *file, char **used)
{
	if (nb_keys == 6 && (size_t)current == (file->len))
	{
		ft_print_err("", " No map in file\n");
		exit(1);
	}
	free(used);
	(void)current;
}
