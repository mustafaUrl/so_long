/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:44:15 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 12:02:46 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_wall(t_game *g, int x, int y)
{
	if (g->counter == 1 || g->counter == 0)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->wl_1, x * 70, y * 73);
	if (g->counter == 2)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->wl_2, x * 70, y * 73);
	if (g->counter == 3)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->wl_3, x * 70, y * 73);
	if (g->counter == 4)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->wl_4, x * 70, y * 73);
}

void	draw_player(t_game *g, int x, int y)
{
	if (g->counter == 1 || g->counter == 0)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->pl_1, x * 70, y * 73);
	if (g->counter == 2)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->pl_2, x * 70, y * 73);
	if (g->counter == 3)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->pl_3, x * 70, y * 73);
	if (g->counter == 4)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->pl_2, x * 70, y * 73);
}

void	draw_coin(t_game *g, int x, int y)
{
	if (g->counter == 1 || g->counter == 0)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->lt_1, x * 70, y * 73);
	if (g->counter == 2)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->lt_2, x * 70, y * 73);
	if (g->counter == 3)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->lt_3, x * 70, y * 73);
	if (g->counter == 4)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->lt_4, x * 70, y * 73);
}

void	draw_door(t_game *g, int x, int y)
{
	if (g->counter == 1 || g->counter == 0)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->d_1, x * 70, y * 73);
	if (g->counter == 2)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->d_2, x * 70, y * 73);
	if (g->counter == 3)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->d_3, x * 70, y * 73);
	if (g->counter == 4)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->d_4, x * 70, y * 73);
}

void	draw_enemy(t_game *g, int x, int y)
{
	if (g->counter == 1 || g->counter == 0)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->e1, x * 70, y * 73);
	if (g->counter == 2)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->e2, x * 70, y * 73);
	if (g->counter == 3)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->e3, x * 70, y * 73);
	if (g->counter == 4)
		mlx_put_image_to_window(g->mlx, g->window, \
				g->img->e4, x * 70, y * 73);
}
