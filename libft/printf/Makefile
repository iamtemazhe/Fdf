# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2019/03/15 20:50:33 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_printf.c	itoa_base.c				output.c		\
		printstr.c	numeric_processing.c	types_analis.c	\
		patoi.c

INCL= ../includes/
OBJ = $(SRC:.c=.o)
CFLAGS+=-O2 -Wall -Wextra -Werror -I $(INCL)

all: $(OBJ)

clean:
	rm -f *.o

re: clean all
