/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:54:10 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/09 12:54:12 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LINUX_H
# define MLX_LINUX_H

void	*mlx_init(void);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width,
		int *height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
		int *endian);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_destroy_display(void *mlx_ptr);

#endif
