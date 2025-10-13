/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:58:08 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:58:08 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZERS_H
# define INITIALIZERS_H

# include "raycasters.h"

void	init_game(t_game *game);

void	init_cam(t_game *game);

void	init_textures(t_game *game);

void	init_player(t_game *game);

void	init_wall(t_game *game);

void	init_ray(t_game *game);

#endif // !INITIALIZERS_H
