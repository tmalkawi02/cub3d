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
static void	render_minimap_simple(t_game *game);

#if DEBUG == 1
static int fps_count = 0;
#endif

void    draw_direction_ray(t_game *game, int scale)
{
    int     player_x;
    int     player_y;
    double  ray_x;
    double  ray_y;
    int     map_x;
    int     map_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  side_dist_x;
    double  side_dist_y;
    int     step_x;
    int     step_y;
    int     hit;
    int     i;
    double  t;
    
    // Player position
    player_x = (int)(game->play->pos_x * scale);
    player_y = (int)(game->play->pos_y * scale);
    
    // Ray direction = player direction
    ray_x = game->play->dir_x;
    ray_y = game->play->dir_y;
    
    // Starting map position
    map_x = (int)game->play->pos_x;
    map_y = (int)game->play->pos_y;
    
    // Delta distances
    delta_dist_x = fabs(1 / ray_x);
    delta_dist_y = fabs(1 / ray_y);
    
    // Calculate step and initial side_dist
    if (ray_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->play->pos_x - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - game->play->pos_x) * delta_dist_x;
    }
    
    if (ray_y < 0)
    {
        step_y = -1;
        side_dist_y = (game->play->pos_y - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - game->play->pos_y) * delta_dist_y;
    }
    
    // Perform DDA
    hit = 0;
    while (!hit)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
        }
        
        if (game->map[map_y][map_x] == '1')
            hit = 1;
    }
    
    // Draw line from player to hit
    i = 0;
    while (i <= 100)
    {
        t = (double)i / 100;
        render_pixel(game, 
                    player_x + (int)((map_x * scale + scale/2 - player_x) * t),
                    player_y + (int)((map_y * scale + scale/2 - player_y) * t),
                    0xFFFF00);
        i++;
    }
    
    // Draw hit point
    render_pixel(game, map_x * scale + scale/2, map_y * scale + scale/2, 0x00FF00);
}

int	render_loop(t_game *game)
{
	int	x;

#if DEBUG == 1
	if (fps_count % 60 == 0)
	{
		printf("=== FRAME ===\n");
		printf("PLayer pos: (%.2f, %.2f)\n", game->play->pos_x, game->play->pos_y);
		printf("PLayer dir: (%.2f, %.2f)\n", game->play->dir_x, game->play->dir_y);
		printf("PLayer plane: (%.2f, %.2f)\n", game->play->plane_x, game->play->plane_y);
	}
	fps_count++;
#endif

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
	render_minimap_simple(game);
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

static void	render_minimap_simple(t_game *game)
{
    int     x;
    int     y;
    int     pixel_x;
    int     pixel_y;
    int     scale;
    
    scale = 12;  // 8 pixels per map tile
    
    // Draw walls
    y = 0;
    while (y < 14)
    {
        x = 0;
        while (x < 33)
        {
            if (game->map[y][x] == '1')
            {
                // Draw wall tile
                pixel_y = 0;
                while (pixel_y < scale)
                {
                    pixel_x = 0;
                    while (pixel_x < scale)
                    {
                        render_pixel(game, x * scale + pixel_x, 
                                   y * scale + pixel_y, 0xFFFFFF);
                        pixel_x++;
                    }
                    pixel_y++;
                }
            }
            x++;
        }
        y++;
    }
    
    // Draw player as single bright pixel (or small cross)
    pixel_x = (int)(game->play->pos_x * scale);
    pixel_y = (int)(game->play->pos_y * scale);

	draw_direction_ray(game, scale);

    render_pixel(game, pixel_x, pixel_y, 0xFF0000);          // Center
    render_pixel(game, pixel_x + 1, pixel_y, 0xFF0000);      // Right
    render_pixel(game, pixel_x - 1, pixel_y, 0xFF0000);      // Left
    render_pixel(game, pixel_x, pixel_y + 1, 0xFF0000);      // Down
    render_pixel(game, pixel_x, pixel_y - 1, 0xFF0000);      // Up
}
