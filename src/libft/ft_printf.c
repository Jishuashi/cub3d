/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:12:56 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/16 15:35:10 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_print_arg(va_list arg, char type);

int	ft_printf(const char *s, ...)
{
	va_list	params;
	size_t	len;
	size_t	i;
	size_t	res;
	int		count;

	len = ft_strlen(s);
	va_start(params, s);
	i = 0;
	res = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] == '%')
		{
			res += ft_print_arg(params, s[i + 1]);
			i++;
			count += 2;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(params);
	return ((len + res) - count);
}

static	size_t	ft_print_arg(va_list arg, char type)
{
	if (type == 's')
		return (ft_putstr((char *)va_arg(arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr((int)va_arg(arg, int)));
	else if (type == 'c')
		return (ft_putchar((int)va_arg(arg, int)));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'u')
		return (ft_putnbr_usigned((unsigned int)va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex((unsigned int)va_arg(arg, unsigned int), 1));
	else if (type == 'X')
		return (ft_print_hex((unsigned int)va_arg(arg, unsigned int), 0));
	else if (type == 'p')
		return (ft_print_addr((void *)va_arg(arg, void *)));
	else if (type == 'l')
		return (ft_putnbr_long((long)va_arg(arg, long)));
	return (0);
}
