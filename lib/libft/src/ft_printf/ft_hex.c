/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:22:13 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:51 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief get the length of a pointer in base 16
 *
 * @param p
 * @return int
 */
int	length_of_pointer(uintptr_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

/**
 * @brief prints the pointer in readable base 16 string
 *
 * @param p
 */
void	translate_in_hex(uintptr_t p)
{
	if (p >= 16)
	{
		translate_in_hex(p / 16);
		translate_in_hex(p % 16);
	}
	else if (p <= 9)
	{
		ft_putchar_fd((p + '0'), 1);
	}
	else
	{
		ft_putchar_fd((p - 10 + 'a'), 1);
	}
}

/**
 * @brief print the actual whole pointer in readable
 * base 16 string
 *
 * @param p
 * @return int
 */
int	ft_pointer_in_hex(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
		len += ft_putstr_len("(nil)");
	else
	{
		len += ft_putstr_len("0x");
		translate_in_hex(p);
		len += length_of_pointer(p);
	}
	return (len);
}

int	ft_itohx(unsigned int n)
{
	char				*hex;
	int					len;
	unsigned long long	nb;

	hex = "0123456789abcdef";
	len = 0;
	nb = n;
	if (nb >= 16)
	{
		len += ft_itohx(nb / 16);
		len += ft_itohx(nb % 16);
	}
	else
	{
		len += ft_putchar_len(hex[nb]);
	}
	return (len);
}

int	ft_hex_uppercase(unsigned int n)
{
	char	*hex;
	int		len;
	long	nb;
	char	up_hex;

	hex = "0123456789ABCDEF";
	len = 0;
	nb = n;
	if (nb >= 16)
	{
		len += ft_hex_uppercase(nb / 16);
		len += ft_hex_uppercase(nb % 16);
	}
	else
	{
		up_hex = hex[nb];
		len += ft_putchar_len(up_hex);
	}
	return (len);
}
