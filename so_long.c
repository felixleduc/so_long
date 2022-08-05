/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:49:12 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/05 14:30:58 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hooking(int key, t_vars *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	mlx_clear_window(vars->mlx, vars->win);
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

int	loop_hook(t_vars *vars)
{
	vars->frame += 1;
	if (vars->frame % 101 == 0)
		vars->last += 1;
	if (vars->frame % 201)
		vars->last -= 1;
	if (vars->frame % 2000 == 0)
	{
		vars->frame_e += 1;
		if (vars->frame_e > 2)
			vars->frame_e = 0;
		set_window(vars);
	}
	if (vars->frame % 7501 == 0 && vars->n == 1)
	{
		enemy_move(vars);
		set_window(vars);
	}
	return (0);
}

void	init(t_vars *vars)
{
	vars->win = mlx_new_window
		(vars->mlx, vars->map.length * 64, vars->map.height * 64, "./so_long");
	vars->map.moves = 0;
	vars->frame = 0;
	vars->frame_e = 0;
	vars->last = 0;
	vars->p_pos = '0';
	vars->en_pos = '0';
	vars->n = 0;
}

int	main(int argc, char *argv[])
{
	t_vars		vars;

	if (argc != 2)
	{
		write(1, "Missing a map argument\n", 23);
		return (0);
	}
	vars.mlx = mlx_init();
	bad_file(argv);
	make_map(&vars, argv);
	init(&vars);
	place_enemy(&vars);
	set_window(&vars);
	mlx_hook(vars.win, 2, 1L << 0, hooking, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
