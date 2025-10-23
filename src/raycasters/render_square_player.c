/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:05:17 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 11:55:01 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdio.h>

#define PLAYER_SCALE	0.5

void	render_square_player(t_minimap *minimap, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (minimap->scale * PLAYER_SCALE))
	{
		j = -1;
		while (++j < (minimap->scale * PLAYER_SCALE))
		{
			render_pixel(game, minimap->square_x + i,
				minimap->square_y + j, minimap->play_col);
		}
	}
}
