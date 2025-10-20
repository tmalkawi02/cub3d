# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:27:03 by tmalkawi          #+#    #+#              #
#    Updated: 2025/10/13 13:27:03 by tmalkawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d
SRC_PATH=src
INITIALIZERS_PATH=initializers
HANDLERS_PATH=handlers
CLEAN_PATH=cleaners
RAYCASTERS_PATH=raycasters
HELPERS_PATH=helpers
SRC=main.c \

SRC += $(SRC_PATH)/$(INITIALIZERS_PATH)/init_game.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_cam.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_textures.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_player.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_wall.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_ray.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_px_data.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_player_backward_direction.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_player_right_direction.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_player_left_direction.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_player_forward_direction.c

SRC += $(SRC_PATH)/$(CLEAN_PATH)/clean_game.c

SRC += $(SRC_PATH)/$(HELPERS_PATH)/get_map.c \
	   $(SRC_PATH)/$(HELPERS_PATH)/is_wall.c

SRC += $(SRC_PATH)/$(HANDLERS_PATH)/k_press.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/k_release.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_move.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_move_right.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_move_left.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_move_up.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_move_down.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_rotate_left.c \
	   $(SRC_PATH)/$(HANDLERS_PATH)/player_rotate_right.c

SRC += $(SRC_PATH)/$(RAYCASTERS_PATH)/render_loop.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/set_ray_values.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/perform_dda.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/calculate_wall.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/render_pixel.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/render_pixel_texture.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/select_wall_texture.c \
	   $(SRC_PATH)/$(RAYCASTERS_PATH)/calculate_texture_coord.c

LIB_PATH=lib
COMPILER=clang
INCLUDES = -I./lib/mlx/ -I/usr/include -I./include/ -I./lib/libft/include/
LIBRARIES = -L$(LIB_PATH)/libft/build/bin/ -L$(LIB_PATH)/mlx/ -L/usr/lib -lft -lmlx -Ilmx -lXext -lX11 -lm -lz
COMPILER_ARGS=-Wall -Wextra -Werror -g3 -O3
OBJECTS=$(addprefix obj/, $(patsubst %.c, %.o, $(SRC)))


all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIB_PATH)/libft/
	make -C $(LIB_PATH)/mlx/
	$(COMPILER) $(COMPILER_ARGS) $(MAIN) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $@

obj/%.o: %.c
	@mkdir -p $(dir $(NAME))
	@mkdir -p $(dir $(OBJECTS))
	$(COMPILER) $(COMPILER_ARGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf obj/
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
