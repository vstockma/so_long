/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:44:44 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/17 12:44:46 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_check(t_var *vars)
{
	int	i;
	int	j;

	j = 0;
	ft_check_rect(vars);
	ft_check_map(vars);
	ft_counts(vars);
	while (vars->arr[j] != NULL)
	{
		i = 0;
		while (vars->arr[j][i] != '\0')
		{
			if (vars->arr[0][i] != '1')
				ft_error_exit(-6);
			else if (vars->arr[vars->count - 1][i] != '1')
				ft_error_exit(-6);
			else if (vars->arr[j][0] != '1' ||
				vars->arr[j][vars->length - 1] != '1')
				ft_error_exit(-6);
			else if (vars->arr[j][i] != '1' && vars->arr[j][i] != '0' &&
				vars->arr[j][i] != 'E'&& vars->arr[j][i] != 'C' &&
				vars->arr[j][i] != 'P')
				ft_error_exit(-1);
			i++;
		}
		j++;
	}
}

void	linecount(int fd, t_var *vars)
{
	int		n;
	char	*line;

	n = 1;
	line = ft_calloc(1, 1);
	while (n > 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n == -1)
		{
			free(line);
		}
		if (ft_strchr(line, '\n'))
			vars->count++;
	}
	vars->count++;
	close(fd);
}

void	put_arr(int fd, t_var *vars)
{
	char	*line;
	int		j;

	j = 0;
	linecount(fd, vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	vars->arr = malloc(sizeof(char *) * vars->count);
	line = ft_calloc(1, 1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		vars->arr[j] = line;
		j++;
	}
	free(line);
}

static void	init_vars(t_var *vars)
{
	vars->count = 0;
	vars->length = 0;
	vars->exit_count = 0;
	vars->start_count = 0;
	vars->collectible_count = 0;
	vars->player_pos_x = 0;
	vars->player_pos_y = 0;
	vars->exit_pos_x = 0;
	vars->exit_pos_y = 0;
	vars->index = 0;
	vars->num = 0;
}

int	main(void)
{
	int		fd;
	t_var	vars;
	int		i;

	i = 0;
	init_vars(&vars);
	fd = open("map_descriptor.ber", O_RDONLY);
	put_arr(fd, &vars);
	ft_error_check(&vars);
	while (i < vars.count)
	{
		ft_printf("%s\n", vars.arr[i]);
		i++;
	}
	close(fd);
	return (0);
}
