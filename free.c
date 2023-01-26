/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:35:58 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/12 14:07:55 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_me(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->count)
	{
		free(vars->arr[i]);
		free(vars->copy[i]);
		i++;
	}
	free(vars->arr);
	free(vars->copy);
	free(vars);
	exit(0);
	return (0);
}

int	ft_free_copy(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->count)
	{
		free(vars->arr[i]);
		i++;
	}
	free(vars->arr);
	free(vars);
	exit(0);
	return (0);
}

int	ft_free(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->count)
	{
		free(vars->arr[i]);
		free(vars->copy[i]);
		i++;
	}
	free(vars->arr);
	free(vars->copy);
	mlx_destroy_image(vars->mlx, vars->play);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->empty);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->coll);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
	return (0);
}
