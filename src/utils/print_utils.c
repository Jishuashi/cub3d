/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 03:24:26 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:26:12 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/**
 * Prints a formatted error message and exits the program.
 *
 * The function writes the label, the message, and a newline to stderr. If a
 * parsing context is provided, it also frees the partial parsed data before
 * terminating.
 *
 * @param var Error target or label to print.
 * @param msg Message describing the error.
 * @param par Optional parsing context to free before exit.
 */
void	ft_print_err(char *var, char *msg, t_parsed	*par)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (par)
	{
		free_parsed(par);
		free_file(par->file);
		free(par->used_key);
	}
	exit(1);
}
