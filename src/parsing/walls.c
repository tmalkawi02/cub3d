/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:02:07 by aborel            #+#    #+#             */
/*   Updated: 2025/10/20 17:32:56 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "libft.h"
#include "parsing.h"

void outline_east(t_wall *w)
{
	if (w->col == w->start && w->row == 0)
		return ;
	if (w->row > 0)
	{
		while (w->map[w->row - 1][w->col] == ' ')
		{
			if (w->map[w->row][w->col] == '1')
				w->col++;
		}
	}
	else if (w->row == 0)
	{
		while (w->map[w->row][w->col] == '1')
			w->col++;
	}
	if (w->map[w->row][w->col] == '0')
		w->col--;
	if (w->row > 0 && w->map[w->row - 1][w->col] == '1')
		outline_north(w);
	else if (w->row < w->n_rows && w->map[w->row + 1][w->col] == '1')
		outline_south(w);
	else
		w->error = 1;
	return ;
}

void outline_west(t_wall *w)
{
	if (w->col == w->start && w->row == 0)
		return ;
	if (w->row < w->n_rows - 1)
	{
		while (w->map[w->row + 1][w->col] == ' ')
		{
			if (w->map[w->row][w->col] == '1')
				w->col--;
		}
	}
	else if (w->row == w->n_rows - 1)
	{
		while (w->col >= 0 && w->map[w->row][w->col] == '1')
			w->col--;
	}
	if (w->map[w->row][w->col] == '0')
		w->col++;
	if (w->row < w->n_rows - 1 && w->map[w->row + 1][w->col] == '1')
		outline_south(w);
	else if (w->row > 0 && w->map[w->row - 1][w->col] == '1')
		outline_north(w);
	else
		w->error = 1;
	return ;
}

void outline_north(t_wall *w)
{
	if (w->col == w->start && w->row == 0)
		return ;
	if (w->col > 0)
	{
		while (w->map[w->row][w->col - 1] == ' ')
		{
			if (w->map[w->row][w->col] == '1')
				w->row--;
		}
	}
	else if (w->col == 0)
	{
		while (w->row >= 0 && w->map[w->row][w->col] == '1')
			w->row--;
	}
	if (w->map[w->row][w->col] == '0')
		w->row++;
	if (w->row > 0 && w->map[w->row][w->col - 1] == '1')
		outline_west(w);
	else if (w->row < w->n_rows && w->map[w->row][w->col + 1] == '1')
		outline_east(w);
	else
		w->error = 1;
	return ;
}

void outline_south(t_wall *w)
{
	if (w->col == w->start && w->row == 0)
		return ;
	if (w->col < w->n_cols - 1)
	{
		while (w->map[w->row][w->col + 1] == ' ')
		{
			if (w->map[w->row][w->col] == '1')
				w->row++;
		}
	}
	else if (w->col == w->n_cols - 1)
	{
		while (w->col > w->n_cols && w->map[w->row][w->col] == '1')
			w->row++;
	}
	if (w->map[w->row][w->col] == '0')
		w->row--;
	if (w->row < w->n_rows && w->map[w->row][w->col + 1] == '1')
		outline_east(w);
	else if (w->row > 0 && w->map[w->row][w->col - 1] == '1')
		outline_west(w);
	else
		w->error = 1;
	return ;
}
/**
 * @brief checks that the map is surrounded by walls
 * 
 * @param fd: map file
 * @return int: 0 if no walls, 1 if valid walls
 */
int	check_walls(char **map, t_wall *wall)
{
	wall->map = map;
	wall->row = 0;
	wall->col = skip_whitespace(map[0]);
	wall->start = wall->col;
	if (map[wall->row][wall->col] != '1')
		return (0);
	wall->error = 0;
	outline_east(wall);
	if (wall->error)
		return (0);
	else
		return (1);
}
