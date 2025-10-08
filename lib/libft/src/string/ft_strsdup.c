/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:47 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/03/15 11:01:28 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_strsdup(const char **s)
{
	char	**dupped;
	size_t	len;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	len = ft_strslen(s);
	dupped = malloc((len + 1) * sizeof(char *));
	if (!dupped)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		dupped[i] = ft_strdup(s[i]);
		if (dupped[i] == NULL)
			return (ft_free_tab((void **) dupped), NULL);
	}
	dupped[i] = NULL;
	return (dupped);
}

/*int main(void)*/
/*{*/
/*	char	**splitted = ft_split("jaime les tomates", ' ');*/
/*	char	**dupped = ft_strsdup((const char **)splitted);*/
/**/
/*	if (!splitted)*/
/*		return (1);*/
/*	for (int i = 0; dupped[i]; i++) {*/
/*		printf("dupped[%d] = %s\n", i, dupped[i]);	*/
/*	}*/
/*	return (0);*/
/*}*/
