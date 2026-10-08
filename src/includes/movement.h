/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:59:30 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/17 10:16:16 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
# include "cube3d.h"

void	move_player(t_game *data, double move_x, double move_y);
void	rotate_player(t_game *data, double angle);
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
int		game_loop(void *param);
void	update_player(t_game *data);

#endif
