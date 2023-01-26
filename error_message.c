/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:03 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/13 13:59:43 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(int i, t_var *vars)
{
	(void)vars;
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
	else if (i == -8)
		ft_printf("File descriptor Error!");
	ft_free_copy(vars);
}

void	ft_error_mess(int i, t_var *vars)
{
	if (i == -7)
		ft_printf("Invalid map! There is no valid path!");
	ft_free_me(vars);
}

void	ft_first_error(t_var *vars)
{
	ft_printf("Error\nWrong file format!");
	free(vars);
	exit(0);
}

void	ft_counts(t_var *vars)
{
	if (vars->exit_count != 1)
		ft_error_exit(-2, vars);
	if (vars->collectible_count < 1)
		ft_error_exit(-3, vars);
	if (vars->start_count != 1)
		ft_error_exit(-4, vars);
}
