/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:00:27 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			size;
	unsigned char	*ps;

	if (c > 256)
		c = c - 256;
	ps = (unsigned char *)s;
	size = ft_strlen(s);
	if (!s[0] && (unsigned char)c)
		return (0);
	else if (s[0] == '\0')
		return ((char *)ps);
	while (*s)
		s++;
	while (*s != (unsigned char) c && size > 0)
	{
		s--;
		size--;
	}
	if (*s != (unsigned char) c)
		return (0);
	return ((char *) s);
}

/*
#include "libft.h"
#include "libft.h"
int main()
{
	printf("res=%s\n", ft_strrchr("teste", 'e'));
	printf("res=%s\n", strrchr("teste", 'e'));
}
*/
