/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_enemy_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:19:54 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/05 14:18:19 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_vars *vars, int i, int j)
{
	if (vars->p_pos == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p, j * 64, i * 64);
	else if (vars->p_pos == 'f')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->p_f, j * 64, i * 64);
	else if (vars->p_pos == 'b')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->p_b, j * 64, i * 64);
	else if (vars->p_pos == 'l')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->p_l, j * 64, i * 64);
	else if (vars->p_pos == 'r')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->p_r, j * 64, i * 64);
}

void	enemy_pos(t_vars *vars, int i, int j)
{
	if (vars->en_pos == '0')
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->en_f, j * 64, i * 64);
	else if (vars->en_pos == 'f')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->en_f, j * 64, i * 64);
	else if (vars->en_pos == 'b')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->en_b, j * 64, i * 64);
	else if (vars->en_pos == 'l')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->en_l, j * 64, i * 64);
	else if (vars->en_pos == 'r')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->en_r, j * 64, i * 64);
}

void	place_enemy(t_vars *vars)
{
	int	i;
	int	j;

	if (vars->map.height >= 5 && vars->map.length >= 7)
	{
		i = -1;
		while (vars->map.map[++i])
		{
			j = -1;
			while (vars->map.map[i][++j])
			{
				if (vars->map.map[i][j] == '0')
				{
					vars->map.map[i][j] = 'N';
					vars->n = 1;
					vars->en_x = i * 64;
					vars->en_y = j * 64;
					mlx_put_image_to_window
					(vars->mlx, vars->win, vars->en_f, j * 64, i * 64);
					return ;
				}
			}
		}
	}
}

void	check_elements2(t_vars *vars, int i, int j)
{
	if (vars->map.map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->e[vars->frame_e], j * 64, i * 64);
	else if (vars->map.map[i][j] == 'N')
		enemy_pos(vars, i, j);
}
