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

void	calculate_texture_coord(t_ray *ray, t_wall *wall, t_texture *tex)
{
	wall->tex_x = (int)(wall->wall_x * (double)tex->width);
	if (wall->tex_x < 0)
		wall->tex_x = 0;
	if (wall->tex_x >= tex->width)
		wall->tex_x = tex->width - 1;
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		wall->tex_x = tex->width - wall->tex_x - 1;
	wall->step = (double)tex->height / (double)wall->line_height;
	wall->tex_pos = (wall->draw_start - (double)WIN_HEIGHT / 2.0
			+ (double)wall->line_height / 2.0) * wall->step;
}
