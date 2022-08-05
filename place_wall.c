/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:51:32 by fleduc            #+#    #+#             */
/*   Updated: 2022/07/05 12:57:01 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_wall(t_vars *vars, int i, int j)
{
	if (vars->map.map[i - 1][j] != '1' && vars->map.map[i + 1][j] != '1'
		&& vars->map.map[i][j - 1] != '1' && vars->map.map[i][j + 1] != '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->walls->wall_round, j * 64, i * 64);
	else if (vars->map.map[i - 1][j] != '1'
		&& vars->map.map[i][j - 1] != '1' && vars->map.map[i][j + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_top, j * 64, i * 64);
	else if (vars->map.map[i + 1][j] != '1'
		&& vars->map.map[i][j - 1] != '1' && vars->map.map[i][j + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_bottom, j * 64, i * 64);
	else if (vars->map.map[i][j + 1] != '1'
		&& vars->map.map[i + 1][j] != '1' && vars->map.map[i - 1][j] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_right, j * 64, i * 64);
	else if (vars->map.map[i][j - 1] != '1'
		&& vars->map.map[i + 1][j] != '1' && vars->map.map[i - 1][j] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_left, j * 64, i * 64);
	else
		place_wall2(vars, i, j);
}

void	place_wall2(t_vars *vars, int i, int j)
{
	if (vars->map.map[i - 1][j] != '1' && vars->map.map[i][j - 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_tl, j * 64, i * 64);
	else if (vars->map.map[i - 1][j] != '1' && vars->map.map[i][j + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_tr, j * 64, i * 64);
	else if (vars->map.map[i + 1][j] != '1' && vars->map.map[i][j - 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_bl, j * 64, i * 64);
	else if (vars->map.map[i + 1][j] != '1' && vars->map.map[i][j + 1] != '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->walls->wall_br, j * 64, i * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->o, j * 64, i * 64);
}
