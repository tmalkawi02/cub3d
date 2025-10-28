/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:24 by aborel            #+#    #+#             */
/*   Updated: 2025/10/28 15:25:45 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"
#include "initializers.h"

char	**fill_rows(char fd, char **map, int rows, int cols)
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
		map[i] = ft_calloc(cols + 1, sizeof(char));
		if (!map[i])
			return (map_error(line, map));
		map[i] = copy_wout_nl(line, map[i], cols);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	get_n_rows(int fd, t_game *game)
{
	int		rows;
	char	*line;
	int		cols;
	int		temp_cols;

	rows = 1;
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
		free(line);
	}
	close(fd);
	game->n_rows = rows;
	game->n_cols = cols;
}

int	build_map(int fd, char *mapfile, t_game *game)
{
	int		i;
	char	*line;

	get_n_rows(fd, game);
	game->map = (char **)ft_calloc(game->n_rows + 1, sizeof(char *));
	if (!game->map)
		return (-1);
	i = 0;
	open_map(&fd, mapfile);
	while (i++ < game->lines_read - 1)
	{
		line = get_next_line(fd);
		free(line);
	}
	game->map = fill_rows(fd, game->map, game->n_rows, game->n_cols);
	if (game->map[0] == 0 || !check_walls(game->map, game))
		return (-1);
	return (0);
}

void	parse_map(char *mapfile, t_game *game)
{
	int	map_fd;

	map_fd = 0;
	if (open_map(&map_fd, mapfile) == -1)
		return (parsing_err("Error\nCould not open map\n", game, 0));
	if (assign_textures(map_fd, game) == -1)
		return (parsing_err("Error\nCould not assign textures\n", game, map_fd));
	if (check_textures(game) == -1)
		return (parsing_err("Error\nNot all textures assigned\n", game, map_fd));
	if (build_map(map_fd, mapfile, game) == -1)
		return (parsing_err("Error\nCould not build map\n", game, map_fd));
	close(map_fd);
	get_next_line(-1);
}
