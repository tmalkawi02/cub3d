/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:01:28 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_formats(va_list args, const char format);

/**
 * @brief handle the format specifiers of the printf function
 *
 * @param args
 * @param format
 * @return int
 */
static int	handle_formats(va_list args, const char format)
{
	int	c_printed;

	c_printed = 0;
	if (format == 'c')
		c_printed += ft_putchar_len(va_arg(args, int));
	else if (format == 's')
		c_printed += ft_putstr_len(va_arg(args, char *));
	else if (format == '%')
		c_printed += ft_putchar_len('%');
	else if (format == 'd')
		c_printed += ft_putnbr_len(va_arg(args, int));
	else if (format == 'i')
		c_printed += ft_putnbr_len(va_arg(args, int));
	else if (format == 'p')
		c_printed += ft_pointer_in_hex(va_arg(args, uintptr_t));
	else if (format == 'u')
		c_printed += ft_putunbr_len(va_arg(args, int));
	else if (format == 'X')
		c_printed += ft_hex_uppercase(va_arg(args, int));
	else if (format == 'x')
		c_printed += ft_itohx(va_arg(args, int));
	return (c_printed);
}

/**
 * @brief my printf function
 *
 * @param s
 * @param ...
 * @return int
 */
int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	count;
	int		i;

	if (!s)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += handle_formats(args, s[i + 1]);
			i++;
		}
		else
			count += ft_putchar_len(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
