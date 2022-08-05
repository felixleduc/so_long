/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_ground.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:23:58 by fleduc            #+#    #+#             */
/*   Updated: 2022/07/05 12:44:22 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_ground(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < (vars->map.height))
	{
		y = 0;
		while (y < (vars->map.length))
		{
			if (x == 0 || x == vars->map.height - 1)
				mlx_put_image_to_window
					(vars->mlx, vars->win, vars->g, y * 64, x * 64);
			else if (y == 0 || y == vars->map.length - 1)
				mlx_put_image_to_window
					(vars->mlx, vars->win, vars->g, y * 64, x * 64);
			else
				check_ground(vars, x, y);
			y++;
		}
		x++;
	}
}

void	check_ground(t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y + 1] == '1' && vars->map.map[x][y - 1] == '1'
		&& vars->map.map[x + 1][y] == '1' && vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_full, y * 64, x * 64);
	else if (vars->map.map[x][y + 1] == '1' && vars->map.map[x + 1][y] == '1'
		&& vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_3r, y * 64, x * 64);
	else if (vars->map.map[x][y - 1] == '1' && vars->map.map[x + 1][y] == '1'
		&& vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_3l, y * 64, x * 64);
	else if (vars->map.map[x][y + 1] == '1' && vars->map.map[x][y - 1] == '1'
		&& vars->map.map[x + 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_3t, y * 64, x * 64);
	else if (vars->map.map[x][y + 1] == '1' && vars->map.map[x][y - 1] == '1'
		&& vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_3b, y * 64, x * 64);
	else
		check_ground2(vars, x, y);
	check_corners(vars, x, y);
}

void	check_ground2(t_vars *vars, int x, int y)
{
	if (vars->map.map[x + 1][y] == '1' && vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_2t, y * 64, x * 64);
	else if (vars->map.map[x][y + 1] == '1' && vars->map.map[x][y - 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_2l, y * 64, x * 64);
	else if (vars->map.map[x - 1][y] == '1' && vars->map.map[x][y - 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_tl, y * 64, x * 64);
	else if (vars->map.map[x - 1][y] == '1' && vars->map.map[x][y + 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_tr, y * 64, x * 64);
	else if (vars->map.map[x + 1][y] == '1' && vars->map.map[x][y - 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_bl, y * 64, x * 64);
	else if (vars->map.map[x + 1][y] == '1' && vars->map.map[x][y + 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_br, y * 64, x * 64);
	else
		check_ground3(vars, x, y);
}

void	check_ground3(t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y - 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_l, y * 64, x * 64);
	else if (vars->map.map[x][y + 1] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_r, y * 64, x * 64);
	else if (vars->map.map[x - 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_t, y * 64, x * 64);
	else if (vars->map.map[x + 1][y] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_b, y * 64, x * 64);
	else
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->g, y * 64, x * 64);
}

void	check_corners(t_vars *vars, int x, int y)
{
	if (vars->map.map[x - 1][y + 1] == '1'
		&& vars->map.map[x - 1][y] != '1' && vars->map.map[x][y + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_str, y * 64, x * 64);
	if (vars->map.map[x - 1][y - 1] == '1'
		&& vars->map.map[x - 1][y] != '1' && vars->map.map[x][y - 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_stl, y * 64, x * 64);
	if (vars->map.map[x + 1][y + 1] == '1'
		&& vars->map.map[x + 1][y] != '1' && vars->map.map[x][y + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_sbr, y * 64, x * 64);
	if (vars->map.map[x + 1][y - 1] == '1'
		&& vars->map.map[x + 1][y] != '1' && vars->map.map[x][y - 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->grounds->ground_sbl, y * 64, x * 64);
}
