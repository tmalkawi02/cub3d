/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:36 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc((size + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		joined[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	joined[size] = '\0';
	return (joined);
}

/*
int main(int ac, char **av)
{
	if (ac > 2)
	{
		char *joined = ft_strjoin(av[1], av[2]);
		printf("joined=%s\n", joined);
	}
}
*/
