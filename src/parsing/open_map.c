/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:04:14 by aborel            #+#    #+#             */
/*   Updated: 2025/10/14 12:49:32 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"


/**
 * @brief checks the map is a ".cub" file, opens the map
 * 
 * @param map_fd place to stock fd
 * @param mapfile file path
 * @return int opened fd
 */
int	open_map(int *map_fd, char *mapfile)
{
	int	i;

	i = ft_strlen(mapfile);
	if (ft_strncmp(&mapfile[i - 4], ".cub", 4))
		return (-1);
	*map_fd = open(mapfile, O_RDONLY);
	return (*map_fd);
}
