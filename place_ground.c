/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_ground.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:23:58 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 11:29:25 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_ground(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < (vars->map.length * 64))
	{
		y = 0;
		while (y < (vars->map.height * 64))
		{
			if (x > 0 && x < vars->map.length && y > 0 && y < vars->map.height)
				check_corner(vars, x, y);
			else
				mlx_put_image_to_window
					(vars->mlx, vars->win, vars->ground, x, y);
			y += 64;
		}
		x += 64;
	}
}

void	check_corner(t_vars *vars, int x, int y)
{
	if ()
		;
	else if ()
		;
}

void	check_side(t_vars *vars, int x, int y)
{
	
}
