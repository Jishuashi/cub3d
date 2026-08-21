/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_format_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:15:30 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/21 19:33:53 by hchartie         ###   ########.fr       */
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
			return (free(par.used_key), 0);
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
	while (id[i])
	{
		if (!ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])))
		{
			if (*nb_key >= 6)
				ft_print_err("", "Too many key\n", par);
			while (++e < *nb_key)
				if (!ft_strncmp(par->sp_l[0], u_keys[e], ft_strlen(u_keys[e])))
					ft_print_err(par->sp_l[0], " duplicated key\n", par);
			if (ft_strlen(par->sp_l[0]) == 2)
				if (!check_file(par->sp_l[1]))
					ft_print_err(par->sp_l[1],
						" file not found or no permission\n", par);
			u_keys[*nb_key] = id[i];
			*nb_key += 1;
		}
		i++;
	}
}

int	check_if_map(t_parsed *par, int nb_keys)
{
	int			is_map_line;
	static char	*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			i;

	i = 0;
	is_map_line = 0;
	if (!par->sp_l || !par->sp_l[0] || par->sp_l[0][0] == '\n')
		return (0);
	while (id[i])
	{
		if (ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])) == 0)
			return (0);
		i++;
	}
	if (ft_strchr(" 10", par->sp_l[0][0]))
		is_map_line = 1;
	if (is_map_line && nb_keys < 6)
		err_map_pos(par);
	else if (is_map_line && nb_keys == 6)
		return (1);
	else if (!is_map_line && nb_keys == 6)
		ft_print_err("", "Invalid char in map or invalid key\n", par);
	return (0);
}

void	check_no_map(int nb_keys, int current, t_file *file, char **used)
{
	free(used);
	if (nb_keys == 6 && (size_t)current == (file->len))
	{
		free_file(file);
		ft_print_err("", "No map in file\n", NULL);
	}
	(void)current;
}
