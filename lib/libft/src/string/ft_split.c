/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:31 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/02/12 12:12:15 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void		**free_everything(char **s, size_t size);
static size_t	occ_of_words(const char *s, char c);
static char		*word(const char *s, size_t start_word, size_t end_word);
static char		**fill_tab(const char *s, char c, char **tab);

static char	**fill_tab(const char *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	int		len_word;

	i = 0;
	j = 0;
	len_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && len_word < 0 && s[i])
			len_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && len_word >= 0)
		{
			tab[j] = word(s, len_word, i);
			if (!tab[j])
				return ((char **) free_everything(tab, j));
			j++;
			len_word = -1;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

static void	**free_everything(char **s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	occ_of_words(const char *s, char c)
{
	size_t	counter;
	int		trigger;
	size_t	i;

	counter = 0;
	trigger = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			counter++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (counter);
}

static char	*word(const char *s, size_t start_word, size_t end_word)
{
	char	*word;
	size_t	i;

	if (start_word >= end_word)
		return (NULL);
	word = malloc((end_word - start_word + 1) * sizeof(char));
	if (!word)
	{
		free(word);
		word = NULL;
		return (NULL);
	}
	i = 0;
	while (start_word < end_word)
		word[i++] = s[start_word++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**strs_tab;
	int		count;

	if (!s)
		return (NULL);
	count = occ_of_words(s, c) + 1;
	strs_tab = malloc(count * sizeof(char *));
	if (!strs_tab)
		return (NULL);
	if (count == 0)
	{
		strs_tab[0] = NULL;
		return (strs_tab);
	}
	return (fill_tab(s, c, strs_tab));
}

/*
int main()
{
	char *seq = "hello!";
	char sep = ' ';
	size_t occ = occ_of_words(seq, sep);
	printf("nb words -> %ld\n", occ);
	char **splitted = ft_split(seq, sep);
	for (size_t i = 0; i < occ; i++) {
		printf("splitted[%ld]=%s\n", i, splitted[i]);
	}
	free_everything(splitted, occ);
}
*/
