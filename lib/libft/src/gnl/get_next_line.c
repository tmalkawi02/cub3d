/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:42:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/02/12 12:06:30 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get the next line object
 *
 * @param fd
 * @return char*
 *
 * @todo: Read file desc to add in linked list
 * @todo: Get line from stash
 * @todo: Clean that stash
 */
char	*get_next_line(int fd)
{
	static t_gnl_list	*stash;
	char				*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free_everything_gnl(&stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	stash_currently_read(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line_by_lf(stash, &line);
	free_stash(&stash);
	if (line && line[0] == '\0')
	{
		free_everything_gnl(&stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * @brief Stash the currently read lines to the list
 * and frees it fro each iterations
 *
 * @param fd
 * @param stash
 */
void	stash_currently_read(int fd, t_gnl_list **stash)
{
	char	*curr;
	int		bytes_returned;

	bytes_returned = 1;
	while (!has_new_line(*stash) && bytes_returned > 0)
	{
		curr = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!curr)
			return ;
		bytes_returned = read(fd, curr, BUFFER_SIZE);
		if (!bytes_returned || bytes_returned < 0)
		{
			free(curr);
			return ;
		}
		curr[bytes_returned] = '\0';
		emplace_in_list(stash, curr, bytes_returned);
		free(curr);
	}
}

/**
 * @brief Emplace the line read from stash_currently_read
 * into the list
 *
 * @param stash
 * @param buf
 * @param bytes_returned
 */
void	emplace_in_list(t_gnl_list **stash, char *buf, int bytes_returned)
{
	t_gnl_list	*new;
	t_gnl_list	*last;
	int			i;

	new = malloc(sizeof(t_gnl_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = (char *)malloc(sizeof(char) * (bytes_returned + 1));
	if (!new->content)
		return ;
	i = -1;
	while (buf[++i] && i < bytes_returned)
		new->content[i] = buf[i];
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last = get_last_node(*stash);
	last->next = new;
}

/**
 * @brief extract the line depending on its line feed
 * and place it in our line
 *
 * @param stash
 * @char line
 *
 * @return void
 */
void	extract_line_by_lf(t_gnl_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	mema_line(stash, line);
	if (*line == NULL)
		return ;
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->content[j])
		{
			if (stash->content[j] == '\n')
			{
				(*line)[i++] = stash->content[j++];
				break ;
			}
			(*line)[i++] = stash->content[j++];
		}
		stash = stash->next;
	}
	(*line)[i] = '\0';
}

/**
 * @brief allocate memory for the supposed next line
 * after the line feed. Therefore it will look for any
 * trailling line feed. Extract the line from it then
 * replace the current stash to the one that have been cleaned
 *
 * @param stash
 *
 * @return void
 */
void	free_stash(t_gnl_list **stash)
{
	int			i;
	int			j;
	t_gnl_list	*rm;
	t_gnl_list	*last;

	rm = malloc(sizeof(t_gnl_list));
	if (!rm || !stash)
		return ;
	rm->next = NULL;
	last = get_last_node(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	rm->content = malloc(sizeof(char) * (my_strlen(last->content) - i) + 1);
	if (!rm->content)
		return ;
	j = 0;
	while (last->content[i])
		rm->content[j++] = last->content[i++];
	rm->content[j] = '\0';
	free_everything_gnl(stash);
	*stash = rm;
}
