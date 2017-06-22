# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 13:21:13 by lyoung            #+#    #+#              #
#    Updated: 2017/06/22 12:01:03 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAG = -Wall -Werror -Wextra
MLXFLAG = -framework OpenGL -framework AppKit
MLX = minilibx/libmlx.a
LIBFT = libft/libft.a

FILES = main.c \

SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc -o $(NAME) $(CFLAG) $(OBJ) $(MLX) $(LIBFT) $(MLXFLAG)
	@echo "\033[32m- fractol executable compiled\033[0m"

$(OBJ): %.o: %.c
	@gcc -c $(CFLAG) $< -o $@

$(MLX):
	@make -C minilibx
	@echo "\033[32m- libmlx.a compiled\033[0m"

$(LIBFT):
	@make -C libft

clean:
	@rm -f $(OBJ)
	@echo "\033[31m- fractol object files removed\033[0m"

fclean: clean
	@rm -f fdf
	@make -C minilibx clean
	@echo "\033[31m- libmlx.a removed\033[0m"
	@make -C libft fclean

re: fclean all