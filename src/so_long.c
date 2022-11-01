/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:14:57 by muraler           #+#    #+#             */
/*   Updated: 2022/10/26 14:14:57 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_game *g)
{
	int	x;
	int	y;

	x = 70;
	y = 73;
	g->img = malloc(sizeof(t_img));
	g->img->back = mlx_xpm_file_to_image(g->mlx, "xpm/a.xpm", &x, &y);
	g->img->door = mlx_xpm_file_to_image(g->mlx, "xpm/d1.xpm", &x, &y);
	g->img->loot = mlx_xpm_file_to_image(g->mlx, "xpm/k4.xpm", &x, &y);
	g->img->wall = mlx_xpm_file_to_image(g->mlx, "xpm/R.xpm", &x, &y);
	g->img->player = mlx_xpm_file_to_image(g->mlx, "xpm/pl_1.xpm", &x, &y);
}

void	draw_img_ul(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->window, g->img->wall,
			x * 70, y * 73);
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->img->back,
			x * 70, y * 73);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->window, g->img->player,
			x * 70, y * 73);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->window, g->img->loot,
			x * 70, y * 73);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window, g->img->door,
			x * 70, y * 73);
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
	g->window = mlx_new_window(g->mlx, g->max_x * 70, g->max_y * 73, "so_long");
	put_img(g);
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
