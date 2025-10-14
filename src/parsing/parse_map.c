/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/14 13:23:17 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

/**
 * @brief checks that the map is surrounded by walls
 * 
 * @param fd: map file
 * @return int: 0 if no walls, 1 if valid walls
 */
// int	check_walls(int fd)
// {

// }

// int	build_map(int fd, t_game *game)
// {
// 	return (0);
// }

int	parse_map(char *mapfile, t_game *game)
{
	int			map_fd;

	if (open_map(&map_fd, mapfile) == -1)
		return (err("Error\nCould not open map\n", game));
	game->texs = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!game->texs)
		return (0);
	if (!initialise_textures(game->texs))
		return(err("Error\nTexture memory allocation failed\n", game));
	if (assign_textures(map_fd, game) == -1)
		return (err("Error\nCould not assign textures\n", game));
	if (check_textures(game) == -1)
		return (err("Error\nNot all textures assigned\n", game));
	// if (build_map(map_fd, game) == -1)
	// 	return (err("Error\nCould not build map\n", game));
	return (0);
}
