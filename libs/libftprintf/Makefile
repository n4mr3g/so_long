# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 23:46:57 by gpiccion          #+#    #+#              #
#    Updated: 2022/08/21 01:18:20 by gpiccion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############		VARIABLES		##############

NAME 					= ../libftprintf.a
CC						= cc
CFLAGS					= -Wall -Wextra -Werror
INCLUDES				= -I./includes -I$(LIBFT_DIR)
LIBFT_DIR				= ./libft
LIBFT					= $(LIBFT_DIR)/libft.a

SRC						= ft_printf.c format_eval.c conversions.c conversions2.c auxiliary.c auxiliary2.c auxiliary3.c

OBJ						= $(SRC:.c=.o)


##############		RULES		##############

all:					$(NAME) 

$(NAME):				$(LIBFT) $(OBJ)
						ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)/*.o

$(LIBFT):	
						make -C $(LIBFT_DIR)

%.o:					%.c
						echo "Compiling $<"
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:					re

clean:
						rm -f $(OBJ)
						make clean -C $(LIBFT_DIR)

fclean:					clean
						rm -f $(NAME)
						make fclean -C $(LIBFT_DIR)

re:						fclean all

.PHONY: all clean fclean re