/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:37:58 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:50 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief prints an integer in stdin but this time
 * we also count the bytes printed
 *
 * @param n
 * @return int
 */
int	ft_putnbr_len(int n)
{
	int		len;
	char	*nums;

	nums = ft_itoa(n);
	len = ft_putstr_len(nums);
	free(nums);
	return (len);
}

/**
 * @brief same thing as putnbr_len but we work
 * with unsigned ints/decimals
 *
 * @param n
 * @return int
 */
int	ft_putunbr_len(unsigned int n)
{
	int					len;
	unsigned long long	nb;

	len = 0;
	nb = n;
	if (nb >= 10)
		len += ft_putunbr_len(n / 10);
	len += ft_putchar_len((n % 10) + '0');
	return (len);
}
