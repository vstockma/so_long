/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:44:44 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/12 12:42:11 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_check(t_var *vars)
{
	ft_check_rect(vars);
	ft_check_map(vars);
	ft_counts(vars);
	ft_check_walls(vars);
	ft_path(vars);
}

void	linecount(int fd, t_var *vars)
{
	int		n;
	char	*line;

	n = 1;
	line = malloc(2);
	while (n > 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n == -1)
		{
			
			ft_error_exit(-8, vars);
		}
		line[n] = '\0';
		if (ft_strchr(line, '\n'))
			vars->count++;
	}
	vars->count++;
	free(line);
	line = NULL;
	close(fd);
}

void	put_arr(int fd, t_var *vars)
{
	int	j;

	j = 0;
	linecount(fd, vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	vars->arr = malloc(sizeof(char *) * (vars->count + 1));
	while (j < vars->count)
	{
		vars->arr[j] = get_next_line(fd);
		j++;
	}
	vars->arr[vars->count] = NULL;
	close(fd);
}

int	main(void)
{
	int		fd;
	t_var	vars;

	init_vars(&vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	put_arr(fd, &vars);
	ft_error_check(&vars);
	ft_printf("%s\n", vars.arr[0]);
	ft_printf("%s\n", vars.arr[1]);
	ft_printf("%s\n", vars.arr[2]);
	ft_printf("%s\n", vars.arr[3]);
	ft_printf("%s\n", vars.arr[4]);
	ft_free_all(&vars);
	close(fd);
	return (0);
	
}
