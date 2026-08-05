/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 00:55:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 01:17:24 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*trim_nl(char *str)
{
	char	*temp;

	temp = str;
	str = ft_strtrim(str, "\n");
	free(temp);
	return (str);
}

int	check_int_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] - 48) >= 0 && (str[i] - 48) <= 9)
			return (0);
		i++;
	}
	return (1);
}
