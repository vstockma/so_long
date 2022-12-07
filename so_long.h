/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:05:52 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/05 11:06:02 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

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

//pathfinding.c
void    ft_path(t_var *vars);			//
void    ft_copy_array(t_var *vars);
int    ft_find_it(int x, int y, t_var *vars);

#endif
