/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:16:08 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 11:16:08 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "raycasters.h"

void	player_move_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->play->pos_x + game->play->dir_y * MOVE_SPEED;
	new_y = game->play->pos_y - game->play->dir_x * MOVE_SPEED;
	if (game->map[(int)new_y][(int)game->play->pos_x] == 0)
		game->play->pos_y = new_y;
	if (game->map[(int)game->play->pos_y][(int)new_x])
		game->play->pos_x = new_x;
}
