/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:58:31 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 13:58:31 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define MAX_ARGS 2

int	main(int ac, char **av)
{
	(void) av;
	if (ac != MAX_ARGS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
