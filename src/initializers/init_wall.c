/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:21:41 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 13:21:41 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializers.h"
#include <stdlib.h>
#include "cleaners.h"
#include "libft.h"
#include "parsing.h"

void	init_wall(t_game *game)
{
	if (game == NULL)
		return ;
	game->wall = malloc(sizeof(t_wall));
	if (game->wall == NULL)
		return (parsing_err("Error\nUnable to init wall data", game, 0));
	ft_bzero(game->wall, sizeof(t_wall));
}
