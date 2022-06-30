/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:31:17 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 10:57:39 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	block_walls(t_vars *vars)
{
	if (vars->map.map[vars->x / 64][vars->y / 64] == '1')
		return (1);
	vars->map.moves += 1;
	return (0);
}

int	lock_exit(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map.map[vars->x / 64][vars->y / 64] == 'E')
	{
		if (vars->nb_collect != 0)
			return (1);
		else
		{
			mlx_destroy_window(vars->mlx, vars->win);
			exit(0);
		}
	}
	return (0);
}

void	keys_up_down(t_vars *vars, int key)
{
	if (key == 13)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->x -= 64;
		if (block_walls(vars) || lock_exit(vars))
			vars->x += 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
	}
	else if (key == 1)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->x += 64;
		if (block_walls(vars) || lock_exit(vars))
			vars->x -= 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
	}
}

void	keys_left_right(t_vars *vars, int key)
{
	if (key == 0)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->y -= 64;
		if (block_walls(vars) || lock_exit(vars))
			vars->y += 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
	}
	else if (key == 2)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->y += 64;
		if (block_walls(vars) || lock_exit(vars))
			vars->y -= 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
	}
}
