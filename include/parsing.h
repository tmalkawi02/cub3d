/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:41 by aborel            #+#    #+#             */
/*   Updated: 2025/10/22 17:39:04 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct s_wall
{
	char	**map;
	int		row;
	int		col;
	int		n_rows;
	int		n_cols;
	int		error;
	int		start;
}	t_wall;

int		parse_map(char *mapfile, t_game *game);
int		open_map(int *map_fd, char *mapfile);
int		initialise_textures(t_textures *tex);
int		parsing_err(char *s, t_game *game, int fd);
int		assign_textures(int fd, int *lines_read, t_game *game);
int		assign_colours(unsigned long *ptr, char *line);
int		is_whitespace(char c);
int		skip_whitespace(char *s);
int		wordcmp(char *s1, char *s2);
char	*next_word(char *s);
void	free_assign_textures(char *line, char *id);
int		check_textures(t_game *game);
void	clean_game(t_game *game);
char	**map_error(char *line, char **map);
int		valid_line(char *s, int *pos);
char	*copy_wout_nl(char *src, char *dest, int len);
int		check_walls(char **map, t_wall *wall);
int		check_col(char **map, int row, int col);
int		skip_whitespace_col(char **map);

#endif