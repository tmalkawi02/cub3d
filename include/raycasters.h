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

# define WIN_WIDTH	1280.0f
# define WIN_HEIGHT	720.0f
# define N_PATH		"./assets/one.xpm"
# define S_PATH		"./assets/two.xpm"
# define E_PATH		"./assets/three.xpm"
# define W_PATH		"./assets/four.xpm"
# define CEILING_COL	0x87CEEB
# define FLOOR_COL		0x6b5428	
# ifndef MOVE_SPEED
#  define MOVE_SPEED 0.005f
# endif
# ifndef ROT_SPEED
#  define ROT_SPEED 0.005f
# endif
# ifndef DEBUG
#  define DEBUG 1
# endif

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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_px_data
{
	int		len_line;
	int		endian;
	int		bpp;
	char	*addr;
	void	*img;
}	t_px_data;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_wall;

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
	double	x;
	double	y;
}	t_camera;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_camera	*cam;	
	t_textures	*texs;
	t_player	*play;
	t_wall		*wall;
	t_ray		*ray;
	t_px_data	*px_data;
}	t_game;

unsigned int	render_pixel_texture(unsigned int x,
					unsigned int y, t_texture *tex);

t_texture		*select_wall_texture(t_game *game, t_ray *ray);

void			calculate_texture_coord(t_ray *ray,
					t_wall *wall, t_texture *tex);

int				render_loop(t_game *game);

void			set_ray_values(t_game *game, int x);

void			perform_dda(t_game *game);

void			draw_textured_walls(t_game *game, t_wall *wall,
					t_texture *tex, int x);

void			render_pixel(t_game *game, unsigned int x,
					unsigned int y, int color);

void			calculate_wall(t_game *game);

void			draw_wall_strip(t_game *game, t_ray *ray, t_wall *wall, int x);

#endif
