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
        return 1;
    }
    if (vars->arr[x][y] == 0)
    {
        if (ft_find_it(x + 1, y, &vars) == 0)
            return 1;
        if (ft_find_it(x, y + 1, &vars) == 0)
            return 1;
        if (ft_find_it(x - 1, y, &vars) == 0)
            return 1;
        if (ft_find_it(x, y - 1, &vars) == 0)
            return 1;
    }
}

void    ft_path(t_var *vars)
{
    int x;
    int y;

    x = vars->p_x;
    y = vars->p_y;
    while ()
    {
        ft_find_it(x, y, &vars)
    }
}