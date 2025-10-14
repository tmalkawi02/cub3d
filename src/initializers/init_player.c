/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:13:10 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 16:13:10 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializers.h"
#include "libft.h"
#include "raycasters.h"
#include <stdlib.h>
#include "cleaners.h"

static void	find_player_position(t_game *game);
void	init_player(t_game *game)
{
	game->play = malloc(sizeof(t_player));
	if (game->play == NULL)
		return (clean_game(game));
	ft_bzero(game->play, sizeof(t_player));
}

static void	find_player_position(t_game *game)
{
	size_t	x;
	size_t	y;
	bool	found;

	y = -1;
	found = false;
	while (game->map[++y] && !found)
	{
		x = -1;
		while (game->map[y][++x] && !found)
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
					|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				game->play->pos_x = x + 0.5f;
				game->play->pos_y = y + 0.5f;
			}
		}
	}
}
