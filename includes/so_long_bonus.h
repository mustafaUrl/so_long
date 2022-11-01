/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:43:59 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 11:52:31 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*back;
	void	*lt_1;
	void	*lt_2;
	void	*lt_3;
	void	*lt_4;
	void	*pl_1;
	void	*pl_2;
	void	*pl_3;
	void	*pl_4;
	void	*d_1;
	void	*d_2;
	void	*d_3;
	void	*d_4;
	void	*wl_1;
	void	*wl_2;
	void	*wl_3;
	void	*wl_4;
	void	*e1;
	void	*e2;
	void	*e3;
	void	*e4;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		coin;
	int		player;
	int		exit;
	int		enemy;
	int		ch_coin;
	int		ch_exit;
	int		move;
	int		k;
	int		counter;
	char	**map;
	int		anims;
	t_img	*img;
}			t_game;

int		exit_hook(t_game *game);
int		redraw_map(t_game *g);
void	draw_img(t_game *g);
int		key_func(int code, t_game *g);
void	check_map(t_game *g);
void	check_format(char *str, t_game *g);
void	char_check(t_game *g);
void	inv_check(t_game *g);
void	ft_err(char c, t_game *g);
void	valid_path(t_game *err);
void	create_mlx(t_game *g);
void	draw_img_ul(t_game *g, int x, int y);
void	up(t_game *g);
void	down(t_game *g);
void	left(t_game *g);
void	right(t_game *g);
void	map_init(t_game *g, char *av);
void	draw_wall(t_game *g, int x, int y);
void	draw_player(t_game *g, int x, int y);
void	draw_coin(t_game *g, int x, int y);
void	draw_door(t_game *g, int x, int y);
void	draw_enemy(t_game *g, int x, int y);
void	enemy_run(t_game *g);
#endif
