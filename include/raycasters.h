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
# define N_PATH		"./assets/one.xpm"
# define S_PATH		"./assets/two.xpm"
# define E_PATH		"./assets/three.xpm"
# define W_PATH		"./assets/four.xpm"

typedef enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_event;

/*
 * @field int kup w key
 * @field int kdown s key
 * @field int kright d key
 * @field int kleft a key
 * @field rrotate right arrow key
 * @field lrotate left arrow key
 * @field pos_x Player X position (exact)
 * @field pos_y PLayer Y postion (exact)
 * @field dir_x Direction Vector X
 * @field dir_y Direction Vector Y
 * @field plane_x Camera Plane X
 * @field plane_y Camera Plane Y
 */
typedef struct s_player
{
	int		kup;
	int		kdown;
	int		kright;
	int		kleft;
	int		rrotate;
	int		lrotate;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

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
	t_player	*play;
}	t_game;

#endif
