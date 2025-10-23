/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:14:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 14:18:37 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "raycasters_bonus.h"

static void	clear_screen(t_game *game);

int	render_loop_bonus(t_game *game)
{
	int	x;

	x = -1;
	clear_screen(game);
	player_move(game);
	while (++x < WIN_WIDTH)
	{
		set_ray_values(game, x);
		perform_dda(game);
		calculate_wall(game);
		draw_wall_strip(game, game->ray, game->wall, x);
	}
	render_map_bonus(game, game->minimap);
	game->minimap->square_x = (int)game->play->pos_x * game->minimap->scale;
	game->minimap->square_y = (int)game->play->pos_y * game->minimap->scale;
	render_square_player(game->minimap, game);
	mlx_put_image_to_window(game->mlx, game->win, game->px_data->img, 0, 0);
	return (EXIT_SUCCESS);
}

static void	clear_screen(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			render_pixel(game, i, j, 0x000000);
			j++;
		}		
		i++;
	}
}
