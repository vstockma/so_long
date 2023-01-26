/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:15:45 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/13 13:14:05 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_var *vars)
{
	vars->count = 0;
	vars->length = 0;
	vars->exit_count = 0;
	vars->start_count = 0;
	vars->collectible_count = 0;
	vars->p_x = 0;
	vars->p_y = 0;
	vars->e_x = 0;
	vars->e_y = 0;
	vars->index = 0;
	vars->num = 0;
	vars->find_val = 0;
	vars->moves = 0;
	vars->end = 0;
}

void	ft_copy_array(t_var *vars)
{
	char	*line;
	int		j;
	int		fd;

	j = 0;
	fd = open(vars->file, O_RDONLY);
	vars->copy = malloc(sizeof(char *) * vars->count);
	while (j < vars->count)
	{
		line = get_next_line(fd);
		vars->copy[j] = line;
		j++;
	}
	close(fd);
}

int	ft_find_it(int x, int y, t_var *vars)
{
	if (x == vars->e_x && y == vars->e_y)
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
		ft_error_mess(-7, vars);
}
