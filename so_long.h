/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:05:52 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/13 14:00:20 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_var
{
	int		count;
	int		length;
	int		exit_count;
	int		start_count;
	int		collectible_count;
	int		index;
	int		num;
	char	*file;
	char	**arr;
	char	**copy;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		find_val;
	char	*line;
	void	*mlx;
	void	*win;
	int		moves;
	int		lin;
	int		col;
	int		end;
	void	*play;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*empty;
}			t_var;

//so_long.c
void	ft_error_check(t_var *vars);
void	linecount(int fd, t_var *vars);
void	put_arr(int fd, t_var *vars);

//error_check.c
void	ft_check_rect(t_var *vars);
void	ft_check_map(t_var *vars);
void	ft_unnetig(t_var *vars);
void	ft_check_walls(t_var *vars);
int		ft_checkfile(char *str);

//error_message.c
void	ft_error_exit(int i, t_var *vars);
void	ft_error_mess(int i, t_var *vars);
void	ft_first_error(t_var *vars);
void	ft_counts(t_var *vars);

//pathfinding.c
void	init_vars(t_var *vars);
void	ft_copy_array(t_var *vars);
int		ft_find_it(int x, int y, t_var *vars);
void	ft_path(t_var *vars);

//window.c
int		ft_check_move(t_var *vars, int line, int col, int key);
void	ft_move(t_var *vars, int line, int col, int key);
int		key_hook(int keycode, t_var *vars);
void	ft_mlx(t_var *vars);

//image.c
void	ft_put_xpm(t_var *vars);
void	ft_put_image(t_var *vars);
void	ft_extantion(t_var *vars);
int		ft_update(t_var *vars);

//free.c
int		ft_free_me(t_var *vars);
int		ft_free_copy(t_var *vars);
int		ft_free(t_var *vars);

#endif
