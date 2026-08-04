/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:56:46 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	puthex(int c, int islower);
static int	ft_get_hex_char(int c);

/**
 * @brief Print int in Hex
 * 
 * @param nb The nb to print in Hex
 * @param lower 1 to print in Lowercase 0 to print in Uppercase
 */
size_t	ft_print_hex(unsigned int nb, int islower)
{
	size_t	res;

	res = 0;
	if (nb > 15)
		res += ft_print_hex(nb / 16, islower);
	else
	{
		puthex(nb, islower);
		res = 1;
		return (res);
	}
	puthex(nb % 16, islower);
	res ++;
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
