/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:13:08 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/20 11:13:08 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

void	draw_textured_walls(t_game *game, t_wall *wall, t_texture *tex, int x)
{
	int				y;
	int				tex_y;
	unsigned int	color;

	y = wall->draw_start;
	while (y <= wall->draw_end)
	{
		tex_y = (int)wall->tex_pos % tex->height;
		if (tex_y < 0)
			tex_y += tex->height;
		wall->tex_pos += wall->step;
		color = render_pixel_texture(wall->tex_x, tex_y, tex);
		render_pixel(game, x, y, color);
		y++;
	}
}
