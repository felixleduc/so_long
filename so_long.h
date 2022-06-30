/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:05:33 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/30 11:19:57 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> //a supprimer
# include "libft/libft.h"

typedef struct s_map
{
	int		check_c;
	int		check_e;
	int		check_p;
	int		height;
	int		length;
	int		moves;
	char	**map;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*ground;
	void	*obstacle;
	void	*collectible;
	void	*exit;
	void	*exit_unlocked;
	int		x;
	int		y;
	int		nb_collect;
	int		frame;
	int		frame_ground;
	t_map	map;
}	t_vars;

int		main(int argc, char *argv[]);
void	make_map(t_vars *vars, char **map_arg);
void	check_size_map(t_vars *vars, char **map_arg);
void	place_ground(t_vars *vars);
void	set_window(t_vars *vars);
void	set_sprites(t_vars *vars);
void	place_sprites(t_vars *vars);
void	check_elements(t_vars *vars, int i, int j);
void	keys_up_down(t_vars *vars, int key);
void	keys_left_right(t_vars *vars, int key);
int		close_game(t_vars *vars);
int		hooking(int key, t_vars *vars);
void	check_map(t_vars *vars);
void	delete(t_vars *vars);
void	exitter(t_vars *vars);
void	init(t_vars *vars);
void	set_ground(t_vars *vars);

#endif
