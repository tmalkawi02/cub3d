/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:46:54 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/02/12 12:06:44 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Gets the length of a given string
 *
 * @param s
 * @return size_t
 */
size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Check if the content of a linked list
 * has new line. e.g. "\n"
 *
 * @param stash
 * @return int
 */
int	has_new_line(t_gnl_list *stash)
{
	int			i;
	t_gnl_list	*curr;

	if (!stash)
		return (0);
	curr = get_last_node(stash);
	i = 0;
	while (curr->content[i])
	{
		if (curr->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Get the last node object
 *
 * @param stash
 * @return t_gnl_list*
 */
t_gnl_list	*get_last_node(t_gnl_list *stash)
{
	t_gnl_list	*curr;

	curr = stash;
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

/**
 * @brief memory allocate (mema) the line needed
 * to emplace in the stash
 *
 * @param stash
 * @param line
 *
 * @return void
 */
void	mema_line(t_gnl_list *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/**
 * @brief litteraly frees everything,
 * although it works fine without it 
 * it will silence any memory leaks
 *
 * @param stash
 *
 * @return void
 */
void	free_everything_gnl(t_gnl_list **stash)
{
	t_gnl_list	*current;
	t_gnl_list	*next;

	current = *stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*stash = NULL;
}
