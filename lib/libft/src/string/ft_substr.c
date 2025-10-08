/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:47 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:55 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_allocations(const char *s, unsigned int start, size_t len);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*allocated;
	size_t	max_size;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	max_size = 32767;
	if (len > max_size)
		len = ft_strlen(s);
	allocated = handle_allocations(s, start, len);
	if (!allocated)
		return (0);
	j = 0;
	i = start;
	while (j < len && s[i])
	{
		allocated[j] = s[i];
		j++;
		i++;
	}
	allocated[j] = '\0';
	return (allocated);
}

static char	*handle_allocations(const char *s, unsigned int start, size_t len)
{
	char	*alloc;

	alloc = 0;
	if (start >= ft_strlen(s))
	{
		alloc = malloc(sizeof(char));
		if (!alloc)
			return (0);
		return (alloc);
	}
	alloc = (char *)malloc((len + 1));
	if (!alloc)
		return (0);
	return (alloc);
}

/*
#include "libft.h"
int main(int ac, char **av)
{
	if (ac > 3)
	{
		char *test = ft_substr(av[1], atoll(av[2]), atoll(av[3]));
		for (int i = 0; test[i]; i++)
			printf("test[%d]=%c\n", i, test[i]);
		printf("substr=%s", test);
		free(test);
	}
}
*/
