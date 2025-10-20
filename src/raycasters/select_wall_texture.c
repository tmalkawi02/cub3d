/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_wall_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:48:46 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/20 10:48:46 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

t_texture	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (game->texs->east);
		else
			return (game->texs->west);
	}
	else
	{
		if (ray->dir_y > 0)
			return (game->texs->south);
		else
			return (game->texs->north);
	}
}
