/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:03:50 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:28 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	callback(unsigned int n, char *c)
{
	write(1, c, (ft_strlen(c) - n) + 1);
}

int main()
{
	char *str = "jaimelestomates";
	printf("before -> %s\n", str);
	ft_striteri(str, &callback);
	printf("after -> %s\n", str);
}
*/
