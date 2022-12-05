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

int    ft_find_it(int x, int y, t_var *vars)
{
    if (x == vars->e_x &&
        y == vars->e_y)
    {
        vars->copy[x][y] = '0';
        ft_error_exit(-7);
    }
    if (vars->arr[x][y] == '0' || vars->arr[x][y] == 'P' || vars->arr[x][y] == 'C')
    {
        vars->copy[x][y] = 'a';
        if (ft_find_it(x + 1, y, vars) == '0' || ft_find_it(x + 1, y, vars) == 'C')
            return 0;
        if (ft_find_it(x, y + 1, vars) == '0' || ft_find_it(x + 1, y, vars) == 'C')
            return 0;
        if (ft_find_it(x - 1, y, vars) == '0' || ft_find_it(x + 1, y, vars) == 'C')
            return 0;
        if (ft_find_it(x, y - 1, vars) == '0' || ft_find_it(x + 1, y, vars) == 'C')
            return 0;
        vars->copy[x][y]  = '1';
    }
    return 0;
}

void    ft_path(t_var *vars)
{
    int x;
    int y;

    x = vars->p_x;
    y = vars->p_y;
    ft_copy_array(vars);
    ft_find_it(x, y, vars);
	ft_printf("**%s\n", vars->copy[0]);
	ft_printf("**%s\n", vars->copy[1]);
	ft_printf("**%s\n", vars->copy[2]);
	ft_printf("**%s\n", vars->copy[3]);
	ft_printf("**%s\n", vars->copy[4]);
}

void    ft_copy_array(t_var *vars)
{
    char	*line;
	int		j;
    int 	fd;

	j = 0;
	fd = open("map_descriptor.ber", O_RDONLY);
	vars->copy = malloc(sizeof(char *) * vars->count);
	line = ft_calloc(1, 1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		vars->copy[j] = line;
		j++;
	}
	free(line);
	close(fd);
}