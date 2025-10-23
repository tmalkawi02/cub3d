/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:42:27 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/13 15:42:27 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "raycasters.h"
# include <stdbool.h>

char	**get_map(void);

bool	is_wall(t_game *game, int x, int y);

bool	is_player(t_game *game, int x, int y);

#endif
