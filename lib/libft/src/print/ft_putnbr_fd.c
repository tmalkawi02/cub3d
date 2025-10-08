/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:58:06 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ptn(int nb, int fd);
static void	pt(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	ptn(n, fd);
}

static void	pt(char c, int fd)
{
	write(fd, &c, 1);
}

void	ptn(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb >= 10)
	{
		ptn(nb / 10, fd);
		ptn(nb % 10, fd);
	}
	else if (nb < 10)
	{
		pt(nb + '0', fd);
	}
}

/*
int main()
{
	ft_putnbr_fd(-4785, 1);
}
*/
