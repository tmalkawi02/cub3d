/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:25:35 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 15:25:35 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <math.h>

void	calculate_wall(t_game *game)
{
	game->wall->line_height = (int)(WIN_HEIGHT / game->ray->perp_wall_dist);
	game->wall->draw_start = (float)-game->wall->line_height
		/ 2 + WIN_HEIGHT / 2;
	if (game->wall->draw_start < 0)
		game->wall->draw_start = 0;
	game->wall->draw_end = (float)game->wall->line_height / 2 + WIN_HEIGHT / 2;
	if (game->wall->draw_end >= WIN_HEIGHT)
		game->wall->draw_end = WIN_HEIGHT - 1;
	if (game->ray->side == 0)
		game->wall->wall_x = game->play->pos_y
			+ game->ray->perp_wall_dist * game->ray->dir_y;
	else
		game->wall->wall_x = game->play->pos_x + game->ray->perp_wall_dist
			* game->ray->dir_x;
	game->wall->wall_x -= floor(game->wall->wall_x);
}
