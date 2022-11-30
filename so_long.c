/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:44:44 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/17 12:44:46 by vstockma         ###   ########.fr       */
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
	line = ft_calloc(1, 1);
	while (n > 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n == -1)
		{
			free(line);
		}
		if (ft_strchr(line, '\n'))
			vars->count++;
	}
	vars->count++;
	close(fd);
}

void	put_arr(int fd, t_var *vars)
{
	char	*line;
	int		j;

	j = 0;
	linecount(fd, vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	vars->arr = malloc(sizeof(char *) * vars->count);
	line = ft_calloc(1, 1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		vars->arr[j] = line;
		j++;
	}
	free(line);
}

int	main(void)
{
	int		fd;
	t_var	vars;
	int		i;

	i = 0;
	init_vars(&vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	put_arr(fd, &vars);
	ft_error_check(&vars);
	while (i < vars.count)
	{
		ft_printf("%s\n", vars.arr[i]);
		i++;
	}
	close(fd);
	return (0);
}
