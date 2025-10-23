/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:33 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 11:10:33 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters_bonus.h"

void	player_move_bonus(t_game *game)
{
	if (game->play->kright)
		player_move_right(game);
	else if (game->play->kleft)
		player_move_left(game);
	else if (game->play->kup)
		player_move_up(game);
	else if (game->play->kdown)
		player_move_down(game);
	if (game->play->rrotate)
		player_rotate_right(game);
	else if (game->play->lrotate)
		player_rotate_left(game);
	return ;
}
