/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:54:10 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/16 22:04:15 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LINUX_H
# define MLX_LINUX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width,
		int *height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
		int *endian);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
		int x, int y);
int		mlx_key_hook(void *win_ptr, int (*funct)(int, void *), void *param);
int		mlx_hook(void *win_ptr, int event, int mask, int (*funct)(),
		void *param);
int		mlx_loop_hook(void *mlx_ptr, int (*funct)(void *), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_loop_end(void *mlx_ptr);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_destroy_display(void *mlx_ptr);

#endif
