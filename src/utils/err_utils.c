/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:47:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/14 19:29:17 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	err_map_pos(t_parsed	*par)
{
	static char			*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int					i;

	i = 0;
	if (!par->sp_l || !par->sp_l[0])
		return ;
	while (id[i])
	{
		if (!ft_strncmp(par->sp_l[0], id[i], ft_strlen(id[i])))
			return ;
		i++;
	}
	i = 0;
	while (par->sp_l[0][i])
	{
		if (par->sp_l[0][i] == ' ' || par->sp_l[0][i] == '1')
			ft_print_err("", "Map not at EOF or Less than 6 keys\n", par);
		i++;
	}
}
