/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:02:50 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 14:02:50 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "raycasters.h"
#include <stdio.h>

void	render_map_bonus(t_game *game, t_minimap *minimap)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
			{
				minimap->square_x = j * minimap->scale;
				minimap->square_y = i * minimap->scale;
				render_square(minimap, game);
			}
			else if (game->map[i][j] == '0' || is_player(game, j, i))
			{
				minimap->square_x = j * minimap->scale;
				minimap->square_y = i * minimap->scale;
				render_square_bg(minimap, game);
			}
		}
	}
}
