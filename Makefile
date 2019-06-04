# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2019/03/16 18:20:26 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC  = fdf.c drawing.c img_params.c inp_keyboard.c inp_mouse.c put_image.c

INCL = libft/includes/
MLXI = minilibx_macos/

LIB  = libft/
MLX  = minilibx_macos/

FLG  = -Wall -Wextra -Werror

FRAEM= -framework OpenGL -framework AppKit

OBJ  = $(SRC:.c=.o)
CFLAGS+=-O2 -I $(INCL) -I $(MLXI) $(FLG)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB) fclean && make -C $(LIB)
	@make -C $(MLX) re
	gcc -O2 -o $(NAME) $(OBJ) -I $(INCL) -I $(MLXI) -L $(LIB) -lft -L $(MLX) -lmlx $(FRAEM) $(FLG)

clean:
	rm -f *.o
	make -C $(LIB) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
