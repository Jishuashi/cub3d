/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:57:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 02:04:39 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	color_error_exit(char *line, int fd, char **split_line, char **split_val, char *var, char *msg)
{
	if (split_val)
		free_double(split_val);
	ft_print_err(var, msg);
	free_parsed(line, fd, split_line);
	exit(1);
}

void	validate_color_components(char *line, int fd, char **split_line, char **split_val, char *var)
{
	int		i;

	split_val[2] = trim_nl(split_val[2]);
	i = 0;
	while (split_val[i])
	{
		if (!check_int_str(split_val[i]))
			color_error_exit(line, fd, split_line, split_val, var, " contain non int char\n");
		i++;
	}
	free_double(split_val);
}

void	check_color(int fd, char *line, char **split_line)
{
	int		i;
	char	**split_val;

	if (split_line[0][0] == '\n')
		return ;
	if (ft_strlen(split_line[0]) == 1)
	{
		if (!split_line[1])
			color_error_exit(line, fd, split_line, NULL, split_line[0], " missing color values\n");
		split_val = ft_split(split_line[1], ',');
		if (!split_val)
			color_error_exit(line, fd, split_line, NULL, "", "Memory alloc failed");
		i = 0;
		while (split_val[i])
			i++;
		if (i != 3)
			color_error_exit(line, fd, split_line, split_val, split_line[0], " invalid color format\n");
		validate_color_components(line, fd, split_line, split_val, split_line[0]);
	}
}
