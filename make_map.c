/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:29:31 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 11:24:41 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_vars *vars, char **map_arg)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	check_size_map(vars, map_arg);
	vars->map.map = (char **)ft_calloc(vars->map.height + 1, sizeof(char *));
	fd = open(map_arg[1], O_RDONLY);
	line = get_next_line(fd);
	vars->map.length = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		j = -1;
		vars->map.map[i] = (char *)ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[++j])
			vars->map.map[i][j] = line[j];
		free(line);
		line = get_next_line(fd);
		++i;
	}
	close(fd);
	check_map(vars);
	set_sprites(vars);
}

void	check_size_map(t_vars *vars, char **map_arg)
{
	char	*line;
	int		fd;

	fd = open(map_arg[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(vars->map.height) += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	place_sprites(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->map.check_e = 0;
	while (i < vars->map.height)
	{
		j = 0;
		while (j < vars->map.length)
		{
			check_elements(vars, i, j);
			++j;
		}
		++i;
	}
	exitter(vars);
}

void	exitter(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.map[++i])
	{
		j = -1;
		while (vars->map.map[i][++j])
		{
			if (vars->nb_collect == 0 && vars->map.map[i][j] == 'E')
			{
				mlx_put_image_to_window
					(vars->mlx, vars->win, vars->ground, j * 64, i * 64);
				mlx_put_image_to_window
					(vars->mlx, vars->win, vars->exit_unlocked, j * 64, i * 64);
			}
		}
	}
}

void	check_elements(t_vars *vars, int i, int j)
{
	if (vars->map.map[i][j] == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->obstacle, j * 64, i * 64);
	else if (vars->map.map[i][j] == 'P')
	{
		vars->x = i * 64;
		vars->y = j * 64;
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->player, j * 64, i * 64);
	}
	else if (vars->map.map[i][j] == 'C')
	{
		vars->nb_collect += 1;
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->collectible, j * 64, i * 64);
	}
	else if (vars->map.map[i][j] == 'E')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->exit, j * 64, i * 64);
}
