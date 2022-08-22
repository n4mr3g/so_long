# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 05:34:19 by gpiccion          #+#    #+#              #
#    Updated: 2022/08/22 01:36:40 by gpiccion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############		VARIABLES		##############

NAME			=	so_long

LIBS_DIR		=	./libs/
SRC_DIR			=	./src/

MLX				=	$(LIBS_DIR)mlx/libmlx_Linux.a
FT_PRINTF		=	$(LIBS_DIR)libftprintf.a

SRC_NAMES		=	get_next_line.c \
					inits.c \
					draw_floor.c \
					draw_collectibles.c \
					draw_exit.c \
					draw_player.c \
					draw_walls.c \
					load_map.c \
					enemies.c \
					player_controller.c \
					error_mgmt.c \
					main.c


SRC				=$(addprefix $(SRC_DIR), $(SRC_NAMES))
OBJ				=${SRC:.c=.o}

INCLUDES		=	-I./libs/libftprintf/includes \
					-I./libs/libftprintf/libft \
					-I./libs/mlx \
					-I./includes

CC				=	cc

CFLAGS			=	-O3 -fsanitize=address -g3 -Wall -Wextra #-Werror

##############		RULES		##############

all: display $(NAME)

$(NAME): $(MLX) $(FT_PRINTF) $(OBJ) 
	$(CC) $(SRC) $(INCLUDES) -o $(NAME) -L./libs/mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -L./libs -lftprintf

$(MLX):
	make -C $(LIBS_DIR)mlx/

$(FT_PRINTF):
	make -C $(LIBS_DIR)libftprintf/

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

display:
	echo "export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0"

clean:
	make clean -C $(LIBS_DIR)mlx
	make clean -C $(LIBS_DIR)libftprintf
	rm -rf $(OBJ)
	
fclean: clean
	make fclean -C $(LIBS_DIR)libftprintf
	rm -rf $(MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re