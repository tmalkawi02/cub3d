/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:33:54 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;
	size_t				i;

	if (!dest && !src)
		return (0);
	if (n == 0)
		return (dest);
	p_src = src;
	p_dest = dest;
	i = 0;
	while (n > 0)
	{
		p_dest[i] = p_src[i];
		i++;
		n--;
	}
	return (dest);
}

/*
int main()
{
	int n = 5;
	int	dest[n];
	int	src[] = {7, 7, 7, 7, 7};
	int *res = ft_memcpy(dest, src, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
}
*/
