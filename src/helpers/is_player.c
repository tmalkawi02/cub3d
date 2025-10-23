/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:46:40 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 11:46:40 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "raycasters.h"

bool	is_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
			|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
		return (true);
	return (false);
}
