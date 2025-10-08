/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:23 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:17 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_number(long n);
static char	*preallocate(int len);
static char	*divide_chars(int i, int size, long nb, char *str);

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		size;
	int		i;

	nb = n;
	size = len_number(nb);
	str = preallocate(size);
	if (!str)
		return (NULL);
	i = 0;
	if (nb == 0)
		str[0] = '0';
	str[len_number(n)] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		i++;
	}
	return (divide_chars(i, size, nb, str));
}

static char	*divide_chars(int i, int size, long nb, char *str)
{
	while (size-- > i)
	{
		str[size] = ((nb % 10) + '0');
		nb /= 10;
	}
	return (str);
}

int	len_number(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*preallocate(int len)
{
	char	*tab;

	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	return (tab);
}

/*
int	main()
{
	char *test_ft = ft_itoa(-7458);
	for (int i = 0; i < 10; i++) {
		if (test_ft[i] == '\0')
		{
			printf("test_ft[%d] -> \\0\n", i);
			continue;
		}
		printf("test_ft[%d] -> %c\n", i, test_ft[i]);
	}
	free(test_ft);
}
*/
