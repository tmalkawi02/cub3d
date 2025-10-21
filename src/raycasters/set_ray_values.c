/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:57:50 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/21 10:20:24 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <math.h>

static void		calc_step_and_sidedist(t_game *game);
static double	check_div_by_zero(double v);

void	set_ray_values(t_game *game, int x)
{
	game->ray->camera_x = 2 * x
		/ (double)WIN_WIDTH - 1.0;
	game->ray->dir_x = game->play->dir_x
		+ game->play->plane_x * game->ray->camera_x;
	game->ray->dir_y = game->play->dir_y
		+ game->play->plane_y * game->ray->camera_x;
	game->ray->map_x = (int)game->play->pos_x;
	game->ray->map_y = (int)game->play->pos_y;
	game->ray->delta_dist_x = check_div_by_zero(game->ray->dir_x);
	game->ray->delta_dist_y = check_div_by_zero(game->ray->dir_y);
	game->ray->hit = 0;
	calc_step_and_sidedist(game);
}

static void	calc_step_and_sidedist(t_game *game)
{
	if (game->ray->dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->play->pos_x - game->ray->map_x)
			* game->ray->delta_dist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = (game->ray->map_x + 1.0 - game->play->pos_x)
			* game->ray->delta_dist_x;
	}
	if (game->ray->dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->play->pos_y - game->ray->map_y)
			* game->ray->delta_dist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = (game->ray->map_y + 1.0 - game->play->pos_y)
			* game->ray->delta_dist_y;
	}
}

static double	check_div_by_zero(double v)
{
	if (v == 0)
		return (1e30);
	else
		return (fabs(1.0 / v));
}
