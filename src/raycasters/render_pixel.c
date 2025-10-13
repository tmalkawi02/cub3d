/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:49:25 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 15:49:25 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

void	render_pixel(t_game *game, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = game->px_data->addr + (y * game->px_data->len_line + x
			* (game->px_data->bpp / 8));
	*(unsigned int *)dst = color;
}
