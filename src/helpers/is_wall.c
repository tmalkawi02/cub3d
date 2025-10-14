/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:47:48 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 14:47:48 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stdbool.h>

// TODO: add map metrics bounds
bool	is_wall(t_game *game, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x > 32 || y > 13)
		return (true);
	c = game->map[y][x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (false);
	return (true);
}
