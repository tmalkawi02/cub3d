/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:55 by aborel            #+#    #+#             */
/*   Updated: 2025/10/14 18:46:59 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

/**
 * @brief Set the tex of a direction
 * 
 * @param map 
 * @param file 
 * @return int -1 if failed
 */
int	tex_file(t_texture *dir, char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (!is_whitespace(line[i]))
		i++;
	while (is_whitespace(line[i]))
		i++;
	path = next_word(&line[i]);
	if (!path)
		return (-1);
	if (dir->tex_path)
		free(dir->tex_path);
	dir->tex_path = path;
	return (0);
}

int	next_colour(char *s, bool end)
{
	int	i;

	i = 0;
	i += skip_whitespace(&s[i]);
	while (ft_isdigit(s[i]))
		i++;
	i += skip_whitespace(&s[i]);
	if (!end)
	{
		if (s[i] != ',')
			return (-1);
		i++;
	}
	i += skip_whitespace(&s[i]);
	return (i);
}

int	assign_colours(unsigned long *ptr, char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 2;
	r = ft_atoi(&line[i]);
	i += next_colour(&line[i], 0);
	g = ft_atoi(&line[i]);
	i += next_colour(&line[i], 0);
	b = ft_atoi(&line[i]);
	i += next_colour(&line[i], 1);
	if (line[i])
		return (-1);
	*ptr = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (0);
}

int	set_texture(t_game *game, char *line, char *id)
{
	int	ret;

	if (!wordcmp(id, "NO") || !wordcmp(id, "N"))
		ret = tex_file(game->texs->north, line);
	else if (!wordcmp(id, "SO") || !wordcmp(id, "S"))
		ret = tex_file(game->texs->south, line);
	else if (!wordcmp(id, "WE") || !wordcmp(id, "W"))
		ret = tex_file(game->texs->west, line);
	else if (!wordcmp(id, "EA") || !wordcmp(id, "E"))
		ret = tex_file(game->texs->east, line);
	else if (!wordcmp(id, "C"))
		ret = assign_colours(&game->ceiling, line);
	else if (!wordcmp(id, "F"))
		ret = assign_colours(&game->floor, line);
	else
		ret = -1;
	return (ret);
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
		if (!line[i])
		{
			free(line);
			continue ;
		}
		if (ft_isdigit(line[i]))
		{
			free(line);
			break ;
		}
		id = next_word(&line[i]);
		if (id == 0)
		{
			free(line);
			continue ;
		}
		
		if (set_texture(game, &line[i], id) == -1)
		{
			free_assign_textures(line, id);
			return (-1);
		}
		free_assign_textures(line, id);
	}
	return (0);
}
