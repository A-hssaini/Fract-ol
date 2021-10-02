# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 18:23:16 by ahssaini          #+#    #+#              #
#    Updated: 2021/09/25 18:23:17 by ahssaini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =  main.c\
		drawing.c\
		control.c\
		init.c\
		fract_calcul.c\
		utils.c\

OBJ = main.o\
	  drawing.o\
	  control.o\
	  init.o\
	  fract_calcul.o\
	  utils.o\


CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS)

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(MLX)

%.o: %.c fractol.h
	$(CC) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
