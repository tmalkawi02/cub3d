/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:58 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 16:07:58 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaners.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include "stdbool.h"

int	k_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		clean_game(game);
		return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
	}
	else if (keycode == XK_w)
		game->play->kup = true;
	else if (keycode == XK_a)
		game->play->kleft = true;
	else if (keycode == XK_s)
		game->play->kdown = true;
	else if (keycode == XK_d)
		game->play->kright = true;
	else if (keycode == XK_Right)
		game->play->rrotate = true;
	else if (keycode == XK_Left)
		game->play->lrotate = true;
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
