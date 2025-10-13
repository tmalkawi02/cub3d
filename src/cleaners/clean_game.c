/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:02:15 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 15:02:15 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycasters.h"
#include <stdlib.h>

static void	clean_textures(t_game *game);

void	clean_game(t_game *game)
{
	clean_textures(game);
	if (game->cam)
		free(game->cam);
	if (game->play)
		free(game->play);
	if (game->ray)
		free(game->ray);
	if (game->wall)
		free(game->wall);
	if (game->mlx)
	{
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(EXIT_FAILURE);
}

static void	clean_textures(t_game *game)
{
	(void) game;
	if (game->texs == NULL)
		return ;
	if (game->texs->north)
	{
		mlx_destroy_image(game->mlx, game->texs->north->img);
		free(game->texs->north);
	}
	if (game->texs->south)
	{
		mlx_destroy_image(game->mlx, game->texs->south->img);
		free(game->texs->south);
	}
	if (game->texs->east)
	{
		mlx_destroy_image(game->mlx, game->texs->east->img);
		free(game->texs->east);
	}
	if (game->texs->west)
	{
		mlx_destroy_image(game->mlx, game->texs->west->img);
		free(game->texs->west);
	}
	free(game->texs);
}
