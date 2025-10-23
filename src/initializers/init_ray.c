/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:37:20 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 13:37:20 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raycasters.h"
#include <stdlib.h>
#include "cleaners.h"
#include "parsing.h"

void	init_ray(t_game *game)
{
	if (game == NULL)
		return ;
	game->ray = malloc(sizeof(t_ray));
	if (game->ray == NULL)
		return (parsing_err("Error\nUnable to init rays", game, 0));
	ft_bzero(game->ray, sizeof(t_ray));
}
