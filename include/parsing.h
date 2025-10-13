/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborel <aborel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:41 by aborel            #+#    #+#             */
/*   Updated: 2025/10/13 15:35:49 by aborel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <fcntl.h>

int	parse_map(char *mapfile, t_game *game);
int	open_map(int *map_fd, char *mapfile);
int	err(char *s, int code);
int	assign_textures(int fd, t_textures *tex);
int	assign_colours(int fd, t_game *game);
int	err(char *s, int code);
int	skip_whitespace(char *s);
int	wordcmp(char *s1, char *s2);
#endif