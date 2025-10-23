/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square_bg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:05:17 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 11:57:04 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdio.h>

void	render_square_bg(t_minimap *minimap, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < minimap->scale)
	{
		j = -1;
		while (++j < minimap->scale)
		{
			render_pixel(game, minimap->square_x + i,
				minimap->square_y + j, minimap->bg_color);
		}
	}
}
