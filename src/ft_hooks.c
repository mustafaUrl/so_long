/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:20 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 15:16:26 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	up(t_game *g)
{
	if (g->map[g->player_y - 1][g->player_x] != '1')
	{
		if (g->map[g->player_y - 1][g->player_x] == '0')
		{
			g->map[g->player_y - 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y - 1][g->player_x] == 'C')
		{
			g->map[g->player_y - 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y - 1][g->player_x] == 'E' && g->coin == 0)
			exit_hook(g);
		if (g->map[g->player_y - 1][g->player_x] != 'E')
		{
			g->player_y--;
			g->move++;
			ft_printf("\rMovement Counter : %i", g->move);
		}
	}
}

void	down(t_game *g)
{
	if (g->map[g->player_y + 1][g->player_x] != '1')
	{
		if (g->map[g->player_y + 1][g->player_x] == '0')
		{
			g->map[g->player_y + 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y + 1][g->player_x] == 'C')
		{
			g->map[g->player_y + 1][g->player_x] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y + 1][g->player_x] == 'E' && g->coin == 0)
			exit_hook(g);
		if (g->map[g->player_y + 1][g->player_x] != 'E')
		{
			g->player_y++;
			g->move++;
			ft_printf("\rMovement Counter : %i", g->move);
		}
	}
}

void	left(t_game *g)
{
	if (g->map[g->player_y][g->player_x - 1] != '1')
	{
		if (g->map[g->player_y][g->player_x - 1] == '0')
		{
			g->map[g->player_y][g->player_x - 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y][g->player_x - 1] == 'C')
		{
			g->map[g->player_y][g->player_x - 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y][g->player_x - 1] == 'E' && g->coin == 0)
			exit_hook(g);
		if (g->map[g->player_y][g->player_x - 1] != 'E')
		{
			g->player_x--;
			g->move++;
			ft_printf("\rMovement Counter : %i", g->move);
		}
	}
}

void	right(t_game *g)
{
	if (g->map[g->player_y][g->player_x + 1] != '1')
	{
		if (g->map[g->player_y][g->player_x + 1] == '0')
		{
			g->map[g->player_y][g->player_x + 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
		}
		if (g->map[g->player_y][g->player_x + 1] == 'C')
		{
			g->map[g->player_y][g->player_x + 1] = 'P';
			g->map[g->player_y][g->player_x] = '0';
			g->coin--;
		}
		if (g->map[g->player_y][g->player_x + 1] == 'E' && g->coin == 0)
			exit_hook(g);
		if (g->map[g->player_y][g->player_x + 1] != 'E')
		{
			g->player_x++;
			g->move++;
			ft_printf("\rMovement Counter : %i", g->move);
		}
	}
}

int	redraw_map(t_game *g)
{
	mlx_clear_window(g->mlx, g->window);
	draw_img(g);
	return (0);
}
