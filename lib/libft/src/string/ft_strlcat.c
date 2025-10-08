/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:05:34 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:55:33 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	n;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dsize <= dlen)
		return (dsize + slen);
	n = dsize - dlen - 1;
	if (n > slen)
		n = slen;
	ft_memcpy(dst + dlen, src, n);
	dst[dlen + n] = '\0';
	return (dlen + (slen));
}
