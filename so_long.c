/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:44:44 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/20 14:03:52 by vstockma         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		fd;
	t_var	vars;

	if (ac != 2)
		return (0);
	if (ft_checkfile(av[1]) == 1)
		return(0);
	fd = open(av[1], O_RDONLY);
	init_vars(&vars);
	put_arr(fd, &vars);
	ft_error_check(&vars);
	if (vars.arr != NULL)
	{
		ft_mlx(vars);
	}
	exit(1);
	close(fd);
	return (0);
}
