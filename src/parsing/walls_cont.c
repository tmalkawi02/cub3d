/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:28:11 by aborel            #+#    #+#             */
/*   Updated: 2025/10/22 19:31:00 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "parsing.h"
#include "libft.h"

int	is_cardinal(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_room_col(char **map, int row, int col, t_game *w)
{
	if (row == w->n_rows)
		return (row);
	if (map[row][col] != '1')
		return (0);
	while (row < w->n_rows && map[row][col] == '1')
		row++;
	if (row == w->n_rows)
		return (row);
	if (map[row][col] != '0' && !is_cardinal(map[row][col]))
		return (0);
	while (row < w->n_rows && (map[row][col] == '0' || is_cardinal(map[row][col])))
		row++;
	if (row == w->n_rows || map[row][col] != '1')
		return (0);
	while (row < w->n_rows && map[row][col] == '1')
		row++;
	return (row - 1);
}

int	check_gap_col(char **map, int row, int col, t_game *w)
{
	if (map[row][col] != '1')
		return (0);
	while (row < w->n_rows && map[row][col] == '1')
		row++;
	if (row == w->n_rows)
		return (row);
	if (map[row][col] != ' ')
		return (0);
	while (row < w->n_rows && map[row][col] == ' ')
		row++;
	if (row == w->n_rows)
		return (row);
	if (map[row][col] == 0)
		return (row);
	if (map[row][col] != '1')
		return (0);
	while (row < w->n_rows && map[row][col] == '1')
		row++;
	return (row - 1);
}

int	check_col(char **map, int row, int col, t_game *game)
{
	int	room;
	int	gap;

	if (row == game->n_rows)
		return (row++);
	if (map[row][col] != '1')
		return (0);
	while (row < game->n_rows)
	{
		room = check_room_col(map, row, col, game);
		gap = check_gap_col(map, row, col, game);
		if (gap == 0 && room == 0)
			return (0);
		row = room + gap;
		if (room == gap)
			row = room;
	}
	return (1);
}

int	skip_whitespace_col(char **map, int col, t_game *game)
{
	int	row;

	row = 0;
	while (row < game->n_rows && map[row][col] == ' ')
		row++;
	return (row);
}