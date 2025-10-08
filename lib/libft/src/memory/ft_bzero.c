/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:29:00 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include "libft.h"
int main()
{
	char str[0xF00];
 	char str2[0xF00];

 	memset(str, 'a', 0xF00);
 	memset(str2, 'a', 0xF00);
 	bzero(str, 20);
 	ft_bzero(str2, 20);
 	if (!memcmp(str, str2, 0xF00))
 		printf("yes\n");
	printf("no\n");
}
*/
