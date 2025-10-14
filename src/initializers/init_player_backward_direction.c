/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_backward_direction.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:48:02 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/14 12:48:02 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializers.h"

void	init_player_backward_direction(t_game *game)
{
	game->play->dir_x = 0.0f;
	game->play->dir_y = 1.0f;
	game->play->plane_x = -0.66;
	game->play->plane_y = 0.0f;
}
