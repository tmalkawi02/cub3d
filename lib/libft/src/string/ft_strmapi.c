/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:33:41 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mapped;

	mapped = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapped)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}

/*
char	callback(unsigned int n, char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('t');
	else if (n > 90)
		return ('o');
	return ('f');
}
*/

/*
int main()
{
	char *str = "JaImeE LeS ManGas zxksadkaskjdhk";
	char *mapped;
	printf("before -> %s\n", str);
	mapped = ft_strmapi(str, &callback);
	printf("after -> %s\n", mapped);
	free(mapped);
}
*/
