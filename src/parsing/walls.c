/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:00:08 by aborel            #+#    #+#             */
/*   Updated: 2025/10/22 19:30:03 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "parsing.h"
#include "libft.h"

int	check_room(char **map, int row, int col)
{
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		col++;
	if (map[row][col] != '0' && !is_cardinal(map[row][col]))
		return (0);
	while (map[row][col] == '0' || is_cardinal(map[row][col]))
		col++;
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		col++;
	return (col - 1);
}

int	check_gap(char **map, int row, int col)
{
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		col++;
	if (map[row][col] != ' ')
		return (0);
	while (map[row][col] == ' ')
		col++;
	if (map[row][col] == 0)
		return (col);
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		col++;
	return (col - 1);
}

int	check_row(char **map, int row, int col)
{
	int	room;
	int	gap;

	if (map[row][col] != '1')
		return (0);
	while (map[row][col])
	{
		room = check_room(map, row, col);
		gap = check_gap(map, row, col);
		if (gap == 0 && room == 0)
			return (0);
		col = room + gap;
	}
	return (1);
}

int	check_walls(char **map, t_game *game)
{
	int	ret;
	int	row;
	int	col;
	int	i;

	ret = 0;
	row = 0;
	while (row < game->n_rows)
	{
		i = skip_whitespace(map[row]);
		if (check_row(map, row, i) == 0)
			return (0);
		row++;
	}
	col = 0;
	while (col < game->n_cols)
	{
		i = skip_whitespace_col(map, col, game);
		if (check_col(map, i, col, game) == 0)
			return (0);
		col++;
	}	
	return (1);
}
