# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachanai <sachanai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:17:55 by tmalkawi          #+#    #+#              #
#    Updated: 2025/09/22 16:33:31 by sachanai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d
SRC_PATH=src
INITIALIZERS_PATH=initializers
CLEAN_PATH=cleaners
SRC=main.c \

SRC += $(SRC_PATH)/$(INITIALIZERS_PATH)/init_game.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_cam.c \
	   $(SRC_PATH)/$(INITIALIZERS_PATH)/init_textures.c \

SRC += $(SRC_PATH)/$(CLEAN_PATH)/clean_game.c

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
