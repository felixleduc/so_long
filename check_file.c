/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:45:59 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 15:57:52 by fleduc           ###   ########.fr       */
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

void	bad_file(char *map_arg[])
{
	int	dot_count;
	int	i;

	dot_count = 0;
	i = 0;
	while (map_arg[1][i])
	{
		if (map_arg[1][i] == '.')
			dot_count++;
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
