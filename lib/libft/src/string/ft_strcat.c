/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:10:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/04/08 16:10:04 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (src == NULL && dst != NULL)
		return (dst);
	if (src != NULL && dst == NULL)
		return ((char *) src);
	dst_len = ft_strlen(dst);
	i = -1;
	while (src && src[++i])
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst);
}
