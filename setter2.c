/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:24:23 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/10 11:15:46 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_anims(t_vars *vars, int i)
{
	vars->e[1] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit2.xpm", &i, &i);
	vars->e[2] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit3.xpm", &i, &i);
	vars->e_unlocked[1] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit_unlocked2.xpm", &i, &i);
	vars->e_unlocked[2] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit_unlocked3.xpm", &i, &i);
	vars->p_f = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_f.xpm", &i, &i);
	vars->p_b = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_b.xpm", &i, &i);
	vars->p_r = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_r.xpm", &i, &i);
	vars->p_l = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_l.xpm", &i, &i);
	vars->en_f = mlx_xpm_file_to_image
		(vars->mlx, "assets/enemy_f.xpm", &i, &i);
	vars->en_b = mlx_xpm_file_to_image
		(vars->mlx, "assets/enemy_b.xpm", &i, &i);
	vars->en_l = mlx_xpm_file_to_image
		(vars->mlx, "assets/enemy_l.xpm", &i, &i);
	vars->en_r = mlx_xpm_file_to_image
		(vars->mlx, "assets/enemy_r.xpm", &i, &i);
	set_anims2(vars, i);
}

void	set_anims2(t_vars *vars, int i)
{
	vars->c[1] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible_l.xpm", &i, &i);
	vars->c[2] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible_c.xpm", &i, &i);
	vars->c[3] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible_r.xpm", &i, &i);
}
