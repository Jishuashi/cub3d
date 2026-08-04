/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:30:18 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;
	size_t			res;

	res = 0;
	if (n < 0)
	{
		nb = n * -1;
		write(1, "-", 1);
		res = 1;
	}
	else
		nb = n;
	if (nb > 9)
		res += ft_putnbr((nb / 10));
	else
	{
		c = (nb + 48);
		write(1, &c, 1);
		return (res + 1);
	}
	c = (nb % 10 + 48);
	write(1, &c, 1);
	res++;
	return (res);
}
