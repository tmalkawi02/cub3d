/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:14:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 13:14:04 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdlib.h>

int	render_loop(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		set_ray_values(game, x);
		perform_dda(game);
		calculate_wall(game);
		calculate_wall(game);
	}
	return (EXIT_SUCCESS);
}
