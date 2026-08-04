/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:22:31 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/18 16:19:24 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_char(int nb);
static char		*ft_put_int_in_str(char *str, unsigned int nb, size_t len);

/**
 * @brief Allocates memory (using malloc(3)) and returns
 *	a string representing the integer received as an
 *	argument. Negative numbers must be handled.
 * 
 * @param n The integer to convert.
 * @return The string representing the integer.
 *	NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char			*str;
	size_t			len_char;
	unsigned int	nb;

	str = NULL;
	len_char = ft_count_char(n);
	str = (char *)malloc(sizeof(char) * (len_char + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb = (n * -1);
		str[0] = '-';
	}
	else
		nb = n;
	str = ft_put_int_in_str(str, nb, len_char);
	return (str);
}

static size_t	ft_count_char(int nb)
{
	size_t			res;
	unsigned int	n;

	res = 0;
	if (nb < 0)
	{
		res = 1;
		n = nb * -1;
	}
	else
		n = nb;
	while (n > 9)
	{
		n /= 10;
		res++;
	}
	return (res + 1);
}

static char	*ft_put_int_in_str(char *str, unsigned int nb, size_t len)
{
	unsigned int	n;
	size_t			i;
	size_t			min_idx;

	n = nb;
	if (len != ft_count_char(nb) || n == 2147483648)
		min_idx = 1;
	else
		min_idx = 0;
	i = (len - 1);
	while (i > min_idx)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	str[min_idx] = n + 48;
	str[len] = '\0';
	return (str);
}
