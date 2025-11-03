/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:47:48 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/29 15:36:59 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stdbool.h>

bool	is_wall(t_game *game, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x > game->n_cols || y > game->n_rows)
		return (true);
	c = game->map[y][x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (false);
	return (true);
}
