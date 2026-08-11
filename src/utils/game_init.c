/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:00 by ldeplace          #+#    #+#             */
/*   Updated: 2026/08/11 12:22:15 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	init_game(t_game *game, char *file)
{
	char	*texture_paths;

	if (!game)
		return (0);
	game->textures = alloc_textures();
	if (!game->textures)
		return (0);
	if (!init_mlx(game))
		return (free_textures_struct(NULL, &game->textures), 0);
	texture_paths = get_texture_paths(file);
	if (!texture_paths)
		return (cleanup_mlx(game), 0);
	if (!init_textures(game->mlx, game->textures, texture_paths))
		return (free(texture_paths), cleanup_mlx(game), 0);
	free(texture_paths);
	return (1);
}
