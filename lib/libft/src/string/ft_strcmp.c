/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:23:44 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/04/07 08:23:44 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	i = 0;
	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	while (ps1[i] && ps1[i] == ps2[i])
		i++;
	return (ps1[i] - ps2[i]);
}
