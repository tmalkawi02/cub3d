/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/13 14:01:48 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"

/**
 * @brief checks that the map is surrounded by walls
 * 
 * @param fd: map file
 * @return int: 0 if no walls, 1 if valid walls
 */
int	check_walls(int fd)
{

}

int	build_map(int fd, t_game *game)
{
	
}

int	parse_map(char *mapfile, t_game *game)
{
	int		map_fd;
	char 	*line;

	if (open_map(&map_fd, mapfile) == -1)
		return (err("Could not open map\n", 1));
	if (assign_textures(map_fd, game->texs) == -1)
		return (err("Could not assign textures\n", 2));
	if (assign_colours(map_fd, game) == -1)
		return (err("Could not assign colours", 3));
	if (build_map(map_fd, game) == -1)
		return (err("Could not build map\n", 4));
}
