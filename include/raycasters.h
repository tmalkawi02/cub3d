/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:06:55 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/10/08 14:06:55 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTERS_H
# define RAYCASTERS_H

# define WIN_HEIGHT 1280.0f
# define WIN_WIDTH	720.0f

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		len_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_ray_textures {
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;
}	t_textures;

typedef struct s_camera
{
	float	x;
	float	y;
}	t_camera;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_camera	*cam;	
	t_textures	*texs;
}	t_game;

void	clean_game(t_game *game);

void	init_game(t_game *game);

#endif
