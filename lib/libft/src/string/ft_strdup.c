/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:11:46 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_allocations(size_t len);

char	*ft_strdup(const char *s)
{
	char		*duplicate_string;
	size_t		i;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	duplicate_string = handle_allocations(size);
	if (!duplicate_string)
		return (NULL);
	i = 0;
	while (i < size)
	{
		duplicate_string[i] = s[i];
		i++;
	}
	duplicate_string[i] = '\0';
	return (duplicate_string);
}

static char	*handle_allocations(size_t len)
{
	char	*alloc;

	alloc = 0;
	if (len == 0)
	{
		alloc = (char *)malloc(sizeof(char));
		if (!alloc)
			return (0);
		alloc[0] = 0;
		return (alloc);
	}
	alloc = (char *)malloc(sizeof(char) * (len + 1));
	if (!alloc)
		return (0);
	return (alloc);
}

/*
#include "libft.h"
int main()
{
	char *str;
 	char *tmp = "lorem ipsum dolor sit amet";

 	str = ft_strdup(tmp);
	printf("\nSuccess ? %s", !strcmp(str, tmp) ? "yes" : "no");
 	free(str);
}
*/
