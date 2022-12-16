/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:45:53 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/16 12:11:27 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	handle_input(int keysym, t_var *vars)
//{
//	if (keysym == XK_Escape)
//		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
//	return (0);
//}

void	ft_mlx(t_var vars)
{
	ft_error_check(&vars);
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			ft_error_exit(0, &vars);
		ft_put_xpm(&vars);
		vars.win = mlx_new_window(vars.mlx, 50 * vars.length,
										50 * vars.count, "Valentins Game!");
		if (vars.win == NULL)
			ft_error_exit(0, &vars);

		
		mlx_key_hook(vars.win, key_hook, &vars);

		mlx_loop(vars.mlx);
}

int	key_hook(int keycode, t_var *vars)
{
	int	line;
	int	col;

	line = vars->p_y;
	col = vars->p_x;
	if (keycode == 100 || keycode == 65363)			//D RIGHT
		col++;
	else if (keycode == 97 || keycode == 65361)		//A LEFT
		col--;
	else if (keycode == 119 || keycode == 65362)	//W UP
		line--;
	else if (keycode == 115 || keycode == 65364)	//S DOWN
		line++;
	else if (keycode == 65307)						//XK_Escape
		ft_free_all(vars);
	return (0);
}