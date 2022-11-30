/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:13:32 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/25 11:13:35 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rect(t_var *vars)
{
	int	i;
	int	comp;

	i = 0;
	vars->length = ft_strlen(vars->arr[i]);
	comp = vars->length;
	while (i < vars->count)
	{
		if (vars->arr[i] == NULL)
			break ;
		vars->length = ft_strlen(vars->arr[i]);
		if (vars->length != comp)
			ft_error_exit(-5);
		i++;
	}
}

void	ft_check_map(t_var *vars)
{
	vars->num = 0;
	while (vars->arr[vars->num] != NULL)
	{
		vars->index = 0;
		while (vars->arr[vars->num][vars->index] != '\0')
		{
			if (vars->arr[vars->num][vars->index] == 'E')
			{
				vars->exit_count++;
				vars->exit_pos_x = vars->index;
				vars->exit_pos_y = vars->num;
			}
			else if (vars->arr[vars->num][vars->index] == 'C')
				vars->collectible_count++;
			else
				ft_unnetig(vars);
			vars->index++;
		}
		vars->num++;
	}
}

void	ft_unnetig(t_var *vars)
{
	if (vars->arr[vars->num][vars->index] == 'P')
	{
		vars->start_count++;
		vars->player_pos_x = vars->index;
		vars->player_pos_y = vars->num;
	}
	else if (vars->arr[vars->num][vars->index] != '1' &&
			vars->arr[vars->num][vars->index] != '0' &&
			vars->arr[vars->num][vars->index] != 'E' &&
			vars->arr[vars->num][vars->index] != 'C' &&
			vars->arr[vars->num][vars->index] != 'P')
		ft_error_exit(-1);
}

void	ft_counts(t_var *vars)
{
	if (vars->exit_count != 1)
		ft_error_exit(-2);
	if (vars->collectible_count < 1)
		ft_error_exit(-3);
	if (vars->start_count != 1)
		ft_error_exit(-4);
}

void	ft_check_walls(t_var *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->arr[j] != NULL)
	{
		i = 0;
		while (i < vars->length)
		{
			if (vars->arr[0][i] != '1')
				ft_error_exit(-6);
			else if (vars->arr[vars->count - 1][i] != '1')
				ft_error_exit(-6);
			else if (vars->arr[j][0] != '1' ||
				vars->arr[j][vars->length - 1] != '1')
				ft_error_exit(-6);
			i++;
		}
		j++;
	}
}
