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
#include "parsing.h"

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
}
