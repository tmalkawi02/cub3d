/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:21:11 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:21:11 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializers.h"
#include "raycasters.h"
#include "mlx.h"
#include <stdlib.h>
#include "cleaners.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (clean_game(game));
	game->win = mlx_new_window(game->mlx, WIN_HEIGHT, WIN_WIDTH, "cub3d");
	init_cam(game);
	init_player(game);
	init_textures(game);
	init_wall(game);
	return ;
}
