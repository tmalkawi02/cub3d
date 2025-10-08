/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:22:13 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
#include "libft.h"
#include "libft.h"
int main()
{
	for (int i = 'A'; i <= 'z'; i++) {
		if (!isalpha(i))
			continue;
		printf("ft_isalpha=%d\n", ft_isalpha(i));
		printf("char tested=%c\n", (char) i);		
		printf("isalpha=%d\n", isalpha(i));
		printf("\n");
		if (!ft_isalpha(i))
			break;
	}
}
*/
