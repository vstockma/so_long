/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:48:53 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/16 12:55:38 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_put_xpm(t_var *vars)
{
    t_mlx   img;
    int     collum;
    int     line;

    collum = 50;
    line = 50;
    img.coll = mlx_xpm_file_to_image(vars->mlx, "./img/coll.xpm", &collum, &line);
    img.exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm", &collum, &line);
    img.play = mlx_xpm_file_to_image(vars->mlx, "./img/player.xpm", &collum, &line);
    img.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm", &collum, &line);
    img.empty = mlx_xpm_file_to_image(vars->mlx, "./img/empty.xpm", &collum, &line);
    ft_put_image(&img, vars);
}

void	ft_put_image(t_mlx *img, t_var *vars)
{
	vars->num = 0;
	while (vars->arr[vars->num] != NULL)
	{
		vars->index = 0;
		while (vars->arr[vars->num][vars->index] != '\0')
		{
			if (vars->arr[vars->num][vars->index] == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win,
                                        img->exit, vars->col, vars->lin);
			else if (vars->arr[vars->num][vars->index] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
                                        img->coll, vars->col, vars->lin);
			else
				ft_extantion(img, vars);
			vars->index++;
            vars->col += 50;
		}
		vars->num++;
        vars->lin += 50;
	}
}

void	ft_extantion(t_mlx *img, t_var *vars)
{
	if (vars->arr[vars->num][vars->index] == 'P')
        mlx_put_image_to_window(vars->mlx, vars->win,
                                img->play, vars->col, vars->lin);
	else if (vars->arr[vars->num][vars->index] == '1')
        mlx_put_image_to_window(vars->mlx, vars->win,
                                img->wall, vars->col, vars->lin);
    else
        mlx_put_image_to_window(vars->mlx, vars->win,
                                img->empty, vars->col, vars->lin);
}