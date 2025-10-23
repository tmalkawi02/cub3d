/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:06:55 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:06:55 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTERS_BONUS_H
# define RAYCASTERS_BONUS_H

# ifndef BONUS_CUB3D
#  define BONUS_CUB3D 0
# endif

# include "raycasters.h"

int		render_loop_bonus(t_game *game);

void	render_map_bonus(t_game *game, t_minimap *minimap);

void	player_move_bonus(t_game *game);

void	player_move_right_bonus(t_game *game);

void	player_move_left_bonus(t_game *game);

void	player_move_down_bonus(t_game *game);

void	player_move_up_bonus(t_game *game);

void	player_rotate_left_bonus(t_game *game);

void	player_rotate_right_bonus(t_game *game);

#endif
