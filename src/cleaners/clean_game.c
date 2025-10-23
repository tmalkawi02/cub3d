/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:02:15 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 18:45:02 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycasters.h"
#include <stdlib.h>

static void	clean_textures(t_game *game);
static void	clean_win_image(t_game *game);

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
	clean_win_image(game);
	if (game->minimap)
		free(game->minimap);
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
	//exit(EXIT_FAILURE);
}

static void	clean_textures(t_game *game)
{
	(void) game;
	if (game->texs == NULL)
		return ;
	if (game->texs->north)
	{
		if (game->texs->north->img)
			mlx_destroy_image(game->mlx, game->texs->north->img);
		if (game->texs->north->tex_path)
			free(game->texs->north->tex_path);
		free(game->texs->north);
	}
	if (game->texs->south)
	{
		if (game->texs->south->img)
			mlx_destroy_image(game->mlx, game->texs->south->img);
		if (game->texs->south->tex_path)
			free(game->texs->south->tex_path);
		free(game->texs->south);
	}
	if (game->texs->east)
	{
		if (game->texs->east->img)
			mlx_destroy_image(game->mlx, game->texs->east->img);
		if (game->texs->east->tex_path)
			free(game->texs->east->tex_path);
		free(game->texs->east);
	}
	if (game->texs->west)
	{
		if (game->texs->west->img)
			mlx_destroy_image(game->mlx, game->texs->west->img);
		if (game->texs->west->tex_path)
			free(game->texs->west->tex_path);
		free(game->texs->west);
	}
	free(game->texs);
}

static void	clean_win_image(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->px_data)
	{
		mlx_destroy_image(game->mlx, game->px_data->img);
		free(game->px_data);
	}
}
