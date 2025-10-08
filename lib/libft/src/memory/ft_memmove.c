/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:15:38 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	size_t	i;

	pdest = (char *)dest;
	psrc = (char *)src;
	if (pdest == NULL && psrc == NULL)
		return (NULL);
	i = 0;
	if (pdest > psrc)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	else
	{
		while (n--)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}

/*
#include "libft.h"
#include "libft.h"
#include "libft.h"
int main()
{
	int data[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};
	int count = 10;
	printf("valeurs avant mouvements ->");
	for (int i = 0; i < count; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	void *source = (void *)data;
	void *dest = (void *)(data + 1);
	size_t size = sizeof(int) * count;
	ft_memmove(dest, source, size);
	data[0] = 10;
	printf("valeurs apres mouvement ->");
	for (int i = 0; i < count; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
*/
