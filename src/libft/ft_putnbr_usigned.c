/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_usigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:48:31 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_usigned(unsigned int nb)
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
