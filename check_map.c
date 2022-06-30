/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:27:24 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 10:48:28 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[i])
	{
		free(vars->map.map[i]);
		++i;
	}
	free(vars->map.map);
	write(2, "Error\n", 6);
	write(2, "Map not correctly formatted\n", 28);
	exit(1);
}

void	check_map3(t_vars *vars, int i, int j)
{
	if (vars->map.map[i][j] == 'C')
		vars->map.check_c = 1;
	else if (vars->map.map[i][j] == 'E')
		vars->map.check_e = 1;
	else if (vars->map.map[i][j] == 'P')
		vars->map.check_p += 1;
	if (vars->map.map[i][j] == 'P' && vars->map.check_p > 1)
		vars->map.map[i][j] = '0';
}

void	check_map2(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.map[++i])
	{
		j = -1;
		while (vars->map.map[i][++j])
		{
			if ((i == 0 || i == vars->map.height - 1)
				&& vars->map.map[i][j] != '1' && j < vars->map.length)
				delete(vars);
			if ((j == 0 || j == vars->map.length - 1)
				&& vars->map.map[i][j] != '1')
				delete(vars);
			check_map3(vars, i, j);
		}
	}
	if (vars->map.check_p < 1 || vars->map.check_c < 1
		|| vars->map.check_e < 1)
		delete(vars);
}

void	check_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	vars->map.check_p = 0;
	while (vars->map.map[++i])
	{
		j = -1;
		while (vars->map.map[i][++j])
		{
			if (vars->map.map[i][j] != '1' && vars->map.map[i][j] != '0'
				&& vars->map.map[i][j] != 'C' && vars->map.map[i][j] != 'E'
				&& vars->map.map[i][j] != 'P' && vars->map.map[i][j] != '\n')
				delete(vars);
		}
	}
	check_map2(vars);
}
