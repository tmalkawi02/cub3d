/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:41 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:49 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char c, const char *set);
static char	*afroml(const char *s1, size_t begin, size_t length);

char	*ft_strtrim(const char *s1, const char *set)
{
	int	j;
	int	i;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set))
		i++;
	while (j >= 0 && is_in_set(s1[j], set))
		j--;
	return (afroml(s1, i, j - (i - 1)));
}

static char	*afroml(const char *s1, size_t begin, size_t length)
{
	char	*s;
	size_t	i;

	if (length <= 0 || begin >= ft_strlen(s1))
		return (ft_strdup(""));
	s = ft_calloc(length + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < length)
	{
		s[i] = s1[begin + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	is_in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*
int main(int ac, char **av)
{
	if (ac > 2)
	{
		char *test = ft_strtrim(av[1], av[2]);
		printf("res=%s", test);
		free(test);
	}
}
*/
