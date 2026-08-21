/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:57:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/14 19:35:59 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	color_error_exit(t_parsed *parsed, char **sp_val, char *var
	, char *msg)
{
	if (sp_val)
		free_double(sp_val);
	ft_print_err(var, msg, parsed);
}

void	validate_color_components(t_parsed *parsed, char **split_val, char *var)
{
	int		i;
	char	*trimmed;

	trimmed = trim_nl(split_val[2]);
	if (!trimmed)
		color_error_exit(parsed, split_val, var, "Memory alloc failed\n");
	split_val[2] = trimmed;
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

	if (!parsed->sp_l || !parsed->sp_l[0])
		return ;
	if (parsed->sp_l[0][0] == '\n')
		return ;
	if (ft_strlen(parsed->sp_l[0]) == 1)
	{
		parsed->sp_l[1] = reduce_space_val(&parsed->sp_l[1]);
		if (!parsed->sp_l[1] || parsed->sp_l[1][0] == '\0')
			color_error_exit(parsed, NULL, parsed->sp_l[0],
				" missing color values\n");
		split_val = ft_split(parsed->sp_l[1], ',');
		if (!split_val)
			color_error_exit(parsed, NULL, "", "Memory alloc failed\n");
		i = 0;
		while (split_val[i])
			i++;
		if (i != 3)
			color_error_exit(parsed, split_val, parsed->sp_l[0],
				" invalid color format\n");
		validate_color_components(parsed, split_val, parsed->sp_l[0]);
	}
}
