/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:55 by aborel            #+#    #+#             */
/*   Updated: 2025/10/13 15:45:59 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"

/**
 * @brief Set the tex of a direction
 * 
 * @param map 
 * @param file 
 * @return int 
 */
int	tex_file(t_texture *dir, char *file)
{

}
int	assign_colours(unsigned long *ptr, char *line)
{

}
int	set_texture(t_game *game, char *line, char *id)
{
	if (!wordcmp(id, "NO") || !wordcmp(id, "N"))
		tex_file(game->texs->north, line);
	else if (!wordcmp(id, "SO") || !wordcmp(id, "S"))
		tex_file(game->texs->south, line);
	else if (!wordcmp(id, "WE") || !wordcmp(id, "W"))
		tex_file(game->texs->west, line);
	else if (!wordcmp(id, "EA") || !wordcmp(id, "E"))
		tex_file(game->texs->east, line);
	else if (!wordcmp(id, "C"))
		assign_colours(&game->ceiling, line);
	else if (!wordcmp(id, "F"))
		assign_colours(&game->floor, line);
}

int	assign_textures(int fd, t_game *game)
{
	char	*line;
	int		i;
	char	*id;

	while (1)
	{
		line = get_next_line(fd);
		i = skip_whitespace(line);
		id = next_word(&line[i]);
		if (id == 0)
		{
			free(line);
			continue ;
		}
		if (set_texture(game, &line[i], id) == -1)
		{
			free(line);
			free(id);
			return (-1);
		}
	}
}
