/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:11:38 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/03/08 16:14:24 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*allocated;

	allocated = malloc(size * nmemb);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, nmemb * size);
	return (allocated);
}

/*
int main(void)
{
	char size[1024];
	char nmemb[1024];
	fgets(size, 1024, stdin);
	fgets(nmemb, 1024, stdin);
	printf("passed to stdin size => %d\n", atoi(size));
	printf("passed to stdin nmemb => %d\n", atoi(nmemb));
	size_t *test_1 = ft_calloc(atoll(nmemb), atoll(size));
	size_t *test_2 = calloc(atoll(nmemb), atoll(size));

	for (int i = 0; i < atoll(size); i++)
		printf("ft_calloc=%ld\n", test_1[i]);
	for (int i = 0; i < atoll(size); i++)
		printf("calloc=%ld\n", test_2[i]);
	free(test_1);
	free(test_2);
}
*/
