/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:12:29 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 12:12:29 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "raycasters.h"
#include <math.h>

void	player_rotate_right(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = game->play->dir_x;
	old_plane_x = game->play->plane_x;
	game->play->dir_x = game->play->dir_x * cos(ROT_SPEED)
		- game->play->dir_y * sin(ROT_SPEED);
	game->play->dir_y = old_dir_x * sin(ROT_SPEED)
		+ game->play->dir_y * cos(ROT_SPEED);
	game->play->plane_x = game->play->plane_x * cos(ROT_SPEED)
		- game->play->plane_y * sin(ROT_SPEED);
	game->play->plane_y = old_plane_x * sin(ROT_SPEED)
		+ game->play->plane_y * cos(ROT_SPEED);
	return ;
}
