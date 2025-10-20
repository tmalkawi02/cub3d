/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:10:00 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 12:10:00 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "raycasters.h"
#include <math.h>

void	player_rotate_left(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;
	float	angle;

	old_dir_x = game->play->dir_x;
	old_plane_x = game->play->dir_y;
	angle = -ROT_SPEED;
	game->play->dir_x = game->play->dir_x * cos(angle)
		- game->play->dir_y * sin(angle);
	game->play->dir_y = old_dir_x * sin(angle)
		+ game->play->dir_y * cos(angle);
	game->play->plane_x = game->play->plane_x * cos(angle)
		- game->play->plane_y * sin(angle);
	game->play->plane_y = old_plane_x * sin(angle)
		+ game->play->plane_y * cos(angle);
	return ;
}
