/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:44:11 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/19 13:50:22 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the integer ’n’ to the specified file
	descriptor.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		nb = n * -1;
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	else
	{
		c = (nb + 48);
		write(fd, &c, 1);
		return ;
	}
	c = (nb % 10 + 48);
	write(fd, &c, 1);
}
