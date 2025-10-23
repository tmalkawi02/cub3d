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
