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
#include "helpers.h"
#include "parsing.h"

static void	set_address_of_textures(t_game *game);
static int	load_texture(t_game *game, t_texture *tex, char *path);

void	init_game(t_game *game, char *arg)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (parsing_err("Error\nUnable to init game", game, 0));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_px_data(game);
	init_cam(game);
	init_textures(game);
	parse_map(arg, game);
	set_address_of_textures(game);
	init_player(game);
	init_wall(game);
	init_ray(game);
	init_minimap(game);
	return ;
}

static void	set_address_of_textures(t_game *game)
{
	if (load_texture(game, game->texs->north, game->texs->north->tex_path) == 0)
		return (parsing_err("Error\nUnable to load North texture\n", game, 0));
	if (load_texture(game, game->texs->south, game->texs->south->tex_path) == 0)
		return (parsing_err("Error\nUnable to load South texture\n", game, 0));
	if (load_texture(game, game->texs->east, game->texs->east->tex_path) == 0)
		return (parsing_err("Error\nUnable to load east texture\n", game, 0));
	if (load_texture(game, game->texs->west, game->texs->west->tex_path) == 0)
		return (parsing_err("Error\nUnable to load west texture\n", game, 0));
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
