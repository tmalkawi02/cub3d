/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_release.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:34 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 16:07:34 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include "stdbool.h"

int	k_release(int keycode, t_game *game)
{
	if (game == NULL)
		return (EXIT_FAILURE);
	else if (keycode == XK_w)
		game->play->kup = false;
	else if (keycode == XK_a)
		game->play->kleft = false;
	else if (keycode == XK_s)
		game->play->kdown = false;
	else if (keycode == XK_d)
		game->play->kright = false;
	else if (keycode == XK_Right)
		game->play->rrotate = false;
	else if (keycode == XK_Left)
		game->play->lrotate = false;
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
