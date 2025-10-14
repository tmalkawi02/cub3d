/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:37 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 16:05:37 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "raycasters.h"

int		k_release(int keytcode, t_game *game);

int		k_press(int keycode, t_game *game);

void	player_move(t_game *game);

void	player_move_right(t_game *game);

void	player_move_left(t_game *game);

void	player_move_down(t_game *game);

void	player_move_up(t_game *game);

void	player_rotate_left(t_game *game);

void	player_rotate_right(t_game *game);

#endif
