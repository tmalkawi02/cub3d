/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:23:54 by aborel            #+#    #+#             */
/*   Updated: 2025/10/20 17:29:47 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"
#include "parsing.h"

char	**map_error(char *line, char **map)
{
	free(line);
	map[0][0] = 0;
	return (map);
}

int	valid_line(char *s, int *pos)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == ' ' || s[i] == '\n')
			i++;
		else if (*pos == 0 && (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E'))
		{
			*pos = 1;
			i++;
		}
		else
			return (0);
	}
	if (s[0] != '1' || s[i - 1] != '1')
		return (0);
	return (i);
}

char	*copy_wout_nl(char *src, char *dest, int len)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = 0;
	while (i < len)
		dest[i++] = ' ';
	free(src);
	return (dest);
}
