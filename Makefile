# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:20:33 by vstockma          #+#    #+#              #
#    Updated: 2022/12/13 12:41:50 by vstockma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out

SRC = so_long.c error_check.c error_message.c pathfinding.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

CC = cc

RM = rm -f

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -lXext -lX11 -lm -lpthread -ldl -fPIE

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

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
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) fclean

re: fclean all