/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:57:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 01:19:14 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	check_color(int fd, char *line, char **split_line)
{
	int		i;
	char	**split_val;

	if (split_line[0][0] == '\n')
		return ;
	if (ft_strlen(split_line[0]) == 1)
	{
		split_val = ft_split(split_line[1], ',');
		if (!split_val)
			return (free_parsed(line, fd, split_line), ft_print_err(""
					, "Memory alloc failed"));
		i = 0;
		while (split_val[i])
		{
			if (i == 3)
				split_val[i] = trim_nl(split_val[i]);
			if (!check_int_str(split_val[i]))
				return (free_double(split_val)
					, free_parsed(line, fd, split_line)
					, ft_print_err(split_line[0], " contain non int char\n")
					, exit(1));
			i++;
		}
	}
}
