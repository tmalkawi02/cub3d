/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:35:39 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 11:35:39 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "helpers.h"
#include "raycasters.h"

void	player_move_down(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->play->pos_x - game->play->dir_x * MOVE_SPEED;
	new_y = game->play->pos_y - game->play->dir_y * MOVE_SPEED;
	if (is_wall(game, (int)game->play->pos_x, (int)new_y))
		game->play->pos_y = new_y;
	if (is_wall(game, (int)new_x, (int)game->play->pos_y))
		game->play->pos_x = new_x;
}
