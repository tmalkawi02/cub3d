/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:31:36 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:36:21 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdlib.h>
#include "libft.h"

// TODO: add clean up for game->cam
void	init_cam(t_game *game)
{
	game->cam = malloc(sizeof(t_camera));
	if (game->cam == NULL)
		return ;
	ft_bzero(game->cam, sizeof(t_camera));
}
