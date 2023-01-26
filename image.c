/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:48:53 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/12 14:08:00 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_xpm(t_var *vars)
{
	int	collum;
	int	line;

	collum = 50;
	line = 50;
	vars->coll = mlx_xpm_file_to_image(vars->mlx, "./img/coll.xpm", &collum,
			&line);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm", &collum,
			&line);
	vars->play = mlx_xpm_file_to_image(vars->mlx, "./img/player.xpm", &collum,
			&line);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm", &collum,
			&line);
	vars->empty = mlx_xpm_file_to_image(vars->mlx, "./img/empty.xpm", &collum,
			&line);
}

void	ft_put_image(t_var *vars)
{
	vars->num = 0;
	vars->lin = 0;
	while (vars->arr[vars->num] != NULL)
	{
		vars->index = 0;
		vars->col = 0;
		while (vars->arr[vars->num][vars->index] != '\0')
		{
			if (vars->arr[vars->num][vars->index] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->exit, vars->col, vars->lin);
			else if (vars->arr[vars->num][vars->index] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->coll, vars->col, vars->lin);
			else
				ft_extantion(vars);
			vars->index++;
			vars->col += 50;
		}
		vars->num++;
		vars->lin += 50;
	}
}

void	ft_extantion(t_var *vars)
{
	if (vars->arr[vars->num][vars->index] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->play,
			vars->col, vars->lin);
	else if (vars->arr[vars->num][vars->index] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
			vars->col, vars->lin);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty,
			vars->col, vars->lin);
}

int	ft_update(t_var *vars)
{
	ft_put_image(vars);
	return (0);
}
