/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/13 13:08:37 by aborel           ###   ########.fr       */
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

/**
 * @brief Set the colour of a direction
 * 
 * @param map 
 * @param file 
 * @return int 
 */
int	set_colour(char *dir, char *file)
{

}

int	parse_map(char *mapfile)
{
	int		map_fd;
	char 	*line;

	if (open_map(&map_fd, mapfile) == -1)
		return (err("Could not open map\n", 1));
}
