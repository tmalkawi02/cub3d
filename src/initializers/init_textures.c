/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:37:41 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:37:41 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "raycasters.h"
#include <stdlib.h>
#include "cleaners.h"

static void	set_address_of_textures(t_game *game);
static int	load_texture(t_game *game, t_texture *tex, char *path);

void	init_textures(t_game *game)
{
	game->texs = malloc(sizeof(t_textures));
	if (game->texs == NULL)
		return ;
	ft_bzero(game->texs, sizeof(t_textures));
	game->texs->north = malloc(sizeof(t_texture));
	if (game->texs->north == NULL)
		return ;
	ft_bzero(game->texs->north, sizeof(t_texture));
	game->texs->south = malloc(sizeof(t_texture));
	if (game->texs->south == NULL)
		return ;
	ft_bzero(game->texs->south, sizeof(t_texture));
	game->texs->east = malloc(sizeof(t_texture));
	if (game->texs->east == NULL)
		return ;
	ft_bzero(game->texs->east, sizeof(t_texture));
	game->texs->west = malloc(sizeof(t_texture));
	if (game->texs->west == NULL)
		return ;
	ft_bzero(game->texs->west, sizeof(t_texture));
	set_address_of_textures(game);
}

static void	set_address_of_textures(t_game *game)
{
	if (load_texture(game, game->texs->north, N_PATH) == 0)
		return (clean_game(game));
	if (load_texture(game, game->texs->south, S_PATH) == 0)
		return (clean_game(game));
	if (load_texture(game, game->texs->east, E_PATH) == 0)
		return (clean_game(game));
	if (load_texture(game, game->texs->west, W_PATH) == 0)
		return (clean_game(game));
}

static int	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (tex->img == NULL)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->len_line, &tex->endian);
	if (tex->addr == NULL)
		return (0);
	return (1);
}
