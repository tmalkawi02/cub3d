/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:14:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 13:14:04 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "helpers.h"
#include "initializers.h"
#include "mlx.h"
#include <math.h>
#include "raycasters.h"
#include <stdlib.h>
#include <stdio.h>

static void	clear_screen(t_game *game);

int	render_loop(t_game *game)
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
