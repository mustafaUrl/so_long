/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:43:28 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 11:13:12 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
	void	*loot;
	void	*player;
	void	*door;
	void	*wall;
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
	int		ch_coin;
	int		ch_exit;
	int		move;
	char	**map;
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

#endif
