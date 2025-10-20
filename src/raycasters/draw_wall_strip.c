/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_strip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:35:48 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/20 11:35:48 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdio.h>

void	draw_wall_strip(t_game *game, t_ray *ray, t_wall *wall, int x)
{
	t_texture	*tex;
	int			y;

	tex = select_wall_texture(game, ray);
	calculate_texture_coord(ray, wall, tex);
	y = -1;
	while (++y < wall->draw_start)
		render_pixel(game, x, y, CEILING_COL);
	draw_textured_walls(game, wall, tex, x);
	y = wall->draw_end - 1;
	while (++y < WIN_HEIGHT)
		render_pixel(game, x, y, FLOOR_COL);
}
