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
#include <stddef.h>
#include <stdlib.h>
#include "cleaners.h"
#include "parsing.h"

static void	find_player_position(t_game *game);
static void	set_player_dir(t_game *game, char coord);

void	init_player(t_game *game)
{
	game->play = malloc(sizeof(t_player));
	if (game->play == NULL)
		return (parsing_err("Error\nUnable to init player", game, 0));
	ft_bzero(game->play, sizeof(t_player));
	find_player_position(game);
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
				set_player_dir(game, game->map[y][x]);
				found = true;
			}
		}
	}
}

static void	set_player_dir(t_game *game, char coord)
{
	if (coord == 'N')
		init_player_forward_direction(game);
	else if (coord == 'S')
		init_player_backward_direction(game);
	else if (coord == 'E')
		init_player_right_direction(game);
	else if (coord == 'W')
		init_player_left_direction(game);
	else
		return ;
	return ;
}
