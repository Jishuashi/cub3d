/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:23:46 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char *str)
{
	size_t	res;

	res = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ft_putchar(*str);
		str++;
		res++;
	}
	return (res);
}
