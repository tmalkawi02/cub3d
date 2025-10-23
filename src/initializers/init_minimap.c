/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:11:55 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 11:11:55 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializers.h"
#include "libft.h"
#include "raycasters.h"
#include <stdlib.h>
#include "parsing.h"

void	init_minimap(t_game *game)
{
	game->minimap = malloc(sizeof(t_minimap));
	if (game->minimap == NULL)
		return (parsing_err("Error\nUnable to init minimap", game, 0));
	ft_bzero(game->minimap, sizeof(t_minimap));
	game->minimap->fg_color = 0xFFFFFF;
	game->minimap->bg_color = 0x7393B3;
	game->minimap->play_col = 0xFF0000;
	game->minimap->scale = 12;
}
