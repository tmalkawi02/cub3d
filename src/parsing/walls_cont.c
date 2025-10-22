/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:28:11 by aborel            #+#    #+#             */
/*   Updated: 2025/10/22 17:38:22 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "parsing.h"
#include "libft.h"

int	check_room_col(char **map, int row, int col)
{
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		row++;
	if (map[row][col] != '0')
		return (0);
	while (map[row][col] == '0')
		row++;
	if (map[row][col] = 0)
		return (col);
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		row++;
	return (row - 1);
}

int	check_gap_col(char **map, int row, int col)
{
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		row++;
	if (map[row][col] != ' ')
		return (0);
	while (map[row][col] == ' ')
		row++;
	if (map[row][col] = 0)
		return (col);
	if (map[row][col] != '1')
		return (0);
	while (map[row][col] == '1')
		row++;
	return (row - 1);
}

int	check_col(char **map, int row, int col)
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
		row += room + gap;
	}
	return (1);
}

int	skip_whitespace_col(char **map)
{
	int	col;

	col = 0;
	while (map[0][col] == ' ')
		col++;
	return (col);
}