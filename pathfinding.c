/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:15:45 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/30 15:15:49 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_it(int x, int y, t_var *vars)
{
	if (x == vars->e_x
		&& y == vars->e_y)
	{
		vars->copy[y][x] = '0';
		return (0);
	}
	if (vars->copy[y][x] == '0' || vars->copy[y][x] == 'P'
		|| vars->copy[y][x] == 'C')
	{
		vars->copy[y][x] = 'a';
		if (ft_find_it(x + 1, y, vars) == 0)
			return (0);
		if (ft_find_it(x, y + 1, vars) == 0)
			return (0);
		if (ft_find_it(x, y - 1, vars) == 0)
			return (0);
		if (ft_find_it(x - 1, y, vars) == 0)
			return (0);
		vars->copy[y][x] = '1';
	}
	return (1);
}

void	ft_path(t_var *vars)
{
	int	x;
	int	y;

	x = vars->p_x;
	y = vars->p_y;
	ft_copy_array(vars);
	vars->find_val = ft_find_it(x, y, vars);
	if (vars->find_val == 1)
		ft_error_exit(-7, vars);
	free(vars->copy);
}

void	ft_copy_array(t_var *vars)
{
	char	*line;
	int		j;
	int		fd;

	j = 0;
	fd = open("map_descriptor.ber", O_RDONLY);
	vars->copy = malloc(sizeof(char *) * vars->count);
	while (j < vars->count)
	{
		line = get_next_line(fd);
		vars->copy[j] = line;
		j++;
	}
	close(fd);
}
