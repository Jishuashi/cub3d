/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:38:45 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 16:09:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_point	*get_point(int x, int y)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (!res)
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = set_point(res, x, y);
	return (res);
}

t_point	*set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
	return (point);
}
