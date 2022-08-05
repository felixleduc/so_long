/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:20 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/05 14:00:02 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_vars *vars)
{
	int	random;

	random = (vars->frame + vars->last) % 4 + 1;
	if (random == 1)
	{
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = '0';
		vars->en_x += 64;
		if (vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'P')
			close_game(vars);
		if (block_walls_en(vars)
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'E'
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'C')
			vars->en_x -= 64;
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = 'N';
		vars->en_pos = 'f';
	}
	else
		enemy_move2(vars, random);
}

void	enemy_move2(t_vars *vars, int random)
{
	if (random == 2)
	{
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = '0';
		vars->en_x -= 64;
		if (vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'P')
			close_game(vars);
		if (block_walls_en(vars)
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'E'
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'C')
			vars->en_x += 64;
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = 'N';
		vars->en_pos = 'b';
	}
	else
		enemy_move3(vars, random);
}

void	enemy_move3(t_vars *vars, int random)
{
	if (random == 3)
	{
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = '0';
		vars->en_y -= 64;
		if (vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'P')
			close_game(vars);
		if (block_walls_en(vars)
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'E'
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'C')
			vars->en_y += 64;
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = 'N';
		vars->en_pos = 'l';
	}
	else
		enemy_move4(vars, random);
}

void	enemy_move4(t_vars *vars, int random)
{
	if (random == 4)
	{
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = '0';
		vars->en_y += 64;
		if (vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'P')
			close_game(vars);
		if (block_walls_en(vars)
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'E'
			|| vars->map.map[vars->en_x / 64][vars->en_y / 64] == 'C')
			vars->en_y -= 64;
		vars->map.map[vars->en_x / 64][vars->en_y / 64] = 'N';
		vars->en_pos = 'r';
	}
}

int	block_walls_en(t_vars *vars)
{
	if (vars->map.map[vars->en_x / 64][vars->en_y / 64] == '1')
		return (1);
	return (0);
}
