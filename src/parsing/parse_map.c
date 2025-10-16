/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/16 15:26:39 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

/**
 * @brief checks that the map is surrounded by walls
 * 
 * @param fd: map file
 * @return int: 0 if no walls, 1 if valid walls
 */
int	check_walls(char **map)
{

}

char **fill_rows(char fd, char **map)
{
	int		i;
	char	*line;
	int		len;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[len])
		{
			if (!valid(line[len]))
				return (map_error(line, map));
			len++;
		}
		
		map[i] = ft_calloc(len, sizeof(char));
		if (!map[i])
			return (map_error(line, map));
		map[i] = copy(line);
		i++;
	}
}

int	get_n_rows(int fd, char *mapfile)
{
	int		rows;
	char	c;
	
	rows = 0;
	while (read(fd, &c, 1) > 0)
    {
        if (c == '\n')
            rows++;
    }
    close(fd);
	return (rows);
}

int	build_map(int fd, int lines_read, char *mapfile, t_game *game)
{
	int		rows;
	int		i;
	char	*line;

	rows = get_n_rows(fd, mapfile);
	game->map = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (!game->map)
		return (-1);
	i = 0;
	open_map(&fd, mapfile);
	while (i++ < lines_read)
	{
		line = get_next_line(fd);
		free(line);
	}
	game->map = fill_rows(fd, game->map);
	if (game->map[0][0] = 0 || check_walls(game->map) == -1)
		return (err("Error\nInvalid map\n", game, fd));
	return (0);
}

int	parse_map(char *mapfile, t_game *game)
{
	int	map_fd;
	int	lines_read;

	map_fd = 0;
	lines_read = 0;
	game->texs = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!game->texs)
		return (0);
	if (open_map(&map_fd, mapfile) == -1)
		return (parsing_err("Error\nCould not open map\n", game, 0));
	if (!initialise_textures(game->texs))
		return(parsing_err("Error\nTexture memory allocation failed\n", game, map_fd));
	if (assign_textures(map_fd, &lines_read, game) == -1)
		return (parsing_err("Error\nCould not assign textures\n", game, map_fd));
	if (check_textures(game) == -1)
		return (parsing_err("Error\nNot all textures assigned\n", game, map_fd));
	if (build_map(map_fd, lines_read, mapfile, game) == -1)
		return (err("Error\nCould not build map\n", game));
	close(map_fd);
	get_next_line(-1);
	return (0);
}
