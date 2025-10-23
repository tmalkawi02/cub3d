/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_px_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:11:43 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 16:11:43 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "raycasters.h"
#include <stdlib.h>
#include "cleaners.h"
#include "parsing.h"

void	init_px_data(t_game *game)
{
	if (game == NULL)
		return ;
	game->px_data = malloc(sizeof(t_px_data));
	if (game->px_data == NULL)
		return (parsing_err("Error\nUnable to init pixels data", game, 0));
	ft_bzero(game->px_data, sizeof(t_px_data));
	game->px_data->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game->px_data->img == NULL)
		return ;
	game->px_data->addr = mlx_get_data_addr(game->px_data->img,
			&game->px_data->bpp,
			&game->px_data->len_line, &game->px_data->endian);
	ft_memset(game->px_data->addr,
		0, WIN_WIDTH * WIN_HEIGHT * ((float)game->px_data->bpp / 8));
}
