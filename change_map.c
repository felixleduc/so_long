/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:31:17 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/05 14:35:51 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	block_walls(t_vars *vars)
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
		{
			vars->map.moves -= 1;
			return (1);
		}
		else
		{
			write(1, "You won!\n", 9);
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
		if (vars->map.map[vars->x / 64][vars->y / 64] == 'N')
			close_game(vars);
		if (block_walls(vars) || lock_exit(vars))
			vars->x += 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
		vars->p_pos = 'b';
	}
	else if (key == 1)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->x += 64;
		if (vars->map.map[vars->x / 64][vars->y / 64] == 'N')
			close_game(vars);
		if (block_walls(vars) || lock_exit(vars))
			vars->x -= 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
		vars->p_pos = 'f';
	}
}

void	keys_left_right(t_vars *vars, int key)
{
	if (key == 0)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->y -= 64;
		if (vars->map.map[vars->x / 64][vars->y / 64] == 'N')
			close_game(vars);
		if (block_walls(vars) || lock_exit(vars))
			vars->y += 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
		vars->p_pos = 'l';
	}
	else if (key == 2)
	{
		vars->map.map[vars->x / 64][vars->y / 64] = '0';
		vars->y += 64;
		if (vars->map.map[vars->x / 64][vars->y / 64] == 'N')
			close_game(vars);
		if (block_walls(vars) || lock_exit(vars))
			vars->y -= 64;
		vars->map.map[vars->x / 64][vars->y / 64] = 'P';
		vars->p_pos = 'r';
	}
}
