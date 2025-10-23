/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:05:17 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/23 11:05:17 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

void	render_square(t_minimap *minimap, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < minimap->scale)
	{
		j = -1;
		while (++j < minimap->scale)
		{
			render_pixel(game, minimap->scale + i,
				minimap->scale + j, minimap->fg_color);
		}
	}
}
