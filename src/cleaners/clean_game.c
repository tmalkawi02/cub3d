/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:02:15 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/28 15:07:26 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycasters.h"
#include <stdlib.h>

static void	clean_textures(t_game *game);
static void	clean_win_image(t_game *game);
void		free_split(char **str);
void		clean_texs(t_texture *tex, t_game *game);

void	clean_mlx(t_game *game)
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

void	clean_game(t_game *game)
{
	if (game->map)
		free_split(game->map);
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
		clean_mlx(game);
	free(game);
	exit(EXIT_FAILURE);
}

static void	clean_textures(t_game *game)
{
	(void) game;
	if (game->texs == NULL)
		return ;
	if (game->texs->north)
		clean_texs(game->texs->north, game);
	if (game->texs->south)
		clean_texs(game->texs->south, game);
	if (game->texs->east)
		clean_texs(game->texs->east, game);
	if (game->texs->west)
		clean_texs(game->texs->west, game);
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

void	clean_texs(t_texture *tex, t_game *game)
{
	if (tex->img)
		mlx_destroy_image(game->mlx, tex->img);
	if (tex->tex_path)
		free(tex->tex_path);
	free(tex);
}
