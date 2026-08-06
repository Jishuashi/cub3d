/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:57:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 17:35:08 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	color_error_exit(t_parsed *parsed, char **sp_val, char *var
	, char *msg)
{
	if (sp_val)
		free_double(sp_val);
	ft_print_err(var, msg);
	free_parsed(parsed);
	exit(1);
}

void	validate_color_components(t_parsed *parsed, char **split_val, char *var)
{
	int		i;

	split_val[2] = trim_nl(split_val[2]);
	i = 0;
	while (split_val[i])
	{
		if (!check_int_str(split_val[i]))
			color_error_exit(parsed, split_val, var, " contain non int char\n");
		i++;
	}
	free_double(split_val);
}

void	check_color(t_parsed *parsed)
{
	int		i;
	char	**split_val;

	if (parsed->split_line[0][0] == '\n')
		return ;
	if (ft_strlen(parsed->split_line[0]) == 1)
	{
		if (!parsed->split_line[1])
			color_error_exit(parsed, NULL, parsed->split_line[0],
				" missing color values\n");
		split_val = ft_split(parsed->split_line[1], ',');
		if (!split_val)
			color_error_exit(parsed, NULL, "", "Memory alloc failed\n");
		i = 0;
		while (split_val[i])
			i++;
		if (i != 3)
			color_error_exit(parsed, split_val, parsed->split_line[0],
				" invalid color format\n");
		validate_color_components(parsed, split_val, parsed->split_line[0]);
	}
}
