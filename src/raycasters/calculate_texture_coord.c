/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture_coord.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:58:50 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/20 10:58:50 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <math.h>

void	calculate_texture_coord(t_game *game, t_ray *ray,
			t_wall *wall, t_texture *tex)
{
	float	wall_x;

	if (ray->side == 0)
		wall_x = game->play->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->play->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	wall->tex_x = (int)(wall_x * (float)tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		wall->tex_x = tex->width - wall->tex_x - 1;
	wall->step = 1.0f * tex->height / wall->line_height;
	wall->tex_pos = (wall->draw_start - WIN_HEIGHT
			/ 2 + (float)wall->line_height / 2) * wall->step;
}
