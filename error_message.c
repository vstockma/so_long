/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:03 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/20 13:39:43 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(int i, t_var *vars)
{
	ft_printf("Error\n");
	if (i == 0)
		ft_printf("Initialisation Error\n");
	else if (i == -1)
		ft_printf("Invalid map! Wrong characters!\n");
	else if (i == -2)
		ft_printf("Invalid map! Wrong amount of exits!");
	else if (i == -3)
		ft_printf("Invalid map! Not enough collectibles!");
	else if (i == -4)
		ft_printf("Invalid map! Wrong amount of starts!");
	else if (i == -5)
		ft_printf("Invalid map! Not rectangular!");
	else if (i == -6)
		ft_printf("Invalid map! Not surrounded by walls!");
	else if (i == -7)
		ft_printf("Invalid map! There is no valid path!");
	else if (i == -8)
		ft_printf("File descriptor Error!");
	free(vars->arr);
	//ft_free_all(&vars);
}

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

void	ft_free_all(t_var *vars)
{
	int i;

	i = 0;
	while (i < vars->count)
	{
		free(vars->arr[i]);
		free(vars->copy[i]);
		i++;
	}
	free(vars->arr);
	free(vars->copy);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

int	ft_checkfile(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i++] != 'b')
				return (1);
			if (str[i++] != 'e')
				return (1);
			if (str[i++] != 'r')
				return (1);
			if (str[i] != '\0')
				return (1);
		}
		else
			i++;
	}
	return (0);
}