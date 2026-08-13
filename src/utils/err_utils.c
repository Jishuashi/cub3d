/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:47:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/13 16:43:34 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	err_duplicate(t_parsed	*parsed)
{
	ft_print_err(parsed->sp_l[0], " : Duplicate key\n");
	free_parsed(parsed);
	free_file(parsed->file);
	free(parsed->used_key);
	exit (1);
}

void	err_file(t_parsed	*par)
{
	free_file(par->file);
	ft_print_err(par->sp_l[1], " File not found\n");
	free_parsed(par);
	free(par->used_key);
	exit (1);
}

void	err_map_pos(t_parsed	*par)
{
	static char			*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					i;

	i = 0;
	while (id[i++])
	{
		if (!id[i])
			break ;
		if (!ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])))
			return ;
	}
	i = 0;
	while (par->sp_l[0][i])
	{
		if (par->sp_l[0][i] == ' ' || par->sp_l[0][i] == '1')
			return (free_file(par->file)
				, ft_print_err("", "Map not at EOF or Less than 6 keys\n"),
				free_parsed(par), free(par->used_key), exit (1));
		i++;
	}
}
