/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:57:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 15:40:42 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * Frees color parsing resources and exits with a formatted error.
 *
 * @param parsed Parsing context to clean before exit.
 * @param sp_val Split color values to free.
 * @param var Name of the invalid color field.
 * @param msg Error message to print.
 */
static void	color_error_exit(t_parsed *parsed, char **sp_val, char *var
	, char *msg)
{
	if (sp_val)
		free_double(sp_val);
	ft_print_err(var, msg, parsed);
}

/**
 * Validates the values extracted from a color definition.
 *
 * Every component must be a numeric string. If a non-digit is found, the
 * function aborts with the appropriate parser error.
 *
 * @param parsed Current parsing state.
 * @param split_val String array containing the RGB components.
 * @param var Name of the color field being validated.
 */
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
			color_error_exit(parsed, split_val, var,
				" contains a non-numeric or negative value\n");
		i++;
	}
	free_double(split_val);
}

/**
 * Parses and validates a color line declared in the map header.
 *
 * The function expects a value formatted as three comma-separated integers, and
 * validates the numeric content before freeing temporary split data.
 *
 * @param parsed Parsing context containing the current line.
 */
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

/**
 * Checks that every parsed RGB component is within the allowed range.
 *
 * @param assets Assets containing the floor and ceiling colors.
 * @return 1 when all components are at most 255, otherwise 0.
 */
int	check_colors_value(t_assets *assets)
{
	if (assets->floor->red > 255 || assets->floor->green > 255
		|| assets->floor->blue > 255)
		return (0);
	if (assets->ceiling->red > 255 || assets->ceiling->green > 255
		|| assets->ceiling->blue > 255)
		return (0);
	return (1);
}
