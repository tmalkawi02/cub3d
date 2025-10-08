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

void	init_player(t_game *game)
{
	game->play = malloc(sizeof(t_player));
	if (game->play == NULL)
		return (clean_game(game));
	ft_bzero(game->play, sizeof(t_player));
}
