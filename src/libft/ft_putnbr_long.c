/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:04 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/16 15:34:22 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_long(long nb)
{
	char		c;
	size_t		res;

	res = 0;
	if (nb > 9)
		res += ft_putnbr((nb / 10));
	else
	{
		c = (nb + 48);
		write(1, &c, 1);
		res = 1;
		return (res);
	}
	c = (nb % 10 + 48);
	res++;
	write(1, &c, 1);
	return (res);
}
