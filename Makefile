# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:20:33 by vstockma          #+#    #+#              #
#    Updated: 2022/12/07 15:12:26 by vstockma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out

SRC = so_long.c error_check.c error_message.c pathfinding.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

CC = cc

RM = rm -f

MLX_PATH = minilibx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -lXext -lX11 -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

.PHONY: all clean fclean re

all: comp $(NAME)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

comp:
	@echo $(B)
	make -C $(LIBFT_PATH) all
	@echo $(B)
	make -C $(MLX_PATH) all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) fclean
	$(RM) $(NAME)

re: fclean all