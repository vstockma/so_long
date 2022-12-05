/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:03 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/25 12:50:05 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(int i)
{
	ft_printf("Error\n");
	if (i == -1)
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
		ft_printf("Invalid map! Not a valid path!");
	exit(1);
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
}