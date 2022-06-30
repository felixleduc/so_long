/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:32:40 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 11:21:29 by fleduc           ###   ########.fr       */
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
	mlx_string_put(vars->mlx, vars->win, 0, 16, 0x00FF0000, "gems: ");
	c = ft_itoa(vars->nb_collect);
	mlx_string_put(vars->mlx, vars->win, 64, 16, 0x00FF0000, c);
	free(c);
}

void	set_sprites(t_vars *vars)
{
	int	i;

	i = 64;
	vars->player = mlx_xpm_file_to_image
		(vars->mlx, "assets/player.xpm", &i, &i);
	vars->obstacle = mlx_xpm_file_to_image
		(vars->mlx, "assets/obstacle.xpm", &i, &i);
	vars->collectible = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible.xpm", &i, &i);
	vars->exit = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit.xpm", &i, &i);
	vars->exit_unlocked = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit_unlocked.xpm", &i, &i);
	set_ground(vars, i);
}

void	set_ground(t_vars *vars, int i)
{
	vars->ground = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground.xpm", &i, &i);
	vars->ground_top_left = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_top_left.xpm", &i, &i);
	vars->ground_top_right = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_top_right.xpm", &i, &i);
	vars->ground_bottom_left = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_bottom_left.xpm", &i, &i);
	vars->ground_bottom_right = mlx_xpm_file_to_image
		(vars->mlx, "assets/ground_bottom_right.xpm", &i, &i);
}
