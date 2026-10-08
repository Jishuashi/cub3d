/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:47:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:26:12 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/**
 * Validates the placement of the map section in the file.
 *
 * The function ensures that the map is not found before all required keys are
 * declared and raises an error if the map is placed in the wrong section.
 *
 * @param par Parsing context containing the current split line.
 */
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

/**
 * Validates the value attached to a recognized header key.
 *
 * Every key needs a value. Texture keys (two letters) must have exactly one
 * value, and that value must be a readable file.
 *
 * @param par Parsing context containing the current split line.
 */
void	check_key_value(t_parsed *par)
{
	if (!par->sp_l[1] || par->sp_l[1][0] == '\0')
		ft_print_err(par->sp_l[0], " missing value\n", par);
	if (ft_strlen(par->sp_l[0]) != 2)
		return ;
	if (par->sp_l[2] && par->sp_l[2][0] != '\n')
		ft_print_err(par->sp_l[0], " too many values\n", par);
	if (!check_file(par->sp_l[1]))
		ft_print_err(par->sp_l[1],
			" file not found or no permission\n", par);
}
