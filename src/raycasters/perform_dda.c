/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:30:45 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 14:30:45 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

static void	calc_perpendicular_dist(t_game *game);

void	perform_dda(t_game *game)
{
	while (game->ray->hit == 0)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_dist_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_dist_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->hit = 1;
	}
	calc_perpendicular_dist(game);
}

static void	calc_perpendicular_dist(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->perp_wall_dist = (game->ray->map_x - game->play->pos_x
				+ (1.0f - game->ray->step_x) / 2.0) / game->ray->dir_x;
	else
		game->ray->perp_wall_dist = (game->ray->map_y - game->play->pos_y
				+ (1.0f - game->ray->step_y) / 2.0) / game->ray->dir_y;
}
