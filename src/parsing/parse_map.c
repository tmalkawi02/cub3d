/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/14 17:20:33 by aborel           ###   ########.fr       */
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
	int	map_fd;

	map_fd = 0;
	game->texs = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!game->texs)
		return (0);
	if (open_map(&map_fd, mapfile) == -1)
		return (parsing_err("Error\nCould not open map\n", game, 0));
	if (!initialise_textures(game->texs))
		return(parsing_err("Error\nTexture memory allocation failed\n", game, map_fd));
	if (assign_textures(map_fd, game) == -1)
		return (parsing_err("Error\nCould not assign textures\n", game, map_fd));
	if (check_textures(game) == -1)
		return (parsing_err("Error\nNot all textures assigned\n", game, map_fd));
	// if (build_map(map_fd, game) == -1)
	// 	return (err("Error\nCould not build map\n", game));
	close(map_fd);
	get_next_line(-1);
	return (0);
}
