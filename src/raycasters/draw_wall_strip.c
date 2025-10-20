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

void	draw_wall_strip(t_game *game, t_ray *ray, t_wall *wall, int x)
{
	t_texture	*tex;

	tex = select_wall_texture(game, ray);
	calculate_texture_coord(game, ray, wall, tex);
	draw_textured_walls(game, wall, tex, x);
}
