/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:40:47 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/03/10 10:28:42 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include "libft.h"
#include "libft.h"
int main()
{
	for (int i = 32; i <= 126; i++) {
		printf("char tested=%c\n", (char) i);		
		if (!isprint(i))
			continue;
		printf("ft_isprint=%d\n", ft_isprint(i));
		printf("isalpha=%d\n", isprint(i));
		printf("\n");
		if (!ft_isprint(i))
			break;
	}
}
*/
