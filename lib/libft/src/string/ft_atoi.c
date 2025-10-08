/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:05 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:11 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_whitespace(int c);

static int	check_whitespace(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while (check_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '+' && ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += (nptr[i] - '0') % 10;
		i++;
	}
	return (res * sign);
}

/*
#include "libft.h"
int main(int ac, char **av)
{
	(void) ac;
	printf("ft_atoi=%d\n", ft_atoi(av[1]));
	printf("ATOI=%d\n", atoi(av[1]));
}
*/
