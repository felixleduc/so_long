/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:45:59 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/10 15:40:23 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_file(char *map_arg[])
{
	int	fd;

	fd = open(map_arg[1], O_RDONLY);
	if (read(fd, 0, 10) == 0)
	{
		write(2, "Error\n", 6);
		write(2, "Empty file\n", 11);
		exit(1);
	}
	close(fd);
}

void	rectangle_map(t_vars *vars)
{
	int	i;
	int	temp;

	i = 0;
	temp = (int) ft_strlen(vars->map.map[0]);
	while (++i < vars->map.height - 1)
	{
		if (temp != (int) ft_strlen(vars->map.map[i]))
		{
			write(2, "Error\n", 6);
			write(2, "Not a rectangle map\n", 20);
			exit(1);
		}
	}
}

void	directory_only(char *map_arg[])
{
	int	fd;

	fd = open(map_arg[1], O_DIRECTORY);
	if (fd >= 0)
	{
		write(2, "Error\n", 6);
		write(2, "Not a file\n", 11);
		exit(1);
	}
}

void	file_not_exist(char *arg)
{
	if (open(arg, O_RDONLY) < 0)
	{
		write(2, "Error\n", 6);
		write(2, "Not an existing file\n", 21);
		exit(1);	
	}
}

void	bad_file(char *map_arg[])
{
	int	dot_count;
	int	i;

	file_not_exist(map_arg[1]);
	dot_count = 0;
	i = 0;
	while (map_arg[1][i])
	{
		if (map_arg[1][i] == '.')
			dot_count++;
		if (map_arg[1][i] == '/' && dot_count > 0)
			dot_count = 0;
		++i;
	}
	if (map_arg[1][i - 1] != 'r' || map_arg[1][i - 2] != 'e'
		|| map_arg[1][i - 3] != 'b' || map_arg[1][i - 4] != '.'
		|| dot_count != 1)
	{
		write(2, "Error\n", 6);
		write(2, "Not a .ber file\n", 16);
		exit(1);
	}
}
