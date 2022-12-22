/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:05:52 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/22 16:25:53 by vstockma         ###   ########.fr       */
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
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_mlx
{
	void	*play;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*empty;
	
}	t_mlx;

typedef struct s_var
{
	int		count;
	int		length;
	int		exit_count;
	int		start_count;
	int		collectible_count;
	int		index;
	int		num;
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
	t_mlx	p;
}	t_var;

char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *str);

int		ft_printf(const char *str, ...);
int		ft_putc(char c);
int		ft_puts(va_list args);
int		ft_putdi(va_list args);
void	ft_putchar(char c);
int		ft_putu(va_list args);
int		ft_putxlower(va_list args);
int		ft_putxupper(va_list args);
int		ft_putp(va_list args);

//get_next_line
char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

//so_long.c
void	ft_error_check(t_var *vars);	//calling every funtion of "error_check.c" -> error handling
void	linecount(int fd, t_var *vars);	//counting how many line the map has
void	put_arr(int fd, t_var *vars);	//putting each line in a 2D array

//error_check.c
void	ft_check_rect(t_var *vars); 	//checking if its retangular
void	ft_check_map(t_var *vars);		//checking if there are only 1, 0, E, C and P and the right amount of each
void	ft_counts(t_var *vars);			//function which calls the error message depending on the amount of E, P and C
void	ft_check_walls(t_var *vars);	//checking if the map is surounded by walls
void	ft_unnetig(t_var *vars);		//subfunction of "ft_check_map" cause of lines

//error_message.c
void	ft_error_exit(int i, t_var *vars);			//error messages
void	init_vars(t_var *vars);			//initialising vars of my list
void	ft_free_all(t_var *vars);		//free memory
int		ft_checkfile(char *str);			//checking for ".ber" file

//pathfinding.c
void    ft_path(t_var *vars);			//
void    ft_copy_array(t_var *vars);
int    ft_find_it(int x, int y, t_var *vars);

//window.c
void	ft_mlx(t_var vars);
int		key_hook(int keycode, t_var *vars);
void	ft_move(t_var *vars, int line, int col, int key);
int	ft_update(t_var *vars);
int	ft_check_move(t_var *vars, int line, int col, int key);

//image.c
void    ft_put_xpm(t_var *vars);
void    ft_put_image(t_var *vars);
void	ft_extantion(t_var *vars);

#endif