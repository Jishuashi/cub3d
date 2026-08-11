/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:23:12 by louka             #+#    #+#             */
/*   Updated: 2026/08/11 12:08:44 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	cleanup_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures_struct(game->mlx, &game->textures);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	init_mlx(t_game *game)
{
	if (!game)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (write(2, "Error\nFailed to init MLX\n", 25), 0);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		return (cleanup_mlx(game), write(2, "Error\nWindow failed\n", 20), 0);
	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame.img)
		return (cleanup_mlx(game), write(2, "Error\nImage failed\n", 19), 0);
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_per_pixel,
			&game->frame.line_length,
			&game->frame.endian);
	if (!game->frame.addr)
		return (cleanup_mlx(game), write(2, "Error\nAddr failed\n", 18), 0);
	game->frame.width = WIN_WIDTH;
	game->frame.height = WIN_HEIGHT;
	return (1);
}
