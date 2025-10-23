/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:58:31 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 13:58:31 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "handlers.h"
#include "raycasters_bonus.h"
#include "mlx.h"
#include "initializers.h"
#include "cleaners.h"
#include <X11/X.h>

#define MAX_ARGS 2
#ifndef BONUS_CUB3D
# define BONUS_CUB3D 0
#endif

static int	destroy_button(t_game *game);

int	main(int ac, char **av)
{
	t_game	game;

	(void) av;
	if (ac != MAX_ARGS)
		return (EXIT_FAILURE);
	printf("%d\n", BONUS_CUB3D);
	init_game(&game);
	mlx_hook(game.win, ON_DESTROY, ButtonPressMask, &destroy_button, &game);
	mlx_hook(game.win, ON_KEYDOWN, KeyPressMask,
		&k_press, &game);
	mlx_hook(game.win, ON_KEYUP, KeyReleaseMask,
		&k_release, &game);
	mlx_loop_hook(game.mlx, &render_loop, &game);
	mlx_loop(game.mlx);
	clean_game(&game);
	return (EXIT_SUCCESS);
}

static int	destroy_button(t_game *game)
{
	clean_game(game);
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
