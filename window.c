/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:18:50 by vstockma          #+#    #+#             */
/*   Updated: 2023/01/12 14:18:53 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_move(t_var *vars, int line, int col, int key)
{
	if (vars->arr[line][col] == '1')
		return (-1);
	if (vars->arr[line][col] == 'E' && vars->collectible_count == 0)
		vars->end = 1;
	if (vars->arr[line][col] == 'E')
		return (-1);
	if (vars->end)
		return (-1);
	if (key != UP && key != DOWN && key != LEFT && key != RIGHT)
		return (-1);
	else
		return (1);
}

void	ft_move(t_var *vars, int line, int col, int key)
{
	int	x;
	int	y;
	int	check;

	y = vars->p_y;
	x = vars->p_x;
	check = ft_check_move(vars, line, col, key);
	if (vars->end == 1)
		ft_free(vars);
	if (check > 0)
	{
		if (vars->arr[line][col] == 'C')
			vars->collectible_count--;
		vars->arr[y][x] = '0';
		vars->arr[line][col] = 'P';
		vars->p_y = line;
		vars->p_x = col;
		vars->moves++;
		ft_printf("move: %d\n", vars->moves);
	}
}

int	key_hook(int keycode, t_var *vars)
{
	int	line;
	int	col;

	line = vars->p_y;
	col = vars->p_x;
	if (keycode == 65307)
		ft_free(vars);
	if (keycode == D || keycode == RIGHT)
		col++;
	if (keycode == A || keycode == LEFT)
		col--;
	if (keycode == W || keycode == UP)
		line--;
	if (keycode == S || keycode == DOWN)
		line++;
	if (!vars->end)
		ft_move(vars, line, col, keycode);
	return (1);
}

void	ft_mlx(t_var *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_error_exit(0, vars);
	vars->win = mlx_new_window(vars->mlx, 50 * vars->length, 50 * vars->count,
			"so_long");
	if (vars->win == NULL)
		ft_error_exit(0, vars);
	ft_put_xpm(vars);
	mlx_hook(vars->win, KeyPress, 1, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 0, ft_free, vars);
	mlx_loop_hook(vars->mlx, ft_update, vars);
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_loop(vars->mlx);
}
