/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:00 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:43 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j]
			&& big[i + j]
			&& i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}

/*
#include "libft.h"
int main(int ac, char **av)
{
	(void) ac;
	printf("ft_strnstr=%s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("STRNSTR=%s\n", strnstr(av[1], av[2], atoi(av[3])));
}
*/
