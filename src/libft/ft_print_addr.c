/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:41:12 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		puthex(int c, int islower);
static int		ft_get_hex_char(int c);
static size_t	ft_print_hex_addr(unsigned long int nb, int islower);

size_t	ft_print_addr(void *ptr)
{
	unsigned long int	addr;

	addr = (unsigned long int)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_print_hex_addr(addr, 1) + 2);
}

static size_t	ft_print_hex_addr(unsigned long int nb, int islower)
{
	size_t	res;
	size_t	i;
	int		buffer[20];

	res = 0;
	i = 0;
	while (nb > 15)
	{
		buffer[i++] = nb % 16;
		nb /= 16;
		res++;
	}
	buffer[i++] = nb;
	res++;
	while (i > 0)
	{
		puthex(buffer[--i], islower);
	}
	return (res);
}

static void	puthex(int c, int islower)
{
	if (islower)
		ft_putchar(ft_tolower(ft_get_hex_char(c)));
	else
		ft_putchar(ft_get_hex_char(c));
}

static int	ft_get_hex_char(int c)
{
	if (c >= 10 && c < 16)
		return ('A' + (c - 10));
	else
		return (c + 48);
}
