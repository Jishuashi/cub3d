/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:47:16 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/10 00:30:40 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	err_duplicate(t_parsed	*parsed)
{
	ft_print_err(parsed->sp_l[0], " : Duplicate key\n");
	free_parsed(parsed);
	free_file(parsed->file);
	free(parsed->used_key);
	exit (1);
}
