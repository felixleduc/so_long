/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:05:33 by fleduc            #+#    #+#             */
/*   Updated: 2022/08/11 15:34:53 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
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

typedef struct s_grounds
{
	void	*ground_tl;
	void	*ground_tr;
	void	*ground_bl;
	void	*ground_br;
	void	*ground_l;
	void	*ground_r;
	void	*ground_t;
	void	*ground_b;
	void	*ground_stl;
	void	*ground_str;
	void	*ground_sbl;
	void	*ground_sbr;
	void	*ground_full;
	void	*ground_2l;
	void	*ground_2t;
	void	*ground_3l;
	void	*ground_3t;
	void	*ground_3b;
	void	*ground_3r;
	void	*flowers;
}	t_grounds;

typedef struct s_walls
{
	void	*wall_top;
	void	*wall_bottom;
	void	*wall_right;
	void	*wall_left;
	void	*wall_bl;
	void	*wall_br;
	void	*wall_tl;
	void	*wall_tr;
	void	*wall_round;
}	t_walls;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*p;
	void		*p_f;
	void		*p_b;
	void		*p_r;
	void		*p_l;
	void		*en_f;
	void		*en_b;
	void		*en_l;
	void		*en_r;
	void		*g;
	void		*o;
	void		*c[4];
	void		*e[3];
	void		*e_unlocked[3];
	char		**file;
	int			x;
	int			y;
	int			n;
	int			en_x;
	int			en_y;
	char		p_pos;
	char		en_pos;
	int			nb_collect;
	int			frame;
	int			frame_e;
	int			frame_c;
	int			last;
	t_map		map;
	t_walls		*walls;
	t_grounds	*grounds;
}	t_vars;

int		main(int argc, char *argv[]);
void	make_map(t_vars *vars, char **map_arg);
void	check_size_map(t_vars *vars, char **map_arg);
void	place_ground(t_vars *vars);
void	set_window(t_vars *vars);
void	set_sprites(t_vars *vars);
void	set_anims(t_vars *vars, int i);
void	set_anims2(t_vars *vars, int i);
void	place_sprites(t_vars *vars);
void	check_elements(t_vars *vars, int i, int j);
void	check_elements2(t_vars *vars, int i, int j);
void	keys_up_down(t_vars *vars, int key);
void	keys_left_right(t_vars *vars, int key);
int		close_game(t_vars *vars);
int		hooking(int key, t_vars *vars);
void	check_map(t_vars *vars);
void	deleter(t_vars *vars);
void	exitter(t_vars *vars);
void	init(t_vars *vars);
int		block_walls(t_vars *vars);
int		block_walls_en(t_vars *vars);
int		lock_exit(t_vars *vars);
void	set_ground(t_vars *vars, int i);
void	set_ground2(t_vars *vars, int i);
void	check_ground(t_vars *vars, int x, int y);
void	check_ground2(t_vars *vars, int x, int y);
void	check_ground3(t_vars *vars, int x, int y);
void	check_corners(t_vars *vars, int x, int y);
void	place_wall(t_vars *vars, int i, int j);
void	place_wall2(t_vars *vars, int i, int j);
void	player_pos(t_vars *vars, int i, int j);
void	enemy_pos(t_vars *vars, int i, int j);
void	place_enemy(t_vars *vars);
void	enemy_move(t_vars *vars);
void	enemy_move2(t_vars *vars, int random);
void	enemy_move3(t_vars *vars, int random);
void	enemy_move4(t_vars *vars, int random);
void	set_walls(t_vars *vars, int i);
void	empty_file(char *map_arg[]);
void	bad_file(char *map_arg[]);
void	directory_only(char *map_arg[]);
void	file_not_exit(char *arg);
void	rectangle_map(t_vars *vars);

#endif
