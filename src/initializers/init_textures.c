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

static void	set_address_of_texture(t_game *game);

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
	set_address_of_texture(game);
}

static void	set_address_of_texture(t_game *game)
{
	game->texs->north->img = mlx_xpm_file_to_image(game->mlx, N_PATH,
			&game->texs->north->width, &game->texs->north->height);
	if (game->texs->north->img == NULL)
		return (clean_game(game));
	game->texs->south->img = mlx_xpm_file_to_image(game->mlx, S_PATH,
			&game->texs->south->width, &game->texs->south->height);
	if (game->texs->south->img == NULL)
		return (clean_game(game));
	game->texs->east->img = mlx_xpm_file_to_image(game->mlx, E_PATH,
			&game->texs->east->width, &game->texs->east->height);
	if (game->texs->east->img == NULL)
		return (clean_game(game));
	game->texs->west->img = mlx_xpm_file_to_image(game->mlx, W_PATH,
			&game->texs->west->width, &game->texs->west->height);
	if (game->texs->west->img == NULL)
		return (clean_game(game));
}
