/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:42:08 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/20 09:42:08 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasters.h"

unsigned int	render_pixel_texture(unsigned int x,
			unsigned int y, t_texture *tex)
{
	char	*pixel_index;

	if (x < 0 || y < 0
		|| x >= (unsigned int)tex->width || y >= (unsigned int)tex->height)
		return (0);
	pixel_index = tex->addr + (y * tex->len_line + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel_index);
}
