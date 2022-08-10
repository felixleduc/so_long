/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:32:40 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/10 11:03:57 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_window(t_vars *vars)
{
	char	*c;

	vars->nb_collect = 0;
	place_ground(vars);
	place_sprites(vars);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0x00FF0000, "moves: ");
	c = ft_itoa(vars->map.moves);
	mlx_string_put(vars->mlx, vars->win, 64, 0, 0x00FF0000, c);
	free(c);
	if (vars->nb_collect > 0)
	{
		mlx_string_put(vars->mlx, vars->win, 0, 16, 0x00FF0000, "gems: ");
		c = ft_itoa(vars->nb_collect);
		mlx_string_put(vars->mlx, vars->win, 64, 16, 0x00FF0000, c);
		free(c);
	}
	else
		mlx_string_put
			(vars->mlx, vars->win, 0, 16, 0x00FF0000, "portal opened!");
}

void	set_sprites(t_vars *vars)
{
	int	i;

	i = 64;
	vars->p = mlx_xpm_file_to_image
		(vars->mlx, "assets/player.xpm", &i, &i);
	vars->g = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground.xpm", &i, &i);
	vars->o = mlx_xpm_file_to_image
		(vars->mlx, "assets/obstacle.xpm", &i, &i);
	vars->c[0] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible.xpm", &i, &i);
	vars->e[0] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit.xpm", &i, &i);
	vars->e_unlocked[0] = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit_unlocked.xpm", &i, &i);
	set_anims(vars, i);
	set_walls(vars, i);
	set_ground(vars, i);
}

void	set_walls(t_vars *vars, int i)
{
	vars->walls = malloc(sizeof(t_walls));
	vars->walls->wall_top = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_top.xpm", &i, &i);
	vars->walls->wall_bottom = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_bottom.xpm", &i, &i);
	vars->walls->wall_right = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_right.xpm", &i, &i);
	vars->walls->wall_left = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_left.xpm", &i, &i);
	vars->walls->wall_bl = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_bottom_left.xpm", &i, &i);
	vars->walls->wall_br = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_bottom_right.xpm", &i, &i);
	vars->walls->wall_tl = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_top_left.xpm", &i, &i);
	vars->walls->wall_tr = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_top_right.xpm", &i, &i);
	vars->walls->wall_round = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall_round.xpm", &i, &i);
}

void	set_ground(t_vars *vars, int i)
{
	vars->grounds = malloc(sizeof(t_grounds));
	vars->grounds->ground_tl = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_top_left.xpm", &i, &i);
	vars->grounds->ground_tr = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_top_right.xpm", &i, &i);
	vars->grounds->ground_bl = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_bottom_left.xpm", &i, &i);
	vars->grounds->ground_br = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_bottom_right.xpm", &i, &i);
	vars->grounds->ground_t = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_top.xpm", &i, &i);
	vars->grounds->ground_b = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_bottom.xpm", &i, &i);
	vars->grounds->ground_r = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_right.xpm", &i, &i);
	vars->grounds->ground_l = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_left.xpm", &i, &i);
	vars->grounds->ground_2l = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_2_left.xpm", &i, &i);
	vars->grounds->ground_2t = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_2_top.xpm", &i, &i);
	vars->grounds->ground_full = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_full.xpm", &i, &i);
	set_ground2(vars, i);
}

void	set_ground2(t_vars *vars, int i)
{
	vars->grounds->ground_stl = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_stl.xpm", &i, &i);
	vars->grounds->ground_str = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_str.xpm", &i, &i);
	vars->grounds->ground_sbl = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_sbl.xpm", &i, &i);
	vars->grounds->ground_sbr = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_sbr.xpm", &i, &i);
	vars->grounds->ground_3l = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_3_left.xpm", &i, &i);
	vars->grounds->ground_3t = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_3_top.xpm", &i, &i);
	vars->grounds->ground_3b = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_3_bottom.xpm", &i, &i);
	vars->grounds->ground_3r = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_3_right.xpm", &i, &i);
	vars->grounds->flowers = mlx_xpm_file_to_image
		(vars->mlx, "assets/flowers.xpm", &i, &i);
}
