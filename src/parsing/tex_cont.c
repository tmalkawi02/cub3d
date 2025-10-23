/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:20:52 by aborel            #+#    #+#             */
/*   Updated: 2025/10/14 18:09:32 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

void	free_assign_textures(char *line, char *id)
{
	free(line);
	if (id)
		free(id);
}

int	check_textures(t_game *game)
{
	if (game->texs->north->tex_path == 0 || game->texs->south->tex_path == 0)
		return (-1);
	if (game->texs->west->tex_path == 0 || game->texs->east->tex_path == 0)
		return (-1);
	if (game->floor == 0 || game->ceiling == 0)
		return (-1);
	return (0);
}

int	initialise_textures(t_textures *tex)
{
	t_texture *north;
	t_texture *south;
	t_texture *west;
	t_texture *east;

	north = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!north)
		return (0);
	south = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!south)
		return (0);
	east = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!east)
		return (0);
	west = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!west)
		return (0);
	tex->north = north;
	tex->south = south;
	tex->west = west;
	tex->east = east;
	return (1);
}
