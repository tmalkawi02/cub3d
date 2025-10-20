/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/20 17:48:01 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

char **fill_rows(char fd, char **map, int rows, int cols)
{
	int		i;
	char	*line;
	int		len;
	int		pos;

	pos = 0;
	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = valid_line(line, &pos);
		if (!len)
			return (map_error(line, map));
		map[i] = ft_calloc(cols, sizeof(char));
		if (!map[i])
			return (map_error(line, map));
		map[i] = copy_wout_nl(line, map[i], cols);
		i++;
	}
	return (map);
}

void	get_n_rows(int fd, t_wall *wall)
{
	int		rows;
	char	*line;
	int		cols;
	int		temp_cols;

	rows = 0;
	cols = 0;
	while (1)
    {
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		temp_cols = ft_strlen(line);
		if (temp_cols > cols)
			cols = temp_cols;
    }
    close(fd);
	wall->n_rows = rows;
	wall->n_cols = cols;
}

int	build_map(int fd, int lines_read, char *mapfile, t_game *game)
{
	int		i;
	char	*line;
	t_wall	*wall;

	wall = (t_wall *)ft_calloc(1, sizeof(t_wall));
	if (!wall)
		return (-1);
	get_n_rows(fd, wall);
	game->map = (char **)ft_calloc(wall->n_rows + 1, sizeof(char *));
	if (!game->map)
		return (-1);
	i = 0;
	open_map(&fd, mapfile);
	while (i++ < lines_read - 1)
	{
		line = get_next_line(fd);
		free(line);
	}
	game->map = fill_rows(fd, game->map, wall->n_rows, wall->n_cols);
	if (game->map[0] == 0 || !check_walls(game->map, wall))
		return (-1);
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
		return (parsing_err("Error\nCould not build map\n", game, map_fd));
	close(map_fd);
	get_next_line(-1);
	return (0);
}
