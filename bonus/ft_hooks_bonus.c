/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:20 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 15:13:32 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		if ((g->map[g->player_y -1][g->player_x] == 'E' && g->coin == 0) \
		|| g->map[g->player_y -1][g->player_x] == 'N')
			exit_hook(g);
		if (g->map[g->player_y - 1][g->player_x] != 'E')
		{
			g->player_y--;
			g->move++;
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
		if ((g->map[g->player_y + 1][g->player_x] == 'E' && g->coin == 0) \
		|| g->map[g->player_y + 1][g->player_x] == 'N')
			exit_hook(g);
		if (g->map[g->player_y + 1][g->player_x] != 'E')
		{
			g->player_y++;
			g->move++;
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
		if ((g->map[g->player_y][g->player_x - 1] == 'E' && g->coin == 0) \
		|| g->map[g->player_y][g->player_x - 1] == 'N')
			exit_hook(g);
		if (g->map[g->player_y][g->player_x - 1] != 'E')
		{
			g->player_x--;
			g->move++;
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
		if ((g->map[g->player_y][g->player_x + 1] == 'E' && g->coin == 0) \
		|| g->map[g->player_y][g->player_x + 1] == 'N')
			exit_hook(g);
		if (g->map[g->player_y][g->player_x + 1] != 'E')
		{
			g->player_x++;
			g->move++;
		}
	}
}

int	redraw_map(t_game *g)
{
	char	*s;

	if (g->anims == 1000)
	{
		s = ft_itoa(g->move);
		ft_printf("\rMovement Counter : %i", g->move);
		mlx_clear_window(g->mlx, g->window);
		enemy_run(g);
		draw_img(g);
		mlx_string_put(g->mlx, g->window, 20, 20, 255, s);
		g->k++;
		free(s);
		g->anims = 0;
	}
	g->anims++;
	return (0);
}
