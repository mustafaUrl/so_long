/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:14:57 by muraler           #+#    #+#             */
/*   Updated: 2022/10/26 16:42:05 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img(t_game *g, int x, int y)
{
	g->img = malloc(sizeof(t_img));
	g->img->back = mlx_xpm_file_to_image(g->mlx, "xpm/a.xpm", &x, &y);
	g->img->e1 = mlx_xpm_file_to_image(g->mlx, "xpm/en1.xpm", &x, &y);
	g->img->e2 = mlx_xpm_file_to_image(g->mlx, "xpm/en2.xpm", &x, &y);
	g->img->e3 = mlx_xpm_file_to_image(g->mlx, "xpm/en3.xpm", &x, &y);
	g->img->e4 = mlx_xpm_file_to_image(g->mlx, "xpm/en4.xpm", &x, &y);
	g->img->d_1 = mlx_xpm_file_to_image(g->mlx, "xpm/d1.xpm", &x, &y);
	g->img->d_2 = mlx_xpm_file_to_image(g->mlx, "xpm/d2.xpm", &x, &y);
	g->img->d_3 = mlx_xpm_file_to_image(g->mlx, "xpm/d3.xpm", &x, &y);
	g->img->d_4 = mlx_xpm_file_to_image(g->mlx, "xpm/d4.xpm", &x, &y);
	g->img->lt_1 = mlx_xpm_file_to_image(g->mlx, "xpm/k1.xpm", &x, &y);
	g->img->lt_2 = mlx_xpm_file_to_image(g->mlx, "xpm/k2.xpm", &x, &y);
	g->img->lt_3 = mlx_xpm_file_to_image(g->mlx, "xpm/k3.xpm", &x, &y);
	g->img->lt_4 = mlx_xpm_file_to_image(g->mlx, "xpm/k4.xpm", &x, &y);
	g->img->wl_1 = mlx_xpm_file_to_image(g->mlx, "xpm/R1.xpm", &x, &y);
	g->img->wl_2 = mlx_xpm_file_to_image(g->mlx, "xpm/R2.xpm", &x, &y);
	g->img->wl_3 = mlx_xpm_file_to_image(g->mlx, "xpm/R3.xpm", &x, &y);
	g->img->wl_4 = mlx_xpm_file_to_image(g->mlx, "xpm/R4.xpm", &x, &y);
	g->img->pl_1 = mlx_xpm_file_to_image(g->mlx, "xpm/pl_1.xpm", &x, &y);
	g->img->pl_2 = mlx_xpm_file_to_image(g->mlx, "xpm/pl_2.xpm", &x, &y);
	g->img->pl_3 = mlx_xpm_file_to_image(g->mlx, "xpm/pl_3.xpm", &x, &y);
	g->img->pl_4 = mlx_xpm_file_to_image(g->mlx, "xpm/pl_4.xpm", &x, &y);
}

void	draw_img_ul(t_game *g, int x, int y)
{
	if (g->counter == 5)
		g->counter = 1;
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->img->back \
		, x * 70, y * 73);
	if (g->map[y][x] == '1')
		draw_wall(g, x, y);
	if (g->map[y][x] == 'P')
		draw_player(g, x, y);
	if (g->map[y][x] == 'C')
		draw_coin(g, x, y);
	if (g->map[y][x] == 'E')
		draw_door(g, x, y);
	if (g->map[y][x] == 'N')
		draw_enemy(g, x, y);
		g->counter++;
}

void	draw_img(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->max_y)
	{
		x = 0;
		while (x < g->max_x)
		{
			draw_img_ul(g, x, y);
			x++;
		}
		y++;
	}
}

void	create_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->k = 0;
	g->anims = 0;
	g->window = mlx_new_window(g->mlx, g->max_x * 70, g->max_y * 73, "so_long");
	put_img(g, 70, 73);
	draw_img(g);
	mlx_hook(g->window, 2, 0, key_func, g);
	mlx_loop_hook(g->mlx, redraw_map, g);
	mlx_hook(g->window, 17, 0, exit_hook, g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ac != 2)
		ft_err('a', game);
	check_format(av[1], game);
	map_init(game, av[1]);
	check_map(game);
	create_mlx(game);
}
