/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:49:12 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 11:15:33 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hooking(int key, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	keys_up_down(vars, key);
	keys_left_right(vars, key);
	set_window(vars);
	return (0);
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

/*int	loop_hook(t_vars *vars)
{
	vars->frame += 1;
	if (vars->frame % 5000 == 0)
		vars->frame_ground += 1;
	if (vars->frame_ground > 1)
		vars->frame_ground = 0;
	return (0);
}*/

void	init(t_vars *vars)
{
	vars->win = mlx_new_window
		(vars->mlx, vars->map.length * 64, vars->map.height * 64, "./so_long");
	vars->map.moves = 0;
	vars->frame = 0;
	vars->frame_ground = 0;
}

int	main(int argc, char *argv[])
{
	t_vars		vars;

	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	make_map(&vars, argv);
	init(&vars);
	set_window(&vars);
	mlx_key_hook(vars.win, hooking, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	//mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
