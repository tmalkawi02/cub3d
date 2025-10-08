/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachanai <sachanai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:33:32 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/08/25 12:54:42 by sachanai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_strnull(const char *s)
{
	if (s == NULL)
		return (true);
	if (s[0] == '\0')
		return (true);
	return (false);
}

